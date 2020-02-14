#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  tlv ;
struct sr6_tlv_t {scalar_t__ type; scalar_t__ len; int /*<<< orphan*/  lo; int /*<<< orphan*/  hi; } ;
struct ip6_t {int next_header; } ;
struct ip6_srh_t {int type; int first_segment; int hdrlen; } ;
struct ip6_addr_t {scalar_t__ type; scalar_t__ len; int /*<<< orphan*/  lo; int /*<<< orphan*/  hi; } ;
struct __sk_buff {scalar_t__ data; scalar_t__ data_end; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ SR6_TLV_EGRESS ; 
 scalar_t__ SR6_TLV_HMAC ; 
 scalar_t__ SR6_TLV_PADDING ; 
 int bpf_lwt_seg6_adjust_srh (struct __sk_buff*,scalar_t__,int) ; 
 int bpf_lwt_seg6_store_bytes (struct __sk_buff*,scalar_t__,void*,int) ; 
 int bpf_skb_load_bytes (struct __sk_buff*,int,struct sr6_tlv_t*,int) ; 
 void* cursor_advance (void*,int) ; 
 int ntohll (int /*<<< orphan*/ ) ; 

__attribute__((always_inline)) struct ip6_srh_t *get_srh(struct __sk_buff *skb)
{
	void *cursor, *data_end;
	struct ip6_srh_t *srh;
	struct ip6_t *ip;
	uint8_t *ipver;

	data_end = (void *)(long)skb->data_end;
	cursor = (void *)(long)skb->data;
	ipver = (uint8_t *)cursor;

	if ((void *)ipver + sizeof(*ipver) > data_end)
		return NULL;

	if ((*ipver >> 4) != 6)
		return NULL;

	ip = cursor_advance(cursor, sizeof(*ip));
	if ((void *)ip + sizeof(*ip) > data_end)
		return NULL;

	if (ip->next_header != 43)
		return NULL;

	srh = cursor_advance(cursor, sizeof(*srh));
	if ((void *)srh + sizeof(*srh) > data_end)
		return NULL;

	if (srh->type != 4)
		return NULL;

	return srh;
}

__attribute__((always_inline))
int update_tlv_pad(struct __sk_buff *skb, uint32_t new_pad,
		   uint32_t old_pad, uint32_t pad_off)
{
	int err;

	if (new_pad != old_pad) {
		err = bpf_lwt_seg6_adjust_srh(skb, pad_off,
					  (int) new_pad - (int) old_pad);
		if (err)
			return err;
	}

	if (new_pad > 0) {
		char pad_tlv_buf[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0};
		struct sr6_tlv_t *pad_tlv = (struct sr6_tlv_t *) pad_tlv_buf;

		pad_tlv->type = SR6_TLV_PADDING;
		pad_tlv->len = new_pad - 2;

		err = bpf_lwt_seg6_store_bytes(skb, pad_off,
					       (void *)pad_tlv_buf, new_pad);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((always_inline))
int is_valid_tlv_boundary(struct __sk_buff *skb, struct ip6_srh_t *srh,
			  uint32_t *tlv_off, uint32_t *pad_size,
			  uint32_t *pad_off)
{
	uint32_t srh_off, cur_off;
	int offset_valid = 0;
	int err;

	srh_off = (char *)srh - (char *)(long)skb->data;
	// cur_off = end of segments, start of possible TLVs
	cur_off = srh_off + sizeof(*srh) +
		sizeof(struct ip6_addr_t) * (srh->first_segment + 1);

	*pad_off = 0;

	// we can only go as far as ~10 TLVs due to the BPF max stack size
	#pragma clang loop unroll(full)
	for (int i = 0; i < 10; i++) {
		struct sr6_tlv_t tlv;

		if (cur_off == *tlv_off)
			offset_valid = 1;

		if (cur_off >= srh_off + ((srh->hdrlen + 1) << 3))
			break;

		err = bpf_skb_load_bytes(skb, cur_off, &tlv, sizeof(tlv));
		if (err)
			return err;

		if (tlv.type == SR6_TLV_PADDING) {
			*pad_size = tlv.len + sizeof(tlv);
			*pad_off = cur_off;

			if (*tlv_off == srh_off) {
				*tlv_off = cur_off;
				offset_valid = 1;
			}
			break;

		} else if (tlv.type == SR6_TLV_HMAC) {
			break;
		}

		cur_off += sizeof(tlv) + tlv.len;
	} // we reached the padding or HMAC TLVs, or the end of the SRH

	if (*pad_off == 0)
		*pad_off = cur_off;

	if (*tlv_off == -1)
		*tlv_off = cur_off;
	else if (!offset_valid)
		return -EINVAL;

	return 0;
}

__attribute__((always_inline))
int add_tlv(struct __sk_buff *skb, struct ip6_srh_t *srh, uint32_t tlv_off,
	    struct sr6_tlv_t *itlv, uint8_t tlv_size)
{
	uint32_t srh_off = (char *)srh - (char *)(long)skb->data;
	uint8_t len_remaining, new_pad;
	uint32_t pad_off = 0;
	uint32_t pad_size = 0;
	uint32_t partial_srh_len;
	int err;

	if (tlv_off != -1)
		tlv_off += srh_off;

	if (itlv->type == SR6_TLV_PADDING || itlv->type == SR6_TLV_HMAC)
		return -EINVAL;

	err = is_valid_tlv_boundary(skb, srh, &tlv_off, &pad_size, &pad_off);
	if (err)
		return err;

	err = bpf_lwt_seg6_adjust_srh(skb, tlv_off, sizeof(*itlv) + itlv->len);
	if (err)
		return err;

	err = bpf_lwt_seg6_store_bytes(skb, tlv_off, (void *)itlv, tlv_size);
	if (err)
		return err;

	// the following can't be moved inside update_tlv_pad because the
	// bpf verifier has some issues with it
	pad_off += sizeof(*itlv) + itlv->len;
	partial_srh_len = pad_off - srh_off;
	len_remaining = partial_srh_len % 8;
	new_pad = 8 - len_remaining;

	if (new_pad == 1) // cannot pad for 1 byte only
		new_pad = 9;
	else if (new_pad == 8)
		new_pad = 0;

	return update_tlv_pad(skb, new_pad, pad_size, pad_off);
}

__attribute__((always_inline))
int delete_tlv(struct __sk_buff *skb, struct ip6_srh_t *srh,
	       uint32_t tlv_off)
{
	uint32_t srh_off = (char *)srh - (char *)(long)skb->data;
	uint8_t len_remaining, new_pad;
	uint32_t partial_srh_len;
	uint32_t pad_off = 0;
	uint32_t pad_size = 0;
	struct sr6_tlv_t tlv;
	int err;

	tlv_off += srh_off;

	err = is_valid_tlv_boundary(skb, srh, &tlv_off, &pad_size, &pad_off);
	if (err)
		return err;

	err = bpf_skb_load_bytes(skb, tlv_off, &tlv, sizeof(tlv));
	if (err)
		return err;

	err = bpf_lwt_seg6_adjust_srh(skb, tlv_off, -(sizeof(tlv) + tlv.len));
	if (err)
		return err;

	pad_off -= sizeof(tlv) + tlv.len;
	partial_srh_len = pad_off - srh_off;
	len_remaining = partial_srh_len % 8;
	new_pad = 8 - len_remaining;
	if (new_pad == 1) // cannot pad for 1 byte only
		new_pad = 9;
	else if (new_pad == 8)
		new_pad = 0;

	return update_tlv_pad(skb, new_pad, pad_size, pad_off);
}

__attribute__((always_inline))
int has_egr_tlv(struct __sk_buff *skb, struct ip6_srh_t *srh)
{
	int tlv_offset = sizeof(struct ip6_t) + sizeof(struct ip6_srh_t) +
		((srh->first_segment + 1) << 4);
	struct sr6_tlv_t tlv;

	if (bpf_skb_load_bytes(skb, tlv_offset, &tlv, sizeof(struct sr6_tlv_t)))
		return 0;

	if (tlv.type == SR6_TLV_EGRESS && tlv.len == 18) {
		struct ip6_addr_t egr_addr;

		if (bpf_skb_load_bytes(skb, tlv_offset + 4, &egr_addr, 16))
			return 0;

		// check if egress TLV value is correct
		if (ntohll(egr_addr.hi) == 0xfd00000000000000 &&
				ntohll(egr_addr.lo) == 0x4)
			return 1;
	}

	return 0;
}


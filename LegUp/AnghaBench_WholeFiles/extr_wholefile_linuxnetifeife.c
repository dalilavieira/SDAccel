#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {char* data; TYPE_1__* dev; } ;
struct meta_tlvhdr {int /*<<< orphan*/  len; int /*<<< orphan*/  type; } ;
struct ifeheadr {void* tlv_data; int /*<<< orphan*/  metalen; } ;
typedef  void const ethhdr ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {int hard_header_len; } ;

/* Variables and functions */
 int IFE_METAHDRLEN ; 
 int NLA_ALIGN (int) ; 
 int NLA_HDRLEN ; 
 int /*<<< orphan*/  __skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  __skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  htonl (int) ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  memcpy (char*,void const*,int) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int nla_total_size (int) ; 
 int ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int skb_cow_head (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_mac_header (struct sk_buff*,int) ; 
 scalar_t__ unlikely (int) ; 

void *ife_encode(struct sk_buff *skb, u16 metalen)
{
	/* OUTERHDR:TOTMETALEN:{TLVHDR:Metadatum:TLVHDR..}:ORIGDATA
	 * where ORIGDATA = original ethernet header ...
	 */
	int hdrm = metalen + IFE_METAHDRLEN;
	int total_push = hdrm + skb->dev->hard_header_len;
	struct ifeheadr *ifehdr;
	struct ethhdr *iethh;	/* inner ether header */
	int skboff = 0;
	int err;

	err = skb_cow_head(skb, total_push);
	if (unlikely(err))
		return NULL;

	iethh = (struct ethhdr *) skb->data;

	__skb_push(skb, total_push);
	memcpy(skb->data, iethh, skb->dev->hard_header_len);
	skb_reset_mac_header(skb);
	skboff += skb->dev->hard_header_len;

	/* total metadata length */
	ifehdr = (struct ifeheadr *) (skb->data + skboff);
	metalen += IFE_METAHDRLEN;
	ifehdr->metalen = htons(metalen);

	return ifehdr->tlv_data;
}

void *ife_decode(struct sk_buff *skb, u16 *metalen)
{
	struct ifeheadr *ifehdr;
	int total_pull;
	u16 ifehdrln;

	if (!pskb_may_pull(skb, skb->dev->hard_header_len + IFE_METAHDRLEN))
		return NULL;

	ifehdr = (struct ifeheadr *) (skb->data + skb->dev->hard_header_len);
	ifehdrln = ntohs(ifehdr->metalen);
	total_pull = skb->dev->hard_header_len + ifehdrln;

	if (unlikely(ifehdrln < 2))
		return NULL;

	if (unlikely(!pskb_may_pull(skb, total_pull)))
		return NULL;

	skb_set_mac_header(skb, total_pull);
	__skb_pull(skb, total_pull);
	*metalen = ifehdrln - IFE_METAHDRLEN;

	return &ifehdr->tlv_data;
}

__attribute__((used)) static bool __ife_tlv_meta_valid(const unsigned char *skbdata,
				 const unsigned char *ifehdr_end)
{
	const struct meta_tlvhdr *tlv;
	u16 tlvlen;

	if (unlikely(skbdata + sizeof(*tlv) > ifehdr_end))
		return false;

	tlv = (const struct meta_tlvhdr *)skbdata;
	tlvlen = ntohs(tlv->len);

	/* tlv length field is inc header, check on minimum */
	if (tlvlen < NLA_HDRLEN)
		return false;

	/* overflow by NLA_ALIGN check */
	if (NLA_ALIGN(tlvlen) < tlvlen)
		return false;

	if (unlikely(skbdata + NLA_ALIGN(tlvlen) > ifehdr_end))
		return false;

	return true;
}

void *ife_tlv_meta_decode(void *skbdata, const void *ifehdr_end, u16 *attrtype,
			  u16 *dlen, u16 *totlen)
{
	struct meta_tlvhdr *tlv;

	if (!__ife_tlv_meta_valid(skbdata, ifehdr_end))
		return NULL;

	tlv = (struct meta_tlvhdr *)skbdata;
	*dlen = ntohs(tlv->len) - NLA_HDRLEN;
	*attrtype = ntohs(tlv->type);

	if (totlen)
		*totlen = nla_total_size(*dlen);

	return skbdata + sizeof(struct meta_tlvhdr);
}

void *ife_tlv_meta_next(void *skbdata)
{
	struct meta_tlvhdr *tlv = (struct meta_tlvhdr *) skbdata;
	u16 tlvlen = ntohs(tlv->len);

	tlvlen = NLA_ALIGN(tlvlen);

	return skbdata + tlvlen;
}

int ife_tlv_meta_encode(void *skbdata, u16 attrtype, u16 dlen, const void *dval)
{
	__be32 *tlv = (__be32 *) (skbdata);
	u16 totlen = nla_total_size(dlen);	/*alignment + hdr */
	char *dptr = (char *) tlv + NLA_HDRLEN;
	u32 htlv = attrtype << 16 | (dlen + NLA_HDRLEN);

	*tlv = htonl(htlv);
	memset(dptr, 0, totlen - NLA_HDRLEN);
	memcpy(dptr, dval, dlen);

	return totlen;
}


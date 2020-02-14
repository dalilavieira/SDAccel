#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  val ;
typedef  int u8 ;
typedef  int /*<<< orphan*/  tmp ;
struct udphdr {int source; int dest; int check; int len; } ;
struct sk_buff {int /*<<< orphan*/  len; int /*<<< orphan*/  dev; } ;
struct lowpan_nhc {int /*<<< orphan*/ * idmask; int /*<<< orphan*/ * id; } ;
struct ipv6hdr {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  d_size; } ;
struct TYPE_3__ {int lltype; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int EINVAL ; 
#define  LOWPAN_LLTYPE_IEEE802154 132 
 int LOWPAN_NHC_UDP_4BIT_MASK ; 
 int LOWPAN_NHC_UDP_4BIT_PORT ; 
 int LOWPAN_NHC_UDP_8BIT_MASK ; 
 int LOWPAN_NHC_UDP_8BIT_PORT ; 
 int LOWPAN_NHC_UDP_CS_C ; 
#define  LOWPAN_NHC_UDP_CS_P_00 131 
#define  LOWPAN_NHC_UDP_CS_P_01 130 
#define  LOWPAN_NHC_UDP_CS_P_10 129 
#define  LOWPAN_NHC_UDP_CS_P_11 128 
 int /*<<< orphan*/  LOWPAN_NHC_UDP_ID ; 
 int /*<<< orphan*/  LOWPAN_NHC_UDP_MASK ; 
 void* htons (int /*<<< orphan*/ ) ; 
 TYPE_2__* lowpan_802154_cb (struct sk_buff*) ; 
 TYPE_1__* lowpan_dev (int /*<<< orphan*/ ) ; 
 int lowpan_fetch_skb (struct sk_buff*,int*,int) ; 
 int /*<<< orphan*/  lowpan_push_hc_data (int**,int*,int) ; 
 int ntohs (int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_debug_ratelimited (char*) ; 
 int /*<<< orphan*/  skb_copy_to_linear_data (struct sk_buff*,struct udphdr*,int) ; 
 int skb_cow (struct sk_buff*,size_t) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,int) ; 
 struct udphdr* udp_hdr (struct sk_buff*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int udp_uncompress(struct sk_buff *skb, size_t needed)
{
	u8 tmp = 0, val = 0;
	struct udphdr uh;
	bool fail;
	int err;

	fail = lowpan_fetch_skb(skb, &tmp, sizeof(tmp));

	pr_debug("UDP header uncompression\n");
	switch (tmp & LOWPAN_NHC_UDP_CS_P_11) {
	case LOWPAN_NHC_UDP_CS_P_00:
		fail |= lowpan_fetch_skb(skb, &uh.source, sizeof(uh.source));
		fail |= lowpan_fetch_skb(skb, &uh.dest, sizeof(uh.dest));
		break;
	case LOWPAN_NHC_UDP_CS_P_01:
		fail |= lowpan_fetch_skb(skb, &uh.source, sizeof(uh.source));
		fail |= lowpan_fetch_skb(skb, &val, sizeof(val));
		uh.dest = htons(val + LOWPAN_NHC_UDP_8BIT_PORT);
		break;
	case LOWPAN_NHC_UDP_CS_P_10:
		fail |= lowpan_fetch_skb(skb, &val, sizeof(val));
		uh.source = htons(val + LOWPAN_NHC_UDP_8BIT_PORT);
		fail |= lowpan_fetch_skb(skb, &uh.dest, sizeof(uh.dest));
		break;
	case LOWPAN_NHC_UDP_CS_P_11:
		fail |= lowpan_fetch_skb(skb, &val, sizeof(val));
		uh.source = htons(LOWPAN_NHC_UDP_4BIT_PORT + (val >> 4));
		uh.dest = htons(LOWPAN_NHC_UDP_4BIT_PORT + (val & 0x0f));
		break;
	default:
		BUG();
	}

	pr_debug("uncompressed UDP ports: src = %d, dst = %d\n",
		 ntohs(uh.source), ntohs(uh.dest));

	/* checksum */
	if (tmp & LOWPAN_NHC_UDP_CS_C) {
		pr_debug_ratelimited("checksum elided currently not supported\n");
		fail = true;
	} else {
		fail |= lowpan_fetch_skb(skb, &uh.check, sizeof(uh.check));
	}

	if (fail)
		return -EINVAL;

	/* UDP length needs to be infered from the lower layers
	 * here, we obtain the hint from the remaining size of the
	 * frame
	 */
	switch (lowpan_dev(skb->dev)->lltype) {
	case LOWPAN_LLTYPE_IEEE802154:
		if (lowpan_802154_cb(skb)->d_size)
			uh.len = htons(lowpan_802154_cb(skb)->d_size -
				       sizeof(struct ipv6hdr));
		else
			uh.len = htons(skb->len + sizeof(struct udphdr));
		break;
	default:
		uh.len = htons(skb->len + sizeof(struct udphdr));
		break;
	}
	pr_debug("uncompressed UDP length: src = %d", ntohs(uh.len));

	/* replace the compressed UDP head by the uncompressed UDP
	 * header
	 */
	err = skb_cow(skb, needed);
	if (unlikely(err))
		return err;

	skb_push(skb, sizeof(struct udphdr));
	skb_copy_to_linear_data(skb, &uh, sizeof(struct udphdr));

	return 0;
}

__attribute__((used)) static int udp_compress(struct sk_buff *skb, u8 **hc_ptr)
{
	const struct udphdr *uh = udp_hdr(skb);
	u8 tmp;

	if (((ntohs(uh->source) & LOWPAN_NHC_UDP_4BIT_MASK) ==
	     LOWPAN_NHC_UDP_4BIT_PORT) &&
	    ((ntohs(uh->dest) & LOWPAN_NHC_UDP_4BIT_MASK) ==
	     LOWPAN_NHC_UDP_4BIT_PORT)) {
		pr_debug("UDP header: both ports compression to 4 bits\n");
		/* compression value */
		tmp = LOWPAN_NHC_UDP_CS_P_11;
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
		/* source and destination port */
		tmp = ntohs(uh->dest) - LOWPAN_NHC_UDP_4BIT_PORT +
		      ((ntohs(uh->source) - LOWPAN_NHC_UDP_4BIT_PORT) << 4);
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
	} else if ((ntohs(uh->dest) & LOWPAN_NHC_UDP_8BIT_MASK) ==
			LOWPAN_NHC_UDP_8BIT_PORT) {
		pr_debug("UDP header: remove 8 bits of dest\n");
		/* compression value */
		tmp = LOWPAN_NHC_UDP_CS_P_01;
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
		/* source port */
		lowpan_push_hc_data(hc_ptr, &uh->source, sizeof(uh->source));
		/* destination port */
		tmp = ntohs(uh->dest) - LOWPAN_NHC_UDP_8BIT_PORT;
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
	} else if ((ntohs(uh->source) & LOWPAN_NHC_UDP_8BIT_MASK) ==
			LOWPAN_NHC_UDP_8BIT_PORT) {
		pr_debug("UDP header: remove 8 bits of source\n");
		/* compression value */
		tmp = LOWPAN_NHC_UDP_CS_P_10;
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
		/* source port */
		tmp = ntohs(uh->source) - LOWPAN_NHC_UDP_8BIT_PORT;
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
		/* destination port */
		lowpan_push_hc_data(hc_ptr, &uh->dest, sizeof(uh->dest));
	} else {
		pr_debug("UDP header: can't compress\n");
		/* compression value */
		tmp = LOWPAN_NHC_UDP_CS_P_00;
		lowpan_push_hc_data(hc_ptr, &tmp, sizeof(tmp));
		/* source port */
		lowpan_push_hc_data(hc_ptr, &uh->source, sizeof(uh->source));
		/* destination port */
		lowpan_push_hc_data(hc_ptr, &uh->dest, sizeof(uh->dest));
	}

	/* checksum is always inline */
	lowpan_push_hc_data(hc_ptr, &uh->check, sizeof(uh->check));

	return 0;
}

__attribute__((used)) static void udp_nhid_setup(struct lowpan_nhc *nhc)
{
	nhc->id[0] = LOWPAN_NHC_UDP_ID;
	nhc->idmask[0] = LOWPAN_NHC_UDP_MASK;
}


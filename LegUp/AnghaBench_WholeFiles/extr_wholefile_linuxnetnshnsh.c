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
typedef  scalar_t__ u8 ;
struct sk_buff {unsigned int mac_len; int network_header; int mac_header; scalar_t__ protocol; struct sk_buff* next; scalar_t__ data; } ;
typedef  struct nshhdr {scalar_t__ np; } const nshhdr ;
typedef  int /*<<< orphan*/  netdev_features_t ;
typedef  scalar_t__ __be16 ;

/* Variables and functions */
 int EAFNOSUPPORT ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct sk_buff* ERR_PTR (int) ; 
 unsigned int ETH_HLEN ; 
 int /*<<< orphan*/  ETH_P_NSH ; 
 int /*<<< orphan*/  ETH_P_TEB ; 
 scalar_t__ IS_ERR_OR_NULL (struct sk_buff*) ; 
 int /*<<< orphan*/  NETIF_F_SG ; 
 size_t NSH_BASE_HDR_LEN ; 
 scalar_t__ TUN_P_ETHERNET ; 
 int /*<<< orphan*/  __skb_pull (struct sk_buff*,unsigned int) ; 
 int /*<<< orphan*/  __skb_push (struct sk_buff*,unsigned int) ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct nshhdr const*,struct nshhdr const*,size_t) ; 
 struct nshhdr const* nsh_hdr (struct sk_buff*) ; 
 void* nsh_hdr_len (struct nshhdr const*) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,unsigned int) ; 
 scalar_t__ skb_cow_head (struct sk_buff*,size_t) ; 
 int /*<<< orphan*/  skb_gso_error_unwind (struct sk_buff*,scalar_t__,unsigned int,int,unsigned int) ; 
 struct sk_buff* skb_mac_gso_segment (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_postpush_rcsum (struct sk_buff*,struct nshhdr const*,size_t) ; 
 int /*<<< orphan*/  skb_pull_rcsum (struct sk_buff*,size_t) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,size_t) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_mac_len (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_mac_header (struct sk_buff*,int) ; 
 scalar_t__ tun_p_from_eth_p (scalar_t__) ; 
 scalar_t__ tun_p_to_eth_p (scalar_t__) ; 
 scalar_t__ unlikely (int) ; 

int nsh_push(struct sk_buff *skb, const struct nshhdr *pushed_nh)
{
	struct nshhdr *nh;
	size_t length = nsh_hdr_len(pushed_nh);
	u8 next_proto;

	if (skb->mac_len) {
		next_proto = TUN_P_ETHERNET;
	} else {
		next_proto = tun_p_from_eth_p(skb->protocol);
		if (!next_proto)
			return -EAFNOSUPPORT;
	}

	/* Add the NSH header */
	if (skb_cow_head(skb, length) < 0)
		return -ENOMEM;

	skb_push(skb, length);
	nh = (struct nshhdr *)(skb->data);
	memcpy(nh, pushed_nh, length);
	nh->np = next_proto;
	skb_postpush_rcsum(skb, nh, length);

	skb->protocol = htons(ETH_P_NSH);
	skb_reset_mac_header(skb);
	skb_reset_network_header(skb);
	skb_reset_mac_len(skb);

	return 0;
}

int nsh_pop(struct sk_buff *skb)
{
	struct nshhdr *nh;
	size_t length;
	__be16 inner_proto;

	if (!pskb_may_pull(skb, NSH_BASE_HDR_LEN))
		return -ENOMEM;
	nh = (struct nshhdr *)(skb->data);
	length = nsh_hdr_len(nh);
	if (length < NSH_BASE_HDR_LEN)
		return -EINVAL;
	inner_proto = tun_p_to_eth_p(nh->np);
	if (!pskb_may_pull(skb, length))
		return -ENOMEM;

	if (!inner_proto)
		return -EAFNOSUPPORT;

	skb_pull_rcsum(skb, length);
	skb_reset_mac_header(skb);
	skb_reset_network_header(skb);
	skb_reset_mac_len(skb);
	skb->protocol = inner_proto;

	return 0;
}

__attribute__((used)) static struct sk_buff *nsh_gso_segment(struct sk_buff *skb,
				       netdev_features_t features)
{
	struct sk_buff *segs = ERR_PTR(-EINVAL);
	unsigned int nsh_len, mac_len;
	__be16 proto;
	int nhoff;

	skb_reset_network_header(skb);

	nhoff = skb->network_header - skb->mac_header;
	mac_len = skb->mac_len;

	if (unlikely(!pskb_may_pull(skb, NSH_BASE_HDR_LEN)))
		goto out;
	nsh_len = nsh_hdr_len(nsh_hdr(skb));
	if (nsh_len < NSH_BASE_HDR_LEN)
		goto out;
	if (unlikely(!pskb_may_pull(skb, nsh_len)))
		goto out;

	proto = tun_p_to_eth_p(nsh_hdr(skb)->np);
	if (!proto)
		goto out;

	__skb_pull(skb, nsh_len);

	skb_reset_mac_header(skb);
	skb->mac_len = proto == htons(ETH_P_TEB) ? ETH_HLEN : 0;
	skb->protocol = proto;

	features &= NETIF_F_SG;
	segs = skb_mac_gso_segment(skb, features);
	if (IS_ERR_OR_NULL(segs)) {
		skb_gso_error_unwind(skb, htons(ETH_P_NSH), nsh_len,
				     skb->network_header - nhoff,
				     mac_len);
		goto out;
	}

	for (skb = segs; skb; skb = skb->next) {
		skb->protocol = htons(ETH_P_NSH);
		__skb_push(skb, nsh_len);
		skb_set_mac_header(skb, -nhoff);
		skb->network_header = skb->mac_header + mac_len;
		skb->mac_len = mac_len;
	}

out:
	return segs;
}


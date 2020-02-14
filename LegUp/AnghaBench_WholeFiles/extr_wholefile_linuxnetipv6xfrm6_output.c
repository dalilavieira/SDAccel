#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct TYPE_9__ {scalar_t__ mode; } ;
struct xfrm_state {TYPE_3__* outer_mode; TYPE_1__ props; } ;
struct sock {scalar_t__ sk_family; int sk_protocol; int /*<<< orphan*/  sk_bound_dev_if; } ;
struct sk_buff {int ignore_df; int len; scalar_t__ protocol; struct sock* sk; int /*<<< orphan*/  dev; scalar_t__ encapsulation; } ;
struct net {int dummy; } ;
struct ipv6hdr {int /*<<< orphan*/  nexthdr; int /*<<< orphan*/  daddr; } ;
struct flowi6 {int /*<<< orphan*/  daddr; int /*<<< orphan*/  fl6_dport; int /*<<< orphan*/  flowi6_oif; } ;
struct dst_entry {int /*<<< orphan*/  dev; struct xfrm_state* xfrm; } ;
struct TYPE_15__ {int /*<<< orphan*/  protocol; } ;
struct TYPE_14__ {int dontfrag; } ;
struct TYPE_13__ {int /*<<< orphan*/  inet_dport; } ;
struct TYPE_12__ {int flags; } ;
struct TYPE_11__ {int (* output2 ) (struct xfrm_state*,struct sk_buff*) ;TYPE_2__* afinfo; } ;
struct TYPE_10__ {int (* output_finish ) (struct sock*,struct sk_buff*) ;} ;

/* Variables and functions */
 scalar_t__ AF_INET6 ; 
 int EMSGSIZE ; 
 int /*<<< orphan*/  ETH_P_IPV6 ; 
 int /*<<< orphan*/  ICMPV6_PKT_TOOBIG ; 
 TYPE_4__* IP6CB (struct sk_buff*) ; 
 int IP6SKB_REROUTED ; 
 int IPPROTO_RAW ; 
 int IPPROTO_UDP ; 
 int IPV6_MIN_MTU ; 
 int /*<<< orphan*/  NFPROTO_IPV6 ; 
 int NF_HOOK_COND (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct net*,struct sock*,struct sk_buff*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int (*) (struct net*,struct sock*,struct sk_buff*),int) ; 
 int /*<<< orphan*/  NF_INET_POST_ROUTING ; 
 TYPE_7__* XFRM_MODE_SKB_CB (struct sk_buff*) ; 
 scalar_t__ XFRM_MODE_TUNNEL ; 
 scalar_t__ dst_allfrag (struct dst_entry*) ; 
 int dst_mtu (struct dst_entry*) ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  icmpv6_send (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_6__* inet6_sk (struct sock*) ; 
 TYPE_5__* inet_sk (struct sock*) ; 
 struct ipv6hdr* inner_ipv6_hdr (struct sk_buff*) ; 
 int ip6_find_1stfragopt (struct sk_buff*,int /*<<< orphan*/ **) ; 
 int ip6_fragment (struct net*,struct sock*,struct sk_buff*,int (*) (struct net*,struct sock*,struct sk_buff*)) ; 
 int ip6_skb_dst_mtu (struct sk_buff*) ; 
 struct ipv6hdr* ipv6_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  ipv6_local_error (struct sock*,int,struct flowi6*,int) ; 
 int /*<<< orphan*/  ipv6_local_rxpmtu (struct sock*,struct flowi6*,int) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 struct dst_entry* skb_dst (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_gso_validate_network_len (struct sk_buff*,int) ; 
 scalar_t__ skb_is_gso (struct sk_buff*) ; 
 int stub1 (struct xfrm_state*,struct sk_buff*) ; 
 int stub2 (struct sock*,struct sk_buff*) ; 
 int stub3 (struct sock*,struct sk_buff*) ; 
 int xfrm6_extract_header (struct sk_buff*) ; 
 int xfrm_inner_extract_output (struct xfrm_state*,struct sk_buff*) ; 
 int /*<<< orphan*/  xfrm_local_error (struct sk_buff*,int) ; 
 int xfrm_output (struct sock*,struct sk_buff*) ; 

int xfrm6_find_1stfragopt(struct xfrm_state *x, struct sk_buff *skb,
			  u8 **prevhdr)
{
	return ip6_find_1stfragopt(skb, prevhdr);
}

__attribute__((used)) static int xfrm6_local_dontfrag(struct sk_buff *skb)
{
	int proto;
	struct sock *sk = skb->sk;

	if (sk) {
		if (sk->sk_family != AF_INET6)
			return 0;

		proto = sk->sk_protocol;
		if (proto == IPPROTO_UDP || proto == IPPROTO_RAW)
			return inet6_sk(sk)->dontfrag;
	}

	return 0;
}

__attribute__((used)) static void xfrm6_local_rxpmtu(struct sk_buff *skb, u32 mtu)
{
	struct flowi6 fl6;
	struct sock *sk = skb->sk;

	fl6.flowi6_oif = sk->sk_bound_dev_if;
	fl6.daddr = ipv6_hdr(skb)->daddr;

	ipv6_local_rxpmtu(sk, &fl6, mtu);
}

void xfrm6_local_error(struct sk_buff *skb, u32 mtu)
{
	struct flowi6 fl6;
	const struct ipv6hdr *hdr;
	struct sock *sk = skb->sk;

	hdr = skb->encapsulation ? inner_ipv6_hdr(skb) : ipv6_hdr(skb);
	fl6.fl6_dport = inet_sk(sk)->inet_dport;
	fl6.daddr = hdr->daddr;

	ipv6_local_error(sk, EMSGSIZE, &fl6, mtu);
}

__attribute__((used)) static int xfrm6_tunnel_check_size(struct sk_buff *skb)
{
	int mtu, ret = 0;
	struct dst_entry *dst = skb_dst(skb);

	if (skb->ignore_df)
		goto out;

	mtu = dst_mtu(dst);
	if (mtu < IPV6_MIN_MTU)
		mtu = IPV6_MIN_MTU;

	if ((!skb_is_gso(skb) && skb->len > mtu) ||
	    (skb_is_gso(skb) &&
	     !skb_gso_validate_network_len(skb, ip6_skb_dst_mtu(skb)))) {
		skb->dev = dst->dev;
		skb->protocol = htons(ETH_P_IPV6);

		if (xfrm6_local_dontfrag(skb))
			xfrm6_local_rxpmtu(skb, mtu);
		else if (skb->sk)
			xfrm_local_error(skb, mtu);
		else
			icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
		ret = -EMSGSIZE;
	}
out:
	return ret;
}

int xfrm6_extract_output(struct xfrm_state *x, struct sk_buff *skb)
{
	int err;

	err = xfrm6_tunnel_check_size(skb);
	if (err)
		return err;

	XFRM_MODE_SKB_CB(skb)->protocol = ipv6_hdr(skb)->nexthdr;

	return xfrm6_extract_header(skb);
}

int xfrm6_prepare_output(struct xfrm_state *x, struct sk_buff *skb)
{
	int err;

	err = xfrm_inner_extract_output(x, skb);
	if (err)
		return err;

	skb->ignore_df = 1;
	skb->protocol = htons(ETH_P_IPV6);

	return x->outer_mode->output2(x, skb);
}

int xfrm6_output_finish(struct sock *sk, struct sk_buff *skb)
{
	memset(IP6CB(skb), 0, sizeof(*IP6CB(skb)));

#ifdef CONFIG_NETFILTER
	IP6CB(skb)->flags |= IP6SKB_XFRM_TRANSFORMED;
#endif

	return xfrm_output(sk, skb);
}

__attribute__((used)) static int __xfrm6_output_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
	struct xfrm_state *x = skb_dst(skb)->xfrm;

	return x->outer_mode->afinfo->output_finish(sk, skb);
}

__attribute__((used)) static int __xfrm6_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
	struct dst_entry *dst = skb_dst(skb);
	struct xfrm_state *x = dst->xfrm;
	int mtu;
	bool toobig;

#ifdef CONFIG_NETFILTER
	if (!x) {
		IP6CB(skb)->flags |= IP6SKB_REROUTED;
		return dst_output(net, sk, skb);
	}
#endif

	if (x->props.mode != XFRM_MODE_TUNNEL)
		goto skip_frag;

	if (skb->protocol == htons(ETH_P_IPV6))
		mtu = ip6_skb_dst_mtu(skb);
	else
		mtu = dst_mtu(skb_dst(skb));

	toobig = skb->len > mtu && !skb_is_gso(skb);

	if (toobig && xfrm6_local_dontfrag(skb)) {
		xfrm6_local_rxpmtu(skb, mtu);
		kfree_skb(skb);
		return -EMSGSIZE;
	} else if (!skb->ignore_df && toobig && skb->sk) {
		xfrm_local_error(skb, mtu);
		kfree_skb(skb);
		return -EMSGSIZE;
	}

	if (toobig || dst_allfrag(skb_dst(skb)))
		return ip6_fragment(net, sk, skb,
				    __xfrm6_output_finish);

skip_frag:
	return x->outer_mode->afinfo->output_finish(sk, skb);
}

int xfrm6_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
	return NF_HOOK_COND(NFPROTO_IPV6, NF_INET_POST_ROUTING,
			    net, sk, skb,  NULL, skb_dst(skb)->dev,
			    __xfrm6_output,
			    !(IP6CB(skb)->flags & IP6SKB_REROUTED));
}


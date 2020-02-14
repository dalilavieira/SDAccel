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
struct sk_buff {int dummy; } ;
struct nft_pktinfo {int dummy; } ;
struct nf_hook_state {int dummy; } ;
struct nf_hook_ops {int dummy; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int nf_nat_l3proto_ipv6_register_fn (struct net*,struct nf_hook_ops const*) ; 
 int /*<<< orphan*/  nf_nat_l3proto_ipv6_unregister_fn (struct net*,struct nf_hook_ops const*) ; 
 unsigned int nft_do_chain (struct nft_pktinfo*,void*) ; 
 int /*<<< orphan*/  nft_set_pktinfo (struct nft_pktinfo*,struct sk_buff*,struct nf_hook_state const*) ; 
 int /*<<< orphan*/  nft_set_pktinfo_ipv6 (struct nft_pktinfo*,struct sk_buff*) ; 

__attribute__((used)) static unsigned int nft_nat_do_chain(void *priv,
				     struct sk_buff *skb,
				     const struct nf_hook_state *state)
{
	struct nft_pktinfo pkt;

	nft_set_pktinfo(&pkt, skb, state);
	nft_set_pktinfo_ipv6(&pkt, skb);

	return nft_do_chain(&pkt, priv);
}

__attribute__((used)) static int nft_nat_ipv6_reg(struct net *net, const struct nf_hook_ops *ops)
{
	return nf_nat_l3proto_ipv6_register_fn(net, ops);
}

__attribute__((used)) static void nft_nat_ipv6_unreg(struct net *net, const struct nf_hook_ops *ops)
{
	nf_nat_l3proto_ipv6_unregister_fn(net, ops);
}


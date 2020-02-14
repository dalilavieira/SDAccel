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
struct sk_buff {struct net_device* dev; int /*<<< orphan*/  protocol; } ;
struct nlattr {int dummy; } ;
struct TYPE_2__ {unsigned int code; } ;
struct nft_regs {int* data; TYPE_1__ verdict; } ;
struct nft_pktinfo {struct sk_buff* skb; } ;
struct nft_fwd_netdev {size_t sreg_dev; } ;
struct nft_fwd_neigh {size_t sreg_addr; size_t sreg_dev; int nfproto; } ;
struct nft_expr_ops {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;
struct net_device {int dummy; } ;
struct ipv6hdr {int /*<<< orphan*/  hop_limit; } ;
struct iphdr {int dummy; } ;
struct in_addr {int dummy; } ;
struct in6_addr {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 struct nft_expr_ops const* ERR_PTR (int) ; 
 int /*<<< orphan*/  ETH_P_IP ; 
 int /*<<< orphan*/  ETH_P_IPV6 ; 
 int NEIGH_ARP_TABLE ; 
 int NEIGH_ND_TABLE ; 
#define  NFPROTO_IPV4 129 
#define  NFPROTO_IPV6 128 
 size_t NFTA_FWD_NFPROTO ; 
 size_t NFTA_FWD_SREG_ADDR ; 
 size_t NFTA_FWD_SREG_DEV ; 
 unsigned int NFT_BREAK ; 
 unsigned int NF_DROP ; 
 void* NF_STOLEN ; 
 struct net_device* dev_get_by_index_rcu (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  htonl (int) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip_decrease_ttl (struct iphdr*) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 struct ipv6hdr* ipv6_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  neigh_xmit (int,struct net_device*,void*,struct sk_buff*) ; 
 int /*<<< orphan*/  nf_fwd_netdev_egress (struct nft_pktinfo const*,int) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 struct nft_expr_ops const nft_fwd_neigh_netdev_ops ; 
 struct nft_expr_ops const nft_fwd_netdev_ops ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 void* nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_load (size_t,unsigned int) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_try_make_writable (struct sk_buff*,int) ; 

__attribute__((used)) static void nft_fwd_netdev_eval(const struct nft_expr *expr,
				struct nft_regs *regs,
				const struct nft_pktinfo *pkt)
{
	struct nft_fwd_netdev *priv = nft_expr_priv(expr);
	int oif = regs->data[priv->sreg_dev];

	nf_fwd_netdev_egress(pkt, oif);
	regs->verdict.code = NF_STOLEN;
}

__attribute__((used)) static int nft_fwd_netdev_init(const struct nft_ctx *ctx,
			       const struct nft_expr *expr,
			       const struct nlattr * const tb[])
{
	struct nft_fwd_netdev *priv = nft_expr_priv(expr);

	if (tb[NFTA_FWD_SREG_DEV] == NULL)
		return -EINVAL;

	priv->sreg_dev = nft_parse_register(tb[NFTA_FWD_SREG_DEV]);
	return nft_validate_register_load(priv->sreg_dev, sizeof(int));
}

__attribute__((used)) static int nft_fwd_netdev_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_fwd_netdev *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_FWD_SREG_DEV, priv->sreg_dev))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static void nft_fwd_neigh_eval(const struct nft_expr *expr,
			      struct nft_regs *regs,
			      const struct nft_pktinfo *pkt)
{
	struct nft_fwd_neigh *priv = nft_expr_priv(expr);
	void *addr = &regs->data[priv->sreg_addr];
	int oif = regs->data[priv->sreg_dev];
	unsigned int verdict = NF_STOLEN;
	struct sk_buff *skb = pkt->skb;
	struct net_device *dev;
	int neigh_table;

	switch (priv->nfproto) {
	case NFPROTO_IPV4: {
		struct iphdr *iph;

		if (skb->protocol != htons(ETH_P_IP)) {
			verdict = NFT_BREAK;
			goto out;
		}
		if (skb_try_make_writable(skb, sizeof(*iph))) {
			verdict = NF_DROP;
			goto out;
		}
		iph = ip_hdr(skb);
		ip_decrease_ttl(iph);
		neigh_table = NEIGH_ARP_TABLE;
		break;
		}
	case NFPROTO_IPV6: {
		struct ipv6hdr *ip6h;

		if (skb->protocol != htons(ETH_P_IPV6)) {
			verdict = NFT_BREAK;
			goto out;
		}
		if (skb_try_make_writable(skb, sizeof(*ip6h))) {
			verdict = NF_DROP;
			goto out;
		}
		ip6h = ipv6_hdr(skb);
		ip6h->hop_limit--;
		neigh_table = NEIGH_ND_TABLE;
		break;
		}
	default:
		verdict = NFT_BREAK;
		goto out;
	}

	dev = dev_get_by_index_rcu(nft_net(pkt), oif);
	if (dev == NULL)
		return;

	skb->dev = dev;
	neigh_xmit(neigh_table, dev, addr, skb);
out:
	regs->verdict.code = verdict;
}

__attribute__((used)) static int nft_fwd_neigh_init(const struct nft_ctx *ctx,
			      const struct nft_expr *expr,
			      const struct nlattr * const tb[])
{
	struct nft_fwd_neigh *priv = nft_expr_priv(expr);
	unsigned int addr_len;
	int err;

	if (!tb[NFTA_FWD_SREG_DEV] ||
	    !tb[NFTA_FWD_SREG_ADDR] ||
	    !tb[NFTA_FWD_NFPROTO])
		return -EINVAL;

	priv->sreg_dev = nft_parse_register(tb[NFTA_FWD_SREG_DEV]);
	priv->sreg_addr = nft_parse_register(tb[NFTA_FWD_SREG_ADDR]);
	priv->nfproto = ntohl(nla_get_be32(tb[NFTA_FWD_NFPROTO]));

	switch (priv->nfproto) {
	case NFPROTO_IPV4:
		addr_len = sizeof(struct in_addr);
		break;
	case NFPROTO_IPV6:
		addr_len = sizeof(struct in6_addr);
		break;
	default:
		return -EOPNOTSUPP;
	}

	err = nft_validate_register_load(priv->sreg_dev, sizeof(int));
	if (err < 0)
		return err;

	return nft_validate_register_load(priv->sreg_addr, addr_len);
}

__attribute__((used)) static int nft_fwd_neigh_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_fwd_neigh *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_FWD_SREG_DEV, priv->sreg_dev) ||
	    nft_dump_register(skb, NFTA_FWD_SREG_ADDR, priv->sreg_addr) ||
	    nla_put_be32(skb, NFTA_FWD_NFPROTO, htonl(priv->nfproto)))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static const struct nft_expr_ops *
nft_fwd_select_ops(const struct nft_ctx *ctx,
		   const struct nlattr * const tb[])
{
	if (tb[NFTA_FWD_SREG_ADDR])
		return &nft_fwd_neigh_netdev_ops;
	if (tb[NFTA_FWD_SREG_DEV])
		return &nft_fwd_netdev_ops;

        return ERR_PTR(-EOPNOTSUPP);
}


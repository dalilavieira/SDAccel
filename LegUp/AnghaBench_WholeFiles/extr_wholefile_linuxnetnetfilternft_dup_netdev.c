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
struct nlattr {int dummy; } ;
struct nft_regs {int* data; } ;
struct nft_pktinfo {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_dup_netdev {size_t sreg_dev; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t NFTA_DUP_SREG_DEV ; 
 int /*<<< orphan*/  nf_dup_netdev_egress (struct nft_pktinfo const*,int) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 struct nft_dup_netdev* nft_expr_priv (struct nft_expr const*) ; 
 size_t nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_load (size_t,int) ; 

__attribute__((used)) static void nft_dup_netdev_eval(const struct nft_expr *expr,
				struct nft_regs *regs,
				const struct nft_pktinfo *pkt)
{
	struct nft_dup_netdev *priv = nft_expr_priv(expr);
	int oif = regs->data[priv->sreg_dev];

	nf_dup_netdev_egress(pkt, oif);
}

__attribute__((used)) static int nft_dup_netdev_init(const struct nft_ctx *ctx,
			       const struct nft_expr *expr,
			       const struct nlattr * const tb[])
{
	struct nft_dup_netdev *priv = nft_expr_priv(expr);

	if (tb[NFTA_DUP_SREG_DEV] == NULL)
		return -EINVAL;

	priv->sreg_dev = nft_parse_register(tb[NFTA_DUP_SREG_DEV]);
	return nft_validate_register_load(priv->sreg_dev, sizeof(int));
}

__attribute__((used)) static int nft_dup_netdev_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_dup_netdev *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_DUP_SREG_DEV, priv->sreg_dev))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}


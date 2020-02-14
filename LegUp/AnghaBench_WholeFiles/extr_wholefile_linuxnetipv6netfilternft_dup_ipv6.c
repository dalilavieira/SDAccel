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
struct nft_pktinfo {int /*<<< orphan*/  skb; } ;
struct nft_expr {int dummy; } ;
struct nft_dup_ipv6 {size_t sreg_addr; int sreg_dev; } ;
struct nft_ctx {int dummy; } ;
struct in6_addr {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t NFTA_DUP_SREG_ADDR ; 
 size_t NFTA_DUP_SREG_DEV ; 
 int /*<<< orphan*/  nf_dup_ipv6 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct in6_addr*,int) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 struct nft_dup_ipv6* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nft_hook (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 void* nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_load (size_t,int) ; 

__attribute__((used)) static void nft_dup_ipv6_eval(const struct nft_expr *expr,
			      struct nft_regs *regs,
			      const struct nft_pktinfo *pkt)
{
	struct nft_dup_ipv6 *priv = nft_expr_priv(expr);
	struct in6_addr *gw = (struct in6_addr *)&regs->data[priv->sreg_addr];
	int oif = priv->sreg_dev ? regs->data[priv->sreg_dev] : -1;

	nf_dup_ipv6(nft_net(pkt), pkt->skb, nft_hook(pkt), gw, oif);
}

__attribute__((used)) static int nft_dup_ipv6_init(const struct nft_ctx *ctx,
			     const struct nft_expr *expr,
			     const struct nlattr * const tb[])
{
	struct nft_dup_ipv6 *priv = nft_expr_priv(expr);
	int err;

	if (tb[NFTA_DUP_SREG_ADDR] == NULL)
		return -EINVAL;

	priv->sreg_addr = nft_parse_register(tb[NFTA_DUP_SREG_ADDR]);
	err = nft_validate_register_load(priv->sreg_addr, sizeof(struct in6_addr));
	if (err < 0)
		return err;

	if (tb[NFTA_DUP_SREG_DEV] != NULL) {
		priv->sreg_dev = nft_parse_register(tb[NFTA_DUP_SREG_DEV]);
		return nft_validate_register_load(priv->sreg_dev, sizeof(int));
	}
	return 0;
}

__attribute__((used)) static int nft_dup_ipv6_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_dup_ipv6 *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_DUP_SREG_ADDR, priv->sreg_addr))
		goto nla_put_failure;
	if (priv->sreg_dev &&
	    nft_dump_register(skb, NFTA_DUP_SREG_DEV, priv->sreg_dev))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}


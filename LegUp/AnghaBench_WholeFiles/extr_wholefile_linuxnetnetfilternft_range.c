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
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct TYPE_2__ {void* code; } ;
struct nft_regs {TYPE_1__ verdict; int /*<<< orphan*/ * data; } ;
struct nft_range_expr {size_t sreg; scalar_t__ len; int op; int /*<<< orphan*/  data_to; int /*<<< orphan*/  data_from; } ;
struct nft_pktinfo {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_data_desc {scalar_t__ len; int /*<<< orphan*/  type; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t NFTA_RANGE_FROM_DATA ; 
 size_t NFTA_RANGE_OP ; 
 size_t NFTA_RANGE_SREG ; 
 size_t NFTA_RANGE_TO_DATA ; 
 void* NFT_BREAK ; 
 int /*<<< orphan*/  NFT_DATA_VALUE ; 
#define  NFT_RANGE_EQ 129 
#define  NFT_RANGE_NEQ 128 
 int /*<<< orphan*/  U8_MAX ; 
 int /*<<< orphan*/  htonl (int) ; 
 int memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ nft_data_dump (struct sk_buff*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int nft_data_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,struct nft_data_desc*,struct nlattr const* const) ; 
 int /*<<< orphan*/  nft_data_release (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 size_t nft_parse_register (struct nlattr const* const) ; 
 int nft_parse_u32_check (struct nlattr const* const,int /*<<< orphan*/ ,int*) ; 
 int nft_validate_register_load (size_t,scalar_t__) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nft_range_eval(const struct nft_expr *expr,
			 struct nft_regs *regs,
			 const struct nft_pktinfo *pkt)
{
	const struct nft_range_expr *priv = nft_expr_priv(expr);
	int d1, d2;

	d1 = memcmp(&regs->data[priv->sreg], &priv->data_from, priv->len);
	d2 = memcmp(&regs->data[priv->sreg], &priv->data_to, priv->len);
	switch (priv->op) {
	case NFT_RANGE_EQ:
		if (d1 < 0 || d2 > 0)
			regs->verdict.code = NFT_BREAK;
		break;
	case NFT_RANGE_NEQ:
		if (d1 >= 0 && d2 <= 0)
			regs->verdict.code = NFT_BREAK;
		break;
	}
}

__attribute__((used)) static int nft_range_init(const struct nft_ctx *ctx, const struct nft_expr *expr,
			const struct nlattr * const tb[])
{
	struct nft_range_expr *priv = nft_expr_priv(expr);
	struct nft_data_desc desc_from, desc_to;
	int err;
	u32 op;

	if (!tb[NFTA_RANGE_SREG]      ||
	    !tb[NFTA_RANGE_OP]	      ||
	    !tb[NFTA_RANGE_FROM_DATA] ||
	    !tb[NFTA_RANGE_TO_DATA])
		return -EINVAL;

	err = nft_data_init(NULL, &priv->data_from, sizeof(priv->data_from),
			    &desc_from, tb[NFTA_RANGE_FROM_DATA]);
	if (err < 0)
		return err;

	err = nft_data_init(NULL, &priv->data_to, sizeof(priv->data_to),
			    &desc_to, tb[NFTA_RANGE_TO_DATA]);
	if (err < 0)
		goto err1;

	if (desc_from.len != desc_to.len) {
		err = -EINVAL;
		goto err2;
	}

	priv->sreg = nft_parse_register(tb[NFTA_RANGE_SREG]);
	err = nft_validate_register_load(priv->sreg, desc_from.len);
	if (err < 0)
		goto err2;

	err = nft_parse_u32_check(tb[NFTA_RANGE_OP], U8_MAX, &op);
	if (err < 0)
		goto err2;

	switch (op) {
	case NFT_RANGE_EQ:
	case NFT_RANGE_NEQ:
		break;
	default:
		err = -EINVAL;
		goto err2;
	}

	priv->op  = op;
	priv->len = desc_from.len;
	return 0;
err2:
	nft_data_release(&priv->data_to, desc_to.type);
err1:
	nft_data_release(&priv->data_from, desc_from.type);
	return err;
}

__attribute__((used)) static int nft_range_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_range_expr *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_RANGE_SREG, priv->sreg))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_RANGE_OP, htonl(priv->op)))
		goto nla_put_failure;

	if (nft_data_dump(skb, NFTA_RANGE_FROM_DATA, &priv->data_from,
			  NFT_DATA_VALUE, priv->len) < 0 ||
	    nft_data_dump(skb, NFTA_RANGE_TO_DATA, &priv->data_to,
			  NFT_DATA_VALUE, priv->len) < 0)
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}


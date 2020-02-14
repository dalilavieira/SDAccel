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
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_regs {int /*<<< orphan*/ * data; } ;
struct nft_pktinfo {int dummy; } ;
struct TYPE_2__ {int code; int /*<<< orphan*/  chain; } ;
struct nft_data {TYPE_1__ verdict; } ;
struct nft_immediate_expr {size_t dreg; struct nft_data data; int /*<<< orphan*/  dlen; } ;
struct nft_expr {int dummy; } ;
struct nft_data_desc {int /*<<< orphan*/  type; int /*<<< orphan*/  len; } ;
struct nft_ctx {int /*<<< orphan*/  level; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t NFTA_IMMEDIATE_DATA ; 
 size_t NFTA_IMMEDIATE_DREG ; 
#define  NFT_GOTO 129 
#define  NFT_JUMP 128 
 scalar_t__ NFT_REG_VERDICT ; 
 int nft_chain_validate (struct nft_ctx const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nft_data_copy (int /*<<< orphan*/ *,struct nft_data*,int /*<<< orphan*/ ) ; 
 int nft_data_dump (struct sk_buff*,size_t,struct nft_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void nft_data_hold (struct nft_data*,int /*<<< orphan*/ ) ; 
 int nft_data_init (struct nft_ctx const*,struct nft_data*,int,struct nft_data_desc*,struct nlattr const* const) ; 
 void nft_data_release (struct nft_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nft_dreg_to_type (size_t) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 size_t nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_store (struct nft_ctx const*,size_t,struct nft_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nft_immediate_eval(const struct nft_expr *expr,
			       struct nft_regs *regs,
			       const struct nft_pktinfo *pkt)
{
	const struct nft_immediate_expr *priv = nft_expr_priv(expr);

	nft_data_copy(&regs->data[priv->dreg], &priv->data, priv->dlen);
}

__attribute__((used)) static int nft_immediate_init(const struct nft_ctx *ctx,
			      const struct nft_expr *expr,
			      const struct nlattr * const tb[])
{
	struct nft_immediate_expr *priv = nft_expr_priv(expr);
	struct nft_data_desc desc;
	int err;

	if (tb[NFTA_IMMEDIATE_DREG] == NULL ||
	    tb[NFTA_IMMEDIATE_DATA] == NULL)
		return -EINVAL;

	err = nft_data_init(ctx, &priv->data, sizeof(priv->data), &desc,
			    tb[NFTA_IMMEDIATE_DATA]);
	if (err < 0)
		return err;

	priv->dlen = desc.len;

	priv->dreg = nft_parse_register(tb[NFTA_IMMEDIATE_DREG]);
	err = nft_validate_register_store(ctx, priv->dreg, &priv->data,
					  desc.type, desc.len);
	if (err < 0)
		goto err1;

	return 0;

err1:
	nft_data_release(&priv->data, desc.type);
	return err;
}

__attribute__((used)) static void nft_immediate_activate(const struct nft_ctx *ctx,
				   const struct nft_expr *expr)
{
	const struct nft_immediate_expr *priv = nft_expr_priv(expr);

	return nft_data_hold(&priv->data, nft_dreg_to_type(priv->dreg));
}

__attribute__((used)) static void nft_immediate_deactivate(const struct nft_ctx *ctx,
				     const struct nft_expr *expr)
{
	const struct nft_immediate_expr *priv = nft_expr_priv(expr);

	return nft_data_release(&priv->data, nft_dreg_to_type(priv->dreg));
}

__attribute__((used)) static int nft_immediate_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_immediate_expr *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_IMMEDIATE_DREG, priv->dreg))
		goto nla_put_failure;

	return nft_data_dump(skb, NFTA_IMMEDIATE_DATA, &priv->data,
			     nft_dreg_to_type(priv->dreg), priv->dlen);

nla_put_failure:
	return -1;
}

__attribute__((used)) static int nft_immediate_validate(const struct nft_ctx *ctx,
				  const struct nft_expr *expr,
				  const struct nft_data **d)
{
	const struct nft_immediate_expr *priv = nft_expr_priv(expr);
	struct nft_ctx *pctx = (struct nft_ctx *)ctx;
	const struct nft_data *data;
	int err;

	if (priv->dreg != NFT_REG_VERDICT)
		return 0;

	data = &priv->data;

	switch (data->verdict.code) {
	case NFT_JUMP:
	case NFT_GOTO:
		pctx->level++;
		err = nft_chain_validate(ctx, data->verdict.chain);
		if (err < 0)
			return err;
		pctx->level--;
		break;
	default:
		break;
	}

	return 0;
}


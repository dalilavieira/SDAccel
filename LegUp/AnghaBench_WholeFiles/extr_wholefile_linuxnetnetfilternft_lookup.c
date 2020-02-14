#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
typedef  int u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_set_iter {scalar_t__ err; int (* fn ) (struct nft_ctx const*,struct nft_set*,struct nft_set_iter const*,struct nft_set_elem*) ;scalar_t__ count; scalar_t__ skip; void* genmask; } ;
struct nft_set_ext {int dummy; } ;
struct nft_set_elem {int /*<<< orphan*/  priv; } ;
struct nft_set {int flags; scalar_t__ dtype; TYPE_1__* ops; int /*<<< orphan*/  name; int /*<<< orphan*/  dlen; int /*<<< orphan*/  klen; } ;
struct TYPE_7__ {int /*<<< orphan*/  code; } ;
struct nft_regs {int /*<<< orphan*/ * data; TYPE_2__ verdict; } ;
struct nft_pktinfo {int dummy; } ;
struct TYPE_9__ {int flags; } ;
struct nft_lookup {size_t sreg; int invert; size_t dreg; struct nft_set* set; TYPE_4__ binding; } ;
struct nft_expr {int dummy; } ;
struct TYPE_8__ {int code; int /*<<< orphan*/  chain; } ;
struct nft_data {TYPE_3__ verdict; } ;
struct nft_ctx {int /*<<< orphan*/  net; int /*<<< orphan*/  level; int /*<<< orphan*/  table; } ;
struct TYPE_6__ {int (* lookup ) (int /*<<< orphan*/ ,struct nft_set const*,int /*<<< orphan*/ *,struct nft_set_ext const**) ;int /*<<< orphan*/  (* walk ) (struct nft_ctx const*,struct nft_set*,struct nft_set_iter*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 scalar_t__ IS_ERR (struct nft_set*) ; 
 size_t NFTA_LOOKUP_DREG ; 
 size_t NFTA_LOOKUP_FLAGS ; 
 size_t NFTA_LOOKUP_SET ; 
 size_t NFTA_LOOKUP_SET_ID ; 
 size_t NFTA_LOOKUP_SREG ; 
 int /*<<< orphan*/  NFT_BREAK ; 
 scalar_t__ NFT_DATA_VERDICT ; 
#define  NFT_GOTO 129 
#define  NFT_JUMP 128 
 int NFT_LOOKUP_F_INV ; 
 int NFT_SET_ELEM_INTERVAL_END ; 
 int NFT_SET_EVAL ; 
 int /*<<< orphan*/  NFT_SET_EXT_FLAGS ; 
 int NFT_SET_MAP ; 
 int PTR_ERR (struct nft_set*) ; 
 int /*<<< orphan*/  htonl (int) ; 
 int nf_tables_bind_set (struct nft_ctx const*,struct nft_set*,TYPE_4__*) ; 
 int /*<<< orphan*/  nf_tables_unbind_set (struct nft_ctx const*,struct nft_set*,TYPE_4__*) ; 
 int nft_chain_validate (struct nft_ctx const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nft_data_copy (int /*<<< orphan*/ *,struct nft_data*,int /*<<< orphan*/ ) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 void* nft_genmask_next (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 void* nft_parse_register (struct nlattr const* const) ; 
 struct nft_set_ext* nft_set_elem_ext (struct nft_set*,int /*<<< orphan*/ ) ; 
 struct nft_data* nft_set_ext_data (struct nft_set_ext const*) ; 
 scalar_t__ nft_set_ext_exists (struct nft_set_ext const*,int /*<<< orphan*/ ) ; 
 int* nft_set_ext_flags (struct nft_set_ext const*) ; 
 struct nft_set* nft_set_lookup_global (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nlattr const* const,struct nlattr const* const,void*) ; 
 int nft_validate_register_load (size_t,int /*<<< orphan*/ ) ; 
 int nft_validate_register_store (struct nft_ctx const*,size_t,int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_string (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int stub1 (int /*<<< orphan*/ ,struct nft_set const*,int /*<<< orphan*/ *,struct nft_set_ext const**) ; 
 int /*<<< orphan*/  stub2 (struct nft_ctx const*,struct nft_set*,struct nft_set_iter*) ; 

void nft_lookup_eval(const struct nft_expr *expr,
		     struct nft_regs *regs,
		     const struct nft_pktinfo *pkt)
{
	const struct nft_lookup *priv = nft_expr_priv(expr);
	const struct nft_set *set = priv->set;
	const struct nft_set_ext *ext;
	bool found;

	found = set->ops->lookup(nft_net(pkt), set, &regs->data[priv->sreg],
				 &ext) ^ priv->invert;
	if (!found) {
		regs->verdict.code = NFT_BREAK;
		return;
	}

	if (set->flags & NFT_SET_MAP)
		nft_data_copy(&regs->data[priv->dreg],
			      nft_set_ext_data(ext), set->dlen);

}

__attribute__((used)) static int nft_lookup_init(const struct nft_ctx *ctx,
			   const struct nft_expr *expr,
			   const struct nlattr * const tb[])
{
	struct nft_lookup *priv = nft_expr_priv(expr);
	u8 genmask = nft_genmask_next(ctx->net);
	struct nft_set *set;
	u32 flags;
	int err;

	if (tb[NFTA_LOOKUP_SET] == NULL ||
	    tb[NFTA_LOOKUP_SREG] == NULL)
		return -EINVAL;

	set = nft_set_lookup_global(ctx->net, ctx->table, tb[NFTA_LOOKUP_SET],
				    tb[NFTA_LOOKUP_SET_ID], genmask);
	if (IS_ERR(set))
		return PTR_ERR(set);

	if (set->flags & NFT_SET_EVAL)
		return -EOPNOTSUPP;

	priv->sreg = nft_parse_register(tb[NFTA_LOOKUP_SREG]);
	err = nft_validate_register_load(priv->sreg, set->klen);
	if (err < 0)
		return err;

	if (tb[NFTA_LOOKUP_FLAGS]) {
		flags = ntohl(nla_get_be32(tb[NFTA_LOOKUP_FLAGS]));

		if (flags & ~NFT_LOOKUP_F_INV)
			return -EINVAL;

		if (flags & NFT_LOOKUP_F_INV) {
			if (set->flags & NFT_SET_MAP)
				return -EINVAL;
			priv->invert = true;
		}
	}

	if (tb[NFTA_LOOKUP_DREG] != NULL) {
		if (priv->invert)
			return -EINVAL;
		if (!(set->flags & NFT_SET_MAP))
			return -EINVAL;

		priv->dreg = nft_parse_register(tb[NFTA_LOOKUP_DREG]);
		err = nft_validate_register_store(ctx, priv->dreg, NULL,
						  set->dtype, set->dlen);
		if (err < 0)
			return err;
	} else if (set->flags & NFT_SET_MAP)
		return -EINVAL;

	priv->binding.flags = set->flags & NFT_SET_MAP;

	err = nf_tables_bind_set(ctx, set, &priv->binding);
	if (err < 0)
		return err;

	priv->set = set;
	return 0;
}

__attribute__((used)) static void nft_lookup_destroy(const struct nft_ctx *ctx,
			       const struct nft_expr *expr)
{
	struct nft_lookup *priv = nft_expr_priv(expr);

	nf_tables_unbind_set(ctx, priv->set, &priv->binding);
}

__attribute__((used)) static int nft_lookup_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_lookup *priv = nft_expr_priv(expr);
	u32 flags = priv->invert ? NFT_LOOKUP_F_INV : 0;

	if (nla_put_string(skb, NFTA_LOOKUP_SET, priv->set->name))
		goto nla_put_failure;
	if (nft_dump_register(skb, NFTA_LOOKUP_SREG, priv->sreg))
		goto nla_put_failure;
	if (priv->set->flags & NFT_SET_MAP)
		if (nft_dump_register(skb, NFTA_LOOKUP_DREG, priv->dreg))
			goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_LOOKUP_FLAGS, htonl(flags)))
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int nft_lookup_validate_setelem(const struct nft_ctx *ctx,
				       struct nft_set *set,
				       const struct nft_set_iter *iter,
				       struct nft_set_elem *elem)
{
	const struct nft_set_ext *ext = nft_set_elem_ext(set, elem->priv);
	struct nft_ctx *pctx = (struct nft_ctx *)ctx;
	const struct nft_data *data;
	int err;

	if (nft_set_ext_exists(ext, NFT_SET_EXT_FLAGS) &&
	    *nft_set_ext_flags(ext) & NFT_SET_ELEM_INTERVAL_END)
		return 0;

	data = nft_set_ext_data(ext);
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

__attribute__((used)) static int nft_lookup_validate(const struct nft_ctx *ctx,
			       const struct nft_expr *expr,
			       const struct nft_data **d)
{
	const struct nft_lookup *priv = nft_expr_priv(expr);
	struct nft_set_iter iter;

	if (!(priv->set->flags & NFT_SET_MAP) ||
	    priv->set->dtype != NFT_DATA_VERDICT)
		return 0;

	iter.genmask	= nft_genmask_next(ctx->net);
	iter.skip	= 0;
	iter.count	= 0;
	iter.err	= 0;
	iter.fn		= nft_lookup_validate_setelem;

	priv->set->ops->walk(ctx, priv->set, &iter);
	if (iter.err < 0)
		return iter.err;

	return 0;
}


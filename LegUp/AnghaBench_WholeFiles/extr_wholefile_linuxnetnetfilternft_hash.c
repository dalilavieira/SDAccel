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
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_symhash {int modulus; size_t dreg; scalar_t__ offset; struct nft_set* map; } ;
struct nft_set_ext {int dummy; } ;
struct nft_set {int /*<<< orphan*/  name; int /*<<< orphan*/  dlen; TYPE_1__* ops; } ;
struct nft_regs {scalar_t__* data; } ;
struct nft_pktinfo {struct sk_buff* skb; } ;
struct nft_jhash {size_t sreg; int len; int seed; int modulus; size_t dreg; int offset; int autogen_seed; struct nft_set* map; } ;
struct nft_expr_ops {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int /*<<< orphan*/  table; int /*<<< orphan*/  net; } ;
struct TYPE_2__ {int (* lookup ) (int /*<<< orphan*/ ,struct nft_set const*,scalar_t__*,struct nft_set_ext const**) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  EOPNOTSUPP ; 
 int EOVERFLOW ; 
 int ERANGE ; 
 struct nft_expr_ops const* ERR_PTR (int /*<<< orphan*/ ) ; 
 size_t NFTA_HASH_DREG ; 
 size_t NFTA_HASH_LEN ; 
 size_t NFTA_HASH_MODULUS ; 
 size_t NFTA_HASH_OFFSET ; 
 size_t NFTA_HASH_SEED ; 
 size_t NFTA_HASH_SET_ID ; 
 size_t NFTA_HASH_SET_NAME ; 
 size_t NFTA_HASH_SREG ; 
 size_t NFTA_HASH_TYPE ; 
 int /*<<< orphan*/  NFT_DATA_VALUE ; 
#define  NFT_HASH_JENKINS 129 
#define  NFT_HASH_SYM 128 
 int PTR_ERR_OR_ZERO (struct nft_set*) ; 
 int /*<<< orphan*/  U8_MAX ; 
 int /*<<< orphan*/  __skb_get_hash_symmetric (struct sk_buff*) ; 
 int /*<<< orphan*/  get_random_bytes (int*,int) ; 
 int /*<<< orphan*/  htonl (int) ; 
 int /*<<< orphan*/  jhash (void const*,int,int) ; 
 int /*<<< orphan*/  nft_data_copy (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nft_genmask_next (int /*<<< orphan*/ ) ; 
 struct nft_expr_ops const nft_jhash_map_ops ; 
 struct nft_expr_ops const nft_jhash_ops ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 void* nft_parse_register (struct nlattr const* const) ; 
 int nft_parse_u32_check (struct nlattr const* const,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  nft_set_ext_data (struct nft_set_ext const*) ; 
 void* nft_set_lookup_global (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nlattr const* const,struct nlattr const* const,int /*<<< orphan*/ ) ; 
 struct nft_expr_ops const nft_symhash_map_ops ; 
 struct nft_expr_ops const nft_symhash_ops ; 
 scalar_t__ nft_validate_register_load (size_t,scalar_t__) ; 
 int nft_validate_register_store (struct nft_ctx const*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_string (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 void* ntohl (int /*<<< orphan*/ ) ; 
 scalar_t__ reciprocal_scale (int /*<<< orphan*/ ,int) ; 
 int stub1 (int /*<<< orphan*/ ,struct nft_set const*,scalar_t__*,struct nft_set_ext const**) ; 
 int stub2 (int /*<<< orphan*/ ,struct nft_set const*,scalar_t__*,struct nft_set_ext const**) ; 

__attribute__((used)) static void nft_jhash_eval(const struct nft_expr *expr,
			   struct nft_regs *regs,
			   const struct nft_pktinfo *pkt)
{
	struct nft_jhash *priv = nft_expr_priv(expr);
	const void *data = &regs->data[priv->sreg];
	u32 h;

	h = reciprocal_scale(jhash(data, priv->len, priv->seed),
			     priv->modulus);

	regs->data[priv->dreg] = h + priv->offset;
}

__attribute__((used)) static void nft_jhash_map_eval(const struct nft_expr *expr,
			       struct nft_regs *regs,
			       const struct nft_pktinfo *pkt)
{
	struct nft_jhash *priv = nft_expr_priv(expr);
	const void *data = &regs->data[priv->sreg];
	const struct nft_set *map = priv->map;
	const struct nft_set_ext *ext;
	u32 result;
	bool found;

	result = reciprocal_scale(jhash(data, priv->len, priv->seed),
					priv->modulus) + priv->offset;

	found = map->ops->lookup(nft_net(pkt), map, &result, &ext);
	if (!found)
		return;

	nft_data_copy(&regs->data[priv->dreg],
		      nft_set_ext_data(ext), map->dlen);
}

__attribute__((used)) static void nft_symhash_eval(const struct nft_expr *expr,
			     struct nft_regs *regs,
			     const struct nft_pktinfo *pkt)
{
	struct nft_symhash *priv = nft_expr_priv(expr);
	struct sk_buff *skb = pkt->skb;
	u32 h;

	h = reciprocal_scale(__skb_get_hash_symmetric(skb), priv->modulus);

	regs->data[priv->dreg] = h + priv->offset;
}

__attribute__((used)) static void nft_symhash_map_eval(const struct nft_expr *expr,
				 struct nft_regs *regs,
				 const struct nft_pktinfo *pkt)
{
	struct nft_symhash *priv = nft_expr_priv(expr);
	struct sk_buff *skb = pkt->skb;
	const struct nft_set *map = priv->map;
	const struct nft_set_ext *ext;
	u32 result;
	bool found;

	result = reciprocal_scale(__skb_get_hash_symmetric(skb),
				  priv->modulus) + priv->offset;

	found = map->ops->lookup(nft_net(pkt), map, &result, &ext);
	if (!found)
		return;

	nft_data_copy(&regs->data[priv->dreg],
		      nft_set_ext_data(ext), map->dlen);
}

__attribute__((used)) static int nft_jhash_init(const struct nft_ctx *ctx,
			  const struct nft_expr *expr,
			  const struct nlattr * const tb[])
{
	struct nft_jhash *priv = nft_expr_priv(expr);
	u32 len;
	int err;

	if (!tb[NFTA_HASH_SREG] ||
	    !tb[NFTA_HASH_DREG] ||
	    !tb[NFTA_HASH_LEN]  ||
	    !tb[NFTA_HASH_MODULUS])
		return -EINVAL;

	if (tb[NFTA_HASH_OFFSET])
		priv->offset = ntohl(nla_get_be32(tb[NFTA_HASH_OFFSET]));

	priv->sreg = nft_parse_register(tb[NFTA_HASH_SREG]);
	priv->dreg = nft_parse_register(tb[NFTA_HASH_DREG]);

	err = nft_parse_u32_check(tb[NFTA_HASH_LEN], U8_MAX, &len);
	if (err < 0)
		return err;
	if (len == 0)
		return -ERANGE;

	priv->len = len;

	priv->modulus = ntohl(nla_get_be32(tb[NFTA_HASH_MODULUS]));
	if (priv->modulus < 1)
		return -ERANGE;

	if (priv->offset + priv->modulus - 1 < priv->offset)
		return -EOVERFLOW;

	if (tb[NFTA_HASH_SEED]) {
		priv->seed = ntohl(nla_get_be32(tb[NFTA_HASH_SEED]));
	} else {
		priv->autogen_seed = true;
		get_random_bytes(&priv->seed, sizeof(priv->seed));
	}

	return nft_validate_register_load(priv->sreg, len) &&
	       nft_validate_register_store(ctx, priv->dreg, NULL,
					   NFT_DATA_VALUE, sizeof(u32));
}

__attribute__((used)) static int nft_jhash_map_init(const struct nft_ctx *ctx,
			      const struct nft_expr *expr,
			      const struct nlattr * const tb[])
{
	struct nft_jhash *priv = nft_expr_priv(expr);
	u8 genmask = nft_genmask_next(ctx->net);

	nft_jhash_init(ctx, expr, tb);
	priv->map = nft_set_lookup_global(ctx->net, ctx->table,
					  tb[NFTA_HASH_SET_NAME],
					  tb[NFTA_HASH_SET_ID], genmask);
	return PTR_ERR_OR_ZERO(priv->map);
}

__attribute__((used)) static int nft_symhash_init(const struct nft_ctx *ctx,
			    const struct nft_expr *expr,
			    const struct nlattr * const tb[])
{
	struct nft_symhash *priv = nft_expr_priv(expr);

	if (!tb[NFTA_HASH_DREG]    ||
	    !tb[NFTA_HASH_MODULUS])
		return -EINVAL;

	if (tb[NFTA_HASH_OFFSET])
		priv->offset = ntohl(nla_get_be32(tb[NFTA_HASH_OFFSET]));

	priv->dreg = nft_parse_register(tb[NFTA_HASH_DREG]);

	priv->modulus = ntohl(nla_get_be32(tb[NFTA_HASH_MODULUS]));
	if (priv->modulus <= 1)
		return -ERANGE;

	if (priv->offset + priv->modulus - 1 < priv->offset)
		return -EOVERFLOW;

	return nft_validate_register_store(ctx, priv->dreg, NULL,
					   NFT_DATA_VALUE, sizeof(u32));
}

__attribute__((used)) static int nft_symhash_map_init(const struct nft_ctx *ctx,
				const struct nft_expr *expr,
				const struct nlattr * const tb[])
{
	struct nft_jhash *priv = nft_expr_priv(expr);
	u8 genmask = nft_genmask_next(ctx->net);

	nft_symhash_init(ctx, expr, tb);
	priv->map = nft_set_lookup_global(ctx->net, ctx->table,
					  tb[NFTA_HASH_SET_NAME],
					  tb[NFTA_HASH_SET_ID], genmask);
	return PTR_ERR_OR_ZERO(priv->map);
}

__attribute__((used)) static int nft_jhash_dump(struct sk_buff *skb,
			  const struct nft_expr *expr)
{
	const struct nft_jhash *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_HASH_SREG, priv->sreg))
		goto nla_put_failure;
	if (nft_dump_register(skb, NFTA_HASH_DREG, priv->dreg))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_HASH_LEN, htonl(priv->len)))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_HASH_MODULUS, htonl(priv->modulus)))
		goto nla_put_failure;
	if (!priv->autogen_seed &&
	    nla_put_be32(skb, NFTA_HASH_SEED, htonl(priv->seed)))
		goto nla_put_failure;
	if (priv->offset != 0)
		if (nla_put_be32(skb, NFTA_HASH_OFFSET, htonl(priv->offset)))
			goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_HASH_TYPE, htonl(NFT_HASH_JENKINS)))
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int nft_jhash_map_dump(struct sk_buff *skb,
			       const struct nft_expr *expr)
{
	const struct nft_jhash *priv = nft_expr_priv(expr);

	if (nft_jhash_dump(skb, expr) ||
	    nla_put_string(skb, NFTA_HASH_SET_NAME, priv->map->name))
		return -1;

	return 0;
}

__attribute__((used)) static int nft_symhash_dump(struct sk_buff *skb,
			    const struct nft_expr *expr)
{
	const struct nft_symhash *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_HASH_DREG, priv->dreg))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_HASH_MODULUS, htonl(priv->modulus)))
		goto nla_put_failure;
	if (priv->offset != 0)
		if (nla_put_be32(skb, NFTA_HASH_OFFSET, htonl(priv->offset)))
			goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_HASH_TYPE, htonl(NFT_HASH_SYM)))
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int nft_symhash_map_dump(struct sk_buff *skb,
				const struct nft_expr *expr)
{
	const struct nft_symhash *priv = nft_expr_priv(expr);

	if (nft_symhash_dump(skb, expr) ||
	    nla_put_string(skb, NFTA_HASH_SET_NAME, priv->map->name))
		return -1;

	return 0;
}

__attribute__((used)) static const struct nft_expr_ops *
nft_hash_select_ops(const struct nft_ctx *ctx,
		    const struct nlattr * const tb[])
{
	u32 type;

	if (!tb[NFTA_HASH_TYPE])
		return &nft_jhash_ops;

	type = ntohl(nla_get_be32(tb[NFTA_HASH_TYPE]));
	switch (type) {
	case NFT_HASH_SYM:
		if (tb[NFTA_HASH_SET_NAME])
			return &nft_symhash_map_ops;
		return &nft_symhash_ops;
	case NFT_HASH_JENKINS:
		if (tb[NFTA_HASH_SET_NAME])
			return &nft_jhash_map_ops;
		return &nft_jhash_ops;
	default:
		break;
	}
	return ERR_PTR(-EOPNOTSUPP);
}


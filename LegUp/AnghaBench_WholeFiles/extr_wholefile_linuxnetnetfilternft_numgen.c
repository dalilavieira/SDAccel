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
typedef  scalar_t__ u32 ;
struct sk_buff {int dummy; } ;
struct rnd_state {int dummy; } ;
struct nlattr {int dummy; } ;
struct nft_regs {scalar_t__* data; } ;
struct nft_pktinfo {int dummy; } ;
struct nft_ng_random {int modulus; scalar_t__ offset; size_t dreg; } ;
struct nft_ng_inc {scalar_t__ modulus; scalar_t__ offset; size_t dreg; int /*<<< orphan*/  counter; } ;
struct nft_expr_ops {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;
typedef  enum nft_registers { ____Placeholder_nft_registers } nft_registers ;
typedef  enum nft_ng_types { ____Placeholder_nft_ng_types } nft_ng_types ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int EOVERFLOW ; 
 int ERANGE ; 
 struct nft_expr_ops const* ERR_PTR (int /*<<< orphan*/ ) ; 
 size_t NFTA_NG_DREG ; 
 size_t NFTA_NG_MODULUS ; 
 size_t NFTA_NG_OFFSET ; 
 size_t NFTA_NG_TYPE ; 
 int /*<<< orphan*/  NFT_DATA_VALUE ; 
#define  NFT_NG_INCREMENTAL 129 
#define  NFT_NG_RANDOM 128 
 scalar_t__ atomic_cmpxchg (int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  htonl (scalar_t__) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,int) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 struct nft_expr_ops const nft_ng_inc_ops ; 
 struct nft_expr_ops const nft_ng_random_ops ; 
 int /*<<< orphan*/  nft_numgen_prandom_state ; 
 void* nft_parse_register (struct nlattr const* const) ; 
 int nft_validate_register_store (struct nft_ctx const*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 void* ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prandom_init_once (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  prandom_u32_state (struct rnd_state*) ; 
 scalar_t__ reciprocal_scale (int /*<<< orphan*/ ,int) ; 
 struct rnd_state* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static u32 nft_ng_inc_gen(struct nft_ng_inc *priv)
{
	u32 nval, oval;

	do {
		oval = atomic_read(&priv->counter);
		nval = (oval + 1 < priv->modulus) ? oval + 1 : 0;
	} while (atomic_cmpxchg(&priv->counter, oval, nval) != oval);

	return nval + priv->offset;
}

__attribute__((used)) static void nft_ng_inc_eval(const struct nft_expr *expr,
			    struct nft_regs *regs,
			    const struct nft_pktinfo *pkt)
{
	struct nft_ng_inc *priv = nft_expr_priv(expr);

	regs->data[priv->dreg] = nft_ng_inc_gen(priv);
}

__attribute__((used)) static int nft_ng_inc_init(const struct nft_ctx *ctx,
			   const struct nft_expr *expr,
			   const struct nlattr * const tb[])
{
	struct nft_ng_inc *priv = nft_expr_priv(expr);

	if (tb[NFTA_NG_OFFSET])
		priv->offset = ntohl(nla_get_be32(tb[NFTA_NG_OFFSET]));

	priv->modulus = ntohl(nla_get_be32(tb[NFTA_NG_MODULUS]));
	if (priv->modulus == 0)
		return -ERANGE;

	if (priv->offset + priv->modulus - 1 < priv->offset)
		return -EOVERFLOW;

	priv->dreg = nft_parse_register(tb[NFTA_NG_DREG]);
	atomic_set(&priv->counter, priv->modulus - 1);

	return nft_validate_register_store(ctx, priv->dreg, NULL,
					   NFT_DATA_VALUE, sizeof(u32));
}

__attribute__((used)) static int nft_ng_dump(struct sk_buff *skb, enum nft_registers dreg,
		       u32 modulus, enum nft_ng_types type, u32 offset)
{
	if (nft_dump_register(skb, NFTA_NG_DREG, dreg))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_NG_MODULUS, htonl(modulus)))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_NG_TYPE, htonl(type)))
		goto nla_put_failure;
	if (nla_put_be32(skb, NFTA_NG_OFFSET, htonl(offset)))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int nft_ng_inc_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_ng_inc *priv = nft_expr_priv(expr);

	return nft_ng_dump(skb, priv->dreg, priv->modulus, NFT_NG_INCREMENTAL,
			   priv->offset);
}

__attribute__((used)) static u32 nft_ng_random_gen(struct nft_ng_random *priv)
{
	struct rnd_state *state = this_cpu_ptr(&nft_numgen_prandom_state);

	return reciprocal_scale(prandom_u32_state(state), priv->modulus) +
	       priv->offset;
}

__attribute__((used)) static void nft_ng_random_eval(const struct nft_expr *expr,
			       struct nft_regs *regs,
			       const struct nft_pktinfo *pkt)
{
	struct nft_ng_random *priv = nft_expr_priv(expr);

	regs->data[priv->dreg] = nft_ng_random_gen(priv);
}

__attribute__((used)) static int nft_ng_random_init(const struct nft_ctx *ctx,
			      const struct nft_expr *expr,
			      const struct nlattr * const tb[])
{
	struct nft_ng_random *priv = nft_expr_priv(expr);

	if (tb[NFTA_NG_OFFSET])
		priv->offset = ntohl(nla_get_be32(tb[NFTA_NG_OFFSET]));

	priv->modulus = ntohl(nla_get_be32(tb[NFTA_NG_MODULUS]));
	if (priv->modulus == 0)
		return -ERANGE;

	if (priv->offset + priv->modulus - 1 < priv->offset)
		return -EOVERFLOW;

	prandom_init_once(&nft_numgen_prandom_state);

	priv->dreg = nft_parse_register(tb[NFTA_NG_DREG]);

	return nft_validate_register_store(ctx, priv->dreg, NULL,
					   NFT_DATA_VALUE, sizeof(u32));
}

__attribute__((used)) static int nft_ng_random_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_ng_random *priv = nft_expr_priv(expr);

	return nft_ng_dump(skb, priv->dreg, priv->modulus, NFT_NG_RANDOM,
			   priv->offset);
}

__attribute__((used)) static const struct nft_expr_ops *
nft_ng_select_ops(const struct nft_ctx *ctx, const struct nlattr * const tb[])
{
	u32 type;

	if (!tb[NFTA_NG_DREG]	 ||
	    !tb[NFTA_NG_MODULUS] ||
	    !tb[NFTA_NG_TYPE])
		return ERR_PTR(-EINVAL);

	type = ntohl(nla_get_be32(tb[NFTA_NG_TYPE]));

	switch (type) {
	case NFT_NG_INCREMENTAL:
		return &nft_ng_inc_ops;
	case NFT_NG_RANDOM:
		return &nft_ng_random_ops;
	}

	return ERR_PTR(-EINVAL);
}


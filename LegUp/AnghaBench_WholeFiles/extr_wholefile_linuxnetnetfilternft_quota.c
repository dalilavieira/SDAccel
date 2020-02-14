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
typedef  scalar_t__ u64 ;
typedef  unsigned long u32 ;
struct sk_buff {int /*<<< orphan*/  len; } ;
struct nlattr {int dummy; } ;
struct TYPE_2__ {void* code; } ;
struct nft_regs {TYPE_1__ verdict; } ;
struct nft_quota {scalar_t__ quota; int flags; int /*<<< orphan*/  consumed; } ;
struct nft_pktinfo {struct sk_buff* skb; } ;
struct nft_object {int /*<<< orphan*/  table; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int EOVERFLOW ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 size_t NFTA_QUOTA_BYTES ; 
 size_t NFTA_QUOTA_CONSUMED ; 
 size_t NFTA_QUOTA_FLAGS ; 
 int /*<<< orphan*/  NFTA_QUOTA_PAD ; 
 void* NFT_BREAK ; 
 int /*<<< orphan*/  NFT_MSG_NEWOBJ ; 
 int /*<<< orphan*/  NFT_QUOTA_DEPLETED_BIT ; 
 unsigned long NFT_QUOTA_F_DEPLETED ; 
 int NFT_QUOTA_F_INV ; 
 scalar_t__ S64_MAX ; 
 scalar_t__ atomic64_add_return (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ atomic64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic64_set (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  atomic64_sub (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  cpu_to_be64 (scalar_t__) ; 
 int /*<<< orphan*/  htonl (unsigned long) ; 
 struct nft_quota* nft_expr_priv (struct nft_expr const*) ; 
 int /*<<< orphan*/  nft_net (struct nft_pktinfo const*) ; 
 struct nft_quota* nft_obj_data (struct nft_object*) ; 
 int /*<<< orphan*/  nft_obj_notify (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nft_object*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nft_pf (struct nft_pktinfo const*) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 int /*<<< orphan*/  nla_get_be64 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_be64 (struct sk_buff*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static inline bool nft_overquota(struct nft_quota *priv,
				 const struct sk_buff *skb)
{
	return atomic64_add_return(skb->len, &priv->consumed) >= priv->quota;
}

__attribute__((used)) static inline bool nft_quota_invert(struct nft_quota *priv)
{
	return priv->flags & NFT_QUOTA_F_INV;
}

__attribute__((used)) static inline void nft_quota_do_eval(struct nft_quota *priv,
				     struct nft_regs *regs,
				     const struct nft_pktinfo *pkt)
{
	if (nft_overquota(priv, pkt->skb) ^ nft_quota_invert(priv))
		regs->verdict.code = NFT_BREAK;
}

__attribute__((used)) static void nft_quota_obj_eval(struct nft_object *obj,
			       struct nft_regs *regs,
			       const struct nft_pktinfo *pkt)
{
	struct nft_quota *priv = nft_obj_data(obj);
	bool overquota;

	overquota = nft_overquota(priv, pkt->skb);
	if (overquota ^ nft_quota_invert(priv))
		regs->verdict.code = NFT_BREAK;

	if (overquota &&
	    !test_and_set_bit(NFT_QUOTA_DEPLETED_BIT, &priv->flags))
		nft_obj_notify(nft_net(pkt), obj->table, obj, 0, 0,
			       NFT_MSG_NEWOBJ, nft_pf(pkt), 0, GFP_ATOMIC);
}

__attribute__((used)) static int nft_quota_do_init(const struct nlattr * const tb[],
			     struct nft_quota *priv)
{
	unsigned long flags = 0;
	u64 quota, consumed = 0;

	if (!tb[NFTA_QUOTA_BYTES])
		return -EINVAL;

	quota = be64_to_cpu(nla_get_be64(tb[NFTA_QUOTA_BYTES]));
	if (quota > S64_MAX)
		return -EOVERFLOW;

	if (tb[NFTA_QUOTA_CONSUMED]) {
		consumed = be64_to_cpu(nla_get_be64(tb[NFTA_QUOTA_CONSUMED]));
		if (consumed > quota)
			return -EINVAL;
	}

	if (tb[NFTA_QUOTA_FLAGS]) {
		flags = ntohl(nla_get_be32(tb[NFTA_QUOTA_FLAGS]));
		if (flags & ~NFT_QUOTA_F_INV)
			return -EINVAL;
		if (flags & NFT_QUOTA_F_DEPLETED)
			return -EOPNOTSUPP;
	}

	priv->quota = quota;
	priv->flags = flags;
	atomic64_set(&priv->consumed, consumed);

	return 0;
}

__attribute__((used)) static int nft_quota_obj_init(const struct nft_ctx *ctx,
			      const struct nlattr * const tb[],
			      struct nft_object *obj)
{
	struct nft_quota *priv = nft_obj_data(obj);

	return nft_quota_do_init(tb, priv);
}

__attribute__((used)) static int nft_quota_do_dump(struct sk_buff *skb, struct nft_quota *priv,
			     bool reset)
{
	u64 consumed, consumed_cap;
	u32 flags = priv->flags;

	/* Since we inconditionally increment consumed quota for each packet
	 * that we see, don't go over the quota boundary in what we send to
	 * userspace.
	 */
	consumed = atomic64_read(&priv->consumed);
	if (consumed >= priv->quota) {
		consumed_cap = priv->quota;
		flags |= NFT_QUOTA_F_DEPLETED;
	} else {
		consumed_cap = consumed;
	}

	if (nla_put_be64(skb, NFTA_QUOTA_BYTES, cpu_to_be64(priv->quota),
			 NFTA_QUOTA_PAD) ||
	    nla_put_be64(skb, NFTA_QUOTA_CONSUMED, cpu_to_be64(consumed_cap),
			 NFTA_QUOTA_PAD) ||
	    nla_put_be32(skb, NFTA_QUOTA_FLAGS, htonl(flags)))
		goto nla_put_failure;

	if (reset) {
		atomic64_sub(consumed, &priv->consumed);
		clear_bit(NFT_QUOTA_DEPLETED_BIT, &priv->flags);
	}
	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int nft_quota_obj_dump(struct sk_buff *skb, struct nft_object *obj,
			      bool reset)
{
	struct nft_quota *priv = nft_obj_data(obj);

	return nft_quota_do_dump(skb, priv, reset);
}

__attribute__((used)) static void nft_quota_eval(const struct nft_expr *expr,
			   struct nft_regs *regs,
			   const struct nft_pktinfo *pkt)
{
	struct nft_quota *priv = nft_expr_priv(expr);

	nft_quota_do_eval(priv, regs, pkt);
}

__attribute__((used)) static int nft_quota_init(const struct nft_ctx *ctx,
			  const struct nft_expr *expr,
			  const struct nlattr * const tb[])
{
	struct nft_quota *priv = nft_expr_priv(expr);

	return nft_quota_do_init(tb, priv);
}

__attribute__((used)) static int nft_quota_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_quota *priv = nft_expr_priv(expr);

	return nft_quota_do_dump(skb, priv, false);
}


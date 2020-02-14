#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  int u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct TYPE_4__ {void* code; } ;
struct nft_regs {TYPE_2__ verdict; } ;
struct nft_pktinfo {TYPE_1__* skb; } ;
struct nft_object_ops {int dummy; } ;
struct nft_object {int dummy; } ;
struct nft_limit {scalar_t__ tokens; scalar_t__ last; scalar_t__ tokens_max; int invert; int rate; scalar_t__ nsecs; int burst; int /*<<< orphan*/  lock; } ;
struct nft_limit_pkts {scalar_t__ cost; struct nft_limit limit; } ;
typedef  struct nft_object_ops nft_expr_ops ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;
typedef  scalar_t__ s64 ;
typedef  enum nft_limit_type { ____Placeholder_nft_limit_type } nft_limit_type ;
struct TYPE_3__ {int len; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  EOPNOTSUPP ; 
 int EOVERFLOW ; 
 struct nft_object_ops const* ERR_PTR (int /*<<< orphan*/ ) ; 
 size_t NFTA_LIMIT_BURST ; 
 size_t NFTA_LIMIT_FLAGS ; 
 int /*<<< orphan*/  NFTA_LIMIT_PAD ; 
 size_t NFTA_LIMIT_RATE ; 
 size_t NFTA_LIMIT_TYPE ; 
 size_t NFTA_LIMIT_UNIT ; 
 void* NFT_BREAK ; 
 int NFT_LIMIT_F_INV ; 
#define  NFT_LIMIT_PKTS 129 
 int NFT_LIMIT_PKT_BURST_DEFAULT ; 
#define  NFT_LIMIT_PKT_BYTES 128 
 scalar_t__ NSEC_PER_SEC ; 
 void* be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be64 (scalar_t__) ; 
 void* div64_u64 (int,scalar_t__) ; 
 scalar_t__ div_u64 (int,scalar_t__) ; 
 int /*<<< orphan*/  htonl (int) ; 
 void* ktime_get_ns () ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 struct nft_object_ops const nft_limit_bytes_ops ; 
 struct nft_object_ops const nft_limit_obj_bytes_ops ; 
 struct nft_object_ops const nft_limit_obj_pkts_ops ; 
 struct nft_object_ops const nft_limit_pkts_ops ; 
 void* nft_obj_data (struct nft_object*) ; 
 int /*<<< orphan*/  nla_get_be32 (struct nlattr const* const) ; 
 int /*<<< orphan*/  nla_get_be64 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_be64 (struct sk_buff*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool nft_limit_eval(struct nft_limit *limit, u64 cost)
{
	u64 now, tokens;
	s64 delta;

	spin_lock_bh(&limit->lock);
	now = ktime_get_ns();
	tokens = limit->tokens + now - limit->last;
	if (tokens > limit->tokens_max)
		tokens = limit->tokens_max;

	limit->last = now;
	delta = tokens - cost;
	if (delta >= 0) {
		limit->tokens = delta;
		spin_unlock_bh(&limit->lock);
		return limit->invert;
	}
	limit->tokens = tokens;
	spin_unlock_bh(&limit->lock);
	return !limit->invert;
}

__attribute__((used)) static int nft_limit_init(struct nft_limit *limit,
			  const struct nlattr * const tb[], bool pkts)
{
	u64 unit, tokens;

	if (tb[NFTA_LIMIT_RATE] == NULL ||
	    tb[NFTA_LIMIT_UNIT] == NULL)
		return -EINVAL;

	limit->rate = be64_to_cpu(nla_get_be64(tb[NFTA_LIMIT_RATE]));
	unit = be64_to_cpu(nla_get_be64(tb[NFTA_LIMIT_UNIT]));
	limit->nsecs = unit * NSEC_PER_SEC;
	if (limit->rate == 0 || limit->nsecs < unit)
		return -EOVERFLOW;

	if (tb[NFTA_LIMIT_BURST])
		limit->burst = ntohl(nla_get_be32(tb[NFTA_LIMIT_BURST]));

	if (pkts && limit->burst == 0)
		limit->burst = NFT_LIMIT_PKT_BURST_DEFAULT;

	if (limit->rate + limit->burst < limit->rate)
		return -EOVERFLOW;

	if (pkts) {
		tokens = div_u64(limit->nsecs, limit->rate) * limit->burst;
	} else {
		/* The token bucket size limits the number of tokens can be
		 * accumulated. tokens_max specifies the bucket size.
		 * tokens_max = unit * (rate + burst) / rate.
		 */
		tokens = div_u64(limit->nsecs * (limit->rate + limit->burst),
				 limit->rate);
	}

	limit->tokens = tokens;
	limit->tokens_max = limit->tokens;

	if (tb[NFTA_LIMIT_FLAGS]) {
		u32 flags = ntohl(nla_get_be32(tb[NFTA_LIMIT_FLAGS]));

		if (flags & NFT_LIMIT_F_INV)
			limit->invert = true;
	}
	limit->last = ktime_get_ns();
	spin_lock_init(&limit->lock);

	return 0;
}

__attribute__((used)) static int nft_limit_dump(struct sk_buff *skb, const struct nft_limit *limit,
			  enum nft_limit_type type)
{
	u32 flags = limit->invert ? NFT_LIMIT_F_INV : 0;
	u64 secs = div_u64(limit->nsecs, NSEC_PER_SEC);

	if (nla_put_be64(skb, NFTA_LIMIT_RATE, cpu_to_be64(limit->rate),
			 NFTA_LIMIT_PAD) ||
	    nla_put_be64(skb, NFTA_LIMIT_UNIT, cpu_to_be64(secs),
			 NFTA_LIMIT_PAD) ||
	    nla_put_be32(skb, NFTA_LIMIT_BURST, htonl(limit->burst)) ||
	    nla_put_be32(skb, NFTA_LIMIT_TYPE, htonl(type)) ||
	    nla_put_be32(skb, NFTA_LIMIT_FLAGS, htonl(flags)))
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static void nft_limit_pkts_eval(const struct nft_expr *expr,
				struct nft_regs *regs,
				const struct nft_pktinfo *pkt)
{
	struct nft_limit_pkts *priv = nft_expr_priv(expr);

	if (nft_limit_eval(&priv->limit, priv->cost))
		regs->verdict.code = NFT_BREAK;
}

__attribute__((used)) static int nft_limit_pkts_init(const struct nft_ctx *ctx,
			       const struct nft_expr *expr,
			       const struct nlattr * const tb[])
{
	struct nft_limit_pkts *priv = nft_expr_priv(expr);
	int err;

	err = nft_limit_init(&priv->limit, tb, true);
	if (err < 0)
		return err;

	priv->cost = div64_u64(priv->limit.nsecs, priv->limit.rate);
	return 0;
}

__attribute__((used)) static int nft_limit_pkts_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_limit_pkts *priv = nft_expr_priv(expr);

	return nft_limit_dump(skb, &priv->limit, NFT_LIMIT_PKTS);
}

__attribute__((used)) static void nft_limit_bytes_eval(const struct nft_expr *expr,
				 struct nft_regs *regs,
				 const struct nft_pktinfo *pkt)
{
	struct nft_limit *priv = nft_expr_priv(expr);
	u64 cost = div64_u64(priv->nsecs * pkt->skb->len, priv->rate);

	if (nft_limit_eval(priv, cost))
		regs->verdict.code = NFT_BREAK;
}

__attribute__((used)) static int nft_limit_bytes_init(const struct nft_ctx *ctx,
				const struct nft_expr *expr,
				const struct nlattr * const tb[])
{
	struct nft_limit *priv = nft_expr_priv(expr);

	return nft_limit_init(priv, tb, false);
}

__attribute__((used)) static int nft_limit_bytes_dump(struct sk_buff *skb,
				const struct nft_expr *expr)
{
	const struct nft_limit *priv = nft_expr_priv(expr);

	return nft_limit_dump(skb, priv, NFT_LIMIT_PKT_BYTES);
}

__attribute__((used)) static const struct nft_expr_ops *
nft_limit_select_ops(const struct nft_ctx *ctx,
		     const struct nlattr * const tb[])
{
	if (tb[NFTA_LIMIT_TYPE] == NULL)
		return &nft_limit_pkts_ops;

	switch (ntohl(nla_get_be32(tb[NFTA_LIMIT_TYPE]))) {
	case NFT_LIMIT_PKTS:
		return &nft_limit_pkts_ops;
	case NFT_LIMIT_PKT_BYTES:
		return &nft_limit_bytes_ops;
	}
	return ERR_PTR(-EOPNOTSUPP);
}

__attribute__((used)) static void nft_limit_obj_pkts_eval(struct nft_object *obj,
				    struct nft_regs *regs,
				    const struct nft_pktinfo *pkt)
{
	struct nft_limit_pkts *priv = nft_obj_data(obj);

	if (nft_limit_eval(&priv->limit, priv->cost))
		regs->verdict.code = NFT_BREAK;
}

__attribute__((used)) static int nft_limit_obj_pkts_init(const struct nft_ctx *ctx,
				   const struct nlattr * const tb[],
				   struct nft_object *obj)
{
	struct nft_limit_pkts *priv = nft_obj_data(obj);
	int err;

	err = nft_limit_init(&priv->limit, tb, true);
	if (err < 0)
		return err;

	priv->cost = div64_u64(priv->limit.nsecs, priv->limit.rate);
	return 0;
}

__attribute__((used)) static int nft_limit_obj_pkts_dump(struct sk_buff *skb,
				   struct nft_object *obj,
				   bool reset)
{
	const struct nft_limit_pkts *priv = nft_obj_data(obj);

	return nft_limit_dump(skb, &priv->limit, NFT_LIMIT_PKTS);
}

__attribute__((used)) static void nft_limit_obj_bytes_eval(struct nft_object *obj,
				     struct nft_regs *regs,
				     const struct nft_pktinfo *pkt)
{
	struct nft_limit *priv = nft_obj_data(obj);
	u64 cost = div64_u64(priv->nsecs * pkt->skb->len, priv->rate);

	if (nft_limit_eval(priv, cost))
		regs->verdict.code = NFT_BREAK;
}

__attribute__((used)) static int nft_limit_obj_bytes_init(const struct nft_ctx *ctx,
				    const struct nlattr * const tb[],
				    struct nft_object *obj)
{
	struct nft_limit *priv = nft_obj_data(obj);

	return nft_limit_init(priv, tb, false);
}

__attribute__((used)) static int nft_limit_obj_bytes_dump(struct sk_buff *skb,
				    struct nft_object *obj,
				    bool reset)
{
	const struct nft_limit *priv = nft_obj_data(obj);

	return nft_limit_dump(skb, priv, NFT_LIMIT_PKT_BYTES);
}

__attribute__((used)) static const struct nft_object_ops *
nft_limit_obj_select_ops(const struct nft_ctx *ctx,
			 const struct nlattr * const tb[])
{
	if (!tb[NFTA_LIMIT_TYPE])
		return &nft_limit_obj_pkts_ops;

	switch (ntohl(nla_get_be32(tb[NFTA_LIMIT_TYPE]))) {
	case NFT_LIMIT_PKTS:
		return &nft_limit_obj_pkts_ops;
	case NFT_LIMIT_PKT_BYTES:
		return &nft_limit_obj_bytes_ops;
	}
	return ERR_PTR(-EOPNOTSUPP);
}


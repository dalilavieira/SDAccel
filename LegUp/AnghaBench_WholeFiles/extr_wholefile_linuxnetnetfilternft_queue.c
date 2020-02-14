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
typedef  scalar_t__ u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct TYPE_2__ {scalar_t__ code; } ;
struct nft_regs {scalar_t__* data; TYPE_1__ verdict; } ;
struct nft_queue {scalar_t__ queuenum; int queues_total; int flags; size_t sreg_qnum; } ;
struct nft_pktinfo {int /*<<< orphan*/  skb; } ;
struct nft_expr_ops {int dummy; } ;
struct nft_expr {int dummy; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int ERANGE ; 
 struct nft_expr_ops const* ERR_PTR (int) ; 
 size_t NFTA_QUEUE_FLAGS ; 
 size_t NFTA_QUEUE_NUM ; 
 size_t NFTA_QUEUE_SREG_QNUM ; 
 size_t NFTA_QUEUE_TOTAL ; 
 int NFT_QUEUE_FLAG_BYPASS ; 
 int NFT_QUEUE_FLAG_CPU_FANOUT ; 
 int NFT_QUEUE_FLAG_MASK ; 
 scalar_t__ NF_QUEUE_NR (scalar_t__) ; 
 scalar_t__ NF_VERDICT_FLAG_QUEUE_BYPASS ; 
 scalar_t__ U16_MAX ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  init_hashrandom (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jhash_initval ; 
 scalar_t__ nfqueue_hash (int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ nft_dump_register (struct sk_buff*,size_t,size_t) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 size_t nft_parse_register (struct nlattr const* const) ; 
 int /*<<< orphan*/  nft_pf (struct nft_pktinfo const*) ; 
 struct nft_expr_ops const nft_queue_ops ; 
 struct nft_expr_ops const nft_queue_sreg_ops ; 
 int nft_validate_register_load (size_t,int) ; 
 int /*<<< orphan*/  nla_get_be16 (struct nlattr const* const) ; 
 scalar_t__ nla_put_be16 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 void* ntohs (int /*<<< orphan*/ ) ; 
 int raw_smp_processor_id () ; 

__attribute__((used)) static void nft_queue_eval(const struct nft_expr *expr,
			   struct nft_regs *regs,
			   const struct nft_pktinfo *pkt)
{
	struct nft_queue *priv = nft_expr_priv(expr);
	u32 queue = priv->queuenum;
	u32 ret;

	if (priv->queues_total > 1) {
		if (priv->flags & NFT_QUEUE_FLAG_CPU_FANOUT) {
			int cpu = raw_smp_processor_id();

			queue = priv->queuenum + cpu % priv->queues_total;
		} else {
			queue = nfqueue_hash(pkt->skb, queue,
					     priv->queues_total, nft_pf(pkt),
					     jhash_initval);
		}
	}

	ret = NF_QUEUE_NR(queue);
	if (priv->flags & NFT_QUEUE_FLAG_BYPASS)
		ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;

	regs->verdict.code = ret;
}

__attribute__((used)) static void nft_queue_sreg_eval(const struct nft_expr *expr,
				struct nft_regs *regs,
				const struct nft_pktinfo *pkt)
{
	struct nft_queue *priv = nft_expr_priv(expr);
	u32 queue, ret;

	queue = regs->data[priv->sreg_qnum];

	ret = NF_QUEUE_NR(queue);
	if (priv->flags & NFT_QUEUE_FLAG_BYPASS)
		ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;

	regs->verdict.code = ret;
}

__attribute__((used)) static int nft_queue_init(const struct nft_ctx *ctx,
			  const struct nft_expr *expr,
			  const struct nlattr * const tb[])
{
	struct nft_queue *priv = nft_expr_priv(expr);
	u32 maxid;

	priv->queuenum = ntohs(nla_get_be16(tb[NFTA_QUEUE_NUM]));

	if (tb[NFTA_QUEUE_TOTAL])
		priv->queues_total = ntohs(nla_get_be16(tb[NFTA_QUEUE_TOTAL]));
	else
		priv->queues_total = 1;

	if (priv->queues_total == 0)
		return -EINVAL;

	maxid = priv->queues_total - 1 + priv->queuenum;
	if (maxid > U16_MAX)
		return -ERANGE;

	if (tb[NFTA_QUEUE_FLAGS]) {
		priv->flags = ntohs(nla_get_be16(tb[NFTA_QUEUE_FLAGS]));
		if (priv->flags & ~NFT_QUEUE_FLAG_MASK)
			return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int nft_queue_sreg_init(const struct nft_ctx *ctx,
			       const struct nft_expr *expr,
			       const struct nlattr * const tb[])
{
	struct nft_queue *priv = nft_expr_priv(expr);
	int err;

	priv->sreg_qnum = nft_parse_register(tb[NFTA_QUEUE_SREG_QNUM]);
	err = nft_validate_register_load(priv->sreg_qnum, sizeof(u32));
	if (err < 0)
		return err;

	if (tb[NFTA_QUEUE_FLAGS]) {
		priv->flags = ntohs(nla_get_be16(tb[NFTA_QUEUE_FLAGS]));
		if (priv->flags & ~NFT_QUEUE_FLAG_MASK)
			return -EINVAL;
		if (priv->flags & NFT_QUEUE_FLAG_CPU_FANOUT)
			return -EOPNOTSUPP;
	}

	return 0;
}

__attribute__((used)) static int nft_queue_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_queue *priv = nft_expr_priv(expr);

	if (nla_put_be16(skb, NFTA_QUEUE_NUM, htons(priv->queuenum)) ||
	    nla_put_be16(skb, NFTA_QUEUE_TOTAL, htons(priv->queues_total)) ||
	    nla_put_be16(skb, NFTA_QUEUE_FLAGS, htons(priv->flags)))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static int
nft_queue_sreg_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_queue *priv = nft_expr_priv(expr);

	if (nft_dump_register(skb, NFTA_QUEUE_SREG_QNUM, priv->sreg_qnum) ||
	    nla_put_be16(skb, NFTA_QUEUE_FLAGS, htons(priv->flags)))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}

__attribute__((used)) static const struct nft_expr_ops *
nft_queue_select_ops(const struct nft_ctx *ctx,
		     const struct nlattr * const tb[])
{
	if (tb[NFTA_QUEUE_NUM] && tb[NFTA_QUEUE_SREG_QNUM])
		return ERR_PTR(-EINVAL);

	init_hashrandom(&jhash_initval);

	if (tb[NFTA_QUEUE_NUM])
		return &nft_queue_ops;

	if (tb[NFTA_QUEUE_SREG_QNUM])
		return &nft_queue_sreg_ops;

	return ERR_PTR(-EINVAL);
}


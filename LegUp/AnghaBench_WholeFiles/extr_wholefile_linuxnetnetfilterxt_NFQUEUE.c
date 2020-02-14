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
struct xt_tgchk_param {TYPE_1__* target; struct xt_NFQ_info_v3* targinfo; } ;
struct xt_action_param {struct xt_NFQ_info_v3* targinfo; } ;
struct xt_NFQ_info_v3 {int queuenum; int queues_total; int flags; scalar_t__ bypass; } ;
struct xt_NFQ_info_v2 {int queuenum; int queues_total; int flags; scalar_t__ bypass; } ;
struct xt_NFQ_info_v1 {int queuenum; int queues_total; int flags; scalar_t__ bypass; } ;
struct xt_NFQ_info {int queuenum; int queues_total; int flags; scalar_t__ bypass; } ;
struct sk_buff {int dummy; } ;
struct TYPE_2__ {int revision; } ;

/* Variables and functions */
 int EINVAL ; 
 int ERANGE ; 
 int NFQ_FLAG_BYPASS ; 
 int NFQ_FLAG_CPU_FANOUT ; 
 int NFQ_FLAG_MASK ; 
 unsigned int NF_QUEUE_NR (int) ; 
 unsigned int NF_VERDICT_FLAG_QUEUE_BYPASS ; 
 int /*<<< orphan*/  init_hashrandom (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jhash_initval ; 
 int nfqueue_hash (struct sk_buff*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,...) ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  xt_family (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
nfqueue_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_NFQ_info *tinfo = par->targinfo;

	return NF_QUEUE_NR(tinfo->queuenum);
}

__attribute__((used)) static unsigned int
nfqueue_tg_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_NFQ_info_v1 *info = par->targinfo;
	u32 queue = info->queuenum;

	if (info->queues_total > 1) {
		queue = nfqueue_hash(skb, queue, info->queues_total,
				     xt_family(par), jhash_initval);
	}
	return NF_QUEUE_NR(queue);
}

__attribute__((used)) static unsigned int
nfqueue_tg_v2(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_NFQ_info_v2 *info = par->targinfo;
	unsigned int ret = nfqueue_tg_v1(skb, par);

	if (info->bypass)
		ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;
	return ret;
}

__attribute__((used)) static int nfqueue_tg_check(const struct xt_tgchk_param *par)
{
	const struct xt_NFQ_info_v3 *info = par->targinfo;
	u32 maxid;

	init_hashrandom(&jhash_initval);

	if (info->queues_total == 0) {
		pr_info_ratelimited("number of total queues is 0\n");
		return -EINVAL;
	}
	maxid = info->queues_total - 1 + info->queuenum;
	if (maxid > 0xffff) {
		pr_info_ratelimited("number of queues (%u) out of range (got %u)\n",
				    info->queues_total, maxid);
		return -ERANGE;
	}
	if (par->target->revision == 2 && info->flags > 1)
		return -EINVAL;
	if (par->target->revision == 3 && info->flags & ~NFQ_FLAG_MASK)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static unsigned int
nfqueue_tg_v3(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_NFQ_info_v3 *info = par->targinfo;
	u32 queue = info->queuenum;
	int ret;

	if (info->queues_total > 1) {
		if (info->flags & NFQ_FLAG_CPU_FANOUT) {
			int cpu = smp_processor_id();

			queue = info->queuenum + cpu % info->queues_total;
		} else {
			queue = nfqueue_hash(skb, queue, info->queues_total,
					     xt_family(par), jhash_initval);
		}
	}

	ret = NF_QUEUE_NR(queue);
	if (info->flags & NFQ_FLAG_BYPASS)
		ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;

	return ret;
}


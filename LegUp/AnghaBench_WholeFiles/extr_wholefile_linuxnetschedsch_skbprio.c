#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct tcmsg {int /*<<< orphan*/  tcm_handle; } ;
struct tc_skbprio_qopt {int limit; } ;
struct skbprio_sched_data {int highest_prio; int lowest_prio; TYPE_3__* qstats; struct sk_buff_head* qdiscs; } ;
struct sk_buff_head {int dummy; } ;
struct sk_buff {int len; int /*<<< orphan*/  priority; } ;
struct qdisc_walker {int stop; scalar_t__ count; scalar_t__ skip; scalar_t__ (* fn ) (struct Qdisc*,unsigned int,struct qdisc_walker*) ;} ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct gnet_dump {int dummy; } ;
struct TYPE_6__ {int qlen; } ;
struct TYPE_5__ {scalar_t__ backlog; } ;
struct Qdisc {int limit; TYPE_2__ q; TYPE_1__ qstats; } ;
typedef  int /*<<< orphan*/  opt ;
struct TYPE_7__ {int /*<<< orphan*/  qlen; int /*<<< orphan*/  backlog; int /*<<< orphan*/  overlimits; int /*<<< orphan*/  drops; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int NET_XMIT_CN ; 
 int NET_XMIT_SUCCESS ; 
 int SKBPRIO_MAX_PRIORITY ; 
 int /*<<< orphan*/  TCA_OPTIONS ; 
 int /*<<< orphan*/  TC_H_MIN (unsigned long) ; 
 struct sk_buff* __skb_dequeue (struct sk_buff_head*) ; 
 struct sk_buff* __skb_dequeue_tail (struct sk_buff_head*) ; 
 int /*<<< orphan*/  __skb_queue_head_init (struct sk_buff_head*) ; 
 int /*<<< orphan*/  __skb_queue_purge (struct sk_buff_head*) ; 
 int /*<<< orphan*/  __skb_queue_tail (struct sk_buff_head*,struct sk_buff*) ; 
 scalar_t__ gnet_stats_copy_queue (struct gnet_dump*,int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_3__**,int /*<<< orphan*/ ,int) ; 
 int min (int /*<<< orphan*/ ,unsigned int const) ; 
 struct tc_skbprio_qopt* nla_data (struct nlattr*) ; 
 scalar_t__ nla_put (struct sk_buff*,int /*<<< orphan*/ ,int,struct tc_skbprio_qopt*) ; 
 int /*<<< orphan*/  qdisc_bstats_update (struct Qdisc*,struct sk_buff*) ; 
 int qdisc_drop (struct sk_buff*,struct Qdisc*,struct sk_buff**) ; 
 scalar_t__ qdisc_pkt_len (struct sk_buff*) ; 
 struct skbprio_sched_data* qdisc_priv (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_qstats_backlog_dec (struct Qdisc*,struct sk_buff*) ; 
 int /*<<< orphan*/  qdisc_qstats_backlog_inc (struct Qdisc*,struct sk_buff*) ; 
 scalar_t__ skb_queue_empty (struct sk_buff_head*) ; 
 scalar_t__ stub1 (struct Qdisc*,unsigned int,struct qdisc_walker*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static u16 calc_new_high_prio(const struct skbprio_sched_data *q)
{
	int prio;

	for (prio = q->highest_prio - 1; prio >= q->lowest_prio; prio--) {
		if (!skb_queue_empty(&q->qdiscs[prio]))
			return prio;
	}

	/* SKB queue is empty, return 0 (default highest priority setting). */
	return 0;
}

__attribute__((used)) static u16 calc_new_low_prio(const struct skbprio_sched_data *q)
{
	int prio;

	for (prio = q->lowest_prio + 1; prio <= q->highest_prio; prio++) {
		if (!skb_queue_empty(&q->qdiscs[prio]))
			return prio;
	}

	/* SKB queue is empty, return SKBPRIO_MAX_PRIORITY - 1
	 * (default lowest priority setting).
	 */
	return SKBPRIO_MAX_PRIORITY - 1;
}

__attribute__((used)) static int skbprio_enqueue(struct sk_buff *skb, struct Qdisc *sch,
			  struct sk_buff **to_free)
{
	const unsigned int max_priority = SKBPRIO_MAX_PRIORITY - 1;
	struct skbprio_sched_data *q = qdisc_priv(sch);
	struct sk_buff_head *qdisc;
	struct sk_buff_head *lp_qdisc;
	struct sk_buff *to_drop;
	u16 prio, lp;

	/* Obtain the priority of @skb. */
	prio = min(skb->priority, max_priority);

	qdisc = &q->qdiscs[prio];
	if (sch->q.qlen < sch->limit) {
		__skb_queue_tail(qdisc, skb);
		qdisc_qstats_backlog_inc(sch, skb);
		q->qstats[prio].backlog += qdisc_pkt_len(skb);

		/* Check to update highest and lowest priorities. */
		if (prio > q->highest_prio)
			q->highest_prio = prio;

		if (prio < q->lowest_prio)
			q->lowest_prio = prio;

		sch->q.qlen++;
		return NET_XMIT_SUCCESS;
	}

	/* If this packet has the lowest priority, drop it. */
	lp = q->lowest_prio;
	if (prio <= lp) {
		q->qstats[prio].drops++;
		q->qstats[prio].overlimits++;
		return qdisc_drop(skb, sch, to_free);
	}

	__skb_queue_tail(qdisc, skb);
	qdisc_qstats_backlog_inc(sch, skb);
	q->qstats[prio].backlog += qdisc_pkt_len(skb);

	/* Drop the packet at the tail of the lowest priority qdisc. */
	lp_qdisc = &q->qdiscs[lp];
	to_drop = __skb_dequeue_tail(lp_qdisc);
	BUG_ON(!to_drop);
	qdisc_qstats_backlog_dec(sch, to_drop);
	qdisc_drop(to_drop, sch, to_free);

	q->qstats[lp].backlog -= qdisc_pkt_len(to_drop);
	q->qstats[lp].drops++;
	q->qstats[lp].overlimits++;

	/* Check to update highest and lowest priorities. */
	if (skb_queue_empty(lp_qdisc)) {
		if (q->lowest_prio == q->highest_prio) {
			/* The incoming packet is the only packet in queue. */
			BUG_ON(sch->q.qlen != 1);
			q->lowest_prio = prio;
			q->highest_prio = prio;
		} else {
			q->lowest_prio = calc_new_low_prio(q);
		}
	}

	if (prio > q->highest_prio)
		q->highest_prio = prio;

	return NET_XMIT_CN;
}

__attribute__((used)) static struct sk_buff *skbprio_dequeue(struct Qdisc *sch)
{
	struct skbprio_sched_data *q = qdisc_priv(sch);
	struct sk_buff_head *hpq = &q->qdiscs[q->highest_prio];
	struct sk_buff *skb = __skb_dequeue(hpq);

	if (unlikely(!skb))
		return NULL;

	sch->q.qlen--;
	qdisc_qstats_backlog_dec(sch, skb);
	qdisc_bstats_update(sch, skb);

	q->qstats[q->highest_prio].backlog -= qdisc_pkt_len(skb);

	/* Update highest priority field. */
	if (skb_queue_empty(hpq)) {
		if (q->lowest_prio == q->highest_prio) {
			BUG_ON(sch->q.qlen);
			q->highest_prio = 0;
			q->lowest_prio = SKBPRIO_MAX_PRIORITY - 1;
		} else {
			q->highest_prio = calc_new_high_prio(q);
		}
	}
	return skb;
}

__attribute__((used)) static int skbprio_change(struct Qdisc *sch, struct nlattr *opt,
			struct netlink_ext_ack *extack)
{
	struct tc_skbprio_qopt *ctl = nla_data(opt);

	sch->limit = ctl->limit;
	return 0;
}

__attribute__((used)) static int skbprio_init(struct Qdisc *sch, struct nlattr *opt,
			struct netlink_ext_ack *extack)
{
	struct skbprio_sched_data *q = qdisc_priv(sch);
	int prio;

	/* Initialise all queues, one for each possible priority. */
	for (prio = 0; prio < SKBPRIO_MAX_PRIORITY; prio++)
		__skb_queue_head_init(&q->qdiscs[prio]);

	memset(&q->qstats, 0, sizeof(q->qstats));
	q->highest_prio = 0;
	q->lowest_prio = SKBPRIO_MAX_PRIORITY - 1;
	sch->limit = 64;
	if (!opt)
		return 0;

	return skbprio_change(sch, opt, extack);
}

__attribute__((used)) static int skbprio_dump(struct Qdisc *sch, struct sk_buff *skb)
{
	struct tc_skbprio_qopt opt;

	opt.limit = sch->limit;

	if (nla_put(skb, TCA_OPTIONS, sizeof(opt), &opt))
		return -1;

	return skb->len;
}

__attribute__((used)) static void skbprio_reset(struct Qdisc *sch)
{
	struct skbprio_sched_data *q = qdisc_priv(sch);
	int prio;

	sch->qstats.backlog = 0;
	sch->q.qlen = 0;

	for (prio = 0; prio < SKBPRIO_MAX_PRIORITY; prio++)
		__skb_queue_purge(&q->qdiscs[prio]);

	memset(&q->qstats, 0, sizeof(q->qstats));
	q->highest_prio = 0;
	q->lowest_prio = SKBPRIO_MAX_PRIORITY - 1;
}

__attribute__((used)) static void skbprio_destroy(struct Qdisc *sch)
{
	struct skbprio_sched_data *q = qdisc_priv(sch);
	int prio;

	for (prio = 0; prio < SKBPRIO_MAX_PRIORITY; prio++)
		__skb_queue_purge(&q->qdiscs[prio]);
}

__attribute__((used)) static struct Qdisc *skbprio_leaf(struct Qdisc *sch, unsigned long arg)
{
	return NULL;
}

__attribute__((used)) static unsigned long skbprio_find(struct Qdisc *sch, u32 classid)
{
	return 0;
}

__attribute__((used)) static int skbprio_dump_class(struct Qdisc *sch, unsigned long cl,
			     struct sk_buff *skb, struct tcmsg *tcm)
{
	tcm->tcm_handle |= TC_H_MIN(cl);
	return 0;
}

__attribute__((used)) static int skbprio_dump_class_stats(struct Qdisc *sch, unsigned long cl,
				   struct gnet_dump *d)
{
	struct skbprio_sched_data *q = qdisc_priv(sch);
	if (gnet_stats_copy_queue(d, NULL, &q->qstats[cl - 1],
		q->qstats[cl - 1].qlen) < 0)
		return -1;
	return 0;
}

__attribute__((used)) static void skbprio_walk(struct Qdisc *sch, struct qdisc_walker *arg)
{
	unsigned int i;

	if (arg->stop)
		return;

	for (i = 0; i < SKBPRIO_MAX_PRIORITY; i++) {
		if (arg->count < arg->skip) {
			arg->count++;
			continue;
		}
		if (arg->fn(sch, i + 1, arg) < 0) {
			arg->stop = 1;
			break;
		}
		arg->count++;
	}
}


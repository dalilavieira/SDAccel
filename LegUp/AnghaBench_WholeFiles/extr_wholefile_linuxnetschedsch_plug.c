#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct tc_plug_qopt {int limit; int action; } ;
struct sk_buff {scalar_t__ len; } ;
struct plug_sched_data {scalar_t__ limit; int unplug_indefinite; int throttled; scalar_t__ pkts_current_epoch; scalar_t__ pkts_last_epoch; scalar_t__ pkts_to_release; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct TYPE_4__ {scalar_t__ backlog; } ;
struct Qdisc {int /*<<< orphan*/  dev_queue; TYPE_1__ qstats; } ;
struct TYPE_5__ {int tx_queue_len; } ;

/* Variables and functions */
 int EINVAL ; 
#define  TCQ_PLUG_BUFFER 131 
#define  TCQ_PLUG_LIMIT 130 
#define  TCQ_PLUG_RELEASE_INDEFINITE 129 
#define  TCQ_PLUG_RELEASE_ONE 128 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  netif_schedule_queue (int /*<<< orphan*/ ) ; 
 struct tc_plug_qopt* nla_data (struct nlattr*) ; 
 int nla_len (struct nlattr*) ; 
 int psched_mtu (TYPE_2__*) ; 
 struct sk_buff* qdisc_dequeue_head (struct Qdisc*) ; 
 TYPE_2__* qdisc_dev (struct Qdisc*) ; 
 int qdisc_drop (struct sk_buff*,struct Qdisc*,struct sk_buff**) ; 
 int qdisc_enqueue_tail (struct sk_buff*,struct Qdisc*) ; 
 struct plug_sched_data* qdisc_priv (struct Qdisc*) ; 

__attribute__((used)) static int plug_enqueue(struct sk_buff *skb, struct Qdisc *sch,
			struct sk_buff **to_free)
{
	struct plug_sched_data *q = qdisc_priv(sch);

	if (likely(sch->qstats.backlog + skb->len <= q->limit)) {
		if (!q->unplug_indefinite)
			q->pkts_current_epoch++;
		return qdisc_enqueue_tail(skb, sch);
	}

	return qdisc_drop(skb, sch, to_free);
}

__attribute__((used)) static struct sk_buff *plug_dequeue(struct Qdisc *sch)
{
	struct plug_sched_data *q = qdisc_priv(sch);

	if (q->throttled)
		return NULL;

	if (!q->unplug_indefinite) {
		if (!q->pkts_to_release) {
			/* No more packets to dequeue. Block the queue
			 * and wait for the next release command.
			 */
			q->throttled = true;
			return NULL;
		}
		q->pkts_to_release--;
	}

	return qdisc_dequeue_head(sch);
}

__attribute__((used)) static int plug_init(struct Qdisc *sch, struct nlattr *opt,
		     struct netlink_ext_ack *extack)
{
	struct plug_sched_data *q = qdisc_priv(sch);

	q->pkts_current_epoch = 0;
	q->pkts_last_epoch = 0;
	q->pkts_to_release = 0;
	q->unplug_indefinite = false;

	if (opt == NULL) {
		q->limit = qdisc_dev(sch)->tx_queue_len
		           * psched_mtu(qdisc_dev(sch));
	} else {
		struct tc_plug_qopt *ctl = nla_data(opt);

		if (nla_len(opt) < sizeof(*ctl))
			return -EINVAL;

		q->limit = ctl->limit;
	}

	q->throttled = true;
	return 0;
}

__attribute__((used)) static int plug_change(struct Qdisc *sch, struct nlattr *opt,
		       struct netlink_ext_ack *extack)
{
	struct plug_sched_data *q = qdisc_priv(sch);
	struct tc_plug_qopt *msg;

	if (opt == NULL)
		return -EINVAL;

	msg = nla_data(opt);
	if (nla_len(opt) < sizeof(*msg))
		return -EINVAL;

	switch (msg->action) {
	case TCQ_PLUG_BUFFER:
		/* Save size of the current buffer */
		q->pkts_last_epoch = q->pkts_current_epoch;
		q->pkts_current_epoch = 0;
		if (q->unplug_indefinite)
			q->throttled = true;
		q->unplug_indefinite = false;
		break;
	case TCQ_PLUG_RELEASE_ONE:
		/* Add packets from the last complete buffer to the
		 * packets to be released set.
		 */
		q->pkts_to_release += q->pkts_last_epoch;
		q->pkts_last_epoch = 0;
		q->throttled = false;
		netif_schedule_queue(sch->dev_queue);
		break;
	case TCQ_PLUG_RELEASE_INDEFINITE:
		q->unplug_indefinite = true;
		q->pkts_to_release = 0;
		q->pkts_last_epoch = 0;
		q->pkts_current_epoch = 0;
		q->throttled = false;
		netif_schedule_queue(sch->dev_queue);
		break;
	case TCQ_PLUG_LIMIT:
		/* Limit is supplied in bytes */
		q->limit = msg->limit;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}


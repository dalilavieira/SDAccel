#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_9__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct tc_etf_qopt_offload {int enable; scalar_t__ queue; } ;
struct tc_etf_qopt {scalar_t__ clockid; scalar_t__ delta; int /*<<< orphan*/  flags; } ;
struct TYPE_10__ {int ee_errno; int ee_data; int ee_info; scalar_t__ ee_pad; int /*<<< orphan*/  ee_code; scalar_t__ ee_type; int /*<<< orphan*/  ee_origin; } ;
struct sock_exterr_skb {TYPE_1__ ee; } ;
struct sock {scalar_t__ sk_clockid; scalar_t__ sk_txtime_deadline_mode; int /*<<< orphan*/  sk_txtime_report_errors; } ;
struct sk_buff {int tstamp; int /*<<< orphan*/  rbnode; void* dev; int /*<<< orphan*/ * prev; int /*<<< orphan*/ * next; struct sock* sk; } ;
struct rb_node {struct rb_node* rb_left; struct rb_node* rb_right; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct net_device_ops {int (* ndo_setup_tc ) (struct net_device*,int /*<<< orphan*/ ,struct tc_etf_qopt_offload*) ;} ;
struct net_device {struct net_device_ops* netdev_ops; } ;
struct TYPE_13__ {struct Qdisc* qdisc; } ;
struct TYPE_12__ {struct rb_node* rb_node; } ;
struct etf_sched_data {scalar_t__ clockid; scalar_t__ deadline_mode; int (* get_time ) () ;int last; scalar_t__ delta; scalar_t__ offload; TYPE_6__ watchdog; TYPE_3__ head; scalar_t__ queue; } ;
struct TYPE_14__ {scalar_t__ qlen; } ;
struct TYPE_11__ {scalar_t__ backlog; } ;
struct Qdisc {TYPE_9__ q; TYPE_2__ qstats; scalar_t__ dev_queue; } ;
typedef  int /*<<< orphan*/  opt ;
typedef  int ktime_t ;

/* Variables and functions */
#define  CLOCK_BOOTTIME 131 
#define  CLOCK_MONOTONIC 130 
#define  CLOCK_REALTIME 129 
#define  CLOCK_TAI 128 
 scalar_t__ DEADLINE_MODE_IS_ON (struct tc_etf_qopt*) ; 
 int ECANCELED ; 
 int EINVAL ; 
 int ENOTSUPP ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int NET_XMIT_SUCCESS ; 
 int /*<<< orphan*/  NL_SET_ERR_MSG (struct netlink_ext_ack*,char*) ; 
 scalar_t__ OFFLOAD_IS_ON (struct tc_etf_qopt*) ; 
 struct sock_exterr_skb* SKB_EXT_ERR (struct sk_buff*) ; 
 int /*<<< orphan*/  SOCK_TXTIME ; 
 int /*<<< orphan*/  SO_EE_CODE_TXTIME_INVALID_PARAM ; 
 int /*<<< orphan*/  SO_EE_CODE_TXTIME_MISSED ; 
 int /*<<< orphan*/  SO_EE_ORIGIN_TXTIME ; 
 int /*<<< orphan*/  TCA_ETF_MAX ; 
 size_t TCA_ETF_PARMS ; 
 int /*<<< orphan*/  TCA_OPTIONS ; 
 int /*<<< orphan*/  TC_ETF_DEADLINE_MODE_ON ; 
 int /*<<< orphan*/  TC_ETF_OFFLOAD_ON ; 
 int /*<<< orphan*/  TC_SETUP_QDISC_ETF ; 
 int /*<<< orphan*/  __qdisc_reset_queue (TYPE_9__*) ; 
 int /*<<< orphan*/  etf_policy ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree_skb_list (struct sk_buff*) ; 
 scalar_t__ ktime_after (int,int) ; 
 scalar_t__ ktime_before (int,int) ; 
 int ktime_get () ; 
 int ktime_get_boottime () ; 
 int ktime_get_clocktai () ; 
 int ktime_get_real () ; 
 int ktime_sub_ns (int,scalar_t__) ; 
 int /*<<< orphan*/  ktime_to_ns (int) ; 
 scalar_t__ netdev_get_tx_queue (struct net_device*,int /*<<< orphan*/ ) ; 
 struct tc_etf_qopt* nla_data (struct nlattr*) ; 
 int /*<<< orphan*/  nla_nest_cancel (struct sk_buff*,struct nlattr*) ; 
 int nla_nest_end (struct sk_buff*,struct nlattr*) ; 
 struct nlattr* nla_nest_start (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int nla_parse_nested (struct nlattr**,int /*<<< orphan*/ ,struct nlattr*,int /*<<< orphan*/ ,struct netlink_ext_ack*) ; 
 scalar_t__ nla_put (struct sk_buff*,size_t,int,struct tc_etf_qopt*) ; 
 int /*<<< orphan*/  pr_debug (char*,scalar_t__,scalar_t__,char*,char*) ; 
 int /*<<< orphan*/  pr_warn (char*,scalar_t__) ; 
 int /*<<< orphan*/  qdisc_bstats_update (struct Qdisc*,struct sk_buff*) ; 
 void* qdisc_dev (struct Qdisc*) ; 
 int qdisc_drop (struct sk_buff*,struct Qdisc*,struct sk_buff**) ; 
 struct etf_sched_data* qdisc_priv (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_qstats_backlog_dec (struct Qdisc*,struct sk_buff*) ; 
 int /*<<< orphan*/  qdisc_qstats_backlog_inc (struct Qdisc*,struct sk_buff*) ; 
 int /*<<< orphan*/  qdisc_qstats_overlimit (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_watchdog_cancel (TYPE_6__*) ; 
 int /*<<< orphan*/  qdisc_watchdog_init_clockid (TYPE_6__*,struct Qdisc*,int) ; 
 int /*<<< orphan*/  qdisc_watchdog_schedule_ns (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rb_erase (int /*<<< orphan*/ *,TYPE_3__*) ; 
 struct rb_node* rb_first (TYPE_3__*) ; 
 int /*<<< orphan*/  rb_insert_color (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  rb_link_node (int /*<<< orphan*/ *,struct rb_node*,struct rb_node**) ; 
 struct rb_node* rb_next (struct rb_node*) ; 
 struct sk_buff* rb_to_skb (struct rb_node*) ; 
 int /*<<< orphan*/  rtnl_kfree_skbs (struct sk_buff*,struct sk_buff*) ; 
 struct sk_buff* skb_clone (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_flag (struct sock*,int /*<<< orphan*/ ) ; 
 scalar_t__ sock_queue_err_skb (struct sock*,struct sk_buff*) ; 
 int stub1 () ; 
 int stub2 () ; 
 int stub3 (struct net_device*,int /*<<< orphan*/ ,struct tc_etf_qopt_offload*) ; 
 int stub4 (struct net_device*,int /*<<< orphan*/ ,struct tc_etf_qopt_offload*) ; 

__attribute__((used)) static inline int validate_input_params(struct tc_etf_qopt *qopt,
					struct netlink_ext_ack *extack)
{
	/* Check if params comply to the following rules:
	 *	* Clockid and delta must be valid.
	 *
	 *	* Dynamic clockids are not supported.
	 *
	 *	* Delta must be a positive integer.
	 *
	 * Also note that for the HW offload case, we must
	 * expect that system clocks have been synchronized to PHC.
	 */
	if (qopt->clockid < 0) {
		NL_SET_ERR_MSG(extack, "Dynamic clockids are not supported");
		return -ENOTSUPP;
	}

	if (qopt->clockid != CLOCK_TAI) {
		NL_SET_ERR_MSG(extack, "Invalid clockid. CLOCK_TAI must be used");
		return -EINVAL;
	}

	if (qopt->delta < 0) {
		NL_SET_ERR_MSG(extack, "Delta must be positive");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static bool is_packet_valid(struct Qdisc *sch, struct sk_buff *nskb)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	ktime_t txtime = nskb->tstamp;
	struct sock *sk = nskb->sk;
	ktime_t now;

	if (!sk)
		return false;

	if (!sock_flag(sk, SOCK_TXTIME))
		return false;

	/* We don't perform crosstimestamping.
	 * Drop if packet's clockid differs from qdisc's.
	 */
	if (sk->sk_clockid != q->clockid)
		return false;

	if (sk->sk_txtime_deadline_mode != q->deadline_mode)
		return false;

	now = q->get_time();
	if (ktime_before(txtime, now) || ktime_before(txtime, q->last))
		return false;

	return true;
}

__attribute__((used)) static struct sk_buff *etf_peek_timesortedlist(struct Qdisc *sch)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct rb_node *p;

	p = rb_first(&q->head);
	if (!p)
		return NULL;

	return rb_to_skb(p);
}

__attribute__((used)) static void reset_watchdog(struct Qdisc *sch)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct sk_buff *skb = etf_peek_timesortedlist(sch);
	ktime_t next;

	if (!skb)
		return;

	next = ktime_sub_ns(skb->tstamp, q->delta);
	qdisc_watchdog_schedule_ns(&q->watchdog, ktime_to_ns(next));
}

__attribute__((used)) static void report_sock_error(struct sk_buff *skb, u32 err, u8 code)
{
	struct sock_exterr_skb *serr;
	struct sk_buff *clone;
	ktime_t txtime = skb->tstamp;

	if (!skb->sk || !(skb->sk->sk_txtime_report_errors))
		return;

	clone = skb_clone(skb, GFP_ATOMIC);
	if (!clone)
		return;

	serr = SKB_EXT_ERR(clone);
	serr->ee.ee_errno = err;
	serr->ee.ee_origin = SO_EE_ORIGIN_TXTIME;
	serr->ee.ee_type = 0;
	serr->ee.ee_code = code;
	serr->ee.ee_pad = 0;
	serr->ee.ee_data = (txtime >> 32); /* high part of tstamp */
	serr->ee.ee_info = txtime; /* low part of tstamp */

	if (sock_queue_err_skb(skb->sk, clone))
		kfree_skb(clone);
}

__attribute__((used)) static int etf_enqueue_timesortedlist(struct sk_buff *nskb, struct Qdisc *sch,
				      struct sk_buff **to_free)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct rb_node **p = &q->head.rb_node, *parent = NULL;
	ktime_t txtime = nskb->tstamp;

	if (!is_packet_valid(sch, nskb)) {
		report_sock_error(nskb, EINVAL,
				  SO_EE_CODE_TXTIME_INVALID_PARAM);
		return qdisc_drop(nskb, sch, to_free);
	}

	while (*p) {
		struct sk_buff *skb;

		parent = *p;
		skb = rb_to_skb(parent);
		if (ktime_after(txtime, skb->tstamp))
			p = &parent->rb_right;
		else
			p = &parent->rb_left;
	}
	rb_link_node(&nskb->rbnode, parent, p);
	rb_insert_color(&nskb->rbnode, &q->head);

	qdisc_qstats_backlog_inc(sch, nskb);
	sch->q.qlen++;

	/* Now we may need to re-arm the qdisc watchdog for the next packet. */
	reset_watchdog(sch);

	return NET_XMIT_SUCCESS;
}

__attribute__((used)) static void timesortedlist_erase(struct Qdisc *sch, struct sk_buff *skb,
				 bool drop)
{
	struct etf_sched_data *q = qdisc_priv(sch);

	rb_erase(&skb->rbnode, &q->head);

	/* The rbnode field in the skb re-uses these fields, now that
	 * we are done with the rbnode, reset them.
	 */
	skb->next = NULL;
	skb->prev = NULL;
	skb->dev = qdisc_dev(sch);

	qdisc_qstats_backlog_dec(sch, skb);

	if (drop) {
		struct sk_buff *to_free = NULL;

		report_sock_error(skb, ECANCELED, SO_EE_CODE_TXTIME_MISSED);

		qdisc_drop(skb, sch, &to_free);
		kfree_skb_list(to_free);
		qdisc_qstats_overlimit(sch);
	} else {
		qdisc_bstats_update(sch, skb);

		q->last = skb->tstamp;
	}

	sch->q.qlen--;
}

__attribute__((used)) static struct sk_buff *etf_dequeue_timesortedlist(struct Qdisc *sch)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct sk_buff *skb;
	ktime_t now, next;

	skb = etf_peek_timesortedlist(sch);
	if (!skb)
		return NULL;

	now = q->get_time();

	/* Drop if packet has expired while in queue. */
	if (ktime_before(skb->tstamp, now)) {
		timesortedlist_erase(sch, skb, true);
		skb = NULL;
		goto out;
	}

	/* When in deadline mode, dequeue as soon as possible and change the
	 * txtime from deadline to (now + delta).
	 */
	if (q->deadline_mode) {
		timesortedlist_erase(sch, skb, false);
		skb->tstamp = now;
		goto out;
	}

	next = ktime_sub_ns(skb->tstamp, q->delta);

	/* Dequeue only if now is within the [txtime - delta, txtime] range. */
	if (ktime_after(now, next))
		timesortedlist_erase(sch, skb, false);
	else
		skb = NULL;

out:
	/* Now we may need to re-arm the qdisc watchdog for the next packet. */
	reset_watchdog(sch);

	return skb;
}

__attribute__((used)) static void etf_disable_offload(struct net_device *dev,
				struct etf_sched_data *q)
{
	struct tc_etf_qopt_offload etf = { };
	const struct net_device_ops *ops;
	int err;

	if (!q->offload)
		return;

	ops = dev->netdev_ops;
	if (!ops->ndo_setup_tc)
		return;

	etf.queue = q->queue;
	etf.enable = 0;

	err = ops->ndo_setup_tc(dev, TC_SETUP_QDISC_ETF, &etf);
	if (err < 0)
		pr_warn("Couldn't disable ETF offload for queue %d\n",
			etf.queue);
}

__attribute__((used)) static int etf_enable_offload(struct net_device *dev, struct etf_sched_data *q,
			      struct netlink_ext_ack *extack)
{
	const struct net_device_ops *ops = dev->netdev_ops;
	struct tc_etf_qopt_offload etf = { };
	int err;

	if (q->offload)
		return 0;

	if (!ops->ndo_setup_tc) {
		NL_SET_ERR_MSG(extack, "Specified device does not support ETF offload");
		return -EOPNOTSUPP;
	}

	etf.queue = q->queue;
	etf.enable = 1;

	err = ops->ndo_setup_tc(dev, TC_SETUP_QDISC_ETF, &etf);
	if (err < 0) {
		NL_SET_ERR_MSG(extack, "Specified device failed to setup ETF hardware offload");
		return err;
	}

	return 0;
}

__attribute__((used)) static int etf_init(struct Qdisc *sch, struct nlattr *opt,
		    struct netlink_ext_ack *extack)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct net_device *dev = qdisc_dev(sch);
	struct nlattr *tb[TCA_ETF_MAX + 1];
	struct tc_etf_qopt *qopt;
	int err;

	if (!opt) {
		NL_SET_ERR_MSG(extack,
			       "Missing ETF qdisc options which are mandatory");
		return -EINVAL;
	}

	err = nla_parse_nested(tb, TCA_ETF_MAX, opt, etf_policy, extack);
	if (err < 0)
		return err;

	if (!tb[TCA_ETF_PARMS]) {
		NL_SET_ERR_MSG(extack, "Missing mandatory ETF parameters");
		return -EINVAL;
	}

	qopt = nla_data(tb[TCA_ETF_PARMS]);

	pr_debug("delta %d clockid %d offload %s deadline %s\n",
		 qopt->delta, qopt->clockid,
		 OFFLOAD_IS_ON(qopt) ? "on" : "off",
		 DEADLINE_MODE_IS_ON(qopt) ? "on" : "off");

	err = validate_input_params(qopt, extack);
	if (err < 0)
		return err;

	q->queue = sch->dev_queue - netdev_get_tx_queue(dev, 0);

	if (OFFLOAD_IS_ON(qopt)) {
		err = etf_enable_offload(dev, q, extack);
		if (err < 0)
			return err;
	}

	/* Everything went OK, save the parameters used. */
	q->delta = qopt->delta;
	q->clockid = qopt->clockid;
	q->offload = OFFLOAD_IS_ON(qopt);
	q->deadline_mode = DEADLINE_MODE_IS_ON(qopt);

	switch (q->clockid) {
	case CLOCK_REALTIME:
		q->get_time = ktime_get_real;
		break;
	case CLOCK_MONOTONIC:
		q->get_time = ktime_get;
		break;
	case CLOCK_BOOTTIME:
		q->get_time = ktime_get_boottime;
		break;
	case CLOCK_TAI:
		q->get_time = ktime_get_clocktai;
		break;
	default:
		NL_SET_ERR_MSG(extack, "Clockid is not supported");
		return -ENOTSUPP;
	}

	qdisc_watchdog_init_clockid(&q->watchdog, sch, q->clockid);

	return 0;
}

__attribute__((used)) static void timesortedlist_clear(struct Qdisc *sch)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct rb_node *p = rb_first(&q->head);

	while (p) {
		struct sk_buff *skb = rb_to_skb(p);

		p = rb_next(p);

		rb_erase(&skb->rbnode, &q->head);
		rtnl_kfree_skbs(skb, skb);
		sch->q.qlen--;
	}
}

__attribute__((used)) static void etf_reset(struct Qdisc *sch)
{
	struct etf_sched_data *q = qdisc_priv(sch);

	/* Only cancel watchdog if it's been initialized. */
	if (q->watchdog.qdisc == sch)
		qdisc_watchdog_cancel(&q->watchdog);

	/* No matter which mode we are on, it's safe to clear both lists. */
	timesortedlist_clear(sch);
	__qdisc_reset_queue(&sch->q);

	sch->qstats.backlog = 0;
	sch->q.qlen = 0;

	q->last = 0;
}

__attribute__((used)) static void etf_destroy(struct Qdisc *sch)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct net_device *dev = qdisc_dev(sch);

	/* Only cancel watchdog if it's been initialized. */
	if (q->watchdog.qdisc == sch)
		qdisc_watchdog_cancel(&q->watchdog);

	etf_disable_offload(dev, q);
}

__attribute__((used)) static int etf_dump(struct Qdisc *sch, struct sk_buff *skb)
{
	struct etf_sched_data *q = qdisc_priv(sch);
	struct tc_etf_qopt opt = { };
	struct nlattr *nest;

	nest = nla_nest_start(skb, TCA_OPTIONS);
	if (!nest)
		goto nla_put_failure;

	opt.delta = q->delta;
	opt.clockid = q->clockid;
	if (q->offload)
		opt.flags |= TC_ETF_OFFLOAD_ON;

	if (q->deadline_mode)
		opt.flags |= TC_ETF_DEADLINE_MODE_ON;

	if (nla_put(skb, TCA_ETF_PARMS, sizeof(opt), &opt))
		goto nla_put_failure;

	return nla_nest_end(skb, nest);

nla_put_failure:
	nla_nest_cancel(skb, nest);
	return -1;
}


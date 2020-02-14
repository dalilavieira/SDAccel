#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct tc_red_qopt {int qth_min; int qth_max; int Wlog; scalar_t__ limit; int flags; int /*<<< orphan*/  Scell_log; int /*<<< orphan*/  Plog; } ;
struct tc_choke_xstats {int /*<<< orphan*/  matched; int /*<<< orphan*/  other; int /*<<< orphan*/  pdrop; scalar_t__ marked; scalar_t__ early; } ;
struct sk_buff {scalar_t__ protocol; } ;
struct red_parms {scalar_t__ qth_min; scalar_t__ qth_max; int Wlog; int /*<<< orphan*/  max_P; int /*<<< orphan*/  Scell_log; int /*<<< orphan*/  Plog; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct gnet_dump {int dummy; } ;
struct flow_keys {int dummy; } ;
struct choke_skb_cb {int keys_valid; int /*<<< orphan*/  keys; int /*<<< orphan*/  classid; } ;
struct TYPE_15__ {int /*<<< orphan*/  matched; int /*<<< orphan*/  other; int /*<<< orphan*/  pdrop; scalar_t__ forced_mark; scalar_t__ prob_mark; scalar_t__ forced_drop; scalar_t__ prob_drop; } ;
struct TYPE_16__ {scalar_t__ qavg; int qcount; void* qR; } ;
struct choke_sched_data {unsigned int tail; unsigned int head; unsigned int tab_mask; int flags; scalar_t__ limit; struct sk_buff** tab; TYPE_3__ stats; struct red_parms parms; TYPE_4__ vars; } ;
struct TYPE_14__ {scalar_t__ qlen; } ;
struct TYPE_13__ {scalar_t__ backlog; } ;
struct Qdisc {TYPE_2__ q; TYPE_1__ qstats; } ;
typedef  int /*<<< orphan*/  st ;
typedef  int /*<<< orphan*/  opt ;
struct TYPE_12__ {scalar_t__ data; } ;

/* Variables and functions */
 scalar_t__ CHOKE_MAX_QUEUE ; 
 int EINVAL ; 
 int EMSGSIZE ; 
 int ENOMEM ; 
 int GFP_KERNEL ; 
 int /*<<< orphan*/  INET_ECN_set_ce (struct sk_buff*) ; 
 int NET_XMIT_CN ; 
 int NET_XMIT_SUCCESS ; 
 int /*<<< orphan*/  TCA_CHOKE_MAX ; 
 size_t TCA_CHOKE_MAX_P ; 
 size_t TCA_CHOKE_PARMS ; 
 size_t TCA_CHOKE_STAB ; 
 int /*<<< orphan*/  TCA_OPTIONS ; 
 int TC_RED_ECN ; 
 int TC_RED_HARDDROP ; 
 int __GFP_ZERO ; 
 int /*<<< orphan*/  choke_policy ; 
 int gnet_stats_copy_app (struct gnet_dump*,struct tc_choke_xstats*,int) ; 
 int /*<<< orphan*/  kvfree (void*) ; 
 struct sk_buff** kvmalloc_array (unsigned int,int,int) ; 
 int /*<<< orphan*/  make_flow_keys_digest (int /*<<< orphan*/ *,struct flow_keys*) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct sk_buff**,int /*<<< orphan*/ ,int) ; 
 struct tc_red_qopt* nla_data (struct nlattr*) ; 
 int /*<<< orphan*/  nla_get_u32 (struct nlattr*) ; 
 int /*<<< orphan*/  nla_nest_cancel (struct sk_buff*,struct nlattr*) ; 
 int nla_nest_end (struct sk_buff*,struct nlattr*) ; 
 struct nlattr* nla_nest_start (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int nla_parse_nested (struct nlattr**,int /*<<< orphan*/ ,struct nlattr*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ nla_put (struct sk_buff*,size_t,int,struct tc_red_qopt*) ; 
 scalar_t__ nla_put_u32 (struct sk_buff*,size_t,int /*<<< orphan*/ ) ; 
 unsigned int prandom_u32_max (unsigned int) ; 
 int /*<<< orphan*/  qdisc_bstats_update (struct Qdisc*,struct sk_buff*) ; 
 int /*<<< orphan*/  qdisc_cb_private_validate (struct sk_buff const*,int) ; 
 int qdisc_drop (struct sk_buff*,struct Qdisc*,struct sk_buff**) ; 
 unsigned int qdisc_pkt_len (struct sk_buff*) ; 
 struct choke_sched_data* qdisc_priv (struct Qdisc*) ; 
 int /*<<< orphan*/  qdisc_qstats_backlog_dec (struct Qdisc*,struct sk_buff*) ; 
 int /*<<< orphan*/  qdisc_qstats_backlog_inc (struct Qdisc*,struct sk_buff*) ; 
 int /*<<< orphan*/  qdisc_qstats_overlimit (struct Qdisc*) ; 
 TYPE_11__* qdisc_skb_cb (struct sk_buff const*) ; 
 int /*<<< orphan*/  qdisc_tree_reduce_backlog (struct Qdisc*,unsigned int,unsigned int) ; 
 scalar_t__ red_calc_qavg (struct red_parms const*,TYPE_4__*,scalar_t__) ; 
 int /*<<< orphan*/  red_check_params (int,int,int) ; 
 int /*<<< orphan*/  red_end_of_idle_period (TYPE_4__*) ; 
 scalar_t__ red_is_idling (TYPE_4__*) ; 
 scalar_t__ red_mark_probability (struct red_parms const*,TYPE_4__*,scalar_t__) ; 
 void* red_random (struct red_parms const*) ; 
 int /*<<< orphan*/  red_restart (TYPE_4__*) ; 
 int /*<<< orphan*/  red_set_parms (struct red_parms*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct tc_red_qopt*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  red_set_vars (TYPE_4__*) ; 
 int /*<<< orphan*/  red_start_of_idle_period (TYPE_4__*) ; 
 int roundup_pow_of_two (scalar_t__) ; 
 int /*<<< orphan*/  rtnl_qdisc_drop (struct sk_buff*,struct Qdisc*) ; 
 int /*<<< orphan*/  sch_tree_lock (struct Qdisc*) ; 
 int /*<<< orphan*/  sch_tree_unlock (struct Qdisc*) ; 
 int /*<<< orphan*/  skb_flow_dissect_flow_keys (struct sk_buff*,struct flow_keys*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int choke_len(const struct choke_sched_data *q)
{
	return (q->tail - q->head) & q->tab_mask;
}

__attribute__((used)) static int use_ecn(const struct choke_sched_data *q)
{
	return q->flags & TC_RED_ECN;
}

__attribute__((used)) static int use_harddrop(const struct choke_sched_data *q)
{
	return q->flags & TC_RED_HARDDROP;
}

__attribute__((used)) static void choke_zap_head_holes(struct choke_sched_data *q)
{
	do {
		q->head = (q->head + 1) & q->tab_mask;
		if (q->head == q->tail)
			break;
	} while (q->tab[q->head] == NULL);
}

__attribute__((used)) static void choke_zap_tail_holes(struct choke_sched_data *q)
{
	do {
		q->tail = (q->tail - 1) & q->tab_mask;
		if (q->head == q->tail)
			break;
	} while (q->tab[q->tail] == NULL);
}

__attribute__((used)) static void choke_drop_by_idx(struct Qdisc *sch, unsigned int idx,
			      struct sk_buff **to_free)
{
	struct choke_sched_data *q = qdisc_priv(sch);
	struct sk_buff *skb = q->tab[idx];

	q->tab[idx] = NULL;

	if (idx == q->head)
		choke_zap_head_holes(q);
	if (idx == q->tail)
		choke_zap_tail_holes(q);

	qdisc_qstats_backlog_dec(sch, skb);
	qdisc_tree_reduce_backlog(sch, 1, qdisc_pkt_len(skb));
	qdisc_drop(skb, sch, to_free);
	--sch->q.qlen;
}

__attribute__((used)) static inline struct choke_skb_cb *choke_skb_cb(const struct sk_buff *skb)
{
	qdisc_cb_private_validate(skb, sizeof(struct choke_skb_cb));
	return (struct choke_skb_cb *)qdisc_skb_cb(skb)->data;
}

__attribute__((used)) static inline void choke_set_classid(struct sk_buff *skb, u16 classid)
{
	choke_skb_cb(skb)->classid = classid;
}

__attribute__((used)) static bool choke_match_flow(struct sk_buff *skb1,
			     struct sk_buff *skb2)
{
	struct flow_keys temp;

	if (skb1->protocol != skb2->protocol)
		return false;

	if (!choke_skb_cb(skb1)->keys_valid) {
		choke_skb_cb(skb1)->keys_valid = 1;
		skb_flow_dissect_flow_keys(skb1, &temp, 0);
		make_flow_keys_digest(&choke_skb_cb(skb1)->keys, &temp);
	}

	if (!choke_skb_cb(skb2)->keys_valid) {
		choke_skb_cb(skb2)->keys_valid = 1;
		skb_flow_dissect_flow_keys(skb2, &temp, 0);
		make_flow_keys_digest(&choke_skb_cb(skb2)->keys, &temp);
	}

	return !memcmp(&choke_skb_cb(skb1)->keys,
		       &choke_skb_cb(skb2)->keys,
		       sizeof(choke_skb_cb(skb1)->keys));
}

__attribute__((used)) static struct sk_buff *choke_peek_random(const struct choke_sched_data *q,
					 unsigned int *pidx)
{
	struct sk_buff *skb;
	int retrys = 3;

	do {
		*pidx = (q->head + prandom_u32_max(choke_len(q))) & q->tab_mask;
		skb = q->tab[*pidx];
		if (skb)
			return skb;
	} while (--retrys > 0);

	return q->tab[*pidx = q->head];
}

__attribute__((used)) static bool choke_match_random(const struct choke_sched_data *q,
			       struct sk_buff *nskb,
			       unsigned int *pidx)
{
	struct sk_buff *oskb;

	if (q->head == q->tail)
		return false;

	oskb = choke_peek_random(q, pidx);
	return choke_match_flow(oskb, nskb);
}

__attribute__((used)) static int choke_enqueue(struct sk_buff *skb, struct Qdisc *sch,
			 struct sk_buff **to_free)
{
	struct choke_sched_data *q = qdisc_priv(sch);
	const struct red_parms *p = &q->parms;

	choke_skb_cb(skb)->keys_valid = 0;
	/* Compute average queue usage (see RED) */
	q->vars.qavg = red_calc_qavg(p, &q->vars, sch->q.qlen);
	if (red_is_idling(&q->vars))
		red_end_of_idle_period(&q->vars);

	/* Is queue small? */
	if (q->vars.qavg <= p->qth_min)
		q->vars.qcount = -1;
	else {
		unsigned int idx;

		/* Draw a packet at random from queue and compare flow */
		if (choke_match_random(q, skb, &idx)) {
			q->stats.matched++;
			choke_drop_by_idx(sch, idx, to_free);
			goto congestion_drop;
		}

		/* Queue is large, always mark/drop */
		if (q->vars.qavg > p->qth_max) {
			q->vars.qcount = -1;

			qdisc_qstats_overlimit(sch);
			if (use_harddrop(q) || !use_ecn(q) ||
			    !INET_ECN_set_ce(skb)) {
				q->stats.forced_drop++;
				goto congestion_drop;
			}

			q->stats.forced_mark++;
		} else if (++q->vars.qcount) {
			if (red_mark_probability(p, &q->vars, q->vars.qavg)) {
				q->vars.qcount = 0;
				q->vars.qR = red_random(p);

				qdisc_qstats_overlimit(sch);
				if (!use_ecn(q) || !INET_ECN_set_ce(skb)) {
					q->stats.prob_drop++;
					goto congestion_drop;
				}

				q->stats.prob_mark++;
			}
		} else
			q->vars.qR = red_random(p);
	}

	/* Admit new packet */
	if (sch->q.qlen < q->limit) {
		q->tab[q->tail] = skb;
		q->tail = (q->tail + 1) & q->tab_mask;
		++sch->q.qlen;
		qdisc_qstats_backlog_inc(sch, skb);
		return NET_XMIT_SUCCESS;
	}

	q->stats.pdrop++;
	return qdisc_drop(skb, sch, to_free);

congestion_drop:
	qdisc_drop(skb, sch, to_free);
	return NET_XMIT_CN;
}

__attribute__((used)) static struct sk_buff *choke_dequeue(struct Qdisc *sch)
{
	struct choke_sched_data *q = qdisc_priv(sch);
	struct sk_buff *skb;

	if (q->head == q->tail) {
		if (!red_is_idling(&q->vars))
			red_start_of_idle_period(&q->vars);
		return NULL;
	}

	skb = q->tab[q->head];
	q->tab[q->head] = NULL;
	choke_zap_head_holes(q);
	--sch->q.qlen;
	qdisc_qstats_backlog_dec(sch, skb);
	qdisc_bstats_update(sch, skb);

	return skb;
}

__attribute__((used)) static void choke_reset(struct Qdisc *sch)
{
	struct choke_sched_data *q = qdisc_priv(sch);

	while (q->head != q->tail) {
		struct sk_buff *skb = q->tab[q->head];

		q->head = (q->head + 1) & q->tab_mask;
		if (!skb)
			continue;
		rtnl_qdisc_drop(skb, sch);
	}

	sch->q.qlen = 0;
	sch->qstats.backlog = 0;
	memset(q->tab, 0, (q->tab_mask + 1) * sizeof(struct sk_buff *));
	q->head = q->tail = 0;
	red_restart(&q->vars);
}

__attribute__((used)) static void choke_free(void *addr)
{
	kvfree(addr);
}

__attribute__((used)) static int choke_change(struct Qdisc *sch, struct nlattr *opt,
			struct netlink_ext_ack *extack)
{
	struct choke_sched_data *q = qdisc_priv(sch);
	struct nlattr *tb[TCA_CHOKE_MAX + 1];
	const struct tc_red_qopt *ctl;
	int err;
	struct sk_buff **old = NULL;
	unsigned int mask;
	u32 max_P;

	if (opt == NULL)
		return -EINVAL;

	err = nla_parse_nested(tb, TCA_CHOKE_MAX, opt, choke_policy, NULL);
	if (err < 0)
		return err;

	if (tb[TCA_CHOKE_PARMS] == NULL ||
	    tb[TCA_CHOKE_STAB] == NULL)
		return -EINVAL;

	max_P = tb[TCA_CHOKE_MAX_P] ? nla_get_u32(tb[TCA_CHOKE_MAX_P]) : 0;

	ctl = nla_data(tb[TCA_CHOKE_PARMS]);

	if (!red_check_params(ctl->qth_min, ctl->qth_max, ctl->Wlog))
		return -EINVAL;

	if (ctl->limit > CHOKE_MAX_QUEUE)
		return -EINVAL;

	mask = roundup_pow_of_two(ctl->limit + 1) - 1;
	if (mask != q->tab_mask) {
		struct sk_buff **ntab;

		ntab = kvmalloc_array((mask + 1), sizeof(struct sk_buff *), GFP_KERNEL | __GFP_ZERO);
		if (!ntab)
			return -ENOMEM;

		sch_tree_lock(sch);
		old = q->tab;
		if (old) {
			unsigned int oqlen = sch->q.qlen, tail = 0;
			unsigned dropped = 0;

			while (q->head != q->tail) {
				struct sk_buff *skb = q->tab[q->head];

				q->head = (q->head + 1) & q->tab_mask;
				if (!skb)
					continue;
				if (tail < mask) {
					ntab[tail++] = skb;
					continue;
				}
				dropped += qdisc_pkt_len(skb);
				qdisc_qstats_backlog_dec(sch, skb);
				--sch->q.qlen;
				rtnl_qdisc_drop(skb, sch);
			}
			qdisc_tree_reduce_backlog(sch, oqlen - sch->q.qlen, dropped);
			q->head = 0;
			q->tail = tail;
		}

		q->tab_mask = mask;
		q->tab = ntab;
	} else
		sch_tree_lock(sch);

	q->flags = ctl->flags;
	q->limit = ctl->limit;

	red_set_parms(&q->parms, ctl->qth_min, ctl->qth_max, ctl->Wlog,
		      ctl->Plog, ctl->Scell_log,
		      nla_data(tb[TCA_CHOKE_STAB]),
		      max_P);
	red_set_vars(&q->vars);

	if (q->head == q->tail)
		red_end_of_idle_period(&q->vars);

	sch_tree_unlock(sch);
	choke_free(old);
	return 0;
}

__attribute__((used)) static int choke_init(struct Qdisc *sch, struct nlattr *opt,
		      struct netlink_ext_ack *extack)
{
	return choke_change(sch, opt, extack);
}

__attribute__((used)) static int choke_dump(struct Qdisc *sch, struct sk_buff *skb)
{
	struct choke_sched_data *q = qdisc_priv(sch);
	struct nlattr *opts = NULL;
	struct tc_red_qopt opt = {
		.limit		= q->limit,
		.flags		= q->flags,
		.qth_min	= q->parms.qth_min >> q->parms.Wlog,
		.qth_max	= q->parms.qth_max >> q->parms.Wlog,
		.Wlog		= q->parms.Wlog,
		.Plog		= q->parms.Plog,
		.Scell_log	= q->parms.Scell_log,
	};

	opts = nla_nest_start(skb, TCA_OPTIONS);
	if (opts == NULL)
		goto nla_put_failure;

	if (nla_put(skb, TCA_CHOKE_PARMS, sizeof(opt), &opt) ||
	    nla_put_u32(skb, TCA_CHOKE_MAX_P, q->parms.max_P))
		goto nla_put_failure;
	return nla_nest_end(skb, opts);

nla_put_failure:
	nla_nest_cancel(skb, opts);
	return -EMSGSIZE;
}

__attribute__((used)) static int choke_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
	struct choke_sched_data *q = qdisc_priv(sch);
	struct tc_choke_xstats st = {
		.early	= q->stats.prob_drop + q->stats.forced_drop,
		.marked	= q->stats.prob_mark + q->stats.forced_mark,
		.pdrop	= q->stats.pdrop,
		.other	= q->stats.other,
		.matched = q->stats.matched,
	};

	return gnet_stats_copy_app(d, &st, sizeof(st));
}

__attribute__((used)) static void choke_destroy(struct Qdisc *sch)
{
	struct choke_sched_data *q = qdisc_priv(sch);

	choke_free(q->tab);
}

__attribute__((used)) static struct sk_buff *choke_peek_head(struct Qdisc *sch)
{
	struct choke_sched_data *q = qdisc_priv(sch);

	return (q->head != q->tail) ? q->tab[q->head] : NULL;
}


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
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct flowidn {int daddr; int saddr; } ;
struct TYPE_2__ {struct flowidn dn; } ;
struct flowi {TYPE_1__ u; } ;
struct fib_rules_ops {int dummy; } ;
struct fib_rule_hdr {scalar_t__ src_len; scalar_t__ dst_len; scalar_t__ tos; } ;
struct fib_rule {int action; scalar_t__ table; } ;
struct fib_lookup_arg {struct dn_fib_res* result; int /*<<< orphan*/ * rule; } ;
struct dn_fib_table {int (* lookup ) (struct dn_fib_table*,struct flowidn*,struct dn_fib_res*) ;scalar_t__ n; } ;
struct dn_fib_rule {int src; int srcmask; int dst; int dstmask; scalar_t__ src_len; scalar_t__ dst_len; } ;
struct dn_fib_res {unsigned int type; int /*<<< orphan*/ * r; } ;
typedef  int __le16 ;

/* Variables and functions */
 int EACCES ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENETUNREACH ; 
 int ENOBUFS ; 
 size_t FRA_DST ; 
 size_t FRA_SRC ; 
#define  FR_ACT_BLACKHOLE 131 
#define  FR_ACT_PROHIBIT 130 
#define  FR_ACT_TO_TBL 129 
#define  FR_ACT_UNREACHABLE 128 
 int /*<<< orphan*/  NL_SET_ERR_MSG (struct netlink_ext_ack*,char*) ; 
 unsigned int RTN_UNICAST ; 
 scalar_t__ RT_TABLE_LOCAL ; 
 scalar_t__ RT_TABLE_UNSPEC ; 
 struct dn_fib_table* dn_fib_empty_table () ; 
 struct dn_fib_table* dn_fib_get_table (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dn_fib_res_put (struct dn_fib_res*) ; 
 int /*<<< orphan*/  dn_fib_rules_ops ; 
 int /*<<< orphan*/  dn_rt_cache_flush (int) ; 
 void* dnet_make_mask (scalar_t__) ; 
 int fib_rules_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct fib_lookup_arg*) ; 
 int /*<<< orphan*/  flowidn_to_flowi (struct flowidn*) ; 
 scalar_t__ nla_get_le16 (struct nlattr*) ; 
 scalar_t__ nla_put_le16 (struct sk_buff*,size_t,scalar_t__) ; 
 int stub1 (struct dn_fib_table*,struct flowidn*,struct dn_fib_res*) ; 
 int stub2 (struct dn_fib_table*,struct flowidn*,struct dn_fib_res*) ; 

int dn_fib_lookup(struct flowidn *flp, struct dn_fib_res *res)
{
	struct fib_lookup_arg arg = {
		.result = res,
	};
	int err;

	err = fib_rules_lookup(dn_fib_rules_ops,
			       flowidn_to_flowi(flp), 0, &arg);
	res->r = arg.rule;

	return err;
}

__attribute__((used)) static int dn_fib_rule_action(struct fib_rule *rule, struct flowi *flp,
			      int flags, struct fib_lookup_arg *arg)
{
	struct flowidn *fld = &flp->u.dn;
	int err = -EAGAIN;
	struct dn_fib_table *tbl;

	switch(rule->action) {
	case FR_ACT_TO_TBL:
		break;

	case FR_ACT_UNREACHABLE:
		err = -ENETUNREACH;
		goto errout;

	case FR_ACT_PROHIBIT:
		err = -EACCES;
		goto errout;

	case FR_ACT_BLACKHOLE:
	default:
		err = -EINVAL;
		goto errout;
	}

	tbl = dn_fib_get_table(rule->table, 0);
	if (tbl == NULL)
		goto errout;

	err = tbl->lookup(tbl, fld, (struct dn_fib_res *)arg->result);
	if (err > 0)
		err = -EAGAIN;
errout:
	return err;
}

__attribute__((used)) static int dn_fib_rule_match(struct fib_rule *rule, struct flowi *fl, int flags)
{
	struct dn_fib_rule *r = (struct dn_fib_rule *)rule;
	struct flowidn *fld = &fl->u.dn;
	__le16 daddr = fld->daddr;
	__le16 saddr = fld->saddr;

	if (((saddr ^ r->src) & r->srcmask) ||
	    ((daddr ^ r->dst) & r->dstmask))
		return 0;

	return 1;
}

__attribute__((used)) static int dn_fib_rule_configure(struct fib_rule *rule, struct sk_buff *skb,
				 struct fib_rule_hdr *frh,
				 struct nlattr **tb,
				 struct netlink_ext_ack *extack)
{
	int err = -EINVAL;
	struct dn_fib_rule *r = (struct dn_fib_rule *)rule;

	if (frh->tos) {
		NL_SET_ERR_MSG(extack, "Invalid tos value");
		goto  errout;
	}

	if (rule->table == RT_TABLE_UNSPEC) {
		if (rule->action == FR_ACT_TO_TBL) {
			struct dn_fib_table *table;

			table = dn_fib_empty_table();
			if (table == NULL) {
				err = -ENOBUFS;
				goto errout;
			}

			rule->table = table->n;
		}
	}

	if (frh->src_len)
		r->src = nla_get_le16(tb[FRA_SRC]);

	if (frh->dst_len)
		r->dst = nla_get_le16(tb[FRA_DST]);

	r->src_len = frh->src_len;
	r->srcmask = dnet_make_mask(r->src_len);
	r->dst_len = frh->dst_len;
	r->dstmask = dnet_make_mask(r->dst_len);
	err = 0;
errout:
	return err;
}

__attribute__((used)) static int dn_fib_rule_compare(struct fib_rule *rule, struct fib_rule_hdr *frh,
			       struct nlattr **tb)
{
	struct dn_fib_rule *r = (struct dn_fib_rule *)rule;

	if (frh->src_len && (r->src_len != frh->src_len))
		return 0;

	if (frh->dst_len && (r->dst_len != frh->dst_len))
		return 0;

	if (frh->src_len && (r->src != nla_get_le16(tb[FRA_SRC])))
		return 0;

	if (frh->dst_len && (r->dst != nla_get_le16(tb[FRA_DST])))
		return 0;

	return 1;
}

unsigned int dnet_addr_type(__le16 addr)
{
	struct flowidn fld = { .daddr = addr };
	struct dn_fib_res res;
	unsigned int ret = RTN_UNICAST;
	struct dn_fib_table *tb = dn_fib_get_table(RT_TABLE_LOCAL, 0);

	res.r = NULL;

	if (tb) {
		if (!tb->lookup(tb, &fld, &res)) {
			ret = res.type;
			dn_fib_res_put(&res);
		}
	}
	return ret;
}

__attribute__((used)) static int dn_fib_rule_fill(struct fib_rule *rule, struct sk_buff *skb,
			    struct fib_rule_hdr *frh)
{
	struct dn_fib_rule *r = (struct dn_fib_rule *)rule;

	frh->dst_len = r->dst_len;
	frh->src_len = r->src_len;
	frh->tos = 0;

	if ((r->dst_len &&
	     nla_put_le16(skb, FRA_DST, r->dst)) ||
	    (r->src_len &&
	     nla_put_le16(skb, FRA_SRC, r->src)))
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -ENOBUFS;
}

__attribute__((used)) static void dn_fib_rule_flush_cache(struct fib_rules_ops *ops)
{
	dn_rt_cache_flush(-1);
}


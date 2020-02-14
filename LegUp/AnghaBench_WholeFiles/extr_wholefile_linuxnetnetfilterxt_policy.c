#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
union nf_inet_addr {int ip; int /*<<< orphan*/  in6; } ;
struct xt_policy_info {int flags; int len; struct xt_policy_elem* pol; } ;
struct TYPE_8__ {int saddr; int daddr; int proto; int mode; int spi; int reqid; } ;
struct TYPE_6__ {int /*<<< orphan*/  reqid; int /*<<< orphan*/  spi; int /*<<< orphan*/  mode; int /*<<< orphan*/  proto; int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; } ;
struct xt_policy_elem {scalar_t__ proto; scalar_t__ mode; scalar_t__ spi; scalar_t__ reqid; TYPE_4__ invert; TYPE_2__ match; union nf_inet_addr dmask; union nf_inet_addr daddr; union nf_inet_addr smask; union nf_inet_addr saddr; } ;
struct xt_mtchk_param {int hook_mask; struct xt_policy_info* matchinfo; } ;
struct xt_action_param {struct xt_policy_info* matchinfo; } ;
struct TYPE_7__ {scalar_t__ mode; scalar_t__ reqid; int /*<<< orphan*/  saddr; } ;
struct TYPE_5__ {scalar_t__ proto; scalar_t__ spi; int /*<<< orphan*/  daddr; } ;
struct xfrm_state {TYPE_3__ props; TYPE_1__ id; } ;
struct xfrm_dst {struct dst_entry* child; } ;
struct sk_buff {struct sec_path* sp; } ;
struct sec_path {int len; struct xfrm_state** xvec; } ;
struct dst_entry {struct xfrm_state* xfrm; } ;

/* Variables and functions */
 int EINVAL ; 
#define  NFPROTO_IPV4 129 
#define  NFPROTO_IPV6 128 
 int NF_INET_LOCAL_IN ; 
 int NF_INET_LOCAL_OUT ; 
 int NF_INET_POST_ROUTING ; 
 int NF_INET_PRE_ROUTING ; 
 int XT_POLICY_MATCH_IN ; 
 int XT_POLICY_MATCH_NONE ; 
 int XT_POLICY_MATCH_OUT ; 
 int XT_POLICY_MATCH_STRICT ; 
 scalar_t__ XT_POLICY_MAX_ELEM ; 
 int /*<<< orphan*/  ipv6_masked_addr_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,char const*) ; 
 struct dst_entry* skb_dst (struct sk_buff const*) ; 
 unsigned short xt_family (struct xt_action_param*) ; 

__attribute__((used)) static inline bool
xt_addr_cmp(const union nf_inet_addr *a1, const union nf_inet_addr *m,
	    const union nf_inet_addr *a2, unsigned short family)
{
	switch (family) {
	case NFPROTO_IPV4:
		return ((a1->ip ^ a2->ip) & m->ip) == 0;
	case NFPROTO_IPV6:
		return ipv6_masked_addr_cmp(&a1->in6, &m->in6, &a2->in6) == 0;
	}
	return false;
}

__attribute__((used)) static bool
match_xfrm_state(const struct xfrm_state *x, const struct xt_policy_elem *e,
		 unsigned short family)
{
#define MATCH_ADDR(x,y,z)	(!e->match.x ||			       \
				 (xt_addr_cmp(&e->x, &e->y, (const union nf_inet_addr *)(z), family) \
				  ^ e->invert.x))
#define MATCH(x,y)		(!e->match.x || ((e->x == (y)) ^ e->invert.x))

	return MATCH_ADDR(saddr, smask, &x->props.saddr) &&
	       MATCH_ADDR(daddr, dmask, &x->id.daddr) &&
	       MATCH(proto, x->id.proto) &&
	       MATCH(mode, x->props.mode) &&
	       MATCH(spi, x->id.spi) &&
	       MATCH(reqid, x->props.reqid);
}

__attribute__((used)) static int
match_policy_in(const struct sk_buff *skb, const struct xt_policy_info *info,
		unsigned short family)
{
	const struct xt_policy_elem *e;
	const struct sec_path *sp = skb->sp;
	int strict = info->flags & XT_POLICY_MATCH_STRICT;
	int i, pos;

	if (sp == NULL)
		return -1;
	if (strict && info->len != sp->len)
		return 0;

	for (i = sp->len - 1; i >= 0; i--) {
		pos = strict ? i - sp->len + 1 : 0;
		if (pos >= info->len)
			return 0;
		e = &info->pol[pos];

		if (match_xfrm_state(sp->xvec[i], e, family)) {
			if (!strict)
				return 1;
		} else if (strict)
			return 0;
	}

	return strict ? 1 : 0;
}

__attribute__((used)) static int
match_policy_out(const struct sk_buff *skb, const struct xt_policy_info *info,
		 unsigned short family)
{
	const struct xt_policy_elem *e;
	const struct dst_entry *dst = skb_dst(skb);
	int strict = info->flags & XT_POLICY_MATCH_STRICT;
	int i, pos;

	if (dst->xfrm == NULL)
		return -1;

	for (i = 0; dst && dst->xfrm;
	     dst = ((struct xfrm_dst *)dst)->child, i++) {
		pos = strict ? i : 0;
		if (pos >= info->len)
			return 0;
		e = &info->pol[pos];

		if (match_xfrm_state(dst->xfrm, e, family)) {
			if (!strict)
				return 1;
		} else if (strict)
			return 0;
	}

	return strict ? i == info->len : 0;
}

__attribute__((used)) static bool
policy_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_policy_info *info = par->matchinfo;
	int ret;

	if (info->flags & XT_POLICY_MATCH_IN)
		ret = match_policy_in(skb, info, xt_family(par));
	else
		ret = match_policy_out(skb, info, xt_family(par));

	if (ret < 0)
		ret = info->flags & XT_POLICY_MATCH_NONE ? true : false;
	else if (info->flags & XT_POLICY_MATCH_NONE)
		ret = false;

	return ret;
}

__attribute__((used)) static int policy_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_policy_info *info = par->matchinfo;
	const char *errmsg = "neither incoming nor outgoing policy selected";

	if (!(info->flags & (XT_POLICY_MATCH_IN|XT_POLICY_MATCH_OUT)))
		goto err;

	if (par->hook_mask & ((1 << NF_INET_PRE_ROUTING) |
	    (1 << NF_INET_LOCAL_IN)) && info->flags & XT_POLICY_MATCH_OUT) {
		errmsg = "output policy not valid in PREROUTING and INPUT";
		goto err;
	}
	if (par->hook_mask & ((1 << NF_INET_POST_ROUTING) |
	    (1 << NF_INET_LOCAL_OUT)) && info->flags & XT_POLICY_MATCH_IN) {
		errmsg = "input policy not valid in POSTROUTING and OUTPUT";
		goto err;
	}
	if (info->len > XT_POLICY_MAX_ELEM) {
		errmsg = "too many policy elements";
		goto err;
	}
	return 0;
err:
	pr_info_ratelimited("%s\n", errmsg);
	return -EINVAL;
}


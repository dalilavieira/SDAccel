#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
union nf_inet_addr {int ip; int /*<<< orphan*/  in6; } ;
typedef  unsigned int u_int8_t ;
typedef  scalar_t__ u16 ;
struct xt_mtdtor_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_mtchk_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_conntrack_mtinfo3 {int match_flags; scalar_t__ l4proto; int invert_flags; scalar_t__ origsrc_port; scalar_t__ origdst_port; scalar_t__ replsrc_port; scalar_t__ repldst_port; scalar_t__ origsrc_port_high; scalar_t__ origdst_port_high; scalar_t__ replsrc_port_high; scalar_t__ repldst_port_high; unsigned long expires_min; unsigned long expires_max; scalar_t__ state_mask; scalar_t__ status_mask; union nf_inet_addr repldst_mask; union nf_inet_addr repldst_addr; union nf_inet_addr replsrc_mask; union nf_inet_addr replsrc_addr; union nf_inet_addr origdst_mask; union nf_inet_addr origdst_addr; union nf_inet_addr origsrc_mask; union nf_inet_addr origsrc_addr; } ;
struct xt_conntrack_mtinfo2 {int match_flags; scalar_t__ l4proto; int invert_flags; scalar_t__ origsrc_port; scalar_t__ origdst_port; scalar_t__ replsrc_port; scalar_t__ repldst_port; scalar_t__ origsrc_port_high; scalar_t__ origdst_port_high; scalar_t__ replsrc_port_high; scalar_t__ repldst_port_high; unsigned long expires_min; unsigned long expires_max; scalar_t__ state_mask; scalar_t__ status_mask; union nf_inet_addr repldst_mask; union nf_inet_addr repldst_addr; union nf_inet_addr replsrc_mask; union nf_inet_addr replsrc_addr; union nf_inet_addr origdst_mask; union nf_inet_addr origdst_addr; union nf_inet_addr origsrc_mask; union nf_inet_addr origsrc_addr; } ;
struct xt_conntrack_mtinfo1 {int match_flags; scalar_t__ l4proto; int invert_flags; scalar_t__ origsrc_port; scalar_t__ origdst_port; scalar_t__ replsrc_port; scalar_t__ repldst_port; scalar_t__ origsrc_port_high; scalar_t__ origdst_port_high; scalar_t__ replsrc_port_high; scalar_t__ repldst_port_high; unsigned long expires_min; unsigned long expires_max; scalar_t__ state_mask; scalar_t__ status_mask; union nf_inet_addr repldst_mask; union nf_inet_addr repldst_addr; union nf_inet_addr replsrc_mask; union nf_inet_addr replsrc_addr; union nf_inet_addr origdst_mask; union nf_inet_addr origdst_addr; union nf_inet_addr origsrc_mask; union nf_inet_addr origsrc_addr; } ;
struct xt_action_param {struct xt_conntrack_mtinfo3* matchinfo; TYPE_3__* match; } ;
struct sk_buff {int dummy; } ;
struct TYPE_8__ {scalar_t__ all; } ;
struct TYPE_10__ {TYPE_2__ u; union nf_inet_addr u3; } ;
struct TYPE_7__ {scalar_t__ all; } ;
struct TYPE_11__ {TYPE_1__ u; union nf_inet_addr u3; } ;
struct nf_conntrack_tuple {TYPE_4__ dst; TYPE_5__ src; } ;
struct nf_conn {scalar_t__ status; TYPE_6__* tuplehash; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;
struct TYPE_12__ {struct nf_conntrack_tuple tuple; } ;
struct TYPE_9__ {int revision; } ;

/* Variables and functions */
 size_t CTINFO2DIR (int) ; 
 unsigned long HZ ; 
 int /*<<< orphan*/  IPS_DST_NAT_BIT ; 
 int /*<<< orphan*/  IPS_SRC_NAT_BIT ; 
 size_t IP_CT_DIR_ORIGINAL ; 
 size_t IP_CT_DIR_REPLY ; 
 int IP_CT_UNTRACKED ; 
 unsigned int NFPROTO_IPV4 ; 
 unsigned int NFPROTO_IPV6 ; 
 int XT_CONNTRACK_DIRECTION ; 
 int XT_CONNTRACK_EXPIRES ; 
 int XT_CONNTRACK_ORIGDST ; 
 int XT_CONNTRACK_ORIGDST_PORT ; 
 int XT_CONNTRACK_ORIGSRC ; 
 int XT_CONNTRACK_ORIGSRC_PORT ; 
 int XT_CONNTRACK_PROTO ; 
 int XT_CONNTRACK_REPLDST ; 
 int XT_CONNTRACK_REPLDST_PORT ; 
 int XT_CONNTRACK_REPLSRC ; 
 int XT_CONNTRACK_REPLSRC_PORT ; 
 int XT_CONNTRACK_STATE ; 
 unsigned int XT_CONNTRACK_STATE_BIT (int) ; 
 unsigned int XT_CONNTRACK_STATE_DNAT ; 
 unsigned int XT_CONNTRACK_STATE_INVALID ; 
 unsigned int XT_CONNTRACK_STATE_SNAT ; 
 unsigned int XT_CONNTRACK_STATE_UNTRACKED ; 
 int XT_CONNTRACK_STATUS ; 
 scalar_t__ ipv6_masked_addr_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned long nf_ct_expires (struct nf_conn const*) ; 
 struct nf_conn* nf_ct_get (struct sk_buff const*,int*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ nf_ct_protonum (struct nf_conn const*) ; 
 scalar_t__ ntohs (scalar_t__) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,scalar_t__*) ; 
 unsigned int xt_family (struct xt_action_param*) ; 

__attribute__((used)) static bool
conntrack_addrcmp(const union nf_inet_addr *kaddr,
                  const union nf_inet_addr *uaddr,
                  const union nf_inet_addr *umask, unsigned int l3proto)
{
	if (l3proto == NFPROTO_IPV4)
		return ((kaddr->ip ^ uaddr->ip) & umask->ip) == 0;
	else if (l3proto == NFPROTO_IPV6)
		return ipv6_masked_addr_cmp(&kaddr->in6, &umask->in6,
		       &uaddr->in6) == 0;
	else
		return false;
}

__attribute__((used)) static inline bool
conntrack_mt_origsrc(const struct nf_conn *ct,
                     const struct xt_conntrack_mtinfo2 *info,
		     u_int8_t family)
{
	return conntrack_addrcmp(&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3,
	       &info->origsrc_addr, &info->origsrc_mask, family);
}

__attribute__((used)) static inline bool
conntrack_mt_origdst(const struct nf_conn *ct,
                     const struct xt_conntrack_mtinfo2 *info,
		     u_int8_t family)
{
	return conntrack_addrcmp(&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.dst.u3,
	       &info->origdst_addr, &info->origdst_mask, family);
}

__attribute__((used)) static inline bool
conntrack_mt_replsrc(const struct nf_conn *ct,
                     const struct xt_conntrack_mtinfo2 *info,
		     u_int8_t family)
{
	return conntrack_addrcmp(&ct->tuplehash[IP_CT_DIR_REPLY].tuple.src.u3,
	       &info->replsrc_addr, &info->replsrc_mask, family);
}

__attribute__((used)) static inline bool
conntrack_mt_repldst(const struct nf_conn *ct,
                     const struct xt_conntrack_mtinfo2 *info,
		     u_int8_t family)
{
	return conntrack_addrcmp(&ct->tuplehash[IP_CT_DIR_REPLY].tuple.dst.u3,
	       &info->repldst_addr, &info->repldst_mask, family);
}

__attribute__((used)) static inline bool
ct_proto_port_check(const struct xt_conntrack_mtinfo2 *info,
                    const struct nf_conn *ct)
{
	const struct nf_conntrack_tuple *tuple;

	tuple = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
	if ((info->match_flags & XT_CONNTRACK_PROTO) &&
	    (nf_ct_protonum(ct) == info->l4proto) ^
	    !(info->invert_flags & XT_CONNTRACK_PROTO))
		return false;

	/* Shortcut to match all recognized protocols by using ->src.all. */
	if ((info->match_flags & XT_CONNTRACK_ORIGSRC_PORT) &&
	    (tuple->src.u.all == info->origsrc_port) ^
	    !(info->invert_flags & XT_CONNTRACK_ORIGSRC_PORT))
		return false;

	if ((info->match_flags & XT_CONNTRACK_ORIGDST_PORT) &&
	    (tuple->dst.u.all == info->origdst_port) ^
	    !(info->invert_flags & XT_CONNTRACK_ORIGDST_PORT))
		return false;

	tuple = &ct->tuplehash[IP_CT_DIR_REPLY].tuple;

	if ((info->match_flags & XT_CONNTRACK_REPLSRC_PORT) &&
	    (tuple->src.u.all == info->replsrc_port) ^
	    !(info->invert_flags & XT_CONNTRACK_REPLSRC_PORT))
		return false;

	if ((info->match_flags & XT_CONNTRACK_REPLDST_PORT) &&
	    (tuple->dst.u.all == info->repldst_port) ^
	    !(info->invert_flags & XT_CONNTRACK_REPLDST_PORT))
		return false;

	return true;
}

__attribute__((used)) static inline bool
port_match(u16 min, u16 max, u16 port, bool invert)
{
	return (port >= min && port <= max) ^ invert;
}

__attribute__((used)) static inline bool
ct_proto_port_check_v3(const struct xt_conntrack_mtinfo3 *info,
		       const struct nf_conn *ct)
{
	const struct nf_conntrack_tuple *tuple;

	tuple = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
	if ((info->match_flags & XT_CONNTRACK_PROTO) &&
	    (nf_ct_protonum(ct) == info->l4proto) ^
	    !(info->invert_flags & XT_CONNTRACK_PROTO))
		return false;

	/* Shortcut to match all recognized protocols by using ->src.all. */
	if ((info->match_flags & XT_CONNTRACK_ORIGSRC_PORT) &&
	    !port_match(info->origsrc_port, info->origsrc_port_high,
			ntohs(tuple->src.u.all),
			info->invert_flags & XT_CONNTRACK_ORIGSRC_PORT))
		return false;

	if ((info->match_flags & XT_CONNTRACK_ORIGDST_PORT) &&
	    !port_match(info->origdst_port, info->origdst_port_high,
			ntohs(tuple->dst.u.all),
			info->invert_flags & XT_CONNTRACK_ORIGDST_PORT))
		return false;

	tuple = &ct->tuplehash[IP_CT_DIR_REPLY].tuple;

	if ((info->match_flags & XT_CONNTRACK_REPLSRC_PORT) &&
	    !port_match(info->replsrc_port, info->replsrc_port_high,
			ntohs(tuple->src.u.all),
			info->invert_flags & XT_CONNTRACK_REPLSRC_PORT))
		return false;

	if ((info->match_flags & XT_CONNTRACK_REPLDST_PORT) &&
	    !port_match(info->repldst_port, info->repldst_port_high,
			ntohs(tuple->dst.u.all),
			info->invert_flags & XT_CONNTRACK_REPLDST_PORT))
		return false;

	return true;
}

__attribute__((used)) static bool
conntrack_mt(const struct sk_buff *skb, struct xt_action_param *par,
             u16 state_mask, u16 status_mask)
{
	const struct xt_conntrack_mtinfo2 *info = par->matchinfo;
	enum ip_conntrack_info ctinfo;
	const struct nf_conn *ct;
	unsigned int statebit;

	ct = nf_ct_get(skb, &ctinfo);

	if (ct)
		statebit = XT_CONNTRACK_STATE_BIT(ctinfo);
	else if (ctinfo == IP_CT_UNTRACKED)
		statebit = XT_CONNTRACK_STATE_UNTRACKED;
	else
		statebit = XT_CONNTRACK_STATE_INVALID;

	if (info->match_flags & XT_CONNTRACK_STATE) {
		if (ct != NULL) {
			if (test_bit(IPS_SRC_NAT_BIT, &ct->status))
				statebit |= XT_CONNTRACK_STATE_SNAT;
			if (test_bit(IPS_DST_NAT_BIT, &ct->status))
				statebit |= XT_CONNTRACK_STATE_DNAT;
		}
		if (!!(state_mask & statebit) ^
		    !(info->invert_flags & XT_CONNTRACK_STATE))
			return false;
	}

	if (ct == NULL)
		return info->match_flags & XT_CONNTRACK_STATE;
	if ((info->match_flags & XT_CONNTRACK_DIRECTION) &&
	    (CTINFO2DIR(ctinfo) == IP_CT_DIR_ORIGINAL) ^
	    !(info->invert_flags & XT_CONNTRACK_DIRECTION))
		return false;

	if (info->match_flags & XT_CONNTRACK_ORIGSRC)
		if (conntrack_mt_origsrc(ct, info, xt_family(par)) ^
		    !(info->invert_flags & XT_CONNTRACK_ORIGSRC))
			return false;

	if (info->match_flags & XT_CONNTRACK_ORIGDST)
		if (conntrack_mt_origdst(ct, info, xt_family(par)) ^
		    !(info->invert_flags & XT_CONNTRACK_ORIGDST))
			return false;

	if (info->match_flags & XT_CONNTRACK_REPLSRC)
		if (conntrack_mt_replsrc(ct, info, xt_family(par)) ^
		    !(info->invert_flags & XT_CONNTRACK_REPLSRC))
			return false;

	if (info->match_flags & XT_CONNTRACK_REPLDST)
		if (conntrack_mt_repldst(ct, info, xt_family(par)) ^
		    !(info->invert_flags & XT_CONNTRACK_REPLDST))
			return false;

	if (par->match->revision != 3) {
		if (!ct_proto_port_check(info, ct))
			return false;
	} else {
		if (!ct_proto_port_check_v3(par->matchinfo, ct))
			return false;
	}

	if ((info->match_flags & XT_CONNTRACK_STATUS) &&
	    (!!(status_mask & ct->status) ^
	    !(info->invert_flags & XT_CONNTRACK_STATUS)))
		return false;

	if (info->match_flags & XT_CONNTRACK_EXPIRES) {
		unsigned long expires = nf_ct_expires(ct) / HZ;

		if ((expires >= info->expires_min &&
		    expires <= info->expires_max) ^
		    !(info->invert_flags & XT_CONNTRACK_EXPIRES))
			return false;
	}
	return true;
}

__attribute__((used)) static bool
conntrack_mt_v1(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_conntrack_mtinfo1 *info = par->matchinfo;

	return conntrack_mt(skb, par, info->state_mask, info->status_mask);
}

__attribute__((used)) static bool
conntrack_mt_v2(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_conntrack_mtinfo2 *info = par->matchinfo;

	return conntrack_mt(skb, par, info->state_mask, info->status_mask);
}

__attribute__((used)) static bool
conntrack_mt_v3(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_conntrack_mtinfo3 *info = par->matchinfo;

	return conntrack_mt(skb, par, info->state_mask, info->status_mask);
}

__attribute__((used)) static int conntrack_mt_check(const struct xt_mtchk_param *par)
{
	int ret;

	ret = nf_ct_netns_get(par->net, par->family);
	if (ret < 0)
		pr_info_ratelimited("cannot load conntrack support for proto=%u\n",
				    par->family);
	return ret;
}

__attribute__((used)) static void conntrack_mt_destroy(const struct xt_mtdtor_param *par)
{
	nf_ct_netns_put(par->net, par->family);
}


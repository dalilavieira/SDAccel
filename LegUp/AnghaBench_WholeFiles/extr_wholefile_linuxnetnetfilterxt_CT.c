#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zone ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct xt_tgdtor_param {scalar_t__ family; struct xt_ct_target_info_v1* targinfo; TYPE_4__* net; } ;
struct xt_tgchk_param {scalar_t__ family; TYPE_4__* net; struct xt_ct_target_info_v1* targinfo; struct ipt_entry* entryinfo; } ;
struct xt_ct_target_info_v1 {int flags; char* helper; char* timeout; struct nf_conn* ct; int /*<<< orphan*/  exp_events; int /*<<< orphan*/  ct_events; scalar_t__ zone; } ;
struct xt_ct_target_info {int flags; char* helper; char* timeout; struct nf_conn* ct; int /*<<< orphan*/  exp_events; int /*<<< orphan*/  ct_events; scalar_t__ zone; } ;
struct xt_action_param {struct xt_ct_target_info_v1* targinfo; } ;
struct sk_buff {scalar_t__ _nfct; } ;
struct nf_conntrack_zone {int /*<<< orphan*/  flags; int /*<<< orphan*/  dir; scalar_t__ id; } ;
struct nf_conntrack_helper {int dummy; } ;
struct nf_conn_help {struct nf_conntrack_helper* helper; } ;
struct TYPE_12__ {int /*<<< orphan*/  use; } ;
struct nf_conn {TYPE_7__ ct_general; int /*<<< orphan*/  status; } ;
struct TYPE_10__ {int invflags; int /*<<< orphan*/  proto; } ;
struct TYPE_9__ {int invflags; int /*<<< orphan*/  proto; } ;
struct ipt_entry {TYPE_3__ ipv6; TYPE_2__ ip; } ;
struct ip6t_entry {TYPE_3__ ipv6; TYPE_2__ ip; } ;
struct TYPE_8__ {int notrack_deprecated_warning; } ;
struct TYPE_11__ {TYPE_1__ xt; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENAMETOOLONG ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IP6T_INV_PROTO ; 
 int /*<<< orphan*/  IPS_CONFIRMED_BIT ; 
 int IPT_INV_PROTO ; 
 int /*<<< orphan*/  IP_CT_NEW ; 
 int /*<<< orphan*/  IP_CT_UNTRACKED ; 
 scalar_t__ NFPROTO_IPV4 ; 
 scalar_t__ NFPROTO_IPV6 ; 
 int /*<<< orphan*/  NF_CT_DEFAULT_ZONE_DIR ; 
 int /*<<< orphan*/  NF_CT_FLAG_MARK ; 
 int /*<<< orphan*/  NF_CT_ZONE_DIR_ORIG ; 
 int /*<<< orphan*/  NF_CT_ZONE_DIR_REPL ; 
 int XT_CONTINUE ; 
 int XT_CT_MASK ; 
 int XT_CT_NOTRACK ; 
#define  XT_CT_ZONE_DIR_ORIG 129 
#define  XT_CT_ZONE_DIR_REPL 128 
 int XT_CT_ZONE_MARK ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  memset (struct nf_conntrack_zone*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nf_conntrack_get (TYPE_7__*) ; 
 int /*<<< orphan*/  nf_conntrack_helper_put (struct nf_conntrack_helper*) ; 
 struct nf_conntrack_helper* nf_conntrack_helper_try_module_get (char const*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_ecache_ext_add (struct nf_conn*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nf_conn_help* nf_ct_helper_ext_add (struct nf_conn*,int /*<<< orphan*/ ) ; 
 int nf_ct_netns_get (TYPE_4__*,scalar_t__) ; 
 int /*<<< orphan*/  nf_ct_netns_put (TYPE_4__*,scalar_t__) ; 
 int /*<<< orphan*/  nf_ct_put (struct nf_conn*) ; 
 int /*<<< orphan*/  nf_ct_set (struct sk_buff*,struct nf_conn*,int /*<<< orphan*/ ) ; 
 struct nf_conn* nf_ct_tmpl_alloc (TYPE_4__*,struct nf_conntrack_zone*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_tmpl_free (struct nf_conn*) ; 
 struct nf_conn_help* nfct_help (struct nf_conn*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,...) ; 
 int strnlen (char*,int) ; 

__attribute__((used)) static inline int xt_ct_target(struct sk_buff *skb, struct nf_conn *ct)
{
	/* Previously seen (loopback)? Ignore. */
	if (skb->_nfct != 0)
		return XT_CONTINUE;

	if (ct) {
		atomic_inc(&ct->ct_general.use);
		nf_ct_set(skb, ct, IP_CT_NEW);
	} else {
		nf_ct_set(skb, ct, IP_CT_UNTRACKED);
	}

	return XT_CONTINUE;
}

__attribute__((used)) static unsigned int xt_ct_target_v0(struct sk_buff *skb,
				    const struct xt_action_param *par)
{
	const struct xt_ct_target_info *info = par->targinfo;
	struct nf_conn *ct = info->ct;

	return xt_ct_target(skb, ct);
}

__attribute__((used)) static unsigned int xt_ct_target_v1(struct sk_buff *skb,
				    const struct xt_action_param *par)
{
	const struct xt_ct_target_info_v1 *info = par->targinfo;
	struct nf_conn *ct = info->ct;

	return xt_ct_target(skb, ct);
}

__attribute__((used)) static u8 xt_ct_find_proto(const struct xt_tgchk_param *par)
{
	if (par->family == NFPROTO_IPV4) {
		const struct ipt_entry *e = par->entryinfo;

		if (e->ip.invflags & IPT_INV_PROTO)
			return 0;
		return e->ip.proto;
	} else if (par->family == NFPROTO_IPV6) {
		const struct ip6t_entry *e = par->entryinfo;

		if (e->ipv6.invflags & IP6T_INV_PROTO)
			return 0;
		return e->ipv6.proto;
	} else
		return 0;
}

__attribute__((used)) static int
xt_ct_set_helper(struct nf_conn *ct, const char *helper_name,
		 const struct xt_tgchk_param *par)
{
	struct nf_conntrack_helper *helper;
	struct nf_conn_help *help;
	u8 proto;

	proto = xt_ct_find_proto(par);
	if (!proto) {
		pr_info_ratelimited("You must specify a L4 protocol and not use inversions on it\n");
		return -ENOENT;
	}

	helper = nf_conntrack_helper_try_module_get(helper_name, par->family,
						    proto);
	if (helper == NULL) {
		pr_info_ratelimited("No such helper \"%s\"\n", helper_name);
		return -ENOENT;
	}

	help = nf_ct_helper_ext_add(ct, GFP_KERNEL);
	if (help == NULL) {
		nf_conntrack_helper_put(helper);
		return -ENOMEM;
	}

	help->helper = helper;
	return 0;
}

__attribute__((used)) static int
xt_ct_set_timeout(struct nf_conn *ct, const struct xt_tgchk_param *par,
		  const char *timeout_name)
{
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
	typeof(nf_ct_timeout_find_get_hook) timeout_find_get;
	const struct nf_conntrack_l4proto *l4proto;
	struct nf_ct_timeout *timeout;
	struct nf_conn_timeout *timeout_ext;
	const char *errmsg = NULL;
	int ret = 0;
	u8 proto;

	rcu_read_lock();
	timeout_find_get = rcu_dereference(nf_ct_timeout_find_get_hook);
	if (timeout_find_get == NULL) {
		ret = -ENOENT;
		errmsg = "Timeout policy base is empty";
		goto out;
	}

	proto = xt_ct_find_proto(par);
	if (!proto) {
		ret = -EINVAL;
		errmsg = "You must specify a L4 protocol and not use inversions on it";
		goto out;
	}

	timeout = timeout_find_get(par->net, timeout_name);
	if (timeout == NULL) {
		ret = -ENOENT;
		pr_info_ratelimited("No such timeout policy \"%s\"\n",
				    timeout_name);
		goto out;
	}

	if (timeout->l3num != par->family) {
		ret = -EINVAL;
		pr_info_ratelimited("Timeout policy `%s' can only be used by L%d protocol number %d\n",
				    timeout_name, 3, timeout->l3num);
		goto err_put_timeout;
	}
	/* Make sure the timeout policy matches any existing protocol tracker,
	 * otherwise default to generic.
	 */
	l4proto = __nf_ct_l4proto_find(par->family, proto);
	if (timeout->l4proto->l4proto != l4proto->l4proto) {
		ret = -EINVAL;
		pr_info_ratelimited("Timeout policy `%s' can only be used by L%d protocol number %d\n",
				    timeout_name, 4, timeout->l4proto->l4proto);
		goto err_put_timeout;
	}
	timeout_ext = nf_ct_timeout_ext_add(ct, timeout, GFP_ATOMIC);
	if (!timeout_ext) {
		ret = -ENOMEM;
		goto err_put_timeout;
	}

	rcu_read_unlock();
	return ret;

err_put_timeout:
	__xt_ct_tg_timeout_put(timeout);
out:
	rcu_read_unlock();
	if (errmsg)
		pr_info_ratelimited("%s\n", errmsg);
	return ret;
#else
	return -EOPNOTSUPP;
#endif
}

__attribute__((used)) static u16 xt_ct_flags_to_dir(const struct xt_ct_target_info_v1 *info)
{
	switch (info->flags & (XT_CT_ZONE_DIR_ORIG |
			       XT_CT_ZONE_DIR_REPL)) {
	case XT_CT_ZONE_DIR_ORIG:
		return NF_CT_ZONE_DIR_ORIG;
	case XT_CT_ZONE_DIR_REPL:
		return NF_CT_ZONE_DIR_REPL;
	default:
		return NF_CT_DEFAULT_ZONE_DIR;
	}
}

__attribute__((used)) static int xt_ct_tg_check(const struct xt_tgchk_param *par,
			  struct xt_ct_target_info_v1 *info)
{
	struct nf_conntrack_zone zone;
	struct nf_conn_help *help;
	struct nf_conn *ct;
	int ret = -EOPNOTSUPP;

	if (info->flags & XT_CT_NOTRACK) {
		ct = NULL;
		goto out;
	}

#ifndef CONFIG_NF_CONNTRACK_ZONES
	if (info->zone || info->flags & (XT_CT_ZONE_DIR_ORIG |
					 XT_CT_ZONE_DIR_REPL |
					 XT_CT_ZONE_MARK))
		goto err1;
#endif

	ret = nf_ct_netns_get(par->net, par->family);
	if (ret < 0)
		goto err1;

	memset(&zone, 0, sizeof(zone));
	zone.id = info->zone;
	zone.dir = xt_ct_flags_to_dir(info);
	if (info->flags & XT_CT_ZONE_MARK)
		zone.flags |= NF_CT_FLAG_MARK;

	ct = nf_ct_tmpl_alloc(par->net, &zone, GFP_KERNEL);
	if (!ct) {
		ret = -ENOMEM;
		goto err2;
	}

	ret = 0;
	if ((info->ct_events || info->exp_events) &&
	    !nf_ct_ecache_ext_add(ct, info->ct_events, info->exp_events,
				  GFP_KERNEL)) {
		ret = -EINVAL;
		goto err3;
	}

	if (info->helper[0]) {
		if (strnlen(info->helper, sizeof(info->helper)) == sizeof(info->helper)) {
			ret = -ENAMETOOLONG;
			goto err3;
		}

		ret = xt_ct_set_helper(ct, info->helper, par);
		if (ret < 0)
			goto err3;
	}

	if (info->timeout[0]) {
		if (strnlen(info->timeout, sizeof(info->timeout)) == sizeof(info->timeout)) {
			ret = -ENAMETOOLONG;
			goto err4;
		}

		ret = xt_ct_set_timeout(ct, par, info->timeout);
		if (ret < 0)
			goto err4;
	}
	__set_bit(IPS_CONFIRMED_BIT, &ct->status);
	nf_conntrack_get(&ct->ct_general);
out:
	info->ct = ct;
	return 0;

err4:
	help = nfct_help(ct);
	if (help)
		nf_conntrack_helper_put(help->helper);
err3:
	nf_ct_tmpl_free(ct);
err2:
	nf_ct_netns_put(par->net, par->family);
err1:
	return ret;
}

__attribute__((used)) static int xt_ct_tg_check_v0(const struct xt_tgchk_param *par)
{
	struct xt_ct_target_info *info = par->targinfo;
	struct xt_ct_target_info_v1 info_v1 = {
		.flags 		= info->flags,
		.zone		= info->zone,
		.ct_events	= info->ct_events,
		.exp_events	= info->exp_events,
	};
	int ret;

	if (info->flags & ~XT_CT_NOTRACK)
		return -EINVAL;

	memcpy(info_v1.helper, info->helper, sizeof(info->helper));

	ret = xt_ct_tg_check(par, &info_v1);
	if (ret < 0)
		return ret;

	info->ct = info_v1.ct;

	return ret;
}

__attribute__((used)) static int xt_ct_tg_check_v1(const struct xt_tgchk_param *par)
{
	struct xt_ct_target_info_v1 *info = par->targinfo;

	if (info->flags & ~XT_CT_NOTRACK)
		return -EINVAL;

	return xt_ct_tg_check(par, par->targinfo);
}

__attribute__((used)) static int xt_ct_tg_check_v2(const struct xt_tgchk_param *par)
{
	struct xt_ct_target_info_v1 *info = par->targinfo;

	if (info->flags & ~XT_CT_MASK)
		return -EINVAL;

	return xt_ct_tg_check(par, par->targinfo);
}

__attribute__((used)) static void xt_ct_destroy_timeout(struct nf_conn *ct)
{
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
	struct nf_conn_timeout *timeout_ext;
	typeof(nf_ct_timeout_put_hook) timeout_put;

	rcu_read_lock();
	timeout_put = rcu_dereference(nf_ct_timeout_put_hook);

	if (timeout_put) {
		timeout_ext = nf_ct_timeout_find(ct);
		if (timeout_ext) {
			timeout_put(timeout_ext->timeout);
			RCU_INIT_POINTER(timeout_ext->timeout, NULL);
		}
	}
	rcu_read_unlock();
#endif
}

__attribute__((used)) static void xt_ct_tg_destroy(const struct xt_tgdtor_param *par,
			     struct xt_ct_target_info_v1 *info)
{
	struct nf_conn *ct = info->ct;
	struct nf_conn_help *help;

	if (ct) {
		help = nfct_help(ct);
		if (help)
			nf_conntrack_helper_put(help->helper);

		nf_ct_netns_put(par->net, par->family);

		xt_ct_destroy_timeout(ct);
		nf_ct_put(info->ct);
	}
}

__attribute__((used)) static void xt_ct_tg_destroy_v0(const struct xt_tgdtor_param *par)
{
	struct xt_ct_target_info *info = par->targinfo;
	struct xt_ct_target_info_v1 info_v1 = {
		.flags 		= info->flags,
		.zone		= info->zone,
		.ct_events	= info->ct_events,
		.exp_events	= info->exp_events,
		.ct		= info->ct,
	};
	memcpy(info_v1.helper, info->helper, sizeof(info->helper));

	xt_ct_tg_destroy(par, &info_v1);
}

__attribute__((used)) static void xt_ct_tg_destroy_v1(const struct xt_tgdtor_param *par)
{
	xt_ct_tg_destroy(par, par->targinfo);
}

__attribute__((used)) static unsigned int
notrack_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	/* Previously seen (loopback)? Ignore. */
	if (skb->_nfct != 0)
		return XT_CONTINUE;

	nf_ct_set(skb, NULL, IP_CT_UNTRACKED);

	return XT_CONTINUE;
}

__attribute__((used)) static int notrack_chk(const struct xt_tgchk_param *par)
{
	if (!par->net->xt.notrack_deprecated_warning) {
		pr_info("netfilter: NOTRACK target is deprecated, "
			"use CT instead or upgrade iptables\n");
		par->net->xt.notrack_deprecated_warning = true;
	}
	return 0;
}


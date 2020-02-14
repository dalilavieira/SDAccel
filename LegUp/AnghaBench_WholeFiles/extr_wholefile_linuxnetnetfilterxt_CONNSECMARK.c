#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct xt_tgdtor_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_tgchk_param {int table; int family; int /*<<< orphan*/  net; struct xt_connsecmark_target_info* targinfo; } ;
struct xt_connsecmark_target_info {int mode; } ;
struct xt_action_param {struct xt_connsecmark_target_info* targinfo; } ;
typedef  struct sk_buff {scalar_t__ secmark; } const sk_buff ;
struct nf_conn {scalar_t__ secmark; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
#define  CONNSECMARK_RESTORE 129 
#define  CONNSECMARK_SAVE 128 
 int EINVAL ; 
 int /*<<< orphan*/  IPCT_SECMARK ; 
 unsigned int XT_CONTINUE ; 
 int /*<<< orphan*/  nf_conntrack_event_cache (int /*<<< orphan*/ ,struct nf_conn*) ; 
 void* nf_ct_get (struct sk_buff const*,int*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int) ; 
 scalar_t__ strcmp (int,char*) ; 

__attribute__((used)) static void secmark_save(const struct sk_buff *skb)
{
	if (skb->secmark) {
		struct nf_conn *ct;
		enum ip_conntrack_info ctinfo;

		ct = nf_ct_get(skb, &ctinfo);
		if (ct && !ct->secmark) {
			ct->secmark = skb->secmark;
			nf_conntrack_event_cache(IPCT_SECMARK, ct);
		}
	}
}

__attribute__((used)) static void secmark_restore(struct sk_buff *skb)
{
	if (!skb->secmark) {
		const struct nf_conn *ct;
		enum ip_conntrack_info ctinfo;

		ct = nf_ct_get(skb, &ctinfo);
		if (ct && ct->secmark)
			skb->secmark = ct->secmark;
	}
}

__attribute__((used)) static unsigned int
connsecmark_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_connsecmark_target_info *info = par->targinfo;

	switch (info->mode) {
	case CONNSECMARK_SAVE:
		secmark_save(skb);
		break;

	case CONNSECMARK_RESTORE:
		secmark_restore(skb);
		break;

	default:
		BUG();
	}

	return XT_CONTINUE;
}

__attribute__((used)) static int connsecmark_tg_check(const struct xt_tgchk_param *par)
{
	const struct xt_connsecmark_target_info *info = par->targinfo;
	int ret;

	if (strcmp(par->table, "mangle") != 0 &&
	    strcmp(par->table, "security") != 0) {
		pr_info_ratelimited("only valid in \'mangle\' or \'security\' table, not \'%s\'\n",
				    par->table);
		return -EINVAL;
	}

	switch (info->mode) {
	case CONNSECMARK_SAVE:
	case CONNSECMARK_RESTORE:
		break;

	default:
		pr_info_ratelimited("invalid mode: %hu\n", info->mode);
		return -EINVAL;
	}

	ret = nf_ct_netns_get(par->net, par->family);
	if (ret < 0)
		pr_info_ratelimited("cannot load conntrack support for proto=%u\n",
				    par->family);
	return ret;
}

__attribute__((used)) static void connsecmark_tg_destroy(const struct xt_tgdtor_param *par)
{
	nf_ct_netns_put(par->net, par->family);
}


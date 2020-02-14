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
struct xt_state_info {unsigned int statemask; } ;
struct xt_mtdtor_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_mtchk_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_action_param {struct xt_state_info* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct nf_conn {int dummy; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;

/* Variables and functions */
 int IP_CT_UNTRACKED ; 
 unsigned int XT_STATE_BIT (int) ; 
 unsigned int XT_STATE_INVALID ; 
 unsigned int XT_STATE_UNTRACKED ; 
 struct nf_conn* nf_ct_get (struct sk_buff const*,int*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
state_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_state_info *sinfo = par->matchinfo;
	enum ip_conntrack_info ctinfo;
	unsigned int statebit;
	struct nf_conn *ct = nf_ct_get(skb, &ctinfo);

	if (ct)
		statebit = XT_STATE_BIT(ctinfo);
	else if (ctinfo == IP_CT_UNTRACKED)
		statebit = XT_STATE_UNTRACKED;
	else
		statebit = XT_STATE_INVALID;

	return (sinfo->statemask & statebit);
}

__attribute__((used)) static int state_mt_check(const struct xt_mtchk_param *par)
{
	int ret;

	ret = nf_ct_netns_get(par->net, par->family);
	if (ret < 0)
		pr_info_ratelimited("cannot load conntrack support for proto=%u\n",
				    par->family);
	return ret;
}

__attribute__((used)) static void state_mt_destroy(const struct xt_mtdtor_param *par)
{
	nf_ct_netns_put(par->net, par->family);
}


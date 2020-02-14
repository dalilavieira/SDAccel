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
struct xt_tgdtor_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_tgchk_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; struct nf_nat_range2* targinfo; } ;
struct xt_action_param {int /*<<< orphan*/  targinfo; } ;
struct sk_buff {int dummy; } ;
struct nf_nat_range2 {int flags; int rangesize; TYPE_1__* range; } ;
struct nf_nat_ipv4_multi_range_compat {int flags; int rangesize; TYPE_1__* range; } ;
struct TYPE_2__ {int flags; } ;

/* Variables and functions */
 int EINVAL ; 
 int NF_NAT_RANGE_MAP_IPS ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int nf_nat_redirect_ipv4 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int nf_nat_redirect_ipv6 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  xt_hooknum (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
redirect_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
	return nf_nat_redirect_ipv6(skb, par->targinfo, xt_hooknum(par));
}

__attribute__((used)) static int redirect_tg6_checkentry(const struct xt_tgchk_param *par)
{
	const struct nf_nat_range2 *range = par->targinfo;

	if (range->flags & NF_NAT_RANGE_MAP_IPS)
		return -EINVAL;

	return nf_ct_netns_get(par->net, par->family);
}

__attribute__((used)) static void redirect_tg_destroy(const struct xt_tgdtor_param *par)
{
	nf_ct_netns_put(par->net, par->family);
}

__attribute__((used)) static int redirect_tg4_check(const struct xt_tgchk_param *par)
{
	const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;

	if (mr->range[0].flags & NF_NAT_RANGE_MAP_IPS) {
		pr_debug("bad MAP_IPS.\n");
		return -EINVAL;
	}
	if (mr->rangesize != 1) {
		pr_debug("bad rangesize %u.\n", mr->rangesize);
		return -EINVAL;
	}
	return nf_ct_netns_get(par->net, par->family);
}

__attribute__((used)) static unsigned int
redirect_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
	return nf_nat_redirect_ipv4(skb, par->targinfo, xt_hooknum(par));
}


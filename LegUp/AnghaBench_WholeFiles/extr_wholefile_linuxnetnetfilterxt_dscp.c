#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u_int8_t ;
struct xt_tos_match_info {scalar_t__ dscp; int tos_mask; int tos_value; int /*<<< orphan*/  invert; } ;
struct xt_mtchk_param {struct xt_tos_match_info* matchinfo; } ;
struct xt_dscp_info {scalar_t__ dscp; int tos_mask; int tos_value; int /*<<< orphan*/  invert; } ;
struct xt_action_param {struct xt_tos_match_info* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct TYPE_3__ {int tos; } ;

/* Variables and functions */
 int EDOM ; 
 scalar_t__ NFPROTO_IPV4 ; 
 scalar_t__ XT_DSCP_MAX ; 
 scalar_t__ XT_DSCP_SHIFT ; 
 TYPE_1__* ip_hdr (struct sk_buff const*) ; 
 scalar_t__ ipv4_get_dsfield (TYPE_1__*) ; 
 scalar_t__ ipv6_get_dsfield (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipv6_hdr (struct sk_buff const*) ; 
 scalar_t__ xt_family (struct xt_action_param*) ; 

__attribute__((used)) static bool
dscp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_dscp_info *info = par->matchinfo;
	u_int8_t dscp = ipv4_get_dsfield(ip_hdr(skb)) >> XT_DSCP_SHIFT;

	return (dscp == info->dscp) ^ !!info->invert;
}

__attribute__((used)) static bool
dscp_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_dscp_info *info = par->matchinfo;
	u_int8_t dscp = ipv6_get_dsfield(ipv6_hdr(skb)) >> XT_DSCP_SHIFT;

	return (dscp == info->dscp) ^ !!info->invert;
}

__attribute__((used)) static int dscp_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_dscp_info *info = par->matchinfo;

	if (info->dscp > XT_DSCP_MAX)
		return -EDOM;

	return 0;
}

__attribute__((used)) static bool tos_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_tos_match_info *info = par->matchinfo;

	if (xt_family(par) == NFPROTO_IPV4)
		return ((ip_hdr(skb)->tos & info->tos_mask) ==
		       info->tos_value) ^ !!info->invert;
	else
		return ((ipv6_get_dsfield(ipv6_hdr(skb)) & info->tos_mask) ==
		       info->tos_value) ^ !!info->invert;
}


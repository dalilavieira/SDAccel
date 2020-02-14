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
struct xt_mtchk_param {struct ebt_pkttype_info* matchinfo; } ;
struct xt_action_param {struct ebt_pkttype_info* matchinfo; } ;
struct sk_buff {scalar_t__ pkt_type; } ;
struct ebt_pkttype_info {scalar_t__ pkt_type; int invert; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static bool
ebt_pkttype_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct ebt_pkttype_info *info = par->matchinfo;

	return (skb->pkt_type == info->pkt_type) ^ info->invert;
}

__attribute__((used)) static int ebt_pkttype_mt_check(const struct xt_mtchk_param *par)
{
	const struct ebt_pkttype_info *info = par->matchinfo;

	if (info->invert != 0 && info->invert != 1)
		return -EINVAL;
	/* Allow any pkt_type value */
	return 0;
}


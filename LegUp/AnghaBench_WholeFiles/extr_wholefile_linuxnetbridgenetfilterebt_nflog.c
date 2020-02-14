#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct xt_tgchk_param {struct ebt_nflog_info* targinfo; } ;
struct xt_action_param {struct ebt_nflog_info* targinfo; } ;
struct sk_buff {int dummy; } ;
struct TYPE_3__ {scalar_t__ flags; int /*<<< orphan*/  qthreshold; int /*<<< orphan*/  group; int /*<<< orphan*/  copy_len; } ;
struct TYPE_4__ {TYPE_1__ ulog; } ;
struct nf_loginfo {TYPE_2__ u; int /*<<< orphan*/  type; } ;
struct net {int dummy; } ;
struct ebt_nflog_info {char* prefix; int flags; int /*<<< orphan*/  threshold; int /*<<< orphan*/  group; int /*<<< orphan*/  len; } ;

/* Variables and functions */
 unsigned int EBT_CONTINUE ; 
 int EBT_NFLOG_MASK ; 
 int EBT_NFLOG_PREFIX_SIZE ; 
 int EINVAL ; 
 int /*<<< orphan*/  NF_LOG_TYPE_ULOG ; 
 int /*<<< orphan*/  PF_BRIDGE ; 
 int /*<<< orphan*/  nf_log_packet (struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nf_loginfo*,char*,char*) ; 
 int /*<<< orphan*/  xt_hooknum (struct xt_action_param const*) ; 
 int /*<<< orphan*/  xt_in (struct xt_action_param const*) ; 
 struct net* xt_net (struct xt_action_param const*) ; 
 int /*<<< orphan*/  xt_out (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
ebt_nflog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct ebt_nflog_info *info = par->targinfo;
	struct net *net = xt_net(par);
	struct nf_loginfo li;

	li.type = NF_LOG_TYPE_ULOG;
	li.u.ulog.copy_len = info->len;
	li.u.ulog.group = info->group;
	li.u.ulog.qthreshold = info->threshold;
	li.u.ulog.flags = 0;

	nf_log_packet(net, PF_BRIDGE, xt_hooknum(par), skb, xt_in(par),
		      xt_out(par), &li, "%s", info->prefix);
	return EBT_CONTINUE;
}

__attribute__((used)) static int ebt_nflog_tg_check(const struct xt_tgchk_param *par)
{
	struct ebt_nflog_info *info = par->targinfo;

	if (info->flags & ~EBT_NFLOG_MASK)
		return -EINVAL;
	info->prefix[EBT_NFLOG_PREFIX_SIZE - 1] = '\0';
	return 0;
}


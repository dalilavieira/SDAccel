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
struct xt_tgdtor_param {int /*<<< orphan*/  family; } ;
struct xt_tgchk_param {int /*<<< orphan*/  family; struct xt_nflog_info* targinfo; } ;
struct xt_nflog_info {int flags; char* prefix; int /*<<< orphan*/  threshold; int /*<<< orphan*/  group; int /*<<< orphan*/  len; } ;
struct xt_action_param {struct xt_nflog_info* targinfo; } ;
struct sk_buff {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  flags; int /*<<< orphan*/  qthreshold; int /*<<< orphan*/  group; int /*<<< orphan*/  copy_len; } ;
struct TYPE_4__ {TYPE_1__ ulog; } ;
struct nf_loginfo {TYPE_2__ u; int /*<<< orphan*/  type; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  NF_LOG_F_COPY_LEN ; 
 int /*<<< orphan*/  NF_LOG_TYPE_ULOG ; 
 unsigned int XT_CONTINUE ; 
 int XT_NFLOG_F_COPY_LEN ; 
 int XT_NFLOG_MASK ; 
 int /*<<< orphan*/  nf_log_packet (struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nf_loginfo*,char*,char*) ; 
 int nf_logger_find_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_logger_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xt_family (struct xt_action_param const*) ; 
 int /*<<< orphan*/  xt_hooknum (struct xt_action_param const*) ; 
 int /*<<< orphan*/  xt_in (struct xt_action_param const*) ; 
 struct net* xt_net (struct xt_action_param const*) ; 
 int /*<<< orphan*/  xt_out (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
nflog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_nflog_info *info = par->targinfo;
	struct net *net = xt_net(par);
	struct nf_loginfo li;

	li.type		     = NF_LOG_TYPE_ULOG;
	li.u.ulog.copy_len   = info->len;
	li.u.ulog.group	     = info->group;
	li.u.ulog.qthreshold = info->threshold;
	li.u.ulog.flags	     = 0;

	if (info->flags & XT_NFLOG_F_COPY_LEN)
		li.u.ulog.flags |= NF_LOG_F_COPY_LEN;

	nf_log_packet(net, xt_family(par), xt_hooknum(par), skb, xt_in(par),
		      xt_out(par), &li, "%s", info->prefix);

	return XT_CONTINUE;
}

__attribute__((used)) static int nflog_tg_check(const struct xt_tgchk_param *par)
{
	const struct xt_nflog_info *info = par->targinfo;

	if (info->flags & ~XT_NFLOG_MASK)
		return -EINVAL;
	if (info->prefix[sizeof(info->prefix) - 1] != '\0')
		return -EINVAL;

	return nf_logger_find_get(par->family, NF_LOG_TYPE_ULOG);
}

__attribute__((used)) static void nflog_tg_destroy(const struct xt_tgdtor_param *par)
{
	nf_logger_put(par->family, NF_LOG_TYPE_ULOG);
}


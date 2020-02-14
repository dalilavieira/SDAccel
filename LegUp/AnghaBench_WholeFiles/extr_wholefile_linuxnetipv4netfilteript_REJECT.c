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
struct xt_tgchk_param {struct ipt_entry* entryinfo; struct ipt_reject_info* targinfo; } ;
struct xt_action_param {struct ipt_reject_info* targinfo; } ;
struct sk_buff {int dummy; } ;
struct ipt_reject_info {int with; } ;
struct TYPE_2__ {scalar_t__ proto; int invflags; } ;
struct ipt_entry {TYPE_1__ ip; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  ICMP_HOST_ANO ; 
 int /*<<< orphan*/  ICMP_HOST_UNREACH ; 
 int /*<<< orphan*/  ICMP_NET_ANO ; 
 int /*<<< orphan*/  ICMP_NET_UNREACH ; 
 int /*<<< orphan*/  ICMP_PKT_FILTERED ; 
 int /*<<< orphan*/  ICMP_PORT_UNREACH ; 
 int /*<<< orphan*/  ICMP_PROT_UNREACH ; 
 scalar_t__ IPPROTO_TCP ; 
#define  IPT_ICMP_ADMIN_PROHIBITED 136 
#define  IPT_ICMP_ECHOREPLY 135 
#define  IPT_ICMP_HOST_PROHIBITED 134 
#define  IPT_ICMP_HOST_UNREACHABLE 133 
#define  IPT_ICMP_NET_PROHIBITED 132 
#define  IPT_ICMP_NET_UNREACHABLE 131 
#define  IPT_ICMP_PORT_UNREACHABLE 130 
#define  IPT_ICMP_PROT_UNREACHABLE 129 
#define  IPT_TCP_RESET 128 
 unsigned int NF_DROP ; 
 int XT_INV_PROTO ; 
 int /*<<< orphan*/  nf_send_reset (int /*<<< orphan*/ ,struct sk_buff*,int) ; 
 int /*<<< orphan*/  nf_send_unreach (struct sk_buff*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*) ; 
 int xt_hooknum (struct xt_action_param const*) ; 
 int /*<<< orphan*/  xt_net (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
reject_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct ipt_reject_info *reject = par->targinfo;
	int hook = xt_hooknum(par);

	switch (reject->with) {
	case IPT_ICMP_NET_UNREACHABLE:
		nf_send_unreach(skb, ICMP_NET_UNREACH, hook);
		break;
	case IPT_ICMP_HOST_UNREACHABLE:
		nf_send_unreach(skb, ICMP_HOST_UNREACH, hook);
		break;
	case IPT_ICMP_PROT_UNREACHABLE:
		nf_send_unreach(skb, ICMP_PROT_UNREACH, hook);
		break;
	case IPT_ICMP_PORT_UNREACHABLE:
		nf_send_unreach(skb, ICMP_PORT_UNREACH, hook);
		break;
	case IPT_ICMP_NET_PROHIBITED:
		nf_send_unreach(skb, ICMP_NET_ANO, hook);
		break;
	case IPT_ICMP_HOST_PROHIBITED:
		nf_send_unreach(skb, ICMP_HOST_ANO, hook);
		break;
	case IPT_ICMP_ADMIN_PROHIBITED:
		nf_send_unreach(skb, ICMP_PKT_FILTERED, hook);
		break;
	case IPT_TCP_RESET:
		nf_send_reset(xt_net(par), skb, hook);
	case IPT_ICMP_ECHOREPLY:
		/* Doesn't happen. */
		break;
	}

	return NF_DROP;
}

__attribute__((used)) static int reject_tg_check(const struct xt_tgchk_param *par)
{
	const struct ipt_reject_info *rejinfo = par->targinfo;
	const struct ipt_entry *e = par->entryinfo;

	if (rejinfo->with == IPT_ICMP_ECHOREPLY) {
		pr_info_ratelimited("ECHOREPLY no longer supported.\n");
		return -EINVAL;
	} else if (rejinfo->with == IPT_TCP_RESET) {
		/* Must specify that it's a TCP packet */
		if (e->ip.proto != IPPROTO_TCP ||
		    (e->ip.invflags & XT_INV_PROTO)) {
			pr_info_ratelimited("TCP_RESET invalid for non-tcp\n");
			return -EINVAL;
		}
	}
	return 0;
}


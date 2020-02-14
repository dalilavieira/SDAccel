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
struct xt_tgchk_param {struct ip6t_entry* entryinfo; struct ip6t_reject_info* targinfo; } ;
struct xt_action_param {struct ip6t_reject_info* targinfo; } ;
struct sk_buff {int dummy; } ;
struct net {int dummy; } ;
struct ip6t_reject_info {int with; } ;
struct TYPE_2__ {int flags; scalar_t__ proto; int invflags; } ;
struct ip6t_entry {TYPE_1__ ipv6; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  ICMPV6_ADDR_UNREACH ; 
 int /*<<< orphan*/  ICMPV6_ADM_PROHIBITED ; 
 int /*<<< orphan*/  ICMPV6_NOROUTE ; 
 int /*<<< orphan*/  ICMPV6_NOT_NEIGHBOUR ; 
 int /*<<< orphan*/  ICMPV6_POLICY_FAIL ; 
 int /*<<< orphan*/  ICMPV6_PORT_UNREACH ; 
 int /*<<< orphan*/  ICMPV6_REJECT_ROUTE ; 
 int IP6T_F_PROTO ; 
#define  IP6T_ICMP6_ADDR_UNREACH 136 
#define  IP6T_ICMP6_ADM_PROHIBITED 135 
#define  IP6T_ICMP6_ECHOREPLY 134 
#define  IP6T_ICMP6_NOT_NEIGHBOUR 133 
#define  IP6T_ICMP6_NO_ROUTE 132 
#define  IP6T_ICMP6_POLICY_FAIL 131 
#define  IP6T_ICMP6_PORT_UNREACH 130 
#define  IP6T_ICMP6_REJECT_ROUTE 129 
#define  IP6T_TCP_RESET 128 
 scalar_t__ IPPROTO_TCP ; 
 unsigned int NF_DROP ; 
 int XT_INV_PROTO ; 
 int /*<<< orphan*/  nf_send_reset6 (struct net*,struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_send_unreach6 (struct net*,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*) ; 
 int /*<<< orphan*/  xt_hooknum (struct xt_action_param const*) ; 
 struct net* xt_net (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
reject_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct ip6t_reject_info *reject = par->targinfo;
	struct net *net = xt_net(par);

	switch (reject->with) {
	case IP6T_ICMP6_NO_ROUTE:
		nf_send_unreach6(net, skb, ICMPV6_NOROUTE, xt_hooknum(par));
		break;
	case IP6T_ICMP6_ADM_PROHIBITED:
		nf_send_unreach6(net, skb, ICMPV6_ADM_PROHIBITED,
				 xt_hooknum(par));
		break;
	case IP6T_ICMP6_NOT_NEIGHBOUR:
		nf_send_unreach6(net, skb, ICMPV6_NOT_NEIGHBOUR,
				 xt_hooknum(par));
		break;
	case IP6T_ICMP6_ADDR_UNREACH:
		nf_send_unreach6(net, skb, ICMPV6_ADDR_UNREACH,
				 xt_hooknum(par));
		break;
	case IP6T_ICMP6_PORT_UNREACH:
		nf_send_unreach6(net, skb, ICMPV6_PORT_UNREACH,
				 xt_hooknum(par));
		break;
	case IP6T_ICMP6_ECHOREPLY:
		/* Do nothing */
		break;
	case IP6T_TCP_RESET:
		nf_send_reset6(net, skb, xt_hooknum(par));
		break;
	case IP6T_ICMP6_POLICY_FAIL:
		nf_send_unreach6(net, skb, ICMPV6_POLICY_FAIL, xt_hooknum(par));
		break;
	case IP6T_ICMP6_REJECT_ROUTE:
		nf_send_unreach6(net, skb, ICMPV6_REJECT_ROUTE,
				 xt_hooknum(par));
		break;
	}

	return NF_DROP;
}

__attribute__((used)) static int reject_tg6_check(const struct xt_tgchk_param *par)
{
	const struct ip6t_reject_info *rejinfo = par->targinfo;
	const struct ip6t_entry *e = par->entryinfo;

	if (rejinfo->with == IP6T_ICMP6_ECHOREPLY) {
		pr_info_ratelimited("ECHOREPLY is not supported\n");
		return -EINVAL;
	} else if (rejinfo->with == IP6T_TCP_RESET) {
		/* Must specify that it's a TCP packet */
		if (!(e->ipv6.flags & IP6T_F_PROTO) ||
		    e->ipv6.proto != IPPROTO_TCP ||
		    (e->ipv6.invflags & XT_INV_PROTO)) {
			pr_info_ratelimited("TCP_RESET illegal for non-tcp\n");
			return -EINVAL;
		}
	}
	return 0;
}


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
struct xt_mtchk_param {struct ipt_ip* entryinfo; struct xt_ecn_info* matchinfo; } ;
struct xt_ecn_info {int operation; int invert; int ip_ect; } ;
struct xt_action_param {struct xt_ecn_info* matchinfo; int /*<<< orphan*/  thoff; } ;
struct tcphdr {int ece; int cwr; } ;
struct sk_buff {int dummy; } ;
struct ipt_ip {scalar_t__ proto; int invflags; } ;
struct ip6t_ip6 {scalar_t__ proto; int invflags; } ;
typedef  int /*<<< orphan*/  _tcph ;
struct TYPE_4__ {int tos; } ;
struct TYPE_3__ {int* flow_lbl; } ;

/* Variables and functions */
 int EINVAL ; 
 int IP6T_INV_PROTO ; 
 scalar_t__ IPPROTO_TCP ; 
 int IPT_INV_PROTO ; 
 int XT_ECN_IP_MASK ; 
 int XT_ECN_OP_MATCH_CWR ; 
 int XT_ECN_OP_MATCH_ECE ; 
 int XT_ECN_OP_MATCH_IP ; 
 int XT_ECN_OP_MATCH_MASK ; 
 TYPE_2__* ip_hdr (struct sk_buff const*) ; 
 TYPE_1__* ipv6_hdr (struct sk_buff const*) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*) ; 
 struct tcphdr* skb_header_pointer (struct sk_buff const*,int /*<<< orphan*/ ,int,struct tcphdr*) ; 

__attribute__((used)) static bool match_tcp(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_ecn_info *einfo = par->matchinfo;
	struct tcphdr _tcph;
	const struct tcphdr *th;

	/* In practice, TCP match does this, so can't fail.  But let's
	 * be good citizens.
	 */
	th = skb_header_pointer(skb, par->thoff, sizeof(_tcph), &_tcph);
	if (th == NULL)
		return false;

	if (einfo->operation & XT_ECN_OP_MATCH_ECE) {
		if (einfo->invert & XT_ECN_OP_MATCH_ECE) {
			if (th->ece == 1)
				return false;
		} else {
			if (th->ece == 0)
				return false;
		}
	}

	if (einfo->operation & XT_ECN_OP_MATCH_CWR) {
		if (einfo->invert & XT_ECN_OP_MATCH_CWR) {
			if (th->cwr == 1)
				return false;
		} else {
			if (th->cwr == 0)
				return false;
		}
	}

	return true;
}

__attribute__((used)) static inline bool match_ip(const struct sk_buff *skb,
			    const struct xt_ecn_info *einfo)
{
	return ((ip_hdr(skb)->tos & XT_ECN_IP_MASK) == einfo->ip_ect) ^
	       !!(einfo->invert & XT_ECN_OP_MATCH_IP);
}

__attribute__((used)) static bool ecn_mt4(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_ecn_info *info = par->matchinfo;

	if (info->operation & XT_ECN_OP_MATCH_IP && !match_ip(skb, info))
		return false;

	if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
	    !match_tcp(skb, par))
		return false;

	return true;
}

__attribute__((used)) static int ecn_mt_check4(const struct xt_mtchk_param *par)
{
	const struct xt_ecn_info *info = par->matchinfo;
	const struct ipt_ip *ip = par->entryinfo;

	if (info->operation & XT_ECN_OP_MATCH_MASK)
		return -EINVAL;

	if (info->invert & XT_ECN_OP_MATCH_MASK)
		return -EINVAL;

	if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
	    (ip->proto != IPPROTO_TCP || ip->invflags & IPT_INV_PROTO)) {
		pr_info_ratelimited("cannot match TCP bits for non-tcp packets\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static inline bool match_ipv6(const struct sk_buff *skb,
			      const struct xt_ecn_info *einfo)
{
	return (((ipv6_hdr(skb)->flow_lbl[0] >> 4) & XT_ECN_IP_MASK) ==
	        einfo->ip_ect) ^
	       !!(einfo->invert & XT_ECN_OP_MATCH_IP);
}

__attribute__((used)) static bool ecn_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_ecn_info *info = par->matchinfo;

	if (info->operation & XT_ECN_OP_MATCH_IP && !match_ipv6(skb, info))
		return false;

	if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
	    !match_tcp(skb, par))
		return false;

	return true;
}

__attribute__((used)) static int ecn_mt_check6(const struct xt_mtchk_param *par)
{
	const struct xt_ecn_info *info = par->matchinfo;
	const struct ip6t_ip6 *ip = par->entryinfo;

	if (info->operation & XT_ECN_OP_MATCH_MASK)
		return -EINVAL;

	if (info->invert & XT_ECN_OP_MATCH_MASK)
		return -EINVAL;

	if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
	    (ip->proto != IPPROTO_TCP || ip->invflags & IP6T_INV_PROTO)) {
		pr_info_ratelimited("cannot match TCP bits for non-tcp packets\n");
		return -EINVAL;
	}

	return 0;
}


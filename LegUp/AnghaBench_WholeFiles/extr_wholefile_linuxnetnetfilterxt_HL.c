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
struct xt_tgchk_param {struct ipt_TTL_info* targinfo; } ;
struct xt_action_param {struct ipt_TTL_info* targinfo; } ;
struct sk_buff {int /*<<< orphan*/  len; } ;
struct ipv6hdr {int hop_limit; } ;
struct ipt_TTL_info {int mode; int ttl; int hop_limit; } ;
struct iphdr {int ttl; int /*<<< orphan*/  check; } ;
struct ip6t_HL_info {int mode; int ttl; int hop_limit; } ;

/* Variables and functions */
 int EINVAL ; 
#define  IP6T_HL_DEC 133 
#define  IP6T_HL_INC 132 
 scalar_t__ IP6T_HL_MAXMODE ; 
#define  IP6T_HL_SET 131 
#define  IPT_TTL_DEC 130 
#define  IPT_TTL_INC 129 
 scalar_t__ IPT_TTL_MAXMODE ; 
#define  IPT_TTL_SET 128 
 unsigned int NF_DROP ; 
 unsigned int XT_CONTINUE ; 
 int /*<<< orphan*/  csum_replace2 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 struct ipv6hdr* ipv6_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_make_writable (struct sk_buff*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int
ttl_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	struct iphdr *iph;
	const struct ipt_TTL_info *info = par->targinfo;
	int new_ttl;

	if (!skb_make_writable(skb, skb->len))
		return NF_DROP;

	iph = ip_hdr(skb);

	switch (info->mode) {
	case IPT_TTL_SET:
		new_ttl = info->ttl;
		break;
	case IPT_TTL_INC:
		new_ttl = iph->ttl + info->ttl;
		if (new_ttl > 255)
			new_ttl = 255;
		break;
	case IPT_TTL_DEC:
		new_ttl = iph->ttl - info->ttl;
		if (new_ttl < 0)
			new_ttl = 0;
		break;
	default:
		new_ttl = iph->ttl;
		break;
	}

	if (new_ttl != iph->ttl) {
		csum_replace2(&iph->check, htons(iph->ttl << 8),
					   htons(new_ttl << 8));
		iph->ttl = new_ttl;
	}

	return XT_CONTINUE;
}

__attribute__((used)) static unsigned int
hl_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
	struct ipv6hdr *ip6h;
	const struct ip6t_HL_info *info = par->targinfo;
	int new_hl;

	if (!skb_make_writable(skb, skb->len))
		return NF_DROP;

	ip6h = ipv6_hdr(skb);

	switch (info->mode) {
	case IP6T_HL_SET:
		new_hl = info->hop_limit;
		break;
	case IP6T_HL_INC:
		new_hl = ip6h->hop_limit + info->hop_limit;
		if (new_hl > 255)
			new_hl = 255;
		break;
	case IP6T_HL_DEC:
		new_hl = ip6h->hop_limit - info->hop_limit;
		if (new_hl < 0)
			new_hl = 0;
		break;
	default:
		new_hl = ip6h->hop_limit;
		break;
	}

	ip6h->hop_limit = new_hl;

	return XT_CONTINUE;
}

__attribute__((used)) static int ttl_tg_check(const struct xt_tgchk_param *par)
{
	const struct ipt_TTL_info *info = par->targinfo;

	if (info->mode > IPT_TTL_MAXMODE)
		return -EINVAL;
	if (info->mode != IPT_TTL_SET && info->ttl == 0)
		return -EINVAL;
	return 0;
}

__attribute__((used)) static int hl_tg6_check(const struct xt_tgchk_param *par)
{
	const struct ip6t_HL_info *info = par->targinfo;

	if (info->mode > IP6T_HL_MAXMODE)
		return -EINVAL;
	if (info->mode != IP6T_HL_SET && info->hop_limit == 0)
		return -EINVAL;
	return 0;
}


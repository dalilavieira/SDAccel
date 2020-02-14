#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct xt_tgchk_param {struct ipt_entry* entryinfo; struct ipt_ECN_info* targinfo; } ;
struct xt_action_param {struct ipt_ECN_info* targinfo; } ;
struct tcphdr {scalar_t__ ece; scalar_t__ cwr; int /*<<< orphan*/  check; } ;
struct sk_buff {int dummy; } ;
struct TYPE_6__ {scalar_t__ proto; int invflags; } ;
struct ipt_entry {TYPE_3__ ip; } ;
struct TYPE_4__ {scalar_t__ ece; scalar_t__ cwr; } ;
struct TYPE_5__ {TYPE_1__ tcp; } ;
struct ipt_ECN_info {int ip_ect; int operation; TYPE_2__ proto; } ;
struct iphdr {int tos; scalar_t__ protocol; int /*<<< orphan*/  check; } ;
typedef  int /*<<< orphan*/  _tcph ;
typedef  int __u8 ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IPPROTO_TCP ; 
 int IPT_ECN_IP_MASK ; 
 int IPT_ECN_OP_MASK ; 
 int IPT_ECN_OP_SET_CWR ; 
 int IPT_ECN_OP_SET_ECE ; 
 int IPT_ECN_OP_SET_IP ; 
 unsigned int NF_DROP ; 
 unsigned int XT_CONTINUE ; 
 int XT_INV_PROTO ; 
 int /*<<< orphan*/  csum_replace2 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  inet_proto_csum_replace2 (int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 int ip_hdrlen (struct sk_buff*) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*) ; 
 struct tcphdr* skb_header_pointer (struct sk_buff*,int,int,struct tcphdr*) ; 
 int /*<<< orphan*/  skb_make_writable (struct sk_buff*,int) ; 

__attribute__((used)) static inline bool
set_ect_ip(struct sk_buff *skb, const struct ipt_ECN_info *einfo)
{
	struct iphdr *iph = ip_hdr(skb);

	if ((iph->tos & IPT_ECN_IP_MASK) != (einfo->ip_ect & IPT_ECN_IP_MASK)) {
		__u8 oldtos;
		if (!skb_make_writable(skb, sizeof(struct iphdr)))
			return false;
		iph = ip_hdr(skb);
		oldtos = iph->tos;
		iph->tos &= ~IPT_ECN_IP_MASK;
		iph->tos |= (einfo->ip_ect & IPT_ECN_IP_MASK);
		csum_replace2(&iph->check, htons(oldtos), htons(iph->tos));
	}
	return true;
}

__attribute__((used)) static inline bool
set_ect_tcp(struct sk_buff *skb, const struct ipt_ECN_info *einfo)
{
	struct tcphdr _tcph, *tcph;
	__be16 oldval;

	/* Not enough header? */
	tcph = skb_header_pointer(skb, ip_hdrlen(skb), sizeof(_tcph), &_tcph);
	if (!tcph)
		return false;

	if ((!(einfo->operation & IPT_ECN_OP_SET_ECE) ||
	     tcph->ece == einfo->proto.tcp.ece) &&
	    (!(einfo->operation & IPT_ECN_OP_SET_CWR) ||
	     tcph->cwr == einfo->proto.tcp.cwr))
		return true;

	if (!skb_make_writable(skb, ip_hdrlen(skb) + sizeof(*tcph)))
		return false;
	tcph = (void *)ip_hdr(skb) + ip_hdrlen(skb);

	oldval = ((__be16 *)tcph)[6];
	if (einfo->operation & IPT_ECN_OP_SET_ECE)
		tcph->ece = einfo->proto.tcp.ece;
	if (einfo->operation & IPT_ECN_OP_SET_CWR)
		tcph->cwr = einfo->proto.tcp.cwr;

	inet_proto_csum_replace2(&tcph->check, skb,
				 oldval, ((__be16 *)tcph)[6], false);
	return true;
}

__attribute__((used)) static unsigned int
ecn_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct ipt_ECN_info *einfo = par->targinfo;

	if (einfo->operation & IPT_ECN_OP_SET_IP)
		if (!set_ect_ip(skb, einfo))
			return NF_DROP;

	if (einfo->operation & (IPT_ECN_OP_SET_ECE | IPT_ECN_OP_SET_CWR) &&
	    ip_hdr(skb)->protocol == IPPROTO_TCP)
		if (!set_ect_tcp(skb, einfo))
			return NF_DROP;

	return XT_CONTINUE;
}

__attribute__((used)) static int ecn_tg_check(const struct xt_tgchk_param *par)
{
	const struct ipt_ECN_info *einfo = par->targinfo;
	const struct ipt_entry *e = par->entryinfo;

	if (einfo->operation & IPT_ECN_OP_MASK)
		return -EINVAL;

	if (einfo->ip_ect & ~IPT_ECN_IP_MASK)
		return -EINVAL;

	if ((einfo->operation & (IPT_ECN_OP_SET_ECE|IPT_ECN_OP_SET_CWR)) &&
	    (e->ip.proto != IPPROTO_TCP || (e->ip.invflags & XT_INV_PROTO))) {
		pr_info_ratelimited("cannot use operation on non-tcp rule\n");
		return -EINVAL;
	}
	return 0;
}


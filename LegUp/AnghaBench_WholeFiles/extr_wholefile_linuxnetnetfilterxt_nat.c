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
struct xt_tgchk_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; struct nf_nat_range2 const* targinfo; } ;
struct xt_action_param {struct nf_nat_range2 const* targinfo; } ;
struct sk_buff {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  ip; } ;
typedef  struct nf_nat_range2 {int rangesize; TYPE_1__ base_proto; struct nf_nat_ipv4_range* range; int /*<<< orphan*/  max_proto; int /*<<< orphan*/  min_proto; TYPE_1__ max_addr; TYPE_1__ min_addr; int /*<<< orphan*/  flags; } const nf_nat_range2 ;
typedef  struct nf_nat_range {int rangesize; TYPE_1__ base_proto; struct nf_nat_ipv4_range* range; int /*<<< orphan*/  max_proto; int /*<<< orphan*/  min_proto; TYPE_1__ max_addr; TYPE_1__ min_addr; int /*<<< orphan*/  flags; } const nf_nat_range ;
struct nf_nat_ipv4_range {int /*<<< orphan*/  max; int /*<<< orphan*/  min; int /*<<< orphan*/  max_ip; int /*<<< orphan*/  min_ip; int /*<<< orphan*/  flags; } ;
typedef  struct nf_nat_ipv4_multi_range_compat {int rangesize; TYPE_1__ base_proto; struct nf_nat_ipv4_range* range; int /*<<< orphan*/  max_proto; int /*<<< orphan*/  min_proto; TYPE_1__ max_addr; TYPE_1__ min_addr; int /*<<< orphan*/  flags; } const nf_nat_ipv4_multi_range_compat ;
struct nf_conn {int dummy; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;

/* Variables and functions */
 int EINVAL ; 
 int IP_CT_NEW ; 
 int IP_CT_RELATED ; 
 int IP_CT_RELATED_REPLY ; 
 int /*<<< orphan*/  NF_NAT_MANIP_DST ; 
 int /*<<< orphan*/  NF_NAT_MANIP_SRC ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  memcpy (struct nf_nat_range2 const*,struct nf_nat_range2 const*,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 struct nf_conn* nf_ct_get (struct sk_buff*,int*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int nf_nat_setup_info (struct nf_conn*,struct nf_nat_range2 const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*) ; 

__attribute__((used)) static int xt_nat_checkentry_v0(const struct xt_tgchk_param *par)
{
	const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;

	if (mr->rangesize != 1) {
		pr_info_ratelimited("multiple ranges no longer supported\n");
		return -EINVAL;
	}
	return nf_ct_netns_get(par->net, par->family);
}

__attribute__((used)) static int xt_nat_checkentry(const struct xt_tgchk_param *par)
{
	return nf_ct_netns_get(par->net, par->family);
}

__attribute__((used)) static void xt_nat_destroy(const struct xt_tgdtor_param *par)
{
	nf_ct_netns_put(par->net, par->family);
}

__attribute__((used)) static void xt_nat_convert_range(struct nf_nat_range2 *dst,
				 const struct nf_nat_ipv4_range *src)
{
	memset(&dst->min_addr, 0, sizeof(dst->min_addr));
	memset(&dst->max_addr, 0, sizeof(dst->max_addr));
	memset(&dst->base_proto, 0, sizeof(dst->base_proto));

	dst->flags	 = src->flags;
	dst->min_addr.ip = src->min_ip;
	dst->max_addr.ip = src->max_ip;
	dst->min_proto	 = src->min;
	dst->max_proto	 = src->max;
}

__attribute__((used)) static unsigned int
xt_snat_target_v0(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
	struct nf_nat_range2 range;
	enum ip_conntrack_info ctinfo;
	struct nf_conn *ct;

	ct = nf_ct_get(skb, &ctinfo);
	WARN_ON(!(ct != NULL &&
		 (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
		  ctinfo == IP_CT_RELATED_REPLY)));

	xt_nat_convert_range(&range, &mr->range[0]);
	return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_SRC);
}

__attribute__((used)) static unsigned int
xt_dnat_target_v0(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
	struct nf_nat_range2 range;
	enum ip_conntrack_info ctinfo;
	struct nf_conn *ct;

	ct = nf_ct_get(skb, &ctinfo);
	WARN_ON(!(ct != NULL &&
		 (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED)));

	xt_nat_convert_range(&range, &mr->range[0]);
	return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_DST);
}

__attribute__((used)) static unsigned int
xt_snat_target_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct nf_nat_range *range_v1 = par->targinfo;
	struct nf_nat_range2 range;
	enum ip_conntrack_info ctinfo;
	struct nf_conn *ct;

	ct = nf_ct_get(skb, &ctinfo);
	WARN_ON(!(ct != NULL &&
		 (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
		  ctinfo == IP_CT_RELATED_REPLY)));

	memcpy(&range, range_v1, sizeof(*range_v1));
	memset(&range.base_proto, 0, sizeof(range.base_proto));

	return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_SRC);
}

__attribute__((used)) static unsigned int
xt_dnat_target_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct nf_nat_range *range_v1 = par->targinfo;
	struct nf_nat_range2 range;
	enum ip_conntrack_info ctinfo;
	struct nf_conn *ct;

	ct = nf_ct_get(skb, &ctinfo);
	WARN_ON(!(ct != NULL &&
		 (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED)));

	memcpy(&range, range_v1, sizeof(*range_v1));
	memset(&range.base_proto, 0, sizeof(range.base_proto));

	return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_DST);
}

__attribute__((used)) static unsigned int
xt_snat_target_v2(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct nf_nat_range2 *range = par->targinfo;
	enum ip_conntrack_info ctinfo;
	struct nf_conn *ct;

	ct = nf_ct_get(skb, &ctinfo);
	WARN_ON(!(ct != NULL &&
		 (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
		  ctinfo == IP_CT_RELATED_REPLY)));

	return nf_nat_setup_info(ct, range, NF_NAT_MANIP_SRC);
}

__attribute__((used)) static unsigned int
xt_dnat_target_v2(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct nf_nat_range2 *range = par->targinfo;
	enum ip_conntrack_info ctinfo;
	struct nf_conn *ct;

	ct = nf_ct_get(skb, &ctinfo);
	WARN_ON(!(ct != NULL &&
		 (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED)));

	return nf_nat_setup_info(ct, range, NF_NAT_MANIP_DST);
}


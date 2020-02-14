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
struct xt_mtdtor_param {int const family; int /*<<< orphan*/  net; } ;
struct xt_mtchk_param {int const family; int /*<<< orphan*/  net; struct xt_connlabel_mtinfo* matchinfo; } ;
struct xt_connlabel_mtinfo {int options; int /*<<< orphan*/  bit; } ;
struct xt_action_param {struct xt_connlabel_mtinfo* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct nf_conn_labels {int /*<<< orphan*/  bits; } ;
struct nf_conn {int dummy; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IPCT_LABEL ; 
 int XT_CONNLABEL_OP_INVERT ; 
 int XT_CONNLABEL_OP_SET ; 
 int nf_connlabels_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_connlabels_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_conntrack_event_cache (int /*<<< orphan*/ ,struct nf_conn*) ; 
 struct nf_conn* nf_ct_get (struct sk_buff const*,int*) ; 
 struct nf_conn_labels* nf_ct_labels_find (struct nf_conn*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int const) ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
connlabel_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_connlabel_mtinfo *info = par->matchinfo;
	enum ip_conntrack_info ctinfo;
	struct nf_conn_labels *labels;
	struct nf_conn *ct;
	bool invert = info->options & XT_CONNLABEL_OP_INVERT;

	ct = nf_ct_get(skb, &ctinfo);
	if (ct == NULL)
		return invert;

	labels = nf_ct_labels_find(ct);
	if (!labels)
		return invert;

	if (test_bit(info->bit, labels->bits))
		return !invert;

	if (info->options & XT_CONNLABEL_OP_SET) {
		if (!test_and_set_bit(info->bit, labels->bits))
			nf_conntrack_event_cache(IPCT_LABEL, ct);

		return !invert;
	}

	return invert;
}

__attribute__((used)) static int connlabel_mt_check(const struct xt_mtchk_param *par)
{
	const int options = XT_CONNLABEL_OP_INVERT |
			    XT_CONNLABEL_OP_SET;
	struct xt_connlabel_mtinfo *info = par->matchinfo;
	int ret;

	if (info->options & ~options) {
		pr_info_ratelimited("Unknown options in mask %x\n",
				    info->options);
		return -EINVAL;
	}

	ret = nf_ct_netns_get(par->net, par->family);
	if (ret < 0) {
		pr_info_ratelimited("cannot load conntrack support for proto=%u\n",
				    par->family);
		return ret;
	}

	ret = nf_connlabels_get(par->net, info->bit);
	if (ret < 0)
		nf_ct_netns_put(par->net, par->family);
	return ret;
}

__attribute__((used)) static void connlabel_mt_destroy(const struct xt_mtdtor_param *par)
{
	nf_connlabels_put(par->net);
	nf_ct_netns_put(par->net, par->family);
}


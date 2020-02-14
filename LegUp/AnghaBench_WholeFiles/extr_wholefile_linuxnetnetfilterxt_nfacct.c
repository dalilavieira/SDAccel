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
struct xt_nfacct_match_info {struct nf_acct* nfacct; int /*<<< orphan*/  name; } ;
struct xt_mtdtor_param {struct xt_nfacct_match_info* matchinfo; } ;
struct xt_mtchk_param {int /*<<< orphan*/  net; struct xt_nfacct_match_info* matchinfo; } ;
struct xt_action_param {struct xt_nfacct_match_info* targinfo; } ;
struct sk_buff {int dummy; } ;
struct nf_acct {int dummy; } ;

/* Variables and functions */
 int ENOENT ; 
 int NFACCT_UNDERQUOTA ; 
 struct nf_acct* nfnl_acct_find_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int nfnl_acct_overquota (int /*<<< orphan*/ ,struct nf_acct*) ; 
 int /*<<< orphan*/  nfnl_acct_put (struct nf_acct*) ; 
 int /*<<< orphan*/  nfnl_acct_update (struct sk_buff const*,struct nf_acct*) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xt_net (struct xt_action_param*) ; 

__attribute__((used)) static bool nfacct_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	int overquota;
	const struct xt_nfacct_match_info *info = par->targinfo;

	nfnl_acct_update(skb, info->nfacct);

	overquota = nfnl_acct_overquota(xt_net(par), info->nfacct);

	return overquota == NFACCT_UNDERQUOTA ? false : true;
}

__attribute__((used)) static int
nfacct_mt_checkentry(const struct xt_mtchk_param *par)
{
	struct xt_nfacct_match_info *info = par->matchinfo;
	struct nf_acct *nfacct;

	nfacct = nfnl_acct_find_get(par->net, info->name);
	if (nfacct == NULL) {
		pr_info_ratelimited("accounting object `%s' does not exists\n",
				    info->name);
		return -ENOENT;
	}
	info->nfacct = nfacct;
	return 0;
}

__attribute__((used)) static void
nfacct_mt_destroy(const struct xt_mtdtor_param *par)
{
	const struct xt_nfacct_match_info *info = par->matchinfo;

	nfnl_acct_put(info->nfacct);
}


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
typedef  scalar_t__ u_int32_t ;
struct xt_rateest_match_info {int flags; int mode; struct xt_rateest* est2; struct xt_rateest* est1; int /*<<< orphan*/  name2; int /*<<< orphan*/  name1; scalar_t__ pps2; scalar_t__ bps2; scalar_t__ pps1; scalar_t__ bps1; } ;
struct xt_rateest {int /*<<< orphan*/  rate_est; } ;
struct xt_mtdtor_param {int /*<<< orphan*/  net; struct xt_rateest_match_info* matchinfo; } ;
struct xt_mtchk_param {int /*<<< orphan*/  net; struct xt_rateest_match_info* matchinfo; } ;
struct xt_action_param {struct xt_rateest_match_info* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct gnet_stats_rate_est64 {scalar_t__ pps; scalar_t__ bps; int /*<<< orphan*/  member_0; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int XT_RATEEST_MATCH_ABS ; 
 int XT_RATEEST_MATCH_BPS ; 
 int XT_RATEEST_MATCH_DELTA ; 
#define  XT_RATEEST_MATCH_EQ 130 
#define  XT_RATEEST_MATCH_GT 129 
 int XT_RATEEST_MATCH_INVERT ; 
#define  XT_RATEEST_MATCH_LT 128 
 int XT_RATEEST_MATCH_PPS ; 
 int XT_RATEEST_MATCH_REL ; 
 int /*<<< orphan*/  gen_estimator_read (int /*<<< orphan*/ *,struct gnet_stats_rate_est64*) ; 
 int hweight32 (int) ; 
 struct xt_rateest* xt_rateest_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xt_rateest_put (int /*<<< orphan*/ ,struct xt_rateest*) ; 

__attribute__((used)) static bool
xt_rateest_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_rateest_match_info *info = par->matchinfo;
	struct gnet_stats_rate_est64 sample = {0};
	u_int32_t bps1, bps2, pps1, pps2;
	bool ret = true;

	gen_estimator_read(&info->est1->rate_est, &sample);

	if (info->flags & XT_RATEEST_MATCH_DELTA) {
		bps1 = info->bps1 >= sample.bps ? info->bps1 - sample.bps : 0;
		pps1 = info->pps1 >= sample.pps ? info->pps1 - sample.pps : 0;
	} else {
		bps1 = sample.bps;
		pps1 = sample.pps;
	}

	if (info->flags & XT_RATEEST_MATCH_ABS) {
		bps2 = info->bps2;
		pps2 = info->pps2;
	} else {
		gen_estimator_read(&info->est2->rate_est, &sample);

		if (info->flags & XT_RATEEST_MATCH_DELTA) {
			bps2 = info->bps2 >= sample.bps ? info->bps2 - sample.bps : 0;
			pps2 = info->pps2 >= sample.pps ? info->pps2 - sample.pps : 0;
		} else {
			bps2 = sample.bps;
			pps2 = sample.pps;
		}
	}

	switch (info->mode) {
	case XT_RATEEST_MATCH_LT:
		if (info->flags & XT_RATEEST_MATCH_BPS)
			ret &= bps1 < bps2;
		if (info->flags & XT_RATEEST_MATCH_PPS)
			ret &= pps1 < pps2;
		break;
	case XT_RATEEST_MATCH_GT:
		if (info->flags & XT_RATEEST_MATCH_BPS)
			ret &= bps1 > bps2;
		if (info->flags & XT_RATEEST_MATCH_PPS)
			ret &= pps1 > pps2;
		break;
	case XT_RATEEST_MATCH_EQ:
		if (info->flags & XT_RATEEST_MATCH_BPS)
			ret &= bps1 == bps2;
		if (info->flags & XT_RATEEST_MATCH_PPS)
			ret &= pps1 == pps2;
		break;
	}

	ret ^= info->flags & XT_RATEEST_MATCH_INVERT ? true : false;
	return ret;
}

__attribute__((used)) static int xt_rateest_mt_checkentry(const struct xt_mtchk_param *par)
{
	struct xt_rateest_match_info *info = par->matchinfo;
	struct xt_rateest *est1, *est2;
	int ret = -EINVAL;

	if (hweight32(info->flags & (XT_RATEEST_MATCH_ABS |
				     XT_RATEEST_MATCH_REL)) != 1)
		goto err1;

	if (!(info->flags & (XT_RATEEST_MATCH_BPS | XT_RATEEST_MATCH_PPS)))
		goto err1;

	switch (info->mode) {
	case XT_RATEEST_MATCH_EQ:
	case XT_RATEEST_MATCH_LT:
	case XT_RATEEST_MATCH_GT:
		break;
	default:
		goto err1;
	}

	ret  = -ENOENT;
	est1 = xt_rateest_lookup(par->net, info->name1);
	if (!est1)
		goto err1;

	est2 = NULL;
	if (info->flags & XT_RATEEST_MATCH_REL) {
		est2 = xt_rateest_lookup(par->net, info->name2);
		if (!est2)
			goto err2;
	}

	info->est1 = est1;
	info->est2 = est2;
	return 0;

err2:
	xt_rateest_put(par->net, est1);
err1:
	return ret;
}

__attribute__((used)) static void xt_rateest_mt_destroy(const struct xt_mtdtor_param *par)
{
	struct xt_rateest_match_info *info = par->matchinfo;

	xt_rateest_put(par->net, info->est1);
	if (info->est2)
		xt_rateest_put(par->net, info->est2);
}


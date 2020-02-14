#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int every; int /*<<< orphan*/  count; } ;
struct TYPE_6__ {int probability; } ;
struct TYPE_8__ {TYPE_2__ nth; TYPE_1__ random; } ;
struct xt_statistic_info {int flags; int mode; TYPE_4__* master; TYPE_3__ u; } ;
struct xt_mtdtor_param {struct xt_statistic_info* matchinfo; } ;
struct xt_mtchk_param {struct xt_statistic_info* matchinfo; } ;
struct xt_action_param {struct xt_statistic_info* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  count; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int XT_STATISTIC_INVERT ; 
 int XT_STATISTIC_MASK ; 
 scalar_t__ XT_STATISTIC_MODE_MAX ; 
#define  XT_STATISTIC_MODE_NTH 129 
#define  XT_STATISTIC_MODE_RANDOM 128 
 int atomic_cmpxchg (int /*<<< orphan*/ *,int,int) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (TYPE_4__*) ; 
 TYPE_4__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int prandom_u32 () ; 

__attribute__((used)) static bool
statistic_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_statistic_info *info = par->matchinfo;
	bool ret = info->flags & XT_STATISTIC_INVERT;
	int nval, oval;

	switch (info->mode) {
	case XT_STATISTIC_MODE_RANDOM:
		if ((prandom_u32() & 0x7FFFFFFF) < info->u.random.probability)
			ret = !ret;
		break;
	case XT_STATISTIC_MODE_NTH:
		do {
			oval = atomic_read(&info->master->count);
			nval = (oval == info->u.nth.every) ? 0 : oval + 1;
		} while (atomic_cmpxchg(&info->master->count, oval, nval) != oval);
		if (nval == 0)
			ret = !ret;
		break;
	}

	return ret;
}

__attribute__((used)) static int statistic_mt_check(const struct xt_mtchk_param *par)
{
	struct xt_statistic_info *info = par->matchinfo;

	if (info->mode > XT_STATISTIC_MODE_MAX ||
	    info->flags & ~XT_STATISTIC_MASK)
		return -EINVAL;

	info->master = kzalloc(sizeof(*info->master), GFP_KERNEL);
	if (info->master == NULL)
		return -ENOMEM;
	atomic_set(&info->master->count, info->u.nth.count);

	return 0;
}

__attribute__((used)) static void statistic_mt_destroy(const struct xt_mtdtor_param *par)
{
	const struct xt_statistic_info *info = par->matchinfo;

	kfree(info->master);
}


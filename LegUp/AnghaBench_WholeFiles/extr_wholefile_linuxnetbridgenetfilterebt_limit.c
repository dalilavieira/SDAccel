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
typedef  int u_int32_t ;
struct xt_mtchk_param {struct ebt_limit_info* matchinfo; } ;
struct xt_action_param {scalar_t__ matchinfo; } ;
struct sk_buff {int dummy; } ;
struct ebt_limit_info {scalar_t__ credit; scalar_t__ credit_cap; scalar_t__ cost; int burst; int avg; void* prev; } ;

/* Variables and functions */
 unsigned long CREDITS_PER_JIFFY ; 
 int EBT_LIMIT_SCALE ; 
 int EINVAL ; 
 unsigned long HZ ; 
 void* jiffies ; 
 int /*<<< orphan*/  limit_lock ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int,int) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 unsigned long xchg (void**,unsigned long) ; 

__attribute__((used)) static bool
ebt_limit_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	struct ebt_limit_info *info = (void *)par->matchinfo;
	unsigned long now = jiffies;

	spin_lock_bh(&limit_lock);
	info->credit += (now - xchg(&info->prev, now)) * CREDITS_PER_JIFFY;
	if (info->credit > info->credit_cap)
		info->credit = info->credit_cap;

	if (info->credit >= info->cost) {
		/* We're not limited. */
		info->credit -= info->cost;
		spin_unlock_bh(&limit_lock);
		return true;
	}

	spin_unlock_bh(&limit_lock);
	return false;
}

__attribute__((used)) static u_int32_t
user2credits(u_int32_t user)
{
	/* If multiplying would overflow... */
	if (user > 0xFFFFFFFF / (HZ*CREDITS_PER_JIFFY))
		/* Divide first. */
		return (user / EBT_LIMIT_SCALE) * HZ * CREDITS_PER_JIFFY;

	return (user * HZ * CREDITS_PER_JIFFY) / EBT_LIMIT_SCALE;
}

__attribute__((used)) static int ebt_limit_mt_check(const struct xt_mtchk_param *par)
{
	struct ebt_limit_info *info = par->matchinfo;

	/* Check for overflow. */
	if (info->burst == 0 ||
	    user2credits(info->avg * info->burst) < user2credits(info->avg)) {
		pr_info_ratelimited("overflow, try lower: %u/%u\n",
				    info->avg, info->burst);
		return -EINVAL;
	}

	/* User avg in seconds * EBT_LIMIT_SCALE: convert to jiffies * 128. */
	info->prev = jiffies;
	info->credit = user2credits(info->avg * info->burst);
	info->credit_cap = user2credits(info->avg * info->burst);
	info->cost = user2credits(info->avg);
	return 0;
}


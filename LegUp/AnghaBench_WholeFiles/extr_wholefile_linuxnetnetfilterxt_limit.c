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
typedef  int u32 ;
struct xt_rateinfo {scalar_t__ credit_cap; scalar_t__ cost; int burst; int avg; struct xt_limit_priv* master; } ;
struct xt_mtdtor_param {struct xt_rateinfo* matchinfo; } ;
struct xt_mtchk_param {struct xt_rateinfo* matchinfo; } ;
struct xt_limit_priv {scalar_t__ credit; int /*<<< orphan*/  lock; void* prev; } ;
struct xt_action_param {struct xt_rateinfo* matchinfo; } ;
struct sk_buff {int dummy; } ;

/* Variables and functions */
 unsigned long CREDITS_PER_JIFFY ; 
 int ENOMEM ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long HZ ; 
 int XT_LIMIT_SCALE ; 
 void* jiffies ; 
 int /*<<< orphan*/  kfree (struct xt_limit_priv*) ; 
 struct xt_limit_priv* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int,int) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 unsigned long xchg (void**,unsigned long) ; 

__attribute__((used)) static bool
limit_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_rateinfo *r = par->matchinfo;
	struct xt_limit_priv *priv = r->master;
	unsigned long now = jiffies;

	spin_lock_bh(&priv->lock);
	priv->credit += (now - xchg(&priv->prev, now)) * CREDITS_PER_JIFFY;
	if (priv->credit > r->credit_cap)
		priv->credit = r->credit_cap;

	if (priv->credit >= r->cost) {
		/* We're not limited. */
		priv->credit -= r->cost;
		spin_unlock_bh(&priv->lock);
		return true;
	}

	spin_unlock_bh(&priv->lock);
	return false;
}

__attribute__((used)) static u32 user2credits(u32 user)
{
	/* If multiplying would overflow... */
	if (user > 0xFFFFFFFF / (HZ*CREDITS_PER_JIFFY))
		/* Divide first. */
		return (user / XT_LIMIT_SCALE) * HZ * CREDITS_PER_JIFFY;

	return (user * HZ * CREDITS_PER_JIFFY) / XT_LIMIT_SCALE;
}

__attribute__((used)) static int limit_mt_check(const struct xt_mtchk_param *par)
{
	struct xt_rateinfo *r = par->matchinfo;
	struct xt_limit_priv *priv;

	/* Check for overflow. */
	if (r->burst == 0
	    || user2credits(r->avg * r->burst) < user2credits(r->avg)) {
		pr_info_ratelimited("Overflow, try lower: %u/%u\n",
				    r->avg, r->burst);
		return -ERANGE;
	}

	priv = kmalloc(sizeof(*priv), GFP_KERNEL);
	if (priv == NULL)
		return -ENOMEM;

	/* For SMP, we only want to use one set of state. */
	r->master = priv;
	/* User avg in seconds * XT_LIMIT_SCALE: convert to jiffies *
	   128. */
	priv->prev = jiffies;
	priv->credit = user2credits(r->avg * r->burst); /* Credits full. */
	if (r->cost == 0) {
		r->credit_cap = priv->credit; /* Credits full. */
		r->cost = user2credits(r->avg);
	}
	spin_lock_init(&priv->lock);

	return 0;
}

__attribute__((used)) static void limit_mt_destroy(const struct xt_mtdtor_param *par)
{
	const struct xt_rateinfo *info = par->matchinfo;

	kfree(info->master);
}


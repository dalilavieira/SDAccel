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
struct xt_quota_priv {scalar_t__ quota; int /*<<< orphan*/  lock; } ;
struct xt_quota_info {int flags; scalar_t__ quota; struct xt_quota_priv* master; } ;
struct xt_mtdtor_param {struct xt_quota_info* matchinfo; } ;
struct xt_mtchk_param {struct xt_quota_info* matchinfo; } ;
struct xt_action_param {scalar_t__ matchinfo; } ;
struct sk_buff {scalar_t__ len; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int XT_QUOTA_INVERT ; 
 int XT_QUOTA_MASK ; 
 int /*<<< orphan*/  kfree (struct xt_quota_priv*) ; 
 struct xt_quota_priv* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool
quota_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	struct xt_quota_info *q = (void *)par->matchinfo;
	struct xt_quota_priv *priv = q->master;
	bool ret = q->flags & XT_QUOTA_INVERT;

	spin_lock_bh(&priv->lock);
	if (priv->quota >= skb->len) {
		priv->quota -= skb->len;
		ret = !ret;
	} else {
		/* we do not allow even small packets from now on */
		priv->quota = 0;
	}
	spin_unlock_bh(&priv->lock);

	return ret;
}

__attribute__((used)) static int quota_mt_check(const struct xt_mtchk_param *par)
{
	struct xt_quota_info *q = par->matchinfo;

	if (q->flags & ~XT_QUOTA_MASK)
		return -EINVAL;

	q->master = kmalloc(sizeof(*q->master), GFP_KERNEL);
	if (q->master == NULL)
		return -ENOMEM;

	spin_lock_init(&q->master->lock);
	q->master->quota = q->quota;
	return 0;
}

__attribute__((used)) static void quota_mt_destroy(const struct xt_mtdtor_param *par)
{
	const struct xt_quota_info *q = par->matchinfo;

	kfree(q->master);
}


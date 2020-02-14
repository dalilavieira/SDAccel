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
struct device {int dummy; } ;
struct clk {char const* name; scalar_t__ enabled; unsigned long rate; TYPE_1__* clk_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* disable ) (struct clk*) ;int /*<<< orphan*/  (* enable ) (struct clk*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ENOENT ; 
 struct clk* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WARN_ON (struct clk*) ; 
 int /*<<< orphan*/  clk_lock ; 
 char const* dev_name (struct device*) ; 
 struct clk** mcf_clks ; 
 int /*<<< orphan*/  pr_warn (char*,char const*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  stub1 (struct clk*) ; 
 int /*<<< orphan*/  stub2 (struct clk*) ; 

struct clk *clk_get(struct device *dev, const char *id)
{
	const char *clk_name = dev ? dev_name(dev) : id ? id : NULL;
	struct clk *clk;
	unsigned i;

	for (i = 0; (clk = mcf_clks[i]) != NULL; ++i)
		if (!strcmp(clk->name, clk_name))
			return clk;
	pr_warn("clk_get: didn't find clock %s\n", clk_name);
	return ERR_PTR(-ENOENT);
}

int clk_enable(struct clk *clk)
{
	unsigned long flags;
	spin_lock_irqsave(&clk_lock, flags);
	if ((clk->enabled++ == 0) && clk->clk_ops)
		clk->clk_ops->enable(clk);
	spin_unlock_irqrestore(&clk_lock, flags);

	return 0;
}

void clk_disable(struct clk *clk)
{
	unsigned long flags;

	if (!clk)
		return;

	spin_lock_irqsave(&clk_lock, flags);
	if ((--clk->enabled == 0) && clk->clk_ops)
		clk->clk_ops->disable(clk);
	spin_unlock_irqrestore(&clk_lock, flags);
}

void clk_put(struct clk *clk)
{
	if (clk->enabled != 0)
		pr_warn("clk_put %s still enabled\n", clk->name);
}

unsigned long clk_get_rate(struct clk *clk)
{
	if (!clk)
		return 0;

	return clk->rate;
}

long clk_round_rate(struct clk *clk, unsigned long rate)
{
	WARN_ON(clk);
	return 0;
}

int clk_set_rate(struct clk *clk, unsigned long rate)
{
	WARN_ON(clk);
	return 0;
}

int clk_set_parent(struct clk *clk, struct clk *parent)
{
	WARN_ON(clk);
	return 0;
}

struct clk *clk_get_parent(struct clk *clk)
{
	WARN_ON(clk);
	return NULL;
}


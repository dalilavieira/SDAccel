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
struct device {int dummy; } ;
struct clk_init_data {char const* name; unsigned long flags; char const** parent_names; int num_parents; int /*<<< orphan*/ * ops; } ;
struct clk_hw {struct clk* clk; struct clk_init_data* init; } ;
struct clk_fixed_rate {unsigned long fixed_rate; unsigned long fixed_accuracy; struct clk_hw hw; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 unsigned long CLK_IS_BASIC ; 
 int ENOMEM ; 
 struct clk* ERR_CAST (struct clk_hw*) ; 
 struct clk_hw* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk_hw*) ; 
 struct clk_hw* __clk_get_hw (struct clk*) ; 
 int /*<<< orphan*/  clk_fixed_rate_ops ; 
 int clk_hw_register (struct device*,struct clk_hw*) ; 
 int /*<<< orphan*/  clk_hw_unregister (struct clk_hw*) ; 
 int /*<<< orphan*/  clk_unregister (struct clk*) ; 
 int /*<<< orphan*/  kfree (struct clk_fixed_rate*) ; 
 struct clk_fixed_rate* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct clk_fixed_rate* to_clk_fixed_rate (struct clk_hw*) ; 

__attribute__((used)) static unsigned long clk_fixed_rate_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	return to_clk_fixed_rate(hw)->fixed_rate;
}

__attribute__((used)) static unsigned long clk_fixed_rate_recalc_accuracy(struct clk_hw *hw,
		unsigned long parent_accuracy)
{
	return to_clk_fixed_rate(hw)->fixed_accuracy;
}

struct clk_hw *clk_hw_register_fixed_rate_with_accuracy(struct device *dev,
		const char *name, const char *parent_name, unsigned long flags,
		unsigned long fixed_rate, unsigned long fixed_accuracy)
{
	struct clk_fixed_rate *fixed;
	struct clk_hw *hw;
	struct clk_init_data init;
	int ret;

	/* allocate fixed-rate clock */
	fixed = kzalloc(sizeof(*fixed), GFP_KERNEL);
	if (!fixed)
		return ERR_PTR(-ENOMEM);

	init.name = name;
	init.ops = &clk_fixed_rate_ops;
	init.flags = flags | CLK_IS_BASIC;
	init.parent_names = (parent_name ? &parent_name: NULL);
	init.num_parents = (parent_name ? 1 : 0);

	/* struct clk_fixed_rate assignments */
	fixed->fixed_rate = fixed_rate;
	fixed->fixed_accuracy = fixed_accuracy;
	fixed->hw.init = &init;

	/* register the clock */
	hw = &fixed->hw;
	ret = clk_hw_register(dev, hw);
	if (ret) {
		kfree(fixed);
		hw = ERR_PTR(ret);
	}

	return hw;
}

struct clk *clk_register_fixed_rate_with_accuracy(struct device *dev,
		const char *name, const char *parent_name, unsigned long flags,
		unsigned long fixed_rate, unsigned long fixed_accuracy)
{
	struct clk_hw *hw;

	hw = clk_hw_register_fixed_rate_with_accuracy(dev, name, parent_name,
			flags, fixed_rate, fixed_accuracy);
	if (IS_ERR(hw))
		return ERR_CAST(hw);
	return hw->clk;
}

struct clk_hw *clk_hw_register_fixed_rate(struct device *dev, const char *name,
		const char *parent_name, unsigned long flags,
		unsigned long fixed_rate)
{
	return clk_hw_register_fixed_rate_with_accuracy(dev, name, parent_name,
						     flags, fixed_rate, 0);
}

struct clk *clk_register_fixed_rate(struct device *dev, const char *name,
		const char *parent_name, unsigned long flags,
		unsigned long fixed_rate)
{
	return clk_register_fixed_rate_with_accuracy(dev, name, parent_name,
						     flags, fixed_rate, 0);
}

void clk_unregister_fixed_rate(struct clk *clk)
{
	struct clk_hw *hw;

	hw = __clk_get_hw(clk);
	if (!hw)
		return;

	clk_unregister(clk);
	kfree(to_clk_fixed_rate(hw));
}

void clk_hw_unregister_fixed_rate(struct clk_hw *hw)
{
	struct clk_fixed_rate *fixed;

	fixed = to_clk_fixed_rate(hw);

	clk_hw_unregister(hw);
	kfree(fixed);
}


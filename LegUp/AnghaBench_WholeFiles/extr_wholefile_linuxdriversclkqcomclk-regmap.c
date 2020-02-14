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
struct device {struct device* parent; } ;
struct clk_regmap {unsigned int enable_mask; int /*<<< orphan*/  hw; void* regmap; int /*<<< orphan*/  enable_reg; scalar_t__ enable_is_inverted; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 void* dev_get_regmap (struct device*,int /*<<< orphan*/ *) ; 
 int devm_clk_hw_register (struct device*,int /*<<< orphan*/ *) ; 
 int regmap_read (void*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (void*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct clk_regmap* to_clk_regmap (struct clk_hw*) ; 

int clk_is_enabled_regmap(struct clk_hw *hw)
{
	struct clk_regmap *rclk = to_clk_regmap(hw);
	unsigned int val;
	int ret;

	ret = regmap_read(rclk->regmap, rclk->enable_reg, &val);
	if (ret != 0)
		return ret;

	if (rclk->enable_is_inverted)
		return (val & rclk->enable_mask) == 0;
	else
		return (val & rclk->enable_mask) != 0;
}

int clk_enable_regmap(struct clk_hw *hw)
{
	struct clk_regmap *rclk = to_clk_regmap(hw);
	unsigned int val;

	if (rclk->enable_is_inverted)
		val = 0;
	else
		val = rclk->enable_mask;

	return regmap_update_bits(rclk->regmap, rclk->enable_reg,
				  rclk->enable_mask, val);
}

void clk_disable_regmap(struct clk_hw *hw)
{
	struct clk_regmap *rclk = to_clk_regmap(hw);
	unsigned int val;

	if (rclk->enable_is_inverted)
		val = rclk->enable_mask;
	else
		val = 0;

	regmap_update_bits(rclk->regmap, rclk->enable_reg, rclk->enable_mask,
			   val);
}

int devm_clk_register_regmap(struct device *dev, struct clk_regmap *rclk)
{
	if (dev && dev_get_regmap(dev, NULL))
		rclk->regmap = dev_get_regmap(dev, NULL);
	else if (dev && dev->parent)
		rclk->regmap = dev_get_regmap(dev->parent, NULL);

	return devm_clk_hw_register(dev, &rclk->hw);
}


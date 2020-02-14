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
typedef  int u8 ;
struct uniphier_clk_cpugear_data {unsigned int mask; scalar_t__ regbase; int /*<<< orphan*/  num_parents; int /*<<< orphan*/  parent_names; } ;
struct clk_hw {struct clk_init_data* init; } ;
struct uniphier_clk_cpugear {unsigned int mask; struct clk_hw hw; scalar_t__ regbase; struct regmap* regmap; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct clk_init_data {char const* name; int /*<<< orphan*/  num_parents; int /*<<< orphan*/  parent_names; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct clk_hw* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ UNIPHIER_CLK_CPUGEAR_SET ; 
 scalar_t__ UNIPHIER_CLK_CPUGEAR_STAT ; 
 scalar_t__ UNIPHIER_CLK_CPUGEAR_UPD ; 
 unsigned int UNIPHIER_CLK_CPUGEAR_UPD_BIT ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 int devm_clk_hw_register (struct device*,struct clk_hw*) ; 
 struct uniphier_clk_cpugear* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int regmap_read (struct regmap*,scalar_t__,unsigned int*) ; 
 int regmap_read_poll_timeout (struct regmap*,scalar_t__,unsigned int,int,int /*<<< orphan*/ ,int) ; 
 int regmap_write_bits (struct regmap*,scalar_t__,unsigned int,unsigned int) ; 
 struct uniphier_clk_cpugear* to_uniphier_clk_cpugear (struct clk_hw*) ; 
 int /*<<< orphan*/  uniphier_clk_cpugear_ops ; 

__attribute__((used)) static int uniphier_clk_cpugear_set_parent(struct clk_hw *hw, u8 index)
{
	struct uniphier_clk_cpugear *gear = to_uniphier_clk_cpugear(hw);
	int ret;
	unsigned int val;

	ret = regmap_write_bits(gear->regmap,
				gear->regbase + UNIPHIER_CLK_CPUGEAR_SET,
				gear->mask, index);
	if (ret)
		return ret;

	ret = regmap_write_bits(gear->regmap,
				gear->regbase + UNIPHIER_CLK_CPUGEAR_UPD,
				UNIPHIER_CLK_CPUGEAR_UPD_BIT,
				UNIPHIER_CLK_CPUGEAR_UPD_BIT);
	if (ret)
		return ret;

	return regmap_read_poll_timeout(gear->regmap,
				gear->regbase + UNIPHIER_CLK_CPUGEAR_UPD,
				val, !(val & UNIPHIER_CLK_CPUGEAR_UPD_BIT),
				0, 1);
}

__attribute__((used)) static u8 uniphier_clk_cpugear_get_parent(struct clk_hw *hw)
{
	struct uniphier_clk_cpugear *gear = to_uniphier_clk_cpugear(hw);
	int num_parents = clk_hw_get_num_parents(hw);
	int ret;
	unsigned int val;

	ret = regmap_read(gear->regmap,
			  gear->regbase + UNIPHIER_CLK_CPUGEAR_STAT, &val);
	if (ret)
		return ret;

	val &= gear->mask;

	return val < num_parents ? val : -EINVAL;
}

struct clk_hw *uniphier_clk_register_cpugear(struct device *dev,
					 struct regmap *regmap,
					 const char *name,
				const struct uniphier_clk_cpugear_data *data)
{
	struct uniphier_clk_cpugear *gear;
	struct clk_init_data init;
	int ret;

	gear = devm_kzalloc(dev, sizeof(*gear), GFP_KERNEL);
	if (!gear)
		return ERR_PTR(-ENOMEM);

	init.name = name;
	init.ops = &uniphier_clk_cpugear_ops;
	init.flags = CLK_SET_RATE_PARENT;
	init.parent_names = data->parent_names;
	init.num_parents = data->num_parents,

	gear->regmap = regmap;
	gear->regbase = data->regbase;
	gear->mask = data->mask;
	gear->hw.init = &init;

	ret = devm_clk_hw_register(dev, &gear->hw);
	if (ret)
		return ERR_PTR(ret);

	return &gear->hw;
}


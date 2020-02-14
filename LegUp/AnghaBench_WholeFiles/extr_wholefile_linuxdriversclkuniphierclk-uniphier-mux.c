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
typedef  size_t u8 ;
struct uniphier_clk_mux_data {unsigned int* masks; unsigned int* vals; int /*<<< orphan*/  reg; int /*<<< orphan*/  num_parents; int /*<<< orphan*/  parent_names; } ;
struct clk_hw {struct clk_init_data* init; } ;
struct uniphier_clk_mux {unsigned int* masks; unsigned int* vals; struct clk_hw hw; int /*<<< orphan*/  reg; struct regmap* regmap; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct clk_init_data {char const* name; int /*<<< orphan*/  num_parents; int /*<<< orphan*/  parent_names; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 size_t EINVAL ; 
 int ENOMEM ; 
 struct clk_hw* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 int devm_clk_hw_register (struct device*,struct clk_hw*) ; 
 struct uniphier_clk_mux* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct uniphier_clk_mux* to_uniphier_clk_mux (struct clk_hw*) ; 
 int /*<<< orphan*/  uniphier_clk_mux_ops ; 

__attribute__((used)) static int uniphier_clk_mux_set_parent(struct clk_hw *hw, u8 index)
{
	struct uniphier_clk_mux *mux = to_uniphier_clk_mux(hw);

	return regmap_write_bits(mux->regmap, mux->reg, mux->masks[index],
				 mux->vals[index]);
}

__attribute__((used)) static u8 uniphier_clk_mux_get_parent(struct clk_hw *hw)
{
	struct uniphier_clk_mux *mux = to_uniphier_clk_mux(hw);
	int num_parents = clk_hw_get_num_parents(hw);
	int ret;
	unsigned int val;
	u8 i;

	ret = regmap_read(mux->regmap, mux->reg, &val);
	if (ret)
		return ret;

	for (i = 0; i < num_parents; i++)
		if ((mux->masks[i] & val) == mux->vals[i])
			return i;

	return -EINVAL;
}

struct clk_hw *uniphier_clk_register_mux(struct device *dev,
					 struct regmap *regmap,
					 const char *name,
				const struct uniphier_clk_mux_data *data)
{
	struct uniphier_clk_mux *mux;
	struct clk_init_data init;
	int ret;

	mux = devm_kzalloc(dev, sizeof(*mux), GFP_KERNEL);
	if (!mux)
		return ERR_PTR(-ENOMEM);

	init.name = name;
	init.ops = &uniphier_clk_mux_ops;
	init.flags = CLK_SET_RATE_PARENT;
	init.parent_names = data->parent_names;
	init.num_parents = data->num_parents,

	mux->regmap = regmap;
	mux->reg = data->reg;
	mux->masks = data->masks;
	mux->vals = data->vals;
	mux->hw.init = &init;

	ret = devm_clk_hw_register(dev, &mux->hw);
	if (ret)
		return ERR_PTR(ret);

	return &mux->hw;
}


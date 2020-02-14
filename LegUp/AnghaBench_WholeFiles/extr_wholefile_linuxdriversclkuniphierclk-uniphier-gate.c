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
struct uniphier_clk_gate_data {int /*<<< orphan*/  bit; int /*<<< orphan*/  reg; scalar_t__ parent_name; } ;
struct clk_hw {struct clk_init_data* init; } ;
struct uniphier_clk_gate {struct clk_hw hw; int /*<<< orphan*/  bit; int /*<<< orphan*/  reg; struct regmap* regmap; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct clk_init_data {char const* name; int num_parents; scalar_t__* parent_names; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 int ENOMEM ; 
 struct clk_hw* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int devm_clk_hw_register (struct device*,struct clk_hw*) ; 
 struct uniphier_clk_gate* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 scalar_t__ regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct uniphier_clk_gate* to_uniphier_clk_gate (struct clk_hw*) ; 
 int /*<<< orphan*/  uniphier_clk_gate_ops ; 

__attribute__((used)) static int uniphier_clk_gate_endisable(struct clk_hw *hw, int enable)
{
	struct uniphier_clk_gate *gate = to_uniphier_clk_gate(hw);

	return regmap_write_bits(gate->regmap, gate->reg, BIT(gate->bit),
				 enable ? BIT(gate->bit) : 0);
}

__attribute__((used)) static int uniphier_clk_gate_enable(struct clk_hw *hw)
{
	return uniphier_clk_gate_endisable(hw, 1);
}

__attribute__((used)) static void uniphier_clk_gate_disable(struct clk_hw *hw)
{
	if (uniphier_clk_gate_endisable(hw, 0) < 0)
		pr_warn("failed to disable clk\n");
}

__attribute__((used)) static int uniphier_clk_gate_is_enabled(struct clk_hw *hw)
{
	struct uniphier_clk_gate *gate = to_uniphier_clk_gate(hw);
	unsigned int val;

	if (regmap_read(gate->regmap, gate->reg, &val) < 0)
		pr_warn("is_enabled() may return wrong result\n");

	return !!(val & BIT(gate->bit));
}

struct clk_hw *uniphier_clk_register_gate(struct device *dev,
					  struct regmap *regmap,
					  const char *name,
				const struct uniphier_clk_gate_data *data)
{
	struct uniphier_clk_gate *gate;
	struct clk_init_data init;
	int ret;

	gate = devm_kzalloc(dev, sizeof(*gate), GFP_KERNEL);
	if (!gate)
		return ERR_PTR(-ENOMEM);

	init.name = name;
	init.ops = &uniphier_clk_gate_ops;
	init.flags = data->parent_name ? CLK_SET_RATE_PARENT : 0;
	init.parent_names = data->parent_name ? &data->parent_name : NULL;
	init.num_parents = data->parent_name ? 1 : 0;

	gate->regmap = regmap;
	gate->reg = data->reg;
	gate->bit = data->bit;
	gate->hw.init = &init;

	ret = devm_clk_hw_register(dev, &gate->hw);
	if (ret)
		return ERR_PTR(ret);

	return &gate->hw;
}


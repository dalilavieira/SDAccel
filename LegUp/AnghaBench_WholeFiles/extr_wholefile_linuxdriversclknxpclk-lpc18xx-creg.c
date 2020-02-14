#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct regmap {int dummy; } ;
struct TYPE_5__ {struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct device_node {int /*<<< orphan*/  parent; } ;
struct device {int dummy; } ;
struct clk_init_data {char* name; char const** parent_names; int num_parents; scalar_t__ flags; int /*<<< orphan*/  ops; } ;
struct clk_hw {int dummy; } ;
struct TYPE_4__ {struct clk_init_data* init; } ;
struct clk_creg_data {int en_mask; char* name; TYPE_1__ hw; struct regmap* reg; int /*<<< orphan*/  ops; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 size_t CREG_CLK_1KHZ ; 
 size_t CREG_CLK_32KHZ ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int /*<<< orphan*/  LPC18XX_CREG_CREG0 ; 
 int LPC18XX_CREG_CREG0_PD32KHZ ; 
 int LPC18XX_CREG_CREG0_RESET32KHZ ; 
 int PTR_ERR (struct regmap*) ; 
 struct clk** clk_creg ; 
 struct clk_creg_data* clk_creg_clocks ; 
 int /*<<< orphan*/  clk_creg_data ; 
 struct clk** clk_creg_early ; 
 struct clk* clk_register (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 struct clk* devm_clk_register (struct device*,TYPE_1__*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int of_clk_add_provider (struct device_node*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_clk_src_onecell_get ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 struct regmap* syscon_node_to_regmap (int /*<<< orphan*/ ) ; 
 struct clk_creg_data* to_clk_creg (struct clk_hw*) ; 

__attribute__((used)) static int clk_creg_32k_prepare(struct clk_hw *hw)
{
	struct clk_creg_data *creg = to_clk_creg(hw);
	int ret;

	ret = regmap_update_bits(creg->reg, LPC18XX_CREG_CREG0,
				 LPC18XX_CREG_CREG0_PD32KHZ |
				 LPC18XX_CREG_CREG0_RESET32KHZ, 0);

	/*
	 * Powering up the 32k oscillator takes a long while
	 * and sadly there aren't any status bit to poll.
	 */
	msleep(2500);

	return ret;
}

__attribute__((used)) static void clk_creg_32k_unprepare(struct clk_hw *hw)
{
	struct clk_creg_data *creg = to_clk_creg(hw);

	regmap_update_bits(creg->reg, LPC18XX_CREG_CREG0,
			   LPC18XX_CREG_CREG0_PD32KHZ,
			   LPC18XX_CREG_CREG0_PD32KHZ);
}

__attribute__((used)) static int clk_creg_32k_is_prepared(struct clk_hw *hw)
{
	struct clk_creg_data *creg = to_clk_creg(hw);
	u32 reg;

	regmap_read(creg->reg, LPC18XX_CREG_CREG0, &reg);

	return !(reg & LPC18XX_CREG_CREG0_PD32KHZ) &&
	       !(reg & LPC18XX_CREG_CREG0_RESET32KHZ);
}

__attribute__((used)) static unsigned long clk_creg_1k_recalc_rate(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	return parent_rate / 32;
}

__attribute__((used)) static int clk_creg_enable(struct clk_hw *hw)
{
	struct clk_creg_data *creg = to_clk_creg(hw);

	return regmap_update_bits(creg->reg, LPC18XX_CREG_CREG0,
				  creg->en_mask, creg->en_mask);
}

__attribute__((used)) static void clk_creg_disable(struct clk_hw *hw)
{
	struct clk_creg_data *creg = to_clk_creg(hw);

	regmap_update_bits(creg->reg, LPC18XX_CREG_CREG0,
			   creg->en_mask, 0);
}

__attribute__((used)) static int clk_creg_is_enabled(struct clk_hw *hw)
{
	struct clk_creg_data *creg = to_clk_creg(hw);
	u32 reg;

	regmap_read(creg->reg, LPC18XX_CREG_CREG0, &reg);

	return !!(reg & creg->en_mask);
}

__attribute__((used)) static struct clk *clk_register_creg_clk(struct device *dev,
					 struct clk_creg_data *creg_clk,
					 const char **parent_name,
					 struct regmap *syscon)
{
	struct clk_init_data init;

	init.ops = creg_clk->ops;
	init.name = creg_clk->name;
	init.parent_names = parent_name;
	init.num_parents = 1;
	init.flags = 0;

	creg_clk->reg = syscon;
	creg_clk->hw.init = &init;

	if (dev)
		return devm_clk_register(dev, &creg_clk->hw);

	return clk_register(NULL, &creg_clk->hw);
}

__attribute__((used)) static int lpc18xx_creg_clk_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct regmap *syscon;

	syscon = syscon_node_to_regmap(np->parent);
	if (IS_ERR(syscon)) {
		dev_err(&pdev->dev, "syscon lookup failed\n");
		return PTR_ERR(syscon);
	}

	clk_creg[CREG_CLK_32KHZ] = clk_creg_early[CREG_CLK_32KHZ];
	clk_creg[CREG_CLK_1KHZ] =
		clk_register_creg_clk(NULL, &clk_creg_clocks[CREG_CLK_1KHZ],
				      &clk_creg_clocks[CREG_CLK_32KHZ].name,
				      syscon);

	return of_clk_add_provider(np, of_clk_src_onecell_get, &clk_creg_data);
}


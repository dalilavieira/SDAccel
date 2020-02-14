#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_5__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u32 ;
struct TYPE_8__ {struct clk_init_data* init; } ;
struct vexpress_osc {unsigned long rate_min; unsigned long rate_max; TYPE_5__ hw; struct clk* reg; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct clk_init_data {int /*<<< orphan*/  name; scalar_t__ num_parents; scalar_t__ flags; int /*<<< orphan*/ * ops; } ;
struct clk_hw {int dummy; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (unsigned long*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  clk_hw_set_rate_range (TYPE_5__*,unsigned long,unsigned long) ; 
 struct clk* clk_register (int /*<<< orphan*/ *,TYPE_5__*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_1__*) ; 
 struct vexpress_osc* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct clk* devm_regmap_init_vexpress_config (TYPE_1__*) ; 
 int /*<<< orphan*/  of_clk_add_provider (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct clk*) ; 
 int /*<<< orphan*/  of_clk_src_simple_get ; 
 scalar_t__ of_property_read_string (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ of_property_read_u32_array (int /*<<< orphan*/ ,char*,unsigned long*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (struct clk*,int /*<<< orphan*/ ,unsigned long*) ; 
 int regmap_write (struct clk*,int /*<<< orphan*/ ,unsigned long) ; 
 struct vexpress_osc* to_vexpress_osc (struct clk_hw*) ; 
 int /*<<< orphan*/  vexpress_osc_ops ; 

__attribute__((used)) static unsigned long vexpress_osc_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	struct vexpress_osc *osc = to_vexpress_osc(hw);
	u32 rate;

	regmap_read(osc->reg, 0, &rate);

	return rate;
}

__attribute__((used)) static long vexpress_osc_round_rate(struct clk_hw *hw, unsigned long rate,
		unsigned long *parent_rate)
{
	struct vexpress_osc *osc = to_vexpress_osc(hw);

	if (osc->rate_min && rate < osc->rate_min)
		rate = osc->rate_min;

	if (osc->rate_max && rate > osc->rate_max)
		rate = osc->rate_max;

	return rate;
}

__attribute__((used)) static int vexpress_osc_set_rate(struct clk_hw *hw, unsigned long rate,
		unsigned long parent_rate)
{
	struct vexpress_osc *osc = to_vexpress_osc(hw);

	return regmap_write(osc->reg, 0, rate);
}

__attribute__((used)) static int vexpress_osc_probe(struct platform_device *pdev)
{
	struct clk_init_data init;
	struct vexpress_osc *osc;
	struct clk *clk;
	u32 range[2];

	osc = devm_kzalloc(&pdev->dev, sizeof(*osc), GFP_KERNEL);
	if (!osc)
		return -ENOMEM;

	osc->reg = devm_regmap_init_vexpress_config(&pdev->dev);
	if (IS_ERR(osc->reg))
		return PTR_ERR(osc->reg);

	if (of_property_read_u32_array(pdev->dev.of_node, "freq-range", range,
			ARRAY_SIZE(range)) == 0) {
		osc->rate_min = range[0];
		osc->rate_max = range[1];
	}

	if (of_property_read_string(pdev->dev.of_node, "clock-output-names",
			&init.name) != 0)
		init.name = dev_name(&pdev->dev);

	init.ops = &vexpress_osc_ops;
	init.flags = 0;
	init.num_parents = 0;

	osc->hw.init = &init;

	clk = clk_register(NULL, &osc->hw);
	if (IS_ERR(clk))
		return PTR_ERR(clk);

	of_clk_add_provider(pdev->dev.of_node, of_clk_src_simple_get, clk);
	clk_hw_set_rate_range(&osc->hw, osc->rate_min, osc->rate_max);

	dev_dbg(&pdev->dev, "Registered clock '%s'\n", init.name);

	return 0;
}


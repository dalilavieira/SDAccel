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
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct clk_init_data {char* name; scalar_t__ num_parents; int /*<<< orphan*/ * parent_names; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;
struct clk_hw {int dummy; } ;
struct TYPE_2__ {struct clk_init_data* init; } ;
struct clk_hifiberry_hw {scalar_t__ mode; TYPE_1__ hw; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 unsigned long CLK_44EN_RATE ; 
 unsigned long CLK_48EN_RATE ; 
 int /*<<< orphan*/  CLK_IS_BASIC ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ERR (struct clk*) ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  clk_hifiberry_dacpro_rate_ops ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct clk* devm_clk_register (struct device*,TYPE_1__*) ; 
 int /*<<< orphan*/  kfree (struct clk_hifiberry_hw*) ; 
 struct clk_hifiberry_hw* kzalloc (int,int /*<<< orphan*/ ) ; 
 int of_clk_add_provider (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct clk*) ; 
 int /*<<< orphan*/  of_clk_del_provider (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_clk_src_simple_get ; 
 struct clk_hifiberry_hw* to_hifiberry_clk (struct clk_hw*) ; 

__attribute__((used)) static unsigned long clk_hifiberry_dacpro_recalc_rate(struct clk_hw *hw,
	unsigned long parent_rate)
{
	return (to_hifiberry_clk(hw)->mode == 0) ? CLK_44EN_RATE :
		CLK_48EN_RATE;
}

__attribute__((used)) static long clk_hifiberry_dacpro_round_rate(struct clk_hw *hw,
	unsigned long rate, unsigned long *parent_rate)
{
	long actual_rate;

	if (rate <= CLK_44EN_RATE) {
		actual_rate = (long)CLK_44EN_RATE;
	} else if (rate >= CLK_48EN_RATE) {
		actual_rate = (long)CLK_48EN_RATE;
	} else {
		long diff44Rate = (long)(rate - CLK_44EN_RATE);
		long diff48Rate = (long)(CLK_48EN_RATE - rate);

		if (diff44Rate < diff48Rate)
			actual_rate = (long)CLK_44EN_RATE;
		else
			actual_rate = (long)CLK_48EN_RATE;
	}
	return actual_rate;
}

__attribute__((used)) static int clk_hifiberry_dacpro_set_rate(struct clk_hw *hw,
	unsigned long rate, unsigned long parent_rate)
{
	unsigned long actual_rate;
	struct clk_hifiberry_hw *clk = to_hifiberry_clk(hw);

	actual_rate = (unsigned long)clk_hifiberry_dacpro_round_rate(hw, rate,
		&parent_rate);
	clk->mode = (actual_rate == CLK_44EN_RATE) ? 0 : 1;
	return 0;
}

__attribute__((used)) static int clk_hifiberry_dacpro_probe(struct platform_device *pdev)
{
	int ret;
	struct clk_hifiberry_hw *proclk;
	struct clk *clk;
	struct device *dev;
	struct clk_init_data init;

	dev = &pdev->dev;

	proclk = kzalloc(sizeof(struct clk_hifiberry_hw), GFP_KERNEL);
	if (!proclk)
		return -ENOMEM;

	init.name = "clk-hifiberry-dacpro";
	init.ops = &clk_hifiberry_dacpro_rate_ops;
	init.flags = CLK_IS_BASIC;
	init.parent_names = NULL;
	init.num_parents = 0;

	proclk->mode = 0;
	proclk->hw.init = &init;

	clk = devm_clk_register(dev, &proclk->hw);
	if (!IS_ERR(clk)) {
		ret = of_clk_add_provider(dev->of_node, of_clk_src_simple_get,
			clk);
	} else {
		dev_err(dev, "Fail to register clock driver\n");
		kfree(proclk);
		ret = PTR_ERR(clk);
	}
	return ret;
}

__attribute__((used)) static int clk_hifiberry_dacpro_remove(struct platform_device *pdev)
{
	of_clk_del_provider(pdev->dev.of_node);
	return 0;
}


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
typedef  int u32 ;
struct device {int dummy; } ;
struct clk_pll_data {int pllm_lower_mask; int pllm_upper_mask; int pllm_upper_shift; int plld_mask; int clkod_mask; int clkod_shift; int postdiv; scalar_t__ pllod; scalar_t__ has_pllctrl; scalar_t__ pll_ctl0; scalar_t__ pllm; } ;
struct TYPE_2__ {struct clk_init_data* init; } ;
struct clk_pll {TYPE_1__ hw; struct clk_pll_data* pll_data; } ;
struct clk_init_data {char const* name; char const** parent_names; int num_parents; scalar_t__ flags; int /*<<< orphan*/ * ops; } ;
struct clk_hw {int dummy; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 struct clk* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int /*<<< orphan*/  clk_pll_ops ; 
 struct clk* clk_register (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  kfree (struct clk_pll*) ; 
 struct clk_pll* kzalloc (int,int /*<<< orphan*/ ) ; 
 int readl (scalar_t__) ; 
 struct clk_pll* to_clk_pll (struct clk_hw*) ; 

__attribute__((used)) static unsigned long clk_pllclk_recalc(struct clk_hw *hw,
					unsigned long parent_rate)
{
	struct clk_pll *pll = to_clk_pll(hw);
	struct clk_pll_data *pll_data = pll->pll_data;
	unsigned long rate = parent_rate;
	u32  mult = 0, prediv, postdiv, val;

	/*
	 * get bits 0-5 of multiplier from pllctrl PLLM register
	 * if has_pllctrl is non zero
	 */
	if (pll_data->has_pllctrl) {
		val = readl(pll_data->pllm);
		mult = (val & pll_data->pllm_lower_mask);
	}

	/* bit6-12 of PLLM is in Main PLL control register */
	val = readl(pll_data->pll_ctl0);
	mult |= ((val & pll_data->pllm_upper_mask)
			>> pll_data->pllm_upper_shift);
	prediv = (val & pll_data->plld_mask);

	if (!pll_data->has_pllctrl)
		/* read post divider from od bits*/
		postdiv = ((val & pll_data->clkod_mask) >>
				 pll_data->clkod_shift) + 1;
	else if (pll_data->pllod) {
		postdiv = readl(pll_data->pllod);
		postdiv = ((postdiv & pll_data->clkod_mask) >>
				pll_data->clkod_shift) + 1;
	} else
		postdiv = pll_data->postdiv;

	rate /= (prediv + 1);
	rate = (rate * (mult + 1));
	rate /= postdiv;

	return rate;
}

__attribute__((used)) static struct clk *clk_register_pll(struct device *dev,
			const char *name,
			const char *parent_name,
			struct clk_pll_data *pll_data)
{
	struct clk_init_data init;
	struct clk_pll *pll;
	struct clk *clk;

	pll = kzalloc(sizeof(*pll), GFP_KERNEL);
	if (!pll)
		return ERR_PTR(-ENOMEM);

	init.name = name;
	init.ops = &clk_pll_ops;
	init.flags = 0;
	init.parent_names = (parent_name ? &parent_name : NULL);
	init.num_parents = (parent_name ? 1 : 0);

	pll->pll_data	= pll_data;
	pll->hw.init = &init;

	clk = clk_register(NULL, &pll->hw);
	if (IS_ERR(clk))
		goto out;

	return clk;
out:
	kfree(pll);
	return NULL;
}


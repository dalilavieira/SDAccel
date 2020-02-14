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
typedef  int u8 ;
typedef  int u32 ;
struct dpll_data {int idlest_mask; int enable_mask; int autoidle_mask; int /*<<< orphan*/  control_reg; int /*<<< orphan*/  autoidle_reg; int /*<<< orphan*/  idlest_reg; } ;
struct clk_hw_omap {unsigned long fixed_rate; struct dpll_data* dpll_data; int /*<<< orphan*/  hw; } ;
struct clk_hw {int dummy; } ;
struct TYPE_2__ {int (* clk_readl ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* clk_writel ) (int,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int APLL_AUTO_IDLE ; 
 int APLL_FORCE_LOCK ; 
 int EBUSY ; 
 int EINVAL ; 
 int MAX_APLL_WAIT_TRIES ; 
 int OMAP2_APLL_AUTOIDLE_DISABLE ; 
 int OMAP2_APLL_AUTOIDLE_LOW_POWER_STOP ; 
 int OMAP2_EN_APLL_LOCKED ; 
 int OMAP2_EN_APLL_STOPPED ; 
 int __ffs (int) ; 
 char* clk_hw_get_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_debug (char*,char const*,char*,int) ; 
 int /*<<< orphan*/  pr_warn (char*,char const*,...) ; 
 int stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub10 (int,int /*<<< orphan*/ *) ; 
 int stub11 (int /*<<< orphan*/ *) ; 
 int stub12 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub13 (int,int /*<<< orphan*/ *) ; 
 int stub14 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub15 (int,int /*<<< orphan*/ *) ; 
 int stub2 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ *) ; 
 int stub4 (int /*<<< orphan*/ *) ; 
 int stub5 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ *) ; 
 int stub7 (int /*<<< orphan*/ *) ; 
 int stub8 (int /*<<< orphan*/ *) ; 
 int stub9 (int /*<<< orphan*/ *) ; 
 TYPE_1__* ti_clk_ll_ops ; 
 struct clk_hw_omap* to_clk_hw_omap (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int dra7_apll_enable(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	int r = 0, i = 0;
	struct dpll_data *ad;
	const char *clk_name;
	u8 state = 1;
	u32 v;

	ad = clk->dpll_data;
	if (!ad)
		return -EINVAL;

	clk_name = clk_hw_get_name(&clk->hw);

	state <<= __ffs(ad->idlest_mask);

	/* Check is already locked */
	v = ti_clk_ll_ops->clk_readl(&ad->idlest_reg);

	if ((v & ad->idlest_mask) == state)
		return r;

	v = ti_clk_ll_ops->clk_readl(&ad->control_reg);
	v &= ~ad->enable_mask;
	v |= APLL_FORCE_LOCK << __ffs(ad->enable_mask);
	ti_clk_ll_ops->clk_writel(v, &ad->control_reg);

	state <<= __ffs(ad->idlest_mask);

	while (1) {
		v = ti_clk_ll_ops->clk_readl(&ad->idlest_reg);
		if ((v & ad->idlest_mask) == state)
			break;
		if (i > MAX_APLL_WAIT_TRIES)
			break;
		i++;
		udelay(1);
	}

	if (i == MAX_APLL_WAIT_TRIES) {
		pr_warn("clock: %s failed transition to '%s'\n",
			clk_name, (state) ? "locked" : "bypassed");
		r = -EBUSY;
	} else
		pr_debug("clock: %s transition to '%s' in %d loops\n",
			 clk_name, (state) ? "locked" : "bypassed", i);

	return r;
}

__attribute__((used)) static void dra7_apll_disable(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	struct dpll_data *ad;
	u8 state = 1;
	u32 v;

	ad = clk->dpll_data;

	state <<= __ffs(ad->idlest_mask);

	v = ti_clk_ll_ops->clk_readl(&ad->control_reg);
	v &= ~ad->enable_mask;
	v |= APLL_AUTO_IDLE << __ffs(ad->enable_mask);
	ti_clk_ll_ops->clk_writel(v, &ad->control_reg);
}

__attribute__((used)) static int dra7_apll_is_enabled(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	struct dpll_data *ad;
	u32 v;

	ad = clk->dpll_data;

	v = ti_clk_ll_ops->clk_readl(&ad->control_reg);
	v &= ad->enable_mask;

	v >>= __ffs(ad->enable_mask);

	return v == APLL_AUTO_IDLE ? 0 : 1;
}

__attribute__((used)) static u8 dra7_init_apll_parent(struct clk_hw *hw)
{
	return 0;
}

__attribute__((used)) static int omap2_apll_is_enabled(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	struct dpll_data *ad = clk->dpll_data;
	u32 v;

	v = ti_clk_ll_ops->clk_readl(&ad->control_reg);
	v &= ad->enable_mask;

	v >>= __ffs(ad->enable_mask);

	return v == OMAP2_EN_APLL_LOCKED ? 1 : 0;
}

__attribute__((used)) static unsigned long omap2_apll_recalc(struct clk_hw *hw,
				       unsigned long parent_rate)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);

	if (omap2_apll_is_enabled(hw))
		return clk->fixed_rate;

	return 0;
}

__attribute__((used)) static int omap2_apll_enable(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	struct dpll_data *ad = clk->dpll_data;
	u32 v;
	int i = 0;

	v = ti_clk_ll_ops->clk_readl(&ad->control_reg);
	v &= ~ad->enable_mask;
	v |= OMAP2_EN_APLL_LOCKED << __ffs(ad->enable_mask);
	ti_clk_ll_ops->clk_writel(v, &ad->control_reg);

	while (1) {
		v = ti_clk_ll_ops->clk_readl(&ad->idlest_reg);
		if (v & ad->idlest_mask)
			break;
		if (i > MAX_APLL_WAIT_TRIES)
			break;
		i++;
		udelay(1);
	}

	if (i == MAX_APLL_WAIT_TRIES) {
		pr_warn("%s failed to transition to locked\n",
			clk_hw_get_name(&clk->hw));
		return -EBUSY;
	}

	return 0;
}

__attribute__((used)) static void omap2_apll_disable(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	struct dpll_data *ad = clk->dpll_data;
	u32 v;

	v = ti_clk_ll_ops->clk_readl(&ad->control_reg);
	v &= ~ad->enable_mask;
	v |= OMAP2_EN_APLL_STOPPED << __ffs(ad->enable_mask);
	ti_clk_ll_ops->clk_writel(v, &ad->control_reg);
}

__attribute__((used)) static void omap2_apll_set_autoidle(struct clk_hw_omap *clk, u32 val)
{
	struct dpll_data *ad = clk->dpll_data;
	u32 v;

	v = ti_clk_ll_ops->clk_readl(&ad->autoidle_reg);
	v &= ~ad->autoidle_mask;
	v |= val << __ffs(ad->autoidle_mask);
	ti_clk_ll_ops->clk_writel(v, &ad->control_reg);
}

__attribute__((used)) static void omap2_apll_allow_idle(struct clk_hw_omap *clk)
{
	omap2_apll_set_autoidle(clk, OMAP2_APLL_AUTOIDLE_LOW_POWER_STOP);
}

__attribute__((used)) static void omap2_apll_deny_idle(struct clk_hw_omap *clk)
{
	omap2_apll_set_autoidle(clk, OMAP2_APLL_AUTOIDLE_DISABLE);
}


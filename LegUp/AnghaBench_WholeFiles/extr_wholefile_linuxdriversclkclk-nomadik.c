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
typedef  int u32 ;
struct notifier_block {int dummy; } ;
struct clk_pll {int id; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int NOTIFY_OK ; 
 scalar_t__ SRC_PLLCR ; 
 int SRC_PLLCR_PLL1EN ; 
 int SRC_PLLCR_PLL1OVER ; 
 int SRC_PLLCR_PLL2EN ; 
 scalar_t__ SRC_PLLFR ; 
 scalar_t__ SRC_XTALCR ; 
 int SRC_XTALCR_MXTALEN ; 
 int SRC_XTALCR_MXTALOVER ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ src_base ; 
 int /*<<< orphan*/  src_lock ; 
 struct clk_pll* to_pll (struct clk_hw*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int nomadik_clk_reboot_handler(struct notifier_block *this,
				unsigned long code,
				void *unused)
{
	u32 val;

	/* The main chrystal need to be enabled for reboot to work */
	val = readl(src_base + SRC_XTALCR);
	val &= ~SRC_XTALCR_MXTALOVER;
	val |= SRC_XTALCR_MXTALEN;
	pr_crit("force-enabling MXTALO\n");
	writel(val, src_base + SRC_XTALCR);
	return NOTIFY_OK;
}

__attribute__((used)) static int pll_clk_enable(struct clk_hw *hw)
{
	struct clk_pll *pll = to_pll(hw);
	u32 val;

	spin_lock(&src_lock);
	val = readl(src_base + SRC_PLLCR);
	if (pll->id == 1) {
		if (val & SRC_PLLCR_PLL1OVER) {
			val |= SRC_PLLCR_PLL1EN;
			writel(val, src_base + SRC_PLLCR);
		}
	} else if (pll->id == 2) {
		val |= SRC_PLLCR_PLL2EN;
		writel(val, src_base + SRC_PLLCR);
	}
	spin_unlock(&src_lock);
	return 0;
}

__attribute__((used)) static void pll_clk_disable(struct clk_hw *hw)
{
	struct clk_pll *pll = to_pll(hw);
	u32 val;

	spin_lock(&src_lock);
	val = readl(src_base + SRC_PLLCR);
	if (pll->id == 1) {
		if (val & SRC_PLLCR_PLL1OVER) {
			val &= ~SRC_PLLCR_PLL1EN;
			writel(val, src_base + SRC_PLLCR);
		}
	} else if (pll->id == 2) {
		val &= ~SRC_PLLCR_PLL2EN;
		writel(val, src_base + SRC_PLLCR);
	}
	spin_unlock(&src_lock);
}

__attribute__((used)) static int pll_clk_is_enabled(struct clk_hw *hw)
{
	struct clk_pll *pll = to_pll(hw);
	u32 val;

	val = readl(src_base + SRC_PLLCR);
	if (pll->id == 1) {
		if (val & SRC_PLLCR_PLL1OVER)
			return !!(val & SRC_PLLCR_PLL1EN);
	} else if (pll->id == 2) {
		return !!(val & SRC_PLLCR_PLL2EN);
	}
	return 1;
}

__attribute__((used)) static unsigned long pll_clk_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	struct clk_pll *pll = to_pll(hw);
	u32 val;

	val = readl(src_base + SRC_PLLFR);

	if (pll->id == 1) {
		u8 mul;
		u8 div;

		mul = (val >> 8) & 0x3FU;
		mul += 2;
		div = val & 0x07U;
		return (parent_rate * mul) >> div;
	}

	if (pll->id == 2) {
		u8 mul;

		mul = (val >> 24) & 0x3FU;
		mul += 2;
		return (parent_rate * mul);
	}

	/* Unknown PLL */
	return 0;
}


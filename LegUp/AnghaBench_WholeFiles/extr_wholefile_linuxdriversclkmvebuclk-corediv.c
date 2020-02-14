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
typedef  unsigned long u32 ;
struct clk_hw {int dummy; } ;
struct clk_corediv_soc_desc {unsigned long enable_bit_offset; unsigned long ratio_reload; scalar_t__ ratio_offset; } ;
struct clk_corediv_desc {unsigned long offset; unsigned long mask; int /*<<< orphan*/  fieldbit; } ;
struct clk_corediv {int /*<<< orphan*/  lock; scalar_t__ reg; struct clk_corediv_desc* desc; struct clk_corediv_soc_desc* soc_desc; } ;

/* Variables and functions */
 unsigned long BIT (int /*<<< orphan*/ ) ; 
 unsigned long CORE_CLK_DIV_RATIO_MASK ; 
 unsigned long readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct clk_corediv* to_corediv_clk (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static int clk_corediv_is_enabled(struct clk_hw *hwclk)
{
	struct clk_corediv *corediv = to_corediv_clk(hwclk);
	const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
	const struct clk_corediv_desc *desc = corediv->desc;
	u32 enable_mask = BIT(desc->fieldbit) << soc_desc->enable_bit_offset;

	return !!(readl(corediv->reg) & enable_mask);
}

__attribute__((used)) static int clk_corediv_enable(struct clk_hw *hwclk)
{
	struct clk_corediv *corediv = to_corediv_clk(hwclk);
	const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
	const struct clk_corediv_desc *desc = corediv->desc;
	unsigned long flags = 0;
	u32 reg;

	spin_lock_irqsave(&corediv->lock, flags);

	reg = readl(corediv->reg);
	reg |= (BIT(desc->fieldbit) << soc_desc->enable_bit_offset);
	writel(reg, corediv->reg);

	spin_unlock_irqrestore(&corediv->lock, flags);

	return 0;
}

__attribute__((used)) static void clk_corediv_disable(struct clk_hw *hwclk)
{
	struct clk_corediv *corediv = to_corediv_clk(hwclk);
	const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
	const struct clk_corediv_desc *desc = corediv->desc;
	unsigned long flags = 0;
	u32 reg;

	spin_lock_irqsave(&corediv->lock, flags);

	reg = readl(corediv->reg);
	reg &= ~(BIT(desc->fieldbit) << soc_desc->enable_bit_offset);
	writel(reg, corediv->reg);

	spin_unlock_irqrestore(&corediv->lock, flags);
}

__attribute__((used)) static unsigned long clk_corediv_recalc_rate(struct clk_hw *hwclk,
					 unsigned long parent_rate)
{
	struct clk_corediv *corediv = to_corediv_clk(hwclk);
	const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
	const struct clk_corediv_desc *desc = corediv->desc;
	u32 reg, div;

	reg = readl(corediv->reg + soc_desc->ratio_offset);
	div = (reg >> desc->offset) & desc->mask;
	return parent_rate / div;
}

__attribute__((used)) static long clk_corediv_round_rate(struct clk_hw *hwclk, unsigned long rate,
			       unsigned long *parent_rate)
{
	/* Valid ratio are 1:4, 1:5, 1:6 and 1:8 */
	u32 div;

	div = *parent_rate / rate;
	if (div < 4)
		div = 4;
	else if (div > 6)
		div = 8;

	return *parent_rate / div;
}

__attribute__((used)) static int clk_corediv_set_rate(struct clk_hw *hwclk, unsigned long rate,
			    unsigned long parent_rate)
{
	struct clk_corediv *corediv = to_corediv_clk(hwclk);
	const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
	const struct clk_corediv_desc *desc = corediv->desc;
	unsigned long flags = 0;
	u32 reg, div;

	div = parent_rate / rate;

	spin_lock_irqsave(&corediv->lock, flags);

	/* Write new divider to the divider ratio register */
	reg = readl(corediv->reg + soc_desc->ratio_offset);
	reg &= ~(desc->mask << desc->offset);
	reg |= (div & desc->mask) << desc->offset;
	writel(reg, corediv->reg + soc_desc->ratio_offset);

	/* Set reload-force for this clock */
	reg = readl(corediv->reg) | BIT(desc->fieldbit);
	writel(reg, corediv->reg);

	/* Now trigger the clock update */
	reg = readl(corediv->reg) | soc_desc->ratio_reload;
	writel(reg, corediv->reg);

	/*
	 * Wait for clocks to settle down, and then clear all the
	 * ratios request and the reload request.
	 */
	udelay(1000);
	reg &= ~(CORE_CLK_DIV_RATIO_MASK | soc_desc->ratio_reload);
	writel(reg, corediv->reg);
	udelay(1000);

	spin_unlock_irqrestore(&corediv->lock, flags);

	return 0;
}


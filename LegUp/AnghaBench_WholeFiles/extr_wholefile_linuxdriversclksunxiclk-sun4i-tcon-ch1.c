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
struct tcon_ch1_clk {int /*<<< orphan*/  lock; int /*<<< orphan*/  reg; } ;
struct clk_rate_request {unsigned long rate; unsigned long best_parent_rate; struct clk_hw* best_parent_hw; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 long EINVAL ; 
 int TCON_CH1_SCLK1_GATE_BIT ; 
 int TCON_CH1_SCLK1_HALF_BIT ; 
 int TCON_CH1_SCLK2_DIV_MASK ; 
 int TCON_CH1_SCLK2_GATE_BIT ; 
 int TCON_CH1_SCLK2_MUX_MASK ; 
 int TCON_CH1_SCLK2_MUX_SHIFT ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int) ; 
 unsigned long clk_hw_get_rate (struct clk_hw*) ; 
 struct tcon_ch1_clk* hw_to_tclk (struct clk_hw*) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tcon_ch1_disable(struct clk_hw *hw)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&tclk->lock, flags);
	reg = readl(tclk->reg);
	reg &= ~(TCON_CH1_SCLK2_GATE_BIT | TCON_CH1_SCLK1_GATE_BIT);
	writel(reg, tclk->reg);
	spin_unlock_irqrestore(&tclk->lock, flags);
}

__attribute__((used)) static int tcon_ch1_enable(struct clk_hw *hw)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&tclk->lock, flags);
	reg = readl(tclk->reg);
	reg |= TCON_CH1_SCLK2_GATE_BIT | TCON_CH1_SCLK1_GATE_BIT;
	writel(reg, tclk->reg);
	spin_unlock_irqrestore(&tclk->lock, flags);

	return 0;
}

__attribute__((used)) static int tcon_ch1_is_enabled(struct clk_hw *hw)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	u32 reg;

	reg = readl(tclk->reg);
	return reg & (TCON_CH1_SCLK2_GATE_BIT | TCON_CH1_SCLK1_GATE_BIT);
}

__attribute__((used)) static u8 tcon_ch1_get_parent(struct clk_hw *hw)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	u32 reg;

	reg = readl(tclk->reg) >> TCON_CH1_SCLK2_MUX_SHIFT;
	reg &= reg >> TCON_CH1_SCLK2_MUX_MASK;

	return reg;
}

__attribute__((used)) static int tcon_ch1_set_parent(struct clk_hw *hw, u8 index)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&tclk->lock, flags);
	reg = readl(tclk->reg);
	reg &= ~(TCON_CH1_SCLK2_MUX_MASK << TCON_CH1_SCLK2_MUX_SHIFT);
	reg |= index << TCON_CH1_SCLK2_MUX_SHIFT;
	writel(reg, tclk->reg);
	spin_unlock_irqrestore(&tclk->lock, flags);

	return 0;
}

__attribute__((used)) static unsigned long tcon_ch1_calc_divider(unsigned long rate,
					   unsigned long parent_rate,
					   u8 *div,
					   bool *half)
{
	unsigned long best_rate = 0;
	u8 best_m = 0, m;
	bool is_double;

	for (m = 1; m < 16; m++) {
		u8 d;

		for (d = 1; d < 3; d++) {
			unsigned long tmp_rate;

			tmp_rate = parent_rate / m / d;

			if (tmp_rate > rate)
				continue;

			if (!best_rate ||
			    (rate - tmp_rate) < (rate - best_rate)) {
				best_rate = tmp_rate;
				best_m = m;
				is_double = d;
			}
		}
	}

	if (div && half) {
		*div = best_m;
		*half = is_double;
	}

	return best_rate;
}

__attribute__((used)) static int tcon_ch1_determine_rate(struct clk_hw *hw,
				   struct clk_rate_request *req)
{
	long best_rate = -EINVAL;
	int i;

	for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
		unsigned long parent_rate;
		unsigned long tmp_rate;
		struct clk_hw *parent;

		parent = clk_hw_get_parent_by_index(hw, i);
		if (!parent)
			continue;

		parent_rate = clk_hw_get_rate(parent);

		tmp_rate = tcon_ch1_calc_divider(req->rate, parent_rate,
						 NULL, NULL);

		if (best_rate < 0 ||
		    (req->rate - tmp_rate) < (req->rate - best_rate)) {
			best_rate = tmp_rate;
			req->best_parent_rate = parent_rate;
			req->best_parent_hw = parent;
		}
	}

	if (best_rate < 0)
		return best_rate;

	req->rate = best_rate;
	return 0;
}

__attribute__((used)) static unsigned long tcon_ch1_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	u32 reg;

	reg = readl(tclk->reg);

	parent_rate /= (reg & TCON_CH1_SCLK2_DIV_MASK) + 1;

	if (reg & TCON_CH1_SCLK1_HALF_BIT)
		parent_rate /= 2;

	return parent_rate;
}

__attribute__((used)) static int tcon_ch1_set_rate(struct clk_hw *hw, unsigned long rate,
			     unsigned long parent_rate)
{
	struct tcon_ch1_clk *tclk = hw_to_tclk(hw);
	unsigned long flags;
	bool half;
	u8 div_m;
	u32 reg;

	tcon_ch1_calc_divider(rate, parent_rate, &div_m, &half);

	spin_lock_irqsave(&tclk->lock, flags);
	reg = readl(tclk->reg);
	reg &= ~(TCON_CH1_SCLK2_DIV_MASK | TCON_CH1_SCLK1_HALF_BIT);
	reg |= (div_m - 1) & TCON_CH1_SCLK2_DIV_MASK;

	if (half)
		reg |= TCON_CH1_SCLK1_HALF_BIT;

	writel(reg, tclk->reg);
	spin_unlock_irqrestore(&tclk->lock, flags);

	return 0;
}


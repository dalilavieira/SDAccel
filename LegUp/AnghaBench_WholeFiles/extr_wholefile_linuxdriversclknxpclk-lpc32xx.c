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
typedef  int u64 ;
typedef  int u32 ;
struct lpc32xx_usb_clk {int enable; int ctrl_mask; int ctrl_enable; int busy; int ctrl_disable; } ;
struct lpc32xx_pll_clk {unsigned int enable; int m_div; int n_div; int p_div; int mode; int /*<<< orphan*/  reg; } ;
struct lpc32xx_clk_mux {int shift; int mask; int* table; int /*<<< orphan*/  reg; } ;
struct lpc32xx_clk_gate {int bit_idx; int flags; int /*<<< orphan*/  reg; } ;
struct lpc32xx_clk_div {unsigned int shift; int width; int flags; int /*<<< orphan*/  reg; struct clk_div_table* table; } ;
struct lpc32xx_clk {int busy_mask; int busy; unsigned int enable_mask; int enable; unsigned int disable_mask; int disable; int /*<<< orphan*/  reg; } ;
struct clk_hw {int dummy; } ;
struct clk_div_table {unsigned int div; unsigned int val; } ;

/* Variables and functions */
 int BIT (int) ; 
 unsigned long CLK_DIVIDER_ONE_BASED ; 
 int CLK_DIVIDER_READ_ONLY ; 
 int CLK_GATE_SET_TO_DISABLE ; 
 long DIV_ROUND_UP (unsigned long,unsigned int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  LPC32XX_CLKPWR_USB_CTRL ; 
 size_t LPC32XX_CLK_PERIPH ; 
 scalar_t__ LPC32XX_USB_CLK_CTRL ; 
 scalar_t__ LPC32XX_USB_CLK_STS ; 
#define  PLL_BYPASS 132 
 int PLL_CTRL_BYPASS ; 
 int PLL_CTRL_DIRECT ; 
 int PLL_CTRL_FEEDBACK ; 
 int PLL_CTRL_FEEDDIV ; 
 int PLL_CTRL_LOCK ; 
 int PLL_CTRL_POSTDIV ; 
 int PLL_CTRL_PREDIV ; 
#define  PLL_DIRECT 131 
#define  PLL_DIRECT_BYPASS 130 
#define  PLL_INTEGER 129 
#define  PLL_NON_INTEGER 128 
 int /*<<< orphan*/ * clk ; 
 unsigned long clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_hw_get_name (struct clk_hw*) ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int /*<<< orphan*/ ) ; 
 int clk_hw_get_rate (struct clk_hw*) ; 
 int /*<<< orphan*/  clk_regmap ; 
 void* div64_u64 (int,int) ; 
 unsigned int div_mask (int) ; 
 unsigned int divider_get_val (unsigned long,unsigned long,struct clk_div_table*,int,unsigned long) ; 
 unsigned long divider_recalc_rate (struct clk_hw*,unsigned long,unsigned int,struct clk_div_table*,int,int) ; 
 long divider_round_rate (struct clk_hw*,unsigned long,unsigned long*,struct clk_div_table*,int,unsigned long) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,int,...) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,unsigned long,...) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct lpc32xx_clk* to_lpc32xx_clk (struct clk_hw*) ; 
 struct lpc32xx_clk_div* to_lpc32xx_div (struct clk_hw*) ; 
 struct lpc32xx_clk_gate* to_lpc32xx_gate (struct clk_hw*) ; 
 struct lpc32xx_clk_mux* to_lpc32xx_mux (struct clk_hw*) ; 
 struct lpc32xx_pll_clk* to_lpc32xx_pll_clk (struct clk_hw*) ; 
 struct lpc32xx_usb_clk* to_lpc32xx_usb_clk (struct clk_hw*) ; 
 scalar_t__ usb_clk_vbase ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline bool pll_is_valid(u64 val0, u64 val1, u64 min, u64 max)
{
	return (val0 >= (val1 * min) && val0 <= (val1 * max));
}

__attribute__((used)) static inline u32 lpc32xx_usb_clk_read(struct lpc32xx_usb_clk *clk)
{
	return readl(usb_clk_vbase + LPC32XX_USB_CLK_STS);
}

__attribute__((used)) static inline void lpc32xx_usb_clk_write(struct lpc32xx_usb_clk *clk, u32 val)
{
	writel(val, usb_clk_vbase + LPC32XX_USB_CLK_CTRL);
}

__attribute__((used)) static int clk_mask_enable(struct clk_hw *hw)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
	u32 val;

	regmap_read(clk_regmap, clk->reg, &val);

	if (clk->busy_mask && (val & clk->busy_mask) == clk->busy)
		return -EBUSY;

	return regmap_update_bits(clk_regmap, clk->reg,
				  clk->enable_mask, clk->enable);
}

__attribute__((used)) static void clk_mask_disable(struct clk_hw *hw)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);

	regmap_update_bits(clk_regmap, clk->reg,
			   clk->disable_mask, clk->disable);
}

__attribute__((used)) static int clk_mask_is_enabled(struct clk_hw *hw)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
	u32 val;

	regmap_read(clk_regmap, clk->reg, &val);

	return ((val & clk->enable_mask) == clk->enable);
}

__attribute__((used)) static int clk_pll_enable(struct clk_hw *hw)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
	u32 val, count;

	regmap_update_bits(clk_regmap, clk->reg, clk->enable, clk->enable);

	for (count = 0; count < 1000; count++) {
		regmap_read(clk_regmap, clk->reg, &val);
		if (val & PLL_CTRL_LOCK)
			break;
	}

	if (val & PLL_CTRL_LOCK)
		return 0;

	return -ETIMEDOUT;
}

__attribute__((used)) static void clk_pll_disable(struct clk_hw *hw)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);

	regmap_update_bits(clk_regmap, clk->reg, clk->enable, 0x0);
}

__attribute__((used)) static int clk_pll_is_enabled(struct clk_hw *hw)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
	u32 val;

	regmap_read(clk_regmap, clk->reg, &val);

	val &= clk->enable | PLL_CTRL_LOCK;
	if (val == (clk->enable | PLL_CTRL_LOCK))
		return 1;

	return 0;
}

__attribute__((used)) static unsigned long clk_pll_397x_recalc_rate(struct clk_hw *hw,
					      unsigned long parent_rate)
{
	return parent_rate * 397;
}

__attribute__((used)) static unsigned long clk_pll_recalc_rate(struct clk_hw *hw,
					 unsigned long parent_rate)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
	bool is_direct, is_bypass, is_feedback;
	unsigned long rate, cco_rate, ref_rate;
	u32 val;

	regmap_read(clk_regmap, clk->reg, &val);
	is_direct = val & PLL_CTRL_DIRECT;
	is_bypass = val & PLL_CTRL_BYPASS;
	is_feedback = val & PLL_CTRL_FEEDBACK;

	clk->m_div = ((val & PLL_CTRL_FEEDDIV) >> 1) + 1;
	clk->n_div = ((val & PLL_CTRL_PREDIV) >> 9) + 1;
	clk->p_div = ((val & PLL_CTRL_POSTDIV) >> 11) + 1;

	if (is_direct && is_bypass) {
		clk->p_div = 0;
		clk->mode = PLL_DIRECT_BYPASS;
		return parent_rate;
	}
	if (is_bypass) {
		clk->mode = PLL_BYPASS;
		return parent_rate / (1 << clk->p_div);
	}
	if (is_direct) {
		clk->p_div = 0;
		clk->mode = PLL_DIRECT;
	}

	ref_rate = parent_rate / clk->n_div;
	rate = cco_rate = ref_rate * clk->m_div;

	if (!is_direct) {
		if (is_feedback) {
			cco_rate *= (1 << clk->p_div);
			clk->mode = PLL_INTEGER;
		} else {
			rate /= (1 << clk->p_div);
			clk->mode = PLL_NON_INTEGER;
		}
	}

	pr_debug("%s: %lu: 0x%x: %d/%d/%d, %lu/%lu/%d => %lu\n",
		 clk_hw_get_name(hw),
		 parent_rate, val, is_direct, is_bypass, is_feedback,
		 clk->n_div, clk->m_div, (1 << clk->p_div), rate);

	if (clk_pll_is_enabled(hw) &&
	    !(pll_is_valid(parent_rate, 1, 1000000, 20000000)
	      && pll_is_valid(cco_rate, 1, 156000000, 320000000)
	      && pll_is_valid(ref_rate, 1, 1000000, 27000000)))
		pr_err("%s: PLL clocks are not in valid ranges: %lu/%lu/%lu\n",
		       clk_hw_get_name(hw),
		       parent_rate, cco_rate, ref_rate);

	return rate;
}

__attribute__((used)) static int clk_pll_set_rate(struct clk_hw *hw, unsigned long rate,
			    unsigned long parent_rate)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
	u32 val;
	unsigned long new_rate;

	/* Validate PLL clock parameters computed on round rate stage */
	switch (clk->mode) {
	case PLL_DIRECT:
		val = PLL_CTRL_DIRECT;
		val |= (clk->m_div - 1) << 1;
		val |= (clk->n_div - 1) << 9;
		new_rate = (parent_rate * clk->m_div) / clk->n_div;
		break;
	case PLL_BYPASS:
		val = PLL_CTRL_BYPASS;
		val |= (clk->p_div - 1) << 11;
		new_rate = parent_rate / (1 << (clk->p_div));
		break;
	case PLL_DIRECT_BYPASS:
		val = PLL_CTRL_DIRECT | PLL_CTRL_BYPASS;
		new_rate = parent_rate;
		break;
	case PLL_INTEGER:
		val = PLL_CTRL_FEEDBACK;
		val |= (clk->m_div - 1) << 1;
		val |= (clk->n_div - 1) << 9;
		val |= (clk->p_div - 1) << 11;
		new_rate = (parent_rate * clk->m_div) / clk->n_div;
		break;
	case PLL_NON_INTEGER:
		val = 0x0;
		val |= (clk->m_div - 1) << 1;
		val |= (clk->n_div - 1) << 9;
		val |= (clk->p_div - 1) << 11;
		new_rate = (parent_rate * clk->m_div) /
				(clk->n_div * (1 << clk->p_div));
		break;
	default:
		return -EINVAL;
	}

	/* Sanity check that round rate is equal to the requested one */
	if (new_rate != rate)
		return -EINVAL;

	return regmap_update_bits(clk_regmap, clk->reg, 0x1FFFF, val);
}

__attribute__((used)) static long clk_hclk_pll_round_rate(struct clk_hw *hw, unsigned long rate,
				    unsigned long *parent_rate)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
	u64 m_i, o = rate, i = *parent_rate, d = (u64)rate << 6;
	u64 m = 0, n = 0, p = 0;
	int p_i, n_i;

	pr_debug("%s: %lu/%lu\n", clk_hw_get_name(hw), *parent_rate, rate);

	if (rate > 266500000)
		return -EINVAL;

	/* Have to check all 20 possibilities to find the minimal M */
	for (p_i = 4; p_i >= 0; p_i--) {
		for (n_i = 4; n_i > 0; n_i--) {
			m_i = div64_u64(o * n_i * (1 << p_i), i);

			/* Check for valid PLL parameter constraints */
			if (!(m_i && m_i <= 256
			      && pll_is_valid(i, n_i, 1000000, 27000000)
			      && pll_is_valid(i * m_i * (1 << p_i), n_i,
					      156000000, 320000000)))
				continue;

			/* Store some intermediate valid parameters */
			if (o * n_i * (1 << p_i) - i * m_i <= d) {
				m = m_i;
				n = n_i;
				p = p_i;
				d = o * n_i * (1 << p_i) - i * m_i;
			}
		}
	}

	if (d == (u64)rate << 6) {
		pr_err("%s: %lu: no valid PLL parameters are found\n",
		       clk_hw_get_name(hw), rate);
		return -EINVAL;
	}

	clk->m_div = m;
	clk->n_div = n;
	clk->p_div = p;

	/* Set only direct or non-integer mode of PLL */
	if (!p)
		clk->mode = PLL_DIRECT;
	else
		clk->mode = PLL_NON_INTEGER;

	o = div64_u64(i * m, n * (1 << p));

	if (!d)
		pr_debug("%s: %lu: found exact match: %llu/%llu/%llu\n",
			 clk_hw_get_name(hw), rate, m, n, p);
	else
		pr_debug("%s: %lu: found closest: %llu/%llu/%llu - %llu\n",
			 clk_hw_get_name(hw), rate, m, n, p, o);

	return o;
}

__attribute__((used)) static long clk_usb_pll_round_rate(struct clk_hw *hw, unsigned long rate,
				   unsigned long *parent_rate)
{
	struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
	struct clk_hw *usb_div_hw, *osc_hw;
	u64 d_i, n_i, m, o;

	pr_debug("%s: %lu/%lu\n", clk_hw_get_name(hw), *parent_rate, rate);

	/*
	 * The only supported USB clock is 48MHz, with PLL internal constraints
	 * on Fclkin, Fcco and Fref this implies that Fcco must be 192MHz
	 * and post-divider must be 4, this slightly simplifies calculation of
	 * USB divider, USB PLL N and M parameters.
	 */
	if (rate != 48000000)
		return -EINVAL;

	/* USB divider clock */
	usb_div_hw = clk_hw_get_parent_by_index(hw, 0);
	if (!usb_div_hw)
		return -EINVAL;

	/* Main oscillator clock */
	osc_hw = clk_hw_get_parent_by_index(usb_div_hw, 0);
	if (!osc_hw)
		return -EINVAL;
	o = clk_hw_get_rate(osc_hw);	/* must be in range 1..20 MHz */

	/* Check if valid USB divider and USB PLL parameters exists */
	for (d_i = 16; d_i >= 1; d_i--) {
		for (n_i = 1; n_i <= 4; n_i++) {
			m = div64_u64(192000000 * d_i * n_i, o);
			if (!(m && m <= 256
			      && m * o == 192000000 * d_i * n_i
			      && pll_is_valid(o, d_i, 1000000, 20000000)
			      && pll_is_valid(o, d_i * n_i, 1000000, 27000000)))
				continue;

			clk->n_div = n_i;
			clk->m_div = m;
			clk->p_div = 2;
			clk->mode = PLL_NON_INTEGER;
			*parent_rate = div64_u64(o, d_i);

			return rate;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int clk_ddram_is_enabled(struct clk_hw *hw)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
	u32 val;

	regmap_read(clk_regmap, clk->reg, &val);
	val &= clk->enable_mask | clk->busy_mask;

	return (val == (BIT(7) | BIT(0)) ||
		val == (BIT(8) | BIT(1)));
}

__attribute__((used)) static int clk_ddram_enable(struct clk_hw *hw)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
	u32 val, hclk_div;

	regmap_read(clk_regmap, clk->reg, &val);
	hclk_div = val & clk->busy_mask;

	/*
	 * DDRAM clock must be 2 times higher than HCLK,
	 * this implies DDRAM clock can not be enabled,
	 * if HCLK clock rate is equal to ARM clock rate
	 */
	if (hclk_div == 0x0 || hclk_div == (BIT(1) | BIT(0)))
		return -EINVAL;

	return regmap_update_bits(clk_regmap, clk->reg,
				  clk->enable_mask, hclk_div << 7);
}

__attribute__((used)) static unsigned long clk_ddram_recalc_rate(struct clk_hw *hw,
					   unsigned long parent_rate)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
	u32 val;

	if (!clk_ddram_is_enabled(hw))
		return 0;

	regmap_read(clk_regmap, clk->reg, &val);
	val &= clk->enable_mask;

	return parent_rate / (val >> 7);
}

__attribute__((used)) static unsigned long lpc32xx_clk_uart_recalc_rate(struct clk_hw *hw,
						  unsigned long parent_rate)
{
	struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
	u32 val, x, y;

	regmap_read(clk_regmap, clk->reg, &val);
	x = (val & 0xFF00) >> 8;
	y = val & 0xFF;

	if (x && y)
		return (parent_rate * x) / y;
	else
		return 0;
}

__attribute__((used)) static int clk_usb_enable(struct clk_hw *hw)
{
	struct lpc32xx_usb_clk *clk = to_lpc32xx_usb_clk(hw);
	u32 val, ctrl_val, count;

	pr_debug("%s: 0x%x\n", clk_hw_get_name(hw), clk->enable);

	if (clk->ctrl_mask) {
		regmap_read(clk_regmap, LPC32XX_CLKPWR_USB_CTRL, &ctrl_val);
		regmap_update_bits(clk_regmap, LPC32XX_CLKPWR_USB_CTRL,
				   clk->ctrl_mask, clk->ctrl_enable);
	}

	val = lpc32xx_usb_clk_read(clk);
	if (clk->busy && (val & clk->busy) == clk->busy) {
		if (clk->ctrl_mask)
			regmap_write(clk_regmap, LPC32XX_CLKPWR_USB_CTRL,
				     ctrl_val);
		return -EBUSY;
	}

	val |= clk->enable;
	lpc32xx_usb_clk_write(clk, val);

	for (count = 0; count < 1000; count++) {
		val = lpc32xx_usb_clk_read(clk);
		if ((val & clk->enable) == clk->enable)
			break;
	}

	if ((val & clk->enable) == clk->enable)
		return 0;

	if (clk->ctrl_mask)
		regmap_write(clk_regmap, LPC32XX_CLKPWR_USB_CTRL, ctrl_val);

	return -ETIMEDOUT;
}

__attribute__((used)) static void clk_usb_disable(struct clk_hw *hw)
{
	struct lpc32xx_usb_clk *clk = to_lpc32xx_usb_clk(hw);
	u32 val = lpc32xx_usb_clk_read(clk);

	val &= ~clk->enable;
	lpc32xx_usb_clk_write(clk, val);

	if (clk->ctrl_mask)
		regmap_update_bits(clk_regmap, LPC32XX_CLKPWR_USB_CTRL,
				   clk->ctrl_mask, clk->ctrl_disable);
}

__attribute__((used)) static int clk_usb_is_enabled(struct clk_hw *hw)
{
	struct lpc32xx_usb_clk *clk = to_lpc32xx_usb_clk(hw);
	u32 ctrl_val, val;

	if (clk->ctrl_mask) {
		regmap_read(clk_regmap, LPC32XX_CLKPWR_USB_CTRL, &ctrl_val);
		if ((ctrl_val & clk->ctrl_mask) != clk->ctrl_enable)
			return 0;
	}

	val = lpc32xx_usb_clk_read(clk);

	return ((val & clk->enable) == clk->enable);
}

__attribute__((used)) static unsigned long clk_usb_i2c_recalc_rate(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	return clk_get_rate(clk[LPC32XX_CLK_PERIPH]);
}

__attribute__((used)) static int lpc32xx_clk_gate_enable(struct clk_hw *hw)
{
	struct lpc32xx_clk_gate *clk = to_lpc32xx_gate(hw);
	u32 mask = BIT(clk->bit_idx);
	u32 val = (clk->flags & CLK_GATE_SET_TO_DISABLE ? 0x0 : mask);

	return regmap_update_bits(clk_regmap, clk->reg, mask, val);
}

__attribute__((used)) static void lpc32xx_clk_gate_disable(struct clk_hw *hw)
{
	struct lpc32xx_clk_gate *clk = to_lpc32xx_gate(hw);
	u32 mask = BIT(clk->bit_idx);
	u32 val = (clk->flags & CLK_GATE_SET_TO_DISABLE ? mask : 0x0);

	regmap_update_bits(clk_regmap, clk->reg, mask, val);
}

__attribute__((used)) static int lpc32xx_clk_gate_is_enabled(struct clk_hw *hw)
{
	struct lpc32xx_clk_gate *clk = to_lpc32xx_gate(hw);
	u32 val;
	bool is_set;

	regmap_read(clk_regmap, clk->reg, &val);
	is_set = val & BIT(clk->bit_idx);

	return (clk->flags & CLK_GATE_SET_TO_DISABLE ? !is_set : is_set);
}

__attribute__((used)) static unsigned int _get_table_div(const struct clk_div_table *table,
							unsigned int val)
{
	const struct clk_div_table *clkt;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->val == val)
			return clkt->div;
	return 0;
}

__attribute__((used)) static unsigned int _get_div(const struct clk_div_table *table,
			     unsigned int val, unsigned long flags, u8 width)
{
	if (flags & CLK_DIVIDER_ONE_BASED)
		return val;
	if (table)
		return _get_table_div(table, val);
	return val + 1;
}

__attribute__((used)) static unsigned long clk_divider_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	struct lpc32xx_clk_div *divider = to_lpc32xx_div(hw);
	unsigned int val;

	regmap_read(clk_regmap, divider->reg, &val);

	val >>= divider->shift;
	val &= div_mask(divider->width);

	return divider_recalc_rate(hw, parent_rate, val, divider->table,
				   divider->flags, divider->width);
}

__attribute__((used)) static long clk_divider_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *prate)
{
	struct lpc32xx_clk_div *divider = to_lpc32xx_div(hw);
	unsigned int bestdiv;

	/* if read only, just return current value */
	if (divider->flags & CLK_DIVIDER_READ_ONLY) {
		regmap_read(clk_regmap, divider->reg, &bestdiv);
		bestdiv >>= divider->shift;
		bestdiv &= div_mask(divider->width);
		bestdiv = _get_div(divider->table, bestdiv, divider->flags,
			divider->width);
		return DIV_ROUND_UP(*prate, bestdiv);
	}

	return divider_round_rate(hw, rate, prate, divider->table,
				  divider->width, divider->flags);
}

__attribute__((used)) static int clk_divider_set_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long parent_rate)
{
	struct lpc32xx_clk_div *divider = to_lpc32xx_div(hw);
	unsigned int value;

	value = divider_get_val(rate, parent_rate, divider->table,
				divider->width, divider->flags);

	return regmap_update_bits(clk_regmap, divider->reg,
				  div_mask(divider->width) << divider->shift,
				  value << divider->shift);
}

__attribute__((used)) static u8 clk_mux_get_parent(struct clk_hw *hw)
{
	struct lpc32xx_clk_mux *mux = to_lpc32xx_mux(hw);
	u32 num_parents = clk_hw_get_num_parents(hw);
	u32 val;

	regmap_read(clk_regmap, mux->reg, &val);
	val >>= mux->shift;
	val &= mux->mask;

	if (mux->table) {
		u32 i;

		for (i = 0; i < num_parents; i++)
			if (mux->table[i] == val)
				return i;
		return -EINVAL;
	}

	if (val >= num_parents)
		return -EINVAL;

	return val;
}

__attribute__((used)) static int clk_mux_set_parent(struct clk_hw *hw, u8 index)
{
	struct lpc32xx_clk_mux *mux = to_lpc32xx_mux(hw);

	if (mux->table)
		index = mux->table[index];

	return regmap_update_bits(clk_regmap, mux->reg,
			  mux->mask << mux->shift, index << mux->shift);
}


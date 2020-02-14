#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct clk {int enable_mask; unsigned long (* get_rate ) (struct clk*) ;unsigned long rate; int (* set_rate ) (struct clk*,unsigned long) ;struct clk* parent; scalar_t__ enable_reg; scalar_t__ sw_locked; int /*<<< orphan*/  users; } ;
struct TYPE_6__ {unsigned long rate; } ;
struct TYPE_5__ {int rate; } ;
struct TYPE_4__ {unsigned long rate; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int EP93XX_I2SCLKDIV_LRDIV128 ; 
 unsigned int EP93XX_I2SCLKDIV_LRDIV32 ; 
 unsigned int EP93XX_I2SCLKDIV_LRDIV64 ; 
 int EP93XX_I2SCLKDIV_LRDIV_MASK ; 
 unsigned int EP93XX_I2SCLKDIV_SDIV ; 
 unsigned long EP93XX_KEYTCHCLK_DIV16 ; 
 unsigned long EP93XX_KEYTCHCLK_DIV4 ; 
 int EP93XX_SYSCON_CLKDIV_ESEL ; 
 int EP93XX_SYSCON_CLKDIV_PDIV_SHIFT ; 
 int EP93XX_SYSCON_CLKDIV_PSEL ; 
 scalar_t__ EP93XX_SYSCON_PWRCNT ; 
 int EP93XX_SYSCON_PWRCNT_UARTBAUD ; 
 int /*<<< orphan*/  WARN_ON (struct clk*) ; 
 int __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int,scalar_t__) ; 
 unsigned long abs (unsigned long) ; 
 unsigned long clk_get_rate (struct clk*) ; 
 TYPE_3__ clk_i2s_lrclk ; 
 TYPE_2__ clk_i2s_mclk ; 
 TYPE_1__ clk_i2s_sclk ; 
 int /*<<< orphan*/  clk_lock ; 
 struct clk clk_pll1 ; 
 struct clk clk_pll2 ; 
 struct clk clk_xtali ; 
 int /*<<< orphan*/  do_div (unsigned long long,int) ; 
 int /*<<< orphan*/  ep93xx_devcfg_set_clear (int,unsigned int) ; 
 int /*<<< orphan*/  ep93xx_syscon_swlocked_write (unsigned int,scalar_t__) ; 
 unsigned long max3 (int,int,int) ; 
 unsigned long min (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned long stub1 (struct clk*) ; 
 int stub2 (struct clk*,unsigned long) ; 

__attribute__((used)) static inline void ep93xx_devcfg_set_bits(unsigned int bits)
{
	ep93xx_devcfg_set_clear(bits, 0x00);
}

__attribute__((used)) static inline void ep93xx_devcfg_clear_bits(unsigned int bits)
{
	ep93xx_devcfg_set_clear(0x00, bits);
}

__attribute__((used)) static void __clk_enable(struct clk *clk)
{
	if (!clk->users++) {
		if (clk->parent)
			__clk_enable(clk->parent);

		if (clk->enable_reg) {
			u32 v;

			v = __raw_readl(clk->enable_reg);
			v |= clk->enable_mask;
			if (clk->sw_locked)
				ep93xx_syscon_swlocked_write(v, clk->enable_reg);
			else
				__raw_writel(v, clk->enable_reg);
		}
	}
}

int clk_enable(struct clk *clk)
{
	unsigned long flags;

	if (!clk)
		return -EINVAL;

	spin_lock_irqsave(&clk_lock, flags);
	__clk_enable(clk);
	spin_unlock_irqrestore(&clk_lock, flags);

	return 0;
}

__attribute__((used)) static void __clk_disable(struct clk *clk)
{
	if (!--clk->users) {
		if (clk->enable_reg) {
			u32 v;

			v = __raw_readl(clk->enable_reg);
			v &= ~clk->enable_mask;
			if (clk->sw_locked)
				ep93xx_syscon_swlocked_write(v, clk->enable_reg);
			else
				__raw_writel(v, clk->enable_reg);
		}

		if (clk->parent)
			__clk_disable(clk->parent);
	}
}

void clk_disable(struct clk *clk)
{
	unsigned long flags;

	if (!clk)
		return;

	spin_lock_irqsave(&clk_lock, flags);
	__clk_disable(clk);
	spin_unlock_irqrestore(&clk_lock, flags);
}

__attribute__((used)) static unsigned long get_uart_rate(struct clk *clk)
{
	unsigned long rate = clk_get_rate(clk->parent);
	u32 value;

	value = __raw_readl(EP93XX_SYSCON_PWRCNT);
	if (value & EP93XX_SYSCON_PWRCNT_UARTBAUD)
		return rate;
	else
		return rate / 2;
}

unsigned long clk_get_rate(struct clk *clk)
{
	if (clk->get_rate)
		return clk->get_rate(clk);

	return clk->rate;
}

__attribute__((used)) static int set_keytchclk_rate(struct clk *clk, unsigned long rate)
{
	u32 val;
	u32 div_bit;

	val = __raw_readl(clk->enable_reg);

	/*
	 * The Key Matrix and ADC clocks are configured using the same
	 * System Controller register.  The clock used will be either
	 * 1/4 or 1/16 the external clock rate depending on the
	 * EP93XX_SYSCON_KEYTCHCLKDIV_KDIV/EP93XX_SYSCON_KEYTCHCLKDIV_ADIV
	 * bit being set or cleared.
	 */
	div_bit = clk->enable_mask >> 15;

	if (rate == EP93XX_KEYTCHCLK_DIV4)
		val |= div_bit;
	else if (rate == EP93XX_KEYTCHCLK_DIV16)
		val &= ~div_bit;
	else
		return -EINVAL;

	ep93xx_syscon_swlocked_write(val, clk->enable_reg);
	clk->rate = rate;
	return 0;
}

__attribute__((used)) static int calc_clk_div(struct clk *clk, unsigned long rate,
			int *psel, int *esel, int *pdiv, int *div)
{
	struct clk *mclk;
	unsigned long max_rate, actual_rate, mclk_rate, rate_err = -1;
	int i, found = 0, __div = 0, __pdiv = 0;

	/* Don't exceed the maximum rate */
	max_rate = max3(clk_pll1.rate / 4, clk_pll2.rate / 4, clk_xtali.rate / 4);
	rate = min(rate, max_rate);

	/*
	 * Try the two pll's and the external clock
	 * Because the valid predividers are 2, 2.5 and 3, we multiply
	 * all the clocks by 2 to avoid floating point math.
	 *
	 * This is based on the algorithm in the ep93xx raster guide:
	 * http://be-a-maverick.com/en/pubs/appNote/AN269REV1.pdf
	 *
	 */
	for (i = 0; i < 3; i++) {
		if (i == 0)
			mclk = &clk_xtali;
		else if (i == 1)
			mclk = &clk_pll1;
		else
			mclk = &clk_pll2;
		mclk_rate = mclk->rate * 2;

		/* Try each predivider value */
		for (__pdiv = 4; __pdiv <= 6; __pdiv++) {
			__div = mclk_rate / (rate * __pdiv);
			if (__div < 2 || __div > 127)
				continue;

			actual_rate = mclk_rate / (__pdiv * __div);

			if (!found || abs(actual_rate - rate) < rate_err) {
				*pdiv = __pdiv - 3;
				*div = __div;
				*psel = (i == 2);
				*esel = (i != 0);
				clk->parent = mclk;
				clk->rate = actual_rate;
				rate_err = abs(actual_rate - rate);
				found = 1;
			}
		}
	}

	if (!found)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int set_div_rate(struct clk *clk, unsigned long rate)
{
	int err, psel = 0, esel = 0, pdiv = 0, div = 0;
	u32 val;

	err = calc_clk_div(clk, rate, &psel, &esel, &pdiv, &div);
	if (err)
		return err;

	/* Clear the esel, psel, pdiv and div bits */
	val = __raw_readl(clk->enable_reg);
	val &= ~0x7fff;

	/* Set the new esel, psel, pdiv and div bits for the new clock rate */
	val |= (esel ? EP93XX_SYSCON_CLKDIV_ESEL : 0) |
		(psel ? EP93XX_SYSCON_CLKDIV_PSEL : 0) |
		(pdiv << EP93XX_SYSCON_CLKDIV_PDIV_SHIFT) | div;
	ep93xx_syscon_swlocked_write(val, clk->enable_reg);
	return 0;
}

__attribute__((used)) static int set_i2s_sclk_rate(struct clk *clk, unsigned long rate)
{
	unsigned val = __raw_readl(clk->enable_reg);

	if (rate == clk_i2s_mclk.rate / 2)
		ep93xx_syscon_swlocked_write(val & ~EP93XX_I2SCLKDIV_SDIV, 
					     clk->enable_reg);
	else if (rate == clk_i2s_mclk.rate / 4)
		ep93xx_syscon_swlocked_write(val | EP93XX_I2SCLKDIV_SDIV, 
					     clk->enable_reg);
	else
		return -EINVAL;

	clk_i2s_sclk.rate = rate;
	return 0;
}

__attribute__((used)) static int set_i2s_lrclk_rate(struct clk *clk, unsigned long rate)
{
	unsigned val = __raw_readl(clk->enable_reg) & 
		~EP93XX_I2SCLKDIV_LRDIV_MASK;
	
	if (rate == clk_i2s_sclk.rate / 32)
		ep93xx_syscon_swlocked_write(val | EP93XX_I2SCLKDIV_LRDIV32,
					     clk->enable_reg);
	else if (rate == clk_i2s_sclk.rate / 64)
		ep93xx_syscon_swlocked_write(val | EP93XX_I2SCLKDIV_LRDIV64,
					     clk->enable_reg);
	else if (rate == clk_i2s_sclk.rate / 128)
		ep93xx_syscon_swlocked_write(val | EP93XX_I2SCLKDIV_LRDIV128,
					     clk->enable_reg);
	else
		return -EINVAL;

	clk_i2s_lrclk.rate = rate;
	return 0;
}

int clk_set_rate(struct clk *clk, unsigned long rate)
{
	if (clk->set_rate)
		return clk->set_rate(clk, rate);

	return -EINVAL;
}

long clk_round_rate(struct clk *clk, unsigned long rate)
{
	WARN_ON(clk);
	return 0;
}

int clk_set_parent(struct clk *clk, struct clk *parent)
{
	WARN_ON(clk);
	return 0;
}

struct clk *clk_get_parent(struct clk *clk)
{
	return clk->parent;
}

__attribute__((used)) static unsigned long calc_pll_rate(u32 config_word)
{
	unsigned long long rate;
	int i;

	rate = clk_xtali.rate;
	rate *= ((config_word >> 11) & 0x1f) + 1;		/* X1FBD */
	rate *= ((config_word >> 5) & 0x3f) + 1;		/* X2FBD */
	do_div(rate, (config_word & 0x1f) + 1);			/* X2IPD */
	for (i = 0; i < ((config_word >> 16) & 3); i++)		/* PS */
		rate >>= 1;

	return (unsigned long)rate;
}


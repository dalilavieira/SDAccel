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
typedef  int u64 ;
typedef  int u32 ;
struct regmap {int dummy; } ;
struct pll_freq_tbl {long freq; int l; int m; int n; int /*<<< orphan*/  ibits; } ;
struct pll_config {int vco_val; int pre_div_val; int post_div_val; int mn_ena_mask; int main_output_mask; int aux_output_mask; int vco_mask; int pre_div_mask; int post_div_mask; int /*<<< orphan*/  n; int /*<<< orphan*/  m; int /*<<< orphan*/  l; } ;
struct clk_rate_request {unsigned long rate; unsigned long best_parent_rate; } ;
struct TYPE_2__ {struct regmap* regmap; int /*<<< orphan*/  hw; } ;
struct clk_pll {int post_div_shift; int /*<<< orphan*/  n_reg; TYPE_1__ clkr; int /*<<< orphan*/  m_reg; int /*<<< orphan*/  l_reg; int /*<<< orphan*/  mode_reg; struct pll_freq_tbl* freq_tbl; int /*<<< orphan*/  config_reg; scalar_t__ status_bit; int /*<<< orphan*/  status_reg; scalar_t__ post_div_width; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int BIT (scalar_t__) ; 
 int EINVAL ; 
 int ETIMEDOUT ; 
 int PLL_BYPASSNL ; 
 int PLL_OUTCTRL ; 
 int PLL_RESET_N ; 
 int PLL_VOTE_FSM_ENA ; 
 int /*<<< orphan*/  WARN (int,char*,char const*) ; 
 int clk_enable_regmap (struct clk_hw*) ; 
 char* clk_hw_get_name (int /*<<< orphan*/ *) ; 
 struct clk_hw* clk_hw_get_parent (struct clk_hw*) ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  qcom_pll_set_fsm_mode (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct clk_pll* to_clk_pll (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int clk_pll_enable(struct clk_hw *hw)
{
	struct clk_pll *pll = to_clk_pll(hw);
	int ret;
	u32 mask, val;

	mask = PLL_OUTCTRL | PLL_RESET_N | PLL_BYPASSNL;
	ret = regmap_read(pll->clkr.regmap, pll->mode_reg, &val);
	if (ret)
		return ret;

	/* Skip if already enabled or in FSM mode */
	if ((val & mask) == mask || val & PLL_VOTE_FSM_ENA)
		return 0;

	/* Disable PLL bypass mode. */
	ret = regmap_update_bits(pll->clkr.regmap, pll->mode_reg, PLL_BYPASSNL,
				 PLL_BYPASSNL);
	if (ret)
		return ret;

	/*
	 * H/W requires a 5us delay between disabling the bypass and
	 * de-asserting the reset. Delay 10us just to be safe.
	 */
	udelay(10);

	/* De-assert active-low PLL reset. */
	ret = regmap_update_bits(pll->clkr.regmap, pll->mode_reg, PLL_RESET_N,
				 PLL_RESET_N);
	if (ret)
		return ret;

	/* Wait until PLL is locked. */
	udelay(50);

	/* Enable PLL output. */
	return regmap_update_bits(pll->clkr.regmap, pll->mode_reg, PLL_OUTCTRL,
				 PLL_OUTCTRL);
}

__attribute__((used)) static void clk_pll_disable(struct clk_hw *hw)
{
	struct clk_pll *pll = to_clk_pll(hw);
	u32 mask;
	u32 val;

	regmap_read(pll->clkr.regmap, pll->mode_reg, &val);
	/* Skip if in FSM mode */
	if (val & PLL_VOTE_FSM_ENA)
		return;
	mask = PLL_OUTCTRL | PLL_RESET_N | PLL_BYPASSNL;
	regmap_update_bits(pll->clkr.regmap, pll->mode_reg, mask, 0);
}

__attribute__((used)) static unsigned long
clk_pll_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	struct clk_pll *pll = to_clk_pll(hw);
	u32 l, m, n, config;
	unsigned long rate;
	u64 tmp;

	regmap_read(pll->clkr.regmap, pll->l_reg, &l);
	regmap_read(pll->clkr.regmap, pll->m_reg, &m);
	regmap_read(pll->clkr.regmap, pll->n_reg, &n);

	l &= 0x3ff;
	m &= 0x7ffff;
	n &= 0x7ffff;

	rate = parent_rate * l;
	if (n) {
		tmp = parent_rate;
		tmp *= m;
		do_div(tmp, n);
		rate += tmp;
	}
	if (pll->post_div_width) {
		regmap_read(pll->clkr.regmap, pll->config_reg, &config);
		config >>= pll->post_div_shift;
		config &= BIT(pll->post_div_width) - 1;
		rate /= config + 1;
	}

	return rate;
}

__attribute__((used)) static const
struct pll_freq_tbl *find_freq(const struct pll_freq_tbl *f, unsigned long rate)
{
	if (!f)
		return NULL;

	for (; f->freq; f++)
		if (rate <= f->freq)
			return f;

	return NULL;
}

__attribute__((used)) static int
clk_pll_determine_rate(struct clk_hw *hw, struct clk_rate_request *req)
{
	struct clk_pll *pll = to_clk_pll(hw);
	const struct pll_freq_tbl *f;

	f = find_freq(pll->freq_tbl, req->rate);
	if (!f)
		req->rate = clk_pll_recalc_rate(hw, req->best_parent_rate);
	else
		req->rate = f->freq;

	return 0;
}

__attribute__((used)) static int
clk_pll_set_rate(struct clk_hw *hw, unsigned long rate, unsigned long p_rate)
{
	struct clk_pll *pll = to_clk_pll(hw);
	const struct pll_freq_tbl *f;
	bool enabled;
	u32 mode;
	u32 enable_mask = PLL_OUTCTRL | PLL_BYPASSNL | PLL_RESET_N;

	f = find_freq(pll->freq_tbl, rate);
	if (!f)
		return -EINVAL;

	regmap_read(pll->clkr.regmap, pll->mode_reg, &mode);
	enabled = (mode & enable_mask) == enable_mask;

	if (enabled)
		clk_pll_disable(hw);

	regmap_update_bits(pll->clkr.regmap, pll->l_reg, 0x3ff, f->l);
	regmap_update_bits(pll->clkr.regmap, pll->m_reg, 0x7ffff, f->m);
	regmap_update_bits(pll->clkr.regmap, pll->n_reg, 0x7ffff, f->n);
	regmap_write(pll->clkr.regmap, pll->config_reg, f->ibits);

	if (enabled)
		clk_pll_enable(hw);

	return 0;
}

__attribute__((used)) static int wait_for_pll(struct clk_pll *pll)
{
	u32 val;
	int count;
	int ret;
	const char *name = clk_hw_get_name(&pll->clkr.hw);

	/* Wait for pll to enable. */
	for (count = 200; count > 0; count--) {
		ret = regmap_read(pll->clkr.regmap, pll->status_reg, &val);
		if (ret)
			return ret;
		if (val & BIT(pll->status_bit))
			return 0;
		udelay(1);
	}

	WARN(1, "%s didn't enable after voting for it!\n", name);
	return -ETIMEDOUT;
}

__attribute__((used)) static int clk_pll_vote_enable(struct clk_hw *hw)
{
	int ret;
	struct clk_pll *p = to_clk_pll(clk_hw_get_parent(hw));

	ret = clk_enable_regmap(hw);
	if (ret)
		return ret;

	return wait_for_pll(p);
}

__attribute__((used)) static void clk_pll_configure(struct clk_pll *pll, struct regmap *regmap,
	const struct pll_config *config)
{
	u32 val;
	u32 mask;

	regmap_write(regmap, pll->l_reg, config->l);
	regmap_write(regmap, pll->m_reg, config->m);
	regmap_write(regmap, pll->n_reg, config->n);

	val = config->vco_val;
	val |= config->pre_div_val;
	val |= config->post_div_val;
	val |= config->mn_ena_mask;
	val |= config->main_output_mask;
	val |= config->aux_output_mask;

	mask = config->vco_mask;
	mask |= config->pre_div_mask;
	mask |= config->post_div_mask;
	mask |= config->mn_ena_mask;
	mask |= config->main_output_mask;
	mask |= config->aux_output_mask;

	regmap_update_bits(regmap, pll->config_reg, mask, val);
}

void clk_pll_configure_sr(struct clk_pll *pll, struct regmap *regmap,
		const struct pll_config *config, bool fsm_mode)
{
	clk_pll_configure(pll, regmap, config);
	if (fsm_mode)
		qcom_pll_set_fsm_mode(regmap, pll->mode_reg, 1, 8);
}

void clk_pll_configure_sr_hpm_lp(struct clk_pll *pll, struct regmap *regmap,
		const struct pll_config *config, bool fsm_mode)
{
	clk_pll_configure(pll, regmap, config);
	if (fsm_mode)
		qcom_pll_set_fsm_mode(regmap, pll->mode_reg, 1, 0);
}

__attribute__((used)) static int clk_pll_sr2_enable(struct clk_hw *hw)
{
	struct clk_pll *pll = to_clk_pll(hw);
	int ret;
	u32 mode;

	ret = regmap_read(pll->clkr.regmap, pll->mode_reg, &mode);
	if (ret)
		return ret;

	/* Disable PLL bypass mode. */
	ret = regmap_update_bits(pll->clkr.regmap, pll->mode_reg, PLL_BYPASSNL,
				 PLL_BYPASSNL);
	if (ret)
		return ret;

	/*
	 * H/W requires a 5us delay between disabling the bypass and
	 * de-asserting the reset. Delay 10us just to be safe.
	 */
	udelay(10);

	/* De-assert active-low PLL reset. */
	ret = regmap_update_bits(pll->clkr.regmap, pll->mode_reg, PLL_RESET_N,
				 PLL_RESET_N);
	if (ret)
		return ret;

	ret = wait_for_pll(pll);
	if (ret)
		return ret;

	/* Enable PLL output. */
	return regmap_update_bits(pll->clkr.regmap, pll->mode_reg, PLL_OUTCTRL,
				 PLL_OUTCTRL);
}

__attribute__((used)) static int
clk_pll_sr2_set_rate(struct clk_hw *hw, unsigned long rate, unsigned long prate)
{
	struct clk_pll *pll = to_clk_pll(hw);
	const struct pll_freq_tbl *f;
	bool enabled;
	u32 mode;
	u32 enable_mask = PLL_OUTCTRL | PLL_BYPASSNL | PLL_RESET_N;

	f = find_freq(pll->freq_tbl, rate);
	if (!f)
		return -EINVAL;

	regmap_read(pll->clkr.regmap, pll->mode_reg, &mode);
	enabled = (mode & enable_mask) == enable_mask;

	if (enabled)
		clk_pll_disable(hw);

	regmap_update_bits(pll->clkr.regmap, pll->l_reg, 0x3ff, f->l);
	regmap_update_bits(pll->clkr.regmap, pll->m_reg, 0x7ffff, f->m);
	regmap_update_bits(pll->clkr.regmap, pll->n_reg, 0x7ffff, f->n);

	if (enabled)
		clk_pll_sr2_enable(hw);

	return 0;
}


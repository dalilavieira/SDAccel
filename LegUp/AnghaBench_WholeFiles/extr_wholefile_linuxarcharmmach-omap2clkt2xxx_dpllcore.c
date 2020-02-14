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
typedef  long long u32 ;
typedef  scalar_t__ u16 ;
struct prcm_config {int cm_clksel1_pll; long long cm_clksel2_pll; int /*<<< orphan*/  base_sdrc_rfr; } ;
struct dpll_data {int mult_mask; int div1_mask; int /*<<< orphan*/  mult_div1_reg; } ;
struct clk_hw_omap {struct dpll_data* dpll_data; } ;
struct clk_hw {int dummy; } ;
typedef  scalar_t__ s16 ;
struct TYPE_6__ {scalar_t__ va; } ;
struct TYPE_5__ {int dpll_speed; int xtal_speed; } ;
struct TYPE_4__ {int (* clk_readl ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 long long CORE_CLK_SRC_32K ; 
 long long CORE_CLK_SRC_DPLL ; 
 long long CORE_CLK_SRC_DPLL_X2 ; 
 int EINVAL ; 
 long long OMAP24XX_CORE_CLK_SRC_MASK ; 
 scalar_t__ OMAP_SDRC_REGADDR (scalar_t__) ; 
 scalar_t__ OMAP_SMS_REGADDR (scalar_t__) ; 
 int /*<<< orphan*/  SDRC_RFR_CTRL_BYPASS ; 
 int /*<<< orphan*/  WARN (void*,char*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 long long __ffs (long long) ; 
 TYPE_3__ cm_base ; 
 TYPE_2__* curr_prcm_set ; 
 void* dpll_core_ck ; 
 long long omap2_get_dpll_rate (void*) ; 
 int /*<<< orphan*/  omap2_set_prcm (long long,int /*<<< orphan*/ ,long long) ; 
 long long omap2xxx_cm_get_core_clk_src () ; 
 long long omap2xxx_cm_get_core_pll_config () ; 
 int /*<<< orphan*/  omap2xxx_sdrc_dll_is_unlocked () ; 
 int /*<<< orphan*/  omap2xxx_sdrc_init_params (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap2xxx_sdrc_reprogram (long long,int) ; 
 TYPE_1__ omap_clk_ll_ops ; 
 long long readl_relaxed (scalar_t__) ; 
 int stub1 (int /*<<< orphan*/ *) ; 
 void* to_clk_hw_omap (struct clk_hw*) ; 
 int /*<<< orphan*/  writel_relaxed (long long,scalar_t__) ; 

__attribute__((used)) static inline u32 omap2_cm_read_mod_reg(s16 module, u16 idx)
{
	return readl_relaxed(cm_base.va + module + idx);
}

__attribute__((used)) static inline void omap2_cm_write_mod_reg(u32 val, s16 module, u16 idx)
{
	writel_relaxed(val, cm_base.va + module + idx);
}

__attribute__((used)) static inline u32 omap2_cm_rmw_mod_reg_bits(u32 mask, u32 bits, s16 module,
					    s16 idx)
{
	u32 v;

	v = omap2_cm_read_mod_reg(module, idx);
	v &= ~mask;
	v |= bits;
	omap2_cm_write_mod_reg(v, module, idx);

	return v;
}

__attribute__((used)) static inline u32 omap2_cm_read_mod_bits_shift(s16 domain, s16 idx, u32 mask)
{
	u32 v;

	v = omap2_cm_read_mod_reg(domain, idx);
	v &= mask;
	v >>= __ffs(mask);

	return v;
}

__attribute__((used)) static inline u32 omap2_cm_set_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
	return omap2_cm_rmw_mod_reg_bits(bits, bits, module, idx);
}

__attribute__((used)) static inline u32 omap2_cm_clear_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
	return omap2_cm_rmw_mod_reg_bits(bits, 0x0, module, idx);
}

__attribute__((used)) static inline void sdrc_write_reg(u32 val, u16 reg)
{
	writel_relaxed(val, OMAP_SDRC_REGADDR(reg));
}

__attribute__((used)) static inline u32 sdrc_read_reg(u16 reg)
{
	return readl_relaxed(OMAP_SDRC_REGADDR(reg));
}

__attribute__((used)) static inline void sms_write_reg(u32 val, u16 reg)
{
	writel_relaxed(val, OMAP_SMS_REGADDR(reg));
}

__attribute__((used)) static inline u32 sms_read_reg(u16 reg)
{
	return readl_relaxed(OMAP_SMS_REGADDR(reg));
}

__attribute__((used)) static inline void omap_push_sram_idle(void) {}

unsigned long omap2xxx_clk_get_core_rate(void)
{
	long long core_clk;
	u32 v;

	WARN_ON(!dpll_core_ck);

	core_clk = omap2_get_dpll_rate(dpll_core_ck);

	v = omap2xxx_cm_get_core_clk_src();

	if (v == CORE_CLK_SRC_32K)
		core_clk = 32768;
	else
		core_clk *= v;

	return core_clk;
}

__attribute__((used)) static long omap2_dpllcore_round_rate(unsigned long target_rate)
{
	u32 high, low, core_clk_src;

	core_clk_src = omap2xxx_cm_get_core_clk_src();

	if (core_clk_src == CORE_CLK_SRC_DPLL) {	/* DPLL clockout */
		high = curr_prcm_set->dpll_speed * 2;
		low = curr_prcm_set->dpll_speed;
	} else {				/* DPLL clockout x 2 */
		high = curr_prcm_set->dpll_speed;
		low = curr_prcm_set->dpll_speed / 2;
	}

#ifdef DOWN_VARIABLE_DPLL
	if (target_rate > high)
		return high;
	else
		return target_rate;
#else
	if (target_rate > low)
		return high;
	else
		return low;
#endif

}

unsigned long omap2_dpllcore_recalc(struct clk_hw *hw,
				    unsigned long parent_rate)
{
	return omap2xxx_clk_get_core_rate();
}

int omap2_reprogram_dpllcore(struct clk_hw *hw, unsigned long rate,
			     unsigned long parent_rate)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	u32 cur_rate, low, mult, div, valid_rate, done_rate;
	u32 bypass = 0;
	struct prcm_config tmpset;
	const struct dpll_data *dd;

	cur_rate = omap2xxx_clk_get_core_rate();
	mult = omap2xxx_cm_get_core_clk_src();

	if ((rate == (cur_rate / 2)) && (mult == 2)) {
		omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL, 1);
	} else if ((rate == (cur_rate * 2)) && (mult == 1)) {
		omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL_X2, 1);
	} else if (rate != cur_rate) {
		valid_rate = omap2_dpllcore_round_rate(rate);
		if (valid_rate != rate)
			return -EINVAL;

		if (mult == 1)
			low = curr_prcm_set->dpll_speed;
		else
			low = curr_prcm_set->dpll_speed / 2;

		dd = clk->dpll_data;
		if (!dd)
			return -EINVAL;

		tmpset.cm_clksel1_pll =
			omap_clk_ll_ops.clk_readl(&dd->mult_div1_reg);
		tmpset.cm_clksel1_pll &= ~(dd->mult_mask |
					   dd->div1_mask);
		div = ((curr_prcm_set->xtal_speed / 1000000) - 1);
		tmpset.cm_clksel2_pll = omap2xxx_cm_get_core_pll_config();
		tmpset.cm_clksel2_pll &= ~OMAP24XX_CORE_CLK_SRC_MASK;
		if (rate > low) {
			tmpset.cm_clksel2_pll |= CORE_CLK_SRC_DPLL_X2;
			mult = ((rate / 2) / 1000000);
			done_rate = CORE_CLK_SRC_DPLL_X2;
		} else {
			tmpset.cm_clksel2_pll |= CORE_CLK_SRC_DPLL;
			mult = (rate / 1000000);
			done_rate = CORE_CLK_SRC_DPLL;
		}
		tmpset.cm_clksel1_pll |= (div << __ffs(dd->mult_mask));
		tmpset.cm_clksel1_pll |= (mult << __ffs(dd->div1_mask));

		/* Worst case */
		tmpset.base_sdrc_rfr = SDRC_RFR_CTRL_BYPASS;

		if (rate == curr_prcm_set->xtal_speed)	/* If asking for 1-1 */
			bypass = 1;

		/* For omap2xxx_sdrc_init_params() */
		omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL_X2, 1);

		/* Force dll lock mode */
		omap2_set_prcm(tmpset.cm_clksel1_pll, tmpset.base_sdrc_rfr,
			       bypass);

		/* Errata: ret dll entry state */
		omap2xxx_sdrc_init_params(omap2xxx_sdrc_dll_is_unlocked());
		omap2xxx_sdrc_reprogram(done_rate, 0);
	}

	return 0;
}

void omap2xxx_clkt_dpllcore_init(struct clk_hw *hw)
{
	WARN(dpll_core_ck, "dpll_core_ck already set - should never happen");
	dpll_core_ck = to_clk_hw_omap(hw);
}


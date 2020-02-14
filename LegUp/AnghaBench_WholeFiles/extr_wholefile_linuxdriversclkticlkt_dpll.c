#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct dpll_data {int flags; unsigned int max_divider; unsigned int min_divider; int enable_mask; int mult_mask; int div1_mask; unsigned long max_rate; int max_multiplier; unsigned long last_rounded_rate; int last_rounded_m; int last_rounded_n; int /*<<< orphan*/  clk_ref; int /*<<< orphan*/  mult_div1_reg; int /*<<< orphan*/  clk_bypass; int /*<<< orphan*/  control_reg; } ;
struct clk_hw_omap {struct dpll_data* dpll_data; int /*<<< orphan*/  hw; } ;
struct clk_hw {int dummy; } ;
struct TYPE_4__ {long fint_min; long fint_max; long fint_band1_max; long fint_band2_min; int dpll_bypass_vals; } ;
struct TYPE_3__ {int (* clk_readl ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int DPLL_FINT_INVALID ; 
 int DPLL_FINT_UNDERFLOW ; 
 int DPLL_J_TYPE ; 
 int DPLL_MIN_MULTIPLIER ; 
 int DPLL_MULT_UNDERFLOW ; 
 int DPLL_ROUNDING_VAL ; 
 int DPLL_SCALE_FACTOR ; 
 int EINVAL ; 
 int INT_MAX ; 
 long LONG_MAX ; 
 long OMAP3PLUS_DPLL_FINT_JTYPE_MAX ; 
 long OMAP3PLUS_DPLL_FINT_JTYPE_MIN ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int __ffs (int) ; 
 char* clk_hw_get_name (struct clk_hw*) ; 
 int /*<<< orphan*/  clk_hw_get_parent (int /*<<< orphan*/ *) ; 
 unsigned long clk_hw_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int stub1 (int /*<<< orphan*/ *) ; 
 int stub2 (int /*<<< orphan*/ *) ; 
 int stub3 (int /*<<< orphan*/ *) ; 
 TYPE_2__* ti_clk_get_features () ; 
 TYPE_1__* ti_clk_ll_ops ; 
 struct clk_hw_omap* to_clk_hw_omap (struct clk_hw*) ; 

__attribute__((used)) static int _dpll_test_fint(struct clk_hw_omap *clk, unsigned int n)
{
	struct dpll_data *dd;
	long fint, fint_min, fint_max;
	int ret = 0;

	dd = clk->dpll_data;

	/* DPLL divider must result in a valid jitter correction val */
	fint = clk_hw_get_rate(clk_hw_get_parent(&clk->hw)) / n;

	if (dd->flags & DPLL_J_TYPE) {
		fint_min = OMAP3PLUS_DPLL_FINT_JTYPE_MIN;
		fint_max = OMAP3PLUS_DPLL_FINT_JTYPE_MAX;
	} else {
		fint_min = ti_clk_get_features()->fint_min;
		fint_max = ti_clk_get_features()->fint_max;
	}

	if (!fint_min || !fint_max) {
		WARN(1, "No fint limits available!\n");
		return DPLL_FINT_INVALID;
	}

	if (fint < ti_clk_get_features()->fint_min) {
		pr_debug("rejecting n=%d due to Fint failure, lowering max_divider\n",
			 n);
		dd->max_divider = n;
		ret = DPLL_FINT_UNDERFLOW;
	} else if (fint > ti_clk_get_features()->fint_max) {
		pr_debug("rejecting n=%d due to Fint failure, boosting min_divider\n",
			 n);
		dd->min_divider = n;
		ret = DPLL_FINT_INVALID;
	} else if (fint > ti_clk_get_features()->fint_band1_max &&
		   fint < ti_clk_get_features()->fint_band2_min) {
		pr_debug("rejecting n=%d due to Fint failure\n", n);
		ret = DPLL_FINT_INVALID;
	}

	return ret;
}

__attribute__((used)) static unsigned long _dpll_compute_new_rate(unsigned long parent_rate,
					    unsigned int m, unsigned int n)
{
	unsigned long long num;

	num = (unsigned long long)parent_rate * m;
	do_div(num, n);
	return num;
}

__attribute__((used)) static int _dpll_test_mult(int *m, int n, unsigned long *new_rate,
			   unsigned long target_rate,
			   unsigned long parent_rate)
{
	int r = 0, carry = 0;

	/* Unscale m and round if necessary */
	if (*m % DPLL_SCALE_FACTOR >= DPLL_ROUNDING_VAL)
		carry = 1;
	*m = (*m / DPLL_SCALE_FACTOR) + carry;

	/*
	 * The new rate must be <= the target rate to avoid programming
	 * a rate that is impossible for the hardware to handle
	 */
	*new_rate = _dpll_compute_new_rate(parent_rate, *m, n);
	if (*new_rate > target_rate) {
		(*m)--;
		*new_rate = 0;
	}

	/* Guard against m underflow */
	if (*m < DPLL_MIN_MULTIPLIER) {
		*m = DPLL_MIN_MULTIPLIER;
		*new_rate = 0;
		r = DPLL_MULT_UNDERFLOW;
	}

	if (*new_rate == 0)
		*new_rate = _dpll_compute_new_rate(parent_rate, *m, n);

	return r;
}

__attribute__((used)) static int _omap2_dpll_is_in_bypass(u32 v)
{
	u8 mask, val;

	mask = ti_clk_get_features()->dpll_bypass_vals;

	/*
	 * Each set bit in the mask corresponds to a bypass value equal
	 * to the bitshift. Go through each set-bit in the mask and
	 * compare against the given register value.
	 */
	while (mask) {
		val = __ffs(mask);
		mask ^= (1 << val);
		if (v == val)
			return 1;
	}

	return 0;
}

u8 omap2_init_dpll_parent(struct clk_hw *hw)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	u32 v;
	struct dpll_data *dd;

	dd = clk->dpll_data;
	if (!dd)
		return -EINVAL;

	v = ti_clk_ll_ops->clk_readl(&dd->control_reg);
	v &= dd->enable_mask;
	v >>= __ffs(dd->enable_mask);

	/* Reparent the struct clk in case the dpll is in bypass */
	if (_omap2_dpll_is_in_bypass(v))
		return 1;

	return 0;
}

unsigned long omap2_get_dpll_rate(struct clk_hw_omap *clk)
{
	u64 dpll_clk;
	u32 dpll_mult, dpll_div, v;
	struct dpll_data *dd;

	dd = clk->dpll_data;
	if (!dd)
		return 0;

	/* Return bypass rate if DPLL is bypassed */
	v = ti_clk_ll_ops->clk_readl(&dd->control_reg);
	v &= dd->enable_mask;
	v >>= __ffs(dd->enable_mask);

	if (_omap2_dpll_is_in_bypass(v))
		return clk_hw_get_rate(dd->clk_bypass);

	v = ti_clk_ll_ops->clk_readl(&dd->mult_div1_reg);
	dpll_mult = v & dd->mult_mask;
	dpll_mult >>= __ffs(dd->mult_mask);
	dpll_div = v & dd->div1_mask;
	dpll_div >>= __ffs(dd->div1_mask);

	dpll_clk = (u64)clk_hw_get_rate(dd->clk_ref) * dpll_mult;
	do_div(dpll_clk, dpll_div + 1);

	return dpll_clk;
}

long omap2_dpll_round_rate(struct clk_hw *hw, unsigned long target_rate,
			   unsigned long *parent_rate)
{
	struct clk_hw_omap *clk = to_clk_hw_omap(hw);
	int m, n, r, scaled_max_m;
	int min_delta_m = INT_MAX, min_delta_n = INT_MAX;
	unsigned long scaled_rt_rp;
	unsigned long new_rate = 0;
	struct dpll_data *dd;
	unsigned long ref_rate;
	long delta;
	long prev_min_delta = LONG_MAX;
	const char *clk_name;

	if (!clk || !clk->dpll_data)
		return ~0;

	dd = clk->dpll_data;

	if (dd->max_rate && target_rate > dd->max_rate)
		target_rate = dd->max_rate;

	ref_rate = clk_hw_get_rate(dd->clk_ref);
	clk_name = clk_hw_get_name(hw);
	pr_debug("clock: %s: starting DPLL round_rate, target rate %lu\n",
		 clk_name, target_rate);

	scaled_rt_rp = target_rate / (ref_rate / DPLL_SCALE_FACTOR);
	scaled_max_m = dd->max_multiplier * DPLL_SCALE_FACTOR;

	dd->last_rounded_rate = 0;

	for (n = dd->min_divider; n <= dd->max_divider; n++) {
		/* Is the (input clk, divider) pair valid for the DPLL? */
		r = _dpll_test_fint(clk, n);
		if (r == DPLL_FINT_UNDERFLOW)
			break;
		else if (r == DPLL_FINT_INVALID)
			continue;

		/* Compute the scaled DPLL multiplier, based on the divider */
		m = scaled_rt_rp * n;

		/*
		 * Since we're counting n up, a m overflow means we
		 * can bail out completely (since as n increases in
		 * the next iteration, there's no way that m can
		 * increase beyond the current m)
		 */
		if (m > scaled_max_m)
			break;

		r = _dpll_test_mult(&m, n, &new_rate, target_rate,
				    ref_rate);

		/* m can't be set low enough for this n - try with a larger n */
		if (r == DPLL_MULT_UNDERFLOW)
			continue;

		/* skip rates above our target rate */
		delta = target_rate - new_rate;
		if (delta < 0)
			continue;

		if (delta < prev_min_delta) {
			prev_min_delta = delta;
			min_delta_m = m;
			min_delta_n = n;
		}

		pr_debug("clock: %s: m = %d: n = %d: new_rate = %lu\n",
			 clk_name, m, n, new_rate);

		if (delta == 0)
			break;
	}

	if (prev_min_delta == LONG_MAX) {
		pr_debug("clock: %s: cannot round to rate %lu\n",
			 clk_name, target_rate);
		return ~0;
	}

	dd->last_rounded_m = min_delta_m;
	dd->last_rounded_n = min_delta_n;
	dd->last_rounded_rate = target_rate - prev_min_delta;

	return dd->last_rounded_rate;
}


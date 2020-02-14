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
struct fapll_synth {int index; scalar_t__ div; scalar_t__ freq; struct fapll_data* fd; } ;
struct fapll_data {scalar_t__ base; int /*<<< orphan*/  name; scalar_t__ bypass_bit_inverted; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 void* DIV_ROUND_UP (unsigned long,int) ; 
 unsigned long DIV_ROUND_UP_ULL (unsigned long,int) ; 
 int EINVAL ; 
 int ETIMEDOUT ; 
 int FAPLL_MAIN_BP ; 
 int FAPLL_MAIN_CLEAR_MASK ; 
 int FAPLL_MAIN_DIV_P_SHIFT ; 
 int FAPLL_MAIN_LOCK ; 
 int FAPLL_MAIN_MAX_MULT_N ; 
 int FAPLL_MAIN_MULT_N_SHIFT ; 
 int FAPLL_MAIN_PLLEN ; 
 int FAPLL_MAX_RETRIES ; 
 scalar_t__ FAPLL_PWD_OFFSET ; 
 int SYNTH_LDFREQ ; 
 int SYNTH_LDMDIV1 ; 
 int SYNTH_MAX_DIV_M ; 
 int SYNTH_MAX_INT_DIV ; 
 int SYNTH_PHASE_K ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int readl_relaxed (scalar_t__) ; 
 struct fapll_data* to_fapll (struct clk_hw*) ; 
 struct fapll_synth* to_synth (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static bool ti_fapll_clock_is_bypass(struct fapll_data *fd)
{
	u32 v = readl_relaxed(fd->base);

	if (fd->bypass_bit_inverted)
		return !(v & FAPLL_MAIN_BP);
	else
		return !!(v & FAPLL_MAIN_BP);
}

__attribute__((used)) static void ti_fapll_set_bypass(struct fapll_data *fd)
{
	u32 v = readl_relaxed(fd->base);

	if (fd->bypass_bit_inverted)
		v &= ~FAPLL_MAIN_BP;
	else
		v |= FAPLL_MAIN_BP;
	writel_relaxed(v, fd->base);
}

__attribute__((used)) static void ti_fapll_clear_bypass(struct fapll_data *fd)
{
	u32 v = readl_relaxed(fd->base);

	if (fd->bypass_bit_inverted)
		v |= FAPLL_MAIN_BP;
	else
		v &= ~FAPLL_MAIN_BP;
	writel_relaxed(v, fd->base);
}

__attribute__((used)) static int ti_fapll_wait_lock(struct fapll_data *fd)
{
	int retries = FAPLL_MAX_RETRIES;
	u32 v;

	while ((v = readl_relaxed(fd->base))) {
		if (v & FAPLL_MAIN_LOCK)
			return 0;

		if (retries-- <= 0)
			break;

		udelay(1);
	}

	pr_err("%s failed to lock\n", fd->name);

	return -ETIMEDOUT;
}

__attribute__((used)) static int ti_fapll_enable(struct clk_hw *hw)
{
	struct fapll_data *fd = to_fapll(hw);
	u32 v = readl_relaxed(fd->base);

	v |= FAPLL_MAIN_PLLEN;
	writel_relaxed(v, fd->base);
	ti_fapll_wait_lock(fd);

	return 0;
}

__attribute__((used)) static void ti_fapll_disable(struct clk_hw *hw)
{
	struct fapll_data *fd = to_fapll(hw);
	u32 v = readl_relaxed(fd->base);

	v &= ~FAPLL_MAIN_PLLEN;
	writel_relaxed(v, fd->base);
}

__attribute__((used)) static int ti_fapll_is_enabled(struct clk_hw *hw)
{
	struct fapll_data *fd = to_fapll(hw);
	u32 v = readl_relaxed(fd->base);

	return v & FAPLL_MAIN_PLLEN;
}

__attribute__((used)) static unsigned long ti_fapll_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	struct fapll_data *fd = to_fapll(hw);
	u32 fapll_n, fapll_p, v;
	u64 rate;

	if (ti_fapll_clock_is_bypass(fd))
		return parent_rate;

	rate = parent_rate;

	/* PLL pre-divider is P and multiplier is N */
	v = readl_relaxed(fd->base);
	fapll_p = (v >> 8) & 0xff;
	if (fapll_p)
		do_div(rate, fapll_p);
	fapll_n = v >> 16;
	if (fapll_n)
		rate *= fapll_n;

	return rate;
}

__attribute__((used)) static u8 ti_fapll_get_parent(struct clk_hw *hw)
{
	struct fapll_data *fd = to_fapll(hw);

	if (ti_fapll_clock_is_bypass(fd))
		return 1;

	return 0;
}

__attribute__((used)) static int ti_fapll_set_div_mult(unsigned long rate,
				 unsigned long parent_rate,
				 u32 *pre_div_p, u32 *mult_n)
{
	/*
	 * So far no luck getting decent clock with PLL divider,
	 * PLL does not seem to lock and the signal does not look
	 * right. It seems the divider can only be used together
	 * with the multiplier?
	 */
	if (rate < parent_rate) {
		pr_warn("FAPLL main divider rates unsupported\n");
		return -EINVAL;
	}

	*mult_n = rate / parent_rate;
	if (*mult_n > FAPLL_MAIN_MAX_MULT_N)
		return -EINVAL;
	*pre_div_p = 1;

	return 0;
}

__attribute__((used)) static long ti_fapll_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *parent_rate)
{
	u32 pre_div_p, mult_n;
	int error;

	if (!rate)
		return -EINVAL;

	error = ti_fapll_set_div_mult(rate, *parent_rate,
				      &pre_div_p, &mult_n);
	if (error)
		return error;

	rate = *parent_rate / pre_div_p;
	rate *= mult_n;

	return rate;
}

__attribute__((used)) static int ti_fapll_set_rate(struct clk_hw *hw, unsigned long rate,
			     unsigned long parent_rate)
{
	struct fapll_data *fd = to_fapll(hw);
	u32 pre_div_p, mult_n, v;
	int error;

	if (!rate)
		return -EINVAL;

	error = ti_fapll_set_div_mult(rate, parent_rate,
				      &pre_div_p, &mult_n);
	if (error)
		return error;

	ti_fapll_set_bypass(fd);
	v = readl_relaxed(fd->base);
	v &= ~FAPLL_MAIN_CLEAR_MASK;
	v |= pre_div_p << FAPLL_MAIN_DIV_P_SHIFT;
	v |= mult_n << FAPLL_MAIN_MULT_N_SHIFT;
	writel_relaxed(v, fd->base);
	if (ti_fapll_is_enabled(hw))
		ti_fapll_wait_lock(fd);
	ti_fapll_clear_bypass(fd);

	return 0;
}

__attribute__((used)) static int ti_fapll_synth_enable(struct clk_hw *hw)
{
	struct fapll_synth *synth = to_synth(hw);
	u32 v = readl_relaxed(synth->fd->base + FAPLL_PWD_OFFSET);

	v &= ~(1 << synth->index);
	writel_relaxed(v, synth->fd->base + FAPLL_PWD_OFFSET);

	return 0;
}

__attribute__((used)) static void ti_fapll_synth_disable(struct clk_hw *hw)
{
	struct fapll_synth *synth = to_synth(hw);
	u32 v = readl_relaxed(synth->fd->base + FAPLL_PWD_OFFSET);

	v |= 1 << synth->index;
	writel_relaxed(v, synth->fd->base + FAPLL_PWD_OFFSET);
}

__attribute__((used)) static int ti_fapll_synth_is_enabled(struct clk_hw *hw)
{
	struct fapll_synth *synth = to_synth(hw);
	u32 v = readl_relaxed(synth->fd->base + FAPLL_PWD_OFFSET);

	return !(v & (1 << synth->index));
}

__attribute__((used)) static unsigned long ti_fapll_synth_recalc_rate(struct clk_hw *hw,
						unsigned long parent_rate)
{
	struct fapll_synth *synth = to_synth(hw);
	u32 synth_div_m;
	u64 rate;

	/* The audio_pll_clk1 is hardwired to produce 32.768KiHz clock */
	if (!synth->div)
		return 32768;

	/*
	 * PLL in bypass sets the synths in bypass mode too. The PLL rate
	 * can be also be set to 27MHz, so we can't use parent_rate to
	 * check for bypass mode.
	 */
	if (ti_fapll_clock_is_bypass(synth->fd))
		return parent_rate;

	rate = parent_rate;

	/*
	 * Synth frequency integer and fractional divider.
	 * Note that the phase output K is 8, so the result needs
	 * to be multiplied by SYNTH_PHASE_K.
	 */
	if (synth->freq) {
		u32 v, synth_int_div, synth_frac_div, synth_div_freq;

		v = readl_relaxed(synth->freq);
		synth_int_div = (v >> 24) & 0xf;
		synth_frac_div = v & 0xffffff;
		synth_div_freq = (synth_int_div * 10000000) + synth_frac_div;
		rate *= 10000000;
		do_div(rate, synth_div_freq);
		rate *= SYNTH_PHASE_K;
	}

	/* Synth post-divider M */
	synth_div_m = readl_relaxed(synth->div) & SYNTH_MAX_DIV_M;

	return DIV_ROUND_UP_ULL(rate, synth_div_m);
}

__attribute__((used)) static unsigned long ti_fapll_synth_get_frac_rate(struct clk_hw *hw,
						  unsigned long parent_rate)
{
	struct fapll_synth *synth = to_synth(hw);
	unsigned long current_rate, frac_rate;
	u32 post_div_m;

	current_rate = ti_fapll_synth_recalc_rate(hw, parent_rate);
	post_div_m = readl_relaxed(synth->div) & SYNTH_MAX_DIV_M;
	frac_rate = current_rate * post_div_m;

	return frac_rate;
}

__attribute__((used)) static u32 ti_fapll_synth_set_frac_rate(struct fapll_synth *synth,
					unsigned long rate,
					unsigned long parent_rate)
{
	u32 post_div_m, synth_int_div = 0, synth_frac_div = 0, v;

	post_div_m = DIV_ROUND_UP_ULL((u64)parent_rate * SYNTH_PHASE_K, rate);
	post_div_m = post_div_m / SYNTH_MAX_INT_DIV;
	if (post_div_m > SYNTH_MAX_DIV_M)
		return -EINVAL;
	if (!post_div_m)
		post_div_m = 1;

	for (; post_div_m < SYNTH_MAX_DIV_M; post_div_m++) {
		synth_int_div = DIV_ROUND_UP_ULL((u64)parent_rate *
						 SYNTH_PHASE_K *
						 10000000,
						 rate * post_div_m);
		synth_frac_div = synth_int_div % 10000000;
		synth_int_div /= 10000000;

		if (synth_int_div <= SYNTH_MAX_INT_DIV)
			break;
	}

	if (synth_int_div > SYNTH_MAX_INT_DIV)
		return -EINVAL;

	v = readl_relaxed(synth->freq);
	v &= ~0x1fffffff;
	v |= (synth_int_div & SYNTH_MAX_INT_DIV) << 24;
	v |= (synth_frac_div & 0xffffff);
	v |= SYNTH_LDFREQ;
	writel_relaxed(v, synth->freq);

	return post_div_m;
}

__attribute__((used)) static long ti_fapll_synth_round_rate(struct clk_hw *hw, unsigned long rate,
				      unsigned long *parent_rate)
{
	struct fapll_synth *synth = to_synth(hw);
	struct fapll_data *fd = synth->fd;
	unsigned long r;

	if (ti_fapll_clock_is_bypass(fd) || !synth->div || !rate)
		return -EINVAL;

	/* Only post divider m available with no fractional divider? */
	if (!synth->freq) {
		unsigned long frac_rate;
		u32 synth_post_div_m;

		frac_rate = ti_fapll_synth_get_frac_rate(hw, *parent_rate);
		synth_post_div_m = DIV_ROUND_UP(frac_rate, rate);
		r = DIV_ROUND_UP(frac_rate, synth_post_div_m);
		goto out;
	}

	r = *parent_rate * SYNTH_PHASE_K;
	if (rate > r)
		goto out;

	r = DIV_ROUND_UP_ULL(r, SYNTH_MAX_INT_DIV * SYNTH_MAX_DIV_M);
	if (rate < r)
		goto out;

	r = rate;
out:
	return r;
}

__attribute__((used)) static int ti_fapll_synth_set_rate(struct clk_hw *hw, unsigned long rate,
				   unsigned long parent_rate)
{
	struct fapll_synth *synth = to_synth(hw);
	struct fapll_data *fd = synth->fd;
	unsigned long frac_rate, post_rate = 0;
	u32 post_div_m = 0, v;

	if (ti_fapll_clock_is_bypass(fd) || !synth->div || !rate)
		return -EINVAL;

	/* Produce the rate with just post divider M? */
	frac_rate = ti_fapll_synth_get_frac_rate(hw, parent_rate);
	if (frac_rate < rate) {
		if (!synth->freq)
			return -EINVAL;
	} else {
		post_div_m = DIV_ROUND_UP(frac_rate, rate);
		if (post_div_m && (post_div_m <= SYNTH_MAX_DIV_M))
			post_rate = DIV_ROUND_UP(frac_rate, post_div_m);
		if (!synth->freq && !post_rate)
			return -EINVAL;
	}

	/* Need to recalculate the fractional divider? */
	if ((post_rate != rate) && synth->freq)
		post_div_m = ti_fapll_synth_set_frac_rate(synth,
							  rate,
							  parent_rate);

	v = readl_relaxed(synth->div);
	v &= ~SYNTH_MAX_DIV_M;
	v |= post_div_m;
	v |= SYNTH_LDMDIV1;
	writel_relaxed(v, synth->div);

	return 0;
}


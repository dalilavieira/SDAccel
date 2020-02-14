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
typedef  unsigned int uint64_t ;
typedef  int u8 ;
typedef  unsigned int u64 ;
struct regmap {int dummy; } ;
struct parm {unsigned int shift; int /*<<< orphan*/  width; int /*<<< orphan*/  reg_off; } ;
struct meson_clk_mpll_data {int flags; scalar_t__ lock; struct parm misc; struct parm n2; struct parm ssen; struct parm sdm_en; struct parm sdm; } ;
struct clk_regmap_mux_data {int dummy; } ;
struct clk_regmap_gate_data {int dummy; } ;
struct clk_regmap_div_data {int dummy; } ;
struct clk_regmap {struct regmap* map; scalar_t__ data; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int CLK_MESON_MPLL_ROUND_CLOSEST ; 
 unsigned int DIV_ROUND_CLOSEST_ULL (unsigned int,unsigned long) ; 
 long DIV_ROUND_UP_ULL (unsigned int,unsigned long) ; 
 long EINVAL ; 
 scalar_t__ MESON_PARM_APPLICABLE (struct parm*) ; 
 unsigned int N2_MAX ; 
 unsigned int N2_MIN ; 
 unsigned int PARM_GET (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 unsigned int SDM_DEN ; 
 int /*<<< orphan*/  SETPMASK (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  __acquire (scalar_t__) ; 
 int /*<<< orphan*/  __release (scalar_t__) ; 
 unsigned int do_div (unsigned int,unsigned long) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (scalar_t__,unsigned long) ; 
 struct clk_regmap* to_clk_regmap (struct clk_hw*) ; 

__attribute__((used)) static inline struct clk_regmap_gate_data *
clk_get_regmap_gate_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_gate_data *)clk->data;
}

__attribute__((used)) static inline struct clk_regmap_div_data *
clk_get_regmap_div_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_div_data *)clk->data;
}

__attribute__((used)) static inline struct clk_regmap_mux_data *
clk_get_regmap_mux_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_mux_data *)clk->data;
}

__attribute__((used)) static inline unsigned int meson_parm_read(struct regmap *map, struct parm *p)
{
	unsigned int val;

	regmap_read(map, p->reg_off, &val);
	return PARM_GET(p->width, p->shift, val);
}

__attribute__((used)) static inline void meson_parm_write(struct regmap *map, struct parm *p,
				    unsigned int val)
{
	regmap_update_bits(map, p->reg_off, SETPMASK(p->width, p->shift),
			   val << p->shift);
}

__attribute__((used)) static inline struct meson_clk_mpll_data *
meson_clk_mpll_data(struct clk_regmap *clk)
{
	return (struct meson_clk_mpll_data *)clk->data;
}

__attribute__((used)) static long rate_from_params(unsigned long parent_rate,
			     unsigned int sdm,
			     unsigned int n2)
{
	unsigned long divisor = (SDM_DEN * n2) + sdm;

	if (n2 < N2_MIN)
		return -EINVAL;

	return DIV_ROUND_UP_ULL((u64)parent_rate * SDM_DEN, divisor);
}

__attribute__((used)) static void params_from_rate(unsigned long requested_rate,
			     unsigned long parent_rate,
			     unsigned int *sdm,
			     unsigned int *n2,
			     u8 flags)
{
	uint64_t div = parent_rate;
	uint64_t frac = do_div(div, requested_rate);

	frac *= SDM_DEN;

	if (flags & CLK_MESON_MPLL_ROUND_CLOSEST)
		*sdm = DIV_ROUND_CLOSEST_ULL(frac, requested_rate);
	else
		*sdm = DIV_ROUND_UP_ULL(frac, requested_rate);

	if (*sdm == SDM_DEN) {
		*sdm = 0;
		div += 1;
	}

	if (div < N2_MIN) {
		*n2 = N2_MIN;
		*sdm = 0;
	} else if (div > N2_MAX) {
		*n2 = N2_MAX;
		*sdm = SDM_DEN - 1;
	} else {
		*n2 = div;
	}
}

__attribute__((used)) static unsigned long mpll_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_mpll_data *mpll = meson_clk_mpll_data(clk);
	unsigned int sdm, n2;
	long rate;

	sdm = meson_parm_read(clk->map, &mpll->sdm);
	n2 = meson_parm_read(clk->map, &mpll->n2);

	rate = rate_from_params(parent_rate, sdm, n2);
	return rate < 0 ? 0 : rate;
}

__attribute__((used)) static long mpll_round_rate(struct clk_hw *hw,
			    unsigned long rate,
			    unsigned long *parent_rate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_mpll_data *mpll = meson_clk_mpll_data(clk);
	unsigned int sdm, n2;

	params_from_rate(rate, *parent_rate, &sdm, &n2, mpll->flags);
	return rate_from_params(*parent_rate, sdm, n2);
}

__attribute__((used)) static int mpll_set_rate(struct clk_hw *hw,
			 unsigned long rate,
			 unsigned long parent_rate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_clk_mpll_data *mpll = meson_clk_mpll_data(clk);
	unsigned int sdm, n2;
	unsigned long flags = 0;

	params_from_rate(rate, parent_rate, &sdm, &n2, mpll->flags);

	if (mpll->lock)
		spin_lock_irqsave(mpll->lock, flags);
	else
		__acquire(mpll->lock);

	/* Enable and set the fractional part */
	meson_parm_write(clk->map, &mpll->sdm, sdm);
	meson_parm_write(clk->map, &mpll->sdm_en, 1);

	/* Set additional fractional part enable if required */
	if (MESON_PARM_APPLICABLE(&mpll->ssen))
		meson_parm_write(clk->map, &mpll->ssen, 1);

	/* Set the integer divider part */
	meson_parm_write(clk->map, &mpll->n2, n2);

	/* Set the magic misc bit if required */
	if (MESON_PARM_APPLICABLE(&mpll->misc))
		meson_parm_write(clk->map, &mpll->misc, 1);

	if (mpll->lock)
		spin_unlock_irqrestore(mpll->lock, flags);
	else
		__release(mpll->lock);

	return 0;
}


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
typedef  unsigned int u8 ;
typedef  unsigned int u32 ;
typedef  unsigned int u16 ;
struct regmap {int dummy; } ;
struct clk_pll_layout {unsigned int pllr_mask; unsigned int mul_mask; unsigned int mul_shift; } ;
struct TYPE_3__ {unsigned long min; unsigned long max; } ;
struct clk_pll_characteristics {unsigned int* out; unsigned int* icpll; int num_output; TYPE_2__* output; TYPE_1__ input; } ;
struct clk_pll {unsigned int id; unsigned int div; unsigned int mul; size_t range; struct clk_pll_characteristics* characteristics; struct clk_pll_layout* layout; struct regmap* regmap; } ;
struct clk_hw {int dummy; } ;
struct TYPE_4__ {long min; long max; } ;

/* Variables and functions */
 int AT91_PMC_PLLICPR ; 
 int AT91_PMC_SR ; 
 unsigned long DIV_ROUND_CLOSEST (unsigned long,unsigned long) ; 
 unsigned long DIV_ROUND_UP (unsigned long,unsigned long) ; 
 long ERANGE ; 
 unsigned int PLL_COUNT_SHIFT ; 
 unsigned int PLL_DIV (unsigned int) ; 
 unsigned long PLL_DIV_MAX ; 
 unsigned int PLL_ICPR_MASK (unsigned int) ; 
 unsigned int PLL_ICPR_SHIFT (unsigned int) ; 
 unsigned int PLL_MAX_COUNT ; 
 unsigned int PLL_MUL (unsigned int,struct clk_pll_layout const*) ; 
 unsigned long PLL_MUL_MAX (struct clk_pll_layout const*) ; 
 unsigned long PLL_MUL_MIN ; 
 unsigned int PLL_OUT_SHIFT ; 
 int PLL_REG (unsigned int) ; 
 unsigned int PLL_STATUS_MASK (unsigned int) ; 
 unsigned long ULONG_MAX ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int,unsigned int,unsigned int) ; 
 struct clk_pll* to_clk_pll (struct clk_hw*) ; 

__attribute__((used)) static inline void pmc_register_id(u8 id) {}

__attribute__((used)) static inline void pmc_register_pck(u8 pck) {}

__attribute__((used)) static inline bool clk_pll_ready(struct regmap *regmap, int id)
{
	unsigned int status;

	regmap_read(regmap, AT91_PMC_SR, &status);

	return status & PLL_STATUS_MASK(id) ? 1 : 0;
}

__attribute__((used)) static int clk_pll_prepare(struct clk_hw *hw)
{
	struct clk_pll *pll = to_clk_pll(hw);
	struct regmap *regmap = pll->regmap;
	const struct clk_pll_layout *layout = pll->layout;
	const struct clk_pll_characteristics *characteristics =
							pll->characteristics;
	u8 id = pll->id;
	u32 mask = PLL_STATUS_MASK(id);
	int offset = PLL_REG(id);
	u8 out = 0;
	unsigned int pllr;
	unsigned int status;
	u8 div;
	u16 mul;

	regmap_read(regmap, offset, &pllr);
	div = PLL_DIV(pllr);
	mul = PLL_MUL(pllr, layout);

	regmap_read(regmap, AT91_PMC_SR, &status);
	if ((status & mask) &&
	    (div == pll->div && mul == pll->mul))
		return 0;

	if (characteristics->out)
		out = characteristics->out[pll->range];

	if (characteristics->icpll)
		regmap_update_bits(regmap, AT91_PMC_PLLICPR, PLL_ICPR_MASK(id),
			characteristics->icpll[pll->range] << PLL_ICPR_SHIFT(id));

	regmap_update_bits(regmap, offset, layout->pllr_mask,
			pll->div | (PLL_MAX_COUNT << PLL_COUNT_SHIFT) |
			(out << PLL_OUT_SHIFT) |
			((pll->mul & layout->mul_mask) << layout->mul_shift));

	while (!clk_pll_ready(regmap, pll->id))
		cpu_relax();

	return 0;
}

__attribute__((used)) static int clk_pll_is_prepared(struct clk_hw *hw)
{
	struct clk_pll *pll = to_clk_pll(hw);

	return clk_pll_ready(pll->regmap, pll->id);
}

__attribute__((used)) static void clk_pll_unprepare(struct clk_hw *hw)
{
	struct clk_pll *pll = to_clk_pll(hw);
	unsigned int mask = pll->layout->pllr_mask;

	regmap_update_bits(pll->regmap, PLL_REG(pll->id), mask, ~mask);
}

__attribute__((used)) static unsigned long clk_pll_recalc_rate(struct clk_hw *hw,
					 unsigned long parent_rate)
{
	struct clk_pll *pll = to_clk_pll(hw);

	if (!pll->div || !pll->mul)
		return 0;

	return (parent_rate / pll->div) * (pll->mul + 1);
}

__attribute__((used)) static long clk_pll_get_best_div_mul(struct clk_pll *pll, unsigned long rate,
				     unsigned long parent_rate,
				     u32 *div, u32 *mul,
				     u32 *index) {
	const struct clk_pll_layout *layout = pll->layout;
	const struct clk_pll_characteristics *characteristics =
							pll->characteristics;
	unsigned long bestremainder = ULONG_MAX;
	unsigned long maxdiv, mindiv, tmpdiv;
	long bestrate = -ERANGE;
	unsigned long bestdiv;
	unsigned long bestmul;
	int i = 0;

	/* Check if parent_rate is a valid input rate */
	if (parent_rate < characteristics->input.min)
		return -ERANGE;

	/*
	 * Calculate minimum divider based on the minimum multiplier, the
	 * parent_rate and the requested rate.
	 * Should always be 2 according to the input and output characteristics
	 * of the PLL blocks.
	 */
	mindiv = (parent_rate * PLL_MUL_MIN) / rate;
	if (!mindiv)
		mindiv = 1;

	if (parent_rate > characteristics->input.max) {
		tmpdiv = DIV_ROUND_UP(parent_rate, characteristics->input.max);
		if (tmpdiv > PLL_DIV_MAX)
			return -ERANGE;

		if (tmpdiv > mindiv)
			mindiv = tmpdiv;
	}

	/*
	 * Calculate the maximum divider which is limited by PLL register
	 * layout (limited by the MUL or DIV field size).
	 */
	maxdiv = DIV_ROUND_UP(parent_rate * PLL_MUL_MAX(layout), rate);
	if (maxdiv > PLL_DIV_MAX)
		maxdiv = PLL_DIV_MAX;

	/*
	 * Iterate over the acceptable divider values to find the best
	 * divider/multiplier pair (the one that generates the closest
	 * rate to the requested one).
	 */
	for (tmpdiv = mindiv; tmpdiv <= maxdiv; tmpdiv++) {
		unsigned long remainder;
		unsigned long tmprate;
		unsigned long tmpmul;

		/*
		 * Calculate the multiplier associated with the current
		 * divider that provide the closest rate to the requested one.
		 */
		tmpmul = DIV_ROUND_CLOSEST(rate, parent_rate / tmpdiv);
		tmprate = (parent_rate / tmpdiv) * tmpmul;
		if (tmprate > rate)
			remainder = tmprate - rate;
		else
			remainder = rate - tmprate;

		/*
		 * Compare the remainder with the best remainder found until
		 * now and elect a new best multiplier/divider pair if the
		 * current remainder is smaller than the best one.
		 */
		if (remainder < bestremainder) {
			bestremainder = remainder;
			bestdiv = tmpdiv;
			bestmul = tmpmul;
			bestrate = tmprate;
		}

		/*
		 * We've found a perfect match!
		 * Stop searching now and use this multiplier/divider pair.
		 */
		if (!remainder)
			break;
	}

	/* We haven't found any multiplier/divider pair => return -ERANGE */
	if (bestrate < 0)
		return bestrate;

	/* Check if bestrate is a valid output rate  */
	for (i = 0; i < characteristics->num_output; i++) {
		if (bestrate >= characteristics->output[i].min &&
		    bestrate <= characteristics->output[i].max)
			break;
	}

	if (i >= characteristics->num_output)
		return -ERANGE;

	if (div)
		*div = bestdiv;
	if (mul)
		*mul = bestmul - 1;
	if (index)
		*index = i;

	return bestrate;
}

__attribute__((used)) static long clk_pll_round_rate(struct clk_hw *hw, unsigned long rate,
					unsigned long *parent_rate)
{
	struct clk_pll *pll = to_clk_pll(hw);

	return clk_pll_get_best_div_mul(pll, rate, *parent_rate,
					NULL, NULL, NULL);
}

__attribute__((used)) static int clk_pll_set_rate(struct clk_hw *hw, unsigned long rate,
			    unsigned long parent_rate)
{
	struct clk_pll *pll = to_clk_pll(hw);
	long ret;
	u32 div;
	u32 mul;
	u32 index;

	ret = clk_pll_get_best_div_mul(pll, rate, parent_rate,
				       &div, &mul, &index);
	if (ret < 0)
		return ret;

	pll->range = index;
	pll->div = div;
	pll->mul = mul;

	return 0;
}


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
typedef  int /*<<< orphan*/  u64 ;
struct regmap {int dummy; } ;
struct parm {int width; unsigned int shift; int /*<<< orphan*/  reg_off; } ;
struct clk_duty {int num; int den; } ;
struct meson_sclk_div_data {int cached_div; struct clk_duty cached_duty; struct parm div; struct parm hi; } ;
struct clk_regmap_mux_data {int dummy; } ;
struct clk_regmap_gate_data {int dummy; } ;
struct clk_regmap_div_data {int dummy; } ;
struct clk_regmap {struct regmap* map; scalar_t__ data; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int CLK_SET_RATE_PARENT ; 
 unsigned int DIV_ROUND_CLOSEST (int,int) ; 
 int DIV_ROUND_CLOSEST_ULL (int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long DIV_ROUND_UP_ULL (int /*<<< orphan*/ ,int) ; 
 scalar_t__ MESON_PARM_APPLICABLE (struct parm*) ; 
 unsigned int PARM_GET (int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  SETPMASK (int,unsigned int) ; 
 unsigned long ULONG_MAX ; 
 scalar_t__ abs (unsigned long) ; 
 int clamp (int,int,int) ; 
 int clk_hw_get_flags (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent (struct clk_hw*) ; 
 scalar_t__ clk_hw_is_enabled (struct clk_hw*) ; 
 unsigned long clk_hw_round_rate (struct clk_hw*,unsigned long) ; 
 int /*<<< orphan*/  memcpy (struct clk_duty*,struct clk_duty*,int) ; 
 unsigned long min (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
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

__attribute__((used)) static inline struct meson_sclk_div_data *
meson_sclk_div_data(struct clk_regmap *clk)
{
	return (struct meson_sclk_div_data *)clk->data;
}

__attribute__((used)) static int sclk_div_maxval(struct meson_sclk_div_data *sclk)
{
	return (1 << sclk->div.width) - 1;
}

__attribute__((used)) static int sclk_div_maxdiv(struct meson_sclk_div_data *sclk)
{
	return sclk_div_maxval(sclk) + 1;
}

__attribute__((used)) static int sclk_div_getdiv(struct clk_hw *hw, unsigned long rate,
			   unsigned long prate, int maxdiv)
{
	int div = DIV_ROUND_CLOSEST_ULL((u64)prate, rate);

	return clamp(div, 2, maxdiv);
}

__attribute__((used)) static int sclk_div_bestdiv(struct clk_hw *hw, unsigned long rate,
			    unsigned long *prate,
			    struct meson_sclk_div_data *sclk)
{
	struct clk_hw *parent = clk_hw_get_parent(hw);
	int bestdiv = 0, i;
	unsigned long maxdiv, now, parent_now;
	unsigned long best = 0, best_parent = 0;

	if (!rate)
		rate = 1;

	maxdiv = sclk_div_maxdiv(sclk);

	if (!(clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT))
		return sclk_div_getdiv(hw, rate, *prate, maxdiv);

	/*
	 * The maximum divider we can use without overflowing
	 * unsigned long in rate * i below
	 */
	maxdiv = min(ULONG_MAX / rate, maxdiv);

	for (i = 2; i <= maxdiv; i++) {
		/*
		 * It's the most ideal case if the requested rate can be
		 * divided from parent clock without needing to change
		 * parent rate, so return the divider immediately.
		 */
		if (rate * i == *prate)
			return i;

		parent_now = clk_hw_round_rate(parent, rate * i);
		now = DIV_ROUND_UP_ULL((u64)parent_now, i);

		if (abs(rate - now) < abs(rate - best)) {
			bestdiv = i;
			best = now;
			best_parent = parent_now;
		}
	}

	if (!bestdiv)
		bestdiv = sclk_div_maxdiv(sclk);
	else
		*prate = best_parent;

	return bestdiv;
}

__attribute__((used)) static long sclk_div_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *prate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);
	int div;

	div = sclk_div_bestdiv(hw, rate, prate, sclk);

	return DIV_ROUND_UP_ULL((u64)*prate, div);
}

__attribute__((used)) static void sclk_apply_ratio(struct clk_regmap *clk,
			     struct meson_sclk_div_data *sclk)
{
	unsigned int hi = DIV_ROUND_CLOSEST(sclk->cached_div *
					    sclk->cached_duty.num,
					    sclk->cached_duty.den);

	if (hi)
		hi -= 1;

	meson_parm_write(clk->map, &sclk->hi, hi);
}

__attribute__((used)) static int sclk_div_set_duty_cycle(struct clk_hw *hw,
				   struct clk_duty *duty)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);

	if (MESON_PARM_APPLICABLE(&sclk->hi)) {
		memcpy(&sclk->cached_duty, duty, sizeof(*duty));
		sclk_apply_ratio(clk, sclk);
	}

	return 0;
}

__attribute__((used)) static int sclk_div_get_duty_cycle(struct clk_hw *hw,
				   struct clk_duty *duty)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);
	int hi;

	if (!MESON_PARM_APPLICABLE(&sclk->hi)) {
		duty->num = 1;
		duty->den = 2;
		return 0;
	}

	hi = meson_parm_read(clk->map, &sclk->hi);
	duty->num = hi + 1;
	duty->den = sclk->cached_div;
	return 0;
}

__attribute__((used)) static void sclk_apply_divider(struct clk_regmap *clk,
			       struct meson_sclk_div_data *sclk)
{
	if (MESON_PARM_APPLICABLE(&sclk->hi))
		sclk_apply_ratio(clk, sclk);

	meson_parm_write(clk->map, &sclk->div, sclk->cached_div - 1);
}

__attribute__((used)) static int sclk_div_set_rate(struct clk_hw *hw, unsigned long rate,
			     unsigned long prate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);
	unsigned long maxdiv = sclk_div_maxdiv(sclk);

	sclk->cached_div = sclk_div_getdiv(hw, rate, prate, maxdiv);

	if (clk_hw_is_enabled(hw))
		sclk_apply_divider(clk, sclk);

	return 0;
}

__attribute__((used)) static unsigned long sclk_div_recalc_rate(struct clk_hw *hw,
					  unsigned long prate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);

	return DIV_ROUND_UP_ULL((u64)prate, sclk->cached_div);
}

__attribute__((used)) static int sclk_div_enable(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);

	sclk_apply_divider(clk, sclk);

	return 0;
}

__attribute__((used)) static void sclk_div_disable(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);

	meson_parm_write(clk->map, &sclk->div, 0);
}

__attribute__((used)) static int sclk_div_is_enabled(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);

	if (meson_parm_read(clk->map, &sclk->div))
		return 1;

	return 0;
}

__attribute__((used)) static void sclk_div_init(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct meson_sclk_div_data *sclk = meson_sclk_div_data(clk);
	unsigned int val;

	val = meson_parm_read(clk->map, &sclk->div);

	/* if the divider is initially disabled, assume max */
	if (!val)
		sclk->cached_div = sclk_div_maxdiv(sclk);
	else
		sclk->cached_div = val + 1;

	sclk_div_get_duty_cycle(hw, &sclk->cached_duty);
}


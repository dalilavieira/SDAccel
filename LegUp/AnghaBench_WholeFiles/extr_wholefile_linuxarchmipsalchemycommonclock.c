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
struct clk_rate_request {long rate; long best_parent_rate; struct clk_hw* best_parent_hw; } ;
struct clk_hw {int dummy; } ;
struct alchemy_fgcs_clk {int shift; int parent; int isen; int /*<<< orphan*/  reg; int /*<<< orphan*/  reglock; } ;
struct alchemy_auxpll_clk {unsigned long maxmult; int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 scalar_t__ ALCHEMY_CPU_AU1300 ; 
 int /*<<< orphan*/  AU1000_SYS_CPUPLL ; 
 int EINVAL ; 
 long INT_MAX ; 
 scalar_t__ alchemy_get_cputype () ; 
 int alchemy_rdsys (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alchemy_wrsys (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  au1xxx_cpu_has_pll_wo () ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int) ; 
 long clk_hw_get_rate (struct clk_hw*) ; 
 int /*<<< orphan*/  clk_hw_is_prepared (struct clk_hw*) ; 
 long clk_hw_round_rate (struct clk_hw*,long) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 
 struct alchemy_auxpll_clk* to_auxpll_clk (struct clk_hw*) ; 
 struct alchemy_fgcs_clk* to_fgcs_clk (struct clk_hw*) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long alchemy_clk_cpu_recalc(struct clk_hw *hw,
					    unsigned long parent_rate)
{
	unsigned long t;

	/*
	 * On early Au1000, sys_cpupll was write-only. Since these
	 * silicon versions of Au1000 are not sold, we don't bend
	 * over backwards trying to determine the frequency.
	 */
	if (unlikely(au1xxx_cpu_has_pll_wo()))
		t = 396000000;
	else {
		t = alchemy_rdsys(AU1000_SYS_CPUPLL) & 0x7f;
		if (alchemy_get_cputype() < ALCHEMY_CPU_AU1300)
			t &= 0x3f;
		t *= parent_rate;
	}

	return t;
}

__attribute__((used)) static unsigned long alchemy_clk_aux_recalc(struct clk_hw *hw,
					    unsigned long parent_rate)
{
	struct alchemy_auxpll_clk *a = to_auxpll_clk(hw);

	return (alchemy_rdsys(a->reg) & 0xff) * parent_rate;
}

__attribute__((used)) static int alchemy_clk_aux_setr(struct clk_hw *hw,
				unsigned long rate,
				unsigned long parent_rate)
{
	struct alchemy_auxpll_clk *a = to_auxpll_clk(hw);
	unsigned long d = rate;

	if (rate)
		d /= parent_rate;
	else
		d = 0;

	/* minimum is 84MHz, max is 756-1032 depending on variant */
	if (((d < 7) && (d != 0)) || (d > a->maxmult))
		return -EINVAL;

	alchemy_wrsys(d, a->reg);
	return 0;
}

__attribute__((used)) static long alchemy_clk_aux_roundr(struct clk_hw *hw,
					    unsigned long rate,
					    unsigned long *parent_rate)
{
	struct alchemy_auxpll_clk *a = to_auxpll_clk(hw);
	unsigned long mult;

	if (!rate || !*parent_rate)
		return 0;

	mult = rate / (*parent_rate);

	if (mult && (mult < 7))
		mult = 7;
	if (mult > a->maxmult)
		mult = a->maxmult;

	return (*parent_rate) * mult;
}

__attribute__((used)) static long alchemy_calc_div(unsigned long rate, unsigned long prate,
			       int scale, int maxdiv, unsigned long *rv)
{
	long div1, div2;

	div1 = prate / rate;
	if ((prate / div1) > rate)
		div1++;

	if (scale == 2) {	/* only div-by-multiple-of-2 possible */
		if (div1 & 1)
			div1++;	/* stay <=prate */
	}

	div2 = (div1 / scale) - 1;	/* value to write to register */

	if (div2 > maxdiv)
		div2 = maxdiv;
	if (rv)
		*rv = div2;

	div1 = ((div2 + 1) * scale);
	return div1;
}

__attribute__((used)) static int alchemy_clk_fgcs_detr(struct clk_hw *hw,
				 struct clk_rate_request *req,
				 int scale, int maxdiv)
{
	struct clk_hw *pc, *bpc, *free;
	long tdv, tpr, pr, nr, br, bpr, diff, lastdiff;
	int j;

	lastdiff = INT_MAX;
	bpr = 0;
	bpc = NULL;
	br = -EINVAL;
	free = NULL;

	/* look at the rates each enabled parent supplies and select
	 * the one that gets closest to but not over the requested rate.
	 */
	for (j = 0; j < 7; j++) {
		pc = clk_hw_get_parent_by_index(hw, j);
		if (!pc)
			break;

		/* if this parent is currently unused, remember it.
		 * XXX: we would actually want clk_has_active_children()
		 * but this is a good-enough approximation for now.
		 */
		if (!clk_hw_is_prepared(pc)) {
			if (!free)
				free = pc;
		}

		pr = clk_hw_get_rate(pc);
		if (pr < req->rate)
			continue;

		/* what can hardware actually provide */
		tdv = alchemy_calc_div(req->rate, pr, scale, maxdiv, NULL);
		nr = pr / tdv;
		diff = req->rate - nr;
		if (nr > req->rate)
			continue;

		if (diff < lastdiff) {
			lastdiff = diff;
			bpr = pr;
			bpc = pc;
			br = nr;
		}
		if (diff == 0)
			break;
	}

	/* if we couldn't get the exact rate we wanted from the enabled
	 * parents, maybe we can tell an available disabled/inactive one
	 * to give us a rate we can divide down to the requested rate.
	 */
	if (lastdiff && free) {
		for (j = (maxdiv == 4) ? 1 : scale; j <= maxdiv; j += scale) {
			tpr = req->rate * j;
			if (tpr < 0)
				break;
			pr = clk_hw_round_rate(free, tpr);

			tdv = alchemy_calc_div(req->rate, pr, scale, maxdiv,
					       NULL);
			nr = pr / tdv;
			diff = req->rate - nr;
			if (nr > req->rate)
				continue;
			if (diff < lastdiff) {
				lastdiff = diff;
				bpr = pr;
				bpc = free;
				br = nr;
			}
			if (diff == 0)
				break;
		}
	}

	if (br < 0)
		return br;

	req->best_parent_rate = bpr;
	req->best_parent_hw = bpc;
	req->rate = br;

	return 0;
}

__attribute__((used)) static int alchemy_clk_fgv1_en(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long v, flags;

	spin_lock_irqsave(c->reglock, flags);
	v = alchemy_rdsys(c->reg);
	v |= (1 << 1) << c->shift;
	alchemy_wrsys(v, c->reg);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}

__attribute__((used)) static int alchemy_clk_fgv1_isen(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long v = alchemy_rdsys(c->reg) >> (c->shift + 1);

	return v & 1;
}

__attribute__((used)) static void alchemy_clk_fgv1_dis(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long v, flags;

	spin_lock_irqsave(c->reglock, flags);
	v = alchemy_rdsys(c->reg);
	v &= ~((1 << 1) << c->shift);
	alchemy_wrsys(v, c->reg);
	spin_unlock_irqrestore(c->reglock, flags);
}

__attribute__((used)) static int alchemy_clk_fgv1_setp(struct clk_hw *hw, u8 index)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long v, flags;

	spin_lock_irqsave(c->reglock, flags);
	v = alchemy_rdsys(c->reg);
	if (index)
		v |= (1 << c->shift);
	else
		v &= ~(1 << c->shift);
	alchemy_wrsys(v, c->reg);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}

__attribute__((used)) static u8 alchemy_clk_fgv1_getp(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);

	return (alchemy_rdsys(c->reg) >> c->shift) & 1;
}

__attribute__((used)) static int alchemy_clk_fgv1_setr(struct clk_hw *hw, unsigned long rate,
				 unsigned long parent_rate)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long div, v, flags, ret;
	int sh = c->shift + 2;

	if (!rate || !parent_rate || rate > (parent_rate / 2))
		return -EINVAL;
	ret = alchemy_calc_div(rate, parent_rate, 2, 512, &div);
	spin_lock_irqsave(c->reglock, flags);
	v = alchemy_rdsys(c->reg);
	v &= ~(0xff << sh);
	v |= div << sh;
	alchemy_wrsys(v, c->reg);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}

__attribute__((used)) static unsigned long alchemy_clk_fgv1_recalc(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long v = alchemy_rdsys(c->reg) >> (c->shift + 2);

	v = ((v & 0xff) + 1) * 2;
	return parent_rate / v;
}

__attribute__((used)) static int alchemy_clk_fgv1_detr(struct clk_hw *hw,
				 struct clk_rate_request *req)
{
	return alchemy_clk_fgcs_detr(hw, req, 2, 512);
}

__attribute__((used)) static void __alchemy_clk_fgv2_en(struct alchemy_fgcs_clk *c)
{
	unsigned long v = alchemy_rdsys(c->reg);

	v &= ~(3 << c->shift);
	v |= (c->parent & 3) << c->shift;
	alchemy_wrsys(v, c->reg);
	c->isen = 1;
}

__attribute__((used)) static int alchemy_clk_fgv2_en(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long flags;

	/* enable by setting the previous parent clock */
	spin_lock_irqsave(c->reglock, flags);
	__alchemy_clk_fgv2_en(c);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}

__attribute__((used)) static int alchemy_clk_fgv2_isen(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);

	return ((alchemy_rdsys(c->reg) >> c->shift) & 3) != 0;
}

__attribute__((used)) static void alchemy_clk_fgv2_dis(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long v, flags;

	spin_lock_irqsave(c->reglock, flags);
	v = alchemy_rdsys(c->reg);
	v &= ~(3 << c->shift);	/* set input mux to "disabled" state */
	alchemy_wrsys(v, c->reg);
	c->isen = 0;
	spin_unlock_irqrestore(c->reglock, flags);
}

__attribute__((used)) static int alchemy_clk_fgv2_setp(struct clk_hw *hw, u8 index)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long flags;

	spin_lock_irqsave(c->reglock, flags);
	c->parent = index + 1;	/* value to write to register */
	if (c->isen)
		__alchemy_clk_fgv2_en(c);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}

__attribute__((used)) static u8 alchemy_clk_fgv2_getp(struct clk_hw *hw)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long flags, v;

	spin_lock_irqsave(c->reglock, flags);
	v = c->parent - 1;
	spin_unlock_irqrestore(c->reglock, flags);
	return v;
}

__attribute__((used)) static int alchemy_clk_fgv2_setr(struct clk_hw *hw, unsigned long rate,
				 unsigned long parent_rate)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	int sh = c->shift + 2;
	unsigned long div, v, flags, ret;

	if (!rate || !parent_rate || rate > parent_rate)
		return -EINVAL;

	v = alchemy_rdsys(c->reg) & (1 << 30); /* test "scale" bit */
	ret = alchemy_calc_div(rate, parent_rate, v ? 1 : 2,
			       v ? 256 : 512, &div);

	spin_lock_irqsave(c->reglock, flags);
	v = alchemy_rdsys(c->reg);
	v &= ~(0xff << sh);
	v |= (div & 0xff) << sh;
	alchemy_wrsys(v, c->reg);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}

__attribute__((used)) static unsigned long alchemy_clk_fgv2_recalc(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	int sh = c->shift + 2;
	unsigned long v, t;

	v = alchemy_rdsys(c->reg);
	t = parent_rate / (((v >> sh) & 0xff) + 1);
	if ((v & (1 << 30)) == 0)		/* test scale bit */
		t /= 2;

	return t;
}

__attribute__((used)) static int alchemy_clk_fgv2_detr(struct clk_hw *hw,
				 struct clk_rate_request *req)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	int scale, maxdiv;

	if (alchemy_rdsys(c->reg) & (1 << 30)) {
		scale = 1;
		maxdiv = 256;
	} else {
		scale = 2;
		maxdiv = 512;
	}

	return alchemy_clk_fgcs_detr(hw, req, scale, maxdiv);
}


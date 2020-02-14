#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct platform_device {int dummy; } ;
struct notifier_block {int dummy; } ;
struct freq_tbl {long freq; int pre_div; int /*<<< orphan*/  src; } ;
struct clk_hw {int dummy; } ;
struct clk_fepll_vco {int refclkdiv_shift; int fdbkdiv_shift; int /*<<< orphan*/  fdbkdiv_width; int /*<<< orphan*/  refclkdiv_width; int /*<<< orphan*/  reg; } ;
struct TYPE_7__ {int /*<<< orphan*/  regmap; } ;
struct TYPE_8__ {int shift; int /*<<< orphan*/  width; int /*<<< orphan*/  reg; TYPE_1__ clkr; } ;
struct clk_fepll {int fixed_div; struct clk_div_table* div_table; TYPE_2__ cdiv; int /*<<< orphan*/  freq_tbl; struct clk_fepll_vco* pll_vco; } ;
struct clk_div_table {int div; int val; } ;
struct TYPE_10__ {int /*<<< orphan*/  clk; } ;
struct TYPE_9__ {TYPE_4__ hw; } ;
struct TYPE_12__ {TYPE_3__ clkr; } ;
struct TYPE_11__ {int (* set_parent ) (TYPE_4__*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 long EINVAL ; 
 unsigned long PRE_RATE_CHANGE ; 
 TYPE_6__ apps_clk_src ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int /*<<< orphan*/ ) ; 
 unsigned long clk_hw_get_rate (struct clk_hw*) ; 
 int clk_notifier_register (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int clk_notifier_unregister (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_5__ clk_rcg2_ops ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  gcc_ipq4019_cpu_clk_notifier ; 
 int /*<<< orphan*/  gcc_ipq4019_cpu_safe_parent ; 
 int /*<<< orphan*/  gcc_ipq4019_desc ; 
 int notifier_from_errno (int) ; 
 int qcom_cc_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 struct freq_tbl* qcom_find_freq (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int stub1 (TYPE_4__*,int /*<<< orphan*/ ) ; 
 struct clk_fepll* to_clk_fepll (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static u64 clk_fepll_vco_calc_rate(struct clk_fepll *pll_div,
				   unsigned long parent_rate)
{
	const struct clk_fepll_vco *pll_vco = pll_div->pll_vco;
	u32 fdbkdiv, refclkdiv, cdiv;
	u64 vco;

	regmap_read(pll_div->cdiv.clkr.regmap, pll_vco->reg, &cdiv);
	refclkdiv = (cdiv >> pll_vco->refclkdiv_shift) &
		    (BIT(pll_vco->refclkdiv_width) - 1);
	fdbkdiv = (cdiv >> pll_vco->fdbkdiv_shift) &
		  (BIT(pll_vco->fdbkdiv_width) - 1);

	vco = parent_rate / refclkdiv;
	vco *= 2;
	vco *= fdbkdiv;

	return vco;
}

__attribute__((used)) static long clk_cpu_div_round_rate(struct clk_hw *hw, unsigned long rate,
				   unsigned long *p_rate)
{
	struct clk_fepll *pll = to_clk_fepll(hw);
	struct clk_hw *p_hw;
	const struct freq_tbl *f;

	f = qcom_find_freq(pll->freq_tbl, rate);
	if (!f)
		return -EINVAL;

	p_hw = clk_hw_get_parent_by_index(hw, f->src);
	*p_rate = clk_hw_get_rate(p_hw);

	return f->freq;
}

__attribute__((used)) static int clk_cpu_div_set_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long parent_rate)
{
	struct clk_fepll *pll = to_clk_fepll(hw);
	const struct freq_tbl *f;
	u32 mask;
	int ret;

	f = qcom_find_freq(pll->freq_tbl, rate);
	if (!f)
		return -EINVAL;

	mask = (BIT(pll->cdiv.width) - 1) << pll->cdiv.shift;
	ret = regmap_update_bits(pll->cdiv.clkr.regmap,
				 pll->cdiv.reg, mask,
				 f->pre_div << pll->cdiv.shift);
	/*
	 * There is no status bit which can be checked for successful CPU
	 * divider update operation so using delay for the same.
	 */
	udelay(1);

	return 0;
}

__attribute__((used)) static unsigned long
clk_cpu_div_recalc_rate(struct clk_hw *hw,
			unsigned long parent_rate)
{
	struct clk_fepll *pll = to_clk_fepll(hw);
	u32 cdiv, pre_div;
	u64 rate;

	regmap_read(pll->cdiv.clkr.regmap, pll->cdiv.reg, &cdiv);
	cdiv = (cdiv >> pll->cdiv.shift) & (BIT(pll->cdiv.width) - 1);

	/*
	 * Some dividers have value in 0.5 fraction so multiply both VCO
	 * frequency(parent_rate) and pre_div with 2 to make integer
	 * calculation.
	 */
	if (cdiv > 10)
		pre_div = (cdiv + 1) * 2;
	else
		pre_div = cdiv + 12;

	rate = clk_fepll_vco_calc_rate(pll, parent_rate) * 2;
	do_div(rate, pre_div);

	return rate;
}

__attribute__((used)) static unsigned long
clk_regmap_clk_div_recalc_rate(struct clk_hw *hw,
			       unsigned long parent_rate)
{
	struct clk_fepll *pll = to_clk_fepll(hw);
	u32 cdiv, pre_div = 1;
	u64 rate;
	const struct clk_div_table *clkt;

	if (pll->fixed_div) {
		pre_div = pll->fixed_div;
	} else {
		regmap_read(pll->cdiv.clkr.regmap, pll->cdiv.reg, &cdiv);
		cdiv = (cdiv >> pll->cdiv.shift) & (BIT(pll->cdiv.width) - 1);

		for (clkt = pll->div_table; clkt->div; clkt++) {
			if (clkt->val == cdiv)
				pre_div = clkt->div;
		}
	}

	rate = clk_fepll_vco_calc_rate(pll, parent_rate);
	do_div(rate, pre_div);

	return rate;
}

__attribute__((used)) static int
gcc_ipq4019_cpu_clk_notifier_fn(struct notifier_block *nb,
				unsigned long action, void *data)
{
	int err = 0;

	if (action == PRE_RATE_CHANGE)
		err = clk_rcg2_ops.set_parent(&apps_clk_src.clkr.hw,
					      gcc_ipq4019_cpu_safe_parent);

	return notifier_from_errno(err);
}

__attribute__((used)) static int gcc_ipq4019_probe(struct platform_device *pdev)
{
	int err;

	err = qcom_cc_probe(pdev, &gcc_ipq4019_desc);
	if (err)
		return err;

	return clk_notifier_register(apps_clk_src.clkr.hw.clk,
				     &gcc_ipq4019_cpu_clk_notifier);
}

__attribute__((used)) static int gcc_ipq4019_remove(struct platform_device *pdev)
{
	return clk_notifier_unregister(apps_clk_src.clkr.hw.clk,
				       &gcc_ipq4019_cpu_clk_notifier);
}


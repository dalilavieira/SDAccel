#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {int /*<<< orphan*/  data; } ;
struct TYPE_6__ {int /*<<< orphan*/  regmap; } ;
struct clk_pix_rdi {int s2_mask; int s_mask; int /*<<< orphan*/  s_reg; TYPE_1__ clkr; int /*<<< orphan*/  s2_reg; } ;
struct clk_hw {int /*<<< orphan*/  clk; } ;
struct TYPE_7__ {int /*<<< orphan*/ * init; } ;
struct TYPE_8__ {TYPE_2__ hw; } ;
struct TYPE_10__ {TYPE_4__* s; TYPE_3__ clkr; int /*<<< orphan*/  freq_tbl; } ;
struct TYPE_9__ {void* parent_map; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int) ; 
 int /*<<< orphan*/  clk_pll_configure_sr (int /*<<< orphan*/ *,struct regmap*,int /*<<< orphan*/ *,int) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_tbl_gfx3d_8064 ; 
 int /*<<< orphan*/  gfx3d_8064_init ; 
 TYPE_5__ gfx3d_src ; 
 int /*<<< orphan*/  mmcc_msm8960_match_table ; 
 void* mmcc_pxo_pll8_pll2_pll15_map ; 
 int of_device_is_compatible (int /*<<< orphan*/ ,char*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  pll15 ; 
 int /*<<< orphan*/  pll15_config ; 
 struct regmap* qcom_cc_map (struct platform_device*,int /*<<< orphan*/ ) ; 
 int qcom_cc_really_probe (struct platform_device*,int /*<<< orphan*/ ,struct regmap*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 struct clk_pix_rdi* to_clk_pix_rdi (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int pix_rdi_set_parent(struct clk_hw *hw, u8 index)
{
	int i;
	int ret = 0;
	u32 val;
	struct clk_pix_rdi *rdi = to_clk_pix_rdi(hw);
	int num_parents = clk_hw_get_num_parents(hw);

	/*
	 * These clocks select three inputs via two muxes. One mux selects
	 * between csi0 and csi1 and the second mux selects between that mux's
	 * output and csi2. The source and destination selections for each
	 * mux must be clocking for the switch to succeed so just turn on
	 * all three sources because it's easier than figuring out what source
	 * needs to be on at what time.
	 */
	for (i = 0; i < num_parents; i++) {
		struct clk_hw *p = clk_hw_get_parent_by_index(hw, i);
		ret = clk_prepare_enable(p->clk);
		if (ret)
			goto err;
	}

	if (index == 2)
		val = rdi->s2_mask;
	else
		val = 0;
	regmap_update_bits(rdi->clkr.regmap, rdi->s2_reg, rdi->s2_mask, val);
	/*
	 * Wait at least 6 cycles of slowest clock
	 * for the glitch-free MUX to fully switch sources.
	 */
	udelay(1);

	if (index == 1)
		val = rdi->s_mask;
	else
		val = 0;
	regmap_update_bits(rdi->clkr.regmap, rdi->s_reg, rdi->s_mask, val);
	/*
	 * Wait at least 6 cycles of slowest clock
	 * for the glitch-free MUX to fully switch sources.
	 */
	udelay(1);

err:
	for (i--; i >= 0; i--) {
		struct clk_hw *p = clk_hw_get_parent_by_index(hw, i);
		clk_disable_unprepare(p->clk);
	}

	return ret;
}

__attribute__((used)) static u8 pix_rdi_get_parent(struct clk_hw *hw)
{
	u32 val;
	struct clk_pix_rdi *rdi = to_clk_pix_rdi(hw);


	regmap_read(rdi->clkr.regmap, rdi->s2_reg, &val);
	if (val & rdi->s2_mask)
		return 2;

	regmap_read(rdi->clkr.regmap, rdi->s_reg, &val);
	if (val & rdi->s_mask)
		return 1;

	return 0;
}

__attribute__((used)) static int mmcc_msm8960_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	struct regmap *regmap;
	bool is_8064;
	struct device *dev = &pdev->dev;

	match = of_match_device(mmcc_msm8960_match_table, dev);
	if (!match)
		return -EINVAL;

	is_8064 = of_device_is_compatible(dev->of_node, "qcom,mmcc-apq8064");
	if (is_8064) {
		gfx3d_src.freq_tbl = clk_tbl_gfx3d_8064;
		gfx3d_src.clkr.hw.init = &gfx3d_8064_init;
		gfx3d_src.s[0].parent_map = mmcc_pxo_pll8_pll2_pll15_map;
		gfx3d_src.s[1].parent_map = mmcc_pxo_pll8_pll2_pll15_map;
	}

	regmap = qcom_cc_map(pdev, match->data);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	clk_pll_configure_sr(&pll15, regmap, &pll15_config, false);

	return qcom_cc_really_probe(pdev, match->data, regmap);
}


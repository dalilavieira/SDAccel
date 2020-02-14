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
struct reset_controller_dev {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {int /*<<< orphan*/  data; } ;
struct gdsc_desc {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/  clkr; } ;
struct TYPE_9__ {int /*<<< orphan*/  clkr; } ;
struct TYPE_8__ {int /*<<< orphan*/  clkr; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent_map; int /*<<< orphan*/  freq_tbl; } ;
struct TYPE_6__ {int num_parents; int /*<<< orphan*/  parent_names; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOSYS ; 
 size_t GCC_SDCC1_CDCCAL_FF_CLK ; 
 size_t GCC_SDCC1_CDCCAL_SLEEP_CLK ; 
 size_t GPLL4 ; 
 size_t GPLL4_VOTE ; 
 int /*<<< orphan*/  ftbl_gcc_sdcc1_apps_clk_pro ; 
 int /*<<< orphan*/ ** gcc_msm8974_clocks ; 
 int /*<<< orphan*/  gcc_msm8974_desc ; 
 int /*<<< orphan*/  gcc_msm8974_match_table ; 
 TYPE_5__ gcc_sdcc1_cdccal_ff_clk ; 
 TYPE_4__ gcc_sdcc1_cdccal_sleep_clk ; 
 int /*<<< orphan*/  gcc_xo_gpll0_gpll4 ; 
 int /*<<< orphan*/  gcc_xo_gpll0_gpll4_map ; 
 TYPE_3__ gpll4 ; 
 int /*<<< orphan*/  gpll4_vote ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int qcom_cc_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int qcom_cc_register_board_clk (struct device*,char*,char*,int) ; 
 int qcom_cc_register_sleep_clk (struct device*) ; 
 TYPE_2__ sdcc1_apps_clk_src ; 
 TYPE_1__ sdcc1_apps_clk_src_init ; 

__attribute__((used)) static inline int gdsc_register(struct gdsc_desc *desc,
				struct reset_controller_dev *rcdev,
				struct regmap *r)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void gdsc_unregister(struct gdsc_desc *desc) {}

__attribute__((used)) static void msm8974_pro_clock_override(void)
{
	sdcc1_apps_clk_src_init.parent_names = gcc_xo_gpll0_gpll4;
	sdcc1_apps_clk_src_init.num_parents = 3;
	sdcc1_apps_clk_src.freq_tbl = ftbl_gcc_sdcc1_apps_clk_pro;
	sdcc1_apps_clk_src.parent_map = gcc_xo_gpll0_gpll4_map;

	gcc_msm8974_clocks[GPLL4] = &gpll4.clkr;
	gcc_msm8974_clocks[GPLL4_VOTE] = &gpll4_vote;
	gcc_msm8974_clocks[GCC_SDCC1_CDCCAL_SLEEP_CLK] =
		&gcc_sdcc1_cdccal_sleep_clk.clkr;
	gcc_msm8974_clocks[GCC_SDCC1_CDCCAL_FF_CLK] =
		&gcc_sdcc1_cdccal_ff_clk.clkr;
}

__attribute__((used)) static int gcc_msm8974_probe(struct platform_device *pdev)
{
	int ret;
	struct device *dev = &pdev->dev;
	bool pro;
	const struct of_device_id *id;

	id = of_match_device(gcc_msm8974_match_table, dev);
	if (!id)
		return -ENODEV;
	pro = !!(id->data);

	if (pro)
		msm8974_pro_clock_override();

	ret = qcom_cc_register_board_clk(dev, "xo_board", "xo", 19200000);
	if (ret)
		return ret;

	ret = qcom_cc_register_sleep_clk(dev);
	if (ret)
		return ret;

	return qcom_cc_probe(pdev, &gcc_msm8974_desc);
}


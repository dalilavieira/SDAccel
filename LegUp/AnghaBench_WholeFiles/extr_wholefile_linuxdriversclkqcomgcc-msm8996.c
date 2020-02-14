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
struct reset_controller_dev {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct gdsc_desc {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIT (int) ; 
 int ENOSYS ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int devm_clk_hw_register (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gcc_msm8996_desc ; 
 int /*<<< orphan*/ * gcc_msm8996_hws ; 
 struct regmap* qcom_cc_map (struct platform_device*,int /*<<< orphan*/ *) ; 
 int qcom_cc_really_probe (struct platform_device*,int /*<<< orphan*/ *,struct regmap*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int gdsc_register(struct gdsc_desc *desc,
				struct reset_controller_dev *rcdev,
				struct regmap *r)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void gdsc_unregister(struct gdsc_desc *desc) {}

__attribute__((used)) static int gcc_msm8996_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	int i, ret;
	struct regmap *regmap;

	regmap = qcom_cc_map(pdev, &gcc_msm8996_desc);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	/*
	 * Set the HMSS_AHB_CLK_SLEEP_ENA bit to allow the hmss_ahb_clk to be
	 * turned off by hardware during certain apps low power modes.
	 */
	regmap_update_bits(regmap, 0x52008, BIT(21), BIT(21));

	for (i = 0; i < ARRAY_SIZE(gcc_msm8996_hws); i++) {
		ret = devm_clk_hw_register(dev, gcc_msm8996_hws[i]);
		if (ret)
			return ret;
	}

	return qcom_cc_really_probe(pdev, &gcc_msm8996_desc, regmap);
}


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
struct platform_device {int dummy; } ;
struct gdsc_desc {int dummy; } ;

/* Variables and functions */
 int ENOSYS ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  gcc_sdm845_desc ; 
 struct regmap* qcom_cc_map (struct platform_device*,int /*<<< orphan*/ *) ; 
 int qcom_cc_really_probe (struct platform_device*,int /*<<< orphan*/ *,struct regmap*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int,int,int) ; 

__attribute__((used)) static inline int gdsc_register(struct gdsc_desc *desc,
				struct reset_controller_dev *rcdev,
				struct regmap *r)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void gdsc_unregister(struct gdsc_desc *desc) {}

__attribute__((used)) static int gcc_sdm845_probe(struct platform_device *pdev)
{
	struct regmap *regmap;

	regmap = qcom_cc_map(pdev, &gcc_sdm845_desc);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	/* Disable the GPLL0 active input to MMSS and GPU via MISC registers */
	regmap_update_bits(regmap, 0x09ffc, 0x3, 0x3);
	regmap_update_bits(regmap, 0x71028, 0x3, 0x3);

	return qcom_cc_really_probe(pdev, &gcc_sdm845_desc, regmap);
}


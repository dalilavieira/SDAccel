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
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct platform_device*) ; 
 int PTR_ERR (struct platform_device*) ; 
 int /*<<< orphan*/  gcc_msm8960_match_table ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 struct platform_device* platform_device_register_data (struct device*,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_unregister (struct platform_device*) ; 
 struct platform_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct platform_device*) ; 
 int qcom_cc_probe (struct platform_device*,int /*<<< orphan*/ ) ; 
 int qcom_cc_register_board_clk (struct device*,char*,char*,int) ; 

__attribute__((used)) static int gcc_msm8960_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	const struct of_device_id *match;
	struct platform_device *tsens;
	int ret;

	match = of_match_device(gcc_msm8960_match_table, &pdev->dev);
	if (!match)
		return -EINVAL;

	ret = qcom_cc_register_board_clk(dev, "cxo_board", "cxo", 19200000);
	if (ret)
		return ret;

	ret = qcom_cc_register_board_clk(dev, "pxo_board", "pxo", 27000000);
	if (ret)
		return ret;

	ret = qcom_cc_probe(pdev, match->data);
	if (ret)
		return ret;

	tsens = platform_device_register_data(&pdev->dev, "qcom-tsens", -1,
					      NULL, 0);
	if (IS_ERR(tsens))
		return PTR_ERR(tsens);

	platform_set_drvdata(pdev, tsens);

	return 0;
}

__attribute__((used)) static int gcc_msm8960_remove(struct platform_device *pdev)
{
	struct platform_device *tsens = platform_get_drvdata(pdev);

	platform_device_unregister(tsens);

	return 0;
}


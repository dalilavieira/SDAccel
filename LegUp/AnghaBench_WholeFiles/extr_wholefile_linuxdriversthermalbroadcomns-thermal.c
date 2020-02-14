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
typedef  int u32 ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct ns_thermal {scalar_t__ pvtmon; int /*<<< orphan*/  tz; } ;

/* Variables and functions */
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ PVTMON_CONTROL0 ; 
 int PVTMON_CONTROL0_SEL_MASK ; 
 int PVTMON_CONTROL0_SEL_TEMP_MONITOR ; 
 scalar_t__ PVTMON_STATUS ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_of_node (struct device*) ; 
 struct ns_thermal* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_thermal_zone_of_sensor_register (struct device*,int /*<<< orphan*/ ,struct ns_thermal*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  ns_thermal_ops ; 
 scalar_t__ of_iomap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ns_thermal* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ns_thermal*) ; 
 int readl (scalar_t__) ; 
 int thermal_zone_get_offset (int /*<<< orphan*/ ) ; 
 int thermal_zone_get_slope (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int ns_thermal_get_temp(void *data, int *temp)
{
	struct ns_thermal *ns_thermal = data;
	int offset = thermal_zone_get_offset(ns_thermal->tz);
	int slope = thermal_zone_get_slope(ns_thermal->tz);
	u32 val;

	val = readl(ns_thermal->pvtmon + PVTMON_CONTROL0);
	if ((val & PVTMON_CONTROL0_SEL_MASK) != PVTMON_CONTROL0_SEL_TEMP_MONITOR) {
		/* Clear current mode selection */
		val &= ~PVTMON_CONTROL0_SEL_MASK;

		/* Set temp monitor mode (it's the default actually) */
		val |= PVTMON_CONTROL0_SEL_TEMP_MONITOR;

		writel(val, ns_thermal->pvtmon + PVTMON_CONTROL0);
	}

	val = readl(ns_thermal->pvtmon + PVTMON_STATUS);
	*temp = slope * val + offset;

	return 0;
}

__attribute__((used)) static int ns_thermal_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct ns_thermal *ns_thermal;

	ns_thermal = devm_kzalloc(dev, sizeof(*ns_thermal), GFP_KERNEL);
	if (!ns_thermal)
		return -ENOMEM;

	ns_thermal->pvtmon = of_iomap(dev_of_node(dev), 0);
	if (WARN_ON(!ns_thermal->pvtmon))
		return -ENOENT;

	ns_thermal->tz = devm_thermal_zone_of_sensor_register(dev, 0,
							      ns_thermal,
							      &ns_thermal_ops);
	if (IS_ERR(ns_thermal->tz)) {
		iounmap(ns_thermal->pvtmon);
		return PTR_ERR(ns_thermal->tz);
	}

	platform_set_drvdata(pdev, ns_thermal);

	return 0;
}

__attribute__((used)) static int ns_thermal_remove(struct platform_device *pdev)
{
	struct ns_thermal *ns_thermal = platform_get_drvdata(pdev);

	iounmap(ns_thermal->pvtmon);

	return 0;
}


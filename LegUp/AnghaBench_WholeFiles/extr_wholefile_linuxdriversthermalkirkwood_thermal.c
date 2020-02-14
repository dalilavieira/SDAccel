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
struct thermal_zone_device {int /*<<< orphan*/  device; struct kirkwood_thermal_priv* devdata; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct kirkwood_thermal_priv {struct thermal_zone_device* sensor; } ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct thermal_zone_device*) ; 
 unsigned long KIRKWOOD_THERMAL_TEMP_MASK ; 
 unsigned long KIRKWOOD_THERMAL_TEMP_OFFSET ; 
 unsigned long KIRKWOOD_THERMAL_VALID_MASK ; 
 unsigned long KIRKWOOD_THERMAL_VALID_OFFSET ; 
 int PTR_ERR (struct thermal_zone_device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct thermal_zone_device* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct kirkwood_thermal_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ops ; 
 struct thermal_zone_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct thermal_zone_device*) ; 
 unsigned long readl_relaxed (struct thermal_zone_device*) ; 
 struct thermal_zone_device* thermal_zone_device_register (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct kirkwood_thermal_priv*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  thermal_zone_device_unregister (struct thermal_zone_device*) ; 

__attribute__((used)) static int kirkwood_get_temp(struct thermal_zone_device *thermal,
			  int *temp)
{
	unsigned long reg;
	struct kirkwood_thermal_priv *priv = thermal->devdata;

	reg = readl_relaxed(priv->sensor);

	/* Valid check */
	if (!((reg >> KIRKWOOD_THERMAL_VALID_OFFSET) &
	    KIRKWOOD_THERMAL_VALID_MASK)) {
		dev_err(&thermal->device,
			"Temperature sensor reading not valid\n");
		return -EIO;
	}

	/*
	 * Calculate temperature. According to Marvell internal
	 * documentation the formula for this is:
	 * Celsius = (322-reg)/1.3625
	 */
	reg = (reg >> KIRKWOOD_THERMAL_TEMP_OFFSET) &
		KIRKWOOD_THERMAL_TEMP_MASK;
	*temp = ((3220000000UL - (10000000UL * reg)) / 13625);

	return 0;
}

__attribute__((used)) static int kirkwood_thermal_probe(struct platform_device *pdev)
{
	struct thermal_zone_device *thermal = NULL;
	struct kirkwood_thermal_priv *priv;
	struct resource *res;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->sensor = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->sensor))
		return PTR_ERR(priv->sensor);

	thermal = thermal_zone_device_register("kirkwood_thermal", 0, 0,
					       priv, &ops, NULL, 0, 0);
	if (IS_ERR(thermal)) {
		dev_err(&pdev->dev,
			"Failed to register thermal zone device\n");
		return PTR_ERR(thermal);
	}

	platform_set_drvdata(pdev, thermal);

	return 0;
}

__attribute__((used)) static int kirkwood_thermal_exit(struct platform_device *pdev)
{
	struct thermal_zone_device *kirkwood_thermal =
		platform_get_drvdata(pdev);

	thermal_zone_device_unregister(kirkwood_thermal);

	return 0;
}


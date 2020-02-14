#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct st_thermal_sensor {int /*<<< orphan*/  regmap; struct device* dev; TYPE_1__* cdata; int /*<<< orphan*/  pwr; } ;
struct platform_device {int dummy; } ;
struct device {int dummy; } ;
typedef  enum st_thermal_power_state { ____Placeholder_st_thermal_power_state } st_thermal_power_state ;
struct TYPE_2__ {int /*<<< orphan*/  sys_compat; int /*<<< orphan*/ * reg_fields; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 size_t TEMP_PWR ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  devm_regmap_field_alloc (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_field_write (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  st_syscfg_thermal_of_match ; 
 int st_thermal_register (struct platform_device*,int /*<<< orphan*/ ) ; 
 int st_thermal_unregister (struct platform_device*) ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_compatible (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int st_syscfg_power_ctrl(struct st_thermal_sensor *sensor,
				enum st_thermal_power_state power_state)
{
	return regmap_field_write(sensor->pwr, power_state);
}

__attribute__((used)) static int st_syscfg_alloc_regfields(struct st_thermal_sensor *sensor)
{
	struct device *dev = sensor->dev;

	sensor->pwr = devm_regmap_field_alloc(dev, sensor->regmap,
					sensor->cdata->reg_fields[TEMP_PWR]);

	if (IS_ERR(sensor->pwr)) {
		dev_err(dev, "failed to alloc syscfg regfields\n");
		return PTR_ERR(sensor->pwr);
	}

	return 0;
}

__attribute__((used)) static int st_syscfg_regmap_init(struct st_thermal_sensor *sensor)
{
	sensor->regmap =
		syscon_regmap_lookup_by_compatible(sensor->cdata->sys_compat);
	if (IS_ERR(sensor->regmap)) {
		dev_err(sensor->dev, "failed to find syscfg regmap\n");
		return PTR_ERR(sensor->regmap);
	}

	return 0;
}

__attribute__((used)) static int st_syscfg_probe(struct platform_device *pdev)
{
	return st_thermal_register(pdev, st_syscfg_thermal_of_match);
}

__attribute__((used)) static int st_syscfg_remove(struct platform_device *pdev)
{
	return st_thermal_unregister(pdev);
}


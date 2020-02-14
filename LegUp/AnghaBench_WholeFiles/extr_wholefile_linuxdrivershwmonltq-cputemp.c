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
typedef  int umode_t ;
typedef  int u32 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int /*<<< orphan*/  CGU_GPHY1_CR ; 
 int CGU_TEMP_PD ; 
 int ENODEV ; 
 int EOPNOTSUPP ; 
 scalar_t__ IS_ERR (struct device*) ; 
 int PTR_ERR (struct device*) ; 
 scalar_t__ SOC_TYPE_VR9_2 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int devm_add_action (int /*<<< orphan*/ *,void (*) (void*),int /*<<< orphan*/ *) ; 
 struct device* devm_hwmon_device_register_with_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int hwmon_temp ; 
#define  hwmon_temp_input 128 
 int ltq_cgu_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_cgu_w32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_chip_info ; 
 scalar_t__ ltq_soc_type () ; 

__attribute__((used)) static void ltq_cputemp_enable(void)
{
	ltq_cgu_w32(ltq_cgu_r32(CGU_GPHY1_CR) | CGU_TEMP_PD, CGU_GPHY1_CR);
}

__attribute__((used)) static void ltq_cputemp_disable(void *data)
{
	ltq_cgu_w32(ltq_cgu_r32(CGU_GPHY1_CR) & ~CGU_TEMP_PD, CGU_GPHY1_CR);
}

__attribute__((used)) static int ltq_read(struct device *dev, enum hwmon_sensor_types type,
		    u32 attr, int channel, long *temp)
{
	int value;

	switch (attr) {
	case hwmon_temp_input:
		/* get the temperature including one decimal place */
		value = (ltq_cgu_r32(CGU_GPHY1_CR) >> 9) & 0x01FF;
		value = value * 5;
		/* range -38 to +154 °C, register value zero is -38.0 °C */
		value -= 380;
		/* scale temp to millidegree */
		value = value * 100;
		break;
	default:
		return -EOPNOTSUPP;
	}

	*temp = value;
	return 0;
}

__attribute__((used)) static umode_t ltq_is_visible(const void *_data, enum hwmon_sensor_types type,
			      u32 attr, int channel)
{
	if (type != hwmon_temp)
		return 0;

	switch (attr) {
	case hwmon_temp_input:
		return 0444;
	default:
		return 0;
	}
}

__attribute__((used)) static int ltq_cputemp_probe(struct platform_device *pdev)
{
	struct device *hwmon_dev;
	int err = 0;

	/* available on vr9 v1.2 SoCs only */
	if (ltq_soc_type() != SOC_TYPE_VR9_2)
		return -ENODEV;

	err = devm_add_action(&pdev->dev, ltq_cputemp_disable, NULL);
	if (err)
		return err;

	ltq_cputemp_enable();

	hwmon_dev = devm_hwmon_device_register_with_info(&pdev->dev,
							 "ltq_cputemp",
							 NULL,
							 &ltq_chip_info,
							 NULL);

	if (IS_ERR(hwmon_dev)) {
		dev_err(&pdev->dev, "Failed to register as hwmon device");
		return PTR_ERR(hwmon_dev);
	}

	return 0;
}


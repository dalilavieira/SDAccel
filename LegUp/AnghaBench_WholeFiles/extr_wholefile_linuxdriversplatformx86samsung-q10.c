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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_2__ {int brightness; } ;
struct backlight_device {TYPE_1__ props; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BACKLIGHT_PLATFORM ; 
 int EIO ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 int SAMSUNGQ10_BL_MAX_INTENSITY ; 
 int /*<<< orphan*/  acpi_evaluate_object (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct backlight_device* backlight_device_register (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int /*<<< orphan*/  backlight_device_unregister (struct backlight_device*) ; 
 int /*<<< orphan*/  ec_handle ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 struct backlight_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 
 int /*<<< orphan*/  samsungq10_bl_ops ; 

__attribute__((used)) static int samsungq10_bl_set_intensity(struct backlight_device *bd)
{

	acpi_status status;
	int i;

	for (i = 0; i < SAMSUNGQ10_BL_MAX_INTENSITY; i++) {
		status = acpi_evaluate_object(ec_handle, "_Q63", NULL, NULL);
		if (ACPI_FAILURE(status))
			return -EIO;
	}
	for (i = 0; i < bd->props.brightness; i++) {
		status = acpi_evaluate_object(ec_handle, "_Q64", NULL, NULL);
		if (ACPI_FAILURE(status))
			return -EIO;
	}

	return 0;
}

__attribute__((used)) static int samsungq10_probe(struct platform_device *pdev)
{

	struct backlight_properties props;
	struct backlight_device *bd;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_PLATFORM;
	props.max_brightness = SAMSUNGQ10_BL_MAX_INTENSITY;
	bd = backlight_device_register("samsung", &pdev->dev, NULL,
				       &samsungq10_bl_ops, &props);
	if (IS_ERR(bd))
		return PTR_ERR(bd);

	platform_set_drvdata(pdev, bd);

	return 0;
}

__attribute__((used)) static int samsungq10_remove(struct platform_device *pdev)
{

	struct backlight_device *bd = platform_get_drvdata(pdev);

	backlight_device_unregister(bd);

	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct thermal_cooling_device {struct int3406_thermal_data* devdata; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct int3406_thermal_data {unsigned long upper_limit; unsigned long lower_limit; TYPE_2__* br; int /*<<< orphan*/  cooling_dev; struct backlight_device* raw_bd; scalar_t__ handle; } ;
struct TYPE_4__ {int /*<<< orphan*/  brightness; } ;
struct backlight_device {TYPE_1__ props; } ;
struct acpi_device {int /*<<< orphan*/  handle; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_5__ {int* levels; int count; } ;

/* Variables and functions */
 struct acpi_device* ACPI_COMPANION (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ACPI_DEVICE_NOTIFY ; 
 scalar_t__ ACPI_HANDLE (int /*<<< orphan*/ *) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int ACPI_TO_RAW (int,struct int3406_thermal_data*) ; 
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ INT3406_BRIGHTNESS_LIMITS_CHANGED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int RAW_TO_ACPI (int /*<<< orphan*/ ,struct int3406_thermal_data*) ; 
 int /*<<< orphan*/  acpi_device_bid (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (scalar_t__,char*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int acpi_install_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,scalar_t__,void*),struct int3406_thermal_data*) ; 
 int acpi_video_get_levels (struct acpi_device*,TYPE_2__**,int /*<<< orphan*/ *) ; 
 struct backlight_device* backlight_device_get_by_type (int /*<<< orphan*/ ) ; 
 int backlight_device_set_brightness (struct backlight_device*,int) ; 
 struct int3406_thermal_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (TYPE_2__*) ; 
 struct int3406_thermal_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct int3406_thermal_data*) ; 
 int /*<<< orphan*/  thermal_cooling_device_register (int /*<<< orphan*/ ,struct int3406_thermal_data*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  thermal_cooling_device_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  video_cooling_ops ; 

__attribute__((used)) static int
int3406_thermal_get_max_state(struct thermal_cooling_device *cooling_dev,
			      unsigned long *state)
{
	struct int3406_thermal_data *d = cooling_dev->devdata;

	*state = d->upper_limit - d->lower_limit;
	return 0;
}

__attribute__((used)) static int
int3406_thermal_set_cur_state(struct thermal_cooling_device *cooling_dev,
			      unsigned long state)
{
	struct int3406_thermal_data *d = cooling_dev->devdata;
	int acpi_level, raw_level;

	if (state > d->upper_limit - d->lower_limit)
		return -EINVAL;

	acpi_level = d->br->levels[d->upper_limit - state];

	raw_level = ACPI_TO_RAW(acpi_level, d);

	return backlight_device_set_brightness(d->raw_bd, raw_level);
}

__attribute__((used)) static int
int3406_thermal_get_cur_state(struct thermal_cooling_device *cooling_dev,
			      unsigned long *state)
{
	struct int3406_thermal_data *d = cooling_dev->devdata;
	int acpi_level;
	int index;

	acpi_level = RAW_TO_ACPI(d->raw_bd->props.brightness, d);

	/*
	 * There is no 1:1 mapping between the firmware interface level
	 * with the raw interface level, we will have to find one that is
	 * right above it.
	 */
	for (index = d->lower_limit; index < d->upper_limit; index++) {
		if (acpi_level <= d->br->levels[index])
			break;
	}

	*state = d->upper_limit - index;
	return 0;
}

__attribute__((used)) static int int3406_thermal_get_index(int *array, int nr, int value)
{
	int i;

	for (i = 2; i < nr; i++) {
		if (array[i] == value)
			break;
	}
	return i == nr ? -ENOENT : i;
}

__attribute__((used)) static void int3406_thermal_get_limit(struct int3406_thermal_data *d)
{
	acpi_status status;
	unsigned long long lower_limit, upper_limit;

	status = acpi_evaluate_integer(d->handle, "DDDL", NULL, &lower_limit);
	if (ACPI_SUCCESS(status))
		d->lower_limit = int3406_thermal_get_index(d->br->levels,
					d->br->count, lower_limit);

	status = acpi_evaluate_integer(d->handle, "DDPC", NULL, &upper_limit);
	if (ACPI_SUCCESS(status))
		d->upper_limit = int3406_thermal_get_index(d->br->levels,
					d->br->count, upper_limit);

	/* lower_limit and upper_limit should be always set */
	d->lower_limit = d->lower_limit > 0 ? d->lower_limit : 2;
	d->upper_limit = d->upper_limit > 0 ? d->upper_limit : d->br->count - 1;
}

__attribute__((used)) static void int3406_notify(acpi_handle handle, u32 event, void *data)
{
	if (event == INT3406_BRIGHTNESS_LIMITS_CHANGED)
		int3406_thermal_get_limit(data);
}

__attribute__((used)) static int int3406_thermal_probe(struct platform_device *pdev)
{
	struct acpi_device *adev = ACPI_COMPANION(&pdev->dev);
	struct int3406_thermal_data *d;
	struct backlight_device *bd;
	int ret;

	if (!ACPI_HANDLE(&pdev->dev))
		return -ENODEV;

	d = devm_kzalloc(&pdev->dev, sizeof(*d), GFP_KERNEL);
	if (!d)
		return -ENOMEM;
	d->handle = ACPI_HANDLE(&pdev->dev);

	bd = backlight_device_get_by_type(BACKLIGHT_RAW);
	if (!bd)
		return -ENODEV;
	d->raw_bd = bd;

	ret = acpi_video_get_levels(ACPI_COMPANION(&pdev->dev), &d->br, NULL);
	if (ret)
		return ret;

	int3406_thermal_get_limit(d);

	d->cooling_dev = thermal_cooling_device_register(acpi_device_bid(adev),
							 d, &video_cooling_ops);
	if (IS_ERR(d->cooling_dev))
		goto err;

	ret = acpi_install_notify_handler(adev->handle, ACPI_DEVICE_NOTIFY,
					  int3406_notify, d);
	if (ret)
		goto err_cdev;

	platform_set_drvdata(pdev, d);

	return 0;

err_cdev:
	thermal_cooling_device_unregister(d->cooling_dev);
err:
	kfree(d->br);
	return -ENODEV;
}

__attribute__((used)) static int int3406_thermal_remove(struct platform_device *pdev)
{
	struct int3406_thermal_data *d = platform_get_drvdata(pdev);

	thermal_cooling_device_unregister(d->cooling_dev);
	kfree(d->br);
	return 0;
}


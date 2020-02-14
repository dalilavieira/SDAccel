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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct int34x_thermal_zone {void* priv_data; int /*<<< orphan*/  zone; } ;
struct int3402_thermal_data {struct int34x_thermal_zone* int340x_zone; int /*<<< orphan*/  handle; } ;
struct acpi_device {int /*<<< orphan*/  handle; } ;
typedef  enum thermal_notify_event { ____Placeholder_thermal_notify_event } thermal_notify_event ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 struct acpi_device* ACPI_COMPANION (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ACPI_DEVICE_NOTIFY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  INT3402_PERF_CHANGED_EVENT 129 
#define  INT3402_THERMAL_EVENT 128 
 scalar_t__ IS_ERR (struct int34x_thermal_zone*) ; 
 int PTR_ERR (struct int34x_thermal_zone*) ; 
 int THERMAL_TRIP_VIOLATED ; 
 int /*<<< orphan*/  acpi_has_method (int /*<<< orphan*/ ,char*) ; 
 int acpi_install_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,int,void*),struct int3402_thermal_data*) ; 
 int /*<<< orphan*/  acpi_remove_notify_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,int,void*)) ; 
 struct int3402_thermal_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct int34x_thermal_zone* int340x_thermal_zone_add (struct acpi_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  int340x_thermal_zone_remove (struct int34x_thermal_zone*) ; 
 struct int3402_thermal_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct int3402_thermal_data*) ; 
 int /*<<< orphan*/  thermal_zone_device_update (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void int340x_thermal_zone_set_priv_data(
			struct int34x_thermal_zone *tzone, void *priv_data)
{
	tzone->priv_data = priv_data;
}

__attribute__((used)) static inline void *int340x_thermal_zone_get_priv_data(
			struct int34x_thermal_zone *tzone)
{
	return tzone->priv_data;
}

__attribute__((used)) static inline void int340x_thermal_zone_device_update(
					struct int34x_thermal_zone *tzone,
					enum thermal_notify_event event)
{
	thermal_zone_device_update(tzone->zone, event);
}

__attribute__((used)) static void int3402_notify(acpi_handle handle, u32 event, void *data)
{
	struct int3402_thermal_data *priv = data;

	if (!priv)
		return;

	switch (event) {
	case INT3402_PERF_CHANGED_EVENT:
		break;
	case INT3402_THERMAL_EVENT:
		int340x_thermal_zone_device_update(priv->int340x_zone,
						   THERMAL_TRIP_VIOLATED);
		break;
	default:
		break;
	}
}

__attribute__((used)) static int int3402_thermal_probe(struct platform_device *pdev)
{
	struct acpi_device *adev = ACPI_COMPANION(&pdev->dev);
	struct int3402_thermal_data *d;
	int ret;

	if (!acpi_has_method(adev->handle, "_TMP"))
		return -ENODEV;

	d = devm_kzalloc(&pdev->dev, sizeof(*d), GFP_KERNEL);
	if (!d)
		return -ENOMEM;

	d->int340x_zone = int340x_thermal_zone_add(adev, NULL);
	if (IS_ERR(d->int340x_zone))
		return PTR_ERR(d->int340x_zone);

	ret = acpi_install_notify_handler(adev->handle,
					  ACPI_DEVICE_NOTIFY,
					  int3402_notify,
					  d);
	if (ret) {
		int340x_thermal_zone_remove(d->int340x_zone);
		return ret;
	}

	d->handle = adev->handle;
	platform_set_drvdata(pdev, d);

	return 0;
}

__attribute__((used)) static int int3402_thermal_remove(struct platform_device *pdev)
{
	struct int3402_thermal_data *d = platform_get_drvdata(pdev);

	acpi_remove_notify_handler(d->handle,
				   ACPI_DEVICE_NOTIFY, int3402_notify);
	int340x_thermal_zone_remove(d->int340x_zone);

	return 0;
}


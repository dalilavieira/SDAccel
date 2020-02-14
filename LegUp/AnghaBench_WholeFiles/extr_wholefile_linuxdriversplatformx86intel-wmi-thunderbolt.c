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
typedef  int u8 ;
struct TYPE_2__ {int /*<<< orphan*/  kobj; } ;
struct wmi_device {TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct acpi_buffer {int length; int* pointer; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 size_t EINVAL ; 
 size_t ENODEV ; 
 int /*<<< orphan*/  INTEL_WMI_THUNDERBOLT_GUID ; 
 int /*<<< orphan*/  KOBJ_CHANGE ; 
 int hex_to_bin (char const) ; 
 int /*<<< orphan*/  kobject_uevent (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tbt_attribute_group ; 
 int /*<<< orphan*/  wmi_evaluate_method (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct acpi_buffer*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t force_power_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct acpi_buffer input;
	acpi_status status;
	u8 mode;

	input.length = sizeof(u8);
	input.pointer = &mode;
	mode = hex_to_bin(buf[0]);
	if (mode == 0 || mode == 1) {
		status = wmi_evaluate_method(INTEL_WMI_THUNDERBOLT_GUID, 0, 1,
					     &input, NULL);
		if (ACPI_FAILURE(status))
			return -ENODEV;
	} else {
		return -EINVAL;
	}
	return count;
}

__attribute__((used)) static int intel_wmi_thunderbolt_probe(struct wmi_device *wdev)
{
	int ret;

	ret = sysfs_create_group(&wdev->dev.kobj, &tbt_attribute_group);
	kobject_uevent(&wdev->dev.kobj, KOBJ_CHANGE);
	return ret;
}

__attribute__((used)) static int intel_wmi_thunderbolt_remove(struct wmi_device *wdev)
{
	sysfs_remove_group(&wdev->dev.kobj, &tbt_attribute_group);
	kobject_uevent(&wdev->dev.kobj, KOBJ_CHANGE);
	return 0;
}


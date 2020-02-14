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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct toshiba_haps_dev {int protection_level; struct acpi_device* acpi_dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_4__ {int /*<<< orphan*/  device_class; } ;
struct acpi_device {TYPE_2__ dev; int /*<<< orphan*/  handle; struct toshiba_haps_dev* driver_data; TYPE_1__ pnp; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  acpi_bus_generate_netlink_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_evaluate_object (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_execute_simple_method (int /*<<< orphan*/ ,char*,int) ; 
 struct toshiba_haps_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_2__*,struct toshiba_haps_dev*) ; 
 int /*<<< orphan*/  haps_attr_group ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 
 struct toshiba_haps_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int sprintf (char*,char*,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct toshiba_haps_dev* toshiba_haps ; 

__attribute__((used)) static int toshiba_haps_reset_protection(acpi_handle handle)
{
	acpi_status status;

	status = acpi_evaluate_object(handle, "RSSS", NULL, NULL);
	if (ACPI_FAILURE(status)) {
		pr_err("Unable to reset the HDD protection\n");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int toshiba_haps_protection_level(acpi_handle handle, int level)
{
	acpi_status status;

	status = acpi_execute_simple_method(handle, "PTLV", level);
	if (ACPI_FAILURE(status)) {
		pr_err("Error while setting the protection level\n");
		return -EIO;
	}

	pr_debug("HDD protection level set to: %d\n", level);

	return 0;
}

__attribute__((used)) static ssize_t protection_level_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct toshiba_haps_dev *haps = dev_get_drvdata(dev);

	return sprintf(buf, "%i\n", haps->protection_level);
}

__attribute__((used)) static ssize_t protection_level_store(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	struct toshiba_haps_dev *haps = dev_get_drvdata(dev);
	int level;
	int ret;

	ret = kstrtoint(buf, 0, &level);
	if (ret)
		return ret;
	/*
	 * Check for supported levels, which can be:
	 * 0 - Disabled | 1 - Low | 2 - Medium | 3 - High
	 */
	if (level < 0 || level > 3)
		return -EINVAL;

	/* Set the sensor level */
	ret = toshiba_haps_protection_level(haps->acpi_dev->handle, level);
	if (ret != 0)
		return ret;

	haps->protection_level = level;

	return count;
}

__attribute__((used)) static ssize_t reset_protection_store(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	struct toshiba_haps_dev *haps = dev_get_drvdata(dev);
	int reset;
	int ret;

	ret = kstrtoint(buf, 0, &reset);
	if (ret)
		return ret;
	/* The only accepted value is 1 */
	if (reset != 1)
		return -EINVAL;

	/* Reset the protection interface */
	ret = toshiba_haps_reset_protection(haps->acpi_dev->handle);
	if (ret != 0)
		return ret;

	return count;
}

__attribute__((used)) static void toshiba_haps_notify(struct acpi_device *device, u32 event)
{
	pr_debug("Received event: 0x%x", event);

	acpi_bus_generate_netlink_event(device->pnp.device_class,
					dev_name(&device->dev),
					event, 0);
}

__attribute__((used)) static int toshiba_haps_remove(struct acpi_device *device)
{
	sysfs_remove_group(&device->dev.kobj, &haps_attr_group);

	if (toshiba_haps)
		toshiba_haps = NULL;

	return 0;
}

__attribute__((used)) static int toshiba_haps_available(acpi_handle handle)
{
	acpi_status status;
	u64 hdd_present;

	/*
	 * A non existent device as well as having (only)
	 * Solid State Drives can cause the call to fail.
	 */
	status = acpi_evaluate_integer(handle, "_STA", NULL, &hdd_present);
	if (ACPI_FAILURE(status)) {
		pr_err("ACPI call to query HDD protection failed\n");
		return 0;
	}

	if (!hdd_present) {
		pr_info("HDD protection not available or using SSD\n");
		return 0;
	}

	return 1;
}

__attribute__((used)) static int toshiba_haps_add(struct acpi_device *acpi_dev)
{
	struct toshiba_haps_dev *haps;
	int ret;

	if (toshiba_haps)
		return -EBUSY;

	if (!toshiba_haps_available(acpi_dev->handle))
		return -ENODEV;

	pr_info("Toshiba HDD Active Protection Sensor device\n");

	haps = kzalloc(sizeof(struct toshiba_haps_dev), GFP_KERNEL);
	if (!haps)
		return -ENOMEM;

	haps->acpi_dev = acpi_dev;
	haps->protection_level = 2;
	acpi_dev->driver_data = haps;
	dev_set_drvdata(&acpi_dev->dev, haps);

	/* Set the protection level, currently at level 2 (Medium) */
	ret = toshiba_haps_protection_level(acpi_dev->handle, 2);
	if (ret != 0)
		return ret;

	ret = sysfs_create_group(&acpi_dev->dev.kobj, &haps_attr_group);
	if (ret)
		return ret;

	toshiba_haps = haps;

	return 0;
}


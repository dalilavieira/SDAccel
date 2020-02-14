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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct acpi_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  handle; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int /*<<< orphan*/  acpi_execute_simple_method (int /*<<< orphan*/ ,char*,unsigned long) ; 
 int device_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irst_timeout_attr ; 
 int /*<<< orphan*/  irst_wakeup_attr ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int sprintf (char*,char*,unsigned long long) ; 
 struct acpi_device* to_acpi_device (struct device*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static ssize_t irst_show_wakeup_events(struct device *dev,
				       struct device_attribute *attr,
				       char *buf)
{
	struct acpi_device *acpi;
	unsigned long long value;
	acpi_status status;

	acpi = to_acpi_device(dev);

	status = acpi_evaluate_integer(acpi->handle, "GFFS", NULL, &value);
	if (ACPI_FAILURE(status))
		return -EINVAL;

	return sprintf(buf, "%lld\n", value);
}

__attribute__((used)) static ssize_t irst_store_wakeup_events(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct acpi_device *acpi;
	acpi_status status;
	unsigned long value;
	int error;

	acpi = to_acpi_device(dev);

	error = kstrtoul(buf, 0, &value);

	if (error)
		return error;

	status = acpi_execute_simple_method(acpi->handle, "SFFS", value);

	if (ACPI_FAILURE(status))
		return -EINVAL;

	return count;
}

__attribute__((used)) static ssize_t irst_show_wakeup_time(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct acpi_device *acpi;
	unsigned long long value;
	acpi_status status;

	acpi = to_acpi_device(dev);

	status = acpi_evaluate_integer(acpi->handle, "GFTV", NULL, &value);
	if (ACPI_FAILURE(status))
		return -EINVAL;

	return sprintf(buf, "%lld\n", value);
}

__attribute__((used)) static ssize_t irst_store_wakeup_time(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	struct acpi_device *acpi;
	acpi_status status;
	unsigned long value;
	int error;

	acpi = to_acpi_device(dev);

	error = kstrtoul(buf, 0, &value);

	if (error)
		return error;

	status = acpi_execute_simple_method(acpi->handle, "SFTV", value);

	if (ACPI_FAILURE(status))
		return -EINVAL;

	return count;
}

__attribute__((used)) static int irst_add(struct acpi_device *acpi)
{
	int error;

	error = device_create_file(&acpi->dev, &irst_timeout_attr);
	if (unlikely(error))
		return error;

	error = device_create_file(&acpi->dev, &irst_wakeup_attr);
	if (unlikely(error))
		device_remove_file(&acpi->dev, &irst_timeout_attr);

	return error;
}

__attribute__((used)) static int irst_remove(struct acpi_device *acpi)
{
	device_remove_file(&acpi->dev, &irst_wakeup_attr);
	device_remove_file(&acpi->dev, &irst_timeout_attr);

	return 0;
}


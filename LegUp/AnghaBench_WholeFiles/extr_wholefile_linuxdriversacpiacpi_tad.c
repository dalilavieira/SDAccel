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
struct TYPE_2__ {scalar_t__ value; } ;
union acpi_object {TYPE_1__ integer; int /*<<< orphan*/  type; } ;
typedef  scalar_t__ u32 ;
struct device {int /*<<< orphan*/  kobj; } ;
struct platform_device {struct device dev; } ;
struct device_attribute {int dummy; } ;
struct acpi_tad_driver_data {scalar_t__ capabilities; } ;
struct acpi_object_list {int /*<<< orphan*/  count; union acpi_object* pointer; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HANDLE (struct device*) ; 
 scalar_t__ ACPI_TAD_AC_TIMER ; 
 unsigned long long ACPI_TAD_AC_WAKE ; 
 scalar_t__ ACPI_TAD_DC_TIMER ; 
 int ACPI_TAD_DC_WAKE ; 
 scalar_t__ ACPI_TAD_WAKE_DISABLED ; 
 int /*<<< orphan*/  ACPI_TYPE_INTEGER ; 
 int /*<<< orphan*/  ARRAY_SIZE (union acpi_object*) ; 
 int DPM_FLAG_LEAVE_SUSPENDED ; 
 int DPM_FLAG_SMART_SUSPEND ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,struct acpi_object_list*,unsigned long long*) ; 
 int /*<<< orphan*/  acpi_has_method (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  acpi_tad_attr_group ; 
 int /*<<< orphan*/  acpi_tad_dc_attr_group ; 
 char* alarm_specval ; 
 struct acpi_tad_driver_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_pm_set_driver_flags (struct device*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct acpi_tad_driver_data*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct acpi_tad_driver_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 
 int kstrtou32 (char const*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_suspend (struct device*) ; 
 char* policy_specval ; 
 int sprintf (char*,char*,scalar_t__) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ sysfs_streq (char const*,char const*) ; 

__attribute__((used)) static int acpi_tad_wake_set(struct device *dev, char *method, u32 timer_id,
			     u32 value)
{
	acpi_handle handle = ACPI_HANDLE(dev);
	union acpi_object args[] = {
		{ .type = ACPI_TYPE_INTEGER, },
		{ .type = ACPI_TYPE_INTEGER, },
	};
	struct acpi_object_list arg_list = {
		.pointer = args,
		.count = ARRAY_SIZE(args),
	};
	unsigned long long retval;
	acpi_status status;

	args[0].integer.value = timer_id;
	args[1].integer.value = value;

	pm_runtime_get_sync(dev);

	status = acpi_evaluate_integer(handle, method, &arg_list, &retval);

	pm_runtime_put_sync(dev);

	if (ACPI_FAILURE(status) || retval)
		return -EIO;

	return 0;
}

__attribute__((used)) static int acpi_tad_wake_write(struct device *dev, const char *buf, char *method,
			       u32 timer_id, const char *specval)
{
	u32 value;

	if (sysfs_streq(buf, specval)) {
		value = ACPI_TAD_WAKE_DISABLED;
	} else {
		int ret = kstrtou32(buf, 0, &value);

		if (ret)
			return ret;

		if (value == ACPI_TAD_WAKE_DISABLED)
			return -EINVAL;
	}

	return acpi_tad_wake_set(dev, method, timer_id, value);
}

__attribute__((used)) static ssize_t acpi_tad_wake_read(struct device *dev, char *buf, char *method,
				  u32 timer_id, const char *specval)
{
	acpi_handle handle = ACPI_HANDLE(dev);
	union acpi_object args[] = {
		{ .type = ACPI_TYPE_INTEGER, },
	};
	struct acpi_object_list arg_list = {
		.pointer = args,
		.count = ARRAY_SIZE(args),
	};
	unsigned long long retval;
	acpi_status status;

	args[0].integer.value = timer_id;

	pm_runtime_get_sync(dev);

	status = acpi_evaluate_integer(handle, method, &arg_list, &retval);

	pm_runtime_put_sync(dev);

	if (ACPI_FAILURE(status))
		return -EIO;

	if ((u32)retval == ACPI_TAD_WAKE_DISABLED)
		return sprintf(buf, "%s\n", specval);

	return sprintf(buf, "%u\n", (u32)retval);
}

__attribute__((used)) static int acpi_tad_alarm_write(struct device *dev, const char *buf,
				u32 timer_id)
{
	return acpi_tad_wake_write(dev, buf, "_STV", timer_id, alarm_specval);
}

__attribute__((used)) static ssize_t acpi_tad_alarm_read(struct device *dev, char *buf, u32 timer_id)
{
	return acpi_tad_wake_read(dev, buf, "_TIV", timer_id, alarm_specval);
}

__attribute__((used)) static int acpi_tad_policy_write(struct device *dev, const char *buf,
				 u32 timer_id)
{
	return acpi_tad_wake_write(dev, buf, "_STP", timer_id, policy_specval);
}

__attribute__((used)) static ssize_t acpi_tad_policy_read(struct device *dev, char *buf, u32 timer_id)
{
	return acpi_tad_wake_read(dev, buf, "_TIP", timer_id, policy_specval);
}

__attribute__((used)) static int acpi_tad_clear_status(struct device *dev, u32 timer_id)
{
	acpi_handle handle = ACPI_HANDLE(dev);
	union acpi_object args[] = {
		{ .type = ACPI_TYPE_INTEGER, },
	};
	struct acpi_object_list arg_list = {
		.pointer = args,
		.count = ARRAY_SIZE(args),
	};
	unsigned long long retval;
	acpi_status status;

	args[0].integer.value = timer_id;

	pm_runtime_get_sync(dev);

	status = acpi_evaluate_integer(handle, "_CWS", &arg_list, &retval);

	pm_runtime_put_sync(dev);

	if (ACPI_FAILURE(status) || retval)
		return -EIO;

	return 0;
}

__attribute__((used)) static int acpi_tad_status_write(struct device *dev, const char *buf, u32 timer_id)
{
	int ret, value;

	ret = kstrtoint(buf, 0, &value);
	if (ret)
		return ret;

	if (value)
		return -EINVAL;

	return acpi_tad_clear_status(dev, timer_id);
}

__attribute__((used)) static ssize_t acpi_tad_status_read(struct device *dev, char *buf, u32 timer_id)
{
	acpi_handle handle = ACPI_HANDLE(dev);
	union acpi_object args[] = {
		{ .type = ACPI_TYPE_INTEGER, },
	};
	struct acpi_object_list arg_list = {
		.pointer = args,
		.count = ARRAY_SIZE(args),
	};
	unsigned long long retval;
	acpi_status status;

	args[0].integer.value = timer_id;

	pm_runtime_get_sync(dev);

	status = acpi_evaluate_integer(handle, "_GWS", &arg_list, &retval);

	pm_runtime_put_sync(dev);

	if (ACPI_FAILURE(status))
		return -EIO;

	return sprintf(buf, "0x%02X\n", (u32)retval);
}

__attribute__((used)) static ssize_t caps_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct acpi_tad_driver_data *dd = dev_get_drvdata(dev);

	return sprintf(buf, "0x%02X\n", dd->capabilities);
}

__attribute__((used)) static ssize_t ac_alarm_store(struct device *dev, struct device_attribute *attr,
			      const char *buf, size_t count)
{
	int ret = acpi_tad_alarm_write(dev, buf, ACPI_TAD_AC_TIMER);

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t ac_alarm_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	return acpi_tad_alarm_read(dev, buf, ACPI_TAD_AC_TIMER);
}

__attribute__((used)) static ssize_t ac_policy_store(struct device *dev, struct device_attribute *attr,
			       const char *buf, size_t count)
{
	int ret = acpi_tad_policy_write(dev, buf, ACPI_TAD_AC_TIMER);

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t ac_policy_show(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return acpi_tad_policy_read(dev, buf, ACPI_TAD_AC_TIMER);
}

__attribute__((used)) static ssize_t ac_status_store(struct device *dev, struct device_attribute *attr,
			       const char *buf, size_t count)
{
	int ret = acpi_tad_status_write(dev, buf, ACPI_TAD_AC_TIMER);

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t ac_status_show(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return acpi_tad_status_read(dev, buf, ACPI_TAD_AC_TIMER);
}

__attribute__((used)) static ssize_t dc_alarm_store(struct device *dev, struct device_attribute *attr,
			      const char *buf, size_t count)
{
	int ret = acpi_tad_alarm_write(dev, buf, ACPI_TAD_DC_TIMER);

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t dc_alarm_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	return acpi_tad_alarm_read(dev, buf, ACPI_TAD_DC_TIMER);
}

__attribute__((used)) static ssize_t dc_policy_store(struct device *dev, struct device_attribute *attr,
			       const char *buf, size_t count)
{
	int ret = acpi_tad_policy_write(dev, buf, ACPI_TAD_DC_TIMER);

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t dc_policy_show(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return acpi_tad_policy_read(dev, buf, ACPI_TAD_DC_TIMER);
}

__attribute__((used)) static ssize_t dc_status_store(struct device *dev, struct device_attribute *attr,
			       const char *buf, size_t count)
{
	int ret = acpi_tad_status_write(dev, buf, ACPI_TAD_DC_TIMER);

	return ret ? ret : count;
}

__attribute__((used)) static ssize_t dc_status_show(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return acpi_tad_status_read(dev, buf, ACPI_TAD_DC_TIMER);
}

__attribute__((used)) static int acpi_tad_disable_timer(struct device *dev, u32 timer_id)
{
	return acpi_tad_wake_set(dev, "_STV", timer_id, ACPI_TAD_WAKE_DISABLED);
}

__attribute__((used)) static int acpi_tad_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct acpi_tad_driver_data *dd = dev_get_drvdata(dev);

	device_init_wakeup(dev, false);

	pm_runtime_get_sync(dev);

	if (dd->capabilities & ACPI_TAD_DC_WAKE)
		sysfs_remove_group(&dev->kobj, &acpi_tad_dc_attr_group);

	sysfs_remove_group(&dev->kobj, &acpi_tad_attr_group);

	acpi_tad_disable_timer(dev, ACPI_TAD_AC_TIMER);
	acpi_tad_clear_status(dev, ACPI_TAD_AC_TIMER);
	if (dd->capabilities & ACPI_TAD_DC_WAKE) {
		acpi_tad_disable_timer(dev, ACPI_TAD_DC_TIMER);
		acpi_tad_clear_status(dev, ACPI_TAD_DC_TIMER);
	}

	pm_runtime_put_sync(dev);
	pm_runtime_disable(dev);
	return 0;
}

__attribute__((used)) static int acpi_tad_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	acpi_handle handle = ACPI_HANDLE(dev);
	struct acpi_tad_driver_data *dd;
	acpi_status status;
	unsigned long long caps;
	int ret;

	/*
	 * Initialization failure messages are mostly about firmware issues, so
	 * print them at the "info" level.
	 */
	status = acpi_evaluate_integer(handle, "_GCP", NULL, &caps);
	if (ACPI_FAILURE(status)) {
		dev_info(dev, "Unable to get capabilities\n");
		return -ENODEV;
	}

	if (!(caps & ACPI_TAD_AC_WAKE)) {
		dev_info(dev, "Unsupported capabilities\n");
		return -ENODEV;
	}

	if (!acpi_has_method(handle, "_PRW")) {
		dev_info(dev, "Missing _PRW\n");
		return -ENODEV;
	}

	dd = devm_kzalloc(dev, sizeof(*dd), GFP_KERNEL);
	if (!dd)
		return -ENOMEM;

	dd->capabilities = caps;
	dev_set_drvdata(dev, dd);

	/*
	 * Assume that the ACPI PM domain has been attached to the device and
	 * simply enable system wakeup and runtime PM and put the device into
	 * runtime suspend.  Everything else should be taken care of by the ACPI
	 * PM domain callbacks.
	 */
	device_init_wakeup(dev, true);
	dev_pm_set_driver_flags(dev, DPM_FLAG_SMART_SUSPEND |
				     DPM_FLAG_LEAVE_SUSPENDED);
	/*
	 * The platform bus type layer tells the ACPI PM domain powers up the
	 * device, so set the runtime PM status of it to "active".
	 */
	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	pm_runtime_suspend(dev);

	ret = sysfs_create_group(&dev->kobj, &acpi_tad_attr_group);
	if (ret)
		goto fail;

	if (caps & ACPI_TAD_DC_WAKE) {
		ret = sysfs_create_group(&dev->kobj, &acpi_tad_dc_attr_group);
		if (ret)
			goto fail;
	}

	return 0;

fail:
	acpi_tad_remove(pdev);
	return ret;
}


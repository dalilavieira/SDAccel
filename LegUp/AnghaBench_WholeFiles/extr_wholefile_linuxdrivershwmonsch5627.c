#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct sensor_device_attribute {size_t index; } ;
struct sch5627_data {int control; int valid; int* temp; int* fan; int* in; int* temp_max; int* temp_crit; int* fan_min; int /*<<< orphan*/  update_lock; int /*<<< orphan*/  addr; scalar_t__ watchdog; struct sch5627_data* hwmon_dev; void* last_battery; void* last_updated; } ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_6__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 char* DEVNAME ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct sch5627_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 scalar_t__ IS_ERR (struct sch5627_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct sch5627_data*) ; 
 int SCH5627_COMPANY_ID ; 
 int SCH5627_HWMON_ID ; 
 char** SCH5627_IN_LABELS ; 
 int SCH5627_NO_FANS ; 
 int SCH5627_NO_IN ; 
 int SCH5627_NO_TEMPS ; 
 int SCH5627_PRIMARY_ID ; 
 int /*<<< orphan*/  SCH5627_REG_BUILD_CODE ; 
 int /*<<< orphan*/  SCH5627_REG_BUILD_ID ; 
 int /*<<< orphan*/  SCH5627_REG_COMPANY_ID ; 
 int /*<<< orphan*/  SCH5627_REG_CTRL ; 
 int /*<<< orphan*/ * SCH5627_REG_FAN ; 
 int /*<<< orphan*/ * SCH5627_REG_FAN_MIN ; 
 int /*<<< orphan*/  SCH5627_REG_HWMON_ID ; 
 int /*<<< orphan*/  SCH5627_REG_HWMON_REV ; 
 int* SCH5627_REG_IN_FACTOR ; 
 int /*<<< orphan*/ * SCH5627_REG_IN_HIGH_NIBBLE ; 
 int /*<<< orphan*/ * SCH5627_REG_IN_LSN ; 
 int /*<<< orphan*/ * SCH5627_REG_IN_MSB ; 
 int /*<<< orphan*/  SCH5627_REG_PRIMARY_ID ; 
 int /*<<< orphan*/ * SCH5627_REG_TEMP_ABS ; 
 int /*<<< orphan*/ * SCH5627_REG_TEMP_HIGH ; 
 int /*<<< orphan*/ * SCH5627_REG_TEMP_HIGH_NIBBLE ; 
 int /*<<< orphan*/ * SCH5627_REG_TEMP_LSN ; 
 int /*<<< orphan*/ * SCH5627_REG_TEMP_MSB ; 
 struct sch5627_data* dev_get_drvdata (struct device*) ; 
 struct sch5627_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct sch5627_data* hwmon_device_register (TYPE_1__*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (struct sch5627_data*) ; 
 void* jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct sch5627_data* platform_get_drvdata (struct platform_device*) ; 
 TYPE_2__* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sch5627_data*) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  sch5627_group ; 
 int sch56xx_read_virtual_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sch56xx_read_virtual_reg12 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sch56xx_read_virtual_reg16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ sch56xx_watchdog_register (TYPE_1__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sch56xx_watchdog_unregister (scalar_t__) ; 
 int /*<<< orphan*/  sch56xx_write_virtual_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,...) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (void*,void*) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct sch5627_data *sch5627_update_device(struct device *dev)
{
	struct sch5627_data *data = dev_get_drvdata(dev);
	struct sch5627_data *ret = data;
	int i, val;

	mutex_lock(&data->update_lock);

	/* Trigger a Vbat voltage measurement every 5 minutes */
	if (time_after(jiffies, data->last_battery + 300 * HZ)) {
		sch56xx_write_virtual_reg(data->addr, SCH5627_REG_CTRL,
					  data->control | 0x10);
		data->last_battery = jiffies;
	}

	/* Cache the values for 1 second */
	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		for (i = 0; i < SCH5627_NO_TEMPS; i++) {
			val = sch56xx_read_virtual_reg12(data->addr,
				SCH5627_REG_TEMP_MSB[i],
				SCH5627_REG_TEMP_LSN[i],
				SCH5627_REG_TEMP_HIGH_NIBBLE[i]);
			if (unlikely(val < 0)) {
				ret = ERR_PTR(val);
				goto abort;
			}
			data->temp[i] = val;
		}

		for (i = 0; i < SCH5627_NO_FANS; i++) {
			val = sch56xx_read_virtual_reg16(data->addr,
							 SCH5627_REG_FAN[i]);
			if (unlikely(val < 0)) {
				ret = ERR_PTR(val);
				goto abort;
			}
			data->fan[i] = val;
		}

		for (i = 0; i < SCH5627_NO_IN; i++) {
			val = sch56xx_read_virtual_reg12(data->addr,
				SCH5627_REG_IN_MSB[i],
				SCH5627_REG_IN_LSN[i],
				SCH5627_REG_IN_HIGH_NIBBLE[i]);
			if (unlikely(val < 0)) {
				ret = ERR_PTR(val);
				goto abort;
			}
			data->in[i] = val;
		}

		data->last_updated = jiffies;
		data->valid = 1;
	}
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static int sch5627_read_limits(struct sch5627_data *data)
{
	int i, val;

	for (i = 0; i < SCH5627_NO_TEMPS; i++) {
		/*
		 * Note what SMSC calls ABS, is what lm_sensors calls max
		 * (aka high), and HIGH is what lm_sensors calls crit.
		 */
		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5627_REG_TEMP_ABS[i]);
		if (val < 0)
			return val;
		data->temp_max[i] = val;

		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5627_REG_TEMP_HIGH[i]);
		if (val < 0)
			return val;
		data->temp_crit[i] = val;
	}
	for (i = 0; i < SCH5627_NO_FANS; i++) {
		val = sch56xx_read_virtual_reg16(data->addr,
						 SCH5627_REG_FAN_MIN[i]);
		if (val < 0)
			return val;
		data->fan_min[i] = val;
	}

	return 0;
}

__attribute__((used)) static int reg_to_temp(u16 reg)
{
	return (reg * 625) / 10 - 64000;
}

__attribute__((used)) static int reg_to_temp_limit(u8 reg)
{
	return (reg - 64) * 1000;
}

__attribute__((used)) static int reg_to_rpm(u16 reg)
{
	if (reg == 0)
		return -EIO;
	if (reg == 0xffff)
		return 0;

	return 5400540 / reg;
}

__attribute__((used)) static ssize_t name_show(struct device *dev, struct device_attribute *devattr,
	char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%s\n", DEVNAME);
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = sch5627_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = reg_to_temp(data->temp[attr->index]);
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_temp_fault(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = sch5627_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return snprintf(buf, PAGE_SIZE, "%d\n", data->temp[attr->index] == 0);
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = dev_get_drvdata(dev);
	int val;

	val = reg_to_temp_limit(data->temp_max[attr->index]);
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_temp_crit(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = dev_get_drvdata(dev);
	int val;

	val = reg_to_temp_limit(data->temp_crit[attr->index]);
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = sch5627_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = reg_to_rpm(data->fan[attr->index]);
	if (val < 0)
		return val;

	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_fan_fault(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = sch5627_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return snprintf(buf, PAGE_SIZE, "%d\n",
			data->fan[attr->index] == 0xffff);
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = dev_get_drvdata(dev);
	int val = reg_to_rpm(data->fan_min[attr->index]);
	if (val < 0)
		return val;

	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5627_data *data = sch5627_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = DIV_ROUND_CLOSEST(
		data->in[attr->index] * SCH5627_REG_IN_FACTOR[attr->index],
		10000);
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_in_label(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);

	return snprintf(buf, PAGE_SIZE, "%s\n",
			SCH5627_IN_LABELS[attr->index]);
}

__attribute__((used)) static int sch5627_remove(struct platform_device *pdev)
{
	struct sch5627_data *data = platform_get_drvdata(pdev);

	if (data->watchdog)
		sch56xx_watchdog_unregister(data->watchdog);

	if (data->hwmon_dev)
		hwmon_device_unregister(data->hwmon_dev);

	sysfs_remove_group(&pdev->dev.kobj, &sch5627_group);

	return 0;
}

__attribute__((used)) static int sch5627_probe(struct platform_device *pdev)
{
	struct sch5627_data *data;
	int err, build_code, build_id, hwmon_rev, val;

	data = devm_kzalloc(&pdev->dev, sizeof(struct sch5627_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
	mutex_init(&data->update_lock);
	platform_set_drvdata(pdev, data);

	val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_HWMON_ID);
	if (val < 0) {
		err = val;
		goto error;
	}
	if (val != SCH5627_HWMON_ID) {
		pr_err("invalid %s id: 0x%02X (expected 0x%02X)\n", "hwmon",
		       val, SCH5627_HWMON_ID);
		err = -ENODEV;
		goto error;
	}

	val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_COMPANY_ID);
	if (val < 0) {
		err = val;
		goto error;
	}
	if (val != SCH5627_COMPANY_ID) {
		pr_err("invalid %s id: 0x%02X (expected 0x%02X)\n", "company",
		       val, SCH5627_COMPANY_ID);
		err = -ENODEV;
		goto error;
	}

	val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_PRIMARY_ID);
	if (val < 0) {
		err = val;
		goto error;
	}
	if (val != SCH5627_PRIMARY_ID) {
		pr_err("invalid %s id: 0x%02X (expected 0x%02X)\n", "primary",
		       val, SCH5627_PRIMARY_ID);
		err = -ENODEV;
		goto error;
	}

	build_code = sch56xx_read_virtual_reg(data->addr,
					      SCH5627_REG_BUILD_CODE);
	if (build_code < 0) {
		err = build_code;
		goto error;
	}

	build_id = sch56xx_read_virtual_reg16(data->addr,
					      SCH5627_REG_BUILD_ID);
	if (build_id < 0) {
		err = build_id;
		goto error;
	}

	hwmon_rev = sch56xx_read_virtual_reg(data->addr,
					     SCH5627_REG_HWMON_REV);
	if (hwmon_rev < 0) {
		err = hwmon_rev;
		goto error;
	}

	val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_CTRL);
	if (val < 0) {
		err = val;
		goto error;
	}
	data->control = val;
	if (!(data->control & 0x01)) {
		pr_err("hardware monitoring not enabled\n");
		err = -ENODEV;
		goto error;
	}
	/* Trigger a Vbat voltage measurement, so that we get a valid reading
	   the first time we read Vbat */
	sch56xx_write_virtual_reg(data->addr, SCH5627_REG_CTRL,
				  data->control | 0x10);
	data->last_battery = jiffies;

	/*
	 * Read limits, we do this only once as reading a register on
	 * the sch5627 is quite expensive (and they don't change).
	 */
	err = sch5627_read_limits(data);
	if (err)
		goto error;

	pr_info("found %s chip at %#hx\n", DEVNAME, data->addr);
	pr_info("firmware build: code 0x%02X, id 0x%04X, hwmon: rev 0x%02X\n",
		build_code, build_id, hwmon_rev);

	/* Register sysfs interface files */
	err = sysfs_create_group(&pdev->dev.kobj, &sch5627_group);
	if (err)
		goto error;

	data->hwmon_dev = hwmon_device_register(&pdev->dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		data->hwmon_dev = NULL;
		goto error;
	}

	/* Note failing to register the watchdog is not a fatal error */
	data->watchdog = sch56xx_watchdog_register(&pdev->dev, data->addr,
			(build_code << 24) | (build_id << 8) | hwmon_rev,
			&data->update_lock, 1);

	return 0;

error:
	sch5627_remove(pdev);
	return err;
}


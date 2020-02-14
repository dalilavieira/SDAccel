#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct sensor_device_attribute {size_t index; } ;
struct sch5636_data {int valid; int* in; int* temp_ctrl; int* temp_val; int* fan_ctrl; int* fan_val; int /*<<< orphan*/  update_lock; int /*<<< orphan*/  addr; scalar_t__ watchdog; struct sch5636_data* hwmon_dev; scalar_t__ last_updated; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_9__ {int /*<<< orphan*/  start; } ;
struct TYPE_8__ {int /*<<< orphan*/  dev_attr; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev_attr; } ;
struct TYPE_6__ {int /*<<< orphan*/  dev_attr; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 char* DEVNAME ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct sch5636_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 scalar_t__ IS_ERR (struct sch5636_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct sch5636_data*) ; 
 int SCH5636_FAN_ALARM ; 
 int SCH5636_FAN_DEACTIVATED ; 
 int SCH5636_FAN_NOT_PRESENT ; 
 char** SCH5636_IN_LABELS ; 
 int SCH5636_NO_FANS ; 
 int SCH5636_NO_INS ; 
 int SCH5636_NO_TEMPS ; 
 scalar_t__ SCH5636_REG_FAN_CTRL (int) ; 
 int /*<<< orphan*/ * SCH5636_REG_FAN_VAL ; 
 scalar_t__ SCH5636_REG_FUJITSU_ID ; 
 scalar_t__ SCH5636_REG_FUJITSU_REV ; 
 int* SCH5636_REG_IN_FACTORS ; 
 scalar_t__* SCH5636_REG_IN_VAL ; 
 scalar_t__ SCH5636_REG_TEMP_CTRL (int) ; 
 scalar_t__* SCH5636_REG_TEMP_VAL ; 
 int SCH5636_TEMP_ALARM ; 
 int SCH5636_TEMP_DEACTIVATED ; 
 int SCH5636_TEMP_WORKING ; 
 struct sch5636_data* dev_get_drvdata (struct device*) ; 
 int device_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct sch5636_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct sch5636_data* hwmon_device_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hwmon_device_unregister (struct sch5636_data*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct sch5636_data* platform_get_drvdata (struct platform_device*) ; 
 TYPE_4__* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sch5636_data*) ; 
 int /*<<< orphan*/  pr_err (char*,char,...) ; 
 int /*<<< orphan*/  pr_info (char*,char*,int /*<<< orphan*/ ,int,int) ; 
 TYPE_3__* sch5636_attr ; 
 TYPE_2__* sch5636_fan_attr ; 
 TYPE_1__* sch5636_temp_attr ; 
 int sch56xx_read_virtual_reg (int /*<<< orphan*/ ,scalar_t__) ; 
 int sch56xx_read_virtual_reg16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ sch56xx_watchdog_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sch56xx_watchdog_unregister (scalar_t__) ; 
 int /*<<< orphan*/  sch56xx_write_virtual_reg (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct sch5636_data *sch5636_update_device(struct device *dev)
{
	struct sch5636_data *data = dev_get_drvdata(dev);
	struct sch5636_data *ret = data;
	int i, val;

	mutex_lock(&data->update_lock);

	/* Cache the values for 1 second */
	if (data->valid && !time_after(jiffies, data->last_updated + HZ))
		goto abort;

	for (i = 0; i < SCH5636_NO_INS; i++) {
		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_IN_VAL[i]);
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->in[i] = val;
	}

	for (i = 0; i < SCH5636_NO_TEMPS; i++) {
		if (data->temp_ctrl[i] & SCH5636_TEMP_DEACTIVATED)
			continue;

		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_TEMP_VAL[i]);
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->temp_val[i] = val;

		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_TEMP_CTRL(i));
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->temp_ctrl[i] = val;
		/* Alarms need to be explicitly write-cleared */
		if (val & SCH5636_TEMP_ALARM) {
			sch56xx_write_virtual_reg(data->addr,
						SCH5636_REG_TEMP_CTRL(i), val);
		}
	}

	for (i = 0; i < SCH5636_NO_FANS; i++) {
		if (data->fan_ctrl[i] & SCH5636_FAN_DEACTIVATED)
			continue;

		val = sch56xx_read_virtual_reg16(data->addr,
						 SCH5636_REG_FAN_VAL[i]);
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->fan_val[i] = val;

		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_FAN_CTRL(i));
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->fan_ctrl[i] = val;
		/* Alarms need to be explicitly write-cleared */
		if (val & SCH5636_FAN_ALARM) {
			sch56xx_write_virtual_reg(data->addr,
						SCH5636_REG_FAN_CTRL(i), val);
		}
	}

	data->last_updated = jiffies;
	data->valid = 1;
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static int reg_to_rpm(u16 reg)
{
	if (reg == 0)
		return -EIO;
	if (reg == 0xffff)
		return 0;

	return 5400540 / reg;
}

__attribute__((used)) static ssize_t show_name(struct device *dev, struct device_attribute *devattr,
	char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%s\n", DEVNAME);
}

__attribute__((used)) static ssize_t show_in_value(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = DIV_ROUND_CLOSEST(
		data->in[attr->index] * SCH5636_REG_IN_FACTORS[attr->index],
		255);
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_in_label(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);

	return snprintf(buf, PAGE_SIZE, "%s\n",
			SCH5636_IN_LABELS[attr->index]);
}

__attribute__((used)) static ssize_t show_temp_value(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = (data->temp_val[attr->index] - 64) * 1000;
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_temp_fault(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = (data->temp_ctrl[attr->index] & SCH5636_TEMP_WORKING) ? 0 : 1;
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_temp_alarm(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = (data->temp_ctrl[attr->index] & SCH5636_TEMP_ALARM) ? 1 : 0;
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_fan_value(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = reg_to_rpm(data->fan_val[attr->index]);
	if (val < 0)
		return val;

	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_fan_fault(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = (data->fan_ctrl[attr->index] & SCH5636_FAN_NOT_PRESENT) ? 1 : 0;
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t show_fan_alarm(struct device *dev, struct device_attribute
	*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct sch5636_data *data = sch5636_update_device(dev);
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = (data->fan_ctrl[attr->index] & SCH5636_FAN_ALARM) ? 1 : 0;
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static int sch5636_remove(struct platform_device *pdev)
{
	struct sch5636_data *data = platform_get_drvdata(pdev);
	int i;

	if (data->watchdog)
		sch56xx_watchdog_unregister(data->watchdog);

	if (data->hwmon_dev)
		hwmon_device_unregister(data->hwmon_dev);

	for (i = 0; i < ARRAY_SIZE(sch5636_attr); i++)
		device_remove_file(&pdev->dev, &sch5636_attr[i].dev_attr);

	for (i = 0; i < SCH5636_NO_TEMPS * 3; i++)
		device_remove_file(&pdev->dev,
				   &sch5636_temp_attr[i].dev_attr);

	for (i = 0; i < SCH5636_NO_FANS * 3; i++)
		device_remove_file(&pdev->dev,
				   &sch5636_fan_attr[i].dev_attr);

	return 0;
}

__attribute__((used)) static int sch5636_probe(struct platform_device *pdev)
{
	struct sch5636_data *data;
	int i, err, val, revision[2];
	char id[4];

	data = devm_kzalloc(&pdev->dev, sizeof(struct sch5636_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
	mutex_init(&data->update_lock);
	platform_set_drvdata(pdev, data);

	for (i = 0; i < 3; i++) {
		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_FUJITSU_ID + i);
		if (val < 0) {
			pr_err("Could not read Fujitsu id byte at %#x\n",
				SCH5636_REG_FUJITSU_ID + i);
			err = val;
			goto error;
		}
		id[i] = val;
	}
	id[i] = '\0';

	if (strcmp(id, "THS")) {
		pr_err("Unknown Fujitsu id: %02x%02x%02x\n",
		       id[0], id[1], id[2]);
		err = -ENODEV;
		goto error;
	}

	for (i = 0; i < 2; i++) {
		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_FUJITSU_REV + i);
		if (val < 0) {
			err = val;
			goto error;
		}
		revision[i] = val;
	}
	pr_info("Found %s chip at %#hx, revision: %d.%02d\n", DEVNAME,
		data->addr, revision[0], revision[1]);

	/* Read all temp + fan ctrl registers to determine which are active */
	for (i = 0; i < SCH5636_NO_TEMPS; i++) {
		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_TEMP_CTRL(i));
		if (unlikely(val < 0)) {
			err = val;
			goto error;
		}
		data->temp_ctrl[i] = val;
	}

	for (i = 0; i < SCH5636_NO_FANS; i++) {
		val = sch56xx_read_virtual_reg(data->addr,
					       SCH5636_REG_FAN_CTRL(i));
		if (unlikely(val < 0)) {
			err = val;
			goto error;
		}
		data->fan_ctrl[i] = val;
	}

	for (i = 0; i < ARRAY_SIZE(sch5636_attr); i++) {
		err = device_create_file(&pdev->dev,
					 &sch5636_attr[i].dev_attr);
		if (err)
			goto error;
	}

	for (i = 0; i < (SCH5636_NO_TEMPS * 3); i++) {
		if (data->temp_ctrl[i/3] & SCH5636_TEMP_DEACTIVATED)
			continue;

		err = device_create_file(&pdev->dev,
					&sch5636_temp_attr[i].dev_attr);
		if (err)
			goto error;
	}

	for (i = 0; i < (SCH5636_NO_FANS * 3); i++) {
		if (data->fan_ctrl[i/3] & SCH5636_FAN_DEACTIVATED)
			continue;

		err = device_create_file(&pdev->dev,
					&sch5636_fan_attr[i].dev_attr);
		if (err)
			goto error;
	}

	data->hwmon_dev = hwmon_device_register(&pdev->dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		data->hwmon_dev = NULL;
		goto error;
	}

	/* Note failing to register the watchdog is not a fatal error */
	data->watchdog = sch56xx_watchdog_register(&pdev->dev, data->addr,
					(revision[0] << 8) | revision[1],
					&data->update_lock, 0);

	return 0;

error:
	sch5636_remove(pdev);
	return err;
}


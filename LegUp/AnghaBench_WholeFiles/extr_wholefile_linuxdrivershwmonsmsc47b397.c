#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct smsc47b397_data {int valid; int* temp; int* fan; int /*<<< orphan*/  update_lock; int /*<<< orphan*/  lock; scalar_t__ addr; scalar_t__ last_updated; } ;
struct sensor_device_attribute {size_t index; } ;
struct resource {scalar_t__ start; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int s8 ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {TYPE_1__ driver; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 scalar_t__ REG ; 
 int SMSC47B397_REG_FAN_LSB (int) ; 
 int SMSC47B397_REG_FAN_MSB (int) ; 
 int SMSC47B397_REG_TEMP (int) ; 
 scalar_t__ SMSC_EXTENT ; 
 scalar_t__ VAL ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,unsigned long,scalar_t__) ; 
 struct smsc47b397_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,char*,struct smsc47b397_data*,int /*<<< orphan*/ ) ; 
 struct smsc47b397_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_request_region (struct device*,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 int inb_p (scalar_t__) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ smsc47b397_driver ; 
 int /*<<< orphan*/  smsc47b397_groups ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline void superio_outb(int reg, int val)
{
	outb(reg, REG);
	outb(val, VAL);
}

__attribute__((used)) static inline int superio_inb(int reg)
{
	outb(reg, REG);
	return inb(VAL);
}

__attribute__((used)) static inline void superio_select(int ld)
{
	superio_outb(0x07, ld);
}

__attribute__((used)) static inline void superio_enter(void)
{
	outb(0x55, REG);
}

__attribute__((used)) static inline void superio_exit(void)
{
	outb(0xAA, REG);
}

__attribute__((used)) static int smsc47b397_read_value(struct smsc47b397_data *data, u8 reg)
{
	int res;

	mutex_lock(&data->lock);
	outb(reg, data->addr);
	res = inb_p(data->addr + 1);
	mutex_unlock(&data->lock);
	return res;
}

__attribute__((used)) static struct smsc47b397_data *smsc47b397_update_device(struct device *dev)
{
	struct smsc47b397_data *data = dev_get_drvdata(dev);
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		dev_dbg(dev, "starting device update...\n");

		/* 4 temperature inputs, 4 fan inputs */
		for (i = 0; i < 4; i++) {
			data->temp[i] = smsc47b397_read_value(data,
					SMSC47B397_REG_TEMP(i));

			/* must read LSB first */
			data->fan[i]  = smsc47b397_read_value(data,
					SMSC47B397_REG_FAN_LSB(i));
			data->fan[i] |= smsc47b397_read_value(data,
					SMSC47B397_REG_FAN_MSB(i)) << 8;
		}

		data->last_updated = jiffies;
		data->valid = 1;

		dev_dbg(dev, "... device update complete\n");
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static int temp_from_reg(u8 reg)
{
	return (s8)reg * 1000;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute
			 *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct smsc47b397_data *data = smsc47b397_update_device(dev);
	return sprintf(buf, "%d\n", temp_from_reg(data->temp[attr->index]));
}

__attribute__((used)) static int fan_from_reg(u16 reg)
{
	if (reg == 0 || reg == 0xffff)
		return 0;
	return 90000 * 60 / reg;
}

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute
			*devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct smsc47b397_data *data = smsc47b397_update_device(dev);
	return sprintf(buf, "%d\n", fan_from_reg(data->fan[attr->index]));
}

__attribute__((used)) static int smsc47b397_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct smsc47b397_data *data;
	struct device *hwmon_dev;
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if (!devm_request_region(dev, res->start, SMSC_EXTENT,
				 smsc47b397_driver.driver.name)) {
		dev_err(dev, "Region 0x%lx-0x%lx already in use!\n",
			(unsigned long)res->start,
			(unsigned long)res->start + SMSC_EXTENT - 1);
		return -EBUSY;
	}

	data = devm_kzalloc(dev, sizeof(struct smsc47b397_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->addr = res->start;
	mutex_init(&data->lock);
	mutex_init(&data->update_lock);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, "smsc47b397",
							   data,
							   smsc47b397_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


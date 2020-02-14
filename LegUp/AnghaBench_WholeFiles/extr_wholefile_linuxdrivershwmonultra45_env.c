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
typedef  int u8 ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct platform_device {int /*<<< orphan*/ * resource; TYPE_2__ dev; } ;
struct env {scalar_t__ regs; int /*<<< orphan*/  hwmon_dev; int /*<<< orphan*/  lock; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int s8 ;
struct TYPE_4__ {int index; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ FAN_DATA_VALID (int) ; 
 int FAN_PERIOD_TO_RPM (int) ; 
 int FAN_RPM_TO_PERIOD (unsigned long) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IREG_FAN0 ; 
 int IREG_FAN_STAT ; 
 int IREG_LCL_TEMP ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ REG_ADDR ; 
 scalar_t__ REG_DATA ; 
 int /*<<< orphan*/  REG_SIZE ; 
 scalar_t__ REG_STAT ; 
 struct env* dev_get_drvdata (struct device*) ; 
 struct env* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  env_group ; 
 int /*<<< orphan*/  hwmon_device_register (TYPE_2__*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 scalar_t__ of_ioremap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  of_iounmap (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ) ; 
 struct env* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct env*) ; 
 int readb (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,...) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static u8 env_read(struct env *p, u8 ireg)
{
	u8 ret;

	spin_lock(&p->lock);
	writeb(ireg, p->regs + REG_ADDR);
	ret = readb(p->regs + REG_DATA);
	spin_unlock(&p->lock);

	return ret;
}

__attribute__((used)) static void env_write(struct env *p, u8 ireg, u8 val)
{
	spin_lock(&p->lock);
	writeb(ireg, p->regs + REG_ADDR);
	writeb(val, p->regs + REG_DATA);
	spin_unlock(&p->lock);
}

__attribute__((used)) static ssize_t show_fan_speed(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	int fan_nr = to_sensor_dev_attr(attr)->index;
	struct env *p = dev_get_drvdata(dev);
	int rpm, period;
	u8 val;

	val = env_read(p, IREG_FAN0 + fan_nr);
	period = (int) val << 8;
	if (FAN_DATA_VALID(period))
		rpm = FAN_PERIOD_TO_RPM(period);
	else
		rpm = 0;

	return sprintf(buf, "%d\n", rpm);
}

__attribute__((used)) static ssize_t set_fan_speed(struct device *dev, struct device_attribute *attr,
			     const char *buf, size_t count)
{
	int fan_nr = to_sensor_dev_attr(attr)->index;
	unsigned long rpm;
	struct env *p = dev_get_drvdata(dev);
	int period;
	u8 val;
	int err;

	err = kstrtoul(buf, 10, &rpm);
	if (err)
		return err;

	if (!rpm)
		return -EINVAL;

	period = FAN_RPM_TO_PERIOD(rpm);
	val = period >> 8;
	env_write(p, IREG_FAN0 + fan_nr, val);

	return count;
}

__attribute__((used)) static ssize_t show_fan_fault(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	int fan_nr = to_sensor_dev_attr(attr)->index;
	struct env *p = dev_get_drvdata(dev);
	u8 val = env_read(p, IREG_FAN_STAT);
	return sprintf(buf, "%d\n", (val & (1 << fan_nr)) ? 1 : 0);
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	int temp_nr = to_sensor_dev_attr(attr)->index;
	struct env *p = dev_get_drvdata(dev);
	s8 val;

	val = env_read(p, IREG_LCL_TEMP + temp_nr);
	return sprintf(buf, "%d\n", ((int) val) - 64);
}

__attribute__((used)) static ssize_t show_stat_bit(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct env *p = dev_get_drvdata(dev);
	u8 val;

	val = readb(p->regs + REG_STAT);
	return sprintf(buf, "%d\n", (val & (1 << index)) ? 1 : 0);
}

__attribute__((used)) static ssize_t show_fwver(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct env *p = dev_get_drvdata(dev);
	u8 val;

	val = readb(p->regs + REG_STAT);
	return sprintf(buf, "%d\n", val >> 4);
}

__attribute__((used)) static ssize_t show_name(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return sprintf(buf, "ultra45\n");
}

__attribute__((used)) static int env_probe(struct platform_device *op)
{
	struct env *p = devm_kzalloc(&op->dev, sizeof(*p), GFP_KERNEL);
	int err = -ENOMEM;

	if (!p)
		goto out;

	spin_lock_init(&p->lock);

	p->regs = of_ioremap(&op->resource[0], 0, REG_SIZE, "pic16f747");
	if (!p->regs)
		goto out;

	err = sysfs_create_group(&op->dev.kobj, &env_group);
	if (err)
		goto out_iounmap;

	p->hwmon_dev = hwmon_device_register(&op->dev);
	if (IS_ERR(p->hwmon_dev)) {
		err = PTR_ERR(p->hwmon_dev);
		goto out_sysfs_remove_group;
	}

	platform_set_drvdata(op, p);
	err = 0;

out:
	return err;

out_sysfs_remove_group:
	sysfs_remove_group(&op->dev.kobj, &env_group);

out_iounmap:
	of_iounmap(&op->resource[0], p->regs, REG_SIZE);

	goto out;
}

__attribute__((used)) static int env_remove(struct platform_device *op)
{
	struct env *p = platform_get_drvdata(op);

	if (p) {
		sysfs_remove_group(&op->dev.kobj, &env_group);
		hwmon_device_unregister(p->hwmon_dev);
		of_iounmap(&op->resource[0], p->regs, REG_SIZE);
	}

	return 0;
}


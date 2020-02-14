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
typedef  int u32 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct nsa320_hwmon {int mcu_data; int /*<<< orphan*/  update_lock; void* data; void* clk; void* act; scalar_t__ last_updated; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int s32 ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int BIT (int) ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ HZ ; 
 scalar_t__ IS_ERR (void*) ; 
 int MAGIC_NUMBER ; 
 int PTR_ERR (void*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 struct nsa320_hwmon* dev_get_drvdata (struct device*) ; 
 void* devm_gpiod_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct device* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,char*,struct nsa320_hwmon*,int /*<<< orphan*/ ) ; 
 struct nsa320_hwmon* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 scalar_t__ gpiod_get_value (void*) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nsa320_groups ; 
 char** nsa320_input_names ; 
 int sprintf (char*,char*,...) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static s32 nsa320_hwmon_update(struct device *dev)
{
	u32 mcu_data;
	u32 mask;
	struct nsa320_hwmon *hwmon = dev_get_drvdata(dev);

	mutex_lock(&hwmon->update_lock);

	mcu_data = hwmon->mcu_data;

	if (time_after(jiffies, hwmon->last_updated + HZ) || mcu_data == 0) {
		gpiod_set_value(hwmon->act, 1);
		msleep(100);

		mcu_data = 0;
		for (mask = BIT(31); mask; mask >>= 1) {
			gpiod_set_value(hwmon->clk, 0);
			usleep_range(100, 200);
			gpiod_set_value(hwmon->clk, 1);
			usleep_range(100, 200);
			if (gpiod_get_value(hwmon->data))
				mcu_data |= mask;
		}

		gpiod_set_value(hwmon->act, 0);
		dev_dbg(dev, "Read raw MCU data %08x\n", mcu_data);

		if ((mcu_data >> 24) != MAGIC_NUMBER) {
			dev_dbg(dev, "Read invalid MCU data %08x\n", mcu_data);
			mcu_data = -EIO;
		} else {
			hwmon->mcu_data = mcu_data;
			hwmon->last_updated = jiffies;
		}
	}

	mutex_unlock(&hwmon->update_lock);

	return mcu_data;
}

__attribute__((used)) static ssize_t show_label(struct device *dev,
			  struct device_attribute *attr, char *buf)
{
	int channel = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%s\n", nsa320_input_names[channel]);
}

__attribute__((used)) static ssize_t temp1_input_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	s32 mcu_data = nsa320_hwmon_update(dev);

	if (mcu_data < 0)
		return mcu_data;

	return sprintf(buf, "%d\n", (mcu_data & 0xffff) * 100);
}

__attribute__((used)) static ssize_t fan1_input_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	s32 mcu_data = nsa320_hwmon_update(dev);

	if (mcu_data < 0)
		return mcu_data;

	return sprintf(buf, "%d\n", ((mcu_data & 0xff0000) >> 16) * 100);
}

__attribute__((used)) static int nsa320_hwmon_probe(struct platform_device *pdev)
{
	struct nsa320_hwmon	*hwmon;
	struct device		*classdev;

	hwmon = devm_kzalloc(&pdev->dev, sizeof(*hwmon), GFP_KERNEL);
	if (!hwmon)
		return -ENOMEM;

	/* Look up the GPIO pins to use */
	hwmon->act = devm_gpiod_get(&pdev->dev, "act", GPIOD_OUT_LOW);
	if (IS_ERR(hwmon->act))
		return PTR_ERR(hwmon->act);

	hwmon->clk = devm_gpiod_get(&pdev->dev, "clk", GPIOD_OUT_HIGH);
	if (IS_ERR(hwmon->clk))
		return PTR_ERR(hwmon->clk);

	hwmon->data = devm_gpiod_get(&pdev->dev, "data", GPIOD_IN);
	if (IS_ERR(hwmon->data))
		return PTR_ERR(hwmon->data);

	mutex_init(&hwmon->update_lock);

	classdev = devm_hwmon_device_register_with_groups(&pdev->dev,
					"nsa320", hwmon, nsa320_groups);

	return PTR_ERR_OR_ZERO(classdev);

}


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
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct device_attribute {int dummy; } ;
struct TYPE_2__ {int vid; int cpu_vid; int gpio1; int gpio2; } ;
struct atxp1_data {int valid; int vrm; int /*<<< orphan*/  update_lock; struct i2c_client* client; TYPE_1__ reg; scalar_t__ last_updated; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATXP1_CVID ; 
 int /*<<< orphan*/  ATXP1_GPIO1 ; 
 int ATXP1_GPIO1MASK ; 
 int /*<<< orphan*/  ATXP1_GPIO2 ; 
 int /*<<< orphan*/  ATXP1_VID ; 
 int ATXP1_VIDENA ; 
 int ATXP1_VIDMASK ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 scalar_t__ IS_ERR (struct device*) ; 
 int PTR_ERR (struct device*) ; 
 int /*<<< orphan*/  atxp1_groups ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct atxp1_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int,...) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct atxp1_data*,int /*<<< orphan*/ ) ; 
 struct atxp1_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ time_after (int /*<<< orphan*/ ,scalar_t__) ; 
 int vid_from_reg (int,int) ; 
 int vid_to_reg (unsigned long,int) ; 
 int vid_which_vrm () ; 

__attribute__((used)) static struct atxp1_data *atxp1_update_device(struct device *dev)
{
	struct atxp1_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {

		/* Update local register data */
		data->reg.vid = i2c_smbus_read_byte_data(client, ATXP1_VID);
		data->reg.cpu_vid = i2c_smbus_read_byte_data(client,
							     ATXP1_CVID);
		data->reg.gpio1 = i2c_smbus_read_byte_data(client, ATXP1_GPIO1);
		data->reg.gpio2 = i2c_smbus_read_byte_data(client, ATXP1_GPIO2);

		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t cpu0_vid_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	int size;
	struct atxp1_data *data;

	data = atxp1_update_device(dev);

	size = sprintf(buf, "%d\n", vid_from_reg(data->reg.vid & ATXP1_VIDMASK,
						 data->vrm));

	return size;
}

__attribute__((used)) static ssize_t cpu0_vid_store(struct device *dev,
			      struct device_attribute *attr, const char *buf,
			      size_t count)
{
	struct atxp1_data *data = atxp1_update_device(dev);
	struct i2c_client *client = data->client;
	int vid, cvid;
	unsigned long vcore;
	int err;

	err = kstrtoul(buf, 10, &vcore);
	if (err)
		return err;

	vcore /= 25;
	vcore *= 25;

	/* Calculate VID */
	vid = vid_to_reg(vcore, data->vrm);
	if (vid < 0) {
		dev_err(dev, "VID calculation failed.\n");
		return vid;
	}

	/*
	 * If output enabled, use control register value.
	 * Otherwise original CPU VID
	 */
	if (data->reg.vid & ATXP1_VIDENA)
		cvid = data->reg.vid & ATXP1_VIDMASK;
	else
		cvid = data->reg.cpu_vid;

	/* Nothing changed, aborting */
	if (vid == cvid)
		return count;

	dev_dbg(dev, "Setting VCore to %d mV (0x%02x)\n", (int)vcore, vid);

	/* Write every 25 mV step to increase stability */
	if (cvid > vid) {
		for (; cvid >= vid; cvid--)
			i2c_smbus_write_byte_data(client,
						ATXP1_VID, cvid | ATXP1_VIDENA);
	} else {
		for (; cvid <= vid; cvid++)
			i2c_smbus_write_byte_data(client,
						ATXP1_VID, cvid | ATXP1_VIDENA);
	}

	data->valid = 0;

	return count;
}

__attribute__((used)) static ssize_t gpio1_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int size;
	struct atxp1_data *data;

	data = atxp1_update_device(dev);

	size = sprintf(buf, "0x%02x\n", data->reg.gpio1 & ATXP1_GPIO1MASK);

	return size;
}

__attribute__((used)) static ssize_t gpio1_store(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct atxp1_data *data = atxp1_update_device(dev);
	struct i2c_client *client = data->client;
	unsigned long value;
	int err;

	err = kstrtoul(buf, 16, &value);
	if (err)
		return err;

	value &= ATXP1_GPIO1MASK;

	if (value != (data->reg.gpio1 & ATXP1_GPIO1MASK)) {
		dev_info(dev, "Writing 0x%x to GPIO1.\n", (unsigned int)value);

		i2c_smbus_write_byte_data(client, ATXP1_GPIO1, value);

		data->valid = 0;
	}

	return count;
}

__attribute__((used)) static ssize_t gpio2_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int size;
	struct atxp1_data *data;

	data = atxp1_update_device(dev);

	size = sprintf(buf, "0x%02x\n", data->reg.gpio2);

	return size;
}

__attribute__((used)) static ssize_t gpio2_store(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct atxp1_data *data = atxp1_update_device(dev);
	struct i2c_client *client = data->client;
	unsigned long value;
	int err;

	err = kstrtoul(buf, 16, &value);
	if (err)
		return err;
	value &= 0xff;

	if (value != data->reg.gpio2) {
		dev_info(dev, "Writing 0x%x to GPIO1.\n", (unsigned int)value);

		i2c_smbus_write_byte_data(client, ATXP1_GPIO2, value);

		data->valid = 0;
	}

	return count;
}

__attribute__((used)) static int atxp1_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct atxp1_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(dev, sizeof(struct atxp1_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	/* Get VRM */
	data->vrm = vid_which_vrm();
	if (data->vrm != 90 && data->vrm != 91) {
		dev_err(dev, "atxp1: Not supporting VRM %d.%d\n",
			data->vrm / 10, data->vrm % 10);
		return -ENODEV;
	}

	data->client = client;
	mutex_init(&data->update_lock);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   atxp1_groups);
	if (IS_ERR(hwmon_dev))
		return PTR_ERR(hwmon_dev);

	dev_info(dev, "Using VRM: %d.%d\n", data->vrm / 10, data->vrm % 10);

	return 0;
}


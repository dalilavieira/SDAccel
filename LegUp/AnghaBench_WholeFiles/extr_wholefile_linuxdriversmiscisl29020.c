#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct i2c_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  m_als_gr ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_1__*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int sprintf (char*,char*,unsigned long) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t als_sensing_range_show(struct device *dev,
			struct device_attribute *attr,  char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int  val;

	val = i2c_smbus_read_byte_data(client, 0x00);

	if (val < 0)
		return val;
	return sprintf(buf, "%d000\n", 1 << (2 * (val & 3)));

}

__attribute__((used)) static ssize_t als_lux_input_data_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int ret_val, val;
	unsigned long int lux;
	int temp;

	pm_runtime_get_sync(dev);
	msleep(100);

	mutex_lock(&mutex);
	temp = i2c_smbus_read_byte_data(client, 0x02); /* MSB data */
	if (temp < 0) {
		pm_runtime_put_sync(dev);
		mutex_unlock(&mutex);
		return temp;
	}

	ret_val = i2c_smbus_read_byte_data(client, 0x01); /* LSB data */
	mutex_unlock(&mutex);

	if (ret_val < 0) {
		pm_runtime_put_sync(dev);
		return ret_val;
	}

	ret_val |= temp << 8;
	val = i2c_smbus_read_byte_data(client, 0x00);
	pm_runtime_put_sync(dev);
	if (val < 0)
		return val;
	lux = ((((1 << (2 * (val & 3))))*1000) * ret_val) / 65536;
	return sprintf(buf, "%ld\n", lux);
}

__attribute__((used)) static ssize_t als_sensing_range_store(struct device *dev,
		struct device_attribute *attr, const  char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	int ret_val;
	unsigned long val;

	ret_val = kstrtoul(buf, 10, &val);
	if (ret_val)
		return ret_val;

	if (val < 1 || val > 64000)
		return -EINVAL;

	/* Pick the smallest sensor range that will meet our requirements */
	if (val <= 1000)
		val = 1;
	else if (val <= 4000)
		val = 2;
	else if (val <= 16000)
		val = 3;
	else
		val = 4;

	ret_val = i2c_smbus_read_byte_data(client, 0x00);
	if (ret_val < 0)
		return ret_val;

	ret_val &= 0xFC; /*reset the bit before setting them */
	ret_val |= val - 1;
	ret_val = i2c_smbus_write_byte_data(client, 0x00, ret_val);

	if (ret_val < 0)
		return ret_val;
	return count;
}

__attribute__((used)) static void als_set_power_state(struct i2c_client *client, int enable)
{
	int ret_val;

	ret_val = i2c_smbus_read_byte_data(client, 0x00);
	if (ret_val < 0)
		return;

	if (enable)
		ret_val |= 0x80;
	else
		ret_val &= 0x7F;

	i2c_smbus_write_byte_data(client, 0x00, ret_val);
}

__attribute__((used)) static int als_set_default_config(struct i2c_client *client)
{
	int retval;

	retval = i2c_smbus_write_byte_data(client, 0x00, 0xc0);
	if (retval < 0) {
		dev_err(&client->dev, "default write failed.");
		return retval;
	}
	return 0;
}

__attribute__((used)) static int  isl29020_probe(struct i2c_client *client,
					const struct i2c_device_id *id)
{
	int res;

	res = als_set_default_config(client);
	if (res <  0)
		return res;

	res = sysfs_create_group(&client->dev.kobj, &m_als_gr);
	if (res) {
		dev_err(&client->dev, "isl29020: device create file failed\n");
		return res;
	}
	dev_info(&client->dev, "%s isl29020: ALS chip found\n", client->name);
	als_set_power_state(client, 0);
	pm_runtime_enable(&client->dev);
	return res;
}

__attribute__((used)) static int isl29020_remove(struct i2c_client *client)
{
	sysfs_remove_group(&client->dev.kobj, &m_als_gr);
	return 0;
}


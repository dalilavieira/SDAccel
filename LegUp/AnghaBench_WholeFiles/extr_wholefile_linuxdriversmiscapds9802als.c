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
struct i2c_device_id {int dummy; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct i2c_client {struct device dev; } ;
struct device_attribute {int dummy; } ;
struct als_data {int /*<<< orphan*/  mutex; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ENOMEM ; 
 int ERANGE ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct als_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct als_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  kfree (struct als_data*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 struct als_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m_als_gr ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (struct device*) ; 
 int sprintf (char*,char*,...) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t als_sensing_range_show(struct device *dev,
			struct device_attribute *attr,  char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int  val;

	val = i2c_smbus_read_byte_data(client, 0x81);
	if (val < 0)
		return val;
	if (val & 1)
		return sprintf(buf, "4095\n");
	else
		return sprintf(buf, "65535\n");
}

__attribute__((used)) static int als_wait_for_data_ready(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	int ret;
	int retry = 10;

	do {
		msleep(30);
		ret = i2c_smbus_read_byte_data(client, 0x86);
	} while (!(ret & 0x80) && retry--);

	if (retry < 0) {
		dev_warn(dev, "timeout waiting for data ready\n");
		return -ETIMEDOUT;
	}

	return 0;
}

__attribute__((used)) static ssize_t als_lux0_input_data_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct als_data *data = i2c_get_clientdata(client);
	int ret_val;
	int temp;

	/* Protect against parallel reads */
	pm_runtime_get_sync(dev);
	mutex_lock(&data->mutex);

	/* clear EOC interrupt status */
	i2c_smbus_write_byte(client, 0x40);
	/* start measurement */
	temp = i2c_smbus_read_byte_data(client, 0x81);
	i2c_smbus_write_byte_data(client, 0x81, temp | 0x08);

	ret_val = als_wait_for_data_ready(dev);
	if (ret_val < 0)
		goto failed;

	temp = i2c_smbus_read_byte_data(client, 0x8C); /* LSB data */
	if (temp < 0) {
		ret_val = temp;
		goto failed;
	}
	ret_val = i2c_smbus_read_byte_data(client, 0x8D); /* MSB data */
	if (ret_val < 0)
		goto failed;

	mutex_unlock(&data->mutex);
	pm_runtime_put_sync(dev);

	temp = (ret_val << 8) | temp;
	return sprintf(buf, "%d\n", temp);
failed:
	mutex_unlock(&data->mutex);
	pm_runtime_put_sync(dev);
	return ret_val;
}

__attribute__((used)) static ssize_t als_sensing_range_store(struct device *dev,
		struct device_attribute *attr, const  char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct als_data *data = i2c_get_clientdata(client);
	int ret_val;
	unsigned long val;

	ret_val = kstrtoul(buf, 10, &val);
	if (ret_val)
		return ret_val;

	if (val < 4096)
		val = 1;
	else if (val < 65536)
		val = 2;
	else
		return -ERANGE;

	pm_runtime_get_sync(dev);

	/* Make sure nobody else reads/modifies/writes 0x81 while we
	   are active */
	mutex_lock(&data->mutex);

	ret_val = i2c_smbus_read_byte_data(client, 0x81);
	if (ret_val < 0)
		goto fail;

	/* Reset the bits before setting them */
	ret_val = ret_val & 0xFA;

	if (val == 1) /* Setting detection range up to 4k LUX */
		ret_val = (ret_val | 0x01);
	else /* Setting detection range up to 64k LUX*/
		ret_val = (ret_val | 0x00);

	ret_val = i2c_smbus_write_byte_data(client, 0x81, ret_val);

	if (ret_val >= 0) {
		/* All OK */
		mutex_unlock(&data->mutex);
		pm_runtime_put_sync(dev);
		return count;
	}
fail:
	mutex_unlock(&data->mutex);
	pm_runtime_put_sync(dev);
	return ret_val;
}

__attribute__((used)) static int als_set_power_state(struct i2c_client *client, bool on_off)
{
	int ret_val;
	struct als_data *data = i2c_get_clientdata(client);

	mutex_lock(&data->mutex);
	ret_val = i2c_smbus_read_byte_data(client, 0x80);
	if (ret_val < 0)
		goto fail;
	if (on_off)
		ret_val = ret_val | 0x01;
	else
		ret_val = ret_val & 0xFE;
	ret_val = i2c_smbus_write_byte_data(client, 0x80, ret_val);
fail:
	mutex_unlock(&data->mutex);
	return ret_val;
}

__attribute__((used)) static int als_set_default_config(struct i2c_client *client)
{
	int ret_val;
	/* Write the command and then switch on */
	ret_val = i2c_smbus_write_byte_data(client, 0x80, 0x01);
	if (ret_val < 0) {
		dev_err(&client->dev, "failed default switch on write\n");
		return ret_val;
	}
	/* detection range: 1~64K Lux, maunal measurement */
	ret_val = i2c_smbus_write_byte_data(client, 0x81, 0x08);
	if (ret_val < 0)
		dev_err(&client->dev, "failed default LUX on write\n");

	/*  We always get 0 for the 1st measurement after system power on,
	 *  so make sure it is finished before user asks for data.
	 */
	als_wait_for_data_ready(&client->dev);

	return ret_val;
}

__attribute__((used)) static int apds9802als_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	int res;
	struct als_data *data;

	data = kzalloc(sizeof(struct als_data), GFP_KERNEL);
	if (data == NULL) {
		dev_err(&client->dev, "Memory allocation failed\n");
		return -ENOMEM;
	}
	i2c_set_clientdata(client, data);
	res = sysfs_create_group(&client->dev.kobj, &m_als_gr);
	if (res) {
		dev_err(&client->dev, "device create file failed\n");
		goto als_error1;
	}
	dev_info(&client->dev, "ALS chip found\n");
	als_set_default_config(client);
	mutex_init(&data->mutex);

	pm_runtime_set_active(&client->dev);
	pm_runtime_enable(&client->dev);

	return res;
als_error1:
	kfree(data);
	return res;
}

__attribute__((used)) static int apds9802als_remove(struct i2c_client *client)
{
	struct als_data *data = i2c_get_clientdata(client);

	pm_runtime_get_sync(&client->dev);

	als_set_power_state(client, false);
	sysfs_remove_group(&client->dev.kobj, &m_als_gr);

	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);
	pm_runtime_put_noidle(&client->dev);

	kfree(data);
	return 0;
}


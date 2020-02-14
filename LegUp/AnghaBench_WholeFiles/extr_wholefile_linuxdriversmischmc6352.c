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
typedef  char u8 ;
struct i2c_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 unsigned long array_index_nospec (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  compass_mutex ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,...) ; 
 int i2c_master_recv (struct i2c_client*,unsigned char*,int) ; 
 int i2c_master_send (struct i2c_client*,char*,int) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  m_compass_gr ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int,int) ; 
 unsigned long strlen (char const*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static int compass_command(struct i2c_client *c, u8 cmd)
{
	int ret = i2c_master_send(c, &cmd, 1);
	if (ret < 0)
		dev_warn(&c->dev, "command '%c' failed.\n", cmd);
	return ret;
}

__attribute__((used)) static int compass_store(struct device *dev, const char *buf, size_t count,
			const char *map)
{
	struct i2c_client *c = to_i2c_client(dev);
	int ret;
	unsigned long val;

	ret = kstrtoul(buf, 10, &val);
	if (ret)
		return ret;
	if (val >= strlen(map))
		return -EINVAL;
	val = array_index_nospec(val, strlen(map));
	mutex_lock(&compass_mutex);
	ret = compass_command(c, map[val]);
	mutex_unlock(&compass_mutex);
	if (ret < 0)
		return ret;
	return count;
}

__attribute__((used)) static ssize_t compass_calibration_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	return compass_store(dev, buf, count, "EC");
}

__attribute__((used)) static ssize_t compass_power_mode_store(struct device *dev,
		struct device_attribute *attr, const  char *buf, size_t count)
{
	return compass_store(dev, buf, count, "SW");
}

__attribute__((used)) static ssize_t compass_heading_data_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	unsigned char i2c_data[2];
	int ret;

	mutex_lock(&compass_mutex);
	ret = compass_command(client, 'A');
	if (ret != 1) {
		mutex_unlock(&compass_mutex);
		return ret;
	}
	msleep(10); /* sending 'A' cmd we need to wait for 7-10 millisecs */
	ret = i2c_master_recv(client, i2c_data, 2);
	mutex_unlock(&compass_mutex);
	if (ret < 0) {
		dev_warn(dev, "i2c read data cmd failed\n");
		return ret;
	}
	ret = (i2c_data[0] << 8) | i2c_data[1];
	return sprintf(buf, "%d.%d\n", ret/10, ret%10);
}

__attribute__((used)) static int hmc6352_probe(struct i2c_client *client,
					const struct i2c_device_id *id)
{
	int res;

	res = sysfs_create_group(&client->dev.kobj, &m_compass_gr);
	if (res) {
		dev_err(&client->dev, "device_create_file failed\n");
		return res;
	}
	dev_info(&client->dev, "%s HMC6352 compass chip found\n",
							client->name);
	return 0;
}

__attribute__((used)) static int hmc6352_remove(struct i2c_client *client)
{
	sysfs_remove_group(&client->dev.kobj, &m_compass_gr);
	return 0;
}


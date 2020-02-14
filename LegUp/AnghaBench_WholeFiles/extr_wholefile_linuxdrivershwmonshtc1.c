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
struct shtc1_platform_data {int blocking_io; int high_precision; } ;
struct shtc1_data {int valid; int temperature; int humidity; int /*<<< orphan*/  update_lock; scalar_t__ platform_data; struct shtc1_platform_data setup; struct i2c_client* client; scalar_t__ nonblocking_wait_time; int /*<<< orphan*/  command; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct shtc1_data dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int valid; int temperature; int humidity; int /*<<< orphan*/  update_lock; scalar_t__ platform_data; struct shtc1_platform_data setup; struct i2c_client* client; scalar_t__ nonblocking_wait_time; int /*<<< orphan*/  command; scalar_t__ last_updated; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  id_reg ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct shtc1_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 scalar_t__ IS_ERR (struct shtc1_data*) ; 
 int /*<<< orphan*/  PTR_ERR (struct shtc1_data*) ; 
 int PTR_ERR_OR_ZERO (struct shtc1_data*) ; 
 int SHTC1_CMD_LENGTH ; 
 char SHTC1_ID ; 
 char SHTC1_ID_REG_MASK ; 
 scalar_t__ SHTC1_NONBLOCKING_WAIT_TIME_HPM ; 
 scalar_t__ SHTC1_NONBLOCKING_WAIT_TIME_LPM ; 
 int SHTC1_RESPONSE_LENGTH ; 
 int be16_to_cpup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (struct shtc1_data*,char*) ; 
 int /*<<< orphan*/  dev_err (struct shtc1_data*,char*,...) ; 
 struct shtc1_data* dev_get_drvdata (struct shtc1_data*) ; 
 struct shtc1_data* devm_hwmon_device_register_with_groups (struct shtc1_data*,int /*<<< orphan*/ ,struct shtc1_data*,int /*<<< orphan*/ ) ; 
 struct shtc1_data* devm_kzalloc (struct shtc1_data*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int i2c_master_send (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  shtc1_cmd_measure_blocking_hpm ; 
 int /*<<< orphan*/  shtc1_cmd_measure_blocking_lpm ; 
 int /*<<< orphan*/  shtc1_cmd_measure_nonblocking_hpm ; 
 int /*<<< orphan*/  shtc1_cmd_measure_nonblocking_lpm ; 
 int /*<<< orphan*/  shtc1_cmd_read_id_reg ; 
 int /*<<< orphan*/  shtc1_groups ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,scalar_t__) ; 

__attribute__((used)) static int shtc1_update_values(struct i2c_client *client,
			       struct shtc1_data *data,
			       char *buf, int bufsize)
{
	int ret = i2c_master_send(client, data->command, SHTC1_CMD_LENGTH);
	if (ret != SHTC1_CMD_LENGTH) {
		dev_err(&client->dev, "failed to send command: %d\n", ret);
		return ret < 0 ? ret : -EIO;
	}

	/*
	 * In blocking mode (clock stretching mode) the I2C bus
	 * is blocked for other traffic, thus the call to i2c_master_recv()
	 * will wait until the data is ready. For non blocking mode, we
	 * have to wait ourselves.
	 */
	if (!data->setup.blocking_io)
		usleep_range(data->nonblocking_wait_time,
			     data->nonblocking_wait_time + 1000);

	ret = i2c_master_recv(client, buf, bufsize);
	if (ret != bufsize) {
		dev_err(&client->dev, "failed to read values: %d\n", ret);
		return ret < 0 ? ret : -EIO;
	}

	return 0;
}

__attribute__((used)) static struct shtc1_data *shtc1_update_client(struct device *dev)
{
	struct shtc1_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned char buf[SHTC1_RESPONSE_LENGTH];
	int val;
	int ret = 0;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ / 10) || !data->valid) {
		ret = shtc1_update_values(client, data, buf, sizeof(buf));
		if (ret)
			goto out;

		/*
		 * From datasheet:
		 * T = -45 + 175 * ST / 2^16
		 * RH = 100 * SRH / 2^16
		 *
		 * Adapted for integer fixed point (3 digit) arithmetic.
		 */
		val = be16_to_cpup((__be16 *)buf);
		data->temperature = ((21875 * val) >> 13) - 45000;
		val = be16_to_cpup((__be16 *)(buf + 3));
		data->humidity = ((12500 * val) >> 13);

		data->last_updated = jiffies;
		data->valid = true;
	}

out:
	mutex_unlock(&data->update_lock);

	return ret == 0 ? data : ERR_PTR(ret);
}

__attribute__((used)) static ssize_t temp1_input_show(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	struct shtc1_data *data = shtc1_update_client(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->temperature);
}

__attribute__((used)) static ssize_t humidity1_input_show(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	struct shtc1_data *data = shtc1_update_client(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->humidity);
}

__attribute__((used)) static void shtc1_select_command(struct shtc1_data *data)
{
	if (data->setup.high_precision) {
		data->command = data->setup.blocking_io ?
				shtc1_cmd_measure_blocking_hpm :
				shtc1_cmd_measure_nonblocking_hpm;
		data->nonblocking_wait_time = SHTC1_NONBLOCKING_WAIT_TIME_HPM;

	} else {
		data->command = data->setup.blocking_io ?
				shtc1_cmd_measure_blocking_lpm :
				shtc1_cmd_measure_nonblocking_lpm;
		data->nonblocking_wait_time = SHTC1_NONBLOCKING_WAIT_TIME_LPM;
	}
}

__attribute__((used)) static int shtc1_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	int ret;
	char id_reg[2];
	struct shtc1_data *data;
	struct device *hwmon_dev;
	struct i2c_adapter *adap = client->adapter;
	struct device *dev = &client->dev;

	if (!i2c_check_functionality(adap, I2C_FUNC_I2C)) {
		dev_err(dev, "plain i2c transactions not supported\n");
		return -ENODEV;
	}

	ret = i2c_master_send(client, shtc1_cmd_read_id_reg, SHTC1_CMD_LENGTH);
	if (ret != SHTC1_CMD_LENGTH) {
		dev_err(dev, "could not send read_id_reg command: %d\n", ret);
		return ret < 0 ? ret : -ENODEV;
	}
	ret = i2c_master_recv(client, id_reg, sizeof(id_reg));
	if (ret != sizeof(id_reg)) {
		dev_err(dev, "could not read ID register: %d\n", ret);
		return -ENODEV;
	}
	if ((id_reg[1] & SHTC1_ID_REG_MASK) != SHTC1_ID) {
		dev_err(dev, "ID register doesn't match\n");
		return -ENODEV;
	}

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->setup.blocking_io = false;
	data->setup.high_precision = true;
	data->client = client;

	if (client->dev.platform_data)
		data->setup = *(struct shtc1_platform_data *)dev->platform_data;
	shtc1_select_command(data);
	mutex_init(&data->update_lock);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev,
							   client->name,
							   data,
							   shtc1_groups);
	if (IS_ERR(hwmon_dev))
		dev_dbg(dev, "unable to register hwmon device\n");

	return PTR_ERR_OR_ZERO(hwmon_dev);
}


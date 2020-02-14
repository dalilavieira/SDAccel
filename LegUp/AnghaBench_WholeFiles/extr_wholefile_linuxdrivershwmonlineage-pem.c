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
typedef  int u8 ;
struct sensor_device_attribute_2 {size_t nr; int index; } ;
struct sensor_device_attribute {int index; } ;
struct pem_data {int valid; int* data_string; int input_length; int* input_string; int fans_supported; int* fan_speed; int* firmware_rev; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct pem_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 int I2C_SMBUS_BLOCK_MAX ; 
 int INPUT_STRING_LEN ; 
 scalar_t__ IS_ERR (struct pem_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PEM_CLEAR_INFO_FLAGS ; 
#define  PEM_DATA_CURRENT 137 
#define  PEM_DATA_TEMP 136 
#define  PEM_DATA_TEMP_CRIT 135 
#define  PEM_DATA_TEMP_MAX 134 
#define  PEM_DATA_VOUT_LSB 133 
#define  PEM_FAN_FAN1 132 
#define  PEM_FAN_FAN2 131 
#define  PEM_FAN_FAN3 130 
#define  PEM_INPUT_POWER_LSB 129 
#define  PEM_INPUT_VOLTAGE 128 
 int PEM_READ_DATA_STRING ; 
 int PEM_READ_FAN_SPEED ; 
 int PEM_READ_FIRMWARE_REV ; 
 int PEM_READ_INPUT_STRING ; 
 int /*<<< orphan*/  PTR_ERR (struct pem_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 struct pem_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int,int,int) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct pem_data*,int /*<<< orphan*/ **) ; 
 struct pem_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_smbus_read_block_data (struct i2c_client*,int,int*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pem_fan_group ; 
 int /*<<< orphan*/  pem_group ; 
 int /*<<< orphan*/  pem_input_group ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,long) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int pem_read_block(struct i2c_client *client, u8 command, u8 *data,
			  int data_len)
{
	u8 block_buffer[I2C_SMBUS_BLOCK_MAX];
	int result;

	result = i2c_smbus_read_block_data(client, command, block_buffer);
	if (unlikely(result < 0))
		goto abort;
	if (unlikely(result == 0xff || result != data_len)) {
		result = -EIO;
		goto abort;
	}
	memcpy(data, block_buffer, data_len);
	result = 0;
abort:
	return result;
}

__attribute__((used)) static struct pem_data *pem_update_device(struct device *dev)
{
	struct pem_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct pem_data *ret = data;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		int result;

		/* Read data string */
		result = pem_read_block(client, PEM_READ_DATA_STRING,
					data->data_string,
					sizeof(data->data_string));
		if (unlikely(result < 0)) {
			ret = ERR_PTR(result);
			goto abort;
		}

		/* Read input string */
		if (data->input_length) {
			result = pem_read_block(client, PEM_READ_INPUT_STRING,
						data->input_string,
						data->input_length);
			if (unlikely(result < 0)) {
				ret = ERR_PTR(result);
				goto abort;
			}
		}

		/* Read fan speeds */
		if (data->fans_supported) {
			result = pem_read_block(client, PEM_READ_FAN_SPEED,
						data->fan_speed,
						sizeof(data->fan_speed));
			if (unlikely(result < 0)) {
				ret = ERR_PTR(result);
				goto abort;
			}
		}

		i2c_smbus_write_byte(client, PEM_CLEAR_INFO_FLAGS);

		data->last_updated = jiffies;
		data->valid = 1;
	}
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static long pem_get_data(u8 *data, int len, int index)
{
	long val;

	switch (index) {
	case PEM_DATA_VOUT_LSB:
		val = (data[index] + (data[index+1] << 8)) * 5 / 2;
		break;
	case PEM_DATA_CURRENT:
		val = data[index] * 200;
		break;
	case PEM_DATA_TEMP:
		val = data[index] * 1000;
		break;
	case PEM_DATA_TEMP_MAX:
		val = 97 * 1000;	/* 97 degrees C per datasheet */
		break;
	case PEM_DATA_TEMP_CRIT:
		val = 107 * 1000;	/* 107 degrees C per datasheet */
		break;
	default:
		WARN_ON_ONCE(1);
		val = 0;
	}
	return val;
}

__attribute__((used)) static long pem_get_input(u8 *data, int len, int index)
{
	long val;

	switch (index) {
	case PEM_INPUT_VOLTAGE:
		if (len == INPUT_STRING_LEN)
			val = (data[index] + (data[index+1] << 8) - 75) * 1000;
		else
			val = (data[index] - 75) * 1000;
		break;
	case PEM_INPUT_POWER_LSB:
		if (len == INPUT_STRING_LEN)
			index++;
		val = (data[index] + (data[index+1] << 8)) * 1000000L;
		break;
	default:
		WARN_ON_ONCE(1);
		val = 0;
	}
	return val;
}

__attribute__((used)) static long pem_get_fan(u8 *data, int len, int index)
{
	long val;

	switch (index) {
	case PEM_FAN_FAN1:
	case PEM_FAN_FAN2:
	case PEM_FAN_FAN3:
		val = data[index] * 100;
		break;
	default:
		WARN_ON_ONCE(1);
		val = 0;
	}
	return val;
}

__attribute__((used)) static ssize_t pem_show_bool(struct device *dev,
			     struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
	struct pem_data *data = pem_update_device(dev);
	u8 status;

	if (IS_ERR(data))
		return PTR_ERR(data);

	status = data->data_string[attr->nr] & attr->index;
	return snprintf(buf, PAGE_SIZE, "%d\n", !!status);
}

__attribute__((used)) static ssize_t pem_show_data(struct device *dev, struct device_attribute *da,
			     char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct pem_data *data = pem_update_device(dev);
	long value;

	if (IS_ERR(data))
		return PTR_ERR(data);

	value = pem_get_data(data->data_string, sizeof(data->data_string),
			     attr->index);

	return snprintf(buf, PAGE_SIZE, "%ld\n", value);
}

__attribute__((used)) static ssize_t pem_show_input(struct device *dev, struct device_attribute *da,
			      char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct pem_data *data = pem_update_device(dev);
	long value;

	if (IS_ERR(data))
		return PTR_ERR(data);

	value = pem_get_input(data->input_string, sizeof(data->input_string),
			      attr->index);

	return snprintf(buf, PAGE_SIZE, "%ld\n", value);
}

__attribute__((used)) static ssize_t pem_show_fan(struct device *dev, struct device_attribute *da,
			    char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct pem_data *data = pem_update_device(dev);
	long value;

	if (IS_ERR(data))
		return PTR_ERR(data);

	value = pem_get_fan(data->fan_speed, sizeof(data->fan_speed),
			    attr->index);

	return snprintf(buf, PAGE_SIZE, "%ld\n", value);
}

__attribute__((used)) static int pem_probe(struct i2c_client *client,
		     const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct pem_data *data;
	int ret, idx = 0;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BLOCK_DATA
				     | I2C_FUNC_SMBUS_WRITE_BYTE))
		return -ENODEV;

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/*
	 * We use the next two commands to determine if the device is really
	 * there.
	 */
	ret = pem_read_block(client, PEM_READ_FIRMWARE_REV,
			     data->firmware_rev, sizeof(data->firmware_rev));
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte(client, PEM_CLEAR_INFO_FLAGS);
	if (ret < 0)
		return ret;

	dev_info(dev, "Firmware revision %d.%d.%d\n",
		 data->firmware_rev[0], data->firmware_rev[1],
		 data->firmware_rev[2]);

	/* sysfs hooks */
	data->groups[idx++] = &pem_group;

	/*
	 * Check if input readings are supported.
	 * This is the case if we can read input data,
	 * and if the returned data is not all zeros.
	 * Note that input alarms are always supported.
	 */
	ret = pem_read_block(client, PEM_READ_INPUT_STRING,
			     data->input_string,
			     sizeof(data->input_string) - 1);
	if (!ret && (data->input_string[0] || data->input_string[1] ||
		     data->input_string[2]))
		data->input_length = sizeof(data->input_string) - 1;
	else if (ret < 0) {
		/* Input string is one byte longer for some devices */
		ret = pem_read_block(client, PEM_READ_INPUT_STRING,
				    data->input_string,
				    sizeof(data->input_string));
		if (!ret && (data->input_string[0] || data->input_string[1] ||
			    data->input_string[2] || data->input_string[3]))
			data->input_length = sizeof(data->input_string);
	}

	if (data->input_length)
		data->groups[idx++] = &pem_input_group;

	/*
	 * Check if fan speed readings are supported.
	 * This is the case if we can read fan speed data,
	 * and if the returned data is not all zeros.
	 * Note that the fan alarm is always supported.
	 */
	ret = pem_read_block(client, PEM_READ_FAN_SPEED,
			     data->fan_speed,
			     sizeof(data->fan_speed));
	if (!ret && (data->fan_speed[0] || data->fan_speed[1] ||
		     data->fan_speed[2] || data->fan_speed[3])) {
		data->fans_supported = true;
		data->groups[idx++] = &pem_fan_group;
	}

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


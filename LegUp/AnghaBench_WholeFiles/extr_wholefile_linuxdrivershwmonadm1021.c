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
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; int /*<<< orphan*/  addr; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct adm1021_data {int valid; int* temp; int* temp_max; scalar_t__ type; int* temp_min; int alarms; int remote_temp_offset; int remote_temp_offset_prec; int low_power; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
typedef  int ssize_t ;
typedef  int s8 ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADM1021_REG_CONFIG_R ; 
 int /*<<< orphan*/  ADM1021_REG_CONFIG_W ; 
 int /*<<< orphan*/  ADM1021_REG_CONV_RATE_R ; 
 int /*<<< orphan*/  ADM1021_REG_CONV_RATE_W ; 
 int /*<<< orphan*/  ADM1021_REG_DEV_ID ; 
 int /*<<< orphan*/  ADM1021_REG_MAN_ID ; 
 int /*<<< orphan*/  ADM1021_REG_STATUS ; 
 int /*<<< orphan*/  ADM1021_REG_TEMP (int) ; 
 int /*<<< orphan*/  ADM1021_REG_THYST_R (int) ; 
 int /*<<< orphan*/  ADM1021_REG_THYST_W (int) ; 
 int /*<<< orphan*/  ADM1021_REG_TOS_R (int) ; 
 int /*<<< orphan*/  ADM1021_REG_TOS_W (int) ; 
 int /*<<< orphan*/  ADM1023_REG_REM_OFFSET ; 
 int /*<<< orphan*/  ADM1023_REG_REM_OFFSET_PREC ; 
 int /*<<< orphan*/  ADM1023_REG_REM_TEMP_PREC ; 
 int /*<<< orphan*/  ADM1023_REG_REM_THYST_PREC ; 
 int /*<<< orphan*/  ADM1023_REG_REM_TOS_PREC ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  adm1021_group ; 
 int /*<<< orphan*/  adm1021_min_group ; 
 scalar_t__ adm1023 ; 
 int clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct adm1021_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct adm1021_data*,int /*<<< orphan*/ **) ; 
 struct adm1021_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_adapter_id (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 scalar_t__ lm84 ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  read_only ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static struct adm1021_data *adm1021_update_device(struct device *dev)
{
	struct adm1021_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {
		int i;

		dev_dbg(dev, "Starting adm1021 update\n");

		for (i = 0; i < 2; i++) {
			data->temp[i] = 1000 *
				(s8) i2c_smbus_read_byte_data(
					client, ADM1021_REG_TEMP(i));
			data->temp_max[i] = 1000 *
				(s8) i2c_smbus_read_byte_data(
					client, ADM1021_REG_TOS_R(i));
			if (data->type != lm84) {
				data->temp_min[i] = 1000 *
				  (s8) i2c_smbus_read_byte_data(client,
							ADM1021_REG_THYST_R(i));
			}
		}
		data->alarms = i2c_smbus_read_byte_data(client,
						ADM1021_REG_STATUS) & 0x7c;
		if (data->type == adm1023) {
			/*
			 * The ADM1023 provides 3 extra bits of precision for
			 * the remote sensor in extra registers.
			 */
			data->temp[1] += 125 * (i2c_smbus_read_byte_data(
				client, ADM1023_REG_REM_TEMP_PREC) >> 5);
			data->temp_max[1] += 125 * (i2c_smbus_read_byte_data(
				client, ADM1023_REG_REM_TOS_PREC) >> 5);
			data->temp_min[1] += 125 * (i2c_smbus_read_byte_data(
				client, ADM1023_REG_REM_THYST_PREC) >> 5);
			data->remote_temp_offset =
				i2c_smbus_read_byte_data(client,
						ADM1023_REG_REM_OFFSET);
			data->remote_temp_offset_prec =
				i2c_smbus_read_byte_data(client,
						ADM1023_REG_REM_OFFSET_PREC);
		}
		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev,
			 struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct adm1021_data *data = adm1021_update_device(dev);

	return sprintf(buf, "%d\n", data->temp[index]);
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev,
			     struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct adm1021_data *data = adm1021_update_device(dev);

	return sprintf(buf, "%d\n", data->temp_max[index]);
}

__attribute__((used)) static ssize_t show_temp_min(struct device *dev,
			     struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct adm1021_data *data = adm1021_update_device(dev);

	return sprintf(buf, "%d\n", data->temp_min[index]);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1021_data *data = adm1021_update_device(dev);
	return sprintf(buf, "%u\n", (data->alarms >> index) & 1);
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev,
			   struct device_attribute *attr,
			   char *buf)
{
	struct adm1021_data *data = adm1021_update_device(dev);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev,
			    struct device_attribute *devattr,
			    const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct adm1021_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long temp;
	int reg_val, err;

	err = kstrtol(buf, 10, &temp);
	if (err)
		return err;
	temp /= 1000;

	mutex_lock(&data->update_lock);
	reg_val = clamp_val(temp, -128, 127);
	data->temp_max[index] = reg_val * 1000;
	if (!read_only)
		i2c_smbus_write_byte_data(client, ADM1021_REG_TOS_W(index),
					  reg_val);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t set_temp_min(struct device *dev,
			    struct device_attribute *devattr,
			    const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct adm1021_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long temp;
	int reg_val, err;

	err = kstrtol(buf, 10, &temp);
	if (err)
		return err;
	temp /= 1000;

	mutex_lock(&data->update_lock);
	reg_val = clamp_val(temp, -128, 127);
	data->temp_min[index] = reg_val * 1000;
	if (!read_only)
		i2c_smbus_write_byte_data(client, ADM1021_REG_THYST_W(index),
					  reg_val);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t low_power_show(struct device *dev,
			      struct device_attribute *devattr, char *buf)
{
	struct adm1021_data *data = adm1021_update_device(dev);
	return sprintf(buf, "%d\n", data->low_power);
}

__attribute__((used)) static ssize_t low_power_store(struct device *dev,
			       struct device_attribute *devattr,
			       const char *buf, size_t count)
{
	struct adm1021_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	char low_power;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;
	low_power = val != 0;

	mutex_lock(&data->update_lock);
	if (low_power != data->low_power) {
		int config = i2c_smbus_read_byte_data(
			client, ADM1021_REG_CONFIG_R);
		data->low_power = low_power;
		i2c_smbus_write_byte_data(client, ADM1021_REG_CONFIG_W,
			(config & 0xBF) | (low_power << 6));
	}
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static int adm1021_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	const char *type_name;
	int conv_rate, status, config, man_id, dev_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		pr_debug("detect failed, smbus byte data not supported!\n");
		return -ENODEV;
	}

	status = i2c_smbus_read_byte_data(client, ADM1021_REG_STATUS);
	conv_rate = i2c_smbus_read_byte_data(client,
					     ADM1021_REG_CONV_RATE_R);
	config = i2c_smbus_read_byte_data(client, ADM1021_REG_CONFIG_R);

	/* Check unused bits */
	if ((status & 0x03) || (config & 0x3F) || (conv_rate & 0xF8)) {
		pr_debug("detect failed, chip not detected!\n");
		return -ENODEV;
	}

	/* Determine the chip type. */
	man_id = i2c_smbus_read_byte_data(client, ADM1021_REG_MAN_ID);
	dev_id = i2c_smbus_read_byte_data(client, ADM1021_REG_DEV_ID);

	if (man_id < 0 || dev_id < 0)
		return -ENODEV;

	if (man_id == 0x4d && dev_id == 0x01)
		type_name = "max1617a";
	else if (man_id == 0x41) {
		if ((dev_id & 0xF0) == 0x30)
			type_name = "adm1023";
		else if ((dev_id & 0xF0) == 0x00)
			type_name = "adm1021";
		else
			return -ENODEV;
	} else if (man_id == 0x49)
		type_name = "thmc10";
	else if (man_id == 0x23)
		type_name = "gl523sm";
	else if (man_id == 0x54)
		type_name = "mc1066";
	else {
		int lte, rte, lhi, rhi, llo, rlo;

		/* extra checks for LM84 and MAX1617 to avoid misdetections */

		llo = i2c_smbus_read_byte_data(client, ADM1021_REG_THYST_R(0));
		rlo = i2c_smbus_read_byte_data(client, ADM1021_REG_THYST_R(1));

		/* fail if any of the additional register reads failed */
		if (llo < 0 || rlo < 0)
			return -ENODEV;

		lte = i2c_smbus_read_byte_data(client, ADM1021_REG_TEMP(0));
		rte = i2c_smbus_read_byte_data(client, ADM1021_REG_TEMP(1));
		lhi = i2c_smbus_read_byte_data(client, ADM1021_REG_TOS_R(0));
		rhi = i2c_smbus_read_byte_data(client, ADM1021_REG_TOS_R(1));

		/*
		 * Fail for negative temperatures and negative high limits.
		 * This check also catches read errors on the tested registers.
		 */
		if ((s8)lte < 0 || (s8)rte < 0 || (s8)lhi < 0 || (s8)rhi < 0)
			return -ENODEV;

		/* fail if all registers hold the same value */
		if (lte == rte && lte == lhi && lte == rhi && lte == llo
		    && lte == rlo)
			return -ENODEV;

		/*
		 * LM84 Mfr ID is in a different place,
		 * and it has more unused bits.
		 */
		if (conv_rate == 0x00
		    && (config & 0x7F) == 0x00
		    && (status & 0xAB) == 0x00) {
			type_name = "lm84";
		} else {
			/* fail if low limits are larger than high limits */
			if ((s8)llo > lhi || (s8)rlo > rhi)
				return -ENODEV;
			type_name = "max1617";
		}
	}

	pr_debug("Detected chip %s at adapter %d, address 0x%02x.\n",
		 type_name, i2c_adapter_id(adapter), client->addr);
	strlcpy(info->type, type_name, I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void adm1021_init_client(struct i2c_client *client)
{
	/* Enable ADC and disable suspend mode */
	i2c_smbus_write_byte_data(client, ADM1021_REG_CONFIG_W,
		i2c_smbus_read_byte_data(client, ADM1021_REG_CONFIG_R) & 0xBF);
	/* Set Conversion rate to 1/sec (this can be tinkered with) */
	i2c_smbus_write_byte_data(client, ADM1021_REG_CONV_RATE_W, 0x04);
}

__attribute__((used)) static int adm1021_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct adm1021_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(dev, sizeof(struct adm1021_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	data->type = id->driver_data;
	mutex_init(&data->update_lock);

	/* Initialize the ADM1021 chip */
	if (data->type != lm84 && !read_only)
		adm1021_init_client(client);

	data->groups[0] = &adm1021_group;
	if (data->type != lm84)
		data->groups[1] = &adm1021_min_group;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);

	return PTR_ERR_OR_ZERO(hwmon_dev);
}


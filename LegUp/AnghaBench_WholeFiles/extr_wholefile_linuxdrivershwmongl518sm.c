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
typedef  int u8 ;
typedef  int u16 ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct gl518_data {int valid; int alarms; int beep_mask; int* voltage_min; int* voltage_max; int* fan_in; int* fan_min; int temp_in; int temp_max; int temp_hyst; int* fan_div; int fan_auto1; int alarm_mask; int beep_enable; scalar_t__ type; int* voltage_in; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int DIV_FROM_REG (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int FAN_FROM_REG (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GL518_REG_ALARM ; 
 int GL518_REG_CHIP_ID ; 
 int GL518_REG_CONF ; 
 int GL518_REG_FAN_COUNT ; 
 int GL518_REG_FAN_LIMIT ; 
 int GL518_REG_INT ; 
 int GL518_REG_MASK ; 
 int GL518_REG_MISC ; 
 int GL518_REG_REVISION ; 
 int GL518_REG_TEMP_HYST ; 
 int GL518_REG_TEMP_IN ; 
 int GL518_REG_TEMP_MAX ; 
 int GL518_REG_VDD ; 
 int GL518_REG_VDD_LIMIT ; 
 int GL518_REG_VIN1 ; 
 int GL518_REG_VIN1_LIMIT ; 
 int GL518_REG_VIN2 ; 
 int GL518_REG_VIN2_LIMIT ; 
 int GL518_REG_VIN3 ; 
 int GL518_REG_VIN3_LIMIT ; 
 int HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int clamp_val (int,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,unsigned long) ; 
 struct gl518_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct gl518_data*,int /*<<< orphan*/ **) ; 
 struct gl518_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gl518_group ; 
 int /*<<< orphan*/  gl518_group_r80 ; 
 scalar_t__ gl518sm_r00 ; 
 scalar_t__ gl518sm_r80 ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int,int) ; 
 scalar_t__ jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline u8 FAN_TO_REG(long rpm, int div)
{
	long rpmdiv;
	if (rpm == 0)
		return 0;
	rpmdiv = clamp_val(rpm, 1, 960000) * div;
	return clamp_val((480000 + rpmdiv / 2) / rpmdiv, 1, 255);
}

__attribute__((used)) static int gl518_read_value(struct i2c_client *client, u8 reg)
{
	if ((reg >= 0x07) && (reg <= 0x0c))
		return i2c_smbus_read_word_swapped(client, reg);
	else
		return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static int gl518_write_value(struct i2c_client *client, u8 reg, u16 value)
{
	if ((reg >= 0x07) && (reg <= 0x0c))
		return i2c_smbus_write_word_swapped(client, reg, value);
	else
		return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static struct gl518_data *gl518_update_device(struct device *dev)
{
	struct gl518_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int val;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {
		dev_dbg(&client->dev, "Starting gl518 update\n");

		data->alarms = gl518_read_value(client, GL518_REG_INT);
		data->beep_mask = gl518_read_value(client, GL518_REG_ALARM);

		val = gl518_read_value(client, GL518_REG_VDD_LIMIT);
		data->voltage_min[0] = val & 0xff;
		data->voltage_max[0] = (val >> 8) & 0xff;
		val = gl518_read_value(client, GL518_REG_VIN1_LIMIT);
		data->voltage_min[1] = val & 0xff;
		data->voltage_max[1] = (val >> 8) & 0xff;
		val = gl518_read_value(client, GL518_REG_VIN2_LIMIT);
		data->voltage_min[2] = val & 0xff;
		data->voltage_max[2] = (val >> 8) & 0xff;
		val = gl518_read_value(client, GL518_REG_VIN3_LIMIT);
		data->voltage_min[3] = val & 0xff;
		data->voltage_max[3] = (val >> 8) & 0xff;

		val = gl518_read_value(client, GL518_REG_FAN_COUNT);
		data->fan_in[0] = (val >> 8) & 0xff;
		data->fan_in[1] = val & 0xff;

		val = gl518_read_value(client, GL518_REG_FAN_LIMIT);
		data->fan_min[0] = (val >> 8) & 0xff;
		data->fan_min[1] = val & 0xff;

		data->temp_in = gl518_read_value(client, GL518_REG_TEMP_IN);
		data->temp_max =
		    gl518_read_value(client, GL518_REG_TEMP_MAX);
		data->temp_hyst =
		    gl518_read_value(client, GL518_REG_TEMP_HYST);

		val = gl518_read_value(client, GL518_REG_MISC);
		data->fan_div[0] = (val >> 6) & 0x03;
		data->fan_div[1] = (val >> 4) & 0x03;
		data->fan_auto1  = (val >> 3) & 0x01;

		data->alarms &= data->alarm_mask;

		val = gl518_read_value(client, GL518_REG_CONF);
		data->beep_enable = (val >> 2) & 1;

		if (data->type != gl518sm_r00) {
			data->voltage_in[0] =
			    gl518_read_value(client, GL518_REG_VDD);
			data->voltage_in[1] =
			    gl518_read_value(client, GL518_REG_VIN1);
			data->voltage_in[2] =
			    gl518_read_value(client, GL518_REG_VIN2);
		}
		data->voltage_in[3] =
		    gl518_read_value(client, GL518_REG_VIN3);

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_fan_input(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct gl518_data *data = gl518_update_device(dev);
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_in[nr],
					DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct gl518_data *data = gl518_update_device(dev);
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
					DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct gl518_data *data = gl518_update_device(dev);
	return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct gl518_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	int regvalue;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	regvalue = gl518_read_value(client, GL518_REG_FAN_LIMIT);
	data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
	regvalue = (regvalue & (0xff << (8 * nr)))
		 | (data->fan_min[nr] << (8 * (1 - nr)));
	gl518_write_value(client, GL518_REG_FAN_LIMIT, regvalue);

	data->beep_mask = gl518_read_value(client, GL518_REG_ALARM);
	if (data->fan_min[nr] == 0)
		data->alarm_mask &= ~(0x20 << nr);
	else
		data->alarm_mask |= (0x20 << nr);
	data->beep_mask &= data->alarm_mask;
	gl518_write_value(client, GL518_REG_ALARM, data->beep_mask);

	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct gl518_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	int regvalue;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	switch (val) {
	case 1:
		val = 0;
		break;
	case 2:
		val = 1;
		break;
	case 4:
		val = 2;
		break;
	case 8:
		val = 3;
		break;
	default:
		dev_err(dev,
			"Invalid fan clock divider %lu, choose one of 1, 2, 4 or 8\n",
			val);
		return -EINVAL;
	}

	mutex_lock(&data->update_lock);
	regvalue = gl518_read_value(client, GL518_REG_MISC);
	data->fan_div[nr] = val;
	regvalue = (regvalue & ~(0xc0 >> (2 * nr)))
		 | (data->fan_div[nr] << (6 - 2 * nr));
	gl518_write_value(client, GL518_REG_MISC, regvalue);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct gl518_data *data = gl518_update_device(dev);
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct gl518_data *data = gl518_update_device(dev);
	return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}

__attribute__((used)) static ssize_t set_beep(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	struct gl518_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int bitnr = to_sensor_dev_attr(attr)->index;
	unsigned long bit;
	int err;

	err = kstrtoul(buf, 10, &bit);
	if (err)
		return err;

	if (bit & ~1)
		return -EINVAL;

	mutex_lock(&data->update_lock);
	data->beep_mask = gl518_read_value(client, GL518_REG_ALARM);
	if (bit)
		data->beep_mask |= (1 << bitnr);
	else
		data->beep_mask &= ~(1 << bitnr);
	gl518_write_value(client, GL518_REG_ALARM, data->beep_mask);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static int gl518_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int rev;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	/* Now, we do the remaining detection. */
	if ((gl518_read_value(client, GL518_REG_CHIP_ID) != 0x80)
	 || (gl518_read_value(client, GL518_REG_CONF) & 0x80))
		return -ENODEV;

	/* Determine the chip type. */
	rev = gl518_read_value(client, GL518_REG_REVISION);
	if (rev != 0x00 && rev != 0x80)
		return -ENODEV;

	strlcpy(info->type, "gl518sm", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void gl518_init_client(struct i2c_client *client)
{
	/* Make sure we leave D7:Reset untouched */
	u8 regvalue = gl518_read_value(client, GL518_REG_CONF) & 0x7f;

	/* Comparator mode (D3=0), standby mode (D6=0) */
	gl518_write_value(client, GL518_REG_CONF, (regvalue &= 0x37));

	/* Never interrupts */
	gl518_write_value(client, GL518_REG_MASK, 0x00);

	/* Clear status register (D5=1), start (D6=1) */
	gl518_write_value(client, GL518_REG_CONF, 0x20 | regvalue);
	gl518_write_value(client, GL518_REG_CONF, 0x40 | regvalue);
}

__attribute__((used)) static int gl518_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct gl518_data *data;
	int revision;

	data = devm_kzalloc(dev, sizeof(struct gl518_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	revision = gl518_read_value(client, GL518_REG_REVISION);
	data->type = revision == 0x80 ? gl518sm_r80 : gl518sm_r00;
	mutex_init(&data->update_lock);

	/* Initialize the GL518SM chip */
	data->alarm_mask = 0xff;
	gl518_init_client(client);

	/* sysfs hooks */
	data->groups[0] = &gl518_group;
	if (data->type == gl518sm_r80)
		data->groups[1] = &gl518_group_r80;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


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
typedef  scalar_t__ u8 ;
typedef  int u16 ;
struct sensor_device_attribute {size_t index; } ;
struct lm77_data {int valid; int* temp; int alarms; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int s16 ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ LM77_REG_CONF ; 
 scalar_t__ LM77_REG_TEMP ; 
 scalar_t__ LM77_REG_TEMP_HYST ; 
 int /*<<< orphan*/  LM77_TEMP_MAX ; 
 int /*<<< orphan*/  LM77_TEMP_MIN ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 long clamp_val (long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct lm77_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct lm77_data*,int /*<<< orphan*/ ) ; 
 struct lm77_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,scalar_t__) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,scalar_t__,int) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,scalar_t__,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  lm77_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 size_t t_crit ; 
 size_t t_hyst ; 
 int t_min ; 
 int t_num_temp ; 
 scalar_t__* temp_regs ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline s16 LM77_TEMP_TO_REG(int temp)
{
	return (temp / 500) * 8;
}

__attribute__((used)) static inline int LM77_TEMP_FROM_REG(s16 reg)
{
	return (reg / 8) * 500;
}

__attribute__((used)) static u16 lm77_read_value(struct i2c_client *client, u8 reg)
{
	if (reg == LM77_REG_CONF)
		return i2c_smbus_read_byte_data(client, reg);
	else
		return i2c_smbus_read_word_swapped(client, reg);
}

__attribute__((used)) static int lm77_write_value(struct i2c_client *client, u8 reg, u16 value)
{
	if (reg == LM77_REG_CONF)
		return i2c_smbus_write_byte_data(client, reg, value);
	else
		return i2c_smbus_write_word_swapped(client, reg, value);
}

__attribute__((used)) static struct lm77_data *lm77_update_device(struct device *dev)
{
	struct lm77_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {
		dev_dbg(&client->dev, "Starting lm77 update\n");
		for (i = 0; i < t_num_temp; i++) {
			data->temp[i] =
			  LM77_TEMP_FROM_REG(lm77_read_value(client,
							     temp_regs[i]));
		}
		data->alarms =
			lm77_read_value(client, LM77_REG_TEMP) & 0x0007;
		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
			 char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm77_data *data = lm77_update_device(dev);

	return sprintf(buf, "%d\n", data->temp[attr->index]);
}

__attribute__((used)) static ssize_t show_temp_hyst(struct device *dev,
			      struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm77_data *data = lm77_update_device(dev);
	int nr = attr->index;
	int temp;

	temp = nr == t_min ? data->temp[nr] + data->temp[t_hyst] :
			     data->temp[nr] - data->temp[t_hyst];

	return sprintf(buf, "%d\n", temp);
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
			const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm77_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = attr->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	val = clamp_val(val, LM77_TEMP_MIN, LM77_TEMP_MAX);
	mutex_lock(&data->update_lock);
	data->temp[nr] = val;
	lm77_write_value(client, temp_regs[nr], LM77_TEMP_TO_REG(val));
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_hyst(struct device *dev,
			     struct device_attribute *devattr,
			     const char *buf, size_t count)
{
	struct lm77_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	val = clamp_val(data->temp[t_crit] - val, LM77_TEMP_MIN, LM77_TEMP_MAX);
	data->temp[t_hyst] = val;
	lm77_write_value(client, LM77_REG_TEMP_HYST,
			 LM77_TEMP_TO_REG(data->temp[t_hyst]));
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct lm77_data *data = lm77_update_device(dev);
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static int lm77_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int i, cur, conf, hyst, crit, min, max;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	/*
	 * Here comes the remaining detection.  Since the LM77 has no
	 * register dedicated to identification, we have to rely on the
	 * following tricks:
	 *
	 * 1. the high 4 bits represent the sign and thus they should
	 *    always be the same
	 * 2. the high 3 bits are unused in the configuration register
	 * 3. addresses 0x06 and 0x07 return the last read value
	 * 4. registers cycling over 8-address boundaries
	 *
	 * Word-sized registers are high-byte first.
	 */

	/* addresses cycling */
	cur = i2c_smbus_read_word_data(client, 0);
	conf = i2c_smbus_read_byte_data(client, 1);
	hyst = i2c_smbus_read_word_data(client, 2);
	crit = i2c_smbus_read_word_data(client, 3);
	min = i2c_smbus_read_word_data(client, 4);
	max = i2c_smbus_read_word_data(client, 5);
	for (i = 8; i <= 0xff; i += 8) {
		if (i2c_smbus_read_byte_data(client, i + 1) != conf
		 || i2c_smbus_read_word_data(client, i + 2) != hyst
		 || i2c_smbus_read_word_data(client, i + 3) != crit
		 || i2c_smbus_read_word_data(client, i + 4) != min
		 || i2c_smbus_read_word_data(client, i + 5) != max)
			return -ENODEV;
	}

	/* sign bits */
	if (((cur & 0x00f0) != 0xf0 && (cur & 0x00f0) != 0x0)
	 || ((hyst & 0x00f0) != 0xf0 && (hyst & 0x00f0) != 0x0)
	 || ((crit & 0x00f0) != 0xf0 && (crit & 0x00f0) != 0x0)
	 || ((min & 0x00f0) != 0xf0 && (min & 0x00f0) != 0x0)
	 || ((max & 0x00f0) != 0xf0 && (max & 0x00f0) != 0x0))
		return -ENODEV;

	/* unused bits */
	if (conf & 0xe0)
		return -ENODEV;

	/* 0x06 and 0x07 return the last read value */
	cur = i2c_smbus_read_word_data(client, 0);
	if (i2c_smbus_read_word_data(client, 6) != cur
	 || i2c_smbus_read_word_data(client, 7) != cur)
		return -ENODEV;
	hyst = i2c_smbus_read_word_data(client, 2);
	if (i2c_smbus_read_word_data(client, 6) != hyst
	 || i2c_smbus_read_word_data(client, 7) != hyst)
		return -ENODEV;
	min = i2c_smbus_read_word_data(client, 4);
	if (i2c_smbus_read_word_data(client, 6) != min
	 || i2c_smbus_read_word_data(client, 7) != min)
		return -ENODEV;

	strlcpy(info->type, "lm77", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void lm77_init_client(struct i2c_client *client)
{
	/* Initialize the LM77 chip - turn off shutdown mode */
	int conf = lm77_read_value(client, LM77_REG_CONF);
	if (conf & 1)
		lm77_write_value(client, LM77_REG_CONF, conf & 0xfe);
}

__attribute__((used)) static int lm77_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct lm77_data *data;

	data = devm_kzalloc(dev, sizeof(struct lm77_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the LM77 chip */
	lm77_init_client(client);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, lm77_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


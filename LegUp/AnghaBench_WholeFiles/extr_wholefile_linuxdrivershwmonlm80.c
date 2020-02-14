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
struct sensor_device_attribute {int index; } ;
struct lm80_data {int error; int valid; int** in; int** fan; int* temp; int* fan_div; int alarms; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; int nr; } ;

/* Variables and functions */
 int DIV_FROM_REG (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct lm80_data* ERR_PTR (int) ; 
 int FAN_FROM_REG (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int IN_FROM_REG (int) ; 
 int IN_TO_REG (long) ; 
 scalar_t__ IS_ERR (struct lm80_data*) ; 
 int LM80_REG_ALARM1 ; 
 int LM80_REG_ALARM2 ; 
 int LM80_REG_CONFIG ; 
 int LM80_REG_FAN1 ; 
 int LM80_REG_FAN2 ; 
 int LM80_REG_FANDIV ; 
 int LM80_REG_FAN_MIN (int) ; 
 int LM80_REG_IN (int) ; 
 int LM80_REG_IN_MAX (int) ; 
 int LM80_REG_IN_MIN (int) ; 
 int LM80_REG_RES ; 
 int LM80_REG_TEMP ; 
 int LM96080_REG_CONV_RATE ; 
 int LM96080_REG_DEV_ID ; 
 int LM96080_REG_MAN_ID ; 
 int PTR_ERR (struct lm80_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int TEMP_FROM_REG (int) ; 
 int TEMP_TO_REG (long) ; 
 unsigned char clamp_val (int,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,unsigned long) ; 
 struct lm80_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct lm80_data*,int /*<<< orphan*/ ) ; 
 struct lm80_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 size_t f_input ; 
 size_t f_min ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 size_t i_input ; 
 size_t i_max ; 
 size_t i_min ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  lm80_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 size_t t_input ; 
 int t_num_temp ; 
 int* temp_regs ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 TYPE_1__* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static inline unsigned char FAN_TO_REG(unsigned rpm, unsigned div)
{
	if (rpm == 0)
		return 255;
	rpm = clamp_val(rpm, 1, 1000000);
	return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}

__attribute__((used)) static int lm80_read_value(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static int lm80_write_value(struct i2c_client *client, u8 reg, u8 value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static void lm80_init_client(struct i2c_client *client)
{
	/*
	 * Reset all except Watchdog values and last conversion values
	 * This sets fan-divs to 2, among others. This makes most other
	 * initializations unnecessary
	 */
	lm80_write_value(client, LM80_REG_CONFIG, 0x80);
	/* Set 11-bit temperature resolution */
	lm80_write_value(client, LM80_REG_RES, 0x08);

	/* Start monitoring */
	lm80_write_value(client, LM80_REG_CONFIG, 0x01);
}

__attribute__((used)) static struct lm80_data *lm80_update_device(struct device *dev)
{
	struct lm80_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int i;
	int rv;
	int prev_rv;
	struct lm80_data *ret = data;

	mutex_lock(&data->update_lock);

	if (data->error)
		lm80_init_client(client);

	if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
		dev_dbg(dev, "Starting lm80 update\n");
		for (i = 0; i <= 6; i++) {
			rv = lm80_read_value(client, LM80_REG_IN(i));
			if (rv < 0)
				goto abort;
			data->in[i_input][i] = rv;

			rv = lm80_read_value(client, LM80_REG_IN_MIN(i));
			if (rv < 0)
				goto abort;
			data->in[i_min][i] = rv;

			rv = lm80_read_value(client, LM80_REG_IN_MAX(i));
			if (rv < 0)
				goto abort;
			data->in[i_max][i] = rv;
		}

		rv = lm80_read_value(client, LM80_REG_FAN1);
		if (rv < 0)
			goto abort;
		data->fan[f_input][0] = rv;

		rv = lm80_read_value(client, LM80_REG_FAN_MIN(1));
		if (rv < 0)
			goto abort;
		data->fan[f_min][0] = rv;

		rv = lm80_read_value(client, LM80_REG_FAN2);
		if (rv < 0)
			goto abort;
		data->fan[f_input][1] = rv;

		rv = lm80_read_value(client, LM80_REG_FAN_MIN(2));
		if (rv < 0)
			goto abort;
		data->fan[f_min][1] = rv;

		prev_rv = rv = lm80_read_value(client, LM80_REG_TEMP);
		if (rv < 0)
			goto abort;
		rv = lm80_read_value(client, LM80_REG_RES);
		if (rv < 0)
			goto abort;
		data->temp[t_input] = (prev_rv << 8) | (rv & 0xf0);

		for (i = t_input + 1; i < t_num_temp; i++) {
			rv = lm80_read_value(client, temp_regs[i]);
			if (rv < 0)
				goto abort;
			data->temp[i] = rv << 8;
		}

		rv = lm80_read_value(client, LM80_REG_FANDIV);
		if (rv < 0)
			goto abort;
		data->fan_div[0] = (rv >> 2) & 0x03;
		data->fan_div[1] = (rv >> 4) & 0x03;

		prev_rv = rv = lm80_read_value(client, LM80_REG_ALARM1);
		if (rv < 0)
			goto abort;
		rv = lm80_read_value(client, LM80_REG_ALARM2);
		if (rv < 0)
			goto abort;
		data->alarms = prev_rv + (rv << 8);

		data->last_updated = jiffies;
		data->valid = 1;
		data->error = 0;
	}
	goto done;

abort:
	ret = ERR_PTR(rv);
	data->valid = 0;
	data->error = 1;

done:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *attr,
		       char *buf)
{
	struct lm80_data *data = lm80_update_device(dev);
	int index = to_sensor_dev_attr_2(attr)->index;
	int nr = to_sensor_dev_attr_2(attr)->nr;

	if (IS_ERR(data))
		return PTR_ERR(data);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in[nr][index]));
}

__attribute__((used)) static ssize_t set_in(struct device *dev, struct device_attribute *attr,
		      const char *buf, size_t count)
{
	struct lm80_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int index = to_sensor_dev_attr_2(attr)->index;
	int nr = to_sensor_dev_attr_2(attr)->nr;
	long val;
	u8 reg;
	int err = kstrtol(buf, 10, &val);
	if (err < 0)
		return err;

	reg = nr == i_min ? LM80_REG_IN_MIN(index) : LM80_REG_IN_MAX(index);

	mutex_lock(&data->update_lock);
	data->in[nr][index] = IN_TO_REG(val);
	lm80_write_value(client, reg, data->in[nr][index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	int index = to_sensor_dev_attr_2(attr)->index;
	int nr = to_sensor_dev_attr_2(attr)->nr;
	struct lm80_data *data = lm80_update_device(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr][index],
		       DIV_FROM_REG(data->fan_div[index])));
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
	char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct lm80_data *data = lm80_update_device(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);
	return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int index = to_sensor_dev_attr_2(attr)->index;
	int nr = to_sensor_dev_attr_2(attr)->nr;
	struct lm80_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	mutex_lock(&data->update_lock);
	data->fan[nr][index] = FAN_TO_REG(val,
					  DIV_FROM_REG(data->fan_div[index]));
	lm80_write_value(client, LM80_REG_FAN_MIN(index + 1),
			 data->fan[nr][index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct lm80_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long min, val;
	u8 reg;
	int rv;

	rv = kstrtoul(buf, 10, &val);
	if (rv < 0)
		return rv;

	/* Save fan_min */
	mutex_lock(&data->update_lock);
	min = FAN_FROM_REG(data->fan[f_min][nr],
			   DIV_FROM_REG(data->fan_div[nr]));

	switch (val) {
	case 1:
		data->fan_div[nr] = 0;
		break;
	case 2:
		data->fan_div[nr] = 1;
		break;
	case 4:
		data->fan_div[nr] = 2;
		break;
	case 8:
		data->fan_div[nr] = 3;
		break;
	default:
		dev_err(dev,
			"fan_div value %ld not supported. Choose one of 1, 2, 4 or 8!\n",
			val);
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}

	rv = lm80_read_value(client, LM80_REG_FANDIV);
	if (rv < 0) {
		mutex_unlock(&data->update_lock);
		return rv;
	}
	reg = (rv & ~(3 << (2 * (nr + 1))))
	    | (data->fan_div[nr] << (2 * (nr + 1)));
	lm80_write_value(client, LM80_REG_FANDIV, reg);

	/* Restore fan_min */
	data->fan[f_min][nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
	lm80_write_value(client, LM80_REG_FAN_MIN(nr + 1),
			 data->fan[f_min][nr]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
			 char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm80_data *data = lm80_update_device(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
			const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm80_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = attr->index;
	long val;
	int err = kstrtol(buf, 10, &val);
	if (err < 0)
		return err;

	mutex_lock(&data->update_lock);
	data->temp[nr] = TEMP_TO_REG(val);
	lm80_write_value(client, temp_regs[nr], data->temp[nr] >> 8);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct lm80_data *data = lm80_update_device(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct lm80_data *data = lm80_update_device(dev);
	if (IS_ERR(data))
		return PTR_ERR(data);
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static int lm80_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int i, cur, man_id, dev_id;
	const char *name = NULL;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* First check for unused bits, common to both chip types */
	if ((lm80_read_value(client, LM80_REG_ALARM2) & 0xc0)
	 || (lm80_read_value(client, LM80_REG_CONFIG) & 0x80))
		return -ENODEV;

	/*
	 * The LM96080 has manufacturer and stepping/die rev registers so we
	 * can just check that. The LM80 does not have such registers so we
	 * have to use a more expensive trick.
	 */
	man_id = lm80_read_value(client, LM96080_REG_MAN_ID);
	dev_id = lm80_read_value(client, LM96080_REG_DEV_ID);
	if (man_id == 0x01 && dev_id == 0x08) {
		/* Check more unused bits for confirmation */
		if (lm80_read_value(client, LM96080_REG_CONV_RATE) & 0xfe)
			return -ENODEV;

		name = "lm96080";
	} else {
		/* Check 6-bit addressing */
		for (i = 0x2a; i <= 0x3d; i++) {
			cur = i2c_smbus_read_byte_data(client, i);
			if ((i2c_smbus_read_byte_data(client, i + 0x40) != cur)
			 || (i2c_smbus_read_byte_data(client, i + 0x80) != cur)
			 || (i2c_smbus_read_byte_data(client, i + 0xc0) != cur))
				return -ENODEV;
		}

		name = "lm80";
	}

	strlcpy(info->type, name, I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int lm80_probe(struct i2c_client *client,
		      const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct lm80_data *data;
	int rv;

	data = devm_kzalloc(dev, sizeof(struct lm80_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the LM80 chip */
	lm80_init_client(client);

	/* A few vars need to be filled upon startup */
	rv = lm80_read_value(client, LM80_REG_FAN_MIN(1));
	if (rv < 0)
		return rv;
	data->fan[f_min][0] = rv;
	rv = lm80_read_value(client, LM80_REG_FAN_MIN(2));
	if (rv < 0)
		return rv;
	data->fan[f_min][1] = rv;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, lm80_groups);

	return PTR_ERR_OR_ZERO(hwmon_dev);
}


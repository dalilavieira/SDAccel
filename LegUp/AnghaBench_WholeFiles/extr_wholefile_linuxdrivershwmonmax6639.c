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
struct sensor_device_attribute {size_t index; } ;
struct max6639_platform_data {int ppr; int rpm_range; scalar_t__ pwm_polarity; } ;
struct max6639_data {int valid; int status; int* fan; int* temp; int* temp_fault; int* temp_therm; int* temp_alert; int* temp_ot; int* pwm; int rpm_range; int ppr; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct max6639_data* ERR_PTR (int) ; 
 int FAN_FROM_REG (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (struct max6639_data*) ; 
 int MAX6639_FAN_CONFIG1_PWM ; 
 int MAX6639_FAN_CONFIG3_THERM_FULL_SPEED ; 
 int MAX6639_GCONFIG_CH2_LOCAL ; 
 int MAX6639_GCONFIG_DISABLE_TIMEOUT ; 
 int MAX6639_GCONFIG_POR ; 
 int MAX6639_GCONFIG_PWM_FREQ_HI ; 
 int /*<<< orphan*/  MAX6639_REG_ALERT_LIMIT (int) ; 
 int /*<<< orphan*/  MAX6639_REG_DEVID ; 
 int /*<<< orphan*/  MAX6639_REG_FAN_CNT (int) ; 
 int /*<<< orphan*/  MAX6639_REG_FAN_CONFIG1 (int) ; 
 int /*<<< orphan*/  MAX6639_REG_FAN_CONFIG2a (int) ; 
 int /*<<< orphan*/  MAX6639_REG_FAN_CONFIG3 (int) ; 
 int /*<<< orphan*/  MAX6639_REG_FAN_PPR (int) ; 
 int /*<<< orphan*/  MAX6639_REG_GCONFIG ; 
 int /*<<< orphan*/  MAX6639_REG_MANUID ; 
 int /*<<< orphan*/  MAX6639_REG_OT_LIMIT (int) ; 
 int /*<<< orphan*/  MAX6639_REG_STATUS ; 
 int /*<<< orphan*/  MAX6639_REG_TARGTDUTY (int) ; 
 int /*<<< orphan*/  MAX6639_REG_TEMP (int) ; 
 int /*<<< orphan*/  MAX6639_REG_TEMP_EXT (int) ; 
 int /*<<< orphan*/  MAX6639_REG_THERM_LIMIT (int) ; 
 int PTR_ERR (struct max6639_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 void* TEMP_LIMIT_TO_REG (unsigned long) ; 
 unsigned long clamp_val (unsigned long,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct max6639_data* dev_get_drvdata (struct device*) ; 
 struct max6639_platform_data* dev_get_platdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct max6639_data*,int /*<<< orphan*/ ) ; 
 struct max6639_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  max6639_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* rpm_ranges ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static struct max6639_data *max6639_update_device(struct device *dev)
{
	struct max6639_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct max6639_data *ret = data;
	int i;
	int status_reg;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
		int res;

		dev_dbg(&client->dev, "Starting max6639 update\n");

		status_reg = i2c_smbus_read_byte_data(client,
						      MAX6639_REG_STATUS);
		if (status_reg < 0) {
			ret = ERR_PTR(status_reg);
			goto abort;
		}

		data->status = status_reg;

		for (i = 0; i < 2; i++) {
			res = i2c_smbus_read_byte_data(client,
					MAX6639_REG_FAN_CNT(i));
			if (res < 0) {
				ret = ERR_PTR(res);
				goto abort;
			}
			data->fan[i] = res;

			res = i2c_smbus_read_byte_data(client,
					MAX6639_REG_TEMP_EXT(i));
			if (res < 0) {
				ret = ERR_PTR(res);
				goto abort;
			}
			data->temp[i] = res >> 5;
			data->temp_fault[i] = res & 0x01;

			res = i2c_smbus_read_byte_data(client,
					MAX6639_REG_TEMP(i));
			if (res < 0) {
				ret = ERR_PTR(res);
				goto abort;
			}
			data->temp[i] |= res << 3;
		}

		data->last_updated = jiffies;
		data->valid = 1;
	}
abort:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static ssize_t show_temp_input(struct device *dev,
			       struct device_attribute *dev_attr, char *buf)
{
	long temp;
	struct max6639_data *data = max6639_update_device(dev);
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);

	if (IS_ERR(data))
		return PTR_ERR(data);

	temp = data->temp[attr->index] * 125;
	return sprintf(buf, "%ld\n", temp);
}

__attribute__((used)) static ssize_t show_temp_fault(struct device *dev,
			       struct device_attribute *dev_attr, char *buf)
{
	struct max6639_data *data = max6639_update_device(dev);
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->temp_fault[attr->index]);
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev,
			     struct device_attribute *dev_attr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%d\n", (data->temp_therm[attr->index] * 1000));
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev,
			    struct device_attribute *dev_attr,
			    const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int res;

	res = kstrtoul(buf, 10, &val);
	if (res)
		return res;

	mutex_lock(&data->update_lock);
	data->temp_therm[attr->index] = TEMP_LIMIT_TO_REG(val);
	i2c_smbus_write_byte_data(client,
				  MAX6639_REG_THERM_LIMIT(attr->index),
				  data->temp_therm[attr->index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_crit(struct device *dev,
			      struct device_attribute *dev_attr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%d\n", (data->temp_alert[attr->index] * 1000));
}

__attribute__((used)) static ssize_t set_temp_crit(struct device *dev,
			     struct device_attribute *dev_attr,
			     const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int res;

	res = kstrtoul(buf, 10, &val);
	if (res)
		return res;

	mutex_lock(&data->update_lock);
	data->temp_alert[attr->index] = TEMP_LIMIT_TO_REG(val);
	i2c_smbus_write_byte_data(client,
				  MAX6639_REG_ALERT_LIMIT(attr->index),
				  data->temp_alert[attr->index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_emergency(struct device *dev,
				   struct device_attribute *dev_attr,
				   char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%d\n", (data->temp_ot[attr->index] * 1000));
}

__attribute__((used)) static ssize_t set_temp_emergency(struct device *dev,
				  struct device_attribute *dev_attr,
				  const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int res;

	res = kstrtoul(buf, 10, &val);
	if (res)
		return res;

	mutex_lock(&data->update_lock);
	data->temp_ot[attr->index] = TEMP_LIMIT_TO_REG(val);
	i2c_smbus_write_byte_data(client,
				  MAX6639_REG_OT_LIMIT(attr->index),
				  data->temp_ot[attr->index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm(struct device *dev,
			struct device_attribute *dev_attr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%d\n", data->pwm[attr->index] * 255 / 120);
}

__attribute__((used)) static ssize_t set_pwm(struct device *dev,
		       struct device_attribute *dev_attr,
		       const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
	struct max6639_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int res;

	res = kstrtoul(buf, 10, &val);
	if (res)
		return res;

	val = clamp_val(val, 0, 255);

	mutex_lock(&data->update_lock);
	data->pwm[attr->index] = (u8)(val * 120 / 255);
	i2c_smbus_write_byte_data(client,
				  MAX6639_REG_TARGTDUTY(attr->index),
				  data->pwm[attr->index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_fan_input(struct device *dev,
			      struct device_attribute *dev_attr, char *buf)
{
	struct max6639_data *data = max6639_update_device(dev);
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[attr->index],
		       data->rpm_range));
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev,
			  struct device_attribute *dev_attr, char *buf)
{
	struct max6639_data *data = max6639_update_device(dev);
	struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", !!(data->status & (1 << attr->index)));
}

__attribute__((used)) static int rpm_range_to_reg(int range)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(rpm_ranges); i++) {
		if (rpm_ranges[i] == range)
			return i;
	}

	return 1; /* default: 4000 RPM */
}

__attribute__((used)) static int max6639_init_client(struct i2c_client *client,
			       struct max6639_data *data)
{
	struct max6639_platform_data *max6639_info =
		dev_get_platdata(&client->dev);
	int i;
	int rpm_range = 1; /* default: 4000 RPM */
	int err;

	/* Reset chip to default values, see below for GCONFIG setup */
	err = i2c_smbus_write_byte_data(client, MAX6639_REG_GCONFIG,
				  MAX6639_GCONFIG_POR);
	if (err)
		goto exit;

	/* Fans pulse per revolution is 2 by default */
	if (max6639_info && max6639_info->ppr > 0 &&
			max6639_info->ppr < 5)
		data->ppr = max6639_info->ppr;
	else
		data->ppr = 2;
	data->ppr -= 1;

	if (max6639_info)
		rpm_range = rpm_range_to_reg(max6639_info->rpm_range);
	data->rpm_range = rpm_range;

	for (i = 0; i < 2; i++) {

		/* Set Fan pulse per revolution */
		err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_FAN_PPR(i),
				data->ppr << 6);
		if (err)
			goto exit;

		/* Fans config PWM, RPM */
		err = i2c_smbus_write_byte_data(client,
			MAX6639_REG_FAN_CONFIG1(i),
			MAX6639_FAN_CONFIG1_PWM | rpm_range);
		if (err)
			goto exit;

		/* Fans PWM polarity high by default */
		if (max6639_info && max6639_info->pwm_polarity == 0)
			err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_FAN_CONFIG2a(i), 0x00);
		else
			err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_FAN_CONFIG2a(i), 0x02);
		if (err)
			goto exit;

		/*
		 * /THERM full speed enable,
		 * PWM frequency 25kHz, see also GCONFIG below
		 */
		err = i2c_smbus_write_byte_data(client,
			MAX6639_REG_FAN_CONFIG3(i),
			MAX6639_FAN_CONFIG3_THERM_FULL_SPEED | 0x03);
		if (err)
			goto exit;

		/* Max. temp. 80C/90C/100C */
		data->temp_therm[i] = 80;
		data->temp_alert[i] = 90;
		data->temp_ot[i] = 100;
		err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_THERM_LIMIT(i),
				data->temp_therm[i]);
		if (err)
			goto exit;
		err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_ALERT_LIMIT(i),
				data->temp_alert[i]);
		if (err)
			goto exit;
		err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_OT_LIMIT(i), data->temp_ot[i]);
		if (err)
			goto exit;

		/* PWM 120/120 (i.e. 100%) */
		data->pwm[i] = 120;
		err = i2c_smbus_write_byte_data(client,
				MAX6639_REG_TARGTDUTY(i), data->pwm[i]);
		if (err)
			goto exit;
	}
	/* Start monitoring */
	err = i2c_smbus_write_byte_data(client, MAX6639_REG_GCONFIG,
		MAX6639_GCONFIG_DISABLE_TIMEOUT | MAX6639_GCONFIG_CH2_LOCAL |
		MAX6639_GCONFIG_PWM_FREQ_HI);
exit:
	return err;
}

__attribute__((used)) static int max6639_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int dev_id, manu_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* Actual detection via device and manufacturer ID */
	dev_id = i2c_smbus_read_byte_data(client, MAX6639_REG_DEVID);
	manu_id = i2c_smbus_read_byte_data(client, MAX6639_REG_MANUID);
	if (dev_id != 0x58 || manu_id != 0x4D)
		return -ENODEV;

	strlcpy(info->type, "max6639", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int max6639_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct max6639_data *data;
	struct device *hwmon_dev;
	int err;

	data = devm_kzalloc(dev, sizeof(struct max6639_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the max6639 chip */
	err = max6639_init_client(client, data);
	if (err < 0)
		return err;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   max6639_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


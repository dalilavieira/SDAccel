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
struct thermal_data {int /*<<< orphan*/ ** groups; int /*<<< orphan*/  mutex; struct regmap* regmap; } ;
struct sensor_device_attribute_2 {int nr; unsigned int index; } ;
struct sensor_device_attribute {int index; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int driver_data; int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct device_attribute {int dummy; } ;
typedef  struct regmap device ;
typedef  int ssize_t ;

/* Variables and functions */
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  THERMAL_PID_REG ; 
 int /*<<< orphan*/  THERMAL_REVISION_REG ; 
 int /*<<< orphan*/  THERMAL_SMSC_ID_REG ; 
 int clamp_val (int,int /*<<< orphan*/ ,int) ; 
 struct thermal_data* dev_get_drvdata (struct regmap*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct regmap* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct thermal_data*,int /*<<< orphan*/ **) ; 
 struct thermal_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
#define  emc1402 130 
 int /*<<< orphan*/  emc1402_alarm_group ; 
 int /*<<< orphan*/  emc1402_group ; 
#define  emc1403 129 
 int /*<<< orphan*/  emc1403_group ; 
 int /*<<< orphan*/  emc1403_regmap_config ; 
#define  emc1404 128 
 int /*<<< orphan*/  emc1404_group ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_read (struct regmap*,int,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int,unsigned int,unsigned int) ; 
 int regmap_write (struct regmap*,int,int) ; 
 int sprintf (char*,char*,unsigned int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t show_temp(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
	struct thermal_data *data = dev_get_drvdata(dev);
	unsigned int val;
	int retval;

	retval = regmap_read(data->regmap, sda->index, &val);
	if (retval < 0)
		return retval;
	return sprintf(buf, "%d000\n", val);
}

__attribute__((used)) static ssize_t show_bit(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
	struct thermal_data *data = dev_get_drvdata(dev);
	unsigned int val;
	int retval;

	retval = regmap_read(data->regmap, sda->nr, &val);
	if (retval < 0)
		return retval;
	return sprintf(buf, "%d\n", !!(val & sda->index));
}

__attribute__((used)) static ssize_t store_temp(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
	struct thermal_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int retval;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;
	retval = regmap_write(data->regmap, sda->index,
			      DIV_ROUND_CLOSEST(val, 1000));
	if (retval < 0)
		return retval;
	return count;
}

__attribute__((used)) static ssize_t store_bit(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
	struct thermal_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int retval;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	retval = regmap_update_bits(data->regmap, sda->nr, sda->index,
				    val ? sda->index : 0);
	if (retval < 0)
		return retval;
	return count;
}

__attribute__((used)) static ssize_t show_hyst_common(struct device *dev,
				struct device_attribute *attr, char *buf,
				bool is_min)
{
	struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
	struct thermal_data *data = dev_get_drvdata(dev);
	struct regmap *regmap = data->regmap;
	unsigned int limit;
	unsigned int hyst;
	int retval;

	retval = regmap_read(regmap, sda->index, &limit);
	if (retval < 0)
		return retval;

	retval = regmap_read(regmap, 0x21, &hyst);
	if (retval < 0)
		return retval;

	return sprintf(buf, "%d000\n", is_min ? limit + hyst : limit - hyst);
}

__attribute__((used)) static ssize_t show_hyst(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	return show_hyst_common(dev, attr, buf, false);
}

__attribute__((used)) static ssize_t show_min_hyst(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	return show_hyst_common(dev, attr, buf, true);
}

__attribute__((used)) static ssize_t store_hyst(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
	struct thermal_data *data = dev_get_drvdata(dev);
	struct regmap *regmap = data->regmap;
	unsigned int limit;
	int retval;
	int hyst;
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	mutex_lock(&data->mutex);
	retval = regmap_read(regmap, sda->index, &limit);
	if (retval < 0)
		goto fail;

	hyst = limit * 1000 - val;
	hyst = clamp_val(DIV_ROUND_CLOSEST(hyst, 1000), 0, 255);
	retval = regmap_write(regmap, 0x21, hyst);
	if (retval == 0)
		retval = count;
fail:
	mutex_unlock(&data->mutex);
	return retval;
}

__attribute__((used)) static int emc1403_detect(struct i2c_client *client,
			struct i2c_board_info *info)
{
	int id;
	/* Check if thermal chip is SMSC and EMC1403 or EMC1423 */

	id = i2c_smbus_read_byte_data(client, THERMAL_SMSC_ID_REG);
	if (id != 0x5d)
		return -ENODEV;

	id = i2c_smbus_read_byte_data(client, THERMAL_PID_REG);
	switch (id) {
	case 0x20:
		strlcpy(info->type, "emc1402", I2C_NAME_SIZE);
		break;
	case 0x21:
		strlcpy(info->type, "emc1403", I2C_NAME_SIZE);
		break;
	case 0x22:
		strlcpy(info->type, "emc1422", I2C_NAME_SIZE);
		break;
	case 0x23:
		strlcpy(info->type, "emc1423", I2C_NAME_SIZE);
		break;
	case 0x25:
		strlcpy(info->type, "emc1404", I2C_NAME_SIZE);
		break;
	case 0x27:
		strlcpy(info->type, "emc1424", I2C_NAME_SIZE);
		break;
	default:
		return -ENODEV;
	}

	id = i2c_smbus_read_byte_data(client, THERMAL_REVISION_REG);
	if (id < 0x01 || id > 0x04)
		return -ENODEV;

	return 0;
}

__attribute__((used)) static bool emc1403_regmap_is_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case 0x00:	/* internal diode high byte */
	case 0x01:	/* external diode 1 high byte */
	case 0x02:	/* status */
	case 0x10:	/* external diode 1 low byte */
	case 0x1b:	/* external diode fault */
	case 0x23:	/* external diode 2 high byte */
	case 0x24:	/* external diode 2 low byte */
	case 0x29:	/* internal diode low byte */
	case 0x2a:	/* externl diode 3 high byte */
	case 0x2b:	/* external diode 3 low byte */
	case 0x35:	/* high limit status */
	case 0x36:	/* low limit status */
	case 0x37:	/* therm limit status */
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int emc1403_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct thermal_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(&client->dev, sizeof(struct thermal_data),
			    GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	data->regmap = devm_regmap_init_i2c(client, &emc1403_regmap_config);
	if (IS_ERR(data->regmap))
		return PTR_ERR(data->regmap);

	mutex_init(&data->mutex);

	switch (id->driver_data) {
	case emc1404:
		data->groups[2] = &emc1404_group;
		/* fall through */
	case emc1403:
		data->groups[1] = &emc1403_group;
		/* fall through */
	case emc1402:
		data->groups[0] = &emc1402_group;
	}

	if (id->driver_data == emc1402)
		data->groups[1] = &emc1402_alarm_group;

	hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
							   client->name, data,
							   data->groups);
	if (IS_ERR(hwmon_dev))
		return PTR_ERR(hwmon_dev);

	dev_info(&client->dev, "%s Thermal chip found\n", id->name);
	return 0;
}


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
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int addr; int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct adm1025_data {int valid; int* in; int* in_min; int* in_max; int* temp; int* temp_min; int* temp_max; int alarms; int vid; int vrm; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADM1025_REG_CHIP_ID ; 
 int /*<<< orphan*/  ADM1025_REG_CONFIG ; 
 int /*<<< orphan*/  ADM1025_REG_IN (int) ; 
 int /*<<< orphan*/  ADM1025_REG_IN_MAX (int) ; 
 int /*<<< orphan*/  ADM1025_REG_IN_MIN (int) ; 
 int /*<<< orphan*/  ADM1025_REG_MAN_ID ; 
 int /*<<< orphan*/  ADM1025_REG_STATUS1 ; 
 int /*<<< orphan*/  ADM1025_REG_STATUS2 ; 
 int /*<<< orphan*/  ADM1025_REG_TEMP (int) ; 
 int /*<<< orphan*/  ADM1025_REG_TEMP_HIGH (int) ; 
 int /*<<< orphan*/  ADM1025_REG_TEMP_LOW (int) ; 
 int /*<<< orphan*/  ADM1025_REG_VID ; 
 int /*<<< orphan*/  ADM1025_REG_VID4 ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int IN_FROM_REG (int,int /*<<< orphan*/ ) ; 
 void* IN_TO_REG (long,int /*<<< orphan*/ ) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int TEMP_FROM_REG (int) ; 
 void* TEMP_TO_REG (long) ; 
 int /*<<< orphan*/  adm1025_group ; 
 int /*<<< orphan*/  adm1025_group_in4 ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct adm1025_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct adm1025_data*,int /*<<< orphan*/ **) ; 
 struct adm1025_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct adm1025_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct adm1025_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * in_scale ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 int vid_from_reg (int,int) ; 
 unsigned long vid_which_vrm () ; 

__attribute__((used)) static struct adm1025_data *adm1025_update_device(struct device *dev)
{
	struct adm1025_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ * 2) || !data->valid) {
		int i;

		dev_dbg(&client->dev, "Updating data.\n");
		for (i = 0; i < 6; i++) {
			data->in[i] = i2c_smbus_read_byte_data(client,
				      ADM1025_REG_IN(i));
			data->in_min[i] = i2c_smbus_read_byte_data(client,
					  ADM1025_REG_IN_MIN(i));
			data->in_max[i] = i2c_smbus_read_byte_data(client,
					  ADM1025_REG_IN_MAX(i));
		}
		for (i = 0; i < 2; i++) {
			data->temp[i] = i2c_smbus_read_byte_data(client,
					ADM1025_REG_TEMP(i));
			data->temp_min[i] = i2c_smbus_read_byte_data(client,
					    ADM1025_REG_TEMP_LOW(i));
			data->temp_max[i] = i2c_smbus_read_byte_data(client,
					    ADM1025_REG_TEMP_HIGH(i));
		}
		data->alarms = i2c_smbus_read_byte_data(client,
			       ADM1025_REG_STATUS1)
			     | (i2c_smbus_read_byte_data(client,
				ADM1025_REG_STATUS2) << 8);
		data->vid = (i2c_smbus_read_byte_data(client,
			     ADM1025_REG_VID) & 0x0f)
			  | ((i2c_smbus_read_byte_data(client,
			      ADM1025_REG_VID4) & 0x01) << 4);

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t
show_in(struct device *dev, struct device_attribute *attr, char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%u\n", IN_FROM_REG(data->in[index],
		       in_scale[index]));
}

__attribute__((used)) static ssize_t
show_in_min(struct device *dev, struct device_attribute *attr, char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%u\n", IN_FROM_REG(data->in_min[index],
		       in_scale[index]));
}

__attribute__((used)) static ssize_t
show_in_max(struct device *dev, struct device_attribute *attr, char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%u\n", IN_FROM_REG(data->in_max[index],
		       in_scale[index]));
}

__attribute__((used)) static ssize_t
show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[index]));
}

__attribute__((used)) static ssize_t
show_temp_min(struct device *dev, struct device_attribute *attr, char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[index]));
}

__attribute__((used)) static ssize_t
show_temp_max(struct device *dev, struct device_attribute *attr, char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[index]));
}

__attribute__((used)) static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_min[index] = IN_TO_REG(val, in_scale[index]);
	i2c_smbus_write_byte_data(client, ADM1025_REG_IN_MIN(index),
				  data->in_min[index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_max[index] = IN_TO_REG(val, in_scale[index]);
	i2c_smbus_write_byte_data(client, ADM1025_REG_IN_MAX(index),
				  data->in_max[index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_min[index] = TEMP_TO_REG(val);
	i2c_smbus_write_byte_data(client, ADM1025_REG_TEMP_LOW(index),
				  data->temp_min[index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_max[index] = TEMP_TO_REG(val);
	i2c_smbus_write_byte_data(client, ADM1025_REG_TEMP_HIGH(index),
				  data->temp_max[index]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
alarms_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t
show_alarm(struct device *dev, struct device_attribute *attr, char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static ssize_t
cpu0_vid_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct adm1025_data *data = adm1025_update_device(dev);
	return sprintf(buf, "%u\n", vid_from_reg(data->vid, data->vrm));
}

__attribute__((used)) static ssize_t
vrm_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct adm1025_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%u\n", data->vrm);
}

__attribute__((used)) static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	struct adm1025_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	if (val > 255)
		return -EINVAL;

	data->vrm = val;
	return count;
}

__attribute__((used)) static int adm1025_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	const char *name;
	u8 man_id, chip_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* Check for unused bits */
	if ((i2c_smbus_read_byte_data(client, ADM1025_REG_CONFIG) & 0x80)
	 || (i2c_smbus_read_byte_data(client, ADM1025_REG_STATUS1) & 0xC0)
	 || (i2c_smbus_read_byte_data(client, ADM1025_REG_STATUS2) & 0xBC)) {
		dev_dbg(&adapter->dev, "ADM1025 detection failed at 0x%02x\n",
			client->addr);
		return -ENODEV;
	}

	/* Identification */
	chip_id = i2c_smbus_read_byte_data(client, ADM1025_REG_CHIP_ID);
	if ((chip_id & 0xF0) != 0x20)
		return -ENODEV;

	man_id = i2c_smbus_read_byte_data(client, ADM1025_REG_MAN_ID);
	if (man_id == 0x41)
		name = "adm1025";
	else if (man_id == 0xA1 && client->addr != 0x2E)
		name = "ne1619";
	else
		return -ENODEV;

	strlcpy(info->type, name, I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void adm1025_init_client(struct i2c_client *client)
{
	u8 reg;
	struct adm1025_data *data = i2c_get_clientdata(client);
	int i;

	data->vrm = vid_which_vrm();

	/*
	 * Set high limits
	 * Usually we avoid setting limits on driver init, but it happens
	 * that the ADM1025 comes with stupid default limits (all registers
	 * set to 0). In case the chip has not gone through any limit
	 * setting yet, we better set the high limits to the max so that
	 * no alarm triggers.
	 */
	for (i = 0; i < 6; i++) {
		reg = i2c_smbus_read_byte_data(client,
					       ADM1025_REG_IN_MAX(i));
		if (reg == 0)
			i2c_smbus_write_byte_data(client,
						  ADM1025_REG_IN_MAX(i),
						  0xFF);
	}
	for (i = 0; i < 2; i++) {
		reg = i2c_smbus_read_byte_data(client,
					       ADM1025_REG_TEMP_HIGH(i));
		if (reg == 0)
			i2c_smbus_write_byte_data(client,
						  ADM1025_REG_TEMP_HIGH(i),
						  0x7F);
	}

	/*
	 * Start the conversions
	 */
	reg = i2c_smbus_read_byte_data(client, ADM1025_REG_CONFIG);
	if (!(reg & 0x01))
		i2c_smbus_write_byte_data(client, ADM1025_REG_CONFIG,
					  (reg&0x7E)|0x01);
}

__attribute__((used)) static int adm1025_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct adm1025_data *data;
	u8 config;

	data = devm_kzalloc(dev, sizeof(struct adm1025_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the ADM1025 chip */
	adm1025_init_client(client);

	/* sysfs hooks */
	data->groups[0] = &adm1025_group;
	/* Pin 11 is either in4 (+12V) or VID4 */
	config = i2c_smbus_read_byte_data(client, ADM1025_REG_CONFIG);
	if (!(config & 0x20))
		data->groups[1] = &adm1025_group_in4;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


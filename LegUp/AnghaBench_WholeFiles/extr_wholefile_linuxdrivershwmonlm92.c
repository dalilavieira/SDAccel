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
typedef  int u16 ;
struct sensor_device_attribute {size_t index; } ;
struct lm92_data {int valid; int* temp; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int s16 ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int /*<<< orphan*/  LM92_REG_CONFIG ; 
 int /*<<< orphan*/  LM92_REG_MAN_ID ; 
 int /*<<< orphan*/  LM92_REG_TEMP_HYST ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 long clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 struct lm92_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct lm92_data*,int /*<<< orphan*/ ) ; 
 struct lm92_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  lm92_groups ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/ * regs ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 size_t t_hyst ; 
 size_t t_input ; 
 size_t t_min ; 
 int t_num_regs ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline int TEMP_FROM_REG(s16 reg)
{
	return reg / 8 * 625 / 10;
}

__attribute__((used)) static inline s16 TEMP_TO_REG(long val)
{
	val = clamp_val(val, -60000, 160000);
	return val * 10 / 625 * 8;
}

__attribute__((used)) static inline u8 ALARMS_FROM_REG(s16 reg)
{
	return reg & 0x0007;
}

__attribute__((used)) static struct lm92_data *lm92_update_device(struct device *dev)
{
	struct lm92_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ)
	 || !data->valid) {
		dev_dbg(&client->dev, "Updating lm92 data\n");
		for (i = 0; i < t_num_regs; i++) {
			data->temp[i] =
				i2c_smbus_read_word_swapped(client, regs[i]);
		}
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
	struct lm92_data *data = lm92_update_device(dev);

	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
			   const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm92_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = attr->index;
	long val;
	int err;
	
	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp[nr] = TEMP_TO_REG(val);
	i2c_smbus_write_word_swapped(client, regs[nr], data->temp[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_hyst(struct device *dev,
			      struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm92_data *data = lm92_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index])
		       - TEMP_FROM_REG(data->temp[t_hyst]));
}

__attribute__((used)) static ssize_t temp1_min_hyst_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct lm92_data *data = lm92_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[t_min])
		       + TEMP_FROM_REG(data->temp[t_hyst]));
}

__attribute__((used)) static ssize_t set_temp_hyst(struct device *dev,
			     struct device_attribute *devattr,
			     const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct lm92_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	val = clamp_val(val, -120000, 220000);
	mutex_lock(&data->update_lock);
	 data->temp[t_hyst] =
		TEMP_TO_REG(TEMP_FROM_REG(data->temp[attr->index]) - val);
	i2c_smbus_write_word_swapped(client, LM92_REG_TEMP_HYST,
				     data->temp[t_hyst]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct lm92_data *data = lm92_update_device(dev);
	return sprintf(buf, "%d\n", ALARMS_FROM_REG(data->temp[t_input]));
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct lm92_data *data = lm92_update_device(dev);
	return sprintf(buf, "%d\n", (data->temp[t_input] >> bitnr) & 1);
}

__attribute__((used)) static void lm92_init_client(struct i2c_client *client)
{
	u8 config;

	/* Start the conversions if needed */
	config = i2c_smbus_read_byte_data(client, LM92_REG_CONFIG);
	if (config & 0x01)
		i2c_smbus_write_byte_data(client, LM92_REG_CONFIG,
					  config & 0xFE);
}

__attribute__((used)) static int lm92_detect(struct i2c_client *new_client,
		       struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = new_client->adapter;
	u8 config;
	u16 man_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
					    | I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	config = i2c_smbus_read_byte_data(new_client, LM92_REG_CONFIG);
	man_id = i2c_smbus_read_word_data(new_client, LM92_REG_MAN_ID);

	if ((config & 0xe0) == 0x00 && man_id == 0x0180)
		pr_info("lm92: Found National Semiconductor LM92 chip\n");
	else
		return -ENODEV;

	strlcpy(info->type, "lm92", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int lm92_probe(struct i2c_client *new_client,
		      const struct i2c_device_id *id)
{
	struct device *hwmon_dev;
	struct lm92_data *data;

	data = devm_kzalloc(&new_client->dev, sizeof(struct lm92_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = new_client;
	mutex_init(&data->update_lock);

	/* Initialize the chipset */
	lm92_init_client(new_client);

	hwmon_dev = devm_hwmon_device_register_with_groups(&new_client->dev,
							   new_client->name,
							   data, lm92_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


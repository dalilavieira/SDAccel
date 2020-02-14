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
typedef  int u32 ;
typedef  int u16 ;
struct lm95234_data {int interval; int* tcrit1; int* tcrit2; int* toffset; int thyst; int sensor_type; int last_updated; int valid; int* temp; int status; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int addr; int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int s16 ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
#define  LM95233_CHIP_ID 129 
#define  LM95234_CHIP_ID 128 
 int /*<<< orphan*/  LM95234_REG_CHIP_ID ; 
 int /*<<< orphan*/  LM95234_REG_CONFIG ; 
 int /*<<< orphan*/  LM95234_REG_CONVRATE ; 
 int /*<<< orphan*/  LM95234_REG_MAN_ID ; 
 int /*<<< orphan*/  LM95234_REG_OFFSET (int) ; 
 int /*<<< orphan*/  LM95234_REG_REM_MODEL ; 
 int /*<<< orphan*/  LM95234_REG_REM_MODEL_STS ; 
 int /*<<< orphan*/  LM95234_REG_STATUS ; 
 int /*<<< orphan*/  LM95234_REG_STS_FAULT ; 
 int /*<<< orphan*/  LM95234_REG_STS_TCRIT1 ; 
 int /*<<< orphan*/  LM95234_REG_STS_TCRIT2 ; 
 int /*<<< orphan*/  LM95234_REG_TCRIT1 (int) ; 
 int /*<<< orphan*/  LM95234_REG_TCRIT2 (int) ; 
 int /*<<< orphan*/  LM95234_REG_TCRIT_HYST ; 
 int /*<<< orphan*/  LM95234_REG_TEMPH (int) ; 
 int /*<<< orphan*/  LM95234_REG_TEMPL (int) ; 
 int /*<<< orphan*/  LM95234_REG_UTEMPH (int) ; 
 int /*<<< orphan*/  LM95234_REG_UTEMPL (int) ; 
 int NATSEMI_MAN_ID ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 long clamp_val (int,int,int) ; 
 struct lm95234_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_notice (struct device*,char*,int) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct lm95234_data*,int /*<<< orphan*/ **) ; 
 struct lm95234_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 scalar_t__ lm95234 ; 
 int /*<<< orphan*/  lm95234_common_group ; 
 int /*<<< orphan*/  lm95234_group ; 
 void* msecs_to_jiffies (unsigned long) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (int,int) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 unsigned long* update_intervals ; 

__attribute__((used)) static int lm95234_read_temp(struct i2c_client *client, int index, int *t)
{
	int val;
	u16 temp = 0;

	if (index) {
		val = i2c_smbus_read_byte_data(client,
					       LM95234_REG_UTEMPH(index - 1));
		if (val < 0)
			return val;
		temp = val << 8;
		val = i2c_smbus_read_byte_data(client,
					       LM95234_REG_UTEMPL(index - 1));
		if (val < 0)
			return val;
		temp |= val;
		*t = temp;
	}
	/*
	 * Read signed temperature if unsigned temperature is 0,
	 * or if this is the local sensor.
	 */
	if (!temp) {
		val = i2c_smbus_read_byte_data(client,
					       LM95234_REG_TEMPH(index));
		if (val < 0)
			return val;
		temp = val << 8;
		val = i2c_smbus_read_byte_data(client,
					       LM95234_REG_TEMPL(index));
		if (val < 0)
			return val;
		temp |= val;
		*t = (s16)temp;
	}
	return 0;
}

__attribute__((used)) static int lm95234_fill_cache(struct lm95234_data *data,
			      struct i2c_client *client)
{
	int i, ret;

	ret = i2c_smbus_read_byte_data(client, LM95234_REG_CONVRATE);
	if (ret < 0)
		return ret;

	data->interval = msecs_to_jiffies(update_intervals[ret & 0x03]);

	for (i = 0; i < ARRAY_SIZE(data->tcrit1); i++) {
		ret = i2c_smbus_read_byte_data(client, LM95234_REG_TCRIT1(i));
		if (ret < 0)
			return ret;
		data->tcrit1[i] = ret;
	}
	for (i = 0; i < ARRAY_SIZE(data->tcrit2); i++) {
		ret = i2c_smbus_read_byte_data(client, LM95234_REG_TCRIT2(i));
		if (ret < 0)
			return ret;
		data->tcrit2[i] = ret;
	}
	for (i = 0; i < ARRAY_SIZE(data->toffset); i++) {
		ret = i2c_smbus_read_byte_data(client, LM95234_REG_OFFSET(i));
		if (ret < 0)
			return ret;
		data->toffset[i] = ret;
	}

	ret = i2c_smbus_read_byte_data(client, LM95234_REG_TCRIT_HYST);
	if (ret < 0)
		return ret;
	data->thyst = ret;

	ret = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL);
	if (ret < 0)
		return ret;
	data->sensor_type = ret;

	return 0;
}

__attribute__((used)) static int lm95234_update_device(struct lm95234_data *data)
{
	struct i2c_client *client = data->client;
	int ret;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + data->interval) ||
	    !data->valid) {
		int i;

		if (!data->valid) {
			ret = lm95234_fill_cache(data, client);
			if (ret < 0)
				goto abort;
		}

		data->valid = false;
		for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
			ret = lm95234_read_temp(client, i, &data->temp[i]);
			if (ret < 0)
				goto abort;
		}

		ret = i2c_smbus_read_byte_data(client, LM95234_REG_STS_FAULT);
		if (ret < 0)
			goto abort;
		data->status = ret;

		ret = i2c_smbus_read_byte_data(client, LM95234_REG_STS_TCRIT1);
		if (ret < 0)
			goto abort;
		data->status |= ret << 8;

		ret = i2c_smbus_read_byte_data(client, LM95234_REG_STS_TCRIT2);
		if (ret < 0)
			goto abort;
		data->status |= ret << 16;

		data->last_updated = jiffies;
		data->valid = true;
	}
	ret = 0;
abort:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	return sprintf(buf, "%d\n",
		       DIV_ROUND_CLOSEST(data->temp[index] * 125, 32));
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev,
			  struct device_attribute *attr, char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	u32 mask = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	return sprintf(buf, "%u", !!(data->status & mask));
}

__attribute__((used)) static ssize_t show_type(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	u8 mask = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	return sprintf(buf, data->sensor_type & mask ? "1\n" : "2\n");
}

__attribute__((used)) static ssize_t set_type(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	unsigned long val;
	u8 mask = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	ret = kstrtoul(buf, 10, &val);
	if (ret < 0)
		return ret;

	if (val != 1 && val != 2)
		return -EINVAL;

	mutex_lock(&data->update_lock);
	if (val == 1)
		data->sensor_type |= mask;
	else
		data->sensor_type &= ~mask;
	data->valid = false;
	i2c_smbus_write_byte_data(data->client, LM95234_REG_REM_MODEL,
				  data->sensor_type);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_tcrit2(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	return sprintf(buf, "%u", data->tcrit2[index] * 1000);
}

__attribute__((used)) static ssize_t set_tcrit2(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	long val;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0, index ? 255 : 127);

	mutex_lock(&data->update_lock);
	data->tcrit2[index] = val;
	i2c_smbus_write_byte_data(data->client, LM95234_REG_TCRIT2(index), val);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_tcrit2_hyst(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	/* Result can be negative, so be careful with unsigned operands */
	return sprintf(buf, "%d",
		       ((int)data->tcrit2[index] - (int)data->thyst) * 1000);
}

__attribute__((used)) static ssize_t show_tcrit1(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%u", data->tcrit1[index] * 1000);
}

__attribute__((used)) static ssize_t set_tcrit1(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);
	long val;

	if (ret)
		return ret;

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0, 255);

	mutex_lock(&data->update_lock);
	data->tcrit1[index] = val;
	i2c_smbus_write_byte_data(data->client, LM95234_REG_TCRIT1(index), val);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_tcrit1_hyst(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	/* Result can be negative, so be careful with unsigned operands */
	return sprintf(buf, "%d",
		       ((int)data->tcrit1[index] - (int)data->thyst) * 1000);
}

__attribute__((used)) static ssize_t set_tcrit1_hyst(struct device *dev,
			       struct device_attribute *attr,
			       const char *buf, size_t count)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);
	long val;

	if (ret)
		return ret;

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	val = DIV_ROUND_CLOSEST(val, 1000);
	val = clamp_val((int)data->tcrit1[index] - val, 0, 31);

	mutex_lock(&data->update_lock);
	data->thyst = val;
	i2c_smbus_write_byte_data(data->client, LM95234_REG_TCRIT_HYST, val);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_offset(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	return sprintf(buf, "%d", data->toffset[index] * 500);
}

__attribute__((used)) static ssize_t set_offset(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int index = to_sensor_dev_attr(attr)->index;
	int ret = lm95234_update_device(data);
	long val;

	if (ret)
		return ret;

	ret = kstrtol(buf, 10, &val);
	if (ret < 0)
		return ret;

	/* Accuracy is 1/2 degrees C */
	val = clamp_val(DIV_ROUND_CLOSEST(val, 500), -128, 127);

	mutex_lock(&data->update_lock);
	data->toffset[index] = val;
	i2c_smbus_write_byte_data(data->client, LM95234_REG_OFFSET(index), val);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t update_interval_show(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int ret = lm95234_update_device(data);

	if (ret)
		return ret;

	return sprintf(buf, "%lu\n",
		       DIV_ROUND_CLOSEST(data->interval * 1000, HZ));
}

__attribute__((used)) static ssize_t update_interval_store(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf, size_t count)
{
	struct lm95234_data *data = dev_get_drvdata(dev);
	int ret = lm95234_update_device(data);
	unsigned long val;
	u8 regval;

	if (ret)
		return ret;

	ret = kstrtoul(buf, 10, &val);
	if (ret < 0)
		return ret;

	for (regval = 0; regval < 3; regval++) {
		if (val <= update_intervals[regval])
			break;
	}

	mutex_lock(&data->update_lock);
	data->interval = msecs_to_jiffies(update_intervals[regval]);
	i2c_smbus_write_byte_data(data->client, LM95234_REG_CONVRATE, regval);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static int lm95234_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int address = client->addr;
	u8 config_mask, model_mask;
	int mfg_id, chip_id, val;
	const char *name;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	mfg_id = i2c_smbus_read_byte_data(client, LM95234_REG_MAN_ID);
	if (mfg_id != NATSEMI_MAN_ID)
		return -ENODEV;

	chip_id = i2c_smbus_read_byte_data(client, LM95234_REG_CHIP_ID);
	switch (chip_id) {
	case LM95233_CHIP_ID:
		if (address != 0x18 && address != 0x2a && address != 0x2b)
			return -ENODEV;
		config_mask = 0xbf;
		model_mask = 0xf9;
		name = "lm95233";
		break;
	case LM95234_CHIP_ID:
		if (address != 0x18 && address != 0x4d && address != 0x4e)
			return -ENODEV;
		config_mask = 0xbc;
		model_mask = 0xe1;
		name = "lm95234";
		break;
	default:
		return -ENODEV;
	}

	val = i2c_smbus_read_byte_data(client, LM95234_REG_STATUS);
	if (val & 0x30)
		return -ENODEV;

	val = i2c_smbus_read_byte_data(client, LM95234_REG_CONFIG);
	if (val & config_mask)
		return -ENODEV;

	val = i2c_smbus_read_byte_data(client, LM95234_REG_CONVRATE);
	if (val & 0xfc)
		return -ENODEV;

	val = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL);
	if (val & model_mask)
		return -ENODEV;

	val = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL_STS);
	if (val & model_mask)
		return -ENODEV;

	strlcpy(info->type, name, I2C_NAME_SIZE);
	return 0;
}

__attribute__((used)) static int lm95234_init_client(struct i2c_client *client)
{
	int val, model;

	/* start conversion if necessary */
	val = i2c_smbus_read_byte_data(client, LM95234_REG_CONFIG);
	if (val < 0)
		return val;
	if (val & 0x40)
		i2c_smbus_write_byte_data(client, LM95234_REG_CONFIG,
					  val & ~0x40);

	/* If diode type status reports an error, try to fix it */
	val = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL_STS);
	if (val < 0)
		return val;
	model = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL);
	if (model < 0)
		return model;
	if (model & val) {
		dev_notice(&client->dev,
			   "Fixing remote diode type misconfiguration (0x%x)\n",
			   val);
		i2c_smbus_write_byte_data(client, LM95234_REG_REM_MODEL,
					  model & ~val);
	}
	return 0;
}

__attribute__((used)) static int lm95234_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct lm95234_data *data;
	struct device *hwmon_dev;
	int err;

	data = devm_kzalloc(dev, sizeof(struct lm95234_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the LM95234 chip */
	err = lm95234_init_client(client);
	if (err < 0)
		return err;

	data->groups[0] = &lm95234_common_group;
	if (id->driver_data == lm95234)
		data->groups[1] = &lm95234_group;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


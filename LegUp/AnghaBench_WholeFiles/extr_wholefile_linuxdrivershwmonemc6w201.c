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
struct emc6w201_data {int valid; int** in; int** temp; int** fan; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; int nr; } ;

/* Variables and functions */
 void* DIV_ROUND_CLOSEST (unsigned int,unsigned long) ; 
 int EMC6W201_REG_COMPANY ; 
 int EMC6W201_REG_CONFIG ; 
 int EMC6W201_REG_FAN (int) ; 
 int EMC6W201_REG_FAN_MIN (int) ; 
 int EMC6W201_REG_IN (int) ; 
 int EMC6W201_REG_IN_HIGH (int) ; 
 int EMC6W201_REG_IN_LOW (int) ; 
 int EMC6W201_REG_TEMP (int) ; 
 int EMC6W201_REG_TEMP_HIGH (int) ; 
 int EMC6W201_REG_TEMP_LOW (int) ; 
 int EMC6W201_REG_VERSTEP ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 void* clamp_val (unsigned long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct emc6w201_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct emc6w201_data*,int /*<<< orphan*/ ) ; 
 struct emc6w201_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emc6w201_groups ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 size_t input ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 scalar_t__ likely (int) ; 
 size_t max ; 
 size_t min ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned int* nominal_mv ; 
 int sprintf (char*,char*,unsigned int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static u16 emc6w201_read16(struct i2c_client *client, u8 reg)
{
	int lsb, msb;

	lsb = i2c_smbus_read_byte_data(client, reg);
	msb = i2c_smbus_read_byte_data(client, reg + 1);
	if (unlikely(lsb < 0 || msb < 0)) {
		dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
			16, "read", reg);
		return 0xFFFF;	/* Arbitrary value */
	}

	return (msb << 8) | lsb;
}

__attribute__((used)) static int emc6w201_write16(struct i2c_client *client, u8 reg, u16 val)
{
	int err;

	err = i2c_smbus_write_byte_data(client, reg, val & 0xff);
	if (likely(!err))
		err = i2c_smbus_write_byte_data(client, reg + 1, val >> 8);
	if (unlikely(err < 0))
		dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
			16, "write", reg);

	return err;
}

__attribute__((used)) static u8 emc6w201_read8(struct i2c_client *client, u8 reg)
{
	int val;

	val = i2c_smbus_read_byte_data(client, reg);
	if (unlikely(val < 0)) {
		dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
			8, "read", reg);
		return 0x00;	/* Arbitrary value */
	}

	return val;
}

__attribute__((used)) static int emc6w201_write8(struct i2c_client *client, u8 reg, u8 val)
{
	int err;

	err = i2c_smbus_write_byte_data(client, reg, val);
	if (unlikely(err < 0))
		dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
			8, "write", reg);

	return err;
}

__attribute__((used)) static struct emc6w201_data *emc6w201_update_device(struct device *dev)
{
	struct emc6w201_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		for (nr = 0; nr < 6; nr++) {
			data->in[input][nr] =
				emc6w201_read8(client,
						EMC6W201_REG_IN(nr));
			data->in[min][nr] =
				emc6w201_read8(client,
						EMC6W201_REG_IN_LOW(nr));
			data->in[max][nr] =
				emc6w201_read8(client,
						EMC6W201_REG_IN_HIGH(nr));
		}

		for (nr = 0; nr < 6; nr++) {
			data->temp[input][nr] =
				emc6w201_read8(client,
						EMC6W201_REG_TEMP(nr));
			data->temp[min][nr] =
				emc6w201_read8(client,
						EMC6W201_REG_TEMP_LOW(nr));
			data->temp[max][nr] =
				emc6w201_read8(client,
						EMC6W201_REG_TEMP_HIGH(nr));
		}

		for (nr = 0; nr < 5; nr++) {
			data->fan[input][nr] =
				emc6w201_read16(client,
						EMC6W201_REG_FAN(nr));
			data->fan[min][nr] =
				emc6w201_read16(client,
						EMC6W201_REG_FAN_MIN(nr));
		}

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *devattr,
	char *buf)
{
	struct emc6w201_data *data = emc6w201_update_device(dev);
	int sf = to_sensor_dev_attr_2(devattr)->index;
	int nr = to_sensor_dev_attr_2(devattr)->nr;

	return sprintf(buf, "%u\n",
		       (unsigned)data->in[sf][nr] * nominal_mv[nr] / 0xC0);
}

__attribute__((used)) static ssize_t set_in(struct device *dev, struct device_attribute *devattr,
		      const char *buf, size_t count)
{
	struct emc6w201_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int sf = to_sensor_dev_attr_2(devattr)->index;
	int nr = to_sensor_dev_attr_2(devattr)->nr;
	int err;
	long val;
	u8 reg;

	err = kstrtol(buf, 10, &val);
	if (err < 0)
		return err;

	val = clamp_val(val, 0, 255 * nominal_mv[nr] / 192);
	val = DIV_ROUND_CLOSEST(val * 192, nominal_mv[nr]);
	reg = (sf == min) ? EMC6W201_REG_IN_LOW(nr)
			  : EMC6W201_REG_IN_HIGH(nr);

	mutex_lock(&data->update_lock);
	data->in[sf][nr] = val;
	err = emc6w201_write8(client, reg, data->in[sf][nr]);
	mutex_unlock(&data->update_lock);

	return err < 0 ? err : count;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
	char *buf)
{
	struct emc6w201_data *data = emc6w201_update_device(dev);
	int sf = to_sensor_dev_attr_2(devattr)->index;
	int nr = to_sensor_dev_attr_2(devattr)->nr;

	return sprintf(buf, "%d\n", (int)data->temp[sf][nr] * 1000);
}

__attribute__((used)) static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
			const char *buf, size_t count)
{
	struct emc6w201_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int sf = to_sensor_dev_attr_2(devattr)->index;
	int nr = to_sensor_dev_attr_2(devattr)->nr;
	int err;
	long val;
	u8 reg;

	err = kstrtol(buf, 10, &val);
	if (err < 0)
		return err;

	val = clamp_val(val, -127000, 127000);
	val = DIV_ROUND_CLOSEST(val, 1000);
	reg = (sf == min) ? EMC6W201_REG_TEMP_LOW(nr)
			  : EMC6W201_REG_TEMP_HIGH(nr);

	mutex_lock(&data->update_lock);
	data->temp[sf][nr] = val;
	err = emc6w201_write8(client, reg, data->temp[sf][nr]);
	mutex_unlock(&data->update_lock);

	return err < 0 ? err : count;
}

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
	char *buf)
{
	struct emc6w201_data *data = emc6w201_update_device(dev);
	int sf = to_sensor_dev_attr_2(devattr)->index;
	int nr = to_sensor_dev_attr_2(devattr)->nr;
	unsigned rpm;

	if (data->fan[sf][nr] == 0 || data->fan[sf][nr] == 0xFFFF)
		rpm = 0;
	else
		rpm = 5400000U / data->fan[sf][nr];

	return sprintf(buf, "%u\n", rpm);
}

__attribute__((used)) static ssize_t set_fan(struct device *dev, struct device_attribute *devattr,
		       const char *buf, size_t count)
{
	struct emc6w201_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int sf = to_sensor_dev_attr_2(devattr)->index;
	int nr = to_sensor_dev_attr_2(devattr)->nr;
	int err;
	unsigned long val;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	if (val == 0) {
		val = 0xFFFF;
	} else {
		val = DIV_ROUND_CLOSEST(5400000U, val);
		val = clamp_val(val, 0, 0xFFFE);
	}

	mutex_lock(&data->update_lock);
	data->fan[sf][nr] = val;
	err = emc6w201_write16(client, EMC6W201_REG_FAN_MIN(nr),
			       data->fan[sf][nr]);
	mutex_unlock(&data->update_lock);

	return err < 0 ? err : count;
}

__attribute__((used)) static int emc6w201_detect(struct i2c_client *client,
			   struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int company, verstep, config;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* Identification */
	company = i2c_smbus_read_byte_data(client, EMC6W201_REG_COMPANY);
	if (company != 0x5C)
		return -ENODEV;
	verstep = i2c_smbus_read_byte_data(client, EMC6W201_REG_VERSTEP);
	if (verstep < 0 || (verstep & 0xF0) != 0xB0)
		return -ENODEV;
	if ((verstep & 0x0F) > 2) {
		dev_dbg(&client->dev, "Unknown EMC6W201 stepping %d\n",
			verstep & 0x0F);
		return -ENODEV;
	}

	/* Check configuration */
	config = i2c_smbus_read_byte_data(client, EMC6W201_REG_CONFIG);
	if (config < 0 || (config & 0xF4) != 0x04)
		return -ENODEV;
	if (!(config & 0x01)) {
		dev_err(&client->dev, "Monitoring not enabled\n");
		return -ENODEV;
	}

	strlcpy(info->type, "emc6w201", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int emc6w201_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct emc6w201_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(dev, sizeof(struct emc6w201_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   emc6w201_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


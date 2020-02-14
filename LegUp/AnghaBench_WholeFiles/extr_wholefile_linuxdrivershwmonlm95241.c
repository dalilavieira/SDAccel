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
typedef  int umode_t ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct lm95241_data {long interval; int valid; int* temp; int status; int config; int model; int trutherm; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
typedef  int s16 ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int BIT (int) ; 
 int CFG_CR0076 ; 
 int CFG_CR0182 ; 
 int CFG_CR1000 ; 
 int CFG_CR2700 ; 
 int CFG_CRMASK ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
#define  LM95231_CHIP_ID 137 
#define  LM95241_CHIP_ID 136 
 int /*<<< orphan*/  LM95241_REG_RW_CONFIG ; 
 int /*<<< orphan*/  LM95241_REG_RW_REMOTE_MODEL ; 
 int /*<<< orphan*/  LM95241_REG_RW_REM_FILTER ; 
 int /*<<< orphan*/  LM95241_REG_RW_TRUTHERM ; 
 int /*<<< orphan*/  LM95241_REG_R_CHIP_ID ; 
 int /*<<< orphan*/  LM95241_REG_R_MAN_ID ; 
 int /*<<< orphan*/  LM95241_REG_R_STATUS ; 
 int NATSEMI_MAN_ID ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int R1DF_MASK ; 
 int R1DM ; 
 int R1FE_MASK ; 
 int R1MS_MASK ; 
 int R2DF_MASK ; 
 int R2DM ; 
 int R2FE_MASK ; 
 int R2MS_MASK ; 
 int S_IRUGO ; 
 int S_IWUSR ; 
 int TT1_SHIFT ; 
 int TT2_SHIFT ; 
 int TT_MASK ; 
 int TT_OFF ; 
 int TT_ON ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct lm95241_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct lm95241_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct lm95241_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
#define  hwmon_chip 135 
#define  hwmon_chip_update_interval 134 
#define  hwmon_temp 133 
#define  hwmon_temp_fault 132 
#define  hwmon_temp_input 131 
#define  hwmon_temp_max 130 
#define  hwmon_temp_min 129 
#define  hwmon_temp_type 128 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 void* i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  lm95241_chip_info ; 
 int /*<<< orphan*/ * lm95241_reg_address ; 
 scalar_t__ msecs_to_jiffies (long) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 

__attribute__((used)) static int temp_from_reg_signed(u8 val_h, u8 val_l)
{
	s16 val_hl = (val_h << 8) | val_l;
	return val_hl * 1000 / 256;
}

__attribute__((used)) static int temp_from_reg_unsigned(u8 val_h, u8 val_l)
{
	u16 val_hl = (val_h << 8) | val_l;
	return val_hl * 1000 / 256;
}

__attribute__((used)) static struct lm95241_data *lm95241_update_device(struct device *dev)
{
	struct lm95241_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated
		       + msecs_to_jiffies(data->interval)) ||
	    !data->valid) {
		int i;

		dev_dbg(dev, "Updating lm95241 data.\n");
		for (i = 0; i < ARRAY_SIZE(lm95241_reg_address); i++)
			data->temp[i]
			  = i2c_smbus_read_byte_data(client,
						     lm95241_reg_address[i]);

		data->status = i2c_smbus_read_byte_data(client,
							LM95241_REG_R_STATUS);
		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static int lm95241_read_chip(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct lm95241_data *data = dev_get_drvdata(dev);

	switch (attr) {
	case hwmon_chip_update_interval:
		*val = data->interval;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95241_read_temp(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct lm95241_data *data = lm95241_update_device(dev);

	switch (attr) {
	case hwmon_temp_input:
		if (!channel || (data->config & BIT(channel - 1)))
			*val = temp_from_reg_signed(data->temp[channel * 2],
						data->temp[channel * 2 + 1]);
		else
			*val = temp_from_reg_unsigned(data->temp[channel * 2],
						data->temp[channel * 2 + 1]);
		return 0;
	case hwmon_temp_min:
		if (channel == 1)
			*val = (data->config & R1DF_MASK) ? -128000 : 0;
		else
			*val = (data->config & R2DF_MASK) ? -128000 : 0;
		return 0;
	case hwmon_temp_max:
		if (channel == 1)
			*val = (data->config & R1DF_MASK) ? 127875 : 255875;
		else
			*val = (data->config & R2DF_MASK) ? 127875 : 255875;
		return 0;
	case hwmon_temp_type:
		if (channel == 1)
			*val = (data->model & R1MS_MASK) ? 1 : 2;
		else
			*val = (data->model & R2MS_MASK) ? 1 : 2;
		return 0;
	case hwmon_temp_fault:
		if (channel == 1)
			*val = !!(data->status & R1DM);
		else
			*val = !!(data->status & R2DM);
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95241_read(struct device *dev, enum hwmon_sensor_types type,
			u32 attr, int channel, long *val)
{
	switch (type) {
	case hwmon_chip:
		return lm95241_read_chip(dev, attr, channel, val);
	case hwmon_temp:
		return lm95241_read_temp(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95241_write_chip(struct device *dev, u32 attr, int channel,
			      long val)
{
	struct lm95241_data *data = dev_get_drvdata(dev);
	int convrate;
	u8 config;
	int ret;

	mutex_lock(&data->update_lock);

	switch (attr) {
	case hwmon_chip_update_interval:
		config = data->config & ~CFG_CRMASK;
		if (val < 130) {
			convrate = 76;
			config |= CFG_CR0076;
		} else if (val < 590) {
			convrate = 182;
			config |= CFG_CR0182;
		} else if (val < 1850) {
			convrate = 1000;
			config |= CFG_CR1000;
		} else {
			convrate = 2700;
			config |= CFG_CR2700;
		}
		data->interval = convrate;
		data->config = config;
		ret = i2c_smbus_write_byte_data(data->client,
						LM95241_REG_RW_CONFIG, config);
		break;
	default:
		ret = -EOPNOTSUPP;
		break;
	}
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static int lm95241_write_temp(struct device *dev, u32 attr, int channel,
			      long val)
{
	struct lm95241_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int ret;

	mutex_lock(&data->update_lock);

	switch (attr) {
	case hwmon_temp_min:
		if (channel == 1) {
			if (val < 0)
				data->config |= R1DF_MASK;
			else
				data->config &= ~R1DF_MASK;
		} else {
			if (val < 0)
				data->config |= R2DF_MASK;
			else
				data->config &= ~R2DF_MASK;
		}
		data->valid = 0;
		ret = i2c_smbus_write_byte_data(client, LM95241_REG_RW_CONFIG,
						data->config);
		break;
	case hwmon_temp_max:
		if (channel == 1) {
			if (val <= 127875)
				data->config |= R1DF_MASK;
			else
				data->config &= ~R1DF_MASK;
		} else {
			if (val <= 127875)
				data->config |= R2DF_MASK;
			else
				data->config &= ~R2DF_MASK;
		}
		data->valid = 0;
		ret = i2c_smbus_write_byte_data(client, LM95241_REG_RW_CONFIG,
						data->config);
		break;
	case hwmon_temp_type:
		if (val != 1 && val != 2) {
			ret = -EINVAL;
			break;
		}
		if (channel == 1) {
			data->trutherm &= ~(TT_MASK << TT1_SHIFT);
			if (val == 1) {
				data->model |= R1MS_MASK;
				data->trutherm |= (TT_ON << TT1_SHIFT);
			} else {
				data->model &= ~R1MS_MASK;
				data->trutherm |= (TT_OFF << TT1_SHIFT);
			}
		} else {
			data->trutherm &= ~(TT_MASK << TT2_SHIFT);
			if (val == 1) {
				data->model |= R2MS_MASK;
				data->trutherm |= (TT_ON << TT2_SHIFT);
			} else {
				data->model &= ~R2MS_MASK;
				data->trutherm |= (TT_OFF << TT2_SHIFT);
			}
		}
		ret = i2c_smbus_write_byte_data(client,
						LM95241_REG_RW_REMOTE_MODEL,
						data->model);
		if (ret < 0)
			break;
		ret = i2c_smbus_write_byte_data(client, LM95241_REG_RW_TRUTHERM,
						data->trutherm);
		break;
	default:
		ret = -EOPNOTSUPP;
		break;
	}

	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int lm95241_write(struct device *dev, enum hwmon_sensor_types type,
			 u32 attr, int channel, long val)
{
	switch (type) {
	case hwmon_chip:
		return lm95241_write_chip(dev, attr, channel, val);
	case hwmon_temp:
		return lm95241_write_temp(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t lm95241_is_visible(const void *data,
				  enum hwmon_sensor_types type,
				  u32 attr, int channel)
{
	switch (type) {
	case hwmon_chip:
		switch (attr) {
		case hwmon_chip_update_interval:
			return S_IRUGO | S_IWUSR;
		}
		break;
	case hwmon_temp:
		switch (attr) {
		case hwmon_temp_input:
			return S_IRUGO;
		case hwmon_temp_fault:
			return S_IRUGO;
		case hwmon_temp_min:
		case hwmon_temp_max:
		case hwmon_temp_type:
			return S_IRUGO | S_IWUSR;
		}
		break;
	default:
		break;
	}
	return 0;
}

__attribute__((used)) static int lm95241_detect(struct i2c_client *new_client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = new_client->adapter;
	const char *name;
	int mfg_id, chip_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	mfg_id = i2c_smbus_read_byte_data(new_client, LM95241_REG_R_MAN_ID);
	if (mfg_id != NATSEMI_MAN_ID)
		return -ENODEV;

	chip_id = i2c_smbus_read_byte_data(new_client, LM95241_REG_R_CHIP_ID);
	switch (chip_id) {
	case LM95231_CHIP_ID:
		name = "lm95231";
		break;
	case LM95241_CHIP_ID:
		name = "lm95241";
		break;
	default:
		return -ENODEV;
	}

	/* Fill the i2c board info */
	strlcpy(info->type, name, I2C_NAME_SIZE);
	return 0;
}

__attribute__((used)) static void lm95241_init_client(struct i2c_client *client,
				struct lm95241_data *data)
{
	data->interval = 1000;
	data->config = CFG_CR1000;
	data->trutherm = (TT_OFF << TT1_SHIFT) | (TT_OFF << TT2_SHIFT);

	i2c_smbus_write_byte_data(client, LM95241_REG_RW_CONFIG, data->config);
	i2c_smbus_write_byte_data(client, LM95241_REG_RW_REM_FILTER,
				  R1FE_MASK | R2FE_MASK);
	i2c_smbus_write_byte_data(client, LM95241_REG_RW_TRUTHERM,
				  data->trutherm);
	i2c_smbus_write_byte_data(client, LM95241_REG_RW_REMOTE_MODEL,
				  data->model);
}

__attribute__((used)) static int lm95241_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct lm95241_data *data;
	struct device *hwmon_dev;

	data = devm_kzalloc(dev, sizeof(struct lm95241_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the LM95241 chip */
	lm95241_init_client(client, data);

	hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
							   data,
							   &lm95241_chip_info,
							   NULL);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


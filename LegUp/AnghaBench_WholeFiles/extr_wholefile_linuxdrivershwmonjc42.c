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
typedef  int /*<<< orphan*/  umode_t ;
typedef  int u32 ;
typedef  int u16 ;
struct jc42_data {int valid; int* temp; size_t config; int extended; int orig_config; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct jc42_chips {int manid; int devid_mask; int devid; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
typedef  int s16 ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int ARRAY_SIZE (struct jc42_chips*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 struct jc42_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (struct jc42_data*) ; 
 int JC42_ALARM_CRIT_BIT ; 
 int JC42_ALARM_MAX_BIT ; 
 int JC42_ALARM_MIN_BIT ; 
 int JC42_CAP_RANGE ; 
 unsigned int JC42_CFG_EVENT_LOCK ; 
 size_t JC42_CFG_HYST_MASK ; 
 size_t JC42_CFG_HYST_SHIFT ; 
 int JC42_CFG_SHUTDOWN ; 
 unsigned int JC42_CFG_TCRIT_LOCK ; 
 int /*<<< orphan*/  JC42_REG_CAP ; 
 int /*<<< orphan*/  JC42_REG_CONFIG ; 
 int /*<<< orphan*/  JC42_REG_DEVICEID ; 
 int /*<<< orphan*/  JC42_REG_MANID ; 
 int /*<<< orphan*/  JC42_REG_SMBUS ; 
 int /*<<< orphan*/  JC42_TEMP_MAX ; 
 int /*<<< orphan*/  JC42_TEMP_MIN ; 
 int /*<<< orphan*/  JC42_TEMP_MIN_EXTENDED ; 
 int PTR_ERR (struct jc42_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int SMBUS_STMOUT ; 
 int /*<<< orphan*/  S_IRUGO ; 
 int /*<<< orphan*/  S_IWUSR ; 
 void* clamp_val (long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct jc42_data* dev_get_drvdata (struct device*) ; 
 scalar_t__ device_property_read_bool (struct device*,char*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct jc42_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct jc42_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
#define  hwmon_temp_crit 136 
#define  hwmon_temp_crit_alarm 135 
#define  hwmon_temp_crit_hyst 134 
#define  hwmon_temp_input 133 
#define  hwmon_temp_max 132 
#define  hwmon_temp_max_alarm 131 
#define  hwmon_temp_max_hyst 130 
#define  hwmon_temp_min 129 
#define  hwmon_temp_min_alarm 128 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 struct jc42_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct jc42_data*) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  jc42_chip_info ; 
 struct jc42_chips* jc42_chips ; 
 int* jc42_hysteresis ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 size_t t_crit ; 
 size_t t_input ; 
 size_t t_max ; 
 size_t t_min ; 
 int t_num_temp ; 
 int /*<<< orphan*/ * temp_regs ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 

__attribute__((used)) static u16 jc42_temp_to_reg(long temp, bool extended)
{
	int ntemp = clamp_val(temp,
			      extended ? JC42_TEMP_MIN_EXTENDED :
			      JC42_TEMP_MIN, JC42_TEMP_MAX);

	/* convert from 0.001 to 0.0625 resolution */
	return (ntemp * 2 / 125) & 0x1fff;
}

__attribute__((used)) static int jc42_temp_from_reg(s16 reg)
{
	reg = sign_extend32(reg, 12);

	/* convert from 0.0625 to 0.001 resolution */
	return reg * 125 / 2;
}

__attribute__((used)) static struct jc42_data *jc42_update_device(struct device *dev)
{
	struct jc42_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct jc42_data *ret = data;
	int i, val;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		for (i = 0; i < t_num_temp; i++) {
			val = i2c_smbus_read_word_swapped(client, temp_regs[i]);
			if (val < 0) {
				ret = ERR_PTR(val);
				goto abort;
			}
			data->temp[i] = val;
		}
		data->last_updated = jiffies;
		data->valid = true;
	}
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static int jc42_read(struct device *dev, enum hwmon_sensor_types type,
		     u32 attr, int channel, long *val)
{
	struct jc42_data *data = jc42_update_device(dev);
	int temp, hyst;

	if (IS_ERR(data))
		return PTR_ERR(data);

	switch (attr) {
	case hwmon_temp_input:
		*val = jc42_temp_from_reg(data->temp[t_input]);
		return 0;
	case hwmon_temp_min:
		*val = jc42_temp_from_reg(data->temp[t_min]);
		return 0;
	case hwmon_temp_max:
		*val = jc42_temp_from_reg(data->temp[t_max]);
		return 0;
	case hwmon_temp_crit:
		*val = jc42_temp_from_reg(data->temp[t_crit]);
		return 0;
	case hwmon_temp_max_hyst:
		temp = jc42_temp_from_reg(data->temp[t_max]);
		hyst = jc42_hysteresis[(data->config & JC42_CFG_HYST_MASK)
						>> JC42_CFG_HYST_SHIFT];
		*val = temp - hyst;
		return 0;
	case hwmon_temp_crit_hyst:
		temp = jc42_temp_from_reg(data->temp[t_crit]);
		hyst = jc42_hysteresis[(data->config & JC42_CFG_HYST_MASK)
						>> JC42_CFG_HYST_SHIFT];
		*val = temp - hyst;
		return 0;
	case hwmon_temp_min_alarm:
		*val = (data->temp[t_input] >> JC42_ALARM_MIN_BIT) & 1;
		return 0;
	case hwmon_temp_max_alarm:
		*val = (data->temp[t_input] >> JC42_ALARM_MAX_BIT) & 1;
		return 0;
	case hwmon_temp_crit_alarm:
		*val = (data->temp[t_input] >> JC42_ALARM_CRIT_BIT) & 1;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int jc42_write(struct device *dev, enum hwmon_sensor_types type,
		      u32 attr, int channel, long val)
{
	struct jc42_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int diff, hyst;
	int ret;

	mutex_lock(&data->update_lock);

	switch (attr) {
	case hwmon_temp_min:
		data->temp[t_min] = jc42_temp_to_reg(val, data->extended);
		ret = i2c_smbus_write_word_swapped(client, temp_regs[t_min],
						   data->temp[t_min]);
		break;
	case hwmon_temp_max:
		data->temp[t_max] = jc42_temp_to_reg(val, data->extended);
		ret = i2c_smbus_write_word_swapped(client, temp_regs[t_max],
						   data->temp[t_max]);
		break;
	case hwmon_temp_crit:
		data->temp[t_crit] = jc42_temp_to_reg(val, data->extended);
		ret = i2c_smbus_write_word_swapped(client, temp_regs[t_crit],
						   data->temp[t_crit]);
		break;
	case hwmon_temp_crit_hyst:
		/*
		 * JC42.4 compliant chips only support four hysteresis values.
		 * Pick best choice and go from there.
		 */
		val = clamp_val(val, (data->extended ? JC42_TEMP_MIN_EXTENDED
						     : JC42_TEMP_MIN) - 6000,
				JC42_TEMP_MAX);
		diff = jc42_temp_from_reg(data->temp[t_crit]) - val;
		hyst = 0;
		if (diff > 0) {
			if (diff < 2250)
				hyst = 1;	/* 1.5 degrees C */
			else if (diff < 4500)
				hyst = 2;	/* 3.0 degrees C */
			else
				hyst = 3;	/* 6.0 degrees C */
		}
		data->config = (data->config & ~JC42_CFG_HYST_MASK) |
				(hyst << JC42_CFG_HYST_SHIFT);
		ret = i2c_smbus_write_word_swapped(data->client,
						   JC42_REG_CONFIG,
						   data->config);
		break;
	default:
		ret = -EOPNOTSUPP;
		break;
	}

	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static umode_t jc42_is_visible(const void *_data, enum hwmon_sensor_types type,
			       u32 attr, int channel)
{
	const struct jc42_data *data = _data;
	unsigned int config = data->config;
	umode_t mode = S_IRUGO;

	switch (attr) {
	case hwmon_temp_min:
	case hwmon_temp_max:
		if (!(config & JC42_CFG_EVENT_LOCK))
			mode |= S_IWUSR;
		break;
	case hwmon_temp_crit:
		if (!(config & JC42_CFG_TCRIT_LOCK))
			mode |= S_IWUSR;
		break;
	case hwmon_temp_crit_hyst:
		if (!(config & (JC42_CFG_EVENT_LOCK | JC42_CFG_TCRIT_LOCK)))
			mode |= S_IWUSR;
		break;
	case hwmon_temp_input:
	case hwmon_temp_max_hyst:
	case hwmon_temp_min_alarm:
	case hwmon_temp_max_alarm:
	case hwmon_temp_crit_alarm:
		break;
	default:
		mode = 0;
		break;
	}
	return mode;
}

__attribute__((used)) static int jc42_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int i, config, cap, manid, devid;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	cap = i2c_smbus_read_word_swapped(client, JC42_REG_CAP);
	config = i2c_smbus_read_word_swapped(client, JC42_REG_CONFIG);
	manid = i2c_smbus_read_word_swapped(client, JC42_REG_MANID);
	devid = i2c_smbus_read_word_swapped(client, JC42_REG_DEVICEID);

	if (cap < 0 || config < 0 || manid < 0 || devid < 0)
		return -ENODEV;

	if ((cap & 0xff00) || (config & 0xf800))
		return -ENODEV;

	for (i = 0; i < ARRAY_SIZE(jc42_chips); i++) {
		struct jc42_chips *chip = &jc42_chips[i];
		if (manid == chip->manid &&
		    (devid & chip->devid_mask) == chip->devid) {
			strlcpy(info->type, "jc42", I2C_NAME_SIZE);
			return 0;
		}
	}
	return -ENODEV;
}

__attribute__((used)) static int jc42_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct jc42_data *data;
	int config, cap;

	data = devm_kzalloc(dev, sizeof(struct jc42_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	cap = i2c_smbus_read_word_swapped(client, JC42_REG_CAP);
	if (cap < 0)
		return cap;

	data->extended = !!(cap & JC42_CAP_RANGE);

	if (device_property_read_bool(dev, "smbus-timeout-disable")) {
		int smbus;

		/*
		 * Not all chips support this register, but from a
		 * quick read of various datasheets no chip appears
		 * incompatible with the below attempt to disable
		 * the timeout. And the whole thing is opt-in...
		 */
		smbus = i2c_smbus_read_word_swapped(client, JC42_REG_SMBUS);
		if (smbus < 0)
			return smbus;
		i2c_smbus_write_word_swapped(client, JC42_REG_SMBUS,
					     smbus | SMBUS_STMOUT);
	}

	config = i2c_smbus_read_word_swapped(client, JC42_REG_CONFIG);
	if (config < 0)
		return config;

	data->orig_config = config;
	if (config & JC42_CFG_SHUTDOWN) {
		config &= ~JC42_CFG_SHUTDOWN;
		i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG, config);
	}
	data->config = config;

	hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
							 data, &jc42_chip_info,
							 NULL);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

__attribute__((used)) static int jc42_remove(struct i2c_client *client)
{
	struct jc42_data *data = i2c_get_clientdata(client);

	/* Restore original configuration except hysteresis */
	if ((data->config & ~JC42_CFG_HYST_MASK) !=
	    (data->orig_config & ~JC42_CFG_HYST_MASK)) {
		int config;

		config = (data->orig_config & ~JC42_CFG_HYST_MASK)
		  | (data->config & JC42_CFG_HYST_MASK);
		i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG, config);
	}
	return 0;
}


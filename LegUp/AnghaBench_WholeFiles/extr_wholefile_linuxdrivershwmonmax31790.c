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
struct max31790_data {int valid; int fault_status; int* tach; int* fan_config; int* pwm; int* target_count; int* fan_dynamics; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 struct max31790_data* ERR_PTR (int) ; 
 int FAN_RPM_MAX ; 
 int FAN_RPM_MIN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 scalar_t__ IS_ERR (struct max31790_data*) ; 
 int MAX31790_FAN_CFG_RPM_MODE ; 
 int MAX31790_FAN_CFG_TACH_INPUT ; 
 int MAX31790_FAN_CFG_TACH_INPUT_EN ; 
 int MAX31790_FAN_DYN_SR_MASK ; 
 int MAX31790_FAN_DYN_SR_SHIFT ; 
 int /*<<< orphan*/  MAX31790_REG_FAN_CONFIG (int) ; 
 int /*<<< orphan*/  MAX31790_REG_FAN_DYNAMICS (int) ; 
 int /*<<< orphan*/  MAX31790_REG_FAN_FAULT_STATUS1 ; 
 int /*<<< orphan*/  MAX31790_REG_FAN_FAULT_STATUS2 ; 
 int /*<<< orphan*/  MAX31790_REG_PWMOUT (int) ; 
 int /*<<< orphan*/  MAX31790_REG_TACH_COUNT (int) ; 
 int /*<<< orphan*/  MAX31790_REG_TARGET_COUNT (int) ; 
 int NR_CHANNEL ; 
 int PTR_ERR (struct max31790_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int RPM_FROM_REG (int,int) ; 
 int RPM_TO_REG (long,int) ; 
 size_t SR_FROM_REG (int) ; 
 int S_IRUGO ; 
 int S_IWUSR ; 
 void* clamp_val (int,int,int) ; 
 struct max31790_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct max31790_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct max31790_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
#define  hwmon_fan 134 
#define  hwmon_fan_fault 133 
#define  hwmon_fan_input 132 
#define  hwmon_fan_target 131 
#define  hwmon_pwm 130 
#define  hwmon_pwm_enable 129 
#define  hwmon_pwm_input 128 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,long) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  max31790_chip_info ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* tach_period ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 

__attribute__((used)) static struct max31790_data *max31790_update_device(struct device *dev)
{
	struct max31790_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct max31790_data *ret = data;
	int i;
	int rv;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		rv = i2c_smbus_read_byte_data(client,
				MAX31790_REG_FAN_FAULT_STATUS1);
		if (rv < 0)
			goto abort;
		data->fault_status = rv & 0x3F;

		rv = i2c_smbus_read_byte_data(client,
				MAX31790_REG_FAN_FAULT_STATUS2);
		if (rv < 0)
			goto abort;
		data->fault_status |= (rv & 0x3F) << 6;

		for (i = 0; i < NR_CHANNEL; i++) {
			rv = i2c_smbus_read_word_swapped(client,
					MAX31790_REG_TACH_COUNT(i));
			if (rv < 0)
				goto abort;
			data->tach[i] = rv;

			if (data->fan_config[i]
			    & MAX31790_FAN_CFG_TACH_INPUT) {
				rv = i2c_smbus_read_word_swapped(client,
					MAX31790_REG_TACH_COUNT(NR_CHANNEL
								+ i));
				if (rv < 0)
					goto abort;
				data->tach[NR_CHANNEL + i] = rv;
			} else {
				rv = i2c_smbus_read_word_swapped(client,
						MAX31790_REG_PWMOUT(i));
				if (rv < 0)
					goto abort;
				data->pwm[i] = rv;

				rv = i2c_smbus_read_word_swapped(client,
						MAX31790_REG_TARGET_COUNT(i));
				if (rv < 0)
					goto abort;
				data->target_count[i] = rv;
			}
		}

		data->last_updated = jiffies;
		data->valid = true;
	}
	goto done;

abort:
	data->valid = false;
	ret = ERR_PTR(rv);

done:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static u8 get_tach_period(u8 fan_dynamics)
{
	return tach_period[SR_FROM_REG(fan_dynamics)];
}

__attribute__((used)) static u8 bits_for_tach_period(int rpm)
{
	u8 bits;

	if (rpm < 500)
		bits = 0x0;
	else if (rpm < 1000)
		bits = 0x1;
	else if (rpm < 2000)
		bits = 0x2;
	else if (rpm < 4000)
		bits = 0x3;
	else if (rpm < 8000)
		bits = 0x4;
	else
		bits = 0x5;

	return bits;
}

__attribute__((used)) static int max31790_read_fan(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct max31790_data *data = max31790_update_device(dev);
	int sr, rpm;

	if (IS_ERR(data))
		return PTR_ERR(data);

	switch (attr) {
	case hwmon_fan_input:
		sr = get_tach_period(data->fan_dynamics[channel]);
		rpm = RPM_FROM_REG(data->tach[channel], sr);
		*val = rpm;
		return 0;
	case hwmon_fan_target:
		sr = get_tach_period(data->fan_dynamics[channel]);
		rpm = RPM_FROM_REG(data->target_count[channel], sr);
		*val = rpm;
		return 0;
	case hwmon_fan_fault:
		*val = !!(data->fault_status & (1 << channel));
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int max31790_write_fan(struct device *dev, u32 attr, int channel,
			      long val)
{
	struct max31790_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int target_count;
	int err = 0;
	u8 bits;
	int sr;

	mutex_lock(&data->update_lock);

	switch (attr) {
	case hwmon_fan_target:
		val = clamp_val(val, FAN_RPM_MIN, FAN_RPM_MAX);
		bits = bits_for_tach_period(val);
		data->fan_dynamics[channel] =
			((data->fan_dynamics[channel] &
			  ~MAX31790_FAN_DYN_SR_MASK) |
			 (bits << MAX31790_FAN_DYN_SR_SHIFT));
		err = i2c_smbus_write_byte_data(client,
					MAX31790_REG_FAN_DYNAMICS(channel),
					data->fan_dynamics[channel]);
		if (err < 0)
			break;

		sr = get_tach_period(data->fan_dynamics[channel]);
		target_count = RPM_TO_REG(val, sr);
		target_count = clamp_val(target_count, 0x1, 0x7FF);

		data->target_count[channel] = target_count << 5;

		err = i2c_smbus_write_word_swapped(client,
					MAX31790_REG_TARGET_COUNT(channel),
					data->target_count[channel]);
		break;
	default:
		err = -EOPNOTSUPP;
		break;
	}

	mutex_unlock(&data->update_lock);

	return err;
}

__attribute__((used)) static umode_t max31790_fan_is_visible(const void *_data, u32 attr, int channel)
{
	const struct max31790_data *data = _data;
	u8 fan_config = data->fan_config[channel % NR_CHANNEL];

	switch (attr) {
	case hwmon_fan_input:
	case hwmon_fan_fault:
		if (channel < NR_CHANNEL ||
		    (fan_config & MAX31790_FAN_CFG_TACH_INPUT))
			return S_IRUGO;
		return 0;
	case hwmon_fan_target:
		if (channel < NR_CHANNEL &&
		    !(fan_config & MAX31790_FAN_CFG_TACH_INPUT))
			return S_IRUGO | S_IWUSR;
		return 0;
	default:
		return 0;
	}
}

__attribute__((used)) static int max31790_read_pwm(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct max31790_data *data = max31790_update_device(dev);
	u8 fan_config;

	if (IS_ERR(data))
		return PTR_ERR(data);

	fan_config = data->fan_config[channel];

	switch (attr) {
	case hwmon_pwm_input:
		*val = data->pwm[channel] >> 8;
		return 0;
	case hwmon_pwm_enable:
		if (fan_config & MAX31790_FAN_CFG_RPM_MODE)
			*val = 2;
		else if (fan_config & MAX31790_FAN_CFG_TACH_INPUT_EN)
			*val = 1;
		else
			*val = 0;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int max31790_write_pwm(struct device *dev, u32 attr, int channel,
			      long val)
{
	struct max31790_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 fan_config;
	int err = 0;

	mutex_lock(&data->update_lock);

	switch (attr) {
	case hwmon_pwm_input:
		if (val < 0 || val > 255) {
			err = -EINVAL;
			break;
		}
		data->pwm[channel] = val << 8;
		err = i2c_smbus_write_word_swapped(client,
						   MAX31790_REG_PWMOUT(channel),
						   data->pwm[channel]);
		break;
	case hwmon_pwm_enable:
		fan_config = data->fan_config[channel];
		if (val == 0) {
			fan_config &= ~(MAX31790_FAN_CFG_TACH_INPUT_EN |
					MAX31790_FAN_CFG_RPM_MODE);
		} else if (val == 1) {
			fan_config = (fan_config |
				      MAX31790_FAN_CFG_TACH_INPUT_EN) &
				     ~MAX31790_FAN_CFG_RPM_MODE;
		} else if (val == 2) {
			fan_config |= MAX31790_FAN_CFG_TACH_INPUT_EN |
				      MAX31790_FAN_CFG_RPM_MODE;
		} else {
			err = -EINVAL;
			break;
		}
		data->fan_config[channel] = fan_config;
		err = i2c_smbus_write_byte_data(client,
					MAX31790_REG_FAN_CONFIG(channel),
					fan_config);
		break;
	default:
		err = -EOPNOTSUPP;
		break;
	}

	mutex_unlock(&data->update_lock);

	return err;
}

__attribute__((used)) static umode_t max31790_pwm_is_visible(const void *_data, u32 attr, int channel)
{
	const struct max31790_data *data = _data;
	u8 fan_config = data->fan_config[channel];

	switch (attr) {
	case hwmon_pwm_input:
	case hwmon_pwm_enable:
		if (!(fan_config & MAX31790_FAN_CFG_TACH_INPUT))
			return S_IRUGO | S_IWUSR;
		return 0;
	default:
		return 0;
	}
}

__attribute__((used)) static int max31790_read(struct device *dev, enum hwmon_sensor_types type,
			 u32 attr, int channel, long *val)
{
	switch (type) {
	case hwmon_fan:
		return max31790_read_fan(dev, attr, channel, val);
	case hwmon_pwm:
		return max31790_read_pwm(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int max31790_write(struct device *dev, enum hwmon_sensor_types type,
			  u32 attr, int channel, long val)
{
	switch (type) {
	case hwmon_fan:
		return max31790_write_fan(dev, attr, channel, val);
	case hwmon_pwm:
		return max31790_write_pwm(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t max31790_is_visible(const void *data,
				   enum hwmon_sensor_types type,
				   u32 attr, int channel)
{
	switch (type) {
	case hwmon_fan:
		return max31790_fan_is_visible(data, attr, channel);
	case hwmon_pwm:
		return max31790_pwm_is_visible(data, attr, channel);
	default:
		return 0;
	}
}

__attribute__((used)) static int max31790_init_client(struct i2c_client *client,
				struct max31790_data *data)
{
	int i, rv;

	for (i = 0; i < NR_CHANNEL; i++) {
		rv = i2c_smbus_read_byte_data(client,
				MAX31790_REG_FAN_CONFIG(i));
		if (rv < 0)
			return rv;
		data->fan_config[i] = rv;

		rv = i2c_smbus_read_byte_data(client,
				MAX31790_REG_FAN_DYNAMICS(i));
		if (rv < 0)
			return rv;
		data->fan_dynamics[i] = rv;
	}

	return 0;
}

__attribute__((used)) static int max31790_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct device *dev = &client->dev;
	struct max31790_data *data;
	struct device *hwmon_dev;
	int err;

	if (!i2c_check_functionality(adapter,
			I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	data = devm_kzalloc(dev, sizeof(struct max31790_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/*
	 * Initialize the max31790 chip
	 */
	err = max31790_init_client(client, data);
	if (err)
		return err;

	hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
							 data,
							 &max31790_chip_info,
							 NULL);

	return PTR_ERR_OR_ZERO(hwmon_dev);
}


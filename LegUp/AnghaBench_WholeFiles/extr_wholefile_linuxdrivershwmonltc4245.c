#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
typedef  int u8 ;
typedef  int u32 ;
struct ltc4245_platform_data {int use_extra_gpios; } ;
struct ltc4245_data {int use_extra_gpios; int* gpios; int* vregs; int* cregs; int valid; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_4__ {struct device_node* of_node; } ;
struct i2c_client {int /*<<< orphan*/  name; TYPE_1__ dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  scalar_t__ s32 ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int BIT (int) ; 
 int EAGAIN ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
#define  LTC4245_12VIN 148 
#define  LTC4245_12VOUT 147 
#define  LTC4245_12VSENSE 146 
#define  LTC4245_3VIN 145 
#define  LTC4245_3VOUT 144 
#define  LTC4245_3VSENSE 143 
#define  LTC4245_5VIN 142 
#define  LTC4245_5VOUT 141 
#define  LTC4245_5VSENSE 140 
 size_t LTC4245_FAULT1 ; 
 size_t LTC4245_FAULT2 ; 
 size_t LTC4245_GPIO ; 
#define  LTC4245_GPIOADC 139 
#define  LTC4245_VEEIN 138 
#define  LTC4245_VEEOUT 137 
#define  LTC4245_VEESENSE 136 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  S_IRUGO ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 long abs (unsigned long) ; 
 struct ltc4245_data* dev_get_drvdata (struct device*) ; 
 struct ltc4245_platform_data* dev_get_platdata (TYPE_1__*) ; 
 struct device* devm_hwmon_device_register_with_info (TYPE_1__*,int /*<<< orphan*/ ,struct ltc4245_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct ltc4245_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
#define  hwmon_curr 135 
#define  hwmon_curr_input 134 
#define  hwmon_curr_max_alarm 133 
#define  hwmon_in 132 
#define  hwmon_in_input 131 
#define  hwmon_in_min_alarm 130 
#define  hwmon_power 129 
#define  hwmon_power_input 128 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,size_t,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  ltc4245_chip_info ; 
 int* ltc4245_curr_regs ; 
 int* ltc4245_in_regs ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void ltc4245_update_gpios(struct device *dev)
{
	struct ltc4245_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 gpio_curr, gpio_next, gpio_reg;
	int i;

	/* no extra gpio support, we're basically done */
	if (!data->use_extra_gpios) {
		data->gpios[0] = data->vregs[LTC4245_GPIOADC - 0x10];
		return;
	}

	/*
	 * If the last reading was too long ago, then we mark all old GPIO
	 * readings as stale by setting them to -EAGAIN
	 */
	if (time_after(jiffies, data->last_updated + 5 * HZ)) {
		for (i = 0; i < ARRAY_SIZE(data->gpios); i++)
			data->gpios[i] = -EAGAIN;
	}

	/*
	 * Get the current GPIO pin
	 *
	 * The datasheet calls these GPIO[1-3], but we'll calculate the zero
	 * based array index instead, and call them GPIO[0-2]. This is much
	 * easier to think about.
	 */
	gpio_curr = (data->cregs[LTC4245_GPIO] & 0xc0) >> 6;
	if (gpio_curr > 0)
		gpio_curr -= 1;

	/* Read the GPIO voltage from the GPIOADC register */
	data->gpios[gpio_curr] = data->vregs[LTC4245_GPIOADC - 0x10];

	/* Find the next GPIO pin to read */
	gpio_next = (gpio_curr + 1) % ARRAY_SIZE(data->gpios);

	/*
	 * Calculate the correct setting for the GPIO register so it will
	 * sample the next GPIO pin
	 */
	gpio_reg = (data->cregs[LTC4245_GPIO] & 0x3f) | ((gpio_next + 1) << 6);

	/* Update the GPIO register */
	i2c_smbus_write_byte_data(client, LTC4245_GPIO, gpio_reg);

	/* Update saved data */
	data->cregs[LTC4245_GPIO] = gpio_reg;
}

__attribute__((used)) static struct ltc4245_data *ltc4245_update_device(struct device *dev)
{
	struct ltc4245_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	s32 val;
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {

		/* Read control registers -- 0x00 to 0x07 */
		for (i = 0; i < ARRAY_SIZE(data->cregs); i++) {
			val = i2c_smbus_read_byte_data(client, i);
			if (unlikely(val < 0))
				data->cregs[i] = 0;
			else
				data->cregs[i] = val;
		}

		/* Read voltage registers -- 0x10 to 0x1c */
		for (i = 0; i < ARRAY_SIZE(data->vregs); i++) {
			val = i2c_smbus_read_byte_data(client, i+0x10);
			if (unlikely(val < 0))
				data->vregs[i] = 0;
			else
				data->vregs[i] = val;
		}

		/* Update GPIO readings */
		ltc4245_update_gpios(dev);

		data->last_updated = jiffies;
		data->valid = true;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static int ltc4245_get_voltage(struct device *dev, u8 reg)
{
	struct ltc4245_data *data = ltc4245_update_device(dev);
	const u8 regval = data->vregs[reg - 0x10];
	u32 voltage = 0;

	switch (reg) {
	case LTC4245_12VIN:
	case LTC4245_12VOUT:
		voltage = regval * 55;
		break;
	case LTC4245_5VIN:
	case LTC4245_5VOUT:
		voltage = regval * 22;
		break;
	case LTC4245_3VIN:
	case LTC4245_3VOUT:
		voltage = regval * 15;
		break;
	case LTC4245_VEEIN:
	case LTC4245_VEEOUT:
		voltage = regval * -55;
		break;
	case LTC4245_GPIOADC:
		voltage = regval * 10;
		break;
	default:
		/* If we get here, the developer messed up */
		WARN_ON_ONCE(1);
		break;
	}

	return voltage;
}

__attribute__((used)) static unsigned int ltc4245_get_current(struct device *dev, u8 reg)
{
	struct ltc4245_data *data = ltc4245_update_device(dev);
	const u8 regval = data->vregs[reg - 0x10];
	unsigned int voltage;
	unsigned int curr;

	/*
	 * The strange looking conversions that follow are fixed-point
	 * math, since we cannot do floating point in the kernel.
	 *
	 * Step 1: convert sense register to microVolts
	 * Step 2: convert voltage to milliAmperes
	 *
	 * If you play around with the V=IR equation, you come up with
	 * the following: X uV / Y mOhm == Z mA
	 *
	 * With the resistors that are fractions of a milliOhm, we multiply
	 * the voltage and resistance by 10, to shift the decimal point.
	 * Now we can use the normal division operator again.
	 */

	switch (reg) {
	case LTC4245_12VSENSE:
		voltage = regval * 250; /* voltage in uV */
		curr = voltage / 50; /* sense resistor 50 mOhm */
		break;
	case LTC4245_5VSENSE:
		voltage = regval * 125; /* voltage in uV */
		curr = (voltage * 10) / 35; /* sense resistor 3.5 mOhm */
		break;
	case LTC4245_3VSENSE:
		voltage = regval * 125; /* voltage in uV */
		curr = (voltage * 10) / 25; /* sense resistor 2.5 mOhm */
		break;
	case LTC4245_VEESENSE:
		voltage = regval * 250; /* voltage in uV */
		curr = voltage / 100; /* sense resistor 100 mOhm */
		break;
	default:
		/* If we get here, the developer messed up */
		WARN_ON_ONCE(1);
		curr = 0;
		break;
	}

	return curr;
}

__attribute__((used)) static int ltc4245_read_curr(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct ltc4245_data *data = ltc4245_update_device(dev);

	switch (attr) {
	case hwmon_curr_input:
		*val = ltc4245_get_current(dev, ltc4245_curr_regs[channel]);
		return 0;
	case hwmon_curr_max_alarm:
		*val = !!(data->cregs[LTC4245_FAULT1] & BIT(channel + 4));
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int ltc4245_read_in(struct device *dev, u32 attr, int channel, long *val)
{
	struct ltc4245_data *data = ltc4245_update_device(dev);

	switch (attr) {
	case hwmon_in_input:
		if (channel < 8) {
			*val = ltc4245_get_voltage(dev,
						ltc4245_in_regs[channel]);
		} else {
			int regval = data->gpios[channel - 8];

			if (regval < 0)
				return regval;
			*val = regval * 10;
		}
		return 0;
	case hwmon_in_min_alarm:
		if (channel < 4)
			*val = !!(data->cregs[LTC4245_FAULT1] & BIT(channel));
		else
			*val = !!(data->cregs[LTC4245_FAULT2] &
				  BIT(channel - 4));
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int ltc4245_read_power(struct device *dev, u32 attr, int channel,
			      long *val)
{
	unsigned long curr;
	long voltage;

	switch (attr) {
	case hwmon_power_input:
		(void)ltc4245_update_device(dev);
		curr = ltc4245_get_current(dev, ltc4245_curr_regs[channel]);
		voltage = ltc4245_get_voltage(dev, ltc4245_in_regs[channel]);
		*val = abs(curr * voltage);
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int ltc4245_read(struct device *dev, enum hwmon_sensor_types type,
			u32 attr, int channel, long *val)
{

	switch (type) {
	case hwmon_curr:
		return ltc4245_read_curr(dev, attr, channel, val);
	case hwmon_power:
		return ltc4245_read_power(dev, attr, channel, val);
	case hwmon_in:
		return ltc4245_read_in(dev, attr, channel - 1, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t ltc4245_is_visible(const void *_data,
				  enum hwmon_sensor_types type,
				  u32 attr, int channel)
{
	const struct ltc4245_data *data = _data;

	switch (type) {
	case hwmon_in:
		if (channel == 0)
			return 0;
		switch (attr) {
		case hwmon_in_input:
			if (channel > 9 && !data->use_extra_gpios)
				return 0;
			return S_IRUGO;
		case hwmon_in_min_alarm:
			if (channel > 8)
				return 0;
			return S_IRUGO;
		default:
			return 0;
		}
	case hwmon_curr:
		switch (attr) {
		case hwmon_curr_input:
		case hwmon_curr_max_alarm:
			return S_IRUGO;
		default:
			return 0;
		}
	case hwmon_power:
		switch (attr) {
		case hwmon_power_input:
			return S_IRUGO;
		default:
			return 0;
		}
	default:
		return 0;
	}
}

__attribute__((used)) static bool ltc4245_use_extra_gpios(struct i2c_client *client)
{
	struct ltc4245_platform_data *pdata = dev_get_platdata(&client->dev);
	struct device_node *np = client->dev.of_node;

	/* prefer platform data */
	if (pdata)
		return pdata->use_extra_gpios;

	/* fallback on OF */
	if (of_find_property(np, "ltc4245,use-extra-gpios", NULL))
		return true;

	return false;
}

__attribute__((used)) static int ltc4245_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct ltc4245_data *data;
	struct device *hwmon_dev;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);
	data->use_extra_gpios = ltc4245_use_extra_gpios(client);

	/* Initialize the LTC4245 chip */
	i2c_smbus_write_byte_data(client, LTC4245_FAULT1, 0x00);
	i2c_smbus_write_byte_data(client, LTC4245_FAULT2, 0x00);

	hwmon_dev = devm_hwmon_device_register_with_info(&client->dev,
							 client->name, data,
							 &ltc4245_chip_info,
							 NULL);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


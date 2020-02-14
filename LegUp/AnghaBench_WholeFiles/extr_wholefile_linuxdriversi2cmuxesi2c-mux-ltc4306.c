#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_12__ {int base; int can_sleep; int (* get_direction ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* set_config ) (struct gpio_chip*,unsigned int,unsigned long) ;int /*<<< orphan*/  owner; struct device* parent; scalar_t__ ngpio; int /*<<< orphan*/  label; } ;
struct ltc4306 {struct gpio_desc* regmap; struct chip_desc const* chip; TYPE_5__ gpiochip; } ;
struct i2c_mux_core {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;
struct i2c_client {int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct i2c_adapter {int dummy; } ;
struct gpio_desc {int dummy; } ;
struct gpio_chip {int dummy; } ;
struct device {int dummy; } ;
struct chip_desc {int nchans; scalar_t__ num_gpios; } ;
struct TYPE_11__ {size_t driver_data; } ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 int /*<<< orphan*/  I2C_MUX_LOCKED ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 unsigned int LTC_DOWNSTREAM_ACCL_EN ; 
 unsigned int LTC_GPIO_ALL_INPUT ; 
 unsigned int LTC_REG_CONFIG ; 
 unsigned int LTC_REG_MODE ; 
 unsigned int LTC_REG_SWITCH ; 
 unsigned int LTC_SWITCH_MASK ; 
 unsigned int LTC_UPSTREAM_ACCL_EN ; 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 129 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 128 
 int PTR_ERR (struct gpio_desc*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct chip_desc* chips ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 int device_property_read_bool (TYPE_1__*,char*) ; 
 int devm_gpiochip_add_data (struct device*,TYPE_5__*,struct ltc4306*) ; 
 struct gpio_desc* devm_gpiod_get_optional (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 struct gpio_desc* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct ltc4306* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiod_set_value (struct gpio_desc*,int) ; 
 struct i2c_mux_core* i2c_get_clientdata (struct i2c_client*) ; 
 TYPE_3__* i2c_match_id (int /*<<< orphan*/ ,struct i2c_client*) ; 
 int i2c_mux_add_adapter (struct i2c_mux_core*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct i2c_mux_core* i2c_mux_alloc (struct i2c_adapter*,TYPE_1__*,int,int,int /*<<< orphan*/ ,int (*) (struct i2c_mux_core*,int),int (*) (struct i2c_mux_core*,int)) ; 
 int /*<<< orphan*/  i2c_mux_del_adapters (struct i2c_mux_core*) ; 
 struct ltc4306* i2c_mux_priv (struct i2c_mux_core*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct i2c_mux_core*) ; 
 int /*<<< orphan*/  ltc4306_id ; 
 int /*<<< orphan*/  ltc4306_regmap_config ; 
 struct chip_desc* of_device_get_match_data (TYPE_1__*) ; 
 int pinconf_to_config_param (unsigned long) ; 
 struct device* regmap_get_device (struct gpio_desc*) ; 
 int regmap_read (struct gpio_desc*,unsigned int,unsigned int*) ; 
 int regmap_update_bits (struct gpio_desc*,unsigned int,unsigned int,unsigned int) ; 
 scalar_t__ regmap_write (struct gpio_desc*,unsigned int,unsigned int) ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static bool ltc4306_is_volatile_reg(struct device *dev, unsigned int reg)
{
	return (reg == LTC_REG_CONFIG) ? true : false;
}

__attribute__((used)) static int ltc4306_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct ltc4306 *data = gpiochip_get_data(chip);
	unsigned int val;
	int ret;

	ret = regmap_read(data->regmap, LTC_REG_CONFIG, &val);
	if (ret < 0)
		return ret;

	return !!(val & BIT(1 - offset));
}

__attribute__((used)) static void ltc4306_gpio_set(struct gpio_chip *chip, unsigned int offset,
			     int value)
{
	struct ltc4306 *data = gpiochip_get_data(chip);

	regmap_update_bits(data->regmap, LTC_REG_CONFIG, BIT(5 - offset),
			   value ? BIT(5 - offset) : 0);
}

__attribute__((used)) static int ltc4306_gpio_get_direction(struct gpio_chip *chip,
				      unsigned int offset)
{
	struct ltc4306 *data = gpiochip_get_data(chip);
	unsigned int val;
	int ret;

	ret = regmap_read(data->regmap, LTC_REG_MODE, &val);
	if (ret < 0)
		return ret;

	return !!(val & BIT(7 - offset));
}

__attribute__((used)) static int ltc4306_gpio_direction_input(struct gpio_chip *chip,
					unsigned int offset)
{
	struct ltc4306 *data = gpiochip_get_data(chip);

	return regmap_update_bits(data->regmap, LTC_REG_MODE,
				  BIT(7 - offset), BIT(7 - offset));
}

__attribute__((used)) static int ltc4306_gpio_direction_output(struct gpio_chip *chip,
					 unsigned int offset, int value)
{
	struct ltc4306 *data = gpiochip_get_data(chip);

	ltc4306_gpio_set(chip, offset, value);
	return regmap_update_bits(data->regmap, LTC_REG_MODE,
				  BIT(7 - offset), 0);
}

__attribute__((used)) static int ltc4306_gpio_set_config(struct gpio_chip *chip,
				   unsigned int offset, unsigned long config)
{
	struct ltc4306 *data = gpiochip_get_data(chip);
	unsigned int val;

	switch (pinconf_to_config_param(config)) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		val = 0;
		break;
	case PIN_CONFIG_DRIVE_PUSH_PULL:
		val = BIT(4 - offset);
		break;
	default:
		return -ENOTSUPP;
	}

	return regmap_update_bits(data->regmap, LTC_REG_MODE,
				  BIT(4 - offset), val);
}

__attribute__((used)) static int ltc4306_gpio_init(struct ltc4306 *data)
{
	struct device *dev = regmap_get_device(data->regmap);

	if (!data->chip->num_gpios)
		return 0;

	data->gpiochip.label = dev_name(dev);
	data->gpiochip.base = -1;
	data->gpiochip.ngpio = data->chip->num_gpios;
	data->gpiochip.parent = dev;
	data->gpiochip.can_sleep = true;
	data->gpiochip.get_direction = ltc4306_gpio_get_direction;
	data->gpiochip.direction_input = ltc4306_gpio_direction_input;
	data->gpiochip.direction_output = ltc4306_gpio_direction_output;
	data->gpiochip.get = ltc4306_gpio_get;
	data->gpiochip.set = ltc4306_gpio_set;
	data->gpiochip.set_config = ltc4306_gpio_set_config;
	data->gpiochip.owner = THIS_MODULE;

	/* gpiolib assumes all GPIOs default input */
	regmap_write(data->regmap, LTC_REG_MODE, LTC_GPIO_ALL_INPUT);

	return devm_gpiochip_add_data(dev, &data->gpiochip, data);
}

__attribute__((used)) static int ltc4306_select_mux(struct i2c_mux_core *muxc, u32 chan)
{
	struct ltc4306 *data = i2c_mux_priv(muxc);

	return regmap_update_bits(data->regmap, LTC_REG_SWITCH,
				  LTC_SWITCH_MASK, BIT(7 - chan));
}

__attribute__((used)) static int ltc4306_deselect_mux(struct i2c_mux_core *muxc, u32 chan)
{
	struct ltc4306 *data = i2c_mux_priv(muxc);

	return regmap_update_bits(data->regmap, LTC_REG_SWITCH,
				  LTC_SWITCH_MASK, 0);
}

__attribute__((used)) static int ltc4306_probe(struct i2c_client *client)
{
	struct i2c_adapter *adap = to_i2c_adapter(client->dev.parent);
	const struct chip_desc *chip;
	struct i2c_mux_core *muxc;
	struct ltc4306 *data;
	struct gpio_desc *gpio;
	bool idle_disc;
	unsigned int val = 0;
	int num, ret;

	chip = of_device_get_match_data(&client->dev);

	if (!chip)
		chip = &chips[i2c_match_id(ltc4306_id, client)->driver_data];

	idle_disc = device_property_read_bool(&client->dev,
					      "i2c-mux-idle-disconnect");

	muxc = i2c_mux_alloc(adap, &client->dev,
			     chip->nchans, sizeof(*data),
			     I2C_MUX_LOCKED, ltc4306_select_mux,
			     idle_disc ? ltc4306_deselect_mux : NULL);
	if (!muxc)
		return -ENOMEM;
	data = i2c_mux_priv(muxc);
	data->chip = chip;

	i2c_set_clientdata(client, muxc);

	data->regmap = devm_regmap_init_i2c(client, &ltc4306_regmap_config);
	if (IS_ERR(data->regmap)) {
		ret = PTR_ERR(data->regmap);
		dev_err(&client->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	/* Reset and enable the mux if an enable GPIO is specified. */
	gpio = devm_gpiod_get_optional(&client->dev, "enable", GPIOD_OUT_LOW);
	if (IS_ERR(gpio))
		return PTR_ERR(gpio);

	if (gpio) {
		udelay(1);
		gpiod_set_value(gpio, 1);
	}

	/*
	 * Write the mux register at addr to verify
	 * that the mux is in fact present. This also
	 * initializes the mux to disconnected state.
	 */
	if (regmap_write(data->regmap, LTC_REG_SWITCH, 0) < 0) {
		dev_warn(&client->dev, "probe failed\n");
		return -ENODEV;
	}

	if (device_property_read_bool(&client->dev,
				      "ltc,downstream-accelerators-enable"))
		val |= LTC_DOWNSTREAM_ACCL_EN;

	if (device_property_read_bool(&client->dev,
				      "ltc,upstream-accelerators-enable"))
		val |= LTC_UPSTREAM_ACCL_EN;

	if (regmap_write(data->regmap, LTC_REG_CONFIG, val) < 0)
		return -ENODEV;

	ret = ltc4306_gpio_init(data);
	if (ret < 0)
		return ret;

	/* Now create an adapter for each channel */
	for (num = 0; num < chip->nchans; num++) {
		ret = i2c_mux_add_adapter(muxc, 0, num, 0);
		if (ret) {
			i2c_mux_del_adapters(muxc);
			return ret;
		}
	}

	dev_info(&client->dev,
		 "registered %d multiplexed busses for I2C switch %s\n",
		 num, client->name);

	return 0;
}

__attribute__((used)) static int ltc4306_remove(struct i2c_client *client)
{
	struct i2c_mux_core *muxc = i2c_get_clientdata(client);

	i2c_mux_del_adapters(muxc);

	return 0;
}


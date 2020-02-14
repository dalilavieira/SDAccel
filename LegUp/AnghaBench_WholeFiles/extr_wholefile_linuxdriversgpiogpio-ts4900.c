#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_7__ {char* label; TYPE_2__* parent; int /*<<< orphan*/  ngpio; } ;
struct ts4900_gpio_priv {unsigned int input_bit; TYPE_1__ gpio_chip; int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {TYPE_2__ dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFAULT_PIN_NUMBER ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned int TS4900_GPIO_OE ; 
 unsigned int TS4900_GPIO_OUT ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int devm_gpiochip_add_data (TYPE_2__*,TYPE_1__*,struct ts4900_gpio_priv*) ; 
 struct ts4900_gpio_priv* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct ts4900_gpio_priv* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ts4900_gpio_priv*) ; 
 scalar_t__ of_device_get_match_data (TYPE_2__*) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int) ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 TYPE_1__ template_chip ; 
 int /*<<< orphan*/  ts4900_regmap_config ; 

__attribute__((used)) static int ts4900_gpio_get_direction(struct gpio_chip *chip,
				     unsigned int offset)
{
	struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int reg;

	regmap_read(priv->regmap, offset, &reg);

	return !(reg & TS4900_GPIO_OE);
}

__attribute__((used)) static int ts4900_gpio_direction_input(struct gpio_chip *chip,
				       unsigned int offset)
{
	struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);

	/*
	 * This will clear the output enable bit, the other bits are
	 * dontcare when this is cleared
	 */
	return regmap_write(priv->regmap, offset, 0);
}

__attribute__((used)) static int ts4900_gpio_direction_output(struct gpio_chip *chip,
					unsigned int offset, int value)
{
	struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
	int ret;

	if (value)
		ret = regmap_write(priv->regmap, offset, TS4900_GPIO_OE |
							 TS4900_GPIO_OUT);
	else
		ret = regmap_write(priv->regmap, offset, TS4900_GPIO_OE);

	return ret;
}

__attribute__((used)) static int ts4900_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
	unsigned int reg;

	regmap_read(priv->regmap, offset, &reg);

	return !!(reg & priv->input_bit);
}

__attribute__((used)) static void ts4900_gpio_set(struct gpio_chip *chip, unsigned int offset,
			    int value)
{
	struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);

	if (value)
		regmap_update_bits(priv->regmap, offset, TS4900_GPIO_OUT,
				   TS4900_GPIO_OUT);
	else
		regmap_update_bits(priv->regmap, offset, TS4900_GPIO_OUT, 0);
}

__attribute__((used)) static int ts4900_gpio_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct ts4900_gpio_priv *priv;
	u32 ngpio;
	int ret;

	if (of_property_read_u32(client->dev.of_node, "ngpios", &ngpio))
		ngpio = DEFAULT_PIN_NUMBER;

	priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->gpio_chip = template_chip;
	priv->gpio_chip.label = "ts4900-gpio";
	priv->gpio_chip.ngpio = ngpio;
	priv->gpio_chip.parent = &client->dev;
	priv->input_bit = (uintptr_t)of_device_get_match_data(&client->dev);

	priv->regmap = devm_regmap_init_i2c(client, &ts4900_regmap_config);
	if (IS_ERR(priv->regmap)) {
		ret = PTR_ERR(priv->regmap);
		dev_err(&client->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	ret = devm_gpiochip_add_data(&client->dev, &priv->gpio_chip, priv);
	if (ret < 0) {
		dev_err(&client->dev, "Unable to register gpiochip\n");
		return ret;
	}

	i2c_set_clientdata(client, priv);

	return 0;
}


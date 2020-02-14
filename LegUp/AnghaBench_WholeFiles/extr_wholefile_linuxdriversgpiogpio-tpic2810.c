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
typedef  int u8 ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct tpic2810 {int buffer; TYPE_1__ chip; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  TPIC2810_WS_COMMAND ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct tpic2810* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int gpiochip_add_data (TYPE_1__*,struct tpic2810*) ; 
 struct tpic2810* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (TYPE_1__*) ; 
 struct tpic2810* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tpic2810*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_1__ template_chip ; 
static  void tpic2810_set (struct gpio_chip*,unsigned int,int) ; 

__attribute__((used)) static int tpic2810_get_direction(struct gpio_chip *chip,
				  unsigned offset)
{
	/* This device always output */
	return 0;
}

__attribute__((used)) static int tpic2810_direction_input(struct gpio_chip *chip,
				    unsigned offset)
{
	/* This device is output only */
	return -EINVAL;
}

__attribute__((used)) static int tpic2810_direction_output(struct gpio_chip *chip,
				     unsigned offset, int value)
{
	/* This device always output */
	tpic2810_set(chip, offset, value);
	return 0;
}

__attribute__((used)) static void tpic2810_set_mask_bits(struct gpio_chip *chip, u8 mask, u8 bits)
{
	struct tpic2810 *gpio = gpiochip_get_data(chip);
	u8 buffer;
	int err;

	mutex_lock(&gpio->lock);

	buffer = gpio->buffer & ~mask;
	buffer |= (mask & bits);

	err = i2c_smbus_write_byte_data(gpio->client, TPIC2810_WS_COMMAND,
					buffer);
	if (!err)
		gpio->buffer = buffer;

	mutex_unlock(&gpio->lock);
}

__attribute__((used)) static void tpic2810_set(struct gpio_chip *chip, unsigned offset, int value)
{
	tpic2810_set_mask_bits(chip, BIT(offset), value ? BIT(offset) : 0);
}

__attribute__((used)) static void tpic2810_set_multiple(struct gpio_chip *chip, unsigned long *mask,
				  unsigned long *bits)
{
	tpic2810_set_mask_bits(chip, *mask, *bits);
}

__attribute__((used)) static int tpic2810_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct tpic2810 *gpio;
	int ret;

	gpio = devm_kzalloc(&client->dev, sizeof(*gpio), GFP_KERNEL);
	if (!gpio)
		return -ENOMEM;

	i2c_set_clientdata(client, gpio);

	gpio->chip = template_chip;
	gpio->chip.parent = &client->dev;

	gpio->client = client;

	mutex_init(&gpio->lock);

	ret = gpiochip_add_data(&gpio->chip, gpio);
	if (ret < 0) {
		dev_err(&client->dev, "Unable to register gpiochip\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int tpic2810_remove(struct i2c_client *client)
{
	struct tpic2810 *gpio = i2c_get_clientdata(client);

	gpiochip_remove(&gpio->chip);

	return 0;
}


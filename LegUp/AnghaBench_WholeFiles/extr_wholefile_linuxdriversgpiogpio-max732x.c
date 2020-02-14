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
typedef  unsigned int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct max732x_platform_data {int gpio_base; int (* setup ) (struct i2c_client*,unsigned int,int,int /*<<< orphan*/ ) ;int (* teardown ) (struct i2c_client*,unsigned int,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  context; scalar_t__ irq_base; } ;
struct gpio_chip {int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;void (* set_multiple ) (struct gpio_chip*,unsigned long*,unsigned long*) ;int (* get ) (struct gpio_chip*,unsigned int) ;int can_sleep; unsigned int base; int ngpio; struct device* parent; int /*<<< orphan*/  owner; int /*<<< orphan*/  label; } ;
struct max732x_chip {unsigned int mask_group_a; unsigned int* reg_out; unsigned int dir_input; unsigned int dir_output; struct i2c_client* client_dummy; struct gpio_chip gpio_chip; int /*<<< orphan*/  lock; struct i2c_client* client_group_a; struct i2c_client* client_group_b; struct i2c_client* client; } ;
struct i2c_device_id {size_t driver_data; } ;
struct device {struct device_node* of_node; } ;
struct i2c_client {int addr; struct device dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  name; scalar_t__ irq; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EACCES ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INT_NONE ; 
#define  PORT_INPUT 130 
#define  PORT_OPENDRAIN 129 
#define  PORT_OUTPUT 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct max732x_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int gpiochip_add_data (struct gpio_chip*,struct max732x_chip*) ; 
 struct max732x_chip* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (struct gpio_chip*) ; 
 struct max732x_chip* i2c_get_clientdata (struct i2c_client*) ; 
 struct i2c_client* i2c_new_dummy (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max732x_chip*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,unsigned int) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int* max732x_features ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct i2c_client*,unsigned int,int,int /*<<< orphan*/ ) ; 
 int stub2 (struct i2c_client*,unsigned int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int max732x_writeb(struct max732x_chip *chip, int group_a, uint8_t val)
{
	struct i2c_client *client;
	int ret;

	client = group_a ? chip->client_group_a : chip->client_group_b;
	ret = i2c_smbus_write_byte(client, val);
	if (ret < 0) {
		dev_err(&client->dev, "failed writing\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int max732x_readb(struct max732x_chip *chip, int group_a, uint8_t *val)
{
	struct i2c_client *client;
	int ret;

	client = group_a ? chip->client_group_a : chip->client_group_b;
	ret = i2c_smbus_read_byte(client);
	if (ret < 0) {
		dev_err(&client->dev, "failed reading\n");
		return ret;
	}

	*val = (uint8_t)ret;
	return 0;
}

__attribute__((used)) static inline int is_group_a(struct max732x_chip *chip, unsigned off)
{
	return (1u << off) & chip->mask_group_a;
}

__attribute__((used)) static int max732x_gpio_get_value(struct gpio_chip *gc, unsigned off)
{
	struct max732x_chip *chip = gpiochip_get_data(gc);
	uint8_t reg_val;
	int ret;

	ret = max732x_readb(chip, is_group_a(chip, off), &reg_val);
	if (ret < 0)
		return ret;

	return !!(reg_val & (1u << (off & 0x7)));
}

__attribute__((used)) static void max732x_gpio_set_mask(struct gpio_chip *gc, unsigned off, int mask,
				  int val)
{
	struct max732x_chip *chip = gpiochip_get_data(gc);
	uint8_t reg_out;
	int ret;

	mutex_lock(&chip->lock);

	reg_out = (off > 7) ? chip->reg_out[1] : chip->reg_out[0];
	reg_out = (reg_out & ~mask) | (val & mask);

	ret = max732x_writeb(chip, is_group_a(chip, off), reg_out);
	if (ret < 0)
		goto out;

	/* update the shadow register then */
	if (off > 7)
		chip->reg_out[1] = reg_out;
	else
		chip->reg_out[0] = reg_out;
out:
	mutex_unlock(&chip->lock);
}

__attribute__((used)) static void max732x_gpio_set_value(struct gpio_chip *gc, unsigned off, int val)
{
	unsigned base = off & ~0x7;
	uint8_t mask = 1u << (off & 0x7);

	max732x_gpio_set_mask(gc, base, mask, val << (off & 0x7));
}

__attribute__((used)) static void max732x_gpio_set_multiple(struct gpio_chip *gc,
				      unsigned long *mask, unsigned long *bits)
{
	unsigned mask_lo = mask[0] & 0xff;
	unsigned mask_hi = (mask[0] >> 8) & 0xff;

	if (mask_lo)
		max732x_gpio_set_mask(gc, 0, mask_lo, bits[0] & 0xff);
	if (mask_hi)
		max732x_gpio_set_mask(gc, 8, mask_hi, (bits[0] >> 8) & 0xff);
}

__attribute__((used)) static int max732x_gpio_direction_input(struct gpio_chip *gc, unsigned off)
{
	struct max732x_chip *chip = gpiochip_get_data(gc);
	unsigned int mask = 1u << off;

	if ((mask & chip->dir_input) == 0) {
		dev_dbg(&chip->client->dev, "%s port %d is output only\n",
			chip->client->name, off);
		return -EACCES;
	}

	/*
	 * Open-drain pins must be set to high impedance (which is
	 * equivalent to output-high) to be turned into an input.
	 */
	if ((mask & chip->dir_output))
		max732x_gpio_set_value(gc, off, 1);

	return 0;
}

__attribute__((used)) static int max732x_gpio_direction_output(struct gpio_chip *gc,
		unsigned off, int val)
{
	struct max732x_chip *chip = gpiochip_get_data(gc);
	unsigned int mask = 1u << off;

	if ((mask & chip->dir_output) == 0) {
		dev_dbg(&chip->client->dev, "%s port %d is input only\n",
			chip->client->name, off);
		return -EACCES;
	}

	max732x_gpio_set_value(gc, off, val);
	return 0;
}

__attribute__((used)) static int max732x_irq_setup(struct max732x_chip *chip,
			     const struct i2c_device_id *id)
{
	struct i2c_client *client = chip->client;
	struct max732x_platform_data *pdata = dev_get_platdata(&client->dev);
	int has_irq = max732x_features[id->driver_data] >> 32;

	if (((pdata && pdata->irq_base) || client->irq) && has_irq != INT_NONE)
		dev_warn(&client->dev, "interrupt support not compiled in\n");

	return 0;
}

__attribute__((used)) static int max732x_setup_gpio(struct max732x_chip *chip,
					const struct i2c_device_id *id,
					unsigned gpio_start)
{
	struct gpio_chip *gc = &chip->gpio_chip;
	uint32_t id_data = (uint32_t)max732x_features[id->driver_data];
	int i, port = 0;

	for (i = 0; i < 16; i++, id_data >>= 2) {
		unsigned int mask = 1 << port;

		switch (id_data & 0x3) {
		case PORT_OUTPUT:
			chip->dir_output |= mask;
			break;
		case PORT_INPUT:
			chip->dir_input |= mask;
			break;
		case PORT_OPENDRAIN:
			chip->dir_output |= mask;
			chip->dir_input |= mask;
			break;
		default:
			continue;
		}

		if (i < 8)
			chip->mask_group_a |= mask;
		port++;
	}

	if (chip->dir_input)
		gc->direction_input = max732x_gpio_direction_input;
	if (chip->dir_output) {
		gc->direction_output = max732x_gpio_direction_output;
		gc->set = max732x_gpio_set_value;
		gc->set_multiple = max732x_gpio_set_multiple;
	}
	gc->get = max732x_gpio_get_value;
	gc->can_sleep = true;

	gc->base = gpio_start;
	gc->ngpio = port;
	gc->label = chip->client->name;
	gc->parent = &chip->client->dev;
	gc->owner = THIS_MODULE;

	return port;
}

__attribute__((used)) static struct max732x_platform_data *of_gpio_max732x(struct device *dev)
{
	struct max732x_platform_data *pdata;

	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;

	pdata->gpio_base = -1;

	return pdata;
}

__attribute__((used)) static int max732x_probe(struct i2c_client *client,
				   const struct i2c_device_id *id)
{
	struct max732x_platform_data *pdata;
	struct device_node *node;
	struct max732x_chip *chip;
	struct i2c_client *c;
	uint16_t addr_a, addr_b;
	int ret, nr_port;

	pdata = dev_get_platdata(&client->dev);
	node = client->dev.of_node;

	if (!pdata && node)
		pdata = of_gpio_max732x(&client->dev);

	if (!pdata) {
		dev_dbg(&client->dev, "no platform data\n");
		return -EINVAL;
	}

	chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
	if (chip == NULL)
		return -ENOMEM;
	chip->client = client;

	nr_port = max732x_setup_gpio(chip, id, pdata->gpio_base);
	chip->gpio_chip.parent = &client->dev;

	addr_a = (client->addr & 0x0f) | 0x60;
	addr_b = (client->addr & 0x0f) | 0x50;

	switch (client->addr & 0x70) {
	case 0x60:
		chip->client_group_a = client;
		if (nr_port > 8) {
			c = i2c_new_dummy(client->adapter, addr_b);
			if (!c) {
				dev_err(&client->dev,
					"Failed to allocate I2C device\n");
				ret = -ENODEV;
				goto out_failed;
			}
			chip->client_group_b = chip->client_dummy = c;
		}
		break;
	case 0x50:
		chip->client_group_b = client;
		if (nr_port > 8) {
			c = i2c_new_dummy(client->adapter, addr_a);
			if (!c) {
				dev_err(&client->dev,
					"Failed to allocate I2C device\n");
				ret = -ENODEV;
				goto out_failed;
			}
			chip->client_group_a = chip->client_dummy = c;
		}
		break;
	default:
		dev_err(&client->dev, "invalid I2C address specified %02x\n",
				client->addr);
		ret = -EINVAL;
		goto out_failed;
	}

	if (nr_port > 8 && !chip->client_dummy) {
		dev_err(&client->dev,
			"Failed to allocate second group I2C device\n");
		ret = -ENODEV;
		goto out_failed;
	}

	mutex_init(&chip->lock);

	ret = max732x_readb(chip, is_group_a(chip, 0), &chip->reg_out[0]);
	if (ret)
		goto out_failed;
	if (nr_port > 8) {
		ret = max732x_readb(chip, is_group_a(chip, 8), &chip->reg_out[1]);
		if (ret)
			goto out_failed;
	}

	ret = gpiochip_add_data(&chip->gpio_chip, chip);
	if (ret)
		goto out_failed;

	ret = max732x_irq_setup(chip, id);
	if (ret) {
		gpiochip_remove(&chip->gpio_chip);
		goto out_failed;
	}

	if (pdata && pdata->setup) {
		ret = pdata->setup(client, chip->gpio_chip.base,
				chip->gpio_chip.ngpio, pdata->context);
		if (ret < 0)
			dev_warn(&client->dev, "setup failed, %d\n", ret);
	}

	i2c_set_clientdata(client, chip);
	return 0;

out_failed:
	i2c_unregister_device(chip->client_dummy);
	return ret;
}

__attribute__((used)) static int max732x_remove(struct i2c_client *client)
{
	struct max732x_platform_data *pdata = dev_get_platdata(&client->dev);
	struct max732x_chip *chip = i2c_get_clientdata(client);

	if (pdata && pdata->teardown) {
		int ret;

		ret = pdata->teardown(client, chip->gpio_chip.base,
				chip->gpio_chip.ngpio, pdata->context);
		if (ret < 0) {
			dev_err(&client->dev, "%s failed, %d\n",
					"teardown", ret);
			return ret;
		}
	}

	gpiochip_remove(&chip->gpio_chip);

	/* unregister any dummy i2c_client */
	i2c_unregister_device(chip->client_dummy);

	return 0;
}


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
struct TYPE_2__ {int base; int can_sleep; int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int /*<<< orphan*/  ngpio; int /*<<< orphan*/  owner; int /*<<< orphan*/ * parent; int /*<<< orphan*/  label; } ;
struct mc9s08dz60 {TYPE_1__ chip; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct gpio_chip {int dummy; } ;
typedef  int s32 ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIO_NUM ; 
 int GPIO_NUM_PER_GROUP ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int devm_gpiochip_add_data (int /*<<< orphan*/ *,TYPE_1__*,struct mc9s08dz60*) ; 
 struct mc9s08dz60* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct mc9s08dz60* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct mc9s08dz60*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 

__attribute__((used)) static void mc9s_gpio_to_reg_and_bit(int offset, u8 *reg, u8 *bit)
{
	*reg = 0x20 + offset / GPIO_NUM_PER_GROUP;
	*bit = offset % GPIO_NUM_PER_GROUP;
}

__attribute__((used)) static int mc9s08dz60_get_value(struct gpio_chip *gc, unsigned offset)
{
	u8 reg, bit;
	s32 value;
	struct mc9s08dz60 *mc9s = gpiochip_get_data(gc);

	mc9s_gpio_to_reg_and_bit(offset, &reg, &bit);
	value = i2c_smbus_read_byte_data(mc9s->client, reg);

	return (value >= 0) ? (value >> bit) & 0x1 : 0;
}

__attribute__((used)) static int mc9s08dz60_set(struct mc9s08dz60 *mc9s, unsigned offset, int val)
{
	u8 reg, bit;
	s32 value;

	mc9s_gpio_to_reg_and_bit(offset, &reg, &bit);
	value = i2c_smbus_read_byte_data(mc9s->client, reg);
	if (value >= 0) {
		if (val)
			value |= 1 << bit;
		else
			value &= ~(1 << bit);

		return i2c_smbus_write_byte_data(mc9s->client, reg, value);
	} else
		return value;

}

__attribute__((used)) static void mc9s08dz60_set_value(struct gpio_chip *gc, unsigned offset, int val)
{
	struct mc9s08dz60 *mc9s = gpiochip_get_data(gc);

	mc9s08dz60_set(mc9s, offset, val);
}

__attribute__((used)) static int mc9s08dz60_direction_output(struct gpio_chip *gc,
				       unsigned offset, int val)
{
	struct mc9s08dz60 *mc9s = gpiochip_get_data(gc);

	return mc9s08dz60_set(mc9s, offset, val);
}

__attribute__((used)) static int mc9s08dz60_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct mc9s08dz60 *mc9s;

	mc9s = devm_kzalloc(&client->dev, sizeof(*mc9s), GFP_KERNEL);
	if (!mc9s)
		return -ENOMEM;

	mc9s->chip.label = client->name;
	mc9s->chip.base = -1;
	mc9s->chip.parent = &client->dev;
	mc9s->chip.owner = THIS_MODULE;
	mc9s->chip.ngpio = GPIO_NUM;
	mc9s->chip.can_sleep = true;
	mc9s->chip.get = mc9s08dz60_get_value;
	mc9s->chip.set = mc9s08dz60_set_value;
	mc9s->chip.direction_output = mc9s08dz60_direction_output;
	mc9s->client = client;
	i2c_set_clientdata(client, mc9s);

	return devm_gpiochip_add_data(&client->dev, &mc9s->chip, mc9s);
}


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
typedef  unsigned int u8 ;
typedef  scalar_t__ u16 ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct ad5592r_state {int /*<<< orphan*/  dev; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 unsigned int AD5592R_REG_ADC_SEQ ; 
 unsigned int AD5593R_MODE_ADC_READBACK ; 
 unsigned int AD5593R_MODE_CONF ; 
 unsigned int AD5593R_MODE_DAC_WRITE ; 
 unsigned int AD5593R_MODE_GPIO_READBACK ; 
 unsigned int AD5593R_MODE_REG_READBACK ; 
 scalar_t__ BIT (unsigned int) ; 
 int ad5592r_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int ad5592r_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ad5593r_rw_ops ; 
 scalar_t__ i2c_smbus_read_word_swapped (struct i2c_client*,unsigned int) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,unsigned int,scalar_t__) ; 
 struct i2c_client* to_i2c_client (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ad5593r_write_dac(struct ad5592r_state *st, unsigned chan, u16 value)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);

	return i2c_smbus_write_word_swapped(i2c,
			AD5593R_MODE_DAC_WRITE | chan, value);
}

__attribute__((used)) static int ad5593r_read_adc(struct ad5592r_state *st, unsigned chan, u16 *value)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);
	s32 val;

	val = i2c_smbus_write_word_swapped(i2c,
			AD5593R_MODE_CONF | AD5592R_REG_ADC_SEQ, BIT(chan));
	if (val < 0)
		return (int) val;

	val = i2c_smbus_read_word_swapped(i2c, AD5593R_MODE_ADC_READBACK);
	if (val < 0)
		return (int) val;

	*value = (u16) val;

	return 0;
}

__attribute__((used)) static int ad5593r_reg_write(struct ad5592r_state *st, u8 reg, u16 value)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);

	return i2c_smbus_write_word_swapped(i2c,
			AD5593R_MODE_CONF | reg, value);
}

__attribute__((used)) static int ad5593r_reg_read(struct ad5592r_state *st, u8 reg, u16 *value)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);
	s32 val;

	val = i2c_smbus_read_word_swapped(i2c, AD5593R_MODE_REG_READBACK | reg);
	if (val < 0)
		return (int) val;

	*value = (u16) val;

	return 0;
}

__attribute__((used)) static int ad5593r_gpio_read(struct ad5592r_state *st, u8 *value)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);
	s32 val;

	val = i2c_smbus_read_word_swapped(i2c, AD5593R_MODE_GPIO_READBACK);
	if (val < 0)
		return (int) val;

	*value = (u8) val;

	return 0;
}

__attribute__((used)) static int ad5593r_i2c_probe(struct i2c_client *i2c,
		const struct i2c_device_id *id)
{
	return ad5592r_probe(&i2c->dev, id->name, &ad5593r_rw_ops);
}

__attribute__((used)) static int ad5593r_i2c_remove(struct i2c_client *i2c)
{
	return ad5592r_remove(&i2c->dev);
}


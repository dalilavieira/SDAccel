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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  adt7410_i2c_ops ; 
 int adt7x10_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int adt7x10_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_swapped (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_word_swapped (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_i2c_client (struct device*) ; 

__attribute__((used)) static int adt7410_i2c_read_word(struct device *dev, u8 reg)
{
	return i2c_smbus_read_word_swapped(to_i2c_client(dev), reg);
}

__attribute__((used)) static int adt7410_i2c_write_word(struct device *dev, u8 reg, u16 data)
{
	return i2c_smbus_write_word_swapped(to_i2c_client(dev), reg, data);
}

__attribute__((used)) static int adt7410_i2c_read_byte(struct device *dev, u8 reg)
{
	return i2c_smbus_read_byte_data(to_i2c_client(dev), reg);
}

__attribute__((used)) static int adt7410_i2c_write_byte(struct device *dev, u8 reg, u8 data)
{
	return i2c_smbus_write_byte_data(to_i2c_client(dev), reg, data);
}

__attribute__((used)) static int adt7410_i2c_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	if (!i2c_check_functionality(client->adapter,
			I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	return adt7x10_probe(&client->dev, NULL, client->irq, &adt7410_i2c_ops);
}

__attribute__((used)) static int adt7410_i2c_remove(struct i2c_client *client)
{
	return adt7x10_remove(&client->dev, client->irq);
}


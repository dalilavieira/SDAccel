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
struct regmap {int dummy; } ;
struct pm860x_chip {struct regmap* regmap_companion; struct regmap* regmap; struct i2c_client* client; } ;
struct i2c_msg {int len; unsigned char* buf; scalar_t__ flags; int /*<<< orphan*/  addr; } ;
struct i2c_client {struct i2c_adapter* adapter; int /*<<< orphan*/  addr; } ;
struct i2c_adapter {TYPE_1__* algo; } ;
struct TYPE_2__ {int (* master_xfer ) (struct i2c_adapter*,struct i2c_msg*,int) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  I2C_LOCK_SEGMENT ; 
 scalar_t__ I2C_M_RD ; 
 int /*<<< orphan*/  I2C_SMBUS_BLOCK_MAX ; 
 struct pm860x_chip* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_lock_bus (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_unlock_bus (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,void*,int) ; 
 int regmap_raw_read (struct regmap*,int,unsigned char*,int) ; 
 int regmap_raw_write (struct regmap*,int,unsigned char*,int) ; 
 int regmap_read (struct regmap*,int,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int,unsigned char,unsigned char) ; 
 int regmap_write (struct regmap*,int,unsigned char) ; 
 int stub1 (struct i2c_adapter*,struct i2c_msg*,int) ; 
 int stub2 (struct i2c_adapter*,struct i2c_msg*,int) ; 

int pm860x_reg_read(struct i2c_client *i2c, int reg)
{
	struct pm860x_chip *chip = i2c_get_clientdata(i2c);
	struct regmap *map = (i2c == chip->client) ? chip->regmap
				: chip->regmap_companion;
	unsigned int data;
	int ret;

	ret = regmap_read(map, reg, &data);
	if (ret < 0)
		return ret;
	else
		return (int)data;
}

int pm860x_reg_write(struct i2c_client *i2c, int reg,
		     unsigned char data)
{
	struct pm860x_chip *chip = i2c_get_clientdata(i2c);
	struct regmap *map = (i2c == chip->client) ? chip->regmap
				: chip->regmap_companion;
	int ret;

	ret = regmap_write(map, reg, data);
	return ret;
}

int pm860x_bulk_read(struct i2c_client *i2c, int reg,
		     int count, unsigned char *buf)
{
	struct pm860x_chip *chip = i2c_get_clientdata(i2c);
	struct regmap *map = (i2c == chip->client) ? chip->regmap
				: chip->regmap_companion;
	int ret;

	ret = regmap_raw_read(map, reg, buf, count);
	return ret;
}

int pm860x_bulk_write(struct i2c_client *i2c, int reg,
		      int count, unsigned char *buf)
{
	struct pm860x_chip *chip = i2c_get_clientdata(i2c);
	struct regmap *map = (i2c == chip->client) ? chip->regmap
				: chip->regmap_companion;
	int ret;

	ret = regmap_raw_write(map, reg, buf, count);
	return ret;
}

int pm860x_set_bits(struct i2c_client *i2c, int reg,
		    unsigned char mask, unsigned char data)
{
	struct pm860x_chip *chip = i2c_get_clientdata(i2c);
	struct regmap *map = (i2c == chip->client) ? chip->regmap
				: chip->regmap_companion;
	int ret;

	ret = regmap_update_bits(map, reg, mask, data);
	return ret;
}

__attribute__((used)) static int read_device(struct i2c_client *i2c, int reg,
		       int bytes, void *dest)
{
	unsigned char msgbuf0[I2C_SMBUS_BLOCK_MAX + 3];
	unsigned char msgbuf1[I2C_SMBUS_BLOCK_MAX + 2];
	struct i2c_adapter *adap = i2c->adapter;
	struct i2c_msg msg[2] = {
					{
						.addr = i2c->addr,
						.flags = 0,
						.len = 1,
						.buf = msgbuf0
					},
					{	.addr = i2c->addr,
						.flags = I2C_M_RD,
						.len = 0,
						.buf = msgbuf1
					},
				};
	int num = 1, ret = 0;

	if (dest == NULL)
		return -EINVAL;
	msgbuf0[0] = (unsigned char)reg;	/* command */
	msg[1].len = bytes;

	/* if data needs to read back, num should be 2 */
	if (bytes > 0)
		num = 2;
	ret = adap->algo->master_xfer(adap, msg, num);
	memcpy(dest, msgbuf1, bytes);
	if (ret < 0)
		return ret;
	return 0;
}

__attribute__((used)) static int write_device(struct i2c_client *i2c, int reg,
			int bytes, void *src)
{
	unsigned char buf[2];
	struct i2c_adapter *adap = i2c->adapter;
	struct i2c_msg msg;
	int ret;

	buf[0] = (unsigned char)reg;
	memcpy(&buf[1], src, bytes);
	msg.addr = i2c->addr;
	msg.flags = 0;
	msg.len = bytes + 1;
	msg.buf = buf;

	ret = adap->algo->master_xfer(adap, &msg, 1);
	if (ret < 0)
		return ret;
	return 0;
}

int pm860x_page_reg_write(struct i2c_client *i2c, int reg,
			  unsigned char data)
{
	unsigned char zero;
	int ret;

	i2c_lock_bus(i2c->adapter, I2C_LOCK_SEGMENT);
	read_device(i2c, 0xFA, 0, &zero);
	read_device(i2c, 0xFB, 0, &zero);
	read_device(i2c, 0xFF, 0, &zero);
	ret = write_device(i2c, reg, 1, &data);
	read_device(i2c, 0xFE, 0, &zero);
	read_device(i2c, 0xFC, 0, &zero);
	i2c_unlock_bus(i2c->adapter, I2C_LOCK_SEGMENT);
	return ret;
}

int pm860x_page_bulk_read(struct i2c_client *i2c, int reg,
			  int count, unsigned char *buf)
{
	unsigned char zero = 0;
	int ret;

	i2c_lock_bus(i2c->adapter, I2C_LOCK_SEGMENT);
	read_device(i2c, 0xfa, 0, &zero);
	read_device(i2c, 0xfb, 0, &zero);
	read_device(i2c, 0xff, 0, &zero);
	ret = read_device(i2c, reg, count, buf);
	read_device(i2c, 0xFE, 0, &zero);
	read_device(i2c, 0xFC, 0, &zero);
	i2c_unlock_bus(i2c->adapter, I2C_LOCK_SEGMENT);
	return ret;
}


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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct i2c_msg {int flags; int len; char* buf; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int /*<<< orphan*/  name; int /*<<< orphan*/  driver_data; } ;
struct i2c_client {int flags; int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
struct ad5686_state {TYPE_1__* data; int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {char* d8; void* d32; int /*<<< orphan*/  d16; } ;

/* Variables and functions */
 int AD5686_ADDR (int /*<<< orphan*/ ) ; 
 int AD5686_CMD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AD5686_CMD_NOOP ; 
 int EIO ; 
 int I2C_M_RD ; 
 int ad5686_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct ad5686_state*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int),int (*) (struct ad5686_state*,int /*<<< orphan*/ )) ; 
 int ad5686_remove (int /*<<< orphan*/ *) ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 void* cpu_to_be32 (int) ; 
 int i2c_master_send (struct i2c_client*,char*,int) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 struct i2c_client* to_i2c_client (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ad5686_i2c_read(struct ad5686_state *st, u8 addr)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);
	struct i2c_msg msg[2] = {
		{
			.addr = i2c->addr,
			.flags = i2c->flags,
			.len = 3,
			.buf = &st->data[0].d8[1],
		},
		{
			.addr = i2c->addr,
			.flags = i2c->flags | I2C_M_RD,
			.len = 2,
			.buf = (char *)&st->data[0].d16,
		},
	};
	int ret;

	st->data[0].d32 = cpu_to_be32(AD5686_CMD(AD5686_CMD_NOOP) |
				      AD5686_ADDR(addr) |
				      0x00);

	ret = i2c_transfer(i2c->adapter, msg, 2);
	if (ret < 0)
		return ret;

	return be16_to_cpu(st->data[0].d16);
}

__attribute__((used)) static int ad5686_i2c_write(struct ad5686_state *st,
			    u8 cmd, u8 addr, u16 val)
{
	struct i2c_client *i2c = to_i2c_client(st->dev);
	int ret;

	st->data[0].d32 = cpu_to_be32(AD5686_CMD(cmd) | AD5686_ADDR(addr)
				      | val);

	ret = i2c_master_send(i2c, &st->data[0].d8[1], 3);
	if (ret < 0)
		return ret;

	return (ret != 3) ? -EIO : 0;
}

__attribute__((used)) static int ad5686_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	return ad5686_probe(&i2c->dev, id->driver_data, id->name,
			    ad5686_i2c_write, ad5686_i2c_read);
}

__attribute__((used)) static int ad5686_i2c_remove(struct i2c_client *i2c)
{
	return ad5686_remove(&i2c->dev);
}


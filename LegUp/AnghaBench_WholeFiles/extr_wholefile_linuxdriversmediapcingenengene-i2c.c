#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_11__ {int Device; int* Data; } ;
struct TYPE_10__ {int Length; int /*<<< orphan*/  Opcode; } ;
struct TYPE_12__ {int* raw8; TYPE_4__ I2CRead; TYPE_3__ hdr; } ;
struct ngene_command {int in_len; int out_len; TYPE_5__ cmd; } ;
struct ngene_channel {int number; struct ngene* dev; } ;
struct ngene {int i2c_current_bus; TYPE_2__* pci_dev; TYPE_7__* channel; int /*<<< orphan*/  i2c_switch_mutex; TYPE_6__* card_info; } ;
struct i2c_msg {int flags; int addr; int* buf; int len; } ;
struct TYPE_8__ {int /*<<< orphan*/ * parent; } ;
struct i2c_adapter {TYPE_1__ dev; void* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; } ;
struct TYPE_14__ {struct i2c_adapter i2c_adapter; } ;
struct TYPE_13__ {int i2c_access; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_I2C_READ ; 
 int /*<<< orphan*/  CMD_I2C_WRITE ; 
 int EIO ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 scalar_t__ i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (struct i2c_adapter*,TYPE_7__*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ ngene_command (struct ngene*,struct ngene_command*) ; 
 int /*<<< orphan*/  ngene_command_gpio_set (struct ngene*,int,int) ; 
 int /*<<< orphan*/  ngene_i2c_algo ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int ngene_command_i2c_read(struct ngene *dev, u8 adr,
			   u8 *out, u8 outlen, u8 *in, u8 inlen, int flag)
{
	struct ngene_command com;

	com.cmd.hdr.Opcode = CMD_I2C_READ;
	com.cmd.hdr.Length = outlen + 3;
	com.cmd.I2CRead.Device = adr << 1;
	memcpy(com.cmd.I2CRead.Data, out, outlen);
	com.cmd.I2CRead.Data[outlen] = inlen;
	com.cmd.I2CRead.Data[outlen + 1] = 0;
	com.in_len = outlen + 3;
	com.out_len = inlen + 1;

	if (ngene_command(dev, &com) < 0)
		return -EIO;

	if ((com.cmd.raw8[0] >> 1) != adr)
		return -EIO;

	if (flag)
		memcpy(in, com.cmd.raw8, inlen + 1);
	else
		memcpy(in, com.cmd.raw8 + 1, inlen);
	return 0;
}

__attribute__((used)) static int ngene_command_i2c_write(struct ngene *dev, u8 adr,
				   u8 *out, u8 outlen)
{
	struct ngene_command com;


	com.cmd.hdr.Opcode = CMD_I2C_WRITE;
	com.cmd.hdr.Length = outlen + 1;
	com.cmd.I2CRead.Device = adr << 1;
	memcpy(com.cmd.I2CRead.Data, out, outlen);
	com.in_len = outlen + 1;
	com.out_len = 1;

	if (ngene_command(dev, &com) < 0)
		return -EIO;

	if (com.cmd.raw8[0] == 1)
		return -EIO;

	return 0;
}

__attribute__((used)) static void ngene_i2c_set_bus(struct ngene *dev, int bus)
{
	if (!(dev->card_info->i2c_access & 2))
		return;
	if (dev->i2c_current_bus == bus)
		return;

	switch (bus) {
	case 0:
		ngene_command_gpio_set(dev, 3, 0);
		ngene_command_gpio_set(dev, 2, 1);
		break;

	case 1:
		ngene_command_gpio_set(dev, 2, 0);
		ngene_command_gpio_set(dev, 3, 1);
		break;
	}
	dev->i2c_current_bus = bus;
}

__attribute__((used)) static int ngene_i2c_master_xfer(struct i2c_adapter *adapter,
				 struct i2c_msg msg[], int num)
{
	struct ngene_channel *chan =
		(struct ngene_channel *)i2c_get_adapdata(adapter);
	struct ngene *dev = chan->dev;

	mutex_lock(&dev->i2c_switch_mutex);
	ngene_i2c_set_bus(dev, chan->number);

	if (num == 2 && msg[1].flags & I2C_M_RD && !(msg[0].flags & I2C_M_RD))
		if (!ngene_command_i2c_read(dev, msg[0].addr,
					    msg[0].buf, msg[0].len,
					    msg[1].buf, msg[1].len, 0))
			goto done;

	if (num == 1 && !(msg[0].flags & I2C_M_RD))
		if (!ngene_command_i2c_write(dev, msg[0].addr,
					     msg[0].buf, msg[0].len))
			goto done;
	if (num == 1 && (msg[0].flags & I2C_M_RD))
		if (!ngene_command_i2c_read(dev, msg[0].addr, NULL, 0,
					    msg[0].buf, msg[0].len, 0))
			goto done;

	mutex_unlock(&dev->i2c_switch_mutex);
	return -EIO;

done:
	mutex_unlock(&dev->i2c_switch_mutex);
	return num;
}

__attribute__((used)) static u32 ngene_i2c_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

int ngene_i2c_init(struct ngene *dev, int dev_nr)
{
	struct i2c_adapter *adap = &(dev->channel[dev_nr].i2c_adapter);

	i2c_set_adapdata(adap, &(dev->channel[dev_nr]));

	strcpy(adap->name, "nGene");

	adap->algo = &ngene_i2c_algo;
	adap->algo_data = (void *)&(dev->channel[dev_nr]);
	adap->dev.parent = &dev->pci_dev->dev;

	return i2c_add_adapter(adap);
}


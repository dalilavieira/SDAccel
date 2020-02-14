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
typedef  char u8 ;
struct tps6507x_dev {int (* read_dev ) (struct tps6507x_dev*,char,int,void*) ;int (* write_dev ) (struct tps6507x_dev*,char,int,void*) ;int /*<<< orphan*/ * dev; struct i2c_client* i2c_client; } ;
struct i2c_msg {int len; char* buf; scalar_t__ flags; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ I2C_M_RD ; 
 int TPS6507X_MAX_REGISTER ; 
 struct tps6507x_dev* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int i2c_master_send (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tps6507x_dev*) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  memcpy (char*,void*,int) ; 
 int /*<<< orphan*/  tps6507x_devs ; 

__attribute__((used)) static int tps6507x_i2c_read_device(struct tps6507x_dev *tps6507x, char reg,
				  int bytes, void *dest)
{
	struct i2c_client *i2c = tps6507x->i2c_client;
	struct i2c_msg xfer[2];
	int ret;

	/* Write register */
	xfer[0].addr = i2c->addr;
	xfer[0].flags = 0;
	xfer[0].len = 1;
	xfer[0].buf = &reg;

	/* Read data */
	xfer[1].addr = i2c->addr;
	xfer[1].flags = I2C_M_RD;
	xfer[1].len = bytes;
	xfer[1].buf = dest;

	ret = i2c_transfer(i2c->adapter, xfer, 2);
	if (ret == 2)
		ret = 0;
	else if (ret >= 0)
		ret = -EIO;

	return ret;
}

__attribute__((used)) static int tps6507x_i2c_write_device(struct tps6507x_dev *tps6507x, char reg,
				   int bytes, void *src)
{
	struct i2c_client *i2c = tps6507x->i2c_client;
	/* we add 1 byte for device register */
	u8 msg[TPS6507X_MAX_REGISTER + 1];
	int ret;

	if (bytes > TPS6507X_MAX_REGISTER)
		return -EINVAL;

	msg[0] = reg;
	memcpy(&msg[1], src, bytes);

	ret = i2c_master_send(i2c, msg, bytes + 1);
	if (ret < 0)
		return ret;
	if (ret != bytes + 1)
		return -EIO;
	return 0;
}

__attribute__((used)) static int tps6507x_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct tps6507x_dev *tps6507x;

	tps6507x = devm_kzalloc(&i2c->dev, sizeof(struct tps6507x_dev),
				GFP_KERNEL);
	if (tps6507x == NULL)
		return -ENOMEM;

	i2c_set_clientdata(i2c, tps6507x);
	tps6507x->dev = &i2c->dev;
	tps6507x->i2c_client = i2c;
	tps6507x->read_dev = tps6507x_i2c_read_device;
	tps6507x->write_dev = tps6507x_i2c_write_device;

	return devm_mfd_add_devices(tps6507x->dev, -1, tps6507x_devs,
				    ARRAY_SIZE(tps6507x_devs), NULL, 0, NULL);
}


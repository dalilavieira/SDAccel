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
typedef  int u8 ;
typedef  int u16 ;
struct mii_bus {int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int) ;struct i2c_adapter* priv; struct device* parent; int /*<<< orphan*/  id; } ;
struct i2c_msg {int addr; int len; int* buf; scalar_t__ flags; } ;
struct i2c_adapter {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  data ;

/* Variables and functions */
 int ARRAY_SIZE (struct i2c_msg*) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct mii_bus* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 scalar_t__ I2C_M_RD ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 char* dev_name (struct device*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_transfer (struct i2c_adapter*,struct i2c_msg*,int) ; 
 struct mii_bus* mdiobus_alloc () ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 

__attribute__((used)) static bool i2c_mii_valid_phy_id(int phy_id)
{
	return phy_id != 0x10 && phy_id != 0x11;
}

__attribute__((used)) static unsigned int i2c_mii_phy_addr(int phy_id)
{
	return phy_id + 0x40;
}

__attribute__((used)) static int i2c_mii_read(struct mii_bus *bus, int phy_id, int reg)
{
	struct i2c_adapter *i2c = bus->priv;
	struct i2c_msg msgs[2];
	u8 data[2], dev_addr = reg;
	int bus_addr, ret;

	if (!i2c_mii_valid_phy_id(phy_id))
		return 0xffff;

	bus_addr = i2c_mii_phy_addr(phy_id);
	msgs[0].addr = bus_addr;
	msgs[0].flags = 0;
	msgs[0].len = 1;
	msgs[0].buf = &dev_addr;
	msgs[1].addr = bus_addr;
	msgs[1].flags = I2C_M_RD;
	msgs[1].len = sizeof(data);
	msgs[1].buf = data;

	ret = i2c_transfer(i2c, msgs, ARRAY_SIZE(msgs));
	if (ret != ARRAY_SIZE(msgs))
		return 0xffff;

	return data[0] << 8 | data[1];
}

__attribute__((used)) static int i2c_mii_write(struct mii_bus *bus, int phy_id, int reg, u16 val)
{
	struct i2c_adapter *i2c = bus->priv;
	struct i2c_msg msg;
	int ret;
	u8 data[3];

	if (!i2c_mii_valid_phy_id(phy_id))
		return 0;

	data[0] = reg;
	data[1] = val >> 8;
	data[2] = val;

	msg.addr = i2c_mii_phy_addr(phy_id);
	msg.flags = 0;
	msg.len = 3;
	msg.buf = data;

	ret = i2c_transfer(i2c, &msg, 1);

	return ret < 0 ? ret : 0;
}

struct mii_bus *mdio_i2c_alloc(struct device *parent, struct i2c_adapter *i2c)
{
	struct mii_bus *mii;

	if (!i2c_check_functionality(i2c, I2C_FUNC_I2C))
		return ERR_PTR(-EINVAL);

	mii = mdiobus_alloc();
	if (!mii)
		return ERR_PTR(-ENOMEM);

	snprintf(mii->id, MII_BUS_ID_SIZE, "i2c:%s", dev_name(parent));
	mii->parent = parent;
	mii->read = i2c_mii_read;
	mii->write = i2c_mii_write;
	mii->priv = i2c;

	return mii;
}


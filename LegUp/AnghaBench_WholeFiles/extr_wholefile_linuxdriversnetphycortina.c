#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_3__ {int /*<<< orphan*/  addr; int /*<<< orphan*/  bus; } ;
struct phy_device {int link; TYPE_2__* drv; int /*<<< orphan*/  duplex; int /*<<< orphan*/  speed; TYPE_1__ mdio; } ;
struct TYPE_4__ {int phy_id; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  DUPLEX_FULL ; 
 int ENODEV ; 
 int ENXIO ; 
 int MII_ADDR_C45 ; 
 int /*<<< orphan*/  SPEED_10000 ; 
 int VILLA_GLOBAL_CHIP_ID_LSB ; 
 int VILLA_GLOBAL_CHIP_ID_MSB ; 
 int VILLA_GLOBAL_GPIO_1_INTS ; 
 int mdiobus_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phydev_err (struct phy_device*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cortina_read_reg(struct phy_device *phydev, u16 regnum)
{
	return mdiobus_read(phydev->mdio.bus, phydev->mdio.addr,
			    MII_ADDR_C45 | regnum);
}

__attribute__((used)) static int cortina_read_status(struct phy_device *phydev)
{
	int gpio_int_status, ret = 0;

	gpio_int_status = cortina_read_reg(phydev, VILLA_GLOBAL_GPIO_1_INTS);
	if (gpio_int_status < 0) {
		ret = gpio_int_status;
		goto err;
	}

	if (gpio_int_status & 0x8) {
		/* up when edc_convergedS set */
		phydev->speed = SPEED_10000;
		phydev->duplex = DUPLEX_FULL;
		phydev->link = 1;
	} else {
		phydev->link = 0;
	}

err:
	return ret;
}

__attribute__((used)) static int cortina_probe(struct phy_device *phydev)
{
	u32 phy_id = 0;
	int id_lsb = 0, id_msb = 0;

	/* Read device id from phy registers. */
	id_lsb = cortina_read_reg(phydev, VILLA_GLOBAL_CHIP_ID_LSB);
	if (id_lsb < 0)
		return -ENXIO;

	phy_id = id_lsb << 16;

	id_msb = cortina_read_reg(phydev, VILLA_GLOBAL_CHIP_ID_MSB);
	if (id_msb < 0)
		return -ENXIO;

	phy_id |= id_msb;

	/* Make sure the device tree binding matched the driver with the
	 * right device.
	 */
	if (phy_id != phydev->drv->phy_id) {
		phydev_err(phydev, "Error matching phy with %s driver\n",
			   phydev->drv->name);
		return -ENODEV;
	}

	return 0;
}


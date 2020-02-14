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
struct phy_device {scalar_t__ interrupts; } ;

/* Variables and functions */
 int /*<<< orphan*/  MII_AM79C_IR ; 
 int /*<<< orphan*/  MII_AM79C_IR_IMASK_INIT ; 
 int /*<<< orphan*/  MII_BMSR ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int am79c_ack_interrupt(struct phy_device *phydev)
{
	int err;

	err = phy_read(phydev, MII_BMSR);
	if (err < 0)
		return err;

	err = phy_read(phydev, MII_AM79C_IR);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int am79c_config_init(struct phy_device *phydev)
{
	return 0;
}

__attribute__((used)) static int am79c_config_intr(struct phy_device *phydev)
{
	int err;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		err = phy_write(phydev, MII_AM79C_IR, MII_AM79C_IR_IMASK_INIT);
	else
		err = phy_write(phydev, MII_AM79C_IR, 0);

	return err;
}


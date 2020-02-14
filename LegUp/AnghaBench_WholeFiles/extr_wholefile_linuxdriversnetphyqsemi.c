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
 int /*<<< orphan*/  MII_BMSR ; 
 int /*<<< orphan*/  MII_EXPANSION ; 
 int /*<<< orphan*/  MII_QS6612_IMR ; 
 int MII_QS6612_IMR_INIT ; 
 int /*<<< orphan*/  MII_QS6612_ISR ; 
 int /*<<< orphan*/  MII_QS6612_PCR ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int qs6612_config_init(struct phy_device *phydev)
{
	/* The PHY powers up isolated on the RPX,
	 * so send a command to allow operation.
	 * XXX - My docs indicate this should be 0x0940
	 * ...or something.  The current value sets three
	 * reserved bits, bit 11, which specifies it should be
	 * set to one, bit 10, which specifies it should be set
	 * to 0, and bit 7, which doesn't specify.  However, my
	 * docs are preliminary, and I will leave it like this
	 * until someone more knowledgable corrects me or it.
	 * -- Andy Fleming
	 */
	return phy_write(phydev, MII_QS6612_PCR, 0x0dc0);
}

__attribute__((used)) static int qs6612_ack_interrupt(struct phy_device *phydev)
{
	int err;

	err = phy_read(phydev, MII_QS6612_ISR);

	if (err < 0)
		return err;

	err = phy_read(phydev, MII_BMSR);

	if (err < 0)
		return err;

	err = phy_read(phydev, MII_EXPANSION);

	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int qs6612_config_intr(struct phy_device *phydev)
{
	int err;
	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		err = phy_write(phydev, MII_QS6612_IMR,
				MII_QS6612_IMR_INIT);
	else
		err = phy_write(phydev, MII_QS6612_IMR, 0);

	return err;

}


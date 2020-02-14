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
struct phy_device {scalar_t__ interrupts; } ;

/* Variables and functions */
 int ALL_FALLBACK_ON ; 
 int BMCR_PDOWN ; 
 int /*<<< orphan*/  DP83865_INT_CLEAR ; 
 int /*<<< orphan*/  DP83865_INT_MASK ; 
 int DP83865_INT_MASK_DEFAULT ; 
 int /*<<< orphan*/  DP83865_INT_STATUS ; 
 int /*<<< orphan*/  LED_CTRL_REG ; 
 int /*<<< orphan*/  MII_BMCR ; 
 int /*<<< orphan*/  NS_EXP_MEM_ADD ; 
 int /*<<< orphan*/  NS_EXP_MEM_CTL ; 
 int /*<<< orphan*/  NS_EXP_MEM_DATA ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int hdx_loopback_off ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_debug (char*,char*) ; 

__attribute__((used)) static u8 ns_exp_read(struct phy_device *phydev, u16 reg)
{
	phy_write(phydev, NS_EXP_MEM_ADD, reg);
	return phy_read(phydev, NS_EXP_MEM_DATA);
}

__attribute__((used)) static void ns_exp_write(struct phy_device *phydev, u16 reg, u8 data)
{
	phy_write(phydev, NS_EXP_MEM_ADD, reg);
	phy_write(phydev, NS_EXP_MEM_DATA, data);
}

__attribute__((used)) static int ns_config_intr(struct phy_device *phydev)
{
	int err;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		err = phy_write(phydev, DP83865_INT_MASK,
				DP83865_INT_MASK_DEFAULT);
	else
		err = phy_write(phydev, DP83865_INT_MASK, 0);

	return err;
}

__attribute__((used)) static int ns_ack_interrupt(struct phy_device *phydev)
{
	int ret = phy_read(phydev, DP83865_INT_STATUS);
	if (ret < 0)
		return ret;

	/* Clear the interrupt status bit by writing a “1”
	 * to the corresponding bit in INT_CLEAR (2:0 are reserved) */
	ret = phy_write(phydev, DP83865_INT_CLEAR, ret & ~0x7);

	return ret;
}

__attribute__((used)) static void ns_giga_speed_fallback(struct phy_device *phydev, int mode)
{
	int bmcr = phy_read(phydev, MII_BMCR);

	phy_write(phydev, MII_BMCR, (bmcr | BMCR_PDOWN));

	/* Enable 8 bit expended memory read/write (no auto increment) */
	phy_write(phydev, NS_EXP_MEM_CTL, 0);
	phy_write(phydev, NS_EXP_MEM_ADD, 0x1C0);
	phy_write(phydev, NS_EXP_MEM_DATA, 0x0008);
	phy_write(phydev, MII_BMCR, (bmcr & ~BMCR_PDOWN));
	phy_write(phydev, LED_CTRL_REG, mode);
}

__attribute__((used)) static void ns_10_base_t_hdx_loopack(struct phy_device *phydev, int disable)
{
	if (disable)
		ns_exp_write(phydev, 0x1c0, ns_exp_read(phydev, 0x1c0) | 1);
	else
		ns_exp_write(phydev, 0x1c0,
			     ns_exp_read(phydev, 0x1c0) & 0xfffe);

	pr_debug("10BASE-T HDX loopback %s\n",
		 (ns_exp_read(phydev, 0x1c0) & 0x0001) ? "off" : "on");
}

__attribute__((used)) static int ns_config_init(struct phy_device *phydev)
{
	ns_giga_speed_fallback(phydev, ALL_FALLBACK_ON);
	/* In the latest MAC or switches design, the 10 Mbps loopback
	   is desired to be turned off. */
	ns_10_base_t_hdx_loopack(phydev, hdx_loopback_off);
	return ns_ack_interrupt(phydev);
}


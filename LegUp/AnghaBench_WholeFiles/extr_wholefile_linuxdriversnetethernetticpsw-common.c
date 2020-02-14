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
typedef  int u32 ;
typedef  int u16 ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  CTRL_MAC_HI_REG (int,int) ; 
 int /*<<< orphan*/  CTRL_MAC_LO_REG (int,int) ; 
 int ENODEV ; 
 int ENOENT ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 scalar_t__ of_device_is_compatible (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ of_machine_is_compatible (char*) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 struct regmap* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int davinci_emac_3517_get_macid(struct device *dev, u16 offset,
				       int slave, u8 *mac_addr)
{
	u32 macid_lsb;
	u32 macid_msb;
	struct regmap *syscon;

	syscon = syscon_regmap_lookup_by_phandle(dev->of_node, "syscon");
	if (IS_ERR(syscon)) {
		if (PTR_ERR(syscon) == -ENODEV)
			return 0;
		return PTR_ERR(syscon);
	}

	regmap_read(syscon, CTRL_MAC_LO_REG(offset, slave), &macid_lsb);
	regmap_read(syscon, CTRL_MAC_HI_REG(offset, slave), &macid_msb);

	mac_addr[0] = (macid_msb >> 16) & 0xff;
	mac_addr[1] = (macid_msb >> 8)  & 0xff;
	mac_addr[2] = macid_msb & 0xff;
	mac_addr[3] = (macid_lsb >> 16) & 0xff;
	mac_addr[4] = (macid_lsb >> 8)  & 0xff;
	mac_addr[5] = macid_lsb & 0xff;

	return 0;
}

__attribute__((used)) static int cpsw_am33xx_cm_get_macid(struct device *dev, u16 offset, int slave,
				    u8 *mac_addr)
{
	u32 macid_lo;
	u32 macid_hi;
	struct regmap *syscon;

	syscon = syscon_regmap_lookup_by_phandle(dev->of_node, "syscon");
	if (IS_ERR(syscon)) {
		if (PTR_ERR(syscon) == -ENODEV)
			return 0;
		return PTR_ERR(syscon);
	}

	regmap_read(syscon, CTRL_MAC_LO_REG(offset, slave), &macid_lo);
	regmap_read(syscon, CTRL_MAC_HI_REG(offset, slave), &macid_hi);

	mac_addr[5] = (macid_lo >> 8) & 0xff;
	mac_addr[4] = macid_lo & 0xff;
	mac_addr[3] = (macid_hi >> 24) & 0xff;
	mac_addr[2] = (macid_hi >> 16) & 0xff;
	mac_addr[1] = (macid_hi >> 8) & 0xff;
	mac_addr[0] = macid_hi & 0xff;

	return 0;
}

int ti_cm_get_macid(struct device *dev, int slave, u8 *mac_addr)
{
	if (of_machine_is_compatible("ti,dm8148"))
		return cpsw_am33xx_cm_get_macid(dev, 0x630, slave, mac_addr);

	if (of_machine_is_compatible("ti,am33xx"))
		return cpsw_am33xx_cm_get_macid(dev, 0x630, slave, mac_addr);

	if (of_device_is_compatible(dev->of_node, "ti,am3517-emac"))
		return davinci_emac_3517_get_macid(dev, 0x110, slave, mac_addr);

	if (of_device_is_compatible(dev->of_node, "ti,dm816-emac"))
		return cpsw_am33xx_cm_get_macid(dev, 0x30, slave, mac_addr);

	if (of_machine_is_compatible("ti,am43"))
		return cpsw_am33xx_cm_get_macid(dev, 0x630, slave, mac_addr);

	if (of_machine_is_compatible("ti,dra7"))
		return davinci_emac_3517_get_macid(dev, 0x514, slave, mac_addr);

	dev_info(dev, "incompatible machine/device type for reading mac address\n");
	return -ENOENT;
}


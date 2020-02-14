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
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct mii_bus {int /*<<< orphan*/  name; } ;
struct mdio_device {scalar_t__ addr; int /*<<< orphan*/  dev; struct mii_bus* bus; } ;
struct dsa_switch {int dummy; } ;
struct b53_device {scalar_t__ chip_id; int current_page; struct dsa_switch* ds; struct mii_bus* bus; struct mii_bus* priv; } ;
struct b53_arl_entry {int port; int is_valid; int is_age; int is_static; int vid; int /*<<< orphan*/  mac; } ;

/* Variables and functions */
 int ARLTBL_AGE ; 
 int ARLTBL_DATA_PORT_ID_MASK ; 
 int ARLTBL_STATIC ; 
 int ARLTBL_VALID ; 
 int ARLTBL_VID_MASK ; 
 int ARLTBL_VID_S ; 
 int B53_BRCM_OUI_1 ; 
 int B53_BRCM_OUI_2 ; 
 int B53_BRCM_OUI_3 ; 
 int B53_BRCM_OUI_4 ; 
 scalar_t__ BCM53010_DEVICE_ID ; 
 scalar_t__ BCM53011_DEVICE_ID ; 
 scalar_t__ BCM53012_DEVICE_ID ; 
 scalar_t__ BCM53018_DEVICE_ID ; 
 scalar_t__ BCM53019_DEVICE_ID ; 
 scalar_t__ BCM53115_DEVICE_ID ; 
 scalar_t__ BCM53125_DEVICE_ID ; 
 scalar_t__ BCM53128_DEVICE_ID ; 
 scalar_t__ BCM5325_DEVICE_ID ; 
 scalar_t__ BCM5395_DEVICE_ID ; 
 scalar_t__ BCM5397_DEVICE_ID ; 
 scalar_t__ BCM5398_DEVICE_ID ; 
 scalar_t__ BCM583XX_DEVICE_ID ; 
 scalar_t__ BCM58XX_DEVICE_ID ; 
 scalar_t__ BCM7278_DEVICE_ID ; 
 scalar_t__ BCM7445_DEVICE_ID ; 
 scalar_t__ BRCM_PSEUDO_PHY_ADDR ; 
 int EIO ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int REG_MII_ADDR ; 
 int REG_MII_ADDR_READ ; 
 int REG_MII_ADDR_WRITE ; 
 int REG_MII_DATA0 ; 
 int REG_MII_DATA1 ; 
 int REG_MII_PAGE ; 
 int REG_MII_PAGE_ENABLE ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  b53_mdio_ops ; 
 struct b53_device* b53_switch_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct mii_bus*) ; 
 int b53_switch_register (struct b53_device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct b53_device* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct b53_device*) ; 
 int /*<<< orphan*/  dsa_unregister_switch (struct dsa_switch*) ; 
 int ether_addr_to_u64 (int /*<<< orphan*/ ) ; 
 int mdiobus_read (struct mii_bus*,int /*<<< orphan*/ ,int) ; 
 int mdiobus_read_nested (struct mii_bus*,int,int) ; 
 int mdiobus_write_nested (struct mii_bus*,int,int,int) ; 
 int /*<<< orphan*/  memset (struct b53_arl_entry*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ of_machine_is_compatible (char*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  u64_to_ether_addr (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline int is5325(struct b53_device *dev)
{
	return dev->chip_id == BCM5325_DEVICE_ID;
}

__attribute__((used)) static inline int is5365(struct b53_device *dev)
{
#ifdef CONFIG_BCM47XX
	return dev->chip_id == BCM5365_DEVICE_ID;
#else
	return 0;
#endif
}

__attribute__((used)) static inline int is5397_98(struct b53_device *dev)
{
	return dev->chip_id == BCM5397_DEVICE_ID ||
		dev->chip_id == BCM5398_DEVICE_ID;
}

__attribute__((used)) static inline int is539x(struct b53_device *dev)
{
	return dev->chip_id == BCM5395_DEVICE_ID ||
		dev->chip_id == BCM5397_DEVICE_ID ||
		dev->chip_id == BCM5398_DEVICE_ID;
}

__attribute__((used)) static inline int is531x5(struct b53_device *dev)
{
	return dev->chip_id == BCM53115_DEVICE_ID ||
		dev->chip_id == BCM53125_DEVICE_ID ||
		dev->chip_id == BCM53128_DEVICE_ID;
}

__attribute__((used)) static inline int is63xx(struct b53_device *dev)
{
#ifdef CONFIG_BCM63XX
	return dev->chip_id == BCM63XX_DEVICE_ID;
#else
	return 0;
#endif
}

__attribute__((used)) static inline int is5301x(struct b53_device *dev)
{
	return dev->chip_id == BCM53010_DEVICE_ID ||
		dev->chip_id == BCM53011_DEVICE_ID ||
		dev->chip_id == BCM53012_DEVICE_ID ||
		dev->chip_id == BCM53018_DEVICE_ID ||
		dev->chip_id == BCM53019_DEVICE_ID;
}

__attribute__((used)) static inline int is58xx(struct b53_device *dev)
{
	return dev->chip_id == BCM58XX_DEVICE_ID ||
		dev->chip_id == BCM583XX_DEVICE_ID ||
		dev->chip_id == BCM7445_DEVICE_ID ||
		dev->chip_id == BCM7278_DEVICE_ID;
}

__attribute__((used)) static inline void b53_switch_remove(struct b53_device *dev)
{
	dsa_unregister_switch(dev->ds);
}

__attribute__((used)) static inline void b53_arl_to_entry(struct b53_arl_entry *ent,
				    u64 mac_vid, u32 fwd_entry)
{
	memset(ent, 0, sizeof(*ent));
	ent->port = fwd_entry & ARLTBL_DATA_PORT_ID_MASK;
	ent->is_valid = !!(fwd_entry & ARLTBL_VALID);
	ent->is_age = !!(fwd_entry & ARLTBL_AGE);
	ent->is_static = !!(fwd_entry & ARLTBL_STATIC);
	u64_to_ether_addr(mac_vid, ent->mac);
	ent->vid = mac_vid >> ARLTBL_VID_S;
}

__attribute__((used)) static inline void b53_arl_from_entry(u64 *mac_vid, u32 *fwd_entry,
				      const struct b53_arl_entry *ent)
{
	*mac_vid = ether_addr_to_u64(ent->mac);
	*mac_vid |= (u64)(ent->vid & ARLTBL_VID_MASK) << ARLTBL_VID_S;
	*fwd_entry = ent->port & ARLTBL_DATA_PORT_ID_MASK;
	if (ent->is_valid)
		*fwd_entry |= ARLTBL_VALID;
	if (ent->is_static)
		*fwd_entry |= ARLTBL_STATIC;
	if (ent->is_age)
		*fwd_entry |= ARLTBL_AGE;
}

__attribute__((used)) static inline int b53_switch_get_reset_gpio(struct b53_device *dev)
{
	return -ENOENT;
}

__attribute__((used)) static int b53_mdio_op(struct b53_device *dev, u8 page, u8 reg, u16 op)
{
	int i;
	u16 v;
	int ret;
	struct mii_bus *bus = dev->priv;

	if (dev->current_page != page) {
		/* set page number */
		v = (page << 8) | REG_MII_PAGE_ENABLE;
		ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
					   REG_MII_PAGE, v);
		if (ret)
			return ret;
		dev->current_page = page;
	}

	/* set register address */
	v = (reg << 8) | op;
	ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR, REG_MII_ADDR, v);
	if (ret)
		return ret;

	/* check if operation completed */
	for (i = 0; i < 5; ++i) {
		v = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
					REG_MII_ADDR);
		if (!(v & (REG_MII_ADDR_WRITE | REG_MII_ADDR_READ)))
			break;
		usleep_range(10, 100);
	}

	if (WARN_ON(i == 5))
		return -EIO;

	return 0;
}

__attribute__((used)) static int b53_mdio_read8(struct b53_device *dev, u8 page, u8 reg, u8 *val)
{
	struct mii_bus *bus = dev->priv;
	int ret;

	ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
	if (ret)
		return ret;

	*val = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
				   REG_MII_DATA0) & 0xff;

	return 0;
}

__attribute__((used)) static int b53_mdio_read16(struct b53_device *dev, u8 page, u8 reg, u16 *val)
{
	struct mii_bus *bus = dev->priv;
	int ret;

	ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
	if (ret)
		return ret;

	*val = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR, REG_MII_DATA0);

	return 0;
}

__attribute__((used)) static int b53_mdio_read32(struct b53_device *dev, u8 page, u8 reg, u32 *val)
{
	struct mii_bus *bus = dev->priv;
	int ret;

	ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
	if (ret)
		return ret;

	*val = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR, REG_MII_DATA0);
	*val |= mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
				    REG_MII_DATA1) << 16;

	return 0;
}

__attribute__((used)) static int b53_mdio_read48(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
	struct mii_bus *bus = dev->priv;
	u64 temp = 0;
	int i;
	int ret;

	ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
	if (ret)
		return ret;

	for (i = 2; i >= 0; i--) {
		temp <<= 16;
		temp |= mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
				     REG_MII_DATA0 + i);
	}

	*val = temp;

	return 0;
}

__attribute__((used)) static int b53_mdio_read64(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
	struct mii_bus *bus = dev->priv;
	u64 temp = 0;
	int i;
	int ret;

	ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
	if (ret)
		return ret;

	for (i = 3; i >= 0; i--) {
		temp <<= 16;
		temp |= mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
					    REG_MII_DATA0 + i);
	}

	*val = temp;

	return 0;
}

__attribute__((used)) static int b53_mdio_write8(struct b53_device *dev, u8 page, u8 reg, u8 value)
{
	struct mii_bus *bus = dev->priv;
	int ret;

	ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
				   REG_MII_DATA0, value);
	if (ret)
		return ret;

	return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}

__attribute__((used)) static int b53_mdio_write16(struct b53_device *dev, u8 page, u8 reg,
			    u16 value)
{
	struct mii_bus *bus = dev->priv;
	int ret;

	ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
				   REG_MII_DATA0, value);
	if (ret)
		return ret;

	return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}

__attribute__((used)) static int b53_mdio_write32(struct b53_device *dev, u8 page, u8 reg,
			    u32 value)
{
	struct mii_bus *bus = dev->priv;
	unsigned int i;
	u32 temp = value;

	for (i = 0; i < 2; i++) {
		int ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
					       REG_MII_DATA0 + i,
					       temp & 0xffff);
		if (ret)
			return ret;
		temp >>= 16;
	}

	return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}

__attribute__((used)) static int b53_mdio_write48(struct b53_device *dev, u8 page, u8 reg,
			    u64 value)
{
	struct mii_bus *bus = dev->priv;
	unsigned int i;
	u64 temp = value;

	for (i = 0; i < 3; i++) {
		int ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
					       REG_MII_DATA0 + i,
					       temp & 0xffff);
		if (ret)
			return ret;
		temp >>= 16;
	}

	return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}

__attribute__((used)) static int b53_mdio_write64(struct b53_device *dev, u8 page, u8 reg,
			    u64 value)
{
	struct mii_bus *bus = dev->priv;
	unsigned int i;
	u64 temp = value;

	for (i = 0; i < 4; i++) {
		int ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
					       REG_MII_DATA0 + i,
					       temp & 0xffff);
		if (ret)
			return ret;
		temp >>= 16;
	}

	return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}

__attribute__((used)) static int b53_mdio_phy_read16(struct b53_device *dev, int addr, int reg,
			       u16 *value)
{
	struct mii_bus *bus = dev->priv;

	*value = mdiobus_read_nested(bus, addr, reg);

	return 0;
}

__attribute__((used)) static int b53_mdio_phy_write16(struct b53_device *dev, int addr, int reg,
				u16 value)
{
	struct mii_bus *bus = dev->bus;

	return mdiobus_write_nested(bus, addr, reg, value);
}

__attribute__((used)) static int b53_mdio_probe(struct mdio_device *mdiodev)
{
	struct b53_device *dev;
	u32 phy_id;
	int ret;

	/* allow the generic PHY driver to take over the non-management MDIO
	 * addresses
	 */
	if (mdiodev->addr != BRCM_PSEUDO_PHY_ADDR && mdiodev->addr != 0) {
		dev_err(&mdiodev->dev, "leaving address %d to PHY\n",
			mdiodev->addr);
		return -ENODEV;
	}

	/* read the first port's id */
	phy_id = mdiobus_read(mdiodev->bus, 0, 2) << 16;
	phy_id |= mdiobus_read(mdiodev->bus, 0, 3);

	/* BCM5325, BCM539x (OUI_1)
	 * BCM53125, BCM53128 (OUI_2)
	 * BCM5365 (OUI_3)
	 */
	if ((phy_id & 0xfffffc00) != B53_BRCM_OUI_1 &&
	    (phy_id & 0xfffffc00) != B53_BRCM_OUI_2 &&
	    (phy_id & 0xfffffc00) != B53_BRCM_OUI_3 &&
	    (phy_id & 0xfffffc00) != B53_BRCM_OUI_4) {
		dev_err(&mdiodev->dev, "Unsupported device: 0x%08x\n", phy_id);
		return -ENODEV;
	}

	/* First probe will come from SWITCH_MDIO controller on the 7445D0
	 * switch, which will conflict with the 7445 integrated switch
	 * pseudo-phy (we end-up programming both). In that case, we return
	 * -EPROBE_DEFER for the first time we get here, and wait until we come
	 * back with the slave MDIO bus which has the correct indirection
	 * layer setup
	 */
	if (of_machine_is_compatible("brcm,bcm7445d0") &&
	    strcmp(mdiodev->bus->name, "sf2 slave mii"))
		return -EPROBE_DEFER;

	dev = b53_switch_alloc(&mdiodev->dev, &b53_mdio_ops, mdiodev->bus);
	if (!dev)
		return -ENOMEM;

	/* we don't use page 0xff, so force a page set */
	dev->current_page = 0xff;
	dev->bus = mdiodev->bus;

	dev_set_drvdata(&mdiodev->dev, dev);

	ret = b53_switch_register(dev);
	if (ret) {
		dev_err(&mdiodev->dev, "failed to register switch: %i\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static void b53_mdio_remove(struct mdio_device *mdiodev)
{
	struct b53_device *dev = dev_get_drvdata(&mdiodev->dev);
	struct dsa_switch *ds = dev->ds;

	dsa_unregister_switch(ds);
}


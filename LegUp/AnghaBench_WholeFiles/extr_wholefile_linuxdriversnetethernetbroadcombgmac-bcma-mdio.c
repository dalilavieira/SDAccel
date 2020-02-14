#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct mii_bus {char* name; int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int) ;int (* reset ) (struct mii_bus*) ;int phy_mask; int /*<<< orphan*/ * parent; struct bgmac* priv; int /*<<< orphan*/  id; } ;
struct TYPE_9__ {struct bcma_device* core; } ;
struct bgmac {int (* read ) (struct bgmac*,int) ;int (* idm_read ) (struct bgmac*,int) ;int (* clk_enabled ) (struct bgmac*) ;int (* get_bus_clock ) (struct bgmac*) ;int (* phy_connect ) (struct bgmac*) ;int phyaddr; TYPE_4__ bcma; int /*<<< orphan*/ * dev; TYPE_3__* net_dev; int /*<<< orphan*/  (* cmn_maskset32 ) (struct bgmac*,int,int,int) ;int /*<<< orphan*/  (* cco_ctl_maskset ) (struct bgmac*,int,int,int) ;int /*<<< orphan*/  (* clk_enable ) (struct bgmac*,int) ;int /*<<< orphan*/  (* idm_write ) (struct bgmac*,int,int) ;int /*<<< orphan*/  (* write ) (struct bgmac*,int,int) ;} ;
struct bcma_drv_cc {int dummy; } ;
struct TYPE_6__ {scalar_t__ id; } ;
struct bcma_device {int core_unit; int /*<<< orphan*/  dev; TYPE_5__* bus; TYPE_1__ id; } ;
struct bcma_chipinfo {scalar_t__ id; int pkg; } ;
struct TYPE_7__ {struct bcma_device* core; } ;
struct TYPE_10__ {int num; struct bcma_drv_cc drv_cc; struct bcma_chipinfo chipinfo; TYPE_2__ drv_gmac_cmn; } ;
struct TYPE_8__ {scalar_t__ phydev; } ;

/* Variables and functions */
 scalar_t__ BCMA_CHIP_ID_BCM4749 ; 
 scalar_t__ BCMA_CHIP_ID_BCM5356 ; 
 scalar_t__ BCMA_CHIP_ID_BCM5357 ; 
 scalar_t__ BCMA_CHIP_ID_BCM53572 ; 
 scalar_t__ BCMA_CORE_4706_MAC_GBIT ; 
 scalar_t__ BCMA_GMAC_CMN_PA_ADDR_MASK ; 
 int BCMA_GMAC_CMN_PA_ADDR_SHIFT ; 
 int BCMA_GMAC_CMN_PA_DATA_MASK ; 
 scalar_t__ BCMA_GMAC_CMN_PA_REG_MASK ; 
 int BCMA_GMAC_CMN_PA_REG_SHIFT ; 
 int BCMA_GMAC_CMN_PA_START ; 
 int BCMA_GMAC_CMN_PA_WRITE ; 
 int BCMA_GMAC_CMN_PC_EPA_MASK ; 
 scalar_t__ BCMA_GMAC_CMN_PC_MCT_MASK ; 
 scalar_t__ BCMA_GMAC_CMN_PC_MCT_SHIFT ; 
 scalar_t__ BCMA_GMAC_CMN_PC_MTE ; 
 int BCMA_GMAC_CMN_PHY_ACCESS ; 
 int BCMA_GMAC_CMN_PHY_CTL ; 
 int BGMAC_INT_STATUS ; 
 int BGMAC_IS_MDIO ; 
 scalar_t__ BGMAC_PA_ADDR_MASK ; 
 int BGMAC_PA_ADDR_SHIFT ; 
 int BGMAC_PA_DATA_MASK ; 
 scalar_t__ BGMAC_PA_REG_MASK ; 
 int BGMAC_PA_REG_SHIFT ; 
 int BGMAC_PA_START ; 
 int BGMAC_PA_WRITE ; 
 int BGMAC_PC_EPA_MASK ; 
 scalar_t__ BGMAC_PC_MCT_MASK ; 
 scalar_t__ BGMAC_PC_MCT_SHIFT ; 
 scalar_t__ BGMAC_PC_MTE ; 
 int BGMAC_PHY_ACCESS ; 
 int BGMAC_PHY_CNTL ; 
 int BGMAC_PHY_NOREGS ; 
 int BMCR_RESET ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int ENOMEM ; 
 struct mii_bus* ERR_PTR (int) ; 
 int ETIMEDOUT ; 
 int MII_BMCR ; 
 int /*<<< orphan*/  bcma_chipco_chipctl_maskset (struct bcma_drv_cc*,int,int,int /*<<< orphan*/ ) ; 
 int bcma_read32 (struct bcma_device*,int) ; 
 int /*<<< orphan*/  bcma_write32 (struct bcma_device*,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct mii_bus* mdiobus_alloc () ; 
 int /*<<< orphan*/  mdiobus_free (struct mii_bus*) ; 
 int mdiobus_register (struct mii_bus*) ; 
 int /*<<< orphan*/  mdiobus_unregister (struct mii_bus*) ; 
 int /*<<< orphan*/  phy_init_hw (scalar_t__) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,char*,int,int) ; 
 int stub1 (struct bgmac*,int) ; 
 int stub10 (struct bgmac*) ; 
 int /*<<< orphan*/  stub2 (struct bgmac*,int,int) ; 
 int stub3 (struct bgmac*,int) ; 
 int /*<<< orphan*/  stub4 (struct bgmac*,int,int) ; 
 int stub5 (struct bgmac*) ; 
 int /*<<< orphan*/  stub6 (struct bgmac*,int) ; 
 int /*<<< orphan*/  stub7 (struct bgmac*,int,int,int) ; 
 int stub8 (struct bgmac*) ; 
 int /*<<< orphan*/  stub9 (struct bgmac*,int,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline u32 bgmac_read(struct bgmac *bgmac, u16 offset)
{
	return bgmac->read(bgmac, offset);
}

__attribute__((used)) static inline void bgmac_write(struct bgmac *bgmac, u16 offset, u32 value)
{
	bgmac->write(bgmac, offset, value);
}

__attribute__((used)) static inline u32 bgmac_idm_read(struct bgmac *bgmac, u16 offset)
{
	return bgmac->idm_read(bgmac, offset);
}

__attribute__((used)) static inline void bgmac_idm_write(struct bgmac *bgmac, u16 offset, u32 value)
{
	bgmac->idm_write(bgmac, offset, value);
}

__attribute__((used)) static inline bool bgmac_clk_enabled(struct bgmac *bgmac)
{
	return bgmac->clk_enabled(bgmac);
}

__attribute__((used)) static inline void bgmac_clk_enable(struct bgmac *bgmac, u32 flags)
{
	bgmac->clk_enable(bgmac, flags);
}

__attribute__((used)) static inline void bgmac_cco_ctl_maskset(struct bgmac *bgmac, u32 offset,
					 u32 mask, u32 set)
{
	bgmac->cco_ctl_maskset(bgmac, offset, mask, set);
}

__attribute__((used)) static inline u32 bgmac_get_bus_clock(struct bgmac *bgmac)
{
	return bgmac->get_bus_clock(bgmac);
}

__attribute__((used)) static inline void bgmac_cmn_maskset32(struct bgmac *bgmac, u16 offset,
				       u32 mask, u32 set)
{
	bgmac->cmn_maskset32(bgmac, offset, mask, set);
}

__attribute__((used)) static inline void bgmac_maskset(struct bgmac *bgmac, u16 offset, u32 mask,
				   u32 set)
{
	bgmac_write(bgmac, offset, (bgmac_read(bgmac, offset) & mask) | set);
}

__attribute__((used)) static inline void bgmac_mask(struct bgmac *bgmac, u16 offset, u32 mask)
{
	bgmac_maskset(bgmac, offset, mask, 0);
}

__attribute__((used)) static inline void bgmac_set(struct bgmac *bgmac, u16 offset, u32 set)
{
	bgmac_maskset(bgmac, offset, ~0, set);
}

__attribute__((used)) static inline int bgmac_phy_connect(struct bgmac *bgmac)
{
	return bgmac->phy_connect(bgmac);
}

__attribute__((used)) static bool bcma_mdio_wait_value(struct bcma_device *core, u16 reg, u32 mask,
				 u32 value, int timeout)
{
	u32 val;
	int i;

	for (i = 0; i < timeout / 10; i++) {
		val = bcma_read32(core, reg);
		if ((val & mask) == value)
			return true;
		udelay(10);
	}
	dev_err(&core->dev, "Timeout waiting for reg 0x%X\n", reg);
	return false;
}

__attribute__((used)) static u16 bcma_mdio_phy_read(struct bgmac *bgmac, u8 phyaddr, u8 reg)
{
	struct bcma_device *core;
	u16 phy_access_addr;
	u16 phy_ctl_addr;
	u32 tmp;

	BUILD_BUG_ON(BGMAC_PA_DATA_MASK != BCMA_GMAC_CMN_PA_DATA_MASK);
	BUILD_BUG_ON(BGMAC_PA_ADDR_MASK != BCMA_GMAC_CMN_PA_ADDR_MASK);
	BUILD_BUG_ON(BGMAC_PA_ADDR_SHIFT != BCMA_GMAC_CMN_PA_ADDR_SHIFT);
	BUILD_BUG_ON(BGMAC_PA_REG_MASK != BCMA_GMAC_CMN_PA_REG_MASK);
	BUILD_BUG_ON(BGMAC_PA_REG_SHIFT != BCMA_GMAC_CMN_PA_REG_SHIFT);
	BUILD_BUG_ON(BGMAC_PA_WRITE != BCMA_GMAC_CMN_PA_WRITE);
	BUILD_BUG_ON(BGMAC_PA_START != BCMA_GMAC_CMN_PA_START);
	BUILD_BUG_ON(BGMAC_PC_EPA_MASK != BCMA_GMAC_CMN_PC_EPA_MASK);
	BUILD_BUG_ON(BGMAC_PC_MCT_MASK != BCMA_GMAC_CMN_PC_MCT_MASK);
	BUILD_BUG_ON(BGMAC_PC_MCT_SHIFT != BCMA_GMAC_CMN_PC_MCT_SHIFT);
	BUILD_BUG_ON(BGMAC_PC_MTE != BCMA_GMAC_CMN_PC_MTE);

	if (bgmac->bcma.core->id.id == BCMA_CORE_4706_MAC_GBIT) {
		core = bgmac->bcma.core->bus->drv_gmac_cmn.core;
		phy_access_addr = BCMA_GMAC_CMN_PHY_ACCESS;
		phy_ctl_addr = BCMA_GMAC_CMN_PHY_CTL;
	} else {
		core = bgmac->bcma.core;
		phy_access_addr = BGMAC_PHY_ACCESS;
		phy_ctl_addr = BGMAC_PHY_CNTL;
	}

	tmp = bcma_read32(core, phy_ctl_addr);
	tmp &= ~BGMAC_PC_EPA_MASK;
	tmp |= phyaddr;
	bcma_write32(core, phy_ctl_addr, tmp);

	tmp = BGMAC_PA_START;
	tmp |= phyaddr << BGMAC_PA_ADDR_SHIFT;
	tmp |= reg << BGMAC_PA_REG_SHIFT;
	bcma_write32(core, phy_access_addr, tmp);

	if (!bcma_mdio_wait_value(core, phy_access_addr, BGMAC_PA_START, 0,
				  1000)) {
		dev_err(&core->dev, "Reading PHY %d register 0x%X failed\n",
			phyaddr, reg);
		return 0xffff;
	}

	return bcma_read32(core, phy_access_addr) & BGMAC_PA_DATA_MASK;
}

__attribute__((used)) static int bcma_mdio_phy_write(struct bgmac *bgmac, u8 phyaddr, u8 reg,
			       u16 value)
{
	struct bcma_device *core;
	u16 phy_access_addr;
	u16 phy_ctl_addr;
	u32 tmp;

	if (bgmac->bcma.core->id.id == BCMA_CORE_4706_MAC_GBIT) {
		core = bgmac->bcma.core->bus->drv_gmac_cmn.core;
		phy_access_addr = BCMA_GMAC_CMN_PHY_ACCESS;
		phy_ctl_addr = BCMA_GMAC_CMN_PHY_CTL;
	} else {
		core = bgmac->bcma.core;
		phy_access_addr = BGMAC_PHY_ACCESS;
		phy_ctl_addr = BGMAC_PHY_CNTL;
	}

	tmp = bcma_read32(core, phy_ctl_addr);
	tmp &= ~BGMAC_PC_EPA_MASK;
	tmp |= phyaddr;
	bcma_write32(core, phy_ctl_addr, tmp);

	bcma_write32(bgmac->bcma.core, BGMAC_INT_STATUS, BGMAC_IS_MDIO);
	if (bcma_read32(bgmac->bcma.core, BGMAC_INT_STATUS) & BGMAC_IS_MDIO)
		dev_warn(&core->dev, "Error setting MDIO int\n");

	tmp = BGMAC_PA_START;
	tmp |= BGMAC_PA_WRITE;
	tmp |= phyaddr << BGMAC_PA_ADDR_SHIFT;
	tmp |= reg << BGMAC_PA_REG_SHIFT;
	tmp |= value;
	bcma_write32(core, phy_access_addr, tmp);

	if (!bcma_mdio_wait_value(core, phy_access_addr, BGMAC_PA_START, 0,
				  1000)) {
		dev_err(&core->dev, "Writing to PHY %d register 0x%X failed\n",
			phyaddr, reg);
		return -ETIMEDOUT;
	}

	return 0;
}

__attribute__((used)) static void bcma_mdio_phy_init(struct bgmac *bgmac)
{
	struct bcma_chipinfo *ci = &bgmac->bcma.core->bus->chipinfo;
	u8 i;

	/* For some legacy hardware we do chipset-based PHY initialization here
	 * without even detecting PHY ID. It's hacky and should be cleaned as
	 * soon as someone can test it.
	 */
	if (ci->id == BCMA_CHIP_ID_BCM5356) {
		for (i = 0; i < 5; i++) {
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x008b);
			bcma_mdio_phy_write(bgmac, i, 0x15, 0x0100);
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x000f);
			bcma_mdio_phy_write(bgmac, i, 0x12, 0x2aaa);
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x000b);
		}
		return;
	}
	if ((ci->id == BCMA_CHIP_ID_BCM5357 && ci->pkg != 10) ||
	    (ci->id == BCMA_CHIP_ID_BCM4749 && ci->pkg != 10) ||
	    (ci->id == BCMA_CHIP_ID_BCM53572 && ci->pkg != 9)) {
		struct bcma_drv_cc *cc = &bgmac->bcma.core->bus->drv_cc;

		bcma_chipco_chipctl_maskset(cc, 2, ~0xc0000000, 0);
		bcma_chipco_chipctl_maskset(cc, 4, ~0x80000000, 0);
		for (i = 0; i < 5; i++) {
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x000f);
			bcma_mdio_phy_write(bgmac, i, 0x16, 0x5284);
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x000b);
			bcma_mdio_phy_write(bgmac, i, 0x17, 0x0010);
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x000f);
			bcma_mdio_phy_write(bgmac, i, 0x16, 0x5296);
			bcma_mdio_phy_write(bgmac, i, 0x17, 0x1073);
			bcma_mdio_phy_write(bgmac, i, 0x17, 0x9073);
			bcma_mdio_phy_write(bgmac, i, 0x16, 0x52b6);
			bcma_mdio_phy_write(bgmac, i, 0x17, 0x9273);
			bcma_mdio_phy_write(bgmac, i, 0x1f, 0x000b);
		}
		return;
	}

	/* For all other hw do initialization using PHY subsystem. */
	if (bgmac->net_dev && bgmac->net_dev->phydev)
		phy_init_hw(bgmac->net_dev->phydev);
}

__attribute__((used)) static int bcma_mdio_phy_reset(struct mii_bus *bus)
{
	struct bgmac *bgmac = bus->priv;
	u8 phyaddr = bgmac->phyaddr;

	if (phyaddr == BGMAC_PHY_NOREGS)
		return 0;

	bcma_mdio_phy_write(bgmac, phyaddr, MII_BMCR, BMCR_RESET);
	udelay(100);
	if (bcma_mdio_phy_read(bgmac, phyaddr, MII_BMCR) & BMCR_RESET)
		dev_err(bgmac->dev, "PHY reset failed\n");
	bcma_mdio_phy_init(bgmac);

	return 0;
}

__attribute__((used)) static int bcma_mdio_mii_read(struct mii_bus *bus, int mii_id, int regnum)
{
	return bcma_mdio_phy_read(bus->priv, mii_id, regnum);
}

__attribute__((used)) static int bcma_mdio_mii_write(struct mii_bus *bus, int mii_id, int regnum,
			       u16 value)
{
	return bcma_mdio_phy_write(bus->priv, mii_id, regnum, value);
}

struct mii_bus *bcma_mdio_mii_register(struct bgmac *bgmac)
{
	struct bcma_device *core = bgmac->bcma.core;
	struct mii_bus *mii_bus;
	int err;

	mii_bus = mdiobus_alloc();
	if (!mii_bus) {
		err = -ENOMEM;
		goto err;
	}

	mii_bus->name = "bcma_mdio mii bus";
	sprintf(mii_bus->id, "%s-%d-%d", "bcma_mdio", core->bus->num,
		core->core_unit);
	mii_bus->priv = bgmac;
	mii_bus->read = bcma_mdio_mii_read;
	mii_bus->write = bcma_mdio_mii_write;
	mii_bus->reset = bcma_mdio_phy_reset;
	mii_bus->parent = &core->dev;
	mii_bus->phy_mask = ~(1 << bgmac->phyaddr);

	err = mdiobus_register(mii_bus);
	if (err) {
		dev_err(&core->dev, "Registration of mii bus failed\n");
		goto err_free_bus;
	}

	return mii_bus;

err_free_bus:
	mdiobus_free(mii_bus);
err:
	return ERR_PTR(err);
}

void bcma_mdio_mii_unregister(struct mii_bus *mii_bus)
{
	if (!mii_bus)
		return;

	mdiobus_unregister(mii_bus);
	mdiobus_free(mii_bus);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct ssb_sprom {int boardflags_lo; int /*<<< orphan*/  et2phyaddr; int /*<<< orphan*/  et1phyaddr; int /*<<< orphan*/  et0phyaddr; int /*<<< orphan*/ * et2mac; int /*<<< orphan*/ * et1mac; int /*<<< orphan*/ * et0mac; } ;
struct phy_device {int /*<<< orphan*/  dev_flags; TYPE_3__* drv; int /*<<< orphan*/  id; } ;
struct mii_bus {int /*<<< orphan*/  dev_flags; TYPE_3__* drv; int /*<<< orphan*/  id; } ;
struct TYPE_10__ {scalar_t__ cmn; struct bcma_device* core; } ;
struct bgmac {int (* read ) (struct bgmac*,int /*<<< orphan*/ ) ;void (* write ) (struct bgmac*,int /*<<< orphan*/ ,int) ;int (* idm_read ) (struct bgmac*,int /*<<< orphan*/ ) ;void (* idm_write ) (struct bgmac*,int /*<<< orphan*/ ,int) ;int (* clk_enabled ) (struct bgmac*) ;void (* clk_enable ) (struct bgmac*,int) ;void (* cco_ctl_maskset ) (struct bgmac*,int,int,int) ;int (* get_bus_clock ) (struct bgmac*) ;void (* cmn_maskset32 ) (struct bgmac*,int /*<<< orphan*/ ,int,int) ;int (* phy_connect ) (struct bgmac*) ;int has_robosw; struct phy_device* mii_bus; int /*<<< orphan*/  feature_flags; TYPE_7__* dev; int /*<<< orphan*/  phyaddr; TYPE_1__ bcma; TYPE_6__* net_dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  dma_dev; } ;
struct bcma_drv_cc {int dummy; } ;
struct TYPE_14__ {scalar_t__ id; int rev; } ;
struct bcma_device {int core_unit; TYPE_5__ id; TYPE_4__* bus; int /*<<< orphan*/  irq; int /*<<< orphan*/  dma_dev; int /*<<< orphan*/  dev; } ;
struct bcma_chipinfo {int id; int pkg; } ;
typedef  int /*<<< orphan*/  bus_id ;
struct TYPE_16__ {scalar_t__ of_node; } ;
struct TYPE_15__ {int /*<<< orphan*/  dev_addr; } ;
struct TYPE_11__ {scalar_t__ core; } ;
struct TYPE_13__ {scalar_t__ hosttype; TYPE_2__ drv_gmac_cmn; struct ssb_sprom sprom; struct bcma_chipinfo chipinfo; struct bcma_drv_cc drv_cc; } ;
struct TYPE_12__ {int phy_id; int phy_id_mask; } ;

/* Variables and functions */
#define  BCMA_CHIP_ID_BCM4707 136 
#define  BCMA_CHIP_ID_BCM47094 135 
#define  BCMA_CHIP_ID_BCM4716 134 
#define  BCMA_CHIP_ID_BCM47162 133 
#define  BCMA_CHIP_ID_BCM4749 132 
#define  BCMA_CHIP_ID_BCM53018 131 
#define  BCMA_CHIP_ID_BCM5357 130 
#define  BCMA_CHIP_ID_BCM53572 129 
#define  BCMA_CHIP_ID_BCM53573 128 
 scalar_t__ BCMA_CORE_4706_MAC_GBIT ; 
 scalar_t__ BCMA_HOSTTYPE_PCI ; 
 int BCMA_PKG_ID_BCM47186 ; 
 int BCMA_PKG_ID_BCM47188 ; 
 int BCMA_PKG_ID_BCM47189 ; 
 int BCMA_PKG_ID_BCM5358 ; 
 int BGMAC_BFL_ENETADM ; 
 int BGMAC_BFL_ENETROBO ; 
 int /*<<< orphan*/  BGMAC_FEAT_CC4_IF_SW_TYPE ; 
 int /*<<< orphan*/  BGMAC_FEAT_CC4_IF_SW_TYPE_RGMII ; 
 int /*<<< orphan*/  BGMAC_FEAT_CC7_IF_TYPE_RGMII ; 
 int /*<<< orphan*/  BGMAC_FEAT_CLKCTLST ; 
 int /*<<< orphan*/  BGMAC_FEAT_CMDCFG_SR_REV4 ; 
 int /*<<< orphan*/  BGMAC_FEAT_CMN_PHY_CTL ; 
 int /*<<< orphan*/  BGMAC_FEAT_FLW_CTRL1 ; 
 int /*<<< orphan*/  BGMAC_FEAT_FLW_CTRL2 ; 
 int /*<<< orphan*/  BGMAC_FEAT_FORCE_SPEED_2500 ; 
 int /*<<< orphan*/  BGMAC_FEAT_IOST_ATTACHED ; 
 int /*<<< orphan*/  BGMAC_FEAT_IRQ_ID_OOB_6 ; 
 int /*<<< orphan*/  BGMAC_FEAT_MISC_PLL_REQ ; 
 int /*<<< orphan*/  BGMAC_FEAT_NO_CLR_MIB ; 
 int /*<<< orphan*/  BGMAC_FEAT_NO_RESET ; 
 int /*<<< orphan*/  BGMAC_FEAT_RX_MASK_SETUP ; 
 int /*<<< orphan*/  BGMAC_FEAT_SET_RXQ_CLK ; 
 int /*<<< orphan*/  BGMAC_FEAT_SW_TYPE_EPHYRMII ; 
 int /*<<< orphan*/  BGMAC_FEAT_SW_TYPE_PHY ; 
 int /*<<< orphan*/  BGMAC_FEAT_SW_TYPE_RGMII ; 
 int /*<<< orphan*/  BGMAC_FEAT_TX_MASK_SETUP ; 
 int /*<<< orphan*/  BGMAC_PHY_MASK ; 
 int /*<<< orphan*/  BGMAC_PHY_NOREGS ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 scalar_t__ IS_ERR (struct phy_device*) ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 int /*<<< orphan*/  PHY_BRCM_EN_MASTER_MODE ; 
 int PHY_ID_BCM54210E ; 
 char* PHY_ID_FMT ; 
 int /*<<< orphan*/  PHY_INTERFACE_MODE_MII ; 
 int PTR_ERR (struct phy_device*) ; 
 int bcma_aread32 (struct bcma_device*,int /*<<< orphan*/ ) ; 
 void bcma_awrite32 (struct bcma_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bcma_chipco_chipctl_maskset (struct bcma_drv_cc*,int,int,int) ; 
 int /*<<< orphan*/  bcma_core_enable (struct bcma_device*,int) ; 
 int bcma_core_is_enabled (struct bcma_device*) ; 
 struct bgmac* bcma_get_drvdata (struct bcma_device*) ; 
 int /*<<< orphan*/  bcma_maskset32 (scalar_t__,int /*<<< orphan*/ ,int,int) ; 
 struct phy_device* bcma_mdio_mii_register (struct bgmac*) ; 
 int /*<<< orphan*/  bcma_mdio_mii_unregister (struct phy_device*) ; 
 int bcma_pmu_get_bus_clock (struct bcma_drv_cc*) ; 
 int bcma_read32 (struct bcma_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcma_set_drvdata (struct bcma_device*,struct bgmac*) ; 
 int /*<<< orphan*/  bcma_write32 (struct bcma_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bgmac_adjust_link ; 
 struct bgmac* bgmac_alloc (int /*<<< orphan*/ *) ; 
 int bgmac_enet_probe (struct bgmac*) ; 
 int /*<<< orphan*/  bgmac_enet_remove (struct bgmac*) ; 
 int bgmac_phy_connect_direct (struct bgmac*) ; 
 int /*<<< orphan*/  dev_err (TYPE_7__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_7__*,char*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_7__*,char*) ; 
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  kfree (struct bgmac*) ; 
 struct phy_device* mdiobus_get_phy (struct phy_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * of_get_mac_address (scalar_t__) ; 
 struct phy_device* phy_connect (TYPE_6__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (struct bgmac*,int /*<<< orphan*/ ) ; 
 int stub10 (struct bgmac*) ; 
 void stub2 (struct bgmac*,int /*<<< orphan*/ ,int) ; 
 int stub3 (struct bgmac*,int /*<<< orphan*/ ) ; 
 void stub4 (struct bgmac*,int /*<<< orphan*/ ,int) ; 
 int stub5 (struct bgmac*) ; 
 void stub6 (struct bgmac*,int) ; 
 void stub7 (struct bgmac*,int,int,int) ; 
 int stub8 (struct bgmac*) ; 
 void stub9 (struct bgmac*,int /*<<< orphan*/ ,int,int) ; 

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

__attribute__((used)) static inline bool bgmac_is_bcm4707_family(struct bcma_device *core)
{
	switch (core->bus->chipinfo.id) {
	case BCMA_CHIP_ID_BCM4707:
	case BCMA_CHIP_ID_BCM47094:
	case BCMA_CHIP_ID_BCM53018:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static u32 bcma_bgmac_read(struct bgmac *bgmac, u16 offset)
{
	return bcma_read32(bgmac->bcma.core, offset);
}

__attribute__((used)) static void bcma_bgmac_write(struct bgmac *bgmac, u16 offset, u32 value)
{
	bcma_write32(bgmac->bcma.core, offset, value);
}

__attribute__((used)) static u32 bcma_bgmac_idm_read(struct bgmac *bgmac, u16 offset)
{
	return bcma_aread32(bgmac->bcma.core, offset);
}

__attribute__((used)) static void bcma_bgmac_idm_write(struct bgmac *bgmac, u16 offset, u32 value)
{
	return bcma_awrite32(bgmac->bcma.core, offset, value);
}

__attribute__((used)) static bool bcma_bgmac_clk_enabled(struct bgmac *bgmac)
{
	return bcma_core_is_enabled(bgmac->bcma.core);
}

__attribute__((used)) static void bcma_bgmac_clk_enable(struct bgmac *bgmac, u32 flags)
{
	bcma_core_enable(bgmac->bcma.core, flags);
}

__attribute__((used)) static void bcma_bgmac_cco_ctl_maskset(struct bgmac *bgmac, u32 offset,
				       u32 mask, u32 set)
{
	struct bcma_drv_cc *cc = &bgmac->bcma.core->bus->drv_cc;

	bcma_chipco_chipctl_maskset(cc, offset, mask, set);
}

__attribute__((used)) static u32 bcma_bgmac_get_bus_clock(struct bgmac *bgmac)
{
	struct bcma_drv_cc *cc = &bgmac->bcma.core->bus->drv_cc;

	return bcma_pmu_get_bus_clock(cc);
}

__attribute__((used)) static void bcma_bgmac_cmn_maskset32(struct bgmac *bgmac, u16 offset, u32 mask,
				     u32 set)
{
	bcma_maskset32(bgmac->bcma.cmn, offset, mask, set);
}

__attribute__((used)) static int bcma_phy_connect(struct bgmac *bgmac)
{
	struct phy_device *phy_dev;
	char bus_id[MII_BUS_ID_SIZE + 3];

	/* Connect to the PHY */
	snprintf(bus_id, sizeof(bus_id), PHY_ID_FMT, bgmac->mii_bus->id,
		 bgmac->phyaddr);
	phy_dev = phy_connect(bgmac->net_dev, bus_id, bgmac_adjust_link,
			      PHY_INTERFACE_MODE_MII);
	if (IS_ERR(phy_dev)) {
		dev_err(bgmac->dev, "PHY connection failed\n");
		return PTR_ERR(phy_dev);
	}

	return 0;
}

__attribute__((used)) static int bgmac_probe(struct bcma_device *core)
{
	struct bcma_chipinfo *ci = &core->bus->chipinfo;
	struct ssb_sprom *sprom = &core->bus->sprom;
	struct mii_bus *mii_bus;
	struct bgmac *bgmac;
	const u8 *mac = NULL;
	int err;

	bgmac = bgmac_alloc(&core->dev);
	if (!bgmac)
		return -ENOMEM;

	bgmac->bcma.core = core;
	bgmac->dma_dev = core->dma_dev;
	bgmac->irq = core->irq;

	bcma_set_drvdata(core, bgmac);

	if (bgmac->dev->of_node)
		mac = of_get_mac_address(bgmac->dev->of_node);

	/* If no MAC address assigned via device tree, check SPROM */
	if (!mac) {
		switch (core->core_unit) {
		case 0:
			mac = sprom->et0mac;
			break;
		case 1:
			mac = sprom->et1mac;
			break;
		case 2:
			mac = sprom->et2mac;
			break;
		default:
			dev_err(bgmac->dev, "Unsupported core_unit %d\n",
				core->core_unit);
			err = -ENOTSUPP;
			goto err;
		}
	}

	ether_addr_copy(bgmac->net_dev->dev_addr, mac);

	/* On BCM4706 we need common core to access PHY */
	if (core->id.id == BCMA_CORE_4706_MAC_GBIT &&
	    !core->bus->drv_gmac_cmn.core) {
		dev_err(bgmac->dev, "GMAC CMN core not found (required for BCM4706)\n");
		err = -ENODEV;
		goto err;
	}
	bgmac->bcma.cmn = core->bus->drv_gmac_cmn.core;

	switch (core->core_unit) {
	case 0:
		bgmac->phyaddr = sprom->et0phyaddr;
		break;
	case 1:
		bgmac->phyaddr = sprom->et1phyaddr;
		break;
	case 2:
		bgmac->phyaddr = sprom->et2phyaddr;
		break;
	}
	bgmac->phyaddr &= BGMAC_PHY_MASK;
	if (bgmac->phyaddr == BGMAC_PHY_MASK) {
		dev_err(bgmac->dev, "No PHY found\n");
		err = -ENODEV;
		goto err;
	}
	dev_info(bgmac->dev, "Found PHY addr: %d%s\n", bgmac->phyaddr,
		 bgmac->phyaddr == BGMAC_PHY_NOREGS ? " (NOREGS)" : "");

	if (!bgmac_is_bcm4707_family(core) &&
	    !(ci->id == BCMA_CHIP_ID_BCM53573 && core->core_unit == 1)) {
		struct phy_device *phydev;

		mii_bus = bcma_mdio_mii_register(bgmac);
		if (IS_ERR(mii_bus)) {
			err = PTR_ERR(mii_bus);
			goto err;
		}
		bgmac->mii_bus = mii_bus;

		phydev = mdiobus_get_phy(bgmac->mii_bus, bgmac->phyaddr);
		if (ci->id == BCMA_CHIP_ID_BCM53573 && phydev &&
		    (phydev->drv->phy_id & phydev->drv->phy_id_mask) == PHY_ID_BCM54210E)
			phydev->dev_flags |= PHY_BRCM_EN_MASTER_MODE;
	}

	if (core->bus->hosttype == BCMA_HOSTTYPE_PCI) {
		dev_err(bgmac->dev, "PCI setup not implemented\n");
		err = -ENOTSUPP;
		goto err1;
	}

	bgmac->has_robosw = !!(sprom->boardflags_lo & BGMAC_BFL_ENETROBO);
	if (bgmac->has_robosw)
		dev_warn(bgmac->dev, "Support for Roboswitch not implemented\n");

	if (sprom->boardflags_lo & BGMAC_BFL_ENETADM)
		dev_warn(bgmac->dev, "Support for ADMtek ethernet switch not implemented\n");

	/* Feature Flags */
	switch (ci->id) {
	/* BCM 471X/535X family */
	case BCMA_CHIP_ID_BCM4716:
		bgmac->feature_flags |= BGMAC_FEAT_CLKCTLST;
		/* fallthrough */
	case BCMA_CHIP_ID_BCM47162:
		bgmac->feature_flags |= BGMAC_FEAT_FLW_CTRL2;
		bgmac->feature_flags |= BGMAC_FEAT_SET_RXQ_CLK;
		break;
	case BCMA_CHIP_ID_BCM5357:
	case BCMA_CHIP_ID_BCM53572:
		bgmac->feature_flags |= BGMAC_FEAT_SET_RXQ_CLK;
		bgmac->feature_flags |= BGMAC_FEAT_CLKCTLST;
		bgmac->feature_flags |= BGMAC_FEAT_FLW_CTRL1;
		bgmac->feature_flags |= BGMAC_FEAT_SW_TYPE_PHY;
		if (ci->pkg == BCMA_PKG_ID_BCM47188 ||
		    ci->pkg == BCMA_PKG_ID_BCM47186) {
			bgmac->feature_flags |= BGMAC_FEAT_SW_TYPE_RGMII;
			bgmac->feature_flags |= BGMAC_FEAT_IOST_ATTACHED;
		}
		if (ci->pkg == BCMA_PKG_ID_BCM5358)
			bgmac->feature_flags |= BGMAC_FEAT_SW_TYPE_EPHYRMII;
		break;
	case BCMA_CHIP_ID_BCM53573:
		bgmac->feature_flags |= BGMAC_FEAT_CLKCTLST;
		bgmac->feature_flags |= BGMAC_FEAT_SET_RXQ_CLK;
		if (ci->pkg == BCMA_PKG_ID_BCM47189)
			bgmac->feature_flags |= BGMAC_FEAT_IOST_ATTACHED;
		if (core->core_unit == 0) {
			bgmac->feature_flags |= BGMAC_FEAT_CC4_IF_SW_TYPE;
			if (ci->pkg == BCMA_PKG_ID_BCM47189)
				bgmac->feature_flags |=
					BGMAC_FEAT_CC4_IF_SW_TYPE_RGMII;
		} else if (core->core_unit == 1) {
			bgmac->feature_flags |= BGMAC_FEAT_IRQ_ID_OOB_6;
			bgmac->feature_flags |= BGMAC_FEAT_CC7_IF_TYPE_RGMII;
		}
		break;
	case BCMA_CHIP_ID_BCM4749:
		bgmac->feature_flags |= BGMAC_FEAT_SET_RXQ_CLK;
		bgmac->feature_flags |= BGMAC_FEAT_CLKCTLST;
		bgmac->feature_flags |= BGMAC_FEAT_FLW_CTRL1;
		bgmac->feature_flags |= BGMAC_FEAT_SW_TYPE_PHY;
		if (ci->pkg == 10) {
			bgmac->feature_flags |= BGMAC_FEAT_SW_TYPE_RGMII;
			bgmac->feature_flags |= BGMAC_FEAT_IOST_ATTACHED;
		}
		break;
	/* bcm4707_family */
	case BCMA_CHIP_ID_BCM4707:
	case BCMA_CHIP_ID_BCM47094:
	case BCMA_CHIP_ID_BCM53018:
		bgmac->feature_flags |= BGMAC_FEAT_CLKCTLST;
		bgmac->feature_flags |= BGMAC_FEAT_NO_RESET;
		bgmac->feature_flags |= BGMAC_FEAT_FORCE_SPEED_2500;
		break;
	default:
		bgmac->feature_flags |= BGMAC_FEAT_CLKCTLST;
		bgmac->feature_flags |= BGMAC_FEAT_SET_RXQ_CLK;
	}

	if (!bgmac_is_bcm4707_family(core) && core->id.rev > 2)
		bgmac->feature_flags |= BGMAC_FEAT_MISC_PLL_REQ;

	if (core->id.id == BCMA_CORE_4706_MAC_GBIT) {
		bgmac->feature_flags |= BGMAC_FEAT_CMN_PHY_CTL;
		bgmac->feature_flags |= BGMAC_FEAT_NO_CLR_MIB;
	}

	if (core->id.rev >= 4) {
		bgmac->feature_flags |= BGMAC_FEAT_CMDCFG_SR_REV4;
		bgmac->feature_flags |= BGMAC_FEAT_TX_MASK_SETUP;
		bgmac->feature_flags |= BGMAC_FEAT_RX_MASK_SETUP;
	}

	bgmac->read = bcma_bgmac_read;
	bgmac->write = bcma_bgmac_write;
	bgmac->idm_read = bcma_bgmac_idm_read;
	bgmac->idm_write = bcma_bgmac_idm_write;
	bgmac->clk_enabled = bcma_bgmac_clk_enabled;
	bgmac->clk_enable = bcma_bgmac_clk_enable;
	bgmac->cco_ctl_maskset = bcma_bgmac_cco_ctl_maskset;
	bgmac->get_bus_clock = bcma_bgmac_get_bus_clock;
	bgmac->cmn_maskset32 = bcma_bgmac_cmn_maskset32;
	if (bgmac->mii_bus)
		bgmac->phy_connect = bcma_phy_connect;
	else
		bgmac->phy_connect = bgmac_phy_connect_direct;

	err = bgmac_enet_probe(bgmac);
	if (err)
		goto err1;

	return 0;

err1:
	bcma_mdio_mii_unregister(bgmac->mii_bus);
err:
	bcma_set_drvdata(core, NULL);

	return err;
}

__attribute__((used)) static void bgmac_remove(struct bcma_device *core)
{
	struct bgmac *bgmac = bcma_get_drvdata(core);

	bcma_mdio_mii_unregister(bgmac->mii_bus);
	bgmac_enet_remove(bgmac);
	bcma_set_drvdata(core, NULL);
	kfree(bgmac);
}


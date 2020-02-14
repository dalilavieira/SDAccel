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
typedef  scalar_t__ u32 ;
struct TYPE_9__ {int (* mdio_read ) (int /*<<< orphan*/ ,int,int,int) ;int prtad; int (* mdio_write ) (int /*<<< orphan*/ ,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; int /*<<< orphan*/  mmds; int /*<<< orphan*/  dev; } ;
struct cphy {unsigned int caps; char const* desc; TYPE_4__ mdio; struct adapter* adapter; struct cphy_ops const* ops; } ;
struct port_info {struct cphy phy; } ;
struct mdio_ops {int (* read ) (int /*<<< orphan*/ ,int,int,int) ;int (* write ) (int /*<<< orphan*/ ,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; } ;
struct mc7 {unsigned int size; } ;
struct mc5 {unsigned int tcam_size; } ;
struct cphy_ops {int /*<<< orphan*/  mmds; } ;
struct TYPE_7__ {scalar_t__ variant; } ;
struct TYPE_6__ {int cclk; } ;
struct TYPE_8__ {int offload; TYPE_2__ pci; TYPE_1__ vpd; } ;
struct adapter {TYPE_3__ params; int /*<<< orphan*/  open_device_map; int /*<<< orphan*/ * port; scalar_t__ regs; } ;
struct TYPE_10__ {int caps; } ;

/* Variables and functions */
 unsigned int ADVERTISED_10000baseT_Full ; 
 unsigned int ADVERTISED_1000baseT_Full ; 
 unsigned int ADVERTISED_1000baseT_Half ; 
 unsigned int ADVERTISED_100baseT_Full ; 
 unsigned int ADVERTISED_100baseT_Half ; 
 unsigned int ADVERTISED_Asym_Pause ; 
 unsigned int ADVERTISED_Pause ; 
 unsigned int ADVERTISE_100FULL ; 
 unsigned int ADVERTISE_100HALF ; 
 unsigned int ADVERTISE_PAUSE_ASYM ; 
 unsigned int ADVERTISE_PAUSE_CAP ; 
 unsigned int ADV_10G_FULL ; 
 unsigned int ADV_1G_FULL ; 
 unsigned int ADV_1G_HALF ; 
 int AQ_1G_CTRL ; 
 int AQ_ANEG_STAT ; 
 int AQ_FW_VERSION ; 
 int AQ_IFLAG_GLOBAL ; 
 int AQ_IMASK_GLOBAL ; 
 int AQ_IMASK_PMA ; 
 int AQ_LINK_STAT ; 
 unsigned int AQ_LOWPOWER ; 
 unsigned int AQ_RESET ; 
 int AQ_XAUI_RX_CFG ; 
 int AQ_XAUI_TX_CFG ; 
 int /*<<< orphan*/  A_T3DBG_GPIO_EN ; 
 int BMCR_ANENABLE ; 
 int BMCR_ANRESTART ; 
 int BMCR_LOOPBACK ; 
 int /*<<< orphan*/  CH_DBG (struct adapter*,int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  CH_WARN (struct adapter*,char*,int,...) ; 
 int DUPLEX_FULL ; 
 int DUPLEX_HALF ; 
 unsigned int F_GPIO10_OUT_VAL ; 
 unsigned int F_GPIO6_OUT_VAL ; 
 unsigned int IMASK_GLOBAL ; 
 unsigned int IMASK_PMA ; 
 int MDIO_AN_10GBT_CTRL ; 
 int MDIO_AN_ADVERTISE ; 
 int MDIO_CTRL1 ; 
 int MDIO_CTRL1_LPOWER ; 
 int MDIO_MMD_AN ; 
 int MDIO_MMD_PHYXS ; 
 int MDIO_MMD_PMAPMD ; 
 int MDIO_MMD_VEND1 ; 
 int MDIO_STAT1 ; 
 int /*<<< orphan*/  MMIO ; 
 int /*<<< orphan*/  OFFLOAD_DEVMAP_BIT ; 
 scalar_t__ PCI_VARIANT_PCIE ; 
 int SPEED_10 ; 
 int SPEED_100 ; 
 int SPEED_1000 ; 
 int SPEED_10000 ; 
 int SUPPORTED_10000baseT_Full ; 
 int SUPPORTED_1000baseT_Full ; 
 int SUPPORTED_AUI ; 
 int SUPPORTED_Autoneg ; 
 int SUPPORTED_TP ; 
 TYPE_5__* adapter_info (struct adapter const*) ; 
 struct cphy_ops aq100x_ops ; 
 int cphy_cause_link_change ; 
 int mdio_set_flag (TYPE_4__*,int,int,int,int,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct port_info* netdev_priv (int /*<<< orphan*/ ) ; 
 scalar_t__ readl (scalar_t__) ; 
 int stub1 (int /*<<< orphan*/ ,int,int,int) ; 
 int stub2 (int /*<<< orphan*/ ,int,int,int,unsigned int) ; 
 int t3_mdio_change_bits (struct cphy*,int,int,unsigned int,unsigned int) ; 
 int t3_phy_reset (struct cphy*,int,int) ; 
 int /*<<< orphan*/  t3_set_reg_field (struct adapter*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int t3_wait_op_done_val (struct adapter*,int,scalar_t__,int,int,int,int /*<<< orphan*/ *) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline unsigned int t3_mc5_size(const struct mc5 *p)
{
	return p->tcam_size;
}

__attribute__((used)) static inline unsigned int t3_mc7_size(const struct mc7 *p)
{
	return p->size;
}

__attribute__((used)) static inline int t3_mdio_read(struct cphy *phy, int mmd, int reg,
			       unsigned int *valp)
{
	int rc = phy->mdio.mdio_read(phy->mdio.dev, phy->mdio.prtad, mmd, reg);
	*valp = (rc >= 0) ? rc : -1;
	return (rc >= 0) ? 0 : rc;
}

__attribute__((used)) static inline int t3_mdio_write(struct cphy *phy, int mmd, int reg,
				unsigned int val)
{
	return phy->mdio.mdio_write(phy->mdio.dev, phy->mdio.prtad, mmd,
				    reg, val);
}

__attribute__((used)) static inline void cphy_init(struct cphy *phy, struct adapter *adapter,
			     int phy_addr, const struct cphy_ops *phy_ops,
			     const struct mdio_ops *mdio_ops,
			      unsigned int caps, const char *desc)
{
	phy->caps = caps;
	phy->adapter = adapter;
	phy->desc = desc;
	phy->ops = phy_ops;
	if (mdio_ops) {
		phy->mdio.prtad = phy_addr;
		phy->mdio.mmds = phy_ops->mmds;
		phy->mdio.mode_support = mdio_ops->mode_support;
		phy->mdio.mdio_read = mdio_ops->read;
		phy->mdio.mdio_write = mdio_ops->write;
	}
}

__attribute__((used)) static inline u32 t3_read_reg(struct adapter *adapter, u32 reg_addr)
{
	u32 val = readl(adapter->regs + reg_addr);

	CH_DBG(adapter, MMIO, "read register 0x%x value 0x%x\n", reg_addr, val);
	return val;
}

__attribute__((used)) static inline void t3_write_reg(struct adapter *adapter, u32 reg_addr, u32 val)
{
	CH_DBG(adapter, MMIO, "setting register 0x%x to 0x%x\n", reg_addr, val);
	writel(val, adapter->regs + reg_addr);
}

__attribute__((used)) static inline struct port_info *adap2pinfo(struct adapter *adap, int idx)
{
	return netdev_priv(adap->port[idx]);
}

__attribute__((used)) static inline int phy2portid(struct cphy *phy)
{
	struct adapter *adap = phy->adapter;
	struct port_info *port0 = adap2pinfo(adap, 0);

	return &port0->phy == phy ? 0 : 1;
}

__attribute__((used)) static inline int offload_running(struct adapter *adapter)
{
	return test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map);
}

__attribute__((used)) static inline int uses_xaui(const struct adapter *adap)
{
	return adapter_info(adap)->caps & SUPPORTED_AUI;
}

__attribute__((used)) static inline int is_10G(const struct adapter *adap)
{
	return adapter_info(adap)->caps & SUPPORTED_10000baseT_Full;
}

__attribute__((used)) static inline int is_offload(const struct adapter *adap)
{
	return adap->params.offload;
}

__attribute__((used)) static inline unsigned int core_ticks_per_usec(const struct adapter *adap)
{
	return adap->params.vpd.cclk / 1000;
}

__attribute__((used)) static inline unsigned int is_pcie(const struct adapter *adap)
{
	return adap->params.pci.variant == PCI_VARIANT_PCIE;
}

__attribute__((used)) static inline int t3_wait_op_done(struct adapter *adapter, int reg, u32 mask,
				  int polarity, int attempts, int delay)
{
	return t3_wait_op_done_val(adapter, reg, mask, polarity, attempts,
				   delay, NULL);
}

__attribute__((used)) static int aq100x_reset(struct cphy *phy, int wait)
{
	/*
	 * Ignore the caller specified wait time; always wait for the reset to
	 * complete. Can take up to 3s.
	 */
	int err = t3_phy_reset(phy, MDIO_MMD_VEND1, 3000);

	if (err)
		CH_WARN(phy->adapter, "PHY%d: reset failed (0x%x).\n",
			phy->mdio.prtad, err);

	return err;
}

__attribute__((used)) static int aq100x_intr_enable(struct cphy *phy)
{
	int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AQ_IMASK_PMA, IMASK_PMA);
	if (err)
		return err;

	err = t3_mdio_write(phy, MDIO_MMD_VEND1, AQ_IMASK_GLOBAL, IMASK_GLOBAL);
	return err;
}

__attribute__((used)) static int aq100x_intr_disable(struct cphy *phy)
{
	return t3_mdio_write(phy, MDIO_MMD_VEND1, AQ_IMASK_GLOBAL, 0);
}

__attribute__((used)) static int aq100x_intr_clear(struct cphy *phy)
{
	unsigned int v;

	t3_mdio_read(phy, MDIO_MMD_VEND1, AQ_IFLAG_GLOBAL, &v);
	t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_STAT1, &v);

	return 0;
}

__attribute__((used)) static int aq100x_intr_handler(struct cphy *phy)
{
	int err;
	unsigned int cause, v;

	err = t3_mdio_read(phy, MDIO_MMD_VEND1, AQ_IFLAG_GLOBAL, &cause);
	if (err)
		return err;

	/* Read (and reset) the latching version of the status */
	t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_STAT1, &v);

	return cphy_cause_link_change;
}

__attribute__((used)) static int aq100x_power_down(struct cphy *phy, int off)
{
	return mdio_set_flag(&phy->mdio, phy->mdio.prtad,
			     MDIO_MMD_PMAPMD, MDIO_CTRL1,
			     MDIO_CTRL1_LPOWER, off);
}

__attribute__((used)) static int aq100x_autoneg_enable(struct cphy *phy)
{
	int err;

	err = aq100x_power_down(phy, 0);
	if (!err)
		err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
				    MDIO_MMD_AN, MDIO_CTRL1,
				    BMCR_ANENABLE | BMCR_ANRESTART, 1);

	return err;
}

__attribute__((used)) static int aq100x_autoneg_restart(struct cphy *phy)
{
	int err;

	err = aq100x_power_down(phy, 0);
	if (!err)
		err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
				    MDIO_MMD_AN, MDIO_CTRL1,
				    BMCR_ANENABLE | BMCR_ANRESTART, 1);

	return err;
}

__attribute__((used)) static int aq100x_advertise(struct cphy *phy, unsigned int advertise_map)
{
	unsigned int adv;
	int err;

	/* 10G advertisement */
	adv = 0;
	if (advertise_map & ADVERTISED_10000baseT_Full)
		adv |= ADV_10G_FULL;
	err = t3_mdio_change_bits(phy, MDIO_MMD_AN, MDIO_AN_10GBT_CTRL,
				  ADV_10G_FULL, adv);
	if (err)
		return err;

	/* 1G advertisement */
	adv = 0;
	if (advertise_map & ADVERTISED_1000baseT_Full)
		adv |= ADV_1G_FULL;
	if (advertise_map & ADVERTISED_1000baseT_Half)
		adv |= ADV_1G_HALF;
	err = t3_mdio_change_bits(phy, MDIO_MMD_AN, AQ_1G_CTRL,
				  ADV_1G_FULL | ADV_1G_HALF, adv);
	if (err)
		return err;

	/* 100M, pause advertisement */
	adv = 0;
	if (advertise_map & ADVERTISED_100baseT_Half)
		adv |= ADVERTISE_100HALF;
	if (advertise_map & ADVERTISED_100baseT_Full)
		adv |= ADVERTISE_100FULL;
	if (advertise_map & ADVERTISED_Pause)
		adv |= ADVERTISE_PAUSE_CAP;
	if (advertise_map & ADVERTISED_Asym_Pause)
		adv |= ADVERTISE_PAUSE_ASYM;
	err = t3_mdio_change_bits(phy, MDIO_MMD_AN, MDIO_AN_ADVERTISE,
				  0xfe0, adv);

	return err;
}

__attribute__((used)) static int aq100x_set_loopback(struct cphy *phy, int mmd, int dir, int enable)
{
	return mdio_set_flag(&phy->mdio, phy->mdio.prtad,
			     MDIO_MMD_PMAPMD, MDIO_CTRL1,
			     BMCR_LOOPBACK, enable);
}

__attribute__((used)) static int aq100x_set_speed_duplex(struct cphy *phy, int speed, int duplex)
{
	/* no can do */
	return -1;
}

__attribute__((used)) static int aq100x_get_link_status(struct cphy *phy, int *link_ok,
				  int *speed, int *duplex, int *fc)
{
	int err;
	unsigned int v;

	if (link_ok) {
		err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AQ_LINK_STAT, &v);
		if (err)
			return err;

		*link_ok = v & 1;
		if (!*link_ok)
			return 0;
	}

	err = t3_mdio_read(phy, MDIO_MMD_AN, AQ_ANEG_STAT, &v);
	if (err)
		return err;

	if (speed) {
		switch (v & 0x6) {
		case 0x6:
			*speed = SPEED_10000;
			break;
		case 0x4:
			*speed = SPEED_1000;
			break;
		case 0x2:
			*speed = SPEED_100;
			break;
		case 0x0:
			*speed = SPEED_10;
			break;
		}
	}

	if (duplex)
		*duplex = v & 1 ? DUPLEX_FULL : DUPLEX_HALF;

	return 0;
}

int t3_aq100x_phy_prep(struct cphy *phy, struct adapter *adapter, int phy_addr,
		       const struct mdio_ops *mdio_ops)
{
	unsigned int v, v2, gpio, wait;
	int err;

	cphy_init(phy, adapter, phy_addr, &aq100x_ops, mdio_ops,
		  SUPPORTED_1000baseT_Full | SUPPORTED_10000baseT_Full |
		  SUPPORTED_TP | SUPPORTED_Autoneg | SUPPORTED_AUI,
		  "1000/10GBASE-T");

	/*
	 * The PHY has been out of reset ever since the system powered up.  So
	 * we do a hard reset over here.
	 */
	gpio = phy_addr ? F_GPIO10_OUT_VAL : F_GPIO6_OUT_VAL;
	t3_set_reg_field(adapter, A_T3DBG_GPIO_EN, gpio, 0);
	msleep(1);
	t3_set_reg_field(adapter, A_T3DBG_GPIO_EN, gpio, gpio);

	/*
	 * Give it enough time to load the firmware and get ready for mdio.
	 */
	msleep(1000);
	wait = 500; /* in 10ms increments */
	do {
		err = t3_mdio_read(phy, MDIO_MMD_VEND1, MDIO_CTRL1, &v);
		if (err || v == 0xffff) {

			/* Allow prep_adapter to succeed when ffff is read */

			CH_WARN(adapter, "PHY%d: reset failed (0x%x, 0x%x).\n",
				phy_addr, err, v);
			goto done;
		}

		v &= AQ_RESET;
		if (v)
			msleep(10);
	} while (v && --wait);
	if (v) {
		CH_WARN(adapter, "PHY%d: reset timed out (0x%x).\n",
			phy_addr, v);

		goto done; /* let prep_adapter succeed */
	}

	/* Datasheet says 3s max but this has been observed */
	wait = (500 - wait) * 10 + 1000;
	if (wait > 3000)
		CH_WARN(adapter, "PHY%d: reset took %ums\n", phy_addr, wait);

	/* Firmware version check. */
	t3_mdio_read(phy, MDIO_MMD_VEND1, AQ_FW_VERSION, &v);
	if (v != 101)
		CH_WARN(adapter, "PHY%d: unsupported firmware %d\n",
			phy_addr, v);

	/*
	 * The PHY should start in really-low-power mode.  Prepare it for normal
	 * operations.
	 */
	err = t3_mdio_read(phy, MDIO_MMD_VEND1, MDIO_CTRL1, &v);
	if (err)
		return err;
	if (v & AQ_LOWPOWER) {
		err = t3_mdio_change_bits(phy, MDIO_MMD_VEND1, MDIO_CTRL1,
					  AQ_LOWPOWER, 0);
		if (err)
			return err;
		msleep(10);
	} else
		CH_WARN(adapter, "PHY%d does not start in low power mode.\n",
			phy_addr);

	/*
	 * Verify XAUI settings, but let prep succeed no matter what.
	 */
	v = v2 = 0;
	t3_mdio_read(phy, MDIO_MMD_PHYXS, AQ_XAUI_RX_CFG, &v);
	t3_mdio_read(phy, MDIO_MMD_PHYXS, AQ_XAUI_TX_CFG, &v2);
	if (v != 0x1b || v2 != 0x1b)
		CH_WARN(adapter,
			"PHY%d: incorrect XAUI settings (0x%x, 0x%x).\n",
			phy_addr, v, v2);

done:
	return err;
}


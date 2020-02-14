#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct net_device {int dummy; } ;
struct mdio_ops {int (* read ) (struct net_device*,int,int,int) ;int (* write ) (struct net_device*,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; } ;
struct cphy_ops {int /*<<< orphan*/  mmds; } ;
struct TYPE_5__ {int (* mdio_read ) (struct net_device*,int,int,int) ;int prtad; int (* mdio_write ) (struct net_device*,int,int,int,unsigned int) ;struct net_device* dev; int /*<<< orphan*/  mode_support; int /*<<< orphan*/  mmds; } ;
struct cphy {struct adapter* adapter; TYPE_2__ mdio; struct cphy_ops const* ops; } ;
struct TYPE_4__ {int is_asic; int chip_version; int chip_revision; } ;
struct adapter {TYPE_1__ params; } ;
typedef  struct adapter adapter_t ;
struct TYPE_6__ {int clock_core; } ;

/* Variables and functions */
 int /*<<< orphan*/  A_ELMER0_GPO ; 
 int /*<<< orphan*/  A_ELMER0_INT_CAUSE ; 
 int /*<<< orphan*/  A_ELMER0_INT_ENABLE ; 
 int DUPLEX_FULL ; 
 int ELMER0_GP_BIT6 ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MDIO_CTRL2 ; 
 int MDIO_DEVAD_NONE ; 
 int MDIO_MMD_PCS ; 
 int MDIO_MMD_PMAPMD ; 
 int MDIO_PMA_LASI_CTRL ; 
 unsigned int MDIO_PMA_LASI_LSALARM ; 
 int MDIO_PMA_LASI_STAT ; 
 int MDIO_STAT1 ; 
 int MDIO_STAT1_LSTATUS ; 
 int MDIO_STAT2 ; 
 int PAUSE_RX ; 
 int PAUSE_TX ; 
 int SPEED_10000 ; 
 TYPE_3__* board_info (struct adapter const*) ; 
 int cphy_cause_link_change ; 
 int /*<<< orphan*/  kfree (struct cphy*) ; 
 struct cphy* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct cphy_ops mv88x201x_ops ; 
 struct adapter* netdev_priv (struct net_device*) ; 
 int stub1 (struct net_device*,int,int,int) ; 
 int stub2 (struct net_device*,int,int,int,unsigned int) ; 
 int /*<<< orphan*/  t1_is_T1B (struct adapter const*) ; 
 int /*<<< orphan*/  t1_tpi_read (struct adapter*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  t1_tpi_write (struct adapter*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline int t1_is_asic(const adapter_t *adapter)
{
	return adapter->params.is_asic;
}

__attribute__((used)) static inline int adapter_matches_type(const adapter_t *adapter,
				       int version, int revision)
{
	return adapter->params.chip_version == version &&
	       adapter->params.chip_revision == revision;
}

__attribute__((used)) static inline int vlan_tso_capable(const adapter_t *adapter)
{
	return !t1_is_T1B(adapter);
}

__attribute__((used)) static inline unsigned int core_ticks_per_usec(const adapter_t *adap)
{
	return board_info(adap)->clock_core / 1000000;
}

__attribute__((used)) static inline int cphy_mdio_read(struct cphy *cphy, int mmd, int reg,
				 unsigned int *valp)
{
	int rc = cphy->mdio.mdio_read(cphy->mdio.dev, cphy->mdio.prtad, mmd,
				      reg);
	*valp = (rc >= 0) ? rc : -1;
	return (rc >= 0) ? 0 : rc;
}

__attribute__((used)) static inline int cphy_mdio_write(struct cphy *cphy, int mmd, int reg,
				  unsigned int val)
{
	return cphy->mdio.mdio_write(cphy->mdio.dev, cphy->mdio.prtad, mmd,
				     reg, val);
}

__attribute__((used)) static inline int simple_mdio_read(struct cphy *cphy, int reg,
				   unsigned int *valp)
{
	return cphy_mdio_read(cphy, MDIO_DEVAD_NONE, reg, valp);
}

__attribute__((used)) static inline int simple_mdio_write(struct cphy *cphy, int reg,
				    unsigned int val)
{
	return cphy_mdio_write(cphy, MDIO_DEVAD_NONE, reg, val);
}

__attribute__((used)) static inline void cphy_init(struct cphy *phy, struct net_device *dev,
			     int phy_addr, const struct cphy_ops *phy_ops,
			     const struct mdio_ops *mdio_ops)
{
	struct adapter *adapter = netdev_priv(dev);
	phy->adapter = adapter;
	phy->ops     = phy_ops;
	if (mdio_ops) {
		phy->mdio.prtad = phy_addr;
		phy->mdio.mmds = phy_ops->mmds;
		phy->mdio.mode_support = mdio_ops->mode_support;
		phy->mdio.mdio_read = mdio_ops->read;
		phy->mdio.mdio_write = mdio_ops->write;
	}
	phy->mdio.dev = dev;
}

__attribute__((used)) static int led_init(struct cphy *cphy)
{
	/* Setup the LED registers so we can turn on/off.
	 * Writing these bits maps control to another
	 * register. mmd(0x1) addr(0x7)
	 */
	cphy_mdio_write(cphy, MDIO_MMD_PCS, 0x8304, 0xdddd);
	return 0;
}

__attribute__((used)) static int led_link(struct cphy *cphy, u32 do_enable)
{
	u32 led = 0;
#define LINK_ENABLE_BIT 0x1

	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_CTRL2, &led);

	if (do_enable & LINK_ENABLE_BIT) {
		led |= LINK_ENABLE_BIT;
		cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_CTRL2, led);
	} else {
		led &= ~LINK_ENABLE_BIT;
		cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_CTRL2, led);
	}
	return 0;
}

__attribute__((used)) static int mv88x201x_reset(struct cphy *cphy, int wait)
{
	/* This can be done through registers.  It is not required since
	 * a full chip reset is used.
	 */
	return 0;
}

__attribute__((used)) static int mv88x201x_interrupt_enable(struct cphy *cphy)
{
	/* Enable PHY LASI interrupts. */
	cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL,
			MDIO_PMA_LASI_LSALARM);

	/* Enable Marvell interrupts through Elmer0. */
	if (t1_is_asic(cphy->adapter)) {
		u32 elmer;

		t1_tpi_read(cphy->adapter, A_ELMER0_INT_ENABLE, &elmer);
		elmer |= ELMER0_GP_BIT6;
		t1_tpi_write(cphy->adapter, A_ELMER0_INT_ENABLE, elmer);
	}
	return 0;
}

__attribute__((used)) static int mv88x201x_interrupt_disable(struct cphy *cphy)
{
	/* Disable PHY LASI interrupts. */
	cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL, 0x0);

	/* Disable Marvell interrupts through Elmer0. */
	if (t1_is_asic(cphy->adapter)) {
		u32 elmer;

		t1_tpi_read(cphy->adapter, A_ELMER0_INT_ENABLE, &elmer);
		elmer &= ~ELMER0_GP_BIT6;
		t1_tpi_write(cphy->adapter, A_ELMER0_INT_ENABLE, elmer);
	}
	return 0;
}

__attribute__((used)) static int mv88x201x_interrupt_clear(struct cphy *cphy)
{
	u32 elmer;
	u32 val;

#ifdef MV88x2010_LINK_STATUS_BUGS
	/* Required to read twice before clear takes affect. */
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_RXSTAT, &val);
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_TXSTAT, &val);
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_STAT, &val);

	/* Read this register after the others above it else
	 * the register doesn't clear correctly.
	 */
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT1, &val);
#endif

	/* Clear link status. */
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT1, &val);
	/* Clear PHY LASI interrupts. */
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_STAT, &val);

#ifdef MV88x2010_LINK_STATUS_BUGS
	/* Do it again. */
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_RXSTAT, &val);
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_TXSTAT, &val);
#endif

	/* Clear Marvell interrupts through Elmer0. */
	if (t1_is_asic(cphy->adapter)) {
		t1_tpi_read(cphy->adapter, A_ELMER0_INT_CAUSE, &elmer);
		elmer |= ELMER0_GP_BIT6;
		t1_tpi_write(cphy->adapter, A_ELMER0_INT_CAUSE, elmer);
	}
	return 0;
}

__attribute__((used)) static int mv88x201x_interrupt_handler(struct cphy *cphy)
{
	/* Clear interrupts */
	mv88x201x_interrupt_clear(cphy);

	/* We have only enabled link change interrupts and so
	 * cphy_cause must be a link change interrupt.
	 */
	return cphy_cause_link_change;
}

__attribute__((used)) static int mv88x201x_set_loopback(struct cphy *cphy, int on)
{
	return 0;
}

__attribute__((used)) static int mv88x201x_get_link_status(struct cphy *cphy, int *link_ok,
				     int *speed, int *duplex, int *fc)
{
	u32 val = 0;

	if (link_ok) {
		/* Read link status. */
		cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT1, &val);
		val &= MDIO_STAT1_LSTATUS;
		*link_ok = (val == MDIO_STAT1_LSTATUS);
		/* Turn on/off Link LED */
		led_link(cphy, *link_ok);
	}
	if (speed)
		*speed = SPEED_10000;
	if (duplex)
		*duplex = DUPLEX_FULL;
	if (fc)
		*fc = PAUSE_RX | PAUSE_TX;
	return 0;
}

__attribute__((used)) static void mv88x201x_destroy(struct cphy *cphy)
{
	kfree(cphy);
}

__attribute__((used)) static struct cphy *mv88x201x_phy_create(struct net_device *dev, int phy_addr,
					 const struct mdio_ops *mdio_ops)
{
	u32 val;
	struct cphy *cphy = kzalloc(sizeof(*cphy), GFP_KERNEL);

	if (!cphy)
		return NULL;

	cphy_init(cphy, dev, phy_addr, &mv88x201x_ops, mdio_ops);

	/* Commands the PHY to enable XFP's clock. */
	cphy_mdio_read(cphy, MDIO_MMD_PCS, 0x8300, &val);
	cphy_mdio_write(cphy, MDIO_MMD_PCS, 0x8300, val | 1);

	/* Clear link status. Required because of a bug in the PHY.  */
	cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT2, &val);
	cphy_mdio_read(cphy, MDIO_MMD_PCS, MDIO_STAT2, &val);

	/* Allows for Link,Ack LED turn on/off */
	led_init(cphy);
	return cphy;
}

__attribute__((used)) static int mv88x201x_phy_reset(adapter_t *adapter)
{
	u32 val;

	t1_tpi_read(adapter, A_ELMER0_GPO, &val);
	val &= ~4;
	t1_tpi_write(adapter, A_ELMER0_GPO, val);
	msleep(100);

	t1_tpi_write(adapter, A_ELMER0_GPO, val | 4);
	msleep(1000);

	/* Now lets enable the Laser. Delay 100us */
	t1_tpi_read(adapter, A_ELMER0_GPO, &val);
	val |= 0x8000;
	t1_tpi_write(adapter, A_ELMER0_GPO, val);
	udelay(100);
	return 0;
}


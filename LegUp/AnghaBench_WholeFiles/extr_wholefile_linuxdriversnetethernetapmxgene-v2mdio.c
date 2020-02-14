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
typedef  int u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_4__ {int /*<<< orphan*/  phy_mode; } ;
struct xge_pdata {scalar_t__ phy_speed; TYPE_2__ resources; struct mii_bus* mdio_bus; TYPE_1__* pdev; } ;
struct phy_device {scalar_t__ speed; int supported; int advertising; scalar_t__ link; } ;
struct net_device {struct phy_device* phydev; } ;
struct device {int dummy; } ;
struct mii_bus {scalar_t__ state; char* name; int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int) ;int phy_mask; int /*<<< orphan*/  id; struct device* parent; struct xge_pdata* priv; struct device dev; } ;
struct TYPE_3__ {struct device dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int GENMASK (int,int) ; 
 scalar_t__ IS_ERR (struct phy_device*) ; 
 scalar_t__ MDIOBUS_REGISTERED ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 int /*<<< orphan*/  MII_MGMT_ADDRESS ; 
 int MII_MGMT_BUSY ; 
 int /*<<< orphan*/  MII_MGMT_COMMAND ; 
 int /*<<< orphan*/  MII_MGMT_CONTROL ; 
 int /*<<< orphan*/  MII_MGMT_INDICATORS ; 
 int /*<<< orphan*/  MII_MGMT_STATUS ; 
 int MII_READ_CYCLE ; 
 int /*<<< orphan*/  PHY_ADDR ; 
 int PTR_ERR (struct phy_device*) ; 
 int /*<<< orphan*/  REG_ADDR ; 
 int /*<<< orphan*/  SET_REG_BITS (int*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ SPEED_UNKNOWN ; 
 int SUPPORTED_1000baseT_Half ; 
 int SUPPORTED_100baseT_Full ; 
 int SUPPORTED_100baseT_Half ; 
 int SUPPORTED_10baseT_Full ; 
 int SUPPORTED_10baseT_Half ; 
 int SUPPORTED_AUI ; 
 int SUPPORTED_BNC ; 
 int SUPPORTED_FIBRE ; 
 int SUPPORTED_MII ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 char* dev_name (struct device*) ; 
 struct mii_bus* mdiobus_alloc () ; 
 int /*<<< orphan*/  mdiobus_free (struct mii_bus*) ; 
 int mdiobus_register (struct mii_bus*) ; 
 int /*<<< orphan*/  mdiobus_unregister (struct mii_bus*) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*) ; 
 struct xge_pdata* netdev_priv (struct net_device*) ; 
 struct phy_device* phy_connect (struct net_device*,int /*<<< orphan*/ ,void (*) (struct net_device*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  phy_disconnect (struct phy_device*) ; 
 struct phy_device* phy_find_first (struct mii_bus*) ; 
 int /*<<< orphan*/  phy_print_status (struct phy_device*) ; 
 int /*<<< orphan*/  phydev_name (struct phy_device*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  xge_mac_disable (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_enable (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_set_speed (struct xge_pdata*) ; 
 int xge_rd_csr (struct xge_pdata*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xge_wr_csr (struct xge_pdata*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void xgene_set_reg_bits(u32 *var, int pos, int len, u32 val)
{
	u32 mask = GENMASK(pos + len, pos);

	*var &= ~mask;
	*var |= ((val << pos) & mask);
}

__attribute__((used)) static inline u32 xgene_get_reg_bits(u32 var, int pos, int len)
{
	u32 mask = GENMASK(pos + len, pos);

	return (var & mask) >> pos;
}

__attribute__((used)) static inline u64 xge_set_desc_bits(int pos, int len, u64 val)
{
	return (val & ((1ULL << len) - 1)) << pos;
}

__attribute__((used)) static inline u64 xge_get_desc_bits(int pos, int len, u64 src)
{
	return (src >> pos) & ((1ULL << len) - 1);
}

__attribute__((used)) static int xge_mdio_write(struct mii_bus *bus, int phy_id, int reg, u16 data)
{
	struct xge_pdata *pdata = bus->priv;
	u32 done, val = 0;
	u8 wait = 10;

	SET_REG_BITS(&val, PHY_ADDR, phy_id);
	SET_REG_BITS(&val, REG_ADDR, reg);
	xge_wr_csr(pdata, MII_MGMT_ADDRESS, val);

	xge_wr_csr(pdata, MII_MGMT_CONTROL, data);
	do {
		usleep_range(5, 10);
		done = xge_rd_csr(pdata, MII_MGMT_INDICATORS);
	} while ((done & MII_MGMT_BUSY) && wait--);

	if (done & MII_MGMT_BUSY) {
		dev_err(&bus->dev, "MII_MGMT write failed\n");
		return -ETIMEDOUT;
	}

	return 0;
}

__attribute__((used)) static int xge_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
	struct xge_pdata *pdata = bus->priv;
	u32 data, done, val = 0;
	u8 wait = 10;

	SET_REG_BITS(&val, PHY_ADDR, phy_id);
	SET_REG_BITS(&val, REG_ADDR, reg);
	xge_wr_csr(pdata, MII_MGMT_ADDRESS, val);

	xge_wr_csr(pdata, MII_MGMT_COMMAND, MII_READ_CYCLE);
	do {
		usleep_range(5, 10);
		done = xge_rd_csr(pdata, MII_MGMT_INDICATORS);
	} while ((done & MII_MGMT_BUSY) && wait--);

	if (done & MII_MGMT_BUSY) {
		dev_err(&bus->dev, "MII_MGMT read failed\n");
		return -ETIMEDOUT;
	}

	data = xge_rd_csr(pdata, MII_MGMT_STATUS);
	xge_wr_csr(pdata, MII_MGMT_COMMAND, 0);

	return data;
}

__attribute__((used)) static void xge_adjust_link(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct phy_device *phydev = ndev->phydev;

	if (phydev->link) {
		if (pdata->phy_speed != phydev->speed) {
			pdata->phy_speed = phydev->speed;
			xge_mac_set_speed(pdata);
			xge_mac_enable(pdata);
			phy_print_status(phydev);
		}
	} else {
		if (pdata->phy_speed != SPEED_UNKNOWN) {
			pdata->phy_speed = SPEED_UNKNOWN;
			xge_mac_disable(pdata);
			phy_print_status(phydev);
		}
	}
}

void xge_mdio_remove(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct mii_bus *mdio_bus = pdata->mdio_bus;

	if (ndev->phydev)
		phy_disconnect(ndev->phydev);

	if (mdio_bus->state == MDIOBUS_REGISTERED)
		mdiobus_unregister(mdio_bus);

	mdiobus_free(mdio_bus);
}

int xge_mdio_config(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	struct mii_bus *mdio_bus;
	struct phy_device *phydev;
	int ret;

	mdio_bus = mdiobus_alloc();
	if (!mdio_bus)
		return -ENOMEM;

	mdio_bus->name = "APM X-Gene Ethernet (v2) MDIO Bus";
	mdio_bus->read = xge_mdio_read;
	mdio_bus->write = xge_mdio_write;
	mdio_bus->priv = pdata;
	mdio_bus->parent = dev;
	snprintf(mdio_bus->id, MII_BUS_ID_SIZE, "%s-mii", dev_name(dev));
	pdata->mdio_bus = mdio_bus;

	mdio_bus->phy_mask = 0x1;
	ret = mdiobus_register(mdio_bus);
	if (ret)
		goto err;

	phydev = phy_find_first(mdio_bus);
	if (!phydev) {
		dev_err(dev, "no PHY found\n");
		ret = -ENODEV;
		goto err;
	}
	phydev = phy_connect(ndev, phydev_name(phydev),
			     &xge_adjust_link,
			     pdata->resources.phy_mode);

	if (IS_ERR(phydev)) {
		netdev_err(ndev, "Could not attach to PHY\n");
		ret = PTR_ERR(phydev);
		goto err;
	}

	phydev->supported &= ~(SUPPORTED_10baseT_Half |
			       SUPPORTED_10baseT_Full |
			       SUPPORTED_100baseT_Half |
			       SUPPORTED_100baseT_Full |
			       SUPPORTED_1000baseT_Half |
			       SUPPORTED_AUI |
			       SUPPORTED_MII |
			       SUPPORTED_FIBRE |
			       SUPPORTED_BNC);
	phydev->advertising = phydev->supported;
	pdata->phy_speed = SPEED_UNKNOWN;

	return 0;
err:
	xge_mdio_remove(ndev);

	return ret;
}


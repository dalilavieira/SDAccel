#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_11__ {struct device_node* of_node; } ;
struct platform_device {char* name; TYPE_5__ dev; } ;
struct mii_bus {char* name; int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int) ;struct emac_adapter* priv; TYPE_5__* parent; int /*<<< orphan*/  id; } ;
struct emac_adapter {TYPE_2__* phydev; struct mii_bus* mii_bus; scalar_t__ base; } ;
struct device_node {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; } ;
struct TYPE_10__ {TYPE_1__ mdio; } ;

/* Variables and functions */
 int EIO ; 
 scalar_t__ EMAC_MDIO_CTRL ; 
 scalar_t__ EMAC_PHY_STS ; 
 int ENODEV ; 
 int ENOMEM ; 
 int MDIO_BUSY ; 
 int MDIO_CLK_25_4 ; 
 int MDIO_CLK_SEL_BMSK ; 
 int MDIO_CLK_SEL_SHFT ; 
 int MDIO_DATA_BMSK ; 
 int MDIO_DATA_SHFT ; 
 int MDIO_RD_NWR ; 
 int MDIO_REG_ADDR_BMSK ; 
 int MDIO_REG_ADDR_SHFT ; 
 int MDIO_START ; 
 int /*<<< orphan*/  MDIO_STATUS_DELAY_TIME ; 
 int MDIO_WAIT_TIMES ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 int /*<<< orphan*/  PHY_ADDR_BMSK ; 
 int PHY_ADDR_SHFT ; 
 int SUP_PREAMBLE ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*) ; 
 int device_property_read_u32 (TYPE_5__*,char*,int*) ; 
 struct mii_bus* devm_mdiobus_alloc (TYPE_5__*) ; 
 int /*<<< orphan*/  emac_reg_update32 (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ *) ; 
 scalar_t__ has_acpi_companion (TYPE_5__*) ; 
 TYPE_2__* mdiobus_get_phy (struct mii_bus*,int) ; 
 int mdiobus_register (struct mii_bus*) ; 
 int /*<<< orphan*/  mdiobus_unregister (struct mii_bus*) ; 
 int of_mdiobus_register (struct mii_bus*,struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 TYPE_2__* of_phy_find_device (struct device_node*) ; 
 TYPE_2__* phy_find_first (struct mii_bus*) ; 
 scalar_t__ readl_poll_timeout (scalar_t__,int,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int emac_mdio_read(struct mii_bus *bus, int addr, int regnum)
{
	struct emac_adapter *adpt = bus->priv;
	u32 reg;

	emac_reg_update32(adpt->base + EMAC_PHY_STS, PHY_ADDR_BMSK,
			  (addr << PHY_ADDR_SHFT));

	reg = SUP_PREAMBLE |
	      ((MDIO_CLK_25_4 << MDIO_CLK_SEL_SHFT) & MDIO_CLK_SEL_BMSK) |
	      ((regnum << MDIO_REG_ADDR_SHFT) & MDIO_REG_ADDR_BMSK) |
	      MDIO_START | MDIO_RD_NWR;

	writel(reg, adpt->base + EMAC_MDIO_CTRL);

	if (readl_poll_timeout(adpt->base + EMAC_MDIO_CTRL, reg,
			       !(reg & (MDIO_START | MDIO_BUSY)),
			       MDIO_STATUS_DELAY_TIME, MDIO_WAIT_TIMES * 100))
		return -EIO;

	return (reg >> MDIO_DATA_SHFT) & MDIO_DATA_BMSK;
}

__attribute__((used)) static int emac_mdio_write(struct mii_bus *bus, int addr, int regnum, u16 val)
{
	struct emac_adapter *adpt = bus->priv;
	u32 reg;

	emac_reg_update32(adpt->base + EMAC_PHY_STS, PHY_ADDR_BMSK,
			  (addr << PHY_ADDR_SHFT));

	reg = SUP_PREAMBLE |
		((MDIO_CLK_25_4 << MDIO_CLK_SEL_SHFT) & MDIO_CLK_SEL_BMSK) |
		((regnum << MDIO_REG_ADDR_SHFT) & MDIO_REG_ADDR_BMSK) |
		((val << MDIO_DATA_SHFT) & MDIO_DATA_BMSK) |
		MDIO_START;

	writel(reg, adpt->base + EMAC_MDIO_CTRL);

	if (readl_poll_timeout(adpt->base + EMAC_MDIO_CTRL, reg,
			       !(reg & (MDIO_START | MDIO_BUSY)),
			       MDIO_STATUS_DELAY_TIME, MDIO_WAIT_TIMES * 100))
		return -EIO;

	return 0;
}

int emac_phy_config(struct platform_device *pdev, struct emac_adapter *adpt)
{
	struct device_node *np = pdev->dev.of_node;
	struct mii_bus *mii_bus;
	int ret;

	/* Create the mii_bus object for talking to the MDIO bus */
	adpt->mii_bus = mii_bus = devm_mdiobus_alloc(&pdev->dev);
	if (!mii_bus)
		return -ENOMEM;

	mii_bus->name = "emac-mdio";
	snprintf(mii_bus->id, MII_BUS_ID_SIZE, "%s", pdev->name);
	mii_bus->read = emac_mdio_read;
	mii_bus->write = emac_mdio_write;
	mii_bus->parent = &pdev->dev;
	mii_bus->priv = adpt;

	if (has_acpi_companion(&pdev->dev)) {
		u32 phy_addr;

		ret = mdiobus_register(mii_bus);
		if (ret) {
			dev_err(&pdev->dev, "could not register mdio bus\n");
			return ret;
		}
		ret = device_property_read_u32(&pdev->dev, "phy-channel",
					       &phy_addr);
		if (ret)
			/* If we can't read a valid phy address, then assume
			 * that there is only one phy on this mdio bus.
			 */
			adpt->phydev = phy_find_first(mii_bus);
		else
			adpt->phydev = mdiobus_get_phy(mii_bus, phy_addr);

		/* of_phy_find_device() claims a reference to the phydev,
		 * so we do that here manually as well. When the driver
		 * later unloads, it can unilaterally drop the reference
		 * without worrying about ACPI vs DT.
		 */
		if (adpt->phydev)
			get_device(&adpt->phydev->mdio.dev);
	} else {
		struct device_node *phy_np;

		ret = of_mdiobus_register(mii_bus, np);
		if (ret) {
			dev_err(&pdev->dev, "could not register mdio bus\n");
			return ret;
		}

		phy_np = of_parse_phandle(np, "phy-handle", 0);
		adpt->phydev = of_phy_find_device(phy_np);
		of_node_put(phy_np);
	}

	if (!adpt->phydev) {
		dev_err(&pdev->dev, "could not find external phy\n");
		mdiobus_unregister(mii_bus);
		return -ENODEV;
	}

	return 0;
}


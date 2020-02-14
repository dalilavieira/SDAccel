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
struct phy_provider {int /*<<< orphan*/  dev; } ;
struct phy {int /*<<< orphan*/  dev; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct mdio_device {struct device dev; int /*<<< orphan*/  addr; int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLK_ADDR_REG_OFFSET ; 
 scalar_t__ IS_ERR (struct phy_provider*) ; 
 int /*<<< orphan*/  PLL_AFE1_100MHZ_BLK ; 
 int /*<<< orphan*/  PLL_CLK_AMP_2P05V ; 
 int /*<<< orphan*/  PLL_CLK_AMP_OFFSET ; 
 int PTR_ERR (struct phy_provider*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct phy_provider* devm_of_phy_provider_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_phy_create (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int mdiobus_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ns2_pci_phy_ops ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 struct mdio_device* phy_get_drvdata (struct phy_provider*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy_provider*,struct mdio_device*) ; 

__attribute__((used)) static int ns2_pci_phy_init(struct phy *p)
{
	struct mdio_device *mdiodev = phy_get_drvdata(p);
	int rc;

	/* select the AFE 100MHz block page */
	rc = mdiobus_write(mdiodev->bus, mdiodev->addr,
			   BLK_ADDR_REG_OFFSET, PLL_AFE1_100MHZ_BLK);
	if (rc)
		goto err;

	/* set the 100 MHz reference clock amplitude to 2.05 v */
	rc = mdiobus_write(mdiodev->bus, mdiodev->addr,
			   PLL_CLK_AMP_OFFSET, PLL_CLK_AMP_2P05V);
	if (rc)
		goto err;

	return 0;

err:
	dev_err(&mdiodev->dev, "Error %d writing to phy\n", rc);
	return rc;
}

__attribute__((used)) static int ns2_pci_phy_probe(struct mdio_device *mdiodev)
{
	struct device *dev = &mdiodev->dev;
	struct phy_provider *provider;
	struct phy *phy;

	phy = devm_phy_create(dev, dev->of_node, &ns2_pci_phy_ops);
	if (IS_ERR(phy)) {
		dev_err(dev, "failed to create Phy\n");
		return PTR_ERR(phy);
	}

	phy_set_drvdata(phy, mdiodev);

	provider = devm_of_phy_provider_register(&phy->dev,
						 of_phy_simple_xlate);
	if (IS_ERR(provider)) {
		dev_err(dev, "failed to register Phy provider\n");
		return PTR_ERR(provider);
	}

	dev_info(dev, "%s PHY registered\n", dev_name(dev));

	return 0;
}


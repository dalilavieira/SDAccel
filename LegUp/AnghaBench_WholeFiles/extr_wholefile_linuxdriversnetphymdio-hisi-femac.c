#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct resource {int dummy; } ;
struct TYPE_3__ {struct device_node* of_node; } ;
struct platform_device {char* name; TYPE_1__ dev; } ;
struct mii_bus {char* name; int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int) ;struct hisi_femac_mdio_data* priv; TYPE_1__* parent; int /*<<< orphan*/  id; } ;
struct hisi_femac_mdio_data {scalar_t__ clk; scalar_t__ membase; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int BIT_PHY_ADDR_OFFSET ; 
 int BIT_WR_DATA_OFFSET ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ MDIO_RO_DATA ; 
 scalar_t__ MDIO_RWCTRL ; 
 int MDIO_RW_FINISH ; 
 int MDIO_WRITE ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 scalar_t__ devm_clk_get (TYPE_1__*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 struct mii_bus* mdiobus_alloc_size (int) ; 
 int /*<<< orphan*/  mdiobus_free (struct mii_bus*) ; 
 int /*<<< orphan*/  mdiobus_unregister (struct mii_bus*) ; 
 int of_mdiobus_register (struct mii_bus*,struct device_node*) ; 
 struct mii_bus* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mii_bus*) ; 
 int readl (scalar_t__) ; 
 int readl_poll_timeout (scalar_t__,int,int,int,int) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int hisi_femac_mdio_wait_ready(struct hisi_femac_mdio_data *data)
{
	u32 val;

	return readl_poll_timeout(data->membase + MDIO_RWCTRL,
				  val, val & MDIO_RW_FINISH, 20, 10000);
}

__attribute__((used)) static int hisi_femac_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
	struct hisi_femac_mdio_data *data = bus->priv;
	int ret;

	ret = hisi_femac_mdio_wait_ready(data);
	if (ret)
		return ret;

	writel((mii_id << BIT_PHY_ADDR_OFFSET) | regnum,
	       data->membase + MDIO_RWCTRL);

	ret = hisi_femac_mdio_wait_ready(data);
	if (ret)
		return ret;

	return readl(data->membase + MDIO_RO_DATA) & 0xFFFF;
}

__attribute__((used)) static int hisi_femac_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
				 u16 value)
{
	struct hisi_femac_mdio_data *data = bus->priv;
	int ret;

	ret = hisi_femac_mdio_wait_ready(data);
	if (ret)
		return ret;

	writel(MDIO_WRITE | (value << BIT_WR_DATA_OFFSET) |
	       (mii_id << BIT_PHY_ADDR_OFFSET) | regnum,
	       data->membase + MDIO_RWCTRL);

	return hisi_femac_mdio_wait_ready(data);
}

__attribute__((used)) static int hisi_femac_mdio_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct mii_bus *bus;
	struct hisi_femac_mdio_data *data;
	struct resource *res;
	int ret;

	bus = mdiobus_alloc_size(sizeof(*data));
	if (!bus)
		return -ENOMEM;

	bus->name = "hisi_femac_mii_bus";
	bus->read = &hisi_femac_mdio_read;
	bus->write = &hisi_femac_mdio_write;
	snprintf(bus->id, MII_BUS_ID_SIZE, "%s", pdev->name);
	bus->parent = &pdev->dev;

	data = bus->priv;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	data->membase = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(data->membase)) {
		ret = PTR_ERR(data->membase);
		goto err_out_free_mdiobus;
	}

	data->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(data->clk)) {
		ret = PTR_ERR(data->clk);
		goto err_out_free_mdiobus;
	}

	ret = clk_prepare_enable(data->clk);
	if (ret)
		goto err_out_free_mdiobus;

	ret = of_mdiobus_register(bus, np);
	if (ret)
		goto err_out_disable_clk;

	platform_set_drvdata(pdev, bus);

	return 0;

err_out_disable_clk:
	clk_disable_unprepare(data->clk);
err_out_free_mdiobus:
	mdiobus_free(bus);
	return ret;
}

__attribute__((used)) static int hisi_femac_mdio_remove(struct platform_device *pdev)
{
	struct mii_bus *bus = platform_get_drvdata(pdev);
	struct hisi_femac_mdio_data *data = bus->priv;

	mdiobus_unregister(bus);
	clk_disable_unprepare(data->clk);
	mdiobus_free(bus);

	return 0;
}


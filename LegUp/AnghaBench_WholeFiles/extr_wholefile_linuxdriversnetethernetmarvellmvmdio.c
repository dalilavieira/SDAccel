#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct orion_mdio_ops {scalar_t__ (* is_done ) (struct orion_mdio_dev*) ;int /*<<< orphan*/  poll_interval_max; int /*<<< orphan*/  poll_interval_min; } ;
struct orion_mdio_dev {scalar_t__ err_interrupt; scalar_t__ regs; int /*<<< orphan*/ * clk; int /*<<< orphan*/  smi_busy_wait; } ;
struct mii_bus {int (* read ) (struct mii_bus*,int,int) ;int (* write ) (struct mii_bus*,int,int,int) ;char* name; struct orion_mdio_dev* priv; TYPE_1__* parent; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum orion_mdio_bus_type { ____Placeholder_orion_mdio_bus_type } orion_mdio_bus_type ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
#define  BUS_TYPE_SMI 129 
#define  BUS_TYPE_XSMI 128 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPROBE_DEFER ; 
 int ETIMEDOUT ; 
 int GENMASK (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MII_ADDR_C45 ; 
 int /*<<< orphan*/  MII_BUS_ID_SIZE ; 
 scalar_t__ MVMDIO_ERR_INT_CAUSE ; 
 scalar_t__ MVMDIO_ERR_INT_MASK ; 
 int MVMDIO_ERR_INT_SMI_DONE ; 
 int MVMDIO_SMI_BUSY ; 
 int MVMDIO_SMI_DATA_SHIFT ; 
 int MVMDIO_SMI_PHY_ADDR_SHIFT ; 
 int MVMDIO_SMI_PHY_REG_SHIFT ; 
 int MVMDIO_SMI_READ_OPERATION ; 
 int MVMDIO_SMI_READ_VALID ; 
 int /*<<< orphan*/  MVMDIO_SMI_TIMEOUT ; 
 int MVMDIO_SMI_WRITE_OPERATION ; 
 scalar_t__ MVMDIO_XSMI_ADDR_REG ; 
 int MVMDIO_XSMI_BUSY ; 
 int MVMDIO_XSMI_DEVADDR_SHIFT ; 
 scalar_t__ MVMDIO_XSMI_MGNT_REG ; 
 int MVMDIO_XSMI_PHYADDR_SHIFT ; 
 int MVMDIO_XSMI_READ_OPERATION ; 
 int MVMDIO_XSMI_READ_VALID ; 
 int MVMDIO_XSMI_WRITE_OPERATION ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 char* dev_name (TYPE_1__*) ; 
 scalar_t__ devm_ioremap (TYPE_1__*,int /*<<< orphan*/ ,scalar_t__) ; 
 struct mii_bus* devm_mdiobus_alloc_size (TYPE_1__*,int) ; 
 int devm_request_irq (TYPE_1__*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct orion_mdio_dev*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  mdiobus_unregister (struct mii_bus*) ; 
 int /*<<< orphan*/  of_clk_get (int /*<<< orphan*/ ,int) ; 
 scalar_t__ of_device_get_match_data (TYPE_1__*) ; 
 int of_mdiobus_register (struct mii_bus*,int /*<<< orphan*/ ) ; 
 struct orion_mdio_ops orion_mdio_smi_ops ; 
 struct orion_mdio_ops orion_mdio_xsmi_ops ; 
 struct mii_bus* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mii_bus*) ; 
 int readl (scalar_t__) ; 
 scalar_t__ resource_size (struct resource*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 scalar_t__ stub1 (struct orion_mdio_dev*) ; 
 scalar_t__ stub2 (struct orion_mdio_dev*) ; 
 scalar_t__ time_is_before_jiffies (unsigned long) ; 
 unsigned long usecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_event_timeout (int /*<<< orphan*/ ,scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int orion_mdio_wait_ready(const struct orion_mdio_ops *ops,
				 struct mii_bus *bus)
{
	struct orion_mdio_dev *dev = bus->priv;
	unsigned long timeout = usecs_to_jiffies(MVMDIO_SMI_TIMEOUT);
	unsigned long end = jiffies + timeout;
	int timedout = 0;

	while (1) {
	        if (ops->is_done(dev))
			return 0;
	        else if (timedout)
			break;

	        if (dev->err_interrupt <= 0) {
			usleep_range(ops->poll_interval_min,
				     ops->poll_interval_max);

			if (time_is_before_jiffies(end))
				++timedout;
	        } else {
			/* wait_event_timeout does not guarantee a delay of at
			 * least one whole jiffie, so timeout must be no less
			 * than two.
			 */
			if (timeout < 2)
				timeout = 2;
			wait_event_timeout(dev->smi_busy_wait,
				           ops->is_done(dev), timeout);

			++timedout;
	        }
	}

	dev_err(bus->parent, "Timeout: SMI busy for too long\n");
	return  -ETIMEDOUT;
}

__attribute__((used)) static int orion_mdio_smi_is_done(struct orion_mdio_dev *dev)
{
	return !(readl(dev->regs) & MVMDIO_SMI_BUSY);
}

__attribute__((used)) static int orion_mdio_smi_read(struct mii_bus *bus, int mii_id,
			       int regnum)
{
	struct orion_mdio_dev *dev = bus->priv;
	u32 val;
	int ret;

	if (regnum & MII_ADDR_C45)
		return -EOPNOTSUPP;

	ret = orion_mdio_wait_ready(&orion_mdio_smi_ops, bus);
	if (ret < 0)
		return ret;

	writel(((mii_id << MVMDIO_SMI_PHY_ADDR_SHIFT) |
		(regnum << MVMDIO_SMI_PHY_REG_SHIFT)  |
		MVMDIO_SMI_READ_OPERATION),
	       dev->regs);

	ret = orion_mdio_wait_ready(&orion_mdio_smi_ops, bus);
	if (ret < 0)
		return ret;

	val = readl(dev->regs);
	if (!(val & MVMDIO_SMI_READ_VALID)) {
		dev_err(bus->parent, "SMI bus read not valid\n");
		return -ENODEV;
	}

	return val & GENMASK(15, 0);
}

__attribute__((used)) static int orion_mdio_smi_write(struct mii_bus *bus, int mii_id,
				int regnum, u16 value)
{
	struct orion_mdio_dev *dev = bus->priv;
	int ret;

	if (regnum & MII_ADDR_C45)
		return -EOPNOTSUPP;

	ret = orion_mdio_wait_ready(&orion_mdio_smi_ops, bus);
	if (ret < 0)
		return ret;

	writel(((mii_id << MVMDIO_SMI_PHY_ADDR_SHIFT) |
		(regnum << MVMDIO_SMI_PHY_REG_SHIFT)  |
		MVMDIO_SMI_WRITE_OPERATION            |
		(value << MVMDIO_SMI_DATA_SHIFT)),
	       dev->regs);

	return 0;
}

__attribute__((used)) static int orion_mdio_xsmi_is_done(struct orion_mdio_dev *dev)
{
	return !(readl(dev->regs + MVMDIO_XSMI_MGNT_REG) & MVMDIO_XSMI_BUSY);
}

__attribute__((used)) static int orion_mdio_xsmi_read(struct mii_bus *bus, int mii_id,
				int regnum)
{
	struct orion_mdio_dev *dev = bus->priv;
	u16 dev_addr = (regnum >> 16) & GENMASK(4, 0);
	int ret;

	if (!(regnum & MII_ADDR_C45))
		return -EOPNOTSUPP;

	ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
	if (ret < 0)
		return ret;

	writel(regnum & GENMASK(15, 0), dev->regs + MVMDIO_XSMI_ADDR_REG);
	writel((mii_id << MVMDIO_XSMI_PHYADDR_SHIFT) |
	       (dev_addr << MVMDIO_XSMI_DEVADDR_SHIFT) |
	       MVMDIO_XSMI_READ_OPERATION,
	       dev->regs + MVMDIO_XSMI_MGNT_REG);

	ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
	if (ret < 0)
		return ret;

	if (!(readl(dev->regs + MVMDIO_XSMI_MGNT_REG) &
	      MVMDIO_XSMI_READ_VALID)) {
		dev_err(bus->parent, "XSMI bus read not valid\n");
		return -ENODEV;
	}

	return readl(dev->regs + MVMDIO_XSMI_MGNT_REG) & GENMASK(15, 0);
}

__attribute__((used)) static int orion_mdio_xsmi_write(struct mii_bus *bus, int mii_id,
				int regnum, u16 value)
{
	struct orion_mdio_dev *dev = bus->priv;
	u16 dev_addr = (regnum >> 16) & GENMASK(4, 0);
	int ret;

	if (!(regnum & MII_ADDR_C45))
		return -EOPNOTSUPP;

	ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
	if (ret < 0)
		return ret;

	writel(regnum & GENMASK(15, 0), dev->regs + MVMDIO_XSMI_ADDR_REG);
	writel((mii_id << MVMDIO_XSMI_PHYADDR_SHIFT) |
	       (dev_addr << MVMDIO_XSMI_DEVADDR_SHIFT) |
	       MVMDIO_XSMI_WRITE_OPERATION | value,
	       dev->regs + MVMDIO_XSMI_MGNT_REG);

	return 0;
}

__attribute__((used)) static irqreturn_t orion_mdio_err_irq(int irq, void *dev_id)
{
	struct orion_mdio_dev *dev = dev_id;

	if (readl(dev->regs + MVMDIO_ERR_INT_CAUSE) &
			MVMDIO_ERR_INT_SMI_DONE) {
		writel(~MVMDIO_ERR_INT_SMI_DONE,
				dev->regs + MVMDIO_ERR_INT_CAUSE);
		wake_up(&dev->smi_busy_wait);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

__attribute__((used)) static int orion_mdio_probe(struct platform_device *pdev)
{
	enum orion_mdio_bus_type type;
	struct resource *r;
	struct mii_bus *bus;
	struct orion_mdio_dev *dev;
	int i, ret;

	type = (enum orion_mdio_bus_type)of_device_get_match_data(&pdev->dev);

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!r) {
		dev_err(&pdev->dev, "No SMI register address given\n");
		return -ENODEV;
	}

	bus = devm_mdiobus_alloc_size(&pdev->dev,
				      sizeof(struct orion_mdio_dev));
	if (!bus)
		return -ENOMEM;

	switch (type) {
	case BUS_TYPE_SMI:
		bus->read = orion_mdio_smi_read;
		bus->write = orion_mdio_smi_write;
		break;
	case BUS_TYPE_XSMI:
		bus->read = orion_mdio_xsmi_read;
		bus->write = orion_mdio_xsmi_write;
		break;
	}

	bus->name = "orion_mdio_bus";
	snprintf(bus->id, MII_BUS_ID_SIZE, "%s-mii",
		 dev_name(&pdev->dev));
	bus->parent = &pdev->dev;

	dev = bus->priv;
	dev->regs = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (!dev->regs) {
		dev_err(&pdev->dev, "Unable to remap SMI register\n");
		return -ENODEV;
	}

	init_waitqueue_head(&dev->smi_busy_wait);

	for (i = 0; i < ARRAY_SIZE(dev->clk); i++) {
		dev->clk[i] = of_clk_get(pdev->dev.of_node, i);
		if (IS_ERR(dev->clk[i]))
			break;
		clk_prepare_enable(dev->clk[i]);
	}

	dev->err_interrupt = platform_get_irq(pdev, 0);
	if (dev->err_interrupt > 0 &&
	    resource_size(r) < MVMDIO_ERR_INT_MASK + 4) {
		dev_err(&pdev->dev,
			"disabling interrupt, resource size is too small\n");
		dev->err_interrupt = 0;
	}
	if (dev->err_interrupt > 0) {
		ret = devm_request_irq(&pdev->dev, dev->err_interrupt,
					orion_mdio_err_irq,
					IRQF_SHARED, pdev->name, dev);
		if (ret)
			goto out_mdio;

		writel(MVMDIO_ERR_INT_SMI_DONE,
			dev->regs + MVMDIO_ERR_INT_MASK);

	} else if (dev->err_interrupt == -EPROBE_DEFER) {
		ret = -EPROBE_DEFER;
		goto out_mdio;
	}

	ret = of_mdiobus_register(bus, pdev->dev.of_node);
	if (ret < 0) {
		dev_err(&pdev->dev, "Cannot register MDIO bus (%d)\n", ret);
		goto out_mdio;
	}

	platform_set_drvdata(pdev, bus);

	return 0;

out_mdio:
	if (dev->err_interrupt > 0)
		writel(0, dev->regs + MVMDIO_ERR_INT_MASK);

	for (i = 0; i < ARRAY_SIZE(dev->clk); i++) {
		if (IS_ERR(dev->clk[i]))
			break;
		clk_disable_unprepare(dev->clk[i]);
		clk_put(dev->clk[i]);
	}

	return ret;
}

__attribute__((used)) static int orion_mdio_remove(struct platform_device *pdev)
{
	struct mii_bus *bus = platform_get_drvdata(pdev);
	struct orion_mdio_dev *dev = bus->priv;
	int i;

	if (dev->err_interrupt > 0)
		writel(0, dev->regs + MVMDIO_ERR_INT_MASK);
	mdiobus_unregister(bus);

	for (i = 0; i < ARRAY_SIZE(dev->clk); i++) {
		if (IS_ERR(dev->clk[i]))
			break;
		clk_disable_unprepare(dev->clk[i]);
		clk_put(dev->clk[i]);
	}

	return 0;
}


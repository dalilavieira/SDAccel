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
struct xgbe_version_data {int /*<<< orphan*/  rx_max_fifo_size; int /*<<< orphan*/  tx_max_fifo_size; } ;
struct xgbe_prv_data {int use_acpi; int per_channel_irq; int coherent; int irq_count; int dev_irq; int* channel_irq; unsigned int channel_irq_count; int an_irq; struct platform_device* phy_platdev; int /*<<< orphan*/  netdev; struct platform_device* platdev; struct xgbe_version_data* vdata; int /*<<< orphan*/  rx_max_fifo_size; int /*<<< orphan*/  tx_max_fifo_size; int /*<<< orphan*/  awcr; int /*<<< orphan*/  arcr; int /*<<< orphan*/  channel_irq_mode; int /*<<< orphan*/  phy_mode; int /*<<< orphan*/  mac_addr; struct xgbe_prv_data* sir1_regs; struct xgbe_prv_data* sir0_regs; struct xgbe_prv_data* rxtx_regs; struct xgbe_prv_data* xpcs_regs; struct xgbe_prv_data* xgmac_regs; struct device* phy_dev; int /*<<< orphan*/  adev; int /*<<< orphan*/  dev; } ;
struct resource {int dummy; } ;
struct device {scalar_t__ of_node; } ;
struct platform_device {int num_resources; struct device dev; struct resource* resource; } ;
typedef  enum dev_dma_attr { ____Placeholder_dev_dma_attr } dev_dma_attr ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_COMPANION (struct device*) ; 
 unsigned int ARRAY_SIZE (int*) ; 
 int DEV_DMA_COHERENT ; 
 int DEV_DMA_NOT_SUPPORTED ; 
 int EINVAL ; 
 int ENODEV ; 
 unsigned int IORESOURCE_IRQ ; 
 unsigned int IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  PHY_INTERFACE_MODE_XGMII ; 
 int PTR_ERR (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  XGBE_DMA_IRQS_PROPERTY ; 
 int /*<<< orphan*/  XGBE_DMA_OS_ARCR ; 
 int /*<<< orphan*/  XGBE_DMA_OS_AWCR ; 
 int /*<<< orphan*/  XGBE_DMA_SYS_ARCR ; 
 int /*<<< orphan*/  XGBE_DMA_SYS_AWCR ; 
 int /*<<< orphan*/  XGBE_IRQ_MODE_EDGE ; 
 int /*<<< orphan*/  XGBE_MAC_ADDR_PROPERTY ; 
 int /*<<< orphan*/  XGBE_PHY_MODE_PROPERTY ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_notice (struct device*,char*) ; 
 int device_get_dma_attr (struct device*) ; 
 scalar_t__ device_property_present (struct device*,int /*<<< orphan*/ ) ; 
 int device_property_read_string (struct device*,int /*<<< orphan*/ ,char const**) ; 
 int device_property_read_u8_array (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void* devm_ioremap_resource (struct device*,struct resource*) ; 
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  is_valid_ether_addr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  netdev_notice (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ netif_msg_probe (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  phy_modes (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_put (struct platform_device*) ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_driver_unregister (int /*<<< orphan*/ *) ; 
 struct xgbe_prv_data* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,unsigned int,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xgbe_prv_data*) ; 
 unsigned int resource_type (struct resource*) ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 
 struct xgbe_prv_data* xgbe_alloc_pdata (struct device*) ; 
 int xgbe_config_netdev (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  xgbe_deconfig_netdev (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  xgbe_driver ; 
 int /*<<< orphan*/  xgbe_free_pdata (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  xgbe_set_counts (struct xgbe_prv_data*) ; 

__attribute__((used)) static inline int xgbe_pci_init(void) { return 0; }

__attribute__((used)) static inline void xgbe_pci_exit(void) { }

__attribute__((used)) static inline void xgbe_debugfs_init(struct xgbe_prv_data *pdata) {}

__attribute__((used)) static inline void xgbe_debugfs_exit(struct xgbe_prv_data *pdata) {}

__attribute__((used)) static inline void xgbe_debugfs_rename(struct xgbe_prv_data *pdata) {}

__attribute__((used)) static struct xgbe_version_data *xgbe_acpi_vdata(struct xgbe_prv_data *pdata)
{
	return NULL;
}

__attribute__((used)) static int xgbe_acpi_support(struct xgbe_prv_data *pdata)
{
	return -EINVAL;
}

__attribute__((used)) static struct xgbe_version_data *xgbe_of_vdata(struct xgbe_prv_data *pdata)
{
	return NULL;
}

__attribute__((used)) static int xgbe_of_support(struct xgbe_prv_data *pdata)
{
	return -EINVAL;
}

__attribute__((used)) static struct platform_device *xgbe_of_get_phy_pdev(struct xgbe_prv_data *pdata)
{
	return NULL;
}

__attribute__((used)) static unsigned int xgbe_resource_count(struct platform_device *pdev,
					unsigned int type)
{
	unsigned int count;
	int i;

	for (i = 0, count = 0; i < pdev->num_resources; i++) {
		struct resource *res = &pdev->resource[i];

		if (type == resource_type(res))
			count++;
	}

	return count;
}

__attribute__((used)) static struct platform_device *xgbe_get_phy_pdev(struct xgbe_prv_data *pdata)
{
	struct platform_device *phy_pdev;

	if (pdata->use_acpi) {
		get_device(pdata->dev);
		phy_pdev = pdata->platdev;
	} else {
		phy_pdev = xgbe_of_get_phy_pdev(pdata);
	}

	return phy_pdev;
}

__attribute__((used)) static struct xgbe_version_data *xgbe_get_vdata(struct xgbe_prv_data *pdata)
{
	return pdata->use_acpi ? xgbe_acpi_vdata(pdata)
			       : xgbe_of_vdata(pdata);
}

__attribute__((used)) static int xgbe_platform_probe(struct platform_device *pdev)
{
	struct xgbe_prv_data *pdata;
	struct device *dev = &pdev->dev;
	struct platform_device *phy_pdev;
	struct resource *res;
	const char *phy_mode;
	unsigned int phy_memnum, phy_irqnum;
	unsigned int dma_irqnum, dma_irqend;
	enum dev_dma_attr attr;
	int ret;

	pdata = xgbe_alloc_pdata(dev);
	if (IS_ERR(pdata)) {
		ret = PTR_ERR(pdata);
		goto err_alloc;
	}

	pdata->platdev = pdev;
	pdata->adev = ACPI_COMPANION(dev);
	platform_set_drvdata(pdev, pdata);

	/* Check if we should use ACPI or DT */
	pdata->use_acpi = dev->of_node ? 0 : 1;

	/* Get the version data */
	pdata->vdata = xgbe_get_vdata(pdata);

	phy_pdev = xgbe_get_phy_pdev(pdata);
	if (!phy_pdev) {
		dev_err(dev, "unable to obtain phy device\n");
		ret = -EINVAL;
		goto err_phydev;
	}
	pdata->phy_platdev = phy_pdev;
	pdata->phy_dev = &phy_pdev->dev;

	if (pdev == phy_pdev) {
		/* New style device tree or ACPI:
		 *   The XGBE and PHY resources are grouped together with
		 *   the PHY resources listed last
		 */
		phy_memnum = xgbe_resource_count(pdev, IORESOURCE_MEM) - 3;
		phy_irqnum = xgbe_resource_count(pdev, IORESOURCE_IRQ) - 1;
		dma_irqnum = 1;
		dma_irqend = phy_irqnum;
	} else {
		/* Old style device tree:
		 *   The XGBE and PHY resources are separate
		 */
		phy_memnum = 0;
		phy_irqnum = 0;
		dma_irqnum = 1;
		dma_irqend = xgbe_resource_count(pdev, IORESOURCE_IRQ);
	}

	/* Obtain the mmio areas for the device */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	pdata->xgmac_regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(pdata->xgmac_regs)) {
		dev_err(dev, "xgmac ioremap failed\n");
		ret = PTR_ERR(pdata->xgmac_regs);
		goto err_io;
	}
	if (netif_msg_probe(pdata))
		dev_dbg(dev, "xgmac_regs = %p\n", pdata->xgmac_regs);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	pdata->xpcs_regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(pdata->xpcs_regs)) {
		dev_err(dev, "xpcs ioremap failed\n");
		ret = PTR_ERR(pdata->xpcs_regs);
		goto err_io;
	}
	if (netif_msg_probe(pdata))
		dev_dbg(dev, "xpcs_regs  = %p\n", pdata->xpcs_regs);

	res = platform_get_resource(phy_pdev, IORESOURCE_MEM, phy_memnum++);
	pdata->rxtx_regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(pdata->rxtx_regs)) {
		dev_err(dev, "rxtx ioremap failed\n");
		ret = PTR_ERR(pdata->rxtx_regs);
		goto err_io;
	}
	if (netif_msg_probe(pdata))
		dev_dbg(dev, "rxtx_regs  = %p\n", pdata->rxtx_regs);

	res = platform_get_resource(phy_pdev, IORESOURCE_MEM, phy_memnum++);
	pdata->sir0_regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(pdata->sir0_regs)) {
		dev_err(dev, "sir0 ioremap failed\n");
		ret = PTR_ERR(pdata->sir0_regs);
		goto err_io;
	}
	if (netif_msg_probe(pdata))
		dev_dbg(dev, "sir0_regs  = %p\n", pdata->sir0_regs);

	res = platform_get_resource(phy_pdev, IORESOURCE_MEM, phy_memnum++);
	pdata->sir1_regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(pdata->sir1_regs)) {
		dev_err(dev, "sir1 ioremap failed\n");
		ret = PTR_ERR(pdata->sir1_regs);
		goto err_io;
	}
	if (netif_msg_probe(pdata))
		dev_dbg(dev, "sir1_regs  = %p\n", pdata->sir1_regs);

	/* Retrieve the MAC address */
	ret = device_property_read_u8_array(dev, XGBE_MAC_ADDR_PROPERTY,
					    pdata->mac_addr,
					    sizeof(pdata->mac_addr));
	if (ret || !is_valid_ether_addr(pdata->mac_addr)) {
		dev_err(dev, "invalid %s property\n", XGBE_MAC_ADDR_PROPERTY);
		if (!ret)
			ret = -EINVAL;
		goto err_io;
	}

	/* Retrieve the PHY mode - it must be "xgmii" */
	ret = device_property_read_string(dev, XGBE_PHY_MODE_PROPERTY,
					  &phy_mode);
	if (ret || strcmp(phy_mode, phy_modes(PHY_INTERFACE_MODE_XGMII))) {
		dev_err(dev, "invalid %s property\n", XGBE_PHY_MODE_PROPERTY);
		if (!ret)
			ret = -EINVAL;
		goto err_io;
	}
	pdata->phy_mode = PHY_INTERFACE_MODE_XGMII;

	/* Check for per channel interrupt support */
	if (device_property_present(dev, XGBE_DMA_IRQS_PROPERTY)) {
		pdata->per_channel_irq = 1;
		pdata->channel_irq_mode = XGBE_IRQ_MODE_EDGE;
	}

	/* Obtain device settings unique to ACPI/OF */
	if (pdata->use_acpi)
		ret = xgbe_acpi_support(pdata);
	else
		ret = xgbe_of_support(pdata);
	if (ret)
		goto err_io;

	/* Set the DMA coherency values */
	attr = device_get_dma_attr(dev);
	if (attr == DEV_DMA_NOT_SUPPORTED) {
		dev_err(dev, "DMA is not supported");
		ret = -ENODEV;
		goto err_io;
	}
	pdata->coherent = (attr == DEV_DMA_COHERENT);
	if (pdata->coherent) {
		pdata->arcr = XGBE_DMA_OS_ARCR;
		pdata->awcr = XGBE_DMA_OS_AWCR;
	} else {
		pdata->arcr = XGBE_DMA_SYS_ARCR;
		pdata->awcr = XGBE_DMA_SYS_AWCR;
	}

	/* Set the maximum fifo amounts */
	pdata->tx_max_fifo_size = pdata->vdata->tx_max_fifo_size;
	pdata->rx_max_fifo_size = pdata->vdata->rx_max_fifo_size;

	/* Set the hardware channel and queue counts */
	xgbe_set_counts(pdata);

	/* Always have XGMAC and XPCS (auto-negotiation) interrupts */
	pdata->irq_count = 2;

	/* Get the device interrupt */
	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		dev_err(dev, "platform_get_irq 0 failed\n");
		goto err_io;
	}
	pdata->dev_irq = ret;

	/* Get the per channel DMA interrupts */
	if (pdata->per_channel_irq) {
		unsigned int i, max = ARRAY_SIZE(pdata->channel_irq);

		for (i = 0; (i < max) && (dma_irqnum < dma_irqend); i++) {
			ret = platform_get_irq(pdata->platdev, dma_irqnum++);
			if (ret < 0) {
				netdev_err(pdata->netdev,
					   "platform_get_irq %u failed\n",
					   dma_irqnum - 1);
				goto err_io;
			}

			pdata->channel_irq[i] = ret;
		}

		pdata->channel_irq_count = max;

		pdata->irq_count += max;
	}

	/* Get the auto-negotiation interrupt */
	ret = platform_get_irq(phy_pdev, phy_irqnum++);
	if (ret < 0) {
		dev_err(dev, "platform_get_irq phy 0 failed\n");
		goto err_io;
	}
	pdata->an_irq = ret;

	/* Configure the netdev resource */
	ret = xgbe_config_netdev(pdata);
	if (ret)
		goto err_io;

	netdev_notice(pdata->netdev, "net device enabled\n");

	return 0;

err_io:
	platform_device_put(phy_pdev);

err_phydev:
	xgbe_free_pdata(pdata);

err_alloc:
	dev_notice(dev, "net device not enabled\n");

	return ret;
}

__attribute__((used)) static int xgbe_platform_remove(struct platform_device *pdev)
{
	struct xgbe_prv_data *pdata = platform_get_drvdata(pdev);

	xgbe_deconfig_netdev(pdata);

	platform_device_put(pdata->phy_platdev);

	xgbe_free_pdata(pdata);

	return 0;
}

int xgbe_platform_init(void)
{
	return platform_driver_register(&xgbe_driver);
}

void xgbe_platform_exit(void)
{
	platform_driver_unregister(&xgbe_driver);
}


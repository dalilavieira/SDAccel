#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct pci_device_id {int vendor; int device; int /*<<< orphan*/  subvendor; } ;
struct pci_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  subsystem_device; } ;
struct ddb_link {TYPE_1__* dev; } ;
struct ddb {int regs; int msi; int has_dma; TYPE_3__* link; struct pci_dev* pdev; int /*<<< orphan*/  regs_len; int /*<<< orphan*/ * dev; int /*<<< orphan*/  mutex; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;
struct TYPE_6__ {int vendor; int device; int devid; int hwid; int regmapid; int /*<<< orphan*/  subdevice; int /*<<< orphan*/  subvendor; } ;
struct TYPE_7__ {TYPE_2__ ids; TYPE_4__* info; struct ddb* dev; } ;
struct TYPE_5__ {int regs; } ;

/* Variables and functions */
 int DMA_BASE_READ ; 
 int DMA_BASE_WRITE ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int INTERRUPT_ENABLE ; 
 int IRQF_SHARED ; 
 int MSI1_ENABLE ; 
 int MSI2_ENABLE ; 
 int MSI3_ENABLE ; 
 int MSI4_ENABLE ; 
 int MSI5_ENABLE ; 
 int MSI6_ENABLE ; 
 int MSI7_ENABLE ; 
 int /*<<< orphan*/  ddb_buffers_free (struct ddb*) ; 
 int /*<<< orphan*/  ddb_device_destroy (struct ddb*) ; 
 int /*<<< orphan*/  ddb_i2c_release (struct ddb*) ; 
 scalar_t__ ddb_init (struct ddb*) ; 
 int /*<<< orphan*/  ddb_irq_handler ; 
 int /*<<< orphan*/  ddb_ports_detach (struct ddb*) ; 
 int /*<<< orphan*/  ddb_ports_release (struct ddb*) ; 
 int /*<<< orphan*/  ddb_unmap (struct ddb*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct ddb*) ; 
 TYPE_4__* get_ddb_info (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ioremap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy_fromio (void*,int,long) ; 
 int /*<<< orphan*/  memcpy_toio (int,void*,long) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 scalar_t__ pci_enable_device (struct pci_dev*) ; 
 scalar_t__ pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_irq_vector (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pci_resource_len (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 scalar_t__ pci_set_dma_mask (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct ddb*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int readl (int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,void*) ; 
 struct ddb* vzalloc (int) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline u32 ddblreadl(struct ddb_link *link, u32 adr)
{
	return readl(link->dev->regs + adr);
}

__attribute__((used)) static inline void ddblwritel(struct ddb_link *link, u32 val, u32 adr)
{
	writel(val, link->dev->regs + adr);
}

__attribute__((used)) static inline u32 ddbreadl(struct ddb *dev, u32 adr)
{
	return readl(dev->regs + adr);
}

__attribute__((used)) static inline void ddbwritel(struct ddb *dev, u32 val, u32 adr)
{
	writel(val, dev->regs + adr);
}

__attribute__((used)) static inline void ddbcpyto(struct ddb *dev, u32 adr, void *src, long count)
{
	memcpy_toio(dev->regs + adr, src, count);
}

__attribute__((used)) static inline void ddbcpyfrom(struct ddb *dev, void *dst, u32 adr, long count)
{
	memcpy_fromio(dst, dev->regs + adr, count);
}

__attribute__((used)) static inline u32 safe_ddbreadl(struct ddb *dev, u32 adr)
{
	u32 val = ddbreadl(dev, adr);

	/* (ddb)readl returns (uint)-1 (all bits set) on failure, catch that */
	if (val == ~0) {
		dev_err(&dev->pdev->dev, "ddbreadl failure, adr=%08x\n", adr);
		return 0;
	}

	return val;
}

__attribute__((used)) static void ddb_irq_disable(struct ddb *dev)
{
	ddbwritel(dev, 0, INTERRUPT_ENABLE);
	ddbwritel(dev, 0, MSI1_ENABLE);
}

__attribute__((used)) static void ddb_msi_exit(struct ddb *dev)
{
#ifdef CONFIG_PCI_MSI
	if (dev->msi)
		pci_free_irq_vectors(dev->pdev);
#endif
}

__attribute__((used)) static void ddb_irq_exit(struct ddb *dev)
{
	ddb_irq_disable(dev);
	if (dev->msi == 2)
		free_irq(pci_irq_vector(dev->pdev, 1), dev);
	free_irq(pci_irq_vector(dev->pdev, 0), dev);
}

__attribute__((used)) static void ddb_remove(struct pci_dev *pdev)
{
	struct ddb *dev = (struct ddb *)pci_get_drvdata(pdev);

	ddb_device_destroy(dev);
	ddb_ports_detach(dev);
	ddb_i2c_release(dev);

	ddb_irq_exit(dev);
	ddb_msi_exit(dev);
	ddb_ports_release(dev);
	ddb_buffers_free(dev);

	ddb_unmap(dev);
	pci_set_drvdata(pdev, NULL);
	pci_disable_device(pdev);
}

__attribute__((used)) static int ddb_irq_init(struct ddb *dev)
{
	int stat;
	int irq_flag = IRQF_SHARED;

	ddbwritel(dev, 0x00000000, INTERRUPT_ENABLE);
	ddbwritel(dev, 0x00000000, MSI1_ENABLE);
	ddbwritel(dev, 0x00000000, MSI2_ENABLE);
	ddbwritel(dev, 0x00000000, MSI3_ENABLE);
	ddbwritel(dev, 0x00000000, MSI4_ENABLE);
	ddbwritel(dev, 0x00000000, MSI5_ENABLE);
	ddbwritel(dev, 0x00000000, MSI6_ENABLE);
	ddbwritel(dev, 0x00000000, MSI7_ENABLE);

#ifdef CONFIG_PCI_MSI
	ddb_irq_msi(dev, 2);

	if (dev->msi)
		irq_flag = 0;
	if (dev->msi == 2) {
		stat = request_irq(pci_irq_vector(dev->pdev, 0),
				   ddb_irq_handler0, irq_flag, "ddbridge",
				   (void *)dev);
		if (stat < 0)
			return stat;
		stat = request_irq(pci_irq_vector(dev->pdev, 1),
				   ddb_irq_handler1, irq_flag, "ddbridge",
				   (void *)dev);
		if (stat < 0) {
			free_irq(pci_irq_vector(dev->pdev, 0), dev);
			return stat;
		}
	} else
#endif
	{
		stat = request_irq(pci_irq_vector(dev->pdev, 0),
				   ddb_irq_handler, irq_flag, "ddbridge",
				   (void *)dev);
		if (stat < 0)
			return stat;
	}
	if (dev->msi == 2) {
		ddbwritel(dev, 0x0fffff00, INTERRUPT_ENABLE);
		ddbwritel(dev, 0x0000000f, MSI1_ENABLE);
	} else {
		ddbwritel(dev, 0x0fffff0f, INTERRUPT_ENABLE);
		ddbwritel(dev, 0x00000000, MSI1_ENABLE);
	}
	return stat;
}

__attribute__((used)) static int ddb_probe(struct pci_dev *pdev,
		     const struct pci_device_id *id)
{
	struct ddb *dev;
	int stat = 0;

	if (pci_enable_device(pdev) < 0)
		return -ENODEV;

	pci_set_master(pdev);

	if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64)))
		if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))
			return -ENODEV;

	dev = vzalloc(sizeof(*dev));
	if (!dev)
		return -ENOMEM;

	mutex_init(&dev->mutex);
	dev->has_dma = 1;
	dev->pdev = pdev;
	dev->dev = &pdev->dev;
	pci_set_drvdata(pdev, dev);

	dev->link[0].ids.vendor = id->vendor;
	dev->link[0].ids.device = id->device;
	dev->link[0].ids.subvendor = id->subvendor;
	dev->link[0].ids.subdevice = pdev->subsystem_device;
	dev->link[0].ids.devid = (id->device << 16) | id->vendor;

	dev->link[0].dev = dev;
	dev->link[0].info = get_ddb_info(id->vendor, id->device,
					 id->subvendor, pdev->subsystem_device);

	dev_info(&pdev->dev, "detected %s\n", dev->link[0].info->name);

	dev->regs_len = pci_resource_len(dev->pdev, 0);
	dev->regs = ioremap(pci_resource_start(dev->pdev, 0),
			    pci_resource_len(dev->pdev, 0));

	if (!dev->regs) {
		dev_err(&pdev->dev, "not enough memory for register map\n");
		stat = -ENOMEM;
		goto fail;
	}
	if (ddbreadl(dev, 0) == 0xffffffff) {
		dev_err(&pdev->dev, "cannot read registers\n");
		stat = -ENODEV;
		goto fail;
	}

	dev->link[0].ids.hwid = ddbreadl(dev, 0);
	dev->link[0].ids.regmapid = ddbreadl(dev, 4);

	dev_info(&pdev->dev, "HW %08x REGMAP %08x\n",
		 dev->link[0].ids.hwid, dev->link[0].ids.regmapid);

	ddbwritel(dev, 0, DMA_BASE_READ);
	ddbwritel(dev, 0, DMA_BASE_WRITE);

	stat = ddb_irq_init(dev);
	if (stat < 0)
		goto fail0;

	if (ddb_init(dev) == 0)
		return 0;

	ddb_irq_exit(dev);
fail0:
	dev_err(&pdev->dev, "fail0\n");
	ddb_msi_exit(dev);
fail:
	dev_err(&pdev->dev, "fail\n");

	ddb_unmap(dev);
	pci_set_drvdata(pdev, NULL);
	pci_disable_device(pdev);
	return -1;
}


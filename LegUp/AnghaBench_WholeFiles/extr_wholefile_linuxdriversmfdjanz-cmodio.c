#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct resource {scalar_t__ end; scalar_t__ start; TYPE_1__* parent; void* flags; } ;
struct pci_device_id {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  kobj; } ;
struct pci_dev {TYPE_3__ dev; int /*<<< orphan*/  irq; TYPE_1__* resource; } ;
struct mfd_cell {char* name; int num_resources; int pdata_size; struct janz_platform_data* platform_data; scalar_t__ id; struct resource* resources; } ;
struct janz_platform_data {unsigned int modno; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct cmodio_device {int hex; TYPE_2__* ctrl; struct pci_dev* pdev; struct mfd_cell* cells; struct janz_platform_data* pdata; struct resource* resources; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_10__ {int /*<<< orphan*/  int_disable; int /*<<< orphan*/  int_enable; } ;
struct TYPE_9__ {scalar_t__ end; scalar_t__ start; } ;

/* Variables and functions */
 unsigned int CMODIO_MODULBUS_SIZE ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* IORESOURCE_IRQ ; 
 void* IORESOURCE_MEM ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  cmodio_id ; 
 int /*<<< orphan*/  cmodio_sysfs_attr_group ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,int,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 struct cmodio_device* dev_get_drvdata (struct device*) ; 
 struct cmodio_device* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int ioread8 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iounmap (TYPE_2__*) ; 
 int /*<<< orphan*/  iowrite8 (int,int /*<<< orphan*/ *) ; 
 int mfd_add_devices (TYPE_3__*,int /*<<< orphan*/ ,struct mfd_cell*,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (TYPE_3__*) ; 
 char** modules ; 
 int num_modules ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct cmodio_device* pci_get_drvdata (struct pci_dev*) ; 
 TYPE_2__* pci_ioremap_bar (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct cmodio_device*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int cmodio_setup_subdevice(struct cmodio_device *priv,
					    char *name, unsigned int devno,
					    unsigned int modno)
{
	struct janz_platform_data *pdata;
	struct mfd_cell *cell;
	struct resource *res;
	struct pci_dev *pci;

	pci = priv->pdev;
	cell = &priv->cells[devno];
	res = &priv->resources[devno * 3];
	pdata = &priv->pdata[devno];

	cell->name = name;
	cell->resources = res;
	cell->num_resources = 3;

	/* Setup the subdevice ID -- must be unique */
	cell->id = cmodio_id++;

	/* Add platform data */
	pdata->modno = modno;
	cell->platform_data = pdata;
	cell->pdata_size = sizeof(*pdata);

	/* MODULbus registers -- PCI BAR3 is big-endian MODULbus access */
	res->flags = IORESOURCE_MEM;
	res->parent = &pci->resource[3];
	res->start = pci->resource[3].start + (CMODIO_MODULBUS_SIZE * modno);
	res->end = res->start + CMODIO_MODULBUS_SIZE - 1;
	res++;

	/* PLX Control Registers -- PCI BAR4 is interrupt and other registers */
	res->flags = IORESOURCE_MEM;
	res->parent = &pci->resource[4];
	res->start = pci->resource[4].start;
	res->end = pci->resource[4].end;
	res++;

	/*
	 * IRQ
	 *
	 * The start and end fields are used as an offset to the irq_base
	 * parameter passed into the mfd_add_devices() function call. All
	 * devices share the same IRQ.
	 */
	res->flags = IORESOURCE_IRQ;
	res->parent = NULL;
	res->start = 0;
	res->end = 0;
	res++;

	return 0;
}

__attribute__((used)) static int cmodio_probe_submodules(struct cmodio_device *priv)
{
	struct pci_dev *pdev = priv->pdev;
	unsigned int num_probed = 0;
	char *name;
	int i;

	for (i = 0; i < num_modules; i++) {
		name = modules[i];
		if (!strcmp(name, "") || !strcmp(name, "empty"))
			continue;

		dev_dbg(&priv->pdev->dev, "MODULbus %d: name %s\n", i, name);
		cmodio_setup_subdevice(priv, name, num_probed, i);
		num_probed++;
	}

	/* print an error message if no modules were probed */
	if (num_probed == 0) {
		dev_err(&priv->pdev->dev, "no MODULbus modules specified, "
					  "please set the ``modules'' kernel "
					  "parameter according to your "
					  "hardware configuration\n");
		return -ENODEV;
	}

	return mfd_add_devices(&pdev->dev, 0, priv->cells,
			       num_probed, NULL, pdev->irq, NULL);
}

__attribute__((used)) static ssize_t mbus_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct cmodio_device *priv = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%x\n", priv->hex);
}

__attribute__((used)) static int cmodio_pci_probe(struct pci_dev *dev,
				      const struct pci_device_id *id)
{
	struct cmodio_device *priv;
	int ret;

	priv = devm_kzalloc(&dev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	pci_set_drvdata(dev, priv);
	priv->pdev = dev;

	/* Hardware Initialization */
	ret = pci_enable_device(dev);
	if (ret) {
		dev_err(&dev->dev, "unable to enable device\n");
		return ret;
	}

	pci_set_master(dev);
	ret = pci_request_regions(dev, DRV_NAME);
	if (ret) {
		dev_err(&dev->dev, "unable to request regions\n");
		goto out_pci_disable_device;
	}

	/* Onboard configuration registers */
	priv->ctrl = pci_ioremap_bar(dev, 4);
	if (!priv->ctrl) {
		dev_err(&dev->dev, "unable to remap onboard regs\n");
		ret = -ENOMEM;
		goto out_pci_release_regions;
	}

	/* Read the hex switch on the carrier board */
	priv->hex = ioread8(&priv->ctrl->int_enable);

	/* Add the MODULbus number (hex switch value) to the device's sysfs */
	ret = sysfs_create_group(&dev->dev.kobj, &cmodio_sysfs_attr_group);
	if (ret) {
		dev_err(&dev->dev, "unable to create sysfs attributes\n");
		goto out_unmap_ctrl;
	}

	/*
	 * Disable all interrupt lines, each submodule will enable its
	 * own interrupt line if needed
	 */
	iowrite8(0xf, &priv->ctrl->int_disable);

	/* Register drivers for all submodules */
	ret = cmodio_probe_submodules(priv);
	if (ret) {
		dev_err(&dev->dev, "unable to probe submodules\n");
		goto out_sysfs_remove_group;
	}

	return 0;

out_sysfs_remove_group:
	sysfs_remove_group(&dev->dev.kobj, &cmodio_sysfs_attr_group);
out_unmap_ctrl:
	iounmap(priv->ctrl);
out_pci_release_regions:
	pci_release_regions(dev);
out_pci_disable_device:
	pci_disable_device(dev);

	return ret;
}

__attribute__((used)) static void cmodio_pci_remove(struct pci_dev *dev)
{
	struct cmodio_device *priv = pci_get_drvdata(dev);

	mfd_remove_devices(&dev->dev);
	sysfs_remove_group(&dev->dev.kobj, &cmodio_sysfs_attr_group);
	iounmap(priv->ctrl);
	pci_release_regions(dev);
	pci_disable_device(dev);
}


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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  subsystem_device; int /*<<< orphan*/  subsystem_vendor; TYPE_4__* driver; int /*<<< orphan*/  dev; } ;
struct bcma_drv_pci {int dummy; } ;
struct bcma_drv_mips {int dummy; } ;
struct bcma_drv_gmac_cmn {int dummy; } ;
struct bcma_drv_cc {TYPE_2__* core; } ;
struct TYPE_8__ {int id; } ;
struct bcma_device {int addr; int wrap; int /*<<< orphan*/  core_index; TYPE_5__* bus; TYPE_3__ id; } ;
struct TYPE_6__ {int /*<<< orphan*/  type; int /*<<< orphan*/  vendor; } ;
struct bcma_bus {scalar_t__ hosttype; int host_is_pcie2; struct pci_dev* host_pci; int /*<<< orphan*/ * drv_pci; int /*<<< orphan*/  mmio; TYPE_1__ boardinfo; int /*<<< orphan*/ * ops; } ;
struct TYPE_10__ {int mmio; struct bcma_device* mapped_core; struct pci_dev* host_pci; scalar_t__ host_is_pcie2; } ;
struct TYPE_9__ {char* name; } ;
struct TYPE_7__ {struct bcma_bus* bus; } ;

/* Variables and functions */
#define  BCMA_CORE_CHIPCOMMON 129 
#define  BCMA_CORE_PCIE 128 
 int /*<<< orphan*/  BCMA_CORE_PCIE2 ; 
 int BCMA_CORE_SIZE ; 
 scalar_t__ BCMA_HOSTTYPE_PCI ; 
 int BCMA_PCIE2_BAR0_WIN2 ; 
 int BCMA_PCI_BAR0_WIN ; 
 int BCMA_PCI_BAR0_WIN2 ; 
 int BCMA_PCI_IRQMASK ; 
 int BIT (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int bcma_bus_register (struct bcma_bus*) ; 
 int bcma_bus_scan (struct bcma_bus*) ; 
 int /*<<< orphan*/  bcma_bus_unregister (struct bcma_bus*) ; 
 int /*<<< orphan*/  bcma_core_pci_down (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bcma_debug (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  bcma_err (struct bcma_bus*,char*) ; 
 scalar_t__ bcma_find_core (struct bcma_bus*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcma_host_pci_ops ; 
 int /*<<< orphan*/  bcma_init_bus (struct bcma_bus*) ; 
 int /*<<< orphan*/  bcma_unregister_cores (struct bcma_bus*) ; 
 char* dev_name (int /*<<< orphan*/ *) ; 
 int ioread16 (int) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  ioread8 (int) ; 
 int /*<<< orphan*/  iowrite16 (int,int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  iowrite8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kfree (struct bcma_bus*) ; 
 struct bcma_bus* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct bcma_bus* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_iomap (struct pci_dev*,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_is_pcie (struct pci_dev*) ; 
 int pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,char const*) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct bcma_bus*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int pci_write_config_dword (struct pci_dev*,int,int) ; 

__attribute__((used)) static inline int bcma_pflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "Parallel flash not supported\n");
	return 0;
}

__attribute__((used)) static inline int bcma_sflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "Serial flash not supported\n");
	return 0;
}

__attribute__((used)) static inline int bcma_nflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "NAND flash not supported\n");
	return 0;
}

__attribute__((used)) static inline bool bcma_core_pci_is_in_hostmode(struct bcma_drv_pci *pc)
{
	return false;
}

__attribute__((used)) static inline void bcma_core_pci_hostmode_init(struct bcma_drv_pci *pc)
{
}

__attribute__((used)) static inline unsigned int bcma_core_mips_irq(struct bcma_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void bcma_core_mips_early_init(struct bcma_drv_mips *mcore)
{
}

__attribute__((used)) static inline void bcma_core_mips_init(struct bcma_drv_mips *mcore)
{
}

__attribute__((used)) static inline void bcma_core_gmac_cmn_init(struct bcma_drv_gmac_cmn *gc)
{
}

__attribute__((used)) static inline int bcma_gpio_init(struct bcma_drv_cc *cc)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline int bcma_gpio_unregister(struct bcma_drv_cc *cc)
{
	return 0;
}

__attribute__((used)) static void bcma_host_pci_switch_core(struct bcma_device *core)
{
	int win2 = core->bus->host_is_pcie2 ?
		BCMA_PCIE2_BAR0_WIN2 : BCMA_PCI_BAR0_WIN2;

	pci_write_config_dword(core->bus->host_pci, BCMA_PCI_BAR0_WIN,
			       core->addr);
	pci_write_config_dword(core->bus->host_pci, win2, core->wrap);
	core->bus->mapped_core = core;
	bcma_debug(core->bus, "Switched to core: 0x%X\n", core->id.id);
}

__attribute__((used)) static u16 bcma_host_pci_provide_access_to_core(struct bcma_device *core)
{
	switch (core->id.id) {
	case BCMA_CORE_CHIPCOMMON:
		return 3 * BCMA_CORE_SIZE;
	case BCMA_CORE_PCIE:
		return 2 * BCMA_CORE_SIZE;
	}

	if (core->bus->mapped_core != core)
		bcma_host_pci_switch_core(core);
	return 0;
}

__attribute__((used)) static u8 bcma_host_pci_read8(struct bcma_device *core, u16 offset)
{
	offset += bcma_host_pci_provide_access_to_core(core);
	return ioread8(core->bus->mmio + offset);
}

__attribute__((used)) static u16 bcma_host_pci_read16(struct bcma_device *core, u16 offset)
{
	offset += bcma_host_pci_provide_access_to_core(core);
	return ioread16(core->bus->mmio + offset);
}

__attribute__((used)) static u32 bcma_host_pci_read32(struct bcma_device *core, u16 offset)
{
	offset += bcma_host_pci_provide_access_to_core(core);
	return ioread32(core->bus->mmio + offset);
}

__attribute__((used)) static void bcma_host_pci_write8(struct bcma_device *core, u16 offset,
				 u8 value)
{
	offset += bcma_host_pci_provide_access_to_core(core);
	iowrite8(value, core->bus->mmio + offset);
}

__attribute__((used)) static void bcma_host_pci_write16(struct bcma_device *core, u16 offset,
				 u16 value)
{
	offset += bcma_host_pci_provide_access_to_core(core);
	iowrite16(value, core->bus->mmio + offset);
}

__attribute__((used)) static void bcma_host_pci_write32(struct bcma_device *core, u16 offset,
				 u32 value)
{
	offset += bcma_host_pci_provide_access_to_core(core);
	iowrite32(value, core->bus->mmio + offset);
}

__attribute__((used)) static u32 bcma_host_pci_aread32(struct bcma_device *core, u16 offset)
{
	if (core->bus->mapped_core != core)
		bcma_host_pci_switch_core(core);
	return ioread32(core->bus->mmio + (1 * BCMA_CORE_SIZE) + offset);
}

__attribute__((used)) static void bcma_host_pci_awrite32(struct bcma_device *core, u16 offset,
				  u32 value)
{
	if (core->bus->mapped_core != core)
		bcma_host_pci_switch_core(core);
	iowrite32(value, core->bus->mmio + (1 * BCMA_CORE_SIZE) + offset);
}

__attribute__((used)) static int bcma_host_pci_probe(struct pci_dev *dev,
			       const struct pci_device_id *id)
{
	struct bcma_bus *bus;
	int err = -ENOMEM;
	const char *name;
	u32 val;

	/* Alloc */
	bus = kzalloc(sizeof(*bus), GFP_KERNEL);
	if (!bus)
		goto out;

	/* Basic PCI configuration */
	err = pci_enable_device(dev);
	if (err)
		goto err_kfree_bus;

	name = dev_name(&dev->dev);
	if (dev->driver && dev->driver->name)
		name = dev->driver->name;
	err = pci_request_regions(dev, name);
	if (err)
		goto err_pci_disable;
	pci_set_master(dev);

	/* Disable the RETRY_TIMEOUT register (0x41) to keep
	 * PCI Tx retries from interfering with C3 CPU state */
	pci_read_config_dword(dev, 0x40, &val);
	if ((val & 0x0000ff00) != 0)
		pci_write_config_dword(dev, 0x40, val & 0xffff00ff);

	/* SSB needed additional powering up, do we have any AMBA PCI cards? */
	if (!pci_is_pcie(dev)) {
		bcma_err(bus, "PCI card detected, they are not supported.\n");
		err = -ENXIO;
		goto err_pci_release_regions;
	}

	/* Map MMIO */
	err = -ENOMEM;
	bus->mmio = pci_iomap(dev, 0, ~0UL);
	if (!bus->mmio)
		goto err_pci_release_regions;

	/* Host specific */
	bus->host_pci = dev;
	bus->hosttype = BCMA_HOSTTYPE_PCI;
	bus->ops = &bcma_host_pci_ops;

	bus->boardinfo.vendor = bus->host_pci->subsystem_vendor;
	bus->boardinfo.type = bus->host_pci->subsystem_device;

	/* Initialize struct, detect chip */
	bcma_init_bus(bus);

	/* Scan bus to find out generation of PCIe core */
	err = bcma_bus_scan(bus);
	if (err)
		goto err_pci_unmap_mmio;

	if (bcma_find_core(bus, BCMA_CORE_PCIE2))
		bus->host_is_pcie2 = true;

	/* Register */
	err = bcma_bus_register(bus);
	if (err)
		goto err_unregister_cores;

	pci_set_drvdata(dev, bus);

out:
	return err;

err_unregister_cores:
	bcma_unregister_cores(bus);
err_pci_unmap_mmio:
	pci_iounmap(dev, bus->mmio);
err_pci_release_regions:
	pci_release_regions(dev);
err_pci_disable:
	pci_disable_device(dev);
err_kfree_bus:
	kfree(bus);
	return err;
}

__attribute__((used)) static void bcma_host_pci_remove(struct pci_dev *dev)
{
	struct bcma_bus *bus = pci_get_drvdata(dev);

	bcma_bus_unregister(bus);
	pci_iounmap(dev, bus->mmio);
	pci_release_regions(dev);
	pci_disable_device(dev);
	kfree(bus);
}

void bcma_host_pci_down(struct bcma_bus *bus)
{
	if (bus->hosttype != BCMA_HOSTTYPE_PCI)
		return;

	if (!bus->host_is_pcie2)
		bcma_core_pci_down(&bus->drv_pci[0]);
}

int bcma_host_pci_irq_ctl(struct bcma_bus *bus, struct bcma_device *core,
			  bool enable)
{
	struct pci_dev *pdev;
	u32 coremask, tmp;
	int err = 0;

	if (bus->hosttype != BCMA_HOSTTYPE_PCI) {
		/* This bcma device is not on a PCI host-bus. So the IRQs are
		 * not routed through the PCI core.
		 * So we must not enable routing through the PCI core. */
		goto out;
	}

	pdev = bus->host_pci;

	err = pci_read_config_dword(pdev, BCMA_PCI_IRQMASK, &tmp);
	if (err)
		goto out;

	coremask = BIT(core->core_index) << 8;
	if (enable)
		tmp |= coremask;
	else
		tmp &= ~coremask;

	err = pci_write_config_dword(pdev, BCMA_PCI_IRQMASK, tmp);

out:
	return err;
}


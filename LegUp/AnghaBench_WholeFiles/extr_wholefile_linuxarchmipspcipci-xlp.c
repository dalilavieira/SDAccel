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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct pci_dev {unsigned int devfn; struct pci_bus* bus; } ;
struct pci_bus {scalar_t__ number; struct pci_dev* self; struct pci_bus* parent; } ;

/* Variables and functions */
 int PCIBIOS_BAD_REGISTER_NUMBER ; 
 int PCIBIOS_SUCCESSFUL ; 
 int PCI_FUNC (unsigned int) ; 
 int PCI_SLOT (unsigned int) ; 
 int /*<<< orphan*/  PIC_PCIE_LINK_LEGACY_IRQ (int) ; 
 scalar_t__ cpu_is_xlp9xx () ; 
 int nlm_irq_to_xirq (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlm_node_present (int) ; 
 scalar_t__ pci_cfg_addr (scalar_t__,unsigned int,int) ; 
 scalar_t__ pci_config_base ; 

__attribute__((used)) static inline u32 pci_cfg_read_32bit(struct pci_bus *bus, unsigned int devfn,
	int where)
{
	u32 data;
	u32 *cfgaddr;

	where &= ~3;
	if (cpu_is_xlp9xx()) {
		/* be very careful on SoC buses */
		if (bus->number == 0) {
			/* Scan only existing nodes - uboot bug? */
			if (PCI_SLOT(devfn) != 0 ||
					   !nlm_node_present(PCI_FUNC(devfn)))
				return 0xffffffff;
		} else if (bus->parent->number == 0) {	/* SoC bus */
			if (PCI_SLOT(devfn) == 0)	/* b.0.0 hangs */
				return 0xffffffff;
			if (devfn == 44)		/* b.5.4 hangs */
				return 0xffffffff;
		}
	} else if (bus->number == 0 && PCI_SLOT(devfn) == 1 && where == 0x954) {
		return 0xffffffff;
	}
	cfgaddr = (u32 *)(pci_config_base +
			pci_cfg_addr(bus->number, devfn, where));
	data = *cfgaddr;
	return data;
}

__attribute__((used)) static inline void pci_cfg_write_32bit(struct pci_bus *bus, unsigned int devfn,
	int where, u32 data)
{
	u32 *cfgaddr;

	cfgaddr = (u32 *)(pci_config_base +
			pci_cfg_addr(bus->number, devfn, where & ~3));
	*cfgaddr = data;
}

__attribute__((used)) static int nlm_pcibios_read(struct pci_bus *bus, unsigned int devfn,
	int where, int size, u32 *val)
{
	u32 data;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	data = pci_cfg_read_32bit(bus, devfn, where);

	if (size == 1)
		*val = (data >> ((where & 3) << 3)) & 0xff;
	else if (size == 2)
		*val = (data >> ((where & 3) << 3)) & 0xffff;
	else
		*val = data;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int nlm_pcibios_write(struct pci_bus *bus, unsigned int devfn,
		int where, int size, u32 val)
{
	u32 data;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	data = pci_cfg_read_32bit(bus, devfn, where);

	if (size == 1)
		data = (data & ~(0xff << ((where & 3) << 3))) |
			(val << ((where & 3) << 3));
	else if (size == 2)
		data = (data & ~(0xffff << ((where & 3) << 3))) |
			(val << ((where & 3) << 3));
	else
		data = val;

	pci_cfg_write_32bit(bus, devfn, where, data);

	return PCIBIOS_SUCCESSFUL;
}

struct pci_dev *xlp_get_pcie_link(const struct pci_dev *dev)
{
	struct pci_bus *bus, *p;

	bus = dev->bus;

	if (cpu_is_xlp9xx()) {
		/* find bus with grand parent number == 0 */
		for (p = bus->parent; p && p->parent && p->parent->number != 0;
				p = p->parent)
			bus = p;
		return (p && p->parent) ? bus->self : NULL;
	} else {
		/* Find the bridge on bus 0 */
		for (p = bus->parent; p && p->number != 0; p = p->parent)
			bus = p;

		return p ? bus->self : NULL;
	}
}

int xlp_socdev_to_node(const struct pci_dev *lnkdev)
{
	if (cpu_is_xlp9xx())
		return PCI_FUNC(lnkdev->bus->self->devfn);
	else
		return PCI_SLOT(lnkdev->devfn) / 8;
}

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	struct pci_dev *lnkdev;
	int lnkfunc, node;

	/*
	 * For XLP PCIe, there is an IRQ per Link, find out which
	 * link the device is on to assign interrupts
	*/
	lnkdev = xlp_get_pcie_link(dev);
	if (lnkdev == NULL)
		return 0;

	lnkfunc = PCI_FUNC(lnkdev->devfn);
	node = xlp_socdev_to_node(lnkdev);

	return nlm_irq_to_xirq(node, PIC_PCIE_LINK_LEGACY_IRQ(lnkfunc));
}

int pcibios_plat_dev_init(struct pci_dev *dev)
{
	return 0;
}

__attribute__((used)) static inline void xlp_config_pci_bswap(int node, int link) {}


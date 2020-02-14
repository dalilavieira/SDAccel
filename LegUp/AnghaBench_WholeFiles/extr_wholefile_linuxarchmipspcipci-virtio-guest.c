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
union pci_config_address {int register_number; unsigned int devfn_number; int enable_bit; int /*<<< orphan*/  w; int /*<<< orphan*/  bus_number; } ;
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct pci_dev {int dummy; } ;
struct pci_bus {int /*<<< orphan*/  number; } ;

/* Variables and functions */
 int MIPS_IRQ_PCIA ; 
 int PCIBIOS_SUCCESSFUL ; 
 int /*<<< orphan*/  PCI_CONFIG_ADDRESS ; 
 int /*<<< orphan*/  PCI_CONFIG_DATA ; 
 int /*<<< orphan*/  inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outw (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int pcibios_plat_dev_init(struct pci_dev *dev)
{
	return 0;
}

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	return ((pin + slot) % 4)+ MIPS_IRQ_PCIA;
}

__attribute__((used)) static void pci_virtio_guest_write_config_addr(struct pci_bus *bus,
					unsigned int devfn, int reg)
{
	union pci_config_address pca = { .w = 0 };

	pca.register_number = reg;
	pca.devfn_number = devfn;
	pca.bus_number = bus->number;
	pca.enable_bit = 1;

	outl(pca.w, PCI_CONFIG_ADDRESS);
}

__attribute__((used)) static int pci_virtio_guest_write_config(struct pci_bus *bus,
		unsigned int devfn, int reg, int size, u32 val)
{
	pci_virtio_guest_write_config_addr(bus, devfn, reg);

	switch (size) {
	case 1:
		outb(val, PCI_CONFIG_DATA + (reg & 3));
		break;
	case 2:
		outw(val, PCI_CONFIG_DATA + (reg & 2));
		break;
	case 4:
		outl(val, PCI_CONFIG_DATA);
		break;
	}

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int pci_virtio_guest_read_config(struct pci_bus *bus, unsigned int devfn,
					int reg, int size, u32 *val)
{
	pci_virtio_guest_write_config_addr(bus, devfn, reg);

	switch (size) {
	case 1:
		*val = inb(PCI_CONFIG_DATA + (reg & 3));
		break;
	case 2:
		*val = inw(PCI_CONFIG_DATA + (reg & 2));
		break;
	case 4:
		*val = inl(PCI_CONFIG_DATA);
		break;
	}
	return PCIBIOS_SUCCESSFUL;
}


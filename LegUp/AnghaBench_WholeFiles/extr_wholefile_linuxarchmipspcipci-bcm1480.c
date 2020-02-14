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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct pci_dev {int dummy; } ;
struct pci_bus {scalar_t__ number; } ;

/* Variables and functions */
 int CFGADDR (struct pci_bus*,unsigned int,int) ; 
 int K_BCM1480_INT_PCI_INTA ; 
 int PCIBIOS_BAD_REGISTER_NUMBER ; 
 int PCIBIOS_SUCCESSFUL ; 
 int PCI_BUS_ENABLED ; 
 int PCI_DEVICE_MODE ; 
 int PCI_SLOT (int) ; 
 int bcm1480_bus_status ; 
 scalar_t__ cfg_space ; 

__attribute__((used)) static inline u32 READCFG32(u32 addr)
{
	return *(u32 *)(cfg_space + (addr&~3));
}

__attribute__((used)) static inline void WRITECFG32(u32 addr, u32 data)
{
	*(u32 *)(cfg_space + (addr & ~3)) = data;
}

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	if (pin == 0)
		return -1;

	return K_BCM1480_INT_PCI_INTA - 1 + pin;
}

int pcibios_plat_dev_init(struct pci_dev *dev)
{
	return 0;
}

__attribute__((used)) static int bcm1480_pci_can_access(struct pci_bus *bus, int devfn)
{
	u32 devno;

	if (!(bcm1480_bus_status & (PCI_BUS_ENABLED | PCI_DEVICE_MODE)))
		return 0;

	if (bus->number == 0) {
		devno = PCI_SLOT(devfn);
		if (bcm1480_bus_status & PCI_DEVICE_MODE)
			return 0;
		else
			return 1;
	} else
		return 1;
}

__attribute__((used)) static int bcm1480_pcibios_read(struct pci_bus *bus, unsigned int devfn,
				int where, int size, u32 * val)
{
	u32 data = 0;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	if (bcm1480_pci_can_access(bus, devfn))
		data = READCFG32(CFGADDR(bus, devfn, where));
	else
		data = 0xFFFFFFFF;

	if (size == 1)
		*val = (data >> ((where & 3) << 3)) & 0xff;
	else if (size == 2)
		*val = (data >> ((where & 3) << 3)) & 0xffff;
	else
		*val = data;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int bcm1480_pcibios_write(struct pci_bus *bus, unsigned int devfn,
				int where, int size, u32 val)
{
	u32 cfgaddr = CFGADDR(bus, devfn, where);
	u32 data = 0;

	if ((size == 2) && (where & 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;
	else if ((size == 4) && (where & 3))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	if (!bcm1480_pci_can_access(bus, devfn))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	data = READCFG32(cfgaddr);

	if (size == 1)
		data = (data & ~(0xff << ((where & 3) << 3))) |
		    (val << ((where & 3) << 3));
	else if (size == 2)
		data = (data & ~(0xffff << ((where & 3) << 3))) |
		    (val << ((where & 3) << 3));
	else
		data = val;

	WRITECFG32(cfgaddr, data);

	return PCIBIOS_SUCCESSFUL;
}


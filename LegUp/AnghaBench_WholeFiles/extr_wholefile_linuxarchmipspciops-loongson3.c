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
typedef  int u_int64_t ;
typedef  int u32 ;
struct pci_bus {unsigned char number; } ;

/* Variables and functions */
 int /*<<< orphan*/  HT1LO_PCICFG_BASE ; 
 int /*<<< orphan*/  HT1LO_PCICFG_BASE_TP1 ; 
 int PCIBIOS_DEVICE_NOT_FOUND ; 
 int PCIBIOS_SUCCESSFUL ; 
 unsigned char PCI_ACCESS_READ ; 
 unsigned char PCI_ACCESS_WRITE ; 
 int PCI_FUNC (unsigned int) ; 
 int PCI_SLOT (unsigned int) ; 
 int TO_UNCAC (int /*<<< orphan*/ ) ; 
 int readl (void*) ; 
 int /*<<< orphan*/  writel (int,void*) ; 

__attribute__((used)) static int loongson3_pci_config_access(unsigned char access_type,
		struct pci_bus *bus, unsigned int devfn,
		int where, u32 *data)
{
	unsigned char busnum = bus->number;
	u_int64_t addr, type;
	void *addrp;
	int device = PCI_SLOT(devfn);
	int function = PCI_FUNC(devfn);
	int reg = where & ~3;

	addr = (busnum << 16) | (device << 11) | (function << 8) | reg;
	if (busnum == 0) {
		if (device > 31)
			return PCIBIOS_DEVICE_NOT_FOUND;
		addrp = (void *)(TO_UNCAC(HT1LO_PCICFG_BASE) | (addr & 0xffff));
		type = 0;

	} else {
		addrp = (void *)(TO_UNCAC(HT1LO_PCICFG_BASE_TP1) | (addr));
		type = 0x10000;
	}

	if (access_type == PCI_ACCESS_WRITE)
		writel(*data, addrp);
	else {
		*data = readl(addrp);
		if (*data == 0xffffffff) {
			*data = -1;
			return PCIBIOS_DEVICE_NOT_FOUND;
		}
	}
	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int loongson3_pci_pcibios_read(struct pci_bus *bus, unsigned int devfn,
				 int where, int size, u32 *val)
{
	u32 data = 0;
	int ret = loongson3_pci_config_access(PCI_ACCESS_READ,
			bus, devfn, where, &data);

	if (ret != PCIBIOS_SUCCESSFUL)
		return ret;

	if (size == 1)
		*val = (data >> ((where & 3) << 3)) & 0xff;
	else if (size == 2)
		*val = (data >> ((where & 3) << 3)) & 0xffff;
	else
		*val = data;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int loongson3_pci_pcibios_write(struct pci_bus *bus, unsigned int devfn,
				  int where, int size, u32 val)
{
	u32 data = 0;
	int ret;

	if (size == 4)
		data = val;
	else {
		ret = loongson3_pci_config_access(PCI_ACCESS_READ,
				bus, devfn, where, &data);
		if (ret != PCIBIOS_SUCCESSFUL)
			return ret;

		if (size == 1)
			data = (data & ~(0xff << ((where & 3) << 3))) |
			    (val << ((where & 3) << 3));
		else if (size == 2)
			data = (data & ~(0xffff << ((where & 3) << 3))) |
			    (val << ((where & 3) << 3));
	}

	ret = loongson3_pci_config_access(PCI_ACCESS_WRITE,
			bus, devfn, where, &data);

	return ret;
}


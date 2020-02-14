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
typedef  int u32 ;
struct pci_bus {unsigned char number; } ;

/* Variables and functions */
 int GT_INTRCAUSE_MASABORT0_BIT ; 
 int /*<<< orphan*/  GT_INTRCAUSE_OFS ; 
 int GT_INTRCAUSE_TARABORT0_BIT ; 
 unsigned char GT_PCI0_CFGADDR_BUSNUM_SHF ; 
 unsigned char GT_PCI0_CFGADDR_CONFIGEN_BIT ; 
 unsigned int GT_PCI0_CFGADDR_FUNCTNUM_SHF ; 
 int /*<<< orphan*/  GT_PCI0_CFGADDR_OFS ; 
 int GT_PCI0_CFGADDR_REGNUM_SHF ; 
 int /*<<< orphan*/  GT_PCI0_CFGDATA_OFS ; 
 int GT_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GT_WRITE (int /*<<< orphan*/ ,int) ; 
 int PCIBIOS_DEVICE_NOT_FOUND ; 
 int PCIBIOS_SUCCESSFUL ; 
 unsigned char PCI_ACCESS_READ ; 
 unsigned char PCI_ACCESS_WRITE ; 
 unsigned int PCI_DEVFN (int,int /*<<< orphan*/ ) ; 
 scalar_t__ PCI_SLOT (unsigned int) ; 
 int __GT_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __GT_WRITE (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int gt64xxx_pci0_pcibios_config_access(unsigned char access_type,
		struct pci_bus *bus, unsigned int devfn, int where, u32 * data)
{
	unsigned char busnum = bus->number;
	u32 intr;

	if ((busnum == 0) && (devfn >= PCI_DEVFN(31, 0)))
		return -1;	/* Because of a bug in the galileo (for slot 31). */

	/* Clear cause register bits */
	GT_WRITE(GT_INTRCAUSE_OFS, ~(GT_INTRCAUSE_MASABORT0_BIT |
				     GT_INTRCAUSE_TARABORT0_BIT));

	/* Setup address */
	GT_WRITE(GT_PCI0_CFGADDR_OFS,
		 (busnum << GT_PCI0_CFGADDR_BUSNUM_SHF) |
		 (devfn << GT_PCI0_CFGADDR_FUNCTNUM_SHF) |
		 ((where / 4) << GT_PCI0_CFGADDR_REGNUM_SHF) |
		 GT_PCI0_CFGADDR_CONFIGEN_BIT);

	if (access_type == PCI_ACCESS_WRITE) {
		if (busnum == 0 && PCI_SLOT(devfn) == 0) {
			/*
			 * The Galileo system controller is acting
			 * differently than other devices.
			 */
			GT_WRITE(GT_PCI0_CFGDATA_OFS, *data);
		} else
			__GT_WRITE(GT_PCI0_CFGDATA_OFS, *data);
	} else {
		if (busnum == 0 && PCI_SLOT(devfn) == 0) {
			/*
			 * The Galileo system controller is acting
			 * differently than other devices.
			 */
			*data = GT_READ(GT_PCI0_CFGDATA_OFS);
		} else
			*data = __GT_READ(GT_PCI0_CFGDATA_OFS);
	}

	/* Check for master or target abort */
	intr = GT_READ(GT_INTRCAUSE_OFS);

	if (intr & (GT_INTRCAUSE_MASABORT0_BIT | GT_INTRCAUSE_TARABORT0_BIT)) {
		/* Error occurred */

		/* Clear bits */
		GT_WRITE(GT_INTRCAUSE_OFS, ~(GT_INTRCAUSE_MASABORT0_BIT |
					     GT_INTRCAUSE_TARABORT0_BIT));

		return -1;
	}

	return 0;
}

__attribute__((used)) static int gt64xxx_pci0_pcibios_read(struct pci_bus *bus, unsigned int devfn,
		int where, int size, u32 * val)
{
	u32 data = 0;

	if (gt64xxx_pci0_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
					       where, &data))
		return PCIBIOS_DEVICE_NOT_FOUND;

	if (size == 1)
		*val = (data >> ((where & 3) << 3)) & 0xff;
	else if (size == 2)
		*val = (data >> ((where & 3) << 3)) & 0xffff;
	else
		*val = data;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int gt64xxx_pci0_pcibios_write(struct pci_bus *bus, unsigned int devfn,
		int where, int size, u32 val)
{
	u32 data = 0;

	if (size == 4)
		data = val;
	else {
		if (gt64xxx_pci0_pcibios_config_access(PCI_ACCESS_READ, bus,
						       devfn, where, &data))
			return PCIBIOS_DEVICE_NOT_FOUND;

		if (size == 1)
			data = (data & ~(0xff << ((where & 3) << 3))) |
				(val << ((where & 3) << 3));
		else if (size == 2)
			data = (data & ~(0xffff << ((where & 3) << 3))) |
				(val << ((where & 3) << 3));
	}

	if (gt64xxx_pci0_pcibios_config_access(PCI_ACCESS_WRITE, bus, devfn,
					       where, &data))
		return PCIBIOS_DEVICE_NOT_FOUND;

	return PCIBIOS_SUCCESSFUL;
}


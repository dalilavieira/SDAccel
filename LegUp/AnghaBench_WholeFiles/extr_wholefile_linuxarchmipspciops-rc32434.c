#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_bus {scalar_t__ number; } ;
struct TYPE_2__ {int pcicfgd; } ;

/* Variables and functions */
 int PCIBIOS_SUCCESSFUL ; 
 unsigned char PCI_ACCESS_READ ; 
 unsigned char PCI_ACCESS_WRITE ; 
 int /*<<< orphan*/  PCI_CFG_SET (scalar_t__,unsigned int,int,unsigned char) ; 
 int PCI_FUNC (unsigned int) ; 
 int PCI_SLOT (unsigned int) ; 
 int PCI_VENDOR_ID ; 
 int /*<<< orphan*/  msleep (int) ; 
 TYPE_1__* rc32434_pci ; 
 int /*<<< orphan*/  rc32434_sync () ; 

__attribute__((used)) static inline int config_access(unsigned char access_type,
				struct pci_bus *bus, unsigned int devfn,
				unsigned char where, u32 *data)
{
	unsigned int slot = PCI_SLOT(devfn);
	u8 func = PCI_FUNC(devfn);

	/* Setup address */
	PCI_CFG_SET(bus->number, slot, func, where);
	rc32434_sync();

	if (access_type == PCI_ACCESS_WRITE)
		rc32434_pci->pcicfgd = *data;
	else
		*data = rc32434_pci->pcicfgd;

	rc32434_sync();

	return 0;
}

__attribute__((used)) static int read_config_byte(struct pci_bus *bus, unsigned int devfn,
			    int where, u8 *val)
{
	u32 data;
	int ret;

	ret = config_access(PCI_ACCESS_READ, bus, devfn, where, &data);
	*val = (data >> ((where & 3) << 3)) & 0xff;
	return ret;
}

__attribute__((used)) static int read_config_word(struct pci_bus *bus, unsigned int devfn,
			    int where, u16 *val)
{
	u32 data;
	int ret;

	ret = config_access(PCI_ACCESS_READ, bus, devfn, where, &data);
	*val = (data >> ((where & 3) << 3)) & 0xffff;
	return ret;
}

__attribute__((used)) static int read_config_dword(struct pci_bus *bus, unsigned int devfn,
			     int where, u32 *val)
{
	int ret;
	int delay = 1;

	/*
	 * Don't scan too far, else there will be errors with plugged in
	 * daughterboard (rb564).
	 */
	if (bus->number == 0 && PCI_SLOT(devfn) > 21)
		return 0;

retry:
	ret = config_access(PCI_ACCESS_READ, bus, devfn, where, val);

	/*
	 * Certain devices react delayed at device scan time, this
	 * gives them time to settle
	 */
	if (where == PCI_VENDOR_ID) {
		if (ret == 0xffffffff || ret == 0x00000000 ||
		    ret == 0x0000ffff || ret == 0xffff0000) {
			if (delay > 4)
				return 0;
			delay *= 2;
			msleep(delay);
			goto retry;
		}
	}

	return ret;
}

__attribute__((used)) static int
write_config_byte(struct pci_bus *bus, unsigned int devfn, int where,
		  u8 val)
{
	u32 data = 0;

	if (config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
		return -1;

	data = (data & ~(0xff << ((where & 3) << 3))) |
	    (val << ((where & 3) << 3));

	if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
		return -1;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int
write_config_word(struct pci_bus *bus, unsigned int devfn, int where,
		  u16 val)
{
	u32 data = 0;

	if (config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
		return -1;

	data = (data & ~(0xffff << ((where & 3) << 3))) |
	    (val << ((where & 3) << 3));

	if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
		return -1;


	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int
write_config_dword(struct pci_bus *bus, unsigned int devfn, int where,
		   u32 val)
{
	if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &val))
		return -1;

	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int pci_config_read(struct pci_bus *bus, unsigned int devfn,
			   int where, int size, u32 *val)
{
	switch (size) {
	case 1:
		return read_config_byte(bus, devfn, where, (u8 *) val);
	case 2:
		return read_config_word(bus, devfn, where, (u16 *) val);
	default:
		return read_config_dword(bus, devfn, where, val);
	}
}

__attribute__((used)) static int pci_config_write(struct pci_bus *bus, unsigned int devfn,
			    int where, int size, u32 val)
{
	switch (size) {
	case 1:
		return write_config_byte(bus, devfn, where, (u8) val);
	case 2:
		return write_config_word(bus, devfn, where, (u16) val);
	default:
		return write_config_dword(bus, devfn, where, val);
	}
}


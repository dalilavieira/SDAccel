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
typedef  int volatile u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct pci_bus {int number; int /*<<< orphan*/ * parent; } ;
struct TYPE_2__ {int ica; int pcistat; int pcistatim; int /*<<< orphan*/  icd; } ;

/* Variables and functions */
 int PCIBIOS_DEVICE_NOT_FOUND ; 
 int PCIBIOS_SUCCESSFUL ; 
 unsigned char PCI_DEVFN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int PCI_STATUS_REC_MASTER_ABORT ; 
 int /*<<< orphan*/  TX3927_PCIC_MAX_DEVNU ; 
 int /*<<< orphan*/  cpu_to_le16 (int volatile) ; 
 int /*<<< orphan*/  cpu_to_le32 (int volatile) ; 
 int /*<<< orphan*/  iob () ; 
 int le16_to_cpu (int /*<<< orphan*/  volatile) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 TYPE_1__* tx3927_pcicptr ; 

__attribute__((used)) static int mkaddr(struct pci_bus *bus, unsigned char devfn, unsigned char where)
{
	if (bus->parent == NULL &&
	    devfn >= PCI_DEVFN(TX3927_PCIC_MAX_DEVNU, 0))
		return -1;
	tx3927_pcicptr->ica =
		((bus->number & 0xff) << 0x10) |
		((devfn & 0xff) << 0x08) |
		(where & 0xfc) | (bus->parent ? 1 : 0);

	/* clear M_ABORT and Disable M_ABORT Int. */
	tx3927_pcicptr->pcistat |= PCI_STATUS_REC_MASTER_ABORT;
	tx3927_pcicptr->pcistatim &= ~PCI_STATUS_REC_MASTER_ABORT;
	return 0;
}

__attribute__((used)) static inline int check_abort(void)
{
	if (tx3927_pcicptr->pcistat & PCI_STATUS_REC_MASTER_ABORT) {
		tx3927_pcicptr->pcistat |= PCI_STATUS_REC_MASTER_ABORT;
		tx3927_pcicptr->pcistatim |= PCI_STATUS_REC_MASTER_ABORT;
		/* flush write buffer */
		iob();
		return PCIBIOS_DEVICE_NOT_FOUND;
	}
	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int tx3927_pci_read_config(struct pci_bus *bus, unsigned int devfn,
	int where, int size, u32 * val)
{
	if (mkaddr(bus, devfn, where)) {
		*val = 0xffffffff;
		return PCIBIOS_DEVICE_NOT_FOUND;
	}

	switch (size) {
	case 1:
		*val = *(volatile u8 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 3));
		break;

	case 2:
		*val = le16_to_cpu(*(volatile u16 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 3)));
		break;

	case 4:
		*val = le32_to_cpu(tx3927_pcicptr->icd);
		break;
	}

	return check_abort();
}

__attribute__((used)) static int tx3927_pci_write_config(struct pci_bus *bus, unsigned int devfn,
	int where, int size, u32 val)
{
	if (mkaddr(bus, devfn, where))
		return PCIBIOS_DEVICE_NOT_FOUND;

	switch (size) {
	case 1:
		*(volatile u8 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 3)) = val;
		break;

	case 2:
		*(volatile u16 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 2)) =
	    cpu_to_le16(val);
		break;

	case 4:
		tx3927_pcicptr->icd = cpu_to_le32(val);
	}

	return check_abort();
}


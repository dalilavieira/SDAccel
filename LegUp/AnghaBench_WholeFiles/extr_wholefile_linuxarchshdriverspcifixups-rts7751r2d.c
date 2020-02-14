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
typedef  size_t u8 ;
struct pci_dev {int dummy; } ;
struct pci_channel {scalar_t__ reg_base; } ;

/* Variables and functions */
 unsigned long PCIMCR_MRSET_OFF ; 
 unsigned long PCIMCR_RFSH_OFF ; 
 unsigned long SH4_PCIAINTM ; 
 unsigned long SH4_PCIBCR1 ; 
 unsigned long SH4_PCIINTM ; 
 unsigned long SH4_PCILAR0 ; 
 unsigned long SH4_PCILAR1 ; 
 unsigned long SH4_PCIMCR ; 
 scalar_t__ SH7751_BCR1 ; 
 scalar_t__ SH7751_MCR ; 
 unsigned long SH7751_PCICONF1 ; 
 unsigned long SH7751_PCICONF4 ; 
 unsigned long SH7751_PCICONF5 ; 
 unsigned long SH7751_PCICONF6 ; 
 unsigned long __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 int* lboxre2_irq_tab ; 
 scalar_t__ mach_is_lboxre2 () ; 
 int* rts7751r2d_irq_tab ; 

__attribute__((used)) static inline void pci_write_reg(struct pci_channel *chan,
				 unsigned long val, unsigned long reg)
{
	__raw_writel(val, chan->reg_base + reg);
}

__attribute__((used)) static inline unsigned long pci_read_reg(struct pci_channel *chan,
					 unsigned long reg)
{
	return __raw_readl(chan->reg_base + reg);
}

int pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
	if (mach_is_lboxre2())
		return lboxre2_irq_tab[slot];
	else
		return rts7751r2d_irq_tab[slot];
}

int pci_fixup_pcic(struct pci_channel *chan)
{
	unsigned long bcr1, mcr;

	bcr1 = __raw_readl(SH7751_BCR1);
	bcr1 |= 0x40080000;	/* Enable Bit 19 BREQEN, set PCIC to slave */
	pci_write_reg(chan, bcr1, SH4_PCIBCR1);

	/* Enable all interrupts, so we known what to fix */
	pci_write_reg(chan, 0x0000c3ff, SH4_PCIINTM);
	pci_write_reg(chan, 0x0000380f, SH4_PCIAINTM);

	pci_write_reg(chan, 0xfb900047, SH7751_PCICONF1);
	pci_write_reg(chan, 0xab000001, SH7751_PCICONF4);

	mcr = __raw_readl(SH7751_MCR);
	mcr = (mcr & PCIMCR_MRSET_OFF) & PCIMCR_RFSH_OFF;
	pci_write_reg(chan, mcr, SH4_PCIMCR);

	pci_write_reg(chan, 0x0c000000, SH7751_PCICONF5);
	pci_write_reg(chan, 0xd0000000, SH7751_PCICONF6);
	pci_write_reg(chan, 0x0c000000, SH4_PCILAR0);
	pci_write_reg(chan, 0x00000000, SH4_PCILAR1);

	return 0;
}


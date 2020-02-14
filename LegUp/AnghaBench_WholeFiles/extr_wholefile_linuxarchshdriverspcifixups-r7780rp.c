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
typedef  int u8 ;
struct pci_dev {int dummy; } ;
struct pci_channel {scalar_t__ reg_base; } ;

/* Variables and functions */
 unsigned long __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,scalar_t__) ; 
 int evt2irq (int) ; 

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
	return evt2irq(0xa20) + slot;
}


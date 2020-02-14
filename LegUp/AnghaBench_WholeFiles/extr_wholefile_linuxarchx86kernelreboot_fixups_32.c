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
struct pci_dev {int dummy; } ;
struct device_fixup {int /*<<< orphan*/  (* reboot_fixup ) (struct pci_dev*) ;int /*<<< orphan*/  device; int /*<<< orphan*/  vendor; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct device_fixup*) ; 
 int /*<<< orphan*/  MSR_DIVIL_SOFT_RESET ; 
 struct device_fixup* fixups_table ; 
 scalar_t__ in_interrupt () ; 
 unsigned int inl (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  outl (unsigned int,int) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_device (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  stub1 (struct pci_dev*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wrmsrl (int /*<<< orphan*/ ,unsigned long long) ; 

__attribute__((used)) static void cs5530a_warm_reset(struct pci_dev *dev)
{
	/* writing 1 to the reset control register, 0x44 causes the
	cs5530a to perform a system warm reset */
	pci_write_config_byte(dev, 0x44, 0x1);
	udelay(50); /* shouldn't get here but be safe and spin-a-while */
	return;
}

__attribute__((used)) static void cs5536_warm_reset(struct pci_dev *dev)
{
	/* writing 1 to the LSB of this MSR causes a hard reset */
	wrmsrl(MSR_DIVIL_SOFT_RESET, 1ULL);
	udelay(50); /* shouldn't get here but be safe and spin a while */
}

__attribute__((used)) static void rdc321x_reset(struct pci_dev *dev)
{
	unsigned i;
	/* Voluntary reset the watchdog timer */
	outl(0x80003840, 0xCF8);
	/* Generate a CPU reset on next tick */
	i = inl(0xCFC);
	/* Use the minimum timer resolution */
	i |= 0x1600;
	outl(i, 0xCFC);
	outb(1, 0x92);
}

__attribute__((used)) static void ce4100_reset(struct pci_dev *dev)
{
	int i;

	for (i = 0; i < 10; i++) {
		outb(0x2, 0xcf9);
		udelay(50);
	}
}

void mach_reboot_fixups(void)
{
	const struct device_fixup *cur;
	struct pci_dev *dev;
	int i;

	/* we can be called from sysrq-B code. In such a case it is
	 * prohibited to dig PCI */
	if (in_interrupt())
		return;

	for (i=0; i < ARRAY_SIZE(fixups_table); i++) {
		cur = &(fixups_table[i]);
		dev = pci_get_device(cur->vendor, cur->device, NULL);
		if (!dev)
			continue;

		cur->reboot_fixup(dev);
		pci_dev_put(dev);
	}
}


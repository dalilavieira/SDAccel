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
struct platform_device {int dummy; } ;
struct pci_bus {scalar_t__ number; } ;
struct linux_pcic {scalar_t__ pcic_regs; scalar_t__ pcic_config_space_data; scalar_t__ pcic_config_space_addr; } ;

/* Variables and functions */
 int CONFIG_CMD (unsigned int,unsigned int,int) ; 
 int EINVAL ; 
 int HZ ; 
 scalar_t__ PCI_SYS_COUNTER ; 
 int PCI_SYS_COUNTER_OVERFLOW ; 
 scalar_t__ PCI_SYS_LIMIT ; 
 int TICK_TIMER_LIMIT ; 
 int USECS_PER_JIFFY ; 
 unsigned long get_irqmask (unsigned int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 unsigned int irq_alloc (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler_name (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,void*) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  nop () ; 
 struct linux_pcic pcic0 ; 
 int /*<<< orphan*/  pcic_irq ; 
 int pcic_speculative ; 
 void* pcic_timer_dummy ; 
 scalar_t__ pcic_trapped ; 
 int /*<<< orphan*/  printk (char*,char*,int) ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int pcic_read_config_dword(unsigned int busno, unsigned int devfn,
    int where, u32 *value)
{
	struct linux_pcic *pcic;
	unsigned long flags;

	pcic = &pcic0;

	local_irq_save(flags);
#if 0 /* does not fail here */
	pcic_speculative = 1;
	pcic_trapped = 0;
#endif
	writel(CONFIG_CMD(busno, devfn, where), pcic->pcic_config_space_addr);
#if 0 /* does not fail here */
	nop();
	if (pcic_trapped) {
		local_irq_restore(flags);
		*value = ~0;
		return 0;
	}
#endif
	pcic_speculative = 2;
	pcic_trapped = 0;
	*value = readl(pcic->pcic_config_space_data + (where&4));
	nop();
	if (pcic_trapped) {
		pcic_speculative = 0;
		local_irq_restore(flags);
		*value = ~0;
		return 0;
	}
	pcic_speculative = 0;
	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int pcic_read_config(struct pci_bus *bus, unsigned int devfn,
   int where, int size, u32 *val)
{
	unsigned int v;

	if (bus->number != 0) return -EINVAL;
	switch (size) {
	case 1:
		pcic_read_config_dword(bus->number, devfn, where&~3, &v);
		*val = 0xff & (v >> (8*(where & 3)));
		return 0;
	case 2:
		if (where&1) return -EINVAL;
		pcic_read_config_dword(bus->number, devfn, where&~3, &v);
		*val = 0xffff & (v >> (8*(where & 3)));
		return 0;
	case 4:
		if (where&3) return -EINVAL;
		pcic_read_config_dword(bus->number, devfn, where&~3, val);
		return 0;
	}
	return -EINVAL;
}

__attribute__((used)) static int pcic_write_config_dword(unsigned int busno, unsigned int devfn,
    int where, u32 value)
{
	struct linux_pcic *pcic;
	unsigned long flags;

	pcic = &pcic0;

	local_irq_save(flags);
	writel(CONFIG_CMD(busno, devfn, where), pcic->pcic_config_space_addr);
	writel(value, pcic->pcic_config_space_data + (where&4));
	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int pcic_write_config(struct pci_bus *bus, unsigned int devfn,
   int where, int size, u32 val)
{
	unsigned int v;

	if (bus->number != 0) return -EINVAL;
	switch (size) {
	case 1:
		pcic_read_config_dword(bus->number, devfn, where&~3, &v);
		v = (v & ~(0xff << (8*(where&3)))) |
		    ((0xff&val) << (8*(where&3)));
		return pcic_write_config_dword(bus->number, devfn, where&~3, v);
	case 2:
		if (where&1) return -EINVAL;
		pcic_read_config_dword(bus->number, devfn, where&~3, &v);
		v = (v & ~(0xffff << (8*(where&3)))) |
		    ((0xffff&val) << (8*(where&3)));
		return pcic_write_config_dword(bus->number, devfn, where&~3, v);
	case 4:
		if (where&3) return -EINVAL;
		return pcic_write_config_dword(bus->number, devfn, where, val);
	}
	return -EINVAL;
}

__attribute__((used)) static void pcic_clear_clock_irq(void)
{
	pcic_timer_dummy = readl(pcic0.pcic_regs+PCI_SYS_LIMIT);
}

__attribute__((used)) static unsigned int pcic_cycles_offset(void)
{
	u32 value, count;

	value = readl(pcic0.pcic_regs + PCI_SYS_COUNTER);
	count = value & ~PCI_SYS_COUNTER_OVERFLOW;

	if (value & PCI_SYS_COUNTER_OVERFLOW)
		count += TICK_TIMER_LIMIT;
	/*
	 * We divide all by HZ
	 * to have microsecond resolution and to avoid overflow
	 */
	count = ((count / HZ) * USECS_PER_JIFFY) / (TICK_TIMER_LIMIT / HZ);

	/* Coordinate with the sparc_config.clock_rate setting */
	return count * 2;
}

unsigned int pcic_build_device_irq(struct platform_device *op,
                                   unsigned int real_irq)
{
	unsigned int irq;
	unsigned long mask;

	irq = 0;
	mask = get_irqmask(real_irq);
	if (mask == 0)
		goto out;

	irq = irq_alloc(real_irq, real_irq);
	if (irq == 0)
		goto out;

	irq_set_chip_and_handler_name(irq, &pcic_irq,
	                              handle_level_irq, "PCIC");
	irq_set_chip_data(irq, (void *)mask);

out:
	return irq;
}

__attribute__((used)) static void pcic_load_profile_irq(int cpu, unsigned int limit)
{
	printk("PCIC: unimplemented code: FILE=%s LINE=%d", __FILE__, __LINE__);
}


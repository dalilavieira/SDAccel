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
typedef  int u64 ;
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 unsigned long A_BCM1480_IMR_MAPPER (unsigned int) ; 
 unsigned long A_BCM1480_IMR_REGISTER (int,scalar_t__) ; 
 int BCM1480_IMR_HL_SPACING ; 
 int BCM1480_NR_IRQS ; 
 int BCM1480_NR_IRQS_HALF ; 
 int /*<<< orphan*/  IOADDR (unsigned long) ; 
 unsigned long R_BCM1480_IMR_INTERRUPT_MASK_H ; 
 unsigned long R_BCM1480_IMR_INTERRUPT_STATUS_BASE_H ; 
 unsigned long R_BCM1480_IMR_INTERRUPT_STATUS_BASE_L ; 
 scalar_t__ R_BCM1480_IMR_LDT_INTERRUPT_CLR_H ; 
 scalar_t__ R_BCM1480_IMR_LDT_INTERRUPT_H ; 
 int ____raw_readq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ____raw_writeq (int,int /*<<< orphan*/ ) ; 
 void* __raw_readq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeq (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm1480_imr_lock ; 
 int* bcm1480_irq_owner ; 
 int /*<<< orphan*/  do_IRQ (scalar_t__) ; 
 scalar_t__ fls64 (unsigned long long) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int smp_processor_id () ; 

void bcm1480_mask_irq(int cpu, int irq)
{
	unsigned long flags, hl_spacing;
	u64 cur_ints;

	raw_spin_lock_irqsave(&bcm1480_imr_lock, flags);
	hl_spacing = 0;
	if ((irq >= BCM1480_NR_IRQS_HALF) && (irq <= BCM1480_NR_IRQS)) {
		hl_spacing = BCM1480_IMR_HL_SPACING;
		irq -= BCM1480_NR_IRQS_HALF;
	}
	cur_ints = ____raw_readq(IOADDR(A_BCM1480_IMR_MAPPER(cpu) + R_BCM1480_IMR_INTERRUPT_MASK_H + hl_spacing));
	cur_ints |= (((u64) 1) << irq);
	____raw_writeq(cur_ints, IOADDR(A_BCM1480_IMR_MAPPER(cpu) + R_BCM1480_IMR_INTERRUPT_MASK_H + hl_spacing));
	raw_spin_unlock_irqrestore(&bcm1480_imr_lock, flags);
}

void bcm1480_unmask_irq(int cpu, int irq)
{
	unsigned long flags, hl_spacing;
	u64 cur_ints;

	raw_spin_lock_irqsave(&bcm1480_imr_lock, flags);
	hl_spacing = 0;
	if ((irq >= BCM1480_NR_IRQS_HALF) && (irq <= BCM1480_NR_IRQS)) {
		hl_spacing = BCM1480_IMR_HL_SPACING;
		irq -= BCM1480_NR_IRQS_HALF;
	}
	cur_ints = ____raw_readq(IOADDR(A_BCM1480_IMR_MAPPER(cpu) + R_BCM1480_IMR_INTERRUPT_MASK_H + hl_spacing));
	cur_ints &= ~(((u64) 1) << irq);
	____raw_writeq(cur_ints, IOADDR(A_BCM1480_IMR_MAPPER(cpu) + R_BCM1480_IMR_INTERRUPT_MASK_H + hl_spacing));
	raw_spin_unlock_irqrestore(&bcm1480_imr_lock, flags);
}

__attribute__((used)) static void disable_bcm1480_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	bcm1480_mask_irq(bcm1480_irq_owner[irq], irq);
}

__attribute__((used)) static void enable_bcm1480_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	bcm1480_unmask_irq(bcm1480_irq_owner[irq], irq);
}

__attribute__((used)) static void ack_bcm1480_irq(struct irq_data *d)
{
	unsigned int irq_dirty, irq = d->irq;
	u64 pending;
	int k;

	/*
	 * If the interrupt was an HT interrupt, now is the time to
	 * clear it.  NOTE: we assume the HT bridge was set up to
	 * deliver the interrupts to all CPUs (which makes affinity
	 * changing easier for us)
	 */
	irq_dirty = irq;
	if ((irq_dirty >= BCM1480_NR_IRQS_HALF) && (irq_dirty <= BCM1480_NR_IRQS)) {
		irq_dirty -= BCM1480_NR_IRQS_HALF;
	}
	for (k=0; k<2; k++) { /* Loop through high and low LDT interrupts */
		pending = __raw_readq(IOADDR(A_BCM1480_IMR_REGISTER(bcm1480_irq_owner[irq],
						R_BCM1480_IMR_LDT_INTERRUPT_H + (k*BCM1480_IMR_HL_SPACING))));
		pending &= ((u64)1 << (irq_dirty));
		if (pending) {
#ifdef CONFIG_SMP
			int i;
			for (i=0; i<NR_CPUS; i++) {
				/*
				 * Clear for all CPUs so an affinity switch
				 * doesn't find an old status
				 */
				__raw_writeq(pending, IOADDR(A_BCM1480_IMR_REGISTER(cpu_logical_map(i),
								R_BCM1480_IMR_LDT_INTERRUPT_CLR_H + (k*BCM1480_IMR_HL_SPACING))));
			}
#else
			__raw_writeq(pending, IOADDR(A_BCM1480_IMR_REGISTER(0, R_BCM1480_IMR_LDT_INTERRUPT_CLR_H + (k*BCM1480_IMR_HL_SPACING))));
#endif

			/*
			 * Generate EOI.  For Pass 1 parts, EOI is a nop.  For
			 * Pass 2, the LDT world may be edge-triggered, but
			 * this EOI shouldn't hurt.  If they are
			 * level-sensitive, the EOI is required.
			 */
#ifdef CONFIG_PCI
			if (ht_eoi_space)
				*(uint32_t *)(ht_eoi_space+(irq<<16)+(7<<2)) = 0;
#endif
		}
	}
	bcm1480_mask_irq(bcm1480_irq_owner[irq], irq);
}

__attribute__((used)) static inline void dispatch_ip2(void)
{
	unsigned long long mask_h, mask_l;
	unsigned int cpu = smp_processor_id();
	unsigned long base;

	/*
	 * Default...we've hit an IP[2] interrupt, which means we've got to
	 * check the 1480 interrupt registers to figure out what to do.	 Need
	 * to detect which CPU we're on, now that smp_affinity is supported.
	 */
	base = A_BCM1480_IMR_MAPPER(cpu);
	mask_h = __raw_readq(
		IOADDR(base + R_BCM1480_IMR_INTERRUPT_STATUS_BASE_H));
	mask_l = __raw_readq(
		IOADDR(base + R_BCM1480_IMR_INTERRUPT_STATUS_BASE_L));

	if (mask_h) {
		if (mask_h ^ 1)
			do_IRQ(fls64(mask_h) - 1);
		else if (mask_l)
			do_IRQ(63 + fls64(mask_l));
	}
}


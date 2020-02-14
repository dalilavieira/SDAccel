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
 scalar_t__ A_IMR_MAPPER (int) ; 
 scalar_t__ A_IMR_REGISTER (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IOADDR (scalar_t__) ; 
 scalar_t__ R_IMR_INTERRUPT_MASK ; 
 int /*<<< orphan*/  R_IMR_INTERRUPT_STATUS_BASE ; 
 int ____raw_readq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ____raw_writeq (int,int /*<<< orphan*/ ) ; 
 unsigned long long __raw_readq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_IRQ (scalar_t__) ; 
 scalar_t__ fls64 (unsigned long long) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  sb1250_imr_lock ; 
 int* sb1250_irq_owner ; 
 unsigned int smp_processor_id () ; 

void sb1250_mask_irq(int cpu, int irq)
{
	unsigned long flags;
	u64 cur_ints;

	raw_spin_lock_irqsave(&sb1250_imr_lock, flags);
	cur_ints = ____raw_readq(IOADDR(A_IMR_MAPPER(cpu) +
					R_IMR_INTERRUPT_MASK));
	cur_ints |= (((u64) 1) << irq);
	____raw_writeq(cur_ints, IOADDR(A_IMR_MAPPER(cpu) +
					R_IMR_INTERRUPT_MASK));
	raw_spin_unlock_irqrestore(&sb1250_imr_lock, flags);
}

void sb1250_unmask_irq(int cpu, int irq)
{
	unsigned long flags;
	u64 cur_ints;

	raw_spin_lock_irqsave(&sb1250_imr_lock, flags);
	cur_ints = ____raw_readq(IOADDR(A_IMR_MAPPER(cpu) +
					R_IMR_INTERRUPT_MASK));
	cur_ints &= ~(((u64) 1) << irq);
	____raw_writeq(cur_ints, IOADDR(A_IMR_MAPPER(cpu) +
					R_IMR_INTERRUPT_MASK));
	raw_spin_unlock_irqrestore(&sb1250_imr_lock, flags);
}

__attribute__((used)) static void disable_sb1250_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	sb1250_mask_irq(sb1250_irq_owner[irq], irq);
}

__attribute__((used)) static void enable_sb1250_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	sb1250_unmask_irq(sb1250_irq_owner[irq], irq);
}

__attribute__((used)) static void ack_sb1250_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;
#ifdef CONFIG_SIBYTE_HAS_LDT
	u64 pending;

	/*
	 * If the interrupt was an HT interrupt, now is the time to
	 * clear it.  NOTE: we assume the HT bridge was set up to
	 * deliver the interrupts to all CPUs (which makes affinity
	 * changing easier for us)
	 */
	pending = __raw_readq(IOADDR(A_IMR_REGISTER(sb1250_irq_owner[irq],
						    R_IMR_LDT_INTERRUPT)));
	pending &= ((u64)1 << (irq));
	if (pending) {
		int i;
		for (i=0; i<NR_CPUS; i++) {
			int cpu;
#ifdef CONFIG_SMP
			cpu = cpu_logical_map(i);
#else
			cpu = i;
#endif
			/*
			 * Clear for all CPUs so an affinity switch
			 * doesn't find an old status
			 */
			__raw_writeq(pending,
				     IOADDR(A_IMR_REGISTER(cpu,
						R_IMR_LDT_INTERRUPT_CLR)));
		}

		/*
		 * Generate EOI.  For Pass 1 parts, EOI is a nop.  For
		 * Pass 2, the LDT world may be edge-triggered, but
		 * this EOI shouldn't hurt.  If they are
		 * level-sensitive, the EOI is required.
		 */
		*(uint32_t *)(ldt_eoi_space+(irq<<16)+(7<<2)) = 0;
	}
#endif
	sb1250_mask_irq(sb1250_irq_owner[irq], irq);
}

__attribute__((used)) static inline void dispatch_ip2(void)
{
	unsigned int cpu = smp_processor_id();
	unsigned long long mask;

	/*
	 * Default...we've hit an IP[2] interrupt, which means we've got to
	 * check the 1250 interrupt registers to figure out what to do.	 Need
	 * to detect which CPU we're on, now that smp_affinity is supported.
	 */
	mask = __raw_readq(IOADDR(A_IMR_REGISTER(cpu,
				  R_IMR_INTERRUPT_STATUS_BASE)));
	if (mask)
		do_IRQ(fls64(mask) - 1);
}


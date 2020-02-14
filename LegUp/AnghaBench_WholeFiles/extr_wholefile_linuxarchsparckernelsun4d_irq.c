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
struct sun4d_handler_data {unsigned int real_irq; } ;
struct pt_regs {int dummy; } ;
struct irq_data {int /*<<< orphan*/  irq; } ;
struct irq_bucket {int /*<<< orphan*/  irq; struct irq_bucket* next; } ;
struct TYPE_2__ {int /*<<< orphan*/  l10_timer_limit; } ;

/* Variables and functions */
 int /*<<< orphan*/  SBI2DEVID (unsigned int) ; 
 unsigned int acquire_sbi (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bw_clear_intr_mask (int,unsigned int) ; 
 int bw_get_intr_mask (int) ; 
 int /*<<< orphan*/  bw_set_prof_limit (int,unsigned int) ; 
 int cc_get_imsk () ; 
 int /*<<< orphan*/  cc_get_ipen () ; 
 int /*<<< orphan*/  cc_set_iclr (int) ; 
 int /*<<< orphan*/  cc_set_imsk (int) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 struct sun4d_handler_data* irq_data_get_irq_handler_data (struct irq_data*) ; 
 int /*<<< orphan*/  irq_enter () ; 
 int /*<<< orphan*/  irq_exit () ; 
 int /*<<< orphan*/  irq_link (int /*<<< orphan*/ ) ; 
 struct irq_bucket** irq_map ; 
 int /*<<< orphan*/  irq_unlink (int /*<<< orphan*/ ) ; 
 int* pil_to_sbus ; 
 int /*<<< orphan*/  release_sbi (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  sbus_readl (int /*<<< orphan*/ *) ; 
 struct pt_regs* set_irq_regs (struct pt_regs*) ; 
 TYPE_1__* sun4d_timers ; 
 unsigned int timer_value (unsigned int) ; 

__attribute__((used)) static unsigned int sun4d_encode_irq(int board, int lvl, int slot)
{
	return (board + 1) << 5 | (lvl << 2) | slot;
}

__attribute__((used)) static void sun4d_sbus_handler_irq(int sbusl)
{
	unsigned int bus_mask;
	unsigned int sbino, slot;
	unsigned int sbil;

	bus_mask = bw_get_intr_mask(sbusl) & 0x3ffff;
	bw_clear_intr_mask(sbusl, bus_mask);

	sbil = (sbusl << 2);
	/* Loop for each pending SBI */
	for (sbino = 0; bus_mask; sbino++, bus_mask >>= 1) {
		unsigned int idx, mask;

		if (!(bus_mask & 1))
			continue;
		/* XXX This seems to ACK the irq twice.  acquire_sbi()
		 * XXX uses swap, therefore this writes 0xf << sbil,
		 * XXX then later release_sbi() will write the individual
		 * XXX bits which were set again.
		 */
		mask = acquire_sbi(SBI2DEVID(sbino), 0xf << sbil);
		mask &= (0xf << sbil);

		/* Loop for each pending SBI slot */
		slot = (1 << sbil);
		for (idx = 0; mask != 0; idx++, slot <<= 1) {
			unsigned int pil;
			struct irq_bucket *p;

			if (!(mask & slot))
				continue;

			mask &= ~slot;
			pil = sun4d_encode_irq(sbino, sbusl, idx);

			p = irq_map[pil];
			while (p) {
				struct irq_bucket *next;

				next = p->next;
				generic_handle_irq(p->irq);
				p = next;
			}
			release_sbi(SBI2DEVID(sbino), slot);
		}
	}
}

void sun4d_handler_irq(unsigned int pil, struct pt_regs *regs)
{
	struct pt_regs *old_regs;
	/* SBUS IRQ level (1 - 7) */
	int sbusl = pil_to_sbus[pil];

	/* FIXME: Is this necessary?? */
	cc_get_ipen();

	cc_set_iclr(1 << pil);

#ifdef CONFIG_SMP
	/*
	 * Check IPI data structures after IRQ has been cleared. Hard and Soft
	 * IRQ can happen at the same time, so both cases are always handled.
	 */
	if (pil == SUN4D_IPI_IRQ)
		sun4d_ipi_interrupt();
#endif

	old_regs = set_irq_regs(regs);
	irq_enter();
	if (sbusl == 0) {
		/* cpu interrupt */
		struct irq_bucket *p;

		p = irq_map[pil];
		while (p) {
			struct irq_bucket *next;

			next = p->next;
			generic_handle_irq(p->irq);
			p = next;
		}
	} else {
		/* SBUS interrupt */
		sun4d_sbus_handler_irq(sbusl);
	}
	irq_exit();
	set_irq_regs(old_regs);
}

__attribute__((used)) static void sun4d_mask_irq(struct irq_data *data)
{
	struct sun4d_handler_data *handler_data = irq_data_get_irq_handler_data(data);
	unsigned int real_irq;
#ifdef CONFIG_SMP
	int cpuid = handler_data->cpuid;
	unsigned long flags;
#endif
	real_irq = handler_data->real_irq;
#ifdef CONFIG_SMP
	spin_lock_irqsave(&sun4d_imsk_lock, flags);
	cc_set_imsk_other(cpuid, cc_get_imsk_other(cpuid) | (1 << real_irq));
	spin_unlock_irqrestore(&sun4d_imsk_lock, flags);
#else
	cc_set_imsk(cc_get_imsk() | (1 << real_irq));
#endif
}

__attribute__((used)) static void sun4d_unmask_irq(struct irq_data *data)
{
	struct sun4d_handler_data *handler_data = irq_data_get_irq_handler_data(data);
	unsigned int real_irq;
#ifdef CONFIG_SMP
	int cpuid = handler_data->cpuid;
	unsigned long flags;
#endif
	real_irq = handler_data->real_irq;

#ifdef CONFIG_SMP
	spin_lock_irqsave(&sun4d_imsk_lock, flags);
	cc_set_imsk_other(cpuid, cc_get_imsk_other(cpuid) & ~(1 << real_irq));
	spin_unlock_irqrestore(&sun4d_imsk_lock, flags);
#else
	cc_set_imsk(cc_get_imsk() & ~(1 << real_irq));
#endif
}

__attribute__((used)) static unsigned int sun4d_startup_irq(struct irq_data *data)
{
	irq_link(data->irq);
	sun4d_unmask_irq(data);
	return 0;
}

__attribute__((used)) static void sun4d_shutdown_irq(struct irq_data *data)
{
	sun4d_mask_irq(data);
	irq_unlink(data->irq);
}

__attribute__((used)) static void sun4d_clear_clock_irq(void)
{
	sbus_readl(&sun4d_timers->l10_timer_limit);
}

__attribute__((used)) static void sun4d_load_profile_irq(int cpu, unsigned int limit)
{
	unsigned int value = limit ? timer_value(limit) : 0;
	bw_set_prof_limit(cpu, value);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct irq_data {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/ * bytes; } ;
struct TYPE_4__ {int /*<<< orphan*/ * bytes; int /*<<< orphan*/  word; } ;
struct TYPE_6__ {TYPE_2__ qirr; TYPE_1__ xirr; } ;

/* Variables and functions */
 int XICS_IPI ; 
 unsigned int XICS_IRQ_SPURIOUS ; 
 TYPE_3__** icp_native_regs ; 
 unsigned int in_be32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iosync () ; 
 unsigned int irq_find_mapping (int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ irqd_to_hwirq (struct irq_data*) ; 
 unsigned int kvmppc_get_xics_latch () ; 
 scalar_t__ likely (unsigned int) ; 
 int /*<<< orphan*/  out_8 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  out_be32 (int /*<<< orphan*/ *,unsigned int) ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  xics_host ; 
 int /*<<< orphan*/  xics_mask_unknown_vec (unsigned int) ; 
 int xics_pop_cppr () ; 
 int /*<<< orphan*/  xics_push_cppr (unsigned int) ; 
 int /*<<< orphan*/  xics_set_base_cppr (unsigned char) ; 

__attribute__((used)) static inline unsigned int icp_native_get_xirr(void)
{
	int cpu = smp_processor_id();
	unsigned int xirr;

	/* Handled an interrupt latched by KVM */
	xirr = kvmppc_get_xics_latch();
	if (xirr)
		return xirr;

	return in_be32(&icp_native_regs[cpu]->xirr.word);
}

__attribute__((used)) static inline void icp_native_set_xirr(unsigned int value)
{
	int cpu = smp_processor_id();

	out_be32(&icp_native_regs[cpu]->xirr.word, value);
}

__attribute__((used)) static inline void icp_native_set_cppr(u8 value)
{
	int cpu = smp_processor_id();

	out_8(&icp_native_regs[cpu]->xirr.bytes[0], value);
}

__attribute__((used)) static inline void icp_native_set_qirr(int n_cpu, u8 value)
{
	out_8(&icp_native_regs[n_cpu]->qirr.bytes[0], value);
}

__attribute__((used)) static void icp_native_set_cpu_priority(unsigned char cppr)
{
	xics_set_base_cppr(cppr);
	icp_native_set_cppr(cppr);
	iosync();
}

void icp_native_eoi(struct irq_data *d)
{
	unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);

	iosync();
	icp_native_set_xirr((xics_pop_cppr() << 24) | hw_irq);
}

__attribute__((used)) static void icp_native_teardown_cpu(void)
{
	int cpu = smp_processor_id();

	/* Clear any pending IPI */
	icp_native_set_qirr(cpu, 0xff);
}

__attribute__((used)) static void icp_native_flush_ipi(void)
{
	/* We take the ipi irq but and never return so we
	 * need to EOI the IPI, but want to leave our priority 0
	 *
	 * should we check all the other interrupts too?
	 * should we be flagging idle loop instead?
	 * or creating some task to be scheduled?
	 */

	icp_native_set_xirr((0x00 << 24) | XICS_IPI);
}

__attribute__((used)) static unsigned int icp_native_get_irq(void)
{
	unsigned int xirr = icp_native_get_xirr();
	unsigned int vec = xirr & 0x00ffffff;
	unsigned int irq;

	if (vec == XICS_IRQ_SPURIOUS)
		return 0;

	irq = irq_find_mapping(xics_host, vec);
	if (likely(irq)) {
		xics_push_cppr(vec);
		return irq;
	}

	/* We don't have a linux mapping, so have rtas mask it. */
	xics_mask_unknown_vec(vec);

	/* We might learn about it later, so EOI it */
	icp_native_set_xirr(xirr);

	return 0;
}


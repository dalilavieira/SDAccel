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
struct irq_data {int dummy; } ;
struct device_node {int dummy; } ;
typedef  scalar_t__ int64_t ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 unsigned char DEFAULT_PRIORITY ; 
 int ENODEV ; 
 unsigned char LOWEST_PRIORITY ; 
 int XICS_IPI ; 
 unsigned int XICS_IRQ_SPURIOUS ; 
 unsigned int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  force_external_irq_replay () ; 
 int hard_smp_processor_id () ; 
 int /*<<< orphan*/  icp_opal_ops ; 
 int /*<<< orphan*/ * icp_ops ; 
 int /*<<< orphan*/  iosync () ; 
 unsigned int irq_find_mapping (int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ irqd_to_hwirq (struct irq_data*) ; 
 unsigned int kvmppc_get_xics_latch () ; 
 scalar_t__ likely (unsigned int) ; 
 struct device_node* of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 scalar_t__ opal_int_eoi (int) ; 
 scalar_t__ opal_int_get_xirr (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  opal_int_set_cppr (unsigned char) ; 
 int /*<<< orphan*/  opal_int_set_mfrr (int,int) ; 
 int /*<<< orphan*/  printk (char*) ; 
 int /*<<< orphan*/  xics_host ; 
 int /*<<< orphan*/  xics_mask_unknown_vec (unsigned int) ; 
 int xics_pop_cppr () ; 
 int /*<<< orphan*/  xics_push_cppr (unsigned int) ; 
 int /*<<< orphan*/  xics_set_base_cppr (unsigned char) ; 

__attribute__((used)) static void icp_opal_teardown_cpu(void)
{
	int hw_cpu = hard_smp_processor_id();

	/* Clear any pending IPI */
	opal_int_set_mfrr(hw_cpu, 0xff);
}

__attribute__((used)) static void icp_opal_flush_ipi(void)
{
	/*
	 * We take the ipi irq but and never return so we need to EOI the IPI,
	 * but want to leave our priority 0.
	 *
	 * Should we check all the other interrupts too?
	 * Should we be flagging idle loop instead?
	 * Or creating some task to be scheduled?
	 */
	if (opal_int_eoi((0x00 << 24) | XICS_IPI) > 0)
		force_external_irq_replay();
}

__attribute__((used)) static unsigned int icp_opal_get_xirr(void)
{
	unsigned int kvm_xirr;
	__be32 hw_xirr;
	int64_t rc;

	/* Handle an interrupt latched by KVM first */
	kvm_xirr = kvmppc_get_xics_latch();
	if (kvm_xirr)
		return kvm_xirr;

	/* Then ask OPAL */
	rc = opal_int_get_xirr(&hw_xirr, false);
	if (rc < 0)
		return 0;
	return be32_to_cpu(hw_xirr);
}

__attribute__((used)) static unsigned int icp_opal_get_irq(void)
{
	unsigned int xirr;
	unsigned int vec;
	unsigned int irq;

	xirr = icp_opal_get_xirr();
	vec = xirr & 0x00ffffff;
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
	if (opal_int_eoi(xirr) > 0)
		force_external_irq_replay();

	return 0;
}

__attribute__((used)) static void icp_opal_set_cpu_priority(unsigned char cppr)
{
	/*
	 * Here be dragons. The caller has asked to allow only IPI's and not
	 * external interrupts. But OPAL XIVE doesn't support that. So instead
	 * of allowing no interrupts allow all. That's still not right, but
	 * currently the only caller who does this is xics_migrate_irqs_away()
	 * and it works in that case.
	 */
	if (cppr >= DEFAULT_PRIORITY)
		cppr = LOWEST_PRIORITY;

	xics_set_base_cppr(cppr);
	opal_int_set_cppr(cppr);
	iosync();
}

__attribute__((used)) static void icp_opal_eoi(struct irq_data *d)
{
	unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
	int64_t rc;

	iosync();
	rc = opal_int_eoi((xics_pop_cppr() << 24) | hw_irq);

	/*
	 * EOI tells us whether there are more interrupts to fetch.
	 *
	 * Some HW implementations might not be able to send us another
	 * external interrupt in that case, so we force a replay.
	 */
	if (rc > 0)
		force_external_irq_replay();
}

int icp_opal_init(void)
{
	struct device_node *np;

	np = of_find_compatible_node(NULL, NULL, "ibm,opal-intc");
	if (!np)
		return -ENODEV;

	icp_ops = &icp_opal_ops;

	printk("XICS: Using OPAL ICP fallbacks\n");

	return 0;
}


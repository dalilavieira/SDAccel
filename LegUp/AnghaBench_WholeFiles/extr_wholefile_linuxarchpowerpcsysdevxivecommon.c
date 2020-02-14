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
typedef  size_t u8 ;
typedef  scalar_t__ u32 ;
struct xive_q {int idx; scalar_t__ toggle; int msk; int /*<<< orphan*/  count; int /*<<< orphan*/  pending_count; scalar_t__ qpage; } ;
struct xive_irq_data {int /*<<< orphan*/  target; int /*<<< orphan*/ * trig_mmio; int /*<<< orphan*/ * eoi_mmio; } ;
struct xive_cpu {int pending_prio; size_t cppr; struct xive_q* queue; } ;
struct irq_domain {int dummy; } ;
struct irq_data {int dummy; } ;
struct irq_chip {int dummy; } ;
struct device_node {int dummy; } ;
typedef  scalar_t__ irq_hw_number_t ;
typedef  enum irq_domain_bus_token { ____Placeholder_irq_domain_bus_token } irq_domain_bus_token ;
struct TYPE_2__ {int (* populate_irq_data ) (scalar_t__,struct xive_irq_data*) ;int (* match ) (struct device_node*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_VERBOSE (char*,size_t) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_LEVEL ; 
 unsigned int IRQ_TYPE_EDGE_RISING ; 
 unsigned int IRQ_TYPE_LEVEL_LOW ; 
 scalar_t__ PAGE_SHIFT ; 
 scalar_t__ TM_CPPR ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  XIVE_INVALID_TARGET ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_sub (int,int /*<<< orphan*/ *) ; 
 int atomic_xchg (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ be32_to_cpup (scalar_t__) ; 
 size_t ffs (int) ; 
 int /*<<< orphan*/  handle_fasteoi_irq ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_clear_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 struct xive_irq_data* irq_get_handler_data (unsigned int) ; 
 struct irq_data* irq_get_irq_data (unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,struct irq_chip*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_handler_data (unsigned int,struct xive_irq_data*) ; 
 scalar_t__ irqd_to_hwirq (struct irq_data*) ; 
 int /*<<< orphan*/  kfree (struct xive_irq_data*) ; 
 struct xive_irq_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_8 (scalar_t__,size_t) ; 
 int stub1 (scalar_t__,struct xive_irq_data*) ; 
 int stub2 (struct device_node*) ; 
 struct irq_chip xive_irq_chip ; 
 TYPE_1__* xive_ops ; 
 scalar_t__ xive_tima ; 
 scalar_t__ xive_tima_offset ; 

__attribute__((used)) static inline u32 xive_alloc_order(u32 queue_shift)
{
	return (queue_shift > PAGE_SHIFT) ? (queue_shift - PAGE_SHIFT) : 0;
}

__attribute__((used)) static u32 xive_read_eq(struct xive_q *q, bool just_peek)
{
	u32 cur;

	if (!q->qpage)
		return 0;
	cur = be32_to_cpup(q->qpage + q->idx);

	/* Check valid bit (31) vs current toggle polarity */
	if ((cur >> 31) == q->toggle)
		return 0;

	/* If consuming from the queue ... */
	if (!just_peek) {
		/* Next entry */
		q->idx = (q->idx + 1) & q->msk;

		/* Wrap around: flip valid toggle */
		if (q->idx == 0)
			q->toggle ^= 1;
	}
	/* Mask out the valid bit (31) */
	return cur & 0x7fffffff;
}

__attribute__((used)) static u32 xive_scan_interrupts(struct xive_cpu *xc, bool just_peek)
{
	u32 irq = 0;
	u8 prio;

	/* Find highest pending priority */
	while (xc->pending_prio != 0) {
		struct xive_q *q;

		prio = ffs(xc->pending_prio) - 1;
		DBG_VERBOSE("scan_irq: trying prio %d\n", prio);

		/* Try to fetch */
		irq = xive_read_eq(&xc->queue[prio], just_peek);

		/* Found something ? That's it */
		if (irq)
			break;

		/* Clear pending bits */
		xc->pending_prio &= ~(1 << prio);

		/*
		 * Check if the queue count needs adjusting due to
		 * interrupts being moved away. See description of
		 * xive_dec_target_count()
		 */
		q = &xc->queue[prio];
		if (atomic_read(&q->pending_count)) {
			int p = atomic_xchg(&q->pending_count, 0);
			if (p) {
				WARN_ON(p > atomic_read(&q->count));
				atomic_sub(p, &q->count);
			}
		}
	}

	/* If nothing was found, set CPPR to 0xff */
	if (irq == 0)
		prio = 0xff;

	/* Update HW CPPR to match if necessary */
	if (prio != xc->cppr) {
		DBG_VERBOSE("scan_irq: adjusting CPPR to %d\n", prio);
		xc->cppr = prio;
		out_8(xive_tima + xive_tima_offset + TM_CPPR, prio);
	}

	return irq;
}

bool is_xive_irq(struct irq_chip *chip)
{
	return chip == &xive_irq_chip;
}

void xive_cleanup_irq_data(struct xive_irq_data *xd)
{
	if (xd->eoi_mmio) {
		iounmap(xd->eoi_mmio);
		if (xd->eoi_mmio == xd->trig_mmio)
			xd->trig_mmio = NULL;
		xd->eoi_mmio = NULL;
	}
	if (xd->trig_mmio) {
		iounmap(xd->trig_mmio);
		xd->trig_mmio = NULL;
	}
}

__attribute__((used)) static int xive_irq_alloc_data(unsigned int virq, irq_hw_number_t hw)
{
	struct xive_irq_data *xd;
	int rc;

	xd = kzalloc(sizeof(struct xive_irq_data), GFP_KERNEL);
	if (!xd)
		return -ENOMEM;
	rc = xive_ops->populate_irq_data(hw, xd);
	if (rc) {
		kfree(xd);
		return rc;
	}
	xd->target = XIVE_INVALID_TARGET;
	irq_set_handler_data(virq, xd);

	return 0;
}

__attribute__((used)) static void xive_irq_free_data(unsigned int virq)
{
	struct xive_irq_data *xd = irq_get_handler_data(virq);

	if (!xd)
		return;
	irq_set_handler_data(virq, NULL);
	xive_cleanup_irq_data(xd);
	kfree(xd);
}

__attribute__((used)) static int xive_irq_domain_map(struct irq_domain *h, unsigned int virq,
			       irq_hw_number_t hw)
{
	int rc;

	/*
	 * Mark interrupts as edge sensitive by default so that resend
	 * actually works. Will fix that up below if needed.
	 */
	irq_clear_status_flags(virq, IRQ_LEVEL);

#ifdef CONFIG_SMP
	/* IPIs are special and come up with HW number 0 */
	if (hw == 0) {
		/*
		 * IPIs are marked per-cpu. We use separate HW interrupts under
		 * the hood but associated with the same "linux" interrupt
		 */
		irq_set_chip_and_handler(virq, &xive_ipi_chip,
					 handle_percpu_irq);
		return 0;
	}
#endif

	rc = xive_irq_alloc_data(virq, hw);
	if (rc)
		return rc;

	irq_set_chip_and_handler(virq, &xive_irq_chip, handle_fasteoi_irq);

	return 0;
}

__attribute__((used)) static void xive_irq_domain_unmap(struct irq_domain *d, unsigned int virq)
{
	struct irq_data *data = irq_get_irq_data(virq);
	unsigned int hw_irq;

	/* XXX Assign BAD number */
	if (!data)
		return;
	hw_irq = (unsigned int)irqd_to_hwirq(data);
	if (hw_irq)
		xive_irq_free_data(virq);
}

__attribute__((used)) static int xive_irq_domain_xlate(struct irq_domain *h, struct device_node *ct,
				 const u32 *intspec, unsigned int intsize,
				 irq_hw_number_t *out_hwirq, unsigned int *out_flags)

{
	*out_hwirq = intspec[0];

	/*
	 * If intsize is at least 2, we look for the type in the second cell,
	 * we assume the LSB indicates a level interrupt.
	 */
	if (intsize > 1) {
		if (intspec[1] & 1)
			*out_flags = IRQ_TYPE_LEVEL_LOW;
		else
			*out_flags = IRQ_TYPE_EDGE_RISING;
	} else
		*out_flags = IRQ_TYPE_LEVEL_LOW;

	return 0;
}

__attribute__((used)) static int xive_irq_domain_match(struct irq_domain *h, struct device_node *node,
				 enum irq_domain_bus_token bus_token)
{
	return xive_ops->match(node);
}


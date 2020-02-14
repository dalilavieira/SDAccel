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
typedef  int u64 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct xive_q {unsigned int msk; int eoi_phys; int /*<<< orphan*/ * qpage; void* esc_irq; scalar_t__ toggle; scalar_t__ idx; } ;
struct xive_irq_data {int eoi_page; int trig_page; unsigned int esb_shift; void* trig_mmio; void* eoi_mmio; scalar_t__ hw_irq; void* src_chip; int /*<<< orphan*/  flags; } ;
struct xive_cpu {int pending_prio; size_t cppr; struct xive_q* queue; } ;
struct device_node {int dummy; } ;
typedef  scalar_t__ s64 ;
typedef  int /*<<< orphan*/  __be64 ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 scalar_t__ OPAL_BUSY ; 
 int /*<<< orphan*/  OPAL_BUSY_DELAY_MS ; 
 int /*<<< orphan*/  OPAL_XIVE_ANY_CHIP ; 
 int OPAL_XIVE_EQ_ALWAYS_NOTIFY ; 
 int OPAL_XIVE_EQ_ENABLED ; 
 int OPAL_XIVE_EQ_ESCALATE ; 
 int OPAL_XIVE_IRQ_EOI_VIA_FW ; 
 int OPAL_XIVE_IRQ_LSI ; 
 int OPAL_XIVE_IRQ_MASK_VIA_FW ; 
 int OPAL_XIVE_IRQ_SHIFT_BUG ; 
 int OPAL_XIVE_IRQ_STORE_EOI ; 
 int /*<<< orphan*/  OPAL_XIVE_MODE_EMU ; 
 int OPAL_XIVE_VP_ENABLED ; 
 int OPAL_XIVE_VP_SINGLE_ESCALATION ; 
 scalar_t__ PAGE_SHIFT ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int TM_QW2W2_VP ; 
 scalar_t__ TM_QW2_HV_POOL ; 
#define  TM_QW3_NSR_HE_LSI 131 
#define  TM_QW3_NSR_HE_NONE 130 
#define  TM_QW3_NSR_HE_PHYS 129 
#define  TM_QW3_NSR_HE_POOL 128 
 scalar_t__ TM_SPC_ACK_HV_REG ; 
 scalar_t__ TM_SPC_PULL_POOL_CTX ; 
 scalar_t__ TM_WORD0 ; 
 scalar_t__ TM_WORD2 ; 
 scalar_t__ WARN_ON (int) ; 
 scalar_t__ XIVE_INVALID_VP ; 
 int /*<<< orphan*/  XIVE_IRQ_FLAG_EOI_FW ; 
 int /*<<< orphan*/  XIVE_IRQ_FLAG_LSI ; 
 int /*<<< orphan*/  XIVE_IRQ_FLAG_MASK_FW ; 
 int /*<<< orphan*/  XIVE_IRQ_FLAG_SHIFT_BUG ; 
 int /*<<< orphan*/  XIVE_IRQ_FLAG_STORE_EOI ; 
 int /*<<< orphan*/  XIVE_SYNC_EAS ; 
 int __pa (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_readw (scalar_t__) ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 void* be32_to_cpu (int /*<<< orphan*/ ) ; 
 int be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_pages (unsigned long,unsigned int) ; 
 scalar_t__ get_hard_smp_processor_id (unsigned int) ; 
 int in_be32 (scalar_t__) ; 
 int /*<<< orphan*/  in_be64 (scalar_t__) ; 
 void* ioremap (int,unsigned int) ; 
 int /*<<< orphan*/  kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kmem_cache_create (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  memset (struct xive_irq_data*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nr_cpu_ids ; 
 int of_device_is_compatible (struct device_node*,char*) ; 
 int of_property_count_elems_of_size (struct device_node*,char*,int) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int of_property_read_u32_array (struct device_node*,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  opal_int_eoi (scalar_t__) ; 
 scalar_t__ opal_xive_allocate_irq (int /*<<< orphan*/ ) ; 
 scalar_t__ opal_xive_free_irq (scalar_t__) ; 
 scalar_t__ opal_xive_free_vp_block (scalar_t__) ; 
 scalar_t__ opal_xive_get_irq_info (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ opal_xive_get_queue_info (scalar_t__,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ opal_xive_get_vp_info (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opal_xive_reset (int /*<<< orphan*/ ) ; 
 scalar_t__ opal_xive_set_irq_config (scalar_t__,scalar_t__,size_t,scalar_t__) ; 
 scalar_t__ opal_xive_set_queue_info (scalar_t__,size_t,int,scalar_t__,int) ; 
 scalar_t__ opal_xive_set_vp_info (scalar_t__,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  opal_xive_sync (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  out_be32 (scalar_t__,int) ; 
 int /*<<< orphan*/  pr_debug (char*,scalar_t__,...) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*,scalar_t__) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  wmb () ; 
 int xive_has_single_esc ; 
 scalar_t__ xive_native_alloc_vp_block (int /*<<< orphan*/ ) ; 
 scalar_t__ xive_pool_vps ; 
 int /*<<< orphan*/  xive_provision_cache ; 
 int xive_provision_chip_count ; 
 int /*<<< orphan*/  xive_provision_chips ; 
 int /*<<< orphan*/  xive_provision_size ; 
 int /*<<< orphan*/ * xive_queue_page_alloc (unsigned int,scalar_t__) ; 
 scalar_t__ xive_queue_shift ; 
 scalar_t__ xive_tima ; 

__attribute__((used)) static inline u32 xive_alloc_order(u32 queue_shift)
{
	return (queue_shift > PAGE_SHIFT) ? (queue_shift - PAGE_SHIFT) : 0;
}

int xive_native_populate_irq_data(u32 hw_irq, struct xive_irq_data *data)
{
	__be64 flags, eoi_page, trig_page;
	__be32 esb_shift, src_chip;
	u64 opal_flags;
	s64 rc;

	memset(data, 0, sizeof(*data));

	rc = opal_xive_get_irq_info(hw_irq, &flags, &eoi_page, &trig_page,
				    &esb_shift, &src_chip);
	if (rc) {
		pr_err("opal_xive_get_irq_info(0x%x) returned %lld\n",
		       hw_irq, rc);
		return -EINVAL;
	}

	opal_flags = be64_to_cpu(flags);
	if (opal_flags & OPAL_XIVE_IRQ_STORE_EOI)
		data->flags |= XIVE_IRQ_FLAG_STORE_EOI;
	if (opal_flags & OPAL_XIVE_IRQ_LSI)
		data->flags |= XIVE_IRQ_FLAG_LSI;
	if (opal_flags & OPAL_XIVE_IRQ_SHIFT_BUG)
		data->flags |= XIVE_IRQ_FLAG_SHIFT_BUG;
	if (opal_flags & OPAL_XIVE_IRQ_MASK_VIA_FW)
		data->flags |= XIVE_IRQ_FLAG_MASK_FW;
	if (opal_flags & OPAL_XIVE_IRQ_EOI_VIA_FW)
		data->flags |= XIVE_IRQ_FLAG_EOI_FW;
	data->eoi_page = be64_to_cpu(eoi_page);
	data->trig_page = be64_to_cpu(trig_page);
	data->esb_shift = be32_to_cpu(esb_shift);
	data->src_chip = be32_to_cpu(src_chip);

	data->eoi_mmio = ioremap(data->eoi_page, 1u << data->esb_shift);
	if (!data->eoi_mmio) {
		pr_err("Failed to map EOI page for irq 0x%x\n", hw_irq);
		return -ENOMEM;
	}

	data->hw_irq = hw_irq;

	if (!data->trig_page)
		return 0;
	if (data->trig_page == data->eoi_page) {
		data->trig_mmio = data->eoi_mmio;
		return 0;
	}

	data->trig_mmio = ioremap(data->trig_page, 1u << data->esb_shift);
	if (!data->trig_mmio) {
		pr_err("Failed to map trigger page for irq 0x%x\n", hw_irq);
		return -ENOMEM;
	}
	return 0;
}

int xive_native_configure_irq(u32 hw_irq, u32 target, u8 prio, u32 sw_irq)
{
	s64 rc;

	for (;;) {
		rc = opal_xive_set_irq_config(hw_irq, target, prio, sw_irq);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	return rc == 0 ? 0 : -ENXIO;
}

int xive_native_configure_queue(u32 vp_id, struct xive_q *q, u8 prio,
				__be32 *qpage, u32 order, bool can_escalate)
{
	s64 rc = 0;
	__be64 qeoi_page_be;
	__be32 esc_irq_be;
	u64 flags, qpage_phys;

	/* If there's an actual queue page, clean it */
	if (order) {
		if (WARN_ON(!qpage))
			return -EINVAL;
		qpage_phys = __pa(qpage);
	} else
		qpage_phys = 0;

	/* Initialize the rest of the fields */
	q->msk = order ? ((1u << (order - 2)) - 1) : 0;
	q->idx = 0;
	q->toggle = 0;

	rc = opal_xive_get_queue_info(vp_id, prio, NULL, NULL,
				      &qeoi_page_be,
				      &esc_irq_be,
				      NULL);
	if (rc) {
		pr_err("Error %lld getting queue info prio %d\n", rc, prio);
		rc = -EIO;
		goto fail;
	}
	q->eoi_phys = be64_to_cpu(qeoi_page_be);

	/* Default flags */
	flags = OPAL_XIVE_EQ_ALWAYS_NOTIFY | OPAL_XIVE_EQ_ENABLED;

	/* Escalation needed ? */
	if (can_escalate) {
		q->esc_irq = be32_to_cpu(esc_irq_be);
		flags |= OPAL_XIVE_EQ_ESCALATE;
	}

	/* Configure and enable the queue in HW */
	for (;;) {
		rc = opal_xive_set_queue_info(vp_id, prio, qpage_phys, order, flags);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	if (rc) {
		pr_err("Error %lld setting queue for prio %d\n", rc, prio);
		rc = -EIO;
	} else {
		/*
		 * KVM code requires all of the above to be visible before
		 * q->qpage is set due to how it manages IPI EOIs
		 */
		wmb();
		q->qpage = qpage;
	}
fail:
	return rc;
}

__attribute__((used)) static void __xive_native_disable_queue(u32 vp_id, struct xive_q *q, u8 prio)
{
	s64 rc;

	/* Disable the queue in HW */
	for (;;) {
		rc = opal_xive_set_queue_info(vp_id, prio, 0, 0, 0);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	if (rc)
		pr_err("Error %lld disabling queue for prio %d\n", rc, prio);
}

void xive_native_disable_queue(u32 vp_id, struct xive_q *q, u8 prio)
{
	__xive_native_disable_queue(vp_id, q, prio);
}

__attribute__((used)) static int xive_native_setup_queue(unsigned int cpu, struct xive_cpu *xc, u8 prio)
{
	struct xive_q *q = &xc->queue[prio];
	__be32 *qpage;

	qpage = xive_queue_page_alloc(cpu, xive_queue_shift);
	if (IS_ERR(qpage))
		return PTR_ERR(qpage);

	return xive_native_configure_queue(get_hard_smp_processor_id(cpu),
					   q, prio, qpage, xive_queue_shift, false);
}

__attribute__((used)) static void xive_native_cleanup_queue(unsigned int cpu, struct xive_cpu *xc, u8 prio)
{
	struct xive_q *q = &xc->queue[prio];
	unsigned int alloc_order;

	/*
	 * We use the variant with no iounmap as this is called on exec
	 * from an IPI and iounmap isn't safe
	 */
	__xive_native_disable_queue(get_hard_smp_processor_id(cpu), q, prio);
	alloc_order = xive_alloc_order(xive_queue_shift);
	free_pages((unsigned long)q->qpage, alloc_order);
	q->qpage = NULL;
}

__attribute__((used)) static bool xive_native_match(struct device_node *node)
{
	return of_device_is_compatible(node, "ibm,opal-xive-vc");
}

u32 xive_native_alloc_irq(void)
{
	s64 rc;

	for (;;) {
		rc = opal_xive_allocate_irq(OPAL_XIVE_ANY_CHIP);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	if (rc < 0)
		return 0;
	return rc;
}

void xive_native_free_irq(u32 irq)
{
	for (;;) {
		s64 rc = opal_xive_free_irq(irq);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
}

__attribute__((used)) static void xive_native_shutdown(void)
{
	/* Switch the XIVE to emulation mode */
	opal_xive_reset(OPAL_XIVE_MODE_EMU);
}

__attribute__((used)) static void xive_native_update_pending(struct xive_cpu *xc)
{
	u8 he, cppr;
	u16 ack;

	/* Perform the acknowledge hypervisor to register cycle */
	ack = be16_to_cpu(__raw_readw(xive_tima + TM_SPC_ACK_HV_REG));

	/* Synchronize subsequent queue accesses */
	mb();

	/*
	 * Grab the CPPR and the "HE" field which indicates the source
	 * of the hypervisor interrupt (if any)
	 */
	cppr = ack & 0xff;
	he = (ack >> 8) >> 6;
	switch(he) {
	case TM_QW3_NSR_HE_NONE: /* Nothing to see here */
		break;
	case TM_QW3_NSR_HE_PHYS: /* Physical thread interrupt */
		if (cppr == 0xff)
			return;
		/* Mark the priority pending */
		xc->pending_prio |= 1 << cppr;

		/*
		 * A new interrupt should never have a CPPR less favored
		 * than our current one.
		 */
		if (cppr >= xc->cppr)
			pr_err("CPU %d odd ack CPPR, got %d at %d\n",
			       smp_processor_id(), cppr, xc->cppr);

		/* Update our idea of what the CPPR is */
		xc->cppr = cppr;
		break;
	case TM_QW3_NSR_HE_POOL: /* HV Pool interrupt (unused) */
	case TM_QW3_NSR_HE_LSI:  /* Legacy FW LSI (unused) */
		pr_err("CPU %d got unexpected interrupt type HE=%d\n",
		       smp_processor_id(), he);
		return;
	}
}

__attribute__((used)) static void xive_native_eoi(u32 hw_irq)
{
	/*
	 * Not normally used except if specific interrupts need
	 * a workaround on EOI.
	 */
	opal_int_eoi(hw_irq);
}

__attribute__((used)) static void xive_native_setup_cpu(unsigned int cpu, struct xive_cpu *xc)
{
	s64 rc;
	u32 vp;
	__be64 vp_cam_be;
	u64 vp_cam;

	if (xive_pool_vps == XIVE_INVALID_VP)
		return;

	/* Check if pool VP already active, if it is, pull it */
	if (in_be32(xive_tima + TM_QW2_HV_POOL + TM_WORD2) & TM_QW2W2_VP)
		in_be64(xive_tima + TM_SPC_PULL_POOL_CTX);

	/* Enable the pool VP */
	vp = xive_pool_vps + cpu;
	for (;;) {
		rc = opal_xive_set_vp_info(vp, OPAL_XIVE_VP_ENABLED, 0);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	if (rc) {
		pr_err("Failed to enable pool VP on CPU %d\n", cpu);
		return;
	}

	/* Grab it's CAM value */
	rc = opal_xive_get_vp_info(vp, NULL, &vp_cam_be, NULL, NULL);
	if (rc) {
		pr_err("Failed to get pool VP info CPU %d\n", cpu);
		return;
	}
	vp_cam = be64_to_cpu(vp_cam_be);

	/* Push it on the CPU (set LSMFB to 0xff to skip backlog scan) */
	out_be32(xive_tima + TM_QW2_HV_POOL + TM_WORD0, 0xff);
	out_be32(xive_tima + TM_QW2_HV_POOL + TM_WORD2, TM_QW2W2_VP | vp_cam);
}

__attribute__((used)) static void xive_native_teardown_cpu(unsigned int cpu, struct xive_cpu *xc)
{
	s64 rc;
	u32 vp;

	if (xive_pool_vps == XIVE_INVALID_VP)
		return;

	/* Pull the pool VP from the CPU */
	in_be64(xive_tima + TM_SPC_PULL_POOL_CTX);

	/* Disable it */
	vp = xive_pool_vps + cpu;
	for (;;) {
		rc = opal_xive_set_vp_info(vp, 0, 0);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
}

void xive_native_sync_source(u32 hw_irq)
{
	opal_xive_sync(XIVE_SYNC_EAS, hw_irq);
}

__attribute__((used)) static bool xive_parse_provisioning(struct device_node *np)
{
	int rc;

	if (of_property_read_u32(np, "ibm,xive-provision-page-size",
				 &xive_provision_size) < 0)
		return true;
	rc = of_property_count_elems_of_size(np, "ibm,xive-provision-chips", 4);
	if (rc < 0) {
		pr_err("Error %d getting provision chips array\n", rc);
		return false;
	}
	xive_provision_chip_count = rc;
	if (rc == 0)
		return true;

	xive_provision_chips = kcalloc(4, xive_provision_chip_count,
				       GFP_KERNEL);
	if (WARN_ON(!xive_provision_chips))
		return false;

	rc = of_property_read_u32_array(np, "ibm,xive-provision-chips",
					xive_provision_chips,
					xive_provision_chip_count);
	if (rc < 0) {
		pr_err("Error %d reading provision chips array\n", rc);
		return false;
	}

	xive_provision_cache = kmem_cache_create("xive-provision",
						 xive_provision_size,
						 xive_provision_size,
						 0, NULL);
	if (!xive_provision_cache) {
		pr_err("Failed to allocate provision cache\n");
		return false;
	}
	return true;
}

__attribute__((used)) static void xive_native_setup_pools(void)
{
	/* Allocate a pool big enough */
	pr_debug("XIVE: Allocating VP block for pool size %u\n", nr_cpu_ids);

	xive_pool_vps = xive_native_alloc_vp_block(nr_cpu_ids);
	if (WARN_ON(xive_pool_vps == XIVE_INVALID_VP))
		pr_err("XIVE: Failed to allocate pool VP, KVM might not function\n");

	pr_debug("XIVE: Pool VPs allocated at 0x%x for %u max CPUs\n",
		 xive_pool_vps, nr_cpu_ids);
}

u32 xive_native_default_eq_shift(void)
{
	return xive_queue_shift;
}

void xive_native_free_vp_block(u32 vp_base)
{
	s64 rc;

	if (vp_base == XIVE_INVALID_VP)
		return;

	rc = opal_xive_free_vp_block(vp_base);
	if (rc < 0)
		pr_warn("OPAL error %lld freeing VP block\n", rc);
}

int xive_native_enable_vp(u32 vp_id, bool single_escalation)
{
	s64 rc;
	u64 flags = OPAL_XIVE_VP_ENABLED;

	if (single_escalation)
		flags |= OPAL_XIVE_VP_SINGLE_ESCALATION;
	for (;;) {
		rc = opal_xive_set_vp_info(vp_id, flags, 0);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	return rc ? -EIO : 0;
}

int xive_native_disable_vp(u32 vp_id)
{
	s64 rc;

	for (;;) {
		rc = opal_xive_set_vp_info(vp_id, 0, 0);
		if (rc != OPAL_BUSY)
			break;
		msleep(OPAL_BUSY_DELAY_MS);
	}
	return rc ? -EIO : 0;
}

int xive_native_get_vp_info(u32 vp_id, u32 *out_cam_id, u32 *out_chip_id)
{
	__be64 vp_cam_be;
	__be32 vp_chip_id_be;
	s64 rc;

	rc = opal_xive_get_vp_info(vp_id, NULL, &vp_cam_be, NULL, &vp_chip_id_be);
	if (rc)
		return -EIO;
	*out_cam_id = be64_to_cpu(vp_cam_be) & 0xffffffffu;
	*out_chip_id = be32_to_cpu(vp_chip_id_be);

	return 0;
}

bool xive_native_has_single_escalation(void)
{
	return xive_has_single_esc;
}


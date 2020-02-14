#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct slice_data {int* level_to_irq; } ;
struct ioc3 {scalar_t__ eier; } ;
struct hub_data {int /*<<< orphan*/  slice_map; struct slice_data* slice; int /*<<< orphan*/  irq_alloc_mask; int /*<<< orphan*/  h_cpus; } ;
typedef  int /*<<< orphan*/  nasid_t ;
typedef  int cnodeid_t ;
struct TYPE_4__ {scalar_t__ memory_base; } ;
struct TYPE_3__ {struct slice_data* data; } ;

/* Variables and functions */
 int BASE_PCI_IRQ ; 
 int /*<<< orphan*/  COMPACT_TO_NASID_NODEID (int) ; 
 int /*<<< orphan*/  IIO_ICTO ; 
 int /*<<< orphan*/  IIO_ICTP ; 
 scalar_t__ INT_PEND0_BASELVL ; 
 scalar_t__ INT_PEND1_BASELVL ; 
 int IP_PEND0_6_63 ; 
 TYPE_2__* KL_CONFIG_CH_CONS_INFO (int /*<<< orphan*/ ) ; 
 int LEVELS_PER_SLICE ; 
 int /*<<< orphan*/  LOCAL_HUB_CLR_INTR (scalar_t__) ; 
 int LOCAL_HUB_L (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOCAL_HUB_S (int /*<<< orphan*/ ,int) ; 
 int MSC_PANIC_INTR ; 
 int NASID_TO_COMPACT_NODEID (int /*<<< orphan*/ ) ; 
 int NI_BRDCAST_ERR_A ; 
 int /*<<< orphan*/  NI_STATUS_REV_ID ; 
 int NSRI_NODEID_MASK ; 
 int NSRI_NODEID_SHFT ; 
 int /*<<< orphan*/  PI_CPU_NUM ; 
 int /*<<< orphan*/  PI_INT_PEND_MOD ; 
 int /*<<< orphan*/  REMOTE_HUB_S (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int SRB_DEV0 ; 
 int SRB_DEV1 ; 
 int /*<<< orphan*/  ST0_IM ; 
 int /*<<< orphan*/  __set_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_c0_status (int /*<<< orphan*/ ) ; 
 TYPE_1__* cpu_data ; 
 int /*<<< orphan*/  cpu_time_init () ; 
 int /*<<< orphan*/  cpumask_set_cpu (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cputoslice (int) ; 
 int get_compact_nodeid () ; 
 struct hub_data* hub_data (int) ; 
 int /*<<< orphan*/ * hub_init_mask ; 
 int /*<<< orphan*/  hub_rtc_init (int) ; 
 int /*<<< orphan*/  install_cpu_nmi_handler (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  install_ipi () ; 
 int /*<<< orphan*/  set_c0_status (int) ; 
 int smp_processor_id () ; 
 scalar_t__ test_and_set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xtalk_probe_node (int) ; 

__attribute__((used)) static void per_hub_init(cnodeid_t cnode)
{
	struct hub_data *hub = hub_data(cnode);
	nasid_t nasid = COMPACT_TO_NASID_NODEID(cnode);
	int i;

	cpumask_set_cpu(smp_processor_id(), &hub->h_cpus);

	if (test_and_set_bit(cnode, hub_init_mask))
		return;
	/*
	 * Set CRB timeout at 5ms, (< PI timeout of 10ms)
	 */
	REMOTE_HUB_S(nasid, IIO_ICTP, 0x800);
	REMOTE_HUB_S(nasid, IIO_ICTO, 0xff);

	hub_rtc_init(cnode);
	xtalk_probe_node(cnode);

#ifdef CONFIG_REPLICATE_EXHANDLERS
	/*
	 * If this is not a headless node initialization,
	 * copy over the caliased exception handlers.
	 */
	if (get_compact_nodeid() == cnode) {
		extern char except_vec2_generic, except_vec3_generic;
		extern void build_tlb_refill_handler(void);

		memcpy((void *)(CKSEG0 + 0x100), &except_vec2_generic, 0x80);
		memcpy((void *)(CKSEG0 + 0x180), &except_vec3_generic, 0x80);
		build_tlb_refill_handler();
		memcpy((void *)(CKSEG0 + 0x100), (void *) CKSEG0, 0x80);
		memcpy((void *)(CKSEG0 + 0x180), &except_vec3_generic, 0x100);
		__flush_cache_all();
	}
#endif

	/*
	 * Some interrupts are reserved by hardware or by software convention.
	 * Mark these as reserved right away so they won't be used accidentally
	 * later.
	 */
	for (i = 0; i <= BASE_PCI_IRQ; i++) {
		__set_bit(i, hub->irq_alloc_mask);
		LOCAL_HUB_CLR_INTR(INT_PEND0_BASELVL + i);
	}

	__set_bit(IP_PEND0_6_63, hub->irq_alloc_mask);
	LOCAL_HUB_S(PI_INT_PEND_MOD, IP_PEND0_6_63);

	for (i = NI_BRDCAST_ERR_A; i <= MSC_PANIC_INTR; i++) {
		__set_bit(i, hub->irq_alloc_mask);
		LOCAL_HUB_CLR_INTR(INT_PEND1_BASELVL + i);
	}
}

void per_cpu_init(void)
{
	int cpu = smp_processor_id();
	int slice = LOCAL_HUB_L(PI_CPU_NUM);
	cnodeid_t cnode = get_compact_nodeid();
	struct hub_data *hub = hub_data(cnode);
	struct slice_data *si = hub->slice + slice;
	int i;

	if (test_and_set_bit(slice, &hub->slice_map))
		return;

	clear_c0_status(ST0_IM);

	per_hub_init(cnode);

	for (i = 0; i < LEVELS_PER_SLICE; i++)
		si->level_to_irq[i] = -1;

	/*
	 * We use this so we can find the local hub's data as fast as only
	 * possible.
	 */
	cpu_data[cpu].data = si;

	cpu_time_init();
	install_ipi();

	/* Install our NMI handler if symmon hasn't installed one. */
	install_cpu_nmi_handler(cputoslice(cpu));

	set_c0_status(SRB_DEV0 | SRB_DEV1);
}

nasid_t
get_nasid(void)
{
	return (nasid_t)((LOCAL_HUB_L(NI_STATUS_REV_ID) & NSRI_NODEID_MASK)
			 >> NSRI_NODEID_SHFT);
}

cnodeid_t get_compact_nodeid(void)
{
	return NASID_TO_COMPACT_NODEID(get_nasid());
}

__attribute__((used)) static inline void ioc3_eth_init(void)
{
	struct ioc3 *ioc3;
	nasid_t nid;

	nid = get_nasid();
	ioc3 = (struct ioc3 *) KL_CONFIG_CH_CONS_INFO(nid)->memory_base;

	ioc3->eier = 0;
}


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
struct nps_host_reg_thr_init_sts {scalar_t__ thr_id; scalar_t__ err; scalar_t__ bsy; void* value; } ;
struct nps_host_reg_thr_init {scalar_t__ thr_id; int str; void* value; } ;
struct nps_host_reg_mtm_cfg {int nat; int ten; void* value; } ;
struct nps_host_reg_aux_udmc {int nat; scalar_t__ value; } ;
struct nps_host_reg_aux_mt_ctrl {int hsen; int mten; scalar_t__ value; int /*<<< orphan*/  hs_cnt; } ;
struct nps_host_reg_aux_dpc {int ien; int men; scalar_t__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  CTOP_AUX_DPC ; 
 int /*<<< orphan*/  CTOP_AUX_MT_CTRL ; 
 int /*<<< orphan*/  CTOP_AUX_UDMC ; 
 int /*<<< orphan*/  MTM_CFG (unsigned int) ; 
 int /*<<< orphan*/  MTM_THR_INIT (int) ; 
 int /*<<< orphan*/  MTM_THR_INIT_STS (int) ; 
 scalar_t__ NPS_CPU_TO_THREAD_NUM (unsigned int) ; 
 int NPS_NUM_HW_THREADS ; 
 int /*<<< orphan*/  cpu_possible_mask ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  cpumask_bits (int /*<<< orphan*/ ) ; 
 int ilog2 (int) ; 
 void* ioread32be (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iowrite32be (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtm_hs_ctr ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 
 scalar_t__ read_aux_reg (int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_aux_reg (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void mtm_init_nat(int cpu)
{
	struct nps_host_reg_mtm_cfg mtm_cfg;
	struct nps_host_reg_aux_udmc udmc;
	int log_nat, nat = 0, i, t;

	/* Iterate core threads and update nat */
	for (i = 0, t = cpu; i < NPS_NUM_HW_THREADS; i++, t++)
		nat += test_bit(t, cpumask_bits(cpu_possible_mask));

	log_nat = ilog2(nat);

	udmc.value = read_aux_reg(CTOP_AUX_UDMC);
	udmc.nat = log_nat;
	write_aux_reg(CTOP_AUX_UDMC, udmc.value);

	mtm_cfg.value = ioread32be(MTM_CFG(cpu));
	mtm_cfg.nat = log_nat;
	iowrite32be(mtm_cfg.value, MTM_CFG(cpu));
}

__attribute__((used)) static void mtm_init_thread(int cpu)
{
	int i, tries = 5;
	struct nps_host_reg_thr_init thr_init;
	struct nps_host_reg_thr_init_sts thr_init_sts;

	/* Set thread init register */
	thr_init.value = 0;
	iowrite32be(thr_init.value, MTM_THR_INIT(cpu));
	thr_init.thr_id = NPS_CPU_TO_THREAD_NUM(cpu);
	thr_init.str = 1;
	iowrite32be(thr_init.value, MTM_THR_INIT(cpu));

	/* Poll till thread init is done */
	for (i = 0; i < tries; i++) {
		thr_init_sts.value = ioread32be(MTM_THR_INIT_STS(cpu));
		if (thr_init_sts.thr_id == thr_init.thr_id) {
			if (thr_init_sts.bsy)
				continue;
			else if (thr_init_sts.err)
				pr_warn("Failed to thread init cpu %u\n", cpu);
			break;
		}

		pr_warn("Wrong thread id in thread init for cpu %u\n", cpu);
		break;
	}

	if (i == tries)
		pr_warn("Got thread init timeout for cpu %u\n", cpu);
}

int mtm_enable_thread(int cpu)
{
	struct nps_host_reg_mtm_cfg mtm_cfg;

	if (NPS_CPU_TO_THREAD_NUM(cpu) == 0)
		return 1;

	/* Enable thread in mtm */
	mtm_cfg.value = ioread32be(MTM_CFG(cpu));
	mtm_cfg.ten |= (1 << (NPS_CPU_TO_THREAD_NUM(cpu)));
	iowrite32be(mtm_cfg.value, MTM_CFG(cpu));

	return 0;
}

void mtm_enable_core(unsigned int cpu)
{
	int i;
	struct nps_host_reg_aux_mt_ctrl mt_ctrl;
	struct nps_host_reg_mtm_cfg mtm_cfg;
	struct nps_host_reg_aux_dpc dpc;

	/*
	 * Initializing dpc register in each CPU.
	 * Overwriting the init value of the DPC
	 * register so that CMEM and FMT virtual address
	 * spaces are accessible, and Data Plane HW
	 * facilities are enabled.
	 */
	dpc.ien = 1;
	dpc.men = 1;
	write_aux_reg(CTOP_AUX_DPC, dpc.value);

	if (NPS_CPU_TO_THREAD_NUM(cpu) != 0)
		return;

	/* Initialize Number of Active Threads */
	mtm_init_nat(cpu);

	/* Initialize mtm_cfg */
	mtm_cfg.value = ioread32be(MTM_CFG(cpu));
	mtm_cfg.ten = 1;
	iowrite32be(mtm_cfg.value, MTM_CFG(cpu));

	/* Initialize all other threads in core */
	for (i = 1; i < NPS_NUM_HW_THREADS; i++)
		mtm_init_thread(cpu + i);


	/* Enable HW schedule, stall counter, mtm */
	mt_ctrl.value = 0;
	mt_ctrl.hsen = 1;
	mt_ctrl.hs_cnt = mtm_hs_ctr;
	mt_ctrl.mten = 1;
	write_aux_reg(CTOP_AUX_MT_CTRL, mt_ctrl.value);

	/*
	 * HW scheduling mechanism will start working
	 * Only after call to instruction "schd.rw".
	 * cpu_relax() calls "schd.rw" instruction.
	 */
	cpu_relax();
}


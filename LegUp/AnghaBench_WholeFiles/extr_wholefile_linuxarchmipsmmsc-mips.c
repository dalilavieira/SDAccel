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
struct TYPE_2__ {int linesz; } ;
struct cpuinfo_mips {TYPE_1__ scache; } ;

/* Variables and functions */
 int CM_GCR_L2_PFT_CONTROL_B_CEN ; 
 int CM_GCR_L2_PFT_CONTROL_B_PORTID ; 
 unsigned long CM_GCR_L2_PFT_CONTROL_NPFT ; 
 unsigned long CM_GCR_L2_PFT_CONTROL_PAGEMASK ; 
 unsigned long CM_GCR_L2_PFT_CONTROL_PFTEN ; 
 scalar_t__ CM_REV_CM2_5 ; 
#define  CPU_1004K 137 
#define  CPU_1074K 136 
#define  CPU_34K 135 
#define  CPU_74K 134 
#define  CPU_BMIPS5000 133 
#define  CPU_INTERAPTIV 132 
#define  CPU_P5600 131 
#define  CPU_P6600 130 
#define  CPU_PROAPTIV 129 
#define  CPU_QEMU_GENERIC 128 
 int /*<<< orphan*/  Hit_Writeback_Inv_SD ; 
 unsigned long PAGE_MASK ; 
 int /*<<< orphan*/  blast_inv_scache_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  blast_scache_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  cache_op (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  clear_gcr_l2_pft_control (unsigned long) ; 
 int /*<<< orphan*/  clear_gcr_l2_pft_control_b (int) ; 
 unsigned long cpu_scache_line_size () ; 
 int current_cpu_type () ; 
 scalar_t__ mips_cm_revision () ; 
 unsigned int read_c0_config2 () ; 
 unsigned long read_gcr_l2_pft_control () ; 
 int /*<<< orphan*/  set_gcr_l2_pft_control_b (int) ; 
 int /*<<< orphan*/  write_gcr_l2_pft_control (unsigned long) ; 

__attribute__((used)) static void mips_sc_wback_inv(unsigned long addr, unsigned long size)
{
	blast_scache_range(addr, addr + size);
}

__attribute__((used)) static void mips_sc_inv(unsigned long addr, unsigned long size)
{
	unsigned long lsize = cpu_scache_line_size();
	unsigned long almask = ~(lsize - 1);

	cache_op(Hit_Writeback_Inv_SD, addr & almask);
	cache_op(Hit_Writeback_Inv_SD, (addr + size - 1) & almask);
	blast_inv_scache_range(addr, addr + size);
}

__attribute__((used)) static void mips_sc_enable(void)
{
	/* L2 cache is permanently enabled */
}

__attribute__((used)) static void mips_sc_disable(void)
{
	/* L2 cache is permanently enabled */
}

__attribute__((used)) static void mips_sc_prefetch_enable(void)
{
	unsigned long pftctl;

	if (mips_cm_revision() < CM_REV_CM2_5)
		return;

	/*
	 * If there is one or more L2 prefetch unit present then enable
	 * prefetching for both code & data, for all ports.
	 */
	pftctl = read_gcr_l2_pft_control();
	if (pftctl & CM_GCR_L2_PFT_CONTROL_NPFT) {
		pftctl &= ~CM_GCR_L2_PFT_CONTROL_PAGEMASK;
		pftctl |= PAGE_MASK & CM_GCR_L2_PFT_CONTROL_PAGEMASK;
		pftctl |= CM_GCR_L2_PFT_CONTROL_PFTEN;
		write_gcr_l2_pft_control(pftctl);

		set_gcr_l2_pft_control_b(CM_GCR_L2_PFT_CONTROL_B_PORTID |
					 CM_GCR_L2_PFT_CONTROL_B_CEN);
	}
}

__attribute__((used)) static void mips_sc_prefetch_disable(void)
{
	if (mips_cm_revision() < CM_REV_CM2_5)
		return;

	clear_gcr_l2_pft_control(CM_GCR_L2_PFT_CONTROL_PFTEN);
	clear_gcr_l2_pft_control_b(CM_GCR_L2_PFT_CONTROL_B_PORTID |
				   CM_GCR_L2_PFT_CONTROL_B_CEN);
}

__attribute__((used)) static bool mips_sc_prefetch_is_enabled(void)
{
	unsigned long pftctl;

	if (mips_cm_revision() < CM_REV_CM2_5)
		return false;

	pftctl = read_gcr_l2_pft_control();
	if (!(pftctl & CM_GCR_L2_PFT_CONTROL_NPFT))
		return false;
	return !!(pftctl & CM_GCR_L2_PFT_CONTROL_PFTEN);
}

__attribute__((used)) static inline int mips_sc_is_activated(struct cpuinfo_mips *c)
{
	unsigned int config2 = read_c0_config2();
	unsigned int tmp;

	/* Check the bypass bit (L2B) */
	switch (current_cpu_type()) {
	case CPU_34K:
	case CPU_74K:
	case CPU_1004K:
	case CPU_1074K:
	case CPU_INTERAPTIV:
	case CPU_PROAPTIV:
	case CPU_P5600:
	case CPU_BMIPS5000:
	case CPU_QEMU_GENERIC:
	case CPU_P6600:
		if (config2 & (1 << 12))
			return 0;
	}

	tmp = (config2 >> 4) & 0x0f;
	if (0 < tmp && tmp <= 7)
		c->scache.linesz = 2 << tmp;
	else
		return 0;
	return 1;
}


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
typedef  long u32 ;

/* Variables and functions */
 scalar_t__ ARM_CPU_PART_CORTEX_A9 ; 
 int /*<<< orphan*/  C2_STATE ; 
 int ENOSYS ; 
 int /*<<< orphan*/  FW_DO_IDLE_AFTR ; 
 unsigned long S5P_CENTRAL_LOWPWR_CFG ; 
 long S5P_CENTRAL_SEQ_CONFIGURATION ; 
 long S5P_CENTRAL_SEQ_OPTION ; 
 long S5P_CHECK_AFTR ; 
 long S5P_USE_STANDBY_WFE0 ; 
 long S5P_USE_STANDBY_WFI0 ; 
 long S5P_WAKEUP_MASK ; 
 long S5P_WAKEUP_MASK2 ; 
 long S5P_WAKEUP_STAT ; 
 int /*<<< orphan*/  SYS_AFTR ; 
 long __pa_symbol (int /*<<< orphan*/ ) ; 
 int call_firmware_op (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int /*<<< orphan*/  cpu_pm_enter () ; 
 int /*<<< orphan*/  cpu_pm_exit () ; 
 int /*<<< orphan*/  cpu_suspend (int /*<<< orphan*/ ,int (*) (unsigned long)) ; 
 int /*<<< orphan*/  do_idle ; 
 long exynos_boot_vector_addr () ; 
 long exynos_boot_vector_flag () ; 
 int /*<<< orphan*/  exynos_clear_boot_flag (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exynos_cpu_resume ; 
 int /*<<< orphan*/  exynos_set_boot_flag (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exynos_sys_powerdown_conf (int /*<<< orphan*/ ) ; 
 long pmu_base_addr ; 
 scalar_t__ read_cpuid_part () ; 
 long readl_relaxed (long) ; 
 int /*<<< orphan*/  resume ; 
 unsigned long* save_arm_register ; 
 unsigned int smp_processor_id () ; 
 scalar_t__ soc_is_exynos3250 () ; 
 scalar_t__ soc_is_exynos4412 () ; 
 int /*<<< orphan*/  writel_relaxed (long,long) ; 

__attribute__((used)) static inline void exynos_pm_init(void) {}

__attribute__((used)) static inline void exynos_scu_enable(void) { }

__attribute__((used)) static inline void pmu_raw_writel(u32 val, u32 offset)
{
	writel_relaxed(val, pmu_base_addr + offset);
}

__attribute__((used)) static inline u32 pmu_raw_readl(u32 offset)
{
	return readl_relaxed(pmu_base_addr + offset);
}

void exynos_cpu_save_register(void)
{
	unsigned long tmp;

	/* Save Power control register */
	asm ("mrc p15, 0, %0, c15, c0, 0"
	     : "=r" (tmp) : : "cc");

	save_arm_register[0] = tmp;

	/* Save Diagnostic register */
	asm ("mrc p15, 0, %0, c15, c0, 1"
	     : "=r" (tmp) : : "cc");

	save_arm_register[1] = tmp;
}

void exynos_cpu_restore_register(void)
{
	unsigned long tmp;

	/* Restore Power control register */
	tmp = save_arm_register[0];

	asm volatile ("mcr p15, 0, %0, c15, c0, 0"
		      : : "r" (tmp)
		      : "cc");

	/* Restore Diagnostic register */
	tmp = save_arm_register[1];

	asm volatile ("mcr p15, 0, %0, c15, c0, 1"
		      : : "r" (tmp)
		      : "cc");
}

void exynos_pm_central_suspend(void)
{
	unsigned long tmp;

	/* Setting Central Sequence Register for power down mode */
	tmp = pmu_raw_readl(S5P_CENTRAL_SEQ_CONFIGURATION);
	tmp &= ~S5P_CENTRAL_LOWPWR_CFG;
	pmu_raw_writel(tmp, S5P_CENTRAL_SEQ_CONFIGURATION);
}

int exynos_pm_central_resume(void)
{
	unsigned long tmp;

	/*
	 * If PMU failed while entering sleep mode, WFI will be
	 * ignored by PMU and then exiting cpu_do_idle().
	 * S5P_CENTRAL_LOWPWR_CFG bit will not be set automatically
	 * in this situation.
	 */
	tmp = pmu_raw_readl(S5P_CENTRAL_SEQ_CONFIGURATION);
	if (!(tmp & S5P_CENTRAL_LOWPWR_CFG)) {
		tmp |= S5P_CENTRAL_LOWPWR_CFG;
		pmu_raw_writel(tmp, S5P_CENTRAL_SEQ_CONFIGURATION);
		/* clear the wakeup state register */
		pmu_raw_writel(0x0, S5P_WAKEUP_STAT);
		/* No need to perform below restore code */
		return -1;
	}

	return 0;
}

__attribute__((used)) static void exynos_set_wakeupmask(long mask)
{
	pmu_raw_writel(mask, S5P_WAKEUP_MASK);
	if (soc_is_exynos3250())
		pmu_raw_writel(0x0, S5P_WAKEUP_MASK2);
}

__attribute__((used)) static void exynos_cpu_set_boot_vector(long flags)
{
	writel_relaxed(__pa_symbol(exynos_cpu_resume),
		       exynos_boot_vector_addr());
	writel_relaxed(flags, exynos_boot_vector_flag());
}

__attribute__((used)) static int exynos_aftr_finisher(unsigned long flags)
{
	int ret;

	exynos_set_wakeupmask(soc_is_exynos3250() ? 0x40003ffe : 0x0000ff3e);
	/* Set value of power down register for aftr mode */
	exynos_sys_powerdown_conf(SYS_AFTR);

	ret = call_firmware_op(do_idle, FW_DO_IDLE_AFTR);
	if (ret == -ENOSYS) {
		if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A9)
			exynos_cpu_save_register();
		exynos_cpu_set_boot_vector(S5P_CHECK_AFTR);
		cpu_do_idle();
	}

	return 1;
}

void exynos_enter_aftr(void)
{
	unsigned int cpuid = smp_processor_id();

	cpu_pm_enter();

	if (soc_is_exynos3250())
		exynos_set_boot_flag(cpuid, C2_STATE);

	exynos_pm_central_suspend();

	if (soc_is_exynos4412()) {
		/* Setting SEQ_OPTION register */
		pmu_raw_writel(S5P_USE_STANDBY_WFI0 | S5P_USE_STANDBY_WFE0,
			       S5P_CENTRAL_SEQ_OPTION);
	}

	cpu_suspend(0, exynos_aftr_finisher);

	if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A9) {
		exynos_scu_enable();
		if (call_firmware_op(resume) == -ENOSYS)
			exynos_cpu_restore_register();
	}

	exynos_pm_central_resume();

	if (soc_is_exynos3250())
		exynos_clear_boot_flag(cpuid, C2_STATE);

	cpu_pm_exit();
}


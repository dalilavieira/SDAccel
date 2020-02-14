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
typedef  int u32 ;
struct TYPE_4__ {int cpmimr; int cpmcimr; int cpmmcmr; int cpmnmimr; int ippdexpcr; int cdozcr; int cnapcr; int powmgtcsr; int ctbenr; } ;
struct TYPE_3__ {int tpmimr0; int tpmcimr0; int tpmmcmr0; int tpmnmimr0; int* ippdexpcr; int tph10setr0; int pcph15setr; int pcph20setr; int pcph30setr; int tph10clrr0; int pcph15clrr; int pcph20clrr; int pcph30clrr; int powmgtcsr; int pctbenr; } ;

/* Variables and functions */
#define  E500_PM_PH10 133 
#define  E500_PM_PH15 132 
#define  E500_PM_PH20 131 
#define  E500_PM_PH30 130 
 int EINVAL ; 
 int ETIMEDOUT ; 
#define  PLAT_PM_LPM20 129 
#define  PLAT_PM_SLEEP 128 
 int RCPM_POWMGTCSR_LPM20_RQ ; 
 int RCPM_POWMGTCSR_LPM20_ST ; 
 int RCPM_POWMGTCSR_P_LPM20_ST ; 
 int RCPM_POWMGTCSR_SLP ; 
 int /*<<< orphan*/  clrbits32 (int*,int) ; 
 int cpu_core_index_of_thread (int) ; 
 unsigned int fsl_supported_pm_modes ; 
 int get_hard_smp_processor_id (int) ; 
 int in_be32 (int*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 
 TYPE_2__* rcpm_v1_regs ; 
 TYPE_1__* rcpm_v2_regs ; 
 int /*<<< orphan*/  setbits32 (int*,int) ; 
 int spin_event_timeout (int,int,int) ; 
 int threads_per_core ; 

__attribute__((used)) static void rcpm_v1_irq_mask(int cpu)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	setbits32(&rcpm_v1_regs->cpmimr, mask);
	setbits32(&rcpm_v1_regs->cpmcimr, mask);
	setbits32(&rcpm_v1_regs->cpmmcmr, mask);
	setbits32(&rcpm_v1_regs->cpmnmimr, mask);
}

__attribute__((used)) static void rcpm_v2_irq_mask(int cpu)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	setbits32(&rcpm_v2_regs->tpmimr0, mask);
	setbits32(&rcpm_v2_regs->tpmcimr0, mask);
	setbits32(&rcpm_v2_regs->tpmmcmr0, mask);
	setbits32(&rcpm_v2_regs->tpmnmimr0, mask);
}

__attribute__((used)) static void rcpm_v1_irq_unmask(int cpu)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	clrbits32(&rcpm_v1_regs->cpmimr, mask);
	clrbits32(&rcpm_v1_regs->cpmcimr, mask);
	clrbits32(&rcpm_v1_regs->cpmmcmr, mask);
	clrbits32(&rcpm_v1_regs->cpmnmimr, mask);
}

__attribute__((used)) static void rcpm_v2_irq_unmask(int cpu)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	clrbits32(&rcpm_v2_regs->tpmimr0, mask);
	clrbits32(&rcpm_v2_regs->tpmcimr0, mask);
	clrbits32(&rcpm_v2_regs->tpmmcmr0, mask);
	clrbits32(&rcpm_v2_regs->tpmnmimr0, mask);
}

__attribute__((used)) static void rcpm_v1_set_ip_power(bool enable, u32 mask)
{
	if (enable)
		setbits32(&rcpm_v1_regs->ippdexpcr, mask);
	else
		clrbits32(&rcpm_v1_regs->ippdexpcr, mask);
}

__attribute__((used)) static void rcpm_v2_set_ip_power(bool enable, u32 mask)
{
	if (enable)
		setbits32(&rcpm_v2_regs->ippdexpcr[0], mask);
	else
		clrbits32(&rcpm_v2_regs->ippdexpcr[0], mask);
}

__attribute__((used)) static void rcpm_v1_cpu_enter_state(int cpu, int state)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	switch (state) {
	case E500_PM_PH10:
		setbits32(&rcpm_v1_regs->cdozcr, mask);
		break;
	case E500_PM_PH15:
		setbits32(&rcpm_v1_regs->cnapcr, mask);
		break;
	default:
		pr_warn("Unknown cpu PM state (%d)\n", state);
		break;
	}
}

__attribute__((used)) static void rcpm_v2_cpu_enter_state(int cpu, int state)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	u32 mask = 1 << cpu_core_index_of_thread(cpu);

	switch (state) {
	case E500_PM_PH10:
		/* one bit corresponds to one thread for PH10 of 6500 */
		setbits32(&rcpm_v2_regs->tph10setr0, 1 << hw_cpu);
		break;
	case E500_PM_PH15:
		setbits32(&rcpm_v2_regs->pcph15setr, mask);
		break;
	case E500_PM_PH20:
		setbits32(&rcpm_v2_regs->pcph20setr, mask);
		break;
	case E500_PM_PH30:
		setbits32(&rcpm_v2_regs->pcph30setr, mask);
		break;
	default:
		pr_warn("Unknown cpu PM state (%d)\n", state);
	}
}

__attribute__((used)) static void rcpm_v1_cpu_die(int cpu)
{
	rcpm_v1_cpu_enter_state(cpu, E500_PM_PH15);
}

__attribute__((used)) static void rcpm_v2_cpu_die(int cpu)
{
#ifdef CONFIG_PPC64
	int primary;

	if (threads_per_core == 2) {
		primary = cpu_first_thread_sibling(cpu);
		if (cpu_is_offline(primary) && cpu_is_offline(primary + 1)) {
			/* if both threads are offline, put the cpu in PH20 */
			rcpm_v2_cpu_enter_state(cpu, E500_PM_PH20);
		} else {
			/* if only one thread is offline, disable the thread */
			qoriq_disable_thread(cpu);
		}
	}
#endif

	if (threads_per_core == 1)
		rcpm_v2_cpu_enter_state(cpu, E500_PM_PH20);
}

__attribute__((used)) static void rcpm_v1_cpu_exit_state(int cpu, int state)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	switch (state) {
	case E500_PM_PH10:
		clrbits32(&rcpm_v1_regs->cdozcr, mask);
		break;
	case E500_PM_PH15:
		clrbits32(&rcpm_v1_regs->cnapcr, mask);
		break;
	default:
		pr_warn("Unknown cpu PM state (%d)\n", state);
		break;
	}
}

__attribute__((used)) static void rcpm_v1_cpu_up_prepare(int cpu)
{
	rcpm_v1_cpu_exit_state(cpu, E500_PM_PH15);
	rcpm_v1_irq_unmask(cpu);
}

__attribute__((used)) static void rcpm_v2_cpu_exit_state(int cpu, int state)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	u32 mask = 1 << cpu_core_index_of_thread(cpu);

	switch (state) {
	case E500_PM_PH10:
		setbits32(&rcpm_v2_regs->tph10clrr0, 1 << hw_cpu);
		break;
	case E500_PM_PH15:
		setbits32(&rcpm_v2_regs->pcph15clrr, mask);
		break;
	case E500_PM_PH20:
		setbits32(&rcpm_v2_regs->pcph20clrr, mask);
		break;
	case E500_PM_PH30:
		setbits32(&rcpm_v2_regs->pcph30clrr, mask);
		break;
	default:
		pr_warn("Unknown cpu PM state (%d)\n", state);
	}
}

__attribute__((used)) static void rcpm_v2_cpu_up_prepare(int cpu)
{
	rcpm_v2_cpu_exit_state(cpu, E500_PM_PH20);
	rcpm_v2_irq_unmask(cpu);
}

__attribute__((used)) static int rcpm_v1_plat_enter_state(int state)
{
	u32 *pmcsr_reg = &rcpm_v1_regs->powmgtcsr;
	int ret = 0;
	int result;

	switch (state) {
	case PLAT_PM_SLEEP:
		setbits32(pmcsr_reg, RCPM_POWMGTCSR_SLP);

		/* Upon resume, wait for RCPM_POWMGTCSR_SLP bit to be clear. */
		result = spin_event_timeout(
		  !(in_be32(pmcsr_reg) & RCPM_POWMGTCSR_SLP), 10000, 10);
		if (!result) {
			pr_err("timeout waiting for SLP bit to be cleared\n");
			ret = -ETIMEDOUT;
		}
		break;
	default:
		pr_warn("Unknown platform PM state (%d)", state);
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int rcpm_v2_plat_enter_state(int state)
{
	u32 *pmcsr_reg = &rcpm_v2_regs->powmgtcsr;
	int ret = 0;
	int result;

	switch (state) {
	case PLAT_PM_LPM20:
		/* clear previous LPM20 status */
		setbits32(pmcsr_reg, RCPM_POWMGTCSR_P_LPM20_ST);
		/* enter LPM20 status */
		setbits32(pmcsr_reg, RCPM_POWMGTCSR_LPM20_RQ);

		/* At this point, the device is in LPM20 status. */

		/* resume ... */
		result = spin_event_timeout(
		  !(in_be32(pmcsr_reg) & RCPM_POWMGTCSR_LPM20_ST), 10000, 10);
		if (!result) {
			pr_err("timeout waiting for LPM20 bit to be cleared\n");
			ret = -ETIMEDOUT;
		}
		break;
	default:
		pr_warn("Unknown platform PM state (%d)\n", state);
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int rcpm_v1_plat_enter_sleep(void)
{
	return rcpm_v1_plat_enter_state(PLAT_PM_SLEEP);
}

__attribute__((used)) static int rcpm_v2_plat_enter_sleep(void)
{
	return rcpm_v2_plat_enter_state(PLAT_PM_LPM20);
}

__attribute__((used)) static void rcpm_common_freeze_time_base(u32 *tben_reg, int freeze)
{
	static u32 mask;

	if (freeze) {
		mask = in_be32(tben_reg);
		clrbits32(tben_reg, mask);
	} else {
		setbits32(tben_reg, mask);
	}

	/* read back to push the previous write */
	in_be32(tben_reg);
}

__attribute__((used)) static void rcpm_v1_freeze_time_base(bool freeze)
{
	rcpm_common_freeze_time_base(&rcpm_v1_regs->ctbenr, freeze);
}

__attribute__((used)) static void rcpm_v2_freeze_time_base(bool freeze)
{
	rcpm_common_freeze_time_base(&rcpm_v2_regs->pctbenr, freeze);
}

__attribute__((used)) static unsigned int rcpm_get_pm_modes(void)
{
	return fsl_supported_pm_modes;
}


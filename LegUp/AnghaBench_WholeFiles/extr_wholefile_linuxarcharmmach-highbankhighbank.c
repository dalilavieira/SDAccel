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
typedef  int u32 ;
struct notifier_block {int dummy; } ;

/* Variables and functions */
 unsigned long HB_PWR_HARD_RESET ; 
 unsigned long HB_PWR_SHUTDOWN ; 
 unsigned long HB_PWR_SOFT_RESET ; 
 unsigned long HB_PWR_SUSPEND ; 
 scalar_t__ HB_SREG_A9_PWR_REQ ; 
 int KEY_POWER ; 
 int MPIDR_AFFINITY_LEVEL (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCU_PM_NORMAL ; 
 int /*<<< orphan*/  SCU_PM_POWEROFF ; 
 scalar_t__ SREG_CPU_PWR_CTRL (int) ; 
 int /*<<< orphan*/  cpu_logical_map (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ctrl_alt_del () ; 
 int /*<<< orphan*/  orderly_poweroff (int) ; 
 scalar_t__ scu_base_addr ; 
 int /*<<< orphan*/  scu_power_mode (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 scalar_t__ sregs_base ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline void highbank_pm_init(void) {}

__attribute__((used)) static inline void highbank_set_core_pwr(void)
{
	int cpu = MPIDR_AFFINITY_LEVEL(cpu_logical_map(smp_processor_id()), 0);
	if (scu_base_addr)
		scu_power_mode(scu_base_addr, SCU_PM_POWEROFF);
	else
		writel_relaxed(1, sregs_base + SREG_CPU_PWR_CTRL(cpu));
}

__attribute__((used)) static inline void highbank_clear_core_pwr(void)
{
	int cpu = MPIDR_AFFINITY_LEVEL(cpu_logical_map(smp_processor_id()), 0);
	if (scu_base_addr)
		scu_power_mode(scu_base_addr, SCU_PM_NORMAL);
	else
		writel_relaxed(0, sregs_base + SREG_CPU_PWR_CTRL(cpu));
}

__attribute__((used)) static inline void highbank_set_pwr_suspend(void)
{
	writel(HB_PWR_SUSPEND, sregs_base + HB_SREG_A9_PWR_REQ);
	highbank_set_core_pwr();
}

__attribute__((used)) static inline void highbank_set_pwr_shutdown(void)
{
	writel(HB_PWR_SHUTDOWN, sregs_base + HB_SREG_A9_PWR_REQ);
	highbank_set_core_pwr();
}

__attribute__((used)) static inline void highbank_set_pwr_soft_reset(void)
{
	writel(HB_PWR_SOFT_RESET, sregs_base + HB_SREG_A9_PWR_REQ);
	highbank_set_core_pwr();
}

__attribute__((used)) static inline void highbank_set_pwr_hard_reset(void)
{
	writel(HB_PWR_HARD_RESET, sregs_base + HB_SREG_A9_PWR_REQ);
	highbank_set_core_pwr();
}

__attribute__((used)) static inline void highbank_clear_pwr_request(void)
{
	writel(~0UL, sregs_base + HB_SREG_A9_PWR_REQ);
	highbank_clear_core_pwr();
}

__attribute__((used)) static int hb_keys_notifier(struct notifier_block *nb, unsigned long event, void *data)
{
	u32 key = *(u32 *)data;

	if (event != 0x1000)
		return 0;

	if (key == KEY_POWER)
		orderly_poweroff(false);
	else if (key == 0xffff)
		ctrl_alt_del();

	return 0;
}


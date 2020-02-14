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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  (* phys_reset_t ) (unsigned long,int /*<<< orphan*/ ) ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  arm_pm_restart (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  call_with_stack (void (*) (void*),void*,void*) ; 
 int /*<<< orphan*/  cpu_proc_fin () ; 
 int /*<<< orphan*/  cpu_reset ; 
 int /*<<< orphan*/  disable_nonboot_cpus () ; 
 int /*<<< orphan*/  do_kernel_restart (char*) ; 
 int /*<<< orphan*/  flush_cache_all () ; 
 int /*<<< orphan*/  is_hyp_mode_available () ; 
 int /*<<< orphan*/  local_fiq_disable () ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 void machine_power_off () ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int num_online_cpus () ; 
 int /*<<< orphan*/  outer_disable () ; 
 int /*<<< orphan*/  pm_power_off () ; 
 int /*<<< orphan*/  printk (char*) ; 
 int /*<<< orphan*/  raw_local_irq_disable () ; 
 int /*<<< orphan*/  reboot_mode ; 
 int /*<<< orphan*/  setup_mm_for_reboot () ; 
 int /*<<< orphan*/  smp_send_stop () ; 
 int /*<<< orphan*/ * soft_restart_stack ; 
 scalar_t__ virt_to_idmap (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __soft_restart(void *addr)
{
	phys_reset_t phys_reset;

	/* Take out a flat memory mapping. */
	setup_mm_for_reboot();

	/* Clean and invalidate caches */
	flush_cache_all();

	/* Turn off caching */
	cpu_proc_fin();

	/* Push out any further dirty data, and ensure cache is empty */
	flush_cache_all();

	/* Switch to the identity mapping. */
	phys_reset = (phys_reset_t)virt_to_idmap(cpu_reset);

	/* original stub should be restored by kvm */
	phys_reset((unsigned long)addr, is_hyp_mode_available());

	/* Should never get here. */
	BUG();
}

void _soft_restart(unsigned long addr, bool disable_l2)
{
	u64 *stack = soft_restart_stack + ARRAY_SIZE(soft_restart_stack);

	/* Disable interrupts first */
	raw_local_irq_disable();
	local_fiq_disable();

	/* Disable the L2 if we're the last man standing. */
	if (disable_l2)
		outer_disable();

	/* Change to the new stack and continue with the reset. */
	call_with_stack(__soft_restart, (void *)addr, (void *)stack);

	/* Should never get here. */
	BUG();
}

void soft_restart(unsigned long addr)
{
	_soft_restart(addr, num_online_cpus() == 1);
}

void machine_shutdown(void)
{
	disable_nonboot_cpus();
}

void machine_halt(void)
{
	machine_power_off();
}

void machine_power_off(void)
{
	local_irq_disable();
	smp_send_stop();

	if (pm_power_off)
		pm_power_off();
}

void machine_restart(char *cmd)
{
	local_irq_disable();
	smp_send_stop();

	if (arm_pm_restart)
		arm_pm_restart(reboot_mode, cmd);
	else
		do_kernel_restart(cmd);

	/* Give a grace period for failure to restart of 1s */
	mdelay(1000);

	/* Whoops - the platform was unable to reboot. Tell the user! */
	printk("Reboot failed -- System halted\n");
	while (1);
}


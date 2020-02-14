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
struct TYPE_2__ {int /*<<< orphan*/  (* halt ) () ;int /*<<< orphan*/  (* restart ) (char*) ;int /*<<< orphan*/  (* shutdown ) () ;int /*<<< orphan*/  (* power_off ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  __flush_tlb_global () ; 
 int /*<<< orphan*/  cpu_sleep () ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 TYPE_1__ machine_ops ; 
 void machine_shutdown () ; 
 int /*<<< orphan*/  pm_power_off () ; 
 int /*<<< orphan*/  smp_send_stop () ; 
 int /*<<< orphan*/  stop_this_cpu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 () ; 
 int /*<<< orphan*/  stub3 (char*) ; 
 int /*<<< orphan*/  stub4 () ; 
 int /*<<< orphan*/  trigger_address_error () ; 

__attribute__((used)) static void native_machine_restart(char * __unused)
{
	local_irq_disable();

	/* Destroy all of the TLBs in preparation for reset by MMU */
	__flush_tlb_global();

	/* Address error with SR.BL=1 first. */
	trigger_address_error();

#ifdef CONFIG_SUPERH32
	/* If that fails or is unsupported, go for the watchdog next. */
	watchdog_trigger_immediate();
#endif

	/*
	 * Give up and sleep.
	 */
	while (1)
		cpu_sleep();
}

__attribute__((used)) static void native_machine_shutdown(void)
{
	smp_send_stop();
}

__attribute__((used)) static void native_machine_power_off(void)
{
	if (pm_power_off)
		pm_power_off();
}

__attribute__((used)) static void native_machine_halt(void)
{
	/* stop other cpus */
	machine_shutdown();

	/* stop this cpu */
	stop_this_cpu(NULL);
}

void machine_power_off(void)
{
	machine_ops.power_off();
}

void machine_shutdown(void)
{
	machine_ops.shutdown();
}

void machine_restart(char *cmd)
{
	machine_ops.restart(cmd);
}

void machine_halt(void)
{
	machine_ops.halt();
}


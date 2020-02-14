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
struct pt_regs {int dummy; } ;
struct cpumask {int dummy; } ;
typedef  int /*<<< orphan*/  cpumask_var_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* send_IPI_allbutself ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* send_IPI_mask ) (struct cpumask const*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* send_IPI ) (int,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CALL_FUNCTION_SINGLE_VECTOR ; 
 int /*<<< orphan*/  CALL_FUNCTION_VECTOR ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  NMI_FLAG_FIRST ; 
 int NMI_HANDLED ; 
 int /*<<< orphan*/  NMI_LOCAL ; 
 int /*<<< orphan*/  NMI_VECTOR ; 
 int /*<<< orphan*/  REBOOT_VECTOR ; 
 int /*<<< orphan*/  RESCHEDULE_VECTOR ; 
 int USEC_PER_MSEC ; 
 unsigned long USEC_PER_SEC ; 
 int /*<<< orphan*/  WARN (int,char*,int) ; 
 int /*<<< orphan*/  alloc_cpumask_var (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_1__* apic ; 
 int atomic_cmpxchg (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_callout_mask ; 
 int /*<<< orphan*/  cpu_emergency_vmxoff () ; 
 int /*<<< orphan*/  cpu_info ; 
 int /*<<< orphan*/  cpu_is_offline (int) ; 
 struct cpumask const* cpu_online_mask ; 
 int /*<<< orphan*/  cpumask_clear_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_copy (int /*<<< orphan*/ ,struct cpumask const*) ; 
 scalar_t__ cpumask_equal (struct cpumask const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_local_APIC () ; 
 int /*<<< orphan*/  free_cpumask_var (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipi_entering_ack_irq () ; 
 int /*<<< orphan*/  irq_exit () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mcheck_cpu_clear (int /*<<< orphan*/ ) ; 
 int num_online_cpus () ; 
 int /*<<< orphan*/  pr_emerg (char*) ; 
 scalar_t__ raw_smp_processor_id () ; 
 scalar_t__ reboot_force ; 
 scalar_t__ register_nmi_handler (int /*<<< orphan*/ ,int (*) (unsigned int,struct pt_regs*),int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  safe_smp_processor_id () ; 
 int /*<<< orphan*/  smp_no_nmi_ipi ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  stop_this_cpu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stopping_cpu ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct cpumask const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (struct cpumask const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  this_cpu_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udelay (int) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static void native_smp_send_reschedule(int cpu)
{
	if (unlikely(cpu_is_offline(cpu))) {
		WARN(1, "sched: Unexpected reschedule of offline CPU#%d!\n", cpu);
		return;
	}
	apic->send_IPI(cpu, RESCHEDULE_VECTOR);
}

void native_send_call_func_single_ipi(int cpu)
{
	apic->send_IPI(cpu, CALL_FUNCTION_SINGLE_VECTOR);
}

void native_send_call_func_ipi(const struct cpumask *mask)
{
	cpumask_var_t allbutself;

	if (!alloc_cpumask_var(&allbutself, GFP_ATOMIC)) {
		apic->send_IPI_mask(mask, CALL_FUNCTION_VECTOR);
		return;
	}

	cpumask_copy(allbutself, cpu_online_mask);
	cpumask_clear_cpu(smp_processor_id(), allbutself);

	if (cpumask_equal(mask, allbutself) &&
	    cpumask_equal(cpu_online_mask, cpu_callout_mask))
		apic->send_IPI_allbutself(CALL_FUNCTION_VECTOR);
	else
		apic->send_IPI_mask(mask, CALL_FUNCTION_VECTOR);

	free_cpumask_var(allbutself);
}

__attribute__((used)) static int smp_stop_nmi_callback(unsigned int val, struct pt_regs *regs)
{
	/* We are registered on stopping cpu too, avoid spurious NMI */
	if (raw_smp_processor_id() == atomic_read(&stopping_cpu))
		return NMI_HANDLED;

	cpu_emergency_vmxoff();
	stop_this_cpu(NULL);

	return NMI_HANDLED;
}

void smp_reboot_interrupt(void)
{
	ipi_entering_ack_irq();
	cpu_emergency_vmxoff();
	stop_this_cpu(NULL);
	irq_exit();
}

__attribute__((used)) static void native_stop_other_cpus(int wait)
{
	unsigned long flags;
	unsigned long timeout;

	if (reboot_force)
		return;

	/*
	 * Use an own vector here because smp_call_function
	 * does lots of things not suitable in a panic situation.
	 */

	/*
	 * We start by using the REBOOT_VECTOR irq.
	 * The irq is treated as a sync point to allow critical
	 * regions of code on other cpus to release their spin locks
	 * and re-enable irqs.  Jumping straight to an NMI might
	 * accidentally cause deadlocks with further shutdown/panic
	 * code.  By syncing, we give the cpus up to one second to
	 * finish their work before we force them off with the NMI.
	 */
	if (num_online_cpus() > 1) {
		/* did someone beat us here? */
		if (atomic_cmpxchg(&stopping_cpu, -1, safe_smp_processor_id()) != -1)
			return;

		/* sync above data before sending IRQ */
		wmb();

		apic->send_IPI_allbutself(REBOOT_VECTOR);

		/*
		 * Don't wait longer than a second if the caller
		 * didn't ask us to wait.
		 */
		timeout = USEC_PER_SEC;
		while (num_online_cpus() > 1 && (wait || timeout--))
			udelay(1);
	}
	
	/* if the REBOOT_VECTOR didn't work, try with the NMI */
	if ((num_online_cpus() > 1) && (!smp_no_nmi_ipi))  {
		if (register_nmi_handler(NMI_LOCAL, smp_stop_nmi_callback,
					 NMI_FLAG_FIRST, "smp_stop"))
			/* Note: we ignore failures here */
			/* Hope the REBOOT_IRQ is good enough */
			goto finish;

		/* sync above data before sending IRQ */
		wmb();

		pr_emerg("Shutting down cpus with NMI\n");

		apic->send_IPI_allbutself(NMI_VECTOR);

		/*
		 * Don't wait longer than a 10 ms if the caller
		 * didn't ask us to wait.
		 */
		timeout = USEC_PER_MSEC * 10;
		while (num_online_cpus() > 1 && (wait || timeout--))
			udelay(1);
	}

finish:
	local_irq_save(flags);
	disable_local_APIC();
	mcheck_cpu_clear(this_cpu_ptr(&cpu_info));
	local_irq_restore(flags);
}


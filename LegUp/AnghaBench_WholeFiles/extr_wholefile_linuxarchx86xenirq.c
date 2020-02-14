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
struct vcpu_info {int evtchn_upcall_mask; int /*<<< orphan*/  evtchn_upcall_pending; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 scalar_t__ HYPERVISOR_sched_op (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  HYPERVISOR_vcpu_op (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  HYPERVISOR_xen_version (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SCHEDOP_block ; 
 int /*<<< orphan*/  VCPUOP_down ; 
 unsigned long X86_EFLAGS_IF ; 
 int /*<<< orphan*/  barrier () ; 
 scalar_t__ irqs_disabled () ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  preempt_enable_no_resched () ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 struct vcpu_info* this_cpu_read (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xen_vcpu ; 
 int /*<<< orphan*/  xen_vcpu_nr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void xen_smp_init(void) {}

__attribute__((used)) static inline void xen_hvm_smp_init(void) {}

__attribute__((used)) static inline void xen_init_spinlocks(void)
{
}

__attribute__((used)) static inline void xen_init_lock_cpu(int cpu)
{
}

__attribute__((used)) static inline void xen_uninit_lock_cpu(int cpu)
{
}

__attribute__((used)) static inline void xen_pv_pre_suspend(void) {}

__attribute__((used)) static inline void xen_pv_post_suspend(int suspend_cancelled) {}

__attribute__((used)) static inline void xen_hvm_post_suspend(int suspend_cancelled) {}

void xen_force_evtchn_callback(void)
{
	(void)HYPERVISOR_xen_version(0, NULL);
}

unsigned long xen_save_fl(void)
{
	struct vcpu_info *vcpu;
	unsigned long flags;

	vcpu = this_cpu_read(xen_vcpu);

	/* flag has opposite sense of mask */
	flags = !vcpu->evtchn_upcall_mask;

	/* convert to IF type flag
	   -0 -> 0x00000000
	   -1 -> 0xffffffff
	*/
	return (-flags) & X86_EFLAGS_IF;
}

void xen_irq_disable(void)
{
	/* There's a one instruction preempt window here.  We need to
	   make sure we're don't switch CPUs between getting the vcpu
	   pointer and updating the mask. */
	preempt_disable();
	this_cpu_read(xen_vcpu)->evtchn_upcall_mask = 1;
	preempt_enable_no_resched();
}

void xen_irq_enable(void)
{
	struct vcpu_info *vcpu;

	/*
	 * We may be preempted as soon as vcpu->evtchn_upcall_mask is
	 * cleared, so disable preemption to ensure we check for
	 * events on the VCPU we are still running on.
	 */
	preempt_disable();

	vcpu = this_cpu_read(xen_vcpu);
	vcpu->evtchn_upcall_mask = 0;

	/* Doesn't matter if we get preempted here, because any
	   pending event will get dealt with anyway. */

	barrier(); /* unmask then check (avoid races) */
	if (unlikely(vcpu->evtchn_upcall_pending))
		xen_force_evtchn_callback();

	preempt_enable();
}

__attribute__((used)) static void xen_safe_halt(void)
{
	/* Blocking includes an implicit local_irq_enable(). */
	if (HYPERVISOR_sched_op(SCHEDOP_block, NULL) != 0)
		BUG();
}

__attribute__((used)) static void xen_halt(void)
{
	if (irqs_disabled())
		HYPERVISOR_vcpu_op(VCPUOP_down,
				   xen_vcpu_nr(smp_processor_id()), NULL);
	else
		xen_safe_halt();
}


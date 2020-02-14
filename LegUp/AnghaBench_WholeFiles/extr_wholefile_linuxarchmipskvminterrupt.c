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
typedef  int u32 ;
struct mips_coproc {int dummy; } ;
struct kvm_vcpu_arch {unsigned long pending_exceptions; int pc; unsigned long pending_exceptions_clr; struct mips_coproc* cop0; } ;
struct kvm_vcpu {struct kvm_vcpu_arch arch; } ;
struct kvm_mips_interrupt {scalar_t__ irq; } ;
struct TYPE_2__ {scalar_t__ (* irq_deliver ) (struct kvm_vcpu*,unsigned int,int) ;scalar_t__ (* irq_clear ) (struct kvm_vcpu*,unsigned int,int) ;} ;

/* Variables and functions */
 int BITS_PER_BYTE ; 
 int CAUSEB_EXCCODE ; 
 int CAUSEF_BD ; 
 int /*<<< orphan*/  CAUSEF_EXCCODE ; 
 int CAUSEF_IV ; 
 int C_IRQ0 ; 
 int C_IRQ1 ; 
 int C_IRQ2 ; 
 int C_IRQ5 ; 
 int C_TI ; 
 int EXCCODE_INT ; 
 int IE_IRQ0 ; 
 int IE_IRQ1 ; 
 int IE_IRQ2 ; 
 int IE_IRQ5 ; 
 int /*<<< orphan*/  KVM_MIPS_IRQ_CLEAR_ALL_AT_ONCE ; 
 int /*<<< orphan*/  KVM_MIPS_IRQ_DELIVER_ALL_AT_ONCE ; 
#define  MIPS_EXC_INT_IO 131 
#define  MIPS_EXC_INT_IPI_1 130 
#define  MIPS_EXC_INT_IPI_2 129 
#define  MIPS_EXC_INT_TIMER 128 
 unsigned int MIPS_EXC_MAX ; 
 int ST0_ERL ; 
 int ST0_EXL ; 
 int ST0_IE ; 
 unsigned int __ffs (unsigned long) ; 
 int /*<<< orphan*/  clear_bit (unsigned int,unsigned long*) ; 
 unsigned int find_next_bit (unsigned long*,int,unsigned int) ; 
 int /*<<< orphan*/  kvm_change_c0_guest_cause (struct mips_coproc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kvm_clear_c0_guest_cause (struct mips_coproc*,int) ; 
 int /*<<< orphan*/  kvm_debug (char*,int) ; 
 int /*<<< orphan*/  kvm_err (char*) ; 
 TYPE_1__* kvm_mips_callbacks ; 
 int kvm_mips_guest_exception_base (struct kvm_vcpu*) ; 
 int kvm_read_c0_guest_cause (struct mips_coproc*) ; 
 int kvm_read_c0_guest_status (struct mips_coproc*) ; 
 int /*<<< orphan*/  kvm_set_c0_guest_cause (struct mips_coproc*,int) ; 
 int /*<<< orphan*/  kvm_set_c0_guest_status (struct mips_coproc*,int) ; 
 int /*<<< orphan*/  kvm_write_c0_guest_epc (struct mips_coproc*,int) ; 
 int /*<<< orphan*/  set_bit (unsigned int,unsigned long*) ; 
 scalar_t__ stub1 (struct kvm_vcpu*,unsigned int,int) ; 
 scalar_t__ stub2 (struct kvm_vcpu*,unsigned int,int) ; 
 int test_bit (int,unsigned long*) ; 

void kvm_mips_queue_irq(struct kvm_vcpu *vcpu, unsigned int priority)
{
	set_bit(priority, &vcpu->arch.pending_exceptions);
}

void kvm_mips_dequeue_irq(struct kvm_vcpu *vcpu, unsigned int priority)
{
	clear_bit(priority, &vcpu->arch.pending_exceptions);
}

void kvm_mips_queue_timer_int_cb(struct kvm_vcpu *vcpu)
{
	/*
	 * Cause bits to reflect the pending timer interrupt,
	 * the EXC code will be set when we are actually
	 * delivering the interrupt:
	 */
	kvm_set_c0_guest_cause(vcpu->arch.cop0, (C_IRQ5 | C_TI));

	/* Queue up an INT exception for the core */
	kvm_mips_queue_irq(vcpu, MIPS_EXC_INT_TIMER);

}

void kvm_mips_dequeue_timer_int_cb(struct kvm_vcpu *vcpu)
{
	kvm_clear_c0_guest_cause(vcpu->arch.cop0, (C_IRQ5 | C_TI));
	kvm_mips_dequeue_irq(vcpu, MIPS_EXC_INT_TIMER);
}

void kvm_mips_queue_io_int_cb(struct kvm_vcpu *vcpu,
			      struct kvm_mips_interrupt *irq)
{
	int intr = (int)irq->irq;

	/*
	 * Cause bits to reflect the pending IO interrupt,
	 * the EXC code will be set when we are actually
	 * delivering the interrupt:
	 */
	switch (intr) {
	case 2:
		kvm_set_c0_guest_cause(vcpu->arch.cop0, (C_IRQ0));
		/* Queue up an INT exception for the core */
		kvm_mips_queue_irq(vcpu, MIPS_EXC_INT_IO);
		break;

	case 3:
		kvm_set_c0_guest_cause(vcpu->arch.cop0, (C_IRQ1));
		kvm_mips_queue_irq(vcpu, MIPS_EXC_INT_IPI_1);
		break;

	case 4:
		kvm_set_c0_guest_cause(vcpu->arch.cop0, (C_IRQ2));
		kvm_mips_queue_irq(vcpu, MIPS_EXC_INT_IPI_2);
		break;

	default:
		break;
	}

}

void kvm_mips_dequeue_io_int_cb(struct kvm_vcpu *vcpu,
				struct kvm_mips_interrupt *irq)
{
	int intr = (int)irq->irq;

	switch (intr) {
	case -2:
		kvm_clear_c0_guest_cause(vcpu->arch.cop0, (C_IRQ0));
		kvm_mips_dequeue_irq(vcpu, MIPS_EXC_INT_IO);
		break;

	case -3:
		kvm_clear_c0_guest_cause(vcpu->arch.cop0, (C_IRQ1));
		kvm_mips_dequeue_irq(vcpu, MIPS_EXC_INT_IPI_1);
		break;

	case -4:
		kvm_clear_c0_guest_cause(vcpu->arch.cop0, (C_IRQ2));
		kvm_mips_dequeue_irq(vcpu, MIPS_EXC_INT_IPI_2);
		break;

	default:
		break;
	}

}

int kvm_mips_irq_deliver_cb(struct kvm_vcpu *vcpu, unsigned int priority,
			    u32 cause)
{
	int allowed = 0;
	u32 exccode;

	struct kvm_vcpu_arch *arch = &vcpu->arch;
	struct mips_coproc *cop0 = vcpu->arch.cop0;

	switch (priority) {
	case MIPS_EXC_INT_TIMER:
		if ((kvm_read_c0_guest_status(cop0) & ST0_IE)
		    && (!(kvm_read_c0_guest_status(cop0) & (ST0_EXL | ST0_ERL)))
		    && (kvm_read_c0_guest_status(cop0) & IE_IRQ5)) {
			allowed = 1;
			exccode = EXCCODE_INT;
		}
		break;

	case MIPS_EXC_INT_IO:
		if ((kvm_read_c0_guest_status(cop0) & ST0_IE)
		    && (!(kvm_read_c0_guest_status(cop0) & (ST0_EXL | ST0_ERL)))
		    && (kvm_read_c0_guest_status(cop0) & IE_IRQ0)) {
			allowed = 1;
			exccode = EXCCODE_INT;
		}
		break;

	case MIPS_EXC_INT_IPI_1:
		if ((kvm_read_c0_guest_status(cop0) & ST0_IE)
		    && (!(kvm_read_c0_guest_status(cop0) & (ST0_EXL | ST0_ERL)))
		    && (kvm_read_c0_guest_status(cop0) & IE_IRQ1)) {
			allowed = 1;
			exccode = EXCCODE_INT;
		}
		break;

	case MIPS_EXC_INT_IPI_2:
		if ((kvm_read_c0_guest_status(cop0) & ST0_IE)
		    && (!(kvm_read_c0_guest_status(cop0) & (ST0_EXL | ST0_ERL)))
		    && (kvm_read_c0_guest_status(cop0) & IE_IRQ2)) {
			allowed = 1;
			exccode = EXCCODE_INT;
		}
		break;

	default:
		break;
	}

	/* Are we allowed to deliver the interrupt ??? */
	if (allowed) {
		if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
			/* save old pc */
			kvm_write_c0_guest_epc(cop0, arch->pc);
			kvm_set_c0_guest_status(cop0, ST0_EXL);

			if (cause & CAUSEF_BD)
				kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
			else
				kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);

			kvm_debug("Delivering INT @ pc %#lx\n", arch->pc);

		} else
			kvm_err("Trying to deliver interrupt when EXL is already set\n");

		kvm_change_c0_guest_cause(cop0, CAUSEF_EXCCODE,
					  (exccode << CAUSEB_EXCCODE));

		/* XXXSL Set PC to the interrupt exception entry point */
		arch->pc = kvm_mips_guest_exception_base(vcpu);
		if (kvm_read_c0_guest_cause(cop0) & CAUSEF_IV)
			arch->pc += 0x200;
		else
			arch->pc += 0x180;

		clear_bit(priority, &vcpu->arch.pending_exceptions);
	}

	return allowed;
}

int kvm_mips_irq_clear_cb(struct kvm_vcpu *vcpu, unsigned int priority,
			  u32 cause)
{
	return 1;
}

void kvm_mips_deliver_interrupts(struct kvm_vcpu *vcpu, u32 cause)
{
	unsigned long *pending = &vcpu->arch.pending_exceptions;
	unsigned long *pending_clr = &vcpu->arch.pending_exceptions_clr;
	unsigned int priority;

	if (!(*pending) && !(*pending_clr))
		return;

	priority = __ffs(*pending_clr);
	while (priority <= MIPS_EXC_MAX) {
		if (kvm_mips_callbacks->irq_clear(vcpu, priority, cause)) {
			if (!KVM_MIPS_IRQ_CLEAR_ALL_AT_ONCE)
				break;
		}

		priority = find_next_bit(pending_clr,
					 BITS_PER_BYTE * sizeof(*pending_clr),
					 priority + 1);
	}

	priority = __ffs(*pending);
	while (priority <= MIPS_EXC_MAX) {
		if (kvm_mips_callbacks->irq_deliver(vcpu, priority, cause)) {
			if (!KVM_MIPS_IRQ_DELIVER_ALL_AT_ONCE)
				break;
		}

		priority = find_next_bit(pending,
					 BITS_PER_BYTE * sizeof(*pending),
					 priority + 1);
	}

}

int kvm_mips_pending_timer(struct kvm_vcpu *vcpu)
{
	return test_bit(MIPS_EXC_INT_TIMER, &vcpu->arch.pending_exceptions);
}


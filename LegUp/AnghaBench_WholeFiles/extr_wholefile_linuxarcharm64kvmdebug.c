#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u64 ;
struct TYPE_7__ {int /*<<< orphan*/ * dbg_wvr; int /*<<< orphan*/ * dbg_wcr; int /*<<< orphan*/ * dbg_bvr; int /*<<< orphan*/ * dbg_bcr; } ;
struct TYPE_6__ {unsigned long mdscr_el1; } ;
struct TYPE_8__ {int flags; int mdcr_el2; TYPE_2__* debug_ptr; TYPE_2__ vcpu_debug_state; TYPE_2__ external_debug_state; TYPE_1__ guest_debug_preserved; } ;
struct kvm_vcpu {int guest_debug; TYPE_3__ arch; } ;
struct TYPE_9__ {int hsr; } ;
struct TYPE_10__ {TYPE_4__ arch; } ;
struct kvm_run {TYPE_5__ debug; int /*<<< orphan*/  exit_reason; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 unsigned long DBG_MDSCR_KDE ; 
 unsigned long DBG_MDSCR_MDE ; 
 unsigned long DBG_MDSCR_SS ; 
 unsigned long DBG_SPSR_SS ; 
 int ESR_ELx_EC_SHIFT ; 
 int ESR_ELx_EC_SOFTSTP_LOW ; 
 int KVM_ARM64_DEBUG_DIRTY ; 
 int /*<<< orphan*/  KVM_EXIT_DEBUG ; 
 int KVM_GUESTDBG_SINGLESTEP ; 
 int KVM_GUESTDBG_USE_HW ; 
 int MDCR_EL2_HPMN_MASK ; 
 int MDCR_EL2_TDA ; 
 int MDCR_EL2_TDE ; 
 int MDCR_EL2_TDOSA ; 
 int MDCR_EL2_TDRA ; 
 int MDCR_EL2_TPM ; 
 int MDCR_EL2_TPMCR ; 
 int MDCR_EL2_TPMS ; 
 int /*<<< orphan*/  MDSCR_EL1 ; 
 int /*<<< orphan*/  __kvm_get_mdcr_el2 ; 
 int __this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __this_cpu_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_num_brps () ; 
 int /*<<< orphan*/  get_num_wrps () ; 
 int /*<<< orphan*/  kvm_call_hyp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdcr_el2 ; 
 int /*<<< orphan*/  trace_kvm_arm_clear_debug (int) ; 
 int /*<<< orphan*/  trace_kvm_arm_set_dreg32 (char*,unsigned long) ; 
 int /*<<< orphan*/  trace_kvm_arm_set_regset (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_kvm_arm_setup_debug (struct kvm_vcpu*,int) ; 
 unsigned long* vcpu_cpsr (struct kvm_vcpu*) ; 
 unsigned long vcpu_read_sys_reg (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vcpu_write_sys_reg (struct kvm_vcpu*,unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void save_guest_debug_regs(struct kvm_vcpu *vcpu)
{
	u64 val = vcpu_read_sys_reg(vcpu, MDSCR_EL1);

	vcpu->arch.guest_debug_preserved.mdscr_el1 = val;

	trace_kvm_arm_set_dreg32("Saved MDSCR_EL1",
				vcpu->arch.guest_debug_preserved.mdscr_el1);
}

__attribute__((used)) static void restore_guest_debug_regs(struct kvm_vcpu *vcpu)
{
	u64 val = vcpu->arch.guest_debug_preserved.mdscr_el1;

	vcpu_write_sys_reg(vcpu, val, MDSCR_EL1);

	trace_kvm_arm_set_dreg32("Restored MDSCR_EL1",
				vcpu_read_sys_reg(vcpu, MDSCR_EL1));
}

void kvm_arm_init_debug(void)
{
	__this_cpu_write(mdcr_el2, kvm_call_hyp(__kvm_get_mdcr_el2));
}

void kvm_arm_reset_debug_ptr(struct kvm_vcpu *vcpu)
{
	vcpu->arch.debug_ptr = &vcpu->arch.vcpu_debug_state;
}

void kvm_arm_setup_debug(struct kvm_vcpu *vcpu)
{
	bool trap_debug = !(vcpu->arch.flags & KVM_ARM64_DEBUG_DIRTY);
	unsigned long mdscr;

	trace_kvm_arm_setup_debug(vcpu, vcpu->guest_debug);

	/*
	 * This also clears MDCR_EL2_E2PB_MASK to disable guest access
	 * to the profiling buffer.
	 */
	vcpu->arch.mdcr_el2 = __this_cpu_read(mdcr_el2) & MDCR_EL2_HPMN_MASK;
	vcpu->arch.mdcr_el2 |= (MDCR_EL2_TPM |
				MDCR_EL2_TPMS |
				MDCR_EL2_TPMCR |
				MDCR_EL2_TDRA |
				MDCR_EL2_TDOSA);

	/* Is Guest debugging in effect? */
	if (vcpu->guest_debug) {
		/* Route all software debug exceptions to EL2 */
		vcpu->arch.mdcr_el2 |= MDCR_EL2_TDE;

		/* Save guest debug state */
		save_guest_debug_regs(vcpu);

		/*
		 * Single Step (ARM ARM D2.12.3 The software step state
		 * machine)
		 *
		 * If we are doing Single Step we need to manipulate
		 * the guest's MDSCR_EL1.SS and PSTATE.SS. Once the
		 * step has occurred the hypervisor will trap the
		 * debug exception and we return to userspace.
		 *
		 * If the guest attempts to single step its userspace
		 * we would have to deal with a trapped exception
		 * while in the guest kernel. Because this would be
		 * hard to unwind we suppress the guest's ability to
		 * do so by masking MDSCR_EL.SS.
		 *
		 * This confuses guest debuggers which use
		 * single-step behind the scenes but everything
		 * returns to normal once the host is no longer
		 * debugging the system.
		 */
		if (vcpu->guest_debug & KVM_GUESTDBG_SINGLESTEP) {
			*vcpu_cpsr(vcpu) |=  DBG_SPSR_SS;
			mdscr = vcpu_read_sys_reg(vcpu, MDSCR_EL1);
			mdscr |= DBG_MDSCR_SS;
			vcpu_write_sys_reg(vcpu, mdscr, MDSCR_EL1);
		} else {
			mdscr = vcpu_read_sys_reg(vcpu, MDSCR_EL1);
			mdscr &= ~DBG_MDSCR_SS;
			vcpu_write_sys_reg(vcpu, mdscr, MDSCR_EL1);
		}

		trace_kvm_arm_set_dreg32("SPSR_EL2", *vcpu_cpsr(vcpu));

		/*
		 * HW Breakpoints and watchpoints
		 *
		 * We simply switch the debug_ptr to point to our new
		 * external_debug_state which has been populated by the
		 * debug ioctl. The existing KVM_ARM64_DEBUG_DIRTY
		 * mechanism ensures the registers are updated on the
		 * world switch.
		 */
		if (vcpu->guest_debug & KVM_GUESTDBG_USE_HW) {
			/* Enable breakpoints/watchpoints */
			mdscr = vcpu_read_sys_reg(vcpu, MDSCR_EL1);
			mdscr |= DBG_MDSCR_MDE;
			vcpu_write_sys_reg(vcpu, mdscr, MDSCR_EL1);

			vcpu->arch.debug_ptr = &vcpu->arch.external_debug_state;
			vcpu->arch.flags |= KVM_ARM64_DEBUG_DIRTY;
			trap_debug = true;

			trace_kvm_arm_set_regset("BKPTS", get_num_brps(),
						&vcpu->arch.debug_ptr->dbg_bcr[0],
						&vcpu->arch.debug_ptr->dbg_bvr[0]);

			trace_kvm_arm_set_regset("WAPTS", get_num_wrps(),
						&vcpu->arch.debug_ptr->dbg_wcr[0],
						&vcpu->arch.debug_ptr->dbg_wvr[0]);
		}
	}

	BUG_ON(!vcpu->guest_debug &&
		vcpu->arch.debug_ptr != &vcpu->arch.vcpu_debug_state);

	/* Trap debug register access */
	if (trap_debug)
		vcpu->arch.mdcr_el2 |= MDCR_EL2_TDA;

	/* If KDE or MDE are set, perform a full save/restore cycle. */
	if (vcpu_read_sys_reg(vcpu, MDSCR_EL1) & (DBG_MDSCR_KDE | DBG_MDSCR_MDE))
		vcpu->arch.flags |= KVM_ARM64_DEBUG_DIRTY;

	trace_kvm_arm_set_dreg32("MDCR_EL2", vcpu->arch.mdcr_el2);
	trace_kvm_arm_set_dreg32("MDSCR_EL1", vcpu_read_sys_reg(vcpu, MDSCR_EL1));
}

void kvm_arm_clear_debug(struct kvm_vcpu *vcpu)
{
	trace_kvm_arm_clear_debug(vcpu->guest_debug);

	if (vcpu->guest_debug) {
		restore_guest_debug_regs(vcpu);

		/*
		 * If we were using HW debug we need to restore the
		 * debug_ptr to the guest debug state.
		 */
		if (vcpu->guest_debug & KVM_GUESTDBG_USE_HW) {
			kvm_arm_reset_debug_ptr(vcpu);

			trace_kvm_arm_set_regset("BKPTS", get_num_brps(),
						&vcpu->arch.debug_ptr->dbg_bcr[0],
						&vcpu->arch.debug_ptr->dbg_bvr[0]);

			trace_kvm_arm_set_regset("WAPTS", get_num_wrps(),
						&vcpu->arch.debug_ptr->dbg_wcr[0],
						&vcpu->arch.debug_ptr->dbg_wvr[0]);
		}
	}
}

bool kvm_arm_handle_step_debug(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
	if (vcpu->guest_debug & KVM_GUESTDBG_SINGLESTEP) {
		run->exit_reason = KVM_EXIT_DEBUG;
		run->debug.arch.hsr = ESR_ELx_EC_SOFTSTP_LOW << ESR_ELx_EC_SHIFT;
		return true;
	}
	return false;
}


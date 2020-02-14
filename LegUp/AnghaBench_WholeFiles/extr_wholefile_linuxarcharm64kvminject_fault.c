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
typedef  int u64 ;
typedef  unsigned long u32 ;
struct kvm_vcpu {int dummy; } ;
typedef  enum exception_type { ____Placeholder_exception_type } exception_type ;

/* Variables and functions */
 int CURRENT_EL_SP_EL0_VECTOR ; 
 int CURRENT_EL_SP_ELx_VECTOR ; 
 int /*<<< orphan*/  ESR_EL1 ; 
 unsigned long ESR_ELx_EC_DABT_LOW ; 
 unsigned long ESR_ELx_EC_IABT_CUR ; 
 unsigned long ESR_ELx_EC_IABT_LOW ; 
 unsigned long ESR_ELx_EC_SHIFT ; 
 unsigned long ESR_ELx_EC_UNKNOWN ; 
 unsigned long ESR_ELx_FSC_EXTABT ; 
 unsigned long ESR_ELx_IL ; 
 int ESR_ELx_ISS_MASK ; 
 int ESR_ELx_ISV ; 
 int /*<<< orphan*/  FAR_EL1 ; 
 int /*<<< orphan*/  HCR_VSE ; 
 int LOWER_EL_AArch32_VECTOR ; 
 int LOWER_EL_AArch64_VECTOR ; 
 int PSR_MODE32_BIT ; 
#define  PSR_MODE_EL0t 130 
#define  PSR_MODE_EL1h 129 
#define  PSR_MODE_EL1t 128 
 int PSR_MODE_MASK ; 
 int PSTATE_FAULT_BITS_64 ; 
 int /*<<< orphan*/  VBAR_EL1 ; 
 int except_type_sync ; 
 int /*<<< orphan*/  kvm_inject_dabt32 (struct kvm_vcpu*,unsigned long) ; 
 int /*<<< orphan*/  kvm_inject_pabt32 (struct kvm_vcpu*,unsigned long) ; 
 int /*<<< orphan*/  kvm_inject_undef32 (struct kvm_vcpu*) ; 
 scalar_t__ kvm_vcpu_trap_il_is32bit (struct kvm_vcpu*) ; 
 int* vcpu_cpsr (struct kvm_vcpu*) ; 
 scalar_t__ vcpu_el1_is_32bit (struct kvm_vcpu*) ; 
 int /*<<< orphan*/ * vcpu_hcr (struct kvm_vcpu*) ; 
 int vcpu_mode_is_32bit (struct kvm_vcpu*) ; 
 int* vcpu_pc (struct kvm_vcpu*) ; 
 int vcpu_read_sys_reg (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vcpu_set_vsesr (struct kvm_vcpu*,int) ; 
 int /*<<< orphan*/  vcpu_write_elr_el1 (struct kvm_vcpu*,int) ; 
 int /*<<< orphan*/  vcpu_write_spsr (struct kvm_vcpu*,unsigned long) ; 
 int /*<<< orphan*/  vcpu_write_sys_reg (struct kvm_vcpu*,unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u64 get_except_vector(struct kvm_vcpu *vcpu, enum exception_type type)
{
	u64 exc_offset;

	switch (*vcpu_cpsr(vcpu) & (PSR_MODE_MASK | PSR_MODE32_BIT)) {
	case PSR_MODE_EL1t:
		exc_offset = CURRENT_EL_SP_EL0_VECTOR;
		break;
	case PSR_MODE_EL1h:
		exc_offset = CURRENT_EL_SP_ELx_VECTOR;
		break;
	case PSR_MODE_EL0t:
		exc_offset = LOWER_EL_AArch64_VECTOR;
		break;
	default:
		exc_offset = LOWER_EL_AArch32_VECTOR;
	}

	return vcpu_read_sys_reg(vcpu, VBAR_EL1) + exc_offset + type;
}

__attribute__((used)) static void inject_abt64(struct kvm_vcpu *vcpu, bool is_iabt, unsigned long addr)
{
	unsigned long cpsr = *vcpu_cpsr(vcpu);
	bool is_aarch32 = vcpu_mode_is_32bit(vcpu);
	u32 esr = 0;

	vcpu_write_elr_el1(vcpu, *vcpu_pc(vcpu));
	*vcpu_pc(vcpu) = get_except_vector(vcpu, except_type_sync);

	*vcpu_cpsr(vcpu) = PSTATE_FAULT_BITS_64;
	vcpu_write_spsr(vcpu, cpsr);

	vcpu_write_sys_reg(vcpu, addr, FAR_EL1);

	/*
	 * Build an {i,d}abort, depending on the level and the
	 * instruction set. Report an external synchronous abort.
	 */
	if (kvm_vcpu_trap_il_is32bit(vcpu))
		esr |= ESR_ELx_IL;

	/*
	 * Here, the guest runs in AArch64 mode when in EL1. If we get
	 * an AArch32 fault, it means we managed to trap an EL0 fault.
	 */
	if (is_aarch32 || (cpsr & PSR_MODE_MASK) == PSR_MODE_EL0t)
		esr |= (ESR_ELx_EC_IABT_LOW << ESR_ELx_EC_SHIFT);
	else
		esr |= (ESR_ELx_EC_IABT_CUR << ESR_ELx_EC_SHIFT);

	if (!is_iabt)
		esr |= ESR_ELx_EC_DABT_LOW << ESR_ELx_EC_SHIFT;

	vcpu_write_sys_reg(vcpu, esr | ESR_ELx_FSC_EXTABT, ESR_EL1);
}

__attribute__((used)) static void inject_undef64(struct kvm_vcpu *vcpu)
{
	unsigned long cpsr = *vcpu_cpsr(vcpu);
	u32 esr = (ESR_ELx_EC_UNKNOWN << ESR_ELx_EC_SHIFT);

	vcpu_write_elr_el1(vcpu, *vcpu_pc(vcpu));
	*vcpu_pc(vcpu) = get_except_vector(vcpu, except_type_sync);

	*vcpu_cpsr(vcpu) = PSTATE_FAULT_BITS_64;
	vcpu_write_spsr(vcpu, cpsr);

	/*
	 * Build an unknown exception, depending on the instruction
	 * set.
	 */
	if (kvm_vcpu_trap_il_is32bit(vcpu))
		esr |= ESR_ELx_IL;

	vcpu_write_sys_reg(vcpu, esr, ESR_EL1);
}

void kvm_inject_dabt(struct kvm_vcpu *vcpu, unsigned long addr)
{
	if (vcpu_el1_is_32bit(vcpu))
		kvm_inject_dabt32(vcpu, addr);
	else
		inject_abt64(vcpu, false, addr);
}

void kvm_inject_pabt(struct kvm_vcpu *vcpu, unsigned long addr)
{
	if (vcpu_el1_is_32bit(vcpu))
		kvm_inject_pabt32(vcpu, addr);
	else
		inject_abt64(vcpu, true, addr);
}

void kvm_inject_undefined(struct kvm_vcpu *vcpu)
{
	if (vcpu_el1_is_32bit(vcpu))
		kvm_inject_undef32(vcpu);
	else
		inject_undef64(vcpu);
}

void kvm_set_sei_esr(struct kvm_vcpu *vcpu, u64 esr)
{
	vcpu_set_vsesr(vcpu, esr & ESR_ELx_ISS_MASK);
	*vcpu_hcr(vcpu) |= HCR_VSE;
}

void kvm_inject_vabt(struct kvm_vcpu *vcpu)
{
	kvm_set_sei_esr(vcpu, ESR_ELx_ISV);
}


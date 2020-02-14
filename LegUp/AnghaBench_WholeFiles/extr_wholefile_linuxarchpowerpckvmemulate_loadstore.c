#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_8__ {int /*<<< orphan*/  ccr; int /*<<< orphan*/  msr; } ;
struct TYPE_7__ {TYPE_4__ regs; int /*<<< orphan*/  cr; TYPE_2__* shared; scalar_t__ mmio_host_swabbed; scalar_t__ mmio_vmx_offset; scalar_t__ mmio_vmx_copy_nums; scalar_t__ mmio_sign_extend; scalar_t__ mmio_sp64_extend; int /*<<< orphan*/  mmio_copy_type; scalar_t__ mmio_vsx_offset; scalar_t__ mmio_vsx_copy_nums; } ;
struct TYPE_5__ {int /*<<< orphan*/  gdbell_exits; int /*<<< orphan*/  dbell_exits; int /*<<< orphan*/  signal_exits; int /*<<< orphan*/  itlb_virt_miss_exits; int /*<<< orphan*/  itlb_real_miss_exits; int /*<<< orphan*/  mmio_exits; int /*<<< orphan*/  dtlb_virt_miss_exits; int /*<<< orphan*/  dtlb_real_miss_exits; int /*<<< orphan*/  syscall_exits; int /*<<< orphan*/  isi_exits; int /*<<< orphan*/  dsi_exits; int /*<<< orphan*/  emulated_inst_exits; int /*<<< orphan*/  dec_exits; int /*<<< orphan*/  ext_intr_exits; } ;
struct kvm_vcpu {TYPE_3__ arch; struct kvm_run* run; TYPE_1__ stat; } ;
struct kvm_run {int dummy; } ;
struct instruction_op {int type; int /*<<< orphan*/  ea; int /*<<< orphan*/  update_reg; int /*<<< orphan*/  val; int /*<<< orphan*/  reg; } ;
typedef  enum emulation_result { ____Placeholder_emulation_result } emulation_result ;
struct TYPE_6__ {int /*<<< orphan*/  msr; } ;

/* Variables and functions */
 int BYTEREV ; 
#define  CACHEOP 144 
#define  DBELL_EXITS 143 
#define  DEC_EXITS 142 
#define  DSI_EXITS 141 
#define  DTLB_REAL_MISS_EXITS 140 
#define  DTLB_VIRT_MISS_EXITS 139 
#define  EMULATED_INST_EXITS 138 
 int EMULATE_DONE ; 
 int EMULATE_FAIL ; 
#define  EXT_INTR_EXITS 137 
#define  GDBELL_EXITS 136 
 int GETSIZE (int) ; 
 int INSTR_TYPE_MASK ; 
 int /*<<< orphan*/  INST_GENERIC ; 
#define  ISI_EXITS 135 
#define  ITLB_REAL_MISS_EXITS 134 
#define  ITLB_VIRT_MISS_EXITS 133 
 int /*<<< orphan*/  KVMPPC_VSX_COPY_NONE ; 
#define  LOAD 132 
#define  MMIO_EXITS 131 
#define  SIGNAL_EXITS 130 
 int SIGNEXT ; 
#define  STORE 129 
#define  SYSCALL_EXITS 128 
 int UPDATE ; 
 scalar_t__ analyse_instr (struct instruction_op*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int get_ra (int /*<<< orphan*/ ) ; 
 int get_rs (int /*<<< orphan*/ ) ; 
 int get_rt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvmppc_core_queue_program (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int kvmppc_get_last_inst (struct kvm_vcpu*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ kvmppc_get_pc (struct kvm_vcpu*) ; 
 int kvmppc_handle_load (struct kvm_run*,struct kvm_vcpu*,int /*<<< orphan*/ ,int,int) ; 
 int kvmppc_handle_loads (struct kvm_run*,struct kvm_vcpu*,int /*<<< orphan*/ ,int,int) ; 
 int kvmppc_handle_store (struct kvm_run*,struct kvm_vcpu*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  kvmppc_set_gpr (struct kvm_vcpu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvmppc_set_pc (struct kvm_vcpu*,scalar_t__) ; 
 int /*<<< orphan*/  trace_kvm_ppc_instr (int /*<<< orphan*/ ,scalar_t__,int) ; 

__attribute__((used)) static inline void kvmppc_init_timing_stats(struct kvm_vcpu *vcpu) {}

__attribute__((used)) static inline void kvmppc_update_timing_stats(struct kvm_vcpu *vcpu) {}

__attribute__((used)) static inline void kvmppc_create_vcpu_debugfs(struct kvm_vcpu *vcpu,
						unsigned int id) {}

__attribute__((used)) static inline void kvmppc_remove_vcpu_debugfs(struct kvm_vcpu *vcpu) {}

__attribute__((used)) static inline void kvmppc_set_exit_type(struct kvm_vcpu *vcpu, int type) {}

__attribute__((used)) static inline void kvmppc_account_exit_stat(struct kvm_vcpu *vcpu, int type)
{
	/* type has to be known at build time for optimization */

	/* The BUILD_BUG_ON below breaks in funny ways, commented out
	 * for now ... -BenH
	BUILD_BUG_ON(!__builtin_constant_p(type));
	*/
	switch (type) {
	case EXT_INTR_EXITS:
		vcpu->stat.ext_intr_exits++;
		break;
	case DEC_EXITS:
		vcpu->stat.dec_exits++;
		break;
	case EMULATED_INST_EXITS:
		vcpu->stat.emulated_inst_exits++;
		break;
	case DSI_EXITS:
		vcpu->stat.dsi_exits++;
		break;
	case ISI_EXITS:
		vcpu->stat.isi_exits++;
		break;
	case SYSCALL_EXITS:
		vcpu->stat.syscall_exits++;
		break;
	case DTLB_REAL_MISS_EXITS:
		vcpu->stat.dtlb_real_miss_exits++;
		break;
	case DTLB_VIRT_MISS_EXITS:
		vcpu->stat.dtlb_virt_miss_exits++;
		break;
	case MMIO_EXITS:
		vcpu->stat.mmio_exits++;
		break;
	case ITLB_REAL_MISS_EXITS:
		vcpu->stat.itlb_real_miss_exits++;
		break;
	case ITLB_VIRT_MISS_EXITS:
		vcpu->stat.itlb_virt_miss_exits++;
		break;
	case SIGNAL_EXITS:
		vcpu->stat.signal_exits++;
		break;
	case DBELL_EXITS:
		vcpu->stat.dbell_exits++;
		break;
	case GDBELL_EXITS:
		vcpu->stat.gdbell_exits++;
		break;
	}
}

__attribute__((used)) static inline void kvmppc_account_exit(struct kvm_vcpu *vcpu, int type)
{
	kvmppc_set_exit_type(vcpu, type);
	kvmppc_account_exit_stat(vcpu, type);
}

int kvmppc_emulate_loadstore(struct kvm_vcpu *vcpu)
{
	struct kvm_run *run = vcpu->run;
	u32 inst;
	int ra, rs, rt;
	enum emulation_result emulated = EMULATE_FAIL;
	int advance = 1;
	struct instruction_op op;

	/* this default type might be overwritten by subcategories */
	kvmppc_set_exit_type(vcpu, EMULATED_INST_EXITS);

	emulated = kvmppc_get_last_inst(vcpu, INST_GENERIC, &inst);
	if (emulated != EMULATE_DONE)
		return emulated;

	ra = get_ra(inst);
	rs = get_rs(inst);
	rt = get_rt(inst);

	/*
	 * if mmio_vsx_tx_sx_enabled == 0, copy data between
	 * VSR[0..31] and memory
	 * if mmio_vsx_tx_sx_enabled == 1, copy data between
	 * VSR[32..63] and memory
	 */
	vcpu->arch.mmio_vsx_copy_nums = 0;
	vcpu->arch.mmio_vsx_offset = 0;
	vcpu->arch.mmio_copy_type = KVMPPC_VSX_COPY_NONE;
	vcpu->arch.mmio_sp64_extend = 0;
	vcpu->arch.mmio_sign_extend = 0;
	vcpu->arch.mmio_vmx_copy_nums = 0;
	vcpu->arch.mmio_vmx_offset = 0;
	vcpu->arch.mmio_host_swabbed = 0;

	emulated = EMULATE_FAIL;
	vcpu->arch.regs.msr = vcpu->arch.shared->msr;
	vcpu->arch.regs.ccr = vcpu->arch.cr;
	if (analyse_instr(&op, &vcpu->arch.regs, inst) == 0) {
		int type = op.type & INSTR_TYPE_MASK;
		int size = GETSIZE(op.type);

		switch (type) {
		case LOAD:  {
			int instr_byte_swap = op.type & BYTEREV;

			if (op.type & SIGNEXT)
				emulated = kvmppc_handle_loads(run, vcpu,
						op.reg, size, !instr_byte_swap);
			else
				emulated = kvmppc_handle_load(run, vcpu,
						op.reg, size, !instr_byte_swap);

			if ((op.type & UPDATE) && (emulated != EMULATE_FAIL))
				kvmppc_set_gpr(vcpu, op.update_reg, op.ea);

			break;
		}
#ifdef CONFIG_PPC_FPU
		case LOAD_FP:
			if (kvmppc_check_fp_disabled(vcpu))
				return EMULATE_DONE;

			if (op.type & FPCONV)
				vcpu->arch.mmio_sp64_extend = 1;

			if (op.type & SIGNEXT)
				emulated = kvmppc_handle_loads(run, vcpu,
					     KVM_MMIO_REG_FPR|op.reg, size, 1);
			else
				emulated = kvmppc_handle_load(run, vcpu,
					     KVM_MMIO_REG_FPR|op.reg, size, 1);

			if ((op.type & UPDATE) && (emulated != EMULATE_FAIL))
				kvmppc_set_gpr(vcpu, op.update_reg, op.ea);

			break;
#endif
#ifdef CONFIG_ALTIVEC
		case LOAD_VMX:
			if (kvmppc_check_altivec_disabled(vcpu))
				return EMULATE_DONE;

			/* Hardware enforces alignment of VMX accesses */
			vcpu->arch.vaddr_accessed &= ~((unsigned long)size - 1);
			vcpu->arch.paddr_accessed &= ~((unsigned long)size - 1);

			if (size == 16) { /* lvx */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_DWORD;
			} else if (size == 4) { /* lvewx  */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_WORD;
			} else if (size == 2) { /* lvehx  */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_HWORD;
			} else if (size == 1) { /* lvebx  */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_BYTE;
			} else
				break;

			vcpu->arch.mmio_vmx_offset =
				(vcpu->arch.vaddr_accessed & 0xf)/size;

			if (size == 16) {
				vcpu->arch.mmio_vmx_copy_nums = 2;
				emulated = kvmppc_handle_vmx_load(run,
						vcpu, KVM_MMIO_REG_VMX|op.reg,
						8, 1);
			} else {
				vcpu->arch.mmio_vmx_copy_nums = 1;
				emulated = kvmppc_handle_vmx_load(run, vcpu,
						KVM_MMIO_REG_VMX|op.reg,
						size, 1);
			}
			break;
#endif
#ifdef CONFIG_VSX
		case LOAD_VSX: {
			int io_size_each;

			if (op.vsx_flags & VSX_CHECK_VEC) {
				if (kvmppc_check_altivec_disabled(vcpu))
					return EMULATE_DONE;
			} else {
				if (kvmppc_check_vsx_disabled(vcpu))
					return EMULATE_DONE;
			}

			if (op.vsx_flags & VSX_FPCONV)
				vcpu->arch.mmio_sp64_extend = 1;

			if (op.element_size == 8)  {
				if (op.vsx_flags & VSX_SPLAT)
					vcpu->arch.mmio_copy_type =
						KVMPPC_VSX_COPY_DWORD_LOAD_DUMP;
				else
					vcpu->arch.mmio_copy_type =
						KVMPPC_VSX_COPY_DWORD;
			} else if (op.element_size == 4) {
				if (op.vsx_flags & VSX_SPLAT)
					vcpu->arch.mmio_copy_type =
						KVMPPC_VSX_COPY_WORD_LOAD_DUMP;
				else
					vcpu->arch.mmio_copy_type =
						KVMPPC_VSX_COPY_WORD;
			} else
				break;

			if (size < op.element_size) {
				/* precision convert case: lxsspx, etc */
				vcpu->arch.mmio_vsx_copy_nums = 1;
				io_size_each = size;
			} else { /* lxvw4x, lxvd2x, etc */
				vcpu->arch.mmio_vsx_copy_nums =
					size/op.element_size;
				io_size_each = op.element_size;
			}

			emulated = kvmppc_handle_vsx_load(run, vcpu,
					KVM_MMIO_REG_VSX|op.reg, io_size_each,
					1, op.type & SIGNEXT);
			break;
		}
#endif
		case STORE:
			/* if need byte reverse, op.val has been reversed by
			 * analyse_instr().
			 */
			emulated = kvmppc_handle_store(run, vcpu, op.val,
					size, 1);

			if ((op.type & UPDATE) && (emulated != EMULATE_FAIL))
				kvmppc_set_gpr(vcpu, op.update_reg, op.ea);

			break;
#ifdef CONFIG_PPC_FPU
		case STORE_FP:
			if (kvmppc_check_fp_disabled(vcpu))
				return EMULATE_DONE;

			/* The FP registers need to be flushed so that
			 * kvmppc_handle_store() can read actual FP vals
			 * from vcpu->arch.
			 */
			if (vcpu->kvm->arch.kvm_ops->giveup_ext)
				vcpu->kvm->arch.kvm_ops->giveup_ext(vcpu,
						MSR_FP);

			if (op.type & FPCONV)
				vcpu->arch.mmio_sp64_extend = 1;

			emulated = kvmppc_handle_store(run, vcpu,
					VCPU_FPR(vcpu, op.reg), size, 1);

			if ((op.type & UPDATE) && (emulated != EMULATE_FAIL))
				kvmppc_set_gpr(vcpu, op.update_reg, op.ea);

			break;
#endif
#ifdef CONFIG_ALTIVEC
		case STORE_VMX:
			if (kvmppc_check_altivec_disabled(vcpu))
				return EMULATE_DONE;

			/* Hardware enforces alignment of VMX accesses. */
			vcpu->arch.vaddr_accessed &= ~((unsigned long)size - 1);
			vcpu->arch.paddr_accessed &= ~((unsigned long)size - 1);

			if (vcpu->kvm->arch.kvm_ops->giveup_ext)
				vcpu->kvm->arch.kvm_ops->giveup_ext(vcpu,
						MSR_VEC);
			if (size == 16) { /* stvx */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_DWORD;
			} else if (size == 4) { /* stvewx  */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_WORD;
			} else if (size == 2) { /* stvehx  */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_HWORD;
			} else if (size == 1) { /* stvebx  */
				vcpu->arch.mmio_copy_type =
						KVMPPC_VMX_COPY_BYTE;
			} else
				break;

			vcpu->arch.mmio_vmx_offset =
				(vcpu->arch.vaddr_accessed & 0xf)/size;

			if (size == 16) {
				vcpu->arch.mmio_vmx_copy_nums = 2;
				emulated = kvmppc_handle_vmx_store(run,
						vcpu, op.reg, 8, 1);
			} else {
				vcpu->arch.mmio_vmx_copy_nums = 1;
				emulated = kvmppc_handle_vmx_store(run,
						vcpu, op.reg, size, 1);
			}

			break;
#endif
#ifdef CONFIG_VSX
		case STORE_VSX: {
			int io_size_each;

			if (op.vsx_flags & VSX_CHECK_VEC) {
				if (kvmppc_check_altivec_disabled(vcpu))
					return EMULATE_DONE;
			} else {
				if (kvmppc_check_vsx_disabled(vcpu))
					return EMULATE_DONE;
			}

			if (vcpu->kvm->arch.kvm_ops->giveup_ext)
				vcpu->kvm->arch.kvm_ops->giveup_ext(vcpu,
						MSR_VSX);

			if (op.vsx_flags & VSX_FPCONV)
				vcpu->arch.mmio_sp64_extend = 1;

			if (op.element_size == 8)
				vcpu->arch.mmio_copy_type =
						KVMPPC_VSX_COPY_DWORD;
			else if (op.element_size == 4)
				vcpu->arch.mmio_copy_type =
						KVMPPC_VSX_COPY_WORD;
			else
				break;

			if (size < op.element_size) {
				/* precise conversion case, like stxsspx */
				vcpu->arch.mmio_vsx_copy_nums = 1;
				io_size_each = size;
			} else { /* stxvw4x, stxvd2x, etc */
				vcpu->arch.mmio_vsx_copy_nums =
						size/op.element_size;
				io_size_each = op.element_size;
			}

			emulated = kvmppc_handle_vsx_store(run, vcpu,
					op.reg, io_size_each, 1);
			break;
		}
#endif
		case CACHEOP:
			/* Do nothing. The guest is performing dcbi because
			 * hardware DMA is not snooped by the dcache, but
			 * emulated DMA either goes through the dcache as
			 * normal writes, or the host kernel has handled dcache
			 * coherence.
			 */
			emulated = EMULATE_DONE;
			break;
		default:
			break;
		}
	}

	if (emulated == EMULATE_FAIL) {
		advance = 0;
		kvmppc_core_queue_program(vcpu, 0);
	}

	trace_kvm_ppc_instr(inst, kvmppc_get_pc(vcpu), emulated);

	/* Advance past emulated instruction. */
	if (advance)
		kvmppc_set_pc(vcpu, kvmppc_get_pc(vcpu) + 4);

	return emulated;
}


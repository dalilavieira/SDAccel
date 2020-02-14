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
typedef  int /*<<< orphan*/  syscalls_ia32 ;
typedef  int /*<<< orphan*/  syscalls_64 ;
struct pt_regs {int dummy; } ;
struct entry_stack {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  code32_start; int /*<<< orphan*/  pref_address; int /*<<< orphan*/  init_size; int /*<<< orphan*/  kernel_alignment; int /*<<< orphan*/  version; int /*<<< orphan*/  hardware_subarch; int /*<<< orphan*/  loadflags; } ;
struct TYPE_7__ {int /*<<< orphan*/  addr_limit; int /*<<< orphan*/  sp; } ;
struct TYPE_6__ {int /*<<< orphan*/  flags; } ;
struct TYPE_5__ {int /*<<< orphan*/  sp1; int /*<<< orphan*/  sp0; int /*<<< orphan*/  ist; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLANK () ; 
 int /*<<< orphan*/  BP_code32_start ; 
 int /*<<< orphan*/  BP_hardware_subarch ; 
 int /*<<< orphan*/  BP_init_size ; 
 int /*<<< orphan*/  BP_kernel_alignment ; 
 int /*<<< orphan*/  BP_loadflags ; 
 int /*<<< orphan*/  BP_pref_address ; 
 int /*<<< orphan*/  BP_scratch ; 
 int /*<<< orphan*/  BP_secure_boot ; 
 int /*<<< orphan*/  BP_version ; 
 int /*<<< orphan*/  CPU_ENTRY_AREA_entry_stack ; 
 int /*<<< orphan*/  CPU_ENTRY_AREA_entry_trampoline ; 
 int /*<<< orphan*/  CPU_ENTRY_AREA_tss ; 
 int /*<<< orphan*/  DEFINE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  IA32_NR_syscalls ; 
 int /*<<< orphan*/  MASK_entry_stack ; 
 int /*<<< orphan*/  NR_syscalls ; 
 int /*<<< orphan*/  OFFSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PTREGS_SIZE ; 
 int /*<<< orphan*/  SIZEOF_entry_stack ; 
 int /*<<< orphan*/  TASK_TI_flags ; 
 int /*<<< orphan*/  TASK_addr_limit ; 
 int /*<<< orphan*/  TASK_threadsp ; 
 int /*<<< orphan*/  TLB_STATE_user_pcid_flush_mask ; 
 int /*<<< orphan*/  TSS_ist ; 
 int /*<<< orphan*/  TSS_sp0 ; 
 int /*<<< orphan*/  TSS_sp1 ; 
 int /*<<< orphan*/  __NR_syscall_compat_max ; 
 int /*<<< orphan*/  __NR_syscall_max ; 
 int /*<<< orphan*/  __crt_ctx ; 
 int /*<<< orphan*/  address ; 
 int /*<<< orphan*/  boot_params ; 
 int /*<<< orphan*/  bp ; 
 int /*<<< orphan*/  bx ; 
 int /*<<< orphan*/  cpu_entry_area ; 
 int /*<<< orphan*/  cr0 ; 
 int /*<<< orphan*/  cr2 ; 
 int /*<<< orphan*/  cr3 ; 
 int /*<<< orphan*/  cr4 ; 
 int /*<<< orphan*/  cr8 ; 
 int /*<<< orphan*/  crypto_tfm ; 
 int /*<<< orphan*/  crypto_tfm_ctx_offset ; 
 int /*<<< orphan*/  cx ; 
 int /*<<< orphan*/  di ; 
 int /*<<< orphan*/  dx ; 
 int /*<<< orphan*/  entry_stack_page ; 
 int /*<<< orphan*/  entry_trampoline ; 
 int /*<<< orphan*/  flags ; 
 int /*<<< orphan*/  gdt_desc ; 
 TYPE_4__ hdr ; 
 int /*<<< orphan*/  next ; 
 int /*<<< orphan*/  orig_address ; 
 int /*<<< orphan*/  pbe ; 
 int /*<<< orphan*/  pbe_address ; 
 int /*<<< orphan*/  pbe_next ; 
 int /*<<< orphan*/  pbe_orig_address ; 
 int /*<<< orphan*/  pt_regs ; 
 int /*<<< orphan*/  pt_regs_bp ; 
 int /*<<< orphan*/  pt_regs_bx ; 
 int /*<<< orphan*/  pt_regs_cx ; 
 int /*<<< orphan*/  pt_regs_di ; 
 int /*<<< orphan*/  pt_regs_dx ; 
 int /*<<< orphan*/  pt_regs_flags ; 
 int /*<<< orphan*/  pt_regs_r10 ; 
 int /*<<< orphan*/  pt_regs_r11 ; 
 int /*<<< orphan*/  pt_regs_r12 ; 
 int /*<<< orphan*/  pt_regs_r13 ; 
 int /*<<< orphan*/  pt_regs_r14 ; 
 int /*<<< orphan*/  pt_regs_r15 ; 
 int /*<<< orphan*/  pt_regs_r8 ; 
 int /*<<< orphan*/  pt_regs_r9 ; 
 int /*<<< orphan*/  pt_regs_si ; 
 int /*<<< orphan*/  pt_regs_sp ; 
 int /*<<< orphan*/  r10 ; 
 int /*<<< orphan*/  r11 ; 
 int /*<<< orphan*/  r12 ; 
 int /*<<< orphan*/  r13 ; 
 int /*<<< orphan*/  r14 ; 
 int /*<<< orphan*/  r15 ; 
 int /*<<< orphan*/  r8 ; 
 int /*<<< orphan*/  r9 ; 
 int /*<<< orphan*/  saved_context ; 
 int /*<<< orphan*/  saved_context_cr0 ; 
 int /*<<< orphan*/  saved_context_cr2 ; 
 int /*<<< orphan*/  saved_context_cr3 ; 
 int /*<<< orphan*/  saved_context_cr4 ; 
 int /*<<< orphan*/  saved_context_cr8 ; 
 int /*<<< orphan*/  saved_context_gdt_desc ; 
 int /*<<< orphan*/  scratch ; 
 int /*<<< orphan*/  secure_boot ; 
 int /*<<< orphan*/  si ; 
 int /*<<< orphan*/  sp ; 
 int /*<<< orphan*/  task_struct ; 
 TYPE_3__ thread ; 
 TYPE_2__ thread_info ; 
 int /*<<< orphan*/  tlb_state ; 
 int /*<<< orphan*/  tss ; 
 int /*<<< orphan*/  tss_struct ; 
 int /*<<< orphan*/  user_pcid_flush_mask ; 
 TYPE_1__ x86_tss ; 

int main(void)
{
#ifdef CONFIG_PARAVIRT
	OFFSET(PV_CPU_usergs_sysret64, pv_cpu_ops, usergs_sysret64);
	OFFSET(PV_CPU_swapgs, pv_cpu_ops, swapgs);
#ifdef CONFIG_DEBUG_ENTRY
	OFFSET(PV_IRQ_save_fl, pv_irq_ops, save_fl);
#endif
	BLANK();
#endif

#if defined(CONFIG_KVM_GUEST) && defined(CONFIG_PARAVIRT_SPINLOCKS)
	OFFSET(KVM_STEAL_TIME_preempted, kvm_steal_time, preempted);
	BLANK();
#endif

#define ENTRY(entry) OFFSET(pt_regs_ ## entry, pt_regs, entry)
	ENTRY(bx);
	ENTRY(cx);
	ENTRY(dx);
	ENTRY(sp);
	ENTRY(bp);
	ENTRY(si);
	ENTRY(di);
	ENTRY(r8);
	ENTRY(r9);
	ENTRY(r10);
	ENTRY(r11);
	ENTRY(r12);
	ENTRY(r13);
	ENTRY(r14);
	ENTRY(r15);
	ENTRY(flags);
	BLANK();
#undef ENTRY

#define ENTRY(entry) OFFSET(saved_context_ ## entry, saved_context, entry)
	ENTRY(cr0);
	ENTRY(cr2);
	ENTRY(cr3);
	ENTRY(cr4);
	ENTRY(cr8);
	ENTRY(gdt_desc);
	BLANK();
#undef ENTRY

	OFFSET(TSS_ist, tss_struct, x86_tss.ist);
	BLANK();

#ifdef CONFIG_STACKPROTECTOR
	DEFINE(stack_canary_offset, offsetof(union irq_stack_union, stack_canary));
	BLANK();
#endif

	DEFINE(__NR_syscall_max, sizeof(syscalls_64) - 1);
	DEFINE(NR_syscalls, sizeof(syscalls_64));

	DEFINE(__NR_syscall_compat_max, sizeof(syscalls_ia32) - 1);
	DEFINE(IA32_NR_syscalls, sizeof(syscalls_ia32));

	return 0;
}

void common(void) {
	BLANK();
	OFFSET(TASK_threadsp, task_struct, thread.sp);
#ifdef CONFIG_STACKPROTECTOR
	OFFSET(TASK_stack_canary, task_struct, stack_canary);
#endif

	BLANK();
	OFFSET(TASK_TI_flags, task_struct, thread_info.flags);
	OFFSET(TASK_addr_limit, task_struct, thread.addr_limit);

	BLANK();
	OFFSET(crypto_tfm_ctx_offset, crypto_tfm, __crt_ctx);

	BLANK();
	OFFSET(pbe_address, pbe, address);
	OFFSET(pbe_orig_address, pbe, orig_address);
	OFFSET(pbe_next, pbe, next);

#if defined(CONFIG_X86_32) || defined(CONFIG_IA32_EMULATION)
	BLANK();
	OFFSET(IA32_SIGCONTEXT_ax, sigcontext_32, ax);
	OFFSET(IA32_SIGCONTEXT_bx, sigcontext_32, bx);
	OFFSET(IA32_SIGCONTEXT_cx, sigcontext_32, cx);
	OFFSET(IA32_SIGCONTEXT_dx, sigcontext_32, dx);
	OFFSET(IA32_SIGCONTEXT_si, sigcontext_32, si);
	OFFSET(IA32_SIGCONTEXT_di, sigcontext_32, di);
	OFFSET(IA32_SIGCONTEXT_bp, sigcontext_32, bp);
	OFFSET(IA32_SIGCONTEXT_sp, sigcontext_32, sp);
	OFFSET(IA32_SIGCONTEXT_ip, sigcontext_32, ip);

	BLANK();
	OFFSET(IA32_RT_SIGFRAME_sigcontext, rt_sigframe_ia32, uc.uc_mcontext);
#endif

#ifdef CONFIG_PARAVIRT
	BLANK();
	OFFSET(PARAVIRT_PATCH_pv_cpu_ops, paravirt_patch_template, pv_cpu_ops);
	OFFSET(PARAVIRT_PATCH_pv_irq_ops, paravirt_patch_template, pv_irq_ops);
	OFFSET(PV_IRQ_irq_disable, pv_irq_ops, irq_disable);
	OFFSET(PV_IRQ_irq_enable, pv_irq_ops, irq_enable);
	OFFSET(PV_CPU_iret, pv_cpu_ops, iret);
	OFFSET(PV_CPU_read_cr0, pv_cpu_ops, read_cr0);
	OFFSET(PV_MMU_read_cr2, pv_mmu_ops, read_cr2);
#endif

#ifdef CONFIG_XEN
	BLANK();
	OFFSET(XEN_vcpu_info_mask, vcpu_info, evtchn_upcall_mask);
	OFFSET(XEN_vcpu_info_pending, vcpu_info, evtchn_upcall_pending);
#endif

	BLANK();
	OFFSET(BP_scratch, boot_params, scratch);
	OFFSET(BP_secure_boot, boot_params, secure_boot);
	OFFSET(BP_loadflags, boot_params, hdr.loadflags);
	OFFSET(BP_hardware_subarch, boot_params, hdr.hardware_subarch);
	OFFSET(BP_version, boot_params, hdr.version);
	OFFSET(BP_kernel_alignment, boot_params, hdr.kernel_alignment);
	OFFSET(BP_init_size, boot_params, hdr.init_size);
	OFFSET(BP_pref_address, boot_params, hdr.pref_address);
	OFFSET(BP_code32_start, boot_params, hdr.code32_start);

	BLANK();
	DEFINE(PTREGS_SIZE, sizeof(struct pt_regs));

	/* TLB state for the entry code */
	OFFSET(TLB_STATE_user_pcid_flush_mask, tlb_state, user_pcid_flush_mask);

	/* Layout info for cpu_entry_area */
	OFFSET(CPU_ENTRY_AREA_tss, cpu_entry_area, tss);
	OFFSET(CPU_ENTRY_AREA_entry_trampoline, cpu_entry_area, entry_trampoline);
	OFFSET(CPU_ENTRY_AREA_entry_stack, cpu_entry_area, entry_stack_page);
	DEFINE(SIZEOF_entry_stack, sizeof(struct entry_stack));
	DEFINE(MASK_entry_stack, (~(sizeof(struct entry_stack) - 1)));

	/* Offset for sp0 and sp1 into the tss_struct */
	OFFSET(TSS_sp0, tss_struct, x86_tss.sp0);
	OFFSET(TSS_sp1, tss_struct, x86_tss.sp1);
}


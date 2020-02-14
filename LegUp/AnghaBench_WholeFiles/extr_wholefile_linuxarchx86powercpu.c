#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_11__ {scalar_t__ q; } ;
struct TYPE_12__ {TYPE_3__ reg; int /*<<< orphan*/  msr_no; } ;
struct saved_msr {int valid; TYPE_4__ info; } ;
struct TYPE_13__ {int num; struct saved_msr* array; } ;
struct TYPE_9__ {unsigned long address; scalar_t__ size; } ;
struct saved_context {int misc_enable_saved; TYPE_5__ saved_msrs; scalar_t__ misc_enable; int /*<<< orphan*/  cr4; int /*<<< orphan*/  cr3; int /*<<< orphan*/  cr2; int /*<<< orphan*/  cr0; int /*<<< orphan*/  tr; TYPE_1__ gdt_desc; int /*<<< orphan*/  idt; } ;
struct dmi_system_id {int /*<<< orphan*/  ident; } ;
struct TYPE_16__ {int /*<<< orphan*/  active_mm; } ;
struct TYPE_10__ {int /*<<< orphan*/  x86_tss; } ;
struct TYPE_15__ {TYPE_2__ tss; } ;
struct TYPE_14__ {int /*<<< orphan*/  (* save_sched_clock_state ) () ;} ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ GDT_SIZE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MSR_IA32_MISC_ENABLE ; 
 int /*<<< orphan*/  MSR_IA32_THERM_CONTROL ; 
 int /*<<< orphan*/  X86_FEATURE_SEP ; 
 int /*<<< orphan*/  __read_cr3 () ; 
 int /*<<< orphan*/  __read_cr4 () ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 TYPE_8__* current ; 
 int /*<<< orphan*/  dmi_check_system (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_sep_cpu () ; 
 int /*<<< orphan*/  fpu__resume_cpu () ; 
 TYPE_7__* get_cpu_entry_area (int) ; 
 scalar_t__ get_cpu_gdt_rw (int) ; 
 int /*<<< orphan*/  initialize_tlbstate_and_flush () ; 
 int /*<<< orphan*/  kernel_fpu_begin () ; 
 int /*<<< orphan*/  kernel_fpu_end () ; 
 struct saved_msr* kmalloc_array (int const,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  load_TR_desc () ; 
 int /*<<< orphan*/  load_fixmap_gdt (int) ; 
 int /*<<< orphan*/  load_mm_ldt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msr_save_dmi_table ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rdmsrl_safe (int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  read_cr0 () ; 
 int /*<<< orphan*/  read_cr2 () ; 
 struct saved_context saved_context ; 
 int /*<<< orphan*/  set_tss_desc (int,int /*<<< orphan*/ *) ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  store_idt (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  store_tr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  wrmsrl (int /*<<< orphan*/ ,scalar_t__) ; 
 TYPE_6__ x86_platform ; 

__attribute__((used)) static void msr_save_context(struct saved_context *ctxt)
{
	struct saved_msr *msr = ctxt->saved_msrs.array;
	struct saved_msr *end = msr + ctxt->saved_msrs.num;

	while (msr < end) {
		msr->valid = !rdmsrl_safe(msr->info.msr_no, &msr->info.reg.q);
		msr++;
	}
}

__attribute__((used)) static void msr_restore_context(struct saved_context *ctxt)
{
	struct saved_msr *msr = ctxt->saved_msrs.array;
	struct saved_msr *end = msr + ctxt->saved_msrs.num;

	while (msr < end) {
		if (msr->valid)
			wrmsrl(msr->info.msr_no, msr->info.reg.q);
		msr++;
	}
}

__attribute__((used)) static void __save_processor_state(struct saved_context *ctxt)
{
#ifdef CONFIG_X86_32
	mtrr_save_fixed_ranges(NULL);
#endif
	kernel_fpu_begin();

	/*
	 * descriptor tables
	 */
	store_idt(&ctxt->idt);

	/*
	 * We save it here, but restore it only in the hibernate case.
	 * For ACPI S3 resume, this is loaded via 'early_gdt_desc' in 64-bit
	 * mode in "secondary_startup_64". In 32-bit mode it is done via
	 * 'pmode_gdt' in wakeup_start.
	 */
	ctxt->gdt_desc.size = GDT_SIZE - 1;
	ctxt->gdt_desc.address = (unsigned long)get_cpu_gdt_rw(smp_processor_id());

	store_tr(ctxt->tr);

	/* XMM0..XMM15 should be handled by kernel_fpu_begin(). */
	/*
	 * segment registers
	 */
#ifdef CONFIG_X86_32_LAZY_GS
	savesegment(gs, ctxt->gs);
#endif
#ifdef CONFIG_X86_64
	savesegment(gs, ctxt->gs);
	savesegment(fs, ctxt->fs);
	savesegment(ds, ctxt->ds);
	savesegment(es, ctxt->es);

	rdmsrl(MSR_FS_BASE, ctxt->fs_base);
	rdmsrl(MSR_GS_BASE, ctxt->kernelmode_gs_base);
	rdmsrl(MSR_KERNEL_GS_BASE, ctxt->usermode_gs_base);
	mtrr_save_fixed_ranges(NULL);

	rdmsrl(MSR_EFER, ctxt->efer);
#endif

	/*
	 * control registers
	 */
	ctxt->cr0 = read_cr0();
	ctxt->cr2 = read_cr2();
	ctxt->cr3 = __read_cr3();
	ctxt->cr4 = __read_cr4();
#ifdef CONFIG_X86_64
	ctxt->cr8 = read_cr8();
#endif
	ctxt->misc_enable_saved = !rdmsrl_safe(MSR_IA32_MISC_ENABLE,
					       &ctxt->misc_enable);
	msr_save_context(ctxt);
}

void save_processor_state(void)
{
	__save_processor_state(&saved_context);
	x86_platform.save_sched_clock_state();
}

__attribute__((used)) static void do_fpu_end(void)
{
	/*
	 * Restore FPU regs if necessary.
	 */
	kernel_fpu_end();
}

__attribute__((used)) static void fix_processor_context(void)
{
	int cpu = smp_processor_id();
#ifdef CONFIG_X86_64
	struct desc_struct *desc = get_cpu_gdt_rw(cpu);
	tss_desc tss;
#endif

	/*
	 * We need to reload TR, which requires that we change the
	 * GDT entry to indicate "available" first.
	 *
	 * XXX: This could probably all be replaced by a call to
	 * force_reload_TR().
	 */
	set_tss_desc(cpu, &get_cpu_entry_area(cpu)->tss.x86_tss);

#ifdef CONFIG_X86_64
	memcpy(&tss, &desc[GDT_ENTRY_TSS], sizeof(tss_desc));
	tss.type = 0x9; /* The available 64-bit TSS (see AMD vol 2, pg 91 */
	write_gdt_entry(desc, GDT_ENTRY_TSS, &tss, DESC_TSS);

	syscall_init();				/* This sets MSR_*STAR and related */
#else
	if (boot_cpu_has(X86_FEATURE_SEP))
		enable_sep_cpu();
#endif
	load_TR_desc();				/* This does ltr */
	load_mm_ldt(current->active_mm);	/* This does lldt */
	initialize_tlbstate_and_flush();

	fpu__resume_cpu();

	/* The processor is back on the direct GDT, load back the fixmap */
	load_fixmap_gdt(cpu);
}

__attribute__((used)) static int msr_init_context(const u32 *msr_id, const int total_num)
{
	int i = 0;
	struct saved_msr *msr_array;

	if (saved_context.saved_msrs.array || saved_context.saved_msrs.num > 0) {
		pr_err("x86/pm: MSR quirk already applied, please check your DMI match table.\n");
		return -EINVAL;
	}

	msr_array = kmalloc_array(total_num, sizeof(struct saved_msr), GFP_KERNEL);
	if (!msr_array) {
		pr_err("x86/pm: Can not allocate memory to save/restore MSRs during suspend.\n");
		return -ENOMEM;
	}

	for (i = 0; i < total_num; i++) {
		msr_array[i].info.msr_no	= msr_id[i];
		msr_array[i].valid		= false;
		msr_array[i].info.reg.q		= 0;
	}
	saved_context.saved_msrs.num	= total_num;
	saved_context.saved_msrs.array	= msr_array;

	return 0;
}

__attribute__((used)) static int msr_initialize_bdw(const struct dmi_system_id *d)
{
	/* Add any extra MSR ids into this array. */
	u32 bdw_msr_id[] = { MSR_IA32_THERM_CONTROL };

	pr_info("x86/pm: %s detected, MSR saving is needed during suspending.\n", d->ident);
	return msr_init_context(bdw_msr_id, ARRAY_SIZE(bdw_msr_id));
}

__attribute__((used)) static int pm_check_save_msr(void)
{
	dmi_check_system(msr_save_dmi_table);
	return 0;
}


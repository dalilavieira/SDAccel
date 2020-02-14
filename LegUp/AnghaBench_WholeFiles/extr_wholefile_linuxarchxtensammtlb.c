#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int vm_flags; struct mm_struct* vm_mm; } ;
struct TYPE_3__ {scalar_t__* asid; int cpu; } ;
struct mm_struct {TYPE_1__ context; } ;
struct TYPE_4__ {struct mm_struct* active_mm; } ;

/* Variables and functions */
 int ASID_INSERT (scalar_t__) ; 
 int DTLB_ARF_WAYS ; 
 int ITLB_ARF_WAYS ; 
 scalar_t__ NO_CONTEXT ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_OFFSET ; 
 int PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 unsigned long TASK_SIZE ; 
 int VM_EXEC ; 
 int XCHAL_DTLB_ARF_ENTRIES_LOG2 ; 
 int XCHAL_ITLB_ARF_ENTRIES_LOG2 ; 
 int _TLB_ENTRIES ; 
 int /*<<< orphan*/  activate_context (struct mm_struct*,int) ; 
 TYPE_2__* current ; 
 int get_rasid_register () ; 
 int /*<<< orphan*/  invalidate_dtlb_entry_no_isync (int) ; 
 int /*<<< orphan*/  invalidate_dtlb_mapping (unsigned long) ; 
 int /*<<< orphan*/  invalidate_itlb_entry_no_isync (int) ; 
 int /*<<< orphan*/  invalidate_itlb_mapping (unsigned long) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned long,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  set_rasid_register (int) ; 
 int smp_processor_id () ; 

__attribute__((used)) static inline void __flush_itlb_all (void)
{
	int w, i;

	for (w = 0; w < ITLB_ARF_WAYS; w++) {
		for (i = 0; i < (1 << XCHAL_ITLB_ARF_ENTRIES_LOG2); i++) {
			int e = w + (i << PAGE_SHIFT);
			invalidate_itlb_entry_no_isync(e);
		}
	}
	asm volatile ("isync\n");
}

__attribute__((used)) static inline void __flush_dtlb_all (void)
{
	int w, i;

	for (w = 0; w < DTLB_ARF_WAYS; w++) {
		for (i = 0; i < (1 << XCHAL_DTLB_ARF_ENTRIES_LOG2); i++) {
			int e = w + (i << PAGE_SHIFT);
			invalidate_dtlb_entry_no_isync(e);
		}
	}
	asm volatile ("isync\n");
}

void local_flush_tlb_all(void)
{
	__flush_itlb_all();
	__flush_dtlb_all();
}

void local_flush_tlb_mm(struct mm_struct *mm)
{
	int cpu = smp_processor_id();

	if (mm == current->active_mm) {
		unsigned long flags;
		local_irq_save(flags);
		mm->context.asid[cpu] = NO_CONTEXT;
		activate_context(mm, cpu);
		local_irq_restore(flags);
	} else {
		mm->context.asid[cpu] = NO_CONTEXT;
		mm->context.cpu = -1;
	}
}

void local_flush_tlb_range(struct vm_area_struct *vma,
		unsigned long start, unsigned long end)
{
	int cpu = smp_processor_id();
	struct mm_struct *mm = vma->vm_mm;
	unsigned long flags;

	if (mm->context.asid[cpu] == NO_CONTEXT)
		return;

	pr_debug("[tlbrange<%02lx,%08lx,%08lx>]\n",
		 (unsigned long)mm->context.asid[cpu], start, end);
	local_irq_save(flags);

	if (end-start + (PAGE_SIZE-1) <= _TLB_ENTRIES << PAGE_SHIFT) {
		int oldpid = get_rasid_register();

		set_rasid_register(ASID_INSERT(mm->context.asid[cpu]));
		start &= PAGE_MASK;
		if (vma->vm_flags & VM_EXEC)
			while(start < end) {
				invalidate_itlb_mapping(start);
				invalidate_dtlb_mapping(start);
				start += PAGE_SIZE;
			}
		else
			while(start < end) {
				invalidate_dtlb_mapping(start);
				start += PAGE_SIZE;
			}

		set_rasid_register(oldpid);
	} else {
		local_flush_tlb_mm(mm);
	}
	local_irq_restore(flags);
}

void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
	int cpu = smp_processor_id();
	struct mm_struct* mm = vma->vm_mm;
	unsigned long flags;
	int oldpid;

	if (mm->context.asid[cpu] == NO_CONTEXT)
		return;

	local_irq_save(flags);

	oldpid = get_rasid_register();
	set_rasid_register(ASID_INSERT(mm->context.asid[cpu]));

	if (vma->vm_flags & VM_EXEC)
		invalidate_itlb_mapping(page);
	invalidate_dtlb_mapping(page);

	set_rasid_register(oldpid);

	local_irq_restore(flags);
}

void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
	if (end > start && start >= TASK_SIZE && end <= PAGE_OFFSET &&
	    end - start < _TLB_ENTRIES << PAGE_SHIFT) {
		start &= PAGE_MASK;
		while (start < end) {
			invalidate_itlb_mapping(start);
			invalidate_dtlb_mapping(start);
			start += PAGE_SIZE;
		}
	} else {
		local_flush_tlb_all();
	}
}


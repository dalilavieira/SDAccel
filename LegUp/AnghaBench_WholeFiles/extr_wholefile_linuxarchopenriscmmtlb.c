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
struct vm_area_struct {int dummy; } ;
struct task_struct {int dummy; } ;
struct mm_struct {int /*<<< orphan*/  context; int /*<<< orphan*/  pgd; } ;

/* Variables and functions */
 int /*<<< orphan*/  NO_CONTEXT ; 
 unsigned long NUM_ITLB_SETS ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  SPR_DTLBMR_BASE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPR_ITLBMR_BASE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * current_pgd ; 
 int /*<<< orphan*/  flush_dtlb_page_eir (int) ; 
 int /*<<< orphan*/  flush_dtlb_page_no_eir (int) ; 
 int /*<<< orphan*/  flush_itlb_page_eir (int) ; 
 int /*<<< orphan*/  flush_itlb_page_no_eir (int) ; 
 int /*<<< orphan*/  flush_tlb_mm (struct mm_struct*) ; 
 int have_dtlbeir ; 
 int have_itlbeir ; 
 int /*<<< orphan*/  mtspr_off (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 size_t smp_processor_id () ; 

void local_flush_tlb_all(void)
{
	int i;
	unsigned long num_tlb_sets;

	/* Determine number of sets for IMMU. */
	/* FIXME: Assumption is I & D nsets equal. */
	num_tlb_sets = NUM_ITLB_SETS;

	for (i = 0; i < num_tlb_sets; i++) {
		mtspr_off(SPR_DTLBMR_BASE(0), i, 0);
		mtspr_off(SPR_ITLBMR_BASE(0), i, 0);
	}
}

void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long addr)
{
	if (have_dtlbeir)
		flush_dtlb_page_eir(addr);
	else
		flush_dtlb_page_no_eir(addr);

	if (have_itlbeir)
		flush_itlb_page_eir(addr);
	else
		flush_itlb_page_no_eir(addr);
}

void local_flush_tlb_range(struct vm_area_struct *vma,
			   unsigned long start, unsigned long end)
{
	int addr;
	bool dtlbeir;
	bool itlbeir;

	dtlbeir = have_dtlbeir;
	itlbeir = have_itlbeir;

	for (addr = start; addr < end; addr += PAGE_SIZE) {
		if (dtlbeir)
			flush_dtlb_page_eir(addr);
		else
			flush_dtlb_page_no_eir(addr);

		if (itlbeir)
			flush_itlb_page_eir(addr);
		else
			flush_itlb_page_no_eir(addr);
	}
}

void local_flush_tlb_mm(struct mm_struct *mm)
{

	/* Was seeing bugs with the mm struct passed to us. Scrapped most of
	   this function. */
	/* Several architctures do this */
	local_flush_tlb_all();
}

void switch_mm(struct mm_struct *prev, struct mm_struct *next,
	       struct task_struct *next_tsk)
{
	/* remember the pgd for the fault handlers
	 * this is similar to the pgd register in some other CPU's.
	 * we need our own copy of it because current and active_mm
	 * might be invalid at points where we still need to derefer
	 * the pgd.
	 */
	current_pgd[smp_processor_id()] = next->pgd;

	/* We don't have context support implemented, so flush all
	 * entries belonging to previous map
	 */

	if (prev != next)
		local_flush_tlb_mm(prev);

}

int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
	mm->context = NO_CONTEXT;
	return 0;
}

void destroy_context(struct mm_struct *mm)
{
	flush_tlb_mm(mm);

}


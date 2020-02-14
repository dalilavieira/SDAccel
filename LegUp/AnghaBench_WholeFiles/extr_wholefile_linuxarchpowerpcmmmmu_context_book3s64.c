#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct task_struct {int dummy; } ;
struct page {int /*<<< orphan*/  pt_frag_refcount; } ;
struct TYPE_4__ {scalar_t__ id; int* extended_id; int /*<<< orphan*/ * pmd_frag; int /*<<< orphan*/ * pte_frag; int /*<<< orphan*/  copros; int /*<<< orphan*/  active_cpus; int /*<<< orphan*/ * npu_context; } ;
struct mm_struct {TYPE_1__ context; int /*<<< orphan*/  pgd; } ;
typedef  TYPE_1__ mm_context_t ;
struct TYPE_5__ {scalar_t__ prtb0; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long MAX_USER_CONTEXT ; 
 unsigned long MAX_USER_CONTEXT_65BIT_VA ; 
 int MIN_USER_CONTEXT ; 
 int /*<<< orphan*/  MMU_FTR_68_BIT_VA ; 
 size_t MMU_NO_CONTEXT ; 
 unsigned long PAGE_MASK ; 
 scalar_t__ PMD_FRAG_NR ; 
 unsigned long PMD_FRAG_SIZE_SHIFT ; 
 scalar_t__ PTE_FRAG_NR ; 
 unsigned long PTE_FRAG_SIZE_SHIFT ; 
 unsigned long RADIX_PGD_INDEX_SIZE ; 
 int /*<<< orphan*/  WARN (int,char*,int,int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __free_page (struct page*) ; 
 unsigned long __pa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ atomic_sub_and_test (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_to_be64 (unsigned long) ; 
 int ida_alloc_range (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_free (int /*<<< orphan*/ *,int) ; 
 int mmu_base_pid ; 
 int /*<<< orphan*/  mmu_context_ida ; 
 scalar_t__ mmu_has_feature (int /*<<< orphan*/ ) ; 
 int mmu_pid_bits ; 
 int /*<<< orphan*/  pgtable_page_dtor (struct page*) ; 
 int /*<<< orphan*/  pgtable_pmd_page_dtor (struct page*) ; 
 int /*<<< orphan*/  pkey_mm_init (struct mm_struct*) ; 
 TYPE_2__* process_tb ; 
 unsigned long radix__get_tree_size () ; 
 scalar_t__ radix_enabled () ; 
 int /*<<< orphan*/  slice_init_new_context_exec (struct mm_struct*) ; 
 int /*<<< orphan*/  subpage_prot_free (struct mm_struct*) ; 
 int /*<<< orphan*/  subpage_prot_init_new_context (struct mm_struct*) ; 
 struct page* virt_to_page (void*) ; 

__attribute__((used)) static int alloc_context_id(int min_id, int max_id)
{
	return ida_alloc_range(&mmu_context_ida, min_id, max_id, GFP_KERNEL);
}

void hash__reserve_context_id(int id)
{
	int result = ida_alloc_range(&mmu_context_ida, id, id, GFP_KERNEL);

	WARN(result != id, "mmu: Failed to reserve context id %d (rc %d)\n", id, result);
}

int hash__alloc_context_id(void)
{
	unsigned long max;

	if (mmu_has_feature(MMU_FTR_68_BIT_VA))
		max = MAX_USER_CONTEXT;
	else
		max = MAX_USER_CONTEXT_65BIT_VA;

	return alloc_context_id(MIN_USER_CONTEXT, max);
}

__attribute__((used)) static int hash__init_new_context(struct mm_struct *mm)
{
	int index;

	index = hash__alloc_context_id();
	if (index < 0)
		return index;

	/*
	 * The old code would re-promote on fork, we don't do that when using
	 * slices as it could cause problem promoting slices that have been
	 * forced down to 4K.
	 *
	 * For book3s we have MMU_NO_CONTEXT set to be ~0. Hence check
	 * explicitly against context.id == 0. This ensures that we properly
	 * initialize context slice details for newly allocated mm's (which will
	 * have id == 0) and don't alter context slice inherited via fork (which
	 * will have id != 0).
	 *
	 * We should not be calling init_new_context() on init_mm. Hence a
	 * check against 0 is OK.
	 */
	if (mm->context.id == 0)
		slice_init_new_context_exec(mm);

	subpage_prot_init_new_context(mm);

	pkey_mm_init(mm);
	return index;
}

__attribute__((used)) static int radix__init_new_context(struct mm_struct *mm)
{
	unsigned long rts_field;
	int index, max_id;

	max_id = (1 << mmu_pid_bits) - 1;
	index = alloc_context_id(mmu_base_pid, max_id);
	if (index < 0)
		return index;

	/*
	 * set the process table entry,
	 */
	rts_field = radix__get_tree_size();
	process_tb[index].prtb0 = cpu_to_be64(rts_field | __pa(mm->pgd) | RADIX_PGD_INDEX_SIZE);

	/*
	 * Order the above store with subsequent update of the PID
	 * register (at which point HW can start loading/caching
	 * the entry) and the corresponding load by the MMU from
	 * the L2 cache.
	 */
	asm volatile("ptesync;isync" : : : "memory");

	mm->context.npu_context = NULL;

	return index;
}

int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
	int index;

	if (radix_enabled())
		index = radix__init_new_context(mm);
	else
		index = hash__init_new_context(mm);

	if (index < 0)
		return index;

	mm->context.id = index;

	mm->context.pte_frag = NULL;
	mm->context.pmd_frag = NULL;
#ifdef CONFIG_SPAPR_TCE_IOMMU
	mm_iommu_init(mm);
#endif
	atomic_set(&mm->context.active_cpus, 0);
	atomic_set(&mm->context.copros, 0);

	return 0;
}

void __destroy_context(int context_id)
{
	ida_free(&mmu_context_ida, context_id);
}

__attribute__((used)) static void destroy_contexts(mm_context_t *ctx)
{
	int index, context_id;

	for (index = 0; index < ARRAY_SIZE(ctx->extended_id); index++) {
		context_id = ctx->extended_id[index];
		if (context_id)
			ida_free(&mmu_context_ida, context_id);
	}
}

__attribute__((used)) static void pte_frag_destroy(void *pte_frag)
{
	int count;
	struct page *page;

	page = virt_to_page(pte_frag);
	/* drop all the pending references */
	count = ((unsigned long)pte_frag & ~PAGE_MASK) >> PTE_FRAG_SIZE_SHIFT;
	/* We allow PTE_FRAG_NR fragments from a PTE page */
	if (atomic_sub_and_test(PTE_FRAG_NR - count, &page->pt_frag_refcount)) {
		pgtable_page_dtor(page);
		__free_page(page);
	}
}

__attribute__((used)) static void pmd_frag_destroy(void *pmd_frag)
{
	int count;
	struct page *page;

	page = virt_to_page(pmd_frag);
	/* drop all the pending references */
	count = ((unsigned long)pmd_frag & ~PAGE_MASK) >> PMD_FRAG_SIZE_SHIFT;
	/* We allow PTE_FRAG_NR fragments from a PTE page */
	if (atomic_sub_and_test(PMD_FRAG_NR - count, &page->pt_frag_refcount)) {
		pgtable_pmd_page_dtor(page);
		__free_page(page);
	}
}

__attribute__((used)) static void destroy_pagetable_cache(struct mm_struct *mm)
{
	void *frag;

	frag = mm->context.pte_frag;
	if (frag)
		pte_frag_destroy(frag);

	frag = mm->context.pmd_frag;
	if (frag)
		pmd_frag_destroy(frag);
	return;
}

void destroy_context(struct mm_struct *mm)
{
#ifdef CONFIG_SPAPR_TCE_IOMMU
	WARN_ON_ONCE(!list_empty(&mm->context.iommu_group_mem_list));
#endif
	if (radix_enabled())
		WARN_ON(process_tb[mm->context.id].prtb0 != 0);
	else
		subpage_prot_free(mm);
	destroy_contexts(&mm->context);
	mm->context.id = MMU_NO_CONTEXT;
}

void arch_exit_mmap(struct mm_struct *mm)
{
	destroy_pagetable_cache(mm);

	if (radix_enabled()) {
		/*
		 * Radix doesn't have a valid bit in the process table
		 * entries. However we know that at least P9 implementation
		 * will avoid caching an entry with an invalid RTS field,
		 * and 0 is invalid. So this will do.
		 *
		 * This runs before the "fullmm" tlb flush in exit_mmap,
		 * which does a RIC=2 tlbie to clear the process table
		 * entry. See the "fullmm" comments in tlb-radix.c.
		 *
		 * No barrier required here after the store because
		 * this process will do the invalidate, which starts with
		 * ptesync.
		 */
		process_tb[mm->context.id].prtb0 = 0;
	}
}


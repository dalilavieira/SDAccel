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
struct vm_area_struct {int /*<<< orphan*/  vm_mm; } ;
struct page {int /*<<< orphan*/  flags; } ;
struct mm_struct {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;
struct TYPE_3__ {scalar_t__ regs; } ;
struct TYPE_4__ {TYPE_1__ thread; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CPU_FTR_COHERENT_ICACHE ; 
 int /*<<< orphan*/  CPU_FTR_NOEXECUTE ; 
 int /*<<< orphan*/  PG_arch_1 ; 
 scalar_t__ PageReserved (struct page*) ; 
 int TRAP (scalar_t__) ; 
 int /*<<< orphan*/  VM_WARN_ON (int) ; 
 int _PAGE_HPTEFLAGS ; 
 int _PAGE_NO_CACHE ; 
 int _PAGE_PRESENT ; 
 int _PAGE_PRIVILEGED ; 
 int _PAGE_PTE ; 
 int _PAGE_SPECIAL ; 
 int _PAGE_USER ; 
 unsigned long __pa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __pte (int) ; 
 int /*<<< orphan*/  __ptep_set_access_flags (struct vm_area_struct*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __set_pte_at (struct mm_struct*,unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert_pte_locked (int /*<<< orphan*/ ,unsigned long) ; 
 scalar_t__ cpu_has_feature (int /*<<< orphan*/ ) ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  flush_dcache_icache_page (struct page*) ; 
 int /*<<< orphan*/  mmu_virtual_psize ; 
 unsigned long offset_in_page (void*) ; 
 int /*<<< orphan*/  pfn_to_kaddr (unsigned long) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pfn_valid (unsigned long) ; 
 unsigned long pte_pfn (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_present (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pte_protnone (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pte_same (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pte_val (int /*<<< orphan*/ ) ; 
 scalar_t__ radix_enabled () ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 
 unsigned long vmalloc_to_pfn (void*) ; 

__attribute__((used)) static inline int is_exec_fault(void)
{
	return current->thread.regs && TRAP(current->thread.regs) == 0x400;
}

__attribute__((used)) static inline int pte_looks_normal(pte_t pte)
{

#if defined(CONFIG_PPC_BOOK3S_64)
	if ((pte_val(pte) & (_PAGE_PRESENT | _PAGE_SPECIAL)) == _PAGE_PRESENT) {
		if (pte_ci(pte))
			return 0;
		if (pte_user(pte))
			return 1;
	}
	return 0;
#else
	return (pte_val(pte) &
		(_PAGE_PRESENT | _PAGE_SPECIAL | _PAGE_NO_CACHE | _PAGE_USER |
		 _PAGE_PRIVILEGED)) ==
		(_PAGE_PRESENT | _PAGE_USER);
#endif
}

__attribute__((used)) static struct page *maybe_pte_to_page(pte_t pte)
{
	unsigned long pfn = pte_pfn(pte);
	struct page *page;

	if (unlikely(!pfn_valid(pfn)))
		return NULL;
	page = pfn_to_page(pfn);
	if (PageReserved(page))
		return NULL;
	return page;
}

__attribute__((used)) static pte_t set_pte_filter(pte_t pte)
{
	if (radix_enabled())
		return pte;

	pte = __pte(pte_val(pte) & ~_PAGE_HPTEFLAGS);
	if (pte_looks_normal(pte) && !(cpu_has_feature(CPU_FTR_COHERENT_ICACHE) ||
				       cpu_has_feature(CPU_FTR_NOEXECUTE))) {
		struct page *pg = maybe_pte_to_page(pte);
		if (!pg)
			return pte;
		if (!test_bit(PG_arch_1, &pg->flags)) {
			flush_dcache_icache_page(pg);
			set_bit(PG_arch_1, &pg->flags);
		}
	}
	return pte;
}

__attribute__((used)) static pte_t set_access_flags_filter(pte_t pte, struct vm_area_struct *vma,
				     int dirty)
{
	return pte;
}

void set_pte_at(struct mm_struct *mm, unsigned long addr, pte_t *ptep,
		pte_t pte)
{
	/*
	 * When handling numa faults, we already have the pte marked
	 * _PAGE_PRESENT, but we can be sure that it is not in hpte.
	 * Hence we can use set_pte_at for them.
	 */
	VM_WARN_ON(pte_present(*ptep) && !pte_protnone(*ptep));

	/* Add the pte bit when trying to set a pte */
	pte = __pte(pte_val(pte) | _PAGE_PTE);

	/* Note: mm->context.id might not yet have been assigned as
	 * this context might not have been activated yet when this
	 * is called.
	 */
	pte = set_pte_filter(pte);

	/* Perform the setting of the PTE */
	__set_pte_at(mm, addr, ptep, pte, 0);
}

int ptep_set_access_flags(struct vm_area_struct *vma, unsigned long address,
			  pte_t *ptep, pte_t entry, int dirty)
{
	int changed;
	entry = set_access_flags_filter(entry, vma, dirty);
	changed = !pte_same(*(ptep), entry);
	if (changed) {
		assert_pte_locked(vma->vm_mm, address);
		__ptep_set_access_flags(vma, ptep, entry,
					address, mmu_virtual_psize);
	}
	return changed;
}

unsigned long vmalloc_to_phys(void *va)
{
	unsigned long pfn = vmalloc_to_pfn(va);

	BUG_ON(!pfn);
	return __pa(pfn_to_kaddr(pfn)) + offset_in_page(va);
}


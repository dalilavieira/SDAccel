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
struct page {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 scalar_t__ FIXADDR_START ; 
 int FIX_KMAP_BEGIN ; 
 int KM_TYPE_NR ; 
 int /*<<< orphan*/  LAST_PKMAP ; 
 unsigned long PAGE_MASK ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 unsigned long PKMAP_ADDR (int /*<<< orphan*/ ) ; 
 size_t PKMAP_NR (unsigned long) ; 
 int /*<<< orphan*/  PageHighMem (struct page*) ; 
 int /*<<< orphan*/  __cpuc_flush_dcache_area (void*,int /*<<< orphan*/ ) ; 
 unsigned long __fix_to_virt (int) ; 
 scalar_t__ cache_is_vivt () ; 
 int /*<<< orphan*/  in_interrupt () ; 
 int kmap_atomic_idx () ; 
 int /*<<< orphan*/  kmap_atomic_idx_pop () ; 
 int kmap_atomic_idx_push () ; 
 void* kmap_high (struct page*) ; 
 void* kmap_high_get (struct page*) ; 
 int /*<<< orphan*/  kmap_prot ; 
 int /*<<< orphan*/  kunmap_high (struct page*) ; 
 int /*<<< orphan*/  local_flush_tlb_kernel_page (unsigned long) ; 
 int /*<<< orphan*/  might_sleep () ; 
 int /*<<< orphan*/  mk_pte (struct page*,int /*<<< orphan*/ ) ; 
 void* page_address (struct page*) ; 
 int /*<<< orphan*/  pagefault_disable () ; 
 int /*<<< orphan*/  pagefault_enable () ; 
 int /*<<< orphan*/  pfn_pte (unsigned long,int /*<<< orphan*/ ) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/ * pkmap_page_table ; 
 int /*<<< orphan*/  pmd_off_k (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ ,unsigned long) ; 
 struct page* pte_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pte_ext (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int smp_processor_id () ; 

__attribute__((used)) static inline void set_fixmap_pte(int idx, pte_t pte)
{
	unsigned long vaddr = __fix_to_virt(idx);
	pte_t *ptep = pte_offset_kernel(pmd_off_k(vaddr), vaddr);

	set_pte_ext(ptep, pte, 0);
	local_flush_tlb_kernel_page(vaddr);
}

__attribute__((used)) static inline pte_t get_fixmap_pte(unsigned long vaddr)
{
	pte_t *ptep = pte_offset_kernel(pmd_off_k(vaddr), vaddr);

	return *ptep;
}

void *kmap(struct page *page)
{
	might_sleep();
	if (!PageHighMem(page))
		return page_address(page);
	return kmap_high(page);
}

void kunmap(struct page *page)
{
	BUG_ON(in_interrupt());
	if (!PageHighMem(page))
		return;
	kunmap_high(page);
}

void *kmap_atomic(struct page *page)
{
	unsigned int idx;
	unsigned long vaddr;
	void *kmap;
	int type;

	preempt_disable();
	pagefault_disable();
	if (!PageHighMem(page))
		return page_address(page);

#ifdef CONFIG_DEBUG_HIGHMEM
	/*
	 * There is no cache coherency issue when non VIVT, so force the
	 * dedicated kmap usage for better debugging purposes in that case.
	 */
	if (!cache_is_vivt())
		kmap = NULL;
	else
#endif
		kmap = kmap_high_get(page);
	if (kmap)
		return kmap;

	type = kmap_atomic_idx_push();

	idx = FIX_KMAP_BEGIN + type + KM_TYPE_NR * smp_processor_id();
	vaddr = __fix_to_virt(idx);
#ifdef CONFIG_DEBUG_HIGHMEM
	/*
	 * With debugging enabled, kunmap_atomic forces that entry to 0.
	 * Make sure it was indeed properly unmapped.
	 */
	BUG_ON(!pte_none(get_fixmap_pte(vaddr)));
#endif
	/*
	 * When debugging is off, kunmap_atomic leaves the previous mapping
	 * in place, so the contained TLB flush ensures the TLB is updated
	 * with the new mapping.
	 */
	set_fixmap_pte(idx, mk_pte(page, kmap_prot));

	return (void *)vaddr;
}

void __kunmap_atomic(void *kvaddr)
{
	unsigned long vaddr = (unsigned long) kvaddr & PAGE_MASK;
	int idx, type;

	if (kvaddr >= (void *)FIXADDR_START) {
		type = kmap_atomic_idx();
		idx = FIX_KMAP_BEGIN + type + KM_TYPE_NR * smp_processor_id();

		if (cache_is_vivt())
			__cpuc_flush_dcache_area((void *)vaddr, PAGE_SIZE);
#ifdef CONFIG_DEBUG_HIGHMEM
		BUG_ON(vaddr != __fix_to_virt(idx));
		set_fixmap_pte(idx, __pte(0));
#else
		(void) idx;  /* to kill a warning */
#endif
		kmap_atomic_idx_pop();
	} else if (vaddr >= PKMAP_ADDR(0) && vaddr < PKMAP_ADDR(LAST_PKMAP)) {
		/* this address was obtained through kmap_high_get() */
		kunmap_high(pte_page(pkmap_page_table[PKMAP_NR(vaddr)]));
	}
	pagefault_enable();
	preempt_enable();
}

void *kmap_atomic_pfn(unsigned long pfn)
{
	unsigned long vaddr;
	int idx, type;
	struct page *page = pfn_to_page(pfn);

	preempt_disable();
	pagefault_disable();
	if (!PageHighMem(page))
		return page_address(page);

	type = kmap_atomic_idx_push();
	idx = FIX_KMAP_BEGIN + type + KM_TYPE_NR * smp_processor_id();
	vaddr = __fix_to_virt(idx);
#ifdef CONFIG_DEBUG_HIGHMEM
	BUG_ON(!pte_none(get_fixmap_pte(vaddr)));
#endif
	set_fixmap_pte(idx, pfn_pte(pfn, kmap_prot));

	return (void *)vaddr;
}


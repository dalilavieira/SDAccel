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

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 unsigned long FIXMAP_ADDR (int) ; 
 unsigned long FIXMAP_BASE ; 
 unsigned long FIXMAP_SIZE ; 
 int KM_TYPE_NR ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  PageHighMem (struct page*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 scalar_t__ fixmap_page_table ; 
 int /*<<< orphan*/  in_interrupt () ; 
 int /*<<< orphan*/  init_mm ; 
 int kmap_atomic_idx () ; 
 int /*<<< orphan*/  kmap_atomic_idx_pop () ; 
 int kmap_atomic_idx_push () ; 
 void* kmap_high (struct page*) ; 
 int /*<<< orphan*/  kmap_prot ; 
 int /*<<< orphan*/  local_flush_tlb_kernel_range (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  mk_pte (struct page*,int /*<<< orphan*/ ) ; 
 void* page_address (struct page*) ; 
 int /*<<< orphan*/  pagefault_disable () ; 
 int /*<<< orphan*/  pagefault_enable () ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  pte_clear (int /*<<< orphan*/ *,unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  set_pte_at (int /*<<< orphan*/ *,unsigned long,scalar_t__,int /*<<< orphan*/ ) ; 
 int smp_processor_id () ; 

void *kmap(struct page *page)
{
	BUG_ON(in_interrupt());
	if (!PageHighMem(page))
		return page_address(page);

	return kmap_high(page);
}

void *kmap_atomic(struct page *page)
{
	int idx, cpu_idx;
	unsigned long vaddr;

	preempt_disable();
	pagefault_disable();
	if (!PageHighMem(page))
		return page_address(page);

	cpu_idx = kmap_atomic_idx_push();
	idx = cpu_idx + KM_TYPE_NR * smp_processor_id();
	vaddr = FIXMAP_ADDR(idx);

	set_pte_at(&init_mm, vaddr, fixmap_page_table + idx,
		   mk_pte(page, kmap_prot));

	return (void *)vaddr;
}

void __kunmap_atomic(void *kv)
{
	unsigned long kvaddr = (unsigned long)kv;

	if (kvaddr >= FIXMAP_BASE && kvaddr < (FIXMAP_BASE + FIXMAP_SIZE)) {

		/*
		 * Because preemption is disabled, this vaddr can be associated
		 * with the current allocated index.
		 * But in case of multiple live kmap_atomic(), it still relies on
		 * callers to unmap in right order.
		 */
		int cpu_idx = kmap_atomic_idx();
		int idx = cpu_idx + KM_TYPE_NR * smp_processor_id();

		WARN_ON(kvaddr != FIXMAP_ADDR(idx));

		pte_clear(&init_mm, kvaddr, fixmap_page_table + idx);
		local_flush_tlb_kernel_range(kvaddr, kvaddr + PAGE_SIZE);

		kmap_atomic_idx_pop();
	}

	pagefault_enable();
	preempt_enable();
}


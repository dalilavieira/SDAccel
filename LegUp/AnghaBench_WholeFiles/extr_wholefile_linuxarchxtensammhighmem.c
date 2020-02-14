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
typedef  enum fixed_addresses { ____Placeholder_fixed_addresses } fixed_addresses ;

/* Variables and functions */
 unsigned long DCACHE_ALIAS (unsigned long) ; 
 int DCACHE_N_COLORS ; 
 scalar_t__ FIXADDR_START ; 
 scalar_t__ FIXADDR_TOP ; 
 int FIX_KMAP_BEGIN ; 
 int KM_TYPE_NR ; 
 int /*<<< orphan*/  PAGE_KERNEL_EXEC ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  PageHighMem (struct page*) ; 
 unsigned long __fix_to_virt (int) ; 
 int /*<<< orphan*/  init_mm ; 
 int kmap_atomic_idx () ; 
 int /*<<< orphan*/  kmap_atomic_idx_pop () ; 
 int kmap_atomic_idx_push () ; 
 int kmap_pte ; 
 int /*<<< orphan*/  local_flush_tlb_kernel_range (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  mk_pte (struct page*,int /*<<< orphan*/ ) ; 
 void* page_address (struct page*) ; 
 unsigned long page_to_phys (struct page*) ; 
 int /*<<< orphan*/  pagefault_disable () ; 
 int /*<<< orphan*/  pagefault_enable () ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  pte_clear (int /*<<< orphan*/ *,void*,int) ; 
 int /*<<< orphan*/  set_pte (int,int /*<<< orphan*/ ) ; 
 int smp_processor_id () ; 

__attribute__((used)) static inline void kmap_waitqueues_init(void)
{
}

__attribute__((used)) static inline enum fixed_addresses kmap_idx(int type, unsigned long color)
{
	return (type + KM_TYPE_NR * smp_processor_id()) * DCACHE_N_COLORS +
		color;
}

void *kmap_atomic(struct page *page)
{
	enum fixed_addresses idx;
	unsigned long vaddr;

	preempt_disable();
	pagefault_disable();
	if (!PageHighMem(page))
		return page_address(page);

	idx = kmap_idx(kmap_atomic_idx_push(),
		       DCACHE_ALIAS(page_to_phys(page)));
	vaddr = __fix_to_virt(FIX_KMAP_BEGIN + idx);
#ifdef CONFIG_DEBUG_HIGHMEM
	BUG_ON(!pte_none(*(kmap_pte + idx)));
#endif
	set_pte(kmap_pte + idx, mk_pte(page, PAGE_KERNEL_EXEC));

	return (void *)vaddr;
}

void __kunmap_atomic(void *kvaddr)
{
	if (kvaddr >= (void *)FIXADDR_START &&
	    kvaddr < (void *)FIXADDR_TOP) {
		int idx = kmap_idx(kmap_atomic_idx(),
				   DCACHE_ALIAS((unsigned long)kvaddr));

		/*
		 * Force other mappings to Oops if they'll try to access this
		 * pte without first remap it.  Keeping stale mappings around
		 * is a bad idea also, in case the page changes cacheability
		 * attributes or becomes a protected page in a hypervisor.
		 */
		pte_clear(&init_mm, kvaddr, kmap_pte + idx);
		local_flush_tlb_kernel_range((unsigned long)kvaddr,
					     (unsigned long)kvaddr + PAGE_SIZE);

		kmap_atomic_idx_pop();
	}

	pagefault_enable();
	preempt_enable();
}


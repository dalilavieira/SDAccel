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
struct vm_area_struct {int vm_flags; } ;
struct page {int /*<<< orphan*/  flags; } ;
typedef  int /*<<< orphan*/  pte_t ;

/* Variables and functions */
 int L1_CACHE_BYTES ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long PAGE_SIZE ; 
 int /*<<< orphan*/  PG_dc_clean ; 
 unsigned int SPR_DCBFR ; 
 unsigned int SPR_ICBIR ; 
 int VM_EXEC ; 
 int /*<<< orphan*/  mtspr (unsigned int const,unsigned long) ; 
 unsigned long page_to_pfn (struct page*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 unsigned long pte_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sync_icache_dcache (struct page*) ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cache_loop(struct page *page, const unsigned int reg)
{
	unsigned long paddr = page_to_pfn(page) << PAGE_SHIFT;
	unsigned long line = paddr & ~(L1_CACHE_BYTES - 1);

	while (line < paddr + PAGE_SIZE) {
		mtspr(reg, line);
		line += L1_CACHE_BYTES;
	}
}

void local_dcache_page_flush(struct page *page)
{
	cache_loop(page, SPR_DCBFR);
}

void local_icache_page_inv(struct page *page)
{
	cache_loop(page, SPR_ICBIR);
}

void update_cache(struct vm_area_struct *vma, unsigned long address,
	pte_t *pte)
{
	unsigned long pfn = pte_val(*pte) >> PAGE_SHIFT;
	struct page *page = pfn_to_page(pfn);
	int dirty = !test_and_set_bit(PG_dc_clean, &page->flags);

	/*
	 * Since icaches do not snoop for updated data on OpenRISC, we
	 * must write back and invalidate any dirty pages manually. We
	 * can skip data pages, since they will not end up in icaches.
	 */
	if ((vma->vm_flags & VM_EXEC) && dirty)
		sync_icache_dcache(page);
}


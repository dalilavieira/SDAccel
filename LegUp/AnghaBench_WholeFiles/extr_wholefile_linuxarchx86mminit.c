#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  enum page_cache_mode { ____Placeholder_page_cache_mode } page_cache_mode ;
struct TYPE_4__ {unsigned long start; unsigned long end; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  E820_MAX_ENTRIES ; 
 int PAGE_SHIFT ; 
 int _PAGE_CACHE_MODE_WB ; 
 int /*<<< orphan*/ * __cachemode2pte_tbl ; 
 int /*<<< orphan*/  __cm_idx2pte (unsigned int) ; 
 int* __pte2cachemode_tbl ; 
 int add_range_with_merge (TYPE_1__*,int /*<<< orphan*/ ,int,unsigned long,unsigned long) ; 
 void* alloc_low_pages (int) ; 
 int clean_sort_range (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  max_low_pfn_mapped ; 
 int /*<<< orphan*/  max_pfn_mapped ; 
 unsigned long min (unsigned long,unsigned long) ; 
 int nr_pfn_mapped ; 
 TYPE_1__* pfn_mapped ; 

__attribute__((used)) static inline void *alloc_low_page(void)
{
	return alloc_low_pages(1);
}

__attribute__((used)) static void add_pfn_range_mapped(unsigned long start_pfn, unsigned long end_pfn)
{
	nr_pfn_mapped = add_range_with_merge(pfn_mapped, E820_MAX_ENTRIES,
					     nr_pfn_mapped, start_pfn, end_pfn);
	nr_pfn_mapped = clean_sort_range(pfn_mapped, E820_MAX_ENTRIES);

	max_pfn_mapped = max(max_pfn_mapped, end_pfn);

	if (start_pfn < (1UL<<(32-PAGE_SHIFT)))
		max_low_pfn_mapped = max(max_low_pfn_mapped,
					 min(end_pfn, 1UL<<(32-PAGE_SHIFT)));
}

bool pfn_range_is_mapped(unsigned long start_pfn, unsigned long end_pfn)
{
	int i;

	for (i = 0; i < nr_pfn_mapped; i++)
		if ((start_pfn >= pfn_mapped[i].start) &&
		    (end_pfn <= pfn_mapped[i].end))
			return true;

	return false;
}

void update_cache_mode_entry(unsigned entry, enum page_cache_mode cache)
{
	/* entry 0 MUST be WB (hardwired to speed up translations) */
	BUG_ON(!entry && cache != _PAGE_CACHE_MODE_WB);

	__cachemode2pte_tbl[cache] = __cm_idx2pte(entry);
	__pte2cachemode_tbl[entry] = cache;
}


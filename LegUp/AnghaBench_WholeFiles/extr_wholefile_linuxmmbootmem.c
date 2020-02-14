#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int vm_flags_t ;
struct zone {scalar_t__ managed_pages; scalar_t__ contiguous; } ;
struct vm_area_struct {int vm_flags; } ;
struct page {int dummy; } ;
struct mm_struct {int dummy; } ;
struct file_ra_state {int /*<<< orphan*/  async_size; int /*<<< orphan*/  size; int /*<<< orphan*/  start; } ;
struct file {int dummy; } ;
struct address_space {int dummy; } ;
struct TYPE_3__ {struct zone* node_zones; } ;
typedef  TYPE_1__ pg_data_t ;
typedef  enum mminit_level { ____Placeholder_mminit_level } mminit_level ;
typedef  enum migratetype { ____Placeholder_migratetype } migratetype ;

/* Variables and functions */
 int MAX_NR_ZONES ; 
 int MAX_ORDER_NR_PAGES ; 
 int MIGRATE_HIGHATOMIC ; 
 int /*<<< orphan*/  PageTail (struct page*) ; 
 int /*<<< orphan*/  VM_BUG_ON_PAGE (int /*<<< orphan*/ ,struct page*) ; 
 int VM_EXEC ; 
 int VM_HUGETLB ; 
 int VM_LOCKED ; 
 int VM_MAYWRITE ; 
 int VM_PFNMAP ; 
 int VM_SHARED ; 
 int VM_STACK ; 
 int VM_WRITE ; 
 unsigned long __do_page_cache_readahead (struct address_space*,struct file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct page* __pageblock_pfn_to_page (unsigned long,unsigned long,struct zone*) ; 
 int get_pageblock_migratetype (struct page*) ; 
 struct page* nth_page (struct page*,int) ; 
 unsigned int page_private (struct page*) ; 
 int /*<<< orphan*/  page_ref_count (struct page*) ; 
 int page_to_pfn (struct page*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  set_page_count (struct page*,int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline bool can_madv_dontneed_vma(struct vm_area_struct *vma)
{
	return !(vma->vm_flags & (VM_LOCKED|VM_HUGETLB|VM_PFNMAP));
}

__attribute__((used)) static inline unsigned long ra_submit(struct file_ra_state *ra,
		struct address_space *mapping, struct file *filp)
{
	return __do_page_cache_readahead(mapping, filp,
					ra->start, ra->size, ra->async_size);
}

__attribute__((used)) static inline void set_page_refcounted(struct page *page)
{
	VM_BUG_ON_PAGE(PageTail(page), page);
	VM_BUG_ON_PAGE(page_ref_count(page), page);
	set_page_count(page, 1);
}

__attribute__((used)) static inline unsigned long
__find_buddy_pfn(unsigned long page_pfn, unsigned int order)
{
	return page_pfn ^ (1 << order);
}

__attribute__((used)) static inline struct page *pageblock_pfn_to_page(unsigned long start_pfn,
				unsigned long end_pfn, struct zone *zone)
{
	if (zone->contiguous)
		return pfn_to_page(start_pfn);

	return __pageblock_pfn_to_page(start_pfn, end_pfn, zone);
}

__attribute__((used)) static inline unsigned int page_order(struct page *page)
{
	/* PageBuddy() must be checked by the caller */
	return page_private(page);
}

__attribute__((used)) static inline bool is_cow_mapping(vm_flags_t flags)
{
	return (flags & (VM_SHARED | VM_MAYWRITE)) == VM_MAYWRITE;
}

__attribute__((used)) static inline bool is_exec_mapping(vm_flags_t flags)
{
	return (flags & (VM_EXEC | VM_WRITE | VM_STACK)) == VM_EXEC;
}

__attribute__((used)) static inline bool is_stack_mapping(vm_flags_t flags)
{
	return (flags & VM_STACK) == VM_STACK;
}

__attribute__((used)) static inline bool is_data_mapping(vm_flags_t flags)
{
	return (flags & (VM_WRITE | VM_SHARED | VM_STACK)) == VM_WRITE;
}

__attribute__((used)) static inline void clear_page_mlock(struct page *page) { }

__attribute__((used)) static inline void mlock_vma_page(struct page *page) { }

__attribute__((used)) static inline void mlock_migrate_page(struct page *new, struct page *old) { }

__attribute__((used)) static inline struct page *mem_map_offset(struct page *base, int offset)
{
	if (unlikely(offset >= MAX_ORDER_NR_PAGES))
		return nth_page(base, offset);
	return base + offset;
}

__attribute__((used)) static inline struct page *mem_map_next(struct page *iter,
						struct page *base, int offset)
{
	if (unlikely((offset & (MAX_ORDER_NR_PAGES - 1)) == 0)) {
		unsigned long pfn = page_to_pfn(base) + offset;
		if (!pfn_valid(pfn))
			return NULL;
		return pfn_to_page(pfn);
	}
	return iter + 1;
}

__attribute__((used)) static inline void mminit_dprintk(enum mminit_level level,
				const char *prefix, const char *fmt, ...)
{
}

__attribute__((used)) static inline void mminit_verify_pageflags_layout(void)
{
}

__attribute__((used)) static inline void mminit_verify_zonelist(void)
{
}

__attribute__((used)) static inline void mminit_validate_memmodel_limits(unsigned long *start_pfn,
				unsigned long *end_pfn)
{
}

__attribute__((used)) static inline void try_to_unmap_flush(void)
{
}

__attribute__((used)) static inline void try_to_unmap_flush_dirty(void)
{
}

__attribute__((used)) static inline void flush_tlb_batched_pending(struct mm_struct *mm)
{
}

__attribute__((used)) static inline bool is_migrate_highatomic(enum migratetype migratetype)
{
	return migratetype == MIGRATE_HIGHATOMIC;
}

__attribute__((used)) static inline bool is_migrate_highatomic_page(struct page *page)
{
	return get_pageblock_migratetype(page) == MIGRATE_HIGHATOMIC;
}

void reset_node_managed_pages(pg_data_t *pgdat)
{
	struct zone *z;

	for (z = pgdat->node_zones; z < pgdat->node_zones + MAX_NR_ZONES; z++)
		z->managed_pages = 0;
}


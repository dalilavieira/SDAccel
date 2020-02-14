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
typedef  int vm_flags_t ;
typedef  unsigned long u64 ;
struct zone {scalar_t__ contiguous; } ;
struct vm_area_struct {int vm_flags; } ;
struct page {int dummy; } ;
struct mm_struct {int dummy; } ;
struct file_ra_state {int /*<<< orphan*/  async_size; int /*<<< orphan*/  size; int /*<<< orphan*/  start; } ;
struct file {int dummy; } ;
struct dentry {int dummy; } ;
struct address_space {int dummy; } ;
typedef  enum mminit_level { ____Placeholder_mminit_level } mminit_level ;
typedef  enum migratetype { ____Placeholder_migratetype } migratetype ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPERM ; 
 int MAX_ORDER_NR_PAGES ; 
 int /*<<< orphan*/  MF_COUNT_INCREASED ; 
 int MIGRATE_HIGHATOMIC ; 
 int /*<<< orphan*/  PageHuge (struct page*) ; 
 int /*<<< orphan*/  PageLRU (struct page*) ; 
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
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 struct page* compound_head (struct page*) ; 
 int /*<<< orphan*/ * debugfs_create_dir (char*,int /*<<< orphan*/ *) ; 
 struct dentry* debugfs_create_file (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct dentry* debugfs_create_u32 (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct dentry* debugfs_create_u64 (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_hwpoison_page (struct page*) ; 
 int get_pageblock_migratetype (struct page*) ; 
 int /*<<< orphan*/ * hwpoison_dir ; 
 int hwpoison_filter (struct page*) ; 
 int /*<<< orphan*/  hwpoison_filter_dev_major ; 
 int /*<<< orphan*/  hwpoison_filter_dev_minor ; 
 int /*<<< orphan*/  hwpoison_filter_enable ; 
 int /*<<< orphan*/  hwpoison_filter_flags_mask ; 
 int /*<<< orphan*/  hwpoison_filter_flags_value ; 
 int /*<<< orphan*/  hwpoison_fops ; 
 int memory_failure (unsigned long,int /*<<< orphan*/ ) ; 
 struct page* nth_page (struct page*,int) ; 
 unsigned int page_private (struct page*) ; 
 int /*<<< orphan*/  page_ref_count (struct page*) ; 
 int page_to_pfn (struct page*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  pr_info (char*,unsigned long) ; 
 int /*<<< orphan*/  put_hwpoison_page (struct page*) ; 
 int /*<<< orphan*/  set_page_count (struct page*,int) ; 
 int /*<<< orphan*/  shake_page (struct page*,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  unpoison_fops ; 
 int unpoison_memory (unsigned long) ; 

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

__attribute__((used)) static int hwpoison_inject(void *data, u64 val)
{
	unsigned long pfn = val;
	struct page *p;
	struct page *hpage;
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	if (!pfn_valid(pfn))
		return -ENXIO;

	p = pfn_to_page(pfn);
	hpage = compound_head(p);
	/*
	 * This implies unable to support free buddy pages.
	 */
	if (!get_hwpoison_page(p))
		return 0;

	if (!hwpoison_filter_enable)
		goto inject;

	shake_page(hpage, 0);
	/*
	 * This implies unable to support non-LRU pages.
	 */
	if (!PageLRU(hpage) && !PageHuge(p))
		goto put_out;

	/*
	 * do a racy check with elevated page count, to make sure PG_hwpoison
	 * will only be set for the targeted owner (or on a free page).
	 * memory_failure() will redo the check reliably inside page lock.
	 */
	err = hwpoison_filter(hpage);
	if (err)
		goto put_out;

inject:
	pr_info("Injecting memory failure at pfn %#lx\n", pfn);
	return memory_failure(pfn, MF_COUNT_INCREASED);
put_out:
	put_hwpoison_page(p);
	return 0;
}

__attribute__((used)) static int hwpoison_unpoison(void *data, u64 val)
{
	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	return unpoison_memory(val);
}

__attribute__((used)) static void pfn_inject_exit(void)
{
	debugfs_remove_recursive(hwpoison_dir);
}

__attribute__((used)) static int pfn_inject_init(void)
{
	struct dentry *dentry;

	hwpoison_dir = debugfs_create_dir("hwpoison", NULL);
	if (hwpoison_dir == NULL)
		return -ENOMEM;

	/*
	 * Note that the below poison/unpoison interfaces do not involve
	 * hardware status change, hence do not require hardware support.
	 * They are mainly for testing hwpoison in software level.
	 */
	dentry = debugfs_create_file("corrupt-pfn", 0200, hwpoison_dir,
					  NULL, &hwpoison_fops);
	if (!dentry)
		goto fail;

	dentry = debugfs_create_file("unpoison-pfn", 0200, hwpoison_dir,
				     NULL, &unpoison_fops);
	if (!dentry)
		goto fail;

	dentry = debugfs_create_u32("corrupt-filter-enable", 0600,
				    hwpoison_dir, &hwpoison_filter_enable);
	if (!dentry)
		goto fail;

	dentry = debugfs_create_u32("corrupt-filter-dev-major", 0600,
				    hwpoison_dir, &hwpoison_filter_dev_major);
	if (!dentry)
		goto fail;

	dentry = debugfs_create_u32("corrupt-filter-dev-minor", 0600,
				    hwpoison_dir, &hwpoison_filter_dev_minor);
	if (!dentry)
		goto fail;

	dentry = debugfs_create_u64("corrupt-filter-flags-mask", 0600,
				    hwpoison_dir, &hwpoison_filter_flags_mask);
	if (!dentry)
		goto fail;

	dentry = debugfs_create_u64("corrupt-filter-flags-value", 0600,
				    hwpoison_dir, &hwpoison_filter_flags_value);
	if (!dentry)
		goto fail;

#ifdef CONFIG_MEMCG
	dentry = debugfs_create_u64("corrupt-filter-memcg", 0600,
				    hwpoison_dir, &hwpoison_filter_memcg);
	if (!dentry)
		goto fail;
#endif

	return 0;
fail:
	pfn_inject_exit();
	return -ENOMEM;
}


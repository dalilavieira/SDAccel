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
typedef  int vm_flags_t ;
typedef  scalar_t__ u64 ;
struct zone {scalar_t__ contiguous; } ;
struct vm_area_struct {int vm_flags; } ;
struct radix_tree_node {int dummy; } ;
struct pagevec {int nr; struct page** pages; } ;
struct page {scalar_t__ index; struct address_space* mapping; } ;
struct mm_struct {int dummy; } ;
struct inode {int i_size; struct address_space* i_mapping; } ;
struct file_ra_state {int /*<<< orphan*/  async_size; int /*<<< orphan*/  size; int /*<<< orphan*/  start; } ;
struct file {int dummy; } ;
struct address_space {scalar_t__ nrexceptional; scalar_t__ nrpages; TYPE_2__* a_ops; int /*<<< orphan*/  i_pages; TYPE_1__* host; } ;
typedef  scalar_t__ pgoff_t ;
typedef  int loff_t ;
typedef  enum mminit_level { ____Placeholder_mminit_level } mminit_level ;
typedef  enum migratetype { ____Placeholder_migratetype } migratetype ;
struct TYPE_4__ {void (* invalidatepage ) (struct page*,unsigned int,unsigned int) ;int (* launder_page ) (struct page*) ;int /*<<< orphan*/  (* freepage ) (struct page*) ;} ;
struct TYPE_3__ {int /*<<< orphan*/  i_mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (scalar_t__) ; 
 int /*<<< orphan*/  ClearPageMappedToDisk (struct page*) ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HPAGE_PMD_NR ; 
 int MAX_ORDER_NR_PAGES ; 
 int MIGRATE_HIGHATOMIC ; 
 int PAGEVEC_SIZE ; 
 int PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 scalar_t__ PageDirty (struct page*) ; 
 int /*<<< orphan*/  PageTail (struct page*) ; 
 scalar_t__ PageTransHuge (struct page*) ; 
 scalar_t__ PageTransTail (struct page*) ; 
 scalar_t__ PageWriteback (struct page*) ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VM_BUG_ON_PAGE (int /*<<< orphan*/ ,struct page*) ; 
 int VM_EXEC ; 
 int VM_HUGETLB ; 
 int VM_LOCKED ; 
 int VM_MAYWRITE ; 
 int VM_PFNMAP ; 
 int VM_SHARED ; 
 int VM_STACK ; 
 int VM_WRITE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __delete_from_page_cache (struct page*,int /*<<< orphan*/ *) ; 
 unsigned long __do_page_cache_readahead (struct address_space*,struct file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct page* __pageblock_pfn_to_page (unsigned long,unsigned long,struct zone*) ; 
 int /*<<< orphan*/  __radix_tree_lookup (int /*<<< orphan*/ *,scalar_t__,struct radix_tree_node**,void***) ; 
 int /*<<< orphan*/  __radix_tree_replace (int /*<<< orphan*/ *,struct radix_tree_node*,void**,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cancel_dirty_page (struct page*) ; 
 int /*<<< orphan*/  cleancache_invalidate_inode (struct address_space*) ; 
 int /*<<< orphan*/  cleancache_invalidate_page (struct address_space*,struct page*) ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  dax_delete_mapping_entry (struct address_space*,scalar_t__) ; 
 int dax_invalidate_mapping_entry_sync (struct address_space*,scalar_t__) ; 
 int dax_mapping (struct address_space*) ; 
 int /*<<< orphan*/  deactivate_file_page (struct page*) ; 
 int /*<<< orphan*/  delete_from_page_cache (struct page*) ; 
 int /*<<< orphan*/  delete_from_page_cache_batch (struct address_space*,struct pagevec*) ; 
 struct page* find_lock_page (struct address_space*,scalar_t__) ; 
 int get_pageblock_migratetype (struct page*) ; 
 int i_blocksize (struct inode*) ; 
 int /*<<< orphan*/  i_size_write (struct inode*,int) ; 
 int /*<<< orphan*/  lock_page (struct page*) ; 
 int /*<<< orphan*/  mapping_set_exiting (struct address_space*) ; 
 scalar_t__ min (scalar_t__,scalar_t__) ; 
 struct page* nth_page (struct page*,int) ; 
 scalar_t__ page_has_private (struct page*) ; 
 scalar_t__ page_mapped (struct page*) ; 
 struct address_space* page_mapping (struct page*) ; 
 scalar_t__ page_mkclean (struct page*) ; 
 unsigned int page_private (struct page*) ; 
 int /*<<< orphan*/  page_ref_count (struct page*) ; 
 scalar_t__ page_to_index (struct page*) ; 
 int page_to_pfn (struct page*) ; 
 void pagecache_isize_extended (struct inode*,int,int) ; 
 int /*<<< orphan*/  pagevec_add (struct pagevec*,struct page*) ; 
 int pagevec_count (struct pagevec*) ; 
 int /*<<< orphan*/  pagevec_init (struct pagevec*) ; 
 scalar_t__ pagevec_lookup_entries (struct pagevec*,struct address_space*,scalar_t__,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  pagevec_release (struct pagevec*) ; 
 int /*<<< orphan*/  pagevec_remove_exceptionals (struct pagevec*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 scalar_t__ radix_tree_exceptional_entry (struct page*) ; 
 int remove_mapping (struct address_space*,struct page*) ; 
 int round_down (int,int) ; 
 int round_up (int,int) ; 
 int /*<<< orphan*/  set_page_count (struct page*,int) ; 
 int /*<<< orphan*/  set_page_dirty (struct page*) ; 
 scalar_t__ shmem_mapping (struct address_space*) ; 
 int /*<<< orphan*/  smp_rmb () ; 
 void stub1 (struct page*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  stub2 (struct page*) ; 
 int stub3 (struct page*) ; 
 int /*<<< orphan*/  try_to_release_page (struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trylock_page (struct page*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  unlock_page (struct page*) ; 
 int /*<<< orphan*/  unmap_mapping_pages (struct address_space*,scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  unmap_mapping_range (struct address_space*,int,int,int) ; 
 int /*<<< orphan*/  wait_on_page_writeback (struct page*) ; 
 int /*<<< orphan*/  workingset_update_node ; 
 int /*<<< orphan*/  xa_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xa_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  xa_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xa_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  zero_user_segment (struct page*,unsigned int,unsigned int) ; 

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

__attribute__((used)) static inline void __clear_shadow_entry(struct address_space *mapping,
				pgoff_t index, void *entry)
{
	struct radix_tree_node *node;
	void **slot;

	if (!__radix_tree_lookup(&mapping->i_pages, index, &node, &slot))
		return;
	if (*slot != entry)
		return;
	__radix_tree_replace(&mapping->i_pages, node, slot, NULL,
			     workingset_update_node);
	mapping->nrexceptional--;
}

__attribute__((used)) static void clear_shadow_entry(struct address_space *mapping, pgoff_t index,
			       void *entry)
{
	xa_lock_irq(&mapping->i_pages);
	__clear_shadow_entry(mapping, index, entry);
	xa_unlock_irq(&mapping->i_pages);
}

__attribute__((used)) static void truncate_exceptional_pvec_entries(struct address_space *mapping,
				struct pagevec *pvec, pgoff_t *indices,
				pgoff_t end)
{
	int i, j;
	bool dax, lock;

	/* Handled by shmem itself */
	if (shmem_mapping(mapping))
		return;

	for (j = 0; j < pagevec_count(pvec); j++)
		if (radix_tree_exceptional_entry(pvec->pages[j]))
			break;

	if (j == pagevec_count(pvec))
		return;

	dax = dax_mapping(mapping);
	lock = !dax && indices[j] < end;
	if (lock)
		xa_lock_irq(&mapping->i_pages);

	for (i = j; i < pagevec_count(pvec); i++) {
		struct page *page = pvec->pages[i];
		pgoff_t index = indices[i];

		if (!radix_tree_exceptional_entry(page)) {
			pvec->pages[j++] = page;
			continue;
		}

		if (index >= end)
			continue;

		if (unlikely(dax)) {
			dax_delete_mapping_entry(mapping, index);
			continue;
		}

		__clear_shadow_entry(mapping, index, page);
	}

	if (lock)
		xa_unlock_irq(&mapping->i_pages);
	pvec->nr = j;
}

__attribute__((used)) static int invalidate_exceptional_entry(struct address_space *mapping,
					pgoff_t index, void *entry)
{
	/* Handled by shmem itself, or for DAX we do nothing. */
	if (shmem_mapping(mapping) || dax_mapping(mapping))
		return 1;
	clear_shadow_entry(mapping, index, entry);
	return 1;
}

__attribute__((used)) static int invalidate_exceptional_entry2(struct address_space *mapping,
					 pgoff_t index, void *entry)
{
	/* Handled by shmem itself */
	if (shmem_mapping(mapping))
		return 1;
	if (dax_mapping(mapping))
		return dax_invalidate_mapping_entry_sync(mapping, index);
	clear_shadow_entry(mapping, index, entry);
	return 1;
}

void do_invalidatepage(struct page *page, unsigned int offset,
		       unsigned int length)
{
	void (*invalidatepage)(struct page *, unsigned int, unsigned int);

	invalidatepage = page->mapping->a_ops->invalidatepage;
#ifdef CONFIG_BLOCK
	if (!invalidatepage)
		invalidatepage = block_invalidatepage;
#endif
	if (invalidatepage)
		(*invalidatepage)(page, offset, length);
}

__attribute__((used)) static void
truncate_cleanup_page(struct address_space *mapping, struct page *page)
{
	if (page_mapped(page)) {
		pgoff_t nr = PageTransHuge(page) ? HPAGE_PMD_NR : 1;
		unmap_mapping_pages(mapping, page->index, nr, false);
	}

	if (page_has_private(page))
		do_invalidatepage(page, 0, PAGE_SIZE);

	/*
	 * Some filesystems seem to re-dirty the page even after
	 * the VM has canceled the dirty bit (eg ext3 journaling).
	 * Hence dirty accounting check is placed after invalidation.
	 */
	cancel_dirty_page(page);
	ClearPageMappedToDisk(page);
}

__attribute__((used)) static int
invalidate_complete_page(struct address_space *mapping, struct page *page)
{
	int ret;

	if (page->mapping != mapping)
		return 0;

	if (page_has_private(page) && !try_to_release_page(page, 0))
		return 0;

	ret = remove_mapping(mapping, page);

	return ret;
}

int truncate_inode_page(struct address_space *mapping, struct page *page)
{
	VM_BUG_ON_PAGE(PageTail(page), page);

	if (page->mapping != mapping)
		return -EIO;

	truncate_cleanup_page(mapping, page);
	delete_from_page_cache(page);
	return 0;
}

int generic_error_remove_page(struct address_space *mapping, struct page *page)
{
	if (!mapping)
		return -EINVAL;
	/*
	 * Only punch for normal data pages for now.
	 * Handling other types like directories would need more auditing.
	 */
	if (!S_ISREG(mapping->host->i_mode))
		return -EIO;
	return truncate_inode_page(mapping, page);
}

int invalidate_inode_page(struct page *page)
{
	struct address_space *mapping = page_mapping(page);
	if (!mapping)
		return 0;
	if (PageDirty(page) || PageWriteback(page))
		return 0;
	if (page_mapped(page))
		return 0;
	return invalidate_complete_page(mapping, page);
}

void truncate_inode_pages_range(struct address_space *mapping,
				loff_t lstart, loff_t lend)
{
	pgoff_t		start;		/* inclusive */
	pgoff_t		end;		/* exclusive */
	unsigned int	partial_start;	/* inclusive */
	unsigned int	partial_end;	/* exclusive */
	struct pagevec	pvec;
	pgoff_t		indices[PAGEVEC_SIZE];
	pgoff_t		index;
	int		i;

	if (mapping->nrpages == 0 && mapping->nrexceptional == 0)
		goto out;

	/* Offsets within partial pages */
	partial_start = lstart & (PAGE_SIZE - 1);
	partial_end = (lend + 1) & (PAGE_SIZE - 1);

	/*
	 * 'start' and 'end' always covers the range of pages to be fully
	 * truncated. Partial pages are covered with 'partial_start' at the
	 * start of the range and 'partial_end' at the end of the range.
	 * Note that 'end' is exclusive while 'lend' is inclusive.
	 */
	start = (lstart + PAGE_SIZE - 1) >> PAGE_SHIFT;
	if (lend == -1)
		/*
		 * lend == -1 indicates end-of-file so we have to set 'end'
		 * to the highest possible pgoff_t and since the type is
		 * unsigned we're using -1.
		 */
		end = -1;
	else
		end = (lend + 1) >> PAGE_SHIFT;

	pagevec_init(&pvec);
	index = start;
	while (index < end && pagevec_lookup_entries(&pvec, mapping, index,
			min(end - index, (pgoff_t)PAGEVEC_SIZE),
			indices)) {
		/*
		 * Pagevec array has exceptional entries and we may also fail
		 * to lock some pages. So we store pages that can be deleted
		 * in a new pagevec.
		 */
		struct pagevec locked_pvec;

		pagevec_init(&locked_pvec);
		for (i = 0; i < pagevec_count(&pvec); i++) {
			struct page *page = pvec.pages[i];

			/* We rely upon deletion not changing page->index */
			index = indices[i];
			if (index >= end)
				break;

			if (radix_tree_exceptional_entry(page))
				continue;

			if (!trylock_page(page))
				continue;
			WARN_ON(page_to_index(page) != index);
			if (PageWriteback(page)) {
				unlock_page(page);
				continue;
			}
			if (page->mapping != mapping) {
				unlock_page(page);
				continue;
			}
			pagevec_add(&locked_pvec, page);
		}
		for (i = 0; i < pagevec_count(&locked_pvec); i++)
			truncate_cleanup_page(mapping, locked_pvec.pages[i]);
		delete_from_page_cache_batch(mapping, &locked_pvec);
		for (i = 0; i < pagevec_count(&locked_pvec); i++)
			unlock_page(locked_pvec.pages[i]);
		truncate_exceptional_pvec_entries(mapping, &pvec, indices, end);
		pagevec_release(&pvec);
		cond_resched();
		index++;
	}
	if (partial_start) {
		struct page *page = find_lock_page(mapping, start - 1);
		if (page) {
			unsigned int top = PAGE_SIZE;
			if (start > end) {
				/* Truncation within a single page */
				top = partial_end;
				partial_end = 0;
			}
			wait_on_page_writeback(page);
			zero_user_segment(page, partial_start, top);
			cleancache_invalidate_page(mapping, page);
			if (page_has_private(page))
				do_invalidatepage(page, partial_start,
						  top - partial_start);
			unlock_page(page);
			put_page(page);
		}
	}
	if (partial_end) {
		struct page *page = find_lock_page(mapping, end);
		if (page) {
			wait_on_page_writeback(page);
			zero_user_segment(page, 0, partial_end);
			cleancache_invalidate_page(mapping, page);
			if (page_has_private(page))
				do_invalidatepage(page, 0,
						  partial_end);
			unlock_page(page);
			put_page(page);
		}
	}
	/*
	 * If the truncation happened within a single page no pages
	 * will be released, just zeroed, so we can bail out now.
	 */
	if (start >= end)
		goto out;

	index = start;
	for ( ; ; ) {
		cond_resched();
		if (!pagevec_lookup_entries(&pvec, mapping, index,
			min(end - index, (pgoff_t)PAGEVEC_SIZE), indices)) {
			/* If all gone from start onwards, we're done */
			if (index == start)
				break;
			/* Otherwise restart to make sure all gone */
			index = start;
			continue;
		}
		if (index == start && indices[0] >= end) {
			/* All gone out of hole to be punched, we're done */
			pagevec_remove_exceptionals(&pvec);
			pagevec_release(&pvec);
			break;
		}

		for (i = 0; i < pagevec_count(&pvec); i++) {
			struct page *page = pvec.pages[i];

			/* We rely upon deletion not changing page->index */
			index = indices[i];
			if (index >= end) {
				/* Restart punch to make sure all gone */
				index = start - 1;
				break;
			}

			if (radix_tree_exceptional_entry(page))
				continue;

			lock_page(page);
			WARN_ON(page_to_index(page) != index);
			wait_on_page_writeback(page);
			truncate_inode_page(mapping, page);
			unlock_page(page);
		}
		truncate_exceptional_pvec_entries(mapping, &pvec, indices, end);
		pagevec_release(&pvec);
		index++;
	}

out:
	cleancache_invalidate_inode(mapping);
}

void truncate_inode_pages(struct address_space *mapping, loff_t lstart)
{
	truncate_inode_pages_range(mapping, lstart, (loff_t)-1);
}

void truncate_inode_pages_final(struct address_space *mapping)
{
	unsigned long nrexceptional;
	unsigned long nrpages;

	/*
	 * Page reclaim can not participate in regular inode lifetime
	 * management (can't call iput()) and thus can race with the
	 * inode teardown.  Tell it when the address space is exiting,
	 * so that it does not install eviction information after the
	 * final truncate has begun.
	 */
	mapping_set_exiting(mapping);

	/*
	 * When reclaim installs eviction entries, it increases
	 * nrexceptional first, then decreases nrpages.  Make sure we see
	 * this in the right order or we might miss an entry.
	 */
	nrpages = mapping->nrpages;
	smp_rmb();
	nrexceptional = mapping->nrexceptional;

	if (nrpages || nrexceptional) {
		/*
		 * As truncation uses a lockless tree lookup, cycle
		 * the tree lock to make sure any ongoing tree
		 * modification that does not see AS_EXITING is
		 * completed before starting the final truncate.
		 */
		xa_lock_irq(&mapping->i_pages);
		xa_unlock_irq(&mapping->i_pages);
	}

	/*
	 * Cleancache needs notification even if there are no pages or shadow
	 * entries.
	 */
	truncate_inode_pages(mapping, 0);
}

unsigned long invalidate_mapping_pages(struct address_space *mapping,
		pgoff_t start, pgoff_t end)
{
	pgoff_t indices[PAGEVEC_SIZE];
	struct pagevec pvec;
	pgoff_t index = start;
	unsigned long ret;
	unsigned long count = 0;
	int i;

	pagevec_init(&pvec);
	while (index <= end && pagevec_lookup_entries(&pvec, mapping, index,
			min(end - index, (pgoff_t)PAGEVEC_SIZE - 1) + 1,
			indices)) {
		for (i = 0; i < pagevec_count(&pvec); i++) {
			struct page *page = pvec.pages[i];

			/* We rely upon deletion not changing page->index */
			index = indices[i];
			if (index > end)
				break;

			if (radix_tree_exceptional_entry(page)) {
				invalidate_exceptional_entry(mapping, index,
							     page);
				continue;
			}

			if (!trylock_page(page))
				continue;

			WARN_ON(page_to_index(page) != index);

			/* Middle of THP: skip */
			if (PageTransTail(page)) {
				unlock_page(page);
				continue;
			} else if (PageTransHuge(page)) {
				index += HPAGE_PMD_NR - 1;
				i += HPAGE_PMD_NR - 1;
				/*
				 * 'end' is in the middle of THP. Don't
				 * invalidate the page as the part outside of
				 * 'end' could be still useful.
				 */
				if (index > end) {
					unlock_page(page);
					continue;
				}
			}

			ret = invalidate_inode_page(page);
			unlock_page(page);
			/*
			 * Invalidation is a hint that the page is no longer
			 * of interest and try to speed up its reclaim.
			 */
			if (!ret)
				deactivate_file_page(page);
			count += ret;
		}
		pagevec_remove_exceptionals(&pvec);
		pagevec_release(&pvec);
		cond_resched();
		index++;
	}
	return count;
}

__attribute__((used)) static int
invalidate_complete_page2(struct address_space *mapping, struct page *page)
{
	unsigned long flags;

	if (page->mapping != mapping)
		return 0;

	if (page_has_private(page) && !try_to_release_page(page, GFP_KERNEL))
		return 0;

	xa_lock_irqsave(&mapping->i_pages, flags);
	if (PageDirty(page))
		goto failed;

	BUG_ON(page_has_private(page));
	__delete_from_page_cache(page, NULL);
	xa_unlock_irqrestore(&mapping->i_pages, flags);

	if (mapping->a_ops->freepage)
		mapping->a_ops->freepage(page);

	put_page(page);	/* pagecache ref */
	return 1;
failed:
	xa_unlock_irqrestore(&mapping->i_pages, flags);
	return 0;
}

__attribute__((used)) static int do_launder_page(struct address_space *mapping, struct page *page)
{
	if (!PageDirty(page))
		return 0;
	if (page->mapping != mapping || mapping->a_ops->launder_page == NULL)
		return 0;
	return mapping->a_ops->launder_page(page);
}

int invalidate_inode_pages2_range(struct address_space *mapping,
				  pgoff_t start, pgoff_t end)
{
	pgoff_t indices[PAGEVEC_SIZE];
	struct pagevec pvec;
	pgoff_t index;
	int i;
	int ret = 0;
	int ret2 = 0;
	int did_range_unmap = 0;

	if (mapping->nrpages == 0 && mapping->nrexceptional == 0)
		goto out;

	pagevec_init(&pvec);
	index = start;
	while (index <= end && pagevec_lookup_entries(&pvec, mapping, index,
			min(end - index, (pgoff_t)PAGEVEC_SIZE - 1) + 1,
			indices)) {
		for (i = 0; i < pagevec_count(&pvec); i++) {
			struct page *page = pvec.pages[i];

			/* We rely upon deletion not changing page->index */
			index = indices[i];
			if (index > end)
				break;

			if (radix_tree_exceptional_entry(page)) {
				if (!invalidate_exceptional_entry2(mapping,
								   index, page))
					ret = -EBUSY;
				continue;
			}

			lock_page(page);
			WARN_ON(page_to_index(page) != index);
			if (page->mapping != mapping) {
				unlock_page(page);
				continue;
			}
			wait_on_page_writeback(page);
			if (page_mapped(page)) {
				if (!did_range_unmap) {
					/*
					 * Zap the rest of the file in one hit.
					 */
					unmap_mapping_pages(mapping, index,
						(1 + end - index), false);
					did_range_unmap = 1;
				} else {
					/*
					 * Just zap this page
					 */
					unmap_mapping_pages(mapping, index,
								1, false);
				}
			}
			BUG_ON(page_mapped(page));
			ret2 = do_launder_page(mapping, page);
			if (ret2 == 0) {
				if (!invalidate_complete_page2(mapping, page))
					ret2 = -EBUSY;
			}
			if (ret2 < 0)
				ret = ret2;
			unlock_page(page);
		}
		pagevec_remove_exceptionals(&pvec);
		pagevec_release(&pvec);
		cond_resched();
		index++;
	}
	/*
	 * For DAX we invalidate page tables after invalidating radix tree.  We
	 * could invalidate page tables while invalidating each entry however
	 * that would be expensive. And doing range unmapping before doesn't
	 * work as we have no cheap way to find whether radix tree entry didn't
	 * get remapped later.
	 */
	if (dax_mapping(mapping)) {
		unmap_mapping_pages(mapping, start, end - start + 1, false);
	}
out:
	cleancache_invalidate_inode(mapping);
	return ret;
}

int invalidate_inode_pages2(struct address_space *mapping)
{
	return invalidate_inode_pages2_range(mapping, 0, -1);
}

void truncate_pagecache(struct inode *inode, loff_t newsize)
{
	struct address_space *mapping = inode->i_mapping;
	loff_t holebegin = round_up(newsize, PAGE_SIZE);

	/*
	 * unmap_mapping_range is called twice, first simply for
	 * efficiency so that truncate_inode_pages does fewer
	 * single-page unmaps.  However after this first call, and
	 * before truncate_inode_pages finishes, it is possible for
	 * private pages to be COWed, which remain after
	 * truncate_inode_pages finishes, hence the second
	 * unmap_mapping_range call must be made for correctness.
	 */
	unmap_mapping_range(mapping, holebegin, 0, 1);
	truncate_inode_pages(mapping, newsize);
	unmap_mapping_range(mapping, holebegin, 0, 1);
}

void truncate_setsize(struct inode *inode, loff_t newsize)
{
	loff_t oldsize = inode->i_size;

	i_size_write(inode, newsize);
	if (newsize > oldsize)
		pagecache_isize_extended(inode, oldsize, newsize);
	truncate_pagecache(inode, newsize);
}

void pagecache_isize_extended(struct inode *inode, loff_t from, loff_t to)
{
	int bsize = i_blocksize(inode);
	loff_t rounded_from;
	struct page *page;
	pgoff_t index;

	WARN_ON(to > inode->i_size);

	if (from >= to || bsize == PAGE_SIZE)
		return;
	/* Page straddling @from will not have any hole block created? */
	rounded_from = round_up(from, bsize);
	if (to <= rounded_from || !(rounded_from & (PAGE_SIZE - 1)))
		return;

	index = from >> PAGE_SHIFT;
	page = find_lock_page(inode->i_mapping, index);
	/* Page not cached? Nothing to do */
	if (!page)
		return;
	/*
	 * See clear_page_dirty_for_io() for details why set_page_dirty()
	 * is needed.
	 */
	if (page_mkclean(page))
		set_page_dirty(page);
	unlock_page(page);
	put_page(page);
}

void truncate_pagecache_range(struct inode *inode, loff_t lstart, loff_t lend)
{
	struct address_space *mapping = inode->i_mapping;
	loff_t unmap_start = round_up(lstart, PAGE_SIZE);
	loff_t unmap_end = round_down(1 + lend, PAGE_SIZE) - 1;
	/*
	 * This rounding is currently just for example: unmap_mapping_range
	 * expands its hole outwards, whereas we want it to contract the hole
	 * inwards.  However, existing callers of truncate_pagecache_range are
	 * doing their own page rounding first.  Note that unmap_mapping_range
	 * allows holelen 0 for all, and we allow lend -1 for end of file.
	 */

	/*
	 * Unlike in truncate_pagecache, unmap_mapping_range is called only
	 * once (before truncating pagecache), and without "even_cows" flag:
	 * hole-punching should not remove private COWed pages from the hole.
	 */
	if ((u64)unmap_end > (u64)unmap_start)
		unmap_mapping_range(mapping, unmap_start,
				    1 + unmap_end - unmap_start, 0);
	truncate_inode_pages_range(mapping, lstart, lend);
}


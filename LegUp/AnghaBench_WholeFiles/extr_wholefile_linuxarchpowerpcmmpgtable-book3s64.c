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
struct vm_area_struct {int dummy; } ;
struct spinlock {int dummy; } ;
struct page {int /*<<< orphan*/  pt_frag_refcount; } ;
struct mmu_gather {int dummy; } ;
struct TYPE_3__ {void* pte_frag; void* pmd_frag; } ;
struct mm_struct {int /*<<< orphan*/  page_table_lock; TYPE_1__ context; } ;
typedef  void pte_t ;
typedef  void pmd_t ;
typedef  int /*<<< orphan*/  phys_addr_t ;
typedef  int gfp_t ;
struct TYPE_4__ {int /*<<< orphan*/  (* hpte_clear_all ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int GFP_KERNEL_ACCOUNT ; 
 unsigned long PAGE_MASK ; 
 int PGALLOC_GFP ; 
 int /*<<< orphan*/  PGT_CACHE (int /*<<< orphan*/ ) ; 
 int PMD_FRAG_NR ; 
 int PMD_FRAG_SIZE ; 
#define  PMD_INDEX 130 
 int PTE_FRAG_NR ; 
 int PTE_FRAG_SIZE ; 
#define  PTE_INDEX 129 
 int /*<<< orphan*/  PUD_CACHE_INDEX ; 
#define  PUD_INDEX 128 
 int __GFP_ACCOUNT ; 
 int __GFP_ZERO ; 
 int /*<<< orphan*/  __free_page (struct page*) ; 
 int /*<<< orphan*/  __free_pages (struct page*,int /*<<< orphan*/ ) ; 
 struct page* alloc_page (int) ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 struct mm_struct init_mm ; 
 int /*<<< orphan*/  kmem_cache_free (int /*<<< orphan*/ ,void*) ; 
 scalar_t__ likely (int) ; 
 TYPE_2__ mmu_hash_ops ; 
 void* page_address (struct page*) ; 
 int /*<<< orphan*/  pgtable_page_ctor (struct page*) ; 
 int /*<<< orphan*/  pgtable_page_dtor (struct page*) ; 
 int /*<<< orphan*/  pgtable_pmd_page_ctor (struct page*) ; 
 int /*<<< orphan*/  pgtable_pmd_page_dtor (struct page*) ; 
 int /*<<< orphan*/  radix__mmu_cleanup_all () ; 
 scalar_t__ radix_enabled () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 () ; 
 struct page* virt_to_page (unsigned long*) ; 
 scalar_t__ vma_is_anonymous (struct vm_area_struct*) ; 

__attribute__((used)) static inline phys_addr_t v_block_mapped(unsigned long va) { return 0; }

__attribute__((used)) static inline unsigned long p_block_mapped(phys_addr_t pa) { return 0; }

void mmu_cleanup_all(void)
{
	if (radix_enabled())
		radix__mmu_cleanup_all();
	else if (mmu_hash_ops.hpte_clear_all)
		mmu_hash_ops.hpte_clear_all();
}

__attribute__((used)) static pmd_t *get_pmd_from_cache(struct mm_struct *mm)
{
	void *pmd_frag, *ret;

	spin_lock(&mm->page_table_lock);
	ret = mm->context.pmd_frag;
	if (ret) {
		pmd_frag = ret + PMD_FRAG_SIZE;
		/*
		 * If we have taken up all the fragments mark PTE page NULL
		 */
		if (((unsigned long)pmd_frag & ~PAGE_MASK) == 0)
			pmd_frag = NULL;
		mm->context.pmd_frag = pmd_frag;
	}
	spin_unlock(&mm->page_table_lock);
	return (pmd_t *)ret;
}

__attribute__((used)) static pmd_t *__alloc_for_pmdcache(struct mm_struct *mm)
{
	void *ret = NULL;
	struct page *page;
	gfp_t gfp = GFP_KERNEL_ACCOUNT | __GFP_ZERO;

	if (mm == &init_mm)
		gfp &= ~__GFP_ACCOUNT;
	page = alloc_page(gfp);
	if (!page)
		return NULL;
	if (!pgtable_pmd_page_ctor(page)) {
		__free_pages(page, 0);
		return NULL;
	}

	atomic_set(&page->pt_frag_refcount, 1);

	ret = page_address(page);
	/*
	 * if we support only one fragment just return the
	 * allocated page.
	 */
	if (PMD_FRAG_NR == 1)
		return ret;

	spin_lock(&mm->page_table_lock);
	/*
	 * If we find pgtable_page set, we return
	 * the allocated page with single fragement
	 * count.
	 */
	if (likely(!mm->context.pmd_frag)) {
		atomic_set(&page->pt_frag_refcount, PMD_FRAG_NR);
		mm->context.pmd_frag = ret + PMD_FRAG_SIZE;
	}
	spin_unlock(&mm->page_table_lock);

	return (pmd_t *)ret;
}

pmd_t *pmd_fragment_alloc(struct mm_struct *mm, unsigned long vmaddr)
{
	pmd_t *pmd;

	pmd = get_pmd_from_cache(mm);
	if (pmd)
		return pmd;

	return __alloc_for_pmdcache(mm);
}

void pmd_fragment_free(unsigned long *pmd)
{
	struct page *page = virt_to_page(pmd);

	BUG_ON(atomic_read(&page->pt_frag_refcount) <= 0);
	if (atomic_dec_and_test(&page->pt_frag_refcount)) {
		pgtable_pmd_page_dtor(page);
		__free_page(page);
	}
}

__attribute__((used)) static pte_t *get_pte_from_cache(struct mm_struct *mm)
{
	void *pte_frag, *ret;

	spin_lock(&mm->page_table_lock);
	ret = mm->context.pte_frag;
	if (ret) {
		pte_frag = ret + PTE_FRAG_SIZE;
		/*
		 * If we have taken up all the fragments mark PTE page NULL
		 */
		if (((unsigned long)pte_frag & ~PAGE_MASK) == 0)
			pte_frag = NULL;
		mm->context.pte_frag = pte_frag;
	}
	spin_unlock(&mm->page_table_lock);
	return (pte_t *)ret;
}

__attribute__((used)) static pte_t *__alloc_for_ptecache(struct mm_struct *mm, int kernel)
{
	void *ret = NULL;
	struct page *page;

	if (!kernel) {
		page = alloc_page(PGALLOC_GFP | __GFP_ACCOUNT);
		if (!page)
			return NULL;
		if (!pgtable_page_ctor(page)) {
			__free_page(page);
			return NULL;
		}
	} else {
		page = alloc_page(PGALLOC_GFP);
		if (!page)
			return NULL;
	}

	atomic_set(&page->pt_frag_refcount, 1);

	ret = page_address(page);
	/*
	 * if we support only one fragment just return the
	 * allocated page.
	 */
	if (PTE_FRAG_NR == 1)
		return ret;
	spin_lock(&mm->page_table_lock);
	/*
	 * If we find pgtable_page set, we return
	 * the allocated page with single fragement
	 * count.
	 */
	if (likely(!mm->context.pte_frag)) {
		atomic_set(&page->pt_frag_refcount, PTE_FRAG_NR);
		mm->context.pte_frag = ret + PTE_FRAG_SIZE;
	}
	spin_unlock(&mm->page_table_lock);

	return (pte_t *)ret;
}

pte_t *pte_fragment_alloc(struct mm_struct *mm, unsigned long vmaddr, int kernel)
{
	pte_t *pte;

	pte = get_pte_from_cache(mm);
	if (pte)
		return pte;

	return __alloc_for_ptecache(mm, kernel);
}

void pte_fragment_free(unsigned long *table, int kernel)
{
	struct page *page = virt_to_page(table);

	BUG_ON(atomic_read(&page->pt_frag_refcount) <= 0);
	if (atomic_dec_and_test(&page->pt_frag_refcount)) {
		if (!kernel)
			pgtable_page_dtor(page);
		__free_page(page);
	}
}

__attribute__((used)) static inline void pgtable_free(void *table, int index)
{
	switch (index) {
	case PTE_INDEX:
		pte_fragment_free(table, 0);
		break;
	case PMD_INDEX:
		pmd_fragment_free(table);
		break;
	case PUD_INDEX:
		kmem_cache_free(PGT_CACHE(PUD_CACHE_INDEX), table);
		break;
#if defined(CONFIG_PPC_4K_PAGES) && defined(CONFIG_HUGETLB_PAGE)
		/* 16M hugepd directory at pud level */
	case HTLB_16M_INDEX:
		BUILD_BUG_ON(H_16M_CACHE_INDEX <= 0);
		kmem_cache_free(PGT_CACHE(H_16M_CACHE_INDEX), table);
		break;
		/* 16G hugepd directory at the pgd level */
	case HTLB_16G_INDEX:
		BUILD_BUG_ON(H_16G_CACHE_INDEX <= 0);
		kmem_cache_free(PGT_CACHE(H_16G_CACHE_INDEX), table);
		break;
#endif
		/* We don't free pgd table via RCU callback */
	default:
		BUG();
	}
}

void pgtable_free_tlb(struct mmu_gather *tlb, void *table, int index)
{
	return pgtable_free(table, index);
}

int pmd_move_must_withdraw(struct spinlock *new_pmd_ptl,
			   struct spinlock *old_pmd_ptl,
			   struct vm_area_struct *vma)
{
	if (radix_enabled())
		return (new_pmd_ptl != old_pmd_ptl) && vma_is_anonymous(vma);

	return true;
}


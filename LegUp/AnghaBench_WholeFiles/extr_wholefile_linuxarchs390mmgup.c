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
struct page {int dummy; } ;
struct TYPE_3__ {unsigned long asce_limit; } ;
struct mm_struct {TYPE_1__ context; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
typedef  int /*<<< orphan*/  p4d_t ;
struct TYPE_4__ {struct mm_struct* mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  FOLL_WRITE ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 unsigned long PMD_MASK ; 
 unsigned long PUD_MASK ; 
 int /*<<< orphan*/  VM_BUG_ON (int) ; 
 int /*<<< orphan*/  VM_BUG_ON_PAGE (int,struct page*) ; 
 unsigned long _PAGE_INVALID ; 
 unsigned long _PAGE_PROTECT ; 
 unsigned long _PAGE_SPECIAL ; 
 unsigned long _REGION_ENTRY_INVALID ; 
 unsigned long _REGION_ENTRY_PROTECT ; 
 unsigned long _REGION_ENTRY_TYPE_MASK ; 
 unsigned long _REGION_ENTRY_TYPE_R1 ; 
 unsigned long _REGION_ENTRY_TYPE_R2 ; 
 unsigned long _REGION_ENTRY_TYPE_R3 ; 
 unsigned long _SEGMENT_ENTRY_INVALID ; 
 unsigned long _SEGMENT_ENTRY_PROTECT ; 
 int /*<<< orphan*/  barrier () ; 
 struct page* compound_head (struct page*) ; 
 TYPE_2__* current ; 
 int get_user_pages_unlocked (unsigned long,int,struct page**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  might_sleep () ; 
 unsigned long p4d_addr_end (unsigned long,unsigned long) ; 
 scalar_t__ p4d_deref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p4d_index (unsigned long) ; 
 scalar_t__ p4d_none (int /*<<< orphan*/ ) ; 
 unsigned long p4d_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  page_cache_add_speculative (struct page*,int) ; 
 int /*<<< orphan*/  page_cache_get_speculative (struct page*) ; 
 int /*<<< orphan*/  pfn_valid (unsigned long) ; 
 unsigned long pgd_addr_end (unsigned long,unsigned long) ; 
 scalar_t__ pgd_deref (int /*<<< orphan*/ ) ; 
 scalar_t__ pgd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pgd_offset (struct mm_struct*,unsigned long) ; 
 unsigned long pgd_val (int /*<<< orphan*/ ) ; 
 unsigned long pmd_addr_end (unsigned long,unsigned long) ; 
 scalar_t__ pmd_deref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmd_index (unsigned long) ; 
 int pmd_large (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_none (int /*<<< orphan*/ ) ; 
 struct page* pmd_page (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_protnone (int /*<<< orphan*/ ) ; 
 unsigned long pmd_val (int /*<<< orphan*/ ) ; 
 int pte_index (unsigned long) ; 
 struct page* pte_page (int /*<<< orphan*/ ) ; 
 unsigned long pte_pfn (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_protnone (int /*<<< orphan*/ ) ; 
 unsigned long pte_val (int /*<<< orphan*/ ) ; 
 unsigned long pud_addr_end (unsigned long,unsigned long) ; 
 scalar_t__ pud_deref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pud_index (unsigned long) ; 
 int pud_large (int /*<<< orphan*/ ) ; 
 scalar_t__ pud_none (int /*<<< orphan*/ ) ; 
 struct page* pud_page (int /*<<< orphan*/ ) ; 
 unsigned long pud_pfn (int /*<<< orphan*/ ) ; 
 unsigned long pud_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline int gup_pte_range(pmd_t *pmdp, pmd_t pmd, unsigned long addr,
		unsigned long end, int write, struct page **pages, int *nr)
{
	struct page *head, *page;
	unsigned long mask;
	pte_t *ptep, pte;

	mask = (write ? _PAGE_PROTECT : 0) | _PAGE_INVALID | _PAGE_SPECIAL;

	ptep = ((pte_t *) pmd_deref(pmd)) + pte_index(addr);
	do {
		pte = *ptep;
		barrier();
		/* Similar to the PMD case, NUMA hinting must take slow path */
		if (pte_protnone(pte))
			return 0;
		if ((pte_val(pte) & mask) != 0)
			return 0;
		VM_BUG_ON(!pfn_valid(pte_pfn(pte)));
		page = pte_page(pte);
		head = compound_head(page);
		if (!page_cache_get_speculative(head))
			return 0;
		if (unlikely(pte_val(pte) != pte_val(*ptep))) {
			put_page(head);
			return 0;
		}
		VM_BUG_ON_PAGE(compound_head(page) != head, page);
		pages[*nr] = page;
		(*nr)++;

	} while (ptep++, addr += PAGE_SIZE, addr != end);

	return 1;
}

__attribute__((used)) static inline int gup_huge_pmd(pmd_t *pmdp, pmd_t pmd, unsigned long addr,
		unsigned long end, int write, struct page **pages, int *nr)
{
	struct page *head, *page;
	unsigned long mask;
	int refs;

	mask = (write ? _SEGMENT_ENTRY_PROTECT : 0) | _SEGMENT_ENTRY_INVALID;
	if ((pmd_val(pmd) & mask) != 0)
		return 0;
	VM_BUG_ON(!pfn_valid(pmd_val(pmd) >> PAGE_SHIFT));

	refs = 0;
	head = pmd_page(pmd);
	page = head + ((addr & ~PMD_MASK) >> PAGE_SHIFT);
	do {
		VM_BUG_ON(compound_head(page) != head);
		pages[*nr] = page;
		(*nr)++;
		page++;
		refs++;
	} while (addr += PAGE_SIZE, addr != end);

	if (!page_cache_add_speculative(head, refs)) {
		*nr -= refs;
		return 0;
	}

	if (unlikely(pmd_val(pmd) != pmd_val(*pmdp))) {
		*nr -= refs;
		while (refs--)
			put_page(head);
		return 0;
	}

	return 1;
}

__attribute__((used)) static inline int gup_pmd_range(pud_t *pudp, pud_t pud, unsigned long addr,
		unsigned long end, int write, struct page **pages, int *nr)
{
	unsigned long next;
	pmd_t *pmdp, pmd;

	pmdp = (pmd_t *) pudp;
	if ((pud_val(pud) & _REGION_ENTRY_TYPE_MASK) == _REGION_ENTRY_TYPE_R3)
		pmdp = (pmd_t *) pud_deref(pud);
	pmdp += pmd_index(addr);
	do {
		pmd = *pmdp;
		barrier();
		next = pmd_addr_end(addr, end);
		if (pmd_none(pmd))
			return 0;
		if (unlikely(pmd_large(pmd))) {
			/*
			 * NUMA hinting faults need to be handled in the GUP
			 * slowpath for accounting purposes and so that they
			 * can be serialised against THP migration.
			 */
			if (pmd_protnone(pmd))
				return 0;
			if (!gup_huge_pmd(pmdp, pmd, addr, next,
					  write, pages, nr))
				return 0;
		} else if (!gup_pte_range(pmdp, pmd, addr, next,
					  write, pages, nr))
			return 0;
	} while (pmdp++, addr = next, addr != end);

	return 1;
}

__attribute__((used)) static int gup_huge_pud(pud_t *pudp, pud_t pud, unsigned long addr,
		unsigned long end, int write, struct page **pages, int *nr)
{
	struct page *head, *page;
	unsigned long mask;
	int refs;

	mask = (write ? _REGION_ENTRY_PROTECT : 0) | _REGION_ENTRY_INVALID;
	if ((pud_val(pud) & mask) != 0)
		return 0;
	VM_BUG_ON(!pfn_valid(pud_pfn(pud)));

	refs = 0;
	head = pud_page(pud);
	page = head + ((addr & ~PUD_MASK) >> PAGE_SHIFT);
	do {
		VM_BUG_ON_PAGE(compound_head(page) != head, page);
		pages[*nr] = page;
		(*nr)++;
		page++;
		refs++;
	} while (addr += PAGE_SIZE, addr != end);

	if (!page_cache_add_speculative(head, refs)) {
		*nr -= refs;
		return 0;
	}

	if (unlikely(pud_val(pud) != pud_val(*pudp))) {
		*nr -= refs;
		while (refs--)
			put_page(head);
		return 0;
	}

	return 1;
}

__attribute__((used)) static inline int gup_pud_range(p4d_t *p4dp, p4d_t p4d, unsigned long addr,
		unsigned long end, int write, struct page **pages, int *nr)
{
	unsigned long next;
	pud_t *pudp, pud;

	pudp = (pud_t *) p4dp;
	if ((p4d_val(p4d) & _REGION_ENTRY_TYPE_MASK) == _REGION_ENTRY_TYPE_R2)
		pudp = (pud_t *) p4d_deref(p4d);
	pudp += pud_index(addr);
	do {
		pud = *pudp;
		barrier();
		next = pud_addr_end(addr, end);
		if (pud_none(pud))
			return 0;
		if (unlikely(pud_large(pud))) {
			if (!gup_huge_pud(pudp, pud, addr, next, write, pages,
					  nr))
				return 0;
		} else if (!gup_pmd_range(pudp, pud, addr, next, write, pages,
					  nr))
			return 0;
	} while (pudp++, addr = next, addr != end);

	return 1;
}

__attribute__((used)) static inline int gup_p4d_range(pgd_t *pgdp, pgd_t pgd, unsigned long addr,
		unsigned long end, int write, struct page **pages, int *nr)
{
	unsigned long next;
	p4d_t *p4dp, p4d;

	p4dp = (p4d_t *) pgdp;
	if ((pgd_val(pgd) & _REGION_ENTRY_TYPE_MASK) == _REGION_ENTRY_TYPE_R1)
		p4dp = (p4d_t *) pgd_deref(pgd);
	p4dp += p4d_index(addr);
	do {
		p4d = *p4dp;
		barrier();
		next = p4d_addr_end(addr, end);
		if (p4d_none(p4d))
			return 0;
		if (!gup_pud_range(p4dp, p4d, addr, next, write, pages, nr))
			return 0;
	} while (p4dp++, addr = next, addr != end);

	return 1;
}

int __get_user_pages_fast(unsigned long start, int nr_pages, int write,
			  struct page **pages)
{
	struct mm_struct *mm = current->mm;
	unsigned long addr, len, end;
	unsigned long next, flags;
	pgd_t *pgdp, pgd;
	int nr = 0;

	start &= PAGE_MASK;
	addr = start;
	len = (unsigned long) nr_pages << PAGE_SHIFT;
	end = start + len;
	if ((end <= start) || (end > mm->context.asce_limit))
		return 0;
	/*
	 * local_irq_save() doesn't prevent pagetable teardown, but does
	 * prevent the pagetables from being freed on s390.
	 *
	 * So long as we atomically load page table pointers versus teardown,
	 * we can follow the address down to the the page and take a ref on it.
	 */
	local_irq_save(flags);
	pgdp = pgd_offset(mm, addr);
	do {
		pgd = *pgdp;
		barrier();
		next = pgd_addr_end(addr, end);
		if (pgd_none(pgd))
			break;
		if (!gup_p4d_range(pgdp, pgd, addr, next, write, pages, &nr))
			break;
	} while (pgdp++, addr = next, addr != end);
	local_irq_restore(flags);

	return nr;
}

int get_user_pages_fast(unsigned long start, int nr_pages, int write,
			struct page **pages)
{
	int nr, ret;

	might_sleep();
	start &= PAGE_MASK;
	nr = __get_user_pages_fast(start, nr_pages, write, pages);
	if (nr == nr_pages)
		return nr;

	/* Try to get the remaining pages with get_user_pages */
	start += nr << PAGE_SHIFT;
	pages += nr;
	ret = get_user_pages_unlocked(start, nr_pages - nr, pages,
				      write ? FOLL_WRITE : 0);
	/* Have to be a bit careful with return values */
	if (nr > 0)
		ret = (ret < 0) ? nr : ret + nr;
	return ret;
}


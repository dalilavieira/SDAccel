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
struct vm_unmapped_area_info {unsigned long length; unsigned long low_limit; unsigned long high_limit; int align_mask; scalar_t__ align_offset; scalar_t__ flags; } ;
struct page {int dummy; } ;
struct mmu_gather {int dummy; } ;
struct mm_struct {int dummy; } ;
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;

/* Variables and functions */
 int EINVAL ; 
 unsigned long ENOMEM ; 
 struct page* ERR_PTR (int) ; 
 unsigned long HPAGE_MASK ; 
 unsigned long HPAGE_REGION_BASE ; 
 int HPAGE_SIZE ; 
 unsigned long MAP_FIXED ; 
 int PAGE_MASK ; 
 unsigned long PAGE_SHIFT ; 
 scalar_t__ REGION_NUMBER (unsigned long) ; 
 scalar_t__ RGN_HPAGE ; 
 unsigned long RGN_MAP_LIMIT ; 
 int /*<<< orphan*/  free_pgd_range (struct mmu_gather*,unsigned long,unsigned long,unsigned long,unsigned long) ; 
 unsigned long htlbpage_to_page (unsigned long) ; 
 int /*<<< orphan*/ * pgd_offset (struct mm_struct*,unsigned long) ; 
 scalar_t__ pgd_present (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_alloc (struct mm_struct*,int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pmd_present (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pte_alloc_map (struct mm_struct*,int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pte_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pte_offset_map (int /*<<< orphan*/ *,unsigned long) ; 
 struct page* pte_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_alloc (struct mm_struct*,int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pud_present (int /*<<< orphan*/ ) ; 
 unsigned long vm_unmapped_area (struct vm_unmapped_area_info*) ; 

pte_t *
huge_pte_alloc(struct mm_struct *mm, unsigned long addr, unsigned long sz)
{
	unsigned long taddr = htlbpage_to_page(addr);
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte = NULL;

	pgd = pgd_offset(mm, taddr);
	pud = pud_alloc(mm, pgd, taddr);
	if (pud) {
		pmd = pmd_alloc(mm, pud, taddr);
		if (pmd)
			pte = pte_alloc_map(mm, pmd, taddr);
	}
	return pte;
}

pte_t *
huge_pte_offset (struct mm_struct *mm, unsigned long addr, unsigned long sz)
{
	unsigned long taddr = htlbpage_to_page(addr);
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte = NULL;

	pgd = pgd_offset(mm, taddr);
	if (pgd_present(*pgd)) {
		pud = pud_offset(pgd, taddr);
		if (pud_present(*pud)) {
			pmd = pmd_offset(pud, taddr);
			if (pmd_present(*pmd))
				pte = pte_offset_map(pmd, taddr);
		}
	}

	return pte;
}

int prepare_hugepage_range(struct file *file,
			unsigned long addr, unsigned long len)
{
	if (len & ~HPAGE_MASK)
		return -EINVAL;
	if (addr & ~HPAGE_MASK)
		return -EINVAL;
	if (REGION_NUMBER(addr) != RGN_HPAGE)
		return -EINVAL;

	return 0;
}

struct page *follow_huge_addr(struct mm_struct *mm, unsigned long addr, int write)
{
	struct page *page;
	pte_t *ptep;

	if (REGION_NUMBER(addr) != RGN_HPAGE)
		return ERR_PTR(-EINVAL);

	ptep = huge_pte_offset(mm, addr, HPAGE_SIZE);
	if (!ptep || pte_none(*ptep))
		return NULL;
	page = pte_page(*ptep);
	page += ((addr & ~HPAGE_MASK) >> PAGE_SHIFT);
	return page;
}

int pmd_huge(pmd_t pmd)
{
	return 0;
}

int pud_huge(pud_t pud)
{
	return 0;
}

void hugetlb_free_pgd_range(struct mmu_gather *tlb,
			unsigned long addr, unsigned long end,
			unsigned long floor, unsigned long ceiling)
{
	/*
	 * This is called to free hugetlb page tables.
	 *
	 * The offset of these addresses from the base of the hugetlb
	 * region must be scaled down by HPAGE_SIZE/PAGE_SIZE so that
	 * the standard free_pgd_range will free the right page tables.
	 *
	 * If floor and ceiling are also in the hugetlb region, they
	 * must likewise be scaled down; but if outside, left unchanged.
	 */

	addr = htlbpage_to_page(addr);
	end  = htlbpage_to_page(end);
	if (REGION_NUMBER(floor) == RGN_HPAGE)
		floor = htlbpage_to_page(floor);
	if (REGION_NUMBER(ceiling) == RGN_HPAGE)
		ceiling = htlbpage_to_page(ceiling);

	free_pgd_range(tlb, addr, end, floor, ceiling);
}

unsigned long hugetlb_get_unmapped_area(struct file *file, unsigned long addr, unsigned long len,
		unsigned long pgoff, unsigned long flags)
{
	struct vm_unmapped_area_info info;

	if (len > RGN_MAP_LIMIT)
		return -ENOMEM;
	if (len & ~HPAGE_MASK)
		return -EINVAL;

	/* Handle MAP_FIXED */
	if (flags & MAP_FIXED) {
		if (prepare_hugepage_range(file, addr, len))
			return -EINVAL;
		return addr;
	}

	/* This code assumes that RGN_HPAGE != 0. */
	if ((REGION_NUMBER(addr) != RGN_HPAGE) || (addr & (HPAGE_SIZE - 1)))
		addr = HPAGE_REGION_BASE;

	info.flags = 0;
	info.length = len;
	info.low_limit = addr;
	info.high_limit = HPAGE_REGION_BASE + RGN_MAP_LIMIT;
	info.align_mask = PAGE_MASK & (HPAGE_SIZE - 1);
	info.align_offset = 0;
	return vm_unmapped_area(&info);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct page {int dummy; } ;
struct mm_struct {int dummy; } ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int pgd_t ;
struct TYPE_6__ {TYPE_1__* mm; } ;
struct TYPE_5__ {int* pgd; } ;
struct TYPE_4__ {int* pgd; } ;

/* Variables and functions */
 int FIRST_KERNEL_PGD_NR ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  NR_PAGETABLE ; 
 int PGDIR_SHIFT ; 
 int PTRS_PER_PGD ; 
 int USER_PTRS_PER_PGD ; 
 scalar_t__ __get_free_pages (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __pmd (unsigned long) ; 
 int /*<<< orphan*/  cpu_dcache_wb_range (unsigned long,unsigned long) ; 
 TYPE_3__* current ; 
 int /*<<< orphan*/  dec_zone_page_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_pages (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inc_zone_page_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ init_mm ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  mm_dec_nr_ptes (struct mm_struct*) ; 
 int* pgd_offset_k (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmd_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_bad (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmd_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pmd_free (struct mm_struct*,int /*<<< orphan*/ *) ; 
 scalar_t__ pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int*,int) ; 
 struct page* pmd_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pte_free (struct mm_struct*,struct page*) ; 
 int /*<<< orphan*/  set_pmd (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virt_to_page (unsigned long*) ; 

pgd_t *pgd_alloc(struct mm_struct *mm)
{
	pgd_t *new_pgd, *init_pgd;
	int i;

	new_pgd = (pgd_t *) __get_free_pages(GFP_KERNEL, 0);
	if (!new_pgd)
		return NULL;
	for (i = 0; i < PTRS_PER_PGD; i++) {
		(*new_pgd) = 1;
		new_pgd++;
	}
	new_pgd -= PTRS_PER_PGD;

	init_pgd = pgd_offset_k(0);

	memcpy(new_pgd + FIRST_KERNEL_PGD_NR, init_pgd + FIRST_KERNEL_PGD_NR,
	       (PTRS_PER_PGD - FIRST_KERNEL_PGD_NR) * sizeof(pgd_t));

	cpu_dcache_wb_range((unsigned long)new_pgd,
			    (unsigned long)new_pgd +
			    PTRS_PER_PGD * sizeof(pgd_t));
	inc_zone_page_state(virt_to_page((unsigned long *)new_pgd),
			    NR_PAGETABLE);

	return new_pgd;
}

void pgd_free(struct mm_struct *mm, pgd_t * pgd)
{
	pmd_t *pmd;
	struct page *pte;

	if (!pgd)
		return;

	pmd = (pmd_t *) pgd;
	if (pmd_none(*pmd))
		goto free;
	if (pmd_bad(*pmd)) {
		pmd_ERROR(*pmd);
		pmd_clear(pmd);
		goto free;
	}

	pte = pmd_page(*pmd);
	pmd_clear(pmd);
	dec_zone_page_state(virt_to_page((unsigned long *)pgd), NR_PAGETABLE);
	pte_free(mm, pte);
	mm_dec_nr_ptes(mm);
	pmd_free(mm, pmd);
free:
	free_pages((unsigned long)pgd, 0);
}

void setup_mm_for_reboot(char mode)
{
	unsigned long pmdval;
	pgd_t *pgd;
	pmd_t *pmd;
	int i;

	if (current->mm && current->mm->pgd)
		pgd = current->mm->pgd;
	else
		pgd = init_mm.pgd;

	for (i = 0; i < USER_PTRS_PER_PGD; i++) {
		pmdval = (i << PGDIR_SHIFT);
		pmd = pmd_offset(pgd + i, i << PGDIR_SHIFT);
		set_pmd(pmd, __pmd(pmdval));
	}
}


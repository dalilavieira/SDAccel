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
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 unsigned long PAGE_ALIGN (unsigned long) ; 
 int /*<<< orphan*/  PAGE_KERNEL_EXEC ; 
 int /*<<< orphan*/  PAGE_OFFSET ; 
 unsigned long PAGE_SHIFT ; 
 int PTRS_PER_PGD ; 
 int PTRS_PER_PMD ; 
 int PTRS_PER_PTE ; 
 unsigned long _PAGE_KERNEL_TABLE ; 
 int /*<<< orphan*/  __nosave_begin ; 
 int /*<<< orphan*/  __nosave_end ; 
 unsigned long __pa (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __pmd (unsigned long) ; 
 scalar_t__ get_safe_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_flush_tlb_all () ; 
 unsigned long max_low_pfn ; 
 int /*<<< orphan*/  pfn_pte (unsigned long,int /*<<< orphan*/ ) ; 
 int pgd_index (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  restore_image (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  restore_pblist ; 
 int /*<<< orphan*/ * resume_pg_dir ; 
 int /*<<< orphan*/  set_pmd (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pte (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static pmd_t *resume_one_md_table_init(pgd_t *pgd)
{
	pud_t *pud;
	pmd_t *pmd_table;

	pud = pud_offset(pgd, 0);
	pmd_table = pmd_offset(pud, 0);

	return pmd_table;
}

__attribute__((used)) static pte_t *resume_one_page_table_init(pmd_t *pmd)
{
	if (pmd_none(*pmd)) {
		pte_t *page_table = (pte_t *)get_safe_page(GFP_ATOMIC);
		if (!page_table)
			return NULL;

		set_pmd(pmd, __pmd(__pa(page_table) | _PAGE_KERNEL_TABLE));

		BUG_ON(page_table != pte_offset_kernel(pmd, 0));

		return page_table;
	}

	return pte_offset_kernel(pmd, 0);
}

__attribute__((used)) static int resume_physical_mapping_init(pgd_t *pgd_base)
{
	unsigned long pfn;
	pgd_t *pgd;
	pmd_t *pmd;
	pte_t *pte;
	int pgd_idx, pmd_idx;

	pgd_idx = pgd_index(PAGE_OFFSET);
	pgd = pgd_base + pgd_idx;
	pfn = 0;

	for (; pgd_idx < PTRS_PER_PGD; pgd++, pgd_idx++) {
		pmd = resume_one_md_table_init(pgd);
		if (!pmd)
			return -ENOMEM;

		if (pfn >= max_low_pfn)
			continue;

		for (pmd_idx = 0; pmd_idx < PTRS_PER_PMD; pmd++, pmd_idx++) {
			pte_t *max_pte;

			if (pfn >= max_low_pfn)
				break;

			/* Map with normal page tables.
			 * NOTE: We can mark everything as executable here
			 */
			pte = resume_one_page_table_init(pmd);
			if (!pte)
				return -ENOMEM;

			max_pte = pte + PTRS_PER_PTE;
			for (; pte < max_pte; pte++, pfn++) {
				if (pfn >= max_low_pfn)
					break;

				set_pte(pte, pfn_pte(pfn, PAGE_KERNEL_EXEC));
			}
		}
	}

	return 0;
}

__attribute__((used)) static inline void resume_init_first_level_page_table(pgd_t *pg_dir)
{
}

int swsusp_arch_resume(void)
{
	int error;

	resume_pg_dir = (pgd_t *)get_safe_page(GFP_ATOMIC);
	if (!resume_pg_dir)
		return -ENOMEM;

	resume_init_first_level_page_table(resume_pg_dir);
	error = resume_physical_mapping_init(resume_pg_dir);
	if (error)
		return error;

	/* We have got enough memory and from now on we cannot recover */
	restore_image(resume_pg_dir, restore_pblist);
	return 0;
}

int pfn_is_nosave(unsigned long pfn)
{
	unsigned long begin_pfn = __pa(&__nosave_begin) >> PAGE_SHIFT;
	unsigned long end_pfn = PAGE_ALIGN(__pa(&__nosave_end)) >> PAGE_SHIFT;

	return (pfn >= begin_pfn) && (pfn < end_pfn);
}

void save_processor_state(void)
{
}

void restore_processor_state(void)
{
	local_flush_tlb_all();
}


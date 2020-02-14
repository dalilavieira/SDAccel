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
typedef  int /*<<< orphan*/  p4d_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 unsigned long PAGE_ALIGN (unsigned long) ; 
 int /*<<< orphan*/  PAGE_KERNEL_EXEC ; 
 int /*<<< orphan*/  PAGE_KERNEL_LARGE_EXEC ; 
 int /*<<< orphan*/  PAGE_OFFSET ; 
 unsigned long PAGE_SHIFT ; 
 int PTRS_PER_PGD ; 
 int PTRS_PER_PMD ; 
 int PTRS_PER_PTE ; 
 int /*<<< orphan*/  X86_FEATURE_PSE ; 
 int _PAGE_TABLE ; 
 int /*<<< orphan*/  __nosave_begin ; 
 int /*<<< orphan*/  __nosave_end ; 
 int __pa (int /*<<< orphan*/ *) ; 
 unsigned long __pa_symbol (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __pmd (int) ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 scalar_t__ get_safe_page (int /*<<< orphan*/ ) ; 
 unsigned long max_low_pfn ; 
 int /*<<< orphan*/ * p4d_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pfn_pmd (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pfn_pte (unsigned long,int /*<<< orphan*/ ) ; 
 int pgd_index (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pmd (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pte (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static pmd_t *resume_one_md_table_init(pgd_t *pgd)
{
	p4d_t *p4d;
	pud_t *pud;
	pmd_t *pmd_table;

#ifdef CONFIG_X86_PAE
	pmd_table = (pmd_t *)get_safe_page(GFP_ATOMIC);
	if (!pmd_table)
		return NULL;

	set_pgd(pgd, __pgd(__pa(pmd_table) | _PAGE_PRESENT));
	p4d = p4d_offset(pgd, 0);
	pud = pud_offset(p4d, 0);

	BUG_ON(pmd_table != pmd_offset(pud, 0));
#else
	p4d = p4d_offset(pgd, 0);
	pud = pud_offset(p4d, 0);
	pmd_table = pmd_offset(pud, 0);
#endif

	return pmd_table;
}

__attribute__((used)) static pte_t *resume_one_page_table_init(pmd_t *pmd)
{
	if (pmd_none(*pmd)) {
		pte_t *page_table = (pte_t *)get_safe_page(GFP_ATOMIC);
		if (!page_table)
			return NULL;

		set_pmd(pmd, __pmd(__pa(page_table) | _PAGE_TABLE));

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
			if (pfn >= max_low_pfn)
				break;

			/* Map with big pages if possible, otherwise create
			 * normal page tables.
			 * NOTE: We can mark everything as executable here
			 */
			if (boot_cpu_has(X86_FEATURE_PSE)) {
				set_pmd(pmd, pfn_pmd(pfn, PAGE_KERNEL_LARGE_EXEC));
				pfn += PTRS_PER_PTE;
			} else {
				pte_t *max_pte;

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
	}

	return 0;
}

__attribute__((used)) static inline void resume_init_first_level_page_table(pgd_t *pg_dir)
{
#ifdef CONFIG_X86_PAE
	int i;

	/* Init entries of the first-level page table to the zero page */
	for (i = 0; i < PTRS_PER_PGD; i++)
		set_pgd(pg_dir + i,
			__pgd(__pa(empty_zero_page) | _PAGE_PRESENT));
#endif
}

int pfn_is_nosave(unsigned long pfn)
{
	unsigned long nosave_begin_pfn = __pa_symbol(&__nosave_begin) >> PAGE_SHIFT;
	unsigned long nosave_end_pfn = PAGE_ALIGN(__pa_symbol(&__nosave_end)) >> PAGE_SHIFT;
	return (pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}


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
struct page {int dummy; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  phys_addr_t ;
typedef  int /*<<< orphan*/  pgd_t ;

/* Variables and functions */
 scalar_t__ pgd_huge (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgd_page_vaddr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgd_pte (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_devmap (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_huge (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmd_page_vaddr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmd_pte (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_trans_huge (int /*<<< orphan*/ ) ; 
 struct page* pte_page (int /*<<< orphan*/ ) ; 
 scalar_t__ pud_huge (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pud_page_vaddr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pud_pte (int /*<<< orphan*/ ) ; 
 struct page* virt_to_page (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline phys_addr_t v_block_mapped(unsigned long va) { return 0; }

__attribute__((used)) static inline unsigned long p_block_mapped(phys_addr_t pa) { return 0; }

struct page *pgd_page(pgd_t pgd)
{
	if (pgd_huge(pgd))
		return pte_page(pgd_pte(pgd));
	return virt_to_page(pgd_page_vaddr(pgd));
}

struct page *pud_page(pud_t pud)
{
	if (pud_huge(pud))
		return pte_page(pud_pte(pud));
	return virt_to_page(pud_page_vaddr(pud));
}

struct page *pmd_page(pmd_t pmd)
{
	if (pmd_trans_huge(pmd) || pmd_huge(pmd) || pmd_devmap(pmd))
		return pte_page(pmd_pte(pmd));
	return virt_to_page(pmd_page_vaddr(pmd));
}


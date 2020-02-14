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
struct mm_struct {int dummy; } ;
typedef  int /*<<< orphan*/  pgd_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PGALLOC_GFP ; 
 int PTE_MAGNITUDE ; 
 int PTRS_PER_PGD ; 
 int /*<<< orphan*/  SLAB_PANIC ; 
 int USER_PTRS_PER_PGD ; 
 int /*<<< orphan*/ * kmem_cache_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kmem_cache_create (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (void*)) ; 
 int /*<<< orphan*/  kmem_cache_free (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  pgd_cachep ; 
 int swapper_pg_dir ; 

void pgd_ctor(void *x)
{
	pgd_t *pgd = x;

	memcpy(pgd + USER_PTRS_PER_PGD,
	       swapper_pg_dir + USER_PTRS_PER_PGD,
	       (PTRS_PER_PGD - USER_PTRS_PER_PGD) * sizeof(pgd_t));
}

void pgtable_cache_init(void)
{
	pgd_cachep = kmem_cache_create("pgd_cache",
				       PTRS_PER_PGD * (1<<PTE_MAGNITUDE),
				       PAGE_SIZE, SLAB_PANIC, pgd_ctor);
#if PAGETABLE_LEVELS > 2
	pmd_cachep = kmem_cache_create("pmd_cache",
				       PTRS_PER_PMD * (1<<PTE_MAGNITUDE),
				       PAGE_SIZE, SLAB_PANIC, NULL);
#endif
}

pgd_t *pgd_alloc(struct mm_struct *mm)
{
	return kmem_cache_alloc(pgd_cachep, PGALLOC_GFP);
}

void pgd_free(struct mm_struct *mm, pgd_t *pgd)
{
	kmem_cache_free(pgd_cachep, pgd);
}


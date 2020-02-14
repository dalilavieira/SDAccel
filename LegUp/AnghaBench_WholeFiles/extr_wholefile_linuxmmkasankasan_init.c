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
struct kmem_cache {int dummy; } ;
struct kasan_free_meta {int dummy; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
typedef  int /*<<< orphan*/  p4d_t ;

/* Variables and functions */
 unsigned long KASAN_SHADOW_OFFSET ; 
 unsigned long KASAN_SHADOW_SCALE_SHIFT ; 
 int /*<<< orphan*/  kasan_zero_page ; 
 int /*<<< orphan*/  kasan_zero_pte ; 
 int /*<<< orphan*/  lm_alias (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_page (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_page (int /*<<< orphan*/ ) ; 
 scalar_t__ virt_to_page (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline const void *kasan_shadow_to_mem(const void *shadow_addr)
{
	return (void *)(((unsigned long)shadow_addr - KASAN_SHADOW_OFFSET)
		<< KASAN_SHADOW_SCALE_SHIFT);
}

__attribute__((used)) static inline void quarantine_put(struct kasan_free_meta *info,
				struct kmem_cache *cache) { }

__attribute__((used)) static inline void quarantine_reduce(void) { }

__attribute__((used)) static inline void quarantine_remove_cache(struct kmem_cache *cache) { }

__attribute__((used)) static inline bool kasan_p4d_table(pgd_t pgd)
{
	return 0;
}

__attribute__((used)) static inline bool kasan_pud_table(p4d_t p4d)
{
	return 0;
}

__attribute__((used)) static inline bool kasan_pmd_table(pud_t pud)
{
	return 0;
}

__attribute__((used)) static inline bool kasan_pte_table(pmd_t pmd)
{
	return pmd_page(pmd) == virt_to_page(lm_alias(kasan_zero_pte));
}

__attribute__((used)) static inline bool kasan_zero_page_entry(pte_t pte)
{
	return pte_page(pte) == virt_to_page(lm_alias(kasan_zero_page));
}


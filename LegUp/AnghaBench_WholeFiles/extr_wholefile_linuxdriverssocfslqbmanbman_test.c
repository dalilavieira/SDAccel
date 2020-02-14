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
typedef  scalar_t__ u8 ;

/* Variables and functions */
 int /*<<< orphan*/  dpaa_invalidate (void*) ; 
 int /*<<< orphan*/  prefetch (void*) ; 

__attribute__((used)) static inline void dpaa_flush(void *p)
{
	/*
	 * Only PPC needs to flush the cache currently - on ARM the mapping
	 * is non cacheable
	 */
#ifdef CONFIG_PPC
	flush_dcache_range((unsigned long)p, (unsigned long)p+64);
#endif
}

__attribute__((used)) static inline void dpaa_touch_ro(void *p)
{
#if (L1_CACHE_BYTES == 32)
	prefetch(p+32);
#endif
	prefetch(p);
}

__attribute__((used)) static inline void dpaa_invalidate_touch_ro(void *p)
{
	dpaa_invalidate(p);
	dpaa_touch_ro(p);
}

__attribute__((used)) static inline u8 dpaa_cyc_diff(u8 ringsize, u8 first, u8 last)
{
	/* 'first' is included, 'last' is excluded */
	if (first <= last)
		return last - first;
	return ringsize + last - first;
}

__attribute__((used)) static int test_init(void)
{
#ifdef CONFIG_FSL_BMAN_TEST_API
	int loop = 1;

	while (loop--)
		bman_test_api();
#endif
	return 0;
}

__attribute__((used)) static void test_exit(void)
{
}


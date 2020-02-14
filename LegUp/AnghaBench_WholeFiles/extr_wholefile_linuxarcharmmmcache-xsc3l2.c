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

/* Variables and functions */
 int CACHE_LINE_SIZE ; 
 int CACHE_SET_SIZE (unsigned long) ; 
 int CACHE_WAY_PER_SET ; 
 unsigned long __phys_to_virt (unsigned long) ; 
 int /*<<< orphan*/  dsb () ; 

__attribute__((used)) static inline int xsc3_l2_present(void)
{
	unsigned long l2ctype;

	__asm__("mrc p15, 1, %0, c0, c0, 1" : "=r" (l2ctype));

	return !!(l2ctype & 0xf8);
}

__attribute__((used)) static inline void xsc3_l2_clean_mva(unsigned long addr)
{
	__asm__("mcr p15, 1, %0, c7, c11, 1" : : "r" (addr));
}

__attribute__((used)) static inline void xsc3_l2_inv_mva(unsigned long addr)
{
	__asm__("mcr p15, 1, %0, c7, c7, 1" : : "r" (addr));
}

__attribute__((used)) static inline void xsc3_l2_inv_all(void)
{
	unsigned long l2ctype, set_way;
	int set, way;

	__asm__("mrc p15, 1, %0, c0, c0, 1" : "=r" (l2ctype));

	for (set = 0; set < CACHE_SET_SIZE(l2ctype); set++) {
		for (way = 0; way < CACHE_WAY_PER_SET; way++) {
			set_way = (way << 29) | (set << 5);
			__asm__("mcr p15, 1, %0, c7, c11, 2" : : "r"(set_way));
		}
	}

	dsb();
}

__attribute__((used)) static inline void l2_unmap_va(unsigned long va)
{
#ifdef CONFIG_HIGHMEM
	if (va != -1)
		kunmap_atomic((void *)va);
#endif
}

__attribute__((used)) static inline unsigned long l2_map_va(unsigned long pa, unsigned long prev_va)
{
#ifdef CONFIG_HIGHMEM
	unsigned long va = prev_va & PAGE_MASK;
	unsigned long pa_offset = pa << (32 - PAGE_SHIFT);
	if (unlikely(pa_offset < (prev_va << (32 - PAGE_SHIFT)))) {
		/*
		 * Switching to a new page.  Because cache ops are
		 * using virtual addresses only, we must put a mapping
		 * in place for it.
		 */
		l2_unmap_va(prev_va);
		va = (unsigned long)kmap_atomic_pfn(pa >> PAGE_SHIFT);
	}
	return va + (pa_offset >> (32 - PAGE_SHIFT));
#else
	return __phys_to_virt(pa);
#endif
}

__attribute__((used)) static void xsc3_l2_inv_range(unsigned long start, unsigned long end)
{
	unsigned long vaddr;

	if (start == 0 && end == -1ul) {
		xsc3_l2_inv_all();
		return;
	}

	vaddr = -1;  /* to force the first mapping */

	/*
	 * Clean and invalidate partial first cache line.
	 */
	if (start & (CACHE_LINE_SIZE - 1)) {
		vaddr = l2_map_va(start & ~(CACHE_LINE_SIZE - 1), vaddr);
		xsc3_l2_clean_mva(vaddr);
		xsc3_l2_inv_mva(vaddr);
		start = (start | (CACHE_LINE_SIZE - 1)) + 1;
	}

	/*
	 * Invalidate all full cache lines between 'start' and 'end'.
	 */
	while (start < (end & ~(CACHE_LINE_SIZE - 1))) {
		vaddr = l2_map_va(start, vaddr);
		xsc3_l2_inv_mva(vaddr);
		start += CACHE_LINE_SIZE;
	}

	/*
	 * Clean and invalidate partial last cache line.
	 */
	if (start < end) {
		vaddr = l2_map_va(start, vaddr);
		xsc3_l2_clean_mva(vaddr);
		xsc3_l2_inv_mva(vaddr);
	}

	l2_unmap_va(vaddr);

	dsb();
}

__attribute__((used)) static void xsc3_l2_clean_range(unsigned long start, unsigned long end)
{
	unsigned long vaddr;

	vaddr = -1;  /* to force the first mapping */

	start &= ~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		vaddr = l2_map_va(start, vaddr);
		xsc3_l2_clean_mva(vaddr);
		start += CACHE_LINE_SIZE;
	}

	l2_unmap_va(vaddr);

	dsb();
}

__attribute__((used)) static inline void xsc3_l2_flush_all(void)
{
	unsigned long l2ctype, set_way;
	int set, way;

	__asm__("mrc p15, 1, %0, c0, c0, 1" : "=r" (l2ctype));

	for (set = 0; set < CACHE_SET_SIZE(l2ctype); set++) {
		for (way = 0; way < CACHE_WAY_PER_SET; way++) {
			set_way = (way << 29) | (set << 5);
			__asm__("mcr p15, 1, %0, c7, c15, 2" : : "r"(set_way));
		}
	}

	dsb();
}

__attribute__((used)) static void xsc3_l2_flush_range(unsigned long start, unsigned long end)
{
	unsigned long vaddr;

	if (start == 0 && end == -1ul) {
		xsc3_l2_flush_all();
		return;
	}

	vaddr = -1;  /* to force the first mapping */

	start &= ~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		vaddr = l2_map_va(start, vaddr);
		xsc3_l2_clean_mva(vaddr);
		xsc3_l2_inv_mva(vaddr);
		start += CACHE_LINE_SIZE;
	}

	l2_unmap_va(vaddr);

	dsb();
}


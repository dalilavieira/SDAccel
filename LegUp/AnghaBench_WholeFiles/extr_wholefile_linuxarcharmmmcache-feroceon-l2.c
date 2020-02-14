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
 int /*<<< orphan*/  BUG_ON (unsigned long) ; 
 int CACHE_LINE_SIZE ; 
 unsigned long MAX_RANGE_SIZE ; 
 unsigned long PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 unsigned long __phys_to_virt (unsigned long) ; 
 int /*<<< orphan*/  dsb () ; 
 int /*<<< orphan*/  l2_wt_override ; 
 int /*<<< orphan*/  raw_local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  raw_local_irq_save (unsigned long) ; 

__attribute__((used)) static inline unsigned long l2_get_va(unsigned long paddr)
{
#ifdef CONFIG_HIGHMEM
	/*
	 * Because range ops can't be done on physical addresses,
	 * we simply install a virtual mapping for it only for the
	 * TLB lookup to occur, hence no need to flush the untouched
	 * memory mapping afterwards (note: a cache flush may happen
	 * in some circumstances depending on the path taken in kunmap_atomic).
	 */
	void *vaddr = kmap_atomic_pfn(paddr >> PAGE_SHIFT);
	return (unsigned long)vaddr + (paddr & ~PAGE_MASK);
#else
	return __phys_to_virt(paddr);
#endif
}

__attribute__((used)) static inline void l2_put_va(unsigned long vaddr)
{
#ifdef CONFIG_HIGHMEM
	kunmap_atomic((void *)vaddr);
#endif
}

__attribute__((used)) static inline void l2_clean_pa(unsigned long addr)
{
	__asm__("mcr p15, 1, %0, c15, c9, 3" : : "r" (addr));
}

__attribute__((used)) static inline void l2_clean_pa_range(unsigned long start, unsigned long end)
{
	unsigned long va_start, va_end, flags;

	/*
	 * Make sure 'start' and 'end' reference the same page, as
	 * L2 is PIPT and range operations only do a TLB lookup on
	 * the start address.
	 */
	BUG_ON((start ^ end) >> PAGE_SHIFT);

	va_start = l2_get_va(start);
	va_end = va_start + (end - start);
	raw_local_irq_save(flags);
	__asm__("mcr p15, 1, %0, c15, c9, 4\n\t"
		"mcr p15, 1, %1, c15, c9, 5"
		: : "r" (va_start), "r" (va_end));
	raw_local_irq_restore(flags);
	l2_put_va(va_start);
}

__attribute__((used)) static inline void l2_clean_inv_pa(unsigned long addr)
{
	__asm__("mcr p15, 1, %0, c15, c10, 3" : : "r" (addr));
}

__attribute__((used)) static inline void l2_inv_pa(unsigned long addr)
{
	__asm__("mcr p15, 1, %0, c15, c11, 3" : : "r" (addr));
}

__attribute__((used)) static inline void l2_inv_pa_range(unsigned long start, unsigned long end)
{
	unsigned long va_start, va_end, flags;

	/*
	 * Make sure 'start' and 'end' reference the same page, as
	 * L2 is PIPT and range operations only do a TLB lookup on
	 * the start address.
	 */
	BUG_ON((start ^ end) >> PAGE_SHIFT);

	va_start = l2_get_va(start);
	va_end = va_start + (end - start);
	raw_local_irq_save(flags);
	__asm__("mcr p15, 1, %0, c15, c11, 4\n\t"
		"mcr p15, 1, %1, c15, c11, 5"
		: : "r" (va_start), "r" (va_end));
	raw_local_irq_restore(flags);
	l2_put_va(va_start);
}

__attribute__((used)) static inline void l2_inv_all(void)
{
	__asm__("mcr p15, 1, %0, c15, c11, 0" : : "r" (0));
}

__attribute__((used)) static unsigned long calc_range_end(unsigned long start, unsigned long end)
{
	unsigned long range_end;

	BUG_ON(start & (CACHE_LINE_SIZE - 1));
	BUG_ON(end & (CACHE_LINE_SIZE - 1));

	/*
	 * Try to process all cache lines between 'start' and 'end'.
	 */
	range_end = end;

	/*
	 * Limit the number of cache lines processed at once,
	 * since cache range operations stall the CPU pipeline
	 * until completion.
	 */
	if (range_end > start + MAX_RANGE_SIZE)
		range_end = start + MAX_RANGE_SIZE;

	/*
	 * Cache range operations can't straddle a page boundary.
	 */
	if (range_end > (start | (PAGE_SIZE - 1)) + 1)
		range_end = (start | (PAGE_SIZE - 1)) + 1;

	return range_end;
}

__attribute__((used)) static void feroceon_l2_inv_range(unsigned long start, unsigned long end)
{
	/*
	 * Clean and invalidate partial first cache line.
	 */
	if (start & (CACHE_LINE_SIZE - 1)) {
		l2_clean_inv_pa(start & ~(CACHE_LINE_SIZE - 1));
		start = (start | (CACHE_LINE_SIZE - 1)) + 1;
	}

	/*
	 * Clean and invalidate partial last cache line.
	 */
	if (start < end && end & (CACHE_LINE_SIZE - 1)) {
		l2_clean_inv_pa(end & ~(CACHE_LINE_SIZE - 1));
		end &= ~(CACHE_LINE_SIZE - 1);
	}

	/*
	 * Invalidate all full cache lines between 'start' and 'end'.
	 */
	while (start < end) {
		unsigned long range_end = calc_range_end(start, end);
		l2_inv_pa_range(start, range_end - CACHE_LINE_SIZE);
		start = range_end;
	}

	dsb();
}

__attribute__((used)) static void feroceon_l2_clean_range(unsigned long start, unsigned long end)
{
	/*
	 * If L2 is forced to WT, the L2 will always be clean and we
	 * don't need to do anything here.
	 */
	if (!l2_wt_override) {
		start &= ~(CACHE_LINE_SIZE - 1);
		end = (end + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1);
		while (start != end) {
			unsigned long range_end = calc_range_end(start, end);
			l2_clean_pa_range(start, range_end - CACHE_LINE_SIZE);
			start = range_end;
		}
	}

	dsb();
}

__attribute__((used)) static void feroceon_l2_flush_range(unsigned long start, unsigned long end)
{
	start &= ~(CACHE_LINE_SIZE - 1);
	end = (end + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1);
	while (start != end) {
		unsigned long range_end = calc_range_end(start, end);
		if (!l2_wt_override)
			l2_clean_pa_range(start, range_end - CACHE_LINE_SIZE);
		l2_inv_pa_range(start, range_end - CACHE_LINE_SIZE);
		start = range_end;
	}

	dsb();
}


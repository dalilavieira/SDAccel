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
struct flusher_data {int addr1; int addr2; } ;

/* Variables and functions */
 unsigned long CACHE_IC_ADDRESS_ARRAY ; 
 unsigned long CACHE_OC_ADDRESS_ARRAY ; 
 unsigned long CACHE_PHYSADDR_MASK ; 
 unsigned long CCR_ICACHE_INVALIDATE ; 
 unsigned long CCR_OCACHE_INVALIDATE ; 
 int L1_CACHE_BYTES ; 
 unsigned long MAX_ICACHE_PAGES ; 
 unsigned long MAX_OCACHE_PAGES ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long SH_CACHE_ASSOC ; 
 unsigned long SH_CCR ; 
 unsigned long __raw_readl (unsigned long) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  back_to_cached () ; 
 int /*<<< orphan*/  jump_to_uncached () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

__attribute__((used)) static void sh2a_invalidate_line(unsigned long cache_addr, unsigned long v)
{
	/* Set associative bit to hit all ways */
	unsigned long addr = (v & 0x000007f0) | SH_CACHE_ASSOC;
	__raw_writel((addr & CACHE_PHYSADDR_MASK), cache_addr | addr);
}

__attribute__((used)) static void sh2a__flush_wback_region(void *start, int size)
{
#ifdef CONFIG_CACHE_WRITEBACK
	unsigned long v;
	unsigned long begin, end;
	unsigned long flags;
	int nr_ways;

	begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
	end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
		& ~(L1_CACHE_BYTES-1);
	nr_ways = current_cpu_data.dcache.ways;

	local_irq_save(flags);
	jump_to_uncached();

	/* If there are too many pages then flush the entire cache */
	if (((end - begin) >> PAGE_SHIFT) >= MAX_OCACHE_PAGES) {
		begin = CACHE_OC_ADDRESS_ARRAY;
		end = begin + (nr_ways * current_cpu_data.dcache.way_size);

		for (v = begin; v < end; v += L1_CACHE_BYTES) {
			unsigned long data = __raw_readl(v);
			if (data & SH_CACHE_UPDATED)
				__raw_writel(data & ~SH_CACHE_UPDATED, v);
		}
	} else {
		int way;
		for (way = 0; way < nr_ways; way++) {
			for (v = begin; v < end; v += L1_CACHE_BYTES)
				sh2a_flush_oc_line(v, way);
		}
	}

	back_to_cached();
	local_irq_restore(flags);
#endif
}

__attribute__((used)) static void sh2a__flush_purge_region(void *start, int size)
{
	unsigned long v;
	unsigned long begin, end;
	unsigned long flags;

	begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
	end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
		& ~(L1_CACHE_BYTES-1);

	local_irq_save(flags);
	jump_to_uncached();

	for (v = begin; v < end; v+=L1_CACHE_BYTES) {
#ifdef CONFIG_CACHE_WRITEBACK
		int way;
		int nr_ways = current_cpu_data.dcache.ways;
		for (way = 0; way < nr_ways; way++)
			sh2a_flush_oc_line(v, way);
#endif
		sh2a_invalidate_line(CACHE_OC_ADDRESS_ARRAY, v);
	}

	back_to_cached();
	local_irq_restore(flags);
}

__attribute__((used)) static void sh2a__flush_invalidate_region(void *start, int size)
{
	unsigned long v;
	unsigned long begin, end;
	unsigned long flags;

	begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
	end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
		& ~(L1_CACHE_BYTES-1);

	local_irq_save(flags);
	jump_to_uncached();

	/* If there are too many pages then just blow the cache */
	if (((end - begin) >> PAGE_SHIFT) >= MAX_OCACHE_PAGES) {
		__raw_writel(__raw_readl(SH_CCR) | CCR_OCACHE_INVALIDATE,
			     SH_CCR);
	} else {
		for (v = begin; v < end; v += L1_CACHE_BYTES)
			sh2a_invalidate_line(CACHE_OC_ADDRESS_ARRAY, v);
	}

	back_to_cached();
	local_irq_restore(flags);
}

__attribute__((used)) static void sh2a_flush_icache_range(void *args)
{
	struct flusher_data *data = args;
	unsigned long start, end;
	unsigned long v;
	unsigned long flags;

	start = data->addr1 & ~(L1_CACHE_BYTES-1);
	end = (data->addr2 + L1_CACHE_BYTES-1) & ~(L1_CACHE_BYTES-1);

#ifdef CONFIG_CACHE_WRITEBACK
	sh2a__flush_wback_region((void *)start, end-start);
#endif

	local_irq_save(flags);
	jump_to_uncached();

	/* I-Cache invalidate */
	/* If there are too many pages then just blow the cache */
	if (((end - start) >> PAGE_SHIFT) >= MAX_ICACHE_PAGES) {
		__raw_writel(__raw_readl(SH_CCR) | CCR_ICACHE_INVALIDATE,
			     SH_CCR);
	} else {
		for (v = start; v < end; v += L1_CACHE_BYTES)
			sh2a_invalidate_line(CACHE_IC_ADDRESS_ARRAY, v);
	}

	back_to_cached();
	local_irq_restore(flags);
}


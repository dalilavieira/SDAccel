#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {unsigned long ways; unsigned long entry_mask; scalar_t__ way_incr; } ;
struct TYPE_4__ {TYPE_1__ dcache; } ;

/* Variables and functions */
 unsigned long CACHE_OC_ADDRESS_ARRAY ; 
 unsigned long CACHE_PHYSADDR_MASK ; 
 int L1_CACHE_BYTES ; 
 unsigned long SH_CACHE_ASSOC ; 
 unsigned long SH_CACHE_UPDATED ; 
 unsigned long __pa (unsigned long) ; 
 unsigned long __raw_readl (unsigned long) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,unsigned long) ; 
 TYPE_2__ current_cpu_data ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

__attribute__((used)) static void sh3__flush_wback_region(void *start, int size)
{
	unsigned long v, j;
	unsigned long begin, end;
	unsigned long flags;

	begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
	end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
		& ~(L1_CACHE_BYTES-1);

	for (v = begin; v < end; v+=L1_CACHE_BYTES) {
		unsigned long addrstart = CACHE_OC_ADDRESS_ARRAY;
		for (j = 0; j < current_cpu_data.dcache.ways; j++) {
			unsigned long data, addr, p;

			p = __pa(v);
			addr = addrstart | (v & current_cpu_data.dcache.entry_mask);
			local_irq_save(flags);
			data = __raw_readl(addr);

			if ((data & CACHE_PHYSADDR_MASK) ==
			    (p & CACHE_PHYSADDR_MASK)) {
				data &= ~SH_CACHE_UPDATED;
				__raw_writel(data, addr);
				local_irq_restore(flags);
				break;
			}
			local_irq_restore(flags);
			addrstart += current_cpu_data.dcache.way_incr;
		}
	}
}

__attribute__((used)) static void sh3__flush_purge_region(void *start, int size)
{
	unsigned long v;
	unsigned long begin, end;

	begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
	end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
		& ~(L1_CACHE_BYTES-1);

	for (v = begin; v < end; v+=L1_CACHE_BYTES) {
		unsigned long data, addr;

		data = (v & 0xfffffc00); /* _Virtual_ address, ~U, ~V */
		addr = CACHE_OC_ADDRESS_ARRAY |
			(v & current_cpu_data.dcache.entry_mask) | SH_CACHE_ASSOC;
		__raw_writel(data, addr);
	}
}


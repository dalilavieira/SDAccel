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
typedef  int /*<<< orphan*/  phys_addr_t ;

/* Variables and functions */
 scalar_t__ KERNEL_END ; 
 scalar_t__ KERNEL_START ; 
 unsigned long MAX_DMA_ADDRESS ; 
 unsigned long PAGE_OFFSET ; 
 int /*<<< orphan*/  VIRTUAL_BUG_ON (int) ; 
 int /*<<< orphan*/  WARN (int,char*,void*,void*) ; 
 int /*<<< orphan*/  __pa_symbol_nodebug (unsigned long) ; 
 int /*<<< orphan*/  __virt_to_phys_nodebug (unsigned long) ; 
 scalar_t__ high_memory ; 

__attribute__((used)) static inline bool __virt_addr_valid(unsigned long x)
{
	/*
	 * high_memory does not get immediately defined, and there
	 * are early callers of __pa() against PAGE_OFFSET
	 */
	if (!high_memory && x >= PAGE_OFFSET)
		return true;

	if (high_memory && x >= PAGE_OFFSET && x < (unsigned long)high_memory)
		return true;

	/*
	 * MAX_DMA_ADDRESS is a virtual address that may not correspond to an
	 * actual physical address. Enough code relies on __pa(MAX_DMA_ADDRESS)
	 * that we just need to work around it and always return true.
	 */
	if (x == MAX_DMA_ADDRESS)
		return true;

	return false;
}

phys_addr_t __virt_to_phys(unsigned long x)
{
	WARN(!__virt_addr_valid(x),
	     "virt_to_phys used for non-linear address: %pK (%pS)\n",
	     (void *)x, (void *)x);

	return __virt_to_phys_nodebug(x);
}

phys_addr_t __phys_addr_symbol(unsigned long x)
{
	/* This is bounds checking against the kernel image only.
	 * __pa_symbol should only be used on kernel symbol addresses.
	 */
	VIRTUAL_BUG_ON(x < (unsigned long)KERNEL_START ||
		       x > (unsigned long)KERNEL_END);

	return __pa_symbol_nodebug(x);
}


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
typedef  unsigned long u32 ;
typedef  int mtrr_type ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  MSR_K6_UWCCR ; 
 int MTRR_TYPE_UNCACHABLE ; 
 unsigned int MTRR_TYPE_WRCOMB ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  rdmsr (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  wbinvd () ; 
 int /*<<< orphan*/  wrmsr (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 

__attribute__((used)) static void
amd_get_mtrr(unsigned int reg, unsigned long *base,
	     unsigned long *size, mtrr_type *type)
{
	unsigned long low, high;

	rdmsr(MSR_K6_UWCCR, low, high);
	/* Upper dword is region 1, lower is region 0 */
	if (reg == 1)
		low = high;
	/* The base masks off on the right alignment */
	*base = (low & 0xFFFE0000) >> PAGE_SHIFT;
	*type = 0;
	if (low & 1)
		*type = MTRR_TYPE_UNCACHABLE;
	if (low & 2)
		*type = MTRR_TYPE_WRCOMB;
	if (!(low & 3)) {
		*size = 0;
		return;
	}
	/*
	 * This needs a little explaining. The size is stored as an
	 * inverted mask of bits of 128K granularity 15 bits long offset
	 * 2 bits.
	 *
	 * So to get a size we do invert the mask and add 1 to the lowest
	 * mask bit (4 as its 2 bits in). This gives us a size we then shift
	 * to turn into 128K blocks.
	 *
	 * eg              111 1111 1111 1100      is 512K
	 *
	 * invert          000 0000 0000 0011
	 * +1              000 0000 0000 0100
	 * *128K   ...
	 */
	low = (~low) & 0x1FFFC;
	*size = (low + 4) << (15 - PAGE_SHIFT);
}

__attribute__((used)) static void
amd_set_mtrr(unsigned int reg, unsigned long base, unsigned long size, mtrr_type type)
{
	u32 regs[2];

	/*
	 * Low is MTRR0, High MTRR 1
	 */
	rdmsr(MSR_K6_UWCCR, regs[0], regs[1]);
	/*
	 * Blank to disable
	 */
	if (size == 0) {
		regs[reg] = 0;
	} else {
		/*
		 * Set the register to the base, the type (off by one) and an
		 * inverted bitmask of the size The size is the only odd
		 * bit. We are fed say 512K We invert this and we get 111 1111
		 * 1111 1011 but if you subtract one and invert you get the
		 * desired 111 1111 1111 1100 mask
		 *
		 *  But ~(x - 1) == ~x + 1 == -x. Two's complement rocks!
		 */
		regs[reg] = (-size >> (15 - PAGE_SHIFT) & 0x0001FFFC)
		    | (base << PAGE_SHIFT) | (type + 1);
	}

	/*
	 * The writeback rule is quite specific. See the manual. Its
	 * disable local interrupts, write back the cache, set the mtrr
	 */
	wbinvd();
	wrmsr(MSR_K6_UWCCR, regs[0], regs[1]);
}

__attribute__((used)) static int
amd_validate_add_page(unsigned long base, unsigned long size, unsigned int type)
{
	/*
	 * Apply the K6 block alignment and size rules
	 * In order
	 * o Uncached or gathering only
	 * o 128K or bigger block
	 * o Power of 2 block
	 * o base suitably aligned to the power
	 */
	if (type > MTRR_TYPE_WRCOMB || size < (1 << (17 - PAGE_SHIFT))
	    || (size & ~(size - 1)) - size || (base & (size - 1)))
		return -EINVAL;
	return 0;
}


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
typedef  void* u32 ;
typedef  unsigned int mtrr_type ;
struct TYPE_4__ {int low; int high; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* get ) (int,unsigned long*,unsigned long*,unsigned int*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENOSPC ; 
 scalar_t__ MSR_IDT_MCR0 ; 
 unsigned int MTRR_TYPE_UNCACHABLE ; 
 unsigned int MTRR_TYPE_WRBACK ; 
 unsigned int MTRR_TYPE_WRCOMB ; 
 int PAGE_SHIFT ; 
 TYPE_2__* centaur_mcr ; 
 int centaur_mcr_reserved ; 
 int centaur_mcr_type ; 
 TYPE_1__* mtrr_if ; 
 int num_var_ranges ; 
 int /*<<< orphan*/  pr_warn (char*,char*) ; 
 int /*<<< orphan*/  stub1 (int,unsigned long*,unsigned long*,unsigned int*) ; 
 int /*<<< orphan*/  wrmsr (scalar_t__,unsigned long,unsigned long) ; 

__attribute__((used)) static int
centaur_get_free_region(unsigned long base, unsigned long size, int replace_reg)
{
	unsigned long lbase, lsize;
	mtrr_type ltype;
	int i, max;

	max = num_var_ranges;
	if (replace_reg >= 0 && replace_reg < max)
		return replace_reg;

	for (i = 0; i < max; ++i) {
		if (centaur_mcr_reserved & (1 << i))
			continue;
		mtrr_if->get(i, &lbase, &lsize, &ltype);
		if (lsize == 0)
			return i;
	}

	return -ENOSPC;
}

void mtrr_centaur_report_mcr(int mcr, u32 lo, u32 hi)
{
	centaur_mcr[mcr].low = lo;
	centaur_mcr[mcr].high = hi;
}

__attribute__((used)) static void
centaur_get_mcr(unsigned int reg, unsigned long *base,
		unsigned long *size, mtrr_type * type)
{
	*base = centaur_mcr[reg].high >> PAGE_SHIFT;
	*size = -(centaur_mcr[reg].low & 0xfffff000) >> PAGE_SHIFT;
	*type = MTRR_TYPE_WRCOMB;		/* write-combining  */

	if (centaur_mcr_type == 1 && ((centaur_mcr[reg].low & 31) & 2))
		*type = MTRR_TYPE_UNCACHABLE;
	if (centaur_mcr_type == 1 && (centaur_mcr[reg].low & 31) == 25)
		*type = MTRR_TYPE_WRBACK;
	if (centaur_mcr_type == 0 && (centaur_mcr[reg].low & 31) == 31)
		*type = MTRR_TYPE_WRBACK;
}

__attribute__((used)) static void
centaur_set_mcr(unsigned int reg, unsigned long base,
		unsigned long size, mtrr_type type)
{
	unsigned long low, high;

	if (size == 0) {
		/* Disable */
		high = low = 0;
	} else {
		high = base << PAGE_SHIFT;
		if (centaur_mcr_type == 0) {
			/* Only support write-combining... */
			low = -size << PAGE_SHIFT | 0x1f;
		} else {
			if (type == MTRR_TYPE_UNCACHABLE)
				low = -size << PAGE_SHIFT | 0x02; /* NC */
			else
				low = -size << PAGE_SHIFT | 0x09; /* WWO, WC */
		}
	}
	centaur_mcr[reg].high = high;
	centaur_mcr[reg].low = low;
	wrmsr(MSR_IDT_MCR0 + reg, low, high);
}

__attribute__((used)) static int
centaur_validate_add_page(unsigned long base, unsigned long size, unsigned int type)
{
	/*
	 * FIXME: Winchip2 supports uncached
	 */
	if (type != MTRR_TYPE_WRCOMB &&
	    (centaur_mcr_type == 0 || type != MTRR_TYPE_UNCACHABLE)) {
		pr_warn("mtrr: only write-combining%s supported\n",
			   centaur_mcr_type ? " and uncacheable are" : " is");
		return -EINVAL;
	}
	return 0;
}


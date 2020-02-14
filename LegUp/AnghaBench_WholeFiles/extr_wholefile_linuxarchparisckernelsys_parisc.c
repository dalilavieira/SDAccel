#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct vm_unmapped_area_info {unsigned long length; unsigned long low_limit; unsigned long high_limit; int align_mask; unsigned long align_offset; scalar_t__ flags; } ;
struct vm_area_struct {int dummy; } ;
struct rlimit {unsigned long rlim_max; } ;
struct mm_struct {unsigned long mmap_legacy_base; unsigned long mmap_base; unsigned long (* get_unmapped_area ) (struct file*,unsigned long,unsigned long,unsigned long,unsigned long) ;} ;
struct file {int dummy; } ;
struct TYPE_2__ {int personality; int flags; struct mm_struct* mm; } ;

/* Variables and functions */
 int ADDR_COMPAT_LAYOUT ; 
 unsigned long EINVAL ; 
 unsigned long ENOMEM ; 
 int GET_LAST_MMAP (struct file*) ; 
 unsigned long MAP_FIXED ; 
 unsigned long MAP_SHARED ; 
 unsigned int MMAP_RND_MASK ; 
 unsigned long PAGE_ALIGN (unsigned long) ; 
 int PAGE_MASK ; 
 unsigned int PAGE_SHIFT ; 
 unsigned long PAGE_SIZE ; 
 int PF_RANDOMIZE ; 
 int /*<<< orphan*/  RLIMIT_STACK ; 
 int /*<<< orphan*/  SET_LAST_MMAP (struct file*,unsigned long) ; 
 int SHM_COLOUR ; 
 unsigned int STACK_RND_MASK ; 
 unsigned long STACK_SIZE_MAX ; 
 unsigned long STACK_TOP ; 
 unsigned long const TASK_SIZE ; 
 unsigned long TASK_UNMAPPED_BASE ; 
 int /*<<< orphan*/  VM_BUG_ON (int) ; 
 scalar_t__ VM_UNMAPPED_AREA_TOPDOWN ; 
 TYPE_1__* current ; 
 struct vm_area_struct* find_vma_prev (struct mm_struct*,unsigned long,struct vm_area_struct**) ; 
 unsigned int get_random_int () ; 
 unsigned long rlimit_max (int /*<<< orphan*/ ) ; 
 int sysctl_legacy_va_layout ; 
 unsigned long vm_end_gap (struct vm_area_struct*) ; 
 unsigned long vm_start_gap (struct vm_area_struct*) ; 
 unsigned long vm_unmapped_area (struct vm_unmapped_area_info*) ; 

__attribute__((used)) static int get_offset(unsigned int last_mmap)
{
	return (last_mmap & (SHM_COLOUR-1)) >> PAGE_SHIFT;
}

__attribute__((used)) static unsigned long shared_align_offset(unsigned int last_mmap,
					 unsigned long pgoff)
{
	return (get_offset(last_mmap) + pgoff) << PAGE_SHIFT;
}

__attribute__((used)) static inline unsigned long COLOR_ALIGN(unsigned long addr,
			 unsigned int last_mmap, unsigned long pgoff)
{
	unsigned long base = (addr+SHM_COLOUR-1) & ~(SHM_COLOUR-1);
	unsigned long off  = (SHM_COLOUR-1) &
		(shared_align_offset(last_mmap, pgoff) << PAGE_SHIFT);

	return base + off;
}

__attribute__((used)) static unsigned long mmap_upper_limit(struct rlimit *rlim_stack)
{
	unsigned long stack_base;

	/* Limit stack size - see setup_arg_pages() in fs/exec.c */
	stack_base = rlim_stack ? rlim_stack->rlim_max
				: rlimit_max(RLIMIT_STACK);
	if (stack_base > STACK_SIZE_MAX)
		stack_base = STACK_SIZE_MAX;

	/* Add space for stack randomization. */
	stack_base += (STACK_RND_MASK << PAGE_SHIFT);

	return PAGE_ALIGN(STACK_TOP - stack_base);
}

unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr,
		unsigned long len, unsigned long pgoff, unsigned long flags)
{
	struct mm_struct *mm = current->mm;
	struct vm_area_struct *vma, *prev;
	unsigned long task_size = TASK_SIZE;
	int do_color_align, last_mmap;
	struct vm_unmapped_area_info info;

	if (len > task_size)
		return -ENOMEM;

	do_color_align = 0;
	if (filp || (flags & MAP_SHARED))
		do_color_align = 1;
	last_mmap = GET_LAST_MMAP(filp);

	if (flags & MAP_FIXED) {
		if ((flags & MAP_SHARED) && last_mmap &&
		    (addr - shared_align_offset(last_mmap, pgoff))
				& (SHM_COLOUR - 1))
			return -EINVAL;
		goto found_addr;
	}

	if (addr) {
		if (do_color_align && last_mmap)
			addr = COLOR_ALIGN(addr, last_mmap, pgoff);
		else
			addr = PAGE_ALIGN(addr);

		vma = find_vma_prev(mm, addr, &prev);
		if (task_size - len >= addr &&
		    (!vma || addr + len <= vm_start_gap(vma)) &&
		    (!prev || addr >= vm_end_gap(prev)))
			goto found_addr;
	}

	info.flags = 0;
	info.length = len;
	info.low_limit = mm->mmap_legacy_base;
	info.high_limit = mmap_upper_limit(NULL);
	info.align_mask = last_mmap ? (PAGE_MASK & (SHM_COLOUR - 1)) : 0;
	info.align_offset = shared_align_offset(last_mmap, pgoff);
	addr = vm_unmapped_area(&info);

found_addr:
	if (do_color_align && !last_mmap && !(addr & ~PAGE_MASK))
		SET_LAST_MMAP(filp, addr - (pgoff << PAGE_SHIFT));

	return addr;
}

unsigned long
arch_get_unmapped_area_topdown(struct file *filp, const unsigned long addr0,
			  const unsigned long len, const unsigned long pgoff,
			  const unsigned long flags)
{
	struct vm_area_struct *vma, *prev;
	struct mm_struct *mm = current->mm;
	unsigned long addr = addr0;
	int do_color_align, last_mmap;
	struct vm_unmapped_area_info info;

	/* requested length too big for entire address space */
	if (len > TASK_SIZE)
		return -ENOMEM;

	do_color_align = 0;
	if (filp || (flags & MAP_SHARED))
		do_color_align = 1;
	last_mmap = GET_LAST_MMAP(filp);

	if (flags & MAP_FIXED) {
		if ((flags & MAP_SHARED) && last_mmap &&
		    (addr - shared_align_offset(last_mmap, pgoff))
			& (SHM_COLOUR - 1))
			return -EINVAL;
		goto found_addr;
	}

	/* requesting a specific address */
	if (addr) {
		if (do_color_align && last_mmap)
			addr = COLOR_ALIGN(addr, last_mmap, pgoff);
		else
			addr = PAGE_ALIGN(addr);

		vma = find_vma_prev(mm, addr, &prev);
		if (TASK_SIZE - len >= addr &&
		    (!vma || addr + len <= vm_start_gap(vma)) &&
		    (!prev || addr >= vm_end_gap(prev)))
			goto found_addr;
	}

	info.flags = VM_UNMAPPED_AREA_TOPDOWN;
	info.length = len;
	info.low_limit = PAGE_SIZE;
	info.high_limit = mm->mmap_base;
	info.align_mask = last_mmap ? (PAGE_MASK & (SHM_COLOUR - 1)) : 0;
	info.align_offset = shared_align_offset(last_mmap, pgoff);
	addr = vm_unmapped_area(&info);
	if (!(addr & ~PAGE_MASK))
		goto found_addr;
	VM_BUG_ON(addr != -ENOMEM);

	/*
	 * A failed mmap() very likely causes application failure,
	 * so fall back to the bottom-up function here. This scenario
	 * can happen with large stack limits and large mmap()
	 * allocations.
	 */
	return arch_get_unmapped_area(filp, addr0, len, pgoff, flags);

found_addr:
	if (do_color_align && !last_mmap && !(addr & ~PAGE_MASK))
		SET_LAST_MMAP(filp, addr - (pgoff << PAGE_SHIFT));

	return addr;
}

__attribute__((used)) static int mmap_is_legacy(void)
{
	if (current->personality & ADDR_COMPAT_LAYOUT)
		return 1;

	/* parisc stack always grows up - so a unlimited stack should
	 * not be an indicator to use the legacy memory layout.
	 * if (rlimit(RLIMIT_STACK) == RLIM_INFINITY)
	 *	return 1;
	 */

	return sysctl_legacy_va_layout;
}

__attribute__((used)) static unsigned long mmap_rnd(void)
{
	unsigned long rnd = 0;

	if (current->flags & PF_RANDOMIZE)
		rnd = get_random_int() & MMAP_RND_MASK;

	return rnd << PAGE_SHIFT;
}

unsigned long arch_mmap_rnd(void)
{
	return (get_random_int() & MMAP_RND_MASK) << PAGE_SHIFT;
}

__attribute__((used)) static unsigned long mmap_legacy_base(void)
{
	return TASK_UNMAPPED_BASE + mmap_rnd();
}

void arch_pick_mmap_layout(struct mm_struct *mm, struct rlimit *rlim_stack)
{
	mm->mmap_legacy_base = mmap_legacy_base();
	mm->mmap_base = mmap_upper_limit(rlim_stack);

	if (mmap_is_legacy()) {
		mm->mmap_base = mm->mmap_legacy_base;
		mm->get_unmapped_area = arch_get_unmapped_area;
	} else {
		mm->get_unmapped_area = arch_get_unmapped_area_topdown;
	}
}


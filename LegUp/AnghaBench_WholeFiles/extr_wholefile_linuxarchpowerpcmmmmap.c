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
struct rlimit {scalar_t__ rlim_cur; } ;
struct mm_struct {unsigned long mmap_base; int /*<<< orphan*/  get_unmapped_area; } ;
struct TYPE_2__ {int personality; int flags; } ;

/* Variables and functions */
 int ADDR_COMPAT_LAYOUT ; 
 unsigned long DEFAULT_MAP_WINDOW ; 
 unsigned long MAX_GAP ; 
 unsigned long MIN_GAP ; 
 unsigned long PAGE_ALIGN (unsigned long) ; 
 unsigned long PAGE_SHIFT ; 
 int PF_RANDOMIZE ; 
 scalar_t__ RLIM_INFINITY ; 
 unsigned long TASK_UNMAPPED_BASE ; 
 int /*<<< orphan*/  arch_get_unmapped_area ; 
 int /*<<< orphan*/  arch_get_unmapped_area_topdown ; 
 TYPE_1__* current ; 
 unsigned long get_random_long () ; 
 scalar_t__ is_32bit_task () ; 
 unsigned long mmap_rnd_bits ; 
 void radix__arch_pick_mmap_layout (struct mm_struct*,unsigned long,struct rlimit*) ; 
 scalar_t__ radix_enabled () ; 
 unsigned long stack_guard_gap ; 
 int sysctl_legacy_va_layout ; 

__attribute__((used)) static inline int mmap_is_legacy(struct rlimit *rlim_stack)
{
	if (current->personality & ADDR_COMPAT_LAYOUT)
		return 1;

	if (rlim_stack->rlim_cur == RLIM_INFINITY)
		return 1;

	return sysctl_legacy_va_layout;
}

unsigned long arch_mmap_rnd(void)
{
	unsigned long shift, rnd;

	shift = mmap_rnd_bits;
#ifdef CONFIG_COMPAT
	if (is_32bit_task())
		shift = mmap_rnd_compat_bits;
#endif
	rnd = get_random_long() % (1ul << shift);

	return rnd << PAGE_SHIFT;
}

__attribute__((used)) static inline unsigned long stack_maxrandom_size(void)
{
	if (!(current->flags & PF_RANDOMIZE))
		return 0;

	/* 8MB for 32bit, 1GB for 64bit */
	if (is_32bit_task())
		return (1<<23);
	else
		return (1<<30);
}

__attribute__((used)) static inline unsigned long mmap_base(unsigned long rnd,
				      struct rlimit *rlim_stack)
{
	unsigned long gap = rlim_stack->rlim_cur;
	unsigned long pad = stack_maxrandom_size() + stack_guard_gap;

	/* Values close to RLIM_INFINITY can overflow. */
	if (gap + pad > gap)
		gap += pad;

	if (gap < MIN_GAP)
		gap = MIN_GAP;
	else if (gap > MAX_GAP)
		gap = MAX_GAP;

	return PAGE_ALIGN(DEFAULT_MAP_WINDOW - gap - rnd);
}

void arch_pick_mmap_layout(struct mm_struct *mm, struct rlimit *rlim_stack)
{
	unsigned long random_factor = 0UL;

	if (current->flags & PF_RANDOMIZE)
		random_factor = arch_mmap_rnd();

	if (radix_enabled())
		return radix__arch_pick_mmap_layout(mm, random_factor,
						    rlim_stack);
	/*
	 * Fall back to the standard layout if the personality
	 * bit is set, or if the expected stack growth is unlimited:
	 */
	if (mmap_is_legacy(rlim_stack)) {
		mm->mmap_base = TASK_UNMAPPED_BASE;
		mm->get_unmapped_area = arch_get_unmapped_area;
	} else {
		mm->mmap_base = mmap_base(random_factor, rlim_stack);
		mm->get_unmapped_area = arch_get_unmapped_area_topdown;
	}
}


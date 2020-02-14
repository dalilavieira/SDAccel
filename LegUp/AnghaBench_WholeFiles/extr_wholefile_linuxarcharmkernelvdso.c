#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct vm_special_mapping {int dummy; } ;
struct vm_area_struct {unsigned long vm_end; unsigned long vm_start; } ;
struct vdso_data {int tk_is_cntvct; int xtime_clock_snsec; int cs_shift; int /*<<< orphan*/  tz_dsttime; int /*<<< orphan*/  tz_minuteswest; int /*<<< orphan*/  cs_mask; int /*<<< orphan*/  cs_mult; int /*<<< orphan*/  xtime_clock_sec; int /*<<< orphan*/  cs_cycle_last; int /*<<< orphan*/  wtm_clock_nsec; int /*<<< orphan*/  wtm_clock_sec; scalar_t__ xtime_coarse_nsec; int /*<<< orphan*/  xtime_coarse_sec; int /*<<< orphan*/  seq_count; } ;
struct timespec64 {int /*<<< orphan*/  tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct TYPE_14__ {int xtime_nsec; int shift; int /*<<< orphan*/  mask; int /*<<< orphan*/  mult; int /*<<< orphan*/  cycle_last; TYPE_5__* clock; } ;
struct timekeeper {TYPE_6__ tkr_mono; int /*<<< orphan*/  xtime_sec; struct timespec64 wall_to_monotonic; } ;
struct TYPE_11__ {unsigned long vdso; } ;
struct mm_struct {TYPE_3__ context; } ;
struct TYPE_16__ {TYPE_2__* mm; } ;
struct TYPE_15__ {int /*<<< orphan*/  tz_dsttime; int /*<<< orphan*/  tz_minuteswest; } ;
struct TYPE_12__ {int /*<<< orphan*/  vdso_direct; } ;
struct TYPE_13__ {TYPE_4__ archdata; } ;
struct TYPE_9__ {unsigned long vdso; } ;
struct TYPE_10__ {TYPE_1__ context; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_ARM_ARCH_TIMER ; 
 int EINVAL ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IS_ERR (struct vm_area_struct*) ; 
 int PAGE_SHIFT ; 
 unsigned long PAGE_SIZE ; 
 int PTR_ERR_OR_ZERO (struct vm_area_struct*) ; 
 int VM_EXEC ; 
 int VM_MAYEXEC ; 
 int VM_MAYREAD ; 
 int VM_MAYWRITE ; 
 int VM_READ ; 
 struct vm_area_struct* _install_special_mapping (struct mm_struct*,unsigned long,unsigned long,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cntvct_ok ; 
 TYPE_8__* current ; 
 int /*<<< orphan*/  flush_dcache_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_wmb () ; 
 TYPE_7__ sys_tz ; 
 struct vdso_data* vdso_data ; 
 int /*<<< orphan*/  vdso_data_mapping ; 
 int /*<<< orphan*/  vdso_text_mapping ; 
 int /*<<< orphan*/ * vdso_text_pagelist ; 
 int vdso_total_pages ; 
 int /*<<< orphan*/  virt_to_page (struct vdso_data*) ; 

__attribute__((used)) static int vdso_mremap(const struct vm_special_mapping *sm,
		struct vm_area_struct *new_vma)
{
	unsigned long new_size = new_vma->vm_end - new_vma->vm_start;
	unsigned long vdso_size;

	/* without VVAR page */
	vdso_size = (vdso_total_pages - 1) << PAGE_SHIFT;

	if (vdso_size != new_size)
		return -EINVAL;

	current->mm->context.vdso = new_vma->vm_start;

	return 0;
}

__attribute__((used)) static int install_vvar(struct mm_struct *mm, unsigned long addr)
{
	struct vm_area_struct *vma;

	vma = _install_special_mapping(mm, addr, PAGE_SIZE,
				       VM_READ | VM_MAYREAD,
				       &vdso_data_mapping);

	return PTR_ERR_OR_ZERO(vma);
}

void arm_install_vdso(struct mm_struct *mm, unsigned long addr)
{
	struct vm_area_struct *vma;
	unsigned long len;

	mm->context.vdso = 0;

	if (vdso_text_pagelist == NULL)
		return;

	if (install_vvar(mm, addr))
		return;

	/* Account for vvar page. */
	addr += PAGE_SIZE;
	len = (vdso_total_pages - 1) << PAGE_SHIFT;

	vma = _install_special_mapping(mm, addr, len,
		VM_READ | VM_EXEC | VM_MAYREAD | VM_MAYWRITE | VM_MAYEXEC,
		&vdso_text_mapping);

	if (!IS_ERR(vma))
		mm->context.vdso = addr;
}

__attribute__((used)) static void vdso_write_begin(struct vdso_data *vdata)
{
	++vdso_data->seq_count;
	smp_wmb(); /* Pairs with smp_rmb in vdso_read_retry */
}

__attribute__((used)) static void vdso_write_end(struct vdso_data *vdata)
{
	smp_wmb(); /* Pairs with smp_rmb in vdso_read_begin */
	++vdso_data->seq_count;
}

__attribute__((used)) static bool tk_is_cntvct(const struct timekeeper *tk)
{
	if (!IS_ENABLED(CONFIG_ARM_ARCH_TIMER))
		return false;

	if (!tk->tkr_mono.clock->archdata.vdso_direct)
		return false;

	return true;
}

void update_vsyscall(struct timekeeper *tk)
{
	struct timespec64 *wtm = &tk->wall_to_monotonic;

	if (!cntvct_ok) {
		/* The entry points have been zeroed, so there is no
		 * point in updating the data page.
		 */
		return;
	}

	vdso_write_begin(vdso_data);

	vdso_data->tk_is_cntvct			= tk_is_cntvct(tk);
	vdso_data->xtime_coarse_sec		= tk->xtime_sec;
	vdso_data->xtime_coarse_nsec		= (u32)(tk->tkr_mono.xtime_nsec >>
							tk->tkr_mono.shift);
	vdso_data->wtm_clock_sec		= wtm->tv_sec;
	vdso_data->wtm_clock_nsec		= wtm->tv_nsec;

	if (vdso_data->tk_is_cntvct) {
		vdso_data->cs_cycle_last	= tk->tkr_mono.cycle_last;
		vdso_data->xtime_clock_sec	= tk->xtime_sec;
		vdso_data->xtime_clock_snsec	= tk->tkr_mono.xtime_nsec;
		vdso_data->cs_mult		= tk->tkr_mono.mult;
		vdso_data->cs_shift		= tk->tkr_mono.shift;
		vdso_data->cs_mask		= tk->tkr_mono.mask;
	}

	vdso_write_end(vdso_data);

	flush_dcache_page(virt_to_page(vdso_data));
}

void update_vsyscall_tz(void)
{
	vdso_data->tz_minuteswest	= sys_tz.tz_minuteswest;
	vdso_data->tz_dsttime		= sys_tz.tz_dsttime;
	flush_dcache_page(virt_to_page(vdso_data));
}


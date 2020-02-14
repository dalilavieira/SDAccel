#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int /*<<< orphan*/  vm_page_prot; } ;
struct vdso_data {int cs_shift; int xtime_clock_nsec; int xtime_coarse_nsec; int /*<<< orphan*/  tz_dsttime; int /*<<< orphan*/  tz_minuteswest; int /*<<< orphan*/  xtime_coarse_sec; int /*<<< orphan*/  xtime_clock_sec; int /*<<< orphan*/  wtm_clock_nsec; int /*<<< orphan*/  wtm_clock_sec; int /*<<< orphan*/  cs_cycle_last; int /*<<< orphan*/  cs_mult; int /*<<< orphan*/  cs_mask; int /*<<< orphan*/  seq_count; int /*<<< orphan*/  cycle_count_down; int /*<<< orphan*/  cycle_count_offset; } ;
struct TYPE_9__ {int shift; int xtime_nsec; int /*<<< orphan*/  cycle_last; int /*<<< orphan*/  mult; int /*<<< orphan*/  mask; } ;
struct TYPE_8__ {int /*<<< orphan*/  tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct timekeeper {TYPE_3__ tkr_mono; int /*<<< orphan*/  xtime_sec; TYPE_2__ wall_to_monotonic; } ;
struct TYPE_7__ {int /*<<< orphan*/ * vdso; } ;
struct mm_struct {unsigned long mmap_base; int /*<<< orphan*/  mmap_sem; TYPE_1__ context; } ;
struct linux_binprm {int dummy; } ;
typedef  int /*<<< orphan*/  pgprot_t ;
struct TYPE_12__ {struct mm_struct* mm; } ;
struct TYPE_11__ {int /*<<< orphan*/  tz_dsttime; int /*<<< orphan*/  tz_minuteswest; } ;
struct TYPE_10__ {unsigned long mapping_base; int /*<<< orphan*/  cycle_count_down; int /*<<< orphan*/  cycle_count_reg_offset; } ;

/* Variables and functions */
 int EINTR ; 
 unsigned long EMPTY_VALUE ; 
 scalar_t__ IS_ERR (struct vm_area_struct*) ; 
 scalar_t__ IS_ERR_VALUE (unsigned long) ; 
 unsigned long PAGE_ALIGN (unsigned long) ; 
 unsigned long PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 unsigned long PMD_MASK ; 
 unsigned long PMD_SIZE ; 
 int PTR_ERR (struct vm_area_struct*) ; 
 unsigned long TASK_SIZE ; 
 int VM_EXEC ; 
 int VM_MAYEXEC ; 
 int VM_MAYREAD ; 
 int VM_MAYWRITE ; 
 int VM_READ ; 
 int _PAGE_C_DEV ; 
 int _PAGE_D ; 
 int _PAGE_M_UR_KR ; 
 int _PAGE_V ; 
 int /*<<< orphan*/  __pgprot (int) ; 
 struct vm_area_struct* _install_special_mapping (struct mm_struct*,unsigned long,unsigned long,int,int /*<<< orphan*/ *) ; 
 TYPE_6__* current ; 
 scalar_t__ down_write_killable (int /*<<< orphan*/ *) ; 
 unsigned long get_random_int () ; 
 unsigned long get_unmapped_area (int /*<<< orphan*/ *,unsigned long,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int io_remap_pfn_range (struct vm_area_struct*,unsigned long,unsigned long,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_wmb () ; 
 TYPE_5__ sys_tz ; 
 TYPE_4__ timer_info ; 
 unsigned long timer_mapping_base ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 
 struct vdso_data* vdso_data ; 
 unsigned long vdso_pages ; 
 int /*<<< orphan*/ * vdso_spec ; 
 unsigned long virt_to_phys (struct vdso_data*) ; 

__attribute__((used)) static void get_timer_node_info(void)
{
	timer_mapping_base = timer_info.mapping_base;
	vdso_data->cycle_count_offset =
		timer_info.cycle_count_reg_offset;
	vdso_data->cycle_count_down =
		timer_info.cycle_count_down;
}

unsigned long inline vdso_random_addr(unsigned long vdso_mapping_len)
{
	unsigned long start = current->mm->mmap_base, end, offset, addr;
	start = PAGE_ALIGN(start);

	/* Round the lowest possible end address up to a PMD boundary. */
	end = (start + vdso_mapping_len + PMD_SIZE - 1) & PMD_MASK;
	if (end >= TASK_SIZE)
		end = TASK_SIZE;
	end -= vdso_mapping_len;

	if (end > start) {
		offset = get_random_int() % (((end - start) >> PAGE_SHIFT) + 1);
		addr = start + (offset << PAGE_SHIFT);
	} else {
		addr = start;
	}
	return addr;
}

int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
	struct mm_struct *mm = current->mm;
	unsigned long vdso_base, vdso_text_len, vdso_mapping_len;
	struct vm_area_struct *vma;
	unsigned long addr = 0;
	pgprot_t prot;
	int ret, vvar_page_num = 2;

	vdso_text_len = vdso_pages << PAGE_SHIFT;

	if(timer_mapping_base == EMPTY_VALUE)
		vvar_page_num = 1;
	/* Be sure to map the data page */
	vdso_mapping_len = vdso_text_len + vvar_page_num * PAGE_SIZE;
#ifdef CONFIG_CPU_CACHE_ALIASING
	vdso_mapping_len += L1_cache_info[DCACHE].aliasing_num - 1;
#endif

	if (down_write_killable(&mm->mmap_sem))
		return -EINTR;

	addr = vdso_random_addr(vdso_mapping_len);
	vdso_base = get_unmapped_area(NULL, addr, vdso_mapping_len, 0, 0);
	if (IS_ERR_VALUE(vdso_base)) {
		ret = vdso_base;
		goto up_fail;
	}

#ifdef CONFIG_CPU_CACHE_ALIASING
	{
		unsigned int aliasing_mask =
		    L1_cache_info[DCACHE].aliasing_mask;
		unsigned int page_colour_ofs;
		page_colour_ofs = ((unsigned int)vdso_data & aliasing_mask) -
		    (vdso_base & aliasing_mask);
		vdso_base += page_colour_ofs & aliasing_mask;
	}
#endif

	vma = _install_special_mapping(mm, vdso_base, vvar_page_num * PAGE_SIZE,
				       VM_READ | VM_MAYREAD, &vdso_spec[0]);
	if (IS_ERR(vma)) {
		ret = PTR_ERR(vma);
		goto up_fail;
	}

	/*Map vdata to user space */
	ret = io_remap_pfn_range(vma, vdso_base,
				 virt_to_phys(vdso_data) >> PAGE_SHIFT,
				 PAGE_SIZE, vma->vm_page_prot);
	if (ret)
		goto up_fail;

	/*Map timer to user space */
	vdso_base += PAGE_SIZE;
	prot = __pgprot(_PAGE_V | _PAGE_M_UR_KR | _PAGE_D |  _PAGE_C_DEV);
	ret = io_remap_pfn_range(vma, vdso_base, timer_mapping_base >> PAGE_SHIFT,
				 PAGE_SIZE, prot);
	if (ret)
		goto up_fail;

	/*Map vdso to user space */
	vdso_base += PAGE_SIZE;
	mm->context.vdso = (void *)vdso_base;
	vma = _install_special_mapping(mm, vdso_base, vdso_text_len,
				       VM_READ | VM_EXEC |
				       VM_MAYREAD | VM_MAYWRITE | VM_MAYEXEC,
				       &vdso_spec[1]);
	if (IS_ERR(vma)) {
		ret = PTR_ERR(vma);
		goto up_fail;
	}

	up_write(&mm->mmap_sem);
	return 0;

up_fail:
	mm->context.vdso = NULL;
	up_write(&mm->mmap_sem);
	return ret;
}

__attribute__((used)) static void vdso_write_begin(struct vdso_data *vdata)
{
	++vdso_data->seq_count;
	smp_wmb();		/* Pairs with smp_rmb in vdso_read_retry */
}

__attribute__((used)) static void vdso_write_end(struct vdso_data *vdata)
{
	smp_wmb();		/* Pairs with smp_rmb in vdso_read_begin */
	++vdso_data->seq_count;
}

void update_vsyscall(struct timekeeper *tk)
{
	vdso_write_begin(vdso_data);
	vdso_data->cs_mask = tk->tkr_mono.mask;
	vdso_data->cs_mult = tk->tkr_mono.mult;
	vdso_data->cs_shift = tk->tkr_mono.shift;
	vdso_data->cs_cycle_last = tk->tkr_mono.cycle_last;
	vdso_data->wtm_clock_sec = tk->wall_to_monotonic.tv_sec;
	vdso_data->wtm_clock_nsec = tk->wall_to_monotonic.tv_nsec;
	vdso_data->xtime_clock_sec = tk->xtime_sec;
	vdso_data->xtime_clock_nsec = tk->tkr_mono.xtime_nsec;
	vdso_data->xtime_coarse_sec = tk->xtime_sec;
	vdso_data->xtime_coarse_nsec = tk->tkr_mono.xtime_nsec >>
	    tk->tkr_mono.shift;
	vdso_write_end(vdso_data);
}

void update_vsyscall_tz(void)
{
	vdso_data->tz_minuteswest = sys_tz.tz_minuteswest;
	vdso_data->tz_dsttime = sys_tz.tz_dsttime;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct vm_area_struct {struct mm_struct* vm_mm; } ;
struct pt_regs {int dummy; } ;
struct TYPE_4__ {unsigned long id; } ;
struct mm_struct {int /*<<< orphan*/  pgd; TYPE_1__ context; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
struct TYPE_6__ {unsigned long line_size; unsigned long ways; unsigned long sets; } ;
struct TYPE_5__ {struct mm_struct* mm; } ;

/* Variables and functions */
 int CACHE_CTL_mskDC_EN ; 
 int CACHE_CTL_mskIC_EN ; 
 int /*<<< orphan*/  CCTL_CMD_L2_PA_INVAL ; 
 int /*<<< orphan*/  CCTL_CMD_L2_PA_WB ; 
 int /*<<< orphan*/  CCTL_CMD_L2_PA_WBINVAL ; 
 size_t DCACHE ; 
 int /*<<< orphan*/  GIE_DISABLE () ; 
 size_t ICACHE ; 
 TYPE_3__* L1_cache_info ; 
 int /*<<< orphan*/  NDS32_CCTL_L1D_IX_RWD ; 
 int /*<<< orphan*/  NDS32_SR_CACHE_CTL ; 
 int /*<<< orphan*/  NDS32_SR_L1_PPTB ; 
 int /*<<< orphan*/  NDS32_SR_TLB_MISC ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_SIZE ; 
 unsigned long TLB_MISC_mskCID ; 
 int /*<<< orphan*/  __nds32__cctl_l1d_invalall () ; 
 int /*<<< orphan*/  __nds32__cctl_l1d_wball_one_lvl () ; 
 int /*<<< orphan*/  __nds32__cctlidx_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nds32__isb () ; 
 void* __nds32__mfsr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nds32__msync_all () ; 
 int /*<<< orphan*/  __nds32__mtsr_dsb (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nds32__mtsr_isb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nds32__standby_no_wake_grant () ; 
 int __pa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_l2cache_op (unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  pgd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pgd_offset (struct mm_struct*,unsigned long) ; 
 int /*<<< orphan*/ * pgd_offset_k (unsigned long) ; 
 int /*<<< orphan*/  pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pte_kernel_write (int) ; 
 int* pte_offset_map (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pte_present (int) ; 
 scalar_t__ pte_read (int) ; 
 scalar_t__ pte_write (int) ; 
 int /*<<< orphan*/  pud_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 

int va_kernel_present(unsigned long addr)
{
	pmd_t *pmd;
	pte_t *ptep, pte;

	pmd = pmd_offset(pgd_offset_k(addr), addr);
	if (!pmd_none(*pmd)) {
		ptep = pte_offset_map(pmd, addr);
		pte = *ptep;
		if (pte_present(pte))
			return pte;
	}
	return 0;
}

pte_t va_present(struct mm_struct * mm, unsigned long addr)
{
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *ptep, pte;

	pgd = pgd_offset(mm, addr);
	if (!pgd_none(*pgd)) {
		pud = pud_offset(pgd, addr);
		if (!pud_none(*pud)) {
			pmd = pmd_offset(pud, addr);
			if (!pmd_none(*pmd)) {
				ptep = pte_offset_map(pmd, addr);
				pte = *ptep;
				if (pte_present(pte))
					return pte;
			}
		}
	}
	return 0;

}

int va_readable(struct pt_regs *regs, unsigned long addr)
{
	struct mm_struct *mm = current->mm;
	pte_t pte;
	int ret = 0;

	if (user_mode(regs)) {
		/* user mode */
		pte = va_present(mm, addr);
		if (!pte && pte_read(pte))
			ret = 1;
	} else {
		/* superuser mode is always readable, so we can only
		 * check it is present or not*/
		return (! !va_kernel_present(addr));
	}
	return ret;
}

int va_writable(struct pt_regs *regs, unsigned long addr)
{
	struct mm_struct *mm = current->mm;
	pte_t pte;
	int ret = 0;

	if (user_mode(regs)) {
		/* user mode */
		pte = va_present(mm, addr);
		if (!pte && pte_write(pte))
			ret = 1;
	} else {
		/* superuser mode */
		pte = va_kernel_present(addr);
		if (!pte && pte_kernel_write(pte))
			ret = 1;
	}
	return ret;
}

void cpu_icache_inval_all(void)
{
	unsigned long end, line_size;

	line_size = L1_cache_info[ICACHE].line_size;
	end =
	    line_size * L1_cache_info[ICACHE].ways * L1_cache_info[ICACHE].sets;

	do {
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL"::"r" (end));
	} while (end > 0);
	__nds32__isb();
}

void cpu_dcache_inval_all(void)
{
	__nds32__cctl_l1d_invalall();
}

void cpu_dcache_wb_all(void)
{
	__nds32__cctl_l1d_wball_one_lvl();
	__nds32__cctlidx_read(NDS32_CCTL_L1D_IX_RWD,0);
}

void cpu_dcache_wbinval_all(void)
{
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
	unsigned long flags;
	local_irq_save(flags);
#endif
	cpu_dcache_wb_all();
	cpu_dcache_inval_all();
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
	local_irq_restore(flags);
#endif
}

void cpu_icache_inval_page(unsigned long start)
{
	unsigned long line_size, end;

	line_size = L1_cache_info[ICACHE].line_size;
	end = start + PAGE_SIZE;

	do {
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (end));
	} while (end != start);
	__nds32__isb();
}

void cpu_dcache_inval_page(unsigned long start)
{
	unsigned long line_size, end;

	line_size = L1_cache_info[DCACHE].line_size;
	end = start + PAGE_SIZE;

	do {
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
	} while (end != start);
}

void cpu_dcache_wb_page(unsigned long start)
{
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
	unsigned long line_size, end;

	line_size = L1_cache_info[DCACHE].line_size;
	end = start + PAGE_SIZE;

	do {
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
		end -= line_size;
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
	} while (end != start);
	__nds32__cctlidx_read(NDS32_CCTL_L1D_IX_RWD,0);
#endif
}

void cpu_dcache_wbinval_page(unsigned long start)
{
	unsigned long line_size, end;

	line_size = L1_cache_info[DCACHE].line_size;
	end = start + PAGE_SIZE;

	do {
		end -= line_size;
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
#endif
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
		end -= line_size;
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
#endif
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
		end -= line_size;
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
#endif
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
		end -= line_size;
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (end));
#endif
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (end));
	} while (end != start);
	__nds32__cctlidx_read(NDS32_CCTL_L1D_IX_RWD,0);
}

void cpu_cache_wbinval_page(unsigned long page, int flushi)
{
	cpu_dcache_wbinval_page(page);
	if (flushi)
		cpu_icache_inval_page(page);
}

void cpu_icache_inval_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;

	line_size = L1_cache_info[ICACHE].line_size;

	while (end > start) {
		__asm__ volatile ("\n\tcctl %0, L1I_VA_INVAL"::"r" (start));
		start += line_size;
	}
	__nds32__isb();
}

void cpu_dcache_inval_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;

	line_size = L1_cache_info[DCACHE].line_size;

	while (end > start) {
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (start));
		start += line_size;
	}
}

void cpu_dcache_wb_range(unsigned long start, unsigned long end)
{
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
	unsigned long line_size;

	line_size = L1_cache_info[DCACHE].line_size;

	while (end > start) {
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (start));
		start += line_size;
	}
	__nds32__cctlidx_read(NDS32_CCTL_L1D_IX_RWD,0);
#endif
}

void cpu_dcache_wbinval_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;

	line_size = L1_cache_info[DCACHE].line_size;

	while (end > start) {
#ifndef CONFIG_CPU_DCACHE_WRITETHROUGH
		__asm__ volatile ("\n\tcctl %0, L1D_VA_WB"::"r" (start));
#endif
		__asm__ volatile ("\n\tcctl %0, L1D_VA_INVAL"::"r" (start));
		start += line_size;
	}
	__nds32__cctlidx_read(NDS32_CCTL_L1D_IX_RWD,0);
}

void cpu_cache_wbinval_range(unsigned long start, unsigned long end, int flushi)
{
	unsigned long line_size, align_start, align_end;

	line_size = L1_cache_info[DCACHE].line_size;
	align_start = start & ~(line_size - 1);
	align_end = (end + line_size - 1) & ~(line_size - 1);
	cpu_dcache_wbinval_range(align_start, align_end);

	if (flushi) {
		line_size = L1_cache_info[ICACHE].line_size;
		align_start = start & ~(line_size - 1);
		align_end = (end + line_size - 1) & ~(line_size - 1);
		cpu_icache_inval_range(align_start, align_end);
	}
}

void cpu_cache_wbinval_range_check(struct vm_area_struct *vma,
				   unsigned long start, unsigned long end,
				   bool flushi, bool wbd)
{
	unsigned long line_size, t_start, t_end;

	if (!flushi && !wbd)
		return;
	line_size = L1_cache_info[DCACHE].line_size;
	start = start & ~(line_size - 1);
	end = (end + line_size - 1) & ~(line_size - 1);

	if ((end - start) > (8 * PAGE_SIZE)) {
		if (wbd)
			cpu_dcache_wbinval_all();
		if (flushi)
			cpu_icache_inval_all();
		return;
	}

	t_start = (start + PAGE_SIZE) & PAGE_MASK;
	t_end = ((end - 1) & PAGE_MASK);

	if ((start & PAGE_MASK) == t_end) {
		if (va_present(vma->vm_mm, start)) {
			if (wbd)
				cpu_dcache_wbinval_range(start, end);
			if (flushi)
				cpu_icache_inval_range(start, end);
		}
		return;
	}

	if (va_present(vma->vm_mm, start)) {
		if (wbd)
			cpu_dcache_wbinval_range(start, t_start);
		if (flushi)
			cpu_icache_inval_range(start, t_start);
	}

	if (va_present(vma->vm_mm, end - 1)) {
		if (wbd)
			cpu_dcache_wbinval_range(t_end, end);
		if (flushi)
			cpu_icache_inval_range(t_end, end);
	}

	while (t_start < t_end) {
		if (va_present(vma->vm_mm, t_start)) {
			if (wbd)
				cpu_dcache_wbinval_page(t_start);
			if (flushi)
				cpu_icache_inval_page(t_start);
		}
		t_start += PAGE_SIZE;
	}
}

void cpu_dma_wb_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;
	unsigned long flags;
	line_size = L1_cache_info[DCACHE].line_size;
	start = start & (~(line_size - 1));
	end = (end + line_size - 1) & (~(line_size - 1));
	if (unlikely(start == end))
		return;

	local_irq_save(flags);
	cpu_dcache_wb_range(start, end);
	cpu_l2cache_op(start, end, CCTL_CMD_L2_PA_WB);
	__nds32__msync_all();
	local_irq_restore(flags);
}

void cpu_dma_inval_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;
	unsigned long old_start = start;
	unsigned long old_end = end;
	unsigned long flags;
	line_size = L1_cache_info[DCACHE].line_size;
	start = start & (~(line_size - 1));
	end = (end + line_size - 1) & (~(line_size - 1));
	if (unlikely(start == end))
		return;
	local_irq_save(flags);
	if (start != old_start) {
		cpu_dcache_wbinval_range(start, start + line_size);
		cpu_l2cache_op(start, start + line_size, CCTL_CMD_L2_PA_WBINVAL);
	}
	if (end != old_end) {
		cpu_dcache_wbinval_range(end - line_size, end);
		cpu_l2cache_op(end - line_size, end, CCTL_CMD_L2_PA_WBINVAL);
	}
	cpu_dcache_inval_range(start, end);
	cpu_l2cache_op(start, end, CCTL_CMD_L2_PA_INVAL);
	__nds32__msync_all();
	local_irq_restore(flags);

}

void cpu_dma_wbinval_range(unsigned long start, unsigned long end)
{
	unsigned long line_size;
	unsigned long flags;
	line_size = L1_cache_info[DCACHE].line_size;
	start = start & (~(line_size - 1));
	end = (end + line_size - 1) & (~(line_size - 1));
	if (unlikely(start == end))
		return;

	local_irq_save(flags);
	cpu_dcache_wbinval_range(start, end);
	cpu_l2cache_op(start, end, CCTL_CMD_L2_PA_WBINVAL);
	__nds32__msync_all();
	local_irq_restore(flags);
}

void cpu_proc_init(void)
{
}

void cpu_proc_fin(void)
{
}

void cpu_do_idle(void)
{
	__nds32__standby_no_wake_grant();
}

void cpu_reset(unsigned long reset)
{
	u32 tmp;
	GIE_DISABLE();
	tmp = __nds32__mfsr(NDS32_SR_CACHE_CTL);
	tmp &= ~(CACHE_CTL_mskIC_EN | CACHE_CTL_mskDC_EN);
	__nds32__mtsr_isb(tmp, NDS32_SR_CACHE_CTL);
	cpu_dcache_wbinval_all();
	cpu_icache_inval_all();

	__asm__ __volatile__("jr.toff %0\n\t"::"r"(reset));
}

void cpu_switch_mm(struct mm_struct *mm)
{
	unsigned long cid;
	cid = __nds32__mfsr(NDS32_SR_TLB_MISC);
	cid = (cid & ~TLB_MISC_mskCID) | mm->context.id;
	__nds32__mtsr_dsb(cid, NDS32_SR_TLB_MISC);
	__nds32__mtsr_isb(__pa(mm->pgd), NDS32_SR_L1_PPTB);
}


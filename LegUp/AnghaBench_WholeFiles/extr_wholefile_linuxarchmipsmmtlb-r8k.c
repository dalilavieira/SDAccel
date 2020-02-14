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
struct vm_area_struct {scalar_t__ vm_mm; } ;
struct mm_struct {int dummy; } ;
struct cpuinfo_mips {int tlbsize; } ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
struct TYPE_2__ {scalar_t__ active_mm; } ;

/* Variables and functions */
 int CKSEG0 ; 
 unsigned long PAGE_MASK ; 
 int PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 unsigned long ST0_KPS ; 
 unsigned long ST0_UPS ; 
 int TFP_TLB_SET_SHIFT ; 
 int TFP_TLB_SIZE ; 
 int /*<<< orphan*/  build_tlb_refill_handler () ; 
 int cpu_asid (int,struct mm_struct*) ; 
 int cpu_asid_mask (struct cpuinfo_mips*) ; 
 scalar_t__ cpu_context (int,struct mm_struct*) ; 
 TYPE_1__* current ; 
 struct cpuinfo_mips current_cpu_data ; 
 int /*<<< orphan*/  drop_mmu_context (struct mm_struct*,int) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mtc0_tlbw_hazard () ; 
 int /*<<< orphan*/ * pgd_offset (scalar_t__,unsigned long) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/ * pte_offset_map (int /*<<< orphan*/ *,unsigned long) ; 
 int pte_val (int /*<<< orphan*/ ) ; 
 unsigned int read_c0_config () ; 
 int read_c0_entryhi () ; 
 unsigned long read_c0_status () ; 
 long read_c0_tlbset () ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  tlb_probe () ; 
 int /*<<< orphan*/  tlb_write () ; 
 int /*<<< orphan*/  tlbw_use_hazard () ; 
 int /*<<< orphan*/  write_c0_entryhi (int) ; 
 int /*<<< orphan*/  write_c0_entrylo (int) ; 
 int /*<<< orphan*/  write_c0_status (unsigned long) ; 
 int /*<<< orphan*/  write_c0_tlbset (int) ; 
 int /*<<< orphan*/  write_c0_vaddr (unsigned long) ; 
 int /*<<< orphan*/  write_c0_wired (int /*<<< orphan*/ ) ; 

void local_flush_tlb_all(void)
{
	unsigned long flags;
	unsigned long old_ctx;
	int entry;

	local_irq_save(flags);
	/* Save old context and create impossible VPN2 value */
	old_ctx = read_c0_entryhi();
	write_c0_entrylo(0);

	for (entry = 0; entry < TFP_TLB_SIZE; entry++) {
		write_c0_tlbset(entry >> TFP_TLB_SET_SHIFT);
		write_c0_vaddr(entry << PAGE_SHIFT);
		write_c0_entryhi(CKSEG0 + (entry << (PAGE_SHIFT + 1)));
		mtc0_tlbw_hazard();
		tlb_write();
	}
	tlbw_use_hazard();
	write_c0_entryhi(old_ctx);
	local_irq_restore(flags);
}

void local_flush_tlb_mm(struct mm_struct *mm)
{
	int cpu = smp_processor_id();

	if (cpu_context(cpu, mm) != 0)
		drop_mmu_context(mm, cpu);
}

void local_flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
	unsigned long end)
{
	struct mm_struct *mm = vma->vm_mm;
	int cpu = smp_processor_id();
	unsigned long flags;
	int oldpid, newpid, size;

	if (!cpu_context(cpu, mm))
		return;

	size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
	size = (size + 1) >> 1;

	local_irq_save(flags);

	if (size > TFP_TLB_SIZE / 2) {
		drop_mmu_context(mm, cpu);
		goto out_restore;
	}

	oldpid = read_c0_entryhi();
	newpid = cpu_asid(cpu, mm);

	write_c0_entrylo(0);

	start &= PAGE_MASK;
	end += (PAGE_SIZE - 1);
	end &= PAGE_MASK;
	while (start < end) {
		signed long idx;

		write_c0_vaddr(start);
		write_c0_entryhi(start);
		start += PAGE_SIZE;
		tlb_probe();
		idx = read_c0_tlbset();
		if (idx < 0)
			continue;

		write_c0_entryhi(CKSEG0 + (idx << (PAGE_SHIFT + 1)));
		tlb_write();
	}
	write_c0_entryhi(oldpid);

out_restore:
	local_irq_restore(flags);
}

void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
	unsigned long size, flags;

	size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
	size = (size + 1) >> 1;

	if (size > TFP_TLB_SIZE / 2) {
		local_flush_tlb_all();
		return;
	}

	local_irq_save(flags);

	write_c0_entrylo(0);

	start &= PAGE_MASK;
	end += (PAGE_SIZE - 1);
	end &= PAGE_MASK;
	while (start < end) {
		signed long idx;

		write_c0_vaddr(start);
		write_c0_entryhi(start);
		start += PAGE_SIZE;
		tlb_probe();
		idx = read_c0_tlbset();
		if (idx < 0)
			continue;

		write_c0_entryhi(CKSEG0 + (idx << (PAGE_SHIFT + 1)));
		tlb_write();
	}

	local_irq_restore(flags);
}

void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
	int cpu = smp_processor_id();
	unsigned long flags;
	int oldpid, newpid;
	signed long idx;

	if (!cpu_context(cpu, vma->vm_mm))
		return;

	newpid = cpu_asid(cpu, vma->vm_mm);
	page &= PAGE_MASK;
	local_irq_save(flags);
	oldpid = read_c0_entryhi();
	write_c0_vaddr(page);
	write_c0_entryhi(newpid);
	tlb_probe();
	idx = read_c0_tlbset();
	if (idx < 0)
		goto finish;

	write_c0_entrylo(0);
	write_c0_entryhi(CKSEG0 + (idx << (PAGE_SHIFT + 1)));
	tlb_write();

finish:
	write_c0_entryhi(oldpid);
	local_irq_restore(flags);
}

void __update_tlb(struct vm_area_struct * vma, unsigned long address, pte_t pte)
{
	unsigned long flags;
	pgd_t *pgdp;
	pmd_t *pmdp;
	pte_t *ptep;
	int pid;

	/*
	 * Handle debugger faulting in for debugee.
	 */
	if (current->active_mm != vma->vm_mm)
		return;

	pid = read_c0_entryhi() & cpu_asid_mask(&current_cpu_data);

	local_irq_save(flags);
	address &= PAGE_MASK;
	write_c0_vaddr(address);
	write_c0_entryhi(pid);
	pgdp = pgd_offset(vma->vm_mm, address);
	pmdp = pmd_offset(pgdp, address);
	ptep = pte_offset_map(pmdp, address);
	tlb_probe();

	write_c0_entrylo(pte_val(*ptep++) >> 6);
	tlb_write();

	write_c0_entryhi(pid);
	local_irq_restore(flags);
}

__attribute__((used)) static void probe_tlb(unsigned long config)
{
	struct cpuinfo_mips *c = &current_cpu_data;

	c->tlbsize = 3 * 128;		/* 3 sets each 128 entries */
}

void tlb_init(void)
{
	unsigned int config = read_c0_config();
	unsigned long status;

	probe_tlb(config);

	status = read_c0_status();
	status &= ~(ST0_UPS | ST0_KPS);
#ifdef CONFIG_PAGE_SIZE_4KB
	status |= (TFP_PAGESIZE_4K << 32) | (TFP_PAGESIZE_4K << 36);
#elif defined(CONFIG_PAGE_SIZE_8KB)
	status |= (TFP_PAGESIZE_8K << 32) | (TFP_PAGESIZE_8K << 36);
#elif defined(CONFIG_PAGE_SIZE_16KB)
	status |= (TFP_PAGESIZE_16K << 32) | (TFP_PAGESIZE_16K << 36);
#elif defined(CONFIG_PAGE_SIZE_64KB)
	status |= (TFP_PAGESIZE_64K << 32) | (TFP_PAGESIZE_64K << 36);
#endif
	write_c0_status(status);

	write_c0_wired(0);

	local_flush_tlb_all();

	build_tlb_refill_handler();
}


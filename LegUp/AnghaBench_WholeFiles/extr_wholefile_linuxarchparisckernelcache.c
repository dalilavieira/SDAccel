#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {unsigned long vm_end; unsigned long vm_start; int vm_flags; TYPE_1__* vm_mm; struct vm_area_struct* vm_next; } ;
struct seq_file {int dummy; } ;
struct page {int /*<<< orphan*/  flags; } ;
struct mm_struct {scalar_t__ context; struct vm_area_struct* mmap; int /*<<< orphan*/ * pgd; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
struct TYPE_12__ {int /*<<< orphan*/  num_comb; int /*<<< orphan*/  num_d; int /*<<< orphan*/  num_i; } ;
struct TYPE_11__ {int /*<<< orphan*/  num_comb; int /*<<< orphan*/  num_d; int /*<<< orphan*/  num_i; } ;
struct TYPE_14__ {int max_size; TYPE_5__ variable_range_info; TYPE_4__ fixed_range_info; } ;
struct TYPE_10__ {scalar_t__ tc_sh; } ;
struct TYPE_9__ {scalar_t__ cc_sh; scalar_t__ cc_wt; } ;
struct TYPE_13__ {int ic_size; int dc_loop; int dc_size; TYPE_3__ dt_conf; int /*<<< orphan*/  dt_size; int /*<<< orphan*/  it_size; TYPE_2__ dc_conf; } ;
struct TYPE_8__ {scalar_t__ context; int /*<<< orphan*/ * pgd; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_SMP ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  PFN_PHYS (unsigned long) ; 
 int /*<<< orphan*/  PG_dcache_dirty ; 
 int VM_EXEC ; 
 int /*<<< orphan*/  __flush_cache_page (struct vm_area_struct*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __pa (void*) ; 
 int /*<<< orphan*/  arch_irqs_disabled () ; 
 TYPE_7__ btlb_info ; 
 TYPE_6__ cache_info ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  copy_page_asm (void*,void*) ; 
 int /*<<< orphan*/  flush_data_cache () ; 
 int /*<<< orphan*/  flush_data_cache_local (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flush_dcache_page_asm (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  flush_instruction_cache_local (int /*<<< orphan*/ *) ; 
 void flush_kernel_dcache_page_addr (void*) ; 
 int /*<<< orphan*/  flush_kernel_dcache_page_asm (void*) ; 
 int /*<<< orphan*/  flush_kernel_dcache_range_asm (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  flush_tlb_all () ; 
 int /*<<< orphan*/  flush_tlb_kernel_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  flush_tlb_page (struct vm_area_struct*,unsigned long) ; 
 int /*<<< orphan*/  flush_tlb_range (struct vm_area_struct*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  flush_user_dcache_range_asm (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  flush_user_icache_range_asm (unsigned long,unsigned long) ; 
 scalar_t__ likely (int) ; 
 scalar_t__ mfsp (int) ; 
 int /*<<< orphan*/  mtsp (unsigned long,int) ; 
 int /*<<< orphan*/  on_each_cpu (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 scalar_t__ page_mapping_file (struct page*) ; 
 unsigned long parisc_cache_flush_threshold ; 
 scalar_t__ parisc_requires_coherency () ; 
 unsigned long parisc_tlb_flush_threshold ; 
 int /*<<< orphan*/  pdtlb (unsigned long) ; 
 int /*<<< orphan*/  pdtlb_kernel (void*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 void* pfn_va (unsigned long) ; 
 scalar_t__ pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  pgd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pitlb (unsigned long) ; 
 int /*<<< orphan*/  pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/ * pte_offset_map (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned long pte_pfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pud_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  purge_kernel_dcache_range_asm (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  purge_tlb_end (unsigned long) ; 
 int /*<<< orphan*/  purge_tlb_start (unsigned long) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  split_tlb ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (scalar_t__) ; 

void
flush_cache_all_local(void)
{
	flush_instruction_cache_local(NULL);
	flush_data_cache_local(NULL);
}

void
update_mmu_cache(struct vm_area_struct *vma, unsigned long address, pte_t *ptep)
{
	unsigned long pfn = pte_pfn(*ptep);
	struct page *page;

	/* We don't have pte special.  As a result, we can be called with
	   an invalid pfn and we don't need to flush the kernel dcache page.
	   This occurs with FireGL card in C8000.  */
	if (!pfn_valid(pfn))
		return;

	page = pfn_to_page(pfn);
	if (page_mapping_file(page) &&
	    test_bit(PG_dcache_dirty, &page->flags)) {
		flush_kernel_dcache_page_addr(pfn_va(pfn));
		clear_bit(PG_dcache_dirty, &page->flags);
	} else if (parisc_requires_coherency())
		flush_kernel_dcache_page_addr(pfn_va(pfn));
}

void
show_cache_info(struct seq_file *m)
{
	char buf[32];

	seq_printf(m, "I-cache\t\t: %ld KB\n", 
		cache_info.ic_size/1024 );
	if (cache_info.dc_loop != 1)
		snprintf(buf, 32, "%lu-way associative", cache_info.dc_loop);
	seq_printf(m, "D-cache\t\t: %ld KB (%s%s, %s)\n",
		cache_info.dc_size/1024,
		(cache_info.dc_conf.cc_wt ? "WT":"WB"),
		(cache_info.dc_conf.cc_sh ? ", shared I/D":""),
		((cache_info.dc_loop == 1) ? "direct mapped" : buf));
	seq_printf(m, "ITLB entries\t: %ld\n" "DTLB entries\t: %ld%s\n",
		cache_info.it_size,
		cache_info.dt_size,
		cache_info.dt_conf.tc_sh ? " - shared with ITLB":""
	);
		
#ifndef CONFIG_PA20
	/* BTLB - Block TLB */
	if (btlb_info.max_size==0) {
		seq_printf(m, "BTLB\t\t: not supported\n" );
	} else {
		seq_printf(m, 
		"BTLB fixed\t: max. %d pages, pagesize=%d (%dMB)\n"
		"BTLB fix-entr.\t: %d instruction, %d data (%d combined)\n"
		"BTLB var-entr.\t: %d instruction, %d data (%d combined)\n",
		btlb_info.max_size, (int)4096,
		btlb_info.max_size>>8,
		btlb_info.fixed_range_info.num_i,
		btlb_info.fixed_range_info.num_d,
		btlb_info.fixed_range_info.num_comb, 
		btlb_info.variable_range_info.num_i,
		btlb_info.variable_range_info.num_d,
		btlb_info.variable_range_info.num_comb
		);
	}
#endif
}

void flush_kernel_dcache_page_addr(void *addr)
{
	unsigned long flags;

	flush_kernel_dcache_page_asm(addr);
	purge_tlb_start(flags);
	pdtlb_kernel(addr);
	purge_tlb_end(flags);
}

void copy_user_page(void *vto, void *vfrom, unsigned long vaddr,
	struct page *pg)
{
       /* Copy using kernel mapping.  No coherency is needed (all in
	  kunmap) for the `to' page.  However, the `from' page needs to
	  be flushed through a mapping equivalent to the user mapping
	  before it can be accessed through the kernel mapping. */
	preempt_disable();
	flush_dcache_page_asm(__pa(vfrom), vaddr);
	copy_page_asm(vto, vfrom);
	preempt_enable();
}

int __flush_tlb_range(unsigned long sid, unsigned long start,
		      unsigned long end)
{
	unsigned long flags;

	if ((!IS_ENABLED(CONFIG_SMP) || !arch_irqs_disabled()) &&
	    end - start >= parisc_tlb_flush_threshold) {
		flush_tlb_all();
		return 1;
	}

	/* Purge TLB entries for small ranges using the pdtlb and
	   pitlb instructions.  These instructions execute locally
	   but cause a purge request to be broadcast to other TLBs.  */
	if (likely(!split_tlb)) {
		while (start < end) {
			purge_tlb_start(flags);
			mtsp(sid, 1);
			pdtlb(start);
			purge_tlb_end(flags);
			start += PAGE_SIZE;
		}
		return 0;
	}

	/* split TLB case */
	while (start < end) {
		purge_tlb_start(flags);
		mtsp(sid, 1);
		pdtlb(start);
		pitlb(start);
		purge_tlb_end(flags);
		start += PAGE_SIZE;
	}
	return 0;
}

__attribute__((used)) static void cacheflush_h_tmp_function(void *dummy)
{
	flush_cache_all_local();
}

void flush_cache_all(void)
{
	on_each_cpu(cacheflush_h_tmp_function, NULL, 1);
}

__attribute__((used)) static inline unsigned long mm_total_size(struct mm_struct *mm)
{
	struct vm_area_struct *vma;
	unsigned long usize = 0;

	for (vma = mm->mmap; vma; vma = vma->vm_next)
		usize += vma->vm_end - vma->vm_start;
	return usize;
}

__attribute__((used)) static inline pte_t *get_ptep(pgd_t *pgd, unsigned long addr)
{
	pte_t *ptep = NULL;

	if (!pgd_none(*pgd)) {
		pud_t *pud = pud_offset(pgd, addr);
		if (!pud_none(*pud)) {
			pmd_t *pmd = pmd_offset(pud, addr);
			if (!pmd_none(*pmd))
				ptep = pte_offset_map(pmd, addr);
		}
	}
	return ptep;
}

void flush_cache_mm(struct mm_struct *mm)
{
	struct vm_area_struct *vma;
	pgd_t *pgd;

	/* Flushing the whole cache on each cpu takes forever on
	   rp3440, etc.  So, avoid it if the mm isn't too big.  */
	if ((!IS_ENABLED(CONFIG_SMP) || !arch_irqs_disabled()) &&
	    mm_total_size(mm) >= parisc_cache_flush_threshold) {
		if (mm->context)
			flush_tlb_all();
		flush_cache_all();
		return;
	}

	if (mm->context == mfsp(3)) {
		for (vma = mm->mmap; vma; vma = vma->vm_next) {
			flush_user_dcache_range_asm(vma->vm_start, vma->vm_end);
			if (vma->vm_flags & VM_EXEC)
				flush_user_icache_range_asm(vma->vm_start, vma->vm_end);
			flush_tlb_range(vma, vma->vm_start, vma->vm_end);
		}
		return;
	}

	pgd = mm->pgd;
	for (vma = mm->mmap; vma; vma = vma->vm_next) {
		unsigned long addr;

		for (addr = vma->vm_start; addr < vma->vm_end;
		     addr += PAGE_SIZE) {
			unsigned long pfn;
			pte_t *ptep = get_ptep(pgd, addr);
			if (!ptep)
				continue;
			pfn = pte_pfn(*ptep);
			if (!pfn_valid(pfn))
				continue;
			if (unlikely(mm->context))
				flush_tlb_page(vma, addr);
			__flush_cache_page(vma, addr, PFN_PHYS(pfn));
		}
	}
}

void flush_cache_range(struct vm_area_struct *vma,
		unsigned long start, unsigned long end)
{
	pgd_t *pgd;
	unsigned long addr;

	if ((!IS_ENABLED(CONFIG_SMP) || !arch_irqs_disabled()) &&
	    end - start >= parisc_cache_flush_threshold) {
		if (vma->vm_mm->context)
			flush_tlb_range(vma, start, end);
		flush_cache_all();
		return;
	}

	if (vma->vm_mm->context == mfsp(3)) {
		flush_user_dcache_range_asm(start, end);
		if (vma->vm_flags & VM_EXEC)
			flush_user_icache_range_asm(start, end);
		flush_tlb_range(vma, start, end);
		return;
	}

	pgd = vma->vm_mm->pgd;
	for (addr = vma->vm_start; addr < vma->vm_end; addr += PAGE_SIZE) {
		unsigned long pfn;
		pte_t *ptep = get_ptep(pgd, addr);
		if (!ptep)
			continue;
		pfn = pte_pfn(*ptep);
		if (pfn_valid(pfn)) {
			if (unlikely(vma->vm_mm->context))
				flush_tlb_page(vma, addr);
			__flush_cache_page(vma, addr, PFN_PHYS(pfn));
		}
	}
}

void
flush_cache_page(struct vm_area_struct *vma, unsigned long vmaddr, unsigned long pfn)
{
	if (pfn_valid(pfn)) {
		if (likely(vma->vm_mm->context))
			flush_tlb_page(vma, vmaddr);
		__flush_cache_page(vma, vmaddr, PFN_PHYS(pfn));
	}
}

void flush_kernel_vmap_range(void *vaddr, int size)
{
	unsigned long start = (unsigned long)vaddr;
	unsigned long end = start + size;

	if ((!IS_ENABLED(CONFIG_SMP) || !arch_irqs_disabled()) &&
	    (unsigned long)size >= parisc_cache_flush_threshold) {
		flush_tlb_kernel_range(start, end);
		flush_data_cache();
		return;
	}

	flush_kernel_dcache_range_asm(start, end);
	flush_tlb_kernel_range(start, end);
}

void invalidate_kernel_vmap_range(void *vaddr, int size)
{
	unsigned long start = (unsigned long)vaddr;
	unsigned long end = start + size;

	if ((!IS_ENABLED(CONFIG_SMP) || !arch_irqs_disabled()) &&
	    (unsigned long)size >= parisc_cache_flush_threshold) {
		flush_tlb_kernel_range(start, end);
		flush_data_cache();
		return;
	}

	purge_kernel_dcache_range_asm(start, end);
	flush_tlb_kernel_range(start, end);
}


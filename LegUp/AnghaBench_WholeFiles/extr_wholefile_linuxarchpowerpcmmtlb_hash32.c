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
struct vm_area_struct {unsigned long vm_start; unsigned long vm_end; struct mm_struct* vm_mm; struct vm_area_struct* vm_next; } ;
struct mmu_gather {int dummy; } ;
struct TYPE_2__ {unsigned int id; } ;
struct mm_struct {TYPE_1__ context; struct vm_area_struct* mmap; } ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  phys_addr_t ;

/* Variables and functions */
 scalar_t__ Hash ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long PGDIR_MASK ; 
 unsigned long PGDIR_SIZE ; 
 unsigned long TASK_SIZE ; 
 unsigned long __pa (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _tlbia () ; 
 int /*<<< orphan*/  _tlbie (unsigned long) ; 
 int /*<<< orphan*/  flush_hash_pages (unsigned int,unsigned long,unsigned long,int) ; 
 struct mm_struct init_mm ; 
 int /*<<< orphan*/  pgd_offset (struct mm_struct*,unsigned long) ; 
 int /*<<< orphan*/  pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long pmd_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pud_offset (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static inline phys_addr_t v_block_mapped(unsigned long va) { return 0; }

__attribute__((used)) static inline unsigned long p_block_mapped(phys_addr_t pa) { return 0; }

void flush_hash_entry(struct mm_struct *mm, pte_t *ptep, unsigned long addr)
{
	unsigned long ptephys;

	if (Hash) {
		ptephys = __pa(ptep) & PAGE_MASK;
		flush_hash_pages(mm->context.id, addr, ptephys, 1);
	}
}

void tlb_flush(struct mmu_gather *tlb)
{
	if (!Hash) {
		/*
		 * 603 needs to flush the whole TLB here since
		 * it doesn't use a hash table.
		 */
		_tlbia();
	}
}

__attribute__((used)) static void flush_range(struct mm_struct *mm, unsigned long start,
			unsigned long end)
{
	pmd_t *pmd;
	unsigned long pmd_end;
	int count;
	unsigned int ctx = mm->context.id;

	if (!Hash) {
		_tlbia();
		return;
	}
	start &= PAGE_MASK;
	if (start >= end)
		return;
	end = (end - 1) | ~PAGE_MASK;
	pmd = pmd_offset(pud_offset(pgd_offset(mm, start), start), start);
	for (;;) {
		pmd_end = ((start + PGDIR_SIZE) & PGDIR_MASK) - 1;
		if (pmd_end > end)
			pmd_end = end;
		if (!pmd_none(*pmd)) {
			count = ((pmd_end - start) >> PAGE_SHIFT) + 1;
			flush_hash_pages(ctx, start, pmd_val(*pmd), count);
		}
		if (pmd_end == end)
			break;
		start = pmd_end + 1;
		++pmd;
	}
}

void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
	flush_range(&init_mm, start, end);
}

void flush_tlb_mm(struct mm_struct *mm)
{
	struct vm_area_struct *mp;

	if (!Hash) {
		_tlbia();
		return;
	}

	/*
	 * It is safe to go down the mm's list of vmas when called
	 * from dup_mmap, holding mmap_sem.  It would also be safe from
	 * unmap_region or exit_mmap, but not from vmtruncate on SMP -
	 * but it seems dup_mmap is the only SMP case which gets here.
	 */
	for (mp = mm->mmap; mp != NULL; mp = mp->vm_next)
		flush_range(mp->vm_mm, mp->vm_start, mp->vm_end);
}

void flush_tlb_page(struct vm_area_struct *vma, unsigned long vmaddr)
{
	struct mm_struct *mm;
	pmd_t *pmd;

	if (!Hash) {
		_tlbie(vmaddr);
		return;
	}
	mm = (vmaddr < TASK_SIZE)? vma->vm_mm: &init_mm;
	pmd = pmd_offset(pud_offset(pgd_offset(mm, vmaddr), vmaddr), vmaddr);
	if (!pmd_none(*pmd))
		flush_hash_pages(mm->context.id, vmaddr, pmd_val(*pmd), 1);
}

void flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
		     unsigned long end)
{
	flush_range(vma->vm_mm, start, end);
}


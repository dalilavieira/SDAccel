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
typedef  unsigned long u64 ;
struct vm_area_struct {struct mm_struct* vm_mm; int /*<<< orphan*/  vm_file; } ;
struct TYPE_3__ {unsigned long id; } ;
struct mm_struct {TYPE_1__ context; } ;
struct hstate {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;
struct TYPE_4__ {int enc; } ;

/* Variables and functions */
 unsigned long MAS1_TID (unsigned long) ; 
 unsigned long MAS1_TSIZE (unsigned long) ; 
 unsigned long MAS1_VALID ; 
 unsigned long MAS2_WIMGE_MASK ; 
 unsigned long MAS3_BAP_MASK ; 
 unsigned long MAS3_SW ; 
 unsigned long MAS3_UW ; 
 int /*<<< orphan*/  MMU_FTR_BIG_PHYS ; 
 int /*<<< orphan*/  MMU_FTR_USE_PAIRED_MAS ; 
 int /*<<< orphan*/  MMU_FTR_USE_TLBRSRV ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long PTE_BAP_SHIFT ; 
 unsigned long PTE_WIMGE_SHIFT ; 
 int /*<<< orphan*/  SPRN_MAS1 ; 
 int /*<<< orphan*/  SPRN_MAS2 ; 
 int /*<<< orphan*/  SPRN_MAS3 ; 
 int /*<<< orphan*/  SPRN_MAS6 ; 
 int /*<<< orphan*/  SPRN_MAS7 ; 
 int /*<<< orphan*/  SPRN_MAS7_MAS3 ; 
 int /*<<< orphan*/  __flush_tlb_page (struct mm_struct*,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 unsigned long __ilog2 (unsigned long) ; 
 struct hstate* hstate_file (int /*<<< orphan*/ ) ; 
 int huge_page_shift (struct hstate*) ; 
 int is_kernel_addr (unsigned long) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 unsigned long lower_32_bits (unsigned long) ; 
 scalar_t__ mmu_has_feature (int /*<<< orphan*/ ) ; 
 TYPE_2__* mmu_psize_defs ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  pte_dirty (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_pfn (int /*<<< orphan*/ ) ; 
 unsigned long pte_val (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 unsigned long upper_32_bits (unsigned long) ; 
 unsigned long vma_mmu_pagesize (struct vm_area_struct*) ; 

__attribute__((used)) static inline int mmu_get_tsize(int psize)
{
	return mmu_psize_defs[psize].enc;
}

__attribute__((used)) static inline void book3e_tlb_lock(void)
{
}

__attribute__((used)) static inline void book3e_tlb_unlock(void)
{
}

__attribute__((used)) static inline int book3e_tlb_exists(unsigned long ea, unsigned long pid)
{
	int found = 0;

	mtspr(SPRN_MAS6, pid << 16);
	if (mmu_has_feature(MMU_FTR_USE_TLBRSRV)) {
		asm volatile(
			"li	%0,0\n"
			"tlbsx.	0,%1\n"
			"bne	1f\n"
			"li	%0,1\n"
			"1:\n"
			: "=&r"(found) : "r"(ea));
	} else {
		asm volatile(
			"tlbsx	0,%1\n"
			"mfspr	%0,0x271\n"
			"srwi	%0,%0,31\n"
			: "=&r"(found) : "r"(ea));
	}

	return found;
}

void book3e_hugetlb_preload(struct vm_area_struct *vma, unsigned long ea,
			    pte_t pte)
{
	unsigned long mas1, mas2;
	u64 mas7_3;
	unsigned long psize, tsize, shift;
	unsigned long flags;
	struct mm_struct *mm;

#ifdef CONFIG_PPC_FSL_BOOK3E
	int index;
#endif

	if (unlikely(is_kernel_addr(ea)))
		return;

	mm = vma->vm_mm;

	psize = vma_mmu_pagesize(vma);
	shift = __ilog2(psize);
	tsize = shift - 10;
	/*
	 * We can't be interrupted while we're setting up the MAS
	 * regusters or after we've confirmed that no tlb exists.
	 */
	local_irq_save(flags);

	book3e_tlb_lock();

	if (unlikely(book3e_tlb_exists(ea, mm->context.id))) {
		book3e_tlb_unlock();
		local_irq_restore(flags);
		return;
	}

#ifdef CONFIG_PPC_FSL_BOOK3E
	/* We have to use the CAM(TLB1) on FSL parts for hugepages */
	index = tlb1_next();
	mtspr(SPRN_MAS0, MAS0_ESEL(index) | MAS0_TLBSEL(1));
#endif

	mas1 = MAS1_VALID | MAS1_TID(mm->context.id) | MAS1_TSIZE(tsize);
	mas2 = ea & ~((1UL << shift) - 1);
	mas2 |= (pte_val(pte) >> PTE_WIMGE_SHIFT) & MAS2_WIMGE_MASK;
	mas7_3 = (u64)pte_pfn(pte) << PAGE_SHIFT;
	mas7_3 |= (pte_val(pte) >> PTE_BAP_SHIFT) & MAS3_BAP_MASK;
	if (!pte_dirty(pte))
		mas7_3 &= ~(MAS3_SW|MAS3_UW);

	mtspr(SPRN_MAS1, mas1);
	mtspr(SPRN_MAS2, mas2);

	if (mmu_has_feature(MMU_FTR_USE_PAIRED_MAS)) {
		mtspr(SPRN_MAS7_MAS3, mas7_3);
	} else {
		if (mmu_has_feature(MMU_FTR_BIG_PHYS))
			mtspr(SPRN_MAS7, upper_32_bits(mas7_3));
		mtspr(SPRN_MAS3, lower_32_bits(mas7_3));
	}

	asm volatile ("tlbwe");

	book3e_tlb_unlock();
	local_irq_restore(flags);
}

void flush_hugetlb_page(struct vm_area_struct *vma, unsigned long vmaddr)
{
	struct hstate *hstate = hstate_file(vma->vm_file);
	unsigned long tsize = huge_page_shift(hstate) - 10;

	__flush_tlb_page(vma->vm_mm, vmaddr, tsize, 0);
}


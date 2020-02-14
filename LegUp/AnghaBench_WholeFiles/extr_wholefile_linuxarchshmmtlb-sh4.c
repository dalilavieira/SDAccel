#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {scalar_t__ vm_mm; } ;
struct TYPE_5__ {unsigned long pte_low; } ;
typedef  TYPE_1__ pte_t ;
struct TYPE_7__ {int flags; } ;
struct TYPE_6__ {scalar_t__ active_mm; } ;

/* Variables and functions */
 int CPU_HAS_PTEA ; 
 int /*<<< orphan*/  MMUCR ; 
 unsigned long MMUCR_URB ; 
 unsigned long MMUCR_URB_NENTRIES ; 
 unsigned long MMUCR_URB_SHIFT ; 
 int MMU_ITLB_ADDRESS_ARRAY ; 
 int MMU_PAGE_ASSOC_BIT ; 
 int MMU_PTEA ; 
 int MMU_PTEH ; 
 int MMU_PTEL ; 
 int MMU_UTLB_ADDRESS_ARRAY ; 
 unsigned long MMU_VPN_MASK ; 
 unsigned long _PAGE_FLAGS_HARDWARE_MASK ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int) ; 
 int /*<<< orphan*/  back_to_cached () ; 
 int copy_ptea_attributes (unsigned long) ; 
 TYPE_3__* cpu_data ; 
 int /*<<< orphan*/  ctrl_barrier () ; 
 TYPE_2__* current ; 
 unsigned long get_asid () ; 
 int /*<<< orphan*/  jump_to_uncached () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

void __update_tlb(struct vm_area_struct *vma, unsigned long address, pte_t pte)
{
	unsigned long flags, pteval, vpn;

	/*
	 * Handle debugger faulting in for debugee.
	 */
	if (vma && current->active_mm != vma->vm_mm)
		return;

	local_irq_save(flags);

	/* Set PTEH register */
	vpn = (address & MMU_VPN_MASK) | get_asid();
	__raw_writel(vpn, MMU_PTEH);

	pteval = pte.pte_low;

	/* Set PTEA register */
#ifdef CONFIG_X2TLB
	/*
	 * For the extended mode TLB this is trivial, only the ESZ and
	 * EPR bits need to be written out to PTEA, with the remainder of
	 * the protection bits (with the exception of the compat-mode SZ
	 * and PR bits, which are cleared) being written out in PTEL.
	 */
	__raw_writel(pte.pte_high, MMU_PTEA);
#else
	if (cpu_data->flags & CPU_HAS_PTEA) {
		/* The last 3 bits and the first one of pteval contains
		 * the PTEA timing control and space attribute bits
		 */
		__raw_writel(copy_ptea_attributes(pteval), MMU_PTEA);
	}
#endif

	/* Set PTEL register */
	pteval &= _PAGE_FLAGS_HARDWARE_MASK; /* drop software flags */
#ifdef CONFIG_CACHE_WRITETHROUGH
	pteval |= _PAGE_WT;
#endif
	/* conveniently, we want all the software flags to be 0 anyway */
	__raw_writel(pteval, MMU_PTEL);

	/* Load the TLB */
	asm volatile("ldtlb": /* no output */ : /* no input */ : "memory");
	local_irq_restore(flags);
}

void local_flush_tlb_one(unsigned long asid, unsigned long page)
{
	unsigned long addr, data;

	/*
	 * NOTE: PTEH.ASID should be set to this MM
	 *       _AND_ we need to write ASID to the array.
	 *
	 * It would be simple if we didn't need to set PTEH.ASID...
	 */
	addr = MMU_UTLB_ADDRESS_ARRAY | MMU_PAGE_ASSOC_BIT;
	data = page | asid; /* VALID bit is off */
	jump_to_uncached();
	__raw_writel(data, addr);
	back_to_cached();
}

void local_flush_tlb_all(void)
{
	unsigned long flags, status;
	int i;

	/*
	 * Flush all the TLB.
	 */
	local_irq_save(flags);
	jump_to_uncached();

	status = __raw_readl(MMUCR);
	status = ((status & MMUCR_URB) >> MMUCR_URB_SHIFT);

	if (status == 0)
		status = MMUCR_URB_NENTRIES;

	for (i = 0; i < status; i++)
		__raw_writel(0x0, MMU_UTLB_ADDRESS_ARRAY | (i << 8));

	for (i = 0; i < 4; i++)
		__raw_writel(0x0, MMU_ITLB_ADDRESS_ARRAY | (i << 8));

	back_to_cached();
	ctrl_barrier();
	local_irq_restore(flags);
}


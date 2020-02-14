#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int tlbsize; } ;

/* Variables and functions */
 unsigned long KSEG0 ; 
 unsigned long PAGE_MASK ; 
 unsigned long R3K_ENTRYLO_D ; 
 unsigned long R3K_ENTRYLO_G ; 
 unsigned long R3K_ENTRYLO_N ; 
 unsigned long R3K_ENTRYLO_V ; 
 unsigned long cpu_asid_mask (TYPE_1__*) ; 
 TYPE_1__ current_cpu_data ; 
 int /*<<< orphan*/  pr_cont (char*,unsigned long,unsigned long,unsigned long,int,int,int,int) ; 
 int /*<<< orphan*/  pr_info (char*,unsigned long) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 scalar_t__ r3k_have_wired_reg ; 
 unsigned long read_c0_entryhi () ; 
 unsigned long read_c0_entrylo0 () ; 
 unsigned long read_c0_index () ; 
 unsigned long read_c0_wired () ; 
 int /*<<< orphan*/  write_c0_entryhi (unsigned int) ; 
 int /*<<< orphan*/  write_c0_index (int) ; 

void dump_tlb_regs(void)
{
	pr_info("Index    : %0x\n", read_c0_index());
	pr_info("EntryHi  : %0lx\n", read_c0_entryhi());
	pr_info("EntryLo  : %0lx\n", read_c0_entrylo0());
	if (r3k_have_wired_reg)
		pr_info("Wired    : %0x\n", read_c0_wired());
}

__attribute__((used)) static void dump_tlb(int first, int last)
{
	int	i;
	unsigned int asid;
	unsigned long entryhi, entrylo0, asid_mask;

	asid_mask = cpu_asid_mask(&current_cpu_data);
	asid = read_c0_entryhi() & asid_mask;

	for (i = first; i <= last; i++) {
		write_c0_index(i<<8);
		__asm__ __volatile__(
			".set\tnoreorder\n\t"
			"tlbr\n\t"
			"nop\n\t"
			".set\treorder");
		entryhi	 = read_c0_entryhi();
		entrylo0 = read_c0_entrylo0();

		/* Unused entries have a virtual address of KSEG0.  */
		if ((entryhi & PAGE_MASK) != KSEG0 &&
		    (entrylo0 & R3K_ENTRYLO_G ||
		     (entryhi & asid_mask) == asid)) {
			/*
			 * Only print entries in use
			 */
			printk("Index: %2d ", i);

			pr_cont("va=%08lx asid=%08lx"
				"  [pa=%06lx n=%d d=%d v=%d g=%d]",
				entryhi & PAGE_MASK,
				entryhi & asid_mask,
				entrylo0 & PAGE_MASK,
				(entrylo0 & R3K_ENTRYLO_N) ? 1 : 0,
				(entrylo0 & R3K_ENTRYLO_D) ? 1 : 0,
				(entrylo0 & R3K_ENTRYLO_V) ? 1 : 0,
				(entrylo0 & R3K_ENTRYLO_G) ? 1 : 0);
		}
	}
	printk("\n");

	write_c0_entryhi(asid);
}

void dump_tlb_all(void)
{
	dump_tlb(0, current_cpu_data.tlbsize - 1);
}


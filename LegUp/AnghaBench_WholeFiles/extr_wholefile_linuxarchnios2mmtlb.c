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
struct vm_area_struct {TYPE_1__* vm_mm; } ;
struct mm_struct {int /*<<< orphan*/  context; } ;
typedef  int /*<<< orphan*/  mm_context_t ;
struct TYPE_6__ {unsigned int tlb_num_ways; unsigned int tlb_num_lines; unsigned long tlb_num_ways_log2; } ;
struct TYPE_5__ {struct mm_struct* mm; } ;
struct TYPE_4__ {int /*<<< orphan*/  context; } ;

/* Variables and functions */
 unsigned int CONFIG_NIOS2_IO_REGION_BASE ; 
 int /*<<< orphan*/  CTL_PTEADDR ; 
 int /*<<< orphan*/  CTL_TLBACC ; 
 int /*<<< orphan*/  CTL_TLBMISC ; 
 unsigned long MAX_PHYS_ADDR ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_SHIFT ; 
 unsigned int PAGE_SIZE ; 
 unsigned long RDCTL (int /*<<< orphan*/ ) ; 
 unsigned long TLBMISC_PID ; 
 unsigned long TLBMISC_PID_MASK ; 
 unsigned long TLBMISC_PID_SHIFT ; 
 unsigned long TLBMISC_RD ; 
 unsigned long TLBMISC_WAY ; 
 unsigned int TLBMISC_WAY_SHIFT ; 
 unsigned long TLBMISC_WE ; 
 unsigned long TLB_INDEX_MASK ; 
 int /*<<< orphan*/  WRCTL (int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long _PAGE_CACHED ; 
 unsigned long _PAGE_EXEC ; 
 unsigned long _PAGE_GLOBAL ; 
 unsigned long _PAGE_READ ; 
 unsigned long _PAGE_WRITE ; 
 TYPE_3__ cpuinfo ; 
 TYPE_2__* current ; 
 void flush_tlb_all () ; 
 void flush_tlb_one (unsigned long) ; 
 unsigned long get_pid_from_context (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned int,...) ; 

__attribute__((used)) static void get_misc_and_pid(unsigned long *misc, unsigned long *pid)
{
	*misc  = RDCTL(CTL_TLBMISC);
	*misc &= (TLBMISC_PID | TLBMISC_WAY);
	*pid  = *misc & TLBMISC_PID;
}

void flush_tlb_mm(struct mm_struct *mm)
{
	if (current->mm == mm)
		flush_tlb_all();
	else
		memset(&mm->context, 0, sizeof(mm_context_t));
}

void flush_tlb_one_pid(unsigned long addr, unsigned long mmu_pid)
{
	unsigned int way;
	unsigned long org_misc, pid_misc;

	pr_debug("Flush tlb-entry for vaddr=%#lx\n", addr);

	/* remember pid/way until we return. */
	get_misc_and_pid(&org_misc, &pid_misc);

	WRCTL(CTL_PTEADDR, (addr >> PAGE_SHIFT) << 2);

	for (way = 0; way < cpuinfo.tlb_num_ways; way++) {
		unsigned long pteaddr;
		unsigned long tlbmisc;
		unsigned long pid;

		tlbmisc = pid_misc | TLBMISC_RD | (way << TLBMISC_WAY_SHIFT);
		WRCTL(CTL_TLBMISC, tlbmisc);
		pteaddr = RDCTL(CTL_PTEADDR);
		tlbmisc = RDCTL(CTL_TLBMISC);
		pid = (tlbmisc >> TLBMISC_PID_SHIFT) & TLBMISC_PID_MASK;
		if (((((pteaddr >> 2) & 0xfffff)) == (addr >> PAGE_SHIFT)) &&
				pid == mmu_pid) {
			unsigned long vaddr = CONFIG_NIOS2_IO_REGION_BASE +
				((PAGE_SIZE * cpuinfo.tlb_num_lines) * way) +
				(addr & TLB_INDEX_MASK);
			pr_debug("Flush entry by writing %#lx way=%dl pid=%ld\n",
				vaddr, way, (pid_misc >> TLBMISC_PID_SHIFT));

			WRCTL(CTL_PTEADDR, (vaddr >> 12) << 2);
			tlbmisc = pid_misc | TLBMISC_WE |
				(way << TLBMISC_WAY_SHIFT);
			WRCTL(CTL_TLBMISC, tlbmisc);
			WRCTL(CTL_TLBACC, (MAX_PHYS_ADDR >> PAGE_SHIFT));
		}
	}

	WRCTL(CTL_TLBMISC, org_misc);
}

void flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
			unsigned long end)
{
	unsigned long mmu_pid = get_pid_from_context(&vma->vm_mm->context);

	while (start < end) {
		flush_tlb_one_pid(start, mmu_pid);
		start += PAGE_SIZE;
	}
}

void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
	while (start < end) {
		flush_tlb_one(start);
		start += PAGE_SIZE;
	}
}

void flush_tlb_one(unsigned long addr)
{
	unsigned int way;
	unsigned long org_misc, pid_misc;

	pr_debug("Flush tlb-entry for vaddr=%#lx\n", addr);

	/* remember pid/way until we return. */
	get_misc_and_pid(&org_misc, &pid_misc);

	WRCTL(CTL_PTEADDR, (addr >> PAGE_SHIFT) << 2);

	for (way = 0; way < cpuinfo.tlb_num_ways; way++) {
		unsigned long pteaddr;
		unsigned long tlbmisc;

		tlbmisc = pid_misc | TLBMISC_RD | (way << TLBMISC_WAY_SHIFT);
		WRCTL(CTL_TLBMISC, tlbmisc);
		pteaddr = RDCTL(CTL_PTEADDR);
		tlbmisc = RDCTL(CTL_TLBMISC);

		if ((((pteaddr >> 2) & 0xfffff)) == (addr >> PAGE_SHIFT)) {
			unsigned long vaddr = CONFIG_NIOS2_IO_REGION_BASE +
				((PAGE_SIZE * cpuinfo.tlb_num_lines) * way) +
				(addr & TLB_INDEX_MASK);

			pr_debug("Flush entry by writing %#lx way=%dl pid=%ld\n",
				vaddr, way, (pid_misc >> TLBMISC_PID_SHIFT));

			tlbmisc = pid_misc | TLBMISC_WE |
				(way << TLBMISC_WAY_SHIFT);
			WRCTL(CTL_PTEADDR, (vaddr >> 12) << 2);
			WRCTL(CTL_TLBMISC, tlbmisc);
			WRCTL(CTL_TLBACC, (MAX_PHYS_ADDR >> PAGE_SHIFT));
		}
	}

	WRCTL(CTL_TLBMISC, org_misc);
}

void dump_tlb_line(unsigned long line)
{
	unsigned int way;
	unsigned long org_misc;

	pr_debug("dump tlb-entries for line=%#lx (addr %08lx)\n", line,
		line << (PAGE_SHIFT + cpuinfo.tlb_num_ways_log2));

	/* remember pid/way until we return */
	org_misc = (RDCTL(CTL_TLBMISC) & (TLBMISC_PID | TLBMISC_WAY));

	WRCTL(CTL_PTEADDR, line << 2);

	for (way = 0; way < cpuinfo.tlb_num_ways; way++) {
		unsigned long pteaddr;
		unsigned long tlbmisc;
		unsigned long tlbacc;

		WRCTL(CTL_TLBMISC, TLBMISC_RD | (way << TLBMISC_WAY_SHIFT));
		pteaddr = RDCTL(CTL_PTEADDR);
		tlbmisc = RDCTL(CTL_TLBMISC);
		tlbacc = RDCTL(CTL_TLBACC);

		if ((tlbacc << PAGE_SHIFT) != (MAX_PHYS_ADDR & PAGE_MASK)) {
			pr_debug("-- way:%02x vpn:0x%08lx phys:0x%08lx pid:0x%02lx flags:%c%c%c%c%c\n",
				way,
				(pteaddr << (PAGE_SHIFT-2)),
				(tlbacc << PAGE_SHIFT),
				((tlbmisc >> TLBMISC_PID_SHIFT) &
				TLBMISC_PID_MASK),
				(tlbacc & _PAGE_READ ? 'r' : '-'),
				(tlbacc & _PAGE_WRITE ? 'w' : '-'),
				(tlbacc & _PAGE_EXEC ? 'x' : '-'),
				(tlbacc & _PAGE_GLOBAL ? 'g' : '-'),
				(tlbacc & _PAGE_CACHED ? 'c' : '-'));
		}
	}

	WRCTL(CTL_TLBMISC, org_misc);
}

void dump_tlb(void)
{
	unsigned int i;

	for (i = 0; i < cpuinfo.tlb_num_lines; i++)
		dump_tlb_line(i);
}

void flush_tlb_pid(unsigned long pid)
{
	unsigned int line;
	unsigned int way;
	unsigned long org_misc, pid_misc;

	/* remember pid/way until we return */
	get_misc_and_pid(&org_misc, &pid_misc);

	for (line = 0; line < cpuinfo.tlb_num_lines; line++) {
		WRCTL(CTL_PTEADDR, line << 2);

		for (way = 0; way < cpuinfo.tlb_num_ways; way++) {
			unsigned long pteaddr;
			unsigned long tlbmisc;
			unsigned long tlbacc;

			tlbmisc = pid_misc | TLBMISC_RD |
				(way << TLBMISC_WAY_SHIFT);
			WRCTL(CTL_TLBMISC, tlbmisc);
			pteaddr = RDCTL(CTL_PTEADDR);
			tlbmisc = RDCTL(CTL_TLBMISC);
			tlbacc = RDCTL(CTL_TLBACC);

			if (((tlbmisc>>TLBMISC_PID_SHIFT) & TLBMISC_PID_MASK)
				== pid) {
				tlbmisc = pid_misc | TLBMISC_WE |
					(way << TLBMISC_WAY_SHIFT);
				WRCTL(CTL_TLBMISC, tlbmisc);
				WRCTL(CTL_TLBACC,
					(MAX_PHYS_ADDR >> PAGE_SHIFT));
			}
		}

		WRCTL(CTL_TLBMISC, org_misc);
	}
}

void flush_tlb_all(void)
{
	int i;
	unsigned long vaddr = CONFIG_NIOS2_IO_REGION_BASE;
	unsigned int way;
	unsigned long org_misc, pid_misc, tlbmisc;

	/* remember pid/way until we return */
	get_misc_and_pid(&org_misc, &pid_misc);
	pid_misc |= TLBMISC_WE;

	/* Map each TLB entry to physcal address 0 with no-access and a
	   bad ptbase */
	for (way = 0; way < cpuinfo.tlb_num_ways; way++) {
		tlbmisc = pid_misc | (way << TLBMISC_WAY_SHIFT);
		for (i = 0; i < cpuinfo.tlb_num_lines; i++) {
			WRCTL(CTL_PTEADDR, ((vaddr) >> PAGE_SHIFT) << 2);
			WRCTL(CTL_TLBMISC, tlbmisc);
			WRCTL(CTL_TLBACC, (MAX_PHYS_ADDR >> PAGE_SHIFT));
			vaddr += 1UL << 12;
		}
	}

	/* restore pid/way */
	WRCTL(CTL_TLBMISC, org_misc);
}

void set_mmu_pid(unsigned long pid)
{
	WRCTL(CTL_TLBMISC, (RDCTL(CTL_TLBMISC) & TLBMISC_WAY) |
		((pid & TLBMISC_PID_MASK) << TLBMISC_PID_SHIFT));
}


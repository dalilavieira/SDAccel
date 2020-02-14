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
struct seq_file {int dummy; } ;
struct pg_state {unsigned int current_prot; int level; scalar_t__ current_address; int start_address; TYPE_1__* marker; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  st ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
typedef  int /*<<< orphan*/  p4d_t ;
struct TYPE_4__ {int kernel_asce; } ;
struct TYPE_3__ {char const* const name; scalar_t__ start_address; } ;

/* Variables and functions */
 size_t MODULES_NR ; 
 unsigned long MODULES_VADDR ; 
 scalar_t__ P4D_SIZE ; 
 scalar_t__ PAGE_SIZE ; 
 scalar_t__ PGDIR_SIZE ; 
 scalar_t__ PMD_SIZE ; 
 int PTRS_PER_P4D ; 
 int PTRS_PER_PGD ; 
 int PTRS_PER_PMD ; 
 int PTRS_PER_PTE ; 
 int PTRS_PER_PUD ; 
 scalar_t__ PUD_SIZE ; 
 TYPE_2__ S390_lowcore ; 
 size_t VMALLOC_NR ; 
 unsigned long VMALLOC_START ; 
 size_t VMEMMAP_NR ; 
 unsigned int _PAGE_INVALID ; 
 unsigned int _PAGE_NOEXEC ; 
 unsigned int _PAGE_PROTECT ; 
 unsigned int _REGION_ENTRY_NOEXEC ; 
 unsigned int _REGION_ENTRY_PROTECT ; 
 int _REGION_ENTRY_TYPE_MASK ; 
 unsigned int _SEGMENT_ENTRY_NOEXEC ; 
 unsigned int _SEGMENT_ENTRY_PROTECT ; 
 TYPE_1__* address_markers ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  debugfs_create_file (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned long max_addr ; 
 int /*<<< orphan*/  memset (struct pg_state*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  p4d_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * p4d_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  pgd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pgd_offset_k (unsigned long) ; 
 scalar_t__ pmd_large (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmd_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int pmd_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ptdump_fops ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int pte_val (int /*<<< orphan*/ ) ; 
 scalar_t__ pud_large (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pud_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned int pud_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 
 scalar_t__ vmemmap ; 

__attribute__((used)) static void print_prot(struct seq_file *m, unsigned int pr, int level)
{
	static const char * const level_name[] =
		{ "ASCE", "PGD", "PUD", "PMD", "PTE" };

	seq_printf(m, "%s ", level_name[level]);
	if (pr & _PAGE_INVALID) {
		seq_printf(m, "I\n");
		return;
	}
	seq_puts(m, (pr & _PAGE_PROTECT) ? "RO " : "RW ");
	seq_puts(m, (pr & _PAGE_NOEXEC) ? "NX\n" : "X\n");
}

__attribute__((used)) static void note_page(struct seq_file *m, struct pg_state *st,
		     unsigned int new_prot, int level)
{
	static const char units[] = "KMGTPE";
	int width = sizeof(unsigned long) * 2;
	const char *unit = units;
	unsigned int prot, cur;
	unsigned long delta;

	/*
	 * If we have a "break" in the series, we need to flush the state
	 * that we have now. "break" is either changing perms, levels or
	 * address space marker.
	 */
	prot = new_prot;
	cur = st->current_prot;

	if (!st->level) {
		/* First entry */
		st->current_prot = new_prot;
		st->level = level;
		st->marker = address_markers;
		seq_printf(m, "---[ %s ]---\n", st->marker->name);
	} else if (prot != cur || level != st->level ||
		   st->current_address >= st->marker[1].start_address) {
		/* Print the actual finished series */
		seq_printf(m, "0x%0*lx-0x%0*lx",
			   width, st->start_address,
			   width, st->current_address);
		delta = (st->current_address - st->start_address) >> 10;
		while (!(delta & 0x3ff) && unit[1]) {
			delta >>= 10;
			unit++;
		}
		seq_printf(m, "%9lu%c ", delta, *unit);
		print_prot(m, st->current_prot, st->level);
		if (st->current_address >= st->marker[1].start_address) {
			st->marker++;
			seq_printf(m, "---[ %s ]---\n", st->marker->name);
		}
		st->start_address = st->current_address;
		st->current_prot = new_prot;
		st->level = level;
	}
}

__attribute__((used)) static void walk_pte_level(struct seq_file *m, struct pg_state *st,
			   pmd_t *pmd, unsigned long addr)
{
	unsigned int prot;
	pte_t *pte;
	int i;

	for (i = 0; i < PTRS_PER_PTE && addr < max_addr; i++) {
		st->current_address = addr;
		pte = pte_offset_kernel(pmd, addr);
		prot = pte_val(*pte) &
			(_PAGE_PROTECT | _PAGE_INVALID | _PAGE_NOEXEC);
		note_page(m, st, prot, 4);
		addr += PAGE_SIZE;
	}
}

__attribute__((used)) static void walk_pmd_level(struct seq_file *m, struct pg_state *st,
			   pud_t *pud, unsigned long addr)
{
	unsigned int prot;
	pmd_t *pmd;
	int i;

	for (i = 0; i < PTRS_PER_PMD && addr < max_addr; i++) {
		st->current_address = addr;
		pmd = pmd_offset(pud, addr);
		if (!pmd_none(*pmd)) {
			if (pmd_large(*pmd)) {
				prot = pmd_val(*pmd) &
					(_SEGMENT_ENTRY_PROTECT |
					 _SEGMENT_ENTRY_NOEXEC);
				note_page(m, st, prot, 3);
			} else
				walk_pte_level(m, st, pmd, addr);
		} else
			note_page(m, st, _PAGE_INVALID, 3);
		addr += PMD_SIZE;
	}
}

__attribute__((used)) static void walk_pud_level(struct seq_file *m, struct pg_state *st,
			   p4d_t *p4d, unsigned long addr)
{
	unsigned int prot;
	pud_t *pud;
	int i;

	for (i = 0; i < PTRS_PER_PUD && addr < max_addr; i++) {
		st->current_address = addr;
		pud = pud_offset(p4d, addr);
		if (!pud_none(*pud))
			if (pud_large(*pud)) {
				prot = pud_val(*pud) &
					(_REGION_ENTRY_PROTECT |
					 _REGION_ENTRY_NOEXEC);
				note_page(m, st, prot, 2);
			} else
				walk_pmd_level(m, st, pud, addr);
		else
			note_page(m, st, _PAGE_INVALID, 2);
		addr += PUD_SIZE;
	}
}

__attribute__((used)) static void walk_p4d_level(struct seq_file *m, struct pg_state *st,
			   pgd_t *pgd, unsigned long addr)
{
	p4d_t *p4d;
	int i;

	for (i = 0; i < PTRS_PER_P4D && addr < max_addr; i++) {
		st->current_address = addr;
		p4d = p4d_offset(pgd, addr);
		if (!p4d_none(*p4d))
			walk_pud_level(m, st, p4d, addr);
		else
			note_page(m, st, _PAGE_INVALID, 2);
		addr += P4D_SIZE;
	}
}

__attribute__((used)) static void walk_pgd_level(struct seq_file *m)
{
	unsigned long addr = 0;
	struct pg_state st;
	pgd_t *pgd;
	int i;

	memset(&st, 0, sizeof(st));
	for (i = 0; i < PTRS_PER_PGD && addr < max_addr; i++) {
		st.current_address = addr;
		pgd = pgd_offset_k(addr);
		if (!pgd_none(*pgd))
			walk_p4d_level(m, &st, pgd, addr);
		else
			note_page(m, &st, _PAGE_INVALID, 1);
		addr += PGDIR_SIZE;
		cond_resched();
	}
	/* Flush out the last page */
	st.current_address = max_addr;
	note_page(m, &st, 0, 0);
}

__attribute__((used)) static int ptdump_show(struct seq_file *m, void *v)
{
	walk_pgd_level(m);
	return 0;
}

__attribute__((used)) static int ptdump_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, ptdump_show, NULL);
}

__attribute__((used)) static int pt_dump_init(void)
{
	/*
	 * Figure out the maximum virtual address being accessible with the
	 * kernel ASCE. We need this to keep the page table walker functions
	 * from accessing non-existent entries.
	 */
	max_addr = (S390_lowcore.kernel_asce & _REGION_ENTRY_TYPE_MASK) >> 2;
	max_addr = 1UL << (max_addr * 11 + 31);
	address_markers[MODULES_NR].start_address = MODULES_VADDR;
	address_markers[VMEMMAP_NR].start_address = (unsigned long) vmemmap;
	address_markers[VMALLOC_NR].start_address = VMALLOC_START;
	debugfs_create_file("kernel_page_tables", 0400, NULL, NULL, &ptdump_fops);
	return 0;
}


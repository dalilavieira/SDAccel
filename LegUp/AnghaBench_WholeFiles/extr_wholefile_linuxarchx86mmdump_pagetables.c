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
struct seq_file {int dummy; } ;
struct pg_state {void* current_prot; int effective_prot; int level; scalar_t__ lines; int to_dmesg; scalar_t__ current_address; int check_wx; int start_address; int wx_pages; TYPE_1__* marker; } ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int pgprotval_t ;
typedef  void* pgprot_t ;
typedef  int /*<<< orphan*/  pgd_t ;
typedef  int /*<<< orphan*/  p4d_t ;
struct TYPE_2__ {scalar_t__ start_address; scalar_t__ max_lines; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_X86_64 ; 
 int /*<<< orphan*/ * INIT_PGD ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 int P4D_LEVEL_MULT ; 
 int PAGE_SIZE ; 
 int PGD_LEVEL_MULT ; 
 int PTE_LEVEL_MULT ; 
 int PTRS_PER_P4D ; 
 int PTRS_PER_PGD ; 
 int PTRS_PER_PTE ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*,void*,void*) ; 
 int _PAGE_GLOBAL ; 
 int _PAGE_NX ; 
 int _PAGE_PAT ; 
 int _PAGE_PAT_LARGE ; 
 int _PAGE_PCD ; 
 int _PAGE_PRESENT ; 
 int _PAGE_PSE ; 
 int _PAGE_PWT ; 
 int _PAGE_RW ; 
 int _PAGE_USER ; 
 int __VIRTUAL_MASK_SHIFT ; 
 int /*<<< orphan*/  __p4d (int /*<<< orphan*/ ) ; 
 void* __pgprot (int) ; 
 TYPE_1__* address_markers ; 
 int /*<<< orphan*/  cond_resched () ; 
 int p4d_flags (int /*<<< orphan*/ ) ; 
 scalar_t__ p4d_large (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p4d_none (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p4d_present (int /*<<< orphan*/ ) ; 
 int pgd_flags (int /*<<< orphan*/ ) ; 
 scalar_t__ pgd_large (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgd_none (int /*<<< orphan*/ ) ; 
 scalar_t__ pgd_page_vaddr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgd_present (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgd_val (int /*<<< orphan*/ ) ; 
 int pgprot_val (void*) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pt_dump_cont_printf (struct seq_file*,int,char*,...) ; 
 int /*<<< orphan*/  pt_dump_seq_printf (struct seq_file*,int,char*,int,...) ; 
 int pte_flags (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pte_offset_map (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  pte_unmap (int /*<<< orphan*/ *) ; 
 void walk_pud_level (struct seq_file*,struct pg_state*,int /*<<< orphan*/ ,int,unsigned long) ; 

__attribute__((used)) static void printk_prot(struct seq_file *m, pgprot_t prot, int level, bool dmsg)
{
	pgprotval_t pr = pgprot_val(prot);
	static const char * const level_name[] =
		{ "cr3", "pgd", "p4d", "pud", "pmd", "pte" };

	if (!(pr & _PAGE_PRESENT)) {
		/* Not present */
		pt_dump_cont_printf(m, dmsg, "                              ");
	} else {
		if (pr & _PAGE_USER)
			pt_dump_cont_printf(m, dmsg, "USR ");
		else
			pt_dump_cont_printf(m, dmsg, "    ");
		if (pr & _PAGE_RW)
			pt_dump_cont_printf(m, dmsg, "RW ");
		else
			pt_dump_cont_printf(m, dmsg, "ro ");
		if (pr & _PAGE_PWT)
			pt_dump_cont_printf(m, dmsg, "PWT ");
		else
			pt_dump_cont_printf(m, dmsg, "    ");
		if (pr & _PAGE_PCD)
			pt_dump_cont_printf(m, dmsg, "PCD ");
		else
			pt_dump_cont_printf(m, dmsg, "    ");

		/* Bit 7 has a different meaning on level 3 vs 4 */
		if (level <= 4 && pr & _PAGE_PSE)
			pt_dump_cont_printf(m, dmsg, "PSE ");
		else
			pt_dump_cont_printf(m, dmsg, "    ");
		if ((level == 5 && pr & _PAGE_PAT) ||
		    ((level == 4 || level == 3) && pr & _PAGE_PAT_LARGE))
			pt_dump_cont_printf(m, dmsg, "PAT ");
		else
			pt_dump_cont_printf(m, dmsg, "    ");
		if (pr & _PAGE_GLOBAL)
			pt_dump_cont_printf(m, dmsg, "GLB ");
		else
			pt_dump_cont_printf(m, dmsg, "    ");
		if (pr & _PAGE_NX)
			pt_dump_cont_printf(m, dmsg, "NX ");
		else
			pt_dump_cont_printf(m, dmsg, "x  ");
	}
	pt_dump_cont_printf(m, dmsg, "%s\n", level_name[level]);
}

__attribute__((used)) static unsigned long normalize_addr(unsigned long u)
{
	int shift;
	if (!IS_ENABLED(CONFIG_X86_64))
		return u;

	shift = 64 - (__VIRTUAL_MASK_SHIFT + 1);
	return (signed long)(u << shift) >> shift;
}

__attribute__((used)) static void note_page(struct seq_file *m, struct pg_state *st,
		      pgprot_t new_prot, pgprotval_t new_eff, int level)
{
	pgprotval_t prot, cur, eff;
	static const char units[] = "BKMGTPE";

	/*
	 * If we have a "break" in the series, we need to flush the state that
	 * we have now. "break" is either changing perms, levels or
	 * address space marker.
	 */
	prot = pgprot_val(new_prot);
	cur = pgprot_val(st->current_prot);
	eff = st->effective_prot;

	if (!st->level) {
		/* First entry */
		st->current_prot = new_prot;
		st->effective_prot = new_eff;
		st->level = level;
		st->marker = address_markers;
		st->lines = 0;
		pt_dump_seq_printf(m, st->to_dmesg, "---[ %s ]---\n",
				   st->marker->name);
	} else if (prot != cur || new_eff != eff || level != st->level ||
		   st->current_address >= st->marker[1].start_address) {
		const char *unit = units;
		unsigned long delta;
		int width = sizeof(unsigned long) * 2;

		if (st->check_wx && (eff & _PAGE_RW) && !(eff & _PAGE_NX)) {
			WARN_ONCE(1,
				  "x86/mm: Found insecure W+X mapping at address %p/%pS\n",
				  (void *)st->start_address,
				  (void *)st->start_address);
			st->wx_pages += (st->current_address -
					 st->start_address) / PAGE_SIZE;
		}

		/*
		 * Now print the actual finished series
		 */
		if (!st->marker->max_lines ||
		    st->lines < st->marker->max_lines) {
			pt_dump_seq_printf(m, st->to_dmesg,
					   "0x%0*lx-0x%0*lx   ",
					   width, st->start_address,
					   width, st->current_address);

			delta = st->current_address - st->start_address;
			while (!(delta & 1023) && unit[1]) {
				delta >>= 10;
				unit++;
			}
			pt_dump_cont_printf(m, st->to_dmesg, "%9lu%c ",
					    delta, *unit);
			printk_prot(m, st->current_prot, st->level,
				    st->to_dmesg);
		}
		st->lines++;

		/*
		 * We print markers for special areas of address space,
		 * such as the start of vmalloc space etc.
		 * This helps in the interpretation.
		 */
		if (st->current_address >= st->marker[1].start_address) {
			if (st->marker->max_lines &&
			    st->lines > st->marker->max_lines) {
				unsigned long nskip =
					st->lines - st->marker->max_lines;
				pt_dump_seq_printf(m, st->to_dmesg,
						   "... %lu entr%s skipped ... \n",
						   nskip,
						   nskip == 1 ? "y" : "ies");
			}
			st->marker++;
			st->lines = 0;
			pt_dump_seq_printf(m, st->to_dmesg, "---[ %s ]---\n",
					   st->marker->name);
		}

		st->start_address = st->current_address;
		st->current_prot = new_prot;
		st->effective_prot = new_eff;
		st->level = level;
	}
}

__attribute__((used)) static inline pgprotval_t effective_prot(pgprotval_t prot1, pgprotval_t prot2)
{
	return (prot1 & prot2 & (_PAGE_USER | _PAGE_RW)) |
	       ((prot1 | prot2) & _PAGE_NX);
}

__attribute__((used)) static void walk_pte_level(struct seq_file *m, struct pg_state *st, pmd_t addr,
			   pgprotval_t eff_in, unsigned long P)
{
	int i;
	pte_t *pte;
	pgprotval_t prot, eff;

	for (i = 0; i < PTRS_PER_PTE; i++) {
		st->current_address = normalize_addr(P + i * PTE_LEVEL_MULT);
		pte = pte_offset_map(&addr, st->current_address);
		prot = pte_flags(*pte);
		eff = effective_prot(eff_in, prot);
		note_page(m, st, __pgprot(prot), eff, 5);
		pte_unmap(pte);
	}
}

__attribute__((used)) static inline bool kasan_page_table(struct seq_file *m, struct pg_state *st,
				void *pt)
{
	return false;
}

__attribute__((used)) static void walk_p4d_level(struct seq_file *m, struct pg_state *st, pgd_t addr,
			   pgprotval_t eff_in, unsigned long P)
{
	int i;
	p4d_t *start, *p4d_start;
	pgprotval_t prot, eff;

	if (PTRS_PER_P4D == 1)
		return walk_pud_level(m, st, __p4d(pgd_val(addr)), eff_in, P);

	p4d_start = start = (p4d_t *)pgd_page_vaddr(addr);

	for (i = 0; i < PTRS_PER_P4D; i++) {
		st->current_address = normalize_addr(P + i * P4D_LEVEL_MULT);
		if (!p4d_none(*start)) {
			prot = p4d_flags(*start);
			eff = effective_prot(eff_in, prot);
			if (p4d_large(*start) || !p4d_present(*start)) {
				note_page(m, st, __pgprot(prot), eff, 2);
			} else if (!kasan_page_table(m, st, p4d_start)) {
				walk_pud_level(m, st, *start, eff,
					       P + i * P4D_LEVEL_MULT);
			}
		} else
			note_page(m, st, __pgprot(0), 0, 2);

		start++;
	}
}

__attribute__((used)) static inline bool is_hypervisor_range(int idx)
{
#ifdef CONFIG_X86_64
	/*
	 * A hole in the beginning of kernel address space reserved
	 * for a hypervisor.
	 */
	return	(idx >= pgd_index(GUARD_HOLE_BASE_ADDR)) &&
		(idx <  pgd_index(GUARD_HOLE_END_ADDR));
#else
	return false;
#endif
}

__attribute__((used)) static void ptdump_walk_pgd_level_core(struct seq_file *m, pgd_t *pgd,
				       bool checkwx, bool dmesg)
{
	pgd_t *start = INIT_PGD;
	pgprotval_t prot, eff;
	int i;
	struct pg_state st = {};

	if (pgd) {
		start = pgd;
		st.to_dmesg = dmesg;
	}

	st.check_wx = checkwx;
	if (checkwx)
		st.wx_pages = 0;

	for (i = 0; i < PTRS_PER_PGD; i++) {
		st.current_address = normalize_addr(i * PGD_LEVEL_MULT);
		if (!pgd_none(*start) && !is_hypervisor_range(i)) {
			prot = pgd_flags(*start);
#ifdef CONFIG_X86_PAE
			eff = _PAGE_USER | _PAGE_RW;
#else
			eff = prot;
#endif
			if (pgd_large(*start) || !pgd_present(*start)) {
				note_page(m, &st, __pgprot(prot), eff, 1);
			} else {
				walk_p4d_level(m, &st, *start, eff,
					       i * PGD_LEVEL_MULT);
			}
		} else
			note_page(m, &st, __pgprot(0), 0, 1);

		cond_resched();
		start++;
	}

	/* Flush out the last page */
	st.current_address = normalize_addr(PTRS_PER_PGD*PGD_LEVEL_MULT);
	note_page(m, &st, __pgprot(0), 0, 0);
	if (!checkwx)
		return;
	if (st.wx_pages)
		pr_info("x86/mm: Checked W+X mappings: FAILED, %lu W+X pages found.\n",
			st.wx_pages);
	else
		pr_info("x86/mm: Checked W+X mappings: passed, no W+X pages found.\n");
}

void ptdump_walk_pgd_level(struct seq_file *m, pgd_t *pgd)
{
	ptdump_walk_pgd_level_core(m, pgd, false, true);
}

void ptdump_walk_pgd_level_debugfs(struct seq_file *m, pgd_t *pgd, bool user)
{
#ifdef CONFIG_PAGE_TABLE_ISOLATION
	if (user && static_cpu_has(X86_FEATURE_PTI))
		pgd = kernel_to_user_pgdp(pgd);
#endif
	ptdump_walk_pgd_level_core(m, pgd, false, false);
}

void ptdump_walk_user_pgd_level_checkwx(void)
{
#ifdef CONFIG_PAGE_TABLE_ISOLATION
	pgd_t *pgd = INIT_PGD;

	if (!(__supported_pte_mask & _PAGE_NX) ||
	    !static_cpu_has(X86_FEATURE_PTI))
		return;

	pr_info("x86/mm: Checking user space page tables\n");
	pgd = kernel_to_user_pgdp(pgd);
	ptdump_walk_pgd_level_core(NULL, pgd, true, false);
#endif
}

void ptdump_walk_pgd_level_checkwx(void)
{
	ptdump_walk_pgd_level_core(NULL, NULL, true, false);
}


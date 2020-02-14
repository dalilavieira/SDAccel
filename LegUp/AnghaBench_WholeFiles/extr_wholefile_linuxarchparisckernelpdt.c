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
struct pdc_pat_mem_retinfo {int /*<<< orphan*/  good_mem; int /*<<< orphan*/  first_dbe_loc; int /*<<< orphan*/  current_pdt_entries; int /*<<< orphan*/  max_pdt_entries; } ;
struct pdc_pat_mem_phys_mem_location {int dimm_slot; } ;
struct pdc_pat_mem_cell_pdt_retinfo {int /*<<< orphan*/  good_mem; int /*<<< orphan*/  first_dbe_loc; int /*<<< orphan*/  current_pdt_entries; int /*<<< orphan*/  max_pdt_entries; } ;
struct TYPE_2__ {int /*<<< orphan*/  good_mem; int /*<<< orphan*/  first_dbe_loc; scalar_t__ pdt_status; int /*<<< orphan*/  pdt_entries; int /*<<< orphan*/  pdt_size; } ;

/* Variables and functions */
 int PDC_BAD_PROC ; 
 unsigned long PDT_ADDR_PERM_ERR ; 
 unsigned long PDT_ADDR_PHYS_MASK ; 
 unsigned long PDT_ADDR_SINGLE_ERR ; 
 scalar_t__ PDT_NONE ; 
 scalar_t__ is_pdc_pat () ; 
 int /*<<< orphan*/  parisc_cell_num ; 
 int /*<<< orphan*/  pdc_pat_mem_get_dimm_phys_location (struct pdc_pat_mem_phys_mem_location*,unsigned long) ; 
 int pdc_pat_mem_pdt_cell_info (struct pdc_pat_mem_cell_pdt_retinfo*,int /*<<< orphan*/ ) ; 
 int pdc_pat_mem_pdt_info (struct pdc_pat_mem_retinfo*) ; 
 TYPE_1__ pdt_status ; 
 scalar_t__ pdt_type ; 
 int /*<<< orphan*/  pr_warn (char*,unsigned long,char*,char*,char*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

void arch_report_meminfo(struct seq_file *m)
{
	if (pdt_type == PDT_NONE)
		return;

	seq_printf(m, "PDT_max_entries: %7lu\n",
			pdt_status.pdt_size);
	seq_printf(m, "PDT_cur_entries: %7lu\n",
			pdt_status.pdt_entries);
}

__attribute__((used)) static int get_info_pat_new(void)
{
	struct pdc_pat_mem_retinfo pat_rinfo;
	int ret;

	/* newer PAT machines like C8000 report info for all cells */
	if (is_pdc_pat())
		ret = pdc_pat_mem_pdt_info(&pat_rinfo);
	else
		return PDC_BAD_PROC;

	pdt_status.pdt_size = pat_rinfo.max_pdt_entries;
	pdt_status.pdt_entries = pat_rinfo.current_pdt_entries;
	pdt_status.pdt_status = 0;
	pdt_status.first_dbe_loc = pat_rinfo.first_dbe_loc;
	pdt_status.good_mem = pat_rinfo.good_mem;

	return ret;
}

__attribute__((used)) static int get_info_pat_cell(void)
{
	struct pdc_pat_mem_cell_pdt_retinfo cell_rinfo;
	int ret;

	/* older PAT machines like rp5470 report cell info only */
	if (is_pdc_pat())
		ret = pdc_pat_mem_pdt_cell_info(&cell_rinfo, parisc_cell_num);
	else
		return PDC_BAD_PROC;

	pdt_status.pdt_size = cell_rinfo.max_pdt_entries;
	pdt_status.pdt_entries = cell_rinfo.current_pdt_entries;
	pdt_status.pdt_status = 0;
	pdt_status.first_dbe_loc = cell_rinfo.first_dbe_loc;
	pdt_status.good_mem = cell_rinfo.good_mem;

	return ret;
}

__attribute__((used)) static void report_mem_err(unsigned long pde)
{
	struct pdc_pat_mem_phys_mem_location loc;
	unsigned long addr;
	char dimm_txt[32];

	addr = pde & PDT_ADDR_PHYS_MASK;

	/* show DIMM slot description on PAT machines */
	if (is_pdc_pat()) {
		pdc_pat_mem_get_dimm_phys_location(&loc, addr);
		sprintf(dimm_txt, "DIMM slot %02x, ", loc.dimm_slot);
	} else
		dimm_txt[0] = 0;

	pr_warn("PDT: BAD MEMORY at 0x%08lx, %s%s%s-bit error.\n",
		addr, dimm_txt,
		pde & PDT_ADDR_PERM_ERR ? "permanent ":"",
		pde & PDT_ADDR_SINGLE_ERR ? "single":"multi");
}


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
typedef  int u64 ;
typedef  unsigned long phys_addr_t ;
struct TYPE_4__ {int MAS0; int MAS1; unsigned long MAS2; unsigned long MAS3; int MAS7; } ;
struct TYPE_3__ {unsigned long limit; unsigned long start; unsigned long phys; } ;

/* Variables and functions */
 int MAS0_ESEL (int) ; 
 int MAS0_NV (int) ; 
 int MAS0_TLBSEL (int) ; 
 int MAS1_IPROT ; 
 int MAS1_TID (unsigned int) ; 
 int MAS1_TSIZE (unsigned int) ; 
 int MAS1_VALID ; 
 unsigned long MAS2_E ; 
 unsigned long MAS2_G ; 
 unsigned long MAS2_I ; 
 unsigned long MAS2_M ; 
 unsigned long MAS2_W ; 
 unsigned long MAS3_RPN ; 
 unsigned long MAS3_SR ; 
 unsigned long MAS3_SW ; 
 unsigned long MAS3_SX ; 
 int MAS3_UR ; 
 int MAS3_UW ; 
 int MAS3_UX ; 
 int MMUCFG_MAVN ; 
 int MMUCFG_MAVN_V1 ; 
 int /*<<< orphan*/  MMU_FTR_BIG_PHYS ; 
 int /*<<< orphan*/  PAGE_KERNEL_X ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_OFFSET ; 
 int /*<<< orphan*/  SPRN_MMUCFG ; 
 int /*<<< orphan*/  SPRN_TLB1CFG ; 
 int /*<<< orphan*/  SPRN_TLB1PS ; 
 TYPE_2__* TLBCAM ; 
 unsigned long _PAGE_COHERENT ; 
 unsigned long _PAGE_ENDIAN ; 
 unsigned long _PAGE_GUARDED ; 
 unsigned long _PAGE_NO_CACHE ; 
 unsigned long _PAGE_RW ; 
 unsigned long _PAGE_WRITETHRU ; 
 unsigned int __ffs (unsigned long) ; 
 int __ilog2 (int) ; 
 int /*<<< orphan*/  __pte (unsigned long) ; 
 int /*<<< orphan*/  loadcam_multi (int /*<<< orphan*/ ,int,int) ; 
 unsigned long memstart_addr ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 scalar_t__ mmu_has_feature (int /*<<< orphan*/ ) ; 
 unsigned long pgprot_val (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_user (int /*<<< orphan*/ ) ; 
 TYPE_1__* tlbcam_addrs ; 
 int tlbcam_index ; 

__attribute__((used)) static inline phys_addr_t v_block_mapped(unsigned long va) { return 0; }

__attribute__((used)) static inline unsigned long p_block_mapped(phys_addr_t pa) { return 0; }

unsigned long tlbcam_sz(int idx)
{
	return tlbcam_addrs[idx].limit - tlbcam_addrs[idx].start + 1;
}

__attribute__((used)) static void settlbcam(int index, unsigned long virt, phys_addr_t phys,
		unsigned long size, unsigned long flags, unsigned int pid)
{
	unsigned int tsize;

	tsize = __ilog2(size) - 10;

#if defined(CONFIG_SMP) || defined(CONFIG_PPC_E500MC)
	if ((flags & _PAGE_NO_CACHE) == 0)
		flags |= _PAGE_COHERENT;
#endif

	TLBCAM[index].MAS0 = MAS0_TLBSEL(1) | MAS0_ESEL(index) | MAS0_NV(index+1);
	TLBCAM[index].MAS1 = MAS1_VALID | MAS1_IPROT | MAS1_TSIZE(tsize) | MAS1_TID(pid);
	TLBCAM[index].MAS2 = virt & PAGE_MASK;

	TLBCAM[index].MAS2 |= (flags & _PAGE_WRITETHRU) ? MAS2_W : 0;
	TLBCAM[index].MAS2 |= (flags & _PAGE_NO_CACHE) ? MAS2_I : 0;
	TLBCAM[index].MAS2 |= (flags & _PAGE_COHERENT) ? MAS2_M : 0;
	TLBCAM[index].MAS2 |= (flags & _PAGE_GUARDED) ? MAS2_G : 0;
	TLBCAM[index].MAS2 |= (flags & _PAGE_ENDIAN) ? MAS2_E : 0;

	TLBCAM[index].MAS3 = (phys & MAS3_RPN) | MAS3_SX | MAS3_SR;
	TLBCAM[index].MAS3 |= ((flags & _PAGE_RW) ? MAS3_SW : 0);
	if (mmu_has_feature(MMU_FTR_BIG_PHYS))
		TLBCAM[index].MAS7 = (u64)phys >> 32;

	/* Below is unlikely -- only for large user pages or similar */
	if (pte_user(__pte(flags))) {
	   TLBCAM[index].MAS3 |= MAS3_UX | MAS3_UR;
	   TLBCAM[index].MAS3 |= ((flags & _PAGE_RW) ? MAS3_UW : 0);
	}

	tlbcam_addrs[index].start = virt;
	tlbcam_addrs[index].limit = virt + size - 1;
	tlbcam_addrs[index].phys = phys;
}

unsigned long calc_cam_sz(unsigned long ram, unsigned long virt,
			  phys_addr_t phys)
{
	unsigned int camsize = __ilog2(ram);
	unsigned int align = __ffs(virt | phys);
	unsigned long max_cam;

	if ((mfspr(SPRN_MMUCFG) & MMUCFG_MAVN) == MMUCFG_MAVN_V1) {
		/* Convert (4^max) kB to (2^max) bytes */
		max_cam = ((mfspr(SPRN_TLB1CFG) >> 16) & 0xf) * 2 + 10;
		camsize &= ~1U;
		align &= ~1U;
	} else {
		/* Convert (2^max) kB to (2^max) bytes */
		max_cam = __ilog2(mfspr(SPRN_TLB1PS)) + 10;
	}

	if (camsize > align)
		camsize = align;
	if (camsize > max_cam)
		camsize = max_cam;

	return 1UL << camsize;
}

__attribute__((used)) static unsigned long map_mem_in_cams_addr(phys_addr_t phys, unsigned long virt,
					unsigned long ram, int max_cam_idx,
					bool dryrun)
{
	int i;
	unsigned long amount_mapped = 0;

	/* Calculate CAM values */
	for (i = 0; ram && i < max_cam_idx; i++) {
		unsigned long cam_sz;

		cam_sz = calc_cam_sz(ram, virt, phys);
		if (!dryrun)
			settlbcam(i, virt, phys, cam_sz,
				  pgprot_val(PAGE_KERNEL_X), 0);

		ram -= cam_sz;
		amount_mapped += cam_sz;
		virt += cam_sz;
		phys += cam_sz;
	}

	if (dryrun)
		return amount_mapped;

	loadcam_multi(0, i, max_cam_idx);
	tlbcam_index = i;

#ifdef CONFIG_PPC64
	get_paca()->tcd.esel_next = i;
	get_paca()->tcd.esel_max = mfspr(SPRN_TLB1CFG) & TLBnCFG_N_ENTRY;
	get_paca()->tcd.esel_first = i;
#endif

	return amount_mapped;
}

unsigned long map_mem_in_cams(unsigned long ram, int max_cam_idx, bool dryrun)
{
	unsigned long virt = PAGE_OFFSET;
	phys_addr_t phys = memstart_addr;

	return map_mem_in_cams_addr(phys, virt, ram, max_cam_idx, dryrun);
}


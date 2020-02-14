#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct nvkm_vmm {int dummy; } ;
struct nvkm_mmu_pt {int dummy; } ;
struct nvkm_mmu {int dummy; } ;
struct lock_class_key {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT_ULL (int) ; 
 int /*<<< orphan*/  VMM_FO064 (struct nvkm_mmu_pt*,struct nvkm_vmm*,int,int /*<<< orphan*/ ,int) ; 
 int gf100_vmm_new_ (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct nvkm_mmu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int,struct lock_class_key*,char const*,struct nvkm_vmm**) ; 
 int /*<<< orphan*/  gk104_vmm_16 ; 
 int /*<<< orphan*/  gk104_vmm_17 ; 

void
gk104_vmm_lpt_invalid(struct nvkm_vmm *vmm,
		      struct nvkm_mmu_pt *pt, u32 ptei, u32 ptes)
{
	/* VALID_FALSE + PRIV tells the MMU to ignore corresponding SPTEs. */
	VMM_FO064(pt, vmm, ptei * 8, BIT_ULL(1) /* PRIV. */, ptes);
}

int
gk104_vmm_new(struct nvkm_mmu *mmu, u64 addr, u64 size, void *argv, u32 argc,
	      struct lock_class_key *key, const char *name,
	      struct nvkm_vmm **pvmm)
{
	return gf100_vmm_new_(&gk104_vmm_16, &gk104_vmm_17, mmu, addr,
			      size, argv, argc, key, name, pvmm);
}


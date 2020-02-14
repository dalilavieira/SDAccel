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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct nvkm_vmm_func {int dummy; } ;
struct nvkm_vmm {TYPE_2__* func; } ;
struct nvkm_mmu_pt {int dummy; } ;
struct nvkm_mmu {int dummy; } ;
struct nvkm_memory {int dummy; } ;
struct lock_class_key {int dummy; } ;
struct gm200_vmm_vn {int dummy; } ;
struct gm200_vmm_v0 {int bigpage; } ;
struct TYPE_4__ {TYPE_1__* page; } ;
struct TYPE_3__ {int shift; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT_ULL (int) ; 
 int EINVAL ; 
 int ENOSYS ; 
 int /*<<< orphan*/  VMM_FO064 (struct nvkm_mmu_pt*,struct nvkm_vmm*,int,int /*<<< orphan*/ ,int) ; 
 int gf100_vmm_join_ (struct nvkm_vmm*,struct nvkm_memory*,int /*<<< orphan*/ ) ; 
 int gf100_vmm_new_ (struct nvkm_vmm_func*,struct nvkm_vmm_func*,struct nvkm_mmu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int,struct lock_class_key*,char const*,struct nvkm_vmm**) ; 
 struct nvkm_vmm_func gm200_vmm_16 ; 
 struct nvkm_vmm_func gm200_vmm_17 ; 
 int nvif_unpack (int,void**,int*,struct gm200_vmm_v0,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nvif_unvers (int,void**,int*,struct gm200_vmm_vn) ; 
 int nvkm_vmm_new_ (struct nvkm_vmm_func const*,struct nvkm_mmu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct lock_class_key*,char const*,struct nvkm_vmm**) ; 

__attribute__((used)) static void
gm200_vmm_pgt_sparse(struct nvkm_vmm *vmm,
		     struct nvkm_mmu_pt *pt, u32 ptei, u32 ptes)
{
	/* VALID_FALSE + VOL tells the MMU to treat the PTE as sparse. */
	VMM_FO064(pt, vmm, ptei * 8, BIT_ULL(32) /* VOL. */, ptes);
}

__attribute__((used)) static void
gm200_vmm_pgd_sparse(struct nvkm_vmm *vmm,
		     struct nvkm_mmu_pt *pt, u32 pdei, u32 pdes)
{
	/* VALID_FALSE + VOL_BIG tells the MMU to treat the PDE as sparse. */
	VMM_FO064(pt, vmm, pdei * 8, BIT_ULL(35) /* VOL_BIG. */, pdes);
}

int
gm200_vmm_join_(struct nvkm_vmm *vmm, struct nvkm_memory *inst, u64 base)
{
	if (vmm->func->page[1].shift == 16)
		base |= BIT_ULL(11);
	return gf100_vmm_join_(vmm, inst, base);
}

int
gm200_vmm_join(struct nvkm_vmm *vmm, struct nvkm_memory *inst)
{
	return gm200_vmm_join_(vmm, inst, 0);
}

int
gm200_vmm_new_(const struct nvkm_vmm_func *func_16,
	       const struct nvkm_vmm_func *func_17,
	       struct nvkm_mmu *mmu, u64 addr, u64 size, void *argv, u32 argc,
	       struct lock_class_key *key, const char *name,
	       struct nvkm_vmm **pvmm)
{
	const struct nvkm_vmm_func *func;
	union {
		struct gm200_vmm_vn vn;
		struct gm200_vmm_v0 v0;
	} *args = argv;
	int ret = -ENOSYS;

	if (!(ret = nvif_unpack(ret, &argv, &argc, args->v0, 0, 0, false))) {
		switch (args->v0.bigpage) {
		case 16: func = func_16; break;
		case 17: func = func_17; break;
		default:
			return -EINVAL;
		}
	} else
	if (!(ret = nvif_unvers(ret, &argv, &argc, args->vn))) {
		func = func_17;
	} else
		return ret;

	return nvkm_vmm_new_(func, mmu, 0, addr, size, key, name, pvmm);
}

int
gm200_vmm_new(struct nvkm_mmu *mmu, u64 addr, u64 size, void *argv, u32 argc,
	      struct lock_class_key *key, const char *name,
	      struct nvkm_vmm **pvmm)
{
	return gm200_vmm_new_(&gm200_vmm_16, &gm200_vmm_17, mmu, addr,
			      size, argv, argc, key, name, pvmm);
}

int
gm200_vmm_new_fixed(struct nvkm_mmu *mmu, u64 addr, u64 size,
		    void *argv, u32 argc, struct lock_class_key *key,
		    const char *name, struct nvkm_vmm **pvmm)
{
	return gf100_vmm_new_(&gm200_vmm_16, &gm200_vmm_17, mmu, addr,
			      size, argv, argc, key, name, pvmm);
}


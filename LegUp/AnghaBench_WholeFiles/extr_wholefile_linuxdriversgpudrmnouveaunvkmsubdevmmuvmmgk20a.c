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
typedef  int /*<<< orphan*/  u32 ;
struct nvkm_vmm {int dummy; } ;
struct nvkm_mmu {int dummy; } ;
struct lock_class_key {int dummy; } ;
typedef  enum nvkm_memory_target { ____Placeholder_nvkm_memory_target } nvkm_memory_target ;

/* Variables and functions */
 int EINVAL ; 
#define  NVKM_MEM_TARGET_NCOH 128 
 int gf100_vmm_new_ (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct nvkm_mmu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,struct lock_class_key*,char const*,struct nvkm_vmm**) ; 
 int /*<<< orphan*/  gk20a_vmm_16 ; 
 int /*<<< orphan*/  gk20a_vmm_17 ; 

int
gk20a_vmm_aper(enum nvkm_memory_target target)
{
	switch (target) {
	case NVKM_MEM_TARGET_NCOH: return 0;
	default:
		return -EINVAL;
	}
}

int
gk20a_vmm_new(struct nvkm_mmu *mmu, u64 addr, u64 size, void *argv, u32 argc,
	      struct lock_class_key *key, const char *name,
	      struct nvkm_vmm **pvmm)
{
	return gf100_vmm_new_(&gk20a_vmm_16, &gk20a_vmm_17, mmu, addr,
			      size, argv, argc, key, name, pvmm);
}


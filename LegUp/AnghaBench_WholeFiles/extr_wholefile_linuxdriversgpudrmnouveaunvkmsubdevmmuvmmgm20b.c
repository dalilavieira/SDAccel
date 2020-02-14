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

/* Variables and functions */
 int gf100_vmm_new_ (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct nvkm_mmu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,struct lock_class_key*,char const*,struct nvkm_vmm**) ; 
 int gm200_vmm_new_ (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct nvkm_mmu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,struct lock_class_key*,char const*,struct nvkm_vmm**) ; 
 int /*<<< orphan*/  gm20b_vmm_16 ; 
 int /*<<< orphan*/  gm20b_vmm_17 ; 

int
gm20b_vmm_new(struct nvkm_mmu *mmu, u64 addr, u64 size, void *argv, u32 argc,
	      struct lock_class_key *key, const char *name,
	      struct nvkm_vmm **pvmm)
{
	return gm200_vmm_new_(&gm20b_vmm_16, &gm20b_vmm_17, mmu, addr,
			      size, argv, argc, key, name, pvmm);
}

int
gm20b_vmm_new_fixed(struct nvkm_mmu *mmu, u64 addr, u64 size,
		    void *argv, u32 argc, struct lock_class_key *key,
		    const char *name, struct nvkm_vmm **pvmm)
{
	return gf100_vmm_new_(&gm20b_vmm_16, &gm20b_vmm_17, mmu, addr,
			      size, argv, argc, key, name, pvmm);
}


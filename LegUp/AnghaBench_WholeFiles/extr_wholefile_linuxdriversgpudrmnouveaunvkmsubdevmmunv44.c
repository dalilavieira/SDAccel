#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct nvkm_mmu {TYPE_4__* vmm; TYPE_1__ subdev; } ;
struct nvkm_memory {int dummy; } ;
struct nvkm_device {scalar_t__ type; int /*<<< orphan*/  cfgopt; } ;
struct TYPE_8__ {int null; TYPE_3__* pd; } ;
struct TYPE_7__ {TYPE_2__** pt; } ;
struct TYPE_6__ {struct nvkm_memory* memory; } ;

/* Variables and functions */
 scalar_t__ NVKM_DEVICE_AGP ; 
 int nv04_mmu_new (struct nvkm_device*,int,struct nvkm_mmu**) ; 
 int /*<<< orphan*/  nv44_mmu ; 
 int /*<<< orphan*/  nvkm_boolopt (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_memory_addr (struct nvkm_memory*) ; 
 int nvkm_memory_size (struct nvkm_memory*) ; 
 int nvkm_mmu_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_mmu**) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
nv44_mmu_init(struct nvkm_mmu *mmu)
{
	struct nvkm_device *device = mmu->subdev.device;
	struct nvkm_memory *pt = mmu->vmm->pd->pt[0]->memory;
	u32 addr;

	/* calculate vram address of this PRAMIN block, object must be
	 * allocated on 512KiB alignment, and not exceed a total size
	 * of 512KiB for this to work correctly
	 */
	addr  = nvkm_rd32(device, 0x10020c);
	addr -= ((nvkm_memory_addr(pt) >> 19) + 1) << 19;

	nvkm_wr32(device, 0x100850, 0x80000000);
	nvkm_wr32(device, 0x100818, mmu->vmm->null);
	nvkm_wr32(device, 0x100804, (nvkm_memory_size(pt) / 4) * 4096);
	nvkm_wr32(device, 0x100850, 0x00008000);
	nvkm_mask(device, 0x10008c, 0x00000200, 0x00000200);
	nvkm_wr32(device, 0x100820, 0x00000000);
	nvkm_wr32(device, 0x10082c, 0x00000001);
	nvkm_wr32(device, 0x100800, addr | 0x00000010);
}

int
nv44_mmu_new(struct nvkm_device *device, int index, struct nvkm_mmu **pmmu)
{
	if (device->type == NVKM_DEVICE_AGP ||
	    !nvkm_boolopt(device->cfgopt, "NvPCIE", true))
		return nv04_mmu_new(device, index, pmmu);

	return nvkm_mmu_new_(&nv44_mmu, device, index, pmmu);
}


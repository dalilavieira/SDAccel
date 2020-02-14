#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct TYPE_11__ {int oclass; } ;
struct nvkm_oclass {TYPE_10__ base; } ;
struct nvkm_memory {int dummy; } ;
typedef  struct nvkm_memory nvkm_gpuobj ;
struct nvkm_dmaobj {int start; int limit; int target; int access; TYPE_3__* dma; } ;
struct TYPE_18__ {struct nvkm_device* device; } ;
struct TYPE_19__ {TYPE_7__ subdev; } ;
struct nvkm_dma {TYPE_8__ engine; } ;
struct nvkm_device {TYPE_9__* mmu; } ;
struct nv04_dmaobj {int clone; int flags0; int flags2; struct nvkm_dmaobj base; } ;
struct TYPE_20__ {int /*<<< orphan*/ * func; TYPE_6__* vmm; } ;
struct TYPE_17__ {TYPE_5__* pd; } ;
struct TYPE_16__ {TYPE_4__** pt; } ;
struct TYPE_15__ {struct nvkm_memory* memory; } ;
struct TYPE_12__ {struct nvkm_device* device; } ;
struct TYPE_13__ {TYPE_1__ subdev; } ;
struct TYPE_14__ {TYPE_2__ engine; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  NV_MEM_ACCESS_RO 133 
#define  NV_MEM_ACCESS_RW 132 
#define  NV_MEM_ACCESS_WO 131 
#define  NV_MEM_TARGET_PCI 130 
#define  NV_MEM_TARGET_PCI_NOSNOOP 129 
 int NV_MEM_TARGET_VM ; 
#define  NV_MEM_TARGET_VRAM 128 
 struct nv04_dmaobj* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct nv04_dmaobj* nv04_dmaobj (struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  nv04_dmaobj_func ; 
 int /*<<< orphan*/  nv04_mmu ; 
 int nvkm_dmaobj_ctor (int /*<<< orphan*/ *,struct nvkm_dma*,struct nvkm_oclass const*,void**,int*,struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  nvkm_done (struct nvkm_memory*) ; 
 int nvkm_gpuobj_new (struct nvkm_device*,int,int,int,struct nvkm_memory*,struct nvkm_memory**) ; 
 int nvkm_gpuobj_wrap (struct nvkm_memory*,struct nvkm_memory**) ; 
 int /*<<< orphan*/  nvkm_kmap (struct nvkm_memory*) ; 
 int nvkm_ro32 (struct nvkm_memory*,int) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_memory*,int,int) ; 

__attribute__((used)) static int
nv04_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
		 int align, struct nvkm_gpuobj **pgpuobj)
{
	struct nv04_dmaobj *dmaobj = nv04_dmaobj(base);
	struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
	u64 offset = dmaobj->base.start & 0xfffff000;
	u64 adjust = dmaobj->base.start & 0x00000fff;
	u32 length = dmaobj->base.limit - dmaobj->base.start;
	int ret;

	if (dmaobj->clone) {
		struct nvkm_memory *pgt =
			device->mmu->vmm->pd->pt[0]->memory;
		if (!dmaobj->base.start)
			return nvkm_gpuobj_wrap(pgt, pgpuobj);
		nvkm_kmap(pgt);
		offset  = nvkm_ro32(pgt, 8 + (offset >> 10));
		offset &= 0xfffff000;
		nvkm_done(pgt);
	}

	ret = nvkm_gpuobj_new(device, 16, align, false, parent, pgpuobj);
	if (ret == 0) {
		nvkm_kmap(*pgpuobj);
		nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0 | (adjust << 20));
		nvkm_wo32(*pgpuobj, 0x04, length);
		nvkm_wo32(*pgpuobj, 0x08, dmaobj->flags2 | offset);
		nvkm_wo32(*pgpuobj, 0x0c, dmaobj->flags2 | offset);
		nvkm_done(*pgpuobj);
	}

	return ret;
}

int
nv04_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
		void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
	struct nvkm_device *device = dma->engine.subdev.device;
	struct nv04_dmaobj *dmaobj;
	int ret;

	if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
		return -ENOMEM;
	*pdmaobj = &dmaobj->base;

	ret = nvkm_dmaobj_ctor(&nv04_dmaobj_func, dma, oclass,
			       &data, &size, &dmaobj->base);
	if (ret)
		return ret;

	if (dmaobj->base.target == NV_MEM_TARGET_VM) {
		if (device->mmu->func == &nv04_mmu)
			dmaobj->clone = true;
		dmaobj->base.target = NV_MEM_TARGET_PCI;
		dmaobj->base.access = NV_MEM_ACCESS_RW;
	}

	dmaobj->flags0 = oclass->base.oclass;
	switch (dmaobj->base.target) {
	case NV_MEM_TARGET_VRAM:
		dmaobj->flags0 |= 0x00003000;
		break;
	case NV_MEM_TARGET_PCI:
		dmaobj->flags0 |= 0x00023000;
		break;
	case NV_MEM_TARGET_PCI_NOSNOOP:
		dmaobj->flags0 |= 0x00033000;
		break;
	default:
		return -EINVAL;
	}

	switch (dmaobj->base.access) {
	case NV_MEM_ACCESS_RO:
		dmaobj->flags0 |= 0x00004000;
		break;
	case NV_MEM_ACCESS_WO:
		dmaobj->flags0 |= 0x00008000;
	case NV_MEM_ACCESS_RW:
		dmaobj->flags2 |= 0x00000002;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}


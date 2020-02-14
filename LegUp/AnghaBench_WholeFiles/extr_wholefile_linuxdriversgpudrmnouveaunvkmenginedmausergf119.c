#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nvkm_oclass {struct nvkm_object* parent; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_gpuobj {int dummy; } ;
struct nvkm_dmaobj {int start; int limit; int target; TYPE_3__* dma; } ;
struct nvkm_dma {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct gf119_dmaobj {int flags0; struct nvkm_dmaobj base; } ;
struct gf119_dma_v0 {int page; int kind; int /*<<< orphan*/  version; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;
struct TYPE_6__ {TYPE_2__ engine; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int GF119_DMA_V0_KIND_PITCH ; 
 int GF119_DMA_V0_KIND_VM ; 
 int GF119_DMA_V0_PAGE_LP ; 
 int GF119_DMA_V0_PAGE_SP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  NV_MEM_TARGET_PCI 131 
#define  NV_MEM_TARGET_PCI_NOSNOOP 130 
#define  NV_MEM_TARGET_VM 129 
#define  NV_MEM_TARGET_VRAM 128 
 struct gf119_dmaobj* gf119_dmaobj (struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  gf119_dmaobj_func ; 
 struct gf119_dmaobj* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvif_ioctl (struct nvkm_object*,char*,int,...) ; 
 int nvif_unpack (int,void**,int*,struct gf119_dma_v0,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nvkm_dmaobj_ctor (int /*<<< orphan*/ *,struct nvkm_dma*,struct nvkm_oclass const*,void**,int*,struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  nvkm_done (struct nvkm_gpuobj*) ; 
 int nvkm_gpuobj_new (struct nvkm_device*,int,int,int,struct nvkm_gpuobj*,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_kmap (struct nvkm_gpuobj*) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_gpuobj*,int,int) ; 

__attribute__((used)) static int
gf119_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
		  int align, struct nvkm_gpuobj **pgpuobj)
{
	struct gf119_dmaobj *dmaobj = gf119_dmaobj(base);
	struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
	int ret;

	ret = nvkm_gpuobj_new(device, 24, align, false, parent, pgpuobj);
	if (ret == 0) {
		nvkm_kmap(*pgpuobj);
		nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0);
		nvkm_wo32(*pgpuobj, 0x04, dmaobj->base.start >> 8);
		nvkm_wo32(*pgpuobj, 0x08, dmaobj->base.limit >> 8);
		nvkm_wo32(*pgpuobj, 0x0c, 0x00000000);
		nvkm_wo32(*pgpuobj, 0x10, 0x00000000);
		nvkm_wo32(*pgpuobj, 0x14, 0x00000000);
		nvkm_done(*pgpuobj);
	}

	return ret;
}

int
gf119_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
		 void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
	union {
		struct gf119_dma_v0 v0;
	} *args;
	struct nvkm_object *parent = oclass->parent;
	struct gf119_dmaobj *dmaobj;
	u32 kind, page;
	int ret;

	if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
		return -ENOMEM;
	*pdmaobj = &dmaobj->base;

	ret = nvkm_dmaobj_ctor(&gf119_dmaobj_func, dma, oclass,
			       &data, &size, &dmaobj->base);
	if (ret)
		return ret;

	ret  = -ENOSYS;
	args = data;

	nvif_ioctl(parent, "create gf119 dma size %d\n", size);
	if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
		nvif_ioctl(parent,
			   "create gf100 dma vers %d page %d kind %02x\n",
			   args->v0.version, args->v0.page, args->v0.kind);
		kind = args->v0.kind;
		page = args->v0.page;
	} else
	if (size == 0) {
		if (dmaobj->base.target != NV_MEM_TARGET_VM) {
			kind = GF119_DMA_V0_KIND_PITCH;
			page = GF119_DMA_V0_PAGE_SP;
		} else {
			kind = GF119_DMA_V0_KIND_VM;
			page = GF119_DMA_V0_PAGE_LP;
		}
	} else
		return ret;

	if (page > 1)
		return -EINVAL;
	dmaobj->flags0 = (kind << 20) | (page << 6);

	switch (dmaobj->base.target) {
	case NV_MEM_TARGET_VRAM:
		dmaobj->flags0 |= 0x00000009;
		break;
	case NV_MEM_TARGET_VM:
	case NV_MEM_TARGET_PCI:
	case NV_MEM_TARGET_PCI_NOSNOOP:
		/* XXX: don't currently know how to construct a real one
		 *      of these.  we only use them to represent pushbufs
		 *      on these chipsets, and the classes that use them
		 *      deal with the target themselves.
		 */
		break;
	default:
		return -EINVAL;
	}

	return 0;
}


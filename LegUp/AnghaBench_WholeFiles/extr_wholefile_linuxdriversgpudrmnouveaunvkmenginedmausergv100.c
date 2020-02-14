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
typedef  int u64 ;
typedef  int u32 ;
struct nvkm_oclass {struct nvkm_object* parent; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_gpuobj {int dummy; } ;
struct nvkm_dmaobj {int start; int limit; int target; TYPE_3__* dma; } ;
struct nvkm_dma {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct gv100_dmaobj {int flags0; struct nvkm_dmaobj base; } ;
struct gf119_dma_v0 {scalar_t__ page; scalar_t__ kind; int /*<<< orphan*/  version; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;
struct TYPE_6__ {TYPE_2__ engine; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int GF119_DMA_V0_PAGE_SP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  NV_MEM_TARGET_PCI 130 
#define  NV_MEM_TARGET_PCI_NOSNOOP 129 
#define  NV_MEM_TARGET_VRAM 128 
 struct gv100_dmaobj* gv100_dmaobj (struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  gv100_dmaobj_func ; 
 struct gv100_dmaobj* kzalloc (int,int /*<<< orphan*/ ) ; 
 int lower_32_bits (int) ; 
 int /*<<< orphan*/  nvif_ioctl (struct nvkm_object*,char*,int,...) ; 
 int nvif_unpack (int,void**,int*,struct gf119_dma_v0,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nvkm_dmaobj_ctor (int /*<<< orphan*/ *,struct nvkm_dma*,struct nvkm_oclass const*,void**,int*,struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  nvkm_done (struct nvkm_gpuobj*) ; 
 int nvkm_gpuobj_new (struct nvkm_device*,int,int,int,struct nvkm_gpuobj*,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_kmap (struct nvkm_gpuobj*) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_gpuobj*,int,int) ; 
 int upper_32_bits (int) ; 

__attribute__((used)) static int
gv100_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
		  int align, struct nvkm_gpuobj **pgpuobj)
{
	struct gv100_dmaobj *dmaobj = gv100_dmaobj(base);
	struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
	u64 start = dmaobj->base.start >> 8;
	u64 limit = dmaobj->base.limit >> 8;
	int ret;

	ret = nvkm_gpuobj_new(device, 24, align, false, parent, pgpuobj);
	if (ret == 0) {
		nvkm_kmap(*pgpuobj);
		nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0);
		nvkm_wo32(*pgpuobj, 0x04, lower_32_bits(start));
		nvkm_wo32(*pgpuobj, 0x08, upper_32_bits(start));
		nvkm_wo32(*pgpuobj, 0x0c, lower_32_bits(limit));
		nvkm_wo32(*pgpuobj, 0x10, upper_32_bits(limit));
		nvkm_done(*pgpuobj);
	}

	return ret;
}

int
gv100_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
		 void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
	union {
		struct gf119_dma_v0 v0;
	} *args;
	struct nvkm_object *parent = oclass->parent;
	struct gv100_dmaobj *dmaobj;
	u32 kind, page;
	int ret;

	if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
		return -ENOMEM;
	*pdmaobj = &dmaobj->base;

	ret = nvkm_dmaobj_ctor(&gv100_dmaobj_func, dma, oclass,
			       &data, &size, &dmaobj->base);
	if (ret)
		return ret;

	ret  = -ENOSYS;
	args = data;

	nvif_ioctl(parent, "create gv100 dma size %d\n", size);
	if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
		nvif_ioctl(parent,
			   "create gv100 dma vers %d page %d kind %02x\n",
			   args->v0.version, args->v0.page, args->v0.kind);
		kind = args->v0.kind != 0;
		page = args->v0.page != 0;
	} else
	if (size == 0) {
		kind = 0;
		page = GF119_DMA_V0_PAGE_SP;
	} else
		return ret;

	if (kind)
		dmaobj->flags0 |= 0x00100000;
	if (page)
		dmaobj->flags0 |= 0x00000040;
	dmaobj->flags0 |= 0x00000004; /* rw */

	switch (dmaobj->base.target) {
	case NV_MEM_TARGET_VRAM       : dmaobj->flags0 |= 0x00000001; break;
	case NV_MEM_TARGET_PCI        : dmaobj->flags0 |= 0x00000002; break;
	case NV_MEM_TARGET_PCI_NOSNOOP: dmaobj->flags0 |= 0x00000003; break;
	default:
		return -EINVAL;
	}

	return 0;
}


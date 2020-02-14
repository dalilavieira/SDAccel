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
struct TYPE_8__ {int oclass; } ;
struct nvkm_oclass {TYPE_4__ base; struct nvkm_object* parent; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_gpuobj {int dummy; } ;
struct nvkm_dmaobj {int target; int access; int /*<<< orphan*/  start; int /*<<< orphan*/  limit; TYPE_3__* dma; } ;
struct nvkm_dma {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct gf100_dmaobj {int flags0; int flags5; struct nvkm_dmaobj base; } ;
struct gf100_dma_v0 {int priv; int kind; int /*<<< orphan*/  version; } ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct TYPE_6__ {TYPE_1__ subdev; } ;
struct TYPE_7__ {TYPE_2__ engine; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int GF100_DMA_V0_KIND_PITCH ; 
 int GF100_DMA_V0_KIND_VM ; 
 int GF100_DMA_V0_PRIV_US ; 
 int GF100_DMA_V0_PRIV_VM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  NV_MEM_ACCESS_RO 135 
#define  NV_MEM_ACCESS_RW 134 
#define  NV_MEM_ACCESS_VM 133 
#define  NV_MEM_ACCESS_WO 132 
#define  NV_MEM_TARGET_PCI 131 
#define  NV_MEM_TARGET_PCI_NOSNOOP 130 
#define  NV_MEM_TARGET_VM 129 
#define  NV_MEM_TARGET_VRAM 128 
 struct gf100_dmaobj* gf100_dmaobj (struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  gf100_dmaobj_func ; 
 struct gf100_dmaobj* kzalloc (int,int /*<<< orphan*/ ) ; 
 int lower_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvif_ioctl (struct nvkm_object*,char*,int,...) ; 
 int nvif_unpack (int,void**,int*,struct gf100_dma_v0,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nvkm_dmaobj_ctor (int /*<<< orphan*/ *,struct nvkm_dma*,struct nvkm_oclass const*,void**,int*,struct nvkm_dmaobj*) ; 
 int /*<<< orphan*/  nvkm_done (struct nvkm_gpuobj*) ; 
 int nvkm_gpuobj_new (struct nvkm_device*,int,int,int,struct nvkm_gpuobj*,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_kmap (struct nvkm_gpuobj*) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_gpuobj*,int,int) ; 
 int upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
gf100_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
		  int align, struct nvkm_gpuobj **pgpuobj)
{
	struct gf100_dmaobj *dmaobj = gf100_dmaobj(base);
	struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
	int ret;

	ret = nvkm_gpuobj_new(device, 24, align, false, parent, pgpuobj);
	if (ret == 0) {
		nvkm_kmap(*pgpuobj);
		nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0);
		nvkm_wo32(*pgpuobj, 0x04, lower_32_bits(dmaobj->base.limit));
		nvkm_wo32(*pgpuobj, 0x08, lower_32_bits(dmaobj->base.start));
		nvkm_wo32(*pgpuobj, 0x0c, upper_32_bits(dmaobj->base.limit) << 24 |
					  upper_32_bits(dmaobj->base.start));
		nvkm_wo32(*pgpuobj, 0x10, 0x00000000);
		nvkm_wo32(*pgpuobj, 0x14, dmaobj->flags5);
		nvkm_done(*pgpuobj);
	}

	return ret;
}

int
gf100_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
		 void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
	union {
		struct gf100_dma_v0 v0;
	} *args;
	struct nvkm_object *parent = oclass->parent;
	struct gf100_dmaobj *dmaobj;
	u32 kind, user, unkn;
	int ret;

	if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
		return -ENOMEM;
	*pdmaobj = &dmaobj->base;

	ret = nvkm_dmaobj_ctor(&gf100_dmaobj_func, dma, oclass,
			       &data, &size, &dmaobj->base);
	if (ret)
		return ret;

	ret  = -ENOSYS;
	args = data;

	nvif_ioctl(parent, "create gf100 dma size %d\n", size);
	if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
		nvif_ioctl(parent,
			   "create gf100 dma vers %d priv %d kind %02x\n",
			   args->v0.version, args->v0.priv, args->v0.kind);
		kind = args->v0.kind;
		user = args->v0.priv;
		unkn = 0;
	} else
	if (size == 0) {
		if (dmaobj->base.target != NV_MEM_TARGET_VM) {
			kind = GF100_DMA_V0_KIND_PITCH;
			user = GF100_DMA_V0_PRIV_US;
			unkn = 2;
		} else {
			kind = GF100_DMA_V0_KIND_VM;
			user = GF100_DMA_V0_PRIV_VM;
			unkn = 0;
		}
	} else
		return ret;

	if (user > 2)
		return -EINVAL;
	dmaobj->flags0 |= (kind << 22) | (user << 20) | oclass->base.oclass;
	dmaobj->flags5 |= (unkn << 16);

	switch (dmaobj->base.target) {
	case NV_MEM_TARGET_VM:
		dmaobj->flags0 |= 0x00000000;
		break;
	case NV_MEM_TARGET_VRAM:
		dmaobj->flags0 |= 0x00010000;
		break;
	case NV_MEM_TARGET_PCI:
		dmaobj->flags0 |= 0x00020000;
		break;
	case NV_MEM_TARGET_PCI_NOSNOOP:
		dmaobj->flags0 |= 0x00030000;
		break;
	default:
		return -EINVAL;
	}

	switch (dmaobj->base.access) {
	case NV_MEM_ACCESS_VM:
		break;
	case NV_MEM_ACCESS_RO:
		dmaobj->flags0 |= 0x00040000;
		break;
	case NV_MEM_ACCESS_WO:
	case NV_MEM_ACCESS_RW:
		dmaobj->flags0 |= 0x00080000;
		break;
	}

	return 0;
}


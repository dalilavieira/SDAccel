#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct nvkm_sclass {int dummy; } ;
struct nvkm_oclass {struct nvkm_sclass base; struct nvkm_sclass const* engn; struct nvkm_engine* engine; } ;
struct nvkm_object {int dummy; } ;
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_engine {TYPE_1__ subdev; } ;
struct nvkm_dmaobj {struct nvkm_object object; } ;
struct nvkm_dma_func {int (* class_new ) (struct nvkm_dma*,struct nvkm_oclass const*,void*,int /*<<< orphan*/ ,struct nvkm_dmaobj**) ;} ;
struct nvkm_dma {int /*<<< orphan*/  engine; struct nvkm_dma_func const* func; } ;
struct nvkm_device_oclass {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct nvkm_sclass*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nvkm_dma* kzalloc (int,int /*<<< orphan*/ ) ; 
 void* nvkm_dma (struct nvkm_engine*) ; 
 struct nvkm_device_oclass nvkm_dma_oclass_base ; 
 struct nvkm_sclass* nvkm_dma_sclass ; 
 int nvkm_engine_ctor (void* (*) (struct nvkm_engine*),struct nvkm_device*,int,int,int /*<<< orphan*/ *) ; 
 int stub1 (struct nvkm_dma*,struct nvkm_oclass const*,void*,int /*<<< orphan*/ ,struct nvkm_dmaobj**) ; 

__attribute__((used)) static int
nvkm_dma_oclass_new(struct nvkm_device *device,
		    const struct nvkm_oclass *oclass, void *data, u32 size,
		    struct nvkm_object **pobject)
{
	struct nvkm_dma *dma = nvkm_dma(oclass->engine);
	struct nvkm_dmaobj *dmaobj = NULL;
	int ret;

	ret = dma->func->class_new(dma, oclass, data, size, &dmaobj);
	if (dmaobj)
		*pobject = &dmaobj->object;
	return ret;
}

__attribute__((used)) static int
nvkm_dma_oclass_fifo_new(const struct nvkm_oclass *oclass, void *data, u32 size,
			 struct nvkm_object **pobject)
{
	return nvkm_dma_oclass_new(oclass->engine->subdev.device,
				   oclass, data, size, pobject);
}

__attribute__((used)) static int
nvkm_dma_oclass_base_get(struct nvkm_oclass *sclass, int index,
			 const struct nvkm_device_oclass **class)
{
	const int count = ARRAY_SIZE(nvkm_dma_sclass);
	if (index < count) {
		const struct nvkm_sclass *oclass = &nvkm_dma_sclass[index];
		sclass->base = oclass[0];
		sclass->engn = oclass;
		*class = &nvkm_dma_oclass_base;
		return index;
	}
	return count;
}

__attribute__((used)) static int
nvkm_dma_oclass_fifo_get(struct nvkm_oclass *oclass, int index)
{
	const int count = ARRAY_SIZE(nvkm_dma_sclass);
	if (index < count) {
		oclass->base = nvkm_dma_sclass[index];
		return index;
	}
	return count;
}

__attribute__((used)) static void *
nvkm_dma_dtor(struct nvkm_engine *engine)
{
	return nvkm_dma(engine);
}

int
nvkm_dma_new_(const struct nvkm_dma_func *func, struct nvkm_device *device,
	      int index, struct nvkm_dma **pdma)
{
	struct nvkm_dma *dma;

	if (!(dma = *pdma = kzalloc(sizeof(*dma), GFP_KERNEL)))
		return -ENOMEM;
	dma->func = func;

	return nvkm_engine_ctor(&nvkm_dma, device, index, true, &dma->engine);
}


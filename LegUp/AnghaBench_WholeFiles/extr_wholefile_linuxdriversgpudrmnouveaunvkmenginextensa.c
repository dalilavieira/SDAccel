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
struct nvkm_xtensa_func {int unkd28; int /*<<< orphan*/  fifo_val; TYPE_1__* sclass; } ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_engine {struct nvkm_subdev subdev; } ;
struct nvkm_xtensa {int addr; struct nvkm_engine engine; struct nvkm_xtensa_func const* func; int /*<<< orphan*/  gpu_fw; } ;
struct TYPE_4__ {scalar_t__ oclass; } ;
struct nvkm_oclass {TYPE_1__ base; struct nvkm_engine* engine; } ;
struct nvkm_object {TYPE_3__* engine; } ;
struct nvkm_gpuobj {int dummy; } ;
struct nvkm_device {int /*<<< orphan*/  dev; } ;
struct firmware {int size; scalar_t__ data; } ;
typedef  int /*<<< orphan*/  name ;
struct TYPE_5__ {int /*<<< orphan*/  device; } ;
struct TYPE_6__ {TYPE_2__ subdev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  NVKM_MEM_TARGET_INST ; 
 struct nvkm_xtensa* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*) ; 
 int /*<<< orphan*/  nvkm_done (int /*<<< orphan*/ ) ; 
 int nvkm_engine_ctor (void* (*) (struct nvkm_engine*),struct nvkm_device*,int,int,struct nvkm_engine*) ; 
 int nvkm_gpuobj_new (int /*<<< orphan*/ ,int,int,int,struct nvkm_gpuobj*,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_kmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int nvkm_memory_addr (int /*<<< orphan*/ ) ; 
 int nvkm_memory_new (struct nvkm_device*,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *) ; 
 int nvkm_memory_size (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_memory_unref (int /*<<< orphan*/ *) ; 
 int nvkm_rd32 (struct nvkm_device*,int const) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*,...) ; 
 int /*<<< orphan*/  nvkm_wo32 (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int const,int) ; 
 void* nvkm_xtensa (struct nvkm_engine*) ; 
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 

__attribute__((used)) static int
nvkm_xtensa_oclass_get(struct nvkm_oclass *oclass, int index)
{
	struct nvkm_xtensa *xtensa = nvkm_xtensa(oclass->engine);
	int c = 0;

	while (xtensa->func->sclass[c].oclass) {
		if (c++ == index) {
			oclass->base = xtensa->func->sclass[index];
			return index;
		}
	}

	return c;
}

__attribute__((used)) static int
nvkm_xtensa_cclass_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
			int align, struct nvkm_gpuobj **pgpuobj)
{
	return nvkm_gpuobj_new(object->engine->subdev.device, 0x10000, align,
			       true, parent, pgpuobj);
}

__attribute__((used)) static void
nvkm_xtensa_intr(struct nvkm_engine *engine)
{
	struct nvkm_xtensa *xtensa = nvkm_xtensa(engine);
	struct nvkm_subdev *subdev = &xtensa->engine.subdev;
	struct nvkm_device *device = subdev->device;
	const u32 base = xtensa->addr;
	u32 unk104 = nvkm_rd32(device, base + 0xd04);
	u32 intr = nvkm_rd32(device, base + 0xc20);
	u32 chan = nvkm_rd32(device, base + 0xc28);
	u32 unk10c = nvkm_rd32(device, base + 0xd0c);

	if (intr & 0x10)
		nvkm_warn(subdev, "Watchdog interrupt, engine hung.\n");
	nvkm_wr32(device, base + 0xc20, intr);
	intr = nvkm_rd32(device, base + 0xc20);
	if (unk104 == 0x10001 && unk10c == 0x200 && chan && !intr) {
		nvkm_debug(subdev, "Enabling FIFO_CTRL\n");
		nvkm_mask(device, xtensa->addr + 0xd94, 0, xtensa->func->fifo_val);
	}
}

__attribute__((used)) static int
nvkm_xtensa_fini(struct nvkm_engine *engine, bool suspend)
{
	struct nvkm_xtensa *xtensa = nvkm_xtensa(engine);
	struct nvkm_device *device = xtensa->engine.subdev.device;
	const u32 base = xtensa->addr;

	nvkm_wr32(device, base + 0xd84, 0); /* INTR_EN */
	nvkm_wr32(device, base + 0xd94, 0); /* FIFO_CTRL */

	if (!suspend)
		nvkm_memory_unref(&xtensa->gpu_fw);
	return 0;
}

__attribute__((used)) static int
nvkm_xtensa_init(struct nvkm_engine *engine)
{
	struct nvkm_xtensa *xtensa = nvkm_xtensa(engine);
	struct nvkm_subdev *subdev = &xtensa->engine.subdev;
	struct nvkm_device *device = subdev->device;
	const u32 base = xtensa->addr;
	const struct firmware *fw;
	char name[32];
	int i, ret;
	u64 addr, size;
	u32 tmp;

	if (!xtensa->gpu_fw) {
		snprintf(name, sizeof(name), "nouveau/nv84_xuc%03x",
			 xtensa->addr >> 12);

		ret = request_firmware(&fw, name, device->dev);
		if (ret) {
			nvkm_warn(subdev, "unable to load firmware %s\n", name);
			return ret;
		}

		if (fw->size > 0x40000) {
			nvkm_warn(subdev, "firmware %s too large\n", name);
			release_firmware(fw);
			return -EINVAL;
		}

		ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST,
				      0x40000, 0x1000, false,
				      &xtensa->gpu_fw);
		if (ret) {
			release_firmware(fw);
			return ret;
		}

		nvkm_kmap(xtensa->gpu_fw);
		for (i = 0; i < fw->size / 4; i++)
			nvkm_wo32(xtensa->gpu_fw, i * 4, *((u32 *)fw->data + i));
		nvkm_done(xtensa->gpu_fw);
		release_firmware(fw);
	}

	addr = nvkm_memory_addr(xtensa->gpu_fw);
	size = nvkm_memory_size(xtensa->gpu_fw);

	nvkm_wr32(device, base + 0xd10, 0x1fffffff); /* ?? */
	nvkm_wr32(device, base + 0xd08, 0x0fffffff); /* ?? */

	nvkm_wr32(device, base + 0xd28, xtensa->func->unkd28); /* ?? */
	nvkm_wr32(device, base + 0xc20, 0x3f); /* INTR */
	nvkm_wr32(device, base + 0xd84, 0x3f); /* INTR_EN */

	nvkm_wr32(device, base + 0xcc0, addr >> 8); /* XT_REGION_BASE */
	nvkm_wr32(device, base + 0xcc4, 0x1c); /* XT_REGION_SETUP */
	nvkm_wr32(device, base + 0xcc8, size >> 8); /* XT_REGION_LIMIT */

	tmp = nvkm_rd32(device, 0x0);
	nvkm_wr32(device, base + 0xde0, tmp); /* SCRATCH_H2X */

	nvkm_wr32(device, base + 0xce8, 0xf); /* XT_REGION_SETUP */

	nvkm_wr32(device, base + 0xc20, 0x3f); /* INTR */
	nvkm_wr32(device, base + 0xd84, 0x3f); /* INTR_EN */
	return 0;
}

__attribute__((used)) static void *
nvkm_xtensa_dtor(struct nvkm_engine *engine)
{
	return nvkm_xtensa(engine);
}

int
nvkm_xtensa_new_(const struct nvkm_xtensa_func *func,
		 struct nvkm_device *device, int index, bool enable,
		 u32 addr, struct nvkm_engine **pengine)
{
	struct nvkm_xtensa *xtensa;

	if (!(xtensa = kzalloc(sizeof(*xtensa), GFP_KERNEL)))
		return -ENOMEM;
	xtensa->func = func;
	xtensa->addr = addr;
	*pengine = &xtensa->engine;

	return nvkm_engine_ctor(&nvkm_xtensa, device, index,
				enable, &xtensa->engine);
}


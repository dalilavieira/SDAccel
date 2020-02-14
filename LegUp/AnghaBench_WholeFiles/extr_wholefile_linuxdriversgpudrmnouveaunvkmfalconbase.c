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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct nvkm_subdev {int index; struct nvkm_device* device; } ;
struct nvkm_memory {int dummy; } ;
struct nvkm_falcon_func {int (* enable ) (struct nvkm_falcon*) ;int (* wait_for_halt ) (struct nvkm_falcon*,int) ;int (* clear_interrupt ) (struct nvkm_falcon*,int) ;int /*<<< orphan*/  (* disable ) (struct nvkm_falcon*) ;int /*<<< orphan*/  (* start ) (struct nvkm_falcon*) ;int /*<<< orphan*/  (* set_start_addr ) (struct nvkm_falcon*,int) ;int /*<<< orphan*/  (* bind_context ) (struct nvkm_falcon*,struct nvkm_memory*) ;int /*<<< orphan*/  (* read_dmem ) (struct nvkm_falcon*,int,int,int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  (* load_dmem ) (struct nvkm_falcon*,void*,int,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* load_imem ) (struct nvkm_falcon*,void*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ;} ;
struct TYPE_3__ {int ports; int limit; } ;
struct TYPE_4__ {int ports; int limit; } ;
struct nvkm_falcon {int secret; char const* name; int addr; int version; int has_emem; int debug; TYPE_1__ data; TYPE_2__ code; int /*<<< orphan*/  dmem_mutex; int /*<<< orphan*/  mutex; struct nvkm_subdev* owner; struct nvkm_falcon_func const* func; struct nvkm_subdev const* user; } ;
struct nvkm_device {int dummy; } ;
typedef  enum nvkm_devidx { ____Placeholder_nvkm_devidx } nvkm_devidx ;

/* Variables and functions */
 int EBUSY ; 
#define  NVKM_ENGINE_GR 131 
#define  NVKM_ENGINE_NVDEC 130 
#define  NVKM_ENGINE_SEC2 129 
#define  NVKM_SUBDEV_PMU 128 
 int /*<<< orphan*/  kfree (struct nvkm_falcon*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev const*,char*,char const*) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev const*,char*,...) ; 
 int nvkm_falcon_rd32 (struct nvkm_falcon*,int) ; 
 int /*<<< orphan*/  nvkm_mc_disable (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_mc_enable (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_mc_enabled (struct nvkm_device*,int) ; 
 int /*<<< orphan*/ * nvkm_subdev_name ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev const*,char*,...) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_falcon*,void*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int stub10 (struct nvkm_falcon*,int) ; 
 int /*<<< orphan*/  stub2 (struct nvkm_falcon*,void*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct nvkm_falcon*,int,int,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub4 (struct nvkm_falcon*,struct nvkm_memory*) ; 
 int /*<<< orphan*/  stub5 (struct nvkm_falcon*,int) ; 
 int /*<<< orphan*/  stub6 (struct nvkm_falcon*) ; 
 int stub7 (struct nvkm_falcon*) ; 
 int /*<<< orphan*/  stub8 (struct nvkm_falcon*) ; 
 int stub9 (struct nvkm_falcon*,int) ; 
 scalar_t__ unlikely (int) ; 

void
nvkm_falcon_load_imem(struct nvkm_falcon *falcon, void *data, u32 start,
		      u32 size, u16 tag, u8 port, bool secure)
{
	if (secure && !falcon->secret) {
		nvkm_warn(falcon->user,
			  "writing with secure tag on a non-secure falcon!\n");
		return;
	}

	falcon->func->load_imem(falcon, data, start, size, tag, port,
				secure);
}

void
nvkm_falcon_load_dmem(struct nvkm_falcon *falcon, void *data, u32 start,
		      u32 size, u8 port)
{
	mutex_lock(&falcon->dmem_mutex);

	falcon->func->load_dmem(falcon, data, start, size, port);

	mutex_unlock(&falcon->dmem_mutex);
}

void
nvkm_falcon_read_dmem(struct nvkm_falcon *falcon, u32 start, u32 size, u8 port,
		      void *data)
{
	mutex_lock(&falcon->dmem_mutex);

	falcon->func->read_dmem(falcon, start, size, port, data);

	mutex_unlock(&falcon->dmem_mutex);
}

void
nvkm_falcon_bind_context(struct nvkm_falcon *falcon, struct nvkm_memory *inst)
{
	if (!falcon->func->bind_context) {
		nvkm_error(falcon->user,
			   "Context binding not supported on this falcon!\n");
		return;
	}

	falcon->func->bind_context(falcon, inst);
}

void
nvkm_falcon_set_start_addr(struct nvkm_falcon *falcon, u32 start_addr)
{
	falcon->func->set_start_addr(falcon, start_addr);
}

void
nvkm_falcon_start(struct nvkm_falcon *falcon)
{
	falcon->func->start(falcon);
}

int
nvkm_falcon_enable(struct nvkm_falcon *falcon)
{
	struct nvkm_device *device = falcon->owner->device;
	enum nvkm_devidx id = falcon->owner->index;
	int ret;

	nvkm_mc_enable(device, id);
	ret = falcon->func->enable(falcon);
	if (ret) {
		nvkm_mc_disable(device, id);
		return ret;
	}

	return 0;
}

void
nvkm_falcon_disable(struct nvkm_falcon *falcon)
{
	struct nvkm_device *device = falcon->owner->device;
	enum nvkm_devidx id = falcon->owner->index;

	/* already disabled, return or wait_idle will timeout */
	if (!nvkm_mc_enabled(device, id))
		return;

	falcon->func->disable(falcon);

	nvkm_mc_disable(device, id);
}

int
nvkm_falcon_reset(struct nvkm_falcon *falcon)
{
	nvkm_falcon_disable(falcon);
	return nvkm_falcon_enable(falcon);
}

int
nvkm_falcon_wait_for_halt(struct nvkm_falcon *falcon, u32 ms)
{
	return falcon->func->wait_for_halt(falcon, ms);
}

int
nvkm_falcon_clear_interrupt(struct nvkm_falcon *falcon, u32 mask)
{
	return falcon->func->clear_interrupt(falcon, mask);
}

void
nvkm_falcon_put(struct nvkm_falcon *falcon, const struct nvkm_subdev *user)
{
	if (unlikely(!falcon))
		return;

	mutex_lock(&falcon->mutex);
	if (falcon->user == user) {
		nvkm_debug(falcon->user, "released %s falcon\n", falcon->name);
		falcon->user = NULL;
	}
	mutex_unlock(&falcon->mutex);
}

int
nvkm_falcon_get(struct nvkm_falcon *falcon, const struct nvkm_subdev *user)
{
	mutex_lock(&falcon->mutex);
	if (falcon->user) {
		nvkm_error(user, "%s falcon already acquired by %s!\n",
			   falcon->name, nvkm_subdev_name[falcon->user->index]);
		mutex_unlock(&falcon->mutex);
		return -EBUSY;
	}

	nvkm_debug(user, "acquired %s falcon\n", falcon->name);
	falcon->user = user;
	mutex_unlock(&falcon->mutex);
	return 0;
}

void
nvkm_falcon_ctor(const struct nvkm_falcon_func *func,
		 struct nvkm_subdev *subdev, const char *name, u32 addr,
		 struct nvkm_falcon *falcon)
{
	u32 debug_reg;
	u32 reg;

	falcon->func = func;
	falcon->owner = subdev;
	falcon->name = name;
	falcon->addr = addr;
	mutex_init(&falcon->mutex);
	mutex_init(&falcon->dmem_mutex);

	reg = nvkm_falcon_rd32(falcon, 0x12c);
	falcon->version = reg & 0xf;
	falcon->secret = (reg >> 4) & 0x3;
	falcon->code.ports = (reg >> 8) & 0xf;
	falcon->data.ports = (reg >> 12) & 0xf;

	reg = nvkm_falcon_rd32(falcon, 0x108);
	falcon->code.limit = (reg & 0x1ff) << 8;
	falcon->data.limit = (reg & 0x3fe00) >> 1;

	switch (subdev->index) {
	case NVKM_ENGINE_GR:
		debug_reg = 0x0;
		break;
	case NVKM_SUBDEV_PMU:
		debug_reg = 0xc08;
		break;
	case NVKM_ENGINE_NVDEC:
		debug_reg = 0xd00;
		break;
	case NVKM_ENGINE_SEC2:
		debug_reg = 0x408;
		falcon->has_emem = true;
		break;
	default:
		nvkm_warn(subdev, "unsupported falcon %s!\n",
			  nvkm_subdev_name[subdev->index]);
		debug_reg = 0;
		break;
	}

	if (debug_reg) {
		u32 val = nvkm_falcon_rd32(falcon, debug_reg);
		falcon->debug = (val >> 20) & 0x1;
	}
}

void
nvkm_falcon_del(struct nvkm_falcon **pfalcon)
{
	if (*pfalcon) {
		kfree(*pfalcon);
		*pfalcon = NULL;
	}
}


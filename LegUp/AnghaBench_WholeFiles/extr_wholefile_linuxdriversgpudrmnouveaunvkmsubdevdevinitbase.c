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
struct nvkm_subdev {int /*<<< orphan*/  device; } ;
struct nvkm_devinit_func {int (* pll_set ) (struct nvkm_devinit*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* post ) (struct nvkm_devinit*,int) ;void* (* dtor ) (struct nvkm_devinit*) ;int /*<<< orphan*/  (* init ) (struct nvkm_devinit*) ;int /*<<< orphan*/  (* preinit ) (struct nvkm_devinit*) ;int /*<<< orphan*/  (* disable ) (struct nvkm_devinit*) ;int /*<<< orphan*/  (* meminit ) (struct nvkm_devinit*) ;int /*<<< orphan*/  (* mmio ) (struct nvkm_devinit*,int /*<<< orphan*/ ) ;} ;
struct nvkm_devinit {int post; int force_post; struct nvkm_devinit_func const* func; int /*<<< orphan*/  subdev; } ;
struct nvkm_device {int /*<<< orphan*/  cfgopt; } ;

/* Variables and functions */
 int nvkm_boolopt (int /*<<< orphan*/ ,char*,int) ; 
 struct nvkm_devinit* nvkm_devinit (struct nvkm_subdev*) ; 
 int /*<<< orphan*/  nvkm_lockvgac (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nvkm_subdev_ctor (struct nvkm_devinit* (*) (struct nvkm_subdev*),struct nvkm_device*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_devinit*,int /*<<< orphan*/ ) ; 
 int stub2 (struct nvkm_devinit*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct nvkm_devinit*) ; 
 int /*<<< orphan*/  stub4 (struct nvkm_devinit*) ; 
 int stub5 (struct nvkm_devinit*,int) ; 
 int /*<<< orphan*/  stub6 (struct nvkm_devinit*) ; 
 int /*<<< orphan*/  stub7 (struct nvkm_devinit*) ; 
 void* stub8 (struct nvkm_devinit*) ; 

u32
nvkm_devinit_mmio(struct nvkm_devinit *init, u32 addr)
{
	if (init->func->mmio)
		addr = init->func->mmio(init, addr);
	return addr;
}

int
nvkm_devinit_pll_set(struct nvkm_devinit *init, u32 type, u32 khz)
{
	return init->func->pll_set(init, type, khz);
}

void
nvkm_devinit_meminit(struct nvkm_devinit *init)
{
	if (init->func->meminit)
		init->func->meminit(init);
}

u64
nvkm_devinit_disable(struct nvkm_devinit *init)
{
	if (init && init->func->disable)
		return init->func->disable(init);
	return 0;
}

int
nvkm_devinit_post(struct nvkm_devinit *init, u64 *disable)
{
	int ret = 0;
	if (init && init->func->post)
		ret = init->func->post(init, init->post);
	*disable = nvkm_devinit_disable(init);
	return ret;
}

__attribute__((used)) static int
nvkm_devinit_fini(struct nvkm_subdev *subdev, bool suspend)
{
	struct nvkm_devinit *init = nvkm_devinit(subdev);
	/* force full reinit on resume */
	if (suspend)
		init->post = true;
	return 0;
}

__attribute__((used)) static int
nvkm_devinit_preinit(struct nvkm_subdev *subdev)
{
	struct nvkm_devinit *init = nvkm_devinit(subdev);

	if (init->func->preinit)
		init->func->preinit(init);

	/* Override the post flag during the first call if NvForcePost is set */
	if (init->force_post) {
		init->post = init->force_post;
		init->force_post = false;
	}

	/* unlock the extended vga crtc regs */
	nvkm_lockvgac(subdev->device, false);
	return 0;
}

__attribute__((used)) static int
nvkm_devinit_init(struct nvkm_subdev *subdev)
{
	struct nvkm_devinit *init = nvkm_devinit(subdev);
	if (init->func->init)
		init->func->init(init);
	return 0;
}

__attribute__((used)) static void *
nvkm_devinit_dtor(struct nvkm_subdev *subdev)
{
	struct nvkm_devinit *init = nvkm_devinit(subdev);
	void *data = init;

	if (init->func->dtor)
		data = init->func->dtor(init);

	/* lock crtc regs */
	nvkm_lockvgac(subdev->device, true);
	return data;
}

void
nvkm_devinit_ctor(const struct nvkm_devinit_func *func,
		  struct nvkm_device *device, int index,
		  struct nvkm_devinit *init)
{
	nvkm_subdev_ctor(&nvkm_devinit, device, index, &init->subdev);
	init->func = func;
	init->force_post = nvkm_boolopt(device->cfgopt, "NvForcePost", false);
}


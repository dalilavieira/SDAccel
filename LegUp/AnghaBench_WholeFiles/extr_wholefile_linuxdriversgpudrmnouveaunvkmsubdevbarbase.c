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
struct nvkm_vmm {int dummy; } ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_device {struct nvkm_bar* bar; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* wait ) (struct nvkm_bar*) ;int /*<<< orphan*/  (* init ) (struct nvkm_bar*) ;int /*<<< orphan*/  (* fini ) (struct nvkm_bar*) ;struct nvkm_vmm* (* vmm ) (struct nvkm_bar*) ;} ;
struct TYPE_4__ {int /*<<< orphan*/  (* wait ) (struct nvkm_bar*) ;int /*<<< orphan*/  (* init ) (struct nvkm_bar*) ;int /*<<< orphan*/  (* fini ) (struct nvkm_bar*) ;struct nvkm_vmm* (* vmm ) (struct nvkm_bar*) ;} ;
struct nvkm_bar_func {int (* oneinit ) (struct nvkm_bar*) ;void* (* dtor ) (struct nvkm_bar*) ;int /*<<< orphan*/  (* init ) (struct nvkm_bar*) ;TYPE_2__ bar1; TYPE_1__ bar2; int /*<<< orphan*/  (* flush ) (struct nvkm_bar*) ;} ;
struct TYPE_6__ {scalar_t__ oneinit; } ;
struct nvkm_bar {int bar2; int /*<<< orphan*/  lock; struct nvkm_bar_func const* func; TYPE_3__ subdev; } ;

/* Variables and functions */
 struct nvkm_bar* nvkm_bar (struct nvkm_subdev*) ; 
 int /*<<< orphan*/  nvkm_subdev_ctor (struct nvkm_bar* (*) (struct nvkm_subdev*),struct nvkm_device*,int,TYPE_3__*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub10 (struct nvkm_bar*) ; 
 int stub11 (struct nvkm_bar*) ; 
 void* stub12 (struct nvkm_bar*) ; 
 struct nvkm_vmm* stub2 (struct nvkm_bar*) ; 
 struct nvkm_vmm* stub3 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub4 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub5 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub6 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub7 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub8 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub9 (struct nvkm_bar*) ; 

void
nvkm_bar_flush(struct nvkm_bar *bar)
{
	if (bar && bar->func->flush)
		bar->func->flush(bar);
}

struct nvkm_vmm *
nvkm_bar_bar1_vmm(struct nvkm_device *device)
{
	return device->bar->func->bar1.vmm(device->bar);
}

struct nvkm_vmm *
nvkm_bar_bar2_vmm(struct nvkm_device *device)
{
	/* Denies access to BAR2 when it's not initialised, used by INSTMEM
	 * to know when object access needs to go through the BAR0 window.
	 */
	struct nvkm_bar *bar = device->bar;
	if (bar && bar->bar2)
		return bar->func->bar2.vmm(bar);
	return NULL;
}

void
nvkm_bar_bar2_fini(struct nvkm_device *device)
{
	struct nvkm_bar *bar = device->bar;
	if (bar && bar->bar2) {
		bar->func->bar2.fini(bar);
		bar->bar2 = false;
	}
}

void
nvkm_bar_bar2_init(struct nvkm_device *device)
{
	struct nvkm_bar *bar = device->bar;
	if (bar && bar->subdev.oneinit && !bar->bar2 && bar->func->bar2.init) {
		bar->func->bar2.init(bar);
		bar->func->bar2.wait(bar);
		bar->bar2 = true;
	}
}

__attribute__((used)) static int
nvkm_bar_fini(struct nvkm_subdev *subdev, bool suspend)
{
	struct nvkm_bar *bar = nvkm_bar(subdev);
	if (bar->func->bar1.fini)
		bar->func->bar1.fini(bar);
	return 0;
}

__attribute__((used)) static int
nvkm_bar_init(struct nvkm_subdev *subdev)
{
	struct nvkm_bar *bar = nvkm_bar(subdev);
	bar->func->bar1.init(bar);
	bar->func->bar1.wait(bar);
	if (bar->func->init)
		bar->func->init(bar);
	return 0;
}

__attribute__((used)) static int
nvkm_bar_oneinit(struct nvkm_subdev *subdev)
{
	struct nvkm_bar *bar = nvkm_bar(subdev);
	return bar->func->oneinit(bar);
}

__attribute__((used)) static void *
nvkm_bar_dtor(struct nvkm_subdev *subdev)
{
	struct nvkm_bar *bar = nvkm_bar(subdev);
	nvkm_bar_bar2_fini(subdev->device);
	return bar->func->dtor(bar);
}

void
nvkm_bar_ctor(const struct nvkm_bar_func *func, struct nvkm_device *device,
	      int index, struct nvkm_bar *bar)
{
	nvkm_subdev_ctor(&nvkm_bar, device, index, &bar->subdev);
	bar->func = func;
	spin_lock_init(&bar->lock);
}


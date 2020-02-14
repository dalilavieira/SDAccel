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
struct nvkm_subdev {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct nvkm_bus_func {int /*<<< orphan*/  (* init ) (struct nvkm_bus*) ;int /*<<< orphan*/  (* intr ) (struct nvkm_bus*) ;} ;
struct nvkm_bus {struct nvkm_bus_func const* func; int /*<<< orphan*/  subdev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nvkm_bus* kzalloc (int,int /*<<< orphan*/ ) ; 
 void* nvkm_bus (struct nvkm_subdev*) ; 
 int /*<<< orphan*/  nvkm_subdev_ctor (void* (*) (struct nvkm_subdev*),struct nvkm_device*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_bus*) ; 
 int /*<<< orphan*/  stub2 (struct nvkm_bus*) ; 

__attribute__((used)) static void
nvkm_bus_intr(struct nvkm_subdev *subdev)
{
	struct nvkm_bus *bus = nvkm_bus(subdev);
	bus->func->intr(bus);
}

__attribute__((used)) static int
nvkm_bus_init(struct nvkm_subdev *subdev)
{
	struct nvkm_bus *bus = nvkm_bus(subdev);
	bus->func->init(bus);
	return 0;
}

__attribute__((used)) static void *
nvkm_bus_dtor(struct nvkm_subdev *subdev)
{
	return nvkm_bus(subdev);
}

int
nvkm_bus_new_(const struct nvkm_bus_func *func, struct nvkm_device *device,
	      int index, struct nvkm_bus **pbus)
{
	struct nvkm_bus *bus;
	if (!(bus = *pbus = kzalloc(sizeof(*bus), GFP_KERNEL)))
		return -ENOMEM;
	nvkm_subdev_ctor(&nvkm_bus, device, index, &bus->subdev);
	bus->func = func;
	return 0;
}


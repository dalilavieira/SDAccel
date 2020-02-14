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
typedef  int u32 ;
struct nvkm_therm {int /*<<< orphan*/  subdev; } ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_gpio {int /*<<< orphan*/  subdev; } ;
struct nvkm_device {struct nvkm_therm* therm; struct nvkm_gpio* gpio; } ;
struct nvkm_bus {struct nvkm_subdev subdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv31_bus ; 
 int nvkm_bus_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_bus**) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*,...) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_subdev_intr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
nv31_bus_intr(struct nvkm_bus *bus)
{
	struct nvkm_subdev *subdev = &bus->subdev;
	struct nvkm_device *device = subdev->device;
	u32 stat = nvkm_rd32(device, 0x001100) & nvkm_rd32(device, 0x001140);
	u32 gpio = nvkm_rd32(device, 0x001104) & nvkm_rd32(device, 0x001144);

	if (gpio) {
		struct nvkm_gpio *gpio = device->gpio;
		if (gpio)
			nvkm_subdev_intr(&gpio->subdev);
	}

	if (stat & 0x00000008) {  /* NV41- */
		u32 addr = nvkm_rd32(device, 0x009084);
		u32 data = nvkm_rd32(device, 0x009088);

		nvkm_error(subdev, "MMIO %s of %08x FAULT at %06x\n",
			   (addr & 0x00000002) ? "write" : "read", data,
			   (addr & 0x00fffffc));

		stat &= ~0x00000008;
		nvkm_wr32(device, 0x001100, 0x00000008);
	}

	if (stat & 0x00070000) {
		struct nvkm_therm *therm = device->therm;
		if (therm)
			nvkm_subdev_intr(&therm->subdev);
		stat &= ~0x00070000;
		nvkm_wr32(device, 0x001100, 0x00070000);
	}

	if (stat) {
		nvkm_error(subdev, "intr %08x\n", stat);
		nvkm_mask(device, 0x001140, stat, 0x00000000);
	}
}

__attribute__((used)) static void
nv31_bus_init(struct nvkm_bus *bus)
{
	struct nvkm_device *device = bus->subdev.device;
	nvkm_wr32(device, 0x001100, 0xffffffff);
	nvkm_wr32(device, 0x001140, 0x00070008);
}

int
nv31_bus_new(struct nvkm_device *device, int index, struct nvkm_bus **pbus)
{
	return nvkm_bus_new_(&nv31_bus, device, index, pbus);
}


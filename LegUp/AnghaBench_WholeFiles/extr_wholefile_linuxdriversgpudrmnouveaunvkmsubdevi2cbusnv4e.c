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
typedef  scalar_t__ u8 ;
struct nvkm_i2c_pad {int dummy; } ;
struct nvkm_i2c_bus {TYPE_3__* pad; } ;
struct nvkm_device {int dummy; } ;
struct nv4e_i2c_bus {scalar_t__ addr; struct nvkm_i2c_bus base; } ;
struct TYPE_6__ {TYPE_2__* i2c; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nv4e_i2c_bus* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct nv4e_i2c_bus* nv4e_i2c_bus (struct nvkm_i2c_bus*) ; 
 int /*<<< orphan*/  nv4e_i2c_bus_func ; 
 int /*<<< orphan*/  nvkm_i2c_bus_ctor (int /*<<< orphan*/ *,struct nvkm_i2c_pad*,int,struct nvkm_i2c_bus*) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,scalar_t__,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,scalar_t__) ; 

__attribute__((used)) static void
nv4e_i2c_bus_drive_scl(struct nvkm_i2c_bus *base, int state)
{
	struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	nvkm_mask(device, bus->addr, 0x2f, state ? 0x21 : 0x01);
}

__attribute__((used)) static void
nv4e_i2c_bus_drive_sda(struct nvkm_i2c_bus *base, int state)
{
	struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	nvkm_mask(device, bus->addr, 0x1f, state ? 0x11 : 0x01);
}

__attribute__((used)) static int
nv4e_i2c_bus_sense_scl(struct nvkm_i2c_bus *base)
{
	struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	return !!(nvkm_rd32(device, bus->addr) & 0x00040000);
}

__attribute__((used)) static int
nv4e_i2c_bus_sense_sda(struct nvkm_i2c_bus *base)
{
	struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	return !!(nvkm_rd32(device, bus->addr) & 0x00080000);
}

int
nv4e_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive,
		 struct nvkm_i2c_bus **pbus)
{
	struct nv4e_i2c_bus *bus;

	if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
		return -ENOMEM;
	*pbus = &bus->base;

	nvkm_i2c_bus_ctor(&nv4e_i2c_bus_func, pad, id, &bus->base);
	bus->addr = 0x600800 + drive;
	return 0;
}


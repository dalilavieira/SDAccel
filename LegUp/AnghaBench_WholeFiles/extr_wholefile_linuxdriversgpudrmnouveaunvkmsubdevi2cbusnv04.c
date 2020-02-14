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
typedef  int u8 ;
struct nvkm_i2c_pad {int dummy; } ;
struct nvkm_i2c_bus {TYPE_3__* pad; } ;
struct nvkm_device {int dummy; } ;
struct nv04_i2c_bus {int drive; int sense; struct nvkm_i2c_bus base; } ;
struct TYPE_6__ {TYPE_2__* i2c; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nv04_i2c_bus* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct nv04_i2c_bus* nv04_i2c_bus (struct nvkm_i2c_bus*) ; 
 int /*<<< orphan*/  nv04_i2c_bus_func ; 
 int /*<<< orphan*/  nvkm_i2c_bus_ctor (int /*<<< orphan*/ *,struct nvkm_i2c_pad*,int,struct nvkm_i2c_bus*) ; 
 int nvkm_rdvgac (struct nvkm_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nvkm_wrvgac (struct nvkm_device*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void
nv04_i2c_bus_drive_scl(struct nvkm_i2c_bus *base, int state)
{
	struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	u8 val = nvkm_rdvgac(device, 0, bus->drive);
	if (state) val |= 0x20;
	else	   val &= 0xdf;
	nvkm_wrvgac(device, 0, bus->drive, val | 0x01);
}

__attribute__((used)) static void
nv04_i2c_bus_drive_sda(struct nvkm_i2c_bus *base, int state)
{
	struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	u8 val = nvkm_rdvgac(device, 0, bus->drive);
	if (state) val |= 0x10;
	else	   val &= 0xef;
	nvkm_wrvgac(device, 0, bus->drive, val | 0x01);
}

__attribute__((used)) static int
nv04_i2c_bus_sense_scl(struct nvkm_i2c_bus *base)
{
	struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	return !!(nvkm_rdvgac(device, 0, bus->sense) & 0x04);
}

__attribute__((used)) static int
nv04_i2c_bus_sense_sda(struct nvkm_i2c_bus *base)
{
	struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	return !!(nvkm_rdvgac(device, 0, bus->sense) & 0x08);
}

int
nv04_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive, u8 sense,
		 struct nvkm_i2c_bus **pbus)
{
	struct nv04_i2c_bus *bus;

	if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
		return -ENOMEM;
	*pbus = &bus->base;

	nvkm_i2c_bus_ctor(&nv04_i2c_bus_func, pad, id, &bus->base);
	bus->drive = drive;
	bus->sense = sense;
	return 0;
}


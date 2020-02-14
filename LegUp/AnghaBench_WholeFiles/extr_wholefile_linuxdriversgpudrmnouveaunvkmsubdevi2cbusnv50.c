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
typedef  size_t u8 ;
typedef  int u32 ;
struct nvkm_i2c_pad {TYPE_4__* i2c; } ;
struct nvkm_i2c_bus {TYPE_3__* pad; } ;
struct nvkm_device {int dummy; } ;
struct nv50_i2c_bus {int data; int addr; struct nvkm_i2c_bus base; } ;
struct TYPE_8__ {int /*<<< orphan*/  subdev; } ;
struct TYPE_7__ {TYPE_2__* i2c; } ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct TYPE_6__ {TYPE_1__ subdev; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (int const*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nv50_i2c_bus* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct nv50_i2c_bus* nv50_i2c_bus (struct nvkm_i2c_bus*) ; 
 int /*<<< orphan*/  nv50_i2c_bus_func ; 
 int /*<<< orphan*/  nvkm_i2c_bus_ctor (int /*<<< orphan*/ *,struct nvkm_i2c_pad*,int,struct nvkm_i2c_bus*) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_warn (int /*<<< orphan*/ *,char*,size_t) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
nv50_i2c_bus_drive_scl(struct nvkm_i2c_bus *base, int state)
{
	struct nv50_i2c_bus *bus = nv50_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	if (state) bus->data |= 0x01;
	else	   bus->data &= 0xfe;
	nvkm_wr32(device, bus->addr, bus->data);
}

__attribute__((used)) static void
nv50_i2c_bus_drive_sda(struct nvkm_i2c_bus *base, int state)
{
	struct nv50_i2c_bus *bus = nv50_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	if (state) bus->data |= 0x02;
	else	   bus->data &= 0xfd;
	nvkm_wr32(device, bus->addr, bus->data);
}

__attribute__((used)) static int
nv50_i2c_bus_sense_scl(struct nvkm_i2c_bus *base)
{
	struct nv50_i2c_bus *bus = nv50_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	return !!(nvkm_rd32(device, bus->addr) & 0x00000001);
}

__attribute__((used)) static int
nv50_i2c_bus_sense_sda(struct nvkm_i2c_bus *base)
{
	struct nv50_i2c_bus *bus = nv50_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	return !!(nvkm_rd32(device, bus->addr) & 0x00000002);
}

__attribute__((used)) static void
nv50_i2c_bus_init(struct nvkm_i2c_bus *base)
{
	struct nv50_i2c_bus *bus = nv50_i2c_bus(base);
	struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
	nvkm_wr32(device, bus->addr, (bus->data = 0x00000007));
}

int
nv50_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive,
		 struct nvkm_i2c_bus **pbus)
{
	static const u32 addr[] = {
		0x00e138, 0x00e150, 0x00e168, 0x00e180,
		0x00e254, 0x00e274, 0x00e764, 0x00e780,
		0x00e79c, 0x00e7b8
	};
	struct nv50_i2c_bus *bus;

	if (drive >= ARRAY_SIZE(addr)) {
		nvkm_warn(&pad->i2c->subdev, "bus %d unknown\n", drive);
		return -ENODEV;
	}

	if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
		return -ENOMEM;
	*pbus = &bus->base;

	nvkm_i2c_bus_ctor(&nv50_i2c_bus_func, pad, id, &bus->base);
	bus->addr = addr[drive];
	bus->data = 0x00000007;
	return 0;
}


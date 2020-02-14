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
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_5__ {int link; } ;
struct nvkm_ior {int id; TYPE_4__* disp; TYPE_1__ asy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_6__ {struct nvkm_device* device; } ;
struct TYPE_7__ {TYPE_2__ subdev; } ;
struct TYPE_8__ {TYPE_3__ engine; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int const,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int const,int) ; 

__attribute__((used)) static inline u32
nv50_ior_base(struct nvkm_ior *ior)
{
	return ior->id * 0x800;
}

__attribute__((used)) static inline u32
nv50_sor_link(struct nvkm_ior *ior)
{
	return nv50_ior_base(ior) + ((ior->asy.link == 2) * 0x80);
}

void
gf119_hda_eld(struct nvkm_ior *ior, u8 *data, u8 size)
{
	struct nvkm_device *device = ior->disp->engine.subdev.device;
	const u32 soff = 0x030 * ior->id;
	int i;

	for (i = 0; i < size; i++)
		nvkm_wr32(device, 0x10ec00 + soff, (i << 8) | data[i]);
	for (; i < 0x60; i++)
		nvkm_wr32(device, 0x10ec00 + soff, (i << 8));
	nvkm_mask(device, 0x10ec10 + soff, 0x80000002, 0x80000002);
}

void
gf119_hda_hpd(struct nvkm_ior *ior, int head, bool present)
{
	struct nvkm_device *device = ior->disp->engine.subdev.device;
	const u32 hoff = 0x800 * head;
	u32 data = 0x80000000;
	u32 mask = 0x80000001;
	if (present) {
		nvkm_mask(device, 0x616548 + hoff, 0x00000070, 0x00000000);
		data |= 0x00000001;
	} else {
		mask |= 0x00000002;
	}
	nvkm_mask(device, 0x10ec10 + ior->id * 0x030, mask, data);
}


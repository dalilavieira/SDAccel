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
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  gf100_ibus ; 
 struct nvkm_subdev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*,int,int,int,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_subdev_ctor (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_subdev*) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
gf100_ibus_intr_hub(struct nvkm_subdev *ibus, int i)
{
	struct nvkm_device *device = ibus->device;
	u32 addr = nvkm_rd32(device, 0x122120 + (i * 0x0400));
	u32 data = nvkm_rd32(device, 0x122124 + (i * 0x0400));
	u32 stat = nvkm_rd32(device, 0x122128 + (i * 0x0400));
	nvkm_debug(ibus, "HUB%d: %06x %08x (%08x)\n", i, addr, data, stat);
	nvkm_mask(device, 0x122128 + (i * 0x0400), 0x00000200, 0x00000000);
}

__attribute__((used)) static void
gf100_ibus_intr_rop(struct nvkm_subdev *ibus, int i)
{
	struct nvkm_device *device = ibus->device;
	u32 addr = nvkm_rd32(device, 0x124120 + (i * 0x0400));
	u32 data = nvkm_rd32(device, 0x124124 + (i * 0x0400));
	u32 stat = nvkm_rd32(device, 0x124128 + (i * 0x0400));
	nvkm_debug(ibus, "ROP%d: %06x %08x (%08x)\n", i, addr, data, stat);
	nvkm_mask(device, 0x124128 + (i * 0x0400), 0x00000200, 0x00000000);
}

__attribute__((used)) static void
gf100_ibus_intr_gpc(struct nvkm_subdev *ibus, int i)
{
	struct nvkm_device *device = ibus->device;
	u32 addr = nvkm_rd32(device, 0x128120 + (i * 0x0400));
	u32 data = nvkm_rd32(device, 0x128124 + (i * 0x0400));
	u32 stat = nvkm_rd32(device, 0x128128 + (i * 0x0400));
	nvkm_debug(ibus, "GPC%d: %06x %08x (%08x)\n", i, addr, data, stat);
	nvkm_mask(device, 0x128128 + (i * 0x0400), 0x00000200, 0x00000000);
}

void
gf100_ibus_intr(struct nvkm_subdev *ibus)
{
	struct nvkm_device *device = ibus->device;
	u32 intr0 = nvkm_rd32(device, 0x121c58);
	u32 intr1 = nvkm_rd32(device, 0x121c5c);
	u32 hubnr = nvkm_rd32(device, 0x121c70);
	u32 ropnr = nvkm_rd32(device, 0x121c74);
	u32 gpcnr = nvkm_rd32(device, 0x121c78);
	u32 i;

	for (i = 0; (intr0 & 0x0000ff00) && i < hubnr; i++) {
		u32 stat = 0x00000100 << i;
		if (intr0 & stat) {
			gf100_ibus_intr_hub(ibus, i);
			intr0 &= ~stat;
		}
	}

	for (i = 0; (intr0 & 0xffff0000) && i < ropnr; i++) {
		u32 stat = 0x00010000 << i;
		if (intr0 & stat) {
			gf100_ibus_intr_rop(ibus, i);
			intr0 &= ~stat;
		}
	}

	for (i = 0; intr1 && i < gpcnr; i++) {
		u32 stat = 0x00000001 << i;
		if (intr1 & stat) {
			gf100_ibus_intr_gpc(ibus, i);
			intr1 &= ~stat;
		}
	}
}

__attribute__((used)) static int
gf100_ibus_init(struct nvkm_subdev *ibus)
{
	struct nvkm_device *device = ibus->device;
	nvkm_mask(device, 0x122310, 0x0003ffff, 0x00000800);
	nvkm_wr32(device, 0x12232c, 0x00100064);
	nvkm_wr32(device, 0x122330, 0x00100064);
	nvkm_wr32(device, 0x122334, 0x00100064);
	nvkm_mask(device, 0x122348, 0x0003ffff, 0x00000100);
	return 0;
}

int
gf100_ibus_new(struct nvkm_device *device, int index,
	       struct nvkm_subdev **pibus)
{
	struct nvkm_subdev *ibus;
	if (!(ibus = *pibus = kzalloc(sizeof(*ibus), GFP_KERNEL)))
		return -ENOMEM;
	nvkm_subdev_ctor(&gf100_ibus, device, index, ibus);
	return 0;
}


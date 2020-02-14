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
typedef  int u64 ;
typedef  int u32 ;
struct nvkm_ram {int size; int stolen; int /*<<< orphan*/  vram; TYPE_2__* fb; } ;
struct TYPE_6__ {struct nvkm_device* device; } ;
struct nvkm_fb {TYPE_3__ subdev; } ;
struct nvkm_device {int dummy; } ;
struct mcp77_ram {int poller_base; struct nvkm_ram base; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  NVKM_RAM_MM_NORMAL ; 
 int NVKM_RAM_MM_SHIFT ; 
 int /*<<< orphan*/  NVKM_RAM_TYPE_STOLEN ; 
 struct mcp77_ram* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct mcp77_ram* mcp77_ram (struct nvkm_ram*) ; 
 int /*<<< orphan*/  mcp77_ram_func ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_mm_fini (int /*<<< orphan*/ *) ; 
 int nvkm_mm_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int) ; 
 int nvkm_ram_ctor (int /*<<< orphan*/ *,struct nvkm_fb*,int /*<<< orphan*/ ,int,struct nvkm_ram*) ; 
 scalar_t__ nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static int
mcp77_ram_init(struct nvkm_ram *base)
{
	struct mcp77_ram *ram = mcp77_ram(base);
	struct nvkm_device *device = ram->base.fb->subdev.device;
	u32 dniso  = ((ram->base.size - (ram->poller_base + 0x00)) >> 5) - 1;
	u32 hostnb = ((ram->base.size - (ram->poller_base + 0x20)) >> 5) - 1;
	u32 flush  = ((ram->base.size - (ram->poller_base + 0x40)) >> 5) - 1;

	/* Enable NISO poller for various clients and set their associated
	 * read address, only for MCP77/78 and MCP79/7A. (fd#27501)
	 */
	nvkm_wr32(device, 0x100c18, dniso);
	nvkm_mask(device, 0x100c14, 0x00000000, 0x00000001);
	nvkm_wr32(device, 0x100c1c, hostnb);
	nvkm_mask(device, 0x100c14, 0x00000000, 0x00000002);
	nvkm_wr32(device, 0x100c24, flush);
	nvkm_mask(device, 0x100c14, 0x00000000, 0x00010000);
	return 0;
}

int
mcp77_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
	struct nvkm_device *device = fb->subdev.device;
	u32 rsvd_head = ( 256 * 1024); /* vga memory */
	u32 rsvd_tail = (1024 * 1024) + 0x1000; /* vbios etc + poller mem */
	u64 base = (u64)nvkm_rd32(device, 0x100e10) << 12;
	u64 size = (u64)nvkm_rd32(device, 0x100e14) << 12;
	struct mcp77_ram *ram;
	int ret;

	if (!(ram = kzalloc(sizeof(*ram), GFP_KERNEL)))
		return -ENOMEM;
	*pram = &ram->base;

	ret = nvkm_ram_ctor(&mcp77_ram_func, fb, NVKM_RAM_TYPE_STOLEN,
			    size, &ram->base);
	if (ret)
		return ret;

	ram->poller_base = size - rsvd_tail;
	ram->base.stolen = base;
	nvkm_mm_fini(&ram->base.vram);

	return nvkm_mm_init(&ram->base.vram, NVKM_RAM_MM_NORMAL,
			    rsvd_head >> NVKM_RAM_MM_SHIFT,
			    (size - rsvd_head - rsvd_tail) >>
			    NVKM_RAM_MM_SHIFT, 1);
}


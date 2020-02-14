#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nvkm_fb_tile {int addr; int pitch; int zcomp; TYPE_5__* tag; scalar_t__ limit; } ;
struct TYPE_9__ {struct nvkm_device* device; } ;
struct nvkm_fb {TYPE_4__ subdev; int /*<<< orphan*/  tags; TYPE_3__* ram; TYPE_2__* func; } ;
struct nvkm_device {int chipset; } ;
struct TYPE_10__ {int offset; } ;
struct TYPE_8__ {int parts; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* comp ) (struct nvkm_fb*,int,int,int,struct nvkm_fb_tile*) ;} ;
struct TYPE_7__ {TYPE_1__ tile; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int clamp (int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ max (unsigned int,int) ; 
 int /*<<< orphan*/  nv30_fb ; 
 int nvkm_fb_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_fb**) ; 
 int /*<<< orphan*/  nvkm_mm_head (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int,TYPE_5__**) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 
 int round_up (int,int) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_fb*,int,int,int,struct nvkm_fb_tile*) ; 

void
nv30_fb_tile_init(struct nvkm_fb *fb, int i, u32 addr, u32 size, u32 pitch,
		  u32 flags, struct nvkm_fb_tile *tile)
{
	/* for performance, select alternate bank offset for zeta */
	if (!(flags & 4)) {
		tile->addr = (0 << 4);
	} else {
		if (fb->func->tile.comp) /* z compression */
			fb->func->tile.comp(fb, i, size, flags, tile);
		tile->addr = (1 << 4);
	}

	tile->addr |= 0x00000001; /* enable */
	tile->addr |= addr;
	tile->limit = max(1u, addr + size) - 1;
	tile->pitch = pitch;
}

__attribute__((used)) static void
nv30_fb_tile_comp(struct nvkm_fb *fb, int i, u32 size, u32 flags,
		  struct nvkm_fb_tile *tile)
{
	u32 tiles = DIV_ROUND_UP(size, 0x40);
	u32 tags  = round_up(tiles / fb->ram->parts, 0x40);
	if (!nvkm_mm_head(&fb->tags, 0, 1, tags, tags, 1, &tile->tag)) {
		if (flags & 2) tile->zcomp |= 0x01000000; /* Z16 */
		else           tile->zcomp |= 0x02000000; /* Z24S8 */
		tile->zcomp |= ((tile->tag->offset           ) >> 6);
		tile->zcomp |= ((tile->tag->offset + tags - 1) >> 6) << 12;
#ifdef __BIG_ENDIAN
		tile->zcomp |= 0x10000000;
#endif
	}
}

__attribute__((used)) static int
calc_bias(struct nvkm_fb *fb, int k, int i, int j)
{
	struct nvkm_device *device = fb->subdev.device;
	int b = (device->chipset > 0x30 ?
		 nvkm_rd32(device, 0x122c + 0x10 * k + 0x4 * j) >>
			(4 * (i ^ 1)) :
		 0) & 0xf;

	return 2 * (b & 0x8 ? b - 0x10 : b);
}

__attribute__((used)) static int
calc_ref(struct nvkm_fb *fb, int l, int k, int i)
{
	int j, x = 0;

	for (j = 0; j < 4; j++) {
		int m = (l >> (8 * i) & 0xff) + calc_bias(fb, k, i, j);

		x |= (0x80 | clamp(m, 0, 0x1f)) << (8 * j);
	}

	return x;
}

void
nv30_fb_init(struct nvkm_fb *fb)
{
	struct nvkm_device *device = fb->subdev.device;
	int i, j;

	/* Init the memory timing regs at 0x10037c/0x1003ac */
	if (device->chipset == 0x30 ||
	    device->chipset == 0x31 ||
	    device->chipset == 0x35) {
		/* Related to ROP count */
		int n = (device->chipset == 0x31 ? 2 : 4);
		int l = nvkm_rd32(device, 0x1003d0);

		for (i = 0; i < n; i++) {
			for (j = 0; j < 3; j++)
				nvkm_wr32(device, 0x10037c + 0xc * i + 0x4 * j,
					  calc_ref(fb, l, 0, j));

			for (j = 0; j < 2; j++)
				nvkm_wr32(device, 0x1003ac + 0x8 * i + 0x4 * j,
					  calc_ref(fb, l, 1, j));
		}
	}
}

int
nv30_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
	return nvkm_fb_new_(&nv30_fb, device, index, pfb);
}


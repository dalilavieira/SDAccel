#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nvkm_fb_tile {int addr; int limit; int pitch; int zcomp; TYPE_5__* tag; } ;
struct TYPE_10__ {struct nvkm_device* device; } ;
struct nvkm_fb {TYPE_4__ subdev; int /*<<< orphan*/  tags; TYPE_3__* ram; TYPE_2__* func; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_11__ {int offset; } ;
struct TYPE_9__ {int parts; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* comp ) (struct nvkm_fb*,int,int,int,struct nvkm_fb_tile*) ;} ;
struct TYPE_8__ {TYPE_1__ tile; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int max (unsigned int,int) ; 
 int /*<<< orphan*/  nv20_fb ; 
 int nvkm_fb_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_fb**) ; 
 int /*<<< orphan*/  nvkm_mm_free (int /*<<< orphan*/ *,TYPE_5__**) ; 
 int /*<<< orphan*/  nvkm_mm_head (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int,TYPE_5__**) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 
 int round_up (int,int) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_fb*,int,int,int,struct nvkm_fb_tile*) ; 

void
nv20_fb_tile_init(struct nvkm_fb *fb, int i, u32 addr, u32 size, u32 pitch,
		  u32 flags, struct nvkm_fb_tile *tile)
{
	tile->addr  = 0x00000001 | addr;
	tile->limit = max(1u, addr + size) - 1;
	tile->pitch = pitch;
	if (flags & 4) {
		fb->func->tile.comp(fb, i, size, flags, tile);
		tile->addr |= 2;
	}
}

__attribute__((used)) static void
nv20_fb_tile_comp(struct nvkm_fb *fb, int i, u32 size, u32 flags,
		  struct nvkm_fb_tile *tile)
{
	u32 tiles = DIV_ROUND_UP(size, 0x40);
	u32 tags  = round_up(tiles / fb->ram->parts, 0x40);
	if (!nvkm_mm_head(&fb->tags, 0, 1, tags, tags, 1, &tile->tag)) {
		if (!(flags & 2)) tile->zcomp = 0x00000000; /* Z16 */
		else              tile->zcomp = 0x04000000; /* Z24S8 */
		tile->zcomp |= tile->tag->offset;
		tile->zcomp |= 0x80000000; /* enable */
#ifdef __BIG_ENDIAN
		tile->zcomp |= 0x08000000;
#endif
	}
}

void
nv20_fb_tile_fini(struct nvkm_fb *fb, int i, struct nvkm_fb_tile *tile)
{
	tile->addr  = 0;
	tile->limit = 0;
	tile->pitch = 0;
	tile->zcomp = 0;
	nvkm_mm_free(&fb->tags, &tile->tag);
}

void
nv20_fb_tile_prog(struct nvkm_fb *fb, int i, struct nvkm_fb_tile *tile)
{
	struct nvkm_device *device = fb->subdev.device;
	nvkm_wr32(device, 0x100244 + (i * 0x10), tile->limit);
	nvkm_wr32(device, 0x100248 + (i * 0x10), tile->pitch);
	nvkm_wr32(device, 0x100240 + (i * 0x10), tile->addr);
	nvkm_rd32(device, 0x100240 + (i * 0x10));
	nvkm_wr32(device, 0x100300 + (i * 0x04), tile->zcomp);
}

u32
nv20_fb_tags(struct nvkm_fb *fb)
{
	const u32 tags = nvkm_rd32(fb->subdev.device, 0x100320);
	return tags ? tags + 1 : 0;
}

int
nv20_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
	return nvkm_fb_new_(&nv20_fb, device, index, pfb);
}


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
typedef  int u32 ;
struct nvkm_fb_tile {int zcomp; TYPE_3__* tag; } ;
struct TYPE_5__ {int /*<<< orphan*/  device; } ;
struct nvkm_fb {TYPE_2__ subdev; int /*<<< orphan*/  tags; TYPE_1__* ram; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_6__ {int offset; } ;
struct TYPE_4__ {int parts; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int /*<<< orphan*/  nv40_fb ; 
 int nvkm_fb_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_fb**) ; 
 int /*<<< orphan*/  nvkm_mask (int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  nvkm_mm_head (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int,TYPE_3__**) ; 
 int round_up (int,int) ; 

void
nv40_fb_tile_comp(struct nvkm_fb *fb, int i, u32 size, u32 flags,
		  struct nvkm_fb_tile *tile)
{
	u32 tiles = DIV_ROUND_UP(size, 0x80);
	u32 tags  = round_up(tiles / fb->ram->parts, 0x100);
	if ( (flags & 2) &&
	    !nvkm_mm_head(&fb->tags, 0, 1, tags, tags, 1, &tile->tag)) {
		tile->zcomp  = 0x28000000; /* Z24S8_SPLIT_GRAD */
		tile->zcomp |= ((tile->tag->offset           ) >> 8);
		tile->zcomp |= ((tile->tag->offset + tags - 1) >> 8) << 13;
#ifdef __BIG_ENDIAN
		tile->zcomp |= 0x40000000;
#endif
	}
}

__attribute__((used)) static void
nv40_fb_init(struct nvkm_fb *fb)
{
	nvkm_mask(fb->subdev.device, 0x10033c, 0x00008000, 0x00000000);
}

int
nv40_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
	return nvkm_fb_new_(&nv40_fb, device, index, pfb);
}


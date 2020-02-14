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
struct nvkm_gr {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_8__ {struct nvkm_device* device; } ;
struct TYPE_9__ {TYPE_3__ subdev; } ;
struct TYPE_10__ {TYPE_4__ engine; } ;
struct gf100_gr {TYPE_5__ base; TYPE_2__* zbc_depth; TYPE_1__* zbc_color; } ;
struct TYPE_7__ {int format; int ds; } ;
struct TYPE_6__ {int format; int* ds; } ;

/* Variables and functions */
 int TPC_UNIT (int,int,int) ; 
 int gm200_gr_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_gr**) ; 
 int /*<<< orphan*/  gp100_gr ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int const) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int const,int) ; 

void
gp100_gr_zbc_clear_color(struct gf100_gr *gr, int zbc)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	const int znum =  zbc - 1;
	const u32 zoff = znum * 4;

	if (gr->zbc_color[zbc].format) {
		nvkm_wr32(device, 0x418010 + zoff, gr->zbc_color[zbc].ds[0]);
		nvkm_wr32(device, 0x41804c + zoff, gr->zbc_color[zbc].ds[1]);
		nvkm_wr32(device, 0x418088 + zoff, gr->zbc_color[zbc].ds[2]);
		nvkm_wr32(device, 0x4180c4 + zoff, gr->zbc_color[zbc].ds[3]);
	}

	nvkm_mask(device, 0x418100 + ((znum / 4) * 4),
			  0x0000007f << ((znum % 4) * 7),
			  gr->zbc_color[zbc].format << ((znum % 4) * 7));
}

void
gp100_gr_zbc_clear_depth(struct gf100_gr *gr, int zbc)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	const int znum =  zbc - 1;
	const u32 zoff = znum * 4;

	if (gr->zbc_depth[zbc].format)
		nvkm_wr32(device, 0x418110 + zoff, gr->zbc_depth[zbc].ds);
	nvkm_mask(device, 0x41814c + ((znum / 4) * 4),
			  0x0000007f << ((znum % 4) * 7),
			  gr->zbc_depth[zbc].format << ((znum % 4) * 7));
}

void
gp100_gr_init_shader_exceptions(struct gf100_gr *gr, int gpc, int tpc)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x644), 0x00dffffe);
	nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x64c), 0x00000105);
}

__attribute__((used)) static void
gp100_gr_init_419c9c(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_mask(device, 0x419c9c, 0x00010000, 0x00010000);
	nvkm_mask(device, 0x419c9c, 0x00020000, 0x00020000);
}

void
gp100_gr_init_fecs_exceptions(struct gf100_gr *gr)
{
	nvkm_wr32(gr->base.engine.subdev.device, 0x409c24, 0x000f0002);
}

void
gp100_gr_init_rop_active_fbps(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	/*XXX: otherwise identical to gm200 aside from mask.. do everywhere? */
	const u32 fbp_count = nvkm_rd32(device, 0x12006c) & 0x0000000f;
	nvkm_mask(device, 0x408850, 0x0000000f, fbp_count); /* zrop */
	nvkm_mask(device, 0x408958, 0x0000000f, fbp_count); /* crop */
}

int
gp100_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
	return gm200_gr_new_(&gp100_gr, device, index, pgr);
}


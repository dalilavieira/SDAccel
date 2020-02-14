#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_3__ {struct nvkm_device* device; } ;
struct TYPE_4__ {TYPE_1__ subdev; } ;
struct nvkm_gr {TYPE_2__ engine; } ;
struct nvkm_device {int /*<<< orphan*/  secboot; } ;
struct gf100_gr_func {int dummy; } ;
struct gf100_gr {int gpc_nr; int tpc_total; int screen_tile_row_offset; int /*<<< orphan*/  fuc_method; int /*<<< orphan*/  fuc_bundle; int /*<<< orphan*/  fuc_sw_ctx; int /*<<< orphan*/  fuc_sw_nonctx; int /*<<< orphan*/  fuc41ad; int /*<<< orphan*/  fuc41ac; int /*<<< orphan*/  fuc409d; int /*<<< orphan*/  fuc409c; struct nvkm_gr base; int /*<<< orphan*/  tile; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPC_BCAST (int) ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_FECS ; 
 int /*<<< orphan*/  NVKM_SECBOOT_FALCON_GPCCS ; 
 int gf100_gr_ctor (struct gf100_gr_func const*,struct nvkm_device*,int,struct gf100_gr*) ; 
 int gf100_gr_ctor_fw (struct gf100_gr*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gf100_gr_oneinit_sm_id (struct gf100_gr*) ; 
 int /*<<< orphan*/  gf100_gr_oneinit_tiles (struct gf100_gr*) ; 
 int gk20a_gr_aiv_to_init (struct gf100_gr*,char*,int /*<<< orphan*/ *) ; 
 int gk20a_gr_av_to_init (struct gf100_gr*,char*,int /*<<< orphan*/ *) ; 
 int gk20a_gr_av_to_method (struct gf100_gr*,char*,int /*<<< orphan*/ *) ; 
 struct gf100_gr_func gm200_gr ; 
 int /*<<< orphan*/  gm200_gr_tile_map_2_8 ; 
 int /*<<< orphan*/  gm200_gr_tile_map_4_16 ; 
 int /*<<< orphan*/  gm200_gr_tile_map_6_24 ; 
 struct gf100_gr* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int const) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_secboot_is_managed (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

int
gm200_gr_rops(struct gf100_gr *gr)
{
	return nvkm_rd32(gr->base.engine.subdev.device, 0x12006c);
}

void
gm200_gr_init_ds_hww_esr_2(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_wr32(device, 0x405848, 0xc0000000);
	nvkm_mask(device, 0x40584c, 0x00000001, 0x00000001);
}

void
gm200_gr_init_num_active_ltcs(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_wr32(device, GPC_BCAST(0x08ac), nvkm_rd32(device, 0x100800));
	nvkm_wr32(device, GPC_BCAST(0x033c), nvkm_rd32(device, 0x100804));
}

void
gm200_gr_init_gpc_mmu(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;

	nvkm_wr32(device, 0x418880, nvkm_rd32(device, 0x100c80) & 0xf0001fff);
	nvkm_wr32(device, 0x418890, 0x00000000);
	nvkm_wr32(device, 0x418894, 0x00000000);

	nvkm_wr32(device, 0x4188b4, nvkm_rd32(device, 0x100cc8));
	nvkm_wr32(device, 0x4188b8, nvkm_rd32(device, 0x100ccc));
	nvkm_wr32(device, 0x4188b0, nvkm_rd32(device, 0x100cc4));
}

__attribute__((used)) static void
gm200_gr_init_rop_active_fbps(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	const u32 fbp_count = nvkm_rd32(device, 0x12006c);
	nvkm_mask(device, 0x408850, 0x0000000f, fbp_count); /* zrop */
	nvkm_mask(device, 0x408958, 0x0000000f, fbp_count); /* crop */
}

void
gm200_gr_oneinit_sm_id(struct gf100_gr *gr)
{
	/*XXX: There's a different algorithm here I've not yet figured out. */
	gf100_gr_oneinit_sm_id(gr);
}

void
gm200_gr_oneinit_tiles(struct gf100_gr *gr)
{
	/*XXX: Not sure what this is about.  The algorithm from NVGPU
	 *     seems to work for all boards I tried from earlier (and
	 *     later) GPUs except in these specific configurations.
	 *
	 *     Let's just hardcode them for now.
	 */
	if (gr->gpc_nr == 2 && gr->tpc_total == 8) {
		memcpy(gr->tile, gm200_gr_tile_map_2_8, gr->tpc_total);
		gr->screen_tile_row_offset = 1;
	} else
	if (gr->gpc_nr == 4 && gr->tpc_total == 16) {
		memcpy(gr->tile, gm200_gr_tile_map_4_16, gr->tpc_total);
		gr->screen_tile_row_offset = 4;
	} else
	if (gr->gpc_nr == 6 && gr->tpc_total == 24) {
		memcpy(gr->tile, gm200_gr_tile_map_6_24, gr->tpc_total);
		gr->screen_tile_row_offset = 5;
	} else {
		gf100_gr_oneinit_tiles(gr);
	}
}

int
gm200_gr_new_(const struct gf100_gr_func *func, struct nvkm_device *device,
	      int index, struct nvkm_gr **pgr)
{
	struct gf100_gr *gr;
	int ret;

	if (!(gr = kzalloc(sizeof(*gr), GFP_KERNEL)))
		return -ENOMEM;
	*pgr = &gr->base;

	ret = gf100_gr_ctor(func, device, index, gr);
	if (ret)
		return ret;

	/* Load firmwares for non-secure falcons */
	if (!nvkm_secboot_is_managed(device->secboot,
				     NVKM_SECBOOT_FALCON_FECS)) {
		if ((ret = gf100_gr_ctor_fw(gr, "gr/fecs_inst", &gr->fuc409c)) ||
		    (ret = gf100_gr_ctor_fw(gr, "gr/fecs_data", &gr->fuc409d)))
			return ret;
	}
	if (!nvkm_secboot_is_managed(device->secboot,
				     NVKM_SECBOOT_FALCON_GPCCS)) {
		if ((ret = gf100_gr_ctor_fw(gr, "gr/gpccs_inst", &gr->fuc41ac)) ||
		    (ret = gf100_gr_ctor_fw(gr, "gr/gpccs_data", &gr->fuc41ad)))
			return ret;
	}

	if ((ret = gk20a_gr_av_to_init(gr, "gr/sw_nonctx", &gr->fuc_sw_nonctx)) ||
	    (ret = gk20a_gr_aiv_to_init(gr, "gr/sw_ctx", &gr->fuc_sw_ctx)) ||
	    (ret = gk20a_gr_av_to_init(gr, "gr/sw_bundle_init", &gr->fuc_bundle)) ||
	    (ret = gk20a_gr_av_to_method(gr, "gr/sw_method_init", &gr->fuc_method)))
		return ret;

	return 0;
}

int
gm200_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
	return gm200_gr_new_(&gm200_gr, device, index, pgr);
}


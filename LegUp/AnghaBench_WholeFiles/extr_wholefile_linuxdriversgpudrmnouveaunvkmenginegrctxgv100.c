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
struct nvkm_device {int dummy; } ;
struct gf100_grctx_func {int alpha_nr; int attrib_nr; int gfxp_nr; int alpha_nr_max; } ;
struct gf100_grctx {struct gf100_gr* gr; } ;
struct TYPE_6__ {struct nvkm_device* device; } ;
struct TYPE_7__ {TYPE_2__ subdev; } ;
struct TYPE_8__ {TYPE_3__ engine; } ;
struct gf100_gr {int tpc_total; int gpc_nr; int* ppc_nr; int const** ppc_tpc_nr; int* ppc_mask; int screen_tile_row_offset; int* tile; TYPE_4__ base; TYPE_1__* func; } ;
struct TYPE_5__ {struct gf100_grctx_func* grctx; } ;

/* Variables and functions */
 int GPC_UNIT (int,int) ; 
 int PPC_UNIT (int,int,int /*<<< orphan*/ ) ; 
 int TPC_UNIT (int,int,int) ; 
 int /*<<< orphan*/  mmio_refn (struct gf100_grctx*,int,int,int const,int) ; 
 int mmio_vram (struct gf100_grctx*,int,int,int) ; 
 int /*<<< orphan*/  mmio_wr32 (struct gf100_grctx*,int const,int const) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int const,int const) ; 
 int /*<<< orphan*/  nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
gv100_grctx_generate_attrib(struct gf100_grctx *info)
{
	struct gf100_gr *gr = info->gr;
	const struct gf100_grctx_func *grctx = gr->func->grctx;
	const u32  alpha = grctx->alpha_nr;
	const u32 attrib = grctx->attrib_nr;
	const u32   gfxp = grctx->gfxp_nr;
	const int s = 12;
	const int max_batches = 0xffff;
	u32 size = grctx->alpha_nr_max * gr->tpc_total;
	u32 ao = 0;
	u32 bo = ao + size;
	int gpc, ppc, b, n = 0;

	size += grctx->gfxp_nr * gr->tpc_total;
	size = ((size * 0x20) + 128) & ~127;
	b = mmio_vram(info, size, (1 << s), false);

	mmio_refn(info, 0x418810, 0x80000000, s, b);
	mmio_refn(info, 0x419848, 0x10000000, s, b);
	mmio_refn(info, 0x419c2c, 0x10000000, s, b);
	mmio_refn(info, 0x419e00, 0x00000000, s, b);
	mmio_wr32(info, 0x419e04, 0x80000000 | size >> 7);
	mmio_wr32(info, 0x405830, attrib);
	mmio_wr32(info, 0x40585c, alpha);
	mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);

	for (gpc = 0; gpc < gr->gpc_nr; gpc++) {
		for (ppc = 0; ppc < gr->ppc_nr[gpc]; ppc++, n++) {
			const u32 as =  alpha * gr->ppc_tpc_nr[gpc][ppc];
			const u32 bs = attrib * gr->ppc_tpc_nr[gpc][ppc];
			const u32 gs =   gfxp * gr->ppc_tpc_nr[gpc][ppc];
			const u32 u = 0x418ea0 + (n * 0x04);
			const u32 o = PPC_UNIT(gpc, ppc, 0);
			if (!(gr->ppc_mask[gpc] & (1 << ppc)))
				continue;
			mmio_wr32(info, o + 0xc0, gs);
			mmio_wr32(info, o + 0xf4, bo);
			mmio_wr32(info, o + 0xf0, bs);
			bo += gs;
			mmio_wr32(info, o + 0xe4, as);
			mmio_wr32(info, o + 0xf8, ao);
			ao += grctx->alpha_nr_max * gr->ppc_tpc_nr[gpc][ppc];
			mmio_wr32(info, u, bs);
		}
	}

	mmio_wr32(info, 0x4181e4, 0x00000100);
	mmio_wr32(info, 0x41befc, 0x00000100);
}

__attribute__((used)) static void
gv100_grctx_generate_rop_mapping(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	u32 data;
	int i, j;

	/* Pack tile map into register format. */
	nvkm_wr32(device, 0x418bb8, (gr->tpc_total << 8) |
				     gr->screen_tile_row_offset);
	for (i = 0; i < 11; i++) {
		for (data = 0, j = 0; j < 6; j++)
			data |= (gr->tile[i * 6 + j] & 0x1f) << (j * 5);
		nvkm_wr32(device, 0x418b08 + (i * 4), data);
		nvkm_wr32(device, 0x41bf00 + (i * 4), data);
		nvkm_wr32(device, 0x40780c + (i * 4), data);
	}

	/* GPC_BROADCAST.TP_BROADCAST */
	nvkm_wr32(device, 0x41bfd0, (gr->tpc_total << 8) |
				     gr->screen_tile_row_offset);
	for (i = 0, j = 1; i < 5; i++, j += 4) {
		u8 v19 = (1 << (j + 0)) % gr->tpc_total;
		u8 v20 = (1 << (j + 1)) % gr->tpc_total;
		u8 v21 = (1 << (j + 2)) % gr->tpc_total;
		u8 v22 = (1 << (j + 3)) % gr->tpc_total;
		nvkm_wr32(device, 0x41bfb0 + (i * 4), (v22 << 24) |
						      (v21 << 16) |
						      (v20 <<  8) |
						       v19);
	}

	/* UNK78xx */
	nvkm_wr32(device, 0x4078bc, (gr->tpc_total << 8) |
				     gr->screen_tile_row_offset);
}

__attribute__((used)) static void
gv100_grctx_generate_r400088(struct gf100_gr *gr, bool on)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_mask(device, 0x400088, 0x00060000, on ? 0x00060000 : 0x00000000);
}

__attribute__((used)) static void
gv100_grctx_generate_sm_id(struct gf100_gr *gr, int gpc, int tpc, int sm)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x608), sm);
	nvkm_wr32(device, GPC_UNIT(gpc, 0x0c10 + tpc * 4), sm);
	nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x088), sm);
}

__attribute__((used)) static void
gv100_grctx_generate_unkn(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_mask(device, 0x41980c, 0x00000010, 0x00000010);
	nvkm_mask(device, 0x41be08, 0x00000004, 0x00000004);
	nvkm_mask(device, 0x4064c0, 0x80000000, 0x80000000);
	nvkm_mask(device, 0x405800, 0x08000000, 0x08000000);
	nvkm_mask(device, 0x419c00, 0x00000008, 0x00000008);
}

__attribute__((used)) static void
gv100_grctx_unkn88c(struct gf100_gr *gr, bool on)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	const u32 mask = 0x00000010, data = on ? mask : 0x00000000;
	nvkm_mask(device, 0x40988c, mask, data);
	nvkm_rd32(device, 0x40988c);
	nvkm_mask(device, 0x41a88c, mask, data);
	nvkm_rd32(device, 0x41a88c);
	nvkm_mask(device, 0x408a14, mask, data);
	nvkm_rd32(device, 0x408a14);
}


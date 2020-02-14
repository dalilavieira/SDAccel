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
typedef  int u32 ;
struct nvkm_device {int dummy; } ;
struct gf100_grctx_func {int bundle_size; int bundle_token_limit; int const pagepool_size; int alpha_nr; int attrib_nr; int attrib_nr_max; int alpha_nr_max; int /*<<< orphan*/  bundle_min_gpm_fifo_depth; } ;
struct gf100_grctx {struct gf100_gr* gr; } ;
struct TYPE_6__ {struct nvkm_device* device; } ;
struct TYPE_7__ {TYPE_2__ subdev; } ;
struct TYPE_8__ {TYPE_3__ engine; } ;
struct gf100_gr {int const tpc_total; int gpc_nr; int* ppc_nr; int const** ppc_tpc_nr; int* ppc_mask; TYPE_4__ base; TYPE_1__* func; } ;
struct TYPE_5__ {struct gf100_grctx_func* grctx; } ;

/* Variables and functions */
 int GPC_UNIT (int,int) ; 
 int PPC_UNIT (int,int,int /*<<< orphan*/ ) ; 
 int TPC_UNIT (int,int,int) ; 
 int min (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mmio_refn (struct gf100_grctx*,int,int,int const,int const) ; 
 int mmio_vram (struct gf100_grctx*,int const,int,int) ; 
 int /*<<< orphan*/  mmio_wr32 (struct gf100_grctx*,int const,int const) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
gm107_grctx_generate_r419e00(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_mask(device, 0x419e00, 0x00808080, 0x00808080);
	nvkm_mask(device, 0x419ccc, 0x80000000, 0x80000000);
	nvkm_mask(device, 0x419f80, 0x80000000, 0x80000000);
	nvkm_mask(device, 0x419f88, 0x80000000, 0x80000000);
}

void
gm107_grctx_generate_bundle(struct gf100_grctx *info)
{
	const struct gf100_grctx_func *grctx = info->gr->func->grctx;
	const u32 state_limit = min(grctx->bundle_min_gpm_fifo_depth,
				    grctx->bundle_size / 0x20);
	const u32 token_limit = grctx->bundle_token_limit;
	const int s = 8;
	const int b = mmio_vram(info, grctx->bundle_size, (1 << s), true);
	mmio_refn(info, 0x408004, 0x00000000, s, b);
	mmio_wr32(info, 0x408008, 0x80000000 | (grctx->bundle_size >> s));
	mmio_refn(info, 0x418e24, 0x00000000, s, b);
	mmio_wr32(info, 0x418e28, 0x80000000 | (grctx->bundle_size >> s));
	mmio_wr32(info, 0x4064c8, (state_limit << 16) | token_limit);
}

void
gm107_grctx_generate_pagepool(struct gf100_grctx *info)
{
	const struct gf100_grctx_func *grctx = info->gr->func->grctx;
	const int s = 8;
	const int b = mmio_vram(info, grctx->pagepool_size, (1 << s), true);
	mmio_refn(info, 0x40800c, 0x00000000, s, b);
	mmio_wr32(info, 0x408010, 0x80000000);
	mmio_refn(info, 0x419004, 0x00000000, s, b);
	mmio_wr32(info, 0x419008, 0x00000000);
	mmio_wr32(info, 0x4064cc, 0x80000000);
	mmio_wr32(info, 0x418e30, 0x80000000); /* guess at it being related */
}

void
gm107_grctx_generate_attrib(struct gf100_grctx *info)
{
	struct gf100_gr *gr = info->gr;
	const struct gf100_grctx_func *grctx = gr->func->grctx;
	const u32  alpha = grctx->alpha_nr;
	const u32 attrib = grctx->attrib_nr;
	const u32   size = 0x20 * (grctx->attrib_nr_max + grctx->alpha_nr_max);
	const int s = 12;
	const int b = mmio_vram(info, size * gr->tpc_total, (1 << s), false);
	const int max_batches = 0xffff;
	u32 bo = 0;
	u32 ao = bo + grctx->attrib_nr_max * gr->tpc_total;
	int gpc, ppc, n = 0;

	mmio_refn(info, 0x418810, 0x80000000, s, b);
	mmio_refn(info, 0x419848, 0x10000000, s, b);
	mmio_refn(info, 0x419c2c, 0x10000000, s, b);
	mmio_wr32(info, 0x405830, (attrib << 16) | alpha);
	mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);

	for (gpc = 0; gpc < gr->gpc_nr; gpc++) {
		for (ppc = 0; ppc < gr->ppc_nr[gpc]; ppc++, n++) {
			const u32 as =  alpha * gr->ppc_tpc_nr[gpc][ppc];
			const u32 bs = attrib * gr->ppc_tpc_nr[gpc][ppc];
			const u32 u = 0x418ea0 + (n * 0x04);
			const u32 o = PPC_UNIT(gpc, ppc, 0);
			if (!(gr->ppc_mask[gpc] & (1 << ppc)))
				continue;
			mmio_wr32(info, o + 0xc0, bs);
			mmio_wr32(info, o + 0xf4, bo);
			bo += grctx->attrib_nr_max * gr->ppc_tpc_nr[gpc][ppc];
			mmio_wr32(info, o + 0xe4, as);
			mmio_wr32(info, o + 0xf8, ao);
			ao += grctx->alpha_nr_max * gr->ppc_tpc_nr[gpc][ppc];
			mmio_wr32(info, u, ((bs / 3) << 16) | bs);
		}
	}
}

__attribute__((used)) static void
gm107_grctx_generate_r406500(struct gf100_gr *gr)
{
	nvkm_wr32(gr->base.engine.subdev.device, 0x406500, 0x00000001);
}

void
gm107_grctx_generate_sm_id(struct gf100_gr *gr, int gpc, int tpc, int sm)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x698), sm);
	nvkm_wr32(device, GPC_UNIT(gpc, 0x0c10 + tpc * 4), sm);
	nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x088), sm);
}


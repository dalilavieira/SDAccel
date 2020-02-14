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
struct gf100_grctx_func {int alpha_nr; int attrib_nr; int attrib_nr_max; int alpha_nr_max; } ;
struct gf100_grctx {struct gf100_gr* gr; } ;
struct TYPE_6__ {struct nvkm_device* device; } ;
struct TYPE_7__ {TYPE_2__ subdev; } ;
struct TYPE_8__ {TYPE_3__ engine; } ;
struct gf100_gr {int const tpc_total; int gpc_nr; int* tpc_nr; TYPE_4__ base; TYPE_1__* func; } ;
struct TYPE_5__ {struct gf100_grctx_func* grctx; } ;

/* Variables and functions */
 int TPC_UNIT (int,int,int) ; 
 int /*<<< orphan*/  mmio_refn (struct gf100_grctx*,int,int,int const,int const) ; 
 int /*<<< orphan*/  mmio_skip (struct gf100_grctx*,int const,int const) ; 
 int mmio_vram (struct gf100_grctx*,int const,int,int) ; 
 int /*<<< orphan*/  mmio_wr32 (struct gf100_grctx*,int const,int const) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 

void
gf108_grctx_generate_attrib(struct gf100_grctx *info)
{
	struct gf100_gr *gr = info->gr;
	const struct gf100_grctx_func *grctx = gr->func->grctx;
	const u32  alpha = grctx->alpha_nr;
	const u32   beta = grctx->attrib_nr;
	const u32   size = 0x20 * (grctx->attrib_nr_max + grctx->alpha_nr_max);
	const int s = 12;
	const int b = mmio_vram(info, size * gr->tpc_total, (1 << s), false);
	const int timeslice_mode = 1;
	const int max_batches = 0xffff;
	u32 bo = 0;
	u32 ao = bo + grctx->attrib_nr_max * gr->tpc_total;
	int gpc, tpc;

	mmio_refn(info, 0x418810, 0x80000000, s, b);
	mmio_refn(info, 0x419848, 0x10000000, s, b);
	mmio_wr32(info, 0x405830, (beta << 16) | alpha);
	mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);

	for (gpc = 0; gpc < gr->gpc_nr; gpc++) {
		for (tpc = 0; tpc < gr->tpc_nr[gpc]; tpc++) {
			const u32 a = alpha;
			const u32 b =  beta;
			const u32 t = timeslice_mode;
			const u32 o = TPC_UNIT(gpc, tpc, 0x500);
			mmio_skip(info, o + 0x20, (t << 28) | (b << 16) | ++bo);
			mmio_wr32(info, o + 0x20, (t << 28) | (b << 16) | --bo);
			bo += grctx->attrib_nr_max;
			mmio_wr32(info, o + 0x44, (a << 16) | ao);
			ao += grctx->alpha_nr_max;
		}
	}
}

void
gf108_grctx_generate_unkn(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_mask(device, 0x418c6c, 0x00000001, 0x00000001);
	nvkm_mask(device, 0x41980c, 0x00000010, 0x00000010);
	nvkm_mask(device, 0x419814, 0x00000004, 0x00000004);
	nvkm_mask(device, 0x4064c0, 0x80000000, 0x80000000);
	nvkm_mask(device, 0x405800, 0x08000000, 0x08000000);
	nvkm_mask(device, 0x419c00, 0x00000008, 0x00000008);
}


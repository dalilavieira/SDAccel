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
struct nvkm_pll_vals {int N1; int M1; int N2; int M2; int log2P; int /*<<< orphan*/  refclk; } ;
struct nvkm_devinit {int dummy; } ;
struct nvkm_device {TYPE_2__* bios; struct nvkm_devinit* devinit; } ;
struct TYPE_6__ {struct nvkm_device* device; } ;
struct nvkm_clk {int (* pll_calc ) (struct nvkm_clk*,struct nvbios_pll*,int,struct nvkm_pll_vals*) ;int (* pll_prog ) (struct nvkm_clk*,int,struct nvkm_pll_vals*) ;TYPE_3__ subdev; } ;
struct nvbios_pll {int /*<<< orphan*/  refclk; } ;
struct TYPE_4__ {int chip; } ;
struct TYPE_5__ {TYPE_1__ version; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv04_clk ; 
 int nv04_pll_calc (TYPE_3__*,struct nvbios_pll*,int,int*,int*,int*,int*,int*) ; 
 int nvkm_clk_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,int,struct nvkm_clk**) ; 
 int /*<<< orphan*/  setPLL_double_highregs (struct nvkm_devinit*,int,struct nvkm_pll_vals*) ; 
 int /*<<< orphan*/  setPLL_double_lowregs (struct nvkm_devinit*,int,struct nvkm_pll_vals*) ; 
 int /*<<< orphan*/  setPLL_single (struct nvkm_devinit*,int,struct nvkm_pll_vals*) ; 

int
nv04_clk_pll_calc(struct nvkm_clk *clock, struct nvbios_pll *info,
		  int clk, struct nvkm_pll_vals *pv)
{
	int N1, M1, N2, M2, P;
	int ret = nv04_pll_calc(&clock->subdev, info, clk, &N1, &M1, &N2, &M2, &P);
	if (ret) {
		pv->refclk = info->refclk;
		pv->N1 = N1;
		pv->M1 = M1;
		pv->N2 = N2;
		pv->M2 = M2;
		pv->log2P = P;
	}
	return ret;
}

int
nv04_clk_pll_prog(struct nvkm_clk *clk, u32 reg1, struct nvkm_pll_vals *pv)
{
	struct nvkm_device *device = clk->subdev.device;
	struct nvkm_devinit *devinit = device->devinit;
	int cv = device->bios->version.chip;

	if (cv == 0x30 || cv == 0x31 || cv == 0x35 || cv == 0x36 ||
	    cv >= 0x40) {
		if (reg1 > 0x405c)
			setPLL_double_highregs(devinit, reg1, pv);
		else
			setPLL_double_lowregs(devinit, reg1, pv);
	} else
		setPLL_single(devinit, reg1, pv);

	return 0;
}

int
nv04_clk_new(struct nvkm_device *device, int index, struct nvkm_clk **pclk)
{
	int ret = nvkm_clk_new_(&nv04_clk, device, index, false, pclk);
	if (ret == 0) {
		(*pclk)->pll_calc = nv04_clk_pll_calc;
		(*pclk)->pll_prog = nv04_clk_pll_prog;
	}
	return ret;
}


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
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_device {int crystal; int /*<<< orphan*/  bios; } ;
struct nvkm_cstate {int* domain; } ;
struct nvkm_clk {int /*<<< orphan*/  pll_prog; int /*<<< orphan*/  pll_calc; struct nvkm_subdev subdev; } ;
struct TYPE_4__ {scalar_t__ max_freq; } ;
struct TYPE_3__ {int max_freq; } ;
struct nvbios_pll {TYPE_2__ vco2; TYPE_1__ vco1; } ;
struct nv40_clk {int npll_ctrl; int npll_coef; int spll; int ctrl; struct nvkm_clk base; } ;
typedef  enum nv_clk_src { ____Placeholder_nv_clk_src } nv_clk_src ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nv40_clk* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  nv04_clk_pll_calc ; 
 int /*<<< orphan*/  nv04_clk_pll_prog ; 
 int nv04_pll_calc (struct nvkm_subdev*,struct nvbios_pll*,int,int*,int*,int*,int*,int*) ; 
 struct nv40_clk* nv40_clk (struct nvkm_clk*) ; 
#define  nv_clk_src_core 132 
#define  nv_clk_src_crystal 131 
#define  nv_clk_src_href 130 
#define  nv_clk_src_mem 129 
#define  nv_clk_src_shader 128 
 int nvbios_pll_parse (int /*<<< orphan*/ ,int,struct nvbios_pll*) ; 
 int nvkm_clk_ctor (struct nv40_clk* (*) (struct nvkm_clk*),struct nvkm_device*,int,int,struct nvkm_clk*) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*,int,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static u32
read_pll_1(struct nv40_clk *clk, u32 reg)
{
	struct nvkm_device *device = clk->base.subdev.device;
	u32 ctrl = nvkm_rd32(device, reg + 0x00);
	int P = (ctrl & 0x00070000) >> 16;
	int N = (ctrl & 0x0000ff00) >> 8;
	int M = (ctrl & 0x000000ff) >> 0;
	u32 ref = 27000, khz = 0;

	if (ctrl & 0x80000000)
		khz = ref * N / M;

	return khz >> P;
}

__attribute__((used)) static u32
read_pll_2(struct nv40_clk *clk, u32 reg)
{
	struct nvkm_device *device = clk->base.subdev.device;
	u32 ctrl = nvkm_rd32(device, reg + 0x00);
	u32 coef = nvkm_rd32(device, reg + 0x04);
	int N2 = (coef & 0xff000000) >> 24;
	int M2 = (coef & 0x00ff0000) >> 16;
	int N1 = (coef & 0x0000ff00) >> 8;
	int M1 = (coef & 0x000000ff) >> 0;
	int P = (ctrl & 0x00070000) >> 16;
	u32 ref = 27000, khz = 0;

	if ((ctrl & 0x80000000) && M1) {
		khz = ref * N1 / M1;
		if ((ctrl & 0x40000100) == 0x40000000) {
			if (M2)
				khz = khz * N2 / M2;
			else
				khz = 0;
		}
	}

	return khz >> P;
}

__attribute__((used)) static u32
read_clk(struct nv40_clk *clk, u32 src)
{
	switch (src) {
	case 3:
		return read_pll_2(clk, 0x004000);
	case 2:
		return read_pll_1(clk, 0x004008);
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int
nv40_clk_read(struct nvkm_clk *base, enum nv_clk_src src)
{
	struct nv40_clk *clk = nv40_clk(base);
	struct nvkm_subdev *subdev = &clk->base.subdev;
	struct nvkm_device *device = subdev->device;
	u32 mast = nvkm_rd32(device, 0x00c040);

	switch (src) {
	case nv_clk_src_crystal:
		return device->crystal;
	case nv_clk_src_href:
		return 100000; /*XXX: PCIE/AGP differ*/
	case nv_clk_src_core:
		return read_clk(clk, (mast & 0x00000003) >> 0);
	case nv_clk_src_shader:
		return read_clk(clk, (mast & 0x00000030) >> 4);
	case nv_clk_src_mem:
		return read_pll_2(clk, 0x4020);
	default:
		break;
	}

	nvkm_debug(subdev, "unknown clock source %d %08x\n", src, mast);
	return -EINVAL;
}

__attribute__((used)) static int
nv40_clk_calc_pll(struct nv40_clk *clk, u32 reg, u32 khz,
		  int *N1, int *M1, int *N2, int *M2, int *log2P)
{
	struct nvkm_subdev *subdev = &clk->base.subdev;
	struct nvbios_pll pll;
	int ret;

	ret = nvbios_pll_parse(subdev->device->bios, reg, &pll);
	if (ret)
		return ret;

	if (khz < pll.vco1.max_freq)
		pll.vco2.max_freq = 0;

	ret = nv04_pll_calc(subdev, &pll, khz, N1, M1, N2, M2, log2P);
	if (ret == 0)
		return -ERANGE;

	return ret;
}

__attribute__((used)) static int
nv40_clk_calc(struct nvkm_clk *base, struct nvkm_cstate *cstate)
{
	struct nv40_clk *clk = nv40_clk(base);
	int gclk = cstate->domain[nv_clk_src_core];
	int sclk = cstate->domain[nv_clk_src_shader];
	int N1, M1, N2, M2, log2P;
	int ret;

	/* core/geometric clock */
	ret = nv40_clk_calc_pll(clk, 0x004000, gclk,
				&N1, &M1, &N2, &M2, &log2P);
	if (ret < 0)
		return ret;

	if (N2 == M2) {
		clk->npll_ctrl = 0x80000100 | (log2P << 16);
		clk->npll_coef = (N1 << 8) | M1;
	} else {
		clk->npll_ctrl = 0xc0000000 | (log2P << 16);
		clk->npll_coef = (N2 << 24) | (M2 << 16) | (N1 << 8) | M1;
	}

	/* use the second pll for shader/rop clock, if it differs from core */
	if (sclk && sclk != gclk) {
		ret = nv40_clk_calc_pll(clk, 0x004008, sclk,
					&N1, &M1, NULL, NULL, &log2P);
		if (ret < 0)
			return ret;

		clk->spll = 0xc0000000 | (log2P << 16) | (N1 << 8) | M1;
		clk->ctrl = 0x00000223;
	} else {
		clk->spll = 0x00000000;
		clk->ctrl = 0x00000333;
	}

	return 0;
}

__attribute__((used)) static int
nv40_clk_prog(struct nvkm_clk *base)
{
	struct nv40_clk *clk = nv40_clk(base);
	struct nvkm_device *device = clk->base.subdev.device;
	nvkm_mask(device, 0x00c040, 0x00000333, 0x00000000);
	nvkm_wr32(device, 0x004004, clk->npll_coef);
	nvkm_mask(device, 0x004000, 0xc0070100, clk->npll_ctrl);
	nvkm_mask(device, 0x004008, 0xc007ffff, clk->spll);
	mdelay(5);
	nvkm_mask(device, 0x00c040, 0x00000333, clk->ctrl);
	return 0;
}

__attribute__((used)) static void
nv40_clk_tidy(struct nvkm_clk *obj)
{
}

int
nv40_clk_new(struct nvkm_device *device, int index, struct nvkm_clk **pclk)
{
	struct nv40_clk *clk;

	if (!(clk = kzalloc(sizeof(*clk), GFP_KERNEL)))
		return -ENOMEM;
	clk->base.pll_calc = nv04_clk_pll_calc;
	clk->base.pll_prog = nv04_clk_pll_prog;
	*pclk = &clk->base;

	return nvkm_clk_ctor(&nv40_clk, device, index, true, &clk->base);
}


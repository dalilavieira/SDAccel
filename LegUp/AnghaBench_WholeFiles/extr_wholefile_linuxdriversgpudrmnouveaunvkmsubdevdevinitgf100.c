#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long long u64 ;
typedef  int u32 ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_devinit {int post; struct nvkm_subdev subdev; } ;
struct nvkm_device {int /*<<< orphan*/  bios; } ;
struct nvbios_pll {int type; int /*<<< orphan*/  reg; } ;
struct TYPE_2__ {struct nvkm_subdev subdev; } ;
struct nv50_devinit {TYPE_1__ base; } ;

/* Variables and functions */
 int BIT (int) ; 
 int EINVAL ; 
 unsigned long long NVKM_ENGINE_CE0 ; 
 unsigned long long NVKM_ENGINE_CE1 ; 
 unsigned long long NVKM_ENGINE_DISP ; 
 unsigned long long NVKM_ENGINE_MSENC ; 
 unsigned long long NVKM_ENGINE_MSPDEC ; 
 unsigned long long NVKM_ENGINE_MSPPP ; 
 unsigned long long NVKM_ENGINE_MSVLD ; 
#define  PLL_VPLL0 131 
#define  PLL_VPLL1 130 
#define  PLL_VPLL2 129 
#define  PLL_VPLL3 128 
 int /*<<< orphan*/  gf100_devinit ; 
 int gt215_pll_calc (struct nvkm_subdev*,struct nvbios_pll*,int,int*,int*,int*,int*) ; 
 struct nv50_devinit* nv50_devinit (struct nvkm_devinit*) ; 
 int nv50_devinit_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_devinit**) ; 
 int nvbios_pll_parse (int /*<<< orphan*/ ,int,struct nvbios_pll*) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int /*<<< orphan*/ ,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int /*<<< orphan*/ ,int) ; 

int
gf100_devinit_pll_set(struct nvkm_devinit *init, u32 type, u32 freq)
{
	struct nvkm_subdev *subdev = &init->subdev;
	struct nvkm_device *device = subdev->device;
	struct nvbios_pll info;
	int N, fN, M, P;
	int ret;

	ret = nvbios_pll_parse(device->bios, type, &info);
	if (ret)
		return ret;

	ret = gt215_pll_calc(subdev, &info, freq, &N, &fN, &M, &P);
	if (ret < 0)
		return ret;

	switch (info.type) {
	case PLL_VPLL0:
	case PLL_VPLL1:
	case PLL_VPLL2:
	case PLL_VPLL3:
		nvkm_mask(device, info.reg + 0x0c, 0x00000000, 0x00000100);
		nvkm_wr32(device, info.reg + 0x04, (P << 16) | (N << 8) | M);
		nvkm_wr32(device, info.reg + 0x10, fN << 16);
		break;
	default:
		nvkm_warn(subdev, "%08x/%dKhz unimplemented\n", type, freq);
		ret = -EINVAL;
		break;
	}

	return ret;
}

__attribute__((used)) static u64
gf100_devinit_disable(struct nvkm_devinit *init)
{
	struct nvkm_device *device = init->subdev.device;
	u32 r022500 = nvkm_rd32(device, 0x022500);
	u64 disable = 0ULL;

	if (r022500 & 0x00000001)
		disable |= (1ULL << NVKM_ENGINE_DISP);

	if (r022500 & 0x00000002) {
		disable |= (1ULL << NVKM_ENGINE_MSPDEC);
		disable |= (1ULL << NVKM_ENGINE_MSPPP);
	}

	if (r022500 & 0x00000004)
		disable |= (1ULL << NVKM_ENGINE_MSVLD);
	if (r022500 & 0x00000008)
		disable |= (1ULL << NVKM_ENGINE_MSENC);
	if (r022500 & 0x00000100)
		disable |= (1ULL << NVKM_ENGINE_CE0);
	if (r022500 & 0x00000200)
		disable |= (1ULL << NVKM_ENGINE_CE1);

	return disable;
}

void
gf100_devinit_preinit(struct nvkm_devinit *base)
{
	struct nv50_devinit *init = nv50_devinit(base);
	struct nvkm_subdev *subdev = &init->base.subdev;
	struct nvkm_device *device = subdev->device;

	/*
	 * This bit is set by devinit, and flips back to 0 on suspend. We
	 * can use it as a reliable way to know whether we should run devinit.
	 */
	base->post = ((nvkm_rd32(device, 0x2240c) & BIT(1)) == 0);
}

int
gf100_devinit_new(struct nvkm_device *device, int index,
		struct nvkm_devinit **pinit)
{
	return nv50_devinit_new_(&gf100_devinit, device, index, pinit);
}


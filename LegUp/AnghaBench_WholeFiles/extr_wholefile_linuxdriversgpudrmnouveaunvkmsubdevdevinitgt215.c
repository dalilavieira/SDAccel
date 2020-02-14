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
typedef  unsigned long long u64 ;
typedef  int u32 ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_devinit {struct nvkm_subdev subdev; } ;
struct nvkm_device {int /*<<< orphan*/  bios; } ;
struct nvbios_pll {int type; scalar_t__ reg; } ;
struct TYPE_3__ {struct nvkm_device* device; } ;
struct TYPE_4__ {TYPE_1__ subdev; } ;
struct nv50_devinit {int r001540; TYPE_2__ base; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned long long NVKM_ENGINE_CE0 ; 
 unsigned long long NVKM_ENGINE_DISP ; 
 unsigned long long NVKM_ENGINE_MSPDEC ; 
 unsigned long long NVKM_ENGINE_MSPPP ; 
 unsigned long long NVKM_ENGINE_MSVLD ; 
#define  PLL_VPLL0 129 
#define  PLL_VPLL1 128 
 int /*<<< orphan*/  gt215_devinit ; 
 int* gt215_devinit_mmio_part ; 
 int gt215_pll_calc (struct nvkm_subdev*,struct nvbios_pll*,int,int*,int*,int*,int*) ; 
 int hweight8 (int) ; 
 struct nv50_devinit* nv50_devinit (struct nvkm_devinit*) ; 
 int nv50_devinit_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_devinit**) ; 
 int nvbios_pll_parse (int /*<<< orphan*/ ,int,struct nvbios_pll*) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int /*<<< orphan*/ ,int,int) ; 
 void* nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,scalar_t__,int) ; 

int
gt215_devinit_pll_set(struct nvkm_devinit *init, u32 type, u32 freq)
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
		nvkm_wr32(device, info.reg + 0, 0x50000610);
		nvkm_mask(device, info.reg + 4, 0x003fffff,
						(P << 16) | (M << 8) | N);
		nvkm_wr32(device, info.reg + 8, fN);
		break;
	default:
		nvkm_warn(subdev, "%08x/%dKhz unimplemented\n", type, freq);
		ret = -EINVAL;
		break;
	}

	return ret;
}

__attribute__((used)) static u64
gt215_devinit_disable(struct nvkm_devinit *init)
{
	struct nvkm_device *device = init->subdev.device;
	u32 r001540 = nvkm_rd32(device, 0x001540);
	u32 r00154c = nvkm_rd32(device, 0x00154c);
	u64 disable = 0ULL;

	if (!(r001540 & 0x40000000)) {
		disable |= (1ULL << NVKM_ENGINE_MSPDEC);
		disable |= (1ULL << NVKM_ENGINE_MSPPP);
	}

	if (!(r00154c & 0x00000004))
		disable |= (1ULL << NVKM_ENGINE_DISP);
	if (!(r00154c & 0x00000020))
		disable |= (1ULL << NVKM_ENGINE_MSVLD);
	if (!(r00154c & 0x00000200))
		disable |= (1ULL << NVKM_ENGINE_CE0);

	return disable;
}

__attribute__((used)) static u32
gt215_devinit_mmio(struct nvkm_devinit *base, u32 addr)
{
	struct nv50_devinit *init = nv50_devinit(base);
	struct nvkm_device *device = init->base.subdev.device;
	u32 *mmio = gt215_devinit_mmio_part;

	/* the init tables on some boards have INIT_RAM_RESTRICT_ZM_REG_GROUP
	 * instructions which touch registers that may not even exist on
	 * some configurations (Quadro 400), which causes the register
	 * interface to screw up for some amount of time after attempting to
	 * write to one of these, and results in all sorts of things going
	 * horribly wrong.
	 *
	 * the binary driver avoids touching these registers at all, however,
	 * the video bios doesn't care and does what the scripts say.  it's
	 * presumed that the io-port access to init registers isn't effected
	 * by the screw-up bug mentioned above.
	 *
	 * really, a new opcode should've been invented to handle these
	 * requirements, but whatever, it's too late for that now.
	 */
	while (mmio[0]) {
		if (addr >= mmio[0] && addr <= mmio[1]) {
			u32 part = (addr / mmio[2]) & 7;
			if (!init->r001540)
				init->r001540 = nvkm_rd32(device, 0x001540);
			if (part >= hweight8((init->r001540 >> 16) & 0xff))
				return ~0;
			return addr;
		}
		mmio += 3;
	}

	return addr;
}

int
gt215_devinit_new(struct nvkm_device *device, int index,
		struct nvkm_devinit **pinit)
{
	return nv50_devinit_new_(&gt215_devinit, device, index, pinit);
}


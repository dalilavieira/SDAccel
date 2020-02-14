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
struct TYPE_8__ {int link; } ;
struct nvkm_ior {int id; TYPE_4__ asy; TYPE_3__* disp; } ;
struct nvkm_disp {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct TYPE_6__ {TYPE_1__ subdev; } ;
struct TYPE_7__ {TYPE_2__ engine; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOR ; 
 int /*<<< orphan*/  gm107_sor ; 
 int nvkm_ior_new_ (int /*<<< orphan*/ *,struct nvkm_disp*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int const,int,int const) ; 

__attribute__((used)) static inline u32
nv50_ior_base(struct nvkm_ior *ior)
{
	return ior->id * 0x800;
}

__attribute__((used)) static inline u32
nv50_sor_link(struct nvkm_ior *ior)
{
	return nv50_ior_base(ior) + ((ior->asy.link == 2) * 0x80);
}

void
gm107_sor_dp_pattern(struct nvkm_ior *sor, int pattern)
{
	struct nvkm_device *device = sor->disp->engine.subdev.device;
	const u32 soff = nv50_ior_base(sor);
	const u32 data = 0x01010101 * pattern;
	if (sor->asy.link & 1)
		nvkm_mask(device, 0x61c110 + soff, 0x0f0f0f0f, data);
	else
		nvkm_mask(device, 0x61c12c + soff, 0x0f0f0f0f, data);
}

int
gm107_sor_new(struct nvkm_disp *disp, int id)
{
	return nvkm_ior_new_(&gm107_sor, disp, SOR, id);
}


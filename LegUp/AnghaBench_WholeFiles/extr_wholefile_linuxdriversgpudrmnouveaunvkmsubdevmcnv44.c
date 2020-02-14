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
typedef  int u32 ;
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_mc {TYPE_1__ subdev; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv44_mc ; 
 int nvkm_mc_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_mc**) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

void
nv44_mc_init(struct nvkm_mc *mc)
{
	struct nvkm_device *device = mc->subdev.device;
	u32 tmp = nvkm_rd32(device, 0x10020c);

	nvkm_wr32(device, 0x000200, 0xffffffff); /* everything enabled */

	nvkm_wr32(device, 0x001700, tmp);
	nvkm_wr32(device, 0x001704, 0);
	nvkm_wr32(device, 0x001708, 0);
	nvkm_wr32(device, 0x00170c, tmp);
}

int
nv44_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
	return nvkm_mc_new_(&nv44_mc, device, index, pmc);
}


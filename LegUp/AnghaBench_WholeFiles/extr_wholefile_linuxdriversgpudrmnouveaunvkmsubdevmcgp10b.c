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
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_mc {TYPE_1__ subdev; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int gp100_mc_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_mc**) ; 
 int /*<<< orphan*/  gp10b_mc ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

void
gp10b_mc_init(struct nvkm_mc *mc)
{
	struct nvkm_device *device = mc->subdev.device;
	nvkm_wr32(device, 0x000200, 0xffffffff); /* everything on */
	nvkm_wr32(device, 0x00020c, 0xffffffff); /* everything out of ELPG */
}

int
gp10b_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
	return gp100_mc_new_(&gp10b_mc, device, index, pmc);
}


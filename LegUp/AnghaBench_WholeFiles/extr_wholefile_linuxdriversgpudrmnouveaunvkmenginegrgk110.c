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
struct nvkm_gr {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;
struct TYPE_6__ {TYPE_2__ engine; } ;
struct gf100_gr {TYPE_3__ base; } ;

/* Variables and functions */
 int gf100_gr_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_gr**) ; 
 int /*<<< orphan*/  gk110_gr ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 

void
gk110_gr_init_419eb4(struct gf100_gr *gr)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	nvkm_mask(device, 0x419eb4, 0x00001000, 0x00001000);
	nvkm_mask(device, 0x419eb4, 0x00002000, 0x00002000);
	nvkm_mask(device, 0x419eb4, 0x00004000, 0x00004000);
	nvkm_mask(device, 0x419eb4, 0x00008000, 0x00008000);
	nvkm_mask(device, 0x419eb4, 0x00001000, 0x00000000);
	nvkm_mask(device, 0x419eb4, 0x00002000, 0x00000000);
	nvkm_mask(device, 0x419eb4, 0x00004000, 0x00000000);
	nvkm_mask(device, 0x419eb4, 0x00008000, 0x00000000);
}

int
gk110_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
	return gf100_gr_new_(&gk110_gr, device, index, pgr);
}


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
struct TYPE_3__ {struct nvkm_device* device; } ;
struct TYPE_4__ {TYPE_1__ subdev; } ;
struct nvkm_falcon {TYPE_2__ engine; } ;
struct nvkm_engine {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gf100_msppp ; 
 int nvkm_msppp_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_engine**) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
gf100_msppp_init(struct nvkm_falcon *msppp)
{
	struct nvkm_device *device = msppp->engine.subdev.device;
	nvkm_wr32(device, 0x086010, 0x0000fff2);
	nvkm_wr32(device, 0x08601c, 0x0000fff2);
}

int
gf100_msppp_new(struct nvkm_device *device, int index,
		struct nvkm_engine **pengine)
{
	return nvkm_msppp_new_(&gf100_msppp, device, index, pengine);
}


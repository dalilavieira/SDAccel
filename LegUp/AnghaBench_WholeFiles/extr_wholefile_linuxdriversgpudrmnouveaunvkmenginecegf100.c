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
struct TYPE_3__ {int index; struct nvkm_device* device; } ;
struct TYPE_4__ {TYPE_1__ subdev; } ;
struct nvkm_falcon {scalar_t__ addr; TYPE_2__ engine; } ;
struct nvkm_engine {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int NVKM_ENGINE_CE0 ; 
 int NVKM_ENGINE_CE1 ; 
 int /*<<< orphan*/  gf100_ce0 ; 
 int /*<<< orphan*/  gf100_ce1 ; 
 int nvkm_falcon_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,int,int,struct nvkm_engine**) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,scalar_t__,int const) ; 

__attribute__((used)) static void
gf100_ce_init(struct nvkm_falcon *ce)
{
	struct nvkm_device *device = ce->engine.subdev.device;
	const int index = ce->engine.subdev.index - NVKM_ENGINE_CE0;
	nvkm_wr32(device, ce->addr + 0x084, index);
}

int
gf100_ce_new(struct nvkm_device *device, int index,
	     struct nvkm_engine **pengine)
{
	if (index == NVKM_ENGINE_CE0) {
		return nvkm_falcon_new_(&gf100_ce0, device, index, true,
					0x104000, pengine);
	} else
	if (index == NVKM_ENGINE_CE1) {
		return nvkm_falcon_new_(&gf100_ce1, device, index, true,
					0x105000, pengine);
	}
	return -ENODEV;
}


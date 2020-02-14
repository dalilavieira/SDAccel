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
struct nvkm_pmu {TYPE_1__ subdev; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gp102_pmu ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_pmu_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pmu**) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 

__attribute__((used)) static void
gp102_pmu_reset(struct nvkm_pmu *pmu)
{
	struct nvkm_device *device = pmu->subdev.device;
	nvkm_mask(device, 0x10a3c0, 0x00000001, 0x00000001);
	nvkm_mask(device, 0x10a3c0, 0x00000001, 0x00000000);
}

__attribute__((used)) static bool
gp102_pmu_enabled(struct nvkm_pmu *pmu)
{
	return !(nvkm_rd32(pmu->subdev.device, 0x10a3c0) & 0x00000001);
}

int
gp102_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
	return nvkm_pmu_new_(&gp102_pmu, device, index, ppmu);
}


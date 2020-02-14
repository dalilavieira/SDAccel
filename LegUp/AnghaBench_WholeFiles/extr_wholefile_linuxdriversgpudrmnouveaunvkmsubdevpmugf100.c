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
 int /*<<< orphan*/  NVKM_SUBDEV_PMU ; 
 int /*<<< orphan*/  gf100_pmu ; 
 int /*<<< orphan*/  nvkm_mc_disable (struct nvkm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_mc_enable (struct nvkm_device*,int /*<<< orphan*/ ) ; 
 int nvkm_mc_enabled (struct nvkm_device*,int /*<<< orphan*/ ) ; 
 int nvkm_pmu_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pmu**) ; 

void
gf100_pmu_reset(struct nvkm_pmu *pmu)
{
	struct nvkm_device *device = pmu->subdev.device;
	nvkm_mc_disable(device, NVKM_SUBDEV_PMU);
	nvkm_mc_enable(device, NVKM_SUBDEV_PMU);
}

bool
gf100_pmu_enabled(struct nvkm_pmu *pmu)
{
	return nvkm_mc_enabled(pmu->subdev.device, NVKM_SUBDEV_PMU);
}

int
gf100_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
	return nvkm_pmu_new_(&gf100_pmu, device, index, ppmu);
}


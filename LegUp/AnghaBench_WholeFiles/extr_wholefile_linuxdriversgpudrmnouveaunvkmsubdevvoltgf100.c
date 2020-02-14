#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_volt {scalar_t__ speedo; struct nvkm_subdev subdev; } ;
struct nvkm_fuse {int dummy; } ;
struct nvkm_device {struct nvkm_fuse* fuse; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  gf100_volt ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*) ; 
 int nvkm_fuse_read (struct nvkm_fuse*,int) ; 
 int nvkm_volt_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_volt**) ; 
 int nvkm_voltgpio_init (struct nvkm_volt*) ; 

__attribute__((used)) static int
gf100_volt_speedo_read(struct nvkm_volt *volt)
{
	struct nvkm_device *device = volt->subdev.device;
	struct nvkm_fuse *fuse = device->fuse;

	if (!fuse)
		return -EINVAL;

	return nvkm_fuse_read(fuse, 0x1cc);
}

int
gf100_volt_oneinit(struct nvkm_volt *volt)
{
	struct nvkm_subdev *subdev = &volt->subdev;
	if (volt->speedo <= 0)
		nvkm_error(subdev, "couldn't find speedo value, volting not "
			   "possible\n");
	return 0;
}

int
gf100_volt_new(struct nvkm_device *device, int index, struct nvkm_volt **pvolt)
{
	struct nvkm_volt *volt;
	int ret;

	ret = nvkm_volt_new_(&gf100_volt, device, index, &volt);
	*pvolt = volt;
	if (ret)
		return ret;

	return nvkm_voltgpio_init(volt);
}


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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct nvif_object {int dummy; } ;
struct nv_device_time_v0 {scalar_t__ version; int /*<<< orphan*/  time; } ;
struct TYPE_2__ {int /*<<< orphan*/ * func; } ;
struct nvif_device {struct nv_device_time_v0 info; int /*<<< orphan*/  object; TYPE_1__ user; int /*<<< orphan*/ * runlist; } ;
typedef  int /*<<< orphan*/  s32 ;
typedef  int /*<<< orphan*/  args ;

/* Variables and functions */
 int /*<<< orphan*/  NV_DEVICE_V0_INFO ; 
 int /*<<< orphan*/  NV_DEVICE_V0_TIME ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nvif_object_fini (int /*<<< orphan*/ *) ; 
 int nvif_object_init (struct nvif_object*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int nvif_object_mthd (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct nv_device_time_v0*,int) ; 
 int /*<<< orphan*/  nvif_user_fini (struct nvif_device*) ; 

u64
nvif_device_time(struct nvif_device *device)
{
	struct nv_device_time_v0 args = {};
	int ret = nvif_object_mthd(&device->object, NV_DEVICE_V0_TIME,
				   &args, sizeof(args));
	WARN_ON_ONCE(ret != 0);
	return args.time;
}

void
nvif_device_fini(struct nvif_device *device)
{
	nvif_user_fini(device);
	kfree(device->runlist);
	device->runlist = NULL;
	nvif_object_fini(&device->object);
}

int
nvif_device_init(struct nvif_object *parent, u32 handle, s32 oclass,
		 void *data, u32 size, struct nvif_device *device)
{
	int ret = nvif_object_init(parent, handle, oclass, data, size,
				   &device->object);
	device->runlist = NULL;
	device->user.func = NULL;
	if (ret == 0) {
		device->info.version = 0;
		ret = nvif_object_mthd(&device->object, NV_DEVICE_V0_INFO,
				       &device->info, sizeof(device->info));
	}
	return ret;
}


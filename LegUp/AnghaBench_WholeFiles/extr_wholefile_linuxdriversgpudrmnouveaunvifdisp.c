#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct nvif_mclass {int member_1; int /*<<< orphan*/  oclass; int /*<<< orphan*/  member_0; } ;
struct TYPE_3__ {int /*<<< orphan*/ * client; } ;
struct nvif_disp {TYPE_1__ object; } ;
struct nvif_device {int /*<<< orphan*/  object; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
#define  G82_DISP 141 
#define  GF110_DISP 140 
#define  GK104_DISP 139 
#define  GK110_DISP 138 
#define  GM107_DISP 137 
#define  GM200_DISP 136 
#define  GP100_DISP 135 
#define  GP102_DISP 134 
#define  GT200_DISP 133 
#define  GT206_DISP 132 
#define  GT214_DISP 131 
#define  GV100_DISP 130 
#define  NV04_DISP 129 
#define  NV50_DISP 128 
 int /*<<< orphan*/  nvif_object_fini (TYPE_1__*) ; 
 int nvif_object_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int nvif_sclass (int /*<<< orphan*/ *,struct nvif_mclass const*,int /*<<< orphan*/ ) ; 

void
nvif_disp_dtor(struct nvif_disp *disp)
{
	nvif_object_fini(&disp->object);
}

int
nvif_disp_ctor(struct nvif_device *device, s32 oclass, struct nvif_disp *disp)
{
	static const struct nvif_mclass disps[] = {
		{ GV100_DISP, -1 },
		{ GP102_DISP, -1 },
		{ GP100_DISP, -1 },
		{ GM200_DISP, -1 },
		{ GM107_DISP, -1 },
		{ GK110_DISP, -1 },
		{ GK104_DISP, -1 },
		{ GF110_DISP, -1 },
		{ GT214_DISP, -1 },
		{ GT206_DISP, -1 },
		{ GT200_DISP, -1 },
		{   G82_DISP, -1 },
		{  NV50_DISP, -1 },
		{  NV04_DISP, -1 },
		{}
	};
	int cid = nvif_sclass(&device->object, disps, oclass);
	disp->object.client = NULL;
	if (cid < 0)
		return cid;

	return nvif_object_init(&device->object, 0, disps[cid].oclass,
				NULL, 0, &disp->object);
}


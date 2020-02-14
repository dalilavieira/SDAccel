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
typedef  int u32 ;
typedef  int u16 ;
struct nvkm_head_state {int vblanks; int vtotal; int vblanke; int hblanks; int htotal; int hblanke; } ;
struct nvkm_head {int id; TYPE_3__* disp; } ;
struct nvkm_disp {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;
struct TYPE_6__ {TYPE_2__ engine; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv04_head ; 
 int nvkm_head_new_ (int /*<<< orphan*/ *,struct nvkm_disp*,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static void
nv04_head_vblank_put(struct nvkm_head *head)
{
	struct nvkm_device *device = head->disp->engine.subdev.device;
	nvkm_wr32(device, 0x600140 + (head->id * 0x2000) , 0x00000000);
}

__attribute__((used)) static void
nv04_head_vblank_get(struct nvkm_head *head)
{
	struct nvkm_device *device = head->disp->engine.subdev.device;
	nvkm_wr32(device, 0x600140 + (head->id * 0x2000) , 0x00000001);
}

__attribute__((used)) static void
nv04_head_rgpos(struct nvkm_head *head, u16 *hline, u16 *vline)
{
	struct nvkm_device *device = head->disp->engine.subdev.device;
	u32 data = nvkm_rd32(device, 0x600868 + (head->id * 0x2000));
	*hline = (data & 0xffff0000) >> 16;
	*vline = (data & 0x0000ffff);
}

__attribute__((used)) static void
nv04_head_state(struct nvkm_head *head, struct nvkm_head_state *state)
{
	struct nvkm_device *device = head->disp->engine.subdev.device;
	const u32 hoff = head->id * 0x0200;
	state->vblanks = nvkm_rd32(device, 0x680800 + hoff) & 0x0000ffff;
	state->vtotal  = nvkm_rd32(device, 0x680804 + hoff) & 0x0000ffff;
	state->vblanke = state->vtotal - 1;
	state->hblanks = nvkm_rd32(device, 0x680820 + hoff) & 0x0000ffff;
	state->htotal  = nvkm_rd32(device, 0x680824 + hoff) & 0x0000ffff;
	state->hblanke = state->htotal - 1;
}

int
nv04_head_new(struct nvkm_disp *disp, int id)
{
	return nvkm_head_new_(&nv04_head, disp, id);
}


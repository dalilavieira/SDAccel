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
typedef  int /*<<< orphan*/  u32 ;
struct nvkm_fault_buffer {TYPE_3__* fault; TYPE_1__* vma; } ;
struct nvkm_fault {int /*<<< orphan*/  event; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct TYPE_6__ {TYPE_2__ subdev; } ;
struct TYPE_4__ {int /*<<< orphan*/  addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  gp100_fault ; 
 int /*<<< orphan*/  lower_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_event_send (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int nvkm_fault_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_fault**) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
gp100_fault_buffer_fini(struct nvkm_fault_buffer *buffer)
{
	struct nvkm_device *device = buffer->fault->subdev.device;
	nvkm_mask(device, 0x002a70, 0x00000001, 0x00000000);
}

__attribute__((used)) static void
gp100_fault_buffer_init(struct nvkm_fault_buffer *buffer)
{
	struct nvkm_device *device = buffer->fault->subdev.device;
	nvkm_wr32(device, 0x002a74, upper_32_bits(buffer->vma->addr));
	nvkm_wr32(device, 0x002a70, lower_32_bits(buffer->vma->addr));
	nvkm_mask(device, 0x002a70, 0x00000001, 0x00000001);
}

__attribute__((used)) static u32
gp100_fault_buffer_entries(struct nvkm_fault_buffer *buffer)
{
	return nvkm_rd32(buffer->fault->subdev.device, 0x002a78);
}

__attribute__((used)) static void
gp100_fault_intr(struct nvkm_fault *fault)
{
	nvkm_event_send(&fault->event, 1, 0, NULL, 0);
}

int
gp100_fault_new(struct nvkm_device *device, int index,
		struct nvkm_fault **pfault)
{
	return nvkm_fault_new_(&gp100_fault, device, index, pfault);
}


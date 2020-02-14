#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct nvkm_memory {int dummy; } ;
struct nvkm_fifo_cgrp {int chan_nr; int id; } ;
struct nvkm_fifo {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_8__ {int chid; TYPE_3__* inst; } ;
struct gk104_fifo_chan {TYPE_4__ base; TYPE_2__* fifo; } ;
struct TYPE_7__ {scalar_t__ addr; } ;
struct TYPE_5__ {struct nvkm_memory* mem; } ;
struct TYPE_6__ {TYPE_1__ user; } ;

/* Variables and functions */
 int gk104_fifo_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,int,struct nvkm_fifo**) ; 
 int /*<<< orphan*/  gv100_fifo ; 
 int lower_32_bits (scalar_t__ const) ; 
 scalar_t__ nvkm_memory_addr (struct nvkm_memory*) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_memory*,scalar_t__,int) ; 
 int upper_32_bits (scalar_t__ const) ; 

__attribute__((used)) static void
gv100_fifo_runlist_chan(struct gk104_fifo_chan *chan,
			struct nvkm_memory *memory, u32 offset)
{
	struct nvkm_memory *usermem = chan->fifo->user.mem;
	const u64 user = nvkm_memory_addr(usermem) + (chan->base.chid * 0x200);
	const u64 inst = chan->base.inst->addr;

	nvkm_wo32(memory, offset + 0x0, lower_32_bits(user));
	nvkm_wo32(memory, offset + 0x4, upper_32_bits(user));
	nvkm_wo32(memory, offset + 0x8, lower_32_bits(inst) | chan->base.chid);
	nvkm_wo32(memory, offset + 0xc, upper_32_bits(inst));
}

__attribute__((used)) static void
gv100_fifo_runlist_cgrp(struct nvkm_fifo_cgrp *cgrp,
			struct nvkm_memory *memory, u32 offset)
{
	nvkm_wo32(memory, offset + 0x0, (128 << 24) | (3 << 16) | 0x00000001);
	nvkm_wo32(memory, offset + 0x4, cgrp->chan_nr);
	nvkm_wo32(memory, offset + 0x8, cgrp->id);
	nvkm_wo32(memory, offset + 0xc, 0x00000000);
}

int
gv100_fifo_new(struct nvkm_device *device, int index, struct nvkm_fifo **pfifo)
{
	return gk104_fifo_new_(&gv100_fifo, device, index, 4096, pfifo);
}


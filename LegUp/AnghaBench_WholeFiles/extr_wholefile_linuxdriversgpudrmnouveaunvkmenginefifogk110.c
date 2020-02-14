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
typedef  scalar_t__ u32 ;
struct nvkm_memory {int dummy; } ;
struct nvkm_fifo_cgrp {int chan_nr; int id; } ;
struct nvkm_fifo {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int gk104_fifo_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,int,struct nvkm_fifo**) ; 
 int /*<<< orphan*/  gk110_fifo ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_memory*,scalar_t__,int) ; 

void
gk110_fifo_runlist_cgrp(struct nvkm_fifo_cgrp *cgrp,
			struct nvkm_memory *memory, u32 offset)
{
	nvkm_wo32(memory, offset + 0, (cgrp->chan_nr << 26) | (128 << 18) |
				      (3 << 14) | 0x00002000 | cgrp->id);
	nvkm_wo32(memory, offset + 4, 0x00000000);
}

int
gk110_fifo_new(struct nvkm_device *device, int index, struct nvkm_fifo **pfifo)
{
	return gk104_fifo_new_(&gk110_fifo, device, index, 4096, pfifo);
}


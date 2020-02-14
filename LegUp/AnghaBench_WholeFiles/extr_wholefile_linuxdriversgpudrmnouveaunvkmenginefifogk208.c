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
struct nvkm_fifo {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;
struct TYPE_6__ {TYPE_2__ engine; } ;
struct gk104_fifo {int pbdma_nr; TYPE_3__ base; } ;

/* Variables and functions */
 int gk104_fifo_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,int,struct nvkm_fifo**) ; 
 int /*<<< orphan*/  gk208_fifo ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

void
gk208_fifo_init_pbdma_timeout(struct gk104_fifo *fifo)
{
	struct nvkm_device *device = fifo->base.engine.subdev.device;
	int i;

	for (i = 0; i < fifo->pbdma_nr; i++)
		nvkm_wr32(device, 0x04012c + (i * 0x2000), 0x0000ffff);
}

int
gk208_fifo_new(struct nvkm_device *device, int index, struct nvkm_fifo **pfifo)
{
	return gk104_fifo_new_(&gk208_fifo, device, index, 1024, pfifo);
}


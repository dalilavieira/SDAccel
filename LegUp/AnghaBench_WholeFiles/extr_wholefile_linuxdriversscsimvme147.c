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
struct TYPE_5__ {int this_residual; int /*<<< orphan*/  ptr; } ;
struct scsi_cmnd {TYPE_2__ SCp; TYPE_1__* device; } ;
struct WD33C93_hostdata {int dma_dir; } ;
struct Scsi_Host {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int dma_intr; int dma_bcr; unsigned long dma_dadr; unsigned char dma_cntrl; } ;
struct TYPE_4__ {struct Scsi_Host* host; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int MVME147_IRQ_SCSI_PORT ; 
 int /*<<< orphan*/  cache_clear (unsigned long,int) ; 
 int /*<<< orphan*/  cache_push (unsigned long,int) ; 
 TYPE_3__* m147_pcc ; 
 struct WD33C93_hostdata* shost_priv (struct Scsi_Host*) ; 
 unsigned long virt_to_bus (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wd33c93_intr (struct Scsi_Host*) ; 

__attribute__((used)) static irqreturn_t mvme147_intr(int irq, void *data)
{
	struct Scsi_Host *instance = data;

	if (irq == MVME147_IRQ_SCSI_PORT)
		wd33c93_intr(instance);
	else
		m147_pcc->dma_intr = 0x89;	/* Ack and enable ints */
	return IRQ_HANDLED;
}

__attribute__((used)) static int dma_setup(struct scsi_cmnd *cmd, int dir_in)
{
	struct Scsi_Host *instance = cmd->device->host;
	struct WD33C93_hostdata *hdata = shost_priv(instance);
	unsigned char flags = 0x01;
	unsigned long addr = virt_to_bus(cmd->SCp.ptr);

	/* setup dma direction */
	if (!dir_in)
		flags |= 0x04;

	/* remember direction */
	hdata->dma_dir = dir_in;

	if (dir_in) {
		/* invalidate any cache */
		cache_clear(addr, cmd->SCp.this_residual);
	} else {
		/* push any dirty cache */
		cache_push(addr, cmd->SCp.this_residual);
	}

	/* start DMA */
	m147_pcc->dma_bcr = cmd->SCp.this_residual | (1 << 24);
	m147_pcc->dma_dadr = addr;
	m147_pcc->dma_cntrl = flags;

	/* return success */
	return 0;
}

__attribute__((used)) static void dma_stop(struct Scsi_Host *instance, struct scsi_cmnd *SCpnt,
		     int status)
{
	m147_pcc->dma_cntrl = 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/ * SCMD; int /*<<< orphan*/ * SASR; } ;
typedef  TYPE_4__ wd33c93_regs ;
struct zorro_device_id {unsigned int driver_data; } ;
struct TYPE_6__ {unsigned long start; } ;
struct zorro_dev {TYPE_1__ resource; int /*<<< orphan*/  slotaddr; } ;
struct TYPE_8__ {int /*<<< orphan*/  this_residual; int /*<<< orphan*/ * ptr; } ;
struct scsi_cmnd {TYPE_3__ SCp; TYPE_2__* device; } ;
struct gvp11_scsiregs {unsigned int CNTR; unsigned long ACR; int BANK; int ST_DMA; int SP_DMA; int secret2; int secret3; int /*<<< orphan*/  SCMD; int /*<<< orphan*/  SASR; scalar_t__ secret1; } ;
struct WD33C93_hostdata {unsigned long dma_xfer_mask; int dma_bounce_len; scalar_t__ dma_buffer_pool; int dma_dir; int no_sync; int /*<<< orphan*/  dma_mode; scalar_t__ fast; int /*<<< orphan*/ * dma_bounce_buffer; } ;
struct gvp11_hostdata {struct gvp11_scsiregs* regs; struct WD33C93_hostdata wh; } ;
struct Scsi_Host {int /*<<< orphan*/  unique_id; int /*<<< orphan*/  irq; int /*<<< orphan*/  host_lock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {struct Scsi_Host* host; } ;

/* Variables and functions */
 void* BUF_CHIP_ALLOCED ; 
 scalar_t__ BUF_SCSI_ALLOCED ; 
 int /*<<< orphan*/  CTRL_DMA ; 
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GVP11_DMAC_BUSY ; 
 unsigned short GVP11_DMAC_DIR_WRITE ; 
 void* GVP11_DMAC_INT_ENABLE ; 
 unsigned int GVP11_DMAC_INT_PENDING ; 
 unsigned int GVP_SCSICLKMASK ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_AMIGA_PORTS ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  WD33C93_FS_12_15 ; 
 int /*<<< orphan*/  WD33C93_FS_8_10 ; 
 struct gvp11_scsiregs* ZTWO_VADDR (unsigned long) ; 
 void* amiga_chip_alloc (int,char*) ; 
 int /*<<< orphan*/  amiga_chip_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cache_clear (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cache_push (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct Scsi_Host*) ; 
 int /*<<< orphan*/  gvp11_scsi_template ; 
 int gvp11_xfer_mask ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_mem_region (unsigned long,int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct Scsi_Host*) ; 
 int /*<<< orphan*/  request_mem_region (unsigned long,int,char*) ; 
 int scsi_add_host (struct Scsi_Host*,int /*<<< orphan*/ *) ; 
 struct Scsi_Host* scsi_host_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  scsi_host_put (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_remove_host (struct Scsi_Host*) ; 
 int /*<<< orphan*/  scsi_scan_host (struct Scsi_Host*) ; 
 struct gvp11_hostdata* shost_priv (struct Scsi_Host*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long virt_to_bus (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wd33c93_init (struct Scsi_Host*,TYPE_4__,int (*) (struct scsi_cmnd*,int),void (*) (struct Scsi_Host*,struct scsi_cmnd*,int),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wd33c93_intr (struct Scsi_Host*) ; 
 struct Scsi_Host* zorro_get_drvdata (struct zorro_dev*) ; 
 int zorro_resource_len (struct zorro_dev*) ; 
 int /*<<< orphan*/  zorro_set_drvdata (struct zorro_dev*,struct Scsi_Host*) ; 

__attribute__((used)) static irqreturn_t gvp11_intr(int irq, void *data)
{
	struct Scsi_Host *instance = data;
	struct gvp11_hostdata *hdata = shost_priv(instance);
	unsigned int status = hdata->regs->CNTR;
	unsigned long flags;

	if (!(status & GVP11_DMAC_INT_PENDING))
		return IRQ_NONE;

	spin_lock_irqsave(instance->host_lock, flags);
	wd33c93_intr(instance);
	spin_unlock_irqrestore(instance->host_lock, flags);
	return IRQ_HANDLED;
}

void gvp11_setup(char *str, int *ints)
{
	gvp11_xfer_mask = ints[1];
}

__attribute__((used)) static int dma_setup(struct scsi_cmnd *cmd, int dir_in)
{
	struct Scsi_Host *instance = cmd->device->host;
	struct gvp11_hostdata *hdata = shost_priv(instance);
	struct WD33C93_hostdata *wh = &hdata->wh;
	struct gvp11_scsiregs *regs = hdata->regs;
	unsigned short cntr = GVP11_DMAC_INT_ENABLE;
	unsigned long addr = virt_to_bus(cmd->SCp.ptr);
	int bank_mask;
	static int scsi_alloc_out_of_range = 0;

	/* use bounce buffer if the physical address is bad */
	if (addr & wh->dma_xfer_mask) {
		wh->dma_bounce_len = (cmd->SCp.this_residual + 511) & ~0x1ff;

		if (!scsi_alloc_out_of_range) {
			wh->dma_bounce_buffer =
				kmalloc(wh->dma_bounce_len, GFP_KERNEL);
			wh->dma_buffer_pool = BUF_SCSI_ALLOCED;
		}

		if (scsi_alloc_out_of_range ||
		    !wh->dma_bounce_buffer) {
			wh->dma_bounce_buffer =
				amiga_chip_alloc(wh->dma_bounce_len,
						 "GVP II SCSI Bounce Buffer");

			if (!wh->dma_bounce_buffer) {
				wh->dma_bounce_len = 0;
				return 1;
			}

			wh->dma_buffer_pool = BUF_CHIP_ALLOCED;
		}

		/* check if the address of the bounce buffer is OK */
		addr = virt_to_bus(wh->dma_bounce_buffer);

		if (addr & wh->dma_xfer_mask) {
			/* fall back to Chip RAM if address out of range */
			if (wh->dma_buffer_pool == BUF_SCSI_ALLOCED) {
				kfree(wh->dma_bounce_buffer);
				scsi_alloc_out_of_range = 1;
			} else {
				amiga_chip_free(wh->dma_bounce_buffer);
			}

			wh->dma_bounce_buffer =
				amiga_chip_alloc(wh->dma_bounce_len,
						 "GVP II SCSI Bounce Buffer");

			if (!wh->dma_bounce_buffer) {
				wh->dma_bounce_len = 0;
				return 1;
			}

			addr = virt_to_bus(wh->dma_bounce_buffer);
			wh->dma_buffer_pool = BUF_CHIP_ALLOCED;
		}

		if (!dir_in) {
			/* copy to bounce buffer for a write */
			memcpy(wh->dma_bounce_buffer, cmd->SCp.ptr,
			       cmd->SCp.this_residual);
		}
	}

	/* setup dma direction */
	if (!dir_in)
		cntr |= GVP11_DMAC_DIR_WRITE;

	wh->dma_dir = dir_in;
	regs->CNTR = cntr;

	/* setup DMA *physical* address */
	regs->ACR = addr;

	if (dir_in) {
		/* invalidate any cache */
		cache_clear(addr, cmd->SCp.this_residual);
	} else {
		/* push any dirty cache */
		cache_push(addr, cmd->SCp.this_residual);
	}

	bank_mask = (~wh->dma_xfer_mask >> 18) & 0x01c0;
	if (bank_mask)
		regs->BANK = bank_mask & (addr >> 18);

	/* start DMA */
	regs->ST_DMA = 1;

	/* return success */
	return 0;
}

__attribute__((used)) static void dma_stop(struct Scsi_Host *instance, struct scsi_cmnd *SCpnt,
		     int status)
{
	struct gvp11_hostdata *hdata = shost_priv(instance);
	struct WD33C93_hostdata *wh = &hdata->wh;
	struct gvp11_scsiregs *regs = hdata->regs;

	/* stop DMA */
	regs->SP_DMA = 1;
	/* remove write bit from CONTROL bits */
	regs->CNTR = GVP11_DMAC_INT_ENABLE;

	/* copy from a bounce buffer, if necessary */
	if (status && wh->dma_bounce_buffer) {
		if (wh->dma_dir && SCpnt)
			memcpy(SCpnt->SCp.ptr, wh->dma_bounce_buffer,
			       SCpnt->SCp.this_residual);

		if (wh->dma_buffer_pool == BUF_SCSI_ALLOCED)
			kfree(wh->dma_bounce_buffer);
		else
			amiga_chip_free(wh->dma_bounce_buffer);

		wh->dma_bounce_buffer = NULL;
		wh->dma_bounce_len = 0;
	}
}

__attribute__((used)) static int check_wd33c93(struct gvp11_scsiregs *regs)
{
#ifdef CHECK_WD33C93
	volatile unsigned char *sasr_3393, *scmd_3393;
	unsigned char save_sasr;
	unsigned char q, qq;

	/*
	 * These darn GVP boards are a problem - it can be tough to tell
	 * whether or not they include a SCSI controller. This is the
	 * ultimate Yet-Another-GVP-Detection-Hack in that it actually
	 * probes for a WD33c93 chip: If we find one, it's extremely
	 * likely that this card supports SCSI, regardless of Product_
	 * Code, Board_Size, etc.
	 */

	/* Get pointers to the presumed register locations and save contents */

	sasr_3393 = &regs->SASR;
	scmd_3393 = &regs->SCMD;
	save_sasr = *sasr_3393;

	/* First test the AuxStatus Reg */

	q = *sasr_3393;	/* read it */
	if (q & 0x08)	/* bit 3 should always be clear */
		return -ENODEV;
	*sasr_3393 = WD_AUXILIARY_STATUS;	/* setup indirect address */
	if (*sasr_3393 == WD_AUXILIARY_STATUS) {	/* shouldn't retain the write */
		*sasr_3393 = save_sasr;	/* Oops - restore this byte */
		return -ENODEV;
	}
	if (*sasr_3393 != q) {	/* should still read the same */
		*sasr_3393 = save_sasr;	/* Oops - restore this byte */
		return -ENODEV;
	}
	if (*scmd_3393 != q)	/* and so should the image at 0x1f */
		return -ENODEV;

	/*
	 * Ok, we probably have a wd33c93, but let's check a few other places
	 * for good measure. Make sure that this works for both 'A and 'B
	 * chip versions.
	 */

	*sasr_3393 = WD_SCSI_STATUS;
	q = *scmd_3393;
	*sasr_3393 = WD_SCSI_STATUS;
	*scmd_3393 = ~q;
	*sasr_3393 = WD_SCSI_STATUS;
	qq = *scmd_3393;
	*sasr_3393 = WD_SCSI_STATUS;
	*scmd_3393 = q;
	if (qq != q)	/* should be read only */
		return -ENODEV;
	*sasr_3393 = 0x1e;	/* this register is unimplemented */
	q = *scmd_3393;
	*sasr_3393 = 0x1e;
	*scmd_3393 = ~q;
	*sasr_3393 = 0x1e;
	qq = *scmd_3393;
	*sasr_3393 = 0x1e;
	*scmd_3393 = q;
	if (qq != q || qq != 0xff)	/* should be read only, all 1's */
		return -ENODEV;
	*sasr_3393 = WD_TIMEOUT_PERIOD;
	q = *scmd_3393;
	*sasr_3393 = WD_TIMEOUT_PERIOD;
	*scmd_3393 = ~q;
	*sasr_3393 = WD_TIMEOUT_PERIOD;
	qq = *scmd_3393;
	*sasr_3393 = WD_TIMEOUT_PERIOD;
	*scmd_3393 = q;
	if (qq != (~q & 0xff))	/* should be read/write */
		return -ENODEV;
#endif /* CHECK_WD33C93 */

	return 0;
}

__attribute__((used)) static int gvp11_probe(struct zorro_dev *z, const struct zorro_device_id *ent)
{
	struct Scsi_Host *instance;
	unsigned long address;
	int error;
	unsigned int epc;
	unsigned int default_dma_xfer_mask;
	struct gvp11_hostdata *hdata;
	struct gvp11_scsiregs *regs;
	wd33c93_regs wdregs;

	default_dma_xfer_mask = ent->driver_data;

	/*
	 * Rumors state that some GVP ram boards use the same product
	 * code as the SCSI controllers. Therefore if the board-size
	 * is not 64KB we assume it is a ram board and bail out.
	 */
	if (zorro_resource_len(z) != 0x10000)
		return -ENODEV;

	address = z->resource.start;
	if (!request_mem_region(address, 256, "wd33c93"))
		return -EBUSY;

	regs = ZTWO_VADDR(address);

	error = check_wd33c93(regs);
	if (error)
		goto fail_check_or_alloc;

	instance = scsi_host_alloc(&gvp11_scsi_template,
				   sizeof(struct gvp11_hostdata));
	if (!instance) {
		error = -ENOMEM;
		goto fail_check_or_alloc;
	}

	instance->irq = IRQ_AMIGA_PORTS;
	instance->unique_id = z->slotaddr;

	regs->secret2 = 1;
	regs->secret1 = 0;
	regs->secret3 = 15;
	while (regs->CNTR & GVP11_DMAC_BUSY)
		;
	regs->CNTR = 0;
	regs->BANK = 0;

	wdregs.SASR = &regs->SASR;
	wdregs.SCMD = &regs->SCMD;

	hdata = shost_priv(instance);
	if (gvp11_xfer_mask)
		hdata->wh.dma_xfer_mask = gvp11_xfer_mask;
	else
		hdata->wh.dma_xfer_mask = default_dma_xfer_mask;

	hdata->wh.no_sync = 0xff;
	hdata->wh.fast = 0;
	hdata->wh.dma_mode = CTRL_DMA;
	hdata->regs = regs;

	/*
	 * Check for 14MHz SCSI clock
	 */
	epc = *(unsigned short *)(ZTWO_VADDR(address) + 0x8000);
	wd33c93_init(instance, wdregs, dma_setup, dma_stop,
		     (epc & GVP_SCSICLKMASK) ? WD33C93_FS_8_10
					     : WD33C93_FS_12_15);

	error = request_irq(IRQ_AMIGA_PORTS, gvp11_intr, IRQF_SHARED,
			    "GVP11 SCSI", instance);
	if (error)
		goto fail_irq;

	regs->CNTR = GVP11_DMAC_INT_ENABLE;

	error = scsi_add_host(instance, NULL);
	if (error)
		goto fail_host;

	zorro_set_drvdata(z, instance);
	scsi_scan_host(instance);
	return 0;

fail_host:
	free_irq(IRQ_AMIGA_PORTS, instance);
fail_irq:
	scsi_host_put(instance);
fail_check_or_alloc:
	release_mem_region(address, 256);
	return error;
}

__attribute__((used)) static void gvp11_remove(struct zorro_dev *z)
{
	struct Scsi_Host *instance = zorro_get_drvdata(z);
	struct gvp11_hostdata *hdata = shost_priv(instance);

	hdata->regs->CNTR = 0;
	scsi_remove_host(instance);
	free_irq(IRQ_AMIGA_PORTS, instance);
	scsi_host_put(instance);
	release_mem_region(z->resource.start, 256);
}


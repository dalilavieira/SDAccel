#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int dummy; } ;
struct ide_port_info {int dummy; } ;
struct TYPE_13__ {scalar_t__ device_addr; } ;
struct TYPE_16__ {unsigned long select_data; int channel; scalar_t__ dma_base; int /*<<< orphan*/  irq; TYPE_3__* mate; int /*<<< orphan*/  dev; TYPE_2__* dma_ops; TYPE_1__ io_ports; } ;
typedef  TYPE_4__ ide_hwif_t ;
struct TYPE_17__ {int dev_flags; int dn; int select; TYPE_4__* hwif; } ;
typedef  TYPE_5__ ide_drive_t ;
struct TYPE_15__ {unsigned long select_data; } ;
struct TYPE_14__ {int (* dma_sff_read_status ) (TYPE_4__*) ;} ;

/* Variables and functions */
 int ATA_DEVICE_OBS ; 
 scalar_t__ ATA_DMA_CMD ; 
 scalar_t__ ATA_DMA_STATUS ; 
 int IDE_DFLAG_PRESENT ; 
 int IDE_DFLAG_USING_DMA ; 
 int /*<<< orphan*/  ide_dma_start (TYPE_5__*) ; 
 int ide_pci_init_one (struct pci_dev*,struct ide_port_info*,int /*<<< orphan*/ *) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 struct ide_port_info ns87415_chipset ; 
 int /*<<< orphan*/ * ns87415_control ; 
 int /*<<< orphan*/  ns87415_count ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 int /*<<< orphan*/  pci_get_legacy_ide_irq (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,...) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,unsigned int*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,unsigned int) ; 
 int stub1 (TYPE_4__*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void ns87415_prepare_drive (ide_drive_t *drive, unsigned int use_dma)
{
	ide_hwif_t *hwif = drive->hwif;
	struct pci_dev *dev = to_pci_dev(hwif->dev);
	unsigned int bit, other, new, *old = (unsigned int *) hwif->select_data;
	unsigned long flags;

	local_irq_save(flags);
	new = *old;

	/* Adjust IRQ enable bit */
	bit = 1 << (8 + hwif->channel);

	if (drive->dev_flags & IDE_DFLAG_PRESENT)
		new &= ~bit;
	else
		new |= bit;

	/* Select PIO or DMA, DMA may only be selected for one drive/channel. */
	bit   = 1 << (20 + (drive->dn & 1) + (hwif->channel << 1));
	other = 1 << (20 + (1 - (drive->dn & 1)) + (hwif->channel << 1));
	new = use_dma ? ((new & ~other) | bit) : (new & ~bit);

	if (new != *old) {
		unsigned char stat;

		/*
		 * Don't change DMA engine settings while Write Buffers
		 * are busy.
		 */
		(void) pci_read_config_byte(dev, 0x43, &stat);
		while (stat & 0x03) {
			udelay(1);
			(void) pci_read_config_byte(dev, 0x43, &stat);
		}

		*old = new;
		(void) pci_write_config_dword(dev, 0x40, new);

		/*
		 * And let things settle...
		 */
		udelay(10);
	}

	local_irq_restore(flags);
}

__attribute__((used)) static void ns87415_dev_select(ide_drive_t *drive)
{
	ns87415_prepare_drive(drive,
			      !!(drive->dev_flags & IDE_DFLAG_USING_DMA));

	outb(drive->select | ATA_DEVICE_OBS, drive->hwif->io_ports.device_addr);
}

__attribute__((used)) static void ns87415_dma_start(ide_drive_t *drive)
{
	ns87415_prepare_drive(drive, 1);
	ide_dma_start(drive);
}

__attribute__((used)) static int ns87415_dma_end(ide_drive_t *drive)
{
	ide_hwif_t *hwif = drive->hwif;
	u8 dma_stat = 0, dma_cmd = 0;

	dma_stat = hwif->dma_ops->dma_sff_read_status(hwif);
	/* get DMA command mode */
	dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
	/* stop DMA */
	outb(dma_cmd & ~1, hwif->dma_base + ATA_DMA_CMD);
	/* from ERRATA: clear the INTR & ERROR bits */
	dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
	outb(dma_cmd | 6, hwif->dma_base + ATA_DMA_CMD);

	ns87415_prepare_drive(drive, 0);

	/* verify good DMA status */
	return (dma_stat & 7) != 4;
}

__attribute__((used)) static void init_hwif_ns87415 (ide_hwif_t *hwif)
{
	struct pci_dev *dev = to_pci_dev(hwif->dev);
	unsigned int ctrl, using_inta;
	u8 progif;
#ifdef __sparc_v9__
	int timeout;
	u8 stat;
#endif

	/*
	 * We cannot probe for IRQ: both ports share common IRQ on INTA.
	 * Also, leave IRQ masked during drive probing, to prevent infinite
	 * interrupts from a potentially floating INTA..
	 *
	 * IRQs get unmasked in dev_select() when drive is first used.
	 */
	(void) pci_read_config_dword(dev, 0x40, &ctrl);
	(void) pci_read_config_byte(dev, 0x09, &progif);
	/* is irq in "native" mode? */
	using_inta = progif & (1 << (hwif->channel << 1));
	if (!using_inta)
		using_inta = ctrl & (1 << (4 + hwif->channel));
	if (hwif->mate) {
		hwif->select_data = hwif->mate->select_data;
	} else {
		hwif->select_data = (unsigned long)
					&ns87415_control[ns87415_count++];
		ctrl |= (1 << 8) | (1 << 9);	/* mask both IRQs */
		if (using_inta)
			ctrl &= ~(1 << 6);	/* unmask INTA */
		*((unsigned int *)hwif->select_data) = ctrl;
		(void) pci_write_config_dword(dev, 0x40, ctrl);

		/*
		 * Set prefetch size to 512 bytes for both ports,
		 * but don't turn on/off prefetching here.
		 */
		pci_write_config_byte(dev, 0x55, 0xee);

#ifdef __sparc_v9__
		/*
		 * XXX: Reset the device, if we don't it will not respond to
		 *      dev_select() properly during first ide_probe_port().
		 */
		timeout = 10000;
		outb(12, hwif->io_ports.ctl_addr);
		udelay(10);
		outb(8, hwif->io_ports.ctl_addr);
		do {
			udelay(50);
			stat = hwif->tp_ops->read_status(hwif);
			if (stat == 0xff)
				break;
		} while ((stat & ATA_BUSY) && --timeout);
#endif
	}

	if (!using_inta)
		hwif->irq = pci_get_legacy_ide_irq(dev, hwif->channel);

	if (!hwif->dma_base)
		return;

	outb(0x60, hwif->dma_base + ATA_DMA_STATUS);
}

__attribute__((used)) static int ns87415_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
	struct ide_port_info d = ns87415_chipset;

#ifdef CONFIG_SUPERIO
	if (PCI_SLOT(dev->devfn) == 0xE) {
		/* Built-in - assume it's under superio. */
		d.init_iops = superio_init_iops;
		d.tp_ops = &superio_tp_ops;
	}
#endif
	return ide_pci_init_one(dev, &d, NULL);
}


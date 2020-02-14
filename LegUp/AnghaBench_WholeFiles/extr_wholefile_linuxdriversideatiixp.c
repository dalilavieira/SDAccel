#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {size_t driver_data; } ;
struct pci_dev {int dummy; } ;
struct TYPE_10__ {int channel; int /*<<< orphan*/  dev; } ;
typedef  TYPE_1__ ide_hwif_t ;
struct TYPE_11__ {int dn; int pio_mode; int dma_mode; } ;
typedef  TYPE_2__ ide_drive_t ;
struct TYPE_13__ {int recover_width; int command_width; } ;
struct TYPE_12__ {int recover_width; int command_width; } ;

/* Variables and functions */
 int ATA_CBL_PATA40 ; 
 int ATA_CBL_PATA80 ; 
 int /*<<< orphan*/  ATIIXP_IDE_MDMA_TIMING ; 
 int ATIIXP_IDE_PIO_MODE ; 
 int /*<<< orphan*/  ATIIXP_IDE_PIO_TIMING ; 
 int ATIIXP_IDE_UDMA_CONTROL ; 
 int ATIIXP_IDE_UDMA_MODE ; 
 int const XFER_MW_DMA_0 ; 
 int XFER_PIO_0 ; 
 int const XFER_UDMA_0 ; 
 int /*<<< orphan*/  atiixp_lock ; 
 int /*<<< orphan*/ * atiixp_pci_info ; 
 int ide_pci_init_one (struct pci_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_4__* mdma_timing ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int,int) ; 
 TYPE_3__* pio_timing ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void atiixp_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	struct pci_dev *dev = to_pci_dev(hwif->dev);
	unsigned long flags;
	int timing_shift = (drive->dn ^ 1) * 8;
	u32 pio_timing_data;
	u16 pio_mode_data;
	const u8 pio = drive->pio_mode - XFER_PIO_0;

	spin_lock_irqsave(&atiixp_lock, flags);

	pci_read_config_word(dev, ATIIXP_IDE_PIO_MODE, &pio_mode_data);
	pio_mode_data &= ~(0x07 << (drive->dn * 4));
	pio_mode_data |= (pio << (drive->dn * 4));
	pci_write_config_word(dev, ATIIXP_IDE_PIO_MODE, pio_mode_data);

	pci_read_config_dword(dev, ATIIXP_IDE_PIO_TIMING, &pio_timing_data);
	pio_timing_data &= ~(0xff << timing_shift);
	pio_timing_data |= (pio_timing[pio].recover_width << timing_shift) |
		 (pio_timing[pio].command_width << (timing_shift + 4));
	pci_write_config_dword(dev, ATIIXP_IDE_PIO_TIMING, pio_timing_data);

	spin_unlock_irqrestore(&atiixp_lock, flags);
}

__attribute__((used)) static void atiixp_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	struct pci_dev *dev = to_pci_dev(hwif->dev);
	unsigned long flags;
	int timing_shift = (drive->dn ^ 1) * 8;
	u32 tmp32;
	u16 tmp16;
	u16 udma_ctl = 0;
	const u8 speed = drive->dma_mode;

	spin_lock_irqsave(&atiixp_lock, flags);

	pci_read_config_word(dev, ATIIXP_IDE_UDMA_CONTROL, &udma_ctl);

	if (speed >= XFER_UDMA_0) {
		pci_read_config_word(dev, ATIIXP_IDE_UDMA_MODE, &tmp16);
		tmp16 &= ~(0x07 << (drive->dn * 4));
		tmp16 |= ((speed & 0x07) << (drive->dn * 4));
		pci_write_config_word(dev, ATIIXP_IDE_UDMA_MODE, tmp16);

		udma_ctl |= (1 << drive->dn);
	} else if (speed >= XFER_MW_DMA_0) {
		u8 i = speed & 0x03;

		pci_read_config_dword(dev, ATIIXP_IDE_MDMA_TIMING, &tmp32);
		tmp32 &= ~(0xff << timing_shift);
		tmp32 |= (mdma_timing[i].recover_width << timing_shift) |
			 (mdma_timing[i].command_width << (timing_shift + 4));
		pci_write_config_dword(dev, ATIIXP_IDE_MDMA_TIMING, tmp32);

		udma_ctl &= ~(1 << drive->dn);
	}

	pci_write_config_word(dev, ATIIXP_IDE_UDMA_CONTROL, udma_ctl);

	spin_unlock_irqrestore(&atiixp_lock, flags);
}

__attribute__((used)) static u8 atiixp_cable_detect(ide_hwif_t *hwif)
{
	struct pci_dev *pdev = to_pci_dev(hwif->dev);
	u8 udma_mode = 0, ch = hwif->channel;

	pci_read_config_byte(pdev, ATIIXP_IDE_UDMA_MODE + ch, &udma_mode);

	if ((udma_mode & 0x07) >= 0x04 || (udma_mode & 0x70) >= 0x40)
		return ATA_CBL_PATA80;
	else
		return ATA_CBL_PATA40;
}

__attribute__((used)) static int atiixp_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
	return ide_pci_init_one(dev, &atiixp_pci_info[id->driver_data], NULL);
}


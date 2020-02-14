#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  dev; } ;
typedef  TYPE_1__ ide_hwif_t ;
struct TYPE_12__ {int dn; scalar_t__ const pio_mode; scalar_t__ dma_mode; } ;
typedef  TYPE_2__ ide_drive_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATAC_CH0D0_DMA ; 
 int /*<<< orphan*/  ATAC_CH0D0_PIO ; 
 int /*<<< orphan*/  ATAC_CH0D1_DMA ; 
 int /*<<< orphan*/  ATAC_CH0D1_PIO ; 
 scalar_t__ ATA_CBL_PATA40 ; 
 scalar_t__ ATA_CBL_PATA80 ; 
 int /*<<< orphan*/  CS5535_CABLE_DETECT ; 
 scalar_t__ const XFER_MW_DMA_0 ; 
 scalar_t__ const XFER_MW_DMA_2 ; 
 scalar_t__ const XFER_PIO_0 ; 
 scalar_t__ const XFER_SW_DMA_0 ; 
 scalar_t__ const XFER_UDMA_0 ; 
 scalar_t__ const XFER_UDMA_4 ; 
 int /*<<< orphan*/  cs5535_chipset ; 
 int* cs5535_mwdma_timings ; 
 int* cs5535_pio_cmd_timings ; 
 int* cs5535_pio_dta_timings ; 
 int* cs5535_udma_timings ; 
 TYPE_2__* ide_get_pair_dev (TYPE_2__*) ; 
 int ide_pci_init_one (struct pci_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  rdmsr (int /*<<< orphan*/ ,int,int) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wrmsr (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cs5535_set_speed(ide_drive_t *drive, const u8 speed)
{
	u32 reg = 0, dummy;
	u8 unit = drive->dn & 1;

	/* Set the PIO timings */
	if (speed < XFER_SW_DMA_0) {
		ide_drive_t *pair = ide_get_pair_dev(drive);
		u8 cmd, pioa;

		cmd = pioa = speed - XFER_PIO_0;

		if (pair) {
			u8 piob = pair->pio_mode - XFER_PIO_0;

			if (piob < cmd)
				cmd = piob;
		}

		/* Write the speed of the current drive */
		reg = (cs5535_pio_cmd_timings[cmd] << 16) |
			cs5535_pio_dta_timings[pioa];
		wrmsr(unit ? ATAC_CH0D1_PIO : ATAC_CH0D0_PIO, reg, 0);

		/* And if nessesary - change the speed of the other drive */
		rdmsr(unit ?  ATAC_CH0D0_PIO : ATAC_CH0D1_PIO, reg, dummy);

		if (((reg >> 16) & cs5535_pio_cmd_timings[cmd]) !=
			cs5535_pio_cmd_timings[cmd]) {
			reg &= 0x0000FFFF;
			reg |= cs5535_pio_cmd_timings[cmd] << 16;
			wrmsr(unit ? ATAC_CH0D0_PIO : ATAC_CH0D1_PIO, reg, 0);
		}

		/* Set bit 31 of the DMA register for PIO format 1 timings */
		rdmsr(unit ?  ATAC_CH0D1_DMA : ATAC_CH0D0_DMA, reg, dummy);
		wrmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA,
					reg | 0x80000000UL, 0);
	} else {
		rdmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA, reg, dummy);

		reg &= 0x80000000UL;  /* Preserve the PIO format bit */

		if (speed >= XFER_UDMA_0 && speed <= XFER_UDMA_4)
			reg |= cs5535_udma_timings[speed - XFER_UDMA_0];
		else if (speed >= XFER_MW_DMA_0 && speed <= XFER_MW_DMA_2)
			reg |= cs5535_mwdma_timings[speed - XFER_MW_DMA_0];
		else
			return;

		wrmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA, reg, 0);
	}
}

__attribute__((used)) static void cs5535_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	cs5535_set_speed(drive, drive->dma_mode);
}

__attribute__((used)) static void cs5535_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	cs5535_set_speed(drive, drive->pio_mode);
}

__attribute__((used)) static u8 cs5535_cable_detect(ide_hwif_t *hwif)
{
	struct pci_dev *dev = to_pci_dev(hwif->dev);
	u8 bit;

	/* if a 80 wire cable was detected */
	pci_read_config_byte(dev, CS5535_CABLE_DETECT, &bit);

	return (bit & 1) ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
}

__attribute__((used)) static int cs5535_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
	return ide_pci_init_one(dev, &cs5535_chipset, NULL);
}


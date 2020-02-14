#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  unsigned int u32 ;
typedef  int u16 ;
struct sc1200_saved_state {int dummy; } ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int dummy; } ;
struct TYPE_18__ {size_t ultra_mask; unsigned long dma_base; TYPE_1__* dma_ops; scalar_t__ channel; int /*<<< orphan*/  dev; } ;
typedef  TYPE_2__ ide_hwif_t ;
struct TYPE_19__ {int dn; int* id; size_t dma_mode; size_t pio_mode; int dev_flags; int /*<<< orphan*/  name; TYPE_2__* hwif; } ;
typedef  TYPE_3__ ide_drive_t ;
struct TYPE_17__ {int /*<<< orphan*/  (* dma_host_set ) (TYPE_3__*,int) ;} ;

/* Variables and functions */
 size_t ATA_ID_FIELD_VALID ; 
 size_t ATA_ID_MWDMA_MODES ; 
 size_t ATA_ID_UDMA_MODES ; 
 int IDE_DFLAG_USING_DMA ; 
 unsigned int PCI_CLK_33 ; 
 unsigned int PCI_CLK_33A ; 
 unsigned char SC1200_REV_B1 ; 
 size_t const XFER_MW_DMA_0 ; 
 int XFER_MW_DMA_1 ; 
 int XFER_MW_DMA_2 ; 
 size_t XFER_PIO_0 ; 
 size_t const XFER_UDMA_0 ; 
 int XFER_UDMA_1 ; 
 int XFER_UDMA_2 ; 
 scalar_t__ __ide_dma_bad_drive (TYPE_3__*) ; 
 scalar_t__ ata_id_has_dma (int*) ; 
 int /*<<< orphan*/  ide_dma_off_quietly (TYPE_3__*) ; 
 TYPE_3__* ide_get_pair_dev (TYPE_3__*) ; 
 int ide_pci_init_one (struct pci_dev*,int /*<<< orphan*/ *,struct sc1200_saved_state*) ; 
 scalar_t__ ide_set_dma_mode (TYPE_3__*,int) ; 
 int inb (unsigned long) ; 
 unsigned int inw (int) ; 
 int /*<<< orphan*/  kfree (struct sc1200_saved_state*) ; 
 int /*<<< orphan*/  outb (int,unsigned long) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  printk (char*,size_t,...) ; 
 int /*<<< orphan*/  sc1200_chipset ; 
 unsigned int** sc1200_pio_timings ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*,int) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned short sc1200_get_pci_clock (void)
{
	unsigned char chip_id, silicon_revision;
	unsigned int pci_clock;
	/*
	 * Check the silicon revision, as not all versions of the chip
	 * have the register with the fast PCI bus timings.
	 */
	chip_id = inb (0x903c);
	silicon_revision = inb (0x903d);

	// Read the fast pci clock frequency
	if (chip_id == 0x04 && silicon_revision < SC1200_REV_B1) {
		pci_clock = PCI_CLK_33;
	} else {
		// check clock generator configuration (cfcc)
		// the clock is in bits 8 and 9 of this word

		pci_clock = inw (0x901e);
		pci_clock >>= 8;
		pci_clock &= 0x03;
		if (pci_clock == PCI_CLK_33A)
			pci_clock = PCI_CLK_33;
	}
	return pci_clock;
}

__attribute__((used)) static void sc1200_tunepio(ide_drive_t *drive, u8 pio)
{
	ide_hwif_t *hwif = drive->hwif;
	struct pci_dev *pdev = to_pci_dev(hwif->dev);
	unsigned int basereg = hwif->channel ? 0x50 : 0x40, format = 0;

	pci_read_config_dword(pdev, basereg + 4, &format);
	format = (format >> 31) & 1;
	if (format)
		format += sc1200_get_pci_clock();
	pci_write_config_dword(pdev, basereg + ((drive->dn & 1) << 3),
			       sc1200_pio_timings[format][pio]);
}

__attribute__((used)) static u8 sc1200_udma_filter(ide_drive_t *drive)
{
	ide_hwif_t *hwif = drive->hwif;
	ide_drive_t *mate = ide_get_pair_dev(drive);
	u16 *mateid;
	u8 mask = hwif->ultra_mask;

	if (mate == NULL)
		goto out;
	mateid = mate->id;

	if (ata_id_has_dma(mateid) && __ide_dma_bad_drive(mate) == 0) {
		if ((mateid[ATA_ID_FIELD_VALID] & 4) &&
		    (mateid[ATA_ID_UDMA_MODES] & 7))
			goto out;
		if (mateid[ATA_ID_MWDMA_MODES] & 7)
			mask = 0;
	}
out:
	return mask;
}

__attribute__((used)) static void sc1200_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	struct pci_dev		*dev = to_pci_dev(hwif->dev);
	unsigned int		reg, timings;
	unsigned short		pci_clock;
	unsigned int		basereg = hwif->channel ? 0x50 : 0x40;
	const u8		mode = drive->dma_mode;

	static const u32 udma_timing[3][3] = {
		{ 0x00921250, 0x00911140, 0x00911030 },
		{ 0x00932470, 0x00922260, 0x00922140 },
		{ 0x009436a1, 0x00933481, 0x00923261 },
	};

	static const u32 mwdma_timing[3][3] = {
		{ 0x00077771, 0x00012121, 0x00002020 },
		{ 0x000bbbb2, 0x00024241, 0x00013131 },
		{ 0x000ffff3, 0x00035352, 0x00015151 },
	};

	pci_clock = sc1200_get_pci_clock();

	/*
	 * Note that each DMA mode has several timings associated with it.
	 * The correct timing depends on the fast PCI clock freq.
	 */

	if (mode >= XFER_UDMA_0)
		timings =  udma_timing[pci_clock][mode - XFER_UDMA_0];
	else
		timings = mwdma_timing[pci_clock][mode - XFER_MW_DMA_0];

	if ((drive->dn & 1) == 0) {
		pci_read_config_dword(dev, basereg + 4, &reg);
		timings |= reg & 0x80000000;	/* preserve PIO format bit */
		pci_write_config_dword(dev, basereg + 4, timings);
	} else
		pci_write_config_dword(dev, basereg + 12, timings);
}

__attribute__((used)) static int sc1200_dma_end(ide_drive_t *drive)
{
	ide_hwif_t *hwif = drive->hwif;
	unsigned long dma_base = hwif->dma_base;
	u8 dma_stat;

	dma_stat = inb(dma_base+2);		/* get DMA status */

	if (!(dma_stat & 4))
		printk(" ide_dma_end dma_stat=%0x err=%x newerr=%x\n",
		  dma_stat, ((dma_stat&7)!=4), ((dma_stat&2)==2));

	outb(dma_stat|0x1b, dma_base+2);	/* clear the INTR & ERROR bits */
	outb(inb(dma_base)&~1, dma_base);	/* !! DO THIS HERE !! stop DMA */

	return (dma_stat & 7) != 4;		/* verify good DMA status */
}

__attribute__((used)) static void sc1200_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	int		mode = -1;
	const u8	pio = drive->pio_mode - XFER_PIO_0;

	/*
	 * bad abuse of ->set_pio_mode interface
	 */
	switch (pio) {
		case 200: mode = XFER_UDMA_0;	break;
		case 201: mode = XFER_UDMA_1;	break;
		case 202: mode = XFER_UDMA_2;	break;
		case 100: mode = XFER_MW_DMA_0;	break;
		case 101: mode = XFER_MW_DMA_1;	break;
		case 102: mode = XFER_MW_DMA_2;	break;
	}
	if (mode != -1) {
		printk("SC1200: %s: changing (U)DMA mode\n", drive->name);
		ide_dma_off_quietly(drive);
		if (ide_set_dma_mode(drive, mode) == 0 &&
		    (drive->dev_flags & IDE_DFLAG_USING_DMA))
			hwif->dma_ops->dma_host_set(drive, 1);
		return;
	}

	sc1200_tunepio(drive, pio);
}

__attribute__((used)) static int sc1200_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
	struct sc1200_saved_state *ss = NULL;
	int rc;

#ifdef CONFIG_PM
	ss = kmalloc(sizeof(*ss), GFP_KERNEL);
	if (ss == NULL)
		return -ENOMEM;
#endif
	rc = ide_pci_init_one(dev, &sc1200_chipset, ss);
	if (rc)
		kfree(ss);

	return rc;
}


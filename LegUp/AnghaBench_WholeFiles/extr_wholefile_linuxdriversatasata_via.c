#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct pci_dev {int device; } ;
struct ata_taskfile {scalar_t__ ctl; int /*<<< orphan*/  flags; } ;
struct TYPE_12__ {scalar_t__ command; } ;
struct ata_queued_cmd {TYPE_6__* scsicmd; TYPE_5__ tf; struct ata_port* ap; } ;
struct TYPE_11__ {int /*<<< orphan*/  action; } ;
struct ata_eh_context {TYPE_4__ i; } ;
struct TYPE_10__ {struct ata_eh_context eh_context; } ;
struct TYPE_8__ {scalar_t__ scr_addr; } ;
struct ata_port {int port_no; scalar_t__ last_ctl; int pflags; TYPE_7__* host; TYPE_3__ link; TYPE_2__* ops; TYPE_1__ ioaddr; } ;
struct ata_link {int pmp; struct ata_port* ap; } ;
struct ata_device {int devno; size_t pio_mode; size_t dma_mode; } ;
struct TYPE_14__ {int /*<<< orphan*/  dev; } ;
struct TYPE_13__ {scalar_t__ sc_data_direction; } ;
struct TYPE_9__ {int /*<<< orphan*/  (* sff_check_status ) (struct ata_port*) ;} ;

/* Variables and functions */
 int ATA_CBL_PATA40 ; 
 int ATA_CBL_PATA80 ; 
 scalar_t__ ATA_CMD_PACKET ; 
 int /*<<< orphan*/  ATA_EH_RESET ; 
 int ATA_PFLAG_LOADING ; 
 int /*<<< orphan*/  ATA_TFLAG_DEVICE ; 
 scalar_t__ DMA_TO_DEVICE ; 
 int EINVAL ; 
 int HZ ; 
 int PATA_PIO_TIMING ; 
 int PATA_UDMA_TIMING ; 
#define  SCR_CONTROL 130 
#define  SCR_ERROR 129 
#define  SCR_STATUS 128 
 int /*<<< orphan*/  WARN_ON (int) ; 
 size_t XFER_PIO_0 ; 
 size_t XFER_UDMA_0 ; 
 int /*<<< orphan*/  ata_bmdma_irq_clear (struct ata_port*) ; 
 int /*<<< orphan*/  ata_bmdma_start (struct ata_queued_cmd*) ; 
 int /*<<< orphan*/  ata_msleep (struct ata_port*,int) ; 
 int /*<<< orphan*/  ata_port_info (struct ata_port*,char*,char*,int,int) ; 
 int /*<<< orphan*/  ata_sff_pause (struct ata_port*) ; 
 int /*<<< orphan*/  ata_sff_tf_load (struct ata_port*,struct ata_taskfile const*) ; 
 int /*<<< orphan*/  ata_sff_wait_ready (struct ata_link*,unsigned long) ; 
 int ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (int,scalar_t__) ; 
 int jiffies ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,int const) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  stub1 (struct ata_port*) ; 
 scalar_t__ time_before (int,unsigned long) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int svia_scr_read(struct ata_link *link, unsigned int sc_reg, u32 *val)
{
	if (sc_reg > SCR_CONTROL)
		return -EINVAL;
	*val = ioread32(link->ap->ioaddr.scr_addr + (4 * sc_reg));
	return 0;
}

__attribute__((used)) static int svia_scr_write(struct ata_link *link, unsigned int sc_reg, u32 val)
{
	if (sc_reg > SCR_CONTROL)
		return -EINVAL;
	iowrite32(val, link->ap->ioaddr.scr_addr + (4 * sc_reg));
	return 0;
}

__attribute__((used)) static int vt8251_scr_read(struct ata_link *link, unsigned int scr, u32 *val)
{
	static const u8 ipm_tbl[] = { 1, 2, 6, 0 };
	struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
	int slot = 2 * link->ap->port_no + link->pmp;
	u32 v = 0;
	u8 raw;

	switch (scr) {
	case SCR_STATUS:
		pci_read_config_byte(pdev, 0xA0 + slot, &raw);

		/* read the DET field, bit0 and 1 of the config byte */
		v |= raw & 0x03;

		/* read the SPD field, bit4 of the configure byte */
		if (raw & (1 << 4))
			v |= 0x02 << 4;
		else
			v |= 0x01 << 4;

		/* read the IPM field, bit2 and 3 of the config byte */
		v |= ipm_tbl[(raw >> 2) & 0x3];
		break;

	case SCR_ERROR:
		/* devices other than 5287 uses 0xA8 as base */
		WARN_ON(pdev->device != 0x5287);
		pci_read_config_dword(pdev, 0xB0 + slot * 4, &v);
		break;

	case SCR_CONTROL:
		pci_read_config_byte(pdev, 0xA4 + slot, &raw);

		/* read the DET field, bit0 and bit1 */
		v |= ((raw & 0x02) << 1) | (raw & 0x01);

		/* read the IPM field, bit2 and bit3 */
		v |= ((raw >> 2) & 0x03) << 8;
		break;

	default:
		return -EINVAL;
	}

	*val = v;
	return 0;
}

__attribute__((used)) static int vt8251_scr_write(struct ata_link *link, unsigned int scr, u32 val)
{
	struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
	int slot = 2 * link->ap->port_no + link->pmp;
	u32 v = 0;

	switch (scr) {
	case SCR_ERROR:
		/* devices other than 5287 uses 0xA8 as base */
		WARN_ON(pdev->device != 0x5287);
		pci_write_config_dword(pdev, 0xB0 + slot * 4, val);
		return 0;

	case SCR_CONTROL:
		/* set the DET field */
		v |= ((val & 0x4) >> 1) | (val & 0x1);

		/* set the IPM field */
		v |= ((val >> 8) & 0x3) << 2;

		pci_write_config_byte(pdev, 0xA4 + slot, v);
		return 0;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static void svia_tf_load(struct ata_port *ap, const struct ata_taskfile *tf)
{
	struct ata_taskfile ttf;

	if (tf->ctl != ap->last_ctl)  {
		ttf = *tf;
		ttf.flags |= ATA_TFLAG_DEVICE;
		tf = &ttf;
	}
	ata_sff_tf_load(ap, tf);
}

__attribute__((used)) static void svia_noop_freeze(struct ata_port *ap)
{
	/* Some VIA controllers choke if ATA_NIEN is manipulated in
	 * certain way.  Leave it alone and just clear pending IRQ.
	 */
	ap->ops->sff_check_status(ap);
	ata_bmdma_irq_clear(ap);
}

__attribute__((used)) static int vt6420_prereset(struct ata_link *link, unsigned long deadline)
{
	struct ata_port *ap = link->ap;
	struct ata_eh_context *ehc = &ap->link.eh_context;
	unsigned long timeout = jiffies + (HZ * 5);
	u32 sstatus, scontrol;
	int online;

	/* don't do any SCR stuff if we're not loading */
	if (!(ap->pflags & ATA_PFLAG_LOADING))
		goto skip_scr;

	/* Resume phy.  This is the old SATA resume sequence */
	svia_scr_write(link, SCR_CONTROL, 0x300);
	svia_scr_read(link, SCR_CONTROL, &scontrol); /* flush */

	/* wait for phy to become ready, if necessary */
	do {
		ata_msleep(link->ap, 200);
		svia_scr_read(link, SCR_STATUS, &sstatus);
		if ((sstatus & 0xf) != 1)
			break;
	} while (time_before(jiffies, timeout));

	/* open code sata_print_link_status() */
	svia_scr_read(link, SCR_STATUS, &sstatus);
	svia_scr_read(link, SCR_CONTROL, &scontrol);

	online = (sstatus & 0xf) == 0x3;

	ata_port_info(ap,
		      "SATA link %s 1.5 Gbps (SStatus %X SControl %X)\n",
		      online ? "up" : "down", sstatus, scontrol);

	/* SStatus is read one more time */
	svia_scr_read(link, SCR_STATUS, &sstatus);

	if (!online) {
		/* tell EH to bail */
		ehc->i.action &= ~ATA_EH_RESET;
		return 0;
	}

 skip_scr:
	/* wait for !BSY */
	ata_sff_wait_ready(link, deadline);

	return 0;
}

__attribute__((used)) static void vt6420_bmdma_start(struct ata_queued_cmd *qc)
{
	struct ata_port *ap = qc->ap;
	if ((qc->tf.command == ATA_CMD_PACKET) &&
	    (qc->scsicmd->sc_data_direction == DMA_TO_DEVICE)) {
		/* Prevents corruption on some ATAPI burners */
		ata_sff_pause(ap);
	}
	ata_bmdma_start(qc);
}

__attribute__((used)) static int vt6421_pata_cable_detect(struct ata_port *ap)
{
	struct pci_dev *pdev = to_pci_dev(ap->host->dev);
	u8 tmp;

	pci_read_config_byte(pdev, PATA_UDMA_TIMING, &tmp);
	if (tmp & 0x10)
		return ATA_CBL_PATA40;
	return ATA_CBL_PATA80;
}

__attribute__((used)) static void vt6421_set_pio_mode(struct ata_port *ap, struct ata_device *adev)
{
	struct pci_dev *pdev = to_pci_dev(ap->host->dev);
	static const u8 pio_bits[] = { 0xA8, 0x65, 0x65, 0x31, 0x20 };
	pci_write_config_byte(pdev, PATA_PIO_TIMING - adev->devno,
			      pio_bits[adev->pio_mode - XFER_PIO_0]);
}

__attribute__((used)) static void vt6421_set_dma_mode(struct ata_port *ap, struct ata_device *adev)
{
	struct pci_dev *pdev = to_pci_dev(ap->host->dev);
	static const u8 udma_bits[] = { 0xEE, 0xE8, 0xE6, 0xE4, 0xE2, 0xE1, 0xE0, 0xE0 };
	pci_write_config_byte(pdev, PATA_UDMA_TIMING - adev->devno,
			      udma_bits[adev->dma_mode - XFER_UDMA_0]);
}


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
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  u_long ;
typedef  int u_int ;
struct seeprom_descriptor {int sd_MS; int sd_CS; int sd_CK; int sd_DO; int sd_chip; int sd_DI; int /*<<< orphan*/  sd_RDY; } ;
struct seeprom_config {int checksum; } ;
struct seeprom_cmd {int len; scalar_t__* bits; } ;
struct scsi_sense_data {int dummy; } ;
struct scsi_cmnd {int result; int sc_data_direction; } ;
struct scb {TYPE_2__* platform_data; struct scsi_cmnd* io_ctx; } ;
struct ahc_softc {char* name; TYPE_3__* platform_data; } ;
struct ahc_devinfo {int dummy; } ;
typedef  scalar_t__ sector_t ;
struct TYPE_6__ {int /*<<< orphan*/  spin_lock; } ;
struct TYPE_5__ {TYPE_1__* dev; int /*<<< orphan*/  sense_resid; int /*<<< orphan*/  xfer_len; } ;
struct TYPE_4__ {int /*<<< orphan*/  qfrozen; } ;

/* Variables and functions */
 scalar_t__ C46 ; 
 scalar_t__ C56_66 ; 
 int CAM_DEV_QFRZN ; 
 int CAM_STATUS_MASK ; 
 int /*<<< orphan*/  CLOCK_PULSE (struct seeprom_descriptor*,int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int /*<<< orphan*/  INTSTAT ; 
 int SEEPROM_DATA_INB (struct seeprom_descriptor*) ; 
 int /*<<< orphan*/  SEEPROM_OUTB (struct seeprom_descriptor*,int) ; 
 int /*<<< orphan*/  ahc_inb (struct ahc_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,scalar_t__) ; 
 int /*<<< orphan*/  scsi_get_resid (struct scsi_cmnd*) ; 
 int /*<<< orphan*/  scsi_set_resid (struct scsi_cmnd*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sector_div (scalar_t__,int) ; 
 struct seeprom_cmd seeprom_ewds ; 
 struct seeprom_cmd seeprom_ewen ; 
 struct seeprom_cmd seeprom_long_ewds ; 
 struct seeprom_cmd seeprom_long_ewen ; 
 struct seeprom_cmd seeprom_read ; 
 struct seeprom_cmd seeprom_write ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline int
aic_sector_div(sector_t capacity, int heads, int sectors)
{
	/* ugly, ugly sector_div calling convention.. */
	sector_div(capacity, (heads * sectors));
	return (int)capacity;
}

__attribute__((used)) static inline uint32_t
scsi_4btoul(uint8_t *bytes)
{
	uint32_t rv;

	rv = (bytes[0] << 24) |
	     (bytes[1] << 16) |
	     (bytes[2] << 8) |
	     bytes[3];
	return (rv);
}

__attribute__((used)) static inline void
ahc_scb_timer_reset(struct scb *scb, u_int usec)
{
}

__attribute__((used)) static inline void
ahc_lockinit(struct ahc_softc *ahc)
{
	spin_lock_init(&ahc->platform_data->spin_lock);
}

__attribute__((used)) static inline void
ahc_lock(struct ahc_softc *ahc, unsigned long *flags)
{
	spin_lock_irqsave(&ahc->platform_data->spin_lock, *flags);
}

__attribute__((used)) static inline void
ahc_unlock(struct ahc_softc *ahc, unsigned long *flags)
{
	spin_unlock_irqrestore(&ahc->platform_data->spin_lock, *flags);
}

__attribute__((used)) static inline int	ahc_linux_eisa_init(void) {
	return -ENODEV;
}

__attribute__((used)) static inline void	ahc_linux_eisa_exit(void) {
}

__attribute__((used)) static inline int ahc_linux_pci_init(void) {
	return 0;
}

__attribute__((used)) static inline void ahc_linux_pci_exit(void) {
}

__attribute__((used)) static inline void
ahc_flush_device_writes(struct ahc_softc *ahc)
{
	/* XXX Is this sufficient for all architectures??? */
	ahc_inb(ahc, INTSTAT);
}

__attribute__((used)) static inline
void ahc_cmd_set_transaction_status(struct scsi_cmnd *cmd, uint32_t status)
{
	cmd->result &= ~(CAM_STATUS_MASK << 16);
	cmd->result |= status << 16;
}

__attribute__((used)) static inline
void ahc_set_transaction_status(struct scb *scb, uint32_t status)
{
	ahc_cmd_set_transaction_status(scb->io_ctx,status);
}

__attribute__((used)) static inline
void ahc_cmd_set_scsi_status(struct scsi_cmnd *cmd, uint32_t status)
{
	cmd->result &= ~0xFFFF;
	cmd->result |= status;
}

__attribute__((used)) static inline
void ahc_set_scsi_status(struct scb *scb, uint32_t status)
{
	ahc_cmd_set_scsi_status(scb->io_ctx, status);
}

__attribute__((used)) static inline
uint32_t ahc_cmd_get_transaction_status(struct scsi_cmnd *cmd)
{
	return ((cmd->result >> 16) & CAM_STATUS_MASK);
}

__attribute__((used)) static inline
uint32_t ahc_get_transaction_status(struct scb *scb)
{
	return (ahc_cmd_get_transaction_status(scb->io_ctx));
}

__attribute__((used)) static inline
uint32_t ahc_cmd_get_scsi_status(struct scsi_cmnd *cmd)
{
	return (cmd->result & 0xFFFF);
}

__attribute__((used)) static inline
uint32_t ahc_get_scsi_status(struct scb *scb)
{
	return (ahc_cmd_get_scsi_status(scb->io_ctx));
}

__attribute__((used)) static inline
void ahc_set_transaction_tag(struct scb *scb, int enabled, u_int type)
{
	/*
	 * Nothing to do for linux as the incoming transaction
	 * has no concept of tag/non tagged, etc.
	 */
}

__attribute__((used)) static inline
u_long ahc_get_transfer_length(struct scb *scb)
{
	return (scb->platform_data->xfer_len);
}

__attribute__((used)) static inline
int ahc_get_transfer_dir(struct scb *scb)
{
	return (scb->io_ctx->sc_data_direction);
}

__attribute__((used)) static inline
void ahc_set_residual(struct scb *scb, u_long resid)
{
	scsi_set_resid(scb->io_ctx, resid);
}

__attribute__((used)) static inline
void ahc_set_sense_residual(struct scb *scb, u_long resid)
{
	scb->platform_data->sense_resid = resid;
}

__attribute__((used)) static inline
u_long ahc_get_residual(struct scb *scb)
{
	return scsi_get_resid(scb->io_ctx);
}

__attribute__((used)) static inline
u_long ahc_get_sense_residual(struct scb *scb)
{
	return (scb->platform_data->sense_resid);
}

__attribute__((used)) static inline
int ahc_perform_autosense(struct scb *scb)
{
	/*
	 * We always perform autosense in Linux.
	 * On other platforms this is set on a
	 * per-transaction basis.
	 */
	return (1);
}

__attribute__((used)) static inline uint32_t
ahc_get_sense_bufsize(struct ahc_softc *ahc, struct scb *scb)
{
	return (sizeof(struct scsi_sense_data));
}

__attribute__((used)) static inline void
ahc_notify_xfer_settings_change(struct ahc_softc *ahc,
				struct ahc_devinfo *devinfo)
{
	/* Nothing to do here for linux */
}

__attribute__((used)) static inline void
ahc_platform_scb_free(struct ahc_softc *ahc, struct scb *scb)
{
}

__attribute__((used)) static inline void
ahc_freeze_scb(struct scb *scb)
{
	if ((scb->io_ctx->result & (CAM_DEV_QFRZN << 16)) == 0) {
                scb->io_ctx->result |= CAM_DEV_QFRZN << 16;
                scb->platform_data->dev->qfrozen++;
        }
}

__attribute__((used)) static inline char *ahc_name(struct ahc_softc *ahc)
{
	return (ahc->name);
}

__attribute__((used)) static void
send_seeprom_cmd(struct seeprom_descriptor *sd, const struct seeprom_cmd *cmd)
{
	uint8_t temp;
	int i = 0;

	/* Send chip select for one clock cycle. */
	temp = sd->sd_MS ^ sd->sd_CS;
	SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
	CLOCK_PULSE(sd, sd->sd_RDY);

	for (i = 0; i < cmd->len; i++) {
		if (cmd->bits[i] != 0)
			temp ^= sd->sd_DO;
		SEEPROM_OUTB(sd, temp);
		CLOCK_PULSE(sd, sd->sd_RDY);
		SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
		CLOCK_PULSE(sd, sd->sd_RDY);
		if (cmd->bits[i] != 0)
			temp ^= sd->sd_DO;
	}
}

__attribute__((used)) static void
reset_seeprom(struct seeprom_descriptor *sd)
{
	uint8_t temp;

	temp = sd->sd_MS;
	SEEPROM_OUTB(sd, temp);
	CLOCK_PULSE(sd, sd->sd_RDY);
	SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
	CLOCK_PULSE(sd, sd->sd_RDY);
	SEEPROM_OUTB(sd, temp);
	CLOCK_PULSE(sd, sd->sd_RDY);
}

int
ahc_read_seeprom(struct seeprom_descriptor *sd, uint16_t *buf,
		 u_int start_addr, u_int count)
{
	int i = 0;
	u_int k = 0;
	uint16_t v;
	uint8_t temp;

	/*
	 * Read the requested registers of the seeprom.  The loop
	 * will range from 0 to count-1.
	 */
	for (k = start_addr; k < count + start_addr; k++) {
		/*
		 * Now we're ready to send the read command followed by the
		 * address of the 16-bit register we want to read.
		 */
		send_seeprom_cmd(sd, &seeprom_read);

		/* Send the 6 or 8 bit address (MSB first, LSB last). */
		temp = sd->sd_MS ^ sd->sd_CS;
		for (i = (sd->sd_chip - 1); i >= 0; i--) {
			if ((k & (1 << i)) != 0)
				temp ^= sd->sd_DO;
			SEEPROM_OUTB(sd, temp);
			CLOCK_PULSE(sd, sd->sd_RDY);
			SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
			CLOCK_PULSE(sd, sd->sd_RDY);
			if ((k & (1 << i)) != 0)
				temp ^= sd->sd_DO;
		}

		/*
		 * Now read the 16 bit register.  An initial 0 precedes the
		 * register contents which begins with bit 15 (MSB) and ends
		 * with bit 0 (LSB).  The initial 0 will be shifted off the
		 * top of our word as we let the loop run from 0 to 16.
		 */
		v = 0;
		for (i = 16; i >= 0; i--) {
			SEEPROM_OUTB(sd, temp);
			CLOCK_PULSE(sd, sd->sd_RDY);
			v <<= 1;
			if (SEEPROM_DATA_INB(sd) & sd->sd_DI)
				v |= 1;
			SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
			CLOCK_PULSE(sd, sd->sd_RDY);
		}

		buf[k - start_addr] = v;

		/* Reset the chip select for the next command cycle. */
		reset_seeprom(sd);
	}
#ifdef AHC_DUMP_EEPROM
	printk("\nSerial EEPROM:\n\t");
	for (k = 0; k < count; k = k + 1) {
		if (((k % 8) == 0) && (k != 0)) {
			printk(KERN_CONT "\n\t");
		}
		printk(KERN_CONT " 0x%x", buf[k]);
	}
	printk(KERN_CONT "\n");
#endif
	return (1);
}

int
ahc_write_seeprom(struct seeprom_descriptor *sd, uint16_t *buf,
		  u_int start_addr, u_int count)
{
	const struct seeprom_cmd *ewen, *ewds;
	uint16_t v;
	uint8_t temp;
	int i, k;

	/* Place the chip into write-enable mode */
	if (sd->sd_chip == C46) {
		ewen = &seeprom_ewen;
		ewds = &seeprom_ewds;
	} else if (sd->sd_chip == C56_66) {
		ewen = &seeprom_long_ewen;
		ewds = &seeprom_long_ewds;
	} else {
		printk("ahc_write_seeprom: unsupported seeprom type %d\n",
		       sd->sd_chip);
		return (0);
	}

	send_seeprom_cmd(sd, ewen);
	reset_seeprom(sd);

	/* Write all requested data out to the seeprom. */
	temp = sd->sd_MS ^ sd->sd_CS;
	for (k = start_addr; k < count + start_addr; k++) {
		/* Send the write command */
		send_seeprom_cmd(sd, &seeprom_write);

		/* Send the 6 or 8 bit address (MSB first). */
		for (i = (sd->sd_chip - 1); i >= 0; i--) {
			if ((k & (1 << i)) != 0)
				temp ^= sd->sd_DO;
			SEEPROM_OUTB(sd, temp);
			CLOCK_PULSE(sd, sd->sd_RDY);
			SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
			CLOCK_PULSE(sd, sd->sd_RDY);
			if ((k & (1 << i)) != 0)
				temp ^= sd->sd_DO;
		}

		/* Write the 16 bit value, MSB first */
		v = buf[k - start_addr];
		for (i = 15; i >= 0; i--) {
			if ((v & (1 << i)) != 0)
				temp ^= sd->sd_DO;
			SEEPROM_OUTB(sd, temp);
			CLOCK_PULSE(sd, sd->sd_RDY);
			SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
			CLOCK_PULSE(sd, sd->sd_RDY);
			if ((v & (1 << i)) != 0)
				temp ^= sd->sd_DO;
		}

		/* Wait for the chip to complete the write */
		temp = sd->sd_MS;
		SEEPROM_OUTB(sd, temp);
		CLOCK_PULSE(sd, sd->sd_RDY);
		temp = sd->sd_MS ^ sd->sd_CS;
		do {
			SEEPROM_OUTB(sd, temp);
			CLOCK_PULSE(sd, sd->sd_RDY);
			SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
			CLOCK_PULSE(sd, sd->sd_RDY);
		} while ((SEEPROM_DATA_INB(sd) & sd->sd_DI) == 0);

		reset_seeprom(sd);
	}

	/* Put the chip back into write-protect mode */
	send_seeprom_cmd(sd, ewds);
	reset_seeprom(sd);

	return (1);
}

int
ahc_verify_cksum(struct seeprom_config *sc)
{
	int i;
	int maxaddr;
	uint32_t checksum;
	uint16_t *scarray;

	maxaddr = (sizeof(*sc)/2) - 1;
	checksum = 0;
	scarray = (uint16_t *)sc;

	for (i = 0; i < maxaddr; i++)
		checksum = checksum + scarray[i];
	if (checksum == 0
	 || (checksum & 0xFFFF) != sc->checksum) {
		return (0);
	} else {
		return(1);
	}
}


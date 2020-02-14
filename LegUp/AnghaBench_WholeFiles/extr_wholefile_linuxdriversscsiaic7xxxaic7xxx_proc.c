#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  char* uint16_t ;
typedef  unsigned long u_long ;
typedef  int /*<<< orphan*/  u_int16_t ;
typedef  scalar_t__ u_int ;
typedef  int /*<<< orphan*/  u8 ;
struct seq_file {int dummy; } ;
struct seeprom_descriptor {int /*<<< orphan*/  sd_DI; int /*<<< orphan*/  sd_DO; int /*<<< orphan*/  sd_CK; int /*<<< orphan*/  sd_CS; int /*<<< orphan*/  sd_RDY; scalar_t__ sd_MS; int /*<<< orphan*/  sd_chip; void* sd_dataout_offset; void* sd_status_offset; int /*<<< orphan*/  sd_control_offset; struct ahc_softc* sd_ahc; } ;
struct seeprom_config {int dummy; } ;
struct scsi_target {int dummy; } ;
struct scsi_sense_data {int dummy; } ;
struct scsi_device {scalar_t__ lun; TYPE_4__* sdev_target; } ;
struct scsi_cmnd {int result; int sc_data_direction; } ;
struct scb {TYPE_2__* platform_data; struct scsi_cmnd* io_ctx; } ;
struct ahc_transinfo {scalar_t__ offset; scalar_t__ period; int width; int ppr_options; } ;
struct ahc_tmode_tstate {int dummy; } ;
struct ahc_softc {char* name; int features; int chip; char channel; char* description; scalar_t__ our_id; scalar_t__ our_id_b; int /*<<< orphan*/ * seep_config; TYPE_5__* scb_data; TYPE_3__* platform_data; } ;
struct ahc_linux_device {char* commands_issued; char* active; char* openings; char* maxtags; char* qfrozen; } ;
struct ahc_initiator_tinfo {struct ahc_transinfo curr; struct ahc_transinfo goal; struct ahc_transinfo user; } ;
struct ahc_devinfo {int dummy; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  scalar_t__ sector_t ;
struct TYPE_13__ {scalar_t__ period_factor; int period; } ;
struct TYPE_12__ {int /*<<< orphan*/  numscbs; } ;
struct TYPE_11__ {char channel; int /*<<< orphan*/  id; } ;
struct TYPE_10__ {struct scsi_target** starget; int /*<<< orphan*/  spin_lock; } ;
struct TYPE_9__ {unsigned long xfer_len; unsigned long sense_resid; TYPE_1__* dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  qfrozen; } ;

/* Variables and functions */
 int /*<<< orphan*/  AHC_NSEG ; 
 int AHC_NUM_LUNS ; 
 int AHC_TWIN ; 
 int AHC_VL ; 
 int AHC_WIDE ; 
 char* AIC7XXX_DRIVER_VERSION ; 
 int ARRAY_SIZE (TYPE_6__*) ; 
 int /*<<< orphan*/  C46 ; 
 int CAM_DEV_QFRZN ; 
 int CAM_STATUS_MASK ; 
 int /*<<< orphan*/  CK_2840 ; 
 int /*<<< orphan*/  CS_2840 ; 
 int /*<<< orphan*/  DI_2840 ; 
 int /*<<< orphan*/  DO_2840 ; 
 int /*<<< orphan*/  EEPROM_TF ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  INTSTAT ; 
 int MSG_EXT_PPR_DT_REQ ; 
 int /*<<< orphan*/  SEECTL_2840 ; 
 void* STATUS_2840 ; 
 int TRUE ; 
 int /*<<< orphan*/  ahc_controller_info (struct ahc_softc*,char*) ; 
static  void ahc_dump_device_state (struct seq_file*,struct scsi_device*) ; 
 struct ahc_initiator_tinfo* ahc_fetch_transinfo (struct ahc_softc*,char,scalar_t__,scalar_t__,struct ahc_tmode_tstate**) ; 
 int /*<<< orphan*/  ahc_inb (struct ahc_softc*,int /*<<< orphan*/ ) ; 
 int ahc_is_paused (struct ahc_softc*) ; 
 int /*<<< orphan*/  ahc_pause (struct ahc_softc*) ; 
 int /*<<< orphan*/  ahc_read_seeprom (struct seeprom_descriptor*,char**,scalar_t__,int) ; 
 int /*<<< orphan*/  ahc_unpause (struct ahc_softc*) ; 
 int ahc_verify_cksum (struct seeprom_config*) ; 
 int /*<<< orphan*/  ahc_write_seeprom (struct seeprom_descriptor*,int /*<<< orphan*/ *,scalar_t__,int) ; 
 int /*<<< orphan*/ * kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*) ; 
 struct scsi_device* scsi_device_lookup_by_target (struct scsi_target*,int) ; 
 unsigned long scsi_get_resid (struct scsi_cmnd*) ; 
 int /*<<< orphan*/  scsi_set_resid (struct scsi_cmnd*,unsigned long) ; 
 TYPE_6__* scsi_syncrates ; 
 struct ahc_linux_device* scsi_transport_device_data (struct scsi_device*) ; 
 int /*<<< orphan*/  sector_div (scalar_t__,int) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  seq_putc (struct seq_file*,char) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
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

__attribute__((used)) static u_int
ahc_calc_syncsrate(u_int period_factor)
{
	int i;

	/* See if the period is in the "exception" table */
	for (i = 0; i < ARRAY_SIZE(scsi_syncrates); i++) {

		if (period_factor == scsi_syncrates[i].period_factor) {
			/* Period in kHz */
			return (100000000 / scsi_syncrates[i].period);
		}
	}

	/*
	 * Wasn't in the table, so use the standard
	 * 4 times conversion.
	 */
	return (10000000 / (period_factor * 4 * 10));
}

__attribute__((used)) static void
ahc_format_transinfo(struct seq_file *m, struct ahc_transinfo *tinfo)
{
	u_int speed;
	u_int freq;
	u_int mb;

        speed = 3300;
        freq = 0;
	if (tinfo->offset != 0) {
		freq = ahc_calc_syncsrate(tinfo->period);
		speed = freq;
	}
	speed *= (0x01 << tinfo->width);
        mb = speed / 1000;
        if (mb > 0)
		seq_printf(m, "%d.%03dMB/s transfers", mb, speed % 1000);
        else
		seq_printf(m, "%dKB/s transfers", speed);

	if (freq != 0) {
		seq_printf(m, " (%d.%03dMHz%s, offset %d",
			 freq / 1000, freq % 1000,
			 (tinfo->ppr_options & MSG_EXT_PPR_DT_REQ) != 0
			 ? " DT" : "", tinfo->offset);
	}

	if (tinfo->width > 0) {
		if (freq != 0) {
			seq_puts(m, ", ");
		} else {
			seq_puts(m, " (");
		}
		seq_printf(m, "%dbit)", 8 * (0x01 << tinfo->width));
	} else if (freq != 0) {
		seq_putc(m, ')');
	}
	seq_putc(m, '\n');
}

__attribute__((used)) static void
ahc_dump_target_state(struct ahc_softc *ahc, struct seq_file *m,
		      u_int our_id, char channel, u_int target_id,
		      u_int target_offset)
{
	struct	scsi_target *starget;
	struct	ahc_initiator_tinfo *tinfo;
	struct	ahc_tmode_tstate *tstate;
	int	lun;

	tinfo = ahc_fetch_transinfo(ahc, channel, our_id,
				    target_id, &tstate);
	if ((ahc->features & AHC_TWIN) != 0)
		seq_printf(m, "Channel %c ", channel);
	seq_printf(m, "Target %d Negotiation Settings\n", target_id);
	seq_puts(m, "\tUser: ");
	ahc_format_transinfo(m, &tinfo->user);
	starget = ahc->platform_data->starget[target_offset];
	if (!starget)
		return;

	seq_puts(m, "\tGoal: ");
	ahc_format_transinfo(m, &tinfo->goal);
	seq_puts(m, "\tCurr: ");
	ahc_format_transinfo(m, &tinfo->curr);

	for (lun = 0; lun < AHC_NUM_LUNS; lun++) {
		struct scsi_device *sdev;

		sdev = scsi_device_lookup_by_target(starget, lun);

		if (sdev == NULL)
			continue;

		ahc_dump_device_state(m, sdev);
	}
}

__attribute__((used)) static void
ahc_dump_device_state(struct seq_file *m, struct scsi_device *sdev)
{
	struct ahc_linux_device *dev = scsi_transport_device_data(sdev);

	seq_printf(m, "\tChannel %c Target %d Lun %d Settings\n",
		  sdev->sdev_target->channel + 'A',
		   sdev->sdev_target->id, (u8)sdev->lun);

	seq_printf(m, "\t\tCommands Queued %ld\n", dev->commands_issued);
	seq_printf(m, "\t\tCommands Active %d\n", dev->active);
	seq_printf(m, "\t\tCommand Openings %d\n", dev->openings);
	seq_printf(m, "\t\tMax Tagged Openings %d\n", dev->maxtags);
	seq_printf(m, "\t\tDevice Queue Frozen Count %d\n", dev->qfrozen);
}

int
ahc_proc_write_seeprom(struct Scsi_Host *shost, char *buffer, int length)
{
	struct	ahc_softc *ahc = *(struct ahc_softc **)shost->hostdata;
	struct seeprom_descriptor sd;
	int have_seeprom;
	u_long s;
	int paused;
	int written;

	/* Default to failure. */
	written = -EINVAL;
	ahc_lock(ahc, &s);
	paused = ahc_is_paused(ahc);
	if (!paused)
		ahc_pause(ahc);

	if (length != sizeof(struct seeprom_config)) {
		printk("ahc_proc_write_seeprom: incorrect buffer size\n");
		goto done;
	}

	have_seeprom = ahc_verify_cksum((struct seeprom_config*)buffer);
	if (have_seeprom == 0) {
		printk("ahc_proc_write_seeprom: cksum verification failed\n");
		goto done;
	}

	sd.sd_ahc = ahc;
#if AHC_PCI_CONFIG > 0
	if ((ahc->chip & AHC_PCI) != 0) {
		sd.sd_control_offset = SEECTL;
		sd.sd_status_offset = SEECTL;
		sd.sd_dataout_offset = SEECTL;
		if (ahc->flags & AHC_LARGE_SEEPROM)
			sd.sd_chip = C56_66;
		else
			sd.sd_chip = C46;
		sd.sd_MS = SEEMS;
		sd.sd_RDY = SEERDY;
		sd.sd_CS = SEECS;
		sd.sd_CK = SEECK;
		sd.sd_DO = SEEDO;
		sd.sd_DI = SEEDI;
		have_seeprom = ahc_acquire_seeprom(ahc, &sd);
	} else
#endif
	if ((ahc->chip & AHC_VL) != 0) {
		sd.sd_control_offset = SEECTL_2840;
		sd.sd_status_offset = STATUS_2840;
		sd.sd_dataout_offset = STATUS_2840;		
		sd.sd_chip = C46;
		sd.sd_MS = 0;
		sd.sd_RDY = EEPROM_TF;
		sd.sd_CS = CS_2840;
		sd.sd_CK = CK_2840;
		sd.sd_DO = DO_2840;
		sd.sd_DI = DI_2840;
		have_seeprom = TRUE;
	} else {
		printk("ahc_proc_write_seeprom: unsupported adapter type\n");
		goto done;
	}

	if (!have_seeprom) {
		printk("ahc_proc_write_seeprom: No Serial EEPROM\n");
		goto done;
	} else {
		u_int start_addr;

		if (ahc->seep_config == NULL) {
			ahc->seep_config = kmalloc(sizeof(*ahc->seep_config), GFP_ATOMIC);
			if (ahc->seep_config == NULL) {
				printk("aic7xxx: Unable to allocate serial "
				       "eeprom buffer.  Write failing\n");
				goto done;
			}
		}
		printk("aic7xxx: Writing Serial EEPROM\n");
		start_addr = 32 * (ahc->channel - 'A');
		ahc_write_seeprom(&sd, (u_int16_t *)buffer, start_addr,
				  sizeof(struct seeprom_config)/2);
		ahc_read_seeprom(&sd, (uint16_t *)ahc->seep_config,
				 start_addr, sizeof(struct seeprom_config)/2);
#if AHC_PCI_CONFIG > 0
		if ((ahc->chip & AHC_VL) == 0)
			ahc_release_seeprom(&sd);
#endif
		written = length;
	}

done:
	if (!paused)
		ahc_unpause(ahc);
	ahc_unlock(ahc, &s);
	return (written);
}

int
ahc_linux_show_info(struct seq_file *m, struct Scsi_Host *shost)
{
	struct	ahc_softc *ahc = *(struct ahc_softc **)shost->hostdata;
	char	ahc_info[256];
	u_int	max_targ;
	u_int	i;

	seq_printf(m, "Adaptec AIC7xxx driver version: %s\n",
		  AIC7XXX_DRIVER_VERSION);
	seq_printf(m, "%s\n", ahc->description);
	ahc_controller_info(ahc, ahc_info);
	seq_printf(m, "%s\n", ahc_info);
	seq_printf(m, "Allocated SCBs: %d, SG List Length: %d\n\n",
		  ahc->scb_data->numscbs, AHC_NSEG);


	if (ahc->seep_config == NULL)
		seq_puts(m, "No Serial EEPROM\n");
	else {
		seq_puts(m, "Serial EEPROM:\n");
		for (i = 0; i < sizeof(*ahc->seep_config)/2; i++) {
			if (((i % 8) == 0) && (i != 0)) {
				seq_putc(m, '\n');
			}
			seq_printf(m, "0x%.4x ",
				  ((uint16_t*)ahc->seep_config)[i]);
		}
		seq_putc(m, '\n');
	}
	seq_putc(m, '\n');

	max_targ = 16;
	if ((ahc->features & (AHC_WIDE|AHC_TWIN)) == 0)
		max_targ = 8;

	for (i = 0; i < max_targ; i++) {
		u_int our_id;
		u_int target_id;
		char channel;

		channel = 'A';
		our_id = ahc->our_id;
		target_id = i;
		if (i > 7 && (ahc->features & AHC_TWIN) != 0) {
			channel = 'B';
			our_id = ahc->our_id_b;
			target_id = i % 8;
		}

		ahc_dump_target_state(ahc, m, our_id,
				      channel, target_id, i);
	}
	return 0;
}


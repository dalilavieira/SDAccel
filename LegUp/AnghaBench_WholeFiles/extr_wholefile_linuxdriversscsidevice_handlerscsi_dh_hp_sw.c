#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u64 ;
struct scsi_sense_hdr {int sense_key; int asc; int ascq; } ;
struct scsi_device {struct hp_sw_dh_data* handler_data; } ;
struct request {int /*<<< orphan*/  rq_flags; } ;
struct hp_sw_dh_data {scalar_t__ path_state; struct scsi_device* sdev; void* retries; } ;
typedef  int /*<<< orphan*/  (* activate_complete ) (void*,int) ;

/* Variables and functions */
 int BLKPREP_KILL ; 
 int BLKPREP_OK ; 
 int /*<<< orphan*/  DMA_NONE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HP_SW_NAME ; 
 scalar_t__ HP_SW_PATH_ACTIVE ; 
 scalar_t__ HP_SW_PATH_PASSIVE ; 
 scalar_t__ HP_SW_PATH_UNINITIALIZED ; 
 void* HP_SW_RETRIES ; 
 int /*<<< orphan*/  HP_SW_TIMEOUT ; 
 int /*<<< orphan*/  KERN_INFO ; 
 int /*<<< orphan*/  KERN_WARNING ; 
#define  NOT_READY 129 
 int REQ_FAILFAST_DEV ; 
 int REQ_FAILFAST_DRIVER ; 
 int REQ_FAILFAST_TRANSPORT ; 
 int /*<<< orphan*/  RQF_QUIET ; 
 int SCSI_DH_IMM_RETRY ; 
 int SCSI_DH_IO ; 
 int SCSI_DH_NOMEM ; 
 int SCSI_DH_NOSYS ; 
 int SCSI_DH_OK ; 
 int SCSI_DH_RETRY ; 
 int START_STOP ; 
 unsigned char TEST_UNIT_READY ; 
#define  UNIT_ATTENTION 128 
 int /*<<< orphan*/  kfree (struct hp_sw_dh_data*) ; 
 struct hp_sw_dh_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int scsi_execute (struct scsi_device*,unsigned char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct scsi_sense_hdr*,int /*<<< orphan*/ ,void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ scsi_sense_valid (struct scsi_sense_hdr*) ; 
 int /*<<< orphan*/  sdev_printk (int /*<<< orphan*/ ,struct scsi_device*,char*,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static int tur_done(struct scsi_device *sdev, struct hp_sw_dh_data *h,
		    struct scsi_sense_hdr *sshdr)
{
	int ret = SCSI_DH_IO;

	switch (sshdr->sense_key) {
	case UNIT_ATTENTION:
		ret = SCSI_DH_IMM_RETRY;
		break;
	case NOT_READY:
		if (sshdr->asc == 0x04 && sshdr->ascq == 2) {
			/*
			 * LUN not ready - Initialization command required
			 *
			 * This is the passive path
			 */
			h->path_state = HP_SW_PATH_PASSIVE;
			ret = SCSI_DH_OK;
			break;
		}
		/* Fallthrough */
	default:
		sdev_printk(KERN_WARNING, sdev,
			   "%s: sending tur failed, sense %x/%x/%x\n",
			   HP_SW_NAME, sshdr->sense_key, sshdr->asc,
			   sshdr->ascq);
		break;
	}
	return ret;
}

__attribute__((used)) static int hp_sw_tur(struct scsi_device *sdev, struct hp_sw_dh_data *h)
{
	unsigned char cmd[6] = { TEST_UNIT_READY };
	struct scsi_sense_hdr sshdr;
	int ret = SCSI_DH_OK, res;
	u64 req_flags = REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
		REQ_FAILFAST_DRIVER;

retry:
	res = scsi_execute(sdev, cmd, DMA_NONE, NULL, 0, NULL, &sshdr,
			HP_SW_TIMEOUT, HP_SW_RETRIES, req_flags, 0, NULL);
	if (res) {
		if (scsi_sense_valid(&sshdr))
			ret = tur_done(sdev, h, &sshdr);
		else {
			sdev_printk(KERN_WARNING, sdev,
				    "%s: sending tur failed with %x\n",
				    HP_SW_NAME, res);
			ret = SCSI_DH_IO;
		}
	} else {
		h->path_state = HP_SW_PATH_ACTIVE;
		ret = SCSI_DH_OK;
	}
	if (ret == SCSI_DH_IMM_RETRY)
		goto retry;

	return ret;
}

__attribute__((used)) static int hp_sw_start_stop(struct hp_sw_dh_data *h)
{
	unsigned char cmd[6] = { START_STOP, 0, 0, 0, 1, 0 };
	struct scsi_sense_hdr sshdr;
	struct scsi_device *sdev = h->sdev;
	int res, rc = SCSI_DH_OK;
	int retry_cnt = HP_SW_RETRIES;
	u64 req_flags = REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
		REQ_FAILFAST_DRIVER;

retry:
	res = scsi_execute(sdev, cmd, DMA_NONE, NULL, 0, NULL, &sshdr,
			HP_SW_TIMEOUT, HP_SW_RETRIES, req_flags, 0, NULL);
	if (res) {
		if (!scsi_sense_valid(&sshdr)) {
			sdev_printk(KERN_WARNING, sdev,
				    "%s: sending start_stop_unit failed, "
				    "no sense available\n", HP_SW_NAME);
			return SCSI_DH_IO;
		}
		switch (sshdr.sense_key) {
		case NOT_READY:
			if (sshdr.asc == 0x04 && sshdr.ascq == 3) {
				/*
				 * LUN not ready - manual intervention required
				 *
				 * Switch-over in progress, retry.
				 */
				if (--retry_cnt)
					goto retry;
				rc = SCSI_DH_RETRY;
				break;
			}
			/* fall through */
		default:
			sdev_printk(KERN_WARNING, sdev,
				    "%s: sending start_stop_unit failed, "
				    "sense %x/%x/%x\n", HP_SW_NAME,
				    sshdr.sense_key, sshdr.asc, sshdr.ascq);
			rc = SCSI_DH_IO;
		}
	}
	return rc;
}

__attribute__((used)) static int hp_sw_prep_fn(struct scsi_device *sdev, struct request *req)
{
	struct hp_sw_dh_data *h = sdev->handler_data;
	int ret = BLKPREP_OK;

	if (h->path_state != HP_SW_PATH_ACTIVE) {
		ret = BLKPREP_KILL;
		req->rq_flags |= RQF_QUIET;
	}
	return ret;

}

__attribute__((used)) static int hp_sw_activate(struct scsi_device *sdev,
				activate_complete fn, void *data)
{
	int ret = SCSI_DH_OK;
	struct hp_sw_dh_data *h = sdev->handler_data;

	ret = hp_sw_tur(sdev, h);

	if (ret == SCSI_DH_OK && h->path_state == HP_SW_PATH_PASSIVE)
		ret = hp_sw_start_stop(h);

	if (fn)
		fn(data, ret);
	return 0;
}

__attribute__((used)) static int hp_sw_bus_attach(struct scsi_device *sdev)
{
	struct hp_sw_dh_data *h;
	int ret;

	h = kzalloc(sizeof(*h), GFP_KERNEL);
	if (!h)
		return SCSI_DH_NOMEM;
	h->path_state = HP_SW_PATH_UNINITIALIZED;
	h->retries = HP_SW_RETRIES;
	h->sdev = sdev;

	ret = hp_sw_tur(sdev, h);
	if (ret != SCSI_DH_OK)
		goto failed;
	if (h->path_state == HP_SW_PATH_UNINITIALIZED) {
		ret = SCSI_DH_NOSYS;
		goto failed;
	}

	sdev_printk(KERN_INFO, sdev, "%s: attached to %s path\n",
		    HP_SW_NAME, h->path_state == HP_SW_PATH_ACTIVE?
		    "active":"passive");

	sdev->handler_data = h;
	return SCSI_DH_OK;
failed:
	kfree(h);
	return ret;
}

__attribute__((used)) static void hp_sw_bus_detach( struct scsi_device *sdev )
{
	kfree(sdev->handler_data);
	sdev->handler_data = NULL;
}


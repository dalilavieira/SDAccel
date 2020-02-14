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
struct firedtv_tuner_status {int ca_initialization_status; scalar_t__ ca_error_flag; int ca_dvb_flag; int ca_module_present_status; int ca_mmi; scalar_t__ ca_application_info; int ca_date_time_request; } ;
struct firedtv {int ca_last_command; int /*<<< orphan*/  cadev; int /*<<< orphan*/  ca_time_interval; int /*<<< orphan*/  device; int /*<<< orphan*/  adapter; } ;
struct file {struct dvb_device* private_data; } ;
struct dvb_device {struct firedtv* priv; } ;
struct device {int dummy; } ;
struct ca_slot_info {scalar_t__ num; int flags; void* type; } ;
struct ca_msg {int* msg; int /*<<< orphan*/  length; } ;
struct ca_caps {int slot_num; int descr_num; int /*<<< orphan*/  descr_type; void* slot_type; } ;
typedef  int /*<<< orphan*/  poll_table ;
typedef  int /*<<< orphan*/  __poll_t ;

/* Variables and functions */
 void* CA_CI ; 
 int CA_CI_MODULE_PRESENT ; 
 int CA_CI_MODULE_READY ; 
 int /*<<< orphan*/  CA_ECD ; 
#define  CA_GET_CAP 136 
#define  CA_GET_MSG 135 
#define  CA_GET_SLOT_INFO 134 
#define  CA_RESET 133 
#define  CA_SEND_MSG 132 
 int /*<<< orphan*/  DVB_DEVICE_CA ; 
 int EACCES ; 
 int EFAULT ; 
 int EINVAL ; 
#define  EN50221_TAG_APP_INFO_ENQUIRY 131 
#define  EN50221_TAG_CA_INFO_ENQUIRY 130 
#define  EN50221_TAG_CA_PMT 129 
#define  EN50221_TAG_ENTER_MENU 128 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  EPOLLIN ; 
 int avc_ca_app_info (struct firedtv*,int*,int /*<<< orphan*/ *) ; 
 int avc_ca_enter_menu (struct firedtv*) ; 
 int avc_ca_get_mmi (struct firedtv*,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avc_ca_get_time_date (struct firedtv*,int /*<<< orphan*/ *) ; 
 int avc_ca_info (struct firedtv*,int*,int /*<<< orphan*/ *) ; 
 int avc_ca_pmt (struct firedtv*,int*,int) ; 
 int avc_ca_reset (struct firedtv*) ; 
 int avc_tuner_status (struct firedtv*,struct firedtv_tuner_status*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int dvb_register_device (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct firedtv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dvb_unregister_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fdtv_ca ; 

__attribute__((used)) static inline int fdtv_register_rc(struct firedtv *fdtv,
				   struct device *dev) { return 0; }

__attribute__((used)) static inline void fdtv_unregister_rc(struct firedtv *fdtv) {}

__attribute__((used)) static inline void fdtv_handle_rc(struct firedtv *fdtv, unsigned int code) {}

__attribute__((used)) static int fdtv_ca_ready(struct firedtv_tuner_status *stat)
{
	return stat->ca_initialization_status	== 1 &&
	       stat->ca_error_flag		== 0 &&
	       stat->ca_dvb_flag		== 1 &&
	       stat->ca_module_present_status	== 1;
}

__attribute__((used)) static int fdtv_get_ca_flags(struct firedtv_tuner_status *stat)
{
	int flags = 0;

	if (stat->ca_module_present_status == 1)
		flags |= CA_CI_MODULE_PRESENT;
	if (stat->ca_initialization_status == 1 &&
	    stat->ca_error_flag            == 0 &&
	    stat->ca_dvb_flag              == 1)
		flags |= CA_CI_MODULE_READY;
	return flags;
}

__attribute__((used)) static int fdtv_ca_get_caps(void *arg)
{
	struct ca_caps *cap = arg;

	cap->slot_num = 1;
	cap->slot_type = CA_CI;
	cap->descr_num = 1;
	cap->descr_type = CA_ECD;
	return 0;
}

__attribute__((used)) static int fdtv_ca_get_slot_info(struct firedtv *fdtv, void *arg)
{
	struct firedtv_tuner_status stat;
	struct ca_slot_info *slot = arg;
	int err;

	err = avc_tuner_status(fdtv, &stat);
	if (err)
		return err;

	if (slot->num != 0)
		return -EACCES;

	slot->type = CA_CI;
	slot->flags = fdtv_get_ca_flags(&stat);
	return 0;
}

__attribute__((used)) static int fdtv_ca_app_info(struct firedtv *fdtv, void *arg)
{
	struct ca_msg *reply = arg;

	return avc_ca_app_info(fdtv, reply->msg, &reply->length);
}

__attribute__((used)) static int fdtv_ca_info(struct firedtv *fdtv, void *arg)
{
	struct ca_msg *reply = arg;

	return avc_ca_info(fdtv, reply->msg, &reply->length);
}

__attribute__((used)) static int fdtv_ca_get_mmi(struct firedtv *fdtv, void *arg)
{
	struct ca_msg *reply = arg;

	return avc_ca_get_mmi(fdtv, reply->msg, &reply->length);
}

__attribute__((used)) static int fdtv_ca_get_msg(struct firedtv *fdtv, void *arg)
{
	struct firedtv_tuner_status stat;
	int err;

	switch (fdtv->ca_last_command) {
	case EN50221_TAG_APP_INFO_ENQUIRY:
		err = fdtv_ca_app_info(fdtv, arg);
		break;
	case EN50221_TAG_CA_INFO_ENQUIRY:
		err = fdtv_ca_info(fdtv, arg);
		break;
	default:
		err = avc_tuner_status(fdtv, &stat);
		if (err)
			break;
		if (stat.ca_mmi == 1)
			err = fdtv_ca_get_mmi(fdtv, arg);
		else {
			dev_info(fdtv->device, "unhandled CA message 0x%08x\n",
				 fdtv->ca_last_command);
			err = -EACCES;
		}
	}
	fdtv->ca_last_command = 0;
	return err;
}

__attribute__((used)) static int fdtv_ca_pmt(struct firedtv *fdtv, void *arg)
{
	struct ca_msg *msg = arg;
	int data_pos;
	int data_length;
	int i;

	data_pos = 4;
	if (msg->msg[3] & 0x80) {
		data_length = 0;
		for (i = 0; i < (msg->msg[3] & 0x7f); i++)
			data_length = (data_length << 8) + msg->msg[data_pos++];
	} else {
		data_length = msg->msg[3];
	}

	return avc_ca_pmt(fdtv, &msg->msg[data_pos], data_length);
}

__attribute__((used)) static int fdtv_ca_send_msg(struct firedtv *fdtv, void *arg)
{
	struct ca_msg *msg = arg;
	int err;

	/* Do we need a semaphore for this? */
	fdtv->ca_last_command =
		(msg->msg[0] << 16) + (msg->msg[1] << 8) + msg->msg[2];
	switch (fdtv->ca_last_command) {
	case EN50221_TAG_CA_PMT:
		err = fdtv_ca_pmt(fdtv, arg);
		break;
	case EN50221_TAG_APP_INFO_ENQUIRY:
		/* handled in ca_get_msg */
		err = 0;
		break;
	case EN50221_TAG_CA_INFO_ENQUIRY:
		/* handled in ca_get_msg */
		err = 0;
		break;
	case EN50221_TAG_ENTER_MENU:
		err = avc_ca_enter_menu(fdtv);
		break;
	default:
		dev_err(fdtv->device, "unhandled CA message 0x%08x\n",
			fdtv->ca_last_command);
		err = -EACCES;
	}
	return err;
}

__attribute__((used)) static int fdtv_ca_ioctl(struct file *file, unsigned int cmd, void *arg)
{
	struct dvb_device *dvbdev = file->private_data;
	struct firedtv *fdtv = dvbdev->priv;
	struct firedtv_tuner_status stat;
	int err;

	switch (cmd) {
	case CA_RESET:
		err = avc_ca_reset(fdtv);
		break;
	case CA_GET_CAP:
		err = fdtv_ca_get_caps(arg);
		break;
	case CA_GET_SLOT_INFO:
		err = fdtv_ca_get_slot_info(fdtv, arg);
		break;
	case CA_GET_MSG:
		err = fdtv_ca_get_msg(fdtv, arg);
		break;
	case CA_SEND_MSG:
		err = fdtv_ca_send_msg(fdtv, arg);
		break;
	default:
		dev_info(fdtv->device, "unhandled CA ioctl %u\n", cmd);
		err = -EOPNOTSUPP;
	}

	/* FIXME Is this necessary? */
	avc_tuner_status(fdtv, &stat);

	return err;
}

__attribute__((used)) static __poll_t fdtv_ca_io_poll(struct file *file, poll_table *wait)
{
	return EPOLLIN;
}

int fdtv_ca_register(struct firedtv *fdtv)
{
	struct firedtv_tuner_status stat;
	int err;

	if (avc_tuner_status(fdtv, &stat))
		return -EINVAL;

	if (!fdtv_ca_ready(&stat))
		return -EFAULT;

	err = dvb_register_device(&fdtv->adapter, &fdtv->cadev,
				  &fdtv_ca, fdtv, DVB_DEVICE_CA, 0);

	if (stat.ca_application_info == 0)
		dev_err(fdtv->device, "CaApplicationInfo is not set\n");
	if (stat.ca_date_time_request == 1)
		avc_ca_get_time_date(fdtv, &fdtv->ca_time_interval);

	return err;
}

void fdtv_ca_release(struct firedtv *fdtv)
{
	dvb_unregister_device(fdtv->cadev);
}


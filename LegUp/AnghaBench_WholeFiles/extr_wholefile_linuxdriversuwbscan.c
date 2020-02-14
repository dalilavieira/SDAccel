#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {unsigned int wEvent; void* bEventType; } ;
struct uwb_rc_evt_confirm {scalar_t__ bResultCode; TYPE_2__ rceb; } ;
struct TYPE_5__ {void* wCommand; void* bCommandType; } ;
struct uwb_rc_cmd_scan {unsigned int bChannelNumber; int bScanState; TYPE_1__ rccb; void* wStartTime; } ;
struct TYPE_7__ {int /*<<< orphan*/  mutex; int /*<<< orphan*/  dev; } ;
struct uwb_rc {unsigned int scanning; int scan_type; TYPE_3__ uwb_dev; } ;
struct uwb_dev {struct uwb_rc* rc; int /*<<< orphan*/  dev; } ;
struct uwb_beca_e {int /*<<< orphan*/  refcnt; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  reply ;
typedef  enum uwb_scan_type { ____Placeholder_uwb_scan_type } uwb_scan_type ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* UWB_RC_CET_GENERAL ; 
 unsigned int UWB_RC_CMD_SCAN ; 
 scalar_t__ UWB_RC_RES_SUCCESS ; 
 unsigned int UWB_SCAN_TOP ; 
 void* cpu_to_le16 (unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  device_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct uwb_rc_cmd_scan*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct uwb_rc_cmd_scan* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,unsigned int,int) ; 
 int sscanf (char const*,char*,unsigned int*,unsigned int*,unsigned int*) ; 
 struct uwb_dev* to_uwb_dev (struct device*) ; 
 int /*<<< orphan*/  uwb_bce_kfree ; 
 int /*<<< orphan*/  uwb_dev_get (TYPE_3__*) ; 
 int /*<<< orphan*/  uwb_dev_put (TYPE_3__*) ; 
 int uwb_rc_cmd (struct uwb_rc*,char*,TYPE_1__*,int,TYPE_2__*,int) ; 
 int /*<<< orphan*/  uwb_rc_strerror (scalar_t__) ; 

__attribute__((used)) static inline struct uwb_rc *__uwb_rc_get(struct uwb_rc *rc)
{
	uwb_dev_get(&rc->uwb_dev);
	return rc;
}

__attribute__((used)) static inline void __uwb_rc_put(struct uwb_rc *rc)
{
	if (rc)
		uwb_dev_put(&rc->uwb_dev);
}

__attribute__((used)) static inline void uwb_bce_get(struct uwb_beca_e *bce)
{
	kref_get(&bce->refcnt);
}

__attribute__((used)) static inline void uwb_bce_put(struct uwb_beca_e *bce)
{
	kref_put(&bce->refcnt, uwb_bce_kfree);
}

__attribute__((used)) static inline void uwb_dev_lock(struct uwb_dev *uwb_dev)
{
	device_lock(&uwb_dev->dev);
}

__attribute__((used)) static inline void uwb_dev_unlock(struct uwb_dev *uwb_dev)
{
	device_unlock(&uwb_dev->dev);
}

int uwb_rc_scan(struct uwb_rc *rc,
		unsigned channel, enum uwb_scan_type type,
		unsigned bpst_offset)
{
	int result;
	struct uwb_rc_cmd_scan *cmd;
	struct uwb_rc_evt_confirm reply;

	result = -ENOMEM;
	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (cmd == NULL)
		goto error_kzalloc;
	mutex_lock(&rc->uwb_dev.mutex);
	cmd->rccb.bCommandType = UWB_RC_CET_GENERAL;
	cmd->rccb.wCommand = cpu_to_le16(UWB_RC_CMD_SCAN);
	cmd->bChannelNumber = channel;
	cmd->bScanState = type;
	cmd->wStartTime = cpu_to_le16(bpst_offset);
	reply.rceb.bEventType = UWB_RC_CET_GENERAL;
	reply.rceb.wEvent = UWB_RC_CMD_SCAN;
	result = uwb_rc_cmd(rc, "SCAN", &cmd->rccb, sizeof(*cmd),
			    &reply.rceb, sizeof(reply));
	if (result < 0)
		goto error_cmd;
	if (reply.bResultCode != UWB_RC_RES_SUCCESS) {
		dev_err(&rc->uwb_dev.dev,
			"SCAN: command execution failed: %s (%d)\n",
			uwb_rc_strerror(reply.bResultCode), reply.bResultCode);
		result = -EIO;
		goto error_cmd;
	}
	rc->scanning = channel;
	rc->scan_type = type;
error_cmd:
	mutex_unlock(&rc->uwb_dev.mutex);
	kfree(cmd);
error_kzalloc:
	return result;
}

__attribute__((used)) static ssize_t uwb_rc_scan_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct uwb_dev *uwb_dev = to_uwb_dev(dev);
	struct uwb_rc *rc = uwb_dev->rc;
	ssize_t result;

	mutex_lock(&rc->uwb_dev.mutex);
	result = sprintf(buf, "%d %d\n", rc->scanning, rc->scan_type);
	mutex_unlock(&rc->uwb_dev.mutex);
	return result;
}

__attribute__((used)) static ssize_t uwb_rc_scan_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t size)
{
	struct uwb_dev *uwb_dev = to_uwb_dev(dev);
	struct uwb_rc *rc = uwb_dev->rc;
	unsigned channel;
	unsigned type;
	unsigned bpst_offset = 0;
	ssize_t result = -EINVAL;

	result = sscanf(buf, "%u %u %u\n", &channel, &type, &bpst_offset);
	if (result >= 2 && type < UWB_SCAN_TOP)
		result = uwb_rc_scan(rc, channel, type, bpst_offset);

	return result < 0 ? result : size;
}


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
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned int u16 ;
struct TYPE_5__ {int wEvent; void* bEventType; } ;
struct TYPE_4__ {void* wCommand; void* bCommandType; } ;
struct i1480_evt_mpi_read {scalar_t__ bResultCode; TYPE_3__* data; TYPE_2__ rceb; void* size; TYPE_1__ rccb; } ;
struct i1480_evt_confirm {scalar_t__ bResultCode; TYPE_3__* data; TYPE_2__ rceb; void* size; TYPE_1__ rccb; } ;
struct i1480_cmd_mpi_write {scalar_t__ bResultCode; TYPE_3__* data; TYPE_2__ rceb; void* size; TYPE_1__ rccb; } ;
struct i1480_cmd_mpi_read {scalar_t__ bResultCode; TYPE_3__* data; TYPE_2__ rceb; void* size; TYPE_1__ rccb; } ;
struct i1480 {int hw_rev; int buf_size; int /*<<< orphan*/  phy_fw_name; int /*<<< orphan*/  dev; struct i1480_evt_mpi_read* evt_buf; struct i1480_evt_mpi_read* cmd_buf; int /*<<< orphan*/  evt_complete; } ;
struct firmware {char* data; int size; } ;
struct TYPE_6__ {unsigned int page; unsigned int offset; int /*<<< orphan*/  value; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ UWB_RC_RES_SUCCESS ; 
 void* cpu_to_le16 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 void* i1480_CET_VS1 ; 
 int i1480_CMD_MPI_READ ; 
 int i1480_CMD_MPI_WRITE ; 
 int i1480_cmd (struct i1480*,char*,int,int) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (TYPE_3__*,void const*,size_t) ; 
 int /*<<< orphan*/  memset (struct i1480_evt_mpi_read*,int,int) ; 
 size_t min (size_t const,size_t) ; 
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline
void i1480_init(struct i1480 *i1480)
{
	i1480->hw_rev = 1;
	init_completion(&i1480->evt_complete);
}

__attribute__((used)) static
int i1480_mpi_write(struct i1480 *i1480, const void *data, size_t size)
{
	int result;
	struct i1480_cmd_mpi_write *cmd = i1480->cmd_buf;
	struct i1480_evt_confirm *reply = i1480->evt_buf;

	BUG_ON(size > 480);
	result = -ENOMEM;
	cmd->rccb.bCommandType = i1480_CET_VS1;
	cmd->rccb.wCommand = cpu_to_le16(i1480_CMD_MPI_WRITE);
	cmd->size = cpu_to_le16(size);
	memcpy(cmd->data, data, size);
	reply->rceb.bEventType = i1480_CET_VS1;
	reply->rceb.wEvent = i1480_CMD_MPI_WRITE;
	result = i1480_cmd(i1480, "MPI-WRITE", sizeof(*cmd) + size, sizeof(*reply));
	if (result < 0)
		goto out;
	if (reply->bResultCode != UWB_RC_RES_SUCCESS) {
		dev_err(i1480->dev, "MPI-WRITE: command execution failed: %d\n",
			reply->bResultCode);
		result = -EIO;
	}
out:
	return result;
}

__attribute__((used)) static
int i1480_mpi_read(struct i1480 *i1480, u8 *data, u16 srcaddr, size_t size)
{
	int result;
	struct i1480_cmd_mpi_read *cmd = i1480->cmd_buf;
	struct i1480_evt_mpi_read *reply = i1480->evt_buf;
	unsigned cnt;

	memset(i1480->cmd_buf, 0x69, 512);
	memset(i1480->evt_buf, 0x69, 512);

	BUG_ON(size > (i1480->buf_size - sizeof(*reply)) / 3);
	result = -ENOMEM;
	cmd->rccb.bCommandType = i1480_CET_VS1;
	cmd->rccb.wCommand = cpu_to_le16(i1480_CMD_MPI_READ);
	cmd->size = cpu_to_le16(3*size);
	for (cnt = 0; cnt < size; cnt++) {
		cmd->data[cnt].page = (srcaddr + cnt) >> 8;
		cmd->data[cnt].offset = (srcaddr + cnt) & 0xff;
	}
	reply->rceb.bEventType = i1480_CET_VS1;
	reply->rceb.wEvent = i1480_CMD_MPI_READ;
	result = i1480_cmd(i1480, "MPI-READ", sizeof(*cmd) + 2*size,
			sizeof(*reply) + 3*size);
	if (result < 0)
		goto out;
	if (reply->bResultCode != UWB_RC_RES_SUCCESS) {
		dev_err(i1480->dev, "MPI-READ: command execution failed: %d\n",
			reply->bResultCode);
		result = -EIO;
		goto out;
	}
	for (cnt = 0; cnt < size; cnt++) {
		if (reply->data[cnt].page != (srcaddr + cnt) >> 8)
			dev_err(i1480->dev, "MPI-READ: page inconsistency at "
				"index %u: expected 0x%02x, got 0x%02x\n", cnt,
				(srcaddr + cnt) >> 8, reply->data[cnt].page);
		if (reply->data[cnt].offset != ((srcaddr + cnt) & 0x00ff))
			dev_err(i1480->dev, "MPI-READ: offset inconsistency at "
				"index %u: expected 0x%02x, got 0x%02x\n", cnt,
				(srcaddr + cnt) & 0x00ff,
				reply->data[cnt].offset);
		data[cnt] = reply->data[cnt].value;
	}
	result = 0;
out:
	return result;
}

int i1480_phy_fw_upload(struct i1480 *i1480)
{
	int result;
	const struct firmware *fw;
	const char *data_itr, *data_top;
	const size_t MAX_BLK_SIZE = 480;	/* 160 triads */
	size_t data_size;
	u8 phy_stat;

	result = request_firmware(&fw, i1480->phy_fw_name, i1480->dev);
	if (result < 0)
		goto out;
	/* Loop writing data in chunks as big as possible until done. */
	for (data_itr = fw->data, data_top = data_itr + fw->size;
	     data_itr < data_top; data_itr += MAX_BLK_SIZE) {
		data_size = min(MAX_BLK_SIZE, (size_t) (data_top - data_itr));
		result = i1480_mpi_write(i1480, data_itr, data_size);
		if (result < 0)
			goto error_mpi_write;
	}
	/* Read MPI page 0, offset 6; if 0, PHY was initialized correctly. */
	result = i1480_mpi_read(i1480, &phy_stat, 0x0006, 1);
	if (result < 0) {
		dev_err(i1480->dev, "PHY: can't get status: %d\n", result);
		goto error_mpi_status;
	}
	if (phy_stat != 0) {
		result = -ENODEV;
		dev_info(i1480->dev, "error, PHY not ready: %u\n", phy_stat);
		goto error_phy_status;
	}
	dev_info(i1480->dev, "PHY fw '%s': uploaded\n", i1480->phy_fw_name);
error_phy_status:
error_mpi_status:
error_mpi_write:
	release_firmware(fw);
	if (result < 0)
		dev_err(i1480->dev, "PHY fw '%s': failed to upload (%d), "
			"power cycle device\n", i1480->phy_fw_name, result);
out:
	return result;
}


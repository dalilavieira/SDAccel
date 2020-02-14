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
struct s5p_mfc_priv_buf {scalar_t__ size; scalar_t__ virt; } ;
struct s5p_mfc_dev {int fw_get_done; int fw_ver; int risc_on; int* dma_base; scalar_t__ int_err; scalar_t__ int_type; scalar_t__ type; int* inst_no; int /*<<< orphan*/  state; int /*<<< orphan*/  mfc_ops; scalar_t__ int_cond; int /*<<< orphan*/  mfc_cmds; struct s5p_mfc_priv_buf fw_buf; TYPE_1__* plat_dev; TYPE_3__* variant; } ;
struct s5p_mfc_ctx {int fw_get_done; int fw_ver; int risc_on; int* dma_base; scalar_t__ int_err; scalar_t__ int_type; scalar_t__ type; int* inst_no; int /*<<< orphan*/  state; int /*<<< orphan*/  mfc_ops; scalar_t__ int_cond; int /*<<< orphan*/  mfc_cmds; struct s5p_mfc_priv_buf fw_buf; TYPE_1__* plat_dev; TYPE_3__* variant; } ;
struct firmware {scalar_t__ size; int /*<<< orphan*/  data; } ;
typedef  enum s5p_mfc_fw_ver { ____Placeholder_s5p_mfc_fw_ver } s5p_mfc_fw_ver ;
struct TYPE_6__ {int /*<<< orphan*/ * fw_name; TYPE_2__* buf_size; } ;
struct TYPE_5__ {scalar_t__ fw; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 size_t BANK_L_CTX ; 
 size_t BANK_R_CTX ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 scalar_t__ IS_MFCV10 (struct s5p_mfc_dev*) ; 
 scalar_t__ IS_MFCV6_PLUS (struct s5p_mfc_dev*) ; 
 int /*<<< orphan*/  IS_MFCV7_PLUS (struct s5p_mfc_dev*) ; 
 scalar_t__ IS_MFCV8_PLUS (struct s5p_mfc_dev*) ; 
 scalar_t__ MFCINST_DECODER ; 
 int /*<<< orphan*/  MFCINST_FREE ; 
 int /*<<< orphan*/  MFCINST_RETURN_INST ; 
 int /*<<< orphan*/  MFC_BW_TIMEOUT ; 
 int MFC_FW_MAX_VERSIONS ; 
 int* MFC_NO_INSTANCE_SET ; 
 scalar_t__ S5P_FIMV_FW_VERSION ; 
 scalar_t__ S5P_FIMV_FW_VERSION_V6 ; 
 scalar_t__ S5P_FIMV_HOST2RISC_CMD ; 
 scalar_t__ S5P_FIMV_HOST2RISC_CMD_V6 ; 
 scalar_t__ S5P_FIMV_MC_DRAMBASE_ADR_A ; 
 scalar_t__ S5P_FIMV_MC_DRAMBASE_ADR_B ; 
 scalar_t__ S5P_FIMV_MC_STATUS ; 
 scalar_t__ S5P_FIMV_MFC_BUS_RESET_CTRL ; 
 scalar_t__ S5P_FIMV_MFC_CLOCK_OFF_V10 ; 
 scalar_t__ S5P_FIMV_MFC_RESET_V6 ; 
 scalar_t__ S5P_FIMV_REG_CLEAR_BEGIN_V6 ; 
 int S5P_FIMV_REG_CLEAR_COUNT_V6 ; 
 scalar_t__ S5P_FIMV_RISC2HOST_CMD ; 
 scalar_t__ S5P_FIMV_RISC2HOST_CMD_V6 ; 
 scalar_t__ S5P_FIMV_RISC_BASE_ADDRESS_V6 ; 
 scalar_t__ S5P_FIMV_RISC_ON_V6 ; 
 scalar_t__ S5P_FIMV_SI_CH0_INST_ID ; 
 scalar_t__ S5P_FIMV_SI_CH1_INST_ID ; 
 scalar_t__ S5P_FIMV_SW_RESET ; 
 int /*<<< orphan*/  S5P_MFC_R2H_CMD_CLOSE_INSTANCE_RET ; 
 scalar_t__ S5P_MFC_R2H_CMD_FW_STATUS_RET ; 
 int /*<<< orphan*/  S5P_MFC_R2H_CMD_OPEN_INSTANCE_RET ; 
 scalar_t__ S5P_MFC_R2H_CMD_SLEEP_RET ; 
 scalar_t__ S5P_MFC_R2H_CMD_SYS_INIT_RET ; 
 scalar_t__ S5P_MFC_R2H_CMD_WAKEUP_RET ; 
 int /*<<< orphan*/  alloc_dec_temp_buffers ; 
 int /*<<< orphan*/  alloc_instance_buffer ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  mfc_debug (int,char*,...) ; 
 int /*<<< orphan*/  mfc_debug_enter () ; 
 int /*<<< orphan*/  mfc_debug_leave () ; 
 int /*<<< orphan*/  mfc_err (char*,...) ; 
 unsigned int mfc_read (struct s5p_mfc_dev*,scalar_t__) ; 
 int /*<<< orphan*/  mfc_write (struct s5p_mfc_dev*,int,scalar_t__) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_codec_buffers ; 
 int /*<<< orphan*/  release_dec_desc_buffer ; 
 int /*<<< orphan*/  release_dev_context_buffer ; 
 int /*<<< orphan*/  release_firmware (struct firmware*) ; 
 int /*<<< orphan*/  release_instance_buffer ; 
 int request_firmware (struct firmware const**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int s5p_mfc_alloc_priv_buf (struct s5p_mfc_dev*,size_t,struct s5p_mfc_priv_buf*) ; 
 int /*<<< orphan*/  s5p_mfc_clean_dev_int_flags (struct s5p_mfc_dev*) ; 
 int /*<<< orphan*/  s5p_mfc_clock_off () ; 
 int /*<<< orphan*/  s5p_mfc_clock_on () ; 
 int s5p_mfc_hw_call (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct s5p_mfc_dev*) ; 
 int /*<<< orphan*/  s5p_mfc_release_priv_buf (struct s5p_mfc_dev*,struct s5p_mfc_priv_buf*) ; 
 scalar_t__ s5p_mfc_wait_for_done_ctx (struct s5p_mfc_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ s5p_mfc_wait_for_done_dev (struct s5p_mfc_dev*,scalar_t__) ; 
 int /*<<< orphan*/  set_work_bit_irqsave (struct s5p_mfc_dev*) ; 
 int /*<<< orphan*/  sleep_cmd ; 
 int /*<<< orphan*/  sys_init_cmd ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  try_run ; 
 int /*<<< orphan*/  wakeup_cmd ; 
 int /*<<< orphan*/  wmb () ; 

int s5p_mfc_alloc_firmware(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_priv_buf *fw_buf = &dev->fw_buf;
	int err;

	fw_buf->size = dev->variant->buf_size->fw;

	if (fw_buf->virt) {
		mfc_err("Attempting to allocate firmware when it seems that it is already loaded\n");
		return -ENOMEM;
	}

	err = s5p_mfc_alloc_priv_buf(dev, BANK_L_CTX, &dev->fw_buf);
	if (err) {
		mfc_err("Allocating bitprocessor buffer failed\n");
		return err;
	}

	return 0;
}

int s5p_mfc_load_firmware(struct s5p_mfc_dev *dev)
{
	struct firmware *fw_blob;
	int i, err = -EINVAL;

	/* Firmare has to be present as a separate file or compiled
	 * into kernel. */
	mfc_debug_enter();

	if (dev->fw_get_done)
		return 0;

	for (i = MFC_FW_MAX_VERSIONS - 1; i >= 0; i--) {
		if (!dev->variant->fw_name[i])
			continue;
		err = request_firmware((const struct firmware **)&fw_blob,
				dev->variant->fw_name[i], &dev->plat_dev->dev);
		if (!err) {
			dev->fw_ver = (enum s5p_mfc_fw_ver) i;
			break;
		}
	}

	if (err != 0) {
		mfc_err("Firmware is not present in the /lib/firmware directory nor compiled in kernel\n");
		return -EINVAL;
	}
	if (fw_blob->size > dev->fw_buf.size) {
		mfc_err("MFC firmware is too big to be loaded\n");
		release_firmware(fw_blob);
		return -ENOMEM;
	}
	memcpy(dev->fw_buf.virt, fw_blob->data, fw_blob->size);
	wmb();
	dev->fw_get_done = true;
	release_firmware(fw_blob);
	mfc_debug_leave();
	return 0;
}

int s5p_mfc_release_firmware(struct s5p_mfc_dev *dev)
{
	/* Before calling this function one has to make sure
	 * that MFC is no longer processing */
	s5p_mfc_release_priv_buf(dev, &dev->fw_buf);
	dev->fw_get_done = false;
	return 0;
}

__attribute__((used)) static int s5p_mfc_bus_reset(struct s5p_mfc_dev *dev)
{
	unsigned int status;
	unsigned long timeout;

	/* Reset */
	mfc_write(dev, 0x1, S5P_FIMV_MFC_BUS_RESET_CTRL);
	timeout = jiffies + msecs_to_jiffies(MFC_BW_TIMEOUT);
	/* Check bus status */
	do {
		if (time_after(jiffies, timeout)) {
			mfc_err("Timeout while resetting MFC.\n");
			return -EIO;
		}
		status = mfc_read(dev, S5P_FIMV_MFC_BUS_RESET_CTRL);
	} while ((status & 0x2) == 0);
	return 0;
}

int s5p_mfc_reset(struct s5p_mfc_dev *dev)
{
	unsigned int mc_status;
	unsigned long timeout;
	int i;

	mfc_debug_enter();

	if (IS_MFCV6_PLUS(dev)) {
		/* Zero Initialization of MFC registers */
		mfc_write(dev, 0, S5P_FIMV_RISC2HOST_CMD_V6);
		mfc_write(dev, 0, S5P_FIMV_HOST2RISC_CMD_V6);
		mfc_write(dev, 0, S5P_FIMV_FW_VERSION_V6);

		for (i = 0; i < S5P_FIMV_REG_CLEAR_COUNT_V6; i++)
			mfc_write(dev, 0, S5P_FIMV_REG_CLEAR_BEGIN_V6 + (i*4));

		/* check bus reset control before reset */
		if (dev->risc_on)
			if (s5p_mfc_bus_reset(dev))
				return -EIO;
		/* Reset
		 * set RISC_ON to 0 during power_on & wake_up.
		 * V6 needs RISC_ON set to 0 during reset also.
		 */
		if ((!dev->risc_on) || (!IS_MFCV7_PLUS(dev)))
			mfc_write(dev, 0, S5P_FIMV_RISC_ON_V6);

		mfc_write(dev, 0x1FFF, S5P_FIMV_MFC_RESET_V6);
		mfc_write(dev, 0, S5P_FIMV_MFC_RESET_V6);
	} else {
		/* Stop procedure */
		/*  reset RISC */
		mfc_write(dev, 0x3f6, S5P_FIMV_SW_RESET);
		/*  All reset except for MC */
		mfc_write(dev, 0x3e2, S5P_FIMV_SW_RESET);
		mdelay(10);

		timeout = jiffies + msecs_to_jiffies(MFC_BW_TIMEOUT);
		/* Check MC status */
		do {
			if (time_after(jiffies, timeout)) {
				mfc_err("Timeout while resetting MFC\n");
				return -EIO;
			}

			mc_status = mfc_read(dev, S5P_FIMV_MC_STATUS);

		} while (mc_status & 0x3);

		mfc_write(dev, 0x0, S5P_FIMV_SW_RESET);
		mfc_write(dev, 0x3fe, S5P_FIMV_SW_RESET);
	}

	mfc_debug_leave();
	return 0;
}

__attribute__((used)) static inline void s5p_mfc_init_memctrl(struct s5p_mfc_dev *dev)
{
	if (IS_MFCV6_PLUS(dev)) {
		mfc_write(dev, dev->dma_base[BANK_L_CTX],
			  S5P_FIMV_RISC_BASE_ADDRESS_V6);
		mfc_debug(2, "Base Address : %pad\n",
			  &dev->dma_base[BANK_L_CTX]);
	} else {
		mfc_write(dev, dev->dma_base[BANK_L_CTX],
			  S5P_FIMV_MC_DRAMBASE_ADR_A);
		mfc_write(dev, dev->dma_base[BANK_R_CTX],
			  S5P_FIMV_MC_DRAMBASE_ADR_B);
		mfc_debug(2, "Bank1: %pad, Bank2: %pad\n",
			  &dev->dma_base[BANK_L_CTX],
			  &dev->dma_base[BANK_R_CTX]);
	}
}

__attribute__((used)) static inline void s5p_mfc_clear_cmds(struct s5p_mfc_dev *dev)
{
	if (IS_MFCV6_PLUS(dev)) {
		/* Zero initialization should be done before RESET.
		 * Nothing to do here. */
	} else {
		mfc_write(dev, 0xffffffff, S5P_FIMV_SI_CH0_INST_ID);
		mfc_write(dev, 0xffffffff, S5P_FIMV_SI_CH1_INST_ID);
		mfc_write(dev, 0, S5P_FIMV_RISC2HOST_CMD);
		mfc_write(dev, 0, S5P_FIMV_HOST2RISC_CMD);
	}
}

int s5p_mfc_init_hw(struct s5p_mfc_dev *dev)
{
	unsigned int ver;
	int ret;

	mfc_debug_enter();
	if (!dev->fw_buf.virt) {
		mfc_err("Firmware memory is not allocated.\n");
		return -EINVAL;
	}

	/* 0. MFC reset */
	mfc_debug(2, "MFC reset..\n");
	s5p_mfc_clock_on();
	dev->risc_on = 0;
	ret = s5p_mfc_reset(dev);
	if (ret) {
		mfc_err("Failed to reset MFC - timeout\n");
		return ret;
	}
	mfc_debug(2, "Done MFC reset..\n");
	/* 1. Set DRAM base Addr */
	s5p_mfc_init_memctrl(dev);
	/* 2. Initialize registers of channel I/F */
	s5p_mfc_clear_cmds(dev);
	/* 3. Release reset signal to the RISC */
	s5p_mfc_clean_dev_int_flags(dev);
	if (IS_MFCV6_PLUS(dev)) {
		dev->risc_on = 1;
		mfc_write(dev, 0x1, S5P_FIMV_RISC_ON_V6);
	}
	else
		mfc_write(dev, 0x3ff, S5P_FIMV_SW_RESET);

	if (IS_MFCV10(dev))
		mfc_write(dev, 0x0, S5P_FIMV_MFC_CLOCK_OFF_V10);

	mfc_debug(2, "Will now wait for completion of firmware transfer\n");
	if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_FW_STATUS_RET)) {
		mfc_err("Failed to load firmware\n");
		s5p_mfc_reset(dev);
		s5p_mfc_clock_off();
		return -EIO;
	}
	s5p_mfc_clean_dev_int_flags(dev);
	/* 4. Initialize firmware */
	ret = s5p_mfc_hw_call(dev->mfc_cmds, sys_init_cmd, dev);
	if (ret) {
		mfc_err("Failed to send command to MFC - timeout\n");
		s5p_mfc_reset(dev);
		s5p_mfc_clock_off();
		return ret;
	}
	mfc_debug(2, "Ok, now will wait for completion of hardware init\n");
	if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_SYS_INIT_RET)) {
		mfc_err("Failed to init hardware\n");
		s5p_mfc_reset(dev);
		s5p_mfc_clock_off();
		return -EIO;
	}
	dev->int_cond = 0;
	if (dev->int_err != 0 || dev->int_type !=
					S5P_MFC_R2H_CMD_SYS_INIT_RET) {
		/* Failure. */
		mfc_err("Failed to init firmware - error: %d int: %d\n",
						dev->int_err, dev->int_type);
		s5p_mfc_reset(dev);
		s5p_mfc_clock_off();
		return -EIO;
	}
	if (IS_MFCV6_PLUS(dev))
		ver = mfc_read(dev, S5P_FIMV_FW_VERSION_V6);
	else
		ver = mfc_read(dev, S5P_FIMV_FW_VERSION);

	mfc_debug(2, "MFC F/W version : %02xyy, %02xmm, %02xdd\n",
		(ver >> 16) & 0xFF, (ver >> 8) & 0xFF, ver & 0xFF);
	s5p_mfc_clock_off();
	mfc_debug_leave();
	return 0;
}

void s5p_mfc_deinit_hw(struct s5p_mfc_dev *dev)
{
	s5p_mfc_clock_on();

	s5p_mfc_reset(dev);
	s5p_mfc_hw_call(dev->mfc_ops, release_dev_context_buffer, dev);

	s5p_mfc_clock_off();
}

int s5p_mfc_sleep(struct s5p_mfc_dev *dev)
{
	int ret;

	mfc_debug_enter();
	s5p_mfc_clock_on();
	s5p_mfc_clean_dev_int_flags(dev);
	ret = s5p_mfc_hw_call(dev->mfc_cmds, sleep_cmd, dev);
	if (ret) {
		mfc_err("Failed to send command to MFC - timeout\n");
		return ret;
	}
	if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_SLEEP_RET)) {
		mfc_err("Failed to sleep\n");
		return -EIO;
	}
	s5p_mfc_clock_off();
	dev->int_cond = 0;
	if (dev->int_err != 0 || dev->int_type !=
						S5P_MFC_R2H_CMD_SLEEP_RET) {
		/* Failure. */
		mfc_err("Failed to sleep - error: %d int: %d\n", dev->int_err,
								dev->int_type);
		return -EIO;
	}
	mfc_debug_leave();
	return ret;
}

__attribute__((used)) static int s5p_mfc_v8_wait_wakeup(struct s5p_mfc_dev *dev)
{
	int ret;

	/* Release reset signal to the RISC */
	dev->risc_on = 1;
	mfc_write(dev, 0x1, S5P_FIMV_RISC_ON_V6);

	if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_FW_STATUS_RET)) {
		mfc_err("Failed to reset MFCV8\n");
		return -EIO;
	}
	mfc_debug(2, "Write command to wakeup MFCV8\n");
	ret = s5p_mfc_hw_call(dev->mfc_cmds, wakeup_cmd, dev);
	if (ret) {
		mfc_err("Failed to send command to MFCV8 - timeout\n");
		return ret;
	}

	if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_WAKEUP_RET)) {
		mfc_err("Failed to wakeup MFC\n");
		return -EIO;
	}
	return ret;
}

__attribute__((used)) static int s5p_mfc_wait_wakeup(struct s5p_mfc_dev *dev)
{
	int ret;

	/* Send MFC wakeup command */
	ret = s5p_mfc_hw_call(dev->mfc_cmds, wakeup_cmd, dev);
	if (ret) {
		mfc_err("Failed to send command to MFC - timeout\n");
		return ret;
	}

	/* Release reset signal to the RISC */
	if (IS_MFCV6_PLUS(dev)) {
		dev->risc_on = 1;
		mfc_write(dev, 0x1, S5P_FIMV_RISC_ON_V6);
	} else {
		mfc_write(dev, 0x3ff, S5P_FIMV_SW_RESET);
	}

	if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_WAKEUP_RET)) {
		mfc_err("Failed to wakeup MFC\n");
		return -EIO;
	}
	return ret;
}

int s5p_mfc_wakeup(struct s5p_mfc_dev *dev)
{
	int ret;

	mfc_debug_enter();
	/* 0. MFC reset */
	mfc_debug(2, "MFC reset..\n");
	s5p_mfc_clock_on();
	dev->risc_on = 0;
	ret = s5p_mfc_reset(dev);
	if (ret) {
		mfc_err("Failed to reset MFC - timeout\n");
		s5p_mfc_clock_off();
		return ret;
	}
	mfc_debug(2, "Done MFC reset..\n");
	/* 1. Set DRAM base Addr */
	s5p_mfc_init_memctrl(dev);
	/* 2. Initialize registers of channel I/F */
	s5p_mfc_clear_cmds(dev);
	s5p_mfc_clean_dev_int_flags(dev);
	/* 3. Send MFC wakeup command and wait for completion*/
	if (IS_MFCV8_PLUS(dev))
		ret = s5p_mfc_v8_wait_wakeup(dev);
	else
		ret = s5p_mfc_wait_wakeup(dev);

	s5p_mfc_clock_off();
	if (ret)
		return ret;

	dev->int_cond = 0;
	if (dev->int_err != 0 || dev->int_type !=
						S5P_MFC_R2H_CMD_WAKEUP_RET) {
		/* Failure. */
		mfc_err("Failed to wakeup - error: %d int: %d\n", dev->int_err,
								dev->int_type);
		return -EIO;
	}
	mfc_debug_leave();
	return 0;
}

int s5p_mfc_open_mfc_inst(struct s5p_mfc_dev *dev, struct s5p_mfc_ctx *ctx)
{
	int ret = 0;

	ret = s5p_mfc_hw_call(dev->mfc_ops, alloc_instance_buffer, ctx);
	if (ret) {
		mfc_err("Failed allocating instance buffer\n");
		goto err;
	}

	if (ctx->type == MFCINST_DECODER) {
		ret = s5p_mfc_hw_call(dev->mfc_ops,
					alloc_dec_temp_buffers, ctx);
		if (ret) {
			mfc_err("Failed allocating temporary buffers\n");
			goto err_free_inst_buf;
		}
	}

	set_work_bit_irqsave(ctx);
	s5p_mfc_hw_call(dev->mfc_ops, try_run, dev);
	if (s5p_mfc_wait_for_done_ctx(ctx,
		S5P_MFC_R2H_CMD_OPEN_INSTANCE_RET, 0)) {
		/* Error or timeout */
		mfc_err("Error getting instance from hardware\n");
		ret = -EIO;
		goto err_free_desc_buf;
	}

	mfc_debug(2, "Got instance number: %d\n", ctx->inst_no);
	return ret;

err_free_desc_buf:
	if (ctx->type == MFCINST_DECODER)
		s5p_mfc_hw_call(dev->mfc_ops, release_dec_desc_buffer, ctx);
err_free_inst_buf:
	s5p_mfc_hw_call(dev->mfc_ops, release_instance_buffer, ctx);
err:
	return ret;
}

void s5p_mfc_close_mfc_inst(struct s5p_mfc_dev *dev, struct s5p_mfc_ctx *ctx)
{
	ctx->state = MFCINST_RETURN_INST;
	set_work_bit_irqsave(ctx);
	s5p_mfc_hw_call(dev->mfc_ops, try_run, dev);
	/* Wait until instance is returned or timeout occurred */
	if (s5p_mfc_wait_for_done_ctx(ctx,
				S5P_MFC_R2H_CMD_CLOSE_INSTANCE_RET, 0))
		mfc_err("Err returning instance\n");

	/* Free resources */
	s5p_mfc_hw_call(dev->mfc_ops, release_codec_buffers, ctx);
	s5p_mfc_hw_call(dev->mfc_ops, release_instance_buffer, ctx);
	if (ctx->type == MFCINST_DECODER)
		s5p_mfc_hw_call(dev->mfc_ops, release_dec_desc_buffer, ctx);

	ctx->inst_no = MFC_NO_INSTANCE_SET;
	ctx->state = MFCINST_FREE;
}


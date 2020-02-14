#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct video_info {int color_fmt; int color_depth; int h_sync_polarity; int v_sync_polarity; } ;
struct drm_display_mode {int clock; int hsync_start; int hdisplay; int htotal; int hsync_end; int vtotal; int vsync_start; int vsync_end; int vdisplay; } ;
struct TYPE_2__ {int rate; int num_lanes; } ;
struct cdn_dp_device {int fw_version; int /*<<< orphan*/  dev; int /*<<< orphan*/  spdif_rst; int /*<<< orphan*/  spdif_clk; scalar_t__ regs; TYPE_1__ link; struct drm_display_mode mode; struct video_info video_info; } ;
struct audio_info {scalar_t__ format; int channels; int sample_width; int sample_rate; } ;
typedef  int /*<<< orphan*/  status ;
typedef  int /*<<< orphan*/  reg ;
typedef  int /*<<< orphan*/  msg ;
typedef  int /*<<< orphan*/  field ;
typedef  int /*<<< orphan*/  event ;

/* Variables and functions */
 scalar_t__ ADDR_DMEM ; 
 scalar_t__ ADDR_IMEM ; 
 scalar_t__ AFMT_I2S ; 
 scalar_t__ AFMT_SPDIF ; 
 scalar_t__ APB_CTRL ; 
 int APB_DRAM_PATH ; 
 scalar_t__ APB_INT_MASK ; 
 int APB_IRAM_PATH ; 
 int APB_XT_RESET ; 
 int AUDIO_CH_NUM (int) ; 
 int AUDIO_PACK_CONTROL ; 
 int AUDIO_PACK_EN ; 
 scalar_t__ AUDIO_SRC_CNFG ; 
 scalar_t__ AUDIO_SRC_CNTL ; 
 int AUDIO_SW_RST ; 
 int AUDIO_TYPE_LPCM ; 
 int AUX_HOST_INVERT ; 
 int BCS_10 ; 
 int BCS_12 ; 
 int BCS_16 ; 
 int BCS_6 ; 
 int BCS_8 ; 
 int BND_HSYNC2VSYNC ; 
 int BT_601 ; 
 int CDN_DP_MAX_LINK_RATE ; 
 int /*<<< orphan*/  CDN_DP_SPDIF_CLK ; 
 int CFG_DPTX_VIF_CLK_EN ; 
 int CFG_DPTX_VIF_CLK_RSTN_EN ; 
 int CFG_SUB_PCKT_NUM (int) ; 
 int CM_CTRL ; 
 int CM_LANE_CTRL ; 
 scalar_t__ COM_CH_STTS_BITS ; 
 int DPTX_ENABLE_EVENT ; 
 int DPTX_EVENT_ENABLE_HPD ; 
 int DPTX_EVENT_ENABLE_TRAINING ; 
 int DPTX_FRMR_DATA_CLK_EN ; 
 int DPTX_FRMR_DATA_CLK_RSTN_EN ; 
 int DPTX_GET_EDID ; 
 int DPTX_HPD_STATE ; 
 int DPTX_PHY_CHAR_CLK_EN ; 
 int DPTX_PHY_CHAR_RSTN_EN ; 
 int DPTX_PHY_DATA_CLK_EN ; 
 int DPTX_PHY_DATA_RSTN_EN ; 
 int DPTX_READ_DPCD ; 
 int DPTX_READ_EVENT ; 
 int DPTX_READ_LINK_STAT ; 
 int DPTX_SET_HOST_CAPABILITIES ; 
 int DPTX_SET_VIDEO ; 
 int DPTX_SYS_CLK_EN ; 
 int DPTX_SYS_CLK_RSTN_EN ; 
 int DPTX_TRAINING_CONTROL ; 
 int DPTX_WRITE_DPCD ; 
 int DPTX_WRITE_FIELD ; 
 int DPTX_WRITE_REGISTER ; 
 int DP_AUX_SWAP_INVERSION_CONTROL ; 
 int DP_BYTE_COUNT ; 
 int DP_FRAMER_PXL_REPR ; 
 int DP_FRAMER_SP ; 
 int DP_FRAMER_SP_HSP ; 
 int DP_FRAMER_SP_VSP ; 
 int DP_FRAMER_TU ; 
 int DP_FRONT_BACK_PORCH ; 
 int DP_HORIZONTAL ; 
 int DP_VB_ID ; 
 int DP_VC_TABLE (int) ; 
 int DP_VERTICAL_0 ; 
 int DP_VERTICAL_1 ; 
 int /*<<< orphan*/  DRM_DEV_DEBUG (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  DRM_DEV_DEBUG_KMS (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  DRM_DEV_ERROR (int /*<<< orphan*/ ,char*,...) ; 
 int EINVAL ; 
 int ENHANCED ; 
 int EQ_PHASE_FINISHED ; 
 int ETIMEDOUT ; 
 int FAST_LT_NOT_SUPPORT ; 
 scalar_t__ FIFO_CNTL ; 
 int FW_ACTIVE ; 
 int /*<<< orphan*/  FW_ALIVE_TIMEOUT_US ; 
 int FW_STANDBY ; 
 int GENERAL_MAIN_CONTROL ; 
 int HSYNC2VSYNC_POL_CTRL ; 
 int I2S_DEC_PORT_EN (int) ; 
 int I2S_DEC_START ; 
 scalar_t__ KEEP_ALIVE ; 
 int LANE_MAPPING_FLIPPED ; 
 int LANE_MAPPING_NORMAL ; 
 int LANE_REF_CYC ; 
 int /*<<< orphan*/  LINK_TRAINING_RETRY_MS ; 
 int LINK_TRAINING_RUN ; 
 int /*<<< orphan*/  LINK_TRAINING_TIMEOUT_MS ; 
 scalar_t__ MAILBOX0_RD_DATA ; 
 scalar_t__ MAILBOX0_WR_DATA ; 
 scalar_t__ MAILBOX_EMPTY_ADDR ; 
 scalar_t__ MAILBOX_FULL_ADDR ; 
 int MAILBOX_RETRY_US ; 
 int /*<<< orphan*/  MAILBOX_TIMEOUT_US ; 
 int MAX_NUM_CH (int) ; 
 int MB_MODULE_ID_DP_TX ; 
 int MB_MODULE_ID_GENERAL ; 
 int MSA_HORIZONTAL_0 ; 
 int MSA_HORIZONTAL_1 ; 
 int MSA_MISC ; 
 int MSA_VERTICAL_0 ; 
 int MSA_VERTICAL_1 ; 
 int NUM_OF_I2S_PORTS (int) ; 
 int ORIGINAL_SAMP_FREQ (int) ; 
 int PRE_EMPHASIS_LEVEL_3 ; 
 int PTS1 ; 
 int PTS2 ; 
 int PTS3 ; 
 int PTS4 ; 
#define  PXL_RGB 132 
 int SAMPLING_FREQ (int) ; 
 int SCRAMBLER_EN ; 
 scalar_t__ SMPL2PKT_CNFG ; 
 scalar_t__ SMPL2PKT_CNTL ; 
 int SMPL2PKT_EN ; 
 scalar_t__ SOURCE_AIF_CAR ; 
 int SOURCE_AIF_CLK_EN ; 
 int SOURCE_AIF_CLK_RSTN_EN ; 
 int SOURCE_AIF_SYS_CLK_EN ; 
 int SOURCE_AIF_SYS_RSTN_EN ; 
 int SOURCE_AUX_SYS_CLK_EN ; 
 int SOURCE_AUX_SYS_CLK_RSTN_EN ; 
 scalar_t__ SOURCE_CIPHER_CAR ; 
 int SOURCE_CIPHER_CHAR_CLK_EN ; 
 int SOURCE_CIPHER_CHAR_CLK_RSTN_EN ; 
 int SOURCE_CIPHER_SYSTEM_CLK_RSTN_EN ; 
 int SOURCE_CIPHER_SYS_CLK_EN ; 
 scalar_t__ SOURCE_CRYPTO_CAR ; 
 int SOURCE_CRYPTO_SYS_CLK_EN ; 
 int SOURCE_CRYPTO_SYS_CLK_RSTN_EN ; 
 scalar_t__ SOURCE_DPTX_CAR ; 
 scalar_t__ SOURCE_PHY_CAR ; 
 int SOURCE_PHY_CLK_EN ; 
 int SOURCE_PHY_RSTN_EN ; 
 scalar_t__ SOURCE_PKT_CAR ; 
 int SOURCE_PKT_DATA_CLK_EN ; 
 int SOURCE_PKT_DATA_RSTN_EN ; 
 int SOURCE_PKT_SYS_CLK_EN ; 
 int SOURCE_PKT_SYS_RSTN_EN ; 
 int SPDIF_AVG_SEL ; 
 int SPDIF_CDR_CLK_EN ; 
 int SPDIF_CDR_CLK_RSTN_EN ; 
 scalar_t__ SPDIF_CTRL_ADDR ; 
 int SPDIF_ENABLE ; 
 int SPDIF_JITTER_BYPASS ; 
 int STREAM_CONFIG ; 
 scalar_t__ STTS_BIT_CH (int) ; 
 scalar_t__ SW_CLK_H ; 
 scalar_t__ SW_EVENTS0 ; 
 int SYNC_WR_TO_CH_ZERO ; 
 int TRANS_SMPL_WIDTH_32 ; 
 int TU_CNT_RST_EN ; 
 int TU_SIZE ; 
 scalar_t__ VER_H ; 
 scalar_t__ VER_L ; 
 scalar_t__ VER_LIB_H_ADDR ; 
 scalar_t__ VER_LIB_L_ADDR ; 
 int VIF_BYPASS_INTERLACE ; 
 int VOLTAGE_LEVEL_2 ; 
#define  YCBCR_4_2_0 131 
#define  YCBCR_4_2_2 130 
#define  YCBCR_4_4_4 129 
#define  Y_ONLY 128 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_set_rate (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int div_u64 (int,int) ; 
 int do_div (int,int) ; 
 int drm_dp_bw_code_to_link_rate (int) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int readl (scalar_t__) ; 
 int readx_poll_timeout (int (*) (scalar_t__),scalar_t__,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reset_control_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reset_control_deassert (int /*<<< orphan*/ ) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

void cdn_dp_set_fw_clk(struct cdn_dp_device *dp, unsigned long clk)
{
	writel(clk / 1000000, dp->regs + SW_CLK_H);
}

void cdn_dp_clock_reset(struct cdn_dp_device *dp)
{
	u32 val;

	val = DPTX_FRMR_DATA_CLK_RSTN_EN |
	      DPTX_FRMR_DATA_CLK_EN |
	      DPTX_PHY_DATA_RSTN_EN |
	      DPTX_PHY_DATA_CLK_EN |
	      DPTX_PHY_CHAR_RSTN_EN |
	      DPTX_PHY_CHAR_CLK_EN |
	      SOURCE_AUX_SYS_CLK_RSTN_EN |
	      SOURCE_AUX_SYS_CLK_EN |
	      DPTX_SYS_CLK_RSTN_EN |
	      DPTX_SYS_CLK_EN |
	      CFG_DPTX_VIF_CLK_RSTN_EN |
	      CFG_DPTX_VIF_CLK_EN;
	writel(val, dp->regs + SOURCE_DPTX_CAR);

	val = SOURCE_PHY_RSTN_EN | SOURCE_PHY_CLK_EN;
	writel(val, dp->regs + SOURCE_PHY_CAR);

	val = SOURCE_PKT_SYS_RSTN_EN |
	      SOURCE_PKT_SYS_CLK_EN |
	      SOURCE_PKT_DATA_RSTN_EN |
	      SOURCE_PKT_DATA_CLK_EN;
	writel(val, dp->regs + SOURCE_PKT_CAR);

	val = SPDIF_CDR_CLK_RSTN_EN |
	      SPDIF_CDR_CLK_EN |
	      SOURCE_AIF_SYS_RSTN_EN |
	      SOURCE_AIF_SYS_CLK_EN |
	      SOURCE_AIF_CLK_RSTN_EN |
	      SOURCE_AIF_CLK_EN;
	writel(val, dp->regs + SOURCE_AIF_CAR);

	val = SOURCE_CIPHER_SYSTEM_CLK_RSTN_EN |
	      SOURCE_CIPHER_SYS_CLK_EN |
	      SOURCE_CIPHER_CHAR_CLK_RSTN_EN |
	      SOURCE_CIPHER_CHAR_CLK_EN;
	writel(val, dp->regs + SOURCE_CIPHER_CAR);

	val = SOURCE_CRYPTO_SYS_CLK_RSTN_EN |
	      SOURCE_CRYPTO_SYS_CLK_EN;
	writel(val, dp->regs + SOURCE_CRYPTO_CAR);

	/* enable Mailbox and PIF interrupt */
	writel(0, dp->regs + APB_INT_MASK);
}

__attribute__((used)) static int cdn_dp_mailbox_read(struct cdn_dp_device *dp)
{
	int val, ret;

	ret = readx_poll_timeout(readl, dp->regs + MAILBOX_EMPTY_ADDR,
				 val, !val, MAILBOX_RETRY_US,
				 MAILBOX_TIMEOUT_US);
	if (ret < 0)
		return ret;

	return readl(dp->regs + MAILBOX0_RD_DATA) & 0xff;
}

__attribute__((used)) static int cdp_dp_mailbox_write(struct cdn_dp_device *dp, u8 val)
{
	int ret, full;

	ret = readx_poll_timeout(readl, dp->regs + MAILBOX_FULL_ADDR,
				 full, !full, MAILBOX_RETRY_US,
				 MAILBOX_TIMEOUT_US);
	if (ret < 0)
		return ret;

	writel(val, dp->regs + MAILBOX0_WR_DATA);

	return 0;
}

__attribute__((used)) static int cdn_dp_mailbox_validate_receive(struct cdn_dp_device *dp,
					   u8 module_id, u8 opcode,
					   u8 req_size)
{
	u32 mbox_size, i;
	u8 header[4];
	int ret;

	/* read the header of the message */
	for (i = 0; i < 4; i++) {
		ret = cdn_dp_mailbox_read(dp);
		if (ret < 0)
			return ret;

		header[i] = ret;
	}

	mbox_size = (header[2] << 8) | header[3];

	if (opcode != header[0] || module_id != header[1] ||
	    req_size != mbox_size) {
		/*
		 * If the message in mailbox is not what we want, we need to
		 * clear the mailbox by reading its contents.
		 */
		for (i = 0; i < mbox_size; i++)
			if (cdn_dp_mailbox_read(dp) < 0)
				break;

		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int cdn_dp_mailbox_read_receive(struct cdn_dp_device *dp,
				       u8 *buff, u16 buff_size)
{
	u32 i;
	int ret;

	for (i = 0; i < buff_size; i++) {
		ret = cdn_dp_mailbox_read(dp);
		if (ret < 0)
			return ret;

		buff[i] = ret;
	}

	return 0;
}

__attribute__((used)) static int cdn_dp_mailbox_send(struct cdn_dp_device *dp, u8 module_id,
			       u8 opcode, u16 size, u8 *message)
{
	u8 header[4];
	int ret, i;

	header[0] = opcode;
	header[1] = module_id;
	header[2] = (size >> 8) & 0xff;
	header[3] = size & 0xff;

	for (i = 0; i < 4; i++) {
		ret = cdp_dp_mailbox_write(dp, header[i]);
		if (ret)
			return ret;
	}

	for (i = 0; i < size; i++) {
		ret = cdp_dp_mailbox_write(dp, message[i]);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int cdn_dp_reg_write(struct cdn_dp_device *dp, u16 addr, u32 val)
{
	u8 msg[6];

	msg[0] = (addr >> 8) & 0xff;
	msg[1] = addr & 0xff;
	msg[2] = (val >> 24) & 0xff;
	msg[3] = (val >> 16) & 0xff;
	msg[4] = (val >> 8) & 0xff;
	msg[5] = val & 0xff;
	return cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_WRITE_REGISTER,
				   sizeof(msg), msg);
}

__attribute__((used)) static int cdn_dp_reg_write_bit(struct cdn_dp_device *dp, u16 addr,
				u8 start_bit, u8 bits_no, u32 val)
{
	u8 field[8];

	field[0] = (addr >> 8) & 0xff;
	field[1] = addr & 0xff;
	field[2] = start_bit;
	field[3] = bits_no;
	field[4] = (val >> 24) & 0xff;
	field[5] = (val >> 16) & 0xff;
	field[6] = (val >> 8) & 0xff;
	field[7] = val & 0xff;

	return cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_WRITE_FIELD,
				   sizeof(field), field);
}

int cdn_dp_dpcd_read(struct cdn_dp_device *dp, u32 addr, u8 *data, u16 len)
{
	u8 msg[5], reg[5];
	int ret;

	msg[0] = (len >> 8) & 0xff;
	msg[1] = len & 0xff;
	msg[2] = (addr >> 16) & 0xff;
	msg[3] = (addr >> 8) & 0xff;
	msg[4] = addr & 0xff;
	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_READ_DPCD,
				  sizeof(msg), msg);
	if (ret)
		goto err_dpcd_read;

	ret = cdn_dp_mailbox_validate_receive(dp, MB_MODULE_ID_DP_TX,
					      DPTX_READ_DPCD,
					      sizeof(reg) + len);
	if (ret)
		goto err_dpcd_read;

	ret = cdn_dp_mailbox_read_receive(dp, reg, sizeof(reg));
	if (ret)
		goto err_dpcd_read;

	ret = cdn_dp_mailbox_read_receive(dp, data, len);

err_dpcd_read:
	return ret;
}

int cdn_dp_dpcd_write(struct cdn_dp_device *dp, u32 addr, u8 value)
{
	u8 msg[6], reg[5];
	int ret;

	msg[0] = 0;
	msg[1] = 1;
	msg[2] = (addr >> 16) & 0xff;
	msg[3] = (addr >> 8) & 0xff;
	msg[4] = addr & 0xff;
	msg[5] = value;
	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_WRITE_DPCD,
				  sizeof(msg), msg);
	if (ret)
		goto err_dpcd_write;

	ret = cdn_dp_mailbox_validate_receive(dp, MB_MODULE_ID_DP_TX,
					      DPTX_WRITE_DPCD, sizeof(reg));
	if (ret)
		goto err_dpcd_write;

	ret = cdn_dp_mailbox_read_receive(dp, reg, sizeof(reg));
	if (ret)
		goto err_dpcd_write;

	if (addr != (reg[2] << 16 | reg[3] << 8 | reg[4]))
		ret = -EINVAL;

err_dpcd_write:
	if (ret)
		DRM_DEV_ERROR(dp->dev, "dpcd write failed: %d\n", ret);
	return ret;
}

int cdn_dp_load_firmware(struct cdn_dp_device *dp, const u32 *i_mem,
			 u32 i_size, const u32 *d_mem, u32 d_size)
{
	u32 reg;
	int i, ret;

	/* reset ucpu before load firmware*/
	writel(APB_IRAM_PATH | APB_DRAM_PATH | APB_XT_RESET,
	       dp->regs + APB_CTRL);

	for (i = 0; i < i_size; i += 4)
		writel(*i_mem++, dp->regs + ADDR_IMEM + i);

	for (i = 0; i < d_size; i += 4)
		writel(*d_mem++, dp->regs + ADDR_DMEM + i);

	/* un-reset ucpu */
	writel(0, dp->regs + APB_CTRL);

	/* check the keep alive register to make sure fw working */
	ret = readx_poll_timeout(readl, dp->regs + KEEP_ALIVE,
				 reg, reg, 2000, FW_ALIVE_TIMEOUT_US);
	if (ret < 0) {
		DRM_DEV_ERROR(dp->dev, "failed to loaded the FW reg = %x\n",
			      reg);
		return -EINVAL;
	}

	reg = readl(dp->regs + VER_L) & 0xff;
	dp->fw_version = reg;
	reg = readl(dp->regs + VER_H) & 0xff;
	dp->fw_version |= reg << 8;
	reg = readl(dp->regs + VER_LIB_L_ADDR) & 0xff;
	dp->fw_version |= reg << 16;
	reg = readl(dp->regs + VER_LIB_H_ADDR) & 0xff;
	dp->fw_version |= reg << 24;

	DRM_DEV_DEBUG(dp->dev, "firmware version: %x\n", dp->fw_version);

	return 0;
}

int cdn_dp_set_firmware_active(struct cdn_dp_device *dp, bool enable)
{
	u8 msg[5];
	int ret, i;

	msg[0] = GENERAL_MAIN_CONTROL;
	msg[1] = MB_MODULE_ID_GENERAL;
	msg[2] = 0;
	msg[3] = 1;
	msg[4] = enable ? FW_ACTIVE : FW_STANDBY;

	for (i = 0; i < sizeof(msg); i++) {
		ret = cdp_dp_mailbox_write(dp, msg[i]);
		if (ret)
			goto err_set_firmware_active;
	}

	/* read the firmware state */
	for (i = 0; i < sizeof(msg); i++)  {
		ret = cdn_dp_mailbox_read(dp);
		if (ret < 0)
			goto err_set_firmware_active;

		msg[i] = ret;
	}

	ret = 0;

err_set_firmware_active:
	if (ret < 0)
		DRM_DEV_ERROR(dp->dev, "set firmware active failed\n");
	return ret;
}

int cdn_dp_set_host_cap(struct cdn_dp_device *dp, u8 lanes, bool flip)
{
	u8 msg[8];
	int ret;

	msg[0] = CDN_DP_MAX_LINK_RATE;
	msg[1] = lanes | SCRAMBLER_EN;
	msg[2] = VOLTAGE_LEVEL_2;
	msg[3] = PRE_EMPHASIS_LEVEL_3;
	msg[4] = PTS1 | PTS2 | PTS3 | PTS4;
	msg[5] = FAST_LT_NOT_SUPPORT;
	msg[6] = flip ? LANE_MAPPING_FLIPPED : LANE_MAPPING_NORMAL;
	msg[7] = ENHANCED;

	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX,
				  DPTX_SET_HOST_CAPABILITIES,
				  sizeof(msg), msg);
	if (ret)
		goto err_set_host_cap;

	ret = cdn_dp_reg_write(dp, DP_AUX_SWAP_INVERSION_CONTROL,
			       AUX_HOST_INVERT);

err_set_host_cap:
	if (ret)
		DRM_DEV_ERROR(dp->dev, "set host cap failed: %d\n", ret);
	return ret;
}

int cdn_dp_event_config(struct cdn_dp_device *dp)
{
	u8 msg[5];
	int ret;

	memset(msg, 0, sizeof(msg));

	msg[0] = DPTX_EVENT_ENABLE_HPD | DPTX_EVENT_ENABLE_TRAINING;

	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_ENABLE_EVENT,
				  sizeof(msg), msg);
	if (ret)
		DRM_DEV_ERROR(dp->dev, "set event config failed: %d\n", ret);

	return ret;
}

u32 cdn_dp_get_event(struct cdn_dp_device *dp)
{
	return readl(dp->regs + SW_EVENTS0);
}

int cdn_dp_get_hpd_status(struct cdn_dp_device *dp)
{
	u8 status;
	int ret;

	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_HPD_STATE,
				  0, NULL);
	if (ret)
		goto err_get_hpd;

	ret = cdn_dp_mailbox_validate_receive(dp, MB_MODULE_ID_DP_TX,
					      DPTX_HPD_STATE, sizeof(status));
	if (ret)
		goto err_get_hpd;

	ret = cdn_dp_mailbox_read_receive(dp, &status, sizeof(status));
	if (ret)
		goto err_get_hpd;

	return status;

err_get_hpd:
	DRM_DEV_ERROR(dp->dev, "get hpd status failed: %d\n", ret);
	return ret;
}

int cdn_dp_get_edid_block(void *data, u8 *edid,
			  unsigned int block, size_t length)
{
	struct cdn_dp_device *dp = data;
	u8 msg[2], reg[2], i;
	int ret;

	for (i = 0; i < 4; i++) {
		msg[0] = block / 2;
		msg[1] = block % 2;

		ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_GET_EDID,
					  sizeof(msg), msg);
		if (ret)
			continue;

		ret = cdn_dp_mailbox_validate_receive(dp, MB_MODULE_ID_DP_TX,
						      DPTX_GET_EDID,
						      sizeof(reg) + length);
		if (ret)
			continue;

		ret = cdn_dp_mailbox_read_receive(dp, reg, sizeof(reg));
		if (ret)
			continue;

		ret = cdn_dp_mailbox_read_receive(dp, edid, length);
		if (ret)
			continue;

		if (reg[0] == length && reg[1] == block / 2)
			break;
	}

	if (ret)
		DRM_DEV_ERROR(dp->dev, "get block[%d] edid failed: %d\n", block,
			      ret);

	return ret;
}

__attribute__((used)) static int cdn_dp_training_start(struct cdn_dp_device *dp)
{
	unsigned long timeout;
	u8 msg, event[2];
	int ret;

	msg = LINK_TRAINING_RUN;

	/* start training */
	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_TRAINING_CONTROL,
				  sizeof(msg), &msg);
	if (ret)
		goto err_training_start;

	timeout = jiffies + msecs_to_jiffies(LINK_TRAINING_TIMEOUT_MS);
	while (time_before(jiffies, timeout)) {
		msleep(LINK_TRAINING_RETRY_MS);
		ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX,
					  DPTX_READ_EVENT, 0, NULL);
		if (ret)
			goto err_training_start;

		ret = cdn_dp_mailbox_validate_receive(dp, MB_MODULE_ID_DP_TX,
						      DPTX_READ_EVENT,
						      sizeof(event));
		if (ret)
			goto err_training_start;

		ret = cdn_dp_mailbox_read_receive(dp, event, sizeof(event));
		if (ret)
			goto err_training_start;

		if (event[1] & EQ_PHASE_FINISHED)
			return 0;
	}

	ret = -ETIMEDOUT;

err_training_start:
	DRM_DEV_ERROR(dp->dev, "training failed: %d\n", ret);
	return ret;
}

__attribute__((used)) static int cdn_dp_get_training_status(struct cdn_dp_device *dp)
{
	u8 status[10];
	int ret;

	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_READ_LINK_STAT,
				  0, NULL);
	if (ret)
		goto err_get_training_status;

	ret = cdn_dp_mailbox_validate_receive(dp, MB_MODULE_ID_DP_TX,
					      DPTX_READ_LINK_STAT,
					      sizeof(status));
	if (ret)
		goto err_get_training_status;

	ret = cdn_dp_mailbox_read_receive(dp, status, sizeof(status));
	if (ret)
		goto err_get_training_status;

	dp->link.rate = status[0];
	dp->link.num_lanes = status[1];

err_get_training_status:
	if (ret)
		DRM_DEV_ERROR(dp->dev, "get training status failed: %d\n", ret);
	return ret;
}

int cdn_dp_train_link(struct cdn_dp_device *dp)
{
	int ret;

	ret = cdn_dp_training_start(dp);
	if (ret) {
		DRM_DEV_ERROR(dp->dev, "Failed to start training %d\n", ret);
		return ret;
	}

	ret = cdn_dp_get_training_status(dp);
	if (ret) {
		DRM_DEV_ERROR(dp->dev, "Failed to get training stat %d\n", ret);
		return ret;
	}

	DRM_DEV_DEBUG_KMS(dp->dev, "rate:0x%x, lanes:%d\n", dp->link.rate,
			  dp->link.num_lanes);
	return ret;
}

int cdn_dp_set_video_status(struct cdn_dp_device *dp, int active)
{
	u8 msg;
	int ret;

	msg = !!active;

	ret = cdn_dp_mailbox_send(dp, MB_MODULE_ID_DP_TX, DPTX_SET_VIDEO,
				  sizeof(msg), &msg);
	if (ret)
		DRM_DEV_ERROR(dp->dev, "set video status failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static int cdn_dp_get_msa_misc(struct video_info *video,
			       struct drm_display_mode *mode)
{
	u32 msa_misc;
	u8 val[2] = {0};

	switch (video->color_fmt) {
	case PXL_RGB:
	case Y_ONLY:
		val[0] = 0;
		break;
	/* set YUV default color space conversion to BT601 */
	case YCBCR_4_4_4:
		val[0] = 6 + BT_601 * 8;
		break;
	case YCBCR_4_2_2:
		val[0] = 5 + BT_601 * 8;
		break;
	case YCBCR_4_2_0:
		val[0] = 5;
		break;
	};

	switch (video->color_depth) {
	case 6:
		val[1] = 0;
		break;
	case 8:
		val[1] = 1;
		break;
	case 10:
		val[1] = 2;
		break;
	case 12:
		val[1] = 3;
		break;
	case 16:
		val[1] = 4;
		break;
	};

	msa_misc = 2 * val[0] + 32 * val[1] +
		   ((video->color_fmt == Y_ONLY) ? (1 << 14) : 0);

	return msa_misc;
}

int cdn_dp_config_video(struct cdn_dp_device *dp)
{
	struct video_info *video = &dp->video_info;
	struct drm_display_mode *mode = &dp->mode;
	u64 symbol;
	u32 val, link_rate, rem;
	u8 bit_per_pix, tu_size_reg = TU_SIZE;
	int ret;

	bit_per_pix = (video->color_fmt == YCBCR_4_2_2) ?
		      (video->color_depth * 2) : (video->color_depth * 3);

	link_rate = drm_dp_bw_code_to_link_rate(dp->link.rate) / 1000;

	ret = cdn_dp_reg_write(dp, BND_HSYNC2VSYNC, VIF_BYPASS_INTERLACE);
	if (ret)
		goto err_config_video;

	ret = cdn_dp_reg_write(dp, HSYNC2VSYNC_POL_CTRL, 0);
	if (ret)
		goto err_config_video;

	/*
	 * get a best tu_size and valid symbol:
	 * 1. chose Lclk freq(162Mhz, 270Mhz, 540Mhz), set TU to 32
	 * 2. calculate VS(valid symbol) = TU * Pclk * Bpp / (Lclk * Lanes)
	 * 3. if VS > *.85 or VS < *.1 or VS < 2 or TU < VS + 4, then set
	 *    TU += 2 and repeat 2nd step.
	 */
	do {
		tu_size_reg += 2;
		symbol = tu_size_reg * mode->clock * bit_per_pix;
		do_div(symbol, dp->link.num_lanes * link_rate * 8);
		rem = do_div(symbol, 1000);
		if (tu_size_reg > 64) {
			ret = -EINVAL;
			DRM_DEV_ERROR(dp->dev,
				      "tu error, clk:%d, lanes:%d, rate:%d\n",
				      mode->clock, dp->link.num_lanes,
				      link_rate);
			goto err_config_video;
		}
	} while ((symbol <= 1) || (tu_size_reg - symbol < 4) ||
		 (rem > 850) || (rem < 100));

	val = symbol + (tu_size_reg << 8);
	val |= TU_CNT_RST_EN;
	ret = cdn_dp_reg_write(dp, DP_FRAMER_TU, val);
	if (ret)
		goto err_config_video;

	/* set the FIFO Buffer size */
	val = div_u64(mode->clock * (symbol + 1), 1000) + link_rate;
	val /= (dp->link.num_lanes * link_rate);
	val = div_u64(8 * (symbol + 1), bit_per_pix) - val;
	val += 2;
	ret = cdn_dp_reg_write(dp, DP_VC_TABLE(15), val);

	switch (video->color_depth) {
	case 6:
		val = BCS_6;
		break;
	case 8:
		val = BCS_8;
		break;
	case 10:
		val = BCS_10;
		break;
	case 12:
		val = BCS_12;
		break;
	case 16:
		val = BCS_16;
		break;
	};

	val += video->color_fmt << 8;
	ret = cdn_dp_reg_write(dp, DP_FRAMER_PXL_REPR, val);
	if (ret)
		goto err_config_video;

	val = video->h_sync_polarity ? DP_FRAMER_SP_HSP : 0;
	val |= video->v_sync_polarity ? DP_FRAMER_SP_VSP : 0;
	ret = cdn_dp_reg_write(dp, DP_FRAMER_SP, val);
	if (ret)
		goto err_config_video;

	val = (mode->hsync_start - mode->hdisplay) << 16;
	val |= mode->htotal - mode->hsync_end;
	ret = cdn_dp_reg_write(dp, DP_FRONT_BACK_PORCH, val);
	if (ret)
		goto err_config_video;

	val = mode->hdisplay * bit_per_pix / 8;
	ret = cdn_dp_reg_write(dp, DP_BYTE_COUNT, val);
	if (ret)
		goto err_config_video;

	val = mode->htotal | ((mode->htotal - mode->hsync_start) << 16);
	ret = cdn_dp_reg_write(dp, MSA_HORIZONTAL_0, val);
	if (ret)
		goto err_config_video;

	val = mode->hsync_end - mode->hsync_start;
	val |= (mode->hdisplay << 16) | (video->h_sync_polarity << 15);
	ret = cdn_dp_reg_write(dp, MSA_HORIZONTAL_1, val);
	if (ret)
		goto err_config_video;

	val = mode->vtotal;
	val |= (mode->vtotal - mode->vsync_start) << 16;
	ret = cdn_dp_reg_write(dp, MSA_VERTICAL_0, val);
	if (ret)
		goto err_config_video;

	val = mode->vsync_end - mode->vsync_start;
	val |= (mode->vdisplay << 16) | (video->v_sync_polarity << 15);
	ret = cdn_dp_reg_write(dp, MSA_VERTICAL_1, val);
	if (ret)
		goto err_config_video;

	val = cdn_dp_get_msa_misc(video, mode);
	ret = cdn_dp_reg_write(dp, MSA_MISC, val);
	if (ret)
		goto err_config_video;

	ret = cdn_dp_reg_write(dp, STREAM_CONFIG, 1);
	if (ret)
		goto err_config_video;

	val = mode->hsync_end - mode->hsync_start;
	val |= mode->hdisplay << 16;
	ret = cdn_dp_reg_write(dp, DP_HORIZONTAL, val);
	if (ret)
		goto err_config_video;

	val = mode->vdisplay;
	val |= (mode->vtotal - mode->vsync_start) << 16;
	ret = cdn_dp_reg_write(dp, DP_VERTICAL_0, val);
	if (ret)
		goto err_config_video;

	val = mode->vtotal;
	ret = cdn_dp_reg_write(dp, DP_VERTICAL_1, val);
	if (ret)
		goto err_config_video;

	ret = cdn_dp_reg_write_bit(dp, DP_VB_ID, 2, 1, 0);

err_config_video:
	if (ret)
		DRM_DEV_ERROR(dp->dev, "config video failed: %d\n", ret);
	return ret;
}

int cdn_dp_audio_stop(struct cdn_dp_device *dp, struct audio_info *audio)
{
	int ret;

	ret = cdn_dp_reg_write(dp, AUDIO_PACK_CONTROL, 0);
	if (ret) {
		DRM_DEV_ERROR(dp->dev, "audio stop failed: %d\n", ret);
		return ret;
	}

	writel(0, dp->regs + SPDIF_CTRL_ADDR);

	/* clearn the audio config and reset */
	writel(0, dp->regs + AUDIO_SRC_CNTL);
	writel(0, dp->regs + AUDIO_SRC_CNFG);
	writel(AUDIO_SW_RST, dp->regs + AUDIO_SRC_CNTL);
	writel(0, dp->regs + AUDIO_SRC_CNTL);

	/* reset smpl2pckt component  */
	writel(0, dp->regs + SMPL2PKT_CNTL);
	writel(AUDIO_SW_RST, dp->regs + SMPL2PKT_CNTL);
	writel(0, dp->regs + SMPL2PKT_CNTL);

	/* reset FIFO */
	writel(AUDIO_SW_RST, dp->regs + FIFO_CNTL);
	writel(0, dp->regs + FIFO_CNTL);

	if (audio->format == AFMT_SPDIF)
		clk_disable_unprepare(dp->spdif_clk);

	return 0;
}

int cdn_dp_audio_mute(struct cdn_dp_device *dp, bool enable)
{
	int ret;

	ret = cdn_dp_reg_write_bit(dp, DP_VB_ID, 4, 1, enable);
	if (ret)
		DRM_DEV_ERROR(dp->dev, "audio mute failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static void cdn_dp_audio_config_i2s(struct cdn_dp_device *dp,
				    struct audio_info *audio)
{
	int sub_pckt_num = 1, i2s_port_en_val = 0xf, i;
	u32 val;

	if (audio->channels == 2) {
		if (dp->link.num_lanes == 1)
			sub_pckt_num = 2;
		else
			sub_pckt_num = 4;

		i2s_port_en_val = 1;
	} else if (audio->channels == 4) {
		i2s_port_en_val = 3;
	}

	writel(0x0, dp->regs + SPDIF_CTRL_ADDR);

	writel(SYNC_WR_TO_CH_ZERO, dp->regs + FIFO_CNTL);

	val = MAX_NUM_CH(audio->channels);
	val |= NUM_OF_I2S_PORTS(audio->channels);
	val |= AUDIO_TYPE_LPCM;
	val |= CFG_SUB_PCKT_NUM(sub_pckt_num);
	writel(val, dp->regs + SMPL2PKT_CNFG);

	if (audio->sample_width == 16)
		val = 0;
	else if (audio->sample_width == 24)
		val = 1 << 9;
	else
		val = 2 << 9;

	val |= AUDIO_CH_NUM(audio->channels);
	val |= I2S_DEC_PORT_EN(i2s_port_en_val);
	val |= TRANS_SMPL_WIDTH_32;
	writel(val, dp->regs + AUDIO_SRC_CNFG);

	for (i = 0; i < (audio->channels + 1) / 2; i++) {
		if (audio->sample_width == 16)
			val = (0x02 << 8) | (0x02 << 20);
		else if (audio->sample_width == 24)
			val = (0x0b << 8) | (0x0b << 20);

		val |= ((2 * i) << 4) | ((2 * i + 1) << 16);
		writel(val, dp->regs + STTS_BIT_CH(i));
	}

	switch (audio->sample_rate) {
	case 32000:
		val = SAMPLING_FREQ(3) |
		      ORIGINAL_SAMP_FREQ(0xc);
		break;
	case 44100:
		val = SAMPLING_FREQ(0) |
		      ORIGINAL_SAMP_FREQ(0xf);
		break;
	case 48000:
		val = SAMPLING_FREQ(2) |
		      ORIGINAL_SAMP_FREQ(0xd);
		break;
	case 88200:
		val = SAMPLING_FREQ(8) |
		      ORIGINAL_SAMP_FREQ(0x7);
		break;
	case 96000:
		val = SAMPLING_FREQ(0xa) |
		      ORIGINAL_SAMP_FREQ(5);
		break;
	case 176400:
		val = SAMPLING_FREQ(0xc) |
		      ORIGINAL_SAMP_FREQ(3);
		break;
	case 192000:
		val = SAMPLING_FREQ(0xe) |
		      ORIGINAL_SAMP_FREQ(1);
		break;
	}
	val |= 4;
	writel(val, dp->regs + COM_CH_STTS_BITS);

	writel(SMPL2PKT_EN, dp->regs + SMPL2PKT_CNTL);
	writel(I2S_DEC_START, dp->regs + AUDIO_SRC_CNTL);
}

__attribute__((used)) static void cdn_dp_audio_config_spdif(struct cdn_dp_device *dp)
{
	u32 val;

	writel(SYNC_WR_TO_CH_ZERO, dp->regs + FIFO_CNTL);

	val = MAX_NUM_CH(2) | AUDIO_TYPE_LPCM | CFG_SUB_PCKT_NUM(4);
	writel(val, dp->regs + SMPL2PKT_CNFG);
	writel(SMPL2PKT_EN, dp->regs + SMPL2PKT_CNTL);

	val = SPDIF_ENABLE | SPDIF_AVG_SEL | SPDIF_JITTER_BYPASS;
	writel(val, dp->regs + SPDIF_CTRL_ADDR);

	clk_prepare_enable(dp->spdif_clk);
	clk_set_rate(dp->spdif_clk, CDN_DP_SPDIF_CLK);
}

int cdn_dp_audio_config(struct cdn_dp_device *dp, struct audio_info *audio)
{
	int ret;

	/* reset the spdif clk before config */
	if (audio->format == AFMT_SPDIF) {
		reset_control_assert(dp->spdif_rst);
		reset_control_deassert(dp->spdif_rst);
	}

	ret = cdn_dp_reg_write(dp, CM_LANE_CTRL, LANE_REF_CYC);
	if (ret)
		goto err_audio_config;

	ret = cdn_dp_reg_write(dp, CM_CTRL, 0);
	if (ret)
		goto err_audio_config;

	if (audio->format == AFMT_I2S)
		cdn_dp_audio_config_i2s(dp, audio);
	else if (audio->format == AFMT_SPDIF)
		cdn_dp_audio_config_spdif(dp);

	ret = cdn_dp_reg_write(dp, AUDIO_PACK_CONTROL, AUDIO_PACK_EN);

err_audio_config:
	if (ret)
		DRM_DEV_ERROR(dp->dev, "audio config failed: %d\n", ret);
	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct s5p_mfc_hw_cmds {int dummy; } ;
struct TYPE_7__ {int dma; } ;
struct s5p_mfc_dev {int /*<<< orphan*/  curr_ctx; TYPE_3__ ctx_buf; int /*<<< orphan*/  mfc_ops; TYPE_2__* variant; } ;
struct TYPE_8__ {int dma; int size; } ;
struct s5p_mfc_ctx {int codec_mode; scalar_t__ state; int inst_no; int /*<<< orphan*/  num; struct s5p_mfc_dev* dev; TYPE_4__ ctx; } ;
struct s5p_mfc_cmd_args {int dummy; } ;
struct s5p_mfc_buf_size_v6 {int dev_ctx; } ;
struct TYPE_6__ {TYPE_1__* buf_size; } ;
struct TYPE_5__ {struct s5p_mfc_buf_size_v6* priv; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ MFCINST_FREE ; 
 int S5P_FIMV_CODEC_H263_DEC_V6 ; 
 int S5P_FIMV_CODEC_H263_ENC_V6 ; 
 int S5P_FIMV_CODEC_H264_DEC_V6 ; 
 int S5P_FIMV_CODEC_H264_ENC_V6 ; 
 int S5P_FIMV_CODEC_H264_MVC_DEC_V6 ; 
 int S5P_FIMV_CODEC_H264_MVC_ENC_V6 ; 
 int S5P_FIMV_CODEC_HEVC_DEC ; 
 int S5P_FIMV_CODEC_HEVC_ENC ; 
 int S5P_FIMV_CODEC_MPEG2_DEC_V6 ; 
 int S5P_FIMV_CODEC_MPEG4_DEC_V6 ; 
 int S5P_FIMV_CODEC_MPEG4_ENC_V6 ; 
 int S5P_FIMV_CODEC_NONE_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_CODEC_TYPE_V6 ; 
 int S5P_FIMV_CODEC_VC1RCV_DEC_V6 ; 
 int S5P_FIMV_CODEC_VC1_DEC_V6 ; 
 int S5P_FIMV_CODEC_VP8_DEC_V6 ; 
 int S5P_FIMV_CODEC_VP8_ENC_V7 ; 
 int S5P_FIMV_CODEC_VP9_DEC ; 
 int /*<<< orphan*/  S5P_FIMV_CONTEXT_MEM_ADDR_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_CONTEXT_MEM_SIZE_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_D_CRC_CTRL_V6 ; 
 int S5P_FIMV_H2R_CMD_CLOSE_INSTANCE_V6 ; 
 int S5P_FIMV_H2R_CMD_OPEN_INSTANCE_V6 ; 
 int S5P_FIMV_H2R_CMD_SLEEP_V6 ; 
 int S5P_FIMV_H2R_CMD_SYS_INIT_V6 ; 
 int S5P_FIMV_H2R_CMD_WAKEUP_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_CMD_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_INT_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_INSTANCE_ID_V6 ; 
 int /*<<< orphan*/  S5P_FIMV_RISC2HOST_CMD_V6 ; 
#define  S5P_MFC_CODEC_H263_DEC 143 
#define  S5P_MFC_CODEC_H263_ENC 142 
#define  S5P_MFC_CODEC_H264_DEC 141 
#define  S5P_MFC_CODEC_H264_ENC 140 
#define  S5P_MFC_CODEC_H264_MVC_DEC 139 
#define  S5P_MFC_CODEC_H264_MVC_ENC 138 
#define  S5P_MFC_CODEC_HEVC_DEC 137 
#define  S5P_MFC_CODEC_HEVC_ENC 136 
#define  S5P_MFC_CODEC_MPEG2_DEC 135 
#define  S5P_MFC_CODEC_MPEG4_DEC 134 
#define  S5P_MFC_CODEC_MPEG4_ENC 133 
#define  S5P_MFC_CODEC_VC1RCV_DEC 132 
#define  S5P_MFC_CODEC_VC1_DEC 131 
#define  S5P_MFC_CODEC_VP8_DEC 130 
#define  S5P_MFC_CODEC_VP8_ENC 129 
#define  S5P_MFC_CODEC_VP9_DEC 128 
 int /*<<< orphan*/  alloc_dev_context_buffer ; 
 int /*<<< orphan*/  memset (struct s5p_mfc_cmd_args*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mfc_debug (int,char*,int) ; 
 int /*<<< orphan*/  mfc_write (struct s5p_mfc_dev*,int,int /*<<< orphan*/ ) ; 
 struct s5p_mfc_hw_cmds s5p_mfc_cmds_v6 ; 
 int s5p_mfc_hw_call (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct s5p_mfc_dev*) ; 

__attribute__((used)) static int s5p_mfc_cmd_host2risc_v6(struct s5p_mfc_dev *dev, int cmd,
				struct s5p_mfc_cmd_args *args)
{
	mfc_debug(2, "Issue the command: %d\n", cmd);

	/* Reset RISC2HOST command */
	mfc_write(dev, 0x0, S5P_FIMV_RISC2HOST_CMD_V6);

	/* Issue the command */
	mfc_write(dev, cmd, S5P_FIMV_HOST2RISC_CMD_V6);
	mfc_write(dev, 0x1, S5P_FIMV_HOST2RISC_INT_V6);

	return 0;
}

__attribute__((used)) static int s5p_mfc_sys_init_cmd_v6(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_cmd_args h2r_args;
	struct s5p_mfc_buf_size_v6 *buf_size = dev->variant->buf_size->priv;
	int ret;

	ret = s5p_mfc_hw_call(dev->mfc_ops, alloc_dev_context_buffer, dev);
	if (ret)
		return ret;

	mfc_write(dev, dev->ctx_buf.dma, S5P_FIMV_CONTEXT_MEM_ADDR_V6);
	mfc_write(dev, buf_size->dev_ctx, S5P_FIMV_CONTEXT_MEM_SIZE_V6);
	return s5p_mfc_cmd_host2risc_v6(dev, S5P_FIMV_H2R_CMD_SYS_INIT_V6,
					&h2r_args);
}

__attribute__((used)) static int s5p_mfc_sleep_cmd_v6(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_cmd_args h2r_args;

	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	return s5p_mfc_cmd_host2risc_v6(dev, S5P_FIMV_H2R_CMD_SLEEP_V6,
			&h2r_args);
}

__attribute__((used)) static int s5p_mfc_wakeup_cmd_v6(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_cmd_args h2r_args;

	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	return s5p_mfc_cmd_host2risc_v6(dev, S5P_FIMV_H2R_CMD_WAKEUP_V6,
					&h2r_args);
}

__attribute__((used)) static int s5p_mfc_open_inst_cmd_v6(struct s5p_mfc_ctx *ctx)
{
	struct s5p_mfc_dev *dev = ctx->dev;
	struct s5p_mfc_cmd_args h2r_args;
	int codec_type;

	mfc_debug(2, "Requested codec mode: %d\n", ctx->codec_mode);
	dev->curr_ctx = ctx->num;
	switch (ctx->codec_mode) {
	case S5P_MFC_CODEC_H264_DEC:
		codec_type = S5P_FIMV_CODEC_H264_DEC_V6;
		break;
	case S5P_MFC_CODEC_H264_MVC_DEC:
		codec_type = S5P_FIMV_CODEC_H264_MVC_DEC_V6;
		break;
	case S5P_MFC_CODEC_VC1_DEC:
		codec_type = S5P_FIMV_CODEC_VC1_DEC_V6;
		break;
	case S5P_MFC_CODEC_MPEG4_DEC:
		codec_type = S5P_FIMV_CODEC_MPEG4_DEC_V6;
		break;
	case S5P_MFC_CODEC_MPEG2_DEC:
		codec_type = S5P_FIMV_CODEC_MPEG2_DEC_V6;
		break;
	case S5P_MFC_CODEC_H263_DEC:
		codec_type = S5P_FIMV_CODEC_H263_DEC_V6;
		break;
	case S5P_MFC_CODEC_VC1RCV_DEC:
		codec_type = S5P_FIMV_CODEC_VC1RCV_DEC_V6;
		break;
	case S5P_MFC_CODEC_VP8_DEC:
		codec_type = S5P_FIMV_CODEC_VP8_DEC_V6;
		break;
	case S5P_MFC_CODEC_HEVC_DEC:
		codec_type = S5P_FIMV_CODEC_HEVC_DEC;
		break;
	case S5P_MFC_CODEC_VP9_DEC:
		codec_type = S5P_FIMV_CODEC_VP9_DEC;
		break;
	case S5P_MFC_CODEC_H264_ENC:
		codec_type = S5P_FIMV_CODEC_H264_ENC_V6;
		break;
	case S5P_MFC_CODEC_H264_MVC_ENC:
		codec_type = S5P_FIMV_CODEC_H264_MVC_ENC_V6;
		break;
	case S5P_MFC_CODEC_MPEG4_ENC:
		codec_type = S5P_FIMV_CODEC_MPEG4_ENC_V6;
		break;
	case S5P_MFC_CODEC_H263_ENC:
		codec_type = S5P_FIMV_CODEC_H263_ENC_V6;
		break;
	case S5P_MFC_CODEC_VP8_ENC:
		codec_type = S5P_FIMV_CODEC_VP8_ENC_V7;
		break;
	case S5P_MFC_CODEC_HEVC_ENC:
		codec_type = S5P_FIMV_CODEC_HEVC_ENC;
		break;
	default:
		codec_type = S5P_FIMV_CODEC_NONE_V6;
	}
	mfc_write(dev, codec_type, S5P_FIMV_CODEC_TYPE_V6);
	mfc_write(dev, ctx->ctx.dma, S5P_FIMV_CONTEXT_MEM_ADDR_V6);
	mfc_write(dev, ctx->ctx.size, S5P_FIMV_CONTEXT_MEM_SIZE_V6);
	mfc_write(dev, 0, S5P_FIMV_D_CRC_CTRL_V6); /* no crc */

	return s5p_mfc_cmd_host2risc_v6(dev, S5P_FIMV_H2R_CMD_OPEN_INSTANCE_V6,
					&h2r_args);
}

__attribute__((used)) static int s5p_mfc_close_inst_cmd_v6(struct s5p_mfc_ctx *ctx)
{
	struct s5p_mfc_dev *dev = ctx->dev;
	struct s5p_mfc_cmd_args h2r_args;
	int ret = 0;

	dev->curr_ctx = ctx->num;
	if (ctx->state != MFCINST_FREE) {
		mfc_write(dev, ctx->inst_no, S5P_FIMV_INSTANCE_ID_V6);
		ret = s5p_mfc_cmd_host2risc_v6(dev,
					S5P_FIMV_H2R_CMD_CLOSE_INSTANCE_V6,
					&h2r_args);
	} else {
		ret = -EINVAL;
	}

	return ret;
}

struct s5p_mfc_hw_cmds *s5p_mfc_init_hw_cmds_v6(void)
{
	return &s5p_mfc_cmds_v6;
}


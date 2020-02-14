#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct s5p_mfc_hw_cmds {int dummy; } ;
struct TYPE_3__ {int size; } ;
struct s5p_mfc_dev {int /*<<< orphan*/  curr_ctx; TYPE_1__ fw_buf; } ;
struct TYPE_4__ {int ofs; int size; } ;
struct s5p_mfc_ctx {int codec_mode; scalar_t__ state; int inst_no; int /*<<< orphan*/  num; struct s5p_mfc_dev* dev; TYPE_2__ ctx; } ;
struct s5p_mfc_cmd_args {int* arg; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 void* MFCINST_ERROR ; 
 scalar_t__ MFCINST_FREE ; 
 int /*<<< orphan*/  MFC_BW_TIMEOUT ; 
 int S5P_FIMV_CODEC_H263_DEC ; 
 int S5P_FIMV_CODEC_H263_ENC ; 
 int S5P_FIMV_CODEC_H264_DEC ; 
 int S5P_FIMV_CODEC_H264_ENC ; 
 int S5P_FIMV_CODEC_MPEG2_DEC ; 
 int S5P_FIMV_CODEC_MPEG4_DEC ; 
 int S5P_FIMV_CODEC_MPEG4_ENC ; 
 int S5P_FIMV_CODEC_NONE ; 
 int S5P_FIMV_CODEC_VC1RCV_DEC ; 
 int S5P_FIMV_CODEC_VC1_DEC ; 
 int S5P_FIMV_H2R_CMD_CLOSE_INSTANCE ; 
 int S5P_FIMV_H2R_CMD_EMPTY ; 
 int S5P_FIMV_H2R_CMD_OPEN_INSTANCE ; 
 int S5P_FIMV_H2R_CMD_SLEEP ; 
 int S5P_FIMV_H2R_CMD_SYS_INIT ; 
 int S5P_FIMV_H2R_CMD_WAKEUP ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_ARG1 ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_ARG2 ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_ARG3 ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_ARG4 ; 
 int /*<<< orphan*/  S5P_FIMV_HOST2RISC_CMD ; 
#define  S5P_MFC_CODEC_H263_DEC 136 
#define  S5P_MFC_CODEC_H263_ENC 135 
#define  S5P_MFC_CODEC_H264_DEC 134 
#define  S5P_MFC_CODEC_H264_ENC 133 
#define  S5P_MFC_CODEC_MPEG2_DEC 132 
#define  S5P_MFC_CODEC_MPEG4_DEC 131 
#define  S5P_MFC_CODEC_MPEG4_ENC 130 
#define  S5P_MFC_CODEC_VC1RCV_DEC 129 
#define  S5P_MFC_CODEC_VC1_DEC 128 
 unsigned long jiffies ; 
 int /*<<< orphan*/  memset (struct s5p_mfc_cmd_args*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mfc_debug (int,char*,int) ; 
 int /*<<< orphan*/  mfc_err (char*) ; 
 int mfc_read (struct s5p_mfc_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mfc_write (struct s5p_mfc_dev*,int,int /*<<< orphan*/ ) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 struct s5p_mfc_hw_cmds s5p_mfc_cmds_v5 ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 

__attribute__((used)) static int s5p_mfc_cmd_host2risc_v5(struct s5p_mfc_dev *dev, int cmd,
				struct s5p_mfc_cmd_args *args)
{
	int cur_cmd;
	unsigned long timeout;

	timeout = jiffies + msecs_to_jiffies(MFC_BW_TIMEOUT);
	/* wait until host to risc command register becomes 'H2R_CMD_EMPTY' */
	do {
		if (time_after(jiffies, timeout)) {
			mfc_err("Timeout while waiting for hardware\n");
			return -EIO;
		}
		cur_cmd = mfc_read(dev, S5P_FIMV_HOST2RISC_CMD);
	} while (cur_cmd != S5P_FIMV_H2R_CMD_EMPTY);
	mfc_write(dev, args->arg[0], S5P_FIMV_HOST2RISC_ARG1);
	mfc_write(dev, args->arg[1], S5P_FIMV_HOST2RISC_ARG2);
	mfc_write(dev, args->arg[2], S5P_FIMV_HOST2RISC_ARG3);
	mfc_write(dev, args->arg[3], S5P_FIMV_HOST2RISC_ARG4);
	/* Issue the command */
	mfc_write(dev, cmd, S5P_FIMV_HOST2RISC_CMD);
	return 0;
}

__attribute__((used)) static int s5p_mfc_sys_init_cmd_v5(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_cmd_args h2r_args;

	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	h2r_args.arg[0] = dev->fw_buf.size;
	return s5p_mfc_cmd_host2risc_v5(dev, S5P_FIMV_H2R_CMD_SYS_INIT,
			&h2r_args);
}

__attribute__((used)) static int s5p_mfc_sleep_cmd_v5(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_cmd_args h2r_args;

	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	return s5p_mfc_cmd_host2risc_v5(dev, S5P_FIMV_H2R_CMD_SLEEP, &h2r_args);
}

__attribute__((used)) static int s5p_mfc_wakeup_cmd_v5(struct s5p_mfc_dev *dev)
{
	struct s5p_mfc_cmd_args h2r_args;

	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	return s5p_mfc_cmd_host2risc_v5(dev, S5P_FIMV_H2R_CMD_WAKEUP,
			&h2r_args);
}

__attribute__((used)) static int s5p_mfc_open_inst_cmd_v5(struct s5p_mfc_ctx *ctx)
{
	struct s5p_mfc_dev *dev = ctx->dev;
	struct s5p_mfc_cmd_args h2r_args;
	int ret;

	/* Preparing decoding - getting instance number */
	mfc_debug(2, "Getting instance number (codec: %d)\n", ctx->codec_mode);
	dev->curr_ctx = ctx->num;
	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	switch (ctx->codec_mode) {
	case S5P_MFC_CODEC_H264_DEC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_H264_DEC;
		break;
	case S5P_MFC_CODEC_VC1_DEC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_VC1_DEC;
		break;
	case S5P_MFC_CODEC_MPEG4_DEC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_MPEG4_DEC;
		break;
	case S5P_MFC_CODEC_MPEG2_DEC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_MPEG2_DEC;
		break;
	case S5P_MFC_CODEC_H263_DEC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_H263_DEC;
		break;
	case S5P_MFC_CODEC_VC1RCV_DEC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_VC1RCV_DEC;
		break;
	case S5P_MFC_CODEC_H264_ENC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_H264_ENC;
		break;
	case S5P_MFC_CODEC_MPEG4_ENC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_MPEG4_ENC;
		break;
	case S5P_MFC_CODEC_H263_ENC:
		h2r_args.arg[0] = S5P_FIMV_CODEC_H263_ENC;
		break;
	default:
		h2r_args.arg[0] = S5P_FIMV_CODEC_NONE;
	}
	h2r_args.arg[1] = 0; /* no crc & no pixelcache */
	h2r_args.arg[2] = ctx->ctx.ofs;
	h2r_args.arg[3] = ctx->ctx.size;
	ret = s5p_mfc_cmd_host2risc_v5(dev, S5P_FIMV_H2R_CMD_OPEN_INSTANCE,
								&h2r_args);
	if (ret) {
		mfc_err("Failed to create a new instance\n");
		ctx->state = MFCINST_ERROR;
	}
	return ret;
}

__attribute__((used)) static int s5p_mfc_close_inst_cmd_v5(struct s5p_mfc_ctx *ctx)
{
	struct s5p_mfc_dev *dev = ctx->dev;
	struct s5p_mfc_cmd_args h2r_args;
	int ret;

	if (ctx->state == MFCINST_FREE) {
		mfc_err("Instance already returned\n");
		ctx->state = MFCINST_ERROR;
		return -EINVAL;
	}
	/* Closing decoding instance  */
	mfc_debug(2, "Returning instance number %d\n", ctx->inst_no);
	dev->curr_ctx = ctx->num;
	memset(&h2r_args, 0, sizeof(struct s5p_mfc_cmd_args));
	h2r_args.arg[0] = ctx->inst_no;
	ret = s5p_mfc_cmd_host2risc_v5(dev, S5P_FIMV_H2R_CMD_CLOSE_INSTANCE,
								&h2r_args);
	if (ret) {
		mfc_err("Failed to return an instance\n");
		ctx->state = MFCINST_ERROR;
		return -EINVAL;
	}
	return 0;
}

struct s5p_mfc_hw_cmds *s5p_mfc_init_hw_cmds_v5(void)
{
	return &s5p_mfc_cmds_v5;
}


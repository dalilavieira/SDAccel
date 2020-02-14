#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  void* uint64_t ;
struct TYPE_18__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  top; int /*<<< orphan*/  left; } ;
struct mtk_mdp_frame {int /*<<< orphan*/ * payload; TYPE_6__* fmt; int /*<<< orphan*/  height; int /*<<< orphan*/  width; TYPE_9__ crop; } ;
struct TYPE_14__ {TYPE_4__* global_alpha; TYPE_3__* vflip; TYPE_2__* hflip; TYPE_1__* rotate; } ;
struct TYPE_17__ {TYPE_7__* vsi; } ;
struct mtk_mdp_ctx {TYPE_5__ ctrls; TYPE_8__ vpu; struct mtk_mdp_frame d_frame; struct mtk_mdp_frame s_frame; } ;
struct mtk_mdp_addr {scalar_t__* addr; } ;
struct mdp_config_misc {int /*<<< orphan*/  alpha; int /*<<< orphan*/  vflip; int /*<<< orphan*/  hflip; int /*<<< orphan*/  orientation; } ;
struct mdp_config {scalar_t__ h_stride; scalar_t__ w_stride; void* format; int /*<<< orphan*/  h; int /*<<< orphan*/  w; scalar_t__ y; scalar_t__ x; int /*<<< orphan*/  crop_h; int /*<<< orphan*/  crop_w; int /*<<< orphan*/  crop_y; int /*<<< orphan*/  crop_x; } ;
struct mdp_buffer {unsigned int plane_num; int /*<<< orphan*/ * plane_size; void** addr_mva; } ;
typedef  void* int32_t ;
struct TYPE_16__ {struct mdp_config_misc misc; struct mdp_buffer dst_buffer; struct mdp_config dst_config; struct mdp_buffer src_buffer; struct mdp_config src_config; } ;
struct TYPE_15__ {unsigned int num_comp; int pixelformat; } ;
struct TYPE_13__ {int /*<<< orphan*/  val; } ;
struct TYPE_12__ {int /*<<< orphan*/  val; } ;
struct TYPE_11__ {int /*<<< orphan*/  val; } ;
struct TYPE_10__ {int /*<<< orphan*/  val; } ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 void* MDP_COLOR_420_MT21 ; 
 void* MDP_COLOR_I420 ; 
 void* MDP_COLOR_NV12 ; 
 void* MDP_COLOR_UNKNOWN ; 
 void* MDP_COLOR_YV12 ; 
#define  V4L2_PIX_FMT_MT21C 133 
#define  V4L2_PIX_FMT_NV12 132 
#define  V4L2_PIX_FMT_NV12M 131 
#define  V4L2_PIX_FMT_YUV420 130 
#define  V4L2_PIX_FMT_YUV420M 129 
#define  V4L2_PIX_FMT_YVU420 128 
 int /*<<< orphan*/  mtk_mdp_err (char*,int) ; 

__attribute__((used)) static int32_t mtk_mdp_map_color_format(int v4l2_format)
{
	switch (v4l2_format) {
	case V4L2_PIX_FMT_NV12M:
	case V4L2_PIX_FMT_NV12:
		return MDP_COLOR_NV12;
	case V4L2_PIX_FMT_MT21C:
		return MDP_COLOR_420_MT21;
	case V4L2_PIX_FMT_YUV420M:
	case V4L2_PIX_FMT_YUV420:
		return MDP_COLOR_I420;
	case V4L2_PIX_FMT_YVU420:
		return MDP_COLOR_YV12;
	}

	mtk_mdp_err("Unknown format 0x%x", v4l2_format);

	return MDP_COLOR_UNKNOWN;
}

void mtk_mdp_hw_set_input_addr(struct mtk_mdp_ctx *ctx,
			       struct mtk_mdp_addr *addr)
{
	struct mdp_buffer *src_buf = &ctx->vpu.vsi->src_buffer;
	int i;

	for (i = 0; i < ARRAY_SIZE(addr->addr); i++)
		src_buf->addr_mva[i] = (uint64_t)addr->addr[i];
}

void mtk_mdp_hw_set_output_addr(struct mtk_mdp_ctx *ctx,
				struct mtk_mdp_addr *addr)
{
	struct mdp_buffer *dst_buf = &ctx->vpu.vsi->dst_buffer;
	int i;

	for (i = 0; i < ARRAY_SIZE(addr->addr); i++)
		dst_buf->addr_mva[i] = (uint64_t)addr->addr[i];
}

void mtk_mdp_hw_set_in_size(struct mtk_mdp_ctx *ctx)
{
	struct mtk_mdp_frame *frame = &ctx->s_frame;
	struct mdp_config *config = &ctx->vpu.vsi->src_config;

	/* Set input pixel offset */
	config->crop_x = frame->crop.left;
	config->crop_y = frame->crop.top;

	/* Set input cropped size */
	config->crop_w = frame->crop.width;
	config->crop_h = frame->crop.height;

	/* Set input original size */
	config->x = 0;
	config->y = 0;
	config->w = frame->width;
	config->h = frame->height;
}

void mtk_mdp_hw_set_in_image_format(struct mtk_mdp_ctx *ctx)
{
	unsigned int i;
	struct mtk_mdp_frame *frame = &ctx->s_frame;
	struct mdp_config *config = &ctx->vpu.vsi->src_config;
	struct mdp_buffer *src_buf = &ctx->vpu.vsi->src_buffer;

	src_buf->plane_num = frame->fmt->num_comp;
	config->format = mtk_mdp_map_color_format(frame->fmt->pixelformat);
	config->w_stride = 0; /* MDP will calculate it by color format. */
	config->h_stride = 0; /* MDP will calculate it by color format. */

	for (i = 0; i < src_buf->plane_num; i++)
		src_buf->plane_size[i] = frame->payload[i];
}

void mtk_mdp_hw_set_out_size(struct mtk_mdp_ctx *ctx)
{
	struct mtk_mdp_frame *frame = &ctx->d_frame;
	struct mdp_config *config = &ctx->vpu.vsi->dst_config;

	config->crop_x = frame->crop.left;
	config->crop_y = frame->crop.top;
	config->crop_w = frame->crop.width;
	config->crop_h = frame->crop.height;
	config->x = 0;
	config->y = 0;
	config->w = frame->width;
	config->h = frame->height;
}

void mtk_mdp_hw_set_out_image_format(struct mtk_mdp_ctx *ctx)
{
	unsigned int i;
	struct mtk_mdp_frame *frame = &ctx->d_frame;
	struct mdp_config *config = &ctx->vpu.vsi->dst_config;
	struct mdp_buffer *dst_buf = &ctx->vpu.vsi->dst_buffer;

	dst_buf->plane_num = frame->fmt->num_comp;
	config->format = mtk_mdp_map_color_format(frame->fmt->pixelformat);
	config->w_stride = 0; /* MDP will calculate it by color format. */
	config->h_stride = 0; /* MDP will calculate it by color format. */
	for (i = 0; i < dst_buf->plane_num; i++)
		dst_buf->plane_size[i] = frame->payload[i];
}

void mtk_mdp_hw_set_rotation(struct mtk_mdp_ctx *ctx)
{
	struct mdp_config_misc *misc = &ctx->vpu.vsi->misc;

	misc->orientation = ctx->ctrls.rotate->val;
	misc->hflip = ctx->ctrls.hflip->val;
	misc->vflip = ctx->ctrls.vflip->val;
}

void mtk_mdp_hw_set_global_alpha(struct mtk_mdp_ctx *ctx)
{
	struct mdp_config_misc *misc = &ctx->vpu.vsi->misc;

	misc->alpha = ctx->ctrls.global_alpha->val;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct TYPE_21__ {unsigned int down_scale_factor; unsigned int up_scale_factor; } ;
union rga_src_y_factor {size_t val; TYPE_6__ data; } ;
struct TYPE_20__ {unsigned int down_scale_factor; unsigned int up_scale_factor; } ;
union rga_src_x_factor {size_t val; TYPE_5__ data; } ;
struct TYPE_22__ {int vir_stride; int vir_width; } ;
union rga_src_vir_info {size_t val; TYPE_7__ data; } ;
struct TYPE_14__ {scalar_t__ format; size_t mir_mode; scalar_t__ rot_mode; int /*<<< orphan*/  vscl_mode; int /*<<< orphan*/  hscl_mode; void* csc_mode; int /*<<< orphan*/  swap; } ;
union rga_src_info {size_t val; TYPE_11__ data; } ;
struct TYPE_23__ {unsigned int act_height; unsigned int act_width; } ;
union rga_src_act_info {size_t val; TYPE_8__ data; } ;
struct TYPE_15__ {int gradient_sat; int /*<<< orphan*/  bitblt; int /*<<< orphan*/  render; } ;
union rga_mode_ctrl {size_t val; TYPE_12__ data; } ;
struct TYPE_24__ {int vir_stride; } ;
union rga_dst_vir_info {size_t val; TYPE_9__ data; } ;
struct TYPE_18__ {scalar_t__ format; void* csc_mode; int /*<<< orphan*/  swap; } ;
union rga_dst_info {size_t val; TYPE_3__ data; } ;
struct TYPE_13__ {unsigned int act_height; unsigned int act_width; } ;
union rga_dst_act_info {size_t val; TYPE_10__ data; } ;
union rga_alpha_ctrl1 {size_t val; } ;
union rga_alpha_ctrl0 {size_t val; } ;
typedef  size_t u32 ;
struct TYPE_19__ {scalar_t__ major; scalar_t__ minor; } ;
struct rockchip_rga {size_t regs; size_t* cmdbuf_virt; size_t cmdbuf_phy; struct rga_ctx* curr; int /*<<< orphan*/  dev; void* dst_mmu_pages; void* src_mmu_pages; TYPE_4__ version; } ;
struct TYPE_16__ {unsigned int height; unsigned int width; unsigned int left; unsigned int top; } ;
struct rga_frame {unsigned int stride; unsigned int width; unsigned int height; int colorspace; TYPE_2__* fmt; TYPE_1__ crop; } ;
struct rga_ctx {int rotate; struct rockchip_rga* rga; struct rga_frame out; struct rga_frame in; scalar_t__ hflip; scalar_t__ vflip; } ;
struct rga_addr_offset {unsigned int y_off; unsigned int u_off; unsigned int v_off; } ;
struct rga_corners_addr_offset {struct rga_addr_offset left_top; struct rga_addr_offset right_bottom; struct rga_addr_offset right_top; struct rga_addr_offset left_bottom; } ;
typedef  enum e_rga_start_pos { ____Placeholder_e_rga_start_pos } e_rga_start_pos ;
struct TYPE_17__ {unsigned int x_div; unsigned int y_div; unsigned int uv_factor; scalar_t__ hw_format; int /*<<< orphan*/  color_swap; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIDIRECTIONAL ; 
#define  LB 132 
#define  LT 131 
 int /*<<< orphan*/  PAGE_SIZE ; 
#define  RB 130 
 int RGA_ALPHA_CTRL0 ; 
 int RGA_ALPHA_CTRL1 ; 
 int RGA_CMDBUF_SIZE ; 
 size_t RGA_CMD_BASE ; 
 size_t RGA_CMD_CTRL ; 
 scalar_t__ RGA_COLOR_FMT_YUV422SP ; 
 int RGA_DST_ACT_INFO ; 
 int RGA_DST_CB_BASE_ADDR ; 
 int RGA_DST_CR_BASE_ADDR ; 
 void* RGA_DST_CSC_MODE_BT601_R0 ; 
 int RGA_DST_INFO ; 
 int RGA_DST_VIR_INFO ; 
 int RGA_DST_Y_RGB_BASE_ADDR ; 
 size_t RGA_INT ; 
 int RGA_MMU_CTRL1 ; 
 int RGA_MMU_DST_BASE ; 
 int RGA_MMU_SRC1_BASE ; 
 int RGA_MMU_SRC_BASE ; 
 int RGA_MODE_BASE_REG ; 
 int /*<<< orphan*/  RGA_MODE_BITBLT_MODE_SRC_TO_DST ; 
 int RGA_MODE_CTRL ; 
 int /*<<< orphan*/  RGA_MODE_RENDER_BITBLT ; 
 int RGA_SRC_ACT_INFO ; 
 int RGA_SRC_CB_BASE_ADDR ; 
 int RGA_SRC_CR_BASE_ADDR ; 
 void* RGA_SRC_CSC_MODE_BT601_R0 ; 
 void* RGA_SRC_CSC_MODE_BT709_R0 ; 
 int /*<<< orphan*/  RGA_SRC_HSCL_MODE_DOWN ; 
 int /*<<< orphan*/  RGA_SRC_HSCL_MODE_NO ; 
 int /*<<< orphan*/  RGA_SRC_HSCL_MODE_UP ; 
 int RGA_SRC_INFO ; 
 size_t RGA_SRC_MIRR_MODE_X ; 
 size_t RGA_SRC_MIRR_MODE_Y ; 
 scalar_t__ RGA_SRC_ROT_MODE_0_DEGREE ; 
 scalar_t__ RGA_SRC_ROT_MODE_180_DEGREE ; 
 scalar_t__ RGA_SRC_ROT_MODE_270_DEGREE ; 
 scalar_t__ RGA_SRC_ROT_MODE_90_DEGREE ; 
 int RGA_SRC_VIR_INFO ; 
 int /*<<< orphan*/  RGA_SRC_VSCL_MODE_DOWN ; 
 int /*<<< orphan*/  RGA_SRC_VSCL_MODE_NO ; 
 int /*<<< orphan*/  RGA_SRC_VSCL_MODE_UP ; 
 int RGA_SRC_X_FACTOR ; 
 int RGA_SRC_Y_FACTOR ; 
 int RGA_SRC_Y_RGB_BASE_ADDR ; 
 size_t RGA_SYS_CTRL ; 
#define  RT 129 
#define  V4L2_COLORSPACE_REC709 128 
 int abs (unsigned int) ; 
 int /*<<< orphan*/  dma_sync_single_for_device (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (size_t*,int /*<<< orphan*/ ,int) ; 
 size_t readl (size_t) ; 
 int virt_to_phys (void*) ; 
 int /*<<< orphan*/  writel (size_t,size_t) ; 

__attribute__((used)) static inline void rga_write(struct rockchip_rga *rga, u32 reg, u32 value)
{
	writel(value, rga->regs + reg);
}

__attribute__((used)) static inline u32 rga_read(struct rockchip_rga *rga, u32 reg)
{
	return readl(rga->regs + reg);
}

__attribute__((used)) static inline void rga_mod(struct rockchip_rga *rga, u32 reg, u32 val, u32 mask)
{
	u32 temp = rga_read(rga, reg) & ~(mask);

	temp |= val & mask;
	rga_write(rga, reg, temp);
}

__attribute__((used)) static unsigned int rga_get_scaling(unsigned int src, unsigned int dst)
{
	/*
	 * The rga hw scaling factor is a normalized inverse of the
	 * scaling factor.
	 * For example: When source width is 100 and destination width is 200
	 * (scaling of 2x), then the hw factor is NC * 100 / 200.
	 * The normalization factor (NC) is 2^16 = 0x10000.
	 */

	return (src > dst) ? ((dst << 16) / src) : ((src << 16) / dst);
}

__attribute__((used)) static struct rga_corners_addr_offset
rga_get_addr_offset(struct rga_frame *frm, unsigned int x, unsigned int y,
		    unsigned int w, unsigned int h)
{
	struct rga_corners_addr_offset offsets;
	struct rga_addr_offset *lt, *lb, *rt, *rb;
	unsigned int x_div = 0,
		     y_div = 0, uv_stride = 0, pixel_width = 0, uv_factor = 0;

	lt = &offsets.left_top;
	lb = &offsets.left_bottom;
	rt = &offsets.right_top;
	rb = &offsets.right_bottom;

	x_div = frm->fmt->x_div;
	y_div = frm->fmt->y_div;
	uv_factor = frm->fmt->uv_factor;
	uv_stride = frm->stride / x_div;
	pixel_width = frm->stride / frm->width;

	lt->y_off = y * frm->stride + x * pixel_width;
	lt->u_off =
		frm->width * frm->height + (y / y_div) * uv_stride + x / x_div;
	lt->v_off = lt->u_off + frm->width * frm->height / uv_factor;

	lb->y_off = lt->y_off + (h - 1) * frm->stride;
	lb->u_off = lt->u_off + (h / y_div - 1) * uv_stride;
	lb->v_off = lt->v_off + (h / y_div - 1) * uv_stride;

	rt->y_off = lt->y_off + (w - 1) * pixel_width;
	rt->u_off = lt->u_off + w / x_div - 1;
	rt->v_off = lt->v_off + w / x_div - 1;

	rb->y_off = lb->y_off + (w - 1) * pixel_width;
	rb->u_off = lb->u_off + w / x_div - 1;
	rb->v_off = lb->v_off + w / x_div - 1;

	return offsets;
}

__attribute__((used)) static struct rga_addr_offset *rga_lookup_draw_pos(struct
		rga_corners_addr_offset
		* offsets, u32 rotate_mode,
		u32 mirr_mode)
{
	static enum e_rga_start_pos rot_mir_point_matrix[4][4] = {
		{
			LT, RT, LB, RB,
		},
		{
			RT, LT, RB, LB,
		},
		{
			RB, LB, RT, LT,
		},
		{
			LB, RB, LT, RT,
		},
	};

	if (!offsets)
		return NULL;

	switch (rot_mir_point_matrix[rotate_mode][mirr_mode]) {
	case LT:
		return &offsets->left_top;
	case LB:
		return &offsets->left_bottom;
	case RT:
		return &offsets->right_top;
	case RB:
		return &offsets->right_bottom;
	}

	return NULL;
}

__attribute__((used)) static void rga_cmd_set_src_addr(struct rga_ctx *ctx, void *mmu_pages)
{
	struct rockchip_rga *rga = ctx->rga;
	u32 *dest = rga->cmdbuf_virt;
	unsigned int reg;

	reg = RGA_MMU_SRC_BASE - RGA_MODE_BASE_REG;
	dest[reg >> 2] = virt_to_phys(mmu_pages) >> 4;

	reg = RGA_MMU_CTRL1 - RGA_MODE_BASE_REG;
	dest[reg >> 2] |= 0x7;
}

__attribute__((used)) static void rga_cmd_set_src1_addr(struct rga_ctx *ctx, void *mmu_pages)
{
	struct rockchip_rga *rga = ctx->rga;
	u32 *dest = rga->cmdbuf_virt;
	unsigned int reg;

	reg = RGA_MMU_SRC1_BASE - RGA_MODE_BASE_REG;
	dest[reg >> 2] = virt_to_phys(mmu_pages) >> 4;

	reg = RGA_MMU_CTRL1 - RGA_MODE_BASE_REG;
	dest[reg >> 2] |= 0x7 << 4;
}

__attribute__((used)) static void rga_cmd_set_dst_addr(struct rga_ctx *ctx, void *mmu_pages)
{
	struct rockchip_rga *rga = ctx->rga;
	u32 *dest = rga->cmdbuf_virt;
	unsigned int reg;

	reg = RGA_MMU_DST_BASE - RGA_MODE_BASE_REG;
	dest[reg >> 2] = virt_to_phys(mmu_pages) >> 4;

	reg = RGA_MMU_CTRL1 - RGA_MODE_BASE_REG;
	dest[reg >> 2] |= 0x7 << 8;
}

__attribute__((used)) static void rga_cmd_set_trans_info(struct rga_ctx *ctx)
{
	struct rockchip_rga *rga = ctx->rga;
	u32 *dest = rga->cmdbuf_virt;
	unsigned int scale_dst_w, scale_dst_h;
	unsigned int src_h, src_w, src_x, src_y, dst_h, dst_w, dst_x, dst_y;
	union rga_src_info src_info;
	union rga_dst_info dst_info;
	union rga_src_x_factor x_factor;
	union rga_src_y_factor y_factor;
	union rga_src_vir_info src_vir_info;
	union rga_src_act_info src_act_info;
	union rga_dst_vir_info dst_vir_info;
	union rga_dst_act_info dst_act_info;

	struct rga_addr_offset *dst_offset;
	struct rga_corners_addr_offset offsets;
	struct rga_corners_addr_offset src_offsets;

	src_h = ctx->in.crop.height;
	src_w = ctx->in.crop.width;
	src_x = ctx->in.crop.left;
	src_y = ctx->in.crop.top;
	dst_h = ctx->out.crop.height;
	dst_w = ctx->out.crop.width;
	dst_x = ctx->out.crop.left;
	dst_y = ctx->out.crop.top;

	src_info.val = dest[(RGA_SRC_INFO - RGA_MODE_BASE_REG) >> 2];
	dst_info.val = dest[(RGA_DST_INFO - RGA_MODE_BASE_REG) >> 2];
	x_factor.val = dest[(RGA_SRC_X_FACTOR - RGA_MODE_BASE_REG) >> 2];
	y_factor.val = dest[(RGA_SRC_Y_FACTOR - RGA_MODE_BASE_REG) >> 2];
	src_vir_info.val = dest[(RGA_SRC_VIR_INFO - RGA_MODE_BASE_REG) >> 2];
	src_act_info.val = dest[(RGA_SRC_ACT_INFO - RGA_MODE_BASE_REG) >> 2];
	dst_vir_info.val = dest[(RGA_DST_VIR_INFO - RGA_MODE_BASE_REG) >> 2];
	dst_act_info.val = dest[(RGA_DST_ACT_INFO - RGA_MODE_BASE_REG) >> 2];

	src_info.data.format = ctx->in.fmt->hw_format;
	src_info.data.swap = ctx->in.fmt->color_swap;
	dst_info.data.format = ctx->out.fmt->hw_format;
	dst_info.data.swap = ctx->out.fmt->color_swap;

	if (ctx->in.fmt->hw_format >= RGA_COLOR_FMT_YUV422SP) {
		if (ctx->out.fmt->hw_format < RGA_COLOR_FMT_YUV422SP) {
			switch (ctx->in.colorspace) {
			case V4L2_COLORSPACE_REC709:
				src_info.data.csc_mode =
					RGA_SRC_CSC_MODE_BT709_R0;
				break;
			default:
				src_info.data.csc_mode =
					RGA_SRC_CSC_MODE_BT601_R0;
				break;
			}
		}
	}

	if (ctx->out.fmt->hw_format >= RGA_COLOR_FMT_YUV422SP) {
		switch (ctx->out.colorspace) {
		case V4L2_COLORSPACE_REC709:
			dst_info.data.csc_mode = RGA_SRC_CSC_MODE_BT709_R0;
			break;
		default:
			dst_info.data.csc_mode = RGA_DST_CSC_MODE_BT601_R0;
			break;
		}
	}

	if (ctx->vflip)
		src_info.data.mir_mode |= RGA_SRC_MIRR_MODE_X;

	if (ctx->hflip)
		src_info.data.mir_mode |= RGA_SRC_MIRR_MODE_Y;

	switch (ctx->rotate) {
	case 90:
		src_info.data.rot_mode = RGA_SRC_ROT_MODE_90_DEGREE;
		break;
	case 180:
		src_info.data.rot_mode = RGA_SRC_ROT_MODE_180_DEGREE;
		break;
	case 270:
		src_info.data.rot_mode = RGA_SRC_ROT_MODE_270_DEGREE;
		break;
	default:
		src_info.data.rot_mode = RGA_SRC_ROT_MODE_0_DEGREE;
		break;
	}

	/*
	 * Cacluate the up/down scaling mode/factor.
	 *
	 * RGA used to scale the picture first, and then rotate second,
	 * so we need to swap the w/h when rotate degree is 90/270.
	 */
	if (src_info.data.rot_mode == RGA_SRC_ROT_MODE_90_DEGREE ||
	    src_info.data.rot_mode == RGA_SRC_ROT_MODE_270_DEGREE) {
		if (rga->version.major == 0 || rga->version.minor == 0) {
			if (dst_w == src_h)
				src_h -= 8;
			if (abs(src_w - dst_h) < 16)
				src_w -= 16;
		}

		scale_dst_h = dst_w;
		scale_dst_w = dst_h;
	} else {
		scale_dst_w = dst_w;
		scale_dst_h = dst_h;
	}

	if (src_w == scale_dst_w) {
		src_info.data.hscl_mode = RGA_SRC_HSCL_MODE_NO;
		x_factor.val = 0;
	} else if (src_w > scale_dst_w) {
		src_info.data.hscl_mode = RGA_SRC_HSCL_MODE_DOWN;
		x_factor.data.down_scale_factor =
			rga_get_scaling(src_w, scale_dst_w) + 1;
	} else {
		src_info.data.hscl_mode = RGA_SRC_HSCL_MODE_UP;
		x_factor.data.up_scale_factor =
			rga_get_scaling(src_w - 1, scale_dst_w - 1);
	}

	if (src_h == scale_dst_h) {
		src_info.data.vscl_mode = RGA_SRC_VSCL_MODE_NO;
		y_factor.val = 0;
	} else if (src_h > scale_dst_h) {
		src_info.data.vscl_mode = RGA_SRC_VSCL_MODE_DOWN;
		y_factor.data.down_scale_factor =
			rga_get_scaling(src_h, scale_dst_h) + 1;
	} else {
		src_info.data.vscl_mode = RGA_SRC_VSCL_MODE_UP;
		y_factor.data.up_scale_factor =
			rga_get_scaling(src_h - 1, scale_dst_h - 1);
	}

	/*
	 * Cacluate the framebuffer virtual strides and active size,
	 * note that the step of vir_stride / vir_width is 4 byte words
	 */
	src_vir_info.data.vir_stride = ctx->in.stride >> 2;
	src_vir_info.data.vir_width = ctx->in.stride >> 2;

	src_act_info.data.act_height = src_h - 1;
	src_act_info.data.act_width = src_w - 1;

	dst_vir_info.data.vir_stride = ctx->out.stride >> 2;
	dst_act_info.data.act_height = dst_h - 1;
	dst_act_info.data.act_width = dst_w - 1;

	/*
	 * Cacluate the source framebuffer base address with offset pixel.
	 */
	src_offsets = rga_get_addr_offset(&ctx->in, src_x, src_y,
					  src_w, src_h);

	/*
	 * Configure the dest framebuffer base address with pixel offset.
	 */
	offsets = rga_get_addr_offset(&ctx->out, dst_x, dst_y, dst_w, dst_h);
	dst_offset = rga_lookup_draw_pos(&offsets, src_info.data.rot_mode,
					 src_info.data.mir_mode);

	dest[(RGA_SRC_Y_RGB_BASE_ADDR - RGA_MODE_BASE_REG) >> 2] =
		src_offsets.left_top.y_off;
	dest[(RGA_SRC_CB_BASE_ADDR - RGA_MODE_BASE_REG) >> 2] =
		src_offsets.left_top.u_off;
	dest[(RGA_SRC_CR_BASE_ADDR - RGA_MODE_BASE_REG) >> 2] =
		src_offsets.left_top.v_off;

	dest[(RGA_SRC_X_FACTOR - RGA_MODE_BASE_REG) >> 2] = x_factor.val;
	dest[(RGA_SRC_Y_FACTOR - RGA_MODE_BASE_REG) >> 2] = y_factor.val;
	dest[(RGA_SRC_VIR_INFO - RGA_MODE_BASE_REG) >> 2] = src_vir_info.val;
	dest[(RGA_SRC_ACT_INFO - RGA_MODE_BASE_REG) >> 2] = src_act_info.val;

	dest[(RGA_SRC_INFO - RGA_MODE_BASE_REG) >> 2] = src_info.val;

	dest[(RGA_DST_Y_RGB_BASE_ADDR - RGA_MODE_BASE_REG) >> 2] =
		dst_offset->y_off;
	dest[(RGA_DST_CB_BASE_ADDR - RGA_MODE_BASE_REG) >> 2] =
		dst_offset->u_off;
	dest[(RGA_DST_CR_BASE_ADDR - RGA_MODE_BASE_REG) >> 2] =
		dst_offset->v_off;

	dest[(RGA_DST_VIR_INFO - RGA_MODE_BASE_REG) >> 2] = dst_vir_info.val;
	dest[(RGA_DST_ACT_INFO - RGA_MODE_BASE_REG) >> 2] = dst_act_info.val;

	dest[(RGA_DST_INFO - RGA_MODE_BASE_REG) >> 2] = dst_info.val;
}

__attribute__((used)) static void rga_cmd_set_mode(struct rga_ctx *ctx)
{
	struct rockchip_rga *rga = ctx->rga;
	u32 *dest = rga->cmdbuf_virt;
	union rga_mode_ctrl mode;
	union rga_alpha_ctrl0 alpha_ctrl0;
	union rga_alpha_ctrl1 alpha_ctrl1;

	mode.val = 0;
	alpha_ctrl0.val = 0;
	alpha_ctrl1.val = 0;

	mode.data.gradient_sat = 1;
	mode.data.render = RGA_MODE_RENDER_BITBLT;
	mode.data.bitblt = RGA_MODE_BITBLT_MODE_SRC_TO_DST;

	/* disable alpha blending */
	dest[(RGA_ALPHA_CTRL0 - RGA_MODE_BASE_REG) >> 2] = alpha_ctrl0.val;
	dest[(RGA_ALPHA_CTRL1 - RGA_MODE_BASE_REG) >> 2] = alpha_ctrl1.val;

	dest[(RGA_MODE_CTRL - RGA_MODE_BASE_REG) >> 2] = mode.val;
}

__attribute__((used)) static void rga_cmd_set(struct rga_ctx *ctx)
{
	struct rockchip_rga *rga = ctx->rga;

	memset(rga->cmdbuf_virt, 0, RGA_CMDBUF_SIZE * 4);

	rga_cmd_set_src_addr(ctx, rga->src_mmu_pages);
	/*
	 * Due to hardware bug,
	 * src1 mmu also should be configured when using alpha blending.
	 */
	rga_cmd_set_src1_addr(ctx, rga->dst_mmu_pages);

	rga_cmd_set_dst_addr(ctx, rga->dst_mmu_pages);
	rga_cmd_set_mode(ctx);

	rga_cmd_set_trans_info(ctx);

	rga_write(rga, RGA_CMD_BASE, rga->cmdbuf_phy);

	/* sync CMD buf for RGA */
	dma_sync_single_for_device(rga->dev, rga->cmdbuf_phy,
		PAGE_SIZE, DMA_BIDIRECTIONAL);
}

void rga_hw_start(struct rockchip_rga *rga)
{
	struct rga_ctx *ctx = rga->curr;

	rga_cmd_set(ctx);

	rga_write(rga, RGA_SYS_CTRL, 0x00);

	rga_write(rga, RGA_SYS_CTRL, 0x22);

	rga_write(rga, RGA_INT, 0x600);

	rga_write(rga, RGA_CMD_CTRL, 0x1);
}


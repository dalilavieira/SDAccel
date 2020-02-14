#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct gsc_scaler {int /*<<< orphan*/  main_vratio; int /*<<< orphan*/  main_hratio; int /*<<< orphan*/  pre_vratio; int /*<<< orphan*/  pre_hratio; int /*<<< orphan*/  pre_shfactor; } ;
struct TYPE_7__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  top; int /*<<< orphan*/  left; } ;
struct gsc_frame {scalar_t__ colorspace; struct gsc_fmt* fmt; TYPE_1__ crop; int /*<<< orphan*/  f_height; int /*<<< orphan*/  f_width; } ;
struct gsc_fmt {scalar_t__ pixelformat; int num_planes; int num_comp; int /*<<< orphan*/  color; int /*<<< orphan*/  corder; int /*<<< orphan*/  yorder; scalar_t__* depth; } ;
struct gsc_dev {scalar_t__ regs; int /*<<< orphan*/  slock; } ;
struct TYPE_12__ {TYPE_5__* global_alpha; TYPE_4__* vflip; TYPE_3__* hflip; TYPE_2__* rotate; } ;
struct gsc_ctx {int state; scalar_t__ in_path; scalar_t__ out_path; struct gsc_dev* gsc_dev; TYPE_6__ gsc_ctrls; struct gsc_frame d_frame; struct gsc_scaler scaler; struct gsc_frame s_frame; } ;
struct gsc_addr {int y; int cb; int cr; } ;
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;
struct TYPE_11__ {int /*<<< orphan*/  val; } ;
struct TYPE_10__ {int /*<<< orphan*/  val; } ;
struct TYPE_9__ {int /*<<< orphan*/  val; } ;
struct TYPE_8__ {int val; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  EINVAL ; 
 struct gsc_frame* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GSC_CBCR ; 
 int GSC_CROPPED_HEIGHT (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_CROPPED_SIZE ; 
 int GSC_CROPPED_WIDTH (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_DMA ; 
 int GSC_DSTIMG_HEIGHT (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_DSTIMG_OFFSET ; 
 int GSC_DSTIMG_OFFSET_X (int /*<<< orphan*/ ) ; 
 int GSC_DSTIMG_OFFSET_Y (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_DSTIMG_SIZE ; 
 int GSC_DSTIMG_WIDTH (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_ENABLE ; 
 int GSC_ENABLE_ON ; 
 int GSC_ENABLE_SFR_UPDATE ; 
 scalar_t__ GSC_IN_BASE_ADDR_CB (int) ; 
 scalar_t__ GSC_IN_BASE_ADDR_CB_MASK ; 
 scalar_t__ GSC_IN_BASE_ADDR_CR (int) ; 
 scalar_t__ GSC_IN_BASE_ADDR_CR_MASK ; 
 scalar_t__ GSC_IN_BASE_ADDR_Y (int) ; 
 scalar_t__ GSC_IN_BASE_ADDR_Y_MASK ; 
 int GSC_IN_CHROMA_ORDER_CBCR ; 
 int GSC_IN_CHROMA_ORDER_CRCB ; 
 int GSC_IN_CHROMA_ORDER_MASK ; 
 scalar_t__ GSC_IN_CON ; 
 int GSC_IN_FORMAT_MASK ; 
 int GSC_IN_LOCAL_SEL_MASK ; 
 int GSC_IN_PATH_MASK ; 
 int GSC_IN_PATH_MEMORY ; 
 int GSC_IN_RGB565 ; 
 int GSC_IN_RGB_HD_WIDE ; 
 int GSC_IN_RGB_SD_WIDE ; 
 int GSC_IN_RGB_TYPE_MASK ; 
 int GSC_IN_ROT_180 ; 
 int GSC_IN_ROT_270 ; 
 int GSC_IN_ROT_90 ; 
 int GSC_IN_ROT_90_XFLIP ; 
 int GSC_IN_ROT_90_YFLIP ; 
 int GSC_IN_ROT_MASK ; 
 int GSC_IN_ROT_XFLIP ; 
 int GSC_IN_ROT_YFLIP ; 
 int GSC_IN_TILE_C_16x8 ; 
 int GSC_IN_TILE_MODE ; 
 int GSC_IN_TILE_TYPE_MASK ; 
 int GSC_IN_XRGB8888 ; 
 int GSC_IN_YUV420_2P ; 
 int GSC_IN_YUV420_3P ; 
 int GSC_IN_YUV422_1P ; 
 int GSC_IN_YUV422_1P_OEDER_LSB_C ; 
 int GSC_IN_YUV422_1P_ORDER_LSB_Y ; 
 int GSC_IN_YUV422_1P_ORDER_MASK ; 
 int GSC_IN_YUV422_2P ; 
 int GSC_IN_YUV422_3P ; 
 scalar_t__ GSC_IRQ ; 
 int GSC_IRQ_DONE ; 
 int GSC_IRQ_ENABLE ; 
 int GSC_IRQ_FRMDONE_MASK ; 
 int GSC_IRQ_OVERRUN ; 
 int GSC_IRQ_STATUS_FRM_DONE_IRQ ; 
 int GSC_IRQ_STATUS_OR_IRQ ; 
 int /*<<< orphan*/  GSC_LSB_Y ; 
 scalar_t__ GSC_MAIN_H_RATIO ; 
 int GSC_MAIN_H_RATIO_VALUE (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_MAIN_V_RATIO ; 
 int GSC_MAIN_V_RATIO_VALUE (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_OUT_BASE_ADDR_CB (int) ; 
 scalar_t__ GSC_OUT_BASE_ADDR_CB_MASK ; 
 scalar_t__ GSC_OUT_BASE_ADDR_CR (int) ; 
 scalar_t__ GSC_OUT_BASE_ADDR_CR_MASK ; 
 scalar_t__ GSC_OUT_BASE_ADDR_Y (int) ; 
 scalar_t__ GSC_OUT_BASE_ADDR_Y_MASK ; 
 int GSC_OUT_CHROMA_ORDER_CBCR ; 
 int GSC_OUT_CHROMA_ORDER_CRCB ; 
 int GSC_OUT_CHROMA_ORDER_MASK ; 
 scalar_t__ GSC_OUT_CON ; 
 int GSC_OUT_FORMAT_MASK ; 
 int GSC_OUT_GLOBAL_ALPHA (int /*<<< orphan*/ ) ; 
 int GSC_OUT_GLOBAL_ALPHA_MASK ; 
 int GSC_OUT_PATH_LOCAL ; 
 int GSC_OUT_PATH_MASK ; 
 int GSC_OUT_PATH_MEMORY ; 
 int GSC_OUT_RGB565 ; 
 int GSC_OUT_RGB_HD_WIDE ; 
 int GSC_OUT_RGB_SD_WIDE ; 
 int GSC_OUT_RGB_TYPE_MASK ; 
 int GSC_OUT_TILE_C_16x8 ; 
 int GSC_OUT_TILE_MODE ; 
 int GSC_OUT_TILE_TYPE_MASK ; 
 int GSC_OUT_XRGB8888 ; 
 int GSC_OUT_YUV420_2P ; 
 int GSC_OUT_YUV420_3P ; 
 int GSC_OUT_YUV422_1P ; 
 int GSC_OUT_YUV422_1P_OEDER_LSB_C ; 
 int GSC_OUT_YUV422_1P_ORDER_LSB_Y ; 
 int GSC_OUT_YUV422_1P_ORDER_MASK ; 
 int GSC_OUT_YUV422_2P ; 
 int GSC_OUT_YUV444 ; 
 int GSC_PRESC_H_RATIO (int /*<<< orphan*/ ) ; 
 int GSC_PRESC_SHFACTOR (int /*<<< orphan*/ ) ; 
 int GSC_PRESC_V_RATIO (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_PRE_SCALE_RATIO ; 
 int GSC_SCALED_HEIGHT (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_SCALED_SIZE ; 
 int GSC_SCALED_WIDTH (int /*<<< orphan*/ ) ; 
 int GSC_SRCIMG_HEIGHT (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_SRCIMG_OFFSET ; 
 int GSC_SRCIMG_OFFSET_X (int /*<<< orphan*/ ) ; 
 int GSC_SRCIMG_OFFSET_Y (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_SRCIMG_SIZE ; 
 int GSC_SRCIMG_WIDTH (int /*<<< orphan*/ ) ; 
 scalar_t__ GSC_SW_RESET ; 
 int GSC_SW_RESET_SRESET ; 
 int V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE ; 
 int V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE ; 
 scalar_t__ V4L2_COLORSPACE_REC709 ; 
 scalar_t__ V4L2_PIX_FMT_NV12MT_16X16 ; 
 scalar_t__ V4L2_PIX_FMT_RGB32 ; 
 scalar_t__ V4L2_PIX_FMT_RGB565X ; 
 scalar_t__ is_rgb (int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline void gsc_ctx_state_lock_set(u32 state, struct gsc_ctx *ctx)
{
	unsigned long flags;

	spin_lock_irqsave(&ctx->gsc_dev->slock, flags);
	ctx->state |= state;
	spin_unlock_irqrestore(&ctx->gsc_dev->slock, flags);
}

__attribute__((used)) static inline void gsc_ctx_state_lock_clear(u32 state, struct gsc_ctx *ctx)
{
	unsigned long flags;

	spin_lock_irqsave(&ctx->gsc_dev->slock, flags);
	ctx->state &= ~state;
	spin_unlock_irqrestore(&ctx->gsc_dev->slock, flags);
}

__attribute__((used)) static inline int is_tiled(const struct gsc_fmt *fmt)
{
	return fmt->pixelformat == V4L2_PIX_FMT_NV12MT_16X16;
}

__attribute__((used)) static inline void gsc_hw_enable_control(struct gsc_dev *dev, bool on)
{
	u32 cfg = readl(dev->regs + GSC_ENABLE);

	if (on)
		cfg |= GSC_ENABLE_ON;
	else
		cfg &= ~GSC_ENABLE_ON;

	writel(cfg, dev->regs + GSC_ENABLE);
}

__attribute__((used)) static inline int gsc_hw_get_irq_status(struct gsc_dev *dev)
{
	u32 cfg = readl(dev->regs + GSC_IRQ);
	if (cfg & GSC_IRQ_STATUS_OR_IRQ)
		return GSC_IRQ_OVERRUN;
	else
		return GSC_IRQ_DONE;

}

__attribute__((used)) static inline void gsc_hw_clear_irq(struct gsc_dev *dev, int irq)
{
	u32 cfg = readl(dev->regs + GSC_IRQ);
	if (irq == GSC_IRQ_OVERRUN)
		cfg |= GSC_IRQ_STATUS_OR_IRQ;
	else if (irq == GSC_IRQ_DONE)
		cfg |= GSC_IRQ_STATUS_FRM_DONE_IRQ;
	writel(cfg, dev->regs + GSC_IRQ);
}

__attribute__((used)) static inline bool gsc_ctx_state_is_set(u32 mask, struct gsc_ctx *ctx)
{
	unsigned long flags;
	bool ret;

	spin_lock_irqsave(&ctx->gsc_dev->slock, flags);
	ret = (ctx->state & mask) == mask;
	spin_unlock_irqrestore(&ctx->gsc_dev->slock, flags);
	return ret;
}

__attribute__((used)) static inline struct gsc_frame *ctx_get_frame(struct gsc_ctx *ctx,
					      enum v4l2_buf_type type)
{
	struct gsc_frame *frame;

	if (V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE == type) {
		frame = &ctx->s_frame;
	} else if (V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE == type) {
		frame = &ctx->d_frame;
	} else {
		pr_err("Wrong buffer/video queue type (%d)", type);
		return ERR_PTR(-EINVAL);
	}

	return frame;
}

void gsc_hw_set_sw_reset(struct gsc_dev *dev)
{
	writel(GSC_SW_RESET_SRESET, dev->regs + GSC_SW_RESET);
}

int gsc_wait_reset(struct gsc_dev *dev)
{
	unsigned long end = jiffies + msecs_to_jiffies(50);
	u32 cfg;

	while (time_before(jiffies, end)) {
		cfg = readl(dev->regs + GSC_SW_RESET);
		if (!cfg)
			return 0;
		usleep_range(10, 20);
	}

	return -EBUSY;
}

void gsc_hw_set_frm_done_irq_mask(struct gsc_dev *dev, bool mask)
{
	u32 cfg;

	cfg = readl(dev->regs + GSC_IRQ);
	if (mask)
		cfg |= GSC_IRQ_FRMDONE_MASK;
	else
		cfg &= ~GSC_IRQ_FRMDONE_MASK;
	writel(cfg, dev->regs + GSC_IRQ);
}

void gsc_hw_set_gsc_irq_enable(struct gsc_dev *dev, bool mask)
{
	u32 cfg;

	cfg = readl(dev->regs + GSC_IRQ);
	if (mask)
		cfg |= GSC_IRQ_ENABLE;
	else
		cfg &= ~GSC_IRQ_ENABLE;
	writel(cfg, dev->regs + GSC_IRQ);
}

void gsc_hw_set_input_buf_masking(struct gsc_dev *dev, u32 shift,
				bool enable)
{
	u32 cfg = readl(dev->regs + GSC_IN_BASE_ADDR_Y_MASK);
	u32 mask = 1 << shift;

	cfg &= ~mask;
	cfg |= enable << shift;

	writel(cfg, dev->regs + GSC_IN_BASE_ADDR_Y_MASK);
	writel(cfg, dev->regs + GSC_IN_BASE_ADDR_CB_MASK);
	writel(cfg, dev->regs + GSC_IN_BASE_ADDR_CR_MASK);
}

void gsc_hw_set_output_buf_masking(struct gsc_dev *dev, u32 shift,
				bool enable)
{
	u32 cfg = readl(dev->regs + GSC_OUT_BASE_ADDR_Y_MASK);
	u32 mask = 1 << shift;

	cfg &= ~mask;
	cfg |= enable << shift;

	writel(cfg, dev->regs + GSC_OUT_BASE_ADDR_Y_MASK);
	writel(cfg, dev->regs + GSC_OUT_BASE_ADDR_CB_MASK);
	writel(cfg, dev->regs + GSC_OUT_BASE_ADDR_CR_MASK);
}

void gsc_hw_set_input_addr(struct gsc_dev *dev, struct gsc_addr *addr,
				int index)
{
	pr_debug("src_buf[%d]: %pad, cb: %pad, cr: %pad", index,
			&addr->y, &addr->cb, &addr->cr);
	writel(addr->y, dev->regs + GSC_IN_BASE_ADDR_Y(index));
	writel(addr->cb, dev->regs + GSC_IN_BASE_ADDR_CB(index));
	writel(addr->cr, dev->regs + GSC_IN_BASE_ADDR_CR(index));

}

void gsc_hw_set_output_addr(struct gsc_dev *dev,
			     struct gsc_addr *addr, int index)
{
	pr_debug("dst_buf[%d]: %pad, cb: %pad, cr: %pad",
			index, &addr->y, &addr->cb, &addr->cr);
	writel(addr->y, dev->regs + GSC_OUT_BASE_ADDR_Y(index));
	writel(addr->cb, dev->regs + GSC_OUT_BASE_ADDR_CB(index));
	writel(addr->cr, dev->regs + GSC_OUT_BASE_ADDR_CR(index));
}

void gsc_hw_set_input_path(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;

	u32 cfg = readl(dev->regs + GSC_IN_CON);
	cfg &= ~(GSC_IN_PATH_MASK | GSC_IN_LOCAL_SEL_MASK);

	if (ctx->in_path == GSC_DMA)
		cfg |= GSC_IN_PATH_MEMORY;

	writel(cfg, dev->regs + GSC_IN_CON);
}

void gsc_hw_set_in_size(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->s_frame;
	u32 cfg;

	/* Set input pixel offset */
	cfg = GSC_SRCIMG_OFFSET_X(frame->crop.left);
	cfg |= GSC_SRCIMG_OFFSET_Y(frame->crop.top);
	writel(cfg, dev->regs + GSC_SRCIMG_OFFSET);

	/* Set input original size */
	cfg = GSC_SRCIMG_WIDTH(frame->f_width);
	cfg |= GSC_SRCIMG_HEIGHT(frame->f_height);
	writel(cfg, dev->regs + GSC_SRCIMG_SIZE);

	/* Set input cropped size */
	cfg = GSC_CROPPED_WIDTH(frame->crop.width);
	cfg |= GSC_CROPPED_HEIGHT(frame->crop.height);
	writel(cfg, dev->regs + GSC_CROPPED_SIZE);
}

void gsc_hw_set_in_image_rgb(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->s_frame;
	u32 cfg;

	cfg = readl(dev->regs + GSC_IN_CON);
	if (frame->colorspace == V4L2_COLORSPACE_REC709)
		cfg |= GSC_IN_RGB_HD_WIDE;
	else
		cfg |= GSC_IN_RGB_SD_WIDE;

	if (frame->fmt->pixelformat == V4L2_PIX_FMT_RGB565X)
		cfg |= GSC_IN_RGB565;
	else if (frame->fmt->pixelformat == V4L2_PIX_FMT_RGB32)
		cfg |= GSC_IN_XRGB8888;

	writel(cfg, dev->regs + GSC_IN_CON);
}

void gsc_hw_set_in_image_format(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->s_frame;
	u32 i, depth = 0;
	u32 cfg;

	cfg = readl(dev->regs + GSC_IN_CON);
	cfg &= ~(GSC_IN_RGB_TYPE_MASK | GSC_IN_YUV422_1P_ORDER_MASK |
		 GSC_IN_CHROMA_ORDER_MASK | GSC_IN_FORMAT_MASK |
		 GSC_IN_TILE_TYPE_MASK | GSC_IN_TILE_MODE);
	writel(cfg, dev->regs + GSC_IN_CON);

	if (is_rgb(frame->fmt->color)) {
		gsc_hw_set_in_image_rgb(ctx);
		return;
	}
	for (i = 0; i < frame->fmt->num_planes; i++)
		depth += frame->fmt->depth[i];

	switch (frame->fmt->num_comp) {
	case 1:
		cfg |= GSC_IN_YUV422_1P;
		if (frame->fmt->yorder == GSC_LSB_Y)
			cfg |= GSC_IN_YUV422_1P_ORDER_LSB_Y;
		else
			cfg |= GSC_IN_YUV422_1P_OEDER_LSB_C;
		if (frame->fmt->corder == GSC_CBCR)
			cfg |= GSC_IN_CHROMA_ORDER_CBCR;
		else
			cfg |= GSC_IN_CHROMA_ORDER_CRCB;
		break;
	case 2:
		if (depth == 12)
			cfg |= GSC_IN_YUV420_2P;
		else
			cfg |= GSC_IN_YUV422_2P;
		if (frame->fmt->corder == GSC_CBCR)
			cfg |= GSC_IN_CHROMA_ORDER_CBCR;
		else
			cfg |= GSC_IN_CHROMA_ORDER_CRCB;
		break;
	case 3:
		if (depth == 12)
			cfg |= GSC_IN_YUV420_3P;
		else
			cfg |= GSC_IN_YUV422_3P;
		break;
	}

	if (is_tiled(frame->fmt))
		cfg |= GSC_IN_TILE_C_16x8 | GSC_IN_TILE_MODE;

	writel(cfg, dev->regs + GSC_IN_CON);
}

void gsc_hw_set_output_path(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;

	u32 cfg = readl(dev->regs + GSC_OUT_CON);
	cfg &= ~GSC_OUT_PATH_MASK;

	if (ctx->out_path == GSC_DMA)
		cfg |= GSC_OUT_PATH_MEMORY;
	else
		cfg |= GSC_OUT_PATH_LOCAL;

	writel(cfg, dev->regs + GSC_OUT_CON);
}

void gsc_hw_set_out_size(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->d_frame;
	u32 cfg;

	/* Set output original size */
	if (ctx->out_path == GSC_DMA) {
		cfg = GSC_DSTIMG_OFFSET_X(frame->crop.left);
		cfg |= GSC_DSTIMG_OFFSET_Y(frame->crop.top);
		writel(cfg, dev->regs + GSC_DSTIMG_OFFSET);

		cfg = GSC_DSTIMG_WIDTH(frame->f_width);
		cfg |= GSC_DSTIMG_HEIGHT(frame->f_height);
		writel(cfg, dev->regs + GSC_DSTIMG_SIZE);
	}

	/* Set output scaled size */
	if (ctx->gsc_ctrls.rotate->val == 90 ||
	    ctx->gsc_ctrls.rotate->val == 270) {
		cfg = GSC_SCALED_WIDTH(frame->crop.height);
		cfg |= GSC_SCALED_HEIGHT(frame->crop.width);
	} else {
		cfg = GSC_SCALED_WIDTH(frame->crop.width);
		cfg |= GSC_SCALED_HEIGHT(frame->crop.height);
	}
	writel(cfg, dev->regs + GSC_SCALED_SIZE);
}

void gsc_hw_set_out_image_rgb(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->d_frame;
	u32 cfg;

	cfg = readl(dev->regs + GSC_OUT_CON);
	if (frame->colorspace == V4L2_COLORSPACE_REC709)
		cfg |= GSC_OUT_RGB_HD_WIDE;
	else
		cfg |= GSC_OUT_RGB_SD_WIDE;

	if (frame->fmt->pixelformat == V4L2_PIX_FMT_RGB565X)
		cfg |= GSC_OUT_RGB565;
	else if (frame->fmt->pixelformat == V4L2_PIX_FMT_RGB32)
		cfg |= GSC_OUT_XRGB8888;

	writel(cfg, dev->regs + GSC_OUT_CON);
}

void gsc_hw_set_out_image_format(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->d_frame;
	u32 i, depth = 0;
	u32 cfg;

	cfg = readl(dev->regs + GSC_OUT_CON);
	cfg &= ~(GSC_OUT_RGB_TYPE_MASK | GSC_OUT_YUV422_1P_ORDER_MASK |
		 GSC_OUT_CHROMA_ORDER_MASK | GSC_OUT_FORMAT_MASK |
		 GSC_OUT_TILE_TYPE_MASK | GSC_OUT_TILE_MODE);
	writel(cfg, dev->regs + GSC_OUT_CON);

	if (is_rgb(frame->fmt->color)) {
		gsc_hw_set_out_image_rgb(ctx);
		return;
	}

	if (ctx->out_path != GSC_DMA) {
		cfg |= GSC_OUT_YUV444;
		goto end_set;
	}

	for (i = 0; i < frame->fmt->num_planes; i++)
		depth += frame->fmt->depth[i];

	switch (frame->fmt->num_comp) {
	case 1:
		cfg |= GSC_OUT_YUV422_1P;
		if (frame->fmt->yorder == GSC_LSB_Y)
			cfg |= GSC_OUT_YUV422_1P_ORDER_LSB_Y;
		else
			cfg |= GSC_OUT_YUV422_1P_OEDER_LSB_C;
		if (frame->fmt->corder == GSC_CBCR)
			cfg |= GSC_OUT_CHROMA_ORDER_CBCR;
		else
			cfg |= GSC_OUT_CHROMA_ORDER_CRCB;
		break;
	case 2:
		if (depth == 12)
			cfg |= GSC_OUT_YUV420_2P;
		else
			cfg |= GSC_OUT_YUV422_2P;
		if (frame->fmt->corder == GSC_CBCR)
			cfg |= GSC_OUT_CHROMA_ORDER_CBCR;
		else
			cfg |= GSC_OUT_CHROMA_ORDER_CRCB;
		break;
	case 3:
		cfg |= GSC_OUT_YUV420_3P;
		break;
	}

	if (is_tiled(frame->fmt))
		cfg |= GSC_OUT_TILE_C_16x8 | GSC_OUT_TILE_MODE;

end_set:
	writel(cfg, dev->regs + GSC_OUT_CON);
}

void gsc_hw_set_prescaler(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_scaler *sc = &ctx->scaler;
	u32 cfg;

	cfg = GSC_PRESC_SHFACTOR(sc->pre_shfactor);
	cfg |= GSC_PRESC_H_RATIO(sc->pre_hratio);
	cfg |= GSC_PRESC_V_RATIO(sc->pre_vratio);
	writel(cfg, dev->regs + GSC_PRE_SCALE_RATIO);
}

void gsc_hw_set_mainscaler(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_scaler *sc = &ctx->scaler;
	u32 cfg;

	cfg = GSC_MAIN_H_RATIO_VALUE(sc->main_hratio);
	writel(cfg, dev->regs + GSC_MAIN_H_RATIO);

	cfg = GSC_MAIN_V_RATIO_VALUE(sc->main_vratio);
	writel(cfg, dev->regs + GSC_MAIN_V_RATIO);
}

void gsc_hw_set_rotation(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	u32 cfg;

	cfg = readl(dev->regs + GSC_IN_CON);
	cfg &= ~GSC_IN_ROT_MASK;

	switch (ctx->gsc_ctrls.rotate->val) {
	case 270:
		cfg |= GSC_IN_ROT_270;
		break;
	case 180:
		cfg |= GSC_IN_ROT_180;
		break;
	case 90:
		if (ctx->gsc_ctrls.hflip->val)
			cfg |= GSC_IN_ROT_90_XFLIP;
		else if (ctx->gsc_ctrls.vflip->val)
			cfg |= GSC_IN_ROT_90_YFLIP;
		else
			cfg |= GSC_IN_ROT_90;
		break;
	case 0:
		if (ctx->gsc_ctrls.hflip->val)
			cfg |= GSC_IN_ROT_XFLIP;
		else if (ctx->gsc_ctrls.vflip->val)
			cfg |= GSC_IN_ROT_YFLIP;
	}

	writel(cfg, dev->regs + GSC_IN_CON);
}

void gsc_hw_set_global_alpha(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	struct gsc_frame *frame = &ctx->d_frame;
	u32 cfg;

	if (!is_rgb(frame->fmt->color)) {
		pr_debug("Not a RGB format");
		return;
	}

	cfg = readl(dev->regs + GSC_OUT_CON);
	cfg &= ~GSC_OUT_GLOBAL_ALPHA_MASK;

	cfg |= GSC_OUT_GLOBAL_ALPHA(ctx->gsc_ctrls.global_alpha->val);
	writel(cfg, dev->regs + GSC_OUT_CON);
}

void gsc_hw_set_sfr_update(struct gsc_ctx *ctx)
{
	struct gsc_dev *dev = ctx->gsc_dev;
	u32 cfg;

	cfg = readl(dev->regs + GSC_ENABLE);
	cfg |= GSC_ENABLE_SFR_UPDATE;
	writel(cfg, dev->regs + GSC_ENABLE);
}


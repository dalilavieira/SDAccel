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
typedef  scalar_t__ u32 ;
struct TYPE_6__ {int num_pads; TYPE_1__* pads; } ;
struct v4l2_subdev {TYPE_2__ entity; } ;
struct omap3isp_hist_config {scalar_t__ num_acc_frames; scalar_t__ cfa; scalar_t__* wg; int num_regions; scalar_t__ hist_bins; scalar_t__ buf_size; TYPE_4__* region; } ;
struct ispstat {scalar_t__ wait_acc_frames; int update; scalar_t__ state; scalar_t__ buf_size; int /*<<< orphan*/ * dma_ch; int /*<<< orphan*/  event_type; struct omap3isp_hist_config* priv; int /*<<< orphan*/ * ops; struct isp_device* isp; scalar_t__ inc_config; int /*<<< orphan*/  configured; int /*<<< orphan*/  buf_err; TYPE_3__* active_buf; int /*<<< orphan*/  config_counter; } ;
struct isp_pipeline {int state; } ;
struct isp_device {scalar_t__* mmio_base; scalar_t__ mmio_hist_base_phys; struct ispstat isp_hist; int /*<<< orphan*/  dev; } ;
struct dma_slave_config {int src_maxburst; int /*<<< orphan*/  src_addr_width; scalar_t__ src_addr; } ;
struct dma_async_tx_descriptor {void (* callback ) (void*) ;int /*<<< orphan*/  (* tx_submit ) (struct dma_async_tx_descriptor*) ;struct ispstat* callback_param; } ;
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;
typedef  enum isp_mem_resources { ____Placeholder_isp_mem_resources } isp_mem_resources ;
typedef  int /*<<< orphan*/  dma_cookie_t ;
typedef  int /*<<< orphan*/  dma_cap_mask_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;
typedef  int /*<<< orphan*/  cfg ;
struct TYPE_8__ {scalar_t__ h_start; scalar_t__ h_end; scalar_t__ v_start; scalar_t__ v_end; } ;
struct TYPE_7__ {scalar_t__* virt_addr; int /*<<< orphan*/  dma_addr; } ;
struct TYPE_5__ {int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_CTRL_ACK ; 
 int /*<<< orphan*/  DMA_DEV_TO_MEM ; 
 int /*<<< orphan*/  DMA_SLAVE ; 
 int /*<<< orphan*/  DMA_SLAVE_BUSWIDTH_4_BYTES ; 
 int EINVAL ; 
 long ENOIOCTLCMD ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HIST_CONFIG_DMA ; 
 scalar_t__ ISPHIST_ADDR ; 
 scalar_t__ ISPHIST_CNT ; 
 scalar_t__ ISPHIST_CNT_BINS_SHIFT ; 
 scalar_t__ ISPHIST_CNT_CFA_SHIFT ; 
 scalar_t__ ISPHIST_CNT_CLEAR ; 
 scalar_t__ ISPHIST_CNT_SHIFT_SHIFT ; 
 scalar_t__ ISPHIST_DATA ; 
 int /*<<< orphan*/  ISPHIST_IN_BIT_WIDTH_CCDC ; 
 scalar_t__ ISPHIST_PCR ; 
 int ISPHIST_PCR_BUSY ; 
 scalar_t__ ISPHIST_PCR_ENABLE ; 
 scalar_t__ ISPHIST_R0_HORZ ; 
 scalar_t__ ISPHIST_R0_VERT ; 
 scalar_t__ ISPHIST_R1_HORZ ; 
 scalar_t__ ISPHIST_R1_VERT ; 
 scalar_t__ ISPHIST_R2_HORZ ; 
 scalar_t__ ISPHIST_R2_VERT ; 
 scalar_t__ ISPHIST_R3_HORZ ; 
 scalar_t__ ISPHIST_R3_VERT ; 
 scalar_t__ ISPHIST_REG_END_SHIFT ; 
 int ISPHIST_REG_START_END_MASK ; 
 scalar_t__ ISPHIST_REG_START_SHIFT ; 
 scalar_t__ ISPHIST_WB_GAIN ; 
 scalar_t__ ISPHIST_WB_GAIN_WG00_SHIFT ; 
 scalar_t__ ISPHIST_WB_GAIN_WG01_SHIFT ; 
 scalar_t__ ISPHIST_WB_GAIN_WG02_SHIFT ; 
 scalar_t__ ISPHIST_WB_GAIN_WG03_SHIFT ; 
 scalar_t__ ISPSTAT_DISABLED ; 
 scalar_t__ ISPSTAT_DISABLING ; 
 scalar_t__ ISPSTAT_ENABLED ; 
 int ISP_PIPELINE_IDLE_INPUT ; 
 int ISP_PIPELINE_IDLE_OUTPUT ; 
 int ISP_PIPELINE_QUEUE_INPUT ; 
 int ISP_PIPELINE_QUEUE_OUTPUT ; 
 int ISP_PIPELINE_STREAM_INPUT ; 
 int ISP_PIPELINE_STREAM_OUTPUT ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int MEDIA_PAD_FL_SINK ; 
#define  OMAP3ISP_HIST_BINS_128 134 
#define  OMAP3ISP_HIST_BINS_256 133 
#define  OMAP3ISP_HIST_BINS_64 132 
 scalar_t__ OMAP3ISP_HIST_CFA_BAYER ; 
 scalar_t__ OMAP3ISP_HIST_CFA_FOVEONX3 ; 
 scalar_t__ OMAP3ISP_HIST_MAX_BUF_SIZE ; 
 int OMAP3ISP_HIST_MAX_REGIONS ; 
 int OMAP3ISP_HIST_MAX_WG ; 
 int OMAP3ISP_HIST_MEM_SIZE ; 
 scalar_t__ OMAP3ISP_HIST_MEM_SIZE_BINS (int) ; 
 scalar_t__ OMAP3ISP_HIST_MIN_REGIONS ; 
 int OMAP3_ISP_IOMEM_HIST ; 
 int /*<<< orphan*/  OMAP3_ISP_SUBCLK_HIST ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int STAT_BUF_DONE ; 
 int STAT_BUF_WAITING_DMA ; 
 int STAT_NO_BUF ; 
 int V4L2_BUF_TYPE_VIDEO_CAPTURE ; 
 int V4L2_BUF_TYPE_VIDEO_OUTPUT ; 
 int /*<<< orphan*/  V4L2_EVENT_OMAP3ISP_HIST ; 
#define  VIDIOC_OMAP3ISP_HIST_CFG 131 
#define  VIDIOC_OMAP3ISP_STAT_EN 130 
#define  VIDIOC_OMAP3ISP_STAT_REQ 129 
#define  VIDIOC_OMAP3ISP_STAT_REQ_TIME32 128 
 scalar_t__ __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (scalar_t__,scalar_t__) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 struct omap3isp_hist_config* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_async_issue_pending (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dma_cap_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_cap_zero (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_chan_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dma_release_channel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dma_request_chan_by_mask (int /*<<< orphan*/ *) ; 
 scalar_t__ dma_submit_error (int /*<<< orphan*/ ) ; 
 struct dma_async_tx_descriptor* dmaengine_prep_slave_single (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dmaengine_slave_config (int /*<<< orphan*/ *,struct dma_slave_config*) ; 
 int /*<<< orphan*/  hist_ops ; 
 int /*<<< orphan*/  hist_subdev_ops ; 
 int /*<<< orphan*/  memcpy (struct omap3isp_hist_config*,struct omap3isp_hist_config*,int) ; 
 int /*<<< orphan*/  memset (struct dma_slave_config*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  omap3isp_flush (struct isp_device*) ; 
 int /*<<< orphan*/  omap3isp_hist_dma_done (struct isp_device*) ; 
 int /*<<< orphan*/  omap3isp_stat_cleanup (struct ispstat*) ; 
 long omap3isp_stat_config (struct ispstat*,void*) ; 
 int /*<<< orphan*/  omap3isp_stat_dma_isr (struct ispstat*) ; 
 long omap3isp_stat_enable (struct ispstat*,int) ; 
 int omap3isp_stat_init (struct ispstat*,char*,int /*<<< orphan*/ *) ; 
 long omap3isp_stat_request_statistics (struct ispstat*,void*) ; 
 long omap3isp_stat_request_statistics_time32 (struct ispstat*,void*) ; 
 int /*<<< orphan*/  omap3isp_subclk_disable (struct isp_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap3isp_subclk_enable (struct isp_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct dma_async_tx_descriptor*) ; 
 scalar_t__ unlikely (int) ; 
 struct ispstat* v4l2_get_subdevdata (struct v4l2_subdev*) ; 

__attribute__((used)) static inline int isp_pipeline_ready(struct isp_pipeline *pipe)
{
	return pipe->state == (ISP_PIPELINE_STREAM_INPUT |
			       ISP_PIPELINE_STREAM_OUTPUT |
			       ISP_PIPELINE_QUEUE_INPUT |
			       ISP_PIPELINE_QUEUE_OUTPUT |
			       ISP_PIPELINE_IDLE_INPUT |
			       ISP_PIPELINE_IDLE_OUTPUT);
}

__attribute__((used)) static inline
u32 isp_reg_readl(struct isp_device *isp, enum isp_mem_resources isp_mmio_range,
		  u32 reg_offset)
{
	return __raw_readl(isp->mmio_base[isp_mmio_range] + reg_offset);
}

__attribute__((used)) static inline
void isp_reg_writel(struct isp_device *isp, u32 reg_value,
		    enum isp_mem_resources isp_mmio_range, u32 reg_offset)
{
	__raw_writel(reg_value, isp->mmio_base[isp_mmio_range] + reg_offset);
}

__attribute__((used)) static inline
void isp_reg_clr(struct isp_device *isp, enum isp_mem_resources mmio_range,
		 u32 reg, u32 clr_bits)
{
	u32 v = isp_reg_readl(isp, mmio_range, reg);

	isp_reg_writel(isp, v & ~clr_bits, mmio_range, reg);
}

__attribute__((used)) static inline
void isp_reg_set(struct isp_device *isp, enum isp_mem_resources mmio_range,
		 u32 reg, u32 set_bits)
{
	u32 v = isp_reg_readl(isp, mmio_range, reg);

	isp_reg_writel(isp, v | set_bits, mmio_range, reg);
}

__attribute__((used)) static inline
void isp_reg_clr_set(struct isp_device *isp, enum isp_mem_resources mmio_range,
		     u32 reg, u32 clr_bits, u32 set_bits)
{
	u32 v = isp_reg_readl(isp, mmio_range, reg);

	isp_reg_writel(isp, (v & ~clr_bits) | set_bits, mmio_range, reg);
}

__attribute__((used)) static inline enum v4l2_buf_type
isp_pad_buffer_type(const struct v4l2_subdev *subdev, int pad)
{
	if (pad >= subdev->entity.num_pads)
		return 0;

	if (subdev->entity.pads[pad].flags & MEDIA_PAD_FL_SINK)
		return V4L2_BUF_TYPE_VIDEO_OUTPUT;
	else
		return V4L2_BUF_TYPE_VIDEO_CAPTURE;
}

__attribute__((used)) static void hist_reset_mem(struct ispstat *hist)
{
	struct isp_device *isp = hist->isp;
	struct omap3isp_hist_config *conf = hist->priv;
	unsigned int i;

	isp_reg_writel(isp, 0, OMAP3_ISP_IOMEM_HIST, ISPHIST_ADDR);

	/*
	 * By setting it, the histogram internal buffer is being cleared at the
	 * same time it's being read. This bit must be cleared afterwards.
	 */
	isp_reg_set(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT, ISPHIST_CNT_CLEAR);

	/*
	 * We'll clear 4 words at each iteration for optimization. It avoids
	 * 3/4 of the jumps. We also know HIST_MEM_SIZE is divisible by 4.
	 */
	for (i = OMAP3ISP_HIST_MEM_SIZE / 4; i > 0; i--) {
		isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
		isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
		isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
		isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
	}
	isp_reg_clr(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT, ISPHIST_CNT_CLEAR);

	hist->wait_acc_frames = conf->num_acc_frames;
}

__attribute__((used)) static void hist_setup_regs(struct ispstat *hist, void *priv)
{
	struct isp_device *isp = hist->isp;
	struct omap3isp_hist_config *conf = priv;
	int c;
	u32 cnt;
	u32 wb_gain;
	u32 reg_hor[OMAP3ISP_HIST_MAX_REGIONS];
	u32 reg_ver[OMAP3ISP_HIST_MAX_REGIONS];

	if (!hist->update || hist->state == ISPSTAT_DISABLED ||
	    hist->state == ISPSTAT_DISABLING)
		return;

	cnt = conf->cfa << ISPHIST_CNT_CFA_SHIFT;

	wb_gain = conf->wg[0] << ISPHIST_WB_GAIN_WG00_SHIFT;
	wb_gain |= conf->wg[1] << ISPHIST_WB_GAIN_WG01_SHIFT;
	wb_gain |= conf->wg[2] << ISPHIST_WB_GAIN_WG02_SHIFT;
	if (conf->cfa == OMAP3ISP_HIST_CFA_BAYER)
		wb_gain |= conf->wg[3] << ISPHIST_WB_GAIN_WG03_SHIFT;

	/* Regions size and position */
	for (c = 0; c < OMAP3ISP_HIST_MAX_REGIONS; c++) {
		if (c < conf->num_regions) {
			reg_hor[c] = (conf->region[c].h_start <<
				     ISPHIST_REG_START_SHIFT)
				   | (conf->region[c].h_end <<
				     ISPHIST_REG_END_SHIFT);
			reg_ver[c] = (conf->region[c].v_start <<
				     ISPHIST_REG_START_SHIFT)
				   | (conf->region[c].v_end <<
				     ISPHIST_REG_END_SHIFT);
		} else {
			reg_hor[c] = 0;
			reg_ver[c] = 0;
		}
	}

	cnt |= conf->hist_bins << ISPHIST_CNT_BINS_SHIFT;
	switch (conf->hist_bins) {
	case OMAP3ISP_HIST_BINS_256:
		cnt |= (ISPHIST_IN_BIT_WIDTH_CCDC - 8) <<
			ISPHIST_CNT_SHIFT_SHIFT;
		break;
	case OMAP3ISP_HIST_BINS_128:
		cnt |= (ISPHIST_IN_BIT_WIDTH_CCDC - 7) <<
			ISPHIST_CNT_SHIFT_SHIFT;
		break;
	case OMAP3ISP_HIST_BINS_64:
		cnt |= (ISPHIST_IN_BIT_WIDTH_CCDC - 6) <<
			ISPHIST_CNT_SHIFT_SHIFT;
		break;
	default: /* OMAP3ISP_HIST_BINS_32 */
		cnt |= (ISPHIST_IN_BIT_WIDTH_CCDC - 5) <<
			ISPHIST_CNT_SHIFT_SHIFT;
		break;
	}

	hist_reset_mem(hist);

	isp_reg_writel(isp, cnt, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT);
	isp_reg_writel(isp, wb_gain,  OMAP3_ISP_IOMEM_HIST, ISPHIST_WB_GAIN);
	isp_reg_writel(isp, reg_hor[0], OMAP3_ISP_IOMEM_HIST, ISPHIST_R0_HORZ);
	isp_reg_writel(isp, reg_ver[0], OMAP3_ISP_IOMEM_HIST, ISPHIST_R0_VERT);
	isp_reg_writel(isp, reg_hor[1], OMAP3_ISP_IOMEM_HIST, ISPHIST_R1_HORZ);
	isp_reg_writel(isp, reg_ver[1], OMAP3_ISP_IOMEM_HIST, ISPHIST_R1_VERT);
	isp_reg_writel(isp, reg_hor[2], OMAP3_ISP_IOMEM_HIST, ISPHIST_R2_HORZ);
	isp_reg_writel(isp, reg_ver[2], OMAP3_ISP_IOMEM_HIST, ISPHIST_R2_VERT);
	isp_reg_writel(isp, reg_hor[3], OMAP3_ISP_IOMEM_HIST, ISPHIST_R3_HORZ);
	isp_reg_writel(isp, reg_ver[3], OMAP3_ISP_IOMEM_HIST, ISPHIST_R3_VERT);

	hist->update = 0;
	hist->config_counter += hist->inc_config;
	hist->inc_config = 0;
	hist->buf_size = conf->buf_size;
}

__attribute__((used)) static void hist_enable(struct ispstat *hist, int enable)
{
	if (enable) {
		isp_reg_set(hist->isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_PCR,
			    ISPHIST_PCR_ENABLE);
		omap3isp_subclk_enable(hist->isp, OMAP3_ISP_SUBCLK_HIST);
	} else {
		isp_reg_clr(hist->isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_PCR,
			    ISPHIST_PCR_ENABLE);
		omap3isp_subclk_disable(hist->isp, OMAP3_ISP_SUBCLK_HIST);
	}
}

__attribute__((used)) static int hist_busy(struct ispstat *hist)
{
	return isp_reg_readl(hist->isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_PCR)
						& ISPHIST_PCR_BUSY;
}

__attribute__((used)) static void hist_dma_cb(void *data)
{
	struct ispstat *hist = data;

	/* FIXME: The DMA engine API can't report transfer errors :-/ */

	isp_reg_clr(hist->isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT,
		    ISPHIST_CNT_CLEAR);

	omap3isp_stat_dma_isr(hist);
	if (hist->state != ISPSTAT_DISABLED)
		omap3isp_hist_dma_done(hist->isp);
}

__attribute__((used)) static int hist_buf_dma(struct ispstat *hist)
{
	dma_addr_t dma_addr = hist->active_buf->dma_addr;
	struct dma_async_tx_descriptor *tx;
	struct dma_slave_config cfg;
	dma_cookie_t cookie;
	int ret;

	if (unlikely(!dma_addr)) {
		dev_dbg(hist->isp->dev, "hist: invalid DMA buffer address\n");
		goto error;
	}

	isp_reg_writel(hist->isp, 0, OMAP3_ISP_IOMEM_HIST, ISPHIST_ADDR);
	isp_reg_set(hist->isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT,
		    ISPHIST_CNT_CLEAR);
	omap3isp_flush(hist->isp);

	memset(&cfg, 0, sizeof(cfg));
	cfg.src_addr = hist->isp->mmio_hist_base_phys + ISPHIST_DATA;
	cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	cfg.src_maxburst = hist->buf_size / 4;

	ret = dmaengine_slave_config(hist->dma_ch, &cfg);
	if (ret < 0) {
		dev_dbg(hist->isp->dev,
			"hist: DMA slave configuration failed\n");
		goto error;
	}

	tx = dmaengine_prep_slave_single(hist->dma_ch, dma_addr,
					 hist->buf_size, DMA_DEV_TO_MEM,
					 DMA_CTRL_ACK);
	if (tx == NULL) {
		dev_dbg(hist->isp->dev,
			"hist: DMA slave preparation failed\n");
		goto error;
	}

	tx->callback = hist_dma_cb;
	tx->callback_param = hist;
	cookie = tx->tx_submit(tx);
	if (dma_submit_error(cookie)) {
		dev_dbg(hist->isp->dev, "hist: DMA submission failed\n");
		goto error;
	}

	dma_async_issue_pending(hist->dma_ch);

	return STAT_BUF_WAITING_DMA;

error:
	hist_reset_mem(hist);
	return STAT_NO_BUF;
}

__attribute__((used)) static int hist_buf_pio(struct ispstat *hist)
{
	struct isp_device *isp = hist->isp;
	u32 *buf = hist->active_buf->virt_addr;
	unsigned int i;

	if (!buf) {
		dev_dbg(isp->dev, "hist: invalid PIO buffer address\n");
		hist_reset_mem(hist);
		return STAT_NO_BUF;
	}

	isp_reg_writel(isp, 0, OMAP3_ISP_IOMEM_HIST, ISPHIST_ADDR);

	/*
	 * By setting it, the histogram internal buffer is being cleared at the
	 * same time it's being read. This bit must be cleared just after all
	 * data is acquired.
	 */
	isp_reg_set(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT, ISPHIST_CNT_CLEAR);

	/*
	 * We'll read 4 times a 4-bytes-word at each iteration for
	 * optimization. It avoids 3/4 of the jumps. We also know buf_size is
	 * divisible by 16.
	 */
	for (i = hist->buf_size / 16; i > 0; i--) {
		*buf++ = isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
		*buf++ = isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
		*buf++ = isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
		*buf++ = isp_reg_readl(isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_DATA);
	}
	isp_reg_clr(hist->isp, OMAP3_ISP_IOMEM_HIST, ISPHIST_CNT,
		    ISPHIST_CNT_CLEAR);

	return STAT_BUF_DONE;
}

__attribute__((used)) static int hist_buf_process(struct ispstat *hist)
{
	struct omap3isp_hist_config *user_cfg = hist->priv;
	int ret;

	if (atomic_read(&hist->buf_err) || hist->state != ISPSTAT_ENABLED) {
		hist_reset_mem(hist);
		return STAT_NO_BUF;
	}

	if (--(hist->wait_acc_frames))
		return STAT_NO_BUF;

	if (hist->dma_ch)
		ret = hist_buf_dma(hist);
	else
		ret = hist_buf_pio(hist);

	hist->wait_acc_frames = user_cfg->num_acc_frames;

	return ret;
}

__attribute__((used)) static u32 hist_get_buf_size(struct omap3isp_hist_config *conf)
{
	return OMAP3ISP_HIST_MEM_SIZE_BINS(conf->hist_bins) * conf->num_regions;
}

__attribute__((used)) static int hist_validate_params(struct ispstat *hist, void *new_conf)
{
	struct omap3isp_hist_config *user_cfg = new_conf;
	int c;
	u32 buf_size;

	if (user_cfg->cfa > OMAP3ISP_HIST_CFA_FOVEONX3)
		return -EINVAL;

	/* Regions size and position */

	if ((user_cfg->num_regions < OMAP3ISP_HIST_MIN_REGIONS) ||
	    (user_cfg->num_regions > OMAP3ISP_HIST_MAX_REGIONS))
		return -EINVAL;

	/* Regions */
	for (c = 0; c < user_cfg->num_regions; c++) {
		if (user_cfg->region[c].h_start & ~ISPHIST_REG_START_END_MASK)
			return -EINVAL;
		if (user_cfg->region[c].h_end & ~ISPHIST_REG_START_END_MASK)
			return -EINVAL;
		if (user_cfg->region[c].v_start & ~ISPHIST_REG_START_END_MASK)
			return -EINVAL;
		if (user_cfg->region[c].v_end & ~ISPHIST_REG_START_END_MASK)
			return -EINVAL;
		if (user_cfg->region[c].h_start > user_cfg->region[c].h_end)
			return -EINVAL;
		if (user_cfg->region[c].v_start > user_cfg->region[c].v_end)
			return -EINVAL;
	}

	switch (user_cfg->num_regions) {
	case 1:
		if (user_cfg->hist_bins > OMAP3ISP_HIST_BINS_256)
			return -EINVAL;
		break;
	case 2:
		if (user_cfg->hist_bins > OMAP3ISP_HIST_BINS_128)
			return -EINVAL;
		break;
	default: /* 3 or 4 */
		if (user_cfg->hist_bins > OMAP3ISP_HIST_BINS_64)
			return -EINVAL;
		break;
	}

	buf_size = hist_get_buf_size(user_cfg);
	if (buf_size > user_cfg->buf_size)
		/* User's buf_size request wasn't enough */
		user_cfg->buf_size = buf_size;
	else if (user_cfg->buf_size > OMAP3ISP_HIST_MAX_BUF_SIZE)
		user_cfg->buf_size = OMAP3ISP_HIST_MAX_BUF_SIZE;

	return 0;
}

__attribute__((used)) static int hist_comp_params(struct ispstat *hist,
			    struct omap3isp_hist_config *user_cfg)
{
	struct omap3isp_hist_config *cur_cfg = hist->priv;
	int c;

	if (cur_cfg->cfa != user_cfg->cfa)
		return 1;

	if (cur_cfg->num_acc_frames != user_cfg->num_acc_frames)
		return 1;

	if (cur_cfg->hist_bins != user_cfg->hist_bins)
		return 1;

	for (c = 0; c < OMAP3ISP_HIST_MAX_WG; c++) {
		if (c == 3 && user_cfg->cfa == OMAP3ISP_HIST_CFA_FOVEONX3)
			break;
		else if (cur_cfg->wg[c] != user_cfg->wg[c])
			return 1;
	}

	if (cur_cfg->num_regions != user_cfg->num_regions)
		return 1;

	/* Regions */
	for (c = 0; c < user_cfg->num_regions; c++) {
		if (cur_cfg->region[c].h_start != user_cfg->region[c].h_start)
			return 1;
		if (cur_cfg->region[c].h_end != user_cfg->region[c].h_end)
			return 1;
		if (cur_cfg->region[c].v_start != user_cfg->region[c].v_start)
			return 1;
		if (cur_cfg->region[c].v_end != user_cfg->region[c].v_end)
			return 1;
	}

	return 0;
}

__attribute__((used)) static void hist_set_params(struct ispstat *hist, void *new_conf)
{
	struct omap3isp_hist_config *user_cfg = new_conf;
	struct omap3isp_hist_config *cur_cfg = hist->priv;

	if (!hist->configured || hist_comp_params(hist, user_cfg)) {
		memcpy(cur_cfg, user_cfg, sizeof(*user_cfg));
		if (user_cfg->num_acc_frames == 0)
			user_cfg->num_acc_frames = 1;
		hist->inc_config++;
		hist->update = 1;
		/*
		 * User might be asked for a bigger buffer than necessary for
		 * this configuration. In order to return the right amount of
		 * data during buffer request, let's calculate the size here
		 * instead of stick with user_cfg->buf_size.
		 */
		cur_cfg->buf_size = hist_get_buf_size(cur_cfg);

	}
}

__attribute__((used)) static long hist_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
	struct ispstat *stat = v4l2_get_subdevdata(sd);

	switch (cmd) {
	case VIDIOC_OMAP3ISP_HIST_CFG:
		return omap3isp_stat_config(stat, arg);
	case VIDIOC_OMAP3ISP_STAT_REQ:
		return omap3isp_stat_request_statistics(stat, arg);
	case VIDIOC_OMAP3ISP_STAT_REQ_TIME32:
		return omap3isp_stat_request_statistics_time32(stat, arg);
	case VIDIOC_OMAP3ISP_STAT_EN: {
		int *en = arg;
		return omap3isp_stat_enable(stat, !!*en);
	}
	}

	return -ENOIOCTLCMD;

}

int omap3isp_hist_init(struct isp_device *isp)
{
	struct ispstat *hist = &isp->isp_hist;
	struct omap3isp_hist_config *hist_cfg;
	int ret = -1;

	hist_cfg = devm_kzalloc(isp->dev, sizeof(*hist_cfg), GFP_KERNEL);
	if (hist_cfg == NULL)
		return -ENOMEM;

	hist->isp = isp;

	if (HIST_CONFIG_DMA) {
		dma_cap_mask_t mask;

		/*
		 * We need slave capable channel without DMA request line for
		 * reading out the data.
		 * For this we can use dma_request_chan_by_mask() as we are
		 * happy with any channel as long as it is capable of slave
		 * configuration.
		 */
		dma_cap_zero(mask);
		dma_cap_set(DMA_SLAVE, mask);
		hist->dma_ch = dma_request_chan_by_mask(&mask);
		if (IS_ERR(hist->dma_ch)) {
			ret = PTR_ERR(hist->dma_ch);
			if (ret == -EPROBE_DEFER)
				return ret;

			hist->dma_ch = NULL;
			dev_warn(isp->dev,
				 "hist: DMA channel request failed, using PIO\n");
		} else {
			dev_dbg(isp->dev, "hist: using DMA channel %s\n",
				dma_chan_name(hist->dma_ch));
		}
	}

	hist->ops = &hist_ops;
	hist->priv = hist_cfg;
	hist->event_type = V4L2_EVENT_OMAP3ISP_HIST;

	ret = omap3isp_stat_init(hist, "histogram", &hist_subdev_ops);
	if (ret) {
		if (hist->dma_ch)
			dma_release_channel(hist->dma_ch);
	}

	return ret;
}

void omap3isp_hist_cleanup(struct isp_device *isp)
{
	struct ispstat *hist = &isp->isp_hist;

	if (hist->dma_ch)
		dma_release_channel(hist->dma_ch);

	omap3isp_stat_cleanup(hist);
}


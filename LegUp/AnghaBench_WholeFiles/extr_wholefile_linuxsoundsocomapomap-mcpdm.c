#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai {int /*<<< orphan*/  active; } ;
struct snd_pcm_substream {size_t stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_dmaengine_dai_dma_data {int maxburst; } ;
struct resource {scalar_t__ start; } ;
struct pm_qos_request {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct omap_mcpdm {int dn_rx_offset; int* latency; int restart; scalar_t__ irq; struct device* dev; scalar_t__ io_base; TYPE_2__* dma_data; int /*<<< orphan*/  mutex; struct pm_qos_request pm_qos_req; TYPE_1__* config; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {char* filter_data; scalar_t__ addr; } ;
struct TYPE_4__ {int link_mask; int threshold; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int MCPDM_DMA_DN_ENABLE ; 
 int MCPDM_DMA_UP_ENABLE ; 
 int MCPDM_DNOFST_RX1 (int /*<<< orphan*/ ) ; 
 int MCPDM_DNOFST_RX2 (int /*<<< orphan*/ ) ; 
 int MCPDM_DN_IRQ ; 
 int MCPDM_DN_IRQ_EMPTY ; 
 int MCPDM_DN_IRQ_FULL ; 
 int MCPDM_DN_OFST_RX1_EN ; 
 int MCPDM_DN_OFST_RX2_EN ; 
 int MCPDM_DN_THRES_MAX ; 
 int MCPDM_PDM_DN_MASK ; 
 int MCPDM_PDM_UP_MASK ; 
 scalar_t__ MCPDM_REG_CTRL ; 
 scalar_t__ MCPDM_REG_DMAENABLE_CLR ; 
 scalar_t__ MCPDM_REG_DMAENABLE_SET ; 
 scalar_t__ MCPDM_REG_DN_DATA ; 
 scalar_t__ MCPDM_REG_DN_OFFSET ; 
 scalar_t__ MCPDM_REG_FIFO_CTRL_DN ; 
 scalar_t__ MCPDM_REG_FIFO_CTRL_UP ; 
 scalar_t__ MCPDM_REG_IRQENABLE_CLR ; 
 scalar_t__ MCPDM_REG_IRQENABLE_SET ; 
 scalar_t__ MCPDM_REG_IRQSTATUS ; 
 scalar_t__ MCPDM_REG_UP_DATA ; 
 int MCPDM_SW_DN_RST ; 
 int MCPDM_SW_UP_RST ; 
 int MCPDM_UP_IRQ ; 
 int MCPDM_UP_IRQ_EMPTY ; 
 int MCPDM_UP_IRQ_FULL ; 
 int MCPDM_UP_THRES_MAX ; 
 int MCPDM_WD_EN ; 
 int /*<<< orphan*/  PM_QOS_CPU_DMA_LATENCY ; 
 int PTR_ERR (scalar_t__) ; 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
 size_t SNDRV_PCM_STREAM_PLAYBACK ; 
 int USEC_PER_SEC ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct omap_mcpdm* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,void*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  omap_mcpdm_component ; 
 int /*<<< orphan*/  omap_mcpdm_dai ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct omap_mcpdm*) ; 
 int /*<<< orphan*/  pm_qos_add_request (struct pm_qos_request*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pm_qos_remove_request (struct pm_qos_request*) ; 
 scalar_t__ pm_qos_request_active (struct pm_qos_request*) ; 
 int /*<<< orphan*/  pm_qos_update_request (struct pm_qos_request*,int) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int readl_relaxed (scalar_t__) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,void*) ; 
 struct snd_dmaengine_dai_dma_data* snd_soc_dai_get_dma_data (struct snd_soc_dai*,struct snd_pcm_substream*) ; 
 struct omap_mcpdm* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int /*<<< orphan*/  snd_soc_dai_init_dma_data (struct snd_soc_dai*,TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline int sdma_pcm_platform_register(struct device *dev,
					     char *txdmachan, char *rxdmachan)
{
	return -ENODEV;
}

__attribute__((used)) static inline void omap_mcpdm_write(struct omap_mcpdm *mcpdm, u16 reg, u32 val)
{
	writel_relaxed(val, mcpdm->io_base + reg);
}

__attribute__((used)) static inline int omap_mcpdm_read(struct omap_mcpdm *mcpdm, u16 reg)
{
	return readl_relaxed(mcpdm->io_base + reg);
}

__attribute__((used)) static void omap_mcpdm_reg_dump(struct omap_mcpdm *mcpdm) {}

__attribute__((used)) static void omap_mcpdm_start(struct omap_mcpdm *mcpdm)
{
	u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);
	u32 link_mask = mcpdm->config[0].link_mask | mcpdm->config[1].link_mask;

	ctrl |= (MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);

	ctrl |= link_mask;
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);

	ctrl &= ~(MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
}

__attribute__((used)) static void omap_mcpdm_stop(struct omap_mcpdm *mcpdm)
{
	u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);
	u32 link_mask = MCPDM_PDM_DN_MASK | MCPDM_PDM_UP_MASK;

	ctrl |= (MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);

	ctrl &= ~(link_mask);
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);

	ctrl &= ~(MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);

}

__attribute__((used)) static inline int omap_mcpdm_active(struct omap_mcpdm *mcpdm)
{
	return omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL) &
					(MCPDM_PDM_DN_MASK | MCPDM_PDM_UP_MASK);
}

__attribute__((used)) static void omap_mcpdm_open_streams(struct omap_mcpdm *mcpdm)
{
	u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);

	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl | MCPDM_WD_EN);

	omap_mcpdm_write(mcpdm, MCPDM_REG_IRQENABLE_SET,
			MCPDM_DN_IRQ_EMPTY | MCPDM_DN_IRQ_FULL |
			MCPDM_UP_IRQ_EMPTY | MCPDM_UP_IRQ_FULL);

	/* Enable DN RX1/2 offset cancellation feature, if configured */
	if (mcpdm->dn_rx_offset) {
		u32 dn_offset = mcpdm->dn_rx_offset;

		omap_mcpdm_write(mcpdm, MCPDM_REG_DN_OFFSET, dn_offset);
		dn_offset |= (MCPDM_DN_OFST_RX1_EN | MCPDM_DN_OFST_RX2_EN);
		omap_mcpdm_write(mcpdm, MCPDM_REG_DN_OFFSET, dn_offset);
	}

	omap_mcpdm_write(mcpdm, MCPDM_REG_FIFO_CTRL_DN,
			 mcpdm->config[SNDRV_PCM_STREAM_PLAYBACK].threshold);
	omap_mcpdm_write(mcpdm, MCPDM_REG_FIFO_CTRL_UP,
			 mcpdm->config[SNDRV_PCM_STREAM_CAPTURE].threshold);

	omap_mcpdm_write(mcpdm, MCPDM_REG_DMAENABLE_SET,
			MCPDM_DMA_DN_ENABLE | MCPDM_DMA_UP_ENABLE);
}

__attribute__((used)) static void omap_mcpdm_close_streams(struct omap_mcpdm *mcpdm)
{
	/* Disable irq request generation for downlink */
	omap_mcpdm_write(mcpdm, MCPDM_REG_IRQENABLE_CLR,
			MCPDM_DN_IRQ_EMPTY | MCPDM_DN_IRQ_FULL);

	/* Disable DMA request generation for downlink */
	omap_mcpdm_write(mcpdm, MCPDM_REG_DMAENABLE_CLR, MCPDM_DMA_DN_ENABLE);

	/* Disable irq request generation for uplink */
	omap_mcpdm_write(mcpdm, MCPDM_REG_IRQENABLE_CLR,
			MCPDM_UP_IRQ_EMPTY | MCPDM_UP_IRQ_FULL);

	/* Disable DMA request generation for uplink */
	omap_mcpdm_write(mcpdm, MCPDM_REG_DMAENABLE_CLR, MCPDM_DMA_UP_ENABLE);

	/* Disable RX1/2 offset cancellation */
	if (mcpdm->dn_rx_offset)
		omap_mcpdm_write(mcpdm, MCPDM_REG_DN_OFFSET, 0);
}

__attribute__((used)) static irqreturn_t omap_mcpdm_irq_handler(int irq, void *dev_id)
{
	struct omap_mcpdm *mcpdm = dev_id;
	int irq_status;

	irq_status = omap_mcpdm_read(mcpdm, MCPDM_REG_IRQSTATUS);

	/* Acknowledge irq event */
	omap_mcpdm_write(mcpdm, MCPDM_REG_IRQSTATUS, irq_status);

	if (irq_status & MCPDM_DN_IRQ_FULL)
		dev_dbg(mcpdm->dev, "DN (playback) FIFO Full\n");

	if (irq_status & MCPDM_DN_IRQ_EMPTY)
		dev_dbg(mcpdm->dev, "DN (playback) FIFO Empty\n");

	if (irq_status & MCPDM_DN_IRQ)
		dev_dbg(mcpdm->dev, "DN (playback) write request\n");

	if (irq_status & MCPDM_UP_IRQ_FULL)
		dev_dbg(mcpdm->dev, "UP (capture) FIFO Full\n");

	if (irq_status & MCPDM_UP_IRQ_EMPTY)
		dev_dbg(mcpdm->dev, "UP (capture) FIFO Empty\n");

	if (irq_status & MCPDM_UP_IRQ)
		dev_dbg(mcpdm->dev, "UP (capture) write request\n");

	return IRQ_HANDLED;
}

__attribute__((used)) static int omap_mcpdm_dai_startup(struct snd_pcm_substream *substream,
				  struct snd_soc_dai *dai)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);

	mutex_lock(&mcpdm->mutex);

	if (!dai->active)
		omap_mcpdm_open_streams(mcpdm);

	mutex_unlock(&mcpdm->mutex);

	return 0;
}

__attribute__((used)) static void omap_mcpdm_dai_shutdown(struct snd_pcm_substream *substream,
				  struct snd_soc_dai *dai)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
	int tx = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
	int stream1 = tx ? SNDRV_PCM_STREAM_PLAYBACK : SNDRV_PCM_STREAM_CAPTURE;
	int stream2 = tx ? SNDRV_PCM_STREAM_CAPTURE : SNDRV_PCM_STREAM_PLAYBACK;

	mutex_lock(&mcpdm->mutex);

	if (!dai->active) {
		if (omap_mcpdm_active(mcpdm)) {
			omap_mcpdm_stop(mcpdm);
			omap_mcpdm_close_streams(mcpdm);
			mcpdm->config[0].link_mask = 0;
			mcpdm->config[1].link_mask = 0;
		}
	}

	if (mcpdm->latency[stream2])
		pm_qos_update_request(&mcpdm->pm_qos_req,
				      mcpdm->latency[stream2]);
	else if (mcpdm->latency[stream1])
		pm_qos_remove_request(&mcpdm->pm_qos_req);

	mcpdm->latency[stream1] = 0;

	mutex_unlock(&mcpdm->mutex);
}

__attribute__((used)) static int omap_mcpdm_dai_hw_params(struct snd_pcm_substream *substream,
				    struct snd_pcm_hw_params *params,
				    struct snd_soc_dai *dai)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
	int stream = substream->stream;
	struct snd_dmaengine_dai_dma_data *dma_data;
	u32 threshold;
	int channels, latency;
	int link_mask = 0;

	channels = params_channels(params);
	switch (channels) {
	case 5:
		if (stream == SNDRV_PCM_STREAM_CAPTURE)
			/* up to 3 channels for capture */
			return -EINVAL;
		link_mask |= 1 << 4;
		/* fall through */
	case 4:
		if (stream == SNDRV_PCM_STREAM_CAPTURE)
			/* up to 3 channels for capture */
			return -EINVAL;
		link_mask |= 1 << 3;
		/* fall through */
	case 3:
		link_mask |= 1 << 2;
		/* fall through */
	case 2:
		link_mask |= 1 << 1;
		/* fall through */
	case 1:
		link_mask |= 1 << 0;
		break;
	default:
		/* unsupported number of channels */
		return -EINVAL;
	}

	dma_data = snd_soc_dai_get_dma_data(dai, substream);

	threshold = mcpdm->config[stream].threshold;
	/* Configure McPDM channels, and DMA packet size */
	if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
		link_mask <<= 3;

		/* If capture is not running assume a stereo stream to come */
		if (!mcpdm->config[!stream].link_mask)
			mcpdm->config[!stream].link_mask = 0x3;

		dma_data->maxburst =
				(MCPDM_DN_THRES_MAX - threshold) * channels;
		latency = threshold;
	} else {
		/* If playback is not running assume a stereo stream to come */
		if (!mcpdm->config[!stream].link_mask)
			mcpdm->config[!stream].link_mask = (0x3 << 3);

		dma_data->maxburst = threshold * channels;
		latency = (MCPDM_DN_THRES_MAX - threshold);
	}

	/*
	 * The DMA must act to a DMA request within latency time (usec) to avoid
	 * under/overflow
	 */
	mcpdm->latency[stream] = latency * USEC_PER_SEC / params_rate(params);

	if (!mcpdm->latency[stream])
		mcpdm->latency[stream] = 10;

	/* Check if we need to restart McPDM with this stream */
	if (mcpdm->config[stream].link_mask &&
	    mcpdm->config[stream].link_mask != link_mask)
		mcpdm->restart = true;

	mcpdm->config[stream].link_mask = link_mask;

	return 0;
}

__attribute__((used)) static int omap_mcpdm_prepare(struct snd_pcm_substream *substream,
				  struct snd_soc_dai *dai)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
	struct pm_qos_request *pm_qos_req = &mcpdm->pm_qos_req;
	int tx = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
	int stream1 = tx ? SNDRV_PCM_STREAM_PLAYBACK : SNDRV_PCM_STREAM_CAPTURE;
	int stream2 = tx ? SNDRV_PCM_STREAM_CAPTURE : SNDRV_PCM_STREAM_PLAYBACK;
	int latency = mcpdm->latency[stream2];

	/* Prevent omap hardware from hitting off between FIFO fills */
	if (!latency || mcpdm->latency[stream1] < latency)
		latency = mcpdm->latency[stream1];

	if (pm_qos_request_active(pm_qos_req))
		pm_qos_update_request(pm_qos_req, latency);
	else if (latency)
		pm_qos_add_request(pm_qos_req, PM_QOS_CPU_DMA_LATENCY, latency);

	if (!omap_mcpdm_active(mcpdm)) {
		omap_mcpdm_start(mcpdm);
		omap_mcpdm_reg_dump(mcpdm);
	} else if (mcpdm->restart) {
		omap_mcpdm_stop(mcpdm);
		omap_mcpdm_start(mcpdm);
		mcpdm->restart = false;
		omap_mcpdm_reg_dump(mcpdm);
	}

	return 0;
}

__attribute__((used)) static int omap_mcpdm_probe(struct snd_soc_dai *dai)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
	int ret;

	pm_runtime_enable(mcpdm->dev);

	/* Disable lines while request is ongoing */
	pm_runtime_get_sync(mcpdm->dev);
	omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, 0x00);

	ret = request_irq(mcpdm->irq, omap_mcpdm_irq_handler, 0, "McPDM",
			  (void *)mcpdm);

	pm_runtime_put_sync(mcpdm->dev);

	if (ret) {
		dev_err(mcpdm->dev, "Request for IRQ failed\n");
		pm_runtime_disable(mcpdm->dev);
	}

	/* Configure McPDM threshold values */
	mcpdm->config[SNDRV_PCM_STREAM_PLAYBACK].threshold = 2;
	mcpdm->config[SNDRV_PCM_STREAM_CAPTURE].threshold =
							MCPDM_UP_THRES_MAX - 3;

	snd_soc_dai_init_dma_data(dai,
				  &mcpdm->dma_data[SNDRV_PCM_STREAM_PLAYBACK],
				  &mcpdm->dma_data[SNDRV_PCM_STREAM_CAPTURE]);

	return ret;
}

__attribute__((used)) static int omap_mcpdm_remove(struct snd_soc_dai *dai)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);

	free_irq(mcpdm->irq, (void *)mcpdm);
	pm_runtime_disable(mcpdm->dev);

	if (pm_qos_request_active(&mcpdm->pm_qos_req))
		pm_qos_remove_request(&mcpdm->pm_qos_req);

	return 0;
}

void omap_mcpdm_configure_dn_offsets(struct snd_soc_pcm_runtime *rtd,
				    u8 rx1, u8 rx2)
{
	struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(rtd->cpu_dai);

	mcpdm->dn_rx_offset = MCPDM_DNOFST_RX1(rx1) | MCPDM_DNOFST_RX2(rx2);
}

__attribute__((used)) static int asoc_mcpdm_probe(struct platform_device *pdev)
{
	struct omap_mcpdm *mcpdm;
	struct resource *res;
	int ret;

	mcpdm = devm_kzalloc(&pdev->dev, sizeof(struct omap_mcpdm), GFP_KERNEL);
	if (!mcpdm)
		return -ENOMEM;

	platform_set_drvdata(pdev, mcpdm);

	mutex_init(&mcpdm->mutex);

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dma");
	if (res == NULL)
		return -ENOMEM;

	mcpdm->dma_data[0].addr = res->start + MCPDM_REG_DN_DATA;
	mcpdm->dma_data[1].addr = res->start + MCPDM_REG_UP_DATA;

	mcpdm->dma_data[0].filter_data = "dn_link";
	mcpdm->dma_data[1].filter_data = "up_link";

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mpu");
	mcpdm->io_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mcpdm->io_base))
		return PTR_ERR(mcpdm->io_base);

	mcpdm->irq = platform_get_irq(pdev, 0);
	if (mcpdm->irq < 0)
		return mcpdm->irq;

	mcpdm->dev = &pdev->dev;

	ret =  devm_snd_soc_register_component(&pdev->dev,
					       &omap_mcpdm_component,
					       &omap_mcpdm_dai, 1);
	if (ret)
		return ret;

	return sdma_pcm_platform_register(&pdev->dev, "dn_link", "up_link");
}


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
typedef  void* u32 ;
struct snd_soc_pcm_runtime {struct snd_pcm* pcm; TYPE_1__* card; int /*<<< orphan*/  cpu_dai; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {size_t stream; struct snd_soc_pcm_runtime* private_data; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int min_align; scalar_t__ dma_addr; scalar_t__ dma_bytes; scalar_t__ dma_area; } ;
struct snd_pcm_hw_params {unsigned long msbits; } ;
struct snd_pcm {int dummy; } ;
struct snd_card {int /*<<< orphan*/  dev; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct au1xpsc_audio_dmadata {scalar_t__ q_period; scalar_t__ periods; scalar_t__ curr_period; int msbits; int ddma_id; scalar_t__ pos; void* ddma_chan; scalar_t__ dma_area; scalar_t__ dma_area_s; scalar_t__ period_bytes; struct snd_pcm_substream* substream; } ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;
struct TYPE_2__ {struct snd_card* snd_card; } ;

/* Variables and functions */
 int /*<<< orphan*/  AU1XPSC_BUFFER_MIN_BYTES ; 
 int /*<<< orphan*/  DBG (char*,unsigned long,unsigned long,scalar_t__,int) ; 
 int /*<<< orphan*/  DDMA_FLAGS_IE ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int DSCR_CMD0_ALWAYS ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MSG (char*) ; 
 int /*<<< orphan*/  SNDRV_DMA_TYPE_DEV ; 
 int SNDRV_PCM_STREAM_CAPTURE ; 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 int /*<<< orphan*/  au1xpsc_pcm_hardware ; 
 int /*<<< orphan*/  au1xpsc_soc_component ; 
 void* au1xxx_dbdma_chan_alloc (int,int,void (*) (int,void*),void*) ; 
 int /*<<< orphan*/  au1xxx_dbdma_chan_free (void*) ; 
 int /*<<< orphan*/  au1xxx_dbdma_put_dest (void*,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  au1xxx_dbdma_put_source (void*,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  au1xxx_dbdma_reset (void*) ; 
 int /*<<< orphan*/  au1xxx_dbdma_ring_alloc (void*,int) ; 
 int /*<<< orphan*/  au1xxx_dbdma_set_devwidth (void*,int) ; 
 int /*<<< orphan*/  au1xxx_dbdma_start (void*) ; 
 int /*<<< orphan*/  au1xxx_dbdma_stop (void*) ; 
 int /*<<< orphan*/  bytes_to_frames (struct snd_pcm_runtime*,scalar_t__) ; 
 struct au1xpsc_audio_dmadata* devm_kcalloc (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_buffer_bytes (struct snd_pcm_hw_params*) ; 
 scalar_t__ params_period_bytes (struct snd_pcm_hw_params*) ; 
 unsigned long params_periods (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct au1xpsc_audio_dmadata*) ; 
 int /*<<< orphan*/  snd_pcm_lib_free_pages (struct snd_pcm_substream*) ; 
 int snd_pcm_lib_malloc_pages (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_lib_preallocate_pages_for_all (struct snd_pcm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_pcm_period_elapsed (struct snd_pcm_substream*) ; 
 struct au1xpsc_audio_dmadata* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int* snd_soc_dai_get_dma_data (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 struct snd_soc_component* snd_soc_rtdcom_lookup (struct snd_soc_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_set_runtime_hwparams (struct snd_pcm_substream*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void au1x_pcm_queue_tx(struct au1xpsc_audio_dmadata *cd)
{
	au1xxx_dbdma_put_source(cd->ddma_chan, cd->dma_area,
				cd->period_bytes, DDMA_FLAGS_IE);

	/* update next-to-queue period */
	++cd->q_period;
	cd->dma_area += cd->period_bytes;
	if (cd->q_period >= cd->periods) {
		cd->q_period = 0;
		cd->dma_area = cd->dma_area_s;
	}
}

__attribute__((used)) static void au1x_pcm_queue_rx(struct au1xpsc_audio_dmadata *cd)
{
	au1xxx_dbdma_put_dest(cd->ddma_chan, cd->dma_area,
			      cd->period_bytes, DDMA_FLAGS_IE);

	/* update next-to-queue period */
	++cd->q_period;
	cd->dma_area += cd->period_bytes;
	if (cd->q_period >= cd->periods) {
		cd->q_period = 0;
		cd->dma_area = cd->dma_area_s;
	}
}

__attribute__((used)) static void au1x_pcm_dmatx_cb(int irq, void *dev_id)
{
	struct au1xpsc_audio_dmadata *cd = dev_id;

	cd->pos += cd->period_bytes;
	if (++cd->curr_period >= cd->periods) {
		cd->pos = 0;
		cd->curr_period = 0;
	}
	snd_pcm_period_elapsed(cd->substream);
	au1x_pcm_queue_tx(cd);
}

__attribute__((used)) static void au1x_pcm_dmarx_cb(int irq, void *dev_id)
{
	struct au1xpsc_audio_dmadata *cd = dev_id;

	cd->pos += cd->period_bytes;
	if (++cd->curr_period >= cd->periods) {
		cd->pos = 0;
		cd->curr_period = 0;
	}
	snd_pcm_period_elapsed(cd->substream);
	au1x_pcm_queue_rx(cd);
}

__attribute__((used)) static void au1x_pcm_dbdma_free(struct au1xpsc_audio_dmadata *pcd)
{
	if (pcd->ddma_chan) {
		au1xxx_dbdma_stop(pcd->ddma_chan);
		au1xxx_dbdma_reset(pcd->ddma_chan);
		au1xxx_dbdma_chan_free(pcd->ddma_chan);
		pcd->ddma_chan = 0;
		pcd->msbits = 0;
	}
}

__attribute__((used)) static int au1x_pcm_dbdma_realloc(struct au1xpsc_audio_dmadata *pcd,
				 int stype, int msbits)
{
	/* DMA only in 8/16/32 bit widths */
	if (msbits == 24)
		msbits = 32;

	/* check current config: correct bits and descriptors allocated? */
	if ((pcd->ddma_chan) && (msbits == pcd->msbits))
		goto out;	/* all ok! */

	au1x_pcm_dbdma_free(pcd);

	if (stype == SNDRV_PCM_STREAM_CAPTURE)
		pcd->ddma_chan = au1xxx_dbdma_chan_alloc(pcd->ddma_id,
					DSCR_CMD0_ALWAYS,
					au1x_pcm_dmarx_cb, (void *)pcd);
	else
		pcd->ddma_chan = au1xxx_dbdma_chan_alloc(DSCR_CMD0_ALWAYS,
					pcd->ddma_id,
					au1x_pcm_dmatx_cb, (void *)pcd);

	if (!pcd->ddma_chan)
		return -ENOMEM;

	au1xxx_dbdma_set_devwidth(pcd->ddma_chan, msbits);
	au1xxx_dbdma_ring_alloc(pcd->ddma_chan, 2);

	pcd->msbits = msbits;

	au1xxx_dbdma_stop(pcd->ddma_chan);
	au1xxx_dbdma_reset(pcd->ddma_chan);

out:
	return 0;
}

__attribute__((used)) static inline struct au1xpsc_audio_dmadata *to_dmadata(struct snd_pcm_substream *ss)
{
	struct snd_soc_pcm_runtime *rtd = ss->private_data;
	struct snd_soc_component *component = snd_soc_rtdcom_lookup(rtd, DRV_NAME);
	struct au1xpsc_audio_dmadata *pcd = snd_soc_component_get_drvdata(component);
	return &pcd[ss->stream];
}

__attribute__((used)) static int au1xpsc_pcm_hw_params(struct snd_pcm_substream *substream,
				 struct snd_pcm_hw_params *params)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct au1xpsc_audio_dmadata *pcd;
	int stype, ret;

	ret = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
	if (ret < 0)
		goto out;

	stype = substream->stream;
	pcd = to_dmadata(substream);

	DBG("runtime->dma_area = 0x%08lx dma_addr_t = 0x%08lx dma_size = %zu "
	    "runtime->min_align %lu\n",
		(unsigned long)runtime->dma_area,
		(unsigned long)runtime->dma_addr, runtime->dma_bytes,
		runtime->min_align);

	DBG("bits %d  frags %d  frag_bytes %d  is_rx %d\n", params->msbits,
		params_periods(params), params_period_bytes(params), stype);

	ret = au1x_pcm_dbdma_realloc(pcd, stype, params->msbits);
	if (ret) {
		MSG("DDMA channel (re)alloc failed!\n");
		goto out;
	}

	pcd->substream = substream;
	pcd->period_bytes = params_period_bytes(params);
	pcd->periods = params_periods(params);
	pcd->dma_area_s = pcd->dma_area = runtime->dma_addr;
	pcd->q_period = 0;
	pcd->curr_period = 0;
	pcd->pos = 0;

	ret = 0;
out:
	return ret;
}

__attribute__((used)) static int au1xpsc_pcm_hw_free(struct snd_pcm_substream *substream)
{
	snd_pcm_lib_free_pages(substream);
	return 0;
}

__attribute__((used)) static int au1xpsc_pcm_prepare(struct snd_pcm_substream *substream)
{
	struct au1xpsc_audio_dmadata *pcd = to_dmadata(substream);

	au1xxx_dbdma_reset(pcd->ddma_chan);

	if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
		au1x_pcm_queue_rx(pcd);
		au1x_pcm_queue_rx(pcd);
	} else {
		au1x_pcm_queue_tx(pcd);
		au1x_pcm_queue_tx(pcd);
	}

	return 0;
}

__attribute__((used)) static int au1xpsc_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
	u32 c = to_dmadata(substream)->ddma_chan;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
		au1xxx_dbdma_start(c);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
		au1xxx_dbdma_stop(c);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static snd_pcm_uframes_t
au1xpsc_pcm_pointer(struct snd_pcm_substream *substream)
{
	return bytes_to_frames(substream->runtime, to_dmadata(substream)->pos);
}

__attribute__((used)) static int au1xpsc_pcm_open(struct snd_pcm_substream *substream)
{
	struct au1xpsc_audio_dmadata *pcd = to_dmadata(substream);
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	int stype = substream->stream, *dmaids;

	dmaids = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
	if (!dmaids)
		return -ENODEV;	/* whoa, has ordering changed? */

	pcd->ddma_id = dmaids[stype];

	snd_soc_set_runtime_hwparams(substream, &au1xpsc_pcm_hardware);
	return 0;
}

__attribute__((used)) static int au1xpsc_pcm_close(struct snd_pcm_substream *substream)
{
	au1x_pcm_dbdma_free(to_dmadata(substream));
	return 0;
}

__attribute__((used)) static int au1xpsc_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_card *card = rtd->card->snd_card;
	struct snd_pcm *pcm = rtd->pcm;

	snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
		card->dev, AU1XPSC_BUFFER_MIN_BYTES, (4096 * 1024) - 1);

	return 0;
}

__attribute__((used)) static int au1xpsc_pcm_drvprobe(struct platform_device *pdev)
{
	struct au1xpsc_audio_dmadata *dmadata;

	dmadata = devm_kcalloc(&pdev->dev,
			       2, sizeof(struct au1xpsc_audio_dmadata),
			       GFP_KERNEL);
	if (!dmadata)
		return -ENOMEM;

	platform_set_drvdata(pdev, dmadata);

	return devm_snd_soc_register_component(&pdev->dev,
					&au1xpsc_soc_component, NULL, 0);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_8__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {unsigned long vm_pgoff; int /*<<< orphan*/  vm_page_prot; scalar_t__ vm_start; scalar_t__ vm_end; } ;
struct snd_soc_pcm_runtime {struct snd_pcm* pcm; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai {int /*<<< orphan*/  id; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct TYPE_10__ {int /*<<< orphan*/  dev; int /*<<< orphan*/  type; } ;
struct snd_dma_buffer {size_t bytes; int /*<<< orphan*/ * area; int /*<<< orphan*/  addr; int /*<<< orphan*/ * private_data; TYPE_2__ dev; } ;
struct snd_pcm_substream {size_t stream; TYPE_4__* pcm; struct snd_dma_buffer dma_buffer; struct snd_pcm_runtime* runtime; struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_runtime {int /*<<< orphan*/  dma_addr; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_pcm {TYPE_5__* streams; } ;
struct resource {scalar_t__ start; int /*<<< orphan*/  name; } ;
struct TYPE_15__ {struct mmp_audio_platdata* platform_data; } ;
struct platform_device {TYPE_8__ dev; } ;
struct mmp_dma_data {int /*<<< orphan*/  ssp_id; struct resource* dma_res; } ;
struct mmp_audio_platdata {size_t buffer_max_playback; size_t buffer_max_capture; int /*<<< orphan*/  period_max_capture; int /*<<< orphan*/  period_max_playback; } ;
struct gen_pool {int dummy; } ;
struct dma_slave_config {int dummy; } ;
struct dma_chan {scalar_t__ chan_id; TYPE_1__* device; } ;
struct TYPE_14__ {size_t buffer_bytes_max; int /*<<< orphan*/  period_bytes_max; } ;
struct TYPE_13__ {struct snd_pcm_substream* substream; } ;
struct TYPE_12__ {TYPE_3__* card; } ;
struct TYPE_11__ {int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_NAME ; 
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_DMA ; 
 int /*<<< orphan*/  SNDRV_DMA_TYPE_DEV ; 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
 size_t SNDRV_PCM_STREAM_PLAYBACK ; 
 scalar_t__ __phys_to_pfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (TYPE_8__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int dmaengine_slave_config (struct dma_chan*,struct dma_slave_config*) ; 
 int /*<<< orphan*/ * gen_pool_dma_alloc (struct gen_pool*,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gen_pool_free (struct gen_pool*,unsigned long,size_t) ; 
 char* kasprintf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 TYPE_6__* mmp_pcm_hardware ; 
 int /*<<< orphan*/  mmp_soc_component ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,size_t) ; 
 int remap_pfn_range (struct vm_area_struct*,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 struct dma_chan* snd_dmaengine_pcm_get_chan (struct snd_pcm_substream*) ; 
 int snd_dmaengine_pcm_open_request_chan (struct snd_pcm_substream*,int (*) (struct dma_chan*,void*),struct mmp_dma_data*) ; 
 int snd_dmaengine_pcm_prepare_slave_config (struct snd_pcm_substream*,struct snd_pcm_hw_params*,struct dma_slave_config*) ; 
 int /*<<< orphan*/  snd_pcm_set_runtime_buffer (struct snd_pcm_substream*,struct snd_dma_buffer*) ; 
 struct snd_soc_component* snd_soc_rtdcom_lookup (struct snd_soc_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_set_runtime_hwparams (struct snd_pcm_substream*,TYPE_6__*) ; 
 struct gen_pool* sram_get_gpool (char*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 struct platform_device* to_platform_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mmp_pcm_hw_params(struct snd_pcm_substream *substream,
			      struct snd_pcm_hw_params *params)
{
	struct dma_chan *chan = snd_dmaengine_pcm_get_chan(substream);
	struct dma_slave_config slave_config;
	int ret;

	ret =
	    snd_dmaengine_pcm_prepare_slave_config(substream, params,
						   &slave_config);
	if (ret)
		return ret;

	ret = dmaengine_slave_config(chan, &slave_config);
	if (ret)
		return ret;

	snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);

	return 0;
}

__attribute__((used)) static bool filter(struct dma_chan *chan, void *param)
{
	struct mmp_dma_data *dma_data = param;
	bool found = false;
	char *devname;

	devname = kasprintf(GFP_KERNEL, "%s.%d", dma_data->dma_res->name,
		dma_data->ssp_id);
	if ((strcmp(dev_name(chan->device->dev), devname) == 0) &&
		(chan->chan_id == dma_data->dma_res->start)) {
		found = true;
	}

	kfree(devname);
	return found;
}

__attribute__((used)) static int mmp_pcm_open(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = snd_soc_rtdcom_lookup(rtd, DRV_NAME);
	struct platform_device *pdev = to_platform_device(component->dev);
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	struct mmp_dma_data dma_data;
	struct resource *r;

	r = platform_get_resource(pdev, IORESOURCE_DMA, substream->stream);
	if (!r)
		return -EBUSY;

	snd_soc_set_runtime_hwparams(substream,
				&mmp_pcm_hardware[substream->stream]);

	dma_data.dma_res = r;
	dma_data.ssp_id = cpu_dai->id;

	return snd_dmaengine_pcm_open_request_chan(substream, filter,
		    &dma_data);
}

__attribute__((used)) static int mmp_pcm_mmap(struct snd_pcm_substream *substream,
			 struct vm_area_struct *vma)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned long off = vma->vm_pgoff;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	return remap_pfn_range(vma, vma->vm_start,
		__phys_to_pfn(runtime->dma_addr) + off,
		vma->vm_end - vma->vm_start, vma->vm_page_prot);
}

__attribute__((used)) static void mmp_pcm_free_dma_buffers(struct snd_pcm *pcm)
{
	struct snd_pcm_substream *substream;
	struct snd_dma_buffer *buf;
	int stream;
	struct gen_pool *gpool;

	gpool = sram_get_gpool("asram");
	if (!gpool)
		return;

	for (stream = 0; stream < 2; stream++) {
		size_t size = mmp_pcm_hardware[stream].buffer_bytes_max;

		substream = pcm->streams[stream].substream;
		if (!substream)
			continue;

		buf = &substream->dma_buffer;
		if (!buf->area)
			continue;
		gen_pool_free(gpool, (unsigned long)buf->area, size);
		buf->area = NULL;
	}

}

__attribute__((used)) static int mmp_pcm_preallocate_dma_buffer(struct snd_pcm_substream *substream,
								int stream)
{
	struct snd_dma_buffer *buf = &substream->dma_buffer;
	size_t size = mmp_pcm_hardware[stream].buffer_bytes_max;
	struct gen_pool *gpool;

	buf->dev.type = SNDRV_DMA_TYPE_DEV;
	buf->dev.dev = substream->pcm->card->dev;
	buf->private_data = NULL;

	gpool = sram_get_gpool("asram");
	if (!gpool)
		return -ENOMEM;

	buf->area = gen_pool_dma_alloc(gpool, size, &buf->addr);
	if (!buf->area)
		return -ENOMEM;
	buf->bytes = size;
	return 0;
}

__attribute__((used)) static int mmp_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_pcm_substream *substream;
	struct snd_pcm *pcm = rtd->pcm;
	int ret = 0, stream;

	for (stream = 0; stream < 2; stream++) {
		substream = pcm->streams[stream].substream;

		ret = mmp_pcm_preallocate_dma_buffer(substream,	stream);
		if (ret)
			goto err;
	}

	return 0;

err:
	mmp_pcm_free_dma_buffers(pcm);
	return ret;
}

__attribute__((used)) static int mmp_pcm_probe(struct platform_device *pdev)
{
	struct mmp_audio_platdata *pdata = pdev->dev.platform_data;

	if (pdata) {
		mmp_pcm_hardware[SNDRV_PCM_STREAM_PLAYBACK].buffer_bytes_max =
						pdata->buffer_max_playback;
		mmp_pcm_hardware[SNDRV_PCM_STREAM_PLAYBACK].period_bytes_max =
						pdata->period_max_playback;
		mmp_pcm_hardware[SNDRV_PCM_STREAM_CAPTURE].buffer_bytes_max =
						pdata->buffer_max_capture;
		mmp_pcm_hardware[SNDRV_PCM_STREAM_CAPTURE].period_bytes_max =
						pdata->period_max_capture;
	}
	return devm_snd_soc_register_component(&pdev->dev, &mmp_soc_component,
					       NULL, 0);
}


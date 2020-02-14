#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct TYPE_11__ {int /*<<< orphan*/  rates; } ;
struct snd_pcm_runtime {scalar_t__ dma_addr; int /*<<< orphan*/  rate; struct cs5535audio_dma* private_data; TYPE_5__ hw; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_pcm {int /*<<< orphan*/  name; scalar_t__ info_flags; struct cs5535audio* private_data; } ;
struct snd_card {int dummy; } ;
struct snd_ac97_template {int dummy; } ;
struct snd_ac97 {int /*<<< orphan*/ * rates; } ;
struct cs5535audio_dma_desc {void* ctlreserved; void* size; void* addr; } ;
struct TYPE_9__ {int /*<<< orphan*/ * area; scalar_t__ addr; } ;
struct cs5535audio_dma {unsigned int period_bytes; unsigned int periods; scalar_t__ buf_addr; scalar_t__ buf_bytes; int pcm_open_flag; TYPE_4__* ops; struct snd_pcm_substream* substream; TYPE_2__ desc_buf; } ;
struct cs5535audio {struct snd_pcm* pcm; int /*<<< orphan*/  pci; struct cs5535audio_dma* dmas; TYPE_1__* card; struct snd_ac97* ac97; struct snd_pcm_substream* capture_substream; int /*<<< orphan*/  reg_lock; struct snd_pcm_substream* playback_substream; } ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;
struct TYPE_10__ {scalar_t__ (* read_dma_pntr ) (struct cs5535audio*) ;int /*<<< orphan*/  (* disable_dma ) (struct cs5535audio*) ;int /*<<< orphan*/  (* enable_dma ) (struct cs5535audio*) ;int /*<<< orphan*/  (* pause_dma ) (struct cs5535audio*) ;int /*<<< orphan*/  (* setup_prd ) (struct cs5535audio*,scalar_t__) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC97_PCM_FRONT_DAC_RATE ; 
 int /*<<< orphan*/  AC97_PCM_LR_ADC_RATE ; 
 size_t AC97_RATES_ADC ; 
 size_t AC97_RATES_FRONT_DAC ; 
 int /*<<< orphan*/  ACC_BM0_CMD ; 
 int /*<<< orphan*/  ACC_BM0_PNTR ; 
 int /*<<< orphan*/  ACC_BM0_PRD ; 
 int /*<<< orphan*/  ACC_BM1_CMD ; 
 int /*<<< orphan*/  ACC_BM1_PNTR ; 
 int /*<<< orphan*/  ACC_BM1_PRD ; 
 int /*<<< orphan*/  BM_CTL_EN ; 
 int /*<<< orphan*/  BM_CTL_PAUSE ; 
 scalar_t__ CS5535AUDIO_DESC_LIST_SIZE ; 
 size_t CS5535AUDIO_DMA_CAPTURE ; 
 size_t CS5535AUDIO_DMA_PLAYBACK ; 
 unsigned int CS5535AUDIO_MAX_DESCRIPTORS ; 
 int EINVAL ; 
 int ENOMEM ; 
 unsigned int PRD_EOP ; 
 unsigned int PRD_JMP ; 
 int /*<<< orphan*/  SNDRV_DMA_TYPE_DEV ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_PERIODS ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_CAPTURE ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 133 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 132 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 int /*<<< orphan*/  bytes_to_frames (struct snd_pcm_runtime*,scalar_t__) ; 
 void* cpu_to_le16 (unsigned int) ; 
 void* cpu_to_le32 (scalar_t__) ; 
 scalar_t__ cs_readl (struct cs5535audio*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cs_writeb (struct cs5535audio*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cs_writel (struct cs5535audio*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ params_buffer_bytes (struct snd_pcm_hw_params*) ; 
 unsigned int params_period_bytes (struct snd_pcm_hw_params*) ; 
 unsigned int params_periods (struct snd_pcm_hw_params*) ; 
 int snd_ac97_set_rate (struct snd_ac97*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ac97_update_power (struct snd_ac97*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_5__ snd_cs5535audio_capture ; 
 TYPE_4__ snd_cs5535audio_capture_dma_ops ; 
 int /*<<< orphan*/  snd_cs5535audio_capture_ops ; 
 TYPE_5__ snd_cs5535audio_playback ; 
 TYPE_4__ snd_cs5535audio_playback_dma_ops ; 
 int /*<<< orphan*/  snd_cs5535audio_playback_ops ; 
 scalar_t__ snd_dma_alloc_pages (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,TYPE_2__*) ; 
 int /*<<< orphan*/  snd_dma_free_pages (TYPE_2__*) ; 
 int /*<<< orphan*/  snd_dma_pci_data (int /*<<< orphan*/ ) ; 
 int snd_pcm_hw_constraint_integer (struct snd_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int snd_pcm_lib_free_pages (struct snd_pcm_substream*) ; 
 int snd_pcm_lib_malloc_pages (struct snd_pcm_substream*,scalar_t__) ; 
 int /*<<< orphan*/  snd_pcm_lib_preallocate_pages_for_all (struct snd_pcm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_pcm_limit_hw_rates (struct snd_pcm_runtime*) ; 
 int snd_pcm_new (TYPE_1__*,char*,int /*<<< orphan*/ ,int,int,struct snd_pcm**) ; 
 int /*<<< orphan*/  snd_pcm_set_ops (struct snd_pcm*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct cs5535audio* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub1 (struct cs5535audio*) ; 
 int /*<<< orphan*/  stub2 (struct cs5535audio*,scalar_t__) ; 
 int /*<<< orphan*/  stub3 (struct cs5535audio*) ; 
 int /*<<< orphan*/  stub4 (struct cs5535audio*) ; 
 int /*<<< orphan*/  stub5 (struct cs5535audio*) ; 
 int /*<<< orphan*/  stub6 (struct cs5535audio*) ; 
 int /*<<< orphan*/  stub7 (struct cs5535audio*) ; 
 int /*<<< orphan*/  stub8 (struct cs5535audio*) ; 
 scalar_t__ stub9 (struct cs5535audio*) ; 

__attribute__((used)) static inline void olpc_prequirks(struct snd_card *card,
		struct snd_ac97_template *ac97) { }

__attribute__((used)) static inline int olpc_quirks(struct snd_card *card, struct snd_ac97 *ac97)
{
	return 0;
}

__attribute__((used)) static inline void olpc_quirks_cleanup(void) { }

__attribute__((used)) static inline void olpc_analog_input(struct snd_ac97 *ac97, int on) { }

__attribute__((used)) static inline void olpc_mic_bias(struct snd_ac97 *ac97, int on) { }

__attribute__((used)) static inline void olpc_capture_open(struct snd_ac97 *ac97) { }

__attribute__((used)) static inline void olpc_capture_close(struct snd_ac97 *ac97) { }

__attribute__((used)) static int snd_cs5535audio_playback_open(struct snd_pcm_substream *substream)
{
	int err;
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;

	runtime->hw = snd_cs5535audio_playback;
	runtime->hw.rates = cs5535au->ac97->rates[AC97_RATES_FRONT_DAC];
	snd_pcm_limit_hw_rates(runtime);
	cs5535au->playback_substream = substream;
	runtime->private_data = &(cs5535au->dmas[CS5535AUDIO_DMA_PLAYBACK]);
	if ((err = snd_pcm_hw_constraint_integer(runtime,
				SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
		return err;

	return 0;
}

__attribute__((used)) static int snd_cs5535audio_playback_close(struct snd_pcm_substream *substream)
{
	return 0;
}

__attribute__((used)) static int cs5535audio_build_dma_packets(struct cs5535audio *cs5535au,
					 struct cs5535audio_dma *dma,
					 struct snd_pcm_substream *substream,
					 unsigned int periods,
					 unsigned int period_bytes)
{
	unsigned int i;
	u32 addr, desc_addr, jmpprd_addr;
	struct cs5535audio_dma_desc *lastdesc;

	if (periods > CS5535AUDIO_MAX_DESCRIPTORS)
		return -ENOMEM;

	if (dma->desc_buf.area == NULL) {
		if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
					snd_dma_pci_data(cs5535au->pci),
					CS5535AUDIO_DESC_LIST_SIZE+1,
					&dma->desc_buf) < 0)
			return -ENOMEM;
		dma->period_bytes = dma->periods = 0;
	}

	if (dma->periods == periods && dma->period_bytes == period_bytes)
		return 0;

	/* the u32 cast is okay because in snd*create we successfully told
   	   pci alloc that we're only 32 bit capable so the uppper will be 0 */
	addr = (u32) substream->runtime->dma_addr;
	desc_addr = (u32) dma->desc_buf.addr;
	for (i = 0; i < periods; i++) {
		struct cs5535audio_dma_desc *desc =
			&((struct cs5535audio_dma_desc *) dma->desc_buf.area)[i];
		desc->addr = cpu_to_le32(addr);
		desc->size = cpu_to_le16(period_bytes);
		desc->ctlreserved = cpu_to_le16(PRD_EOP);
		desc_addr += sizeof(struct cs5535audio_dma_desc);
		addr += period_bytes;
	}
	/* we reserved one dummy descriptor at the end to do the PRD jump */
	lastdesc = &((struct cs5535audio_dma_desc *) dma->desc_buf.area)[periods];
	lastdesc->addr = cpu_to_le32((u32) dma->desc_buf.addr);
	lastdesc->size = 0;
	lastdesc->ctlreserved = cpu_to_le16(PRD_JMP);
	jmpprd_addr = (u32)dma->desc_buf.addr +
		sizeof(struct cs5535audio_dma_desc) * periods;

	dma->substream = substream;
	dma->period_bytes = period_bytes;
	dma->periods = periods;
	spin_lock_irq(&cs5535au->reg_lock);
	dma->ops->disable_dma(cs5535au);
	dma->ops->setup_prd(cs5535au, jmpprd_addr);
	spin_unlock_irq(&cs5535au->reg_lock);
	return 0;
}

__attribute__((used)) static void cs5535audio_playback_enable_dma(struct cs5535audio *cs5535au)
{
	cs_writeb(cs5535au, ACC_BM0_CMD, BM_CTL_EN);
}

__attribute__((used)) static void cs5535audio_playback_disable_dma(struct cs5535audio *cs5535au)
{
	cs_writeb(cs5535au, ACC_BM0_CMD, 0);
}

__attribute__((used)) static void cs5535audio_playback_pause_dma(struct cs5535audio *cs5535au)
{
	cs_writeb(cs5535au, ACC_BM0_CMD, BM_CTL_PAUSE);
}

__attribute__((used)) static void cs5535audio_playback_setup_prd(struct cs5535audio *cs5535au,
					   u32 prd_addr)
{
	cs_writel(cs5535au, ACC_BM0_PRD, prd_addr);
}

__attribute__((used)) static u32 cs5535audio_playback_read_prd(struct cs5535audio *cs5535au)
{
	return cs_readl(cs5535au, ACC_BM0_PRD);
}

__attribute__((used)) static u32 cs5535audio_playback_read_dma_pntr(struct cs5535audio *cs5535au)
{
	return cs_readl(cs5535au, ACC_BM0_PNTR);
}

__attribute__((used)) static void cs5535audio_capture_enable_dma(struct cs5535audio *cs5535au)
{
	cs_writeb(cs5535au, ACC_BM1_CMD, BM_CTL_EN);
}

__attribute__((used)) static void cs5535audio_capture_disable_dma(struct cs5535audio *cs5535au)
{
	cs_writeb(cs5535au, ACC_BM1_CMD, 0);
}

__attribute__((used)) static void cs5535audio_capture_pause_dma(struct cs5535audio *cs5535au)
{
	cs_writeb(cs5535au, ACC_BM1_CMD, BM_CTL_PAUSE);
}

__attribute__((used)) static void cs5535audio_capture_setup_prd(struct cs5535audio *cs5535au,
					  u32 prd_addr)
{
	cs_writel(cs5535au, ACC_BM1_PRD, prd_addr);
}

__attribute__((used)) static u32 cs5535audio_capture_read_prd(struct cs5535audio *cs5535au)
{
	return cs_readl(cs5535au, ACC_BM1_PRD);
}

__attribute__((used)) static u32 cs5535audio_capture_read_dma_pntr(struct cs5535audio *cs5535au)
{
	return cs_readl(cs5535au, ACC_BM1_PNTR);
}

__attribute__((used)) static void cs5535audio_clear_dma_packets(struct cs5535audio *cs5535au,
					  struct cs5535audio_dma *dma,
					  struct snd_pcm_substream *substream)
{
	snd_dma_free_pages(&dma->desc_buf);
	dma->desc_buf.area = NULL;
	dma->substream = NULL;
}

__attribute__((used)) static int snd_cs5535audio_hw_params(struct snd_pcm_substream *substream,
				     struct snd_pcm_hw_params *hw_params)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	struct cs5535audio_dma *dma = substream->runtime->private_data;
	int err;

	err = snd_pcm_lib_malloc_pages(substream,
					params_buffer_bytes(hw_params));
	if (err < 0)
		return err;
	dma->buf_addr = substream->runtime->dma_addr;
	dma->buf_bytes = params_buffer_bytes(hw_params);

	err = cs5535audio_build_dma_packets(cs5535au, dma, substream,
					    params_periods(hw_params),
					    params_period_bytes(hw_params));
	if (!err)
		dma->pcm_open_flag = 1;

	return err;
}

__attribute__((used)) static int snd_cs5535audio_hw_free(struct snd_pcm_substream *substream)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	struct cs5535audio_dma *dma = substream->runtime->private_data;

	if (dma->pcm_open_flag) {
		if (substream == cs5535au->playback_substream)
			snd_ac97_update_power(cs5535au->ac97,
					AC97_PCM_FRONT_DAC_RATE, 0);
		else
			snd_ac97_update_power(cs5535au->ac97,
					AC97_PCM_LR_ADC_RATE, 0);
		dma->pcm_open_flag = 0;
	}
	cs5535audio_clear_dma_packets(cs5535au, dma, substream);
	return snd_pcm_lib_free_pages(substream);
}

__attribute__((used)) static int snd_cs5535audio_playback_prepare(struct snd_pcm_substream *substream)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	return snd_ac97_set_rate(cs5535au->ac97, AC97_PCM_FRONT_DAC_RATE,
				 substream->runtime->rate);
}

__attribute__((used)) static int snd_cs5535audio_trigger(struct snd_pcm_substream *substream, int cmd)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	struct cs5535audio_dma *dma = substream->runtime->private_data;
	int err = 0;

	spin_lock(&cs5535au->reg_lock);
	switch (cmd) {
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		dma->ops->pause_dma(cs5535au);
		break;
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
		dma->ops->enable_dma(cs5535au);
		break;
	case SNDRV_PCM_TRIGGER_START:
		dma->ops->enable_dma(cs5535au);
		break;
	case SNDRV_PCM_TRIGGER_RESUME:
		dma->ops->enable_dma(cs5535au);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
		dma->ops->disable_dma(cs5535au);
		break;
	case SNDRV_PCM_TRIGGER_SUSPEND:
		dma->ops->disable_dma(cs5535au);
		break;
	default:
		dev_err(cs5535au->card->dev, "unhandled trigger\n");
		err = -EINVAL;
		break;
	}
	spin_unlock(&cs5535au->reg_lock);
	return err;
}

__attribute__((used)) static snd_pcm_uframes_t snd_cs5535audio_pcm_pointer(struct snd_pcm_substream
							*substream)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	u32 curdma;
	struct cs5535audio_dma *dma;

	dma = substream->runtime->private_data;
	curdma = dma->ops->read_dma_pntr(cs5535au);
	if (curdma < dma->buf_addr) {
		dev_err(cs5535au->card->dev, "curdma=%x < %x bufaddr.\n",
					curdma, dma->buf_addr);
		return 0;
	}
	curdma -= dma->buf_addr;
	if (curdma >= dma->buf_bytes) {
		dev_err(cs5535au->card->dev, "diff=%x >= %x buf_bytes.\n",
					curdma, dma->buf_bytes);
		return 0;
	}
	return bytes_to_frames(substream->runtime, curdma);
}

__attribute__((used)) static int snd_cs5535audio_capture_open(struct snd_pcm_substream *substream)
{
	int err;
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;

	runtime->hw = snd_cs5535audio_capture;
	runtime->hw.rates = cs5535au->ac97->rates[AC97_RATES_ADC];
	snd_pcm_limit_hw_rates(runtime);
	cs5535au->capture_substream = substream;
	runtime->private_data = &(cs5535au->dmas[CS5535AUDIO_DMA_CAPTURE]);
	if ((err = snd_pcm_hw_constraint_integer(runtime,
					 SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
		return err;
	olpc_capture_open(cs5535au->ac97);
	return 0;
}

__attribute__((used)) static int snd_cs5535audio_capture_close(struct snd_pcm_substream *substream)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	olpc_capture_close(cs5535au->ac97);
	return 0;
}

__attribute__((used)) static int snd_cs5535audio_capture_prepare(struct snd_pcm_substream *substream)
{
	struct cs5535audio *cs5535au = snd_pcm_substream_chip(substream);
	return snd_ac97_set_rate(cs5535au->ac97, AC97_PCM_LR_ADC_RATE,
				 substream->runtime->rate);
}

int snd_cs5535audio_pcm(struct cs5535audio *cs5535au)
{
	struct snd_pcm *pcm;
	int err;

	err = snd_pcm_new(cs5535au->card, "CS5535 Audio", 0, 1, 1, &pcm);
	if (err < 0)
		return err;

	cs5535au->dmas[CS5535AUDIO_DMA_PLAYBACK].ops =
					&snd_cs5535audio_playback_dma_ops;
	cs5535au->dmas[CS5535AUDIO_DMA_CAPTURE].ops =
					&snd_cs5535audio_capture_dma_ops;
	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
					&snd_cs5535audio_playback_ops);
	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
					&snd_cs5535audio_capture_ops);

	pcm->private_data = cs5535au;
	pcm->info_flags = 0;
	strcpy(pcm->name, "CS5535 Audio");

	snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
					snd_dma_pci_data(cs5535au->pci),
					64*1024, 128*1024);
	cs5535au->pcm = pcm;

	return 0;
}


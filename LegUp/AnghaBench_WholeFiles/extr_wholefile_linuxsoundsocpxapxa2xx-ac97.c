#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_dmaengine_dai_dma_data {int dummy; } ;
struct snd_ac97 {int /*<<< orphan*/  num; } ;
struct platform_device {int id; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int ENXIO ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  pxa2xx_ac97_finish_reset () ; 
 int pxa2xx_ac97_hw_probe (struct platform_device*) ; 
 int /*<<< orphan*/  pxa2xx_ac97_hw_remove (struct platform_device*) ; 
 int /*<<< orphan*/  pxa2xx_ac97_ops ; 
 struct snd_dmaengine_dai_dma_data pxa2xx_ac97_pcm_aux_mono_in ; 
 struct snd_dmaengine_dai_dma_data pxa2xx_ac97_pcm_aux_mono_out ; 
 struct snd_dmaengine_dai_dma_data pxa2xx_ac97_pcm_mic_mono_in ; 
 struct snd_dmaengine_dai_dma_data pxa2xx_ac97_pcm_stereo_in ; 
 struct snd_dmaengine_dai_dma_data pxa2xx_ac97_pcm_stereo_out ; 
 int pxa2xx_ac97_read (int /*<<< orphan*/ ,unsigned short) ; 
 int /*<<< orphan*/  pxa2xx_ac97_try_cold_reset () ; 
 int /*<<< orphan*/  pxa2xx_ac97_try_warm_reset () ; 
 int pxa2xx_ac97_write (int /*<<< orphan*/ ,unsigned short,unsigned short) ; 
 int /*<<< orphan*/  pxa_ac97_component ; 
 int /*<<< orphan*/  pxa_ac97_dai_driver ; 
 int /*<<< orphan*/  snd_soc_dai_set_dma_data (struct snd_soc_dai*,struct snd_pcm_substream*,struct snd_dmaengine_dai_dma_data*) ; 
 int snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_set_ac97_ops (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void pxa2xx_ac97_warm_reset(struct snd_ac97 *ac97)
{
	pxa2xx_ac97_try_warm_reset();

	pxa2xx_ac97_finish_reset();
}

__attribute__((used)) static void pxa2xx_ac97_cold_reset(struct snd_ac97 *ac97)
{
	pxa2xx_ac97_try_cold_reset();

	pxa2xx_ac97_finish_reset();
}

__attribute__((used)) static unsigned short pxa2xx_ac97_legacy_read(struct snd_ac97 *ac97,
					      unsigned short reg)
{
	int ret;

	ret = pxa2xx_ac97_read(ac97->num, reg);
	if (ret < 0)
		return 0;
	else
		return (unsigned short)(ret & 0xffff);
}

__attribute__((used)) static void pxa2xx_ac97_legacy_write(struct snd_ac97 *ac97,
				     unsigned short reg, unsigned short val)
{
	int ret;

	ret = pxa2xx_ac97_write(ac97->num, reg, val);
}

__attribute__((used)) static int pxa2xx_ac97_hifi_startup(struct snd_pcm_substream *substream,
				    struct snd_soc_dai *cpu_dai)
{
	struct snd_dmaengine_dai_dma_data *dma_data;

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		dma_data = &pxa2xx_ac97_pcm_stereo_out;
	else
		dma_data = &pxa2xx_ac97_pcm_stereo_in;

	snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);

	return 0;
}

__attribute__((used)) static int pxa2xx_ac97_aux_startup(struct snd_pcm_substream *substream,
				   struct snd_soc_dai *cpu_dai)
{
	struct snd_dmaengine_dai_dma_data *dma_data;

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		dma_data = &pxa2xx_ac97_pcm_aux_mono_out;
	else
		dma_data = &pxa2xx_ac97_pcm_aux_mono_in;

	snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);

	return 0;
}

__attribute__((used)) static int pxa2xx_ac97_mic_startup(struct snd_pcm_substream *substream,
				   struct snd_soc_dai *cpu_dai)
{
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		return -ENODEV;
	snd_soc_dai_set_dma_data(cpu_dai, substream,
				 &pxa2xx_ac97_pcm_mic_mono_in);

	return 0;
}

__attribute__((used)) static int pxa2xx_ac97_dev_probe(struct platform_device *pdev)
{
	int ret;

	if (pdev->id != -1) {
		dev_err(&pdev->dev, "PXA2xx has only one AC97 port.\n");
		return -ENXIO;
	}

	ret = pxa2xx_ac97_hw_probe(pdev);
	if (ret) {
		dev_err(&pdev->dev, "PXA2xx AC97 hw probe error (%d)\n", ret);
		return ret;
	}

	ret = snd_soc_set_ac97_ops(&pxa2xx_ac97_ops);
	if (ret != 0)
		return ret;

	/* Punt most of the init to the SoC probe; we may need the machine
	 * driver to do interesting things with the clocking to get us up
	 * and running.
	 */
	return snd_soc_register_component(&pdev->dev, &pxa_ac97_component,
					  pxa_ac97_dai_driver, ARRAY_SIZE(pxa_ac97_dai_driver));
}

__attribute__((used)) static int pxa2xx_ac97_dev_remove(struct platform_device *pdev)
{
	snd_soc_unregister_component(&pdev->dev);
	snd_soc_set_ac97_ops(NULL);
	pxa2xx_ac97_hw_remove(pdev);
	return 0;
}


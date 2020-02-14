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
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {TYPE_2__* card; } ;
struct snd_pcm_substream {scalar_t__ stream; TYPE_1__* runtime; } ;
struct snd_ac97_template {int dummy; } ;
struct snd_ac97_bus {int dummy; } ;
struct snd_ac97 {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  snd_card; } ;
struct TYPE_3__ {int /*<<< orphan*/  rate; } ;

/* Variables and functions */
 int AC97_PCM_FRONT_DAC_RATE ; 
 int AC97_PCM_LR_ADC_RATE ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  ac97_dai ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct snd_ac97_template*,int /*<<< orphan*/ ,int) ; 
 int snd_ac97_bus (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct snd_ac97_bus**) ; 
 int snd_ac97_mixer (struct snd_ac97_bus*,struct snd_ac97_template*,struct snd_ac97**) ; 
 int snd_ac97_set_rate (struct snd_ac97*,int,int /*<<< orphan*/ ) ; 
 struct snd_ac97* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_set_drvdata (struct snd_soc_component*,struct snd_ac97*) ; 
 int /*<<< orphan*/  soc_ac97_ops ; 
 int /*<<< orphan*/  soc_component_dev_ac97 ; 

__attribute__((used)) static int ac97_prepare(struct snd_pcm_substream *substream,
			struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct snd_ac97 *ac97 = snd_soc_component_get_drvdata(component);

	int reg = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ?
		  AC97_PCM_FRONT_DAC_RATE : AC97_PCM_LR_ADC_RATE;
	return snd_ac97_set_rate(ac97, reg, substream->runtime->rate);
}

__attribute__((used)) static int ac97_soc_probe(struct snd_soc_component *component)
{
	struct snd_ac97 *ac97;
	struct snd_ac97_bus *ac97_bus;
	struct snd_ac97_template ac97_template;
	int ret;

	/* add codec as bus device for standard ac97 */
	ret = snd_ac97_bus(component->card->snd_card, 0, soc_ac97_ops,
			   NULL, &ac97_bus);
	if (ret < 0)
		return ret;

	memset(&ac97_template, 0, sizeof(struct snd_ac97_template));
	ret = snd_ac97_mixer(ac97_bus, &ac97_template, &ac97);
	if (ret < 0)
		return ret;

	snd_soc_component_set_drvdata(component, ac97);

	return 0;
}

__attribute__((used)) static int ac97_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
			&soc_component_dev_ac97, &ac97_dai, 1);
}

__attribute__((used)) static int ac97_remove(struct platform_device *pdev)
{
	return 0;
}


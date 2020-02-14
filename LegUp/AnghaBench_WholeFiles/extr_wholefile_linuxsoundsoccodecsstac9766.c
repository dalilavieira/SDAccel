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
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {scalar_t__ stream; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int rate; } ;
struct snd_ac97 {int dummy; } ;
typedef  struct snd_ac97 regmap ;
struct platform_device {int /*<<< orphan*/  dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  AC97_EXTENDED_STATUS ; 
 unsigned short AC97_PCM_FRONT_DAC_RATE ; 
 unsigned short AC97_PCM_LR_ADC_RATE ; 
 unsigned short AC97_POWERDOWN ; 
 unsigned short AC97_SPDIF ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct snd_ac97*) ; 
 int PTR_ERR (struct snd_ac97*) ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int /*<<< orphan*/  STAC9766_VENDOR_ID ; 
 int /*<<< orphan*/  STAC9766_VENDOR_ID_MASK ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_ac97* regmap_init_ac97 (struct snd_ac97*,int /*<<< orphan*/ *) ; 
 int snd_ac97_reset (struct snd_ac97*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_exit_regmap (struct snd_soc_component*) ; 
 struct snd_ac97* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,struct snd_ac97*) ; 
 int /*<<< orphan*/  snd_soc_component_set_drvdata (struct snd_soc_component*,struct snd_ac97*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,unsigned short,int) ; 
 int /*<<< orphan*/  snd_soc_free_ac97_component (struct snd_ac97*) ; 
 struct snd_ac97* snd_soc_new_ac97_component (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_stac9766 ; 
 int /*<<< orphan*/  stac9766_dai ; 
 int /*<<< orphan*/  stac9766_regmap_config ; 

__attribute__((used)) static int ac97_analog_prepare(struct snd_pcm_substream *substream,
			       struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned short reg;

	/* enable variable rate audio, disable SPDIF output */
	snd_soc_component_update_bits(component, AC97_EXTENDED_STATUS, 0x5, 0x1);

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = AC97_PCM_FRONT_DAC_RATE;
	else
		reg = AC97_PCM_LR_ADC_RATE;

	return snd_soc_component_write(component, reg, runtime->rate);
}

__attribute__((used)) static int ac97_digital_prepare(struct snd_pcm_substream *substream,
				struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned short reg;

	snd_soc_component_write(component, AC97_SPDIF, 0x2002);

	/* Enable VRA and SPDIF out */
	snd_soc_component_update_bits(component, AC97_EXTENDED_STATUS, 0x5, 0x5);

	reg = AC97_PCM_FRONT_DAC_RATE;

	return snd_soc_component_write(component, reg, runtime->rate);
}

__attribute__((used)) static int stac9766_set_bias_level(struct snd_soc_component *component,
				   enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON: /* full On */
	case SND_SOC_BIAS_PREPARE: /* partial On */
	case SND_SOC_BIAS_STANDBY: /* Off, with power */
		snd_soc_component_write(component, AC97_POWERDOWN, 0x0000);
		break;
	case SND_SOC_BIAS_OFF: /* Off, without power */
		/* disable everything including AC link */
		snd_soc_component_write(component, AC97_POWERDOWN, 0xffff);
		break;
	}
	return 0;
}

__attribute__((used)) static int stac9766_component_resume(struct snd_soc_component *component)
{
	struct snd_ac97 *ac97 = snd_soc_component_get_drvdata(component);

	return snd_ac97_reset(ac97, true, STAC9766_VENDOR_ID,
		STAC9766_VENDOR_ID_MASK);
}

__attribute__((used)) static int stac9766_component_probe(struct snd_soc_component *component)
{
	struct snd_ac97 *ac97;
	struct regmap *regmap;
	int ret;

	ac97 = snd_soc_new_ac97_component(component, STAC9766_VENDOR_ID,
			STAC9766_VENDOR_ID_MASK);
	if (IS_ERR(ac97))
		return PTR_ERR(ac97);

	regmap = regmap_init_ac97(ac97, &stac9766_regmap_config);
	if (IS_ERR(regmap)) {
		ret = PTR_ERR(regmap);
		goto err_free_ac97;
	}

	snd_soc_component_init_regmap(component, regmap);
	snd_soc_component_set_drvdata(component, ac97);

	return 0;
err_free_ac97:
	snd_soc_free_ac97_component(ac97);
	return ret;
}

__attribute__((used)) static void stac9766_component_remove(struct snd_soc_component *component)
{
	struct snd_ac97 *ac97 = snd_soc_component_get_drvdata(component);

	snd_soc_component_exit_regmap(component);
	snd_soc_free_ac97_component(ac97);
}

__attribute__((used)) static int stac9766_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
			&soc_component_dev_stac9766, stac9766_dai, ARRAY_SIZE(stac9766_dai));
}


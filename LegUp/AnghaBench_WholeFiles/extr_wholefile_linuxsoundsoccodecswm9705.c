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
struct wm9705_priv {TYPE_2__* mfd_pdata; int /*<<< orphan*/  ac97; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {scalar_t__ stream; TYPE_1__* runtime; } ;
struct regmap {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {struct regmap* regmap; int /*<<< orphan*/  ac97; } ;
struct TYPE_3__ {int /*<<< orphan*/  rate; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC97_EXTENDED_STATUS ; 
 int AC97_PCM_FRONT_DAC_RATE ; 
 int AC97_PCM_LR_ADC_RATE ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 TYPE_2__* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct wm9705_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm9705_priv*) ; 
 struct wm9705_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,struct regmap*) ; 
 int /*<<< orphan*/  snd_soc_component_set_drvdata (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm9705 ; 
 int /*<<< orphan*/  wm9705_dai ; 

__attribute__((used)) static int ac97_prepare(struct snd_pcm_substream *substream,
			struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	int reg;

	snd_soc_component_update_bits(component, AC97_EXTENDED_STATUS, 0x1, 0x1);

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = AC97_PCM_FRONT_DAC_RATE;
	else
		reg = AC97_PCM_LR_ADC_RATE;

	return snd_soc_component_write(component, reg, substream->runtime->rate);
}

__attribute__((used)) static int wm9705_soc_probe(struct snd_soc_component *component)
{
	struct wm9705_priv *wm9705 = snd_soc_component_get_drvdata(component);
	struct regmap *regmap;

	if (wm9705->mfd_pdata) {
		wm9705->ac97 = wm9705->mfd_pdata->ac97;
		regmap = wm9705->mfd_pdata->regmap;
	} else {
#ifdef CONFIG_SND_SOC_AC97_BUS
		wm9705->ac97 = snd_soc_new_ac97_component(component, WM9705_VENDOR_ID,
						      WM9705_VENDOR_ID_MASK);
		if (IS_ERR(wm9705->ac97)) {
			dev_err(component->dev, "Failed to register AC97 codec\n");
			return PTR_ERR(wm9705->ac97);
		}

		regmap = regmap_init_ac97(wm9705->ac97, &wm9705_regmap_config);
		if (IS_ERR(regmap)) {
			snd_soc_free_ac97_component(wm9705->ac97);
			return PTR_ERR(regmap);
		}
#endif
	}

	snd_soc_component_set_drvdata(component, wm9705->ac97);
	snd_soc_component_init_regmap(component, regmap);

	return 0;
}

__attribute__((used)) static void wm9705_soc_remove(struct snd_soc_component *component)
{
#ifdef CONFIG_SND_SOC_AC97_BUS
	struct wm9705_priv *wm9705 = snd_soc_component_get_drvdata(component);

	if (!wm9705->mfd_pdata) {
		snd_soc_component_exit_regmap(component);
		snd_soc_free_ac97_component(wm9705->ac97);
	}
#endif
}

__attribute__((used)) static int wm9705_probe(struct platform_device *pdev)
{
	struct wm9705_priv *wm9705;

	wm9705 = devm_kzalloc(&pdev->dev, sizeof(*wm9705), GFP_KERNEL);
	if (wm9705 == NULL)
		return -ENOMEM;

	wm9705->mfd_pdata = dev_get_platdata(&pdev->dev);
	platform_set_drvdata(pdev, wm9705);

	return devm_snd_soc_register_component(&pdev->dev,
			&soc_component_dev_wm9705, wm9705_dai, ARRAY_SIZE(wm9705_dai));
}


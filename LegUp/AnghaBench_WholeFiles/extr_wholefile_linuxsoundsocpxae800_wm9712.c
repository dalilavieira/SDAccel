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
struct snd_soc_dapm_widget {int dummy; } ;
struct snd_soc_card {int /*<<< orphan*/ * dev; } ;
struct snd_kcontrol {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_E800_HP_AMP_OFF ; 
 int /*<<< orphan*/  GPIO_E800_SPK_AMP_ON ; 
 int SND_SOC_DAPM_POST_PMD ; 
 int SND_SOC_DAPM_PRE_PMU ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,struct snd_soc_card*) ; 
 struct snd_soc_card e800 ; 
 int /*<<< orphan*/  e800_audio_gpios ; 
 int /*<<< orphan*/  gpio_free_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gpio_request_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int e800_spk_amp_event(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *kcontrol, int event)
{
	if (event & SND_SOC_DAPM_PRE_PMU)
		gpio_set_value(GPIO_E800_SPK_AMP_ON, 1);
	else if (event & SND_SOC_DAPM_POST_PMD)
		gpio_set_value(GPIO_E800_SPK_AMP_ON, 0);

	return 0;
}

__attribute__((used)) static int e800_hp_amp_event(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *kcontrol, int event)
{
	if (event & SND_SOC_DAPM_PRE_PMU)
		gpio_set_value(GPIO_E800_HP_AMP_OFF, 0);
	else if (event & SND_SOC_DAPM_POST_PMD)
		gpio_set_value(GPIO_E800_HP_AMP_OFF, 1);

	return 0;
}

__attribute__((used)) static int e800_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &e800;
	int ret;

	ret = gpio_request_array(e800_audio_gpios,
				 ARRAY_SIZE(e800_audio_gpios));
	if (ret)
		return ret;

	card->dev = &pdev->dev;

	ret = devm_snd_soc_register_card(&pdev->dev, card);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
			ret);
		gpio_free_array(e800_audio_gpios, ARRAY_SIZE(e800_audio_gpios));
	}
	return ret;
}

__attribute__((used)) static int e800_remove(struct platform_device *pdev)
{
	gpio_free_array(e800_audio_gpios, ARRAY_SIZE(e800_audio_gpios));
	return 0;
}


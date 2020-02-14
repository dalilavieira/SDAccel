#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {int /*<<< orphan*/  card; struct snd_soc_dai* cpu_dai; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dapm_widget {int dummy; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {int /*<<< orphan*/ * dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int /*<<< orphan*/  GPIO107_HX4700_SPK_nSD ; 
 int /*<<< orphan*/  GPIO92_HX4700_HP_DRIVER ; 
 int /*<<< orphan*/  PXA2XX_I2S_SYSCLK ; 
 int /*<<< orphan*/  SND_JACK_HEADPHONE ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_OUT ; 
 int /*<<< orphan*/  SND_SOC_DAPM_EVENT_ON (int) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  gpio_free_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gpio_request_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  hs_jack ; 
 int /*<<< orphan*/  hs_jack_gpio ; 
 int /*<<< orphan*/  hs_jack_pin ; 
 int /*<<< orphan*/  hx4700_audio_gpios ; 
 int /*<<< orphan*/  machine_is_h4700 () ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 TYPE_1__ snd_soc_card_hx4700 ; 
 int snd_soc_card_jack_new (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_soc_jack_add_gpios (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int hx4700_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	int ret = 0;

	/* set the I2S system clock as output */
	ret = snd_soc_dai_set_sysclk(cpu_dai, PXA2XX_I2S_SYSCLK, 0,
			SND_SOC_CLOCK_OUT);
	if (ret < 0)
		return ret;

	/* inform codec driver about clock freq *
	 * (PXA I2S always uses divider 256)    */
	ret = snd_soc_dai_set_sysclk(codec_dai, 0, 256 * params_rate(params),
			SND_SOC_CLOCK_IN);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int hx4700_spk_power(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *k, int event)
{
	gpio_set_value(GPIO107_HX4700_SPK_nSD, !!SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

__attribute__((used)) static int hx4700_hp_power(struct snd_soc_dapm_widget *w,
			   struct snd_kcontrol *k, int event)
{
	gpio_set_value(GPIO92_HX4700_HP_DRIVER, !!SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

__attribute__((used)) static int hx4700_ak4641_init(struct snd_soc_pcm_runtime *rtd)
{
	int err;

	/* Jack detection API stuff */
	err = snd_soc_card_jack_new(rtd->card, "Headphone Jack",
				    SND_JACK_HEADPHONE, &hs_jack, hs_jack_pin,
				    ARRAY_SIZE(hs_jack_pin));
	if (err)
		return err;

	err = snd_soc_jack_add_gpios(&hs_jack, 1, &hs_jack_gpio);

	return err;
}

__attribute__((used)) static int hx4700_audio_probe(struct platform_device *pdev)
{
	int ret;

	if (!machine_is_h4700())
		return -ENODEV;

	ret = gpio_request_array(hx4700_audio_gpios,
				ARRAY_SIZE(hx4700_audio_gpios));
	if (ret)
		return ret;

	snd_soc_card_hx4700.dev = &pdev->dev;
	ret = devm_snd_soc_register_card(&pdev->dev, &snd_soc_card_hx4700);
	if (ret)
		gpio_free_array(hx4700_audio_gpios,
				ARRAY_SIZE(hx4700_audio_gpios));

	return ret;
}

__attribute__((used)) static int hx4700_audio_remove(struct platform_device *pdev)
{
	gpio_set_value(GPIO92_HX4700_HP_DRIVER, 0);
	gpio_set_value(GPIO107_HX4700_SPK_nSD, 0);

	gpio_free_array(hx4700_audio_gpios, ARRAY_SIZE(hx4700_audio_gpios));
	return 0;
}


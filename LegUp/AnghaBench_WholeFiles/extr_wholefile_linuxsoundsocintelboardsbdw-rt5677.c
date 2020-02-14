#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct sst_pdata {struct sst_hsw* dsp; } ;
struct sst_hsw {int dummy; } ;
struct snd_soc_pcm_runtime {struct snd_soc_card* card; struct snd_soc_dai* codec_dai; int /*<<< orphan*/ * dev; } ;
struct snd_soc_dapm_widget {struct snd_soc_dapm_context* dapm; } ;
struct snd_soc_dapm_context {struct snd_soc_card* card; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/ * dev; } ;
struct snd_soc_card {int dummy; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct snd_interval {int min; int max; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct bdw_rt5677_priv {struct snd_soc_component* component; int /*<<< orphan*/  gpio_hp_en; } ;
struct TYPE_8__ {int /*<<< orphan*/ * dev; } ;
struct TYPE_7__ {int /*<<< orphan*/ * gpiod_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_NAME ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RT5677_AD_STEREO1_FILTER ; 
 int /*<<< orphan*/  RT5677_CLK_SEL_I2S1_ASRC ; 
 int RT5677_DA_STEREO_FILTER ; 
 int RT5677_I2S1_SOURCE ; 
 int /*<<< orphan*/  RT5677_SCLK_S_MCLK ; 
 int /*<<< orphan*/  SNDRV_PCM_FORMAT_S16_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int /*<<< orphan*/  SND_JACK_HEADPHONE ; 
 int /*<<< orphan*/  SND_JACK_MICROPHONE ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 scalar_t__ SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  SST_HSW_DEVICE_CLOCK_MASTER ; 
 int /*<<< orphan*/  SST_HSW_DEVICE_MCLK_FREQ_24_MHZ ; 
 int /*<<< orphan*/  SST_HSW_DEVICE_SSP_0 ; 
 TYPE_2__ bdw_rt5677_card ; 
 int /*<<< orphan*/  bdw_rt5677_gpios ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct sst_pdata* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int devm_acpi_dev_add_driver_gpios (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_gpiod_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct bdw_rt5677_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  headphone_jack ; 
 TYPE_1__ headphone_jack_gpio ; 
 int /*<<< orphan*/  headphone_jack_pin ; 
 struct snd_interval* hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mic_jack ; 
 TYPE_1__ mic_jack_gpio ; 
 int /*<<< orphan*/  mic_jack_pin ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  params_set_format (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt5677_sel_asrc_clk_src (struct snd_soc_component*,int,int /*<<< orphan*/ ) ; 
 struct bdw_rt5677_priv* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_card_jack_new (struct snd_soc_card*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (TYPE_2__*,struct bdw_rt5677_priv*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_force_enable_pin (struct snd_soc_dapm_context*,char*) ; 
 scalar_t__ snd_soc_jack_add_gpios (int /*<<< orphan*/ *,int,TYPE_1__*) ; 
 struct snd_soc_component* snd_soc_rtdcom_lookup (struct snd_soc_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int sst_hsw_device_set_config (struct sst_hsw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int bdw_rt5677_event_hp(struct snd_soc_dapm_widget *w,
			struct snd_kcontrol *k, int event)
{
	struct snd_soc_dapm_context *dapm = w->dapm;
	struct snd_soc_card *card = dapm->card;
	struct bdw_rt5677_priv *bdw_rt5677 = snd_soc_card_get_drvdata(card);

	if (SND_SOC_DAPM_EVENT_ON(event))
		msleep(70);

	gpiod_set_value_cansleep(bdw_rt5677->gpio_hp_en,
		SND_SOC_DAPM_EVENT_ON(event));

	return 0;
}

__attribute__((used)) static int broadwell_ssp0_fixup(struct snd_soc_pcm_runtime *rtd,
			struct snd_pcm_hw_params *params)
{
	struct snd_interval *rate = hw_param_interval(params,
			SNDRV_PCM_HW_PARAM_RATE);
	struct snd_interval *channels = hw_param_interval(params,
						SNDRV_PCM_HW_PARAM_CHANNELS);

	/* The ADSP will covert the FE rate to 48k, stereo */
	rate->min = rate->max = 48000;
	channels->min = channels->max = 2;

	/* set SSP0 to 16 bit */
	params_set_format(params, SNDRV_PCM_FORMAT_S16_LE);
	return 0;
}

__attribute__((used)) static int bdw_rt5677_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	int ret;

	ret = snd_soc_dai_set_sysclk(codec_dai, RT5677_SCLK_S_MCLK, 24576000,
		SND_SOC_CLOCK_IN);
	if (ret < 0) {
		dev_err(rtd->dev, "can't set codec sysclk configuration\n");
		return ret;
	}

	return ret;
}

__attribute__((used)) static int bdw_rt5677_rtd_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = snd_soc_rtdcom_lookup(rtd, DRV_NAME);
	struct sst_pdata *pdata = dev_get_platdata(component->dev);
	struct sst_hsw *broadwell = pdata->dsp;
	int ret;

	/* Set ADSP SSP port settings */
	ret = sst_hsw_device_set_config(broadwell, SST_HSW_DEVICE_SSP_0,
		SST_HSW_DEVICE_MCLK_FREQ_24_MHZ,
		SST_HSW_DEVICE_CLOCK_MASTER, 9);
	if (ret < 0) {
		dev_err(rtd->dev, "error: failed to set device config\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bdw_rt5677_init(struct snd_soc_pcm_runtime *rtd)
{
	struct bdw_rt5677_priv *bdw_rt5677 =
			snd_soc_card_get_drvdata(rtd->card);
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	int ret;

	ret = devm_acpi_dev_add_driver_gpios(component->dev, bdw_rt5677_gpios);
	if (ret)
		dev_warn(component->dev, "Failed to add driver gpios\n");

	/* Enable codec ASRC function for Stereo DAC/Stereo1 ADC/DMIC/I2S1.
	 * The ASRC clock source is clk_i2s1_asrc.
	 */
	rt5677_sel_asrc_clk_src(component, RT5677_DA_STEREO_FILTER |
			RT5677_AD_STEREO1_FILTER | RT5677_I2S1_SOURCE,
			RT5677_CLK_SEL_I2S1_ASRC);

	/* Request rt5677 GPIO for headphone amp control */
	bdw_rt5677->gpio_hp_en = devm_gpiod_get(component->dev, "headphone-enable",
						GPIOD_OUT_LOW);
	if (IS_ERR(bdw_rt5677->gpio_hp_en)) {
		dev_err(component->dev, "Can't find HP_AMP_SHDN_L gpio\n");
		return PTR_ERR(bdw_rt5677->gpio_hp_en);
	}

	/* Create and initialize headphone jack */
	if (!snd_soc_card_jack_new(rtd->card, "Headphone Jack",
			SND_JACK_HEADPHONE, &headphone_jack,
			&headphone_jack_pin, 1)) {
		headphone_jack_gpio.gpiod_dev = component->dev;
		if (snd_soc_jack_add_gpios(&headphone_jack, 1,
				&headphone_jack_gpio))
			dev_err(component->dev, "Can't add headphone jack gpio\n");
	} else {
		dev_err(component->dev, "Can't create headphone jack\n");
	}

	/* Create and initialize mic jack */
	if (!snd_soc_card_jack_new(rtd->card, "Mic Jack",
			SND_JACK_MICROPHONE, &mic_jack,
			&mic_jack_pin, 1)) {
		mic_jack_gpio.gpiod_dev = component->dev;
		if (snd_soc_jack_add_gpios(&mic_jack, 1, &mic_jack_gpio))
			dev_err(component->dev, "Can't add mic jack gpio\n");
	} else {
		dev_err(component->dev, "Can't create mic jack\n");
	}
	bdw_rt5677->component = component;

	snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
	return 0;
}

__attribute__((used)) static int bdw_rt5677_suspend_pre(struct snd_soc_card *card)
{
	struct bdw_rt5677_priv *bdw_rt5677 = snd_soc_card_get_drvdata(card);
	struct snd_soc_dapm_context *dapm;

	if (bdw_rt5677->component) {
		dapm = snd_soc_component_get_dapm(bdw_rt5677->component);
		snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
	}
	return 0;
}

__attribute__((used)) static int bdw_rt5677_resume_post(struct snd_soc_card *card)
{
	struct bdw_rt5677_priv *bdw_rt5677 = snd_soc_card_get_drvdata(card);
	struct snd_soc_dapm_context *dapm;

	if (bdw_rt5677->component) {
		dapm = snd_soc_component_get_dapm(bdw_rt5677->component);
		snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
	}
	return 0;
}

__attribute__((used)) static int bdw_rt5677_probe(struct platform_device *pdev)
{
	struct bdw_rt5677_priv *bdw_rt5677;

	bdw_rt5677_card.dev = &pdev->dev;

	/* Allocate driver private struct */
	bdw_rt5677 = devm_kzalloc(&pdev->dev, sizeof(struct bdw_rt5677_priv),
		GFP_KERNEL);
	if (!bdw_rt5677) {
		dev_err(&pdev->dev, "Can't allocate bdw_rt5677\n");
		return -ENOMEM;
	}

	snd_soc_card_set_drvdata(&bdw_rt5677_card, bdw_rt5677);

	return devm_snd_soc_register_card(&pdev->dev, &bdw_rt5677_card);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_card* card; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dapm_widget {struct snd_soc_dapm_context* dapm; } ;
struct snd_soc_dapm_context {struct snd_soc_card* card; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_card {TYPE_8__* dev; struct snd_soc_dapm_context dapm; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_14__ {int* item; } ;
struct TYPE_15__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct rx51_audio_pdata {void* speaker_amp_gpio; void* eci_sw_gpio; void* jack_detection_gpio; void* tvout_selection_gpio; } ;
struct TYPE_20__ {struct device_node* of_node; } ;
struct platform_device {TYPE_8__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_19__ {struct device_node* codec_of_node; int /*<<< orphan*/ * codec_name; } ;
struct TYPE_18__ {struct device_node* of_node; int /*<<< orphan*/ * dev_name; } ;
struct TYPE_17__ {struct device_node* codec_of_node; int /*<<< orphan*/ * codec_name; struct device_node* platform_of_node; struct device_node* cpu_of_node; int /*<<< orphan*/ * platform_name; int /*<<< orphan*/ * cpu_dai_name; } ;
struct TYPE_16__ {int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_3__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_ASIS ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
#define  RX51_JACK_HP 130 
#define  RX51_JACK_HS 129 
#define  RX51_JACK_TVOUT 128 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int SND_JACK_HEADSET ; 
 int SND_JACK_VIDEOOUT ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  desc_to_gpio (void*) ; 
 int /*<<< orphan*/  dev_err (TYPE_8__*,char*,...) ; 
 void* devm_gpiod_get (TYPE_8__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_gpiod_put (TYPE_8__*,void*) ; 
 struct rx51_audio_pdata* devm_kzalloc (TYPE_8__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (TYPE_8__*,struct snd_soc_card*) ; 
 int /*<<< orphan*/  gpiod_set_raw_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 int /*<<< orphan*/  machine_is_nokia_rx51 () ; 
 int /*<<< orphan*/  of_machine_is_compatible (char*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int) ; 
 int omap_mcbsp_st_add_controls (struct snd_soc_pcm_runtime*,int) ; 
 TYPE_7__* rx51_aux_dev ; 
 int /*<<< orphan*/  rx51_av_jack ; 
 TYPE_3__* rx51_av_jack_gpios ; 
 TYPE_5__* rx51_codec_conf ; 
 TYPE_4__* rx51_dai ; 
 scalar_t__ rx51_dmic_func ; 
 int rx51_jack_func ; 
 struct snd_soc_card rx51_sound_card ; 
 scalar_t__ rx51_spk_func ; 
 struct snd_soc_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_single (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int) ; 
 struct rx51_audio_pdata* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int snd_soc_card_jack_new (struct snd_soc_card*,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct rx51_audio_pdata*) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_enable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_lock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_unlock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_sync_unlocked (struct snd_soc_dapm_context*) ; 
 int snd_soc_jack_add_gpios (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  snd_soc_limit_volume (struct snd_soc_card*,char*,int) ; 

__attribute__((used)) static void rx51_ext_control(struct snd_soc_dapm_context *dapm)
{
	struct snd_soc_card *card = dapm->card;
	struct rx51_audio_pdata *pdata = snd_soc_card_get_drvdata(card);
	int hp = 0, hs = 0, tvout = 0;

	switch (rx51_jack_func) {
	case RX51_JACK_TVOUT:
		tvout = 1;
		hp = 1;
		break;
	case RX51_JACK_HS:
		hs = 1;
	case RX51_JACK_HP:
		hp = 1;
		break;
	}

	snd_soc_dapm_mutex_lock(dapm);

	if (rx51_spk_func)
		snd_soc_dapm_enable_pin_unlocked(dapm, "Ext Spk");
	else
		snd_soc_dapm_disable_pin_unlocked(dapm, "Ext Spk");
	if (rx51_dmic_func)
		snd_soc_dapm_enable_pin_unlocked(dapm, "DMic");
	else
		snd_soc_dapm_disable_pin_unlocked(dapm, "DMic");
	if (hp)
		snd_soc_dapm_enable_pin_unlocked(dapm, "Headphone Jack");
	else
		snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
	if (hs)
		snd_soc_dapm_enable_pin_unlocked(dapm, "HS Mic");
	else
		snd_soc_dapm_disable_pin_unlocked(dapm, "HS Mic");

	gpiod_set_value(pdata->tvout_selection_gpio, tvout);

	snd_soc_dapm_sync_unlocked(dapm);

	snd_soc_dapm_mutex_unlock(dapm);
}

__attribute__((used)) static int rx51_startup(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;

	snd_pcm_hw_constraint_single(runtime, SNDRV_PCM_HW_PARAM_CHANNELS, 2);
	rx51_ext_control(&card->dapm);

	return 0;
}

__attribute__((used)) static int rx51_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;

	/* Set the codec system clock for DAC and ADC */
	return snd_soc_dai_set_sysclk(codec_dai, 0, 19200000,
				      SND_SOC_CLOCK_IN);
}

__attribute__((used)) static int rx51_get_spk(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.enumerated.item[0] = rx51_spk_func;

	return 0;
}

__attribute__((used)) static int rx51_set_spk(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);

	if (rx51_spk_func == ucontrol->value.enumerated.item[0])
		return 0;

	rx51_spk_func = ucontrol->value.enumerated.item[0];
	rx51_ext_control(&card->dapm);

	return 1;
}

__attribute__((used)) static int rx51_spk_event(struct snd_soc_dapm_widget *w,
			  struct snd_kcontrol *k, int event)
{
	struct snd_soc_dapm_context *dapm = w->dapm;
	struct snd_soc_card *card = dapm->card;
	struct rx51_audio_pdata *pdata = snd_soc_card_get_drvdata(card);

	gpiod_set_raw_value_cansleep(pdata->speaker_amp_gpio,
				     !!SND_SOC_DAPM_EVENT_ON(event));

	return 0;
}

__attribute__((used)) static int rx51_get_input(struct snd_kcontrol *kcontrol,
			  struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.enumerated.item[0] = rx51_dmic_func;

	return 0;
}

__attribute__((used)) static int rx51_set_input(struct snd_kcontrol *kcontrol,
			  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);

	if (rx51_dmic_func == ucontrol->value.enumerated.item[0])
		return 0;

	rx51_dmic_func = ucontrol->value.enumerated.item[0];
	rx51_ext_control(&card->dapm);

	return 1;
}

__attribute__((used)) static int rx51_get_jack(struct snd_kcontrol *kcontrol,
			 struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.enumerated.item[0] = rx51_jack_func;

	return 0;
}

__attribute__((used)) static int rx51_set_jack(struct snd_kcontrol *kcontrol,
			 struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);

	if (rx51_jack_func == ucontrol->value.enumerated.item[0])
		return 0;

	rx51_jack_func = ucontrol->value.enumerated.item[0];
	rx51_ext_control(&card->dapm);

	return 1;
}

__attribute__((used)) static int rx51_aic34_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_card *card = rtd->card;
	struct rx51_audio_pdata *pdata = snd_soc_card_get_drvdata(card);
	int err;

	snd_soc_limit_volume(card, "TPA6130A2 Headphone Playback Volume", 42);

	err = omap_mcbsp_st_add_controls(rtd, 2);
	if (err < 0) {
		dev_err(card->dev, "Failed to add MCBSP controls\n");
		return err;
	}

	/* AV jack detection */
	err = snd_soc_card_jack_new(rtd->card, "AV Jack",
				    SND_JACK_HEADSET | SND_JACK_VIDEOOUT,
				    &rx51_av_jack, NULL, 0);
	if (err) {
		dev_err(card->dev, "Failed to add AV Jack\n");
		return err;
	}

	/* prepare gpio for snd_soc_jack_add_gpios */
	rx51_av_jack_gpios[0].gpio = desc_to_gpio(pdata->jack_detection_gpio);
	devm_gpiod_put(card->dev, pdata->jack_detection_gpio);

	err = snd_soc_jack_add_gpios(&rx51_av_jack,
				     ARRAY_SIZE(rx51_av_jack_gpios),
				     rx51_av_jack_gpios);
	if (err) {
		dev_err(card->dev, "Failed to add GPIOs\n");
		return err;
	}

	return err;
}

__attribute__((used)) static int rx51_soc_probe(struct platform_device *pdev)
{
	struct rx51_audio_pdata *pdata;
	struct device_node *np = pdev->dev.of_node;
	struct snd_soc_card *card = &rx51_sound_card;
	int err;

	if (!machine_is_nokia_rx51() && !of_machine_is_compatible("nokia,omap3-n900"))
		return -ENODEV;

	card->dev = &pdev->dev;

	if (np) {
		struct device_node *dai_node;

		dai_node = of_parse_phandle(np, "nokia,cpu-dai", 0);
		if (!dai_node) {
			dev_err(&pdev->dev, "McBSP node is not provided\n");
			return -EINVAL;
		}
		rx51_dai[0].cpu_dai_name = NULL;
		rx51_dai[0].platform_name = NULL;
		rx51_dai[0].cpu_of_node = dai_node;
		rx51_dai[0].platform_of_node = dai_node;

		dai_node = of_parse_phandle(np, "nokia,audio-codec", 0);
		if (!dai_node) {
			dev_err(&pdev->dev, "Codec node is not provided\n");
			return -EINVAL;
		}
		rx51_dai[0].codec_name = NULL;
		rx51_dai[0].codec_of_node = dai_node;

		dai_node = of_parse_phandle(np, "nokia,audio-codec", 1);
		if (!dai_node) {
			dev_err(&pdev->dev, "Auxiliary Codec node is not provided\n");
			return -EINVAL;
		}
		rx51_aux_dev[0].codec_name = NULL;
		rx51_aux_dev[0].codec_of_node = dai_node;
		rx51_codec_conf[0].dev_name = NULL;
		rx51_codec_conf[0].of_node = dai_node;

		dai_node = of_parse_phandle(np, "nokia,headphone-amplifier", 0);
		if (!dai_node) {
			dev_err(&pdev->dev, "Headphone amplifier node is not provided\n");
			return -EINVAL;
		}
		rx51_aux_dev[1].codec_name = NULL;
		rx51_aux_dev[1].codec_of_node = dai_node;
		rx51_codec_conf[1].dev_name = NULL;
		rx51_codec_conf[1].of_node = dai_node;
	}

	pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
	if (pdata == NULL)
		return -ENOMEM;

	snd_soc_card_set_drvdata(card, pdata);

	pdata->tvout_selection_gpio = devm_gpiod_get(card->dev,
						     "tvout-selection",
						     GPIOD_OUT_LOW);
	if (IS_ERR(pdata->tvout_selection_gpio)) {
		dev_err(card->dev, "could not get tvout selection gpio\n");
		return PTR_ERR(pdata->tvout_selection_gpio);
	}

	pdata->jack_detection_gpio = devm_gpiod_get(card->dev,
						    "jack-detection",
						    GPIOD_ASIS);
	if (IS_ERR(pdata->jack_detection_gpio)) {
		dev_err(card->dev, "could not get jack detection gpio\n");
		return PTR_ERR(pdata->jack_detection_gpio);
	}

	pdata->eci_sw_gpio = devm_gpiod_get(card->dev, "eci-switch",
					    GPIOD_OUT_HIGH);
	if (IS_ERR(pdata->eci_sw_gpio)) {
		dev_err(card->dev, "could not get eci switch gpio\n");
		return PTR_ERR(pdata->eci_sw_gpio);
	}

	pdata->speaker_amp_gpio = devm_gpiod_get(card->dev,
						 "speaker-amplifier",
						 GPIOD_OUT_LOW);
	if (IS_ERR(pdata->speaker_amp_gpio)) {
		dev_err(card->dev, "could not get speaker enable gpio\n");
		return PTR_ERR(pdata->speaker_amp_gpio);
	}

	err = devm_snd_soc_register_card(card->dev, card);
	if (err) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", err);
		return err;
	}

	return 0;
}


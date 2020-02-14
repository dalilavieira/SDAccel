#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_card* card; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_card {int num_links; int fully_routed; scalar_t__ name; TYPE_6__* dev; struct snd_soc_dapm_context dapm; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct property {int dummy; } ;
struct TYPE_13__ {struct device_node* of_node; } ;
struct platform_device {TYPE_6__ dev; } ;
struct omap_twl4030 {scalar_t__ jack_detect; int /*<<< orphan*/  hs_jack; } ;
struct omap_tw4030_pdata {int has_ear; int has_hf; int has_hs; int has_predriv; int has_carkit; int has_mainmic; int has_submic; int has_hsmic; int has_carkitmic; int has_digimic0; int has_digimic1; int has_linein; scalar_t__ jack_detect; int /*<<< orphan*/  voice_connected; scalar_t__ card_name; int /*<<< orphan*/  custom_routing; } ;
struct device_node {int dummy; } ;
struct TYPE_12__ {struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct TYPE_11__ {scalar_t__ gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SND_JACK_HEADSET ; 
 unsigned int SND_SOC_DAIFMT_CBM_CFM ; 
 unsigned int SND_SOC_DAIFMT_DSP_A ; 
 unsigned int SND_SOC_DAIFMT_I2S ; 
 unsigned int SND_SOC_DAIFMT_IB_NF ; 
 unsigned int SND_SOC_DAIFMT_NB_NF ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 struct omap_tw4030_pdata* dev_get_platdata (TYPE_6__*) ; 
 struct omap_twl4030* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (TYPE_6__*,struct snd_soc_card*) ; 
 TYPE_1__* hs_jack_gpios ; 
 TYPE_1__* hs_jack_pins ; 
 struct property* of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct snd_soc_card omap_twl4030_card ; 
 TYPE_3__* omap_twl4030_dai_links ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 struct omap_twl4030* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int snd_soc_card_jack_new (struct snd_soc_card*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct omap_twl4030*) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin (struct snd_soc_dapm_context*,char*) ; 
 int snd_soc_jack_add_gpios (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int snd_soc_of_parse_audio_routing (struct snd_soc_card*,char*) ; 
 scalar_t__ snd_soc_of_parse_card_name (struct snd_soc_card*,char*) ; 
 int snd_soc_runtime_set_dai_fmt (struct snd_soc_pcm_runtime*,unsigned int) ; 

__attribute__((used)) static int omap_twl4030_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	unsigned int fmt;

	switch (params_channels(params)) {
	case 2: /* Stereo I2S mode */
		fmt =	SND_SOC_DAIFMT_I2S |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBM_CFM;
		break;
	case 4: /* Four channel TDM mode */
		fmt =	SND_SOC_DAIFMT_DSP_A |
			SND_SOC_DAIFMT_IB_NF |
			SND_SOC_DAIFMT_CBM_CFM;
		break;
	default:
		return -EINVAL;
	}

	return snd_soc_runtime_set_dai_fmt(rtd, fmt);
}

__attribute__((used)) static inline void twl4030_disconnect_pin(struct snd_soc_dapm_context *dapm,
					  int connected, char *pin)
{
	if (!connected)
		snd_soc_dapm_disable_pin(dapm, pin);
}

__attribute__((used)) static int omap_twl4030_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_card *card = rtd->card;
	struct snd_soc_dapm_context *dapm = &card->dapm;
	struct omap_tw4030_pdata *pdata = dev_get_platdata(card->dev);
	struct omap_twl4030 *priv = snd_soc_card_get_drvdata(card);
	int ret = 0;

	/* Headset jack detection only if it is supported */
	if (priv->jack_detect > 0) {
		hs_jack_gpios[0].gpio = priv->jack_detect;

		ret = snd_soc_card_jack_new(rtd->card, "Headset Jack",
					    SND_JACK_HEADSET, &priv->hs_jack,
					    hs_jack_pins,
					    ARRAY_SIZE(hs_jack_pins));
		if (ret)
			return ret;

		ret = snd_soc_jack_add_gpios(&priv->hs_jack,
					     ARRAY_SIZE(hs_jack_gpios),
					     hs_jack_gpios);
		if (ret)
			return ret;
	}

	/*
	 * NULL pdata means we booted with DT. In this case the routing is
	 * provided and the card is fully routed, no need to mark pins.
	 */
	if (!pdata || !pdata->custom_routing)
		return ret;

	/* Disable not connected paths if not used */
	twl4030_disconnect_pin(dapm, pdata->has_ear, "Earpiece Spk");
	twl4030_disconnect_pin(dapm, pdata->has_hf, "Handsfree Spk");
	twl4030_disconnect_pin(dapm, pdata->has_hs, "Headset Stereophone");
	twl4030_disconnect_pin(dapm, pdata->has_predriv, "Ext Spk");
	twl4030_disconnect_pin(dapm, pdata->has_carkit, "Carkit Spk");

	twl4030_disconnect_pin(dapm, pdata->has_mainmic, "Main Mic");
	twl4030_disconnect_pin(dapm, pdata->has_submic, "Sub Mic");
	twl4030_disconnect_pin(dapm, pdata->has_hsmic, "Headset Mic");
	twl4030_disconnect_pin(dapm, pdata->has_carkitmic, "Carkit Mic");
	twl4030_disconnect_pin(dapm, pdata->has_digimic0, "Digital0 Mic");
	twl4030_disconnect_pin(dapm, pdata->has_digimic1, "Digital1 Mic");
	twl4030_disconnect_pin(dapm, pdata->has_linein, "Line In");

	return ret;
}

__attribute__((used)) static int omap_twl4030_probe(struct platform_device *pdev)
{
	struct omap_tw4030_pdata *pdata = dev_get_platdata(&pdev->dev);
	struct device_node *node = pdev->dev.of_node;
	struct snd_soc_card *card = &omap_twl4030_card;
	struct omap_twl4030 *priv;
	int ret = 0;

	card->dev = &pdev->dev;

	priv = devm_kzalloc(&pdev->dev, sizeof(struct omap_twl4030), GFP_KERNEL);
	if (priv == NULL)
		return -ENOMEM;

	if (node) {
		struct device_node *dai_node;
		struct property *prop;

		if (snd_soc_of_parse_card_name(card, "ti,model")) {
			dev_err(&pdev->dev, "Card name is not provided\n");
			return -ENODEV;
		}

		dai_node = of_parse_phandle(node, "ti,mcbsp", 0);
		if (!dai_node) {
			dev_err(&pdev->dev, "McBSP node is not provided\n");
			return -EINVAL;
		}
		omap_twl4030_dai_links[0].cpu_dai_name  = NULL;
		omap_twl4030_dai_links[0].cpu_of_node = dai_node;

		omap_twl4030_dai_links[0].platform_name  = NULL;
		omap_twl4030_dai_links[0].platform_of_node = dai_node;

		dai_node = of_parse_phandle(node, "ti,mcbsp-voice", 0);
		if (!dai_node) {
			card->num_links = 1;
		} else {
			omap_twl4030_dai_links[1].cpu_dai_name  = NULL;
			omap_twl4030_dai_links[1].cpu_of_node = dai_node;

			omap_twl4030_dai_links[1].platform_name  = NULL;
			omap_twl4030_dai_links[1].platform_of_node = dai_node;
		}

		priv->jack_detect = of_get_named_gpio(node,
						      "ti,jack-det-gpio", 0);

		/* Optional: audio routing can be provided */
		prop = of_find_property(node, "ti,audio-routing", NULL);
		if (prop) {
			ret = snd_soc_of_parse_audio_routing(card,
							    "ti,audio-routing");
			if (ret)
				return ret;

			card->fully_routed = 1;
		}
	} else if (pdata) {
		if (pdata->card_name) {
			card->name = pdata->card_name;
		} else {
			dev_err(&pdev->dev, "Card name is not provided\n");
			return -ENODEV;
		}

		if (!pdata->voice_connected)
			card->num_links = 1;

		priv->jack_detect = pdata->jack_detect;
	} else {
		dev_err(&pdev->dev, "Missing pdata\n");
		return -ENODEV;
	}

	snd_soc_card_set_drvdata(card, priv);
	ret = devm_snd_soc_register_card(&pdev->dev, card);
	if (ret) {
		dev_err(&pdev->dev, "devm_snd_soc_register_card() failed: %d\n",
			ret);
		return ret;
	}

	return 0;
}


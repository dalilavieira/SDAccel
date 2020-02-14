#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct tm2_machine_priv {unsigned int sysclk_rate; int /*<<< orphan*/  gpio_mic_bias; struct snd_soc_component* component; } ;
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; struct snd_soc_card* card; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dapm_widget {TYPE_1__* dapm; } ;
struct snd_soc_dapm_context {scalar_t__ dev; } ;
struct snd_soc_dai_link_component {int /*<<< orphan*/  of_node; int /*<<< orphan*/  member_0; } ;
struct snd_soc_dai {scalar_t__ dev; struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct TYPE_7__ {int bias_level; } ;
struct snd_soc_card {int num_links; TYPE_4__* aux_dev; TYPE_3__* dai_link; struct device* dev; TYPE_2__ dapm; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct of_phandle_args {struct device_node* np; } ;
struct notifier_block {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct device_node {int dummy; } ;
struct arizona_priv {struct arizona* arizona; } ;
struct arizona {int /*<<< orphan*/  notifier; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_10__ {int /*<<< orphan*/  codec_of_node; } ;
struct TYPE_9__ {struct device_node* codec_of_node; } ;
struct TYPE_8__ {int /*<<< orphan*/  codec_dai_name; struct device_node* platform_of_node; struct device_node* cpu_of_node; struct device_node* codec_of_node; int /*<<< orphan*/ * platform_name; int /*<<< orphan*/ * cpu_name; int /*<<< orphan*/  name; } ;
struct TYPE_6__ {struct snd_soc_card* card; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARIZONA_CLK_ASYNCCLK ; 
 int /*<<< orphan*/  ARIZONA_CLK_SRC_FLL1 ; 
 int /*<<< orphan*/  ARIZONA_CLK_SRC_FLL2 ; 
 int /*<<< orphan*/  ARIZONA_CLK_SYSCLK ; 
 int /*<<< orphan*/  ARIZONA_FLL_SRC_MCLK1 ; 
 void* ARRAY_SIZE (unsigned int*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MCLK_RATE ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SAMSUNG_I2S_DIV_BCLK ; 
 int /*<<< orphan*/  SAMSUNG_I2S_OPCLK ; 
 int /*<<< orphan*/  SAMSUNG_I2S_OPCLK_PCLK ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_STANDBY 130 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
#define  SND_SOC_DAPM_POST_PMD 129 
#define  SND_SOC_DAPM_PRE_PMU 128 
 size_t TM2_DAI_AIF1 ; 
 size_t TM2_DAI_AIF2 ; 
 int /*<<< orphan*/  WM5110_FLL1 ; 
 int /*<<< orphan*/  WM5110_FLL1_REFCLK ; 
 int /*<<< orphan*/  WM5110_FLL2 ; 
 int /*<<< orphan*/  WM5110_FLL2_REFCLK ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct snd_soc_card* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct tm2_machine_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (struct device*,struct snd_soc_card*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,unsigned int*,void*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 int of_count_phandle_with_args (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 void* of_parse_phandle (int /*<<< orphan*/ ,char*,int) ; 
 int of_parse_phandle_with_args (int /*<<< orphan*/ ,char*,char const*,int,struct of_phandle_args*) ; 
 int of_parse_phandle_with_fixed_args (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int,struct of_phandle_args*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 struct tm2_machine_priv* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct tm2_machine_priv*) ; 
 struct arizona_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_set_pll (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_soc_component_set_sysclk (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_channel_map (struct snd_soc_dai*,void*,unsigned int*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_soc_dai_set_clkdiv (struct snd_soc_dai*,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int,int,int,int) ; 
 struct snd_soc_dai* snd_soc_find_dai (struct snd_soc_dai_link_component*) ; 
 int snd_soc_get_dai_name (struct of_phandle_args*,int /*<<< orphan*/ *) ; 
 struct snd_soc_pcm_runtime* snd_soc_get_pcm_runtime (struct snd_soc_card*,int /*<<< orphan*/ ) ; 
 int snd_soc_of_parse_audio_routing (struct snd_soc_card*,char*) ; 
 int snd_soc_of_parse_card_name (struct snd_soc_card*,char*) ; 
 struct snd_soc_card tm2_card ; 
 int /*<<< orphan*/  tm2_component ; 
 unsigned int* tm2_dai_links ; 
 unsigned int* tm2_ext_dai ; 
 TYPE_5__ tm2_speaker_amp_dev ; 

__attribute__((used)) static inline int arizona_register_notifier(struct snd_soc_component *component,
					    struct notifier_block *nb,
					    int (*notify)
					    (struct notifier_block *nb,
					    unsigned long action, void *data))
{
	struct arizona_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->arizona;

	nb->notifier_call = notify;

	return blocking_notifier_chain_register(&arizona->notifier, nb);
}

__attribute__((used)) static inline int arizona_unregister_notifier(struct snd_soc_component *component,
					      struct notifier_block *nb)
{
	struct arizona_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->arizona;

	return blocking_notifier_chain_unregister(&arizona->notifier, nb);
}

__attribute__((used)) static int tm2_start_sysclk(struct snd_soc_card *card)
{
	struct tm2_machine_priv *priv = snd_soc_card_get_drvdata(card);
	struct snd_soc_component *component = priv->component;
	int ret;

	ret = snd_soc_component_set_pll(component, WM5110_FLL1_REFCLK,
				    ARIZONA_FLL_SRC_MCLK1,
				    MCLK_RATE,
				    priv->sysclk_rate);
	if (ret < 0) {
		dev_err(component->dev, "Failed to set FLL1 source: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_pll(component, WM5110_FLL1,
				    ARIZONA_FLL_SRC_MCLK1,
				    MCLK_RATE,
				    priv->sysclk_rate);
	if (ret < 0) {
		dev_err(component->dev, "Failed to start FLL1: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_sysclk(component, ARIZONA_CLK_SYSCLK,
				       ARIZONA_CLK_SRC_FLL1,
				       priv->sysclk_rate,
				       SND_SOC_CLOCK_IN);
	if (ret < 0) {
		dev_err(component->dev, "Failed to set SYSCLK source: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int tm2_stop_sysclk(struct snd_soc_card *card)
{
	struct tm2_machine_priv *priv = snd_soc_card_get_drvdata(card);
	struct snd_soc_component *component = priv->component;
	int ret;

	ret = snd_soc_component_set_pll(component, WM5110_FLL1, 0, 0, 0);
	if (ret < 0) {
		dev_err(component->dev, "Failed to stop FLL1: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_sysclk(component, ARIZONA_CLK_SYSCLK,
				       ARIZONA_CLK_SRC_FLL1, 0, 0);
	if (ret < 0) {
		dev_err(component->dev, "Failed to stop SYSCLK: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int tm2_aif1_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct tm2_machine_priv *priv = snd_soc_card_get_drvdata(rtd->card);

	switch (params_rate(params)) {
	case 4000:
	case 8000:
	case 12000:
	case 16000:
	case 24000:
	case 32000:
	case 48000:
	case 96000:
	case 192000:
		/* Highest possible SYSCLK frequency: 147.456MHz */
		priv->sysclk_rate = 147456000U;
		break;
	case 11025:
	case 22050:
	case 44100:
	case 88200:
	case 176400:
		/* Highest possible SYSCLK frequency: 135.4752 MHz */
		priv->sysclk_rate = 135475200U;
		break;
	default:
		dev_err(component->dev, "Not supported sample rate: %d\n",
			params_rate(params));
		return -EINVAL;
	}

	return tm2_start_sysclk(rtd->card);
}

__attribute__((used)) static int tm2_aif2_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;
	unsigned int asyncclk_rate;
	int ret;

	switch (params_rate(params)) {
	case 8000:
	case 12000:
	case 16000:
		/* Highest possible ASYNCCLK frequency: 49.152MHz */
		asyncclk_rate = 49152000U;
		break;
	case 11025:
		/* Highest possible ASYNCCLK frequency: 45.1584 MHz */
		asyncclk_rate = 45158400U;
		break;
	default:
		dev_err(component->dev, "Not supported sample rate: %d\n",
			params_rate(params));
		return -EINVAL;
	}

	ret = snd_soc_component_set_pll(component, WM5110_FLL2_REFCLK,
				    ARIZONA_FLL_SRC_MCLK1,
				    MCLK_RATE,
				    asyncclk_rate);
	if (ret < 0) {
		dev_err(component->dev, "Failed to set FLL2 source: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_pll(component, WM5110_FLL2,
				    ARIZONA_FLL_SRC_MCLK1,
				    MCLK_RATE,
				    asyncclk_rate);
	if (ret < 0) {
		dev_err(component->dev, "Failed to start FLL2: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_sysclk(component, ARIZONA_CLK_ASYNCCLK,
				       ARIZONA_CLK_SRC_FLL2,
				       asyncclk_rate,
				       SND_SOC_CLOCK_IN);
	if (ret < 0) {
		dev_err(component->dev, "Failed to set ASYNCCLK source: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int tm2_aif2_hw_free(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;
	int ret;

	/* disable FLL2 */
	ret = snd_soc_component_set_pll(component, WM5110_FLL2, ARIZONA_FLL_SRC_MCLK1,
				    0, 0);
	if (ret < 0)
		dev_err(component->dev, "Failed to stop FLL2: %d\n", ret);

	return ret;
}

__attribute__((used)) static int tm2_hdmi_hw_params(struct snd_pcm_substream *substream,
			      struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	unsigned int bfs;
	int bitwidth, ret;

	bitwidth = snd_pcm_format_width(params_format(params));
	if (bitwidth < 0) {
		dev_err(rtd->card->dev, "Invalid bit-width: %d\n", bitwidth);
		return bitwidth;
	}

	switch (bitwidth) {
	case 48:
		bfs = 64;
		break;
	case 16:
		bfs = 32;
		break;
	default:
		dev_err(rtd->card->dev, "Unsupported bit-width: %d\n", bitwidth);
		return -EINVAL;
	}

	switch (params_rate(params)) {
	case 48000:
	case 96000:
	case 192000:
		break;
	default:
		dev_err(rtd->card->dev, "Unsupported sample rate: %d\n",
			params_rate(params));
		return -EINVAL;
	}

	ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_OPCLK,
					0, SAMSUNG_I2S_OPCLK_PCLK);
	if (ret < 0)
		return ret;

	ret = snd_soc_dai_set_clkdiv(cpu_dai, SAMSUNG_I2S_DIV_BCLK, bfs);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int tm2_mic_bias(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_card *card = w->dapm->card;
	struct tm2_machine_priv *priv = snd_soc_card_get_drvdata(card);

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		gpiod_set_value_cansleep(priv->gpio_mic_bias,  1);
		break;
	case SND_SOC_DAPM_POST_PMD:
		gpiod_set_value_cansleep(priv->gpio_mic_bias,  0);
		break;
	}

	return 0;
}

__attribute__((used)) static int tm2_set_bias_level(struct snd_soc_card *card,
				struct snd_soc_dapm_context *dapm,
				enum snd_soc_bias_level level)
{
	struct snd_soc_pcm_runtime *rtd;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[0].name);

	if (dapm->dev != rtd->codec_dai->dev)
		return 0;

	switch (level) {
	case SND_SOC_BIAS_STANDBY:
		if (card->dapm.bias_level == SND_SOC_BIAS_OFF)
			tm2_start_sysclk(card);
		break;
	case SND_SOC_BIAS_OFF:
		tm2_stop_sysclk(card);
		break;
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int tm2_late_probe(struct snd_soc_card *card)
{
	struct tm2_machine_priv *priv = snd_soc_card_get_drvdata(card);
	struct snd_soc_dai_link_component dlc = { 0 };
	unsigned int ch_map[] = { 0, 1 };
	struct snd_soc_dai *amp_pdm_dai;
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_dai *aif1_dai;
	struct snd_soc_dai *aif2_dai;
	int ret;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[TM2_DAI_AIF1].name);
	aif1_dai = rtd->codec_dai;
	priv->component = rtd->codec_dai->component;

	ret = snd_soc_dai_set_sysclk(aif1_dai, ARIZONA_CLK_SYSCLK, 0, 0);
	if (ret < 0) {
		dev_err(aif1_dai->dev, "Failed to set SYSCLK: %d\n", ret);
		return ret;
	}

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[TM2_DAI_AIF2].name);
	aif2_dai = rtd->codec_dai;

	ret = snd_soc_dai_set_sysclk(aif2_dai, ARIZONA_CLK_ASYNCCLK, 0, 0);
	if (ret < 0) {
		dev_err(aif2_dai->dev, "Failed to set ASYNCCLK: %d\n", ret);
		return ret;
	}

	dlc.of_node = tm2_speaker_amp_dev.codec_of_node;
	amp_pdm_dai = snd_soc_find_dai(&dlc);
	if (!amp_pdm_dai)
		return -ENODEV;

	/* Set the MAX98504 V/I sense PDM Tx DAI channel mapping */
	ret = snd_soc_dai_set_channel_map(amp_pdm_dai, ARRAY_SIZE(ch_map),
					  ch_map, 0, NULL);
	if (ret < 0)
		return ret;

	ret = snd_soc_dai_set_tdm_slot(amp_pdm_dai, 0x3, 0x0, 2, 16);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int tm2_probe(struct platform_device *pdev)
{
	struct device_node *cpu_dai_node[2] = {};
	struct device_node *codec_dai_node[2] = {};
	const char *cells_name = NULL;
	struct device *dev = &pdev->dev;
	struct snd_soc_card *card = &tm2_card;
	struct tm2_machine_priv *priv;
	struct of_phandle_args args;
	int num_codecs, ret, i;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	snd_soc_card_set_drvdata(card, priv);
	card->dev = dev;

	priv->gpio_mic_bias = devm_gpiod_get(dev, "mic-bias", GPIOD_OUT_HIGH);
	if (IS_ERR(priv->gpio_mic_bias)) {
		dev_err(dev, "Failed to get mic bias gpio\n");
		return PTR_ERR(priv->gpio_mic_bias);
	}

	ret = snd_soc_of_parse_card_name(card, "model");
	if (ret < 0) {
		dev_err(dev, "Card name is not specified\n");
		return ret;
	}

	ret = snd_soc_of_parse_audio_routing(card, "samsung,audio-routing");
	if (ret < 0) {
		dev_err(dev, "Audio routing is not specified or invalid\n");
		return ret;
	}

	card->aux_dev[0].codec_of_node = of_parse_phandle(dev->of_node,
							"audio-amplifier", 0);
	if (!card->aux_dev[0].codec_of_node) {
		dev_err(dev, "audio-amplifier property invalid or missing\n");
		return -EINVAL;
	}

	num_codecs = of_count_phandle_with_args(dev->of_node, "audio-codec",
						 NULL);

	/* Skip the HDMI link if not specified in DT */
	if (num_codecs > 1) {
		card->num_links = ARRAY_SIZE(tm2_dai_links);
		cells_name = "#sound-dai-cells";
	} else {
		card->num_links = ARRAY_SIZE(tm2_dai_links) - 1;
	}

	for (i = 0; i < num_codecs; i++) {
		struct of_phandle_args args;

		ret = of_parse_phandle_with_args(dev->of_node, "i2s-controller",
						 cells_name, i, &args);
		if (!args.np) {
			dev_err(dev, "i2s-controller property parse error: %d\n", i);
			ret = -EINVAL;
			goto dai_node_put;
		}
		cpu_dai_node[i] = args.np;

		codec_dai_node[i] = of_parse_phandle(dev->of_node,
						     "audio-codec", i);
		if (!codec_dai_node[i]) {
			dev_err(dev, "audio-codec property parse error\n");
			ret = -EINVAL;
			goto dai_node_put;
		}
	}

	/* Initialize WM5110 - I2S and HDMI - I2S1 DAI links */
	for (i = 0; i < card->num_links; i++) {
		unsigned int dai_index = 0; /* WM5110 */

		card->dai_link[i].cpu_name = NULL;
		card->dai_link[i].platform_name = NULL;

		if (num_codecs > 1 && i == card->num_links - 1)
			dai_index = 1; /* HDMI */

		card->dai_link[i].codec_of_node = codec_dai_node[dai_index];
		card->dai_link[i].cpu_of_node = cpu_dai_node[dai_index];
		card->dai_link[i].platform_of_node = cpu_dai_node[dai_index];
	}

	if (num_codecs > 1) {
		/* HDMI DAI link (I2S1) */
		i = card->num_links - 1;

		ret = of_parse_phandle_with_fixed_args(dev->of_node,
						"audio-codec", 0, 1, &args);
		if (ret) {
			dev_err(dev, "audio-codec property parse error\n");
			goto dai_node_put;
		}

		ret = snd_soc_get_dai_name(&args, &card->dai_link[i].codec_dai_name);
		if (ret) {
			dev_err(dev, "Unable to get codec_dai_name\n");
			goto dai_node_put;
		}
	}

	ret = devm_snd_soc_register_component(dev, &tm2_component,
				tm2_ext_dai, ARRAY_SIZE(tm2_ext_dai));
	if (ret < 0) {
		dev_err(dev, "Failed to register component: %d\n", ret);
		goto dai_node_put;
	}

	ret = devm_snd_soc_register_card(dev, card);
	if (ret < 0) {
		dev_err(dev, "Failed to register card: %d\n", ret);
		goto dai_node_put;
	}

dai_node_put:
	for (i = 0; i < num_codecs; i++) {
		of_node_put(codec_dai_node[i]);
		of_node_put(cpu_dai_node[i]);
	}

	of_node_put(card->aux_dev[0].codec_of_node);

	return ret;
}

__attribute__((used)) static int tm2_pm_prepare(struct device *dev)
{
	struct snd_soc_card *card = dev_get_drvdata(dev);

	return tm2_stop_sysclk(card);
}

__attribute__((used)) static void tm2_pm_complete(struct device *dev)
{
	struct snd_soc_card *card = dev_get_drvdata(dev);

	tm2_start_sysclk(card);
}


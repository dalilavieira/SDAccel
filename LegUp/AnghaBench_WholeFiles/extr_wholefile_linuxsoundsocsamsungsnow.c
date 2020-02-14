#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai_link {char* name; int dai_fmt; char* stream_name; char* codec_dai_name; struct device_node* codec_of_node; struct device_node* cpu_of_node; struct device_node* platform_of_node; int /*<<< orphan*/ * ops; } ;
struct snow_priv {int /*<<< orphan*/  clk_i2s_bus; struct snd_soc_dai_link dai_link; } ;
struct snd_soc_pcm_runtime {int num_codecs; struct snd_soc_dai* codec_dai; struct snd_soc_dai** codec_dais; TYPE_1__* card; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_card {int num_links; struct device* dev; struct snd_soc_dai_link* dai_link; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
struct TYPE_2__ {struct device* dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int const*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FIN_PLL_RATE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int SND_SOC_DAIFMT_CBS_CFS ; 
 int SND_SOC_DAIFMT_I2S ; 
 int SND_SOC_DAIFMT_NB_NF ; 
 int /*<<< orphan*/  clk_put (int /*<<< orphan*/ ) ; 
 int clk_set_rate (int /*<<< orphan*/ ,long) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct snow_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (struct device*,struct snd_soc_card*) ; 
 int /*<<< orphan*/  of_clk_get_by_name (struct device_node*,char*) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 void* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 struct snow_priv* platform_get_drvdata (struct platform_device*) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 struct snow_priv* snd_soc_card_get_drvdata (TYPE_1__*) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct snow_priv*) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_pcm_runtime* snd_soc_get_pcm_runtime (struct snd_soc_card*,char*) ; 
 int snd_soc_of_get_dai_link_codecs (struct device*,struct device_node*,struct snd_soc_dai_link*) ; 
 int /*<<< orphan*/  snd_soc_of_parse_card_name (struct snd_soc_card*,char*) ; 
 int /*<<< orphan*/  snd_soc_of_put_dai_link_codecs (struct snd_soc_dai_link*) ; 
 int /*<<< orphan*/  snow_card_ops ; 
 struct snd_soc_card snow_snd ; 

__attribute__((used)) static int snow_card_hw_params(struct snd_pcm_substream *substream,
				      struct snd_pcm_hw_params *params)
{
	static const unsigned int pll_rate[] = {
		73728000U, 67737602U, 49152000U, 45158401U, 32768001U
	};
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snow_priv *priv = snd_soc_card_get_drvdata(rtd->card);
	int bfs, psr, rfs, bitwidth;
	unsigned long int rclk;
	long int freq = -EINVAL;
	int ret, i;

	bitwidth = snd_pcm_format_width(params_format(params));
	if (bitwidth < 0) {
		dev_err(rtd->card->dev, "Invalid bit-width: %d\n", bitwidth);
		return bitwidth;
	}

	if (bitwidth != 16 && bitwidth != 24) {
		dev_err(rtd->card->dev, "Unsupported bit-width: %d\n", bitwidth);
		return -EINVAL;
	}

	bfs = 2 * bitwidth;

	switch (params_rate(params)) {
	case 16000:
	case 22050:
	case 24000:
	case 32000:
	case 44100:
	case 48000:
	case 88200:
	case 96000:
		rfs = 8 * bfs;
		break;
	case 64000:
		rfs = 384;
		break;
	case 8000:
	case 11025:
	case 12000:
		rfs = 16 * bfs;
		break;
	default:
		return -EINVAL;
	}

	rclk = params_rate(params) * rfs;

	for (psr = 8; psr > 0; psr /= 2) {
		for (i = 0; i < ARRAY_SIZE(pll_rate); i++) {
			if ((pll_rate[i] - rclk * psr) <= 2) {
				freq = pll_rate[i];
				break;
			}
		}
	}
	if (freq < 0) {
		dev_err(rtd->card->dev, "Unsupported RCLK rate: %lu\n", rclk);
		return -EINVAL;
	}

	ret = clk_set_rate(priv->clk_i2s_bus, freq);
	if (ret < 0) {
		dev_err(rtd->card->dev, "I2S bus clock rate set failed\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int snow_late_probe(struct snd_soc_card *card)
{
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_dai *codec_dai;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[0].name);

	/* In the multi-codec case codec_dais 0 is MAX98095 and 1 is HDMI. */
	if (rtd->num_codecs > 1)
		codec_dai = rtd->codec_dais[0];
	else
		codec_dai = rtd->codec_dai;

	/* Set the MCLK rate for the codec */
	return snd_soc_dai_set_sysclk(codec_dai, 0,
				FIN_PLL_RATE, SND_SOC_CLOCK_IN);
}

__attribute__((used)) static int snow_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct snd_soc_card *card = &snow_snd;
	struct device_node *cpu, *codec;
	struct snd_soc_dai_link *link;
	struct snow_priv *priv;
	int ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	link = &priv->dai_link;

	link->dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS;

	link->name = "Primary";
	link->stream_name = link->name;

	card->dai_link = link;
	card->num_links = 1;
	card->dev = dev;

	/* Try new DT bindings with HDMI support first. */
	cpu = of_get_child_by_name(dev->of_node, "cpu");

	if (cpu) {
		link->ops = &snow_card_ops;

		link->cpu_of_node = of_parse_phandle(cpu, "sound-dai", 0);
		of_node_put(cpu);

		if (!link->cpu_of_node) {
			dev_err(dev, "Failed parsing cpu/sound-dai property\n");
			return -EINVAL;
		}

		codec = of_get_child_by_name(dev->of_node, "codec");
		ret = snd_soc_of_get_dai_link_codecs(dev, codec, link);
		of_node_put(codec);

		if (ret < 0) {
			of_node_put(link->cpu_of_node);
			dev_err(dev, "Failed parsing codec node\n");
			return ret;
		}

		priv->clk_i2s_bus = of_clk_get_by_name(link->cpu_of_node,
						       "i2s_opclk0");
		if (IS_ERR(priv->clk_i2s_bus)) {
			snd_soc_of_put_dai_link_codecs(link);
			of_node_put(link->cpu_of_node);
			return PTR_ERR(priv->clk_i2s_bus);
		}
	} else {
		link->codec_dai_name = "HiFi",

		link->cpu_of_node = of_parse_phandle(dev->of_node,
						"samsung,i2s-controller", 0);
		if (!link->cpu_of_node) {
			dev_err(dev, "i2s-controller property parse error\n");
			return -EINVAL;
		}

		link->codec_of_node = of_parse_phandle(dev->of_node,
						"samsung,audio-codec", 0);
		if (!link->codec_of_node) {
			of_node_put(link->cpu_of_node);
			dev_err(dev, "audio-codec property parse error\n");
			return -EINVAL;
		}
	}

	link->platform_of_node = link->cpu_of_node;

	/* Update card-name if provided through DT, else use default name */
	snd_soc_of_parse_card_name(card, "samsung,model");

	snd_soc_card_set_drvdata(card, priv);

	ret = devm_snd_soc_register_card(dev, card);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int snow_remove(struct platform_device *pdev)
{
	struct snow_priv *priv = platform_get_drvdata(pdev);
	struct snd_soc_dai_link *link = &priv->dai_link;

	of_node_put(link->cpu_of_node);
	of_node_put(link->codec_of_node);
	snd_soc_of_put_dai_link_codecs(link);

	clk_put(priv->clk_i2s_bus);

	return 0;
}


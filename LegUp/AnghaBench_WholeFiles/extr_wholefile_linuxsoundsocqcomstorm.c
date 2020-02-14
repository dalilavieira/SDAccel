#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {int /*<<< orphan*/  cpu_dai; struct snd_soc_card* card; } ;
struct snd_soc_dai_link {void* codec_of_node; void* cpu_of_node; void* platform_of_node; } ;
struct snd_soc_card {int num_links; struct snd_soc_dai_link* dai_link; TYPE_1__* dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_4__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  snd_pcm_format_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int STORM_SYSCLK_MULT ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct snd_soc_card* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (TYPE_1__*,struct snd_soc_card*) ; 
 void* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_sysclk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int snd_soc_of_parse_card_name (struct snd_soc_card*,char*) ; 
 struct snd_soc_dai_link storm_dai_link ; 

__attribute__((used)) static int storm_ops_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
	struct snd_soc_card *card = soc_runtime->card;
	snd_pcm_format_t format = params_format(params);
	unsigned int rate = params_rate(params);
	unsigned int sysclk_freq;
	int bitwidth, ret;

	bitwidth = snd_pcm_format_width(format);
	if (bitwidth < 0) {
		dev_err(card->dev, "invalid bit width given: %d\n", bitwidth);
		return bitwidth;
	}

	/*
	 * as the CPU DAI is the I2S bus master and no system clock is needed by
	 * the MAX98357a DAC, simply set the system clock to be a constant
	 * multiple of the bit clock for the clock divider
	 */
	sysclk_freq = rate * bitwidth * 2 * STORM_SYSCLK_MULT;

	ret = snd_soc_dai_set_sysclk(soc_runtime->cpu_dai, 0, sysclk_freq, 0);
	if (ret) {
		dev_err(card->dev, "error setting sysclk to %u: %d\n",
			sysclk_freq, ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int storm_parse_of(struct snd_soc_card *card)
{
	struct snd_soc_dai_link *dai_link = card->dai_link;
	struct device_node *np = card->dev->of_node;

	dai_link->cpu_of_node = of_parse_phandle(np, "cpu", 0);
	if (!dai_link->cpu_of_node) {
		dev_err(card->dev, "error getting cpu phandle\n");
		return -EINVAL;
	}
	dai_link->platform_of_node = dai_link->cpu_of_node;

	dai_link->codec_of_node = of_parse_phandle(np, "codec", 0);
	if (!dai_link->codec_of_node) {
		dev_err(card->dev, "error getting codec phandle\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int storm_platform_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card;
	int ret;

	card = devm_kzalloc(&pdev->dev, sizeof(*card), GFP_KERNEL);
	if (!card)
		return -ENOMEM;

	card->dev = &pdev->dev;

	ret = snd_soc_of_parse_card_name(card, "qcom,model");
	if (ret) {
		dev_err(&pdev->dev, "error parsing card name: %d\n", ret);
		return ret;
	}

	card->dai_link	= &storm_dai_link;
	card->num_links	= 1;

	ret = storm_parse_of(card);
	if (ret) {
		dev_err(&pdev->dev, "error resolving dai links: %d\n", ret);
		return ret;
	}

	ret = devm_snd_soc_register_card(&pdev->dev, card);
	if (ret)
		dev_err(&pdev->dev, "error registering soundcard: %d\n", ret);

	return ret;

}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; int /*<<< orphan*/  card; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai_link {int (* init ) (struct snd_soc_pcm_runtime*) ;struct device_node* platform_of_node; struct device_node* cpu_of_node; int /*<<< orphan*/ * ops; } ;
struct snd_soc_dai {int /*<<< orphan*/  component; } ;
struct snd_rpi_simple_drvdata {scalar_t__ fixed_bclk_ratio; int /*<<< orphan*/  card_name; struct snd_soc_dai_link* dai; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_7__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct device_node {int dummy; } ;
struct TYPE_6__ {struct snd_soc_dai_link* dai_link; int /*<<< orphan*/  name; TYPE_3__* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADAU1977_SYSCLK ; 
 int /*<<< orphan*/  ADAU1977_SYSCLK_SRC_MCLK ; 
 int ENODEV ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 int devm_snd_soc_register_card (TYPE_3__*,TYPE_1__*) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,scalar_t__) ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 unsigned int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 
 TYPE_1__ snd_rpi_simple ; 
 int /*<<< orphan*/  snd_rpi_simple_of_match ; 
 int /*<<< orphan*/  snd_rpi_simple_ops ; 
 struct snd_rpi_simple_drvdata* snd_soc_card_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (TYPE_1__*,struct snd_rpi_simple_drvdata*) ; 
 int snd_soc_component_set_sysclk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_bclk_ratio (struct snd_soc_dai*,unsigned int) ; 
 int snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_rpi_simple_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_rpi_simple_drvdata *drvdata =
		snd_soc_card_get_drvdata(rtd->card);
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;

	if (drvdata->fixed_bclk_ratio > 0)
		return snd_soc_dai_set_bclk_ratio(cpu_dai,
				drvdata->fixed_bclk_ratio);

	return 0;
}

__attribute__((used)) static int snd_rpi_simple_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	struct snd_rpi_simple_drvdata *drvdata;
	unsigned int sample_bits;

	drvdata = snd_soc_card_get_drvdata(rtd->card);

	if (drvdata->fixed_bclk_ratio > 0)
		return 0; // BCLK is configured in .init

	/* The simple drivers just set the bclk_ratio to sample_bits * 2 so
	 * hard-code this for now. More complex drivers could just replace
	 * the hw_params routine.
	 */
	sample_bits = snd_pcm_format_physical_width(params_format(params));
	return snd_soc_dai_set_bclk_ratio(cpu_dai, sample_bits * 2);
}

__attribute__((used)) static int adau1977_init(struct snd_soc_pcm_runtime *rtd)
{
	int ret;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;

	ret = snd_soc_dai_set_tdm_slot(codec_dai, 0, 0, 0, 0);
	if (ret < 0)
		return ret;

	return snd_soc_component_set_sysclk(codec_dai->component,
			ADAU1977_SYSCLK, ADAU1977_SYSCLK_SRC_MCLK,
			11289600, SND_SOC_CLOCK_IN);
}

__attribute__((used)) static int snd_rpi_simple_probe(struct platform_device *pdev)
{
	int ret = 0;
	const struct of_device_id *of_id;

	snd_rpi_simple.dev = &pdev->dev;
	of_id = of_match_node(snd_rpi_simple_of_match, pdev->dev.of_node);

	if (pdev->dev.of_node && of_id->data) {
		struct device_node *i2s_node;
		struct snd_rpi_simple_drvdata *drvdata =
			(struct snd_rpi_simple_drvdata *) of_id->data;
		struct snd_soc_dai_link *dai = drvdata->dai;

		snd_soc_card_set_drvdata(&snd_rpi_simple, drvdata);

		/* More complex drivers might override individual functions */
		if (!dai->init)
			dai->init = snd_rpi_simple_init;
		if (!dai->ops)
			dai->ops = &snd_rpi_simple_ops;

		snd_rpi_simple.name = drvdata->card_name;

		snd_rpi_simple.dai_link = dai;
		i2s_node = of_parse_phandle(pdev->dev.of_node,
				"i2s-controller", 0);
		if (!i2s_node) {
			pr_err("Failed to find i2s-controller DT node\n");
			return -ENODEV;
		}

		dai->cpu_of_node = i2s_node;
		dai->platform_of_node = i2s_node;
	}

	ret = devm_snd_soc_register_card(&pdev->dev, &snd_rpi_simple);
	if (ret && ret != -EPROBE_DEFER)
		dev_err(&pdev->dev, "Failed to register card %d\n", ret);

	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {TYPE_1__* card; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dai_link {struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_soc_card {TYPE_3__* dev; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; struct snd_soc_pcm_runtime* private_data; } ;
struct TYPE_5__ {int channels_max; int /*<<< orphan*/  formats; } ;
struct snd_pcm_runtime {TYPE_2__ hw; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_6__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int AIC32X4_AVDDWEAKDISABLE ; 
 int /*<<< orphan*/  AIC32X4_LDOCTL ; 
 int AIC32X4_LDOCTLEN ; 
 int /*<<< orphan*/  AIC32X4_MICBIAS ; 
 int AIC32X4_MICBIAS_2075V ; 
 int AIC32X4_MICBIAS_LDOIN ; 
 int /*<<< orphan*/  AIC32X4_PWRCFG ; 
 int /*<<< orphan*/  AIC32X4_SYSCLK_XTAL ; 
 int EINVAL ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  SNDRV_PCM_FMTBIT_S16_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  audiosense_constraints_ch ; 
 int /*<<< orphan*/  audiosense_constraints_rates ; 
 struct snd_soc_card audiosense_pi_card ; 
 struct snd_soc_dai_link* audiosense_pi_card_dai ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct snd_soc_card* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_msbits (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 int snd_soc_unregister_card (struct snd_soc_card*) ; 

__attribute__((used)) static int audiosense_pi_card_init(struct snd_soc_pcm_runtime *rtd)
{
	/* TODO: init of the codec specific dapm data, ignore suspend/resume */
	struct snd_soc_component *component = rtd->codec_dai->component;

	snd_soc_component_update_bits(component, AIC32X4_MICBIAS, 0x78,
				      AIC32X4_MICBIAS_LDOIN |
				      AIC32X4_MICBIAS_2075V);
	snd_soc_component_update_bits(component, AIC32X4_PWRCFG, 0x08,
				      AIC32X4_AVDDWEAKDISABLE);
	snd_soc_component_update_bits(component, AIC32X4_LDOCTL, 0x01,
				      AIC32X4_LDOCTLEN);

	return 0;
}

__attribute__((used)) static int audiosense_pi_card_hw_params(
		struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params)
{
	int ret = 0;
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;

	/* Set the codec system clock, there is a 12 MHz XTAL on the board */
	ret = snd_soc_dai_set_sysclk(codec_dai, AIC32X4_SYSCLK_XTAL,
				     12000000, SND_SOC_CLOCK_IN);
	if (ret) {
		dev_err(rtd->card->dev,
			"could not set codec driver clock params\n");
		return ret;
	}
	return 0;
}

__attribute__((used)) static int audiosense_pi_card_startup(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;

	/*
	 * Set codec to 48Khz Sampling, Stereo I/O and 16 bit audio
	 */
	runtime->hw.channels_max = 2;
	snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
				   &audiosense_constraints_ch);

	runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
	snd_pcm_hw_constraint_msbits(runtime, 0, 16, 16);


	snd_pcm_hw_constraint_list(substream->runtime, 0,
				   SNDRV_PCM_HW_PARAM_RATE,
				   &audiosense_constraints_rates);
	return 0;
}

__attribute__((used)) static int audiosense_pi_card_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct snd_soc_card *card = &audiosense_pi_card;
	struct snd_soc_dai_link *dai = &audiosense_pi_card_dai[0];
	struct device_node *i2s_node = pdev->dev.of_node;

	card->dev = &pdev->dev;

	if (!dai) {
		dev_err(&pdev->dev, "DAI not found. Missing or Invalid\n");
		return -EINVAL;
	}

	i2s_node = of_parse_phandle(pdev->dev.of_node, "i2s-controller", 0);
	if (!i2s_node) {
		dev_err(&pdev->dev,
			"Property 'i2s-controller' missing or invalid\n");
		return -EINVAL;
	}

	dai->cpu_dai_name = NULL;
	dai->cpu_of_node = i2s_node;
	dai->platform_name = NULL;
	dai->platform_of_node = i2s_node;

	of_node_put(i2s_node);

	ret = snd_soc_register_card(card);
	if (ret && ret != -EPROBE_DEFER)
		dev_err(&pdev->dev,
			"snd_soc_register_card() failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static int audiosense_pi_card_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = platform_get_drvdata(pdev);

	return snd_soc_unregister_card(card);

}


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
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_card {TYPE_1__* dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_5__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_6__ {void* codec_of_node; int /*<<< orphan*/ * codec_name; void* cpu_of_node; void* platform_of_node; int /*<<< orphan*/  platform_name; int /*<<< orphan*/  cpu_dai_name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 int EINVAL ; 
 int /*<<< orphan*/  SAMSUNG_I2S_CDCLK ; 
 int /*<<< orphan*/  SAMSUNG_I2S_RCLKSRC_0 ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_OUT ; 
 struct snd_soc_card arndale_rt5631 ; 
 TYPE_3__* arndale_rt5631_dai ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int devm_snd_soc_register_card (TYPE_1__*,struct snd_soc_card*) ; 
 void* of_parse_phandle (struct device_node*,char*,int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int arndale_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	int rfs, ret;
	unsigned long rclk;

	rfs = 256;

	rclk = params_rate(params) * rfs;

	ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_CDCLK,
					0, SND_SOC_CLOCK_OUT);
	if (ret < 0)
		return ret;

	ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_RCLKSRC_0,
					0, SND_SOC_CLOCK_OUT);

	if (ret < 0)
		return ret;

	ret = snd_soc_dai_set_sysclk(codec_dai, 0, rclk, SND_SOC_CLOCK_OUT);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int arndale_audio_probe(struct platform_device *pdev)
{
	int n, ret;
	struct device_node *np = pdev->dev.of_node;
	struct snd_soc_card *card = &arndale_rt5631;

	card->dev = &pdev->dev;

	for (n = 0; np && n < ARRAY_SIZE(arndale_rt5631_dai); n++) {
		if (!arndale_rt5631_dai[n].cpu_dai_name) {
			arndale_rt5631_dai[n].cpu_of_node = of_parse_phandle(np,
					"samsung,audio-cpu", n);

			if (!arndale_rt5631_dai[n].cpu_of_node) {
				dev_err(&pdev->dev,
				"Property 'samsung,audio-cpu' missing or invalid\n");
				return -EINVAL;
			}
		}
		if (!arndale_rt5631_dai[n].platform_name)
			arndale_rt5631_dai[n].platform_of_node =
					arndale_rt5631_dai[n].cpu_of_node;

		arndale_rt5631_dai[n].codec_name = NULL;
		arndale_rt5631_dai[n].codec_of_node = of_parse_phandle(np,
					"samsung,audio-codec", n);
		if (!arndale_rt5631_dai[0].codec_of_node) {
			dev_err(&pdev->dev,
			"Property 'samsung,audio-codec' missing or invalid\n");
			return -EINVAL;
		}
	}

	ret = devm_snd_soc_register_card(card->dev, card);

	if (ret)
		dev_err(&pdev->dev, "snd_soc_register_card() failed:%d\n", ret);

	return ret;
}


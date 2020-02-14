#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dai_link {struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_6__ {struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_5__ {TYPE_2__* dev; } ;

/* Variables and functions */
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 int devm_snd_soc_register_card (TYPE_2__*,TYPE_1__*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 unsigned int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 
 TYPE_1__ snd_rpi_dionaudio_loco ; 
 struct snd_soc_dai_link* snd_rpi_dionaudio_loco_dai ; 
 int snd_soc_dai_set_bclk_ratio (struct snd_soc_dai*,unsigned int) ; 

__attribute__((used)) static int snd_rpi_dionaudio_loco_hw_params(
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;

	unsigned int sample_bits =
		snd_pcm_format_physical_width(params_format(params));

	return snd_soc_dai_set_bclk_ratio(cpu_dai, sample_bits * 2);
}

__attribute__((used)) static int snd_rpi_dionaudio_loco_probe(struct platform_device *pdev)
{
	struct device_node *np;
	int ret = 0;

	snd_rpi_dionaudio_loco.dev = &pdev->dev;

	np = pdev->dev.of_node;
	if (np) {
		struct snd_soc_dai_link *dai = &snd_rpi_dionaudio_loco_dai[0];
		struct device_node *i2s_np;

		i2s_np = of_parse_phandle(np, "i2s-controller", 0);
		if (i2s_np) {
			dai->cpu_dai_name = NULL;
			dai->cpu_of_node = i2s_np;
			dai->platform_name = NULL;
			dai->platform_of_node = i2s_np;
		}
	}

	ret = devm_snd_soc_register_card(&pdev->dev, &snd_rpi_dionaudio_loco);
	if (ret && ret != -EPROBE_DEFER)
		dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
			ret);

	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_6__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* cpu_dai; TYPE_1__* codec_dai; } ;
struct snd_soc_dai_link {char* name; char* stream_name; int dai_fmt; struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_component {TYPE_2__* card; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_10__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_6__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_9__ {TYPE_6__* dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {struct snd_soc_component* component; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  ISABRECODEC_REG_01 ; 
 int /*<<< orphan*/  ISABRECODEC_REG_02 ; 
 int SND_SOC_DAIFMT_CBS_CFS ; 
 int SND_SOC_DAIFMT_I2S ; 
 int SND_SOC_DAIFMT_NB_NF ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 
 TYPE_3__ snd_rpi_i_sabre_q2m ; 
 struct snd_soc_dai_link* snd_rpi_i_sabre_q2m_dai ; 
 unsigned int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_bclk_ratio (struct snd_soc_dai*,int) ; 
 int snd_soc_register_card (TYPE_3__*) ; 
 int snd_soc_unregister_card (TYPE_3__*) ; 

__attribute__((used)) static int snd_rpi_i_sabre_q2m_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = rtd->codec_dai->component;
	unsigned int value;

	/* Device ID */
	value = snd_soc_component_read32(component, ISABRECODEC_REG_01);
	dev_info(component->card->dev, "Audiophonics Device ID : %02X\n", value);

	/* API revision */
	value = snd_soc_component_read32(component, ISABRECODEC_REG_02);
	dev_info(component->card->dev, "Audiophonics API revision : %02X\n", value);

	return 0;
}

__attribute__((used)) static int snd_rpi_i_sabre_q2m_hw_params(
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd     = substream->private_data;
	struct snd_soc_dai         *cpu_dai = rtd->cpu_dai;
	int bclk_ratio;

	bclk_ratio = snd_pcm_format_physical_width(
			params_format(params)) * params_channels(params);
	return snd_soc_dai_set_bclk_ratio(cpu_dai, bclk_ratio);
}

__attribute__((used)) static int snd_rpi_i_sabre_q2m_probe(struct platform_device *pdev)
{
	int ret = 0;

	snd_rpi_i_sabre_q2m.dev = &pdev->dev;
	if (pdev->dev.of_node) {
		struct device_node *i2s_node;
		struct snd_soc_dai_link *dai;

		dai = &snd_rpi_i_sabre_q2m_dai[0];
		i2s_node = of_parse_phandle(pdev->dev.of_node,
							"i2s-controller", 0);
		if (i2s_node) {
			dai->cpu_dai_name     = NULL;
			dai->cpu_of_node      = i2s_node;
			dai->platform_name    = NULL;
			dai->platform_of_node = i2s_node;
		} else {
			dev_err(&pdev->dev,
			    "Property 'i2s-controller' missing or invalid\n");
			return (-EINVAL);
		}

		dai->name        = "I-Sabre Q2M";
		dai->stream_name = "I-Sabre Q2M DAC";
		dai->dai_fmt     = SND_SOC_DAIFMT_I2S
					| SND_SOC_DAIFMT_NB_NF
					| SND_SOC_DAIFMT_CBS_CFS;
	}

	/* Wait for registering codec driver */
	mdelay(50);

	ret = snd_soc_register_card(&snd_rpi_i_sabre_q2m);
	if (ret) {
		dev_err(&pdev->dev,
			"snd_soc_register_card() failed: %d\n", ret);
	}

	return ret;
}

__attribute__((used)) static int snd_rpi_i_sabre_q2m_remove(struct platform_device *pdev)
{
	return snd_soc_unregister_card(&snd_rpi_i_sabre_q2m);
}


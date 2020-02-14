#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_9__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {TYPE_4__* codec_dai; TYPE_4__* cpu_dai; } ;
struct snd_soc_dai_link {struct device_node* codec_of_node; int /*<<< orphan*/ * codec_name; struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_card {TYPE_9__* dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_23__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_9__ dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  mult ;
struct TYPE_22__ {int /*<<< orphan*/  desc; int /*<<< orphan*/  ndescs; } ;
struct TYPE_21__ {TYPE_3__* driver; } ;
struct TYPE_19__ {int channels_min; int channels_max; } ;
struct TYPE_18__ {int channels_min; int channels_max; } ;
struct TYPE_20__ {TYPE_2__ capture; TYPE_1__ playback; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (TYPE_7__*) ; 
 int PTR_ERR (TYPE_7__*) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 133 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 132 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 int SND_SOC_DAIFMT_CBM_CFM ; 
 int SND_SOC_DAIFMT_CBS_CFS ; 
 int SND_SOC_DAIFMT_DSP_A ; 
 int SND_SOC_DAIFMT_I2S ; 
 int SND_SOC_DAIFMT_NB_NF ; 
 int /*<<< orphan*/  audioinjector_octo_constraints ; 
 struct snd_soc_dai_link* audioinjector_octo_dai ; 
 int audioinjector_octo_rate ; 
 TYPE_7__* codec_rst_gpio ; 
 int /*<<< orphan*/  dev_err (TYPE_9__*,char*,...) ; 
 TYPE_7__* devm_gpiod_get_array_optional (TYPE_9__*,char*,int /*<<< orphan*/ ) ; 
 TYPE_7__* devm_gpiod_get_optional (TYPE_9__*,char*,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (TYPE_9__*,struct snd_soc_card*) ; 
 int /*<<< orphan*/  gpiod_set_array_value_cansleep (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  gpiod_set_value (TYPE_7__*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 TYPE_7__* mult_gpios ; 
 int /*<<< orphan*/  non_stop_clocks ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_property_read_bool (scalar_t__,char*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct snd_soc_card snd_soc_audioinjector_octo ; 
 int snd_soc_dai_set_bclk_ratio (TYPE_4__*,int) ; 
 int snd_soc_dai_set_fmt (TYPE_4__*,int) ; 
 int snd_soc_dai_set_sysclk (TYPE_4__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int audioinjector_octo_dai_init(struct snd_soc_pcm_runtime *rtd)
{
	return snd_soc_dai_set_bclk_ratio(rtd->cpu_dai, 64);
}

__attribute__((used)) static int audioinjector_octo_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	rtd->cpu_dai->driver->playback.channels_min = 8;
	rtd->cpu_dai->driver->playback.channels_max = 8;
	rtd->cpu_dai->driver->capture.channels_min = 8;
	rtd->cpu_dai->driver->capture.channels_max = 8;
	rtd->codec_dai->driver->capture.channels_max = 8;
	
	snd_pcm_hw_constraint_list(substream->runtime, 0,
				SNDRV_PCM_HW_PARAM_RATE,
				&audioinjector_octo_constraints);

	return 0;
}

__attribute__((used)) static void audioinjector_octo_shutdown(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	rtd->cpu_dai->driver->playback.channels_min = 2;
	rtd->cpu_dai->driver->playback.channels_max = 2;
	rtd->cpu_dai->driver->capture.channels_min = 2;
	rtd->cpu_dai->driver->capture.channels_max = 2;
	rtd->codec_dai->driver->capture.channels_max = 6;
}

__attribute__((used)) static int audioinjector_octo_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;

	// set codec DAI configuration
	int ret = snd_soc_dai_set_fmt(rtd->codec_dai,
			SND_SOC_DAIFMT_CBS_CFS|SND_SOC_DAIFMT_DSP_A|
			SND_SOC_DAIFMT_NB_NF);
	if (ret < 0)
		return ret;

	// set cpu DAI configuration
	ret = snd_soc_dai_set_fmt(rtd->cpu_dai,
			SND_SOC_DAIFMT_CBM_CFM|SND_SOC_DAIFMT_I2S|
			SND_SOC_DAIFMT_NB_NF);
	if (ret < 0)
		return ret;

	audioinjector_octo_rate = params_rate(params);

	// Set the correct sysclock for the codec
	switch (audioinjector_octo_rate) {
	case 96000:
	case 48000:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 49152000,
									0);
		break;
	case 24000:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 49152000/2,
									0);
		break;
	case 32000:
	case 16000:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 49152000/3,
									0);
		break;
	case 8000:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 49152000/6,
									0);
		break;
	case 88200:
	case 44100:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 45185400,
									0);
		break;
	case 22050:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 45185400/2,
									0);
		break;
	case 29400:
	case 14700:
		return snd_soc_dai_set_sysclk(rtd->codec_dai, 0, 45185400/3,
									0);
		break;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int audioinjector_octo_trigger(struct snd_pcm_substream *substream,
								int cmd){
	int mult[4];

	memset(mult, 0, sizeof(mult));

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		if (!non_stop_clocks)
			break;
		/* Drop through... */
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
		switch (audioinjector_octo_rate) {
		case 96000:
			mult[3] = 1;
		case 88200:
			mult[1] = 1;
			mult[2] = 1;
			break;
		case 48000:
			mult[3] = 1;
		case 44100:
			mult[2] = 1;
			break;
		case 32000:
			mult[3] = 1;
		case 29400:
			mult[0] = 1;
			mult[1] = 1;
			break;
		case 24000:
			mult[3] = 1;
		case 22050:
			mult[1] = 1;
			break;
		case 16000:
			mult[3] = 1;
		case 14700:
			mult[0] = 1;
			break;
		case 8000:
			mult[3] = 1;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}
	gpiod_set_array_value_cansleep(mult_gpios->ndescs, mult_gpios->desc,
									mult);

	return 0;
}

__attribute__((used)) static int audioinjector_octo_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &snd_soc_audioinjector_octo;
	int ret;

	card->dev = &pdev->dev;

	if (pdev->dev.of_node) {
		struct snd_soc_dai_link *dai = &audioinjector_octo_dai[0];
		struct device_node *i2s_node =
					of_parse_phandle(pdev->dev.of_node,
							"i2s-controller", 0);
		struct device_node *codec_node =
					of_parse_phandle(pdev->dev.of_node,
								"codec", 0);

		mult_gpios = devm_gpiod_get_array_optional(&pdev->dev, "mult",
								GPIOD_OUT_LOW);
		if (IS_ERR(mult_gpios))
			return PTR_ERR(mult_gpios);

		codec_rst_gpio = devm_gpiod_get_optional(&pdev->dev, "reset",
								GPIOD_OUT_LOW);
		if (IS_ERR(codec_rst_gpio))
			return PTR_ERR(codec_rst_gpio);

		non_stop_clocks = of_property_read_bool(pdev->dev.of_node, "non-stop-clocks");

		if (codec_rst_gpio)
			gpiod_set_value(codec_rst_gpio, 1);
		msleep(500);
		if (codec_rst_gpio)
			gpiod_set_value(codec_rst_gpio, 0);
		msleep(500);
		if (codec_rst_gpio)
			gpiod_set_value(codec_rst_gpio, 1);
		msleep(500);

		if (i2s_node && codec_node) {
			dai->cpu_dai_name = NULL;
			dai->cpu_of_node = i2s_node;
			dai->platform_name = NULL;
			dai->platform_of_node = i2s_node;
			dai->codec_name = NULL;
			dai->codec_of_node = codec_node;
		} else
			if (!i2s_node) {
				dev_err(&pdev->dev,
				"i2s-controller missing or invalid in DT\n");
				return -EINVAL;
			} else {
				dev_err(&pdev->dev,
				"Property 'codec' missing or invalid\n");
				return -EINVAL;
			}
	}

	ret = devm_snd_soc_register_card(&pdev->dev, card);
	if (ret != 0)
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
	return ret;
}


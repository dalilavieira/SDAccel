#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_card* card; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dapm_route {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; int /*<<< orphan*/  dev; } ;
struct snd_soc_component {int dummy; } ;
struct TYPE_3__ {int idle_bias_off; } ;
struct snd_soc_card {int /*<<< orphan*/ * dev; TYPE_1__ dapm; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct dmi_system_id {scalar_t__ driver_data; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct snd_soc_dapm_route*) ; 
#define  BYT_RT5640_DMIC2_MAP 129 
 int BYT_RT5640_DMIC_EN ; 
#define  BYT_RT5640_IN1_MAP 128 
 int BYT_RT5640_MAP (int) ; 
 int /*<<< orphan*/  RT5640_PLL1_S_BCLK1 ; 
 int /*<<< orphan*/  RT5640_SCLK_S_PLL1 ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 struct snd_soc_card byt_rt5640_card ; 
 struct snd_soc_dapm_route* byt_rt5640_controls ; 
 struct snd_soc_dapm_route* byt_rt5640_intmic_dmic1_map ; 
 struct snd_soc_dapm_route* byt_rt5640_intmic_dmic2_map ; 
 struct snd_soc_dapm_route* byt_rt5640_intmic_in1_map ; 
 int byt_rt5640_quirk ; 
 int /*<<< orphan*/  byt_rt5640_quirk_table ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,struct snd_soc_card*) ; 
 int /*<<< orphan*/  dmi_check_system (int /*<<< orphan*/ ) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int rt5640_dmic_enable (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_add_card_controls (struct snd_soc_card*,struct snd_soc_dapm_route*,int) ; 
 int snd_soc_dai_set_pll (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_soc_dapm_add_routes (TYPE_1__*,struct snd_soc_dapm_route const*,int) ; 
 int /*<<< orphan*/  snd_soc_dapm_ignore_suspend (TYPE_1__*,char*) ; 

__attribute__((used)) static int byt_rt5640_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	int ret;

	ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_PLL1,
				     params_rate(params) * 256,
				     SND_SOC_CLOCK_IN);
	if (ret < 0) {
		dev_err(codec_dai->dev, "can't set codec clock %d\n", ret);
		return ret;
	}
	ret = snd_soc_dai_set_pll(codec_dai, 0, RT5640_PLL1_S_BCLK1,
				  params_rate(params) * 64,
				  params_rate(params) * 256);
	if (ret < 0) {
		dev_err(codec_dai->dev, "can't set codec pll: %d\n", ret);
		return ret;
	}
	return 0;
}

__attribute__((used)) static int byt_rt5640_quirk_cb(const struct dmi_system_id *id)
{
	byt_rt5640_quirk = (unsigned long)id->driver_data;
	return 1;
}

__attribute__((used)) static int byt_rt5640_init(struct snd_soc_pcm_runtime *runtime)
{
	int ret;
	struct snd_soc_component *component = runtime->codec_dai->component;
	struct snd_soc_card *card = runtime->card;
	const struct snd_soc_dapm_route *custom_map;
	int num_routes;

	card->dapm.idle_bias_off = true;

	ret = snd_soc_add_card_controls(card, byt_rt5640_controls,
					ARRAY_SIZE(byt_rt5640_controls));
	if (ret) {
		dev_err(card->dev, "unable to add card controls\n");
		return ret;
	}

	dmi_check_system(byt_rt5640_quirk_table);
	switch (BYT_RT5640_MAP(byt_rt5640_quirk)) {
	case BYT_RT5640_IN1_MAP:
		custom_map = byt_rt5640_intmic_in1_map;
		num_routes = ARRAY_SIZE(byt_rt5640_intmic_in1_map);
		break;
	case BYT_RT5640_DMIC2_MAP:
		custom_map = byt_rt5640_intmic_dmic2_map;
		num_routes = ARRAY_SIZE(byt_rt5640_intmic_dmic2_map);
		break;
	default:
		custom_map = byt_rt5640_intmic_dmic1_map;
		num_routes = ARRAY_SIZE(byt_rt5640_intmic_dmic1_map);
	}

	ret = snd_soc_dapm_add_routes(&card->dapm, custom_map, num_routes);
	if (ret)
		return ret;

	if (byt_rt5640_quirk & BYT_RT5640_DMIC_EN) {
		ret = rt5640_dmic_enable(component, 0, 0);
		if (ret)
			return ret;
	}

	snd_soc_dapm_ignore_suspend(&card->dapm, "Headphone");
	snd_soc_dapm_ignore_suspend(&card->dapm, "Speaker");

	return ret;
}

__attribute__((used)) static int byt_rt5640_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &byt_rt5640_card;

	card->dev = &pdev->dev;
	return devm_snd_soc_register_card(&pdev->dev, card);
}


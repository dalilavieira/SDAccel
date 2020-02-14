#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_card* card; int /*<<< orphan*/  dev; struct snd_soc_dai* codec_dai; } ;
struct snd_soc_dai {int /*<<< orphan*/  name; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_soc_card {int /*<<< orphan*/  name; int /*<<< orphan*/ * dev; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; struct snd_pcm_runtime* runtime; } ;
struct TYPE_7__ {int /*<<< orphan*/  channels_max; } ;
struct snd_pcm_runtime {TYPE_1__ hw; } ;
struct regulator_dev {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct acp_platform_info {int /*<<< orphan*/  capture_channel; void* i2s_instance; } ;
struct TYPE_9__ {int /*<<< orphan*/ * dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  jack; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_CHANNEL0 ; 
 int /*<<< orphan*/  CAP_CHANNEL1 ; 
 int /*<<< orphan*/  CZ_PLAT_CLK ; 
 int /*<<< orphan*/  DA7219_CLKSRC_MCLK ; 
 int /*<<< orphan*/  DA7219_PLL_FREQ_OUT_98304 ; 
 int /*<<< orphan*/  DA7219_SYSCLK_PLL ; 
 int /*<<< orphan*/  DUAL_CHANNEL ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* I2S_BT_INSTANCE ; 
 void* I2S_SP_INSTANCE ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  KEY_PLAYPAUSE ; 
 int /*<<< orphan*/  KEY_VOICECOMMAND ; 
 int /*<<< orphan*/  KEY_VOLUMEDOWN ; 
 int /*<<< orphan*/  KEY_VOLUMEUP ; 
 scalar_t__ PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int SND_JACK_BTN_0 ; 
 int SND_JACK_BTN_1 ; 
 int SND_JACK_BTN_2 ; 
 int SND_JACK_BTN_3 ; 
 int SND_JACK_HEADPHONE ; 
 int SND_JACK_MICROPHONE ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 TYPE_3__ acp_da7219_cfg ; 
 int /*<<< orphan*/  acp_da7219_desc ; 
 int bt_uart_enable ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_get (int /*<<< orphan*/ ,char*) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  constraints_channels ; 
 int /*<<< orphan*/  constraints_rates ; 
 struct snd_soc_card cz_card ; 
 TYPE_2__ cz_jack ; 
 int /*<<< orphan*/  da7219_aad_jack_det (struct snd_soc_component*,TYPE_2__*) ; 
 int /*<<< orphan*/  da7219_dai_clk ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_property_read_bool (int /*<<< orphan*/ *,char*) ; 
 struct acp_platform_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,struct snd_soc_card*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_jack_set_key (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct acp_platform_info* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int snd_soc_card_jack_new (struct snd_soc_card*,char*,int,TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct acp_platform_info*) ; 
 int snd_soc_dai_set_pll (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cz_da7219_init(struct snd_soc_pcm_runtime *rtd)
{
	int ret;
	struct snd_soc_card *card = rtd->card;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_component *component = codec_dai->component;

	dev_info(rtd->dev, "codec dai name = %s\n", codec_dai->name);

	ret = snd_soc_dai_set_sysclk(codec_dai, DA7219_CLKSRC_MCLK,
				     CZ_PLAT_CLK, SND_SOC_CLOCK_IN);
	if (ret < 0) {
		dev_err(rtd->dev, "can't set codec sysclk: %d\n", ret);
		return ret;
	}

	ret = snd_soc_dai_set_pll(codec_dai, 0, DA7219_SYSCLK_PLL,
				  CZ_PLAT_CLK, DA7219_PLL_FREQ_OUT_98304);
	if (ret < 0) {
		dev_err(rtd->dev, "can't set codec pll: %d\n", ret);
		return ret;
	}

	da7219_dai_clk = clk_get(component->dev, "da7219-dai-clks");

	ret = snd_soc_card_jack_new(card, "Headset Jack",
				SND_JACK_HEADPHONE | SND_JACK_MICROPHONE |
				SND_JACK_BTN_0 | SND_JACK_BTN_1 |
				SND_JACK_BTN_2 | SND_JACK_BTN_3,
				&cz_jack, NULL, 0);
	if (ret) {
		dev_err(card->dev, "HP jack creation failed %d\n", ret);
		return ret;
	}

	snd_jack_set_key(cz_jack.jack, SND_JACK_BTN_0, KEY_PLAYPAUSE);
	snd_jack_set_key(cz_jack.jack, SND_JACK_BTN_1, KEY_VOLUMEUP);
	snd_jack_set_key(cz_jack.jack, SND_JACK_BTN_2, KEY_VOLUMEDOWN);
	snd_jack_set_key(cz_jack.jack, SND_JACK_BTN_3, KEY_VOICECOMMAND);

	da7219_aad_jack_det(component, &cz_jack);

	return 0;
}

__attribute__((used)) static int da7219_clk_enable(struct snd_pcm_substream *substream)
{
	int ret = 0;
	struct snd_soc_pcm_runtime *rtd = substream->private_data;

	ret = clk_prepare_enable(da7219_dai_clk);
	if (ret < 0) {
		dev_err(rtd->dev, "can't enable master clock %d\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static void da7219_clk_disable(void)
{
	clk_disable_unprepare(da7219_dai_clk);
}

__attribute__((used)) static int cz_da7219_startup(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;
	struct acp_platform_info *machine = snd_soc_card_get_drvdata(card);

	/*
	 * On this platform for PCM device we support stereo
	 */

	runtime->hw.channels_max = DUAL_CHANNEL;
	snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
				   &constraints_channels);
	snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
				   &constraints_rates);

	machine->i2s_instance = I2S_SP_INSTANCE;
	machine->capture_channel = CAP_CHANNEL1;
	return da7219_clk_enable(substream);
}

__attribute__((used)) static void cz_da7219_shutdown(struct snd_pcm_substream *substream)
{
	da7219_clk_disable();
}

__attribute__((used)) static int cz_max_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;
	struct acp_platform_info *machine = snd_soc_card_get_drvdata(card);

	machine->i2s_instance = I2S_BT_INSTANCE;
	return da7219_clk_enable(substream);
}

__attribute__((used)) static void cz_max_shutdown(struct snd_pcm_substream *substream)
{
	da7219_clk_disable();
}

__attribute__((used)) static int cz_dmic0_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;
	struct acp_platform_info *machine = snd_soc_card_get_drvdata(card);

	machine->i2s_instance = I2S_BT_INSTANCE;
	return da7219_clk_enable(substream);
}

__attribute__((used)) static int cz_dmic1_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;
	struct acp_platform_info *machine = snd_soc_card_get_drvdata(card);

	machine->i2s_instance = I2S_SP_INSTANCE;
	machine->capture_channel = CAP_CHANNEL0;
	return da7219_clk_enable(substream);
}

__attribute__((used)) static void cz_dmic_shutdown(struct snd_pcm_substream *substream)
{
	da7219_clk_disable();
}

__attribute__((used)) static int cz_probe(struct platform_device *pdev)
{
	int ret;
	struct snd_soc_card *card;
	struct acp_platform_info *machine;
	struct regulator_dev *rdev;

	acp_da7219_cfg.dev = &pdev->dev;
	rdev = devm_regulator_register(&pdev->dev, &acp_da7219_desc,
				       &acp_da7219_cfg);
	if (IS_ERR(rdev)) {
		dev_err(&pdev->dev, "Failed to register regulator: %d\n",
			(int)PTR_ERR(rdev));
		return -EINVAL;
	}

	machine = devm_kzalloc(&pdev->dev, sizeof(struct acp_platform_info),
			       GFP_KERNEL);
	if (!machine)
		return -ENOMEM;
	card = &cz_card;
	cz_card.dev = &pdev->dev;
	platform_set_drvdata(pdev, card);
	snd_soc_card_set_drvdata(card, machine);
	ret = devm_snd_soc_register_card(&pdev->dev, &cz_card);
	if (ret) {
		dev_err(&pdev->dev,
				"devm_snd_soc_register_card(%s) failed: %d\n",
				cz_card.name, ret);
		return ret;
	}
	bt_uart_enable = !device_property_read_bool(&pdev->dev,
						    "bt-pad-enable");
	return 0;
}


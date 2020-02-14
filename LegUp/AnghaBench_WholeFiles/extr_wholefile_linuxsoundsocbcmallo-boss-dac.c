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
struct snd_soc_pcm_runtime {struct snd_soc_card* card; struct snd_soc_dai* codec_dai; struct snd_soc_dai* cpu_dai; int /*<<< orphan*/  dev; struct snd_soc_dai_link* dai_link; } ;
struct snd_soc_dapm_context {scalar_t__ dev; int bias_level; } ;
struct snd_soc_dai_link {char* name; char* stream_name; int dai_fmt; struct device_node* platform_of_node; int /*<<< orphan*/ * platform_name; struct device_node* cpu_of_node; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_dai {scalar_t__ dev; struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_soc_card {int (* set_bias_level ) (struct snd_soc_card*,struct snd_soc_dapm_context*,int) ;TYPE_2__* dev; TYPE_1__* dai_link; } ;
struct snd_ratnum {int num; int den_min; int den_max; int den_step; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {unsigned int rate_num; unsigned int rate_den; } ;
struct TYPE_6__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct pcm512x_priv {scalar_t__ sclk; } ;
struct device_node {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
#define  ALLO_BOSS_CLK44EN 132 
#define  ALLO_BOSS_CLK48EN 131 
#define  ALLO_BOSS_NOCLOCK 130 
 int /*<<< orphan*/  CLK_44EN_RATE ; 
 int /*<<< orphan*/  CLK_48EN_RATE ; 
 int EINVAL ; 
 int /*<<< orphan*/  ENOENT ; 
 int ENOMEM ; 
 scalar_t__ ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int /*<<< orphan*/  PCM512x_BCLK_LRCLK_CFG ; 
 int /*<<< orphan*/  PCM512x_GPIO_CONTROL_1 ; 
 int /*<<< orphan*/  PCM512x_GPIO_EN ; 
 int /*<<< orphan*/  PCM512x_GPIO_OUTPUT_3 ; 
 int /*<<< orphan*/  PCM512x_GPIO_OUTPUT_4 ; 
 int /*<<< orphan*/  PCM512x_GPIO_OUTPUT_6 ; 
 int /*<<< orphan*/  PCM512x_MASTER_CLKDIV_2 ; 
 int /*<<< orphan*/  PCM512x_MASTER_MODE ; 
 int /*<<< orphan*/  PCM512x_RATE_DET_4 ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int SND_SOC_DAIFMT_CBM_CFM ; 
 int SND_SOC_DAIFMT_I2S ; 
 int SND_SOC_DAIFMT_NB_NF ; 
 int clk_get_rate (scalar_t__) ; 
 int /*<<< orphan*/  clk_set_rate (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*,int) ; 
 scalar_t__ devm_gpiod_get_optional (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_kfree (int /*<<< orphan*/ ,struct snd_ratnum*) ; 
 struct snd_ratnum* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int digital_gain_0db_limit ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (scalar_t__,int) ; 
 int /*<<< orphan*/  hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ mute_gpio ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_bool (scalar_t__,char*) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 scalar_t__ slave ; 
 struct snd_soc_card snd_allo_boss ; 
 struct snd_soc_dai_link* snd_allo_boss_dai ; 
 int snd_interval_ratnum (int /*<<< orphan*/ ,int,struct snd_ratnum*,unsigned int*,unsigned int*) ; 
 int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 
 int snd_soc_allo_boss_master ; 
 struct pcm512x_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_read (struct snd_soc_component*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_dai_set_tdm_slot (struct snd_soc_dai*,int,int,int,int) ; 
 struct snd_soc_pcm_runtime* snd_soc_get_pcm_runtime (struct snd_soc_card*,int /*<<< orphan*/ ) ; 
 int snd_soc_limit_volume (struct snd_soc_card*,char*,int) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 int snd_soc_unregister_card (struct snd_soc_card*) ; 

__attribute__((used)) static void snd_allo_boss_select_clk(struct snd_soc_component *component,
	int clk_id)
{
	switch (clk_id) {
	case ALLO_BOSS_NOCLOCK:
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x24, 0x00);
		break;
	case ALLO_BOSS_CLK44EN:
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x24, 0x20);
		break;
	case ALLO_BOSS_CLK48EN:
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x24, 0x04);
		break;
	}
}

__attribute__((used)) static void snd_allo_boss_clk_gpio(struct snd_soc_component *component)
{
	snd_soc_component_update_bits(component, PCM512x_GPIO_EN, 0x24, 0x24);
	snd_soc_component_update_bits(component, PCM512x_GPIO_OUTPUT_3, 0x0f, 0x02);
	snd_soc_component_update_bits(component, PCM512x_GPIO_OUTPUT_6, 0x0f, 0x02);
}

__attribute__((used)) static bool snd_allo_boss_is_sclk(struct snd_soc_component *component)
{
	unsigned int sck;

	snd_soc_component_read(component, PCM512x_RATE_DET_4, &sck);
	return (!(sck & 0x40));
}

__attribute__((used)) static bool snd_allo_boss_is_sclk_sleep(
	struct snd_soc_component *component)
{
	msleep(2);
	return snd_allo_boss_is_sclk(component);
}

__attribute__((used)) static bool snd_allo_boss_is_master_card(struct snd_soc_component *component)
{
	bool isClk44EN, isClk48En, isNoClk;

	snd_allo_boss_clk_gpio(component);

	snd_allo_boss_select_clk(component, ALLO_BOSS_CLK44EN);
	isClk44EN = snd_allo_boss_is_sclk_sleep(component);

	snd_allo_boss_select_clk(component, ALLO_BOSS_NOCLOCK);
	isNoClk = snd_allo_boss_is_sclk_sleep(component);

	snd_allo_boss_select_clk(component, ALLO_BOSS_CLK48EN);
	isClk48En = snd_allo_boss_is_sclk_sleep(component);

	return (isClk44EN && isClk48En && !isNoClk);
}

__attribute__((used)) static int snd_allo_boss_clk_for_rate(int sample_rate)
{
	int type;

	switch (sample_rate) {
	case 11025:
	case 22050:
	case 44100:
	case 88200:
	case 176400:
	case 352800:
		type = ALLO_BOSS_CLK44EN;
		break;
	default:
		type = ALLO_BOSS_CLK48EN;
		break;
	}
	return type;
}

__attribute__((used)) static void snd_allo_boss_set_sclk(struct snd_soc_component *component,
	int sample_rate)
{
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	if (!IS_ERR(pcm512x->sclk)) {
		int ctype;

		ctype =	snd_allo_boss_clk_for_rate(sample_rate);
		clk_set_rate(pcm512x->sclk, (ctype == ALLO_BOSS_CLK44EN)
				? CLK_44EN_RATE : CLK_48EN_RATE);
		snd_allo_boss_select_clk(component, ctype);
	}
}

__attribute__((used)) static int snd_allo_boss_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct pcm512x_priv *priv = snd_soc_component_get_drvdata(component);

	if (slave)
		snd_soc_allo_boss_master = false;
	else
		snd_soc_allo_boss_master =
			snd_allo_boss_is_master_card(component);

	if (snd_soc_allo_boss_master) {
		struct snd_soc_dai_link *dai = rtd->dai_link;

		dai->name = "BossDAC";
		dai->stream_name = "Boss DAC HiFi [Master]";
		dai->dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF
			| SND_SOC_DAIFMT_CBM_CFM;

		snd_soc_component_update_bits(component, PCM512x_BCLK_LRCLK_CFG, 0x31, 0x11);
		snd_soc_component_update_bits(component, PCM512x_MASTER_MODE, 0x03, 0x03);
		snd_soc_component_update_bits(component, PCM512x_MASTER_CLKDIV_2, 0x7f, 63);
		/*
		* Default sclk to CLK_48EN_RATE, otherwise codec
		*  pcm512x_dai_startup_master method could call
		*  snd_pcm_hw_constraint_ratnums using CLK_44EN/64
		*  which will mask 384k sample rate.
		*/
		if (!IS_ERR(priv->sclk))
			clk_set_rate(priv->sclk, CLK_48EN_RATE);
	} else {
		priv->sclk = ERR_PTR(-ENOENT);
	}

	snd_soc_component_update_bits(component, PCM512x_GPIO_EN, 0x08, 0x08);
	snd_soc_component_update_bits(component, PCM512x_GPIO_OUTPUT_4, 0x0f, 0x02);
	snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x08, 0x08);

	if (digital_gain_0db_limit) {
		int ret;
		struct snd_soc_card *card = rtd->card;

		ret = snd_soc_limit_volume(card, "Digital Playback Volume",
				207);
		if (ret < 0)
			dev_warn(card->dev, "Failed to set volume limit: %d\n",
					ret);
	}

	return 0;
}

__attribute__((used)) static int snd_allo_boss_update_rate_den(
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	struct snd_ratnum *rats_no_pll;
	unsigned int num = 0, den = 0;
	int err;

	rats_no_pll = devm_kzalloc(rtd->dev, sizeof(*rats_no_pll), GFP_KERNEL);
	if (!rats_no_pll)
		return -ENOMEM;

	rats_no_pll->num = clk_get_rate(pcm512x->sclk) / 64;
	rats_no_pll->den_min = 1;
	rats_no_pll->den_max = 128;
	rats_no_pll->den_step = 1;

	err = snd_interval_ratnum(hw_param_interval(params,
		SNDRV_PCM_HW_PARAM_RATE), 1, rats_no_pll, &num, &den);
	if (err >= 0 && den) {
		params->rate_num = num;
		params->rate_den = den;
	}

	devm_kfree(rtd->dev, rats_no_pll);
	return 0;
}

__attribute__((used)) static void snd_allo_boss_gpio_mute(struct snd_soc_card *card)
{
	if (mute_gpio)
		gpiod_set_value_cansleep(mute_gpio, 1);
}

__attribute__((used)) static void snd_allo_boss_gpio_unmute(struct snd_soc_card *card)
{
	if (mute_gpio)
		gpiod_set_value_cansleep(mute_gpio, 0);
}

__attribute__((used)) static int snd_allo_boss_set_bias_level(struct snd_soc_card *card,
	struct snd_soc_dapm_context *dapm, enum snd_soc_bias_level level)
{
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_dai *codec_dai;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[0].name);
	codec_dai = rtd->codec_dai;

	if (dapm->dev != codec_dai->dev)
		return 0;

	switch (level) {
	case SND_SOC_BIAS_PREPARE:
		if (dapm->bias_level != SND_SOC_BIAS_STANDBY)
			break;
		/* UNMUTE DAC */
		snd_allo_boss_gpio_unmute(card);
		break;

	case SND_SOC_BIAS_STANDBY:
		if (dapm->bias_level != SND_SOC_BIAS_PREPARE)
			break;
		/* MUTE DAC */
		snd_allo_boss_gpio_mute(card);
		break;

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int snd_allo_boss_hw_params(
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	int ret = 0;
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	int channels = params_channels(params);
	int width = snd_pcm_format_physical_width(params_format(params));

	if (snd_soc_allo_boss_master) {
		struct snd_soc_component *component = rtd->codec_dai->component;

		snd_allo_boss_set_sclk(component,
			params_rate(params));

		ret = snd_allo_boss_update_rate_den(
			substream, params);
		if (ret)
			return ret;
	}

	ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x03, 0x03,
		channels, width);
	if (ret)
		return ret;
	ret = snd_soc_dai_set_tdm_slot(rtd->codec_dai, 0x03, 0x03,
		channels, width);
	return ret;
}

__attribute__((used)) static int snd_allo_boss_startup(
	struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct snd_soc_card *card = rtd->card;

	snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x08, 0x08);
	snd_allo_boss_gpio_mute(card);

	if (snd_soc_allo_boss_master) {
		struct pcm512x_priv *priv = snd_soc_component_get_drvdata(component);
		/*
		 * Default sclk to CLK_48EN_RATE, otherwise codec
		 * pcm512x_dai_startup_master method could call
		 * snd_pcm_hw_constraint_ratnums using CLK_44EN/64
		 * which will mask 384k sample rate.
		 */
		if (!IS_ERR(priv->sclk))
			clk_set_rate(priv->sclk, CLK_48EN_RATE);
	}

	return 0;
}

__attribute__((used)) static void snd_allo_boss_shutdown(
	struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;

	snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x08, 0x00);
}

__attribute__((used)) static int snd_allo_boss_prepare(
	struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_card *card = rtd->card;

	snd_allo_boss_gpio_unmute(card);
	return 0;
}

__attribute__((used)) static int snd_allo_boss_probe(struct platform_device *pdev)
{
	int ret = 0;

	snd_allo_boss.dev = &pdev->dev;

	if (pdev->dev.of_node) {
		struct device_node *i2s_node;
		struct snd_soc_dai_link *dai;

		dai = &snd_allo_boss_dai[0];
		i2s_node = of_parse_phandle(pdev->dev.of_node,
					    "i2s-controller", 0);

		if (i2s_node) {
			dai->cpu_dai_name = NULL;
			dai->cpu_of_node = i2s_node;
			dai->platform_name = NULL;
			dai->platform_of_node = i2s_node;
		}

		digital_gain_0db_limit = !of_property_read_bool(
			pdev->dev.of_node, "allo,24db_digital_gain");
		slave = of_property_read_bool(pdev->dev.of_node,
						"allo,slave");

		mute_gpio = devm_gpiod_get_optional(&pdev->dev, "mute",
							GPIOD_OUT_LOW);
		if (IS_ERR(mute_gpio)) {
			ret = PTR_ERR(mute_gpio);
			dev_err(&pdev->dev,
				"failed to get mute gpio: %d\n", ret);
			return ret;
		}

		if (mute_gpio)
			snd_allo_boss.set_bias_level =
				snd_allo_boss_set_bias_level;

		ret = snd_soc_register_card(&snd_allo_boss);
		if (ret) {
			dev_err(&pdev->dev,
				"snd_soc_register_card() failed: %d\n", ret);
			return ret;
		}

		if (mute_gpio)
			snd_allo_boss_gpio_mute(&snd_allo_boss);

		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int snd_allo_boss_remove(struct platform_device *pdev)
{
	snd_allo_boss_gpio_mute(&snd_allo_boss);
	return snd_soc_unregister_card(&snd_allo_boss);
}


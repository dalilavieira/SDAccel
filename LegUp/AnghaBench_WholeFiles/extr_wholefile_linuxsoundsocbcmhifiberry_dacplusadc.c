#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {TYPE_1__* codec_dai; TYPE_1__* cpu_dai; int /*<<< orphan*/  dev; struct snd_soc_card* card; struct snd_soc_dai_link* dai_link; } ;
struct snd_soc_dai_link {char* name; char* stream_name; int dai_fmt; struct device_node* platform_of_node; struct device_node* cpu_of_node; int /*<<< orphan*/ * platform_name; int /*<<< orphan*/ * cpu_dai_name; } ;
struct snd_soc_component {int dummy; } ;
struct snd_soc_card {int /*<<< orphan*/  dev; } ;
struct snd_ratnum {int num; int den_min; int den_max; int den_step; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {unsigned int rate_num; unsigned int rate_den; } ;
struct TYPE_8__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct pcm512x_priv {int /*<<< orphan*/  sclk; } ;
struct device_node {int dummy; } ;
struct TYPE_7__ {TYPE_3__* dev; } ;
struct TYPE_6__ {struct snd_soc_component* component; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_44EN_RATE ; 
 int /*<<< orphan*/  CLK_48EN_RATE ; 
 int /*<<< orphan*/  ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  HIFIBERRY_DACPRO_CLK44EN 130 
#define  HIFIBERRY_DACPRO_CLK48EN 129 
#define  HIFIBERRY_DACPRO_NOCLOCK 128 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCM512x_BCLK_LRCLK_CFG ; 
 int /*<<< orphan*/  PCM512x_GPIO_CONTROL_1 ; 
 int /*<<< orphan*/  PCM512x_GPIO_EN ; 
 int /*<<< orphan*/  PCM512x_GPIO_OUTPUT_3 ; 
 int /*<<< orphan*/  PCM512x_GPIO_OUTPUT_4 ; 
 int /*<<< orphan*/  PCM512x_GPIO_OUTPUT_6 ; 
 int /*<<< orphan*/  PCM512x_MASTER_CLKDIV_2 ; 
 int /*<<< orphan*/  PCM512x_MASTER_MODE ; 
 int /*<<< orphan*/  PCM512x_RATE_DET_4 ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int SND_SOC_DAIFMT_CBM_CFM ; 
 int SND_SOC_DAIFMT_I2S ; 
 int SND_SOC_DAIFMT_NB_NF ; 
 int clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_set_rate (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  devm_kfree (int /*<<< orphan*/ ,struct snd_ratnum*) ; 
 struct snd_ratnum* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (TYPE_3__*,TYPE_2__*) ; 
 int digital_gain_0db_limit ; 
 int /*<<< orphan*/  hifiberry_dacplusadc_LED_cnt ; 
 int /*<<< orphan*/  hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct device_node* of_parse_phandle (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_bool (scalar_t__,char*) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 scalar_t__ slave ; 
 int snd_interval_ratnum (int /*<<< orphan*/ ,int,struct snd_ratnum*,unsigned int*,unsigned int*) ; 
 int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 
 TYPE_2__ snd_rpi_hifiberry_dacplusadc ; 
 struct snd_soc_dai_link* snd_rpi_hifiberry_dacplusadc_dai ; 
 int snd_rpi_hifiberry_is_dacpro ; 
 struct pcm512x_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_read (struct snd_soc_component*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_dai_set_tdm_slot (TYPE_1__*,int,int,int,int) ; 
 int snd_soc_limit_volume (struct snd_soc_card*,char*,int) ; 

__attribute__((used)) static void snd_rpi_hifiberry_dacplusadc_select_clk(struct snd_soc_component *component,
	int clk_id)
{
	switch (clk_id) {
	case HIFIBERRY_DACPRO_NOCLOCK:
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x24, 0x00);
		break;
	case HIFIBERRY_DACPRO_CLK44EN:
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x24, 0x20);
		break;
	case HIFIBERRY_DACPRO_CLK48EN:
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x24, 0x04);
		break;
	}
}

__attribute__((used)) static void snd_rpi_hifiberry_dacplusadc_clk_gpio(struct snd_soc_component *component)
{
	snd_soc_component_update_bits(component, PCM512x_GPIO_EN, 0x24, 0x24);
	snd_soc_component_update_bits(component, PCM512x_GPIO_OUTPUT_3, 0x0f, 0x02);
	snd_soc_component_update_bits(component, PCM512x_GPIO_OUTPUT_6, 0x0f, 0x02);
}

__attribute__((used)) static bool snd_rpi_hifiberry_dacplusadc_is_sclk(struct snd_soc_component *component)
{
	unsigned int sck;

	snd_soc_component_read(component, PCM512x_RATE_DET_4, &sck);
	return (!(sck & 0x40));
}

__attribute__((used)) static bool snd_rpi_hifiberry_dacplusadc_is_sclk_sleep(
	struct snd_soc_component *component)
{
	msleep(2);
	return snd_rpi_hifiberry_dacplusadc_is_sclk(component);
}

__attribute__((used)) static bool snd_rpi_hifiberry_dacplusadc_is_pro_card(struct snd_soc_component *component)
{
	bool isClk44EN, isClk48En, isNoClk;

	snd_rpi_hifiberry_dacplusadc_clk_gpio(component);

	snd_rpi_hifiberry_dacplusadc_select_clk(component, HIFIBERRY_DACPRO_CLK44EN);
	isClk44EN = snd_rpi_hifiberry_dacplusadc_is_sclk_sleep(component);

	snd_rpi_hifiberry_dacplusadc_select_clk(component, HIFIBERRY_DACPRO_NOCLOCK);
	isNoClk = snd_rpi_hifiberry_dacplusadc_is_sclk_sleep(component);

	snd_rpi_hifiberry_dacplusadc_select_clk(component, HIFIBERRY_DACPRO_CLK48EN);
	isClk48En = snd_rpi_hifiberry_dacplusadc_is_sclk_sleep(component);

	return (isClk44EN && isClk48En && !isNoClk);
}

__attribute__((used)) static int snd_rpi_hifiberry_dacplusadc_clk_for_rate(int sample_rate)
{
	int type;

	switch (sample_rate) {
	case 11025:
	case 22050:
	case 44100:
	case 88200:
	case 176400:
	case 352800:
		type = HIFIBERRY_DACPRO_CLK44EN;
		break;
	default:
		type = HIFIBERRY_DACPRO_CLK48EN;
		break;
	}
	return type;
}

__attribute__((used)) static void snd_rpi_hifiberry_dacplusadc_set_sclk(struct snd_soc_component *component,
	int sample_rate)
{
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	if (!IS_ERR(pcm512x->sclk)) {
		int ctype;

		ctype = snd_rpi_hifiberry_dacplusadc_clk_for_rate(sample_rate);
		clk_set_rate(pcm512x->sclk, (ctype == HIFIBERRY_DACPRO_CLK44EN)
			? CLK_44EN_RATE : CLK_48EN_RATE);
		snd_rpi_hifiberry_dacplusadc_select_clk(component, ctype);
	}
}

__attribute__((used)) static int snd_rpi_hifiberry_dacplusadc_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = rtd->codec_dai->component;
	struct pcm512x_priv *priv;

	if (slave)
		snd_rpi_hifiberry_is_dacpro = false;
	else
		snd_rpi_hifiberry_is_dacpro =
				snd_rpi_hifiberry_dacplusadc_is_pro_card(component);

	if (snd_rpi_hifiberry_is_dacpro) {
		struct snd_soc_dai_link *dai = rtd->dai_link;

		dai->name = "HiFiBerry ADCDAC+ Pro";
		dai->stream_name = "HiFiBerry ADCDAC+ Pro HiFi";
		dai->dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF
			| SND_SOC_DAIFMT_CBM_CFM;

		snd_soc_component_update_bits(component, PCM512x_BCLK_LRCLK_CFG, 0x31, 0x11);
		snd_soc_component_update_bits(component, PCM512x_MASTER_MODE, 0x03, 0x03);
		snd_soc_component_update_bits(component, PCM512x_MASTER_CLKDIV_2, 0x7f, 63);
	} else {
		priv = snd_soc_component_get_drvdata(component);
		priv->sclk = ERR_PTR(-ENOENT);
	}

	snd_soc_component_update_bits(component, PCM512x_GPIO_EN, 0x08, 0x08);
	snd_soc_component_update_bits(component, PCM512x_GPIO_OUTPUT_4, 0x0f, 0x02);
	snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1, 0x08, 0x08);

	if (digital_gain_0db_limit) {
		int ret;
		struct snd_soc_card *card = rtd->card;

		ret = snd_soc_limit_volume(card, "Digital Playback Volume", 207);
		if (ret < 0)
			dev_warn(card->dev, "Failed to set volume limit: %d\n", ret);
	}

	return 0;
}

__attribute__((used)) static int snd_rpi_hifiberry_dacplusadc_update_rate_den(
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

__attribute__((used)) static int snd_rpi_hifiberry_dacplusadc_hw_params(
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	int ret = 0;
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	int channels = params_channels(params);
	int width = 32;

	if (snd_rpi_hifiberry_is_dacpro) {
		struct snd_soc_component *component = rtd->codec_dai->component;

		width = snd_pcm_format_physical_width(params_format(params));

		snd_rpi_hifiberry_dacplusadc_set_sclk(component,
			params_rate(params));

		ret = snd_rpi_hifiberry_dacplusadc_update_rate_den(
			substream, params);
	}

	ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x03, 0x03,
		channels, width);
	if (ret)
		return ret;
	ret = snd_soc_dai_set_tdm_slot(rtd->codec_dai, 0x03, 0x03,
		channels, width);
	return ret;
}

__attribute__((used)) static int snd_rpi_hifiberry_dacplusadc_startup(
	struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;

	snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1,
					 0x08, 0x08);
	hifiberry_dacplusadc_LED_cnt++;
	return 0;
}

__attribute__((used)) static void snd_rpi_hifiberry_dacplusadc_shutdown(
	struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_component *component = rtd->codec_dai->component;

	hifiberry_dacplusadc_LED_cnt--;
	if (!hifiberry_dacplusadc_LED_cnt)
		snd_soc_component_update_bits(component, PCM512x_GPIO_CONTROL_1,
						 0x08, 0x00);
}

__attribute__((used)) static int snd_rpi_hifiberry_dacplusadc_probe(struct platform_device *pdev)
{
	int ret = 0;

	snd_rpi_hifiberry_dacplusadc.dev = &pdev->dev;
	if (pdev->dev.of_node) {
		struct device_node *i2s_node;
		struct snd_soc_dai_link *dai;

		dai = &snd_rpi_hifiberry_dacplusadc_dai[0];
		i2s_node = of_parse_phandle(pdev->dev.of_node,
			"i2s-controller", 0);
		if (i2s_node) {
			dai->cpu_of_node = i2s_node;
			dai->platform_of_node = i2s_node;
			dai->cpu_dai_name = NULL;
			dai->platform_name = NULL;
		}
		dai = &snd_rpi_hifiberry_dacplusadc_dai[1];
		i2s_node = of_parse_phandle(pdev->dev.of_node, "dmic", 0);
		if (i2s_node) {
			dai->cpu_of_node = i2s_node;
			dai->platform_of_node = i2s_node;
		}

	}
	digital_gain_0db_limit = !of_property_read_bool(
		pdev->dev.of_node, "hifiberry,24db_digital_gain");
	slave = of_property_read_bool(pdev->dev.of_node,
					"hifiberry-dacplusadc,slave");

	ret = devm_snd_soc_register_card(&pdev->dev,
						 &snd_rpi_hifiberry_dacplusadc);
	if (ret && ret != -EPROBE_DEFER)
		dev_err(&pdev->dev,
			"snd_soc_register_card() failed: %d\n", ret);

	return ret;
}


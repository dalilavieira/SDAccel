#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct snd_soc_dapm_widget {char* name; int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {size_t id; struct snd_soc_component* component; } ;
struct snd_soc_component {TYPE_1__* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct adau1373_platform_data {int num_drc; int** drc_setting; int micbias1; int micbias2; int lineout_differential; scalar_t__ lineout_ground_sense; scalar_t__* input_differential; } ;
struct adau1373_dai {int master; scalar_t__ clk_src; int enable_src; unsigned int sysclk; } ;
struct adau1373 {int /*<<< orphan*/  regmap; struct adau1373_dai* dais; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
typedef  enum adau1373_micbias_voltage { ____Placeholder_adau1373_micbias_voltage } adau1373_micbias_voltage ;
struct TYPE_2__ {struct adau1373_platform_data* platform_data; } ;

/* Variables and functions */
 int const ADAU1373_ADC_CTRL ; 
 int ADAU1373_ADC_CTRL_PEAK_DETECT ; 
 int ADAU1373_ADC_CTRL_RESET_FORCE ; 
#define  ADAU1373_ADC_DAC_STATUS 163 
 int /*<<< orphan*/  ADAU1373_BCLKDIV (size_t) ; 
 unsigned int ADAU1373_BCLKDIV_64 ; 
 int ADAU1373_BCLKDIV_BCLK_MASK ; 
 int ADAU1373_BCLKDIV_SOURCE ; 
 int ADAU1373_BCLKDIV_SR_MASK ; 
 int /*<<< orphan*/  ADAU1373_CLK_SRC_DIV (int) ; 
#define  ADAU1373_CLK_SRC_PLL1 162 
#define  ADAU1373_CLK_SRC_PLL2 161 
 int /*<<< orphan*/  ADAU1373_DAI (size_t) ; 
 unsigned int ADAU1373_DAI_FORMAT_DSP ; 
 unsigned int ADAU1373_DAI_FORMAT_I2S ; 
 unsigned int ADAU1373_DAI_FORMAT_LEFT_J ; 
 unsigned int ADAU1373_DAI_FORMAT_RIGHT_J ; 
 unsigned int ADAU1373_DAI_INVERT_BCLK ; 
 unsigned int ADAU1373_DAI_INVERT_LRCLK ; 
 unsigned int ADAU1373_DAI_MASTER ; 
 unsigned int ADAU1373_DAI_WLEN_16 ; 
 unsigned int ADAU1373_DAI_WLEN_20 ; 
 unsigned int ADAU1373_DAI_WLEN_24 ; 
 unsigned int ADAU1373_DAI_WLEN_32 ; 
 int ADAU1373_DAI_WLEN_MASK ; 
 int const ADAU1373_DPLL_CTRL (int) ; 
 int const ADAU1373_DRC (unsigned int) ; 
 unsigned int ADAU1373_DRC_SIZE ; 
 int const ADAU1373_EP_CTRL ; 
 int ADAU1373_EP_CTRL_MICBIAS1_OFFSET ; 
 int ADAU1373_EP_CTRL_MICBIAS2_OFFSET ; 
 int const ADAU1373_INPUT_MODE ; 
#define  ADAU1373_MICBIAS_1_8V 160 
#define  ADAU1373_MICBIAS_2_2V 159 
#define  ADAU1373_MICBIAS_2_6V 158 
#define  ADAU1373_MICBIAS_2_9V 157 
 int const ADAU1373_OUTPUT_CTRL ; 
 unsigned int ADAU1373_OUTPUT_CTRL_LDIFF ; 
 unsigned int ADAU1373_OUTPUT_CTRL_LNFBEN ; 
#define  ADAU1373_PLL1 156 
#define  ADAU1373_PLL2 155 
 int const ADAU1373_PLL_CTRL1 (int) ; 
 int const ADAU1373_PLL_CTRL2 (int) ; 
 int const ADAU1373_PLL_CTRL3 (int) ; 
 int const ADAU1373_PLL_CTRL4 (int) ; 
 int const ADAU1373_PLL_CTRL5 (int) ; 
 int /*<<< orphan*/  ADAU1373_PLL_CTRL6 (int) ; 
 int ADAU1373_PLL_CTRL6_DPLL_BYPASS ; 
 int ADAU1373_PLL_CTRL6_PLL_EN ; 
#define  ADAU1373_PLL_SRC_BCLK1 154 
#define  ADAU1373_PLL_SRC_BCLK2 153 
#define  ADAU1373_PLL_SRC_BCLK3 152 
#define  ADAU1373_PLL_SRC_GPIO1 151 
#define  ADAU1373_PLL_SRC_GPIO2 150 
#define  ADAU1373_PLL_SRC_GPIO3 149 
#define  ADAU1373_PLL_SRC_GPIO4 148 
#define  ADAU1373_PLL_SRC_LRCLK1 147 
#define  ADAU1373_PLL_SRC_LRCLK2 146 
#define  ADAU1373_PLL_SRC_LRCLK3 145 
#define  ADAU1373_PLL_SRC_MCLK1 144 
#define  ADAU1373_PLL_SRC_MCLK2 143 
 int /*<<< orphan*/  ADAU1373_PWDN_CTRL3 ; 
 int ADAU1373_PWDN_CTRL3_PWR_EN ; 
#define  ADAU1373_SOFT_RESET 142 
 int ARRAY_SIZE (int**) ; 
 unsigned int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_BIAS_OFF 141 
#define  SND_SOC_BIAS_ON 140 
#define  SND_SOC_BIAS_PREPARE 139 
#define  SND_SOC_BIAS_STANDBY 138 
#define  SND_SOC_DAIFMT_CBM_CFM 137 
#define  SND_SOC_DAIFMT_CBS_CFS 136 
#define  SND_SOC_DAIFMT_DSP_B 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_IF 133 
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 130 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 scalar_t__ SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  adau1373_component_driver ; 
 int** adau1373_dai_driver ; 
 int** adau1373_drc_controls ; 
 int** adau1373_lineout2_controls ; 
 int /*<<< orphan*/  adau1373_regmap_config ; 
 int adau_calc_pll_cfg (unsigned int,unsigned int,int*) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct adau1373*) ; 
 struct adau1373* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int**,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int const,int) ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,int**,int) ; 
 struct adau1373* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char*,char const*) ; 

__attribute__((used)) static int adau1373_pll_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	unsigned int pll_id = w->name[3] - '1';
	unsigned int val;

	if (SND_SOC_DAPM_EVENT_ON(event))
		val = ADAU1373_PLL_CTRL6_PLL_EN;
	else
		val = 0;

	regmap_update_bits(adau1373->regmap, ADAU1373_PLL_CTRL6(pll_id),
		ADAU1373_PLL_CTRL6_PLL_EN, val);

	if (SND_SOC_DAPM_EVENT_ON(event))
		mdelay(5);

	return 0;
}

__attribute__((used)) static int adau1373_check_aif_clk(struct snd_soc_dapm_widget *source,
	struct snd_soc_dapm_widget *sink)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(source->dapm);
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	unsigned int dai;
	const char *clk;

	dai = sink->name[3] - '1';

	if (!adau1373->dais[dai].master)
		return 0;

	if (adau1373->dais[dai].clk_src == ADAU1373_CLK_SRC_PLL1)
		clk = "SYSCLK1";
	else
		clk = "SYSCLK2";

	return strcmp(source->name, clk) == 0;
}

__attribute__((used)) static int adau1373_check_src(struct snd_soc_dapm_widget *source,
	struct snd_soc_dapm_widget *sink)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(source->dapm);
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	unsigned int dai;

	dai = sink->name[3] - '1';

	return adau1373->dais[dai].enable_src;
}

__attribute__((used)) static int adau1373_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	struct adau1373_dai *adau1373_dai = &adau1373->dais[dai->id];
	unsigned int div;
	unsigned int freq;
	unsigned int ctrl;

	freq = adau1373_dai->sysclk;

	if (freq % params_rate(params) != 0)
		return -EINVAL;

	switch (freq / params_rate(params)) {
	case 1024: /* sysclk / 256 */
		div = 0;
		break;
	case 1536: /* 2/3 sysclk / 256 */
		div = 1;
		break;
	case 2048: /* 1/2 sysclk / 256 */
		div = 2;
		break;
	case 3072: /* 1/3 sysclk / 256 */
		div = 3;
		break;
	case 4096: /* 1/4 sysclk / 256 */
		div = 4;
		break;
	case 6144: /* 1/6 sysclk / 256 */
		div = 5;
		break;
	case 5632: /* 2/11 sysclk / 256 */
		div = 6;
		break;
	default:
		return -EINVAL;
	}

	adau1373_dai->enable_src = (div != 0);

	regmap_update_bits(adau1373->regmap, ADAU1373_BCLKDIV(dai->id),
		ADAU1373_BCLKDIV_SR_MASK | ADAU1373_BCLKDIV_BCLK_MASK,
		(div << 2) | ADAU1373_BCLKDIV_64);

	switch (params_width(params)) {
	case 16:
		ctrl = ADAU1373_DAI_WLEN_16;
		break;
	case 20:
		ctrl = ADAU1373_DAI_WLEN_20;
		break;
	case 24:
		ctrl = ADAU1373_DAI_WLEN_24;
		break;
	case 32:
		ctrl = ADAU1373_DAI_WLEN_32;
		break;
	default:
		return -EINVAL;
	}

	return regmap_update_bits(adau1373->regmap, ADAU1373_DAI(dai->id),
			ADAU1373_DAI_WLEN_MASK, ctrl);
}

__attribute__((used)) static int adau1373_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	struct adau1373_dai *adau1373_dai = &adau1373->dais[dai->id];
	unsigned int ctrl;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		ctrl = ADAU1373_DAI_MASTER;
		adau1373_dai->master = true;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		ctrl = 0;
		adau1373_dai->master = false;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		ctrl |= ADAU1373_DAI_FORMAT_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		ctrl |= ADAU1373_DAI_FORMAT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		ctrl |= ADAU1373_DAI_FORMAT_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		ctrl |= ADAU1373_DAI_FORMAT_DSP;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_NF:
		ctrl |= ADAU1373_DAI_INVERT_BCLK;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		ctrl |= ADAU1373_DAI_INVERT_LRCLK;
		break;
	case SND_SOC_DAIFMT_IB_IF:
		ctrl |= ADAU1373_DAI_INVERT_LRCLK | ADAU1373_DAI_INVERT_BCLK;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adau1373->regmap, ADAU1373_DAI(dai->id),
		~ADAU1373_DAI_WLEN_MASK, ctrl);

	return 0;
}

__attribute__((used)) static int adau1373_set_dai_sysclk(struct snd_soc_dai *dai,
	int clk_id, unsigned int freq, int dir)
{
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(dai->component);
	struct adau1373_dai *adau1373_dai = &adau1373->dais[dai->id];

	switch (clk_id) {
	case ADAU1373_CLK_SRC_PLL1:
	case ADAU1373_CLK_SRC_PLL2:
		break;
	default:
		return -EINVAL;
	}

	adau1373_dai->sysclk = freq;
	adau1373_dai->clk_src = clk_id;

	regmap_update_bits(adau1373->regmap, ADAU1373_BCLKDIV(dai->id),
		ADAU1373_BCLKDIV_SOURCE, clk_id << 5);

	return 0;
}

__attribute__((used)) static int adau1373_set_pll(struct snd_soc_component *component, int pll_id,
	int source, unsigned int freq_in, unsigned int freq_out)
{
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	unsigned int dpll_div = 0;
	uint8_t pll_regs[5];
	int ret;

	switch (pll_id) {
	case ADAU1373_PLL1:
	case ADAU1373_PLL2:
		break;
	default:
		return -EINVAL;
	}

	switch (source) {
	case ADAU1373_PLL_SRC_BCLK1:
	case ADAU1373_PLL_SRC_BCLK2:
	case ADAU1373_PLL_SRC_BCLK3:
	case ADAU1373_PLL_SRC_LRCLK1:
	case ADAU1373_PLL_SRC_LRCLK2:
	case ADAU1373_PLL_SRC_LRCLK3:
	case ADAU1373_PLL_SRC_MCLK1:
	case ADAU1373_PLL_SRC_MCLK2:
	case ADAU1373_PLL_SRC_GPIO1:
	case ADAU1373_PLL_SRC_GPIO2:
	case ADAU1373_PLL_SRC_GPIO3:
	case ADAU1373_PLL_SRC_GPIO4:
		break;
	default:
		return -EINVAL;
	}

	if (freq_in < 7813 || freq_in > 27000000)
		return -EINVAL;

	if (freq_out < 45158000 || freq_out > 49152000)
		return -EINVAL;

	/* APLL input needs to be >= 8Mhz, so in case freq_in is less we use the
	 * DPLL to get it there. DPLL_out = (DPLL_in / div) * 1024 */
	while (freq_in < 8000000) {
		freq_in *= 2;
		dpll_div++;
	}

	ret = adau_calc_pll_cfg(freq_in, freq_out, pll_regs);
	if (ret)
		return -EINVAL;

	if (dpll_div) {
		dpll_div = 11 - dpll_div;
		regmap_update_bits(adau1373->regmap, ADAU1373_PLL_CTRL6(pll_id),
			ADAU1373_PLL_CTRL6_DPLL_BYPASS, 0);
	} else {
		regmap_update_bits(adau1373->regmap, ADAU1373_PLL_CTRL6(pll_id),
			ADAU1373_PLL_CTRL6_DPLL_BYPASS,
			ADAU1373_PLL_CTRL6_DPLL_BYPASS);
	}

	regmap_write(adau1373->regmap, ADAU1373_DPLL_CTRL(pll_id),
		(source << 4) | dpll_div);
	regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL1(pll_id), pll_regs[0]);
	regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL2(pll_id), pll_regs[1]);
	regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL3(pll_id), pll_regs[2]);
	regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL4(pll_id), pll_regs[3]);
	regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL5(pll_id), pll_regs[4]);

	/* Set sysclk to pll_rate / 4 */
	regmap_update_bits(adau1373->regmap, ADAU1373_CLK_SRC_DIV(pll_id), 0x3f, 0x09);

	return 0;
}

__attribute__((used)) static void adau1373_load_drc_settings(struct adau1373 *adau1373,
	unsigned int nr, uint8_t *drc)
{
	unsigned int i;

	for (i = 0; i < ADAU1373_DRC_SIZE; ++i)
		regmap_write(adau1373->regmap, ADAU1373_DRC(nr) + i, drc[i]);
}

__attribute__((used)) static bool adau1373_valid_micbias(enum adau1373_micbias_voltage micbias)
{
	switch (micbias) {
	case ADAU1373_MICBIAS_2_9V:
	case ADAU1373_MICBIAS_2_2V:
	case ADAU1373_MICBIAS_2_6V:
	case ADAU1373_MICBIAS_1_8V:
		return true;
	default:
		break;
	}
	return false;
}

__attribute__((used)) static int adau1373_probe(struct snd_soc_component *component)
{
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);
	struct adau1373_platform_data *pdata = component->dev->platform_data;
	bool lineout_differential = false;
	unsigned int val;
	int i;

	if (pdata) {
		if (pdata->num_drc > ARRAY_SIZE(pdata->drc_setting))
			return -EINVAL;

		if (!adau1373_valid_micbias(pdata->micbias1) ||
			!adau1373_valid_micbias(pdata->micbias2))
			return -EINVAL;

		for (i = 0; i < pdata->num_drc; ++i) {
			adau1373_load_drc_settings(adau1373, i,
				pdata->drc_setting[i]);
		}

		snd_soc_add_component_controls(component, adau1373_drc_controls,
			pdata->num_drc);

		val = 0;
		for (i = 0; i < 4; ++i) {
			if (pdata->input_differential[i])
				val |= BIT(i);
		}
		regmap_write(adau1373->regmap, ADAU1373_INPUT_MODE, val);

		val = 0;
		if (pdata->lineout_differential)
			val |= ADAU1373_OUTPUT_CTRL_LDIFF;
		if (pdata->lineout_ground_sense)
			val |= ADAU1373_OUTPUT_CTRL_LNFBEN;
		regmap_write(adau1373->regmap, ADAU1373_OUTPUT_CTRL, val);

		lineout_differential = pdata->lineout_differential;

		regmap_write(adau1373->regmap, ADAU1373_EP_CTRL,
			(pdata->micbias1 << ADAU1373_EP_CTRL_MICBIAS1_OFFSET) |
			(pdata->micbias2 << ADAU1373_EP_CTRL_MICBIAS2_OFFSET));
	}

	if (!lineout_differential) {
		snd_soc_add_component_controls(component, adau1373_lineout2_controls,
			ARRAY_SIZE(adau1373_lineout2_controls));
	}

	regmap_write(adau1373->regmap, ADAU1373_ADC_CTRL,
	    ADAU1373_ADC_CTRL_RESET_FORCE | ADAU1373_ADC_CTRL_PEAK_DETECT);

	return 0;
}

__attribute__((used)) static int adau1373_set_bias_level(struct snd_soc_component *component,
	enum snd_soc_bias_level level)
{
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		regmap_update_bits(adau1373->regmap, ADAU1373_PWDN_CTRL3,
			ADAU1373_PWDN_CTRL3_PWR_EN, ADAU1373_PWDN_CTRL3_PWR_EN);
		break;
	case SND_SOC_BIAS_OFF:
		regmap_update_bits(adau1373->regmap, ADAU1373_PWDN_CTRL3,
			ADAU1373_PWDN_CTRL3_PWR_EN, 0);
		break;
	}
	return 0;
}

__attribute__((used)) static int adau1373_resume(struct snd_soc_component *component)
{
	struct adau1373 *adau1373 = snd_soc_component_get_drvdata(component);

	regcache_sync(adau1373->regmap);

	return 0;
}

__attribute__((used)) static bool adau1373_register_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ADAU1373_SOFT_RESET:
	case ADAU1373_ADC_DAC_STATUS:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int adau1373_i2c_probe(struct i2c_client *client,
			      const struct i2c_device_id *id)
{
	struct adau1373 *adau1373;
	int ret;

	adau1373 = devm_kzalloc(&client->dev, sizeof(*adau1373), GFP_KERNEL);
	if (!adau1373)
		return -ENOMEM;

	adau1373->regmap = devm_regmap_init_i2c(client,
		&adau1373_regmap_config);
	if (IS_ERR(adau1373->regmap))
		return PTR_ERR(adau1373->regmap);

	regmap_write(adau1373->regmap, ADAU1373_SOFT_RESET, 0x00);

	dev_set_drvdata(&client->dev, adau1373);

	ret = devm_snd_soc_register_component(&client->dev,
			&adau1373_component_driver,
			adau1373_dai_driver, ARRAY_SIZE(adau1373_dai_driver));
	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u32 ;
struct snd_soc_dai {int /*<<< orphan*/ * dev; struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_5__ {scalar_t__* value; } ;
struct TYPE_6__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct da9055_priv {scalar_t__ mclk_rate; int master; int /*<<< orphan*/  regmap; struct da9055_platform_data* pdata; } ;
struct da9055_platform_data {int micbias; scalar_t__ micbias_source; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_7__ {unsigned int fref; scalar_t__ mode; unsigned int fout; int frac_top; int frac_bot; int integer; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 int DA9055_ADC_L_CTRL ; 
 int DA9055_ADC_L_EN ; 
#define  DA9055_ADC_L_GAIN_STATUS 158 
 int DA9055_ADC_R_CTRL ; 
 int DA9055_ADC_R_EN ; 
#define  DA9055_ADC_R_GAIN_STATUS 157 
 int DA9055_AIF_BCLKS_PER_WCLK_32 ; 
 int DA9055_AIF_BCLK_MASK ; 
 int DA9055_AIF_CLK_EN_MASTER_MODE ; 
 int DA9055_AIF_CLK_EN_SLAVE_MODE ; 
 int DA9055_AIF_CLK_MODE ; 
 int DA9055_AIF_CLK_MODE_MASK ; 
 int DA9055_AIF_CTRL ; 
 int DA9055_AIF_FORMAT_DSP ; 
 int DA9055_AIF_FORMAT_I2S_MODE ; 
 int DA9055_AIF_FORMAT_LEFT_J ; 
 int DA9055_AIF_FORMAT_MASK ; 
 int DA9055_AIF_FORMAT_RIGHT_J ; 
 int DA9055_AIF_WORD_LENGTH_MASK ; 
 int DA9055_AIF_WORD_S16_LE ; 
 int DA9055_AIF_WORD_S20_3LE ; 
 int DA9055_AIF_WORD_S24_LE ; 
 int DA9055_AIF_WORD_S32_LE ; 
 int DA9055_ALC_AVG_ITERATIONS ; 
 int DA9055_ALC_CIC_OP_CHANNEL_LEFT ; 
 int DA9055_ALC_CIC_OP_CHANNEL_RIGHT ; 
 int DA9055_ALC_CIC_OP_LVL_CTRL ; 
#define  DA9055_ALC_CIC_OP_LVL_DATA 156 
 int DA9055_ALC_DATA_MIDDLE ; 
 int DA9055_ALC_DATA_TOP ; 
 int DA9055_ALC_OFFSET_15_8 ; 
 int DA9055_ALC_OFFSET_17_16 ; 
 int DA9055_ALC_OFFSET_OP2M_L ; 
 int DA9055_ALC_OFFSET_OP2M_R ; 
 int DA9055_ALC_OFFSET_OP2U_L ; 
 int DA9055_ALC_OFFSET_OP2U_R ; 
 int DA9055_AUX_L_CTRL ; 
#define  DA9055_AUX_L_GAIN_STATUS 155 
 int DA9055_AUX_R_CTRL ; 
#define  DA9055_AUX_R_GAIN_STATUS 154 
 int DA9055_BIAS_EN ; 
#define  DA9055_CLKSRC_MCLK 153 
 int DA9055_DAC_L_CTRL ; 
#define  DA9055_DAC_L_GAIN_STATUS 152 
 int DA9055_DAC_L_MUTE_EN ; 
 int DA9055_DAC_R_CTRL ; 
#define  DA9055_DAC_R_GAIN_STATUS 151 
 int DA9055_DAC_R_MUTE_EN ; 
 int DA9055_GAIN_RAMPING_EN ; 
 int DA9055_HP_L_CTRL ; 
#define  DA9055_HP_L_GAIN_STATUS 150 
 int DA9055_HP_R_CTRL ; 
#define  DA9055_HP_R_GAIN_STATUS 149 
 int DA9055_LINE_CTRL ; 
#define  DA9055_LINE_GAIN_STATUS 148 
 int DA9055_MICBIAS2_EN ; 
#define  DA9055_MICBIAS_1_6V 147 
#define  DA9055_MICBIAS_1_8V 146 
#define  DA9055_MICBIAS_2_1V 145 
#define  DA9055_MICBIAS_2_2V 144 
 int DA9055_MICBIAS_LEVEL_MASK ; 
 int DA9055_MIC_CONFIG ; 
 int DA9055_MIC_L_CTRL ; 
#define  DA9055_MIC_L_GAIN_STATUS 143 
 int DA9055_MIC_L_MUTE_EN ; 
 int DA9055_MIC_R_CTRL ; 
#define  DA9055_MIC_R_GAIN_STATUS 142 
 int DA9055_MIC_R_MUTE_EN ; 
 int DA9055_MIXIN_L_CTRL ; 
#define  DA9055_MIXIN_L_GAIN_STATUS 141 
 int DA9055_MIXIN_L_MIX_EN ; 
 int DA9055_MIXIN_R_CTRL ; 
#define  DA9055_MIXIN_R_GAIN_STATUS 140 
 int DA9055_MIXIN_R_MIX_EN ; 
 int DA9055_MIXIN_R_SELECT ; 
 int DA9055_MIXOUT_L_CTRL ; 
 int DA9055_MIXOUT_L_MIX_EN ; 
 int DA9055_MIXOUT_R_CTRL ; 
 int DA9055_MIXOUT_R_MIX_EN ; 
 int DA9055_PLL_CTRL ; 
 int DA9055_PLL_EN ; 
 int DA9055_PLL_FRAC_BOT ; 
 int DA9055_PLL_FRAC_TOP ; 
 int DA9055_PLL_INDIV_10_20_MHZ ; 
 int DA9055_PLL_INTEGER ; 
 int DA9055_PLL_SRM_EN ; 
#define  DA9055_PLL_STATUS 139 
 int DA9055_REFERENCES ; 
 int DA9055_SR ; 
 int DA9055_SR_11025 ; 
 int DA9055_SR_12000 ; 
 int DA9055_SR_16000 ; 
 int DA9055_SR_22050 ; 
 int DA9055_SR_32000 ; 
 int DA9055_SR_44100 ; 
 int DA9055_SR_48000 ; 
 int DA9055_SR_8000 ; 
 int DA9055_SR_88200 ; 
 int DA9055_SR_96000 ; 
#define  DA9055_STATUS1 138 
 int DA9055_VMID_EN ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_BIAS_OFF 137 
#define  SND_SOC_BIAS_ON 136 
#define  SND_SOC_BIAS_PREPARE 135 
#define  SND_SOC_BIAS_STANDBY 134 
#define  SND_SOC_DAIFMT_CBM_CFM 133 
#define  SND_SOC_DAIFMT_CBS_CFS 132 
#define  SND_SOC_DAIFMT_DSP_A 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  da9055_dai ; 
 TYPE_3__* da9055_pll_div ; 
 int /*<<< orphan*/  da9055_regmap_config ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct da9055_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct da9055_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct da9055_priv*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct da9055_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int,int) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_put_volsw (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int /*<<< orphan*/  soc_component_dev_da9055 ; 

__attribute__((used)) static int da9055_get_alc_data(struct snd_soc_component *component, u8 reg_val)
{
	int mid_data, top_data;
	int sum = 0;
	u8 iteration;

	for (iteration = 0; iteration < DA9055_ALC_AVG_ITERATIONS;
	     iteration++) {
		/* Select the left or right channel and capture data */
		snd_soc_component_write(component, DA9055_ALC_CIC_OP_LVL_CTRL, reg_val);

		/* Select middle 8 bits for read back from data register */
		snd_soc_component_write(component, DA9055_ALC_CIC_OP_LVL_CTRL,
			      reg_val | DA9055_ALC_DATA_MIDDLE);
		mid_data = snd_soc_component_read32(component, DA9055_ALC_CIC_OP_LVL_DATA);

		/* Select top 8 bits for read back from data register */
		snd_soc_component_write(component, DA9055_ALC_CIC_OP_LVL_CTRL,
			      reg_val | DA9055_ALC_DATA_TOP);
		top_data = snd_soc_component_read32(component, DA9055_ALC_CIC_OP_LVL_DATA);

		sum += ((mid_data << 8) | (top_data << 16));
	}

	return sum / DA9055_ALC_AVG_ITERATIONS;
}

__attribute__((used)) static int da9055_put_alc_sw(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	u8 reg_val, adc_left, adc_right, mic_left, mic_right;
	int avg_left_data, avg_right_data, offset_l, offset_r;

	if (ucontrol->value.integer.value[0]) {
		/*
		 * While enabling ALC (or ALC sync mode), calibration of the DC
		 * offsets must be done first
		 */

		/* Save current values from Mic control registers */
		mic_left = snd_soc_component_read32(component, DA9055_MIC_L_CTRL);
		mic_right = snd_soc_component_read32(component, DA9055_MIC_R_CTRL);

		/* Mute Mic PGA Left and Right */
		snd_soc_component_update_bits(component, DA9055_MIC_L_CTRL,
				    DA9055_MIC_L_MUTE_EN, DA9055_MIC_L_MUTE_EN);
		snd_soc_component_update_bits(component, DA9055_MIC_R_CTRL,
				    DA9055_MIC_R_MUTE_EN, DA9055_MIC_R_MUTE_EN);

		/* Save current values from ADC control registers */
		adc_left = snd_soc_component_read32(component, DA9055_ADC_L_CTRL);
		adc_right = snd_soc_component_read32(component, DA9055_ADC_R_CTRL);

		/* Enable ADC Left and Right */
		snd_soc_component_update_bits(component, DA9055_ADC_L_CTRL,
				    DA9055_ADC_L_EN, DA9055_ADC_L_EN);
		snd_soc_component_update_bits(component, DA9055_ADC_R_CTRL,
				    DA9055_ADC_R_EN, DA9055_ADC_R_EN);

		/* Calculate average for Left and Right data */
		/* Left Data */
		avg_left_data = da9055_get_alc_data(component,
				DA9055_ALC_CIC_OP_CHANNEL_LEFT);
		/* Right Data */
		avg_right_data = da9055_get_alc_data(component,
				 DA9055_ALC_CIC_OP_CHANNEL_RIGHT);

		/* Calculate DC offset */
		offset_l = -avg_left_data;
		offset_r = -avg_right_data;

		reg_val = (offset_l & DA9055_ALC_OFFSET_15_8) >> 8;
		snd_soc_component_write(component, DA9055_ALC_OFFSET_OP2M_L, reg_val);
		reg_val = (offset_l & DA9055_ALC_OFFSET_17_16) >> 16;
		snd_soc_component_write(component, DA9055_ALC_OFFSET_OP2U_L, reg_val);

		reg_val = (offset_r & DA9055_ALC_OFFSET_15_8) >> 8;
		snd_soc_component_write(component, DA9055_ALC_OFFSET_OP2M_R, reg_val);
		reg_val = (offset_r & DA9055_ALC_OFFSET_17_16) >> 16;
		snd_soc_component_write(component, DA9055_ALC_OFFSET_OP2U_R, reg_val);

		/* Restore original values of ADC control registers */
		snd_soc_component_write(component, DA9055_ADC_L_CTRL, adc_left);
		snd_soc_component_write(component, DA9055_ADC_R_CTRL, adc_right);

		/* Restore original values of Mic control registers */
		snd_soc_component_write(component, DA9055_MIC_L_CTRL, mic_left);
		snd_soc_component_write(component, DA9055_MIC_R_CTRL, mic_right);
	}

	return snd_soc_put_volsw(kcontrol, ucontrol);
}

__attribute__((used)) static bool da9055_volatile_register(struct device *dev,
				     unsigned int reg)
{
	switch (reg) {
	case DA9055_STATUS1:
	case DA9055_PLL_STATUS:
	case DA9055_AUX_L_GAIN_STATUS:
	case DA9055_AUX_R_GAIN_STATUS:
	case DA9055_MIC_L_GAIN_STATUS:
	case DA9055_MIC_R_GAIN_STATUS:
	case DA9055_MIXIN_L_GAIN_STATUS:
	case DA9055_MIXIN_R_GAIN_STATUS:
	case DA9055_ADC_L_GAIN_STATUS:
	case DA9055_ADC_R_GAIN_STATUS:
	case DA9055_DAC_L_GAIN_STATUS:
	case DA9055_DAC_R_GAIN_STATUS:
	case DA9055_HP_L_GAIN_STATUS:
	case DA9055_HP_R_GAIN_STATUS:
	case DA9055_LINE_GAIN_STATUS:
	case DA9055_ALC_CIC_OP_LVL_DATA:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int da9055_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct da9055_priv *da9055 = snd_soc_component_get_drvdata(component);
	u8 aif_ctrl, fs;
	u32 sysclk;

	switch (params_width(params)) {
	case 16:
		aif_ctrl = DA9055_AIF_WORD_S16_LE;
		break;
	case 20:
		aif_ctrl = DA9055_AIF_WORD_S20_3LE;
		break;
	case 24:
		aif_ctrl = DA9055_AIF_WORD_S24_LE;
		break;
	case 32:
		aif_ctrl = DA9055_AIF_WORD_S32_LE;
		break;
	default:
		return -EINVAL;
	}

	/* Set AIF format */
	snd_soc_component_update_bits(component, DA9055_AIF_CTRL, DA9055_AIF_WORD_LENGTH_MASK,
			    aif_ctrl);

	switch (params_rate(params)) {
	case 8000:
		fs		= DA9055_SR_8000;
		sysclk		= 3072000;
		break;
	case 11025:
		fs		= DA9055_SR_11025;
		sysclk		= 2822400;
		break;
	case 12000:
		fs		= DA9055_SR_12000;
		sysclk		= 3072000;
		break;
	case 16000:
		fs		= DA9055_SR_16000;
		sysclk		= 3072000;
		break;
	case 22050:
		fs		= DA9055_SR_22050;
		sysclk		= 2822400;
		break;
	case 32000:
		fs		= DA9055_SR_32000;
		sysclk		= 3072000;
		break;
	case 44100:
		fs		= DA9055_SR_44100;
		sysclk		= 2822400;
		break;
	case 48000:
		fs		= DA9055_SR_48000;
		sysclk		= 3072000;
		break;
	case 88200:
		fs		= DA9055_SR_88200;
		sysclk		= 2822400;
		break;
	case 96000:
		fs		= DA9055_SR_96000;
		sysclk		= 3072000;
		break;
	default:
		return -EINVAL;
	}

	if (da9055->mclk_rate) {
		/* PLL Mode, Write actual FS */
		snd_soc_component_write(component, DA9055_SR, fs);
	} else {
		/*
		 * Non-PLL Mode
		 * When PLL is bypassed, chip assumes constant MCLK of
		 * 12.288MHz and uses sample rate value to divide this MCLK
		 * to derive its sys clk. As sys clk has to be 256 * Fs, we
		 * need to write constant sample rate i.e. 48KHz.
		 */
		snd_soc_component_write(component, DA9055_SR, DA9055_SR_48000);
	}

	if (da9055->mclk_rate && (da9055->mclk_rate != sysclk)) {
		/* PLL Mode */
		if (!da9055->master) {
			/* PLL slave mode, enable PLL and also SRM */
			snd_soc_component_update_bits(component, DA9055_PLL_CTRL,
					    DA9055_PLL_EN | DA9055_PLL_SRM_EN,
					    DA9055_PLL_EN | DA9055_PLL_SRM_EN);
		} else {
			/* PLL master mode, only enable PLL */
			snd_soc_component_update_bits(component, DA9055_PLL_CTRL,
					    DA9055_PLL_EN, DA9055_PLL_EN);
		}
	} else {
		/* Non PLL Mode, disable PLL */
		snd_soc_component_update_bits(component, DA9055_PLL_CTRL, DA9055_PLL_EN, 0);
	}

	return 0;
}

__attribute__((used)) static int da9055_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da9055_priv *da9055 = snd_soc_component_get_drvdata(component);
	u8 aif_clk_mode, aif_ctrl, mode;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		/* DA9055 in I2S Master Mode */
		mode = 1;
		aif_clk_mode = DA9055_AIF_CLK_EN_MASTER_MODE;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		/* DA9055 in I2S Slave Mode */
		mode = 0;
		aif_clk_mode = DA9055_AIF_CLK_EN_SLAVE_MODE;
		break;
	default:
		return -EINVAL;
	}

	/* Don't allow change of mode if PLL is enabled */
	if ((snd_soc_component_read32(component, DA9055_PLL_CTRL) & DA9055_PLL_EN) &&
	    (da9055->master != mode))
		return -EINVAL;

	da9055->master = mode;

	/* Only I2S is supported */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		aif_ctrl = DA9055_AIF_FORMAT_I2S_MODE;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		aif_ctrl = DA9055_AIF_FORMAT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		aif_ctrl = DA9055_AIF_FORMAT_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		aif_ctrl = DA9055_AIF_FORMAT_DSP;
		break;
	default:
		return -EINVAL;
	}

	/* By default only 32 BCLK per WCLK is supported */
	aif_clk_mode |= DA9055_AIF_BCLKS_PER_WCLK_32;

	snd_soc_component_update_bits(component, DA9055_AIF_CLK_MODE,
			    (DA9055_AIF_CLK_MODE_MASK | DA9055_AIF_BCLK_MASK),
			    aif_clk_mode);
	snd_soc_component_update_bits(component, DA9055_AIF_CTRL, DA9055_AIF_FORMAT_MASK,
			    aif_ctrl);
	return 0;
}

__attribute__((used)) static int da9055_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;

	if (mute) {
		snd_soc_component_update_bits(component, DA9055_DAC_L_CTRL,
				    DA9055_DAC_L_MUTE_EN, DA9055_DAC_L_MUTE_EN);
		snd_soc_component_update_bits(component, DA9055_DAC_R_CTRL,
				    DA9055_DAC_R_MUTE_EN, DA9055_DAC_R_MUTE_EN);
	} else {
		snd_soc_component_update_bits(component, DA9055_DAC_L_CTRL,
				    DA9055_DAC_L_MUTE_EN, 0);
		snd_soc_component_update_bits(component, DA9055_DAC_R_CTRL,
				    DA9055_DAC_R_MUTE_EN, 0);
	}

	return 0;
}

__attribute__((used)) static int da9055_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da9055_priv *da9055 = snd_soc_component_get_drvdata(component);

	switch (clk_id) {
	case DA9055_CLKSRC_MCLK:
		switch (freq) {
		case 11289600:
		case 12000000:
		case 12288000:
		case 13000000:
		case 13500000:
		case 14400000:
		case 19200000:
		case 19680000:
		case 19800000:
			da9055->mclk_rate = freq;
			return 0;
		default:
			dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
				freq);
			return -EINVAL;
		}
		break;
	default:
		dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
		return -EINVAL;
	}
}

__attribute__((used)) static int da9055_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
			      int source, unsigned int fref, unsigned int fout)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da9055_priv *da9055 = snd_soc_component_get_drvdata(component);

	u8 pll_frac_top, pll_frac_bot, pll_integer, cnt;

	/* Disable PLL before setting the divisors */
	snd_soc_component_update_bits(component, DA9055_PLL_CTRL, DA9055_PLL_EN, 0);

	/* In slave mode, there is only one set of divisors */
	if (!da9055->master && (fout != 2822400))
		goto pll_err;

	/* Search pll div array for correct divisors */
	for (cnt = 0; cnt < ARRAY_SIZE(da9055_pll_div); cnt++) {
		/* Check fref, mode  and fout */
		if ((fref == da9055_pll_div[cnt].fref) &&
		    (da9055->master ==  da9055_pll_div[cnt].mode) &&
		    (fout == da9055_pll_div[cnt].fout)) {
			/* All match, pick up divisors */
			pll_frac_top = da9055_pll_div[cnt].frac_top;
			pll_frac_bot = da9055_pll_div[cnt].frac_bot;
			pll_integer = da9055_pll_div[cnt].integer;
			break;
		}
	}
	if (cnt >= ARRAY_SIZE(da9055_pll_div))
		goto pll_err;

	/* Write PLL dividers */
	snd_soc_component_write(component, DA9055_PLL_FRAC_TOP, pll_frac_top);
	snd_soc_component_write(component, DA9055_PLL_FRAC_BOT, pll_frac_bot);
	snd_soc_component_write(component, DA9055_PLL_INTEGER, pll_integer);

	return 0;
pll_err:
	dev_err(codec_dai->dev, "Error in setting up PLL\n");
	return -EINVAL;
}

__attribute__((used)) static int da9055_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			/* Enable VMID reference & master bias */
			snd_soc_component_update_bits(component, DA9055_REFERENCES,
					    DA9055_VMID_EN | DA9055_BIAS_EN,
					    DA9055_VMID_EN | DA9055_BIAS_EN);
		}
		break;
	case SND_SOC_BIAS_OFF:
		/* Disable VMID reference & master bias */
		snd_soc_component_update_bits(component, DA9055_REFERENCES,
				    DA9055_VMID_EN | DA9055_BIAS_EN, 0);
		break;
	}
	return 0;
}

__attribute__((used)) static int da9055_probe(struct snd_soc_component *component)
{
	struct da9055_priv *da9055 = snd_soc_component_get_drvdata(component);

	/* Enable all Gain Ramps */
	snd_soc_component_update_bits(component, DA9055_AUX_L_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_AUX_R_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_MIXIN_L_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_MIXIN_R_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_ADC_L_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_ADC_R_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_DAC_L_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_DAC_R_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_HP_L_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_HP_R_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
	snd_soc_component_update_bits(component, DA9055_LINE_CTRL,
			    DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);

	/*
	 * There are two separate control bits for input and output mixers.
	 * One to enable corresponding amplifier and other to enable its
	 * output. As amplifier bits are related to power control, they are
	 * being managed by DAPM while other (non power related) bits are
	 * enabled here
	 */
	snd_soc_component_update_bits(component, DA9055_MIXIN_L_CTRL,
			    DA9055_MIXIN_L_MIX_EN, DA9055_MIXIN_L_MIX_EN);
	snd_soc_component_update_bits(component, DA9055_MIXIN_R_CTRL,
			    DA9055_MIXIN_R_MIX_EN, DA9055_MIXIN_R_MIX_EN);

	snd_soc_component_update_bits(component, DA9055_MIXOUT_L_CTRL,
			    DA9055_MIXOUT_L_MIX_EN, DA9055_MIXOUT_L_MIX_EN);
	snd_soc_component_update_bits(component, DA9055_MIXOUT_R_CTRL,
			    DA9055_MIXOUT_R_MIX_EN, DA9055_MIXOUT_R_MIX_EN);

	/* Set this as per your system configuration */
	snd_soc_component_write(component, DA9055_PLL_CTRL, DA9055_PLL_INDIV_10_20_MHZ);

	/* Set platform data values */
	if (da9055->pdata) {
		/* set mic bias source */
		if (da9055->pdata->micbias_source) {
			snd_soc_component_update_bits(component, DA9055_MIXIN_R_SELECT,
					    DA9055_MICBIAS2_EN,
					    DA9055_MICBIAS2_EN);
		} else {
			snd_soc_component_update_bits(component, DA9055_MIXIN_R_SELECT,
					    DA9055_MICBIAS2_EN, 0);
		}
		/* set mic bias voltage */
		switch (da9055->pdata->micbias) {
		case DA9055_MICBIAS_2_2V:
		case DA9055_MICBIAS_2_1V:
		case DA9055_MICBIAS_1_8V:
		case DA9055_MICBIAS_1_6V:
			snd_soc_component_update_bits(component, DA9055_MIC_CONFIG,
					    DA9055_MICBIAS_LEVEL_MASK,
					    (da9055->pdata->micbias) << 4);
			break;
		}
	}
	return 0;
}

__attribute__((used)) static int da9055_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct da9055_priv *da9055;
	struct da9055_platform_data *pdata = dev_get_platdata(&i2c->dev);
	int ret;

	da9055 = devm_kzalloc(&i2c->dev, sizeof(struct da9055_priv),
			      GFP_KERNEL);
	if (!da9055)
		return -ENOMEM;

	if (pdata)
		da9055->pdata = pdata;

	i2c_set_clientdata(i2c, da9055);

	da9055->regmap = devm_regmap_init_i2c(i2c, &da9055_regmap_config);
	if (IS_ERR(da9055->regmap)) {
		ret = PTR_ERR(da9055->regmap);
		dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
		return ret;
	}

	ret = devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_da9055, &da9055_dai, 1);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to register da9055 component: %d\n",
			ret);
	}
	return ret;
}


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
struct snd_soc_dai {int /*<<< orphan*/  dev; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_5__ {scalar_t__* value; } ;
struct TYPE_6__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct device {int dummy; } ;
struct da7210_priv {scalar_t__ mclk_rate; int master; } ;
struct TYPE_7__ {unsigned int fref; scalar_t__ mode; unsigned int fout; int div1; int div2; int div3; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 int /*<<< orphan*/  DA7210_ADC ; 
 int DA7210_ADC_ALC_EN ; 
 int DA7210_ADC_L_EN ; 
 int DA7210_ADC_R_EN ; 
 int /*<<< orphan*/  DA7210_AUX1_L ; 
 int DA7210_AUX1_L_EN ; 
 int DA7210_AUX1_L_VOL ; 
 int DA7210_AUX1_L_ZC ; 
 int DA7210_AUX1_MIN_VOL_NS ; 
 int /*<<< orphan*/  DA7210_AUX1_R ; 
 int DA7210_AUX1_R_EN ; 
 int DA7210_AUX1_R_VOL ; 
 int DA7210_AUX1_R_ZC ; 
 int /*<<< orphan*/  DA7210_AUX2 ; 
 int DA7210_AUX2_EN ; 
#define  DA7210_A_CP_MODE 138 
#define  DA7210_A_HID_UNLOCK 137 
#define  DA7210_A_PLL1 136 
#define  DA7210_A_TEST_UNLOCK 135 
 int DA7210_BIAS_EN ; 
#define  DA7210_CLKSRC_MCLK 134 
 int /*<<< orphan*/  DA7210_CONTROL ; 
 int /*<<< orphan*/  DA7210_DAC_HPF ; 
 int DA7210_DAC_L_EN ; 
 int DA7210_DAC_L_SRC_DAI_L ; 
 int DA7210_DAC_R_EN ; 
 int DA7210_DAC_R_SRC_DAI_R ; 
 int /*<<< orphan*/  DA7210_DAC_SEL ; 
 int /*<<< orphan*/  DA7210_DAI_CFG1 ; 
 int /*<<< orphan*/  DA7210_DAI_CFG3 ; 
 int DA7210_DAI_EN ; 
 scalar_t__ DA7210_DAI_FLEN_64BIT ; 
 scalar_t__ DA7210_DAI_FORMAT_I2SMODE ; 
 scalar_t__ DA7210_DAI_FORMAT_LEFT_J ; 
 scalar_t__ DA7210_DAI_FORMAT_RIGHT_J ; 
 scalar_t__ DA7210_DAI_MODE_MASTER ; 
 scalar_t__ DA7210_DAI_MODE_SLAVE ; 
 int DA7210_DAI_OE ; 
 int DA7210_DAI_OUT_L_SRC ; 
 int DA7210_DAI_OUT_R_SRC ; 
 int /*<<< orphan*/  DA7210_DAI_SRC_SEL ; 
 scalar_t__ DA7210_DAI_WORD_S16_LE ; 
 scalar_t__ DA7210_DAI_WORD_S20_3LE ; 
 scalar_t__ DA7210_DAI_WORD_S24_LE ; 
 scalar_t__ DA7210_DAI_WORD_S32_LE ; 
 int DA7210_HP_2CAP_MODE ; 
 int /*<<< orphan*/  DA7210_HP_CFG ; 
 int DA7210_HP_L_EN ; 
 int DA7210_HP_L_ZC ; 
 int DA7210_HP_MODE ; 
 int DA7210_HP_R_EN ; 
 int DA7210_HP_R_ZC ; 
 int DA7210_HP_SENSE_EN ; 
 int /*<<< orphan*/  DA7210_INMIX_L ; 
 int /*<<< orphan*/  DA7210_INMIX_R ; 
 int DA7210_INPGA_L_VOL ; 
 int DA7210_INPGA_MIN_VOL_NS ; 
 int DA7210_INPGA_R_VOL ; 
 int /*<<< orphan*/  DA7210_IN_GAIN ; 
 int DA7210_IN_L_EN ; 
 int DA7210_IN_R_EN ; 
 int DA7210_MCLK_DET_EN ; 
 int DA7210_MCLK_RANGE_10_20_MHZ ; 
 int DA7210_MCLK_SRM_EN ; 
 int DA7210_MICBIAS_EN ; 
 int /*<<< orphan*/  DA7210_MIC_L ; 
 int DA7210_MIC_L_EN ; 
 int /*<<< orphan*/  DA7210_MIC_R ; 
 int DA7210_MIC_R_EN ; 
 int DA7210_NOISE_SUP_EN ; 
 int /*<<< orphan*/  DA7210_OUT1_L ; 
 int DA7210_OUT1_L_EN ; 
 int /*<<< orphan*/  DA7210_OUT1_R ; 
 int DA7210_OUT1_R_EN ; 
 int /*<<< orphan*/  DA7210_OUT2 ; 
 int DA7210_OUT2_EN ; 
 int DA7210_OUT2_OUTMIX_L ; 
 int DA7210_OUT2_OUTMIX_R ; 
 int /*<<< orphan*/  DA7210_OUTMIX_L ; 
 int /*<<< orphan*/  DA7210_OUTMIX_R ; 
 int DA7210_OUT_L_EN ; 
 int DA7210_OUT_R_EN ; 
 int /*<<< orphan*/  DA7210_PLL ; 
 int DA7210_PLL_BYP ; 
 int /*<<< orphan*/  DA7210_PLL_DIV1 ; 
 int /*<<< orphan*/  DA7210_PLL_DIV2 ; 
 int /*<<< orphan*/  DA7210_PLL_DIV3 ; 
 int DA7210_PLL_DIV_L_MASK ; 
 int DA7210_PLL_EN ; 
 scalar_t__ DA7210_PLL_FS_11025 ; 
 scalar_t__ DA7210_PLL_FS_12000 ; 
 scalar_t__ DA7210_PLL_FS_16000 ; 
 scalar_t__ DA7210_PLL_FS_22050 ; 
 scalar_t__ DA7210_PLL_FS_32000 ; 
 scalar_t__ DA7210_PLL_FS_44100 ; 
 int DA7210_PLL_FS_48000 ; 
 scalar_t__ DA7210_PLL_FS_8000 ; 
 scalar_t__ DA7210_PLL_FS_88200 ; 
 scalar_t__ DA7210_PLL_FS_96000 ; 
 int DA7210_PLL_FS_MASK ; 
 int DA7210_RAMP_EN ; 
 int DA7210_REG_EN ; 
 int DA7210_SC_MST_EN ; 
 int /*<<< orphan*/  DA7210_SOFTMUTE ; 
 int /*<<< orphan*/  DA7210_STARTUP1 ; 
#define  DA7210_STATUS 133 
 int /*<<< orphan*/  DA7210_VERSION ; 
 int /*<<< orphan*/  DA7210_ZERO_CROSS ; 
 int EINVAL ; 
#define  SND_SOC_DAIFMT_CBM_CFM 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
 scalar_t__ SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 scalar_t__ SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 TYPE_3__* da7210_pll_div ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 struct da7210_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_put_volsw (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 

__attribute__((used)) static int da7210_put_alc_sw(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);

	if (ucontrol->value.integer.value[0]) {
		/* Check if noise suppression is enabled */
		if (snd_soc_component_read32(component, DA7210_CONTROL) & DA7210_NOISE_SUP_EN) {
			dev_dbg(component->dev,
				"Disable noise suppression to enable ALC\n");
			return -EINVAL;
		}
	}
	/* If all conditions are met or we are actually disabling ALC */
	return snd_soc_put_volsw(kcontrol, ucontrol);
}

__attribute__((used)) static int da7210_put_noise_sup_sw(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	u8 val;

	if (ucontrol->value.integer.value[0]) {
		/* Check if ALC is enabled */
		if (snd_soc_component_read32(component, DA7210_ADC) & DA7210_ADC_ALC_EN)
			goto err;

		/* Check ZC for HP and AUX1 PGA */
		if ((snd_soc_component_read32(component, DA7210_ZERO_CROSS) &
			(DA7210_AUX1_L_ZC | DA7210_AUX1_R_ZC | DA7210_HP_L_ZC |
			DA7210_HP_R_ZC)) != (DA7210_AUX1_L_ZC |
			DA7210_AUX1_R_ZC | DA7210_HP_L_ZC | DA7210_HP_R_ZC))
			goto err;

		/* Check INPGA_L_VOL and INPGA_R_VOL */
		val = snd_soc_component_read32(component, DA7210_IN_GAIN);
		if (((val & DA7210_INPGA_L_VOL) < DA7210_INPGA_MIN_VOL_NS) ||
			(((val & DA7210_INPGA_R_VOL) >> 4) <
			DA7210_INPGA_MIN_VOL_NS))
			goto err;

		/* Check AUX1_L_VOL and AUX1_R_VOL */
		if (((snd_soc_component_read32(component, DA7210_AUX1_L) & DA7210_AUX1_L_VOL) <
		    DA7210_AUX1_MIN_VOL_NS) ||
		    ((snd_soc_component_read32(component, DA7210_AUX1_R) & DA7210_AUX1_R_VOL) <
		    DA7210_AUX1_MIN_VOL_NS))
			goto err;
	}
	/* If all conditions are met or we are actually disabling Noise sup */
	return snd_soc_put_volsw(kcontrol, ucontrol);

err:
	return -EINVAL;
}

__attribute__((used)) static bool da7210_readable_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA7210_A_HID_UNLOCK:
	case DA7210_A_TEST_UNLOCK:
	case DA7210_A_PLL1:
	case DA7210_A_CP_MODE:
		return false;
	default:
		return true;
	}
}

__attribute__((used)) static bool da7210_volatile_register(struct device *dev,
				    unsigned int reg)
{
	switch (reg) {
	case DA7210_STATUS:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int da7210_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct da7210_priv *da7210 = snd_soc_component_get_drvdata(component);
	u32 dai_cfg1;
	u32 fs, sysclk;

	/* set DAI source to Left and Right ADC */
	snd_soc_component_write(component, DA7210_DAI_SRC_SEL,
		     DA7210_DAI_OUT_R_SRC | DA7210_DAI_OUT_L_SRC);

	/* Enable DAI */
	snd_soc_component_write(component, DA7210_DAI_CFG3, DA7210_DAI_OE | DA7210_DAI_EN);

	dai_cfg1 = 0xFC & snd_soc_component_read32(component, DA7210_DAI_CFG1);

	switch (params_width(params)) {
	case 16:
		dai_cfg1 |= DA7210_DAI_WORD_S16_LE;
		break;
	case 20:
		dai_cfg1 |= DA7210_DAI_WORD_S20_3LE;
		break;
	case 24:
		dai_cfg1 |= DA7210_DAI_WORD_S24_LE;
		break;
	case 32:
		dai_cfg1 |= DA7210_DAI_WORD_S32_LE;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_write(component, DA7210_DAI_CFG1, dai_cfg1);

	switch (params_rate(params)) {
	case 8000:
		fs		= DA7210_PLL_FS_8000;
		sysclk		= 3072000;
		break;
	case 11025:
		fs		= DA7210_PLL_FS_11025;
		sysclk		= 2822400;
		break;
	case 12000:
		fs		= DA7210_PLL_FS_12000;
		sysclk		= 3072000;
		break;
	case 16000:
		fs		= DA7210_PLL_FS_16000;
		sysclk		= 3072000;
		break;
	case 22050:
		fs		= DA7210_PLL_FS_22050;
		sysclk		= 2822400;
		break;
	case 32000:
		fs		= DA7210_PLL_FS_32000;
		sysclk		= 3072000;
		break;
	case 44100:
		fs		= DA7210_PLL_FS_44100;
		sysclk		= 2822400;
		break;
	case 48000:
		fs		= DA7210_PLL_FS_48000;
		sysclk		= 3072000;
		break;
	case 88200:
		fs		= DA7210_PLL_FS_88200;
		sysclk		= 2822400;
		break;
	case 96000:
		fs		= DA7210_PLL_FS_96000;
		sysclk		= 3072000;
		break;
	default:
		return -EINVAL;
	}

	/* Disable active mode */
	snd_soc_component_update_bits(component, DA7210_STARTUP1, DA7210_SC_MST_EN, 0);

	snd_soc_component_update_bits(component, DA7210_PLL, DA7210_PLL_FS_MASK, fs);

	if (da7210->mclk_rate && (da7210->mclk_rate != sysclk)) {
		/* PLL mode, disable PLL bypass */
		snd_soc_component_update_bits(component, DA7210_PLL_DIV3, DA7210_PLL_BYP, 0);

		if (!da7210->master) {
			/* PLL slave mode, also enable SRM */
			snd_soc_component_update_bits(component, DA7210_PLL,
						   (DA7210_MCLK_SRM_EN |
						    DA7210_MCLK_DET_EN),
						   (DA7210_MCLK_SRM_EN |
						    DA7210_MCLK_DET_EN));
		}
	} else {
		/* PLL bypass mode, enable PLL bypass and Auto Detection */
		snd_soc_component_update_bits(component, DA7210_PLL, DA7210_MCLK_DET_EN,
						       DA7210_MCLK_DET_EN);
		snd_soc_component_update_bits(component, DA7210_PLL_DIV3, DA7210_PLL_BYP,
							    DA7210_PLL_BYP);
	}
	/* Enable active mode */
	snd_soc_component_update_bits(component, DA7210_STARTUP1,
			    DA7210_SC_MST_EN, DA7210_SC_MST_EN);

	return 0;
}

__attribute__((used)) static int da7210_set_dai_fmt(struct snd_soc_dai *codec_dai, u32 fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7210_priv *da7210 = snd_soc_component_get_drvdata(component);
	u32 dai_cfg1;
	u32 dai_cfg3;

	dai_cfg1 = 0x7f & snd_soc_component_read32(component, DA7210_DAI_CFG1);
	dai_cfg3 = 0xfc & snd_soc_component_read32(component, DA7210_DAI_CFG3);

	if ((snd_soc_component_read32(component, DA7210_PLL) & DA7210_PLL_EN) &&
		(!(snd_soc_component_read32(component, DA7210_PLL_DIV3) & DA7210_PLL_BYP)))
		return -EINVAL;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		da7210->master = 1;
		dai_cfg1 |= DA7210_DAI_MODE_MASTER;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		da7210->master = 0;
		dai_cfg1 |= DA7210_DAI_MODE_SLAVE;
		break;
	default:
		return -EINVAL;
	}

	/* FIXME
	 *
	 * It support I2S only now
	 */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		dai_cfg3 |= DA7210_DAI_FORMAT_I2SMODE;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		dai_cfg3 |= DA7210_DAI_FORMAT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		dai_cfg3 |= DA7210_DAI_FORMAT_RIGHT_J;
		break;
	default:
		return -EINVAL;
	}

	/* FIXME
	 *
	 * It support 64bit data transmission only now
	 */
	dai_cfg1 |= DA7210_DAI_FLEN_64BIT;

	snd_soc_component_write(component, DA7210_DAI_CFG1, dai_cfg1);
	snd_soc_component_write(component, DA7210_DAI_CFG3, dai_cfg3);

	return 0;
}

__attribute__((used)) static int da7210_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u8 mute_reg = snd_soc_component_read32(component, DA7210_DAC_HPF) & 0xFB;

	if (mute)
		snd_soc_component_write(component, DA7210_DAC_HPF, mute_reg | 0x4);
	else
		snd_soc_component_write(component, DA7210_DAC_HPF, mute_reg);
	return 0;
}

__attribute__((used)) static int da7210_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7210_priv *da7210 = snd_soc_component_get_drvdata(component);

	switch (clk_id) {
	case DA7210_CLKSRC_MCLK:
		switch (freq) {
		case 12000000:
		case 13000000:
		case 13500000:
		case 14400000:
		case 19200000:
		case 19680000:
		case 19800000:
			da7210->mclk_rate = freq;
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

__attribute__((used)) static int da7210_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
			      int source, unsigned int fref, unsigned int fout)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7210_priv *da7210 = snd_soc_component_get_drvdata(component);

	u8 pll_div1, pll_div2, pll_div3, cnt;

	/* In slave mode, there is only one set of divisors */
	if (!da7210->master)
		fout = 2822400;

	/* Search pll div array for correct divisors */
	for (cnt = 0; cnt < ARRAY_SIZE(da7210_pll_div); cnt++) {
		/* check fref, mode  and fout */
		if ((fref == da7210_pll_div[cnt].fref) &&
		    (da7210->master ==  da7210_pll_div[cnt].mode) &&
		    (fout == da7210_pll_div[cnt].fout)) {
			/* all match, pick up divisors */
			pll_div1 = da7210_pll_div[cnt].div1;
			pll_div2 = da7210_pll_div[cnt].div2;
			pll_div3 = da7210_pll_div[cnt].div3;
			break;
		}
	}
	if (cnt >= ARRAY_SIZE(da7210_pll_div))
		goto err;

	/* Disable active mode */
	snd_soc_component_update_bits(component, DA7210_STARTUP1, DA7210_SC_MST_EN, 0);
	/* Write PLL dividers */
	snd_soc_component_write(component, DA7210_PLL_DIV1, pll_div1);
	snd_soc_component_write(component, DA7210_PLL_DIV2, pll_div2);
	snd_soc_component_update_bits(component, DA7210_PLL_DIV3,
				   DA7210_PLL_DIV_L_MASK, pll_div3);

	/* Enable PLL */
	snd_soc_component_update_bits(component, DA7210_PLL, DA7210_PLL_EN, DA7210_PLL_EN);

	/* Enable active mode */
	snd_soc_component_update_bits(component, DA7210_STARTUP1, DA7210_SC_MST_EN,
						    DA7210_SC_MST_EN);
	return 0;
err:
	dev_err(codec_dai->dev, "Unsupported PLL input frequency %d\n", fref);
	return -EINVAL;
}

__attribute__((used)) static int da7210_probe(struct snd_soc_component *component)
{
	struct da7210_priv *da7210 = snd_soc_component_get_drvdata(component);

	dev_info(component->dev, "DA7210 Audio Codec %s\n", DA7210_VERSION);

	da7210->mclk_rate       = 0;    /* This will be set from set_sysclk() */
	da7210->master          = 0;    /* This will be set from set_fmt() */

	/* Enable internal regulator & bias current */
	snd_soc_component_write(component, DA7210_CONTROL, DA7210_REG_EN | DA7210_BIAS_EN);

	/*
	 * ADC settings
	 */

	/* Enable Left & Right MIC PGA and Mic Bias */
	snd_soc_component_write(component, DA7210_MIC_L, DA7210_MIC_L_EN | DA7210_MICBIAS_EN);
	snd_soc_component_write(component, DA7210_MIC_R, DA7210_MIC_R_EN);

	/* Enable Left and Right input PGA */
	snd_soc_component_write(component, DA7210_INMIX_L, DA7210_IN_L_EN);
	snd_soc_component_write(component, DA7210_INMIX_R, DA7210_IN_R_EN);

	/* Enable Left and Right ADC */
	snd_soc_component_write(component, DA7210_ADC, DA7210_ADC_L_EN | DA7210_ADC_R_EN);

	/*
	 * DAC settings
	 */

	/* Enable Left and Right DAC */
	snd_soc_component_write(component, DA7210_DAC_SEL,
		     DA7210_DAC_L_SRC_DAI_L | DA7210_DAC_L_EN |
		     DA7210_DAC_R_SRC_DAI_R | DA7210_DAC_R_EN);

	/* Enable Left and Right out PGA */
	snd_soc_component_write(component, DA7210_OUTMIX_L, DA7210_OUT_L_EN);
	snd_soc_component_write(component, DA7210_OUTMIX_R, DA7210_OUT_R_EN);

	/* Enable Left and Right HeadPhone PGA */
	snd_soc_component_write(component, DA7210_HP_CFG,
		     DA7210_HP_2CAP_MODE | DA7210_HP_SENSE_EN |
		     DA7210_HP_L_EN | DA7210_HP_MODE | DA7210_HP_R_EN);

	/* Enable ramp mode for DAC gain update */
	snd_soc_component_write(component, DA7210_SOFTMUTE, DA7210_RAMP_EN);

	/*
	 * For DA7210 codec, there are two ways to enable/disable analog IOs
	 * and ADC/DAC,
	 * (1) Using "Enable Bit" of register associated with that IO
	 * (or ADC/DAC)
	 *	e.g. Mic Left can be enabled using bit 7 of MIC_L(0x7) reg
	 *
	 * (2) Using "Standby Bit" of STARTUP2 or STARTUP3 register
	 *	e.g. Mic left can be put to STANDBY using bit 0 of STARTUP3(0x5)
	 *
	 * Out of these two methods, the one using STANDBY bits is preferred
	 * way to enable/disable individual blocks. This is because STANDBY
	 * registers are part of system controller which allows system power
	 * up/down in a controlled, pop-free manner. Also, as per application
	 * note of DA7210, STANDBY register bits are only effective if a
	 * particular IO (or ADC/DAC) is already enabled using enable/disable
	 * register bits. Keeping these things in mind, current DAPM
	 * implementation manipulates only STANDBY bits.
	 *
	 * Overall implementation can be outlined as below,
	 *
	 * - "Enable bit" of an IO or ADC/DAC is used to enable it in probe()
	 * - "STANDBY bit" is controlled by DAPM
	 */

	/* Enable Line out amplifiers */
	snd_soc_component_write(component, DA7210_OUT1_L, DA7210_OUT1_L_EN);
	snd_soc_component_write(component, DA7210_OUT1_R, DA7210_OUT1_R_EN);
	snd_soc_component_write(component, DA7210_OUT2, DA7210_OUT2_EN |
		     DA7210_OUT2_OUTMIX_L | DA7210_OUT2_OUTMIX_R);

	/* Enable Aux1 */
	snd_soc_component_write(component, DA7210_AUX1_L, DA7210_AUX1_L_EN);
	snd_soc_component_write(component, DA7210_AUX1_R, DA7210_AUX1_R_EN);
	/* Enable Aux2 */
	snd_soc_component_write(component, DA7210_AUX2, DA7210_AUX2_EN);

	/* Set PLL Master clock range 10-20 MHz, enable PLL bypass */
	snd_soc_component_write(component, DA7210_PLL_DIV3, DA7210_MCLK_RANGE_10_20_MHZ |
					      DA7210_PLL_BYP);

	/* Diable PLL and bypass it */
	snd_soc_component_write(component, DA7210_PLL, DA7210_PLL_FS_48000);

	/* Activate all enabled subsystem */
	snd_soc_component_write(component, DA7210_STARTUP1, DA7210_SC_MST_EN);

	dev_info(component->dev, "DA7210 Audio Codec %s\n", DA7210_VERSION);

	return 0;
}


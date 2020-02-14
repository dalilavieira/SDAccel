#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct ad193x_priv {int type; unsigned int sysclk; struct regmap* regmap; } ;
typedef  enum ad193x_type { ____Placeholder_ad193x_type } ad193x_type ;

/* Variables and functions */
#define  AD1933 139 
#define  AD1934 138 
 unsigned int AD193X_16_CHANNELS ; 
 unsigned int AD193X_2_CHANNELS ; 
 unsigned int AD193X_4_CHANNELS ; 
 unsigned int AD193X_8_CHANNELS ; 
 unsigned int AD193X_ADC_BCLK_INV ; 
 unsigned int AD193X_ADC_BCLK_MASTER ; 
 int AD193X_ADC_CHAN_MASK ; 
 unsigned int AD193X_ADC_CHAN_SHFT ; 
 int /*<<< orphan*/  AD193X_ADC_CTRL0 ; 
 int /*<<< orphan*/  AD193X_ADC_CTRL1 ; 
 int /*<<< orphan*/  AD193X_ADC_CTRL2 ; 
 int AD193X_ADC_FMT_MASK ; 
 unsigned int AD193X_ADC_LCR_MASTER ; 
 unsigned int AD193X_ADC_LEFT_HIGH ; 
 unsigned int AD193X_ADC_SERFMT_AUX ; 
 int AD193X_ADC_SERFMT_MASK ; 
 unsigned int AD193X_ADC_SERFMT_TDM ; 
 int AD193X_ADC_WORD_LEN_MASK ; 
 unsigned int AD193X_DAC_BCLK_INV ; 
 unsigned int AD193X_DAC_BCLK_MASTER ; 
 int AD193X_DAC_CHAN_MASK ; 
 unsigned int AD193X_DAC_CHAN_SHFT ; 
 int /*<<< orphan*/  AD193X_DAC_CHNL_MUTE ; 
 int /*<<< orphan*/  AD193X_DAC_CTRL0 ; 
 int /*<<< orphan*/  AD193X_DAC_CTRL1 ; 
 int /*<<< orphan*/  AD193X_DAC_CTRL2 ; 
 int AD193X_DAC_FMT_MASK ; 
 unsigned int AD193X_DAC_LCR_MASTER ; 
 unsigned int AD193X_DAC_LEFT_HIGH ; 
 int AD193X_DAC_MASTER_MUTE ; 
 int AD193X_DAC_WORD_LEN_MASK ; 
 int AD193X_DAC_WORD_LEN_SHFT ; 
 int /*<<< orphan*/  AD193X_PLL_CLK_CTRL0 ; 
 int /*<<< orphan*/  AD193X_PLL_CLK_CTRL1 ; 
 int AD193X_PLL_INPUT_256 ; 
 int AD193X_PLL_INPUT_384 ; 
 int AD193X_PLL_INPUT_512 ; 
 int AD193X_PLL_INPUT_768 ; 
 int AD193X_PLL_INPUT_MASK ; 
 int ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
#define  SND_SOC_DAIFMT_CBM_CFM 137 
#define  SND_SOC_DAIFMT_CBM_CFS 136 
#define  SND_SOC_DAIFMT_CBS_CFM 135 
#define  SND_SOC_DAIFMT_CBS_CFS 134 
#define  SND_SOC_DAIFMT_DSP_A 133 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 132 
#define  SND_SOC_DAIFMT_IB_IF 131 
#define  SND_SOC_DAIFMT_IB_NF 130 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 129 
#define  SND_SOC_DAIFMT_NB_NF 128 
 int /*<<< orphan*/  ad193x_adc_audio_paths ; 
 int /*<<< orphan*/  ad193x_adc_snd_controls ; 
 int /*<<< orphan*/  ad193x_adc_widgets ; 
 int /*<<< orphan*/  ad193x_dai ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ad193x_priv*) ; 
 struct ad193x_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct ad193x_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  soc_component_dev_ad193x ; 

__attribute__((used)) static inline bool ad193x_has_adc(const struct ad193x_priv *ad193x)
{
	switch (ad193x->type) {
	case AD1933:
	case AD1934:
		return false;
	default:
		break;
	}

	return true;
}

__attribute__((used)) static int ad193x_mute(struct snd_soc_dai *dai, int mute)
{
	struct ad193x_priv *ad193x = snd_soc_component_get_drvdata(dai->component);

	if (mute)
		regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL2,
				    AD193X_DAC_MASTER_MUTE,
				    AD193X_DAC_MASTER_MUTE);
	else
		regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL2,
				    AD193X_DAC_MASTER_MUTE, 0);

	return 0;
}

__attribute__((used)) static int ad193x_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
			       unsigned int rx_mask, int slots, int width)
{
	struct ad193x_priv *ad193x = snd_soc_component_get_drvdata(dai->component);
	unsigned int channels;

	switch (slots) {
	case 2:
		channels = AD193X_2_CHANNELS;
		break;
	case 4:
		channels = AD193X_4_CHANNELS;
		break;
	case 8:
		channels = AD193X_8_CHANNELS;
		break;
	case 16:
		channels = AD193X_16_CHANNELS;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL1,
		AD193X_DAC_CHAN_MASK, channels << AD193X_DAC_CHAN_SHFT);
	if (ad193x_has_adc(ad193x))
		regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL2,
				   AD193X_ADC_CHAN_MASK,
				   channels << AD193X_ADC_CHAN_SHFT);

	return 0;
}

__attribute__((used)) static int ad193x_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct ad193x_priv *ad193x = snd_soc_component_get_drvdata(codec_dai->component);
	unsigned int adc_serfmt = 0;
	unsigned int adc_fmt = 0;
	unsigned int dac_fmt = 0;

	/* At present, the driver only support AUX ADC mode(SND_SOC_DAIFMT_I2S
	 * with TDM) and ADC&DAC TDM mode(SND_SOC_DAIFMT_DSP_A)
	 */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		adc_serfmt |= AD193X_ADC_SERFMT_TDM;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		adc_serfmt |= AD193X_ADC_SERFMT_AUX;
		break;
	default:
		if (ad193x_has_adc(ad193x))
			return -EINVAL;
		break;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF: /* normal bit clock + frame */
		break;
	case SND_SOC_DAIFMT_NB_IF: /* normal bclk + invert frm */
		adc_fmt |= AD193X_ADC_LEFT_HIGH;
		dac_fmt |= AD193X_DAC_LEFT_HIGH;
		break;
	case SND_SOC_DAIFMT_IB_NF: /* invert bclk + normal frm */
		adc_fmt |= AD193X_ADC_BCLK_INV;
		dac_fmt |= AD193X_DAC_BCLK_INV;
		break;
	case SND_SOC_DAIFMT_IB_IF: /* invert bclk + frm */
		adc_fmt |= AD193X_ADC_LEFT_HIGH;
		adc_fmt |= AD193X_ADC_BCLK_INV;
		dac_fmt |= AD193X_DAC_LEFT_HIGH;
		dac_fmt |= AD193X_DAC_BCLK_INV;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM: /* codec clk & frm master */
		adc_fmt |= AD193X_ADC_LCR_MASTER;
		adc_fmt |= AD193X_ADC_BCLK_MASTER;
		dac_fmt |= AD193X_DAC_LCR_MASTER;
		dac_fmt |= AD193X_DAC_BCLK_MASTER;
		break;
	case SND_SOC_DAIFMT_CBS_CFM: /* codec clk slave & frm master */
		adc_fmt |= AD193X_ADC_LCR_MASTER;
		dac_fmt |= AD193X_DAC_LCR_MASTER;
		break;
	case SND_SOC_DAIFMT_CBM_CFS: /* codec clk master & frame slave */
		adc_fmt |= AD193X_ADC_BCLK_MASTER;
		dac_fmt |= AD193X_DAC_BCLK_MASTER;
		break;
	case SND_SOC_DAIFMT_CBS_CFS: /* codec clk & frm slave */
		break;
	default:
		return -EINVAL;
	}

	if (ad193x_has_adc(ad193x)) {
		regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL1,
				   AD193X_ADC_SERFMT_MASK, adc_serfmt);
		regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL2,
				   AD193X_ADC_FMT_MASK, adc_fmt);
	}
	regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL1,
		AD193X_DAC_FMT_MASK, dac_fmt);

	return 0;
}

__attribute__((used)) static int ad193x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ad193x_priv *ad193x = snd_soc_component_get_drvdata(component);
	switch (freq) {
	case 12288000:
	case 18432000:
	case 24576000:
	case 36864000:
		ad193x->sysclk = freq;
		return 0;
	}
	return -EINVAL;
}

__attribute__((used)) static int ad193x_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params,
		struct snd_soc_dai *dai)
{
	int word_len = 0, master_rate = 0;
	struct snd_soc_component *component = dai->component;
	struct ad193x_priv *ad193x = snd_soc_component_get_drvdata(component);

	/* bit size */
	switch (params_width(params)) {
	case 16:
		word_len = 3;
		break;
	case 20:
		word_len = 1;
		break;
	case 24:
	case 32:
		word_len = 0;
		break;
	}

	switch (ad193x->sysclk) {
	case 12288000:
		master_rate = AD193X_PLL_INPUT_256;
		break;
	case 18432000:
		master_rate = AD193X_PLL_INPUT_384;
		break;
	case 24576000:
		master_rate = AD193X_PLL_INPUT_512;
		break;
	case 36864000:
		master_rate = AD193X_PLL_INPUT_768;
		break;
	}

	regmap_update_bits(ad193x->regmap, AD193X_PLL_CLK_CTRL0,
			    AD193X_PLL_INPUT_MASK, master_rate);

	regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL2,
			    AD193X_DAC_WORD_LEN_MASK,
			    word_len << AD193X_DAC_WORD_LEN_SHFT);

	if (ad193x_has_adc(ad193x))
		regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL1,
				   AD193X_ADC_WORD_LEN_MASK, word_len);

	return 0;
}

__attribute__((used)) static int ad193x_component_probe(struct snd_soc_component *component)
{
	struct ad193x_priv *ad193x = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	int num, ret;

	/* default setting for ad193x */

	/* unmute dac channels */
	regmap_write(ad193x->regmap, AD193X_DAC_CHNL_MUTE, 0x0);
	/* de-emphasis: 48kHz, powedown dac */
	regmap_write(ad193x->regmap, AD193X_DAC_CTRL2, 0x1A);
	/* dac in tdm mode */
	regmap_write(ad193x->regmap, AD193X_DAC_CTRL0, 0x40);

	/* adc only */
	if (ad193x_has_adc(ad193x)) {
		/* high-pass filter enable */
		regmap_write(ad193x->regmap, AD193X_ADC_CTRL0, 0x3);
		/* sata delay=1, adc aux mode */
		regmap_write(ad193x->regmap, AD193X_ADC_CTRL1, 0x43);
	}

	/* pll input: mclki/xi */
	regmap_write(ad193x->regmap, AD193X_PLL_CLK_CTRL0, 0x99); /* mclk=24.576Mhz: 0x9D; mclk=12.288Mhz: 0x99 */
	regmap_write(ad193x->regmap, AD193X_PLL_CLK_CTRL1, 0x04);

	/* adc only */
	if (ad193x_has_adc(ad193x)) {
		/* add adc controls */
		num = ARRAY_SIZE(ad193x_adc_snd_controls);
		ret = snd_soc_add_component_controls(component,
						 ad193x_adc_snd_controls,
						 num);
		if (ret)
			return ret;

		/* add adc widgets */
		num = ARRAY_SIZE(ad193x_adc_widgets);
		ret = snd_soc_dapm_new_controls(dapm,
						ad193x_adc_widgets,
						num);
		if (ret)
			return ret;

		/* add adc routes */
		num = ARRAY_SIZE(ad193x_adc_audio_paths);
		ret = snd_soc_dapm_add_routes(dapm,
					      ad193x_adc_audio_paths,
					      num);
		if (ret)
			return ret;
	}

	return 0;
}

int ad193x_probe(struct device *dev, struct regmap *regmap,
		 enum ad193x_type type)
{
	struct ad193x_priv *ad193x;

	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	ad193x = devm_kzalloc(dev, sizeof(*ad193x), GFP_KERNEL);
	if (ad193x == NULL)
		return -ENOMEM;

	ad193x->regmap = regmap;
	ad193x->type = type;

	dev_set_drvdata(dev, ad193x);

	return devm_snd_soc_register_component(dev, &soc_component_dev_ad193x,
		&ad193x_dai, 1);
}


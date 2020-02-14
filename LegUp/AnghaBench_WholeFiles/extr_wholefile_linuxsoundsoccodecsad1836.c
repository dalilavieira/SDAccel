#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct spi_device {int /*<<< orphan*/  dev; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct ad1836_priv {size_t type; int /*<<< orphan*/  regmap; } ;
struct TYPE_7__ {int channels_max; } ;
struct TYPE_6__ {int channels_max; } ;
struct TYPE_9__ {TYPE_2__ capture; TYPE_1__ playback; } ;
struct TYPE_8__ {size_t driver_data; } ;

/* Variables and functions */
 size_t AD1836 ; 
 int /*<<< orphan*/  AD1836_ADC_CTRL1 ; 
 int /*<<< orphan*/  AD1836_ADC_CTRL2 ; 
 int /*<<< orphan*/  AD1836_ADC_CTRL3 ; 
 int /*<<< orphan*/  AD1836_ADC_SERFMT_MASK ; 
 int /*<<< orphan*/  AD1836_ADC_WORD_LEN_MASK ; 
 int AD1836_ADC_WORD_OFFSET ; 
 int /*<<< orphan*/  AD1836_DAC_CTRL1 ; 
 int /*<<< orphan*/  AD1836_DAC_CTRL2 ; 
 int /*<<< orphan*/  AD1836_DAC_L_VOL (int) ; 
 int /*<<< orphan*/  AD1836_DAC_R_VOL (int) ; 
 int /*<<< orphan*/  AD1836_DAC_WORD_LEN_MASK ; 
 int AD1836_DAC_WORD_LEN_OFFSET ; 
 int AD1836_WORD_LEN_16 ; 
 int AD1836_WORD_LEN_20 ; 
 int AD1836_WORD_LEN_24 ; 
 int ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_DAIFMT_CBM_CFM 130 
#define  SND_SOC_DAIFMT_DSP_A 129 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_IB_IF 128 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 int /*<<< orphan*/  ad1836_controls ; 
 int /*<<< orphan*/  ad1836_regmap_config ; 
 int /*<<< orphan*/  ad183x_adc_controls ; 
 int /*<<< orphan*/  ad183x_adc_dapm_widgets ; 
 int /*<<< orphan*/  ad183x_adc_routes ; 
 int /*<<< orphan*/  ad183x_dac_controls ; 
 int /*<<< orphan*/  ad183x_dac_dapm_widgets ; 
 int /*<<< orphan*/  ad183x_dac_routes ; 
 TYPE_4__* ad183x_dais ; 
 struct ad1836_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_spi (struct spi_device*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_4__*,int) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct ad1836_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  soc_component_dev_ad1836 ; 
 TYPE_3__* spi_get_device_id (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct ad1836_priv*) ; 

__attribute__((used)) static int ad1836_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	/* at present, we support adc aux mode to interface with
	 * blackfin sport tdm mode
	 */
	case SND_SOC_DAIFMT_DSP_A:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_IB_IF:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	/* ALCLK,ABCLK are both output, AD1836 can only be master */
	case SND_SOC_DAIFMT_CBM_CFM:
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int ad1836_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params,
		struct snd_soc_dai *dai)
{
	struct ad1836_priv *ad1836 = snd_soc_component_get_drvdata(dai->component);
	int word_len = 0;

	/* bit size */
	switch (params_width(params)) {
	case 16:
		word_len = AD1836_WORD_LEN_16;
		break;
	case 20:
		word_len = AD1836_WORD_LEN_20;
		break;
	case 24:
	case 32:
		word_len = AD1836_WORD_LEN_24;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(ad1836->regmap, AD1836_DAC_CTRL1,
		AD1836_DAC_WORD_LEN_MASK,
		word_len << AD1836_DAC_WORD_LEN_OFFSET);

	regmap_update_bits(ad1836->regmap, AD1836_ADC_CTRL2,
		AD1836_ADC_WORD_LEN_MASK,
		word_len << AD1836_ADC_WORD_OFFSET);

	return 0;
}

__attribute__((used)) static int ad1836_probe(struct snd_soc_component *component)
{
	struct ad1836_priv *ad1836 = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	int num_dacs, num_adcs;
	int ret = 0;
	int i;

	num_dacs = ad183x_dais[ad1836->type].playback.channels_max / 2;
	num_adcs = ad183x_dais[ad1836->type].capture.channels_max / 2;

	/* default setting for ad1836 */
	/* de-emphasis: 48kHz, power-on dac */
	regmap_write(ad1836->regmap, AD1836_DAC_CTRL1, 0x300);
	/* unmute dac channels */
	regmap_write(ad1836->regmap, AD1836_DAC_CTRL2, 0x0);
	/* high-pass filter enable, power-on adc */
	regmap_write(ad1836->regmap, AD1836_ADC_CTRL1, 0x100);
	/* unmute adc channles, adc aux mode */
	regmap_write(ad1836->regmap, AD1836_ADC_CTRL2, 0x180);
	/* volume */
	for (i = 1; i <= num_dacs; ++i) {
		regmap_write(ad1836->regmap, AD1836_DAC_L_VOL(i), 0x3FF);
		regmap_write(ad1836->regmap, AD1836_DAC_R_VOL(i), 0x3FF);
	}

	if (ad1836->type == AD1836) {
		/* left/right diff:PGA/MUX */
		regmap_write(ad1836->regmap, AD1836_ADC_CTRL3, 0x3A);
		ret = snd_soc_add_component_controls(component, ad1836_controls,
				ARRAY_SIZE(ad1836_controls));
		if (ret)
			return ret;
	} else {
		regmap_write(ad1836->regmap, AD1836_ADC_CTRL3, 0x00);
	}

	ret = snd_soc_add_component_controls(component, ad183x_dac_controls, num_dacs * 2);
	if (ret)
		return ret;

	ret = snd_soc_add_component_controls(component, ad183x_adc_controls, num_adcs);
	if (ret)
		return ret;

	ret = snd_soc_dapm_new_controls(dapm, ad183x_dac_dapm_widgets, num_dacs);
	if (ret)
		return ret;

	ret = snd_soc_dapm_new_controls(dapm, ad183x_adc_dapm_widgets, num_adcs);
	if (ret)
		return ret;

	ret = snd_soc_dapm_add_routes(dapm, ad183x_dac_routes, num_dacs);
	if (ret)
		return ret;

	ret = snd_soc_dapm_add_routes(dapm, ad183x_adc_routes, num_adcs);
	if (ret)
		return ret;

	return ret;
}

__attribute__((used)) static void ad1836_remove(struct snd_soc_component *component)
{
	struct ad1836_priv *ad1836 = snd_soc_component_get_drvdata(component);
	/* reset clock control mode */
	regmap_update_bits(ad1836->regmap, AD1836_ADC_CTRL2,
		AD1836_ADC_SERFMT_MASK, 0);
}

__attribute__((used)) static int ad1836_spi_probe(struct spi_device *spi)
{
	struct ad1836_priv *ad1836;
	int ret;

	ad1836 = devm_kzalloc(&spi->dev, sizeof(struct ad1836_priv),
			      GFP_KERNEL);
	if (ad1836 == NULL)
		return -ENOMEM;

	ad1836->regmap = devm_regmap_init_spi(spi, &ad1836_regmap_config);
	if (IS_ERR(ad1836->regmap))
		return PTR_ERR(ad1836->regmap);

	ad1836->type = spi_get_device_id(spi)->driver_data;

	spi_set_drvdata(spi, ad1836);

	ret = devm_snd_soc_register_component(&spi->dev,
			&soc_component_dev_ad1836, &ad183x_dais[ad1836->type], 1);
	return ret;
}


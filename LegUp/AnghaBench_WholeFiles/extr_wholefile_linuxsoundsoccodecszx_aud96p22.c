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
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
struct aud96p22_priv {struct regmap* regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUD96P22_I2S1_CONFIG_0 ; 
 int /*<<< orphan*/  AUD96P22_RESET ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int I2S1_MODE_I2S ; 
 unsigned int I2S1_MODE_LEFT_J ; 
 unsigned int I2S1_MODE_MASK ; 
 unsigned int I2S1_MODE_RIGHT_J ; 
 unsigned int I2S1_MS_MODE ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 unsigned int RST_ADC_DPZ ; 
 unsigned int RST_DAC_DPZ ; 
#define  SND_SOC_DAIFMT_CBM_CFM 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int SND_SOC_DAPM_POST_PMU ; 
 int /*<<< orphan*/  aud96p22_dai ; 
 int /*<<< orphan*/  aud96p22_driver ; 
 int /*<<< orphan*/  aud96p22_regmap ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct aud96p22_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct aud96p22_priv*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct aud96p22_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int aud96p22_adc_event(struct snd_soc_dapm_widget *w,
			      struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct aud96p22_priv *priv = snd_soc_component_get_drvdata(component);
	struct regmap *regmap = priv->regmap;

	if (event != SND_SOC_DAPM_POST_PMU)
		return -EINVAL;

	/* Assert/de-assert the bit to reset ADC data path  */
	regmap_update_bits(regmap, AUD96P22_RESET, RST_ADC_DPZ, 0);
	regmap_update_bits(regmap, AUD96P22_RESET, RST_ADC_DPZ, RST_ADC_DPZ);

	return 0;
}

__attribute__((used)) static int aud96p22_dac_event(struct snd_soc_dapm_widget *w,
			      struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct aud96p22_priv *priv = snd_soc_component_get_drvdata(component);
	struct regmap *regmap = priv->regmap;

	if (event != SND_SOC_DAPM_POST_PMU)
		return -EINVAL;

	/* Assert/de-assert the bit to reset DAC data path  */
	regmap_update_bits(regmap, AUD96P22_RESET, RST_DAC_DPZ, 0);
	regmap_update_bits(regmap, AUD96P22_RESET, RST_DAC_DPZ, RST_DAC_DPZ);

	return 0;
}

__attribute__((used)) static int aud96p22_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct aud96p22_priv *priv = snd_soc_component_get_drvdata(dai->component);
	struct regmap *regmap = priv->regmap;
	unsigned int val;

	/* Master/slave mode */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		val = 0;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		val = I2S1_MS_MODE;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(regmap, AUD96P22_I2S1_CONFIG_0, I2S1_MS_MODE, val);

	/* Audio format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_RIGHT_J:
		val = I2S1_MODE_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_I2S:
		val = I2S1_MODE_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		val = I2S1_MODE_LEFT_J;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(regmap, AUD96P22_I2S1_CONFIG_0, I2S1_MODE_MASK, val);

	return 0;
}

__attribute__((used)) static int aud96p22_i2c_probe(struct i2c_client *i2c,
			      const struct i2c_device_id *id)
{
	struct device *dev = &i2c->dev;
	struct aud96p22_priv *priv;
	int ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (priv == NULL)
		return -ENOMEM;

	priv->regmap = devm_regmap_init_i2c(i2c, &aud96p22_regmap);
	if (IS_ERR(priv->regmap)) {
		ret = PTR_ERR(priv->regmap);
		dev_err(dev, "failed to init i2c regmap: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(i2c, priv);

	ret = devm_snd_soc_register_component(dev, &aud96p22_driver, &aud96p22_dai, 1);
	if (ret) {
		dev_err(dev, "failed to register component: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int aud96p22_i2c_remove(struct i2c_client *i2c)
{
	return 0;
}


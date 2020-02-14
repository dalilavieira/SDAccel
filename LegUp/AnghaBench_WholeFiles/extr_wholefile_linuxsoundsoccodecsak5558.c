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
typedef  int u8 ;
struct snd_soc_dai {struct snd_soc_component* component; int /*<<< orphan*/  dev; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct ak5558_priv {int slot_width; int slots; int /*<<< orphan*/  reset_gpiod; struct i2c_client* i2c; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  AK5558_02_CONTROL1 ; 
 int /*<<< orphan*/  AK5558_03_CONTROL2 ; 
 int AK5558_BITS ; 
 int AK5558_CKS ; 
 int AK5558_CKS_AUTO ; 
 int AK5558_DIF ; 
 int AK5558_DIF_24BIT_MODE ; 
 int AK5558_DIF_32BIT_MODE ; 
 int AK5558_DIF_I2S_MODE ; 
 int AK5558_DIF_MSB_MODE ; 
 int AK5558_MODE_BITS ; 
 int AK5558_MODE_NORMAL ; 
 int AK5558_MODE_TDM128 ; 
 int AK5558_MODE_TDM256 ; 
 int AK5558_MODE_TDM512 ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_DAIFMT_CBM_CFM 134 
#define  SND_SOC_DAIFMT_CBM_CFS 133 
#define  SND_SOC_DAIFMT_CBS_CFM 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
#define  SND_SOC_DAIFMT_DSP_B 130 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
#define  SND_SOC_DAIFMT_LEFT_J 128 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 int /*<<< orphan*/  ak5558_dai ; 
 int /*<<< orphan*/  ak5558_rate_constraints ; 
 int /*<<< orphan*/  ak5558_regmap ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  devm_gpiod_get_optional (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct ak5558_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ak5558_priv*) ; 
 int max (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  params_physical_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct ak5558_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  soc_codec_dev_ak5558 ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int ak5558_set_mcki(struct snd_soc_component *component)
{
	return snd_soc_component_update_bits(component, AK5558_02_CONTROL1, AK5558_CKS,
				   AK5558_CKS_AUTO);
}

__attribute__((used)) static int ak5558_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ak5558_priv *ak5558 = snd_soc_component_get_drvdata(component);
	u8 bits;
	int pcm_width = max(params_physical_width(params), ak5558->slot_width);

	/* set master/slave audio interface */
	bits = snd_soc_component_read32(component, AK5558_02_CONTROL1);
	bits &= ~AK5558_BITS;

	switch (pcm_width) {
	case 16:
		bits |= AK5558_DIF_24BIT_MODE;
		break;
	case 32:
		bits |= AK5558_DIF_32BIT_MODE;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, AK5558_02_CONTROL1, AK5558_BITS, bits);

	return 0;
}

__attribute__((used)) static int ak5558_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	u8 format;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		break;
	case SND_SOC_DAIFMT_CBS_CFM:
	case SND_SOC_DAIFMT_CBM_CFS:
	default:
		dev_err(dai->dev, "Clock mode unsupported");
		return -EINVAL;
	}

	/* set master/slave audio interface */
	format = snd_soc_component_read32(component, AK5558_02_CONTROL1);
	format &= ~AK5558_DIF;

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		format |= AK5558_DIF_I2S_MODE;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		format |= AK5558_DIF_MSB_MODE;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		format |= AK5558_DIF_MSB_MODE;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, AK5558_02_CONTROL1, AK5558_DIF, format);

	return 0;
}

__attribute__((used)) static int ak5558_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
			       unsigned int rx_mask, int slots,
			       int slot_width)
{
	struct snd_soc_component *component = dai->component;
	struct ak5558_priv *ak5558 = snd_soc_component_get_drvdata(component);
	int tdm_mode;

	ak5558->slots = slots;
	ak5558->slot_width = slot_width;

	switch (slots * slot_width) {
	case 128:
		tdm_mode = AK5558_MODE_TDM128;
		break;
	case 256:
		tdm_mode = AK5558_MODE_TDM256;
		break;
	case 512:
		tdm_mode = AK5558_MODE_TDM512;
		break;
	default:
		tdm_mode = AK5558_MODE_NORMAL;
		break;
	}

	snd_soc_component_update_bits(component, AK5558_03_CONTROL2, AK5558_MODE_BITS,
			    tdm_mode);
	return 0;
}

__attribute__((used)) static int ak5558_startup(struct snd_pcm_substream *substream,
			  struct snd_soc_dai *dai)
{
	return snd_pcm_hw_constraint_list(substream->runtime, 0,
					  SNDRV_PCM_HW_PARAM_RATE,
					  &ak5558_rate_constraints);
}

__attribute__((used)) static void ak5558_power_off(struct ak5558_priv *ak5558)
{
	if (!ak5558->reset_gpiod)
		return;

	gpiod_set_value_cansleep(ak5558->reset_gpiod, 0);
	usleep_range(1000, 2000);
}

__attribute__((used)) static void ak5558_power_on(struct ak5558_priv *ak5558)
{
	if (!ak5558->reset_gpiod)
		return;

	gpiod_set_value_cansleep(ak5558->reset_gpiod, 1);
	usleep_range(1000, 2000);
}

__attribute__((used)) static int ak5558_probe(struct snd_soc_component *component)
{
	struct ak5558_priv *ak5558 = snd_soc_component_get_drvdata(component);

	ak5558_power_on(ak5558);
	return ak5558_set_mcki(component);
}

__attribute__((used)) static void ak5558_remove(struct snd_soc_component *component)
{
	struct ak5558_priv *ak5558 = snd_soc_component_get_drvdata(component);

	ak5558_power_off(ak5558);
}

__attribute__((used)) static int ak5558_i2c_probe(struct i2c_client *i2c)
{
	struct ak5558_priv *ak5558;
	int ret = 0;

	ak5558 = devm_kzalloc(&i2c->dev, sizeof(*ak5558), GFP_KERNEL);
	if (!ak5558)
		return -ENOMEM;

	ak5558->regmap = devm_regmap_init_i2c(i2c, &ak5558_regmap);
	if (IS_ERR(ak5558->regmap))
		return PTR_ERR(ak5558->regmap);

	i2c_set_clientdata(i2c, ak5558);
	ak5558->i2c = i2c;

	ak5558->reset_gpiod = devm_gpiod_get_optional(&i2c->dev, "reset",
						      GPIOD_OUT_LOW);
	if (IS_ERR(ak5558->reset_gpiod))
		return PTR_ERR(ak5558->reset_gpiod);

	ret = devm_snd_soc_register_component(&i2c->dev,
				     &soc_codec_dev_ak5558,
				     &ak5558_dai, 1);
	if (ret)
		return ret;

	pm_runtime_enable(&i2c->dev);

	return 0;
}

__attribute__((used)) static int ak5558_i2c_remove(struct i2c_client *i2c)
{
	pm_runtime_disable(&i2c->dev);

	return 0;
}


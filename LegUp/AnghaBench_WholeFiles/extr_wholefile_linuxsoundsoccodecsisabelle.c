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
typedef  unsigned int u16 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 unsigned int BIT (int) ; 
 int EINVAL ; 
 unsigned int ISABELLE_AIF_FMT_MASK ; 
 unsigned int ISABELLE_AIF_LENGTH_20 ; 
 unsigned int ISABELLE_AIF_LENGTH_32 ; 
 unsigned int ISABELLE_AIF_LENGTH_MASK ; 
 unsigned int ISABELLE_AIF_MS ; 
 unsigned int ISABELLE_CHIP_EN ; 
 int /*<<< orphan*/  ISABELLE_DAC1_SOFTRAMP_REG ; 
 int /*<<< orphan*/  ISABELLE_DAC2_SOFTRAMP_REG ; 
 int /*<<< orphan*/  ISABELLE_DAC3_SOFTRAMP_REG ; 
 unsigned int ISABELLE_FS_RATE_11 ; 
 unsigned int ISABELLE_FS_RATE_12 ; 
 unsigned int ISABELLE_FS_RATE_16 ; 
 unsigned int ISABELLE_FS_RATE_22 ; 
 unsigned int ISABELLE_FS_RATE_24 ; 
 unsigned int ISABELLE_FS_RATE_32 ; 
 unsigned int ISABELLE_FS_RATE_44 ; 
 unsigned int ISABELLE_FS_RATE_48 ; 
 unsigned int ISABELLE_FS_RATE_8 ; 
 int /*<<< orphan*/  ISABELLE_FS_RATE_CFG_REG ; 
 unsigned int ISABELLE_FS_RATE_MASK ; 
 unsigned int ISABELLE_I2S_MODE ; 
 int /*<<< orphan*/  ISABELLE_INTF_CFG_REG ; 
 unsigned int ISABELLE_LEFT_J_MODE ; 
 unsigned int ISABELLE_PDM_MODE ; 
 int /*<<< orphan*/  ISABELLE_PWR_EN_REG ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
#define  SND_SOC_BIAS_OFF 136 
#define  SND_SOC_BIAS_ON 135 
#define  SND_SOC_BIAS_PREPARE 134 
#define  SND_SOC_BIAS_STANDBY 133 
#define  SND_SOC_DAIFMT_CBM_CFM 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_PDM 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct regmap*) ; 
 int /*<<< orphan*/  isabelle_dai ; 
 int /*<<< orphan*/  isabelle_regmap_config ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  soc_component_dev_isabelle ; 

__attribute__((used)) static int isabelle_hs_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, ISABELLE_DAC1_SOFTRAMP_REG,
			BIT(4), (mute ? BIT(4) : 0));

	return 0;
}

__attribute__((used)) static int isabelle_hf_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, ISABELLE_DAC2_SOFTRAMP_REG,
			BIT(4), (mute ? BIT(4) : 0));

	return 0;
}

__attribute__((used)) static int isabelle_line_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, ISABELLE_DAC3_SOFTRAMP_REG,
			BIT(4), (mute ? BIT(4) : 0));

	return 0;
}

__attribute__((used)) static int isabelle_set_bias_level(struct snd_soc_component *component,
				enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;

	case SND_SOC_BIAS_STANDBY:
		snd_soc_component_update_bits(component, ISABELLE_PWR_EN_REG,
				ISABELLE_CHIP_EN, BIT(0));
		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, ISABELLE_PWR_EN_REG,
				ISABELLE_CHIP_EN, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int isabelle_hw_params(struct snd_pcm_substream *substream,
			      struct snd_pcm_hw_params *params,
			      struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	u16 aif = 0;
	unsigned int fs_val = 0;

	switch (params_rate(params)) {
	case 8000:
		fs_val = ISABELLE_FS_RATE_8;
		break;
	case 11025:
		fs_val = ISABELLE_FS_RATE_11;
		break;
	case 12000:
		fs_val = ISABELLE_FS_RATE_12;
		break;
	case 16000:
		fs_val = ISABELLE_FS_RATE_16;
		break;
	case 22050:
		fs_val = ISABELLE_FS_RATE_22;
		break;
	case 24000:
		fs_val = ISABELLE_FS_RATE_24;
		break;
	case 32000:
		fs_val = ISABELLE_FS_RATE_32;
		break;
	case 44100:
		fs_val = ISABELLE_FS_RATE_44;
		break;
	case 48000:
		fs_val = ISABELLE_FS_RATE_48;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, ISABELLE_FS_RATE_CFG_REG,
			ISABELLE_FS_RATE_MASK, fs_val);

	/* bit size */
	switch (params_width(params)) {
	case 20:
		aif |= ISABELLE_AIF_LENGTH_20;
		break;
	case 32:
		aif |= ISABELLE_AIF_LENGTH_32;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, ISABELLE_INTF_CFG_REG,
			ISABELLE_AIF_LENGTH_MASK, aif);

	return 0;
}

__attribute__((used)) static int isabelle_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	unsigned int aif_val = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		aif_val &= ~ISABELLE_AIF_MS;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		aif_val |= ISABELLE_AIF_MS;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		aif_val |= ISABELLE_I2S_MODE;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		aif_val |= ISABELLE_LEFT_J_MODE;
		break;
	case SND_SOC_DAIFMT_PDM:
		aif_val |= ISABELLE_PDM_MODE;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, ISABELLE_INTF_CFG_REG,
			(ISABELLE_AIF_MS | ISABELLE_AIF_FMT_MASK), aif_val);

	return 0;
}

__attribute__((used)) static int isabelle_i2c_probe(struct i2c_client *i2c,
			      const struct i2c_device_id *id)
{
	struct regmap *isabelle_regmap;
	int ret = 0;

	isabelle_regmap = devm_regmap_init_i2c(i2c, &isabelle_regmap_config);
	if (IS_ERR(isabelle_regmap)) {
		ret = PTR_ERR(isabelle_regmap);
		dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}
	i2c_set_clientdata(i2c, isabelle_regmap);

	ret = devm_snd_soc_register_component(&i2c->dev,
				&soc_component_dev_isabelle, isabelle_dai,
				ARRAY_SIZE(isabelle_dai));
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to register component: %d\n", ret);
		return ret;
	}

	return ret;
}


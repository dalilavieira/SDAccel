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
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct max98371_priv {int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned int MAX98371_CHANNEL_MASK ; 
 unsigned int MAX98371_DAI_BSEL_32 ; 
 unsigned int MAX98371_DAI_BSEL_48 ; 
 unsigned int MAX98371_DAI_BSEL_64 ; 
 unsigned int MAX98371_DAI_BSEL_MASK ; 
 int /*<<< orphan*/  MAX98371_DAI_CHANNEL ; 
 unsigned int MAX98371_DAI_CHANSZ_16 ; 
 unsigned int MAX98371_DAI_CHANSZ_32 ; 
 int /*<<< orphan*/  MAX98371_DAI_CLK ; 
 unsigned int MAX98371_DAI_LEFT ; 
 unsigned int MAX98371_DAI_RIGHT ; 
 int /*<<< orphan*/  MAX98371_FMT ; 
 unsigned int MAX98371_FMT_MASK ; 
 unsigned int MAX98371_FMT_MODE_MASK ; 
#define  MAX98371_IRQ_CLEAR1 140 
#define  MAX98371_IRQ_CLEAR2 139 
#define  MAX98371_IRQ_CLEAR3 138 
 int /*<<< orphan*/  MAX98371_MONOMIX_SRC ; 
 unsigned int MAX98371_MONOMIX_SRC_MASK ; 
#define  MAX98371_SOFT_RESET 137 
 int /*<<< orphan*/  MAX98371_SPK_SR ; 
 unsigned int MAX98371_SPK_SR_32 ; 
 unsigned int MAX98371_SPK_SR_44 ; 
 unsigned int MAX98371_SPK_SR_48 ; 
 unsigned int MAX98371_SPK_SR_88 ; 
 unsigned int MAX98371_SPK_SR_96 ; 
 unsigned int MAX98371_SPK_SR_MASK ; 
#define  MAX98371_VERSION 136 
 unsigned int MONOMIX_RX_0_1 ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SNDRV_PCM_FORMAT_S16_LE 135 
#define  SNDRV_PCM_FORMAT_S24_LE 134 
#define  SNDRV_PCM_FORMAT_S32_LE 133 
#define  SNDRV_PCM_FORMAT_S8 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 struct max98371_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max98371_priv*) ; 
 int /*<<< orphan*/  max98371_component ; 
 int /*<<< orphan*/  max98371_dai ; 
 int /*<<< orphan*/  max98371_regmap ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int regmap_read (int /*<<< orphan*/ ,int const,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct max98371_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static bool max98371_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX98371_IRQ_CLEAR1:
	case MAX98371_IRQ_CLEAR2:
	case MAX98371_IRQ_CLEAR3:
	case MAX98371_VERSION:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool max98371_readable_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX98371_SOFT_RESET:
		return false;
	default:
		return true;
	}
}

__attribute__((used)) static int max98371_dai_set_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct max98371_priv *max98371 = snd_soc_component_get_drvdata(component);
	unsigned int val = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		dev_err(component->dev, "DAI clock mode unsupported");
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		val |= 0;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		val |= MAX98371_DAI_RIGHT;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		val |= MAX98371_DAI_LEFT;
		break;
	default:
		dev_err(component->dev, "DAI wrong mode unsupported");
		return -EINVAL;
	}
	regmap_update_bits(max98371->regmap, MAX98371_FMT,
			MAX98371_FMT_MODE_MASK, val);
	return 0;
}

__attribute__((used)) static int max98371_dai_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params,
		struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct max98371_priv *max98371 = snd_soc_component_get_drvdata(component);
	int blr_clk_ratio, ch_size, channels = params_channels(params);
	int rate = params_rate(params);

	switch (params_format(params)) {
	case SNDRV_PCM_FORMAT_S8:
		regmap_update_bits(max98371->regmap, MAX98371_FMT,
				MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_16);
		ch_size = 8;
		break;
	case SNDRV_PCM_FORMAT_S16_LE:
		regmap_update_bits(max98371->regmap, MAX98371_FMT,
				MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_16);
		ch_size = 16;
		break;
	case SNDRV_PCM_FORMAT_S24_LE:
		regmap_update_bits(max98371->regmap, MAX98371_FMT,
				MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_32);
		ch_size = 24;
		break;
	case SNDRV_PCM_FORMAT_S32_LE:
		regmap_update_bits(max98371->regmap, MAX98371_FMT,
				MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_32);
		ch_size = 32;
		break;
	default:
		return -EINVAL;
	}

	/* BCLK/LRCLK ratio calculation */
	blr_clk_ratio = channels * ch_size;
	switch (blr_clk_ratio) {
	case 32:
		regmap_update_bits(max98371->regmap,
			MAX98371_DAI_CLK,
			MAX98371_DAI_BSEL_MASK, MAX98371_DAI_BSEL_32);
		break;
	case 48:
		regmap_update_bits(max98371->regmap,
			MAX98371_DAI_CLK,
			MAX98371_DAI_BSEL_MASK, MAX98371_DAI_BSEL_48);
		break;
	case 64:
		regmap_update_bits(max98371->regmap,
			MAX98371_DAI_CLK,
			MAX98371_DAI_BSEL_MASK, MAX98371_DAI_BSEL_64);
		break;
	default:
		return -EINVAL;
	}

	switch (rate) {
	case 32000:
		regmap_update_bits(max98371->regmap,
			MAX98371_SPK_SR,
			MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_32);
		break;
	case 44100:
		regmap_update_bits(max98371->regmap,
			MAX98371_SPK_SR,
			MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_44);
		break;
	case 48000:
		regmap_update_bits(max98371->regmap,
			MAX98371_SPK_SR,
			MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_48);
		break;
	case 88200:
		regmap_update_bits(max98371->regmap,
			MAX98371_SPK_SR,
			MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_88);
		break;
	case 96000:
		regmap_update_bits(max98371->regmap,
			MAX98371_SPK_SR,
			MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_96);
		break;
	default:
		return -EINVAL;
	}

	/* enabling both the RX channels*/
	regmap_update_bits(max98371->regmap, MAX98371_MONOMIX_SRC,
			MAX98371_MONOMIX_SRC_MASK, MONOMIX_RX_0_1);
	regmap_update_bits(max98371->regmap, MAX98371_DAI_CHANNEL,
			MAX98371_CHANNEL_MASK, MAX98371_CHANNEL_MASK);
	return 0;
}

__attribute__((used)) static int max98371_i2c_probe(struct i2c_client *i2c,
		const struct i2c_device_id *id)
{
	struct max98371_priv *max98371;
	int ret, reg;

	max98371 = devm_kzalloc(&i2c->dev,
			sizeof(*max98371), GFP_KERNEL);
	if (!max98371)
		return -ENOMEM;

	i2c_set_clientdata(i2c, max98371);
	max98371->regmap = devm_regmap_init_i2c(i2c, &max98371_regmap);
	if (IS_ERR(max98371->regmap)) {
		ret = PTR_ERR(max98371->regmap);
		dev_err(&i2c->dev,
				"Failed to allocate regmap: %d\n", ret);
		return ret;
	}

	ret = regmap_read(max98371->regmap, MAX98371_VERSION, &reg);
	if (ret < 0) {
		dev_info(&i2c->dev, "device error %d\n", ret);
		return ret;
	}
	dev_info(&i2c->dev, "device version %x\n", reg);

	ret = devm_snd_soc_register_component(&i2c->dev, &max98371_component,
			max98371_dai, ARRAY_SIZE(max98371_dai));
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to register component: %d\n", ret);
		return ret;
	}
	return ret;
}


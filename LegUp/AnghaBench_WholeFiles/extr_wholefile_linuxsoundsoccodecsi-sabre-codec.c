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
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {TYPE_1__* card; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap {int dummy; } ;
struct i_sabre_codec_priv {int fmt; struct regmap* regmap; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
struct TYPE_2__ {struct device* dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  ISABRECODEC_REG_01 138 
#define  ISABRECODEC_REG_02 137 
#define  ISABRECODEC_REG_10 136 
#define  ISABRECODEC_REG_20 135 
#define  ISABRECODEC_REG_21 134 
#define  ISABRECODEC_REG_22 133 
#define  ISABRECODEC_REG_24 132 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 int SND_SOC_DAIFMT_MASTER_MASK ; 
 unsigned int SND_SOC_DAIFMT_NB_NF ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  constraints_slave ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct i_sabre_codec_priv*) ; 
 struct i_sabre_codec_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i_sabre_codec_codec_driver ; 
 int /*<<< orphan*/  i_sabre_codec_dai ; 
 int /*<<< orphan*/  i_sabre_codec_regmap ; 
 int /*<<< orphan*/  params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 int snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct i_sabre_codec_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,int,int) ; 
 int snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (struct device*) ; 

__attribute__((used)) static bool i_sabre_codec_writeable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ISABRECODEC_REG_10:
	case ISABRECODEC_REG_20:
	case ISABRECODEC_REG_21:
	case ISABRECODEC_REG_22:
	case ISABRECODEC_REG_24:
		return true;

	default:
		return false;
	}
}

__attribute__((used)) static bool i_sabre_codec_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ISABRECODEC_REG_01:
	case ISABRECODEC_REG_02:
	case ISABRECODEC_REG_10:
	case ISABRECODEC_REG_20:
	case ISABRECODEC_REG_21:
	case ISABRECODEC_REG_22:
	case ISABRECODEC_REG_24:
		return true;

	default:
		return false;
	}
}

__attribute__((used)) static bool i_sabre_codec_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ISABRECODEC_REG_01:
	case ISABRECODEC_REG_02:
		return true;

	default:
		return false;
	}
}

__attribute__((used)) static int i_sabre_codec_dai_startup_slave(
		struct snd_pcm_substream *substream, struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	int ret;

	ret = snd_pcm_hw_constraint_list(substream->runtime,
			0, SNDRV_PCM_HW_PARAM_RATE, &constraints_slave);
	if (ret != 0) {
		dev_err(component->card->dev, "Failed to setup rates constraints: %d\n", ret);
	}

	return ret;
}

__attribute__((used)) static int i_sabre_codec_dai_startup(
		struct snd_pcm_substream *substream, struct snd_soc_dai *dai)
{
	struct snd_soc_component      *component = dai->component;
	struct i_sabre_codec_priv *i_sabre_codec
					= snd_soc_component_get_drvdata(component);

	switch (i_sabre_codec->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		return i_sabre_codec_dai_startup_slave(substream, dai);

	default:
		return (-EINVAL);
	}
}

__attribute__((used)) static int i_sabre_codec_hw_params(
	struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	struct snd_soc_component      *component = dai->component;
	struct i_sabre_codec_priv *i_sabre_codec
					= snd_soc_component_get_drvdata(component);
	unsigned int daifmt;
	int format_width;

	dev_dbg(component->card->dev, "hw_params %u Hz, %u channels\n",
			params_rate(params), params_channels(params));

	/* Check I2S Format (Bit Size) */
	format_width = snd_pcm_format_width(params_format(params));
	if ((format_width != 32) && (format_width != 16)) {
		dev_err(component->card->dev, "Bad frame size: %d\n",
				snd_pcm_format_width(params_format(params)));
		return (-EINVAL);
	}

	/* Check Slave Mode */
	daifmt = i_sabre_codec->fmt & SND_SOC_DAIFMT_MASTER_MASK;
	if (daifmt != SND_SOC_DAIFMT_CBS_CFS) {
		return (-EINVAL);
	}

	/* Notify Sampling Frequency  */
	switch (params_rate(params))
	{
	case 44100:
	case 48000:
	case 88200:
	case 96000:
	case 176400:
	case 192000:
		snd_soc_component_update_bits(component, ISABRECODEC_REG_10, 0x01, 0x00);
		break;

	case 352800:
	case 384000:
	case 705600:
	case 768000:
	case 1411200:
	case 1536000:
		snd_soc_component_update_bits(component, ISABRECODEC_REG_10, 0x01, 0x01);
		break;
	}

	return 0;
}

__attribute__((used)) static int i_sabre_codec_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component      *component = dai->component;
	struct i_sabre_codec_priv *i_sabre_codec
					= snd_soc_component_get_drvdata(component);

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;

	case SND_SOC_DAIFMT_RIGHT_J:
	case SND_SOC_DAIFMT_LEFT_J:
	default:
		return (-EINVAL);
	}

	/* clock inversion */
	if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF) {
		return (-EINVAL);
	}

	/* Set Audio Data Format */
	i_sabre_codec->fmt = fmt;

	return 0;
}

__attribute__((used)) static int i_sabre_codec_dac_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;

	if (mute) {
		snd_soc_component_update_bits(component, ISABRECODEC_REG_21, 0x01, 0x01);
	} else {
		snd_soc_component_update_bits(component, ISABRECODEC_REG_21, 0x01, 0x00);
	}

	return 0;
}

__attribute__((used)) static int i_sabre_codec_probe(struct device *dev, struct regmap *regmap)
{
	struct i_sabre_codec_priv *i_sabre_codec;
	int ret;

	i_sabre_codec = devm_kzalloc(dev, sizeof(*i_sabre_codec), GFP_KERNEL);
	if (!i_sabre_codec) {
		dev_err(dev, "devm_kzalloc");
		return (-ENOMEM);
	}

	i_sabre_codec->regmap = regmap;

	dev_set_drvdata(dev, i_sabre_codec);

	ret = snd_soc_register_component(dev,
			&i_sabre_codec_codec_driver, &i_sabre_codec_dai, 1);
	if (ret != 0) {
		dev_err(dev, "Failed to register CODEC: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static void i_sabre_codec_remove(struct device *dev)
{
	snd_soc_unregister_component(dev);
}

__attribute__((used)) static int i_sabre_codec_i2c_probe(
		struct i2c_client *i2c, const struct i2c_device_id *id)
{
	struct regmap *regmap;

	regmap = devm_regmap_init_i2c(i2c, &i_sabre_codec_regmap);
	if (IS_ERR(regmap)) {
		return PTR_ERR(regmap);
	}

	return i_sabre_codec_probe(&i2c->dev, regmap);
}

__attribute__((used)) static int i_sabre_codec_i2c_remove(struct i2c_client *i2c)
{
	i_sabre_codec_remove(&i2c->dev);

	return 0;
}


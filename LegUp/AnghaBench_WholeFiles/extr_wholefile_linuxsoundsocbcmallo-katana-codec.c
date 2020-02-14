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
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap_config {int dummy; } ;
struct regmap {int dummy; } ;
struct katana_codec_priv {int fmt; struct regmap* regmap; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
struct TYPE_2__ {struct device* dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int KATANA_CODEC_ALEN_16 ; 
 int KATANA_CODEC_ALEN_24 ; 
 int KATANA_CODEC_ALEN_32 ; 
 int KATANA_CODEC_CHAN_MONO ; 
 int KATANA_CODEC_CHAN_STEREO ; 
 unsigned int KATANA_CODEC_CHIP_ID ; 
#define  KATANA_CODEC_CHIP_ID_REG 130 
 int /*<<< orphan*/  KATANA_CODEC_FORMAT ; 
 int /*<<< orphan*/  KATANA_CODEC_MUTE_STREAM ; 
 int KATANA_CODEC_RATE_176400 ; 
 int KATANA_CODEC_RATE_192000 ; 
 int KATANA_CODEC_RATE_352800 ; 
 int KATANA_CODEC_RATE_384000 ; 
 int KATANA_CODEC_RATE_44100 ; 
 int KATANA_CODEC_RATE_48000 ; 
 int KATANA_CODEC_RATE_88200 ; 
 int KATANA_CODEC_RATE_96000 ; 
 int /*<<< orphan*/  KATANA_CODEC_RESET ; 
 int PTR_ERR (struct regmap*) ; 
#define  SND_SOC_DAIFMT_CBM_CFM 129 
#define  SND_SOC_DAIFMT_CBS_CFS 128 
 int SND_SOC_DAIFMT_MASTER_MASK ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct katana_codec_priv*) ; 
 struct katana_codec_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,struct regmap_config*) ; 
 int /*<<< orphan*/  katana_codec_component_driver ; 
 int /*<<< orphan*/  katana_codec_dai ; 
 struct regmap_config katana_codec_regmap ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int regmap_read (struct regmap*,int const,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 struct katana_codec_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (struct device*) ; 

__attribute__((used)) static bool katana_codec_readable_register(struct device *dev,
				unsigned int reg)
{
	switch (reg) {
	case KATANA_CODEC_CHIP_ID_REG:
		return true;
	default:
		return reg < 0xff;
	}
}

__attribute__((used)) static int katana_codec_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct katana_codec_priv *katana_codec =
		snd_soc_component_get_drvdata(component);
	int fmt = 0;
	int ret;

	dev_dbg(component->card->dev, "hw_params %u Hz, %u channels, %u bits\n",
			params_rate(params),
			params_channels(params),
			params_width(params));

	switch (katana_codec->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM: // master
		if (params_channels(params) == 2)
			fmt = KATANA_CODEC_CHAN_STEREO;
		else
			fmt = KATANA_CODEC_CHAN_MONO;

		switch (params_width(params)) {
		case 16:
			fmt |= KATANA_CODEC_ALEN_16;
			break;
		case 24:
			fmt |= KATANA_CODEC_ALEN_24;
			break;
		case 32:
			fmt |= KATANA_CODEC_ALEN_32;
			break;
		default:
			dev_err(component->card->dev, "Bad frame size: %d\n",
					params_width(params));
			return -EINVAL;
		}

		switch (params_rate(params)) {
		case 44100:
			fmt |= KATANA_CODEC_RATE_44100;
			break;
		case 48000:
			fmt |= KATANA_CODEC_RATE_48000;
			break;
		case 88200:
			fmt |= KATANA_CODEC_RATE_88200;
			break;
		case 96000:
			fmt |= KATANA_CODEC_RATE_96000;
			break;
		case 176400:
			fmt |= KATANA_CODEC_RATE_176400;
			break;
		case 192000:
			fmt |= KATANA_CODEC_RATE_192000;
			break;
		case 352800:
			fmt |= KATANA_CODEC_RATE_352800;
			break;
		case 384000:
			fmt |= KATANA_CODEC_RATE_384000;
			break;
		default:
			dev_err(component->card->dev, "Bad sample rate: %d\n",
					params_rate(params));
			return -EINVAL;
		}

		ret = regmap_write(katana_codec->regmap, KATANA_CODEC_FORMAT,
					fmt);
		if (ret != 0) {
			dev_err(component->card->dev, "Failed to set format: %d\n", ret);
			return ret;
		}
		break;

	case SND_SOC_DAIFMT_CBS_CFS:
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int katana_codec_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct katana_codec_priv *katana_codec =
		snd_soc_component_get_drvdata(component);

	katana_codec->fmt = fmt;

	return 0;
}

int katana_codec_dai_mute_stream(struct snd_soc_dai *dai, int mute,
						int stream)
{
	struct snd_soc_component *component = dai->component;
	struct katana_codec_priv *katana_codec =
		snd_soc_component_get_drvdata(component);
	int ret = 0;

	ret = regmap_write(katana_codec->regmap, KATANA_CODEC_MUTE_STREAM,
				mute);
	if (ret != 0) {
		dev_err(component->card->dev, "Failed to set mute: %d\n", ret);
		return ret;
	}
	return ret;
}

__attribute__((used)) static int allo_katana_component_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	struct regmap *regmap;
	struct regmap_config config = katana_codec_regmap;
	struct device *dev = &i2c->dev;
	struct katana_codec_priv *katana_codec;
	unsigned int chip_id = 0;
	int ret;

	regmap = devm_regmap_init_i2c(i2c, &config);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	katana_codec = devm_kzalloc(dev, sizeof(struct katana_codec_priv),
					GFP_KERNEL);
	if (!katana_codec)
		return -ENOMEM;

	dev_set_drvdata(dev, katana_codec);
	katana_codec->regmap = regmap;

	ret = regmap_read(regmap, KATANA_CODEC_CHIP_ID_REG, &chip_id);
	if ((ret != 0) || (chip_id != KATANA_CODEC_CHIP_ID)) {
		dev_err(dev, "Failed to read Chip or wrong Chip id: %d\n", ret);
		return ret;
	}
	regmap_update_bits(regmap, KATANA_CODEC_RESET, 0x01, 0x01);
	msleep(10);

	ret = snd_soc_register_component(dev, &katana_codec_component_driver,
				    &katana_codec_dai, 1);
	if (ret != 0) {
		dev_err(dev, "failed to register codec: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int allo_katana_component_remove(struct i2c_client *i2c)
{
	snd_soc_unregister_component(&i2c->dev);
	return 0;
}


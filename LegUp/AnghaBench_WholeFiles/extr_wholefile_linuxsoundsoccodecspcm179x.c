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
struct regmap {int dummy; } ;
struct pcm179x_private {unsigned int format; struct regmap* regmap; int /*<<< orphan*/  rate; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PCM179X_ATLD_ENABLE ; 
 int /*<<< orphan*/  PCM179X_FMT_CONTROL ; 
 int PCM179X_FMT_MASK ; 
 int PCM179X_FMT_SHIFT ; 
 int PCM179X_MUTE_MASK ; 
 int /*<<< orphan*/  PCM179X_SOFT_MUTE ; 
 int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct pcm179x_private*) ; 
 struct pcm179x_private* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pcm179x_dai ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 struct pcm179x_private* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  soc_component_dev_pcm179x ; 

__attribute__((used)) static bool pcm179x_accessible_reg(struct device *dev, unsigned int reg)
{
	return reg >= 0x10 && reg <= 0x17;
}

__attribute__((used)) static bool pcm179x_writeable_reg(struct device *dev, unsigned int reg)
{
	bool accessible;

	accessible = pcm179x_accessible_reg(dev, reg);

	return accessible && reg != 0x16 && reg != 0x17;
}

__attribute__((used)) static int pcm179x_set_dai_fmt(struct snd_soc_dai *codec_dai,
                             unsigned int format)
{
	struct snd_soc_component *component = codec_dai->component;
	struct pcm179x_private *priv = snd_soc_component_get_drvdata(component);

	priv->format = format;

	return 0;
}

__attribute__((used)) static int pcm179x_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct pcm179x_private *priv = snd_soc_component_get_drvdata(component);
	int ret;

	ret = regmap_update_bits(priv->regmap, PCM179X_SOFT_MUTE,
				 PCM179X_MUTE_MASK, !!mute);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int pcm179x_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm179x_private *priv = snd_soc_component_get_drvdata(component);
	int val = 0, ret;

	priv->rate = params_rate(params);

	switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_RIGHT_J:
		switch (params_width(params)) {
		case 24:
		case 32:
			val = 2;
			break;
		case 16:
			val = 0;
			break;
		default:
			return -EINVAL;
		}
		break;
	case SND_SOC_DAIFMT_I2S:
		switch (params_width(params)) {
		case 24:
		case 32:
			val = 5;
			break;
		case 16:
			val = 4;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		dev_err(component->dev, "Invalid DAI format\n");
		return -EINVAL;
	}

	val = val << PCM179X_FMT_SHIFT | PCM179X_ATLD_ENABLE;

	ret = regmap_update_bits(priv->regmap, PCM179X_FMT_CONTROL,
				 PCM179X_FMT_MASK | PCM179X_ATLD_ENABLE, val);
	if (ret < 0)
		return ret;

	return 0;
}

int pcm179x_common_init(struct device *dev, struct regmap *regmap)
{
	struct pcm179x_private *pcm179x;

	pcm179x = devm_kzalloc(dev, sizeof(struct pcm179x_private),
				GFP_KERNEL);
	if (!pcm179x)
		return -ENOMEM;

	pcm179x->regmap = regmap;
	dev_set_drvdata(dev, pcm179x);

	return devm_snd_soc_register_component(dev,
			&soc_component_dev_pcm179x, &pcm179x_dai, 1);
}


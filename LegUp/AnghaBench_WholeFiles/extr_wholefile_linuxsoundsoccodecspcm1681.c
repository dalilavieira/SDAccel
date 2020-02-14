#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct pcm1681_private {scalar_t__ rate; unsigned int format; int /*<<< orphan*/  regmap; scalar_t__ deemph; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCM1681_DEEMPH_CONTROL ; 
 int PCM1681_DEEMPH_MASK ; 
 int PCM1681_DEEMPH_RATE_MASK ; 
 int /*<<< orphan*/  PCM1681_FMT_CONTROL ; 
 int /*<<< orphan*/  PCM1681_SOFT_MUTE ; 
 int PCM1681_SOFT_MUTE_ALL ; 
 unsigned int PCM1681_ZERO_DETECT_STATUS ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned int SND_SOC_DAIFMT_CBS_CFS ; 
 int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct pcm1681_private* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct pcm1681_private*) ; 
 scalar_t__ params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pcm1681_dai ; 
 scalar_t__* pcm1681_deemph ; 
 int /*<<< orphan*/  pcm1681_regmap ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct pcm1681_private* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  soc_component_dev_pcm1681 ; 

__attribute__((used)) static bool pcm1681_accessible_reg(struct device *dev, unsigned int reg)
{
	return !((reg == 0x00) || (reg == 0x0f));
}

__attribute__((used)) static bool pcm1681_writeable_reg(struct device *dev, unsigned int reg)
{
	return pcm1681_accessible_reg(dev, reg) &&
		(reg != PCM1681_ZERO_DETECT_STATUS);
}

__attribute__((used)) static int pcm1681_set_deemph(struct snd_soc_component *component)
{
	struct pcm1681_private *priv = snd_soc_component_get_drvdata(component);
	int i = 0, val = -1, enable = 0;

	if (priv->deemph) {
		for (i = 0; i < ARRAY_SIZE(pcm1681_deemph); i++) {
			if (pcm1681_deemph[i] == priv->rate) {
				val = i;
				break;
			}
		}
	}

	if (val != -1) {
		regmap_update_bits(priv->regmap, PCM1681_DEEMPH_CONTROL,
				   PCM1681_DEEMPH_RATE_MASK, val << 3);
		enable = 1;
	} else {
		enable = 0;
	}

	/* enable/disable deemphasis functionality */
	return regmap_update_bits(priv->regmap, PCM1681_DEEMPH_CONTROL,
					PCM1681_DEEMPH_MASK, enable);
}

__attribute__((used)) static int pcm1681_get_deemph(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm1681_private *priv = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = priv->deemph;

	return 0;
}

__attribute__((used)) static int pcm1681_put_deemph(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm1681_private *priv = snd_soc_component_get_drvdata(component);

	priv->deemph = ucontrol->value.integer.value[0];

	return pcm1681_set_deemph(component);
}

__attribute__((used)) static int pcm1681_set_dai_fmt(struct snd_soc_dai *codec_dai,
			      unsigned int format)
{
	struct snd_soc_component *component = codec_dai->component;
	struct pcm1681_private *priv = snd_soc_component_get_drvdata(component);

	/* The PCM1681 can only be slave to all clocks */
	if ((format & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
		dev_err(component->dev, "Invalid clocking mode\n");
		return -EINVAL;
	}

	priv->format = format;

	return 0;
}

__attribute__((used)) static int pcm1681_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct pcm1681_private *priv = snd_soc_component_get_drvdata(component);
	int val;

	if (mute)
		val = PCM1681_SOFT_MUTE_ALL;
	else
		val = 0;

	return regmap_write(priv->regmap, PCM1681_SOFT_MUTE, val);
}

__attribute__((used)) static int pcm1681_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm1681_private *priv = snd_soc_component_get_drvdata(component);
	int val = 0, ret;

	priv->rate = params_rate(params);

	switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_RIGHT_J:
		switch (params_width(params)) {
		case 24:
			val = 0;
			break;
		case 16:
			val = 3;
			break;
		default:
			return -EINVAL;
		}
		break;
	case SND_SOC_DAIFMT_I2S:
		val = 0x04;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		val = 0x05;
		break;
	default:
		dev_err(component->dev, "Invalid DAI format\n");
		return -EINVAL;
	}

	ret = regmap_update_bits(priv->regmap, PCM1681_FMT_CONTROL, 0x0f, val);
	if (ret < 0)
		return ret;

	return pcm1681_set_deemph(component);
}

__attribute__((used)) static int pcm1681_i2c_probe(struct i2c_client *client,
			      const struct i2c_device_id *id)
{
	int ret;
	struct pcm1681_private *priv;

	priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->regmap = devm_regmap_init_i2c(client, &pcm1681_regmap);
	if (IS_ERR(priv->regmap)) {
		ret = PTR_ERR(priv->regmap);
		dev_err(&client->dev, "Failed to create regmap: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(client, priv);

	return devm_snd_soc_register_component(&client->dev,
		&soc_component_dev_pcm1681,
		&pcm1681_dai, 1);
}


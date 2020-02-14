#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tfa9879_priv {int lsb_justified; int /*<<< orphan*/  regmap; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  def; int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_DAIFMT_CBS_CFS 133 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 132 
#define  SND_SOC_DAIFMT_IB_NF 131 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 130 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int TFA9879_I2S_FS_11025 ; 
 int TFA9879_I2S_FS_12000 ; 
 int TFA9879_I2S_FS_16000 ; 
 int TFA9879_I2S_FS_22050 ; 
 int TFA9879_I2S_FS_24000 ; 
 int TFA9879_I2S_FS_32000 ; 
 int TFA9879_I2S_FS_44100 ; 
 int TFA9879_I2S_FS_48000 ; 
 int TFA9879_I2S_FS_64000 ; 
 int TFA9879_I2S_FS_8000 ; 
 int TFA9879_I2S_FS_88200 ; 
 int TFA9879_I2S_FS_96000 ; 
 int /*<<< orphan*/  TFA9879_I2S_FS_MASK ; 
 int TFA9879_I2S_FS_SHIFT ; 
 int TFA9879_I2S_SET_I2S_24 ; 
 int TFA9879_I2S_SET_LSB_J_16 ; 
 int TFA9879_I2S_SET_LSB_J_24 ; 
 int /*<<< orphan*/  TFA9879_I2S_SET_MASK ; 
 int TFA9879_I2S_SET_MSB_J_24 ; 
 int TFA9879_I2S_SET_SHIFT ; 
 int /*<<< orphan*/  TFA9879_MISC_CONTROL ; 
 unsigned int TFA9879_MISC_STATUS ; 
 int TFA9879_SCK_POL_INVERSE ; 
 int /*<<< orphan*/  TFA9879_SCK_POL_MASK ; 
 int TFA9879_SCK_POL_NORMAL ; 
 int TFA9879_SCK_POL_SHIFT ; 
 int /*<<< orphan*/  TFA9879_SERIAL_INTERFACE_1 ; 
 int /*<<< orphan*/  TFA9879_S_MUTE_MASK ; 
 int TFA9879_S_MUTE_SHIFT ; 
 struct tfa9879_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tfa9879_priv*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct tfa9879_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  tfa9879_component ; 
 int /*<<< orphan*/  tfa9879_dai ; 
 int /*<<< orphan*/  tfa9879_regmap ; 
 TYPE_1__* tfa9879_regs ; 

__attribute__((used)) static int tfa9879_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct tfa9879_priv *tfa9879 = snd_soc_component_get_drvdata(component);
	int fs;
	int i2s_set = 0;

	switch (params_rate(params)) {
	case 8000:
		fs = TFA9879_I2S_FS_8000;
		break;
	case 11025:
		fs = TFA9879_I2S_FS_11025;
		break;
	case 12000:
		fs = TFA9879_I2S_FS_12000;
		break;
	case 16000:
		fs = TFA9879_I2S_FS_16000;
		break;
	case 22050:
		fs = TFA9879_I2S_FS_22050;
		break;
	case 24000:
		fs = TFA9879_I2S_FS_24000;
		break;
	case 32000:
		fs = TFA9879_I2S_FS_32000;
		break;
	case 44100:
		fs = TFA9879_I2S_FS_44100;
		break;
	case 48000:
		fs = TFA9879_I2S_FS_48000;
		break;
	case 64000:
		fs = TFA9879_I2S_FS_64000;
		break;
	case 88200:
		fs = TFA9879_I2S_FS_88200;
		break;
	case 96000:
		fs = TFA9879_I2S_FS_96000;
		break;
	default:
		return -EINVAL;
	}

	switch (params_width(params)) {
	case 16:
		i2s_set = TFA9879_I2S_SET_LSB_J_16;
		break;
	case 24:
		i2s_set = TFA9879_I2S_SET_LSB_J_24;
		break;
	default:
		return -EINVAL;
	}

	if (tfa9879->lsb_justified)
		snd_soc_component_update_bits(component,
					      TFA9879_SERIAL_INTERFACE_1,
					      TFA9879_I2S_SET_MASK,
					      i2s_set << TFA9879_I2S_SET_SHIFT);

	snd_soc_component_update_bits(component, TFA9879_SERIAL_INTERFACE_1,
				      TFA9879_I2S_FS_MASK,
				      fs << TFA9879_I2S_FS_SHIFT);
	return 0;
}

__attribute__((used)) static int tfa9879_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;

	snd_soc_component_update_bits(component, TFA9879_MISC_CONTROL,
				      TFA9879_S_MUTE_MASK,
				      !!mute << TFA9879_S_MUTE_SHIFT);

	return 0;
}

__attribute__((used)) static int tfa9879_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct tfa9879_priv *tfa9879 = snd_soc_component_get_drvdata(component);
	int i2s_set;
	int sck_pol;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		sck_pol = TFA9879_SCK_POL_NORMAL;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		sck_pol = TFA9879_SCK_POL_INVERSE;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		tfa9879->lsb_justified = 0;
		i2s_set = TFA9879_I2S_SET_I2S_24;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		tfa9879->lsb_justified = 0;
		i2s_set = TFA9879_I2S_SET_MSB_J_24;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		tfa9879->lsb_justified = 1;
		i2s_set = TFA9879_I2S_SET_LSB_J_24;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, TFA9879_SERIAL_INTERFACE_1,
				      TFA9879_SCK_POL_MASK,
				      sck_pol << TFA9879_SCK_POL_SHIFT);
	snd_soc_component_update_bits(component, TFA9879_SERIAL_INTERFACE_1,
				      TFA9879_I2S_SET_MASK,
				      i2s_set << TFA9879_I2S_SET_SHIFT);
	return 0;
}

__attribute__((used)) static bool tfa9879_volatile_reg(struct device *dev, unsigned int reg)
{
	return reg == TFA9879_MISC_STATUS;
}

__attribute__((used)) static int tfa9879_i2c_probe(struct i2c_client *i2c)
{
	struct tfa9879_priv *tfa9879;
	int i;

	tfa9879 = devm_kzalloc(&i2c->dev, sizeof(*tfa9879), GFP_KERNEL);
	if (!tfa9879)
		return -ENOMEM;

	i2c_set_clientdata(i2c, tfa9879);

	tfa9879->regmap = devm_regmap_init_i2c(i2c, &tfa9879_regmap);
	if (IS_ERR(tfa9879->regmap))
		return PTR_ERR(tfa9879->regmap);

	/* Ensure the device is in reset state */
	for (i = 0; i < ARRAY_SIZE(tfa9879_regs); i++)
		regmap_write(tfa9879->regmap,
			     tfa9879_regs[i].reg, tfa9879_regs[i].def);

	return devm_snd_soc_register_component(&i2c->dev, &tfa9879_component,
					       &tfa9879_dai, 1);
}


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
typedef  int u8 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/ * dev; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {int* item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct ak4458_priv {int digfil; int slot_width; int fs; int fmt; int slots; int /*<<< orphan*/ * dev; void* mute_gpiod; void* reset_gpiod; void* regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  AK4458_00_CONTROL1 ; 
 int /*<<< orphan*/  AK4458_01_CONTROL2 ; 
 int /*<<< orphan*/  AK4458_02_CONTROL3 ; 
 int /*<<< orphan*/  AK4458_05_CONTROL4 ; 
 int /*<<< orphan*/  AK4458_0A_CONTROL6 ; 
 int /*<<< orphan*/  AK4458_0B_CONTROL7 ; 
 int AK4458_ATS_MASK ; 
 int AK4458_ATS_SHIFT ; 
 int AK4458_DIF_16BIT_LSB ; 
 int AK4458_DIF_24BIT_I2S ; 
 int AK4458_DIF_32BIT_I2S ; 
 int AK4458_DIF_32BIT_LSB ; 
 int AK4458_DIF_32BIT_MSB ; 
 int AK4458_DIF_MASK ; 
 int AK4458_MODE_MASK ; 
 int AK4458_MODE_NORMAL ; 
 int AK4458_MODE_TDM128 ; 
 int AK4458_MODE_TDM256 ; 
 int AK4458_MODE_TDM512 ; 
 int AK4458_RSTN_MASK ; 
 int AK4458_SD_MASK ; 
 int AK4458_SLOW_MASK ; 
 int AK4458_SSLOW_MASK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_DAIFMT_CBM_CFM 135 
#define  SND_SOC_DAIFMT_CBM_CFS 134 
#define  SND_SOC_DAIFMT_CBS_CFM 133 
#define  SND_SOC_DAIFMT_CBS_CFS 132 
#define  SND_SOC_DAIFMT_DSP_B 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  ak4458_dai ; 
 int /*<<< orphan*/  ak4458_rate_constraints ; 
 int /*<<< orphan*/  ak4458_regmap ; 
 int* att_speed ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 void* devm_gpiod_get_optional (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct ak4458_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ak4458_priv*) ; 
 int max (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  params_physical_width (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct ak4458_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  soc_codec_dev_ak4458 ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int get_digfil(struct snd_kcontrol *kcontrol,
		      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);

	ucontrol->value.enumerated.item[0] = ak4458->digfil;

	return 0;
}

__attribute__((used)) static int set_digfil(struct snd_kcontrol *kcontrol,
		      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);
	int num;

	num = ucontrol->value.enumerated.item[0];
	if (num > 4)
		return -EINVAL;

	ak4458->digfil = num;

	/* write SD bit */
	snd_soc_component_update_bits(component, AK4458_01_CONTROL2,
			    AK4458_SD_MASK,
			    ((ak4458->digfil & 0x02) << 4));

	/* write SLOW bit */
	snd_soc_component_update_bits(component, AK4458_02_CONTROL3,
			    AK4458_SLOW_MASK,
			    (ak4458->digfil & 0x01));

	/* write SSLOW bit */
	snd_soc_component_update_bits(component, AK4458_05_CONTROL4,
			    AK4458_SSLOW_MASK,
			    ((ak4458->digfil & 0x04) >> 2));

	return 0;
}

__attribute__((used)) static int ak4458_rstn_control(struct snd_soc_component *component, int bit)
{
	int ret;

	if (bit)
		ret = snd_soc_component_update_bits(component,
					  AK4458_00_CONTROL1,
					  AK4458_RSTN_MASK,
					  0x1);
	else
		ret = snd_soc_component_update_bits(component,
					  AK4458_00_CONTROL1,
					  AK4458_RSTN_MASK,
					  0x0);
	return ret;
}

__attribute__((used)) static int ak4458_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);
	int pcm_width = max(params_physical_width(params), ak4458->slot_width);
	int nfs1;
	u8 format;

	nfs1 = params_rate(params);
	ak4458->fs = nfs1;

	/* Master Clock Frequency Auto Setting Mode Enable */
	snd_soc_component_update_bits(component, AK4458_00_CONTROL1, 0x80, 0x80);

	switch (pcm_width) {
	case 16:
		if (ak4458->fmt == SND_SOC_DAIFMT_I2S)
			format = AK4458_DIF_24BIT_I2S;
		else
			format = AK4458_DIF_16BIT_LSB;
		break;
	case 32:
		switch (ak4458->fmt) {
		case SND_SOC_DAIFMT_I2S:
			format = AK4458_DIF_32BIT_I2S;
			break;
		case SND_SOC_DAIFMT_LEFT_J:
			format = AK4458_DIF_32BIT_MSB;
			break;
		case SND_SOC_DAIFMT_RIGHT_J:
			format = AK4458_DIF_32BIT_LSB;
			break;
		case SND_SOC_DAIFMT_DSP_B:
			format = AK4458_DIF_32BIT_MSB;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, AK4458_00_CONTROL1,
			    AK4458_DIF_MASK, format);

	ak4458_rstn_control(component, 0);
	ak4458_rstn_control(component, 1);

	return 0;
}

__attribute__((used)) static int ak4458_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS: /* Slave Mode */
		break;
	case SND_SOC_DAIFMT_CBM_CFM: /* Master Mode is not supported */
	case SND_SOC_DAIFMT_CBS_CFM:
	case SND_SOC_DAIFMT_CBM_CFS:
	default:
		dev_err(component->dev, "Master mode unsupported\n");
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
	case SND_SOC_DAIFMT_DSP_B:
		ak4458->fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
		break;
	default:
		dev_err(component->dev, "Audio format 0x%02X unsupported\n",
			fmt & SND_SOC_DAIFMT_FORMAT_MASK);
		return -EINVAL;
	}

	ak4458_rstn_control(component, 0);
	ak4458_rstn_control(component, 1);

	return 0;
}

__attribute__((used)) static int ak4458_set_dai_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);
	int nfs, ndt, ret, reg;
	int ats;

	nfs = ak4458->fs;

	reg = snd_soc_component_read32(component, AK4458_0B_CONTROL7);
	ats = (reg & AK4458_ATS_MASK) >> AK4458_ATS_SHIFT;

	ndt = att_speed[ats] / (nfs / 1000);

	if (mute) {
		ret = snd_soc_component_update_bits(component, AK4458_01_CONTROL2,  0x01, 1);
		mdelay(ndt);
		if (ak4458->mute_gpiod)
			gpiod_set_value_cansleep(ak4458->mute_gpiod, 1);
	} else {
		if (ak4458->mute_gpiod)
			gpiod_set_value_cansleep(ak4458->mute_gpiod, 0);
		ret = snd_soc_component_update_bits(component, AK4458_01_CONTROL2, 0x01, 0);
		mdelay(ndt);
	}

	return 0;
}

__attribute__((used)) static int ak4458_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
			       unsigned int rx_mask, int slots, int slot_width)
{
	struct snd_soc_component *component = dai->component;
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);
	int mode;

	ak4458->slots = slots;
	ak4458->slot_width = slot_width;

	switch (slots * slot_width) {
	case 128:
		mode = AK4458_MODE_TDM128;
		break;
	case 256:
		mode = AK4458_MODE_TDM256;
		break;
	case 512:
		mode = AK4458_MODE_TDM512;
		break;
	default:
		mode = AK4458_MODE_NORMAL;
		break;
	}

	snd_soc_component_update_bits(component, AK4458_0A_CONTROL6,
			    AK4458_MODE_MASK,
			    mode);

	return 0;
}

__attribute__((used)) static int ak4458_startup(struct snd_pcm_substream *substream,
			  struct snd_soc_dai *dai)
{
	int ret;

	ret = snd_pcm_hw_constraint_list(substream->runtime, 0,
					 SNDRV_PCM_HW_PARAM_RATE,
					 &ak4458_rate_constraints);

	return ret;
}

__attribute__((used)) static void ak4458_power_off(struct ak4458_priv *ak4458)
{
	if (ak4458->reset_gpiod) {
		gpiod_set_value_cansleep(ak4458->reset_gpiod, 0);
		usleep_range(1000, 2000);
	}
}

__attribute__((used)) static void ak4458_power_on(struct ak4458_priv *ak4458)
{
	if (ak4458->reset_gpiod) {
		gpiod_set_value_cansleep(ak4458->reset_gpiod, 1);
		usleep_range(1000, 2000);
	}
}

__attribute__((used)) static void ak4458_init(struct snd_soc_component *component)
{
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);

	/* External Mute ON */
	if (ak4458->mute_gpiod)
		gpiod_set_value_cansleep(ak4458->mute_gpiod, 1);

	ak4458_power_on(ak4458);

	snd_soc_component_update_bits(component, AK4458_00_CONTROL1,
			    0x80, 0x80);   /* ACKS bit = 1; 10000000 */

	ak4458_rstn_control(component, 1);
}

__attribute__((used)) static int ak4458_probe(struct snd_soc_component *component)
{
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);

	ak4458_init(component);

	ak4458->fs = 48000;

	return 0;
}

__attribute__((used)) static void ak4458_remove(struct snd_soc_component *component)
{
	struct ak4458_priv *ak4458 = snd_soc_component_get_drvdata(component);

	ak4458_power_off(ak4458);
}

__attribute__((used)) static int ak4458_i2c_probe(struct i2c_client *i2c)
{
	struct ak4458_priv *ak4458;
	int ret;

	ak4458 = devm_kzalloc(&i2c->dev, sizeof(*ak4458), GFP_KERNEL);
	if (!ak4458)
		return -ENOMEM;

	ak4458->regmap = devm_regmap_init_i2c(i2c, &ak4458_regmap);
	if (IS_ERR(ak4458->regmap))
		return PTR_ERR(ak4458->regmap);

	i2c_set_clientdata(i2c, ak4458);
	ak4458->dev = &i2c->dev;

	ak4458->reset_gpiod = devm_gpiod_get_optional(ak4458->dev, "reset",
						      GPIOD_OUT_LOW);
	if (IS_ERR(ak4458->reset_gpiod))
		return PTR_ERR(ak4458->reset_gpiod);

	ak4458->mute_gpiod = devm_gpiod_get_optional(ak4458->dev, "mute",
						     GPIOD_OUT_LOW);
	if (IS_ERR(ak4458->mute_gpiod))
		return PTR_ERR(ak4458->mute_gpiod);

	ret = devm_snd_soc_register_component(ak4458->dev, &soc_codec_dev_ak4458,
				     &ak4458_dai, 1);
	if (ret < 0) {
		dev_err(ak4458->dev, "Failed to register CODEC: %d\n", ret);
		return ret;
	}

	pm_runtime_enable(&i2c->dev);

	return 0;
}

__attribute__((used)) static int ak4458_i2c_remove(struct i2c_client *i2c)
{
	pm_runtime_disable(&i2c->dev);

	return 0;
}


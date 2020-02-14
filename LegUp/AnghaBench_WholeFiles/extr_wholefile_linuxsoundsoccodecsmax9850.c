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
typedef  int u64 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct max9850_priv {unsigned int sysclk; int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX9850_BCINV ; 
 int /*<<< orphan*/  MAX9850_CHARGE_PUMP ; 
 int /*<<< orphan*/  MAX9850_CLOCK ; 
 int /*<<< orphan*/  MAX9850_DIGITAL_AUDIO ; 
 int MAX9850_DLY ; 
 int /*<<< orphan*/  MAX9850_GENERAL_PURPOSE ; 
 int MAX9850_INV ; 
 int /*<<< orphan*/  MAX9850_LRCLK_LSB ; 
 int /*<<< orphan*/  MAX9850_LRCLK_MSB ; 
 int MAX9850_MASTER ; 
 int MAX9850_RTJ ; 
#define  MAX9850_STATUSA 142 
#define  MAX9850_STATUSB 141 
 int /*<<< orphan*/  MAX9850_VOLUME ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_BIAS_OFF 140 
#define  SND_SOC_BIAS_ON 139 
#define  SND_SOC_BIAS_PREPARE 138 
#define  SND_SOC_BIAS_STANDBY 137 
#define  SND_SOC_DAIFMT_CBM_CFM 136 
#define  SND_SOC_DAIFMT_CBS_CFS 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_IF 133 
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 130 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 struct max9850_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  do_div (int,unsigned int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max9850_priv*) ; 
 int /*<<< orphan*/  max9850_dai ; 
 int /*<<< orphan*/  max9850_regmap ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct max9850_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  soc_component_dev_max9850 ; 

__attribute__((used)) static bool max9850_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX9850_STATUSA:
	case MAX9850_STATUSB:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int max9850_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct max9850_priv *max9850 = snd_soc_component_get_drvdata(component);
	u64 lrclk_div;
	u8 sf, da;

	if (!max9850->sysclk)
		return -EINVAL;

	/* lrclk_div = 2^22 * rate / iclk with iclk = mclk / sf */
	sf = (snd_soc_component_read32(component, MAX9850_CLOCK) >> 2) + 1;
	lrclk_div = (1 << 22);
	lrclk_div *= params_rate(params);
	lrclk_div *= sf;
	do_div(lrclk_div, max9850->sysclk);

	snd_soc_component_write(component, MAX9850_LRCLK_MSB, (lrclk_div >> 8) & 0x7f);
	snd_soc_component_write(component, MAX9850_LRCLK_LSB, lrclk_div & 0xff);

	switch (params_width(params)) {
	case 16:
		da = 0;
		break;
	case 20:
		da = 0x2;
		break;
	case 24:
		da = 0x3;
		break;
	default:
		return -EINVAL;
	}
	snd_soc_component_update_bits(component, MAX9850_DIGITAL_AUDIO, 0x3, da);

	return 0;
}

__attribute__((used)) static int max9850_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct max9850_priv *max9850 = snd_soc_component_get_drvdata(component);

	/* calculate mclk -> iclk divider */
	if (freq <= 13000000)
		snd_soc_component_write(component, MAX9850_CLOCK, 0x0);
	else if (freq <= 26000000)
		snd_soc_component_write(component, MAX9850_CLOCK, 0x4);
	else if (freq <= 40000000)
		snd_soc_component_write(component, MAX9850_CLOCK, 0x8);
	else
		return -EINVAL;

	max9850->sysclk = freq;
	return 0;
}

__attribute__((used)) static int max9850_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u8 da = 0;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		da |= MAX9850_MASTER;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		da |= MAX9850_DLY;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		da |= MAX9850_RTJ;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_IF:
		da |= MAX9850_BCINV | MAX9850_INV;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		da |= MAX9850_BCINV;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		da |= MAX9850_INV;
		break;
	default:
		return -EINVAL;
	}

	/* set da */
	snd_soc_component_write(component, MAX9850_DIGITAL_AUDIO, da);

	return 0;
}

__attribute__((used)) static int max9850_set_bias_level(struct snd_soc_component *component,
				  enum snd_soc_bias_level level)
{
	struct max9850_priv *max9850 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			ret = regcache_sync(max9850->regmap);
			if (ret) {
				dev_err(component->dev,
					"Failed to sync cache: %d\n", ret);
				return ret;
			}
		}
		break;
	case SND_SOC_BIAS_OFF:
		break;
	}
	return 0;
}

__attribute__((used)) static int max9850_probe(struct snd_soc_component *component)
{
	/* enable zero-detect */
	snd_soc_component_update_bits(component, MAX9850_GENERAL_PURPOSE, 1, 1);
	/* enable slew-rate control */
	snd_soc_component_update_bits(component, MAX9850_VOLUME, 0x40, 0x40);
	/* set slew-rate 125ms */
	snd_soc_component_update_bits(component, MAX9850_CHARGE_PUMP, 0xff, 0xc0);

	return 0;
}

__attribute__((used)) static int max9850_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	struct max9850_priv *max9850;
	int ret;

	max9850 = devm_kzalloc(&i2c->dev, sizeof(struct max9850_priv),
			       GFP_KERNEL);
	if (max9850 == NULL)
		return -ENOMEM;

	max9850->regmap = devm_regmap_init_i2c(i2c, &max9850_regmap);
	if (IS_ERR(max9850->regmap))
		return PTR_ERR(max9850->regmap);

	i2c_set_clientdata(i2c, max9850);

	ret = devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_max9850, &max9850_dai, 1);
	return ret;
}


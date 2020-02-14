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
typedef  int u16 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct ak4535_priv {unsigned int sysclk; int /*<<< orphan*/  regmap; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  AK4535_DAC ; 
 int /*<<< orphan*/  AK4535_MODE1 ; 
 int /*<<< orphan*/  AK4535_MODE2 ; 
 int /*<<< orphan*/  AK4535_PM1 ; 
 int /*<<< orphan*/  AK4535_PM2 ; 
#define  AK4535_STATUS 134 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_BIAS_OFF 133 
#define  SND_SOC_BIAS_ON 132 
#define  SND_SOC_BIAS_PREPARE 131 
#define  SND_SOC_BIAS_STANDBY 130 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
#define  SND_SOC_DAIFMT_LEFT_J 128 
 int /*<<< orphan*/  ak4535_dai ; 
 int /*<<< orphan*/  ak4535_regmap ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct ak4535_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ak4535_priv*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  snd_soc_component_cache_sync (struct snd_soc_component*) ; 
 struct ak4535_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  soc_component_dev_ak4535 ; 

__attribute__((used)) static bool ak4535_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case AK4535_STATUS:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int ak4535_set_dai_sysclk(struct snd_soc_dai *codec_dai,
	int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ak4535_priv *ak4535 = snd_soc_component_get_drvdata(component);

	ak4535->sysclk = freq;
	return 0;
}

__attribute__((used)) static int ak4535_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ak4535_priv *ak4535 = snd_soc_component_get_drvdata(component);
	u8 mode2 = snd_soc_component_read32(component, AK4535_MODE2) & ~(0x3 << 5);
	int rate = params_rate(params), fs = 256;

	if (rate)
		fs = ak4535->sysclk / rate;

	/* set fs */
	switch (fs) {
	case 1024:
		mode2 |= (0x2 << 5);
		break;
	case 512:
		mode2 |= (0x1 << 5);
		break;
	case 256:
		break;
	}

	/* set rate */
	snd_soc_component_write(component, AK4535_MODE2, mode2);
	return 0;
}

__attribute__((used)) static int ak4535_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u8 mode1 = 0;

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		mode1 = 0x0002;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		mode1 = 0x0001;
		break;
	default:
		return -EINVAL;
	}

	/* use 32 fs for BCLK to save power */
	mode1 |= 0x4;

	snd_soc_component_write(component, AK4535_MODE1, mode1);
	return 0;
}

__attribute__((used)) static int ak4535_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u16 mute_reg = snd_soc_component_read32(component, AK4535_DAC);
	if (!mute)
		snd_soc_component_write(component, AK4535_DAC, mute_reg & ~0x20);
	else
		snd_soc_component_write(component, AK4535_DAC, mute_reg | 0x20);
	return 0;
}

__attribute__((used)) static int ak4535_set_bias_level(struct snd_soc_component *component,
	enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
		snd_soc_component_update_bits(component, AK4535_DAC, 0x20, 0);
		break;
	case SND_SOC_BIAS_PREPARE:
		snd_soc_component_update_bits(component, AK4535_DAC, 0x20, 0x20);
		break;
	case SND_SOC_BIAS_STANDBY:
		snd_soc_component_update_bits(component, AK4535_PM1, 0x80, 0x80);
		snd_soc_component_update_bits(component, AK4535_PM2, 0x80, 0);
		break;
	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, AK4535_PM1, 0x80, 0);
		break;
	}
	return 0;
}

__attribute__((used)) static int ak4535_resume(struct snd_soc_component *component)
{
	snd_soc_component_cache_sync(component);
	return 0;
}

__attribute__((used)) static int ak4535_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct ak4535_priv *ak4535;
	int ret;

	ak4535 = devm_kzalloc(&i2c->dev, sizeof(struct ak4535_priv),
			      GFP_KERNEL);
	if (ak4535 == NULL)
		return -ENOMEM;

	ak4535->regmap = devm_regmap_init_i2c(i2c, &ak4535_regmap);
	if (IS_ERR(ak4535->regmap)) {
		ret = PTR_ERR(ak4535->regmap);
		dev_err(&i2c->dev, "Failed to init regmap: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(i2c, ak4535);

	ret = devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_ak4535, &ak4535_dai, 1);

	return ret;
}


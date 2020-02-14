#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {TYPE_5__* dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_7__ {int* value; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_9__ {struct ak4641_platform_data* platform_data; } ;
struct i2c_client {TYPE_3__ dev; } ;
struct ak4641_priv {int deemph; scalar_t__ playback_fs; unsigned int sysclk; int /*<<< orphan*/  regmap; } ;
struct ak4641_platform_data {int /*<<< orphan*/  gpio_npdn; int /*<<< orphan*/  gpio_power; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_10__ {struct ak4641_platform_data* platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  AK4641_BTIF ; 
 int /*<<< orphan*/  AK4641_DAC ; 
 int /*<<< orphan*/  AK4641_MODE1 ; 
 int /*<<< orphan*/  AK4641_MODE2 ; 
 int /*<<< orphan*/  AK4641_PM1 ; 
 int /*<<< orphan*/  AK4641_PM2 ; 
 int ARRAY_SIZE (scalar_t__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 135 
#define  SND_SOC_BIAS_ON 134 
#define  SND_SOC_BIAS_PREPARE 133 
#define  SND_SOC_BIAS_STANDBY 132 
#define  SND_SOC_DAIFMT_DSP_A 131 
#define  SND_SOC_DAIFMT_DSP_B 130 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
#define  SND_SOC_DAIFMT_LEFT_J 128 
 scalar_t__ abs (scalar_t__) ; 
 scalar_t__* ak4641_dai ; 
 int /*<<< orphan*/  ak4641_regmap ; 
 scalar_t__* deemph_settings ; 
 int /*<<< orphan*/  dev_dbg (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,int) ; 
 struct ak4641_priv* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (TYPE_3__*,int /*<<< orphan*/ *,scalar_t__*,int) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int gpio_request_one (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ak4641_priv*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_mark_dirty (int /*<<< orphan*/ ) ; 
 int regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct ak4641_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  soc_component_dev_ak4641 ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int ak4641_set_deemph(struct snd_soc_component *component)
{
	struct ak4641_priv *ak4641 = snd_soc_component_get_drvdata(component);
	int i, best = 0;

	for (i = 0 ; i < ARRAY_SIZE(deemph_settings); i++) {
		/* if deemphasis is on, select the nearest available rate */
		if (ak4641->deemph && deemph_settings[i] != 0 &&
		    abs(deemph_settings[i] - ak4641->playback_fs) <
		    abs(deemph_settings[best] - ak4641->playback_fs))
			best = i;

		if (!ak4641->deemph && deemph_settings[i] == 0)
			best = i;
	}

	dev_dbg(component->dev, "Set deemphasis %d\n", best);

	return snd_soc_component_update_bits(component, AK4641_DAC, 0x3, best);
}

__attribute__((used)) static int ak4641_put_deemph(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct ak4641_priv *ak4641 = snd_soc_component_get_drvdata(component);
	int deemph = ucontrol->value.integer.value[0];

	if (deemph > 1)
		return -EINVAL;

	ak4641->deemph = deemph;

	return ak4641_set_deemph(component);
}

__attribute__((used)) static int ak4641_get_deemph(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct ak4641_priv *ak4641 = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = ak4641->deemph;
	return 0;
}

__attribute__((used)) static int ak4641_set_dai_sysclk(struct snd_soc_dai *codec_dai,
	int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ak4641_priv *ak4641 = snd_soc_component_get_drvdata(component);

	ak4641->sysclk = freq;
	return 0;
}

__attribute__((used)) static int ak4641_i2s_hw_params(struct snd_pcm_substream *substream,
				 struct snd_pcm_hw_params *params,
				 struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ak4641_priv *ak4641 = snd_soc_component_get_drvdata(component);
	int rate = params_rate(params), fs = 256;
	u8 mode2;

	if (rate)
		fs = ak4641->sysclk / rate;
	else
		return -EINVAL;

	/* set fs */
	switch (fs) {
	case 1024:
		mode2 = (0x2 << 5);
		break;
	case 512:
		mode2 = (0x1 << 5);
		break;
	case 256:
		mode2 = (0x0 << 5);
		break;
	default:
		dev_err(component->dev, "Error: unsupported fs=%d\n", fs);
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, AK4641_MODE2, (0x3 << 5), mode2);

	/* Update de-emphasis filter for the new rate */
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		ak4641->playback_fs = rate;
		ak4641_set_deemph(component);
	}

	return 0;
}

__attribute__((used)) static int ak4641_pcm_set_dai_fmt(struct snd_soc_dai *codec_dai,
				  unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u8 btif;
	int ret;

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		btif = (0x3 << 5);
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		btif = (0x2 << 5);
		break;
	case SND_SOC_DAIFMT_DSP_A:	/* MSB after FRM */
		btif = (0x0 << 5);
		break;
	case SND_SOC_DAIFMT_DSP_B:	/* MSB during FRM */
		btif = (0x1 << 5);
		break;
	default:
		return -EINVAL;
	}

	ret = snd_soc_component_update_bits(component, AK4641_BTIF, (0x3 << 5), btif);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int ak4641_i2s_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u8 mode1 = 0;

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		mode1 = 0x02;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		mode1 = 0x01;
		break;
	default:
		return -EINVAL;
	}

	return snd_soc_component_write(component, AK4641_MODE1, mode1);
}

__attribute__((used)) static int ak4641_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;

	return snd_soc_component_update_bits(component, AK4641_DAC, 0x20, mute ? 0x20 : 0);
}

__attribute__((used)) static int ak4641_set_bias_level(struct snd_soc_component *component,
	enum snd_soc_bias_level level)
{
	struct ak4641_priv *ak4641 = snd_soc_component_get_drvdata(component);
	struct ak4641_platform_data *pdata = component->dev->platform_data;
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		/* unmute */
		snd_soc_component_update_bits(component, AK4641_DAC, 0x20, 0);
		break;
	case SND_SOC_BIAS_PREPARE:
		/* mute */
		snd_soc_component_update_bits(component, AK4641_DAC, 0x20, 0x20);
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			if (pdata && gpio_is_valid(pdata->gpio_power))
				gpio_set_value(pdata->gpio_power, 1);
			mdelay(1);
			if (pdata && gpio_is_valid(pdata->gpio_npdn))
				gpio_set_value(pdata->gpio_npdn, 1);
			mdelay(1);

			ret = regcache_sync(ak4641->regmap);
			if (ret) {
				dev_err(component->dev,
					"Failed to sync cache: %d\n", ret);
				return ret;
			}
		}
		snd_soc_component_update_bits(component, AK4641_PM1, 0x80, 0x80);
		snd_soc_component_update_bits(component, AK4641_PM2, 0x80, 0);
		break;
	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, AK4641_PM1, 0x80, 0);
		if (pdata && gpio_is_valid(pdata->gpio_npdn))
			gpio_set_value(pdata->gpio_npdn, 0);
		if (pdata && gpio_is_valid(pdata->gpio_power))
			gpio_set_value(pdata->gpio_power, 0);
		regcache_mark_dirty(ak4641->regmap);
		break;
	}
	return 0;
}

__attribute__((used)) static int ak4641_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct ak4641_platform_data *pdata = i2c->dev.platform_data;
	struct ak4641_priv *ak4641;
	int ret;

	ak4641 = devm_kzalloc(&i2c->dev, sizeof(struct ak4641_priv),
			      GFP_KERNEL);
	if (!ak4641)
		return -ENOMEM;

	ak4641->regmap = devm_regmap_init_i2c(i2c, &ak4641_regmap);
	if (IS_ERR(ak4641->regmap))
		return PTR_ERR(ak4641->regmap);

	if (pdata) {
		if (gpio_is_valid(pdata->gpio_power)) {
			ret = gpio_request_one(pdata->gpio_power,
					GPIOF_OUT_INIT_LOW, "ak4641 power");
			if (ret)
				goto err_out;
		}
		if (gpio_is_valid(pdata->gpio_npdn)) {
			ret = gpio_request_one(pdata->gpio_npdn,
					GPIOF_OUT_INIT_LOW, "ak4641 npdn");
			if (ret)
				goto err_gpio;

			udelay(1); /* > 150 ns */
			gpio_set_value(pdata->gpio_npdn, 1);
		}
	}

	i2c_set_clientdata(i2c, ak4641);

	ret = devm_snd_soc_register_component(&i2c->dev,
				&soc_component_dev_ak4641,
				ak4641_dai, ARRAY_SIZE(ak4641_dai));
	if (ret != 0)
		goto err_gpio2;

	return 0;

err_gpio2:
	if (pdata) {
		if (gpio_is_valid(pdata->gpio_power))
			gpio_set_value(pdata->gpio_power, 0);
		if (gpio_is_valid(pdata->gpio_npdn))
			gpio_free(pdata->gpio_npdn);
	}
err_gpio:
	if (pdata && gpio_is_valid(pdata->gpio_power))
		gpio_free(pdata->gpio_power);
err_out:
	return ret;
}

__attribute__((used)) static int ak4641_i2c_remove(struct i2c_client *i2c)
{
	struct ak4641_platform_data *pdata = i2c->dev.platform_data;

	if (pdata) {
		if (gpio_is_valid(pdata->gpio_power)) {
			gpio_set_value(pdata->gpio_power, 0);
			gpio_free(pdata->gpio_power);
		}
		if (gpio_is_valid(pdata->gpio_npdn))
			gpio_free(pdata->gpio_npdn);
	}

	return 0;
}


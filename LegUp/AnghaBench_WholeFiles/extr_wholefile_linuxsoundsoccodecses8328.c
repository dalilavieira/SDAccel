#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {scalar_t__ stream; int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_11__ {unsigned int* value; } ;
struct TYPE_12__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct regmap {int dummy; } ;
struct es8328_priv {unsigned int deemph; int master; int* mclk_ratios; int mclkdiv2; TYPE_4__* supplies; struct regmap* regmap; struct regmap* clk; TYPE_3__* sysclk_constraints; scalar_t__ playback_fs; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_14__ {int val; int /*<<< orphan*/  supply; scalar_t__ rate; } ;
struct TYPE_13__ {int count; scalar_t__* list; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ES8328_ADCCONTROL4 ; 
 int ES8328_ADCCONTROL4_ADCFORMAT_I2S ; 
 int ES8328_ADCCONTROL4_ADCFORMAT_LJUST ; 
 int ES8328_ADCCONTROL4_ADCFORMAT_MASK ; 
 int ES8328_ADCCONTROL4_ADCFORMAT_RJUST ; 
 int ES8328_ADCCONTROL4_ADCWL_MASK ; 
 int ES8328_ADCCONTROL4_ADCWL_SHIFT ; 
 int ES8328_ADCCONTROL5 ; 
 int /*<<< orphan*/  ES8328_CHIPPOWER ; 
 int ES8328_CONTROL1 ; 
 int ES8328_CONTROL1_ENREF ; 
 int ES8328_CONTROL1_VMIDSEL_500k ; 
 int ES8328_CONTROL1_VMIDSEL_50k ; 
 int ES8328_CONTROL1_VMIDSEL_5k ; 
 int ES8328_CONTROL1_VMIDSEL_MASK ; 
 int /*<<< orphan*/  ES8328_CONTROL2 ; 
 int ES8328_CONTROL2_OVERCURRENT_ON ; 
 int ES8328_CONTROL2_THERMAL_SHUTDOWN_ON ; 
 int ES8328_DACCONTROL1 ; 
 int ES8328_DACCONTROL1_DACFORMAT_I2S ; 
 int ES8328_DACCONTROL1_DACFORMAT_LJUST ; 
 int ES8328_DACCONTROL1_DACFORMAT_MASK ; 
 int ES8328_DACCONTROL1_DACFORMAT_RJUST ; 
 int ES8328_DACCONTROL1_DACWL_MASK ; 
 int ES8328_DACCONTROL1_DACWL_SHIFT ; 
 int ES8328_DACCONTROL2 ; 
 int ES8328_DACCONTROL3 ; 
 int ES8328_DACCONTROL3_DACMUTE ; 
 int ES8328_DACCONTROL6 ; 
 int ES8328_DACCONTROL6_DEEMPH_MASK ; 
 int ES8328_DACCONTROL6_DEEMPH_OFF ; 
 int ES8328_MASTERMODE ; 
 int ES8328_MASTERMODE_MCLKDIV2 ; 
 int ES8328_MASTERMODE_MSC ; 
 int ES8328_RATEMASK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 136 
#define  SND_SOC_BIAS_ON 135 
#define  SND_SOC_BIAS_PREPARE 134 
#define  SND_SOC_BIAS_STANDBY 133 
#define  SND_SOC_DAIFMT_CBM_CFM 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 unsigned int SND_SOC_DAIFMT_NB_NF ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 scalar_t__ abs (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct regmap*) ; 
 int clk_prepare_enable (struct regmap*) ; 
 TYPE_3__ constraints_11289 ; 
 TYPE_3__ constraints_12288 ; 
 TYPE_4__* deemph_settings ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct regmap* dev_get_regmap (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct es8328_priv*) ; 
 struct regmap* devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 struct es8328_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_4__*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  es8328_component_driver ; 
 int /*<<< orphan*/  es8328_dai ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int* ratios_11289 ; 
 int* ratios_12288 ; 
 int /*<<< orphan*/  regcache_mark_dirty (struct regmap*) ; 
 int regcache_sync (struct regmap*) ; 
 int regulator_bulk_disable (int,TYPE_4__*) ; 
 int regulator_bulk_enable (int,TYPE_4__*) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct es8328_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,int,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/ * supply_names ; 

__attribute__((used)) static int es8328_set_deemph(struct snd_soc_component *component)
{
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);
	int val, i, best;

	/*
	 * If we're using deemphasis select the nearest available sample
	 * rate.
	 */
	if (es8328->deemph) {
		best = 0;
		for (i = 1; i < ARRAY_SIZE(deemph_settings); i++) {
			if (abs(deemph_settings[i].rate - es8328->playback_fs) <
			    abs(deemph_settings[best].rate - es8328->playback_fs))
				best = i;
		}

		val = deemph_settings[best].val;
	} else {
		val = ES8328_DACCONTROL6_DEEMPH_OFF;
	}

	dev_dbg(component->dev, "Set deemphasis %d\n", val);

	return snd_soc_component_update_bits(component, ES8328_DACCONTROL6,
			ES8328_DACCONTROL6_DEEMPH_MASK, val);
}

__attribute__((used)) static int es8328_get_deemph(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = es8328->deemph;
	return 0;
}

__attribute__((used)) static int es8328_put_deemph(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);
	unsigned int deemph = ucontrol->value.integer.value[0];
	int ret;

	if (deemph > 1)
		return -EINVAL;

	ret = es8328_set_deemph(component);
	if (ret < 0)
		return ret;

	es8328->deemph = deemph;

	return 0;
}

__attribute__((used)) static int es8328_mute(struct snd_soc_dai *dai, int mute)
{
	return snd_soc_component_update_bits(dai->component, ES8328_DACCONTROL3,
			ES8328_DACCONTROL3_DACMUTE,
			mute ? ES8328_DACCONTROL3_DACMUTE : 0);
}

__attribute__((used)) static int es8328_startup(struct snd_pcm_substream *substream,
			  struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);

	if (es8328->master && es8328->sysclk_constraints)
		snd_pcm_hw_constraint_list(substream->runtime, 0,
				SNDRV_PCM_HW_PARAM_RATE,
				es8328->sysclk_constraints);

	return 0;
}

__attribute__((used)) static int es8328_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);
	int i;
	int reg;
	int wl;
	int ratio;

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = ES8328_DACCONTROL2;
	else
		reg = ES8328_ADCCONTROL5;

	if (es8328->master) {
		if (!es8328->sysclk_constraints) {
			dev_err(component->dev, "No MCLK configured\n");
			return -EINVAL;
		}

		for (i = 0; i < es8328->sysclk_constraints->count; i++)
			if (es8328->sysclk_constraints->list[i] ==
			    params_rate(params))
				break;

		if (i == es8328->sysclk_constraints->count) {
			dev_err(component->dev,
				"LRCLK %d unsupported with current clock\n",
				params_rate(params));
			return -EINVAL;
		}
		ratio = es8328->mclk_ratios[i];
	} else {
		ratio = 0;
		es8328->mclkdiv2 = 0;
	}

	snd_soc_component_update_bits(component, ES8328_MASTERMODE,
			ES8328_MASTERMODE_MCLKDIV2,
			es8328->mclkdiv2 ? ES8328_MASTERMODE_MCLKDIV2 : 0);

	switch (params_width(params)) {
	case 16:
		wl = 3;
		break;
	case 18:
		wl = 2;
		break;
	case 20:
		wl = 1;
		break;
	case 24:
		wl = 0;
		break;
	case 32:
		wl = 4;
		break;
	default:
		return -EINVAL;
	}

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		snd_soc_component_update_bits(component, ES8328_DACCONTROL1,
				ES8328_DACCONTROL1_DACWL_MASK,
				wl << ES8328_DACCONTROL1_DACWL_SHIFT);

		es8328->playback_fs = params_rate(params);
		es8328_set_deemph(component);
	} else
		snd_soc_component_update_bits(component, ES8328_ADCCONTROL4,
				ES8328_ADCCONTROL4_ADCWL_MASK,
				wl << ES8328_ADCCONTROL4_ADCWL_SHIFT);

	return snd_soc_component_update_bits(component, reg, ES8328_RATEMASK, ratio);
}

__attribute__((used)) static int es8328_set_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);
	int mclkdiv2 = 0;

	switch (freq) {
	case 0:
		es8328->sysclk_constraints = NULL;
		es8328->mclk_ratios = NULL;
		break;
	case 22579200:
		mclkdiv2 = 1;
		/* fallthru */
	case 11289600:
		es8328->sysclk_constraints = &constraints_11289;
		es8328->mclk_ratios = ratios_11289;
		break;
	case 24576000:
		mclkdiv2 = 1;
		/* fallthru */
	case 12288000:
		es8328->sysclk_constraints = &constraints_12288;
		es8328->mclk_ratios = ratios_12288;
		break;
	default:
		return -EINVAL;
	}

	es8328->mclkdiv2 = mclkdiv2;
	return 0;
}

__attribute__((used)) static int es8328_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct es8328_priv *es8328 = snd_soc_component_get_drvdata(component);
	u8 dac_mode = 0;
	u8 adc_mode = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		/* Master serial port mode, with BCLK generated automatically */
		snd_soc_component_update_bits(component, ES8328_MASTERMODE,
				    ES8328_MASTERMODE_MSC,
				    ES8328_MASTERMODE_MSC);
		es8328->master = true;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		/* Slave serial port mode */
		snd_soc_component_update_bits(component, ES8328_MASTERMODE,
				    ES8328_MASTERMODE_MSC, 0);
		es8328->master = false;
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		dac_mode |= ES8328_DACCONTROL1_DACFORMAT_I2S;
		adc_mode |= ES8328_ADCCONTROL4_ADCFORMAT_I2S;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		dac_mode |= ES8328_DACCONTROL1_DACFORMAT_RJUST;
		adc_mode |= ES8328_ADCCONTROL4_ADCFORMAT_RJUST;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		dac_mode |= ES8328_DACCONTROL1_DACFORMAT_LJUST;
		adc_mode |= ES8328_ADCCONTROL4_ADCFORMAT_LJUST;
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF)
		return -EINVAL;

	snd_soc_component_update_bits(component, ES8328_DACCONTROL1,
			ES8328_DACCONTROL1_DACFORMAT_MASK, dac_mode);
	snd_soc_component_update_bits(component, ES8328_ADCCONTROL4,
			ES8328_ADCCONTROL4_ADCFORMAT_MASK, adc_mode);

	return 0;
}

__attribute__((used)) static int es8328_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		/* VREF, VMID=2x50k, digital enabled */
		snd_soc_component_write(component, ES8328_CHIPPOWER, 0);
		snd_soc_component_update_bits(component, ES8328_CONTROL1,
				ES8328_CONTROL1_VMIDSEL_MASK |
				ES8328_CONTROL1_ENREF,
				ES8328_CONTROL1_VMIDSEL_50k |
				ES8328_CONTROL1_ENREF);
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			snd_soc_component_update_bits(component, ES8328_CONTROL1,
					ES8328_CONTROL1_VMIDSEL_MASK |
					ES8328_CONTROL1_ENREF,
					ES8328_CONTROL1_VMIDSEL_5k |
					ES8328_CONTROL1_ENREF);

			/* Charge caps */
			msleep(100);
		}

		snd_soc_component_write(component, ES8328_CONTROL2,
				ES8328_CONTROL2_OVERCURRENT_ON |
				ES8328_CONTROL2_THERMAL_SHUTDOWN_ON);

		/* VREF, VMID=2*500k, digital stopped */
		snd_soc_component_update_bits(component, ES8328_CONTROL1,
				ES8328_CONTROL1_VMIDSEL_MASK |
				ES8328_CONTROL1_ENREF,
				ES8328_CONTROL1_VMIDSEL_500k |
				ES8328_CONTROL1_ENREF);
		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, ES8328_CONTROL1,
				ES8328_CONTROL1_VMIDSEL_MASK |
				ES8328_CONTROL1_ENREF,
				0);
		break;
	}
	return 0;
}

__attribute__((used)) static int es8328_suspend(struct snd_soc_component *component)
{
	struct es8328_priv *es8328;
	int ret;

	es8328 = snd_soc_component_get_drvdata(component);

	clk_disable_unprepare(es8328->clk);

	ret = regulator_bulk_disable(ARRAY_SIZE(es8328->supplies),
			es8328->supplies);
	if (ret) {
		dev_err(component->dev, "unable to disable regulators\n");
		return ret;
	}
	return 0;
}

__attribute__((used)) static int es8328_resume(struct snd_soc_component *component)
{
	struct regmap *regmap = dev_get_regmap(component->dev, NULL);
	struct es8328_priv *es8328;
	int ret;

	es8328 = snd_soc_component_get_drvdata(component);

	ret = clk_prepare_enable(es8328->clk);
	if (ret) {
		dev_err(component->dev, "unable to enable clock\n");
		return ret;
	}

	ret = regulator_bulk_enable(ARRAY_SIZE(es8328->supplies),
					es8328->supplies);
	if (ret) {
		dev_err(component->dev, "unable to enable regulators\n");
		return ret;
	}

	regcache_mark_dirty(regmap);
	ret = regcache_sync(regmap);
	if (ret) {
		dev_err(component->dev, "unable to sync regcache\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int es8328_component_probe(struct snd_soc_component *component)
{
	struct es8328_priv *es8328;
	int ret;

	es8328 = snd_soc_component_get_drvdata(component);

	ret = regulator_bulk_enable(ARRAY_SIZE(es8328->supplies),
					es8328->supplies);
	if (ret) {
		dev_err(component->dev, "unable to enable regulators\n");
		return ret;
	}

	/* Setup clocks */
	es8328->clk = devm_clk_get(component->dev, NULL);
	if (IS_ERR(es8328->clk)) {
		dev_err(component->dev, "codec clock missing or invalid\n");
		ret = PTR_ERR(es8328->clk);
		goto clk_fail;
	}

	ret = clk_prepare_enable(es8328->clk);
	if (ret) {
		dev_err(component->dev, "unable to prepare codec clk\n");
		goto clk_fail;
	}

	return 0;

clk_fail:
	regulator_bulk_disable(ARRAY_SIZE(es8328->supplies),
			       es8328->supplies);
	return ret;
}

__attribute__((used)) static void es8328_remove(struct snd_soc_component *component)
{
	struct es8328_priv *es8328;

	es8328 = snd_soc_component_get_drvdata(component);

	if (es8328->clk)
		clk_disable_unprepare(es8328->clk);

	regulator_bulk_disable(ARRAY_SIZE(es8328->supplies),
			       es8328->supplies);
}

int es8328_probe(struct device *dev, struct regmap *regmap)
{
	struct es8328_priv *es8328;
	int ret;
	int i;

	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	es8328 = devm_kzalloc(dev, sizeof(*es8328), GFP_KERNEL);
	if (es8328 == NULL)
		return -ENOMEM;

	es8328->regmap = regmap;

	for (i = 0; i < ARRAY_SIZE(es8328->supplies); i++)
		es8328->supplies[i].supply = supply_names[i];

	ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(es8328->supplies),
				es8328->supplies);
	if (ret) {
		dev_err(dev, "unable to get regulators\n");
		return ret;
	}

	dev_set_drvdata(dev, es8328);

	return devm_snd_soc_register_component(dev,
			&es8328_component_driver, &es8328_dai, 1);
}


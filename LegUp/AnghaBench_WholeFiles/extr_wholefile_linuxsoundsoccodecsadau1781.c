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
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct adau1781_platform_data {int left_input_differential; int right_input_differential; scalar_t__ use_dmic; } ;
struct adau {int /*<<< orphan*/  regmap; int /*<<< orphan*/  master; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
typedef  enum adau17x1_type { ____Placeholder_adau17x1_type } adau17x1_type ;

/* Variables and functions */
#define  ADAU1381 146 
 char* ADAU1381_FIRMWARE ; 
#define  ADAU1781 145 
#define  ADAU1781_BEEP_ZC 144 
#define  ADAU1781_DEJITTER 143 
#define  ADAU1781_DIG_PWDN0 142 
#define  ADAU1781_DIG_PWDN1 141 
#define  ADAU1781_DMIC_BEEP_CTRL 140 
 char* ADAU1781_FIRMWARE ; 
 int ADAU1781_INPUT_DIFFERNTIAL ; 
#define  ADAU1781_LEFT_LINEOUT 139 
#define  ADAU1781_LEFT_PGA 138 
#define  ADAU1781_LEFT_PLAYBACK_MIXER 137 
#define  ADAU1781_MONO_PLAYBACK_MIXER 136 
#define  ADAU1781_RIGHT_LINEOUT 135 
#define  ADAU1781_RIGHT_PGA 134 
#define  ADAU1781_RIGHT_PLAYBACK_MIXER 133 
#define  ADAU1781_SPEAKER 132 
 unsigned int ADAU17X1_CLOCK_CONTROL ; 
 int ADAU17X1_CLOCK_CONTROL_SYSCLK_EN ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int /*<<< orphan*/  adau1781_adc_dapm_routes ; 
 int /*<<< orphan*/  adau1781_component_driver ; 
 int /*<<< orphan*/  adau1781_dai_driver ; 
 int /*<<< orphan*/  adau1781_dmic_dapm_routes ; 
 int /*<<< orphan*/  adau1781_dmic_dapm_widgets ; 
 int adau17x1_add_routes (struct snd_soc_component*) ; 
 int adau17x1_add_widgets (struct snd_soc_component*) ; 
 int adau17x1_probe (struct device*,struct regmap*,int,void (*) (struct device*),char const*) ; 
 int adau17x1_readable_register (struct device*,unsigned int) ; 
 struct adau1781_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int,int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct adau* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int adau1781_dejitter_fixup(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct adau *adau = snd_soc_component_get_drvdata(component);

	/* After any power changes have been made the dejitter circuit
	 * has to be reinitialized. */
	regmap_write(adau->regmap, ADAU1781_DEJITTER, 0);
	if (!adau->master)
		regmap_write(adau->regmap, ADAU1781_DEJITTER, 5);

	return 0;
}

__attribute__((used)) static int adau1781_set_bias_level(struct snd_soc_component *component,
		enum snd_soc_bias_level level)
{
	struct adau *adau = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
			ADAU17X1_CLOCK_CONTROL_SYSCLK_EN,
			ADAU17X1_CLOCK_CONTROL_SYSCLK_EN);

		/* Precharge */
		regmap_update_bits(adau->regmap, ADAU1781_DIG_PWDN1, 0x8, 0x8);
		break;
	case SND_SOC_BIAS_OFF:
		regmap_update_bits(adau->regmap, ADAU1781_DIG_PWDN1, 0xc, 0x0);
		regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
			ADAU17X1_CLOCK_CONTROL_SYSCLK_EN, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static bool adau1781_readable_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ADAU1781_DMIC_BEEP_CTRL:
	case ADAU1781_LEFT_PGA:
	case ADAU1781_RIGHT_PGA:
	case ADAU1781_LEFT_PLAYBACK_MIXER:
	case ADAU1781_RIGHT_PLAYBACK_MIXER:
	case ADAU1781_MONO_PLAYBACK_MIXER:
	case ADAU1781_LEFT_LINEOUT:
	case ADAU1781_RIGHT_LINEOUT:
	case ADAU1781_SPEAKER:
	case ADAU1781_BEEP_ZC:
	case ADAU1781_DEJITTER:
	case ADAU1781_DIG_PWDN0:
	case ADAU1781_DIG_PWDN1:
		return true;
	default:
		break;
	}

	return adau17x1_readable_register(dev, reg);
}

__attribute__((used)) static int adau1781_set_input_mode(struct adau *adau, unsigned int reg,
	bool differential)
{
	unsigned int val;

	if (differential)
		val = ADAU1781_INPUT_DIFFERNTIAL;
	else
		val = 0;

	return regmap_update_bits(adau->regmap, reg,
		ADAU1781_INPUT_DIFFERNTIAL, val);
}

__attribute__((used)) static int adau1781_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau1781_platform_data *pdata = dev_get_platdata(component->dev);
	struct adau *adau = snd_soc_component_get_drvdata(component);
	int ret;

	ret = adau17x1_add_widgets(component);
	if (ret)
		return ret;

	if (pdata) {
		ret = adau1781_set_input_mode(adau, ADAU1781_LEFT_PGA,
			pdata->left_input_differential);
		if (ret)
			return ret;
		ret = adau1781_set_input_mode(adau, ADAU1781_RIGHT_PGA,
			pdata->right_input_differential);
		if (ret)
			return ret;
	}

	if (pdata && pdata->use_dmic) {
		ret = snd_soc_dapm_new_controls(dapm,
			adau1781_dmic_dapm_widgets,
			ARRAY_SIZE(adau1781_dmic_dapm_widgets));
		if (ret)
			return ret;
		ret = snd_soc_dapm_add_routes(dapm, adau1781_dmic_dapm_routes,
			ARRAY_SIZE(adau1781_dmic_dapm_routes));
		if (ret)
			return ret;
	} else {
		ret = snd_soc_dapm_add_routes(dapm, adau1781_adc_dapm_routes,
			ARRAY_SIZE(adau1781_adc_dapm_routes));
		if (ret)
			return ret;
	}

	ret = adau17x1_add_routes(component);
	if (ret < 0)
		return ret;

	return 0;
}

int adau1781_probe(struct device *dev, struct regmap *regmap,
	enum adau17x1_type type, void (*switch_mode)(struct device *dev))
{
	const char *firmware_name;
	int ret;

	switch (type) {
	case ADAU1381:
		firmware_name = ADAU1381_FIRMWARE;
		break;
	case ADAU1781:
		firmware_name = ADAU1781_FIRMWARE;
		break;
	default:
		return -EINVAL;
	}

	ret = adau17x1_probe(dev, regmap, type, switch_mode, firmware_name);
	if (ret)
		return ret;

	return devm_snd_soc_register_component(dev, &adau1781_component_driver,
		&adau1781_dai_driver, 1);
}


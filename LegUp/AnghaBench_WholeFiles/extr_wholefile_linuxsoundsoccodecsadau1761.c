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
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai_driver {int dummy; } ;
struct snd_soc_component {TYPE_1__* dev; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct adau1761_platform_data {int lineout_mode; int digmic_jackdetect_pin_mode; int jackdetect_debounce_time; int headphone_mode; scalar_t__ input_differential; int /*<<< orphan*/  jackdetect_active_low; } ;
struct adau {scalar_t__ type; struct regmap* regmap; int /*<<< orphan*/  master; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
typedef  enum adau17x1_type { ____Placeholder_adau17x1_type } adau17x1_type ;
typedef  enum adau1761_output_mode { ____Placeholder_adau1761_output_mode } adau1761_output_mode ;
typedef  enum adau1761_digmic_jackdet_pin_mode { ____Placeholder_adau1761_digmic_jackdet_pin_mode } adau1761_digmic_jackdet_pin_mode ;
struct TYPE_2__ {struct adau1761_platform_data* platform_data; } ;

/* Variables and functions */
 int ADAU1361 ; 
 scalar_t__ ADAU1761 ; 
#define  ADAU1761_CLK_ENABLE0 165 
#define  ADAU1761_CLK_ENABLE1 164 
#define  ADAU1761_DEJITTER 163 
 int ADAU1761_DIFF_INPUT_VOL_LDEN ; 
#define  ADAU1761_DIGMIC_JACKDETECT 162 
 unsigned int ADAU1761_DIGMIC_JACKDETECT_ACTIVE_LOW ; 
 unsigned int ADAU1761_DIGMIC_JACKDETECT_DIGMIC ; 
#define  ADAU1761_DIGMIC_JACKDET_PIN_MODE_DIGMIC 161 
#define  ADAU1761_DIGMIC_JACKDET_PIN_MODE_JACKDETECT 160 
#define  ADAU1761_DIGMIC_JACKDET_PIN_MODE_NONE 159 
 char* ADAU1761_FIRMWARE ; 
#define  ADAU1761_JACKDETECT_DEBOUNCE_10MS 158 
#define  ADAU1761_JACKDETECT_DEBOUNCE_20MS 157 
#define  ADAU1761_JACKDETECT_DEBOUNCE_40MS 156 
#define  ADAU1761_JACKDETECT_DEBOUNCE_5MS 155 
#define  ADAU1761_JACK_DETECT_PIN 154 
#define  ADAU1761_LEFT_DIFF_INPUT_VOL 153 
#define  ADAU1761_OUTPUT_MODE_HEADPHONE 152 
#define  ADAU1761_OUTPUT_MODE_HEADPHONE_CAPLESS 151 
#define  ADAU1761_OUTPUT_MODE_LINE 150 
#define  ADAU1761_PLAY_HP_LEFT_VOL 149 
#define  ADAU1761_PLAY_HP_RIGHT_VOL 148 
 int ADAU1761_PLAY_HP_RIGHT_VOL_MODE_HP ; 
#define  ADAU1761_PLAY_LINE_LEFT_VOL 147 
 int ADAU1761_PLAY_LINE_LEFT_VOL_MODE_HP ; 
#define  ADAU1761_PLAY_LINE_RIGHT_VOL 146 
 int ADAU1761_PLAY_LINE_RIGHT_VOL_MODE_HP ; 
#define  ADAU1761_PLAY_LR_MIXER_LEFT 145 
#define  ADAU1761_PLAY_LR_MIXER_RIGHT 144 
#define  ADAU1761_PLAY_MIXER_LEFT0 143 
#define  ADAU1761_PLAY_MIXER_LEFT1 142 
#define  ADAU1761_PLAY_MIXER_MONO 141 
#define  ADAU1761_PLAY_MIXER_RIGHT0 140 
#define  ADAU1761_PLAY_MIXER_RIGHT1 139 
#define  ADAU1761_PLAY_MONO_OUTPUT_VOL 138 
 int ADAU1761_PLAY_MONO_OUTPUT_VOL_MODE_HP ; 
 int ADAU1761_PLAY_MONO_OUTPUT_VOL_UNMUTE ; 
#define  ADAU1761_POP_CLICK_SUPPRESS 137 
#define  ADAU1761_REC_MIXER_LEFT0 136 
#define  ADAU1761_REC_MIXER_LEFT1 135 
#define  ADAU1761_REC_MIXER_RIGHT0 134 
#define  ADAU1761_REC_MIXER_RIGHT1 133 
#define  ADAU1761_RIGHT_DIFF_INPUT_VOL 132 
 int const ADAU17X1_CLOCK_CONTROL ; 
 int ADAU17X1_CLOCK_CONTROL_SYSCLK_EN ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 struct snd_soc_dai_driver adau1361_dai_driver ; 
 int /*<<< orphan*/  adau1761_capless_dapm_routes ; 
 int /*<<< orphan*/  adau1761_capless_dapm_widgets ; 
 int /*<<< orphan*/  adau1761_component_driver ; 
 struct snd_soc_dai_driver adau1761_dai_driver ; 
 int /*<<< orphan*/  adau1761_dapm_routes ; 
 int /*<<< orphan*/  adau1761_dapm_widgets ; 
 int /*<<< orphan*/  adau1761_differential_mode_controls ; 
 int /*<<< orphan*/  adau1761_dmic_routes ; 
 int /*<<< orphan*/  adau1761_dmic_widgets ; 
 int /*<<< orphan*/  adau1761_jack_detect_controls ; 
 int /*<<< orphan*/  adau1761_mono_controls ; 
 int /*<<< orphan*/  adau1761_mono_dapm_routes ; 
 int /*<<< orphan*/  adau1761_mono_dapm_widgets ; 
 int /*<<< orphan*/  adau1761_no_dmic_routes ; 
 int /*<<< orphan*/  adau1761_single_mode_controls ; 
 int adau17x1_add_routes (struct snd_soc_component*) ; 
 int adau17x1_add_widgets (struct snd_soc_component*) ; 
 int adau17x1_probe (struct device*,struct regmap*,int,void (*) (struct device*),char const*) ; 
 int adau17x1_readable_register (struct device*,unsigned int) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,struct snd_soc_dai_driver*,int) ; 
 int /*<<< orphan*/  regcache_cache_only (struct regmap*,int) ; 
 int /*<<< orphan*/  regcache_sync (struct regmap*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int const,int,int) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int,unsigned int) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct adau* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int adau1761_dejitter_fixup(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct adau *adau = snd_soc_component_get_drvdata(component);

	/* After any power changes have been made the dejitter circuit
	 * has to be reinitialized. */
	regmap_write(adau->regmap, ADAU1761_DEJITTER, 0);
	if (!adau->master)
		regmap_write(adau->regmap, ADAU1761_DEJITTER, 3);

	return 0;
}

__attribute__((used)) static int adau1761_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct adau *adau = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		regcache_cache_only(adau->regmap, false);
		regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
			ADAU17X1_CLOCK_CONTROL_SYSCLK_EN,
			ADAU17X1_CLOCK_CONTROL_SYSCLK_EN);
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF)
			regcache_sync(adau->regmap);
		break;
	case SND_SOC_BIAS_OFF:
		regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
			ADAU17X1_CLOCK_CONTROL_SYSCLK_EN, 0);
		regcache_cache_only(adau->regmap, true);
		break;

	}
	return 0;
}

__attribute__((used)) static enum adau1761_output_mode adau1761_get_lineout_mode(
	struct snd_soc_component *component)
{
	struct adau1761_platform_data *pdata = component->dev->platform_data;

	if (pdata)
		return pdata->lineout_mode;

	return ADAU1761_OUTPUT_MODE_LINE;
}

__attribute__((used)) static int adau1761_setup_digmic_jackdetect(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau1761_platform_data *pdata = component->dev->platform_data;
	struct adau *adau = snd_soc_component_get_drvdata(component);
	enum adau1761_digmic_jackdet_pin_mode mode;
	unsigned int val = 0;
	int ret;

	if (pdata)
		mode = pdata->digmic_jackdetect_pin_mode;
	else
		mode = ADAU1761_DIGMIC_JACKDET_PIN_MODE_NONE;

	switch (mode) {
	case ADAU1761_DIGMIC_JACKDET_PIN_MODE_JACKDETECT:
		switch (pdata->jackdetect_debounce_time) {
		case ADAU1761_JACKDETECT_DEBOUNCE_5MS:
		case ADAU1761_JACKDETECT_DEBOUNCE_10MS:
		case ADAU1761_JACKDETECT_DEBOUNCE_20MS:
		case ADAU1761_JACKDETECT_DEBOUNCE_40MS:
			val |= pdata->jackdetect_debounce_time << 6;
			break;
		default:
			return -EINVAL;
		}
		if (pdata->jackdetect_active_low)
			val |= ADAU1761_DIGMIC_JACKDETECT_ACTIVE_LOW;

		ret = snd_soc_add_component_controls(component,
			adau1761_jack_detect_controls,
			ARRAY_SIZE(adau1761_jack_detect_controls));
		if (ret)
			return ret;
	case ADAU1761_DIGMIC_JACKDET_PIN_MODE_NONE: /* fallthrough */
		ret = snd_soc_dapm_add_routes(dapm, adau1761_no_dmic_routes,
			ARRAY_SIZE(adau1761_no_dmic_routes));
		if (ret)
			return ret;
		break;
	case ADAU1761_DIGMIC_JACKDET_PIN_MODE_DIGMIC:
		ret = snd_soc_dapm_new_controls(dapm, adau1761_dmic_widgets,
			ARRAY_SIZE(adau1761_dmic_widgets));
		if (ret)
			return ret;

		ret = snd_soc_dapm_add_routes(dapm, adau1761_dmic_routes,
			ARRAY_SIZE(adau1761_dmic_routes));
		if (ret)
			return ret;

		val |= ADAU1761_DIGMIC_JACKDETECT_DIGMIC;
		break;
	default:
		return -EINVAL;
	}

	regmap_write(adau->regmap, ADAU1761_DIGMIC_JACKDETECT, val);

	return 0;
}

__attribute__((used)) static int adau1761_setup_headphone_mode(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau *adau = snd_soc_component_get_drvdata(component);
	struct adau1761_platform_data *pdata = component->dev->platform_data;
	enum adau1761_output_mode mode;
	int ret;

	if (pdata)
		mode = pdata->headphone_mode;
	else
		mode = ADAU1761_OUTPUT_MODE_HEADPHONE;

	switch (mode) {
	case ADAU1761_OUTPUT_MODE_LINE:
		break;
	case ADAU1761_OUTPUT_MODE_HEADPHONE_CAPLESS:
		regmap_update_bits(adau->regmap, ADAU1761_PLAY_MONO_OUTPUT_VOL,
			ADAU1761_PLAY_MONO_OUTPUT_VOL_MODE_HP |
			ADAU1761_PLAY_MONO_OUTPUT_VOL_UNMUTE,
			ADAU1761_PLAY_MONO_OUTPUT_VOL_MODE_HP |
			ADAU1761_PLAY_MONO_OUTPUT_VOL_UNMUTE);
		/* fallthrough */
	case ADAU1761_OUTPUT_MODE_HEADPHONE:
		regmap_update_bits(adau->regmap, ADAU1761_PLAY_HP_RIGHT_VOL,
			ADAU1761_PLAY_HP_RIGHT_VOL_MODE_HP,
			ADAU1761_PLAY_HP_RIGHT_VOL_MODE_HP);
		break;
	default:
		return -EINVAL;
	}

	if (mode == ADAU1761_OUTPUT_MODE_HEADPHONE_CAPLESS) {
		ret = snd_soc_dapm_new_controls(dapm,
			adau1761_capless_dapm_widgets,
			ARRAY_SIZE(adau1761_capless_dapm_widgets));
		if (ret)
			return ret;
		ret = snd_soc_dapm_add_routes(dapm,
			adau1761_capless_dapm_routes,
			ARRAY_SIZE(adau1761_capless_dapm_routes));
	} else {
		ret = snd_soc_add_component_controls(component, adau1761_mono_controls,
			ARRAY_SIZE(adau1761_mono_controls));
		if (ret)
			return ret;
		ret = snd_soc_dapm_new_controls(dapm,
			adau1761_mono_dapm_widgets,
			ARRAY_SIZE(adau1761_mono_dapm_widgets));
		if (ret)
			return ret;
		ret = snd_soc_dapm_add_routes(dapm,
			adau1761_mono_dapm_routes,
			ARRAY_SIZE(adau1761_mono_dapm_routes));
	}

	return ret;
}

__attribute__((used)) static bool adau1761_readable_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ADAU1761_DIGMIC_JACKDETECT:
	case ADAU1761_REC_MIXER_LEFT0:
	case ADAU1761_REC_MIXER_LEFT1:
	case ADAU1761_REC_MIXER_RIGHT0:
	case ADAU1761_REC_MIXER_RIGHT1:
	case ADAU1761_LEFT_DIFF_INPUT_VOL:
	case ADAU1761_RIGHT_DIFF_INPUT_VOL:
	case ADAU1761_PLAY_LR_MIXER_LEFT:
	case ADAU1761_PLAY_MIXER_LEFT0:
	case ADAU1761_PLAY_MIXER_LEFT1:
	case ADAU1761_PLAY_MIXER_RIGHT0:
	case ADAU1761_PLAY_MIXER_RIGHT1:
	case ADAU1761_PLAY_LR_MIXER_RIGHT:
	case ADAU1761_PLAY_MIXER_MONO:
	case ADAU1761_PLAY_HP_LEFT_VOL:
	case ADAU1761_PLAY_HP_RIGHT_VOL:
	case ADAU1761_PLAY_LINE_LEFT_VOL:
	case ADAU1761_PLAY_LINE_RIGHT_VOL:
	case ADAU1761_PLAY_MONO_OUTPUT_VOL:
	case ADAU1761_POP_CLICK_SUPPRESS:
	case ADAU1761_JACK_DETECT_PIN:
	case ADAU1761_DEJITTER:
	case ADAU1761_CLK_ENABLE0:
	case ADAU1761_CLK_ENABLE1:
		return true;
	default:
		break;
	}

	return adau17x1_readable_register(dev, reg);
}

__attribute__((used)) static int adau1761_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau1761_platform_data *pdata = component->dev->platform_data;
	struct adau *adau = snd_soc_component_get_drvdata(component);
	int ret;

	ret = adau17x1_add_widgets(component);
	if (ret < 0)
		return ret;

	if (pdata && pdata->input_differential) {
		regmap_update_bits(adau->regmap, ADAU1761_LEFT_DIFF_INPUT_VOL,
			ADAU1761_DIFF_INPUT_VOL_LDEN,
			ADAU1761_DIFF_INPUT_VOL_LDEN);
		regmap_update_bits(adau->regmap, ADAU1761_RIGHT_DIFF_INPUT_VOL,
			ADAU1761_DIFF_INPUT_VOL_LDEN,
			ADAU1761_DIFF_INPUT_VOL_LDEN);
		ret = snd_soc_add_component_controls(component,
			adau1761_differential_mode_controls,
			ARRAY_SIZE(adau1761_differential_mode_controls));
		if (ret)
			return ret;
	} else {
		ret = snd_soc_add_component_controls(component,
			adau1761_single_mode_controls,
			ARRAY_SIZE(adau1761_single_mode_controls));
		if (ret)
			return ret;
	}

	switch (adau1761_get_lineout_mode(component)) {
	case ADAU1761_OUTPUT_MODE_LINE:
		break;
	case ADAU1761_OUTPUT_MODE_HEADPHONE:
		regmap_update_bits(adau->regmap, ADAU1761_PLAY_LINE_LEFT_VOL,
			ADAU1761_PLAY_LINE_LEFT_VOL_MODE_HP,
			ADAU1761_PLAY_LINE_LEFT_VOL_MODE_HP);
		regmap_update_bits(adau->regmap, ADAU1761_PLAY_LINE_RIGHT_VOL,
			ADAU1761_PLAY_LINE_RIGHT_VOL_MODE_HP,
			ADAU1761_PLAY_LINE_RIGHT_VOL_MODE_HP);
		break;
	default:
		return -EINVAL;
	}

	ret = adau1761_setup_headphone_mode(component);
	if (ret)
		return ret;

	ret = adau1761_setup_digmic_jackdetect(component);
	if (ret)
		return ret;

	if (adau->type == ADAU1761) {
		ret = snd_soc_dapm_new_controls(dapm, adau1761_dapm_widgets,
			ARRAY_SIZE(adau1761_dapm_widgets));
		if (ret)
			return ret;

		ret = snd_soc_dapm_add_routes(dapm, adau1761_dapm_routes,
			ARRAY_SIZE(adau1761_dapm_routes));
		if (ret)
			return ret;
	}

	ret = adau17x1_add_routes(component);
	if (ret < 0)
		return ret;

	return 0;
}

int adau1761_probe(struct device *dev, struct regmap *regmap,
	enum adau17x1_type type, void (*switch_mode)(struct device *dev))
{
	struct snd_soc_dai_driver *dai_drv;
	const char *firmware_name;
	int ret;

	if (type == ADAU1361) {
		dai_drv = &adau1361_dai_driver;
		firmware_name = NULL;
	} else {
		dai_drv = &adau1761_dai_driver;
		firmware_name = ADAU1761_FIRMWARE;
	}

	ret = adau17x1_probe(dev, regmap, type, switch_mode, firmware_name);
	if (ret)
		return ret;

	/* Enable cache only mode as we could miss writes before bias level
	 * reaches standby and the core clock is enabled */
	regcache_cache_only(regmap, true);

	return devm_snd_soc_register_component(dev, &adau1761_component_driver,
					       dai_drv, 1);
}


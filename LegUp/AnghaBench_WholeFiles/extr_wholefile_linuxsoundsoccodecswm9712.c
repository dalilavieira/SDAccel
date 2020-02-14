#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct wm9712_priv {unsigned int* hp_mixer; TYPE_3__* mfd_pdata; int /*<<< orphan*/  lock; int /*<<< orphan*/  ac97; } ;
struct soc_mixer_control {int shift; } ;
struct snd_soc_dapm_update {int mask; int val; int /*<<< orphan*/  reg; struct snd_kcontrol* kcontrol; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {scalar_t__ stream; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int rate; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_4__ {unsigned int* value; } ;
struct TYPE_5__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct regmap {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_6__ {struct regmap* regmap; int /*<<< orphan*/  ac97; } ;

/* Variables and functions */
 int AC97_EXTENDED_MSTATUS ; 
 int /*<<< orphan*/  AC97_EXTENDED_STATUS ; 
 int /*<<< orphan*/  AC97_PCI_SID ; 
 int AC97_PCM_FRONT_DAC_RATE ; 
 int AC97_PCM_LR_ADC_RATE ; 
 int AC97_PCM_SURR_DAC_RATE ; 
 int AC97_POWERDOWN ; 
#define  AC97_REC_GAIN 132 
 int /*<<< orphan*/  AC97_VIDEO ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int /*<<< orphan*/  WM9712_VENDOR_ID ; 
 int /*<<< orphan*/  WM9712_VENDOR_ID_MASK ; 
 TYPE_3__* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct wm9712_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm9712_priv*) ; 
 int regmap_ac97_default_volatile (struct device*,unsigned int) ; 
 int snd_ac97_reset (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_cache_sync (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_force_bias_level (struct snd_soc_component*,int const) ; 
 struct wm9712_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,struct regmap*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int,int) ; 
 struct snd_soc_dapm_context* snd_soc_dapm_kcontrol_dapm (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mixer_update_power (struct snd_soc_dapm_context*,struct snd_kcontrol*,unsigned int,struct snd_soc_dapm_update*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  soc_component_dev_wm9712 ; 
 int /*<<< orphan*/  wm9712_dai ; 
 int /*<<< orphan*/ * wm9712_mixer_mute_regs ; 

__attribute__((used)) static bool wm9712_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case AC97_REC_GAIN:
		return true;
	default:
		return regmap_ac97_default_volatile(dev, reg);
	}
}

__attribute__((used)) static int wm9712_hp_mixer_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kcontrol);
	struct snd_soc_component *component = snd_soc_dapm_to_component(dapm);
	struct wm9712_priv *wm9712 = snd_soc_component_get_drvdata(component);
	unsigned int val = ucontrol->value.integer.value[0];
	struct soc_mixer_control *mc =
		(struct soc_mixer_control *)kcontrol->private_value;
	unsigned int mixer, mask, shift, old;
	struct snd_soc_dapm_update update = {};
	bool change;

	mixer = mc->shift >> 8;
	shift = mc->shift & 0xff;
	mask = 1 << shift;

	mutex_lock(&wm9712->lock);
	old = wm9712->hp_mixer[mixer];
	if (ucontrol->value.integer.value[0])
		wm9712->hp_mixer[mixer] |= mask;
	else
		wm9712->hp_mixer[mixer] &= ~mask;

	change = old != wm9712->hp_mixer[mixer];
	if (change) {
		update.kcontrol = kcontrol;
		update.reg = wm9712_mixer_mute_regs[shift];
		update.mask = 0x8000;
		if ((wm9712->hp_mixer[0] & mask) ||
		    (wm9712->hp_mixer[1] & mask))
			update.val = 0x0;
		else
			update.val = 0x8000;

		snd_soc_dapm_mixer_update_power(dapm, kcontrol, val,
			&update);
	}

	mutex_unlock(&wm9712->lock);

	return change;
}

__attribute__((used)) static int wm9712_hp_mixer_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kcontrol);
	struct snd_soc_component *component = snd_soc_dapm_to_component(dapm);
	struct wm9712_priv *wm9712 = snd_soc_component_get_drvdata(component);
	struct soc_mixer_control *mc =
		(struct soc_mixer_control *)kcontrol->private_value;
	unsigned int shift, mixer;

	mixer = mc->shift >> 8;
	shift = mc->shift & 0xff;

	ucontrol->value.integer.value[0] =
		(wm9712->hp_mixer[mixer] >> shift) & 1;

	return 0;
}

__attribute__((used)) static int ac97_prepare(struct snd_pcm_substream *substream,
			struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	int reg;
	struct snd_pcm_runtime *runtime = substream->runtime;

	snd_soc_component_update_bits(component, AC97_EXTENDED_STATUS, 0x1, 0x1);

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = AC97_PCM_FRONT_DAC_RATE;
	else
		reg = AC97_PCM_LR_ADC_RATE;

	return snd_soc_component_write(component, reg, runtime->rate);
}

__attribute__((used)) static int ac97_aux_prepare(struct snd_pcm_substream *substream,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct snd_pcm_runtime *runtime = substream->runtime;

	snd_soc_component_update_bits(component, AC97_EXTENDED_STATUS, 0x1, 0x1);
	snd_soc_component_update_bits(component, AC97_PCI_SID, 0x8000, 0x8000);

	if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
		return -ENODEV;

	return snd_soc_component_write(component, AC97_PCM_SURR_DAC_RATE, runtime->rate);
}

__attribute__((used)) static int wm9712_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		snd_soc_component_write(component, AC97_POWERDOWN, 0x0000);
		break;
	case SND_SOC_BIAS_OFF:
		/* disable everything including AC link */
		snd_soc_component_write(component, AC97_EXTENDED_MSTATUS, 0xffff);
		snd_soc_component_write(component, AC97_POWERDOWN, 0xffff);
		break;
	}
	return 0;
}

__attribute__((used)) static int wm9712_soc_resume(struct snd_soc_component *component)
{
	struct wm9712_priv *wm9712 = snd_soc_component_get_drvdata(component);
	int ret;

	ret = snd_ac97_reset(wm9712->ac97, true, WM9712_VENDOR_ID,
		WM9712_VENDOR_ID_MASK);
	if (ret < 0)
		return ret;

	snd_soc_component_force_bias_level(component, SND_SOC_BIAS_STANDBY);

	if (ret == 0)
		snd_soc_component_cache_sync(component);

	return ret;
}

__attribute__((used)) static int wm9712_soc_probe(struct snd_soc_component *component)
{
	struct wm9712_priv *wm9712 = snd_soc_component_get_drvdata(component);
	struct regmap *regmap;
	int ret;

	if (wm9712->mfd_pdata) {
		wm9712->ac97 = wm9712->mfd_pdata->ac97;
		regmap = wm9712->mfd_pdata->regmap;
	} else {
#ifdef CONFIG_SND_SOC_AC97_BUS
		wm9712->ac97 = snd_soc_new_ac97_component(component, WM9712_VENDOR_ID,
						      WM9712_VENDOR_ID_MASK);
		if (IS_ERR(wm9712->ac97)) {
			ret = PTR_ERR(wm9712->ac97);
			dev_err(component->dev,
				"Failed to register AC97 codec: %d\n", ret);
			return ret;
		}

		regmap = regmap_init_ac97(wm9712->ac97, &wm9712_regmap_config);
		if (IS_ERR(regmap)) {
			snd_soc_free_ac97_component(wm9712->ac97);
			return PTR_ERR(regmap);
		}
#endif
	}

	snd_soc_component_init_regmap(component, regmap);

	/* set alc mux to none */
	snd_soc_component_update_bits(component, AC97_VIDEO, 0x3000, 0x3000);

	return 0;
}

__attribute__((used)) static void wm9712_soc_remove(struct snd_soc_component *component)
{
#ifdef CONFIG_SND_SOC_AC97_BUS
	struct wm9712_priv *wm9712 = snd_soc_component_get_drvdata(component);

	if (!wm9712->mfd_pdata) {
		snd_soc_component_exit_regmap(component);
		snd_soc_free_ac97_component(wm9712->ac97);
	}
#endif
}

__attribute__((used)) static int wm9712_probe(struct platform_device *pdev)
{
	struct wm9712_priv *wm9712;

	wm9712 = devm_kzalloc(&pdev->dev, sizeof(*wm9712), GFP_KERNEL);
	if (wm9712 == NULL)
		return -ENOMEM;

	mutex_init(&wm9712->lock);

	wm9712->mfd_pdata = dev_get_platdata(&pdev->dev);
	platform_set_drvdata(pdev, wm9712);

	return devm_snd_soc_register_component(&pdev->dev,
			&soc_component_dev_wm9712, wm9712_dai, ARRAY_SIZE(wm9712_dai));
}


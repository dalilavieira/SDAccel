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
struct wm8776_priv {int* sysclk; int /*<<< orphan*/  regmap; } ;
struct snd_soc_dai {TYPE_1__* driver; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_2__ {int id; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
#define  SND_SOC_BIAS_OFF 143 
#define  SND_SOC_BIAS_ON 142 
#define  SND_SOC_BIAS_PREPARE 141 
#define  SND_SOC_BIAS_STANDBY 140 
#define  SND_SOC_DAIFMT_CBM_CFM 139 
#define  SND_SOC_DAIFMT_CBS_CFS 138 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 137 
#define  SND_SOC_DAIFMT_IB_IF 136 
#define  SND_SOC_DAIFMT_IB_NF 135 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 134 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 133 
#define  SND_SOC_DAIFMT_NB_NF 132 
#define  SND_SOC_DAIFMT_RIGHT_J 131 
 scalar_t__ WARN_ON (int) ; 
 int WM8776_ADCIFCTRL ; 
 int WM8776_DACIFCTRL ; 
 int const WM8776_DACMUTE ; 
 int WM8776_DACRVOL ; 
#define  WM8776_DAI_ADC 130 
#define  WM8776_DAI_DAC 129 
 int WM8776_HPRVOL ; 
 int WM8776_MSTRCTRL ; 
 int WM8776_PWRDOWN ; 
#define  WM8776_RESET 128 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int,...) ; 
 int* mclk_ratios ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct wm8776_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int const,int) ; 

__attribute__((used)) static bool wm8776_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8776_RESET:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int wm8776_reset(struct snd_soc_component *component)
{
	return snd_soc_component_write(component, WM8776_RESET, 0);
}

__attribute__((used)) static int wm8776_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	int reg, iface, master;

	switch (dai->driver->id) {
	case WM8776_DAI_DAC:
		reg = WM8776_DACIFCTRL;
		master = 0x80;
		break;
	case WM8776_DAI_ADC:
		reg = WM8776_ADCIFCTRL;
		master = 0x100;
		break;
	default:
		return -EINVAL;
	}

	iface = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		master = 0;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		iface |= 0x0002;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		iface |= 0x0001;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_IF:
		iface |= 0x00c;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		iface |= 0x008;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		iface |= 0x004;
		break;
	default:
		return -EINVAL;
	}

	/* Finally, write out the values */
	snd_soc_component_update_bits(component, reg, 0xf, iface);
	snd_soc_component_update_bits(component, WM8776_MSTRCTRL, 0x180, master);

	return 0;
}

__attribute__((used)) static int wm8776_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8776_priv *wm8776 = snd_soc_component_get_drvdata(component);
	int iface_reg, iface;
	int ratio_shift, master;
	int i;

	switch (dai->driver->id) {
	case WM8776_DAI_DAC:
		iface_reg = WM8776_DACIFCTRL;
		master = 0x80;
		ratio_shift = 4;
		break;
	case WM8776_DAI_ADC:
		iface_reg = WM8776_ADCIFCTRL;
		master = 0x100;
		ratio_shift = 0;
		break;
	default:
		return -EINVAL;
	}

	/* Set word length */
	switch (params_width(params)) {
	case 16:
		iface = 0;
		break;
	case 20:
		iface = 0x10;
		break;
	case 24:
		iface = 0x20;
		break;
	case 32:
		iface = 0x30;
		break;
	default:
		dev_err(component->dev, "Unsupported sample size: %i\n",
			params_width(params));
		return -EINVAL;
	}

	/* Only need to set MCLK/LRCLK ratio if we're master */
	if (snd_soc_component_read32(component, WM8776_MSTRCTRL) & master) {
		for (i = 0; i < ARRAY_SIZE(mclk_ratios); i++) {
			if (wm8776->sysclk[dai->driver->id] / params_rate(params)
			    == mclk_ratios[i])
				break;
		}

		if (i == ARRAY_SIZE(mclk_ratios)) {
			dev_err(component->dev,
				"Unable to configure MCLK ratio %d/%d\n",
				wm8776->sysclk[dai->driver->id], params_rate(params));
			return -EINVAL;
		}

		dev_dbg(component->dev, "MCLK is %dfs\n", mclk_ratios[i]);

		snd_soc_component_update_bits(component, WM8776_MSTRCTRL,
				    0x7 << ratio_shift, i << ratio_shift);
	} else {
		dev_dbg(component->dev, "DAI in slave mode\n");
	}

	snd_soc_component_update_bits(component, iface_reg, 0x30, iface);

	return 0;
}

__attribute__((used)) static int wm8776_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;

	return snd_soc_component_write(component, WM8776_DACMUTE, !!mute);
}

__attribute__((used)) static int wm8776_set_sysclk(struct snd_soc_dai *dai,
			     int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = dai->component;
	struct wm8776_priv *wm8776 = snd_soc_component_get_drvdata(component);

	if (WARN_ON(dai->driver->id >= ARRAY_SIZE(wm8776->sysclk)))
		return -EINVAL;

	wm8776->sysclk[dai->driver->id] = freq;

	return 0;
}

__attribute__((used)) static int wm8776_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct wm8776_priv *wm8776 = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			regcache_sync(wm8776->regmap);

			/* Disable the global powerdown; DAPM does the rest */
			snd_soc_component_update_bits(component, WM8776_PWRDOWN, 1, 0);
		}

		break;
	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, WM8776_PWRDOWN, 1, 1);
		break;
	}

	return 0;
}

__attribute__((used)) static int wm8776_probe(struct snd_soc_component *component)
{
	int ret = 0;

	ret = wm8776_reset(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to issue reset: %d\n", ret);
		return ret;
	}

	/* Latch the update bits; right channel only since we always
	 * update both. */
	snd_soc_component_update_bits(component, WM8776_HPRVOL, 0x100, 0x100);
	snd_soc_component_update_bits(component, WM8776_DACRVOL, 0x100, 0x100);

	return ret;
}


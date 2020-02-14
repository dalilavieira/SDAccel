#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct wm8737_priv {int mclk; TYPE_1__* supplies; int /*<<< orphan*/  regmap; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_5__ {scalar_t__ rate; int mclk; int usb; int sr; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
#define  SND_SOC_BIAS_OFF 141 
#define  SND_SOC_BIAS_ON 140 
#define  SND_SOC_BIAS_PREPARE 139 
#define  SND_SOC_BIAS_STANDBY 138 
#define  SND_SOC_DAIFMT_CBM_CFM 137 
#define  SND_SOC_DAIFMT_CBS_CFS 136 
#define  SND_SOC_DAIFMT_DSP_A 135 
#define  SND_SOC_DAIFMT_DSP_B 134 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 133 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 132 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 131 
#define  SND_SOC_DAIFMT_NB_NF 130 
#define  SND_SOC_DAIFMT_RIGHT_J 129 
 int /*<<< orphan*/  WM8737_AUDIO_FORMAT ; 
 int WM8737_CLKDIV2 ; 
 int /*<<< orphan*/  WM8737_CLOCKING ; 
 int WM8737_FORMAT_MASK ; 
 int /*<<< orphan*/  WM8737_LEFT_PGA_VOLUME ; 
 int WM8737_LRP ; 
 int WM8737_LVU ; 
 int /*<<< orphan*/  WM8737_MISC_BIAS_CONTROL ; 
 int WM8737_MS ; 
 int /*<<< orphan*/  WM8737_POWER_MANAGEMENT ; 
#define  WM8737_RESET 128 
 int /*<<< orphan*/  WM8737_RIGHT_PGA_VOLUME ; 
 int WM8737_RVU ; 
 int WM8737_SR_MASK ; 
 int WM8737_SR_SHIFT ; 
 int WM8737_USB_MODE ; 
 int WM8737_VMIDSEL_MASK ; 
 int WM8737_VMIDSEL_SHIFT ; 
 int WM8737_VMID_MASK ; 
 int WM8737_VREF_MASK ; 
 int WM8737_WL_MASK ; 
 TYPE_1__* coeff_div ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_1__*) ; 
 int regulator_bulk_enable (int,TYPE_1__*) ; 
 int /*<<< orphan*/  snd_soc_component_force_bias_level (struct snd_soc_component*,int const) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct wm8737_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int const,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool wm8737_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8737_RESET:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int wm8737_reset(struct snd_soc_component *component)
{
	return snd_soc_component_write(component, WM8737_RESET, 0);
}

__attribute__((used)) static int wm8737_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8737_priv *wm8737 = snd_soc_component_get_drvdata(component);
	int i;
	u16 clocking = 0;
	u16 af = 0;

	for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
		if (coeff_div[i].rate != params_rate(params))
			continue;

		if (coeff_div[i].mclk == wm8737->mclk)
			break;

		if (coeff_div[i].mclk == wm8737->mclk * 2) {
			clocking |= WM8737_CLKDIV2;
			break;
		}
	}

	if (i == ARRAY_SIZE(coeff_div)) {
		dev_err(component->dev, "%dHz MCLK can't support %dHz\n",
			wm8737->mclk, params_rate(params));
		return -EINVAL;
	}

	clocking |= coeff_div[i].usb | (coeff_div[i].sr << WM8737_SR_SHIFT);

	switch (params_width(params)) {
	case 16:
		break;
	case 20:
		af |= 0x8;
		break;
	case 24:
		af |= 0x10;
		break;
	case 32:
		af |= 0x18;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, WM8737_AUDIO_FORMAT, WM8737_WL_MASK, af);
	snd_soc_component_update_bits(component, WM8737_CLOCKING,
			    WM8737_USB_MODE | WM8737_CLKDIV2 | WM8737_SR_MASK,
			    clocking);

	return 0;
}

__attribute__((used)) static int wm8737_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct wm8737_priv *wm8737 = snd_soc_component_get_drvdata(component);
	int i;

	for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
		if (freq == coeff_div[i].mclk ||
		    freq == coeff_div[i].mclk * 2) {
			wm8737->mclk = freq;
			return 0;
		}
	}

	dev_err(component->dev, "MCLK rate %dHz not supported\n", freq);

	return -EINVAL;
}

__attribute__((used)) static int wm8737_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u16 af = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		af |= WM8737_MS;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		af |= 0x2;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		af |= 0x1;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		af |= 0x3;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		af |= 0x13;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_NB_IF:
		af |= WM8737_LRP;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, WM8737_AUDIO_FORMAT,
			    WM8737_FORMAT_MASK | WM8737_LRP | WM8737_MS, af);

	return 0;
}

__attribute__((used)) static int wm8737_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct wm8737_priv *wm8737 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		/* VMID at 2*75k */
		snd_soc_component_update_bits(component, WM8737_MISC_BIAS_CONTROL,
				    WM8737_VMIDSEL_MASK, 0);
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			ret = regulator_bulk_enable(ARRAY_SIZE(wm8737->supplies),
						    wm8737->supplies);
			if (ret != 0) {
				dev_err(component->dev,
					"Failed to enable supplies: %d\n",
					ret);
				return ret;
			}

			regcache_sync(wm8737->regmap);

			/* Fast VMID ramp at 2*2.5k */
			snd_soc_component_update_bits(component, WM8737_MISC_BIAS_CONTROL,
					    WM8737_VMIDSEL_MASK,
					    2 << WM8737_VMIDSEL_SHIFT);

			/* Bring VMID up */
			snd_soc_component_update_bits(component, WM8737_POWER_MANAGEMENT,
					    WM8737_VMID_MASK |
					    WM8737_VREF_MASK,
					    WM8737_VMID_MASK |
					    WM8737_VREF_MASK);

			msleep(500);
		}

		/* VMID at 2*300k */
		snd_soc_component_update_bits(component, WM8737_MISC_BIAS_CONTROL,
				    WM8737_VMIDSEL_MASK,
				    1 << WM8737_VMIDSEL_SHIFT);

		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, WM8737_POWER_MANAGEMENT,
				    WM8737_VMID_MASK | WM8737_VREF_MASK, 0);

		regulator_bulk_disable(ARRAY_SIZE(wm8737->supplies),
				       wm8737->supplies);
		break;
	}

	return 0;
}

__attribute__((used)) static int wm8737_probe(struct snd_soc_component *component)
{
	struct wm8737_priv *wm8737 = snd_soc_component_get_drvdata(component);
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(wm8737->supplies),
				    wm8737->supplies);
	if (ret != 0) {
		dev_err(component->dev, "Failed to enable supplies: %d\n", ret);
		goto err_get;
	}

	ret = wm8737_reset(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to issue reset\n");
		goto err_enable;
	}

	snd_soc_component_update_bits(component, WM8737_LEFT_PGA_VOLUME, WM8737_LVU,
			    WM8737_LVU);
	snd_soc_component_update_bits(component, WM8737_RIGHT_PGA_VOLUME, WM8737_RVU,
			    WM8737_RVU);

	snd_soc_component_force_bias_level(component, SND_SOC_BIAS_STANDBY);

	/* Bias level configuration will have done an extra enable */
	regulator_bulk_disable(ARRAY_SIZE(wm8737->supplies), wm8737->supplies);

	return 0;

err_enable:
	regulator_bulk_disable(ARRAY_SIZE(wm8737->supplies), wm8737->supplies);
err_get:
	return ret;
}


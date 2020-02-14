#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct wm8711_priv {int sysclk; int /*<<< orphan*/  regmap; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_3__ {int rate; int mclk; int sr; int bosr; int usb; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
#define  SND_SOC_BIAS_OFF 143 
#define  SND_SOC_BIAS_ON 142 
#define  SND_SOC_BIAS_PREPARE 141 
#define  SND_SOC_BIAS_STANDBY 140 
#define  SND_SOC_DAIFMT_CBM_CFM 139 
#define  SND_SOC_DAIFMT_CBS_CFS 138 
#define  SND_SOC_DAIFMT_DSP_A 137 
#define  SND_SOC_DAIFMT_DSP_B 136 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 135 
#define  SND_SOC_DAIFMT_IB_IF 134 
#define  SND_SOC_DAIFMT_IB_NF 133 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 132 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 131 
#define  SND_SOC_DAIFMT_NB_NF 130 
#define  SND_SOC_DAIFMT_RIGHT_J 129 
 int /*<<< orphan*/  WM8711_ACTIVE ; 
 int /*<<< orphan*/  WM8711_APDIGI ; 
 int /*<<< orphan*/  WM8711_IFACE ; 
 int /*<<< orphan*/  WM8711_LOUT1V ; 
 int /*<<< orphan*/  WM8711_PWR ; 
#define  WM8711_RESET 128 
 int /*<<< orphan*/  WM8711_ROUT1V ; 
 int /*<<< orphan*/  WM8711_SRATE ; 
 TYPE_1__* coeff_div ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct wm8711_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_is_active (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int wm8711_reset (struct snd_soc_component*) ; 

__attribute__((used)) static bool wm8711_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8711_RESET:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static inline int get_coeff(int mclk, int rate)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
		if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
			return i;
	}
	return 0;
}

__attribute__((used)) static int wm8711_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8711_priv *wm8711 =  snd_soc_component_get_drvdata(component);
	u16 iface = snd_soc_component_read32(component, WM8711_IFACE) & 0xfff3;
	int i = get_coeff(wm8711->sysclk, params_rate(params));
	u16 srate = (coeff_div[i].sr << 2) |
		(coeff_div[i].bosr << 1) | coeff_div[i].usb;

	snd_soc_component_write(component, WM8711_SRATE, srate);

	/* bit size */
	switch (params_width(params)) {
	case 16:
		break;
	case 20:
		iface |= 0x0004;
		break;
	case 24:
		iface |= 0x0008;
		break;
	}

	snd_soc_component_write(component, WM8711_IFACE, iface);
	return 0;
}

__attribute__((used)) static int wm8711_pcm_prepare(struct snd_pcm_substream *substream,
			      struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;

	/* set active */
	snd_soc_component_write(component, WM8711_ACTIVE, 0x0001);

	return 0;
}

__attribute__((used)) static void wm8711_shutdown(struct snd_pcm_substream *substream,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;

	/* deactivate */
	if (!snd_soc_component_is_active(component)) {
		udelay(50);
		snd_soc_component_write(component, WM8711_ACTIVE, 0x0);
	}
}

__attribute__((used)) static int wm8711_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u16 mute_reg = snd_soc_component_read32(component, WM8711_APDIGI) & 0xfff7;

	if (mute)
		snd_soc_component_write(component, WM8711_APDIGI, mute_reg | 0x8);
	else
		snd_soc_component_write(component, WM8711_APDIGI, mute_reg);

	return 0;
}

__attribute__((used)) static int wm8711_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct wm8711_priv *wm8711 =  snd_soc_component_get_drvdata(component);

	switch (freq) {
	case 11289600:
	case 12000000:
	case 12288000:
	case 16934400:
	case 18432000:
		wm8711->sysclk = freq;
		return 0;
	}
	return -EINVAL;
}

__attribute__((used)) static int wm8711_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u16 iface = snd_soc_component_read32(component, WM8711_IFACE) & 0x000c;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		iface |= 0x0040;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		iface |= 0x0002;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		iface |= 0x0001;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		iface |= 0x0003;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		iface |= 0x0013;
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_IF:
		iface |= 0x0090;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		iface |= 0x0080;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		iface |= 0x0010;
		break;
	default:
		return -EINVAL;
	}

	/* set iface */
	snd_soc_component_write(component, WM8711_IFACE, iface);
	return 0;
}

__attribute__((used)) static int wm8711_set_bias_level(struct snd_soc_component *component,
	enum snd_soc_bias_level level)
{
	struct wm8711_priv *wm8711 = snd_soc_component_get_drvdata(component);
	u16 reg = snd_soc_component_read32(component, WM8711_PWR) & 0xff7f;

	switch (level) {
	case SND_SOC_BIAS_ON:
		snd_soc_component_write(component, WM8711_PWR, reg);
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF)
			regcache_sync(wm8711->regmap);

		snd_soc_component_write(component, WM8711_PWR, reg | 0x0040);
		break;
	case SND_SOC_BIAS_OFF:
		snd_soc_component_write(component, WM8711_ACTIVE, 0x0);
		snd_soc_component_write(component, WM8711_PWR, 0xffff);
		break;
	}
	return 0;
}

__attribute__((used)) static int wm8711_probe(struct snd_soc_component *component)
{
	int ret;

	ret = wm8711_reset(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to issue reset\n");
		return ret;
	}

	/* Latch the update bits */
	snd_soc_component_update_bits(component, WM8711_LOUT1V, 0x0100, 0x0100);
	snd_soc_component_update_bits(component, WM8711_ROUT1V, 0x0100, 0x0100);

	return ret;

}


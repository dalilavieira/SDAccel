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
struct wm8988_priv {unsigned int sysclk; int /*<<< orphan*/  regmap; int /*<<< orphan*/ * sysclk_constraints; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_3__ {int rate; int mclk; int sr; int usb; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_BIAS_OFF 176 
#define  SND_SOC_BIAS_ON 175 
#define  SND_SOC_BIAS_PREPARE 174 
#define  SND_SOC_BIAS_STANDBY 173 
#define  SND_SOC_DAIFMT_CBM_CFM 172 
#define  SND_SOC_DAIFMT_CBS_CFS 171 
#define  SND_SOC_DAIFMT_DSP_A 170 
#define  SND_SOC_DAIFMT_DSP_B 169 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 168 
#define  SND_SOC_DAIFMT_IB_IF 167 
#define  SND_SOC_DAIFMT_IB_NF 166 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 165 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 164 
#define  SND_SOC_DAIFMT_NB_NF 163 
#define  SND_SOC_DAIFMT_RIGHT_J 162 
#define  WM8988_3D 161 
#define  WM8988_ADCDAC 160 
#define  WM8988_ADCIN 159 
#define  WM8988_ADCTL1 158 
#define  WM8988_ADCTL2 157 
#define  WM8988_ADCTL3 156 
#define  WM8988_ALC1 155 
#define  WM8988_ALC2 154 
#define  WM8988_ALC3 153 
#define  WM8988_BASS 152 
#define  WM8988_IFACE 151 
#define  WM8988_LADC 150 
#define  WM8988_LADCIN 149 
#define  WM8988_LDAC 148 
#define  WM8988_LINVOL 147 
#define  WM8988_LOUT1V 146 
#define  WM8988_LOUT2V 145 
#define  WM8988_LOUTM1 144 
#define  WM8988_LOUTM2 143 
#define  WM8988_LPPB 142 
#define  WM8988_NGATE 141 
#define  WM8988_PWR1 140 
#define  WM8988_PWR2 139 
#define  WM8988_RADC 138 
#define  WM8988_RADCIN 137 
#define  WM8988_RDAC 136 
#define  WM8988_RESET 135 
#define  WM8988_RINVOL 134 
#define  WM8988_ROUT1V 133 
#define  WM8988_ROUT2V 132 
#define  WM8988_ROUTM1 131 
#define  WM8988_ROUTM2 130 
#define  WM8988_SRATE 129 
#define  WM8988_TREBLE 128 
 TYPE_1__* coeff_div ; 
 int /*<<< orphan*/  constraints_112896 ; 
 int /*<<< orphan*/  constraints_12 ; 
 int /*<<< orphan*/  constraints_12288 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct wm8988_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int const,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int wm8988_reset (struct snd_soc_component*) ; 

__attribute__((used)) static bool wm8988_writeable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8988_LINVOL:
	case WM8988_RINVOL:
	case WM8988_LOUT1V:
	case WM8988_ROUT1V:
	case WM8988_ADCDAC:
	case WM8988_IFACE:
	case WM8988_SRATE:
	case WM8988_LDAC:
	case WM8988_RDAC:
	case WM8988_BASS:
	case WM8988_TREBLE:
	case WM8988_RESET:
	case WM8988_3D:
	case WM8988_ALC1:
	case WM8988_ALC2:
	case WM8988_ALC3:
	case WM8988_NGATE:
	case WM8988_LADC:
	case WM8988_RADC:
	case WM8988_ADCTL1:
	case WM8988_ADCTL2:
	case WM8988_PWR1:
	case WM8988_PWR2:
	case WM8988_ADCTL3:
	case WM8988_ADCIN:
	case WM8988_LADCIN:
	case WM8988_RADCIN:
	case WM8988_LOUTM1:
	case WM8988_LOUTM2:
	case WM8988_ROUTM1:
	case WM8988_ROUTM2:
	case WM8988_LOUT2V:
	case WM8988_ROUT2V:
	case WM8988_LPPB:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int wm8988_lrc_control(struct snd_soc_dapm_widget *w,
			      struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	u16 adctl2 = snd_soc_component_read32(component, WM8988_ADCTL2);

	/* Use the DAC to gate LRC if active, otherwise use ADC */
	if (snd_soc_component_read32(component, WM8988_PWR2) & 0x180)
		adctl2 &= ~0x4;
	else
		adctl2 |= 0x4;

	return snd_soc_component_write(component, WM8988_ADCTL2, adctl2);
}

__attribute__((used)) static inline int get_coeff(int mclk, int rate)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
		if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
			return i;
	}

	return -EINVAL;
}

__attribute__((used)) static int wm8988_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct wm8988_priv *wm8988 = snd_soc_component_get_drvdata(component);

	switch (freq) {
	case 11289600:
	case 18432000:
	case 22579200:
	case 36864000:
		wm8988->sysclk_constraints = &constraints_112896;
		wm8988->sysclk = freq;
		return 0;

	case 12288000:
	case 16934400:
	case 24576000:
	case 33868800:
		wm8988->sysclk_constraints = &constraints_12288;
		wm8988->sysclk = freq;
		return 0;

	case 12000000:
	case 24000000:
		wm8988->sysclk_constraints = &constraints_12;
		wm8988->sysclk = freq;
		return 0;
	}
	return -EINVAL;
}

__attribute__((used)) static int wm8988_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u16 iface = 0;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		iface = 0x0040;
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

	snd_soc_component_write(component, WM8988_IFACE, iface);
	return 0;
}

__attribute__((used)) static int wm8988_pcm_startup(struct snd_pcm_substream *substream,
			      struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8988_priv *wm8988 = snd_soc_component_get_drvdata(component);

	/* The set of sample rates that can be supported depends on the
	 * MCLK supplied to the CODEC - enforce this.
	 */
	if (!wm8988->sysclk) {
		dev_err(component->dev,
			"No MCLK configured, call set_sysclk() on init\n");
		return -EINVAL;
	}

	snd_pcm_hw_constraint_list(substream->runtime, 0,
				   SNDRV_PCM_HW_PARAM_RATE,
				   wm8988->sysclk_constraints);

	return 0;
}

__attribute__((used)) static int wm8988_pcm_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8988_priv *wm8988 = snd_soc_component_get_drvdata(component);
	u16 iface = snd_soc_component_read32(component, WM8988_IFACE) & 0x1f3;
	u16 srate = snd_soc_component_read32(component, WM8988_SRATE) & 0x180;
	int coeff;

	coeff = get_coeff(wm8988->sysclk, params_rate(params));
	if (coeff < 0) {
		coeff = get_coeff(wm8988->sysclk / 2, params_rate(params));
		srate |= 0x40;
	}
	if (coeff < 0) {
		dev_err(component->dev,
			"Unable to configure sample rate %dHz with %dHz MCLK\n",
			params_rate(params), wm8988->sysclk);
		return coeff;
	}

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
	case 32:
		iface |= 0x000c;
		break;
	}

	/* set iface & srate */
	snd_soc_component_write(component, WM8988_IFACE, iface);
	if (coeff >= 0)
		snd_soc_component_write(component, WM8988_SRATE, srate |
			(coeff_div[coeff].sr << 1) | coeff_div[coeff].usb);

	return 0;
}

__attribute__((used)) static int wm8988_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u16 mute_reg = snd_soc_component_read32(component, WM8988_ADCDAC) & 0xfff7;

	if (mute)
		snd_soc_component_write(component, WM8988_ADCDAC, mute_reg | 0x8);
	else
		snd_soc_component_write(component, WM8988_ADCDAC, mute_reg);
	return 0;
}

__attribute__((used)) static int wm8988_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct wm8988_priv *wm8988 = snd_soc_component_get_drvdata(component);
	u16 pwr_reg = snd_soc_component_read32(component, WM8988_PWR1) & ~0x1c1;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		/* VREF, VMID=2x50k, digital enabled */
		snd_soc_component_write(component, WM8988_PWR1, pwr_reg | 0x00c0);
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			regcache_sync(wm8988->regmap);

			/* VREF, VMID=2x5k */
			snd_soc_component_write(component, WM8988_PWR1, pwr_reg | 0x1c1);

			/* Charge caps */
			msleep(100);
		}

		/* VREF, VMID=2*500k, digital stopped */
		snd_soc_component_write(component, WM8988_PWR1, pwr_reg | 0x0141);
		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_write(component, WM8988_PWR1, 0x0000);
		break;
	}
	return 0;
}

__attribute__((used)) static int wm8988_probe(struct snd_soc_component *component)
{
	int ret = 0;

	ret = wm8988_reset(component);
	if (ret < 0) {
		dev_err(component->dev, "Failed to issue reset\n");
		return ret;
	}

	/* set the update bits (we always update left then right) */
	snd_soc_component_update_bits(component, WM8988_RADC, 0x0100, 0x0100);
	snd_soc_component_update_bits(component, WM8988_RDAC, 0x0100, 0x0100);
	snd_soc_component_update_bits(component, WM8988_ROUT1V, 0x0100, 0x0100);
	snd_soc_component_update_bits(component, WM8988_ROUT2V, 0x0100, 0x0100);
	snd_soc_component_update_bits(component, WM8988_RINVOL, 0x0100, 0x0100);

	return 0;
}


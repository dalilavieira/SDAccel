#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; int /*<<< orphan*/  name; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {size_t id; struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {scalar_t__ stream; int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {unsigned int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
struct adav80x {int clk_src; scalar_t__ pll_src; unsigned int deemph; int rate; unsigned int* dai_fmt; unsigned int sysclk; int* sysclk_pd; struct regmap* regmap; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  ADAV80X_ADC_CTRL1 ; 
 unsigned int ADAV80X_ADC_CTRL1_MODULATOR_128FS ; 
 unsigned int ADAV80X_ADC_CTRL1_MODULATOR_64FS ; 
 unsigned int ADAV80X_ADC_CTRL1_MODULATOR_MASK ; 
 unsigned int ADAV80X_CAPTRUE_WORD_LEN18 ; 
 unsigned int ADAV80X_CAPTURE_MODE_I2S ; 
 unsigned int ADAV80X_CAPTURE_MODE_LEFT_J ; 
 unsigned int ADAV80X_CAPTURE_MODE_MASK ; 
 unsigned int ADAV80X_CAPTURE_MODE_MASTER ; 
 unsigned int ADAV80X_CAPTURE_MODE_RIGHT_J ; 
 unsigned int ADAV80X_CAPTURE_WORD_LEN16 ; 
 unsigned int ADAV80X_CAPTURE_WORD_LEN20 ; 
 unsigned int ADAV80X_CAPTURE_WORD_LEN24 ; 
 unsigned int ADAV80X_CAPTURE_WORD_LEN_MASK ; 
#define  ADAV80X_CLK_MCLKI 148 
#define  ADAV80X_CLK_PLL1 147 
#define  ADAV80X_CLK_PLL2 146 
#define  ADAV80X_CLK_SYSCLK1 145 
#define  ADAV80X_CLK_SYSCLK2 144 
#define  ADAV80X_CLK_SYSCLK3 143 
#define  ADAV80X_CLK_XIN 142 
#define  ADAV80X_CLK_XTAL 141 
 int /*<<< orphan*/  ADAV80X_DAC_CTRL1 ; 
 unsigned int ADAV80X_DAC_CTRL1_PD ; 
 int /*<<< orphan*/  ADAV80X_DAC_CTRL2 ; 
 unsigned int ADAV80X_DAC_CTRL2_DEEMPH_32 ; 
 unsigned int ADAV80X_DAC_CTRL2_DEEMPH_44 ; 
 unsigned int ADAV80X_DAC_CTRL2_DEEMPH_48 ; 
 unsigned int ADAV80X_DAC_CTRL2_DEEMPH_MASK ; 
 unsigned int ADAV80X_DAC_CTRL2_DEEMPH_NONE ; 
 unsigned int ADAV80X_DAC_CTRL2_DIV1 ; 
 unsigned int ADAV80X_DAC_CTRL2_DIV2 ; 
 unsigned int ADAV80X_DAC_CTRL2_DIV_MASK ; 
 unsigned int ADAV80X_DAC_CTRL2_INTERPOL_128FS ; 
 unsigned int ADAV80X_DAC_CTRL2_INTERPOL_256FS ; 
 unsigned int ADAV80X_DAC_CTRL2_INTERPOL_MASK ; 
 int /*<<< orphan*/  ADAV80X_DAC_CTRL3 ; 
 int /*<<< orphan*/  ADAV80X_ICLK_CTRL1 ; 
 unsigned int ADAV80X_ICLK_CTRL1_ADC_SRC (int) ; 
 unsigned int ADAV80X_ICLK_CTRL1_DAC_SRC (int) ; 
 unsigned int ADAV80X_ICLK_CTRL1_ICLK2_SRC (int) ; 
 int /*<<< orphan*/  ADAV80X_ICLK_CTRL2 ; 
 unsigned int ADAV80X_ICLK_CTRL2_ICLK1_SRC (int) ; 
 unsigned int ADAV80X_PLAYBACK_MODE_I2S ; 
 unsigned int ADAV80X_PLAYBACK_MODE_LEFT_J ; 
 unsigned int ADAV80X_PLAYBACK_MODE_MASK ; 
 unsigned int ADAV80X_PLAYBACK_MODE_MASTER ; 
 unsigned int ADAV80X_PLAYBACK_MODE_RIGHT_J_16 ; 
 unsigned int ADAV80X_PLAYBACK_MODE_RIGHT_J_18 ; 
 unsigned int ADAV80X_PLAYBACK_MODE_RIGHT_J_20 ; 
 unsigned int ADAV80X_PLAYBACK_MODE_RIGHT_J_24 ; 
 int /*<<< orphan*/  ADAV80X_PLL_CLK_SRC ; 
 unsigned int ADAV80X_PLL_CLK_SRC_PLL_MASK (int) ; 
 unsigned int ADAV80X_PLL_CLK_SRC_PLL_MCLKI (int) ; 
 unsigned int ADAV80X_PLL_CLK_SRC_PLL_XIN (int) ; 
 int /*<<< orphan*/  ADAV80X_PLL_CTRL1 ; 
 unsigned int ADAV80X_PLL_CTRL1_PLLDIV ; 
 int /*<<< orphan*/  ADAV80X_PLL_CTRL2 ; 
 unsigned int ADAV80X_PLL_CTRL2_DOUB (int) ; 
 unsigned int ADAV80X_PLL_CTRL2_FS_32 (int) ; 
 unsigned int ADAV80X_PLL_CTRL2_FS_44 (int) ; 
 unsigned int ADAV80X_PLL_CTRL2_FS_48 (int) ; 
 unsigned int ADAV80X_PLL_CTRL2_PLL_MASK (int) ; 
 int /*<<< orphan*/  ADAV80X_PLL_OUTE ; 
 unsigned int ADAV80X_PLL_OUTE_SYSCLKPD (int) ; 
#define  ADAV80X_PLL_SRC_MCLKI 140 
#define  ADAV80X_PLL_SRC_XIN 139 
#define  ADAV80X_PLL_SRC_XTAL 138 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 137 
#define  SND_SOC_BIAS_ON 136 
#define  SND_SOC_BIAS_PREPARE 135 
#define  SND_SOC_BIAS_STANDBY 134 
 int SND_SOC_CLOCK_IN ; 
#define  SND_SOC_DAIFMT_CBM_CFM 133 
#define  SND_SOC_DAIFMT_CBS_CFS 132 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 131 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 130 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  adav80x_component_driver ; 
 int /*<<< orphan*/  adav80x_dais ; 
 int /*<<< orphan*/ ** adav80x_port_ctrl_regs ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct adav80x*) ; 
 struct adav80x* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (struct regmap*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int snd_pcm_hw_constraint_single (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct adav80x* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_is_active (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_force_enable_pin (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_force_enable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_lock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_unlock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_sync (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_sync_unlocked (struct snd_soc_dapm_context*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static int adav80x_dapm_sysclk_check(struct snd_soc_dapm_widget *source,
			 struct snd_soc_dapm_widget *sink)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(source->dapm);
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	const char *clk;

	switch (adav80x->clk_src) {
	case ADAV80X_CLK_PLL1:
		clk = "PLL1";
		break;
	case ADAV80X_CLK_PLL2:
		clk = "PLL2";
		break;
	case ADAV80X_CLK_XTAL:
		clk = "OSC";
		break;
	default:
		return 0;
	}

	return strcmp(source->name, clk) == 0;
}

__attribute__((used)) static int adav80x_dapm_pll_check(struct snd_soc_dapm_widget *source,
			 struct snd_soc_dapm_widget *sink)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(source->dapm);
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);

	return adav80x->pll_src == ADAV80X_PLL_SRC_XTAL;
}

__attribute__((used)) static int adav80x_set_deemph(struct snd_soc_component *component)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int val;

	if (adav80x->deemph) {
		switch (adav80x->rate) {
		case 32000:
			val = ADAV80X_DAC_CTRL2_DEEMPH_32;
			break;
		case 44100:
			val = ADAV80X_DAC_CTRL2_DEEMPH_44;
			break;
		case 48000:
		case 64000:
		case 88200:
		case 96000:
			val = ADAV80X_DAC_CTRL2_DEEMPH_48;
			break;
		default:
			val = ADAV80X_DAC_CTRL2_DEEMPH_NONE;
			break;
		}
	} else {
		val = ADAV80X_DAC_CTRL2_DEEMPH_NONE;
	}

	return regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL2,
		ADAV80X_DAC_CTRL2_DEEMPH_MASK, val);
}

__attribute__((used)) static int adav80x_put_deemph(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int deemph = ucontrol->value.integer.value[0];

	if (deemph > 1)
		return -EINVAL;

	adav80x->deemph = deemph;

	return adav80x_set_deemph(component);
}

__attribute__((used)) static int adav80x_get_deemph(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = adav80x->deemph;
	return 0;
}

__attribute__((used)) static int adav80x_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int capture = 0x00;
	unsigned int playback = 0x00;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		capture |= ADAV80X_CAPTURE_MODE_MASTER;
		playback |= ADAV80X_PLAYBACK_MODE_MASTER;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		capture |= ADAV80X_CAPTURE_MODE_I2S;
		playback |= ADAV80X_PLAYBACK_MODE_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		capture |= ADAV80X_CAPTURE_MODE_LEFT_J;
		playback |= ADAV80X_PLAYBACK_MODE_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		capture |= ADAV80X_CAPTURE_MODE_RIGHT_J;
		playback |= ADAV80X_PLAYBACK_MODE_RIGHT_J_24;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][0],
		ADAV80X_CAPTURE_MODE_MASK | ADAV80X_CAPTURE_MODE_MASTER,
		capture);
	regmap_write(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][1],
		playback);

	adav80x->dai_fmt[dai->id] = fmt & SND_SOC_DAIFMT_FORMAT_MASK;

	return 0;
}

__attribute__((used)) static int adav80x_set_adc_clock(struct snd_soc_component *component,
		unsigned int sample_rate)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int val;

	if (sample_rate <= 48000)
		val = ADAV80X_ADC_CTRL1_MODULATOR_128FS;
	else
		val = ADAV80X_ADC_CTRL1_MODULATOR_64FS;

	regmap_update_bits(adav80x->regmap, ADAV80X_ADC_CTRL1,
		ADAV80X_ADC_CTRL1_MODULATOR_MASK, val);

	return 0;
}

__attribute__((used)) static int adav80x_set_dac_clock(struct snd_soc_component *component,
		unsigned int sample_rate)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int val;

	if (sample_rate <= 48000)
		val = ADAV80X_DAC_CTRL2_DIV1 | ADAV80X_DAC_CTRL2_INTERPOL_256FS;
	else
		val = ADAV80X_DAC_CTRL2_DIV2 | ADAV80X_DAC_CTRL2_INTERPOL_128FS;

	regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL2,
		ADAV80X_DAC_CTRL2_DIV_MASK | ADAV80X_DAC_CTRL2_INTERPOL_MASK,
		val);

	return 0;
}

__attribute__((used)) static int adav80x_set_capture_pcm_format(struct snd_soc_component *component,
		struct snd_soc_dai *dai, struct snd_pcm_hw_params *params)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int val;

	switch (params_width(params)) {
	case 16:
		val = ADAV80X_CAPTURE_WORD_LEN16;
		break;
	case 18:
		val = ADAV80X_CAPTRUE_WORD_LEN18;
		break;
	case 20:
		val = ADAV80X_CAPTURE_WORD_LEN20;
		break;
	case 24:
		val = ADAV80X_CAPTURE_WORD_LEN24;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][0],
		ADAV80X_CAPTURE_WORD_LEN_MASK, val);

	return 0;
}

__attribute__((used)) static int adav80x_set_playback_pcm_format(struct snd_soc_component *component,
		struct snd_soc_dai *dai, struct snd_pcm_hw_params *params)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int val;

	if (adav80x->dai_fmt[dai->id] != SND_SOC_DAIFMT_RIGHT_J)
		return 0;

	switch (params_width(params)) {
	case 16:
		val = ADAV80X_PLAYBACK_MODE_RIGHT_J_16;
		break;
	case 18:
		val = ADAV80X_PLAYBACK_MODE_RIGHT_J_18;
		break;
	case 20:
		val = ADAV80X_PLAYBACK_MODE_RIGHT_J_20;
		break;
	case 24:
		val = ADAV80X_PLAYBACK_MODE_RIGHT_J_24;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][1],
		ADAV80X_PLAYBACK_MODE_MASK, val);

	return 0;
}

__attribute__((used)) static int adav80x_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int rate = params_rate(params);

	if (rate * 256 != adav80x->sysclk)
		return -EINVAL;

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		adav80x_set_playback_pcm_format(component, dai, params);
		adav80x_set_dac_clock(component, rate);
	} else {
		adav80x_set_capture_pcm_format(component, dai, params);
		adav80x_set_adc_clock(component, rate);
	}
	adav80x->rate = rate;
	adav80x_set_deemph(component);

	return 0;
}

__attribute__((used)) static int adav80x_set_sysclk(struct snd_soc_component *component,
			      int clk_id, int source,
			      unsigned int freq, int dir)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);

	if (dir == SND_SOC_CLOCK_IN) {
		switch (clk_id) {
		case ADAV80X_CLK_XIN:
		case ADAV80X_CLK_XTAL:
		case ADAV80X_CLK_MCLKI:
		case ADAV80X_CLK_PLL1:
		case ADAV80X_CLK_PLL2:
			break;
		default:
			return -EINVAL;
		}

		adav80x->sysclk = freq;

		if (adav80x->clk_src != clk_id) {
			unsigned int iclk_ctrl1, iclk_ctrl2;

			adav80x->clk_src = clk_id;
			if (clk_id == ADAV80X_CLK_XTAL)
				clk_id = ADAV80X_CLK_XIN;

			iclk_ctrl1 = ADAV80X_ICLK_CTRL1_DAC_SRC(clk_id) |
					ADAV80X_ICLK_CTRL1_ADC_SRC(clk_id) |
					ADAV80X_ICLK_CTRL1_ICLK2_SRC(clk_id);
			iclk_ctrl2 = ADAV80X_ICLK_CTRL2_ICLK1_SRC(clk_id);

			regmap_write(adav80x->regmap, ADAV80X_ICLK_CTRL1,
				iclk_ctrl1);
			regmap_write(adav80x->regmap, ADAV80X_ICLK_CTRL2,
				iclk_ctrl2);

			snd_soc_dapm_sync(dapm);
		}
	} else {
		unsigned int mask;

		switch (clk_id) {
		case ADAV80X_CLK_SYSCLK1:
		case ADAV80X_CLK_SYSCLK2:
		case ADAV80X_CLK_SYSCLK3:
			break;
		default:
			return -EINVAL;
		}

		clk_id -= ADAV80X_CLK_SYSCLK1;
		mask = ADAV80X_PLL_OUTE_SYSCLKPD(clk_id);

		if (freq == 0) {
			regmap_update_bits(adav80x->regmap, ADAV80X_PLL_OUTE,
				mask, mask);
			adav80x->sysclk_pd[clk_id] = true;
		} else {
			regmap_update_bits(adav80x->regmap, ADAV80X_PLL_OUTE,
				mask, 0);
			adav80x->sysclk_pd[clk_id] = false;
		}

		snd_soc_dapm_mutex_lock(dapm);

		if (adav80x->sysclk_pd[0])
			snd_soc_dapm_disable_pin_unlocked(dapm, "PLL1");
		else
			snd_soc_dapm_force_enable_pin_unlocked(dapm, "PLL1");

		if (adav80x->sysclk_pd[1] || adav80x->sysclk_pd[2])
			snd_soc_dapm_disable_pin_unlocked(dapm, "PLL2");
		else
			snd_soc_dapm_force_enable_pin_unlocked(dapm, "PLL2");

		snd_soc_dapm_sync_unlocked(dapm);

		snd_soc_dapm_mutex_unlock(dapm);
	}

	return 0;
}

__attribute__((used)) static int adav80x_set_pll(struct snd_soc_component *component, int pll_id,
		int source, unsigned int freq_in, unsigned int freq_out)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int pll_ctrl1 = 0;
	unsigned int pll_ctrl2 = 0;
	unsigned int pll_src;

	switch (source) {
	case ADAV80X_PLL_SRC_XTAL:
	case ADAV80X_PLL_SRC_XIN:
	case ADAV80X_PLL_SRC_MCLKI:
		break;
	default:
		return -EINVAL;
	}

	if (!freq_out)
		return 0;

	switch (freq_in) {
	case 27000000:
		break;
	case 54000000:
		if (source == ADAV80X_PLL_SRC_XIN) {
			pll_ctrl1 |= ADAV80X_PLL_CTRL1_PLLDIV;
			break;
		}
		/* fall through */
	default:
		return -EINVAL;
	}

	if (freq_out > 12288000) {
		pll_ctrl2 |= ADAV80X_PLL_CTRL2_DOUB(pll_id);
		freq_out /= 2;
	}

	/* freq_out = sample_rate * 256 */
	switch (freq_out) {
	case 8192000:
		pll_ctrl2 |= ADAV80X_PLL_CTRL2_FS_32(pll_id);
		break;
	case 11289600:
		pll_ctrl2 |= ADAV80X_PLL_CTRL2_FS_44(pll_id);
		break;
	case 12288000:
		pll_ctrl2 |= ADAV80X_PLL_CTRL2_FS_48(pll_id);
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adav80x->regmap, ADAV80X_PLL_CTRL1,
			ADAV80X_PLL_CTRL1_PLLDIV, pll_ctrl1);
	regmap_update_bits(adav80x->regmap, ADAV80X_PLL_CTRL2,
			ADAV80X_PLL_CTRL2_PLL_MASK(pll_id), pll_ctrl2);

	if (source != adav80x->pll_src) {
		if (source == ADAV80X_PLL_SRC_MCLKI)
			pll_src = ADAV80X_PLL_CLK_SRC_PLL_MCLKI(pll_id);
		else
			pll_src = ADAV80X_PLL_CLK_SRC_PLL_XIN(pll_id);

		regmap_update_bits(adav80x->regmap, ADAV80X_PLL_CLK_SRC,
				ADAV80X_PLL_CLK_SRC_PLL_MASK(pll_id), pll_src);

		adav80x->pll_src = source;

		snd_soc_dapm_sync(dapm);
	}

	return 0;
}

__attribute__((used)) static int adav80x_set_bias_level(struct snd_soc_component *component,
		enum snd_soc_bias_level level)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);
	unsigned int mask = ADAV80X_DAC_CTRL1_PD;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL1, mask,
			0x00);
		break;
	case SND_SOC_BIAS_OFF:
		regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL1, mask,
			mask);
		break;
	}

	return 0;
}

__attribute__((used)) static int adav80x_dai_startup(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);

	if (!snd_soc_component_is_active(component) || !adav80x->rate)
		return 0;

	return snd_pcm_hw_constraint_single(substream->runtime,
			SNDRV_PCM_HW_PARAM_RATE, adav80x->rate);
}

__attribute__((used)) static void adav80x_dai_shutdown(struct snd_pcm_substream *substream,
		struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);

	if (!snd_soc_component_is_active(component))
		adav80x->rate = 0;
}

__attribute__((used)) static int adav80x_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);

	/* Force PLLs on for SYSCLK output */
	snd_soc_dapm_force_enable_pin(dapm, "PLL1");
	snd_soc_dapm_force_enable_pin(dapm, "PLL2");

	/* Power down S/PDIF receiver, since it is currently not supported */
	regmap_write(adav80x->regmap, ADAV80X_PLL_OUTE, 0x20);
	/* Disable DAC zero flag */
	regmap_write(adav80x->regmap, ADAV80X_DAC_CTRL3, 0x6);

	return 0;
}

__attribute__((used)) static int adav80x_resume(struct snd_soc_component *component)
{
	struct adav80x *adav80x = snd_soc_component_get_drvdata(component);

	regcache_sync(adav80x->regmap);

	return 0;
}

int adav80x_bus_probe(struct device *dev, struct regmap *regmap)
{
	struct adav80x *adav80x;

	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	adav80x = devm_kzalloc(dev, sizeof(*adav80x), GFP_KERNEL);
	if (!adav80x)
		return -ENOMEM;

	dev_set_drvdata(dev, adav80x);
	adav80x->regmap = regmap;

	return devm_snd_soc_register_component(dev, &adav80x_component_driver,
		adav80x_dais, ARRAY_SIZE(adav80x_dais));
}


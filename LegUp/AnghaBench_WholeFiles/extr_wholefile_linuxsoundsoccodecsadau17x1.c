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
struct soc_enum {unsigned int shift_l; scalar_t__ items; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_update {int mask; int reg; unsigned int val; struct snd_kcontrol* kcontrol; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_3__ {scalar_t__* item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct regmap {unsigned int current_samplerate; } ;
struct device {int dummy; } ;
struct adau {int* pll_regs; int* dsp_bypass; int* tdm_slot; int type; unsigned int pll_freq; int clk_src; unsigned int sysclk; scalar_t__ dai_fmt; int master; void (* switch_mode ) (struct device*) ;struct regmap* mclk; struct regmap* sigmadsp; struct regmap* regmap; } ;
typedef  enum adau17x1_type { ____Placeholder_adau17x1_type } adau17x1_type ;
typedef  enum adau17x1_micbias_voltage { ____Placeholder_adau17x1_micbias_voltage } adau17x1_micbias_voltage ;

/* Variables and functions */
 int ADAU1361 ; 
#define  ADAU1381 170 
#define  ADAU1761 169 
#define  ADAU1781 168 
#define  ADAU17X1_ADC_CONTROL 167 
#define  ADAU17X1_CLK_SRC_MCLK 166 
#define  ADAU17X1_CLK_SRC_PLL 165 
#define  ADAU17X1_CLK_SRC_PLL_AUTO 164 
#define  ADAU17X1_CLOCK_CONTROL 163 
 unsigned int ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL ; 
#define  ADAU17X1_CONTROL_PORT_PAD0 162 
#define  ADAU17X1_CONTROL_PORT_PAD1 161 
#define  ADAU17X1_CONVERTER0 160 
 unsigned int ADAU17X1_CONVERTER0_ADOSR ; 
 unsigned int ADAU17X1_CONVERTER0_CONVSR_MASK ; 
 unsigned int ADAU17X1_CONVERTER0_DAC_PAIR (int) ; 
 unsigned int ADAU17X1_CONVERTER0_DAC_PAIR_MASK ; 
#define  ADAU17X1_CONVERTER1 159 
 unsigned int ADAU17X1_CONVERTER1_ADC_PAIR (int) ; 
 unsigned int ADAU17X1_CONVERTER1_ADC_PAIR_MASK ; 
#define  ADAU17X1_DAC_CONTROL0 158 
#define  ADAU17X1_DAC_CONTROL1 157 
#define  ADAU17X1_DAC_CONTROL2 156 
#define  ADAU17X1_DSP_ENABLE 155 
#define  ADAU17X1_DSP_RUN 154 
#define  ADAU17X1_DSP_SAMPLING_RATE 153 
#define  ADAU17X1_LEFT_INPUT_DIGITAL_VOL 152 
#define  ADAU17X1_MICBIAS 151 
#define  ADAU17X1_MICBIAS_0_65_AVDD 150 
#define  ADAU17X1_MICBIAS_0_90_AVDD 149 
#define  ADAU17X1_PLAY_POWER_MGMT 148 
 int ADAU17X1_PLL ; 
#define  ADAU17X1_PLL_CONTROL 147 
 int ADAU17X1_PLL_SRC_MCLK ; 
#define  ADAU17X1_REC_POWER_MGMT 146 
#define  ADAU17X1_RIGHT_INPUT_DIGITAL_VOL 145 
#define  ADAU17X1_SERIAL_INPUT_ROUTE 144 
#define  ADAU17X1_SERIAL_OUTPUT_ROUTE 143 
#define  ADAU17X1_SERIAL_PORT0 142 
 unsigned int ADAU17X1_SERIAL_PORT0_BCLK_POL ; 
 unsigned int ADAU17X1_SERIAL_PORT0_LRCLK_POL ; 
 unsigned int ADAU17X1_SERIAL_PORT0_MASTER ; 
 unsigned int ADAU17X1_SERIAL_PORT0_PULSE_MODE ; 
 unsigned int ADAU17X1_SERIAL_PORT0_STEREO ; 
 unsigned int ADAU17X1_SERIAL_PORT0_TDM4 ; 
 unsigned int ADAU17X1_SERIAL_PORT0_TDM8 ; 
 unsigned int ADAU17X1_SERIAL_PORT0_TDM_MASK ; 
#define  ADAU17X1_SERIAL_PORT1 141 
 unsigned int ADAU17X1_SERIAL_PORT1_BCLK128 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_BCLK256 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_BCLK32 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_BCLK48 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_BCLK64 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_BCLK_MASK ; 
 unsigned int ADAU17X1_SERIAL_PORT1_DELAY0 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_DELAY1 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_DELAY16 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_DELAY8 ; 
 unsigned int ADAU17X1_SERIAL_PORT1_DELAY_MASK ; 
#define  ADAU17X1_SERIAL_PORT_PAD 140 
#define  ADAU17X1_SERIAL_SAMPLING_RATE 139 
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
 unsigned int SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_DAIFMT_CBM_CFM 138 
#define  SND_SOC_DAIFMT_CBS_CFS 137 
#define  SND_SOC_DAIFMT_DSP_A 136 
#define  SND_SOC_DAIFMT_DSP_B 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_IF 133 
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 130 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 scalar_t__ SND_SOC_DAPM_EVENT_ON (int) ; 
 int* adau17x1_controls ; 
 int adau17x1_dapm_pll_route ; 
 int* adau17x1_dapm_routes ; 
 int* adau17x1_dapm_widgets ; 
 int* adau17x1_dsp_dapm_routes ; 
 int* adau17x1_dsp_dapm_widgets ; 
 int* adau17x1_no_dsp_dapm_routes ; 
 int adau17x1_setup_firmware (struct snd_soc_component*,unsigned int) ; 
 int adau_calc_pll_cfg (unsigned int,int,int*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct regmap*) ; 
 unsigned int clk_get_rate (struct regmap*) ; 
 int clk_prepare_enable (struct regmap*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct adau* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct adau*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 struct regmap* devm_clk_get (struct device*,char*) ; 
 struct adau* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_sigmadsp_init_regmap (struct device*,struct regmap*,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (struct regmap*) ; 
 int regmap_raw_write (struct regmap*,int,int*,int) ; 
 int regmap_read (struct regmap*,int const,...) ; 
 int regmap_update_bits (struct regmap*,int,unsigned int,unsigned int) ; 
 int regmap_write (struct regmap*,int const,int) ; 
 int sigmadsp_attach (struct regmap*,struct snd_soc_component*) ; 
 int sigmadsp_restrict_params (struct regmap*,struct snd_pcm_substream*) ; 
 int sigmadsp_setup (struct regmap*,unsigned int) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int*,int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct adau* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 unsigned int snd_soc_component_test_bits (struct snd_soc_component*,int,int,unsigned int) ; 
 struct adau* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,int*,int) ; 
 int /*<<< orphan*/  snd_soc_dapm_del_routes (struct snd_soc_dapm_context*,int*,int) ; 
 struct snd_soc_component* snd_soc_dapm_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_lock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_unlock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mux_update_power (struct snd_soc_dapm_context*,struct snd_kcontrol*,scalar_t__,struct soc_enum*,struct snd_soc_dapm_update*) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int*,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 void stub1 (struct device*) ; 

__attribute__((used)) static int adau17x1_pll_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct adau *adau = snd_soc_component_get_drvdata(component);

	if (SND_SOC_DAPM_EVENT_ON(event)) {
		adau->pll_regs[5] = 1;
	} else {
		adau->pll_regs[5] = 0;
		/* Bypass the PLL when disabled, otherwise registers will become
		 * inaccessible. */
		regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
			ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL, 0);
	}

	/* The PLL register is 6 bytes long and can only be written at once. */
	regmap_raw_write(adau->regmap, ADAU17X1_PLL_CONTROL,
			adau->pll_regs, ARRAY_SIZE(adau->pll_regs));

	if (SND_SOC_DAPM_EVENT_ON(event)) {
		mdelay(5);
		regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
			ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL,
			ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL);
	}

	return 0;
}

__attribute__((used)) static int adau17x1_adc_fixup(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct adau *adau = snd_soc_component_get_drvdata(component);

	/*
	 * If we are capturing, toggle the ADOSR bit in Converter Control 0 to
	 * avoid losing SNR (workaround from ADI). This must be done after
	 * the ADC(s) have been enabled. According to the data sheet, it is
	 * normally illegal to set this bit when the sampling rate is 96 kHz,
	 * but according to ADI it is acceptable for this workaround.
	 */
	regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER0,
		ADAU17X1_CONVERTER0_ADOSR, ADAU17X1_CONVERTER0_ADOSR);
	regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER0,
		ADAU17X1_CONVERTER0_ADOSR, 0);

	return 0;
}

__attribute__((used)) static int adau17x1_dsp_mux_enum_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_dapm_kcontrol_component(kcontrol);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau *adau = snd_soc_component_get_drvdata(component);
	struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
	struct snd_soc_dapm_update update = {};
	unsigned int stream = e->shift_l;
	unsigned int val, change;
	int reg;

	if (ucontrol->value.enumerated.item[0] >= e->items)
		return -EINVAL;

	switch (ucontrol->value.enumerated.item[0]) {
	case 0:
		val = 0;
		adau->dsp_bypass[stream] = false;
		break;
	default:
		val = (adau->tdm_slot[stream] * 2) + 1;
		adau->dsp_bypass[stream] = true;
		break;
	}

	if (stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = ADAU17X1_SERIAL_INPUT_ROUTE;
	else
		reg = ADAU17X1_SERIAL_OUTPUT_ROUTE;

	change = snd_soc_component_test_bits(component, reg, 0xff, val);
	if (change) {
		update.kcontrol = kcontrol;
		update.mask = 0xff;
		update.reg = reg;
		update.val = val;

		snd_soc_dapm_mux_update_power(dapm, kcontrol,
				ucontrol->value.enumerated.item[0], e, &update);
	}

	return change;
}

__attribute__((used)) static int adau17x1_dsp_mux_enum_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_dapm_kcontrol_component(kcontrol);
	struct adau *adau = snd_soc_component_get_drvdata(component);
	struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
	unsigned int stream = e->shift_l;
	unsigned int reg, val;
	int ret;

	if (stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = ADAU17X1_SERIAL_INPUT_ROUTE;
	else
		reg = ADAU17X1_SERIAL_OUTPUT_ROUTE;

	ret = regmap_read(adau->regmap, reg, &val);
	if (ret)
		return ret;

	if (val != 0)
		val = 1;
	ucontrol->value.enumerated.item[0] = val;

	return 0;
}

bool adau17x1_has_dsp(struct adau *adau)
{
	switch (adau->type) {
	case ADAU1761:
	case ADAU1381:
	case ADAU1781:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int adau17x1_set_dai_pll(struct snd_soc_dai *dai, int pll_id,
	int source, unsigned int freq_in, unsigned int freq_out)
{
	struct snd_soc_component *component = dai->component;
	struct adau *adau = snd_soc_component_get_drvdata(component);
	int ret;

	if (freq_in < 8000000 || freq_in > 27000000)
		return -EINVAL;

	ret = adau_calc_pll_cfg(freq_in, freq_out, adau->pll_regs);
	if (ret < 0)
		return ret;

	/* The PLL register is 6 bytes long and can only be written at once. */
	ret = regmap_raw_write(adau->regmap, ADAU17X1_PLL_CONTROL,
			adau->pll_regs, ARRAY_SIZE(adau->pll_regs));
	if (ret)
		return ret;

	adau->pll_freq = freq_out;

	return 0;
}

__attribute__((used)) static int adau17x1_set_dai_sysclk(struct snd_soc_dai *dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(dai->component);
	struct adau *adau = snd_soc_component_get_drvdata(dai->component);
	bool is_pll;
	bool was_pll;

	switch (clk_id) {
	case ADAU17X1_CLK_SRC_MCLK:
		is_pll = false;
		break;
	case ADAU17X1_CLK_SRC_PLL_AUTO:
		if (!adau->mclk)
			return -EINVAL;
		/* Fall-through */
	case ADAU17X1_CLK_SRC_PLL:
		is_pll = true;
		break;
	default:
		return -EINVAL;
	}

	switch (adau->clk_src) {
	case ADAU17X1_CLK_SRC_MCLK:
		was_pll = false;
		break;
	case ADAU17X1_CLK_SRC_PLL:
	case ADAU17X1_CLK_SRC_PLL_AUTO:
		was_pll = true;
		break;
	default:
		return -EINVAL;
	}

	adau->sysclk = freq;

	if (is_pll != was_pll) {
		if (is_pll) {
			snd_soc_dapm_add_routes(dapm,
				&adau17x1_dapm_pll_route, 1);
		} else {
			snd_soc_dapm_del_routes(dapm,
				&adau17x1_dapm_pll_route, 1);
		}
	}

	adau->clk_src = clk_id;

	return 0;
}

__attribute__((used)) static int adau17x1_auto_pll(struct snd_soc_dai *dai,
	struct snd_pcm_hw_params *params)
{
	struct adau *adau = snd_soc_dai_get_drvdata(dai);
	unsigned int pll_rate;

	switch (params_rate(params)) {
	case 48000:
	case 8000:
	case 12000:
	case 16000:
	case 24000:
	case 32000:
	case 96000:
		pll_rate = 48000 * 1024;
		break;
	case 44100:
	case 7350:
	case 11025:
	case 14700:
	case 22050:
	case 29400:
	case 88200:
		pll_rate = 44100 * 1024;
		break;
	default:
		return -EINVAL;
	}

	return adau17x1_set_dai_pll(dai, ADAU17X1_PLL, ADAU17X1_PLL_SRC_MCLK,
		clk_get_rate(adau->mclk), pll_rate);
}

__attribute__((used)) static int adau17x1_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct adau *adau = snd_soc_component_get_drvdata(component);
	unsigned int val, div, dsp_div;
	unsigned int freq;
	int ret;

	switch (adau->clk_src) {
	case ADAU17X1_CLK_SRC_PLL_AUTO:
		ret = adau17x1_auto_pll(dai, params);
		if (ret)
			return ret;
		/* Fall-through */
	case ADAU17X1_CLK_SRC_PLL:
		freq = adau->pll_freq;
		break;
	default:
		freq = adau->sysclk;
		break;
	}

	if (freq % params_rate(params) != 0)
		return -EINVAL;

	switch (freq / params_rate(params)) {
	case 1024: /* fs */
		div = 0;
		dsp_div = 1;
		break;
	case 6144: /* fs / 6 */
		div = 1;
		dsp_div = 6;
		break;
	case 4096: /* fs / 4 */
		div = 2;
		dsp_div = 5;
		break;
	case 3072: /* fs / 3 */
		div = 3;
		dsp_div = 4;
		break;
	case 2048: /* fs / 2 */
		div = 4;
		dsp_div = 3;
		break;
	case 1536: /* fs / 1.5 */
		div = 5;
		dsp_div = 2;
		break;
	case 512: /* fs / 0.5 */
		div = 6;
		dsp_div = 0;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER0,
		ADAU17X1_CONVERTER0_CONVSR_MASK, div);
	if (adau17x1_has_dsp(adau)) {
		regmap_write(adau->regmap, ADAU17X1_SERIAL_SAMPLING_RATE, div);
		regmap_write(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, dsp_div);
	}

	if (adau->sigmadsp) {
		ret = adau17x1_setup_firmware(component, params_rate(params));
		if (ret < 0)
			return ret;
	}

	if (adau->dai_fmt != SND_SOC_DAIFMT_RIGHT_J)
		return 0;

	switch (params_width(params)) {
	case 16:
		val = ADAU17X1_SERIAL_PORT1_DELAY16;
		break;
	case 24:
		val = ADAU17X1_SERIAL_PORT1_DELAY8;
		break;
	case 32:
		val = ADAU17X1_SERIAL_PORT1_DELAY0;
		break;
	default:
		return -EINVAL;
	}

	return regmap_update_bits(adau->regmap, ADAU17X1_SERIAL_PORT1,
			ADAU17X1_SERIAL_PORT1_DELAY_MASK, val);
}

__attribute__((used)) static int adau17x1_set_dai_fmt(struct snd_soc_dai *dai,
		unsigned int fmt)
{
	struct adau *adau = snd_soc_component_get_drvdata(dai->component);
	unsigned int ctrl0, ctrl1;
	int lrclk_pol;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		ctrl0 = ADAU17X1_SERIAL_PORT0_MASTER;
		adau->master = true;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		ctrl0 = 0;
		adau->master = false;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		lrclk_pol = 0;
		ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY1;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
		lrclk_pol = 1;
		ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY0;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		lrclk_pol = 1;
		ctrl0 |= ADAU17X1_SERIAL_PORT0_PULSE_MODE;
		ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY1;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		lrclk_pol = 1;
		ctrl0 |= ADAU17X1_SERIAL_PORT0_PULSE_MODE;
		ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY0;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_NF:
		ctrl0 |= ADAU17X1_SERIAL_PORT0_BCLK_POL;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		lrclk_pol = !lrclk_pol;
		break;
	case SND_SOC_DAIFMT_IB_IF:
		ctrl0 |= ADAU17X1_SERIAL_PORT0_BCLK_POL;
		lrclk_pol = !lrclk_pol;
		break;
	default:
		return -EINVAL;
	}

	if (lrclk_pol)
		ctrl0 |= ADAU17X1_SERIAL_PORT0_LRCLK_POL;

	regmap_write(adau->regmap, ADAU17X1_SERIAL_PORT0, ctrl0);
	regmap_write(adau->regmap, ADAU17X1_SERIAL_PORT1, ctrl1);

	adau->dai_fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;

	return 0;
}

__attribute__((used)) static int adau17x1_set_dai_tdm_slot(struct snd_soc_dai *dai,
	unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
	struct adau *adau = snd_soc_component_get_drvdata(dai->component);
	unsigned int ser_ctrl0, ser_ctrl1;
	unsigned int conv_ctrl0, conv_ctrl1;

	/* I2S mode */
	if (slots == 0) {
		slots = 2;
		rx_mask = 3;
		tx_mask = 3;
		slot_width = 32;
	}

	switch (slots) {
	case 2:
		ser_ctrl0 = ADAU17X1_SERIAL_PORT0_STEREO;
		break;
	case 4:
		ser_ctrl0 = ADAU17X1_SERIAL_PORT0_TDM4;
		break;
	case 8:
		if (adau->type == ADAU1361)
			return -EINVAL;

		ser_ctrl0 = ADAU17X1_SERIAL_PORT0_TDM8;
		break;
	default:
		return -EINVAL;
	}

	switch (slot_width * slots) {
	case 32:
		if (adau->type == ADAU1761)
			return -EINVAL;

		ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK32;
		break;
	case 64:
		ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK64;
		break;
	case 48:
		ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK48;
		break;
	case 128:
		ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK128;
		break;
	case 256:
		if (adau->type == ADAU1361)
			return -EINVAL;

		ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK256;
		break;
	default:
		return -EINVAL;
	}

	switch (rx_mask) {
	case 0x03:
		conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(1);
		adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 0;
		break;
	case 0x0c:
		conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(2);
		adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 1;
		break;
	case 0x30:
		conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(3);
		adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 2;
		break;
	case 0xc0:
		conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(4);
		adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 3;
		break;
	default:
		return -EINVAL;
	}

	switch (tx_mask) {
	case 0x03:
		conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(1);
		adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 0;
		break;
	case 0x0c:
		conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(2);
		adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 1;
		break;
	case 0x30:
		conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(3);
		adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 2;
		break;
	case 0xc0:
		conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(4);
		adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 3;
		break;
	default:
		return -EINVAL;
	}

	regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER0,
		ADAU17X1_CONVERTER0_DAC_PAIR_MASK, conv_ctrl0);
	regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER1,
		ADAU17X1_CONVERTER1_ADC_PAIR_MASK, conv_ctrl1);
	regmap_update_bits(adau->regmap, ADAU17X1_SERIAL_PORT0,
		ADAU17X1_SERIAL_PORT0_TDM_MASK, ser_ctrl0);
	regmap_update_bits(adau->regmap, ADAU17X1_SERIAL_PORT1,
		ADAU17X1_SERIAL_PORT1_BCLK_MASK, ser_ctrl1);

	if (!adau17x1_has_dsp(adau))
		return 0;

	if (adau->dsp_bypass[SNDRV_PCM_STREAM_PLAYBACK]) {
		regmap_write(adau->regmap, ADAU17X1_SERIAL_INPUT_ROUTE,
			(adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] * 2) + 1);
	}

	if (adau->dsp_bypass[SNDRV_PCM_STREAM_CAPTURE]) {
		regmap_write(adau->regmap, ADAU17X1_SERIAL_OUTPUT_ROUTE,
			(adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] * 2) + 1);
	}

	return 0;
}

__attribute__((used)) static int adau17x1_startup(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	struct adau *adau = snd_soc_component_get_drvdata(dai->component);

	if (adau->sigmadsp)
		return sigmadsp_restrict_params(adau->sigmadsp, substream);

	return 0;
}

int adau17x1_set_micbias_voltage(struct snd_soc_component *component,
	enum adau17x1_micbias_voltage micbias)
{
	struct adau *adau = snd_soc_component_get_drvdata(component);

	switch (micbias) {
	case ADAU17X1_MICBIAS_0_90_AVDD:
	case ADAU17X1_MICBIAS_0_65_AVDD:
		break;
	default:
		return -EINVAL;
	}

	return regmap_write(adau->regmap, ADAU17X1_MICBIAS, micbias << 2);
}

bool adau17x1_precious_register(struct device *dev, unsigned int reg)
{
	/* SigmaDSP parameter memory */
	if (reg < 0x400)
		return true;

	return false;
}

bool adau17x1_readable_register(struct device *dev, unsigned int reg)
{
	/* SigmaDSP parameter memory */
	if (reg < 0x400)
		return true;

	switch (reg) {
	case ADAU17X1_CLOCK_CONTROL:
	case ADAU17X1_PLL_CONTROL:
	case ADAU17X1_REC_POWER_MGMT:
	case ADAU17X1_MICBIAS:
	case ADAU17X1_SERIAL_PORT0:
	case ADAU17X1_SERIAL_PORT1:
	case ADAU17X1_CONVERTER0:
	case ADAU17X1_CONVERTER1:
	case ADAU17X1_LEFT_INPUT_DIGITAL_VOL:
	case ADAU17X1_RIGHT_INPUT_DIGITAL_VOL:
	case ADAU17X1_ADC_CONTROL:
	case ADAU17X1_PLAY_POWER_MGMT:
	case ADAU17X1_DAC_CONTROL0:
	case ADAU17X1_DAC_CONTROL1:
	case ADAU17X1_DAC_CONTROL2:
	case ADAU17X1_SERIAL_PORT_PAD:
	case ADAU17X1_CONTROL_PORT_PAD0:
	case ADAU17X1_CONTROL_PORT_PAD1:
	case ADAU17X1_DSP_SAMPLING_RATE:
	case ADAU17X1_SERIAL_INPUT_ROUTE:
	case ADAU17X1_SERIAL_OUTPUT_ROUTE:
	case ADAU17X1_DSP_ENABLE:
	case ADAU17X1_DSP_RUN:
	case ADAU17X1_SERIAL_SAMPLING_RATE:
		return true;
	default:
		break;
	}
	return false;
}

bool adau17x1_volatile_register(struct device *dev, unsigned int reg)
{
	/* SigmaDSP parameter and program memory */
	if (reg < 0x4000)
		return true;

	switch (reg) {
	/* The PLL register is 6 bytes long */
	case ADAU17X1_PLL_CONTROL:
	case ADAU17X1_PLL_CONTROL + 1:
	case ADAU17X1_PLL_CONTROL + 2:
	case ADAU17X1_PLL_CONTROL + 3:
	case ADAU17X1_PLL_CONTROL + 4:
	case ADAU17X1_PLL_CONTROL + 5:
		return true;
	default:
		break;
	}

	return false;
}

int adau17x1_setup_firmware(struct snd_soc_component *component,
	unsigned int rate)
{
	int ret;
	int dspsr, dsp_run;
	struct adau *adau = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);

	/* Check if sample rate is the same as before. If it is there is no
	 * point in performing the below steps as the call to
	 * sigmadsp_setup(...) will return directly when it finds the sample
	 * rate to be the same as before. By checking this we can prevent an
	 * audiable popping noise which occours when toggling DSP_RUN.
	 */
	if (adau->sigmadsp->current_samplerate == rate)
		return 0;

	snd_soc_dapm_mutex_lock(dapm);

	ret = regmap_read(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, &dspsr);
	if (ret)
		goto err;

	ret = regmap_read(adau->regmap, ADAU17X1_DSP_RUN, &dsp_run);
	if (ret)
		goto err;

	regmap_write(adau->regmap, ADAU17X1_DSP_ENABLE, 1);
	regmap_write(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, 0xf);
	regmap_write(adau->regmap, ADAU17X1_DSP_RUN, 0);

	ret = sigmadsp_setup(adau->sigmadsp, rate);
	if (ret) {
		regmap_write(adau->regmap, ADAU17X1_DSP_ENABLE, 0);
		goto err;
	}
	regmap_write(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, dspsr);
	regmap_write(adau->regmap, ADAU17X1_DSP_RUN, dsp_run);

err:
	snd_soc_dapm_mutex_unlock(dapm);

	return ret;
}

int adau17x1_add_widgets(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau *adau = snd_soc_component_get_drvdata(component);
	int ret;

	ret = snd_soc_add_component_controls(component, adau17x1_controls,
		ARRAY_SIZE(adau17x1_controls));
	if (ret)
		return ret;
	ret = snd_soc_dapm_new_controls(dapm, adau17x1_dapm_widgets,
		ARRAY_SIZE(adau17x1_dapm_widgets));
	if (ret)
		return ret;

	if (adau17x1_has_dsp(adau)) {
		ret = snd_soc_dapm_new_controls(dapm, adau17x1_dsp_dapm_widgets,
			ARRAY_SIZE(adau17x1_dsp_dapm_widgets));
		if (ret)
			return ret;

		if (!adau->sigmadsp)
			return 0;

		ret = sigmadsp_attach(adau->sigmadsp, component);
		if (ret) {
			dev_err(component->dev, "Failed to attach firmware: %d\n",
				ret);
			return ret;
		}
	}

	return 0;
}

int adau17x1_add_routes(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct adau *adau = snd_soc_component_get_drvdata(component);
	int ret;

	ret = snd_soc_dapm_add_routes(dapm, adau17x1_dapm_routes,
		ARRAY_SIZE(adau17x1_dapm_routes));
	if (ret)
		return ret;

	if (adau17x1_has_dsp(adau)) {
		ret = snd_soc_dapm_add_routes(dapm, adau17x1_dsp_dapm_routes,
			ARRAY_SIZE(adau17x1_dsp_dapm_routes));
	} else {
		ret = snd_soc_dapm_add_routes(dapm, adau17x1_no_dsp_dapm_routes,
			ARRAY_SIZE(adau17x1_no_dsp_dapm_routes));
	}

	if (adau->clk_src != ADAU17X1_CLK_SRC_MCLK)
		snd_soc_dapm_add_routes(dapm, &adau17x1_dapm_pll_route, 1);

	return ret;
}

int adau17x1_resume(struct snd_soc_component *component)
{
	struct adau *adau = snd_soc_component_get_drvdata(component);

	if (adau->switch_mode)
		adau->switch_mode(component->dev);

	regcache_sync(adau->regmap);

	return 0;
}

int adau17x1_probe(struct device *dev, struct regmap *regmap,
	enum adau17x1_type type, void (*switch_mode)(struct device *dev),
	const char *firmware_name)
{
	struct adau *adau;
	int ret;

	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	adau = devm_kzalloc(dev, sizeof(*adau), GFP_KERNEL);
	if (!adau)
		return -ENOMEM;

	adau->mclk = devm_clk_get(dev, "mclk");
	if (IS_ERR(adau->mclk)) {
		if (PTR_ERR(adau->mclk) != -ENOENT)
			return PTR_ERR(adau->mclk);
		/* Clock is optional (for the driver) */
		adau->mclk = NULL;
	} else if (adau->mclk) {
		adau->clk_src = ADAU17X1_CLK_SRC_PLL_AUTO;

		/*
		 * Any valid PLL output rate will work at this point, use one
		 * that is likely to be chosen later as well. The register will
		 * be written when the PLL is powered up for the first time.
		 */
		ret = adau_calc_pll_cfg(clk_get_rate(adau->mclk), 48000 * 1024,
				adau->pll_regs);
		if (ret < 0)
			return ret;

		ret = clk_prepare_enable(adau->mclk);
		if (ret)
			return ret;
	}

	adau->regmap = regmap;
	adau->switch_mode = switch_mode;
	adau->type = type;

	dev_set_drvdata(dev, adau);

	if (firmware_name) {
		adau->sigmadsp = devm_sigmadsp_init_regmap(dev, regmap, NULL,
			firmware_name);
		if (IS_ERR(adau->sigmadsp)) {
			dev_warn(dev, "Could not find firmware file: %ld\n",
				PTR_ERR(adau->sigmadsp));
			adau->sigmadsp = NULL;
		}
	}

	if (switch_mode)
		switch_mode(dev);

	return 0;
}

void adau17x1_remove(struct device *dev)
{
	struct adau *adau = dev_get_drvdata(dev);

	if (adau->mclk)
		clk_disable_unprepare(adau->mclk);
}


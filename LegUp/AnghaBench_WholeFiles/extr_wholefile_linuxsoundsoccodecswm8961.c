#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct wm8961_priv {int sysclk; int /*<<< orphan*/  regmap; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_4__ {int val; int ratio; scalar_t__ rate; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ SNDRV_PCM_STREAM_CAPTURE ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 199 
#define  SND_SOC_BIAS_ON 198 
#define  SND_SOC_BIAS_PREPARE 197 
#define  SND_SOC_BIAS_STANDBY 196 
#define  SND_SOC_DAIFMT_CBM_CFM 195 
#define  SND_SOC_DAIFMT_CBS_CFS 194 
#define  SND_SOC_DAIFMT_DSP_A 193 
#define  SND_SOC_DAIFMT_DSP_B 192 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 191 
#define  SND_SOC_DAIFMT_IB_IF 190 
#define  SND_SOC_DAIFMT_IB_NF 189 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 188 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 187 
#define  SND_SOC_DAIFMT_NB_NF 186 
#define  SND_SOC_DAIFMT_RIGHT_J 185 
 int SND_SOC_DAPM_POST_PMU ; 
 int SND_SOC_DAPM_PRE_PMD ; 
#define  WM8961_ADCL_SIGNAL_PATH 184 
#define  WM8961_ADCR_SIGNAL_PATH 183 
 int WM8961_ADCVU ; 
#define  WM8961_ADC_DAC_CONTROL_1 182 
#define  WM8961_ADC_DAC_CONTROL_2 181 
#define  WM8961_ADDITIONAL_CONTROL_1 180 
#define  WM8961_ADDITIONAL_CONTROL_2 179 
#define  WM8961_ADDITIONAL_CONTROL_3 178 
#define  WM8961_ADDITIONAL_CONTROL_4 177 
#define  WM8961_ALC1 176 
#define  WM8961_ALC2 175 
#define  WM8961_ALC3 174 
#define  WM8961_ANALOGUE_HP_0 173 
#define  WM8961_ANALOGUE_HP_2 172 
#define  WM8961_ANALOGUE_PGA_BIAS 171 
#define  WM8961_ANTI_POP 170 
#define  WM8961_AUDIO_INTERFACE_0 169 
#define  WM8961_AUDIO_INTERFACE_1 168 
#define  WM8961_AUDIO_INTERFACE_2 167 
#define  WM8961_BCLK 166 
 int WM8961_BCLKDIV_MASK ; 
 int WM8961_BCLKINV ; 
 int WM8961_BUFDCOPEN ; 
 int WM8961_BUFIOEN ; 
#define  WM8961_CHARGE_PUMP_1 165 
#define  WM8961_CHARGE_PUMP_B 164 
 unsigned int WM8961_CHIP_REV_MASK ; 
 unsigned int WM8961_CHIP_REV_SHIFT ; 
#define  WM8961_CLASS_D_CONTROL_1 163 
#define  WM8961_CLASS_D_CONTROL_2 162 
 int WM8961_CLK_SYS_RATE_MASK ; 
 int WM8961_CLK_SYS_RATE_SHIFT ; 
#define  WM8961_CLOCKING1 161 
#define  WM8961_CLOCKING2 160 
#define  WM8961_CLOCKING_3 159 
#define  WM8961_CLOCKING_4 158 
 int WM8961_CP_DYN_PWR_MASK ; 
 int WM8961_CP_ENA ; 
 int WM8961_DACMU ; 
 int WM8961_DACSLOPE ; 
 int WM8961_DACSMM ; 
 int WM8961_DCS_ENA_CHAN_HPL ; 
 int WM8961_DCS_ENA_CHAN_HPR ; 
 int WM8961_DCS_TRIG_STARTUP_HPL ; 
 int WM8961_DCS_TRIG_STARTUP_HPR ; 
#define  WM8961_DC_SERVO_0 157 
#define  WM8961_DC_SERVO_1 156 
#define  WM8961_DC_SERVO_3 155 
#define  WM8961_DC_SERVO_5 154 
 unsigned int WM8961_DEVICE_ID_MASK ; 
 unsigned int WM8961_DEVICE_ID_SHIFT ; 
#define  WM8961_DSP_SIDETONE_0 153 
#define  WM8961_DSP_SIDETONE_1 152 
 int WM8961_FORMAT_MASK ; 
#define  WM8961_GENERAL_TEST_1 151 
 int WM8961_HPL_ENA ; 
 int WM8961_HPL_ENA_DLY ; 
 int WM8961_HPL_ENA_OUTP ; 
 int WM8961_HPL_RMV_SHORT ; 
 int WM8961_HPR_ENA ; 
 int WM8961_HPR_ENA_DLY ; 
 int WM8961_HPR_ENA_OUTP ; 
 int WM8961_HPR_RMV_SHORT ; 
 int WM8961_IPVU ; 
#define  WM8961_LEFT_ADC_VOLUME 150 
#define  WM8961_LEFT_DAC_VOLUME 149 
#define  WM8961_LEFT_INPUT_VOLUME 148 
 int WM8961_LO1ZC ; 
 int WM8961_LOUT1_PGA ; 
#define  WM8961_LOUT1_VOLUME 147 
#define  WM8961_LOUT2_VOLUME 146 
#define  WM8961_LRCLK 145 
 int WM8961_LRCLK_RATE_MASK ; 
 int WM8961_LRP ; 
 int WM8961_MANUAL_MODE ; 
 int WM8961_MCLKDIV ; 
 int WM8961_MS ; 
#define  WM8961_NOISE_GATE 144 
 int WM8961_OUT1VU ; 
#define  WM8961_PWR_MGMT_1 143 
#define  WM8961_PWR_MGMT_2 142 
#define  WM8961_PWR_MGMT_3 141 
#define  WM8961_RIGHT_ADC_VOLUME 140 
#define  WM8961_RIGHT_DAC_VOLUME 139 
#define  WM8961_RIGHT_INPUT_VOLUME 138 
 int WM8961_ROUT1_PGA ; 
#define  WM8961_ROUT1_VOLUME 137 
#define  WM8961_ROUT2_VOLUME 136 
 int WM8961_SAMPLE_RATE_MASK ; 
#define  WM8961_SOFTWARE_RESET 135 
 int WM8961_SPKLZC ; 
 int WM8961_SPKL_ENA ; 
 int WM8961_SPKL_PGA ; 
 int WM8961_SPKRZC ; 
 int WM8961_SPKR_ENA ; 
 int WM8961_SPKR_PGA ; 
 int WM8961_SPKVU ; 
 int WM8961_TRIS ; 
 int WM8961_VMIDSEL_MASK ; 
 int WM8961_VMIDSEL_SHIFT ; 
 int WM8961_VREF ; 
 int WM8961_WL_MASK ; 
 int WM8961_WL_SHIFT ; 
#define  WM8961_WRITE_SEQUENCER_1 134 
#define  WM8961_WRITE_SEQUENCER_2 133 
#define  WM8961_WRITE_SEQUENCER_3 132 
#define  WM8961_WRITE_SEQUENCER_4 131 
#define  WM8961_WRITE_SEQUENCER_5 130 
#define  WM8961_WRITE_SEQUENCER_6 129 
#define  WM8961_WRITE_SEQUENCER_7 128 
 scalar_t__ abs (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,unsigned int,unsigned int) ; 
 struct wm8961_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct wm8961_priv*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_cache_bypass (int /*<<< orphan*/ ,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int const,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int const,int) ; 
 int const snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct wm8961_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int snd_soc_component_write (struct snd_soc_component*,int const,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm8961 ; 
 TYPE_1__* wm8961_clk_sys_ratio ; 
 int /*<<< orphan*/  wm8961_dai ; 
 int /*<<< orphan*/  wm8961_regmap ; 
 TYPE_1__* wm8961_srate ; 

__attribute__((used)) static bool wm8961_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8961_SOFTWARE_RESET:
	case WM8961_WRITE_SEQUENCER_7:
	case WM8961_DC_SERVO_1:
		return true;

	default:
		return false;
	}
}

__attribute__((used)) static bool wm8961_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8961_LEFT_INPUT_VOLUME:
	case WM8961_RIGHT_INPUT_VOLUME:
	case WM8961_LOUT1_VOLUME:
	case WM8961_ROUT1_VOLUME:
	case WM8961_CLOCKING1:
	case WM8961_ADC_DAC_CONTROL_1:
	case WM8961_ADC_DAC_CONTROL_2:
	case WM8961_AUDIO_INTERFACE_0:
	case WM8961_CLOCKING2:
	case WM8961_AUDIO_INTERFACE_1:
	case WM8961_LEFT_DAC_VOLUME:
	case WM8961_RIGHT_DAC_VOLUME:
	case WM8961_AUDIO_INTERFACE_2:
	case WM8961_SOFTWARE_RESET:
	case WM8961_ALC1:
	case WM8961_ALC2:
	case WM8961_ALC3:
	case WM8961_NOISE_GATE:
	case WM8961_LEFT_ADC_VOLUME:
	case WM8961_RIGHT_ADC_VOLUME:
	case WM8961_ADDITIONAL_CONTROL_1:
	case WM8961_ADDITIONAL_CONTROL_2:
	case WM8961_PWR_MGMT_1:
	case WM8961_PWR_MGMT_2:
	case WM8961_ADDITIONAL_CONTROL_3:
	case WM8961_ANTI_POP:
	case WM8961_CLOCKING_3:
	case WM8961_ADCL_SIGNAL_PATH:
	case WM8961_ADCR_SIGNAL_PATH:
	case WM8961_LOUT2_VOLUME:
	case WM8961_ROUT2_VOLUME:
	case WM8961_PWR_MGMT_3:
	case WM8961_ADDITIONAL_CONTROL_4:
	case WM8961_CLASS_D_CONTROL_1:
	case WM8961_CLASS_D_CONTROL_2:
	case WM8961_CLOCKING_4:
	case WM8961_DSP_SIDETONE_0:
	case WM8961_DSP_SIDETONE_1:
	case WM8961_DC_SERVO_0:
	case WM8961_DC_SERVO_1:
	case WM8961_DC_SERVO_3:
	case WM8961_DC_SERVO_5:
	case WM8961_ANALOGUE_PGA_BIAS:
	case WM8961_ANALOGUE_HP_0:
	case WM8961_ANALOGUE_HP_2:
	case WM8961_CHARGE_PUMP_1:
	case WM8961_CHARGE_PUMP_B:
	case WM8961_WRITE_SEQUENCER_1:
	case WM8961_WRITE_SEQUENCER_2:
	case WM8961_WRITE_SEQUENCER_3:
	case WM8961_WRITE_SEQUENCER_4:
	case WM8961_WRITE_SEQUENCER_5:
	case WM8961_WRITE_SEQUENCER_6:
	case WM8961_WRITE_SEQUENCER_7:
	case WM8961_GENERAL_TEST_1:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int wm8961_hp_event(struct snd_soc_dapm_widget *w,
			   struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	u16 hp_reg = snd_soc_component_read32(component, WM8961_ANALOGUE_HP_0);
	u16 cp_reg = snd_soc_component_read32(component, WM8961_CHARGE_PUMP_1);
	u16 pwr_reg = snd_soc_component_read32(component, WM8961_PWR_MGMT_2);
	u16 dcs_reg = snd_soc_component_read32(component, WM8961_DC_SERVO_1);
	int timeout = 500;

	if (event & SND_SOC_DAPM_POST_PMU) {
		/* Make sure the output is shorted */
		hp_reg &= ~(WM8961_HPR_RMV_SHORT | WM8961_HPL_RMV_SHORT);
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Enable the charge pump */
		cp_reg |= WM8961_CP_ENA;
		snd_soc_component_write(component, WM8961_CHARGE_PUMP_1, cp_reg);
		mdelay(5);

		/* Enable the PGA */
		pwr_reg |= WM8961_LOUT1_PGA | WM8961_ROUT1_PGA;
		snd_soc_component_write(component, WM8961_PWR_MGMT_2, pwr_reg);

		/* Enable the amplifier */
		hp_reg |= WM8961_HPR_ENA | WM8961_HPL_ENA;
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Second stage enable */
		hp_reg |= WM8961_HPR_ENA_DLY | WM8961_HPL_ENA_DLY;
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Enable the DC servo & trigger startup */
		dcs_reg |=
			WM8961_DCS_ENA_CHAN_HPR | WM8961_DCS_TRIG_STARTUP_HPR |
			WM8961_DCS_ENA_CHAN_HPL | WM8961_DCS_TRIG_STARTUP_HPL;
		dev_dbg(component->dev, "Enabling DC servo\n");

		snd_soc_component_write(component, WM8961_DC_SERVO_1, dcs_reg);
		do {
			msleep(1);
			dcs_reg = snd_soc_component_read32(component, WM8961_DC_SERVO_1);
		} while (--timeout &&
			 dcs_reg & (WM8961_DCS_TRIG_STARTUP_HPR |
				WM8961_DCS_TRIG_STARTUP_HPL));
		if (dcs_reg & (WM8961_DCS_TRIG_STARTUP_HPR |
			       WM8961_DCS_TRIG_STARTUP_HPL))
			dev_err(component->dev, "DC servo timed out\n");
		else
			dev_dbg(component->dev, "DC servo startup complete\n");

		/* Enable the output stage */
		hp_reg |= WM8961_HPR_ENA_OUTP | WM8961_HPL_ENA_OUTP;
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Remove the short on the output stage */
		hp_reg |= WM8961_HPR_RMV_SHORT | WM8961_HPL_RMV_SHORT;
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);
	}

	if (event & SND_SOC_DAPM_PRE_PMD) {
		/* Short the output */
		hp_reg &= ~(WM8961_HPR_RMV_SHORT | WM8961_HPL_RMV_SHORT);
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Disable the output stage */
		hp_reg &= ~(WM8961_HPR_ENA_OUTP | WM8961_HPL_ENA_OUTP);
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Disable DC offset cancellation */
		dcs_reg &= ~(WM8961_DCS_ENA_CHAN_HPR |
			     WM8961_DCS_ENA_CHAN_HPL);
		snd_soc_component_write(component, WM8961_DC_SERVO_1, dcs_reg);

		/* Finish up */
		hp_reg &= ~(WM8961_HPR_ENA_DLY | WM8961_HPR_ENA |
			    WM8961_HPL_ENA_DLY | WM8961_HPL_ENA);
		snd_soc_component_write(component, WM8961_ANALOGUE_HP_0, hp_reg);

		/* Disable the PGA */
		pwr_reg &= ~(WM8961_LOUT1_PGA | WM8961_ROUT1_PGA);
		snd_soc_component_write(component, WM8961_PWR_MGMT_2, pwr_reg);

		/* Disable the charge pump */
		dev_dbg(component->dev, "Disabling charge pump\n");
		snd_soc_component_write(component, WM8961_CHARGE_PUMP_1,
			     cp_reg & ~WM8961_CP_ENA);
	}

	return 0;
}

__attribute__((used)) static int wm8961_spk_event(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	u16 pwr_reg = snd_soc_component_read32(component, WM8961_PWR_MGMT_2);
	u16 spk_reg = snd_soc_component_read32(component, WM8961_CLASS_D_CONTROL_1);

	if (event & SND_SOC_DAPM_POST_PMU) {
		/* Enable the PGA */
		pwr_reg |= WM8961_SPKL_PGA | WM8961_SPKR_PGA;
		snd_soc_component_write(component, WM8961_PWR_MGMT_2, pwr_reg);

		/* Enable the amplifier */
		spk_reg |= WM8961_SPKL_ENA | WM8961_SPKR_ENA;
		snd_soc_component_write(component, WM8961_CLASS_D_CONTROL_1, spk_reg);
	}

	if (event & SND_SOC_DAPM_PRE_PMD) {
		/* Disable the amplifier */
		spk_reg &= ~(WM8961_SPKL_ENA | WM8961_SPKR_ENA);
		snd_soc_component_write(component, WM8961_CLASS_D_CONTROL_1, spk_reg);

		/* Disable the PGA */
		pwr_reg &= ~(WM8961_SPKL_PGA | WM8961_SPKR_PGA);
		snd_soc_component_write(component, WM8961_PWR_MGMT_2, pwr_reg);
	}

	return 0;
}

__attribute__((used)) static int wm8961_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct wm8961_priv *wm8961 = snd_soc_component_get_drvdata(component);
	int i, best, target, fs;
	u16 reg;

	fs = params_rate(params);

	if (!wm8961->sysclk) {
		dev_err(component->dev, "MCLK has not been specified\n");
		return -EINVAL;
	}

	/* Find the closest sample rate for the filters */
	best = 0;
	for (i = 0; i < ARRAY_SIZE(wm8961_srate); i++) {
		if (abs(wm8961_srate[i].rate - fs) <
		    abs(wm8961_srate[best].rate - fs))
			best = i;
	}
	reg = snd_soc_component_read32(component, WM8961_ADDITIONAL_CONTROL_3);
	reg &= ~WM8961_SAMPLE_RATE_MASK;
	reg |= wm8961_srate[best].val;
	snd_soc_component_write(component, WM8961_ADDITIONAL_CONTROL_3, reg);
	dev_dbg(component->dev, "Selected SRATE %dHz for %dHz\n",
		wm8961_srate[best].rate, fs);

	/* Select a CLK_SYS/fs ratio equal to or higher than required */
	target = wm8961->sysclk / fs;

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK && target < 64) {
		dev_err(component->dev,
			"SYSCLK must be at least 64*fs for DAC\n");
		return -EINVAL;
	}
	if (substream->stream == SNDRV_PCM_STREAM_CAPTURE && target < 256) {
		dev_err(component->dev,
			"SYSCLK must be at least 256*fs for ADC\n");
		return -EINVAL;
	}

	for (i = 0; i < ARRAY_SIZE(wm8961_clk_sys_ratio); i++) {
		if (wm8961_clk_sys_ratio[i].ratio >= target)
			break;
	}
	if (i == ARRAY_SIZE(wm8961_clk_sys_ratio)) {
		dev_err(component->dev, "Unable to generate CLK_SYS_RATE\n");
		return -EINVAL;
	}
	dev_dbg(component->dev, "Selected CLK_SYS_RATE of %d for %d/%d=%d\n",
		wm8961_clk_sys_ratio[i].ratio, wm8961->sysclk, fs,
		wm8961->sysclk / fs);

	reg = snd_soc_component_read32(component, WM8961_CLOCKING_4);
	reg &= ~WM8961_CLK_SYS_RATE_MASK;
	reg |= wm8961_clk_sys_ratio[i].val << WM8961_CLK_SYS_RATE_SHIFT;
	snd_soc_component_write(component, WM8961_CLOCKING_4, reg);

	reg = snd_soc_component_read32(component, WM8961_AUDIO_INTERFACE_0);
	reg &= ~WM8961_WL_MASK;
	switch (params_width(params)) {
	case 16:
		break;
	case 20:
		reg |= 1 << WM8961_WL_SHIFT;
		break;
	case 24:
		reg |= 2 << WM8961_WL_SHIFT;
		break;
	case 32:
		reg |= 3 << WM8961_WL_SHIFT;
		break;
	default:
		return -EINVAL;
	}
	snd_soc_component_write(component, WM8961_AUDIO_INTERFACE_0, reg);

	/* Sloping stop-band filter is recommended for <= 24kHz */
	reg = snd_soc_component_read32(component, WM8961_ADC_DAC_CONTROL_2);
	if (fs <= 24000)
		reg |= WM8961_DACSLOPE;
	else
		reg &= ~WM8961_DACSLOPE;
	snd_soc_component_write(component, WM8961_ADC_DAC_CONTROL_2, reg);

	return 0;
}

__attribute__((used)) static int wm8961_set_sysclk(struct snd_soc_dai *dai, int clk_id,
			     unsigned int freq,
			     int dir)
{
	struct snd_soc_component *component = dai->component;
	struct wm8961_priv *wm8961 = snd_soc_component_get_drvdata(component);
	u16 reg = snd_soc_component_read32(component, WM8961_CLOCKING1);

	if (freq > 33000000) {
		dev_err(component->dev, "MCLK must be <33MHz\n");
		return -EINVAL;
	}

	if (freq > 16500000) {
		dev_dbg(component->dev, "Using MCLK/2 for %dHz MCLK\n", freq);
		reg |= WM8961_MCLKDIV;
		freq /= 2;
	} else {
		dev_dbg(component->dev, "Using MCLK/1 for %dHz MCLK\n", freq);
		reg &= ~WM8961_MCLKDIV;
	}

	snd_soc_component_write(component, WM8961_CLOCKING1, reg);

	wm8961->sysclk = freq;

	return 0;
}

__attribute__((used)) static int wm8961_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	u16 aif = snd_soc_component_read32(component, WM8961_AUDIO_INTERFACE_0);

	aif &= ~(WM8961_BCLKINV | WM8961_LRP |
		 WM8961_MS | WM8961_FORMAT_MASK);

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		aif |= WM8961_MS;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_RIGHT_J:
		break;

	case SND_SOC_DAIFMT_LEFT_J:
		aif |= 1;
		break;

	case SND_SOC_DAIFMT_I2S:
		aif |= 2;
		break;

	case SND_SOC_DAIFMT_DSP_B:
		aif |= WM8961_LRP;
		/* fall through */
	case SND_SOC_DAIFMT_DSP_A:
		aif |= 3;
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
		case SND_SOC_DAIFMT_IB_NF:
			break;
		default:
			return -EINVAL;
		}
		break;

	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_NB_IF:
		aif |= WM8961_LRP;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		aif |= WM8961_BCLKINV;
		break;
	case SND_SOC_DAIFMT_IB_IF:
		aif |= WM8961_BCLKINV | WM8961_LRP;
		break;
	default:
		return -EINVAL;
	}

	return snd_soc_component_write(component, WM8961_AUDIO_INTERFACE_0, aif);
}

__attribute__((used)) static int wm8961_set_tristate(struct snd_soc_dai *dai, int tristate)
{
	struct snd_soc_component *component = dai->component;
	u16 reg = snd_soc_component_read32(component, WM8961_ADDITIONAL_CONTROL_2);

	if (tristate)
		reg |= WM8961_TRIS;
	else
		reg &= ~WM8961_TRIS;

	return snd_soc_component_write(component, WM8961_ADDITIONAL_CONTROL_2, reg);
}

__attribute__((used)) static int wm8961_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u16 reg = snd_soc_component_read32(component, WM8961_ADC_DAC_CONTROL_1);

	if (mute)
		reg |= WM8961_DACMU;
	else
		reg &= ~WM8961_DACMU;

	msleep(17);

	return snd_soc_component_write(component, WM8961_ADC_DAC_CONTROL_1, reg);
}

__attribute__((used)) static int wm8961_set_clkdiv(struct snd_soc_dai *dai, int div_id, int div)
{
	struct snd_soc_component *component = dai->component;
	u16 reg;

	switch (div_id) {
	case WM8961_BCLK:
		reg = snd_soc_component_read32(component, WM8961_CLOCKING2);
		reg &= ~WM8961_BCLKDIV_MASK;
		reg |= div;
		snd_soc_component_write(component, WM8961_CLOCKING2, reg);
		break;

	case WM8961_LRCLK:
		reg = snd_soc_component_read32(component, WM8961_AUDIO_INTERFACE_2);
		reg &= ~WM8961_LRCLK_RATE_MASK;
		reg |= div;
		snd_soc_component_write(component, WM8961_AUDIO_INTERFACE_2, reg);
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int wm8961_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	u16 reg;

	/* This is all slightly unusual since we have no bypass paths
	 * and the output amplifier structure means we can just slam
	 * the biases straight up rather than having to ramp them
	 * slowly.
	 */
	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_STANDBY) {
			/* Enable bias generation */
			reg = snd_soc_component_read32(component, WM8961_ANTI_POP);
			reg |= WM8961_BUFIOEN | WM8961_BUFDCOPEN;
			snd_soc_component_write(component, WM8961_ANTI_POP, reg);

			/* VMID=2*50k, VREF */
			reg = snd_soc_component_read32(component, WM8961_PWR_MGMT_1);
			reg &= ~WM8961_VMIDSEL_MASK;
			reg |= (1 << WM8961_VMIDSEL_SHIFT) | WM8961_VREF;
			snd_soc_component_write(component, WM8961_PWR_MGMT_1, reg);
		}
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_PREPARE) {
			/* VREF off */
			reg = snd_soc_component_read32(component, WM8961_PWR_MGMT_1);
			reg &= ~WM8961_VREF;
			snd_soc_component_write(component, WM8961_PWR_MGMT_1, reg);

			/* Bias generation off */
			reg = snd_soc_component_read32(component, WM8961_ANTI_POP);
			reg &= ~(WM8961_BUFIOEN | WM8961_BUFDCOPEN);
			snd_soc_component_write(component, WM8961_ANTI_POP, reg);

			/* VMID off */
			reg = snd_soc_component_read32(component, WM8961_PWR_MGMT_1);
			reg &= ~WM8961_VMIDSEL_MASK;
			snd_soc_component_write(component, WM8961_PWR_MGMT_1, reg);
		}
		break;

	case SND_SOC_BIAS_OFF:
		break;
	}

	return 0;
}

__attribute__((used)) static int wm8961_probe(struct snd_soc_component *component)
{
	u16 reg;

	/* Enable class W */
	reg = snd_soc_component_read32(component, WM8961_CHARGE_PUMP_B);
	reg |= WM8961_CP_DYN_PWR_MASK;
	snd_soc_component_write(component, WM8961_CHARGE_PUMP_B, reg);

	/* Latch volume update bits (right channel only, we always
	 * write both out) and default ZC on. */
	reg = snd_soc_component_read32(component, WM8961_ROUT1_VOLUME);
	snd_soc_component_write(component, WM8961_ROUT1_VOLUME,
		     reg | WM8961_LO1ZC | WM8961_OUT1VU);
	snd_soc_component_write(component, WM8961_LOUT1_VOLUME, reg | WM8961_LO1ZC);
	reg = snd_soc_component_read32(component, WM8961_ROUT2_VOLUME);
	snd_soc_component_write(component, WM8961_ROUT2_VOLUME,
		     reg | WM8961_SPKRZC | WM8961_SPKVU);
	snd_soc_component_write(component, WM8961_LOUT2_VOLUME, reg | WM8961_SPKLZC);

	reg = snd_soc_component_read32(component, WM8961_RIGHT_ADC_VOLUME);
	snd_soc_component_write(component, WM8961_RIGHT_ADC_VOLUME, reg | WM8961_ADCVU);
	reg = snd_soc_component_read32(component, WM8961_RIGHT_INPUT_VOLUME);
	snd_soc_component_write(component, WM8961_RIGHT_INPUT_VOLUME, reg | WM8961_IPVU);

	/* Use soft mute by default */
	reg = snd_soc_component_read32(component, WM8961_ADC_DAC_CONTROL_2);
	reg |= WM8961_DACSMM;
	snd_soc_component_write(component, WM8961_ADC_DAC_CONTROL_2, reg);

	/* Use automatic clocking mode by default; for now this is all
	 * we support.
	 */
	reg = snd_soc_component_read32(component, WM8961_CLOCKING_3);
	reg &= ~WM8961_MANUAL_MODE;
	snd_soc_component_write(component, WM8961_CLOCKING_3, reg);

	return 0;
}

__attribute__((used)) static int wm8961_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct wm8961_priv *wm8961;
	unsigned int val;
	int ret;

	wm8961 = devm_kzalloc(&i2c->dev, sizeof(struct wm8961_priv),
			      GFP_KERNEL);
	if (wm8961 == NULL)
		return -ENOMEM;

	wm8961->regmap = devm_regmap_init_i2c(i2c, &wm8961_regmap);
	if (IS_ERR(wm8961->regmap))
		return PTR_ERR(wm8961->regmap);

	ret = regmap_read(wm8961->regmap, WM8961_SOFTWARE_RESET, &val);
	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to read chip ID: %d\n", ret);
		return ret;
	}

	if (val != 0x1801) {
		dev_err(&i2c->dev, "Device is not a WM8961: ID=0x%x\n", val);
		return -EINVAL;
	}

	/* This isn't volatile - readback doesn't correspond to write */
	regcache_cache_bypass(wm8961->regmap, true);
	ret = regmap_read(wm8961->regmap, WM8961_RIGHT_INPUT_VOLUME, &val);
	regcache_cache_bypass(wm8961->regmap, false);

	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to read chip revision: %d\n", ret);
		return ret;
	}

	dev_info(&i2c->dev, "WM8961 family %d revision %c\n",
		 (val & WM8961_DEVICE_ID_MASK) >> WM8961_DEVICE_ID_SHIFT,
		 ((val & WM8961_CHIP_REV_MASK) >> WM8961_CHIP_REV_SHIFT)
		 + 'A');

	ret = regmap_write(wm8961->regmap, WM8961_SOFTWARE_RESET, 0x1801);
	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to issue reset: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(i2c, wm8961);

	ret = devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_wm8961, &wm8961_dai, 1);

	return ret;
}


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
typedef  unsigned long u64 ;
struct snd_soc_dai {struct snd_soc_component* component; struct device* dev; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_ratnum {int num; int den_min; int den_max; int den_step; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_rule {int /*<<< orphan*/  var; struct pcm512x_priv* private; } ;
struct snd_pcm_hw_params {int rate_den; } ;
struct snd_pcm_hw_constraint_ratnums {int nrats; struct snd_ratnum* rats; } ;
struct snd_kcontrol {int dummy; } ;
struct snd_interval {int min; int max; int /*<<< orphan*/  consumer; int /*<<< orphan*/  supply; } ;
struct TYPE_4__ {int* value; } ;
struct TYPE_5__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct regmap {int dummy; } ;
struct pcm512x_priv {int overclock_pll; int overclock_dsp; unsigned long overclock_dac; int mute; int pll_out; int fmt; unsigned long real_pll; int pll_r; int pll_j; int pll_d; int pll_p; int lrclk_div; int pll_in; struct snd_interval* supplies; int /*<<< orphan*/  sclk; struct regmap* regmap; TYPE_3__* supply_nb; int /*<<< orphan*/  mutex; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ranges ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_6__ {int /*<<< orphan*/  notifier_call; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct snd_interval*) ; 
 void* DIV_ROUND_CLOSEST (unsigned long,unsigned long) ; 
 unsigned long DIV_ROUND_CLOSEST_ULL (unsigned long long,unsigned long) ; 
 unsigned long DIV_ROUND_DOWN_ULL (unsigned long,int) ; 
 unsigned long DIV_ROUND_UP (unsigned long,int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PCM512x_ALEN ; 
 int PCM512x_ALEN_16 ; 
 int PCM512x_ALEN_20 ; 
 int PCM512x_ALEN_24 ; 
 int PCM512x_ALEN_32 ; 
#define  PCM512x_ANALOG_GAIN_BOOST 203 
#define  PCM512x_ANALOG_GAIN_CTRL 202 
#define  PCM512x_ANALOG_MUTE_CTRL 201 
#define  PCM512x_ANALOG_MUTE_DET 200 
#define  PCM512x_AUTO_MUTE 199 
 int PCM512x_BCKO ; 
 int PCM512x_BCKP ; 
#define  PCM512x_BCLK_LRCLK_CFG 198 
#define  PCM512x_CLKDET 197 
#define  PCM512x_CLOCK_STATUS 196 
#define  PCM512x_CRAM_CTRL 195 
#define  PCM512x_DAC_CLKDIV 194 
#define  PCM512x_DAC_REF 193 
#define  PCM512x_DAC_ROUTING 192 
 int PCM512x_DCAS ; 
#define  PCM512x_DIGITAL_MUTE_1 191 
#define  PCM512x_DIGITAL_MUTE_2 190 
#define  PCM512x_DIGITAL_MUTE_3 189 
#define  PCM512x_DIGITAL_MUTE_DET 188 
#define  PCM512x_DIGITAL_VOLUME_1 187 
#define  PCM512x_DIGITAL_VOLUME_2 186 
#define  PCM512x_DIGITAL_VOLUME_3 185 
#define  PCM512x_DSP 184 
#define  PCM512x_DSP_CLKDIV 183 
#define  PCM512x_DSP_GPIO_INPUT 182 
#define  PCM512x_DSP_PROGRAM 181 
#define  PCM512x_ERROR_DETECT 180 
#define  PCM512x_FLEX_A 179 
#define  PCM512x_FLEX_B 178 
 int PCM512x_FSSP ; 
 int PCM512x_FSSP_192KHZ ; 
 int PCM512x_FSSP_384KHZ ; 
 int PCM512x_FSSP_48KHZ ; 
 int PCM512x_FSSP_96KHZ ; 
#define  PCM512x_FS_SPEED_MODE 177 
 int PCM512x_G1OE ; 
#define  PCM512x_GPIN 176 
#define  PCM512x_GPIO_CONTROL_1 175 
#define  PCM512x_GPIO_CONTROL_2 174 
#define  PCM512x_GPIO_DACIN 173 
#define  PCM512x_GPIO_EN 172 
#define  PCM512x_GPIO_OUTPUT_1 171 
#define  PCM512x_GPIO_OUTPUT_2 170 
#define  PCM512x_GPIO_OUTPUT_3 169 
#define  PCM512x_GPIO_OUTPUT_4 168 
#define  PCM512x_GPIO_OUTPUT_5 167 
#define  PCM512x_GPIO_OUTPUT_6 166 
#define  PCM512x_GPIO_PLLIN 165 
 int PCM512x_GREF ; 
 int PCM512x_GREF_GPIO1 ; 
 int PCM512x_GxSL ; 
 int PCM512x_GxSL_PLLCK ; 
#define  PCM512x_I2S_1 164 
#define  PCM512x_I2S_2 163 
#define  PCM512x_IDAC_1 162 
#define  PCM512x_IDAC_2 161 
 int PCM512x_IDBK ; 
 int PCM512x_IDCH ; 
 int PCM512x_IDCM ; 
 int PCM512x_IDFS ; 
 int PCM512x_IDSK ; 
 int PCM512x_IPLK ; 
 int PCM512x_LRKO ; 
#define  PCM512x_MASTER_CLKDIV_1 160 
#define  PCM512x_MASTER_CLKDIV_2 159 
#define  PCM512x_MASTER_MODE 158 
#define  PCM512x_MUTE 157 
#define  PCM512x_NCP_CLKDIV 156 
#define  PCM512x_OSR_CLKDIV 155 
#define  PCM512x_OUTPUT_AMPLITUDE 154 
#define  PCM512x_OVERFLOW 153 
 int PCM512x_PLLE ; 
#define  PCM512x_PLL_COEFF_0 152 
#define  PCM512x_PLL_COEFF_1 151 
#define  PCM512x_PLL_COEFF_2 150 
#define  PCM512x_PLL_COEFF_3 149 
#define  PCM512x_PLL_COEFF_4 148 
#define  PCM512x_PLL_EN 147 
#define  PCM512x_PLL_REF 146 
#define  PCM512x_POWER 145 
#define  PCM512x_RATE_DET_1 144 
#define  PCM512x_RATE_DET_2 143 
#define  PCM512x_RATE_DET_3 142 
#define  PCM512x_RATE_DET_4 141 
 int PCM512x_RBCK ; 
#define  PCM512x_RESET 140 
 int PCM512x_RLRK ; 
 int PCM512x_RQML ; 
 int PCM512x_RQML_SHIFT ; 
 int PCM512x_RQMR ; 
 int PCM512x_RQMR_SHIFT ; 
 int PCM512x_RQST ; 
 int PCM512x_RQSY ; 
 int PCM512x_RQSY_HALT ; 
 int PCM512x_RQSY_RESUME ; 
 int PCM512x_RSTM ; 
 int PCM512x_RSTR ; 
 int PCM512x_SDAC ; 
 int PCM512x_SDAC_GPIO ; 
 int PCM512x_SDAC_SCK ; 
#define  PCM512x_SPI_MISO_FUNCTION 139 
 int PCM512x_SREF ; 
 int PCM512x_SREF_BCK ; 
 int PCM512x_SREF_GPIO ; 
#define  PCM512x_SYNCHRONIZE 138 
#define  PCM512x_UNDERVOLTAGE_PROT 137 
#define  PCM512x_VCOM_CTRL_1 136 
#define  PCM512x_VCOM_CTRL_2 135 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_FRAME_BITS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_BIAS_OFF 134 
#define  SND_SOC_BIAS_ON 133 
#define  SND_SOC_BIAS_PREPARE 132 
#define  SND_SOC_BIAS_STANDBY 131 
#define  SND_SOC_DAIFMT_CBM_CFM 130 
#define  SND_SOC_DAIFMT_CBM_CFS 129 
#define  SND_SOC_DAIFMT_CBS_CFS 128 
 int SND_SOC_DAIFMT_MASTER_MASK ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_get_rate (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  constraints_slave ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct pcm512x_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct pcm512x_priv*) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,struct snd_interval*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int fls (int) ; 
 unsigned long gcd (int,unsigned long) ; 
 int /*<<< orphan*/  hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct snd_interval*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned long params_channels (struct snd_pcm_hw_params*) ; 
 unsigned long params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pcm512x_component_driver ; 
 int /*<<< orphan*/  pcm512x_dai ; 
 int /*<<< orphan*/  pcm512x_regulator_event_0 ; 
 int /*<<< orphan*/  pcm512x_regulator_event_1 ; 
 int /*<<< orphan*/  pcm512x_regulator_event_2 ; 
 int /*<<< orphan*/ * pcm512x_supply_names ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_idle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  regmap_read_poll_timeout (struct regmap*,int const,unsigned int,int,int,int) ; 
 int regmap_update_bits (struct regmap*,int const,int,int) ; 
 int regmap_write (struct regmap*,int const,int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,struct snd_interval*) ; 
 int regulator_bulk_enable (int,struct snd_interval*) ; 
 int regulator_register_notifier (int /*<<< orphan*/ ,TYPE_3__*) ; 
 unsigned long rounddown (unsigned long,unsigned long) ; 
 int snd_interval_ranges (int /*<<< orphan*/ ,int,struct snd_interval*,int /*<<< orphan*/ ) ; 
 int snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_pcm_hw_constraint_ratnums (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct snd_pcm_hw_constraint_ratnums*) ; 
 int snd_pcm_hw_rule_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct snd_pcm_hw_params*,struct snd_pcm_hw_rule*),struct pcm512x_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct pcm512x_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_params_to_bclk (struct snd_pcm_hw_params*) ; 
 int snd_soc_params_to_frame_size (struct snd_pcm_hw_params*) ; 

__attribute__((used)) static bool pcm512x_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case PCM512x_RESET:
	case PCM512x_POWER:
	case PCM512x_MUTE:
	case PCM512x_PLL_EN:
	case PCM512x_SPI_MISO_FUNCTION:
	case PCM512x_DSP:
	case PCM512x_GPIO_EN:
	case PCM512x_BCLK_LRCLK_CFG:
	case PCM512x_DSP_GPIO_INPUT:
	case PCM512x_MASTER_MODE:
	case PCM512x_PLL_REF:
	case PCM512x_DAC_REF:
	case PCM512x_GPIO_DACIN:
	case PCM512x_GPIO_PLLIN:
	case PCM512x_SYNCHRONIZE:
	case PCM512x_PLL_COEFF_0:
	case PCM512x_PLL_COEFF_1:
	case PCM512x_PLL_COEFF_2:
	case PCM512x_PLL_COEFF_3:
	case PCM512x_PLL_COEFF_4:
	case PCM512x_DSP_CLKDIV:
	case PCM512x_DAC_CLKDIV:
	case PCM512x_NCP_CLKDIV:
	case PCM512x_OSR_CLKDIV:
	case PCM512x_MASTER_CLKDIV_1:
	case PCM512x_MASTER_CLKDIV_2:
	case PCM512x_FS_SPEED_MODE:
	case PCM512x_IDAC_1:
	case PCM512x_IDAC_2:
	case PCM512x_ERROR_DETECT:
	case PCM512x_I2S_1:
	case PCM512x_I2S_2:
	case PCM512x_DAC_ROUTING:
	case PCM512x_DSP_PROGRAM:
	case PCM512x_CLKDET:
	case PCM512x_AUTO_MUTE:
	case PCM512x_DIGITAL_VOLUME_1:
	case PCM512x_DIGITAL_VOLUME_2:
	case PCM512x_DIGITAL_VOLUME_3:
	case PCM512x_DIGITAL_MUTE_1:
	case PCM512x_DIGITAL_MUTE_2:
	case PCM512x_DIGITAL_MUTE_3:
	case PCM512x_GPIO_OUTPUT_1:
	case PCM512x_GPIO_OUTPUT_2:
	case PCM512x_GPIO_OUTPUT_3:
	case PCM512x_GPIO_OUTPUT_4:
	case PCM512x_GPIO_OUTPUT_5:
	case PCM512x_GPIO_OUTPUT_6:
	case PCM512x_GPIO_CONTROL_1:
	case PCM512x_GPIO_CONTROL_2:
	case PCM512x_OVERFLOW:
	case PCM512x_RATE_DET_1:
	case PCM512x_RATE_DET_2:
	case PCM512x_RATE_DET_3:
	case PCM512x_RATE_DET_4:
	case PCM512x_CLOCK_STATUS:
	case PCM512x_ANALOG_MUTE_DET:
	case PCM512x_GPIN:
	case PCM512x_DIGITAL_MUTE_DET:
	case PCM512x_OUTPUT_AMPLITUDE:
	case PCM512x_ANALOG_GAIN_CTRL:
	case PCM512x_UNDERVOLTAGE_PROT:
	case PCM512x_ANALOG_MUTE_CTRL:
	case PCM512x_ANALOG_GAIN_BOOST:
	case PCM512x_VCOM_CTRL_1:
	case PCM512x_VCOM_CTRL_2:
	case PCM512x_CRAM_CTRL:
	case PCM512x_FLEX_A:
	case PCM512x_FLEX_B:
		return true;
	default:
		/* There are 256 raw register addresses */
		return reg < 0xff;
	}
}

__attribute__((used)) static bool pcm512x_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case PCM512x_PLL_EN:
	case PCM512x_OVERFLOW:
	case PCM512x_RATE_DET_1:
	case PCM512x_RATE_DET_2:
	case PCM512x_RATE_DET_3:
	case PCM512x_RATE_DET_4:
	case PCM512x_CLOCK_STATUS:
	case PCM512x_ANALOG_MUTE_DET:
	case PCM512x_GPIN:
	case PCM512x_DIGITAL_MUTE_DET:
	case PCM512x_CRAM_CTRL:
		return true;
	default:
		/* There are 256 raw register addresses */
		return reg < 0xff;
	}
}

__attribute__((used)) static int pcm512x_overclock_pll_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = pcm512x->overclock_pll;
	return 0;
}

__attribute__((used)) static int pcm512x_overclock_pll_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	switch (snd_soc_component_get_bias_level(component)) {
	case SND_SOC_BIAS_OFF:
	case SND_SOC_BIAS_STANDBY:
		break;
	default:
		return -EBUSY;
	}

	pcm512x->overclock_pll = ucontrol->value.integer.value[0];
	return 0;
}

__attribute__((used)) static int pcm512x_overclock_dsp_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = pcm512x->overclock_dsp;
	return 0;
}

__attribute__((used)) static int pcm512x_overclock_dsp_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	switch (snd_soc_component_get_bias_level(component)) {
	case SND_SOC_BIAS_OFF:
	case SND_SOC_BIAS_STANDBY:
		break;
	default:
		return -EBUSY;
	}

	pcm512x->overclock_dsp = ucontrol->value.integer.value[0];
	return 0;
}

__attribute__((used)) static int pcm512x_overclock_dac_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = pcm512x->overclock_dac;
	return 0;
}

__attribute__((used)) static int pcm512x_overclock_dac_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	switch (snd_soc_component_get_bias_level(component)) {
	case SND_SOC_BIAS_OFF:
	case SND_SOC_BIAS_STANDBY:
		break;
	default:
		return -EBUSY;
	}

	pcm512x->overclock_dac = ucontrol->value.integer.value[0];
	return 0;
}

__attribute__((used)) static int pcm512x_update_mute(struct pcm512x_priv *pcm512x)
{
	return regmap_update_bits(
		pcm512x->regmap, PCM512x_MUTE, PCM512x_RQML | PCM512x_RQMR,
		(!!(pcm512x->mute & 0x5) << PCM512x_RQML_SHIFT)
		| (!!(pcm512x->mute & 0x3) << PCM512x_RQMR_SHIFT));
}

__attribute__((used)) static int pcm512x_digital_playback_switch_get(struct snd_kcontrol *kcontrol,
					       struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	mutex_lock(&pcm512x->mutex);
	ucontrol->value.integer.value[0] = !(pcm512x->mute & 0x4);
	ucontrol->value.integer.value[1] = !(pcm512x->mute & 0x2);
	mutex_unlock(&pcm512x->mutex);

	return 0;
}

__attribute__((used)) static int pcm512x_digital_playback_switch_put(struct snd_kcontrol *kcontrol,
					       struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	int ret, changed = 0;

	mutex_lock(&pcm512x->mutex);

	if ((pcm512x->mute & 0x4) == (ucontrol->value.integer.value[0] << 2)) {
		pcm512x->mute ^= 0x4;
		changed = 1;
	}
	if ((pcm512x->mute & 0x2) == (ucontrol->value.integer.value[1] << 1)) {
		pcm512x->mute ^= 0x2;
		changed = 1;
	}

	if (changed) {
		ret = pcm512x_update_mute(pcm512x);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to update digital mute: %d\n", ret);
			mutex_unlock(&pcm512x->mutex);
			return ret;
		}
	}

	mutex_unlock(&pcm512x->mutex);

	return changed;
}

__attribute__((used)) static unsigned long pcm512x_pll_max(struct pcm512x_priv *pcm512x)
{
	return 25000000 + 25000000 * pcm512x->overclock_pll / 100;
}

__attribute__((used)) static unsigned long pcm512x_dsp_max(struct pcm512x_priv *pcm512x)
{
	return 50000000 + 50000000 * pcm512x->overclock_dsp / 100;
}

__attribute__((used)) static unsigned long pcm512x_dac_max(struct pcm512x_priv *pcm512x,
				     unsigned long rate)
{
	return rate + rate * pcm512x->overclock_dac / 100;
}

__attribute__((used)) static unsigned long pcm512x_sck_max(struct pcm512x_priv *pcm512x)
{
	if (!pcm512x->pll_out)
		return 25000000;
	return pcm512x_pll_max(pcm512x);
}

__attribute__((used)) static unsigned long pcm512x_ncp_target(struct pcm512x_priv *pcm512x,
					unsigned long dac_rate)
{
	/*
	 * If the DAC is not actually overclocked, use the good old
	 * NCP target rate...
	 */
	if (dac_rate <= 6144000)
		return 1536000;
	/*
	 * ...but if the DAC is in fact overclocked, bump the NCP target
	 * rate to get the recommended dividers even when overclocking.
	 */
	return pcm512x_dac_max(pcm512x, 1536000);
}

__attribute__((used)) static int pcm512x_hw_rule_rate(struct snd_pcm_hw_params *params,
				struct snd_pcm_hw_rule *rule)
{
	struct pcm512x_priv *pcm512x = rule->private;
	struct snd_interval ranges[2];
	int frame_size;

	frame_size = snd_soc_params_to_frame_size(params);
	if (frame_size < 0)
		return frame_size;

	switch (frame_size) {
	case 32:
		/* No hole when the frame size is 32. */
		return 0;
	case 48:
	case 64:
		/* There is only one hole in the range of supported
		 * rates, but it moves with the frame size.
		 */
		memset(ranges, 0, sizeof(ranges));
		ranges[0].min = 8000;
		ranges[0].max = pcm512x_sck_max(pcm512x) / frame_size / 2;
		ranges[1].min = DIV_ROUND_UP(16000000, frame_size);
		ranges[1].max = 384000;
		break;
	default:
		return -EINVAL;
	}

	return snd_interval_ranges(hw_param_interval(params, rule->var),
				   ARRAY_SIZE(ranges), ranges, 0);
}

__attribute__((used)) static int pcm512x_dai_startup_master(struct snd_pcm_substream *substream,
				      struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	struct device *dev = dai->dev;
	struct snd_pcm_hw_constraint_ratnums *constraints_no_pll;
	struct snd_ratnum *rats_no_pll;

	if (IS_ERR(pcm512x->sclk)) {
		dev_err(dev, "Need SCLK for master mode: %ld\n",
			PTR_ERR(pcm512x->sclk));
		return PTR_ERR(pcm512x->sclk);
	}

	if (pcm512x->pll_out)
		return snd_pcm_hw_rule_add(substream->runtime, 0,
					   SNDRV_PCM_HW_PARAM_RATE,
					   pcm512x_hw_rule_rate,
					   pcm512x,
					   SNDRV_PCM_HW_PARAM_FRAME_BITS,
					   SNDRV_PCM_HW_PARAM_CHANNELS, -1);

	constraints_no_pll = devm_kzalloc(dev, sizeof(*constraints_no_pll),
					  GFP_KERNEL);
	if (!constraints_no_pll)
		return -ENOMEM;
	constraints_no_pll->nrats = 1;
	rats_no_pll = devm_kzalloc(dev, sizeof(*rats_no_pll), GFP_KERNEL);
	if (!rats_no_pll)
		return -ENOMEM;
	constraints_no_pll->rats = rats_no_pll;
	rats_no_pll->num = clk_get_rate(pcm512x->sclk) / 64;
	rats_no_pll->den_min = 1;
	rats_no_pll->den_max = 128;
	rats_no_pll->den_step = 1;

	return snd_pcm_hw_constraint_ratnums(substream->runtime, 0,
					     SNDRV_PCM_HW_PARAM_RATE,
					     constraints_no_pll);
}

__attribute__((used)) static int pcm512x_dai_startup_slave(struct snd_pcm_substream *substream,
				     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	struct device *dev = dai->dev;
	struct regmap *regmap = pcm512x->regmap;

	if (IS_ERR(pcm512x->sclk)) {
		dev_info(dev, "No SCLK, using BCLK: %ld\n",
			 PTR_ERR(pcm512x->sclk));

		/* Disable reporting of missing SCLK as an error */
		regmap_update_bits(regmap, PCM512x_ERROR_DETECT,
				   PCM512x_IDCH, PCM512x_IDCH);

		/* Switch PLL input to BCLK */
		regmap_update_bits(regmap, PCM512x_PLL_REF,
				   PCM512x_SREF, PCM512x_SREF_BCK);
	}

	return snd_pcm_hw_constraint_list(substream->runtime, 0,
					  SNDRV_PCM_HW_PARAM_RATE,
					  &constraints_slave);
}

__attribute__((used)) static int pcm512x_dai_startup(struct snd_pcm_substream *substream,
			       struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	switch (pcm512x->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
	case SND_SOC_DAIFMT_CBM_CFS:
		return pcm512x_dai_startup_master(substream, dai);

	case SND_SOC_DAIFMT_CBS_CFS:
		return pcm512x_dai_startup_slave(substream, dai);

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int pcm512x_set_bias_level(struct snd_soc_component *component,
				  enum snd_soc_bias_level level)
{
	struct pcm512x_priv *pcm512x = dev_get_drvdata(component->dev);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
	case SND_SOC_BIAS_PREPARE:
		break;

	case SND_SOC_BIAS_STANDBY:
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
					 PCM512x_RQST, 0);
		if (ret != 0) {
			dev_err(component->dev, "Failed to remove standby: %d\n",
				ret);
			return ret;
		}
		break;

	case SND_SOC_BIAS_OFF:
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
					 PCM512x_RQST, PCM512x_RQST);
		if (ret != 0) {
			dev_err(component->dev, "Failed to request standby: %d\n",
				ret);
			return ret;
		}
		break;
	}

	return 0;
}

__attribute__((used)) static unsigned long pcm512x_find_sck(struct snd_soc_dai *dai,
				      unsigned long bclk_rate)
{
	struct device *dev = dai->dev;
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	unsigned long sck_rate;
	int pow2;

	/* 64 MHz <= pll_rate <= 100 MHz, VREF mode */
	/* 16 MHz <= sck_rate <=  25 MHz, VREF mode */

	/* select sck_rate as a multiple of bclk_rate but still with
	 * as many factors of 2 as possible, as that makes it easier
	 * to find a fast DAC rate
	 */
	pow2 = 1 << fls((pcm512x_pll_max(pcm512x) - 16000000) / bclk_rate);
	for (; pow2; pow2 >>= 1) {
		sck_rate = rounddown(pcm512x_pll_max(pcm512x),
				     bclk_rate * pow2);
		if (sck_rate >= 16000000)
			break;
	}
	if (!pow2) {
		dev_err(dev, "Impossible to generate a suitable SCK\n");
		return 0;
	}

	dev_dbg(dev, "sck_rate %lu\n", sck_rate);
	return sck_rate;
}

__attribute__((used)) static int pcm512x_find_pll_coeff(struct snd_soc_dai *dai,
				  unsigned long pllin_rate,
				  unsigned long pll_rate)
{
	struct device *dev = dai->dev;
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	unsigned long common;
	int R, J, D, P;
	unsigned long K; /* 10000 * J.D */
	unsigned long num;
	unsigned long den;

	common = gcd(pll_rate, pllin_rate);
	dev_dbg(dev, "pll %lu pllin %lu common %lu\n",
		pll_rate, pllin_rate, common);
	num = pll_rate / common;
	den = pllin_rate / common;

	/* pllin_rate / P (or here, den) cannot be greater than 20 MHz */
	if (pllin_rate / den > 20000000 && num < 8) {
		num *= DIV_ROUND_UP(pllin_rate / den, 20000000);
		den *= DIV_ROUND_UP(pllin_rate / den, 20000000);
	}
	dev_dbg(dev, "num / den = %lu / %lu\n", num, den);

	P = den;
	if (den <= 15 && num <= 16 * 63
	    && 1000000 <= pllin_rate / P && pllin_rate / P <= 20000000) {
		/* Try the case with D = 0 */
		D = 0;
		/* factor 'num' into J and R, such that R <= 16 and J <= 63 */
		for (R = 16; R; R--) {
			if (num % R)
				continue;
			J = num / R;
			if (J == 0 || J > 63)
				continue;

			dev_dbg(dev, "R * J / P = %d * %d / %d\n", R, J, P);
			pcm512x->real_pll = pll_rate;
			goto done;
		}
		/* no luck */
	}

	R = 1;

	if (num > 0xffffffffUL / 10000)
		goto fallback;

	/* Try to find an exact pll_rate using the D > 0 case */
	common = gcd(10000 * num, den);
	num = 10000 * num / common;
	den /= common;
	dev_dbg(dev, "num %lu den %lu common %lu\n", num, den, common);

	for (P = den; P <= 15; P++) {
		if (pllin_rate / P < 6667000 || 200000000 < pllin_rate / P)
			continue;
		if (num * P % den)
			continue;
		K = num * P / den;
		/* J == 12 is ok if D == 0 */
		if (K < 40000 || K > 120000)
			continue;

		J = K / 10000;
		D = K % 10000;
		dev_dbg(dev, "J.D / P = %d.%04d / %d\n", J, D, P);
		pcm512x->real_pll = pll_rate;
		goto done;
	}

	/* Fall back to an approximate pll_rate */

fallback:
	/* find smallest possible P */
	P = DIV_ROUND_UP(pllin_rate, 20000000);
	if (!P)
		P = 1;
	else if (P > 15) {
		dev_err(dev, "Need a slower clock as pll-input\n");
		return -EINVAL;
	}
	if (pllin_rate / P < 6667000) {
		dev_err(dev, "Need a faster clock as pll-input\n");
		return -EINVAL;
	}
	K = DIV_ROUND_CLOSEST_ULL(10000ULL * pll_rate * P, pllin_rate);
	if (K < 40000)
		K = 40000;
	/* J == 12 is ok if D == 0 */
	if (K > 120000)
		K = 120000;
	J = K / 10000;
	D = K % 10000;
	dev_dbg(dev, "J.D / P ~ %d.%04d / %d\n", J, D, P);
	pcm512x->real_pll = DIV_ROUND_DOWN_ULL((u64)K * pllin_rate, 10000 * P);

done:
	pcm512x->pll_r = R;
	pcm512x->pll_j = J;
	pcm512x->pll_d = D;
	pcm512x->pll_p = P;
	return 0;
}

__attribute__((used)) static unsigned long pcm512x_pllin_dac_rate(struct snd_soc_dai *dai,
					    unsigned long osr_rate,
					    unsigned long pllin_rate)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	unsigned long dac_rate;

	if (!pcm512x->pll_out)
		return 0; /* no PLL to bypass, force SCK as DAC input */

	if (pllin_rate % osr_rate)
		return 0; /* futile, quit early */

	/* run DAC no faster than 6144000 Hz */
	for (dac_rate = rounddown(pcm512x_dac_max(pcm512x, 6144000), osr_rate);
	     dac_rate;
	     dac_rate -= osr_rate) {

		if (pllin_rate / dac_rate > 128)
			return 0; /* DAC divider would be too big */

		if (!(pllin_rate % dac_rate))
			return dac_rate;

		dac_rate -= osr_rate;
	}

	return 0;
}

__attribute__((used)) static int pcm512x_set_dividers(struct snd_soc_dai *dai,
				struct snd_pcm_hw_params *params)
{
	struct device *dev = dai->dev;
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	unsigned long pllin_rate = 0;
	unsigned long pll_rate;
	unsigned long sck_rate;
	unsigned long mck_rate;
	unsigned long bclk_rate;
	unsigned long sample_rate;
	unsigned long osr_rate;
	unsigned long dacsrc_rate;
	int bclk_div;
	int lrclk_div;
	int dsp_div;
	int dac_div;
	unsigned long dac_rate;
	int ncp_div;
	int osr_div;
	int ret;
	int idac;
	int fssp;
	int gpio;

	if (pcm512x->lrclk_div)
		lrclk_div = pcm512x->lrclk_div;
	else
		lrclk_div = snd_soc_params_to_frame_size(params);
	if (lrclk_div == 0) {
		dev_err(dev, "No LRCLK?\n");
		return -EINVAL;
	}

	if (!pcm512x->pll_out) {
		sck_rate = clk_get_rate(pcm512x->sclk);
		bclk_div = params->rate_den * 64 / lrclk_div;
		bclk_rate = DIV_ROUND_CLOSEST(sck_rate, bclk_div);

		mck_rate = sck_rate;
	} else {
		ret = snd_soc_params_to_bclk(params);
		if (ret < 0) {
			dev_err(dev, "Failed to find suitable BCLK: %d\n", ret);
			return ret;
		}
		if (ret == 0) {
			dev_err(dev, "No BCLK?\n");
			return -EINVAL;
		}
		bclk_rate = ret;

		pllin_rate = clk_get_rate(pcm512x->sclk);

		sck_rate = pcm512x_find_sck(dai, bclk_rate);
		if (!sck_rate)
			return -EINVAL;
		pll_rate = 4 * sck_rate;

		ret = pcm512x_find_pll_coeff(dai, pllin_rate, pll_rate);
		if (ret != 0)
			return ret;

		ret = regmap_write(pcm512x->regmap,
				   PCM512x_PLL_COEFF_0, pcm512x->pll_p - 1);
		if (ret != 0) {
			dev_err(dev, "Failed to write PLL P: %d\n", ret);
			return ret;
		}

		ret = regmap_write(pcm512x->regmap,
				   PCM512x_PLL_COEFF_1, pcm512x->pll_j);
		if (ret != 0) {
			dev_err(dev, "Failed to write PLL J: %d\n", ret);
			return ret;
		}

		ret = regmap_write(pcm512x->regmap,
				   PCM512x_PLL_COEFF_2, pcm512x->pll_d >> 8);
		if (ret != 0) {
			dev_err(dev, "Failed to write PLL D msb: %d\n", ret);
			return ret;
		}

		ret = regmap_write(pcm512x->regmap,
				   PCM512x_PLL_COEFF_3, pcm512x->pll_d & 0xff);
		if (ret != 0) {
			dev_err(dev, "Failed to write PLL D lsb: %d\n", ret);
			return ret;
		}

		ret = regmap_write(pcm512x->regmap,
				   PCM512x_PLL_COEFF_4, pcm512x->pll_r - 1);
		if (ret != 0) {
			dev_err(dev, "Failed to write PLL R: %d\n", ret);
			return ret;
		}

		mck_rate = pcm512x->real_pll;

		bclk_div = DIV_ROUND_CLOSEST(sck_rate, bclk_rate);
	}

	if (bclk_div > 128) {
		dev_err(dev, "Failed to find BCLK divider\n");
		return -EINVAL;
	}

	/* the actual rate */
	sample_rate = sck_rate / bclk_div / lrclk_div;
	osr_rate = 16 * sample_rate;

	/* run DSP no faster than 50 MHz */
	dsp_div = mck_rate > pcm512x_dsp_max(pcm512x) ? 2 : 1;

	dac_rate = pcm512x_pllin_dac_rate(dai, osr_rate, pllin_rate);
	if (dac_rate) {
		/* the desired clock rate is "compatible" with the pll input
		 * clock, so use that clock as dac input instead of the pll
		 * output clock since the pll will introduce jitter and thus
		 * noise.
		 */
		dev_dbg(dev, "using pll input as dac input\n");
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_DAC_REF,
					 PCM512x_SDAC, PCM512x_SDAC_GPIO);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to set gpio as dacref: %d\n", ret);
			return ret;
		}

		gpio = PCM512x_GREF_GPIO1 + pcm512x->pll_in - 1;
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_GPIO_DACIN,
					 PCM512x_GREF, gpio);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to set gpio %d as dacin: %d\n",
				pcm512x->pll_in, ret);
			return ret;
		}

		dacsrc_rate = pllin_rate;
	} else {
		/* run DAC no faster than 6144000 Hz */
		unsigned long dac_mul = pcm512x_dac_max(pcm512x, 6144000)
			/ osr_rate;
		unsigned long sck_mul = sck_rate / osr_rate;

		for (; dac_mul; dac_mul--) {
			if (!(sck_mul % dac_mul))
				break;
		}
		if (!dac_mul) {
			dev_err(dev, "Failed to find DAC rate\n");
			return -EINVAL;
		}

		dac_rate = dac_mul * osr_rate;
		dev_dbg(dev, "dac_rate %lu sample_rate %lu\n",
			dac_rate, sample_rate);

		ret = regmap_update_bits(pcm512x->regmap, PCM512x_DAC_REF,
					 PCM512x_SDAC, PCM512x_SDAC_SCK);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to set sck as dacref: %d\n", ret);
			return ret;
		}

		dacsrc_rate = sck_rate;
	}

	osr_div = DIV_ROUND_CLOSEST(dac_rate, osr_rate);
	if (osr_div > 128) {
		dev_err(dev, "Failed to find OSR divider\n");
		return -EINVAL;
	}

	dac_div = DIV_ROUND_CLOSEST(dacsrc_rate, dac_rate);
	if (dac_div > 128) {
		dev_err(dev, "Failed to find DAC divider\n");
		return -EINVAL;
	}
	dac_rate = dacsrc_rate / dac_div;

	ncp_div = DIV_ROUND_CLOSEST(dac_rate,
				    pcm512x_ncp_target(pcm512x, dac_rate));
	if (ncp_div > 128 || dac_rate / ncp_div > 2048000) {
		/* run NCP no faster than 2048000 Hz, but why? */
		ncp_div = DIV_ROUND_UP(dac_rate, 2048000);
		if (ncp_div > 128) {
			dev_err(dev, "Failed to find NCP divider\n");
			return -EINVAL;
		}
	}

	idac = mck_rate / (dsp_div * sample_rate);

	ret = regmap_write(pcm512x->regmap, PCM512x_DSP_CLKDIV, dsp_div - 1);
	if (ret != 0) {
		dev_err(dev, "Failed to write DSP divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap, PCM512x_DAC_CLKDIV, dac_div - 1);
	if (ret != 0) {
		dev_err(dev, "Failed to write DAC divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap, PCM512x_NCP_CLKDIV, ncp_div - 1);
	if (ret != 0) {
		dev_err(dev, "Failed to write NCP divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap, PCM512x_OSR_CLKDIV, osr_div - 1);
	if (ret != 0) {
		dev_err(dev, "Failed to write OSR divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap,
			   PCM512x_MASTER_CLKDIV_1, bclk_div - 1);
	if (ret != 0) {
		dev_err(dev, "Failed to write BCLK divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap,
			   PCM512x_MASTER_CLKDIV_2, lrclk_div - 1);
	if (ret != 0) {
		dev_err(dev, "Failed to write LRCLK divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap, PCM512x_IDAC_1, idac >> 8);
	if (ret != 0) {
		dev_err(dev, "Failed to write IDAC msb divider: %d\n", ret);
		return ret;
	}

	ret = regmap_write(pcm512x->regmap, PCM512x_IDAC_2, idac & 0xff);
	if (ret != 0) {
		dev_err(dev, "Failed to write IDAC lsb divider: %d\n", ret);
		return ret;
	}

	if (sample_rate <= pcm512x_dac_max(pcm512x, 48000))
		fssp = PCM512x_FSSP_48KHZ;
	else if (sample_rate <= pcm512x_dac_max(pcm512x, 96000))
		fssp = PCM512x_FSSP_96KHZ;
	else if (sample_rate <= pcm512x_dac_max(pcm512x, 192000))
		fssp = PCM512x_FSSP_192KHZ;
	else
		fssp = PCM512x_FSSP_384KHZ;
	ret = regmap_update_bits(pcm512x->regmap, PCM512x_FS_SPEED_MODE,
				 PCM512x_FSSP, fssp);
	if (ret != 0) {
		dev_err(component->dev, "Failed to set fs speed: %d\n", ret);
		return ret;
	}

	dev_dbg(component->dev, "DSP divider %d\n", dsp_div);
	dev_dbg(component->dev, "DAC divider %d\n", dac_div);
	dev_dbg(component->dev, "NCP divider %d\n", ncp_div);
	dev_dbg(component->dev, "OSR divider %d\n", osr_div);
	dev_dbg(component->dev, "BCK divider %d\n", bclk_div);
	dev_dbg(component->dev, "LRCK divider %d\n", lrclk_div);
	dev_dbg(component->dev, "IDAC %d\n", idac);
	dev_dbg(component->dev, "1<<FSSP %d\n", 1 << fssp);

	return 0;
}

__attribute__((used)) static int pcm512x_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	int alen;
	int gpio;
	int clock_output;
	int master_mode;
	int ret;

	dev_dbg(component->dev, "hw_params %u Hz, %u channels\n",
		params_rate(params),
		params_channels(params));

	switch (params_width(params)) {
	case 16:
		alen = PCM512x_ALEN_16;
		break;
	case 20:
		alen = PCM512x_ALEN_20;
		break;
	case 24:
		alen = PCM512x_ALEN_24;
		break;
	case 32:
		alen = PCM512x_ALEN_32;
		break;
	default:
		dev_err(component->dev, "Bad frame size: %d\n",
			params_width(params));
		return -EINVAL;
	}

	switch (pcm512x->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		ret = regmap_update_bits(pcm512x->regmap,
					 PCM512x_BCLK_LRCLK_CFG,
					 PCM512x_BCKP
					 | PCM512x_BCKO | PCM512x_LRKO,
					 0);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to enable slave mode: %d\n", ret);
			return ret;
		}

		ret = regmap_update_bits(pcm512x->regmap, PCM512x_ERROR_DETECT,
					 PCM512x_DCAS, 0);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to enable clock divider autoset: %d\n",
				ret);
			return ret;
		}
		return 0;
	case SND_SOC_DAIFMT_CBM_CFM:
		clock_output = PCM512x_BCKO | PCM512x_LRKO;
		master_mode = PCM512x_RLRK | PCM512x_RBCK;
		break;
	case SND_SOC_DAIFMT_CBM_CFS:
		clock_output = PCM512x_BCKO;
		master_mode = PCM512x_RBCK;
		break;
	default:
		return -EINVAL;
	}

	ret = regmap_update_bits(pcm512x->regmap, PCM512x_I2S_1,
				 PCM512x_ALEN, alen);
	if (ret != 0) {
		dev_err(component->dev, "Failed to set frame size: %d\n", ret);
		return ret;
	}

	if (pcm512x->pll_out) {
		ret = regmap_write(pcm512x->regmap, PCM512x_FLEX_A, 0x11);
		if (ret != 0) {
			dev_err(component->dev, "Failed to set FLEX_A: %d\n", ret);
			return ret;
		}

		ret = regmap_write(pcm512x->regmap, PCM512x_FLEX_B, 0xff);
		if (ret != 0) {
			dev_err(component->dev, "Failed to set FLEX_B: %d\n", ret);
			return ret;
		}

		ret = regmap_update_bits(pcm512x->regmap, PCM512x_ERROR_DETECT,
					 PCM512x_IDFS | PCM512x_IDBK
					 | PCM512x_IDSK | PCM512x_IDCH
					 | PCM512x_IDCM | PCM512x_DCAS
					 | PCM512x_IPLK,
					 PCM512x_IDFS | PCM512x_IDBK
					 | PCM512x_IDSK | PCM512x_IDCH
					 | PCM512x_DCAS);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to ignore auto-clock failures: %d\n",
				ret);
			return ret;
		}
	} else {
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_ERROR_DETECT,
					 PCM512x_IDFS | PCM512x_IDBK
					 | PCM512x_IDSK | PCM512x_IDCH
					 | PCM512x_IDCM | PCM512x_DCAS
					 | PCM512x_IPLK,
					 PCM512x_IDFS | PCM512x_IDBK
					 | PCM512x_IDSK | PCM512x_IDCH
					 | PCM512x_DCAS | PCM512x_IPLK);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to ignore auto-clock failures: %d\n",
				ret);
			return ret;
		}

		ret = regmap_update_bits(pcm512x->regmap, PCM512x_PLL_EN,
					 PCM512x_PLLE, 0);
		if (ret != 0) {
			dev_err(component->dev, "Failed to disable pll: %d\n", ret);
			return ret;
		}
	}

	ret = pcm512x_set_dividers(dai, params);
	if (ret != 0)
		return ret;

	if (pcm512x->pll_out) {
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_PLL_REF,
					 PCM512x_SREF, PCM512x_SREF_GPIO);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to set gpio as pllref: %d\n", ret);
			return ret;
		}

		gpio = PCM512x_GREF_GPIO1 + pcm512x->pll_in - 1;
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_GPIO_PLLIN,
					 PCM512x_GREF, gpio);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to set gpio %d as pllin: %d\n",
				pcm512x->pll_in, ret);
			return ret;
		}

		ret = regmap_update_bits(pcm512x->regmap, PCM512x_PLL_EN,
					 PCM512x_PLLE, PCM512x_PLLE);
		if (ret != 0) {
			dev_err(component->dev, "Failed to enable pll: %d\n", ret);
			return ret;
		}
	}

	ret = regmap_update_bits(pcm512x->regmap, PCM512x_BCLK_LRCLK_CFG,
				 PCM512x_BCKP | PCM512x_BCKO | PCM512x_LRKO,
				 clock_output);
	if (ret != 0) {
		dev_err(component->dev, "Failed to enable clock output: %d\n", ret);
		return ret;
	}

	ret = regmap_update_bits(pcm512x->regmap, PCM512x_MASTER_MODE,
				 PCM512x_RLRK | PCM512x_RBCK,
				 master_mode);
	if (ret != 0) {
		dev_err(component->dev, "Failed to enable master mode: %d\n", ret);
		return ret;
	}

	if (pcm512x->pll_out) {
		gpio = PCM512x_G1OE << (pcm512x->pll_out - 1);
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_GPIO_EN,
					 gpio, gpio);
		if (ret != 0) {
			dev_err(component->dev, "Failed to enable gpio %d: %d\n",
				pcm512x->pll_out, ret);
			return ret;
		}

		gpio = PCM512x_GPIO_OUTPUT_1 + pcm512x->pll_out - 1;
		ret = regmap_update_bits(pcm512x->regmap, gpio,
					 PCM512x_GxSL, PCM512x_GxSL_PLLCK);
		if (ret != 0) {
			dev_err(component->dev, "Failed to output pll on %d: %d\n",
				ret, pcm512x->pll_out);
			return ret;
		}
	}

	ret = regmap_update_bits(pcm512x->regmap, PCM512x_SYNCHRONIZE,
				 PCM512x_RQSY, PCM512x_RQSY_HALT);
	if (ret != 0) {
		dev_err(component->dev, "Failed to halt clocks: %d\n", ret);
		return ret;
	}

	ret = regmap_update_bits(pcm512x->regmap, PCM512x_SYNCHRONIZE,
				 PCM512x_RQSY, PCM512x_RQSY_RESUME);
	if (ret != 0) {
		dev_err(component->dev, "Failed to resume clocks: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int pcm512x_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	pcm512x->fmt = fmt;

	return 0;
}

__attribute__((used)) static int pcm512x_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);
	int ret;
	unsigned int mute_det;

	mutex_lock(&pcm512x->mutex);

	if (mute) {
		pcm512x->mute |= 0x1;
		ret = regmap_update_bits(pcm512x->regmap, PCM512x_MUTE,
					 PCM512x_RQML | PCM512x_RQMR,
					 PCM512x_RQML | PCM512x_RQMR);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to set digital mute: %d\n", ret);
			goto unlock;
		}

		regmap_read_poll_timeout(pcm512x->regmap,
					 PCM512x_ANALOG_MUTE_DET,
					 mute_det, (mute_det & 0x3) == 0,
					 200, 10000);
	} else {
		pcm512x->mute &= ~0x1;
		ret = pcm512x_update_mute(pcm512x);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to update digital mute: %d\n", ret);
			goto unlock;
		}

		regmap_read_poll_timeout(pcm512x->regmap,
					 PCM512x_ANALOG_MUTE_DET,
					 mute_det,
					 (mute_det & 0x3)
					 == ((~pcm512x->mute >> 1) & 0x3),
					 200, 10000);
	}

unlock:
	mutex_unlock(&pcm512x->mutex);

	return ret;
}

__attribute__((used)) static int pcm512x_set_tdm_slot(struct snd_soc_dai *dai,
	unsigned int tx_mask, unsigned int rx_mask,
	int slots, int width)
{
	struct snd_soc_component *component = dai->component;
	struct pcm512x_priv *pcm512x = snd_soc_component_get_drvdata(component);

	switch (slots) {
	case 0:
		pcm512x->lrclk_div = 0;
		return 0;
	case 2:
		if (tx_mask != 0x03 || rx_mask != 0x03)
			return -EINVAL;
		pcm512x->lrclk_div = slots * width;
		return 0;
	default:
		return -EINVAL;
	}
}

int pcm512x_probe(struct device *dev, struct regmap *regmap)
{
	struct pcm512x_priv *pcm512x;
	int i, ret;

	pcm512x = devm_kzalloc(dev, sizeof(struct pcm512x_priv), GFP_KERNEL);
	if (!pcm512x)
		return -ENOMEM;

	mutex_init(&pcm512x->mutex);

	dev_set_drvdata(dev, pcm512x);
	pcm512x->regmap = regmap;

	for (i = 0; i < ARRAY_SIZE(pcm512x->supplies); i++)
		pcm512x->supplies[i].supply = pcm512x_supply_names[i];

	ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(pcm512x->supplies),
				      pcm512x->supplies);
	if (ret != 0) {
		dev_err(dev, "Failed to get supplies: %d\n", ret);
		return ret;
	}

	pcm512x->supply_nb[0].notifier_call = pcm512x_regulator_event_0;
	pcm512x->supply_nb[1].notifier_call = pcm512x_regulator_event_1;
	pcm512x->supply_nb[2].notifier_call = pcm512x_regulator_event_2;

	for (i = 0; i < ARRAY_SIZE(pcm512x->supplies); i++) {
		ret = regulator_register_notifier(pcm512x->supplies[i].consumer,
						  &pcm512x->supply_nb[i]);
		if (ret != 0) {
			dev_err(dev,
				"Failed to register regulator notifier: %d\n",
				ret);
		}
	}

	ret = regulator_bulk_enable(ARRAY_SIZE(pcm512x->supplies),
				    pcm512x->supplies);
	if (ret != 0) {
		dev_err(dev, "Failed to enable supplies: %d\n", ret);
		return ret;
	}

	/* Reset the device, verifying I/O in the process for I2C */
	ret = regmap_write(regmap, PCM512x_RESET,
			   PCM512x_RSTM | PCM512x_RSTR);
	if (ret != 0) {
		dev_err(dev, "Failed to reset device: %d\n", ret);
		goto err;
	}

	ret = regmap_write(regmap, PCM512x_RESET, 0);
	if (ret != 0) {
		dev_err(dev, "Failed to reset device: %d\n", ret);
		goto err;
	}

	pcm512x->sclk = devm_clk_get(dev, NULL);
	if (PTR_ERR(pcm512x->sclk) == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (!IS_ERR(pcm512x->sclk)) {
		ret = clk_prepare_enable(pcm512x->sclk);
		if (ret != 0) {
			dev_err(dev, "Failed to enable SCLK: %d\n", ret);
			return ret;
		}
	}

	/* Default to standby mode */
	ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
				 PCM512x_RQST, PCM512x_RQST);
	if (ret != 0) {
		dev_err(dev, "Failed to request standby: %d\n",
			ret);
		goto err_clk;
	}

	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	pm_runtime_idle(dev);

#ifdef CONFIG_OF
	if (dev->of_node) {
		const struct device_node *np = dev->of_node;
		u32 val;

		if (of_property_read_u32(np, "pll-in", &val) >= 0) {
			if (val > 6) {
				dev_err(dev, "Invalid pll-in\n");
				ret = -EINVAL;
				goto err_clk;
			}
			pcm512x->pll_in = val;
		}

		if (of_property_read_u32(np, "pll-out", &val) >= 0) {
			if (val > 6) {
				dev_err(dev, "Invalid pll-out\n");
				ret = -EINVAL;
				goto err_clk;
			}
			pcm512x->pll_out = val;
		}

		if (!pcm512x->pll_in != !pcm512x->pll_out) {
			dev_err(dev,
				"Error: both pll-in and pll-out, or none\n");
			ret = -EINVAL;
			goto err_clk;
		}
		if (pcm512x->pll_in && pcm512x->pll_in == pcm512x->pll_out) {
			dev_err(dev, "Error: pll-in == pll-out\n");
			ret = -EINVAL;
			goto err_clk;
		}
	}
#endif

	ret = devm_snd_soc_register_component(dev, &pcm512x_component_driver,
				    &pcm512x_dai, 1);
	if (ret != 0) {
		dev_err(dev, "Failed to register CODEC: %d\n", ret);
		goto err_pm;
	}

	return 0;

err_pm:
	pm_runtime_disable(dev);
err_clk:
	if (!IS_ERR(pcm512x->sclk))
		clk_disable_unprepare(pcm512x->sclk);
err:
	regulator_bulk_disable(ARRAY_SIZE(pcm512x->supplies),
				     pcm512x->supplies);
	return ret;
}

void pcm512x_remove(struct device *dev)
{
	struct pcm512x_priv *pcm512x = dev_get_drvdata(dev);

	pm_runtime_disable(dev);
	if (!IS_ERR(pcm512x->sclk))
		clk_disable_unprepare(pcm512x->sclk);
	regulator_bulk_disable(ARRAY_SIZE(pcm512x->supplies),
			       pcm512x->supplies);
}


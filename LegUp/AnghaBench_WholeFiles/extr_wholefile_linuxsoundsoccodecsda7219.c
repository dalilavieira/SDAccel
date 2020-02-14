#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  val ;
typedef  int u8 ;
typedef  unsigned long long u64 ;
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct soc_mixer_control {unsigned int reg; } ;
struct snd_soc_dapm_widget {int reg; int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; struct device* dev; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_6__ {unsigned int* value; } ;
struct TYPE_7__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct regulator {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
struct da7219_priv {int alc_en; int micbias_on_event; int mic_pga_delay; int master; int gain_ramp_ctrl; int clk_src; unsigned int mclk_rate; int /*<<< orphan*/ * regmap; TYPE_3__* supplies; int /*<<< orphan*/ * mclk; struct da7219_pdata* pdata; int /*<<< orphan*/  pll_lock; int /*<<< orphan*/  ctrl_lock; int /*<<< orphan*/  wakeup_source; int /*<<< orphan*/ * dai_clks; } ;
struct da7219_pdata {char* dai_clks_name; int micbias_lvl; int mic_amp_in_sel; int /*<<< orphan*/  wakeup_source; } ;
typedef  int /*<<< orphan*/  offset ;
typedef  int frac_div ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
typedef  enum da7219_micbias_voltage { ____Placeholder_da7219_micbias_voltage } da7219_micbias_voltage ;
typedef  enum da7219_mic_amp_in_sel { ____Placeholder_da7219_mic_amp_in_sel } da7219_mic_amp_in_sel ;
struct TYPE_8__ {struct regulator* consumer; int /*<<< orphan*/  supply; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int const DA7219_ACCDET_CONFIG_1 ; 
#define  DA7219_ACCDET_CONFIG_8 182 
 int DA7219_ACCDET_EN_MASK ; 
#define  DA7219_ACCDET_IRQ_EVENT_A 181 
#define  DA7219_ACCDET_IRQ_EVENT_B 180 
#define  DA7219_ACCDET_STATUS_A 179 
#define  DA7219_ACCDET_STATUS_B 178 
 int DA7219_ADC_L_CTRL ; 
 int DA7219_ADC_L_EN_MASK ; 
#define  DA7219_ADC_L_GAIN_STATUS 177 
 int DA7219_ADC_L_MUTE_EN_MASK ; 
 int DA7219_ADC_L_RAMP_EN_MASK ; 
 int DA7219_ALC_AUTO_CALIB_EN_MASK ; 
 int DA7219_ALC_CALIB_OVERFLOW_MASK ; 
#define  DA7219_ALC_CTRL1 176 
#define  DA7219_ALC_OFFSET_AUTO_M_L 175 
#define  DA7219_ALC_OFFSET_AUTO_U_L 174 
 int DA7219_ALC_OFFSET_EN_MASK ; 
 int DA7219_ALC_SYNC_MODE_MASK ; 
 int DA7219_BEEP_CYCLES_MASK ; 
 int DA7219_BIAS_EN_MASK ; 
 unsigned long long DA7219_BYTE_MASK ; 
 unsigned long long DA7219_BYTE_SHIFT ; 
 unsigned int DA7219_CHIP_MINOR_MASK ; 
 int const DA7219_CHIP_REVISION ; 
#define  DA7219_CIF_CTRL 173 
 int DA7219_CIF_REG_SOFT_RESET_MASK ; 
#define  DA7219_CLKSRC_MCLK 172 
#define  DA7219_CLKSRC_MCLK_SQR 171 
 int DA7219_DAC_L_CTRL ; 
#define  DA7219_DAC_L_GAIN_STATUS 170 
 int DA7219_DAC_L_RAMP_EN_MASK ; 
 int DA7219_DAC_R_CTRL ; 
#define  DA7219_DAC_R_GAIN_STATUS 169 
 int DA7219_DAC_R_RAMP_EN_MASK ; 
 int DA7219_DAI_BCLKS_PER_WCLK_128 ; 
 int DA7219_DAI_BCLKS_PER_WCLK_256 ; 
 int DA7219_DAI_BCLKS_PER_WCLK_32 ; 
 int DA7219_DAI_BCLKS_PER_WCLK_64 ; 
 int DA7219_DAI_BCLKS_PER_WCLK_MASK ; 
 int DA7219_DAI_CH_NUM_MASK ; 
 unsigned int DA7219_DAI_CH_NUM_MAX ; 
 unsigned int DA7219_DAI_CH_NUM_SHIFT ; 
 int DA7219_DAI_CLK_EN_MASK ; 
 int DA7219_DAI_CLK_MODE ; 
 int DA7219_DAI_CLK_POL_INV ; 
 int DA7219_DAI_CLK_POL_MASK ; 
 int DA7219_DAI_CTRL ; 
 int DA7219_DAI_FORMAT_DSP ; 
 int DA7219_DAI_FORMAT_I2S ; 
 int DA7219_DAI_FORMAT_LEFT_J ; 
 int DA7219_DAI_FORMAT_MASK ; 
 int DA7219_DAI_FORMAT_RIGHT_J ; 
 int /*<<< orphan*/  DA7219_DAI_OFFSET_LOWER ; 
 unsigned int DA7219_DAI_OFFSET_MAX ; 
 unsigned int DA7219_DAI_TDM_CH_EN_MASK ; 
 unsigned int DA7219_DAI_TDM_CH_EN_SHIFT ; 
 int DA7219_DAI_TDM_CTRL ; 
 int DA7219_DAI_TDM_MAX_SLOTS ; 
 unsigned int DA7219_DAI_TDM_MODE_EN_MASK ; 
 int DA7219_DAI_WCLK_POL_INV ; 
 int DA7219_DAI_WCLK_POL_MASK ; 
 int DA7219_DAI_WORD_LENGTH_MASK ; 
 int DA7219_DAI_WORD_LENGTH_S16_LE ; 
 int DA7219_DAI_WORD_LENGTH_S20_LE ; 
 int DA7219_DAI_WORD_LENGTH_S24_LE ; 
 int DA7219_DAI_WORD_LENGTH_S32_LE ; 
 int const DA7219_GAIN_RAMP_CTRL ; 
 int DA7219_GAIN_RAMP_RATE_NOMINAL ; 
 int DA7219_HP_L_AMP_MIN_GAIN_EN_MASK ; 
 int DA7219_HP_L_AMP_RAMP_EN_MASK ; 
 int DA7219_HP_L_CTRL ; 
#define  DA7219_HP_L_GAIN_STATUS 168 
 int DA7219_HP_R_AMP_MIN_GAIN_EN_MASK ; 
 int DA7219_HP_R_AMP_RAMP_EN_MASK ; 
 int DA7219_HP_R_CTRL ; 
#define  DA7219_HP_R_GAIN_STATUS 167 
 int const DA7219_IO_CTRL ; 
 int DA7219_IO_VOLTAGE_LEVEL_1_2V_2_8V ; 
 int DA7219_IO_VOLTAGE_LEVEL_2_5V_3_6V ; 
 int DA7219_MICBIAS1_LEVEL_SHIFT ; 
#define  DA7219_MICBIAS_1_6V 166 
#define  DA7219_MICBIAS_1_8V 165 
#define  DA7219_MICBIAS_2_0V 164 
#define  DA7219_MICBIAS_2_2V 163 
#define  DA7219_MICBIAS_2_4V 162 
#define  DA7219_MICBIAS_2_6V 161 
 int const DA7219_MICBIAS_CTRL ; 
 int DA7219_MIC_1_AMP_EN_MASK ; 
 int DA7219_MIC_1_AMP_MUTE_EN_MASK ; 
 int const DA7219_MIC_1_CTRL ; 
#define  DA7219_MIC_1_GAIN_STATUS 160 
 int const DA7219_MIC_1_SELECT ; 
#define  DA7219_MIC_AMP_IN_SEL_DIFF 159 
#define  DA7219_MIC_AMP_IN_SEL_SE_N 158 
#define  DA7219_MIC_AMP_IN_SEL_SE_P 157 
 int DA7219_MIC_PGA_BASE_DELAY ; 
 int DA7219_MIC_PGA_OFFSET_DELAY ; 
 int DA7219_MIN_GAIN_DELAY ; 
 int DA7219_MIXIN_L_AMP_EN_MASK ; 
 int DA7219_MIXIN_L_AMP_MUTE_EN_MASK ; 
 int DA7219_MIXIN_L_AMP_RAMP_EN_MASK ; 
 int DA7219_MIXIN_L_CTRL ; 
#define  DA7219_MIXIN_L_GAIN_STATUS 156 
#define  DA7219_MIXOUT_L_CTRL 155 
#define  DA7219_MIXOUT_R_CTRL 154 
 int DA7219_NUM_SUPPLIES ; 
 int DA7219_PC_COUNT ; 
 int DA7219_PC_FREERUN_MASK ; 
 int DA7219_PLL_CTRL ; 
 int const DA7219_PLL_FRAC_BOT ; 
 int const DA7219_PLL_FRAC_TOP ; 
 int DA7219_PLL_INDIV_18_TO_36_MHZ ; 
 int DA7219_PLL_INDIV_18_TO_36_MHZ_VAL ; 
 int DA7219_PLL_INDIV_2_TO_4_5_MHZ ; 
 int DA7219_PLL_INDIV_2_TO_4_5_MHZ_VAL ; 
 int DA7219_PLL_INDIV_36_TO_54_MHZ ; 
 int DA7219_PLL_INDIV_36_TO_54_MHZ_VAL ; 
 int DA7219_PLL_INDIV_4_5_TO_9_MHZ ; 
 int DA7219_PLL_INDIV_4_5_TO_9_MHZ_VAL ; 
 int DA7219_PLL_INDIV_9_TO_18_MHZ ; 
 int DA7219_PLL_INDIV_9_TO_18_MHZ_VAL ; 
 int DA7219_PLL_INDIV_MASK ; 
 int const DA7219_PLL_INTEGER ; 
 int DA7219_PLL_MCLK_SQR_EN_MASK ; 
 int DA7219_PLL_MODE_BYPASS ; 
 int DA7219_PLL_MODE_MASK ; 
 int DA7219_PLL_MODE_NORMAL ; 
 int DA7219_PLL_MODE_SRM ; 
#define  DA7219_PLL_SRM_STS 153 
 int DA7219_PLL_SRM_STS_SRM_LOCK ; 
 int DA7219_REFERENCES ; 
 int DA7219_SETTLING_DELAY ; 
 int const DA7219_SR ; 
 int DA7219_SRM_CHECK_RETRIES ; 
 int DA7219_SR_11025 ; 
 int DA7219_SR_12000 ; 
 int DA7219_SR_16000 ; 
 int DA7219_SR_22050 ; 
 int DA7219_SR_24000 ; 
 int DA7219_SR_32000 ; 
 int DA7219_SR_44100 ; 
 int DA7219_SR_48000 ; 
 int DA7219_SR_8000 ; 
 int DA7219_SR_88200 ; 
 int DA7219_SR_96000 ; 
 size_t DA7219_SUPPLY_VDDIO ; 
#define  DA7219_SYSCLK_MCLK 152 
#define  DA7219_SYSCLK_PLL 151 
#define  DA7219_SYSCLK_PLL_SRM 150 
 int const DA7219_SYSTEM_ACTIVE ; 
 int DA7219_SYSTEM_ACTIVE_MASK ; 
#define  DA7219_SYSTEM_MODES_INPUT 149 
#define  DA7219_SYSTEM_MODES_OUTPUT 148 
#define  DA7219_SYSTEM_STATUS 147 
 int DA7219_SYS_STAT_CHECK_DELAY ; 
 int DA7219_SYS_STAT_CHECK_RETRIES ; 
#define  DA7219_TONE_GEN_CFG1 146 
 int const DA7219_TONE_GEN_CYCLES ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
#define  SND_SOC_BIAS_OFF 145 
#define  SND_SOC_BIAS_ON 144 
#define  SND_SOC_BIAS_PREPARE 143 
#define  SND_SOC_BIAS_STANDBY 142 
#define  SND_SOC_DAIFMT_CBM_CFM 141 
#define  SND_SOC_DAIFMT_CBS_CFS 140 
#define  SND_SOC_DAIFMT_DSP_B 139 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 138 
#define  SND_SOC_DAIFMT_IB_IF 137 
#define  SND_SOC_DAIFMT_IB_NF 136 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 135 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 134 
#define  SND_SOC_DAIFMT_NB_NF 133 
#define  SND_SOC_DAIFMT_RIGHT_J 132 
#define  SND_SOC_DAPM_POST_PMD 131 
#define  SND_SOC_DAPM_POST_PMU 130 
#define  SND_SOC_DAPM_PRE_PMD 129 
#define  SND_SOC_DAPM_PRE_PMU 128 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ *) ; 
 int clk_prepare_enable (int /*<<< orphan*/ *) ; 
 unsigned int clk_round_rate (int /*<<< orphan*/ *,unsigned int) ; 
 int clk_set_rate (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  cpu_to_le16 (unsigned int) ; 
 int /*<<< orphan*/  da7219_aad_exit (struct snd_soc_component*) ; 
 int da7219_aad_init (struct snd_soc_component*) ; 
 int /*<<< orphan*/  da7219_dai ; 
 int /*<<< orphan*/  da7219_regmap_config ; 
 int /*<<< orphan*/  da7219_rev_aa_patch ; 
 int /*<<< orphan*/ * da7219_supply_names ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct da7219_pdata* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int /*<<< orphan*/  device_property_read_bool (struct device*,char*) ; 
 scalar_t__ device_property_read_string (struct device*,char*,char const**) ; 
 scalar_t__ device_property_read_u32 (struct device*,char*,unsigned int*) ; 
 int /*<<< orphan*/ * devm_clk_get (struct device*,char*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_3__*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  do_div (unsigned long long,unsigned int) ; 
 int fls (unsigned int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct da7219_priv*) ; 
 unsigned int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned int params_channels (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_cache_bypass (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  regmap_bulk_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int regmap_raw_read (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ *,int) ; 
 int regmap_raw_write (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ *,int) ; 
 int regmap_read (int /*<<< orphan*/ *,int const,unsigned int*) ; 
 int regmap_register_patch (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ *,int const,int) ; 
 int /*<<< orphan*/  regmap_write_bits (int /*<<< orphan*/ *,int const,int,int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_3__*) ; 
 int regulator_bulk_enable (int,TYPE_3__*) ; 
 int regulator_get_voltage (struct regulator*) ; 
 int const snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct da7219_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 void* snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int const,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int snd_soc_get_enum_double (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int snd_soc_get_volsw (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_put_enum_double (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int snd_soc_put_volsw (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int /*<<< orphan*/  soc_component_dev_da7219 ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static int da7219_volsw_locked_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	mutex_lock(&da7219->ctrl_lock);
	ret = snd_soc_get_volsw(kcontrol, ucontrol);
	mutex_unlock(&da7219->ctrl_lock);

	return ret;
}

__attribute__((used)) static int da7219_volsw_locked_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	mutex_lock(&da7219->ctrl_lock);
	ret = snd_soc_put_volsw(kcontrol, ucontrol);
	mutex_unlock(&da7219->ctrl_lock);

	return ret;
}

__attribute__((used)) static int da7219_enum_locked_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	mutex_lock(&da7219->ctrl_lock);
	ret = snd_soc_get_enum_double(kcontrol, ucontrol);
	mutex_unlock(&da7219->ctrl_lock);

	return ret;
}

__attribute__((used)) static int da7219_enum_locked_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	mutex_lock(&da7219->ctrl_lock);
	ret = snd_soc_put_enum_double(kcontrol, ucontrol);
	mutex_unlock(&da7219->ctrl_lock);

	return ret;
}

__attribute__((used)) static void da7219_alc_calib(struct snd_soc_component *component)
{
	u8 mic_ctrl, mixin_ctrl, adc_ctrl, calib_ctrl;

	/* Save current state of mic control register */
	mic_ctrl = snd_soc_component_read32(component, DA7219_MIC_1_CTRL);

	/* Save current state of input mixer control register */
	mixin_ctrl = snd_soc_component_read32(component, DA7219_MIXIN_L_CTRL);

	/* Save current state of input ADC control register */
	adc_ctrl = snd_soc_component_read32(component, DA7219_ADC_L_CTRL);

	/* Enable then Mute MIC PGAs */
	snd_soc_component_update_bits(component, DA7219_MIC_1_CTRL, DA7219_MIC_1_AMP_EN_MASK,
			    DA7219_MIC_1_AMP_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_MIC_1_CTRL,
			    DA7219_MIC_1_AMP_MUTE_EN_MASK,
			    DA7219_MIC_1_AMP_MUTE_EN_MASK);

	/* Enable input mixers unmuted */
	snd_soc_component_update_bits(component, DA7219_MIXIN_L_CTRL,
			    DA7219_MIXIN_L_AMP_EN_MASK |
			    DA7219_MIXIN_L_AMP_MUTE_EN_MASK,
			    DA7219_MIXIN_L_AMP_EN_MASK);

	/* Enable input filters unmuted */
	snd_soc_component_update_bits(component, DA7219_ADC_L_CTRL,
			    DA7219_ADC_L_MUTE_EN_MASK | DA7219_ADC_L_EN_MASK,
			    DA7219_ADC_L_EN_MASK);

	/* Perform auto calibration */
	snd_soc_component_update_bits(component, DA7219_ALC_CTRL1,
			    DA7219_ALC_AUTO_CALIB_EN_MASK,
			    DA7219_ALC_AUTO_CALIB_EN_MASK);
	do {
		calib_ctrl = snd_soc_component_read32(component, DA7219_ALC_CTRL1);
	} while (calib_ctrl & DA7219_ALC_AUTO_CALIB_EN_MASK);

	/* If auto calibration fails, disable DC offset, hybrid ALC */
	if (calib_ctrl & DA7219_ALC_CALIB_OVERFLOW_MASK) {
		dev_warn(component->dev,
			 "ALC auto calibration failed with overflow\n");
		snd_soc_component_update_bits(component, DA7219_ALC_CTRL1,
				    DA7219_ALC_OFFSET_EN_MASK |
				    DA7219_ALC_SYNC_MODE_MASK, 0);
	} else {
		/* Enable DC offset cancellation, hybrid mode */
		snd_soc_component_update_bits(component, DA7219_ALC_CTRL1,
				    DA7219_ALC_OFFSET_EN_MASK |
				    DA7219_ALC_SYNC_MODE_MASK,
				    DA7219_ALC_OFFSET_EN_MASK |
				    DA7219_ALC_SYNC_MODE_MASK);
	}

	/* Restore input filter control register to original state */
	snd_soc_component_write(component, DA7219_ADC_L_CTRL, adc_ctrl);

	/* Restore input mixer control registers to original state */
	snd_soc_component_write(component, DA7219_MIXIN_L_CTRL, mixin_ctrl);

	/* Restore MIC control registers to original states */
	snd_soc_component_write(component, DA7219_MIC_1_CTRL, mic_ctrl);
}

__attribute__((used)) static int da7219_mixin_gain_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	ret = snd_soc_put_volsw(kcontrol, ucontrol);

	/*
	 * If ALC in operation and value of control has been updated,
	 * make sure calibrated offsets are updated.
	 */
	if ((ret == 1) && (da7219->alc_en))
		da7219_alc_calib(component);

	return ret;
}

__attribute__((used)) static int da7219_alc_sw_put(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);


	/* Force ALC offset calibration if enabling ALC */
	if ((ucontrol->value.integer.value[0]) && (!da7219->alc_en)) {
		da7219_alc_calib(component);
		da7219->alc_en = true;
	} else {
		da7219->alc_en = false;
	}

	return snd_soc_put_volsw(kcontrol, ucontrol);
}

__attribute__((used)) static int da7219_tonegen_freq_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	struct soc_mixer_control *mixer_ctrl =
		(struct soc_mixer_control *) kcontrol->private_value;
	unsigned int reg = mixer_ctrl->reg;
	u16 val;
	int ret;

	mutex_lock(&da7219->ctrl_lock);
	ret = regmap_raw_read(da7219->regmap, reg, &val, sizeof(val));
	mutex_unlock(&da7219->ctrl_lock);

	if (ret)
		return ret;

	/*
	 * Frequency value spans two 8-bit registers, lower then upper byte.
	 * Therefore we need to convert to host endianness here.
	 */
	ucontrol->value.integer.value[0] = le16_to_cpu(val);

	return 0;
}

__attribute__((used)) static int da7219_tonegen_freq_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	struct soc_mixer_control *mixer_ctrl =
		(struct soc_mixer_control *) kcontrol->private_value;
	unsigned int reg = mixer_ctrl->reg;
	u16 val;
	int ret;

	/*
	 * Frequency value spans two 8-bit registers, lower then upper byte.
	 * Therefore we need to convert to little endian here to align with
	 * HW registers.
	 */
	val = cpu_to_le16(ucontrol->value.integer.value[0]);

	mutex_lock(&da7219->ctrl_lock);
	ret = regmap_raw_write(da7219->regmap, reg, &val, sizeof(val));
	mutex_unlock(&da7219->ctrl_lock);

	return ret;
}

__attribute__((used)) static int da7219_mic_pga_event(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		if (da7219->micbias_on_event) {
			/*
			 * Delay only for first capture after bias enabled to
			 * avoid possible DC offset related noise.
			 */
			da7219->micbias_on_event = false;
			msleep(da7219->mic_pga_delay);
		}
		break;
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int da7219_dai_event(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	u8 pll_ctrl, pll_status;
	int i = 0, ret;
	bool srm_lock = false;

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		if (da7219->master) {
			/* Enable DAI clks for master mode */
			if (da7219->dai_clks) {
				ret = clk_prepare_enable(da7219->dai_clks);
				if (ret) {
					dev_err(component->dev,
						"Failed to enable dai_clks\n");
					return ret;
				}
			} else {
				snd_soc_component_update_bits(component,
							      DA7219_DAI_CLK_MODE,
							      DA7219_DAI_CLK_EN_MASK,
							      DA7219_DAI_CLK_EN_MASK);
			}
		}

		/* PC synchronised to DAI */
		snd_soc_component_update_bits(component, DA7219_PC_COUNT,
				    DA7219_PC_FREERUN_MASK, 0);

		/* Slave mode, if SRM not enabled no need for status checks */
		pll_ctrl = snd_soc_component_read32(component, DA7219_PLL_CTRL);
		if ((pll_ctrl & DA7219_PLL_MODE_MASK) != DA7219_PLL_MODE_SRM)
			return 0;

		/* Check SRM has locked */
		do {
			pll_status = snd_soc_component_read32(component, DA7219_PLL_SRM_STS);
			if (pll_status & DA7219_PLL_SRM_STS_SRM_LOCK) {
				srm_lock = true;
			} else {
				++i;
				msleep(50);
			}
		} while ((i < DA7219_SRM_CHECK_RETRIES) & (!srm_lock));

		if (!srm_lock)
			dev_warn(component->dev, "SRM failed to lock\n");

		return 0;
	case SND_SOC_DAPM_POST_PMD:
		/* PC free-running */
		snd_soc_component_update_bits(component, DA7219_PC_COUNT,
				    DA7219_PC_FREERUN_MASK,
				    DA7219_PC_FREERUN_MASK);

		/* Disable DAI clks if in master mode */
		if (da7219->master) {
			if (da7219->dai_clks)
				clk_disable_unprepare(da7219->dai_clks);
			else
				snd_soc_component_update_bits(component,
							      DA7219_DAI_CLK_MODE,
							      DA7219_DAI_CLK_EN_MASK,
							      0);
		}

		return 0;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int da7219_settling_event(struct snd_soc_dapm_widget *w,
				 struct snd_kcontrol *kcontrol, int event)
{
	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
	case SND_SOC_DAPM_POST_PMD:
		msleep(DA7219_SETTLING_DELAY);
		break;
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int da7219_mixout_event(struct snd_soc_dapm_widget *w,
			       struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	u8 hp_ctrl, min_gain_mask;

	switch (w->reg) {
	case DA7219_MIXOUT_L_CTRL:
		hp_ctrl = DA7219_HP_L_CTRL;
		min_gain_mask = DA7219_HP_L_AMP_MIN_GAIN_EN_MASK;
		break;
	case DA7219_MIXOUT_R_CTRL:
		hp_ctrl = DA7219_HP_R_CTRL;
		min_gain_mask = DA7219_HP_R_AMP_MIN_GAIN_EN_MASK;
		break;
	default:
		return -EINVAL;
	}

	switch (event) {
	case SND_SOC_DAPM_PRE_PMD:
		/* Enable minimum gain on HP to avoid pops */
		snd_soc_component_update_bits(component, hp_ctrl, min_gain_mask,
				    min_gain_mask);

		msleep(DA7219_MIN_GAIN_DELAY);

		break;
	case SND_SOC_DAPM_POST_PMU:
		/* Remove minimum gain on HP */
		snd_soc_component_update_bits(component, hp_ctrl, min_gain_mask, 0);

		break;
	}

	return 0;
}

__attribute__((used)) static int da7219_gain_ramp_event(struct snd_soc_dapm_widget *w,
				  struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
	case SND_SOC_DAPM_PRE_PMD:
		/* Ensure nominal gain ramping for DAPM sequence */
		da7219->gain_ramp_ctrl =
			snd_soc_component_read32(component, DA7219_GAIN_RAMP_CTRL);
		snd_soc_component_write(component, DA7219_GAIN_RAMP_CTRL,
			      DA7219_GAIN_RAMP_RATE_NOMINAL);
		break;
	case SND_SOC_DAPM_POST_PMU:
	case SND_SOC_DAPM_POST_PMD:
		/* Restore previous gain ramp settings */
		snd_soc_component_write(component, DA7219_GAIN_RAMP_CTRL,
			      da7219->gain_ramp_ctrl);
		break;
	}

	return 0;
}

__attribute__((used)) static int da7219_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret = 0;

	if ((da7219->clk_src == clk_id) && (da7219->mclk_rate == freq))
		return 0;

	if ((freq < 2000000) || (freq > 54000000)) {
		dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
			freq);
		return -EINVAL;
	}

	mutex_lock(&da7219->pll_lock);

	switch (clk_id) {
	case DA7219_CLKSRC_MCLK_SQR:
		snd_soc_component_update_bits(component, DA7219_PLL_CTRL,
				    DA7219_PLL_MCLK_SQR_EN_MASK,
				    DA7219_PLL_MCLK_SQR_EN_MASK);
		break;
	case DA7219_CLKSRC_MCLK:
		snd_soc_component_update_bits(component, DA7219_PLL_CTRL,
				    DA7219_PLL_MCLK_SQR_EN_MASK, 0);
		break;
	default:
		dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
		mutex_unlock(&da7219->pll_lock);
		return -EINVAL;
	}

	da7219->clk_src = clk_id;

	if (da7219->mclk) {
		freq = clk_round_rate(da7219->mclk, freq);
		ret = clk_set_rate(da7219->mclk, freq);
		if (ret) {
			dev_err(codec_dai->dev, "Failed to set clock rate %d\n",
				freq);
			mutex_unlock(&da7219->pll_lock);
			return ret;
		}
	}

	da7219->mclk_rate = freq;

	mutex_unlock(&da7219->pll_lock);

	return 0;
}

int da7219_set_pll(struct snd_soc_component *component, int source, unsigned int fout)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);

	u8 pll_ctrl, indiv_bits, indiv;
	u8 pll_frac_top, pll_frac_bot, pll_integer;
	u32 freq_ref;
	u64 frac_div;

	/* Verify 2MHz - 54MHz MCLK provided, and set input divider */
	if (da7219->mclk_rate < 2000000) {
		dev_err(component->dev, "PLL input clock %d below valid range\n",
			da7219->mclk_rate);
		return -EINVAL;
	} else if (da7219->mclk_rate <= 4500000) {
		indiv_bits = DA7219_PLL_INDIV_2_TO_4_5_MHZ;
		indiv = DA7219_PLL_INDIV_2_TO_4_5_MHZ_VAL;
	} else if (da7219->mclk_rate <= 9000000) {
		indiv_bits = DA7219_PLL_INDIV_4_5_TO_9_MHZ;
		indiv = DA7219_PLL_INDIV_4_5_TO_9_MHZ_VAL;
	} else if (da7219->mclk_rate <= 18000000) {
		indiv_bits = DA7219_PLL_INDIV_9_TO_18_MHZ;
		indiv = DA7219_PLL_INDIV_9_TO_18_MHZ_VAL;
	} else if (da7219->mclk_rate <= 36000000) {
		indiv_bits = DA7219_PLL_INDIV_18_TO_36_MHZ;
		indiv = DA7219_PLL_INDIV_18_TO_36_MHZ_VAL;
	} else if (da7219->mclk_rate <= 54000000) {
		indiv_bits = DA7219_PLL_INDIV_36_TO_54_MHZ;
		indiv = DA7219_PLL_INDIV_36_TO_54_MHZ_VAL;
	} else {
		dev_err(component->dev, "PLL input clock %d above valid range\n",
			da7219->mclk_rate);
		return -EINVAL;
	}
	freq_ref = (da7219->mclk_rate / indiv);
	pll_ctrl = indiv_bits;

	/* Configure PLL */
	switch (source) {
	case DA7219_SYSCLK_MCLK:
		pll_ctrl |= DA7219_PLL_MODE_BYPASS;
		snd_soc_component_update_bits(component, DA7219_PLL_CTRL,
				    DA7219_PLL_INDIV_MASK |
				    DA7219_PLL_MODE_MASK, pll_ctrl);
		return 0;
	case DA7219_SYSCLK_PLL:
		pll_ctrl |= DA7219_PLL_MODE_NORMAL;
		break;
	case DA7219_SYSCLK_PLL_SRM:
		pll_ctrl |= DA7219_PLL_MODE_SRM;
		break;
	default:
		dev_err(component->dev, "Invalid PLL config\n");
		return -EINVAL;
	}

	/* Calculate dividers for PLL */
	pll_integer = fout / freq_ref;
	frac_div = (u64)(fout % freq_ref) * 8192ULL;
	do_div(frac_div, freq_ref);
	pll_frac_top = (frac_div >> DA7219_BYTE_SHIFT) & DA7219_BYTE_MASK;
	pll_frac_bot = (frac_div) & DA7219_BYTE_MASK;

	/* Write PLL config & dividers */
	snd_soc_component_write(component, DA7219_PLL_FRAC_TOP, pll_frac_top);
	snd_soc_component_write(component, DA7219_PLL_FRAC_BOT, pll_frac_bot);
	snd_soc_component_write(component, DA7219_PLL_INTEGER, pll_integer);
	snd_soc_component_update_bits(component, DA7219_PLL_CTRL,
			    DA7219_PLL_INDIV_MASK | DA7219_PLL_MODE_MASK,
			    pll_ctrl);

	return 0;
}

__attribute__((used)) static int da7219_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
			      int source, unsigned int fref, unsigned int fout)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	mutex_lock(&da7219->pll_lock);
	ret = da7219_set_pll(component, source, fout);
	mutex_unlock(&da7219->pll_lock);

	return ret;
}

__attribute__((used)) static int da7219_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	u8 dai_clk_mode = 0, dai_ctrl = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		da7219->master = true;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		da7219->master = false;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			break;
		case SND_SOC_DAIFMT_NB_IF:
			dai_clk_mode |= DA7219_DAI_WCLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			dai_clk_mode |= DA7219_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_IF:
			dai_clk_mode |= DA7219_DAI_WCLK_POL_INV |
					DA7219_DAI_CLK_POL_INV;
			break;
		default:
			return -EINVAL;
		}
		break;
	case SND_SOC_DAIFMT_DSP_B:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			dai_clk_mode |= DA7219_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_NB_IF:
			dai_clk_mode |= DA7219_DAI_WCLK_POL_INV |
					DA7219_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			break;
		case SND_SOC_DAIFMT_IB_IF:
			dai_clk_mode |= DA7219_DAI_WCLK_POL_INV;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		dai_ctrl |= DA7219_DAI_FORMAT_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		dai_ctrl |= DA7219_DAI_FORMAT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		dai_ctrl |= DA7219_DAI_FORMAT_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		dai_ctrl |= DA7219_DAI_FORMAT_DSP;
		break;
	default:
		return -EINVAL;
	}

	/* By default 64 BCLKs per WCLK is supported */
	dai_clk_mode |= DA7219_DAI_BCLKS_PER_WCLK_64;

	snd_soc_component_update_bits(component, DA7219_DAI_CLK_MODE,
			    DA7219_DAI_BCLKS_PER_WCLK_MASK |
			    DA7219_DAI_CLK_POL_MASK | DA7219_DAI_WCLK_POL_MASK,
			    dai_clk_mode);
	snd_soc_component_update_bits(component, DA7219_DAI_CTRL, DA7219_DAI_FORMAT_MASK,
			    dai_ctrl);

	return 0;
}

__attribute__((used)) static int da7219_set_dai_tdm_slot(struct snd_soc_dai *dai,
				   unsigned int tx_mask, unsigned int rx_mask,
				   int slots, int slot_width)
{
	struct snd_soc_component *component = dai->component;
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	u8 dai_bclks_per_wclk;
	u16 offset;
	u32 frame_size;

	/* No channels enabled so disable TDM, revert to 64-bit frames */
	if (!tx_mask) {
		snd_soc_component_update_bits(component, DA7219_DAI_TDM_CTRL,
				    DA7219_DAI_TDM_CH_EN_MASK |
				    DA7219_DAI_TDM_MODE_EN_MASK, 0);
		snd_soc_component_update_bits(component, DA7219_DAI_CLK_MODE,
				    DA7219_DAI_BCLKS_PER_WCLK_MASK,
				    DA7219_DAI_BCLKS_PER_WCLK_64);
		return 0;
	}

	/* Check we have valid slots */
	if (fls(tx_mask) > DA7219_DAI_TDM_MAX_SLOTS) {
		dev_err(component->dev, "Invalid number of slots, max = %d\n",
			DA7219_DAI_TDM_MAX_SLOTS);
		return -EINVAL;
	}

	/* Check we have a valid offset given */
	if (rx_mask > DA7219_DAI_OFFSET_MAX) {
		dev_err(component->dev, "Invalid slot offset, max = %d\n",
			DA7219_DAI_OFFSET_MAX);
		return -EINVAL;
	}

	/* Calculate & validate frame size based on slot info provided. */
	frame_size = slots * slot_width;
	switch (frame_size) {
	case 32:
		dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_32;
		break;
	case 64:
		dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_64;
		break;
	case 128:
		dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_128;
		break;
	case 256:
		dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_256;
		break;
	default:
		dev_err(component->dev, "Invalid frame size %d\n", frame_size);
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, DA7219_DAI_CLK_MODE,
			    DA7219_DAI_BCLKS_PER_WCLK_MASK,
			    dai_bclks_per_wclk);

	offset = cpu_to_le16(rx_mask);
	regmap_bulk_write(da7219->regmap, DA7219_DAI_OFFSET_LOWER,
			  &offset, sizeof(offset));

	snd_soc_component_update_bits(component, DA7219_DAI_TDM_CTRL,
			    DA7219_DAI_TDM_CH_EN_MASK |
			    DA7219_DAI_TDM_MODE_EN_MASK,
			    (tx_mask << DA7219_DAI_TDM_CH_EN_SHIFT) |
			    DA7219_DAI_TDM_MODE_EN_MASK);

	return 0;
}

__attribute__((used)) static int da7219_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	u8 dai_ctrl = 0, fs;
	unsigned int channels;

	switch (params_width(params)) {
	case 16:
		dai_ctrl |= DA7219_DAI_WORD_LENGTH_S16_LE;
		break;
	case 20:
		dai_ctrl |= DA7219_DAI_WORD_LENGTH_S20_LE;
		break;
	case 24:
		dai_ctrl |= DA7219_DAI_WORD_LENGTH_S24_LE;
		break;
	case 32:
		dai_ctrl |= DA7219_DAI_WORD_LENGTH_S32_LE;
		break;
	default:
		return -EINVAL;
	}

	channels = params_channels(params);
	if ((channels < 1) || (channels > DA7219_DAI_CH_NUM_MAX)) {
		dev_err(component->dev,
			"Invalid number of channels, only 1 to %d supported\n",
			DA7219_DAI_CH_NUM_MAX);
		return -EINVAL;
	}
	dai_ctrl |= channels << DA7219_DAI_CH_NUM_SHIFT;

	switch (params_rate(params)) {
	case 8000:
		fs = DA7219_SR_8000;
		break;
	case 11025:
		fs = DA7219_SR_11025;
		break;
	case 12000:
		fs = DA7219_SR_12000;
		break;
	case 16000:
		fs = DA7219_SR_16000;
		break;
	case 22050:
		fs = DA7219_SR_22050;
		break;
	case 24000:
		fs = DA7219_SR_24000;
		break;
	case 32000:
		fs = DA7219_SR_32000;
		break;
	case 44100:
		fs = DA7219_SR_44100;
		break;
	case 48000:
		fs = DA7219_SR_48000;
		break;
	case 88200:
		fs = DA7219_SR_88200;
		break;
	case 96000:
		fs = DA7219_SR_96000;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, DA7219_DAI_CTRL,
			    DA7219_DAI_WORD_LENGTH_MASK |
			    DA7219_DAI_CH_NUM_MASK,
			    dai_ctrl);
	snd_soc_component_write(component, DA7219_SR, fs);

	return 0;
}

__attribute__((used)) static enum da7219_micbias_voltage
	da7219_fw_micbias_lvl(struct device *dev, u32 val)
{
	switch (val) {
	case 1600:
		return DA7219_MICBIAS_1_6V;
	case 1800:
		return DA7219_MICBIAS_1_8V;
	case 2000:
		return DA7219_MICBIAS_2_0V;
	case 2200:
		return DA7219_MICBIAS_2_2V;
	case 2400:
		return DA7219_MICBIAS_2_4V;
	case 2600:
		return DA7219_MICBIAS_2_6V;
	default:
		dev_warn(dev, "Invalid micbias level");
		return DA7219_MICBIAS_2_2V;
	}
}

__attribute__((used)) static enum da7219_mic_amp_in_sel
	da7219_fw_mic_amp_in_sel(struct device *dev, const char *str)
{
	if (!strcmp(str, "diff")) {
		return DA7219_MIC_AMP_IN_SEL_DIFF;
	} else if (!strcmp(str, "se_p")) {
		return DA7219_MIC_AMP_IN_SEL_SE_P;
	} else if (!strcmp(str, "se_n")) {
		return DA7219_MIC_AMP_IN_SEL_SE_N;
	} else {
		dev_warn(dev, "Invalid mic input type selection");
		return DA7219_MIC_AMP_IN_SEL_DIFF;
	}
}

__attribute__((used)) static struct da7219_pdata *da7219_fw_to_pdata(struct snd_soc_component *component)
{
	struct device *dev = component->dev;
	struct da7219_pdata *pdata;
	const char *of_str;
	u32 of_val32;

	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;

	pdata->wakeup_source = device_property_read_bool(dev, "wakeup-source");

	pdata->dai_clks_name = "da7219-dai-clks";
	if (device_property_read_string(dev, "clock-output-names",
					&pdata->dai_clks_name))
		dev_warn(dev, "Using default clk name: %s\n",
			 pdata->dai_clks_name);

	if (device_property_read_u32(dev, "dlg,micbias-lvl", &of_val32) >= 0)
		pdata->micbias_lvl = da7219_fw_micbias_lvl(dev, of_val32);
	else
		pdata->micbias_lvl = DA7219_MICBIAS_2_2V;

	if (!device_property_read_string(dev, "dlg,mic-amp-in-sel", &of_str))
		pdata->mic_amp_in_sel = da7219_fw_mic_amp_in_sel(dev, of_str);
	else
		pdata->mic_amp_in_sel = DA7219_MIC_AMP_IN_SEL_DIFF;

	return pdata;
}

__attribute__((used)) static int da7219_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		/* Enable MCLK for transition to ON state */
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_STANDBY) {
			if (da7219->mclk) {
				ret = clk_prepare_enable(da7219->mclk);
				if (ret) {
					dev_err(component->dev,
						"Failed to enable mclk\n");
					return ret;
				}
			}
		}

		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF)
			/* Master bias */
			snd_soc_component_update_bits(component, DA7219_REFERENCES,
					    DA7219_BIAS_EN_MASK,
					    DA7219_BIAS_EN_MASK);

		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_PREPARE) {
			/* Remove MCLK */
			if (da7219->mclk)
				clk_disable_unprepare(da7219->mclk);
		}
		break;
	case SND_SOC_BIAS_OFF:
		/* Only disable master bias if we're not a wake-up source */
		if (!da7219->wakeup_source)
			snd_soc_component_update_bits(component, DA7219_REFERENCES,
					    DA7219_BIAS_EN_MASK, 0);

		break;
	}

	return 0;
}

__attribute__((used)) static int da7219_handle_supplies(struct snd_soc_component *component)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	struct regulator *vddio;
	u8 io_voltage_lvl = DA7219_IO_VOLTAGE_LEVEL_2_5V_3_6V;
	int i, ret;

	/* Get required supplies */
	for (i = 0; i < DA7219_NUM_SUPPLIES; ++i)
		da7219->supplies[i].supply = da7219_supply_names[i];

	ret = devm_regulator_bulk_get(component->dev, DA7219_NUM_SUPPLIES,
				      da7219->supplies);
	if (ret) {
		dev_err(component->dev, "Failed to get supplies");
		return ret;
	}

	/* Determine VDDIO voltage provided */
	vddio = da7219->supplies[DA7219_SUPPLY_VDDIO].consumer;
	ret = regulator_get_voltage(vddio);
	if (ret < 1200000)
		dev_warn(component->dev, "Invalid VDDIO voltage\n");
	else if (ret < 2800000)
		io_voltage_lvl = DA7219_IO_VOLTAGE_LEVEL_1_2V_2_8V;

	/* Enable main supplies */
	ret = regulator_bulk_enable(DA7219_NUM_SUPPLIES, da7219->supplies);
	if (ret) {
		dev_err(component->dev, "Failed to enable supplies");
		return ret;
	}

	/* Ensure device in active mode */
	snd_soc_component_write(component, DA7219_SYSTEM_ACTIVE, DA7219_SYSTEM_ACTIVE_MASK);

	/* Update IO voltage level range */
	snd_soc_component_write(component, DA7219_IO_CTRL, io_voltage_lvl);

	return 0;
}

__attribute__((used)) static inline void da7219_register_dai_clks(struct snd_soc_component *component) {}

__attribute__((used)) static void da7219_handle_pdata(struct snd_soc_component *component)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	struct da7219_pdata *pdata = da7219->pdata;

	if (pdata) {
		u8 micbias_lvl = 0;

		da7219->wakeup_source = pdata->wakeup_source;

		da7219_register_dai_clks(component);

		/* Mic Bias voltages */
		switch (pdata->micbias_lvl) {
		case DA7219_MICBIAS_1_6V:
		case DA7219_MICBIAS_1_8V:
		case DA7219_MICBIAS_2_0V:
		case DA7219_MICBIAS_2_2V:
		case DA7219_MICBIAS_2_4V:
		case DA7219_MICBIAS_2_6V:
			micbias_lvl |= (pdata->micbias_lvl <<
					DA7219_MICBIAS1_LEVEL_SHIFT);
			break;
		}

		snd_soc_component_write(component, DA7219_MICBIAS_CTRL, micbias_lvl);

		/*
		 * Calculate delay required to compensate for DC offset in
		 * Mic PGA, based on Mic Bias voltage.
		 */
		da7219->mic_pga_delay =  DA7219_MIC_PGA_BASE_DELAY +
					(pdata->micbias_lvl *
					 DA7219_MIC_PGA_OFFSET_DELAY);

		/* Mic */
		switch (pdata->mic_amp_in_sel) {
		case DA7219_MIC_AMP_IN_SEL_DIFF:
		case DA7219_MIC_AMP_IN_SEL_SE_P:
		case DA7219_MIC_AMP_IN_SEL_SE_N:
			snd_soc_component_write(component, DA7219_MIC_1_SELECT,
				      pdata->mic_amp_in_sel);
			break;
		}
	}
}

__attribute__((used)) static int da7219_probe(struct snd_soc_component *component)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	unsigned int rev;
	int ret;

	mutex_init(&da7219->ctrl_lock);
	mutex_init(&da7219->pll_lock);

	/* Regulator configuration */
	ret = da7219_handle_supplies(component);
	if (ret)
		return ret;

	ret = regmap_read(da7219->regmap, DA7219_CHIP_REVISION, &rev);
	if (ret) {
		dev_err(component->dev, "Failed to read chip revision: %d\n", ret);
		goto err_disable_reg;
	}

	switch (rev & DA7219_CHIP_MINOR_MASK) {
	case 0:
		ret = regmap_register_patch(da7219->regmap, da7219_rev_aa_patch,
					    ARRAY_SIZE(da7219_rev_aa_patch));
		if (ret) {
			dev_err(component->dev, "Failed to register AA patch: %d\n",
				ret);
			goto err_disable_reg;
		}
		break;
	default:
		break;
	}

	/* Handle DT/ACPI/Platform data */
	da7219->pdata = dev_get_platdata(component->dev);
	if (!da7219->pdata)
		da7219->pdata = da7219_fw_to_pdata(component);

	da7219_handle_pdata(component);

	/* Check if MCLK provided */
	da7219->mclk = devm_clk_get(component->dev, "mclk");
	if (IS_ERR(da7219->mclk)) {
		if (PTR_ERR(da7219->mclk) != -ENOENT) {
			ret = PTR_ERR(da7219->mclk);
			goto err_disable_reg;
		} else {
			da7219->mclk = NULL;
		}
	}

	/* Default PC counter to free-running */
	snd_soc_component_update_bits(component, DA7219_PC_COUNT, DA7219_PC_FREERUN_MASK,
			    DA7219_PC_FREERUN_MASK);

	/* Default gain ramping */
	snd_soc_component_update_bits(component, DA7219_MIXIN_L_CTRL,
			    DA7219_MIXIN_L_AMP_RAMP_EN_MASK,
			    DA7219_MIXIN_L_AMP_RAMP_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_ADC_L_CTRL, DA7219_ADC_L_RAMP_EN_MASK,
			    DA7219_ADC_L_RAMP_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_DAC_L_CTRL, DA7219_DAC_L_RAMP_EN_MASK,
			    DA7219_DAC_L_RAMP_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_DAC_R_CTRL, DA7219_DAC_R_RAMP_EN_MASK,
			    DA7219_DAC_R_RAMP_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_HP_L_CTRL,
			    DA7219_HP_L_AMP_RAMP_EN_MASK,
			    DA7219_HP_L_AMP_RAMP_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_HP_R_CTRL,
			    DA7219_HP_R_AMP_RAMP_EN_MASK,
			    DA7219_HP_R_AMP_RAMP_EN_MASK);

	/* Default minimum gain on HP to avoid pops during DAPM sequencing */
	snd_soc_component_update_bits(component, DA7219_HP_L_CTRL,
			    DA7219_HP_L_AMP_MIN_GAIN_EN_MASK,
			    DA7219_HP_L_AMP_MIN_GAIN_EN_MASK);
	snd_soc_component_update_bits(component, DA7219_HP_R_CTRL,
			    DA7219_HP_R_AMP_MIN_GAIN_EN_MASK,
			    DA7219_HP_R_AMP_MIN_GAIN_EN_MASK);

	/* Default infinite tone gen, start/stop by Kcontrol */
	snd_soc_component_write(component, DA7219_TONE_GEN_CYCLES, DA7219_BEEP_CYCLES_MASK);

	/* Initialise AAD block */
	ret = da7219_aad_init(component);
	if (ret)
		goto err_disable_reg;

	return 0;

err_disable_reg:
	regulator_bulk_disable(DA7219_NUM_SUPPLIES, da7219->supplies);

	return ret;
}

__attribute__((used)) static void da7219_remove(struct snd_soc_component *component)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);

	da7219_aad_exit(component);

#ifdef CONFIG_COMMON_CLK
	if (da7219->dai_clks_lookup)
		clkdev_drop(da7219->dai_clks_lookup);
#endif

	/* Supplies */
	regulator_bulk_disable(DA7219_NUM_SUPPLIES, da7219->supplies);
}

__attribute__((used)) static bool da7219_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA7219_MIC_1_GAIN_STATUS:
	case DA7219_MIXIN_L_GAIN_STATUS:
	case DA7219_ADC_L_GAIN_STATUS:
	case DA7219_DAC_L_GAIN_STATUS:
	case DA7219_DAC_R_GAIN_STATUS:
	case DA7219_HP_L_GAIN_STATUS:
	case DA7219_HP_R_GAIN_STATUS:
	case DA7219_CIF_CTRL:
	case DA7219_PLL_SRM_STS:
	case DA7219_ALC_CTRL1:
	case DA7219_SYSTEM_MODES_INPUT:
	case DA7219_SYSTEM_MODES_OUTPUT:
	case DA7219_ALC_OFFSET_AUTO_M_L:
	case DA7219_ALC_OFFSET_AUTO_U_L:
	case DA7219_TONE_GEN_CFG1:
	case DA7219_ACCDET_STATUS_A:
	case DA7219_ACCDET_STATUS_B:
	case DA7219_ACCDET_IRQ_EVENT_A:
	case DA7219_ACCDET_IRQ_EVENT_B:
	case DA7219_ACCDET_CONFIG_8:
	case DA7219_SYSTEM_STATUS:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int da7219_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct da7219_priv *da7219;
	unsigned int system_active, system_status;
	int i, ret;

	da7219 = devm_kzalloc(&i2c->dev, sizeof(struct da7219_priv),
			      GFP_KERNEL);
	if (!da7219)
		return -ENOMEM;

	i2c_set_clientdata(i2c, da7219);

	da7219->regmap = devm_regmap_init_i2c(i2c, &da7219_regmap_config);
	if (IS_ERR(da7219->regmap)) {
		ret = PTR_ERR(da7219->regmap);
		dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
		return ret;
	}

	regcache_cache_bypass(da7219->regmap, true);

	/* Disable audio paths if still active from previous start */
	regmap_read(da7219->regmap, DA7219_SYSTEM_ACTIVE, &system_active);
	if (system_active) {
		regmap_write(da7219->regmap, DA7219_GAIN_RAMP_CTRL,
			     DA7219_GAIN_RAMP_RATE_NOMINAL);
		regmap_write(da7219->regmap, DA7219_SYSTEM_MODES_INPUT, 0x00);
		regmap_write(da7219->regmap, DA7219_SYSTEM_MODES_OUTPUT, 0x01);

		for (i = 0; i < DA7219_SYS_STAT_CHECK_RETRIES; ++i) {
			regmap_read(da7219->regmap, DA7219_SYSTEM_STATUS,
				    &system_status);
			if (!system_status)
				break;

			msleep(DA7219_SYS_STAT_CHECK_DELAY);
		}
	}

	/* Soft reset component */
	regmap_write_bits(da7219->regmap, DA7219_ACCDET_CONFIG_1,
			  DA7219_ACCDET_EN_MASK, 0);
	regmap_write_bits(da7219->regmap, DA7219_CIF_CTRL,
			  DA7219_CIF_REG_SOFT_RESET_MASK,
			  DA7219_CIF_REG_SOFT_RESET_MASK);
	regmap_write_bits(da7219->regmap, DA7219_SYSTEM_ACTIVE,
			  DA7219_SYSTEM_ACTIVE_MASK, 0);

	regcache_cache_bypass(da7219->regmap, false);

	ret = devm_snd_soc_register_component(&i2c->dev,
				     &soc_component_dev_da7219,
				     &da7219_dai, 1);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to register da7219 component: %d\n",
			ret);
	}
	return ret;
}

__attribute__((used)) static int da7219_i2c_remove(struct i2c_client *client)
{
	return 0;
}


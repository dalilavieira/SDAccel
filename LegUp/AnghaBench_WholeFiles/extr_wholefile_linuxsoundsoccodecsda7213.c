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
typedef  int u8 ;
typedef  unsigned long long u64 ;
typedef  unsigned int u32 ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; struct device* dev; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
struct da7213_priv {int alc_calib_auto; int alc_en; int master; int clk_src; unsigned int mclk_rate; int /*<<< orphan*/ * regmap; int /*<<< orphan*/ * mclk; struct da7213_platform_data* pdata; } ;
struct da7213_platform_data {int micbias1_lvl; int micbias2_lvl; int dmic_data_sel; int dmic_samplephase; int dmic_clk_rate; } ;
typedef  int frac_div ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
typedef  enum da7213_micbias_voltage { ____Placeholder_da7213_micbias_voltage } da7213_micbias_voltage ;
typedef  enum da7213_dmic_samplephase { ____Placeholder_da7213_dmic_samplephase } da7213_dmic_samplephase ;
typedef  enum da7213_dmic_data_sel { ____Placeholder_da7213_dmic_data_sel } da7213_dmic_data_sel ;
typedef  enum da7213_dmic_clk_rate { ____Placeholder_da7213_dmic_clk_rate } da7213_dmic_clk_rate ;

/* Variables and functions */
 int DA7213_ADC_EN ; 
 int DA7213_ADC_L_CTRL ; 
#define  DA7213_ADC_L_GAIN_STATUS 181 
 int DA7213_ADC_R_CTRL ; 
#define  DA7213_ADC_R_GAIN_STATUS 180 
 int DA7213_ALC_AUTO_CALIB_EN ; 
 int DA7213_ALC_AVG_ITERATIONS ; 
 int DA7213_ALC_CALIB_MODE_MAN ; 
 int DA7213_ALC_CALIB_OVERFLOW ; 
 int DA7213_ALC_CIC_OP_CHANNEL_LEFT ; 
 int DA7213_ALC_CIC_OP_CHANNEL_RIGHT ; 
 int DA7213_ALC_CIC_OP_LVL_CTRL ; 
#define  DA7213_ALC_CIC_OP_LVL_DATA 179 
#define  DA7213_ALC_CTRL1 178 
 int DA7213_ALC_DATA_MIDDLE ; 
 int DA7213_ALC_DATA_TOP ; 
 int DA7213_ALC_OFFSET_15_8 ; 
 int DA7213_ALC_OFFSET_19_16 ; 
#define  DA7213_ALC_OFFSET_AUTO_M_L 177 
#define  DA7213_ALC_OFFSET_AUTO_M_R 176 
#define  DA7213_ALC_OFFSET_AUTO_U_L 175 
#define  DA7213_ALC_OFFSET_AUTO_U_R 174 
 int DA7213_ALC_OFFSET_EN ; 
 int DA7213_ALC_OFFSET_MAN_M_L ; 
 int DA7213_ALC_OFFSET_MAN_M_R ; 
 int DA7213_ALC_OFFSET_MAN_U_L ; 
 int DA7213_ALC_OFFSET_MAN_U_R ; 
 int DA7213_ALC_SYNC_MODE ; 
 int DA7213_AUX_L_CTRL ; 
#define  DA7213_AUX_L_GAIN_STATUS 173 
 int DA7213_AUX_R_CTRL ; 
#define  DA7213_AUX_R_GAIN_STATUS 172 
 int DA7213_BIAS_EN ; 
 unsigned long long DA7213_BYTE_MASK ; 
 unsigned long long DA7213_BYTE_SHIFT ; 
#define  DA7213_CLKSRC_MCLK 171 
#define  DA7213_CLKSRC_MCLK_SQR 170 
 int DA7213_DAC_L_CTRL ; 
#define  DA7213_DAC_L_GAIN_STATUS 169 
 int DA7213_DAC_R_CTRL ; 
#define  DA7213_DAC_R_GAIN_STATUS 168 
 int DA7213_DAI_BCLKS_PER_WCLK_64 ; 
 int DA7213_DAI_CLK_EN_MASK ; 
 int DA7213_DAI_CLK_MODE ; 
 int DA7213_DAI_CLK_POL_INV ; 
 int DA7213_DAI_CTRL ; 
 int DA7213_DAI_FORMAT_DSP ; 
 int DA7213_DAI_FORMAT_I2S_MODE ; 
 int DA7213_DAI_FORMAT_LEFT_J ; 
 int DA7213_DAI_FORMAT_MASK ; 
 int DA7213_DAI_FORMAT_RIGHT_J ; 
 int DA7213_DAI_OFFSET ; 
 int DA7213_DAI_WCLK_POL_INV ; 
 int DA7213_DAI_WORD_LENGTH_MASK ; 
 int DA7213_DAI_WORD_LENGTH_S16_LE ; 
 int DA7213_DAI_WORD_LENGTH_S20_LE ; 
 int DA7213_DAI_WORD_LENGTH_S24_LE ; 
 int DA7213_DAI_WORD_LENGTH_S32_LE ; 
#define  DA7213_DMIC_CLK_1_5MHZ 167 
#define  DA7213_DMIC_CLK_3_0MHZ 166 
 int DA7213_DMIC_CLK_RATE_MASK ; 
 int DA7213_DMIC_CLK_RATE_SHIFT ; 
#define  DA7213_DMIC_DATA_LFALL_RRISE 165 
#define  DA7213_DMIC_DATA_LRISE_RFALL 164 
 int DA7213_DMIC_DATA_SEL_MASK ; 
 int DA7213_DMIC_DATA_SEL_SHIFT ; 
 int DA7213_DMIC_SAMPLEPHASE_MASK ; 
 int DA7213_DMIC_SAMPLEPHASE_SHIFT ; 
#define  DA7213_DMIC_SAMPLE_BETWEEN_CLKEDGE 163 
#define  DA7213_DMIC_SAMPLE_ON_CLKEDGE 162 
 int DA7213_GAIN_RAMP_EN ; 
 int DA7213_HP_AMP_OE ; 
 int DA7213_HP_L_CTRL ; 
#define  DA7213_HP_L_GAIN_STATUS 161 
 int DA7213_HP_R_CTRL ; 
#define  DA7213_HP_R_GAIN_STATUS 160 
 int DA7213_LINE_AMP_OE ; 
 int DA7213_LINE_CTRL ; 
#define  DA7213_LINE_GAIN_STATUS 159 
 int DA7213_MICBIAS1_LEVEL_MASK ; 
 int DA7213_MICBIAS1_LEVEL_SHIFT ; 
 int DA7213_MICBIAS2_LEVEL_MASK ; 
 int DA7213_MICBIAS2_LEVEL_SHIFT ; 
#define  DA7213_MICBIAS_1_6V 158 
#define  DA7213_MICBIAS_2_2V 157 
#define  DA7213_MICBIAS_2_5V 156 
#define  DA7213_MICBIAS_3_0V 155 
 int DA7213_MICBIAS_CTRL ; 
 int DA7213_MIC_1_CTRL ; 
#define  DA7213_MIC_1_GAIN_STATUS 154 
 int DA7213_MIC_2_CTRL ; 
#define  DA7213_MIC_2_GAIN_STATUS 153 
 int DA7213_MIC_CONFIG ; 
 int DA7213_MIXIN_L_CTRL ; 
#define  DA7213_MIXIN_L_GAIN_STATUS 152 
 int DA7213_MIXIN_L_MIX_SELECT_MIC_1 ; 
 int DA7213_MIXIN_L_MIX_SELECT_MIC_2 ; 
 int DA7213_MIXIN_L_SELECT ; 
 int DA7213_MIXIN_MIX_EN ; 
 int DA7213_MIXIN_R_CTRL ; 
#define  DA7213_MIXIN_R_GAIN_STATUS 151 
 int DA7213_MIXIN_R_MIX_SELECT_MIC_1 ; 
 int DA7213_MIXIN_R_MIX_SELECT_MIC_2 ; 
 int DA7213_MIXIN_R_SELECT ; 
 int DA7213_MIXOUT_L_CTRL ; 
 int DA7213_MIXOUT_MIX_EN ; 
 int DA7213_MIXOUT_R_CTRL ; 
 int DA7213_MUTE_EN ; 
 int DA7213_PC_COUNT ; 
 int DA7213_PC_FREERUN_MASK ; 
 int DA7213_PLL_32K_MODE ; 
 int DA7213_PLL_CTRL ; 
 int DA7213_PLL_EN ; 
 int DA7213_PLL_FRAC_BOT ; 
 int DA7213_PLL_FRAC_TOP ; 
 unsigned int DA7213_PLL_FREQ_OUT_94310400 ; 
 int DA7213_PLL_INDIV_18_TO_36_MHZ ; 
 int DA7213_PLL_INDIV_18_TO_36_MHZ_VAL ; 
 int DA7213_PLL_INDIV_36_TO_54_MHZ ; 
 int DA7213_PLL_INDIV_36_TO_54_MHZ_VAL ; 
 int DA7213_PLL_INDIV_5_TO_9_MHZ ; 
 int DA7213_PLL_INDIV_5_TO_9_MHZ_VAL ; 
 int DA7213_PLL_INDIV_9_TO_18_MHZ ; 
 int DA7213_PLL_INDIV_9_TO_18_MHZ_VAL ; 
 int DA7213_PLL_INDIV_MASK ; 
 int DA7213_PLL_INTEGER ; 
 int DA7213_PLL_MCLK_SQR_EN ; 
 int DA7213_PLL_MODE_MASK ; 
 int DA7213_PLL_SRM_EN ; 
#define  DA7213_PLL_STATUS 150 
 int DA7213_REFERENCES ; 
 int DA7213_SR ; 
 int DA7213_SRM_CHECK_RETRIES ; 
 int DA7213_SR_11025 ; 
 int DA7213_SR_12000 ; 
 int DA7213_SR_16000 ; 
 int DA7213_SR_22050 ; 
 int DA7213_SR_32000 ; 
 int DA7213_SR_44100 ; 
 int DA7213_SR_48000 ; 
 int DA7213_SR_8000 ; 
 int DA7213_SR_88200 ; 
 int DA7213_SR_96000 ; 
#define  DA7213_STATUS1 149 
#define  DA7213_SYSCLK_MCLK 148 
#define  DA7213_SYSCLK_PLL 147 
#define  DA7213_SYSCLK_PLL_32KHZ 146 
#define  DA7213_SYSCLK_PLL_SRM 145 
 int DA7213_VMID_EN ; 
 int DA7219_PLL_SRM_LOCK ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
#define  SND_SOC_BIAS_OFF 144 
#define  SND_SOC_BIAS_ON 143 
#define  SND_SOC_BIAS_PREPARE 142 
#define  SND_SOC_BIAS_STANDBY 141 
#define  SND_SOC_DAIFMT_CBM_CFM 140 
#define  SND_SOC_DAIFMT_CBS_CFS 139 
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
#define  SND_SOC_DAI_FORMAT_DSP_A 131 
#define  SND_SOC_DAI_FORMAT_DSP_B 130 
#define  SND_SOC_DAPM_POST_PMD 129 
#define  SND_SOC_DAPM_PRE_PMU 128 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ *) ; 
 int clk_prepare_enable (int /*<<< orphan*/ *) ; 
 unsigned int clk_round_rate (int /*<<< orphan*/ *,unsigned int) ; 
 int clk_set_rate (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  da7213_dai ; 
 int /*<<< orphan*/  da7213_regmap_config ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct da7213_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_property_read_string (struct device*,char*,char const**) ; 
 scalar_t__ device_property_read_u32 (struct device*,char*,unsigned int*) ; 
 int /*<<< orphan*/ * devm_clk_get (struct device*,char*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  do_div (unsigned long long,unsigned int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct da7213_priv*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct da7213_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_put_volsw (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int snd_soc_put_volsw_2r (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int /*<<< orphan*/  soc_component_dev_da7213 ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static int da7213_get_alc_data(struct snd_soc_component *component, u8 reg_val)
{
	int mid_data, top_data;
	int sum = 0;
	u8 iteration;

	for (iteration = 0; iteration < DA7213_ALC_AVG_ITERATIONS;
	     iteration++) {
		/* Select the left or right channel and capture data */
		snd_soc_component_write(component, DA7213_ALC_CIC_OP_LVL_CTRL, reg_val);

		/* Select middle 8 bits for read back from data register */
		snd_soc_component_write(component, DA7213_ALC_CIC_OP_LVL_CTRL,
			      reg_val | DA7213_ALC_DATA_MIDDLE);
		mid_data = snd_soc_component_read32(component, DA7213_ALC_CIC_OP_LVL_DATA);

		/* Select top 8 bits for read back from data register */
		snd_soc_component_write(component, DA7213_ALC_CIC_OP_LVL_CTRL,
			      reg_val | DA7213_ALC_DATA_TOP);
		top_data = snd_soc_component_read32(component, DA7213_ALC_CIC_OP_LVL_DATA);

		sum += ((mid_data << 8) | (top_data << 16));
	}

	return sum / DA7213_ALC_AVG_ITERATIONS;
}

__attribute__((used)) static void da7213_alc_calib_man(struct snd_soc_component *component)
{
	u8 reg_val;
	int avg_left_data, avg_right_data, offset_l, offset_r;

	/* Calculate average for Left and Right data */
	/* Left Data */
	avg_left_data = da7213_get_alc_data(component,
			DA7213_ALC_CIC_OP_CHANNEL_LEFT);
	/* Right Data */
	avg_right_data = da7213_get_alc_data(component,
			 DA7213_ALC_CIC_OP_CHANNEL_RIGHT);

	/* Calculate DC offset */
	offset_l = -avg_left_data;
	offset_r = -avg_right_data;

	reg_val = (offset_l & DA7213_ALC_OFFSET_15_8) >> 8;
	snd_soc_component_write(component, DA7213_ALC_OFFSET_MAN_M_L, reg_val);
	reg_val = (offset_l & DA7213_ALC_OFFSET_19_16) >> 16;
	snd_soc_component_write(component, DA7213_ALC_OFFSET_MAN_U_L, reg_val);

	reg_val = (offset_r & DA7213_ALC_OFFSET_15_8) >> 8;
	snd_soc_component_write(component, DA7213_ALC_OFFSET_MAN_M_R, reg_val);
	reg_val = (offset_r & DA7213_ALC_OFFSET_19_16) >> 16;
	snd_soc_component_write(component, DA7213_ALC_OFFSET_MAN_U_R, reg_val);

	/* Enable analog/digital gain mode & offset cancellation */
	snd_soc_component_update_bits(component, DA7213_ALC_CTRL1,
			    DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE,
			    DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE);
}

__attribute__((used)) static void da7213_alc_calib_auto(struct snd_soc_component *component)
{
	u8 alc_ctrl1;

	/* Begin auto calibration and wait for completion */
	snd_soc_component_update_bits(component, DA7213_ALC_CTRL1, DA7213_ALC_AUTO_CALIB_EN,
			    DA7213_ALC_AUTO_CALIB_EN);
	do {
		alc_ctrl1 = snd_soc_component_read32(component, DA7213_ALC_CTRL1);
	} while (alc_ctrl1 & DA7213_ALC_AUTO_CALIB_EN);

	/* If auto calibration fails, fall back to digital gain only mode */
	if (alc_ctrl1 & DA7213_ALC_CALIB_OVERFLOW) {
		dev_warn(component->dev,
			 "ALC auto calibration failed with overflow\n");
		snd_soc_component_update_bits(component, DA7213_ALC_CTRL1,
				    DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE,
				    0);
	} else {
		/* Enable analog/digital gain mode & offset cancellation */
		snd_soc_component_update_bits(component, DA7213_ALC_CTRL1,
				    DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE,
				    DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE);
	}

}

__attribute__((used)) static void da7213_alc_calib(struct snd_soc_component *component)
{
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);
	u8 adc_l_ctrl, adc_r_ctrl;
	u8 mixin_l_sel, mixin_r_sel;
	u8 mic_1_ctrl, mic_2_ctrl;

	/* Save current values from ADC control registers */
	adc_l_ctrl = snd_soc_component_read32(component, DA7213_ADC_L_CTRL);
	adc_r_ctrl = snd_soc_component_read32(component, DA7213_ADC_R_CTRL);

	/* Save current values from MIXIN_L/R_SELECT registers */
	mixin_l_sel = snd_soc_component_read32(component, DA7213_MIXIN_L_SELECT);
	mixin_r_sel = snd_soc_component_read32(component, DA7213_MIXIN_R_SELECT);

	/* Save current values from MIC control registers */
	mic_1_ctrl = snd_soc_component_read32(component, DA7213_MIC_1_CTRL);
	mic_2_ctrl = snd_soc_component_read32(component, DA7213_MIC_2_CTRL);

	/* Enable ADC Left and Right */
	snd_soc_component_update_bits(component, DA7213_ADC_L_CTRL, DA7213_ADC_EN,
			    DA7213_ADC_EN);
	snd_soc_component_update_bits(component, DA7213_ADC_R_CTRL, DA7213_ADC_EN,
			    DA7213_ADC_EN);

	/* Enable MIC paths */
	snd_soc_component_update_bits(component, DA7213_MIXIN_L_SELECT,
			    DA7213_MIXIN_L_MIX_SELECT_MIC_1 |
			    DA7213_MIXIN_L_MIX_SELECT_MIC_2,
			    DA7213_MIXIN_L_MIX_SELECT_MIC_1 |
			    DA7213_MIXIN_L_MIX_SELECT_MIC_2);
	snd_soc_component_update_bits(component, DA7213_MIXIN_R_SELECT,
			    DA7213_MIXIN_R_MIX_SELECT_MIC_2 |
			    DA7213_MIXIN_R_MIX_SELECT_MIC_1,
			    DA7213_MIXIN_R_MIX_SELECT_MIC_2 |
			    DA7213_MIXIN_R_MIX_SELECT_MIC_1);

	/* Mute MIC PGAs */
	snd_soc_component_update_bits(component, DA7213_MIC_1_CTRL, DA7213_MUTE_EN,
			    DA7213_MUTE_EN);
	snd_soc_component_update_bits(component, DA7213_MIC_2_CTRL, DA7213_MUTE_EN,
			    DA7213_MUTE_EN);

	/* Perform calibration */
	if (da7213->alc_calib_auto)
		da7213_alc_calib_auto(component);
	else
		da7213_alc_calib_man(component);

	/* Restore MIXIN_L/R_SELECT registers to their original states */
	snd_soc_component_write(component, DA7213_MIXIN_L_SELECT, mixin_l_sel);
	snd_soc_component_write(component, DA7213_MIXIN_R_SELECT, mixin_r_sel);

	/* Restore ADC control registers to their original states */
	snd_soc_component_write(component, DA7213_ADC_L_CTRL, adc_l_ctrl);
	snd_soc_component_write(component, DA7213_ADC_R_CTRL, adc_r_ctrl);

	/* Restore original values of MIC control registers */
	snd_soc_component_write(component, DA7213_MIC_1_CTRL, mic_1_ctrl);
	snd_soc_component_write(component, DA7213_MIC_2_CTRL, mic_2_ctrl);
}

__attribute__((used)) static int da7213_put_mixin_gain(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);
	int ret;

	ret = snd_soc_put_volsw_2r(kcontrol, ucontrol);

	/* If ALC in operation, make sure calibrated offsets are updated */
	if ((!ret) && (da7213->alc_en))
		da7213_alc_calib(component);

	return ret;
}

__attribute__((used)) static int da7213_put_alc_sw(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);

	/* Force ALC offset calibration if enabling ALC */
	if (ucontrol->value.integer.value[0] ||
	    ucontrol->value.integer.value[1]) {
		if (!da7213->alc_en) {
			da7213_alc_calib(component);
			da7213->alc_en = true;
		}
	} else {
		da7213->alc_en = false;
	}

	return snd_soc_put_volsw(kcontrol, ucontrol);
}

__attribute__((used)) static int da7213_dai_event(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);
	u8 pll_ctrl, pll_status;
	int i = 0;
	bool srm_lock = false;

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		/* Enable DAI clks for master mode */
		if (da7213->master)
			snd_soc_component_update_bits(component, DA7213_DAI_CLK_MODE,
					    DA7213_DAI_CLK_EN_MASK,
					    DA7213_DAI_CLK_EN_MASK);

		/* PC synchronised to DAI */
		snd_soc_component_update_bits(component, DA7213_PC_COUNT,
				    DA7213_PC_FREERUN_MASK, 0);

		/* If SRM not enabled then nothing more to do */
		pll_ctrl = snd_soc_component_read32(component, DA7213_PLL_CTRL);
		if (!(pll_ctrl & DA7213_PLL_SRM_EN))
			return 0;

		/* Assist 32KHz mode PLL lock */
		if (pll_ctrl & DA7213_PLL_32K_MODE) {
			snd_soc_component_write(component, 0xF0, 0x8B);
			snd_soc_component_write(component, 0xF2, 0x03);
			snd_soc_component_write(component, 0xF0, 0x00);
		}

		/* Check SRM has locked */
		do {
			pll_status = snd_soc_component_read32(component, DA7213_PLL_STATUS);
			if (pll_status & DA7219_PLL_SRM_LOCK) {
				srm_lock = true;
			} else {
				++i;
				msleep(50);
			}
		} while ((i < DA7213_SRM_CHECK_RETRIES) && (!srm_lock));

		if (!srm_lock)
			dev_warn(component->dev, "SRM failed to lock\n");

		return 0;
	case SND_SOC_DAPM_POST_PMD:
		/* Revert 32KHz PLL lock udpates if applied previously */
		pll_ctrl = snd_soc_component_read32(component, DA7213_PLL_CTRL);
		if (pll_ctrl & DA7213_PLL_32K_MODE) {
			snd_soc_component_write(component, 0xF0, 0x8B);
			snd_soc_component_write(component, 0xF2, 0x01);
			snd_soc_component_write(component, 0xF0, 0x00);
		}

		/* PC free-running */
		snd_soc_component_update_bits(component, DA7213_PC_COUNT,
				    DA7213_PC_FREERUN_MASK,
				    DA7213_PC_FREERUN_MASK);

		/* Disable DAI clks if in master mode */
		if (da7213->master)
			snd_soc_component_update_bits(component, DA7213_DAI_CLK_MODE,
					    DA7213_DAI_CLK_EN_MASK, 0);
		return 0;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static bool da7213_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA7213_STATUS1:
	case DA7213_PLL_STATUS:
	case DA7213_AUX_L_GAIN_STATUS:
	case DA7213_AUX_R_GAIN_STATUS:
	case DA7213_MIC_1_GAIN_STATUS:
	case DA7213_MIC_2_GAIN_STATUS:
	case DA7213_MIXIN_L_GAIN_STATUS:
	case DA7213_MIXIN_R_GAIN_STATUS:
	case DA7213_ADC_L_GAIN_STATUS:
	case DA7213_ADC_R_GAIN_STATUS:
	case DA7213_DAC_L_GAIN_STATUS:
	case DA7213_DAC_R_GAIN_STATUS:
	case DA7213_HP_L_GAIN_STATUS:
	case DA7213_HP_R_GAIN_STATUS:
	case DA7213_LINE_GAIN_STATUS:
	case DA7213_ALC_CTRL1:
	case DA7213_ALC_OFFSET_AUTO_M_L:
	case DA7213_ALC_OFFSET_AUTO_U_L:
	case DA7213_ALC_OFFSET_AUTO_M_R:
	case DA7213_ALC_OFFSET_AUTO_U_R:
	case DA7213_ALC_CIC_OP_LVL_DATA:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int da7213_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	u8 dai_ctrl = 0;
	u8 fs;

	/* Set DAI format */
	switch (params_width(params)) {
	case 16:
		dai_ctrl |= DA7213_DAI_WORD_LENGTH_S16_LE;
		break;
	case 20:
		dai_ctrl |= DA7213_DAI_WORD_LENGTH_S20_LE;
		break;
	case 24:
		dai_ctrl |= DA7213_DAI_WORD_LENGTH_S24_LE;
		break;
	case 32:
		dai_ctrl |= DA7213_DAI_WORD_LENGTH_S32_LE;
		break;
	default:
		return -EINVAL;
	}

	/* Set sampling rate */
	switch (params_rate(params)) {
	case 8000:
		fs = DA7213_SR_8000;
		break;
	case 11025:
		fs = DA7213_SR_11025;
		break;
	case 12000:
		fs = DA7213_SR_12000;
		break;
	case 16000:
		fs = DA7213_SR_16000;
		break;
	case 22050:
		fs = DA7213_SR_22050;
		break;
	case 32000:
		fs = DA7213_SR_32000;
		break;
	case 44100:
		fs = DA7213_SR_44100;
		break;
	case 48000:
		fs = DA7213_SR_48000;
		break;
	case 88200:
		fs = DA7213_SR_88200;
		break;
	case 96000:
		fs = DA7213_SR_96000;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, DA7213_DAI_CTRL, DA7213_DAI_WORD_LENGTH_MASK,
			    dai_ctrl);
	snd_soc_component_write(component, DA7213_SR, fs);

	return 0;
}

__attribute__((used)) static int da7213_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);
	u8 dai_clk_mode = 0, dai_ctrl = 0;
	u8 dai_offset = 0;

	/* Set master/slave mode */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		da7213->master = true;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		da7213->master = false;
		break;
	default:
		return -EINVAL;
	}

	/* Set clock normal/inverted */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			break;
		case SND_SOC_DAIFMT_NB_IF:
			dai_clk_mode |= DA7213_DAI_WCLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			dai_clk_mode |= DA7213_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_IF:
			dai_clk_mode |= DA7213_DAI_WCLK_POL_INV |
					DA7213_DAI_CLK_POL_INV;
			break;
		default:
			return -EINVAL;
		}
		break;
	case SND_SOC_DAI_FORMAT_DSP_A:
	case SND_SOC_DAI_FORMAT_DSP_B:
		/* The bclk is inverted wrt ASoC conventions */
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			dai_clk_mode |= DA7213_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_NB_IF:
			dai_clk_mode |= DA7213_DAI_WCLK_POL_INV |
					DA7213_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			break;
		case SND_SOC_DAIFMT_IB_IF:
			dai_clk_mode |= DA7213_DAI_WCLK_POL_INV;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	/* Only I2S is supported */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		dai_ctrl |= DA7213_DAI_FORMAT_I2S_MODE;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		dai_ctrl |= DA7213_DAI_FORMAT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		dai_ctrl |= DA7213_DAI_FORMAT_RIGHT_J;
		break;
	case SND_SOC_DAI_FORMAT_DSP_A: /* L data MSB after FRM LRC */
		dai_ctrl |= DA7213_DAI_FORMAT_DSP;
		dai_offset = 1;
		break;
	case SND_SOC_DAI_FORMAT_DSP_B: /* L data MSB during FRM LRC */
		dai_ctrl |= DA7213_DAI_FORMAT_DSP;
		break;
	default:
		return -EINVAL;
	}

	/* By default only 64 BCLK per WCLK is supported */
	dai_clk_mode |= DA7213_DAI_BCLKS_PER_WCLK_64;

	snd_soc_component_write(component, DA7213_DAI_CLK_MODE, dai_clk_mode);
	snd_soc_component_update_bits(component, DA7213_DAI_CTRL, DA7213_DAI_FORMAT_MASK,
			    dai_ctrl);
	snd_soc_component_write(component, DA7213_DAI_OFFSET, dai_offset);

	return 0;
}

__attribute__((used)) static int da7213_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;

	if (mute) {
		snd_soc_component_update_bits(component, DA7213_DAC_L_CTRL,
				    DA7213_MUTE_EN, DA7213_MUTE_EN);
		snd_soc_component_update_bits(component, DA7213_DAC_R_CTRL,
				    DA7213_MUTE_EN, DA7213_MUTE_EN);
	} else {
		snd_soc_component_update_bits(component, DA7213_DAC_L_CTRL,
				    DA7213_MUTE_EN, 0);
		snd_soc_component_update_bits(component, DA7213_DAC_R_CTRL,
				    DA7213_MUTE_EN, 0);
	}

	return 0;
}

__attribute__((used)) static int da7213_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);
	int ret = 0;

	if ((da7213->clk_src == clk_id) && (da7213->mclk_rate == freq))
		return 0;

	if (((freq < 5000000) && (freq != 32768)) || (freq > 54000000)) {
		dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
			freq);
		return -EINVAL;
	}

	switch (clk_id) {
	case DA7213_CLKSRC_MCLK:
		snd_soc_component_update_bits(component, DA7213_PLL_CTRL,
				    DA7213_PLL_MCLK_SQR_EN, 0);
		break;
	case DA7213_CLKSRC_MCLK_SQR:
		snd_soc_component_update_bits(component, DA7213_PLL_CTRL,
				    DA7213_PLL_MCLK_SQR_EN,
				    DA7213_PLL_MCLK_SQR_EN);
		break;
	default:
		dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
		return -EINVAL;
	}

	da7213->clk_src = clk_id;

	if (da7213->mclk) {
		freq = clk_round_rate(da7213->mclk, freq);
		ret = clk_set_rate(da7213->mclk, freq);
		if (ret) {
			dev_err(codec_dai->dev, "Failed to set clock rate %d\n",
				freq);
			return ret;
		}
	}

	da7213->mclk_rate = freq;

	return 0;
}

__attribute__((used)) static int da7213_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
			      int source, unsigned int fref, unsigned int fout)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);

	u8 pll_ctrl, indiv_bits, indiv;
	u8 pll_frac_top, pll_frac_bot, pll_integer;
	u32 freq_ref;
	u64 frac_div;

	/* Workout input divider based on MCLK rate */
	if (da7213->mclk_rate == 32768) {
		if (!da7213->master) {
			dev_err(component->dev,
				"32KHz only valid if codec is clock master\n");
			return -EINVAL;
		}

		/* 32KHz PLL Mode */
		indiv_bits = DA7213_PLL_INDIV_9_TO_18_MHZ;
		indiv = DA7213_PLL_INDIV_9_TO_18_MHZ_VAL;
		source = DA7213_SYSCLK_PLL_32KHZ;
		freq_ref = 3750000;

	} else {
		if (da7213->mclk_rate < 5000000) {
			dev_err(component->dev,
				"PLL input clock %d below valid range\n",
				da7213->mclk_rate);
			return -EINVAL;
		} else if (da7213->mclk_rate <= 9000000) {
			indiv_bits = DA7213_PLL_INDIV_5_TO_9_MHZ;
			indiv = DA7213_PLL_INDIV_5_TO_9_MHZ_VAL;
		} else if (da7213->mclk_rate <= 18000000) {
			indiv_bits = DA7213_PLL_INDIV_9_TO_18_MHZ;
			indiv = DA7213_PLL_INDIV_9_TO_18_MHZ_VAL;
		} else if (da7213->mclk_rate <= 36000000) {
			indiv_bits = DA7213_PLL_INDIV_18_TO_36_MHZ;
			indiv = DA7213_PLL_INDIV_18_TO_36_MHZ_VAL;
		} else if (da7213->mclk_rate <= 54000000) {
			indiv_bits = DA7213_PLL_INDIV_36_TO_54_MHZ;
			indiv = DA7213_PLL_INDIV_36_TO_54_MHZ_VAL;
		} else {
			dev_err(component->dev,
				"PLL input clock %d above valid range\n",
				da7213->mclk_rate);
			return -EINVAL;
		}
		freq_ref = (da7213->mclk_rate / indiv);
	}

	pll_ctrl = indiv_bits;

	/* Configure PLL */
	switch (source) {
	case DA7213_SYSCLK_MCLK:
		snd_soc_component_update_bits(component, DA7213_PLL_CTRL,
				    DA7213_PLL_INDIV_MASK |
				    DA7213_PLL_MODE_MASK, pll_ctrl);
		return 0;
	case DA7213_SYSCLK_PLL:
		break;
	case DA7213_SYSCLK_PLL_SRM:
		pll_ctrl |= DA7213_PLL_SRM_EN;
		fout = DA7213_PLL_FREQ_OUT_94310400;
		break;
	case DA7213_SYSCLK_PLL_32KHZ:
		if (da7213->mclk_rate != 32768) {
			dev_err(component->dev,
				"32KHz mode only valid with 32KHz MCLK\n");
			return -EINVAL;
		}

		pll_ctrl |= DA7213_PLL_32K_MODE | DA7213_PLL_SRM_EN;
		fout = DA7213_PLL_FREQ_OUT_94310400;
		break;
	default:
		dev_err(component->dev, "Invalid PLL config\n");
		return -EINVAL;
	}

	/* Calculate dividers for PLL */
	pll_integer = fout / freq_ref;
	frac_div = (u64)(fout % freq_ref) * 8192ULL;
	do_div(frac_div, freq_ref);
	pll_frac_top = (frac_div >> DA7213_BYTE_SHIFT) & DA7213_BYTE_MASK;
	pll_frac_bot = (frac_div) & DA7213_BYTE_MASK;

	/* Write PLL dividers */
	snd_soc_component_write(component, DA7213_PLL_FRAC_TOP, pll_frac_top);
	snd_soc_component_write(component, DA7213_PLL_FRAC_BOT, pll_frac_bot);
	snd_soc_component_write(component, DA7213_PLL_INTEGER, pll_integer);

	/* Enable PLL */
	pll_ctrl |= DA7213_PLL_EN;
	snd_soc_component_update_bits(component, DA7213_PLL_CTRL,
			    DA7213_PLL_INDIV_MASK | DA7213_PLL_MODE_MASK,
			    pll_ctrl);

	/* Assist 32KHz mode PLL lock */
	if (source == DA7213_SYSCLK_PLL_32KHZ) {
		snd_soc_component_write(component, 0xF0, 0x8B);
		snd_soc_component_write(component, 0xF1, 0x03);
		snd_soc_component_write(component, 0xF1, 0x01);
		snd_soc_component_write(component, 0xF0, 0x00);
	}

	return 0;
}

__attribute__((used)) static int da7213_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		/* Enable MCLK for transition to ON state */
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_STANDBY) {
			if (da7213->mclk) {
				ret = clk_prepare_enable(da7213->mclk);
				if (ret) {
					dev_err(component->dev,
						"Failed to enable mclk\n");
					return ret;
				}
			}
		}
		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			/* Enable VMID reference & master bias */
			snd_soc_component_update_bits(component, DA7213_REFERENCES,
					    DA7213_VMID_EN | DA7213_BIAS_EN,
					    DA7213_VMID_EN | DA7213_BIAS_EN);
		} else {
			/* Remove MCLK */
			if (da7213->mclk)
				clk_disable_unprepare(da7213->mclk);
		}
		break;
	case SND_SOC_BIAS_OFF:
		/* Disable VMID reference & master bias */
		snd_soc_component_update_bits(component, DA7213_REFERENCES,
				    DA7213_VMID_EN | DA7213_BIAS_EN, 0);
		break;
	}
	return 0;
}

__attribute__((used)) static enum da7213_micbias_voltage
	da7213_of_micbias_lvl(struct snd_soc_component *component, u32 val)
{
	switch (val) {
	case 1600:
		return DA7213_MICBIAS_1_6V;
	case 2200:
		return DA7213_MICBIAS_2_2V;
	case 2500:
		return DA7213_MICBIAS_2_5V;
	case 3000:
		return DA7213_MICBIAS_3_0V;
	default:
		dev_warn(component->dev, "Invalid micbias level\n");
		return DA7213_MICBIAS_2_2V;
	}
}

__attribute__((used)) static enum da7213_dmic_data_sel
	da7213_of_dmic_data_sel(struct snd_soc_component *component, const char *str)
{
	if (!strcmp(str, "lrise_rfall")) {
		return DA7213_DMIC_DATA_LRISE_RFALL;
	} else if (!strcmp(str, "lfall_rrise")) {
		return DA7213_DMIC_DATA_LFALL_RRISE;
	} else {
		dev_warn(component->dev, "Invalid DMIC data select type\n");
		return DA7213_DMIC_DATA_LRISE_RFALL;
	}
}

__attribute__((used)) static enum da7213_dmic_samplephase
	da7213_of_dmic_samplephase(struct snd_soc_component *component, const char *str)
{
	if (!strcmp(str, "on_clkedge")) {
		return DA7213_DMIC_SAMPLE_ON_CLKEDGE;
	} else if (!strcmp(str, "between_clkedge")) {
		return DA7213_DMIC_SAMPLE_BETWEEN_CLKEDGE;
	} else {
		dev_warn(component->dev, "Invalid DMIC sample phase\n");
		return DA7213_DMIC_SAMPLE_ON_CLKEDGE;
	}
}

__attribute__((used)) static enum da7213_dmic_clk_rate
	da7213_of_dmic_clkrate(struct snd_soc_component *component, u32 val)
{
	switch (val) {
	case 1500000:
		return DA7213_DMIC_CLK_1_5MHZ;
	case 3000000:
		return DA7213_DMIC_CLK_3_0MHZ;
	default:
		dev_warn(component->dev, "Invalid DMIC clock rate\n");
		return DA7213_DMIC_CLK_1_5MHZ;
	}
}

__attribute__((used)) static struct da7213_platform_data
	*da7213_fw_to_pdata(struct snd_soc_component *component)
{
	struct device *dev = component->dev;
	struct da7213_platform_data *pdata;
	const char *fw_str;
	u32 fw_val32;

	pdata = devm_kzalloc(component->dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;

	if (device_property_read_u32(dev, "dlg,micbias1-lvl", &fw_val32) >= 0)
		pdata->micbias1_lvl = da7213_of_micbias_lvl(component, fw_val32);
	else
		pdata->micbias1_lvl = DA7213_MICBIAS_2_2V;

	if (device_property_read_u32(dev, "dlg,micbias2-lvl", &fw_val32) >= 0)
		pdata->micbias2_lvl = da7213_of_micbias_lvl(component, fw_val32);
	else
		pdata->micbias2_lvl = DA7213_MICBIAS_2_2V;

	if (!device_property_read_string(dev, "dlg,dmic-data-sel", &fw_str))
		pdata->dmic_data_sel = da7213_of_dmic_data_sel(component, fw_str);
	else
		pdata->dmic_data_sel = DA7213_DMIC_DATA_LRISE_RFALL;

	if (!device_property_read_string(dev, "dlg,dmic-samplephase", &fw_str))
		pdata->dmic_samplephase =
			da7213_of_dmic_samplephase(component, fw_str);
	else
		pdata->dmic_samplephase = DA7213_DMIC_SAMPLE_ON_CLKEDGE;

	if (device_property_read_u32(dev, "dlg,dmic-clkrate", &fw_val32) >= 0)
		pdata->dmic_clk_rate = da7213_of_dmic_clkrate(component, fw_val32);
	else
		pdata->dmic_clk_rate = DA7213_DMIC_CLK_3_0MHZ;

	return pdata;
}

__attribute__((used)) static int da7213_probe(struct snd_soc_component *component)
{
	struct da7213_priv *da7213 = snd_soc_component_get_drvdata(component);

	/* Default to using ALC auto offset calibration mode. */
	snd_soc_component_update_bits(component, DA7213_ALC_CTRL1,
			    DA7213_ALC_CALIB_MODE_MAN, 0);
	da7213->alc_calib_auto = true;

	/* Default PC counter to free-running */
	snd_soc_component_update_bits(component, DA7213_PC_COUNT, DA7213_PC_FREERUN_MASK,
			    DA7213_PC_FREERUN_MASK);

	/* Enable all Gain Ramps */
	snd_soc_component_update_bits(component, DA7213_AUX_L_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_AUX_R_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_MIXIN_L_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_MIXIN_R_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_ADC_L_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_ADC_R_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_DAC_L_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_DAC_R_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_HP_L_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_HP_R_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
	snd_soc_component_update_bits(component, DA7213_LINE_CTRL,
			    DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);

	/*
	 * There are two separate control bits for input and output mixers as
	 * well as headphone and line outs.
	 * One to enable corresponding amplifier and other to enable its
	 * output. As amplifier bits are related to power control, they are
	 * being managed by DAPM while other (non power related) bits are
	 * enabled here
	 */
	snd_soc_component_update_bits(component, DA7213_MIXIN_L_CTRL,
			    DA7213_MIXIN_MIX_EN, DA7213_MIXIN_MIX_EN);
	snd_soc_component_update_bits(component, DA7213_MIXIN_R_CTRL,
			    DA7213_MIXIN_MIX_EN, DA7213_MIXIN_MIX_EN);

	snd_soc_component_update_bits(component, DA7213_MIXOUT_L_CTRL,
			    DA7213_MIXOUT_MIX_EN, DA7213_MIXOUT_MIX_EN);
	snd_soc_component_update_bits(component, DA7213_MIXOUT_R_CTRL,
			    DA7213_MIXOUT_MIX_EN, DA7213_MIXOUT_MIX_EN);

	snd_soc_component_update_bits(component, DA7213_HP_L_CTRL,
			    DA7213_HP_AMP_OE, DA7213_HP_AMP_OE);
	snd_soc_component_update_bits(component, DA7213_HP_R_CTRL,
			    DA7213_HP_AMP_OE, DA7213_HP_AMP_OE);

	snd_soc_component_update_bits(component, DA7213_LINE_CTRL,
			    DA7213_LINE_AMP_OE, DA7213_LINE_AMP_OE);

	/* Handle DT/Platform data */
	da7213->pdata = dev_get_platdata(component->dev);
	if (!da7213->pdata)
		da7213->pdata = da7213_fw_to_pdata(component);

	/* Set platform data values */
	if (da7213->pdata) {
		struct da7213_platform_data *pdata = da7213->pdata;
		u8 micbias_lvl = 0, dmic_cfg = 0;

		/* Set Mic Bias voltages */
		switch (pdata->micbias1_lvl) {
		case DA7213_MICBIAS_1_6V:
		case DA7213_MICBIAS_2_2V:
		case DA7213_MICBIAS_2_5V:
		case DA7213_MICBIAS_3_0V:
			micbias_lvl |= (pdata->micbias1_lvl <<
					DA7213_MICBIAS1_LEVEL_SHIFT);
			break;
		}
		switch (pdata->micbias2_lvl) {
		case DA7213_MICBIAS_1_6V:
		case DA7213_MICBIAS_2_2V:
		case DA7213_MICBIAS_2_5V:
		case DA7213_MICBIAS_3_0V:
			micbias_lvl |= (pdata->micbias2_lvl <<
					 DA7213_MICBIAS2_LEVEL_SHIFT);
			break;
		}
		snd_soc_component_update_bits(component, DA7213_MICBIAS_CTRL,
				    DA7213_MICBIAS1_LEVEL_MASK |
				    DA7213_MICBIAS2_LEVEL_MASK, micbias_lvl);

		/* Set DMIC configuration */
		switch (pdata->dmic_data_sel) {
		case DA7213_DMIC_DATA_LFALL_RRISE:
		case DA7213_DMIC_DATA_LRISE_RFALL:
			dmic_cfg |= (pdata->dmic_data_sel <<
				     DA7213_DMIC_DATA_SEL_SHIFT);
			break;
		}
		switch (pdata->dmic_samplephase) {
		case DA7213_DMIC_SAMPLE_ON_CLKEDGE:
		case DA7213_DMIC_SAMPLE_BETWEEN_CLKEDGE:
			dmic_cfg |= (pdata->dmic_samplephase <<
				     DA7213_DMIC_SAMPLEPHASE_SHIFT);
			break;
		}
		switch (pdata->dmic_clk_rate) {
		case DA7213_DMIC_CLK_3_0MHZ:
		case DA7213_DMIC_CLK_1_5MHZ:
			dmic_cfg |= (pdata->dmic_clk_rate <<
				     DA7213_DMIC_CLK_RATE_SHIFT);
			break;
		}
		snd_soc_component_update_bits(component, DA7213_MIC_CONFIG,
				    DA7213_DMIC_DATA_SEL_MASK |
				    DA7213_DMIC_SAMPLEPHASE_MASK |
				    DA7213_DMIC_CLK_RATE_MASK, dmic_cfg);
	}

	/* Check if MCLK provided */
	da7213->mclk = devm_clk_get(component->dev, "mclk");
	if (IS_ERR(da7213->mclk)) {
		if (PTR_ERR(da7213->mclk) != -ENOENT)
			return PTR_ERR(da7213->mclk);
		else
			da7213->mclk = NULL;
	}

	return 0;
}

__attribute__((used)) static int da7213_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct da7213_priv *da7213;
	int ret;

	da7213 = devm_kzalloc(&i2c->dev, sizeof(*da7213), GFP_KERNEL);
	if (!da7213)
		return -ENOMEM;

	i2c_set_clientdata(i2c, da7213);

	da7213->regmap = devm_regmap_init_i2c(i2c, &da7213_regmap_config);
	if (IS_ERR(da7213->regmap)) {
		ret = PTR_ERR(da7213->regmap);
		dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
		return ret;
	}

	ret = devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_da7213, &da7213_dai, 1);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to register da7213 component: %d\n",
			ret);
	}
	return ret;
}


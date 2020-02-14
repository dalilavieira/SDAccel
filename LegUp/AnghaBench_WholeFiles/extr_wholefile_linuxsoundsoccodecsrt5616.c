#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {size_t id; struct snd_soc_component* component; int /*<<< orphan*/  dev; } ;
struct snd_soc_component {int /*<<< orphan*/ * dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct rt5616_priv {int* lrck; unsigned int sysclk; int* bclk; int* master; int sysclk_src; int pll_src; unsigned int pll_in; unsigned int pll_out; int /*<<< orphan*/  regmap; struct snd_soc_component* component; int /*<<< orphan*/  mclk; } ;
struct rl6231_pll_code {int m_bp; int m_code; int n_code; int k_code; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_7__ {unsigned int range_min; unsigned int range_max; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  RT5616_ADC_BST_VOL 235 
#define  RT5616_ADC_DIG_VOL 234 
#define  RT5616_ADDA_CLK1 233 
#define  RT5616_ADDA_CLK2 232 
#define  RT5616_ADJ_HPF_CTRL1 231 
#define  RT5616_ADJ_HPF_CTRL2 230 
#define  RT5616_AD_DA_MIXER 229 
#define  RT5616_A_JD_CTL1 228 
#define  RT5616_A_JD_CTL2 227 
#define  RT5616_BASE_BACK 226 
#define  RT5616_CHARGE_PUMP 225 
 int const RT5616_CHOP_DAC_ADC ; 
 unsigned int RT5616_CP_FQ1_MASK ; 
 unsigned int RT5616_CP_FQ1_SFT ; 
 unsigned int RT5616_CP_FQ2_MASK ; 
 unsigned int RT5616_CP_FQ2_SFT ; 
 unsigned int RT5616_CP_FQ3_MASK ; 
 unsigned int RT5616_CP_FQ3_SFT ; 
 unsigned int RT5616_CP_FQ_12_KHZ ; 
 unsigned int RT5616_CP_FQ_192_KHZ ; 
 unsigned int RT5616_CP_FQ_96_KHZ ; 
#define  RT5616_DAC1_DIG_VOL 224 
#define  RT5616_DEPOP_M1 223 
#define  RT5616_DEPOP_M2 222 
#define  RT5616_DEPOP_M3 221 
 unsigned int RT5616_DEPOP_MAN ; 
 unsigned int RT5616_DEPOP_MASK ; 
#define  RT5616_DEVICE_ID 220 
#define  RT5616_DRC_AGC_1 219 
#define  RT5616_DRC_AGC_2 218 
#define  RT5616_DRC_AGC_3 217 
#define  RT5616_DUMMY2 216 
#define  RT5616_DUMMY3 215 
 unsigned int RT5616_D_GATE_EN ; 
#define  RT5616_D_MISC 214 
#define  RT5616_EQ_CTRL1 213 
#define  RT5616_EQ_CTRL2 212 
#define  RT5616_GLB_CLK 211 
#define  RT5616_GPIO_CTRL1 210 
#define  RT5616_GPIO_CTRL2 209 
#define  RT5616_GPIO_CTRL3 208 
 unsigned int RT5616_HPD_PS_DIS ; 
 unsigned int RT5616_HPD_PS_EN ; 
 unsigned int RT5616_HPD_PS_MASK ; 
#define  RT5616_HPO_MIXER 207 
#define  RT5616_HP_CALIB2 206 
#define  RT5616_HP_CALIB_AMP_DET 205 
 unsigned int RT5616_HP_CB_MASK ; 
 unsigned int RT5616_HP_CB_PD ; 
 unsigned int RT5616_HP_CB_PU ; 
 unsigned int RT5616_HP_CD_PD_EN ; 
 unsigned int RT5616_HP_CD_PD_MASK ; 
 unsigned int RT5616_HP_CO_DIS ; 
 unsigned int RT5616_HP_CO_EN ; 
 unsigned int RT5616_HP_CO_MASK ; 
 unsigned int RT5616_HP_CP_MASK ; 
 unsigned int RT5616_HP_CP_PD ; 
 unsigned int RT5616_HP_CP_PU ; 
 int const RT5616_HP_DCC_INT1 ; 
 unsigned int RT5616_HP_L_SMT_DIS ; 
 unsigned int RT5616_HP_L_SMT_EN ; 
 unsigned int RT5616_HP_L_SMT_MASK ; 
#define  RT5616_HP_OVCD 204 
 unsigned int RT5616_HP_R_SMT_DIS ; 
 unsigned int RT5616_HP_R_SMT_EN ; 
 unsigned int RT5616_HP_R_SMT_MASK ; 
 unsigned int RT5616_HP_SG_DIS ; 
 unsigned int RT5616_HP_SG_EN ; 
 unsigned int RT5616_HP_SG_MASK ; 
#define  RT5616_HP_VOL 203 
#define  RT5616_I2S1_SDP 202 
 unsigned int RT5616_I2S_BP_INV ; 
 unsigned int RT5616_I2S_BP_MASK ; 
 unsigned int RT5616_I2S_DF_LEFT ; 
 unsigned int RT5616_I2S_DF_MASK ; 
 unsigned int RT5616_I2S_DF_PCM_A ; 
 unsigned int RT5616_I2S_DF_PCM_B ; 
 unsigned int RT5616_I2S_DL_20 ; 
 unsigned int RT5616_I2S_DL_24 ; 
 unsigned int RT5616_I2S_DL_8 ; 
 unsigned int RT5616_I2S_DL_MASK ; 
 unsigned int RT5616_I2S_MS_MASK ; 
 unsigned int RT5616_I2S_MS_S ; 
 unsigned int RT5616_I2S_PD1_MASK ; 
 int RT5616_I2S_PD1_SFT ; 
#define  RT5616_IN1_IN2 201 
#define  RT5616_INL1_INR1_VOL 200 
#define  RT5616_INT_IRQ_ST 199 
#define  RT5616_IRQ_CTRL1 198 
#define  RT5616_IRQ_CTRL2 197 
#define  RT5616_JD_CTRL1 196 
#define  RT5616_JD_CTRL2 195 
#define  RT5616_LOUT_CTRL1 194 
#define  RT5616_LOUT_CTRL2 193 
#define  RT5616_LOUT_MIXER 192 
 unsigned int RT5616_L_MUTE ; 
 int const RT5616_MAMP_INT_REG2 ; 
#define  RT5616_MICBIAS 191 
#define  RT5616_MP3_PLUS1 190 
#define  RT5616_MP3_PLUS2 189 
#define  RT5616_OUT_L1_MIXER 188 
#define  RT5616_OUT_L2_MIXER 187 
#define  RT5616_OUT_L3_MIXER 186 
#define  RT5616_OUT_R1_MIXER 185 
#define  RT5616_OUT_R2_MIXER 184 
#define  RT5616_OUT_R3_MIXER 183 
#define  RT5616_PGM_REG_ARR1 182 
#define  RT5616_PGM_REG_ARR2 181 
#define  RT5616_PGM_REG_ARR3 180 
#define  RT5616_PGM_REG_ARR4 179 
#define  RT5616_PGM_REG_ARR5 178 
 unsigned int RT5616_PLL1_SRC_BCLK1 ; 
 unsigned int RT5616_PLL1_SRC_MASK ; 
 unsigned int RT5616_PLL1_SRC_MCLK ; 
#define  RT5616_PLL1_S_BCLK1 177 
#define  RT5616_PLL1_S_BCLK2 176 
#define  RT5616_PLL1_S_MCLK 175 
#define  RT5616_PLL_CTRL1 174 
#define  RT5616_PLL_CTRL2 173 
 int RT5616_PLL_M_BP_SFT ; 
 int RT5616_PLL_M_SFT ; 
 int RT5616_PLL_N_SFT ; 
 unsigned int RT5616_PM_HP_HV ; 
 unsigned int RT5616_PM_HP_MASK ; 
#define  RT5616_PRIV_DATA 172 
#define  RT5616_PRIV_INDEX 171 
 int const RT5616_PR_BASE ; 
#define  RT5616_PV_DET_SPK_G 170 
#define  RT5616_PWR_ANLG1 169 
#define  RT5616_PWR_ANLG2 168 
 unsigned int RT5616_PWR_BG ; 
 unsigned int RT5616_PWR_BST1_OP2 ; 
 unsigned int RT5616_PWR_BST2_OP2 ; 
#define  RT5616_PWR_DIG1 167 
#define  RT5616_PWR_DIG2 166 
 unsigned int RT5616_PWR_FV1 ; 
 unsigned int RT5616_PWR_FV2 ; 
 unsigned int RT5616_PWR_HA ; 
 unsigned int RT5616_PWR_HP_L ; 
 unsigned int RT5616_PWR_HP_R ; 
 unsigned int RT5616_PWR_HV_L ; 
 unsigned int RT5616_PWR_HV_R ; 
 unsigned int RT5616_PWR_LDO_DVO_1_2V ; 
 unsigned int RT5616_PWR_LDO_DVO_MASK ; 
 unsigned int RT5616_PWR_LM ; 
 unsigned int RT5616_PWR_MB ; 
#define  RT5616_PWR_MIXER 165 
#define  RT5616_PWR_VOL 164 
 unsigned int RT5616_PWR_VREF1 ; 
 unsigned int RT5616_PWR_VREF2 ; 
#define  RT5616_REC_L1_MIXER 163 
#define  RT5616_REC_L2_MIXER 162 
#define  RT5616_REC_R1_MIXER 161 
#define  RT5616_REC_R2_MIXER 160 
#define  RT5616_RESET 159 
 unsigned int RT5616_RSTN_DIS ; 
 unsigned int RT5616_RSTN_EN ; 
 unsigned int RT5616_RSTN_MASK ; 
 unsigned int RT5616_RSTP_DIS ; 
 unsigned int RT5616_RSTP_EN ; 
 unsigned int RT5616_RSTP_MASK ; 
 unsigned int RT5616_R_MUTE ; 
#define  RT5616_SCB_CTRL 158 
#define  RT5616_SCB_FUNC 157 
 unsigned int RT5616_SCLK_SRC_MASK ; 
 unsigned int RT5616_SCLK_SRC_MCLK ; 
 unsigned int RT5616_SCLK_SRC_PLL1 ; 
#define  RT5616_SCLK_S_MCLK 156 
#define  RT5616_SCLK_S_PLL1 155 
 unsigned int RT5616_SMT_TRIG_DIS ; 
 unsigned int RT5616_SMT_TRIG_EN ; 
 unsigned int RT5616_SMT_TRIG_MASK ; 
#define  RT5616_STO1_ADC_MIXER 154 
#define  RT5616_STO_DAC_MIXER 153 
#define  RT5616_SVOL_ZC 152 
#define  RT5616_SV_ZCD1 151 
#define  RT5616_SV_ZCD2 150 
#define  RT5616_VENDOR_ID 149 
#define  RT5616_VERSION_ID 148 
#define  RT5616_WIND_FILTER 147 
#define  SNDRV_PCM_FORMAT_S16_LE 146 
#define  SNDRV_PCM_FORMAT_S20_3LE 145 
#define  SNDRV_PCM_FORMAT_S24_LE 144 
#define  SNDRV_PCM_FORMAT_S8 143 
#define  SND_SOC_BIAS_OFF 142 
#define  SND_SOC_BIAS_ON 141 
#define  SND_SOC_BIAS_PREPARE 140 
#define  SND_SOC_BIAS_STANDBY 139 
#define  SND_SOC_DAIFMT_CBM_CFM 138 
#define  SND_SOC_DAIFMT_CBS_CFS 137 
#define  SND_SOC_DAIFMT_DSP_A 136 
#define  SND_SOC_DAIFMT_DSP_B 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_NF 133 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 132 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 131 
#define  SND_SOC_DAPM_POST_PMD 130 
#define  SND_SOC_DAPM_POST_PMU 129 
#define  SND_SOC_DAPM_PRE_PMD 128 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 struct rt5616_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 struct rt5616_priv* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct rt5616_priv*) ; 
 TYPE_1__* init_list ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_format (struct snd_pcm_hw_params*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int const,unsigned int*) ; 
 int regmap_register_patch (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int const,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int const,int) ; 
 int rl6231_get_clk_info (unsigned int,int) ; 
 int rl6231_pll_calc (unsigned int,unsigned int,struct rl6231_pll_code*) ; 
 TYPE_1__* rt5616_dai ; 
 TYPE_1__* rt5616_ranges ; 
 int /*<<< orphan*/  rt5616_regmap ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct rt5616_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 unsigned int snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int const,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int snd_soc_params_to_frame_size (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  soc_component_dev_rt5616 ; 

__attribute__((used)) static bool rt5616_volatile_register(struct device *dev, unsigned int reg)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(rt5616_ranges); i++) {
		if (reg >= rt5616_ranges[i].range_min &&
		    reg <= rt5616_ranges[i].range_max)
			return true;
	}

	switch (reg) {
	case RT5616_RESET:
	case RT5616_PRIV_DATA:
	case RT5616_EQ_CTRL1:
	case RT5616_DRC_AGC_1:
	case RT5616_IRQ_CTRL2:
	case RT5616_INT_IRQ_ST:
	case RT5616_PGM_REG_ARR1:
	case RT5616_PGM_REG_ARR3:
	case RT5616_VENDOR_ID:
	case RT5616_DEVICE_ID:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool rt5616_readable_register(struct device *dev, unsigned int reg)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(rt5616_ranges); i++) {
		if (reg >= rt5616_ranges[i].range_min &&
		    reg <= rt5616_ranges[i].range_max)
			return true;
	}

	switch (reg) {
	case RT5616_RESET:
	case RT5616_VERSION_ID:
	case RT5616_VENDOR_ID:
	case RT5616_DEVICE_ID:
	case RT5616_HP_VOL:
	case RT5616_LOUT_CTRL1:
	case RT5616_LOUT_CTRL2:
	case RT5616_IN1_IN2:
	case RT5616_INL1_INR1_VOL:
	case RT5616_DAC1_DIG_VOL:
	case RT5616_ADC_DIG_VOL:
	case RT5616_ADC_BST_VOL:
	case RT5616_STO1_ADC_MIXER:
	case RT5616_AD_DA_MIXER:
	case RT5616_STO_DAC_MIXER:
	case RT5616_REC_L1_MIXER:
	case RT5616_REC_L2_MIXER:
	case RT5616_REC_R1_MIXER:
	case RT5616_REC_R2_MIXER:
	case RT5616_HPO_MIXER:
	case RT5616_OUT_L1_MIXER:
	case RT5616_OUT_L2_MIXER:
	case RT5616_OUT_L3_MIXER:
	case RT5616_OUT_R1_MIXER:
	case RT5616_OUT_R2_MIXER:
	case RT5616_OUT_R3_MIXER:
	case RT5616_LOUT_MIXER:
	case RT5616_PWR_DIG1:
	case RT5616_PWR_DIG2:
	case RT5616_PWR_ANLG1:
	case RT5616_PWR_ANLG2:
	case RT5616_PWR_MIXER:
	case RT5616_PWR_VOL:
	case RT5616_PRIV_INDEX:
	case RT5616_PRIV_DATA:
	case RT5616_I2S1_SDP:
	case RT5616_ADDA_CLK1:
	case RT5616_ADDA_CLK2:
	case RT5616_GLB_CLK:
	case RT5616_PLL_CTRL1:
	case RT5616_PLL_CTRL2:
	case RT5616_HP_OVCD:
	case RT5616_DEPOP_M1:
	case RT5616_DEPOP_M2:
	case RT5616_DEPOP_M3:
	case RT5616_CHARGE_PUMP:
	case RT5616_PV_DET_SPK_G:
	case RT5616_MICBIAS:
	case RT5616_A_JD_CTL1:
	case RT5616_A_JD_CTL2:
	case RT5616_EQ_CTRL1:
	case RT5616_EQ_CTRL2:
	case RT5616_WIND_FILTER:
	case RT5616_DRC_AGC_1:
	case RT5616_DRC_AGC_2:
	case RT5616_DRC_AGC_3:
	case RT5616_SVOL_ZC:
	case RT5616_JD_CTRL1:
	case RT5616_JD_CTRL2:
	case RT5616_IRQ_CTRL1:
	case RT5616_IRQ_CTRL2:
	case RT5616_INT_IRQ_ST:
	case RT5616_GPIO_CTRL1:
	case RT5616_GPIO_CTRL2:
	case RT5616_GPIO_CTRL3:
	case RT5616_PGM_REG_ARR1:
	case RT5616_PGM_REG_ARR2:
	case RT5616_PGM_REG_ARR3:
	case RT5616_PGM_REG_ARR4:
	case RT5616_PGM_REG_ARR5:
	case RT5616_SCB_FUNC:
	case RT5616_SCB_CTRL:
	case RT5616_BASE_BACK:
	case RT5616_MP3_PLUS1:
	case RT5616_MP3_PLUS2:
	case RT5616_ADJ_HPF_CTRL1:
	case RT5616_ADJ_HPF_CTRL2:
	case RT5616_HP_CALIB_AMP_DET:
	case RT5616_HP_CALIB2:
	case RT5616_SV_ZCD1:
	case RT5616_SV_ZCD2:
	case RT5616_D_MISC:
	case RT5616_DUMMY2:
	case RT5616_DUMMY3:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
			       struct snd_soc_dapm_widget *sink)
{
	unsigned int val;

	val = snd_soc_component_read32(snd_soc_dapm_to_component(source->dapm), RT5616_GLB_CLK);
	val &= RT5616_SCLK_SRC_MASK;
	if (val == RT5616_SCLK_SRC_PLL1)
		return 1;
	else
		return 0;
}

__attribute__((used)) static int rt5616_adc_event(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, RT5616_ADC_DIG_VOL,
				    RT5616_L_MUTE | RT5616_R_MUTE, 0);
		break;

	case SND_SOC_DAPM_POST_PMD:
		snd_soc_component_update_bits(component, RT5616_ADC_DIG_VOL,
				    RT5616_L_MUTE | RT5616_R_MUTE,
				    RT5616_L_MUTE | RT5616_R_MUTE);
		break;

	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5616_charge_pump_event(struct snd_soc_dapm_widget *w,
				    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* depop parameters */
		snd_soc_component_update_bits(component, RT5616_DEPOP_M2,
				    RT5616_DEPOP_MASK, RT5616_DEPOP_MAN);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_HP_CP_MASK | RT5616_HP_SG_MASK |
				    RT5616_HP_CB_MASK, RT5616_HP_CP_PU |
				    RT5616_HP_SG_DIS | RT5616_HP_CB_PU);
		snd_soc_component_write(component, RT5616_PR_BASE +
			      RT5616_HP_DCC_INT1, 0x9f00);
		/* headphone amp power on */
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
				    RT5616_PWR_FV1 | RT5616_PWR_FV2, 0);
		snd_soc_component_update_bits(component, RT5616_PWR_VOL,
				    RT5616_PWR_HV_L | RT5616_PWR_HV_R,
				    RT5616_PWR_HV_L | RT5616_PWR_HV_R);
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
				    RT5616_PWR_HP_L | RT5616_PWR_HP_R |
				    RT5616_PWR_HA, RT5616_PWR_HP_L |
				    RT5616_PWR_HP_R | RT5616_PWR_HA);
		msleep(50);
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
				    RT5616_PWR_FV1 | RT5616_PWR_FV2,
				    RT5616_PWR_FV1 | RT5616_PWR_FV2);

		snd_soc_component_update_bits(component, RT5616_CHARGE_PUMP,
				    RT5616_PM_HP_MASK, RT5616_PM_HP_HV);
		snd_soc_component_update_bits(component, RT5616_PR_BASE +
				    RT5616_CHOP_DAC_ADC, 0x0200, 0x0200);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_HP_CO_MASK | RT5616_HP_SG_MASK,
				    RT5616_HP_CO_EN | RT5616_HP_SG_EN);
		break;
	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, RT5616_PR_BASE +
				    RT5616_CHOP_DAC_ADC, 0x0200, 0x0);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_HP_SG_MASK | RT5616_HP_L_SMT_MASK |
				    RT5616_HP_R_SMT_MASK, RT5616_HP_SG_DIS |
				    RT5616_HP_L_SMT_DIS | RT5616_HP_R_SMT_DIS);
		/* headphone amp power down */
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_SMT_TRIG_MASK |
				    RT5616_HP_CD_PD_MASK | RT5616_HP_CO_MASK |
				    RT5616_HP_CP_MASK | RT5616_HP_SG_MASK |
				    RT5616_HP_CB_MASK,
				    RT5616_SMT_TRIG_DIS | RT5616_HP_CD_PD_EN |
				    RT5616_HP_CO_DIS | RT5616_HP_CP_PD |
				    RT5616_HP_SG_EN | RT5616_HP_CB_PD);
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
				    RT5616_PWR_HP_L | RT5616_PWR_HP_R |
				    RT5616_PWR_HA, 0);
		break;
	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5616_hp_event(struct snd_soc_dapm_widget *w,
			   struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* headphone unmute sequence */
		snd_soc_component_update_bits(component, RT5616_DEPOP_M3,
				    RT5616_CP_FQ1_MASK | RT5616_CP_FQ2_MASK |
				    RT5616_CP_FQ3_MASK,
				    RT5616_CP_FQ_192_KHZ << RT5616_CP_FQ1_SFT |
				    RT5616_CP_FQ_12_KHZ << RT5616_CP_FQ2_SFT |
				    RT5616_CP_FQ_192_KHZ << RT5616_CP_FQ3_SFT);
		snd_soc_component_write(component, RT5616_PR_BASE +
			      RT5616_MAMP_INT_REG2, 0xfc00);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_SMT_TRIG_MASK, RT5616_SMT_TRIG_EN);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_RSTN_MASK, RT5616_RSTN_EN);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_RSTN_MASK | RT5616_HP_L_SMT_MASK |
				    RT5616_HP_R_SMT_MASK, RT5616_RSTN_DIS |
				    RT5616_HP_L_SMT_EN | RT5616_HP_R_SMT_EN);
		snd_soc_component_update_bits(component, RT5616_HP_VOL,
				    RT5616_L_MUTE | RT5616_R_MUTE, 0);
		msleep(100);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_HP_SG_MASK | RT5616_HP_L_SMT_MASK |
				    RT5616_HP_R_SMT_MASK, RT5616_HP_SG_DIS |
				    RT5616_HP_L_SMT_DIS | RT5616_HP_R_SMT_DIS);
		msleep(20);
		snd_soc_component_update_bits(component, RT5616_HP_CALIB_AMP_DET,
				    RT5616_HPD_PS_MASK, RT5616_HPD_PS_EN);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		/* headphone mute sequence */
		snd_soc_component_update_bits(component, RT5616_DEPOP_M3,
				    RT5616_CP_FQ1_MASK | RT5616_CP_FQ2_MASK |
				    RT5616_CP_FQ3_MASK,
				    RT5616_CP_FQ_96_KHZ << RT5616_CP_FQ1_SFT |
				    RT5616_CP_FQ_12_KHZ << RT5616_CP_FQ2_SFT |
				    RT5616_CP_FQ_96_KHZ << RT5616_CP_FQ3_SFT);
		snd_soc_component_write(component, RT5616_PR_BASE +
			      RT5616_MAMP_INT_REG2, 0xfc00);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_HP_SG_MASK, RT5616_HP_SG_EN);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_RSTP_MASK, RT5616_RSTP_EN);
		snd_soc_component_update_bits(component, RT5616_DEPOP_M1,
				    RT5616_RSTP_MASK | RT5616_HP_L_SMT_MASK |
				    RT5616_HP_R_SMT_MASK, RT5616_RSTP_DIS |
				    RT5616_HP_L_SMT_EN | RT5616_HP_R_SMT_EN);
		snd_soc_component_update_bits(component, RT5616_HP_CALIB_AMP_DET,
				    RT5616_HPD_PS_MASK, RT5616_HPD_PS_DIS);
		msleep(90);
		snd_soc_component_update_bits(component, RT5616_HP_VOL,
				    RT5616_L_MUTE | RT5616_R_MUTE,
				    RT5616_L_MUTE | RT5616_R_MUTE);
		msleep(30);
		break;

	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5616_lout_event(struct snd_soc_dapm_widget *w,
			     struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
				    RT5616_PWR_LM, RT5616_PWR_LM);
		snd_soc_component_update_bits(component, RT5616_LOUT_CTRL1,
				    RT5616_L_MUTE | RT5616_R_MUTE, 0);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, RT5616_LOUT_CTRL1,
				    RT5616_L_MUTE | RT5616_R_MUTE,
				    RT5616_L_MUTE | RT5616_R_MUTE);
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
				    RT5616_PWR_LM, 0);
		break;

	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5616_bst1_event(struct snd_soc_dapm_widget *w,
			     struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG2,
				    RT5616_PWR_BST1_OP2, RT5616_PWR_BST1_OP2);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG2,
				    RT5616_PWR_BST1_OP2, 0);
		break;

	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5616_bst2_event(struct snd_soc_dapm_widget *w,
			     struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG2,
				    RT5616_PWR_BST2_OP2, RT5616_PWR_BST2_OP2);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, RT5616_PWR_ANLG2,
				    RT5616_PWR_BST2_OP2, 0);
		break;

	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5616_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct rt5616_priv *rt5616 = snd_soc_component_get_drvdata(component);
	unsigned int val_len = 0, val_clk, mask_clk;
	int pre_div, bclk_ms, frame_size;

	rt5616->lrck[dai->id] = params_rate(params);

	pre_div = rl6231_get_clk_info(rt5616->sysclk, rt5616->lrck[dai->id]);

	if (pre_div < 0) {
		dev_err(component->dev, "Unsupported clock setting\n");
		return -EINVAL;
	}
	frame_size = snd_soc_params_to_frame_size(params);
	if (frame_size < 0) {
		dev_err(component->dev, "Unsupported frame size: %d\n", frame_size);
		return -EINVAL;
	}
	bclk_ms = frame_size > 32 ? 1 : 0;
	rt5616->bclk[dai->id] = rt5616->lrck[dai->id] * (32 << bclk_ms);

	dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
		rt5616->bclk[dai->id], rt5616->lrck[dai->id]);
	dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
		bclk_ms, pre_div, dai->id);

	switch (params_format(params)) {
	case SNDRV_PCM_FORMAT_S16_LE:
		break;
	case SNDRV_PCM_FORMAT_S20_3LE:
		val_len |= RT5616_I2S_DL_20;
		break;
	case SNDRV_PCM_FORMAT_S24_LE:
		val_len |= RT5616_I2S_DL_24;
		break;
	case SNDRV_PCM_FORMAT_S8:
		val_len |= RT5616_I2S_DL_8;
		break;
	default:
		return -EINVAL;
	}

	mask_clk = RT5616_I2S_PD1_MASK;
	val_clk = pre_div << RT5616_I2S_PD1_SFT;
	snd_soc_component_update_bits(component, RT5616_I2S1_SDP,
			    RT5616_I2S_DL_MASK, val_len);
	snd_soc_component_update_bits(component, RT5616_ADDA_CLK1, mask_clk, val_clk);

	return 0;
}

__attribute__((used)) static int rt5616_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct rt5616_priv *rt5616 = snd_soc_component_get_drvdata(component);
	unsigned int reg_val = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		rt5616->master[dai->id] = 1;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		reg_val |= RT5616_I2S_MS_S;
		rt5616->master[dai->id] = 0;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_NF:
		reg_val |= RT5616_I2S_BP_INV;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		reg_val |= RT5616_I2S_DF_LEFT;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		reg_val |= RT5616_I2S_DF_PCM_A;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		reg_val |= RT5616_I2S_DF_PCM_B;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, RT5616_I2S1_SDP,
			    RT5616_I2S_MS_MASK | RT5616_I2S_BP_MASK |
			    RT5616_I2S_DF_MASK, reg_val);

	return 0;
}

__attribute__((used)) static int rt5616_set_dai_sysclk(struct snd_soc_dai *dai,
				 int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = dai->component;
	struct rt5616_priv *rt5616 = snd_soc_component_get_drvdata(component);
	unsigned int reg_val = 0;

	if (freq == rt5616->sysclk && clk_id == rt5616->sysclk_src)
		return 0;

	switch (clk_id) {
	case RT5616_SCLK_S_MCLK:
		reg_val |= RT5616_SCLK_SRC_MCLK;
		break;
	case RT5616_SCLK_S_PLL1:
		reg_val |= RT5616_SCLK_SRC_PLL1;
		break;
	default:
		dev_err(component->dev, "Invalid clock id (%d)\n", clk_id);
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, RT5616_GLB_CLK,
			    RT5616_SCLK_SRC_MASK, reg_val);
	rt5616->sysclk = freq;
	rt5616->sysclk_src = clk_id;

	dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);

	return 0;
}

__attribute__((used)) static int rt5616_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
			      unsigned int freq_in, unsigned int freq_out)
{
	struct snd_soc_component *component = dai->component;
	struct rt5616_priv *rt5616 = snd_soc_component_get_drvdata(component);
	struct rl6231_pll_code pll_code;
	int ret;

	if (source == rt5616->pll_src && freq_in == rt5616->pll_in &&
	    freq_out == rt5616->pll_out)
		return 0;

	if (!freq_in || !freq_out) {
		dev_dbg(component->dev, "PLL disabled\n");

		rt5616->pll_in = 0;
		rt5616->pll_out = 0;
		snd_soc_component_update_bits(component, RT5616_GLB_CLK,
				    RT5616_SCLK_SRC_MASK,
				    RT5616_SCLK_SRC_MCLK);
		return 0;
	}

	switch (source) {
	case RT5616_PLL1_S_MCLK:
		snd_soc_component_update_bits(component, RT5616_GLB_CLK,
				    RT5616_PLL1_SRC_MASK,
				    RT5616_PLL1_SRC_MCLK);
		break;
	case RT5616_PLL1_S_BCLK1:
	case RT5616_PLL1_S_BCLK2:
		snd_soc_component_update_bits(component, RT5616_GLB_CLK,
				    RT5616_PLL1_SRC_MASK,
				    RT5616_PLL1_SRC_BCLK1);
		break;
	default:
		dev_err(component->dev, "Unknown PLL source %d\n", source);
		return -EINVAL;
	}

	ret = rl6231_pll_calc(freq_in, freq_out, &pll_code);
	if (ret < 0) {
		dev_err(component->dev, "Unsupport input clock %d\n", freq_in);
		return ret;
	}

	dev_dbg(component->dev, "bypass=%d m=%d n=%d k=%d\n",
		pll_code.m_bp, (pll_code.m_bp ? 0 : pll_code.m_code),
		pll_code.n_code, pll_code.k_code);

	snd_soc_component_write(component, RT5616_PLL_CTRL1,
		      pll_code.n_code << RT5616_PLL_N_SFT | pll_code.k_code);
	snd_soc_component_write(component, RT5616_PLL_CTRL2,
		      (pll_code.m_bp ? 0 : pll_code.m_code) <<
		      RT5616_PLL_M_SFT |
		      pll_code.m_bp << RT5616_PLL_M_BP_SFT);

	rt5616->pll_in = freq_in;
	rt5616->pll_out = freq_out;
	rt5616->pll_src = source;

	return 0;
}

__attribute__((used)) static int rt5616_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct rt5616_priv *rt5616 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {

	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		/*
		 * SND_SOC_BIAS_PREPARE is called while preparing for a
		 * transition to ON or away from ON. If current bias_level
		 * is SND_SOC_BIAS_ON, then it is preparing for a transition
		 * away from ON. Disable the clock in that case, otherwise
		 * enable it.
		 */
		if (IS_ERR(rt5616->mclk))
			break;

		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_ON) {
			clk_disable_unprepare(rt5616->mclk);
		} else {
			ret = clk_prepare_enable(rt5616->mclk);
			if (ret)
				return ret;
		}
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
					    RT5616_PWR_VREF1 | RT5616_PWR_MB |
					    RT5616_PWR_BG | RT5616_PWR_VREF2,
					    RT5616_PWR_VREF1 | RT5616_PWR_MB |
					    RT5616_PWR_BG | RT5616_PWR_VREF2);
			mdelay(10);
			snd_soc_component_update_bits(component, RT5616_PWR_ANLG1,
					    RT5616_PWR_FV1 | RT5616_PWR_FV2,
					    RT5616_PWR_FV1 | RT5616_PWR_FV2);
			snd_soc_component_update_bits(component, RT5616_D_MISC,
					    RT5616_D_GATE_EN,
					    RT5616_D_GATE_EN);
		}
		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, RT5616_D_MISC, RT5616_D_GATE_EN, 0);
		snd_soc_component_write(component, RT5616_PWR_DIG1, 0x0000);
		snd_soc_component_write(component, RT5616_PWR_DIG2, 0x0000);
		snd_soc_component_write(component, RT5616_PWR_VOL, 0x0000);
		snd_soc_component_write(component, RT5616_PWR_MIXER, 0x0000);
		snd_soc_component_write(component, RT5616_PWR_ANLG1, 0x0000);
		snd_soc_component_write(component, RT5616_PWR_ANLG2, 0x0000);
		break;

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int rt5616_probe(struct snd_soc_component *component)
{
	struct rt5616_priv *rt5616 = snd_soc_component_get_drvdata(component);

	/* Check if MCLK provided */
	rt5616->mclk = devm_clk_get(component->dev, "mclk");
	if (PTR_ERR(rt5616->mclk) == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	rt5616->component = component;

	return 0;
}

__attribute__((used)) static int rt5616_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct rt5616_priv *rt5616;
	unsigned int val;
	int ret;

	rt5616 = devm_kzalloc(&i2c->dev, sizeof(struct rt5616_priv),
			      GFP_KERNEL);
	if (!rt5616)
		return -ENOMEM;

	i2c_set_clientdata(i2c, rt5616);

	rt5616->regmap = devm_regmap_init_i2c(i2c, &rt5616_regmap);
	if (IS_ERR(rt5616->regmap)) {
		ret = PTR_ERR(rt5616->regmap);
		dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	regmap_read(rt5616->regmap, RT5616_DEVICE_ID, &val);
	if (val != 0x6281) {
		dev_err(&i2c->dev,
			"Device with ID register %#x is not rt5616\n",
			val);
		return -ENODEV;
	}
	regmap_write(rt5616->regmap, RT5616_RESET, 0);
	regmap_update_bits(rt5616->regmap, RT5616_PWR_ANLG1,
			   RT5616_PWR_VREF1 | RT5616_PWR_MB |
			   RT5616_PWR_BG | RT5616_PWR_VREF2,
			   RT5616_PWR_VREF1 | RT5616_PWR_MB |
			   RT5616_PWR_BG | RT5616_PWR_VREF2);
	mdelay(10);
	regmap_update_bits(rt5616->regmap, RT5616_PWR_ANLG1,
			   RT5616_PWR_FV1 | RT5616_PWR_FV2,
			   RT5616_PWR_FV1 | RT5616_PWR_FV2);

	ret = regmap_register_patch(rt5616->regmap, init_list,
				    ARRAY_SIZE(init_list));
	if (ret != 0)
		dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);

	regmap_update_bits(rt5616->regmap, RT5616_PWR_ANLG1,
			   RT5616_PWR_LDO_DVO_MASK, RT5616_PWR_LDO_DVO_1_2V);

	return devm_snd_soc_register_component(&i2c->dev,
				      &soc_component_dev_rt5616,
				      rt5616_dai, ARRAY_SIZE(rt5616_dai));
}

__attribute__((used)) static int rt5616_i2c_remove(struct i2c_client *i2c)
{
	return 0;
}

__attribute__((used)) static void rt5616_i2c_shutdown(struct i2c_client *client)
{
	struct rt5616_priv *rt5616 = i2c_get_clientdata(client);

	regmap_write(rt5616->regmap, RT5616_HP_VOL, 0xc8c8);
	regmap_write(rt5616->regmap, RT5616_LOUT_CTRL1, 0xc8c8);
}


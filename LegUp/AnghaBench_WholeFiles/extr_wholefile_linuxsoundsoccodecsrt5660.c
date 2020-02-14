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
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct rt5660_platform_data {scalar_t__ dmic1_data_pin; void* poweroff_codec_in_suspend; void* in3_diff; void* in1_diff; } ;
struct rt5660_priv {int sysclk; int* lrck; int* bclk; int* master; int sysclk_src; int pll_src; unsigned int pll_in; unsigned int pll_out; int /*<<< orphan*/  regmap; struct rt5660_platform_data pdata; int /*<<< orphan*/  mclk; struct snd_soc_component* component; } ;
struct rl6231_pll_code {int m_bp; int m_code; int n_code; int k_code; } ;
struct i2c_device_id {int dummy; } ;
struct device {scalar_t__ of_node; } ;
struct i2c_client {struct device dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_7__ {unsigned int window_start; unsigned int window_len; unsigned int range_min; unsigned int range_max; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  RT5660_ADC_BST_VOL1 246 
#define  RT5660_ADDA_CLK1 245 
#define  RT5660_ADDA_CLK2 244 
#define  RT5660_AD_DA_MIXER 243 
#define  RT5660_AIF1 242 
#define  RT5660_ALC_PGA_CTRL1 241 
#define  RT5660_ALC_PGA_CTRL2 240 
#define  RT5660_ALC_PGA_CTRL3 239 
#define  RT5660_ALC_PGA_CTRL4 238 
#define  RT5660_ALC_PGA_CTRL5 237 
#define  RT5660_ALC_PGA_CTRL6 236 
#define  RT5660_ALC_PGA_CTRL7 235 
 int RT5660_AUTO_DIS_AMP ; 
#define  RT5660_CLSD_AMP_CTRL 234 
#define  RT5660_CLSD_AMP_OC_CTRL 233 
#define  RT5660_CLSD_OUT_CTRL1 232 
#define  RT5660_CLSD_OUT_CTRL2 231 
#define  RT5660_DAC1_DIG_VOL 230 
 unsigned int RT5660_DEVICE_ID ; 
 unsigned int RT5660_DIG_GATE_CTRL ; 
#define  RT5660_DIG_INF1_DATA 229 
#define  RT5660_DIPOLE_MIC_CTRL1 228 
#define  RT5660_DIPOLE_MIC_CTRL10 227 
#define  RT5660_DIPOLE_MIC_CTRL11 226 
#define  RT5660_DIPOLE_MIC_CTRL12 225 
#define  RT5660_DIPOLE_MIC_CTRL2 224 
#define  RT5660_DIPOLE_MIC_CTRL3 223 
#define  RT5660_DIPOLE_MIC_CTRL4 222 
#define  RT5660_DIPOLE_MIC_CTRL5 221 
#define  RT5660_DIPOLE_MIC_CTRL6 220 
#define  RT5660_DIPOLE_MIC_CTRL7 219 
#define  RT5660_DIPOLE_MIC_CTRL8 218 
#define  RT5660_DIPOLE_MIC_CTRL9 217 
 scalar_t__ RT5660_DMIC1_DATA_GPIO2 ; 
 scalar_t__ RT5660_DMIC1_DATA_IN1P ; 
 unsigned int RT5660_DMIC_CLK_MASK ; 
 int RT5660_DMIC_CLK_SFT ; 
#define  RT5660_DMIC_CTRL1 216 
#define  RT5660_DRC1_LM_CTRL1 215 
#define  RT5660_DRC1_LM_CTRL2 214 
#define  RT5660_DRC2_CTRL1 213 
#define  RT5660_DRC2_CTRL2 212 
#define  RT5660_DRC2_CTRL3 211 
#define  RT5660_DRC2_CTRL4 210 
#define  RT5660_DRC2_CTRL5 209 
#define  RT5660_DRC2_LM_CTRL1 208 
#define  RT5660_DRC2_LM_CTRL2 207 
#define  RT5660_DRC_AGC_CTRL1 206 
#define  RT5660_DRC_AGC_CTRL2 205 
#define  RT5660_DRC_AGC_CTRL3 204 
#define  RT5660_DRC_AGC_CTRL4 203 
#define  RT5660_DRC_AGC_CTRL5 202 
#define  RT5660_EQ_CTRL1 201 
#define  RT5660_EQ_CTRL2 200 
#define  RT5660_GEN_CTRL1 199 
#define  RT5660_GEN_CTRL2 198 
#define  RT5660_GEN_CTRL3 197 
#define  RT5660_GLB_CLK 196 
 int RT5660_GP1_PIN_DMIC1_SCL ; 
 int RT5660_GP1_PIN_MASK ; 
#define  RT5660_GPIO_CTRL1 195 
#define  RT5660_GPIO_CTRL2 194 
#define  RT5660_I2S1_SDP 193 
 unsigned int RT5660_I2S_BCLK_MS1_MASK ; 
 int RT5660_I2S_BCLK_MS1_SFT ; 
 unsigned int RT5660_I2S_BP_INV ; 
 unsigned int RT5660_I2S_BP_MASK ; 
 unsigned int RT5660_I2S_DF_LEFT ; 
 unsigned int RT5660_I2S_DF_MASK ; 
 unsigned int RT5660_I2S_DF_PCM_A ; 
 unsigned int RT5660_I2S_DF_PCM_B ; 
 unsigned int RT5660_I2S_DL_20 ; 
 unsigned int RT5660_I2S_DL_24 ; 
 unsigned int RT5660_I2S_DL_8 ; 
 unsigned int RT5660_I2S_DL_MASK ; 
 unsigned int RT5660_I2S_MS_MASK ; 
 unsigned int RT5660_I2S_MS_S ; 
 unsigned int RT5660_I2S_PD1_MASK ; 
 int RT5660_I2S_PD1_SFT ; 
#define  RT5660_IN1_IN2 192 
#define  RT5660_IN3_IN4 191 
#define  RT5660_INT_IRQ_ST 190 
#define  RT5660_IRQ_CTRL1 189 
#define  RT5660_IRQ_CTRL2 188 
#define  RT5660_JD_CTRL 187 
#define  RT5660_LOUT_AMP_CTRL 186 
 unsigned int RT5660_LOUT_CB_MASK ; 
 unsigned int RT5660_LOUT_CB_PD ; 
 unsigned int RT5660_LOUT_CB_PU ; 
 unsigned int RT5660_LOUT_CO_DIS ; 
 unsigned int RT5660_LOUT_CO_EN ; 
 unsigned int RT5660_LOUT_CO_MASK ; 
#define  RT5660_LOUT_MIXER 185 
#define  RT5660_LOUT_VOL 184 
 int RT5660_MCLK_DET ; 
#define  RT5660_MICBIAS 183 
#define  RT5660_MULTI_DRC_CTRL 182 
#define  RT5660_OUT_L1_MIXER 181 
#define  RT5660_OUT_L_GAIN1 180 
#define  RT5660_OUT_L_GAIN2 179 
#define  RT5660_OUT_R1_MIXER 178 
#define  RT5660_OUT_R_GAIN1 177 
#define  RT5660_OUT_R_GAIN2 176 
 unsigned int RT5660_PLL1_SRC_BCLK1 ; 
 unsigned int RT5660_PLL1_SRC_MASK ; 
 unsigned int RT5660_PLL1_SRC_MCLK ; 
#define  RT5660_PLL1_S_BCLK 175 
#define  RT5660_PLL1_S_MCLK 174 
#define  RT5660_PLL_CTRL1 173 
#define  RT5660_PLL_CTRL2 172 
 int RT5660_PLL_M_BP_SFT ; 
 int RT5660_PLL_M_SFT ; 
 int RT5660_PLL_N_SFT ; 
 int RT5660_POW_CLKDET ; 
#define  RT5660_PRIV_DATA 171 
#define  RT5660_PRIV_INDEX 170 
#define  RT5660_PWR_ANLG1 169 
#define  RT5660_PWR_ANLG2 168 
 unsigned int RT5660_PWR_BG ; 
#define  RT5660_PWR_DIG1 167 
#define  RT5660_PWR_DIG2 166 
 unsigned int RT5660_PWR_FV1 ; 
 unsigned int RT5660_PWR_FV2 ; 
 unsigned int RT5660_PWR_MB ; 
#define  RT5660_PWR_MIXER 165 
#define  RT5660_PWR_VOL 164 
 unsigned int RT5660_PWR_VREF1 ; 
 unsigned int RT5660_PWR_VREF2 ; 
#define  RT5660_REC_L1_MIXER 163 
#define  RT5660_REC_L2_MIXER 162 
#define  RT5660_REC_R1_MIXER 161 
#define  RT5660_REC_R2_MIXER 160 
#define  RT5660_RESET 159 
 unsigned int RT5660_SCLK_SRC_MASK ; 
 unsigned int RT5660_SCLK_SRC_MCLK ; 
 unsigned int RT5660_SCLK_SRC_PLL1 ; 
 unsigned int RT5660_SCLK_SRC_RCCLK ; 
#define  RT5660_SCLK_S_MCLK 158 
#define  RT5660_SCLK_S_PLL1 157 
#define  RT5660_SCLK_S_RCCLK 156 
 int RT5660_SEL_DMIC_DATA_GPIO2 ; 
 int RT5660_SEL_DMIC_DATA_IN1P ; 
 int RT5660_SEL_DMIC_DATA_MASK ; 
#define  RT5660_SPK_AMP_SPKVDD 155 
#define  RT5660_SPK_MIXER 154 
#define  RT5660_SPK_VOL 153 
#define  RT5660_SPO_CLSD_RATIO 152 
#define  RT5660_SPO_MIXER 151 
#define  RT5660_STO1_ADC_DIG_VOL 150 
#define  RT5660_STO1_ADC_MIXER 149 
#define  RT5660_STO_DAC_MIXER 148 
#define  RT5660_SV_ZCD1 147 
#define  RT5660_SV_ZCD2 146 
#define  RT5660_VENDOR_ID 145 
#define  RT5660_VENDOR_ID1 144 
#define  RT5660_VENDOR_ID2 143 
#define  RT5660_WIND_FILTER_CTRL1 142 
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
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 130 
#define  SND_SOC_DAPM_POST_PMU 129 
#define  SND_SOC_DAPM_PRE_PMD 128 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct rt5660_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 void* device_property_read_bool (struct device*,char*) ; 
 int /*<<< orphan*/  device_property_read_u32 (struct device*,char*,scalar_t__*) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,char*) ; 
 struct rt5660_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct rt5660_priv*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int const,unsigned int*) ; 
 int regmap_register_patch (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int const,int,int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int const,int /*<<< orphan*/ ) ; 
 int rl6231_calc_dmic_clk (int) ; 
 int rl6231_get_clk_info (int,int) ; 
 int rl6231_get_pre_div (int /*<<< orphan*/ ,int const,int) ; 
 int rl6231_pll_calc (unsigned int,unsigned int,struct rl6231_pll_code*) ; 
 TYPE_1__* rt5660_dai ; 
 TYPE_1__* rt5660_patch ; 
 TYPE_1__* rt5660_ranges ; 
 int /*<<< orphan*/  rt5660_regmap ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct rt5660_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 unsigned int snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int const,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int snd_soc_params_to_frame_size (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  soc_component_dev_rt5660 ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static bool rt5660_volatile_register(struct device *dev, unsigned int reg)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(rt5660_ranges); i++)
		if ((reg >= rt5660_ranges[i].window_start &&
		     reg <= rt5660_ranges[i].window_start +
		     rt5660_ranges[i].window_len) ||
		    (reg >= rt5660_ranges[i].range_min &&
		     reg <= rt5660_ranges[i].range_max))
			return true;

	switch (reg) {
	case RT5660_RESET:
	case RT5660_PRIV_DATA:
	case RT5660_EQ_CTRL1:
	case RT5660_IRQ_CTRL2:
	case RT5660_INT_IRQ_ST:
	case RT5660_VENDOR_ID:
	case RT5660_VENDOR_ID1:
	case RT5660_VENDOR_ID2:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool rt5660_readable_register(struct device *dev, unsigned int reg)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(rt5660_ranges); i++)
		if ((reg >= rt5660_ranges[i].window_start &&
		     reg <= rt5660_ranges[i].window_start +
		     rt5660_ranges[i].window_len) ||
		    (reg >= rt5660_ranges[i].range_min &&
		     reg <= rt5660_ranges[i].range_max))
			return true;

	switch (reg) {
	case RT5660_RESET:
	case RT5660_SPK_VOL:
	case RT5660_LOUT_VOL:
	case RT5660_IN1_IN2:
	case RT5660_IN3_IN4:
	case RT5660_DAC1_DIG_VOL:
	case RT5660_STO1_ADC_DIG_VOL:
	case RT5660_ADC_BST_VOL1:
	case RT5660_STO1_ADC_MIXER:
	case RT5660_AD_DA_MIXER:
	case RT5660_STO_DAC_MIXER:
	case RT5660_DIG_INF1_DATA:
	case RT5660_REC_L1_MIXER:
	case RT5660_REC_L2_MIXER:
	case RT5660_REC_R1_MIXER:
	case RT5660_REC_R2_MIXER:
	case RT5660_LOUT_MIXER:
	case RT5660_SPK_MIXER:
	case RT5660_SPO_MIXER:
	case RT5660_SPO_CLSD_RATIO:
	case RT5660_OUT_L_GAIN1:
	case RT5660_OUT_L_GAIN2:
	case RT5660_OUT_L1_MIXER:
	case RT5660_OUT_R_GAIN1:
	case RT5660_OUT_R_GAIN2:
	case RT5660_OUT_R1_MIXER:
	case RT5660_PWR_DIG1:
	case RT5660_PWR_DIG2:
	case RT5660_PWR_ANLG1:
	case RT5660_PWR_ANLG2:
	case RT5660_PWR_MIXER:
	case RT5660_PWR_VOL:
	case RT5660_PRIV_INDEX:
	case RT5660_PRIV_DATA:
	case RT5660_I2S1_SDP:
	case RT5660_ADDA_CLK1:
	case RT5660_ADDA_CLK2:
	case RT5660_DMIC_CTRL1:
	case RT5660_GLB_CLK:
	case RT5660_PLL_CTRL1:
	case RT5660_PLL_CTRL2:
	case RT5660_CLSD_AMP_OC_CTRL:
	case RT5660_CLSD_AMP_CTRL:
	case RT5660_LOUT_AMP_CTRL:
	case RT5660_SPK_AMP_SPKVDD:
	case RT5660_MICBIAS:
	case RT5660_CLSD_OUT_CTRL1:
	case RT5660_CLSD_OUT_CTRL2:
	case RT5660_DIPOLE_MIC_CTRL1:
	case RT5660_DIPOLE_MIC_CTRL2:
	case RT5660_DIPOLE_MIC_CTRL3:
	case RT5660_DIPOLE_MIC_CTRL4:
	case RT5660_DIPOLE_MIC_CTRL5:
	case RT5660_DIPOLE_MIC_CTRL6:
	case RT5660_DIPOLE_MIC_CTRL7:
	case RT5660_DIPOLE_MIC_CTRL8:
	case RT5660_DIPOLE_MIC_CTRL9:
	case RT5660_DIPOLE_MIC_CTRL10:
	case RT5660_DIPOLE_MIC_CTRL11:
	case RT5660_DIPOLE_MIC_CTRL12:
	case RT5660_EQ_CTRL1:
	case RT5660_EQ_CTRL2:
	case RT5660_DRC_AGC_CTRL1:
	case RT5660_DRC_AGC_CTRL2:
	case RT5660_DRC_AGC_CTRL3:
	case RT5660_DRC_AGC_CTRL4:
	case RT5660_DRC_AGC_CTRL5:
	case RT5660_JD_CTRL:
	case RT5660_IRQ_CTRL1:
	case RT5660_IRQ_CTRL2:
	case RT5660_INT_IRQ_ST:
	case RT5660_GPIO_CTRL1:
	case RT5660_GPIO_CTRL2:
	case RT5660_WIND_FILTER_CTRL1:
	case RT5660_SV_ZCD1:
	case RT5660_SV_ZCD2:
	case RT5660_DRC1_LM_CTRL1:
	case RT5660_DRC1_LM_CTRL2:
	case RT5660_DRC2_LM_CTRL1:
	case RT5660_DRC2_LM_CTRL2:
	case RT5660_MULTI_DRC_CTRL:
	case RT5660_DRC2_CTRL1:
	case RT5660_DRC2_CTRL2:
	case RT5660_DRC2_CTRL3:
	case RT5660_DRC2_CTRL4:
	case RT5660_DRC2_CTRL5:
	case RT5660_ALC_PGA_CTRL1:
	case RT5660_ALC_PGA_CTRL2:
	case RT5660_ALC_PGA_CTRL3:
	case RT5660_ALC_PGA_CTRL4:
	case RT5660_ALC_PGA_CTRL5:
	case RT5660_ALC_PGA_CTRL6:
	case RT5660_ALC_PGA_CTRL7:
	case RT5660_GEN_CTRL1:
	case RT5660_GEN_CTRL2:
	case RT5660_GEN_CTRL3:
	case RT5660_VENDOR_ID:
	case RT5660_VENDOR_ID1:
	case RT5660_VENDOR_ID2:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int rt5660_set_dmic_clk(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);
	int idx, rate;

	rate = rt5660->sysclk / rl6231_get_pre_div(rt5660->regmap,
		RT5660_ADDA_CLK1, RT5660_I2S_PD1_SFT);
	idx = rl6231_calc_dmic_clk(rate);
	if (idx < 0)
		dev_err(component->dev, "Failed to set DMIC clock\n");
	else
		snd_soc_component_update_bits(component, RT5660_DMIC_CTRL1,
			RT5660_DMIC_CLK_MASK, idx << RT5660_DMIC_CLK_SFT);

	return idx;
}

__attribute__((used)) static int rt5660_is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
			 struct snd_soc_dapm_widget *sink)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(source->dapm);
	unsigned int val;

	val = snd_soc_component_read32(component, RT5660_GLB_CLK);
	val &= RT5660_SCLK_SRC_MASK;
	if (val == RT5660_SCLK_SRC_PLL1)
		return 1;
	else
		return 0;
}

__attribute__((used)) static int rt5660_lout_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, RT5660_LOUT_AMP_CTRL,
			RT5660_LOUT_CO_MASK | RT5660_LOUT_CB_MASK,
			RT5660_LOUT_CO_EN | RT5660_LOUT_CB_PU);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, RT5660_LOUT_AMP_CTRL,
			RT5660_LOUT_CO_MASK | RT5660_LOUT_CB_MASK,
			RT5660_LOUT_CO_DIS | RT5660_LOUT_CB_PD);
		break;

	default:
		return 0;
	}

	return 0;
}

__attribute__((used)) static int rt5660_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);
	unsigned int val_len = 0, val_clk, mask_clk;
	int pre_div, bclk_ms, frame_size;

	rt5660->lrck[dai->id] = params_rate(params);
	pre_div = rl6231_get_clk_info(rt5660->sysclk, rt5660->lrck[dai->id]);
	if (pre_div < 0) {
		dev_err(component->dev, "Unsupported clock setting %d for DAI %d\n",
			rt5660->lrck[dai->id], dai->id);
		return -EINVAL;
	}

	frame_size = snd_soc_params_to_frame_size(params);
	if (frame_size < 0) {
		dev_err(component->dev, "Unsupported frame size: %d\n", frame_size);
		return frame_size;
	}

	if (frame_size > 32)
		bclk_ms = 1;
	else
		bclk_ms = 0;

	rt5660->bclk[dai->id] = rt5660->lrck[dai->id] * (32 << bclk_ms);

	dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
		rt5660->bclk[dai->id], rt5660->lrck[dai->id]);
	dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
				bclk_ms, pre_div, dai->id);

	switch (params_width(params)) {
	case 16:
		break;
	case 20:
		val_len |= RT5660_I2S_DL_20;
		break;
	case 24:
		val_len |= RT5660_I2S_DL_24;
		break;
	case 8:
		val_len |= RT5660_I2S_DL_8;
		break;
	default:
		return -EINVAL;
	}

	switch (dai->id) {
	case RT5660_AIF1:
		mask_clk = RT5660_I2S_BCLK_MS1_MASK | RT5660_I2S_PD1_MASK;
		val_clk = bclk_ms << RT5660_I2S_BCLK_MS1_SFT |
			pre_div << RT5660_I2S_PD1_SFT;
		snd_soc_component_update_bits(component, RT5660_I2S1_SDP, RT5660_I2S_DL_MASK,
			val_len);
		snd_soc_component_update_bits(component, RT5660_ADDA_CLK1, mask_clk, val_clk);
		break;

	default:
		dev_err(component->dev, "Invalid dai->id: %d\n", dai->id);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int rt5660_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);
	unsigned int reg_val = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		rt5660->master[dai->id] = 1;
		break;

	case SND_SOC_DAIFMT_CBS_CFS:
		reg_val |= RT5660_I2S_MS_S;
		rt5660->master[dai->id] = 0;
		break;

	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;

	case SND_SOC_DAIFMT_IB_NF:
		reg_val |= RT5660_I2S_BP_INV;
		break;

	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;

	case SND_SOC_DAIFMT_LEFT_J:
		reg_val |= RT5660_I2S_DF_LEFT;
		break;

	case SND_SOC_DAIFMT_DSP_A:
		reg_val |= RT5660_I2S_DF_PCM_A;
		break;

	case SND_SOC_DAIFMT_DSP_B:
		reg_val  |= RT5660_I2S_DF_PCM_B;
		break;

	default:
		return -EINVAL;
	}

	switch (dai->id) {
	case RT5660_AIF1:
		snd_soc_component_update_bits(component, RT5660_I2S1_SDP,
			RT5660_I2S_MS_MASK | RT5660_I2S_BP_MASK |
			RT5660_I2S_DF_MASK, reg_val);
		break;

	default:
		dev_err(component->dev, "Invalid dai->id: %d\n", dai->id);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int rt5660_set_dai_sysclk(struct snd_soc_dai *dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = dai->component;
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);
	unsigned int reg_val = 0;

	if (freq == rt5660->sysclk && clk_id == rt5660->sysclk_src)
		return 0;

	switch (clk_id) {
	case RT5660_SCLK_S_MCLK:
		reg_val |= RT5660_SCLK_SRC_MCLK;
		break;

	case RT5660_SCLK_S_PLL1:
		reg_val |= RT5660_SCLK_SRC_PLL1;
		break;

	case RT5660_SCLK_S_RCCLK:
		reg_val |= RT5660_SCLK_SRC_RCCLK;
		break;

	default:
		dev_err(component->dev, "Invalid clock id (%d)\n", clk_id);
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, RT5660_GLB_CLK, RT5660_SCLK_SRC_MASK,
		reg_val);

	rt5660->sysclk = freq;
	rt5660->sysclk_src = clk_id;

	dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);

	return 0;
}

__attribute__((used)) static int rt5660_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
			unsigned int freq_in, unsigned int freq_out)
{
	struct snd_soc_component *component = dai->component;
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);
	struct rl6231_pll_code pll_code;
	int ret;

	if (source == rt5660->pll_src && freq_in == rt5660->pll_in &&
		freq_out == rt5660->pll_out)
		return 0;

	if (!freq_in || !freq_out) {
		dev_dbg(component->dev, "PLL disabled\n");

		rt5660->pll_in = 0;
		rt5660->pll_out = 0;
		snd_soc_component_update_bits(component, RT5660_GLB_CLK,
			RT5660_SCLK_SRC_MASK, RT5660_SCLK_SRC_MCLK);
		return 0;
	}

	switch (source) {
	case RT5660_PLL1_S_MCLK:
		snd_soc_component_update_bits(component, RT5660_GLB_CLK,
			RT5660_PLL1_SRC_MASK, RT5660_PLL1_SRC_MCLK);
		break;

	case RT5660_PLL1_S_BCLK:
		snd_soc_component_update_bits(component, RT5660_GLB_CLK,
			RT5660_PLL1_SRC_MASK, RT5660_PLL1_SRC_BCLK1);
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

	snd_soc_component_write(component, RT5660_PLL_CTRL1,
		pll_code.n_code << RT5660_PLL_N_SFT | pll_code.k_code);
	snd_soc_component_write(component, RT5660_PLL_CTRL2,
		(pll_code.m_bp ? 0 : pll_code.m_code) << RT5660_PLL_M_SFT |
		pll_code.m_bp << RT5660_PLL_M_BP_SFT);

	rt5660->pll_in = freq_in;
	rt5660->pll_out = freq_out;
	rt5660->pll_src = source;

	return 0;
}

__attribute__((used)) static int rt5660_set_bias_level(struct snd_soc_component *component,
			enum snd_soc_bias_level level)
{
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;

	case SND_SOC_BIAS_PREPARE:
		snd_soc_component_update_bits(component, RT5660_GEN_CTRL1,
			RT5660_DIG_GATE_CTRL, RT5660_DIG_GATE_CTRL);

		if (IS_ERR(rt5660->mclk))
			break;

		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_ON) {
			clk_disable_unprepare(rt5660->mclk);
		} else {
			ret = clk_prepare_enable(rt5660->mclk);
			if (ret)
				return ret;
		}
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			snd_soc_component_update_bits(component, RT5660_PWR_ANLG1,
				RT5660_PWR_VREF1 | RT5660_PWR_MB |
				RT5660_PWR_BG | RT5660_PWR_VREF2,
				RT5660_PWR_VREF1 | RT5660_PWR_MB |
				RT5660_PWR_BG | RT5660_PWR_VREF2);
			usleep_range(10000, 15000);
			snd_soc_component_update_bits(component, RT5660_PWR_ANLG1,
				RT5660_PWR_FV1 | RT5660_PWR_FV2,
				RT5660_PWR_FV1 | RT5660_PWR_FV2);
		}
		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, RT5660_GEN_CTRL1,
			RT5660_DIG_GATE_CTRL, 0);
		break;

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int rt5660_probe(struct snd_soc_component *component)
{
	struct rt5660_priv *rt5660 = snd_soc_component_get_drvdata(component);

	rt5660->component = component;

	return 0;
}

__attribute__((used)) static void rt5660_remove(struct snd_soc_component *component)
{
	snd_soc_component_write(component, RT5660_RESET, 0);
}

__attribute__((used)) static int rt5660_parse_dt(struct rt5660_priv *rt5660, struct device *dev)
{
	rt5660->pdata.in1_diff = device_property_read_bool(dev,
					"realtek,in1-differential");
	rt5660->pdata.in3_diff = device_property_read_bool(dev,
					"realtek,in3-differential");
	rt5660->pdata.poweroff_codec_in_suspend = device_property_read_bool(dev,
					"realtek,poweroff-in-suspend");
	device_property_read_u32(dev, "realtek,dmic1-data-pin",
		&rt5660->pdata.dmic1_data_pin);

	return 0;
}

__attribute__((used)) static int rt5660_i2c_probe(struct i2c_client *i2c,
		    const struct i2c_device_id *id)
{
	struct rt5660_platform_data *pdata = dev_get_platdata(&i2c->dev);
	struct rt5660_priv *rt5660;
	int ret;
	unsigned int val;

	rt5660 = devm_kzalloc(&i2c->dev, sizeof(struct rt5660_priv),
		GFP_KERNEL);

	if (rt5660 == NULL)
		return -ENOMEM;

	/* Check if MCLK provided */
	rt5660->mclk = devm_clk_get(&i2c->dev, "mclk");
	if (PTR_ERR(rt5660->mclk) == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	i2c_set_clientdata(i2c, rt5660);

	if (pdata)
		rt5660->pdata = *pdata;
	else if (i2c->dev.of_node)
		rt5660_parse_dt(rt5660, &i2c->dev);

	rt5660->regmap = devm_regmap_init_i2c(i2c, &rt5660_regmap);
	if (IS_ERR(rt5660->regmap)) {
		ret = PTR_ERR(rt5660->regmap);
		dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	regmap_read(rt5660->regmap, RT5660_VENDOR_ID2, &val);
	if (val != RT5660_DEVICE_ID) {
		dev_err(&i2c->dev,
			"Device with ID register %#x is not rt5660\n", val);
		return -ENODEV;
	}

	regmap_write(rt5660->regmap, RT5660_RESET, 0);

	ret = regmap_register_patch(rt5660->regmap, rt5660_patch,
				    ARRAY_SIZE(rt5660_patch));
	if (ret != 0)
		dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);

	regmap_update_bits(rt5660->regmap, RT5660_GEN_CTRL1,
		RT5660_AUTO_DIS_AMP | RT5660_MCLK_DET | RT5660_POW_CLKDET,
		RT5660_AUTO_DIS_AMP | RT5660_MCLK_DET | RT5660_POW_CLKDET);

	if (rt5660->pdata.dmic1_data_pin) {
		regmap_update_bits(rt5660->regmap, RT5660_GPIO_CTRL1,
			RT5660_GP1_PIN_MASK, RT5660_GP1_PIN_DMIC1_SCL);

		if (rt5660->pdata.dmic1_data_pin == RT5660_DMIC1_DATA_GPIO2)
			regmap_update_bits(rt5660->regmap, RT5660_DMIC_CTRL1,
				RT5660_SEL_DMIC_DATA_MASK,
				RT5660_SEL_DMIC_DATA_GPIO2);
		else if (rt5660->pdata.dmic1_data_pin == RT5660_DMIC1_DATA_IN1P)
			regmap_update_bits(rt5660->regmap, RT5660_DMIC_CTRL1,
				RT5660_SEL_DMIC_DATA_MASK,
				RT5660_SEL_DMIC_DATA_IN1P);
	}

	return devm_snd_soc_register_component(&i2c->dev,
				      &soc_component_dev_rt5660,
				      rt5660_dai, ARRAY_SIZE(rt5660_dai));
}


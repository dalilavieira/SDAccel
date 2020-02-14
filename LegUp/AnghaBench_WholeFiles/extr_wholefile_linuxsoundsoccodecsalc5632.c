#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {unsigned int driver_data; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct alc5632_priv {int sysclk; int id; struct regmap* regmap; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_10__ {char* name; } ;
struct TYPE_9__ {unsigned int pll_in; unsigned int pll_out; int regvalue; int fs; } ;

/* Variables and functions */
 int ALC5632_ADD1_POWER_EN ; 
 int ALC5632_ADD2_POWER_EN ; 
 int ALC5632_ADD3_POWER_EN ; 
 int const ALC5632_DAC_CLK_CTRL1 ; 
 int const ALC5632_DAI_CONTROL ; 
 int ALC5632_DAI_I2S_DF_I2S ; 
 int ALC5632_DAI_I2S_DF_LEFT ; 
 int ALC5632_DAI_I2S_DF_PCM_A ; 
 int ALC5632_DAI_I2S_DF_PCM_B ; 
 int ALC5632_DAI_I2S_DL_16 ; 
 int ALC5632_DAI_I2S_DL_20 ; 
 int ALC5632_DAI_I2S_DL_24 ; 
 int ALC5632_DAI_I2S_DL_MASK ; 
 int ALC5632_DAI_MAIN_I2S_BCLK_POL_CTRL ; 
 int ALC5632_DAI_SDP_MASTER_MODE ; 
 int ALC5632_DAI_SDP_SLAVE_MODE ; 
#define  ALC5632_EQ_CTRL 154 
 int const ALC5632_GPCR1 ; 
 int ALC5632_GPCR1_CLK_SYS_SRC_SEL_PLL1 ; 
 int const ALC5632_GPCR2 ; 
#define  ALC5632_GPIO_PIN_STATUS 153 
#define  ALC5632_HID_CTRL_DATA 152 
 int const ALC5632_HID_CTRL_INDEX ; 
 int const ALC5632_MISC_CTRL ; 
 int ALC5632_MISC_HP_DEPOP_MODE2_EN ; 
 int ALC5632_MISC_HP_DEPOP_MUTE_L ; 
 int ALC5632_MISC_HP_DEPOP_MUTE_R ; 
#define  ALC5632_OVER_CURR_STATUS 151 
 int const ALC5632_PLL1_CTRL ; 
#define  ALC5632_PLL_FR_BCLK 150 
#define  ALC5632_PLL_FR_MCLK 149 
#define  ALC5632_PLL_FR_VBCLK 148 
 int ALC5632_PWR_ADD1_MAIN_BIAS ; 
 int ALC5632_PWR_ADD1_SOFTGEN_EN ; 
 int ALC5632_PWR_ADD2_PLL1 ; 
 int ALC5632_PWR_ADD2_PLL2 ; 
 int ALC5632_PWR_ADD2_VREF ; 
#define  ALC5632_PWR_DOWN_CTRL_STATUS 147 
 int ALC5632_PWR_DOWN_CTRL_STATUS_MASK ; 
 int const ALC5632_PWR_MANAG_ADD1 ; 
 int ALC5632_PWR_MANAG_ADD1_MASK ; 
 int const ALC5632_PWR_MANAG_ADD2 ; 
 int ALC5632_PWR_MANAG_ADD2_MASK ; 
 int const ALC5632_PWR_MANAG_ADD3 ; 
 int ALC5632_PWR_MANAG_ADD3_MASK ; 
 int ALC5632_PWR_VREF_PR2 ; 
 int ALC5632_PWR_VREF_PR3 ; 
#define  ALC5632_RESET 146 
#define  ALC5632_VENDOR_ID1 145 
#define  ALC5632_VENDOR_ID2 144 
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
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
#define  SND_SOC_DAPM_POST_PMD 129 
#define  SND_SOC_DAPM_PRE_PMU 128 
 TYPE_2__ alc5632_dai ; 
 int /*<<< orphan*/  alc5632_regmap ; 
 TYPE_1__* alc5632_vol_snd_controls ; 
 TYPE_1__* codec_master_pll_div ; 
 TYPE_1__* codec_slave_pll_div ; 
 TYPE_1__* coeff_div ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct alc5632_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_2__*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct alc5632_priv*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int regmap_read (struct regmap*,int const,unsigned int*) ; 
 int regmap_write (struct regmap*,int const,int) ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,TYPE_1__*,int) ; 
 struct alc5632_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int const) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int const,int,int) ; 
 int snd_soc_component_write (struct snd_soc_component*,int const,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_device_alc5632 ; 

__attribute__((used)) static bool alc5632_volatile_register(struct device *dev,
							unsigned int reg)
{
	switch (reg) {
	case ALC5632_RESET:
	case ALC5632_PWR_DOWN_CTRL_STATUS:
	case ALC5632_GPIO_PIN_STATUS:
	case ALC5632_OVER_CURR_STATUS:
	case ALC5632_HID_CTRL_DATA:
	case ALC5632_EQ_CTRL:
	case ALC5632_VENDOR_ID1:
	case ALC5632_VENDOR_ID2:
		return true;

	default:
		break;
	}

	return false;
}

__attribute__((used)) static inline int alc5632_reset(struct regmap *map)
{
	return regmap_write(map, ALC5632_RESET, 0x59B4);
}

__attribute__((used)) static int amp_mixer_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	/* to power-on/off class-d amp generators/speaker */
	/* need to write to 'index-46h' register :        */
	/* so write index num (here 0x46) to reg 0x6a     */
	/* and then 0xffff/0 to reg 0x6c                  */
	snd_soc_component_write(component, ALC5632_HID_CTRL_INDEX, 0x46);

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		snd_soc_component_write(component, ALC5632_HID_CTRL_DATA, 0xFFFF);
		break;
	case SND_SOC_DAPM_POST_PMD:
		snd_soc_component_write(component, ALC5632_HID_CTRL_DATA, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int alc5632_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
		int source, unsigned int freq_in, unsigned int freq_out)
{
	int i;
	struct snd_soc_component *component = codec_dai->component;
	int gbl_clk = 0, pll_div = 0;
	u16 reg;

	if (pll_id < ALC5632_PLL_FR_MCLK || pll_id > ALC5632_PLL_FR_VBCLK)
		return -EINVAL;

	/* Disable PLL power */
	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_PWR_ADD2_PLL1,
				0);
	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_PWR_ADD2_PLL2,
				0);

	/* pll is not used in slave mode */
	reg = snd_soc_component_read32(component, ALC5632_DAI_CONTROL);
	if (reg & ALC5632_DAI_SDP_SLAVE_MODE)
		return 0;

	if (!freq_in || !freq_out)
		return 0;

	switch (pll_id) {
	case ALC5632_PLL_FR_MCLK:
		for (i = 0; i < ARRAY_SIZE(codec_master_pll_div); i++) {
			if (codec_master_pll_div[i].pll_in == freq_in
			   && codec_master_pll_div[i].pll_out == freq_out) {
				/* PLL source from MCLK */
				pll_div  = codec_master_pll_div[i].regvalue;
				break;
			}
		}
		break;
	case ALC5632_PLL_FR_BCLK:
		for (i = 0; i < ARRAY_SIZE(codec_slave_pll_div); i++) {
			if (codec_slave_pll_div[i].pll_in == freq_in
			   && codec_slave_pll_div[i].pll_out == freq_out) {
				/* PLL source from Bitclk */
				gbl_clk = ALC5632_PLL_FR_BCLK;
				pll_div = codec_slave_pll_div[i].regvalue;
				break;
			}
		}
		break;
	case ALC5632_PLL_FR_VBCLK:
		for (i = 0; i < ARRAY_SIZE(codec_slave_pll_div); i++) {
			if (codec_slave_pll_div[i].pll_in == freq_in
			   && codec_slave_pll_div[i].pll_out == freq_out) {
				/* PLL source from voice clock */
				gbl_clk = ALC5632_PLL_FR_VBCLK;
				pll_div = codec_slave_pll_div[i].regvalue;
				break;
			}
		}
		break;
	default:
		return -EINVAL;
	}

	if (!pll_div)
		return -EINVAL;

	/* choose MCLK/BCLK/VBCLK */
	snd_soc_component_write(component, ALC5632_GPCR2, gbl_clk);
	/* choose PLL1 clock rate */
	snd_soc_component_write(component, ALC5632_PLL1_CTRL, pll_div);
	/* enable PLL1 */
	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_PWR_ADD2_PLL1,
				ALC5632_PWR_ADD2_PLL1);
	/* enable PLL2 */
	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_PWR_ADD2_PLL2,
				ALC5632_PWR_ADD2_PLL2);
	/* use PLL1 as main SYSCLK */
	snd_soc_component_update_bits(component, ALC5632_GPCR1,
			ALC5632_GPCR1_CLK_SYS_SRC_SEL_PLL1,
			ALC5632_GPCR1_CLK_SYS_SRC_SEL_PLL1);

	return 0;
}

__attribute__((used)) static int get_coeff(struct snd_soc_component *component, int rate)
{
	struct alc5632_priv *alc5632 = snd_soc_component_get_drvdata(component);
	int i;

	for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
		if (coeff_div[i].fs * rate == alc5632->sysclk)
			return i;
	}
	return -EINVAL;
}

__attribute__((used)) static int alc5632_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct alc5632_priv *alc5632 = snd_soc_component_get_drvdata(component);

	switch (freq) {
	case  4096000:
	case  8192000:
	case 11289600:
	case 12288000:
	case 16384000:
	case 16934400:
	case 18432000:
	case 22579200:
	case 24576000:
		alc5632->sysclk = freq;
		return 0;
	}
	return -EINVAL;
}

__attribute__((used)) static int alc5632_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	u16 iface = 0;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		iface = ALC5632_DAI_SDP_MASTER_MODE;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		iface = ALC5632_DAI_SDP_SLAVE_MODE;
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		iface |= ALC5632_DAI_I2S_DF_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		iface |= ALC5632_DAI_I2S_DF_LEFT;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		iface |= ALC5632_DAI_I2S_DF_PCM_A;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		iface |= ALC5632_DAI_I2S_DF_PCM_B;
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_IF:
		iface |= ALC5632_DAI_MAIN_I2S_BCLK_POL_CTRL;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		iface |= ALC5632_DAI_MAIN_I2S_BCLK_POL_CTRL;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		break;
	default:
		return -EINVAL;
	}

	return snd_soc_component_write(component, ALC5632_DAI_CONTROL, iface);
}

__attribute__((used)) static int alc5632_pcm_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	int coeff, rate;
	u16 iface;

	iface = snd_soc_component_read32(component, ALC5632_DAI_CONTROL);
	iface &= ~ALC5632_DAI_I2S_DL_MASK;

	/* bit size */
	switch (params_width(params)) {
	case 16:
		iface |= ALC5632_DAI_I2S_DL_16;
		break;
	case 20:
		iface |= ALC5632_DAI_I2S_DL_20;
		break;
	case 24:
		iface |= ALC5632_DAI_I2S_DL_24;
		break;
	default:
		return -EINVAL;
	}

	/* set iface & srate */
	snd_soc_component_write(component, ALC5632_DAI_CONTROL, iface);
	rate = params_rate(params);
	coeff = get_coeff(component, rate);
	if (coeff < 0)
		return -EINVAL;

	coeff = coeff_div[coeff].regvalue;
	snd_soc_component_write(component, ALC5632_DAC_CLK_CTRL1, coeff);

	return 0;
}

__attribute__((used)) static int alc5632_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	u16 hp_mute = ALC5632_MISC_HP_DEPOP_MUTE_L
						|ALC5632_MISC_HP_DEPOP_MUTE_R;
	u16 mute_reg = snd_soc_component_read32(component, ALC5632_MISC_CTRL) & ~hp_mute;

	if (mute)
		mute_reg |= hp_mute;

	return snd_soc_component_write(component, ALC5632_MISC_CTRL, mute_reg);
}

__attribute__((used)) static void enable_power_depop(struct snd_soc_component *component)
{
	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD1,
				ALC5632_PWR_ADD1_SOFTGEN_EN,
				ALC5632_PWR_ADD1_SOFTGEN_EN);

	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD3,
				ALC5632_ADD3_POWER_EN,
				ALC5632_ADD3_POWER_EN);

	snd_soc_component_update_bits(component, ALC5632_MISC_CTRL,
				ALC5632_MISC_HP_DEPOP_MODE2_EN,
				ALC5632_MISC_HP_DEPOP_MODE2_EN);

	/* "normal" mode: 0 @ 26 */
	/* set all PR0-7 mixers to 0 */
	snd_soc_component_update_bits(component, ALC5632_PWR_DOWN_CTRL_STATUS,
				ALC5632_PWR_DOWN_CTRL_STATUS_MASK,
				0);

	msleep(500);

	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_ADD2_POWER_EN,
				ALC5632_ADD2_POWER_EN);

	snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD1,
				ALC5632_ADD1_POWER_EN,
				ALC5632_ADD1_POWER_EN);

	/* disable HP Depop2 */
	snd_soc_component_update_bits(component, ALC5632_MISC_CTRL,
				ALC5632_MISC_HP_DEPOP_MODE2_EN,
				0);

}

__attribute__((used)) static int alc5632_set_bias_level(struct snd_soc_component *component,
				      enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
		enable_power_depop(component);
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		/* everything off except vref/vmid, */
		snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD1,
				ALC5632_PWR_MANAG_ADD1_MASK,
				ALC5632_PWR_ADD1_MAIN_BIAS);
		snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_PWR_MANAG_ADD2_MASK,
				ALC5632_PWR_ADD2_VREF);
		/* "normal" mode: 0 @ 26 */
		snd_soc_component_update_bits(component, ALC5632_PWR_DOWN_CTRL_STATUS,
				ALC5632_PWR_DOWN_CTRL_STATUS_MASK,
				0xffff ^ (ALC5632_PWR_VREF_PR3
				| ALC5632_PWR_VREF_PR2));
		break;
	case SND_SOC_BIAS_OFF:
		/* everything off, dac mute, inactive */
		snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD2,
				ALC5632_PWR_MANAG_ADD2_MASK, 0);
		snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD3,
				ALC5632_PWR_MANAG_ADD3_MASK, 0);
		snd_soc_component_update_bits(component, ALC5632_PWR_MANAG_ADD1,
				ALC5632_PWR_MANAG_ADD1_MASK, 0);
		break;
	}
	return 0;
}

__attribute__((used)) static int alc5632_probe(struct snd_soc_component *component)
{
	struct alc5632_priv *alc5632 = snd_soc_component_get_drvdata(component);

	switch (alc5632->id) {
	case 0x5c:
		snd_soc_add_component_controls(component, alc5632_vol_snd_controls,
			ARRAY_SIZE(alc5632_vol_snd_controls));
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int alc5632_i2c_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct alc5632_priv *alc5632;
	int ret, ret1, ret2;
	unsigned int vid1, vid2;

	alc5632 = devm_kzalloc(&client->dev,
			 sizeof(struct alc5632_priv), GFP_KERNEL);
	if (alc5632 == NULL)
		return -ENOMEM;

	i2c_set_clientdata(client, alc5632);

	alc5632->regmap = devm_regmap_init_i2c(client, &alc5632_regmap);
	if (IS_ERR(alc5632->regmap)) {
		ret = PTR_ERR(alc5632->regmap);
		dev_err(&client->dev, "regmap_init() failed: %d\n", ret);
		return ret;
	}

	ret1 = regmap_read(alc5632->regmap, ALC5632_VENDOR_ID1, &vid1);
	ret2 = regmap_read(alc5632->regmap, ALC5632_VENDOR_ID2, &vid2);
	if (ret1 != 0 || ret2 != 0) {
		dev_err(&client->dev,
		"Failed to read chip ID: ret1=%d, ret2=%d\n", ret1, ret2);
		return -EIO;
	}

	vid2 >>= 8;

	if ((vid1 != 0x10EC) || (vid2 != id->driver_data)) {
		dev_err(&client->dev,
		"Device is not a ALC5632: VID1=0x%x, VID2=0x%x\n", vid1, vid2);
		return -EINVAL;
	}

	ret = alc5632_reset(alc5632->regmap);
	if (ret < 0) {
		dev_err(&client->dev, "Failed to issue reset\n");
		return ret;
	}

	alc5632->id = vid2;
	switch (alc5632->id) {
	case 0x5c:
		alc5632_dai.name = "alc5632-hifi";
		break;
	default:
		return -EINVAL;
	}

	ret = devm_snd_soc_register_component(&client->dev,
		&soc_component_device_alc5632, &alc5632_dai, 1);

	if (ret < 0) {
		dev_err(&client->dev, "Failed to register component: %d\n", ret);
		return ret;
	}

	return ret;
}


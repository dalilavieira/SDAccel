#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  AK4671_AD_DA_POWER_MANAGEMENT ; 
 int AK4671_BCKP ; 
 int AK4671_DIF ; 
 int AK4671_DIF_DSP_MODE ; 
 int AK4671_DIF_I2S_MODE ; 
 int AK4671_DIF_MSB_MODE ; 
 int /*<<< orphan*/  AK4671_FORMAT_SELECT ; 
 int AK4671_FS ; 
 int AK4671_FS_11_025KHZ ; 
 int AK4671_FS_12KHZ ; 
 int AK4671_FS_16KHZ ; 
 int AK4671_FS_22_05KHZ ; 
 int AK4671_FS_24KHZ ; 
 int AK4671_FS_32KHZ ; 
 int AK4671_FS_44_1KHZ ; 
 int AK4671_FS_48KHZ ; 
 int AK4671_FS_8KHZ ; 
 int /*<<< orphan*/  AK4671_LOUT2_POWER_MANAGERMENT ; 
 int AK4671_MSBS ; 
 int /*<<< orphan*/  AK4671_MUTEN ; 
 int AK4671_M_S ; 
 int AK4671_PLL ; 
 int AK4671_PLL_11_2896MHZ ; 
 int AK4671_PLL_12MHZ ; 
 int AK4671_PLL_12_288MHZ ; 
 int AK4671_PLL_13MHZ ; 
 int AK4671_PLL_13_5MHZ ; 
 int AK4671_PLL_19_2MHZ ; 
 int AK4671_PLL_24MHZ ; 
 int AK4671_PLL_26MHZ ; 
 int AK4671_PLL_27MHZ ; 
 int /*<<< orphan*/  AK4671_PLL_MODE_SELECT0 ; 
 int /*<<< orphan*/  AK4671_PLL_MODE_SELECT1 ; 
 int /*<<< orphan*/  AK4671_PMVCM ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
#define  SND_SOC_BIAS_OFF 138 
#define  SND_SOC_BIAS_ON 137 
#define  SND_SOC_BIAS_PREPARE 136 
#define  SND_SOC_BIAS_STANDBY 135 
#define  SND_SOC_DAIFMT_CBM_CFM 134 
#define  SND_SOC_DAIFMT_CBM_CFS 133 
#define  SND_SOC_DAIFMT_DSP_A 132 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 131 
#define  SND_SOC_DAIFMT_LEFT_J 130 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAPM_POST_PMU 129 
#define  SND_SOC_DAPM_PRE_PMD 128 
 int /*<<< orphan*/  ak4671_dai ; 
 int /*<<< orphan*/  ak4671_regmap ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_ak4671 ; 

__attribute__((used)) static int ak4671_out2_event(struct snd_soc_dapm_widget *w,
		struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		snd_soc_component_update_bits(component, AK4671_LOUT2_POWER_MANAGERMENT,
				    AK4671_MUTEN, AK4671_MUTEN);
		break;
	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, AK4671_LOUT2_POWER_MANAGERMENT,
				    AK4671_MUTEN, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int ak4671_hw_params(struct snd_pcm_substream *substream,
		struct snd_pcm_hw_params *params,
		struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	u8 fs;

	fs = snd_soc_component_read32(component, AK4671_PLL_MODE_SELECT0);
	fs &= ~AK4671_FS;

	switch (params_rate(params)) {
	case 8000:
		fs |= AK4671_FS_8KHZ;
		break;
	case 12000:
		fs |= AK4671_FS_12KHZ;
		break;
	case 16000:
		fs |= AK4671_FS_16KHZ;
		break;
	case 24000:
		fs |= AK4671_FS_24KHZ;
		break;
	case 11025:
		fs |= AK4671_FS_11_025KHZ;
		break;
	case 22050:
		fs |= AK4671_FS_22_05KHZ;
		break;
	case 32000:
		fs |= AK4671_FS_32KHZ;
		break;
	case 44100:
		fs |= AK4671_FS_44_1KHZ;
		break;
	case 48000:
		fs |= AK4671_FS_48KHZ;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_write(component, AK4671_PLL_MODE_SELECT0, fs);

	return 0;
}

__attribute__((used)) static int ak4671_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
		unsigned int freq, int dir)
{
	struct snd_soc_component *component = dai->component;
	u8 pll;

	pll = snd_soc_component_read32(component, AK4671_PLL_MODE_SELECT0);
	pll &= ~AK4671_PLL;

	switch (freq) {
	case 11289600:
		pll |= AK4671_PLL_11_2896MHZ;
		break;
	case 12000000:
		pll |= AK4671_PLL_12MHZ;
		break;
	case 12288000:
		pll |= AK4671_PLL_12_288MHZ;
		break;
	case 13000000:
		pll |= AK4671_PLL_13MHZ;
		break;
	case 13500000:
		pll |= AK4671_PLL_13_5MHZ;
		break;
	case 19200000:
		pll |= AK4671_PLL_19_2MHZ;
		break;
	case 24000000:
		pll |= AK4671_PLL_24MHZ;
		break;
	case 26000000:
		pll |= AK4671_PLL_26MHZ;
		break;
	case 27000000:
		pll |= AK4671_PLL_27MHZ;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_write(component, AK4671_PLL_MODE_SELECT0, pll);

	return 0;
}

__attribute__((used)) static int ak4671_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	u8 mode;
	u8 format;

	/* set master/slave audio interface */
	mode = snd_soc_component_read32(component, AK4671_PLL_MODE_SELECT1);

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		mode |= AK4671_M_S;
		break;
	case SND_SOC_DAIFMT_CBM_CFS:
		mode &= ~(AK4671_M_S);
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	format = snd_soc_component_read32(component, AK4671_FORMAT_SELECT);
	format &= ~AK4671_DIF;

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		format |= AK4671_DIF_I2S_MODE;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		format |= AK4671_DIF_MSB_MODE;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		format |= AK4671_DIF_DSP_MODE;
		format |= AK4671_BCKP;
		format |= AK4671_MSBS;
		break;
	default:
		return -EINVAL;
	}

	/* set mode and format */
	snd_soc_component_write(component, AK4671_PLL_MODE_SELECT1, mode);
	snd_soc_component_write(component, AK4671_FORMAT_SELECT, format);

	return 0;
}

__attribute__((used)) static int ak4671_set_bias_level(struct snd_soc_component *component,
		enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_ON:
	case SND_SOC_BIAS_PREPARE:
	case SND_SOC_BIAS_STANDBY:
		snd_soc_component_update_bits(component, AK4671_AD_DA_POWER_MANAGEMENT,
				    AK4671_PMVCM, AK4671_PMVCM);
		break;
	case SND_SOC_BIAS_OFF:
		snd_soc_component_write(component, AK4671_AD_DA_POWER_MANAGEMENT, 0x00);
		break;
	}
	return 0;
}

__attribute__((used)) static int ak4671_i2c_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct regmap *regmap;
	int ret;

	regmap = devm_regmap_init_i2c(client, &ak4671_regmap);
	if (IS_ERR(regmap)) {
		ret = PTR_ERR(regmap);
		dev_err(&client->dev, "Failed to create regmap: %d\n", ret);
		return ret;
	}

	ret = devm_snd_soc_register_component(&client->dev,
			&soc_component_dev_ak4671, &ak4671_dai, 1);
	return ret;
}


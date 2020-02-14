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
typedef  int u16 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct lm49453_priv {int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int LM49453_AUDIO_PORT1_BASIC_CLK_MS ; 
 int LM49453_AUDIO_PORT1_BASIC_FMT_MASK ; 
 int LM49453_AUDIO_PORT1_BASIC_SYNC_MS ; 
 int LM49453_CHIP_EN ; 
 int /*<<< orphan*/  LM49453_P0_ADC_CLK_DIV_REG ; 
 int /*<<< orphan*/  LM49453_P0_AUDIO_PORT1_BASIC_REG ; 
 int /*<<< orphan*/  LM49453_P0_AUDIO_PORT1_RX_MSB_REG ; 
 int /*<<< orphan*/  LM49453_P0_DAC_DSP_REG ; 
 int /*<<< orphan*/  LM49453_P0_DAC_HP_CLK_DIV_REG ; 
 int /*<<< orphan*/  LM49453_P0_PMC_SETUP_REG ; 
 int LM49453_PMC_SETUP_CHIP_EN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_BIAS_OFF 138 
#define  SND_SOC_BIAS_ON 137 
#define  SND_SOC_BIAS_PREPARE 136 
#define  SND_SOC_BIAS_STANDBY 135 
#define  SND_SOC_DAIFMT_CBM_CFM 134 
#define  SND_SOC_DAIFMT_CBM_CFS 133 
#define  SND_SOC_DAIFMT_CBS_CFM 132 
#define  SND_SOC_DAIFMT_CBS_CFS 131 
#define  SND_SOC_DAIFMT_DSP_A 130 
#define  SND_SOC_DAIFMT_DSP_B 129 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 128 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct lm49453_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lm49453_priv*) ; 
 int /*<<< orphan*/  lm49453_dai ; 
 int /*<<< orphan*/  lm49453_regmap_config ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct lm49453_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  soc_component_dev_lm49453 ; 

__attribute__((used)) static int lm49453_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	u16 clk_div = 0;

	/* Setting DAC clock dividers based on substream sample rate. */
	switch (params_rate(params)) {
	case 8000:
	case 16000:
	case 32000:
	case 24000:
	case 48000:
		clk_div = 256;
		break;
	case 11025:
	case 22050:
	case 44100:
		clk_div = 216;
		break;
	case 96000:
		clk_div = 127;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_write(component, LM49453_P0_ADC_CLK_DIV_REG, clk_div);
	snd_soc_component_write(component, LM49453_P0_DAC_HP_CLK_DIV_REG, clk_div);

	return 0;
}

__attribute__((used)) static int lm49453_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;

	u16 aif_val;
	int mode = 0;
	int clk_phase = 0;
	int clk_shift = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		aif_val = 0;
		break;
	case SND_SOC_DAIFMT_CBS_CFM:
		aif_val = LM49453_AUDIO_PORT1_BASIC_SYNC_MS;
		break;
	case SND_SOC_DAIFMT_CBM_CFS:
		aif_val = LM49453_AUDIO_PORT1_BASIC_CLK_MS;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		aif_val = LM49453_AUDIO_PORT1_BASIC_CLK_MS |
			  LM49453_AUDIO_PORT1_BASIC_SYNC_MS;
		break;
	default:
		return -EINVAL;
	}


	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;
	case SND_SOC_DAIFMT_DSP_A:
		mode = 1;
		clk_phase = (1 << 5);
		clk_shift = 1;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		mode = 1;
		clk_phase = (1 << 5);
		clk_shift = 0;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, LM49453_P0_AUDIO_PORT1_BASIC_REG,
			    LM49453_AUDIO_PORT1_BASIC_FMT_MASK|BIT(0)|BIT(5),
			    (aif_val | mode | clk_phase));

	snd_soc_component_write(component, LM49453_P0_AUDIO_PORT1_RX_MSB_REG, clk_shift);

	return 0;
}

__attribute__((used)) static int lm49453_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
				  unsigned int freq, int dir)
{
	struct snd_soc_component *component = dai->component;
	u16 pll_clk = 0;

	switch (freq) {
	case 12288000:
	case 26000000:
	case 19200000:
		/* pll clk slection */
		pll_clk = 0;
		break;
	case 48000:
	case 32576:
		/* fll clk slection */
		pll_clk = BIT(4);
		return 0;
	default:
		return -EINVAL;
	}

	snd_soc_component_update_bits(component, LM49453_P0_PMC_SETUP_REG, BIT(4), pll_clk);

	return 0;
}

__attribute__((used)) static int lm49453_hp_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, LM49453_P0_DAC_DSP_REG, BIT(1)|BIT(0),
			    (mute ? (BIT(1)|BIT(0)) : 0));
	return 0;
}

__attribute__((used)) static int lm49453_lo_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, LM49453_P0_DAC_DSP_REG, BIT(3)|BIT(2),
			    (mute ? (BIT(3)|BIT(2)) : 0));
	return 0;
}

__attribute__((used)) static int lm49453_ls_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, LM49453_P0_DAC_DSP_REG, BIT(5)|BIT(4),
			    (mute ? (BIT(5)|BIT(4)) : 0));
	return 0;
}

__attribute__((used)) static int lm49453_ep_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, LM49453_P0_DAC_DSP_REG, BIT(4),
			    (mute ? BIT(4) : 0));
	return 0;
}

__attribute__((used)) static int lm49453_ha_mute(struct snd_soc_dai *dai, int mute)
{
	snd_soc_component_update_bits(dai->component, LM49453_P0_DAC_DSP_REG, BIT(7)|BIT(6),
			    (mute ? (BIT(7)|BIT(6)) : 0));
	return 0;
}

__attribute__((used)) static int lm49453_set_bias_level(struct snd_soc_component *component,
				  enum snd_soc_bias_level level)
{
	struct lm49453_priv *lm49453 = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
	case SND_SOC_BIAS_PREPARE:
		break;

	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF)
			regcache_sync(lm49453->regmap);

		snd_soc_component_update_bits(component, LM49453_P0_PMC_SETUP_REG,
				    LM49453_PMC_SETUP_CHIP_EN, LM49453_CHIP_EN);
		break;

	case SND_SOC_BIAS_OFF:
		snd_soc_component_update_bits(component, LM49453_P0_PMC_SETUP_REG,
				    LM49453_PMC_SETUP_CHIP_EN, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int lm49453_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	struct lm49453_priv *lm49453;
	int ret = 0;

	lm49453 = devm_kzalloc(&i2c->dev, sizeof(struct lm49453_priv),
				GFP_KERNEL);

	if (lm49453 == NULL)
		return -ENOMEM;

	i2c_set_clientdata(i2c, lm49453);

	lm49453->regmap = devm_regmap_init_i2c(i2c, &lm49453_regmap_config);
	if (IS_ERR(lm49453->regmap)) {
		ret = PTR_ERR(lm49453->regmap);
		dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	ret =  devm_snd_soc_register_component(&i2c->dev,
				      &soc_component_dev_lm49453,
				      lm49453_dai, ARRAY_SIZE(lm49453_dai));
	if (ret < 0)
		dev_err(&i2c->dev, "Failed to register component: %d\n", ret);

	return ret;
}

__attribute__((used)) static int lm49453_i2c_remove(struct i2c_client *client)
{
	return 0;
}


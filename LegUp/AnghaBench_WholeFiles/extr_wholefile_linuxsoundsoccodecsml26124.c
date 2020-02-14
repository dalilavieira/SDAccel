#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct ml26124_priv {int mclk; int rate; int clk_in; int /*<<< orphan*/  regmap; struct snd_pcm_substream* substream; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_3__ {int rate; int mclk; int pllnl; int pllnh; int pllml; int pllmh; int plldiv; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int BIT (int) ; 
 int DVOL_CTL_DVMUTE_OFF ; 
 int DVOL_CTL_DVMUTE_ON ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int ML26124_BLT_ALL_ON ; 
 int ML26124_BLT_PREAMP_ON ; 
 int /*<<< orphan*/  ML26124_CLK_CTL ; 
 int /*<<< orphan*/  ML26124_DVOL_CTL ; 
 int ML26124_MICBEN_ON ; 
 int /*<<< orphan*/  ML26124_PLLDIV ; 
 int /*<<< orphan*/  ML26124_PLLMH ; 
 int /*<<< orphan*/  ML26124_PLLML ; 
 int /*<<< orphan*/  ML26124_PLLNH ; 
 int /*<<< orphan*/  ML26124_PLLNL ; 
 int /*<<< orphan*/  ML26124_PW_REF_PW_MNG ; 
 int /*<<< orphan*/  ML26124_PW_SPAMP_PW_MNG ; 
 int ML26124_R26_MASK ; 
 int /*<<< orphan*/  ML26124_REC_PLYBAK_RUN ; 
 int /*<<< orphan*/  ML26124_SAI_MODE_SEL ; 
 int /*<<< orphan*/  ML26124_SMPLING_RATE ; 
 int /*<<< orphan*/  ML26124_SW_RST ; 
#define  ML26124_USE_MCLKI 139 
#define  ML26124_USE_PLLOUT 138 
 int ML26124_VMID ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SNDRV_PCM_STREAM_CAPTURE 137 
#define  SNDRV_PCM_STREAM_PLAYBACK 136 
#define  SND_SOC_BIAS_OFF 135 
#define  SND_SOC_BIAS_ON 134 
#define  SND_SOC_BIAS_PREPARE 133 
#define  SND_SOC_BIAS_STANDBY 132 
#define  SND_SOC_DAIFMT_CBM_CFM 131 
#define  SND_SOC_DAIFMT_CBS_CFS 130 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 128 
 TYPE_1__* coeff_div ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct ml26124_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ml26124_priv*) ; 
 int /*<<< orphan*/  ml26124_dai ; 
 int /*<<< orphan*/  ml26124_i2c_regmap ; 
 int /*<<< orphan*/  msleep (int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 int snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct ml26124_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  soc_component_dev_ml26124 ; 

__attribute__((used)) static inline int get_srate(int rate)
{
	int srate;

	switch (rate) {
	case 16000:
		srate = 3;
		break;
	case 32000:
		srate = 6;
		break;
	case 48000:
		srate = 8;
		break;
	default:
		return -EINVAL;
	}
	return srate;
}

__attribute__((used)) static inline int get_coeff(int mclk, int rate)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
		if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
			return i;
	}
	return -EINVAL;
}

__attribute__((used)) static int ml26124_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *hw_params,
			    struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ml26124_priv *priv = snd_soc_component_get_drvdata(component);
	int i = get_coeff(priv->mclk, params_rate(hw_params));
	int srate;

	if (i < 0)
		return i;
	priv->substream = substream;
	priv->rate = params_rate(hw_params);

	if (priv->clk_in) {
		switch (priv->mclk / params_rate(hw_params)) {
		case 256:
			snd_soc_component_update_bits(component, ML26124_CLK_CTL,
					    BIT(0) | BIT(1), 1);
			break;
		case 512:
			snd_soc_component_update_bits(component, ML26124_CLK_CTL,
					    BIT(0) | BIT(1), 2);
			break;
		case 1024:
			snd_soc_component_update_bits(component, ML26124_CLK_CTL,
					    BIT(0) | BIT(1), 3);
			break;
		default:
			dev_err(component->dev, "Unsupported MCLKI\n");
			break;
		}
	} else {
		snd_soc_component_update_bits(component, ML26124_CLK_CTL,
				    BIT(0) | BIT(1), 0);
	}

	srate = get_srate(params_rate(hw_params));
	if (srate < 0)
		return srate;

	snd_soc_component_update_bits(component, ML26124_SMPLING_RATE, 0xf, srate);
	snd_soc_component_update_bits(component, ML26124_PLLNL, 0xff, coeff_div[i].pllnl);
	snd_soc_component_update_bits(component, ML26124_PLLNH, 0x1, coeff_div[i].pllnh);
	snd_soc_component_update_bits(component, ML26124_PLLML, 0xff, coeff_div[i].pllml);
	snd_soc_component_update_bits(component, ML26124_PLLMH, 0x3f, coeff_div[i].pllmh);
	snd_soc_component_update_bits(component, ML26124_PLLDIV, 0x1f, coeff_div[i].plldiv);

	return 0;
}

__attribute__((used)) static int ml26124_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct ml26124_priv *priv = snd_soc_component_get_drvdata(component);

	switch (priv->substream->stream) {
	case SNDRV_PCM_STREAM_CAPTURE:
		snd_soc_component_update_bits(component, ML26124_REC_PLYBAK_RUN, BIT(0), 1);
		break;
	case SNDRV_PCM_STREAM_PLAYBACK:
		snd_soc_component_update_bits(component, ML26124_REC_PLYBAK_RUN, BIT(1), 2);
		break;
	}

	if (mute)
		snd_soc_component_update_bits(component, ML26124_DVOL_CTL, BIT(4),
				    DVOL_CTL_DVMUTE_ON);
	else
		snd_soc_component_update_bits(component, ML26124_DVOL_CTL, BIT(4),
				    DVOL_CTL_DVMUTE_OFF);

	return 0;
}

__attribute__((used)) static int ml26124_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	unsigned char mode;
	struct snd_soc_component *component = codec_dai->component;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		mode = 1;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		mode = 0;
		break;
	default:
		return -EINVAL;
	}
	snd_soc_component_update_bits(component, ML26124_SAI_MODE_SEL, BIT(0), mode);

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int ml26124_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ml26124_priv *priv = snd_soc_component_get_drvdata(component);

	switch (clk_id) {
	case ML26124_USE_PLLOUT:
		priv->clk_in = ML26124_USE_PLLOUT;
		break;
	case ML26124_USE_MCLKI:
		priv->clk_in = ML26124_USE_MCLKI;
		break;
	default:
		return -EINVAL;
	}

	priv->mclk = freq;

	return 0;
}

__attribute__((used)) static int ml26124_set_bias_level(struct snd_soc_component *component,
		enum snd_soc_bias_level level)
{
	struct ml26124_priv *priv = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		snd_soc_component_update_bits(component, ML26124_PW_SPAMP_PW_MNG,
				    ML26124_R26_MASK, ML26124_BLT_PREAMP_ON);
		msleep(100);
		snd_soc_component_update_bits(component, ML26124_PW_SPAMP_PW_MNG,
				    ML26124_R26_MASK,
				    ML26124_MICBEN_ON | ML26124_BLT_ALL_ON);
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		/* VMID ON */
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF) {
			snd_soc_component_update_bits(component, ML26124_PW_REF_PW_MNG,
					    ML26124_VMID, ML26124_VMID);
			msleep(500);
			regcache_sync(priv->regmap);
		}
		break;
	case SND_SOC_BIAS_OFF:
		/* VMID OFF */
		snd_soc_component_update_bits(component, ML26124_PW_REF_PW_MNG,
				    ML26124_VMID, 0);
		break;
	}
	return 0;
}

__attribute__((used)) static int ml26124_probe(struct snd_soc_component *component)
{
	/* Software Reset */
	snd_soc_component_update_bits(component, ML26124_SW_RST, 0x01, 1);
	snd_soc_component_update_bits(component, ML26124_SW_RST, 0x01, 0);

	return 0;
}

__attribute__((used)) static int ml26124_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	struct ml26124_priv *priv;
	int ret;

	priv = devm_kzalloc(&i2c->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	i2c_set_clientdata(i2c, priv);

	priv->regmap = devm_regmap_init_i2c(i2c, &ml26124_i2c_regmap);
	if (IS_ERR(priv->regmap)) {
		ret = PTR_ERR(priv->regmap);
		dev_err(&i2c->dev, "regmap_init_i2c() failed: %d\n", ret);
		return ret;
	}

	return devm_snd_soc_register_component(&i2c->dev,
			&soc_component_dev_ml26124, &ml26124_dai, 1);
}


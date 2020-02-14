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
typedef  int u32 ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct of_device_id {struct ak4642_drvdata* data; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {struct device_node* of_node; } ;
struct i2c_client {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  struct regmap clk ;
struct ak4642_priv {struct regmap* mcko; struct ak4642_drvdata const* drvdata; } ;
struct ak4642_drvdata {int /*<<< orphan*/  regmap_config; int /*<<< orphan*/  extended_frequencies; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int ALC ; 
 int /*<<< orphan*/  ALC_CTL1 ; 
 int ARRAY_SIZE (int const*) ; 
 int BCKO_64 ; 
 int BCKO_MASK ; 
 int DIF_MASK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int FSs (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2S ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int LEFT_J ; 
 int LMTH0 ; 
 int LOPS ; 
 int /*<<< orphan*/  L_IVC ; 
 int MCKO ; 
 int /*<<< orphan*/  MD_CTL1 ; 
 int /*<<< orphan*/  MD_CTL2 ; 
 int MGAIN0 ; 
 int MS ; 
 int PLL0 ; 
 int PLL1 ; 
 int PLL2 ; 
 int PLL3 ; 
 int PLL_MASK ; 
 int PMADL ; 
 int PMADR ; 
 int PMMP ; 
 int PMPLL ; 
 int PMVCM ; 
 int PSs (int) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  PW_MGMT1 ; 
 int /*<<< orphan*/  PW_MGMT2 ; 
 int /*<<< orphan*/  PW_MGMT3 ; 
 int /*<<< orphan*/  R_IVC ; 
 int /*<<< orphan*/  SG_SL1 ; 
 int /*<<< orphan*/  SG_SL2 ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_BIAS_OFF 136 
#define  SND_SOC_DAIFMT_CBM_CFM 135 
#define  SND_SOC_DAIFMT_CBS_CFS 134 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 133 
#define  SND_SOC_DAIFMT_LEFT_J 132 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAPM_POST_PMD 131 
#define  SND_SOC_DAPM_POST_PMU 130 
#define  SND_SOC_DAPM_PRE_PMD 129 
#define  SND_SOC_DAPM_PRE_PMU 128 
 int /*<<< orphan*/  TIMER ; 
 int WTM (int) ; 
 int ZTM (int) ; 
 int /*<<< orphan*/  ak4642_dai ; 
 int /*<<< orphan*/  ak4642_of_match ; 
 struct regmap* ak4642_of_parse_mcko (struct device*) ; 
 int clk_get_rate (struct regmap*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct regmap* dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct ak4642_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ak4642_priv*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_cache_only (struct regmap*,int) ; 
 int /*<<< orphan*/  regcache_mark_dirty (struct regmap*) ; 
 int /*<<< orphan*/  regcache_sync (struct regmap*) ; 
 struct ak4642_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_ak4642 ; 

__attribute__((used)) static int ak4642_lout_event(struct snd_soc_dapm_widget *w,
			     struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_PRE_PMD:
	case SND_SOC_DAPM_PRE_PMU:
		/* Power save mode ON */
		snd_soc_component_update_bits(component, SG_SL2, LOPS, LOPS);
		break;
	case SND_SOC_DAPM_POST_PMU:
	case SND_SOC_DAPM_POST_PMD:
		/* Power save mode OFF */
		msleep(300);
		snd_soc_component_update_bits(component, SG_SL2, LOPS, 0);
		break;
	}

	return 0;
}

__attribute__((used)) static int ak4642_dai_startup(struct snd_pcm_substream *substream,
			      struct snd_soc_dai *dai)
{
	int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
	struct snd_soc_component *component = dai->component;

	if (is_play) {
		/*
		 * start headphone output
		 *
		 * PLL, Master Mode
		 * Audio I/F Format :MSB justified (ADC & DAC)
		 * Bass Boost Level : Middle
		 *
		 * This operation came from example code of
		 * "ASAHI KASEI AK4642" (japanese) manual p97.
		 */
		snd_soc_component_write(component, L_IVC, 0x91); /* volume */
		snd_soc_component_write(component, R_IVC, 0x91); /* volume */
	} else {
		/*
		 * start stereo input
		 *
		 * PLL Master Mode
		 * Audio I/F Format:MSB justified (ADC & DAC)
		 * Pre MIC AMP:+20dB
		 * MIC Power On
		 * ALC setting:Refer to Table 35
		 * ALC bit=“1”
		 *
		 * This operation came from example code of
		 * "ASAHI KASEI AK4642" (japanese) manual p94.
		 */
		snd_soc_component_update_bits(component, SG_SL1, PMMP | MGAIN0, PMMP | MGAIN0);
		snd_soc_component_write(component, TIMER, ZTM(0x3) | WTM(0x3));
		snd_soc_component_write(component, ALC_CTL1, ALC | LMTH0);
		snd_soc_component_update_bits(component, PW_MGMT1, PMADL, PMADL);
		snd_soc_component_update_bits(component, PW_MGMT3, PMADR, PMADR);
	}

	return 0;
}

__attribute__((used)) static void ak4642_dai_shutdown(struct snd_pcm_substream *substream,
			       struct snd_soc_dai *dai)
{
	int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
	struct snd_soc_component *component = dai->component;

	if (is_play) {
	} else {
		/* stop stereo input */
		snd_soc_component_update_bits(component, PW_MGMT1, PMADL, 0);
		snd_soc_component_update_bits(component, PW_MGMT3, PMADR, 0);
		snd_soc_component_update_bits(component, ALC_CTL1, ALC, 0);
	}
}

__attribute__((used)) static int ak4642_dai_set_sysclk(struct snd_soc_dai *codec_dai,
	int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ak4642_priv *priv = snd_soc_component_get_drvdata(component);
	u8 pll;
	int extended_freq = 0;

	switch (freq) {
	case 11289600:
		pll = PLL2;
		break;
	case 12288000:
		pll = PLL2 | PLL0;
		break;
	case 12000000:
		pll = PLL2 | PLL1;
		break;
	case 24000000:
		pll = PLL2 | PLL1 | PLL0;
		break;
	case 13500000:
		pll = PLL3 | PLL2;
		break;
	case 27000000:
		pll = PLL3 | PLL2 | PLL0;
		break;
	case 19200000:
		pll = PLL3;
		extended_freq = 1;
		break;
	case 13000000:
		pll = PLL3 | PLL2 | PLL1;
		extended_freq = 1;
		break;
	case 26000000:
		pll = PLL3 | PLL2 | PLL1 | PLL0;
		extended_freq = 1;
		break;
	default:
		return -EINVAL;
	}

	if (extended_freq && !priv->drvdata->extended_frequencies)
		return -EINVAL;

	snd_soc_component_update_bits(component, MD_CTL1, PLL_MASK, pll);

	return 0;
}

__attribute__((used)) static int ak4642_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	u8 data;
	u8 bcko;

	data = MCKO | PMPLL; /* use MCKO */
	bcko = 0;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		data |= MS;
		bcko = BCKO_64;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}
	snd_soc_component_update_bits(component, PW_MGMT2, MS | MCKO | PMPLL, data);
	snd_soc_component_update_bits(component, MD_CTL1, BCKO_MASK, bcko);

	/* format type */
	data = 0;
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_LEFT_J:
		data = LEFT_J;
		break;
	case SND_SOC_DAIFMT_I2S:
		data = I2S;
		break;
	/* FIXME
	 * Please add RIGHT_J / DSP support here
	 */
	default:
		return -EINVAL;
	}
	snd_soc_component_update_bits(component, MD_CTL1, DIF_MASK, data);

	return 0;
}

__attribute__((used)) static int ak4642_set_mcko(struct snd_soc_component *component,
			   u32 frequency)
{
	static const u32 fs_list[] = {
		[0] = 8000,
		[1] = 12000,
		[2] = 16000,
		[3] = 24000,
		[4] = 7350,
		[5] = 11025,
		[6] = 14700,
		[7] = 22050,
		[10] = 32000,
		[11] = 48000,
		[14] = 29400,
		[15] = 44100,
	};
	static const u32 ps_list[] = {
		[0] = 256,
		[1] = 128,
		[2] = 64,
		[3] = 32
	};
	int ps, fs;

	for (ps = 0; ps < ARRAY_SIZE(ps_list); ps++) {
		for (fs = 0; fs < ARRAY_SIZE(fs_list); fs++) {
			if (frequency == ps_list[ps] * fs_list[fs]) {
				snd_soc_component_write(component, MD_CTL2,
					      PSs(ps) | FSs(fs));
				return 0;
			}
		}
	}

	return 0;
}

__attribute__((used)) static int ak4642_dai_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ak4642_priv *priv = snd_soc_component_get_drvdata(component);
	u32 rate = clk_get_rate(priv->mcko);

	if (!rate)
		rate = params_rate(params) * 256;

	return ak4642_set_mcko(component, rate);
}

__attribute__((used)) static int ak4642_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	switch (level) {
	case SND_SOC_BIAS_OFF:
		snd_soc_component_write(component, PW_MGMT1, 0x00);
		break;
	default:
		snd_soc_component_update_bits(component, PW_MGMT1, PMVCM, PMVCM);
		break;
	}

	return 0;
}

__attribute__((used)) static int ak4642_suspend(struct snd_soc_component *component)
{
	struct regmap *regmap = dev_get_regmap(component->dev, NULL);

	regcache_cache_only(regmap, true);
	regcache_mark_dirty(regmap);
	return 0;
}

__attribute__((used)) static int ak4642_resume(struct snd_soc_component *component)
{
	struct regmap *regmap = dev_get_regmap(component->dev, NULL);

	regcache_cache_only(regmap, false);
	regcache_sync(regmap);
	return 0;
}

__attribute__((used)) static int ak4642_probe(struct snd_soc_component *component)
{
	struct ak4642_priv *priv = snd_soc_component_get_drvdata(component);

	if (priv->mcko)
		ak4642_set_mcko(component, clk_get_rate(priv->mcko));

	return 0;
}

__attribute__((used)) static int ak4642_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct device *dev = &i2c->dev;
	struct device_node *np = dev->of_node;
	const struct ak4642_drvdata *drvdata = NULL;
	struct regmap *regmap;
	struct ak4642_priv *priv;
	struct clk *mcko = NULL;

	if (np) {
		const struct of_device_id *of_id;

		mcko = ak4642_of_parse_mcko(dev);
		if (IS_ERR(mcko))
			mcko = NULL;

		of_id = of_match_device(ak4642_of_match, dev);
		if (of_id)
			drvdata = of_id->data;
	} else {
		drvdata = (const struct ak4642_drvdata *)id->driver_data;
	}

	if (!drvdata) {
		dev_err(dev, "Unknown device type\n");
		return -EINVAL;
	}

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->drvdata = drvdata;
	priv->mcko = mcko;

	i2c_set_clientdata(i2c, priv);

	regmap = devm_regmap_init_i2c(i2c, drvdata->regmap_config);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	return devm_snd_soc_register_component(dev,
				&soc_component_dev_ak4642, &ak4642_dai, 1);
}


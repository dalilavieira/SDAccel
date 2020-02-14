#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct ssm2602_priv {int sysclk; unsigned int clk_out_pwr; int type; struct regmap* regmap; int /*<<< orphan*/ * sysclk_constraints; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int /*<<< orphan*/  runtime; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap {int dummy; } ;
struct device {int dummy; } ;
typedef  enum ssm2602_type { ____Placeholder_ssm2602_type } ssm2602_type ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_11__ {int rate; int mclk; int srate; } ;

/* Variables and functions */
 unsigned int APANA_ENABLE_MIC_BOOST ; 
 unsigned int APANA_SELECT_DAC ; 
 unsigned int APDIGI_ENABLE_DAC_MUTE ; 
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int IFACE_AUDIO_DATA_LEN ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 unsigned int LINVOL_LRIN_BOTH ; 
 unsigned int LOUT1V_LRHP_BOTH ; 
 int PTR_ERR (struct regmap*) ; 
 unsigned int PWR_CLK_OUT_PDN ; 
 unsigned int PWR_OSC_PDN ; 
 unsigned int PWR_POWER_OFF ; 
 unsigned int RINVOL_RLIN_BOTH ; 
 unsigned int ROUT1V_RLHP_BOTH ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
#define  SND_SOC_BIAS_OFF 146 
#define  SND_SOC_BIAS_ON 145 
#define  SND_SOC_BIAS_PREPARE 144 
#define  SND_SOC_BIAS_STANDBY 143 
 int SND_SOC_CLOCK_IN ; 
#define  SND_SOC_DAIFMT_CBM_CFM 142 
#define  SND_SOC_DAIFMT_CBS_CFS 141 
#define  SND_SOC_DAIFMT_DSP_A 140 
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
#define  SSM2602 131 
 unsigned int SSM2602_APANA ; 
 unsigned int SSM2602_APDIGI ; 
#define  SSM2602_CLK_CLKOUT 130 
#define  SSM2602_CLK_XTO 129 
 unsigned int SSM2602_IFACE ; 
 unsigned int SSM2602_LINVOL ; 
 unsigned int SSM2602_LOUT1V ; 
 unsigned int SSM2602_PWR ; 
 unsigned int SSM2602_RESET ; 
 unsigned int SSM2602_RINVOL ; 
 unsigned int SSM2602_ROUT1V ; 
 unsigned int SSM2602_SRATE ; 
 int SSM2602_SYSCLK ; 
#define  SSM2604 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ssm2602_priv*) ; 
 struct ssm2602_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_sync (struct regmap*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,unsigned int,unsigned int,unsigned int) ; 
 int regmap_write (struct regmap*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_list (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,TYPE_1__*,int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct ssm2602_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,TYPE_1__*,int) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  soc_component_dev_ssm2602 ; 
 TYPE_1__* ssm2602_coeff_table ; 
 int /*<<< orphan*/  ssm2602_constraints_11289600 ; 
 int /*<<< orphan*/  ssm2602_constraints_12288000 ; 
 int /*<<< orphan*/  ssm2602_dai ; 
 TYPE_1__* ssm2602_dapm_widgets ; 
 TYPE_1__* ssm2602_routes ; 
 TYPE_1__* ssm2602_snd_controls ; 
 TYPE_1__* ssm2604_dapm_widgets ; 
 TYPE_1__* ssm2604_routes ; 

__attribute__((used)) static inline int ssm2602_get_coeff(int mclk, int rate)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(ssm2602_coeff_table); i++) {
		if (ssm2602_coeff_table[i].rate == rate &&
			ssm2602_coeff_table[i].mclk == mclk)
			return ssm2602_coeff_table[i].srate;
	}
	return -EINVAL;
}

__attribute__((used)) static int ssm2602_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);
	int srate = ssm2602_get_coeff(ssm2602->sysclk, params_rate(params));
	unsigned int iface;

	if (srate < 0)
		return srate;

	regmap_write(ssm2602->regmap, SSM2602_SRATE, srate);

	/* bit size */
	switch (params_width(params)) {
	case 16:
		iface = 0x0;
		break;
	case 20:
		iface = 0x4;
		break;
	case 24:
		iface = 0x8;
		break;
	case 32:
		iface = 0xc;
		break;
	default:
		return -EINVAL;
	}
	regmap_update_bits(ssm2602->regmap, SSM2602_IFACE,
		IFACE_AUDIO_DATA_LEN, iface);
	return 0;
}

__attribute__((used)) static int ssm2602_startup(struct snd_pcm_substream *substream,
			   struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);

	if (ssm2602->sysclk_constraints) {
		snd_pcm_hw_constraint_list(substream->runtime, 0,
				   SNDRV_PCM_HW_PARAM_RATE,
				   ssm2602->sysclk_constraints);
	}

	return 0;
}

__attribute__((used)) static int ssm2602_mute(struct snd_soc_dai *dai, int mute)
{
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(dai->component);

	if (mute)
		regmap_update_bits(ssm2602->regmap, SSM2602_APDIGI,
				    APDIGI_ENABLE_DAC_MUTE,
				    APDIGI_ENABLE_DAC_MUTE);
	else
		regmap_update_bits(ssm2602->regmap, SSM2602_APDIGI,
				    APDIGI_ENABLE_DAC_MUTE, 0);
	return 0;
}

__attribute__((used)) static int ssm2602_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);

	if (dir == SND_SOC_CLOCK_IN) {
		if (clk_id != SSM2602_SYSCLK)
			return -EINVAL;

		switch (freq) {
		case 12288000:
		case 18432000:
			ssm2602->sysclk_constraints = &ssm2602_constraints_12288000;
			break;
		case 11289600:
		case 16934400:
			ssm2602->sysclk_constraints = &ssm2602_constraints_11289600;
			break;
		case 12000000:
			ssm2602->sysclk_constraints = NULL;
			break;
		default:
			return -EINVAL;
		}
		ssm2602->sysclk = freq;
	} else {
		unsigned int mask;

		switch (clk_id) {
		case SSM2602_CLK_CLKOUT:
			mask = PWR_CLK_OUT_PDN;
			break;
		case SSM2602_CLK_XTO:
			mask = PWR_OSC_PDN;
			break;
		default:
			return -EINVAL;
		}

		if (freq == 0)
			ssm2602->clk_out_pwr |= mask;
		else
			ssm2602->clk_out_pwr &= ~mask;

		regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
			PWR_CLK_OUT_PDN | PWR_OSC_PDN, ssm2602->clk_out_pwr);
	}

	return 0;
}

__attribute__((used)) static int ssm2602_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(codec_dai->component);
	unsigned int iface = 0;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		iface |= 0x0040;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		break;
	default:
		return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		iface |= 0x0002;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		iface |= 0x0001;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		iface |= 0x0013;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		iface |= 0x0003;
		break;
	default:
		return -EINVAL;
	}

	/* clock inversion */
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_IF:
		iface |= 0x0090;
		break;
	case SND_SOC_DAIFMT_IB_NF:
		iface |= 0x0080;
		break;
	case SND_SOC_DAIFMT_NB_IF:
		iface |= 0x0010;
		break;
	default:
		return -EINVAL;
	}

	/* set iface */
	regmap_write(ssm2602->regmap, SSM2602_IFACE, iface);
	return 0;
}

__attribute__((used)) static int ssm2602_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);

	switch (level) {
	case SND_SOC_BIAS_ON:
		/* vref/mid on, osc and clkout on if enabled */
		regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
			PWR_POWER_OFF | PWR_CLK_OUT_PDN | PWR_OSC_PDN,
			ssm2602->clk_out_pwr);
		break;
	case SND_SOC_BIAS_PREPARE:
		break;
	case SND_SOC_BIAS_STANDBY:
		/* everything off except vref/vmid, */
		regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
			PWR_POWER_OFF | PWR_CLK_OUT_PDN | PWR_OSC_PDN,
			PWR_CLK_OUT_PDN | PWR_OSC_PDN);
		break;
	case SND_SOC_BIAS_OFF:
		/* everything off */
		regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
			PWR_POWER_OFF, PWR_POWER_OFF);
		break;

	}
	return 0;
}

__attribute__((used)) static int ssm2602_resume(struct snd_soc_component *component)
{
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);

	regcache_sync(ssm2602->regmap);

	return 0;
}

__attribute__((used)) static int ssm2602_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);
	int ret;

	regmap_update_bits(ssm2602->regmap, SSM2602_LOUT1V,
			    LOUT1V_LRHP_BOTH, LOUT1V_LRHP_BOTH);
	regmap_update_bits(ssm2602->regmap, SSM2602_ROUT1V,
			    ROUT1V_RLHP_BOTH, ROUT1V_RLHP_BOTH);

	ret = snd_soc_add_component_controls(component, ssm2602_snd_controls,
			ARRAY_SIZE(ssm2602_snd_controls));
	if (ret)
		return ret;

	ret = snd_soc_dapm_new_controls(dapm, ssm2602_dapm_widgets,
			ARRAY_SIZE(ssm2602_dapm_widgets));
	if (ret)
		return ret;

	return snd_soc_dapm_add_routes(dapm, ssm2602_routes,
			ARRAY_SIZE(ssm2602_routes));
}

__attribute__((used)) static int ssm2604_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	int ret;

	ret = snd_soc_dapm_new_controls(dapm, ssm2604_dapm_widgets,
			ARRAY_SIZE(ssm2604_dapm_widgets));
	if (ret)
		return ret;

	return snd_soc_dapm_add_routes(dapm, ssm2604_routes,
			ARRAY_SIZE(ssm2604_routes));
}

__attribute__((used)) static int ssm260x_component_probe(struct snd_soc_component *component)
{
	struct ssm2602_priv *ssm2602 = snd_soc_component_get_drvdata(component);
	int ret;

	ret = regmap_write(ssm2602->regmap, SSM2602_RESET, 0);
	if (ret < 0) {
		dev_err(component->dev, "Failed to issue reset: %d\n", ret);
		return ret;
	}

	/* set the update bits */
	regmap_update_bits(ssm2602->regmap, SSM2602_LINVOL,
			    LINVOL_LRIN_BOTH, LINVOL_LRIN_BOTH);
	regmap_update_bits(ssm2602->regmap, SSM2602_RINVOL,
			    RINVOL_RLIN_BOTH, RINVOL_RLIN_BOTH);
	/*select Line in as default input*/
	regmap_write(ssm2602->regmap, SSM2602_APANA, APANA_SELECT_DAC |
			APANA_ENABLE_MIC_BOOST);

	switch (ssm2602->type) {
	case SSM2602:
		ret = ssm2602_component_probe(component);
		break;
	case SSM2604:
		ret = ssm2604_component_probe(component);
		break;
	}

	return ret;
}

__attribute__((used)) static bool ssm2602_register_volatile(struct device *dev, unsigned int reg)
{
	return reg == SSM2602_RESET;
}

int ssm2602_probe(struct device *dev, enum ssm2602_type type,
	struct regmap *regmap)
{
	struct ssm2602_priv *ssm2602;

	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	ssm2602 = devm_kzalloc(dev, sizeof(*ssm2602), GFP_KERNEL);
	if (ssm2602 == NULL)
		return -ENOMEM;

	dev_set_drvdata(dev, ssm2602);
	ssm2602->type = type;
	ssm2602->regmap = regmap;

	return devm_snd_soc_register_component(dev, &soc_component_dev_ssm2602,
		&ssm2602_dai, 1);
}


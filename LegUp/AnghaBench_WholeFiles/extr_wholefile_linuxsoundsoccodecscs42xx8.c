#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  size_t u32 ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap {int dummy; } ;
struct of_device_id {TYPE_2__* data; } ;
struct device {int dummy; } ;
struct cs42xx8_priv {unsigned int sysclk; int slave_mode; int tx_channels; TYPE_3__* supplies; struct regmap* regmap; TYPE_2__* drvdata; struct regmap* clk; } ;
struct TYPE_16__ {int channels_max; } ;
struct TYPE_19__ {TYPE_1__ capture; int /*<<< orphan*/  name; } ;
struct TYPE_18__ {size_t ratio; size_t mclk; size_t speed; int /*<<< orphan*/  supply; } ;
struct TYPE_17__ {int num_adcs; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
#define  CS42XX8_CHIPID 135 
 int CS42XX8_CHIPID_CHIP_ID_MASK ; 
 int CS42XX8_CHIPID_REV_ID_MASK ; 
 int /*<<< orphan*/  CS42XX8_DACMUTE ; 
 int CS42XX8_DACMUTE_ALL ; 
 size_t CS42XX8_FM_AUTO ; 
 int /*<<< orphan*/  CS42XX8_FUNCMOD ; 
 size_t CS42XX8_FUNCMOD_MFREQ_MASK ; 
 size_t CS42XX8_FUNCMOD_xC_FM (int,size_t) ; 
 size_t CS42XX8_FUNCMOD_xC_FM_MASK (int) ; 
 int /*<<< orphan*/  CS42XX8_INTF ; 
 size_t CS42XX8_INTF_ADC_DIF_I2S ; 
 size_t CS42XX8_INTF_ADC_DIF_LEFTJ ; 
 size_t CS42XX8_INTF_ADC_DIF_MASK ; 
 size_t CS42XX8_INTF_ADC_DIF_RIGHTJ ; 
 size_t CS42XX8_INTF_ADC_DIF_TDM ; 
 size_t CS42XX8_INTF_DAC_DIF_I2S ; 
 size_t CS42XX8_INTF_DAC_DIF_LEFTJ ; 
 size_t CS42XX8_INTF_DAC_DIF_MASK ; 
 size_t CS42XX8_INTF_DAC_DIF_RIGHTJ ; 
 size_t CS42XX8_INTF_DAC_DIF_TDM ; 
#define  CS42XX8_STATUS 134 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_DAIFMT_CBM_CFM 133 
#define  SND_SOC_DAIFMT_CBS_CFS 132 
#define  SND_SOC_DAIFMT_DSP_A 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 size_t clk_get_rate (struct regmap*) ; 
 TYPE_3__* cs42xx8_adc3_dapm_routes ; 
 TYPE_3__* cs42xx8_adc3_dapm_widgets ; 
 TYPE_3__* cs42xx8_adc3_snd_controls ; 
 TYPE_8__ cs42xx8_dai ; 
 int /*<<< orphan*/  cs42xx8_driver ; 
 int /*<<< orphan*/  cs42xx8_of_match ; 
 TYPE_3__* cs42xx8_ratios ; 
 int /*<<< orphan*/ * cs42xx8_supply_names ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct cs42xx8_priv*) ; 
 struct regmap* devm_clk_get (struct device*,char*) ; 
 struct cs42xx8_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_3__*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,TYPE_8__*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 size_t params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  regcache_cache_only (struct regmap*,int) ; 
 int regmap_read (struct regmap*,int const,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,size_t,size_t) ; 
 int /*<<< orphan*/  regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_3__*) ; 
 int regulator_bulk_enable (int,TYPE_3__*) ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,TYPE_3__*,int) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct cs42xx8_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,TYPE_3__*,int) ; 
 int /*<<< orphan*/  snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,TYPE_3__*,int) ; 

__attribute__((used)) static int cs42xx8_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				  int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct cs42xx8_priv *cs42xx8 = snd_soc_component_get_drvdata(component);

	cs42xx8->sysclk = freq;

	return 0;
}

__attribute__((used)) static int cs42xx8_set_dai_fmt(struct snd_soc_dai *codec_dai,
			       unsigned int format)
{
	struct snd_soc_component *component = codec_dai->component;
	struct cs42xx8_priv *cs42xx8 = snd_soc_component_get_drvdata(component);
	u32 val;

	/* Set DAI format */
	switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_LEFT_J:
		val = CS42XX8_INTF_DAC_DIF_LEFTJ | CS42XX8_INTF_ADC_DIF_LEFTJ;
		break;
	case SND_SOC_DAIFMT_I2S:
		val = CS42XX8_INTF_DAC_DIF_I2S | CS42XX8_INTF_ADC_DIF_I2S;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		val = CS42XX8_INTF_DAC_DIF_RIGHTJ | CS42XX8_INTF_ADC_DIF_RIGHTJ;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		val = CS42XX8_INTF_DAC_DIF_TDM | CS42XX8_INTF_ADC_DIF_TDM;
		break;
	default:
		dev_err(component->dev, "unsupported dai format\n");
		return -EINVAL;
	}

	regmap_update_bits(cs42xx8->regmap, CS42XX8_INTF,
			   CS42XX8_INTF_DAC_DIF_MASK |
			   CS42XX8_INTF_ADC_DIF_MASK, val);

	/* Set master/slave audio interface */
	switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		cs42xx8->slave_mode = true;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		cs42xx8->slave_mode = false;
		break;
	default:
		dev_err(component->dev, "unsupported master/slave mode\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int cs42xx8_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct cs42xx8_priv *cs42xx8 = snd_soc_component_get_drvdata(component);
	bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
	u32 ratio = cs42xx8->sysclk / params_rate(params);
	u32 i, fm, val, mask;

	if (tx)
		cs42xx8->tx_channels = params_channels(params);

	for (i = 0; i < ARRAY_SIZE(cs42xx8_ratios); i++) {
		if (cs42xx8_ratios[i].ratio == ratio)
			break;
	}

	if (i == ARRAY_SIZE(cs42xx8_ratios)) {
		dev_err(component->dev, "unsupported sysclk ratio\n");
		return -EINVAL;
	}

	mask = CS42XX8_FUNCMOD_MFREQ_MASK;
	val = cs42xx8_ratios[i].mclk;

	fm = cs42xx8->slave_mode ? CS42XX8_FM_AUTO : cs42xx8_ratios[i].speed;

	regmap_update_bits(cs42xx8->regmap, CS42XX8_FUNCMOD,
			   CS42XX8_FUNCMOD_xC_FM_MASK(tx) | mask,
			   CS42XX8_FUNCMOD_xC_FM(tx, fm) | val);

	return 0;
}

__attribute__((used)) static int cs42xx8_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct cs42xx8_priv *cs42xx8 = snd_soc_component_get_drvdata(component);
	u8 dac_unmute = cs42xx8->tx_channels ?
		        ~((0x1 << cs42xx8->tx_channels) - 1) : 0;

	regmap_write(cs42xx8->regmap, CS42XX8_DACMUTE,
		     mute ? CS42XX8_DACMUTE_ALL : dac_unmute);

	return 0;
}

__attribute__((used)) static bool cs42xx8_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case CS42XX8_STATUS:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool cs42xx8_writeable_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case CS42XX8_CHIPID:
	case CS42XX8_STATUS:
		return false;
	default:
		return true;
	}
}

__attribute__((used)) static int cs42xx8_component_probe(struct snd_soc_component *component)
{
	struct cs42xx8_priv *cs42xx8 = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);

	switch (cs42xx8->drvdata->num_adcs) {
	case 3:
		snd_soc_add_component_controls(component, cs42xx8_adc3_snd_controls,
					ARRAY_SIZE(cs42xx8_adc3_snd_controls));
		snd_soc_dapm_new_controls(dapm, cs42xx8_adc3_dapm_widgets,
					ARRAY_SIZE(cs42xx8_adc3_dapm_widgets));
		snd_soc_dapm_add_routes(dapm, cs42xx8_adc3_dapm_routes,
					ARRAY_SIZE(cs42xx8_adc3_dapm_routes));
		break;
	default:
		break;
	}

	/* Mute all DAC channels */
	regmap_write(cs42xx8->regmap, CS42XX8_DACMUTE, CS42XX8_DACMUTE_ALL);

	return 0;
}

int cs42xx8_probe(struct device *dev, struct regmap *regmap)
{
	const struct of_device_id *of_id;
	struct cs42xx8_priv *cs42xx8;
	int ret, val, i;

	if (IS_ERR(regmap)) {
		ret = PTR_ERR(regmap);
		dev_err(dev, "failed to allocate regmap: %d\n", ret);
		return ret;
	}

	cs42xx8 = devm_kzalloc(dev, sizeof(*cs42xx8), GFP_KERNEL);
	if (cs42xx8 == NULL)
		return -ENOMEM;

	cs42xx8->regmap = regmap;
	dev_set_drvdata(dev, cs42xx8);

	of_id = of_match_device(cs42xx8_of_match, dev);
	if (of_id)
		cs42xx8->drvdata = of_id->data;

	if (!cs42xx8->drvdata) {
		dev_err(dev, "failed to find driver data\n");
		return -EINVAL;
	}

	cs42xx8->clk = devm_clk_get(dev, "mclk");
	if (IS_ERR(cs42xx8->clk)) {
		dev_err(dev, "failed to get the clock: %ld\n",
				PTR_ERR(cs42xx8->clk));
		return -EINVAL;
	}

	cs42xx8->sysclk = clk_get_rate(cs42xx8->clk);

	for (i = 0; i < ARRAY_SIZE(cs42xx8->supplies); i++)
		cs42xx8->supplies[i].supply = cs42xx8_supply_names[i];

	ret = devm_regulator_bulk_get(dev,
			ARRAY_SIZE(cs42xx8->supplies), cs42xx8->supplies);
	if (ret) {
		dev_err(dev, "failed to request supplies: %d\n", ret);
		return ret;
	}

	ret = regulator_bulk_enable(ARRAY_SIZE(cs42xx8->supplies),
				    cs42xx8->supplies);
	if (ret) {
		dev_err(dev, "failed to enable supplies: %d\n", ret);
		return ret;
	}

	/* Make sure hardware reset done */
	msleep(5);

	/* Validate the chip ID */
	ret = regmap_read(cs42xx8->regmap, CS42XX8_CHIPID, &val);
	if (ret < 0) {
		dev_err(dev, "failed to get device ID, ret = %d", ret);
		goto err_enable;
	}

	/* The top four bits of the chip ID should be 0000 */
	if (((val & CS42XX8_CHIPID_CHIP_ID_MASK) >> 4) != 0x00) {
		dev_err(dev, "unmatched chip ID: %d\n",
			(val & CS42XX8_CHIPID_CHIP_ID_MASK) >> 4);
		ret = -EINVAL;
		goto err_enable;
	}

	dev_info(dev, "found device, revision %X\n",
			val & CS42XX8_CHIPID_REV_ID_MASK);

	cs42xx8_dai.name = cs42xx8->drvdata->name;

	/* Each adc supports stereo input */
	cs42xx8_dai.capture.channels_max = cs42xx8->drvdata->num_adcs * 2;

	ret = devm_snd_soc_register_component(dev, &cs42xx8_driver, &cs42xx8_dai, 1);
	if (ret) {
		dev_err(dev, "failed to register component:%d\n", ret);
		goto err_enable;
	}

	regcache_cache_only(cs42xx8->regmap, true);

err_enable:
	regulator_bulk_disable(ARRAY_SIZE(cs42xx8->supplies),
			       cs42xx8->supplies);

	return ret;
}


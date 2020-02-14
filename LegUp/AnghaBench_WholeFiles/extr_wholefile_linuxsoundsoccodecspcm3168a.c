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
typedef  int u32 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {scalar_t__ stream; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct regmap {int dummy; } ;
struct pcm3168a_priv {unsigned int sysclk; int dac_master_mode; int dac_fmt; int adc_master_mode; int adc_fmt; struct regmap* scki; TYPE_1__* supplies; struct regmap* regmap; } ;
struct device {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  supply; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  DIV_ROUND_UP (int,unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 unsigned int PCM1368A_MAX_SYSCLK ; 
 int PCM3168A_ADC_FMTAD_MASK ; 
 int PCM3168A_ADC_FMTAD_SHIFT ; 
 int PCM3168A_ADC_MSAD_MASK ; 
 int PCM3168A_ADC_MSAD_SHIFT ; 
 int PCM3168A_ADC_MST_FMT ; 
#define  PCM3168A_ADC_OV 137 
 int PCM3168A_DAC_FMT_MASK ; 
 int PCM3168A_DAC_FMT_SHIFT ; 
 int PCM3168A_DAC_MSDA_MASK ; 
 int PCM3168A_DAC_MSDA_SHIFT ; 
 unsigned int PCM3168A_DAC_MUTE ; 
 int PCM3168A_DAC_PWR_MST_FMT ; 
#define  PCM3168A_DAC_ZERO 136 
 int PCM3168A_FMT_DSP_A ; 
 int PCM3168A_FMT_DSP_B ; 
 unsigned int PCM3168A_FMT_DSP_MASK ; 
 int PCM3168A_FMT_I2S ; 
 int PCM3168A_FMT_LEFT_J ; 
 unsigned int PCM3168A_FMT_RIGHT_J ; 
 unsigned int PCM3168A_FMT_RIGHT_J_16 ; 
 int PCM3168A_MRST_MASK ; 
 unsigned int PCM3168A_NUM_SCKI_RATIOS_ADC ; 
 unsigned int PCM3168A_NUM_SCKI_RATIOS_DAC ; 
 unsigned int PCM3168A_RST_SMODE ; 
 int PCM3168A_SRST_MASK ; 
 int PTR_ERR (struct regmap*) ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SND_SOC_DAIFMT_CBM_CFM 135 
#define  SND_SOC_DAIFMT_CBS_CFS 134 
#define  SND_SOC_DAIFMT_DSP_A 133 
#define  SND_SOC_DAIFMT_DSP_B 132 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 131 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 130 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  clk_disable_unprepare (struct regmap*) ; 
 unsigned int clk_get_rate (struct regmap*) ; 
 int clk_prepare_enable (struct regmap*) ; 
 int clk_set_rate (struct regmap*,unsigned int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct pcm3168a_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct pcm3168a_priv*) ; 
 struct regmap* devm_clk_get (struct device*,char*) ; 
 struct pcm3168a_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_1__*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 TYPE_1__* pcm3168a_dais ; 
 int /*<<< orphan*/  pcm3168a_driver ; 
 unsigned int* pcm3168a_scki_ratios ; 
 int /*<<< orphan*/ * pcm3168a_supply_names ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_idle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,int,int,unsigned int) ; 
 int regmap_write (struct regmap*,unsigned int,int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_1__*) ; 
 int regulator_bulk_enable (int,TYPE_1__*) ; 
 struct pcm3168a_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int pcm3168a_reset(struct pcm3168a_priv *pcm3168a)
{
	int ret;

	ret = regmap_write(pcm3168a->regmap, PCM3168A_RST_SMODE, 0);
	if (ret)
		return ret;

	/* Internal reset is de-asserted after 3846 SCKI cycles */
	msleep(DIV_ROUND_UP(3846 * 1000, pcm3168a->sysclk));

	return regmap_write(pcm3168a->regmap, PCM3168A_RST_SMODE,
			PCM3168A_MRST_MASK | PCM3168A_SRST_MASK);
}

__attribute__((used)) static int pcm3168a_digital_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct pcm3168a_priv *pcm3168a = snd_soc_component_get_drvdata(component);

	regmap_write(pcm3168a->regmap, PCM3168A_DAC_MUTE, mute ? 0xff : 0);

	return 0;
}

__attribute__((used)) static int pcm3168a_set_dai_sysclk(struct snd_soc_dai *dai,
				  int clk_id, unsigned int freq, int dir)
{
	struct pcm3168a_priv *pcm3168a = snd_soc_component_get_drvdata(dai->component);
	int ret;

	if (freq > PCM1368A_MAX_SYSCLK)
		return -EINVAL;

	ret = clk_set_rate(pcm3168a->scki, freq);
	if (ret)
		return ret;

	pcm3168a->sysclk = freq;

	return 0;
}

__attribute__((used)) static int pcm3168a_set_dai_fmt(struct snd_soc_dai *dai,
			       unsigned int format, bool dac)
{
	struct snd_soc_component *component = dai->component;
	struct pcm3168a_priv *pcm3168a = snd_soc_component_get_drvdata(component);
	u32 fmt, reg, mask, shift;
	bool master_mode;

	switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_LEFT_J:
		fmt = PCM3168A_FMT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_I2S:
		fmt = PCM3168A_FMT_I2S;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		fmt = PCM3168A_FMT_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		fmt = PCM3168A_FMT_DSP_A;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		fmt = PCM3168A_FMT_DSP_B;
		break;
	default:
		dev_err(component->dev, "unsupported dai format\n");
		return -EINVAL;
	}

	switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		master_mode = false;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		master_mode = true;
		break;
	default:
		dev_err(component->dev, "unsupported master/slave mode\n");
		return -EINVAL;
	}

	switch (format & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	default:
		return -EINVAL;
	}

	if (dac) {
		reg = PCM3168A_DAC_PWR_MST_FMT;
		mask = PCM3168A_DAC_FMT_MASK;
		shift = PCM3168A_DAC_FMT_SHIFT;
		pcm3168a->dac_master_mode = master_mode;
		pcm3168a->dac_fmt = fmt;
	} else {
		reg = PCM3168A_ADC_MST_FMT;
		mask = PCM3168A_ADC_FMTAD_MASK;
		shift = PCM3168A_ADC_FMTAD_SHIFT;
		pcm3168a->adc_master_mode = master_mode;
		pcm3168a->adc_fmt = fmt;
	}

	regmap_update_bits(pcm3168a->regmap, reg, mask, fmt << shift);

	return 0;
}

__attribute__((used)) static int pcm3168a_set_dai_fmt_dac(struct snd_soc_dai *dai,
			       unsigned int format)
{
	return pcm3168a_set_dai_fmt(dai, format, true);
}

__attribute__((used)) static int pcm3168a_set_dai_fmt_adc(struct snd_soc_dai *dai,
			       unsigned int format)
{
	return pcm3168a_set_dai_fmt(dai, format, false);
}

__attribute__((used)) static int pcm3168a_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct pcm3168a_priv *pcm3168a = snd_soc_component_get_drvdata(component);
	bool tx, master_mode;
	u32 val, mask, shift, reg;
	unsigned int rate, fmt, ratio, max_ratio;
	int i, min_frame_size;

	rate = params_rate(params);

	ratio = pcm3168a->sysclk / rate;

	tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
	if (tx) {
		max_ratio = PCM3168A_NUM_SCKI_RATIOS_DAC;
		reg = PCM3168A_DAC_PWR_MST_FMT;
		mask = PCM3168A_DAC_MSDA_MASK;
		shift = PCM3168A_DAC_MSDA_SHIFT;
		master_mode = pcm3168a->dac_master_mode;
		fmt = pcm3168a->dac_fmt;
	} else {
		max_ratio = PCM3168A_NUM_SCKI_RATIOS_ADC;
		reg = PCM3168A_ADC_MST_FMT;
		mask = PCM3168A_ADC_MSAD_MASK;
		shift = PCM3168A_ADC_MSAD_SHIFT;
		master_mode = pcm3168a->adc_master_mode;
		fmt = pcm3168a->adc_fmt;
	}

	for (i = 0; i < max_ratio; i++) {
		if (pcm3168a_scki_ratios[i] == ratio)
			break;
	}

	if (i == max_ratio) {
		dev_err(component->dev, "unsupported sysclk ratio\n");
		return -EINVAL;
	}

	min_frame_size = params_width(params) * 2;
	switch (min_frame_size) {
	case 32:
		if (master_mode || (fmt != PCM3168A_FMT_RIGHT_J)) {
			dev_err(component->dev, "32-bit frames are supported only for slave mode using right justified\n");
			return -EINVAL;
		}
		fmt = PCM3168A_FMT_RIGHT_J_16;
		break;
	case 48:
		if (master_mode || (fmt & PCM3168A_FMT_DSP_MASK)) {
			dev_err(component->dev, "48-bit frames not supported in master mode, or slave mode using DSP\n");
			return -EINVAL;
		}
		break;
	case 64:
		break;
	default:
		dev_err(component->dev, "unsupported frame size: %d\n", min_frame_size);
		return -EINVAL;
	}

	if (master_mode)
		val = ((i + 1) << shift);
	else
		val = 0;

	regmap_update_bits(pcm3168a->regmap, reg, mask, val);

	if (tx) {
		mask = PCM3168A_DAC_FMT_MASK;
		shift = PCM3168A_DAC_FMT_SHIFT;
	} else {
		mask = PCM3168A_ADC_FMTAD_MASK;
		shift = PCM3168A_ADC_FMTAD_SHIFT;
	}

	regmap_update_bits(pcm3168a->regmap, reg, mask, fmt << shift);

	return 0;
}

__attribute__((used)) static bool pcm3168a_readable_register(struct device *dev, unsigned int reg)
{
	if (reg >= PCM3168A_RST_SMODE)
		return true;
	else
		return false;
}

__attribute__((used)) static bool pcm3168a_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case PCM3168A_DAC_ZERO:
	case PCM3168A_ADC_OV:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool pcm3168a_writeable_register(struct device *dev, unsigned int reg)
{
	if (reg < PCM3168A_RST_SMODE)
		return false;

	switch (reg) {
	case PCM3168A_DAC_ZERO:
	case PCM3168A_ADC_OV:
		return false;
	default:
		return true;
	}
}

int pcm3168a_probe(struct device *dev, struct regmap *regmap)
{
	struct pcm3168a_priv *pcm3168a;
	int ret, i;

	pcm3168a = devm_kzalloc(dev, sizeof(*pcm3168a), GFP_KERNEL);
	if (pcm3168a == NULL)
		return -ENOMEM;

	dev_set_drvdata(dev, pcm3168a);

	pcm3168a->scki = devm_clk_get(dev, "scki");
	if (IS_ERR(pcm3168a->scki)) {
		ret = PTR_ERR(pcm3168a->scki);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "failed to acquire clock 'scki': %d\n", ret);
		return ret;
	}

	ret = clk_prepare_enable(pcm3168a->scki);
	if (ret) {
		dev_err(dev, "Failed to enable mclk: %d\n", ret);
		return ret;
	}

	pcm3168a->sysclk = clk_get_rate(pcm3168a->scki);

	for (i = 0; i < ARRAY_SIZE(pcm3168a->supplies); i++)
		pcm3168a->supplies[i].supply = pcm3168a_supply_names[i];

	ret = devm_regulator_bulk_get(dev,
			ARRAY_SIZE(pcm3168a->supplies), pcm3168a->supplies);
	if (ret) {
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "failed to request supplies: %d\n", ret);
		goto err_clk;
	}

	ret = regulator_bulk_enable(ARRAY_SIZE(pcm3168a->supplies),
				    pcm3168a->supplies);
	if (ret) {
		dev_err(dev, "failed to enable supplies: %d\n", ret);
		goto err_clk;
	}

	pcm3168a->regmap = regmap;
	if (IS_ERR(pcm3168a->regmap)) {
		ret = PTR_ERR(pcm3168a->regmap);
		dev_err(dev, "failed to allocate regmap: %d\n", ret);
		goto err_regulator;
	}

	ret = pcm3168a_reset(pcm3168a);
	if (ret) {
		dev_err(dev, "Failed to reset device: %d\n", ret);
		goto err_regulator;
	}

	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	pm_runtime_idle(dev);

	ret = devm_snd_soc_register_component(dev, &pcm3168a_driver, pcm3168a_dais,
			ARRAY_SIZE(pcm3168a_dais));
	if (ret) {
		dev_err(dev, "failed to register component: %d\n", ret);
		goto err_regulator;
	}

	return 0;

err_regulator:
	regulator_bulk_disable(ARRAY_SIZE(pcm3168a->supplies),
			pcm3168a->supplies);
err_clk:
	clk_disable_unprepare(pcm3168a->scki);

	return ret;
}

__attribute__((used)) static void pcm3168a_disable(struct device *dev)
{
	struct pcm3168a_priv *pcm3168a = dev_get_drvdata(dev);

	regulator_bulk_disable(ARRAY_SIZE(pcm3168a->supplies),
			       pcm3168a->supplies);
	clk_disable_unprepare(pcm3168a->scki);
}

void pcm3168a_remove(struct device *dev)
{
	pm_runtime_disable(dev);
#ifndef CONFIG_PM
	pcm3168a_disable(dev);
#endif
}


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
struct spi_device {int /*<<< orphan*/  dev; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct aic26 {int mclk; int master; int datfm; struct spi_device* spi; int /*<<< orphan*/  regmap; struct snd_soc_component* component; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int AIC26_DATFM_DSP ; 
 int AIC26_DATFM_I2S ; 
 int AIC26_DATFM_LEFTJ ; 
 int AIC26_DATFM_RIGHTJ ; 
 int AIC26_DIV_1 ; 
 int AIC26_DIV_1_5 ; 
 int AIC26_DIV_2 ; 
 int AIC26_DIV_3 ; 
 int AIC26_DIV_4 ; 
 int AIC26_DIV_6 ; 
 int /*<<< orphan*/  AIC26_REG_AUDIO_CTRL1 ; 
 int /*<<< orphan*/  AIC26_REG_AUDIO_CTRL2 ; 
 int /*<<< orphan*/  AIC26_REG_AUDIO_CTRL3 ; 
 int /*<<< orphan*/  AIC26_REG_DAC_GAIN ; 
 int /*<<< orphan*/  AIC26_REG_PLL_PROG1 ; 
 int /*<<< orphan*/  AIC26_REG_PLL_PROG2 ; 
 int /*<<< orphan*/  AIC26_REG_POWER_CTRL ; 
 int /*<<< orphan*/  AIC26_REG_RESET ; 
 int AIC26_WLEN_16 ; 
 int AIC26_WLEN_24 ; 
 int AIC26_WLEN_32 ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  SND_SOC_DAIFMT_CBM_CFM 133 
#define  SND_SOC_DAIFMT_CBS_CFS 132 
#define  SND_SOC_DAIFMT_DSP_A 131 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  aic26_dai ; 
 int /*<<< orphan*/  aic26_regmap ; 
 int /*<<< orphan*/  aic26_soc_component_dev ; 
 int /*<<< orphan*/  dev_attr_keyclick ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct aic26* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct aic26*) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 struct aic26* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_spi (struct spi_device*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_width (struct snd_pcm_hw_params*) ; 
 struct aic26* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 size_t sprintf (char*,char*,int,int,int) ; 

__attribute__((used)) static int aic26_hw_params(struct snd_pcm_substream *substream,
			   struct snd_pcm_hw_params *params,
			   struct snd_soc_dai *dai)
{
	struct snd_soc_component *component = dai->component;
	struct aic26 *aic26 = snd_soc_component_get_drvdata(component);
	int fsref, divisor, wlen, pval, jval, dval, qval;
	u16 reg;

	dev_dbg(&aic26->spi->dev, "aic26_hw_params(substream=%p, params=%p)\n",
		substream, params);
	dev_dbg(&aic26->spi->dev, "rate=%i width=%d\n", params_rate(params),
		params_width(params));

	switch (params_rate(params)) {
	case 8000:  fsref = 48000; divisor = AIC26_DIV_6; break;
	case 11025: fsref = 44100; divisor = AIC26_DIV_4; break;
	case 12000: fsref = 48000; divisor = AIC26_DIV_4; break;
	case 16000: fsref = 48000; divisor = AIC26_DIV_3; break;
	case 22050: fsref = 44100; divisor = AIC26_DIV_2; break;
	case 24000: fsref = 48000; divisor = AIC26_DIV_2; break;
	case 32000: fsref = 48000; divisor = AIC26_DIV_1_5; break;
	case 44100: fsref = 44100; divisor = AIC26_DIV_1; break;
	case 48000: fsref = 48000; divisor = AIC26_DIV_1; break;
	default:
		dev_dbg(&aic26->spi->dev, "bad rate\n"); return -EINVAL;
	}

	/* select data word length */
	switch (params_width(params)) {
	case 8:  wlen = AIC26_WLEN_16; break;
	case 16: wlen = AIC26_WLEN_16; break;
	case 24: wlen = AIC26_WLEN_24; break;
	case 32: wlen = AIC26_WLEN_32; break;
	default:
		dev_dbg(&aic26->spi->dev, "bad format\n"); return -EINVAL;
	}

	/**
	 * Configure PLL
	 * fsref = (mclk * PLLM) / 2048
	 * where PLLM = J.DDDD (DDDD register ranges from 0 to 9999, decimal)
	 */
	pval = 1;
	/* compute J portion of multiplier */
	jval = fsref / (aic26->mclk / 2048);
	/* compute fractional DDDD component of multiplier */
	dval = fsref - (jval * (aic26->mclk / 2048));
	dval = (10000 * dval) / (aic26->mclk / 2048);
	dev_dbg(&aic26->spi->dev, "Setting PLLM to %d.%04d\n", jval, dval);
	qval = 0;
	reg = 0x8000 | qval << 11 | pval << 8 | jval << 2;
	snd_soc_component_write(component, AIC26_REG_PLL_PROG1, reg);
	reg = dval << 2;
	snd_soc_component_write(component, AIC26_REG_PLL_PROG2, reg);

	/* Audio Control 3 (master mode, fsref rate) */
	if (aic26->master)
		reg = 0x0800;
	if (fsref == 48000)
		reg = 0x2000;
	snd_soc_component_update_bits(component, AIC26_REG_AUDIO_CTRL3, 0xf800, reg);

	/* Audio Control 1 (FSref divisor) */
	reg = wlen | aic26->datfm | (divisor << 3) | divisor;
	snd_soc_component_update_bits(component, AIC26_REG_AUDIO_CTRL1, 0xfff, reg);

	return 0;
}

__attribute__((used)) static int aic26_mute(struct snd_soc_dai *dai, int mute)
{
	struct snd_soc_component *component = dai->component;
	struct aic26 *aic26 = snd_soc_component_get_drvdata(component);
	u16 reg;

	dev_dbg(&aic26->spi->dev, "aic26_mute(dai=%p, mute=%i)\n",
		dai, mute);

	if (mute)
		reg = 0x8080;
	else
		reg = 0;
	snd_soc_component_update_bits(component, AIC26_REG_DAC_GAIN, 0x8000, reg);

	return 0;
}

__attribute__((used)) static int aic26_set_sysclk(struct snd_soc_dai *codec_dai,
			    int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct aic26 *aic26 = snd_soc_component_get_drvdata(component);

	dev_dbg(&aic26->spi->dev, "aic26_set_sysclk(dai=%p, clk_id==%i,"
		" freq=%i, dir=%i)\n",
		codec_dai, clk_id, freq, dir);

	/* MCLK needs to fall between 2MHz and 50 MHz */
	if ((freq < 2000000) || (freq > 50000000))
		return -EINVAL;

	aic26->mclk = freq;
	return 0;
}

__attribute__((used)) static int aic26_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct aic26 *aic26 = snd_soc_component_get_drvdata(component);

	dev_dbg(&aic26->spi->dev, "aic26_set_fmt(dai=%p, fmt==%i)\n",
		codec_dai, fmt);

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM: aic26->master = 1; break;
	case SND_SOC_DAIFMT_CBS_CFS: aic26->master = 0; break;
	default:
		dev_dbg(&aic26->spi->dev, "bad master\n"); return -EINVAL;
	}

	/* interface format */
	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:     aic26->datfm = AIC26_DATFM_I2S; break;
	case SND_SOC_DAIFMT_DSP_A:   aic26->datfm = AIC26_DATFM_DSP; break;
	case SND_SOC_DAIFMT_RIGHT_J: aic26->datfm = AIC26_DATFM_RIGHTJ; break;
	case SND_SOC_DAIFMT_LEFT_J:  aic26->datfm = AIC26_DATFM_LEFTJ; break;
	default:
		dev_dbg(&aic26->spi->dev, "bad format\n"); return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static ssize_t aic26_keyclick_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct aic26 *aic26 = dev_get_drvdata(dev);
	int val, amp, freq, len;

	val = snd_soc_component_read32(aic26->component, AIC26_REG_AUDIO_CTRL2);
	amp = (val >> 12) & 0x7;
	freq = (125 << ((val >> 8) & 0x7)) >> 1;
	len = 2 * (1 + ((val >> 4) & 0xf));

	return sprintf(buf, "amp=%x freq=%iHz len=%iclks\n", amp, freq, len);
}

__attribute__((used)) static ssize_t aic26_keyclick_set(struct device *dev,
				  struct device_attribute *attr,
				  const char *buf, size_t count)
{
	struct aic26 *aic26 = dev_get_drvdata(dev);

	snd_soc_component_update_bits(aic26->component, AIC26_REG_AUDIO_CTRL2,
			    0x8000, 0x800);

	return count;
}

__attribute__((used)) static int aic26_probe(struct snd_soc_component *component)
{
	struct aic26 *aic26 = dev_get_drvdata(component->dev);
	int ret, reg;

	aic26->component = component;

	/* Reset the codec to power on defaults */
	snd_soc_component_write(component, AIC26_REG_RESET, 0xBB00);

	/* Power up CODEC */
	snd_soc_component_write(component, AIC26_REG_POWER_CTRL, 0);

	/* Audio Control 3 (master mode, fsref rate) */
	reg = snd_soc_component_read32(component, AIC26_REG_AUDIO_CTRL3);
	reg &= ~0xf800;
	reg |= 0x0800; /* set master mode */
	snd_soc_component_write(component, AIC26_REG_AUDIO_CTRL3, reg);

	/* Register the sysfs files for debugging */
	/* Create SysFS files */
	ret = device_create_file(component->dev, &dev_attr_keyclick);
	if (ret)
		dev_info(component->dev, "error creating sysfs files\n");

	return 0;
}

__attribute__((used)) static int aic26_spi_probe(struct spi_device *spi)
{
	struct aic26 *aic26;
	int ret;

	dev_dbg(&spi->dev, "probing tlv320aic26 spi device\n");

	/* Allocate driver data */
	aic26 = devm_kzalloc(&spi->dev, sizeof *aic26, GFP_KERNEL);
	if (!aic26)
		return -ENOMEM;

	aic26->regmap = devm_regmap_init_spi(spi, &aic26_regmap);
	if (IS_ERR(aic26->regmap))
		return PTR_ERR(aic26->regmap);

	/* Initialize the driver data */
	aic26->spi = spi;
	dev_set_drvdata(&spi->dev, aic26);
	aic26->master = 1;

	ret = devm_snd_soc_register_component(&spi->dev,
			&aic26_soc_component_dev, &aic26_dai, 1);
	return ret;
}


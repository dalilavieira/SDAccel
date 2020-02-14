#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct es7241_data {unsigned int mclk; int is_slave; unsigned int fmt; void* m1; void* m0; void* reset; TYPE_1__* chip; } ;
struct es7241_clock_mode {int slv_mfs_num; unsigned int* slv_mfs; unsigned int mst_mfs; int mst_m0; int mst_m1; unsigned int rate_min; unsigned int rate_max; } ;
struct TYPE_2__ {int mode_num; struct es7241_clock_mode* modes; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int SND_SOC_CLOCK_IN ; 
#define  SND_SOC_DAIFMT_CBM_CFM 129 
#define  SND_SOC_DAIFMT_CBS_CFS 128 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
 unsigned int SND_SOC_DAIFMT_I2S ; 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_LEFT_J ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 unsigned int SND_SOC_DAIFMT_NB_NF ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct es7241_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  es7241_component_driver ; 
 int /*<<< orphan*/  es7241_dai ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 TYPE_1__* of_device_get_match_data (struct device*) ; 
 int of_property_read_bool (int /*<<< orphan*/ ,char*) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct es7241_data*) ; 
 struct es7241_data* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 

__attribute__((used)) static void es7241_set_mode(struct es7241_data *priv,  int m0, int m1)
{
	/* put the device in reset */
	gpiod_set_value_cansleep(priv->reset, 0);

	/* set the mode */
	gpiod_set_value_cansleep(priv->m0, m0);
	gpiod_set_value_cansleep(priv->m1, m1);

	/* take the device out of reset - datasheet does not specify a delay */
	gpiod_set_value_cansleep(priv->reset, 1);
}

__attribute__((used)) static int es7241_set_slave_mode(struct es7241_data *priv,
				 const struct es7241_clock_mode *mode,
				 unsigned int mfs)
{
	int j;

	if (!mfs)
		goto out_ok;

	for (j = 0; j < mode->slv_mfs_num; j++) {
		if (mode->slv_mfs[j] == mfs)
			goto out_ok;
	}

	return -EINVAL;

out_ok:
	es7241_set_mode(priv, 1, 1);
	return 0;
}

__attribute__((used)) static int es7241_set_master_mode(struct es7241_data *priv,
				  const struct es7241_clock_mode *mode,
				  unsigned int mfs)
{
	/*
	 * We can't really set clock ratio, if the mclk/lrclk is different
	 * from what we provide, then error out
	 */
	if (mfs && mfs != mode->mst_mfs)
		return -EINVAL;

	es7241_set_mode(priv, mode->mst_m0, mode->mst_m1);

	return 0;
}

__attribute__((used)) static int es7241_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct es7241_data *priv = snd_soc_dai_get_drvdata(dai);
	unsigned int rate = params_rate(params);
	unsigned int mfs = priv->mclk / rate;
	int i;

	for (i = 0; i < priv->chip->mode_num; i++) {
		const struct es7241_clock_mode *mode = &priv->chip->modes[i];

		if (rate < mode->rate_min || rate >= mode->rate_max)
			continue;

		if (priv->is_slave)
			return es7241_set_slave_mode(priv, mode, mfs);
		else
			return es7241_set_master_mode(priv, mode, mfs);
	}

	/* should not happen */
	dev_err(dai->dev, "unsupported rate: %u\n", rate);
	return -EINVAL;
}

__attribute__((used)) static int es7241_set_sysclk(struct snd_soc_dai *dai, int clk_id,
			     unsigned int freq, int dir)
{
	struct es7241_data *priv = snd_soc_dai_get_drvdata(dai);

	if (dir == SND_SOC_CLOCK_IN && clk_id == 0) {
		priv->mclk = freq;
		return 0;
	}

	return -ENOTSUPP;
}

__attribute__((used)) static int es7241_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct es7241_data *priv = snd_soc_dai_get_drvdata(dai);

	if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF) {
		dev_err(dai->dev, "Unsupported dai clock inversion\n");
		return -EINVAL;
	}

	if ((fmt & SND_SOC_DAIFMT_FORMAT_MASK) != priv->fmt) {
		dev_err(dai->dev, "Invalid dai format\n");
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		priv->is_slave = true;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		priv->is_slave = false;
		break;

	default:
		dev_err(dai->dev, "Unsupported clock configuration\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static void es7241_parse_fmt(struct device *dev, struct es7241_data *priv)
{
	bool is_leftj;

	/*
	 * The format is given by a pull resistor on the SDOUT pin:
	 * pull-up for i2s, pull-down for left justified.
	 */
	is_leftj = of_property_read_bool(dev->of_node,
					 "everest,sdout-pull-down");
	if (is_leftj)
		priv->fmt = SND_SOC_DAIFMT_LEFT_J;
	else
		priv->fmt = SND_SOC_DAIFMT_I2S;
}

__attribute__((used)) static int es7241_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct es7241_data *priv;
	int err;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	platform_set_drvdata(pdev, priv);

	priv->chip = of_device_get_match_data(dev);
	if (!priv->chip) {
		dev_err(dev, "failed to match device\n");
		return -ENODEV;
	}

	es7241_parse_fmt(dev, priv);

	priv->reset = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(priv->reset)) {
		err = PTR_ERR(priv->reset);
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get 'reset' gpio: %d", err);
		return err;
	}

	priv->m0 = devm_gpiod_get_optional(dev, "m0", GPIOD_OUT_LOW);
	if (IS_ERR(priv->m0)) {
		err = PTR_ERR(priv->m0);
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get 'm0' gpio: %d", err);
		return err;
	}

	priv->m1 = devm_gpiod_get_optional(dev, "m1", GPIOD_OUT_LOW);
	if (IS_ERR(priv->m1)) {
		err = PTR_ERR(priv->m1);
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get 'm1' gpio: %d", err);
		return err;
	}

	return devm_snd_soc_register_component(&pdev->dev,
				      &es7241_component_driver,
				      &es7241_dai, 1);
}


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
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {struct device* dev; } ;
struct snd_soc_component {struct device* dev; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct es7134_data {unsigned int mclk; struct es7134_chip* chip; } ;
struct es7134_clock_mode {unsigned int rate_min; unsigned int rate_max; int mclk_fs_num; unsigned int* mclk_fs; } ;
struct es7134_chip {int mode_num; int /*<<< orphan*/  dai_drv; scalar_t__ extra_route_num; int /*<<< orphan*/  extra_routes; scalar_t__ extra_widget_num; int /*<<< orphan*/  extra_widgets; struct es7134_clock_mode* modes; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int SND_SOC_CLOCK_IN ; 
 unsigned int SND_SOC_DAIFMT_CBS_CFS ; 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
 unsigned int SND_SOC_DAIFMT_I2S ; 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 unsigned int SND_SOC_DAIFMT_NB_NF ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct es7134_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  es7134_component_driver ; 
 struct es7134_chip* of_device_get_match_data (struct device*) ; 
 unsigned int params_rate (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct es7134_data*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 struct es7134_data* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct es7134_data* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int snd_soc_dapm_add_routes (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,scalar_t__) ; 
 int snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int es7134_check_mclk(struct snd_soc_dai *dai,
			     struct es7134_data *priv,
			     unsigned int rate)
{
	unsigned int mfs = priv->mclk / rate;
	int i, j;

	for (i = 0; i < priv->chip->mode_num; i++) {
		const struct es7134_clock_mode *mode = &priv->chip->modes[i];

		if (rate < mode->rate_min || rate > mode->rate_max)
			continue;

		for (j = 0; j < mode->mclk_fs_num; j++) {
			if (mode->mclk_fs[j] == mfs)
				return 0;
		}

		dev_err(dai->dev, "unsupported mclk_fs %u for rate %u\n",
			mfs, rate);
		return -EINVAL;
	}

	/* should not happen */
	dev_err(dai->dev, "unsupported rate: %u\n", rate);
	return -EINVAL;
}

__attribute__((used)) static int es7134_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	struct es7134_data *priv = snd_soc_dai_get_drvdata(dai);

	/* mclk has not been provided, assume it is OK */
	if (!priv->mclk)
		return 0;

	return es7134_check_mclk(dai, priv, params_rate(params));
}

__attribute__((used)) static int es7134_set_sysclk(struct snd_soc_dai *dai, int clk_id,
			     unsigned int freq, int dir)
{
	struct es7134_data *priv = snd_soc_dai_get_drvdata(dai);

	if (dir == SND_SOC_CLOCK_IN && clk_id == 0) {
		priv->mclk = freq;
		return 0;
	}

	return -ENOTSUPP;
}

__attribute__((used)) static int es7134_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	fmt &= (SND_SOC_DAIFMT_FORMAT_MASK | SND_SOC_DAIFMT_INV_MASK |
		SND_SOC_DAIFMT_MASTER_MASK);

	if (fmt != (SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
		    SND_SOC_DAIFMT_CBS_CFS)) {
		dev_err(codec_dai->dev, "Invalid DAI format\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int es7134_component_probe(struct snd_soc_component *c)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(c);
	struct es7134_data *priv = snd_soc_component_get_drvdata(c);
	const struct es7134_chip *chip = priv->chip;
	int ret;

	if (chip->extra_widget_num) {
		ret = snd_soc_dapm_new_controls(dapm, chip->extra_widgets,
						chip->extra_widget_num);
		if (ret) {
			dev_err(c->dev, "failed to add extra widgets\n");
			return ret;
		}
	}

	if (chip->extra_route_num) {
		ret = snd_soc_dapm_add_routes(dapm, chip->extra_routes,
					      chip->extra_route_num);
		if (ret) {
			dev_err(c->dev, "failed to add extra routes\n");
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int es7134_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct es7134_data *priv;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	platform_set_drvdata(pdev, priv);

	priv->chip = of_device_get_match_data(dev);
	if (!priv->chip) {
		dev_err(dev, "failed to match device\n");
		return -ENODEV;
	}

	return devm_snd_soc_register_component(&pdev->dev,
				      &es7134_component_driver,
				      priv->chip->dai_drv, 1);
}


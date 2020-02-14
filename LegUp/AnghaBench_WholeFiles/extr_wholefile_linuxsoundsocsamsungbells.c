#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; struct snd_soc_dai* cpu_dai; } ;
struct snd_soc_dapm_context {scalar_t__ dev; int bias_level; } ;
struct snd_soc_dai {scalar_t__ dev; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct snd_soc_card {size_t num_rtd; TYPE_1__* dai_link; struct bells_drvdata* drvdata; } ;
struct platform_device {size_t id; int /*<<< orphan*/  dev; } ;
struct notifier_block {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct bells_drvdata {int /*<<< orphan*/  asyncclk_rate; int /*<<< orphan*/  sysclk_rate; } ;
struct arizona_priv {struct arizona* arizona; } ;
struct arizona {int /*<<< orphan*/  notifier; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;
struct TYPE_5__ {int /*<<< orphan*/  name; int /*<<< orphan*/ * dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARIZONA_CLK_ASYNCCLK ; 
 int /*<<< orphan*/  ARIZONA_CLK_OPCLK ; 
 int /*<<< orphan*/  ARIZONA_CLK_SRC_FLL1 ; 
 int /*<<< orphan*/  ARIZONA_CLK_SRC_FLL2 ; 
 int /*<<< orphan*/  ARIZONA_CLK_SYSCLK ; 
 int /*<<< orphan*/  ARIZONA_FLL_SRC_AIF2BCLK ; 
 int /*<<< orphan*/  ARIZONA_FLL_SRC_MCLK1 ; 
 int /*<<< orphan*/  BCLK2_RATE ; 
 size_t DAI_AP_DSP ; 
 size_t DAI_CODEC_CP ; 
 size_t DAI_CODEC_SUB ; 
 size_t DAI_DSP_CODEC ; 
 int /*<<< orphan*/  MCLK_RATE ; 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_OUT ; 
 int /*<<< orphan*/  SYS_MCLK_RATE ; 
 int /*<<< orphan*/  WM5102_FLL1 ; 
 int /*<<< orphan*/  WM5102_FLL2 ; 
 int /*<<< orphan*/  WM9081_SYSCLK_MCLK ; 
 TYPE_2__* bells_cards ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_err (scalar_t__,char*,int,...) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 struct arizona_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int snd_soc_component_set_pll (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_component_set_sysclk (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_dai_set_sysclk (struct snd_soc_dai*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_pcm_runtime* snd_soc_get_pcm_runtime (struct snd_soc_card*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int arizona_register_notifier(struct snd_soc_component *component,
					    struct notifier_block *nb,
					    int (*notify)
					    (struct notifier_block *nb,
					    unsigned long action, void *data))
{
	struct arizona_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->arizona;

	nb->notifier_call = notify;

	return blocking_notifier_chain_register(&arizona->notifier, nb);
}

__attribute__((used)) static inline int arizona_unregister_notifier(struct snd_soc_component *component,
					      struct notifier_block *nb)
{
	struct arizona_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->arizona;

	return blocking_notifier_chain_unregister(&arizona->notifier, nb);
}

__attribute__((used)) static int bells_set_bias_level(struct snd_soc_card *card,
				struct snd_soc_dapm_context *dapm,
				enum snd_soc_bias_level level)
{
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_dai *codec_dai;
	struct snd_soc_component *component;
	struct bells_drvdata *bells = card->drvdata;
	int ret;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_DSP_CODEC].name);
	codec_dai = rtd->codec_dai;
	component = codec_dai->component;

	if (dapm->dev != codec_dai->dev)
		return 0;

	switch (level) {
	case SND_SOC_BIAS_PREPARE:
		if (dapm->bias_level != SND_SOC_BIAS_STANDBY)
			break;

		ret = snd_soc_component_set_pll(component, WM5102_FLL1,
					    ARIZONA_FLL_SRC_MCLK1,
					    MCLK_RATE,
					    bells->sysclk_rate);
		if (ret < 0)
			pr_err("Failed to start FLL: %d\n", ret);

		if (bells->asyncclk_rate) {
			ret = snd_soc_component_set_pll(component, WM5102_FLL2,
						    ARIZONA_FLL_SRC_AIF2BCLK,
						    BCLK2_RATE,
						    bells->asyncclk_rate);
			if (ret < 0)
				pr_err("Failed to start FLL: %d\n", ret);
		}
		break;

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int bells_set_bias_level_post(struct snd_soc_card *card,
				     struct snd_soc_dapm_context *dapm,
				     enum snd_soc_bias_level level)
{
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_dai *codec_dai;
	struct snd_soc_component *component;
	struct bells_drvdata *bells = card->drvdata;
	int ret;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_DSP_CODEC].name);
	codec_dai = rtd->codec_dai;
	component = codec_dai->component;

	if (dapm->dev != codec_dai->dev)
		return 0;

	switch (level) {
	case SND_SOC_BIAS_STANDBY:
		ret = snd_soc_component_set_pll(component, WM5102_FLL1, 0, 0, 0);
		if (ret < 0) {
			pr_err("Failed to stop FLL: %d\n", ret);
			return ret;
		}

		if (bells->asyncclk_rate) {
			ret = snd_soc_component_set_pll(component, WM5102_FLL2,
						    0, 0, 0);
			if (ret < 0) {
				pr_err("Failed to stop FLL: %d\n", ret);
				return ret;
			}
		}
		break;

	default:
		break;
	}

	dapm->bias_level = level;

	return 0;
}

__attribute__((used)) static int bells_late_probe(struct snd_soc_card *card)
{
	struct bells_drvdata *bells = card->drvdata;
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_component *wm0010;
	struct snd_soc_component *component;
	struct snd_soc_dai *aif1_dai;
	struct snd_soc_dai *aif2_dai;
	struct snd_soc_dai *aif3_dai;
	struct snd_soc_dai *wm9081_dai;
	int ret;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_AP_DSP].name);
	wm0010 = rtd->codec_dai->component;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_DSP_CODEC].name);
	component = rtd->codec_dai->component;
	aif1_dai = rtd->codec_dai;

	ret = snd_soc_component_set_sysclk(component, ARIZONA_CLK_SYSCLK,
				       ARIZONA_CLK_SRC_FLL1,
				       bells->sysclk_rate,
				       SND_SOC_CLOCK_IN);
	if (ret != 0) {
		dev_err(component->dev, "Failed to set SYSCLK: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_sysclk(wm0010, 0, 0, SYS_MCLK_RATE, 0);
	if (ret != 0) {
		dev_err(wm0010->dev, "Failed to set WM0010 clock: %d\n", ret);
		return ret;
	}

	ret = snd_soc_dai_set_sysclk(aif1_dai, ARIZONA_CLK_SYSCLK, 0, 0);
	if (ret != 0)
		dev_err(aif1_dai->dev, "Failed to set AIF1 clock: %d\n", ret);

	ret = snd_soc_component_set_sysclk(component, ARIZONA_CLK_OPCLK, 0,
				       SYS_MCLK_RATE, SND_SOC_CLOCK_OUT);
	if (ret != 0)
		dev_err(component->dev, "Failed to set OPCLK: %d\n", ret);

	if (card->num_rtd == DAI_CODEC_CP)
		return 0;

	ret = snd_soc_component_set_sysclk(component, ARIZONA_CLK_ASYNCCLK,
				       ARIZONA_CLK_SRC_FLL2,
				       bells->asyncclk_rate,
				       SND_SOC_CLOCK_IN);
	if (ret != 0) {
		dev_err(component->dev, "Failed to set ASYNCCLK: %d\n", ret);
		return ret;
	}

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_CODEC_CP].name);
	aif2_dai = rtd->cpu_dai;

	ret = snd_soc_dai_set_sysclk(aif2_dai, ARIZONA_CLK_ASYNCCLK, 0, 0);
	if (ret != 0) {
		dev_err(aif2_dai->dev, "Failed to set AIF2 clock: %d\n", ret);
		return ret;
	}

	if (card->num_rtd == DAI_CODEC_SUB)
		return 0;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_CODEC_SUB].name);
	aif3_dai = rtd->cpu_dai;
	wm9081_dai = rtd->codec_dai;

	ret = snd_soc_dai_set_sysclk(aif3_dai, ARIZONA_CLK_SYSCLK, 0, 0);
	if (ret != 0) {
		dev_err(aif1_dai->dev, "Failed to set AIF1 clock: %d\n", ret);
		return ret;
	}

	ret = snd_soc_component_set_sysclk(wm9081_dai->component, WM9081_SYSCLK_MCLK,
				       0, SYS_MCLK_RATE, 0);
	if (ret != 0) {
		dev_err(wm9081_dai->dev, "Failed to set MCLK: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bells_probe(struct platform_device *pdev)
{
	int ret;

	bells_cards[pdev->id].dev = &pdev->dev;

	ret = devm_snd_soc_register_card(&pdev->dev, &bells_cards[pdev->id]);
	if (ret)
		dev_err(&pdev->dev,
			"snd_soc_register_card(%s) failed: %d\n",
			bells_cards[pdev->id].name, ret);

	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int num_inputs; struct arizona* arizona; } ;
struct wm8997_priv {TYPE_8__ core; struct reg_default* fll; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {TYPE_1__* dev; } ;
struct snd_kcontrol {int dummy; } ;
struct regmap {int dummy; } ;
struct reg_default {int vco_mult; int /*<<< orphan*/  def; int /*<<< orphan*/  reg; } ;
struct TYPE_11__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct notifier_block {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct arizona_priv {struct arizona* arizona; } ;
struct arizona {int rev; struct regmap* regmap; int /*<<< orphan*/  dev; struct snd_soc_dapm_context* dapm; int /*<<< orphan*/  notifier; } ;
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 scalar_t__ ARIZONA_FLL1_CONTROL_1 ; 
 scalar_t__ ARIZONA_FLL2_CONTROL_1 ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_LOCK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_LOCK ; 
 struct reg_default ARIZONA_SAMPLE_RATE_2 ; 
 int ARIZONA_SAMPLE_RATE_2_MASK ; 
 struct reg_default ARIZONA_SAMPLE_RATE_3 ; 
 int ARIZONA_SAMPLE_RATE_3_MASK ; 
 int ARRAY_SIZE (struct reg_default*) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
#define  SND_SOC_DAPM_POST_PMD 135 
#define  SND_SOC_DAPM_POST_PMU 134 
#define  SND_SOC_DAPM_PRE_PMD 133 
#define  SND_SOC_DAPM_PRE_PMU 132 
 int WM8997_DIG_VU ; 
#define  WM8997_FLL1 131 
#define  WM8997_FLL1_REFCLK 130 
#define  WM8997_FLL2 129 
#define  WM8997_FLL2_REFCLK 128 
 int arizona_clk_ev (struct snd_soc_dapm_widget*,struct snd_kcontrol*,int) ; 
 int arizona_dvfs_sysclk_ev (struct snd_soc_dapm_widget*,struct snd_kcontrol*,int) ; 
 int /*<<< orphan*/  arizona_free_spk_irqs (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_common (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_dai (TYPE_8__*,int) ; 
 int /*<<< orphan*/  arizona_init_dvfs (TYPE_8__*) ; 
 int /*<<< orphan*/  arizona_init_fll (struct arizona*,int,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct reg_default*) ; 
 int arizona_init_spk (struct snd_soc_component*) ; 
 int arizona_init_spk_irqs (struct arizona*) ; 
 int arizona_init_vol_limit (struct arizona*) ; 
 int arizona_of_get_audio_pdata (struct arizona*) ; 
 int arizona_set_fll (struct reg_default*,int,unsigned int,unsigned int) ; 
 int arizona_set_fll_refclk (struct reg_default*,int,unsigned int,unsigned int) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct arizona* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_platdata (int /*<<< orphan*/ ) ; 
 struct wm8997_priv* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (TYPE_2__*,int /*<<< orphan*/ *,struct reg_default*,int) ; 
 struct wm8997_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm8997_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_idle (TYPE_2__*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,struct reg_default,int,int) ; 
 int /*<<< orphan*/  regmap_write_async (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_disable_pin (struct snd_soc_component*,char*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 void* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,struct regmap*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm8997 ; 
 struct reg_default* wm8997_dai ; 
 struct reg_default* wm8997_digital_vu ; 
 struct reg_default* wm8997_sysclk_reva_patch ; 

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

__attribute__((used)) static int wm8997_sysclk_ev(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);
	struct regmap *regmap = arizona->regmap;
	const struct reg_default *patch = NULL;
	int i, patch_size;

	switch (arizona->rev) {
	case 0:
		patch = wm8997_sysclk_reva_patch;
		patch_size = ARRAY_SIZE(wm8997_sysclk_reva_patch);
		break;
	default:
		break;
	}

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		if (patch)
			for (i = 0; i < patch_size; i++)
				regmap_write_async(regmap, patch[i].reg,
						   patch[i].def);
		break;
	case SND_SOC_DAPM_PRE_PMD:
		break;
	case SND_SOC_DAPM_PRE_PMU:
	case SND_SOC_DAPM_POST_PMD:
		return arizona_clk_ev(w, kcontrol, event);
	default:
		return 0;
	}

	return arizona_dvfs_sysclk_ev(w, kcontrol, event);
}

__attribute__((used)) static int wm8997_set_fll(struct snd_soc_component *component, int fll_id,
			  int source, unsigned int Fref, unsigned int Fout)
{
	struct wm8997_priv *wm8997 = snd_soc_component_get_drvdata(component);

	switch (fll_id) {
	case WM8997_FLL1:
		return arizona_set_fll(&wm8997->fll[0], source, Fref, Fout);
	case WM8997_FLL2:
		return arizona_set_fll(&wm8997->fll[1], source, Fref, Fout);
	case WM8997_FLL1_REFCLK:
		return arizona_set_fll_refclk(&wm8997->fll[0], source, Fref,
					      Fout);
	case WM8997_FLL2_REFCLK:
		return arizona_set_fll_refclk(&wm8997->fll[1], source, Fref,
					      Fout);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int wm8997_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct wm8997_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->core.arizona;
	int ret;

	snd_soc_component_init_regmap(component, arizona->regmap);

	ret = arizona_init_spk(component);
	if (ret < 0)
		return ret;

	snd_soc_component_disable_pin(component, "HAPTICS");

	priv->core.arizona->dapm = dapm;

	return 0;
}

__attribute__((used)) static void wm8997_component_remove(struct snd_soc_component *component)
{
	struct wm8997_priv *priv = snd_soc_component_get_drvdata(component);

	priv->core.arizona->dapm = NULL;
}

__attribute__((used)) static int wm8997_probe(struct platform_device *pdev)
{
	struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
	struct wm8997_priv *wm8997;
	int i, ret;

	wm8997 = devm_kzalloc(&pdev->dev, sizeof(struct wm8997_priv),
			      GFP_KERNEL);
	if (wm8997 == NULL)
		return -ENOMEM;
	platform_set_drvdata(pdev, wm8997);

	if (IS_ENABLED(CONFIG_OF)) {
		if (!dev_get_platdata(arizona->dev)) {
			ret = arizona_of_get_audio_pdata(arizona);
			if (ret < 0)
				return ret;
		}
	}

	wm8997->core.arizona = arizona;
	wm8997->core.num_inputs = 4;

	arizona_init_dvfs(&wm8997->core);

	for (i = 0; i < ARRAY_SIZE(wm8997->fll); i++)
		wm8997->fll[i].vco_mult = 1;

	arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
			 &wm8997->fll[0]);
	arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
			 &wm8997->fll[1]);

	/* SR2 fixed at 8kHz, SR3 fixed at 16kHz */
	regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
			   ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
	regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
			   ARIZONA_SAMPLE_RATE_3_MASK, 0x12);

	for (i = 0; i < ARRAY_SIZE(wm8997_dai); i++)
		arizona_init_dai(&wm8997->core, i);

	/* Latch volume update bits */
	for (i = 0; i < ARRAY_SIZE(wm8997_digital_vu); i++)
		regmap_update_bits(arizona->regmap, wm8997_digital_vu[i],
				   WM8997_DIG_VU, WM8997_DIG_VU);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_idle(&pdev->dev);

	arizona_init_common(arizona);

	ret = arizona_init_vol_limit(arizona);
	if (ret < 0)
		return ret;
	ret = arizona_init_spk_irqs(arizona);
	if (ret < 0)
		return ret;

	ret = devm_snd_soc_register_component(&pdev->dev,
					      &soc_component_dev_wm8997,
					      wm8997_dai,
					      ARRAY_SIZE(wm8997_dai));
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register component: %d\n", ret);
		goto err_spk_irqs;
	}

err_spk_irqs:
	arizona_free_spk_irqs(arizona);

	return ret;
}

__attribute__((used)) static int wm8997_remove(struct platform_device *pdev)
{
	struct wm8997_priv *wm8997 = platform_get_drvdata(pdev);
	struct arizona *arizona = wm8997->core.arizona;

	pm_runtime_disable(&pdev->dev);

	arizona_free_spk_irqs(arizona);

	return 0;
}


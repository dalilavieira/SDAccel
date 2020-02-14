#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_7__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_18__ ;

/* Type definitions */
struct TYPE_20__ {int num_inputs; struct arizona* arizona; } ;
struct wm8998_priv {TYPE_18__ core; TYPE_4__* fll; } ;
struct soc_enum {int reg; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {TYPE_7__* dev; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_22__ {unsigned int* item; } ;
struct TYPE_23__ {TYPE_2__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct TYPE_25__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_7__ dev; } ;
struct notifier_block {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct arizona_priv {struct arizona* arizona; } ;
struct TYPE_21__ {unsigned int* inmode; } ;
struct arizona {int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; struct snd_soc_dapm_context* dapm; TYPE_1__ pdata; int /*<<< orphan*/  notifier; } ;
struct TYPE_24__ {int vco_mult; } ;

/* Variables and functions */
#define  ARIZONA_ADC_DIGITAL_VOLUME_2L 133 
 int /*<<< orphan*/  ARIZONA_ASRC_RATE1 ; 
 unsigned int ARIZONA_ASRC_RATE1_MASK ; 
 unsigned int ARIZONA_ASRC_RATE1_SHIFT ; 
 int /*<<< orphan*/  ARIZONA_ASRC_RATE2 ; 
 unsigned int ARIZONA_ASRC_RATE2_MASK ; 
 unsigned int ARIZONA_ASRC_RATE2_SHIFT ; 
 int /*<<< orphan*/  ARIZONA_ASYNC_SAMPLE_RATE_1 ; 
 scalar_t__ ARIZONA_FLL1_CONTROL_1 ; 
 scalar_t__ ARIZONA_FLL2_CONTROL_1 ; 
 unsigned int ARIZONA_IN1L_CONTROL ; 
 int ARIZONA_IN1L_SRC_MASK ; 
 int ARIZONA_IN1L_SRC_SE_MASK ; 
 int ARIZONA_IN1L_SRC_SE_SHIFT ; 
 unsigned int ARIZONA_IN1L_SRC_SHIFT ; 
 int ARIZONA_IN1_MODE_MASK ; 
 int ARIZONA_IN1_MODE_SHIFT ; 
 unsigned int ARIZONA_IN2L_CONTROL ; 
 unsigned int ARIZONA_INMODE_DMIC ; 
 unsigned int ARIZONA_INMODE_SE ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_LOCK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_LOCK ; 
 int /*<<< orphan*/  ARIZONA_SAMPLE_RATE_1 ; 
 int ARRAY_SIZE (TYPE_4__*) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
#define  SND_SOC_DAPM_PRE_PMU 132 
 int /*<<< orphan*/  WM8998_DIG_VU ; 
#define  WM8998_FLL1 131 
#define  WM8998_FLL1_REFCLK 130 
#define  WM8998_FLL2 129 
#define  WM8998_FLL2_REFCLK 128 
 int /*<<< orphan*/  arizona_free_spk_irqs (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_common (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_dai (TYPE_18__*,int) ; 
 int /*<<< orphan*/  arizona_init_fll (struct arizona*,int,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  arizona_init_gpio (struct snd_soc_component*) ; 
 int arizona_init_spk (struct snd_soc_component*) ; 
 int arizona_init_spk_irqs (struct arizona*) ; 
 int arizona_of_get_audio_pdata (struct arizona*) ; 
 int /*<<< orphan*/  arizona_sample_rate_val_to_name (unsigned int) ; 
 int arizona_set_fll (TYPE_4__*,int,unsigned int,unsigned int) ; 
 int arizona_set_fll_refclk (TYPE_4__*,int,unsigned int,unsigned int) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_err (TYPE_7__*,char*,int) ; 
 struct arizona* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_7__*,char*,int /*<<< orphan*/ ) ; 
 struct wm8998_priv* devm_kzalloc (TYPE_7__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (TYPE_7__*,int /*<<< orphan*/ *,TYPE_4__*,int) ; 
 struct wm8998_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm8998_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_7__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_7__*) ; 
 int /*<<< orphan*/  pm_runtime_idle (TYPE_7__*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,TYPE_4__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_disable_pin (struct snd_soc_component*,char*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 void* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 unsigned int snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,unsigned int,int,unsigned int) ; 
 struct snd_soc_component* snd_soc_dapm_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_dapm_mux_update_power (struct snd_soc_dapm_context*,struct snd_kcontrol*,unsigned int,struct soc_enum*,int /*<<< orphan*/ *) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm8998 ; 
 TYPE_4__* wm8998_dai ; 
 TYPE_4__* wm8998_digital_vu ; 

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

__attribute__((used)) static int wm8998_asrc_ev(struct snd_soc_dapm_widget *w,
			  struct snd_kcontrol *kcontrol,
			  int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	unsigned int val;

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		val = snd_soc_component_read32(component, ARIZONA_ASRC_RATE1);
		val &= ARIZONA_ASRC_RATE1_MASK;
		val >>= ARIZONA_ASRC_RATE1_SHIFT;

		switch (val) {
		case 0:
		case 1:
		case 2:
			val = snd_soc_component_read32(component,
					   ARIZONA_SAMPLE_RATE_1 + val);
			if (val >= 0x11) {
				dev_warn(component->dev,
					 "Unsupported ASRC rate1 (%s)\n",
					 arizona_sample_rate_val_to_name(val));
			return -EINVAL;
			}
			break;
		default:
			dev_err(component->dev,
				"Illegal ASRC rate1 selector (0x%x)\n",
				val);
			return -EINVAL;
		}

		val = snd_soc_component_read32(component, ARIZONA_ASRC_RATE2);
		val &= ARIZONA_ASRC_RATE2_MASK;
		val >>= ARIZONA_ASRC_RATE2_SHIFT;

		switch (val) {
		case 8:
		case 9:
			val -= 0x8;
			val = snd_soc_component_read32(component,
					   ARIZONA_ASYNC_SAMPLE_RATE_1 + val);
			if (val >= 0x11) {
				dev_warn(component->dev,
					 "Unsupported ASRC rate2 (%s)\n",
					 arizona_sample_rate_val_to_name(val));
				return -EINVAL;
			}
			break;
		default:
			dev_err(component->dev,
				"Illegal ASRC rate2 selector (0x%x)\n",
				val);
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int wm8998_inmux_put(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_dapm_kcontrol_component(kcontrol);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct wm8998_priv *wm8998 = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = wm8998->core.arizona;
	struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
	unsigned int mode_reg, mode_index;
	unsigned int mux, inmode, src_val, mode_val;

	mux = ucontrol->value.enumerated.item[0];
	if (mux > 1)
		return -EINVAL;

	switch (e->reg) {
	case ARIZONA_ADC_DIGITAL_VOLUME_2L:
		mode_reg = ARIZONA_IN2L_CONTROL;
		mode_index = 1 + (2 * mux);
		break;
	default:
		mode_reg = ARIZONA_IN1L_CONTROL;
		mode_index = (2 * mux);
		break;
	}

	inmode = arizona->pdata.inmode[mode_index];
	if (inmode & ARIZONA_INMODE_DMIC)
		mode_val = 1 << ARIZONA_IN1_MODE_SHIFT;
	else
		mode_val = 0;

	src_val = mux << ARIZONA_IN1L_SRC_SHIFT;
	if (inmode & ARIZONA_INMODE_SE)
		src_val |= 1 << ARIZONA_IN1L_SRC_SE_SHIFT;

	snd_soc_component_update_bits(component, mode_reg,
				      ARIZONA_IN1_MODE_MASK, mode_val);

	snd_soc_component_update_bits(component, e->reg,
				      ARIZONA_IN1L_SRC_MASK |
				      ARIZONA_IN1L_SRC_SE_MASK,
				      src_val);

	return snd_soc_dapm_mux_update_power(dapm, kcontrol,
					     ucontrol->value.enumerated.item[0],
					     e, NULL);
}

__attribute__((used)) static int wm8998_set_fll(struct snd_soc_component *component, int fll_id,
			  int source, unsigned int Fref, unsigned int Fout)
{
	struct wm8998_priv *wm8998 = snd_soc_component_get_drvdata(component);

	switch (fll_id) {
	case WM8998_FLL1:
		return arizona_set_fll(&wm8998->fll[0], source, Fref, Fout);
	case WM8998_FLL2:
		return arizona_set_fll(&wm8998->fll[1], source, Fref, Fout);
	case WM8998_FLL1_REFCLK:
		return arizona_set_fll_refclk(&wm8998->fll[0], source, Fref,
					      Fout);
	case WM8998_FLL2_REFCLK:
		return arizona_set_fll_refclk(&wm8998->fll[1], source, Fref,
					      Fout);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int wm8998_component_probe(struct snd_soc_component *component)
{
	struct wm8998_priv *priv = snd_soc_component_get_drvdata(component);
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct arizona *arizona = priv->core.arizona;
	int ret;

	arizona->dapm = dapm;
	snd_soc_component_init_regmap(component, arizona->regmap);

	ret = arizona_init_spk(component);
	if (ret < 0)
		return ret;

	arizona_init_gpio(component);

	snd_soc_component_disable_pin(component, "HAPTICS");

	return 0;
}

__attribute__((used)) static void wm8998_component_remove(struct snd_soc_component *component)
{
	struct wm8998_priv *priv = snd_soc_component_get_drvdata(component);

	priv->core.arizona->dapm = NULL;
}

__attribute__((used)) static int wm8998_probe(struct platform_device *pdev)
{
	struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
	struct wm8998_priv *wm8998;
	int i, ret;

	wm8998 = devm_kzalloc(&pdev->dev, sizeof(struct wm8998_priv),
			      GFP_KERNEL);
	if (!wm8998)
		return -ENOMEM;
	platform_set_drvdata(pdev, wm8998);

	if (IS_ENABLED(CONFIG_OF)) {
		if (!dev_get_platdata(arizona->dev)) {
			ret = arizona_of_get_audio_pdata(arizona);
			if (ret < 0)
				return ret;
		}
	}

	wm8998->core.arizona = arizona;
	wm8998->core.num_inputs = 3;	/* IN1L, IN1R, IN2 */

	for (i = 0; i < ARRAY_SIZE(wm8998->fll); i++)
		wm8998->fll[i].vco_mult = 1;

	arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
			 &wm8998->fll[0]);
	arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
			 &wm8998->fll[1]);

	for (i = 0; i < ARRAY_SIZE(wm8998_dai); i++)
		arizona_init_dai(&wm8998->core, i);

	/* Latch volume update bits */
	for (i = 0; i < ARRAY_SIZE(wm8998_digital_vu); i++)
		regmap_update_bits(arizona->regmap, wm8998_digital_vu[i],
				   WM8998_DIG_VU, WM8998_DIG_VU);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_idle(&pdev->dev);

	arizona_init_common(arizona);

	ret = arizona_init_spk_irqs(arizona);
	if (ret < 0)
		return ret;

	ret = devm_snd_soc_register_component(&pdev->dev,
					      &soc_component_dev_wm8998,
					      wm8998_dai,
					      ARRAY_SIZE(wm8998_dai));
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register component: %d\n", ret);
		goto err_spk_irqs;
	}

	return ret;

err_spk_irqs:
	arizona_free_spk_irqs(arizona);

	return ret;
}

__attribute__((used)) static int wm8998_remove(struct platform_device *pdev)
{
	struct wm8998_priv *wm8998 = platform_get_drvdata(pdev);
	struct arizona *arizona = wm8998->core.arizona;

	pm_runtime_disable(&pdev->dev);

	arizona_free_spk_irqs(arizona);

	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_17__ ;
typedef  struct TYPE_19__   TYPE_10__ ;

/* Type definitions */
struct TYPE_20__ {int num_inputs; TYPE_4__* adsp; struct arizona* arizona; } ;
struct wm5102_priv {TYPE_17__ core; struct reg_default* fll; } ;
struct snd_soc_pcm_runtime {int dummy; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {TYPE_10__* dev; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_22__ {int /*<<< orphan*/ * value; } ;
struct TYPE_21__ {int /*<<< orphan*/  data; } ;
struct TYPE_23__ {TYPE_2__ integer; TYPE_1__ bytes; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct snd_compr_stream {struct snd_soc_pcm_runtime* private_data; } ;
struct regmap {int dummy; } ;
struct reg_default {int vco_mult; int /*<<< orphan*/  def; int /*<<< orphan*/  reg; } ;
struct TYPE_19__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_10__ dev; } ;
struct notifier_block {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct arizona_priv {struct arizona* arizona; } ;
struct arizona {int rev; struct regmap* regmap; int /*<<< orphan*/  dev; int /*<<< orphan*/  dac_comp_lock; struct snd_soc_dapm_context* dapm; int /*<<< orphan*/  dac_comp_enabled; int /*<<< orphan*/  dac_comp_coeff; int /*<<< orphan*/  notifier; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_24__ {char* part; int num; int num_mems; struct reg_default* mem; struct regmap* regmap; int /*<<< orphan*/  dev; int /*<<< orphan*/  base; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARIZONA_DSP1_CONTROL_1 ; 
 int /*<<< orphan*/  ARIZONA_DVFS_ADSP1_RQ ; 
 scalar_t__ ARIZONA_FLL1_CONTROL_1 ; 
 scalar_t__ ARIZONA_FLL2_CONTROL_1 ; 
 int /*<<< orphan*/  ARIZONA_IRQ_DSP_IRQ1 ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_LOCK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_LOCK ; 
 struct reg_default ARIZONA_SAMPLE_RATE_2 ; 
 int ARIZONA_SAMPLE_RATE_2_MASK ; 
 struct reg_default ARIZONA_SAMPLE_RATE_3 ; 
 int ARIZONA_SAMPLE_RATE_3_MASK ; 
 unsigned int ARIZONA_SYSCLK_FREQ_MASK ; 
 unsigned int ARIZONA_SYSCLK_FREQ_SHIFT ; 
 int /*<<< orphan*/  ARIZONA_SYSTEM_CLOCK_1 ; 
 int ARRAY_SIZE (struct reg_default*) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
#define  SND_SOC_DAPM_POST_PMD 135 
#define  SND_SOC_DAPM_POST_PMU 134 
#define  SND_SOC_DAPM_PRE_PMD 133 
#define  SND_SOC_DAPM_PRE_PMU 132 
 int WM5102_DIG_VU ; 
#define  WM5102_FLL1 131 
#define  WM5102_FLL1_REFCLK 130 
#define  WM5102_FLL2 129 
#define  WM5102_FLL2_REFCLK 128 
 int /*<<< orphan*/  WMFW_ADSP2 ; 
 int /*<<< orphan*/  arizona_adsp2_rate_controls ; 
 int arizona_clk_ev (struct snd_soc_dapm_widget*,struct snd_kcontrol*,int) ; 
 int arizona_dvfs_down (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int arizona_dvfs_sysclk_ev (struct snd_soc_dapm_widget*,struct snd_kcontrol*,int) ; 
 int arizona_dvfs_up (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  arizona_free_irq (struct arizona*,int /*<<< orphan*/ ,struct wm5102_priv*) ; 
 int /*<<< orphan*/  arizona_free_spk_irqs (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_common (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_dai (TYPE_17__*,int) ; 
 int /*<<< orphan*/  arizona_init_dvfs (TYPE_17__*) ; 
 int /*<<< orphan*/  arizona_init_fll (struct arizona*,int,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct reg_default*) ; 
 int /*<<< orphan*/  arizona_init_gpio (struct snd_soc_component*) ; 
 int arizona_init_spk (struct snd_soc_component*) ; 
 int arizona_init_spk_irqs (struct arizona*) ; 
 int arizona_init_vol_limit (struct arizona*) ; 
 int arizona_of_get_audio_pdata (struct arizona*) ; 
 int arizona_request_irq (struct arizona*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/  (*) (int,void*),struct wm5102_priv*) ; 
 int arizona_set_fll (struct reg_default*,int,unsigned int,unsigned int) ; 
 int arizona_set_fll_refclk (struct reg_default*,int,unsigned int,unsigned int) ; 
 int arizona_set_irq_wake (struct arizona*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  be16_to_cpu (int /*<<< orphan*/ ) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_err (TYPE_10__*,char*,...) ; 
 struct arizona* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_10__*,char*,int) ; 
 struct wm5102_priv* devm_kzalloc (TYPE_10__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (TYPE_10__*,int /*<<< orphan*/ *,struct reg_default*,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct wm5102_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm5102_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_idle (TYPE_10__*) ; 
 int /*<<< orphan*/  put_unaligned_be16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,struct reg_default,int,int) ; 
 int /*<<< orphan*/  regmap_write_async (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_soc_component_disable_pin (struct snd_soc_component*,char*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 void* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,struct regmap*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 struct snd_soc_component* snd_soc_rtdcom_lookup (struct snd_soc_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_wm5102 ; 
 struct reg_default* wm5102_dai ; 
 struct reg_default* wm5102_digital_vu ; 
 struct reg_default* wm5102_dsp1_regions ; 
 struct reg_default* wm5102_sysclk_reva_patch ; 
 struct reg_default* wm5102_sysclk_revb_patch ; 
 int wm_adsp2_component_probe (TYPE_4__*,struct snd_soc_component*) ; 
 int /*<<< orphan*/  wm_adsp2_component_remove (TYPE_4__*,struct snd_soc_component*) ; 
 int wm_adsp2_early_event (struct snd_soc_dapm_widget*,struct snd_kcontrol*,int,unsigned int) ; 
 int wm_adsp2_init (TYPE_4__*) ; 
 int /*<<< orphan*/  wm_adsp2_remove (TYPE_4__*) ; 
 int wm_adsp_compr_handle_irq (TYPE_4__*) ; 
 int wm_adsp_compr_open (TYPE_4__*,struct snd_compr_stream*) ; 

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

__attribute__((used)) static int wm5102_sysclk_ev(struct snd_soc_dapm_widget *w,
			    struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);
	struct regmap *regmap = arizona->regmap;
	const struct reg_default *patch = NULL;
	int i, patch_size;

	switch (arizona->rev) {
	case 0:
		patch = wm5102_sysclk_reva_patch;
		patch_size = ARRAY_SIZE(wm5102_sysclk_reva_patch);
		break;
	default:
		patch = wm5102_sysclk_revb_patch;
		patch_size = ARRAY_SIZE(wm5102_sysclk_revb_patch);
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

__attribute__((used)) static int wm5102_adsp_power_ev(struct snd_soc_dapm_widget *w,
				struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);
	unsigned int v = 0;
	int ret;

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		ret = regmap_read(arizona->regmap, ARIZONA_SYSTEM_CLOCK_1, &v);
		if (ret != 0) {
			dev_err(component->dev,
				"Failed to read SYSCLK state: %d\n", ret);
			return -EIO;
		}

		v = (v & ARIZONA_SYSCLK_FREQ_MASK) >> ARIZONA_SYSCLK_FREQ_SHIFT;

		if (v >= 3) {
			ret = arizona_dvfs_up(component, ARIZONA_DVFS_ADSP1_RQ);
			if (ret) {
				dev_err(component->dev,
					"Failed to raise DVFS: %d\n", ret);
				return ret;
			}
		}
		break;

	case SND_SOC_DAPM_POST_PMD:
		ret = arizona_dvfs_down(component, ARIZONA_DVFS_ADSP1_RQ);
		if (ret)
			dev_warn(component->dev,
				 "Failed to lower DVFS: %d\n", ret);
		break;

	default:
		break;
	}

	return wm_adsp2_early_event(w, kcontrol, event, v);
}

__attribute__((used)) static int wm5102_out_comp_coeff_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);

	mutex_lock(&arizona->dac_comp_lock);
	put_unaligned_be16(arizona->dac_comp_coeff,
			   ucontrol->value.bytes.data);
	mutex_unlock(&arizona->dac_comp_lock);

	return 0;
}

__attribute__((used)) static int wm5102_out_comp_coeff_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);

	mutex_lock(&arizona->dac_comp_lock);
	memcpy(&arizona->dac_comp_coeff, ucontrol->value.bytes.data,
	       sizeof(arizona->dac_comp_coeff));
	arizona->dac_comp_coeff = be16_to_cpu(arizona->dac_comp_coeff);
	mutex_unlock(&arizona->dac_comp_lock);

	return 0;
}

__attribute__((used)) static int wm5102_out_comp_switch_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);

	mutex_lock(&arizona->dac_comp_lock);
	ucontrol->value.integer.value[0] = arizona->dac_comp_enabled;
	mutex_unlock(&arizona->dac_comp_lock);

	return 0;
}

__attribute__((used)) static int wm5102_out_comp_switch_put(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);

	mutex_lock(&arizona->dac_comp_lock);
	arizona->dac_comp_enabled = ucontrol->value.integer.value[0];
	mutex_unlock(&arizona->dac_comp_lock);

	return 0;
}

__attribute__((used)) static int wm5102_set_fll(struct snd_soc_component *component, int fll_id,
			  int source, unsigned int Fref, unsigned int Fout)
{
	struct wm5102_priv *wm5102 = snd_soc_component_get_drvdata(component);

	switch (fll_id) {
	case WM5102_FLL1:
		return arizona_set_fll(&wm5102->fll[0], source, Fref, Fout);
	case WM5102_FLL2:
		return arizona_set_fll(&wm5102->fll[1], source, Fref, Fout);
	case WM5102_FLL1_REFCLK:
		return arizona_set_fll_refclk(&wm5102->fll[0], source, Fref,
					      Fout);
	case WM5102_FLL2_REFCLK:
		return arizona_set_fll_refclk(&wm5102->fll[1], source, Fref,
					      Fout);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int wm5102_open(struct snd_compr_stream *stream)
{
	struct snd_soc_pcm_runtime *rtd = stream->private_data;
	struct snd_soc_component *component = snd_soc_rtdcom_lookup(rtd, DRV_NAME);
	struct wm5102_priv *priv = snd_soc_component_get_drvdata(component);

	return wm_adsp_compr_open(&priv->core.adsp[0], stream);
}

__attribute__((used)) static irqreturn_t wm5102_adsp2_irq(int irq, void *data)
{
	struct wm5102_priv *priv = data;
	struct arizona *arizona = priv->core.arizona;
	int ret;

	ret = wm_adsp_compr_handle_irq(&priv->core.adsp[0]);
	if (ret == -ENODEV) {
		dev_err(arizona->dev, "Spurious compressed data IRQ\n");
		return IRQ_NONE;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int wm5102_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct wm5102_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->core.arizona;
	int ret;

	snd_soc_component_init_regmap(component, arizona->regmap);

	ret = wm_adsp2_component_probe(&priv->core.adsp[0], component);
	if (ret)
		return ret;

	ret = snd_soc_add_component_controls(component,
					     arizona_adsp2_rate_controls, 1);
	if (ret)
		goto err_adsp2_codec_probe;

	ret = arizona_init_spk(component);
	if (ret < 0)
		return ret;

	arizona_init_gpio(component);

	snd_soc_component_disable_pin(component, "HAPTICS");

	priv->core.arizona->dapm = dapm;

	return 0;

err_adsp2_codec_probe:
	wm_adsp2_component_remove(&priv->core.adsp[0], component);

	return ret;
}

__attribute__((used)) static void wm5102_component_remove(struct snd_soc_component *component)
{
	struct wm5102_priv *priv = snd_soc_component_get_drvdata(component);

	wm_adsp2_component_remove(&priv->core.adsp[0], component);

	priv->core.arizona->dapm = NULL;
}

__attribute__((used)) static int wm5102_probe(struct platform_device *pdev)
{
	struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
	struct wm5102_priv *wm5102;
	int i, ret;

	wm5102 = devm_kzalloc(&pdev->dev, sizeof(struct wm5102_priv),
			      GFP_KERNEL);
	if (wm5102 == NULL)
		return -ENOMEM;
	platform_set_drvdata(pdev, wm5102);

	if (IS_ENABLED(CONFIG_OF)) {
		if (!dev_get_platdata(arizona->dev)) {
			ret = arizona_of_get_audio_pdata(arizona);
			if (ret < 0)
				return ret;
		}
	}

	mutex_init(&arizona->dac_comp_lock);

	wm5102->core.arizona = arizona;
	wm5102->core.num_inputs = 6;

	arizona_init_dvfs(&wm5102->core);

	wm5102->core.adsp[0].part = "wm5102";
	wm5102->core.adsp[0].num = 1;
	wm5102->core.adsp[0].type = WMFW_ADSP2;
	wm5102->core.adsp[0].base = ARIZONA_DSP1_CONTROL_1;
	wm5102->core.adsp[0].dev = arizona->dev;
	wm5102->core.adsp[0].regmap = arizona->regmap;
	wm5102->core.adsp[0].mem = wm5102_dsp1_regions;
	wm5102->core.adsp[0].num_mems = ARRAY_SIZE(wm5102_dsp1_regions);

	ret = wm_adsp2_init(&wm5102->core.adsp[0]);
	if (ret != 0)
		return ret;

	for (i = 0; i < ARRAY_SIZE(wm5102->fll); i++)
		wm5102->fll[i].vco_mult = 1;

	arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
			 &wm5102->fll[0]);
	arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
			 &wm5102->fll[1]);

	/* SR2 fixed at 8kHz, SR3 fixed at 16kHz */
	regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
			   ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
	regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
			   ARIZONA_SAMPLE_RATE_3_MASK, 0x12);

	for (i = 0; i < ARRAY_SIZE(wm5102_dai); i++)
		arizona_init_dai(&wm5102->core, i);

	/* Latch volume update bits */
	for (i = 0; i < ARRAY_SIZE(wm5102_digital_vu); i++)
		regmap_update_bits(arizona->regmap, wm5102_digital_vu[i],
				   WM5102_DIG_VU, WM5102_DIG_VU);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_idle(&pdev->dev);

	ret = arizona_request_irq(arizona, ARIZONA_IRQ_DSP_IRQ1,
				  "ADSP2 Compressed IRQ", wm5102_adsp2_irq,
				  wm5102);
	if (ret != 0) {
		dev_err(&pdev->dev, "Failed to request DSP IRQ: %d\n", ret);
		return ret;
	}

	ret = arizona_set_irq_wake(arizona, ARIZONA_IRQ_DSP_IRQ1, 1);
	if (ret != 0)
		dev_warn(&pdev->dev,
			 "Failed to set compressed IRQ as a wake source: %d\n",
			 ret);

	arizona_init_common(arizona);

	ret = arizona_init_vol_limit(arizona);
	if (ret < 0)
		goto err_dsp_irq;
	ret = arizona_init_spk_irqs(arizona);
	if (ret < 0)
		goto err_dsp_irq;

	ret = devm_snd_soc_register_component(&pdev->dev,
					      &soc_component_dev_wm5102,
					      wm5102_dai,
					      ARRAY_SIZE(wm5102_dai));
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register component: %d\n", ret);
		goto err_spk_irqs;
	}

	return ret;

err_spk_irqs:
	arizona_free_spk_irqs(arizona);
err_dsp_irq:
	arizona_set_irq_wake(arizona, ARIZONA_IRQ_DSP_IRQ1, 0);
	arizona_free_irq(arizona, ARIZONA_IRQ_DSP_IRQ1, wm5102);

	return ret;
}

__attribute__((used)) static int wm5102_remove(struct platform_device *pdev)
{
	struct wm5102_priv *wm5102 = platform_get_drvdata(pdev);
	struct arizona *arizona = wm5102->core.arizona;

	pm_runtime_disable(&pdev->dev);

	wm_adsp2_remove(&wm5102->core.adsp[0]);

	arizona_free_spk_irqs(arizona);

	arizona_set_irq_wake(arizona, ARIZONA_IRQ_DSP_IRQ1, 0);
	arizona_free_irq(arizona, ARIZONA_IRQ_DSP_IRQ1, wm5102);

	return 0;
}


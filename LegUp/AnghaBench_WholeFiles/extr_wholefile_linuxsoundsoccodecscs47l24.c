#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_9__ ;
typedef  struct TYPE_31__   TYPE_8__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_24__ ;
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {TYPE_1__* codec_dai; } ;
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {TYPE_9__* dev; } ;
struct snd_kcontrol {int dummy; } ;
struct snd_compr_stream {struct snd_soc_pcm_runtime* private_data; } ;
struct TYPE_32__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_9__ dev; } ;
struct notifier_block {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct TYPE_29__ {int num_inputs; TYPE_2__* adsp; struct arizona* arizona; } ;
struct cs47l24_priv {TYPE_24__ core; TYPE_8__* fll; } ;
struct arizona_voice_trigger_info {int core; } ;
struct arizona_priv {struct arizona* arizona; } ;
struct arizona {int /*<<< orphan*/  regmap; TYPE_9__* dev; struct snd_soc_dapm_context* dapm; int /*<<< orphan*/  notifier; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_31__ {int vco_mult; } ;
struct TYPE_30__ {char* part; int num; int num_mems; int /*<<< orphan*/  mem; scalar_t__ base; int /*<<< orphan*/  regmap; TYPE_9__* dev; int /*<<< orphan*/  type; } ;
struct TYPE_28__ {int name; } ;

/* Variables and functions */
 scalar_t__ ARIZONA_DSP1_CONTROL_1 ; 
 scalar_t__ ARIZONA_FLL1_CONTROL_1 ; 
 scalar_t__ ARIZONA_FLL2_CONTROL_1 ; 
 int /*<<< orphan*/  ARIZONA_IRQ_DSP_IRQ1 ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL1_LOCK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_CLOCK_OK ; 
 int /*<<< orphan*/  ARIZONA_IRQ_FLL2_LOCK ; 
 int ARIZONA_MAX_DAI ; 
 int /*<<< orphan*/  ARIZONA_NOTIFY_VOICE_TRIGGER ; 
 TYPE_8__ ARIZONA_SAMPLE_RATE_2 ; 
 int ARIZONA_SAMPLE_RATE_2_MASK ; 
 TYPE_8__ ARIZONA_SAMPLE_RATE_3 ; 
 int ARIZONA_SAMPLE_RATE_3_MASK ; 
 unsigned int ARIZONA_SYSCLK_FREQ_MASK ; 
 unsigned int ARIZONA_SYSCLK_FREQ_SHIFT ; 
 int /*<<< orphan*/  ARIZONA_SYSTEM_CLOCK_1 ; 
 int ARRAY_SIZE (TYPE_8__*) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int CS47L24_DIG_VU ; 
#define  CS47L24_FLL1 131 
#define  CS47L24_FLL1_REFCLK 130 
#define  CS47L24_FLL2 129 
#define  CS47L24_FLL2_REFCLK 128 
 int /*<<< orphan*/  DRV_NAME ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WMFW_ADSP2 ; 
 int WM_ADSP_COMPR_VOICE_TRIGGER ; 
 int /*<<< orphan*/ * arizona_adsp2_rate_controls ; 
 int /*<<< orphan*/  arizona_call_notifiers (struct arizona*,int /*<<< orphan*/ ,struct arizona_voice_trigger_info*) ; 
 int /*<<< orphan*/  arizona_free_irq (struct arizona*,int /*<<< orphan*/ ,struct cs47l24_priv*) ; 
 int /*<<< orphan*/  arizona_free_spk_irqs (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_common (struct arizona*) ; 
 int /*<<< orphan*/  arizona_init_dai (TYPE_24__*,int) ; 
 int /*<<< orphan*/  arizona_init_fll (struct arizona*,int,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_8__*) ; 
 int /*<<< orphan*/  arizona_init_gpio (struct snd_soc_component*) ; 
 int /*<<< orphan*/  arizona_init_mono (struct snd_soc_component*) ; 
 int arizona_init_spk (struct snd_soc_component*) ; 
 int arizona_init_spk_irqs (struct arizona*) ; 
 int arizona_init_vol_limit (struct arizona*) ; 
 int arizona_of_get_audio_pdata (struct arizona*) ; 
 int arizona_request_irq (struct arizona*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/  (*) (int,void*),struct cs47l24_priv*) ; 
 int arizona_set_fll (TYPE_8__*,int,unsigned int,unsigned int) ; 
 int arizona_set_fll_refclk (TYPE_8__*,int,unsigned int,unsigned int) ; 
 int arizona_set_irq_wake (struct arizona*,int /*<<< orphan*/ ,int) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 TYPE_8__* cs47l24_dai ; 
 TYPE_8__* cs47l24_digital_vu ; 
 TYPE_8__* cs47l24_dsp2_regions ; 
 int /*<<< orphan*/ * cs47l24_dsp_regions ; 
 int /*<<< orphan*/  dev_err (TYPE_9__*,char*,...) ; 
 struct arizona* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_platdata (TYPE_9__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_9__*,char*,int) ; 
 struct cs47l24_priv* devm_kzalloc (TYPE_9__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (TYPE_9__*,int /*<<< orphan*/ *,TYPE_8__*,int) ; 
 struct cs47l24_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cs47l24_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_9__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_9__*) ; 
 int /*<<< orphan*/  pm_runtime_idle (TYPE_9__*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,TYPE_8__,int,int) ; 
 int snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  snd_soc_component_disable_pin (struct snd_soc_component*,char*) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 void* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_init_regmap (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_rtdcom_lookup (struct snd_soc_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_cs47l24 ; 
 scalar_t__ strcmp (int,char*) ; 
 int wm_adsp2_component_probe (TYPE_2__*,struct snd_soc_component*) ; 
 int /*<<< orphan*/  wm_adsp2_component_remove (TYPE_2__*,struct snd_soc_component*) ; 
 int wm_adsp2_early_event (struct snd_soc_dapm_widget*,struct snd_kcontrol*,int,unsigned int) ; 
 int wm_adsp2_init (TYPE_2__*) ; 
 int /*<<< orphan*/  wm_adsp2_remove (TYPE_2__*) ; 
 int wm_adsp_compr_handle_irq (TYPE_2__*) ; 
 int wm_adsp_compr_open (TYPE_2__*,struct snd_compr_stream*) ; 

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

__attribute__((used)) static int cs47l24_adsp_power_ev(struct snd_soc_dapm_widget *w,
				 struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct arizona *arizona = dev_get_drvdata(component->dev->parent);
	unsigned int v;
	int ret;

	ret = regmap_read(arizona->regmap, ARIZONA_SYSTEM_CLOCK_1, &v);
	if (ret != 0) {
		dev_err(component->dev, "Failed to read SYSCLK state: %d\n", ret);
		return ret;
	}

	v = (v & ARIZONA_SYSCLK_FREQ_MASK) >> ARIZONA_SYSCLK_FREQ_SHIFT;

	return wm_adsp2_early_event(w, kcontrol, event, v);
}

__attribute__((used)) static int cs47l24_set_fll(struct snd_soc_component *component, int fll_id,
			   int source, unsigned int Fref, unsigned int Fout)
{
	struct cs47l24_priv *cs47l24 = snd_soc_component_get_drvdata(component);

	switch (fll_id) {
	case CS47L24_FLL1:
		return arizona_set_fll(&cs47l24->fll[0], source, Fref, Fout);
	case CS47L24_FLL2:
		return arizona_set_fll(&cs47l24->fll[1], source, Fref, Fout);
	case CS47L24_FLL1_REFCLK:
		return arizona_set_fll_refclk(&cs47l24->fll[0], source, Fref,
					      Fout);
	case CS47L24_FLL2_REFCLK:
		return arizona_set_fll_refclk(&cs47l24->fll[1], source, Fref,
					      Fout);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int cs47l24_open(struct snd_compr_stream *stream)
{
	struct snd_soc_pcm_runtime *rtd = stream->private_data;
	struct snd_soc_component *component = snd_soc_rtdcom_lookup(rtd, DRV_NAME);
	struct cs47l24_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->core.arizona;
	int n_adsp;

	if (strcmp(rtd->codec_dai->name, "cs47l24-dsp-voicectrl") == 0) {
		n_adsp = 2;
	} else if (strcmp(rtd->codec_dai->name, "cs47l24-dsp-trace") == 0) {
		n_adsp = 1;
	} else {
		dev_err(arizona->dev,
			"No suitable compressed stream for DAI '%s'\n",
			rtd->codec_dai->name);
		return -EINVAL;
	}

	return wm_adsp_compr_open(&priv->core.adsp[n_adsp], stream);
}

__attribute__((used)) static irqreturn_t cs47l24_adsp2_irq(int irq, void *data)
{
	struct cs47l24_priv *priv = data;
	struct arizona *arizona = priv->core.arizona;
	struct arizona_voice_trigger_info info;
	int serviced = 0;
	int i, ret;

	for (i = 1; i <= 2; ++i) {
		ret = wm_adsp_compr_handle_irq(&priv->core.adsp[i]);
		if (ret != -ENODEV)
			serviced++;
		if (ret == WM_ADSP_COMPR_VOICE_TRIGGER) {
			info.core = i;
			arizona_call_notifiers(arizona,
					       ARIZONA_NOTIFY_VOICE_TRIGGER,
					       &info);
		}
	}

	if (!serviced) {
		dev_err(arizona->dev, "Spurious compressed data IRQ\n");
		return IRQ_NONE;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int cs47l24_component_probe(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);
	struct cs47l24_priv *priv = snd_soc_component_get_drvdata(component);
	struct arizona *arizona = priv->core.arizona;
	int ret;

	arizona->dapm = dapm;
	snd_soc_component_init_regmap(component, arizona->regmap);

	ret = arizona_init_spk(component);
	if (ret < 0)
		return ret;

	arizona_init_gpio(component);
	arizona_init_mono(component);

	ret = wm_adsp2_component_probe(&priv->core.adsp[1], component);
	if (ret)
		goto err_adsp2_codec_probe;

	ret = wm_adsp2_component_probe(&priv->core.adsp[2], component);
	if (ret)
		goto err_adsp2_codec_probe;

	ret = snd_soc_add_component_controls(component,
					     &arizona_adsp2_rate_controls[1],
					     2);
	if (ret)
		goto err_adsp2_codec_probe;

	snd_soc_component_disable_pin(component, "HAPTICS");

	return 0;

err_adsp2_codec_probe:
	wm_adsp2_component_remove(&priv->core.adsp[1], component);
	wm_adsp2_component_remove(&priv->core.adsp[2], component);

	return ret;
}

__attribute__((used)) static void cs47l24_component_remove(struct snd_soc_component *component)
{
	struct cs47l24_priv *priv = snd_soc_component_get_drvdata(component);

	wm_adsp2_component_remove(&priv->core.adsp[1], component);
	wm_adsp2_component_remove(&priv->core.adsp[2], component);

	priv->core.arizona->dapm = NULL;
}

__attribute__((used)) static int cs47l24_probe(struct platform_device *pdev)
{
	struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
	struct cs47l24_priv *cs47l24;
	int i, ret;

	BUILD_BUG_ON(ARRAY_SIZE(cs47l24_dai) > ARIZONA_MAX_DAI);

	cs47l24 = devm_kzalloc(&pdev->dev, sizeof(struct cs47l24_priv),
			       GFP_KERNEL);
	if (!cs47l24)
		return -ENOMEM;

	if (IS_ENABLED(CONFIG_OF)) {
		if (!dev_get_platdata(arizona->dev)) {
			ret = arizona_of_get_audio_pdata(arizona);
			if (ret < 0)
				return ret;
		}
	}

	platform_set_drvdata(pdev, cs47l24);

	cs47l24->core.arizona = arizona;
	cs47l24->core.num_inputs = 4;

	for (i = 1; i <= 2; i++) {
		cs47l24->core.adsp[i].part = "cs47l24";
		cs47l24->core.adsp[i].num = i + 1;
		cs47l24->core.adsp[i].type = WMFW_ADSP2;
		cs47l24->core.adsp[i].dev = arizona->dev;
		cs47l24->core.adsp[i].regmap = arizona->regmap;

		cs47l24->core.adsp[i].base = ARIZONA_DSP1_CONTROL_1 +
					     (0x100 * i);
		cs47l24->core.adsp[i].mem = cs47l24_dsp_regions[i - 1];
		cs47l24->core.adsp[i].num_mems =
				ARRAY_SIZE(cs47l24_dsp2_regions);

		ret = wm_adsp2_init(&cs47l24->core.adsp[i]);
		if (ret != 0)
			return ret;
	}

	for (i = 0; i < ARRAY_SIZE(cs47l24->fll); i++)
		cs47l24->fll[i].vco_mult = 3;

	arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
			 &cs47l24->fll[0]);
	arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
			 ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
			 &cs47l24->fll[1]);

	/* SR2 fixed at 8kHz, SR3 fixed at 16kHz */
	regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
			   ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
	regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
			   ARIZONA_SAMPLE_RATE_3_MASK, 0x12);

	for (i = 0; i < ARRAY_SIZE(cs47l24_dai); i++)
		arizona_init_dai(&cs47l24->core, i);

	/* Latch volume update bits */
	for (i = 0; i < ARRAY_SIZE(cs47l24_digital_vu); i++)
		regmap_update_bits(arizona->regmap, cs47l24_digital_vu[i],
				   CS47L24_DIG_VU, CS47L24_DIG_VU);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_idle(&pdev->dev);

	ret = arizona_request_irq(arizona, ARIZONA_IRQ_DSP_IRQ1,
				  "ADSP2 Compressed IRQ", cs47l24_adsp2_irq,
				  cs47l24);
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
					      &soc_component_dev_cs47l24,
					      cs47l24_dai,
					      ARRAY_SIZE(cs47l24_dai));
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register component: %d\n", ret);
		goto err_spk_irqs;
	}

	return ret;

err_spk_irqs:
	arizona_free_spk_irqs(arizona);
err_dsp_irq:
	arizona_set_irq_wake(arizona, ARIZONA_IRQ_DSP_IRQ1, 0);
	arizona_free_irq(arizona, ARIZONA_IRQ_DSP_IRQ1, cs47l24);

	return ret;
}

__attribute__((used)) static int cs47l24_remove(struct platform_device *pdev)
{
	struct cs47l24_priv *cs47l24 = platform_get_drvdata(pdev);
	struct arizona *arizona = cs47l24->core.arizona;

	pm_runtime_disable(&pdev->dev);

	wm_adsp2_remove(&cs47l24->core.adsp[1]);
	wm_adsp2_remove(&cs47l24->core.adsp[2]);

	arizona_free_spk_irqs(arizona);

	arizona_set_irq_wake(arizona, ARIZONA_IRQ_DSP_IRQ1, 0);
	arizona_free_irq(arizona, ARIZONA_IRQ_DSP_IRQ1, cs47l24);

	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_7__ {size_t* value; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct max9759 {size_t gain; int is_mute; TYPE_3__* gpiod_gain; TYPE_3__* gpiod_mute; TYPE_3__* gpiod_shutdown; } ;
struct TYPE_9__ {int ndescs; struct TYPE_9__** desc; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (TYPE_3__*) ; 
 int PTR_ERR (TYPE_3__*) ; 
 scalar_t__ SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 TYPE_3__* devm_gpiod_get_array (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct max9759* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (TYPE_3__*,int) ; 
 int /*<<< orphan*/  max9759_component_driver ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max9759*) ; 
 struct max9759* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int** speaker_gain_table ; 

__attribute__((used)) static int pga_event(struct snd_soc_dapm_widget *w,
		     struct snd_kcontrol *control, int event)
{
	struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
	struct max9759 *priv = snd_soc_component_get_drvdata(c);

	if (SND_SOC_DAPM_EVENT_ON(event))
		gpiod_set_value_cansleep(priv->gpiod_shutdown, 0);
	else
		gpiod_set_value_cansleep(priv->gpiod_shutdown, 1);

	return 0;
}

__attribute__((used)) static int speaker_gain_control_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
	struct max9759 *priv = snd_soc_component_get_drvdata(c);

	ucontrol->value.integer.value[0] = priv->gain;

	return 0;
}

__attribute__((used)) static int speaker_gain_control_put(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
	struct max9759 *priv = snd_soc_component_get_drvdata(c);

	if (ucontrol->value.integer.value[0] > 3)
		return -EINVAL;

	priv->gain = ucontrol->value.integer.value[0];

	/* G1 */
	gpiod_set_value_cansleep(priv->gpiod_gain->desc[0],
				 speaker_gain_table[priv->gain][0]);
	/* G2 */
	gpiod_set_value_cansleep(priv->gpiod_gain->desc[1],
				 speaker_gain_table[priv->gain][1]);

	return 1;
}

__attribute__((used)) static int speaker_mute_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
	struct max9759 *priv = snd_soc_component_get_drvdata(c);

	ucontrol->value.integer.value[0] = !priv->is_mute;

	return 0;
}

__attribute__((used)) static int speaker_mute_put(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
	struct max9759 *priv = snd_soc_component_get_drvdata(c);

	priv->is_mute = !ucontrol->value.integer.value[0];

	gpiod_set_value_cansleep(priv->gpiod_mute, priv->is_mute);

	return 1;
}

__attribute__((used)) static int max9759_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct max9759 *priv;
	int err;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	platform_set_drvdata(pdev, priv);

	priv->gpiod_shutdown = devm_gpiod_get(dev, "shutdown", GPIOD_OUT_HIGH);
	if (IS_ERR(priv->gpiod_shutdown)) {
		err = PTR_ERR(priv->gpiod_shutdown);
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get 'shutdown' gpio: %d", err);
		return err;
	}

	priv->gpiod_mute = devm_gpiod_get(dev, "mute", GPIOD_OUT_HIGH);
	if (IS_ERR(priv->gpiod_mute)) {
		err = PTR_ERR(priv->gpiod_mute);
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get 'mute' gpio: %d", err);
		return err;
	}
	priv->is_mute = true;

	priv->gpiod_gain = devm_gpiod_get_array(dev, "gain", GPIOD_OUT_HIGH);
	if (IS_ERR(priv->gpiod_gain)) {
		err = PTR_ERR(priv->gpiod_gain);
		if (err != -EPROBE_DEFER)
			dev_err(dev, "Failed to get 'gain' gpios: %d", err);
		return err;
	}
	priv->gain = 0;

	if (priv->gpiod_gain->ndescs != 2) {
		dev_err(dev, "Invalid 'gain' gpios count: %d",
			priv->gpiod_gain->ndescs);
		return -EINVAL;
	}

	return devm_snd_soc_register_component(dev, &max9759_component_driver,
					       NULL, 0);
}


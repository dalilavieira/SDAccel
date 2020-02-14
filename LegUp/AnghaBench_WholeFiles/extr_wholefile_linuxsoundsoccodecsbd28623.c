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
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_7__ {scalar_t__* value; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct bd28623_priv {scalar_t__ switch_spk; struct device* dev; void* mute_gpio; void* reset_gpio; TYPE_3__* supplies; } ;
struct TYPE_9__ {int /*<<< orphan*/  supply; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/ * bd28623_supply_names ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct bd28623_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_3__*) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bd28623_priv*) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_3__*) ; 
 int regulator_bulk_enable (int,TYPE_3__*) ; 
 struct bd28623_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  soc_codec_bd ; 
 int /*<<< orphan*/  soc_dai_bd ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int bd28623_power_on(struct bd28623_priv *bd)
{
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(bd->supplies), bd->supplies);
	if (ret) {
		dev_err(bd->dev, "Failed to enable supplies: %d\n", ret);
		return ret;
	}

	gpiod_set_value_cansleep(bd->reset_gpio, 0);
	usleep_range(300000, 400000);

	return 0;
}

__attribute__((used)) static void bd28623_power_off(struct bd28623_priv *bd)
{
	gpiod_set_value_cansleep(bd->reset_gpio, 1);

	regulator_bulk_disable(ARRAY_SIZE(bd->supplies), bd->supplies);
}

__attribute__((used)) static int bd28623_get_switch_spk(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component =
		snd_soc_kcontrol_component(kcontrol);
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);

	ucontrol->value.integer.value[0] = bd->switch_spk;

	return 0;
}

__attribute__((used)) static int bd28623_set_switch_spk(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component =
		snd_soc_kcontrol_component(kcontrol);
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);

	if (bd->switch_spk == ucontrol->value.integer.value[0])
		return 0;

	bd->switch_spk = ucontrol->value.integer.value[0];

	gpiod_set_value_cansleep(bd->mute_gpio, bd->switch_spk ? 0 : 1);

	return 0;
}

__attribute__((used)) static int bd28623_codec_probe(struct snd_soc_component *component)
{
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);
	int ret;

	bd->switch_spk = 1;

	ret = bd28623_power_on(bd);
	if (ret)
		return ret;

	gpiod_set_value_cansleep(bd->mute_gpio, bd->switch_spk ? 0 : 1);

	return 0;
}

__attribute__((used)) static void bd28623_codec_remove(struct snd_soc_component *component)
{
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);

	bd28623_power_off(bd);
}

__attribute__((used)) static int bd28623_codec_suspend(struct snd_soc_component *component)
{
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);

	bd28623_power_off(bd);

	return 0;
}

__attribute__((used)) static int bd28623_codec_resume(struct snd_soc_component *component)
{
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);
	int ret;

	ret = bd28623_power_on(bd);
	if (ret)
		return ret;

	gpiod_set_value_cansleep(bd->mute_gpio, bd->switch_spk ? 0 : 1);

	return 0;
}

__attribute__((used)) static int bd28623_probe(struct platform_device *pdev)
{
	struct bd28623_priv *bd;
	struct device *dev = &pdev->dev;
	int i, ret;

	bd = devm_kzalloc(&pdev->dev, sizeof(struct bd28623_priv), GFP_KERNEL);
	if (!bd)
		return -ENOMEM;

	for (i = 0; i < ARRAY_SIZE(bd->supplies); i++)
		bd->supplies[i].supply = bd28623_supply_names[i];

	ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(bd->supplies),
				      bd->supplies);
	if (ret) {
		dev_err(dev, "Failed to get supplies: %d\n", ret);
		return ret;
	}

	bd->reset_gpio = devm_gpiod_get_optional(dev, "reset",
						 GPIOD_OUT_HIGH);
	if (IS_ERR(bd->reset_gpio)) {
		dev_err(dev, "Failed to request reset_gpio: %ld\n",
			PTR_ERR(bd->reset_gpio));
		return PTR_ERR(bd->reset_gpio);
	}

	bd->mute_gpio = devm_gpiod_get_optional(dev, "mute",
						GPIOD_OUT_HIGH);
	if (IS_ERR(bd->mute_gpio)) {
		dev_err(dev, "Failed to request mute_gpio: %ld\n",
			PTR_ERR(bd->mute_gpio));
		return PTR_ERR(bd->mute_gpio);
	}

	platform_set_drvdata(pdev, bd);
	bd->dev = dev;

	return devm_snd_soc_register_component(dev, &soc_codec_bd,
					       &soc_dai_bd, 1);
}


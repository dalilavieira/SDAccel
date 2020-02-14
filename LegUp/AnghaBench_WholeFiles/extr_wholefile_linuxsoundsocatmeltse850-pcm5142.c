#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct tse850_priv {unsigned int loop1_cache; unsigned int loop2_cache; int add_cache; void* ana; void* loop2; void* loop1; void* add; } ;
struct soc_enum {unsigned int items; } ;
struct snd_soc_dapm_context {struct snd_soc_card* card; } ;
struct snd_soc_dai_link {struct device_node* codec_of_node; struct device_node* platform_of_node; struct device_node* cpu_of_node; } ;
struct snd_soc_card {struct device* dev; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_4__ {unsigned int* item; } ;
struct TYPE_5__ {int /*<<< orphan*/ * value; } ;
struct TYPE_6__ {TYPE_1__ enumerated; TYPE_2__ integer; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct tse850_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* devm_regulator_get (struct device*,char*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct snd_soc_card* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  regulator_disable (void*) ; 
 int regulator_enable (void*) ; 
 int regulator_get_voltage (void*) ; 
 int regulator_set_voltage (void*,unsigned int,unsigned int) ; 
 struct tse850_priv* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct tse850_priv*) ; 
 struct snd_soc_dapm_context* snd_soc_dapm_kcontrol_dapm (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mixer_update_power (struct snd_soc_dapm_context*,struct snd_kcontrol*,int,int /*<<< orphan*/ *) ; 
 int snd_soc_dapm_put_enum_double (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_unregister_card (struct snd_soc_card*) ; 
 struct snd_soc_card tse850_card ; 
 struct snd_soc_dai_link tse850_dailink ; 

__attribute__((used)) static int tse850_get_mux1(struct snd_kcontrol *kctrl,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);

	ucontrol->value.enumerated.item[0] = tse850->loop1_cache;

	return 0;
}

__attribute__((used)) static int tse850_put_mux1(struct snd_kcontrol *kctrl,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
	struct soc_enum *e = (struct soc_enum *)kctrl->private_value;
	unsigned int val = ucontrol->value.enumerated.item[0];

	if (val >= e->items)
		return -EINVAL;

	gpiod_set_value_cansleep(tse850->loop1, val);
	tse850->loop1_cache = val;

	return snd_soc_dapm_put_enum_double(kctrl, ucontrol);
}

__attribute__((used)) static int tse850_get_mux2(struct snd_kcontrol *kctrl,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);

	ucontrol->value.enumerated.item[0] = tse850->loop2_cache;

	return 0;
}

__attribute__((used)) static int tse850_put_mux2(struct snd_kcontrol *kctrl,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
	struct soc_enum *e = (struct soc_enum *)kctrl->private_value;
	unsigned int val = ucontrol->value.enumerated.item[0];

	if (val >= e->items)
		return -EINVAL;

	gpiod_set_value_cansleep(tse850->loop2, val);
	tse850->loop2_cache = val;

	return snd_soc_dapm_put_enum_double(kctrl, ucontrol);
}

int tse850_get_mix(struct snd_kcontrol *kctrl,
		   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);

	ucontrol->value.enumerated.item[0] = tse850->add_cache;

	return 0;
}

int tse850_put_mix(struct snd_kcontrol *kctrl,
		   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
	int connect = !!ucontrol->value.integer.value[0];

	if (tse850->add_cache == connect)
		return 0;

	/*
	 * Hmmm, this gpiod_set_value_cansleep call should probably happen
	 * inside snd_soc_dapm_mixer_update_power in the loop.
	 */
	gpiod_set_value_cansleep(tse850->add, connect);
	tse850->add_cache = connect;

	snd_soc_dapm_mixer_update_power(dapm, kctrl, connect, NULL);
	return 1;
}

int tse850_get_ana(struct snd_kcontrol *kctrl,
		   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
	int ret;

	ret = regulator_get_voltage(tse850->ana);
	if (ret < 0)
		return ret;

	/*
	 * Map regulator output values like so:
	 *      -11.5V to "Low" (enum 0)
	 * 11.5V-12.5V to "12V" (enum 1)
	 * 12.5V-13.5V to "13V" (enum 2)
	 *     ...
	 * 18.5V-19.5V to "19V" (enum 8)
	 * 19.5V-      to "20V" (enum 9)
	 */
	if (ret < 11000000)
		ret = 11000000;
	else if (ret > 20000000)
		ret = 20000000;
	ret -= 11000000;
	ret = (ret + 500000) / 1000000;

	ucontrol->value.enumerated.item[0] = ret;

	return 0;
}

int tse850_put_ana(struct snd_kcontrol *kctrl,
		   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
	struct snd_soc_card *card = dapm->card;
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
	struct soc_enum *e = (struct soc_enum *)kctrl->private_value;
	unsigned int uV = ucontrol->value.enumerated.item[0];
	int ret;

	if (uV >= e->items)
		return -EINVAL;

	/*
	 * Map enum zero (Low) to 2 volts on the regulator, do this since
	 * the ana regulator is supplied by the system 12V voltage and
	 * requesting anything below the system voltage causes the system
	 * voltage to be passed through the regulator. Also, the ana
	 * regulator induces noise when requesting voltages near the
	 * system voltage. So, by mapping Low to 2V, that noise is
	 * eliminated when all that is needed is 12V (the system voltage).
	 */
	if (uV)
		uV = 11000000 + (1000000 * uV);
	else
		uV = 2000000;

	ret = regulator_set_voltage(tse850->ana, uV, uV);
	if (ret < 0)
		return ret;

	return snd_soc_dapm_put_enum_double(kctrl, ucontrol);
}

__attribute__((used)) static int tse850_dt_init(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct device_node *codec_np, *cpu_np;
	struct snd_soc_dai_link *dailink = &tse850_dailink;

	if (!np) {
		dev_err(&pdev->dev, "only device tree supported\n");
		return -EINVAL;
	}

	cpu_np = of_parse_phandle(np, "axentia,cpu-dai", 0);
	if (!cpu_np) {
		dev_err(&pdev->dev, "failed to get cpu dai\n");
		return -EINVAL;
	}
	dailink->cpu_of_node = cpu_np;
	dailink->platform_of_node = cpu_np;
	of_node_put(cpu_np);

	codec_np = of_parse_phandle(np, "axentia,audio-codec", 0);
	if (!codec_np) {
		dev_err(&pdev->dev, "failed to get codec info\n");
		return -EINVAL;
	}
	dailink->codec_of_node = codec_np;
	of_node_put(codec_np);

	return 0;
}

__attribute__((used)) static int tse850_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &tse850_card;
	struct device *dev = card->dev = &pdev->dev;
	struct tse850_priv *tse850;
	int ret;

	tse850 = devm_kzalloc(dev, sizeof(*tse850), GFP_KERNEL);
	if (!tse850)
		return -ENOMEM;

	snd_soc_card_set_drvdata(card, tse850);

	ret = tse850_dt_init(pdev);
	if (ret) {
		dev_err(dev, "failed to init dt info\n");
		return ret;
	}

	tse850->add = devm_gpiod_get(dev, "axentia,add", GPIOD_OUT_HIGH);
	if (IS_ERR(tse850->add)) {
		if (PTR_ERR(tse850->add) != -EPROBE_DEFER)
			dev_err(dev, "failed to get 'add' gpio\n");
		return PTR_ERR(tse850->add);
	}
	tse850->add_cache = 1;

	tse850->loop1 = devm_gpiod_get(dev, "axentia,loop1", GPIOD_OUT_HIGH);
	if (IS_ERR(tse850->loop1)) {
		if (PTR_ERR(tse850->loop1) != -EPROBE_DEFER)
			dev_err(dev, "failed to get 'loop1' gpio\n");
		return PTR_ERR(tse850->loop1);
	}
	tse850->loop1_cache = 1;

	tse850->loop2 = devm_gpiod_get(dev, "axentia,loop2", GPIOD_OUT_HIGH);
	if (IS_ERR(tse850->loop2)) {
		if (PTR_ERR(tse850->loop2) != -EPROBE_DEFER)
			dev_err(dev, "failed to get 'loop2' gpio\n");
		return PTR_ERR(tse850->loop2);
	}
	tse850->loop2_cache = 1;

	tse850->ana = devm_regulator_get(dev, "axentia,ana");
	if (IS_ERR(tse850->ana)) {
		if (PTR_ERR(tse850->ana) != -EPROBE_DEFER)
			dev_err(dev, "failed to get 'ana' regulator\n");
		return PTR_ERR(tse850->ana);
	}

	ret = regulator_enable(tse850->ana);
	if (ret < 0) {
		dev_err(dev, "failed to enable the 'ana' regulator\n");
		return ret;
	}

	ret = snd_soc_register_card(card);
	if (ret) {
		dev_err(dev, "snd_soc_register_card failed\n");
		goto err_disable_ana;
	}

	return 0;

err_disable_ana:
	regulator_disable(tse850->ana);
	return ret;
}

__attribute__((used)) static int tse850_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = platform_get_drvdata(pdev);
	struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);

	snd_soc_unregister_card(card);
	regulator_disable(tse850->ana);

	return 0;
}


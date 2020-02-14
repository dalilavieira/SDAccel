#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {struct snd_soc_card* card; int /*<<< orphan*/  codec_dai; } ;
struct snd_soc_jack {int dummy; } ;
struct TYPE_5__ {int idle_bias_off; } ;
struct snd_soc_card {struct device* dev; TYPE_1__ dapm; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; } ;
struct byt_max98090_private {struct snd_soc_jack jack; } ;
struct TYPE_6__ {struct device* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  M98090_REG_SYSTEM_CLOCK ; 
 int SND_JACK_HEADSET ; 
 int SND_JACK_LINEOUT ; 
 int /*<<< orphan*/  SND_SOC_CLOCK_IN ; 
 int /*<<< orphan*/  acpi_byt_max98090_gpios ; 
 TYPE_2__ byt_max98090_card ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int devm_acpi_dev_add_driver_gpios (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct byt_max98090_private* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (struct device*,TYPE_2__*) ; 
 int /*<<< orphan*/  hs_jack_gpios ; 
 int /*<<< orphan*/  hs_jack_pins ; 
 struct byt_max98090_private* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int snd_soc_card_jack_new (struct snd_soc_card*,char*,int,struct snd_soc_jack*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (TYPE_2__*,struct byt_max98090_private*) ; 
 int snd_soc_dai_set_sysclk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_soc_jack_add_gpiods (int /*<<< orphan*/ ,struct snd_soc_jack*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int byt_max98090_init(struct snd_soc_pcm_runtime *runtime)
{
	int ret;
	struct snd_soc_card *card = runtime->card;
	struct byt_max98090_private *drv = snd_soc_card_get_drvdata(card);
	struct snd_soc_jack *jack = &drv->jack;

	card->dapm.idle_bias_off = true;

	ret = snd_soc_dai_set_sysclk(runtime->codec_dai,
				     M98090_REG_SYSTEM_CLOCK,
				     25000000, SND_SOC_CLOCK_IN);
	if (ret < 0) {
		dev_err(card->dev, "Can't set codec clock %d\n", ret);
		return ret;
	}

	/* Enable jack detection */
	ret = snd_soc_card_jack_new(runtime->card, "Headset",
				    SND_JACK_LINEOUT | SND_JACK_HEADSET, jack,
				    hs_jack_pins, ARRAY_SIZE(hs_jack_pins));
	if (ret)
		return ret;

	return snd_soc_jack_add_gpiods(card->dev->parent, jack,
				       ARRAY_SIZE(hs_jack_gpios),
				       hs_jack_gpios);
}

__attribute__((used)) static int byt_max98090_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct byt_max98090_private *priv;
	int ret_val;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv) {
		dev_err(&pdev->dev, "allocation failed\n");
		return -ENOMEM;
	}

	ret_val = devm_acpi_dev_add_driver_gpios(dev->parent, acpi_byt_max98090_gpios);
	if (ret_val)
		dev_dbg(dev, "Unable to add GPIO mapping table\n");

	byt_max98090_card.dev = &pdev->dev;
	snd_soc_card_set_drvdata(&byt_max98090_card, priv);
	ret_val = devm_snd_soc_register_card(&pdev->dev, &byt_max98090_card);
	if (ret_val) {
		dev_err(&pdev->dev,
			"snd_soc_register_card failed %d\n", ret_val);
		return ret_val;
	}

	return 0;
}


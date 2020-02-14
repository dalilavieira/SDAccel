#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {int /*<<< orphan*/  card; } ;
struct TYPE_12__ {scalar_t__ platform_data; } ;
struct platform_device {TYPE_6__ dev; } ;
struct palm27x_asoc_info {int /*<<< orphan*/  jack_gpio; } ;
struct TYPE_11__ {TYPE_6__* dev; } ;
struct TYPE_10__ {int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_1__*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  SND_JACK_HEADPHONE ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 int devm_snd_soc_register_card (TYPE_6__*,TYPE_3__*) ; 
 int /*<<< orphan*/  hs_jack ; 
 TYPE_1__* hs_jack_gpios ; 
 TYPE_1__* hs_jack_pins ; 
 scalar_t__ machine_is_palmld () ; 
 scalar_t__ machine_is_palmt5 () ; 
 scalar_t__ machine_is_palmte2 () ; 
 scalar_t__ machine_is_palmtx () ; 
 TYPE_3__ palm27x_asoc ; 
 int snd_soc_card_jack_new (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int snd_soc_jack_add_gpios (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 

__attribute__((used)) static int palm27x_ac97_init(struct snd_soc_pcm_runtime *rtd)
{
	int err;

	/* Jack detection API stuff */
	err = snd_soc_card_jack_new(rtd->card, "Headphone Jack",
				    SND_JACK_HEADPHONE, &hs_jack, hs_jack_pins,
				    ARRAY_SIZE(hs_jack_pins));
	if (err)
		return err;

	err = snd_soc_jack_add_gpios(&hs_jack, ARRAY_SIZE(hs_jack_gpios),
				hs_jack_gpios);

	return err;
}

__attribute__((used)) static int palm27x_asoc_probe(struct platform_device *pdev)
{
	int ret;

	if (!(machine_is_palmtx() || machine_is_palmt5() ||
		machine_is_palmld() || machine_is_palmte2()))
		return -ENODEV;

	if (!pdev->dev.platform_data) {
		dev_err(&pdev->dev, "please supply platform_data\n");
		return -ENODEV;
	}

	hs_jack_gpios[0].gpio = ((struct palm27x_asoc_info *)
			(pdev->dev.platform_data))->jack_gpio;

	palm27x_asoc.dev = &pdev->dev;

	ret = devm_snd_soc_register_card(&pdev->dev, &palm27x_asoc);
	if (ret)
		dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
			ret);
	return ret;
}


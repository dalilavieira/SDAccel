#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dapm_widget {TYPE_1__* dapm; } ;
struct snd_soc_card {int /*<<< orphan*/ * dev; } ;
struct snd_kcontrol {int dummy; } ;
struct qi_lb60 {void* amp_gpio; void* snd_gpio; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  card; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  SND_SOC_DAPM_EVENT_OFF (int) ; 
 void* devm_gpiod_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct qi_lb60* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,struct snd_soc_card*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 struct snd_soc_card qi_lb60_card ; 
 struct qi_lb60* snd_soc_card_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct qi_lb60*) ; 

__attribute__((used)) static int qi_lb60_spk_event(struct snd_soc_dapm_widget *widget,
			     struct snd_kcontrol *ctrl, int event)
{
	struct qi_lb60 *qi_lb60 = snd_soc_card_get_drvdata(widget->dapm->card);
	int on = !SND_SOC_DAPM_EVENT_OFF(event);

	gpiod_set_value_cansleep(qi_lb60->snd_gpio, on);
	gpiod_set_value_cansleep(qi_lb60->amp_gpio, on);

	return 0;
}

__attribute__((used)) static int qi_lb60_probe(struct platform_device *pdev)
{
	struct qi_lb60 *qi_lb60;
	struct snd_soc_card *card = &qi_lb60_card;

	qi_lb60 = devm_kzalloc(&pdev->dev, sizeof(*qi_lb60), GFP_KERNEL);
	if (!qi_lb60)
		return -ENOMEM;

	qi_lb60->snd_gpio = devm_gpiod_get(&pdev->dev, "snd", GPIOD_OUT_LOW);
	if (IS_ERR(qi_lb60->snd_gpio))
		return PTR_ERR(qi_lb60->snd_gpio);

	qi_lb60->amp_gpio = devm_gpiod_get(&pdev->dev, "amp", GPIOD_OUT_LOW);
	if (IS_ERR(qi_lb60->amp_gpio))
		return PTR_ERR(qi_lb60->amp_gpio);

	card->dev = &pdev->dev;

	snd_soc_card_set_drvdata(card, qi_lb60);

	return devm_snd_soc_register_card(&pdev->dev, card);
}


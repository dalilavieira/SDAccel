#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_pcm_runtime {TYPE_3__* codec_dai; } ;
struct snd_soc_dapm_widget {TYPE_1__* dapm; } ;
struct snd_soc_component {int dummy; } ;
struct snd_soc_card {TYPE_2__* dai_link; } ;
struct snd_kcontrol {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int /*<<< orphan*/ * dev; } ;
struct TYPE_8__ {struct snd_soc_component* component; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct TYPE_6__ {struct snd_soc_card* card; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC97_3D_CONTROL ; 
 int /*<<< orphan*/  AC97_GPIO_CFG ; 
 int /*<<< orphan*/  AC97_GPIO_PULL ; 
 int ENODEV ; 
 int SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int devm_snd_soc_register_card (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  machine_is_mioa701 () ; 
 TYPE_4__ mioa701 ; 
 unsigned short snd_soc_component_read32 (struct snd_soc_component*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,unsigned short) ; 
 struct snd_soc_pcm_runtime* snd_soc_get_pcm_runtime (struct snd_soc_card*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rear_amp_power(struct snd_soc_component *component, int power)
{
	unsigned short reg;

	if (power) {
		reg = snd_soc_component_read32(component, AC97_GPIO_CFG);
		snd_soc_component_write(component, AC97_GPIO_CFG, reg | 0x0100);
		reg = snd_soc_component_read32(component, AC97_GPIO_PULL);
		snd_soc_component_write(component, AC97_GPIO_PULL, reg | (1<<15));
	} else {
		reg = snd_soc_component_read32(component, AC97_GPIO_CFG);
		snd_soc_component_write(component, AC97_GPIO_CFG, reg & ~0x0100);
		reg = snd_soc_component_read32(component, AC97_GPIO_PULL);
		snd_soc_component_write(component, AC97_GPIO_PULL, reg & ~(1<<15));
	}

	return 0;
}

__attribute__((used)) static int rear_amp_event(struct snd_soc_dapm_widget *widget,
			  struct snd_kcontrol *kctl, int event)
{
	struct snd_soc_card *card = widget->dapm->card;
	struct snd_soc_pcm_runtime *rtd;
	struct snd_soc_component *component;

	rtd = snd_soc_get_pcm_runtime(card, card->dai_link[0].name);
	component = rtd->codec_dai->component;
	return rear_amp_power(component, SND_SOC_DAPM_EVENT_ON(event));
}

__attribute__((used)) static int mioa701_wm9713_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_component *component = rtd->codec_dai->component;

	/* Prepare GPIO8 for rear speaker amplifier */
	snd_soc_component_update_bits(component, AC97_GPIO_CFG, 0x100, 0x100);

	/* Prepare MIC input */
	snd_soc_component_update_bits(component, AC97_3D_CONTROL, 0xc000, 0xc000);

	return 0;
}

__attribute__((used)) static int mioa701_wm9713_probe(struct platform_device *pdev)
{
	int rc;

	if (!machine_is_mioa701())
		return -ENODEV;

	mioa701.dev = &pdev->dev;
	rc = devm_snd_soc_register_card(&pdev->dev, &mioa701);
	if (!rc)
		dev_warn(&pdev->dev, "Be warned that incorrect mixers/muxes setup will "
			 "lead to overheating and possible destruction of your device."
			 " Do not use without a good knowledge of mio's board design!\n");
	return rc;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct tegra_wm9712 {int /*<<< orphan*/  codec; int /*<<< orphan*/  util_data; } ;
struct snd_soc_pcm_runtime {TYPE_1__* card; } ;
struct snd_soc_card {TYPE_3__* dev; } ;
struct TYPE_8__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_7__ {scalar_t__ cpu_of_node; scalar_t__ platform_of_node; } ;
struct TYPE_6__ {int /*<<< orphan*/  dapm; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct tegra_wm9712* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int platform_device_add (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_alloc (char*,int) ; 
 int /*<<< orphan*/  platform_device_del (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_unregister (int /*<<< orphan*/ ) ; 
 struct snd_soc_card* platform_get_drvdata (struct platform_device*) ; 
 struct tegra_wm9712* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct tegra_wm9712*) ; 
 int snd_soc_dapm_force_enable_pin (int /*<<< orphan*/ *,char*) ; 
 int snd_soc_of_parse_audio_routing (struct snd_soc_card*,char*) ; 
 int snd_soc_of_parse_card_name (struct snd_soc_card*,char*) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 struct snd_soc_card snd_soc_tegra_wm9712 ; 
 int /*<<< orphan*/  snd_soc_unregister_card (struct snd_soc_card*) ; 
 int /*<<< orphan*/  tegra_asoc_utils_fini (int /*<<< orphan*/ *) ; 
 int tegra_asoc_utils_init (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int tegra_asoc_utils_set_ac97_rate (int /*<<< orphan*/ *) ; 
 TYPE_2__ tegra_wm9712_dai ; 

__attribute__((used)) static int tegra_wm9712_init(struct snd_soc_pcm_runtime *rtd)
{
	return snd_soc_dapm_force_enable_pin(&rtd->card->dapm, "Mic Bias");
}

__attribute__((used)) static int tegra_wm9712_driver_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct snd_soc_card *card = &snd_soc_tegra_wm9712;
	struct tegra_wm9712 *machine;
	int ret;

	machine = devm_kzalloc(&pdev->dev, sizeof(struct tegra_wm9712),
			       GFP_KERNEL);
	if (!machine)
		return -ENOMEM;

	card->dev = &pdev->dev;
	snd_soc_card_set_drvdata(card, machine);

	machine->codec = platform_device_alloc("wm9712-codec", -1);
	if (!machine->codec) {
		dev_err(&pdev->dev, "Can't allocate wm9712 platform device\n");
		return -ENOMEM;
	}

	ret = platform_device_add(machine->codec);
	if (ret)
		goto codec_put;

	ret = snd_soc_of_parse_card_name(card, "nvidia,model");
	if (ret)
		goto codec_unregister;

	ret = snd_soc_of_parse_audio_routing(card, "nvidia,audio-routing");
	if (ret)
		goto codec_unregister;

	tegra_wm9712_dai.cpu_of_node = of_parse_phandle(np,
				       "nvidia,ac97-controller", 0);
	if (!tegra_wm9712_dai.cpu_of_node) {
		dev_err(&pdev->dev,
			"Property 'nvidia,ac97-controller' missing or invalid\n");
		ret = -EINVAL;
		goto codec_unregister;
	}

	tegra_wm9712_dai.platform_of_node = tegra_wm9712_dai.cpu_of_node;

	ret = tegra_asoc_utils_init(&machine->util_data, &pdev->dev);
	if (ret)
		goto codec_unregister;

	ret = tegra_asoc_utils_set_ac97_rate(&machine->util_data);
	if (ret)
		goto asoc_utils_fini;

	ret = snd_soc_register_card(card);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
			ret);
		goto asoc_utils_fini;
	}

	return 0;

asoc_utils_fini:
	tegra_asoc_utils_fini(&machine->util_data);
codec_unregister:
	platform_device_del(machine->codec);
codec_put:
	platform_device_put(machine->codec);
	return ret;
}

__attribute__((used)) static int tegra_wm9712_driver_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = platform_get_drvdata(pdev);
	struct tegra_wm9712 *machine = snd_soc_card_get_drvdata(card);

	snd_soc_unregister_card(card);

	tegra_asoc_utils_fini(&machine->util_data);

	platform_device_unregister(machine->codec);

	return 0;
}


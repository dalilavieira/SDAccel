#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_pcm_runtime {int dummy; } ;
struct snd_soc_dai_link {int num_links; int no_pcm; int (* be_hw_params_fixup ) (struct snd_soc_pcm_runtime*,struct snd_pcm_hw_params*) ;struct snd_soc_dai_link* dai_link; struct device* dev; } ;
struct snd_soc_card {int num_links; int no_pcm; int (* be_hw_params_fixup ) (struct snd_soc_pcm_runtime*,struct snd_pcm_hw_params*) ;struct snd_soc_card* dai_link; struct device* dev; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_interval {int min; int max; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct snd_soc_dai_link* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct snd_soc_dai_link*) ; 
 struct snd_interval* hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct snd_soc_dai_link*) ; 
 struct snd_soc_dai_link* kzalloc (int,int /*<<< orphan*/ ) ; 
 int qcom_snd_parse_of (struct snd_soc_dai_link*) ; 
 int snd_soc_register_card (struct snd_soc_dai_link*) ; 
 int /*<<< orphan*/  snd_soc_unregister_card (struct snd_soc_dai_link*) ; 

__attribute__((used)) static int apq8096_be_hw_params_fixup(struct snd_soc_pcm_runtime *rtd,
				      struct snd_pcm_hw_params *params)
{
	struct snd_interval *rate = hw_param_interval(params,
					SNDRV_PCM_HW_PARAM_RATE);
	struct snd_interval *channels = hw_param_interval(params,
					SNDRV_PCM_HW_PARAM_CHANNELS);

	rate->min = rate->max = 48000;
	channels->min = channels->max = 2;

	return 0;
}

__attribute__((used)) static void apq8096_add_be_ops(struct snd_soc_card *card)
{
	struct snd_soc_dai_link *link = card->dai_link;
	int i, num_links = card->num_links;

	for (i = 0; i < num_links; i++) {
		if (link->no_pcm == 1)
			link->be_hw_params_fixup = apq8096_be_hw_params_fixup;
		link++;
	}
}

__attribute__((used)) static int apq8096_platform_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card;
	struct device *dev = &pdev->dev;
	int ret;

	card = kzalloc(sizeof(*card), GFP_KERNEL);
	if (!card)
		return -ENOMEM;

	card->dev = dev;
	dev_set_drvdata(dev, card);
	ret = qcom_snd_parse_of(card);
	if (ret) {
		dev_err(dev, "Error parsing OF data\n");
		goto err;
	}

	apq8096_add_be_ops(card);
	ret = snd_soc_register_card(card);
	if (ret)
		goto err_card_register;

	return 0;

err_card_register:
	kfree(card->dai_link);
err:
	kfree(card);
	return ret;
}

__attribute__((used)) static int apq8096_platform_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = dev_get_drvdata(&pdev->dev);

	snd_soc_unregister_card(card);
	kfree(card->dai_link);
	kfree(card);

	return 0;
}


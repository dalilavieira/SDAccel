#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_card {int num_links; TYPE_2__* dai_link; TYPE_3__* dev; } ;
struct snd_pcm_substream {TYPE_1__* pstr; } ;
struct psc_dma_stream {int dummy; } ;
struct psc_dma {struct psc_dma_stream playback; struct psc_dma_stream capture; } ;
struct TYPE_7__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct pcm030_audio_data {int /*<<< orphan*/  codec_device; struct snd_soc_card* card; } ;
struct device_node {int dummy; } ;
struct TYPE_6__ {struct device_node* platform_of_node; } ;
struct TYPE_5__ {scalar_t__ stream; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ SNDRV_PCM_STREAM_CAPTURE ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct pcm030_audio_data* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_machine_is_compatible (char*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct snd_soc_card pcm030_card ; 
 int platform_device_add (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_alloc (char*,int) ; 
 int /*<<< orphan*/  platform_device_unregister (int /*<<< orphan*/ ) ; 
 struct pcm030_audio_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pcm030_audio_data*) ; 
 int request_module (char*) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 int snd_soc_unregister_card (struct snd_soc_card*) ; 

__attribute__((used)) static inline struct psc_dma_stream *
to_psc_dma_stream(struct snd_pcm_substream *substream, struct psc_dma *psc_dma)
{
	if (substream->pstr->stream == SNDRV_PCM_STREAM_CAPTURE)
		return &psc_dma->capture;
	return &psc_dma->playback;
}

__attribute__((used)) static int pcm030_fabric_probe(struct platform_device *op)
{
	struct device_node *np = op->dev.of_node;
	struct device_node *platform_np;
	struct snd_soc_card *card = &pcm030_card;
	struct pcm030_audio_data *pdata;
	int ret;
	int i;

	if (!of_machine_is_compatible("phytec,pcm030"))
		return -ENODEV;

	pdata = devm_kzalloc(&op->dev, sizeof(struct pcm030_audio_data),
			     GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;

	card->dev = &op->dev;

	pdata->card = card;

	platform_np = of_parse_phandle(np, "asoc-platform", 0);
	if (!platform_np) {
		dev_err(&op->dev, "ac97 not registered\n");
		return -ENODEV;
	}

	for (i = 0; i < card->num_links; i++)
		card->dai_link[i].platform_of_node = platform_np;

	ret = request_module("snd-soc-wm9712");
	if (ret)
		dev_err(&op->dev, "request_module returned: %d\n", ret);

	pdata->codec_device = platform_device_alloc("wm9712-codec", -1);
	if (!pdata->codec_device)
		dev_err(&op->dev, "platform_device_alloc() failed\n");

	ret = platform_device_add(pdata->codec_device);
	if (ret)
		dev_err(&op->dev, "platform_device_add() failed: %d\n", ret);

	ret = snd_soc_register_card(card);
	if (ret)
		dev_err(&op->dev, "snd_soc_register_card() failed: %d\n", ret);

	platform_set_drvdata(op, pdata);

	return ret;
}

__attribute__((used)) static int pcm030_fabric_remove(struct platform_device *op)
{
	struct pcm030_audio_data *pdata = platform_get_drvdata(op);
	int ret;

	ret = snd_soc_unregister_card(pdata->card);
	platform_device_unregister(pdata->codec_device);

	return ret;
}


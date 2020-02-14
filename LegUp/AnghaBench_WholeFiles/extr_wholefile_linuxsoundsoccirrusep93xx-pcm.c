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
struct ep93xx_dma_data {scalar_t__ direction; } ;
struct dma_chan {struct ep93xx_dma_data* private; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int SND_DMAENGINE_PCM_FLAG_COMPAT ; 
 int SND_DMAENGINE_PCM_FLAG_NO_DT ; 
 int devm_snd_dmaengine_pcm_register (struct device*,int /*<<< orphan*/ *,int) ; 
 scalar_t__ ep93xx_dma_chan_direction (struct dma_chan*) ; 
 int /*<<< orphan*/  ep93xx_dmaengine_pcm_config ; 

__attribute__((used)) static bool ep93xx_pcm_dma_filter(struct dma_chan *chan, void *filter_param)
{
	struct ep93xx_dma_data *data = filter_param;

	if (data->direction == ep93xx_dma_chan_direction(chan)) {
		chan->private = data;
		return true;
	}

	return false;
}

int devm_ep93xx_pcm_platform_register(struct device *dev)
{
	return devm_snd_dmaengine_pcm_register(dev,
		&ep93xx_dmaengine_pcm_config,
		SND_DMAENGINE_PCM_FLAG_NO_DT |
		SND_DMAENGINE_PCM_FLAG_COMPAT);
}


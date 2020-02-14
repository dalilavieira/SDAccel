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
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_plugin_format {int channels; int /*<<< orphan*/  rate; int /*<<< orphan*/  format; } ;
struct TYPE_5__ {void* addr; } ;
struct snd_pcm_plugin_channel {int wanted; TYPE_2__ area; scalar_t__ enabled; } ;
struct TYPE_6__ {unsigned int channels; } ;
struct TYPE_4__ {int channels; } ;
struct snd_pcm_plugin {scalar_t__ access; int (* transfer ) (struct snd_pcm_plugin*,struct snd_pcm_plugin_channel const*,struct snd_pcm_plugin_channel*,int) ;int (* client_channels ) (struct snd_pcm_plugin*,int,struct snd_pcm_plugin_channel**) ;TYPE_3__ src_format; int /*<<< orphan*/  plug; scalar_t__ extra_data; TYPE_1__ dst_format; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_mask {int dummy; } ;
typedef  int snd_pcm_uframes_t ;
typedef  int snd_pcm_sframes_t ;

/* Variables and functions */
 int ENXIO ; 
 scalar_t__ SNDRV_PCM_ACCESS_RW_INTERLEAVED ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 scalar_t__ params_access (struct snd_pcm_hw_params*) ; 
 int params_channels (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_format (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  params_rate (struct snd_pcm_hw_params*) ; 
 int pcm_read (int /*<<< orphan*/ ,void*,int) ; 
 int pcm_readv (int /*<<< orphan*/ ,void**,int) ; 
 int pcm_write (int /*<<< orphan*/ ,void*,int) ; 
 int pcm_writev (int /*<<< orphan*/ ,void**,int) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 scalar_t__ snd_pcm_plug_stream (struct snd_pcm_substream*) ; 
 int snd_pcm_plugin_build (struct snd_pcm_substream*,char*,struct snd_pcm_plugin_format*,struct snd_pcm_plugin_format*,int,struct snd_pcm_plugin**) ; 
 int snd_pcm_plugin_client_channels (struct snd_pcm_plugin*,int,struct snd_pcm_plugin_channel**) ; 

__attribute__((used)) static inline snd_pcm_sframes_t snd_pcm_plug_client_size(struct snd_pcm_substream *handle, snd_pcm_uframes_t drv_size) { return drv_size; }

__attribute__((used)) static inline snd_pcm_sframes_t snd_pcm_plug_slave_size(struct snd_pcm_substream *handle, snd_pcm_uframes_t clt_size) { return clt_size; }

__attribute__((used)) static inline int snd_pcm_plug_slave_format(int format, const struct snd_mask *format_mask) { return format; }

__attribute__((used)) static snd_pcm_sframes_t io_playback_transfer(struct snd_pcm_plugin *plugin,
				    const struct snd_pcm_plugin_channel *src_channels,
				    struct snd_pcm_plugin_channel *dst_channels,
				    snd_pcm_uframes_t frames)
{
	if (snd_BUG_ON(!plugin))
		return -ENXIO;
	if (snd_BUG_ON(!src_channels))
		return -ENXIO;
	if (plugin->access == SNDRV_PCM_ACCESS_RW_INTERLEAVED) {
		return pcm_write(plugin->plug, src_channels->area.addr, frames);
	} else {
		int channel, channels = plugin->dst_format.channels;
		void **bufs = (void**)plugin->extra_data;
		if (snd_BUG_ON(!bufs))
			return -ENXIO;
		for (channel = 0; channel < channels; channel++) {
			if (src_channels[channel].enabled)
				bufs[channel] = src_channels[channel].area.addr;
			else
				bufs[channel] = NULL;
		}
		return pcm_writev(plugin->plug, bufs, frames);
	}
}

__attribute__((used)) static snd_pcm_sframes_t io_capture_transfer(struct snd_pcm_plugin *plugin,
				   const struct snd_pcm_plugin_channel *src_channels,
				   struct snd_pcm_plugin_channel *dst_channels,
				   snd_pcm_uframes_t frames)
{
	if (snd_BUG_ON(!plugin))
		return -ENXIO;
	if (snd_BUG_ON(!dst_channels))
		return -ENXIO;
	if (plugin->access == SNDRV_PCM_ACCESS_RW_INTERLEAVED) {
		return pcm_read(plugin->plug, dst_channels->area.addr, frames);
	} else {
		int channel, channels = plugin->dst_format.channels;
		void **bufs = (void**)plugin->extra_data;
		if (snd_BUG_ON(!bufs))
			return -ENXIO;
		for (channel = 0; channel < channels; channel++) {
			if (dst_channels[channel].enabled)
				bufs[channel] = dst_channels[channel].area.addr;
			else
				bufs[channel] = NULL;
		}
		return pcm_readv(plugin->plug, bufs, frames);
	}
	return 0;
}

__attribute__((used)) static snd_pcm_sframes_t io_src_channels(struct snd_pcm_plugin *plugin,
			     snd_pcm_uframes_t frames,
			     struct snd_pcm_plugin_channel **channels)
{
	int err;
	unsigned int channel;
	struct snd_pcm_plugin_channel *v;
	err = snd_pcm_plugin_client_channels(plugin, frames, &v);
	if (err < 0)
		return err;
	*channels = v;
	if (plugin->access == SNDRV_PCM_ACCESS_RW_INTERLEAVED) {
		for (channel = 0; channel < plugin->src_format.channels; ++channel, ++v)
			v->wanted = 1;
	}
	return frames;
}

int snd_pcm_plugin_build_io(struct snd_pcm_substream *plug,
			    struct snd_pcm_hw_params *params,
			    struct snd_pcm_plugin **r_plugin)
{
	int err;
	struct snd_pcm_plugin_format format;
	struct snd_pcm_plugin *plugin;

	if (snd_BUG_ON(!r_plugin))
		return -ENXIO;
	*r_plugin = NULL;
	if (snd_BUG_ON(!plug || !params))
		return -ENXIO;
	format.format = params_format(params);
	format.rate = params_rate(params);
	format.channels = params_channels(params);
	err = snd_pcm_plugin_build(plug, "I/O io",
				   &format, &format,
				   sizeof(void *) * format.channels,
				   &plugin);
	if (err < 0)
		return err;
	plugin->access = params_access(params);
	if (snd_pcm_plug_stream(plug) == SNDRV_PCM_STREAM_PLAYBACK) {
		plugin->transfer = io_playback_transfer;
		if (plugin->access == SNDRV_PCM_ACCESS_RW_INTERLEAVED)
			plugin->client_channels = io_src_channels;
	} else {
		plugin->transfer = io_capture_transfer;
	}

	*r_plugin = plugin;
	return 0;
}


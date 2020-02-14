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
struct snd_pcm_plugin_format {int channels; scalar_t__ format; short rate; } ;
struct TYPE_6__ {int first; int step; scalar_t__ addr; } ;
struct snd_pcm_plugin_channel {int enabled; short frames; TYPE_3__ area; scalar_t__ wanted; } ;
struct TYPE_5__ {scalar_t__ rate; int /*<<< orphan*/  format; } ;
struct TYPE_4__ {unsigned int channels; scalar_t__ rate; } ;
struct snd_pcm_plugin {short (* transfer ) (struct snd_pcm_plugin*,struct snd_pcm_plugin_channel const*,struct snd_pcm_plugin_channel*,short) ;short (* src_frames ) (struct snd_pcm_plugin*,short) ;short (* dst_frames ) (struct snd_pcm_plugin*,short) ;int (* action ) (struct snd_pcm_plugin*,int,unsigned long) ;scalar_t__ extra_data; TYPE_2__ dst_format; TYPE_1__ src_format; } ;
struct snd_mask {int dummy; } ;
struct rate_priv {unsigned int pos; short pitch; short old_src_frames; short old_dst_frames; void (* func ) (struct snd_pcm_plugin*,struct snd_pcm_plugin_channel const*,struct snd_pcm_plugin_channel*,short,short) ;struct rate_channel* channels; } ;
struct rate_channel {short last_S1; short last_S2; } ;
typedef  short snd_pcm_uframes_t ;
typedef  short snd_pcm_sframes_t ;
typedef  enum snd_pcm_plugin_action { ____Placeholder_snd_pcm_plugin_action } snd_pcm_plugin_action ;

/* Variables and functions */
 short BITS ; 
 short ENXIO ; 
#define  INIT 129 
#define  PREPARE 128 
 unsigned int R_MASK ; 
 short SHIFT ; 
 scalar_t__ SNDRV_PCM_FORMAT_S16 ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_pcm_area_silence (TYPE_3__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_pcm_plugin_build (struct snd_pcm_substream*,char*,struct snd_pcm_plugin_format*,struct snd_pcm_plugin_format*,int,struct snd_pcm_plugin**) ; 
 void stub1 (struct snd_pcm_plugin*,struct snd_pcm_plugin_channel const*,struct snd_pcm_plugin_channel*,short,short) ; 

__attribute__((used)) static inline snd_pcm_sframes_t snd_pcm_plug_client_size(struct snd_pcm_substream *handle, snd_pcm_uframes_t drv_size) { return drv_size; }

__attribute__((used)) static inline snd_pcm_sframes_t snd_pcm_plug_slave_size(struct snd_pcm_substream *handle, snd_pcm_uframes_t clt_size) { return clt_size; }

__attribute__((used)) static inline int snd_pcm_plug_slave_format(int format, const struct snd_mask *format_mask) { return format; }

__attribute__((used)) static void rate_init(struct snd_pcm_plugin *plugin)
{
	unsigned int channel;
	struct rate_priv *data = (struct rate_priv *)plugin->extra_data;
	data->pos = 0;
	for (channel = 0; channel < plugin->src_format.channels; channel++) {
		data->channels[channel].last_S1 = 0;
		data->channels[channel].last_S2 = 0;
	}
}

__attribute__((used)) static void resample_expand(struct snd_pcm_plugin *plugin,
			    const struct snd_pcm_plugin_channel *src_channels,
			    struct snd_pcm_plugin_channel *dst_channels,
			    int src_frames, int dst_frames)
{
	unsigned int pos = 0;
	signed int val;
	signed short S1, S2;
	signed short *src, *dst;
	unsigned int channel;
	int src_step, dst_step;
	int src_frames1, dst_frames1;
	struct rate_priv *data = (struct rate_priv *)plugin->extra_data;
	struct rate_channel *rchannels = data->channels;
	
	for (channel = 0; channel < plugin->src_format.channels; channel++) {
		pos = data->pos;
		S1 = rchannels->last_S1;
		S2 = rchannels->last_S2;
		if (!src_channels[channel].enabled) {
			if (dst_channels[channel].wanted)
				snd_pcm_area_silence(&dst_channels[channel].area, 0, dst_frames, plugin->dst_format.format);
			dst_channels[channel].enabled = 0;
			continue;
		}
		dst_channels[channel].enabled = 1;
		src = (signed short *)src_channels[channel].area.addr +
			src_channels[channel].area.first / 8 / 2;
		dst = (signed short *)dst_channels[channel].area.addr +
			dst_channels[channel].area.first / 8 / 2;
		src_step = src_channels[channel].area.step / 8 / 2;
		dst_step = dst_channels[channel].area.step / 8 / 2;
		src_frames1 = src_frames;
		dst_frames1 = dst_frames;
		while (dst_frames1-- > 0) {
			if (pos & ~R_MASK) {
				pos &= R_MASK;
				S1 = S2;
				if (src_frames1-- > 0) {
					S2 = *src;
					src += src_step;
				}
			}
			val = S1 + ((S2 - S1) * (signed int)pos) / BITS;
			if (val < -32768)
				val = -32768;
			else if (val > 32767)
				val = 32767;
			*dst = val;
			dst += dst_step;
			pos += data->pitch;
		}
		rchannels->last_S1 = S1;
		rchannels->last_S2 = S2;
		rchannels++;
	}
	data->pos = pos;
}

__attribute__((used)) static void resample_shrink(struct snd_pcm_plugin *plugin,
			    const struct snd_pcm_plugin_channel *src_channels,
			    struct snd_pcm_plugin_channel *dst_channels,
			    int src_frames, int dst_frames)
{
	unsigned int pos = 0;
	signed int val;
	signed short S1, S2;
	signed short *src, *dst;
	unsigned int channel;
	int src_step, dst_step;
	int src_frames1, dst_frames1;
	struct rate_priv *data = (struct rate_priv *)plugin->extra_data;
	struct rate_channel *rchannels = data->channels;

	for (channel = 0; channel < plugin->src_format.channels; ++channel) {
		pos = data->pos;
		S1 = rchannels->last_S1;
		S2 = rchannels->last_S2;
		if (!src_channels[channel].enabled) {
			if (dst_channels[channel].wanted)
				snd_pcm_area_silence(&dst_channels[channel].area, 0, dst_frames, plugin->dst_format.format);
			dst_channels[channel].enabled = 0;
			continue;
		}
		dst_channels[channel].enabled = 1;
		src = (signed short *)src_channels[channel].area.addr +
			src_channels[channel].area.first / 8 / 2;
		dst = (signed short *)dst_channels[channel].area.addr +
			dst_channels[channel].area.first / 8 / 2;
		src_step = src_channels[channel].area.step / 8 / 2;
		dst_step = dst_channels[channel].area.step / 8 / 2;
		src_frames1 = src_frames;
		dst_frames1 = dst_frames;
		while (dst_frames1 > 0) {
			S1 = S2;
			if (src_frames1-- > 0) {
				S2 = *src;
				src += src_step;
			}
			if (pos & ~R_MASK) {
				pos &= R_MASK;
				val = S1 + ((S2 - S1) * (signed int)pos) / BITS;
				if (val < -32768)
					val = -32768;
				else if (val > 32767)
					val = 32767;
				*dst = val;
				dst += dst_step;
				dst_frames1--;
			}
			pos += data->pitch;
		}
		rchannels->last_S1 = S1;
		rchannels->last_S2 = S2;
		rchannels++;
	}
	data->pos = pos;
}

__attribute__((used)) static snd_pcm_sframes_t rate_src_frames(struct snd_pcm_plugin *plugin, snd_pcm_uframes_t frames)
{
	struct rate_priv *data;
	snd_pcm_sframes_t res;

	if (snd_BUG_ON(!plugin))
		return -ENXIO;
	if (frames == 0)
		return 0;
	data = (struct rate_priv *)plugin->extra_data;
	if (plugin->src_format.rate < plugin->dst_format.rate) {
		res = (((frames * data->pitch) + (BITS/2)) >> SHIFT);
	} else {
		res = (((frames << SHIFT) + (data->pitch / 2)) / data->pitch);		
	}
	if (data->old_src_frames > 0) {
		snd_pcm_sframes_t frames1 = frames, res1 = data->old_dst_frames;
		while (data->old_src_frames < frames1) {
			frames1 >>= 1;
			res1 <<= 1;
		}
		while (data->old_src_frames > frames1) {
			frames1 <<= 1;
			res1 >>= 1;
		}
		if (data->old_src_frames == frames1)
			return res1;
	}
	data->old_src_frames = frames;
	data->old_dst_frames = res;
	return res;
}

__attribute__((used)) static snd_pcm_sframes_t rate_dst_frames(struct snd_pcm_plugin *plugin, snd_pcm_uframes_t frames)
{
	struct rate_priv *data;
	snd_pcm_sframes_t res;

	if (snd_BUG_ON(!plugin))
		return -ENXIO;
	if (frames == 0)
		return 0;
	data = (struct rate_priv *)plugin->extra_data;
	if (plugin->src_format.rate < plugin->dst_format.rate) {
		res = (((frames << SHIFT) + (data->pitch / 2)) / data->pitch);
	} else {
		res = (((frames * data->pitch) + (BITS/2)) >> SHIFT);
	}
	if (data->old_dst_frames > 0) {
		snd_pcm_sframes_t frames1 = frames, res1 = data->old_src_frames;
		while (data->old_dst_frames < frames1) {
			frames1 >>= 1;
			res1 <<= 1;
		}
		while (data->old_dst_frames > frames1) {
			frames1 <<= 1;
			res1 >>= 1;
		}
		if (data->old_dst_frames == frames1)
			return res1;
	}
	data->old_dst_frames = frames;
	data->old_src_frames = res;
	return res;
}

__attribute__((used)) static snd_pcm_sframes_t rate_transfer(struct snd_pcm_plugin *plugin,
			     const struct snd_pcm_plugin_channel *src_channels,
			     struct snd_pcm_plugin_channel *dst_channels,
			     snd_pcm_uframes_t frames)
{
	snd_pcm_uframes_t dst_frames;
	struct rate_priv *data;

	if (snd_BUG_ON(!plugin || !src_channels || !dst_channels))
		return -ENXIO;
	if (frames == 0)
		return 0;
#ifdef CONFIG_SND_DEBUG
	{
		unsigned int channel;
		for (channel = 0; channel < plugin->src_format.channels; channel++) {
			if (snd_BUG_ON(src_channels[channel].area.first % 8 ||
				       src_channels[channel].area.step % 8))
				return -ENXIO;
			if (snd_BUG_ON(dst_channels[channel].area.first % 8 ||
				       dst_channels[channel].area.step % 8))
				return -ENXIO;
		}
	}
#endif

	dst_frames = rate_dst_frames(plugin, frames);
	if (dst_frames > dst_channels[0].frames)
		dst_frames = dst_channels[0].frames;
	data = (struct rate_priv *)plugin->extra_data;
	data->func(plugin, src_channels, dst_channels, frames, dst_frames);
	return dst_frames;
}

__attribute__((used)) static int rate_action(struct snd_pcm_plugin *plugin,
		       enum snd_pcm_plugin_action action,
		       unsigned long udata)
{
	if (snd_BUG_ON(!plugin))
		return -ENXIO;
	switch (action) {
	case INIT:
	case PREPARE:
		rate_init(plugin);
		break;
	default:
		break;
	}
	return 0;	/* silenty ignore other actions */
}

int snd_pcm_plugin_build_rate(struct snd_pcm_substream *plug,
			      struct snd_pcm_plugin_format *src_format,
			      struct snd_pcm_plugin_format *dst_format,
			      struct snd_pcm_plugin **r_plugin)
{
	int err;
	struct rate_priv *data;
	struct snd_pcm_plugin *plugin;

	if (snd_BUG_ON(!r_plugin))
		return -ENXIO;
	*r_plugin = NULL;

	if (snd_BUG_ON(src_format->channels != dst_format->channels))
		return -ENXIO;
	if (snd_BUG_ON(src_format->channels <= 0))
		return -ENXIO;
	if (snd_BUG_ON(src_format->format != SNDRV_PCM_FORMAT_S16))
		return -ENXIO;
	if (snd_BUG_ON(dst_format->format != SNDRV_PCM_FORMAT_S16))
		return -ENXIO;
	if (snd_BUG_ON(src_format->rate == dst_format->rate))
		return -ENXIO;

	err = snd_pcm_plugin_build(plug, "rate conversion",
				   src_format, dst_format,
				   sizeof(struct rate_priv) +
				   src_format->channels * sizeof(struct rate_channel),
				   &plugin);
	if (err < 0)
		return err;
	data = (struct rate_priv *)plugin->extra_data;
	if (src_format->rate < dst_format->rate) {
		data->pitch = ((src_format->rate << SHIFT) + (dst_format->rate >> 1)) / dst_format->rate;
		data->func = resample_expand;
	} else {
		data->pitch = ((dst_format->rate << SHIFT) + (src_format->rate >> 1)) / src_format->rate;
		data->func = resample_shrink;
	}
	data->pos = 0;
	rate_init(plugin);
	data->old_src_frames = data->old_dst_frames = 0;
	plugin->transfer = rate_transfer;
	plugin->src_frames = rate_src_frames;
	plugin->dst_frames = rate_dst_frames;
	plugin->action = rate_action;
	*r_plugin = plugin;
	return 0;
}


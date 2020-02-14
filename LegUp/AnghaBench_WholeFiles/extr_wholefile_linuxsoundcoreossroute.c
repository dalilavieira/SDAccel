#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_plugin_format {scalar_t__ rate; scalar_t__ format; } ;
struct snd_pcm_plugin_channel {int enabled; int /*<<< orphan*/  area; scalar_t__ wanted; } ;
struct TYPE_4__ {int channels; int /*<<< orphan*/  format; } ;
struct TYPE_3__ {int channels; } ;
struct snd_pcm_plugin {int (* transfer ) (struct snd_pcm_plugin*,struct snd_pcm_plugin_channel const*,struct snd_pcm_plugin_channel*,int) ;TYPE_2__ dst_format; TYPE_1__ src_format; } ;
struct snd_mask {int dummy; } ;
typedef  int snd_pcm_uframes_t ;
typedef  int snd_pcm_sframes_t ;
typedef  int /*<<< orphan*/  snd_pcm_format_t ;

/* Variables and functions */
 int ENXIO ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_pcm_area_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_area_silence (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_pcm_plugin_build (struct snd_pcm_substream*,char*,struct snd_pcm_plugin_format*,struct snd_pcm_plugin_format*,int /*<<< orphan*/ ,struct snd_pcm_plugin**) ; 

__attribute__((used)) static inline snd_pcm_sframes_t snd_pcm_plug_client_size(struct snd_pcm_substream *handle, snd_pcm_uframes_t drv_size) { return drv_size; }

__attribute__((used)) static inline snd_pcm_sframes_t snd_pcm_plug_slave_size(struct snd_pcm_substream *handle, snd_pcm_uframes_t clt_size) { return clt_size; }

__attribute__((used)) static inline int snd_pcm_plug_slave_format(int format, const struct snd_mask *format_mask) { return format; }

__attribute__((used)) static void zero_areas(struct snd_pcm_plugin_channel *dvp, int ndsts,
		       snd_pcm_uframes_t frames, snd_pcm_format_t format)
{
	int dst = 0;
	for (; dst < ndsts; ++dst) {
		if (dvp->wanted)
			snd_pcm_area_silence(&dvp->area, 0, frames, format);
		dvp->enabled = 0;
		dvp++;
	}
}

__attribute__((used)) static inline void copy_area(const struct snd_pcm_plugin_channel *src_channel,
			     struct snd_pcm_plugin_channel *dst_channel,
			     snd_pcm_uframes_t frames, snd_pcm_format_t format)
{
	dst_channel->enabled = 1;
	snd_pcm_area_copy(&src_channel->area, 0, &dst_channel->area, 0, frames, format);
}

__attribute__((used)) static snd_pcm_sframes_t route_transfer(struct snd_pcm_plugin *plugin,
					const struct snd_pcm_plugin_channel *src_channels,
					struct snd_pcm_plugin_channel *dst_channels,
					snd_pcm_uframes_t frames)
{
	int nsrcs, ndsts, dst;
	struct snd_pcm_plugin_channel *dvp;
	snd_pcm_format_t format;

	if (snd_BUG_ON(!plugin || !src_channels || !dst_channels))
		return -ENXIO;
	if (frames == 0)
		return 0;

	nsrcs = plugin->src_format.channels;
	ndsts = plugin->dst_format.channels;

	format = plugin->dst_format.format;
	dvp = dst_channels;
	if (nsrcs <= 1) {
		/* expand to all channels */
		for (dst = 0; dst < ndsts; ++dst) {
			copy_area(src_channels, dvp, frames, format);
			dvp++;
		}
		return frames;
	}

	for (dst = 0; dst < ndsts && dst < nsrcs; ++dst) {
		copy_area(src_channels, dvp, frames, format);
		dvp++;
		src_channels++;
	}
	if (dst < ndsts)
		zero_areas(dvp, ndsts - dst, frames, format);
	return frames;
}

int snd_pcm_plugin_build_route(struct snd_pcm_substream *plug,
			       struct snd_pcm_plugin_format *src_format,
			       struct snd_pcm_plugin_format *dst_format,
			       struct snd_pcm_plugin **r_plugin)
{
	struct snd_pcm_plugin *plugin;
	int err;

	if (snd_BUG_ON(!r_plugin))
		return -ENXIO;
	*r_plugin = NULL;
	if (snd_BUG_ON(src_format->rate != dst_format->rate))
		return -ENXIO;
	if (snd_BUG_ON(src_format->format != dst_format->format))
		return -ENXIO;

	err = snd_pcm_plugin_build(plug, "route conversion",
				   src_format, dst_format, 0, &plugin);
	if (err < 0)
		return err;

	plugin->transfer = route_transfer;
	*r_plugin = plugin;
	return 0;
}


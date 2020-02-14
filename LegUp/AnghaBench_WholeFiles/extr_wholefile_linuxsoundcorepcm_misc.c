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
struct snd_pcm_substream {scalar_t__ stream; int /*<<< orphan*/  runtime; } ;
struct TYPE_4__ {int rates; unsigned int rate_min; unsigned int rate_max; } ;
struct snd_pcm_runtime {TYPE_1__ hw; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;
typedef  scalar_t__ snd_pcm_format_t ;
struct TYPE_6__ {int signd; int le; int width; int phys; unsigned char const* silence; } ;
struct TYPE_5__ {unsigned int count; unsigned int* list; } ;
typedef  scalar_t__ INT ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ SNDRV_PCM_FORMAT_LAST ; 
 unsigned int SNDRV_PCM_RATE_CONTINUOUS ; 
 unsigned int SNDRV_PCM_RATE_KNOT ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  memset (void*,unsigned char,unsigned int) ; 
 TYPE_3__* pcm_formats ; 
 int /*<<< orphan*/  snd_pcm_capture_avail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_capture_hw_avail (int /*<<< orphan*/ ) ; 
 TYPE_2__ snd_pcm_known_rates ; 
 int /*<<< orphan*/  snd_pcm_playback_avail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_playback_hw_avail (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline snd_pcm_uframes_t
snd_pcm_avail(struct snd_pcm_substream *substream)
{
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		return snd_pcm_playback_avail(substream->runtime);
	else
		return snd_pcm_capture_avail(substream->runtime);
}

__attribute__((used)) static inline snd_pcm_uframes_t
snd_pcm_hw_avail(struct snd_pcm_substream *substream)
{
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		return snd_pcm_playback_hw_avail(substream->runtime);
	else
		return snd_pcm_capture_hw_avail(substream->runtime);
}

__attribute__((used)) static inline void
snd_pcm_timer_resolution_change(struct snd_pcm_substream *substream) {}

__attribute__((used)) static inline void snd_pcm_timer_init(struct snd_pcm_substream *substream) {}

__attribute__((used)) static inline void snd_pcm_timer_done(struct snd_pcm_substream *substream) {}

int snd_pcm_format_signed(snd_pcm_format_t format)
{
	int val;
	if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
		return -EINVAL;
	if ((val = pcm_formats[(INT)format].signd) < 0)
		return -EINVAL;
	return val;
}

int snd_pcm_format_unsigned(snd_pcm_format_t format)
{
	int val;

	val = snd_pcm_format_signed(format);
	if (val < 0)
		return val;
	return !val;
}

int snd_pcm_format_linear(snd_pcm_format_t format)
{
	return snd_pcm_format_signed(format) >= 0;
}

int snd_pcm_format_little_endian(snd_pcm_format_t format)
{
	int val;
	if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
		return -EINVAL;
	if ((val = pcm_formats[(INT)format].le) < 0)
		return -EINVAL;
	return val;
}

int snd_pcm_format_big_endian(snd_pcm_format_t format)
{
	int val;

	val = snd_pcm_format_little_endian(format);
	if (val < 0)
		return val;
	return !val;
}

int snd_pcm_format_width(snd_pcm_format_t format)
{
	int val;
	if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
		return -EINVAL;
	if ((val = pcm_formats[(INT)format].width) == 0)
		return -EINVAL;
	return val;
}

int snd_pcm_format_physical_width(snd_pcm_format_t format)
{
	int val;
	if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
		return -EINVAL;
	if ((val = pcm_formats[(INT)format].phys) == 0)
		return -EINVAL;
	return val;
}

ssize_t snd_pcm_format_size(snd_pcm_format_t format, size_t samples)
{
	int phys_width = snd_pcm_format_physical_width(format);
	if (phys_width < 0)
		return -EINVAL;
	return samples * phys_width / 8;
}

const unsigned char *snd_pcm_format_silence_64(snd_pcm_format_t format)
{
	if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
		return NULL;
	if (! pcm_formats[(INT)format].phys)
		return NULL;
	return pcm_formats[(INT)format].silence;
}

int snd_pcm_format_set_silence(snd_pcm_format_t format, void *data, unsigned int samples)
{
	int width;
	unsigned char *dst, *pat;

	if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
		return -EINVAL;
	if (samples == 0)
		return 0;
	width = pcm_formats[(INT)format].phys; /* physical width */
	pat = pcm_formats[(INT)format].silence;
	if (! width)
		return -EINVAL;
	/* signed or 1 byte data */
	if (pcm_formats[(INT)format].signd == 1 || width <= 8) {
		unsigned int bytes = samples * width / 8;
		memset(data, *pat, bytes);
		return 0;
	}
	/* non-zero samples, fill using a loop */
	width /= 8;
	dst = data;
#if 0
	while (samples--) {
		memcpy(dst, pat, width);
		dst += width;
	}
#else
	/* a bit optimization for constant width */
	switch (width) {
	case 2:
		while (samples--) {
			memcpy(dst, pat, 2);
			dst += 2;
		}
		break;
	case 3:
		while (samples--) {
			memcpy(dst, pat, 3);
			dst += 3;
		}
		break;
	case 4:
		while (samples--) {
			memcpy(dst, pat, 4);
			dst += 4;
		}
		break;
	case 8:
		while (samples--) {
			memcpy(dst, pat, 8);
			dst += 8;
		}
		break;
	}
#endif
	return 0;
}

int snd_pcm_limit_hw_rates(struct snd_pcm_runtime *runtime)
{
	int i;
	for (i = 0; i < (int)snd_pcm_known_rates.count; i++) {
		if (runtime->hw.rates & (1 << i)) {
			runtime->hw.rate_min = snd_pcm_known_rates.list[i];
			break;
		}
	}
	for (i = (int)snd_pcm_known_rates.count - 1; i >= 0; i--) {
		if (runtime->hw.rates & (1 << i)) {
			runtime->hw.rate_max = snd_pcm_known_rates.list[i];
			break;
		}
	}
	return 0;
}

unsigned int snd_pcm_rate_to_rate_bit(unsigned int rate)
{
	unsigned int i;

	for (i = 0; i < snd_pcm_known_rates.count; i++)
		if (snd_pcm_known_rates.list[i] == rate)
			return 1u << i;
	return SNDRV_PCM_RATE_KNOT;
}

unsigned int snd_pcm_rate_bit_to_rate(unsigned int rate_bit)
{
	unsigned int i;

	for (i = 0; i < snd_pcm_known_rates.count; i++)
		if ((1u << i) == rate_bit)
			return snd_pcm_known_rates.list[i];
	return 0;
}

__attribute__((used)) static unsigned int snd_pcm_rate_mask_sanitize(unsigned int rates)
{
	if (rates & SNDRV_PCM_RATE_CONTINUOUS)
		return SNDRV_PCM_RATE_CONTINUOUS;
	else if (rates & SNDRV_PCM_RATE_KNOT)
		return SNDRV_PCM_RATE_KNOT;
	return rates;
}

unsigned int snd_pcm_rate_mask_intersect(unsigned int rates_a,
	unsigned int rates_b)
{
	rates_a = snd_pcm_rate_mask_sanitize(rates_a);
	rates_b = snd_pcm_rate_mask_sanitize(rates_b);

	if (rates_a & SNDRV_PCM_RATE_CONTINUOUS)
		return rates_b;
	else if (rates_b & SNDRV_PCM_RATE_CONTINUOUS)
		return rates_a;
	else if (rates_a & SNDRV_PCM_RATE_KNOT)
		return rates_b;
	else if (rates_b & SNDRV_PCM_RATE_KNOT)
		return rates_a;
	return rates_a & rates_b;
}

unsigned int snd_pcm_rate_range_to_bits(unsigned int rate_min,
	unsigned int rate_max)
{
	unsigned int rates = 0;
	int i;

	for (i = 0; i < snd_pcm_known_rates.count; i++) {
		if (snd_pcm_known_rates.list[i] >= rate_min
			&& snd_pcm_known_rates.list[i] <= rate_max)
			rates |= 1 << i;
	}

	if (!rates)
		rates = SNDRV_PCM_RATE_KNOT;

	return rates;
}


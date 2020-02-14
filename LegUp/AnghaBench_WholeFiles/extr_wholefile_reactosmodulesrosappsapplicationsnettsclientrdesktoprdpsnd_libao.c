#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  unsigned int uint16 ;
struct timeval {long tv_sec; long tv_usec; } ;
struct TYPE_11__ {int p; scalar_t__ end; int /*<<< orphan*/  data; int /*<<< orphan*/  size; } ;
struct audio_packet {unsigned int tick; int /*<<< orphan*/  index; TYPE_3__ s; } ;
struct TYPE_9__ {int bits; int channels; int rate; void* byte_format; } ;
typedef  TYPE_1__ ao_sample_format ;
struct TYPE_10__ {scalar_t__ wFormatTag; int nChannels; int wBitsPerSample; int nSamplesPerSec; } ;
typedef  TYPE_2__ WAVEFORMATEX ;
struct TYPE_12__ {int channels; int dsp_bu; scalar_t__ dsp_; } ;
typedef  TYPE_3__* STREAM ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 void* AO_FMT_LITTLE ; 
 int /*<<< orphan*/  DEBUG (char*) ; 
 scalar_t__ False ; 
 size_t MAX_QUEUE ; 
 TYPE_8__* This ; 
 scalar_t__ True ; 
 int WAVEOUTBUF ; 
 scalar_t__ WAVE_FORMAT_PCM ; 
 int abs (int) ; 
 int /*<<< orphan*/  ao_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ao_default_driver_id () ; 
 int /*<<< orphan*/  ao_initialize () ; 
 int /*<<< orphan*/ * ao_open_live (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ao_play (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  ao_shutdown () ; 
 int /*<<< orphan*/  default_driver ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 scalar_t__ g_reopened ; 
 int g_samplerate ; 
 int g_samplewidth ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,scalar_t__,int) ; 
 int /*<<< orphan*/ * o_device ; 
 struct audio_packet* packet_queue ; 
 size_t queue_hi ; 
 size_t queue_lo ; 
 int /*<<< orphan*/  rdpsnd_send_completion (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warning (char*) ; 
 void wave_out_play () ; 

BOOL
wave_out_open(void)
{
	ao_sample_format format;

	ao_initialize();
	default_driver = ao_default_driver_id();

	format.bits = 16;
	format.channels = 2;
	This->channels = 2;
	format.rate = 44100;
	g_samplerate = 44100;
	format.byte_format = AO_FMT_LITTLE;

	o_device = ao_open_live(default_driver, &format, NULL);
	if (o_device == NULL)
	{
		return False;
	}

	This->dsp_ = 0;
	queue_lo = queue_hi = 0;

	g_reopened = True;

	return True;
}

void
wave_out_close(void)
{
	/* Ack all remaining packets */
	while (queue_lo != queue_hi)
	{
		rdpsnd_send_completion(packet_queue[queue_lo].tick, packet_queue[queue_lo].index);
		free(packet_queue[queue_lo].s.data);
		queue_lo = (queue_lo + 1) % MAX_QUEUE;
	}

	if (o_device != NULL)
		ao_close(o_device);

	ao_shutdown();
}

BOOL
wave_out_format_supported(WAVEFORMATEX * pwfx)
{
	if (pwfx->wFormatTag != WAVE_FORMAT_PCM)
		return False;
	if ((pwfx->nChannels != 1) && (pwfx->nChannels != 2))
		return False;
	if ((pwfx->wBitsPerSample != 8) && (pwfx->wBitsPerSample != 16))
		return False;
	/* The only common denominator between libao output drivers is a sample-rate of
	   44100, we need to upsample 22050 to it */
	if ((pwfx->nSamplesPerSec != 44100) && (pwfx->nSamplesPerSec != 22050))
		return False;

	return True;
}

BOOL
wave_out_set_format(WAVEFORMATEX * pwfx)
{
	ao_sample_format format;

	format.bits = pwfx->wBitsPerSample;
	format.channels = pwfx->nChannels;
	This->channels = pwfx->nChannels;
	format.rate = 44100;
	g_samplerate = pwfx->nSamplesPerSec;
	format.byte_format = AO_FMT_LITTLE;

	g_samplewidth = pwfx->wBitsPerSample / 8;

	if (o_device != NULL)
		ao_close(o_device);

	o_device = ao_open_live(default_driver, &format, NULL);
	if (o_device == NULL)
	{
		return False;
	}

	g_reopened = True;

	return True;
}

void
wave_out_volume(uint16 left, uint16 right)
{
	warning("volume changes not supported with libao-output\n");
}

void
wave_out_write(STREAM s, uint16 tick, uint8 index)
{
	struct audio_packet *packet = &packet_queue[queue_hi];
	unsigned int next_hi = (queue_hi + 1) % MAX_QUEUE;

	if (next_hi == queue_lo)
	{
		error("No space to queue audio packet\n");
		return;
	}

	queue_hi = next_hi;

	packet->s = *s;
	packet->tick = tick;
	packet->index = index;
	packet->s.p += 4;

	/* we steal the data buffer from s, give it a new one */
	s->data = malloc(s->size);

	if (!This->dsp_bu)
		wave_out_play();
}

void
wave_out_play(void)
{
	struct audio_packet *packet;
	STREAM out;
	char outbuf[WAVEOUTBUF];
	int offset, len, i;
	static long prev_s, prev_us;
	unsigned int duration;
	struct timeval tv;
	int next_tick;

	if (g_reopened)
	{
		g_reopened = False;
		gettimeofday(&tv, NULL);
		prev_s = tv.tv_sec;
		prev_us = tv.tv_usec;
	}

	if (queue_lo == queue_hi)
	{
		This->dsp_bu = 0;
		return;
	}

	packet = &packet_queue[queue_lo];
	out = &packet->s;

	if (((queue_lo + 1) % MAX_QUEUE) != queue_hi)
	{
		next_tick = packet_queue[(queue_lo + 1) % MAX_QUEUE].tick;
	}
	else
	{
		next_tick = (packet->tick + 65535) % 65536;
	}

	len = 0;

	if (g_samplerate == 22050)
	{
		/* Resample to 44100 */
		for (i = 0; (i < ((WAVEOUTBUF / 4) * (3 - g_samplewidth))) && (out->p < out->end);
		     i++)
		{
			/* On a stereo-channel we must make sure that left and right
			   does not get mixed up, so we need to expand the sample-
			   data with channels in mind: 1234 -> 12123434
			   If we have a mono-channel, we can expand the data by simply
			   doubling the sample-data: 1234 -> 11223344 */
			if (This->channels == 2)
				offset = ((i * 2) - (i & 1)) * g_samplewidth;
			else
				offset = (i * 2) * g_samplewidth;

			memcpy(&outbuf[offset], out->p, g_samplewidth);
			memcpy(&outbuf[This->channels * g_samplewidth + offset], out->p, g_samplewidth);

			out->p += g_samplewidth;
			len += 2 * g_samplewidth;
		}
	}
	else
	{
		len = (WAVEOUTBUF > (out->end - out->p)) ? (out->end - out->p) : WAVEOUTBUF;
		memcpy(outbuf, out->p, len);
		out->p += len;
	}

	ao_play(o_device, outbuf, len);

	gettimeofday(&tv, NULL);

	duration = ((tv.tv_sec - prev_s) * 1000000 + (tv.tv_usec - prev_us)) / 1000;

	if (packet->tick > next_tick)
		next_tick += 65536;

	if ((out->p == out->end) || duration > next_tick - packet->tick + 500)
	{
		prev_s = tv.tv_sec;
		prev_us = tv.tv_usec;

		if (abs((next_tick - packet->tick) - duration) > 20)
		{
			DEBUG(("duration: %d, calc: %d, ", duration, next_tick - packet->tick));
			DEBUG(("last: %d, is: %d, should: %d\n", packet->tick,
			       (packet->tick + duration) % 65536, next_tick % 65536));
		}

		/* Until all drivers are using the windows sound-ticks, we need to
		   substract the 50 ticks added later by rdpsnd.c */
		rdpsnd_send_completion(((packet->tick + duration) % 65536) - 50, packet->index);
		free(out->data);
		queue_lo = (queue_lo + 1) % MAX_QUEUE;
	}

	This->dsp_bu = 1;
	return;
}


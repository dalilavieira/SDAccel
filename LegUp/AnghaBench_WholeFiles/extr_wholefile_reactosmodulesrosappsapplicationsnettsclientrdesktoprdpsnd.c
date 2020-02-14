#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint32 ;
typedef  size_t uint16 ;
struct TYPE_18__ {size_t wFormatTag; size_t nChannels; int nSamplesPerSec; int nAvgBytesPerSec; size_t nBlockAlign; size_t wBitsPerSample; size_t cbSize; int /*<<< orphan*/  cb; } ;
typedef  TYPE_2__ WAVEFORMATEX ;
struct TYPE_17__ {size_t format_count; size_t current_format; int /*<<< orphan*/ * channel; void* device_open; TYPE_2__* formats; } ;
struct TYPE_19__ {TYPE_1__ rdpsnd; } ;
typedef  int /*<<< orphan*/  STREAM ;
typedef  TYPE_3__ RDPCLIENT ;
typedef  void* BOOL ;

/* Variables and functions */
 int CHANNEL_OPTION_ENCRYPT_RDP ; 
 int CHANNEL_OPTION_INITIALIZED ; 
 void* False ; 
 int MAX_CBSIZE ; 
 size_t MAX_FORMATS ; 
#define  RDPSND_CLOSE 132 
 size_t RDPSND_COMPLETION ; 
#define  RDPSND_NEGOTIATE 131 
#define  RDPSND_SERVERTICK 130 
#define  RDPSND_SET_VOLUME 129 
#define  RDPSND_WRITE 128 
 void* True ; 
 int /*<<< orphan*/  channel_init (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * channel_register (TYPE_3__*,char*,int,void (*) (TYPE_3__*,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  channel_send (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  in_uint16_le (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  in_uint32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint32_le (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8a (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in_uint8s (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint16_le (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  out_uint32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint32_le (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint8 (int /*<<< orphan*/ ,int) ; 
 scalar_t__ s_check_rem (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  s_mark_end (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  unimpl (char*,int) ; 
 int /*<<< orphan*/  wave_out_close () ; 
 scalar_t__ wave_out_format_supported (TYPE_2__*) ; 
 scalar_t__ wave_out_open () ; 
 int /*<<< orphan*/  wave_out_set_format (TYPE_2__*) ; 
 int /*<<< orphan*/  wave_out_volume (int,int) ; 
 int /*<<< orphan*/  wave_out_write (int /*<<< orphan*/ ,size_t,int) ; 

__attribute__((used)) static STREAM
rdpsnd_init_packet(RDPCLIENT * This, uint16 type, uint16 size)
{
	STREAM s;

	s = channel_init(This, This->rdpsnd.channel, size + 4);
	out_uint16_le(s, type);
	out_uint16_le(s, size);
	return s;
}

__attribute__((used)) static void
rdpsnd_send(RDPCLIENT * This, STREAM s)
{
#ifdef RDPSND_DEBUG
	printf("RDPSND send:\n");
	hexdump(s->channel_hdr + 8, s->end - s->channel_hdr - 8);
#endif

	channel_send(This, s, This->rdpsnd.channel);
}

void
rdpsnd_send_completion(RDPCLIENT * This, uint16 tick, uint8 packet_index)
{
	STREAM s;

	s = rdpsnd_init_packet(This, RDPSND_COMPLETION, 4);
	out_uint16_le(s, tick + 50);
	out_uint8(s, packet_index);
	out_uint8(s, 0);
	s_mark_end(s);
	rdpsnd_send(This, s);
}

__attribute__((used)) static void
rdpsnd_process_negotiate(RDPCLIENT * This, STREAM in)
{
	unsigned int in_format_count, i;
	WAVEFORMATEX *format;
	STREAM out;
	BOOL device_available = False;
	int readcnt;
	int discardcnt;

	in_uint8s(in, 14);	/* flags, volume, pitch, UDP port */
	in_uint16_le(in, in_format_count);
	in_uint8s(in, 4);	/* pad, status, pad */

	if (wave_out_open())
	{
		wave_out_close();
		device_available = True;
	}

	This->rdpsnd.format_count = 0;
	if (s_check_rem(in, 18 * in_format_count))
	{
		for (i = 0; i < in_format_count; i++)
		{
			format = &This->rdpsnd.formats[This->rdpsnd.format_count];
			in_uint16_le(in, format->wFormatTag);
			in_uint16_le(in, format->nChannels);
			in_uint32_le(in, format->nSamplesPerSec);
			in_uint32_le(in, format->nAvgBytesPerSec);
			in_uint16_le(in, format->nBlockAlign);
			in_uint16_le(in, format->wBitsPerSample);
			in_uint16_le(in, format->cbSize);

			/* read in the buffer of unknown use */
			readcnt = format->cbSize;
			discardcnt = 0;
			if (format->cbSize > MAX_CBSIZE)
			{
				fprintf(stderr, "cbSize too large for buffer: %d\n",
					format->cbSize);
				readcnt = MAX_CBSIZE;
				discardcnt = format->cbSize - MAX_CBSIZE;
			}
			in_uint8a(in, format->cb, readcnt);
			in_uint8s(in, discardcnt);

			if (device_available && wave_out_format_supported(format))
			{
				This->rdpsnd.format_count++;
				if (This->rdpsnd.format_count == MAX_FORMATS)
					break;
			}
		}
	}

	out = rdpsnd_init_packet(This, RDPSND_NEGOTIATE | 0x200, 20 + 18 * This->rdpsnd.format_count);
	out_uint32_le(out, 3);	/* flags */
	out_uint32(out, 0xffffffff);	/* volume */
	out_uint32(out, 0);	/* pitch */
	out_uint16(out, 0);	/* UDP port */

	out_uint16_le(out, This->rdpsnd.format_count);
	out_uint8(out, 0x95);	/* pad? */
	out_uint16_le(out, 2);	/* status */
	out_uint8(out, 0x77);	/* pad? */

	for (i = 0; i < This->rdpsnd.format_count; i++)
	{
		format = &This->rdpsnd.formats[i];
		out_uint16_le(out, format->wFormatTag);
		out_uint16_le(out, format->nChannels);
		out_uint32_le(out, format->nSamplesPerSec);
		out_uint32_le(out, format->nAvgBytesPerSec);
		out_uint16_le(out, format->nBlockAlign);
		out_uint16_le(out, format->wBitsPerSample);
		out_uint16(out, 0);	/* cbSize */
	}

	s_mark_end(out);
	rdpsnd_send(This, out);
}

__attribute__((used)) static void
rdpsnd_process_servertick(RDPCLIENT * This, STREAM in)
{
	uint16 tick1, tick2;
	STREAM out;

	/* in_uint8s(in, 4); unknown */
	in_uint16_le(in, tick1);
	in_uint16_le(in, tick2);

	out = rdpsnd_init_packet(This, RDPSND_SERVERTICK | 0x2300, 4);
	out_uint16_le(out, tick1);
	out_uint16_le(out, tick2);
	s_mark_end(out);
	rdpsnd_send(This, out);
}

__attribute__((used)) static void
rdpsnd_process(RDPCLIENT * This, STREAM s)
{
	uint8 type;
	uint16 datalen;
	uint32 volume;
	static uint16 tick, format;
	static uint8 packet_index;
	static BOOL awaiting_data_packet;

#ifdef RDPSND_DEBUG
	printf("RDPSND recv:\n");
	hexdump(s->p, s->end - s->p);
#endif

	if (awaiting_data_packet)
	{
		if (format >= MAX_FORMATS)
		{
			error("RDPSND: Invalid format index\n");
			return;
		}

		if (!This->rdpsnd.device_open || (format != This->rdpsnd.current_format))
		{
			if (!This->rdpsnd.device_open && !wave_out_open())
			{
				rdpsnd_send_completion(This, tick, packet_index);
				return;
			}
			if (!wave_out_set_format(&This->rdpsnd.formats[format]))
			{
				rdpsnd_send_completion(This, tick, packet_index);
				wave_out_close();
				This->rdpsnd.device_open = False;
				return;
			}
			This->rdpsnd.device_open = True;
			This->rdpsnd.current_format = format;
		}

		wave_out_write(s, tick, packet_index);
		awaiting_data_packet = False;
		return;
	}

	in_uint8(s, type);
	in_uint8s(s, 1);	/* unknown? */
	in_uint16_le(s, datalen);

	switch (type)
	{
		case RDPSND_WRITE:
			in_uint16_le(s, tick);
			in_uint16_le(s, format);
			in_uint8(s, packet_index);
			awaiting_data_packet = True;
			break;
		case RDPSND_CLOSE:
			wave_out_close();
			This->rdpsnd.device_open = False;
			break;
		case RDPSND_NEGOTIATE:
			rdpsnd_process_negotiate(This, s);
			break;
		case RDPSND_SERVERTICK:
			rdpsnd_process_servertick(This, s);
			break;
		case RDPSND_SET_VOLUME:
			in_uint32(s, volume);
			if (This->rdpsnd.device_open)
			{
				wave_out_volume((volume & 0xffff), (volume & 0xffff0000) >> 16);
			}
			break;
		default:
			unimpl("RDPSND packet type %d\n", type);
			break;
	}
}

BOOL
rdpsnd_init(RDPCLIENT * This)
{
	This->rdpsnd.channel =
		channel_register(This, "rdpsnd", CHANNEL_OPTION_INITIALIZED | CHANNEL_OPTION_ENCRYPT_RDP,
				 rdpsnd_process);
	return (This->rdpsnd.channel != NULL);
}


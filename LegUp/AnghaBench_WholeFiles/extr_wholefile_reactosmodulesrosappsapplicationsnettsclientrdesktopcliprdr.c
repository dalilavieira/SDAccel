#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  int uint32 ;
typedef  scalar_t__ uint16 ;
typedef  int /*<<< orphan*/  buffer ;
struct TYPE_33__ {int last_formats_length; int /*<<< orphan*/ * channel; int /*<<< orphan*/ * last_formats; } ;
struct TYPE_35__ {TYPE_1__ cliprdr; } ;
struct TYPE_34__ {int /*<<< orphan*/ * p; } ;
typedef  TYPE_2__* STREAM ;
typedef  TYPE_3__ RDPCLIENT ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int CHANNEL_OPTION_COMPRESS_RDP ; 
 int CHANNEL_OPTION_ENCRYPT_RDP ; 
 int CHANNEL_OPTION_INITIALIZED ; 
 int CHANNEL_OPTION_SHOW_PROTOCOL ; 
#define  CLIPRDR_CONNECT 132 
#define  CLIPRDR_DATA_REQUEST 131 
#define  CLIPRDR_DATA_RESPONSE 130 
 scalar_t__ CLIPRDR_ERROR ; 
#define  CLIPRDR_FORMAT_ACK 129 
#define  CLIPRDR_FORMAT_ANNOUNCE 128 
 scalar_t__ CLIPRDR_REQUEST ; 
 scalar_t__ CLIPRDR_RESPONSE ; 
 int /*<<< orphan*/  DEBUG_CLIPBOARD (char*) ; 
 int /*<<< orphan*/  buf_out_uint32 (int /*<<< orphan*/ *,int) ; 
 TYPE_2__* channel_init (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * channel_register (TYPE_3__*,char*,int,void (*) (TYPE_3__*,TYPE_2__*)) ; 
 int /*<<< orphan*/  channel_send (TYPE_3__*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 void cliprdr_send_native_format_announce (TYPE_3__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  in_uint16_le (TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  in_uint32_le (TYPE_2__*,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint16_le (TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  out_uint32 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint32_le (TYPE_2__*,int) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_2__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_2__*) ; 
 int /*<<< orphan*/  ui_clip_format_announce (TYPE_3__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ui_clip_handle_data (TYPE_3__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ui_clip_request_data (TYPE_3__*,int) ; 
 int /*<<< orphan*/  ui_clip_request_failed (TYPE_3__*) ; 
 int /*<<< orphan*/  ui_clip_set_mode (TYPE_3__*,char const*) ; 
 int /*<<< orphan*/  ui_clip_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  unimpl (char*,scalar_t__) ; 
 int /*<<< orphan*/  xfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * xmalloc (int) ; 

__attribute__((used)) static void
cliprdr_send_packet(RDPCLIENT * This, uint16 type, uint16 status, uint8 * data, uint32 length)
{
	STREAM s;

	DEBUG_CLIPBOARD(("CLIPRDR send: type=%d, status=%d, length=%d\n", type, status, length));

	s = channel_init(This, This->cliprdr.channel, length + 12);
	out_uint16_le(s, type);
	out_uint16_le(s, status);
	out_uint32_le(s, length);
	out_uint8p(s, data, length);
	out_uint32(s, 0);	/* pad? */
	s_mark_end(s);
	channel_send(This, s, This->cliprdr.channel);
}

void
cliprdr_send_simple_native_format_announce(RDPCLIENT * This, uint32 format)
{
	uint8 buffer[36];

	DEBUG_CLIPBOARD(("cliprdr_send_simple_native_format_announce\n"));

	buf_out_uint32(buffer, format);
	memset(buffer + 4, 0, sizeof(buffer) - 4);	/* description */
	cliprdr_send_native_format_announce(This, buffer, sizeof(buffer));
}

void
cliprdr_send_native_format_announce(RDPCLIENT * This, uint8 * formats_data, uint32 formats_data_length)
{
	DEBUG_CLIPBOARD(("cliprdr_send_native_format_announce\n"));

	cliprdr_send_packet(This, CLIPRDR_FORMAT_ANNOUNCE, CLIPRDR_REQUEST, formats_data,
			    formats_data_length);

	if (formats_data != This->cliprdr.last_formats)
	{
		if (This->cliprdr.last_formats)
			xfree(This->cliprdr.last_formats);

		This->cliprdr.last_formats = xmalloc(formats_data_length);
		memcpy(This->cliprdr.last_formats, formats_data, formats_data_length);
		This->cliprdr.last_formats_length = formats_data_length;
	}
}

void
cliprdr_send_data_request(RDPCLIENT * This, uint32 format)
{
	uint8 buffer[4];

	DEBUG_CLIPBOARD(("cliprdr_send_data_request\n"));
	buf_out_uint32(buffer, format);
	cliprdr_send_packet(This, CLIPRDR_DATA_REQUEST, CLIPRDR_REQUEST, buffer, sizeof(buffer));
}

void
cliprdr_send_data(RDPCLIENT * This, uint8 * data, uint32 length)
{
	DEBUG_CLIPBOARD(("cliprdr_send_data\n"));
	cliprdr_send_packet(This, CLIPRDR_DATA_RESPONSE, CLIPRDR_RESPONSE, data, length);
}

__attribute__((used)) static void
cliprdr_process(RDPCLIENT * This, STREAM s)
{
	uint16 type, status;
	uint32 length, format;
	uint8 *data;

	in_uint16_le(s, type);
	in_uint16_le(s, status);
	in_uint32_le(s, length);
	data = s->p;

	DEBUG_CLIPBOARD(("CLIPRDR recv: type=%d, status=%d, length=%d\n", type, status, length));

	if (status == CLIPRDR_ERROR)
	{
		switch (type)
		{
			case CLIPRDR_FORMAT_ACK:
				/* FIXME: We seem to get this when we send an announce while the server is
				   still processing a paste. Try sending another announce. */
				cliprdr_send_native_format_announce(This, This->cliprdr.last_formats,
								    This->cliprdr.last_formats_length);
				break;
			case CLIPRDR_DATA_RESPONSE:
				ui_clip_request_failed(This);
				break;
			default:
				DEBUG_CLIPBOARD(("CLIPRDR error (type=%d)\n", type));
		}

		return;
	}

	switch (type)
	{
		case CLIPRDR_CONNECT:
			ui_clip_sync(This);
			break;
		case CLIPRDR_FORMAT_ANNOUNCE:
			ui_clip_format_announce(This, data, length);
			cliprdr_send_packet(This, CLIPRDR_FORMAT_ACK, CLIPRDR_RESPONSE, NULL, 0);
			return;
		case CLIPRDR_FORMAT_ACK:
			break;
		case CLIPRDR_DATA_REQUEST:
			in_uint32_le(s, format);
			ui_clip_request_data(This, format);
			break;
		case CLIPRDR_DATA_RESPONSE:
			ui_clip_handle_data(This, data, length);
			break;
		case 7:	/* TODO: W2K3 SP1 sends this on connect with a value of 1 */
			break;
		default:
			unimpl("CLIPRDR packet type %d\n", type);
	}
}

void
cliprdr_set_mode(RDPCLIENT * This, const char *optarg)
{
	ui_clip_set_mode(This, optarg);
}

BOOL
cliprdr_init(RDPCLIENT * This)
{
	This->cliprdr.channel =
		channel_register(This, "cliprdr",
				 CHANNEL_OPTION_INITIALIZED | CHANNEL_OPTION_ENCRYPT_RDP |
				 CHANNEL_OPTION_COMPRESS_RDP | CHANNEL_OPTION_SHOW_PROTOCOL,
				 cliprdr_process);
	return (This->cliprdr.channel != NULL);
}


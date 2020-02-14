#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  scalar_t__ uint32 ;
typedef  scalar_t__ uint16 ;
struct TYPE_32__ {scalar_t__ end; scalar_t__ p; scalar_t__ size; int /*<<< orphan*/ * data; } ;
struct TYPE_31__ {scalar_t__ mcs_id; int flags; void (* process ) (TYPE_1__*,STREAM) ;TYPE_3__ in; int /*<<< orphan*/  name; } ;
typedef  TYPE_2__ VCHANNEL ;
struct TYPE_30__ {size_t num_channels; TYPE_2__* channels; scalar_t__ encryption; int /*<<< orphan*/  use_rdp5; } ;
typedef  TYPE_3__* STREAM ;
typedef  TYPE_1__ RDPCLIENT ;
typedef  int /*<<< orphan*/  CHANNEL_PDU_HEADER ;

/* Variables and functions */
 int CHANNEL_CHUNK_LENGTH ; 
 scalar_t__ CHANNEL_FLAG_FIRST ; 
 scalar_t__ CHANNEL_FLAG_LAST ; 
 scalar_t__ CHANNEL_FLAG_SHOW_PROTOCOL ; 
 int CHANNEL_OPTION_SHOW_PROTOCOL ; 
 int /*<<< orphan*/  DEBUG_CHANNEL (char*) ; 
 size_t MAX_CHANNELS ; 
 scalar_t__ MCS_GLOBAL_CHANNEL ; 
 scalar_t__ MIN (scalar_t__,int) ; 
 int /*<<< orphan*/  SEC_ENCRYPT ; 
 int /*<<< orphan*/  channel_hdr ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  in_uint32_le (TYPE_3__*,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  out_uint32_le (TYPE_3__*,scalar_t__) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_3__*,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_3__*) ; 
 int /*<<< orphan*/  s_pop_layer (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s_push_layer (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 TYPE_3__* sec_init (TYPE_1__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  sec_send_to_channel (TYPE_1__*,TYPE_3__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ ,char*,int) ; 
 void stub1 (TYPE_1__*,TYPE_3__*) ; 
 void stub2 (TYPE_1__*,TYPE_3__*) ; 
 scalar_t__ xrealloc (int /*<<< orphan*/ *,scalar_t__) ; 

VCHANNEL *
channel_register(RDPCLIENT * This, char *name, uint32 flags, void (*callback) (RDPCLIENT *, STREAM))
{
	VCHANNEL *channel;

	if (!This->use_rdp5)
		return NULL;

	if (This->num_channels >= MAX_CHANNELS)
	{
		error("Channel table full, increase MAX_CHANNELS\n");
		return NULL;
	}

	channel = &This->channels[This->num_channels];
	channel->mcs_id = MCS_GLOBAL_CHANNEL + 1 + This->num_channels;
	strncpy(channel->name, name, 8);
	channel->flags = flags;
	channel->process = callback;
	This->num_channels++;
	return channel;
}

STREAM
channel_init(RDPCLIENT * This, VCHANNEL * channel, uint32 length)
{
	STREAM s;

	s = sec_init(This, This->encryption ? SEC_ENCRYPT : 0, length + 8);
	s_push_layer(s, channel_hdr, 8);
	return s;
}

void
channel_send(RDPCLIENT * This, STREAM s, VCHANNEL * channel)
{
	uint32 length, flags;
	uint32 thislength, remaining;
	uint8 *data;

	/* first fragment sent in-place */
	s_pop_layer(s, channel_hdr);
	length = s->end - s->p - sizeof(CHANNEL_PDU_HEADER);

	DEBUG_CHANNEL(("channel_send, length = %d\n", length));

	thislength = MIN(length, CHANNEL_CHUNK_LENGTH);
/* Note: In the original clipboard implementation, this number was
   1592, not 1600. However, I don't remember the reason and 1600 seems
   to work so.. This applies only to *this* length, not the length of
   continuation or ending packets. */
	remaining = length - thislength;
	flags = (remaining == 0) ? CHANNEL_FLAG_FIRST | CHANNEL_FLAG_LAST : CHANNEL_FLAG_FIRST;
	if (channel->flags & CHANNEL_OPTION_SHOW_PROTOCOL)
		flags |= CHANNEL_FLAG_SHOW_PROTOCOL;

	out_uint32_le(s, length);
	out_uint32_le(s, flags);
	data = s->end = s->p + thislength;
	DEBUG_CHANNEL(("Sending %d bytes with FLAG_FIRST\n", thislength));
	sec_send_to_channel(This, s, This->encryption ? SEC_ENCRYPT : 0, channel->mcs_id);

	/* subsequent segments copied (otherwise would have to generate headers backwards) */
	while (remaining > 0)
	{
		thislength = MIN(remaining, CHANNEL_CHUNK_LENGTH);
		remaining -= thislength;
		flags = (remaining == 0) ? CHANNEL_FLAG_LAST : 0;
		if (channel->flags & CHANNEL_OPTION_SHOW_PROTOCOL)
			flags |= CHANNEL_FLAG_SHOW_PROTOCOL;

		DEBUG_CHANNEL(("Sending %d bytes with flags %d\n", thislength, flags));

		s = sec_init(This, This->encryption ? SEC_ENCRYPT : 0, thislength + 8);
		out_uint32_le(s, length);
		out_uint32_le(s, flags);
		out_uint8p(s, data, thislength);
		s_mark_end(s);
		sec_send_to_channel(This, s, This->encryption ? SEC_ENCRYPT : 0, channel->mcs_id);

		data += thislength;
	}
}

void
channel_process(RDPCLIENT * This, STREAM s, uint16 mcs_channel)
{
	uint32 length, flags;
	uint32 thislength;
	VCHANNEL *channel = NULL;
	unsigned int i;
	STREAM in;

	for (i = 0; i < This->num_channels; i++)
	{
		channel = &This->channels[i];
		if (channel->mcs_id == mcs_channel)
			break;
	}

	if (i >= This->num_channels)
		return;

	in_uint32_le(s, length);
	in_uint32_le(s, flags);
	if ((flags & CHANNEL_FLAG_FIRST) && (flags & CHANNEL_FLAG_LAST))
	{
		/* single fragment - pass straight up */
		channel->process(This, s);
	}
	else
	{
		/* add fragment to defragmentation buffer */
		in = &channel->in;
		if (flags & CHANNEL_FLAG_FIRST)
		{
			if (length > in->size)
			{
				in->data = (uint8 *) xrealloc(in->data, length);
				in->size = length;
			}
			in->p = in->data;
		}

		thislength = MIN(s->end - s->p, in->data + in->size - in->p);
		memcpy(in->p, s->p, thislength);
		in->p += thislength;

		if (flags & CHANNEL_FLAG_LAST)
		{
			in->end = in->p;
			in->p = in->data;
			channel->process(This, in);
		}
	}
}


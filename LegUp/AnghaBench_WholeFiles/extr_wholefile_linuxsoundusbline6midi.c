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
struct usb_line6 {struct snd_line6_midi* line6midi; TYPE_1__* properties; int /*<<< orphan*/  card; int /*<<< orphan*/  ifcdev; int /*<<< orphan*/  interval; int /*<<< orphan*/  usbdev; int /*<<< orphan*/  max_packet_size; } ;
struct urb {int status; scalar_t__ actual_length; struct snd_line6_midi* transfer_buffer; scalar_t__ context; } ;
struct snd_rawmidi_substream {int dummy; } ;
struct snd_rawmidi {int info_flags; void (* private_free ) (struct snd_rawmidi*) ;struct snd_line6_midi* private_data; int /*<<< orphan*/  name; int /*<<< orphan*/  id; } ;
struct midi_buffer {int dummy; } ;
struct snd_line6_midi {int num_active_send_urbs; struct midi_buffer midibuf_out; struct midi_buffer midibuf_in; struct usb_line6* line6; int /*<<< orphan*/  lock; int /*<<< orphan*/  send_wait; struct snd_rawmidi_substream* substream_receive; struct snd_rawmidi_substream* substream_transmit; } ;
struct TYPE_4__ {struct usb_line6* line6; } ;
struct TYPE_3__ {int capabilities; int /*<<< orphan*/  name; int /*<<< orphan*/  id; int /*<<< orphan*/  ep_ctrl_w; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ESHUTDOWN ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int LINE6_CAP_CONTROL_MIDI ; 
 int LINE6_FALLBACK_MAXPACKETSIZE ; 
 int /*<<< orphan*/  MIDI_BUFFER_SIZE ; 
 int SNDRV_RAWMIDI_INFO_DUPLEX ; 
 int SNDRV_RAWMIDI_INFO_INPUT ; 
 int SNDRV_RAWMIDI_INFO_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_OUTPUT ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct snd_line6_midi*) ; 
 unsigned char* kmemdup (unsigned char*,int,int /*<<< orphan*/ ) ; 
 struct snd_line6_midi* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  line6_midi_input_ops ; 
 int /*<<< orphan*/  line6_midi_output_ops ; 
 int /*<<< orphan*/  line6_midibuf_bytes_free (struct midi_buffer*) ; 
 int /*<<< orphan*/  line6_midibuf_destroy (struct midi_buffer*) ; 
 int line6_midibuf_init (struct midi_buffer*,int /*<<< orphan*/ ,int) ; 
 int line6_midibuf_read (struct midi_buffer*,unsigned char*,int) ; 
 int /*<<< orphan*/  line6_midibuf_write (struct midi_buffer*,unsigned char*,int) ; 
 TYPE_2__* line6_rawmidi_substream_midi (struct snd_rawmidi_substream*) ; 
 int min (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
static  int send_midi_async (struct usb_line6*,unsigned char*,int) ; 
 int snd_rawmidi_new (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int,int,struct snd_rawmidi**) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (struct snd_rawmidi_substream*,unsigned char*,int) ; 
 int /*<<< orphan*/  snd_rawmidi_set_ops (struct snd_rawmidi*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_rawmidi_transmit_ack (struct snd_rawmidi_substream*,int) ; 
 int snd_rawmidi_transmit_peek (struct snd_rawmidi_substream*,unsigned char*,int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct urb* usb_alloc_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_fill_int_urb (struct urb*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int,void (*) (struct urb*),struct usb_line6*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_free_urb (struct urb*) ; 
 int /*<<< orphan*/  usb_sndintpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int usb_submit_urb (struct urb*,int /*<<< orphan*/ ) ; 
 int usb_urb_ep_type_check (struct urb*) ; 
 int /*<<< orphan*/  wait_event_interruptible (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

void line6_midi_receive(struct usb_line6 *line6, unsigned char *data,
			int length)
{
	if (line6->line6midi->substream_receive)
		snd_rawmidi_receive(line6->line6midi->substream_receive,
				    data, length);
}

__attribute__((used)) static void line6_midi_transmit(struct snd_rawmidi_substream *substream)
{
	struct usb_line6 *line6 =
	    line6_rawmidi_substream_midi(substream)->line6;
	struct snd_line6_midi *line6midi = line6->line6midi;
	struct midi_buffer *mb = &line6midi->midibuf_out;
	unsigned char chunk[LINE6_FALLBACK_MAXPACKETSIZE];
	int req, done;

	for (;;) {
		req = min(line6_midibuf_bytes_free(mb), line6->max_packet_size);
		done = snd_rawmidi_transmit_peek(substream, chunk, req);

		if (done == 0)
			break;

		line6_midibuf_write(mb, chunk, done);
		snd_rawmidi_transmit_ack(substream, done);
	}

	for (;;) {
		done = line6_midibuf_read(mb, chunk,
					  LINE6_FALLBACK_MAXPACKETSIZE);

		if (done == 0)
			break;

		send_midi_async(line6, chunk, done);
	}
}

__attribute__((used)) static void midi_sent(struct urb *urb)
{
	unsigned long flags;
	int status;
	int num;
	struct usb_line6 *line6 = (struct usb_line6 *)urb->context;

	status = urb->status;
	kfree(urb->transfer_buffer);
	usb_free_urb(urb);

	if (status == -ESHUTDOWN)
		return;

	spin_lock_irqsave(&line6->line6midi->lock, flags);
	num = --line6->line6midi->num_active_send_urbs;

	if (num == 0) {
		line6_midi_transmit(line6->line6midi->substream_transmit);
		num = line6->line6midi->num_active_send_urbs;
	}

	if (num == 0)
		wake_up(&line6->line6midi->send_wait);

	spin_unlock_irqrestore(&line6->line6midi->lock, flags);
}

__attribute__((used)) static int send_midi_async(struct usb_line6 *line6, unsigned char *data,
			   int length)
{
	struct urb *urb;
	int retval;
	unsigned char *transfer_buffer;

	urb = usb_alloc_urb(0, GFP_ATOMIC);

	if (urb == NULL)
		return -ENOMEM;

	transfer_buffer = kmemdup(data, length, GFP_ATOMIC);

	if (transfer_buffer == NULL) {
		usb_free_urb(urb);
		return -ENOMEM;
	}

	usb_fill_int_urb(urb, line6->usbdev,
			 usb_sndintpipe(line6->usbdev,
					 line6->properties->ep_ctrl_w),
			 transfer_buffer, length, midi_sent, line6,
			 line6->interval);
	urb->actual_length = 0;
	retval = usb_urb_ep_type_check(urb);
	if (retval < 0)
		goto error;

	retval = usb_submit_urb(urb, GFP_ATOMIC);
	if (retval < 0)
		goto error;

	++line6->line6midi->num_active_send_urbs;
	return 0;

 error:
	dev_err(line6->ifcdev, "usb_submit_urb failed\n");
	usb_free_urb(urb);
	return retval;
}

__attribute__((used)) static int line6_midi_output_open(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static int line6_midi_output_close(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static void line6_midi_output_trigger(struct snd_rawmidi_substream *substream,
				      int up)
{
	unsigned long flags;
	struct usb_line6 *line6 =
	    line6_rawmidi_substream_midi(substream)->line6;

	line6->line6midi->substream_transmit = substream;
	spin_lock_irqsave(&line6->line6midi->lock, flags);

	if (line6->line6midi->num_active_send_urbs == 0)
		line6_midi_transmit(substream);

	spin_unlock_irqrestore(&line6->line6midi->lock, flags);
}

__attribute__((used)) static void line6_midi_output_drain(struct snd_rawmidi_substream *substream)
{
	struct usb_line6 *line6 =
	    line6_rawmidi_substream_midi(substream)->line6;
	struct snd_line6_midi *midi = line6->line6midi;

	wait_event_interruptible(midi->send_wait,
				 midi->num_active_send_urbs == 0);
}

__attribute__((used)) static int line6_midi_input_open(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static int line6_midi_input_close(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static void line6_midi_input_trigger(struct snd_rawmidi_substream *substream,
				     int up)
{
	struct usb_line6 *line6 =
	    line6_rawmidi_substream_midi(substream)->line6;

	if (up)
		line6->line6midi->substream_receive = substream;
	else
		line6->line6midi->substream_receive = NULL;
}

__attribute__((used)) static int snd_line6_new_midi(struct usb_line6 *line6,
			      struct snd_rawmidi **rmidi_ret)
{
	struct snd_rawmidi *rmidi;
	int err;

	err = snd_rawmidi_new(line6->card, "Line 6 MIDI", 0, 1, 1, rmidi_ret);
	if (err < 0)
		return err;

	rmidi = *rmidi_ret;
	strcpy(rmidi->id, line6->properties->id);
	strcpy(rmidi->name, line6->properties->name);

	rmidi->info_flags =
	    SNDRV_RAWMIDI_INFO_OUTPUT |
	    SNDRV_RAWMIDI_INFO_INPUT | SNDRV_RAWMIDI_INFO_DUPLEX;

	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT,
			    &line6_midi_output_ops);
	snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT,
			    &line6_midi_input_ops);
	return 0;
}

__attribute__((used)) static void snd_line6_midi_free(struct snd_rawmidi *rmidi)
{
	struct snd_line6_midi *line6midi = rmidi->private_data;

	line6_midibuf_destroy(&line6midi->midibuf_in);
	line6_midibuf_destroy(&line6midi->midibuf_out);
	kfree(line6midi);
}

int line6_init_midi(struct usb_line6 *line6)
{
	int err;
	struct snd_rawmidi *rmidi;
	struct snd_line6_midi *line6midi;

	if (!(line6->properties->capabilities & LINE6_CAP_CONTROL_MIDI)) {
		/* skip MIDI initialization and report success */
		return 0;
	}

	err = snd_line6_new_midi(line6, &rmidi);
	if (err < 0)
		return err;

	line6midi = kzalloc(sizeof(struct snd_line6_midi), GFP_KERNEL);
	if (!line6midi)
		return -ENOMEM;

	rmidi->private_data = line6midi;
	rmidi->private_free = snd_line6_midi_free;

	init_waitqueue_head(&line6midi->send_wait);
	spin_lock_init(&line6midi->lock);
	line6midi->line6 = line6;

	err = line6_midibuf_init(&line6midi->midibuf_in, MIDI_BUFFER_SIZE, 0);
	if (err < 0)
		return err;

	err = line6_midibuf_init(&line6midi->midibuf_out, MIDI_BUFFER_SIZE, 1);
	if (err < 0)
		return err;

	line6->line6midi = line6midi;
	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct urb {scalar_t__ status; struct snd_usb_caiaqdev* context; } ;
struct TYPE_8__ {scalar_t__ num_midi_out; scalar_t__ num_midi_in; } ;
struct TYPE_7__ {int /*<<< orphan*/  card; } ;
struct TYPE_9__ {int transfer_buffer_length; } ;
struct snd_usb_caiaqdev {int midi_out_active; int* midi_out_buf; struct snd_rawmidi_substream* midi_out_substream; struct snd_rawmidi* rmidi; TYPE_3__ spec; int /*<<< orphan*/  product_name; TYPE_2__ chip; struct snd_rawmidi_substream* midi_receive_substream; TYPE_4__ midi_out_urb; } ;
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct snd_rawmidi {int /*<<< orphan*/  info_flags; struct snd_usb_caiaqdev* private_data; int /*<<< orphan*/  name; } ;
struct device {int dummy; } ;
struct TYPE_6__ {struct snd_usb_caiaqdev* private_data; } ;

/* Variables and functions */
 scalar_t__ EP1_BUFSIZE ; 
 int EP1_CMD_MIDI_WRITE ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_INFO_DUPLEX ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_INFO_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_INFO_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_STREAM_OUTPUT ; 
 struct device* caiaqdev_to_dev (struct snd_usb_caiaqdev*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,struct snd_rawmidi_substream*,int,int) ; 
 int snd_rawmidi_new (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,scalar_t__,struct snd_rawmidi**) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (struct snd_rawmidi_substream*,char const*,int) ; 
 int /*<<< orphan*/  snd_rawmidi_set_ops (struct snd_rawmidi*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_rawmidi_transmit (struct snd_rawmidi_substream*,int*,scalar_t__) ; 
 int /*<<< orphan*/  snd_usb_caiaq_midi_input ; 
 int /*<<< orphan*/  snd_usb_caiaq_midi_output ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usb_kill_urb (TYPE_4__*) ; 
 int usb_submit_urb (TYPE_4__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_usb_caiaq_midi_input_open(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static int snd_usb_caiaq_midi_input_close(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static void snd_usb_caiaq_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_usb_caiaqdev *cdev = substream->rmidi->private_data;

	if (!cdev)
		return;

	cdev->midi_receive_substream = up ? substream : NULL;
}

__attribute__((used)) static int snd_usb_caiaq_midi_output_open(struct snd_rawmidi_substream *substream)
{
	return 0;
}

__attribute__((used)) static int snd_usb_caiaq_midi_output_close(struct snd_rawmidi_substream *substream)
{
	struct snd_usb_caiaqdev *cdev = substream->rmidi->private_data;
	if (cdev->midi_out_active) {
		usb_kill_urb(&cdev->midi_out_urb);
		cdev->midi_out_active = 0;
	}
	return 0;
}

__attribute__((used)) static void snd_usb_caiaq_midi_send(struct snd_usb_caiaqdev *cdev,
				    struct snd_rawmidi_substream *substream)
{
	int len, ret;
	struct device *dev = caiaqdev_to_dev(cdev);

	cdev->midi_out_buf[0] = EP1_CMD_MIDI_WRITE;
	cdev->midi_out_buf[1] = 0; /* port */
	len = snd_rawmidi_transmit(substream, cdev->midi_out_buf + 3,
				   EP1_BUFSIZE - 3);

	if (len <= 0)
		return;

	cdev->midi_out_buf[2] = len;
	cdev->midi_out_urb.transfer_buffer_length = len+3;

	ret = usb_submit_urb(&cdev->midi_out_urb, GFP_ATOMIC);
	if (ret < 0)
		dev_err(dev,
			"snd_usb_caiaq_midi_send(%p): usb_submit_urb() failed,"
			"ret=%d, len=%d\n", substream, ret, len);
	else
		cdev->midi_out_active = 1;
}

__attribute__((used)) static void snd_usb_caiaq_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_usb_caiaqdev *cdev = substream->rmidi->private_data;

	if (up) {
		cdev->midi_out_substream = substream;
		if (!cdev->midi_out_active)
			snd_usb_caiaq_midi_send(cdev, substream);
	} else {
		cdev->midi_out_substream = NULL;
	}
}

void snd_usb_caiaq_midi_handle_input(struct snd_usb_caiaqdev *cdev,
				     int port, const char *buf, int len)
{
	if (!cdev->midi_receive_substream)
		return;

	snd_rawmidi_receive(cdev->midi_receive_substream, buf, len);
}

int snd_usb_caiaq_midi_init(struct snd_usb_caiaqdev *device)
{
	int ret;
	struct snd_rawmidi *rmidi;

	ret = snd_rawmidi_new(device->chip.card, device->product_name, 0,
					device->spec.num_midi_out,
					device->spec.num_midi_in,
					&rmidi);

	if (ret < 0)
		return ret;

	strlcpy(rmidi->name, device->product_name, sizeof(rmidi->name));

	rmidi->info_flags = SNDRV_RAWMIDI_INFO_DUPLEX;
	rmidi->private_data = device;

	if (device->spec.num_midi_out > 0) {
		rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT;
		snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT,
				    &snd_usb_caiaq_midi_output);
	}

	if (device->spec.num_midi_in > 0) {
		rmidi->info_flags |= SNDRV_RAWMIDI_INFO_INPUT;
		snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT,
				    &snd_usb_caiaq_midi_input);
	}

	device->rmidi = rmidi;

	return 0;
}

void snd_usb_caiaq_midi_output_done(struct urb* urb)
{
	struct snd_usb_caiaqdev *cdev = urb->context;

	cdev->midi_out_active = 0;
	if (urb->status != 0)
		return;

	if (!cdev->midi_out_substream)
		return;

	snd_usb_caiaq_midi_send(cdev, cdev->midi_out_substream);
}


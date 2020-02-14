#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_seq_port_subscribe {int dummy; } ;
struct TYPE_10__ {scalar_t__ client; int port; } ;
struct TYPE_11__ {struct snd_rawmidi_substream* output; struct snd_rawmidi_substream* input; } ;
struct TYPE_8__ {int /*<<< orphan*/  client; } ;
struct TYPE_7__ {int port; } ;
struct snd_seq_port_info {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct snd_seq_port_info** ports; TYPE_4__ addr; struct snd_seq_port_info* kernel; struct snd_seq_port_info* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct snd_seq_port_callback {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct snd_seq_port_callback** ports; TYPE_4__ addr; struct snd_seq_port_callback* kernel; struct snd_seq_port_callback* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct snd_seq_event {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct snd_seq_event** ports; TYPE_4__ addr; struct snd_seq_event* kernel; struct snd_seq_event* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct snd_seq_device {int device; struct snd_card* card; struct snd_rawmidi* private_data; } ;
struct snd_rawmidi_substream {struct snd_rawmidi_runtime* runtime; } ;
struct snd_rawmidi_runtime {scalar_t__ avail; void (* event ) (struct snd_rawmidi_substream*) ;struct snd_seq_port_info* private_data; } ;
struct snd_rawmidi_params {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct snd_rawmidi_params** ports; TYPE_4__ addr; struct snd_rawmidi_params* kernel; struct snd_rawmidi_params* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct snd_rawmidi_info {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct snd_rawmidi_info** ports; TYPE_4__ addr; struct snd_rawmidi_info* kernel; struct snd_rawmidi_info* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct snd_rawmidi {TYPE_3__* ops; } ;
struct snd_card {size_t number; scalar_t__* shortname; } ;
struct seq_midisynth_client {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct seq_midisynth_client** ports; TYPE_4__ addr; struct seq_midisynth_client* kernel; struct seq_midisynth_client* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct seq_midisynth {int seq_port; scalar_t__ seq_client; scalar_t__ type; int flags; int device; int subdevice; int avail_min; int no_active_sensing; unsigned int subdevices_count; char* name; int capability; int midi_channels; int (* subscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* unsubscribe ) (void*,struct snd_seq_port_subscribe*) ;int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_port_info*,int,void*,int,int) ;unsigned int* ports_per_device; scalar_t__ num_ports; struct seq_midisynth** ports; TYPE_4__ addr; struct seq_midisynth* kernel; struct seq_midisynth* private_data; int /*<<< orphan*/  owner; int /*<<< orphan*/  subname; void* stream; int /*<<< orphan*/ * parser; TYPE_5__ output_rfile; int /*<<< orphan*/  buffer_size; struct snd_card* card; TYPE_5__ input_rfile; TYPE_2__ dest; TYPE_1__ source; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  snd_seq_dump_func_t ;
typedef  int /*<<< orphan*/  pcallbacks ;
typedef  int /*<<< orphan*/  params ;
typedef  int /*<<< orphan*/  msg ;
typedef  int /*<<< orphan*/  ev ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_9__ {int /*<<< orphan*/  (* get_port_info ) (struct snd_rawmidi*,unsigned int,struct snd_seq_port_info*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MAX_MIDI_EVENT_BUF ; 
 int SNDRV_RAWMIDI_DEVICES ; 
 int SNDRV_RAWMIDI_INFO_DUPLEX ; 
 int SNDRV_RAWMIDI_INFO_INPUT ; 
 int SNDRV_RAWMIDI_INFO_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_LFLG_INPUT ; 
 int /*<<< orphan*/  SNDRV_RAWMIDI_LFLG_OUTPUT ; 
 void* SNDRV_RAWMIDI_STREAM_INPUT ; 
 void* SNDRV_RAWMIDI_STREAM_OUTPUT ; 
 int /*<<< orphan*/  SNDRV_SEQ_ADDRESS_SUBSCRIBERS ; 
 int SNDRV_SEQ_EVENT_LENGTH_MASK ; 
 int SNDRV_SEQ_EVENT_LENGTH_VARIABLE ; 
 scalar_t__ SNDRV_SEQ_EVENT_SYSEX ; 
 int /*<<< orphan*/  SNDRV_SEQ_IOCTL_CREATE_PORT ; 
 int SNDRV_SEQ_PORT_CAP_DUPLEX ; 
 int SNDRV_SEQ_PORT_CAP_READ ; 
 int SNDRV_SEQ_PORT_CAP_SUBS_READ ; 
 int SNDRV_SEQ_PORT_CAP_SUBS_WRITE ; 
 int SNDRV_SEQ_PORT_CAP_SYNC_READ ; 
 int SNDRV_SEQ_PORT_CAP_SYNC_WRITE ; 
 int SNDRV_SEQ_PORT_CAP_WRITE ; 
 int SNDRV_SEQ_PORT_FLG_GIVEN_PORT ; 
 int SNDRV_SEQ_PORT_TYPE_HARDWARE ; 
 int SNDRV_SEQ_PORT_TYPE_MIDI_GENERIC ; 
 int SNDRV_SEQ_PORT_TYPE_PORT ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  input_buffer_size ; 
 struct snd_seq_port_info* kcalloc (unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct snd_seq_port_info*) ; 
 struct snd_seq_port_info* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct snd_seq_port_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct snd_seq_port_info*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  output_buffer_size ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 scalar_t__ printk_ratelimit () ; 
 int /*<<< orphan*/  register_mutex ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int snd_midi_event_decode (int /*<<< orphan*/ *,unsigned char*,int,struct snd_seq_port_info*) ; 
 int /*<<< orphan*/  snd_midi_event_encode_byte (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct snd_seq_port_info*) ; 
 int /*<<< orphan*/  snd_midi_event_free (int /*<<< orphan*/ *) ; 
 scalar_t__ snd_midi_event_new (int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  snd_midi_event_reset_decode (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_midi_event_reset_encode (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_rawmidi_drain_output (struct snd_rawmidi_substream*) ; 
 scalar_t__ snd_rawmidi_info_select (struct snd_card*,struct snd_seq_port_info*) ; 
 int snd_rawmidi_input_params (struct snd_rawmidi_substream*,struct snd_seq_port_info*) ; 
 int snd_rawmidi_kernel_open (struct snd_card*,int,int,int /*<<< orphan*/ ,TYPE_5__*) ; 
 long snd_rawmidi_kernel_read (struct snd_rawmidi_substream*,char*,int) ; 
 int snd_rawmidi_kernel_release (TYPE_5__*) ; 
 int snd_rawmidi_kernel_write (struct snd_rawmidi_substream*,char const*,int) ; 
 int snd_rawmidi_output_params (struct snd_rawmidi_substream*,struct snd_seq_port_info*) ; 
 scalar_t__ snd_seq_create_kernel_client (struct snd_card*,int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  snd_seq_delete_kernel_client (scalar_t__) ; 
 int /*<<< orphan*/  snd_seq_dump_var_event (struct snd_seq_port_info*,int /*<<< orphan*/ ,struct snd_rawmidi_substream*) ; 
 int /*<<< orphan*/  snd_seq_event_port_detach (scalar_t__,int) ; 
 scalar_t__ snd_seq_kernel_client_ctl (scalar_t__,int /*<<< orphan*/ ,struct snd_seq_port_info*) ; 
 int /*<<< orphan*/  snd_seq_kernel_client_dispatch (scalar_t__,struct snd_seq_port_info*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,...) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int,...) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct snd_rawmidi*,unsigned int,struct snd_seq_port_info*) ; 
 struct snd_seq_port_info** synths ; 
 struct snd_seq_device* to_seq_dev (struct device*) ; 

__attribute__((used)) static void snd_midi_input_event(struct snd_rawmidi_substream *substream)
{
	struct snd_rawmidi_runtime *runtime;
	struct seq_midisynth *msynth;
	struct snd_seq_event ev;
	char buf[16], *pbuf;
	long res;

	if (substream == NULL)
		return;
	runtime = substream->runtime;
	msynth = runtime->private_data;
	if (msynth == NULL)
		return;
	memset(&ev, 0, sizeof(ev));
	while (runtime->avail > 0) {
		res = snd_rawmidi_kernel_read(substream, buf, sizeof(buf));
		if (res <= 0)
			continue;
		if (msynth->parser == NULL)
			continue;
		pbuf = buf;
		while (res-- > 0) {
			if (!snd_midi_event_encode_byte(msynth->parser,
							*pbuf++, &ev))
				continue;
			ev.source.port = msynth->seq_port;
			ev.dest.client = SNDRV_SEQ_ADDRESS_SUBSCRIBERS;
			snd_seq_kernel_client_dispatch(msynth->seq_client, &ev, 1, 0);
			/* clear event and reset header */
			memset(&ev, 0, sizeof(ev));
		}
	}
}

__attribute__((used)) static int dump_midi(struct snd_rawmidi_substream *substream, const char *buf, int count)
{
	struct snd_rawmidi_runtime *runtime;
	int tmp;

	if (snd_BUG_ON(!substream || !buf))
		return -EINVAL;
	runtime = substream->runtime;
	if ((tmp = runtime->avail) < count) {
		if (printk_ratelimit())
			pr_err("ALSA: seq_midi: MIDI output buffer overrun\n");
		return -ENOMEM;
	}
	if (snd_rawmidi_kernel_write(substream, buf, count) < count)
		return -EINVAL;
	return 0;
}

__attribute__((used)) static int event_process_midi(struct snd_seq_event *ev, int direct,
			      void *private_data, int atomic, int hop)
{
	struct seq_midisynth *msynth = private_data;
	unsigned char msg[10];	/* buffer for constructing midi messages */
	struct snd_rawmidi_substream *substream;
	int len;

	if (snd_BUG_ON(!msynth))
		return -EINVAL;
	substream = msynth->output_rfile.output;
	if (substream == NULL)
		return -ENODEV;
	if (ev->type == SNDRV_SEQ_EVENT_SYSEX) {	/* special case, to save space */
		if ((ev->flags & SNDRV_SEQ_EVENT_LENGTH_MASK) != SNDRV_SEQ_EVENT_LENGTH_VARIABLE) {
			/* invalid event */
			pr_debug("ALSA: seq_midi: invalid sysex event flags = 0x%x\n", ev->flags);
			return 0;
		}
		snd_seq_dump_var_event(ev, (snd_seq_dump_func_t)dump_midi, substream);
		snd_midi_event_reset_decode(msynth->parser);
	} else {
		if (msynth->parser == NULL)
			return -EIO;
		len = snd_midi_event_decode(msynth->parser, msg, sizeof(msg), ev);
		if (len < 0)
			return 0;
		if (dump_midi(substream, msg, len) < 0)
			snd_midi_event_reset_decode(msynth->parser);
	}
	return 0;
}

__attribute__((used)) static int snd_seq_midisynth_new(struct seq_midisynth *msynth,
				 struct snd_card *card,
				 int device,
				 int subdevice)
{
	if (snd_midi_event_new(MAX_MIDI_EVENT_BUF, &msynth->parser) < 0)
		return -ENOMEM;
	msynth->card = card;
	msynth->device = device;
	msynth->subdevice = subdevice;
	return 0;
}

__attribute__((used)) static int midisynth_subscribe(void *private_data, struct snd_seq_port_subscribe *info)
{
	int err;
	struct seq_midisynth *msynth = private_data;
	struct snd_rawmidi_runtime *runtime;
	struct snd_rawmidi_params params;

	/* open midi port */
	if ((err = snd_rawmidi_kernel_open(msynth->card, msynth->device,
					   msynth->subdevice,
					   SNDRV_RAWMIDI_LFLG_INPUT,
					   &msynth->input_rfile)) < 0) {
		pr_debug("ALSA: seq_midi: midi input open failed!!!\n");
		return err;
	}
	runtime = msynth->input_rfile.input->runtime;
	memset(&params, 0, sizeof(params));
	params.avail_min = 1;
	params.buffer_size = input_buffer_size;
	if ((err = snd_rawmidi_input_params(msynth->input_rfile.input, &params)) < 0) {
		snd_rawmidi_kernel_release(&msynth->input_rfile);
		return err;
	}
	snd_midi_event_reset_encode(msynth->parser);
	runtime->event = snd_midi_input_event;
	runtime->private_data = msynth;
	snd_rawmidi_kernel_read(msynth->input_rfile.input, NULL, 0);
	return 0;
}

__attribute__((used)) static int midisynth_unsubscribe(void *private_data, struct snd_seq_port_subscribe *info)
{
	int err;
	struct seq_midisynth *msynth = private_data;

	if (snd_BUG_ON(!msynth->input_rfile.input))
		return -EINVAL;
	err = snd_rawmidi_kernel_release(&msynth->input_rfile);
	return err;
}

__attribute__((used)) static int midisynth_use(void *private_data, struct snd_seq_port_subscribe *info)
{
	int err;
	struct seq_midisynth *msynth = private_data;
	struct snd_rawmidi_params params;

	/* open midi port */
	if ((err = snd_rawmidi_kernel_open(msynth->card, msynth->device,
					   msynth->subdevice,
					   SNDRV_RAWMIDI_LFLG_OUTPUT,
					   &msynth->output_rfile)) < 0) {
		pr_debug("ALSA: seq_midi: midi output open failed!!!\n");
		return err;
	}
	memset(&params, 0, sizeof(params));
	params.avail_min = 1;
	params.buffer_size = output_buffer_size;
	params.no_active_sensing = 1;
	if ((err = snd_rawmidi_output_params(msynth->output_rfile.output, &params)) < 0) {
		snd_rawmidi_kernel_release(&msynth->output_rfile);
		return err;
	}
	snd_midi_event_reset_decode(msynth->parser);
	return 0;
}

__attribute__((used)) static int midisynth_unuse(void *private_data, struct snd_seq_port_subscribe *info)
{
	struct seq_midisynth *msynth = private_data;

	if (snd_BUG_ON(!msynth->output_rfile.output))
		return -EINVAL;
	snd_rawmidi_drain_output(msynth->output_rfile.output);
	return snd_rawmidi_kernel_release(&msynth->output_rfile);
}

__attribute__((used)) static void snd_seq_midisynth_delete(struct seq_midisynth *msynth)
{
	if (msynth == NULL)
		return;

	if (msynth->seq_client > 0) {
		/* delete port */
		snd_seq_event_port_detach(msynth->seq_client, msynth->seq_port);
	}

	snd_midi_event_free(msynth->parser);
}

__attribute__((used)) static int
snd_seq_midisynth_probe(struct device *_dev)
{
	struct snd_seq_device *dev = to_seq_dev(_dev);
	struct seq_midisynth_client *client;
	struct seq_midisynth *msynth, *ms;
	struct snd_seq_port_info *port;
	struct snd_rawmidi_info *info;
	struct snd_rawmidi *rmidi = dev->private_data;
	int newclient = 0;
	unsigned int p, ports;
	struct snd_seq_port_callback pcallbacks;
	struct snd_card *card = dev->card;
	int device = dev->device;
	unsigned int input_count = 0, output_count = 0;

	if (snd_BUG_ON(!card || device < 0 || device >= SNDRV_RAWMIDI_DEVICES))
		return -EINVAL;
	info = kmalloc(sizeof(*info), GFP_KERNEL);
	if (! info)
		return -ENOMEM;
	info->device = device;
	info->stream = SNDRV_RAWMIDI_STREAM_OUTPUT;
	info->subdevice = 0;
	if (snd_rawmidi_info_select(card, info) >= 0)
		output_count = info->subdevices_count;
	info->stream = SNDRV_RAWMIDI_STREAM_INPUT;
	if (snd_rawmidi_info_select(card, info) >= 0) {
		input_count = info->subdevices_count;
	}
	ports = output_count;
	if (ports < input_count)
		ports = input_count;
	if (ports == 0) {
		kfree(info);
		return -ENODEV;
	}
	if (ports > (256 / SNDRV_RAWMIDI_DEVICES))
		ports = 256 / SNDRV_RAWMIDI_DEVICES;

	mutex_lock(&register_mutex);
	client = synths[card->number];
	if (client == NULL) {
		newclient = 1;
		client = kzalloc(sizeof(*client), GFP_KERNEL);
		if (client == NULL) {
			mutex_unlock(&register_mutex);
			kfree(info);
			return -ENOMEM;
		}
		client->seq_client =
			snd_seq_create_kernel_client(
				card, 0, "%s", card->shortname[0] ?
				(const char *)card->shortname : "External MIDI");
		if (client->seq_client < 0) {
			kfree(client);
			mutex_unlock(&register_mutex);
			kfree(info);
			return -ENOMEM;
		}
	}

	msynth = kcalloc(ports, sizeof(struct seq_midisynth), GFP_KERNEL);
	port = kmalloc(sizeof(*port), GFP_KERNEL);
	if (msynth == NULL || port == NULL)
		goto __nomem;

	for (p = 0; p < ports; p++) {
		ms = &msynth[p];

		if (snd_seq_midisynth_new(ms, card, device, p) < 0)
			goto __nomem;

		/* declare port */
		memset(port, 0, sizeof(*port));
		port->addr.client = client->seq_client;
		port->addr.port = device * (256 / SNDRV_RAWMIDI_DEVICES) + p;
		port->flags = SNDRV_SEQ_PORT_FLG_GIVEN_PORT;
		memset(info, 0, sizeof(*info));
		info->device = device;
		if (p < output_count)
			info->stream = SNDRV_RAWMIDI_STREAM_OUTPUT;
		else
			info->stream = SNDRV_RAWMIDI_STREAM_INPUT;
		info->subdevice = p;
		if (snd_rawmidi_info_select(card, info) >= 0)
			strcpy(port->name, info->subname);
		if (! port->name[0]) {
			if (info->name[0]) {
				if (ports > 1)
					snprintf(port->name, sizeof(port->name), "%s-%u", info->name, p);
				else
					snprintf(port->name, sizeof(port->name), "%s", info->name);
			} else {
				/* last resort */
				if (ports > 1)
					sprintf(port->name, "MIDI %d-%d-%u", card->number, device, p);
				else
					sprintf(port->name, "MIDI %d-%d", card->number, device);
			}
		}
		if ((info->flags & SNDRV_RAWMIDI_INFO_OUTPUT) && p < output_count)
			port->capability |= SNDRV_SEQ_PORT_CAP_WRITE | SNDRV_SEQ_PORT_CAP_SYNC_WRITE | SNDRV_SEQ_PORT_CAP_SUBS_WRITE;
		if ((info->flags & SNDRV_RAWMIDI_INFO_INPUT) && p < input_count)
			port->capability |= SNDRV_SEQ_PORT_CAP_READ | SNDRV_SEQ_PORT_CAP_SYNC_READ | SNDRV_SEQ_PORT_CAP_SUBS_READ;
		if ((port->capability & (SNDRV_SEQ_PORT_CAP_WRITE|SNDRV_SEQ_PORT_CAP_READ)) == (SNDRV_SEQ_PORT_CAP_WRITE|SNDRV_SEQ_PORT_CAP_READ) &&
		    info->flags & SNDRV_RAWMIDI_INFO_DUPLEX)
			port->capability |= SNDRV_SEQ_PORT_CAP_DUPLEX;
		port->type = SNDRV_SEQ_PORT_TYPE_MIDI_GENERIC
			| SNDRV_SEQ_PORT_TYPE_HARDWARE
			| SNDRV_SEQ_PORT_TYPE_PORT;
		port->midi_channels = 16;
		memset(&pcallbacks, 0, sizeof(pcallbacks));
		pcallbacks.owner = THIS_MODULE;
		pcallbacks.private_data = ms;
		pcallbacks.subscribe = midisynth_subscribe;
		pcallbacks.unsubscribe = midisynth_unsubscribe;
		pcallbacks.use = midisynth_use;
		pcallbacks.unuse = midisynth_unuse;
		pcallbacks.event_input = event_process_midi;
		port->kernel = &pcallbacks;
		if (rmidi->ops && rmidi->ops->get_port_info)
			rmidi->ops->get_port_info(rmidi, p, port);
		if (snd_seq_kernel_client_ctl(client->seq_client, SNDRV_SEQ_IOCTL_CREATE_PORT, port)<0)
			goto __nomem;
		ms->seq_client = client->seq_client;
		ms->seq_port = port->addr.port;
	}
	client->ports_per_device[device] = ports;
	client->ports[device] = msynth;
	client->num_ports++;
	if (newclient)
		synths[card->number] = client;
	mutex_unlock(&register_mutex);
	kfree(info);
	kfree(port);
	return 0;	/* success */

      __nomem:
	if (msynth != NULL) {
	      	for (p = 0; p < ports; p++)
	      		snd_seq_midisynth_delete(&msynth[p]);
		kfree(msynth);
	}
	if (newclient) {
		snd_seq_delete_kernel_client(client->seq_client);
		kfree(client);
	}
	kfree(info);
	kfree(port);
	mutex_unlock(&register_mutex);
	return -ENOMEM;
}

__attribute__((used)) static int
snd_seq_midisynth_remove(struct device *_dev)
{
	struct snd_seq_device *dev = to_seq_dev(_dev);
	struct seq_midisynth_client *client;
	struct seq_midisynth *msynth;
	struct snd_card *card = dev->card;
	int device = dev->device, p, ports;
	
	mutex_lock(&register_mutex);
	client = synths[card->number];
	if (client == NULL || client->ports[device] == NULL) {
		mutex_unlock(&register_mutex);
		return -ENODEV;
	}
	ports = client->ports_per_device[device];
	client->ports_per_device[device] = 0;
	msynth = client->ports[device];
	client->ports[device] = NULL;
	for (p = 0; p < ports; p++)
		snd_seq_midisynth_delete(&msynth[p]);
	kfree(msynth);
	client->num_ports--;
	if (client->num_ports <= 0) {
		snd_seq_delete_kernel_client(client->seq_client);
		synths[card->number] = NULL;
		kfree(client);
	}
	mutex_unlock(&register_mutex);
	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ client; } ;
struct snd_seq_port_subscribe {TYPE_1__ sender; } ;
struct snd_seq_port_callback {int (* use ) (void*,struct snd_seq_port_subscribe*) ;int (* unuse ) (void*,struct snd_seq_port_subscribe*) ;int (* event_input ) (struct snd_seq_event*,int,void*,int,int) ;void (* private_free ) (void*) ;struct snd_opl4* private_data; int /*<<< orphan*/  owner; } ;
struct snd_seq_event {int dummy; } ;
struct snd_seq_device {int dummy; } ;
struct snd_opl4 {int seq_client; TYPE_3__* chset; int /*<<< orphan*/  seq_dev_num; TYPE_2__* card; int /*<<< orphan*/  access_mutex; scalar_t__ used; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  pcallbacks ;
struct TYPE_8__ {int client; int port; struct snd_opl4* private_data; } ;
struct TYPE_7__ {int /*<<< orphan*/  module; } ;

/* Variables and functions */
 int EBUSY ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ SNDRV_SEQ_CLIENT_SYSTEM ; 
 scalar_t__ SNDRV_SEQ_DEVICE_ARGPTR (struct snd_seq_device*) ; 
 int SNDRV_SEQ_PORT_CAP_SUBS_WRITE ; 
 int SNDRV_SEQ_PORT_CAP_WRITE ; 
 int SNDRV_SEQ_PORT_TYPE_HARDWARE ; 
 int SNDRV_SEQ_PORT_TYPE_MIDI_GENERIC ; 
 int SNDRV_SEQ_PORT_TYPE_MIDI_GM ; 
 int SNDRV_SEQ_PORT_TYPE_SYNTHESIZER ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  memset (struct snd_seq_port_callback*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opl4_ops ; 
 TYPE_3__* snd_midi_channel_alloc_set (int) ; 
 int /*<<< orphan*/  snd_midi_channel_free_set (TYPE_3__*) ; 
 int /*<<< orphan*/  snd_midi_process_event (int /*<<< orphan*/ *,struct snd_seq_event*,TYPE_3__*) ; 
 int /*<<< orphan*/  snd_opl4_synth_reset (struct snd_opl4*) ; 
 int /*<<< orphan*/  snd_opl4_synth_shutdown (struct snd_opl4*) ; 
 int snd_seq_create_kernel_client (TYPE_2__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  snd_seq_delete_kernel_client (int) ; 
 int snd_seq_event_port_attach (int,struct snd_seq_port_callback*,int,int,int,int,char*) ; 
 scalar_t__ snd_yrw801_detect (struct snd_opl4*) ; 
 struct snd_seq_device* to_seq_dev (struct device*) ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int snd_opl4_create_proc(struct snd_opl4 *opl4) { return 0; }

__attribute__((used)) static inline void snd_opl4_free_proc(struct snd_opl4 *opl4) {}

__attribute__((used)) static int snd_opl4_seq_use_inc(struct snd_opl4 *opl4)
{
	if (!try_module_get(opl4->card->module))
		return -EFAULT;
	return 0;
}

__attribute__((used)) static void snd_opl4_seq_use_dec(struct snd_opl4 *opl4)
{
	module_put(opl4->card->module);
}

__attribute__((used)) static int snd_opl4_seq_use(void *private_data, struct snd_seq_port_subscribe *info)
{
	struct snd_opl4 *opl4 = private_data;
	int err;

	mutex_lock(&opl4->access_mutex);

	if (opl4->used) {
		mutex_unlock(&opl4->access_mutex);
		return -EBUSY;
	}
	opl4->used++;

	if (info->sender.client != SNDRV_SEQ_CLIENT_SYSTEM) {
		err = snd_opl4_seq_use_inc(opl4);
		if (err < 0) {
			mutex_unlock(&opl4->access_mutex);
			return err;
		}
	}

	mutex_unlock(&opl4->access_mutex);

	snd_opl4_synth_reset(opl4);
	return 0;
}

__attribute__((used)) static int snd_opl4_seq_unuse(void *private_data, struct snd_seq_port_subscribe *info)
{
	struct snd_opl4 *opl4 = private_data;

	snd_opl4_synth_shutdown(opl4);

	mutex_lock(&opl4->access_mutex);
	opl4->used--;
	mutex_unlock(&opl4->access_mutex);

	if (info->sender.client != SNDRV_SEQ_CLIENT_SYSTEM)
		snd_opl4_seq_use_dec(opl4);
	return 0;
}

__attribute__((used)) static int snd_opl4_seq_event_input(struct snd_seq_event *ev, int direct,
				    void *private_data, int atomic, int hop)
{
	struct snd_opl4 *opl4 = private_data;

	snd_midi_process_event(&opl4_ops, ev, opl4->chset);
	return 0;
}

__attribute__((used)) static void snd_opl4_seq_free_port(void *private_data)
{
	struct snd_opl4 *opl4 = private_data;

	snd_midi_channel_free_set(opl4->chset);
}

__attribute__((used)) static int snd_opl4_seq_probe(struct device *_dev)
{
	struct snd_seq_device *dev = to_seq_dev(_dev);
	struct snd_opl4 *opl4;
	int client;
	struct snd_seq_port_callback pcallbacks;

	opl4 = *(struct snd_opl4 **)SNDRV_SEQ_DEVICE_ARGPTR(dev);
	if (!opl4)
		return -EINVAL;

	if (snd_yrw801_detect(opl4) < 0)
		return -ENODEV;

	opl4->chset = snd_midi_channel_alloc_set(16);
	if (!opl4->chset)
		return -ENOMEM;
	opl4->chset->private_data = opl4;

	/* allocate new client */
	client = snd_seq_create_kernel_client(opl4->card, opl4->seq_dev_num,
					      "OPL4 Wavetable");
	if (client < 0) {
		snd_midi_channel_free_set(opl4->chset);
		return client;
	}
	opl4->seq_client = client;
	opl4->chset->client = client;

	/* create new port */
	memset(&pcallbacks, 0, sizeof(pcallbacks));
	pcallbacks.owner = THIS_MODULE;
	pcallbacks.use = snd_opl4_seq_use;
	pcallbacks.unuse = snd_opl4_seq_unuse;
	pcallbacks.event_input = snd_opl4_seq_event_input;
	pcallbacks.private_free = snd_opl4_seq_free_port;
	pcallbacks.private_data = opl4;

	opl4->chset->port = snd_seq_event_port_attach(client, &pcallbacks,
						      SNDRV_SEQ_PORT_CAP_WRITE |
						      SNDRV_SEQ_PORT_CAP_SUBS_WRITE,
						      SNDRV_SEQ_PORT_TYPE_MIDI_GENERIC |
						      SNDRV_SEQ_PORT_TYPE_MIDI_GM |
						      SNDRV_SEQ_PORT_TYPE_HARDWARE |
						      SNDRV_SEQ_PORT_TYPE_SYNTHESIZER,
						      16, 24,
						      "OPL4 Wavetable Port");
	if (opl4->chset->port < 0) {
		int err = opl4->chset->port;
		snd_midi_channel_free_set(opl4->chset);
		snd_seq_delete_kernel_client(client);
		opl4->seq_client = -1;
		return err;
	}
	return 0;
}

__attribute__((used)) static int snd_opl4_seq_remove(struct device *_dev)
{
	struct snd_seq_device *dev = to_seq_dev(_dev);
	struct snd_opl4 *opl4;

	opl4 = *(struct snd_opl4 **)SNDRV_SEQ_DEVICE_ARGPTR(dev);
	if (!opl4)
		return -EINVAL;

	if (opl4->seq_client >= 0) {
		snd_seq_delete_kernel_client(opl4->seq_client);
		opl4->seq_client = -1;
	}
	return 0;
}


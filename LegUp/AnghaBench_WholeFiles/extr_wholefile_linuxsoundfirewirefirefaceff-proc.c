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
struct snd_pcm_substream {int dummy; } ;
struct snd_info_entry {int mode; struct snd_ff* private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct snd_ff {TYPE_3__* card; TYPE_2__* spec; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
struct TYPE_6__ {struct snd_info_entry* proc_root; } ;
struct TYPE_5__ {TYPE_1__* protocol; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* dump_sync_status ) (struct snd_ff*,struct snd_info_buffer*) ;int /*<<< orphan*/  (* dump_clock_config ) (struct snd_ff*,struct snd_info_buffer*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int S_IFDIR ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 struct snd_info_entry* snd_info_create_card_entry (TYPE_3__*,char const*,struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_free_entry (struct snd_info_entry*) ; 
 scalar_t__ snd_info_register (struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_ff*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 
 int /*<<< orphan*/  stub1 (struct snd_ff*,struct snd_info_buffer*) ; 
 int /*<<< orphan*/  stub2 (struct snd_ff*,struct snd_info_buffer*) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool rcode_is_permanent_error(int rcode)
{
	return rcode == RCODE_TYPE_ERROR || rcode == RCODE_ADDRESS_ERROR;
}

__attribute__((used)) static inline bool amdtp_stream_running(struct amdtp_stream *s)
{
	return !IS_ERR(s->context);
}

__attribute__((used)) static inline bool amdtp_streaming_error(struct amdtp_stream *s)
{
	return s->packet_index < 0;
}

__attribute__((used)) static inline bool amdtp_stream_pcm_running(struct amdtp_stream *s)
{
	return !!s->pcm;
}

__attribute__((used)) static inline void amdtp_stream_pcm_trigger(struct amdtp_stream *s,
					    struct snd_pcm_substream *pcm)
{
	WRITE_ONCE(s->pcm, pcm);
}

__attribute__((used)) static inline bool cip_sfc_is_base_44100(enum cip_sfc sfc)
{
	return sfc & 1;
}

__attribute__((used)) static inline bool amdtp_stream_wait_callback(struct amdtp_stream *s,
					      unsigned int timeout)
{
	return wait_event_timeout(s->callback_wait,
				  s->callbacked == true,
				  msecs_to_jiffies(timeout)) > 0;
}

__attribute__((used)) static void proc_dump_clock_config(struct snd_info_entry *entry,
				   struct snd_info_buffer *buffer)
{
	struct snd_ff *ff = entry->private_data;

	ff->spec->protocol->dump_clock_config(ff, buffer);
}

__attribute__((used)) static void proc_dump_sync_status(struct snd_info_entry *entry,
				  struct snd_info_buffer *buffer)
{
	struct snd_ff *ff = entry->private_data;

	ff->spec->protocol->dump_sync_status(ff, buffer);
}

__attribute__((used)) static void add_node(struct snd_ff *ff, struct snd_info_entry *root,
		     const char *name,
		     void (*op)(struct snd_info_entry *e,
				struct snd_info_buffer *b))
{
	struct snd_info_entry *entry;

	entry = snd_info_create_card_entry(ff->card, name, root);
	if (entry == NULL)
		return;

	snd_info_set_text_ops(entry, ff, op);
	if (snd_info_register(entry) < 0)
		snd_info_free_entry(entry);
}

void snd_ff_proc_init(struct snd_ff *ff)
{
	struct snd_info_entry *root;

	/*
	 * All nodes are automatically removed at snd_card_disconnect(),
	 * by following to link list.
	 */
	root = snd_info_create_card_entry(ff->card, "firewire",
					  ff->card->proc_root);
	if (root == NULL)
		return;
	root->mode = S_IFDIR | 0555;
	if (snd_info_register(root) < 0) {
		snd_info_free_entry(root);
		return;
	}

	add_node(ff, root, "clock-config", proc_dump_clock_config);
	add_node(ff, root, "sync-status", proc_dump_sync_status);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_oxfw_stream_formation {int /*<<< orphan*/  midi; int /*<<< orphan*/  pcm; int /*<<< orphan*/  rate; } ;
struct snd_oxfw {TYPE_1__* card; int /*<<< orphan*/ ** tx_stream_formats; int /*<<< orphan*/  has_output; int /*<<< orphan*/ ** rx_stream_formats; } ;
struct snd_info_entry {int mode; struct snd_oxfw* private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct fw_unit {int dummy; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum avc_general_plug_dir { ____Placeholder_avc_general_plug_dir } avc_general_plug_dir ;
typedef  int /*<<< orphan*/  curr ;
struct TYPE_2__ {struct snd_info_entry* proc_root; } ;

/* Variables and functions */
 int /*<<< orphan*/  AVC_GENERAL_PLUG_DIR_IN ; 
 int /*<<< orphan*/  AVC_GENERAL_PLUG_DIR_OUT ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int SND_OXFW_STREAM_FORMAT_ENTRIES ; 
 int S_IFDIR ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int avc_stream_get_format (struct fw_unit*,int,unsigned int,int /*<<< orphan*/ *,unsigned int*,unsigned int) ; 
 scalar_t__ memcmp (struct snd_oxfw_stream_formation*,struct snd_oxfw_stream_formation*,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 struct snd_info_entry* snd_info_create_card_entry (TYPE_1__*,char const*,struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_free_entry (struct snd_info_entry*) ; 
 scalar_t__ snd_info_register (struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_oxfw*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 
 int snd_oxfw_stream_get_current_formation (struct snd_oxfw*,int /*<<< orphan*/ ,struct snd_oxfw_stream_formation*) ; 
 int snd_oxfw_stream_parse_format (int /*<<< orphan*/ *,struct snd_oxfw_stream_formation*) ; 
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

__attribute__((used)) static inline int
avc_stream_get_format_single(struct fw_unit *unit,
			     enum avc_general_plug_dir dir, unsigned int pid,
			     u8 *buf, unsigned int *len)
{
	return avc_stream_get_format(unit, dir, pid, buf, len, 0xff);
}

__attribute__((used)) static inline int
avc_stream_get_format_list(struct fw_unit *unit,
			   enum avc_general_plug_dir dir, unsigned int pid,
			   u8 *buf, unsigned int *len,
			   unsigned int eid)
{
	return avc_stream_get_format(unit, dir, pid, buf, len, eid);
}

__attribute__((used)) static void proc_read_formation(struct snd_info_entry *entry,
				struct snd_info_buffer *buffer)
{
	struct snd_oxfw *oxfw = entry->private_data;
	struct snd_oxfw_stream_formation formation, curr;
	u8 *format;
	char flag;
	int i, err;

	/* Show input. */
	err = snd_oxfw_stream_get_current_formation(oxfw,
						    AVC_GENERAL_PLUG_DIR_IN,
						    &curr);
	if (err < 0)
		return;

	snd_iprintf(buffer, "Input Stream to device:\n");
	snd_iprintf(buffer, "\tRate\tPCM\tMIDI\n");
	for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
		format = oxfw->rx_stream_formats[i];
		if (format == NULL)
			continue;

		err = snd_oxfw_stream_parse_format(format, &formation);
		if (err < 0)
			continue;

		if (memcmp(&formation, &curr, sizeof(curr)) == 0)
			flag = '*';
		else
			flag = ' ';

		snd_iprintf(buffer, "%c\t%d\t%d\t%d\n", flag,
			    formation.rate, formation.pcm, formation.midi);
	}

	if (!oxfw->has_output)
		return;

	/* Show output. */
	err = snd_oxfw_stream_get_current_formation(oxfw,
						    AVC_GENERAL_PLUG_DIR_OUT,
						    &curr);
	if (err < 0)
		return;

	snd_iprintf(buffer, "Output Stream from device:\n");
	snd_iprintf(buffer, "\tRate\tPCM\tMIDI\n");
	for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
		format = oxfw->tx_stream_formats[i];
		if (format == NULL)
			continue;

		err = snd_oxfw_stream_parse_format(format, &formation);
		if (err < 0)
			continue;

		if (memcmp(&formation, &curr, sizeof(curr)) == 0)
			flag = '*';
		else
			flag = ' ';

		snd_iprintf(buffer, "%c\t%d\t%d\t%d\n", flag,
			    formation.rate, formation.pcm, formation.midi);
	}
}

__attribute__((used)) static void add_node(struct snd_oxfw *oxfw, struct snd_info_entry *root,
		     const char *name,
		     void (*op)(struct snd_info_entry *e,
				struct snd_info_buffer *b))
{
	struct snd_info_entry *entry;

	entry = snd_info_create_card_entry(oxfw->card, name, root);
	if (entry == NULL)
		return;

	snd_info_set_text_ops(entry, oxfw, op);
	if (snd_info_register(entry) < 0)
		snd_info_free_entry(entry);
}

void snd_oxfw_proc_init(struct snd_oxfw *oxfw)
{
	struct snd_info_entry *root;

	/*
	 * All nodes are automatically removed at snd_card_disconnect(),
	 * by following to link list.
	 */
	root = snd_info_create_card_entry(oxfw->card, "firewire",
					  oxfw->card->proc_root);
	if (root == NULL)
		return;
	root->mode = S_IFDIR | 0555;
	if (snd_info_register(root) < 0) {
		snd_info_free_entry(root);
		return;
	}

	add_node(oxfw, root, "formation", proc_read_formation);
}


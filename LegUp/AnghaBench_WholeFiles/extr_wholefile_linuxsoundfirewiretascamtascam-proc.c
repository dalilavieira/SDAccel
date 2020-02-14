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
struct snd_tscm {TYPE_1__* card; int /*<<< orphan*/  unit; } ;
struct snd_rawmidi_substream {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_info_entry {int mode; struct snd_tscm* private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct snd_fw_async_midi_port {int error; int /*<<< orphan*/  work; struct snd_rawmidi_substream* substream; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  int /*<<< orphan*/  data ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {struct snd_info_entry* proc_root; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int S_IFDIR ; 
 int /*<<< orphan*/  TCODE_READ_QUADLET_REQUEST ; 
 scalar_t__ TSCM_ADDR_BASE ; 
 scalar_t__ TSCM_OFFSET_FIRMWARE_ARM ; 
 scalar_t__ TSCM_OFFSET_FIRMWARE_FPGA ; 
 scalar_t__ TSCM_OFFSET_FIRMWARE_HW ; 
 scalar_t__ TSCM_OFFSET_FIRMWARE_REGISTER ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 unsigned int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int snd_fw_transaction (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct snd_info_entry* snd_info_create_card_entry (TYPE_1__*,char const*,struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_free_entry (struct snd_info_entry*) ; 
 scalar_t__ snd_info_register (struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_tscm*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,unsigned int,unsigned int) ; 
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

__attribute__((used)) static inline void
snd_fw_async_midi_port_run(struct snd_fw_async_midi_port *port,
			   struct snd_rawmidi_substream *substream)
{
	if (!port->error) {
		port->substream = substream;
		schedule_work(&port->work);
	}
}

__attribute__((used)) static inline void
snd_fw_async_midi_port_finish(struct snd_fw_async_midi_port *port)
{
	port->substream = NULL;
	cancel_work_sync(&port->work);
	port->error = false;
}

__attribute__((used)) static void proc_read_firmware(struct snd_info_entry *entry,
			       struct snd_info_buffer *buffer)
{
	struct snd_tscm *tscm = entry->private_data;
	__be32 data;
	unsigned int reg, fpga, arm, hw;
	int err;

	err = snd_fw_transaction(tscm->unit, TCODE_READ_QUADLET_REQUEST,
			TSCM_ADDR_BASE + TSCM_OFFSET_FIRMWARE_REGISTER,
			&data, sizeof(data), 0);
	if (err < 0)
		return;
	reg = be32_to_cpu(data);

	err = snd_fw_transaction(tscm->unit, TCODE_READ_QUADLET_REQUEST,
			TSCM_ADDR_BASE + TSCM_OFFSET_FIRMWARE_FPGA,
			&data, sizeof(data), 0);
	if (err < 0)
		return;
	fpga = be32_to_cpu(data);

	err = snd_fw_transaction(tscm->unit, TCODE_READ_QUADLET_REQUEST,
			TSCM_ADDR_BASE + TSCM_OFFSET_FIRMWARE_ARM,
			&data, sizeof(data), 0);
	if (err < 0)
		return;
	arm = be32_to_cpu(data);

	err = snd_fw_transaction(tscm->unit, TCODE_READ_QUADLET_REQUEST,
			TSCM_ADDR_BASE + TSCM_OFFSET_FIRMWARE_HW,
			&data, sizeof(data), 0);
	if (err < 0)
		return;
	hw = be32_to_cpu(data);

	snd_iprintf(buffer, "Register: %d (0x%08x)\n", reg & 0xffff, reg);
	snd_iprintf(buffer, "FPGA:     %d (0x%08x)\n", fpga & 0xffff, fpga);
	snd_iprintf(buffer, "ARM:      %d (0x%08x)\n", arm & 0xffff, arm);
	snd_iprintf(buffer, "Hardware: %d (0x%08x)\n", hw >> 16, hw);
}

__attribute__((used)) static void add_node(struct snd_tscm *tscm, struct snd_info_entry *root,
		     const char *name,
		     void (*op)(struct snd_info_entry *e,
				struct snd_info_buffer *b))
{
	struct snd_info_entry *entry;

	entry = snd_info_create_card_entry(tscm->card, name, root);
	if (entry == NULL)
		return;

	snd_info_set_text_ops(entry, tscm, op);
	if (snd_info_register(entry) < 0)
		snd_info_free_entry(entry);
}

void snd_tscm_proc_init(struct snd_tscm *tscm)
{
	struct snd_info_entry *root;

	/*
	 * All nodes are automatically removed at snd_card_disconnect(),
	 * by following to link list.
	 */
	root = snd_info_create_card_entry(tscm->card, "firewire",
					  tscm->card->proc_root);
	if (root == NULL)
		return;
	root->mode = S_IFDIR | 0555;
	if (snd_info_register(root) < 0) {
		snd_info_free_entry(root);
		return;
	}

	add_node(tscm, root, "firmware", proc_read_firmware);
}


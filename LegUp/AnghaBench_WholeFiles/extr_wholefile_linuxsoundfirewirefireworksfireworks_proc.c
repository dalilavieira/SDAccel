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
typedef  int /*<<< orphan*/  u32 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_info_entry {int mode; struct snd_efw* private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct snd_efw_phys_meters {unsigned short phys_in_grp_count; unsigned short phys_out_grp_count; int out_meters; int in_meters; int /*<<< orphan*/ * values; int /*<<< orphan*/  mixer_capture_channels; int /*<<< orphan*/  mixer_playback_channels; int /*<<< orphan*/  midi_in_ports; int /*<<< orphan*/  midi_out_ports; int /*<<< orphan*/  amdtp_tx_pcm_channels_4x; int /*<<< orphan*/  amdtp_rx_pcm_channels_4x; int /*<<< orphan*/  amdtp_tx_pcm_channels_2x; int /*<<< orphan*/  amdtp_rx_pcm_channels_2x; int /*<<< orphan*/  amdtp_tx_pcm_channels; int /*<<< orphan*/  amdtp_rx_pcm_channels; TYPE_1__* phys_out_grps; int /*<<< orphan*/  phys_in; int /*<<< orphan*/  phys_out; int /*<<< orphan*/  supported_clocks; int /*<<< orphan*/  min_sample_rate; int /*<<< orphan*/  max_sample_rate; int /*<<< orphan*/  flags; int /*<<< orphan*/  fpga_version; int /*<<< orphan*/  arm_version; int /*<<< orphan*/  dsp_version; int /*<<< orphan*/  model_name; int /*<<< orphan*/  vendor_name; int /*<<< orphan*/  version; int /*<<< orphan*/  type; int /*<<< orphan*/  guid_lo; int /*<<< orphan*/  guid_hi; } ;
struct snd_efw_phys_grp {size_t type; unsigned int count; } ;
struct snd_efw_hwinfo {unsigned short phys_in_grp_count; unsigned short phys_out_grp_count; int out_meters; int in_meters; int /*<<< orphan*/ * values; int /*<<< orphan*/  mixer_capture_channels; int /*<<< orphan*/  mixer_playback_channels; int /*<<< orphan*/  midi_in_ports; int /*<<< orphan*/  midi_out_ports; int /*<<< orphan*/  amdtp_tx_pcm_channels_4x; int /*<<< orphan*/  amdtp_rx_pcm_channels_4x; int /*<<< orphan*/  amdtp_tx_pcm_channels_2x; int /*<<< orphan*/  amdtp_rx_pcm_channels_2x; int /*<<< orphan*/  amdtp_tx_pcm_channels; int /*<<< orphan*/  amdtp_rx_pcm_channels; TYPE_1__* phys_out_grps; int /*<<< orphan*/  phys_in; int /*<<< orphan*/  phys_out; int /*<<< orphan*/  supported_clocks; int /*<<< orphan*/  min_sample_rate; int /*<<< orphan*/  max_sample_rate; int /*<<< orphan*/  flags; int /*<<< orphan*/  fpga_version; int /*<<< orphan*/  arm_version; int /*<<< orphan*/  dsp_version; int /*<<< orphan*/  model_name; int /*<<< orphan*/  vendor_name; int /*<<< orphan*/  version; int /*<<< orphan*/  type; int /*<<< orphan*/  guid_lo; int /*<<< orphan*/  guid_hi; } ;
struct snd_efw {int phys_in; int phys_out; unsigned int phys_out_grp_count; unsigned int phys_in_grp_count; scalar_t__ pull_ptr; scalar_t__ push_ptr; TYPE_2__* card; struct snd_efw_phys_grp* phys_in_grps; struct snd_efw_phys_grp* phys_out_grps; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  enum snd_efw_clock_source { ____Placeholder_snd_efw_clock_source } snd_efw_clock_source ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
struct TYPE_4__ {struct snd_info_entry* proc_root; } ;
struct TYPE_3__ {int /*<<< orphan*/  count; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (char const* const*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int S_IFDIR ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  kfree (struct snd_efw_phys_meters*) ; 
 struct snd_efw_phys_meters* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct snd_efw_phys_meters* kzalloc (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int min (int,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 scalar_t__ snd_efw_command_get_clock_source (struct snd_efw*,int*) ; 
 scalar_t__ snd_efw_command_get_hwinfo (struct snd_efw*,struct snd_efw_phys_meters*) ; 
 int snd_efw_command_get_phys_meters (struct snd_efw*,struct snd_efw_phys_meters*,unsigned int) ; 
 scalar_t__ snd_efw_command_get_sampling_rate (struct snd_efw*,unsigned int*) ; 
 unsigned int snd_efw_resp_buf_size ; 
 struct snd_info_entry* snd_info_create_card_entry (TYPE_2__*,char const*,struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_free_entry (struct snd_info_entry*) ; 
 scalar_t__ snd_info_register (struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_efw*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static inline bool rcode_is_permanent_error(int rcode)
{
	return rcode == RCODE_TYPE_ERROR || rcode == RCODE_ADDRESS_ERROR;
}

__attribute__((used)) static inline const char*
get_phys_name(struct snd_efw_phys_grp *grp, bool input)
{
	static const char *const ch_type[] = {
		"Analog", "S/PDIF", "ADAT", "S/PDIF or ADAT", "Mirroring",
		"Headphones", "I2S", "Guitar", "Pirzo Guitar", "Guitar String",
	};

	if (grp->type < ARRAY_SIZE(ch_type))
		return ch_type[grp->type];
	else if (input)
		return "Input";
	else
		return "Output";
}

__attribute__((used)) static void
proc_read_hwinfo(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
	struct snd_efw *efw = entry->private_data;
	unsigned short i;
	struct snd_efw_hwinfo *hwinfo;

	hwinfo = kmalloc(sizeof(struct snd_efw_hwinfo), GFP_KERNEL);
	if (hwinfo == NULL)
		return;

	if (snd_efw_command_get_hwinfo(efw, hwinfo) < 0)
		goto end;

	snd_iprintf(buffer, "guid_hi: 0x%X\n", hwinfo->guid_hi);
	snd_iprintf(buffer, "guid_lo: 0x%X\n", hwinfo->guid_lo);
	snd_iprintf(buffer, "type: 0x%X\n", hwinfo->type);
	snd_iprintf(buffer, "version: 0x%X\n", hwinfo->version);
	snd_iprintf(buffer, "vendor_name: %s\n", hwinfo->vendor_name);
	snd_iprintf(buffer, "model_name: %s\n", hwinfo->model_name);

	snd_iprintf(buffer, "dsp_version: 0x%X\n", hwinfo->dsp_version);
	snd_iprintf(buffer, "arm_version: 0x%X\n", hwinfo->arm_version);
	snd_iprintf(buffer, "fpga_version: 0x%X\n", hwinfo->fpga_version);

	snd_iprintf(buffer, "flags: 0x%X\n", hwinfo->flags);

	snd_iprintf(buffer, "max_sample_rate: 0x%X\n", hwinfo->max_sample_rate);
	snd_iprintf(buffer, "min_sample_rate: 0x%X\n", hwinfo->min_sample_rate);
	snd_iprintf(buffer, "supported_clock: 0x%X\n",
		    hwinfo->supported_clocks);

	snd_iprintf(buffer, "phys out: 0x%X\n", hwinfo->phys_out);
	snd_iprintf(buffer, "phys in: 0x%X\n", hwinfo->phys_in);

	snd_iprintf(buffer, "phys in grps: 0x%X\n",
		    hwinfo->phys_in_grp_count);
	for (i = 0; i < hwinfo->phys_in_grp_count; i++) {
		snd_iprintf(buffer,
			    "phys in grp[%d]: type 0x%X, count 0x%X\n",
			    i, hwinfo->phys_out_grps[i].type,
			    hwinfo->phys_out_grps[i].count);
	}

	snd_iprintf(buffer, "phys out grps: 0x%X\n",
		    hwinfo->phys_out_grp_count);
	for (i = 0; i < hwinfo->phys_out_grp_count; i++) {
		snd_iprintf(buffer,
			    "phys out grps[%d]: type 0x%X, count 0x%X\n",
			    i, hwinfo->phys_out_grps[i].type,
			    hwinfo->phys_out_grps[i].count);
	}

	snd_iprintf(buffer, "amdtp rx pcm channels 1x: 0x%X\n",
		    hwinfo->amdtp_rx_pcm_channels);
	snd_iprintf(buffer, "amdtp tx pcm channels 1x: 0x%X\n",
		    hwinfo->amdtp_tx_pcm_channels);
	snd_iprintf(buffer, "amdtp rx pcm channels 2x: 0x%X\n",
		    hwinfo->amdtp_rx_pcm_channels_2x);
	snd_iprintf(buffer, "amdtp tx pcm channels 2x: 0x%X\n",
		    hwinfo->amdtp_tx_pcm_channels_2x);
	snd_iprintf(buffer, "amdtp rx pcm channels 4x: 0x%X\n",
		    hwinfo->amdtp_rx_pcm_channels_4x);
	snd_iprintf(buffer, "amdtp tx pcm channels 4x: 0x%X\n",
		    hwinfo->amdtp_tx_pcm_channels_4x);

	snd_iprintf(buffer, "midi out ports: 0x%X\n", hwinfo->midi_out_ports);
	snd_iprintf(buffer, "midi in ports: 0x%X\n", hwinfo->midi_in_ports);

	snd_iprintf(buffer, "mixer playback channels: 0x%X\n",
		    hwinfo->mixer_playback_channels);
	snd_iprintf(buffer, "mixer capture channels: 0x%X\n",
		    hwinfo->mixer_capture_channels);
end:
	kfree(hwinfo);
}

__attribute__((used)) static void
proc_read_clock(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
	struct snd_efw *efw = entry->private_data;
	enum snd_efw_clock_source clock_source;
	unsigned int sampling_rate;

	if (snd_efw_command_get_clock_source(efw, &clock_source) < 0)
		return;

	if (snd_efw_command_get_sampling_rate(efw, &sampling_rate) < 0)
		return;

	snd_iprintf(buffer, "Clock Source: %d\n", clock_source);
	snd_iprintf(buffer, "Sampling Rate: %d\n", sampling_rate);
}

__attribute__((used)) static void
proc_read_phys_meters(struct snd_info_entry *entry,
		      struct snd_info_buffer *buffer)
{
	struct snd_efw *efw = entry->private_data;
	struct snd_efw_phys_meters *meters;
	unsigned int g, c, m, max, size;
	const char *name;
	u32 *linear;
	int err;

	size = sizeof(struct snd_efw_phys_meters) +
	       (efw->phys_in + efw->phys_out) * sizeof(u32);
	meters = kzalloc(size, GFP_KERNEL);
	if (meters == NULL)
		return;

	err = snd_efw_command_get_phys_meters(efw, meters, size);
	if (err < 0)
		goto end;

	snd_iprintf(buffer, "Physical Meters:\n");

	m = 0;
	max = min(efw->phys_out, meters->out_meters);
	linear = meters->values;
	snd_iprintf(buffer, " %d Outputs:\n", max);
	for (g = 0; g < efw->phys_out_grp_count; g++) {
		name = get_phys_name(&efw->phys_out_grps[g], false);
		for (c = 0; c < efw->phys_out_grps[g].count; c++) {
			if (m < max)
				snd_iprintf(buffer, "\t%s [%d]: %d\n",
					    name, c, linear[m++]);
		}
	}

	m = 0;
	max = min(efw->phys_in, meters->in_meters);
	linear = meters->values + meters->out_meters;
	snd_iprintf(buffer, " %d Inputs:\n", max);
	for (g = 0; g < efw->phys_in_grp_count; g++) {
		name = get_phys_name(&efw->phys_in_grps[g], true);
		for (c = 0; c < efw->phys_in_grps[g].count; c++)
			if (m < max)
				snd_iprintf(buffer, "\t%s [%d]: %d\n",
					    name, c, linear[m++]);
	}
end:
	kfree(meters);
}

__attribute__((used)) static void
proc_read_queues_state(struct snd_info_entry *entry,
		       struct snd_info_buffer *buffer)
{
	struct snd_efw *efw = entry->private_data;
	unsigned int consumed;

	if (efw->pull_ptr > efw->push_ptr)
		consumed = snd_efw_resp_buf_size -
			   (unsigned int)(efw->pull_ptr - efw->push_ptr);
	else
		consumed = (unsigned int)(efw->push_ptr - efw->pull_ptr);

	snd_iprintf(buffer, "%d/%d\n",
		    consumed, snd_efw_resp_buf_size);
}

__attribute__((used)) static void
add_node(struct snd_efw *efw, struct snd_info_entry *root, const char *name,
	 void (*op)(struct snd_info_entry *e, struct snd_info_buffer *b))
{
	struct snd_info_entry *entry;

	entry = snd_info_create_card_entry(efw->card, name, root);
	if (entry == NULL)
		return;

	snd_info_set_text_ops(entry, efw, op);
	if (snd_info_register(entry) < 0)
		snd_info_free_entry(entry);
}

void snd_efw_proc_init(struct snd_efw *efw)
{
	struct snd_info_entry *root;

	/*
	 * All nodes are automatically removed at snd_card_disconnect(),
	 * by following to link list.
	 */
	root = snd_info_create_card_entry(efw->card, "firewire",
					  efw->card->proc_root);
	if (root == NULL)
		return;
	root->mode = S_IFDIR | 0555;
	if (snd_info_register(root) < 0) {
		snd_info_free_entry(root);
		return;
	}

	add_node(efw, root, "clock", proc_read_clock);
	add_node(efw, root, "firmware", proc_read_hwinfo);
	add_node(efw, root, "meters", proc_read_phys_meters);
	add_node(efw, root, "queues", proc_read_queues_state);
}


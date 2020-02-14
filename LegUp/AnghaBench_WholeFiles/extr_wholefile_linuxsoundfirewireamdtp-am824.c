#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct snd_rawmidi_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {unsigned int buffer_size; scalar_t__ dma_area; } ;
struct fw_unit {int dummy; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int fdf; int sfc; unsigned int syt_interval; unsigned int pcm_buffer_pointer; unsigned int data_block_counter; int /*<<< orphan*/ * pcm; struct amdtp_am824* protocol; int /*<<< orphan*/  data_block_quadlets; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  context; } ;
struct amdtp_am824 {unsigned int pcm_channels; unsigned int midi_ports; int frame_multiplier; unsigned int* pcm_positions; unsigned int midi_position; unsigned int midi_fifo_limit; int* midi_fifo_used; int /*<<< orphan*/ ** midi; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum cip_flags { ____Placeholder_cip_flags } cip_flags ;
typedef  enum amdtp_stream_direction { ____Placeholder_amdtp_stream_direction } amdtp_stream_direction ;
typedef  unsigned int (* amdtp_stream_process_data_blocks_t ) (struct amdtp_stream*,int /*<<< orphan*/ *,unsigned int,unsigned int*) ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 unsigned int AM824_MAX_CHANNELS_FOR_MIDI ; 
 unsigned int AM824_MAX_CHANNELS_FOR_PCM ; 
 int AMDTP_FDF_AM824 ; 
 int AMDTP_IN_STREAM ; 
 int /*<<< orphan*/  CIP_FMT_AM ; 
 unsigned int DIV_ROUND_UP (unsigned int,int) ; 
 int EINVAL ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned int MAX_MIDI_RX_BLOCKS ; 
 unsigned int MIDI_BYTES_PER_SECOND ; 
 struct snd_rawmidi_substream* READ_ONCE (int /*<<< orphan*/ *) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ *,struct snd_rawmidi_substream*) ; 
 scalar_t__* amdtp_rate_table ; 
 int amdtp_stream_add_pcm_hw_constraints (struct amdtp_stream*,struct snd_pcm_runtime*) ; 
 int amdtp_stream_init (struct amdtp_stream*,struct fw_unit*,int,int,int /*<<< orphan*/ ,unsigned int (*) (struct amdtp_stream*,int /*<<< orphan*/ *,unsigned int,unsigned int*),int) ; 
 int amdtp_stream_set_parameters (struct amdtp_stream*,unsigned int,unsigned int) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int const) ; 
 int frames_to_bytes (struct snd_pcm_runtime*,unsigned int) ; 
 int max (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_pcm_hw_constraint_msbits (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (int /*<<< orphan*/ *,int*,int) ; 
 int snd_rawmidi_transmit (int /*<<< orphan*/ *,int*,int) ; 
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

int amdtp_am824_set_parameters(struct amdtp_stream *s, unsigned int rate,
			       unsigned int pcm_channels,
			       unsigned int midi_ports,
			       bool double_pcm_frames)
{
	struct amdtp_am824 *p = s->protocol;
	unsigned int midi_channels;
	unsigned int i;
	int err;

	if (amdtp_stream_running(s))
		return -EINVAL;

	if (pcm_channels > AM824_MAX_CHANNELS_FOR_PCM)
		return -EINVAL;

	midi_channels = DIV_ROUND_UP(midi_ports, 8);
	if (midi_channels > AM824_MAX_CHANNELS_FOR_MIDI)
		return -EINVAL;

	if (WARN_ON(amdtp_stream_running(s)) ||
	    WARN_ON(pcm_channels > AM824_MAX_CHANNELS_FOR_PCM) ||
	    WARN_ON(midi_channels > AM824_MAX_CHANNELS_FOR_MIDI))
		return -EINVAL;

	err = amdtp_stream_set_parameters(s, rate,
					  pcm_channels + midi_channels);
	if (err < 0)
		return err;

	s->fdf = AMDTP_FDF_AM824 | s->sfc;

	p->pcm_channels = pcm_channels;
	p->midi_ports = midi_ports;

	/*
	 * In IEC 61883-6, one data block represents one event. In ALSA, one
	 * event equals to one PCM frame. But Dice has a quirk at higher
	 * sampling rate to transfer two PCM frames in one data block.
	 */
	if (double_pcm_frames)
		p->frame_multiplier = 2;
	else
		p->frame_multiplier = 1;

	/* init the position map for PCM and MIDI channels */
	for (i = 0; i < pcm_channels; i++)
		p->pcm_positions[i] = i;
	p->midi_position = p->pcm_channels;

	/*
	 * We do not know the actual MIDI FIFO size of most devices.  Just
	 * assume two bytes, i.e., one byte can be received over the bus while
	 * the previous one is transmitted over MIDI.
	 * (The value here is adjusted for midi_ratelimit_per_packet().)
	 */
	p->midi_fifo_limit = rate - MIDI_BYTES_PER_SECOND * s->syt_interval + 1;

	return 0;
}

void amdtp_am824_set_pcm_position(struct amdtp_stream *s, unsigned int index,
				 unsigned int position)
{
	struct amdtp_am824 *p = s->protocol;

	if (index < p->pcm_channels)
		p->pcm_positions[index] = position;
}

void amdtp_am824_set_midi_position(struct amdtp_stream *s,
				   unsigned int position)
{
	struct amdtp_am824 *p = s->protocol;

	p->midi_position = position;
}

__attribute__((used)) static void write_pcm_s32(struct amdtp_stream *s,
			  struct snd_pcm_substream *pcm,
			  __be32 *buffer, unsigned int frames)
{
	struct amdtp_am824 *p = s->protocol;
	struct snd_pcm_runtime *runtime = pcm->runtime;
	unsigned int channels, remaining_frames, i, c;
	const u32 *src;

	channels = p->pcm_channels;
	src = (void *)runtime->dma_area +
			frames_to_bytes(runtime, s->pcm_buffer_pointer);
	remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;

	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c) {
			buffer[p->pcm_positions[c]] =
					cpu_to_be32((*src >> 8) | 0x40000000);
			src++;
		}
		buffer += s->data_block_quadlets;
		if (--remaining_frames == 0)
			src = (void *)runtime->dma_area;
	}
}

__attribute__((used)) static void read_pcm_s32(struct amdtp_stream *s,
			 struct snd_pcm_substream *pcm,
			 __be32 *buffer, unsigned int frames)
{
	struct amdtp_am824 *p = s->protocol;
	struct snd_pcm_runtime *runtime = pcm->runtime;
	unsigned int channels, remaining_frames, i, c;
	u32 *dst;

	channels = p->pcm_channels;
	dst  = (void *)runtime->dma_area +
			frames_to_bytes(runtime, s->pcm_buffer_pointer);
	remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;

	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c) {
			*dst = be32_to_cpu(buffer[p->pcm_positions[c]]) << 8;
			dst++;
		}
		buffer += s->data_block_quadlets;
		if (--remaining_frames == 0)
			dst = (void *)runtime->dma_area;
	}
}

__attribute__((used)) static void write_pcm_silence(struct amdtp_stream *s,
			      __be32 *buffer, unsigned int frames)
{
	struct amdtp_am824 *p = s->protocol;
	unsigned int i, c, channels = p->pcm_channels;

	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c)
			buffer[p->pcm_positions[c]] = cpu_to_be32(0x40000000);
		buffer += s->data_block_quadlets;
	}
}

int amdtp_am824_add_pcm_hw_constraints(struct amdtp_stream *s,
				       struct snd_pcm_runtime *runtime)
{
	int err;

	err = amdtp_stream_add_pcm_hw_constraints(s, runtime);
	if (err < 0)
		return err;

	/* AM824 in IEC 61883-6 can deliver 24bit data. */
	return snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
}

void amdtp_am824_midi_trigger(struct amdtp_stream *s, unsigned int port,
			      struct snd_rawmidi_substream *midi)
{
	struct amdtp_am824 *p = s->protocol;

	if (port < p->midi_ports)
		WRITE_ONCE(p->midi[port], midi);
}

__attribute__((used)) static bool midi_ratelimit_per_packet(struct amdtp_stream *s, unsigned int port)
{
	struct amdtp_am824 *p = s->protocol;
	int used;

	used = p->midi_fifo_used[port];
	if (used == 0) /* common shortcut */
		return true;

	used -= MIDI_BYTES_PER_SECOND * s->syt_interval;
	used = max(used, 0);
	p->midi_fifo_used[port] = used;

	return used < p->midi_fifo_limit;
}

__attribute__((used)) static void midi_rate_use_one_byte(struct amdtp_stream *s, unsigned int port)
{
	struct amdtp_am824 *p = s->protocol;

	p->midi_fifo_used[port] += amdtp_rate_table[s->sfc];
}

__attribute__((used)) static void write_midi_messages(struct amdtp_stream *s, __be32 *buffer,
				unsigned int frames)
{
	struct amdtp_am824 *p = s->protocol;
	unsigned int f, port;
	u8 *b;

	for (f = 0; f < frames; f++) {
		b = (u8 *)&buffer[p->midi_position];

		port = (s->data_block_counter + f) % 8;
		if (f < MAX_MIDI_RX_BLOCKS &&
		    midi_ratelimit_per_packet(s, port) &&
		    p->midi[port] != NULL &&
		    snd_rawmidi_transmit(p->midi[port], &b[1], 1) == 1) {
			midi_rate_use_one_byte(s, port);
			b[0] = 0x81;
		} else {
			b[0] = 0x80;
			b[1] = 0;
		}
		b[2] = 0;
		b[3] = 0;

		buffer += s->data_block_quadlets;
	}
}

__attribute__((used)) static void read_midi_messages(struct amdtp_stream *s,
			       __be32 *buffer, unsigned int frames)
{
	struct amdtp_am824 *p = s->protocol;
	unsigned int f, port;
	int len;
	u8 *b;

	for (f = 0; f < frames; f++) {
		port = (s->data_block_counter + f) % 8;
		b = (u8 *)&buffer[p->midi_position];

		len = b[0] - 0x80;
		if ((1 <= len) &&  (len <= 3) && (p->midi[port]))
			snd_rawmidi_receive(p->midi[port], b + 1, len);

		buffer += s->data_block_quadlets;
	}
}

__attribute__((used)) static unsigned int process_rx_data_blocks(struct amdtp_stream *s, __be32 *buffer,
					   unsigned int data_blocks, unsigned int *syt)
{
	struct amdtp_am824 *p = s->protocol;
	struct snd_pcm_substream *pcm = READ_ONCE(s->pcm);
	unsigned int pcm_frames;

	if (pcm) {
		write_pcm_s32(s, pcm, buffer, data_blocks);
		pcm_frames = data_blocks * p->frame_multiplier;
	} else {
		write_pcm_silence(s, buffer, data_blocks);
		pcm_frames = 0;
	}

	if (p->midi_ports)
		write_midi_messages(s, buffer, data_blocks);

	return pcm_frames;
}

__attribute__((used)) static unsigned int process_tx_data_blocks(struct amdtp_stream *s, __be32 *buffer,
					   unsigned int data_blocks, unsigned int *syt)
{
	struct amdtp_am824 *p = s->protocol;
	struct snd_pcm_substream *pcm = READ_ONCE(s->pcm);
	unsigned int pcm_frames;

	if (pcm) {
		read_pcm_s32(s, pcm, buffer, data_blocks);
		pcm_frames = data_blocks * p->frame_multiplier;
	} else {
		pcm_frames = 0;
	}

	if (p->midi_ports)
		read_midi_messages(s, buffer, data_blocks);

	return pcm_frames;
}

int amdtp_am824_init(struct amdtp_stream *s, struct fw_unit *unit,
		     enum amdtp_stream_direction dir, enum cip_flags flags)
{
	amdtp_stream_process_data_blocks_t process_data_blocks;

	if (dir == AMDTP_IN_STREAM)
		process_data_blocks = process_tx_data_blocks;
	else
		process_data_blocks = process_rx_data_blocks;

	return amdtp_stream_init(s, unit, dir, flags, CIP_FMT_AM,
				 process_data_blocks,
				 sizeof(struct amdtp_am824));
}


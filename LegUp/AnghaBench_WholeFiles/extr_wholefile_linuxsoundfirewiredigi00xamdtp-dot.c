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
struct dot_state {unsigned int off; int idx; int carry; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int fdf; int sfc; unsigned int syt_interval; unsigned int pcm_buffer_pointer; unsigned int data_block_counter; struct amdtp_dot* protocol; int /*<<< orphan*/ * pcm; int /*<<< orphan*/  data_block_quadlets; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  context; } ;
struct amdtp_dot {unsigned int pcm_channels; unsigned int midi_fifo_limit; int* midi_fifo_used; struct dot_state state; int /*<<< orphan*/ ** midi; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum cip_flags { ____Placeholder_cip_flags } cip_flags ;
typedef  enum amdtp_stream_direction { ____Placeholder_amdtp_stream_direction } amdtp_stream_direction ;
typedef  unsigned int (* amdtp_stream_process_data_blocks_t ) (struct amdtp_stream*,int /*<<< orphan*/ *,unsigned int,unsigned int*) ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int AMDTP_FDF_AM824 ; 
 int AMDTP_IN_STREAM ; 
 int CIP_BLOCKING ; 
 int /*<<< orphan*/  CIP_FMT_AM ; 
 int CIP_NONBLOCKING ; 
 int EBUSY ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 size_t MAGIC_DOT_BYTE ; 
 unsigned int MAX_MIDI_PORTS ; 
 unsigned int MIDI_BYTES_PER_SECOND ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 struct snd_rawmidi_substream* READ_ONCE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ *,struct snd_rawmidi_substream*) ; 
 unsigned int* amdtp_rate_table ; 
 int amdtp_stream_add_pcm_hw_constraints (struct amdtp_stream*,struct snd_pcm_runtime*) ; 
 int amdtp_stream_init (struct amdtp_stream*,struct fw_unit*,int,int,int /*<<< orphan*/ ,unsigned int (*) (struct amdtp_stream*,int /*<<< orphan*/ *,unsigned int,unsigned int*),int) ; 
 int amdtp_stream_set_parameters (struct amdtp_stream*,unsigned int,unsigned int) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int const) ; 
 int frames_to_bytes (struct snd_pcm_runtime*,unsigned int) ; 
 int max (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_pcm_hw_constraint_msbits (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_rawmidi_receive (int /*<<< orphan*/ *,int*,unsigned int) ; 
 int snd_rawmidi_transmit (int /*<<< orphan*/ *,int*,int) ; 
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

__attribute__((used)) static u8 dot_scrt(const u8 idx, const unsigned int off)
{
	/*
	 * the length of the added pattern only depends on the lower nibble
	 * of the last non-zero data
	 */
	static const u8 len[16] = {0, 1, 3, 5, 7, 9, 11, 13, 14,
				   12, 10, 8, 6, 4, 2, 0};

	/*
	 * the lower nibble of the salt. Interleaved sequence.
	 * this is walked backwards according to len[]
	 */
	static const u8 nib[15] = {0x8, 0x7, 0x9, 0x6, 0xa, 0x5, 0xb, 0x4,
				   0xc, 0x3, 0xd, 0x2, 0xe, 0x1, 0xf};

	/* circular list for the salt's hi nibble. */
	static const u8 hir[15] = {0x0, 0x6, 0xf, 0x8, 0x7, 0x5, 0x3, 0x4,
				   0xc, 0xd, 0xe, 0x1, 0x2, 0xb, 0xa};

	/*
	 * start offset for upper nibble mapping.
	 * note: 9 is /special/. In the case where the high nibble == 0x9,
	 * hir[] is not used and - coincidentally - the salt's hi nibble is
	 * 0x09 regardless of the offset.
	 */
	static const u8 hio[16] = {0, 11, 12, 6, 7, 5, 1, 4,
				   3, 0x00, 14, 13, 8, 9, 10, 2};

	const u8 ln = idx & 0xf;
	const u8 hn = (idx >> 4) & 0xf;
	const u8 hr = (hn == 0x9) ? 0x9 : hir[(hio[hn] + off) % 15];

	if (len[ln] < off)
		return 0x00;

	return ((nib[14 + off - len[ln]]) | (hr << 4));
}

__attribute__((used)) static void dot_encode_step(struct dot_state *state, __be32 *const buffer)
{
	u8 * const data = (u8 *) buffer;

	if (data[MAGIC_DOT_BYTE] != 0x00) {
		state->off = 0;
		state->idx = data[MAGIC_DOT_BYTE] ^ state->carry;
	}
	data[MAGIC_DOT_BYTE] ^= state->carry;
	state->carry = dot_scrt(state->idx, ++(state->off));
}

int amdtp_dot_set_parameters(struct amdtp_stream *s, unsigned int rate,
			     unsigned int pcm_channels)
{
	struct amdtp_dot *p = s->protocol;
	int err;

	if (amdtp_stream_running(s))
		return -EBUSY;

	/*
	 * A first data channel is for MIDI messages, the rest is Multi Bit
	 * Linear Audio data channel.
	 */
	err = amdtp_stream_set_parameters(s, rate, pcm_channels + 1);
	if (err < 0)
		return err;

	s->fdf = AMDTP_FDF_AM824 | s->sfc;

	p->pcm_channels = pcm_channels;

	/*
	 * We do not know the actual MIDI FIFO size of most devices.  Just
	 * assume two bytes, i.e., one byte can be received over the bus while
	 * the previous one is transmitted over MIDI.
	 * (The value here is adjusted for midi_ratelimit_per_packet().)
	 */
	p->midi_fifo_limit = rate - MIDI_BYTES_PER_SECOND * s->syt_interval + 1;

	return 0;
}

__attribute__((used)) static void write_pcm_s32(struct amdtp_stream *s, struct snd_pcm_substream *pcm,
			  __be32 *buffer, unsigned int frames)
{
	struct amdtp_dot *p = s->protocol;
	struct snd_pcm_runtime *runtime = pcm->runtime;
	unsigned int channels, remaining_frames, i, c;
	const u32 *src;

	channels = p->pcm_channels;
	src = (void *)runtime->dma_area +
			frames_to_bytes(runtime, s->pcm_buffer_pointer);
	remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;

	buffer++;
	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c) {
			buffer[c] = cpu_to_be32((*src >> 8) | 0x40000000);
			dot_encode_step(&p->state, &buffer[c]);
			src++;
		}
		buffer += s->data_block_quadlets;
		if (--remaining_frames == 0)
			src = (void *)runtime->dma_area;
	}
}

__attribute__((used)) static void read_pcm_s32(struct amdtp_stream *s, struct snd_pcm_substream *pcm,
			 __be32 *buffer, unsigned int frames)
{
	struct amdtp_dot *p = s->protocol;
	struct snd_pcm_runtime *runtime = pcm->runtime;
	unsigned int channels, remaining_frames, i, c;
	u32 *dst;

	channels = p->pcm_channels;
	dst  = (void *)runtime->dma_area +
			frames_to_bytes(runtime, s->pcm_buffer_pointer);
	remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;

	buffer++;
	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c) {
			*dst = be32_to_cpu(buffer[c]) << 8;
			dst++;
		}
		buffer += s->data_block_quadlets;
		if (--remaining_frames == 0)
			dst = (void *)runtime->dma_area;
	}
}

__attribute__((used)) static void write_pcm_silence(struct amdtp_stream *s, __be32 *buffer,
			      unsigned int data_blocks)
{
	struct amdtp_dot *p = s->protocol;
	unsigned int channels, i, c;

	channels = p->pcm_channels;

	buffer++;
	for (i = 0; i < data_blocks; ++i) {
		for (c = 0; c < channels; ++c)
			buffer[c] = cpu_to_be32(0x40000000);
		buffer += s->data_block_quadlets;
	}
}

__attribute__((used)) static bool midi_ratelimit_per_packet(struct amdtp_stream *s, unsigned int port)
{
	struct amdtp_dot *p = s->protocol;
	int used;

	used = p->midi_fifo_used[port];
	if (used == 0)
		return true;

	used -= MIDI_BYTES_PER_SECOND * s->syt_interval;
	used = max(used, 0);
	p->midi_fifo_used[port] = used;

	return used < p->midi_fifo_limit;
}

__attribute__((used)) static inline void midi_use_bytes(struct amdtp_stream *s,
				  unsigned int port, unsigned int count)
{
	struct amdtp_dot *p = s->protocol;

	p->midi_fifo_used[port] += amdtp_rate_table[s->sfc] * count;
}

__attribute__((used)) static void write_midi_messages(struct amdtp_stream *s, __be32 *buffer,
				unsigned int data_blocks)
{
	struct amdtp_dot *p = s->protocol;
	unsigned int f, port;
	int len;
	u8 *b;

	for (f = 0; f < data_blocks; f++) {
		port = (s->data_block_counter + f) % 8;
		b = (u8 *)&buffer[0];

		len = 0;
		if (port < MAX_MIDI_PORTS &&
		    midi_ratelimit_per_packet(s, port) &&
		    p->midi[port] != NULL)
			len = snd_rawmidi_transmit(p->midi[port], b + 1, 2);

		if (len > 0) {
			/*
			 * Upper 4 bits of LSB represent port number.
			 * - 0000b: physical MIDI port 1.
			 * - 0010b: physical MIDI port 2.
			 * - 1110b: console MIDI port.
			 */
			if (port == 2)
				b[3] = 0xe0;
			else if (port == 1)
				b[3] = 0x20;
			else
				b[3] = 0x00;
			b[3] |= len;
			midi_use_bytes(s, port, len);
		} else {
			b[1] = 0;
			b[2] = 0;
			b[3] = 0;
		}
		b[0] = 0x80;

		buffer += s->data_block_quadlets;
	}
}

__attribute__((used)) static void read_midi_messages(struct amdtp_stream *s, __be32 *buffer,
			       unsigned int data_blocks)
{
	struct amdtp_dot *p = s->protocol;
	unsigned int f, port, len;
	u8 *b;

	for (f = 0; f < data_blocks; f++) {
		b = (u8 *)&buffer[0];

		len = b[3] & 0x0f;
		if (len > 0) {
			/*
			 * Upper 4 bits of LSB represent port number.
			 * - 0000b: physical MIDI port 1. Use port 0.
			 * - 1110b: console MIDI port. Use port 2.
			 */
			if (b[3] >> 4 > 0)
				port = 2;
			else
				port = 0;

			if (port < MAX_MIDI_PORTS && p->midi[port])
				snd_rawmidi_receive(p->midi[port], b + 1, len);
		}

		buffer += s->data_block_quadlets;
	}
}

int amdtp_dot_add_pcm_hw_constraints(struct amdtp_stream *s,
				     struct snd_pcm_runtime *runtime)
{
	int err;

	/* This protocol delivers 24 bit data in 32bit data channel. */
	err = snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
	if (err < 0)
		return err;

	return amdtp_stream_add_pcm_hw_constraints(s, runtime);
}

void amdtp_dot_midi_trigger(struct amdtp_stream *s, unsigned int port,
			  struct snd_rawmidi_substream *midi)
{
	struct amdtp_dot *p = s->protocol;

	if (port < MAX_MIDI_PORTS)
		WRITE_ONCE(p->midi[port], midi);
}

__attribute__((used)) static unsigned int process_tx_data_blocks(struct amdtp_stream *s,
					   __be32 *buffer,
					   unsigned int data_blocks,
					   unsigned int *syt)
{
	struct snd_pcm_substream *pcm;
	unsigned int pcm_frames;

	pcm = READ_ONCE(s->pcm);
	if (pcm) {
		read_pcm_s32(s, pcm, buffer, data_blocks);
		pcm_frames = data_blocks;
	} else {
		pcm_frames = 0;
	}

	read_midi_messages(s, buffer, data_blocks);

	return pcm_frames;
}

__attribute__((used)) static unsigned int process_rx_data_blocks(struct amdtp_stream *s,
					   __be32 *buffer,
					   unsigned int data_blocks,
					   unsigned int *syt)
{
	struct snd_pcm_substream *pcm;
	unsigned int pcm_frames;

	pcm = READ_ONCE(s->pcm);
	if (pcm) {
		write_pcm_s32(s, pcm, buffer, data_blocks);
		pcm_frames = data_blocks;
	} else {
		write_pcm_silence(s, buffer, data_blocks);
		pcm_frames = 0;
	}

	write_midi_messages(s, buffer, data_blocks);

	return pcm_frames;
}

int amdtp_dot_init(struct amdtp_stream *s, struct fw_unit *unit,
		 enum amdtp_stream_direction dir)
{
	amdtp_stream_process_data_blocks_t process_data_blocks;
	enum cip_flags flags;

	/* Use different mode between incoming/outgoing. */
	if (dir == AMDTP_IN_STREAM) {
		flags = CIP_NONBLOCKING;
		process_data_blocks = process_tx_data_blocks;
	} else {
		flags = CIP_BLOCKING;
		process_data_blocks = process_rx_data_blocks;
	}

	return amdtp_stream_init(s, unit, dir, flags, CIP_FMT_AM,
				 process_data_blocks, sizeof(struct amdtp_dot));
}

void amdtp_dot_reset(struct amdtp_stream *s)
{
	struct amdtp_dot *p = s->protocol;

	p->state.carry = 0x00;
	p->state.idx = 0x00;
	p->state.off = 0;
}


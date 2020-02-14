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
typedef  int /*<<< orphan*/  u32 ;
struct snd_rawmidi_substream {int dummy; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {unsigned int buffer_size; scalar_t__ dma_area; } ;
struct snd_fw_async_midi_port {int error; int /*<<< orphan*/  work; struct snd_rawmidi_substream* substream; } ;
struct fw_unit {int dummy; } ;
struct amdtp_tscm {unsigned int pcm_channels; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; scalar_t__ direction; unsigned int pcm_buffer_pointer; int fdf; struct amdtp_tscm* protocol; int /*<<< orphan*/  pcm; int /*<<< orphan*/  data_block_quadlets; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  context; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum amdtp_stream_direction { ____Placeholder_amdtp_stream_direction } amdtp_stream_direction ;
typedef  unsigned int (* amdtp_stream_process_data_blocks_t ) (struct amdtp_stream*,int*,unsigned int,unsigned int*) ;
typedef  int __be32 ;

/* Variables and functions */
 unsigned int AMDTP_FMT_TSCM_RX ; 
 unsigned int AMDTP_FMT_TSCM_TX ; 
 scalar_t__ AMDTP_IN_STREAM ; 
 int CIP_NONBLOCKING ; 
 int CIP_SKIP_DBC_ZERO_CHECK ; 
 int EBUSY ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 struct snd_pcm_substream* READ_ONCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int amdtp_stream_add_pcm_hw_constraints (struct amdtp_stream*,struct snd_pcm_runtime*) ; 
 int amdtp_stream_init (struct amdtp_stream*,struct fw_unit*,int,int,unsigned int,unsigned int (*) (struct amdtp_stream*,int*,unsigned int,unsigned int*),int) ; 
 int amdtp_stream_set_parameters (struct amdtp_stream*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  be32_to_cpu (int) ; 
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 int cpu_to_be32 (int /*<<< orphan*/  const) ; 
 int frames_to_bytes (struct snd_pcm_runtime*,unsigned int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int snd_pcm_hw_constraint_msbits (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int,int) ; 
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

int amdtp_tscm_set_parameters(struct amdtp_stream *s, unsigned int rate)
{
	struct amdtp_tscm *p = s->protocol;
	unsigned int data_channels;

	if (amdtp_stream_running(s))
		return -EBUSY;

	data_channels = p->pcm_channels;

	/* Packets in in-stream have extra 2 data channels. */
	if (s->direction == AMDTP_IN_STREAM)
		data_channels += 2;

	return amdtp_stream_set_parameters(s, rate, data_channels);
}

__attribute__((used)) static void write_pcm_s32(struct amdtp_stream *s,
			  struct snd_pcm_substream *pcm,
			  __be32 *buffer, unsigned int frames)
{
	struct amdtp_tscm *p = s->protocol;
	struct snd_pcm_runtime *runtime = pcm->runtime;
	unsigned int channels, remaining_frames, i, c;
	const u32 *src;

	channels = p->pcm_channels;
	src = (void *)runtime->dma_area +
			frames_to_bytes(runtime, s->pcm_buffer_pointer);
	remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;

	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c) {
			buffer[c] = cpu_to_be32(*src);
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
	struct amdtp_tscm *p = s->protocol;
	struct snd_pcm_runtime *runtime = pcm->runtime;
	unsigned int channels, remaining_frames, i, c;
	u32 *dst;

	channels = p->pcm_channels;
	dst  = (void *)runtime->dma_area +
			frames_to_bytes(runtime, s->pcm_buffer_pointer);
	remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;

	/* The first data channel is for event counter. */
	buffer += 1;

	for (i = 0; i < frames; ++i) {
		for (c = 0; c < channels; ++c) {
			*dst = be32_to_cpu(buffer[c]);
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
	struct amdtp_tscm *p = s->protocol;
	unsigned int channels, i, c;

	channels = p->pcm_channels;

	for (i = 0; i < data_blocks; ++i) {
		for (c = 0; c < channels; ++c)
			buffer[c] = 0x00000000;
		buffer += s->data_block_quadlets;
	}
}

int amdtp_tscm_add_pcm_hw_constraints(struct amdtp_stream *s,
				      struct snd_pcm_runtime *runtime)
{
	int err;

	/*
	 * Our implementation allows this protocol to deliver 24 bit sample in
	 * 32bit data channel.
	 */
	err = snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
	if (err < 0)
		return err;

	return amdtp_stream_add_pcm_hw_constraints(s, runtime);
}

__attribute__((used)) static unsigned int process_tx_data_blocks(struct amdtp_stream *s,
					   __be32 *buffer,
					   unsigned int data_blocks,
					   unsigned int *syt)
{
	struct snd_pcm_substream *pcm;

	pcm = READ_ONCE(s->pcm);
	if (data_blocks > 0 && pcm)
		read_pcm_s32(s, pcm, buffer, data_blocks);

	/* A place holder for control messages. */

	return data_blocks;
}

__attribute__((used)) static unsigned int process_rx_data_blocks(struct amdtp_stream *s,
					   __be32 *buffer,
					   unsigned int data_blocks,
					   unsigned int *syt)
{
	struct snd_pcm_substream *pcm;

	/* This field is not used. */
	*syt = 0x0000;

	pcm = READ_ONCE(s->pcm);
	if (pcm)
		write_pcm_s32(s, pcm, buffer, data_blocks);
	else
		write_pcm_silence(s, buffer, data_blocks);

	return data_blocks;
}

int amdtp_tscm_init(struct amdtp_stream *s, struct fw_unit *unit,
		    enum amdtp_stream_direction dir, unsigned int pcm_channels)
{
	amdtp_stream_process_data_blocks_t process_data_blocks;
	struct amdtp_tscm *p;
	unsigned int fmt;
	int err;

	if (dir == AMDTP_IN_STREAM) {
		fmt = AMDTP_FMT_TSCM_TX;
		process_data_blocks = process_tx_data_blocks;
	} else {
		fmt = AMDTP_FMT_TSCM_RX;
		process_data_blocks = process_rx_data_blocks;
	}

	err = amdtp_stream_init(s, unit, dir,
				CIP_NONBLOCKING | CIP_SKIP_DBC_ZERO_CHECK, fmt,
				process_data_blocks, sizeof(struct amdtp_tscm));
	if (err < 0)
		return 0;

	/* Use fixed value for FDF field. */
	s->fdf = 0x00;

	/* This protocol uses fixed number of data channels for PCM samples. */
	p = s->protocol;
	p->pcm_channels = pcm_channels;

	return 0;
}


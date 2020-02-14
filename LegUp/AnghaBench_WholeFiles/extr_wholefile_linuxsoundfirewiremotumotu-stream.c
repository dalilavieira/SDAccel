#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_motu_protocol {int (* switch_fetching_mode ) (struct snd_motu*,int) ;int (* cache_packet_formats ) (struct snd_motu*) ;int (* get_clock_rate ) (struct snd_motu*,unsigned int*) ;int (* set_clock_rate ) (struct snd_motu*,unsigned int) ;} ;
struct fw_iso_resources {int channel; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
struct TYPE_10__ {int midi_flag_offset; int midi_byte_offset; scalar_t__* differed_part_pcm_chunks; } ;
struct snd_motu {scalar_t__ capture_substreams; scalar_t__ playback_substreams; int dev_lock_changed; scalar_t__ dev_lock_count; int /*<<< orphan*/  lock; int /*<<< orphan*/  hwdep_wait; struct fw_iso_resources rx_resources; struct amdtp_stream rx_stream; struct fw_iso_resources tx_resources; struct amdtp_stream tx_stream; TYPE_1__* spec; TYPE_3__* unit; TYPE_5__ rx_packet_formats; TYPE_5__ tx_packet_formats; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum amdtp_stream_direction { ____Placeholder_amdtp_stream_direction } amdtp_stream_direction ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_9__ {int /*<<< orphan*/  device; } ;
struct TYPE_8__ {int max_speed; } ;
struct TYPE_7__ {int flags; struct snd_motu_protocol* protocol; } ;

/* Variables and functions */
 int AMDTP_IN_STREAM ; 
 int AMDTP_OUT_STREAM ; 
 unsigned int CALLBACK_TIMEOUT ; 
 int CHANGE_RX_ISOC_COMM_STATE ; 
 int CHANGE_TX_ISOC_COMM_STATE ; 
 int EBUSY ; 
 int ETIMEDOUT ; 
 int ISOC_COMM_CONTROL_MASK ; 
 int /*<<< orphan*/  ISOC_COMM_CONTROL_OFFSET ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PACKET_FORMAT_OFFSET ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int RX_ISOC_COMM_CHANNEL_SHIFT ; 
 int RX_ISOC_COMM_IS_ACTIVATED ; 
 int RX_PACKET_EXCLUDE_DIFFERED_DATA_CHUNKS ; 
 int SND_MOTU_SPEC_RX_MIDI_2ND_Q ; 
 int SND_MOTU_SPEC_RX_MIDI_3RD_Q ; 
 int SND_MOTU_SPEC_TX_MIDI_2ND_Q ; 
 int SND_MOTU_SPEC_TX_MIDI_3RD_Q ; 
 int TX_ISOC_COMM_CHANNEL_SHIFT ; 
 int TX_ISOC_COMM_IS_ACTIVATED ; 
 int TX_PACKET_EXCLUDE_DIFFERED_DATA_CHUNKS ; 
 int TX_PACKET_TRANSMISSION_SPEED_MASK ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int amdtp_motu_init (struct amdtp_stream*,TYPE_3__*,int,struct snd_motu_protocol*) ; 
 int amdtp_motu_set_parameters (struct amdtp_stream*,unsigned int,unsigned int,TYPE_5__*) ; 
 int /*<<< orphan*/  amdtp_stream_destroy (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_get_max_payload (struct amdtp_stream*) ; 
 int amdtp_stream_start (struct amdtp_stream*,int,int) ; 
 int /*<<< orphan*/  amdtp_stream_stop (struct amdtp_stream*) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int fw_iso_resources_allocate (struct fw_iso_resources*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fw_iso_resources_destroy (struct fw_iso_resources*) ; 
 int /*<<< orphan*/  fw_iso_resources_free (struct fw_iso_resources*) ; 
 int fw_iso_resources_init (struct fw_iso_resources*,TYPE_3__*) ; 
 TYPE_2__* fw_parent_device (TYPE_3__*) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_motu_transaction_read (struct snd_motu*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int snd_motu_transaction_write (struct snd_motu*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int stub1 (struct snd_motu*,int) ; 
 int stub2 (struct snd_motu*) ; 
 int stub3 (struct snd_motu*,unsigned int*) ; 
 int stub4 (struct snd_motu*,unsigned int) ; 
 int stub5 (struct snd_motu*,int) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static int start_both_streams(struct snd_motu *motu, unsigned int rate)
{
	unsigned int midi_ports = 0;
	__be32 reg;
	u32 data;
	int err;

	if ((motu->spec->flags & SND_MOTU_SPEC_RX_MIDI_2ND_Q) ||
	    (motu->spec->flags & SND_MOTU_SPEC_RX_MIDI_3RD_Q))
		midi_ports = 1;

	/* Set packet formation to our packet streaming engine. */
	err = amdtp_motu_set_parameters(&motu->rx_stream, rate, midi_ports,
					&motu->rx_packet_formats);
	if (err < 0)
		return err;

	if ((motu->spec->flags & SND_MOTU_SPEC_TX_MIDI_2ND_Q) ||
	    (motu->spec->flags & SND_MOTU_SPEC_TX_MIDI_3RD_Q))
		midi_ports = 1;
	else
		midi_ports = 0;

	err = amdtp_motu_set_parameters(&motu->tx_stream, rate, midi_ports,
					&motu->tx_packet_formats);
	if (err < 0)
		return err;

	/* Get isochronous resources on the bus. */
	err = fw_iso_resources_allocate(&motu->rx_resources,
				amdtp_stream_get_max_payload(&motu->rx_stream),
				fw_parent_device(motu->unit)->max_speed);
	if (err < 0)
		return err;

	err = fw_iso_resources_allocate(&motu->tx_resources,
				amdtp_stream_get_max_payload(&motu->tx_stream),
				fw_parent_device(motu->unit)->max_speed);
	if (err < 0)
		return err;

	/* Configure the unit to start isochronous communication. */
	err = snd_motu_transaction_read(motu, ISOC_COMM_CONTROL_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg) & ~ISOC_COMM_CONTROL_MASK;

	data |= CHANGE_RX_ISOC_COMM_STATE | RX_ISOC_COMM_IS_ACTIVATED |
		(motu->rx_resources.channel << RX_ISOC_COMM_CHANNEL_SHIFT) |
		CHANGE_TX_ISOC_COMM_STATE | TX_ISOC_COMM_IS_ACTIVATED |
		(motu->tx_resources.channel << TX_ISOC_COMM_CHANNEL_SHIFT);

	reg = cpu_to_be32(data);
	return snd_motu_transaction_write(motu, ISOC_COMM_CONTROL_OFFSET, &reg,
					  sizeof(reg));
}

__attribute__((used)) static void stop_both_streams(struct snd_motu *motu)
{
	__be32 reg;
	u32 data;
	int err;

	err = motu->spec->protocol->switch_fetching_mode(motu, false);
	if (err < 0)
		return;

	err = snd_motu_transaction_read(motu, ISOC_COMM_CONTROL_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return;
	data = be32_to_cpu(reg);

	data &= ~(RX_ISOC_COMM_IS_ACTIVATED | TX_ISOC_COMM_IS_ACTIVATED);
	data |= CHANGE_RX_ISOC_COMM_STATE | CHANGE_TX_ISOC_COMM_STATE;

	reg = cpu_to_be32(data);
	snd_motu_transaction_write(motu, ISOC_COMM_CONTROL_OFFSET, &reg,
				   sizeof(reg));

	fw_iso_resources_free(&motu->tx_resources);
	fw_iso_resources_free(&motu->rx_resources);
}

__attribute__((used)) static int start_isoc_ctx(struct snd_motu *motu, struct amdtp_stream *stream)
{
	struct fw_iso_resources *resources;
	int err;

	if (stream == &motu->rx_stream)
		resources = &motu->rx_resources;
	else
		resources = &motu->tx_resources;

	err = amdtp_stream_start(stream, resources->channel,
				 fw_parent_device(motu->unit)->max_speed);
	if (err < 0)
		return err;

	if (!amdtp_stream_wait_callback(stream, CALLBACK_TIMEOUT)) {
		amdtp_stream_stop(stream);
		fw_iso_resources_free(resources);
		return -ETIMEDOUT;
	}

	return 0;
}

__attribute__((used)) static void stop_isoc_ctx(struct snd_motu *motu, struct amdtp_stream *stream)
{
	struct fw_iso_resources *resources;

	if (stream == &motu->rx_stream)
		resources = &motu->rx_resources;
	else
		resources = &motu->tx_resources;

	amdtp_stream_stop(stream);
	fw_iso_resources_free(resources);
}

int snd_motu_stream_cache_packet_formats(struct snd_motu *motu)
{
	int err;

	err = motu->spec->protocol->cache_packet_formats(motu);
	if (err < 0)
		return err;

	if (motu->spec->flags & SND_MOTU_SPEC_TX_MIDI_2ND_Q) {
		motu->tx_packet_formats.midi_flag_offset = 4;
		motu->tx_packet_formats.midi_byte_offset = 6;
	} else if (motu->spec->flags & SND_MOTU_SPEC_TX_MIDI_3RD_Q) {
		motu->tx_packet_formats.midi_flag_offset = 8;
		motu->tx_packet_formats.midi_byte_offset = 7;
	}

	if (motu->spec->flags & SND_MOTU_SPEC_RX_MIDI_2ND_Q) {
		motu->rx_packet_formats.midi_flag_offset = 4;
		motu->rx_packet_formats.midi_byte_offset = 6;
	} else if (motu->spec->flags & SND_MOTU_SPEC_RX_MIDI_3RD_Q) {
		motu->rx_packet_formats.midi_flag_offset = 8;
		motu->rx_packet_formats.midi_byte_offset = 7;
	}

	return 0;
}

__attribute__((used)) static int ensure_packet_formats(struct snd_motu *motu)
{
	__be32 reg;
	u32 data;
	int err;

	err = snd_motu_transaction_read(motu, PACKET_FORMAT_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	data &= ~(TX_PACKET_EXCLUDE_DIFFERED_DATA_CHUNKS |
		  RX_PACKET_EXCLUDE_DIFFERED_DATA_CHUNKS|
		  TX_PACKET_TRANSMISSION_SPEED_MASK);
	if (motu->tx_packet_formats.differed_part_pcm_chunks[0] == 0)
		data |= TX_PACKET_EXCLUDE_DIFFERED_DATA_CHUNKS;
	if (motu->rx_packet_formats.differed_part_pcm_chunks[0] == 0)
		data |= RX_PACKET_EXCLUDE_DIFFERED_DATA_CHUNKS;
	data |= fw_parent_device(motu->unit)->max_speed;

	reg = cpu_to_be32(data);
	return snd_motu_transaction_write(motu, PACKET_FORMAT_OFFSET, &reg,
					  sizeof(reg));
}

int snd_motu_stream_start_duplex(struct snd_motu *motu, unsigned int rate)
{
	const struct snd_motu_protocol *protocol = motu->spec->protocol;
	unsigned int curr_rate;
	int err = 0;

	if (motu->capture_substreams == 0 && motu->playback_substreams == 0)
		return 0;

	/* Some packet queueing errors. */
	if (amdtp_streaming_error(&motu->rx_stream) ||
	    amdtp_streaming_error(&motu->tx_stream)) {
		amdtp_stream_stop(&motu->rx_stream);
		amdtp_stream_stop(&motu->tx_stream);
		stop_both_streams(motu);
	}

	err = snd_motu_stream_cache_packet_formats(motu);
	if (err < 0)
		return err;

	/* Stop stream if rate is different. */
	err = protocol->get_clock_rate(motu, &curr_rate);
	if (err < 0) {
		dev_err(&motu->unit->device,
			"fail to get sampling rate: %d\n", err);
		return err;
	}
	if (rate == 0)
		rate = curr_rate;
	if (rate != curr_rate) {
		amdtp_stream_stop(&motu->rx_stream);
		amdtp_stream_stop(&motu->tx_stream);
		stop_both_streams(motu);
	}

	if (!amdtp_stream_running(&motu->rx_stream)) {
		err = protocol->set_clock_rate(motu, rate);
		if (err < 0) {
			dev_err(&motu->unit->device,
				"fail to set sampling rate: %d\n", err);
			return err;
		}

		err = ensure_packet_formats(motu);
		if (err < 0)
			return err;

		err = start_both_streams(motu, rate);
		if (err < 0) {
			dev_err(&motu->unit->device,
				"fail to start isochronous comm: %d\n", err);
			goto stop_streams;
		}

		err = start_isoc_ctx(motu, &motu->rx_stream);
		if (err < 0) {
			dev_err(&motu->unit->device,
				"fail to start IT context: %d\n", err);
			goto stop_streams;
		}

		err = protocol->switch_fetching_mode(motu, true);
		if (err < 0) {
			dev_err(&motu->unit->device,
				"fail to enable frame fetching: %d\n", err);
			goto stop_streams;
		}
	}

	if (!amdtp_stream_running(&motu->tx_stream) &&
	    motu->capture_substreams > 0) {
		err = start_isoc_ctx(motu, &motu->tx_stream);
		if (err < 0) {
			dev_err(&motu->unit->device,
				"fail to start IR context: %d", err);
			amdtp_stream_stop(&motu->rx_stream);
			goto stop_streams;
		}
	}

	return 0;

stop_streams:
	stop_both_streams(motu);
	return err;
}

void snd_motu_stream_stop_duplex(struct snd_motu *motu)
{
	if (motu->capture_substreams == 0) {
		if (amdtp_stream_running(&motu->tx_stream))
			stop_isoc_ctx(motu, &motu->tx_stream);

		if (motu->playback_substreams == 0) {
			if (amdtp_stream_running(&motu->rx_stream))
				stop_isoc_ctx(motu, &motu->rx_stream);
			stop_both_streams(motu);
		}
	}
}

__attribute__((used)) static int init_stream(struct snd_motu *motu, enum amdtp_stream_direction dir)
{
	int err;
	struct amdtp_stream *stream;
	struct fw_iso_resources *resources;

	if (dir == AMDTP_IN_STREAM) {
		stream = &motu->tx_stream;
		resources = &motu->tx_resources;
	} else {
		stream = &motu->rx_stream;
		resources = &motu->rx_resources;
	}

	err = fw_iso_resources_init(resources, motu->unit);
	if (err < 0)
		return err;

	err = amdtp_motu_init(stream, motu->unit, dir, motu->spec->protocol);
	if (err < 0) {
		amdtp_stream_destroy(stream);
		fw_iso_resources_destroy(resources);
	}

	return err;
}

__attribute__((used)) static void destroy_stream(struct snd_motu *motu,
			   enum amdtp_stream_direction dir)
{
	struct amdtp_stream *stream;
	struct fw_iso_resources *resources;

	if (dir == AMDTP_IN_STREAM) {
		stream = &motu->tx_stream;
		resources = &motu->tx_resources;
	} else {
		stream = &motu->rx_stream;
		resources = &motu->rx_resources;
	}

	amdtp_stream_destroy(stream);
	fw_iso_resources_free(resources);
}

int snd_motu_stream_init_duplex(struct snd_motu *motu)
{
	int err;

	err = init_stream(motu, AMDTP_IN_STREAM);
	if (err < 0)
		return err;

	err = init_stream(motu, AMDTP_OUT_STREAM);
	if (err < 0)
		destroy_stream(motu, AMDTP_IN_STREAM);

	return err;
}

void snd_motu_stream_destroy_duplex(struct snd_motu *motu)
{
	destroy_stream(motu, AMDTP_IN_STREAM);
	destroy_stream(motu, AMDTP_OUT_STREAM);

	motu->playback_substreams = 0;
	motu->capture_substreams = 0;
}

__attribute__((used)) static void motu_lock_changed(struct snd_motu *motu)
{
	motu->dev_lock_changed = true;
	wake_up(&motu->hwdep_wait);
}

int snd_motu_stream_lock_try(struct snd_motu *motu)
{
	int err;

	spin_lock_irq(&motu->lock);

	if (motu->dev_lock_count < 0) {
		err = -EBUSY;
		goto out;
	}

	if (motu->dev_lock_count++ == 0)
		motu_lock_changed(motu);
	err = 0;
out:
	spin_unlock_irq(&motu->lock);
	return err;
}

void snd_motu_stream_lock_release(struct snd_motu *motu)
{
	spin_lock_irq(&motu->lock);

	if (WARN_ON(motu->dev_lock_count <= 0))
		goto out;

	if (--motu->dev_lock_count == 0)
		motu_lock_changed(motu);
out:
	spin_unlock_irq(&motu->lock);
}


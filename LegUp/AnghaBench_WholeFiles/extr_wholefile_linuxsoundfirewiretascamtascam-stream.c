#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
struct TYPE_9__ {int channel; } ;
struct snd_tscm {scalar_t__ substreams_counter; int dev_lock_changed; scalar_t__ dev_lock_count; int /*<<< orphan*/  lock; int /*<<< orphan*/  hwdep_wait; struct amdtp_stream rx_stream; struct amdtp_stream tx_stream; int /*<<< orphan*/  unit; TYPE_3__ tx_resources; TYPE_3__ rx_resources; TYPE_1__* spec; } ;
struct snd_rawmidi_substream {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_fw_async_midi_port {int error; int /*<<< orphan*/  work; struct snd_rawmidi_substream* substream; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  enum snd_tscm_clock { ____Placeholder_snd_tscm_clock } snd_tscm_clock ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  scalar_t__ __be32 ;
struct TYPE_8__ {int /*<<< orphan*/  max_speed; } ;
struct TYPE_7__ {unsigned int pcm_capture_analog_channels; unsigned int pcm_playback_analog_channels; scalar_t__ has_spdif; scalar_t__ has_adat; } ;

/* Variables and functions */
 int /*<<< orphan*/  AMDTP_IN_STREAM ; 
 int /*<<< orphan*/  AMDTP_OUT_STREAM ; 
 int BIT (unsigned int) ; 
 unsigned int CALLBACK_TIMEOUT ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EIO ; 
 int ETIMEDOUT ; 
 int INT_MAX ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int SND_TSCM_CLOCK_ADAT ; 
 int /*<<< orphan*/  TCODE_READ_QUADLET_REQUEST ; 
 int /*<<< orphan*/  TCODE_WRITE_QUADLET_REQUEST ; 
 scalar_t__ TSCM_ADDR_BASE ; 
 scalar_t__ TSCM_OFFSET_CLOCK_STATUS ; 
 scalar_t__ TSCM_OFFSET_ISOC_RX_CH ; 
 scalar_t__ TSCM_OFFSET_ISOC_RX_ON ; 
 scalar_t__ TSCM_OFFSET_ISOC_TX_CH ; 
 scalar_t__ TSCM_OFFSET_ISOC_TX_ON ; 
 scalar_t__ TSCM_OFFSET_MULTIPLEX_MODE ; 
 scalar_t__ TSCM_OFFSET_RX_PCM_CHANNELS ; 
 scalar_t__ TSCM_OFFSET_SET_OPTION ; 
 scalar_t__ TSCM_OFFSET_START_STREAMING ; 
 scalar_t__ TSCM_OFFSET_TX_PCM_CHANNELS ; 
 scalar_t__ TSCM_OFFSET_UNKNOWN ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  amdtp_stream_destroy (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_get_max_payload (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_pcm_abort (struct amdtp_stream*) ; 
 int amdtp_stream_start (struct amdtp_stream*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amdtp_stream_stop (struct amdtp_stream*) ; 
 int amdtp_tscm_init (struct amdtp_stream*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int amdtp_tscm_set_parameters (struct amdtp_stream*,unsigned int) ; 
 int be32_to_cpu (scalar_t__) ; 
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_to_be32 (int) ; 
 int fw_iso_resources_allocate (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fw_iso_resources_destroy (TYPE_3__*) ; 
 int /*<<< orphan*/  fw_iso_resources_free (TYPE_3__*) ; 
 int fw_iso_resources_init (TYPE_3__*,int /*<<< orphan*/ ) ; 
 TYPE_2__* fw_parent_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int snd_fw_transaction (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,scalar_t__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
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

__attribute__((used)) static int get_clock(struct snd_tscm *tscm, u32 *data)
{
	__be32 reg;
	int err;

	err = snd_fw_transaction(tscm->unit, TCODE_READ_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_CLOCK_STATUS,
				 &reg, sizeof(reg), 0);
	if (err >= 0)
		*data = be32_to_cpu(reg);

	return err;
}

__attribute__((used)) static int set_clock(struct snd_tscm *tscm, unsigned int rate,
		     enum snd_tscm_clock clock)
{
	u32 data;
	__be32 reg;
	int err;

	err = get_clock(tscm, &data);
	if (err < 0)
		return err;
	data &= 0x0000ffff;

	if (rate > 0) {
		data &= 0x000000ff;
		/* Base rate. */
		if ((rate % 44100) == 0) {
			data |= 0x00000100;
			/* Multiplier. */
			if (rate / 44100 == 2)
				data |= 0x00008000;
		} else if ((rate % 48000) == 0) {
			data |= 0x00000200;
			/* Multiplier. */
			if (rate / 48000 == 2)
				data |= 0x00008000;
		} else {
			return -EAGAIN;
		}
	}

	if (clock != INT_MAX) {
		data &= 0x0000ff00;
		data |= clock + 1;
	}

	reg = cpu_to_be32(data);

	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_CLOCK_STATUS,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	if (data & 0x00008000)
		reg = cpu_to_be32(0x0000001a);
	else
		reg = cpu_to_be32(0x0000000d);

	return snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				  TSCM_ADDR_BASE + TSCM_OFFSET_MULTIPLEX_MODE,
				  &reg, sizeof(reg), 0);
}

int snd_tscm_stream_get_rate(struct snd_tscm *tscm, unsigned int *rate)
{
	u32 data = 0x0;
	unsigned int trials = 0;
	int err;

	while (data == 0x0 || trials++ < 5) {
		err = get_clock(tscm, &data);
		if (err < 0)
			return err;

		data = (data & 0xff000000) >> 24;
	}

	/* Check base rate. */
	if ((data & 0x0f) == 0x01)
		*rate = 44100;
	else if ((data & 0x0f) == 0x02)
		*rate = 48000;
	else
		return -EAGAIN;

	/* Check multiplier. */
	if ((data & 0xf0) == 0x80)
		*rate *= 2;
	else if ((data & 0xf0) != 0x00)
		return -EAGAIN;

	return err;
}

int snd_tscm_stream_get_clock(struct snd_tscm *tscm, enum snd_tscm_clock *clock)
{
	u32 data;
	int err;

	err = get_clock(tscm, &data);
	if (err < 0)
		return err;

	*clock = ((data & 0x00ff0000) >> 16) - 1;
	if (*clock < 0 || *clock > SND_TSCM_CLOCK_ADAT)
		return -EIO;

	return 0;
}

__attribute__((used)) static int enable_data_channels(struct snd_tscm *tscm)
{
	__be32 reg;
	u32 data;
	unsigned int i;
	int err;

	data = 0;
	for (i = 0; i < tscm->spec->pcm_capture_analog_channels; ++i)
		data |= BIT(i);
	if (tscm->spec->has_adat)
		data |= 0x0000ff00;
	if (tscm->spec->has_spdif)
		data |= 0x00030000;

	reg = cpu_to_be32(data);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_TX_PCM_CHANNELS,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	data = 0;
	for (i = 0; i < tscm->spec->pcm_playback_analog_channels; ++i)
		data |= BIT(i);
	if (tscm->spec->has_adat)
		data |= 0x0000ff00;
	if (tscm->spec->has_spdif)
		data |= 0x00030000;

	reg = cpu_to_be32(data);
	return snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				  TSCM_ADDR_BASE + TSCM_OFFSET_RX_PCM_CHANNELS,
				  &reg, sizeof(reg), 0);
}

__attribute__((used)) static int set_stream_formats(struct snd_tscm *tscm, unsigned int rate)
{
	__be32 reg;
	int err;

	/* Set an option for unknown purpose. */
	reg = cpu_to_be32(0x00200000);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_SET_OPTION,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	err = enable_data_channels(tscm);
	if (err < 0)
		return err;

	return set_clock(tscm, rate, INT_MAX);
}

__attribute__((used)) static void finish_session(struct snd_tscm *tscm)
{
	__be32 reg;

	reg = 0;
	snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
			   TSCM_ADDR_BASE + TSCM_OFFSET_START_STREAMING,
			   &reg, sizeof(reg), 0);

	reg = 0;
	snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
			   TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_RX_ON,
			   &reg, sizeof(reg), 0);

}

__attribute__((used)) static int begin_session(struct snd_tscm *tscm)
{
	__be32 reg;
	int err;

	reg = cpu_to_be32(0x00000001);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_START_STREAMING,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	reg = cpu_to_be32(0x00000001);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_RX_ON,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	/* Set an option for unknown purpose. */
	reg = cpu_to_be32(0x00002000);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_SET_OPTION,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	/* Start multiplexing PCM samples on packets. */
	reg = cpu_to_be32(0x00000001);
	return snd_fw_transaction(tscm->unit,
				  TCODE_WRITE_QUADLET_REQUEST,
				  TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_TX_ON,
				  &reg, sizeof(reg), 0);
}

__attribute__((used)) static void release_resources(struct snd_tscm *tscm)
{
	__be32 reg;

	/* Unregister channels. */
	reg = cpu_to_be32(0x00000000);
	snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
			   TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_TX_CH,
			   &reg, sizeof(reg), 0);
	reg = cpu_to_be32(0x00000000);
	snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
			   TSCM_ADDR_BASE + TSCM_OFFSET_UNKNOWN,
			   &reg, sizeof(reg), 0);
	reg = cpu_to_be32(0x00000000);
	snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
			   TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_RX_CH,
			   &reg, sizeof(reg), 0);

	/* Release isochronous resources. */
	fw_iso_resources_free(&tscm->tx_resources);
	fw_iso_resources_free(&tscm->rx_resources);
}

__attribute__((used)) static int keep_resources(struct snd_tscm *tscm, unsigned int rate)
{
	__be32 reg;
	int err;

	/* Keep resources for in-stream. */
	err = amdtp_tscm_set_parameters(&tscm->tx_stream, rate);
	if (err < 0)
		return err;
	err = fw_iso_resources_allocate(&tscm->tx_resources,
			amdtp_stream_get_max_payload(&tscm->tx_stream),
			fw_parent_device(tscm->unit)->max_speed);
	if (err < 0)
		goto error;

	/* Keep resources for out-stream. */
	err = amdtp_tscm_set_parameters(&tscm->rx_stream, rate);
	if (err < 0)
		return err;
	err = fw_iso_resources_allocate(&tscm->rx_resources,
			amdtp_stream_get_max_payload(&tscm->rx_stream),
			fw_parent_device(tscm->unit)->max_speed);
	if (err < 0)
		return err;

	/* Register the isochronous channel for transmitting stream. */
	reg = cpu_to_be32(tscm->tx_resources.channel);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_TX_CH,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		goto error;

	/* Unknown */
	reg = cpu_to_be32(0x00000002);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_UNKNOWN,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		goto error;

	/* Register the isochronous channel for receiving stream. */
	reg = cpu_to_be32(tscm->rx_resources.channel);
	err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
				 TSCM_ADDR_BASE + TSCM_OFFSET_ISOC_RX_CH,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		goto error;

	return 0;
error:
	release_resources(tscm);
	return err;
}

int snd_tscm_stream_init_duplex(struct snd_tscm *tscm)
{
	unsigned int pcm_channels;
	int err;

	/* For out-stream. */
	err = fw_iso_resources_init(&tscm->rx_resources, tscm->unit);
	if (err < 0)
		return err;
	pcm_channels = tscm->spec->pcm_playback_analog_channels;
	if (tscm->spec->has_adat)
		pcm_channels += 8;
	if (tscm->spec->has_spdif)
		pcm_channels += 2;
	err = amdtp_tscm_init(&tscm->rx_stream, tscm->unit, AMDTP_OUT_STREAM,
			      pcm_channels);
	if (err < 0)
		return err;

	/* For in-stream. */
	err = fw_iso_resources_init(&tscm->tx_resources, tscm->unit);
	if (err < 0)
		return err;
	pcm_channels = tscm->spec->pcm_capture_analog_channels;
	if (tscm->spec->has_adat)
		pcm_channels += 8;
	if (tscm->spec->has_spdif)
		pcm_channels += 2;
	err = amdtp_tscm_init(&tscm->tx_stream, tscm->unit, AMDTP_IN_STREAM,
			      pcm_channels);
	if (err < 0)
		amdtp_stream_destroy(&tscm->rx_stream);

	return err;
}

void snd_tscm_stream_update_duplex(struct snd_tscm *tscm)
{
	amdtp_stream_pcm_abort(&tscm->tx_stream);
	amdtp_stream_stop(&tscm->tx_stream);

	amdtp_stream_pcm_abort(&tscm->rx_stream);
	amdtp_stream_stop(&tscm->rx_stream);
}

void snd_tscm_stream_destroy_duplex(struct snd_tscm *tscm)
{
	amdtp_stream_destroy(&tscm->rx_stream);
	amdtp_stream_destroy(&tscm->tx_stream);

	fw_iso_resources_destroy(&tscm->rx_resources);
	fw_iso_resources_destroy(&tscm->tx_resources);
}

int snd_tscm_stream_start_duplex(struct snd_tscm *tscm, unsigned int rate)
{
	unsigned int curr_rate;
	int err;

	if (tscm->substreams_counter == 0)
		return 0;

	err = snd_tscm_stream_get_rate(tscm, &curr_rate);
	if (err < 0)
		return err;
	if (curr_rate != rate ||
	    amdtp_streaming_error(&tscm->rx_stream) ||
	    amdtp_streaming_error(&tscm->tx_stream)) {
		finish_session(tscm);

		amdtp_stream_stop(&tscm->rx_stream);
		amdtp_stream_stop(&tscm->tx_stream);

		release_resources(tscm);
	}

	if (!amdtp_stream_running(&tscm->rx_stream)) {
		err = keep_resources(tscm, rate);
		if (err < 0)
			goto error;

		err = set_stream_formats(tscm, rate);
		if (err < 0)
			goto error;

		err = begin_session(tscm);
		if (err < 0)
			goto error;

		err = amdtp_stream_start(&tscm->rx_stream,
				tscm->rx_resources.channel,
				fw_parent_device(tscm->unit)->max_speed);
		if (err < 0)
			goto error;

		if (!amdtp_stream_wait_callback(&tscm->rx_stream,
						CALLBACK_TIMEOUT)) {
			err = -ETIMEDOUT;
			goto error;
		}
	}

	if (!amdtp_stream_running(&tscm->tx_stream)) {
		err = amdtp_stream_start(&tscm->tx_stream,
				tscm->tx_resources.channel,
				fw_parent_device(tscm->unit)->max_speed);
		if (err < 0)
			goto error;

		if (!amdtp_stream_wait_callback(&tscm->tx_stream,
						CALLBACK_TIMEOUT)) {
			err = -ETIMEDOUT;
			goto error;
		}
	}

	return 0;
error:
	amdtp_stream_stop(&tscm->rx_stream);
	amdtp_stream_stop(&tscm->tx_stream);

	finish_session(tscm);
	release_resources(tscm);

	return err;
}

void snd_tscm_stream_stop_duplex(struct snd_tscm *tscm)
{
	if (tscm->substreams_counter > 0)
		return;

	amdtp_stream_stop(&tscm->tx_stream);
	amdtp_stream_stop(&tscm->rx_stream);

	finish_session(tscm);
	release_resources(tscm);
}

void snd_tscm_stream_lock_changed(struct snd_tscm *tscm)
{
	tscm->dev_lock_changed = true;
	wake_up(&tscm->hwdep_wait);
}

int snd_tscm_stream_lock_try(struct snd_tscm *tscm)
{
	int err;

	spin_lock_irq(&tscm->lock);

	/* user land lock this */
	if (tscm->dev_lock_count < 0) {
		err = -EBUSY;
		goto end;
	}

	/* this is the first time */
	if (tscm->dev_lock_count++ == 0)
		snd_tscm_stream_lock_changed(tscm);
	err = 0;
end:
	spin_unlock_irq(&tscm->lock);
	return err;
}

void snd_tscm_stream_lock_release(struct snd_tscm *tscm)
{
	spin_lock_irq(&tscm->lock);

	if (WARN_ON(tscm->dev_lock_count <= 0))
		goto end;
	if (--tscm->dev_lock_count == 0)
		snd_tscm_stream_lock_changed(tscm);
end:
	spin_unlock_irq(&tscm->lock);
}


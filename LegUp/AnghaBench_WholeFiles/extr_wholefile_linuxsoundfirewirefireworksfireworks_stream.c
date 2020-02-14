#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_pcm_substream {int dummy; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int tx_first_dbc; int tx_dbc_interval; int /*<<< orphan*/  flags; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
struct TYPE_4__ {int /*<<< orphan*/  channel; } ;
struct cmp_connection {scalar_t__ direction; int /*<<< orphan*/  pcr_index; int /*<<< orphan*/  speed; TYPE_1__ resources; } ;
struct snd_efw {unsigned int* pcm_capture_channels; unsigned int midi_out_ports; unsigned int* pcm_playback_channels; unsigned int midi_in_ports; int firmware_version; scalar_t__ playback_substreams; scalar_t__ capture_substreams; int dev_lock_changed; scalar_t__ dev_lock_count; int /*<<< orphan*/  lock; int /*<<< orphan*/  hwdep_wait; struct amdtp_stream tx_stream; struct amdtp_stream rx_stream; struct cmp_connection in_conn; struct cmp_connection out_conn; TYPE_2__* unit; scalar_t__ is_af9; scalar_t__ is_fireworks3; } ;
typedef  enum cmp_direction { ____Placeholder_cmp_direction } cmp_direction ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum amdtp_stream_direction { ____Placeholder_amdtp_stream_direction } amdtp_stream_direction ;
struct TYPE_5__ {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int AMDTP_IN_STREAM ; 
 int AMDTP_OUT_STREAM ; 
 unsigned int CALLBACK_TIMEOUT ; 
 int /*<<< orphan*/  CIP_BLOCKING ; 
 int /*<<< orphan*/  CIP_DBC_IS_END_EVENT ; 
 int /*<<< orphan*/  CIP_EMPTY_WITH_TAG0 ; 
 int /*<<< orphan*/  CIP_SKIP_DBC_ZERO_CHECK ; 
 int /*<<< orphan*/  CIP_WRONG_DBS ; 
 int CMP_INPUT ; 
 scalar_t__ CMP_OUTPUT ; 
 int EBUSY ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int /*<<< orphan*/  SND_EFW_TRANSPORT_MODE_IEC61883 ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int amdtp_am824_init (struct amdtp_stream*,TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int amdtp_am824_set_parameters (struct amdtp_stream*,unsigned int,unsigned int,unsigned int,int) ; 
 int /*<<< orphan*/  amdtp_stream_destroy (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_get_max_payload (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_pcm_abort (struct amdtp_stream*) ; 
 int amdtp_stream_start (struct amdtp_stream*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amdtp_stream_stop (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_update (struct amdtp_stream*) ; 
 int /*<<< orphan*/  cmp_connection_break (struct cmp_connection*) ; 
 int cmp_connection_check_used (struct cmp_connection*,int*) ; 
 int /*<<< orphan*/  cmp_connection_destroy (struct cmp_connection*) ; 
 int cmp_connection_establish (struct cmp_connection*,int /*<<< orphan*/ ) ; 
 int cmp_connection_init (struct cmp_connection*,TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ cmp_connection_update (struct cmp_connection*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_efw_command_get_sampling_rate (struct snd_efw*,unsigned int*) ; 
 int snd_efw_command_set_sampling_rate (struct snd_efw*,unsigned int) ; 
 int snd_efw_command_set_tx_mode (struct snd_efw*,int /*<<< orphan*/ ) ; 
 int snd_efw_get_multiplier_mode (unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static int
init_stream(struct snd_efw *efw, struct amdtp_stream *stream)
{
	struct cmp_connection *conn;
	enum cmp_direction c_dir;
	enum amdtp_stream_direction s_dir;
	int err;

	if (stream == &efw->tx_stream) {
		conn = &efw->out_conn;
		c_dir = CMP_OUTPUT;
		s_dir = AMDTP_IN_STREAM;
	} else {
		conn = &efw->in_conn;
		c_dir = CMP_INPUT;
		s_dir = AMDTP_OUT_STREAM;
	}

	err = cmp_connection_init(conn, efw->unit, c_dir, 0);
	if (err < 0)
		goto end;

	err = amdtp_am824_init(stream, efw->unit, s_dir, CIP_BLOCKING);
	if (err < 0) {
		amdtp_stream_destroy(stream);
		cmp_connection_destroy(conn);
	}
end:
	return err;
}

__attribute__((used)) static void
stop_stream(struct snd_efw *efw, struct amdtp_stream *stream)
{
	amdtp_stream_pcm_abort(stream);
	amdtp_stream_stop(stream);

	if (stream == &efw->tx_stream)
		cmp_connection_break(&efw->out_conn);
	else
		cmp_connection_break(&efw->in_conn);
}

__attribute__((used)) static int
start_stream(struct snd_efw *efw, struct amdtp_stream *stream,
	     unsigned int sampling_rate)
{
	struct cmp_connection *conn;
	unsigned int mode, pcm_channels, midi_ports;
	int err;

	err = snd_efw_get_multiplier_mode(sampling_rate, &mode);
	if (err < 0)
		goto end;
	if (stream == &efw->tx_stream) {
		conn = &efw->out_conn;
		pcm_channels = efw->pcm_capture_channels[mode];
		midi_ports = efw->midi_out_ports;
	} else {
		conn = &efw->in_conn;
		pcm_channels = efw->pcm_playback_channels[mode];
		midi_ports = efw->midi_in_ports;
	}

	err = amdtp_am824_set_parameters(stream, sampling_rate,
					 pcm_channels, midi_ports, false);
	if (err < 0)
		goto end;

	/*  establish connection via CMP */
	err = cmp_connection_establish(conn,
				amdtp_stream_get_max_payload(stream));
	if (err < 0)
		goto end;

	/* start amdtp stream */
	err = amdtp_stream_start(stream,
				 conn->resources.channel,
				 conn->speed);
	if (err < 0) {
		stop_stream(efw, stream);
		goto end;
	}

	/* wait first callback */
	if (!amdtp_stream_wait_callback(stream, CALLBACK_TIMEOUT)) {
		stop_stream(efw, stream);
		err = -ETIMEDOUT;
	}
end:
	return err;
}

__attribute__((used)) static void
destroy_stream(struct snd_efw *efw, struct amdtp_stream *stream)
{
	struct cmp_connection *conn;

	if (stream == &efw->tx_stream)
		conn = &efw->out_conn;
	else
		conn = &efw->in_conn;

	amdtp_stream_destroy(stream);
	cmp_connection_destroy(conn);
}

__attribute__((used)) static int
check_connection_used_by_others(struct snd_efw *efw, struct amdtp_stream *s)
{
	struct cmp_connection *conn;
	bool used;
	int err;

	if (s == &efw->tx_stream)
		conn = &efw->out_conn;
	else
		conn = &efw->in_conn;

	err = cmp_connection_check_used(conn, &used);
	if ((err >= 0) && used && !amdtp_stream_running(s)) {
		dev_err(&efw->unit->device,
			"Connection established by others: %cPCR[%d]\n",
			(conn->direction == CMP_OUTPUT) ? 'o' : 'i',
			conn->pcr_index);
		err = -EBUSY;
	}

	return err;
}

int snd_efw_stream_init_duplex(struct snd_efw *efw)
{
	int err;

	err = init_stream(efw, &efw->tx_stream);
	if (err < 0)
		goto end;
	/* Fireworks transmits NODATA packets with TAG0. */
	efw->tx_stream.flags |= CIP_EMPTY_WITH_TAG0;
	/* Fireworks has its own meaning for dbc. */
	efw->tx_stream.flags |= CIP_DBC_IS_END_EVENT;
	/* Fireworks reset dbc at bus reset. */
	efw->tx_stream.flags |= CIP_SKIP_DBC_ZERO_CHECK;
	/*
	 * But Recent firmwares starts packets with non-zero dbc.
	 * Driver version 5.7.6 installs firmware version 5.7.3.
	 */
	if (efw->is_fireworks3 &&
	    (efw->firmware_version == 0x5070000 ||
	     efw->firmware_version == 0x5070300 ||
	     efw->firmware_version == 0x5080000))
		efw->tx_stream.tx_first_dbc = 0x02;
	/* AudioFire9 always reports wrong dbs. */
	if (efw->is_af9)
		efw->tx_stream.flags |= CIP_WRONG_DBS;
	/* Firmware version 5.5 reports fixed interval for dbc. */
	if (efw->firmware_version == 0x5050000)
		efw->tx_stream.tx_dbc_interval = 8;

	err = init_stream(efw, &efw->rx_stream);
	if (err < 0) {
		destroy_stream(efw, &efw->tx_stream);
		goto end;
	}

	/* set IEC61883 compliant mode (actually not fully compliant...) */
	err = snd_efw_command_set_tx_mode(efw, SND_EFW_TRANSPORT_MODE_IEC61883);
	if (err < 0) {
		destroy_stream(efw, &efw->tx_stream);
		destroy_stream(efw, &efw->rx_stream);
	}
end:
	return err;
}

int snd_efw_stream_start_duplex(struct snd_efw *efw, unsigned int rate)
{
	unsigned int curr_rate;
	int err = 0;

	/* Need no substreams */
	if (efw->playback_substreams == 0 && efw->capture_substreams  == 0)
		goto end;

	/*
	 * Considering JACK/FFADO streaming:
	 * TODO: This can be removed hwdep functionality becomes popular.
	 */
	err = check_connection_used_by_others(efw, &efw->rx_stream);
	if (err < 0)
		goto end;

	/* packet queueing error */
	if (amdtp_streaming_error(&efw->tx_stream))
		stop_stream(efw, &efw->tx_stream);
	if (amdtp_streaming_error(&efw->rx_stream))
		stop_stream(efw, &efw->rx_stream);

	/* stop streams if rate is different */
	err = snd_efw_command_get_sampling_rate(efw, &curr_rate);
	if (err < 0)
		goto end;
	if (rate == 0)
		rate = curr_rate;
	if (rate != curr_rate) {
		stop_stream(efw, &efw->tx_stream);
		stop_stream(efw, &efw->rx_stream);
	}

	/* master should be always running */
	if (!amdtp_stream_running(&efw->rx_stream)) {
		err = snd_efw_command_set_sampling_rate(efw, rate);
		if (err < 0)
			goto end;

		err = start_stream(efw, &efw->rx_stream, rate);
		if (err < 0) {
			dev_err(&efw->unit->device,
				"fail to start AMDTP master stream:%d\n", err);
			goto end;
		}
	}

	/* start slave if needed */
	if (efw->capture_substreams > 0 &&
	    !amdtp_stream_running(&efw->tx_stream)) {
		err = start_stream(efw, &efw->tx_stream, rate);
		if (err < 0) {
			dev_err(&efw->unit->device,
				"fail to start AMDTP slave stream:%d\n", err);
			stop_stream(efw, &efw->rx_stream);
		}
	}
end:
	return err;
}

void snd_efw_stream_stop_duplex(struct snd_efw *efw)
{
	if (efw->capture_substreams == 0) {
		stop_stream(efw, &efw->tx_stream);

		if (efw->playback_substreams == 0)
			stop_stream(efw, &efw->rx_stream);
	}
}

void snd_efw_stream_update_duplex(struct snd_efw *efw)
{
	if (cmp_connection_update(&efw->out_conn) < 0 ||
	    cmp_connection_update(&efw->in_conn) < 0) {
		stop_stream(efw, &efw->rx_stream);
		stop_stream(efw, &efw->tx_stream);
	} else {
		amdtp_stream_update(&efw->rx_stream);
		amdtp_stream_update(&efw->tx_stream);
	}
}

void snd_efw_stream_destroy_duplex(struct snd_efw *efw)
{
	destroy_stream(efw, &efw->rx_stream);
	destroy_stream(efw, &efw->tx_stream);
}

void snd_efw_stream_lock_changed(struct snd_efw *efw)
{
	efw->dev_lock_changed = true;
	wake_up(&efw->hwdep_wait);
}

int snd_efw_stream_lock_try(struct snd_efw *efw)
{
	int err;

	spin_lock_irq(&efw->lock);

	/* user land lock this */
	if (efw->dev_lock_count < 0) {
		err = -EBUSY;
		goto end;
	}

	/* this is the first time */
	if (efw->dev_lock_count++ == 0)
		snd_efw_stream_lock_changed(efw);
	err = 0;
end:
	spin_unlock_irq(&efw->lock);
	return err;
}

void snd_efw_stream_lock_release(struct snd_efw *efw)
{
	spin_lock_irq(&efw->lock);

	if (WARN_ON(efw->dev_lock_count <= 0))
		goto end;
	if (--efw->dev_lock_count == 0)
		snd_efw_stream_lock_changed(efw);
end:
	spin_unlock_irq(&efw->lock);
}


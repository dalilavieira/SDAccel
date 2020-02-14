#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct snd_pcm_substream {int dummy; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
struct TYPE_8__ {int channel; } ;
struct snd_dg00x {scalar_t__ substreams_counter; int dev_lock_changed; scalar_t__ dev_lock_count; int /*<<< orphan*/  lock; int /*<<< orphan*/  hwdep_wait; struct amdtp_stream rx_stream; struct amdtp_stream tx_stream; TYPE_2__ rx_resources; TYPE_2__ tx_resources; int /*<<< orphan*/  unit; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  enum snd_dg00x_clock { ____Placeholder_snd_dg00x_clock } snd_dg00x_clock ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  int /*<<< orphan*/  data ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_7__ {int /*<<< orphan*/  max_speed; } ;

/* Variables and functions */
 int /*<<< orphan*/  AMDTP_IN_STREAM ; 
 int /*<<< orphan*/  AMDTP_OUT_STREAM ; 
 size_t ARRAY_SIZE (unsigned int*) ; 
 unsigned int CALLBACK_TIMEOUT ; 
 scalar_t__ DG00X_ADDR_BASE ; 
 scalar_t__ DG00X_OFFSET_CLOCK_SOURCE ; 
 scalar_t__ DG00X_OFFSET_DETECT_EXTERNAL ; 
 scalar_t__ DG00X_OFFSET_EXTERNAL_RATE ; 
 scalar_t__ DG00X_OFFSET_ISOC_CHANNELS ; 
 scalar_t__ DG00X_OFFSET_LOCAL_RATE ; 
 scalar_t__ DG00X_OFFSET_STREAMING_SET ; 
 scalar_t__ DG00X_OFFSET_STREAMING_STATE ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int SND_DG00X_CLOCK_COUNT ; 
 unsigned int SND_DG00X_RATE_COUNT ; 
 int /*<<< orphan*/  TCODE_READ_QUADLET_REQUEST ; 
 int /*<<< orphan*/  TCODE_WRITE_QUADLET_REQUEST ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int amdtp_dot_init (struct amdtp_stream*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int amdtp_dot_set_parameters (struct amdtp_stream*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amdtp_stream_destroy (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_get_max_payload (struct amdtp_stream*) ; 
 int amdtp_stream_start (struct amdtp_stream*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amdtp_stream_stop (struct amdtp_stream*) ; 
 int /*<<< orphan*/  amdtp_stream_update (struct amdtp_stream*) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int fw_iso_resources_allocate (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fw_iso_resources_destroy (TYPE_2__*) ; 
 int /*<<< orphan*/  fw_iso_resources_free (TYPE_2__*) ; 
 int fw_iso_resources_init (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fw_iso_resources_update (TYPE_2__*) ; 
 TYPE_1__* fw_parent_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 void snd_dg00x_stream_destroy_duplex (struct snd_dg00x*) ; 
 int /*<<< orphan*/ * snd_dg00x_stream_pcm_channels ; 
 unsigned int* snd_dg00x_stream_rates ; 
 int snd_fw_transaction (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
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

int snd_dg00x_stream_get_local_rate(struct snd_dg00x *dg00x, unsigned int *rate)
{
	u32 data;
	__be32 reg;
	int err;

	err = snd_fw_transaction(dg00x->unit, TCODE_READ_QUADLET_REQUEST,
				 DG00X_ADDR_BASE + DG00X_OFFSET_LOCAL_RATE,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	data = be32_to_cpu(reg) & 0x0f;
	if (data < ARRAY_SIZE(snd_dg00x_stream_rates))
		*rate = snd_dg00x_stream_rates[data];
	else
		err = -EIO;

	return err;
}

int snd_dg00x_stream_set_local_rate(struct snd_dg00x *dg00x, unsigned int rate)
{
	__be32 reg;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(snd_dg00x_stream_rates); i++) {
		if (rate == snd_dg00x_stream_rates[i])
			break;
	}
	if (i == ARRAY_SIZE(snd_dg00x_stream_rates))
		return -EINVAL;

	reg = cpu_to_be32(i);
	return snd_fw_transaction(dg00x->unit, TCODE_WRITE_QUADLET_REQUEST,
				  DG00X_ADDR_BASE + DG00X_OFFSET_LOCAL_RATE,
				  &reg, sizeof(reg), 0);
}

int snd_dg00x_stream_get_clock(struct snd_dg00x *dg00x,
			       enum snd_dg00x_clock *clock)
{
	__be32 reg;
	int err;

	err = snd_fw_transaction(dg00x->unit, TCODE_READ_QUADLET_REQUEST,
				 DG00X_ADDR_BASE + DG00X_OFFSET_CLOCK_SOURCE,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	*clock = be32_to_cpu(reg) & 0x0f;
	if (*clock >= SND_DG00X_CLOCK_COUNT)
		err = -EIO;

	return err;
}

int snd_dg00x_stream_check_external_clock(struct snd_dg00x *dg00x, bool *detect)
{
	__be32 reg;
	int err;

	err = snd_fw_transaction(dg00x->unit, TCODE_READ_QUADLET_REQUEST,
				 DG00X_ADDR_BASE + DG00X_OFFSET_DETECT_EXTERNAL,
				 &reg, sizeof(reg), 0);
	if (err >= 0)
		*detect = be32_to_cpu(reg) > 0;

	return err;
}

int snd_dg00x_stream_get_external_rate(struct snd_dg00x *dg00x,
				       unsigned int *rate)
{
	u32 data;
	__be32 reg;
	int err;

	err = snd_fw_transaction(dg00x->unit, TCODE_READ_QUADLET_REQUEST,
				 DG00X_ADDR_BASE + DG00X_OFFSET_EXTERNAL_RATE,
				 &reg, sizeof(reg), 0);
	if (err < 0)
		return err;

	data = be32_to_cpu(reg) & 0x0f;
	if (data < ARRAY_SIZE(snd_dg00x_stream_rates))
		*rate = snd_dg00x_stream_rates[data];
	/* This means desync. */
	else
		err = -EBUSY;

	return err;
}

__attribute__((used)) static void finish_session(struct snd_dg00x *dg00x)
{
	__be32 data = cpu_to_be32(0x00000003);

	snd_fw_transaction(dg00x->unit, TCODE_WRITE_QUADLET_REQUEST,
			   DG00X_ADDR_BASE + DG00X_OFFSET_STREAMING_SET,
			   &data, sizeof(data), 0);
}

__attribute__((used)) static int begin_session(struct snd_dg00x *dg00x)
{
	__be32 data;
	u32 curr;
	int err;

	err = snd_fw_transaction(dg00x->unit, TCODE_READ_QUADLET_REQUEST,
				 DG00X_ADDR_BASE + DG00X_OFFSET_STREAMING_STATE,
				 &data, sizeof(data), 0);
	if (err < 0)
		goto error;
	curr = be32_to_cpu(data);

	if (curr == 0)
		curr = 2;

	curr--;
	while (curr > 0) {
		data = cpu_to_be32(curr);
		err = snd_fw_transaction(dg00x->unit,
					 TCODE_WRITE_QUADLET_REQUEST,
					 DG00X_ADDR_BASE +
					 DG00X_OFFSET_STREAMING_SET,
					 &data, sizeof(data), 0);
		if (err < 0)
			goto error;

		msleep(20);
		curr--;
	}

	return 0;
error:
	finish_session(dg00x);
	return err;
}

__attribute__((used)) static void release_resources(struct snd_dg00x *dg00x)
{
	__be32 data = 0;

	/* Unregister isochronous channels for both direction. */
	snd_fw_transaction(dg00x->unit, TCODE_WRITE_QUADLET_REQUEST,
			   DG00X_ADDR_BASE + DG00X_OFFSET_ISOC_CHANNELS,
			   &data, sizeof(data), 0);

	/* Release isochronous resources. */
	fw_iso_resources_free(&dg00x->tx_resources);
	fw_iso_resources_free(&dg00x->rx_resources);
}

__attribute__((used)) static int keep_resources(struct snd_dg00x *dg00x, unsigned int rate)
{
	unsigned int i;
	__be32 data;
	int err;

	/* Check sampling rate. */
	for (i = 0; i < SND_DG00X_RATE_COUNT; i++) {
		if (snd_dg00x_stream_rates[i] == rate)
			break;
	}
	if (i == SND_DG00X_RATE_COUNT)
		return -EINVAL;

	/* Keep resources for out-stream. */
	err = amdtp_dot_set_parameters(&dg00x->rx_stream, rate,
				       snd_dg00x_stream_pcm_channels[i]);
	if (err < 0)
		return err;
	err = fw_iso_resources_allocate(&dg00x->rx_resources,
				amdtp_stream_get_max_payload(&dg00x->rx_stream),
				fw_parent_device(dg00x->unit)->max_speed);
	if (err < 0)
		return err;

	/* Keep resources for in-stream. */
	err = amdtp_dot_set_parameters(&dg00x->tx_stream, rate,
				       snd_dg00x_stream_pcm_channels[i]);
	if (err < 0)
		return err;
	err = fw_iso_resources_allocate(&dg00x->tx_resources,
				amdtp_stream_get_max_payload(&dg00x->tx_stream),
				fw_parent_device(dg00x->unit)->max_speed);
	if (err < 0)
		goto error;

	/* Register isochronous channels for both direction. */
	data = cpu_to_be32((dg00x->tx_resources.channel << 16) |
			   dg00x->rx_resources.channel);
	err = snd_fw_transaction(dg00x->unit, TCODE_WRITE_QUADLET_REQUEST,
				 DG00X_ADDR_BASE + DG00X_OFFSET_ISOC_CHANNELS,
				 &data, sizeof(data), 0);
	if (err < 0)
		goto error;

	return 0;
error:
	release_resources(dg00x);
	return err;
}

int snd_dg00x_stream_init_duplex(struct snd_dg00x *dg00x)
{
	int err;

	/* For out-stream. */
	err = fw_iso_resources_init(&dg00x->rx_resources, dg00x->unit);
	if (err < 0)
		goto error;
	err = amdtp_dot_init(&dg00x->rx_stream, dg00x->unit, AMDTP_OUT_STREAM);
	if (err < 0)
		goto error;

	/* For in-stream. */
	err = fw_iso_resources_init(&dg00x->tx_resources, dg00x->unit);
	if (err < 0)
		goto error;
	err = amdtp_dot_init(&dg00x->tx_stream, dg00x->unit, AMDTP_IN_STREAM);
	if (err < 0)
		goto error;

	return 0;
error:
	snd_dg00x_stream_destroy_duplex(dg00x);
	return err;
}

void snd_dg00x_stream_destroy_duplex(struct snd_dg00x *dg00x)
{
	amdtp_stream_destroy(&dg00x->rx_stream);
	fw_iso_resources_destroy(&dg00x->rx_resources);

	amdtp_stream_destroy(&dg00x->tx_stream);
	fw_iso_resources_destroy(&dg00x->tx_resources);
}

int snd_dg00x_stream_start_duplex(struct snd_dg00x *dg00x, unsigned int rate)
{
	unsigned int curr_rate;
	int err = 0;

	if (dg00x->substreams_counter == 0)
		goto end;

	/* Check current sampling rate. */
	err = snd_dg00x_stream_get_local_rate(dg00x, &curr_rate);
	if (err < 0)
		goto error;
	if (rate == 0)
		rate = curr_rate;
	if (curr_rate != rate ||
	    amdtp_streaming_error(&dg00x->tx_stream) ||
	    amdtp_streaming_error(&dg00x->rx_stream)) {
		finish_session(dg00x);

		amdtp_stream_stop(&dg00x->tx_stream);
		amdtp_stream_stop(&dg00x->rx_stream);
		release_resources(dg00x);
	}

	/*
	 * No packets are transmitted without receiving packets, reagardless of
	 * which source of clock is used.
	 */
	if (!amdtp_stream_running(&dg00x->rx_stream)) {
		err = snd_dg00x_stream_set_local_rate(dg00x, rate);
		if (err < 0)
			goto error;

		err = keep_resources(dg00x, rate);
		if (err < 0)
			goto error;

		err = begin_session(dg00x);
		if (err < 0)
			goto error;

		err = amdtp_stream_start(&dg00x->rx_stream,
				dg00x->rx_resources.channel,
				fw_parent_device(dg00x->unit)->max_speed);
		if (err < 0)
			goto error;

		if (!amdtp_stream_wait_callback(&dg00x->rx_stream,
					      CALLBACK_TIMEOUT)) {
			err = -ETIMEDOUT;
			goto error;
		}
	}

	/*
	 * The value of SYT field in transmitted packets is always 0x0000. Thus,
	 * duplex streams with timestamp synchronization cannot be built.
	 */
	if (!amdtp_stream_running(&dg00x->tx_stream)) {
		err = amdtp_stream_start(&dg00x->tx_stream,
				dg00x->tx_resources.channel,
				fw_parent_device(dg00x->unit)->max_speed);
		if (err < 0)
			goto error;

		if (!amdtp_stream_wait_callback(&dg00x->tx_stream,
					      CALLBACK_TIMEOUT)) {
			err = -ETIMEDOUT;
			goto error;
		}
	}
end:
	return err;
error:
	finish_session(dg00x);

	amdtp_stream_stop(&dg00x->tx_stream);
	amdtp_stream_stop(&dg00x->rx_stream);
	release_resources(dg00x);

	return err;
}

void snd_dg00x_stream_stop_duplex(struct snd_dg00x *dg00x)
{
	if (dg00x->substreams_counter > 0)
		return;

	amdtp_stream_stop(&dg00x->tx_stream);
	amdtp_stream_stop(&dg00x->rx_stream);
	finish_session(dg00x);
	release_resources(dg00x);

	/*
	 * Just after finishing the session, the device may lost transmitting
	 * functionality for a short time.
	 */
	msleep(50);
}

void snd_dg00x_stream_update_duplex(struct snd_dg00x *dg00x)
{
	fw_iso_resources_update(&dg00x->tx_resources);
	fw_iso_resources_update(&dg00x->rx_resources);

	amdtp_stream_update(&dg00x->tx_stream);
	amdtp_stream_update(&dg00x->rx_stream);
}

void snd_dg00x_stream_lock_changed(struct snd_dg00x *dg00x)
{
	dg00x->dev_lock_changed = true;
	wake_up(&dg00x->hwdep_wait);
}

int snd_dg00x_stream_lock_try(struct snd_dg00x *dg00x)
{
	int err;

	spin_lock_irq(&dg00x->lock);

	/* user land lock this */
	if (dg00x->dev_lock_count < 0) {
		err = -EBUSY;
		goto end;
	}

	/* this is the first time */
	if (dg00x->dev_lock_count++ == 0)
		snd_dg00x_stream_lock_changed(dg00x);
	err = 0;
end:
	spin_unlock_irq(&dg00x->lock);
	return err;
}

void snd_dg00x_stream_lock_release(struct snd_dg00x *dg00x)
{
	spin_lock_irq(&dg00x->lock);

	if (WARN_ON(dg00x->dev_lock_count <= 0))
		goto end;
	if (--dg00x->dev_lock_count == 0)
		snd_dg00x_stream_lock_changed(dg00x);
end:
	spin_unlock_irq(&dg00x->lock);
}


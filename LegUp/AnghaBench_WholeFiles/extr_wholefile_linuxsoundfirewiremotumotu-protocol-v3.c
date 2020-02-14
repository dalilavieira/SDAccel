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
typedef  size_t u32 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_motu_packet_format {int msg_chunks; unsigned char* differed_part_pcm_chunks; int pcm_byte_offset; void** fixed_part_pcm_chunks; } ;
struct snd_motu {struct snd_motu_packet_format rx_packet_formats; struct snd_motu_packet_format tx_packet_formats; TYPE_1__* spec; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  enum snd_motu_spec_flags { ____Placeholder_snd_motu_spec_flags } snd_motu_spec_flags ;
typedef  enum snd_motu_clock_source { ____Placeholder_snd_motu_clock_source } snd_motu_clock_source ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum amdtp_stream_direction { ____Placeholder_amdtp_stream_direction } amdtp_stream_direction ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {int flags; unsigned char analog_in_ports; unsigned char analog_out_ports; } ;

/* Variables and functions */
 int AMDTP_IN_STREAM ; 
 int AMDTP_OUT_STREAM ; 
 int ARRAY_SIZE (unsigned int*) ; 
 int EINTR ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT_A ; 
 int SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT_B ; 
 int SND_MOTU_CLOCK_SOURCE_INTERNAL ; 
 int SND_MOTU_CLOCK_SOURCE_SPDIF_ON_COAX ; 
 int SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT_A ; 
 int SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT_B ; 
 int SND_MOTU_CLOCK_SOURCE_UNKNOWN ; 
 int SND_MOTU_CLOCK_SOURCE_WORD_ON_BNC ; 
 int SND_MOTU_SPEC_HAS_AESEBU_IFACE ; 
 int SND_MOTU_SPEC_HAS_OPT_IFACE_A ; 
 int SND_MOTU_SPEC_HAS_OPT_IFACE_B ; 
 int SND_MOTU_SPEC_RX_SEPARETED_MAIN ; 
 int SND_MOTU_SPEC_SUPPORT_CLOCK_X4 ; 
 int SND_MOTU_SPEC_TX_MICINST_CHUNK ; 
 int SND_MOTU_SPEC_TX_RETURN_CHUNK ; 
 int SND_MOTU_SPEC_TX_REVERB_CHUNK ; 
 size_t V3_CLOCK_RATE_MASK ; 
 size_t V3_CLOCK_RATE_SHIFT ; 
 size_t V3_CLOCK_SOURCE_MASK ; 
 int /*<<< orphan*/  V3_CLOCK_STATUS_OFFSET ; 
 size_t V3_ENABLE_OPT_IN_IFACE_A ; 
 size_t V3_ENABLE_OPT_IN_IFACE_B ; 
 size_t V3_ENABLE_OPT_OUT_IFACE_A ; 
 size_t V3_ENABLE_OPT_OUT_IFACE_B ; 
 size_t V3_FETCH_PCM_FRAMES ; 
 size_t V3_NO_ADAT_OPT_IN_IFACE_A ; 
 size_t V3_NO_ADAT_OPT_IN_IFACE_B ; 
 size_t V3_NO_ADAT_OPT_OUT_IFACE_A ; 
 size_t V3_NO_ADAT_OPT_OUT_IFACE_B ; 
 int /*<<< orphan*/  V3_OPT_IFACE_MODE_OFFSET ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 size_t be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (size_t) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 scalar_t__ msleep_interruptible (int) ; 
 void* round_up (unsigned char,int) ; 
 unsigned int* snd_motu_clock_rates ; 
 int snd_motu_transaction_read (struct snd_motu*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int snd_motu_transaction_write (struct snd_motu*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
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

__attribute__((used)) static int v3_get_clock_rate(struct snd_motu *motu, unsigned int *rate)
{
	__be32 reg;
	u32 data;
	int err;

	err = snd_motu_transaction_read(motu, V3_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	data = (data & V3_CLOCK_RATE_MASK) >> V3_CLOCK_RATE_SHIFT;
	if (data >= ARRAY_SIZE(snd_motu_clock_rates))
		return -EIO;

	*rate = snd_motu_clock_rates[data];

	return 0;
}

__attribute__((used)) static int v3_set_clock_rate(struct snd_motu *motu, unsigned int rate)
{
	__be32 reg;
	u32 data;
	bool need_to_wait;
	int i, err;

	for (i = 0; i < ARRAY_SIZE(snd_motu_clock_rates); ++i) {
		if (snd_motu_clock_rates[i] == rate)
			break;
	}
	if (i == ARRAY_SIZE(snd_motu_clock_rates))
		return -EINVAL;

	err = snd_motu_transaction_read(motu, V3_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	data &= ~(V3_CLOCK_RATE_MASK | V3_FETCH_PCM_FRAMES);
	data |= i << V3_CLOCK_RATE_SHIFT;

	need_to_wait = data != be32_to_cpu(reg);

	reg = cpu_to_be32(data);
	err = snd_motu_transaction_write(motu, V3_CLOCK_STATUS_OFFSET, &reg,
					 sizeof(reg));
	if (err < 0)
		return err;

	if (need_to_wait) {
		/* Cost expensive. */
		if (msleep_interruptible(4000) > 0)
			return -EINTR;
	}

	return 0;
}

__attribute__((used)) static int v3_get_clock_source(struct snd_motu *motu,
			       enum snd_motu_clock_source *src)
{
	__be32 reg;
	u32 data;
	unsigned int val;
	int err;

	err = snd_motu_transaction_read(motu, V3_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	val = data & V3_CLOCK_SOURCE_MASK;
	if (val == 0x00) {
		*src = SND_MOTU_CLOCK_SOURCE_INTERNAL;
	} else if (val == 0x01) {
		*src = SND_MOTU_CLOCK_SOURCE_WORD_ON_BNC;
	} else if (val == 0x10) {
		*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_COAX;
	} else if (val == 0x18 || val == 0x19) {
		err = snd_motu_transaction_read(motu, V3_OPT_IFACE_MODE_OFFSET,
						&reg, sizeof(reg));
		if (err < 0)
			return err;
		data = be32_to_cpu(reg);

		if (val == 0x18) {
			if (data & V3_NO_ADAT_OPT_IN_IFACE_A)
				*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT_A;
			else
				*src = SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT_A;
		} else {
			if (data & V3_NO_ADAT_OPT_IN_IFACE_B)
				*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT_B;
			else
				*src = SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT_B;
		}
	} else {
		*src = SND_MOTU_CLOCK_SOURCE_UNKNOWN;
	}

	return 0;
}

__attribute__((used)) static int v3_switch_fetching_mode(struct snd_motu *motu, bool enable)
{
	__be32 reg;
	u32 data;
	int err;

	err = snd_motu_transaction_read(motu, V3_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return 0;
	data = be32_to_cpu(reg);

	if (enable)
		data |= V3_FETCH_PCM_FRAMES;
	else
		data &= ~V3_FETCH_PCM_FRAMES;

	reg = cpu_to_be32(data);
	return snd_motu_transaction_write(motu, V3_CLOCK_STATUS_OFFSET, &reg,
					  sizeof(reg));
}

__attribute__((used)) static void calculate_fixed_part(struct snd_motu_packet_format *formats,
				 enum amdtp_stream_direction dir,
				 enum snd_motu_spec_flags flags,
				 unsigned char analog_ports)
{
	unsigned char pcm_chunks[3] = {0, 0, 0};

	formats->msg_chunks = 2;

	pcm_chunks[0] = analog_ports;
	pcm_chunks[1] = analog_ports;
	if (flags & SND_MOTU_SPEC_SUPPORT_CLOCK_X4)
		pcm_chunks[2] = analog_ports;

	if (dir == AMDTP_IN_STREAM) {
		if (flags & SND_MOTU_SPEC_TX_MICINST_CHUNK) {
			pcm_chunks[0] += 2;
			pcm_chunks[1] += 2;
			if (flags & SND_MOTU_SPEC_SUPPORT_CLOCK_X4)
				pcm_chunks[2] += 2;
		}

		if (flags & SND_MOTU_SPEC_TX_RETURN_CHUNK) {
			pcm_chunks[0] += 2;
			pcm_chunks[1] += 2;
			if (flags & SND_MOTU_SPEC_SUPPORT_CLOCK_X4)
				pcm_chunks[2] += 2;
		}

		if (flags & SND_MOTU_SPEC_TX_REVERB_CHUNK) {
			pcm_chunks[0] += 2;
			pcm_chunks[1] += 2;
		}
	} else {
		if (flags & SND_MOTU_SPEC_RX_SEPARETED_MAIN) {
			pcm_chunks[0] += 2;
			pcm_chunks[1] += 2;
		}

		// Packets to v3 units include 2 chunks for phone 1/2, except
		// for 176.4/192.0 kHz.
		pcm_chunks[0] += 2;
		pcm_chunks[1] += 2;
	}

	if (flags & SND_MOTU_SPEC_HAS_AESEBU_IFACE) {
		pcm_chunks[0] += 2;
		pcm_chunks[1] += 2;
	}

	/*
	 * At least, packets have two data chunks for S/PDIF on coaxial
	 * interface.
	 */
	pcm_chunks[0] += 2;
	pcm_chunks[1] += 2;

	/*
	 * Fixed part consists of PCM chunks multiple of 4, with msg chunks. As
	 * a result, this part can includes empty data chunks.
	 */
	formats->fixed_part_pcm_chunks[0] = round_up(2 + pcm_chunks[0], 4) - 2;
	formats->fixed_part_pcm_chunks[1] = round_up(2 + pcm_chunks[1], 4) - 2;
	if (flags & SND_MOTU_SPEC_SUPPORT_CLOCK_X4)
		formats->fixed_part_pcm_chunks[2] =
					round_up(2 + pcm_chunks[2], 4) - 2;
}

__attribute__((used)) static void calculate_differed_part(struct snd_motu_packet_format *formats,
				    enum snd_motu_spec_flags flags, u32 data,
				    u32 a_enable_mask, u32 a_no_adat_mask,
				    u32 b_enable_mask, u32 b_no_adat_mask)
{
	unsigned char pcm_chunks[3] = {0, 0, 0};
	int i;

	if ((flags & SND_MOTU_SPEC_HAS_OPT_IFACE_A) && (data & a_enable_mask)) {
		if (data & a_no_adat_mask) {
			/*
			 * Additional two data chunks for S/PDIF on optical
			 * interface A. This includes empty data chunks.
			 */
			pcm_chunks[0] += 4;
			pcm_chunks[1] += 4;
		} else {
			/*
			 * Additional data chunks for ADAT on optical interface
			 * A.
			 */
			pcm_chunks[0] += 8;
			pcm_chunks[1] += 4;
		}
	}

	if ((flags & SND_MOTU_SPEC_HAS_OPT_IFACE_B) && (data & b_enable_mask)) {
		if (data & b_no_adat_mask) {
			/*
			 * Additional two data chunks for S/PDIF on optical
			 * interface B. This includes empty data chunks.
			 */
			pcm_chunks[0] += 4;
			pcm_chunks[1] += 4;
		} else {
			/*
			 * Additional data chunks for ADAT on optical interface
			 * B.
			 */
			pcm_chunks[0] += 8;
			pcm_chunks[1] += 4;
		}
	}

	for (i = 0; i < 3; ++i) {
		if (pcm_chunks[i] > 0)
			pcm_chunks[i] = round_up(pcm_chunks[i], 4);

		formats->differed_part_pcm_chunks[i] = pcm_chunks[i];
	}
}

__attribute__((used)) static int v3_cache_packet_formats(struct snd_motu *motu)
{
	__be32 reg;
	u32 data;
	int err;

	err = snd_motu_transaction_read(motu, V3_OPT_IFACE_MODE_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	calculate_fixed_part(&motu->tx_packet_formats, AMDTP_IN_STREAM,
			     motu->spec->flags, motu->spec->analog_in_ports);
	calculate_differed_part(&motu->tx_packet_formats,
			motu->spec->flags, data,
			V3_ENABLE_OPT_IN_IFACE_A, V3_NO_ADAT_OPT_IN_IFACE_A,
			V3_ENABLE_OPT_IN_IFACE_B, V3_NO_ADAT_OPT_IN_IFACE_B);

	calculate_fixed_part(&motu->rx_packet_formats, AMDTP_OUT_STREAM,
			     motu->spec->flags, motu->spec->analog_out_ports);
	calculate_differed_part(&motu->rx_packet_formats,
			motu->spec->flags, data,
			V3_ENABLE_OPT_OUT_IFACE_A, V3_NO_ADAT_OPT_OUT_IFACE_A,
			V3_ENABLE_OPT_OUT_IFACE_B, V3_NO_ADAT_OPT_OUT_IFACE_B);

	motu->tx_packet_formats.pcm_byte_offset = 10;
	motu->rx_packet_formats.pcm_byte_offset = 10;

	return 0;
}


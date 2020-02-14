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
typedef  int u32 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_motu_packet_format {int msg_chunks; unsigned char* fixed_part_pcm_chunks; unsigned char* differed_part_pcm_chunks; int pcm_byte_offset; } ;
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
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int SND_MOTU_CLOCK_SOURCE_ADAT_ON_DSUB ; 
 int SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT ; 
 int SND_MOTU_CLOCK_SOURCE_INTERNAL ; 
 int SND_MOTU_CLOCK_SOURCE_SPDIF_ON_COAX ; 
 int SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT ; 
 int SND_MOTU_CLOCK_SOURCE_WORD_ON_BNC ; 
 int SND_MOTU_SPEC_HAS_AESEBU_IFACE ; 
 int SND_MOTU_SPEC_HAS_OPT_IFACE_A ; 
 int SND_MOTU_SPEC_RX_SEPARETED_MAIN ; 
 int SND_MOTU_SPEC_SUPPORT_CLOCK_X4 ; 
 int SND_MOTU_SPEC_TX_MICINST_CHUNK ; 
 int SND_MOTU_SPEC_TX_RETURN_CHUNK ; 
 int V2_CLOCK_RATE_MASK ; 
 int V2_CLOCK_RATE_SHIFT ; 
 int V2_CLOCK_SRC_MASK ; 
 int /*<<< orphan*/  V2_CLOCK_STATUS_OFFSET ; 
 int V2_CLOCK_TRAVELER_FETCH_DISABLE ; 
 int V2_CLOCK_TRAVELER_FETCH_ENABLE ; 
 int /*<<< orphan*/  V2_IN_OUT_CONF_OFFSET ; 
 int V2_OPT_IFACE_MODE_ADAT ; 
 int V2_OPT_IN_IFACE_MASK ; 
 int V2_OPT_IN_IFACE_SHIFT ; 
 int V2_OPT_OUT_IFACE_MASK ; 
 int V2_OPT_OUT_IFACE_SHIFT ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 unsigned int* snd_motu_clock_rates ; 
 TYPE_1__ snd_motu_spec_traveler ; 
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

__attribute__((used)) static int v2_get_clock_rate(struct snd_motu *motu, unsigned int *rate)
{
	__be32 reg;
	unsigned int index;
	int err;

	err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;

	index = (be32_to_cpu(reg) & V2_CLOCK_RATE_MASK) >> V2_CLOCK_RATE_SHIFT;
	if (index >= ARRAY_SIZE(snd_motu_clock_rates))
		return -EIO;

	*rate = snd_motu_clock_rates[index];

	return 0;
}

__attribute__((used)) static int v2_set_clock_rate(struct snd_motu *motu, unsigned int rate)
{
	__be32 reg;
	u32 data;
	int i;
	int err;

	for (i = 0; i < ARRAY_SIZE(snd_motu_clock_rates); ++i) {
		if (snd_motu_clock_rates[i] == rate)
			break;
	}
	if (i == ARRAY_SIZE(snd_motu_clock_rates))
		return -EINVAL;

	err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	data &= ~V2_CLOCK_RATE_MASK;
	data |= i << V2_CLOCK_RATE_SHIFT;

	if (motu->spec == &snd_motu_spec_traveler) {
		data &= ~V2_CLOCK_TRAVELER_FETCH_ENABLE;
		data |= V2_CLOCK_TRAVELER_FETCH_DISABLE;
	}

	reg = cpu_to_be32(data);
	return snd_motu_transaction_write(motu, V2_CLOCK_STATUS_OFFSET, &reg,
					  sizeof(reg));
}

__attribute__((used)) static int v2_get_clock_source(struct snd_motu *motu,
			       enum snd_motu_clock_source *src)
{
	__be32 reg;
	unsigned int index;
	int err;

	err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;

	index = be32_to_cpu(reg) & V2_CLOCK_SRC_MASK;
	if (index > 5)
		return -EIO;

	/* To check the configuration of optical interface. */
	err = snd_motu_transaction_read(motu, V2_IN_OUT_CONF_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;

	switch (index) {
	case 0:
		*src = SND_MOTU_CLOCK_SOURCE_INTERNAL;
		break;
	case 1:
		if (be32_to_cpu(reg) & 0x00000200)
			*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT;
		else
			*src = SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT;
		break;
	case 2:
		*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_COAX;
		break;
	case 4:
		*src = SND_MOTU_CLOCK_SOURCE_WORD_ON_BNC;
		break;
	case 5:
		*src = SND_MOTU_CLOCK_SOURCE_ADAT_ON_DSUB;
		break;
	default:
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int v2_switch_fetching_mode(struct snd_motu *motu, bool enable)
{
	__be32 reg;
	u32 data;
	int err = 0;

	if (motu->spec == &snd_motu_spec_traveler) {
		err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET,
						&reg, sizeof(reg));
		if (err < 0)
			return err;
		data = be32_to_cpu(reg);

		data &= ~(V2_CLOCK_TRAVELER_FETCH_DISABLE |
			  V2_CLOCK_TRAVELER_FETCH_ENABLE);

		if (enable)
			data |= V2_CLOCK_TRAVELER_FETCH_ENABLE;
		else
			data |= V2_CLOCK_TRAVELER_FETCH_DISABLE;

		reg = cpu_to_be32(data);
		err = snd_motu_transaction_write(motu, V2_CLOCK_STATUS_OFFSET,
						 &reg, sizeof(reg));
	}

	return err;
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
		}
		if (flags & SND_MOTU_SPEC_TX_RETURN_CHUNK) {
			pcm_chunks[0] += 2;
			pcm_chunks[1] += 2;
		}
	} else {
		if (flags & SND_MOTU_SPEC_RX_SEPARETED_MAIN) {
			pcm_chunks[0] += 2;
			pcm_chunks[1] += 2;
		}

		// Packets to v2 units include 2 chunks for phone 1/2, except
		// for 176.4/192.0 kHz.
		pcm_chunks[0] += 2;
		pcm_chunks[1] += 2;
	}

	if (flags & SND_MOTU_SPEC_HAS_AESEBU_IFACE) {
		pcm_chunks[0] += 2;
		pcm_chunks[1] += 2;
	}

	/*
	 * All of v2 models have a pair of coaxial interfaces for digital in/out
	 * port. At 44.1/48.0/88.2/96.0 kHz, packets includes PCM from these
	 * ports.
	 */
	pcm_chunks[0] += 2;
	pcm_chunks[1] += 2;

	formats->fixed_part_pcm_chunks[0] = pcm_chunks[0];
	formats->fixed_part_pcm_chunks[1] = pcm_chunks[1];
	formats->fixed_part_pcm_chunks[2] = pcm_chunks[2];
}

__attribute__((used)) static void calculate_differed_part(struct snd_motu_packet_format *formats,
				    enum snd_motu_spec_flags flags,
				    u32 data, u32 mask, u32 shift)
{
	unsigned char pcm_chunks[2] = {0, 0};

	/*
	 * When optical interfaces are configured for S/PDIF (TOSLINK),
	 * the above PCM frames come from them, instead of coaxial
	 * interfaces.
	 */
	data = (data & mask) >> shift;
	if ((flags & SND_MOTU_SPEC_HAS_OPT_IFACE_A) &&
	    data == V2_OPT_IFACE_MODE_ADAT) {
		pcm_chunks[0] += 8;
		pcm_chunks[1] += 4;
	}

	/* At mode x4, no data chunks are supported in this part. */
	formats->differed_part_pcm_chunks[0] = pcm_chunks[0];
	formats->differed_part_pcm_chunks[1] = pcm_chunks[1];
}

__attribute__((used)) static int v2_cache_packet_formats(struct snd_motu *motu)
{
	__be32 reg;
	u32 data;
	int err;

	err = snd_motu_transaction_read(motu, V2_IN_OUT_CONF_OFFSET, &reg,
					sizeof(reg));
	if (err < 0)
		return err;
	data = be32_to_cpu(reg);

	calculate_fixed_part(&motu->tx_packet_formats, AMDTP_IN_STREAM,
			     motu->spec->flags, motu->spec->analog_in_ports);
	calculate_differed_part(&motu->tx_packet_formats, motu->spec->flags,
			data, V2_OPT_IN_IFACE_MASK, V2_OPT_IN_IFACE_SHIFT);

	calculate_fixed_part(&motu->rx_packet_formats, AMDTP_OUT_STREAM,
			     motu->spec->flags, motu->spec->analog_out_ports);
	calculate_differed_part(&motu->rx_packet_formats, motu->spec->flags,
			data, V2_OPT_OUT_IFACE_MASK, V2_OPT_OUT_IFACE_SHIFT);

	motu->tx_packet_formats.pcm_byte_offset = 10;
	motu->rx_packet_formats.pcm_byte_offset = 10;

	return 0;
}


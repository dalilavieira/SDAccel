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
struct snd_pcm_substream {int dummy; } ;
struct snd_dice {scalar_t__* rx_midi_ports; scalar_t__* tx_midi_ports; int /*<<< orphan*/  rx_pcm_chs; int /*<<< orphan*/  tx_pcm_chs; } ;
struct dice_mytek_spec {int /*<<< orphan*/  rx_pcm_chs; int /*<<< orphan*/  tx_pcm_chs; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX_STREAMS ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
 int /*<<< orphan*/  SND_DICE_ADDR_TYPE_GLOBAL ; 
 int /*<<< orphan*/  SND_DICE_ADDR_TYPE_RX ; 
 int /*<<< orphan*/  SND_DICE_ADDR_TYPE_SYNC ; 
 int /*<<< orphan*/  SND_DICE_ADDR_TYPE_TX ; 
 int SND_DICE_RATE_MODE_COUNT ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_dice_transaction_read (struct snd_dice*,int /*<<< orphan*/ ,unsigned int,void*,unsigned int) ; 
 int snd_dice_transaction_write (struct snd_dice*,int /*<<< orphan*/ ,unsigned int,void*,unsigned int) ; 
 struct dice_mytek_spec stereo_192_dsd_dac ; 
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

__attribute__((used)) static inline int snd_dice_transaction_write_global(struct snd_dice *dice,
						    unsigned int offset,
						    void *buf, unsigned int len)
{
	return snd_dice_transaction_write(dice,
					  SND_DICE_ADDR_TYPE_GLOBAL, offset,
					  buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_read_global(struct snd_dice *dice,
						   unsigned int offset,
						   void *buf, unsigned int len)
{
	return snd_dice_transaction_read(dice,
					 SND_DICE_ADDR_TYPE_GLOBAL, offset,
					 buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_write_tx(struct snd_dice *dice,
						unsigned int offset,
						void *buf, unsigned int len)
{
	return snd_dice_transaction_write(dice, SND_DICE_ADDR_TYPE_TX, offset,
					  buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_read_tx(struct snd_dice *dice,
					       unsigned int offset,
					       void *buf, unsigned int len)
{
	return snd_dice_transaction_read(dice, SND_DICE_ADDR_TYPE_TX, offset,
					 buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_write_rx(struct snd_dice *dice,
						unsigned int offset,
						void *buf, unsigned int len)
{
	return snd_dice_transaction_write(dice, SND_DICE_ADDR_TYPE_RX, offset,
					  buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_read_rx(struct snd_dice *dice,
					       unsigned int offset,
					       void *buf, unsigned int len)
{
	return snd_dice_transaction_read(dice, SND_DICE_ADDR_TYPE_RX, offset,
					 buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_write_sync(struct snd_dice *dice,
						  unsigned int offset,
						  void *buf, unsigned int len)
{
	return snd_dice_transaction_write(dice, SND_DICE_ADDR_TYPE_SYNC, offset,
					  buf, len);
}

__attribute__((used)) static inline int snd_dice_transaction_read_sync(struct snd_dice *dice,
						 unsigned int offset,
						 void *buf, unsigned int len)
{
	return snd_dice_transaction_read(dice, SND_DICE_ADDR_TYPE_SYNC, offset,
					 buf, len);
}

int snd_dice_detect_mytek_formats(struct snd_dice *dice)
{
	int i;
	const struct dice_mytek_spec *dev;

	dev = &stereo_192_dsd_dac;

	memcpy(dice->tx_pcm_chs, dev->tx_pcm_chs,
	       MAX_STREAMS * SND_DICE_RATE_MODE_COUNT * sizeof(unsigned int));
	memcpy(dice->rx_pcm_chs, dev->rx_pcm_chs,
	       MAX_STREAMS * SND_DICE_RATE_MODE_COUNT * sizeof(unsigned int));

	for (i = 0; i < MAX_STREAMS; ++i) {
		dice->tx_midi_ports[i] = 0;
		dice->rx_midi_ports[i] = 0;
	}

	return 0;
}


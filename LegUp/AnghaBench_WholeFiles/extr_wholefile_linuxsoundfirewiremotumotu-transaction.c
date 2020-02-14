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
typedef  scalar_t__ u32 ;
struct snd_pcm_substream {int dummy; } ;
struct TYPE_5__ {unsigned long long offset; int length; void (* address_callback ) (struct fw_card*,struct fw_request*,int,int,int,int,unsigned long long,void*,size_t,void*) ;struct snd_motu* callback_data; } ;
struct snd_motu {TYPE_2__ async_handler; int /*<<< orphan*/  unit; int /*<<< orphan*/  hwdep_wait; int /*<<< orphan*/  lock; int /*<<< orphan*/  msg; } ;
struct fw_request {int dummy; } ;
struct fw_device {TYPE_1__* card; } ;
struct fw_card {int dummy; } ;
struct fw_address_region {int start; int end; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  int /*<<< orphan*/  data ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_4__ {int node_id; } ;

/* Variables and functions */
 scalar_t__ ASYNC_ADDR_HI ; 
 scalar_t__ ASYNC_ADDR_LO ; 
 int EINVAL ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_COMPLETE ; 
 int RCODE_TYPE_ERROR ; 
 scalar_t__ SND_MOTU_ADDR_BASE ; 
 int TCODE_READ_BLOCK_REQUEST ; 
 int TCODE_READ_QUADLET_REQUEST ; 
 int TCODE_WRITE_BLOCK_REQUEST ; 
 int TCODE_WRITE_QUADLET_REQUEST ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int fw_core_add_address_handler (TYPE_2__*,struct fw_address_region const*) ; 
 int /*<<< orphan*/  fw_core_remove_address_handler (TYPE_2__*) ; 
 struct fw_device* fw_parent_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fw_send_response (struct fw_card*,struct fw_request*,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_fw_transaction (int /*<<< orphan*/ ,int,scalar_t__,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
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

int snd_motu_transaction_read(struct snd_motu *motu, u32 offset, __be32 *reg,
			      size_t size)
{
	int tcode;

	if (size % sizeof(__be32) > 0 || size <= 0)
		return -EINVAL;
	if (size == sizeof(__be32))
		tcode = TCODE_READ_QUADLET_REQUEST;
	else
		tcode = TCODE_READ_BLOCK_REQUEST;

	return snd_fw_transaction(motu->unit, tcode,
				  SND_MOTU_ADDR_BASE + offset, reg, size, 0);
}

int snd_motu_transaction_write(struct snd_motu *motu, u32 offset, __be32 *reg,
			       size_t size)
{
	int tcode;

	if (size % sizeof(__be32) > 0 || size <= 0)
		return -EINVAL;
	if (size == sizeof(__be32))
		tcode = TCODE_WRITE_QUADLET_REQUEST;
	else
		tcode = TCODE_WRITE_BLOCK_REQUEST;

	return snd_fw_transaction(motu->unit, tcode,
				  SND_MOTU_ADDR_BASE + offset, reg, size, 0);
}

__attribute__((used)) static void handle_message(struct fw_card *card, struct fw_request *request,
			   int tcode, int destination, int source,
			   int generation, unsigned long long offset,
			   void *data, size_t length, void *callback_data)
{
	struct snd_motu *motu = callback_data;
	__be32 *buf = (__be32 *)data;
	unsigned long flags;

	if (tcode != TCODE_WRITE_QUADLET_REQUEST) {
		fw_send_response(card, request, RCODE_COMPLETE);
		return;
	}

	if (offset != motu->async_handler.offset || length != 4) {
		fw_send_response(card, request, RCODE_ADDRESS_ERROR);
		return;
	}

	spin_lock_irqsave(&motu->lock, flags);
	motu->msg = be32_to_cpu(*buf);
	spin_unlock_irqrestore(&motu->lock, flags);

	fw_send_response(card, request, RCODE_COMPLETE);

	wake_up(&motu->hwdep_wait);
}

int snd_motu_transaction_reregister(struct snd_motu *motu)
{
	struct fw_device *device = fw_parent_device(motu->unit);
	__be32 data;
	int err;

	if (motu->async_handler.callback_data == NULL)
		return -EINVAL;

	/* Register messaging address. Block transaction is not allowed. */
	data = cpu_to_be32((device->card->node_id << 16) |
			   (motu->async_handler.offset >> 32));
	err = snd_motu_transaction_write(motu, ASYNC_ADDR_HI, &data,
					 sizeof(data));
	if (err < 0)
		return err;

	data = cpu_to_be32(motu->async_handler.offset);
	return snd_motu_transaction_write(motu, ASYNC_ADDR_LO, &data,
					  sizeof(data));
}

int snd_motu_transaction_register(struct snd_motu *motu)
{
	static const struct fw_address_region resp_register_region = {
		.start	= 0xffffe0000000ull,
		.end	= 0xffffe000ffffull,
	};
	int err;

	/* Perhaps, 4 byte messages are transferred. */
	motu->async_handler.length = 4;
	motu->async_handler.address_callback = handle_message;
	motu->async_handler.callback_data = motu;

	err = fw_core_add_address_handler(&motu->async_handler,
					  &resp_register_region);
	if (err < 0)
		return err;

	err = snd_motu_transaction_reregister(motu);
	if (err < 0) {
		fw_core_remove_address_handler(&motu->async_handler);
		motu->async_handler.address_callback = NULL;
	}

	return err;
}

void snd_motu_transaction_unregister(struct snd_motu *motu)
{
	__be32 data;

	if (motu->async_handler.address_callback != NULL)
		fw_core_remove_address_handler(&motu->async_handler);
	motu->async_handler.address_callback = NULL;

	/* Unregister the address. */
	data = cpu_to_be32(0x00000000);
	snd_motu_transaction_write(motu, ASYNC_ADDR_HI, &data, sizeof(data));
	snd_motu_transaction_write(motu, ASYNC_ADDR_LO, &data, sizeof(data));
}


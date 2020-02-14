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
struct TYPE_5__ {unsigned long long offset; int length; void (* address_callback ) (struct fw_card*,struct fw_request*,int,int,int,int,unsigned long long,void*,size_t,void*) ;struct snd_dg00x* callback_data; } ;
struct snd_dg00x {TYPE_2__ async_handler; int /*<<< orphan*/  unit; int /*<<< orphan*/  hwdep_wait; int /*<<< orphan*/  lock; int /*<<< orphan*/  msg; } ;
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
 scalar_t__ DG00X_ADDR_BASE ; 
 scalar_t__ DG00X_OFFSET_MESSAGE_ADDR ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int /*<<< orphan*/  RCODE_COMPLETE ; 
 int RCODE_TYPE_ERROR ; 
 int /*<<< orphan*/  TCODE_WRITE_BLOCK_REQUEST ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int fw_core_add_address_handler (TYPE_2__*,struct fw_address_region const*) ; 
 int /*<<< orphan*/  fw_core_remove_address_handler (TYPE_2__*) ; 
 struct fw_device* fw_parent_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fw_send_response (struct fw_card*,struct fw_request*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_fw_transaction (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ **,int,int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static void handle_unknown_message(struct snd_dg00x *dg00x,
				   unsigned long long offset, __be32 *buf)
{
	unsigned long flags;

	spin_lock_irqsave(&dg00x->lock, flags);
	dg00x->msg = be32_to_cpu(*buf);
	spin_unlock_irqrestore(&dg00x->lock, flags);

	wake_up(&dg00x->hwdep_wait);
}

__attribute__((used)) static void handle_message(struct fw_card *card, struct fw_request *request,
			   int tcode, int destination, int source,
			   int generation, unsigned long long offset,
			   void *data, size_t length, void *callback_data)
{
	struct snd_dg00x *dg00x = callback_data;
	__be32 *buf = (__be32 *)data;

	fw_send_response(card, request, RCODE_COMPLETE);

	if (offset == dg00x->async_handler.offset)
		handle_unknown_message(dg00x, offset, buf);
}

int snd_dg00x_transaction_reregister(struct snd_dg00x *dg00x)
{
	struct fw_device *device = fw_parent_device(dg00x->unit);
	__be32 data[2];

	/* Unknown. 4bytes. */
	data[0] = cpu_to_be32((device->card->node_id << 16) |
			      (dg00x->async_handler.offset >> 32));
	data[1] = cpu_to_be32(dg00x->async_handler.offset);
	return snd_fw_transaction(dg00x->unit, TCODE_WRITE_BLOCK_REQUEST,
				  DG00X_ADDR_BASE + DG00X_OFFSET_MESSAGE_ADDR,
				  &data, sizeof(data), 0);
}

void snd_dg00x_transaction_unregister(struct snd_dg00x *dg00x)
{
	if (dg00x->async_handler.callback_data == NULL)
		return;

	fw_core_remove_address_handler(&dg00x->async_handler);

	dg00x->async_handler.callback_data = NULL;
}

int snd_dg00x_transaction_register(struct snd_dg00x *dg00x)
{
	static const struct fw_address_region resp_register_region = {
		.start	= 0xffffe0000000ull,
		.end	= 0xffffe000ffffull,
	};
	int err;

	dg00x->async_handler.length = 4;
	dg00x->async_handler.address_callback = handle_message;
	dg00x->async_handler.callback_data = dg00x;

	err = fw_core_add_address_handler(&dg00x->async_handler,
					  &resp_register_region);
	if (err < 0)
		return err;

	err = snd_dg00x_transaction_reregister(dg00x);
	if (err < 0)
		snd_dg00x_transaction_unregister(dg00x);

	return err;
}


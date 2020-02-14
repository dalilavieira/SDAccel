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
struct sk_buff {int* data; } ;
struct lapb_frame {int type; int cr; int ns; int nr; unsigned char pf; unsigned char* control; } ;
struct TYPE_2__ {int cr; int /*<<< orphan*/ * control; } ;
struct lapb_cb {int mode; unsigned short va; unsigned short vs; int vr; int /*<<< orphan*/  state; int /*<<< orphan*/  dev; int /*<<< orphan*/  frmr_type; TYPE_1__ frmr_data; int /*<<< orphan*/  write_queue; int /*<<< orphan*/  ack_queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int LAPB_ADDR_A ; 
 int LAPB_ADDR_B ; 
 int LAPB_ADDR_C ; 
 int LAPB_ADDR_D ; 
 void* LAPB_COMMAND ; 
 int LAPB_DCE ; 
 int LAPB_EMODULUS ; 
 unsigned char LAPB_EPF ; 
 int LAPB_EXTENDED ; 
 void* LAPB_FRMR ; 
 scalar_t__ LAPB_HEADER_LEN ; 
 void* LAPB_I ; 
 int LAPB_ILLEGAL ; 
 int LAPB_MLP ; 
 int LAPB_RESPONSE ; 
 int LAPB_S ; 
 int LAPB_SMODULUS ; 
 unsigned char LAPB_SPF ; 
 int LAPB_U ; 
 struct sk_buff* alloc_skb (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  lapb_dbg (int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  lapb_transmit_buffer (struct lapb_cb*,struct sk_buff*,int) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_append (struct sk_buff*,struct sk_buff*,int /*<<< orphan*/ *) ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 
 scalar_t__ skb_peek (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 unsigned char* skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_queue_head (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,scalar_t__) ; 

void lapb_clear_queues(struct lapb_cb *lapb)
{
	skb_queue_purge(&lapb->write_queue);
	skb_queue_purge(&lapb->ack_queue);
}

void lapb_frames_acked(struct lapb_cb *lapb, unsigned short nr)
{
	struct sk_buff *skb;
	int modulus;

	modulus = (lapb->mode & LAPB_EXTENDED) ? LAPB_EMODULUS : LAPB_SMODULUS;

	/*
	 * Remove all the ack-ed frames from the ack queue.
	 */
	if (lapb->va != nr)
		while (skb_peek(&lapb->ack_queue) && lapb->va != nr) {
			skb = skb_dequeue(&lapb->ack_queue);
			kfree_skb(skb);
			lapb->va = (lapb->va + 1) % modulus;
		}
}

void lapb_requeue_frames(struct lapb_cb *lapb)
{
	struct sk_buff *skb, *skb_prev = NULL;

	/*
	 * Requeue all the un-ack-ed frames on the output queue to be picked
	 * up by lapb_kick called from the timer. This arrangement handles the
	 * possibility of an empty output queue.
	 */
	while ((skb = skb_dequeue(&lapb->ack_queue)) != NULL) {
		if (!skb_prev)
			skb_queue_head(&lapb->write_queue, skb);
		else
			skb_append(skb_prev, skb, &lapb->write_queue);
		skb_prev = skb;
	}
}

int lapb_validate_nr(struct lapb_cb *lapb, unsigned short nr)
{
	unsigned short vc = lapb->va;
	int modulus;

	modulus = (lapb->mode & LAPB_EXTENDED) ? LAPB_EMODULUS : LAPB_SMODULUS;

	while (vc != lapb->vs) {
		if (nr == vc)
			return 1;
		vc = (vc + 1) % modulus;
	}

	return nr == lapb->vs;
}

int lapb_decode(struct lapb_cb *lapb, struct sk_buff *skb,
		struct lapb_frame *frame)
{
	frame->type = LAPB_ILLEGAL;

	lapb_dbg(2, "(%p) S%d RX %3ph\n", lapb->dev, lapb->state, skb->data);

	/* We always need to look at 2 bytes, sometimes we need
	 * to look at 3 and those cases are handled below.
	 */
	if (!pskb_may_pull(skb, 2))
		return -1;

	if (lapb->mode & LAPB_MLP) {
		if (lapb->mode & LAPB_DCE) {
			if (skb->data[0] == LAPB_ADDR_D)
				frame->cr = LAPB_COMMAND;
			if (skb->data[0] == LAPB_ADDR_C)
				frame->cr = LAPB_RESPONSE;
		} else {
			if (skb->data[0] == LAPB_ADDR_C)
				frame->cr = LAPB_COMMAND;
			if (skb->data[0] == LAPB_ADDR_D)
				frame->cr = LAPB_RESPONSE;
		}
	} else {
		if (lapb->mode & LAPB_DCE) {
			if (skb->data[0] == LAPB_ADDR_B)
				frame->cr = LAPB_COMMAND;
			if (skb->data[0] == LAPB_ADDR_A)
				frame->cr = LAPB_RESPONSE;
		} else {
			if (skb->data[0] == LAPB_ADDR_A)
				frame->cr = LAPB_COMMAND;
			if (skb->data[0] == LAPB_ADDR_B)
				frame->cr = LAPB_RESPONSE;
		}
	}

	skb_pull(skb, 1);

	if (lapb->mode & LAPB_EXTENDED) {
		if (!(skb->data[0] & LAPB_S)) {
			if (!pskb_may_pull(skb, 2))
				return -1;
			/*
			 * I frame - carries NR/NS/PF
			 */
			frame->type       = LAPB_I;
			frame->ns         = (skb->data[0] >> 1) & 0x7F;
			frame->nr         = (skb->data[1] >> 1) & 0x7F;
			frame->pf         = skb->data[1] & LAPB_EPF;
			frame->control[0] = skb->data[0];
			frame->control[1] = skb->data[1];
			skb_pull(skb, 2);
		} else if ((skb->data[0] & LAPB_U) == 1) {
			if (!pskb_may_pull(skb, 2))
				return -1;
			/*
			 * S frame - take out PF/NR
			 */
			frame->type       = skb->data[0] & 0x0F;
			frame->nr         = (skb->data[1] >> 1) & 0x7F;
			frame->pf         = skb->data[1] & LAPB_EPF;
			frame->control[0] = skb->data[0];
			frame->control[1] = skb->data[1];
			skb_pull(skb, 2);
		} else if ((skb->data[0] & LAPB_U) == 3) {
			/*
			 * U frame - take out PF
			 */
			frame->type       = skb->data[0] & ~LAPB_SPF;
			frame->pf         = skb->data[0] & LAPB_SPF;
			frame->control[0] = skb->data[0];
			frame->control[1] = 0x00;
			skb_pull(skb, 1);
		}
	} else {
		if (!(skb->data[0] & LAPB_S)) {
			/*
			 * I frame - carries NR/NS/PF
			 */
			frame->type = LAPB_I;
			frame->ns   = (skb->data[0] >> 1) & 0x07;
			frame->nr   = (skb->data[0] >> 5) & 0x07;
			frame->pf   = skb->data[0] & LAPB_SPF;
		} else if ((skb->data[0] & LAPB_U) == 1) {
			/*
			 * S frame - take out PF/NR
			 */
			frame->type = skb->data[0] & 0x0F;
			frame->nr   = (skb->data[0] >> 5) & 0x07;
			frame->pf   = skb->data[0] & LAPB_SPF;
		} else if ((skb->data[0] & LAPB_U) == 3) {
			/*
			 * U frame - take out PF
			 */
			frame->type = skb->data[0] & ~LAPB_SPF;
			frame->pf   = skb->data[0] & LAPB_SPF;
		}

		frame->control[0] = skb->data[0];

		skb_pull(skb, 1);
	}

	return 0;
}

void lapb_send_control(struct lapb_cb *lapb, int frametype,
		       int poll_bit, int type)
{
	struct sk_buff *skb;
	unsigned char  *dptr;

	if ((skb = alloc_skb(LAPB_HEADER_LEN + 3, GFP_ATOMIC)) == NULL)
		return;

	skb_reserve(skb, LAPB_HEADER_LEN + 1);

	if (lapb->mode & LAPB_EXTENDED) {
		if ((frametype & LAPB_U) == LAPB_U) {
			dptr   = skb_put(skb, 1);
			*dptr  = frametype;
			*dptr |= poll_bit ? LAPB_SPF : 0;
		} else {
			dptr     = skb_put(skb, 2);
			dptr[0]  = frametype;
			dptr[1]  = (lapb->vr << 1);
			dptr[1] |= poll_bit ? LAPB_EPF : 0;
		}
	} else {
		dptr   = skb_put(skb, 1);
		*dptr  = frametype;
		*dptr |= poll_bit ? LAPB_SPF : 0;
		if ((frametype & LAPB_U) == LAPB_S)	/* S frames carry NR */
			*dptr |= (lapb->vr << 5);
	}

	lapb_transmit_buffer(lapb, skb, type);
}

void lapb_transmit_frmr(struct lapb_cb *lapb)
{
	struct sk_buff *skb;
	unsigned char  *dptr;

	if ((skb = alloc_skb(LAPB_HEADER_LEN + 7, GFP_ATOMIC)) == NULL)
		return;

	skb_reserve(skb, LAPB_HEADER_LEN + 1);

	if (lapb->mode & LAPB_EXTENDED) {
		dptr    = skb_put(skb, 6);
		*dptr++ = LAPB_FRMR;
		*dptr++ = lapb->frmr_data.control[0];
		*dptr++ = lapb->frmr_data.control[1];
		*dptr++ = (lapb->vs << 1) & 0xFE;
		*dptr   = (lapb->vr << 1) & 0xFE;
		if (lapb->frmr_data.cr == LAPB_RESPONSE)
			*dptr |= 0x01;
		dptr++;
		*dptr++ = lapb->frmr_type;

		lapb_dbg(1, "(%p) S%d TX FRMR %5ph\n",
			 lapb->dev, lapb->state,
			 &skb->data[1]);
	} else {
		dptr    = skb_put(skb, 4);
		*dptr++ = LAPB_FRMR;
		*dptr++ = lapb->frmr_data.control[0];
		*dptr   = (lapb->vs << 1) & 0x0E;
		*dptr  |= (lapb->vr << 5) & 0xE0;
		if (lapb->frmr_data.cr == LAPB_RESPONSE)
			*dptr |= 0x10;
		dptr++;
		*dptr++ = lapb->frmr_type;

		lapb_dbg(1, "(%p) S%d TX FRMR %3ph\n",
			 lapb->dev, lapb->state, &skb->data[1]);
	}

	lapb_transmit_buffer(lapb, skb, LAPB_RESPONSE);
}


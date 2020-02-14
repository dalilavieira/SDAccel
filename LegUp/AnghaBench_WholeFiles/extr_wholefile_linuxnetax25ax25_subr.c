#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {unsigned char* data; } ;
struct net_device {int /*<<< orphan*/  hard_header_len; } ;
typedef  int /*<<< orphan*/  ax25_digi ;
struct TYPE_28__ {unsigned short va; int modulus; unsigned short vs; int vr; int backoff; int n2count; int t1; int rtt; TYPE_4__* sk; int /*<<< orphan*/  state; int /*<<< orphan*/  t1timer; TYPE_2__* ax25_dev; int /*<<< orphan*/  write_queue; int /*<<< orphan*/  ack_queue; int /*<<< orphan*/  frag_queue; int /*<<< orphan*/  reseq_queue; } ;
typedef  TYPE_3__ ax25_cb ;
typedef  int /*<<< orphan*/  ax25_address ;
struct TYPE_29__ {int sk_err; int /*<<< orphan*/  (* sk_state_change ) (TYPE_4__*) ;int /*<<< orphan*/  sk_shutdown; int /*<<< orphan*/  sk_state; } ;
struct TYPE_27__ {TYPE_1__* dev; } ;
struct TYPE_26__ {int /*<<< orphan*/  hard_header_len; } ;

/* Variables and functions */
 unsigned char AX25_DM ; 
 unsigned char AX25_EPF ; 
 int AX25_I ; 
 int AX25_ILLEGAL ; 
 scalar_t__ AX25_MODULUS ; 
 unsigned char AX25_PF ; 
 int /*<<< orphan*/  AX25_RESPONSE ; 
 unsigned char AX25_S ; 
 int /*<<< orphan*/  AX25_STATE_0 ; 
 int AX25_T1CLAMPHI ; 
 int AX25_T1CLAMPLO ; 
 unsigned char AX25_U ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  SEND_SHUTDOWN ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  SOCK_DESTROY ; 
 int /*<<< orphan*/  TCP_CLOSE ; 
 struct sk_buff* alloc_skb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_addr_build (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ax25_addr_size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ax25_digi_invert (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ax25_display_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ax25_link_failed (TYPE_3__*,int) ; 
 int /*<<< orphan*/  ax25_queue_xmit (struct sk_buff*,struct net_device*) ; 
 int /*<<< orphan*/  ax25_stop_heartbeat (TYPE_3__*) ; 
 int /*<<< orphan*/  ax25_stop_idletimer (TYPE_3__*) ; 
 int /*<<< orphan*/  ax25_stop_t1timer (TYPE_3__*) ; 
 int /*<<< orphan*/  ax25_stop_t2timer (TYPE_3__*) ; 
 int /*<<< orphan*/  ax25_stop_t3timer (TYPE_3__*) ; 
 scalar_t__ ax25_t1timer_running (TYPE_3__*) ; 
 int /*<<< orphan*/  ax25_transmit_buffer (TYPE_3__*,struct sk_buff*,int) ; 
 int /*<<< orphan*/  bh_lock_sock (TYPE_4__*) ; 
 int /*<<< orphan*/  bh_unlock_sock (TYPE_4__*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  local_bh_disable () ; 
 int /*<<< orphan*/  local_bh_enable () ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 
 struct sk_buff* skb_dequeue_tail (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * skb_peek (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 char* skb_push (struct sk_buff*,int /*<<< orphan*/ ) ; 
 void* skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_queue_head (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  sock_flag (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_set_flag (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_4__*) ; 

void ax25_clear_queues(ax25_cb *ax25)
{
	skb_queue_purge(&ax25->write_queue);
	skb_queue_purge(&ax25->ack_queue);
	skb_queue_purge(&ax25->reseq_queue);
	skb_queue_purge(&ax25->frag_queue);
}

void ax25_frames_acked(ax25_cb *ax25, unsigned short nr)
{
	struct sk_buff *skb;

	/*
	 * Remove all the ack-ed frames from the ack queue.
	 */
	if (ax25->va != nr) {
		while (skb_peek(&ax25->ack_queue) != NULL && ax25->va != nr) {
			skb = skb_dequeue(&ax25->ack_queue);
			kfree_skb(skb);
			ax25->va = (ax25->va + 1) % ax25->modulus;
		}
	}
}

void ax25_requeue_frames(ax25_cb *ax25)
{
	struct sk_buff *skb;

	/*
	 * Requeue all the un-ack-ed frames on the output queue to be picked
	 * up by ax25_kick called from the timer. This arrangement handles the
	 * possibility of an empty output queue.
	 */
	while ((skb = skb_dequeue_tail(&ax25->ack_queue)) != NULL)
		skb_queue_head(&ax25->write_queue, skb);
}

int ax25_validate_nr(ax25_cb *ax25, unsigned short nr)
{
	unsigned short vc = ax25->va;

	while (vc != ax25->vs) {
		if (nr == vc) return 1;
		vc = (vc + 1) % ax25->modulus;
	}

	if (nr == ax25->vs) return 1;

	return 0;
}

int ax25_decode(ax25_cb *ax25, struct sk_buff *skb, int *ns, int *nr, int *pf)
{
	unsigned char *frame;
	int frametype = AX25_ILLEGAL;

	frame = skb->data;
	*ns = *nr = *pf = 0;

	if (ax25->modulus == AX25_MODULUS) {
		if ((frame[0] & AX25_S) == 0) {
			frametype = AX25_I;			/* I frame - carries NR/NS/PF */
			*ns = (frame[0] >> 1) & 0x07;
			*nr = (frame[0] >> 5) & 0x07;
			*pf = frame[0] & AX25_PF;
		} else if ((frame[0] & AX25_U) == 1) { 	/* S frame - take out PF/NR */
			frametype = frame[0] & 0x0F;
			*nr = (frame[0] >> 5) & 0x07;
			*pf = frame[0] & AX25_PF;
		} else if ((frame[0] & AX25_U) == 3) { 	/* U frame - take out PF */
			frametype = frame[0] & ~AX25_PF;
			*pf = frame[0] & AX25_PF;
		}
		skb_pull(skb, 1);
	} else {
		if ((frame[0] & AX25_S) == 0) {
			frametype = AX25_I;			/* I frame - carries NR/NS/PF */
			*ns = (frame[0] >> 1) & 0x7F;
			*nr = (frame[1] >> 1) & 0x7F;
			*pf = frame[1] & AX25_EPF;
			skb_pull(skb, 2);
		} else if ((frame[0] & AX25_U) == 1) { 	/* S frame - take out PF/NR */
			frametype = frame[0] & 0x0F;
			*nr = (frame[1] >> 1) & 0x7F;
			*pf = frame[1] & AX25_EPF;
			skb_pull(skb, 2);
		} else if ((frame[0] & AX25_U) == 3) { 	/* U frame - take out PF */
			frametype = frame[0] & ~AX25_PF;
			*pf = frame[0] & AX25_PF;
			skb_pull(skb, 1);
		}
	}

	return frametype;
}

void ax25_send_control(ax25_cb *ax25, int frametype, int poll_bit, int type)
{
	struct sk_buff *skb;
	unsigned char  *dptr;

	if ((skb = alloc_skb(ax25->ax25_dev->dev->hard_header_len + 2, GFP_ATOMIC)) == NULL)
		return;

	skb_reserve(skb, ax25->ax25_dev->dev->hard_header_len);

	skb_reset_network_header(skb);

	/* Assume a response - address structure for DTE */
	if (ax25->modulus == AX25_MODULUS) {
		dptr = skb_put(skb, 1);
		*dptr = frametype;
		*dptr |= (poll_bit) ? AX25_PF : 0;
		if ((frametype & AX25_U) == AX25_S)		/* S frames carry NR */
			*dptr |= (ax25->vr << 5);
	} else {
		if ((frametype & AX25_U) == AX25_U) {
			dptr = skb_put(skb, 1);
			*dptr = frametype;
			*dptr |= (poll_bit) ? AX25_PF : 0;
		} else {
			dptr = skb_put(skb, 2);
			dptr[0] = frametype;
			dptr[1] = (ax25->vr << 1);
			dptr[1] |= (poll_bit) ? AX25_EPF : 0;
		}
	}

	ax25_transmit_buffer(ax25, skb, type);
}

void ax25_return_dm(struct net_device *dev, ax25_address *src, ax25_address *dest, ax25_digi *digi)
{
	struct sk_buff *skb;
	char *dptr;
	ax25_digi retdigi;

	if (dev == NULL)
		return;

	if ((skb = alloc_skb(dev->hard_header_len + 1, GFP_ATOMIC)) == NULL)
		return;	/* Next SABM will get DM'd */

	skb_reserve(skb, dev->hard_header_len);
	skb_reset_network_header(skb);

	ax25_digi_invert(digi, &retdigi);

	dptr = skb_put(skb, 1);

	*dptr = AX25_DM | AX25_PF;

	/*
	 *	Do the address ourselves
	 */
	dptr  = skb_push(skb, ax25_addr_size(digi));
	dptr += ax25_addr_build(dptr, dest, src, &retdigi, AX25_RESPONSE, AX25_MODULUS);

	ax25_queue_xmit(skb, dev);
}

void ax25_calculate_t1(ax25_cb *ax25)
{
	int n, t = 2;

	switch (ax25->backoff) {
	case 0:
		break;

	case 1:
		t += 2 * ax25->n2count;
		break;

	case 2:
		for (n = 0; n < ax25->n2count; n++)
			t *= 2;
		if (t > 8) t = 8;
		break;
	}

	ax25->t1 = t * ax25->rtt;
}

void ax25_calculate_rtt(ax25_cb *ax25)
{
	if (ax25->backoff == 0)
		return;

	if (ax25_t1timer_running(ax25) && ax25->n2count == 0)
		ax25->rtt = (9 * ax25->rtt + ax25->t1 - ax25_display_timer(&ax25->t1timer)) / 10;

	if (ax25->rtt < AX25_T1CLAMPLO)
		ax25->rtt = AX25_T1CLAMPLO;

	if (ax25->rtt > AX25_T1CLAMPHI)
		ax25->rtt = AX25_T1CLAMPHI;
}

void ax25_disconnect(ax25_cb *ax25, int reason)
{
	ax25_clear_queues(ax25);

	if (!ax25->sk || !sock_flag(ax25->sk, SOCK_DESTROY))
		ax25_stop_heartbeat(ax25);
	ax25_stop_t1timer(ax25);
	ax25_stop_t2timer(ax25);
	ax25_stop_t3timer(ax25);
	ax25_stop_idletimer(ax25);

	ax25->state = AX25_STATE_0;

	ax25_link_failed(ax25, reason);

	if (ax25->sk != NULL) {
		local_bh_disable();
		bh_lock_sock(ax25->sk);
		ax25->sk->sk_state     = TCP_CLOSE;
		ax25->sk->sk_err       = reason;
		ax25->sk->sk_shutdown |= SEND_SHUTDOWN;
		if (!sock_flag(ax25->sk, SOCK_DEAD)) {
			ax25->sk->sk_state_change(ax25->sk);
			sock_set_flag(ax25->sk, SOCK_DEAD);
		}
		bh_unlock_sock(ax25->sk);
		local_bh_enable();
	}
}


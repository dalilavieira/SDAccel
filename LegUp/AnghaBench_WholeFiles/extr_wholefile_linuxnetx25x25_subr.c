#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {unsigned char cause; unsigned char diagnostic; } ;
struct TYPE_5__ {unsigned char* cuddata; int cudlength; } ;
struct TYPE_8__ {int reverse; } ;
struct x25_sock {unsigned short va; unsigned short vs; int lci; int vr; int condition; int vl; TYPE_2__ causediag; int /*<<< orphan*/  state; TYPE_3__* neighbour; TYPE_1__ calluserdata; TYPE_4__ facilities; int /*<<< orphan*/  vc_facil_mask; int /*<<< orphan*/  dte_facilities; int /*<<< orphan*/  source_addr; int /*<<< orphan*/  dest_addr; int /*<<< orphan*/  ack_queue; int /*<<< orphan*/  fragment_queue; int /*<<< orphan*/  interrupt_out_queue; int /*<<< orphan*/  interrupt_in_queue; } ;
struct sock {int sk_err; int sk_rcvbuf; int /*<<< orphan*/  sk_rmem_alloc; int /*<<< orphan*/  (* sk_state_change ) (struct sock*) ;int /*<<< orphan*/  sk_shutdown; int /*<<< orphan*/  sk_state; int /*<<< orphan*/  sk_write_queue; } ;
struct sk_buff {unsigned char* data; } ;
struct TYPE_7__ {scalar_t__ extended; int /*<<< orphan*/  global_facil_mask; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  SEND_SHUTDOWN ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  TCP_CLOSE ; 
 int /*<<< orphan*/  X25_ADDR_LEN ; 
#define  X25_CALL_ACCEPTED 143 
#define  X25_CALL_REQUEST 142 
#define  X25_CLEAR_CONFIRMATION 141 
#define  X25_CLEAR_REQUEST 140 
 int X25_COND_ACK_PENDING ; 
 int X25_COND_OWN_RX_BUSY ; 
 unsigned char X25_DATA ; 
#define  X25_DIAGNOSTIC 139 
 unsigned char X25_D_BIT ; 
 int X25_EMODULUS ; 
 int X25_EXT_MIN_LEN ; 
 unsigned char X25_EXT_M_BIT ; 
 unsigned char X25_GFI_EXTSEQ ; 
 unsigned char X25_GFI_STDSEQ ; 
 int X25_ILLEGAL ; 
#define  X25_INTERRUPT 138 
#define  X25_INTERRUPT_CONFIRMATION 137 
 int X25_MAX_CUD_LEN ; 
 int X25_MAX_FAC_LEN ; 
 int X25_MAX_L2_LEN ; 
 unsigned char X25_Q_BIT ; 
#define  X25_REGISTRATION_CONFIRMATION 136 
#define  X25_REGISTRATION_REQUEST 135 
#define  X25_REJ 134 
#define  X25_RESET_CONFIRMATION 133 
#define  X25_RESET_REQUEST 132 
#define  X25_RESTART_CONFIRMATION 131 
#define  X25_RESTART_REQUEST 130 
#define  X25_RNR 129 
#define  X25_RR 128 
 int X25_SMODULUS ; 
 int /*<<< orphan*/  X25_STATE_0 ; 
 int X25_STD_MIN_LEN ; 
 unsigned char X25_STD_M_BIT ; 
 struct sk_buff* alloc_skb (int,int /*<<< orphan*/ ) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned char*) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_append (struct sk_buff*,struct sk_buff*,int /*<<< orphan*/ *) ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 
 scalar_t__ skb_peek (int /*<<< orphan*/ *) ; 
 unsigned char* skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,unsigned char*,int) ; 
 int /*<<< orphan*/  skb_queue_head (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int) ; 
 int /*<<< orphan*/  sock_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_set_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 
 int x25_addr_aton (unsigned char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int x25_create_facilities (unsigned char*,TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct x25_sock* x25_sk (struct sock*) ; 
 int /*<<< orphan*/  x25_stop_timer (struct sock*) ; 
 int /*<<< orphan*/  x25_transmit_link (struct sk_buff*,TYPE_3__*) ; 

void x25_clear_queues(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	skb_queue_purge(&sk->sk_write_queue);
	skb_queue_purge(&x25->ack_queue);
	skb_queue_purge(&x25->interrupt_in_queue);
	skb_queue_purge(&x25->interrupt_out_queue);
	skb_queue_purge(&x25->fragment_queue);
}

void x25_frames_acked(struct sock *sk, unsigned short nr)
{
	struct sk_buff *skb;
	struct x25_sock *x25 = x25_sk(sk);
	int modulus = x25->neighbour->extended ? X25_EMODULUS : X25_SMODULUS;

	/*
	 * Remove all the ack-ed frames from the ack queue.
	 */
	if (x25->va != nr)
		while (skb_peek(&x25->ack_queue) && x25->va != nr) {
			skb = skb_dequeue(&x25->ack_queue);
			kfree_skb(skb);
			x25->va = (x25->va + 1) % modulus;
		}
}

void x25_requeue_frames(struct sock *sk)
{
	struct sk_buff *skb, *skb_prev = NULL;

	/*
	 * Requeue all the un-ack-ed frames on the output queue to be picked
	 * up by x25_kick. This arrangement handles the possibility of an empty
	 * output queue.
	 */
	while ((skb = skb_dequeue(&x25_sk(sk)->ack_queue)) != NULL) {
		if (!skb_prev)
			skb_queue_head(&sk->sk_write_queue, skb);
		else
			skb_append(skb_prev, skb, &sk->sk_write_queue);
		skb_prev = skb;
	}
}

int x25_validate_nr(struct sock *sk, unsigned short nr)
{
	struct x25_sock *x25 = x25_sk(sk);
	unsigned short vc = x25->va;
	int modulus = x25->neighbour->extended ? X25_EMODULUS : X25_SMODULUS;

	while (vc != x25->vs) {
		if (nr == vc)
			return 1;
		vc = (vc + 1) % modulus;
	}

	return nr == x25->vs ? 1 : 0;
}

void x25_write_internal(struct sock *sk, int frametype)
{
	struct x25_sock *x25 = x25_sk(sk);
	struct sk_buff *skb;
	unsigned char  *dptr;
	unsigned char  facilities[X25_MAX_FAC_LEN];
	unsigned char  addresses[1 + X25_ADDR_LEN];
	unsigned char  lci1, lci2;
	/*
	 *	Default safe frame size.
	 */
	int len = X25_MAX_L2_LEN + X25_EXT_MIN_LEN;

	/*
	 *	Adjust frame size.
	 */
	switch (frametype) {
	case X25_CALL_REQUEST:
		len += 1 + X25_ADDR_LEN + X25_MAX_FAC_LEN + X25_MAX_CUD_LEN;
		break;
	case X25_CALL_ACCEPTED: /* fast sel with no restr on resp */
		if (x25->facilities.reverse & 0x80) {
			len += 1 + X25_MAX_FAC_LEN + X25_MAX_CUD_LEN;
		} else {
			len += 1 + X25_MAX_FAC_LEN;
		}
		break;
	case X25_CLEAR_REQUEST:
	case X25_RESET_REQUEST:
		len += 2;
		break;
	case X25_RR:
	case X25_RNR:
	case X25_REJ:
	case X25_CLEAR_CONFIRMATION:
	case X25_INTERRUPT_CONFIRMATION:
	case X25_RESET_CONFIRMATION:
		break;
	default:
		pr_err("invalid frame type %02X\n", frametype);
		return;
	}

	if ((skb = alloc_skb(len, GFP_ATOMIC)) == NULL)
		return;

	/*
	 *	Space for Ethernet and 802.2 LLC headers.
	 */
	skb_reserve(skb, X25_MAX_L2_LEN);

	/*
	 *	Make space for the GFI and LCI, and fill them in.
	 */
	dptr = skb_put(skb, 2);

	lci1 = (x25->lci >> 8) & 0x0F;
	lci2 = (x25->lci >> 0) & 0xFF;

	if (x25->neighbour->extended) {
		*dptr++ = lci1 | X25_GFI_EXTSEQ;
		*dptr++ = lci2;
	} else {
		*dptr++ = lci1 | X25_GFI_STDSEQ;
		*dptr++ = lci2;
	}

	/*
	 *	Now fill in the frame type specific information.
	 */
	switch (frametype) {

		case X25_CALL_REQUEST:
			dptr    = skb_put(skb, 1);
			*dptr++ = X25_CALL_REQUEST;
			len     = x25_addr_aton(addresses, &x25->dest_addr,
						&x25->source_addr);
			skb_put_data(skb, addresses, len);
			len     = x25_create_facilities(facilities,
					&x25->facilities,
					&x25->dte_facilities,
					x25->neighbour->global_facil_mask);
			skb_put_data(skb, facilities, len);
			skb_put_data(skb, x25->calluserdata.cuddata,
				     x25->calluserdata.cudlength);
			x25->calluserdata.cudlength = 0;
			break;

		case X25_CALL_ACCEPTED:
			dptr    = skb_put(skb, 2);
			*dptr++ = X25_CALL_ACCEPTED;
			*dptr++ = 0x00;		/* Address lengths */
			len     = x25_create_facilities(facilities,
							&x25->facilities,
							&x25->dte_facilities,
							x25->vc_facil_mask);
			skb_put_data(skb, facilities, len);

			/* fast select with no restriction on response
				allows call user data. Userland must
				ensure it is ours and not theirs */
			if(x25->facilities.reverse & 0x80) {
				skb_put_data(skb,
					     x25->calluserdata.cuddata,
					     x25->calluserdata.cudlength);
			}
			x25->calluserdata.cudlength = 0;
			break;

		case X25_CLEAR_REQUEST:
			dptr    = skb_put(skb, 3);
			*dptr++ = frametype;
			*dptr++ = x25->causediag.cause;
			*dptr++ = x25->causediag.diagnostic;
			break;

		case X25_RESET_REQUEST:
			dptr    = skb_put(skb, 3);
			*dptr++ = frametype;
			*dptr++ = 0x00;		/* XXX */
			*dptr++ = 0x00;		/* XXX */
			break;

		case X25_RR:
		case X25_RNR:
		case X25_REJ:
			if (x25->neighbour->extended) {
				dptr     = skb_put(skb, 2);
				*dptr++  = frametype;
				*dptr++  = (x25->vr << 1) & 0xFE;
			} else {
				dptr     = skb_put(skb, 1);
				*dptr    = frametype;
				*dptr++ |= (x25->vr << 5) & 0xE0;
			}
			break;

		case X25_CLEAR_CONFIRMATION:
		case X25_INTERRUPT_CONFIRMATION:
		case X25_RESET_CONFIRMATION:
			dptr  = skb_put(skb, 1);
			*dptr = frametype;
			break;
	}

	x25_transmit_link(skb, x25->neighbour);
}

int x25_decode(struct sock *sk, struct sk_buff *skb, int *ns, int *nr, int *q,
	       int *d, int *m)
{
	struct x25_sock *x25 = x25_sk(sk);
	unsigned char *frame;

	if (!pskb_may_pull(skb, X25_STD_MIN_LEN))
		return X25_ILLEGAL;
	frame = skb->data;

	*ns = *nr = *q = *d = *m = 0;

	switch (frame[2]) {
	case X25_CALL_REQUEST:
	case X25_CALL_ACCEPTED:
	case X25_CLEAR_REQUEST:
	case X25_CLEAR_CONFIRMATION:
	case X25_INTERRUPT:
	case X25_INTERRUPT_CONFIRMATION:
	case X25_RESET_REQUEST:
	case X25_RESET_CONFIRMATION:
	case X25_RESTART_REQUEST:
	case X25_RESTART_CONFIRMATION:
	case X25_REGISTRATION_REQUEST:
	case X25_REGISTRATION_CONFIRMATION:
	case X25_DIAGNOSTIC:
		return frame[2];
	}

	if (x25->neighbour->extended) {
		if (frame[2] == X25_RR  ||
		    frame[2] == X25_RNR ||
		    frame[2] == X25_REJ) {
			if (!pskb_may_pull(skb, X25_EXT_MIN_LEN))
				return X25_ILLEGAL;
			frame = skb->data;

			*nr = (frame[3] >> 1) & 0x7F;
			return frame[2];
		}
	} else {
		if ((frame[2] & 0x1F) == X25_RR  ||
		    (frame[2] & 0x1F) == X25_RNR ||
		    (frame[2] & 0x1F) == X25_REJ) {
			*nr = (frame[2] >> 5) & 0x07;
			return frame[2] & 0x1F;
		}
	}

	if (x25->neighbour->extended) {
		if ((frame[2] & 0x01) == X25_DATA) {
			if (!pskb_may_pull(skb, X25_EXT_MIN_LEN))
				return X25_ILLEGAL;
			frame = skb->data;

			*q  = (frame[0] & X25_Q_BIT) == X25_Q_BIT;
			*d  = (frame[0] & X25_D_BIT) == X25_D_BIT;
			*m  = (frame[3] & X25_EXT_M_BIT) == X25_EXT_M_BIT;
			*nr = (frame[3] >> 1) & 0x7F;
			*ns = (frame[2] >> 1) & 0x7F;
			return X25_DATA;
		}
	} else {
		if ((frame[2] & 0x01) == X25_DATA) {
			*q  = (frame[0] & X25_Q_BIT) == X25_Q_BIT;
			*d  = (frame[0] & X25_D_BIT) == X25_D_BIT;
			*m  = (frame[2] & X25_STD_M_BIT) == X25_STD_M_BIT;
			*nr = (frame[2] >> 5) & 0x07;
			*ns = (frame[2] >> 1) & 0x07;
			return X25_DATA;
		}
	}

	pr_debug("invalid PLP frame %3ph\n", frame);

	return X25_ILLEGAL;
}

void x25_disconnect(struct sock *sk, int reason, unsigned char cause,
		    unsigned char diagnostic)
{
	struct x25_sock *x25 = x25_sk(sk);

	x25_clear_queues(sk);
	x25_stop_timer(sk);

	x25->lci   = 0;
	x25->state = X25_STATE_0;

	x25->causediag.cause      = cause;
	x25->causediag.diagnostic = diagnostic;

	sk->sk_state     = TCP_CLOSE;
	sk->sk_err       = reason;
	sk->sk_shutdown |= SEND_SHUTDOWN;

	if (!sock_flag(sk, SOCK_DEAD)) {
		sk->sk_state_change(sk);
		sock_set_flag(sk, SOCK_DEAD);
	}
}

void x25_check_rbuf(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	if (atomic_read(&sk->sk_rmem_alloc) < (sk->sk_rcvbuf >> 1) &&
	    (x25->condition & X25_COND_OWN_RX_BUSY)) {
		x25->condition &= ~X25_COND_OWN_RX_BUSY;
		x25->condition &= ~X25_COND_ACK_PENDING;
		x25->vl         = x25->vr;
		x25_write_internal(sk, X25_RR);
		x25_stop_timer(sk);
	}
}


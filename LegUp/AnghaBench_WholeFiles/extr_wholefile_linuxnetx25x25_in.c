#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int winsize_in; } ;
struct TYPE_4__ {int cudlength; int /*<<< orphan*/  cuddata; } ;
struct x25_sock {int fraglen; int condition; int vr; int vl; int state; int /*<<< orphan*/  vs; int /*<<< orphan*/  va; int /*<<< orphan*/  interrupt_in_queue; int /*<<< orphan*/  flags; TYPE_3__ facilities; TYPE_2__* neighbour; TYPE_1__ calluserdata; int /*<<< orphan*/  vc_facil_mask; int /*<<< orphan*/  dte_facilities; int /*<<< orphan*/  fragment_queue; } ;
struct x25_address {int dummy; } ;
struct sock {int sk_rcvbuf; int /*<<< orphan*/  sk_rmem_alloc; int /*<<< orphan*/  (* sk_state_change ) (struct sock*) ;int /*<<< orphan*/  sk_state; int /*<<< orphan*/  (* sk_data_ready ) (struct sock*) ;int /*<<< orphan*/  sk_receive_queue; } ;
struct sk_buff {int len; int /*<<< orphan*/ * data; } ;
struct TYPE_5__ {scalar_t__ extended; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECONNREFUSED ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  SOCK_URGINLINE ; 
 int /*<<< orphan*/  TCP_ESTABLISHED ; 
#define  X25_CALL_ACCEPTED 141 
#define  X25_CLEAR_CONFIRMATION 140 
#define  X25_CLEAR_REQUEST 139 
 int X25_COND_ACK_PENDING ; 
 int X25_COND_OWN_RX_BUSY ; 
 int X25_COND_PEER_RX_BUSY ; 
#define  X25_DATA 138 
 int X25_EMODULUS ; 
 int X25_EXT_MIN_LEN ; 
#define  X25_INTERRUPT 137 
#define  X25_INTERRUPT_CONFIRMATION 136 
 int /*<<< orphan*/  X25_INTERRUPT_FLAG ; 
 int X25_MAX_CUD_LEN ; 
#define  X25_RESET_CONFIRMATION 135 
#define  X25_RESET_REQUEST 134 
#define  X25_RNR 133 
#define  X25_RR 132 
 int X25_SMODULUS ; 
 int X25_STATE_0 ; 
#define  X25_STATE_1 131 
#define  X25_STATE_2 130 
#define  X25_STATE_3 129 
#define  X25_STATE_4 128 
 int X25_STD_MIN_LEN ; 
 struct sk_buff* alloc_skb (int,int /*<<< orphan*/ ) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  sk_send_sigurg (struct sock*) ; 
 int /*<<< orphan*/  skb_copy_bits (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  skb_copy_from_linear_data (struct sk_buff*,int /*<<< orphan*/ ,int) ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_transport_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_owner_r (struct sk_buff*,struct sock*) ; 
 scalar_t__ sock_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_queue_rcv_skb (struct sock*,struct sk_buff*) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 
 int /*<<< orphan*/  stub2 (struct sock*) ; 
 int /*<<< orphan*/  x25_clear_queues (struct sock*) ; 
 int x25_decode (struct sock*,struct sk_buff*,int*,int*,int*,int*,int*) ; 
 int /*<<< orphan*/  x25_disconnect (struct sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  x25_enquiry_response (struct sock*) ; 
 int /*<<< orphan*/  x25_frames_acked (struct sock*,int) ; 
 int /*<<< orphan*/  x25_kick (struct sock*) ; 
 int x25_parse_address_block (struct sk_buff*,struct x25_address*,struct x25_address*) ; 
 int x25_parse_facilities (struct sk_buff*,TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  x25_requeue_frames (struct sock*) ; 
 struct x25_sock* x25_sk (struct sock*) ; 
 int /*<<< orphan*/  x25_start_t22timer (struct sock*) ; 
 int /*<<< orphan*/  x25_start_t23timer (struct sock*) ; 
 int /*<<< orphan*/  x25_start_t2timer (struct sock*) ; 
 int /*<<< orphan*/  x25_stop_timer (struct sock*) ; 
 int /*<<< orphan*/  x25_validate_nr (struct sock*,int) ; 
 int /*<<< orphan*/  x25_write_internal (struct sock*,int const) ; 

__attribute__((used)) static int x25_queue_rx_frame(struct sock *sk, struct sk_buff *skb, int more)
{
	struct sk_buff *skbo, *skbn = skb;
	struct x25_sock *x25 = x25_sk(sk);

	if (more) {
		x25->fraglen += skb->len;
		skb_queue_tail(&x25->fragment_queue, skb);
		skb_set_owner_r(skb, sk);
		return 0;
	}

	if (!more && x25->fraglen > 0) {	/* End of fragment */
		int len = x25->fraglen + skb->len;

		if ((skbn = alloc_skb(len, GFP_ATOMIC)) == NULL){
			kfree_skb(skb);
			return 1;
		}

		skb_queue_tail(&x25->fragment_queue, skb);

		skb_reset_transport_header(skbn);

		skbo = skb_dequeue(&x25->fragment_queue);
		skb_copy_from_linear_data(skbo, skb_put(skbn, skbo->len),
					  skbo->len);
		kfree_skb(skbo);

		while ((skbo =
			skb_dequeue(&x25->fragment_queue)) != NULL) {
			skb_pull(skbo, (x25->neighbour->extended) ?
					X25_EXT_MIN_LEN : X25_STD_MIN_LEN);
			skb_copy_from_linear_data(skbo,
						  skb_put(skbn, skbo->len),
						  skbo->len);
			kfree_skb(skbo);
		}

		x25->fraglen = 0;
	}

	skb_set_owner_r(skbn, sk);
	skb_queue_tail(&sk->sk_receive_queue, skbn);
	if (!sock_flag(sk, SOCK_DEAD))
		sk->sk_data_ready(sk);

	return 0;
}

__attribute__((used)) static int x25_state1_machine(struct sock *sk, struct sk_buff *skb, int frametype)
{
	struct x25_address source_addr, dest_addr;
	int len;
	struct x25_sock *x25 = x25_sk(sk);

	switch (frametype) {
	case X25_CALL_ACCEPTED: {

		x25_stop_timer(sk);
		x25->condition = 0x00;
		x25->vs        = 0;
		x25->va        = 0;
		x25->vr        = 0;
		x25->vl        = 0;
		x25->state     = X25_STATE_3;
		sk->sk_state   = TCP_ESTABLISHED;
		/*
		 *	Parse the data in the frame.
		 */
		if (!pskb_may_pull(skb, X25_STD_MIN_LEN))
			goto out_clear;
		skb_pull(skb, X25_STD_MIN_LEN);

		len = x25_parse_address_block(skb, &source_addr,
					      &dest_addr);
		if (len > 0)
			skb_pull(skb, len);
		else if (len < 0)
			goto out_clear;

		len = x25_parse_facilities(skb, &x25->facilities,
					   &x25->dte_facilities,
					   &x25->vc_facil_mask);
		if (len > 0)
			skb_pull(skb, len);
		else if (len < 0)
			goto out_clear;
		/*
		 *	Copy any Call User Data.
		 */
		if (skb->len > 0) {
			if (skb->len > X25_MAX_CUD_LEN)
				goto out_clear;

			skb_copy_bits(skb, 0, x25->calluserdata.cuddata,
				skb->len);
			x25->calluserdata.cudlength = skb->len;
		}
		if (!sock_flag(sk, SOCK_DEAD))
			sk->sk_state_change(sk);
		break;
	}
	case X25_CLEAR_REQUEST:
		if (!pskb_may_pull(skb, X25_STD_MIN_LEN + 2))
			goto out_clear;

		x25_write_internal(sk, X25_CLEAR_CONFIRMATION);
		x25_disconnect(sk, ECONNREFUSED, skb->data[3], skb->data[4]);
		break;

	default:
		break;
	}

	return 0;

out_clear:
	x25_write_internal(sk, X25_CLEAR_REQUEST);
	x25->state = X25_STATE_2;
	x25_start_t23timer(sk);
	return 0;
}

__attribute__((used)) static int x25_state2_machine(struct sock *sk, struct sk_buff *skb, int frametype)
{
	switch (frametype) {

		case X25_CLEAR_REQUEST:
			if (!pskb_may_pull(skb, X25_STD_MIN_LEN + 2))
				goto out_clear;

			x25_write_internal(sk, X25_CLEAR_CONFIRMATION);
			x25_disconnect(sk, 0, skb->data[3], skb->data[4]);
			break;

		case X25_CLEAR_CONFIRMATION:
			x25_disconnect(sk, 0, 0, 0);
			break;

		default:
			break;
	}

	return 0;

out_clear:
	x25_write_internal(sk, X25_CLEAR_REQUEST);
	x25_start_t23timer(sk);
	return 0;
}

__attribute__((used)) static int x25_state3_machine(struct sock *sk, struct sk_buff *skb, int frametype, int ns, int nr, int q, int d, int m)
{
	int queued = 0;
	int modulus;
	struct x25_sock *x25 = x25_sk(sk);

	modulus = (x25->neighbour->extended) ? X25_EMODULUS : X25_SMODULUS;

	switch (frametype) {

		case X25_RESET_REQUEST:
			x25_write_internal(sk, X25_RESET_CONFIRMATION);
			x25_stop_timer(sk);
			x25->condition = 0x00;
			x25->vs        = 0;
			x25->vr        = 0;
			x25->va        = 0;
			x25->vl        = 0;
			x25_requeue_frames(sk);
			break;

		case X25_CLEAR_REQUEST:
			if (!pskb_may_pull(skb, X25_STD_MIN_LEN + 2))
				goto out_clear;

			x25_write_internal(sk, X25_CLEAR_CONFIRMATION);
			x25_disconnect(sk, 0, skb->data[3], skb->data[4]);
			break;

		case X25_RR:
		case X25_RNR:
			if (!x25_validate_nr(sk, nr)) {
				x25_clear_queues(sk);
				x25_write_internal(sk, X25_RESET_REQUEST);
				x25_start_t22timer(sk);
				x25->condition = 0x00;
				x25->vs        = 0;
				x25->vr        = 0;
				x25->va        = 0;
				x25->vl        = 0;
				x25->state     = X25_STATE_4;
			} else {
				x25_frames_acked(sk, nr);
				if (frametype == X25_RNR) {
					x25->condition |= X25_COND_PEER_RX_BUSY;
				} else {
					x25->condition &= ~X25_COND_PEER_RX_BUSY;
				}
			}
			break;

		case X25_DATA:	/* XXX */
			x25->condition &= ~X25_COND_PEER_RX_BUSY;
			if ((ns != x25->vr) || !x25_validate_nr(sk, nr)) {
				x25_clear_queues(sk);
				x25_write_internal(sk, X25_RESET_REQUEST);
				x25_start_t22timer(sk);
				x25->condition = 0x00;
				x25->vs        = 0;
				x25->vr        = 0;
				x25->va        = 0;
				x25->vl        = 0;
				x25->state     = X25_STATE_4;
				break;
			}
			x25_frames_acked(sk, nr);
			if (ns == x25->vr) {
				if (x25_queue_rx_frame(sk, skb, m) == 0) {
					x25->vr = (x25->vr + 1) % modulus;
					queued = 1;
				} else {
					/* Should never happen */
					x25_clear_queues(sk);
					x25_write_internal(sk, X25_RESET_REQUEST);
					x25_start_t22timer(sk);
					x25->condition = 0x00;
					x25->vs        = 0;
					x25->vr        = 0;
					x25->va        = 0;
					x25->vl        = 0;
					x25->state     = X25_STATE_4;
					break;
				}
				if (atomic_read(&sk->sk_rmem_alloc) >
				    (sk->sk_rcvbuf >> 1))
					x25->condition |= X25_COND_OWN_RX_BUSY;
			}
			/*
			 *	If the window is full Ack it immediately, else
			 *	start the holdback timer.
			 */
			if (((x25->vl + x25->facilities.winsize_in) % modulus) == x25->vr) {
				x25->condition &= ~X25_COND_ACK_PENDING;
				x25_stop_timer(sk);
				x25_enquiry_response(sk);
			} else {
				x25->condition |= X25_COND_ACK_PENDING;
				x25_start_t2timer(sk);
			}
			break;

		case X25_INTERRUPT_CONFIRMATION:
			clear_bit(X25_INTERRUPT_FLAG, &x25->flags);
			break;

		case X25_INTERRUPT:
			if (sock_flag(sk, SOCK_URGINLINE))
				queued = !sock_queue_rcv_skb(sk, skb);
			else {
				skb_set_owner_r(skb, sk);
				skb_queue_tail(&x25->interrupt_in_queue, skb);
				queued = 1;
			}
			sk_send_sigurg(sk);
			x25_write_internal(sk, X25_INTERRUPT_CONFIRMATION);
			break;

		default:
			pr_warn("unknown %02X in state 3\n", frametype);
			break;
	}

	return queued;

out_clear:
	x25_write_internal(sk, X25_CLEAR_REQUEST);
	x25->state = X25_STATE_2;
	x25_start_t23timer(sk);
	return 0;
}

__attribute__((used)) static int x25_state4_machine(struct sock *sk, struct sk_buff *skb, int frametype)
{
	struct x25_sock *x25 = x25_sk(sk);

	switch (frametype) {

		case X25_RESET_REQUEST:
			x25_write_internal(sk, X25_RESET_CONFIRMATION);
			/* fall through */
		case X25_RESET_CONFIRMATION: {
			x25_stop_timer(sk);
			x25->condition = 0x00;
			x25->va        = 0;
			x25->vr        = 0;
			x25->vs        = 0;
			x25->vl        = 0;
			x25->state     = X25_STATE_3;
			x25_requeue_frames(sk);
			break;
		}
		case X25_CLEAR_REQUEST:
			if (!pskb_may_pull(skb, X25_STD_MIN_LEN + 2))
				goto out_clear;

			x25_write_internal(sk, X25_CLEAR_CONFIRMATION);
			x25_disconnect(sk, 0, skb->data[3], skb->data[4]);
			break;

		default:
			break;
	}

	return 0;

out_clear:
	x25_write_internal(sk, X25_CLEAR_REQUEST);
	x25->state = X25_STATE_2;
	x25_start_t23timer(sk);
	return 0;
}

int x25_process_rx_frame(struct sock *sk, struct sk_buff *skb)
{
	struct x25_sock *x25 = x25_sk(sk);
	int queued = 0, frametype, ns, nr, q, d, m;

	if (x25->state == X25_STATE_0)
		return 0;

	frametype = x25_decode(sk, skb, &ns, &nr, &q, &d, &m);

	switch (x25->state) {
	case X25_STATE_1:
		queued = x25_state1_machine(sk, skb, frametype);
		break;
	case X25_STATE_2:
		queued = x25_state2_machine(sk, skb, frametype);
		break;
	case X25_STATE_3:
		queued = x25_state3_machine(sk, skb, frametype, ns, nr, q, d, m);
		break;
	case X25_STATE_4:
		queued = x25_state4_machine(sk, skb, frametype);
		break;
	}

	x25_kick(sk);

	return queued;
}

int x25_backlog_rcv(struct sock *sk, struct sk_buff *skb)
{
	int queued = x25_process_rx_frame(sk, skb);

	if (!queued)
		kfree_skb(skb);

	return 0;
}


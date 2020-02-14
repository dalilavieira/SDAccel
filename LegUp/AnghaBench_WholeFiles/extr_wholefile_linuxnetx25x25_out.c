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
struct TYPE_4__ {unsigned int pacsize_out; int winsize_out; } ;
struct x25_sock {int vs; int vr; scalar_t__ state; int condition; unsigned short va; int vl; int /*<<< orphan*/  ack_queue; TYPE_1__ facilities; TYPE_2__* neighbour; int /*<<< orphan*/  interrupt_out_queue; int /*<<< orphan*/  flags; } ;
struct sock {int /*<<< orphan*/  sk_write_queue; } ;
struct sk_buff {int len; int* data; } ;
struct TYPE_6__ {int flags; } ;
struct TYPE_5__ {scalar_t__ extended; } ;

/* Variables and functions */
 int EWOULDBLOCK ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int MSG_DONTWAIT ; 
 int /*<<< orphan*/  SOCK_DEBUG (struct sock*,char*,int,int) ; 
 int X25_COND_ACK_PENDING ; 
 int X25_COND_OWN_RX_BUSY ; 
 int X25_COND_PEER_RX_BUSY ; 
 int X25_EMODULUS ; 
 int X25_EXT_MIN_LEN ; 
 int X25_EXT_M_BIT ; 
 int /*<<< orphan*/  X25_INTERRUPT_FLAG ; 
 int /*<<< orphan*/  X25_RNR ; 
 int /*<<< orphan*/  X25_RR ; 
 TYPE_3__* X25_SKB_CB (struct sk_buff*) ; 
 int X25_SMODULUS ; 
 scalar_t__ X25_STATE_3 ; 
 int X25_STD_MIN_LEN ; 
 int X25_STD_M_BIT ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  lock_sock (struct sock*) ; 
 int /*<<< orphan*/  release_sock (struct sock*) ; 
 struct sk_buff* skb_clone (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_copy_from_linear_data (struct sk_buff*,unsigned char*,int) ; 
 int /*<<< orphan*/  skb_copy_to_linear_data (struct sk_buff*,unsigned char*,int) ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 
 int skb_headroom (struct sk_buff*) ; 
 int /*<<< orphan*/ * skb_peek (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,int) ; 
 unsigned char* skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_queue_head (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_set_owner_w (struct sk_buff*,struct sock*) ; 
 struct sk_buff* sock_alloc_send_skb (struct sock*,int,int,int*) ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct x25_sock* x25_sk (struct sock*) ; 
 int /*<<< orphan*/  x25_stop_timer (struct sock*) ; 
 int /*<<< orphan*/  x25_transmit_link (struct sk_buff*,TYPE_2__*) ; 
 int /*<<< orphan*/  x25_write_internal (struct sock*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int x25_pacsize_to_bytes(unsigned int pacsize)
{
	int bytes = 1;

	if (!pacsize)
		return 128;

	while (pacsize-- > 0)
		bytes *= 2;

	return bytes;
}

int x25_output(struct sock *sk, struct sk_buff *skb)
{
	struct sk_buff *skbn;
	unsigned char header[X25_EXT_MIN_LEN];
	int err, frontlen, len;
	int sent=0, noblock = X25_SKB_CB(skb)->flags & MSG_DONTWAIT;
	struct x25_sock *x25 = x25_sk(sk);
	int header_len = x25->neighbour->extended ? X25_EXT_MIN_LEN :
						    X25_STD_MIN_LEN;
	int max_len = x25_pacsize_to_bytes(x25->facilities.pacsize_out);

	if (skb->len - header_len > max_len) {
		/* Save a copy of the Header */
		skb_copy_from_linear_data(skb, header, header_len);
		skb_pull(skb, header_len);

		frontlen = skb_headroom(skb);

		while (skb->len > 0) {
			release_sock(sk);
			skbn = sock_alloc_send_skb(sk, frontlen + max_len,
						   noblock, &err);
			lock_sock(sk);
			if (!skbn) {
				if (err == -EWOULDBLOCK && noblock){
					kfree_skb(skb);
					return sent;
				}
				SOCK_DEBUG(sk, "x25_output: fragment alloc"
					       " failed, err=%d, %d bytes "
					       "sent\n", err, sent);
				return err;
			}

			skb_reserve(skbn, frontlen);

			len = max_len > skb->len ? skb->len : max_len;

			/* Copy the user data */
			skb_copy_from_linear_data(skb, skb_put(skbn, len), len);
			skb_pull(skb, len);

			/* Duplicate the Header */
			skb_push(skbn, header_len);
			skb_copy_to_linear_data(skbn, header, header_len);

			if (skb->len > 0) {
				if (x25->neighbour->extended)
					skbn->data[3] |= X25_EXT_M_BIT;
				else
					skbn->data[2] |= X25_STD_M_BIT;
			}

			skb_queue_tail(&sk->sk_write_queue, skbn);
			sent += len;
		}

		kfree_skb(skb);
	} else {
		skb_queue_tail(&sk->sk_write_queue, skb);
		sent = skb->len - header_len;
	}
	return sent;
}

__attribute__((used)) static void x25_send_iframe(struct sock *sk, struct sk_buff *skb)
{
	struct x25_sock *x25 = x25_sk(sk);

	if (!skb)
		return;

	if (x25->neighbour->extended) {
		skb->data[2]  = (x25->vs << 1) & 0xFE;
		skb->data[3] &= X25_EXT_M_BIT;
		skb->data[3] |= (x25->vr << 1) & 0xFE;
	} else {
		skb->data[2] &= X25_STD_M_BIT;
		skb->data[2] |= (x25->vs << 1) & 0x0E;
		skb->data[2] |= (x25->vr << 5) & 0xE0;
	}

	x25_transmit_link(skb, x25->neighbour);
}

void x25_kick(struct sock *sk)
{
	struct sk_buff *skb, *skbn;
	unsigned short start, end;
	int modulus;
	struct x25_sock *x25 = x25_sk(sk);

	if (x25->state != X25_STATE_3)
		return;

	/*
	 *	Transmit interrupt data.
	 */
	if (skb_peek(&x25->interrupt_out_queue) != NULL &&
		!test_and_set_bit(X25_INTERRUPT_FLAG, &x25->flags)) {

		skb = skb_dequeue(&x25->interrupt_out_queue);
		x25_transmit_link(skb, x25->neighbour);
	}

	if (x25->condition & X25_COND_PEER_RX_BUSY)
		return;

	if (!skb_peek(&sk->sk_write_queue))
		return;

	modulus = x25->neighbour->extended ? X25_EMODULUS : X25_SMODULUS;

	start   = skb_peek(&x25->ack_queue) ? x25->vs : x25->va;
	end     = (x25->va + x25->facilities.winsize_out) % modulus;

	if (start == end)
		return;

	x25->vs = start;

	/*
	 * Transmit data until either we're out of data to send or
	 * the window is full.
	 */

	skb = skb_dequeue(&sk->sk_write_queue);

	do {
		if ((skbn = skb_clone(skb, GFP_ATOMIC)) == NULL) {
			skb_queue_head(&sk->sk_write_queue, skb);
			break;
		}

		skb_set_owner_w(skbn, sk);

		/*
		 * Transmit the frame copy.
		 */
		x25_send_iframe(sk, skbn);

		x25->vs = (x25->vs + 1) % modulus;

		/*
		 * Requeue the original data frame.
		 */
		skb_queue_tail(&x25->ack_queue, skb);

	} while (x25->vs != end &&
		 (skb = skb_dequeue(&sk->sk_write_queue)) != NULL);

	x25->vl         = x25->vr;
	x25->condition &= ~X25_COND_ACK_PENDING;

	x25_stop_timer(sk);
}

void x25_enquiry_response(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	if (x25->condition & X25_COND_OWN_RX_BUSY)
		x25_write_internal(sk, X25_RNR);
	else
		x25_write_internal(sk, X25_RR);

	x25->vl         = x25->vr;
	x25->condition &= ~X25_COND_ACK_PENDING;

	x25_stop_timer(sk);
}


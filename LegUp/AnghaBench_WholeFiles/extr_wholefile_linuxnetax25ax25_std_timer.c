#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct sock {int sk_rcvbuf; int /*<<< orphan*/  (* sk_state_change ) (struct sock*) ;int /*<<< orphan*/  sk_shutdown; scalar_t__ sk_err; int /*<<< orphan*/  sk_state; int /*<<< orphan*/  sk_rmem_alloc; } ;
struct TYPE_20__ {int state; int condition; int n2count; int n2; struct sock* sk; int /*<<< orphan*/  modulus; TYPE_1__* ax25_dev; int /*<<< orphan*/  window; } ;
typedef  TYPE_2__ ax25_cb ;
struct TYPE_19__ {int /*<<< orphan*/ * values; } ;

/* Variables and functions */
 int /*<<< orphan*/  AX25_COMMAND ; 
 int AX25_COND_ACK_PENDING ; 
 int AX25_COND_OWN_RX_BUSY ; 
 int /*<<< orphan*/  AX25_DISC ; 
 int /*<<< orphan*/  AX25_DM ; 
 int /*<<< orphan*/  AX25_MODULUS ; 
 int /*<<< orphan*/  AX25_POLLOFF ; 
 int /*<<< orphan*/  AX25_POLLON ; 
 int /*<<< orphan*/  AX25_RESPONSE ; 
 int /*<<< orphan*/  AX25_RR ; 
 int /*<<< orphan*/  AX25_SABM ; 
 int /*<<< orphan*/  AX25_SABME ; 
#define  AX25_STATE_0 132 
#define  AX25_STATE_1 131 
#define  AX25_STATE_2 130 
#define  AX25_STATE_3 129 
#define  AX25_STATE_4 128 
 size_t AX25_VALUES_WINDOW ; 
 int /*<<< orphan*/  ETIMEDOUT ; 
 int /*<<< orphan*/  SEND_SHUTDOWN ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  SOCK_DESTROY ; 
 int /*<<< orphan*/  TCP_CLOSE ; 
 int /*<<< orphan*/  TCP_LISTEN ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ax25_calculate_t1 (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_clear_queues (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_destroy_socket (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_disconnect (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_send_control (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_start_heartbeat (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_start_t1timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_timeout_response (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_transmit_enquiry (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_stop_t2timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_stop_t3timer (TYPE_2__*) ; 
 int /*<<< orphan*/  bh_lock_sock (struct sock*) ; 
 int /*<<< orphan*/  bh_unlock_sock (struct sock*) ; 
 scalar_t__ sock_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_hold (struct sock*) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 
 int /*<<< orphan*/  sock_set_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 

void ax25_std_heartbeat_expiry(ax25_cb *ax25)
{
	struct sock *sk = ax25->sk;

	if (sk)
		bh_lock_sock(sk);

	switch (ax25->state) {
	case AX25_STATE_0:
	case AX25_STATE_2:
		/* Magic here: If we listen() and a new link dies before it
		   is accepted() it isn't 'dead' so doesn't get removed. */
		if (!sk || sock_flag(sk, SOCK_DESTROY) ||
		    (sk->sk_state == TCP_LISTEN &&
		     sock_flag(sk, SOCK_DEAD))) {
			if (sk) {
				sock_hold(sk);
				ax25_destroy_socket(ax25);
				bh_unlock_sock(sk);
				/* Ungrab socket and destroy it */
				sock_put(sk);
			} else
				ax25_destroy_socket(ax25);
			return;
		}
		break;

	case AX25_STATE_3:
	case AX25_STATE_4:
		/*
		 * Check the state of the receive buffer.
		 */
		if (sk != NULL) {
			if (atomic_read(&sk->sk_rmem_alloc) <
			    (sk->sk_rcvbuf >> 1) &&
			    (ax25->condition & AX25_COND_OWN_RX_BUSY)) {
				ax25->condition &= ~AX25_COND_OWN_RX_BUSY;
				ax25->condition &= ~AX25_COND_ACK_PENDING;
				ax25_send_control(ax25, AX25_RR, AX25_POLLOFF, AX25_RESPONSE);
				break;
			}
		}
	}

	if (sk)
		bh_unlock_sock(sk);

	ax25_start_heartbeat(ax25);
}

void ax25_std_t2timer_expiry(ax25_cb *ax25)
{
	if (ax25->condition & AX25_COND_ACK_PENDING) {
		ax25->condition &= ~AX25_COND_ACK_PENDING;
		ax25_std_timeout_response(ax25);
	}
}

void ax25_std_t3timer_expiry(ax25_cb *ax25)
{
	ax25->n2count = 0;
	ax25_std_transmit_enquiry(ax25);
	ax25->state   = AX25_STATE_4;
}

void ax25_std_idletimer_expiry(ax25_cb *ax25)
{
	ax25_clear_queues(ax25);

	ax25->n2count = 0;
	ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
	ax25->state   = AX25_STATE_2;

	ax25_calculate_t1(ax25);
	ax25_start_t1timer(ax25);
	ax25_stop_t2timer(ax25);
	ax25_stop_t3timer(ax25);

	if (ax25->sk != NULL) {
		bh_lock_sock(ax25->sk);
		ax25->sk->sk_state     = TCP_CLOSE;
		ax25->sk->sk_err       = 0;
		ax25->sk->sk_shutdown |= SEND_SHUTDOWN;
		if (!sock_flag(ax25->sk, SOCK_DEAD)) {
			ax25->sk->sk_state_change(ax25->sk);
			sock_set_flag(ax25->sk, SOCK_DEAD);
		}
		bh_unlock_sock(ax25->sk);
	}
}

void ax25_std_t1timer_expiry(ax25_cb *ax25)
{
	switch (ax25->state) {
	case AX25_STATE_1:
		if (ax25->n2count == ax25->n2) {
			if (ax25->modulus == AX25_MODULUS) {
				ax25_disconnect(ax25, ETIMEDOUT);
				return;
			} else {
				ax25->modulus = AX25_MODULUS;
				ax25->window  = ax25->ax25_dev->values[AX25_VALUES_WINDOW];
				ax25->n2count = 0;
				ax25_send_control(ax25, AX25_SABM, AX25_POLLON, AX25_COMMAND);
			}
		} else {
			ax25->n2count++;
			if (ax25->modulus == AX25_MODULUS)
				ax25_send_control(ax25, AX25_SABM, AX25_POLLON, AX25_COMMAND);
			else
				ax25_send_control(ax25, AX25_SABME, AX25_POLLON, AX25_COMMAND);
		}
		break;

	case AX25_STATE_2:
		if (ax25->n2count == ax25->n2) {
			ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
			if (!sock_flag(ax25->sk, SOCK_DESTROY))
				ax25_disconnect(ax25, ETIMEDOUT);
			return;
		} else {
			ax25->n2count++;
			ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
		}
		break;

	case AX25_STATE_3:
		ax25->n2count = 1;
		ax25_std_transmit_enquiry(ax25);
		ax25->state   = AX25_STATE_4;
		break;

	case AX25_STATE_4:
		if (ax25->n2count == ax25->n2) {
			ax25_send_control(ax25, AX25_DM, AX25_POLLON, AX25_RESPONSE);
			ax25_disconnect(ax25, ETIMEDOUT);
			return;
		} else {
			ax25->n2count++;
			ax25_std_transmit_enquiry(ax25);
		}
		break;
	}

	ax25_calculate_t1(ax25);
	ax25_start_t1timer(ax25);
}


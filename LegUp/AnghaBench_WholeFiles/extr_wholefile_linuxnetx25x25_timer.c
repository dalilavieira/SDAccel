#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {void (* function ) (struct timer_list*) ;unsigned long expires; } ;
struct sock {int /*<<< orphan*/  sk_state; TYPE_1__ sk_timer; } ;
struct x25_sock {unsigned long t2; unsigned long t21; unsigned long t22; unsigned long t23; int state; int condition; struct sock sk; TYPE_1__ timer; } ;
struct timer_list {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETIMEDOUT ; 
 int HZ ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  SOCK_DESTROY ; 
 int /*<<< orphan*/  TCP_LISTEN ; 
 int /*<<< orphan*/  X25_CLEAR_REQUEST ; 
 int X25_COND_ACK_PENDING ; 
#define  X25_STATE_0 132 
#define  X25_STATE_1 131 
#define  X25_STATE_2 130 
#define  X25_STATE_3 129 
#define  X25_STATE_4 128 
 int /*<<< orphan*/  bh_lock_sock (struct sock*) ; 
 int /*<<< orphan*/  bh_unlock_sock (struct sock*) ; 
 int /*<<< orphan*/  del_timer (TYPE_1__*) ; 
 void* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  mod_timer (TYPE_1__*,unsigned long) ; 
 struct sock* sk ; 
 int /*<<< orphan*/  sk_timer ; 
 int /*<<< orphan*/  sock_flag (struct sock*,int /*<<< orphan*/ ) ; 
 scalar_t__ sock_owned_by_user (struct sock*) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_pending (TYPE_1__*) ; 
 int /*<<< orphan*/  timer_setup (TYPE_1__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 struct x25_sock* x25 ; 
 int /*<<< orphan*/  x25_check_rbuf (struct sock*) ; 
 int /*<<< orphan*/  x25_destroy_socket_from_timer (struct sock*) ; 
 int /*<<< orphan*/  x25_disconnect (struct sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  x25_enquiry_response (struct sock*) ; 
static  void x25_heartbeat_expiry (struct timer_list*) ; 
 struct x25_sock* x25_sk (struct sock*) ; 
static  void x25_timer_expiry (struct timer_list*) ; 
 int /*<<< orphan*/  x25_write_internal (struct sock*,int /*<<< orphan*/ ) ; 

void x25_init_timers(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	timer_setup(&x25->timer, x25_timer_expiry, 0);

	/* initialized by sock_init_data */
	sk->sk_timer.function = x25_heartbeat_expiry;
}

void x25_start_heartbeat(struct sock *sk)
{
	mod_timer(&sk->sk_timer, jiffies + 5 * HZ);
}

void x25_stop_heartbeat(struct sock *sk)
{
	del_timer(&sk->sk_timer);
}

void x25_start_t2timer(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	mod_timer(&x25->timer, jiffies + x25->t2);
}

void x25_start_t21timer(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	mod_timer(&x25->timer, jiffies + x25->t21);
}

void x25_start_t22timer(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	mod_timer(&x25->timer, jiffies + x25->t22);
}

void x25_start_t23timer(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	mod_timer(&x25->timer, jiffies + x25->t23);
}

void x25_stop_timer(struct sock *sk)
{
	del_timer(&x25_sk(sk)->timer);
}

unsigned long x25_display_timer(struct sock *sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	if (!timer_pending(&x25->timer))
		return 0;

	return x25->timer.expires - jiffies;
}

__attribute__((used)) static void x25_heartbeat_expiry(struct timer_list *t)
{
	struct sock *sk = from_timer(sk, t, sk_timer);

	bh_lock_sock(sk);
	if (sock_owned_by_user(sk)) /* can currently only occur in state 3 */
		goto restart_heartbeat;

	switch (x25_sk(sk)->state) {

		case X25_STATE_0:
			/*
			 * Magic here: If we listen() and a new link dies
			 * before it is accepted() it isn't 'dead' so doesn't
			 * get removed.
			 */
			if (sock_flag(sk, SOCK_DESTROY) ||
			    (sk->sk_state == TCP_LISTEN &&
			     sock_flag(sk, SOCK_DEAD))) {
				bh_unlock_sock(sk);
				x25_destroy_socket_from_timer(sk);
				return;
			}
			break;

		case X25_STATE_3:
			/*
			 * Check for the state of the receive buffer.
			 */
			x25_check_rbuf(sk);
			break;
	}
restart_heartbeat:
	x25_start_heartbeat(sk);
	bh_unlock_sock(sk);
}

__attribute__((used)) static inline void x25_do_timer_expiry(struct sock * sk)
{
	struct x25_sock *x25 = x25_sk(sk);

	switch (x25->state) {

		case X25_STATE_3:	/* T2 */
			if (x25->condition & X25_COND_ACK_PENDING) {
				x25->condition &= ~X25_COND_ACK_PENDING;
				x25_enquiry_response(sk);
			}
			break;

		case X25_STATE_1:	/* T21 */
		case X25_STATE_4:	/* T22 */
			x25_write_internal(sk, X25_CLEAR_REQUEST);
			x25->state = X25_STATE_2;
			x25_start_t23timer(sk);
			break;

		case X25_STATE_2:	/* T23 */
			x25_disconnect(sk, ETIMEDOUT, 0, 0);
			break;
	}
}

__attribute__((used)) static void x25_timer_expiry(struct timer_list *t)
{
	struct x25_sock *x25 = from_timer(x25, t, timer);
	struct sock *sk = &x25->sk;

	bh_lock_sock(sk);
	if (sock_owned_by_user(sk)) { /* can currently only occur in state 3 */
		if (x25_sk(sk)->state == X25_STATE_3)
			x25_start_t2timer(sk);
	} else
		x25_do_timer_expiry(sk);
	bh_unlock_sock(sk);
}


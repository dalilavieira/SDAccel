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
struct timer_list {int dummy; } ;
struct TYPE_5__ {void (* function ) (struct timer_list*) ;} ;
struct sock {int sk_rcvbuf; int /*<<< orphan*/  (* sk_state_change ) (struct sock*) ;int /*<<< orphan*/  sk_shutdown; scalar_t__ sk_err; int /*<<< orphan*/  sk_state; int /*<<< orphan*/  sk_rmem_alloc; TYPE_1__ sk_timer; } ;
struct nr_sock {scalar_t__ t1; scalar_t__ t2; scalar_t__ t4; scalar_t__ idle; int state; int condition; scalar_t__ n2count; scalar_t__ n2; struct sock sock; int /*<<< orphan*/  vr; int /*<<< orphan*/  vl; TYPE_1__ t1timer; TYPE_1__ idletimer; TYPE_1__ t4timer; TYPE_1__ t2timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETIMEDOUT ; 
 int HZ ; 
 int NR_COND_ACK_PENDING ; 
 int NR_COND_OWN_RX_BUSY ; 
 int NR_COND_PEER_RX_BUSY ; 
 int /*<<< orphan*/  NR_CONNREQ ; 
 int /*<<< orphan*/  NR_DISCREQ ; 
 int /*<<< orphan*/  NR_INFOACK ; 
#define  NR_STATE_0 131 
#define  NR_STATE_1 130 
#define  NR_STATE_2 129 
#define  NR_STATE_3 128 
 int /*<<< orphan*/  SEND_SHUTDOWN ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  SOCK_DESTROY ; 
 int /*<<< orphan*/  TCP_CLOSE ; 
 int /*<<< orphan*/  TCP_LISTEN ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bh_lock_sock (struct sock*) ; 
 int /*<<< orphan*/  bh_unlock_sock (struct sock*) ; 
 void* from_timer (struct nr_sock*,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idletimer ; 
 scalar_t__ jiffies ; 
 struct nr_sock* nr ; 
 int /*<<< orphan*/  nr_clear_queues (struct sock*) ; 
 int /*<<< orphan*/  nr_destroy_socket (struct sock*) ; 
 int /*<<< orphan*/  nr_disconnect (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nr_enquiry_response (struct sock*) ; 
static  void nr_heartbeat_expiry (struct timer_list*) ; 
static  void nr_idletimer_expiry (struct timer_list*) ; 
 int /*<<< orphan*/  nr_requeue_frames (struct sock*) ; 
 struct nr_sock* nr_sk (struct sock*) ; 
static  void nr_t1timer_expiry (struct timer_list*) ; 
static  void nr_t2timer_expiry (struct timer_list*) ; 
static  void nr_t4timer_expiry (struct timer_list*) ; 
 int /*<<< orphan*/  nr_write_internal (struct sock*,int /*<<< orphan*/ ) ; 
 struct sock* sk ; 
 int /*<<< orphan*/  sk_reset_timer (struct sock*,TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  sk_stop_timer (struct sock*,TYPE_1__*) ; 
 int /*<<< orphan*/  sk_timer ; 
 scalar_t__ sock_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_hold (struct sock*) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 
 int /*<<< orphan*/  sock_set_flag (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 
 int /*<<< orphan*/  t1timer ; 
 int /*<<< orphan*/  t2timer ; 
 int /*<<< orphan*/  t4timer ; 
 int timer_pending (TYPE_1__*) ; 
 int /*<<< orphan*/  timer_setup (TYPE_1__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 

void nr_init_timers(struct sock *sk)
{
	struct nr_sock *nr = nr_sk(sk);

	timer_setup(&nr->t1timer, nr_t1timer_expiry, 0);
	timer_setup(&nr->t2timer, nr_t2timer_expiry, 0);
	timer_setup(&nr->t4timer, nr_t4timer_expiry, 0);
	timer_setup(&nr->idletimer, nr_idletimer_expiry, 0);

	/* initialized by sock_init_data */
	sk->sk_timer.function = nr_heartbeat_expiry;
}

void nr_start_t1timer(struct sock *sk)
{
	struct nr_sock *nr = nr_sk(sk);

	sk_reset_timer(sk, &nr->t1timer, jiffies + nr->t1);
}

void nr_start_t2timer(struct sock *sk)
{
	struct nr_sock *nr = nr_sk(sk);

	sk_reset_timer(sk, &nr->t2timer, jiffies + nr->t2);
}

void nr_start_t4timer(struct sock *sk)
{
	struct nr_sock *nr = nr_sk(sk);

	sk_reset_timer(sk, &nr->t4timer, jiffies + nr->t4);
}

void nr_start_idletimer(struct sock *sk)
{
	struct nr_sock *nr = nr_sk(sk);

	if (nr->idle > 0)
		sk_reset_timer(sk, &nr->idletimer, jiffies + nr->idle);
}

void nr_start_heartbeat(struct sock *sk)
{
	sk_reset_timer(sk, &sk->sk_timer, jiffies + 5 * HZ);
}

void nr_stop_t1timer(struct sock *sk)
{
	sk_stop_timer(sk, &nr_sk(sk)->t1timer);
}

void nr_stop_t2timer(struct sock *sk)
{
	sk_stop_timer(sk, &nr_sk(sk)->t2timer);
}

void nr_stop_t4timer(struct sock *sk)
{
	sk_stop_timer(sk, &nr_sk(sk)->t4timer);
}

void nr_stop_idletimer(struct sock *sk)
{
	sk_stop_timer(sk, &nr_sk(sk)->idletimer);
}

void nr_stop_heartbeat(struct sock *sk)
{
	sk_stop_timer(sk, &sk->sk_timer);
}

int nr_t1timer_running(struct sock *sk)
{
	return timer_pending(&nr_sk(sk)->t1timer);
}

__attribute__((used)) static void nr_heartbeat_expiry(struct timer_list *t)
{
	struct sock *sk = from_timer(sk, t, sk_timer);
	struct nr_sock *nr = nr_sk(sk);

	bh_lock_sock(sk);
	switch (nr->state) {
	case NR_STATE_0:
		/* Magic here: If we listen() and a new link dies before it
		   is accepted() it isn't 'dead' so doesn't get removed. */
		if (sock_flag(sk, SOCK_DESTROY) ||
		    (sk->sk_state == TCP_LISTEN && sock_flag(sk, SOCK_DEAD))) {
			sock_hold(sk);
			bh_unlock_sock(sk);
			nr_destroy_socket(sk);
			sock_put(sk);
			return;
		}
		break;

	case NR_STATE_3:
		/*
		 * Check for the state of the receive buffer.
		 */
		if (atomic_read(&sk->sk_rmem_alloc) < (sk->sk_rcvbuf / 2) &&
		    (nr->condition & NR_COND_OWN_RX_BUSY)) {
			nr->condition &= ~NR_COND_OWN_RX_BUSY;
			nr->condition &= ~NR_COND_ACK_PENDING;
			nr->vl         = nr->vr;
			nr_write_internal(sk, NR_INFOACK);
			break;
		}
		break;
	}

	nr_start_heartbeat(sk);
	bh_unlock_sock(sk);
}

__attribute__((used)) static void nr_t2timer_expiry(struct timer_list *t)
{
	struct nr_sock *nr = from_timer(nr, t, t2timer);
	struct sock *sk = &nr->sock;

	bh_lock_sock(sk);
	if (nr->condition & NR_COND_ACK_PENDING) {
		nr->condition &= ~NR_COND_ACK_PENDING;
		nr_enquiry_response(sk);
	}
	bh_unlock_sock(sk);
}

__attribute__((used)) static void nr_t4timer_expiry(struct timer_list *t)
{
	struct nr_sock *nr = from_timer(nr, t, t4timer);
	struct sock *sk = &nr->sock;

	bh_lock_sock(sk);
	nr_sk(sk)->condition &= ~NR_COND_PEER_RX_BUSY;
	bh_unlock_sock(sk);
}

__attribute__((used)) static void nr_idletimer_expiry(struct timer_list *t)
{
	struct nr_sock *nr = from_timer(nr, t, idletimer);
	struct sock *sk = &nr->sock;

	bh_lock_sock(sk);

	nr_clear_queues(sk);

	nr->n2count = 0;
	nr_write_internal(sk, NR_DISCREQ);
	nr->state = NR_STATE_2;

	nr_start_t1timer(sk);
	nr_stop_t2timer(sk);
	nr_stop_t4timer(sk);

	sk->sk_state     = TCP_CLOSE;
	sk->sk_err       = 0;
	sk->sk_shutdown |= SEND_SHUTDOWN;

	if (!sock_flag(sk, SOCK_DEAD)) {
		sk->sk_state_change(sk);
		sock_set_flag(sk, SOCK_DEAD);
	}
	bh_unlock_sock(sk);
}

__attribute__((used)) static void nr_t1timer_expiry(struct timer_list *t)
{
	struct nr_sock *nr = from_timer(nr, t, t1timer);
	struct sock *sk = &nr->sock;

	bh_lock_sock(sk);
	switch (nr->state) {
	case NR_STATE_1:
		if (nr->n2count == nr->n2) {
			nr_disconnect(sk, ETIMEDOUT);
			bh_unlock_sock(sk);
			return;
		} else {
			nr->n2count++;
			nr_write_internal(sk, NR_CONNREQ);
		}
		break;

	case NR_STATE_2:
		if (nr->n2count == nr->n2) {
			nr_disconnect(sk, ETIMEDOUT);
			bh_unlock_sock(sk);
			return;
		} else {
			nr->n2count++;
			nr_write_internal(sk, NR_DISCREQ);
		}
		break;

	case NR_STATE_3:
		if (nr->n2count == nr->n2) {
			nr_disconnect(sk, ETIMEDOUT);
			bh_unlock_sock(sk);
			return;
		} else {
			nr->n2count++;
			nr_requeue_frames(sk);
		}
		break;
	}

	nr_start_t1timer(sk);
	bh_unlock_sock(sk);
}


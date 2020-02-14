#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct sock {scalar_t__ sk_state; } ;
struct TYPE_7__ {scalar_t__ qlen; int /*<<< orphan*/ * rskq_rst_tail; int /*<<< orphan*/ * rskq_rst_head; int /*<<< orphan*/  lock; } ;
struct request_sock_queue {int /*<<< orphan*/ * rskq_accept_head; TYPE_1__ fastopenq; int /*<<< orphan*/  rskq_lock; } ;
struct TYPE_9__ {scalar_t__ expires; } ;
struct request_sock {struct request_sock* dl_next; TYPE_3__ rsk_timer; scalar_t__ sk; struct sock* rsk_listener; } ;
struct fastopen_queue {int /*<<< orphan*/  lock; int /*<<< orphan*/  qlen; struct request_sock* rskq_rst_tail; struct request_sock* rskq_rst_head; } ;
struct TYPE_8__ {struct fastopen_queue fastopenq; } ;
struct TYPE_12__ {TYPE_2__ icsk_accept_queue; } ;
struct TYPE_11__ {int tfo_listener; } ;
struct TYPE_10__ {int /*<<< orphan*/ * fastopen_rsk; } ;

/* Variables and functions */
 int HZ ; 
 scalar_t__ TCP_LISTEN ; 
 TYPE_6__* inet_csk (struct sock*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  reqsk_put (struct request_sock*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 TYPE_5__* tcp_rsk (struct request_sock*) ; 
 TYPE_4__* tcp_sk (struct sock*) ; 

void reqsk_queue_alloc(struct request_sock_queue *queue)
{
	spin_lock_init(&queue->rskq_lock);

	spin_lock_init(&queue->fastopenq.lock);
	queue->fastopenq.rskq_rst_head = NULL;
	queue->fastopenq.rskq_rst_tail = NULL;
	queue->fastopenq.qlen = 0;

	queue->rskq_accept_head = NULL;
}

void reqsk_fastopen_remove(struct sock *sk, struct request_sock *req,
			   bool reset)
{
	struct sock *lsk = req->rsk_listener;
	struct fastopen_queue *fastopenq;

	fastopenq = &inet_csk(lsk)->icsk_accept_queue.fastopenq;

	tcp_sk(sk)->fastopen_rsk = NULL;
	spin_lock_bh(&fastopenq->lock);
	fastopenq->qlen--;
	tcp_rsk(req)->tfo_listener = false;
	if (req->sk)	/* the child socket hasn't been accepted yet */
		goto out;

	if (!reset || lsk->sk_state != TCP_LISTEN) {
		/* If the listener has been closed don't bother with the
		 * special RST handling below.
		 */
		spin_unlock_bh(&fastopenq->lock);
		reqsk_put(req);
		return;
	}
	/* Wait for 60secs before removing a req that has triggered RST.
	 * This is a simple defense against TFO spoofing attack - by
	 * counting the req against fastopen.max_qlen, and disabling
	 * TFO when the qlen exceeds max_qlen.
	 *
	 * For more details see CoNext'11 "TCP Fast Open" paper.
	 */
	req->rsk_timer.expires = jiffies + 60*HZ;
	if (fastopenq->rskq_rst_head == NULL)
		fastopenq->rskq_rst_head = req;
	else
		fastopenq->rskq_rst_tail->dl_next = req;

	req->dl_next = NULL;
	fastopenq->rskq_rst_tail = req;
	fastopenq->qlen++;
out:
	spin_unlock_bh(&fastopenq->lock);
}


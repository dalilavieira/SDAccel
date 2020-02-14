#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct sock {scalar_t__ sk_state; scalar_t__ sk_type; } ;
struct sk_buff {int /*<<< orphan*/  dev; } ;
struct llc_sock {scalar_t__ state; int failed_data_req; TYPE_2__* sap; int /*<<< orphan*/  dev; scalar_t__ p_flag; } ;
struct llc_conn_state_ev {void* prim_type; int /*<<< orphan*/  prim; void* type; } ;
struct llc_addr {int /*<<< orphan*/  mac; int /*<<< orphan*/  lsap; } ;
struct TYPE_3__ {int /*<<< orphan*/  lsap; } ;
struct TYPE_4__ {TYPE_1__ laddr; } ;

/* Variables and functions */
 int EBUSY ; 
 int ECONNABORTED ; 
 int EISCONN ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 void* LLC_CONN_EV_TYPE_PRIM ; 
 scalar_t__ LLC_CONN_OUT_OF_SVC ; 
 int /*<<< orphan*/  LLC_CONN_PRIM ; 
 scalar_t__ LLC_CONN_STATE_ADM ; 
 int /*<<< orphan*/  LLC_DATA_PRIM ; 
 int /*<<< orphan*/  LLC_DISC_PRIM ; 
 void* LLC_PRIM_TYPE_REQ ; 
 scalar_t__ SOCK_STREAM ; 
 scalar_t__ TCP_CLOSING ; 
 scalar_t__ TCP_ESTABLISHED ; 
 struct sk_buff* alloc_skb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct llc_conn_state_ev* llc_conn_ev (struct sk_buff*) ; 
 int llc_conn_state_process (struct sock*,struct sk_buff*) ; 
 scalar_t__ llc_data_accept_state (scalar_t__) ; 
 struct sock* llc_lookup_established (TYPE_2__*,struct llc_addr*,struct llc_addr*) ; 
 struct llc_sock* llc_sk (struct sock*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  skb_set_owner_w (struct sk_buff*,struct sock*) ; 
 int /*<<< orphan*/  sock_hold (struct sock*) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 
 scalar_t__ unlikely (int) ; 

int llc_build_and_send_pkt(struct sock *sk, struct sk_buff *skb)
{
	struct llc_conn_state_ev *ev;
	int rc = -ECONNABORTED;
	struct llc_sock *llc = llc_sk(sk);

	if (unlikely(llc->state == LLC_CONN_STATE_ADM))
		goto out;
	rc = -EBUSY;
	if (unlikely(llc_data_accept_state(llc->state) || /* data_conn_refuse */
		     llc->p_flag)) {
		llc->failed_data_req = 1;
		goto out;
	}
	ev = llc_conn_ev(skb);
	ev->type      = LLC_CONN_EV_TYPE_PRIM;
	ev->prim      = LLC_DATA_PRIM;
	ev->prim_type = LLC_PRIM_TYPE_REQ;
	skb->dev      = llc->dev;
	rc = llc_conn_state_process(sk, skb);
out:
	return rc;
}

int llc_establish_connection(struct sock *sk, u8 *lmac, u8 *dmac, u8 dsap)
{
	int rc = -EISCONN;
	struct llc_addr laddr, daddr;
	struct sk_buff *skb;
	struct llc_sock *llc = llc_sk(sk);
	struct sock *existing;

	laddr.lsap = llc->sap->laddr.lsap;
	daddr.lsap = dsap;
	memcpy(daddr.mac, dmac, sizeof(daddr.mac));
	memcpy(laddr.mac, lmac, sizeof(laddr.mac));
	existing = llc_lookup_established(llc->sap, &daddr, &laddr);
	if (existing) {
		if (existing->sk_state == TCP_ESTABLISHED) {
			sk = existing;
			goto out_put;
		} else
			sock_put(existing);
	}
	sock_hold(sk);
	rc = -ENOMEM;
	skb = alloc_skb(0, GFP_ATOMIC);
	if (skb) {
		struct llc_conn_state_ev *ev = llc_conn_ev(skb);

		ev->type      = LLC_CONN_EV_TYPE_PRIM;
		ev->prim      = LLC_CONN_PRIM;
		ev->prim_type = LLC_PRIM_TYPE_REQ;
		skb_set_owner_w(skb, sk);
		rc = llc_conn_state_process(sk, skb);
	}
out_put:
	sock_put(sk);
	return rc;
}

int llc_send_disc(struct sock *sk)
{
	u16 rc = 1;
	struct llc_conn_state_ev *ev;
	struct sk_buff *skb;

	sock_hold(sk);
	if (sk->sk_type != SOCK_STREAM || sk->sk_state != TCP_ESTABLISHED ||
	    llc_sk(sk)->state == LLC_CONN_STATE_ADM ||
	    llc_sk(sk)->state == LLC_CONN_OUT_OF_SVC)
		goto out;
	/*
	 * Postpone unassigning the connection from its SAP and returning the
	 * connection until all ACTIONs have been completely executed
	 */
	skb = alloc_skb(0, GFP_ATOMIC);
	if (!skb)
		goto out;
	skb_set_owner_w(skb, sk);
	sk->sk_state  = TCP_CLOSING;
	ev	      = llc_conn_ev(skb);
	ev->type      = LLC_CONN_EV_TYPE_PRIM;
	ev->prim      = LLC_DISC_PRIM;
	ev->prim_type = LLC_PRIM_TYPE_REQ;
	rc = llc_conn_state_process(sk, skb);
out:
	sock_put(sk);
	return rc;
}


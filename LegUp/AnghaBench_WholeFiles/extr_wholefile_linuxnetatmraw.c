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
typedef  int u32 ;
struct sock {int /*<<< orphan*/  (* sk_write_space ) (struct sock*) ;int /*<<< orphan*/  sk_wmem_alloc; int /*<<< orphan*/  (* sk_data_ready ) (struct sock*) ;int /*<<< orphan*/  sk_receive_queue; } ;
struct sk_buff {scalar_t__ data; } ;
struct atm_vcc {int vci; int vpi; void (* push ) (struct atm_vcc*,struct sk_buff*) ;void (* pop ) (struct atm_vcc*,struct sk_buff*) ;int (* send ) (struct atm_vcc*,struct sk_buff*) ;TYPE_2__* dev; int /*<<< orphan*/ * push_oam; } ;
struct TYPE_6__ {int /*<<< orphan*/  acct_truesize; } ;
struct TYPE_5__ {TYPE_1__* ops; } ;
struct TYPE_4__ {int (* send ) (struct atm_vcc*,struct sk_buff*) ;} ;

/* Variables and functions */
 int ATM_HDR_VCI_MASK ; 
 int ATM_HDR_VCI_SHIFT ; 
 int ATM_HDR_VPI_MASK ; 
 int ATM_HDR_VPI_SHIFT ; 
 TYPE_3__* ATM_SKB (struct sk_buff*) ; 
 int /*<<< orphan*/  CAP_NET_ADMIN ; 
 int EADDRNOTAVAIL ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  pr_debug (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  refcount_sub_and_test (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sock* sk_atm (struct atm_vcc*) ; 
 int /*<<< orphan*/  sk_wmem_alloc_get (struct sock*) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 
 int /*<<< orphan*/  stub2 (struct sock*) ; 
 int stub3 (struct atm_vcc*,struct sk_buff*) ; 

__attribute__((used)) static inline int atm_proc_init(void)
{
	return 0;
}

__attribute__((used)) static inline void atm_proc_exit(void)
{
	/* nothing */
}

__attribute__((used)) static void atm_push_raw(struct atm_vcc *vcc, struct sk_buff *skb)
{
	if (skb) {
		struct sock *sk = sk_atm(vcc);

		skb_queue_tail(&sk->sk_receive_queue, skb);
		sk->sk_data_ready(sk);
	}
}

__attribute__((used)) static void atm_pop_raw(struct atm_vcc *vcc, struct sk_buff *skb)
{
	struct sock *sk = sk_atm(vcc);

	pr_debug("(%d) %d -= %d\n",
		 vcc->vci, sk_wmem_alloc_get(sk), ATM_SKB(skb)->acct_truesize);
	WARN_ON(refcount_sub_and_test(ATM_SKB(skb)->acct_truesize, &sk->sk_wmem_alloc));
	dev_kfree_skb_any(skb);
	sk->sk_write_space(sk);
}

__attribute__((used)) static int atm_send_aal0(struct atm_vcc *vcc, struct sk_buff *skb)
{
	/*
	 * Note that if vpi/vci are _ANY or _UNSPEC the below will
	 * still work
	 */
	if (!capable(CAP_NET_ADMIN) &&
	    (((u32 *)skb->data)[0] & (ATM_HDR_VPI_MASK | ATM_HDR_VCI_MASK)) !=
	    ((vcc->vpi << ATM_HDR_VPI_SHIFT) |
	     (vcc->vci << ATM_HDR_VCI_SHIFT))) {
		kfree_skb(skb);
		return -EADDRNOTAVAIL;
	}
	return vcc->dev->ops->send(vcc, skb);
}

int atm_init_aal0(struct atm_vcc *vcc)
{
	vcc->push = atm_push_raw;
	vcc->pop = atm_pop_raw;
	vcc->push_oam = NULL;
	vcc->send = atm_send_aal0;
	return 0;
}

int atm_init_aal34(struct atm_vcc *vcc)
{
	vcc->push = atm_push_raw;
	vcc->pop = atm_pop_raw;
	vcc->push_oam = NULL;
	vcc->send = vcc->dev->ops->send;
	return 0;
}

int atm_init_aal5(struct atm_vcc *vcc)
{
	vcc->push = atm_push_raw;
	vcc->pop = atm_pop_raw;
	vcc->push_oam = NULL;
	vcc->send = vcc->dev->ops->send;
	return 0;
}


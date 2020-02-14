#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct sock {int dummy; } ;
struct sk_buff {scalar_t__ len; int* data; } ;
struct rose_neigh {int dummy; } ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  rose_address ;
struct TYPE_6__ {scalar_t__ expires; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 unsigned short ROSE_CALL_REQUEST ; 
 size_t ROSE_CALL_REQ_ADDR_LEN_OFF ; 
 unsigned short ROSE_CALL_REQ_ADDR_LEN_VAL ; 
 int ROSE_CALL_REQ_DEST_ADDR_OFF ; 
 scalar_t__ ROSE_CALL_REQ_FACILITIES_OFF ; 
 int ROSE_DEFAULT_MAXVC ; 
 scalar_t__ ROSE_MIN_LEN ; 
 int /*<<< orphan*/  add_timer (TYPE_1__*) ; 
 int /*<<< orphan*/  del_timer (TYPE_1__*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  loopback_queue ; 
 TYPE_1__ loopback_timer ; 
 struct net_device* rose_dev_get (int /*<<< orphan*/ *) ; 
 struct sock* rose_find_socket (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rose_loopback_neigh ; 
static  void rose_loopback_timer (struct timer_list*) ; 
 scalar_t__ rose_process_rx_frame (struct sock*,struct sk_buff*) ; 
 scalar_t__ rose_rx_call_request (struct sk_buff*,struct net_device*,int /*<<< orphan*/ ,unsigned int) ; 
static  void rose_set_loopback_timer () ; 
 struct sk_buff* skb_clone (struct sk_buff*,int /*<<< orphan*/ ) ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_queue_head_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_transport_header (struct sk_buff*) ; 
 int timer_pending (TYPE_1__*) ; 
 int /*<<< orphan*/  timer_setup (TYPE_1__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 

void rose_loopback_init(void)
{
	skb_queue_head_init(&loopback_queue);

	timer_setup(&loopback_timer, rose_loopback_timer, 0);
}

__attribute__((used)) static int rose_loopback_running(void)
{
	return timer_pending(&loopback_timer);
}

int rose_loopback_queue(struct sk_buff *skb, struct rose_neigh *neigh)
{
	struct sk_buff *skbn;

	skbn = skb_clone(skb, GFP_ATOMIC);

	kfree_skb(skb);

	if (skbn != NULL) {
		skb_queue_tail(&loopback_queue, skbn);

		if (!rose_loopback_running())
			rose_set_loopback_timer();
	}

	return 1;
}

__attribute__((used)) static void rose_set_loopback_timer(void)
{
	del_timer(&loopback_timer);

	loopback_timer.expires  = jiffies + 10;
	add_timer(&loopback_timer);
}

__attribute__((used)) static void rose_loopback_timer(struct timer_list *unused)
{
	struct sk_buff *skb;
	struct net_device *dev;
	rose_address *dest;
	struct sock *sk;
	unsigned short frametype;
	unsigned int lci_i, lci_o;

	while ((skb = skb_dequeue(&loopback_queue)) != NULL) {
		if (skb->len < ROSE_MIN_LEN) {
			kfree_skb(skb);
			continue;
		}
		lci_i     = ((skb->data[0] << 8) & 0xF00) + ((skb->data[1] << 0) & 0x0FF);
		frametype = skb->data[2];
		if (frametype == ROSE_CALL_REQUEST &&
		    (skb->len <= ROSE_CALL_REQ_FACILITIES_OFF ||
		     skb->data[ROSE_CALL_REQ_ADDR_LEN_OFF] !=
		     ROSE_CALL_REQ_ADDR_LEN_VAL)) {
			kfree_skb(skb);
			continue;
		}
		dest      = (rose_address *)(skb->data + ROSE_CALL_REQ_DEST_ADDR_OFF);
		lci_o     = ROSE_DEFAULT_MAXVC + 1 - lci_i;

		skb_reset_transport_header(skb);

		sk = rose_find_socket(lci_o, rose_loopback_neigh);
		if (sk) {
			if (rose_process_rx_frame(sk, skb) == 0)
				kfree_skb(skb);
			continue;
		}

		if (frametype == ROSE_CALL_REQUEST) {
			if ((dev = rose_dev_get(dest)) != NULL) {
				if (rose_rx_call_request(skb, dev, rose_loopback_neigh, lci_o) == 0)
					kfree_skb(skb);
			} else {
				kfree_skb(skb);
			}
		} else {
			kfree_skb(skb);
		}
	}
}


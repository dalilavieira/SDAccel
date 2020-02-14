#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct net_device {int /*<<< orphan*/  name; } ;
struct concap_proto {struct net_device* net_dev; } ;
struct TYPE_14__ {int /*<<< orphan*/  xmit_lock; scalar_t__ huptimer; TYPE_2__* netdev; struct TYPE_14__* last; struct TYPE_14__* next; scalar_t__ master; int /*<<< orphan*/  frame_cnt; } ;
typedef  TYPE_1__ isdn_net_local ;
struct TYPE_15__ {int /*<<< orphan*/  queue_lock; TYPE_1__* local; TYPE_1__* queue; } ;
typedef  TYPE_2__ isdn_net_dev ;

/* Variables and functions */
 TYPE_1__* ISDN_MASTER_PRIV (TYPE_1__*) ; 
#define  ISDN_NET_ENCAP_X25IFACE 128 
 scalar_t__ ISDN_NET_MAX_QUEUE_LENGTH ; 
 int /*<<< orphan*/  IX25DEBUG (char*,...) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int isdn_net_dial_req (TYPE_1__*) ; 
 int /*<<< orphan*/  isdn_net_hangup (struct net_device*) ; 
 int /*<<< orphan*/  isdn_net_writebuf_skb (TYPE_1__*,struct sk_buff*) ; 
 struct concap_proto* isdn_x25iface_proto_new () ; 
 int /*<<< orphan*/  local_bh_disable () ; 
 TYPE_1__* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static __inline__ int isdn_net_lp_busy(isdn_net_local *lp)
{
	if (atomic_read(&lp->frame_cnt) < ISDN_NET_MAX_QUEUE_LENGTH)
		return 0;
	else
		return 1;
}

__attribute__((used)) static __inline__ isdn_net_local *isdn_net_get_locked_lp(isdn_net_dev *nd)
{
	unsigned long flags;
	isdn_net_local *lp;

	spin_lock_irqsave(&nd->queue_lock, flags);
	lp = nd->queue;         /* get lp on top of queue */
	while (isdn_net_lp_busy(nd->queue)) {
		nd->queue = nd->queue->next;
		if (nd->queue == lp) { /* not found -- should never happen */
			lp = NULL;
			goto errout;
		}
	}
	lp = nd->queue;
	nd->queue = nd->queue->next;
	spin_unlock_irqrestore(&nd->queue_lock, flags);
	spin_lock(&lp->xmit_lock);
	local_bh_disable();
	return lp;
errout:
	spin_unlock_irqrestore(&nd->queue_lock, flags);
	return lp;
}

__attribute__((used)) static __inline__ void isdn_net_add_to_bundle(isdn_net_dev *nd, isdn_net_local *nlp)
{
	isdn_net_local *lp;
	unsigned long flags;

	spin_lock_irqsave(&nd->queue_lock, flags);

	lp = nd->queue;
//	printk(KERN_DEBUG "%s: lp:%s(%p) nlp:%s(%p) last(%p)\n",
//		__func__, lp->name, lp, nlp->name, nlp, lp->last);
	nlp->last = lp->last;
	lp->last->next = nlp;
	lp->last = nlp;
	nlp->next = lp;
	nd->queue = nlp;

	spin_unlock_irqrestore(&nd->queue_lock, flags);
}

__attribute__((used)) static __inline__ void isdn_net_rm_from_bundle(isdn_net_local *lp)
{
	isdn_net_local *master_lp = lp;
	unsigned long flags;

	if (lp->master)
		master_lp = ISDN_MASTER_PRIV(lp);

//	printk(KERN_DEBUG "%s: lp:%s(%p) mlp:%s(%p) last(%p) next(%p) mndq(%p)\n",
//		__func__, lp->name, lp, master_lp->name, master_lp, lp->last, lp->next, master_lp->netdev->queue);
	spin_lock_irqsave(&master_lp->netdev->queue_lock, flags);
	lp->last->next = lp->next;
	lp->next->last = lp->last;
	if (master_lp->netdev->queue == lp) {
		master_lp->netdev->queue = lp->next;
		if (lp->next == lp) { /* last in queue */
			master_lp->netdev->queue = master_lp->netdev->local;
		}
	}
	lp->next = lp->last = lp;	/* (re)set own pointers */
//	printk(KERN_DEBUG "%s: mndq(%p)\n",
//		__func__, master_lp->netdev->queue);
	spin_unlock_irqrestore(&master_lp->netdev->queue_lock, flags);
}

__attribute__((used)) static int isdn_concap_dl_data_req(struct concap_proto *concap, struct sk_buff *skb)
{
	struct net_device *ndev = concap->net_dev;
	isdn_net_dev *nd = ((isdn_net_local *) netdev_priv(ndev))->netdev;
	isdn_net_local *lp = isdn_net_get_locked_lp(nd);

	IX25DEBUG("isdn_concap_dl_data_req: %s \n", concap->net_dev->name);
	if (!lp) {
		IX25DEBUG("isdn_concap_dl_data_req: %s : isdn_net_send_skb returned %d\n", concap->net_dev->name, 1);
		return 1;
	}
	lp->huptimer = 0;
	isdn_net_writebuf_skb(lp, skb);
	spin_unlock_bh(&lp->xmit_lock);
	IX25DEBUG("isdn_concap_dl_data_req: %s : isdn_net_send_skb returned %d\n", concap->net_dev->name, 0);
	return 0;
}

__attribute__((used)) static int isdn_concap_dl_connect_req(struct concap_proto *concap)
{
	struct net_device *ndev = concap->net_dev;
	isdn_net_local *lp = netdev_priv(ndev);
	int ret;
	IX25DEBUG("isdn_concap_dl_connect_req: %s \n", ndev->name);

	/* dial ... */
	ret = isdn_net_dial_req(lp);
	if (ret) IX25DEBUG("dialing failed\n");
	return ret;
}

__attribute__((used)) static int isdn_concap_dl_disconn_req(struct concap_proto *concap)
{
	IX25DEBUG("isdn_concap_dl_disconn_req: %s \n", concap->net_dev->name);

	isdn_net_hangup(concap->net_dev);
	return 0;
}

struct concap_proto *isdn_concap_new(int encap)
{
	switch (encap) {
	case ISDN_NET_ENCAP_X25IFACE:
		return isdn_x25iface_proto_new();
	}
	return NULL;
}


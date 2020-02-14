#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct sk_buff {int dummy; } ;
struct cardstate {unsigned short hw_hdr_len; int /*<<< orphan*/  dev; int /*<<< orphan*/  lock; int /*<<< orphan*/  event_tasklet; scalar_t__ running; } ;
struct bc_state {struct sk_buff* rx_skb; scalar_t__ rx_bufsize; scalar_t__ ignore; struct cardstate* cs; int /*<<< orphan*/  at_state; } ;
struct at_state_t {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EV_BC_CLOSED ; 
 int /*<<< orphan*/  EV_BC_OPEN ; 
 int ICALL_IGNORE ; 
 struct sk_buff* dev_alloc_skb (scalar_t__) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gigaset_add_event (struct cardstate*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,unsigned short) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void gigaset_schedule_event(struct cardstate *cs)
{
	unsigned long flags;
	spin_lock_irqsave(&cs->lock, flags);
	if (cs->running)
		tasklet_schedule(&cs->event_tasklet);
	spin_unlock_irqrestore(&cs->lock, flags);
}

__attribute__((used)) static inline void gigaset_bchannel_down(struct bc_state *bcs)
{
	gigaset_add_event(bcs->cs, &bcs->at_state, EV_BC_CLOSED, NULL, 0, NULL);
	gigaset_schedule_event(bcs->cs);
}

__attribute__((used)) static inline void gigaset_bchannel_up(struct bc_state *bcs)
{
	gigaset_add_event(bcs->cs, &bcs->at_state, EV_BC_OPEN, NULL, 0, NULL);
	gigaset_schedule_event(bcs->cs);
}

__attribute__((used)) static inline struct sk_buff *gigaset_new_rx_skb(struct bc_state *bcs)
{
	struct cardstate *cs = bcs->cs;
	unsigned short hw_hdr_len = cs->hw_hdr_len;

	if (bcs->ignore) {
		bcs->rx_skb = NULL;
	} else {
		bcs->rx_skb = dev_alloc_skb(bcs->rx_bufsize + hw_hdr_len);
		if (bcs->rx_skb == NULL)
			dev_warn(cs->dev, "could not allocate skb\n");
		else
			skb_reserve(bcs->rx_skb, hw_hdr_len);
	}
	return bcs->rx_skb;
}

void gigaset_skb_sent(struct bc_state *bcs, struct sk_buff *skb)
{
}

void gigaset_skb_rcvd(struct bc_state *bcs, struct sk_buff *skb)
{
}

void gigaset_isdn_rcv_err(struct bc_state *bcs)
{
}

int gigaset_isdn_icall(struct at_state_t *at_state)
{
	return ICALL_IGNORE;
}

void gigaset_isdn_connD(struct bc_state *bcs)
{
}

void gigaset_isdn_hupD(struct bc_state *bcs)
{
}

void gigaset_isdn_connB(struct bc_state *bcs)
{
}

void gigaset_isdn_hupB(struct bc_state *bcs)
{
}

void gigaset_isdn_start(struct cardstate *cs)
{
}

void gigaset_isdn_stop(struct cardstate *cs)
{
}

int gigaset_isdn_regdev(struct cardstate *cs, const char *isdnid)
{
	return 0;
}

void gigaset_isdn_unregdev(struct cardstate *cs)
{
}

void gigaset_isdn_regdrv(void)
{
	pr_info("no ISDN subsystem interface\n");
}

void gigaset_isdn_unregdrv(void)
{
}


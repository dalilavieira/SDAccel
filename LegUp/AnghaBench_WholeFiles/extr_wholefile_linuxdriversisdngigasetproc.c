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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct cardstate {unsigned short hw_hdr_len; int cidmode; int waiting; int /*<<< orphan*/  tty_dev; int /*<<< orphan*/  mutex; int /*<<< orphan*/  waitqueue; int /*<<< orphan*/  at_state; int /*<<< orphan*/  dev; int /*<<< orphan*/  lock; int /*<<< orphan*/  event_tasklet; scalar_t__ running; } ;
struct bc_state {struct sk_buff* rx_skb; scalar_t__ rx_bufsize; scalar_t__ ignore; struct cardstate* cs; int /*<<< orphan*/  at_state; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_INIT ; 
 size_t EINVAL ; 
 size_t ENOMEM ; 
 size_t ERESTARTSYS ; 
 int /*<<< orphan*/  EV_BC_CLOSED ; 
 int /*<<< orphan*/  EV_BC_OPEN ; 
 int /*<<< orphan*/  EV_PROC_CIDMODE ; 
 struct sk_buff* dev_alloc_skb (scalar_t__) ; 
 int /*<<< orphan*/  dev_attr_cidmode ; 
 struct cardstate* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ device_create_file (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gig_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gigaset_add_event (struct cardstate*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,long,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  isspace (int /*<<< orphan*/ ) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 long simple_strtol (char const*,char**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,unsigned short) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 size_t sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wait_event (int /*<<< orphan*/ ,int) ; 

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

__attribute__((used)) static ssize_t show_cidmode(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	struct cardstate *cs = dev_get_drvdata(dev);

	return sprintf(buf, "%u\n", cs->cidmode);
}

__attribute__((used)) static ssize_t set_cidmode(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct cardstate *cs = dev_get_drvdata(dev);
	long int value;
	char *end;

	value = simple_strtol(buf, &end, 0);
	while (*end)
		if (!isspace(*end++))
			return -EINVAL;
	if (value < 0 || value > 1)
		return -EINVAL;

	if (mutex_lock_interruptible(&cs->mutex))
		return -ERESTARTSYS;

	cs->waiting = 1;
	if (!gigaset_add_event(cs, &cs->at_state, EV_PROC_CIDMODE,
			       NULL, value, NULL)) {
		cs->waiting = 0;
		mutex_unlock(&cs->mutex);
		return -ENOMEM;
	}
	gigaset_schedule_event(cs);

	wait_event(cs->waitqueue, !cs->waiting);

	mutex_unlock(&cs->mutex);

	return count;
}

void gigaset_free_dev_sysfs(struct cardstate *cs)
{
	if (!cs->tty_dev)
		return;

	gig_dbg(DEBUG_INIT, "removing sysfs entries");
	device_remove_file(cs->tty_dev, &dev_attr_cidmode);
}

void gigaset_init_dev_sysfs(struct cardstate *cs)
{
	if (!cs->tty_dev)
		return;

	gig_dbg(DEBUG_INIT, "setting up sysfs");
	if (device_create_file(cs->tty_dev, &dev_attr_cidmode))
		pr_err("could not create sysfs attribute\n");
}


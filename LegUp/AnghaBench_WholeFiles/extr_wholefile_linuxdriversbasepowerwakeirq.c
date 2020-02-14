#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct wake_irq {int irq; int status; struct device* dev; struct wake_irq* name; } ;
struct TYPE_2__ {int early_init; struct wake_irq* wakeirq; int /*<<< orphan*/  lock; int /*<<< orphan*/ * qos; } ;
struct device {TYPE_1__ power; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EEXIST ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_DISABLE_UNLAZY ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NOAUTOEN ; 
 int WAKE_IRQ_DEDICATED_ALLOCATED ; 
 int WAKE_IRQ_DEDICATED_MANAGED ; 
 int WAKE_IRQ_DEDICATED_MASK ; 
 scalar_t__ dev_WARN_ONCE (struct device*,struct wake_irq*,char*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 int device_is_registered (struct device*) ; 
 scalar_t__ device_may_wakeup (struct device*) ; 
 int /*<<< orphan*/  device_wakeup_attach_irq (struct device*,struct wake_irq*) ; 
 int /*<<< orphan*/  device_wakeup_detach_irq (struct device*) ; 
 int /*<<< orphan*/  disable_irq_nosync (int) ; 
 int /*<<< orphan*/  disable_irq_wake (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 int /*<<< orphan*/  enable_irq_wake (int) ; 
 int /*<<< orphan*/  free_irq (int,struct wake_irq*) ; 
 int /*<<< orphan*/  irq_get_irq_data (int) ; 
 int /*<<< orphan*/  irq_set_status_flags (int,int /*<<< orphan*/ ) ; 
 scalar_t__ irqd_is_wakeup_set (int /*<<< orphan*/ ) ; 
 struct wake_irq* kasprintf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct wake_irq*) ; 
 struct wake_irq* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 int pm_runtime_resume (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_status_suspended (struct device*) ; 
 int /*<<< orphan*/  pm_wakeup_event (struct device*,int /*<<< orphan*/ ) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,struct wake_irq*,struct wake_irq*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline void device_pm_init_common(struct device *dev)
{
	if (!dev->power.early_init) {
		spin_lock_init(&dev->power.lock);
		dev->power.qos = NULL;
		dev->power.early_init = true;
	}
}

__attribute__((used)) static inline void pm_runtime_early_init(struct device *dev)
{
	device_pm_init_common(dev);
}

__attribute__((used)) static inline void pm_runtime_init(struct device *dev) {}

__attribute__((used)) static inline void pm_runtime_reinit(struct device *dev) {}

__attribute__((used)) static inline void pm_runtime_remove(struct device *dev) {}

__attribute__((used)) static inline int dpm_sysfs_add(struct device *dev) { return 0; }

__attribute__((used)) static inline void dpm_sysfs_remove(struct device *dev) {}

__attribute__((used)) static inline void device_pm_sleep_init(struct device *dev) {}

__attribute__((used)) static inline void device_pm_add(struct device *dev) {}

__attribute__((used)) static inline void device_pm_remove(struct device *dev)
{
	pm_runtime_remove(dev);
}

__attribute__((used)) static inline void device_pm_move_before(struct device *deva,
					 struct device *devb) {}

__attribute__((used)) static inline void device_pm_move_after(struct device *deva,
					struct device *devb) {}

__attribute__((used)) static inline void device_pm_move_last(struct device *dev) {}

__attribute__((used)) static inline void device_pm_check_callbacks(struct device *dev) {}

__attribute__((used)) static inline bool device_pm_initialized(struct device *dev)
{
	return device_is_registered(dev);
}

__attribute__((used)) static inline void device_pm_init(struct device *dev)
{
	device_pm_init_common(dev);
	device_pm_sleep_init(dev);
	pm_runtime_init(dev);
}

__attribute__((used)) static int dev_pm_attach_wake_irq(struct device *dev, int irq,
				  struct wake_irq *wirq)
{
	unsigned long flags;

	if (!dev || !wirq)
		return -EINVAL;

	spin_lock_irqsave(&dev->power.lock, flags);
	if (dev_WARN_ONCE(dev, dev->power.wakeirq,
			  "wake irq already initialized\n")) {
		spin_unlock_irqrestore(&dev->power.lock, flags);
		return -EEXIST;
	}

	dev->power.wakeirq = wirq;
	device_wakeup_attach_irq(dev, wirq);

	spin_unlock_irqrestore(&dev->power.lock, flags);
	return 0;
}

int dev_pm_set_wake_irq(struct device *dev, int irq)
{
	struct wake_irq *wirq;
	int err;

	if (irq < 0)
		return -EINVAL;

	wirq = kzalloc(sizeof(*wirq), GFP_KERNEL);
	if (!wirq)
		return -ENOMEM;

	wirq->dev = dev;
	wirq->irq = irq;

	err = dev_pm_attach_wake_irq(dev, irq, wirq);
	if (err)
		kfree(wirq);

	return err;
}

void dev_pm_clear_wake_irq(struct device *dev)
{
	struct wake_irq *wirq = dev->power.wakeirq;
	unsigned long flags;

	if (!wirq)
		return;

	spin_lock_irqsave(&dev->power.lock, flags);
	device_wakeup_detach_irq(dev);
	dev->power.wakeirq = NULL;
	spin_unlock_irqrestore(&dev->power.lock, flags);

	if (wirq->status & WAKE_IRQ_DEDICATED_ALLOCATED) {
		free_irq(wirq->irq, wirq);
		wirq->status &= ~WAKE_IRQ_DEDICATED_MASK;
	}
	kfree(wirq->name);
	kfree(wirq);
}

__attribute__((used)) static irqreturn_t handle_threaded_wake_irq(int irq, void *_wirq)
{
	struct wake_irq *wirq = _wirq;
	int res;

	/* Maybe abort suspend? */
	if (irqd_is_wakeup_set(irq_get_irq_data(irq))) {
		pm_wakeup_event(wirq->dev, 0);

		return IRQ_HANDLED;
	}

	/* We don't want RPM_ASYNC or RPM_NOWAIT here */
	res = pm_runtime_resume(wirq->dev);
	if (res < 0)
		dev_warn(wirq->dev,
			 "wake IRQ with no resume: %i\n", res);

	return IRQ_HANDLED;
}

int dev_pm_set_dedicated_wake_irq(struct device *dev, int irq)
{
	struct wake_irq *wirq;
	int err;

	if (irq < 0)
		return -EINVAL;

	wirq = kzalloc(sizeof(*wirq), GFP_KERNEL);
	if (!wirq)
		return -ENOMEM;

	wirq->name = kasprintf(GFP_KERNEL, "%s:wakeup", dev_name(dev));
	if (!wirq->name) {
		err = -ENOMEM;
		goto err_free;
	}

	wirq->dev = dev;
	wirq->irq = irq;
	irq_set_status_flags(irq, IRQ_NOAUTOEN);

	/* Prevent deferred spurious wakeirqs with disable_irq_nosync() */
	irq_set_status_flags(irq, IRQ_DISABLE_UNLAZY);

	/*
	 * Consumer device may need to power up and restore state
	 * so we use a threaded irq.
	 */
	err = request_threaded_irq(irq, NULL, handle_threaded_wake_irq,
				   IRQF_ONESHOT, wirq->name, wirq);
	if (err)
		goto err_free_name;

	err = dev_pm_attach_wake_irq(dev, irq, wirq);
	if (err)
		goto err_free_irq;

	wirq->status = WAKE_IRQ_DEDICATED_ALLOCATED;

	return err;

err_free_irq:
	free_irq(irq, wirq);
err_free_name:
	kfree(wirq->name);
err_free:
	kfree(wirq);

	return err;
}

void dev_pm_enable_wake_irq(struct device *dev)
{
	struct wake_irq *wirq = dev->power.wakeirq;

	if (wirq && (wirq->status & WAKE_IRQ_DEDICATED_ALLOCATED))
		enable_irq(wirq->irq);
}

void dev_pm_disable_wake_irq(struct device *dev)
{
	struct wake_irq *wirq = dev->power.wakeirq;

	if (wirq && (wirq->status & WAKE_IRQ_DEDICATED_ALLOCATED))
		disable_irq_nosync(wirq->irq);
}

void dev_pm_enable_wake_irq_check(struct device *dev,
				  bool can_change_status)
{
	struct wake_irq *wirq = dev->power.wakeirq;

	if (!wirq || !((wirq->status & WAKE_IRQ_DEDICATED_MASK)))
		return;

	if (likely(wirq->status & WAKE_IRQ_DEDICATED_MANAGED)) {
		goto enable;
	} else if (can_change_status) {
		wirq->status |= WAKE_IRQ_DEDICATED_MANAGED;
		goto enable;
	}

	return;

enable:
	enable_irq(wirq->irq);
}

void dev_pm_disable_wake_irq_check(struct device *dev)
{
	struct wake_irq *wirq = dev->power.wakeirq;

	if (!wirq || !((wirq->status & WAKE_IRQ_DEDICATED_MASK)))
		return;

	if (wirq->status & WAKE_IRQ_DEDICATED_MANAGED)
		disable_irq_nosync(wirq->irq);
}

void dev_pm_arm_wake_irq(struct wake_irq *wirq)
{
	if (!wirq)
		return;

	if (device_may_wakeup(wirq->dev)) {
		if (wirq->status & WAKE_IRQ_DEDICATED_ALLOCATED &&
		    !pm_runtime_status_suspended(wirq->dev))
			enable_irq(wirq->irq);

		enable_irq_wake(wirq->irq);
	}
}

void dev_pm_disarm_wake_irq(struct wake_irq *wirq)
{
	if (!wirq)
		return;

	if (device_may_wakeup(wirq->dev)) {
		disable_irq_wake(wirq->irq);

		if (wirq->status & WAKE_IRQ_DEDICATED_ALLOCATED &&
		    !pm_runtime_status_suspended(wirq->dev))
			disable_irq_nosync(wirq->irq);
	}
}


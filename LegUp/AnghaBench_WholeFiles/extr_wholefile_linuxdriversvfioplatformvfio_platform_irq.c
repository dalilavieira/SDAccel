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
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
struct vfio_platform_irq {int masked; int hwirq; int flags; int count; int /*<<< orphan*/  lock; struct eventfd_ctx* trigger; struct vfio_platform_irq* name; int /*<<< orphan*/  unmask; int /*<<< orphan*/  mask; } ;
struct vfio_platform_device {int (* get_irq ) (struct vfio_platform_device*,int) ;int num_irqs; struct vfio_platform_irq* irqs; int /*<<< orphan*/  name; } ;
struct eventfd_ctx {int dummy; } ;
typedef  int irqreturn_t ;
typedef  int (* irq_handler_t ) (int,struct vfio_platform_irq*) ;
typedef  scalar_t__ int32_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTTY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NOAUTOEN ; 
 int IRQ_NONE ; 
 int IRQ_TYPE_LEVEL_MASK ; 
 scalar_t__ IS_ERR (struct eventfd_ctx*) ; 
 int PTR_ERR (struct eventfd_ctx*) ; 
 int VFIO_IRQ_INFO_AUTOMASKED ; 
 int VFIO_IRQ_INFO_EVENTFD ; 
 int VFIO_IRQ_INFO_MASKABLE ; 
#define  VFIO_IRQ_SET_ACTION_MASK 130 
#define  VFIO_IRQ_SET_ACTION_TRIGGER 129 
 int VFIO_IRQ_SET_ACTION_TYPE_MASK ; 
#define  VFIO_IRQ_SET_ACTION_UNMASK 128 
 int VFIO_IRQ_SET_DATA_BOOL ; 
 int VFIO_IRQ_SET_DATA_EVENTFD ; 
 int VFIO_IRQ_SET_DATA_NONE ; 
 int /*<<< orphan*/  disable_irq_nosync (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 struct eventfd_ctx* eventfd_ctx_fdget (int) ; 
 int /*<<< orphan*/  eventfd_ctx_put (struct eventfd_ctx*) ; 
 int /*<<< orphan*/  eventfd_signal (struct eventfd_ctx*,int) ; 
 int /*<<< orphan*/  free_irq (int,struct vfio_platform_irq*) ; 
 int /*<<< orphan*/  irq_clear_status_flags (int,int /*<<< orphan*/ ) ; 
 int irq_get_trigger_type (int) ; 
 int /*<<< orphan*/  irq_set_status_flags (int,int /*<<< orphan*/ ) ; 
 struct vfio_platform_irq* kasprintf (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 struct vfio_platform_irq* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct vfio_platform_irq*) ; 
 int request_irq (int,int (*) (int,struct vfio_platform_irq*),int /*<<< orphan*/ ,struct vfio_platform_irq*,struct vfio_platform_irq*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct vfio_platform_device*,int) ; 
 int stub2 (struct vfio_platform_device*,int) ; 
 int /*<<< orphan*/  vfio_virqfd_disable (int /*<<< orphan*/ *) ; 
 int vfio_virqfd_enable (void*,int (*) (void*,void*),int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static void vfio_platform_mask(struct vfio_platform_irq *irq_ctx)
{
	unsigned long flags;

	spin_lock_irqsave(&irq_ctx->lock, flags);

	if (!irq_ctx->masked) {
		disable_irq_nosync(irq_ctx->hwirq);
		irq_ctx->masked = true;
	}

	spin_unlock_irqrestore(&irq_ctx->lock, flags);
}

__attribute__((used)) static int vfio_platform_mask_handler(void *opaque, void *unused)
{
	struct vfio_platform_irq *irq_ctx = opaque;

	vfio_platform_mask(irq_ctx);

	return 0;
}

__attribute__((used)) static int vfio_platform_set_irq_mask(struct vfio_platform_device *vdev,
				      unsigned index, unsigned start,
				      unsigned count, uint32_t flags,
				      void *data)
{
	if (start != 0 || count != 1)
		return -EINVAL;

	if (!(vdev->irqs[index].flags & VFIO_IRQ_INFO_MASKABLE))
		return -EINVAL;

	if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
		int32_t fd = *(int32_t *)data;

		if (fd >= 0)
			return vfio_virqfd_enable((void *) &vdev->irqs[index],
						  vfio_platform_mask_handler,
						  NULL, NULL,
						  &vdev->irqs[index].mask, fd);

		vfio_virqfd_disable(&vdev->irqs[index].mask);
		return 0;
	}

	if (flags & VFIO_IRQ_SET_DATA_NONE) {
		vfio_platform_mask(&vdev->irqs[index]);

	} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
		uint8_t mask = *(uint8_t *)data;

		if (mask)
			vfio_platform_mask(&vdev->irqs[index]);
	}

	return 0;
}

__attribute__((used)) static void vfio_platform_unmask(struct vfio_platform_irq *irq_ctx)
{
	unsigned long flags;

	spin_lock_irqsave(&irq_ctx->lock, flags);

	if (irq_ctx->masked) {
		enable_irq(irq_ctx->hwirq);
		irq_ctx->masked = false;
	}

	spin_unlock_irqrestore(&irq_ctx->lock, flags);
}

__attribute__((used)) static int vfio_platform_unmask_handler(void *opaque, void *unused)
{
	struct vfio_platform_irq *irq_ctx = opaque;

	vfio_platform_unmask(irq_ctx);

	return 0;
}

__attribute__((used)) static int vfio_platform_set_irq_unmask(struct vfio_platform_device *vdev,
					unsigned index, unsigned start,
					unsigned count, uint32_t flags,
					void *data)
{
	if (start != 0 || count != 1)
		return -EINVAL;

	if (!(vdev->irqs[index].flags & VFIO_IRQ_INFO_MASKABLE))
		return -EINVAL;

	if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
		int32_t fd = *(int32_t *)data;

		if (fd >= 0)
			return vfio_virqfd_enable((void *) &vdev->irqs[index],
						  vfio_platform_unmask_handler,
						  NULL, NULL,
						  &vdev->irqs[index].unmask,
						  fd);

		vfio_virqfd_disable(&vdev->irqs[index].unmask);
		return 0;
	}

	if (flags & VFIO_IRQ_SET_DATA_NONE) {
		vfio_platform_unmask(&vdev->irqs[index]);

	} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
		uint8_t unmask = *(uint8_t *)data;

		if (unmask)
			vfio_platform_unmask(&vdev->irqs[index]);
	}

	return 0;
}

__attribute__((used)) static irqreturn_t vfio_automasked_irq_handler(int irq, void *dev_id)
{
	struct vfio_platform_irq *irq_ctx = dev_id;
	unsigned long flags;
	int ret = IRQ_NONE;

	spin_lock_irqsave(&irq_ctx->lock, flags);

	if (!irq_ctx->masked) {
		ret = IRQ_HANDLED;

		/* automask maskable interrupts */
		disable_irq_nosync(irq_ctx->hwirq);
		irq_ctx->masked = true;
	}

	spin_unlock_irqrestore(&irq_ctx->lock, flags);

	if (ret == IRQ_HANDLED)
		eventfd_signal(irq_ctx->trigger, 1);

	return ret;
}

__attribute__((used)) static irqreturn_t vfio_irq_handler(int irq, void *dev_id)
{
	struct vfio_platform_irq *irq_ctx = dev_id;

	eventfd_signal(irq_ctx->trigger, 1);

	return IRQ_HANDLED;
}

__attribute__((used)) static int vfio_set_trigger(struct vfio_platform_device *vdev, int index,
			    int fd, irq_handler_t handler)
{
	struct vfio_platform_irq *irq = &vdev->irqs[index];
	struct eventfd_ctx *trigger;
	int ret;

	if (irq->trigger) {
		irq_clear_status_flags(irq->hwirq, IRQ_NOAUTOEN);
		free_irq(irq->hwirq, irq);
		kfree(irq->name);
		eventfd_ctx_put(irq->trigger);
		irq->trigger = NULL;
	}

	if (fd < 0) /* Disable only */
		return 0;

	irq->name = kasprintf(GFP_KERNEL, "vfio-irq[%d](%s)",
						irq->hwirq, vdev->name);
	if (!irq->name)
		return -ENOMEM;

	trigger = eventfd_ctx_fdget(fd);
	if (IS_ERR(trigger)) {
		kfree(irq->name);
		return PTR_ERR(trigger);
	}

	irq->trigger = trigger;

	irq_set_status_flags(irq->hwirq, IRQ_NOAUTOEN);
	ret = request_irq(irq->hwirq, handler, 0, irq->name, irq);
	if (ret) {
		kfree(irq->name);
		eventfd_ctx_put(trigger);
		irq->trigger = NULL;
		return ret;
	}

	if (!irq->masked)
		enable_irq(irq->hwirq);

	return 0;
}

__attribute__((used)) static int vfio_platform_set_irq_trigger(struct vfio_platform_device *vdev,
					 unsigned index, unsigned start,
					 unsigned count, uint32_t flags,
					 void *data)
{
	struct vfio_platform_irq *irq = &vdev->irqs[index];
	irq_handler_t handler;

	if (vdev->irqs[index].flags & VFIO_IRQ_INFO_AUTOMASKED)
		handler = vfio_automasked_irq_handler;
	else
		handler = vfio_irq_handler;

	if (!count && (flags & VFIO_IRQ_SET_DATA_NONE))
		return vfio_set_trigger(vdev, index, -1, handler);

	if (start != 0 || count != 1)
		return -EINVAL;

	if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
		int32_t fd = *(int32_t *)data;

		return vfio_set_trigger(vdev, index, fd, handler);
	}

	if (flags & VFIO_IRQ_SET_DATA_NONE) {
		handler(irq->hwirq, irq);

	} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
		uint8_t trigger = *(uint8_t *)data;

		if (trigger)
			handler(irq->hwirq, irq);
	}

	return 0;
}

int vfio_platform_set_irqs_ioctl(struct vfio_platform_device *vdev,
				 uint32_t flags, unsigned index, unsigned start,
				 unsigned count, void *data)
{
	int (*func)(struct vfio_platform_device *vdev, unsigned index,
		    unsigned start, unsigned count, uint32_t flags,
		    void *data) = NULL;

	switch (flags & VFIO_IRQ_SET_ACTION_TYPE_MASK) {
	case VFIO_IRQ_SET_ACTION_MASK:
		func = vfio_platform_set_irq_mask;
		break;
	case VFIO_IRQ_SET_ACTION_UNMASK:
		func = vfio_platform_set_irq_unmask;
		break;
	case VFIO_IRQ_SET_ACTION_TRIGGER:
		func = vfio_platform_set_irq_trigger;
		break;
	}

	if (!func)
		return -ENOTTY;

	return func(vdev, index, start, count, flags, data);
}

int vfio_platform_irq_init(struct vfio_platform_device *vdev)
{
	int cnt = 0, i;

	while (vdev->get_irq(vdev, cnt) >= 0)
		cnt++;

	vdev->irqs = kcalloc(cnt, sizeof(struct vfio_platform_irq), GFP_KERNEL);
	if (!vdev->irqs)
		return -ENOMEM;

	for (i = 0; i < cnt; i++) {
		int hwirq = vdev->get_irq(vdev, i);

		if (hwirq < 0)
			goto err;

		spin_lock_init(&vdev->irqs[i].lock);

		vdev->irqs[i].flags = VFIO_IRQ_INFO_EVENTFD;

		if (irq_get_trigger_type(hwirq) & IRQ_TYPE_LEVEL_MASK)
			vdev->irqs[i].flags |= VFIO_IRQ_INFO_MASKABLE
						| VFIO_IRQ_INFO_AUTOMASKED;

		vdev->irqs[i].count = 1;
		vdev->irqs[i].hwirq = hwirq;
		vdev->irqs[i].masked = false;
	}

	vdev->num_irqs = cnt;

	return 0;
err:
	kfree(vdev->irqs);
	return -EINVAL;
}

void vfio_platform_irq_cleanup(struct vfio_platform_device *vdev)
{
	int i;

	for (i = 0; i < vdev->num_irqs; i++)
		vfio_set_trigger(vdev, i, -1, NULL);

	vdev->num_irqs = 0;
	kfree(vdev->irqs);
}


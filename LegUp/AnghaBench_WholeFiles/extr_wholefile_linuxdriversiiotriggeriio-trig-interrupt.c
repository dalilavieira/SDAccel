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
struct resource {unsigned long flags; int start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct iio_trigger {int /*<<< orphan*/  name; int /*<<< orphan*/ * ops; } ;
struct iio_interrupt_trigger_info {int irq; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 unsigned long IRQF_SHARED ; 
 unsigned long IRQF_TRIGGER_MASK ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  free_irq (int,struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_interrupt_trigger_ops ; 
 struct iio_trigger* iio_trigger_alloc (char*,int) ; 
 int /*<<< orphan*/  iio_trigger_free (struct iio_trigger*) ; 
 struct iio_interrupt_trigger_info* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_poll (void*) ; 
 int iio_trigger_register (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct iio_interrupt_trigger_info*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (struct iio_trigger*) ; 
 int /*<<< orphan*/  kfree (struct iio_interrupt_trigger_info*) ; 
 struct iio_interrupt_trigger_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct iio_trigger* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_trigger*) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),unsigned long,int /*<<< orphan*/ ,struct iio_trigger*) ; 

__attribute__((used)) static irqreturn_t iio_interrupt_trigger_poll(int irq, void *private)
{
	iio_trigger_poll(private);
	return IRQ_HANDLED;
}

__attribute__((used)) static int iio_interrupt_trigger_probe(struct platform_device *pdev)
{
	struct iio_interrupt_trigger_info *trig_info;
	struct iio_trigger *trig;
	unsigned long irqflags;
	struct resource *irq_res;
	int irq, ret = 0;

	irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);

	if (irq_res == NULL)
		return -ENODEV;

	irqflags = (irq_res->flags & IRQF_TRIGGER_MASK) | IRQF_SHARED;

	irq = irq_res->start;

	trig = iio_trigger_alloc("irqtrig%d", irq);
	if (!trig) {
		ret = -ENOMEM;
		goto error_ret;
	}

	trig_info = kzalloc(sizeof(*trig_info), GFP_KERNEL);
	if (!trig_info) {
		ret = -ENOMEM;
		goto error_free_trigger;
	}
	iio_trigger_set_drvdata(trig, trig_info);
	trig_info->irq = irq;
	trig->ops = &iio_interrupt_trigger_ops;
	ret = request_irq(irq, iio_interrupt_trigger_poll,
			  irqflags, trig->name, trig);
	if (ret) {
		dev_err(&pdev->dev,
			"request IRQ-%d failed", irq);
		goto error_free_trig_info;
	}

	ret = iio_trigger_register(trig);
	if (ret)
		goto error_release_irq;
	platform_set_drvdata(pdev, trig);

	return 0;

/* First clean up the partly allocated trigger */
error_release_irq:
	free_irq(irq, trig);
error_free_trig_info:
	kfree(trig_info);
error_free_trigger:
	iio_trigger_free(trig);
error_ret:
	return ret;
}

__attribute__((used)) static int iio_interrupt_trigger_remove(struct platform_device *pdev)
{
	struct iio_trigger *trig;
	struct iio_interrupt_trigger_info *trig_info;

	trig = platform_get_drvdata(pdev);
	trig_info = iio_trigger_get_drvdata(trig);
	iio_trigger_unregister(trig);
	free_irq(trig_info->irq, trig);
	kfree(trig_info);
	iio_trigger_free(trig);

	return 0;
}


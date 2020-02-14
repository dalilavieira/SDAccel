#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct iio_dummy_regs {size_t reg_id; unsigned long reg_data; } ;
struct iio_dev_attr {size_t address; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_4__ {int base; int* inuse; int /*<<< orphan*/  irq_sim; struct iio_dummy_regs* regs; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IIO_EVENTGEN_NO ; 
 TYPE_1__* iio_evgen ; 
 int /*<<< orphan*/  irq_sim_fini (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_sim_fire (int /*<<< orphan*/ *,size_t) ; 
 int irq_sim_init (int /*<<< orphan*/ *,int) ; 
 void* irq_sim_irqnum (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 TYPE_1__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev_attr* to_iio_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int iio_dummy_evgen_create(void)
{
	int ret;

	iio_evgen = kzalloc(sizeof(*iio_evgen), GFP_KERNEL);
	if (!iio_evgen)
		return -ENOMEM;

	ret = irq_sim_init(&iio_evgen->irq_sim, IIO_EVENTGEN_NO);
	if (ret < 0) {
		kfree(iio_evgen);
		return ret;
	}

	iio_evgen->base = irq_sim_irqnum(&iio_evgen->irq_sim, 0);
	mutex_init(&iio_evgen->lock);

	return 0;
}

int iio_dummy_evgen_get_irq(void)
{
	int i, ret = 0;

	if (!iio_evgen)
		return -ENODEV;

	mutex_lock(&iio_evgen->lock);
	for (i = 0; i < IIO_EVENTGEN_NO; i++) {
		if (!iio_evgen->inuse[i]) {
			ret = irq_sim_irqnum(&iio_evgen->irq_sim, i);
			iio_evgen->inuse[i] = true;
			break;
		}
	}
	mutex_unlock(&iio_evgen->lock);
	if (i == IIO_EVENTGEN_NO)
		return -ENOMEM;

	return ret;
}

void iio_dummy_evgen_release_irq(int irq)
{
	mutex_lock(&iio_evgen->lock);
	iio_evgen->inuse[irq - iio_evgen->base] = false;
	mutex_unlock(&iio_evgen->lock);
}

struct iio_dummy_regs *iio_dummy_evgen_get_regs(int irq)
{
	return &iio_evgen->regs[irq - iio_evgen->base];
}

__attribute__((used)) static void iio_dummy_evgen_free(void)
{
	irq_sim_fini(&iio_evgen->irq_sim);
	kfree(iio_evgen);
}

__attribute__((used)) static void iio_evgen_release(struct device *dev)
{
	iio_dummy_evgen_free();
}

__attribute__((used)) static ssize_t iio_evgen_poke(struct device *dev,
			      struct device_attribute *attr,
			      const char *buf,
			      size_t len)
{
	struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
	unsigned long event;
	int ret;

	ret = kstrtoul(buf, 10, &event);
	if (ret)
		return ret;

	iio_evgen->regs[this_attr->address].reg_id   = this_attr->address;
	iio_evgen->regs[this_attr->address].reg_data = event;

	irq_sim_fire(&iio_evgen->irq_sim, this_attr->address);

	return len;
}


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
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct completion {int dummy; } ;
struct jz4740_hwmon {scalar_t__ irq; int /*<<< orphan*/  lock; struct completion read_completion; struct platform_device* pdev; int /*<<< orphan*/  base; TYPE_1__* cell; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* disable ) (struct platform_device*) ;int /*<<< orphan*/  (* enable ) (struct platform_device*) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 long ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HZ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  complete (struct completion*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct jz4740_hwmon* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,char*,struct jz4740_hwmon*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_ioremap_resource (struct device*,struct resource*) ; 
 struct jz4740_hwmon* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct jz4740_hwmon*) ; 
 int /*<<< orphan*/  disable_irq (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 int /*<<< orphan*/  init_completion (struct completion*) ; 
 int /*<<< orphan*/  jz4740_groups ; 
 TYPE_1__* mfd_get_cell (struct platform_device*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reinit_completion (struct completion*) ; 
 int sprintf (char*,char*,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct platform_device*) ; 
 int /*<<< orphan*/  stub2 (struct platform_device*) ; 
 long wait_for_completion_interruptible_timeout (struct completion*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t jz4740_hwmon_irq(int irq, void *data)
{
	struct jz4740_hwmon *hwmon = data;

	complete(&hwmon->read_completion);
	return IRQ_HANDLED;
}

__attribute__((used)) static ssize_t in0_input_show(struct device *dev,
			      struct device_attribute *dev_attr, char *buf)
{
	struct jz4740_hwmon *hwmon = dev_get_drvdata(dev);
	struct platform_device *pdev = hwmon->pdev;
	struct completion *completion = &hwmon->read_completion;
	long t;
	unsigned long val;
	int ret;

	mutex_lock(&hwmon->lock);

	reinit_completion(completion);

	enable_irq(hwmon->irq);
	hwmon->cell->enable(pdev);

	t = wait_for_completion_interruptible_timeout(completion, HZ);

	if (t > 0) {
		val = readw(hwmon->base) & 0xfff;
		val = (val * 3300) >> 12;
		ret = sprintf(buf, "%lu\n", val);
	} else {
		ret = t ? t : -ETIMEDOUT;
	}

	hwmon->cell->disable(pdev);
	disable_irq(hwmon->irq);

	mutex_unlock(&hwmon->lock);

	return ret;
}

__attribute__((used)) static int jz4740_hwmon_probe(struct platform_device *pdev)
{
	int ret;
	struct device *dev = &pdev->dev;
	struct jz4740_hwmon *hwmon;
	struct device *hwmon_dev;
	struct resource *mem;

	hwmon = devm_kzalloc(dev, sizeof(*hwmon), GFP_KERNEL);
	if (!hwmon)
		return -ENOMEM;

	hwmon->cell = mfd_get_cell(pdev);

	hwmon->irq = platform_get_irq(pdev, 0);
	if (hwmon->irq < 0) {
		dev_err(&pdev->dev, "Failed to get platform irq: %d\n",
			hwmon->irq);
		return hwmon->irq;
	}

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hwmon->base = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(hwmon->base))
		return PTR_ERR(hwmon->base);

	hwmon->pdev = pdev;
	init_completion(&hwmon->read_completion);
	mutex_init(&hwmon->lock);

	ret = devm_request_irq(dev, hwmon->irq, jz4740_hwmon_irq, 0,
			       pdev->name, hwmon);
	if (ret) {
		dev_err(&pdev->dev, "Failed to request irq: %d\n", ret);
		return ret;
	}
	disable_irq(hwmon->irq);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, "jz4740", hwmon,
							   jz4740_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


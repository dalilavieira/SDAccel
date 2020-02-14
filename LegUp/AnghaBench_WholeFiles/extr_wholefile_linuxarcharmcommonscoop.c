#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int base; int ngpio; void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int /*<<< orphan*/  label; } ;
struct scoop_dev {scalar_t__ base; TYPE_1__ gpio; int /*<<< orphan*/  suspend_set; int /*<<< orphan*/  suspend_clr; int /*<<< orphan*/  scoop_lock; } ;
struct scoop_config {int io_dir; int io_out; int gpio_base; int /*<<< orphan*/  suspend_set; int /*<<< orphan*/  suspend_clr; } ;
struct resource {scalar_t__ start; } ;
struct device {struct scoop_config* platform_data; } ;
struct platform_device {struct device dev; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ SCOOP_CCR ; 
 scalar_t__ SCOOP_CDR ; 
 scalar_t__ SCOOP_CPR ; 
 scalar_t__ SCOOP_GPCR ; 
 scalar_t__ SCOOP_GPRR ; 
 scalar_t__ SCOOP_GPWR ; 
 scalar_t__ SCOOP_IMR ; 
 scalar_t__ SCOOP_IRM ; 
 scalar_t__ SCOOP_ISR ; 
 scalar_t__ SCOOP_MCR ; 
 struct scoop_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int gpiochip_add_data (TYPE_1__*,struct scoop_dev*) ; 
 struct scoop_dev* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (TYPE_1__*) ; 
 unsigned short ioread16 (scalar_t__) ; 
 scalar_t__ ioremap (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  iowrite16 (int,scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct scoop_dev*) ; 
 struct scoop_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct scoop_dev* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct scoop_dev*) ; 
 int /*<<< orphan*/  printk (char*,unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void reset_scoop(struct device *dev)
{
	struct scoop_dev *sdev = dev_get_drvdata(dev);

	iowrite16(0x0100, sdev->base + SCOOP_MCR);  /* 00 */
	iowrite16(0x0000, sdev->base + SCOOP_CDR);  /* 04 */
	iowrite16(0x0000, sdev->base + SCOOP_CCR);  /* 10 */
	iowrite16(0x0000, sdev->base + SCOOP_IMR);  /* 18 */
	iowrite16(0x00FF, sdev->base + SCOOP_IRM);  /* 14 */
	iowrite16(0x0000, sdev->base + SCOOP_ISR);  /* 1C */
	iowrite16(0x0000, sdev->base + SCOOP_IRM);
}

__attribute__((used)) static void __scoop_gpio_set(struct scoop_dev *sdev,
			unsigned offset, int value)
{
	unsigned short gpwr;

	gpwr = ioread16(sdev->base + SCOOP_GPWR);
	if (value)
		gpwr |= 1 << (offset + 1);
	else
		gpwr &= ~(1 << (offset + 1));
	iowrite16(gpwr, sdev->base + SCOOP_GPWR);
}

__attribute__((used)) static void scoop_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
	struct scoop_dev *sdev = gpiochip_get_data(chip);
	unsigned long flags;

	spin_lock_irqsave(&sdev->scoop_lock, flags);

	__scoop_gpio_set(sdev, offset, value);

	spin_unlock_irqrestore(&sdev->scoop_lock, flags);
}

__attribute__((used)) static int scoop_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct scoop_dev *sdev = gpiochip_get_data(chip);

	/* XXX: I'm unsure, but it seems so */
	return !!(ioread16(sdev->base + SCOOP_GPRR) & (1 << (offset + 1)));
}

__attribute__((used)) static int scoop_gpio_direction_input(struct gpio_chip *chip,
			unsigned offset)
{
	struct scoop_dev *sdev = gpiochip_get_data(chip);
	unsigned long flags;
	unsigned short gpcr;

	spin_lock_irqsave(&sdev->scoop_lock, flags);

	gpcr = ioread16(sdev->base + SCOOP_GPCR);
	gpcr &= ~(1 << (offset + 1));
	iowrite16(gpcr, sdev->base + SCOOP_GPCR);

	spin_unlock_irqrestore(&sdev->scoop_lock, flags);

	return 0;
}

__attribute__((used)) static int scoop_gpio_direction_output(struct gpio_chip *chip,
			unsigned offset, int value)
{
	struct scoop_dev *sdev = gpiochip_get_data(chip);
	unsigned long flags;
	unsigned short gpcr;

	spin_lock_irqsave(&sdev->scoop_lock, flags);

	__scoop_gpio_set(sdev, offset, value);

	gpcr = ioread16(sdev->base + SCOOP_GPCR);
	gpcr |= 1 << (offset + 1);
	iowrite16(gpcr, sdev->base + SCOOP_GPCR);

	spin_unlock_irqrestore(&sdev->scoop_lock, flags);

	return 0;
}

unsigned short read_scoop_reg(struct device *dev, unsigned short reg)
{
	struct scoop_dev *sdev = dev_get_drvdata(dev);
	return ioread16(sdev->base + reg);
}

void write_scoop_reg(struct device *dev, unsigned short reg, unsigned short data)
{
	struct scoop_dev *sdev = dev_get_drvdata(dev);
	iowrite16(data, sdev->base + reg);
}

__attribute__((used)) static int scoop_probe(struct platform_device *pdev)
{
	struct scoop_dev *devptr;
	struct scoop_config *inf;
	struct resource *mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	int ret;

	if (!mem)
		return -EINVAL;

	devptr = kzalloc(sizeof(struct scoop_dev), GFP_KERNEL);
	if (!devptr)
		return -ENOMEM;

	spin_lock_init(&devptr->scoop_lock);

	inf = pdev->dev.platform_data;
	devptr->base = ioremap(mem->start, resource_size(mem));

	if (!devptr->base) {
		ret = -ENOMEM;
		goto err_ioremap;
	}

	platform_set_drvdata(pdev, devptr);

	printk("Sharp Scoop Device found at 0x%08x -> 0x%8p\n",(unsigned int)mem->start, devptr->base);

	iowrite16(0x0140, devptr->base + SCOOP_MCR);
	reset_scoop(&pdev->dev);
	iowrite16(0x0000, devptr->base + SCOOP_CPR);
	iowrite16(inf->io_dir & 0xffff, devptr->base + SCOOP_GPCR);
	iowrite16(inf->io_out & 0xffff, devptr->base + SCOOP_GPWR);

	devptr->suspend_clr = inf->suspend_clr;
	devptr->suspend_set = inf->suspend_set;

	devptr->gpio.base = -1;

	if (inf->gpio_base != 0) {
		devptr->gpio.label = dev_name(&pdev->dev);
		devptr->gpio.base = inf->gpio_base;
		devptr->gpio.ngpio = 12; /* PA11 = 0, PA12 = 1, etc. up to PA22 = 11 */
		devptr->gpio.set = scoop_gpio_set;
		devptr->gpio.get = scoop_gpio_get;
		devptr->gpio.direction_input = scoop_gpio_direction_input;
		devptr->gpio.direction_output = scoop_gpio_direction_output;

		ret = gpiochip_add_data(&devptr->gpio, devptr);
		if (ret)
			goto err_gpio;
	}

	return 0;

err_gpio:
	platform_set_drvdata(pdev, NULL);
err_ioremap:
	iounmap(devptr->base);
	kfree(devptr);

	return ret;
}

__attribute__((used)) static int scoop_remove(struct platform_device *pdev)
{
	struct scoop_dev *sdev = platform_get_drvdata(pdev);

	if (!sdev)
		return -EINVAL;

	if (sdev->gpio.base != -1)
		gpiochip_remove(&sdev->gpio);

	platform_set_drvdata(pdev, NULL);
	iounmap(sdev->base);
	kfree(sdev);

	return 0;
}


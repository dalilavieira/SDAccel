#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  type; } ;
struct serio {int (* write ) (struct serio*,unsigned char) ;int (* open ) (struct serio*) ;void (* close ) (struct serio*) ;TYPE_2__ dev; struct ps2if* port_data; int /*<<< orphan*/  phys; int /*<<< orphan*/  name; TYPE_1__ id; } ;
struct resource {int dummy; } ;
struct ps2if {struct serio* io; scalar_t__ base; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  SERIO_8042 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,scalar_t__,int) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct ps2if* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ps2if*) ; 
 struct serio* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct ps2if* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ps2if*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  serio_interrupt (struct serio*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_register_port (struct serio*) ; 
 int /*<<< orphan*/  serio_unregister_port (struct serio*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static irqreturn_t altera_ps2_rxint(int irq, void *dev_id)
{
	struct ps2if *ps2if = dev_id;
	unsigned int status;
	irqreturn_t handled = IRQ_NONE;

	while ((status = readl(ps2if->base)) & 0xffff0000) {
		serio_interrupt(ps2if->io, status & 0xff, 0);
		handled = IRQ_HANDLED;
	}

	return handled;
}

__attribute__((used)) static int altera_ps2_write(struct serio *io, unsigned char val)
{
	struct ps2if *ps2if = io->port_data;

	writel(val, ps2if->base);
	return 0;
}

__attribute__((used)) static int altera_ps2_open(struct serio *io)
{
	struct ps2if *ps2if = io->port_data;

	/* clear fifo */
	while (readl(ps2if->base) & 0xffff0000)
		/* empty */;

	writel(1, ps2if->base + 4); /* enable rx irq */
	return 0;
}

__attribute__((used)) static void altera_ps2_close(struct serio *io)
{
	struct ps2if *ps2if = io->port_data;

	writel(0, ps2if->base + 4); /* disable rx irq */
}

__attribute__((used)) static int altera_ps2_probe(struct platform_device *pdev)
{
	struct ps2if *ps2if;
	struct resource *res;
	struct serio *serio;
	int error, irq;

	ps2if = devm_kzalloc(&pdev->dev, sizeof(struct ps2if), GFP_KERNEL);
	if (!ps2if)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ps2if->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ps2if->base))
		return PTR_ERR(ps2if->base);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return -ENXIO;

	error = devm_request_irq(&pdev->dev, irq, altera_ps2_rxint, 0,
				 pdev->name, ps2if);
	if (error) {
		dev_err(&pdev->dev, "could not request IRQ %d\n", irq);
		return error;
	}

	serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
	if (!serio)
		return -ENOMEM;

	serio->id.type		= SERIO_8042;
	serio->write		= altera_ps2_write;
	serio->open		= altera_ps2_open;
	serio->close		= altera_ps2_close;
	strlcpy(serio->name, dev_name(&pdev->dev), sizeof(serio->name));
	strlcpy(serio->phys, dev_name(&pdev->dev), sizeof(serio->phys));
	serio->port_data	= ps2if;
	serio->dev.parent	= &pdev->dev;
	ps2if->io		= serio;

	dev_info(&pdev->dev, "base %p, irq %d\n", ps2if->base, irq);

	serio_register_port(ps2if->io);
	platform_set_drvdata(pdev, ps2if);

	return 0;
}

__attribute__((used)) static int altera_ps2_remove(struct platform_device *pdev)
{
	struct ps2if *ps2if = platform_get_drvdata(pdev);

	serio_unregister_port(ps2if->io);

	return 0;
}


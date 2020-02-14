#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_8__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct serio {struct apbps2_priv* port_data; } ;
struct resource {int dummy; } ;
struct TYPE_17__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_6__ dev; } ;
struct apbps2_priv {TYPE_2__* io; TYPE_8__* regs; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_18__ {int /*<<< orphan*/  reload; int /*<<< orphan*/  ctrl; int /*<<< orphan*/  data; int /*<<< orphan*/  status; } ;
struct TYPE_15__ {int /*<<< orphan*/  type; } ;
struct TYPE_16__ {int (* open ) (struct serio*) ;void (* close ) (struct serio*) ;int (* write ) (struct serio*,unsigned char) ;int /*<<< orphan*/  phys; int /*<<< orphan*/  name; struct apbps2_priv* port_data; TYPE_1__ id; } ;

/* Variables and functions */
 int APBPS2_CTRL_RE ; 
 int APBPS2_CTRL_RI ; 
 int APBPS2_CTRL_TE ; 
 unsigned long APBPS2_STATUS_DR ; 
 unsigned long APBPS2_STATUS_FE ; 
 unsigned long APBPS2_STATUS_PE ; 
 unsigned long APBPS2_STATUS_TF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (TYPE_8__*) ; 
 int PTR_ERR (TYPE_8__*) ; 
 int /*<<< orphan*/  SERIO_8042 ; 
 unsigned long SERIO_FRAME ; 
 unsigned long SERIO_PARITY ; 
 int /*<<< orphan*/  apbps2_idx ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_6__*,char*,int,TYPE_8__*) ; 
 TYPE_8__* devm_ioremap_resource (TYPE_6__*,struct resource*) ; 
 struct apbps2_priv* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_6__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct apbps2_priv*) ; 
 unsigned long ioread32be (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iowrite32be (int,int /*<<< orphan*/ *) ; 
 int irq_of_parse_and_map (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 struct apbps2_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct apbps2_priv*) ; 
 int /*<<< orphan*/  serio_interrupt (TYPE_2__*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  serio_register_port (TYPE_2__*) ; 
 int /*<<< orphan*/  serio_unregister_port (TYPE_2__*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static irqreturn_t apbps2_isr(int irq, void *dev_id)
{
	struct apbps2_priv *priv = dev_id;
	unsigned long status, data, rxflags;
	irqreturn_t ret = IRQ_NONE;

	while ((status = ioread32be(&priv->regs->status)) & APBPS2_STATUS_DR) {
		data = ioread32be(&priv->regs->data);
		rxflags = (status & APBPS2_STATUS_PE) ? SERIO_PARITY : 0;
		rxflags |= (status & APBPS2_STATUS_FE) ? SERIO_FRAME : 0;

		/* clear error bits? */
		if (rxflags)
			iowrite32be(0, &priv->regs->status);

		serio_interrupt(priv->io, data, rxflags);

		ret = IRQ_HANDLED;
	}

	return ret;
}

__attribute__((used)) static int apbps2_write(struct serio *io, unsigned char val)
{
	struct apbps2_priv *priv = io->port_data;
	unsigned int tleft = 10000; /* timeout in 100ms */

	/* delay until PS/2 controller has room for more chars */
	while ((ioread32be(&priv->regs->status) & APBPS2_STATUS_TF) && tleft--)
		udelay(10);

	if ((ioread32be(&priv->regs->status) & APBPS2_STATUS_TF) == 0) {
		iowrite32be(val, &priv->regs->data);

		iowrite32be(APBPS2_CTRL_RE | APBPS2_CTRL_RI | APBPS2_CTRL_TE,
				&priv->regs->ctrl);
		return 0;
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static int apbps2_open(struct serio *io)
{
	struct apbps2_priv *priv = io->port_data;
	int limit;
	unsigned long tmp;

	/* clear error flags */
	iowrite32be(0, &priv->regs->status);

	/* Clear old data if available (unlikely) */
	limit = 1024;
	while ((ioread32be(&priv->regs->status) & APBPS2_STATUS_DR) && --limit)
		tmp = ioread32be(&priv->regs->data);

	/* Enable reciever and it's interrupt */
	iowrite32be(APBPS2_CTRL_RE | APBPS2_CTRL_RI, &priv->regs->ctrl);

	return 0;
}

__attribute__((used)) static void apbps2_close(struct serio *io)
{
	struct apbps2_priv *priv = io->port_data;

	/* stop interrupts at PS/2 HW level */
	iowrite32be(0, &priv->regs->ctrl);
}

__attribute__((used)) static int apbps2_of_probe(struct platform_device *ofdev)
{
	struct apbps2_priv *priv;
	int irq, err;
	u32 freq_hz;
	struct resource *res;

	priv = devm_kzalloc(&ofdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv) {
		dev_err(&ofdev->dev, "memory allocation failed\n");
		return -ENOMEM;
	}

	/* Find Device Address */
	res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
	priv->regs = devm_ioremap_resource(&ofdev->dev, res);
	if (IS_ERR(priv->regs))
		return PTR_ERR(priv->regs);

	/* Reset hardware, disable interrupt */
	iowrite32be(0, &priv->regs->ctrl);

	/* IRQ */
	irq = irq_of_parse_and_map(ofdev->dev.of_node, 0);
	err = devm_request_irq(&ofdev->dev, irq, apbps2_isr,
				IRQF_SHARED, "apbps2", priv);
	if (err) {
		dev_err(&ofdev->dev, "request IRQ%d failed\n", irq);
		return err;
	}

	/* Get core frequency */
	if (of_property_read_u32(ofdev->dev.of_node, "freq", &freq_hz)) {
		dev_err(&ofdev->dev, "unable to get core frequency\n");
		return -EINVAL;
	}

	/* Set reload register to core freq in kHz/10 */
	iowrite32be(freq_hz / 10000, &priv->regs->reload);

	priv->io = kzalloc(sizeof(struct serio), GFP_KERNEL);
	if (!priv->io)
		return -ENOMEM;

	priv->io->id.type = SERIO_8042;
	priv->io->open = apbps2_open;
	priv->io->close = apbps2_close;
	priv->io->write = apbps2_write;
	priv->io->port_data = priv;
	strlcpy(priv->io->name, "APBPS2 PS/2", sizeof(priv->io->name));
	snprintf(priv->io->phys, sizeof(priv->io->phys),
		 "apbps2_%d", apbps2_idx++);

	dev_info(&ofdev->dev, "irq = %d, base = 0x%p\n", irq, priv->regs);

	serio_register_port(priv->io);

	platform_set_drvdata(ofdev, priv);

	return 0;
}

__attribute__((used)) static int apbps2_of_remove(struct platform_device *of_dev)
{
	struct apbps2_priv *priv = platform_get_drvdata(of_dev);

	serio_unregister_port(priv->io);

	return 0;
}


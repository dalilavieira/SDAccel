#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u32 ;
struct TYPE_11__ {TYPE_3__* parent; } ;
struct TYPE_10__ {int /*<<< orphan*/  type; } ;
struct serio {int (* write ) (struct serio*,unsigned char) ;int (* open ) (struct serio*) ;void (* close ) (struct serio*) ;int /*<<< orphan*/  phys; int /*<<< orphan*/  name; TYPE_2__ dev; struct olpc_apsp* port_data; TYPE_1__ id; } ;
struct resource {int dummy; } ;
struct TYPE_12__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct olpc_apsp {scalar_t__ open_count; scalar_t__ irq; struct serio* padio; struct serio* kbio; TYPE_3__* dev; scalar_t__ base; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned char CMD_CNTR_MASK ; 
 unsigned long CMD_STS_MASK ; 
 scalar_t__ COMMAND_FIFO_STATUS ; 
 scalar_t__ COMMAND_RETURN_STATUS ; 
 unsigned int DATA_MASK ; 
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int INT_0 ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 unsigned char KEYBOARD_PORT ; 
 unsigned char MAX_PENDING_CMDS ; 
 scalar_t__ PJ_INTERRUPT_MASK ; 
 scalar_t__ PJ_RST_INTERRUPT ; 
 unsigned int PORT_MASK ; 
 unsigned char PORT_SHIFT ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ SECURE_PROCESSOR_COMMAND ; 
 int /*<<< orphan*/  SERIO_8042 ; 
 int /*<<< orphan*/  SERIO_8042_XL ; 
 unsigned int SP_COMMAND_COMPLETE_RESET ; 
 unsigned char TOUCHPAD_PORT ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_3__*,int) ; 
 scalar_t__ devm_ioremap_resource (TYPE_3__*,struct resource*) ; 
 struct olpc_apsp* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,struct olpc_apsp*) ; 
 struct serio* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 struct olpc_apsp* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct olpc_apsp*) ; 
 int /*<<< orphan*/  pm_wakeup_event (TYPE_3__*,int) ; 
 void* readl (scalar_t__) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct olpc_apsp*) ; 
 int /*<<< orphan*/  serio_interrupt (struct serio*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_register_port (struct serio*) ; 
 int /*<<< orphan*/  serio_unregister_port (struct serio*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static int olpc_apsp_write(struct serio *port, unsigned char val)
{
	struct olpc_apsp *priv = port->port_data;
	unsigned int i;
	u32 which = 0;

	if (port == priv->padio)
		which = TOUCHPAD_PORT << PORT_SHIFT;
	else
		which = KEYBOARD_PORT << PORT_SHIFT;

	dev_dbg(priv->dev, "olpc_apsp_write which=%x val=%x\n", which, val);
	for (i = 0; i < 50; i++) {
		u32 sts = readl(priv->base + COMMAND_FIFO_STATUS);
		if ((sts & CMD_CNTR_MASK) < MAX_PENDING_CMDS) {
			writel(which | val,
			       priv->base + SECURE_PROCESSOR_COMMAND);
			return 0;
		}
		/* SP busy. This has not been seen in practice. */
		mdelay(1);
	}

	dev_dbg(priv->dev, "olpc_apsp_write timeout, status=%x\n",
		readl(priv->base + COMMAND_FIFO_STATUS));

	return -ETIMEDOUT;
}

__attribute__((used)) static irqreturn_t olpc_apsp_rx(int irq, void *dev_id)
{
	struct olpc_apsp *priv = dev_id;
	unsigned int w, tmp;
	struct serio *serio;

	/*
	 * Write 1 to PJ_RST_INTERRUPT to acknowledge and clear the interrupt
	 * Write 0xff00 to SECURE_PROCESSOR_COMMAND.
	 */
	tmp = readl(priv->base + PJ_RST_INTERRUPT);
	if (!(tmp & SP_COMMAND_COMPLETE_RESET)) {
		dev_warn(priv->dev, "spurious interrupt?\n");
		return IRQ_NONE;
	}

	w = readl(priv->base + COMMAND_RETURN_STATUS);
	dev_dbg(priv->dev, "olpc_apsp_rx %x\n", w);

	if (w >> PORT_SHIFT == KEYBOARD_PORT)
		serio = priv->kbio;
	else
		serio = priv->padio;

	serio_interrupt(serio, w & DATA_MASK, 0);

	/* Ack and clear interrupt */
	writel(tmp | SP_COMMAND_COMPLETE_RESET, priv->base + PJ_RST_INTERRUPT);
	writel(PORT_MASK, priv->base + SECURE_PROCESSOR_COMMAND);

	pm_wakeup_event(priv->dev, 1000);
	return IRQ_HANDLED;
}

__attribute__((used)) static int olpc_apsp_open(struct serio *port)
{
	struct olpc_apsp *priv = port->port_data;
	unsigned int tmp;

	if (priv->open_count++ == 0) {
		/* Enable interrupt 0 by clearing its bit */
		tmp = readl(priv->base + PJ_INTERRUPT_MASK);
		writel(tmp & ~INT_0, priv->base + PJ_INTERRUPT_MASK);
	}

	return 0;
}

__attribute__((used)) static void olpc_apsp_close(struct serio *port)
{
	struct olpc_apsp *priv = port->port_data;
	unsigned int tmp;

	if (--priv->open_count == 0) {
		/* Disable interrupt 0 */
		tmp = readl(priv->base + PJ_INTERRUPT_MASK);
		writel(tmp | INT_0, priv->base + PJ_INTERRUPT_MASK);
	}
}

__attribute__((used)) static int olpc_apsp_probe(struct platform_device *pdev)
{
	struct serio *kb_serio, *pad_serio;
	struct olpc_apsp *priv;
	struct resource *res;
	struct device_node *np;
	unsigned long l;
	int error;

	priv = devm_kzalloc(&pdev->dev, sizeof(struct olpc_apsp), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	np = pdev->dev.of_node;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->base)) {
		dev_err(&pdev->dev, "Failed to map WTM registers\n");
		return PTR_ERR(priv->base);
	}

	priv->irq = platform_get_irq(pdev, 0);
	if (priv->irq < 0)
		return priv->irq;

	l = readl(priv->base + COMMAND_FIFO_STATUS);
	if (!(l & CMD_STS_MASK)) {
		dev_err(&pdev->dev, "SP cannot accept commands.\n");
		return -EIO;
	}

	/* KEYBOARD */
	kb_serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
	if (!kb_serio)
		return -ENOMEM;
	kb_serio->id.type	= SERIO_8042_XL;
	kb_serio->write		= olpc_apsp_write;
	kb_serio->open		= olpc_apsp_open;
	kb_serio->close		= olpc_apsp_close;
	kb_serio->port_data	= priv;
	kb_serio->dev.parent	= &pdev->dev;
	strlcpy(kb_serio->name, "sp keyboard", sizeof(kb_serio->name));
	strlcpy(kb_serio->phys, "sp/serio0", sizeof(kb_serio->phys));
	priv->kbio		= kb_serio;
	serio_register_port(kb_serio);

	/* TOUCHPAD */
	pad_serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
	if (!pad_serio) {
		error = -ENOMEM;
		goto err_pad;
	}
	pad_serio->id.type	= SERIO_8042;
	pad_serio->write	= olpc_apsp_write;
	pad_serio->open		= olpc_apsp_open;
	pad_serio->close	= olpc_apsp_close;
	pad_serio->port_data	= priv;
	pad_serio->dev.parent	= &pdev->dev;
	strlcpy(pad_serio->name, "sp touchpad", sizeof(pad_serio->name));
	strlcpy(pad_serio->phys, "sp/serio1", sizeof(pad_serio->phys));
	priv->padio		= pad_serio;
	serio_register_port(pad_serio);

	error = request_irq(priv->irq, olpc_apsp_rx, 0, "olpc-apsp", priv);
	if (error) {
		dev_err(&pdev->dev, "Failed to request IRQ\n");
		goto err_irq;
	}

	priv->dev = &pdev->dev;
	device_init_wakeup(priv->dev, 1);
	platform_set_drvdata(pdev, priv);

	dev_dbg(&pdev->dev, "probed successfully.\n");
	return 0;

err_irq:
	serio_unregister_port(pad_serio);
err_pad:
	serio_unregister_port(kb_serio);
	return error;
}

__attribute__((used)) static int olpc_apsp_remove(struct platform_device *pdev)
{
	struct olpc_apsp *priv = platform_get_drvdata(pdev);

	free_irq(priv->irq, priv);

	serio_unregister_port(priv->kbio);
	serio_unregister_port(priv->padio);

	return 0;
}


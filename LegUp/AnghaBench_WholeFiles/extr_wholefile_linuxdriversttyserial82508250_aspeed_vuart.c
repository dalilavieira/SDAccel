#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct uart_port {int (* serial_in ) (struct uart_port*,int) ;int minor; int mapbase; int (* startup ) (struct uart_port*) ;void (* shutdown ) (struct uart_port*) ;void (* throttle ) (struct uart_port*) ;void (* unthrottle ) (struct uart_port*) ;int custom_divisor; int regshift; int fifosize; int line; int (* handle_irq ) (struct uart_port*) ;int uartclk; int flags; int /*<<< orphan*/  irq; int /*<<< orphan*/  type; int /*<<< orphan*/  iotype; int /*<<< orphan*/  irqflags; TYPE_2__* dev; int /*<<< orphan*/  status; int /*<<< orphan*/  mapsize; scalar_t__ membase; struct aspeed_vuart* private_data; int /*<<< orphan*/  lock; TYPE_1__* state; int /*<<< orphan*/  (* serial_out ) (struct uart_port*,int,int) ;} ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;unsigned char ier; struct uart_port port; int /*<<< orphan*/  capabilities; int /*<<< orphan*/  (* dl_write ) (struct uart_8250_port*,int) ;} ;
struct timer_list {int dummy; } ;
struct resource {int start; } ;
struct TYPE_7__ {int /*<<< orphan*/  kobj; struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct aspeed_vuart {int line; scalar_t__ clk; TYPE_2__* dev; int /*<<< orphan*/  unthrottle_timer; scalar_t__ regs; struct uart_8250_port* port; } ;
typedef  int status ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  port ;
struct TYPE_6__ {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 scalar_t__ ASPEED_VUART_ADDRH ; 
 scalar_t__ ASPEED_VUART_ADDRL ; 
 scalar_t__ ASPEED_VUART_GCRA ; 
 int ASPEED_VUART_GCRA_DISABLE_HOST_TX_DISCARD ; 
 int ASPEED_VUART_GCRA_VUART_EN ; 
 scalar_t__ ASPEED_VUART_GCRB ; 
 int ASPEED_VUART_GCRB_HOST_SIRQ_MASK ; 
 int ASPEED_VUART_GCRB_HOST_SIRQ_SHIFT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  PORT_16550A ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  UART_CAP_AFE ; 
 int /*<<< orphan*/  UART_CAP_FIFO ; 
 int UART_IER ; 
 unsigned char UART_IER_RDI ; 
 unsigned char UART_IER_RLSI ; 
 int UART_IIR ; 
 unsigned int UART_IIR_NO_INT ; 
 int UART_LSR ; 
 unsigned int UART_LSR_BI ; 
 unsigned int UART_LSR_DR ; 
 unsigned int UART_LSR_THRE ; 
 int UART_MCR ; 
 int UPF_BOOT_AUTOCONF ; 
 int UPF_FIXED_PORT ; 
 int UPF_FIXED_TYPE ; 
 int UPF_NO_THRE_TEST ; 
 int UPF_SHARE_IRQ ; 
 int UPF_SKIP_TEST ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 int /*<<< orphan*/  UPSTAT_SYNC_FIFO ; 
 int /*<<< orphan*/  aspeed_vuart_attr_group ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 struct aspeed_vuart* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 scalar_t__ devm_clk_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 struct aspeed_vuart* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct aspeed_vuart* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_dispose_mapping (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  memset (struct uart_8250_port*,int /*<<< orphan*/ ,int) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int of_alias_get_id (struct device_node*,char*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct aspeed_vuart* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct aspeed_vuart*) ; 
 int readb (scalar_t__) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  serial8250_do_shutdown (struct uart_port*) ; 
 int serial8250_do_startup (struct uart_port*) ; 
 int /*<<< orphan*/  serial8250_modem_status (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_read_char (struct uart_8250_port*,unsigned int) ; 
 int serial8250_register_8250_port (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_tx_chars (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int) ; 
 unsigned int serial_port_in (struct uart_port*,int) ; 
 int snprintf (char*,scalar_t__,char*,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct uart_port*,int) ; 
 int /*<<< orphan*/  stub2 (struct uart_port*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 int /*<<< orphan*/  stub4 (struct uart_8250_port*,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer_pending (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int tty_buffer_space_avail (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (int /*<<< orphan*/ *) ; 
 scalar_t__ unthrottle_timeout ; 
 int /*<<< orphan*/  unthrottle_timer ; 
 struct uart_8250_port* up_to_u8250p (struct uart_port*) ; 
 struct aspeed_vuart* vuart ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static inline int serial_in(struct uart_8250_port *up, int offset)
{
	return up->port.serial_in(&up->port, offset);
}

__attribute__((used)) static inline void serial_out(struct uart_8250_port *up, int offset, int value)
{
	up->port.serial_out(&up->port, offset, value);
}

__attribute__((used)) static inline int serial_dl_read(struct uart_8250_port *up)
{
	return up->dl_read(up);
}

__attribute__((used)) static inline void serial_dl_write(struct uart_8250_port *up, int value)
{
	up->dl_write(up, value);
}

__attribute__((used)) static inline void serial8250_out_MCR(struct uart_8250_port *up, int value)
{
	serial_out(up, UART_MCR, value);
}

__attribute__((used)) static inline int serial8250_in_MCR(struct uart_8250_port *up)
{
	return serial_in(up, UART_MCR);
}

__attribute__((used)) static inline int serial8250_pnp_init(void) { return 0; }

__attribute__((used)) static inline void serial8250_pnp_exit(void) { }

__attribute__((used)) static inline int fintek_8250_probe(struct uart_8250_port *uart) { return 0; }

__attribute__((used)) static inline int is_omap1_8250(struct uart_8250_port *pt)
{
	return 0;
}

__attribute__((used)) static inline int is_omap1510_8250(struct uart_8250_port *pt)
{
	return 0;
}

__attribute__((used)) static inline int serial8250_tx_dma(struct uart_8250_port *p)
{
	return -1;
}

__attribute__((used)) static inline int serial8250_rx_dma(struct uart_8250_port *p)
{
	return -1;
}

__attribute__((used)) static inline void serial8250_rx_dma_flush(struct uart_8250_port *p) { }

__attribute__((used)) static inline int serial8250_request_dma(struct uart_8250_port *p)
{
	return -1;
}

__attribute__((used)) static inline void serial8250_release_dma(struct uart_8250_port *p) { }

__attribute__((used)) static inline int ns16550a_goto_highspeed(struct uart_8250_port *up)
{
	unsigned char status;

	status = serial_in(up, 0x04); /* EXCR2 */
#define PRESL(x) ((x) & 0x30)
	if (PRESL(status) == 0x10) {
		/* already in high speed mode */
		return 0;
	} else {
		status &= ~0xB0; /* Disable LOCK, mask out PRESL[01] */
		status |= 0x10;  /* 1.625 divisor for baud_base --> 921600 */
		serial_out(up, 0x04, status);
	}
	return 1;
}

__attribute__((used)) static inline int serial_index(struct uart_port *port)
{
	return port->minor - 64;
}

__attribute__((used)) static ssize_t lpc_address_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct aspeed_vuart *vuart = dev_get_drvdata(dev);
	u16 addr;

	addr = (readb(vuart->regs + ASPEED_VUART_ADDRH) << 8) |
		(readb(vuart->regs + ASPEED_VUART_ADDRL));

	return snprintf(buf, PAGE_SIZE - 1, "0x%x\n", addr);
}

__attribute__((used)) static ssize_t lpc_address_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct aspeed_vuart *vuart = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 0, &val);
	if (err)
		return err;

	writeb(val >> 8, vuart->regs + ASPEED_VUART_ADDRH);
	writeb(val >> 0, vuart->regs + ASPEED_VUART_ADDRL);

	return count;
}

__attribute__((used)) static ssize_t sirq_show(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	struct aspeed_vuart *vuart = dev_get_drvdata(dev);
	u8 reg;

	reg = readb(vuart->regs + ASPEED_VUART_GCRB);
	reg &= ASPEED_VUART_GCRB_HOST_SIRQ_MASK;
	reg >>= ASPEED_VUART_GCRB_HOST_SIRQ_SHIFT;

	return snprintf(buf, PAGE_SIZE - 1, "%u\n", reg);
}

__attribute__((used)) static ssize_t sirq_store(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct aspeed_vuart *vuart = dev_get_drvdata(dev);
	unsigned long val;
	int err;
	u8 reg;

	err = kstrtoul(buf, 0, &val);
	if (err)
		return err;

	val <<= ASPEED_VUART_GCRB_HOST_SIRQ_SHIFT;
	val &= ASPEED_VUART_GCRB_HOST_SIRQ_MASK;

	reg = readb(vuart->regs + ASPEED_VUART_GCRB);
	reg &= ~ASPEED_VUART_GCRB_HOST_SIRQ_MASK;
	reg |= val;
	writeb(reg, vuart->regs + ASPEED_VUART_GCRB);

	return count;
}

__attribute__((used)) static void aspeed_vuart_set_enabled(struct aspeed_vuart *vuart, bool enabled)
{
	u8 reg = readb(vuart->regs + ASPEED_VUART_GCRA);

	if (enabled)
		reg |= ASPEED_VUART_GCRA_VUART_EN;
	else
		reg &= ~ASPEED_VUART_GCRA_VUART_EN;

	writeb(reg, vuart->regs + ASPEED_VUART_GCRA);
}

__attribute__((used)) static void aspeed_vuart_set_host_tx_discard(struct aspeed_vuart *vuart,
					     bool discard)
{
	u8 reg;

	reg = readb(vuart->regs + ASPEED_VUART_GCRA);

	/* If the DISABLE_HOST_TX_DISCARD bit is set, discard is disabled */
	if (!discard)
		reg |= ASPEED_VUART_GCRA_DISABLE_HOST_TX_DISCARD;
	else
		reg &= ~ASPEED_VUART_GCRA_DISABLE_HOST_TX_DISCARD;

	writeb(reg, vuart->regs + ASPEED_VUART_GCRA);
}

__attribute__((used)) static int aspeed_vuart_startup(struct uart_port *uart_port)
{
	struct uart_8250_port *uart_8250_port = up_to_u8250p(uart_port);
	struct aspeed_vuart *vuart = uart_8250_port->port.private_data;
	int rc;

	rc = serial8250_do_startup(uart_port);
	if (rc)
		return rc;

	aspeed_vuart_set_host_tx_discard(vuart, false);

	return 0;
}

__attribute__((used)) static void aspeed_vuart_shutdown(struct uart_port *uart_port)
{
	struct uart_8250_port *uart_8250_port = up_to_u8250p(uart_port);
	struct aspeed_vuart *vuart = uart_8250_port->port.private_data;

	aspeed_vuart_set_host_tx_discard(vuart, true);

	serial8250_do_shutdown(uart_port);
}

__attribute__((used)) static void __aspeed_vuart_set_throttle(struct uart_8250_port *up,
		bool throttle)
{
	unsigned char irqs = UART_IER_RLSI | UART_IER_RDI;

	up->ier &= ~irqs;
	if (!throttle)
		up->ier |= irqs;
	serial_out(up, UART_IER, up->ier);
}

__attribute__((used)) static void aspeed_vuart_set_throttle(struct uart_port *port, bool throttle)
{
	struct uart_8250_port *up = up_to_u8250p(port);
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);
	__aspeed_vuart_set_throttle(up, throttle);
	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void aspeed_vuart_throttle(struct uart_port *port)
{
	aspeed_vuart_set_throttle(port, true);
}

__attribute__((used)) static void aspeed_vuart_unthrottle(struct uart_port *port)
{
	aspeed_vuart_set_throttle(port, false);
}

__attribute__((used)) static void aspeed_vuart_unthrottle_exp(struct timer_list *timer)
{
	struct aspeed_vuart *vuart = from_timer(vuart, timer, unthrottle_timer);
	struct uart_8250_port *up = vuart->port;

	if (!tty_buffer_space_avail(&up->port.state->port)) {
		mod_timer(&vuart->unthrottle_timer,
			  jiffies + unthrottle_timeout);
		return;
	}

	aspeed_vuart_unthrottle(&up->port);
}

__attribute__((used)) static int aspeed_vuart_handle_irq(struct uart_port *port)
{
	struct uart_8250_port *up = up_to_u8250p(port);
	unsigned int iir, lsr;
	unsigned long flags;
	int space, count;

	iir = serial_port_in(port, UART_IIR);

	if (iir & UART_IIR_NO_INT)
		return 0;

	spin_lock_irqsave(&port->lock, flags);

	lsr = serial_port_in(port, UART_LSR);

	if (lsr & (UART_LSR_DR | UART_LSR_BI)) {
		space = tty_buffer_space_avail(&port->state->port);

		if (!space) {
			/* throttle and schedule an unthrottle later */
			struct aspeed_vuart *vuart = port->private_data;
			__aspeed_vuart_set_throttle(up, true);

			if (!timer_pending(&vuart->unthrottle_timer)) {
				vuart->port = up;
				mod_timer(&vuart->unthrottle_timer,
					  jiffies + unthrottle_timeout);
			}

		} else {
			count = min(space, 256);

			do {
				serial8250_read_char(up, lsr);
				lsr = serial_in(up, UART_LSR);
				if (--count == 0)
					break;
			} while (lsr & (UART_LSR_DR | UART_LSR_BI));

			tty_flip_buffer_push(&port->state->port);
		}
	}

	serial8250_modem_status(up);
	if (lsr & UART_LSR_THRE)
		serial8250_tx_chars(up);

	spin_unlock_irqrestore(&port->lock, flags);

	return 1;
}

__attribute__((used)) static int aspeed_vuart_probe(struct platform_device *pdev)
{
	struct uart_8250_port port;
	struct aspeed_vuart *vuart;
	struct device_node *np;
	struct resource *res;
	u32 clk, prop;
	int rc;

	np = pdev->dev.of_node;

	vuart = devm_kzalloc(&pdev->dev, sizeof(*vuart), GFP_KERNEL);
	if (!vuart)
		return -ENOMEM;

	vuart->dev = &pdev->dev;
	timer_setup(&vuart->unthrottle_timer, aspeed_vuart_unthrottle_exp, 0);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	vuart->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(vuart->regs))
		return PTR_ERR(vuart->regs);

	memset(&port, 0, sizeof(port));
	port.port.private_data = vuart;
	port.port.membase = vuart->regs;
	port.port.mapbase = res->start;
	port.port.mapsize = resource_size(res);
	port.port.startup = aspeed_vuart_startup;
	port.port.shutdown = aspeed_vuart_shutdown;
	port.port.throttle = aspeed_vuart_throttle;
	port.port.unthrottle = aspeed_vuart_unthrottle;
	port.port.status = UPSTAT_SYNC_FIFO;
	port.port.dev = &pdev->dev;

	rc = sysfs_create_group(&vuart->dev->kobj, &aspeed_vuart_attr_group);
	if (rc < 0)
		return rc;

	if (of_property_read_u32(np, "clock-frequency", &clk)) {
		vuart->clk = devm_clk_get(&pdev->dev, NULL);
		if (IS_ERR(vuart->clk)) {
			dev_warn(&pdev->dev,
				"clk or clock-frequency not defined\n");
			rc = PTR_ERR(vuart->clk);
			goto err_sysfs_remove;
		}

		rc = clk_prepare_enable(vuart->clk);
		if (rc < 0)
			goto err_sysfs_remove;

		clk = clk_get_rate(vuart->clk);
	}

	/* If current-speed was set, then try not to change it. */
	if (of_property_read_u32(np, "current-speed", &prop) == 0)
		port.port.custom_divisor = clk / (16 * prop);

	/* Check for shifted address mapping */
	if (of_property_read_u32(np, "reg-offset", &prop) == 0)
		port.port.mapbase += prop;

	/* Check for registers offset within the devices address range */
	if (of_property_read_u32(np, "reg-shift", &prop) == 0)
		port.port.regshift = prop;

	/* Check for fifo size */
	if (of_property_read_u32(np, "fifo-size", &prop) == 0)
		port.port.fifosize = prop;

	/* Check for a fixed line number */
	rc = of_alias_get_id(np, "serial");
	if (rc >= 0)
		port.port.line = rc;

	port.port.irq = irq_of_parse_and_map(np, 0);
	port.port.irqflags = IRQF_SHARED;
	port.port.handle_irq = aspeed_vuart_handle_irq;
	port.port.iotype = UPIO_MEM;
	port.port.type = PORT_16550A;
	port.port.uartclk = clk;
	port.port.flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF
		| UPF_FIXED_PORT | UPF_FIXED_TYPE | UPF_NO_THRE_TEST;

	if (of_property_read_bool(np, "no-loopback-test"))
		port.port.flags |= UPF_SKIP_TEST;

	if (port.port.fifosize)
		port.capabilities = UART_CAP_FIFO;

	if (of_property_read_bool(np, "auto-flow-control"))
		port.capabilities |= UART_CAP_AFE;

	rc = serial8250_register_8250_port(&port);
	if (rc < 0)
		goto err_clk_disable;

	vuart->line = rc;

	aspeed_vuart_set_enabled(vuart, true);
	aspeed_vuart_set_host_tx_discard(vuart, true);
	platform_set_drvdata(pdev, vuart);

	return 0;

err_clk_disable:
	clk_disable_unprepare(vuart->clk);
	irq_dispose_mapping(port.port.irq);
err_sysfs_remove:
	sysfs_remove_group(&vuart->dev->kobj, &aspeed_vuart_attr_group);
	return rc;
}

__attribute__((used)) static int aspeed_vuart_remove(struct platform_device *pdev)
{
	struct aspeed_vuart *vuart = platform_get_drvdata(pdev);

	del_timer_sync(&vuart->unthrottle_timer);
	aspeed_vuart_set_enabled(vuart, false);
	serial8250_unregister_port(vuart->line);
	sysfs_remove_group(&vuart->dev->kobj, &aspeed_vuart_attr_group);
	clk_disable_unprepare(vuart->clk);

	return 0;
}


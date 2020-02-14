#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_8__ {int /*<<< orphan*/  rx; int /*<<< orphan*/  frame; int /*<<< orphan*/  brk; int /*<<< orphan*/  overrun; int /*<<< orphan*/  tx; } ;
struct uart_port {int x_char; int read_status_mask; int ignore_status_mask; scalar_t__ irq; int flags; scalar_t__ type; int /*<<< orphan*/ * membase; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  dev; int /*<<< orphan*/  lock; TYPE_2__* state; TYPE_1__ icount; } ;
struct serial_struct {scalar_t__ irq; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_11__ {scalar_t__ of_node; } ;
struct platform_device {size_t id; TYPE_5__ dev; } ;
struct TYPE_10__ {size_t line; int irq; scalar_t__ uartclk; int flags; int fifosize; int /*<<< orphan*/ * ops; scalar_t__ x_char; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  iotype; scalar_t__ type; TYPE_5__* dev; } ;
struct owl_uart_port {TYPE_3__ port; int /*<<< orphan*/  clk; } ;
struct owl_uart_info {int tx_fifosize; } ;
struct of_device_id {struct owl_uart_info* data; } ;
struct ktermios {int c_cflag; int c_iflag; } ;
struct circ_buf {unsigned int* buf; size_t tail; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_9__ {int /*<<< orphan*/  port; struct circ_buf xmit; } ;

/* Variables and functions */
 int CMSPAR ; 
 int CRTSCTS ; 
#define  CS5 131 
#define  CS6 130 
#define  CS7 129 
#define  CS8 128 
 int CSIZE ; 
 int CSTOPB ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INPCK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned int OWL_UART_CTL ; 
 int OWL_UART_CTL_AFE ; 
 int OWL_UART_CTL_DWLS_5BITS ; 
 int OWL_UART_CTL_DWLS_6BITS ; 
 int OWL_UART_CTL_DWLS_7BITS ; 
 int OWL_UART_CTL_DWLS_8BITS ; 
 int OWL_UART_CTL_DWLS_MASK ; 
 int OWL_UART_CTL_EN ; 
 int OWL_UART_CTL_LBEN ; 
 int OWL_UART_CTL_PRS_EVEN ; 
 int OWL_UART_CTL_PRS_MARK ; 
 int OWL_UART_CTL_PRS_MASK ; 
 int OWL_UART_CTL_PRS_NONE ; 
 int OWL_UART_CTL_PRS_ODD ; 
 int OWL_UART_CTL_PRS_SPACE ; 
 int OWL_UART_CTL_RXDE ; 
 int OWL_UART_CTL_RXIE ; 
 int OWL_UART_CTL_STPS_2BITS ; 
 int OWL_UART_CTL_TRFS_TX ; 
 int OWL_UART_CTL_TXDE ; 
 int OWL_UART_CTL_TXIE ; 
 size_t OWL_UART_PORT_NUM ; 
 unsigned int OWL_UART_RXDAT ; 
 unsigned int OWL_UART_STAT ; 
 int OWL_UART_STAT_CTSS ; 
 int OWL_UART_STAT_RFEM ; 
 int OWL_UART_STAT_RIP ; 
 int OWL_UART_STAT_RTSS ; 
 int OWL_UART_STAT_RXER ; 
 int OWL_UART_STAT_RXST ; 
 int OWL_UART_STAT_TFER ; 
 int OWL_UART_STAT_TFES ; 
 int OWL_UART_STAT_TFFU ; 
 int OWL_UART_STAT_TIP ; 
 unsigned int OWL_UART_TXDAT ; 
 int PARENB ; 
 int PARODD ; 
 scalar_t__ PORT_OWL ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int SERIAL_XMIT_SIZE ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 unsigned int TIOCM_LOOP ; 
 unsigned int TIOCM_RTS ; 
 unsigned int TIOCSER_TEMT ; 
 char TTY_NORMAL ; 
 char TTY_PARITY ; 
 int UART_CONFIG_TYPE ; 
 int UPF_BOOT_AUTOCONF ; 
 int UPF_IOREMAP ; 
 int UPF_LOW_LATENCY ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 scalar_t__ WAKEUP_CHARS ; 
 scalar_t__ clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_set_rate (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * devm_ioremap_nocache (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_iounmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct owl_uart_port* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_release_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_request_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct uart_port*) ; 
 size_t of_alias_get_id (scalar_t__,char*) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  owl_uart_driver ; 
 int /*<<< orphan*/  owl_uart_dt_matches ; 
 int /*<<< orphan*/  owl_uart_ops ; 
 struct owl_uart_port** owl_uart_ports ; 
 struct owl_uart_port* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct owl_uart_port*) ; 
 int readl (int /*<<< orphan*/ *) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct uart_port*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct owl_uart_port* to_owl_uart_port (struct uart_port*) ; 
 struct platform_device* to_platform_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tty_insert_flip_char (int /*<<< orphan*/ *,int,char) ; 
 scalar_t__ tty_termios_baud_rate (struct ktermios*) ; 
 int /*<<< orphan*/  tty_termios_encode_baud_rate (struct ktermios*,unsigned int,unsigned int) ; 
 int uart_add_one_port (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int,int) ; 
 int /*<<< orphan*/  uart_remove_one_port (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void owl_uart_write(struct uart_port *port, u32 val, unsigned int off)
{
	writel(val, port->membase + off);
}

__attribute__((used)) static inline u32 owl_uart_read(struct uart_port *port, unsigned int off)
{
	return readl(port->membase + off);
}

__attribute__((used)) static void owl_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	u32 ctl;

	ctl = owl_uart_read(port, OWL_UART_CTL);

	if (mctrl & TIOCM_LOOP)
		ctl |= OWL_UART_CTL_LBEN;
	else
		ctl &= ~OWL_UART_CTL_LBEN;

	owl_uart_write(port, ctl, OWL_UART_CTL);
}

__attribute__((used)) static unsigned int owl_uart_get_mctrl(struct uart_port *port)
{
	unsigned int mctrl = TIOCM_CAR | TIOCM_DSR;
	u32 stat, ctl;

	ctl = owl_uart_read(port, OWL_UART_CTL);
	stat = owl_uart_read(port, OWL_UART_STAT);
	if (stat & OWL_UART_STAT_RTSS)
		mctrl |= TIOCM_RTS;
	if ((stat & OWL_UART_STAT_CTSS) || !(ctl & OWL_UART_CTL_AFE))
		mctrl |= TIOCM_CTS;
	return mctrl;
}

__attribute__((used)) static unsigned int owl_uart_tx_empty(struct uart_port *port)
{
	unsigned long flags;
	u32 val;
	unsigned int ret;

	spin_lock_irqsave(&port->lock, flags);

	val = owl_uart_read(port, OWL_UART_STAT);
	ret = (val & OWL_UART_STAT_TFES) ? TIOCSER_TEMT : 0;

	spin_unlock_irqrestore(&port->lock, flags);

	return ret;
}

__attribute__((used)) static void owl_uart_stop_rx(struct uart_port *port)
{
	u32 val;

	val = owl_uart_read(port, OWL_UART_CTL);
	val &= ~(OWL_UART_CTL_RXIE | OWL_UART_CTL_RXDE);
	owl_uart_write(port, val, OWL_UART_CTL);

	val = owl_uart_read(port, OWL_UART_STAT);
	val |= OWL_UART_STAT_RIP;
	owl_uart_write(port, val, OWL_UART_STAT);
}

__attribute__((used)) static void owl_uart_stop_tx(struct uart_port *port)
{
	u32 val;

	val = owl_uart_read(port, OWL_UART_CTL);
	val &= ~(OWL_UART_CTL_TXIE | OWL_UART_CTL_TXDE);
	owl_uart_write(port, val, OWL_UART_CTL);

	val = owl_uart_read(port, OWL_UART_STAT);
	val |= OWL_UART_STAT_TIP;
	owl_uart_write(port, val, OWL_UART_STAT);
}

__attribute__((used)) static void owl_uart_start_tx(struct uart_port *port)
{
	u32 val;

	if (uart_tx_stopped(port)) {
		owl_uart_stop_tx(port);
		return;
	}

	val = owl_uart_read(port, OWL_UART_STAT);
	val |= OWL_UART_STAT_TIP;
	owl_uart_write(port, val, OWL_UART_STAT);

	val = owl_uart_read(port, OWL_UART_CTL);
	val |= OWL_UART_CTL_TXIE;
	owl_uart_write(port, val, OWL_UART_CTL);
}

__attribute__((used)) static void owl_uart_send_chars(struct uart_port *port)
{
	struct circ_buf *xmit = &port->state->xmit;
	unsigned int ch;

	if (uart_tx_stopped(port))
		return;

	if (port->x_char) {
		while (!(owl_uart_read(port, OWL_UART_STAT) & OWL_UART_STAT_TFFU))
			cpu_relax();
		owl_uart_write(port, port->x_char, OWL_UART_TXDAT);
		port->icount.tx++;
		port->x_char = 0;
	}

	while (!(owl_uart_read(port, OWL_UART_STAT) & OWL_UART_STAT_TFFU)) {
		if (uart_circ_empty(xmit))
			break;

		ch = xmit->buf[xmit->tail];
		owl_uart_write(port, ch, OWL_UART_TXDAT);
		xmit->tail = (xmit->tail + 1) & (SERIAL_XMIT_SIZE - 1);
		port->icount.tx++;
	}

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

	if (uart_circ_empty(xmit))
		owl_uart_stop_tx(port);
}

__attribute__((used)) static void owl_uart_receive_chars(struct uart_port *port)
{
	u32 stat, val;

	val = owl_uart_read(port, OWL_UART_CTL);
	val &= ~OWL_UART_CTL_TRFS_TX;
	owl_uart_write(port, val, OWL_UART_CTL);

	stat = owl_uart_read(port, OWL_UART_STAT);
	while (!(stat & OWL_UART_STAT_RFEM)) {
		char flag = TTY_NORMAL;

		if (stat & OWL_UART_STAT_RXER)
			port->icount.overrun++;

		if (stat & OWL_UART_STAT_RXST) {
			/* We are not able to distinguish the error type. */
			port->icount.brk++;
			port->icount.frame++;

			stat &= port->read_status_mask;
			if (stat & OWL_UART_STAT_RXST)
				flag = TTY_PARITY;
		} else
			port->icount.rx++;

		val = owl_uart_read(port, OWL_UART_RXDAT);
		val &= 0xff;

		if ((stat & port->ignore_status_mask) == 0)
			tty_insert_flip_char(&port->state->port, val, flag);

		stat = owl_uart_read(port, OWL_UART_STAT);
	}

	spin_unlock(&port->lock);
	tty_flip_buffer_push(&port->state->port);
	spin_lock(&port->lock);
}

__attribute__((used)) static irqreturn_t owl_uart_irq(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	unsigned long flags;
	u32 stat;

	spin_lock_irqsave(&port->lock, flags);

	stat = owl_uart_read(port, OWL_UART_STAT);

	if (stat & OWL_UART_STAT_RIP)
		owl_uart_receive_chars(port);

	if (stat & OWL_UART_STAT_TIP)
		owl_uart_send_chars(port);

	stat = owl_uart_read(port, OWL_UART_STAT);
	stat |= OWL_UART_STAT_RIP | OWL_UART_STAT_TIP;
	owl_uart_write(port, stat, OWL_UART_STAT);

	spin_unlock_irqrestore(&port->lock, flags);

	return IRQ_HANDLED;
}

__attribute__((used)) static void owl_uart_shutdown(struct uart_port *port)
{
	u32 val;
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);

	val = owl_uart_read(port, OWL_UART_CTL);
	val &= ~(OWL_UART_CTL_TXIE | OWL_UART_CTL_RXIE
		| OWL_UART_CTL_TXDE | OWL_UART_CTL_RXDE | OWL_UART_CTL_EN);
	owl_uart_write(port, val, OWL_UART_CTL);

	spin_unlock_irqrestore(&port->lock, flags);

	free_irq(port->irq, port);
}

__attribute__((used)) static int owl_uart_startup(struct uart_port *port)
{
	u32 val;
	unsigned long flags;
	int ret;

	ret = request_irq(port->irq, owl_uart_irq, IRQF_TRIGGER_HIGH,
			"owl-uart", port);
	if (ret)
		return ret;

	spin_lock_irqsave(&port->lock, flags);

	val = owl_uart_read(port, OWL_UART_STAT);
	val |= OWL_UART_STAT_RIP | OWL_UART_STAT_TIP
		| OWL_UART_STAT_RXER | OWL_UART_STAT_TFER | OWL_UART_STAT_RXST;
	owl_uart_write(port, val, OWL_UART_STAT);

	val = owl_uart_read(port, OWL_UART_CTL);
	val |= OWL_UART_CTL_RXIE | OWL_UART_CTL_TXIE;
	val |= OWL_UART_CTL_EN;
	owl_uart_write(port, val, OWL_UART_CTL);

	spin_unlock_irqrestore(&port->lock, flags);

	return 0;
}

__attribute__((used)) static void owl_uart_change_baudrate(struct owl_uart_port *owl_port,
				     unsigned long baud)
{
	clk_set_rate(owl_port->clk, baud * 8);
}

__attribute__((used)) static void owl_uart_set_termios(struct uart_port *port,
				 struct ktermios *termios,
				 struct ktermios *old)
{
	struct owl_uart_port *owl_port = to_owl_uart_port(port);
	unsigned int baud;
	u32 ctl;
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);

	ctl = owl_uart_read(port, OWL_UART_CTL);

	ctl &= ~OWL_UART_CTL_DWLS_MASK;
	switch (termios->c_cflag & CSIZE) {
	case CS5:
		ctl |= OWL_UART_CTL_DWLS_5BITS;
		break;
	case CS6:
		ctl |= OWL_UART_CTL_DWLS_6BITS;
		break;
	case CS7:
		ctl |= OWL_UART_CTL_DWLS_7BITS;
		break;
	case CS8:
	default:
		ctl |= OWL_UART_CTL_DWLS_8BITS;
		break;
	}

	if (termios->c_cflag & CSTOPB)
		ctl |= OWL_UART_CTL_STPS_2BITS;
	else
		ctl &= ~OWL_UART_CTL_STPS_2BITS;

	ctl &= ~OWL_UART_CTL_PRS_MASK;
	if (termios->c_cflag & PARENB) {
		if (termios->c_cflag & CMSPAR) {
			if (termios->c_cflag & PARODD)
				ctl |= OWL_UART_CTL_PRS_MARK;
			else
				ctl |= OWL_UART_CTL_PRS_SPACE;
		} else if (termios->c_cflag & PARODD)
			ctl |= OWL_UART_CTL_PRS_ODD;
		else
			ctl |= OWL_UART_CTL_PRS_EVEN;
	} else
		ctl |= OWL_UART_CTL_PRS_NONE;

	if (termios->c_cflag & CRTSCTS)
		ctl |= OWL_UART_CTL_AFE;
	else
		ctl &= ~OWL_UART_CTL_AFE;

	owl_uart_write(port, ctl, OWL_UART_CTL);

	baud = uart_get_baud_rate(port, termios, old, 9600, 3200000);
	owl_uart_change_baudrate(owl_port, baud);

	/* Don't rewrite B0 */
	if (tty_termios_baud_rate(termios))
		tty_termios_encode_baud_rate(termios, baud, baud);

	port->read_status_mask |= OWL_UART_STAT_RXER;
	if (termios->c_iflag & INPCK)
		port->read_status_mask |= OWL_UART_STAT_RXST;

	uart_update_timeout(port, termios->c_cflag, baud);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void owl_uart_release_port(struct uart_port *port)
{
	struct platform_device *pdev = to_platform_device(port->dev);
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return;

	if (port->flags & UPF_IOREMAP) {
		devm_release_mem_region(port->dev, port->mapbase,
			resource_size(res));
		devm_iounmap(port->dev, port->membase);
		port->membase = NULL;
	}
}

__attribute__((used)) static int owl_uart_request_port(struct uart_port *port)
{
	struct platform_device *pdev = to_platform_device(port->dev);
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -ENXIO;

	if (!devm_request_mem_region(port->dev, port->mapbase,
			resource_size(res), dev_name(port->dev)))
		return -EBUSY;

	if (port->flags & UPF_IOREMAP) {
		port->membase = devm_ioremap_nocache(port->dev, port->mapbase,
				resource_size(res));
		if (!port->membase)
			return -EBUSY;
	}

	return 0;
}

__attribute__((used)) static const char *owl_uart_type(struct uart_port *port)
{
	return (port->type == PORT_OWL) ? "owl-uart" : NULL;
}

__attribute__((used)) static int owl_uart_verify_port(struct uart_port *port,
				struct serial_struct *ser)
{
	if (port->type != PORT_OWL)
		return -EINVAL;

	if (port->irq != ser->irq)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static void owl_uart_config_port(struct uart_port *port, int flags)
{
	if (flags & UART_CONFIG_TYPE) {
		port->type = PORT_OWL;
		owl_uart_request_port(port);
	}
}

__attribute__((used)) static int owl_uart_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	const struct owl_uart_info *info = NULL;
	struct resource *res_mem;
	struct owl_uart_port *owl_port;
	int ret, irq;

	if (pdev->dev.of_node) {
		pdev->id = of_alias_get_id(pdev->dev.of_node, "serial");
		match = of_match_node(owl_uart_dt_matches, pdev->dev.of_node);
		if (match)
			info = match->data;
	}

	if (pdev->id < 0 || pdev->id >= OWL_UART_PORT_NUM) {
		dev_err(&pdev->dev, "id %d out of range\n", pdev->id);
		return -EINVAL;
	}

	res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res_mem) {
		dev_err(&pdev->dev, "could not get mem\n");
		return -ENODEV;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "could not get irq\n");
		return irq;
	}

	if (owl_uart_ports[pdev->id]) {
		dev_err(&pdev->dev, "port %d already allocated\n", pdev->id);
		return -EBUSY;
	}

	owl_port = devm_kzalloc(&pdev->dev, sizeof(*owl_port), GFP_KERNEL);
	if (!owl_port)
		return -ENOMEM;

	owl_port->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(owl_port->clk)) {
		dev_err(&pdev->dev, "could not get clk\n");
		return PTR_ERR(owl_port->clk);
	}

	owl_port->port.dev = &pdev->dev;
	owl_port->port.line = pdev->id;
	owl_port->port.type = PORT_OWL;
	owl_port->port.iotype = UPIO_MEM;
	owl_port->port.mapbase = res_mem->start;
	owl_port->port.irq = irq;
	owl_port->port.uartclk = clk_get_rate(owl_port->clk);
	if (owl_port->port.uartclk == 0) {
		dev_err(&pdev->dev, "clock rate is zero\n");
		return -EINVAL;
	}
	owl_port->port.flags = UPF_BOOT_AUTOCONF | UPF_IOREMAP | UPF_LOW_LATENCY;
	owl_port->port.x_char = 0;
	owl_port->port.fifosize = (info) ? info->tx_fifosize : 16;
	owl_port->port.ops = &owl_uart_ops;

	owl_uart_ports[pdev->id] = owl_port;
	platform_set_drvdata(pdev, owl_port);

	ret = uart_add_one_port(&owl_uart_driver, &owl_port->port);
	if (ret)
		owl_uart_ports[pdev->id] = NULL;

	return ret;
}

__attribute__((used)) static int owl_uart_remove(struct platform_device *pdev)
{
	struct owl_uart_port *owl_port = platform_get_drvdata(pdev);

	uart_remove_one_port(&owl_uart_driver, &owl_port->port);
	owl_uart_ports[pdev->id] = NULL;

	return 0;
}


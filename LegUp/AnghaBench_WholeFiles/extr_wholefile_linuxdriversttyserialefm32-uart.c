#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_8__ {int /*<<< orphan*/  overrun; int /*<<< orphan*/  frame; int /*<<< orphan*/  parity; int /*<<< orphan*/  brk; int /*<<< orphan*/  rx; int /*<<< orphan*/  tx; } ;
struct uart_port {unsigned int membase; int x_char; int read_status_mask; int ignore_status_mask; int uartclk; int irq; scalar_t__ type; int line; int fifosize; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; int /*<<< orphan*/  iotype; int /*<<< orphan*/  mapbase; TYPE_3__* dev; int /*<<< orphan*/  lock; TYPE_2__ icount; TYPE_1__* state; } ;
struct tty_port {int dummy; } ;
struct serial_struct {scalar_t__ type; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct platform_device {int id; TYPE_3__ dev; } ;
struct ktermios {int c_cflag; int c_iflag; } ;
struct efm32_uart_pdata {int location; } ;
struct efm32_uart_port {int txirq; struct uart_port port; struct efm32_uart_pdata pdata; int /*<<< orphan*/  clk; } ;
struct device_node {int dummy; } ;
struct circ_buf {int* buf; size_t tail; } ;
typedef  int irqreturn_t ;
struct TYPE_7__ {struct tty_port port; struct circ_buf xmit; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct efm32_uart_port**) ; 
 int BRKINT ; 
 int CMSPAR ; 
 int CRTSCTS ; 
#define  CS5 131 
#define  CS6 130 
#define  CS7 129 
#define  CS8 128 
 int CSIZE ; 
 int CSTOPB ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IGNBRK ; 
 int IGNPAR ; 
 int INPCK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int IRQ_HANDLED ; 
 int IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PARENB ; 
 int PARMRK ; 
 int PARODD ; 
 scalar_t__ PORT_EFMUART ; 
 scalar_t__ PORT_UNKNOWN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int SW_UARTn_RXDATAX_BERR ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 unsigned int TIOCSER_TEMT ; 
 int TTY_BREAK ; 
 int TTY_FRAME ; 
 int TTY_OVERRUN ; 
 int TTY_PARITY ; 
 int UART_CONFIG_TYPE ; 
 int UART_XMIT_SIZE ; 
 unsigned int UARTn_CLKDIV ; 
 unsigned int UARTn_CMD ; 
 int UARTn_CMD_RXDIS ; 
 int UARTn_CMD_RXEN ; 
 int UARTn_CMD_TXDIS ; 
 int UARTn_CMD_TXEN ; 
 unsigned int UARTn_CTRL ; 
 int UARTn_CTRL_TXBIL ; 
 unsigned int UARTn_FRAME ; 
 int UARTn_FRAME_DATABITS (int) ; 
 int UARTn_FRAME_PARITY_EVEN ; 
 int UARTn_FRAME_PARITY_NONE ; 
 int UARTn_FRAME_PARITY_ODD ; 
 int UARTn_FRAME_STOPBITS_ONE ; 
 int UARTn_FRAME_STOPBITS_TWO ; 
 unsigned int UARTn_IEN ; 
 unsigned int UARTn_IF ; 
 unsigned int UARTn_IFC ; 
 int UARTn_IF_RXDATAV ; 
 int UARTn_IF_RXOF ; 
 int UARTn_IF_TXBL ; 
 int UARTn_IF_TXC ; 
 unsigned int UARTn_ROUTE ; 
 int UARTn_ROUTE_LOCATION (int) ; 
 int UARTn_ROUTE_RXPEN ; 
 int UARTn_ROUTE_TXPEN ; 
 unsigned int UARTn_RXDATAX ; 
 int UARTn_RXDATAX_FERR ; 
 int UARTn_RXDATAX_PERR ; 
 int UARTn_RXDATAX_RXDATA__MASK ; 
 unsigned int UARTn_STATUS ; 
 int UARTn_STATUS_RXDATAV ; 
 int UARTn_STATUS_TXBL ; 
 int UARTn_STATUS_TXC ; 
 unsigned int UARTn_TXDATA ; 
 int /*<<< orphan*/  UPF_BOOT_AUTOCONF ; 
 int /*<<< orphan*/  UPIO_MEM32 ; 
 scalar_t__ WAKEUP_CHARS ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int clk_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_get (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int clk_get_rate (int /*<<< orphan*/ ) ; 
 int clk_prepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct efm32_uart_pdata* dev_get_platdata (TYPE_3__*) ; 
 int /*<<< orphan*/  efm32_uart_pops ; 
 struct efm32_uart_port** efm32_uart_ports ; 
 int /*<<< orphan*/  efm32_uart_reg ; 
 int /*<<< orphan*/  efm_debug (struct efm32_uart_port*,char*,...) ; 
 int /*<<< orphan*/  free_irq (int,struct efm32_uart_port*) ; 
 unsigned int ioremap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iounmap (unsigned int) ; 
 int /*<<< orphan*/  kfree (struct efm32_uart_port*) ; 
 struct efm32_uart_port* kzalloc (int,int /*<<< orphan*/ ) ; 
 int of_alias_get_id (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct efm32_uart_port* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct efm32_uart_port*) ; 
 int readl_relaxed (unsigned int) ; 
 int request_irq (int,int (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct efm32_uart_port*) ; 
 int resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct efm32_uart_port* to_efm_port (struct uart_port*) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (struct tty_port*) ; 
 int /*<<< orphan*/  tty_insert_flip_char (struct tty_port*,int,int) ; 
 int uart_add_one_port (int /*<<< orphan*/ *,struct uart_port*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int,int) ; 
 scalar_t__ uart_handle_break (struct uart_port*) ; 
 scalar_t__ uart_handle_sysrq_char (struct uart_port*,int) ; 
 int /*<<< orphan*/  uart_remove_one_port (int /*<<< orphan*/ *,struct uart_port*) ; 
 int /*<<< orphan*/  uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 int /*<<< orphan*/  writel_relaxed (int,unsigned int) ; 

__attribute__((used)) static void efm32_uart_write32(struct efm32_uart_port *efm_port,
		u32 value, unsigned offset)
{
	writel_relaxed(value, efm_port->port.membase + offset);
}

__attribute__((used)) static u32 efm32_uart_read32(struct efm32_uart_port *efm_port,
		unsigned offset)
{
	return readl_relaxed(efm_port->port.membase + offset);
}

__attribute__((used)) static unsigned int efm32_uart_tx_empty(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);
	u32 status = efm32_uart_read32(efm_port, UARTn_STATUS);

	if (status & UARTn_STATUS_TXC)
		return TIOCSER_TEMT;
	else
		return 0;
}

__attribute__((used)) static void efm32_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	/* sorry, neither handshaking lines nor loop functionallity */
}

__attribute__((used)) static unsigned int efm32_uart_get_mctrl(struct uart_port *port)
{
	/* sorry, no handshaking lines available */
	return TIOCM_CAR | TIOCM_CTS | TIOCM_DSR;
}

__attribute__((used)) static void efm32_uart_stop_tx(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);
	u32 ien = efm32_uart_read32(efm_port,  UARTn_IEN);

	efm32_uart_write32(efm_port, UARTn_CMD_TXDIS, UARTn_CMD);
	ien &= ~(UARTn_IF_TXC | UARTn_IF_TXBL);
	efm32_uart_write32(efm_port, ien, UARTn_IEN);
}

__attribute__((used)) static void efm32_uart_tx_chars(struct efm32_uart_port *efm_port)
{
	struct uart_port *port = &efm_port->port;
	struct circ_buf *xmit = &port->state->xmit;

	while (efm32_uart_read32(efm_port, UARTn_STATUS) &
			UARTn_STATUS_TXBL) {
		if (port->x_char) {
			port->icount.tx++;
			efm32_uart_write32(efm_port, port->x_char,
					UARTn_TXDATA);
			port->x_char = 0;
			continue;
		}
		if (!uart_circ_empty(xmit) && !uart_tx_stopped(port)) {
			port->icount.tx++;
			efm32_uart_write32(efm_port, xmit->buf[xmit->tail],
					UARTn_TXDATA);
			xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		} else
			break;
	}

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

	if (!port->x_char && uart_circ_empty(xmit) &&
			efm32_uart_read32(efm_port, UARTn_STATUS) &
				UARTn_STATUS_TXC)
		efm32_uart_stop_tx(port);
}

__attribute__((used)) static void efm32_uart_start_tx(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);
	u32 ien;

	efm32_uart_write32(efm_port,
			UARTn_IF_TXBL | UARTn_IF_TXC, UARTn_IFC);
	ien = efm32_uart_read32(efm_port, UARTn_IEN);
	efm32_uart_write32(efm_port,
			ien | UARTn_IF_TXBL | UARTn_IF_TXC, UARTn_IEN);
	efm32_uart_write32(efm_port, UARTn_CMD_TXEN, UARTn_CMD);

	efm32_uart_tx_chars(efm_port);
}

__attribute__((used)) static void efm32_uart_stop_rx(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);

	efm32_uart_write32(efm_port, UARTn_CMD_RXDIS, UARTn_CMD);
}

__attribute__((used)) static void efm32_uart_break_ctl(struct uart_port *port, int ctl)
{
	/* not possible without fiddling with gpios */
}

__attribute__((used)) static void efm32_uart_rx_chars(struct efm32_uart_port *efm_port)
{
	struct uart_port *port = &efm_port->port;

	while (efm32_uart_read32(efm_port, UARTn_STATUS) &
			UARTn_STATUS_RXDATAV) {
		u32 rxdata = efm32_uart_read32(efm_port, UARTn_RXDATAX);
		int flag = 0;

		/*
		 * This is a reserved bit and I only saw it read as 0. But to be
		 * sure not to be confused too much by new devices adhere to the
		 * warning in the reference manual that reserverd bits might
		 * read as 1 in the future.
		 */
		rxdata &= ~SW_UARTn_RXDATAX_BERR;

		port->icount.rx++;

		if ((rxdata & UARTn_RXDATAX_FERR) &&
				!(rxdata & UARTn_RXDATAX_RXDATA__MASK)) {
			rxdata |= SW_UARTn_RXDATAX_BERR;
			port->icount.brk++;
			if (uart_handle_break(port))
				continue;
		} else if (rxdata & UARTn_RXDATAX_PERR)
			port->icount.parity++;
		else if (rxdata & UARTn_RXDATAX_FERR)
			port->icount.frame++;

		rxdata &= port->read_status_mask;

		if (rxdata & SW_UARTn_RXDATAX_BERR)
			flag = TTY_BREAK;
		else if (rxdata & UARTn_RXDATAX_PERR)
			flag = TTY_PARITY;
		else if (rxdata & UARTn_RXDATAX_FERR)
			flag = TTY_FRAME;
		else if (uart_handle_sysrq_char(port,
					rxdata & UARTn_RXDATAX_RXDATA__MASK))
			continue;

		if ((rxdata & port->ignore_status_mask) == 0)
			tty_insert_flip_char(&port->state->port,
					rxdata & UARTn_RXDATAX_RXDATA__MASK, flag);
	}
}

__attribute__((used)) static irqreturn_t efm32_uart_rxirq(int irq, void *data)
{
	struct efm32_uart_port *efm_port = data;
	u32 irqflag = efm32_uart_read32(efm_port, UARTn_IF);
	int handled = IRQ_NONE;
	struct uart_port *port = &efm_port->port;
	struct tty_port *tport = &port->state->port;

	spin_lock(&port->lock);

	if (irqflag & UARTn_IF_RXDATAV) {
		efm32_uart_write32(efm_port, UARTn_IF_RXDATAV, UARTn_IFC);
		efm32_uart_rx_chars(efm_port);

		handled = IRQ_HANDLED;
	}

	if (irqflag & UARTn_IF_RXOF) {
		efm32_uart_write32(efm_port, UARTn_IF_RXOF, UARTn_IFC);
		port->icount.overrun++;
		tty_insert_flip_char(tport, 0, TTY_OVERRUN);

		handled = IRQ_HANDLED;
	}

	spin_unlock(&port->lock);

	tty_flip_buffer_push(tport);

	return handled;
}

__attribute__((used)) static irqreturn_t efm32_uart_txirq(int irq, void *data)
{
	struct efm32_uart_port *efm_port = data;
	u32 irqflag = efm32_uart_read32(efm_port, UARTn_IF);

	/* TXBL doesn't need to be cleared */
	if (irqflag & UARTn_IF_TXC)
		efm32_uart_write32(efm_port, UARTn_IF_TXC, UARTn_IFC);

	if (irqflag & (UARTn_IF_TXC | UARTn_IF_TXBL)) {
		efm32_uart_tx_chars(efm_port);
		return IRQ_HANDLED;
	} else
		return IRQ_NONE;
}

__attribute__((used)) static int efm32_uart_startup(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);
	int ret;

	ret = clk_enable(efm_port->clk);
	if (ret) {
		efm_debug(efm_port, "failed to enable clk\n");
		goto err_clk_enable;
	}
	port->uartclk = clk_get_rate(efm_port->clk);

	/* Enable pins at configured location */
	efm32_uart_write32(efm_port,
			UARTn_ROUTE_LOCATION(efm_port->pdata.location) |
			UARTn_ROUTE_RXPEN | UARTn_ROUTE_TXPEN,
			UARTn_ROUTE);

	ret = request_irq(port->irq, efm32_uart_rxirq, 0,
			DRIVER_NAME, efm_port);
	if (ret) {
		efm_debug(efm_port, "failed to register rxirq\n");
		goto err_request_irq_rx;
	}

	/* disable all irqs */
	efm32_uart_write32(efm_port, 0, UARTn_IEN);

	ret = request_irq(efm_port->txirq, efm32_uart_txirq, 0,
			DRIVER_NAME, efm_port);
	if (ret) {
		efm_debug(efm_port, "failed to register txirq\n");
		free_irq(port->irq, efm_port);
err_request_irq_rx:

		clk_disable(efm_port->clk);
	} else {
		efm32_uart_write32(efm_port,
				UARTn_IF_RXDATAV | UARTn_IF_RXOF, UARTn_IEN);
		efm32_uart_write32(efm_port, UARTn_CMD_RXEN, UARTn_CMD);
	}

err_clk_enable:
	return ret;
}

__attribute__((used)) static void efm32_uart_shutdown(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);

	efm32_uart_write32(efm_port, 0, UARTn_IEN);
	free_irq(port->irq, efm_port);

	clk_disable(efm_port->clk);
}

__attribute__((used)) static void efm32_uart_set_termios(struct uart_port *port,
		struct ktermios *new, struct ktermios *old)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);
	unsigned long flags;
	unsigned baud;
	u32 clkdiv;
	u32 frame = 0;

	/* no modem control lines */
	new->c_cflag &= ~(CRTSCTS | CMSPAR);

	baud = uart_get_baud_rate(port, new, old,
			DIV_ROUND_CLOSEST(port->uartclk, 16 * 8192),
			DIV_ROUND_CLOSEST(port->uartclk, 16));

	switch (new->c_cflag & CSIZE) {
	case CS5:
		frame |= UARTn_FRAME_DATABITS(5);
		break;
	case CS6:
		frame |= UARTn_FRAME_DATABITS(6);
		break;
	case CS7:
		frame |= UARTn_FRAME_DATABITS(7);
		break;
	case CS8:
		frame |= UARTn_FRAME_DATABITS(8);
		break;
	}

	if (new->c_cflag & CSTOPB)
		/* the receiver only verifies the first stop bit */
		frame |= UARTn_FRAME_STOPBITS_TWO;
	else
		frame |= UARTn_FRAME_STOPBITS_ONE;

	if (new->c_cflag & PARENB) {
		if (new->c_cflag & PARODD)
			frame |= UARTn_FRAME_PARITY_ODD;
		else
			frame |= UARTn_FRAME_PARITY_EVEN;
	} else
		frame |= UARTn_FRAME_PARITY_NONE;

	/*
	 * the 6 lowest bits of CLKDIV are dc, bit 6 has value 0.25.
	 * port->uartclk <= 14e6, so 4 * port->uartclk doesn't overflow.
	 */
	clkdiv = (DIV_ROUND_CLOSEST(4 * port->uartclk, 16 * baud) - 4) << 6;

	spin_lock_irqsave(&port->lock, flags);

	efm32_uart_write32(efm_port,
			UARTn_CMD_TXDIS | UARTn_CMD_RXDIS, UARTn_CMD);

	port->read_status_mask = UARTn_RXDATAX_RXDATA__MASK;
	if (new->c_iflag & INPCK)
		port->read_status_mask |=
			UARTn_RXDATAX_FERR | UARTn_RXDATAX_PERR;
	if (new->c_iflag & (IGNBRK | BRKINT | PARMRK))
		port->read_status_mask |= SW_UARTn_RXDATAX_BERR;

	port->ignore_status_mask = 0;
	if (new->c_iflag & IGNPAR)
		port->ignore_status_mask |=
			UARTn_RXDATAX_FERR | UARTn_RXDATAX_PERR;
	if (new->c_iflag & IGNBRK)
		port->ignore_status_mask |= SW_UARTn_RXDATAX_BERR;

	uart_update_timeout(port, new->c_cflag, baud);

	efm32_uart_write32(efm_port, UARTn_CTRL_TXBIL, UARTn_CTRL);
	efm32_uart_write32(efm_port, frame, UARTn_FRAME);
	efm32_uart_write32(efm_port, clkdiv, UARTn_CLKDIV);

	efm32_uart_write32(efm_port, UARTn_CMD_TXEN | UARTn_CMD_RXEN,
			UARTn_CMD);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static const char *efm32_uart_type(struct uart_port *port)
{
	return port->type == PORT_EFMUART ? "efm32-uart" : NULL;
}

__attribute__((used)) static void efm32_uart_release_port(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);

	clk_unprepare(efm_port->clk);
	clk_put(efm_port->clk);
	iounmap(port->membase);
}

__attribute__((used)) static int efm32_uart_request_port(struct uart_port *port)
{
	struct efm32_uart_port *efm_port = to_efm_port(port);
	int ret;

	port->membase = ioremap(port->mapbase, 60);
	if (!efm_port->port.membase) {
		ret = -ENOMEM;
		efm_debug(efm_port, "failed to remap\n");
		goto err_ioremap;
	}

	efm_port->clk = clk_get(port->dev, NULL);
	if (IS_ERR(efm_port->clk)) {
		ret = PTR_ERR(efm_port->clk);
		efm_debug(efm_port, "failed to get clock\n");
		goto err_clk_get;
	}

	ret = clk_prepare(efm_port->clk);
	if (ret) {
		clk_put(efm_port->clk);
err_clk_get:

		iounmap(port->membase);
err_ioremap:
		return ret;
	}
	return 0;
}

__attribute__((used)) static void efm32_uart_config_port(struct uart_port *port, int type)
{
	if (type & UART_CONFIG_TYPE &&
			!efm32_uart_request_port(port))
		port->type = PORT_EFMUART;
}

__attribute__((used)) static int efm32_uart_verify_port(struct uart_port *port,
		struct serial_struct *serinfo)
{
	int ret = 0;

	if (serinfo->type != PORT_UNKNOWN && serinfo->type != PORT_EFMUART)
		ret = -EINVAL;

	return ret;
}

__attribute__((used)) static int efm32_uart_probe_dt(struct platform_device *pdev,
		struct efm32_uart_port *efm_port)
{
	struct device_node *np = pdev->dev.of_node;
	u32 location;
	int ret;

	if (!np)
		return 1;

	ret = of_property_read_u32(np, "energymicro,location", &location);

	if (ret)
		/* fall back to wrongly namespaced property */
		ret = of_property_read_u32(np, "efm32,location", &location);

	if (ret)
		/* fall back to old and (wrongly) generic property "location" */
		ret = of_property_read_u32(np, "location", &location);

	if (!ret) {
		if (location > 5) {
			dev_err(&pdev->dev, "invalid location\n");
			return -EINVAL;
		}
		efm_debug(efm_port, "using location %u\n", location);
		efm_port->pdata.location = location;
	} else {
		efm_debug(efm_port, "fall back to location 0\n");
	}

	ret = of_alias_get_id(np, "serial");
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to get alias id: %d\n", ret);
		return ret;
	} else {
		efm_port->port.line = ret;
		return 0;
	}

}

__attribute__((used)) static int efm32_uart_probe(struct platform_device *pdev)
{
	struct efm32_uart_port *efm_port;
	struct resource *res;
	unsigned int line;
	int ret;

	efm_port = kzalloc(sizeof(*efm_port), GFP_KERNEL);
	if (!efm_port) {
		dev_dbg(&pdev->dev, "failed to allocate private data\n");
		return -ENOMEM;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		ret = -ENODEV;
		dev_dbg(&pdev->dev, "failed to determine base address\n");
		goto err_get_base;
	}

	if (resource_size(res) < 60) {
		ret = -EINVAL;
		dev_dbg(&pdev->dev, "memory resource too small\n");
		goto err_too_small;
	}

	ret = platform_get_irq(pdev, 0);
	if (ret <= 0) {
		dev_dbg(&pdev->dev, "failed to get rx irq\n");
		goto err_get_rxirq;
	}

	efm_port->port.irq = ret;

	ret = platform_get_irq(pdev, 1);
	if (ret <= 0)
		ret = efm_port->port.irq + 1;

	efm_port->txirq = ret;

	efm_port->port.dev = &pdev->dev;
	efm_port->port.mapbase = res->start;
	efm_port->port.type = PORT_EFMUART;
	efm_port->port.iotype = UPIO_MEM32;
	efm_port->port.fifosize = 2;
	efm_port->port.ops = &efm32_uart_pops;
	efm_port->port.flags = UPF_BOOT_AUTOCONF;

	ret = efm32_uart_probe_dt(pdev, efm_port);
	if (ret > 0) {
		/* not created by device tree */
		const struct efm32_uart_pdata *pdata = dev_get_platdata(&pdev->dev);

		efm_port->port.line = pdev->id;

		if (pdata)
			efm_port->pdata = *pdata;
	} else if (ret < 0)
		goto err_probe_dt;

	line = efm_port->port.line;

	if (line >= 0 && line < ARRAY_SIZE(efm32_uart_ports))
		efm32_uart_ports[line] = efm_port;

	ret = uart_add_one_port(&efm32_uart_reg, &efm_port->port);
	if (ret) {
		dev_dbg(&pdev->dev, "failed to add port: %d\n", ret);

		if (line >= 0 && line < ARRAY_SIZE(efm32_uart_ports))
			efm32_uart_ports[line] = NULL;
err_probe_dt:
err_get_rxirq:
err_too_small:
err_get_base:
		kfree(efm_port);
	} else {
		platform_set_drvdata(pdev, efm_port);
		dev_dbg(&pdev->dev, "\\o/\n");
	}

	return ret;
}

__attribute__((used)) static int efm32_uart_remove(struct platform_device *pdev)
{
	struct efm32_uart_port *efm_port = platform_get_drvdata(pdev);
	unsigned int line = efm_port->port.line;

	uart_remove_one_port(&efm32_uart_reg, &efm_port->port);

	if (line >= 0 && line < ARRAY_SIZE(efm32_uart_ports))
		efm32_uart_ports[line] = NULL;

	kfree(efm_port);

	return 0;
}


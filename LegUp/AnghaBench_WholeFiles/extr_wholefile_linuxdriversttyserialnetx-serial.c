#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  overrun; int /*<<< orphan*/  frame; int /*<<< orphan*/  parity; int /*<<< orphan*/  rx; int /*<<< orphan*/  tx; } ;
struct uart_port {int x_char; unsigned char read_status_mask; int uartclk; unsigned char ignore_status_mask; scalar_t__ type; scalar_t__ membase; int /*<<< orphan*/ * dev; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  lock; int /*<<< orphan*/  irq; TYPE_2__* state; TYPE_1__ icount; } ;
struct serial_struct {scalar_t__ type; } ;
struct platform_device {size_t id; int /*<<< orphan*/  dev; } ;
struct netx_port {int /*<<< orphan*/  port; } ;
struct ktermios {int c_cflag; int c_iflag; } ;
struct circ_buf {int* buf; size_t tail; } ;
typedef  int /*<<< orphan*/  pm_message_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {struct uart_port port; } ;
struct TYPE_6__ {int /*<<< orphan*/  port; struct circ_buf xmit; } ;

/* Variables and functions */
 int BRKINT ; 
 int CRTSCTS ; 
 unsigned int CR_MSIE ; 
 unsigned int CR_RIE ; 
 unsigned int CR_RTIE ; 
 unsigned int CR_TIE ; 
 unsigned int CR_UART_EN ; 
#define  CS5 131 
#define  CS6 130 
#define  CS7 129 
#define  CS8 128 
 int CSIZE ; 
 int CSTOPB ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EBUSY ; 
 int EINVAL ; 
 int FR_BUSY ; 
 int FR_CTS ; 
 int FR_RXFE ; 
 int FR_TXFF ; 
 int IGNBRK ; 
 int IGNPAR ; 
 int IIR_MASK ; 
 unsigned char IIR_MIS ; 
 unsigned char IIR_RIS ; 
 unsigned char IIR_TIS ; 
 int INPCK ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned char LINE_CR_5BIT ; 
 unsigned char LINE_CR_6BIT ; 
 unsigned char LINE_CR_7BIT ; 
 unsigned char LINE_CR_8BIT ; 
 unsigned int LINE_CR_BRK ; 
 unsigned char LINE_CR_EPS ; 
 int LINE_CR_FEN ; 
 unsigned char LINE_CR_PEN ; 
 unsigned char LINE_CR_STP2 ; 
 int PARENB ; 
 int PARMRK ; 
 int PARODD ; 
 scalar_t__ PORT_NETX ; 
 scalar_t__ PORT_UNKNOWN ; 
 unsigned char RTS_CR_AUTO ; 
 unsigned char RTS_CR_CTS_CTR ; 
 unsigned int RTS_CR_RTS ; 
 unsigned char RTS_CR_RTS_POL ; 
 unsigned char SR_BE ; 
 unsigned char SR_FE ; 
 unsigned char SR_OE ; 
 unsigned char SR_PE ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 unsigned int TIOCM_RTS ; 
 unsigned int TIOCSER_TEMT ; 
 unsigned char TTY_BREAK ; 
 unsigned char TTY_FRAME ; 
 unsigned char TTY_NORMAL ; 
 unsigned char TTY_PARITY ; 
 scalar_t__ UART_BAUDDIV_LSB ; 
 scalar_t__ UART_BAUDDIV_MSB ; 
 int UART_CONFIG_TYPE ; 
 scalar_t__ UART_CR ; 
 scalar_t__ UART_DR ; 
 scalar_t__ UART_ENABLE_MS (struct uart_port*,int) ; 
 scalar_t__ UART_FR ; 
 scalar_t__ UART_IIR ; 
 scalar_t__ UART_LINE_CR ; 
 int /*<<< orphan*/  UART_PORT_SIZE ; 
 scalar_t__ UART_RTS_CR ; 
 scalar_t__ UART_RXFIFO_IRQLEVEL ; 
 scalar_t__ UART_SR ; 
 int UART_XMIT_SIZE ; 
 scalar_t__ WAKEUP_CHARS ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct uart_port*) ; 
 TYPE_3__* netx_ports ; 
 int /*<<< orphan*/  netx_reg ; 
 struct netx_port* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,TYPE_3__*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  release_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct uart_port*) ; 
 int /*<<< orphan*/ * request_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uart_add_one_port (int /*<<< orphan*/ *,struct uart_port*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ uart_handle_break (struct uart_port*) ; 
 int /*<<< orphan*/  uart_handle_cts_change (struct uart_port*,int) ; 
 scalar_t__ uart_handle_sysrq_char (struct uart_port*,unsigned char) ; 
 int /*<<< orphan*/  uart_insert_char (struct uart_port*,unsigned char,unsigned char,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  uart_remove_one_port (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uart_resume_port (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uart_suspend_port (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 scalar_t__ unlikely (unsigned char) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void netx_stop_tx(struct uart_port *port)
{
	unsigned int val;
	val = readl(port->membase + UART_CR);
	writel(val & ~CR_TIE,  port->membase + UART_CR);
}

__attribute__((used)) static void netx_stop_rx(struct uart_port *port)
{
	unsigned int val;
	val = readl(port->membase + UART_CR);
	writel(val & ~CR_RIE,  port->membase + UART_CR);
}

__attribute__((used)) static void netx_enable_ms(struct uart_port *port)
{
	unsigned int val;
	val = readl(port->membase + UART_CR);
	writel(val | CR_MSIE, port->membase + UART_CR);
}

__attribute__((used)) static inline void netx_transmit_buffer(struct uart_port *port)
{
	struct circ_buf *xmit = &port->state->xmit;

	if (port->x_char) {
		writel(port->x_char, port->membase + UART_DR);
		port->icount.tx++;
		port->x_char = 0;
		return;
	}

	if (uart_tx_stopped(port) || uart_circ_empty(xmit)) {
		netx_stop_tx(port);
		return;
	}

	do {
		/* send xmit->buf[xmit->tail]
		 * out the port here */
		writel(xmit->buf[xmit->tail], port->membase + UART_DR);
		xmit->tail = (xmit->tail + 1) &
		         (UART_XMIT_SIZE - 1);
		port->icount.tx++;
		if (uart_circ_empty(xmit))
			break;
	} while (!(readl(port->membase + UART_FR) & FR_TXFF));

	if (uart_circ_empty(xmit))
		netx_stop_tx(port);
}

__attribute__((used)) static void netx_start_tx(struct uart_port *port)
{
	writel(
	    readl(port->membase + UART_CR) | CR_TIE, port->membase + UART_CR);

	if (!(readl(port->membase + UART_FR) & FR_TXFF))
		netx_transmit_buffer(port);
}

__attribute__((used)) static unsigned int netx_tx_empty(struct uart_port *port)
{
	return readl(port->membase + UART_FR) & FR_BUSY ? 0 : TIOCSER_TEMT;
}

__attribute__((used)) static void netx_txint(struct uart_port *port)
{
	struct circ_buf *xmit = &port->state->xmit;

	if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
		netx_stop_tx(port);
		return;
	}

	netx_transmit_buffer(port);

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);
}

__attribute__((used)) static void netx_rxint(struct uart_port *port, unsigned long *flags)
{
	unsigned char rx, flg, status;

	while (!(readl(port->membase + UART_FR) & FR_RXFE)) {
		rx = readl(port->membase + UART_DR);
		flg = TTY_NORMAL;
		port->icount.rx++;
		status = readl(port->membase + UART_SR);
		if (status & SR_BE) {
			writel(0, port->membase + UART_SR);
			if (uart_handle_break(port))
				continue;
		}

		if (unlikely(status & (SR_FE | SR_PE | SR_OE))) {

			if (status & SR_PE)
				port->icount.parity++;
			else if (status & SR_FE)
				port->icount.frame++;
			if (status & SR_OE)
				port->icount.overrun++;

			status &= port->read_status_mask;

			if (status & SR_BE)
				flg = TTY_BREAK;
			else if (status & SR_PE)
				flg = TTY_PARITY;
			else if (status & SR_FE)
				flg = TTY_FRAME;
		}

		if (uart_handle_sysrq_char(port, rx))
			continue;

		uart_insert_char(port, status, SR_OE, rx, flg);
	}

	spin_unlock_irqrestore(&port->lock, *flags);
	tty_flip_buffer_push(&port->state->port);
	spin_lock_irqsave(&port->lock, *flags);
}

__attribute__((used)) static irqreturn_t netx_int(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	unsigned long flags;
	unsigned char status;

	spin_lock_irqsave(&port->lock,flags);

	status = readl(port->membase + UART_IIR) & IIR_MASK;
	while (status) {
		if (status & IIR_RIS)
			netx_rxint(port, &flags);
		if (status & IIR_TIS)
			netx_txint(port);
		if (status & IIR_MIS) {
			if (readl(port->membase + UART_FR) & FR_CTS)
				uart_handle_cts_change(port, 1);
			else
				uart_handle_cts_change(port, 0);
		}
		writel(0, port->membase + UART_IIR);
		status = readl(port->membase + UART_IIR) & IIR_MASK;
	}

	spin_unlock_irqrestore(&port->lock,flags);
	return IRQ_HANDLED;
}

__attribute__((used)) static unsigned int netx_get_mctrl(struct uart_port *port)
{
	unsigned int ret = TIOCM_DSR | TIOCM_CAR;

	if (readl(port->membase + UART_FR) & FR_CTS)
		ret |= TIOCM_CTS;

	return ret;
}

__attribute__((used)) static void netx_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	unsigned int val;

	/* FIXME: Locking needed ? */
	if (mctrl & TIOCM_RTS) {
		val = readl(port->membase + UART_RTS_CR);
		writel(val | RTS_CR_RTS, port->membase + UART_RTS_CR);
	}
}

__attribute__((used)) static void netx_break_ctl(struct uart_port *port, int break_state)
{
	unsigned int line_cr;
	spin_lock_irq(&port->lock);

	line_cr = readl(port->membase + UART_LINE_CR);
	if (break_state != 0)
		line_cr |= LINE_CR_BRK;
	else
		line_cr &= ~LINE_CR_BRK;
	writel(line_cr, port->membase + UART_LINE_CR);

	spin_unlock_irq(&port->lock);
}

__attribute__((used)) static int netx_startup(struct uart_port *port)
{
	int ret;

	ret = request_irq(port->irq, netx_int, 0,
			     DRIVER_NAME, port);
	if (ret) {
		dev_err(port->dev, "unable to grab irq%d\n",port->irq);
		goto exit;
	}

	writel(readl(port->membase + UART_LINE_CR) | LINE_CR_FEN,
		port->membase + UART_LINE_CR);

	writel(CR_MSIE | CR_RIE | CR_TIE | CR_RTIE | CR_UART_EN,
		port->membase + UART_CR);

exit:
	return ret;
}

__attribute__((used)) static void netx_shutdown(struct uart_port *port)
{
	writel(0, port->membase + UART_CR) ;

	free_irq(port->irq, port);
}

__attribute__((used)) static void
netx_set_termios(struct uart_port *port, struct ktermios *termios,
		   struct ktermios *old)
{
	unsigned int baud, quot;
	unsigned char old_cr;
	unsigned char line_cr = LINE_CR_FEN;
	unsigned char rts_cr = 0;

	switch (termios->c_cflag & CSIZE) {
	case CS5:
		line_cr |= LINE_CR_5BIT;
		break;
	case CS6:
		line_cr |= LINE_CR_6BIT;
		break;
	case CS7:
		line_cr |= LINE_CR_7BIT;
		break;
	case CS8:
		line_cr |= LINE_CR_8BIT;
		break;
	}

	if (termios->c_cflag & CSTOPB)
		line_cr |= LINE_CR_STP2;

	if (termios->c_cflag & PARENB) {
		line_cr |= LINE_CR_PEN;
		if (!(termios->c_cflag & PARODD))
			line_cr |= LINE_CR_EPS;
	}

	if (termios->c_cflag & CRTSCTS)
		rts_cr = RTS_CR_AUTO | RTS_CR_CTS_CTR | RTS_CR_RTS_POL;

	baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
	quot = baud * 4096;
	quot /= 1000;
	quot *= 256;
	quot /= 100000;

	spin_lock_irq(&port->lock);

	uart_update_timeout(port, termios->c_cflag, baud);

	old_cr = readl(port->membase + UART_CR);

	/* disable interrupts */
	writel(old_cr & ~(CR_MSIE | CR_RIE | CR_TIE | CR_RTIE),
		port->membase + UART_CR);

	/* drain transmitter */
	while (readl(port->membase + UART_FR) & FR_BUSY);

	/* disable UART */
	writel(old_cr & ~CR_UART_EN, port->membase + UART_CR);

	/* modem status interrupts */
	old_cr &= ~CR_MSIE;
	if (UART_ENABLE_MS(port, termios->c_cflag))
		old_cr |= CR_MSIE;

	writel((quot>>8) & 0xff, port->membase + UART_BAUDDIV_MSB);
	writel(quot & 0xff, port->membase + UART_BAUDDIV_LSB);
	writel(line_cr, port->membase + UART_LINE_CR);

	writel(rts_cr, port->membase + UART_RTS_CR);

	/*
	 * Characters to ignore
	 */
	port->ignore_status_mask = 0;
	if (termios->c_iflag & IGNPAR)
		port->ignore_status_mask |= SR_PE;
	if (termios->c_iflag & IGNBRK) {
		port->ignore_status_mask |= SR_BE;
		/*
		 * If we're ignoring parity and break indicators,
		 * ignore overruns too (for real raw support).
		 */
		if (termios->c_iflag & IGNPAR)
			port->ignore_status_mask |= SR_PE;
	}

	port->read_status_mask = 0;
	if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
		port->read_status_mask |= SR_BE;
	if (termios->c_iflag & INPCK)
		port->read_status_mask |= SR_PE | SR_FE;

	writel(old_cr, port->membase + UART_CR);

	spin_unlock_irq(&port->lock);
}

__attribute__((used)) static const char *netx_type(struct uart_port *port)
{
	return port->type == PORT_NETX ? "NETX" : NULL;
}

__attribute__((used)) static void netx_release_port(struct uart_port *port)
{
	release_mem_region(port->mapbase, UART_PORT_SIZE);
}

__attribute__((used)) static int netx_request_port(struct uart_port *port)
{
	return request_mem_region(port->mapbase, UART_PORT_SIZE,
			DRIVER_NAME) != NULL ? 0 : -EBUSY;
}

__attribute__((used)) static void netx_config_port(struct uart_port *port, int flags)
{
	if (flags & UART_CONFIG_TYPE && netx_request_port(port) == 0)
		port->type = PORT_NETX;
}

__attribute__((used)) static int
netx_verify_port(struct uart_port *port, struct serial_struct *ser)
{
	int ret = 0;

	if (ser->type != PORT_UNKNOWN && ser->type != PORT_NETX)
		ret = -EINVAL;

	return ret;
}

__attribute__((used)) static int serial_netx_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct netx_port *sport = platform_get_drvdata(pdev);

	if (sport)
		uart_suspend_port(&netx_reg, &sport->port);

	return 0;
}

__attribute__((used)) static int serial_netx_resume(struct platform_device *pdev)
{
	struct netx_port *sport = platform_get_drvdata(pdev);

	if (sport)
		uart_resume_port(&netx_reg, &sport->port);

	return 0;
}

__attribute__((used)) static int serial_netx_probe(struct platform_device *pdev)
{
	struct uart_port *port = &netx_ports[pdev->id].port;

	dev_info(&pdev->dev, "initialising\n");

	port->dev = &pdev->dev;

	writel(1, port->membase + UART_RXFIFO_IRQLEVEL);
	uart_add_one_port(&netx_reg, &netx_ports[pdev->id].port);
	platform_set_drvdata(pdev, &netx_ports[pdev->id]);

	return 0;
}

__attribute__((used)) static int serial_netx_remove(struct platform_device *pdev)
{
	struct netx_port *sport = platform_get_drvdata(pdev);

	if (sport)
		uart_remove_one_port(&netx_reg, &sport->port);

	return 0;
}


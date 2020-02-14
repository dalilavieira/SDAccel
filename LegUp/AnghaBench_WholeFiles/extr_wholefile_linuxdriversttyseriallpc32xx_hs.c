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
typedef  int u32 ;
struct TYPE_6__ {int /*<<< orphan*/  overrun; int /*<<< orphan*/  brk; int /*<<< orphan*/  tx; int /*<<< orphan*/  frame; int /*<<< orphan*/  rx; } ;
struct uart_port {int mapbase; int uartclk; scalar_t__ iotype; int flags; int fifosize; int /*<<< orphan*/ * membase; scalar_t__ type; int /*<<< orphan*/  lock; int /*<<< orphan*/  irq; TYPE_2__ icount; TYPE_1__* state; scalar_t__ x_char; } ;
struct tty_port {int dummy; } ;
struct serial_struct {scalar_t__ type; } ;
struct resource {int start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {int mapbase; int irq; int regshift; int flags; int /*<<< orphan*/  lock; int /*<<< orphan*/  line; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * dev; int /*<<< orphan*/  uartclk; scalar_t__ iotype; int /*<<< orphan*/ * membase; } ;
struct lpc32xx_hsuart_port {TYPE_3__ port; } ;
struct ktermios {int c_cflag; } ;
struct circ_buf {size_t tail; scalar_t__* buf; } ;
typedef  int resource_size_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {struct tty_port port; struct circ_buf xmit; } ;

/* Variables and functions */
 int CLOCAL ; 
 int CMSPAR ; 
 int CREAD ; 
 int CRTSCTS ; 
 int CS8 ; 
 int CSIZE ; 
 int CSTOPB ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  FIFO_READ_LIMIT ; 
 int HUPCL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  LPC32XX_HSUART_CTRL (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LPC32XX_HSUART_FIFO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LPC32XX_HSUART_IIR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LPC32XX_HSUART_LEVEL (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LPC32XX_HSUART_RATE (int /*<<< orphan*/ *) ; 
 int LPC32XX_HSU_BREAK ; 
 int LPC32XX_HSU_BRK_INT ; 
 unsigned int LPC32XX_HSU_ERROR_DATA ; 
 int LPC32XX_HSU_ERR_INT_EN ; 
 int LPC32XX_HSU_FE_INT ; 
 int LPC32XX_HSU_OFFSET (int) ; 
 unsigned int LPC32XX_HSU_RX_EMPTY ; 
 int LPC32XX_HSU_RX_INT_EN ; 
 int LPC32XX_HSU_RX_OE_INT ; 
 int LPC32XX_HSU_RX_TIMEOUT_INT ; 
 int LPC32XX_HSU_RX_TL32B ; 
 int LPC32XX_HSU_RX_TRIG_INT ; 
 int LPC32XX_HSU_TMO_INACT_4B ; 
 int LPC32XX_HSU_TX_INT ; 
 unsigned int LPC32XX_HSU_TX_INT_EN ; 
 scalar_t__ LPC32XX_HSU_TX_LEV (scalar_t__) ; 
 int LPC32XX_HSU_TX_TL8B ; 
#define  LPC32XX_HS_UART1_BASE 130 
#define  LPC32XX_HS_UART2_BASE 129 
#define  LPC32XX_HS_UART7_BASE 128 
 int /*<<< orphan*/  LPC32XX_MAIN_OSC_FREQ ; 
 int /*<<< orphan*/  LPC32XX_UARTCTL_CLOOP ; 
 size_t MAX_PORTS ; 
 char const* MODNAME ; 
 int PARENB ; 
 int PARODD ; 
 scalar_t__ PORT_UART00 ; 
 int /*<<< orphan*/  SZ_4K ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 unsigned int TIOCSER_TEMT ; 
 unsigned int TTY_FRAME ; 
 unsigned int TTY_NORMAL ; 
 unsigned int TTY_OVERRUN ; 
 int UART_XMIT_SIZE ; 
 int UPF_BOOT_AUTOCONF ; 
 int UPF_FIXED_PORT ; 
 int UPF_IOREMAP ; 
 scalar_t__ UPIO_MEM32 ; 
 scalar_t__ WAKEUP_CHARS ; 
 int /*<<< orphan*/  WARN (int,char*,int) ; 
 int abs (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,size_t) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct uart_port*) ; 
 int /*<<< orphan*/ * ioremap (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 struct lpc32xx_hsuart_port* lpc32xx_hs_ports ; 
 int /*<<< orphan*/  lpc32xx_hs_reg ; 
 int /*<<< orphan*/  memset (struct lpc32xx_hsuart_port*,int /*<<< orphan*/ ,int) ; 
 struct lpc32xx_hsuart_port* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lpc32xx_hsuart_port*) ; 
 scalar_t__ readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_mem_region (int,int /*<<< orphan*/ ) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char const*,struct uart_port*) ; 
 int /*<<< orphan*/  request_mem_region (int,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  serial_lpc32xx_pops ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (struct tty_port*) ; 
 int /*<<< orphan*/  tty_insert_flip_char (struct tty_port*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  tty_schedule_flip (struct tty_port*) ; 
 scalar_t__ tty_termios_baud_rate (struct ktermios*) ; 
 int /*<<< orphan*/  tty_termios_encode_baud_rate (struct ktermios*,unsigned int,unsigned int) ; 
 int uart_add_one_port (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uart_handle_break (struct uart_port*) ; 
 int /*<<< orphan*/  uart_remove_one_port (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 size_t uarts_registered ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int __serial_get_clock_div(unsigned long uartclk,
					   unsigned long rate)
{
	u32 div, goodrate, hsu_rate, l_hsu_rate, comprate;
	u32 rate_diff;

	/* Find the closest divider to get the desired clock rate */
	div = uartclk / rate;
	goodrate = hsu_rate = (div / 14) - 1;
	if (hsu_rate != 0)
		hsu_rate--;

	/* Tweak divider */
	l_hsu_rate = hsu_rate + 3;
	rate_diff = 0xFFFFFFFF;

	while (hsu_rate < l_hsu_rate) {
		comprate = uartclk / ((hsu_rate + 1) * 14);
		if (abs(comprate - rate) < rate_diff) {
			goodrate = hsu_rate;
			rate_diff = abs(comprate - rate);
		}

		hsu_rate++;
	}
	if (hsu_rate > 0xFF)
		hsu_rate = 0xFF;

	return goodrate;
}

__attribute__((used)) static void __serial_uart_flush(struct uart_port *port)
{
	u32 tmp;
	int cnt = 0;

	while ((readl(LPC32XX_HSUART_LEVEL(port->membase)) > 0) &&
	       (cnt++ < FIFO_READ_LIMIT))
		tmp = readl(LPC32XX_HSUART_FIFO(port->membase));
}

__attribute__((used)) static void __serial_lpc32xx_rx(struct uart_port *port)
{
	struct tty_port *tport = &port->state->port;
	unsigned int tmp, flag;

	/* Read data from FIFO and push into terminal */
	tmp = readl(LPC32XX_HSUART_FIFO(port->membase));
	while (!(tmp & LPC32XX_HSU_RX_EMPTY)) {
		flag = TTY_NORMAL;
		port->icount.rx++;

		if (tmp & LPC32XX_HSU_ERROR_DATA) {
			/* Framing error */
			writel(LPC32XX_HSU_FE_INT,
			       LPC32XX_HSUART_IIR(port->membase));
			port->icount.frame++;
			flag = TTY_FRAME;
			tty_insert_flip_char(tport, 0, TTY_FRAME);
		}

		tty_insert_flip_char(tport, (tmp & 0xFF), flag);

		tmp = readl(LPC32XX_HSUART_FIFO(port->membase));
	}

	spin_unlock(&port->lock);
	tty_flip_buffer_push(tport);
	spin_lock(&port->lock);
}

__attribute__((used)) static void __serial_lpc32xx_tx(struct uart_port *port)
{
	struct circ_buf *xmit = &port->state->xmit;
	unsigned int tmp;

	if (port->x_char) {
		writel((u32)port->x_char, LPC32XX_HSUART_FIFO(port->membase));
		port->icount.tx++;
		port->x_char = 0;
		return;
	}

	if (uart_circ_empty(xmit) || uart_tx_stopped(port))
		goto exit_tx;

	/* Transfer data */
	while (LPC32XX_HSU_TX_LEV(readl(
		LPC32XX_HSUART_LEVEL(port->membase))) < 64) {
		writel((u32) xmit->buf[xmit->tail],
		       LPC32XX_HSUART_FIFO(port->membase));
		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		port->icount.tx++;
		if (uart_circ_empty(xmit))
			break;
	}

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

exit_tx:
	if (uart_circ_empty(xmit)) {
		tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
		tmp &= ~LPC32XX_HSU_TX_INT_EN;
		writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
	}
}

__attribute__((used)) static irqreturn_t serial_lpc32xx_interrupt(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	struct tty_port *tport = &port->state->port;
	u32 status;

	spin_lock(&port->lock);

	/* Read UART status and clear latched interrupts */
	status = readl(LPC32XX_HSUART_IIR(port->membase));

	if (status & LPC32XX_HSU_BRK_INT) {
		/* Break received */
		writel(LPC32XX_HSU_BRK_INT, LPC32XX_HSUART_IIR(port->membase));
		port->icount.brk++;
		uart_handle_break(port);
	}

	/* Framing error */
	if (status & LPC32XX_HSU_FE_INT)
		writel(LPC32XX_HSU_FE_INT, LPC32XX_HSUART_IIR(port->membase));

	if (status & LPC32XX_HSU_RX_OE_INT) {
		/* Receive FIFO overrun */
		writel(LPC32XX_HSU_RX_OE_INT,
		       LPC32XX_HSUART_IIR(port->membase));
		port->icount.overrun++;
		tty_insert_flip_char(tport, 0, TTY_OVERRUN);
		tty_schedule_flip(tport);
	}

	/* Data received? */
	if (status & (LPC32XX_HSU_RX_TIMEOUT_INT | LPC32XX_HSU_RX_TRIG_INT))
		__serial_lpc32xx_rx(port);

	/* Transmit data request? */
	if ((status & LPC32XX_HSU_TX_INT) && (!uart_tx_stopped(port))) {
		writel(LPC32XX_HSU_TX_INT, LPC32XX_HSUART_IIR(port->membase));
		__serial_lpc32xx_tx(port);
	}

	spin_unlock(&port->lock);

	return IRQ_HANDLED;
}

__attribute__((used)) static unsigned int serial_lpc32xx_tx_empty(struct uart_port *port)
{
	unsigned int ret = 0;

	if (LPC32XX_HSU_TX_LEV(readl(LPC32XX_HSUART_LEVEL(port->membase))) == 0)
		ret = TIOCSER_TEMT;

	return ret;
}

__attribute__((used)) static void serial_lpc32xx_set_mctrl(struct uart_port *port,
				     unsigned int mctrl)
{
	/* No signals are supported on HS UARTs */
}

__attribute__((used)) static unsigned int serial_lpc32xx_get_mctrl(struct uart_port *port)
{
	/* No signals are supported on HS UARTs */
	return TIOCM_CAR | TIOCM_DSR | TIOCM_CTS;
}

__attribute__((used)) static void serial_lpc32xx_stop_tx(struct uart_port *port)
{
	u32 tmp;

	tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
	tmp &= ~LPC32XX_HSU_TX_INT_EN;
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
}

__attribute__((used)) static void serial_lpc32xx_start_tx(struct uart_port *port)
{
	u32 tmp;

	__serial_lpc32xx_tx(port);
	tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
	tmp |= LPC32XX_HSU_TX_INT_EN;
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
}

__attribute__((used)) static void serial_lpc32xx_stop_rx(struct uart_port *port)
{
	u32 tmp;

	tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
	tmp &= ~(LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN);
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));

	writel((LPC32XX_HSU_BRK_INT | LPC32XX_HSU_RX_OE_INT |
		LPC32XX_HSU_FE_INT), LPC32XX_HSUART_IIR(port->membase));
}

__attribute__((used)) static void serial_lpc32xx_break_ctl(struct uart_port *port,
				     int break_state)
{
	unsigned long flags;
	u32 tmp;

	spin_lock_irqsave(&port->lock, flags);
	tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
	if (break_state != 0)
		tmp |= LPC32XX_HSU_BREAK;
	else
		tmp &= ~LPC32XX_HSU_BREAK;
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void lpc32xx_loopback_set(resource_size_t mapbase, int state)
{
	int bit;
	u32 tmp;

	switch (mapbase) {
	case LPC32XX_HS_UART1_BASE:
		bit = 0;
		break;
	case LPC32XX_HS_UART2_BASE:
		bit = 1;
		break;
	case LPC32XX_HS_UART7_BASE:
		bit = 6;
		break;
	default:
		WARN(1, "lpc32xx_hs: Warning: Unknown port at %08x\n", mapbase);
		return;
	}

	tmp = readl(LPC32XX_UARTCTL_CLOOP);
	if (state)
		tmp |= (1 << bit);
	else
		tmp &= ~(1 << bit);
	writel(tmp, LPC32XX_UARTCTL_CLOOP);
}

__attribute__((used)) static int serial_lpc32xx_startup(struct uart_port *port)
{
	int retval;
	unsigned long flags;
	u32 tmp;

	spin_lock_irqsave(&port->lock, flags);

	__serial_uart_flush(port);

	writel((LPC32XX_HSU_TX_INT | LPC32XX_HSU_FE_INT |
		LPC32XX_HSU_BRK_INT | LPC32XX_HSU_RX_OE_INT),
	       LPC32XX_HSUART_IIR(port->membase));

	writel(0xFF, LPC32XX_HSUART_RATE(port->membase));

	/*
	 * Set receiver timeout, HSU offset of 20, no break, no interrupts,
	 * and default FIFO trigger levels
	 */
	tmp = LPC32XX_HSU_TX_TL8B | LPC32XX_HSU_RX_TL32B |
		LPC32XX_HSU_OFFSET(20) | LPC32XX_HSU_TMO_INACT_4B;
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));

	lpc32xx_loopback_set(port->mapbase, 0); /* get out of loopback mode */

	spin_unlock_irqrestore(&port->lock, flags);

	retval = request_irq(port->irq, serial_lpc32xx_interrupt,
			     0, MODNAME, port);
	if (!retval)
		writel((tmp | LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN),
		       LPC32XX_HSUART_CTRL(port->membase));

	return retval;
}

__attribute__((used)) static void serial_lpc32xx_shutdown(struct uart_port *port)
{
	u32 tmp;
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);

	tmp = LPC32XX_HSU_TX_TL8B | LPC32XX_HSU_RX_TL32B |
		LPC32XX_HSU_OFFSET(20) | LPC32XX_HSU_TMO_INACT_4B;
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));

	lpc32xx_loopback_set(port->mapbase, 1); /* go to loopback mode */

	spin_unlock_irqrestore(&port->lock, flags);

	free_irq(port->irq, port);
}

__attribute__((used)) static void serial_lpc32xx_set_termios(struct uart_port *port,
				       struct ktermios *termios,
				       struct ktermios *old)
{
	unsigned long flags;
	unsigned int baud, quot;
	u32 tmp;

	/* Always 8-bit, no parity, 1 stop bit */
	termios->c_cflag &= ~(CSIZE | CSTOPB | PARENB | PARODD);
	termios->c_cflag |= CS8;

	termios->c_cflag &= ~(HUPCL | CMSPAR | CLOCAL | CRTSCTS);

	baud = uart_get_baud_rate(port, termios, old, 0,
				  port->uartclk / 14);

	quot = __serial_get_clock_div(port->uartclk, baud);

	spin_lock_irqsave(&port->lock, flags);

	/* Ignore characters? */
	tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
	if ((termios->c_cflag & CREAD) == 0)
		tmp &= ~(LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN);
	else
		tmp |= LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN;
	writel(tmp, LPC32XX_HSUART_CTRL(port->membase));

	writel(quot, LPC32XX_HSUART_RATE(port->membase));

	uart_update_timeout(port, termios->c_cflag, baud);

	spin_unlock_irqrestore(&port->lock, flags);

	/* Don't rewrite B0 */
	if (tty_termios_baud_rate(termios))
		tty_termios_encode_baud_rate(termios, baud, baud);
}

__attribute__((used)) static const char *serial_lpc32xx_type(struct uart_port *port)
{
	return MODNAME;
}

__attribute__((used)) static void serial_lpc32xx_release_port(struct uart_port *port)
{
	if ((port->iotype == UPIO_MEM32) && (port->mapbase)) {
		if (port->flags & UPF_IOREMAP) {
			iounmap(port->membase);
			port->membase = NULL;
		}

		release_mem_region(port->mapbase, SZ_4K);
	}
}

__attribute__((used)) static int serial_lpc32xx_request_port(struct uart_port *port)
{
	int ret = -ENODEV;

	if ((port->iotype == UPIO_MEM32) && (port->mapbase)) {
		ret = 0;

		if (!request_mem_region(port->mapbase, SZ_4K, MODNAME))
			ret = -EBUSY;
		else if (port->flags & UPF_IOREMAP) {
			port->membase = ioremap(port->mapbase, SZ_4K);
			if (!port->membase) {
				release_mem_region(port->mapbase, SZ_4K);
				ret = -ENOMEM;
			}
		}
	}

	return ret;
}

__attribute__((used)) static void serial_lpc32xx_config_port(struct uart_port *port, int uflags)
{
	int ret;

	ret = serial_lpc32xx_request_port(port);
	if (ret < 0)
		return;
	port->type = PORT_UART00;
	port->fifosize = 64;

	__serial_uart_flush(port);

	writel((LPC32XX_HSU_TX_INT | LPC32XX_HSU_FE_INT |
		LPC32XX_HSU_BRK_INT | LPC32XX_HSU_RX_OE_INT),
	       LPC32XX_HSUART_IIR(port->membase));

	writel(0xFF, LPC32XX_HSUART_RATE(port->membase));

	/* Set receiver timeout, HSU offset of 20, no break, no interrupts,
	   and default FIFO trigger levels */
	writel(LPC32XX_HSU_TX_TL8B | LPC32XX_HSU_RX_TL32B |
	       LPC32XX_HSU_OFFSET(20) | LPC32XX_HSU_TMO_INACT_4B,
	       LPC32XX_HSUART_CTRL(port->membase));
}

__attribute__((used)) static int serial_lpc32xx_verify_port(struct uart_port *port,
				      struct serial_struct *ser)
{
	int ret = 0;

	if (ser->type != PORT_UART00)
		ret = -EINVAL;

	return ret;
}

__attribute__((used)) static int serial_hs_lpc32xx_probe(struct platform_device *pdev)
{
	struct lpc32xx_hsuart_port *p = &lpc32xx_hs_ports[uarts_registered];
	int ret = 0;
	struct resource *res;

	if (uarts_registered >= MAX_PORTS) {
		dev_err(&pdev->dev,
			"Error: Number of possible ports exceeded (%d)!\n",
			uarts_registered + 1);
		return -ENXIO;
	}

	memset(p, 0, sizeof(*p));

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev,
			"Error getting mem resource for HS UART port %d\n",
			uarts_registered);
		return -ENXIO;
	}
	p->port.mapbase = res->start;
	p->port.membase = NULL;

	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		dev_err(&pdev->dev, "Error getting irq for HS UART port %d\n",
			uarts_registered);
		return ret;
	}
	p->port.irq = ret;

	p->port.iotype = UPIO_MEM32;
	p->port.uartclk = LPC32XX_MAIN_OSC_FREQ;
	p->port.regshift = 2;
	p->port.flags = UPF_BOOT_AUTOCONF | UPF_FIXED_PORT | UPF_IOREMAP;
	p->port.dev = &pdev->dev;
	p->port.ops = &serial_lpc32xx_pops;
	p->port.line = uarts_registered++;
	spin_lock_init(&p->port.lock);

	/* send port to loopback mode by default */
	lpc32xx_loopback_set(p->port.mapbase, 1);

	ret = uart_add_one_port(&lpc32xx_hs_reg, &p->port);

	platform_set_drvdata(pdev, p);

	return ret;
}

__attribute__((used)) static int serial_hs_lpc32xx_remove(struct platform_device *pdev)
{
	struct lpc32xx_hsuart_port *p = platform_get_drvdata(pdev);

	uart_remove_one_port(&lpc32xx_hs_reg, &p->port);

	return 0;
}


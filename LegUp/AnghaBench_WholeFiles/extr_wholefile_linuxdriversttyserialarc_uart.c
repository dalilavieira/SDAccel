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
typedef  void* u32 ;
struct TYPE_5__ {int /*<<< orphan*/  rx; int /*<<< orphan*/  frame; int /*<<< orphan*/  overrun; int /*<<< orphan*/  tx; } ;
struct uart_port {unsigned int x_char; int uartclk; scalar_t__ type; int line; scalar_t__ ignore_status_mask; int /*<<< orphan*/  fifosize; int /*<<< orphan*/ * ops; int /*<<< orphan*/  flags; int /*<<< orphan*/  iotype; TYPE_3__* dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  membase; int /*<<< orphan*/  lock; TYPE_2__* state; TYPE_1__ icount; } ;
struct serial_struct {scalar_t__ type; } ;
struct TYPE_7__ {struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct ktermios {int c_cflag; } ;
struct device_node {int dummy; } ;
struct circ_buf {unsigned char* buf; size_t tail; } ;
struct arc_uart_port {int baud; struct uart_port port; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int /*<<< orphan*/  port; struct circ_buf xmit; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARC_UART_TX_FIFO_SIZE ; 
 int ARRAY_SIZE (struct arc_uart_port*) ; 
 int CMSPAR ; 
 int CRTSCTS ; 
 int CS8 ; 
 int CSIZE ; 
 char const* DRIVER_NAME ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ PORT_ARC ; 
 scalar_t__ PORT_UNKNOWN ; 
 unsigned int RXEMPTY ; 
 unsigned int RXFERR ; 
 unsigned int RXIENB ; 
 unsigned int RXOERR ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 unsigned int TIOCSER_TEMT ; 
 unsigned int TTY_FRAME ; 
 unsigned int TTY_NORMAL ; 
 unsigned int TTY_OVERRUN ; 
 unsigned int TXEMPTY ; 
 unsigned int TXIENB ; 
 int /*<<< orphan*/  UART_ALL_IRQ_DISABLE (struct uart_port*) ; 
 int /*<<< orphan*/  UART_CLR_STATUS (struct uart_port*,unsigned int) ; 
 int UART_CONFIG_TYPE ; 
 unsigned int UART_GET_DATA (struct uart_port*) ; 
 unsigned int UART_GET_STATUS (struct uart_port*) ; 
 int /*<<< orphan*/  UART_RX_IRQ_DISABLE (struct uart_port*) ; 
 int /*<<< orphan*/  UART_RX_IRQ_ENABLE (struct uart_port*) ; 
 int /*<<< orphan*/  UART_SET_BAUDH (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  UART_SET_BAUDL (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  UART_SET_DATA (struct uart_port*,unsigned char) ; 
 int /*<<< orphan*/  UART_TX_IRQ_DISABLE (struct uart_port*) ; 
 int /*<<< orphan*/  UART_TX_IRQ_ENABLE (struct uart_port*) ; 
 int UART_XMIT_SIZE ; 
 int /*<<< orphan*/  UPF_BOOT_AUTOCONF ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 scalar_t__ WAKEUP_CHARS ; 
 int /*<<< orphan*/  arc_serial_pops ; 
 int /*<<< orphan*/  arc_uart_driver ; 
 struct arc_uart_port* arc_uart_ports ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct uart_port*) ; 
 int /*<<< orphan*/  irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 int of_alias_get_id (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,void**) ; 
 scalar_t__ request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct uart_port*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct arc_uart_port* to_arc_port (struct uart_port*) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (int /*<<< orphan*/ *) ; 
 scalar_t__ tty_termios_baud_rate (struct ktermios*) ; 
 int /*<<< orphan*/  tty_termios_copy_hw (struct ktermios*,struct ktermios*) ; 
 int /*<<< orphan*/  tty_termios_encode_baud_rate (struct ktermios*,unsigned int,unsigned int) ; 
 int uart_add_one_port (int /*<<< orphan*/ *,struct uart_port*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 int /*<<< orphan*/  uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uart_handle_sysrq_char (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  uart_insert_char (struct uart_port*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 scalar_t__ unlikely (unsigned int) ; 

__attribute__((used)) static void arc_serial_stop_rx(struct uart_port *port)
{
	UART_RX_IRQ_DISABLE(port);
}

__attribute__((used)) static void arc_serial_stop_tx(struct uart_port *port)
{
	while (!(UART_GET_STATUS(port) & TXEMPTY))
		cpu_relax();

	UART_TX_IRQ_DISABLE(port);
}

__attribute__((used)) static unsigned int arc_serial_tx_empty(struct uart_port *port)
{
	unsigned int stat;

	stat = UART_GET_STATUS(port);
	if (stat & TXEMPTY)
		return TIOCSER_TEMT;

	return 0;
}

__attribute__((used)) static void arc_serial_tx_chars(struct uart_port *port)
{
	struct circ_buf *xmit = &port->state->xmit;
	int sent = 0;
	unsigned char ch;

	if (unlikely(port->x_char)) {
		UART_SET_DATA(port, port->x_char);
		port->icount.tx++;
		port->x_char = 0;
		sent = 1;
	} else if (!uart_circ_empty(xmit)) {
		ch = xmit->buf[xmit->tail];
		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		port->icount.tx++;
		while (!(UART_GET_STATUS(port) & TXEMPTY))
			cpu_relax();
		UART_SET_DATA(port, ch);
		sent = 1;
	}

	/*
	 * If num chars in xmit buffer are too few, ask tty layer for more.
	 * By Hard ISR to schedule processing in software interrupt part
	 */
	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

	if (sent)
		UART_TX_IRQ_ENABLE(port);
}

__attribute__((used)) static void arc_serial_start_tx(struct uart_port *port)
{
	arc_serial_tx_chars(port);
}

__attribute__((used)) static void arc_serial_rx_chars(struct uart_port *port, unsigned int status)
{
	unsigned int ch, flg = 0;

	/*
	 * UART has 4 deep RX-FIFO. Driver's recongnition of this fact
	 * is very subtle. Here's how ...
	 * Upon getting a RX-Intr, such that RX-EMPTY=0, meaning data available,
	 * driver reads the DATA Reg and keeps doing that in a loop, until
	 * RX-EMPTY=1. Multiple chars being avail, with a single Interrupt,
	 * before RX-EMPTY=0, implies some sort of buffering going on in the
	 * controller, which is indeed the Rx-FIFO.
	 */
	do {
		/*
		 * This could be an Rx Intr for err (no data),
		 * so check err and clear that Intr first
		 */
		if (unlikely(status & (RXOERR | RXFERR))) {
			if (status & RXOERR) {
				port->icount.overrun++;
				flg = TTY_OVERRUN;
				UART_CLR_STATUS(port, RXOERR);
			}

			if (status & RXFERR) {
				port->icount.frame++;
				flg = TTY_FRAME;
				UART_CLR_STATUS(port, RXFERR);
			}
		} else
			flg = TTY_NORMAL;

		if (status & RXEMPTY)
			continue;

		ch = UART_GET_DATA(port);
		port->icount.rx++;

		if (!(uart_handle_sysrq_char(port, ch)))
			uart_insert_char(port, status, RXOERR, ch, flg);

		spin_unlock(&port->lock);
		tty_flip_buffer_push(&port->state->port);
		spin_lock(&port->lock);
	} while (!((status = UART_GET_STATUS(port)) & RXEMPTY));
}

__attribute__((used)) static irqreturn_t arc_serial_isr(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	unsigned int status;

	status = UART_GET_STATUS(port);

	/*
	 * Single IRQ for both Rx (data available) Tx (room available) Interrupt
	 * notifications from the UART Controller.
	 * To demultiplex between the two, we check the relevant bits
	 */
	if (status & RXIENB) {

		/* already in ISR, no need of xx_irqsave */
		spin_lock(&port->lock);
		arc_serial_rx_chars(port, status);
		spin_unlock(&port->lock);
	}

	if ((status & TXIENB) && (status & TXEMPTY)) {

		/* Unconditionally disable further Tx-Interrupts.
		 * will be enabled by tx_chars() if needed.
		 */
		UART_TX_IRQ_DISABLE(port);

		spin_lock(&port->lock);

		if (!uart_tx_stopped(port))
			arc_serial_tx_chars(port);

		spin_unlock(&port->lock);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static unsigned int arc_serial_get_mctrl(struct uart_port *port)
{
	/*
	 * Pretend we have a Modem status reg and following bits are
	 *  always set, to satify the serial core state machine
	 *  (DSR) Data Set Ready
	 *  (CTS) Clear To Send
	 *  (CAR) Carrier Detect
	 */
	return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}

__attribute__((used)) static void arc_serial_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	/* MCR not present */
}

__attribute__((used)) static void arc_serial_break_ctl(struct uart_port *port, int break_state)
{
	/* ARC UART doesn't support sending Break signal */
}

__attribute__((used)) static int arc_serial_startup(struct uart_port *port)
{
	/* Before we hook up the ISR, Disable all UART Interrupts */
	UART_ALL_IRQ_DISABLE(port);

	if (request_irq(port->irq, arc_serial_isr, 0, "arc uart rx-tx", port)) {
		dev_warn(port->dev, "Unable to attach ARC UART intr\n");
		return -EBUSY;
	}

	UART_RX_IRQ_ENABLE(port); /* Only Rx IRQ enabled to begin with */

	return 0;
}

__attribute__((used)) static void arc_serial_shutdown(struct uart_port *port)
{
	free_irq(port->irq, port);
}

__attribute__((used)) static void
arc_serial_set_termios(struct uart_port *port, struct ktermios *new,
		       struct ktermios *old)
{
	struct arc_uart_port *uart = to_arc_port(port);
	unsigned int baud, uartl, uarth, hw_val;
	unsigned long flags;

	/*
	 * Use the generic handler so that any specially encoded baud rates
	 * such as SPD_xx flags or "%B0" can be handled
	 * Max Baud I suppose will not be more than current 115K * 4
	 * Formula for ARC UART is: hw-val = ((CLK/(BAUD*4)) -1)
	 * spread over two 8-bit registers
	 */
	baud = uart_get_baud_rate(port, new, old, 0, 460800);

	hw_val = port->uartclk / (uart->baud * 4) - 1;
	uartl = hw_val & 0xFF;
	uarth = (hw_val >> 8) & 0xFF;

	spin_lock_irqsave(&port->lock, flags);

	UART_ALL_IRQ_DISABLE(port);

	UART_SET_BAUDL(port, uartl);
	UART_SET_BAUDH(port, uarth);

	UART_RX_IRQ_ENABLE(port);

	/*
	 * UART doesn't support Parity/Hardware Flow Control;
	 * Only supports 8N1 character size
	 */
	new->c_cflag &= ~(CMSPAR|CRTSCTS|CSIZE);
	new->c_cflag |= CS8;

	if (old)
		tty_termios_copy_hw(new, old);

	/* Don't rewrite B0 */
	if (tty_termios_baud_rate(new))
		tty_termios_encode_baud_rate(new, baud, baud);

	uart_update_timeout(port, new->c_cflag, baud);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static const char *arc_serial_type(struct uart_port *port)
{
	return port->type == PORT_ARC ? DRIVER_NAME : NULL;
}

__attribute__((used)) static void arc_serial_release_port(struct uart_port *port)
{
}

__attribute__((used)) static int arc_serial_request_port(struct uart_port *port)
{
	return 0;
}

__attribute__((used)) static int
arc_serial_verify_port(struct uart_port *port, struct serial_struct *ser)
{
	if (port->type != PORT_UNKNOWN && ser->type != PORT_ARC)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static void arc_serial_config_port(struct uart_port *port, int flags)
{
	if (flags & UART_CONFIG_TYPE)
		port->type = PORT_ARC;
}

__attribute__((used)) static int arc_serial_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct arc_uart_port *uart;
	struct uart_port *port;
	int dev_id;
	u32 val;

	/* no device tree device */
	if (!np)
		return -ENODEV;

	dev_id = of_alias_get_id(np, "serial");
	if (dev_id < 0)
		dev_id = 0;

	if (dev_id >= ARRAY_SIZE(arc_uart_ports)) {
		dev_err(&pdev->dev, "serial%d out of range\n", dev_id);
		return -EINVAL;
	}

	uart = &arc_uart_ports[dev_id];
	port = &uart->port;

	if (of_property_read_u32(np, "clock-frequency", &val)) {
		dev_err(&pdev->dev, "clock-frequency property NOTset\n");
		return -EINVAL;
	}
	port->uartclk = val;

	if (of_property_read_u32(np, "current-speed", &val)) {
		dev_err(&pdev->dev, "current-speed property NOT set\n");
		return -EINVAL;
	}
	uart->baud = val;

	port->membase = of_iomap(np, 0);
	if (!port->membase)
		/* No point of dev_err since UART itself is hosed here */
		return -ENXIO;

	port->irq = irq_of_parse_and_map(np, 0);

	port->dev = &pdev->dev;
	port->iotype = UPIO_MEM;
	port->flags = UPF_BOOT_AUTOCONF;
	port->line = dev_id;
	port->ops = &arc_serial_pops;

	port->fifosize = ARC_UART_TX_FIFO_SIZE;

	/*
	 * uart_insert_char( ) uses it in decideding whether to ignore a
	 * char or not. Explicitly setting it here, removes the subtelty
	 */
	port->ignore_status_mask = 0;

	return uart_add_one_port(&arc_uart_driver, &arc_uart_ports[dev_id].port);
}

__attribute__((used)) static int arc_serial_remove(struct platform_device *pdev)
{
	/* This will never be called */
	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int ;
struct TYPE_4__ {int /*<<< orphan*/  rng; int /*<<< orphan*/  dsr; int /*<<< orphan*/  tx; int /*<<< orphan*/  overrun; int /*<<< orphan*/  frame; int /*<<< orphan*/  parity; int /*<<< orphan*/  brk; int /*<<< orphan*/  rx; } ;
struct uart_port {int* unused; unsigned int read_status_mask; int uartclk; int fifosize; unsigned int ignore_status_mask; scalar_t__ type; scalar_t__ irq; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  lock; TYPE_2__* state; TYPE_1__ icount; scalar_t__ x_char; } ;
struct serial_struct {scalar_t__ type; scalar_t__ irq; int baud_base; } ;
struct ktermios {int c_cflag; int c_iflag; } ;
struct circ_buf {size_t tail; scalar_t__* buf; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int /*<<< orphan*/  delta_msr_wait; } ;
struct TYPE_5__ {TYPE_3__ port; struct circ_buf xmit; } ;

/* Variables and functions */
 int BRKINT ; 
 int CMSPAR ; 
 int CREAD ; 
#define  CS5 130 
#define  CS6 129 
#define  CS7 128 
 int CSIZE ; 
 int CSTOPB ; 
 int EBUSY ; 
 int EINVAL ; 
 int IGNBRK ; 
 int IGNPAR ; 
 int INPCK ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NOAUTOEN ; 
 int /*<<< orphan*/  IRQ_NOREQUEST ; 
 int /*<<< orphan*/  KS8695_CLR_TX_INT () ; 
 int /*<<< orphan*/  KS8695_IRQ_UART_LINE_STATUS ; 
 int /*<<< orphan*/  KS8695_IRQ_UART_MODEM_STATUS ; 
 int /*<<< orphan*/  KS8695_IRQ_UART_RX ; 
 int /*<<< orphan*/  KS8695_IRQ_UART_TX ; 
 int PARENB ; 
 int PARMRK ; 
 int PARODD ; 
 scalar_t__ PORT_KS8695 ; 
 scalar_t__ PORT_UNKNOWN ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 int TIOCM_DTR ; 
 unsigned int TIOCM_RI ; 
 int TIOCM_RTS ; 
 unsigned int TIOCSER_TEMT ; 
 unsigned int TTY_BREAK ; 
 unsigned int TTY_FRAME ; 
 unsigned int TTY_NORMAL ; 
 unsigned int TTY_PARITY ; 
 int UART_CONFIG_TYPE ; 
 int UART_DUMMY_LSR_RX ; 
 scalar_t__ UART_ENABLE_MS (struct uart_port*,int) ; 
 unsigned int UART_GET_CHAR (struct uart_port*) ; 
 unsigned int UART_GET_FCR (struct uart_port*) ; 
 unsigned int UART_GET_LCR (struct uart_port*) ; 
 int UART_GET_LSR (struct uart_port*) ; 
 unsigned int UART_GET_MCR (struct uart_port*) ; 
 unsigned int UART_GET_MSR (struct uart_port*) ; 
 int /*<<< orphan*/  UART_PORT_SIZE ; 
 int /*<<< orphan*/  UART_PUT_BRDR (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  UART_PUT_CHAR (struct uart_port*,scalar_t__) ; 
 int /*<<< orphan*/  UART_PUT_FCR (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  UART_PUT_LCR (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  UART_PUT_MCR (struct uart_port*,unsigned int) ; 
 int UART_XMIT_SIZE ; 
 unsigned int URCL_5 ; 
 unsigned int URCL_6 ; 
 unsigned int URCL_7 ; 
 unsigned int URCL_8 ; 
 unsigned int URFC_URFE ; 
 unsigned int URFC_URFRT_8 ; 
 unsigned int URFC_URRFR ; 
 unsigned int URFC_URTFR ; 
 unsigned int URLC_URSB ; 
 unsigned int URLC_URSBC ; 
 unsigned int URLS_URBI ; 
 unsigned int URLS_URDR ; 
 unsigned int URLS_URFE ; 
 unsigned int URLS_URPE ; 
 unsigned int URLS_URROE ; 
 int URLS_URTE ; 
 unsigned int URMC_URDTR ; 
 unsigned int URMC_URRTS ; 
 unsigned int URMS_URCTS ; 
 unsigned int URMS_URDCD ; 
 unsigned int URMS_URDCTS ; 
 unsigned int URMS_URDDCD ; 
 unsigned int URMS_URDDST ; 
 unsigned int URMS_URDSR ; 
 unsigned int URMS_URRI ; 
 unsigned int URMS_URTERI ; 
 unsigned int URPE_EVEN ; 
 unsigned int URPE_MARK ; 
 unsigned int URPE_ODD ; 
 unsigned int URPE_SPACE ; 
 scalar_t__ WAKEUP_CHARS ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_irq_nosync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct uart_port*) ; 
 int /*<<< orphan*/  irq_modify_status (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct uart_port*) ; 
 int /*<<< orphan*/ * request_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (TYPE_3__*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int /*<<< orphan*/ ,int) ; 
 unsigned int uart_get_divisor (struct uart_port*,unsigned int) ; 
 scalar_t__ uart_handle_break (struct uart_port*) ; 
 int /*<<< orphan*/  uart_handle_cts_change (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  uart_handle_dcd_change (struct uart_port*,unsigned int) ; 
 scalar_t__ uart_handle_sysrq_char (struct uart_port*,unsigned int) ; 
 int /*<<< orphan*/  uart_insert_char (struct uart_port*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 scalar_t__ uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 scalar_t__ unlikely (unsigned int) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int tx_enabled(struct uart_port *port)
{
	return port->unused[0] & 1;
}

__attribute__((used)) static inline int rx_enabled(struct uart_port *port)
{
	return port->unused[0] & 2;
}

__attribute__((used)) static inline int ms_enabled(struct uart_port *port)
{
	return port->unused[0] & 4;
}

__attribute__((used)) static inline void ms_enable(struct uart_port *port, int enabled)
{
	if(enabled)
		port->unused[0] |= 4;
	else
		port->unused[0] &= ~4;
}

__attribute__((used)) static inline void rx_enable(struct uart_port *port, int enabled)
{
	if(enabled)
		port->unused[0] |= 2;
	else
		port->unused[0] &= ~2;
}

__attribute__((used)) static inline void tx_enable(struct uart_port *port, int enabled)
{
	if(enabled)
		port->unused[0] |= 1;
	else
		port->unused[0] &= ~1;
}

__attribute__((used)) static void ks8695uart_stop_tx(struct uart_port *port)
{
	if (tx_enabled(port)) {
		/* use disable_irq_nosync() and not disable_irq() to avoid self
		 * imposed deadlock by not waiting for irq handler to end,
		 * since this ks8695uart_stop_tx() is called from interrupt context.
		 */
		disable_irq_nosync(KS8695_IRQ_UART_TX);
		tx_enable(port, 0);
	}
}

__attribute__((used)) static void ks8695uart_start_tx(struct uart_port *port)
{
	if (!tx_enabled(port)) {
		enable_irq(KS8695_IRQ_UART_TX);
		tx_enable(port, 1);
	}
}

__attribute__((used)) static void ks8695uart_stop_rx(struct uart_port *port)
{
	if (rx_enabled(port)) {
		disable_irq(KS8695_IRQ_UART_RX);
		rx_enable(port, 0);
	}
}

__attribute__((used)) static void ks8695uart_enable_ms(struct uart_port *port)
{
	if (!ms_enabled(port)) {
		enable_irq(KS8695_IRQ_UART_MODEM_STATUS);
		ms_enable(port,1);
	}
}

__attribute__((used)) static void ks8695uart_disable_ms(struct uart_port *port)
{
	if (ms_enabled(port)) {
		disable_irq(KS8695_IRQ_UART_MODEM_STATUS);
		ms_enable(port,0);
	}
}

__attribute__((used)) static irqreturn_t ks8695uart_rx_chars(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	unsigned int status, ch, lsr, flg, max_count = 256;

	status = UART_GET_LSR(port);		/* clears pending LSR interrupts */
	while ((status & URLS_URDR) && max_count--) {
		ch = UART_GET_CHAR(port);
		flg = TTY_NORMAL;

		port->icount.rx++;

		/*
		 * Note that the error handling code is
		 * out of the main execution path
		 */
		lsr = UART_GET_LSR(port) | UART_DUMMY_LSR_RX;
		if (unlikely(lsr & (URLS_URBI | URLS_URPE | URLS_URFE | URLS_URROE))) {
			if (lsr & URLS_URBI) {
				lsr &= ~(URLS_URFE | URLS_URPE);
				port->icount.brk++;
				if (uart_handle_break(port))
					goto ignore_char;
			}
			if (lsr & URLS_URPE)
				port->icount.parity++;
			if (lsr & URLS_URFE)
				port->icount.frame++;
			if (lsr & URLS_URROE)
				port->icount.overrun++;

			lsr &= port->read_status_mask;

			if (lsr & URLS_URBI)
				flg = TTY_BREAK;
			else if (lsr & URLS_URPE)
				flg = TTY_PARITY;
			else if (lsr & URLS_URFE)
				flg = TTY_FRAME;
		}

		if (uart_handle_sysrq_char(port, ch))
			goto ignore_char;

		uart_insert_char(port, lsr, URLS_URROE, ch, flg);

ignore_char:
		status = UART_GET_LSR(port);
	}
	tty_flip_buffer_push(&port->state->port);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t ks8695uart_tx_chars(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	struct circ_buf *xmit = &port->state->xmit;
	unsigned int count;

	if (port->x_char) {
		KS8695_CLR_TX_INT();
		UART_PUT_CHAR(port, port->x_char);
		port->icount.tx++;
		port->x_char = 0;
		return IRQ_HANDLED;
	}

	if (uart_tx_stopped(port) || uart_circ_empty(xmit)) {
		ks8695uart_stop_tx(port);
		return IRQ_HANDLED;
	}

	count = 16;	/* fifo size */
	while (!uart_circ_empty(xmit) && (count-- > 0)) {
		KS8695_CLR_TX_INT();
		UART_PUT_CHAR(port, xmit->buf[xmit->tail]);

		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		port->icount.tx++;
	}

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

	if (uart_circ_empty(xmit))
		ks8695uart_stop_tx(port);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t ks8695uart_modem_status(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	unsigned int status;

	/*
	 * clear modem interrupt by reading MSR
	 */
	status = UART_GET_MSR(port);

	if (status & URMS_URDDCD)
		uart_handle_dcd_change(port, status & URMS_URDDCD);

	if (status & URMS_URDDST)
		port->icount.dsr++;

	if (status & URMS_URDCTS)
		uart_handle_cts_change(port, status & URMS_URDCTS);

	if (status & URMS_URTERI)
		port->icount.rng++;

	wake_up_interruptible(&port->state->port.delta_msr_wait);

	return IRQ_HANDLED;
}

__attribute__((used)) static unsigned int ks8695uart_tx_empty(struct uart_port *port)
{
	return (UART_GET_LSR(port) & URLS_URTE) ? TIOCSER_TEMT : 0;
}

__attribute__((used)) static unsigned int ks8695uart_get_mctrl(struct uart_port *port)
{
	unsigned int result = 0;
	unsigned int status;

	status = UART_GET_MSR(port);
	if (status & URMS_URDCD)
		result |= TIOCM_CAR;
	if (status & URMS_URDSR)
		result |= TIOCM_DSR;
	if (status & URMS_URCTS)
		result |= TIOCM_CTS;
	if (status & URMS_URRI)
		result |= TIOCM_RI;

	return result;
}

__attribute__((used)) static void ks8695uart_set_mctrl(struct uart_port *port, u_int mctrl)
{
	unsigned int mcr;

	mcr = UART_GET_MCR(port);
	if (mctrl & TIOCM_RTS)
		mcr |= URMC_URRTS;
	else
		mcr &= ~URMC_URRTS;

	if (mctrl & TIOCM_DTR)
		mcr |= URMC_URDTR;
	else
		mcr &= ~URMC_URDTR;

	UART_PUT_MCR(port, mcr);
}

__attribute__((used)) static void ks8695uart_break_ctl(struct uart_port *port, int break_state)
{
	unsigned int lcr;

	lcr = UART_GET_LCR(port);

	if (break_state == -1)
		lcr |= URLC_URSBC;
	else
		lcr &= ~URLC_URSBC;

	UART_PUT_LCR(port, lcr);
}

__attribute__((used)) static int ks8695uart_startup(struct uart_port *port)
{
	int retval;

	irq_modify_status(KS8695_IRQ_UART_TX, IRQ_NOREQUEST, IRQ_NOAUTOEN);
	tx_enable(port, 0);
	rx_enable(port, 1);
	ms_enable(port, 1);

	/*
	 * Allocate the IRQ
	 */
	retval = request_irq(KS8695_IRQ_UART_TX, ks8695uart_tx_chars, 0, "UART TX", port);
	if (retval)
		goto err_tx;

	retval = request_irq(KS8695_IRQ_UART_RX, ks8695uart_rx_chars, 0, "UART RX", port);
	if (retval)
		goto err_rx;

	retval = request_irq(KS8695_IRQ_UART_LINE_STATUS, ks8695uart_rx_chars, 0, "UART LineStatus", port);
	if (retval)
		goto err_ls;

	retval = request_irq(KS8695_IRQ_UART_MODEM_STATUS, ks8695uart_modem_status, 0, "UART ModemStatus", port);
	if (retval)
		goto err_ms;

	return 0;

err_ms:
	free_irq(KS8695_IRQ_UART_LINE_STATUS, port);
err_ls:
	free_irq(KS8695_IRQ_UART_RX, port);
err_rx:
	free_irq(KS8695_IRQ_UART_TX, port);
err_tx:
	return retval;
}

__attribute__((used)) static void ks8695uart_shutdown(struct uart_port *port)
{
	/*
	 * Free the interrupt
	 */
	free_irq(KS8695_IRQ_UART_RX, port);
	free_irq(KS8695_IRQ_UART_TX, port);
	free_irq(KS8695_IRQ_UART_MODEM_STATUS, port);
	free_irq(KS8695_IRQ_UART_LINE_STATUS, port);

	/* disable break condition and fifos */
	UART_PUT_LCR(port, UART_GET_LCR(port) & ~URLC_URSBC);
	UART_PUT_FCR(port, UART_GET_FCR(port) & ~URFC_URFE);
}

__attribute__((used)) static void ks8695uart_set_termios(struct uart_port *port, struct ktermios *termios, struct ktermios *old)
{
	unsigned int lcr, fcr = 0;
	unsigned long flags;
	unsigned int baud, quot;

	/*
	 * Ask the core to calculate the divisor for us.
	 */
	baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
	quot = uart_get_divisor(port, baud);

	switch (termios->c_cflag & CSIZE) {
	case CS5:
		lcr = URCL_5;
		break;
	case CS6:
		lcr = URCL_6;
		break;
	case CS7:
		lcr = URCL_7;
		break;
	default:
		lcr = URCL_8;
		break;
	}

	/* stop bits */
	if (termios->c_cflag & CSTOPB)
		lcr |= URLC_URSB;

	/* parity */
	if (termios->c_cflag & PARENB) {
		if (termios->c_cflag & CMSPAR) {	/* Mark or Space parity */
			if (termios->c_cflag & PARODD)
				lcr |= URPE_MARK;
			else
				lcr |= URPE_SPACE;
		}
		else if (termios->c_cflag & PARODD)
			lcr |= URPE_ODD;
		else
			lcr |= URPE_EVEN;
	}

	if (port->fifosize > 1)
		fcr = URFC_URFRT_8 | URFC_URTFR | URFC_URRFR | URFC_URFE;

	spin_lock_irqsave(&port->lock, flags);

	/*
	 * Update the per-port timeout.
	 */
	uart_update_timeout(port, termios->c_cflag, baud);

	port->read_status_mask = URLS_URROE;
	if (termios->c_iflag & INPCK)
		port->read_status_mask |= (URLS_URFE | URLS_URPE);
	if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
		port->read_status_mask |= URLS_URBI;

	/*
	 * Characters to ignore
	 */
	port->ignore_status_mask = 0;
	if (termios->c_iflag & IGNPAR)
		port->ignore_status_mask |= (URLS_URFE | URLS_URPE);
	if (termios->c_iflag & IGNBRK) {
		port->ignore_status_mask |= URLS_URBI;
		/*
		 * If we're ignoring parity and break indicators,
		 * ignore overruns too (for real raw support).
		 */
		if (termios->c_iflag & IGNPAR)
			port->ignore_status_mask |= URLS_URROE;
	}

	/*
	 * Ignore all characters if CREAD is not set.
	 */
	if ((termios->c_cflag & CREAD) == 0)
		port->ignore_status_mask |= UART_DUMMY_LSR_RX;

	/* first, disable everything */
	if (UART_ENABLE_MS(port, termios->c_cflag))
		ks8695uart_enable_ms(port);
	else
		ks8695uart_disable_ms(port);

	/* Set baud rate */
	UART_PUT_BRDR(port, quot);

	UART_PUT_LCR(port, lcr);
	UART_PUT_FCR(port, fcr);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static const char *ks8695uart_type(struct uart_port *port)
{
	return port->type == PORT_KS8695 ? "KS8695" : NULL;
}

__attribute__((used)) static void ks8695uart_release_port(struct uart_port *port)
{
	release_mem_region(port->mapbase, UART_PORT_SIZE);
}

__attribute__((used)) static int ks8695uart_request_port(struct uart_port *port)
{
	return request_mem_region(port->mapbase, UART_PORT_SIZE,
			"serial_ks8695") != NULL ? 0 : -EBUSY;
}

__attribute__((used)) static void ks8695uart_config_port(struct uart_port *port, int flags)
{
	if (flags & UART_CONFIG_TYPE) {
		port->type = PORT_KS8695;
		ks8695uart_request_port(port);
	}
}

__attribute__((used)) static int ks8695uart_verify_port(struct uart_port *port, struct serial_struct *ser)
{
	int ret = 0;

	if (ser->type != PORT_UNKNOWN && ser->type != PORT_KS8695)
		ret = -EINVAL;
	if (ser->irq != port->irq)
		ret = -EINVAL;
	if (ser->baud_base < 9600)
		ret = -EINVAL;
	return ret;
}


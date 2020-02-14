#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_9__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int tcflag_t ;
struct TYPE_12__ {int /*<<< orphan*/  tx; int /*<<< orphan*/  dsr; int /*<<< orphan*/  rng; int /*<<< orphan*/  overrun; int /*<<< orphan*/  parity; int /*<<< orphan*/  frame; int /*<<< orphan*/  brk; int /*<<< orphan*/  rx; } ;
struct uart_port {int type; int line; scalar_t__ irq; int read_status_mask; int x_char; unsigned int mctrl; int uartclk; int ignore_status_mask; int flags; unsigned long mapbase; scalar_t__ iotype; int fifosize; int /*<<< orphan*/ * dev; int /*<<< orphan*/ * ops; scalar_t__ regshift; int /*<<< orphan*/ * membase; int /*<<< orphan*/  lock; TYPE_2__ icount; TYPE_1__* state; } ;
struct serial_struct {scalar_t__ irq; scalar_t__ io_type; scalar_t__ iomem_base; } ;
struct resource {unsigned long start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct ktermios {int c_cflag; int c_iflag; } ;
struct circ_buf {int* buf; size_t tail; } ;
typedef  scalar_t__ siu_interface_t ;
typedef  int /*<<< orphan*/  pm_message_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  scalar_t__ irda_use_t ;
typedef  int /*<<< orphan*/  irda_speed_t ;
typedef  int irda_module_t ;
struct TYPE_14__ {int /*<<< orphan*/  delta_msr_wait; } ;
struct TYPE_13__ {int nr; } ;
struct TYPE_11__ {struct circ_buf xmit; TYPE_9__ port; } ;

/* Variables and functions */
 int BRKINT ; 
 int CMSPAR ; 
 int CREAD ; 
#define  CS5 135 
#define  CS6 134 
#define  CS7 133 
 int CSIZE ; 
 int CSTOPB ; 
 int /*<<< orphan*/  DSIUINT_ALL ; 
 int /*<<< orphan*/  DSIU_CLOCK ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ FIR_USE_IRDA ; 
#define  HP_IRDA 132 
 int IGNBRK ; 
 int IGNPAR ; 
 int INPCK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRDA_TX_4MBPS ; 
 int IRMSEL ; 
 int IRMSEL_HP ; 
 int IRMSEL_SHARP ; 
 int IRMSEL_TEMIC ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int IRUSESEL ; 
 int PARENB ; 
 int PARMRK ; 
 int PARODD ; 
 unsigned int PORT_UNKNOWN ; 
#define  PORT_VR41XX_DSIU 131 
#define  PORT_VR41XX_SIU 130 
 int RX_MAX_COUNT ; 
#define  SHARP_IRDA 129 
 int SIRSEL ; 
 int /*<<< orphan*/  SIUIRSEL ; 
 int SIU_BAUD_BASE ; 
 int /*<<< orphan*/  SIU_CLOCK ; 
 scalar_t__ SIU_INTERFACE_IRDA ; 
 int SIU_PORTS_MAX ; 
#define  TEMIC_IRDA 128 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_CTS ; 
 unsigned int TIOCM_DSR ; 
 unsigned int TIOCM_DTR ; 
 unsigned int TIOCM_LOOP ; 
 unsigned int TIOCM_OUT1 ; 
 unsigned int TIOCM_OUT2 ; 
 unsigned int TIOCM_RNG ; 
 unsigned int TIOCM_RTS ; 
 unsigned int TIOCSER_TEMT ; 
 int TMICMODE ; 
 int TMICTX ; 
 char TTY_BREAK ; 
 char TTY_FRAME ; 
 char TTY_NORMAL ; 
 char TTY_PARITY ; 
 int TX_MAX_COUNT ; 
 int UART_CONFIG_TYPE ; 
 int /*<<< orphan*/  UART_DLL ; 
 int /*<<< orphan*/  UART_DLM ; 
 scalar_t__ UART_ENABLE_MS (struct uart_port*,int) ; 
 int /*<<< orphan*/  UART_FCR ; 
 int UART_FCR_CLEAR_RCVR ; 
 int UART_FCR_CLEAR_XMIT ; 
 int UART_FCR_ENABLE_FIFO ; 
 int UART_FCR_R_TRIG_10 ; 
 int /*<<< orphan*/  UART_IER ; 
 int UART_IER_MSI ; 
 int UART_IER_RDI ; 
 int UART_IER_RLSI ; 
 int UART_IER_THRI ; 
 int /*<<< orphan*/  UART_IIR ; 
 int UART_IIR_NO_INT ; 
 int /*<<< orphan*/  UART_LCR ; 
 int UART_LCR_DLAB ; 
 int UART_LCR_EPAR ; 
 int UART_LCR_PARITY ; 
 int UART_LCR_SBC ; 
 int UART_LCR_SPAR ; 
 int UART_LCR_STOP ; 
 int UART_LCR_WLEN5 ; 
 int UART_LCR_WLEN6 ; 
 int UART_LCR_WLEN7 ; 
 int UART_LCR_WLEN8 ; 
 int /*<<< orphan*/  UART_LSR ; 
 int UART_LSR_BI ; 
 int UART_LSR_DR ; 
 int UART_LSR_FE ; 
 int UART_LSR_OE ; 
 int UART_LSR_PE ; 
 int UART_LSR_TEMT ; 
 int UART_LSR_THRE ; 
 int /*<<< orphan*/  UART_MCR ; 
 int UART_MCR_DTR ; 
 int UART_MCR_LOOP ; 
 int UART_MCR_OUT1 ; 
 int UART_MCR_OUT2 ; 
 int UART_MCR_RTS ; 
 int /*<<< orphan*/  UART_MSR ; 
 int UART_MSR_ANY_DELTA ; 
 int UART_MSR_CTS ; 
 int UART_MSR_DCD ; 
 int UART_MSR_DCTS ; 
 int UART_MSR_DDCD ; 
 int UART_MSR_DDSR ; 
 int UART_MSR_DSR ; 
 int UART_MSR_RI ; 
 int UART_MSR_TERI ; 
 int /*<<< orphan*/  UART_RX ; 
 int /*<<< orphan*/  UART_TX ; 
 int UART_XMIT_SIZE ; 
 int UPF_BOOT_AUTOCONF ; 
 int UPF_IOREMAP ; 
 scalar_t__ UPIO_MEM ; 
 scalar_t__ WAKEUP_CHARS ; 
 int* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct uart_port*) ; 
 int /*<<< orphan*/ * ioremap (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_mem_region (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  release_resource (struct resource*) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char const*,struct uart_port*) ; 
 struct resource* request_mem_region (unsigned long,unsigned long,char const*) ; 
 int siu_read (struct uart_port*,int /*<<< orphan*/ ) ; 
 TYPE_3__ siu_uart_driver ; 
 int /*<<< orphan*/  siu_uart_ops ; 
 struct uart_port* siu_uart_ports ; 
 int /*<<< orphan*/  siu_write (struct uart_port*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (TYPE_9__*) ; 
 int uart_add_one_port (TYPE_3__*,struct uart_port*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int /*<<< orphan*/ ,int) ; 
 unsigned int uart_get_divisor (struct uart_port*,unsigned int) ; 
 scalar_t__ uart_handle_break (struct uart_port*) ; 
 int /*<<< orphan*/  uart_handle_cts_change (struct uart_port*,int) ; 
 int /*<<< orphan*/  uart_handle_dcd_change (struct uart_port*,int) ; 
 scalar_t__ uart_handle_sysrq_char (struct uart_port*,int) ; 
 int /*<<< orphan*/  uart_insert_char (struct uart_port*,int,int,int,char) ; 
 int uart_register_driver (TYPE_3__*) ; 
 int /*<<< orphan*/  uart_remove_one_port (TYPE_3__*,struct uart_port*) ; 
 int /*<<< orphan*/  uart_resume_port (TYPE_3__*,struct uart_port*) ; 
 int /*<<< orphan*/  uart_suspend_port (TYPE_3__*,struct uart_port*) ; 
 scalar_t__ uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_unregister_driver (TYPE_3__*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  vr41xx_disable_dsiuint (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vr41xx_enable_dsiuint (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vr41xx_mask_clock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vr41xx_supply_clock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

void vr41xx_select_siu_interface(siu_interface_t interface)
{
	struct uart_port *port;
	unsigned long flags;
	uint8_t irsel;

	port = &siu_uart_ports[0];

	spin_lock_irqsave(&port->lock, flags);

	irsel = siu_read(port, SIUIRSEL);
	if (interface == SIU_INTERFACE_IRDA)
		irsel |= SIRSEL;
	else
		irsel &= ~SIRSEL;
	siu_write(port, SIUIRSEL, irsel);

	spin_unlock_irqrestore(&port->lock, flags);
}

void vr41xx_use_irda(irda_use_t use)
{
	struct uart_port *port;
	unsigned long flags;
	uint8_t irsel;

	port = &siu_uart_ports[0];

	spin_lock_irqsave(&port->lock, flags);

	irsel = siu_read(port, SIUIRSEL);
	if (use == FIR_USE_IRDA)
		irsel |= IRUSESEL;
	else
		irsel &= ~IRUSESEL;
	siu_write(port, SIUIRSEL, irsel);

	spin_unlock_irqrestore(&port->lock, flags);
}

void vr41xx_select_irda_module(irda_module_t module, irda_speed_t speed)
{
	struct uart_port *port;
	unsigned long flags;
	uint8_t irsel;

	port = &siu_uart_ports[0];

	spin_lock_irqsave(&port->lock, flags);

	irsel = siu_read(port, SIUIRSEL);
	irsel &= ~(IRMSEL | TMICTX | TMICMODE);
	switch (module) {
	case SHARP_IRDA:
		irsel |= IRMSEL_SHARP;
		break;
	case TEMIC_IRDA:
		irsel |= IRMSEL_TEMIC | TMICMODE;
		if (speed == IRDA_TX_4MBPS)
			irsel |= TMICTX;
		break;
	case HP_IRDA:
		irsel |= IRMSEL_HP;
		break;
	default:
		break;
	}
	siu_write(port, SIUIRSEL, irsel);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static inline void siu_clear_fifo(struct uart_port *port)
{
	siu_write(port, UART_FCR, UART_FCR_ENABLE_FIFO);
	siu_write(port, UART_FCR, UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR |
	                          UART_FCR_CLEAR_XMIT);
	siu_write(port, UART_FCR, 0);
}

__attribute__((used)) static inline unsigned long siu_port_size(struct uart_port *port)
{
	switch (port->type) {
	case PORT_VR41XX_SIU:
		return 11UL;
	case PORT_VR41XX_DSIU:
		return 8UL;
	}

	return 0;
}

__attribute__((used)) static inline unsigned int siu_check_type(struct uart_port *port)
{
	if (port->line == 0)
		return PORT_VR41XX_SIU;
	if (port->line == 1 && port->irq)
		return PORT_VR41XX_DSIU;

	return PORT_UNKNOWN;
}

__attribute__((used)) static inline const char *siu_type_name(struct uart_port *port)
{
	switch (port->type) {
	case PORT_VR41XX_SIU:
		return "SIU";
	case PORT_VR41XX_DSIU:
		return "DSIU";
	}

	return NULL;
}

__attribute__((used)) static unsigned int siu_tx_empty(struct uart_port *port)
{
	uint8_t lsr;

	lsr = siu_read(port, UART_LSR);
	if (lsr & UART_LSR_TEMT)
		return TIOCSER_TEMT;

	return 0;
}

__attribute__((used)) static void siu_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	uint8_t mcr = 0;

	if (mctrl & TIOCM_DTR)
		mcr |= UART_MCR_DTR;
	if (mctrl & TIOCM_RTS)
		mcr |= UART_MCR_RTS;
	if (mctrl & TIOCM_OUT1)
		mcr |= UART_MCR_OUT1;
	if (mctrl & TIOCM_OUT2)
		mcr |= UART_MCR_OUT2;
	if (mctrl & TIOCM_LOOP)
		mcr |= UART_MCR_LOOP;

	siu_write(port, UART_MCR, mcr);
}

__attribute__((used)) static unsigned int siu_get_mctrl(struct uart_port *port)
{
	uint8_t msr;
	unsigned int mctrl = 0;

	msr = siu_read(port, UART_MSR);
	if (msr & UART_MSR_DCD)
		mctrl |= TIOCM_CAR;
	if (msr & UART_MSR_RI)
		mctrl |= TIOCM_RNG;
	if (msr & UART_MSR_DSR)
		mctrl |= TIOCM_DSR;
	if (msr & UART_MSR_CTS)
		mctrl |= TIOCM_CTS;

	return mctrl;
}

__attribute__((used)) static void siu_stop_tx(struct uart_port *port)
{
	unsigned long flags;
	uint8_t ier;

	spin_lock_irqsave(&port->lock, flags);

	ier = siu_read(port, UART_IER);
	ier &= ~UART_IER_THRI;
	siu_write(port, UART_IER, ier);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void siu_start_tx(struct uart_port *port)
{
	unsigned long flags;
	uint8_t ier;

	spin_lock_irqsave(&port->lock, flags);

	ier = siu_read(port, UART_IER);
	ier |= UART_IER_THRI;
	siu_write(port, UART_IER, ier);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void siu_stop_rx(struct uart_port *port)
{
	unsigned long flags;
	uint8_t ier;

	spin_lock_irqsave(&port->lock, flags);

	ier = siu_read(port, UART_IER);
	ier &= ~UART_IER_RLSI;
	siu_write(port, UART_IER, ier);

	port->read_status_mask &= ~UART_LSR_DR;

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void siu_enable_ms(struct uart_port *port)
{
	unsigned long flags;
	uint8_t ier;

	spin_lock_irqsave(&port->lock, flags);

	ier = siu_read(port, UART_IER);
	ier |= UART_IER_MSI;
	siu_write(port, UART_IER, ier);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void siu_break_ctl(struct uart_port *port, int ctl)
{
	unsigned long flags;
	uint8_t lcr;

	spin_lock_irqsave(&port->lock, flags);

	lcr = siu_read(port, UART_LCR);
	if (ctl == -1)
		lcr |= UART_LCR_SBC;
	else
		lcr &= ~UART_LCR_SBC;
	siu_write(port, UART_LCR, lcr);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static inline void receive_chars(struct uart_port *port, uint8_t *status)
{
	uint8_t lsr, ch;
	char flag;
	int max_count = RX_MAX_COUNT;

	lsr = *status;

	do {
		ch = siu_read(port, UART_RX);
		port->icount.rx++;
		flag = TTY_NORMAL;

#ifdef CONFIG_SERIAL_VR41XX_CONSOLE
		lsr |= lsr_break_flag[port->line];
		lsr_break_flag[port->line] = 0;
#endif
		if (unlikely(lsr & (UART_LSR_BI | UART_LSR_FE |
		                    UART_LSR_PE | UART_LSR_OE))) {
			if (lsr & UART_LSR_BI) {
				lsr &= ~(UART_LSR_FE | UART_LSR_PE);
				port->icount.brk++;

				if (uart_handle_break(port))
					goto ignore_char;
			}

			if (lsr & UART_LSR_FE)
				port->icount.frame++;
			if (lsr & UART_LSR_PE)
				port->icount.parity++;
			if (lsr & UART_LSR_OE)
				port->icount.overrun++;

			lsr &= port->read_status_mask;
			if (lsr & UART_LSR_BI)
				flag = TTY_BREAK;
			if (lsr & UART_LSR_FE)
				flag = TTY_FRAME;
			if (lsr & UART_LSR_PE)
				flag = TTY_PARITY;
		}

		if (uart_handle_sysrq_char(port, ch))
			goto ignore_char;

		uart_insert_char(port, lsr, UART_LSR_OE, ch, flag);

	ignore_char:
		lsr = siu_read(port, UART_LSR);
	} while ((lsr & UART_LSR_DR) && (max_count-- > 0));

	tty_flip_buffer_push(&port->state->port);

	*status = lsr;
}

__attribute__((used)) static inline void check_modem_status(struct uart_port *port)
{
	uint8_t msr;

	msr = siu_read(port, UART_MSR);
	if ((msr & UART_MSR_ANY_DELTA) == 0)
		return;
	if (msr & UART_MSR_DDCD)
		uart_handle_dcd_change(port, msr & UART_MSR_DCD);
	if (msr & UART_MSR_TERI)
		port->icount.rng++;
	if (msr & UART_MSR_DDSR)
		port->icount.dsr++;
	if (msr & UART_MSR_DCTS)
		uart_handle_cts_change(port, msr & UART_MSR_CTS);

	wake_up_interruptible(&port->state->port.delta_msr_wait);
}

__attribute__((used)) static inline void transmit_chars(struct uart_port *port)
{
	struct circ_buf *xmit;
	int max_count = TX_MAX_COUNT;

	xmit = &port->state->xmit;

	if (port->x_char) {
		siu_write(port, UART_TX, port->x_char);
		port->icount.tx++;
		port->x_char = 0;
		return;
	}

	if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
		siu_stop_tx(port);
		return;
	}

	do {
		siu_write(port, UART_TX, xmit->buf[xmit->tail]);
		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		port->icount.tx++;
		if (uart_circ_empty(xmit))
			break;
	} while (max_count-- > 0);

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

	if (uart_circ_empty(xmit))
		siu_stop_tx(port);
}

__attribute__((used)) static irqreturn_t siu_interrupt(int irq, void *dev_id)
{
	struct uart_port *port;
	uint8_t iir, lsr;

	port = (struct uart_port *)dev_id;

	iir = siu_read(port, UART_IIR);
	if (iir & UART_IIR_NO_INT)
		return IRQ_NONE;

	lsr = siu_read(port, UART_LSR);
	if (lsr & UART_LSR_DR)
		receive_chars(port, &lsr);

	check_modem_status(port);

	if (lsr & UART_LSR_THRE)
		transmit_chars(port);

	return IRQ_HANDLED;
}

__attribute__((used)) static int siu_startup(struct uart_port *port)
{
	int retval;

	if (port->membase == NULL)
		return -ENODEV;

	siu_clear_fifo(port);

	(void)siu_read(port, UART_LSR);
	(void)siu_read(port, UART_RX);
	(void)siu_read(port, UART_IIR);
	(void)siu_read(port, UART_MSR);

	if (siu_read(port, UART_LSR) == 0xff)
		return -ENODEV;

	retval = request_irq(port->irq, siu_interrupt, 0, siu_type_name(port), port);
	if (retval)
		return retval;

	if (port->type == PORT_VR41XX_DSIU)
		vr41xx_enable_dsiuint(DSIUINT_ALL);

	siu_write(port, UART_LCR, UART_LCR_WLEN8);

	spin_lock_irq(&port->lock);
	siu_set_mctrl(port, port->mctrl);
	spin_unlock_irq(&port->lock);

	siu_write(port, UART_IER, UART_IER_RLSI | UART_IER_RDI);

	(void)siu_read(port, UART_LSR);
	(void)siu_read(port, UART_RX);
	(void)siu_read(port, UART_IIR);
	(void)siu_read(port, UART_MSR);

	return 0;
}

__attribute__((used)) static void siu_shutdown(struct uart_port *port)
{
	unsigned long flags;
	uint8_t lcr;

	siu_write(port, UART_IER, 0);

	spin_lock_irqsave(&port->lock, flags);

	port->mctrl &= ~TIOCM_OUT2;
	siu_set_mctrl(port, port->mctrl);

	spin_unlock_irqrestore(&port->lock, flags);

	lcr = siu_read(port, UART_LCR);
	lcr &= ~UART_LCR_SBC;
	siu_write(port, UART_LCR, lcr);

	siu_clear_fifo(port);

	(void)siu_read(port, UART_RX);

	if (port->type == PORT_VR41XX_DSIU)
		vr41xx_disable_dsiuint(DSIUINT_ALL);

	free_irq(port->irq, port);
}

__attribute__((used)) static void siu_set_termios(struct uart_port *port, struct ktermios *new,
                            struct ktermios *old)
{
	tcflag_t c_cflag, c_iflag;
	uint8_t lcr, fcr, ier;
	unsigned int baud, quot;
	unsigned long flags;

	c_cflag = new->c_cflag;
	switch (c_cflag & CSIZE) {
	case CS5:
		lcr = UART_LCR_WLEN5;
		break;
	case CS6:
		lcr = UART_LCR_WLEN6;
		break;
	case CS7:
		lcr = UART_LCR_WLEN7;
		break;
	default:
		lcr = UART_LCR_WLEN8;
		break;
	}

	if (c_cflag & CSTOPB)
		lcr |= UART_LCR_STOP;
	if (c_cflag & PARENB)
		lcr |= UART_LCR_PARITY;
	if ((c_cflag & PARODD) != PARODD)
		lcr |= UART_LCR_EPAR;
	if (c_cflag & CMSPAR)
		lcr |= UART_LCR_SPAR;

	baud = uart_get_baud_rate(port, new, old, 0, port->uartclk/16);
	quot = uart_get_divisor(port, baud);

	fcr = UART_FCR_ENABLE_FIFO | UART_FCR_R_TRIG_10;

	spin_lock_irqsave(&port->lock, flags);

	uart_update_timeout(port, c_cflag, baud);

	c_iflag = new->c_iflag;

	port->read_status_mask = UART_LSR_THRE | UART_LSR_OE | UART_LSR_DR;
	if (c_iflag & INPCK)
		port->read_status_mask |= UART_LSR_FE | UART_LSR_PE;
	if (c_iflag & (IGNBRK | BRKINT | PARMRK))
		port->read_status_mask |= UART_LSR_BI;

	port->ignore_status_mask = 0;
	if (c_iflag & IGNPAR)
		port->ignore_status_mask |= UART_LSR_FE | UART_LSR_PE;
	if (c_iflag & IGNBRK) {
		port->ignore_status_mask |= UART_LSR_BI;
		if (c_iflag & IGNPAR)
			port->ignore_status_mask |= UART_LSR_OE;
	}

	if ((c_cflag & CREAD) == 0)
		port->ignore_status_mask |= UART_LSR_DR;

	ier = siu_read(port, UART_IER);
	ier &= ~UART_IER_MSI;
	if (UART_ENABLE_MS(port, c_cflag))
		ier |= UART_IER_MSI;
	siu_write(port, UART_IER, ier);

	siu_write(port, UART_LCR, lcr | UART_LCR_DLAB);

	siu_write(port, UART_DLL, (uint8_t)quot);
	siu_write(port, UART_DLM, (uint8_t)(quot >> 8));

	siu_write(port, UART_LCR, lcr);

	siu_write(port, UART_FCR, fcr);

	siu_set_mctrl(port, port->mctrl);

	spin_unlock_irqrestore(&port->lock, flags);
}

__attribute__((used)) static void siu_pm(struct uart_port *port, unsigned int state, unsigned int oldstate)
{
	switch (state) {
	case 0:
		switch (port->type) {
		case PORT_VR41XX_SIU:
			vr41xx_supply_clock(SIU_CLOCK);
			break;
		case PORT_VR41XX_DSIU:
			vr41xx_supply_clock(DSIU_CLOCK);
			break;
		}
		break;
	case 3:
		switch (port->type) {
		case PORT_VR41XX_SIU:
			vr41xx_mask_clock(SIU_CLOCK);
			break;
		case PORT_VR41XX_DSIU:
			vr41xx_mask_clock(DSIU_CLOCK);
			break;
		}
		break;
	}
}

__attribute__((used)) static const char *siu_type(struct uart_port *port)
{
	return siu_type_name(port);
}

__attribute__((used)) static void siu_release_port(struct uart_port *port)
{
	unsigned long size;

	if (port->flags	& UPF_IOREMAP) {
		iounmap(port->membase);
		port->membase = NULL;
	}

	size = siu_port_size(port);
	release_mem_region(port->mapbase, size);
}

__attribute__((used)) static int siu_request_port(struct uart_port *port)
{
	unsigned long size;
	struct resource *res;

	size = siu_port_size(port);
	res = request_mem_region(port->mapbase, size, siu_type_name(port));
	if (res == NULL)
		return -EBUSY;

	if (port->flags & UPF_IOREMAP) {
		port->membase = ioremap(port->mapbase, size);
		if (port->membase == NULL) {
			release_resource(res);
			return -ENOMEM;
		}
	}

	return 0;
}

__attribute__((used)) static void siu_config_port(struct uart_port *port, int flags)
{
	if (flags & UART_CONFIG_TYPE) {
		port->type = siu_check_type(port);
		(void)siu_request_port(port);
	}
}

__attribute__((used)) static int siu_verify_port(struct uart_port *port, struct serial_struct *serial)
{
	if (port->type != PORT_VR41XX_SIU && port->type != PORT_VR41XX_DSIU)
		return -EINVAL;
	if (port->irq != serial->irq)
		return -EINVAL;
	if (port->iotype != serial->io_type)
		return -EINVAL;
	if (port->mapbase != (unsigned long)serial->iomem_base)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int siu_init_ports(struct platform_device *pdev)
{
	struct uart_port *port;
	struct resource *res;
	int *type = dev_get_platdata(&pdev->dev);
	int i;

	if (!type)
		return 0;

	port = siu_uart_ports;
	for (i = 0; i < SIU_PORTS_MAX; i++) {
		port->type = type[i];
		if (port->type == PORT_UNKNOWN)
			continue;
		port->irq = platform_get_irq(pdev, i);
		port->uartclk = SIU_BAUD_BASE * 16;
		port->fifosize = 16;
		port->regshift = 0;
		port->iotype = UPIO_MEM;
		port->flags = UPF_IOREMAP | UPF_BOOT_AUTOCONF;
		port->line = i;
		res = platform_get_resource(pdev, IORESOURCE_MEM, i);
		port->mapbase = res->start;
		port++;
	}

	return i;
}

__attribute__((used)) static int siu_probe(struct platform_device *dev)
{
	struct uart_port *port;
	int num, i, retval;

	num = siu_init_ports(dev);
	if (num <= 0)
		return -ENODEV;

	siu_uart_driver.nr = num;
	retval = uart_register_driver(&siu_uart_driver);
	if (retval)
		return retval;

	for (i = 0; i < num; i++) {
		port = &siu_uart_ports[i];
		port->ops = &siu_uart_ops;
		port->dev = &dev->dev;

		retval = uart_add_one_port(&siu_uart_driver, port);
		if (retval < 0) {
			port->dev = NULL;
			break;
		}
	}

	if (i == 0 && retval < 0) {
		uart_unregister_driver(&siu_uart_driver);
		return retval;
	}

	return 0;
}

__attribute__((used)) static int siu_remove(struct platform_device *dev)
{
	struct uart_port *port;
	int i;

	for (i = 0; i < siu_uart_driver.nr; i++) {
		port = &siu_uart_ports[i];
		if (port->dev == &dev->dev) {
			uart_remove_one_port(&siu_uart_driver, port);
			port->dev = NULL;
		}
	}

	uart_unregister_driver(&siu_uart_driver);

	return 0;
}

__attribute__((used)) static int siu_suspend(struct platform_device *dev, pm_message_t state)
{
	struct uart_port *port;
	int i;

	for (i = 0; i < siu_uart_driver.nr; i++) {
		port = &siu_uart_ports[i];
		if ((port->type == PORT_VR41XX_SIU ||
		     port->type == PORT_VR41XX_DSIU) && port->dev == &dev->dev)
			uart_suspend_port(&siu_uart_driver, port);

	}

	return 0;
}

__attribute__((used)) static int siu_resume(struct platform_device *dev)
{
	struct uart_port *port;
	int i;

	for (i = 0; i < siu_uart_driver.nr; i++) {
		port = &siu_uart_ports[i];
		if ((port->type == PORT_VR41XX_SIU ||
		     port->type == PORT_VR41XX_DSIU) && port->dev == &dev->dev)
			uart_resume_port(&siu_uart_driver, port);
	}

	return 0;
}


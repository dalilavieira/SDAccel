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
typedef  int u16 ;
struct TYPE_8__ {int /*<<< orphan*/  tx; int /*<<< orphan*/  overrun; int /*<<< orphan*/  frame; int /*<<< orphan*/  parity; int /*<<< orphan*/  rx; } ;
struct uart_port {unsigned int read_status_mask; unsigned int ignore_status_mask; int uartclk; scalar_t__ type; scalar_t__ membase; int /*<<< orphan*/  dev; int /*<<< orphan*/  line; TYPE_2__ icount; int /*<<< orphan*/  irq; scalar_t__ x_char; TYPE_1__* state; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {int id; struct device dev; } ;
struct mctrl_gpios {int dummy; } ;
struct ktermios {scalar_t__ c_line; int c_cflag; int c_iflag; } ;
typedef  struct mctrl_gpios gpio_desc ;
struct device_node {int dummy; } ;
struct TYPE_9__ {int irq; int line; int fifosize; int flags; int /*<<< orphan*/ * ops; int /*<<< orphan*/  uartclk; scalar_t__ type; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  iotype; struct device* dev; struct mctrl_gpios* membase; } ;
struct clps711x_port {int tx_enabled; int rx_irq; TYPE_3__ port; struct mctrl_gpios* syscon; struct mctrl_gpios* gpios; } ;
typedef  struct mctrl_gpios clk ;
struct circ_buf {size_t tail; scalar_t__* buf; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum mctrl_gpio_idx { ____Placeholder_mctrl_gpio_idx } mctrl_gpio_idx ;
struct TYPE_7__ {struct circ_buf xmit; int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int BRKINT ; 
 int CMSPAR ; 
 int CREAD ; 
#define  CS5 131 
#define  CS6 130 
#define  CS7 129 
#define  CS8 128 
 int CSIZE ; 
 int CSTOPB ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ENOSYS ; 
 struct mctrl_gpios* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IGNBRK ; 
 int INPCK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct mctrl_gpios*) ; 
 scalar_t__ N_IRDA ; 
 int PARENB ; 
 int PARODD ; 
 scalar_t__ PORT_CLPS711X ; 
 int PTR_ERR (struct mctrl_gpios*) ; 
 int /*<<< orphan*/  SYSCON1_SIREN ; 
 int /*<<< orphan*/  SYSCON_OFFSET ; 
 int /*<<< orphan*/  SYSCON_UARTEN ; 
 int /*<<< orphan*/  SYSFLG_OFFSET ; 
 int SYSFLG_UBUSY ; 
 int SYSFLG_URXFE ; 
 int SYSFLG_UTXFF ; 
 int TIOCM_CAR ; 
 int TIOCM_CTS ; 
 int TIOCM_DSR ; 
 unsigned int TIOCSER_TEMT ; 
 unsigned int TTY_FRAME ; 
 unsigned int TTY_NORMAL ; 
 unsigned int TTY_OVERRUN ; 
 unsigned int TTY_PARITY ; 
 int UARTDR_FRMERR ; 
 scalar_t__ UARTDR_OFFSET ; 
 int UARTDR_OVERR ; 
 int UARTDR_PARERR ; 
 int UART_CLPS711X_NR ; 
 int UART_CONFIG_TYPE ; 
 int UART_XMIT_SIZE ; 
 unsigned int UBRLCR_BREAK ; 
 int UBRLCR_EVENPRT ; 
 int UBRLCR_FIFOEN ; 
 scalar_t__ UBRLCR_OFFSET ; 
 int UBRLCR_PRTEN ; 
 int UBRLCR_WRDLEN5 ; 
 int UBRLCR_WRDLEN6 ; 
 int UBRLCR_WRDLEN7 ; 
 int UBRLCR_WRDLEN8 ; 
 int UBRLCR_XSTOP ; 
 int UPF_FIXED_TYPE ; 
 int UPF_SKIP_TEST ; 
 int /*<<< orphan*/  UPIO_MEM32 ; 
 scalar_t__ WAKEUP_CHARS ; 
 int /*<<< orphan*/  clk_get_rate (struct mctrl_gpios*) ; 
 int /*<<< orphan*/  clps711x_uart ; 
 struct clps711x_port* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct mctrl_gpios* devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 struct mctrl_gpios* devm_ioremap_resource (struct device*,struct resource*) ; 
 struct clps711x_port* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_irq_nosync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int of_alias_get_id (struct device_node*,char*) ; 
 struct clps711x_port* platform_get_drvdata (struct platform_device*) ; 
 void* platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct clps711x_port*) ; 
 unsigned int readl (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int /*<<< orphan*/  regmap_read (struct mctrl_gpios*,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (struct mctrl_gpios*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct mctrl_gpios* syscon_regmap_lookup_by_pdevname (char*) ; 
 struct mctrl_gpios* syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (int /*<<< orphan*/ *) ; 
 int uart_add_one_port (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ uart_circ_chars_pending (struct circ_buf*) ; 
 scalar_t__ uart_circ_empty (struct circ_buf*) ; 
 int /*<<< orphan*/  uart_clps711x_ops ; 
 int /*<<< orphan*/  uart_console (TYPE_3__*) ; 
 unsigned int uart_get_baud_rate (struct uart_port*,struct ktermios*,struct ktermios*,int,int) ; 
 unsigned int uart_get_divisor (struct uart_port*,unsigned int) ; 
 scalar_t__ uart_handle_sysrq_char (struct uart_port*,int) ; 
 int /*<<< orphan*/  uart_insert_char (struct uart_port*,unsigned int,int,int,unsigned int) ; 
 int uart_remove_one_port (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ uart_tx_stopped (struct uart_port*) ; 
 int /*<<< orphan*/  uart_update_timeout (struct uart_port*,int,unsigned int) ; 
 int /*<<< orphan*/  uart_write_wakeup (struct uart_port*) ; 
 scalar_t__ unlikely (unsigned int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline
void mctrl_gpio_set(struct mctrl_gpios *gpios, unsigned int mctrl)
{
}

__attribute__((used)) static inline
unsigned int mctrl_gpio_get(struct mctrl_gpios *gpios, unsigned int *mctrl)
{
	return *mctrl;
}

__attribute__((used)) static inline unsigned int
mctrl_gpio_get_outputs(struct mctrl_gpios *gpios, unsigned int *mctrl)
{
	return *mctrl;
}

__attribute__((used)) static inline
struct gpio_desc *mctrl_gpio_to_gpiod(struct mctrl_gpios *gpios,
				      enum mctrl_gpio_idx gidx)
{
	return ERR_PTR(-ENOSYS);
}

__attribute__((used)) static inline
struct mctrl_gpios *mctrl_gpio_init(struct uart_port *port, unsigned int idx)
{
	return ERR_PTR(-ENOSYS);
}

__attribute__((used)) static inline
struct mctrl_gpios *mctrl_gpio_init_noauto(struct device *dev, unsigned int idx)
{
	return ERR_PTR(-ENOSYS);
}

__attribute__((used)) static inline
void mctrl_gpio_free(struct device *dev, struct mctrl_gpios *gpios)
{
}

__attribute__((used)) static inline void mctrl_gpio_enable_ms(struct mctrl_gpios *gpios)
{
}

__attribute__((used)) static inline void mctrl_gpio_disable_ms(struct mctrl_gpios *gpios)
{
}

__attribute__((used)) static void uart_clps711x_stop_tx(struct uart_port *port)
{
	struct clps711x_port *s = dev_get_drvdata(port->dev);

	if (s->tx_enabled) {
		disable_irq(port->irq);
		s->tx_enabled = 0;
	}
}

__attribute__((used)) static void uart_clps711x_start_tx(struct uart_port *port)
{
	struct clps711x_port *s = dev_get_drvdata(port->dev);

	if (!s->tx_enabled) {
		s->tx_enabled = 1;
		enable_irq(port->irq);
	}
}

__attribute__((used)) static irqreturn_t uart_clps711x_int_rx(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	struct clps711x_port *s = dev_get_drvdata(port->dev);
	unsigned int status, flg;
	u16 ch;

	for (;;) {
		u32 sysflg = 0;

		regmap_read(s->syscon, SYSFLG_OFFSET, &sysflg);
		if (sysflg & SYSFLG_URXFE)
			break;

		ch = readw(port->membase + UARTDR_OFFSET);
		status = ch & (UARTDR_FRMERR | UARTDR_PARERR | UARTDR_OVERR);
		ch &= 0xff;

		port->icount.rx++;
		flg = TTY_NORMAL;

		if (unlikely(status)) {
			if (status & UARTDR_PARERR)
				port->icount.parity++;
			else if (status & UARTDR_FRMERR)
				port->icount.frame++;
			else if (status & UARTDR_OVERR)
				port->icount.overrun++;

			status &= port->read_status_mask;

			if (status & UARTDR_PARERR)
				flg = TTY_PARITY;
			else if (status & UARTDR_FRMERR)
				flg = TTY_FRAME;
			else if (status & UARTDR_OVERR)
				flg = TTY_OVERRUN;
		}

		if (uart_handle_sysrq_char(port, ch))
			continue;

		if (status & port->ignore_status_mask)
			continue;

		uart_insert_char(port, status, UARTDR_OVERR, ch, flg);
	}

	tty_flip_buffer_push(&port->state->port);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t uart_clps711x_int_tx(int irq, void *dev_id)
{
	struct uart_port *port = dev_id;
	struct clps711x_port *s = dev_get_drvdata(port->dev);
	struct circ_buf *xmit = &port->state->xmit;

	if (port->x_char) {
		writew(port->x_char, port->membase + UARTDR_OFFSET);
		port->icount.tx++;
		port->x_char = 0;
		return IRQ_HANDLED;
	}

	if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
		if (s->tx_enabled) {
			disable_irq_nosync(port->irq);
			s->tx_enabled = 0;
		}
		return IRQ_HANDLED;
	}

	while (!uart_circ_empty(xmit)) {
		u32 sysflg = 0;

		writew(xmit->buf[xmit->tail], port->membase + UARTDR_OFFSET);
		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		port->icount.tx++;

		regmap_read(s->syscon, SYSFLG_OFFSET, &sysflg);
		if (sysflg & SYSFLG_UTXFF)
			break;
	}

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);

	return IRQ_HANDLED;
}

__attribute__((used)) static unsigned int uart_clps711x_tx_empty(struct uart_port *port)
{
	struct clps711x_port *s = dev_get_drvdata(port->dev);
	u32 sysflg = 0;

	regmap_read(s->syscon, SYSFLG_OFFSET, &sysflg);

	return (sysflg & SYSFLG_UBUSY) ? 0 : TIOCSER_TEMT;
}

__attribute__((used)) static unsigned int uart_clps711x_get_mctrl(struct uart_port *port)
{
	unsigned int result = TIOCM_DSR | TIOCM_CTS | TIOCM_CAR;
	struct clps711x_port *s = dev_get_drvdata(port->dev);

	return mctrl_gpio_get(s->gpios, &result);
}

__attribute__((used)) static void uart_clps711x_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	struct clps711x_port *s = dev_get_drvdata(port->dev);

	mctrl_gpio_set(s->gpios, mctrl);
}

__attribute__((used)) static void uart_clps711x_break_ctl(struct uart_port *port, int break_state)
{
	unsigned int ubrlcr;

	ubrlcr = readl(port->membase + UBRLCR_OFFSET);
	if (break_state)
		ubrlcr |= UBRLCR_BREAK;
	else
		ubrlcr &= ~UBRLCR_BREAK;
	writel(ubrlcr, port->membase + UBRLCR_OFFSET);
}

__attribute__((used)) static void uart_clps711x_set_ldisc(struct uart_port *port,
				    struct ktermios *termios)
{
	if (!port->line) {
		struct clps711x_port *s = dev_get_drvdata(port->dev);

		regmap_update_bits(s->syscon, SYSCON_OFFSET, SYSCON1_SIREN,
				   (termios->c_line == N_IRDA) ? SYSCON1_SIREN : 0);
	}
}

__attribute__((used)) static int uart_clps711x_startup(struct uart_port *port)
{
	struct clps711x_port *s = dev_get_drvdata(port->dev);

	/* Disable break */
	writel(readl(port->membase + UBRLCR_OFFSET) & ~UBRLCR_BREAK,
	       port->membase + UBRLCR_OFFSET);

	/* Enable the port */
	return regmap_update_bits(s->syscon, SYSCON_OFFSET,
				  SYSCON_UARTEN, SYSCON_UARTEN);
}

__attribute__((used)) static void uart_clps711x_shutdown(struct uart_port *port)
{
	struct clps711x_port *s = dev_get_drvdata(port->dev);

	/* Disable the port */
	regmap_update_bits(s->syscon, SYSCON_OFFSET, SYSCON_UARTEN, 0);
}

__attribute__((used)) static void uart_clps711x_set_termios(struct uart_port *port,
				      struct ktermios *termios,
				      struct ktermios *old)
{
	u32 ubrlcr;
	unsigned int baud, quot;

	/* Mask termios capabilities we don't support */
	termios->c_cflag &= ~CMSPAR;
	termios->c_iflag &= ~(BRKINT | IGNBRK);

	/* Ask the core to calculate the divisor for us */
	baud = uart_get_baud_rate(port, termios, old, port->uartclk / 4096,
						      port->uartclk / 16);
	quot = uart_get_divisor(port, baud);

	switch (termios->c_cflag & CSIZE) {
	case CS5:
		ubrlcr = UBRLCR_WRDLEN5;
		break;
	case CS6:
		ubrlcr = UBRLCR_WRDLEN6;
		break;
	case CS7:
		ubrlcr = UBRLCR_WRDLEN7;
		break;
	case CS8:
	default:
		ubrlcr = UBRLCR_WRDLEN8;
		break;
	}

	if (termios->c_cflag & CSTOPB)
		ubrlcr |= UBRLCR_XSTOP;

	if (termios->c_cflag & PARENB) {
		ubrlcr |= UBRLCR_PRTEN;
		if (!(termios->c_cflag & PARODD))
			ubrlcr |= UBRLCR_EVENPRT;
	}

	/* Enable FIFO */
	ubrlcr |= UBRLCR_FIFOEN;

	/* Set read status mask */
	port->read_status_mask = UARTDR_OVERR;
	if (termios->c_iflag & INPCK)
		port->read_status_mask |= UARTDR_PARERR | UARTDR_FRMERR;

	/* Set status ignore mask */
	port->ignore_status_mask = 0;
	if (!(termios->c_cflag & CREAD))
		port->ignore_status_mask |= UARTDR_OVERR | UARTDR_PARERR |
					    UARTDR_FRMERR;

	uart_update_timeout(port, termios->c_cflag, baud);

	writel(ubrlcr | (quot - 1), port->membase + UBRLCR_OFFSET);
}

__attribute__((used)) static const char *uart_clps711x_type(struct uart_port *port)
{
	return (port->type == PORT_CLPS711X) ? "CLPS711X" : NULL;
}

__attribute__((used)) static void uart_clps711x_config_port(struct uart_port *port, int flags)
{
	if (flags & UART_CONFIG_TYPE)
		port->type = PORT_CLPS711X;
}

__attribute__((used)) static void uart_clps711x_nop_void(struct uart_port *port)
{
}

__attribute__((used)) static int uart_clps711x_nop_int(struct uart_port *port)
{
	return 0;
}

__attribute__((used)) static int uart_clps711x_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	int ret, index = np ? of_alias_get_id(np, "serial") : pdev->id;
	struct clps711x_port *s;
	struct resource *res;
	struct clk *uart_clk;
	int irq;

	if (index < 0 || index >= UART_CLPS711X_NR)
		return -EINVAL;

	s = devm_kzalloc(&pdev->dev, sizeof(*s), GFP_KERNEL);
	if (!s)
		return -ENOMEM;

	uart_clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(uart_clk))
		return PTR_ERR(uart_clk);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	s->port.membase = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(s->port.membase))
		return PTR_ERR(s->port.membase);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;
	s->port.irq = irq;

	s->rx_irq = platform_get_irq(pdev, 1);
	if (s->rx_irq < 0)
		return s->rx_irq;

	if (!np) {
		char syscon_name[9];

		sprintf(syscon_name, "syscon.%i", index + 1);
		s->syscon = syscon_regmap_lookup_by_pdevname(syscon_name);
		if (IS_ERR(s->syscon))
			return PTR_ERR(s->syscon);
	} else {
		s->syscon = syscon_regmap_lookup_by_phandle(np, "syscon");
		if (IS_ERR(s->syscon))
			return PTR_ERR(s->syscon);
	}

	s->port.line		= index;
	s->port.dev		= &pdev->dev;
	s->port.iotype		= UPIO_MEM32;
	s->port.mapbase		= res->start;
	s->port.type		= PORT_CLPS711X;
	s->port.fifosize	= 16;
	s->port.flags		= UPF_SKIP_TEST | UPF_FIXED_TYPE;
	s->port.uartclk		= clk_get_rate(uart_clk);
	s->port.ops		= &uart_clps711x_ops;

	platform_set_drvdata(pdev, s);

	s->gpios = mctrl_gpio_init_noauto(&pdev->dev, 0);
	if (IS_ERR(s->gpios))
	    return PTR_ERR(s->gpios);

	ret = uart_add_one_port(&clps711x_uart, &s->port);
	if (ret)
		return ret;

	/* Disable port */
	if (!uart_console(&s->port))
		regmap_update_bits(s->syscon, SYSCON_OFFSET, SYSCON_UARTEN, 0);

	s->tx_enabled = 1;

	ret = devm_request_irq(&pdev->dev, s->port.irq, uart_clps711x_int_tx, 0,
			       dev_name(&pdev->dev), &s->port);
	if (ret) {
		uart_remove_one_port(&clps711x_uart, &s->port);
		return ret;
	}

	ret = devm_request_irq(&pdev->dev, s->rx_irq, uart_clps711x_int_rx, 0,
			       dev_name(&pdev->dev), &s->port);
	if (ret)
		uart_remove_one_port(&clps711x_uart, &s->port);

	return ret;
}

__attribute__((used)) static int uart_clps711x_remove(struct platform_device *pdev)
{
	struct clps711x_port *s = platform_get_drvdata(pdev);

	return uart_remove_one_port(&clps711x_uart, &s->port);
}


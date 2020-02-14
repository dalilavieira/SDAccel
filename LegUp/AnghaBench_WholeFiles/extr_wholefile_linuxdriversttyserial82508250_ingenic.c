#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct uart_port {int (* serial_in ) (struct uart_port*,int) ;void (* serial_out ) (struct uart_port*,int,int) ;int minor; int regshift; int flags; int line; int /*<<< orphan*/  uartclk; scalar_t__ membase; int /*<<< orphan*/  fifosize; TYPE_1__* dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  iotype; int /*<<< orphan*/  type; int /*<<< orphan*/  lock; } ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;int capabilities; struct uart_port port; int /*<<< orphan*/  tx_loadsz; int /*<<< orphan*/  (* dl_write ) (struct uart_8250_port*,int) ;} ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_device_id {struct ingenic_uart_config* data; } ;
struct ingenic_uart_data {int line; void* clk_baud; void* clk_module; } ;
struct ingenic_uart_config {int /*<<< orphan*/  tx_loadsz; int /*<<< orphan*/  fifosize; } ;
struct console {int dummy; } ;
typedef  int status ;
struct TYPE_8__ {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (void*) ; 
 int /*<<< orphan*/  PORT_16550A ; 
 int PTR_ERR (void*) ; 
 int UART_CAP_FIFO ; 
 int UART_CAP_RTOIE ; 
#define  UART_FCR 130 
 int UART_FCR_UME ; 
#define  UART_IER 129 
 int UART_IER_MSI ; 
 int UART_LSR ; 
 int UART_LSR_TEMT ; 
#define  UART_MCR 128 
 int UART_MCR_FCM ; 
 int UART_MCR_MDCE ; 
 int UART_TX ; 
 int UPF_FIXED_TYPE ; 
 int UPF_IOREMAP ; 
 int UPF_SKIP_TEST ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int /*<<< orphan*/  clk_get_rate (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 void* devm_clk_get (TYPE_1__*,char*) ; 
 scalar_t__ devm_ioremap (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ingenic_uart_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 TYPE_2__* early_device ; 
 int of_alias_get_id (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  of_match ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 struct ingenic_uart_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ingenic_uart_data*) ; 
 unsigned int readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int serial8250_register_8250_port (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int stub1 (struct uart_port*,int) ; 
 void stub2 (struct uart_port*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 int /*<<< orphan*/  stub4 (struct uart_8250_port*,int) ; 
 int stub5 (struct uart_port*,int const) ; 
 int /*<<< orphan*/  uart_console_write (int /*<<< orphan*/ *,char const*,unsigned int,void (*) (struct uart_port*,int)) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

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

__attribute__((used)) static uint8_t early_in(struct uart_port *port, int offset)
{
	return readl(port->membase + (offset << 2));
}

__attribute__((used)) static void early_out(struct uart_port *port, int offset, uint8_t value)
{
	writel(value, port->membase + (offset << 2));
}

__attribute__((used)) static void ingenic_early_console_putc(struct uart_port *port, int c)
{
	uint8_t lsr;

	do {
		lsr = early_in(port, UART_LSR);
	} while ((lsr & UART_LSR_TEMT) == 0);

	early_out(port, UART_TX, c);
}

__attribute__((used)) static void ingenic_early_console_write(struct console *console,
					      const char *s, unsigned int count)
{
	uart_console_write(&early_device->port, s, count,
			   ingenic_early_console_putc);
}

__attribute__((used)) static void ingenic_uart_serial_out(struct uart_port *p, int offset, int value)
{
	int ier;

	switch (offset) {
	case UART_FCR:
		/* UART module enable */
		value |= UART_FCR_UME;
		break;

	case UART_IER:
		/*
		 * Enable receive timeout interrupt with the receive line
		 * status interrupt.
		 */
		value |= (value & 0x4) << 2;
		break;

	case UART_MCR:
		/*
		 * If we have enabled modem status IRQs we should enable
		 * modem mode.
		 */
		ier = p->serial_in(p, UART_IER);

		if (ier & UART_IER_MSI)
			value |= UART_MCR_MDCE | UART_MCR_FCM;
		else
			value &= ~(UART_MCR_MDCE | UART_MCR_FCM);
		break;

	default:
		break;
	}

	writeb(value, p->membase + (offset << p->regshift));
}

__attribute__((used)) static unsigned int ingenic_uart_serial_in(struct uart_port *p, int offset)
{
	unsigned int value;

	value = readb(p->membase + (offset << p->regshift));

	/* Hide non-16550 compliant bits from higher levels */
	switch (offset) {
	case UART_FCR:
		value &= ~UART_FCR_UME;
		break;

	case UART_MCR:
		value &= ~(UART_MCR_MDCE | UART_MCR_FCM);
		break;

	default:
		break;
	}
	return value;
}

__attribute__((used)) static int ingenic_uart_probe(struct platform_device *pdev)
{
	struct uart_8250_port uart = {};
	struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	struct ingenic_uart_data *data;
	const struct ingenic_uart_config *cdata;
	const struct of_device_id *match;
	int err, line;

	match = of_match_device(of_match, &pdev->dev);
	if (!match) {
		dev_err(&pdev->dev, "Error: No device match found\n");
		return -ENODEV;
	}
	cdata = match->data;

	if (!regs || !irq) {
		dev_err(&pdev->dev, "no registers/irq defined\n");
		return -EINVAL;
	}

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	spin_lock_init(&uart.port.lock);
	uart.port.type = PORT_16550A;
	uart.port.flags = UPF_SKIP_TEST | UPF_IOREMAP | UPF_FIXED_TYPE;
	uart.port.iotype = UPIO_MEM;
	uart.port.mapbase = regs->start;
	uart.port.regshift = 2;
	uart.port.serial_out = ingenic_uart_serial_out;
	uart.port.serial_in = ingenic_uart_serial_in;
	uart.port.irq = irq->start;
	uart.port.dev = &pdev->dev;
	uart.port.fifosize = cdata->fifosize;
	uart.tx_loadsz = cdata->tx_loadsz;
	uart.capabilities = UART_CAP_FIFO | UART_CAP_RTOIE;

	/* Check for a fixed line number */
	line = of_alias_get_id(pdev->dev.of_node, "serial");
	if (line >= 0)
		uart.port.line = line;

	uart.port.membase = devm_ioremap(&pdev->dev, regs->start,
					 resource_size(regs));
	if (!uart.port.membase)
		return -ENOMEM;

	data->clk_module = devm_clk_get(&pdev->dev, "module");
	if (IS_ERR(data->clk_module)) {
		err = PTR_ERR(data->clk_module);
		if (err != -EPROBE_DEFER)
			dev_err(&pdev->dev,
				"unable to get module clock: %d\n", err);
		return err;
	}

	data->clk_baud = devm_clk_get(&pdev->dev, "baud");
	if (IS_ERR(data->clk_baud)) {
		err = PTR_ERR(data->clk_baud);
		if (err != -EPROBE_DEFER)
			dev_err(&pdev->dev,
				"unable to get baud clock: %d\n", err);
		return err;
	}

	err = clk_prepare_enable(data->clk_module);
	if (err) {
		dev_err(&pdev->dev, "could not enable module clock: %d\n", err);
		goto out;
	}

	err = clk_prepare_enable(data->clk_baud);
	if (err) {
		dev_err(&pdev->dev, "could not enable baud clock: %d\n", err);
		goto out_disable_moduleclk;
	}
	uart.port.uartclk = clk_get_rate(data->clk_baud);

	data->line = serial8250_register_8250_port(&uart);
	if (data->line < 0) {
		err = data->line;
		goto out_disable_baudclk;
	}

	platform_set_drvdata(pdev, data);
	return 0;

out_disable_baudclk:
	clk_disable_unprepare(data->clk_baud);
out_disable_moduleclk:
	clk_disable_unprepare(data->clk_module);
out:
	return err;
}

__attribute__((used)) static int ingenic_uart_remove(struct platform_device *pdev)
{
	struct ingenic_uart_data *data = platform_get_drvdata(pdev);

	serial8250_unregister_port(data->line);
	clk_disable_unprepare(data->clk_module);
	clk_disable_unprepare(data->clk_baud);
	return 0;
}


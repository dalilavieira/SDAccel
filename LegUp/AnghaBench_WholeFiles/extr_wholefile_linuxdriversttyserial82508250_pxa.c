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
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct uart_port {int minor; struct pxa8250_data* private_data; } ;
struct TYPE_5__ {int (* serial_in ) (TYPE_1__*,int) ;int line; int regshift; int fifosize; int flags; void (* pm ) (struct uart_port*,unsigned int,unsigned int) ;struct pxa8250_data* private_data; int /*<<< orphan*/  uartclk; TYPE_3__* dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  iotype; int /*<<< orphan*/  type; int /*<<< orphan*/  (* serial_out ) (TYPE_1__*,int,int) ;} ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;void (* dl_write ) (struct uart_8250_port*,int) ;TYPE_1__ port; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct pxa8250_data {int line; int /*<<< orphan*/  clk; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
typedef  int status ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PORT_XSCALE ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int UART_DLL ; 
 int UART_DLM ; 
 int UART_MCR ; 
 int UPF_IOREMAP ; 
 int UPF_SKIP_TEST ; 
 int /*<<< orphan*/  UPIO_MEM32 ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_get_rate (int /*<<< orphan*/ ) ; 
 int clk_prepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_3__*,int /*<<< orphan*/ *) ; 
 struct pxa8250_data* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int of_alias_get_id (int /*<<< orphan*/ ,char*) ; 
 struct pxa8250_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pxa8250_data*) ; 
 int serial8250_register_8250_port (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int) ; 
 int stub1 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 void stub4 (struct uart_8250_port*,int) ; 

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

__attribute__((used)) static void serial_pxa_dl_write(struct uart_8250_port *up, int value)
{
	unsigned int dll;

	serial_out(up, UART_DLL, value & 0xff);
	/*
	 * work around Erratum #74 according to Marvel(R) PXA270M Processor
	 * Specification Update (April 19, 2010)
	 */
	dll = serial_in(up, UART_DLL);
	WARN_ON(dll != (value & 0xff));

	serial_out(up, UART_DLM, value >> 8 & 0xff);
}

__attribute__((used)) static void serial_pxa_pm(struct uart_port *port, unsigned int state,
	      unsigned int oldstate)
{
	struct pxa8250_data *data = port->private_data;

	if (!state)
		clk_prepare_enable(data->clk);
	else
		clk_disable_unprepare(data->clk);
}

__attribute__((used)) static int serial_pxa_probe(struct platform_device *pdev)
{
	struct uart_8250_port uart = {};
	struct pxa8250_data *data;
	struct resource *mmres, *irqres;
	int ret;

	mmres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	irqres = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!mmres || !irqres)
		return -ENODEV;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(data->clk))
		return PTR_ERR(data->clk);

	ret = clk_prepare(data->clk);
	if (ret)
		return ret;

	ret = of_alias_get_id(pdev->dev.of_node, "serial");
	if (ret >= 0)
		uart.port.line = ret;

	uart.port.type = PORT_XSCALE;
	uart.port.iotype = UPIO_MEM32;
	uart.port.mapbase = mmres->start;
	uart.port.regshift = 2;
	uart.port.irq = irqres->start;
	uart.port.fifosize = 64;
	uart.port.flags = UPF_IOREMAP | UPF_SKIP_TEST;
	uart.port.dev = &pdev->dev;
	uart.port.uartclk = clk_get_rate(data->clk);
	uart.port.pm = serial_pxa_pm;
	uart.port.private_data = data;
	uart.dl_write = serial_pxa_dl_write;

	ret = serial8250_register_8250_port(&uart);
	if (ret < 0)
		goto err_clk;

	data->line = ret;

	platform_set_drvdata(pdev, data);

	return 0;

 err_clk:
	clk_unprepare(data->clk);
	return ret;
}

__attribute__((used)) static int serial_pxa_remove(struct platform_device *pdev)
{
	struct pxa8250_data *data = platform_get_drvdata(pdev);

	serial8250_unregister_port(data->line);

	clk_unprepare(data->clk);

	return 0;
}


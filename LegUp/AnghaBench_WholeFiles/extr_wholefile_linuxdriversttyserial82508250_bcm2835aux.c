#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct uart_port {int minor; } ;
struct TYPE_10__ {int (* serial_in ) (TYPE_2__*,int) ;int /*<<< orphan*/  (* serial_out ) (TYPE_2__*,int,int) ;} ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;int /*<<< orphan*/  (* dl_write ) (struct uart_8250_port*,int) ;TYPE_2__ port; } ;
struct resource {int dummy; } ;
struct TYPE_12__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_5__ dev; } ;
struct TYPE_9__ {int regshift; int fifosize; int flags; int irq; int line; int uartclk; int /*<<< orphan*/  membase; int /*<<< orphan*/  iotype; int /*<<< orphan*/  type; TYPE_5__* dev; int /*<<< orphan*/  lock; } ;
struct TYPE_11__ {int capabilities; TYPE_1__ port; } ;
struct bcm2835aux_data {int line; int /*<<< orphan*/  clk; TYPE_4__ uart; } ;
typedef  int status ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  PORT_16550 ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int UART_CAP_FIFO ; 
 int UART_CAP_MINI ; 
 int UART_MCR ; 
 int UPF_FIXED_PORT ; 
 int UPF_FIXED_TYPE ; 
 int UPF_SHARE_IRQ ; 
 int UPF_SKIP_TEST ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_get_rate (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_ioremap_resource (TYPE_5__*,struct resource*) ; 
 struct bcm2835aux_data* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int of_alias_get_id (int /*<<< orphan*/ ,char*) ; 
 struct bcm2835aux_data* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bcm2835aux_data*) ; 
 int serial8250_register_8250_port (TYPE_4__*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int stub1 (TYPE_2__*,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 int /*<<< orphan*/  stub4 (struct uart_8250_port*,int) ; 

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

__attribute__((used)) static int bcm2835aux_serial_probe(struct platform_device *pdev)
{
	struct bcm2835aux_data *data;
	struct resource *res;
	int ret;

	/* allocate the custom structure */
	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	/* initialize data */
	spin_lock_init(&data->uart.port.lock);
	data->uart.capabilities = UART_CAP_FIFO | UART_CAP_MINI;
	data->uart.port.dev = &pdev->dev;
	data->uart.port.regshift = 2;
	data->uart.port.type = PORT_16550;
	data->uart.port.iotype = UPIO_MEM;
	data->uart.port.fifosize = 8;
	data->uart.port.flags = UPF_SHARE_IRQ |
				UPF_FIXED_PORT |
				UPF_FIXED_TYPE |
				UPF_SKIP_TEST;

	/* get the clock - this also enables the HW */
	data->clk = devm_clk_get(&pdev->dev, NULL);
	ret = PTR_ERR_OR_ZERO(data->clk);
	if (ret) {
		if (ret != -EPROBE_DEFER)
			dev_err(&pdev->dev, "could not get clk: %d\n", ret);
		return ret;
	}

	/* get the interrupt */
	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		dev_err(&pdev->dev, "irq not found - %i", ret);
		return ret;
	}
	data->uart.port.irq = ret;

	/* map the main registers */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "memory resource not found");
		return -EINVAL;
	}
	data->uart.port.membase = devm_ioremap_resource(&pdev->dev, res);
	ret = PTR_ERR_OR_ZERO(data->uart.port.membase);
	if (ret)
		return ret;

	/* Check for a fixed line number */
	ret = of_alias_get_id(pdev->dev.of_node, "serial");
	if (ret >= 0)
		data->uart.port.line = ret;

	/* enable the clock as a last step */
	ret = clk_prepare_enable(data->clk);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable uart clock - %d\n",
			ret);
		return ret;
	}

	/* the HW-clock divider for bcm2835aux is 8,
	 * but 8250 expects a divider of 16,
	 * so we have to multiply the actual clock by 2
	 * to get identical baudrates.
	 */
	data->uart.port.uartclk = clk_get_rate(data->clk) * 2;

	/* register the port */
	ret = serial8250_register_8250_port(&data->uart);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to register 8250 port - %d\n",
			ret);
		goto dis_clk;
	}
	data->line = ret;

	platform_set_drvdata(pdev, data);

	return 0;

dis_clk:
	clk_disable_unprepare(data->clk);
	return ret;
}

__attribute__((used)) static int bcm2835aux_serial_remove(struct platform_device *pdev)
{
	struct bcm2835aux_data *data = platform_get_drvdata(pdev);

	serial8250_unregister_port(data->uart.port.line);
	clk_disable_unprepare(data->clk);

	return 0;
}


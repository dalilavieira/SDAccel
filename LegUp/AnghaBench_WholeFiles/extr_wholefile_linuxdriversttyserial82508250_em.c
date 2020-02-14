#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  up ;
struct uart_port {int (* serial_in ) (struct uart_port*,int) ;void (* serial_out ) (struct uart_port*,int,int) ;int minor; int flags; int /*<<< orphan*/  iotype; int /*<<< orphan*/  uartclk; struct serial8250_em_priv* private_data; int /*<<< orphan*/ * dev; int /*<<< orphan*/  type; int /*<<< orphan*/  irq; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  membase; } ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;void (* dl_write ) (struct uart_8250_port*,int) ;struct uart_port port; } ;
struct serial8250_em_priv {int line; int /*<<< orphan*/  sclk; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
typedef  int status ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PORT_UNKNOWN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  UART_DLL_EM 139 
#define  UART_DLM_EM 138 
#define  UART_FCR 137 
#define  UART_IER 136 
#define  UART_IIR 135 
#define  UART_LCR 134 
#define  UART_LSR 133 
#define  UART_MCR 132 
#define  UART_MSR 131 
#define  UART_RX 130 
#define  UART_SCR 129 
#define  UART_TX 128 
 int UPF_BOOT_AUTOCONF ; 
 int UPF_FIXED_PORT ; 
 int UPF_IOREMAP ; 
 int /*<<< orphan*/  UPIO_MEM32 ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 struct serial8250_em_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct uart_8250_port*,int /*<<< orphan*/ ,int) ; 
 struct serial8250_em_priv* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct serial8250_em_priv*) ; 
 unsigned int readb (int /*<<< orphan*/ ) ; 
 unsigned int readl (int /*<<< orphan*/ ) ; 
 int serial8250_register_8250_port (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int) ; 
 int stub1 (struct uart_port*,int) ; 
 void stub2 (struct uart_port*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 void stub4 (struct uart_8250_port*,int) ; 
 int /*<<< orphan*/  writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static void serial8250_em_serial_out(struct uart_port *p, int offset, int value)
{
	switch (offset) {
	case UART_TX: /* TX @ 0x00 */
		writeb(value, p->membase);
		break;
	case UART_FCR: /* FCR @ 0x0c (+1) */
	case UART_LCR: /* LCR @ 0x10 (+1) */
	case UART_MCR: /* MCR @ 0x14 (+1) */
	case UART_SCR: /* SCR @ 0x20 (+1) */
		writel(value, p->membase + ((offset + 1) << 2));
		break;
	case UART_IER: /* IER @ 0x04 */
		value &= 0x0f; /* only 4 valid bits - not Xscale */
		/* fall-through */
	case UART_DLL_EM: /* DLL @ 0x24 (+9) */
	case UART_DLM_EM: /* DLM @ 0x28 (+9) */
		writel(value, p->membase + (offset << 2));
	}
}

__attribute__((used)) static unsigned int serial8250_em_serial_in(struct uart_port *p, int offset)
{
	switch (offset) {
	case UART_RX: /* RX @ 0x00 */
		return readb(p->membase);
	case UART_MCR: /* MCR @ 0x14 (+1) */
	case UART_LSR: /* LSR @ 0x18 (+1) */
	case UART_MSR: /* MSR @ 0x1c (+1) */
	case UART_SCR: /* SCR @ 0x20 (+1) */
		return readl(p->membase + ((offset + 1) << 2));
	case UART_IER: /* IER @ 0x04 */
	case UART_IIR: /* IIR @ 0x08 */
	case UART_DLL_EM: /* DLL @ 0x24 (+9) */
	case UART_DLM_EM: /* DLM @ 0x28 (+9) */
		return readl(p->membase + (offset << 2));
	}
	return 0;
}

__attribute__((used)) static int serial8250_em_serial_dl_read(struct uart_8250_port *up)
{
	return serial_in(up, UART_DLL_EM) | serial_in(up, UART_DLM_EM) << 8;
}

__attribute__((used)) static void serial8250_em_serial_dl_write(struct uart_8250_port *up, int value)
{
	serial_out(up, UART_DLL_EM, value & 0xff);
	serial_out(up, UART_DLM_EM, value >> 8 & 0xff);
}

__attribute__((used)) static int serial8250_em_probe(struct platform_device *pdev)
{
	struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	struct serial8250_em_priv *priv;
	struct uart_8250_port up;
	int ret;

	if (!regs || !irq) {
		dev_err(&pdev->dev, "missing registers or irq\n");
		return -EINVAL;
	}

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->sclk = devm_clk_get(&pdev->dev, "sclk");
	if (IS_ERR(priv->sclk)) {
		dev_err(&pdev->dev, "unable to get clock\n");
		return PTR_ERR(priv->sclk);
	}

	memset(&up, 0, sizeof(up));
	up.port.mapbase = regs->start;
	up.port.irq = irq->start;
	up.port.type = PORT_UNKNOWN;
	up.port.flags = UPF_BOOT_AUTOCONF | UPF_FIXED_PORT | UPF_IOREMAP;
	up.port.dev = &pdev->dev;
	up.port.private_data = priv;

	clk_prepare_enable(priv->sclk);
	up.port.uartclk = clk_get_rate(priv->sclk);

	up.port.iotype = UPIO_MEM32;
	up.port.serial_in = serial8250_em_serial_in;
	up.port.serial_out = serial8250_em_serial_out;
	up.dl_read = serial8250_em_serial_dl_read;
	up.dl_write = serial8250_em_serial_dl_write;

	ret = serial8250_register_8250_port(&up);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to register 8250 port\n");
		clk_disable_unprepare(priv->sclk);
		return ret;
	}

	priv->line = ret;
	platform_set_drvdata(pdev, priv);
	return 0;
}

__attribute__((used)) static int serial8250_em_remove(struct platform_device *pdev)
{
	struct serial8250_em_priv *priv = platform_get_drvdata(pdev);

	serial8250_unregister_port(priv->line);
	clk_disable_unprepare(priv->sclk);
	return 0;
}


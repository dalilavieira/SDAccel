#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct uart_port {int minor; unsigned long uartclk; int fifosize; void (* set_termios ) (struct uart_port*,struct ktermios*,struct ktermios*) ;unsigned int (* get_mctrl ) (struct uart_port*) ;int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; scalar_t__ membase; int /*<<< orphan*/  status; struct lpss8250* private_data; } ;
struct TYPE_10__ {int (* serial_in ) (TYPE_4__*,int) ;int regshift; int uartclk; int flags; int /*<<< orphan*/  membase; int /*<<< orphan*/  mapbase; int /*<<< orphan*/  iotype; int /*<<< orphan*/  type; struct lpss8250* private_data; int /*<<< orphan*/  irq; struct device* dev; int /*<<< orphan*/  (* serial_out ) (TYPE_4__*,int,int) ;} ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;int tx_loadsz; int capabilities; TYPE_4__ port; struct uart_8250_dma* dma; int /*<<< orphan*/  (* dl_write ) (struct uart_8250_port*,int) ;} ;
struct TYPE_9__ {int dst_maxburst; } ;
struct TYPE_8__ {int src_maxburst; } ;
struct uart_8250_dma {int (* fn ) (struct dma_chan*,void*) ;struct dw_dma_slave* tx_param; struct dw_dma_slave* rx_param; TYPE_3__ txconf; TYPE_2__ rxconf; } ;
struct pci_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct pci_dev {int device; int /*<<< orphan*/  irq; struct device dev; int /*<<< orphan*/  bus; int /*<<< orphan*/  devfn; } ;
struct lpss8250_board {unsigned long freq; int base_baud; int (* setup ) (struct lpss8250*,TYPE_4__*) ;int /*<<< orphan*/  (* exit ) (struct lpss8250*) ;} ;
struct dw_dma_slave {int src_id; int dst_id; int p_master; scalar_t__ dma_dev; scalar_t__ m_master; } ;
struct lpss8250 {int dma_maxburst; int line; struct lpss8250_board* board; struct dw_dma_slave dma_param; struct uart_8250_dma dma; } ;
struct ktermios {int c_cflag; } ;
struct dma_chan {struct dw_dma_slave* private; TYPE_1__* device; } ;
typedef  int status ;
struct TYPE_7__ {scalar_t__ dev; } ;

/* Variables and functions */
 int BIT (int) ; 
 scalar_t__ BYT_PRV_CLK ; 
 int BYT_PRV_CLK_EN ; 
 unsigned long BYT_PRV_CLK_M_VAL_SHIFT ; 
 unsigned long BYT_PRV_CLK_N_VAL_SHIFT ; 
 int BYT_PRV_CLK_UPDATE ; 
 scalar_t__ BYT_TX_OVF_INT ; 
 int BYT_TX_OVF_INT_MASK ; 
 int CRTSCTS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int PCI_DEVFN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  PCI_DEVICE_ID_INTEL_BDW_UART1 133 
#define  PCI_DEVICE_ID_INTEL_BDW_UART2 132 
#define  PCI_DEVICE_ID_INTEL_BSW_UART1 131 
#define  PCI_DEVICE_ID_INTEL_BSW_UART2 130 
#define  PCI_DEVICE_ID_INTEL_BYT_UART1 129 
#define  PCI_DEVICE_ID_INTEL_BYT_UART2 128 
 int /*<<< orphan*/  PCI_IRQ_ALL_TYPES ; 
 int /*<<< orphan*/  PCI_SLOT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PORT_16550A ; 
 unsigned int TIOCM_CAR ; 
 unsigned int TIOCM_DSR ; 
 int UART_CAP_AFE ; 
 int UART_CAP_FIFO ; 
 int UART_MCR ; 
 int UPF_FIXED_PORT ; 
 int UPF_FIXED_TYPE ; 
 int UPF_SHARE_IRQ ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 int /*<<< orphan*/  UPSTAT_AUTOCTS ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct uart_8250_port*,int /*<<< orphan*/ ,int) ; 
 int pci_alloc_irq_vectors (struct pci_dev*,int,int,int /*<<< orphan*/ ) ; 
 struct lpss8250* pci_get_drvdata (struct pci_dev*) ; 
 struct pci_dev* pci_get_slot (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  pci_irq_vector (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct lpss8250*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int pcim_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pcim_iomap (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rational_best_approximation (unsigned long,unsigned long,unsigned long,unsigned long,unsigned long*,unsigned long*) ; 
 unsigned long rounddown_pow_of_two (unsigned long) ; 
 unsigned int serial8250_do_get_mctrl (struct uart_port*) ; 
 int /*<<< orphan*/  serial8250_do_set_termios (struct uart_port*,struct ktermios*,struct ktermios*) ; 
 int serial8250_register_8250_port (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (int) ; 
 int stub1 (TYPE_4__*,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_4__*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 int /*<<< orphan*/  stub4 (struct uart_8250_port*,int) ; 
 int stub5 (struct lpss8250*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub6 (struct lpss8250*) ; 
 int /*<<< orphan*/  stub7 (struct lpss8250*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 unsigned int tty_termios_baud_rate (struct ktermios*) ; 
 struct uart_8250_port* up_to_u8250p (struct uart_port*) ; 
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

__attribute__((used)) static void byt_set_termios(struct uart_port *p, struct ktermios *termios,
			    struct ktermios *old)
{
	unsigned int baud = tty_termios_baud_rate(termios);
	struct lpss8250 *lpss = p->private_data;
	unsigned long fref = lpss->board->freq, fuart = baud * 16;
	unsigned long w = BIT(15) - 1;
	unsigned long m, n;
	u32 reg;

	/* Gracefully handle the B0 case: fall back to B9600 */
	fuart = fuart ? fuart : 9600 * 16;

	/* Get Fuart closer to Fref */
	fuart *= rounddown_pow_of_two(fref / fuart);

	/*
	 * For baud rates 0.5M, 1M, 1.5M, 2M, 2.5M, 3M, 3.5M and 4M the
	 * dividers must be adjusted.
	 *
	 * uartclk = (m / n) * 100 MHz, where m <= n
	 */
	rational_best_approximation(fuart, fref, w, w, &m, &n);
	p->uartclk = fuart;

	/* Reset the clock */
	reg = (m << BYT_PRV_CLK_M_VAL_SHIFT) | (n << BYT_PRV_CLK_N_VAL_SHIFT);
	writel(reg, p->membase + BYT_PRV_CLK);
	reg |= BYT_PRV_CLK_EN | BYT_PRV_CLK_UPDATE;
	writel(reg, p->membase + BYT_PRV_CLK);

	p->status &= ~UPSTAT_AUTOCTS;
	if (termios->c_cflag & CRTSCTS)
		p->status |= UPSTAT_AUTOCTS;

	serial8250_do_set_termios(p, termios, old);
}

__attribute__((used)) static unsigned int byt_get_mctrl(struct uart_port *port)
{
	unsigned int ret = serial8250_do_get_mctrl(port);

	/* Force DCD and DSR signals to permanently be reported as active */
	ret |= TIOCM_CAR | TIOCM_DSR;

	return ret;
}

__attribute__((used)) static int byt_serial_setup(struct lpss8250 *lpss, struct uart_port *port)
{
	struct dw_dma_slave *param = &lpss->dma_param;
	struct uart_8250_port *up = up_to_u8250p(port);
	struct pci_dev *pdev = to_pci_dev(port->dev);
	unsigned int dma_devfn = PCI_DEVFN(PCI_SLOT(pdev->devfn), 0);
	struct pci_dev *dma_dev = pci_get_slot(pdev->bus, dma_devfn);

	switch (pdev->device) {
	case PCI_DEVICE_ID_INTEL_BYT_UART1:
	case PCI_DEVICE_ID_INTEL_BSW_UART1:
	case PCI_DEVICE_ID_INTEL_BDW_UART1:
		param->src_id = 3;
		param->dst_id = 2;
		break;
	case PCI_DEVICE_ID_INTEL_BYT_UART2:
	case PCI_DEVICE_ID_INTEL_BSW_UART2:
	case PCI_DEVICE_ID_INTEL_BDW_UART2:
		param->src_id = 5;
		param->dst_id = 4;
		break;
	default:
		return -EINVAL;
	}

	param->dma_dev = &dma_dev->dev;
	param->m_master = 0;
	param->p_master = 1;

	/* TODO: Detect FIFO size automaticaly for DesignWare 8250 */
	port->fifosize = 64;
	up->tx_loadsz = 64;

	lpss->dma_maxburst = 16;

	port->set_termios = byt_set_termios;
	port->get_mctrl = byt_get_mctrl;

	/* Disable TX counter interrupts */
	writel(BYT_TX_OVF_INT_MASK, port->membase + BYT_TX_OVF_INT);

	return 0;
}

__attribute__((used)) static void qrk_serial_setup_dma(struct lpss8250 *lpss, struct uart_port *port) {}

__attribute__((used)) static void qrk_serial_exit_dma(struct lpss8250 *lpss) {}

__attribute__((used)) static int qrk_serial_setup(struct lpss8250 *lpss, struct uart_port *port)
{
	struct pci_dev *pdev = to_pci_dev(port->dev);
	int ret;

	pci_set_master(pdev);

	ret = pci_alloc_irq_vectors(pdev, 1, 1, PCI_IRQ_ALL_TYPES);
	if (ret < 0)
		return ret;

	port->irq = pci_irq_vector(pdev, 0);

	qrk_serial_setup_dma(lpss, port);
	return 0;
}

__attribute__((used)) static void qrk_serial_exit(struct lpss8250 *lpss)
{
	qrk_serial_exit_dma(lpss);
}

__attribute__((used)) static bool lpss8250_dma_filter(struct dma_chan *chan, void *param)
{
	struct dw_dma_slave *dws = param;

	if (dws->dma_dev != chan->device->dev)
		return false;

	chan->private = dws;
	return true;
}

__attribute__((used)) static int lpss8250_dma_setup(struct lpss8250 *lpss, struct uart_8250_port *port)
{
	struct uart_8250_dma *dma = &lpss->dma;
	struct dw_dma_slave *rx_param, *tx_param;
	struct device *dev = port->port.dev;

	if (!lpss->dma_param.dma_dev)
		return 0;

	rx_param = devm_kzalloc(dev, sizeof(*rx_param), GFP_KERNEL);
	if (!rx_param)
		return -ENOMEM;

	tx_param = devm_kzalloc(dev, sizeof(*tx_param), GFP_KERNEL);
	if (!tx_param)
		return -ENOMEM;

	*rx_param = lpss->dma_param;
	dma->rxconf.src_maxburst = lpss->dma_maxburst;

	*tx_param = lpss->dma_param;
	dma->txconf.dst_maxburst = lpss->dma_maxburst;

	dma->fn = lpss8250_dma_filter;
	dma->rx_param = rx_param;
	dma->tx_param = tx_param;

	port->dma = dma;
	return 0;
}

__attribute__((used)) static int lpss8250_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	struct uart_8250_port uart;
	struct lpss8250 *lpss;
	int ret;

	ret = pcim_enable_device(pdev);
	if (ret)
		return ret;

	lpss = devm_kzalloc(&pdev->dev, sizeof(*lpss), GFP_KERNEL);
	if (!lpss)
		return -ENOMEM;

	lpss->board = (struct lpss8250_board *)id->driver_data;

	memset(&uart, 0, sizeof(struct uart_8250_port));

	uart.port.dev = &pdev->dev;
	uart.port.irq = pdev->irq;
	uart.port.private_data = lpss;
	uart.port.type = PORT_16550A;
	uart.port.iotype = UPIO_MEM;
	uart.port.regshift = 2;
	uart.port.uartclk = lpss->board->base_baud * 16;
	uart.port.flags = UPF_SHARE_IRQ | UPF_FIXED_PORT | UPF_FIXED_TYPE;
	uart.capabilities = UART_CAP_FIFO | UART_CAP_AFE;
	uart.port.mapbase = pci_resource_start(pdev, 0);
	uart.port.membase = pcim_iomap(pdev, 0, 0);
	if (!uart.port.membase)
		return -ENOMEM;

	ret = lpss->board->setup(lpss, &uart.port);
	if (ret)
		return ret;

	ret = lpss8250_dma_setup(lpss, &uart);
	if (ret)
		goto err_exit;

	ret = serial8250_register_8250_port(&uart);
	if (ret < 0)
		goto err_exit;

	lpss->line = ret;

	pci_set_drvdata(pdev, lpss);
	return 0;

err_exit:
	if (lpss->board->exit)
		lpss->board->exit(lpss);
	return ret;
}

__attribute__((used)) static void lpss8250_remove(struct pci_dev *pdev)
{
	struct lpss8250 *lpss = pci_get_drvdata(pdev);

	serial8250_unregister_port(lpss->line);

	if (lpss->board->exit)
		lpss->board->exit(lpss);
}


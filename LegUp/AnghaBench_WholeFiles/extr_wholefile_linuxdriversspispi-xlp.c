#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_10__ {int /*<<< orphan*/  of_node; } ;
struct xlp_spi_priv {int cs; int rx_len; int* rx_buf; int tx_len; int* tx_buf; int cmd_cont; int /*<<< orphan*/  done; int /*<<< orphan*/  spi_clk; struct clk* base; TYPE_2__ dev; scalar_t__ txerrors; scalar_t__ rxerrors; } ;
struct spi_transfer {unsigned char* tx_buf; unsigned char* rx_buf; int len; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; } ;
struct spi_master {int num_chipselect; int mode_bits; int (* setup ) (struct spi_device*) ;int (* transfer_one ) (struct spi_master*,struct spi_device*,struct spi_transfer*) ;TYPE_1__ dev; scalar_t__ bus_num; } ;
struct spi_device {int chip_select; int mode; TYPE_2__ dev; int /*<<< orphan*/  max_speed_hz; struct spi_master* master; } ;
struct resource {int dummy; } ;
struct platform_device {TYPE_2__ dev; int /*<<< orphan*/  name; } ;
struct clk {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int DIV_ROUND_UP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int PTR_ERR (struct clk*) ; 
 int SPI_CPHA ; 
 int SPI_CPOL ; 
 int SPI_CS_HIGH ; 
 int SPI_CS_OFFSET ; 
 int SPI_LSB_FIRST ; 
 int XLP_SPI_CMD ; 
 int XLP_SPI_CMD_CONT ; 
 int XLP_SPI_CMD_RX_MASK ; 
 int XLP_SPI_CMD_TX_MASK ; 
 int XLP_SPI_CONFIG ; 
 int XLP_SPI_CPHA ; 
 int XLP_SPI_CPOL ; 
 int XLP_SPI_CS_LSBFE ; 
 int XLP_SPI_CS_POL ; 
 int XLP_SPI_FDIV ; 
 int XLP_SPI_FDIV_MAX ; 
 int XLP_SPI_FDIV_MIN ; 
 int XLP_SPI_FIFO_SIZE ; 
 int XLP_SPI_FIFO_THRESH ; 
 int XLP_SPI_FIFO_WCNT ; 
 int XLP_SPI_INTR_DONE ; 
 int XLP_SPI_INTR_EN ; 
 int XLP_SPI_INTR_RXOF ; 
 int XLP_SPI_INTR_RXTH ; 
 int XLP_SPI_INTR_TXTH ; 
 int XLP_SPI_INTR_TXUF ; 
 int XLP_SPI_MAX_CS ; 
 int XLP_SPI_RXCAP_EN ; 
 int XLP_SPI_RXDATA_FIFO ; 
 int XLP_SPI_RXFIFO_WCNT_MASK ; 
 int XLP_SPI_RXMISO_EN ; 
 int XLP_SPI_RX_INT ; 
 int XLP_SPI_RX_OF ; 
 int XLP_SPI_STATUS ; 
 int XLP_SPI_STAT_MASK ; 
 int XLP_SPI_SYSCTRL ; 
 int XLP_SPI_SYS_PMEN ; 
 int XLP_SPI_SYS_RESET ; 
 int XLP_SPI_TXDATA_FIFO ; 
 int XLP_SPI_TXFIFO_WCNT_MASK ; 
 int XLP_SPI_TXFIFO_WCNT_SHIFT ; 
 int XLP_SPI_TXMOSI_EN ; 
 int XLP_SPI_TXRXTH ; 
 int XLP_SPI_TX_INT ; 
 int XLP_SPI_TX_UF ; 
 int XLP_SPI_XFER_SIZE ; 
 int XLP_SPI_XFR_BITCNT_SHIFT ; 
 int XLP_SPI_XFR_DONE ; 
 int /*<<< orphan*/  clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct clk* devm_clk_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 struct clk* devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 struct xlp_spi_priv* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct xlp_spi_priv*) ; 
 int devm_spi_register_master (TYPE_2__*,struct spi_master*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl (struct clk*) ; 
 struct spi_master* spi_alloc_master (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spi_finalize_current_transfer (struct spi_master*) ; 
 struct xlp_spi_priv* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  spi_master_put (struct spi_master*) ; 
 int /*<<< orphan*/  spi_master_set_devdata (struct spi_master*,struct xlp_spi_priv*) ; 
 scalar_t__ spi_transfer_is_last (struct spi_master*,struct spi_transfer*) ; 
 int wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,struct clk*) ; 

__attribute__((used)) static inline u32 xlp_spi_reg_read(struct xlp_spi_priv *priv,
				int cs, int regoff)
{
	return readl(priv->base + regoff + cs * SPI_CS_OFFSET);
}

__attribute__((used)) static inline void xlp_spi_reg_write(struct xlp_spi_priv *priv, int cs,
				int regoff, u32 val)
{
	writel(val, priv->base + regoff + cs * SPI_CS_OFFSET);
}

__attribute__((used)) static inline void xlp_spi_sysctl_write(struct xlp_spi_priv *priv,
				int regoff, u32 val)
{
	writel(val, priv->base + regoff);
}

__attribute__((used)) static void xlp_spi_sysctl_setup(struct xlp_spi_priv *xspi)
{
	int cs;

	for (cs = 0; cs < XLP_SPI_MAX_CS; cs++)
		xlp_spi_sysctl_write(xspi, XLP_SPI_SYSCTRL,
				XLP_SPI_SYS_RESET << cs);
	xlp_spi_sysctl_write(xspi, XLP_SPI_SYSCTRL, XLP_SPI_SYS_PMEN);
}

__attribute__((used)) static int xlp_spi_setup(struct spi_device *spi)
{
	struct xlp_spi_priv *xspi;
	u32 fdiv, cfg;
	int cs;

	xspi = spi_master_get_devdata(spi->master);
	cs = spi->chip_select;
	/*
	 * The value of fdiv must be between 4 and 65535.
	 */
	fdiv = DIV_ROUND_UP(xspi->spi_clk, spi->max_speed_hz);
	if (fdiv > XLP_SPI_FDIV_MAX)
		fdiv = XLP_SPI_FDIV_MAX;
	else if (fdiv < XLP_SPI_FDIV_MIN)
		fdiv = XLP_SPI_FDIV_MIN;

	xlp_spi_reg_write(xspi, cs, XLP_SPI_FDIV, fdiv);
	xlp_spi_reg_write(xspi, cs, XLP_SPI_FIFO_THRESH, XLP_SPI_TXRXTH);
	cfg = xlp_spi_reg_read(xspi, cs, XLP_SPI_CONFIG);
	if (spi->mode & SPI_CPHA)
		cfg |= XLP_SPI_CPHA;
	else
		cfg &= ~XLP_SPI_CPHA;
	if (spi->mode & SPI_CPOL)
		cfg |= XLP_SPI_CPOL;
	else
		cfg &= ~XLP_SPI_CPOL;
	if (!(spi->mode & SPI_CS_HIGH))
		cfg |= XLP_SPI_CS_POL;
	else
		cfg &= ~XLP_SPI_CS_POL;
	if (spi->mode & SPI_LSB_FIRST)
		cfg |= XLP_SPI_CS_LSBFE;
	else
		cfg &= ~XLP_SPI_CS_LSBFE;

	cfg |= XLP_SPI_TXMOSI_EN | XLP_SPI_RXMISO_EN;
	if (fdiv == 4)
		cfg |= XLP_SPI_RXCAP_EN;
	xlp_spi_reg_write(xspi, cs, XLP_SPI_CONFIG, cfg);

	return 0;
}

__attribute__((used)) static void xlp_spi_read_rxfifo(struct xlp_spi_priv *xspi)
{
	u32 rx_data, rxfifo_cnt;
	int i, j, nbytes;

	rxfifo_cnt = xlp_spi_reg_read(xspi, xspi->cs, XLP_SPI_FIFO_WCNT);
	rxfifo_cnt &= XLP_SPI_RXFIFO_WCNT_MASK;
	while (rxfifo_cnt) {
		rx_data = xlp_spi_reg_read(xspi, xspi->cs, XLP_SPI_RXDATA_FIFO);
		j = 0;
		nbytes = min(xspi->rx_len, 4);
		for (i = nbytes - 1; i >= 0; i--, j++)
			xspi->rx_buf[i] = (rx_data >> (j * 8)) & 0xff;

		xspi->rx_len -= nbytes;
		xspi->rx_buf += nbytes;
		rxfifo_cnt--;
	}
}

__attribute__((used)) static void xlp_spi_fill_txfifo(struct xlp_spi_priv *xspi)
{
	u32 tx_data, txfifo_cnt;
	int i, j, nbytes;

	txfifo_cnt = xlp_spi_reg_read(xspi, xspi->cs, XLP_SPI_FIFO_WCNT);
	txfifo_cnt &= XLP_SPI_TXFIFO_WCNT_MASK;
	txfifo_cnt >>= XLP_SPI_TXFIFO_WCNT_SHIFT;
	while (xspi->tx_len && (txfifo_cnt < XLP_SPI_FIFO_SIZE)) {
		j = 0;
		tx_data = 0;
		nbytes = min(xspi->tx_len, 4);
		for (i = nbytes - 1; i >= 0; i--, j++)
			tx_data |= xspi->tx_buf[i] << (j * 8);

		xlp_spi_reg_write(xspi, xspi->cs, XLP_SPI_TXDATA_FIFO, tx_data);
		xspi->tx_len -= nbytes;
		xspi->tx_buf += nbytes;
		txfifo_cnt++;
	}
}

__attribute__((used)) static irqreturn_t xlp_spi_interrupt(int irq, void *dev_id)
{
	struct xlp_spi_priv *xspi = dev_id;
	u32 stat;

	stat = xlp_spi_reg_read(xspi, xspi->cs, XLP_SPI_STATUS) &
		XLP_SPI_STAT_MASK;
	if (!stat)
		return IRQ_NONE;

	if (stat & XLP_SPI_TX_INT) {
		if (xspi->tx_len)
			xlp_spi_fill_txfifo(xspi);
		if (stat & XLP_SPI_TX_UF)
			xspi->txerrors++;
	}

	if (stat & XLP_SPI_RX_INT) {
		if (xspi->rx_len)
			xlp_spi_read_rxfifo(xspi);
		if (stat & XLP_SPI_RX_OF)
			xspi->rxerrors++;
	}

	/* write status back to clear interrupts */
	xlp_spi_reg_write(xspi, xspi->cs, XLP_SPI_STATUS, stat);
	if (stat & XLP_SPI_XFR_DONE)
		complete(&xspi->done);

	return IRQ_HANDLED;
}

__attribute__((used)) static void xlp_spi_send_cmd(struct xlp_spi_priv *xspi, int xfer_len,
			int cmd_cont)
{
	u32 cmd = 0;

	if (xspi->tx_buf)
		cmd |= XLP_SPI_CMD_TX_MASK;
	if (xspi->rx_buf)
		cmd |= XLP_SPI_CMD_RX_MASK;
	if (cmd_cont)
		cmd |= XLP_SPI_CMD_CONT;
	cmd |= ((xfer_len * 8 - 1) << XLP_SPI_XFR_BITCNT_SHIFT);
	xlp_spi_reg_write(xspi, xspi->cs, XLP_SPI_CMD, cmd);
}

__attribute__((used)) static int xlp_spi_xfer_block(struct  xlp_spi_priv *xs,
		const unsigned char *tx_buf,
		unsigned char *rx_buf, int xfer_len, int cmd_cont)
{
	int timeout;
	u32 intr_mask = 0;

	xs->tx_buf = tx_buf;
	xs->rx_buf = rx_buf;
	xs->tx_len = (xs->tx_buf == NULL) ? 0 : xfer_len;
	xs->rx_len = (xs->rx_buf == NULL) ? 0 : xfer_len;
	xs->txerrors = xs->rxerrors = 0;

	/* fill TXDATA_FIFO, then send the CMD */
	if (xs->tx_len)
		xlp_spi_fill_txfifo(xs);

	xlp_spi_send_cmd(xs, xfer_len, cmd_cont);

	/*
	 * We are getting some spurious tx interrupts, so avoid enabling
	 * tx interrupts when only rx is in process.
	 * Enable all the interrupts in tx case.
	 */
	if (xs->tx_len)
		intr_mask |= XLP_SPI_INTR_TXTH | XLP_SPI_INTR_TXUF |
				XLP_SPI_INTR_RXTH | XLP_SPI_INTR_RXOF;
	else
		intr_mask |= XLP_SPI_INTR_RXTH | XLP_SPI_INTR_RXOF;

	intr_mask |= XLP_SPI_INTR_DONE;
	xlp_spi_reg_write(xs, xs->cs, XLP_SPI_INTR_EN, intr_mask);

	timeout = wait_for_completion_timeout(&xs->done,
				msecs_to_jiffies(1000));
	/* Disable interrupts */
	xlp_spi_reg_write(xs, xs->cs, XLP_SPI_INTR_EN, 0x0);
	if (!timeout) {
		dev_err(&xs->dev, "xfer timedout!\n");
		goto out;
	}
	if (xs->txerrors || xs->rxerrors)
		dev_err(&xs->dev, "Over/Underflow rx %d tx %d xfer %d!\n",
				xs->rxerrors, xs->txerrors, xfer_len);

	return xfer_len;
out:
	return -ETIMEDOUT;
}

__attribute__((used)) static int xlp_spi_txrx_bufs(struct xlp_spi_priv *xs, struct spi_transfer *t)
{
	int bytesleft, sz;
	unsigned char *rx_buf;
	const unsigned char *tx_buf;

	tx_buf = t->tx_buf;
	rx_buf = t->rx_buf;
	bytesleft = t->len;
	while (bytesleft) {
		if (bytesleft > XLP_SPI_XFER_SIZE)
			sz = xlp_spi_xfer_block(xs, tx_buf, rx_buf,
					XLP_SPI_XFER_SIZE, 1);
		else
			sz = xlp_spi_xfer_block(xs, tx_buf, rx_buf,
					bytesleft, xs->cmd_cont);
		if (sz < 0)
			return sz;
		bytesleft -= sz;
		if (tx_buf)
			tx_buf += sz;
		if (rx_buf)
			rx_buf += sz;
	}
	return bytesleft;
}

__attribute__((used)) static int xlp_spi_transfer_one(struct spi_master *master,
					struct spi_device *spi,
					struct spi_transfer *t)
{
	struct xlp_spi_priv *xspi = spi_master_get_devdata(master);
	int ret = 0;

	xspi->cs = spi->chip_select;
	xspi->dev = spi->dev;

	if (spi_transfer_is_last(master, t))
		xspi->cmd_cont = 0;
	else
		xspi->cmd_cont = 1;

	if (xlp_spi_txrx_bufs(xspi, t))
		ret = -EIO;

	spi_finalize_current_transfer(master);
	return ret;
}

__attribute__((used)) static int xlp_spi_probe(struct platform_device *pdev)
{
	struct spi_master *master;
	struct xlp_spi_priv *xspi;
	struct resource *res;
	struct clk *clk;
	int irq, err;

	xspi = devm_kzalloc(&pdev->dev, sizeof(*xspi), GFP_KERNEL);
	if (!xspi)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	xspi->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(xspi->base))
		return PTR_ERR(xspi->base);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "no IRQ resource found: %d\n", irq);
		return irq;
	}
	err = devm_request_irq(&pdev->dev, irq, xlp_spi_interrupt, 0,
			pdev->name, xspi);
	if (err) {
		dev_err(&pdev->dev, "unable to request irq %d\n", irq);
		return err;
	}

	clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(clk)) {
		dev_err(&pdev->dev, "could not get spi clock\n");
		return PTR_ERR(clk);
	}

	xspi->spi_clk = clk_get_rate(clk);

	master = spi_alloc_master(&pdev->dev, 0);
	if (!master) {
		dev_err(&pdev->dev, "could not alloc master\n");
		return -ENOMEM;
	}

	master->bus_num = 0;
	master->num_chipselect = XLP_SPI_MAX_CS;
	master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
	master->setup = xlp_spi_setup;
	master->transfer_one = xlp_spi_transfer_one;
	master->dev.of_node = pdev->dev.of_node;

	init_completion(&xspi->done);
	spi_master_set_devdata(master, xspi);
	xlp_spi_sysctl_setup(xspi);

	/* register spi controller */
	err = devm_spi_register_master(&pdev->dev, master);
	if (err) {
		dev_err(&pdev->dev, "spi register master failed!\n");
		spi_master_put(master);
		return err;
	}

	return 0;
}


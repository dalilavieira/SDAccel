#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct spi_transfer {int bits_per_word; int speed_hz; unsigned int len; int* tx_buf; int* rx_buf; } ;
struct spi_master {int mode_bits; int (* setup ) (struct spi_device*) ;void (* set_cs ) (struct spi_device*,int) ;int (* transfer_one ) (struct spi_master*,struct spi_device*,struct spi_transfer*) ;int auto_runtime_pm; int /*<<< orphan*/  bits_per_word_mask; int /*<<< orphan*/  num_chipselect; int /*<<< orphan*/  bus_num; } ;
struct spi_device {int mode; int chip_select; int max_speed_hz; int /*<<< orphan*/  bits_per_word; int /*<<< orphan*/  dev; struct spi_master* master; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct mcfqspi_platform_data {TYPE_1__* cs_control; int /*<<< orphan*/  num_chipselect; int /*<<< orphan*/  bus_num; } ;
struct mcfqspi {scalar_t__ irq; scalar_t__ clk; int /*<<< orphan*/  waitq; TYPE_1__* cs_control; scalar_t__ iobase; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {int (* setup ) (TYPE_1__*) ;int /*<<< orphan*/  (* teardown ) (TYPE_1__*) ;int /*<<< orphan*/  (* deselect ) (TYPE_1__*,int,int) ;int /*<<< orphan*/  (* select ) (TYPE_1__*,int,int) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int MCFQSPI_BUSCLK ; 
 scalar_t__ MCFQSPI_QAR ; 
 int MCFQSPI_QAR_CMDBUF ; 
 int MCFQSPI_QAR_RXBUF ; 
 int MCFQSPI_QAR_TXBUF ; 
 int MCFQSPI_QCR_BITSE ; 
 scalar_t__ MCFQSPI_QDLYR ; 
 int MCFQSPI_QDLYR_SPE ; 
 scalar_t__ MCFQSPI_QDR ; 
 scalar_t__ MCFQSPI_QIR ; 
 int MCFQSPI_QIR_SPIF ; 
 int MCFQSPI_QIR_SPIFE ; 
 scalar_t__ MCFQSPI_QMR ; 
 int MCFQSPI_QMR_CPHA ; 
 int MCFQSPI_QMR_CPOL ; 
 int MCFQSPI_QMR_MSTR ; 
 scalar_t__ MCFQSPI_QWR ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  SPI_BPW_RANGE_MASK (int,int) ; 
 int SPI_CPHA ; 
 int SPI_CPOL ; 
 int SPI_CS_HIGH ; 
 int clamp (int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int /*<<< orphan*/  clk_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct mcfqspi_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 int devm_request_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct mcfqspi*) ; 
 int devm_spi_register_master (int /*<<< orphan*/ *,struct spi_master*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 struct spi_master* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct spi_master*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int readw (scalar_t__) ; 
 struct spi_master* spi_alloc_master (int /*<<< orphan*/ *,int) ; 
 struct mcfqspi* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  spi_master_put (struct spi_master*) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int,int) ; 
 int stub3 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*) ; 
 int /*<<< orphan*/  wait_event (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

__attribute__((used)) static void mcfqspi_wr_qmr(struct mcfqspi *mcfqspi, u16 val)
{
	writew(val, mcfqspi->iobase + MCFQSPI_QMR);
}

__attribute__((used)) static void mcfqspi_wr_qdlyr(struct mcfqspi *mcfqspi, u16 val)
{
	writew(val, mcfqspi->iobase + MCFQSPI_QDLYR);
}

__attribute__((used)) static u16 mcfqspi_rd_qdlyr(struct mcfqspi *mcfqspi)
{
	return readw(mcfqspi->iobase + MCFQSPI_QDLYR);
}

__attribute__((used)) static void mcfqspi_wr_qwr(struct mcfqspi *mcfqspi, u16 val)
{
	writew(val, mcfqspi->iobase + MCFQSPI_QWR);
}

__attribute__((used)) static void mcfqspi_wr_qir(struct mcfqspi *mcfqspi, u16 val)
{
	writew(val, mcfqspi->iobase + MCFQSPI_QIR);
}

__attribute__((used)) static void mcfqspi_wr_qar(struct mcfqspi *mcfqspi, u16 val)
{
	writew(val, mcfqspi->iobase + MCFQSPI_QAR);
}

__attribute__((used)) static void mcfqspi_wr_qdr(struct mcfqspi *mcfqspi, u16 val)
{
	writew(val, mcfqspi->iobase + MCFQSPI_QDR);
}

__attribute__((used)) static u16 mcfqspi_rd_qdr(struct mcfqspi *mcfqspi)
{
	return readw(mcfqspi->iobase + MCFQSPI_QDR);
}

__attribute__((used)) static void mcfqspi_cs_select(struct mcfqspi *mcfqspi, u8 chip_select,
			    bool cs_high)
{
	mcfqspi->cs_control->select(mcfqspi->cs_control, chip_select, cs_high);
}

__attribute__((used)) static void mcfqspi_cs_deselect(struct mcfqspi *mcfqspi, u8 chip_select,
				bool cs_high)
{
	mcfqspi->cs_control->deselect(mcfqspi->cs_control, chip_select, cs_high);
}

__attribute__((used)) static int mcfqspi_cs_setup(struct mcfqspi *mcfqspi)
{
	return (mcfqspi->cs_control->setup) ?
		mcfqspi->cs_control->setup(mcfqspi->cs_control) : 0;
}

__attribute__((used)) static void mcfqspi_cs_teardown(struct mcfqspi *mcfqspi)
{
	if (mcfqspi->cs_control->teardown)
		mcfqspi->cs_control->teardown(mcfqspi->cs_control);
}

__attribute__((used)) static u8 mcfqspi_qmr_baud(u32 speed_hz)
{
	return clamp((MCFQSPI_BUSCLK + speed_hz - 1) / speed_hz, 2u, 255u);
}

__attribute__((used)) static bool mcfqspi_qdlyr_spe(struct mcfqspi *mcfqspi)
{
	return mcfqspi_rd_qdlyr(mcfqspi) & MCFQSPI_QDLYR_SPE;
}

__attribute__((used)) static irqreturn_t mcfqspi_irq_handler(int this_irq, void *dev_id)
{
	struct mcfqspi *mcfqspi = dev_id;

	/* clear interrupt */
	mcfqspi_wr_qir(mcfqspi, MCFQSPI_QIR_SPIFE | MCFQSPI_QIR_SPIF);
	wake_up(&mcfqspi->waitq);

	return IRQ_HANDLED;
}

__attribute__((used)) static void mcfqspi_transfer_msg8(struct mcfqspi *mcfqspi, unsigned count,
				  const u8 *txbuf, u8 *rxbuf)
{
	unsigned i, n, offset = 0;

	n = min(count, 16u);

	mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_CMDBUF);
	for (i = 0; i < n; ++i)
		mcfqspi_wr_qdr(mcfqspi, MCFQSPI_QCR_BITSE);

	mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_TXBUF);
	if (txbuf)
		for (i = 0; i < n; ++i)
			mcfqspi_wr_qdr(mcfqspi, *txbuf++);
	else
		for (i = 0; i < count; ++i)
			mcfqspi_wr_qdr(mcfqspi, 0);

	count -= n;
	if (count) {
		u16 qwr = 0xf08;
		mcfqspi_wr_qwr(mcfqspi, 0x700);
		mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);

		do {
			wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
			mcfqspi_wr_qwr(mcfqspi, qwr);
			mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
			if (rxbuf) {
				mcfqspi_wr_qar(mcfqspi,
					       MCFQSPI_QAR_RXBUF + offset);
				for (i = 0; i < 8; ++i)
					*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
			}
			n = min(count, 8u);
			if (txbuf) {
				mcfqspi_wr_qar(mcfqspi,
					       MCFQSPI_QAR_TXBUF + offset);
				for (i = 0; i < n; ++i)
					mcfqspi_wr_qdr(mcfqspi, *txbuf++);
			}
			qwr = (offset ? 0x808 : 0) + ((n - 1) << 8);
			offset ^= 8;
			count -= n;
		} while (count);
		wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
		mcfqspi_wr_qwr(mcfqspi, qwr);
		mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
		if (rxbuf) {
			mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
			for (i = 0; i < 8; ++i)
				*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
			offset ^= 8;
		}
	} else {
		mcfqspi_wr_qwr(mcfqspi, (n - 1) << 8);
		mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
	}
	wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
	if (rxbuf) {
		mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
		for (i = 0; i < n; ++i)
			*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
	}
}

__attribute__((used)) static void mcfqspi_transfer_msg16(struct mcfqspi *mcfqspi, unsigned count,
				   const u16 *txbuf, u16 *rxbuf)
{
	unsigned i, n, offset = 0;

	n = min(count, 16u);

	mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_CMDBUF);
	for (i = 0; i < n; ++i)
		mcfqspi_wr_qdr(mcfqspi, MCFQSPI_QCR_BITSE);

	mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_TXBUF);
	if (txbuf)
		for (i = 0; i < n; ++i)
			mcfqspi_wr_qdr(mcfqspi, *txbuf++);
	else
		for (i = 0; i < count; ++i)
			mcfqspi_wr_qdr(mcfqspi, 0);

	count -= n;
	if (count) {
		u16 qwr = 0xf08;
		mcfqspi_wr_qwr(mcfqspi, 0x700);
		mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);

		do {
			wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
			mcfqspi_wr_qwr(mcfqspi, qwr);
			mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
			if (rxbuf) {
				mcfqspi_wr_qar(mcfqspi,
					       MCFQSPI_QAR_RXBUF + offset);
				for (i = 0; i < 8; ++i)
					*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
			}
			n = min(count, 8u);
			if (txbuf) {
				mcfqspi_wr_qar(mcfqspi,
					       MCFQSPI_QAR_TXBUF + offset);
				for (i = 0; i < n; ++i)
					mcfqspi_wr_qdr(mcfqspi, *txbuf++);
			}
			qwr = (offset ? 0x808 : 0x000) + ((n - 1) << 8);
			offset ^= 8;
			count -= n;
		} while (count);
		wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
		mcfqspi_wr_qwr(mcfqspi, qwr);
		mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
		if (rxbuf) {
			mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
			for (i = 0; i < 8; ++i)
				*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
			offset ^= 8;
		}
	} else {
		mcfqspi_wr_qwr(mcfqspi, (n - 1) << 8);
		mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
	}
	wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
	if (rxbuf) {
		mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
		for (i = 0; i < n; ++i)
			*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
	}
}

__attribute__((used)) static void mcfqspi_set_cs(struct spi_device *spi, bool enable)
{
	struct mcfqspi *mcfqspi = spi_master_get_devdata(spi->master);
	bool cs_high = spi->mode & SPI_CS_HIGH;

	if (enable)
		mcfqspi_cs_select(mcfqspi, spi->chip_select, cs_high);
	else
		mcfqspi_cs_deselect(mcfqspi, spi->chip_select, cs_high);
}

__attribute__((used)) static int mcfqspi_transfer_one(struct spi_master *master,
				struct spi_device *spi,
				struct spi_transfer *t)
{
	struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
	u16 qmr = MCFQSPI_QMR_MSTR;

	qmr |= t->bits_per_word << 10;
	if (spi->mode & SPI_CPHA)
		qmr |= MCFQSPI_QMR_CPHA;
	if (spi->mode & SPI_CPOL)
		qmr |= MCFQSPI_QMR_CPOL;
	qmr |= mcfqspi_qmr_baud(t->speed_hz);
	mcfqspi_wr_qmr(mcfqspi, qmr);

	mcfqspi_wr_qir(mcfqspi, MCFQSPI_QIR_SPIFE);
	if (t->bits_per_word == 8)
		mcfqspi_transfer_msg8(mcfqspi, t->len, t->tx_buf, t->rx_buf);
	else
		mcfqspi_transfer_msg16(mcfqspi, t->len / 2, t->tx_buf,
				       t->rx_buf);
	mcfqspi_wr_qir(mcfqspi, 0);

	return 0;
}

__attribute__((used)) static int mcfqspi_setup(struct spi_device *spi)
{
	mcfqspi_cs_deselect(spi_master_get_devdata(spi->master),
			    spi->chip_select, spi->mode & SPI_CS_HIGH);

	dev_dbg(&spi->dev,
			"bits per word %d, chip select %d, speed %d KHz\n",
			spi->bits_per_word, spi->chip_select,
			(MCFQSPI_BUSCLK / mcfqspi_qmr_baud(spi->max_speed_hz))
			/ 1000);

	return 0;
}

__attribute__((used)) static int mcfqspi_probe(struct platform_device *pdev)
{
	struct spi_master *master;
	struct mcfqspi *mcfqspi;
	struct resource *res;
	struct mcfqspi_platform_data *pdata;
	int status;

	pdata = dev_get_platdata(&pdev->dev);
	if (!pdata) {
		dev_dbg(&pdev->dev, "platform data is missing\n");
		return -ENOENT;
	}

	if (!pdata->cs_control) {
		dev_dbg(&pdev->dev, "pdata->cs_control is NULL\n");
		return -EINVAL;
	}

	master = spi_alloc_master(&pdev->dev, sizeof(*mcfqspi));
	if (master == NULL) {
		dev_dbg(&pdev->dev, "spi_alloc_master failed\n");
		return -ENOMEM;
	}

	mcfqspi = spi_master_get_devdata(master);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	mcfqspi->iobase = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mcfqspi->iobase)) {
		status = PTR_ERR(mcfqspi->iobase);
		goto fail0;
	}

	mcfqspi->irq = platform_get_irq(pdev, 0);
	if (mcfqspi->irq < 0) {
		dev_dbg(&pdev->dev, "platform_get_irq failed\n");
		status = -ENXIO;
		goto fail0;
	}

	status = devm_request_irq(&pdev->dev, mcfqspi->irq, mcfqspi_irq_handler,
				0, pdev->name, mcfqspi);
	if (status) {
		dev_dbg(&pdev->dev, "request_irq failed\n");
		goto fail0;
	}

	mcfqspi->clk = devm_clk_get(&pdev->dev, "qspi_clk");
	if (IS_ERR(mcfqspi->clk)) {
		dev_dbg(&pdev->dev, "clk_get failed\n");
		status = PTR_ERR(mcfqspi->clk);
		goto fail0;
	}
	clk_enable(mcfqspi->clk);

	master->bus_num = pdata->bus_num;
	master->num_chipselect = pdata->num_chipselect;

	mcfqspi->cs_control = pdata->cs_control;
	status = mcfqspi_cs_setup(mcfqspi);
	if (status) {
		dev_dbg(&pdev->dev, "error initializing cs_control\n");
		goto fail1;
	}

	init_waitqueue_head(&mcfqspi->waitq);

	master->mode_bits = SPI_CS_HIGH | SPI_CPOL | SPI_CPHA;
	master->bits_per_word_mask = SPI_BPW_RANGE_MASK(8, 16);
	master->setup = mcfqspi_setup;
	master->set_cs = mcfqspi_set_cs;
	master->transfer_one = mcfqspi_transfer_one;
	master->auto_runtime_pm = true;

	platform_set_drvdata(pdev, master);
	pm_runtime_enable(&pdev->dev);

	status = devm_spi_register_master(&pdev->dev, master);
	if (status) {
		dev_dbg(&pdev->dev, "spi_register_master failed\n");
		goto fail2;
	}

	dev_info(&pdev->dev, "Coldfire QSPI bus driver\n");

	return 0;

fail2:
	pm_runtime_disable(&pdev->dev);
	mcfqspi_cs_teardown(mcfqspi);
fail1:
	clk_disable(mcfqspi->clk);
fail0:
	spi_master_put(master);

	dev_dbg(&pdev->dev, "Coldfire QSPI probe failed\n");

	return status;
}

__attribute__((used)) static int mcfqspi_remove(struct platform_device *pdev)
{
	struct spi_master *master = platform_get_drvdata(pdev);
	struct mcfqspi *mcfqspi = spi_master_get_devdata(master);

	pm_runtime_disable(&pdev->dev);
	/* disable the hardware (set the baud rate to 0) */
	mcfqspi_wr_qmr(mcfqspi, MCFQSPI_QMR_MSTR);

	mcfqspi_cs_teardown(mcfqspi);
	clk_disable(mcfqspi->clk);

	return 0;
}


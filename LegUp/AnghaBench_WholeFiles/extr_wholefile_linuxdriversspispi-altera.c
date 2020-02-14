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
struct spi_transfer {int* tx_buf; unsigned int* rx_buf; int len; int /*<<< orphan*/  bits_per_word; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct spi_master {int num_chipselect; int (* transfer_one ) (struct spi_master*,struct spi_device*,struct spi_transfer*) ;void (* set_cs ) (struct spi_device*,int) ;TYPE_1__ dev; int /*<<< orphan*/  bits_per_word_mask; int /*<<< orphan*/  mode_bits; int /*<<< orphan*/  bus_num; } ;
struct spi_device {int /*<<< orphan*/  chip_select; struct spi_master* master; } ;
struct resource {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  id; } ;
struct altera_spi {unsigned int imr; unsigned int* tx; int bytes_per_word; size_t count; unsigned int* rx; int len; scalar_t__ irq; scalar_t__ base; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 scalar_t__ ALTERA_SPI_CONTROL ; 
 unsigned int ALTERA_SPI_CONTROL_IRRDY_MSK ; 
 unsigned int ALTERA_SPI_CONTROL_SSO_MSK ; 
 scalar_t__ ALTERA_SPI_RXDATA ; 
 scalar_t__ ALTERA_SPI_SLAVE_SEL ; 
 scalar_t__ ALTERA_SPI_STATUS ; 
 int ALTERA_SPI_STATUS_RRDY_MSK ; 
 scalar_t__ ALTERA_SPI_TXDATA ; 
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int DIV_ROUND_UP (int /*<<< orphan*/ ,int) ; 
 int ENODEV ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  SPI_BPW_RANGE_MASK (int,int) ; 
 int /*<<< orphan*/  SPI_CS_HIGH ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,scalar_t__,scalar_t__) ; 
 scalar_t__ devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 int devm_request_irq (TYPE_2__*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct spi_master*) ; 
 int devm_spi_register_master (TYPE_2__*,struct spi_master*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl (scalar_t__) ; 
 struct spi_master* spi_alloc_master (TYPE_2__*,int) ; 
 int /*<<< orphan*/  spi_finalize_current_transfer (struct spi_master*) ; 
 struct altera_spi* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  spi_master_put (struct spi_master*) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static inline struct altera_spi *altera_spi_to_hw(struct spi_device *sdev)
{
	return spi_master_get_devdata(sdev->master);
}

__attribute__((used)) static void altera_spi_set_cs(struct spi_device *spi, bool is_high)
{
	struct altera_spi *hw = altera_spi_to_hw(spi);

	if (is_high) {
		hw->imr &= ~ALTERA_SPI_CONTROL_SSO_MSK;
		writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
		writel(0, hw->base + ALTERA_SPI_SLAVE_SEL);
	} else {
		writel(BIT(spi->chip_select), hw->base + ALTERA_SPI_SLAVE_SEL);
		hw->imr |= ALTERA_SPI_CONTROL_SSO_MSK;
		writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
	}
}

__attribute__((used)) static void altera_spi_tx_word(struct altera_spi *hw)
{
	unsigned int txd = 0;

	if (hw->tx) {
		switch (hw->bytes_per_word) {
		case 1:
			txd = hw->tx[hw->count];
			break;
		case 2:
			txd = (hw->tx[hw->count * 2]
				| (hw->tx[hw->count * 2 + 1] << 8));
			break;
		}
	}

	writel(txd, hw->base + ALTERA_SPI_TXDATA);
}

__attribute__((used)) static void altera_spi_rx_word(struct altera_spi *hw)
{
	unsigned int rxd;

	rxd = readl(hw->base + ALTERA_SPI_RXDATA);
	if (hw->rx) {
		switch (hw->bytes_per_word) {
		case 1:
			hw->rx[hw->count] = rxd;
			break;
		case 2:
			hw->rx[hw->count * 2] = rxd;
			hw->rx[hw->count * 2 + 1] = rxd >> 8;
			break;
		}
	}

	hw->count++;
}

__attribute__((used)) static int altera_spi_txrx(struct spi_master *master,
	struct spi_device *spi, struct spi_transfer *t)
{
	struct altera_spi *hw = spi_master_get_devdata(master);

	hw->tx = t->tx_buf;
	hw->rx = t->rx_buf;
	hw->count = 0;
	hw->bytes_per_word = DIV_ROUND_UP(t->bits_per_word, 8);
	hw->len = t->len / hw->bytes_per_word;

	if (hw->irq >= 0) {
		/* enable receive interrupt */
		hw->imr |= ALTERA_SPI_CONTROL_IRRDY_MSK;
		writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);

		/* send the first byte */
		altera_spi_tx_word(hw);
	} else {
		while (hw->count < hw->len) {
			altera_spi_tx_word(hw);

			while (!(readl(hw->base + ALTERA_SPI_STATUS) &
				 ALTERA_SPI_STATUS_RRDY_MSK))
				cpu_relax();

			altera_spi_rx_word(hw);
		}
		spi_finalize_current_transfer(master);
	}

	return t->len;
}

__attribute__((used)) static irqreturn_t altera_spi_irq(int irq, void *dev)
{
	struct spi_master *master = dev;
	struct altera_spi *hw = spi_master_get_devdata(master);

	altera_spi_rx_word(hw);

	if (hw->count < hw->len) {
		altera_spi_tx_word(hw);
	} else {
		/* disable receive interrupt */
		hw->imr &= ~ALTERA_SPI_CONTROL_IRRDY_MSK;
		writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);

		spi_finalize_current_transfer(master);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int altera_spi_probe(struct platform_device *pdev)
{
	struct altera_spi *hw;
	struct spi_master *master;
	struct resource *res;
	int err = -ENODEV;

	master = spi_alloc_master(&pdev->dev, sizeof(struct altera_spi));
	if (!master)
		return err;

	/* setup the master state. */
	master->bus_num = pdev->id;
	master->num_chipselect = 16;
	master->mode_bits = SPI_CS_HIGH;
	master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 16);
	master->dev.of_node = pdev->dev.of_node;
	master->transfer_one = altera_spi_txrx;
	master->set_cs = altera_spi_set_cs;

	hw = spi_master_get_devdata(master);

	/* find and map our resources */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hw->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(hw->base)) {
		err = PTR_ERR(hw->base);
		goto exit;
	}
	/* program defaults into the registers */
	hw->imr = 0;		/* disable spi interrupts */
	writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
	writel(0, hw->base + ALTERA_SPI_STATUS);	/* clear status reg */
	if (readl(hw->base + ALTERA_SPI_STATUS) & ALTERA_SPI_STATUS_RRDY_MSK)
		readl(hw->base + ALTERA_SPI_RXDATA);	/* flush rxdata */
	/* irq is optional */
	hw->irq = platform_get_irq(pdev, 0);
	if (hw->irq >= 0) {
		err = devm_request_irq(&pdev->dev, hw->irq, altera_spi_irq, 0,
				       pdev->name, master);
		if (err)
			goto exit;
	}

	err = devm_spi_register_master(&pdev->dev, master);
	if (err)
		goto exit;
	dev_info(&pdev->dev, "base %p, irq %d\n", hw->base, hw->irq);

	return 0;
exit:
	spi_master_put(master);
	return err;
}


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
typedef  int u8 ;
typedef  int u32 ;
struct spi_transfer {unsigned int len; int* tx_buf; int* rx_buf; } ;
struct spi_master {int mode_bits; int num_chipselect; int (* setup ) (struct spi_device*) ;void (* set_cs ) (struct spi_device*,int) ;int (* transfer_one ) (struct spi_master*,struct spi_device*,struct spi_transfer*) ;int /*<<< orphan*/  bits_per_word_mask; int /*<<< orphan*/  bus_num; int /*<<< orphan*/  flags; } ;
struct spi_lp8841_rtc {int /*<<< orphan*/  iomem; int /*<<< orphan*/  state; } ;
struct spi_device {int mode; int /*<<< orphan*/  dev; struct spi_master* master; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int SPI_3WIRE ; 
 int /*<<< orphan*/  SPI_BPW_MASK (int) ; 
 int SPI_CS_HIGH ; 
 int /*<<< orphan*/  SPI_LP8841_RTC_CE ; 
 int /*<<< orphan*/  SPI_LP8841_RTC_CLK ; 
 int SPI_LP8841_RTC_MISO ; 
 int /*<<< orphan*/  SPI_LP8841_RTC_MOSI ; 
 int /*<<< orphan*/  SPI_LP8841_RTC_nWE ; 
 int SPI_LSB_FIRST ; 
 int /*<<< orphan*/  SPI_MASTER_HALF_DUPLEX ; 
 unsigned int SPI_MASTER_NO_RX ; 
 unsigned int SPI_MASTER_NO_TX ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  devm_ioremap_resource (int /*<<< orphan*/ *,void*) ; 
 int devm_spi_register_master (int /*<<< orphan*/ *,struct spi_master*) ; 
 int ioread8 (int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 void* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct spi_master*) ; 
 struct spi_master* spi_alloc_master (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  spi_finalize_current_transfer (struct spi_master*) ; 
 struct spi_lp8841_rtc* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  spi_master_put (struct spi_master*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
setsck(struct spi_lp8841_rtc *data, int is_on)
{
	if (is_on)
		data->state |= SPI_LP8841_RTC_CLK;
	else
		data->state &= ~SPI_LP8841_RTC_CLK;
	writeb(data->state, data->iomem);
}

__attribute__((used)) static inline void
setmosi(struct spi_lp8841_rtc *data, int is_on)
{
	if (is_on)
		data->state |= SPI_LP8841_RTC_MOSI;
	else
		data->state &= ~SPI_LP8841_RTC_MOSI;
	writeb(data->state, data->iomem);
}

__attribute__((used)) static inline int
getmiso(struct spi_lp8841_rtc *data)
{
	return ioread8(data->iomem) & SPI_LP8841_RTC_MISO;
}

__attribute__((used)) static inline u32
bitbang_txrx_be_cpha0_lsb(struct spi_lp8841_rtc *data,
		unsigned usecs, unsigned cpol, unsigned flags,
		u32 word, u8 bits)
{
	/* if (cpol == 0) this is SPI_MODE_0; else this is SPI_MODE_2 */

	u32 shift = 32 - bits;
	/* clock starts at inactive polarity */
	for (; likely(bits); bits--) {

		/* setup LSB (to slave) on leading edge */
		if ((flags & SPI_MASTER_NO_TX) == 0)
			setmosi(data, (word & 1));

		usleep_range(usecs, usecs + 1);	/* T(setup) */

		/* sample LSB (from slave) on trailing edge */
		word >>= 1;
		if ((flags & SPI_MASTER_NO_RX) == 0)
			word |= (getmiso(data) << 31);

		setsck(data, !cpol);
		usleep_range(usecs, usecs + 1);

		setsck(data, cpol);
	}

	word >>= shift;
	return word;
}

__attribute__((used)) static int
spi_lp8841_rtc_transfer_one(struct spi_master *master,
			    struct spi_device *spi,
			    struct spi_transfer *t)
{
	struct spi_lp8841_rtc	*data = spi_master_get_devdata(master);
	unsigned		count = t->len;
	const u8		*tx = t->tx_buf;
	u8			*rx = t->rx_buf;
	u8			word = 0;
	int			ret = 0;

	if (tx) {
		data->state &= ~SPI_LP8841_RTC_nWE;
		writeb(data->state, data->iomem);
		while (likely(count > 0)) {
			word = *tx++;
			bitbang_txrx_be_cpha0_lsb(data, 1, 0,
					SPI_MASTER_NO_RX, word, 8);
			count--;
		}
	} else if (rx) {
		data->state |= SPI_LP8841_RTC_nWE;
		writeb(data->state, data->iomem);
		while (likely(count > 0)) {
			word = bitbang_txrx_be_cpha0_lsb(data, 1, 0,
					SPI_MASTER_NO_TX, word, 8);
			*rx++ = word;
			count--;
		}
	} else {
		ret = -EINVAL;
	}

	spi_finalize_current_transfer(master);

	return ret;
}

__attribute__((used)) static void
spi_lp8841_rtc_set_cs(struct spi_device *spi, bool enable)
{
	struct spi_lp8841_rtc *data = spi_master_get_devdata(spi->master);

	data->state = 0;
	writeb(data->state, data->iomem);
	if (enable) {
		usleep_range(4, 5);
		data->state |= SPI_LP8841_RTC_CE;
		writeb(data->state, data->iomem);
		usleep_range(4, 5);
	}
}

__attribute__((used)) static int
spi_lp8841_rtc_setup(struct spi_device *spi)
{
	if ((spi->mode & SPI_CS_HIGH) == 0) {
		dev_err(&spi->dev, "unsupported active low chip select\n");
		return -EINVAL;
	}

	if ((spi->mode & SPI_LSB_FIRST) == 0) {
		dev_err(&spi->dev, "unsupported MSB first mode\n");
		return -EINVAL;
	}

	if ((spi->mode & SPI_3WIRE) == 0) {
		dev_err(&spi->dev, "unsupported wiring. 3 wires required\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int
spi_lp8841_rtc_probe(struct platform_device *pdev)
{
	int				ret;
	struct spi_master		*master;
	struct spi_lp8841_rtc		*data;
	void				*iomem;

	master = spi_alloc_master(&pdev->dev, sizeof(*data));
	if (!master)
		return -ENOMEM;
	platform_set_drvdata(pdev, master);

	master->flags = SPI_MASTER_HALF_DUPLEX;
	master->mode_bits = SPI_CS_HIGH | SPI_3WIRE | SPI_LSB_FIRST;

	master->bus_num = pdev->id;
	master->num_chipselect = 1;
	master->setup = spi_lp8841_rtc_setup;
	master->set_cs = spi_lp8841_rtc_set_cs;
	master->transfer_one = spi_lp8841_rtc_transfer_one;
	master->bits_per_word_mask = SPI_BPW_MASK(8);
#ifdef CONFIG_OF
	master->dev.of_node = pdev->dev.of_node;
#endif

	data = spi_master_get_devdata(master);

	iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	data->iomem = devm_ioremap_resource(&pdev->dev, iomem);
	ret = PTR_ERR_OR_ZERO(data->iomem);
	if (ret) {
		dev_err(&pdev->dev, "failed to get IO address\n");
		goto err_put_master;
	}

	/* register with the SPI framework */
	ret = devm_spi_register_master(&pdev->dev, master);
	if (ret) {
		dev_err(&pdev->dev, "cannot register spi master\n");
		goto err_put_master;
	}

	return ret;


err_put_master:
	spi_master_put(master);

	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct sg_table {int /*<<< orphan*/  nents; int /*<<< orphan*/  sgl; } ;
struct spi_transfer {struct sg_table rx_sg; struct sg_table tx_sg; } ;
struct spi_message {int /*<<< orphan*/  spi; int /*<<< orphan*/  status; } ;
struct spi_device {struct pxa2xx_spi_chip* controller_data; } ;
struct spi_controller {struct dma_chan* dma_tx; struct dma_chan* dma_rx; struct spi_message* cur_msg; } ;
struct pxa2xx_spi_master {int /*<<< orphan*/  rx_param; int /*<<< orphan*/  dma_filter; int /*<<< orphan*/  tx_param; } ;
struct pxa2xx_spi_chip {int dma_burst_size; } ;
struct driver_data {unsigned int ioaddr; int ssp_type; int mask_sr; int dma_cr1; int clear_sr; int n_bytes; struct spi_controller* master; TYPE_1__* pdev; struct pxa2xx_spi_master* master_info; int /*<<< orphan*/  dma_running; int /*<<< orphan*/  ssdr_physical; } ;
struct dma_slave_config {int direction; int dst_addr_width; int src_addr_width; int /*<<< orphan*/  src_maxburst; int /*<<< orphan*/  src_addr; int /*<<< orphan*/  dst_maxburst; int /*<<< orphan*/  dst_addr; } ;
struct dma_chan {int dummy; } ;
struct dma_async_tx_descriptor {void (* callback ) (void*) ;struct driver_data* callback_param; } ;
struct device {int dummy; } ;
struct chip_data {int /*<<< orphan*/  dma_burst_size; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum dma_transfer_direction { ____Placeholder_dma_transfer_direction } dma_transfer_direction ;
typedef  enum dma_slave_buswidth { ____Placeholder_dma_slave_buswidth } dma_slave_buswidth ;
typedef  int /*<<< orphan*/  dma_cap_mask_t ;
typedef  int /*<<< orphan*/  cfg ;
struct TYPE_2__ {struct device dev; } ;

/* Variables and functions */
#define  CE4100_SSP 130 
 int DMA_CTRL_ACK ; 
 int DMA_DEV_TO_MEM ; 
 int DMA_MEM_TO_DEV ; 
 int DMA_PREP_INTERRUPT ; 
 int /*<<< orphan*/  DMA_SLAVE ; 
 int DMA_SLAVE_BUSWIDTH_1_BYTE ; 
 int DMA_SLAVE_BUSWIDTH_2_BYTES ; 
 int DMA_SLAVE_BUSWIDTH_4_BYTES ; 
 int EBUSY ; 
 int /*<<< orphan*/  EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
#define  PXA25x_SSP 129 
#define  QUARK_X1000_SSP 128 
 int /*<<< orphan*/  RX_THRESH_DFLT ; 
 unsigned int SSCR0 ; 
 int SSCR0_SSE ; 
 unsigned int SSCR1 ; 
 int SSCR1_RxTresh (int /*<<< orphan*/ ) ; 
 int SSCR1_TxTresh (int /*<<< orphan*/ ) ; 
 unsigned int SSSR ; 
 int SSSR_ALT_FRM_MASK ; 
 int SSSR_ROR ; 
 unsigned int SSTO ; 
 int /*<<< orphan*/  TX_THRESH_DFLT ; 
 int __raw_readl (unsigned int) ; 
 int /*<<< orphan*/  __raw_writel (int,unsigned int) ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  dma_async_issue_pending (struct dma_chan*) ; 
 int /*<<< orphan*/  dma_cap_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_cap_zero (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_release_channel (struct dma_chan*) ; 
 void* dma_request_slave_channel_compat (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct device*,char*) ; 
 struct dma_async_tx_descriptor* dmaengine_prep_slave_sg (struct dma_chan*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int dmaengine_slave_config (struct dma_chan*,struct dma_slave_config*) ; 
 int /*<<< orphan*/  dmaengine_submit (struct dma_async_tx_descriptor*) ; 
 int /*<<< orphan*/  dmaengine_terminate_async (struct dma_chan*) ; 
 int /*<<< orphan*/  dmaengine_terminate_sync (struct dma_chan*) ; 
 int /*<<< orphan*/  memset (struct dma_slave_config*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spi_finalize_current_transfer (struct spi_controller*) ; 
 struct chip_data* spi_get_ctldata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 pxa2xx_spi_read(const struct driver_data *drv_data,
				  unsigned reg)
{
	return __raw_readl(drv_data->ioaddr + reg);
}

__attribute__((used)) static  inline void pxa2xx_spi_write(const struct driver_data *drv_data,
				     unsigned reg, u32 val)
{
	__raw_writel(val, drv_data->ioaddr + reg);
}

__attribute__((used)) static inline int pxa25x_ssp_comp(struct driver_data *drv_data)
{
	switch (drv_data->ssp_type) {
	case PXA25x_SSP:
	case CE4100_SSP:
	case QUARK_X1000_SSP:
		return 1;
	default:
		return 0;
	}
}

__attribute__((used)) static inline void write_SSSR_CS(struct driver_data *drv_data, u32 val)
{
	if (drv_data->ssp_type == CE4100_SSP ||
	    drv_data->ssp_type == QUARK_X1000_SSP)
		val |= pxa2xx_spi_read(drv_data, SSSR) & SSSR_ALT_FRM_MASK;

	pxa2xx_spi_write(drv_data, SSSR, val);
}

__attribute__((used)) static void pxa2xx_spi_dma_transfer_complete(struct driver_data *drv_data,
					     bool error)
{
	struct spi_message *msg = drv_data->master->cur_msg;

	/*
	 * It is possible that one CPU is handling ROR interrupt and other
	 * just gets DMA completion. Calling pump_transfers() twice for the
	 * same transfer leads to problems thus we prevent concurrent calls
	 * by using ->dma_running.
	 */
	if (atomic_dec_and_test(&drv_data->dma_running)) {
		/*
		 * If the other CPU is still handling the ROR interrupt we
		 * might not know about the error yet. So we re-check the
		 * ROR bit here before we clear the status register.
		 */
		if (!error) {
			u32 status = pxa2xx_spi_read(drv_data, SSSR)
				     & drv_data->mask_sr;
			error = status & SSSR_ROR;
		}

		/* Clear status & disable interrupts */
		pxa2xx_spi_write(drv_data, SSCR1,
				 pxa2xx_spi_read(drv_data, SSCR1)
				 & ~drv_data->dma_cr1);
		write_SSSR_CS(drv_data, drv_data->clear_sr);
		if (!pxa25x_ssp_comp(drv_data))
			pxa2xx_spi_write(drv_data, SSTO, 0);

		if (error) {
			/* In case we got an error we disable the SSP now */
			pxa2xx_spi_write(drv_data, SSCR0,
					 pxa2xx_spi_read(drv_data, SSCR0)
					 & ~SSCR0_SSE);
			msg->status = -EIO;
		}

		spi_finalize_current_transfer(drv_data->master);
	}
}

__attribute__((used)) static void pxa2xx_spi_dma_callback(void *data)
{
	pxa2xx_spi_dma_transfer_complete(data, false);
}

__attribute__((used)) static struct dma_async_tx_descriptor *
pxa2xx_spi_dma_prepare_one(struct driver_data *drv_data,
			   enum dma_transfer_direction dir,
			   struct spi_transfer *xfer)
{
	struct chip_data *chip =
		spi_get_ctldata(drv_data->master->cur_msg->spi);
	enum dma_slave_buswidth width;
	struct dma_slave_config cfg;
	struct dma_chan *chan;
	struct sg_table *sgt;
	int ret;

	switch (drv_data->n_bytes) {
	case 1:
		width = DMA_SLAVE_BUSWIDTH_1_BYTE;
		break;
	case 2:
		width = DMA_SLAVE_BUSWIDTH_2_BYTES;
		break;
	default:
		width = DMA_SLAVE_BUSWIDTH_4_BYTES;
		break;
	}

	memset(&cfg, 0, sizeof(cfg));
	cfg.direction = dir;

	if (dir == DMA_MEM_TO_DEV) {
		cfg.dst_addr = drv_data->ssdr_physical;
		cfg.dst_addr_width = width;
		cfg.dst_maxburst = chip->dma_burst_size;

		sgt = &xfer->tx_sg;
		chan = drv_data->master->dma_tx;
	} else {
		cfg.src_addr = drv_data->ssdr_physical;
		cfg.src_addr_width = width;
		cfg.src_maxburst = chip->dma_burst_size;

		sgt = &xfer->rx_sg;
		chan = drv_data->master->dma_rx;
	}

	ret = dmaengine_slave_config(chan, &cfg);
	if (ret) {
		dev_warn(&drv_data->pdev->dev, "DMA slave config failed\n");
		return NULL;
	}

	return dmaengine_prep_slave_sg(chan, sgt->sgl, sgt->nents, dir,
				       DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
}

irqreturn_t pxa2xx_spi_dma_transfer(struct driver_data *drv_data)
{
	u32 status;

	status = pxa2xx_spi_read(drv_data, SSSR) & drv_data->mask_sr;
	if (status & SSSR_ROR) {
		dev_err(&drv_data->pdev->dev, "FIFO overrun\n");

		dmaengine_terminate_async(drv_data->master->dma_rx);
		dmaengine_terminate_async(drv_data->master->dma_tx);

		pxa2xx_spi_dma_transfer_complete(drv_data, true);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

int pxa2xx_spi_dma_prepare(struct driver_data *drv_data,
			   struct spi_transfer *xfer)
{
	struct dma_async_tx_descriptor *tx_desc, *rx_desc;
	int err;

	tx_desc = pxa2xx_spi_dma_prepare_one(drv_data, DMA_MEM_TO_DEV, xfer);
	if (!tx_desc) {
		dev_err(&drv_data->pdev->dev,
			"failed to get DMA TX descriptor\n");
		err = -EBUSY;
		goto err_tx;
	}

	rx_desc = pxa2xx_spi_dma_prepare_one(drv_data, DMA_DEV_TO_MEM, xfer);
	if (!rx_desc) {
		dev_err(&drv_data->pdev->dev,
			"failed to get DMA RX descriptor\n");
		err = -EBUSY;
		goto err_rx;
	}

	/* We are ready when RX completes */
	rx_desc->callback = pxa2xx_spi_dma_callback;
	rx_desc->callback_param = drv_data;

	dmaengine_submit(rx_desc);
	dmaengine_submit(tx_desc);
	return 0;

err_rx:
	dmaengine_terminate_async(drv_data->master->dma_tx);
err_tx:
	return err;
}

void pxa2xx_spi_dma_start(struct driver_data *drv_data)
{
	dma_async_issue_pending(drv_data->master->dma_rx);
	dma_async_issue_pending(drv_data->master->dma_tx);

	atomic_set(&drv_data->dma_running, 1);
}

void pxa2xx_spi_dma_stop(struct driver_data *drv_data)
{
	atomic_set(&drv_data->dma_running, 0);
	dmaengine_terminate_sync(drv_data->master->dma_rx);
	dmaengine_terminate_sync(drv_data->master->dma_tx);
}

int pxa2xx_spi_dma_setup(struct driver_data *drv_data)
{
	struct pxa2xx_spi_master *pdata = drv_data->master_info;
	struct device *dev = &drv_data->pdev->dev;
	struct spi_controller *master = drv_data->master;
	dma_cap_mask_t mask;

	dma_cap_zero(mask);
	dma_cap_set(DMA_SLAVE, mask);

	master->dma_tx = dma_request_slave_channel_compat(mask,
				pdata->dma_filter, pdata->tx_param, dev, "tx");
	if (!master->dma_tx)
		return -ENODEV;

	master->dma_rx = dma_request_slave_channel_compat(mask,
				pdata->dma_filter, pdata->rx_param, dev, "rx");
	if (!master->dma_rx) {
		dma_release_channel(master->dma_tx);
		master->dma_tx = NULL;
		return -ENODEV;
	}

	return 0;
}

void pxa2xx_spi_dma_release(struct driver_data *drv_data)
{
	struct spi_controller *master = drv_data->master;

	if (master->dma_rx) {
		dmaengine_terminate_sync(master->dma_rx);
		dma_release_channel(master->dma_rx);
		master->dma_rx = NULL;
	}
	if (master->dma_tx) {
		dmaengine_terminate_sync(master->dma_tx);
		dma_release_channel(master->dma_tx);
		master->dma_tx = NULL;
	}
}

int pxa2xx_spi_set_dma_burst_and_threshold(struct chip_data *chip,
					   struct spi_device *spi,
					   u8 bits_per_word, u32 *burst_code,
					   u32 *threshold)
{
	struct pxa2xx_spi_chip *chip_info = spi->controller_data;

	/*
	 * If the DMA burst size is given in chip_info we use that,
	 * otherwise we use the default. Also we use the default FIFO
	 * thresholds for now.
	 */
	*burst_code = chip_info ? chip_info->dma_burst_size : 1;
	*threshold = SSCR1_RxTresh(RX_THRESH_DFLT)
		   | SSCR1_TxTresh(TX_THRESH_DFLT);

	return 0;
}


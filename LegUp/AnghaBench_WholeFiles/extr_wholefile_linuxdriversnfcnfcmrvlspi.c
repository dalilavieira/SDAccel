#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {struct device_node* of_node; struct nfcmrvl_platform_data* platform_data; } ;
struct spi_device {TYPE_3__ dev; } ;
struct sk_buff {int dummy; } ;
struct nfcmrvl_spi_drv_data {TYPE_1__* priv; int /*<<< orphan*/  handshake_completion; struct spi_device* spi; TYPE_6__* nci_spi; int /*<<< orphan*/  flags; } ;
struct nfcmrvl_private {struct nfcmrvl_spi_drv_data* drv_data; int /*<<< orphan*/  dev; } ;
struct nfcmrvl_platform_data {int irq; } ;
struct nfcmrvl_fw_spi_config {int /*<<< orphan*/  clk; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_15__ {int /*<<< orphan*/  xfer_speed_hz; } ;
struct TYPE_13__ {int support_fw_dnld; int /*<<< orphan*/  ndev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (TYPE_1__*) ; 
 int /*<<< orphan*/  NFCMRVL_PHY_SPI ; 
 int PTR_ERR (TYPE_1__*) ; 
 int /*<<< orphan*/  SPI_WAIT_HANDSHAKE ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 struct nfcmrvl_spi_drv_data* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_3__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct nfcmrvl_spi_drv_data*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 TYPE_6__* nci_spi_allocate_spi (struct spi_device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct sk_buff* nci_spi_read (TYPE_6__*) ; 
 int nci_spi_send (TYPE_6__*,int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  nfc_err (TYPE_3__*,char*,...) ; 
 scalar_t__ nfcmrvl_nci_recv_frame (TYPE_1__*,struct sk_buff*) ; 
 TYPE_1__* nfcmrvl_nci_register_dev (int /*<<< orphan*/ ,struct nfcmrvl_spi_drv_data*,int /*<<< orphan*/ *,TYPE_3__*,struct nfcmrvl_platform_data*) ; 
 int /*<<< orphan*/  nfcmrvl_nci_unregister_dev (TYPE_1__*) ; 
 int nfcmrvl_parse_dt (struct device_node*,struct nfcmrvl_platform_data*) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,int) ; 
 struct nfcmrvl_spi_drv_data* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_ops ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct nfcmrvl_spi_drv_data*) ; 
 scalar_t__ test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t nfcmrvl_spi_int_irq_thread_fn(int irq, void *drv_data_ptr)
{
	struct nfcmrvl_spi_drv_data *drv_data = drv_data_ptr;
	struct sk_buff *skb;

	/*
	 * Special case where we are waiting for SPI_INT deassertion to start a
	 * transfer.
	 */
	if (test_and_clear_bit(SPI_WAIT_HANDSHAKE, &drv_data->flags)) {
		complete(&drv_data->handshake_completion);
		return IRQ_HANDLED;
	}

	/* Normal case, SPI_INT deasserted by slave to trigger a master read */

	skb = nci_spi_read(drv_data->nci_spi);
	if (!skb) {
		nfc_err(&drv_data->spi->dev, "failed to read spi packet");
		return IRQ_HANDLED;
	}

	if (nfcmrvl_nci_recv_frame(drv_data->priv, skb) < 0)
		nfc_err(&drv_data->spi->dev, "corrupted RX packet");

	return IRQ_HANDLED;
}

__attribute__((used)) static int nfcmrvl_spi_nci_open(struct nfcmrvl_private *priv)
{
	return 0;
}

__attribute__((used)) static int nfcmrvl_spi_nci_close(struct nfcmrvl_private *priv)
{
	return 0;
}

__attribute__((used)) static int nfcmrvl_spi_nci_send(struct nfcmrvl_private *priv,
				struct sk_buff *skb)
{
	struct nfcmrvl_spi_drv_data *drv_data = priv->drv_data;
	int err;

	/* Reinit completion for slave handshake */
	reinit_completion(&drv_data->handshake_completion);
	set_bit(SPI_WAIT_HANDSHAKE, &drv_data->flags);

	/*
	 * Append a dummy byte at the end of SPI frame. This is due to a
	 * specific DMA implementation in the controller
	 */
	skb_put(skb, 1);

	/* Send the SPI packet */
	err = nci_spi_send(drv_data->nci_spi, &drv_data->handshake_completion,
			   skb);
	if (err)
		nfc_err(priv->dev, "spi_send failed %d", err);

	return err;
}

__attribute__((used)) static void nfcmrvl_spi_nci_update_config(struct nfcmrvl_private *priv,
					  const void *param)
{
	struct nfcmrvl_spi_drv_data *drv_data = priv->drv_data;
	const struct nfcmrvl_fw_spi_config *config = param;

	drv_data->nci_spi->xfer_speed_hz = config->clk;
}

__attribute__((used)) static int nfcmrvl_spi_parse_dt(struct device_node *node,
				struct nfcmrvl_platform_data *pdata)
{
	int ret;

	ret = nfcmrvl_parse_dt(node, pdata);
	if (ret < 0) {
		pr_err("Failed to get generic entries\n");
		return ret;
	}

	ret = irq_of_parse_and_map(node, 0);
	if (ret < 0) {
		pr_err("Unable to get irq, error: %d\n", ret);
		return ret;
	}
	pdata->irq = ret;

	return 0;
}

__attribute__((used)) static int nfcmrvl_spi_probe(struct spi_device *spi)
{
	struct nfcmrvl_platform_data *pdata;
	struct nfcmrvl_platform_data config;
	struct nfcmrvl_spi_drv_data *drv_data;
	int ret = 0;

	drv_data = devm_kzalloc(&spi->dev, sizeof(*drv_data), GFP_KERNEL);
	if (!drv_data)
		return -ENOMEM;

	drv_data->spi = spi;
	drv_data->priv = NULL;
	spi_set_drvdata(spi, drv_data);

	pdata = spi->dev.platform_data;

	if (!pdata && spi->dev.of_node)
		if (nfcmrvl_spi_parse_dt(spi->dev.of_node, &config) == 0)
			pdata = &config;

	if (!pdata)
		return -EINVAL;

	ret = devm_request_threaded_irq(&drv_data->spi->dev, pdata->irq,
					NULL, nfcmrvl_spi_int_irq_thread_fn,
					IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
					"nfcmrvl_spi_int", drv_data);
	if (ret < 0) {
		nfc_err(&drv_data->spi->dev, "Unable to register IRQ handler");
		return -ENODEV;
	}

	drv_data->priv = nfcmrvl_nci_register_dev(NFCMRVL_PHY_SPI,
						  drv_data, &spi_ops,
						  &drv_data->spi->dev,
						  pdata);
	if (IS_ERR(drv_data->priv))
		return PTR_ERR(drv_data->priv);

	drv_data->priv->support_fw_dnld = true;

	drv_data->nci_spi = nci_spi_allocate_spi(drv_data->spi, 0, 10,
						 drv_data->priv->ndev);

	/* Init completion for slave handshake */
	init_completion(&drv_data->handshake_completion);
	return 0;
}

__attribute__((used)) static int nfcmrvl_spi_remove(struct spi_device *spi)
{
	struct nfcmrvl_spi_drv_data *drv_data = spi_get_drvdata(spi);

	nfcmrvl_nci_unregister_dev(drv_data->priv);
	return 0;
}


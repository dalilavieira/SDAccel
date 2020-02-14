#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct TYPE_13__ {scalar_t__ break_control; } ;
struct nfcmrvl_private {int support_fw_dnld; TYPE_5__ config; TYPE_4__* ndev; struct nci_uart* drv_data; } ;
struct nfcmrvl_platform_data {int flow_control; int break_control; int /*<<< orphan*/  reset_n_io; int /*<<< orphan*/  hci_muxed; } ;
struct nfcmrvl_fw_uart_config {int /*<<< orphan*/  flow_control; int /*<<< orphan*/  baudrate; } ;
struct TYPE_9__ {int (* send ) (struct nci_uart*,struct sk_buff*) ;} ;
struct nci_uart {TYPE_7__* tty; struct nfcmrvl_private* drv_data; TYPE_4__* ndev; TYPE_1__ ops; } ;
struct device_node {int dummy; } ;
struct device {TYPE_2__* parent; } ;
struct TYPE_15__ {TYPE_6__* ops; struct device* dev; } ;
struct TYPE_14__ {int /*<<< orphan*/  (* break_ctl ) (TYPE_7__*,int) ;} ;
struct TYPE_12__ {TYPE_3__* nfc_dev; } ;
struct TYPE_11__ {scalar_t__ fw_download_in_progress; } ;
struct TYPE_10__ {struct device_node* of_node; } ;

/* Variables and functions */
 int ENODEV ; 
 scalar_t__ IS_ERR (struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  NFCMRVL_PHY_UART ; 
 int PTR_ERR (struct nfcmrvl_private*) ; 
 int break_control ; 
 int flow_control ; 
 int /*<<< orphan*/  hci_muxed ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int nci_uart_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nci_uart_set_config (struct nci_uart*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nci_uart_unregister (int /*<<< orphan*/ *) ; 
 int nfcmrvl_nci_recv_frame (struct nfcmrvl_private*,struct sk_buff*) ; 
 struct nfcmrvl_private* nfcmrvl_nci_register_dev (int /*<<< orphan*/ ,struct nci_uart*,int /*<<< orphan*/ *,struct device*,struct nfcmrvl_platform_data*) ; 
 int /*<<< orphan*/  nfcmrvl_nci_uart ; 
 int /*<<< orphan*/  nfcmrvl_nci_unregister_dev (struct nfcmrvl_private*) ; 
 int nfcmrvl_parse_dt (struct device_node*,struct nfcmrvl_platform_data*) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct device_node* of_get_compatible_child (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  reset_n_io ; 
 int stub1 (struct nci_uart*,struct sk_buff*) ; 
 int /*<<< orphan*/  stub2 (TYPE_7__*,int) ; 
 int /*<<< orphan*/  stub3 (TYPE_7__*,int) ; 
 int /*<<< orphan*/  uart_ops ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int nfcmrvl_uart_nci_open(struct nfcmrvl_private *priv)
{
	return 0;
}

__attribute__((used)) static int nfcmrvl_uart_nci_close(struct nfcmrvl_private *priv)
{
	return 0;
}

__attribute__((used)) static int nfcmrvl_uart_nci_send(struct nfcmrvl_private *priv,
				 struct sk_buff *skb)
{
	struct nci_uart *nu = priv->drv_data;

	return nu->ops.send(nu, skb);
}

__attribute__((used)) static void nfcmrvl_uart_nci_update_config(struct nfcmrvl_private *priv,
					   const void *param)
{
	struct nci_uart *nu = priv->drv_data;
	const struct nfcmrvl_fw_uart_config *config = param;

	nci_uart_set_config(nu, le32_to_cpu(config->baudrate),
			    config->flow_control);
}

__attribute__((used)) static int nfcmrvl_uart_parse_dt(struct device_node *node,
				 struct nfcmrvl_platform_data *pdata)
{
	struct device_node *matched_node;
	int ret;

	matched_node = of_get_compatible_child(node, "marvell,nfc-uart");
	if (!matched_node) {
		matched_node = of_get_compatible_child(node, "mrvl,nfc-uart");
		if (!matched_node)
			return -ENODEV;
	}

	ret = nfcmrvl_parse_dt(matched_node, pdata);
	if (ret < 0) {
		pr_err("Failed to get generic entries\n");
		of_node_put(matched_node);
		return ret;
	}

	if (of_find_property(matched_node, "flow-control", NULL))
		pdata->flow_control = 1;
	else
		pdata->flow_control = 0;

	if (of_find_property(matched_node, "break-control", NULL))
		pdata->break_control = 1;
	else
		pdata->break_control = 0;

	of_node_put(matched_node);

	return 0;
}

__attribute__((used)) static int nfcmrvl_nci_uart_open(struct nci_uart *nu)
{
	struct nfcmrvl_private *priv;
	struct nfcmrvl_platform_data *pdata = NULL;
	struct nfcmrvl_platform_data config;
	struct device *dev = nu->tty->dev;

	/*
	 * Platform data cannot be used here since usually it is already used
	 * by low level serial driver. We can try to retrieve serial device
	 * and check if DT entries were added.
	 */

	if (dev && dev->parent && dev->parent->of_node)
		if (nfcmrvl_uart_parse_dt(dev->parent->of_node, &config) == 0)
			pdata = &config;

	if (!pdata) {
		pr_info("No platform data / DT -> fallback to module params\n");
		config.hci_muxed = hci_muxed;
		config.reset_n_io = reset_n_io;
		config.flow_control = flow_control;
		config.break_control = break_control;
		pdata = &config;
	}

	priv = nfcmrvl_nci_register_dev(NFCMRVL_PHY_UART, nu, &uart_ops,
					dev, pdata);
	if (IS_ERR(priv))
		return PTR_ERR(priv);

	priv->support_fw_dnld = true;

	nu->drv_data = priv;
	nu->ndev = priv->ndev;

	return 0;
}

__attribute__((used)) static void nfcmrvl_nci_uart_close(struct nci_uart *nu)
{
	nfcmrvl_nci_unregister_dev((struct nfcmrvl_private *)nu->drv_data);
}

__attribute__((used)) static int nfcmrvl_nci_uart_recv(struct nci_uart *nu, struct sk_buff *skb)
{
	return nfcmrvl_nci_recv_frame((struct nfcmrvl_private *)nu->drv_data,
				      skb);
}

__attribute__((used)) static void nfcmrvl_nci_uart_tx_start(struct nci_uart *nu)
{
	struct nfcmrvl_private *priv = (struct nfcmrvl_private *)nu->drv_data;

	if (priv->ndev->nfc_dev->fw_download_in_progress)
		return;

	/* Remove BREAK to wake up the NFCC */
	if (priv->config.break_control && nu->tty->ops->break_ctl) {
		nu->tty->ops->break_ctl(nu->tty, 0);
		usleep_range(3000, 5000);
	}
}

__attribute__((used)) static void nfcmrvl_nci_uart_tx_done(struct nci_uart *nu)
{
	struct nfcmrvl_private *priv = (struct nfcmrvl_private *)nu->drv_data;

	if (priv->ndev->nfc_dev->fw_download_in_progress)
		return;

	/*
	** To ensure that if the NFCC goes in DEEP SLEEP sate we can wake him
	** up. we set BREAK. Once we will be ready to send again we will remove
	** it.
	*/
	if (priv->config.break_control && nu->tty->ops->break_ctl) {
		nu->tty->ops->break_ctl(nu->tty, -1);
		usleep_range(1000, 3000);
	}
}

__attribute__((used)) static int nfcmrvl_uart_init_module(void)
{
	return nci_uart_register(&nfcmrvl_nci_uart);
}

__attribute__((used)) static void nfcmrvl_uart_exit_module(void)
{
	nci_uart_unregister(&nfcmrvl_nci_uart);
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct sk_buff {unsigned char len; scalar_t__* data; void* dev; } ;
struct TYPE_4__ {int reset_n_io; scalar_t__ hci_muxed; } ;
struct nfcmrvl_private {int phy; TYPE_2__ config; struct device* dev; int /*<<< orphan*/  flags; struct nci_dev* ndev; struct nfcmrvl_if_ops* if_ops; void* drv_data; } ;
struct nfcmrvl_platform_data {int reset_n_io; int hci_muxed; } ;
struct nfcmrvl_if_ops {int (* nci_open ) (struct nfcmrvl_private*) ;int (* nci_send ) (struct nfcmrvl_private*,struct sk_buff*) ;int /*<<< orphan*/  (* nci_close ) (struct nfcmrvl_private*) ;} ;
struct nci_dev {TYPE_1__* nfc_dev; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  enum nfcmrvl_phy { ____Placeholder_nfcmrvl_phy } nfcmrvl_phy ;
typedef  int __u8 ;
struct TYPE_3__ {scalar_t__ fw_download_in_progress; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 struct nfcmrvl_private* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 int NCI_SPI_HDR_LEN ; 
 unsigned char NFCMRVL_HCI_COMMAND_CODE ; 
 scalar_t__ NFCMRVL_HCI_EVENT_CODE ; 
 scalar_t__ NFCMRVL_HCI_EVENT_HEADER_SIZE ; 
 scalar_t__ NFCMRVL_HCI_NFC_EVENT_CODE ; 
 unsigned char NFCMRVL_HCI_OCF ; 
 unsigned char NFCMRVL_HCI_OGF ; 
 int /*<<< orphan*/  NFCMRVL_NCI_RUNNING ; 
 int /*<<< orphan*/  NFCMRVL_PB_BAIL_OUT ; 
 int /*<<< orphan*/  NFCMRVL_PHY_ERROR ; 
 int NFCMRVL_PHY_SPI ; 
 int NFC_PROTO_FELICA_MASK ; 
 int NFC_PROTO_ISO14443_B_MASK ; 
 int NFC_PROTO_ISO14443_MASK ; 
 int NFC_PROTO_ISO15693_MASK ; 
 int NFC_PROTO_JEWEL_MASK ; 
 int NFC_PROTO_MIFARE_MASK ; 
 int NFC_PROTO_NFC_DEP_MASK ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gpio_free (int) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int gpio_request_one (int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  kfree (struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 struct nfcmrvl_private* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,struct nfcmrvl_platform_data*,int) ; 
 struct nci_dev* nci_allocate_device (int /*<<< orphan*/ *,int,int,int) ; 
 int /*<<< orphan*/  nci_free_device (struct nci_dev*) ; 
 struct nfcmrvl_private* nci_get_drvdata (struct nci_dev*) ; 
 int /*<<< orphan*/  nci_recv_frame (struct nci_dev*,struct sk_buff*) ; 
 int nci_register_device (struct nci_dev*) ; 
 int /*<<< orphan*/  nci_set_config (struct nci_dev*,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  nci_set_drvdata (struct nci_dev*,struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  nci_unregister_device (struct nci_dev*) ; 
 int /*<<< orphan*/  nfc_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  nfc_info (struct device*,char*,...) ; 
 void nfcmrvl_chip_halt (struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  nfcmrvl_fw_dnld_abort (struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  nfcmrvl_fw_dnld_deinit (struct nfcmrvl_private*) ; 
 int nfcmrvl_fw_dnld_init (struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  nfcmrvl_fw_dnld_recv_frame (struct nfcmrvl_private*,struct sk_buff*) ; 
 int nfcmrvl_fw_dnld_start (struct nci_dev*,char const*) ; 
 int /*<<< orphan*/  nfcmrvl_nci_ops ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,scalar_t__) ; 
 unsigned char* skb_push (struct sk_buff*,scalar_t__) ; 
 int stub1 (struct nfcmrvl_private*) ; 
 int /*<<< orphan*/  stub2 (struct nfcmrvl_private*) ; 
 int stub3 (struct nfcmrvl_private*,struct sk_buff*) ; 
 int /*<<< orphan*/  test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int nfcmrvl_nci_open(struct nci_dev *ndev)
{
	struct nfcmrvl_private *priv = nci_get_drvdata(ndev);
	int err;

	if (test_and_set_bit(NFCMRVL_NCI_RUNNING, &priv->flags))
		return 0;

	/* Reset possible fault of previous session */
	clear_bit(NFCMRVL_PHY_ERROR, &priv->flags);

	err = priv->if_ops->nci_open(priv);

	if (err)
		clear_bit(NFCMRVL_NCI_RUNNING, &priv->flags);

	return err;
}

__attribute__((used)) static int nfcmrvl_nci_close(struct nci_dev *ndev)
{
	struct nfcmrvl_private *priv = nci_get_drvdata(ndev);

	if (!test_and_clear_bit(NFCMRVL_NCI_RUNNING, &priv->flags))
		return 0;

	priv->if_ops->nci_close(priv);

	return 0;
}

__attribute__((used)) static int nfcmrvl_nci_send(struct nci_dev *ndev, struct sk_buff *skb)
{
	struct nfcmrvl_private *priv = nci_get_drvdata(ndev);

	nfc_info(priv->dev, "send entry, len %d\n", skb->len);

	skb->dev = (void *)ndev;

	if (priv->config.hci_muxed) {
		unsigned char *hdr;
		unsigned char len = skb->len;

		hdr = skb_push(skb, NFCMRVL_HCI_EVENT_HEADER_SIZE);
		hdr[0] = NFCMRVL_HCI_COMMAND_CODE;
		hdr[1] = NFCMRVL_HCI_OGF;
		hdr[2] = NFCMRVL_HCI_OCF;
		hdr[3] = len;
	}

	return priv->if_ops->nci_send(priv, skb);
}

__attribute__((used)) static int nfcmrvl_nci_setup(struct nci_dev *ndev)
{
	__u8 val = 1;

	nci_set_config(ndev, NFCMRVL_PB_BAIL_OUT, 1, &val);
	return 0;
}

__attribute__((used)) static int nfcmrvl_nci_fw_download(struct nci_dev *ndev,
				   const char *firmware_name)
{
	return nfcmrvl_fw_dnld_start(ndev, firmware_name);
}

struct nfcmrvl_private *nfcmrvl_nci_register_dev(enum nfcmrvl_phy phy,
				void *drv_data,
				struct nfcmrvl_if_ops *ops,
				struct device *dev,
				struct nfcmrvl_platform_data *pdata)
{
	struct nfcmrvl_private *priv;
	int rc;
	int headroom;
	int tailroom;
	u32 protocols;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return ERR_PTR(-ENOMEM);

	priv->drv_data = drv_data;
	priv->if_ops = ops;
	priv->dev = dev;
	priv->phy = phy;

	memcpy(&priv->config, pdata, sizeof(*pdata));

	if (gpio_is_valid(priv->config.reset_n_io)) {
		rc = gpio_request_one(priv->config.reset_n_io,
				      GPIOF_OUT_INIT_LOW,
				      "nfcmrvl_reset_n");
		if (rc < 0) {
			priv->config.reset_n_io = -EINVAL;
			nfc_err(dev, "failed to request reset_n io\n");
		}
	}

	if (phy == NFCMRVL_PHY_SPI) {
		headroom = NCI_SPI_HDR_LEN;
		tailroom = 1;
	} else
		headroom = tailroom = 0;

	if (priv->config.hci_muxed)
		headroom += NFCMRVL_HCI_EVENT_HEADER_SIZE;

	protocols = NFC_PROTO_JEWEL_MASK
		| NFC_PROTO_MIFARE_MASK
		| NFC_PROTO_FELICA_MASK
		| NFC_PROTO_ISO14443_MASK
		| NFC_PROTO_ISO14443_B_MASK
		| NFC_PROTO_ISO15693_MASK
		| NFC_PROTO_NFC_DEP_MASK;

	priv->ndev = nci_allocate_device(&nfcmrvl_nci_ops, protocols,
					 headroom, tailroom);
	if (!priv->ndev) {
		nfc_err(dev, "nci_allocate_device failed\n");
		rc = -ENOMEM;
		goto error_free_gpio;
	}

	rc = nfcmrvl_fw_dnld_init(priv);
	if (rc) {
		nfc_err(dev, "failed to initialize FW download %d\n", rc);
		goto error_free_dev;
	}

	nci_set_drvdata(priv->ndev, priv);

	rc = nci_register_device(priv->ndev);
	if (rc) {
		nfc_err(dev, "nci_register_device failed %d\n", rc);
		goto error_fw_dnld_deinit;
	}

	/* Ensure that controller is powered off */
	nfcmrvl_chip_halt(priv);

	nfc_info(dev, "registered with nci successfully\n");
	return priv;

error_fw_dnld_deinit:
	nfcmrvl_fw_dnld_deinit(priv);
error_free_dev:
	nci_free_device(priv->ndev);
error_free_gpio:
	if (gpio_is_valid(priv->config.reset_n_io))
		gpio_free(priv->config.reset_n_io);
	kfree(priv);
	return ERR_PTR(rc);
}

void nfcmrvl_nci_unregister_dev(struct nfcmrvl_private *priv)
{
	struct nci_dev *ndev = priv->ndev;

	if (priv->ndev->nfc_dev->fw_download_in_progress)
		nfcmrvl_fw_dnld_abort(priv);

	nfcmrvl_fw_dnld_deinit(priv);

	if (gpio_is_valid(priv->config.reset_n_io))
		gpio_free(priv->config.reset_n_io);

	nci_unregister_device(ndev);
	nci_free_device(ndev);
	kfree(priv);
}

int nfcmrvl_nci_recv_frame(struct nfcmrvl_private *priv, struct sk_buff *skb)
{
	if (priv->config.hci_muxed) {
		if (skb->data[0] == NFCMRVL_HCI_EVENT_CODE &&
		    skb->data[1] == NFCMRVL_HCI_NFC_EVENT_CODE) {
			/* Data packet, let's extract NCI payload */
			skb_pull(skb, NFCMRVL_HCI_EVENT_HEADER_SIZE);
		} else {
			/* Skip this packet */
			kfree_skb(skb);
			return 0;
		}
	}

	if (priv->ndev->nfc_dev->fw_download_in_progress) {
		nfcmrvl_fw_dnld_recv_frame(priv, skb);
		return 0;
	}

	if (test_bit(NFCMRVL_NCI_RUNNING, &priv->flags))
		nci_recv_frame(priv->ndev, skb);
	else {
		/* Drop this packet since nobody wants it */
		kfree_skb(skb);
		return 0;
	}

	return 0;
}

void nfcmrvl_chip_reset(struct nfcmrvl_private *priv)
{
	/* Reset possible fault of previous session */
	clear_bit(NFCMRVL_PHY_ERROR, &priv->flags);

	if (priv->config.reset_n_io) {
		nfc_info(priv->dev, "reset the chip\n");
		gpio_set_value(priv->config.reset_n_io, 0);
		usleep_range(5000, 10000);
		gpio_set_value(priv->config.reset_n_io, 1);
	} else
		nfc_info(priv->dev, "no reset available on this interface\n");
}

void nfcmrvl_chip_halt(struct nfcmrvl_private *priv)
{
	if (priv->config.reset_n_io)
		gpio_set_value(priv->config.reset_n_io, 0);
}

int nfcmrvl_parse_dt(struct device_node *node,
		     struct nfcmrvl_platform_data *pdata)
{
	int reset_n_io;

	reset_n_io = of_get_named_gpio(node, "reset-n-io", 0);
	if (reset_n_io < 0) {
		pr_info("no reset-n-io config\n");
	} else if (!gpio_is_valid(reset_n_io)) {
		pr_err("invalid reset-n-io GPIO\n");
		return reset_n_io;
	}
	pdata->reset_n_io = reset_n_io;

	if (of_find_property(node, "hci-muxed", NULL))
		pdata->hci_muxed = 1;
	else
		pdata->hci_muxed = 0;

	return 0;
}


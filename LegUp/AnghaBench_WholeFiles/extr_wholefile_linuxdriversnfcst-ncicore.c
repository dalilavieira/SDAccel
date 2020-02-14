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
typedef  int u32 ;
struct st_nci_se_status {int dummy; } ;
struct st_nci_info {struct llt_ndlc* ndlc; int /*<<< orphan*/  flags; } ;
struct sk_buff {scalar_t__* data; void* dev; } ;
struct nci_mode_set_cmd {int mode; int /*<<< orphan*/  cmd_type; } ;
struct nci_dev {int dummy; } ;
struct llt_ndlc {struct nci_dev* ndev; int /*<<< orphan*/  dev; } ;
typedef  scalar_t__ __u8 ;
typedef  int __u32 ;

/* Variables and functions */
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NFC_PROTO_FELICA_MASK ; 
 int NFC_PROTO_ISO14443_B_MASK ; 
 int NFC_PROTO_ISO14443_MASK ; 
 int NFC_PROTO_ISO15693_MASK ; 
 int NFC_PROTO_JEWEL_MASK ; 
 int NFC_PROTO_MIFARE_MASK ; 
 int NFC_PROTO_NFC_DEP_MASK ; 
 scalar_t__ ST_NCI1_X_PROPRIETARY_ISO15693 ; 
 int /*<<< orphan*/  ST_NCI_CORE_PROP ; 
 int /*<<< orphan*/  ST_NCI_RUNNING ; 
 int /*<<< orphan*/  ST_NCI_SET_NFC_MODE ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct st_nci_info* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct nci_dev* nci_allocate_device (int /*<<< orphan*/ *,int,int,int) ; 
 int /*<<< orphan*/  nci_free_device (struct nci_dev*) ; 
 struct st_nci_info* nci_get_drvdata (struct nci_dev*) ; 
 int nci_prop_cmd (struct nci_dev*,int /*<<< orphan*/ ,int,scalar_t__*) ; 
 int nci_register_device (struct nci_dev*) ; 
 int /*<<< orphan*/  nci_req_complete (struct nci_dev*,scalar_t__) ; 
 int /*<<< orphan*/  nci_set_drvdata (struct nci_dev*,struct st_nci_info*) ; 
 int /*<<< orphan*/  nci_unregister_device (struct nci_dev*) ; 
 int /*<<< orphan*/  ndlc_close (struct llt_ndlc*) ; 
 int ndlc_open (struct llt_ndlc*) ; 
 int ndlc_send (struct llt_ndlc*,struct sk_buff*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  st_nci_ops ; 
 int st_nci_se_init (struct nci_dev*,struct st_nci_se_status*) ; 
 int st_nci_vendor_cmds_init (struct nci_dev*) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int st_nci_init(struct nci_dev *ndev)
{
	struct nci_mode_set_cmd cmd;

	cmd.cmd_type = ST_NCI_SET_NFC_MODE;
	cmd.mode = 1;

	return nci_prop_cmd(ndev, ST_NCI_CORE_PROP,
			sizeof(struct nci_mode_set_cmd), (__u8 *)&cmd);
}

__attribute__((used)) static int st_nci_open(struct nci_dev *ndev)
{
	struct st_nci_info *info = nci_get_drvdata(ndev);
	int r;

	if (test_and_set_bit(ST_NCI_RUNNING, &info->flags))
		return 0;

	r = ndlc_open(info->ndlc);
	if (r)
		clear_bit(ST_NCI_RUNNING, &info->flags);

	return r;
}

__attribute__((used)) static int st_nci_close(struct nci_dev *ndev)
{
	struct st_nci_info *info = nci_get_drvdata(ndev);

	if (!test_bit(ST_NCI_RUNNING, &info->flags))
		return 0;

	ndlc_close(info->ndlc);

	clear_bit(ST_NCI_RUNNING, &info->flags);

	return 0;
}

__attribute__((used)) static int st_nci_send(struct nci_dev *ndev, struct sk_buff *skb)
{
	struct st_nci_info *info = nci_get_drvdata(ndev);

	skb->dev = (void *)ndev;

	if (!test_bit(ST_NCI_RUNNING, &info->flags))
		return -EBUSY;

	return ndlc_send(info->ndlc, skb);
}

__attribute__((used)) static __u32 st_nci_get_rfprotocol(struct nci_dev *ndev,
					 __u8 rf_protocol)
{
	return rf_protocol == ST_NCI1_X_PROPRIETARY_ISO15693 ?
		NFC_PROTO_ISO15693_MASK : 0;
}

__attribute__((used)) static int st_nci_prop_rsp_packet(struct nci_dev *ndev,
					struct sk_buff *skb)
{
	__u8 status = skb->data[0];

	nci_req_complete(ndev, status);
	return 0;
}

int st_nci_probe(struct llt_ndlc *ndlc, int phy_headroom,
		 int phy_tailroom, struct st_nci_se_status *se_status)
{
	struct st_nci_info *info;
	int r;
	u32 protocols;

	info = devm_kzalloc(ndlc->dev,
			sizeof(struct st_nci_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	protocols = NFC_PROTO_JEWEL_MASK
		| NFC_PROTO_MIFARE_MASK
		| NFC_PROTO_FELICA_MASK
		| NFC_PROTO_ISO14443_MASK
		| NFC_PROTO_ISO14443_B_MASK
		| NFC_PROTO_ISO15693_MASK
		| NFC_PROTO_NFC_DEP_MASK;

	ndlc->ndev = nci_allocate_device(&st_nci_ops, protocols,
					phy_headroom, phy_tailroom);
	if (!ndlc->ndev) {
		pr_err("Cannot allocate nfc ndev\n");
		return -ENOMEM;
	}
	info->ndlc = ndlc;

	nci_set_drvdata(ndlc->ndev, info);

	r = st_nci_vendor_cmds_init(ndlc->ndev);
	if (r) {
		pr_err("Cannot register proprietary vendor cmds\n");
		goto err_reg_dev;
	}

	r = nci_register_device(ndlc->ndev);
	if (r) {
		pr_err("Cannot register nfc device to nci core\n");
		goto err_reg_dev;
	}

	return st_nci_se_init(ndlc->ndev, se_status);

err_reg_dev:
	nci_free_device(ndlc->ndev);
	return r;
}

void st_nci_remove(struct nci_dev *ndev)
{
	struct st_nci_info *info = nci_get_drvdata(ndev);

	ndlc_close(info->ndlc);

	nci_unregister_device(ndev);
	nci_free_device(ndev);
}


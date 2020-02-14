#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct sk_buff {int /*<<< orphan*/ * data; } ;
struct s3fwrn5_info {TYPE_3__* ndev; int /*<<< orphan*/  phy_id; TYPE_1__* phy_ops; } ;
struct nci_prop_stop_rfreg_cmd {int checksum; } ;
struct nci_prop_set_rfreg_cmd {scalar_t__ index; int /*<<< orphan*/  data; } ;
struct nci_prop_fw_cfg_cmd {int clk_type; int clk_speed; int clk_req; } ;
struct nci_driver_ops {int dummy; } ;
struct nci_dev {int dummy; } ;
struct firmware {int size; scalar_t__ data; } ;
typedef  int /*<<< orphan*/  stop_rfreg ;
typedef  int /*<<< orphan*/  fw_cfg ;
typedef  enum s3fwrn5_mode { ____Placeholder_s3fwrn5_mode } s3fwrn5_mode ;
typedef  int /*<<< orphan*/  __u8 ;
struct TYPE_6__ {TYPE_2__* nfc_dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int (* get_mode ) (int /*<<< orphan*/ ) ;int (* write ) (int /*<<< orphan*/ ,struct sk_buff*) ;int /*<<< orphan*/  (* set_wake ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* set_mode ) (int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 size_t ARRAY_SIZE (struct nci_driver_ops*) ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  NCI_PROP_FW_CFG ; 
 int /*<<< orphan*/  NCI_PROP_SET_RFREG ; 
 int /*<<< orphan*/  NCI_PROP_START_RFREG ; 
 int /*<<< orphan*/  NCI_PROP_STOP_RFREG ; 
 int S3FWRN5_RFREG_SECTION_SIZE ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int nci_prop_cmd (TYPE_3__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nci_req_complete (struct nci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,char const*,int /*<<< orphan*/ *) ; 
 struct nci_driver_ops* s3fwrn5_nci_prop_ops ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int) ; 
 int stub2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int) ; 
 int stub4 (int /*<<< orphan*/ ,struct sk_buff*) ; 

__attribute__((used)) static inline int s3fwrn5_set_mode(struct s3fwrn5_info *info,
	enum s3fwrn5_mode mode)
{
	if (!info->phy_ops->set_mode)
		return -ENOTSUPP;

	info->phy_ops->set_mode(info->phy_id, mode);

	return 0;
}

__attribute__((used)) static inline enum s3fwrn5_mode s3fwrn5_get_mode(struct s3fwrn5_info *info)
{
	if (!info->phy_ops->get_mode)
		return -ENOTSUPP;

	return info->phy_ops->get_mode(info->phy_id);
}

__attribute__((used)) static inline int s3fwrn5_set_wake(struct s3fwrn5_info *info, bool wake)
{
	if (!info->phy_ops->set_wake)
		return -ENOTSUPP;

	info->phy_ops->set_wake(info->phy_id, wake);

	return 0;
}

__attribute__((used)) static inline int s3fwrn5_write(struct s3fwrn5_info *info, struct sk_buff *skb)
{
	if (!info->phy_ops->write)
		return -ENOTSUPP;

	return info->phy_ops->write(info->phy_id, skb);
}

__attribute__((used)) static int s3fwrn5_nci_prop_rsp(struct nci_dev *ndev, struct sk_buff *skb)
{
	__u8 status = skb->data[0];

	nci_req_complete(ndev, status);
	return 0;
}

void s3fwrn5_nci_get_prop_ops(struct nci_driver_ops **ops, size_t *n)
{
	*ops = s3fwrn5_nci_prop_ops;
	*n = ARRAY_SIZE(s3fwrn5_nci_prop_ops);
}

int s3fwrn5_nci_rf_configure(struct s3fwrn5_info *info, const char *fw_name)
{
	const struct firmware *fw;
	struct nci_prop_fw_cfg_cmd fw_cfg;
	struct nci_prop_set_rfreg_cmd set_rfreg;
	struct nci_prop_stop_rfreg_cmd stop_rfreg;
	u32 checksum;
	int i, len;
	int ret;

	ret = request_firmware(&fw, fw_name, &info->ndev->nfc_dev->dev);
	if (ret < 0)
		return ret;

	/* Compute rfreg checksum */

	checksum = 0;
	for (i = 0; i < fw->size; i += 4)
		checksum += *((u32 *)(fw->data+i));

	/* Set default clock configuration for external crystal */

	fw_cfg.clk_type = 0x01;
	fw_cfg.clk_speed = 0xff;
	fw_cfg.clk_req = 0xff;
	ret = nci_prop_cmd(info->ndev, NCI_PROP_FW_CFG,
		sizeof(fw_cfg), (__u8 *)&fw_cfg);
	if (ret < 0)
		goto out;

	/* Start rfreg configuration */

	dev_info(&info->ndev->nfc_dev->dev,
		"rfreg configuration update: %s\n", fw_name);

	ret = nci_prop_cmd(info->ndev, NCI_PROP_START_RFREG, 0, NULL);
	if (ret < 0) {
		dev_err(&info->ndev->nfc_dev->dev,
			"Unable to start rfreg update\n");
		goto out;
	}

	/* Update rfreg */

	set_rfreg.index = 0;
	for (i = 0; i < fw->size; i += S3FWRN5_RFREG_SECTION_SIZE) {
		len = (fw->size - i < S3FWRN5_RFREG_SECTION_SIZE) ?
			(fw->size - i) : S3FWRN5_RFREG_SECTION_SIZE;
		memcpy(set_rfreg.data, fw->data+i, len);
		ret = nci_prop_cmd(info->ndev, NCI_PROP_SET_RFREG,
			len+1, (__u8 *)&set_rfreg);
		if (ret < 0) {
			dev_err(&info->ndev->nfc_dev->dev,
				"rfreg update error (code=%d)\n", ret);
			goto out;
		}
		set_rfreg.index++;
	}

	/* Finish rfreg configuration */

	stop_rfreg.checksum = checksum & 0xffff;
	ret = nci_prop_cmd(info->ndev, NCI_PROP_STOP_RFREG,
		sizeof(stop_rfreg), (__u8 *)&stop_rfreg);
	if (ret < 0) {
		dev_err(&info->ndev->nfc_dev->dev,
			"Unable to stop rfreg update\n");
		goto out;
	}

	dev_info(&info->ndev->nfc_dev->dev,
		"rfreg configuration update: success\n");
out:
	release_firmware(fw);
	return ret;
}


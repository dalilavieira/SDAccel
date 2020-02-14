#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct s3fwrn5_phy_ops {int (* get_mode ) (void*) ;int (* write ) (void*,struct sk_buff*) ;int /*<<< orphan*/  (* set_wake ) (void*,int) ;int /*<<< orphan*/  (* set_mode ) (void*,int) ;} ;
struct TYPE_11__ {struct nci_dev* ndev; } ;
struct s3fwrn5_info {unsigned int max_payload; struct nci_dev* ndev; TYPE_3__ fw_info; int /*<<< orphan*/  mutex; struct s3fwrn5_phy_ops const* phy_ops; struct device* pdev; void* phy_id; } ;
struct nci_dev {TYPE_1__* nfc_dev; int /*<<< orphan*/  manufact_specific_info; } ;
struct device {int dummy; } ;
typedef  enum s3fwrn5_mode { ____Placeholder_s3fwrn5_mode } s3fwrn5_mode ;
struct TYPE_10__ {int /*<<< orphan*/  n_prop_ops; int /*<<< orphan*/  prop_ops; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ S3FWRN5_MODE_COLD ; 
#define  S3FWRN5_MODE_FW 129 
#define  S3FWRN5_MODE_NCI 128 
 int /*<<< orphan*/  S3FWRN5_NFC_PROTOCOLS ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 struct s3fwrn5_info* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct nci_dev* nci_allocate_device (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int nci_core_init (struct nci_dev*) ; 
 int nci_core_reset (struct nci_dev*) ; 
 int /*<<< orphan*/  nci_free_device (struct nci_dev*) ; 
 struct s3fwrn5_info* nci_get_drvdata (struct nci_dev*) ; 
 int nci_recv_frame (struct nci_dev*,struct sk_buff*) ; 
 int nci_register_device (struct nci_dev*) ; 
 int /*<<< orphan*/  nci_set_drvdata (struct nci_dev*,struct s3fwrn5_info*) ; 
 int /*<<< orphan*/  nci_set_parent_dev (struct nci_dev*,struct device*) ; 
 int /*<<< orphan*/  nci_unregister_device (struct nci_dev*) ; 
 int s3fwrn5_fw_check_version (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s3fwrn5_fw_cleanup (TYPE_3__*) ; 
 int s3fwrn5_fw_download (TYPE_3__*) ; 
 int /*<<< orphan*/  s3fwrn5_fw_init (TYPE_3__*,char*) ; 
 int s3fwrn5_fw_recv_frame (struct nci_dev*,struct sk_buff*) ; 
 int s3fwrn5_fw_setup (TYPE_3__*) ; 
 int /*<<< orphan*/  s3fwrn5_nci_get_prop_ops (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_2__ s3fwrn5_nci_ops ; 
 int s3fwrn5_nci_rf_configure (struct s3fwrn5_info*,char*) ; 
 int /*<<< orphan*/  stub1 (void*,int) ; 
 int stub2 (void*) ; 
 int /*<<< orphan*/  stub3 (void*,int) ; 
 int stub4 (void*,struct sk_buff*) ; 

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

__attribute__((used)) static int s3fwrn5_firmware_update(struct s3fwrn5_info *info)
{
	bool need_update;
	int ret;

	s3fwrn5_fw_init(&info->fw_info, "sec_s3fwrn5_firmware.bin");

	/* Update firmware */

	s3fwrn5_set_wake(info, false);
	s3fwrn5_set_mode(info, S3FWRN5_MODE_FW);

	ret = s3fwrn5_fw_setup(&info->fw_info);
	if (ret < 0)
		return ret;

	need_update = s3fwrn5_fw_check_version(&info->fw_info,
		info->ndev->manufact_specific_info);
	if (!need_update)
		goto out;

	dev_info(&info->ndev->nfc_dev->dev, "Detected new firmware version\n");

	ret = s3fwrn5_fw_download(&info->fw_info);
	if (ret < 0)
		goto out;

	/* Update RF configuration */

	s3fwrn5_set_mode(info, S3FWRN5_MODE_NCI);

	s3fwrn5_set_wake(info, true);
	ret = s3fwrn5_nci_rf_configure(info, "sec_s3fwrn5_rfreg.bin");
	s3fwrn5_set_wake(info, false);

out:
	s3fwrn5_set_mode(info, S3FWRN5_MODE_COLD);
	s3fwrn5_fw_cleanup(&info->fw_info);
	return ret;
}

__attribute__((used)) static int s3fwrn5_nci_open(struct nci_dev *ndev)
{
	struct s3fwrn5_info *info = nci_get_drvdata(ndev);

	if (s3fwrn5_get_mode(info) != S3FWRN5_MODE_COLD)
		return  -EBUSY;

	s3fwrn5_set_mode(info, S3FWRN5_MODE_NCI);
	s3fwrn5_set_wake(info, true);

	return 0;
}

__attribute__((used)) static int s3fwrn5_nci_close(struct nci_dev *ndev)
{
	struct s3fwrn5_info *info = nci_get_drvdata(ndev);

	s3fwrn5_set_wake(info, false);
	s3fwrn5_set_mode(info, S3FWRN5_MODE_COLD);

	return 0;
}

__attribute__((used)) static int s3fwrn5_nci_send(struct nci_dev *ndev, struct sk_buff *skb)
{
	struct s3fwrn5_info *info = nci_get_drvdata(ndev);
	int ret;

	mutex_lock(&info->mutex);

	if (s3fwrn5_get_mode(info) != S3FWRN5_MODE_NCI) {
		mutex_unlock(&info->mutex);
		return -EINVAL;
	}

	ret = s3fwrn5_write(info, skb);
	if (ret < 0)
		kfree_skb(skb);

	mutex_unlock(&info->mutex);
	return ret;
}

__attribute__((used)) static int s3fwrn5_nci_post_setup(struct nci_dev *ndev)
{
	struct s3fwrn5_info *info = nci_get_drvdata(ndev);
	int ret;

	ret = s3fwrn5_firmware_update(info);
	if (ret < 0)
		goto out;

	/* NCI core reset */

	s3fwrn5_set_mode(info, S3FWRN5_MODE_NCI);
	s3fwrn5_set_wake(info, true);

	ret = nci_core_reset(info->ndev);
	if (ret < 0)
		goto out;

	ret = nci_core_init(info->ndev);

out:
	return ret;
}

int s3fwrn5_probe(struct nci_dev **ndev, void *phy_id, struct device *pdev,
	const struct s3fwrn5_phy_ops *phy_ops, unsigned int max_payload)
{
	struct s3fwrn5_info *info;
	int ret;

	info = devm_kzalloc(pdev, sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->phy_id = phy_id;
	info->pdev = pdev;
	info->phy_ops = phy_ops;
	info->max_payload = max_payload;
	mutex_init(&info->mutex);

	s3fwrn5_set_mode(info, S3FWRN5_MODE_COLD);

	s3fwrn5_nci_get_prop_ops(&s3fwrn5_nci_ops.prop_ops,
		&s3fwrn5_nci_ops.n_prop_ops);

	info->ndev = nci_allocate_device(&s3fwrn5_nci_ops,
		S3FWRN5_NFC_PROTOCOLS, 0, 0);
	if (!info->ndev)
		return -ENOMEM;

	nci_set_parent_dev(info->ndev, pdev);
	nci_set_drvdata(info->ndev, info);

	ret = nci_register_device(info->ndev);
	if (ret < 0) {
		nci_free_device(info->ndev);
		return ret;
	}

	info->fw_info.ndev = info->ndev;

	*ndev = info->ndev;

	return ret;
}

void s3fwrn5_remove(struct nci_dev *ndev)
{
	struct s3fwrn5_info *info = nci_get_drvdata(ndev);

	s3fwrn5_set_mode(info, S3FWRN5_MODE_COLD);

	nci_unregister_device(ndev);
	nci_free_device(ndev);
}

int s3fwrn5_recv_frame(struct nci_dev *ndev, struct sk_buff *skb,
	enum s3fwrn5_mode mode)
{
	switch (mode) {
	case S3FWRN5_MODE_NCI:
		return nci_recv_frame(ndev, skb);
	case S3FWRN5_MODE_FW:
		return s3fwrn5_fw_recv_frame(ndev, skb);
	default:
		return -ENODEV;
	}
}


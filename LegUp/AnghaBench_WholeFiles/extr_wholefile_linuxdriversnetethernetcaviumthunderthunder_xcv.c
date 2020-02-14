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
typedef  int u64 ;
struct xcv {int dummy; } ;
struct pci_device_id {int dummy; } ;
struct device {int dummy; } ;
struct pci_dev {int revision; scalar_t__ subsystem_device; struct device dev; } ;
struct TYPE_5__ {scalar_t__ reg_base; struct pci_dev* pdev; } ;

/* Variables and functions */
 int CLKRX_BYP ; 
 int CLK_RESET ; 
 int COMP_EN ; 
 int DLL_RESET ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NIC_NODE_ID_MASK ; 
 int NIC_NODE_ID_SHIFT ; 
 int /*<<< orphan*/  PCI_CFG_REG_BAR_NUM ; 
 scalar_t__ PCI_SUBSYS_DEVID_88XX_NIC_PF ; 
 int PORT_EN ; 
 int RX_DATA_RESET ; 
 int RX_PKT_RESET ; 
 int TX_DATA_RESET ; 
 int TX_PKT_RESET ; 
 scalar_t__ XCV_BATCH_CRD_RET ; 
 scalar_t__ XCV_CTL ; 
 scalar_t__ XCV_DLL_CTL ; 
 scalar_t__ XCV_RESET ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  devm_kfree (struct device*,TYPE_1__*) ; 
 TYPE_1__* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,TYPE_1__*) ; 
 scalar_t__ pcim_iomap (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int readq_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writeq_relaxed (int,scalar_t__) ; 
 TYPE_1__* xcv ; 

__attribute__((used)) static inline int nic_get_node_id(struct pci_dev *pdev)
{
	u64 addr = pci_resource_start(pdev, PCI_CFG_REG_BAR_NUM);
	return ((addr >> NIC_NODE_ID_SHIFT) & NIC_NODE_ID_MASK);
}

__attribute__((used)) static inline bool pass1_silicon(struct pci_dev *pdev)
{
	return (pdev->revision < 8) &&
		(pdev->subsystem_device == PCI_SUBSYS_DEVID_88XX_NIC_PF);
}

__attribute__((used)) static inline bool pass2_silicon(struct pci_dev *pdev)
{
	return (pdev->revision >= 8) &&
		(pdev->subsystem_device == PCI_SUBSYS_DEVID_88XX_NIC_PF);
}

void xcv_init_hw(void)
{
	u64  cfg;

	/* Take DLL out of reset */
	cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
	cfg &= ~DLL_RESET;
	writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);

	/* Take clock tree out of reset */
	cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
	cfg &= ~CLK_RESET;
	writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
	/* Wait for DLL to lock */
	msleep(1);

	/* Configure DLL - enable or bypass
	 * TX no bypass, RX bypass
	 */
	cfg = readq_relaxed(xcv->reg_base + XCV_DLL_CTL);
	cfg &= ~0xFF03;
	cfg |= CLKRX_BYP;
	writeq_relaxed(cfg, xcv->reg_base + XCV_DLL_CTL);

	/* Enable compensation controller and force the
	 * write to be visible to HW by readig back.
	 */
	cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
	cfg |= COMP_EN;
	writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
	readq_relaxed(xcv->reg_base + XCV_RESET);
	/* Wait for compensation state machine to lock */
	msleep(10);

	/* enable the XCV block */
	cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
	cfg |= PORT_EN;
	writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);

	cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
	cfg |= CLK_RESET;
	writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
}

void xcv_setup_link(bool link_up, int link_speed)
{
	u64  cfg;
	int speed = 2;

	if (!xcv) {
		pr_err("XCV init not done, probe may have failed\n");
		return;
	}

	if (link_speed == 100)
		speed = 1;
	else if (link_speed == 10)
		speed = 0;

	if (link_up) {
		/* set operating speed */
		cfg = readq_relaxed(xcv->reg_base + XCV_CTL);
		cfg &= ~0x03;
		cfg |= speed;
		writeq_relaxed(cfg, xcv->reg_base + XCV_CTL);

		/* Reset datapaths */
		cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
		cfg |= TX_DATA_RESET | RX_DATA_RESET;
		writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);

		/* Enable the packet flow */
		cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
		cfg |= TX_PKT_RESET | RX_PKT_RESET;
		writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);

		/* Return credits to RGX */
		writeq_relaxed(0x01, xcv->reg_base + XCV_BATCH_CRD_RET);
	} else {
		/* Disable packet flow */
		cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
		cfg &= ~(TX_PKT_RESET | RX_PKT_RESET);
		writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
		readq_relaxed(xcv->reg_base + XCV_RESET);
	}
}

__attribute__((used)) static int xcv_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
	int err;
	struct device *dev = &pdev->dev;

	xcv = devm_kzalloc(dev, sizeof(struct xcv), GFP_KERNEL);
	if (!xcv)
		return -ENOMEM;
	xcv->pdev = pdev;

	pci_set_drvdata(pdev, xcv);

	err = pci_enable_device(pdev);
	if (err) {
		dev_err(dev, "Failed to enable PCI device\n");
		goto err_kfree;
	}

	err = pci_request_regions(pdev, DRV_NAME);
	if (err) {
		dev_err(dev, "PCI request regions failed 0x%x\n", err);
		goto err_disable_device;
	}

	/* MAP configuration registers */
	xcv->reg_base = pcim_iomap(pdev, PCI_CFG_REG_BAR_NUM, 0);
	if (!xcv->reg_base) {
		dev_err(dev, "XCV: Cannot map CSR memory space, aborting\n");
		err = -ENOMEM;
		goto err_release_regions;
	}

	return 0;

err_release_regions:
	pci_release_regions(pdev);
err_disable_device:
	pci_disable_device(pdev);
err_kfree:
	devm_kfree(dev, xcv);
	xcv = NULL;
	return err;
}

__attribute__((used)) static void xcv_remove(struct pci_dev *pdev)
{
	struct device *dev = &pdev->dev;

	if (xcv) {
		devm_kfree(dev, xcv);
		xcv = NULL;
	}

	pci_release_regions(pdev);
	pci_disable_device(pdev);
}


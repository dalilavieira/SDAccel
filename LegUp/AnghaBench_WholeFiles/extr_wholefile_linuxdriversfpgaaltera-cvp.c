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
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct fpga_manager {struct altera_cvp_conf* priv; int /*<<< orphan*/  dev; } ;
struct fpga_image_info {int flags; } ;
struct device_driver {int dummy; } ;
struct altera_cvp_conf {void (* write_data ) (struct altera_cvp_conf*,int const) ;int numclks; scalar_t__ map; int /*<<< orphan*/  mgr_name; struct pci_dev* pci_dev; } ;
typedef  int ssize_t ;
typedef  enum fpga_mgr_states { ____Placeholder_fpga_mgr_states } fpga_mgr_states ;

/* Variables and functions */
 char* ALTERA_CVP_MGR_NAME ; 
 int BIT (size_t) ; 
 int /*<<< orphan*/  CVP_BAR ; 
 unsigned int CVP_DUMMY_WR ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROTO ; 
 int ETIMEDOUT ; 
 int FPGA_MGR_COMPRESSED_BITSTREAM ; 
 int FPGA_MGR_ENCRYPTED_BITSTREAM ; 
 int FPGA_MGR_PARTIAL_RECONFIG ; 
 int FPGA_MGR_STATE_OPERATING ; 
 int FPGA_MGR_STATE_POWER_UP ; 
 int FPGA_MGR_STATE_UNKNOWN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PCI_COMMAND ; 
 int PCI_COMMAND_MEMORY ; 
 size_t SZ_4K ; 
 int TIMEOUT_US ; 
 int /*<<< orphan*/  VSE_CVP_DATA ; 
 int /*<<< orphan*/  VSE_CVP_MODE_CTRL ; 
 int VSE_CVP_MODE_CTRL_CVP_MODE ; 
 int VSE_CVP_MODE_CTRL_HIP_CLK_SEL ; 
 int VSE_CVP_MODE_CTRL_NUMCLKS_MASK ; 
 int VSE_CVP_MODE_CTRL_NUMCLKS_OFF ; 
 int /*<<< orphan*/  VSE_CVP_PROG_CTRL ; 
 int VSE_CVP_PROG_CTRL_CONFIG ; 
 int VSE_CVP_PROG_CTRL_START_XFER ; 
 int /*<<< orphan*/  VSE_CVP_STATUS ; 
 int VSE_CVP_STATUS_CFG_DONE ; 
 int VSE_CVP_STATUS_CFG_ERR ; 
 int VSE_CVP_STATUS_CFG_RDY ; 
 int VSE_CVP_STATUS_CVP_EN ; 
 int VSE_CVP_STATUS_PLD_CLK_IN_USE ; 
 int VSE_CVP_STATUS_USERMODE ; 
 int /*<<< orphan*/  VSE_PCIE_EXT_CAP_ID ; 
 int VSE_PCIE_EXT_CAP_ID_VAL ; 
 int VSE_UNCOR_ERR_CVP_CFG_ERR ; 
 int /*<<< orphan*/  VSE_UNCOR_ERR_STATUS ; 
 int altera_cvp_chkcfg ; 
 int /*<<< orphan*/  altera_cvp_ops ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct altera_cvp_conf* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct fpga_manager* fpga_mgr_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct altera_cvp_conf*) ; 
 int /*<<< orphan*/  fpga_mgr_free (struct fpga_manager*) ; 
 int fpga_mgr_register (struct fpga_manager*) ; 
 int /*<<< orphan*/  fpga_mgr_unregister (struct fpga_manager*) ; 
 int kstrtobool (char const*,int*) ; 
 struct fpga_manager* pci_get_drvdata (struct pci_dev*) ; 
 scalar_t__ pci_iomap (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,scalar_t__) ; 
 char* pci_name (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_release_region (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pci_request_region (struct pci_dev*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct fpga_manager*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int snprintf (char*,int,char*,...) ; 
 void stub1 (struct altera_cvp_conf*,int const) ; 
 void stub2 (struct altera_cvp_conf*,int const) ; 
 void stub3 (struct altera_cvp_conf*,int const) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static enum fpga_mgr_states altera_cvp_state(struct fpga_manager *mgr)
{
	struct altera_cvp_conf *conf = mgr->priv;
	u32 status;

	pci_read_config_dword(conf->pci_dev, VSE_CVP_STATUS, &status);

	if (status & VSE_CVP_STATUS_CFG_DONE)
		return FPGA_MGR_STATE_OPERATING;

	if (status & VSE_CVP_STATUS_CVP_EN)
		return FPGA_MGR_STATE_POWER_UP;

	return FPGA_MGR_STATE_UNKNOWN;
}

__attribute__((used)) static void altera_cvp_write_data_iomem(struct altera_cvp_conf *conf, u32 val)
{
	writel(val, conf->map);
}

__attribute__((used)) static void altera_cvp_write_data_config(struct altera_cvp_conf *conf, u32 val)
{
	pci_write_config_dword(conf->pci_dev, VSE_CVP_DATA, val);
}

__attribute__((used)) static void altera_cvp_dummy_write(struct altera_cvp_conf *conf)
{
	unsigned int i;
	u32 val;

	/* set 1 CVP clock cycle for every CVP Data Register Write */
	pci_read_config_dword(conf->pci_dev, VSE_CVP_MODE_CTRL, &val);
	val &= ~VSE_CVP_MODE_CTRL_NUMCLKS_MASK;
	val |= 1 << VSE_CVP_MODE_CTRL_NUMCLKS_OFF;
	pci_write_config_dword(conf->pci_dev, VSE_CVP_MODE_CTRL, val);

	for (i = 0; i < CVP_DUMMY_WR; i++)
		conf->write_data(conf, 0); /* dummy data, could be any value */
}

__attribute__((used)) static int altera_cvp_wait_status(struct altera_cvp_conf *conf, u32 status_mask,
				  u32 status_val, int timeout_us)
{
	unsigned int retries;
	u32 val;

	retries = timeout_us / 10;
	if (timeout_us % 10)
		retries++;

	do {
		pci_read_config_dword(conf->pci_dev, VSE_CVP_STATUS, &val);
		if ((val & status_mask) == status_val)
			return 0;

		/* use small usleep value to re-check and break early */
		usleep_range(10, 11);
	} while (--retries);

	return -ETIMEDOUT;
}

__attribute__((used)) static int altera_cvp_teardown(struct fpga_manager *mgr,
			       struct fpga_image_info *info)
{
	struct altera_cvp_conf *conf = mgr->priv;
	struct pci_dev *pdev = conf->pci_dev;
	int ret;
	u32 val;

	/* STEP 12 - reset START_XFER bit */
	pci_read_config_dword(pdev, VSE_CVP_PROG_CTRL, &val);
	val &= ~VSE_CVP_PROG_CTRL_START_XFER;
	pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);

	/* STEP 13 - reset CVP_CONFIG bit */
	val &= ~VSE_CVP_PROG_CTRL_CONFIG;
	pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);

	/*
	 * STEP 14
	 * - set CVP_NUMCLKS to 1 and then issue CVP_DUMMY_WR dummy
	 *   writes to the HIP
	 */
	altera_cvp_dummy_write(conf); /* from CVP clock to internal clock */

	/* STEP 15 - poll CVP_CONFIG_READY bit for 0 with 10us timeout */
	ret = altera_cvp_wait_status(conf, VSE_CVP_STATUS_CFG_RDY, 0, 10);
	if (ret)
		dev_err(&mgr->dev, "CFG_RDY == 0 timeout\n");

	return ret;
}

__attribute__((used)) static int altera_cvp_write_init(struct fpga_manager *mgr,
				 struct fpga_image_info *info,
				 const char *buf, size_t count)
{
	struct altera_cvp_conf *conf = mgr->priv;
	struct pci_dev *pdev = conf->pci_dev;
	u32 iflags, val;
	int ret;

	iflags = info ? info->flags : 0;

	if (iflags & FPGA_MGR_PARTIAL_RECONFIG) {
		dev_err(&mgr->dev, "Partial reconfiguration not supported.\n");
		return -EINVAL;
	}

	/* Determine allowed clock to data ratio */
	if (iflags & FPGA_MGR_COMPRESSED_BITSTREAM)
		conf->numclks = 8; /* ratio for all compressed images */
	else if (iflags & FPGA_MGR_ENCRYPTED_BITSTREAM)
		conf->numclks = 4; /* for uncompressed and encrypted images */
	else
		conf->numclks = 1; /* for uncompressed and unencrypted images */

	/* STEP 1 - read CVP status and check CVP_EN flag */
	pci_read_config_dword(pdev, VSE_CVP_STATUS, &val);
	if (!(val & VSE_CVP_STATUS_CVP_EN)) {
		dev_err(&mgr->dev, "CVP mode off: 0x%04x\n", val);
		return -ENODEV;
	}

	if (val & VSE_CVP_STATUS_CFG_RDY) {
		dev_warn(&mgr->dev, "CvP already started, teardown first\n");
		ret = altera_cvp_teardown(mgr, info);
		if (ret)
			return ret;
	}

	/*
	 * STEP 2
	 * - set HIP_CLK_SEL and CVP_MODE (must be set in the order mentioned)
	 */
	/* switch from fabric to PMA clock */
	pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
	val |= VSE_CVP_MODE_CTRL_HIP_CLK_SEL;
	pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);

	/* set CVP mode */
	pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
	val |= VSE_CVP_MODE_CTRL_CVP_MODE;
	pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);

	/*
	 * STEP 3
	 * - set CVP_NUMCLKS to 1 and issue CVP_DUMMY_WR dummy writes to the HIP
	 */
	altera_cvp_dummy_write(conf);

	/* STEP 4 - set CVP_CONFIG bit */
	pci_read_config_dword(pdev, VSE_CVP_PROG_CTRL, &val);
	/* request control block to begin transfer using CVP */
	val |= VSE_CVP_PROG_CTRL_CONFIG;
	pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);

	/* STEP 5 - poll CVP_CONFIG READY for 1 with 10us timeout */
	ret = altera_cvp_wait_status(conf, VSE_CVP_STATUS_CFG_RDY,
				     VSE_CVP_STATUS_CFG_RDY, 10);
	if (ret) {
		dev_warn(&mgr->dev, "CFG_RDY == 1 timeout\n");
		return ret;
	}

	/*
	 * STEP 6
	 * - set CVP_NUMCLKS to 1 and issue CVP_DUMMY_WR dummy writes to the HIP
	 */
	altera_cvp_dummy_write(conf);

	/* STEP 7 - set START_XFER */
	pci_read_config_dword(pdev, VSE_CVP_PROG_CTRL, &val);
	val |= VSE_CVP_PROG_CTRL_START_XFER;
	pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);

	/* STEP 8 - start transfer (set CVP_NUMCLKS for bitstream) */
	pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
	val &= ~VSE_CVP_MODE_CTRL_NUMCLKS_MASK;
	val |= conf->numclks << VSE_CVP_MODE_CTRL_NUMCLKS_OFF;
	pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);

	return 0;
}

__attribute__((used)) static inline int altera_cvp_chk_error(struct fpga_manager *mgr, size_t bytes)
{
	struct altera_cvp_conf *conf = mgr->priv;
	u32 val;

	/* STEP 10 (optional) - check CVP_CONFIG_ERROR flag */
	pci_read_config_dword(conf->pci_dev, VSE_CVP_STATUS, &val);
	if (val & VSE_CVP_STATUS_CFG_ERR) {
		dev_err(&mgr->dev, "CVP_CONFIG_ERROR after %zu bytes!\n",
			bytes);
		return -EPROTO;
	}
	return 0;
}

__attribute__((used)) static int altera_cvp_write(struct fpga_manager *mgr, const char *buf,
			    size_t count)
{
	struct altera_cvp_conf *conf = mgr->priv;
	const u32 *data;
	size_t done, remaining;
	int status = 0;
	u32 mask;

	/* STEP 9 - write 32-bit data from RBF file to CVP data register */
	data = (u32 *)buf;
	remaining = count;
	done = 0;

	while (remaining >= 4) {
		conf->write_data(conf, *data++);
		done += 4;
		remaining -= 4;

		/*
		 * STEP 10 (optional) and STEP 11
		 * - check error flag
		 * - loop until data transfer completed
		 * Config images can be huge (more than 40 MiB), so
		 * only check after a new 4k data block has been written.
		 * This reduces the number of checks and speeds up the
		 * configuration process.
		 */
		if (altera_cvp_chkcfg && !(done % SZ_4K)) {
			status = altera_cvp_chk_error(mgr, done);
			if (status < 0)
				return status;
		}
	}

	/* write up to 3 trailing bytes, if any */
	mask = BIT(remaining * 8) - 1;
	if (mask)
		conf->write_data(conf, *data & mask);

	if (altera_cvp_chkcfg)
		status = altera_cvp_chk_error(mgr, count);

	return status;
}

__attribute__((used)) static int altera_cvp_write_complete(struct fpga_manager *mgr,
				     struct fpga_image_info *info)
{
	struct altera_cvp_conf *conf = mgr->priv;
	struct pci_dev *pdev = conf->pci_dev;
	int ret;
	u32 mask;
	u32 val;

	ret = altera_cvp_teardown(mgr, info);
	if (ret)
		return ret;

	/* STEP 16 - check CVP_CONFIG_ERROR_LATCHED bit */
	pci_read_config_dword(pdev, VSE_UNCOR_ERR_STATUS, &val);
	if (val & VSE_UNCOR_ERR_CVP_CFG_ERR) {
		dev_err(&mgr->dev, "detected CVP_CONFIG_ERROR_LATCHED!\n");
		return -EPROTO;
	}

	/* STEP 17 - reset CVP_MODE and HIP_CLK_SEL bit */
	pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
	val &= ~VSE_CVP_MODE_CTRL_HIP_CLK_SEL;
	val &= ~VSE_CVP_MODE_CTRL_CVP_MODE;
	pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);

	/* STEP 18 - poll PLD_CLK_IN_USE and USER_MODE bits */
	mask = VSE_CVP_STATUS_PLD_CLK_IN_USE | VSE_CVP_STATUS_USERMODE;
	ret = altera_cvp_wait_status(conf, mask, mask, TIMEOUT_US);
	if (ret)
		dev_err(&mgr->dev, "PLD_CLK_IN_USE|USERMODE timeout\n");

	return ret;
}

__attribute__((used)) static ssize_t chkcfg_show(struct device_driver *dev, char *buf)
{
	return snprintf(buf, 3, "%d\n", altera_cvp_chkcfg);
}

__attribute__((used)) static ssize_t chkcfg_store(struct device_driver *drv, const char *buf,
			    size_t count)
{
	int ret;

	ret = kstrtobool(buf, &altera_cvp_chkcfg);
	if (ret)
		return ret;

	return count;
}

__attribute__((used)) static int altera_cvp_probe(struct pci_dev *pdev,
			    const struct pci_device_id *dev_id)
{
	struct altera_cvp_conf *conf;
	struct fpga_manager *mgr;
	u16 cmd, val;
	u32 regval;
	int ret;

	/*
	 * First check if this is the expected FPGA device. PCI config
	 * space access works without enabling the PCI device, memory
	 * space access is enabled further down.
	 */
	pci_read_config_word(pdev, VSE_PCIE_EXT_CAP_ID, &val);
	if (val != VSE_PCIE_EXT_CAP_ID_VAL) {
		dev_err(&pdev->dev, "Wrong EXT_CAP_ID value 0x%x\n", val);
		return -ENODEV;
	}

	pci_read_config_dword(pdev, VSE_CVP_STATUS, &regval);
	if (!(regval & VSE_CVP_STATUS_CVP_EN)) {
		dev_err(&pdev->dev,
			"CVP is disabled for this device: CVP_STATUS Reg 0x%x\n",
			regval);
		return -ENODEV;
	}

	conf = devm_kzalloc(&pdev->dev, sizeof(*conf), GFP_KERNEL);
	if (!conf)
		return -ENOMEM;

	/*
	 * Enable memory BAR access. We cannot use pci_enable_device() here
	 * because it will make the driver unusable with FPGA devices that
	 * have additional big IOMEM resources (e.g. 4GiB BARs) on 32-bit
	 * platform. Such BARs will not have an assigned address range and
	 * pci_enable_device() will fail, complaining about not claimed BAR,
	 * even if the concerned BAR is not needed for FPGA configuration
	 * at all. Thus, enable the device via PCI config space command.
	 */
	pci_read_config_word(pdev, PCI_COMMAND, &cmd);
	if (!(cmd & PCI_COMMAND_MEMORY)) {
		cmd |= PCI_COMMAND_MEMORY;
		pci_write_config_word(pdev, PCI_COMMAND, cmd);
	}

	ret = pci_request_region(pdev, CVP_BAR, "CVP");
	if (ret) {
		dev_err(&pdev->dev, "Requesting CVP BAR region failed\n");
		goto err_disable;
	}

	conf->pci_dev = pdev;
	conf->write_data = altera_cvp_write_data_iomem;

	conf->map = pci_iomap(pdev, CVP_BAR, 0);
	if (!conf->map) {
		dev_warn(&pdev->dev, "Mapping CVP BAR failed\n");
		conf->write_data = altera_cvp_write_data_config;
	}

	snprintf(conf->mgr_name, sizeof(conf->mgr_name), "%s @%s",
		 ALTERA_CVP_MGR_NAME, pci_name(pdev));

	mgr = fpga_mgr_create(&pdev->dev, conf->mgr_name,
			      &altera_cvp_ops, conf);
	if (!mgr) {
		ret = -ENOMEM;
		goto err_unmap;
	}

	pci_set_drvdata(pdev, mgr);

	ret = fpga_mgr_register(mgr);
	if (ret) {
		fpga_mgr_free(mgr);
		goto err_unmap;
	}

	return 0;

err_unmap:
	if (conf->map)
		pci_iounmap(pdev, conf->map);
	pci_release_region(pdev, CVP_BAR);
err_disable:
	cmd &= ~PCI_COMMAND_MEMORY;
	pci_write_config_word(pdev, PCI_COMMAND, cmd);
	return ret;
}

__attribute__((used)) static void altera_cvp_remove(struct pci_dev *pdev)
{
	struct fpga_manager *mgr = pci_get_drvdata(pdev);
	struct altera_cvp_conf *conf = mgr->priv;
	u16 cmd;

	fpga_mgr_unregister(mgr);
	if (conf->map)
		pci_iounmap(pdev, conf->map);
	pci_release_region(pdev, CVP_BAR);
	pci_read_config_word(pdev, PCI_COMMAND, &cmd);
	cmd &= ~PCI_COMMAND_MEMORY;
	pci_write_config_word(pdev, PCI_COMMAND, cmd);
}


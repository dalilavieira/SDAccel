#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sdhci_pci_slot {struct sdhci_host* host; struct sdhci_pci_chip* chip; scalar_t__ private; } ;
struct sdhci_pci_chip {TYPE_3__* pdev; int /*<<< orphan*/  quirks; } ;
struct TYPE_13__ {int (* execute_tuning ) (struct mmc_host*,int) ;} ;
struct sdhci_host {void* private; int flags; int tuning_done; scalar_t__ timing; TYPE_2__ mmc_host_ops; TYPE_10__* mmc; int /*<<< orphan*/  quirks; int /*<<< orphan*/  irq; scalar_t__ ioaddr; } ;
struct TYPE_12__ {int bus_width; } ;
struct mmc_host {TYPE_1__ ios; } ;
struct TYPE_14__ {int device; int revision; } ;
struct TYPE_11__ {int /*<<< orphan*/  caps2; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int MMC_BUS_WIDTH_4 ; 
 int MMC_BUS_WIDTH_8 ; 
 int /*<<< orphan*/  MMC_CAP2_NO_SD ; 
 int /*<<< orphan*/  MMC_CAP2_NO_SDIO ; 
 int MMC_SEND_TUNING_BLOCK_HS200 ; 
 scalar_t__ MMC_TIMING_MMC_HS200 ; 
 int /*<<< orphan*/  O2_SD_ADMA1 ; 
 int /*<<< orphan*/  O2_SD_ADMA2 ; 
 int /*<<< orphan*/  O2_SD_CAPS ; 
 int /*<<< orphan*/  O2_SD_CAP_REG0 ; 
 int /*<<< orphan*/  O2_SD_CAP_REG2 ; 
 int /*<<< orphan*/  O2_SD_CLKREQ ; 
 int /*<<< orphan*/  O2_SD_CLK_SETTING ; 
 int /*<<< orphan*/  O2_SD_DELAY_CTRL ; 
 int /*<<< orphan*/  O2_SD_DEV_CTRL ; 
 int O2_SD_FREG0_LEDOFF ; 
 int O2_SD_FREG4_ENABLE_CLK_SET ; 
 int /*<<< orphan*/  O2_SD_FUNC_REG0 ; 
 int /*<<< orphan*/  O2_SD_FUNC_REG3 ; 
 int /*<<< orphan*/  O2_SD_FUNC_REG4 ; 
 int O2_SD_HW_TUNING_DISABLE ; 
 int /*<<< orphan*/  O2_SD_INF_MOD ; 
 int /*<<< orphan*/  O2_SD_LD0_CTRL ; 
 int O2_SD_LED_ENABLE ; 
 int /*<<< orphan*/  O2_SD_LOCK_WP ; 
 int /*<<< orphan*/  O2_SD_MISC_CTRL4 ; 
 int /*<<< orphan*/  O2_SD_MISC_REG5 ; 
 int /*<<< orphan*/  O2_SD_MISC_SETTING ; 
 int /*<<< orphan*/  O2_SD_MULTI_VCC3V ; 
 int /*<<< orphan*/  O2_SD_PLL_SETTING ; 
 int /*<<< orphan*/  O2_SD_TEST_REG ; 
 int /*<<< orphan*/  O2_SD_TUNING_CTRL ; 
 int /*<<< orphan*/  O2_SD_UHS2_L1_CTRL ; 
 int O2_SD_VENDOR_SETTING ; 
 int O2_SD_VENDOR_SETTING2 ; 
 int /*<<< orphan*/  PCI_CAP_ID_MSI ; 
#define  PCI_DEVICE_ID_O2_8220 136 
#define  PCI_DEVICE_ID_O2_8221 135 
#define  PCI_DEVICE_ID_O2_8320 134 
#define  PCI_DEVICE_ID_O2_8321 133 
#define  PCI_DEVICE_ID_O2_FUJIN2 132 
#define  PCI_DEVICE_ID_O2_SDS0 131 
#define  PCI_DEVICE_ID_O2_SDS1 130 
#define  PCI_DEVICE_ID_O2_SEABIRD0 129 
#define  PCI_DEVICE_ID_O2_SEABIRD1 128 
 int PCI_IRQ_MSI ; 
 int PCI_IRQ_MSIX ; 
 int SDHCI_CTRL_EXEC_TUNING ; 
 int SDHCI_CTRL_TUNED_CLK ; 
 int SDHCI_HOST_CONTROL2 ; 
 int SDHCI_HS400_TUNING ; 
 int /*<<< orphan*/  SDHCI_QUIRK_DELAY_AFTER_POWER ; 
 int /*<<< orphan*/  SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12 ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 int SDHCI_SIGNALING_180 ; 
 int SDHCI_SIGNALING_330 ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  mmc_hostname (TYPE_10__*) ; 
 struct sdhci_host* mmc_priv (struct mmc_host*) ; 
 int pci_alloc_irq_vectors (TYPE_3__*,int,int,int) ; 
 int pci_find_capability (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_irq_vector (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int pci_read_config_byte (TYPE_3__*,int /*<<< orphan*/ ,int*) ; 
 int pci_read_config_dword (TYPE_3__*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_write_config_byte (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pci_write_config_dword (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*,int /*<<< orphan*/ ) ; 
 int readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int /*<<< orphan*/  sdhci_end_tuning (struct sdhci_host*) ; 
 int sdhci_execute_tuning (struct mmc_host*,int) ; 
 int /*<<< orphan*/  sdhci_reset_tuning (struct sdhci_host*) ; 
 int /*<<< orphan*/  sdhci_send_tuning (struct sdhci_host*,int) ; 
 int /*<<< orphan*/  sdhci_set_bus_width (struct sdhci_host*,int) ; 
 int /*<<< orphan*/  sdhci_start_tuning (struct sdhci_host*) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

__attribute__((used)) static inline void sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
	writel(val, host->ioaddr + reg);
}

__attribute__((used)) static inline void sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
	writew(val, host->ioaddr + reg);
}

__attribute__((used)) static inline void sdhci_writeb(struct sdhci_host *host, u8 val, int reg)
{
	writeb(val, host->ioaddr + reg);
}

__attribute__((used)) static inline u32 sdhci_readl(struct sdhci_host *host, int reg)
{
	return readl(host->ioaddr + reg);
}

__attribute__((used)) static inline u16 sdhci_readw(struct sdhci_host *host, int reg)
{
	return readw(host->ioaddr + reg);
}

__attribute__((used)) static inline u8 sdhci_readb(struct sdhci_host *host, int reg)
{
	return readb(host->ioaddr + reg);
}

__attribute__((used)) static inline void *sdhci_priv(struct sdhci_host *host)
{
	return host->private;
}

__attribute__((used)) static inline void sdhci_read_caps(struct sdhci_host *host)
{
	__sdhci_read_caps(host, NULL, NULL, NULL);
}

__attribute__((used)) static inline bool sdhci_sdio_irq_enabled(struct sdhci_host *host)
{
	return !!(host->flags & SDHCI_SDIO_IRQ_ENABLED);
}

__attribute__((used)) static inline void *sdhci_pci_priv(struct sdhci_pci_slot *slot)
{
	return (void *)slot->private;
}

__attribute__((used)) static void sdhci_o2_set_tuning_mode(struct sdhci_host *host)
{
	u16 reg;

	/* enable hardware tuning */
	reg = sdhci_readw(host, O2_SD_VENDOR_SETTING);
	reg &= ~O2_SD_HW_TUNING_DISABLE;
	sdhci_writew(host, reg, O2_SD_VENDOR_SETTING);
}

__attribute__((used)) static void __sdhci_o2_execute_tuning(struct sdhci_host *host, u32 opcode)
{
	int i;

	sdhci_send_tuning(host, MMC_SEND_TUNING_BLOCK_HS200);

	for (i = 0; i < 150; i++) {
		u16 ctrl = sdhci_readw(host, SDHCI_HOST_CONTROL2);

		if (!(ctrl & SDHCI_CTRL_EXEC_TUNING)) {
			if (ctrl & SDHCI_CTRL_TUNED_CLK) {
				host->tuning_done = true;
				return;
			}
			pr_warn("%s: HW tuning failed !\n",
				mmc_hostname(host->mmc));
			break;
		}

		mdelay(1);
	}

	pr_info("%s: Tuning failed, falling back to fixed sampling clock\n",
		mmc_hostname(host->mmc));
	sdhci_reset_tuning(host);
}

__attribute__((used)) static int sdhci_o2_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
	struct sdhci_host *host = mmc_priv(mmc);
	int current_bus_width = 0;

	/*
	 * This handler only implements the eMMC tuning that is specific to
	 * this controller.  Fall back to the standard method for other TIMING.
	 */
	if (host->timing != MMC_TIMING_MMC_HS200)
		return sdhci_execute_tuning(mmc, opcode);

	if (WARN_ON(opcode != MMC_SEND_TUNING_BLOCK_HS200))
		return -EINVAL;

	/*
	 * o2 sdhci host didn't support 8bit emmc tuning
	 */
	if (mmc->ios.bus_width == MMC_BUS_WIDTH_8) {
		current_bus_width = mmc->ios.bus_width;
		sdhci_set_bus_width(host, MMC_BUS_WIDTH_4);
	}

	sdhci_o2_set_tuning_mode(host);

	sdhci_start_tuning(host);

	__sdhci_o2_execute_tuning(host, opcode);

	sdhci_end_tuning(host);

	if (current_bus_width == MMC_BUS_WIDTH_8)
		sdhci_set_bus_width(host, current_bus_width);

	host->flags &= ~SDHCI_HS400_TUNING;
	return 0;
}

__attribute__((used)) static void o2_pci_set_baseclk(struct sdhci_pci_chip *chip, u32 value)
{
	u32 scratch_32;
	pci_read_config_dword(chip->pdev,
			      O2_SD_PLL_SETTING, &scratch_32);

	scratch_32 &= 0x0000FFFF;
	scratch_32 |= value;

	pci_write_config_dword(chip->pdev,
			       O2_SD_PLL_SETTING, scratch_32);
}

__attribute__((used)) static void o2_pci_led_enable(struct sdhci_pci_chip *chip)
{
	int ret;
	u32 scratch_32;

	/* Set led of SD host function enable */
	ret = pci_read_config_dword(chip->pdev,
				    O2_SD_FUNC_REG0, &scratch_32);
	if (ret)
		return;

	scratch_32 &= ~O2_SD_FREG0_LEDOFF;
	pci_write_config_dword(chip->pdev,
			       O2_SD_FUNC_REG0, scratch_32);

	ret = pci_read_config_dword(chip->pdev,
				    O2_SD_TEST_REG, &scratch_32);
	if (ret)
		return;

	scratch_32 |= O2_SD_LED_ENABLE;
	pci_write_config_dword(chip->pdev,
			       O2_SD_TEST_REG, scratch_32);

}

__attribute__((used)) static void sdhci_pci_o2_fujin2_pci_init(struct sdhci_pci_chip *chip)
{
	u32 scratch_32;
	int ret;
	/* Improve write performance for SD3.0 */
	ret = pci_read_config_dword(chip->pdev, O2_SD_DEV_CTRL, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~((1 << 12) | (1 << 13) | (1 << 14));
	pci_write_config_dword(chip->pdev, O2_SD_DEV_CTRL, scratch_32);

	/* Enable Link abnormal reset generating Reset */
	ret = pci_read_config_dword(chip->pdev, O2_SD_MISC_REG5, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~((1 << 19) | (1 << 11));
	scratch_32 |= (1 << 10);
	pci_write_config_dword(chip->pdev, O2_SD_MISC_REG5, scratch_32);

	/* set card power over current protection */
	ret = pci_read_config_dword(chip->pdev, O2_SD_TEST_REG, &scratch_32);
	if (ret)
		return;
	scratch_32 |= (1 << 4);
	pci_write_config_dword(chip->pdev, O2_SD_TEST_REG, scratch_32);

	/* adjust the output delay for SD mode */
	pci_write_config_dword(chip->pdev, O2_SD_DELAY_CTRL, 0x00002492);

	/* Set the output voltage setting of Aux 1.2v LDO */
	ret = pci_read_config_dword(chip->pdev, O2_SD_LD0_CTRL, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~(3 << 12);
	pci_write_config_dword(chip->pdev, O2_SD_LD0_CTRL, scratch_32);

	/* Set Max power supply capability of SD host */
	ret = pci_read_config_dword(chip->pdev, O2_SD_CAP_REG0, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~(0x01FE);
	scratch_32 |= 0x00CC;
	pci_write_config_dword(chip->pdev, O2_SD_CAP_REG0, scratch_32);
	/* Set DLL Tuning Window */
	ret = pci_read_config_dword(chip->pdev,
				    O2_SD_TUNING_CTRL, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~(0x000000FF);
	scratch_32 |= 0x00000066;
	pci_write_config_dword(chip->pdev, O2_SD_TUNING_CTRL, scratch_32);

	/* Set UHS2 T_EIDLE */
	ret = pci_read_config_dword(chip->pdev,
				    O2_SD_UHS2_L1_CTRL, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~(0x000000FC);
	scratch_32 |= 0x00000084;
	pci_write_config_dword(chip->pdev, O2_SD_UHS2_L1_CTRL, scratch_32);

	/* Set UHS2 Termination */
	ret = pci_read_config_dword(chip->pdev, O2_SD_FUNC_REG3, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~((1 << 21) | (1 << 30));

	pci_write_config_dword(chip->pdev, O2_SD_FUNC_REG3, scratch_32);

	/* Set L1 Entrance Timer */
	ret = pci_read_config_dword(chip->pdev, O2_SD_CAPS, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~(0xf0000000);
	scratch_32 |= 0x30000000;
	pci_write_config_dword(chip->pdev, O2_SD_CAPS, scratch_32);

	ret = pci_read_config_dword(chip->pdev,
				    O2_SD_MISC_CTRL4, &scratch_32);
	if (ret)
		return;
	scratch_32 &= ~(0x000f0000);
	scratch_32 |= 0x00080000;
	pci_write_config_dword(chip->pdev, O2_SD_MISC_CTRL4, scratch_32);
}

__attribute__((used)) static void sdhci_pci_o2_enable_msi(struct sdhci_pci_chip *chip,
				    struct sdhci_host *host)
{
	int ret;

	ret = pci_find_capability(chip->pdev, PCI_CAP_ID_MSI);
	if (!ret) {
		pr_info("%s: unsupport msi, use INTx irq\n",
			mmc_hostname(host->mmc));
		return;
	}

	ret = pci_alloc_irq_vectors(chip->pdev, 1, 1,
				    PCI_IRQ_MSI | PCI_IRQ_MSIX);
	if (ret < 0) {
		pr_err("%s: enable PCI MSI failed, err=%d\n",
		       mmc_hostname(host->mmc), ret);
		return;
	}

	host->irq = pci_irq_vector(chip->pdev, 0);
}

int sdhci_pci_o2_probe_slot(struct sdhci_pci_slot *slot)
{
	struct sdhci_pci_chip *chip;
	struct sdhci_host *host;
	u32 reg;
	int ret;

	chip = slot->chip;
	host = slot->host;
	switch (chip->pdev->device) {
	case PCI_DEVICE_ID_O2_SDS0:
	case PCI_DEVICE_ID_O2_SEABIRD0:
	case PCI_DEVICE_ID_O2_SEABIRD1:
	case PCI_DEVICE_ID_O2_SDS1:
	case PCI_DEVICE_ID_O2_FUJIN2:
		reg = sdhci_readl(host, O2_SD_VENDOR_SETTING);
		if (reg & 0x1)
			host->quirks |= SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12;

		sdhci_pci_o2_enable_msi(chip, host);

		if (chip->pdev->device == PCI_DEVICE_ID_O2_SEABIRD0) {
			ret = pci_read_config_dword(chip->pdev,
						    O2_SD_MISC_SETTING, &reg);
			if (ret)
				return -EIO;
			if (reg & (1 << 4)) {
				pr_info("%s: emmc 1.8v flag is set, force 1.8v signaling voltage\n",
					mmc_hostname(host->mmc));
				host->flags &= ~SDHCI_SIGNALING_330;
				host->flags |= SDHCI_SIGNALING_180;
				host->mmc->caps2 |= MMC_CAP2_NO_SD;
				host->mmc->caps2 |= MMC_CAP2_NO_SDIO;
			}
		}

		host->mmc_host_ops.execute_tuning = sdhci_o2_execute_tuning;

		if (chip->pdev->device != PCI_DEVICE_ID_O2_FUJIN2)
			break;
		/* set dll watch dog timer */
		reg = sdhci_readl(host, O2_SD_VENDOR_SETTING2);
		reg |= (1 << 12);
		sdhci_writel(host, reg, O2_SD_VENDOR_SETTING2);

		break;
	default:
		break;
	}

	return 0;
}

int sdhci_pci_o2_probe(struct sdhci_pci_chip *chip)
{
	int ret;
	u8 scratch;
	u32 scratch_32;

	switch (chip->pdev->device) {
	case PCI_DEVICE_ID_O2_8220:
	case PCI_DEVICE_ID_O2_8221:
	case PCI_DEVICE_ID_O2_8320:
	case PCI_DEVICE_ID_O2_8321:
		/* This extra setup is required due to broken ADMA. */
		ret = pci_read_config_byte(chip->pdev,
				O2_SD_LOCK_WP, &scratch);
		if (ret)
			return ret;
		scratch &= 0x7f;
		pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);

		/* Set Multi 3 to VCC3V# */
		pci_write_config_byte(chip->pdev, O2_SD_MULTI_VCC3V, 0x08);

		/* Disable CLK_REQ# support after media DET */
		ret = pci_read_config_byte(chip->pdev,
				O2_SD_CLKREQ, &scratch);
		if (ret)
			return ret;
		scratch |= 0x20;
		pci_write_config_byte(chip->pdev, O2_SD_CLKREQ, scratch);

		/* Choose capabilities, enable SDMA.  We have to write 0x01
		 * to the capabilities register first to unlock it.
		 */
		ret = pci_read_config_byte(chip->pdev, O2_SD_CAPS, &scratch);
		if (ret)
			return ret;
		scratch |= 0x01;
		pci_write_config_byte(chip->pdev, O2_SD_CAPS, scratch);
		pci_write_config_byte(chip->pdev, O2_SD_CAPS, 0x73);

		/* Disable ADMA1/2 */
		pci_write_config_byte(chip->pdev, O2_SD_ADMA1, 0x39);
		pci_write_config_byte(chip->pdev, O2_SD_ADMA2, 0x08);

		/* Disable the infinite transfer mode */
		ret = pci_read_config_byte(chip->pdev,
				O2_SD_INF_MOD, &scratch);
		if (ret)
			return ret;
		scratch |= 0x08;
		pci_write_config_byte(chip->pdev, O2_SD_INF_MOD, scratch);

		/* Lock WP */
		ret = pci_read_config_byte(chip->pdev,
				O2_SD_LOCK_WP, &scratch);
		if (ret)
			return ret;
		scratch |= 0x80;
		pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
		break;
	case PCI_DEVICE_ID_O2_SDS0:
	case PCI_DEVICE_ID_O2_SDS1:
	case PCI_DEVICE_ID_O2_FUJIN2:
		/* UnLock WP */
		ret = pci_read_config_byte(chip->pdev,
				O2_SD_LOCK_WP, &scratch);
		if (ret)
			return ret;

		scratch &= 0x7f;
		pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);

		/* DevId=8520 subId= 0x11 or 0x12  Type Chip support */
		if (chip->pdev->device == PCI_DEVICE_ID_O2_FUJIN2) {
			ret = pci_read_config_dword(chip->pdev,
						    O2_SD_FUNC_REG0,
						    &scratch_32);
			scratch_32 = ((scratch_32 & 0xFF000000) >> 24);

			/* Check Whether subId is 0x11 or 0x12 */
			if ((scratch_32 == 0x11) || (scratch_32 == 0x12)) {
				scratch_32 = 0x25100000;

				o2_pci_set_baseclk(chip, scratch_32);
				ret = pci_read_config_dword(chip->pdev,
							    O2_SD_FUNC_REG4,
							    &scratch_32);

				/* Enable Base Clk setting change */
				scratch_32 |= O2_SD_FREG4_ENABLE_CLK_SET;
				pci_write_config_dword(chip->pdev,
						       O2_SD_FUNC_REG4,
						       scratch_32);

				/* Set Tuning Window to 4 */
				pci_write_config_byte(chip->pdev,
						      O2_SD_TUNING_CTRL, 0x44);

				break;
			}
		}

		/* Enable 8520 led function */
		o2_pci_led_enable(chip);

		/* Set timeout CLK */
		ret = pci_read_config_dword(chip->pdev,
					    O2_SD_CLK_SETTING, &scratch_32);
		if (ret)
			return ret;

		scratch_32 &= ~(0xFF00);
		scratch_32 |= 0x07E0C800;
		pci_write_config_dword(chip->pdev,
				       O2_SD_CLK_SETTING, scratch_32);

		ret = pci_read_config_dword(chip->pdev,
					    O2_SD_CLKREQ, &scratch_32);
		if (ret)
			return ret;
		scratch_32 |= 0x3;
		pci_write_config_dword(chip->pdev, O2_SD_CLKREQ, scratch_32);

		ret = pci_read_config_dword(chip->pdev,
					    O2_SD_PLL_SETTING, &scratch_32);
		if (ret)
			return ret;

		scratch_32 &= ~(0x1F3F070E);
		scratch_32 |= 0x18270106;
		pci_write_config_dword(chip->pdev,
				       O2_SD_PLL_SETTING, scratch_32);

		/* Disable UHS1 funciton */
		ret = pci_read_config_dword(chip->pdev,
					    O2_SD_CAP_REG2, &scratch_32);
		if (ret)
			return ret;
		scratch_32 &= ~(0xE0);
		pci_write_config_dword(chip->pdev,
				       O2_SD_CAP_REG2, scratch_32);

		if (chip->pdev->device == PCI_DEVICE_ID_O2_FUJIN2)
			sdhci_pci_o2_fujin2_pci_init(chip);

		/* Lock WP */
		ret = pci_read_config_byte(chip->pdev,
					   O2_SD_LOCK_WP, &scratch);
		if (ret)
			return ret;
		scratch |= 0x80;
		pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
		break;
	case PCI_DEVICE_ID_O2_SEABIRD0:
		if (chip->pdev->revision == 0x01)
			chip->quirks |= SDHCI_QUIRK_DELAY_AFTER_POWER;
		/* fall through */
	case PCI_DEVICE_ID_O2_SEABIRD1:
		/* UnLock WP */
		ret = pci_read_config_byte(chip->pdev,
				O2_SD_LOCK_WP, &scratch);
		if (ret)
			return ret;

		scratch &= 0x7f;
		pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);

		ret = pci_read_config_dword(chip->pdev,
					    O2_SD_PLL_SETTING, &scratch_32);

		if ((scratch_32 & 0xff000000) == 0x01000000) {
			scratch_32 &= 0x0000FFFF;
			scratch_32 |= 0x1F340000;

			pci_write_config_dword(chip->pdev,
					       O2_SD_PLL_SETTING, scratch_32);
		} else {
			scratch_32 &= 0x0000FFFF;
			scratch_32 |= 0x25100000;

			pci_write_config_dword(chip->pdev,
					       O2_SD_PLL_SETTING, scratch_32);

			ret = pci_read_config_dword(chip->pdev,
						    O2_SD_FUNC_REG4,
						    &scratch_32);
			scratch_32 |= (1 << 22);
			pci_write_config_dword(chip->pdev,
					       O2_SD_FUNC_REG4, scratch_32);
		}

		/* Set Tuning Windows to 5 */
		pci_write_config_byte(chip->pdev,
				O2_SD_TUNING_CTRL, 0x55);
		/* Lock WP */
		ret = pci_read_config_byte(chip->pdev,
					   O2_SD_LOCK_WP, &scratch);
		if (ret)
			return ret;
		scratch |= 0x80;
		pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
		break;
	}

	return 0;
}


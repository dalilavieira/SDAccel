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
typedef  int u8 ;
typedef  int u32 ;
typedef  unsigned int u16 ;
struct soc_device_attribute {int dummy; } ;
struct sdhci_pltfm_host {void* private; struct sdhci_host* clk; } ;
struct sdhci_omap_host {int pbias_enabled; int flags; int timing; scalar_t__ bus_mode; int power_mode; char* version; struct sdhci_host* pbias; struct device* dev; scalar_t__ base; struct sdhci_host* host; struct sdhci_host** pinctrl_state; struct sdhci_host* pinctrl; } ;
struct sdhci_omap_data {int offset; int flags; } ;
struct TYPE_4__ {int (* start_signal_voltage_switch ) (struct mmc_host*,struct mmc_ios*) ;void (* set_ios ) (struct mmc_host*,struct mmc_ios*) ;int (* card_busy ) (struct mmc_host*) ;int (* execute_tuning ) (struct mmc_host*,int) ;void (* enable_sdio_irq ) (struct mmc_host*,int) ;int /*<<< orphan*/  get_ro; } ;
struct sdhci_host {void* private; int flags; int ier; TYPE_2__ mmc_host_ops; struct mmc_host* mmc; scalar_t__ ioaddr; int /*<<< orphan*/  irq; } ;
struct regulator {void* private; int flags; int ier; TYPE_2__ mmc_host_ops; struct mmc_host* mmc; scalar_t__ ioaddr; int /*<<< orphan*/  irq; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct pinctrl_state {void* private; int flags; int ier; TYPE_2__ mmc_host_ops; struct mmc_host* mmc; scalar_t__ ioaddr; int /*<<< orphan*/  irq; } ;
struct of_device_id {scalar_t__ data; } ;
struct mmc_ios {int clock; size_t timing; unsigned char signal_voltage; unsigned int bus_mode; int power_mode; } ;
struct TYPE_3__ {int /*<<< orphan*/  vmmc; struct sdhci_host* vqmmc; } ;
struct mmc_host {int caps; int caps2; int f_max; TYPE_1__ supply; struct mmc_ios ios; } ;
typedef  int /*<<< orphan*/  ktime_t ;

/* Variables and functions */
 int AC12_SCLK_SEL ; 
 int AC12_V1V8_SIGEN ; 
 int CAPA2_TSDR50 ; 
 int CAPA_VS18 ; 
 int CAPA_VS30 ; 
 int CAPA_VS33 ; 
 int CON_CLKEXTFREE ; 
 int CON_CTPL ; 
 int CON_DDR ; 
 int CON_DMA_MASTER ; 
 int CON_DW8 ; 
 int CON_INIT ; 
 int CON_OD ; 
 int CON_PADEN ; 
 unsigned int DIV_ROUND_UP (unsigned int,unsigned int) ; 
 int DLL_CALIB ; 
 int DLL_FORCE_SR_C_MASK ; 
 int DLL_FORCE_SR_C_SHIFT ; 
 int DLL_FORCE_VALUE ; 
 int DLL_SWT ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 struct sdhci_host* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HCTL_SDBP ; 
 int HCTL_SDVS_18 ; 
 int HCTL_SDVS_33 ; 
 int HCTL_SDVS_MASK ; 
 int INT_CC_EN ; 
 unsigned int IOV_1V8 ; 
 unsigned int IOV_3V3 ; 
 scalar_t__ IS_ERR (struct sdhci_host*) ; 
 int MAX_PHASE_DELAY ; 
 unsigned int MMC_BUSMODE_OPENDRAIN ; 
 int MMC_BUS_WIDTH_8 ; 
 int MMC_CAP2_HS200_1_8V_SDR ; 
 int MMC_CAP_1_8V_DDR ; 
 int MMC_CAP_3_3V_DDR ; 
 int MMC_CAP_MMC_HIGHSPEED ; 
 int MMC_CAP_SD_HIGHSPEED ; 
 int MMC_CAP_UHS_DDR50 ; 
 int MMC_CAP_UHS_SDR104 ; 
 int MMC_CAP_UHS_SDR12 ; 
 int MMC_CAP_UHS_SDR25 ; 
 int MMC_CAP_UHS_SDR50 ; 
 scalar_t__ MMC_POWER_OFF ; 
 int MMC_POWER_ON ; 
 int MMC_POWER_UNDEFINED ; 
 unsigned char MMC_SIGNAL_VOLTAGE_180 ; 
 unsigned char MMC_SIGNAL_VOLTAGE_330 ; 
 size_t MMC_TIMING_LEGACY ; 
 unsigned int MMC_TIMING_MMC_DDR52 ; 
 size_t MMC_TIMING_MMC_HS ; 
 int MMC_TIMING_MMC_HS200 ; 
 size_t MMC_TIMING_SD_HS ; 
 unsigned int MMC_TIMING_UHS_DDR50 ; 
 size_t MMC_TIMING_UHS_SDR104 ; 
 size_t MMC_TIMING_UHS_SDR12 ; 
 size_t MMC_TIMING_UHS_SDR25 ; 
 size_t MMC_TIMING_UHS_SDR50 ; 
 int PSTATE_DATI ; 
 int PSTATE_DLEV_DAT0 ; 
 int PTR_ERR (struct sdhci_host*) ; 
 int SDHCI_INT_CARD_INT ; 
 int SDHCI_INT_DATA_CRC ; 
 int SDHCI_INT_ENABLE ; 
 unsigned int SDHCI_OMAP_AC12 ; 
 unsigned int SDHCI_OMAP_CAPA ; 
 unsigned int SDHCI_OMAP_CAPA2 ; 
 unsigned int SDHCI_OMAP_CMD ; 
 unsigned int SDHCI_OMAP_CON ; 
 unsigned int SDHCI_OMAP_DLL ; 
 unsigned int SDHCI_OMAP_HCTL ; 
 unsigned int SDHCI_OMAP_PSTATE ; 
 int SDHCI_OMAP_REQUIRE_IODELAY ; 
 unsigned int SDHCI_OMAP_STAT ; 
 unsigned int SDHCI_OMAP_SYSCTL ; 
 int /*<<< orphan*/  SDHCI_OMAP_TIMEOUT ; 
 int SDHCI_RESET_CMD ; 
 int SDHCI_RESET_DATA ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 int SDHCI_SIGNAL_ENABLE ; 
 int SYSCTL_CEN ; 
 unsigned long SYSCTL_CLKD_MASK ; 
 unsigned int SYSCTL_CLKD_MAX ; 
 unsigned long SYSCTL_CLKD_SHIFT ; 
 scalar_t__ WARN_ON (int) ; 
 int __sdhci_add_host (struct sdhci_host*) ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned int clk_get_rate (struct sdhci_host*) ; 
 int clk_set_rate (struct sdhci_host*,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct sdhci_host* devm_clk_get (struct device*,char*) ; 
 struct sdhci_host** devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct sdhci_host* devm_pinctrl_get (struct device*) ; 
 struct sdhci_host* devm_regulator_get_optional (struct device*,char*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_add_ms (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ktime_after (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get () ; 
 struct device* mmc_dev (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_gpio_get_ro ; 
 int mmc_of_parse (struct mmc_host*) ; 
 struct sdhci_host* mmc_priv (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_regulator_set_ocr (struct mmc_host*,int /*<<< orphan*/ ,unsigned short) ; 
 int /*<<< orphan*/  mmc_send_tuning (struct mmc_host*,int,int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  omap_sdhci_match ; 
 struct sdhci_host* pinctrl_lookup_state (struct sdhci_host*,char*) ; 
 int pinctrl_select_state (struct sdhci_host*,struct sdhci_host*) ; 
 struct sdhci_host* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 unsigned int readw (scalar_t__) ; 
 int regulator_disable (struct sdhci_host*) ; 
 int regulator_enable (struct sdhci_host*) ; 
 struct sdhci_host* regulator_get (struct device*,char*) ; 
 scalar_t__ regulator_is_supported_voltage (struct sdhci_host*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regulator_put (struct sdhci_host*) ; 
 int regulator_set_voltage (struct sdhci_host*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  sdhci_cleanup_host (struct sdhci_host*) ; 
 int /*<<< orphan*/  sdhci_enable_clk (struct sdhci_host*,unsigned long) ; 
 int /*<<< orphan*/  sdhci_enable_sdio_irq (struct mmc_host*,int) ; 
 int /*<<< orphan*/  sdhci_get_of_property (struct platform_device*) ; 
 int /*<<< orphan*/  sdhci_omap_pdata ; 
 int /*<<< orphan*/  sdhci_omap_soc_devices ; 
static  void sdhci_omap_start_clock (struct sdhci_omap_host*) ; 
static  void sdhci_omap_stop_clock (struct sdhci_omap_host*) ; 
 int /*<<< orphan*/  sdhci_pltfm_free (struct platform_device*) ; 
 struct sdhci_host* sdhci_pltfm_init (struct platform_device*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sdhci_remove_host (struct sdhci_host*,int) ; 
 int /*<<< orphan*/  sdhci_reset (struct sdhci_host*,int) ; 
 int /*<<< orphan*/  sdhci_set_bus_width (struct sdhci_host*,int) ; 
 int /*<<< orphan*/  sdhci_set_ios (struct mmc_host*,struct mmc_ios*) ; 
 int /*<<< orphan*/  sdhci_set_uhs_signaling (struct sdhci_host*,unsigned int) ; 
 int sdhci_setup_host (struct sdhci_host*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,char*) ; 
 struct soc_device_attribute* soc_device_match (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (unsigned int,scalar_t__) ; 

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

__attribute__((used)) static inline void *sdhci_pltfm_priv(struct sdhci_pltfm_host *host)
{
	return host->private;
}

__attribute__((used)) static inline u32 sdhci_omap_readl(struct sdhci_omap_host *host,
				   unsigned int offset)
{
	return readl(host->base + offset);
}

__attribute__((used)) static inline void sdhci_omap_writel(struct sdhci_omap_host *host,
				     unsigned int offset, u32 data)
{
	writel(data, host->base + offset);
}

__attribute__((used)) static int sdhci_omap_set_pbias(struct sdhci_omap_host *omap_host,
				bool power_on, unsigned int iov)
{
	int ret;
	struct device *dev = omap_host->dev;

	if (IS_ERR(omap_host->pbias))
		return 0;

	if (power_on) {
		ret = regulator_set_voltage(omap_host->pbias, iov, iov);
		if (ret) {
			dev_err(dev, "pbias set voltage failed\n");
			return ret;
		}

		if (omap_host->pbias_enabled)
			return 0;

		ret = regulator_enable(omap_host->pbias);
		if (ret) {
			dev_err(dev, "pbias reg enable fail\n");
			return ret;
		}

		omap_host->pbias_enabled = true;
	} else {
		if (!omap_host->pbias_enabled)
			return 0;

		ret = regulator_disable(omap_host->pbias);
		if (ret) {
			dev_err(dev, "pbias reg disable fail\n");
			return ret;
		}
		omap_host->pbias_enabled = false;
	}

	return 0;
}

__attribute__((used)) static int sdhci_omap_enable_iov(struct sdhci_omap_host *omap_host,
				 unsigned int iov)
{
	int ret;
	struct sdhci_host *host = omap_host->host;
	struct mmc_host *mmc = host->mmc;

	ret = sdhci_omap_set_pbias(omap_host, false, 0);
	if (ret)
		return ret;

	if (!IS_ERR(mmc->supply.vqmmc)) {
		ret = regulator_set_voltage(mmc->supply.vqmmc, iov, iov);
		if (ret) {
			dev_err(mmc_dev(mmc), "vqmmc set voltage failed\n");
			return ret;
		}
	}

	ret = sdhci_omap_set_pbias(omap_host, true, iov);
	if (ret)
		return ret;

	return 0;
}

__attribute__((used)) static void sdhci_omap_conf_bus_power(struct sdhci_omap_host *omap_host,
				      unsigned char signal_voltage)
{
	u32 reg;
	ktime_t timeout;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_HCTL);
	reg &= ~HCTL_SDVS_MASK;

	if (signal_voltage == MMC_SIGNAL_VOLTAGE_330)
		reg |= HCTL_SDVS_33;
	else
		reg |= HCTL_SDVS_18;

	sdhci_omap_writel(omap_host, SDHCI_OMAP_HCTL, reg);

	reg |= HCTL_SDBP;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_HCTL, reg);

	/* wait 1ms */
	timeout = ktime_add_ms(ktime_get(), SDHCI_OMAP_TIMEOUT);
	while (1) {
		bool timedout = ktime_after(ktime_get(), timeout);

		if (sdhci_omap_readl(omap_host, SDHCI_OMAP_HCTL) & HCTL_SDBP)
			break;
		if (WARN_ON(timedout))
			return;
		usleep_range(5, 10);
	}
}

__attribute__((used)) static void sdhci_omap_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);
	u32 reg;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	if (enable)
		reg |= (CON_CTPL | CON_CLKEXTFREE);
	else
		reg &= ~(CON_CTPL | CON_CLKEXTFREE);
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	sdhci_enable_sdio_irq(mmc, enable);
}

__attribute__((used)) static inline void sdhci_omap_set_dll(struct sdhci_omap_host *omap_host,
				      int count)
{
	int i;
	u32 reg;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_DLL);
	reg |= DLL_FORCE_VALUE;
	reg &= ~DLL_FORCE_SR_C_MASK;
	reg |= (count << DLL_FORCE_SR_C_SHIFT);
	sdhci_omap_writel(omap_host, SDHCI_OMAP_DLL, reg);

	reg |= DLL_CALIB;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_DLL, reg);
	for (i = 0; i < 1000; i++) {
		reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_DLL);
		if (reg & DLL_CALIB)
			break;
	}
	reg &= ~DLL_CALIB;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_DLL, reg);
}

__attribute__((used)) static void sdhci_omap_disable_tuning(struct sdhci_omap_host *omap_host)
{
	u32 reg;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_AC12);
	reg &= ~AC12_SCLK_SEL;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_AC12, reg);

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_DLL);
	reg &= ~(DLL_FORCE_VALUE | DLL_SWT);
	sdhci_omap_writel(omap_host, SDHCI_OMAP_DLL, reg);
}

__attribute__((used)) static int sdhci_omap_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);
	struct device *dev = omap_host->dev;
	struct mmc_ios *ios = &mmc->ios;
	u32 start_window = 0, max_window = 0;
	bool dcrc_was_enabled = false;
	u8 cur_match, prev_match = 0;
	u32 length = 0, max_len = 0;
	u32 phase_delay = 0;
	int ret = 0;
	u32 reg;

	pltfm_host = sdhci_priv(host);
	omap_host = sdhci_pltfm_priv(pltfm_host);
	dev = omap_host->dev;

	/* clock tuning is not needed for upto 52MHz */
	if (ios->clock <= 52000000)
		return 0;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CAPA2);
	if (ios->timing == MMC_TIMING_UHS_SDR50 && !(reg & CAPA2_TSDR50))
		return 0;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_DLL);
	reg |= DLL_SWT;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_DLL, reg);

	/*
	 * OMAP5/DRA74X/DRA72x Errata i802:
	 * DCRC error interrupts (MMCHS_STAT[21] DCRC=0x1) can occur
	 * during the tuning procedure. So disable it during the
	 * tuning procedure.
	 */
	if (host->ier & SDHCI_INT_DATA_CRC) {
		host->ier &= ~SDHCI_INT_DATA_CRC;
		dcrc_was_enabled = true;
	}

	while (phase_delay <= MAX_PHASE_DELAY) {
		sdhci_omap_set_dll(omap_host, phase_delay);

		cur_match = !mmc_send_tuning(mmc, opcode, NULL);
		if (cur_match) {
			if (prev_match) {
				length++;
			} else {
				start_window = phase_delay;
				length = 1;
			}
		}

		if (length > max_len) {
			max_window = start_window;
			max_len = length;
		}

		prev_match = cur_match;
		phase_delay += 4;
	}

	if (!max_len) {
		dev_err(dev, "Unable to find match\n");
		ret = -EIO;
		goto tuning_error;
	}

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_AC12);
	if (!(reg & AC12_SCLK_SEL)) {
		ret = -EIO;
		goto tuning_error;
	}

	phase_delay = max_window + 4 * (max_len >> 1);
	sdhci_omap_set_dll(omap_host, phase_delay);

	goto ret;

tuning_error:
	dev_err(dev, "Tuning failed\n");
	sdhci_omap_disable_tuning(omap_host);

ret:
	sdhci_reset(host, SDHCI_RESET_CMD | SDHCI_RESET_DATA);
	/* Reenable forbidden interrupt */
	if (dcrc_was_enabled)
		host->ier |= SDHCI_INT_DATA_CRC;
	sdhci_writel(host, host->ier, SDHCI_INT_ENABLE);
	sdhci_writel(host, host->ier, SDHCI_SIGNAL_ENABLE);
	return ret;
}

__attribute__((used)) static int sdhci_omap_card_busy(struct mmc_host *mmc)
{
	u32 reg, ac12;
	int ret = false;
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_omap_host *omap_host;
	u32 ier = host->ier;

	pltfm_host = sdhci_priv(host);
	omap_host = sdhci_pltfm_priv(pltfm_host);

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	ac12 = sdhci_omap_readl(omap_host, SDHCI_OMAP_AC12);
	reg &= ~CON_CLKEXTFREE;
	if (ac12 & AC12_V1V8_SIGEN)
		reg |= CON_CLKEXTFREE;
	reg |= CON_PADEN;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	disable_irq(host->irq);
	ier |= SDHCI_INT_CARD_INT;
	sdhci_writel(host, ier, SDHCI_INT_ENABLE);
	sdhci_writel(host, ier, SDHCI_SIGNAL_ENABLE);

	/*
	 * Delay is required for PSTATE to correctly reflect
	 * DLEV/CLEV values after PADEN is set.
	 */
	usleep_range(50, 100);
	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_PSTATE);
	if ((reg & PSTATE_DATI) || !(reg & PSTATE_DLEV_DAT0))
		ret = true;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	reg &= ~(CON_CLKEXTFREE | CON_PADEN);
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	sdhci_writel(host, host->ier, SDHCI_INT_ENABLE);
	sdhci_writel(host, host->ier, SDHCI_SIGNAL_ENABLE);
	enable_irq(host->irq);

	return ret;
}

__attribute__((used)) static int sdhci_omap_start_signal_voltage_switch(struct mmc_host *mmc,
						  struct mmc_ios *ios)
{
	u32 reg;
	int ret;
	unsigned int iov;
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_omap_host *omap_host;
	struct device *dev;

	pltfm_host = sdhci_priv(host);
	omap_host = sdhci_pltfm_priv(pltfm_host);
	dev = omap_host->dev;

	if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_330) {
		reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CAPA);
		if (!(reg & CAPA_VS33))
			return -EOPNOTSUPP;

		sdhci_omap_conf_bus_power(omap_host, ios->signal_voltage);

		reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_AC12);
		reg &= ~AC12_V1V8_SIGEN;
		sdhci_omap_writel(omap_host, SDHCI_OMAP_AC12, reg);

		iov = IOV_3V3;
	} else if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_180) {
		reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CAPA);
		if (!(reg & CAPA_VS18))
			return -EOPNOTSUPP;

		sdhci_omap_conf_bus_power(omap_host, ios->signal_voltage);

		reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_AC12);
		reg |= AC12_V1V8_SIGEN;
		sdhci_omap_writel(omap_host, SDHCI_OMAP_AC12, reg);

		iov = IOV_1V8;
	} else {
		return -EOPNOTSUPP;
	}

	ret = sdhci_omap_enable_iov(omap_host, iov);
	if (ret) {
		dev_err(dev, "failed to switch IO voltage to %dmV\n", iov);
		return ret;
	}

	dev_dbg(dev, "IO voltage switched to %dmV\n", iov);
	return 0;
}

__attribute__((used)) static void sdhci_omap_set_timing(struct sdhci_omap_host *omap_host, u8 timing)
{
	int ret;
	struct pinctrl_state *pinctrl_state;
	struct device *dev = omap_host->dev;

	if (!(omap_host->flags & SDHCI_OMAP_REQUIRE_IODELAY))
		return;

	if (omap_host->timing == timing)
		return;

	sdhci_omap_stop_clock(omap_host);

	pinctrl_state = omap_host->pinctrl_state[timing];
	ret = pinctrl_select_state(omap_host->pinctrl, pinctrl_state);
	if (ret) {
		dev_err(dev, "failed to select pinctrl state\n");
		return;
	}

	sdhci_omap_start_clock(omap_host);
	omap_host->timing = timing;
}

__attribute__((used)) static void sdhci_omap_set_power_mode(struct sdhci_omap_host *omap_host,
				      u8 power_mode)
{
	if (omap_host->bus_mode == MMC_POWER_OFF)
		sdhci_omap_disable_tuning(omap_host);
	omap_host->power_mode = power_mode;
}

__attribute__((used)) static void sdhci_omap_set_bus_mode(struct sdhci_omap_host *omap_host,
				    unsigned int mode)
{
	u32 reg;

	if (omap_host->bus_mode == mode)
		return;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	if (mode == MMC_BUSMODE_OPENDRAIN)
		reg |= CON_OD;
	else
		reg &= ~CON_OD;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	omap_host->bus_mode = mode;
}

__attribute__((used)) static void sdhci_omap_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_omap_host *omap_host;

	pltfm_host = sdhci_priv(host);
	omap_host = sdhci_pltfm_priv(pltfm_host);

	sdhci_omap_set_bus_mode(omap_host, ios->bus_mode);
	sdhci_omap_set_timing(omap_host, ios->timing);
	sdhci_set_ios(mmc, ios);
	sdhci_omap_set_power_mode(omap_host, ios->power_mode);
}

__attribute__((used)) static u16 sdhci_omap_calc_divisor(struct sdhci_pltfm_host *host,
				   unsigned int clock)
{
	u16 dsor;

	dsor = DIV_ROUND_UP(clk_get_rate(host->clk), clock);
	if (dsor > SYSCTL_CLKD_MAX)
		dsor = SYSCTL_CLKD_MAX;

	return dsor;
}

__attribute__((used)) static void sdhci_omap_start_clock(struct sdhci_omap_host *omap_host)
{
	u32 reg;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_SYSCTL);
	reg |= SYSCTL_CEN;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_SYSCTL, reg);
}

__attribute__((used)) static void sdhci_omap_stop_clock(struct sdhci_omap_host *omap_host)
{
	u32 reg;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_SYSCTL);
	reg &= ~SYSCTL_CEN;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_SYSCTL, reg);
}

__attribute__((used)) static void sdhci_omap_set_clock(struct sdhci_host *host, unsigned int clock)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);
	unsigned long clkdiv;

	sdhci_omap_stop_clock(omap_host);

	if (!clock)
		return;

	clkdiv = sdhci_omap_calc_divisor(pltfm_host, clock);
	clkdiv = (clkdiv & SYSCTL_CLKD_MASK) << SYSCTL_CLKD_SHIFT;
	sdhci_enable_clk(host, clkdiv);

	sdhci_omap_start_clock(omap_host);
}

__attribute__((used)) static void sdhci_omap_set_power(struct sdhci_host *host, unsigned char mode,
			  unsigned short vdd)
{
	struct mmc_host *mmc = host->mmc;

	mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, vdd);
}

__attribute__((used)) static int sdhci_omap_enable_dma(struct sdhci_host *host)
{
	u32 reg;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	reg |= CON_DMA_MASTER;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	return 0;
}

__attribute__((used)) static unsigned int sdhci_omap_get_min_clock(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);

	return clk_get_rate(pltfm_host->clk) / SYSCTL_CLKD_MAX;
}

__attribute__((used)) static void sdhci_omap_set_bus_width(struct sdhci_host *host, int width)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);
	u32 reg;

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	if (width == MMC_BUS_WIDTH_8)
		reg |= CON_DW8;
	else
		reg &= ~CON_DW8;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	sdhci_set_bus_width(host, width);
}

__attribute__((used)) static void sdhci_omap_init_74_clocks(struct sdhci_host *host, u8 power_mode)
{
	u32 reg;
	ktime_t timeout;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);

	if (omap_host->power_mode == power_mode)
		return;

	if (power_mode != MMC_POWER_ON)
		return;

	disable_irq(host->irq);

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	reg |= CON_INIT;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CMD, 0x0);

	/* wait 1ms */
	timeout = ktime_add_ms(ktime_get(), SDHCI_OMAP_TIMEOUT);
	while (1) {
		bool timedout = ktime_after(ktime_get(), timeout);

		if (sdhci_omap_readl(omap_host, SDHCI_OMAP_STAT) & INT_CC_EN)
			break;
		if (WARN_ON(timedout))
			return;
		usleep_range(5, 10);
	}

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	reg &= ~CON_INIT;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);
	sdhci_omap_writel(omap_host, SDHCI_OMAP_STAT, INT_CC_EN);

	enable_irq(host->irq);
}

__attribute__((used)) static void sdhci_omap_set_uhs_signaling(struct sdhci_host *host,
					 unsigned int timing)
{
	u32 reg;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_omap_host *omap_host = sdhci_pltfm_priv(pltfm_host);

	sdhci_omap_stop_clock(omap_host);

	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CON);
	if (timing == MMC_TIMING_UHS_DDR50 || timing == MMC_TIMING_MMC_DDR52)
		reg |= CON_DDR;
	else
		reg &= ~CON_DDR;
	sdhci_omap_writel(omap_host, SDHCI_OMAP_CON, reg);

	sdhci_set_uhs_signaling(host, timing);
	sdhci_omap_start_clock(omap_host);
}

__attribute__((used)) static int sdhci_omap_set_capabilities(struct sdhci_omap_host *omap_host)
{
	u32 reg;
	int ret = 0;
	struct device *dev = omap_host->dev;
	struct regulator *vqmmc;

	vqmmc = regulator_get(dev, "vqmmc");
	if (IS_ERR(vqmmc)) {
		ret = PTR_ERR(vqmmc);
		goto reg_put;
	}

	/* voltage capabilities might be set by boot loader, clear it */
	reg = sdhci_omap_readl(omap_host, SDHCI_OMAP_CAPA);
	reg &= ~(CAPA_VS18 | CAPA_VS30 | CAPA_VS33);

	if (regulator_is_supported_voltage(vqmmc, IOV_3V3, IOV_3V3))
		reg |= CAPA_VS33;
	if (regulator_is_supported_voltage(vqmmc, IOV_1V8, IOV_1V8))
		reg |= CAPA_VS18;

	sdhci_omap_writel(omap_host, SDHCI_OMAP_CAPA, reg);

reg_put:
	regulator_put(vqmmc);

	return ret;
}

__attribute__((used)) static struct pinctrl_state
*sdhci_omap_iodelay_pinctrl_state(struct sdhci_omap_host *omap_host, char *mode,
				  u32 *caps, u32 capmask)
{
	struct device *dev = omap_host->dev;
	char *version = omap_host->version;
	struct pinctrl_state *pinctrl_state = ERR_PTR(-ENODEV);
	char str[20];

	if (!(*caps & capmask))
		goto ret;

	if (version) {
		snprintf(str, 20, "%s-%s", mode, version);
		pinctrl_state = pinctrl_lookup_state(omap_host->pinctrl, str);
	}

	if (IS_ERR(pinctrl_state))
		pinctrl_state = pinctrl_lookup_state(omap_host->pinctrl, mode);

	if (IS_ERR(pinctrl_state)) {
		dev_err(dev, "no pinctrl state for %s mode", mode);
		*caps &= ~capmask;
	}

ret:
	return pinctrl_state;
}

__attribute__((used)) static int sdhci_omap_config_iodelay_pinctrl_state(struct sdhci_omap_host
						   *omap_host)
{
	struct device *dev = omap_host->dev;
	struct sdhci_host *host = omap_host->host;
	struct mmc_host *mmc = host->mmc;
	u32 *caps = &mmc->caps;
	u32 *caps2 = &mmc->caps2;
	struct pinctrl_state *state;
	struct pinctrl_state **pinctrl_state;

	if (!(omap_host->flags & SDHCI_OMAP_REQUIRE_IODELAY))
		return 0;

	pinctrl_state = devm_kcalloc(dev,
				     MMC_TIMING_MMC_HS200 + 1,
				     sizeof(*pinctrl_state),
				     GFP_KERNEL);
	if (!pinctrl_state)
		return -ENOMEM;

	omap_host->pinctrl = devm_pinctrl_get(omap_host->dev);
	if (IS_ERR(omap_host->pinctrl)) {
		dev_err(dev, "Cannot get pinctrl\n");
		return PTR_ERR(omap_host->pinctrl);
	}

	state = pinctrl_lookup_state(omap_host->pinctrl, "default");
	if (IS_ERR(state)) {
		dev_err(dev, "no pinctrl state for default mode\n");
		return PTR_ERR(state);
	}
	pinctrl_state[MMC_TIMING_LEGACY] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "sdr104", caps,
						 MMC_CAP_UHS_SDR104);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_UHS_SDR104] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "ddr50", caps,
						 MMC_CAP_UHS_DDR50);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_UHS_DDR50] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "sdr50", caps,
						 MMC_CAP_UHS_SDR50);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_UHS_SDR50] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "sdr25", caps,
						 MMC_CAP_UHS_SDR25);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_UHS_SDR25] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "sdr12", caps,
						 MMC_CAP_UHS_SDR12);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_UHS_SDR12] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "ddr_1_8v", caps,
						 MMC_CAP_1_8V_DDR);
	if (!IS_ERR(state)) {
		pinctrl_state[MMC_TIMING_MMC_DDR52] = state;
	} else {
		state = sdhci_omap_iodelay_pinctrl_state(omap_host, "ddr_3_3v",
							 caps,
							 MMC_CAP_3_3V_DDR);
		if (!IS_ERR(state))
			pinctrl_state[MMC_TIMING_MMC_DDR52] = state;
	}

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "hs", caps,
						 MMC_CAP_SD_HIGHSPEED);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_SD_HS] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "hs", caps,
						 MMC_CAP_MMC_HIGHSPEED);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_MMC_HS] = state;

	state = sdhci_omap_iodelay_pinctrl_state(omap_host, "hs200_1_8v", caps2,
						 MMC_CAP2_HS200_1_8V_SDR);
	if (!IS_ERR(state))
		pinctrl_state[MMC_TIMING_MMC_HS200] = state;

	omap_host->pinctrl_state = pinctrl_state;

	return 0;
}

__attribute__((used)) static int sdhci_omap_probe(struct platform_device *pdev)
{
	int ret;
	u32 offset;
	struct device *dev = &pdev->dev;
	struct sdhci_host *host;
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_omap_host *omap_host;
	struct mmc_host *mmc;
	const struct of_device_id *match;
	struct sdhci_omap_data *data;
	const struct soc_device_attribute *soc;

	match = of_match_device(omap_sdhci_match, dev);
	if (!match)
		return -EINVAL;

	data = (struct sdhci_omap_data *)match->data;
	if (!data) {
		dev_err(dev, "no sdhci omap data\n");
		return -EINVAL;
	}
	offset = data->offset;

	host = sdhci_pltfm_init(pdev, &sdhci_omap_pdata,
				sizeof(*omap_host));
	if (IS_ERR(host)) {
		dev_err(dev, "Failed sdhci_pltfm_init\n");
		return PTR_ERR(host);
	}

	pltfm_host = sdhci_priv(host);
	omap_host = sdhci_pltfm_priv(pltfm_host);
	omap_host->host = host;
	omap_host->base = host->ioaddr;
	omap_host->dev = dev;
	omap_host->power_mode = MMC_POWER_UNDEFINED;
	omap_host->timing = MMC_TIMING_LEGACY;
	omap_host->flags = data->flags;
	host->ioaddr += offset;

	mmc = host->mmc;
	sdhci_get_of_property(pdev);
	ret = mmc_of_parse(mmc);
	if (ret)
		goto err_pltfm_free;

	soc = soc_device_match(sdhci_omap_soc_devices);
	if (soc) {
		omap_host->version = "rev11";
		if (!strcmp(dev_name(dev), "4809c000.mmc"))
			mmc->f_max = 96000000;
		if (!strcmp(dev_name(dev), "480b4000.mmc"))
			mmc->f_max = 48000000;
		if (!strcmp(dev_name(dev), "480ad000.mmc"))
			mmc->f_max = 48000000;
	}

	pltfm_host->clk = devm_clk_get(dev, "fck");
	if (IS_ERR(pltfm_host->clk)) {
		ret = PTR_ERR(pltfm_host->clk);
		goto err_pltfm_free;
	}

	ret = clk_set_rate(pltfm_host->clk, mmc->f_max);
	if (ret) {
		dev_err(dev, "failed to set clock to %d\n", mmc->f_max);
		goto err_pltfm_free;
	}

	omap_host->pbias = devm_regulator_get_optional(dev, "pbias");
	if (IS_ERR(omap_host->pbias)) {
		ret = PTR_ERR(omap_host->pbias);
		if (ret != -ENODEV)
			goto err_pltfm_free;
		dev_dbg(dev, "unable to get pbias regulator %d\n", ret);
	}
	omap_host->pbias_enabled = false;

	/*
	 * omap_device_pm_domain has callbacks to enable the main
	 * functional clock, interface clock and also configure the
	 * SYSCONFIG register of omap devices. The callback will be invoked
	 * as part of pm_runtime_get_sync.
	 */
	pm_runtime_enable(dev);
	ret = pm_runtime_get_sync(dev);
	if (ret < 0) {
		dev_err(dev, "pm_runtime_get_sync failed\n");
		pm_runtime_put_noidle(dev);
		goto err_rpm_disable;
	}

	ret = sdhci_omap_set_capabilities(omap_host);
	if (ret) {
		dev_err(dev, "failed to set system capabilities\n");
		goto err_put_sync;
	}

	host->mmc_host_ops.get_ro = mmc_gpio_get_ro;
	host->mmc_host_ops.start_signal_voltage_switch =
					sdhci_omap_start_signal_voltage_switch;
	host->mmc_host_ops.set_ios = sdhci_omap_set_ios;
	host->mmc_host_ops.card_busy = sdhci_omap_card_busy;
	host->mmc_host_ops.execute_tuning = sdhci_omap_execute_tuning;
	host->mmc_host_ops.enable_sdio_irq = sdhci_omap_enable_sdio_irq;

	ret = sdhci_setup_host(host);
	if (ret)
		goto err_put_sync;

	ret = sdhci_omap_config_iodelay_pinctrl_state(omap_host);
	if (ret)
		goto err_cleanup_host;

	ret = __sdhci_add_host(host);
	if (ret)
		goto err_cleanup_host;

	return 0;

err_cleanup_host:
	sdhci_cleanup_host(host);

err_put_sync:
	pm_runtime_put_sync(dev);

err_rpm_disable:
	pm_runtime_disable(dev);

err_pltfm_free:
	sdhci_pltfm_free(pdev);
	return ret;
}

__attribute__((used)) static int sdhci_omap_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sdhci_host *host = platform_get_drvdata(pdev);

	sdhci_remove_host(host, true);
	pm_runtime_put_sync(dev);
	pm_runtime_disable(dev);
	sdhci_pltfm_free(pdev);

	return 0;
}


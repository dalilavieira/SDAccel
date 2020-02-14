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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sdhci_pci_slot {scalar_t__ private; } ;
struct sdhci_host {void* private; int flags; scalar_t__ ioaddr; } ;

/* Variables and functions */
 int CLKFBOUT_100_MHZ ; 
 int CLKFBOUT_200_MHZ ; 
 int DIV_REG_100_MHZ ; 
 int DIV_REG_200_MHZ ; 
 int SDHCI_CLOCK_CARD_EN ; 
 int SDHCI_CLOCK_CONTROL ; 
 int SDHCI_CLOCK_INT_EN ; 
 int SDHCI_PROG_CLOCK_MODE ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 int SDHCI_VENDOR_PTR_R ; 
 int SDHC_AT_CTRL_R ; 
 int SDHC_CCLK_MMCM_RST ; 
 int SDHC_GPIO_OUT ; 
 int SDHC_MMCM_CLKFBOUT ; 
 int SDHC_MMCM_DIV_REG ; 
 int SDHC_SW_TUNE_EN ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int /*<<< orphan*/  sdhci_set_clock (struct sdhci_host*,unsigned int) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 
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

__attribute__((used)) static void sdhci_snps_set_clock(struct sdhci_host *host, unsigned int clock)
{
	u16 clk;
	u32 reg, vendor_ptr;

	vendor_ptr = sdhci_readw(host, SDHCI_VENDOR_PTR_R);

	/* Disable software managed rx tuning */
	reg = sdhci_readl(host, (SDHC_AT_CTRL_R + vendor_ptr));
	reg &= ~SDHC_SW_TUNE_EN;
	sdhci_writel(host, reg, (SDHC_AT_CTRL_R + vendor_ptr));

	if (clock <= 52000000) {
		sdhci_set_clock(host, clock);
	} else {
		/* Assert reset to MMCM */
		reg = sdhci_readl(host, (SDHC_GPIO_OUT + vendor_ptr));
		reg |= SDHC_CCLK_MMCM_RST;
		sdhci_writel(host, reg, (SDHC_GPIO_OUT + vendor_ptr));

		/* Configure MMCM */
		if (clock == 100000000) {
			sdhci_writel(host, DIV_REG_100_MHZ, SDHC_MMCM_DIV_REG);
			sdhci_writel(host, CLKFBOUT_100_MHZ,
					SDHC_MMCM_CLKFBOUT);
		} else {
			sdhci_writel(host, DIV_REG_200_MHZ, SDHC_MMCM_DIV_REG);
			sdhci_writel(host, CLKFBOUT_200_MHZ,
					SDHC_MMCM_CLKFBOUT);
		}

		/* De-assert reset to MMCM */
		reg = sdhci_readl(host, (SDHC_GPIO_OUT + vendor_ptr));
		reg &= ~SDHC_CCLK_MMCM_RST;
		sdhci_writel(host, reg, (SDHC_GPIO_OUT + vendor_ptr));

		/* Enable clock */
		clk = SDHCI_PROG_CLOCK_MODE | SDHCI_CLOCK_INT_EN |
			SDHCI_CLOCK_CARD_EN;
		sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
	}
}


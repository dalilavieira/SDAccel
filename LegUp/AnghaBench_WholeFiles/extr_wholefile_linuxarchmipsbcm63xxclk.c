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
typedef  int /*<<< orphan*/  u32 ;
struct clk {scalar_t__ usage; scalar_t__ id; unsigned long rate; int /*<<< orphan*/  (* set ) (struct clk*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BCM63XX_RESET_ENETSW ; 
 int /*<<< orphan*/  BCM63XX_RESET_SAR ; 
 scalar_t__ BCMCPU_IS_3368 () ; 
 scalar_t__ BCMCPU_IS_6328 () ; 
 scalar_t__ BCMCPU_IS_6338 () ; 
 scalar_t__ BCMCPU_IS_6345 () ; 
 scalar_t__ BCMCPU_IS_6348 () ; 
 scalar_t__ BCMCPU_IS_6358 () ; 
 scalar_t__ BCMCPU_IS_6362 () ; 
 scalar_t__ BCMCPU_IS_6368 () ; 
 int /*<<< orphan*/  CKCTL_3368_PCM_EN ; 
 int /*<<< orphan*/  CKCTL_6328_HSSPI_EN ; 
 int /*<<< orphan*/  CKCTL_6328_PCIE_EN ; 
 int /*<<< orphan*/  CKCTL_6328_ROBOSW_EN ; 
 int /*<<< orphan*/  CKCTL_6328_USBD_EN ; 
 int /*<<< orphan*/  CKCTL_6328_USBH_EN ; 
 int /*<<< orphan*/  CKCTL_6338_ENET_EN ; 
 int /*<<< orphan*/  CKCTL_6338_SPI_EN ; 
 int /*<<< orphan*/  CKCTL_6345_ENET_EN ; 
 int /*<<< orphan*/  CKCTL_6348_ENET_EN ; 
 int /*<<< orphan*/  CKCTL_6348_SPI_EN ; 
 int /*<<< orphan*/  CKCTL_6348_USBH_EN ; 
 int /*<<< orphan*/  CKCTL_6358_EMUSB_EN ; 
 int /*<<< orphan*/  CKCTL_6358_ENET0_EN ; 
 int /*<<< orphan*/  CKCTL_6358_ENET1_EN ; 
 int /*<<< orphan*/  CKCTL_6358_EPHY_EN ; 
 int /*<<< orphan*/  CKCTL_6358_PCM_EN ; 
 int /*<<< orphan*/  CKCTL_6358_SPI_EN ; 
 int /*<<< orphan*/  CKCTL_6362_HSSPI_EN ; 
 int /*<<< orphan*/  CKCTL_6362_IPSEC_EN ; 
 int /*<<< orphan*/  CKCTL_6362_PCIE_EN ; 
 int /*<<< orphan*/  CKCTL_6362_ROBOSW_EN ; 
 int /*<<< orphan*/  CKCTL_6362_SPI_EN ; 
 int /*<<< orphan*/  CKCTL_6362_USBD_EN ; 
 int /*<<< orphan*/  CKCTL_6362_USBH_EN ; 
 int /*<<< orphan*/  CKCTL_6368_IPSEC_EN ; 
 int /*<<< orphan*/  CKCTL_6368_ROBOSW_EN ; 
 int /*<<< orphan*/  CKCTL_6368_SAR_EN ; 
 int /*<<< orphan*/  CKCTL_6368_SPI_EN ; 
 int /*<<< orphan*/  CKCTL_6368_SWPKT_SAR_EN ; 
 int /*<<< orphan*/  CKCTL_6368_SWPKT_USB_EN ; 
 int /*<<< orphan*/  CKCTL_6368_USBD_EN ; 
 int /*<<< orphan*/  CKCTL_6368_USBH_EN ; 
 int /*<<< orphan*/  PERF_CKCTL_REG ; 
 int /*<<< orphan*/  bcm63xx_core_set_reset (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bcm_perf_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm_perf_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct clk clk_enet_misc ; 
 struct clk clk_swpkt_sar ; 
 struct clk clk_swpkt_usb ; 
 int /*<<< orphan*/  clocks_mutex ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct clk*,int) ; 
 int /*<<< orphan*/  stub2 (struct clk*,int) ; 

__attribute__((used)) static void clk_enable_unlocked(struct clk *clk)
{
	if (clk->set && (clk->usage++) == 0)
		clk->set(clk, 1);
}

__attribute__((used)) static void clk_disable_unlocked(struct clk *clk)
{
	if (clk->set && (--clk->usage) == 0)
		clk->set(clk, 0);
}

__attribute__((used)) static void bcm_hwclock_set(u32 mask, int enable)
{
	u32 reg;

	reg = bcm_perf_readl(PERF_CKCTL_REG);
	if (enable)
		reg |= mask;
	else
		reg &= ~mask;
	bcm_perf_writel(reg, PERF_CKCTL_REG);
}

__attribute__((used)) static void enet_misc_set(struct clk *clk, int enable)
{
	u32 mask;

	if (BCMCPU_IS_6338())
		mask = CKCTL_6338_ENET_EN;
	else if (BCMCPU_IS_6345())
		mask = CKCTL_6345_ENET_EN;
	else if (BCMCPU_IS_6348())
		mask = CKCTL_6348_ENET_EN;
	else
		/* BCMCPU_IS_6358 */
		mask = CKCTL_6358_EMUSB_EN;
	bcm_hwclock_set(mask, enable);
}

__attribute__((used)) static void enetx_set(struct clk *clk, int enable)
{
	if (enable)
		clk_enable_unlocked(&clk_enet_misc);
	else
		clk_disable_unlocked(&clk_enet_misc);

	if (BCMCPU_IS_3368() || BCMCPU_IS_6358()) {
		u32 mask;

		if (clk->id == 0)
			mask = CKCTL_6358_ENET0_EN;
		else
			mask = CKCTL_6358_ENET1_EN;
		bcm_hwclock_set(mask, enable);
	}
}

__attribute__((used)) static void ephy_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_3368() || BCMCPU_IS_6358())
		bcm_hwclock_set(CKCTL_6358_EPHY_EN, enable);
}

__attribute__((used)) static void swpkt_sar_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6368())
		bcm_hwclock_set(CKCTL_6368_SWPKT_SAR_EN, enable);
	else
		return;
}

__attribute__((used)) static void swpkt_usb_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6368())
		bcm_hwclock_set(CKCTL_6368_SWPKT_USB_EN, enable);
	else
		return;
}

__attribute__((used)) static void enetsw_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6328()) {
		bcm_hwclock_set(CKCTL_6328_ROBOSW_EN, enable);
	} else if (BCMCPU_IS_6362()) {
		bcm_hwclock_set(CKCTL_6362_ROBOSW_EN, enable);
	} else if (BCMCPU_IS_6368()) {
		if (enable) {
			clk_enable_unlocked(&clk_swpkt_sar);
			clk_enable_unlocked(&clk_swpkt_usb);
		} else {
			clk_disable_unlocked(&clk_swpkt_usb);
			clk_disable_unlocked(&clk_swpkt_sar);
		}
		bcm_hwclock_set(CKCTL_6368_ROBOSW_EN, enable);
	} else {
		return;
	}

	if (enable) {
		/* reset switch core afer clock change */
		bcm63xx_core_set_reset(BCM63XX_RESET_ENETSW, 1);
		msleep(10);
		bcm63xx_core_set_reset(BCM63XX_RESET_ENETSW, 0);
		msleep(10);
	}
}

__attribute__((used)) static void pcm_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_3368())
		bcm_hwclock_set(CKCTL_3368_PCM_EN, enable);
	if (BCMCPU_IS_6358())
		bcm_hwclock_set(CKCTL_6358_PCM_EN, enable);
}

__attribute__((used)) static void usbh_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6328())
		bcm_hwclock_set(CKCTL_6328_USBH_EN, enable);
	else if (BCMCPU_IS_6348())
		bcm_hwclock_set(CKCTL_6348_USBH_EN, enable);
	else if (BCMCPU_IS_6362())
		bcm_hwclock_set(CKCTL_6362_USBH_EN, enable);
	else if (BCMCPU_IS_6368())
		bcm_hwclock_set(CKCTL_6368_USBH_EN, enable);
}

__attribute__((used)) static void usbd_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6328())
		bcm_hwclock_set(CKCTL_6328_USBD_EN, enable);
	else if (BCMCPU_IS_6362())
		bcm_hwclock_set(CKCTL_6362_USBD_EN, enable);
	else if (BCMCPU_IS_6368())
		bcm_hwclock_set(CKCTL_6368_USBD_EN, enable);
}

__attribute__((used)) static void spi_set(struct clk *clk, int enable)
{
	u32 mask;

	if (BCMCPU_IS_6338())
		mask = CKCTL_6338_SPI_EN;
	else if (BCMCPU_IS_6348())
		mask = CKCTL_6348_SPI_EN;
	else if (BCMCPU_IS_3368() || BCMCPU_IS_6358())
		mask = CKCTL_6358_SPI_EN;
	else if (BCMCPU_IS_6362())
		mask = CKCTL_6362_SPI_EN;
	else
		/* BCMCPU_IS_6368 */
		mask = CKCTL_6368_SPI_EN;
	bcm_hwclock_set(mask, enable);
}

__attribute__((used)) static void hsspi_set(struct clk *clk, int enable)
{
	u32 mask;

	if (BCMCPU_IS_6328())
		mask = CKCTL_6328_HSSPI_EN;
	else if (BCMCPU_IS_6362())
		mask = CKCTL_6362_HSSPI_EN;
	else
		return;

	bcm_hwclock_set(mask, enable);
}

__attribute__((used)) static void xtm_set(struct clk *clk, int enable)
{
	if (!BCMCPU_IS_6368())
		return;

	if (enable)
		clk_enable_unlocked(&clk_swpkt_sar);
	else
		clk_disable_unlocked(&clk_swpkt_sar);

	bcm_hwclock_set(CKCTL_6368_SAR_EN, enable);

	if (enable) {
		/* reset sar core afer clock change */
		bcm63xx_core_set_reset(BCM63XX_RESET_SAR, 1);
		mdelay(1);
		bcm63xx_core_set_reset(BCM63XX_RESET_SAR, 0);
		mdelay(1);
	}
}

__attribute__((used)) static void ipsec_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6362())
		bcm_hwclock_set(CKCTL_6362_IPSEC_EN, enable);
	else if (BCMCPU_IS_6368())
		bcm_hwclock_set(CKCTL_6368_IPSEC_EN, enable);
}

__attribute__((used)) static void pcie_set(struct clk *clk, int enable)
{
	if (BCMCPU_IS_6328())
		bcm_hwclock_set(CKCTL_6328_PCIE_EN, enable);
	else if (BCMCPU_IS_6362())
		bcm_hwclock_set(CKCTL_6362_PCIE_EN, enable);
}

int clk_enable(struct clk *clk)
{
	mutex_lock(&clocks_mutex);
	clk_enable_unlocked(clk);
	mutex_unlock(&clocks_mutex);
	return 0;
}

void clk_disable(struct clk *clk)
{
	if (!clk)
		return;

	mutex_lock(&clocks_mutex);
	clk_disable_unlocked(clk);
	mutex_unlock(&clocks_mutex);
}

unsigned long clk_get_rate(struct clk *clk)
{
	if (!clk)
		return 0;

	return clk->rate;
}

int clk_set_rate(struct clk *clk, unsigned long rate)
{
	return 0;
}

long clk_round_rate(struct clk *clk, unsigned long rate)
{
	return 0;
}


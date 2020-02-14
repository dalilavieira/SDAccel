#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct bcma_drv_pci {int dummy; } ;
struct bcma_drv_mips {int dummy; } ;
struct bcma_drv_gmac_cmn {int dummy; } ;
struct bcma_drv_cc {TYPE_1__* core; } ;
struct TYPE_6__ {scalar_t__ id; } ;
struct bcma_device {TYPE_3__* bus; TYPE_2__ id; } ;
typedef  enum bcma_clkmode { ____Placeholder_bcma_clkmode } bcma_clkmode ;
struct TYPE_7__ {int hosttype; } ;
struct TYPE_5__ {int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 int /*<<< orphan*/  BCMA_CLKCTLST ; 
 int BCMA_CLKCTLST_EXTRESREQ ; 
 int BCMA_CLKCTLST_EXTRESST ; 
 int BCMA_CLKCTLST_FORCEHT ; 
 int BCMA_CLKCTLST_HAVEHT ; 
#define  BCMA_CLKMODE_DYNAMIC 131 
#define  BCMA_CLKMODE_FAST 130 
 scalar_t__ BCMA_CORE_80211 ; 
 scalar_t__ BCMA_CORE_CHIPCOMMON ; 
 scalar_t__ BCMA_CORE_PCIE ; 
 int BCMA_DMA_TRANSLATION_DMA32_CMT ; 
 int BCMA_DMA_TRANSLATION_DMA64_CMT ; 
 int BCMA_DMA_TRANSLATION_NONE ; 
#define  BCMA_HOSTTYPE_PCI 129 
#define  BCMA_HOSTTYPE_SOC 128 
 int BCMA_IOCTL ; 
 int BCMA_IOCTL_CLK ; 
 int BCMA_IOCTL_FGC ; 
 int BCMA_IOST ; 
 int BCMA_IOST_DMA64 ; 
 int BCMA_RESET_CTL ; 
 int BCMA_RESET_CTL_RESET ; 
 int BCMA_RESET_ST ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int bcma_aread32 (struct bcma_device*,int) ; 
 int /*<<< orphan*/  bcma_awrite32 (struct bcma_device*,int,int) ; 
 int /*<<< orphan*/  bcma_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  bcma_mask32 (struct bcma_device*,int /*<<< orphan*/ ,int) ; 
 int bcma_read32 (struct bcma_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcma_set32 (struct bcma_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bcma_warn (TYPE_3__*,char*,int) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int jiffies ; 
 int /*<<< orphan*/  time_after_eq (int,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline int bcma_pflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "Parallel flash not supported\n");
	return 0;
}

__attribute__((used)) static inline int bcma_sflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "Serial flash not supported\n");
	return 0;
}

__attribute__((used)) static inline int bcma_nflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "NAND flash not supported\n");
	return 0;
}

__attribute__((used)) static inline bool bcma_core_pci_is_in_hostmode(struct bcma_drv_pci *pc)
{
	return false;
}

__attribute__((used)) static inline void bcma_core_pci_hostmode_init(struct bcma_drv_pci *pc)
{
}

__attribute__((used)) static inline unsigned int bcma_core_mips_irq(struct bcma_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void bcma_core_mips_early_init(struct bcma_drv_mips *mcore)
{
}

__attribute__((used)) static inline void bcma_core_mips_init(struct bcma_drv_mips *mcore)
{
}

__attribute__((used)) static inline void bcma_core_gmac_cmn_init(struct bcma_drv_gmac_cmn *gc)
{
}

__attribute__((used)) static inline int bcma_gpio_init(struct bcma_drv_cc *cc)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline int bcma_gpio_unregister(struct bcma_drv_cc *cc)
{
	return 0;
}

__attribute__((used)) static bool bcma_core_wait_value(struct bcma_device *core, u16 reg, u32 mask,
				 u32 value, int timeout)
{
	unsigned long deadline = jiffies + timeout;
	u32 val;

	do {
		val = bcma_aread32(core, reg);
		if ((val & mask) == value)
			return true;
		cpu_relax();
		udelay(10);
	} while (!time_after_eq(jiffies, deadline));

	bcma_warn(core->bus, "Timeout waiting for register 0x%04X!\n", reg);

	return false;
}

bool bcma_core_is_enabled(struct bcma_device *core)
{
	if ((bcma_aread32(core, BCMA_IOCTL) & (BCMA_IOCTL_CLK | BCMA_IOCTL_FGC))
	    != BCMA_IOCTL_CLK)
		return false;
	if (bcma_aread32(core, BCMA_RESET_CTL) & BCMA_RESET_CTL_RESET)
		return false;
	return true;
}

void bcma_core_disable(struct bcma_device *core, u32 flags)
{
	if (bcma_aread32(core, BCMA_RESET_CTL) & BCMA_RESET_CTL_RESET)
		return;

	bcma_core_wait_value(core, BCMA_RESET_ST, ~0, 0, 300);

	bcma_awrite32(core, BCMA_RESET_CTL, BCMA_RESET_CTL_RESET);
	bcma_aread32(core, BCMA_RESET_CTL);
	udelay(1);

	bcma_awrite32(core, BCMA_IOCTL, flags);
	bcma_aread32(core, BCMA_IOCTL);
	udelay(10);
}

int bcma_core_enable(struct bcma_device *core, u32 flags)
{
	bcma_core_disable(core, flags);

	bcma_awrite32(core, BCMA_IOCTL, (BCMA_IOCTL_CLK | BCMA_IOCTL_FGC | flags));
	bcma_aread32(core, BCMA_IOCTL);

	bcma_awrite32(core, BCMA_RESET_CTL, 0);
	bcma_aread32(core, BCMA_RESET_CTL);
	udelay(1);

	bcma_awrite32(core, BCMA_IOCTL, (BCMA_IOCTL_CLK | flags));
	bcma_aread32(core, BCMA_IOCTL);
	udelay(1);

	return 0;
}

void bcma_core_set_clockmode(struct bcma_device *core,
			     enum bcma_clkmode clkmode)
{
	u16 i;

	WARN_ON(core->id.id != BCMA_CORE_CHIPCOMMON &&
		core->id.id != BCMA_CORE_PCIE &&
		core->id.id != BCMA_CORE_80211);

	switch (clkmode) {
	case BCMA_CLKMODE_FAST:
		bcma_set32(core, BCMA_CLKCTLST, BCMA_CLKCTLST_FORCEHT);
		usleep_range(64, 300);
		for (i = 0; i < 1500; i++) {
			if (bcma_read32(core, BCMA_CLKCTLST) &
			    BCMA_CLKCTLST_HAVEHT) {
				i = 0;
				break;
			}
			udelay(10);
		}
		if (i)
			bcma_err(core->bus, "HT force timeout\n");
		break;
	case BCMA_CLKMODE_DYNAMIC:
		bcma_set32(core, BCMA_CLKCTLST, ~BCMA_CLKCTLST_FORCEHT);
		break;
	}
}

void bcma_core_pll_ctl(struct bcma_device *core, u32 req, u32 status, bool on)
{
	u16 i;

	WARN_ON(req & ~BCMA_CLKCTLST_EXTRESREQ);
	WARN_ON(status & ~BCMA_CLKCTLST_EXTRESST);

	if (on) {
		bcma_set32(core, BCMA_CLKCTLST, req);
		for (i = 0; i < 10000; i++) {
			if ((bcma_read32(core, BCMA_CLKCTLST) & status) ==
			    status) {
				i = 0;
				break;
			}
			udelay(10);
		}
		if (i)
			bcma_err(core->bus, "PLL enable timeout\n");
	} else {
		/*
		 * Mask the PLL but don't wait for it to be disabled. PLL may be
		 * shared between cores and will be still up if there is another
		 * core using it.
		 */
		bcma_mask32(core, BCMA_CLKCTLST, ~req);
		bcma_read32(core, BCMA_CLKCTLST);
	}
}

u32 bcma_core_dma_translation(struct bcma_device *core)
{
	switch (core->bus->hosttype) {
	case BCMA_HOSTTYPE_SOC:
		return 0;
	case BCMA_HOSTTYPE_PCI:
		if (bcma_aread32(core, BCMA_IOST) & BCMA_IOST_DMA64)
			return BCMA_DMA_TRANSLATION_DMA64_CMT;
		else
			return BCMA_DMA_TRANSLATION_DMA32_CMT;
	default:
		bcma_err(core->bus, "DMA translation unknown for host %d\n",
			 core->bus->hosttype);
	}
	return BCMA_DMA_TRANSLATION_NONE;
}


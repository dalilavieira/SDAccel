#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wdt ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct platform_device {int dummy; } ;
struct bcma_drv_pci {int dummy; } ;
struct bcma_drv_mips {int dummy; } ;
struct bcma_drv_gmac_cmn {int dummy; } ;
struct bcma_drv_cc {int capabilities; int ticks_per_ms; int early_setup_done; int status; int capabilities_ext; int setup_done; int /*<<< orphan*/  gpio_lock; TYPE_4__* core; struct platform_device* watchdog; } ;
struct bcma_device {int dummy; } ;
struct TYPE_6__ {scalar_t__ id; int rev; } ;
struct TYPE_5__ {int leddc_on_time; int leddc_off_time; } ;
struct bcma_bus {scalar_t__ hosttype; TYPE_2__ chipinfo; TYPE_1__ sprom; int /*<<< orphan*/  num; } ;
struct bcm47xx_wdt {int (* timer_set ) (struct bcm47xx_wdt*,int) ;int (* timer_set_ms ) (struct bcm47xx_wdt*,int) ;int max_timer_ms; struct bcma_drv_cc* driver_data; } ;
struct TYPE_7__ {int rev; } ;
struct TYPE_8__ {TYPE_3__ id; struct bcma_bus* bus; } ;

/* Variables and functions */
 int /*<<< orphan*/  BCMA_CC_CAP ; 
 int /*<<< orphan*/  BCMA_CC_CAP_EXT ; 
 int BCMA_CC_CAP_FLASHT ; 
 int BCMA_CC_CAP_NFLASH ; 
 int BCMA_CC_CAP_PCTL ; 
 int BCMA_CC_CAP_PMU ; 
 int /*<<< orphan*/  BCMA_CC_CHIPSTAT ; 
#define  BCMA_CC_FLASHT_ATSER 130 
#define  BCMA_CC_FLASHT_PARA 129 
#define  BCMA_CC_FLASHT_STSER 128 
 int /*<<< orphan*/  BCMA_CC_GPIOCTL ; 
 int /*<<< orphan*/  BCMA_CC_GPIOIN ; 
 int /*<<< orphan*/  BCMA_CC_GPIOIRQ ; 
 int /*<<< orphan*/  BCMA_CC_GPIOOUT ; 
 int /*<<< orphan*/  BCMA_CC_GPIOOUTEN ; 
 int /*<<< orphan*/  BCMA_CC_GPIOPOL ; 
 int /*<<< orphan*/  BCMA_CC_GPIOPULLDOWN ; 
 int /*<<< orphan*/  BCMA_CC_GPIOPULLUP ; 
 int /*<<< orphan*/  BCMA_CC_GPIOTIMER ; 
 int BCMA_CC_GPIOTIMER_OFFTIME_SHIFT ; 
 int BCMA_CC_GPIOTIMER_ONTIME_SHIFT ; 
 int /*<<< orphan*/  BCMA_CC_IRQMASK ; 
 int /*<<< orphan*/  BCMA_CC_IRQSTAT ; 
 int /*<<< orphan*/  BCMA_CC_PMU_WATCHDOG ; 
 int /*<<< orphan*/  BCMA_CC_WATCHDOG ; 
 scalar_t__ BCMA_CHIP_ID_BCM43142 ; 
 scalar_t__ BCMA_CHIP_ID_BCM4706 ; 
 scalar_t__ BCMA_CHIP_ID_BCM4707 ; 
 scalar_t__ BCMA_CHIP_ID_BCM47094 ; 
 scalar_t__ BCMA_CHIP_ID_BCM53018 ; 
 scalar_t__ BCMA_CHIP_ID_BCM53573 ; 
 int /*<<< orphan*/  BCMA_CLKMODE_DYNAMIC ; 
 int /*<<< orphan*/  BCMA_CLKMODE_FAST ; 
 scalar_t__ BCMA_HOSTTYPE_SOC ; 
 int ENOTSUPP ; 
 scalar_t__ IS_ERR (struct platform_device*) ; 
 int PTR_ERR (struct platform_device*) ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 struct bcma_drv_cc* bcm47xx_wdt_get_drvdata (struct bcm47xx_wdt*) ; 
 int bcma_cc_read32 (struct bcma_drv_cc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcma_cc_write32 (struct bcma_drv_cc*,int /*<<< orphan*/ ,int) ; 
 int bcma_chipco_watchdog_timer_set (struct bcma_drv_cc*,int) ; 
 int /*<<< orphan*/  bcma_core_set_clockmode (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcma_debug (struct bcma_bus*,char*) ; 
 int /*<<< orphan*/  bcma_err (struct bcma_bus*,char*) ; 
 int /*<<< orphan*/  bcma_pmu_early_init (struct bcma_drv_cc*) ; 
 int bcma_pmu_get_alp_clock (struct bcma_drv_cc*) ; 
 int /*<<< orphan*/  bcma_pmu_init (struct bcma_drv_cc*) ; 
 int /*<<< orphan*/  bcma_pmu_write32 (struct bcma_drv_cc*,int /*<<< orphan*/ ,int) ; 
 struct platform_device* platform_device_register_data (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,struct bcm47xx_wdt*,int) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

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

__attribute__((used)) static inline u32 bcma_cc_write32_masked(struct bcma_drv_cc *cc, u16 offset,
					 u32 mask, u32 value)
{
	value &= mask;
	value |= bcma_cc_read32(cc, offset) & ~mask;
	bcma_cc_write32(cc, offset, value);

	return value;
}

u32 bcma_chipco_get_alp_clock(struct bcma_drv_cc *cc)
{
	if (cc->capabilities & BCMA_CC_CAP_PMU)
		return bcma_pmu_get_alp_clock(cc);

	return 20000000;
}

__attribute__((used)) static bool bcma_core_cc_has_pmu_watchdog(struct bcma_drv_cc *cc)
{
	struct bcma_bus *bus = cc->core->bus;

	if (cc->capabilities & BCMA_CC_CAP_PMU) {
		if (bus->chipinfo.id == BCMA_CHIP_ID_BCM53573) {
			WARN(bus->chipinfo.rev <= 1, "No watchdog available\n");
			/* 53573B0 and 53573B1 have bugged PMU watchdog. It can
			 * be enabled but timer can't be bumped. Use CC one
			 * instead.
			 */
			return false;
		}
		return true;
	} else {
		return false;
	}
}

__attribute__((used)) static u32 bcma_chipco_watchdog_get_max_timer(struct bcma_drv_cc *cc)
{
	struct bcma_bus *bus = cc->core->bus;
	u32 nb;

	if (bcma_core_cc_has_pmu_watchdog(cc)) {
		if (bus->chipinfo.id == BCMA_CHIP_ID_BCM4706)
			nb = 32;
		else if (cc->core->id.rev < 26)
			nb = 16;
		else
			nb = (cc->core->id.rev >= 37) ? 32 : 24;
	} else {
		nb = 28;
	}
	if (nb == 32)
		return 0xffffffff;
	else
		return (1 << nb) - 1;
}

__attribute__((used)) static u32 bcma_chipco_watchdog_timer_set_wdt(struct bcm47xx_wdt *wdt,
					      u32 ticks)
{
	struct bcma_drv_cc *cc = bcm47xx_wdt_get_drvdata(wdt);

	return bcma_chipco_watchdog_timer_set(cc, ticks);
}

__attribute__((used)) static u32 bcma_chipco_watchdog_timer_set_ms_wdt(struct bcm47xx_wdt *wdt,
						 u32 ms)
{
	struct bcma_drv_cc *cc = bcm47xx_wdt_get_drvdata(wdt);
	u32 ticks;

	ticks = bcma_chipco_watchdog_timer_set(cc, cc->ticks_per_ms * ms);
	return ticks / cc->ticks_per_ms;
}

__attribute__((used)) static int bcma_chipco_watchdog_ticks_per_ms(struct bcma_drv_cc *cc)
{
	struct bcma_bus *bus = cc->core->bus;

	if (cc->capabilities & BCMA_CC_CAP_PMU) {
		if (bus->chipinfo.id == BCMA_CHIP_ID_BCM4706)
			/* 4706 CC and PMU watchdogs are clocked at 1/4 of ALP
			 * clock
			 */
			return bcma_chipco_get_alp_clock(cc) / 4000;
		else
			/* based on 32KHz ILP clock */
			return 32;
	} else {
		return bcma_chipco_get_alp_clock(cc) / 1000;
	}
}

int bcma_chipco_watchdog_register(struct bcma_drv_cc *cc)
{
	struct bcma_bus *bus = cc->core->bus;
	struct bcm47xx_wdt wdt = {};
	struct platform_device *pdev;

	if (bus->chipinfo.id == BCMA_CHIP_ID_BCM53573 &&
	    bus->chipinfo.rev <= 1) {
		pr_debug("No watchdog on 53573A0 / 53573A1\n");
		return 0;
	}

	wdt.driver_data = cc;
	wdt.timer_set = bcma_chipco_watchdog_timer_set_wdt;
	wdt.timer_set_ms = bcma_chipco_watchdog_timer_set_ms_wdt;
	wdt.max_timer_ms =
		bcma_chipco_watchdog_get_max_timer(cc) / cc->ticks_per_ms;

	pdev = platform_device_register_data(NULL, "bcm47xx-wdt",
					     bus->num, &wdt,
					     sizeof(wdt));
	if (IS_ERR(pdev))
		return PTR_ERR(pdev);

	cc->watchdog = pdev;

	return 0;
}

__attribute__((used)) static void bcma_core_chipcommon_flash_detect(struct bcma_drv_cc *cc)
{
	struct bcma_bus *bus = cc->core->bus;

	switch (cc->capabilities & BCMA_CC_CAP_FLASHT) {
	case BCMA_CC_FLASHT_STSER:
	case BCMA_CC_FLASHT_ATSER:
		bcma_debug(bus, "Found serial flash\n");
		bcma_sflash_init(cc);
		break;
	case BCMA_CC_FLASHT_PARA:
		bcma_debug(bus, "Found parallel flash\n");
		bcma_pflash_init(cc);
		break;
	default:
		bcma_err(bus, "Flash type not supported\n");
	}

	if (cc->core->id.rev == 38 ||
	    bus->chipinfo.id == BCMA_CHIP_ID_BCM4706) {
		if (cc->capabilities & BCMA_CC_CAP_NFLASH) {
			bcma_debug(bus, "Found NAND flash\n");
			bcma_nflash_init(cc);
		}
	}
}

void bcma_core_chipcommon_early_init(struct bcma_drv_cc *cc)
{
	struct bcma_bus *bus = cc->core->bus;

	if (cc->early_setup_done)
		return;

	spin_lock_init(&cc->gpio_lock);

	if (cc->core->id.rev >= 11)
		cc->status = bcma_cc_read32(cc, BCMA_CC_CHIPSTAT);
	cc->capabilities = bcma_cc_read32(cc, BCMA_CC_CAP);
	if (cc->core->id.rev >= 35)
		cc->capabilities_ext = bcma_cc_read32(cc, BCMA_CC_CAP_EXT);

	if (cc->capabilities & BCMA_CC_CAP_PMU)
		bcma_pmu_early_init(cc);

	if (bus->hosttype == BCMA_HOSTTYPE_SOC)
		bcma_core_chipcommon_flash_detect(cc);

	cc->early_setup_done = true;
}

void bcma_core_chipcommon_init(struct bcma_drv_cc *cc)
{
	u32 leddc_on = 10;
	u32 leddc_off = 90;

	if (cc->setup_done)
		return;

	bcma_core_chipcommon_early_init(cc);

	if (cc->core->id.rev >= 20) {
		u32 pullup = 0, pulldown = 0;

		if (cc->core->bus->chipinfo.id == BCMA_CHIP_ID_BCM43142) {
			pullup = 0x402e0;
			pulldown = 0x20500;
		}

		bcma_cc_write32(cc, BCMA_CC_GPIOPULLUP, pullup);
		bcma_cc_write32(cc, BCMA_CC_GPIOPULLDOWN, pulldown);
	}

	if (cc->capabilities & BCMA_CC_CAP_PMU)
		bcma_pmu_init(cc);
	if (cc->capabilities & BCMA_CC_CAP_PCTL)
		bcma_err(cc->core->bus, "Power control not implemented!\n");

	if (cc->core->id.rev >= 16) {
		if (cc->core->bus->sprom.leddc_on_time &&
		    cc->core->bus->sprom.leddc_off_time) {
			leddc_on = cc->core->bus->sprom.leddc_on_time;
			leddc_off = cc->core->bus->sprom.leddc_off_time;
		}
		bcma_cc_write32(cc, BCMA_CC_GPIOTIMER,
			((leddc_on << BCMA_CC_GPIOTIMER_ONTIME_SHIFT) |
			 (leddc_off << BCMA_CC_GPIOTIMER_OFFTIME_SHIFT)));
	}
	cc->ticks_per_ms = bcma_chipco_watchdog_ticks_per_ms(cc);

	cc->setup_done = true;
}

u32 bcma_chipco_watchdog_timer_set(struct bcma_drv_cc *cc, u32 ticks)
{
	u32 maxt;

	maxt = bcma_chipco_watchdog_get_max_timer(cc);
	if (bcma_core_cc_has_pmu_watchdog(cc)) {
		if (ticks == 1)
			ticks = 2;
		else if (ticks > maxt)
			ticks = maxt;
		bcma_pmu_write32(cc, BCMA_CC_PMU_WATCHDOG, ticks);
	} else {
		struct bcma_bus *bus = cc->core->bus;

		if (bus->chipinfo.id != BCMA_CHIP_ID_BCM4707 &&
		    bus->chipinfo.id != BCMA_CHIP_ID_BCM47094 &&
		    bus->chipinfo.id != BCMA_CHIP_ID_BCM53018)
			bcma_core_set_clockmode(cc->core,
						ticks ? BCMA_CLKMODE_FAST : BCMA_CLKMODE_DYNAMIC);

		if (ticks > maxt)
			ticks = maxt;
		/* instant NMI */
		bcma_cc_write32(cc, BCMA_CC_WATCHDOG, ticks);
	}
	return ticks;
}

void bcma_chipco_irq_mask(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	bcma_cc_write32_masked(cc, BCMA_CC_IRQMASK, mask, value);
}

u32 bcma_chipco_irq_status(struct bcma_drv_cc *cc, u32 mask)
{
	return bcma_cc_read32(cc, BCMA_CC_IRQSTAT) & mask;
}

u32 bcma_chipco_gpio_in(struct bcma_drv_cc *cc, u32 mask)
{
	return bcma_cc_read32(cc, BCMA_CC_GPIOIN) & mask;
}

u32 bcma_chipco_gpio_out(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOOUT, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}

u32 bcma_chipco_gpio_outen(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOOUTEN, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}

u32 bcma_chipco_gpio_control(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOCTL, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}

u32 bcma_chipco_gpio_intmask(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOIRQ, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}

u32 bcma_chipco_gpio_polarity(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOPOL, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}

u32 bcma_chipco_gpio_pullup(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	if (cc->core->id.rev < 20)
		return 0;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOPULLUP, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}

u32 bcma_chipco_gpio_pulldown(struct bcma_drv_cc *cc, u32 mask, u32 value)
{
	unsigned long flags;
	u32 res;

	if (cc->core->id.rev < 20)
		return 0;

	spin_lock_irqsave(&cc->gpio_lock, flags);
	res = bcma_cc_write32_masked(cc, BCMA_CC_GPIOPULLDOWN, mask, value);
	spin_unlock_irqrestore(&cc->gpio_lock, flags);

	return res;
}


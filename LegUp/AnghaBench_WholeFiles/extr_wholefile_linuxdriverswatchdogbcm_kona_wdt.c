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
typedef  int uint32_t ;
struct watchdog_device {unsigned int timeout; struct device* parent; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct bcm_kona_wdt {int base; unsigned int resolution; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int) ; 
 unsigned int SECS_TO_TICKS (unsigned int,struct bcm_kona_wdt*) ; 
 unsigned int SECWDOG_CLKS_SHIFT ; 
 int SECWDOG_COUNT_MASK ; 
 int SECWDOG_COUNT_REG ; 
 int SECWDOG_CTRL_REG ; 
 unsigned int SECWDOG_DEFAULT_RESOLUTION ; 
 unsigned int SECWDOG_EN_MASK ; 
 unsigned int SECWDOG_MAX_RES ; 
 unsigned int SECWDOG_MAX_TRY ; 
 int SECWDOG_RESERVED_MASK ; 
 unsigned int SECWDOG_RES_MASK ; 
 unsigned int SECWDOG_SRSTEN_MASK ; 
 int SECWDOG_WD_LOAD_FLAG ; 
 unsigned int TICKS_TO_SECS (int,struct bcm_kona_wdt*) ; 
 struct watchdog_device bcm_kona_wdt_wdd ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int devm_ioremap_resource (struct device*,struct resource*) ; 
 struct bcm_kona_wdt* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bcm_kona_wdt*) ; 
 int readl_relaxed (int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 scalar_t__ unlikely (int) ; 
 struct bcm_kona_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct bcm_kona_wdt*) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  writel_relaxed (int,int) ; 

__attribute__((used)) static int secure_register_read(struct bcm_kona_wdt *wdt, uint32_t offset)
{
	uint32_t val;
	unsigned count = 0;

	/*
	 * If the WD_LOAD_FLAG is set, the watchdog counter field is being
	 * updated in hardware. Once the WD timer is updated in hardware, it
	 * gets cleared.
	 */
	do {
		if (unlikely(count > 1))
			udelay(5);
		val = readl_relaxed(wdt->base + offset);
		count++;
	} while ((val & SECWDOG_WD_LOAD_FLAG) && count < SECWDOG_MAX_TRY);

#ifdef CONFIG_BCM_KONA_WDT_DEBUG
	/* Remember the maximum number iterations due to WD_LOAD_FLAG */
	if (count > wdt->busy_count)
		wdt->busy_count = count;
#endif

	/* This is the only place we return a negative value. */
	if (val & SECWDOG_WD_LOAD_FLAG)
		return -ETIMEDOUT;

	/* We always mask out reserved bits. */
	val &= SECWDOG_RESERVED_MASK;

	return val;
}

__attribute__((used)) static void bcm_kona_wdt_debug_init(struct platform_device *pdev) {}

__attribute__((used)) static void bcm_kona_wdt_debug_exit(struct platform_device *pdev) {}

__attribute__((used)) static int bcm_kona_wdt_ctrl_reg_modify(struct bcm_kona_wdt *wdt,
					unsigned mask, unsigned newval)
{
	int val;
	unsigned long flags;
	int ret = 0;

	spin_lock_irqsave(&wdt->lock, flags);

	val = secure_register_read(wdt, SECWDOG_CTRL_REG);
	if (val < 0) {
		ret = val;
	} else {
		val &= ~mask;
		val |= newval;
		writel_relaxed(val, wdt->base + SECWDOG_CTRL_REG);
	}

	spin_unlock_irqrestore(&wdt->lock, flags);

	return ret;
}

__attribute__((used)) static int bcm_kona_wdt_set_resolution_reg(struct bcm_kona_wdt *wdt)
{
	if (wdt->resolution > SECWDOG_MAX_RES)
		return -EINVAL;

	return bcm_kona_wdt_ctrl_reg_modify(wdt, SECWDOG_RES_MASK,
					wdt->resolution << SECWDOG_CLKS_SHIFT);
}

__attribute__((used)) static int bcm_kona_wdt_set_timeout_reg(struct watchdog_device *wdog,
					unsigned watchdog_flags)
{
	struct bcm_kona_wdt *wdt = watchdog_get_drvdata(wdog);

	return bcm_kona_wdt_ctrl_reg_modify(wdt, SECWDOG_COUNT_MASK,
					SECS_TO_TICKS(wdog->timeout, wdt) |
					watchdog_flags);
}

__attribute__((used)) static int bcm_kona_wdt_set_timeout(struct watchdog_device *wdog,
	unsigned int t)
{
	wdog->timeout = t;
	return 0;
}

__attribute__((used)) static unsigned int bcm_kona_wdt_get_timeleft(struct watchdog_device *wdog)
{
	struct bcm_kona_wdt *wdt = watchdog_get_drvdata(wdog);
	int val;
	unsigned long flags;

	spin_lock_irqsave(&wdt->lock, flags);
	val = secure_register_read(wdt, SECWDOG_COUNT_REG);
	spin_unlock_irqrestore(&wdt->lock, flags);

	if (val < 0)
		return val;

	return TICKS_TO_SECS(val & SECWDOG_COUNT_MASK, wdt);
}

__attribute__((used)) static int bcm_kona_wdt_start(struct watchdog_device *wdog)
{
	return bcm_kona_wdt_set_timeout_reg(wdog,
					SECWDOG_EN_MASK | SECWDOG_SRSTEN_MASK);
}

__attribute__((used)) static int bcm_kona_wdt_stop(struct watchdog_device *wdog)
{
	struct bcm_kona_wdt *wdt = watchdog_get_drvdata(wdog);

	return bcm_kona_wdt_ctrl_reg_modify(wdt, SECWDOG_EN_MASK |
					    SECWDOG_SRSTEN_MASK, 0);
}

__attribute__((used)) static void bcm_kona_wdt_shutdown(struct platform_device *pdev)
{
	bcm_kona_wdt_stop(&bcm_kona_wdt_wdd);
}

__attribute__((used)) static int bcm_kona_wdt_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct bcm_kona_wdt *wdt;
	struct resource *res;
	int ret;

	wdt = devm_kzalloc(dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	spin_lock_init(&wdt->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	wdt->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(wdt->base))
		return -ENODEV;

	wdt->resolution = SECWDOG_DEFAULT_RESOLUTION;
	ret = bcm_kona_wdt_set_resolution_reg(wdt);
	if (ret) {
		dev_err(dev, "Failed to set resolution (error: %d)", ret);
		return ret;
	}

	platform_set_drvdata(pdev, wdt);
	watchdog_set_drvdata(&bcm_kona_wdt_wdd, wdt);
	bcm_kona_wdt_wdd.parent = &pdev->dev;

	ret = bcm_kona_wdt_set_timeout_reg(&bcm_kona_wdt_wdd, 0);
	if (ret) {
		dev_err(dev, "Failed set watchdog timeout");
		return ret;
	}

	ret = watchdog_register_device(&bcm_kona_wdt_wdd);
	if (ret) {
		dev_err(dev, "Failed to register watchdog device");
		return ret;
	}

	bcm_kona_wdt_debug_init(pdev);
	dev_dbg(dev, "Broadcom Kona Watchdog Timer");

	return 0;
}

__attribute__((used)) static int bcm_kona_wdt_remove(struct platform_device *pdev)
{
	bcm_kona_wdt_debug_exit(pdev);
	bcm_kona_wdt_shutdown(pdev);
	watchdog_unregister_device(&bcm_kona_wdt_wdd);
	dev_dbg(&pdev->dev, "Watchdog driver disabled");

	return 0;
}


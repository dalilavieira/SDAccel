#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct watchdog_device {unsigned int timeout; int /*<<< orphan*/ * parent; } ;
struct timer_list {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  expires; } ;
struct sh_wdt {TYPE_1__ timer; int /*<<< orphan*/  lock; int /*<<< orphan*/ * base; int /*<<< orphan*/ * dev; int /*<<< orphan*/ * clk; } ;
struct resource {int dummy; } ;
struct platform_device {int id; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int HZ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 unsigned int WATCHDOG_HEARTBEAT ; 
 int WTCSR_IOVF ; 
 int WTCSR_RSTS ; 
 int WTCSR_TME ; 
 int WTCSR_WT ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ *) ; 
 int clock_division_ratio ; 
 int /*<<< orphan*/  del_timer (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/ * devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct sh_wdt* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct sh_wdt* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 unsigned int heartbeat ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ next_heartbeat ; 
 int /*<<< orphan*/  next_ping_period (int) ; 
 int /*<<< orphan*/  nowayout ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (int /*<<< orphan*/ *) ; 
 struct watchdog_device sh_wdt_dev ; 
 int sh_wdt_read_csr () ; 
 int /*<<< orphan*/  sh_wdt_write_cnt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sh_wdt_write_csr (int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ time_before (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (TYPE_1__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 struct sh_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct sh_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 struct sh_wdt* wdt ; 

__attribute__((used)) static int sh_wdt_start(struct watchdog_device *wdt_dev)
{
	struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	unsigned long flags;
	u8 csr;

	pm_runtime_get_sync(wdt->dev);
	clk_enable(wdt->clk);

	spin_lock_irqsave(&wdt->lock, flags);

	next_heartbeat = jiffies + (heartbeat * HZ);
	mod_timer(&wdt->timer, next_ping_period(clock_division_ratio));

	csr = sh_wdt_read_csr();
	csr |= WTCSR_WT | clock_division_ratio;
	sh_wdt_write_csr(csr);

	sh_wdt_write_cnt(0);

	/*
	 * These processors have a bit of an inconsistent initialization
	 * process.. starting with SH-3, RSTS was moved to WTCSR, and the
	 * RSTCSR register was removed.
	 *
	 * On the SH-2 however, in addition with bits being in different
	 * locations, we must deal with RSTCSR outright..
	 */
	csr = sh_wdt_read_csr();
	csr |= WTCSR_TME;
	csr &= ~WTCSR_RSTS;
	sh_wdt_write_csr(csr);

#ifdef CONFIG_CPU_SH2
	csr = sh_wdt_read_rstcsr();
	csr &= ~RSTCSR_RSTS;
	sh_wdt_write_rstcsr(csr);
#endif
	spin_unlock_irqrestore(&wdt->lock, flags);

	return 0;
}

__attribute__((used)) static int sh_wdt_stop(struct watchdog_device *wdt_dev)
{
	struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	unsigned long flags;
	u8 csr;

	spin_lock_irqsave(&wdt->lock, flags);

	del_timer(&wdt->timer);

	csr = sh_wdt_read_csr();
	csr &= ~WTCSR_TME;
	sh_wdt_write_csr(csr);

	spin_unlock_irqrestore(&wdt->lock, flags);

	clk_disable(wdt->clk);
	pm_runtime_put_sync(wdt->dev);

	return 0;
}

__attribute__((used)) static int sh_wdt_keepalive(struct watchdog_device *wdt_dev)
{
	struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	unsigned long flags;

	spin_lock_irqsave(&wdt->lock, flags);
	next_heartbeat = jiffies + (heartbeat * HZ);
	spin_unlock_irqrestore(&wdt->lock, flags);

	return 0;
}

__attribute__((used)) static int sh_wdt_set_heartbeat(struct watchdog_device *wdt_dev, unsigned t)
{
	struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	unsigned long flags;

	if (unlikely(t < 1 || t > 3600)) /* arbitrary upper limit */
		return -EINVAL;

	spin_lock_irqsave(&wdt->lock, flags);
	heartbeat = t;
	wdt_dev->timeout = t;
	spin_unlock_irqrestore(&wdt->lock, flags);

	return 0;
}

__attribute__((used)) static void sh_wdt_ping(struct timer_list *t)
{
	struct sh_wdt *wdt = from_timer(wdt, t, timer);
	unsigned long flags;

	spin_lock_irqsave(&wdt->lock, flags);
	if (time_before(jiffies, next_heartbeat)) {
		u8 csr;

		csr = sh_wdt_read_csr();
		csr &= ~WTCSR_IOVF;
		sh_wdt_write_csr(csr);

		sh_wdt_write_cnt(0);

		mod_timer(&wdt->timer, next_ping_period(clock_division_ratio));
	} else
		dev_warn(wdt->dev, "Heartbeat lost! Will not ping "
		         "the watchdog\n");
	spin_unlock_irqrestore(&wdt->lock, flags);
}

__attribute__((used)) static int sh_wdt_probe(struct platform_device *pdev)
{
	struct sh_wdt *wdt;
	struct resource *res;
	int rc;

	/*
	 * As this driver only covers the global watchdog case, reject
	 * any attempts to register per-CPU watchdogs.
	 */
	if (pdev->id != -1)
		return -EINVAL;

	wdt = devm_kzalloc(&pdev->dev, sizeof(struct sh_wdt), GFP_KERNEL);
	if (unlikely(!wdt))
		return -ENOMEM;

	wdt->dev = &pdev->dev;

	wdt->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(wdt->clk)) {
		/*
		 * Clock framework support is optional, continue on
		 * anyways if we don't find a matching clock.
		 */
		wdt->clk = NULL;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	wdt->base = devm_ioremap_resource(wdt->dev, res);
	if (IS_ERR(wdt->base))
		return PTR_ERR(wdt->base);

	watchdog_set_nowayout(&sh_wdt_dev, nowayout);
	watchdog_set_drvdata(&sh_wdt_dev, wdt);
	sh_wdt_dev.parent = &pdev->dev;

	spin_lock_init(&wdt->lock);

	rc = sh_wdt_set_heartbeat(&sh_wdt_dev, heartbeat);
	if (unlikely(rc)) {
		/* Default timeout if invalid */
		sh_wdt_set_heartbeat(&sh_wdt_dev, WATCHDOG_HEARTBEAT);

		dev_warn(&pdev->dev,
			 "heartbeat value must be 1<=x<=3600, using %d\n",
			 sh_wdt_dev.timeout);
	}

	dev_info(&pdev->dev, "configured with heartbeat=%d sec (nowayout=%d)\n",
		 sh_wdt_dev.timeout, nowayout);

	rc = watchdog_register_device(&sh_wdt_dev);
	if (unlikely(rc)) {
		dev_err(&pdev->dev, "Can't register watchdog (err=%d)\n", rc);
		return rc;
	}

	timer_setup(&wdt->timer, sh_wdt_ping, 0);
	wdt->timer.expires	= next_ping_period(clock_division_ratio);

	dev_info(&pdev->dev, "initialized.\n");

	pm_runtime_enable(&pdev->dev);

	return 0;
}

__attribute__((used)) static int sh_wdt_remove(struct platform_device *pdev)
{
	watchdog_unregister_device(&sh_wdt_dev);

	pm_runtime_disable(&pdev->dev);

	return 0;
}

__attribute__((used)) static void sh_wdt_shutdown(struct platform_device *pdev)
{
	sh_wdt_stop(&sh_wdt_dev);
}


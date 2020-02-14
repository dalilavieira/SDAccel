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
struct watchdog_device {unsigned int timeout; unsigned int pretimeout; int /*<<< orphan*/  status; } ;
struct imx2_wdt_device {int /*<<< orphan*/  regmap; scalar_t__ ext_reset; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int IMX2_WDT_MAX_TIME ; 
 int IMX2_WDT_SEQ1 ; 
 int IMX2_WDT_SEQ2 ; 
 int /*<<< orphan*/  IMX2_WDT_WCR ; 
 unsigned int IMX2_WDT_WCR_SRS ; 
 unsigned int IMX2_WDT_WCR_WDA ; 
 int IMX2_WDT_WCR_WDE ; 
 int IMX2_WDT_WCR_WDZST ; 
 int IMX2_WDT_WCR_WRE ; 
 int IMX2_WDT_WCR_WT ; 
 int /*<<< orphan*/  IMX2_WDT_WICR ; 
 unsigned int IMX2_WDT_WICR_WICT ; 
 unsigned int IMX2_WDT_WICR_WIE ; 
 int /*<<< orphan*/  IMX2_WDT_WICR_WTIS ; 
 int /*<<< orphan*/  IMX2_WDT_WSR ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  WDOG_HW_RUNNING ; 
 unsigned int WDOG_SEC_TO_COUNT (unsigned int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  regmap_write_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct imx2_wdt_device* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_notify_pretimeout (struct watchdog_device*) ; 

__attribute__((used)) static int imx2_wdt_restart(struct watchdog_device *wdog, unsigned long action,
			    void *data)
{
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
	unsigned int wcr_enable = IMX2_WDT_WCR_WDE;

	/* Use internal reset or external - not both */
	if (wdev->ext_reset)
		wcr_enable |= IMX2_WDT_WCR_SRS; /* do not assert int reset */
	else
		wcr_enable |= IMX2_WDT_WCR_WDA; /* do not assert ext-reset */

	/* Assert SRS signal */
	regmap_write(wdev->regmap, IMX2_WDT_WCR, wcr_enable);
	/*
	 * Due to imx6q errata ERR004346 (WDOG: WDOG SRS bit requires to be
	 * written twice), we add another two writes to ensure there must be at
	 * least two writes happen in the same one 32kHz clock period.  We save
	 * the target check here, since the writes shouldn't be a huge burden
	 * for other platforms.
	 */
	regmap_write(wdev->regmap, IMX2_WDT_WCR, wcr_enable);
	regmap_write(wdev->regmap, IMX2_WDT_WCR, wcr_enable);

	/* wait for reset to assert... */
	mdelay(500);

	return 0;
}

__attribute__((used)) static inline void imx2_wdt_setup(struct watchdog_device *wdog)
{
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
	u32 val;

	regmap_read(wdev->regmap, IMX2_WDT_WCR, &val);

	/* Suspend timer in low power mode, write once-only */
	val |= IMX2_WDT_WCR_WDZST;
	/* Strip the old watchdog Time-Out value */
	val &= ~IMX2_WDT_WCR_WT;
	/* Generate internal chip-level reset if WDOG times out */
	if (!wdev->ext_reset)
		val &= ~IMX2_WDT_WCR_WRE;
	/* Or if external-reset assert WDOG_B reset only on time-out */
	else
		val |= IMX2_WDT_WCR_WRE;
	/* Keep Watchdog Disabled */
	val &= ~IMX2_WDT_WCR_WDE;
	/* Set the watchdog's Time-Out value */
	val |= WDOG_SEC_TO_COUNT(wdog->timeout);

	regmap_write(wdev->regmap, IMX2_WDT_WCR, val);

	/* enable the watchdog */
	val |= IMX2_WDT_WCR_WDE;
	regmap_write(wdev->regmap, IMX2_WDT_WCR, val);
}

__attribute__((used)) static inline bool imx2_wdt_is_running(struct imx2_wdt_device *wdev)
{
	u32 val;

	regmap_read(wdev->regmap, IMX2_WDT_WCR, &val);

	return val & IMX2_WDT_WCR_WDE;
}

__attribute__((used)) static int imx2_wdt_ping(struct watchdog_device *wdog)
{
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);

	regmap_write(wdev->regmap, IMX2_WDT_WSR, IMX2_WDT_SEQ1);
	regmap_write(wdev->regmap, IMX2_WDT_WSR, IMX2_WDT_SEQ2);
	return 0;
}

__attribute__((used)) static void __imx2_wdt_set_timeout(struct watchdog_device *wdog,
				   unsigned int new_timeout)
{
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);

	regmap_update_bits(wdev->regmap, IMX2_WDT_WCR, IMX2_WDT_WCR_WT,
			   WDOG_SEC_TO_COUNT(new_timeout));
}

__attribute__((used)) static int imx2_wdt_set_timeout(struct watchdog_device *wdog,
				unsigned int new_timeout)
{
	__imx2_wdt_set_timeout(wdog, new_timeout);

	wdog->timeout = new_timeout;
	return 0;
}

__attribute__((used)) static int imx2_wdt_set_pretimeout(struct watchdog_device *wdog,
				   unsigned int new_pretimeout)
{
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);

	if (new_pretimeout >= IMX2_WDT_MAX_TIME)
		return -EINVAL;

	wdog->pretimeout = new_pretimeout;

	regmap_update_bits(wdev->regmap, IMX2_WDT_WICR,
			   IMX2_WDT_WICR_WIE | IMX2_WDT_WICR_WICT,
			   IMX2_WDT_WICR_WIE | (new_pretimeout << 1));
	return 0;
}

__attribute__((used)) static irqreturn_t imx2_wdt_isr(int irq, void *wdog_arg)
{
	struct watchdog_device *wdog = wdog_arg;
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);

	regmap_write_bits(wdev->regmap, IMX2_WDT_WICR,
			  IMX2_WDT_WICR_WTIS, IMX2_WDT_WICR_WTIS);

	watchdog_notify_pretimeout(wdog);

	return IRQ_HANDLED;
}

__attribute__((used)) static int imx2_wdt_start(struct watchdog_device *wdog)
{
	struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);

	if (imx2_wdt_is_running(wdev))
		imx2_wdt_set_timeout(wdog, wdog->timeout);
	else
		imx2_wdt_setup(wdog);

	set_bit(WDOG_HW_RUNNING, &wdog->status);

	return imx2_wdt_ping(wdog);
}


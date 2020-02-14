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
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_yday; int tm_mon; int tm_year; } ;
struct rtc_wkalrm {int enabled; int pending; struct rtc_time time; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct lpc24xx_rtc {void* clk_reg; void* clk_rtc; void* rtc; void* rtc_base; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int CT0_DOW (int) ; 
 int CT0_HOURS (int) ; 
 int CT0_MINS (int) ; 
 int CT0_SECS (int) ; 
 int CT1_DOM (int) ; 
 int CT1_MONTH (int) ; 
 int CT1_YEAR (int) ; 
 int CT2_DOY (int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (void*) ; 
 int LPC178X_CCALEN ; 
 int LPC24XX_ALARM_DISABLE ; 
 int /*<<< orphan*/  LPC24XX_ALDOM ; 
 int /*<<< orphan*/  LPC24XX_ALDOW ; 
 int /*<<< orphan*/  LPC24XX_ALDOY ; 
 int /*<<< orphan*/  LPC24XX_ALHOUR ; 
 int /*<<< orphan*/  LPC24XX_ALMIN ; 
 int /*<<< orphan*/  LPC24XX_ALMON ; 
 int /*<<< orphan*/  LPC24XX_ALSEC ; 
 int /*<<< orphan*/  LPC24XX_ALYEAR ; 
 int /*<<< orphan*/  LPC24XX_AMR ; 
 int /*<<< orphan*/  LPC24XX_CCR ; 
 int /*<<< orphan*/  LPC24XX_CIIR ; 
 int LPC24XX_CLKEN ; 
 int /*<<< orphan*/  LPC24XX_CTIME0 ; 
 int /*<<< orphan*/  LPC24XX_CTIME1 ; 
 int /*<<< orphan*/  LPC24XX_CTIME2 ; 
 int /*<<< orphan*/  LPC24XX_DOM ; 
 int /*<<< orphan*/  LPC24XX_DOW ; 
 int /*<<< orphan*/  LPC24XX_DOY ; 
 int /*<<< orphan*/  LPC24XX_HOUR ; 
 int /*<<< orphan*/  LPC24XX_ILR ; 
 int /*<<< orphan*/  LPC24XX_MIN ; 
 int /*<<< orphan*/  LPC24XX_MONTH ; 
 int LPC24XX_RTCALF ; 
 int LPC24XX_RTCCIF ; 
 int /*<<< orphan*/  LPC24XX_SEC ; 
 int /*<<< orphan*/  LPC24XX_YEAR ; 
 int PTR_ERR (void*) ; 
 unsigned long RTC_AF ; 
 unsigned long RTC_IRQF ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct lpc24xx_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 void* devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 void* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct lpc24xx_rtc* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct lpc24xx_rtc*) ; 
 void* devm_rtc_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lpc24xx_rtc_ops ; 
 struct lpc24xx_rtc* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lpc24xx_rtc*) ; 
 int rtc_readl (struct lpc24xx_rtc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_update_irq (void*,int,unsigned long) ; 
 int rtc_valid_tm (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_writel (struct lpc24xx_rtc*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int lpc24xx_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);

	/* Disable RTC during update */
	rtc_writel(rtc, LPC24XX_CCR, LPC178X_CCALEN);

	rtc_writel(rtc, LPC24XX_SEC,	tm->tm_sec);
	rtc_writel(rtc, LPC24XX_MIN,	tm->tm_min);
	rtc_writel(rtc, LPC24XX_HOUR,	tm->tm_hour);
	rtc_writel(rtc, LPC24XX_DOW,	tm->tm_wday);
	rtc_writel(rtc, LPC24XX_DOM,	tm->tm_mday);
	rtc_writel(rtc, LPC24XX_DOY,	tm->tm_yday);
	rtc_writel(rtc, LPC24XX_MONTH,	tm->tm_mon);
	rtc_writel(rtc, LPC24XX_YEAR,	tm->tm_year);

	rtc_writel(rtc, LPC24XX_CCR, LPC24XX_CLKEN | LPC178X_CCALEN);

	return 0;
}

__attribute__((used)) static int lpc24xx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
	u32 ct0, ct1, ct2;

	ct0 = rtc_readl(rtc, LPC24XX_CTIME0);
	ct1 = rtc_readl(rtc, LPC24XX_CTIME1);
	ct2 = rtc_readl(rtc, LPC24XX_CTIME2);

	tm->tm_sec  = CT0_SECS(ct0);
	tm->tm_min  = CT0_MINS(ct0);
	tm->tm_hour = CT0_HOURS(ct0);
	tm->tm_wday = CT0_DOW(ct0);
	tm->tm_mon  = CT1_MONTH(ct1);
	tm->tm_mday = CT1_DOM(ct1);
	tm->tm_year = CT1_YEAR(ct1);
	tm->tm_yday = CT2_DOY(ct2);

	return 0;
}

__attribute__((used)) static int lpc24xx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
	struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
	struct rtc_time *tm = &wkalrm->time;

	tm->tm_sec  = rtc_readl(rtc, LPC24XX_ALSEC);
	tm->tm_min  = rtc_readl(rtc, LPC24XX_ALMIN);
	tm->tm_hour = rtc_readl(rtc, LPC24XX_ALHOUR);
	tm->tm_mday = rtc_readl(rtc, LPC24XX_ALDOM);
	tm->tm_wday = rtc_readl(rtc, LPC24XX_ALDOW);
	tm->tm_yday = rtc_readl(rtc, LPC24XX_ALDOY);
	tm->tm_mon  = rtc_readl(rtc, LPC24XX_ALMON);
	tm->tm_year = rtc_readl(rtc, LPC24XX_ALYEAR);

	wkalrm->enabled = rtc_readl(rtc, LPC24XX_AMR) == 0;
	wkalrm->pending = !!(rtc_readl(rtc, LPC24XX_ILR) & LPC24XX_RTCCIF);

	return rtc_valid_tm(&wkalrm->time);
}

__attribute__((used)) static int lpc24xx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
	struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
	struct rtc_time *tm = &wkalrm->time;

	/* Disable alarm irq during update */
	rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);

	rtc_writel(rtc, LPC24XX_ALSEC,  tm->tm_sec);
	rtc_writel(rtc, LPC24XX_ALMIN,  tm->tm_min);
	rtc_writel(rtc, LPC24XX_ALHOUR, tm->tm_hour);
	rtc_writel(rtc, LPC24XX_ALDOM,  tm->tm_mday);
	rtc_writel(rtc, LPC24XX_ALDOW,  tm->tm_wday);
	rtc_writel(rtc, LPC24XX_ALDOY,  tm->tm_yday);
	rtc_writel(rtc, LPC24XX_ALMON,  tm->tm_mon);
	rtc_writel(rtc, LPC24XX_ALYEAR, tm->tm_year);

	if (wkalrm->enabled)
		rtc_writel(rtc, LPC24XX_AMR, 0);

	return 0;
}

__attribute__((used)) static int lpc24xx_rtc_alarm_irq_enable(struct device *dev, unsigned int enable)
{
	struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);

	if (enable)
		rtc_writel(rtc, LPC24XX_AMR, 0);
	else
		rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);

	return 0;
}

__attribute__((used)) static irqreturn_t lpc24xx_rtc_interrupt(int irq, void *data)
{
	unsigned long events = RTC_IRQF;
	struct lpc24xx_rtc *rtc = data;
	u32 rtc_iir;

	/* Check interrupt cause */
	rtc_iir = rtc_readl(rtc, LPC24XX_ILR);
	if (rtc_iir & LPC24XX_RTCALF) {
		events |= RTC_AF;
		rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);
	}

	/* Clear interrupt status and report event */
	rtc_writel(rtc, LPC24XX_ILR, rtc_iir);
	rtc_update_irq(rtc->rtc, 1, events);

	return IRQ_HANDLED;
}

__attribute__((used)) static int lpc24xx_rtc_probe(struct platform_device *pdev)
{
	struct lpc24xx_rtc *rtc;
	struct resource *res;
	int irq, ret;

	rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	rtc->rtc_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(rtc->rtc_base))
		return PTR_ERR(rtc->rtc_base);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_warn(&pdev->dev, "can't get interrupt resource\n");
		return irq;
	}

	rtc->clk_rtc = devm_clk_get(&pdev->dev, "rtc");
	if (IS_ERR(rtc->clk_rtc)) {
		dev_err(&pdev->dev, "error getting rtc clock\n");
		return PTR_ERR(rtc->clk_rtc);
	}

	rtc->clk_reg = devm_clk_get(&pdev->dev, "reg");
	if (IS_ERR(rtc->clk_reg)) {
		dev_err(&pdev->dev, "error getting reg clock\n");
		return PTR_ERR(rtc->clk_reg);
	}

	ret = clk_prepare_enable(rtc->clk_rtc);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable rtc clock\n");
		return ret;
	}

	ret = clk_prepare_enable(rtc->clk_reg);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable reg clock\n");
		goto disable_rtc_clk;
	}

	platform_set_drvdata(pdev, rtc);

	/* Clear any pending interrupts */
	rtc_writel(rtc, LPC24XX_ILR, LPC24XX_RTCCIF | LPC24XX_RTCALF);

	/* Enable RTC count */
	rtc_writel(rtc, LPC24XX_CCR, LPC24XX_CLKEN | LPC178X_CCALEN);

	ret = devm_request_irq(&pdev->dev, irq, lpc24xx_rtc_interrupt, 0,
			       pdev->name, rtc);
	if (ret < 0) {
		dev_warn(&pdev->dev, "can't request interrupt\n");
		goto disable_clks;
	}

	rtc->rtc = devm_rtc_device_register(&pdev->dev, "lpc24xx-rtc",
					    &lpc24xx_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc->rtc)) {
		dev_err(&pdev->dev, "can't register rtc device\n");
		ret = PTR_ERR(rtc->rtc);
		goto disable_clks;
	}

	return 0;

disable_clks:
	clk_disable_unprepare(rtc->clk_reg);
disable_rtc_clk:
	clk_disable_unprepare(rtc->clk_rtc);
	return ret;
}

__attribute__((used)) static int lpc24xx_rtc_remove(struct platform_device *pdev)
{
	struct lpc24xx_rtc *rtc = platform_get_drvdata(pdev);

	/* Ensure all interrupt sources are masked */
	rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);
	rtc_writel(rtc, LPC24XX_CIIR, 0);

	rtc_writel(rtc, LPC24XX_CCR, LPC178X_CCALEN);

	clk_disable_unprepare(rtc->clk_rtc);
	clk_disable_unprepare(rtc->clk_reg);

	return 0;
}


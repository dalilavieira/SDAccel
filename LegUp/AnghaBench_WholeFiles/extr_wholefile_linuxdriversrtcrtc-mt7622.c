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
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_wday; int tm_mday; int tm_mon; int tm_year; } ;
struct rtc_wkalrm {int enabled; int pending; struct rtc_time time; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct mtk_rtc {int base; int rtc; int irq; int clk; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int) ; 
 int MTK_AL ; 
 int /*<<< orphan*/  MTK_DOM ; 
 int /*<<< orphan*/  MTK_DOW ; 
 int /*<<< orphan*/  MTK_HOU ; 
 int /*<<< orphan*/  MTK_MIN ; 
 int /*<<< orphan*/  MTK_MON ; 
 int MTK_RTC_AL_CTL ; 
 int MTK_RTC_CTL ; 
 int MTK_RTC_DEBNCE ; 
 int MTK_RTC_INT ; 
 int MTK_RTC_KEY ; 
 int MTK_RTC_PROT1 ; 
 int MTK_RTC_PROT2 ; 
 int MTK_RTC_PROT3 ; 
 int MTK_RTC_PROT4 ; 
 int MTK_RTC_PWRCHK1 ; 
 int MTK_RTC_PWRCHK2 ; 
 int MTK_RTC_TM_YR_OFFSET ; 
 int /*<<< orphan*/  MTK_RTC_TM_YR_VALID (int) ; 
 int MTK_RTC_TREG (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MTK_SEC ; 
 int MTK_TC ; 
 int /*<<< orphan*/  MTK_YEA ; 
 int PTR_ERR (int) ; 
 int RTC_AF ; 
 int RTC_AL_ALL ; 
 int RTC_AL_EN ; 
 int RTC_DEBNCE_MASK ; 
 int RTC_INT_AL_STA ; 
 int RTC_IRQF ; 
 int RTC_KEY_MAGIC ; 
 int RTC_PROT1_MAGIC ; 
 int RTC_PROT2_MAGIC ; 
 int RTC_PROT3_MAGIC ; 
 int RTC_PROT4_MAGIC ; 
 int RTC_PWRCHK1_MAGIC ; 
 int RTC_PWRCHK2_MAGIC ; 
 int RTC_RC_STOP ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  clk_disable_unprepare (int) ; 
 int clk_prepare_enable (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct mtk_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_init_wakeup (int /*<<< orphan*/ *,int) ; 
 int devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct mtk_rtc* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct mtk_rtc*) ; 
 int devm_rtc_device_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_rtc_ops ; 
 struct mtk_rtc* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mtk_rtc*) ; 
 int readl_relaxed (int) ; 
 int /*<<< orphan*/  rtc_update_irq (int,int,int) ; 
 int /*<<< orphan*/  synchronize_irq (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,int) ; 

__attribute__((used)) static void mtk_w32(struct mtk_rtc *rtc, u32 reg, u32 val)
{
	writel_relaxed(val, rtc->base + reg);
}

__attribute__((used)) static u32 mtk_r32(struct mtk_rtc *rtc, u32 reg)
{
	return readl_relaxed(rtc->base + reg);
}

__attribute__((used)) static void mtk_rmw(struct mtk_rtc *rtc, u32 reg, u32 mask, u32 set)
{
	u32 val;

	val = mtk_r32(rtc, reg);
	val &= ~mask;
	val |= set;
	mtk_w32(rtc, reg, val);
}

__attribute__((used)) static void mtk_set(struct mtk_rtc *rtc, u32 reg, u32 val)
{
	mtk_rmw(rtc, reg, 0, val);
}

__attribute__((used)) static void mtk_clr(struct mtk_rtc *rtc, u32 reg, u32 val)
{
	mtk_rmw(rtc, reg, val, 0);
}

__attribute__((used)) static void mtk_rtc_hw_init(struct mtk_rtc *hw)
{
	/* The setup of the init sequence is for allowing RTC got to work */
	mtk_w32(hw, MTK_RTC_PWRCHK1, RTC_PWRCHK1_MAGIC);
	mtk_w32(hw, MTK_RTC_PWRCHK2, RTC_PWRCHK2_MAGIC);
	mtk_w32(hw, MTK_RTC_KEY, RTC_KEY_MAGIC);
	mtk_w32(hw, MTK_RTC_PROT1, RTC_PROT1_MAGIC);
	mtk_w32(hw, MTK_RTC_PROT2, RTC_PROT2_MAGIC);
	mtk_w32(hw, MTK_RTC_PROT3, RTC_PROT3_MAGIC);
	mtk_w32(hw, MTK_RTC_PROT4, RTC_PROT4_MAGIC);
	mtk_rmw(hw, MTK_RTC_DEBNCE, RTC_DEBNCE_MASK, 0);
	mtk_clr(hw, MTK_RTC_CTL, RTC_RC_STOP);
}

__attribute__((used)) static void mtk_rtc_get_alarm_or_time(struct mtk_rtc *hw, struct rtc_time *tm,
				      int time_alarm)
{
	u32 year, mon, mday, wday, hour, min, sec;

	/*
	 * Read again until the field of the second is not changed which
	 * ensures all fields in the consistent state. Note that MTK_SEC must
	 * be read first. In this way, it guarantees the others remain not
	 * changed when the results for two MTK_SEC consecutive reads are same.
	 */
	do {
		sec = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_SEC));
		min = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_MIN));
		hour = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_HOU));
		wday = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_DOW));
		mday = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_DOM));
		mon = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_MON));
		year = mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_YEA));
	} while (sec != mtk_r32(hw, MTK_RTC_TREG(time_alarm, MTK_SEC)));

	tm->tm_sec  = sec;
	tm->tm_min  = min;
	tm->tm_hour = hour;
	tm->tm_wday = wday;
	tm->tm_mday = mday;
	tm->tm_mon  = mon - 1;

	/* Rebase to the absolute year which userspace queries */
	tm->tm_year = year + MTK_RTC_TM_YR_OFFSET;
}

__attribute__((used)) static void mtk_rtc_set_alarm_or_time(struct mtk_rtc *hw, struct rtc_time *tm,
				      int time_alarm)
{
	u32 year;

	/* Rebase to the relative year which RTC hardware requires */
	year = tm->tm_year - MTK_RTC_TM_YR_OFFSET;

	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_YEA), year);
	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_MON), tm->tm_mon + 1);
	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_DOW), tm->tm_wday);
	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_DOM), tm->tm_mday);
	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_HOU), tm->tm_hour);
	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_MIN), tm->tm_min);
	mtk_w32(hw, MTK_RTC_TREG(time_alarm, MTK_SEC), tm->tm_sec);
}

__attribute__((used)) static irqreturn_t mtk_rtc_alarmirq(int irq, void *id)
{
	struct mtk_rtc *hw = (struct mtk_rtc *)id;
	u32 irq_sta;

	irq_sta = mtk_r32(hw, MTK_RTC_INT);
	if (irq_sta & RTC_INT_AL_STA) {
		/* Stop alarm also implicitly disables the alarm interrupt */
		mtk_w32(hw, MTK_RTC_AL_CTL, 0);
		rtc_update_irq(hw->rtc, 1, RTC_IRQF | RTC_AF);

		/* Ack alarm interrupt status */
		mtk_w32(hw, MTK_RTC_INT, RTC_INT_AL_STA);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

__attribute__((used)) static int mtk_rtc_gettime(struct device *dev, struct rtc_time *tm)
{
	struct mtk_rtc *hw = dev_get_drvdata(dev);

	mtk_rtc_get_alarm_or_time(hw, tm, MTK_TC);

	return 0;
}

__attribute__((used)) static int mtk_rtc_settime(struct device *dev, struct rtc_time *tm)
{
	struct mtk_rtc *hw = dev_get_drvdata(dev);

	if (!MTK_RTC_TM_YR_VALID(tm->tm_year))
		return -EINVAL;

	/* Stop time counter before setting a new one*/
	mtk_set(hw, MTK_RTC_CTL, RTC_RC_STOP);

	mtk_rtc_set_alarm_or_time(hw, tm, MTK_TC);

	/* Restart the time counter */
	mtk_clr(hw, MTK_RTC_CTL, RTC_RC_STOP);

	return 0;
}

__attribute__((used)) static int mtk_rtc_getalarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
	struct mtk_rtc *hw = dev_get_drvdata(dev);
	struct rtc_time *alrm_tm = &wkalrm->time;

	mtk_rtc_get_alarm_or_time(hw, alrm_tm, MTK_AL);

	wkalrm->enabled = !!(mtk_r32(hw, MTK_RTC_AL_CTL) & RTC_AL_EN);
	wkalrm->pending = !!(mtk_r32(hw, MTK_RTC_INT) & RTC_INT_AL_STA);

	return 0;
}

__attribute__((used)) static int mtk_rtc_setalarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
	struct mtk_rtc *hw = dev_get_drvdata(dev);
	struct rtc_time *alrm_tm = &wkalrm->time;

	if (!MTK_RTC_TM_YR_VALID(alrm_tm->tm_year))
		return -EINVAL;

	/*
	 * Stop the alarm also implicitly including disables interrupt before
	 * setting a new one.
	 */
	mtk_clr(hw, MTK_RTC_AL_CTL, RTC_AL_EN);

	/*
	 * Avoid contention between mtk_rtc_setalarm and IRQ handler so that
	 * disabling the interrupt and awaiting for pending IRQ handler to
	 * complete.
	 */
	synchronize_irq(hw->irq);

	mtk_rtc_set_alarm_or_time(hw, alrm_tm, MTK_AL);

	/* Restart the alarm with the new setup */
	mtk_w32(hw, MTK_RTC_AL_CTL, RTC_AL_ALL);

	return 0;
}

__attribute__((used)) static int mtk_rtc_probe(struct platform_device *pdev)
{
	struct mtk_rtc *hw;
	struct resource *res;
	int ret;

	hw = devm_kzalloc(&pdev->dev, sizeof(*hw), GFP_KERNEL);
	if (!hw)
		return -ENOMEM;

	platform_set_drvdata(pdev, hw);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hw->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(hw->base))
		return PTR_ERR(hw->base);

	hw->clk = devm_clk_get(&pdev->dev, "rtc");
	if (IS_ERR(hw->clk)) {
		dev_err(&pdev->dev, "No clock\n");
		return PTR_ERR(hw->clk);
	}

	ret = clk_prepare_enable(hw->clk);
	if (ret)
		return ret;

	hw->irq = platform_get_irq(pdev, 0);
	if (hw->irq < 0) {
		dev_err(&pdev->dev, "No IRQ resource\n");
		ret = hw->irq;
		goto err;
	}

	ret = devm_request_irq(&pdev->dev, hw->irq, mtk_rtc_alarmirq,
			       0, dev_name(&pdev->dev), hw);
	if (ret) {
		dev_err(&pdev->dev, "Can't request IRQ\n");
		goto err;
	}

	mtk_rtc_hw_init(hw);

	device_init_wakeup(&pdev->dev, true);

	hw->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
					   &mtk_rtc_ops, THIS_MODULE);
	if (IS_ERR(hw->rtc)) {
		ret = PTR_ERR(hw->rtc);
		dev_err(&pdev->dev, "Unable to register device\n");
		goto err;
	}

	return 0;
err:
	clk_disable_unprepare(hw->clk);

	return ret;
}

__attribute__((used)) static int mtk_rtc_remove(struct platform_device *pdev)
{
	struct mtk_rtc *hw = platform_get_drvdata(pdev);

	clk_disable_unprepare(hw->clk);

	return 0;
}


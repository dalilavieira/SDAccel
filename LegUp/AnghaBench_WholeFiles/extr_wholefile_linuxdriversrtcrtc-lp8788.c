#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct rtc_time {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; void* tm_year; int tm_wday; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; } ;
struct resource {int start; int end; } ;
struct device {struct device* parent; } ;
struct platform_device {struct device dev; } ;
struct lp8788_rtc {size_t alarm; int /*<<< orphan*/  rdev; struct lp8788* lp; int /*<<< orphan*/  irq; } ;
struct lp8788 {int /*<<< orphan*/  dev; TYPE_1__* pdata; struct irq_domain* irqdm; } ;
struct irq_domain {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {scalar_t__ alarm_sel; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALARM_IRQ_FLAG ; 
 int ARRAY_SIZE (int*) ; 
 scalar_t__ DEFAULT_ALARM_SEL ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ LP8788_ALARM_1 ; 
 int LP8788_ALM_EN_M ; 
 unsigned int LP8788_ALM_EN_S ; 
 int /*<<< orphan*/  LP8788_ALM_IRQ ; 
 void* LP8788_BASE_YEAR ; 
 int LP8788_INTEN_3 ; 
 int LP8788_MONTH_OFFSET ; 
 int LP8788_RTC_SEC ; 
 int LP8788_RTC_UNLOCK ; 
 int LP8788_WDAY_SET ; 
 size_t LPTIME_HOUR ; 
 int LPTIME_MAX ; 
 size_t LPTIME_MDAY ; 
 size_t LPTIME_MIN ; 
 size_t LPTIME_MON ; 
 size_t LPTIME_SEC ; 
 size_t LPTIME_WDAY ; 
 size_t LPTIME_YEAR ; 
 int MAX_WDAY_BITS ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_LATCH ; 
 int RTC_UNLOCK ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int* addr_alarm_en ; 
 int* addr_alarm_sec ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct lp8788_rtc* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct lp8788_rtc*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (struct device*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_create_mapping (struct irq_domain*,int) ; 
 int lp8788_read_multi_bytes (struct lp8788*,int,int*,int) ; 
 int /*<<< orphan*/  lp8788_rtc_ops ; 
 int lp8788_update_bits (struct lp8788*,int,int,unsigned int) ; 
 int lp8788_write_byte (struct lp8788*,int,int) ; 
 int* mask_alarm_en ; 
 struct resource* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lp8788_rtc*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int* shift_alarm_en ; 

__attribute__((used)) static int _to_tm_wday(u8 lp8788_wday)
{
	int i;

	if (lp8788_wday == 0)
		return 0;

	/* lookup defined weekday from read register value */
	for (i = 0; i < MAX_WDAY_BITS; i++) {
		if ((lp8788_wday >> i) == LP8788_WDAY_SET)
			break;
	}

	return i + 1;
}

__attribute__((used)) static inline int _to_lp8788_wday(int tm_wday)
{
	return LP8788_WDAY_SET << (tm_wday - 1);
}

__attribute__((used)) static void lp8788_rtc_unlock(struct lp8788 *lp)
{
	lp8788_write_byte(lp, LP8788_RTC_UNLOCK, RTC_UNLOCK);
	lp8788_write_byte(lp, LP8788_RTC_UNLOCK, RTC_LATCH);
}

__attribute__((used)) static int lp8788_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct lp8788_rtc *rtc = dev_get_drvdata(dev);
	struct lp8788 *lp = rtc->lp;
	u8 data[LPTIME_MAX];
	int ret;

	lp8788_rtc_unlock(lp);

	ret = lp8788_read_multi_bytes(lp, LP8788_RTC_SEC, data,	LPTIME_MAX);
	if (ret)
		return ret;

	tm->tm_sec  = data[LPTIME_SEC];
	tm->tm_min  = data[LPTIME_MIN];
	tm->tm_hour = data[LPTIME_HOUR];
	tm->tm_mday = data[LPTIME_MDAY];
	tm->tm_mon  = data[LPTIME_MON] - LP8788_MONTH_OFFSET;
	tm->tm_year = data[LPTIME_YEAR] + LP8788_BASE_YEAR - 1900;
	tm->tm_wday = _to_tm_wday(data[LPTIME_WDAY]);

	return 0;
}

__attribute__((used)) static int lp8788_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct lp8788_rtc *rtc = dev_get_drvdata(dev);
	struct lp8788 *lp = rtc->lp;
	u8 data[LPTIME_MAX - 1];
	int ret, i, year;

	year = tm->tm_year + 1900 - LP8788_BASE_YEAR;
	if (year < 0) {
		dev_err(lp->dev, "invalid year: %d\n", year);
		return -EINVAL;
	}

	/* because rtc weekday is a readonly register, do not update */
	data[LPTIME_SEC]  = tm->tm_sec;
	data[LPTIME_MIN]  = tm->tm_min;
	data[LPTIME_HOUR] = tm->tm_hour;
	data[LPTIME_MDAY] = tm->tm_mday;
	data[LPTIME_MON]  = tm->tm_mon + LP8788_MONTH_OFFSET;
	data[LPTIME_YEAR] = year;

	for (i = 0; i < ARRAY_SIZE(data); i++) {
		ret = lp8788_write_byte(lp, LP8788_RTC_SEC + i, data[i]);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int lp8788_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct lp8788_rtc *rtc = dev_get_drvdata(dev);
	struct lp8788 *lp = rtc->lp;
	struct rtc_time *tm = &alarm->time;
	u8 addr, data[LPTIME_MAX];
	int ret;

	addr = addr_alarm_sec[rtc->alarm];
	ret = lp8788_read_multi_bytes(lp, addr, data, LPTIME_MAX);
	if (ret)
		return ret;

	tm->tm_sec  = data[LPTIME_SEC];
	tm->tm_min  = data[LPTIME_MIN];
	tm->tm_hour = data[LPTIME_HOUR];
	tm->tm_mday = data[LPTIME_MDAY];
	tm->tm_mon  = data[LPTIME_MON] - LP8788_MONTH_OFFSET;
	tm->tm_year = data[LPTIME_YEAR] + LP8788_BASE_YEAR - 1900;
	tm->tm_wday = _to_tm_wday(data[LPTIME_WDAY]);
	alarm->enabled = data[LPTIME_WDAY] & LP8788_ALM_EN_M;

	return 0;
}

__attribute__((used)) static int lp8788_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct lp8788_rtc *rtc = dev_get_drvdata(dev);
	struct lp8788 *lp = rtc->lp;
	struct rtc_time *tm = &alarm->time;
	u8 addr, data[LPTIME_MAX];
	int ret, i, year;

	year = tm->tm_year + 1900 - LP8788_BASE_YEAR;
	if (year < 0) {
		dev_err(lp->dev, "invalid year: %d\n", year);
		return -EINVAL;
	}

	data[LPTIME_SEC]  = tm->tm_sec;
	data[LPTIME_MIN]  = tm->tm_min;
	data[LPTIME_HOUR] = tm->tm_hour;
	data[LPTIME_MDAY] = tm->tm_mday;
	data[LPTIME_MON]  = tm->tm_mon + LP8788_MONTH_OFFSET;
	data[LPTIME_YEAR] = year;
	data[LPTIME_WDAY] = _to_lp8788_wday(tm->tm_wday);

	for (i = 0; i < ARRAY_SIZE(data); i++) {
		addr = addr_alarm_sec[rtc->alarm] + i;
		ret = lp8788_write_byte(lp, addr, data[i]);
		if (ret)
			return ret;
	}

	alarm->enabled = 1;
	addr = addr_alarm_en[rtc->alarm];

	return lp8788_update_bits(lp, addr, LP8788_ALM_EN_M,
				alarm->enabled << LP8788_ALM_EN_S);
}

__attribute__((used)) static int lp8788_alarm_irq_enable(struct device *dev, unsigned int enable)
{
	struct lp8788_rtc *rtc = dev_get_drvdata(dev);
	struct lp8788 *lp = rtc->lp;
	u8 mask, shift;

	if (!rtc->irq)
		return -EIO;

	mask = mask_alarm_en[rtc->alarm];
	shift = shift_alarm_en[rtc->alarm];

	return lp8788_update_bits(lp, LP8788_INTEN_3, mask, enable << shift);
}

__attribute__((used)) static irqreturn_t lp8788_alarm_irq_handler(int irq, void *ptr)
{
	struct lp8788_rtc *rtc = ptr;

	rtc_update_irq(rtc->rdev, 1, ALARM_IRQ_FLAG);
	return IRQ_HANDLED;
}

__attribute__((used)) static int lp8788_alarm_irq_register(struct platform_device *pdev,
				struct lp8788_rtc *rtc)
{
	struct resource *r;
	struct lp8788 *lp = rtc->lp;
	struct irq_domain *irqdm = lp->irqdm;
	int irq;

	rtc->irq = 0;

	/* even the alarm IRQ number is not specified, rtc time should work */
	r = platform_get_resource_byname(pdev, IORESOURCE_IRQ, LP8788_ALM_IRQ);
	if (!r)
		return 0;

	if (rtc->alarm == LP8788_ALARM_1)
		irq = r->start;
	else
		irq = r->end;

	rtc->irq = irq_create_mapping(irqdm, irq);

	return devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
				lp8788_alarm_irq_handler,
				0, LP8788_ALM_IRQ, rtc);
}

__attribute__((used)) static int lp8788_rtc_probe(struct platform_device *pdev)
{
	struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
	struct lp8788_rtc *rtc;
	struct device *dev = &pdev->dev;

	rtc = devm_kzalloc(dev, sizeof(struct lp8788_rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->lp = lp;
	rtc->alarm = lp->pdata ? lp->pdata->alarm_sel : DEFAULT_ALARM_SEL;
	platform_set_drvdata(pdev, rtc);

	device_init_wakeup(dev, 1);

	rtc->rdev = devm_rtc_device_register(dev, "lp8788_rtc",
					&lp8788_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc->rdev)) {
		dev_err(dev, "can not register rtc device\n");
		return PTR_ERR(rtc->rdev);
	}

	if (lp8788_alarm_irq_register(pdev, rtc))
		dev_warn(lp->dev, "no rtc irq handler\n");

	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct rtc_time {int tm_year; int tm_mon; int tm_mday; int tm_hour; int tm_min; int tm_sec; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; } ;
struct TYPE_5__ {struct device* parent; } ;
struct platform_device {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct device {int dummy; } ;
struct da9055_rtc {int alarm_enable; struct da9055* da9055; int /*<<< orphan*/  rtc; } ;
struct da9055_pdata {scalar_t__ reset_enable; } ;
struct da9055 {int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int DA9055_CRYSTAL_EN ; 
 int /*<<< orphan*/  DA9055_REG_ALARM_H ; 
 int /*<<< orphan*/  DA9055_REG_ALARM_MI ; 
 int /*<<< orphan*/  DA9055_REG_ALARM_MO ; 
 int /*<<< orphan*/  DA9055_REG_ALARM_Y ; 
 int /*<<< orphan*/  DA9055_REG_CONTROL_B ; 
 int /*<<< orphan*/  DA9055_REG_COUNT_S ; 
 int /*<<< orphan*/  DA9055_REG_EN_32K ; 
 int DA9055_RTC_ALM_DAY ; 
 int DA9055_RTC_ALM_EN ; 
 int DA9055_RTC_ALM_HOUR ; 
 int DA9055_RTC_ALM_MIN ; 
 int DA9055_RTC_ALM_MONTH ; 
 int DA9055_RTC_ALM_YEAR ; 
 int DA9055_RTC_DAY ; 
 int DA9055_RTC_EN ; 
 int DA9055_RTC_HOUR ; 
 int DA9055_RTC_MIN ; 
 int DA9055_RTC_MODE_PD ; 
 int DA9055_RTC_MODE_SD ; 
 int DA9055_RTC_MODE_SD_SHIFT ; 
 int DA9055_RTC_MONTH ; 
 int DA9055_RTC_READ ; 
 int DA9055_RTC_SEC ; 
 int DA9055_RTC_TICK_WAKE_MASK ; 
 int DA9055_RTC_YEAR ; 
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int da9055_group_read (struct da9055*,int /*<<< orphan*/ ,int,int*) ; 
 int da9055_group_write (struct da9055*,int /*<<< orphan*/ ,int,int*) ; 
 int da9055_reg_read (struct da9055*,int /*<<< orphan*/ ) ; 
 int da9055_reg_update (struct da9055*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  da9055_rtc_ops ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 void* dev_get_drvdata (struct device*) ; 
 struct da9055_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_1__*,int) ; 
 struct da9055_rtc* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct da9055_rtc*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int platform_get_irq_byname (struct platform_device*,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da9055_rtc*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int rtc_valid_tm (struct rtc_time*) ; 

__attribute__((used)) static int da9055_rtc_enable_alarm(struct da9055_rtc *rtc, bool enable)
{
	int ret;
	if (enable) {
		ret = da9055_reg_update(rtc->da9055, DA9055_REG_ALARM_Y,
					DA9055_RTC_ALM_EN,
					DA9055_RTC_ALM_EN);
		if (ret != 0)
			dev_err(rtc->da9055->dev, "Failed to enable ALM: %d\n",
				ret);
		rtc->alarm_enable = 1;
	} else {
		ret = da9055_reg_update(rtc->da9055, DA9055_REG_ALARM_Y,
					DA9055_RTC_ALM_EN, 0);
		if (ret != 0)
			dev_err(rtc->da9055->dev,
				"Failed to disable ALM: %d\n", ret);
		rtc->alarm_enable = 0;
	}
	return ret;
}

__attribute__((used)) static irqreturn_t da9055_rtc_alm_irq(int irq, void *data)
{
	struct da9055_rtc *rtc = data;

	da9055_rtc_enable_alarm(rtc, 0);
	rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);

	return IRQ_HANDLED;
}

__attribute__((used)) static int da9055_read_alarm(struct da9055 *da9055, struct rtc_time *rtc_tm)
{
	int ret;
	uint8_t v[5];

	ret = da9055_group_read(da9055, DA9055_REG_ALARM_MI, 5, v);
	if (ret != 0) {
		dev_err(da9055->dev, "Failed to group read ALM: %d\n", ret);
		return ret;
	}

	rtc_tm->tm_year = (v[4] & DA9055_RTC_ALM_YEAR) + 100;
	rtc_tm->tm_mon  = (v[3] & DA9055_RTC_ALM_MONTH) - 1;
	rtc_tm->tm_mday = v[2] & DA9055_RTC_ALM_DAY;
	rtc_tm->tm_hour = v[1] & DA9055_RTC_ALM_HOUR;
	rtc_tm->tm_min  = v[0] & DA9055_RTC_ALM_MIN;
	rtc_tm->tm_sec = 0;

	return rtc_valid_tm(rtc_tm);
}

__attribute__((used)) static int da9055_set_alarm(struct da9055 *da9055, struct rtc_time *rtc_tm)
{
	int ret;
	uint8_t v[2];

	rtc_tm->tm_year -= 100;
	rtc_tm->tm_mon += 1;

	ret = da9055_reg_update(da9055, DA9055_REG_ALARM_MI,
				DA9055_RTC_ALM_MIN, rtc_tm->tm_min);
	if (ret != 0) {
		dev_err(da9055->dev, "Failed to write ALRM MIN: %d\n", ret);
		return ret;
	}

	v[0] = rtc_tm->tm_hour;
	v[1] = rtc_tm->tm_mday;

	ret = da9055_group_write(da9055, DA9055_REG_ALARM_H, 2, v);
	if (ret < 0)
		return ret;

	ret = da9055_reg_update(da9055, DA9055_REG_ALARM_MO,
				DA9055_RTC_ALM_MONTH, rtc_tm->tm_mon);
	if (ret < 0)
		dev_err(da9055->dev, "Failed to write ALM Month:%d\n", ret);

	ret = da9055_reg_update(da9055, DA9055_REG_ALARM_Y,
				DA9055_RTC_ALM_YEAR, rtc_tm->tm_year);
	if (ret < 0)
		dev_err(da9055->dev, "Failed to write ALM Year:%d\n", ret);

	return ret;
}

__attribute__((used)) static int da9055_rtc_get_alarm_status(struct da9055 *da9055)
{
	int ret;

	ret = da9055_reg_read(da9055, DA9055_REG_ALARM_Y);
	if (ret < 0) {
		dev_err(da9055->dev, "Failed to read ALM: %d\n", ret);
		return ret;
	}
	ret &= DA9055_RTC_ALM_EN;
	return (ret > 0) ? 1 : 0;
}

__attribute__((used)) static int da9055_rtc_read_time(struct device *dev, struct rtc_time *rtc_tm)
{
	struct da9055_rtc *rtc = dev_get_drvdata(dev);
	uint8_t v[6];
	int ret;

	ret = da9055_reg_read(rtc->da9055, DA9055_REG_COUNT_S);
	if (ret < 0)
		return ret;

	/*
	 * Registers are only valid when RTC_READ
	 * status bit is asserted
	 */
	if (!(ret & DA9055_RTC_READ))
		return -EBUSY;

	ret = da9055_group_read(rtc->da9055, DA9055_REG_COUNT_S, 6, v);
	if (ret < 0) {
		dev_err(rtc->da9055->dev, "Failed to read RTC time : %d\n",
			ret);
		return ret;
	}

	rtc_tm->tm_year = (v[5] & DA9055_RTC_YEAR) + 100;
	rtc_tm->tm_mon  = (v[4] & DA9055_RTC_MONTH) - 1;
	rtc_tm->tm_mday = v[3] & DA9055_RTC_DAY;
	rtc_tm->tm_hour = v[2] & DA9055_RTC_HOUR;
	rtc_tm->tm_min  = v[1] & DA9055_RTC_MIN;
	rtc_tm->tm_sec  = v[0] & DA9055_RTC_SEC;

	return 0;
}

__attribute__((used)) static int da9055_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct da9055_rtc *rtc;
	uint8_t v[6];

	rtc = dev_get_drvdata(dev);

	v[0] = tm->tm_sec;
	v[1] = tm->tm_min;
	v[2] = tm->tm_hour;
	v[3] = tm->tm_mday;
	v[4] = tm->tm_mon + 1;
	v[5] = tm->tm_year - 100;

	return da9055_group_write(rtc->da9055, DA9055_REG_COUNT_S, 6, v);
}

__attribute__((used)) static int da9055_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	int ret;
	struct rtc_time *tm = &alrm->time;
	struct da9055_rtc *rtc = dev_get_drvdata(dev);

	ret = da9055_read_alarm(rtc->da9055, tm);

	if (ret)
		return ret;

	alrm->enabled = da9055_rtc_get_alarm_status(rtc->da9055);

	return 0;
}

__attribute__((used)) static int da9055_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	int ret;
	struct rtc_time *tm = &alrm->time;
	struct da9055_rtc *rtc = dev_get_drvdata(dev);

	ret = da9055_rtc_enable_alarm(rtc, 0);
	if (ret < 0)
		return ret;

	ret = da9055_set_alarm(rtc->da9055, tm);
	if (ret)
		return ret;

	ret = da9055_rtc_enable_alarm(rtc, 1);

	return ret;
}

__attribute__((used)) static int da9055_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct da9055_rtc *rtc = dev_get_drvdata(dev);

	return da9055_rtc_enable_alarm(rtc, enabled);
}

__attribute__((used)) static int da9055_rtc_device_init(struct da9055 *da9055,
					struct da9055_pdata *pdata)
{
	int ret;

	/* Enable RTC and the internal Crystal */
	ret = da9055_reg_update(da9055, DA9055_REG_CONTROL_B,
				DA9055_RTC_EN, DA9055_RTC_EN);
	if (ret < 0)
		return ret;
	ret = da9055_reg_update(da9055, DA9055_REG_EN_32K,
				DA9055_CRYSTAL_EN, DA9055_CRYSTAL_EN);
	if (ret < 0)
		return ret;

	/* Enable RTC in Power Down mode */
	ret = da9055_reg_update(da9055, DA9055_REG_CONTROL_B,
				DA9055_RTC_MODE_PD, DA9055_RTC_MODE_PD);
	if (ret < 0)
		return ret;

	/* Enable RTC in Reset mode */
	if (pdata && pdata->reset_enable) {
		ret = da9055_reg_update(da9055, DA9055_REG_CONTROL_B,
					DA9055_RTC_MODE_SD,
					DA9055_RTC_MODE_SD <<
					DA9055_RTC_MODE_SD_SHIFT);
		if (ret < 0)
			return ret;
	}

	/* Disable the RTC TICK ALM */
	ret = da9055_reg_update(da9055, DA9055_REG_ALARM_MO,
				DA9055_RTC_TICK_WAKE_MASK, 0);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int da9055_rtc_probe(struct platform_device *pdev)
{
	struct da9055_rtc *rtc;
	struct da9055_pdata *pdata = NULL;
	int ret, alm_irq;

	rtc = devm_kzalloc(&pdev->dev, sizeof(struct da9055_rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->da9055 = dev_get_drvdata(pdev->dev.parent);
	pdata = dev_get_platdata(rtc->da9055->dev);
	platform_set_drvdata(pdev, rtc);

	ret = da9055_rtc_device_init(rtc->da9055, pdata);
	if (ret < 0)
		goto err_rtc;

	ret = da9055_reg_read(rtc->da9055, DA9055_REG_ALARM_Y);
	if (ret < 0)
		goto err_rtc;

	if (ret & DA9055_RTC_ALM_EN)
		rtc->alarm_enable = 1;

	device_init_wakeup(&pdev->dev, 1);

	rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
					&da9055_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc->rtc)) {
		ret = PTR_ERR(rtc->rtc);
		goto err_rtc;
	}

	alm_irq = platform_get_irq_byname(pdev, "ALM");
	if (alm_irq < 0)
		return alm_irq;

	ret = devm_request_threaded_irq(&pdev->dev, alm_irq, NULL,
					da9055_rtc_alm_irq,
					IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
					"ALM", rtc);
	if (ret != 0)
		dev_err(rtc->da9055->dev, "irq registration failed: %d\n", ret);

err_rtc:
	return ret;

}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
typedef  int /*<<< orphan*/  time1 ;
struct wm831x_rtc {int alarm_enabled; int /*<<< orphan*/  rtc; struct wm831x* wm831x; } ;
struct wm831x {int /*<<< orphan*/  dev; } ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; } ;
struct TYPE_6__ {struct device* parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int WM831X_GET_TIME_RETRIES ; 
 int /*<<< orphan*/  WM831X_RTC_ALARM_1 ; 
 int /*<<< orphan*/  WM831X_RTC_ALARM_2 ; 
 int WM831X_RTC_ALM_ENA ; 
 int /*<<< orphan*/  WM831X_RTC_CONTROL ; 
 int WM831X_RTC_SYNC_BUSY ; 
 int /*<<< orphan*/  WM831X_RTC_TIME_1 ; 
 int /*<<< orphan*/  WM831X_RTC_TIME_2 ; 
 int WM831X_RTC_VALID ; 
 int /*<<< orphan*/  WM831X_RTC_WRITE_COUNTER ; 
 int WM831X_SET_TIME_RETRIES ; 
 int /*<<< orphan*/  add_device_randomness (int*,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_1__*,int) ; 
 struct wm831x_rtc* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct wm831x_rtc*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (TYPE_1__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (int*,int*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  platform_get_irq_byname (struct platform_device*,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm831x_rtc*) ; 
 int /*<<< orphan*/  rtc_time_to_tm (int,struct rtc_time*) ; 
 int rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int wm831x_bulk_read (struct wm831x*,int /*<<< orphan*/ ,int,int*) ; 
 int wm831x_irq (struct wm831x*,int /*<<< orphan*/ ) ; 
 int wm831x_reg_read (struct wm831x*,int /*<<< orphan*/ ) ; 
 int wm831x_reg_write (struct wm831x*,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  wm831x_rtc_ops ; 
 int wm831x_set_bits (struct wm831x*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void wm831x_rtc_add_randomness(struct wm831x *wm831x)
{
	int ret;
	u16 reg;

	/*
	 * The write counter contains a pseudo-random number which is
	 * regenerated every time we set the RTC so it should be a
	 * useful per-system source of entropy.
	 */
	ret = wm831x_reg_read(wm831x, WM831X_RTC_WRITE_COUNTER);
	if (ret >= 0) {
		reg = ret;
		add_device_randomness(&reg, sizeof(reg));
	} else {
		dev_warn(wm831x->dev, "Failed to read RTC write counter: %d\n",
			 ret);
	}
}

__attribute__((used)) static int wm831x_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
	struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
	struct wm831x *wm831x = wm831x_rtc->wm831x;
	u16 time1[2], time2[2];
	int ret;
	int count = 0;

	/* Has the RTC been programmed? */
	ret = wm831x_reg_read(wm831x, WM831X_RTC_CONTROL);
	if (ret < 0) {
		dev_err(dev, "Failed to read RTC control: %d\n", ret);
		return ret;
	}
	if (!(ret & WM831X_RTC_VALID)) {
		dev_dbg(dev, "RTC not yet configured\n");
		return -EINVAL;
	}

	/* Read twice to make sure we don't read a corrupt, partially
	 * incremented, value.
	 */
	do {
		ret = wm831x_bulk_read(wm831x, WM831X_RTC_TIME_1,
				       2, time1);
		if (ret != 0)
			continue;

		ret = wm831x_bulk_read(wm831x, WM831X_RTC_TIME_1,
				       2, time2);
		if (ret != 0)
			continue;

		if (memcmp(time1, time2, sizeof(time1)) == 0) {
			u32 time = (time1[0] << 16) | time1[1];

			rtc_time_to_tm(time, tm);
			return 0;
		}

	} while (++count < WM831X_GET_TIME_RETRIES);

	dev_err(dev, "Timed out reading current time\n");

	return -EIO;
}

__attribute__((used)) static int wm831x_rtc_set_mmss(struct device *dev, unsigned long time)
{
	struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
	struct wm831x *wm831x = wm831x_rtc->wm831x;
	struct rtc_time new_tm;
	unsigned long new_time;
	int ret;
	int count = 0;

	ret = wm831x_reg_write(wm831x, WM831X_RTC_TIME_1,
			       (time >> 16) & 0xffff);
	if (ret < 0) {
		dev_err(dev, "Failed to write TIME_1: %d\n", ret);
		return ret;
	}

	ret = wm831x_reg_write(wm831x, WM831X_RTC_TIME_2, time & 0xffff);
	if (ret < 0) {
		dev_err(dev, "Failed to write TIME_2: %d\n", ret);
		return ret;
	}

	/* Wait for the update to complete - should happen first time
	 * round but be conservative.
	 */
	do {
		msleep(1);

		ret = wm831x_reg_read(wm831x, WM831X_RTC_CONTROL);
		if (ret < 0)
			ret = WM831X_RTC_SYNC_BUSY;
	} while (!(ret & WM831X_RTC_SYNC_BUSY) &&
		 ++count < WM831X_SET_TIME_RETRIES);

	if (ret & WM831X_RTC_SYNC_BUSY) {
		dev_err(dev, "Timed out writing RTC update\n");
		return -EIO;
	}

	/* Check that the update was accepted; security features may
	 * have caused the update to be ignored.
	 */
	ret = wm831x_rtc_readtime(dev, &new_tm);
	if (ret < 0)
		return ret;

	ret = rtc_tm_to_time(&new_tm, &new_time);
	if (ret < 0) {
		dev_err(dev, "Failed to convert time: %d\n", ret);
		return ret;
	}

	/* Allow a second of change in case of tick */
	if (new_time - time > 1) {
		dev_err(dev, "RTC update not permitted by hardware\n");
		return -EPERM;
	}

	return 0;
}

__attribute__((used)) static int wm831x_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
	int ret;
	u16 data[2];
	u32 time;

	ret = wm831x_bulk_read(wm831x_rtc->wm831x, WM831X_RTC_ALARM_1,
			       2, data);
	if (ret != 0) {
		dev_err(dev, "Failed to read alarm time: %d\n", ret);
		return ret;
	}

	time = (data[0] << 16) | data[1];

	rtc_time_to_tm(time, &alrm->time);

	ret = wm831x_reg_read(wm831x_rtc->wm831x, WM831X_RTC_CONTROL);
	if (ret < 0) {
		dev_err(dev, "Failed to read RTC control: %d\n", ret);
		return ret;
	}

	if (ret & WM831X_RTC_ALM_ENA)
		alrm->enabled = 1;
	else
		alrm->enabled = 0;

	return 0;
}

__attribute__((used)) static int wm831x_rtc_stop_alarm(struct wm831x_rtc *wm831x_rtc)
{
	wm831x_rtc->alarm_enabled = 0;

	return wm831x_set_bits(wm831x_rtc->wm831x, WM831X_RTC_CONTROL,
			       WM831X_RTC_ALM_ENA, 0);
}

__attribute__((used)) static int wm831x_rtc_start_alarm(struct wm831x_rtc *wm831x_rtc)
{
	wm831x_rtc->alarm_enabled = 1;

	return wm831x_set_bits(wm831x_rtc->wm831x, WM831X_RTC_CONTROL,
			       WM831X_RTC_ALM_ENA, WM831X_RTC_ALM_ENA);
}

__attribute__((used)) static int wm831x_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
	struct wm831x *wm831x = wm831x_rtc->wm831x;
	int ret;
	unsigned long time;

	ret = rtc_tm_to_time(&alrm->time, &time);
	if (ret < 0) {
		dev_err(dev, "Failed to convert time: %d\n", ret);
		return ret;
	}

	ret = wm831x_rtc_stop_alarm(wm831x_rtc);
	if (ret < 0) {
		dev_err(dev, "Failed to stop alarm: %d\n", ret);
		return ret;
	}

	ret = wm831x_reg_write(wm831x, WM831X_RTC_ALARM_1,
			       (time >> 16) & 0xffff);
	if (ret < 0) {
		dev_err(dev, "Failed to write ALARM_1: %d\n", ret);
		return ret;
	}

	ret = wm831x_reg_write(wm831x, WM831X_RTC_ALARM_2, time & 0xffff);
	if (ret < 0) {
		dev_err(dev, "Failed to write ALARM_2: %d\n", ret);
		return ret;
	}

	if (alrm->enabled) {
		ret = wm831x_rtc_start_alarm(wm831x_rtc);
		if (ret < 0) {
			dev_err(dev, "Failed to start alarm: %d\n", ret);
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int wm831x_rtc_alarm_irq_enable(struct device *dev,
				       unsigned int enabled)
{
	struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);

	if (enabled)
		return wm831x_rtc_start_alarm(wm831x_rtc);
	else
		return wm831x_rtc_stop_alarm(wm831x_rtc);
}

__attribute__((used)) static irqreturn_t wm831x_alm_irq(int irq, void *data)
{
	struct wm831x_rtc *wm831x_rtc = data;

	rtc_update_irq(wm831x_rtc->rtc, 1, RTC_IRQF | RTC_AF);

	return IRQ_HANDLED;
}

__attribute__((used)) static int wm831x_rtc_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_rtc *wm831x_rtc;
	int alm_irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "ALM"));
	int ret = 0;

	wm831x_rtc = devm_kzalloc(&pdev->dev, sizeof(*wm831x_rtc), GFP_KERNEL);
	if (wm831x_rtc == NULL)
		return -ENOMEM;

	platform_set_drvdata(pdev, wm831x_rtc);
	wm831x_rtc->wm831x = wm831x;

	ret = wm831x_reg_read(wm831x, WM831X_RTC_CONTROL);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to read RTC control: %d\n", ret);
		goto err;
	}
	if (ret & WM831X_RTC_ALM_ENA)
		wm831x_rtc->alarm_enabled = 1;

	device_init_wakeup(&pdev->dev, 1);

	wm831x_rtc->rtc = devm_rtc_device_register(&pdev->dev, "wm831x",
					      &wm831x_rtc_ops, THIS_MODULE);
	if (IS_ERR(wm831x_rtc->rtc)) {
		ret = PTR_ERR(wm831x_rtc->rtc);
		goto err;
	}

	ret = devm_request_threaded_irq(&pdev->dev, alm_irq, NULL,
				wm831x_alm_irq,
				IRQF_TRIGGER_RISING, "RTC alarm",
				wm831x_rtc);
	if (ret != 0) {
		dev_err(&pdev->dev, "Failed to request alarm IRQ %d: %d\n",
			alm_irq, ret);
	}

	wm831x_rtc_add_randomness(wm831x);

	return 0;

err:
	return ret;
}


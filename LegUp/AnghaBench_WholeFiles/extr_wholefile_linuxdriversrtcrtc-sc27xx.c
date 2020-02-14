#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int time64_t ;
struct sprd_rtc {int base; int valid; scalar_t__ irq; TYPE_3__* rtc; TYPE_6__* dev; int /*<<< orphan*/  regmap; } ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {int enabled; int pending; struct rtc_time time; } ;
struct TYPE_16__ {int /*<<< orphan*/  parent; struct device_node* of_node; } ;
struct platform_device {TYPE_6__ dev; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum sprd_rtc_reg_types { ____Placeholder_sprd_rtc_reg_types } sprd_rtc_reg_types ;
struct TYPE_13__ {int /*<<< orphan*/  expires; } ;
struct TYPE_14__ {scalar_t__ enabled; TYPE_1__ node; } ;
struct TYPE_15__ {long long range_max; scalar_t__ range_min; int /*<<< orphan*/ * ops; TYPE_2__ aie_timer; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_EARLY_RESUME ; 
 int IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_RETVAL (int) ; 
 scalar_t__ IS_ERR (TYPE_3__*) ; 
 int PTR_ERR (TYPE_3__*) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
#define  SPRD_RTC_ALARM 130 
 int SPRD_RTC_ALARM_EN ; 
 int SPRD_RTC_ALMLOCK_MASK ; 
 int SPRD_RTC_ALMTIME_INT_MASK ; 
 int SPRD_RTC_ALM_INT_MASK ; 
 int SPRD_RTC_ALM_LOCK ; 
 int SPRD_RTC_ALM_UNLOCK ; 
 int SPRD_RTC_AUXALM_EN ; 
#define  SPRD_RTC_AUX_ALARM 129 
 int SPRD_RTC_DAY_ALM_UPD ; 
 int SPRD_RTC_DAY_ALM_VALUE ; 
 int SPRD_RTC_DAY_AUXALM_UPD ; 
 int SPRD_RTC_DAY_CNT_UPD ; 
 int SPRD_RTC_DAY_CNT_VALUE ; 
 int SPRD_RTC_DAY_MASK ; 
 int SPRD_RTC_HOUR_ALM_UPD ; 
 int SPRD_RTC_HOUR_ALM_VALUE ; 
 int SPRD_RTC_HOUR_AUXALM_UPD ; 
 int SPRD_RTC_HOUR_CNT_UPD ; 
 int SPRD_RTC_HOUR_CNT_VALUE ; 
 int SPRD_RTC_HOUR_MASK ; 
 int SPRD_RTC_INT_CLR ; 
 int SPRD_RTC_INT_EN ; 
 int SPRD_RTC_INT_MASK ; 
 int SPRD_RTC_INT_RAW_STS ; 
 int SPRD_RTC_MIN_ALM_UPD ; 
 int SPRD_RTC_MIN_ALM_VALUE ; 
 int SPRD_RTC_MIN_AUXALM_UPD ; 
 int SPRD_RTC_MIN_CNT_UPD ; 
 int SPRD_RTC_MIN_CNT_VALUE ; 
 int SPRD_RTC_MIN_MASK ; 
 int /*<<< orphan*/  SPRD_RTC_POLL_DELAY_US ; 
 int /*<<< orphan*/  SPRD_RTC_POLL_TIMEOUT ; 
 int SPRD_RTC_POWEROFF_ALM_FLAG ; 
 int SPRD_RTC_POWER_RESET_VALUE ; 
 int SPRD_RTC_POWER_STS_CLEAR ; 
 int SPRD_RTC_POWER_STS_VALID ; 
 int SPRD_RTC_PWR_CTRL ; 
 int SPRD_RTC_PWR_STS ; 
 int SPRD_RTC_SEC_ALM_UPD ; 
 int SPRD_RTC_SEC_ALM_VALUE ; 
 int SPRD_RTC_SEC_AUXALM_UPD ; 
 int SPRD_RTC_SEC_CNT_UPD ; 
 int SPRD_RTC_SEC_CNT_VALUE ; 
 int SPRD_RTC_SEC_MASK ; 
 int SPRD_RTC_SPG_UPD ; 
 int SPRD_RTC_SPG_UPD_EN ; 
 int SPRD_RTC_SPG_VALUE ; 
#define  SPRD_RTC_TIME 128 
 int SPRD_RTC_TIME_INT_MASK ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 struct sprd_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (TYPE_6__*,int) ; 
 struct sprd_rtc* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_6__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct sprd_rtc*) ; 
 TYPE_3__* devm_rtc_allocate_device (TYPE_6__*) ; 
 int div_s64_rem (int,int,int*) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sprd_rtc*) ; 
 int regmap_read (int /*<<< orphan*/ ,int,int*) ; 
 int regmap_read_poll_timeout (int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 
 struct rtc_time rtc_ktime_to_tm (int /*<<< orphan*/ ) ; 
 int rtc_register_device (TYPE_3__*) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int,struct rtc_time*) ; 
 scalar_t__ rtc_tm_sub (struct rtc_time*,struct rtc_time*) ; 
 int rtc_tm_to_time64 (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_3__*,int,int) ; 
 int /*<<< orphan*/  sprd_rtc_ops ; 

__attribute__((used)) static int sprd_rtc_clear_alarm_ints(struct sprd_rtc *rtc)
{
	return regmap_write(rtc->regmap, rtc->base + SPRD_RTC_INT_CLR,
			    SPRD_RTC_ALM_INT_MASK);
}

__attribute__((used)) static int sprd_rtc_disable_ints(struct sprd_rtc *rtc)
{
	int ret;

	ret = regmap_update_bits(rtc->regmap, rtc->base + SPRD_RTC_INT_EN,
				 SPRD_RTC_INT_MASK, 0);
	if (ret)
		return ret;

	return regmap_write(rtc->regmap, rtc->base + SPRD_RTC_INT_CLR,
			    SPRD_RTC_INT_MASK);
}

__attribute__((used)) static int sprd_rtc_lock_alarm(struct sprd_rtc *rtc, bool lock)
{
	int ret;
	u32 val;

	ret = regmap_read(rtc->regmap, rtc->base + SPRD_RTC_SPG_VALUE, &val);
	if (ret)
		return ret;

	val &= ~(SPRD_RTC_ALMLOCK_MASK | SPRD_RTC_POWEROFF_ALM_FLAG);
	if (lock)
		val |= SPRD_RTC_ALM_LOCK;
	else
		val |= SPRD_RTC_ALM_UNLOCK | SPRD_RTC_POWEROFF_ALM_FLAG;

	ret = regmap_write(rtc->regmap, rtc->base + SPRD_RTC_SPG_UPD, val);
	if (ret)
		return ret;

	/* wait until the SPG value is updated successfully */
	ret = regmap_read_poll_timeout(rtc->regmap,
				       rtc->base + SPRD_RTC_INT_RAW_STS, val,
				       (val & SPRD_RTC_SPG_UPD_EN),
				       SPRD_RTC_POLL_DELAY_US,
				       SPRD_RTC_POLL_TIMEOUT);
	if (ret) {
		dev_err(rtc->dev, "failed to update SPG value:%d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int sprd_rtc_get_secs(struct sprd_rtc *rtc, enum sprd_rtc_reg_types type,
			     time64_t *secs)
{
	u32 sec_reg, min_reg, hour_reg, day_reg;
	u32 val, sec, min, hour, day;
	int ret;

	switch (type) {
	case SPRD_RTC_TIME:
		sec_reg = SPRD_RTC_SEC_CNT_VALUE;
		min_reg = SPRD_RTC_MIN_CNT_VALUE;
		hour_reg = SPRD_RTC_HOUR_CNT_VALUE;
		day_reg = SPRD_RTC_DAY_CNT_VALUE;
		break;
	case SPRD_RTC_ALARM:
		sec_reg = SPRD_RTC_SEC_ALM_VALUE;
		min_reg = SPRD_RTC_MIN_ALM_VALUE;
		hour_reg = SPRD_RTC_HOUR_ALM_VALUE;
		day_reg = SPRD_RTC_DAY_ALM_VALUE;
		break;
	case SPRD_RTC_AUX_ALARM:
		sec_reg = SPRD_RTC_SEC_AUXALM_UPD;
		min_reg = SPRD_RTC_MIN_AUXALM_UPD;
		hour_reg = SPRD_RTC_HOUR_AUXALM_UPD;
		day_reg = SPRD_RTC_DAY_AUXALM_UPD;
		break;
	default:
		return -EINVAL;
	}

	ret = regmap_read(rtc->regmap, rtc->base + sec_reg, &val);
	if (ret)
		return ret;

	sec = val & SPRD_RTC_SEC_MASK;

	ret = regmap_read(rtc->regmap, rtc->base + min_reg, &val);
	if (ret)
		return ret;

	min = val & SPRD_RTC_MIN_MASK;

	ret = regmap_read(rtc->regmap, rtc->base + hour_reg, &val);
	if (ret)
		return ret;

	hour = val & SPRD_RTC_HOUR_MASK;

	ret = regmap_read(rtc->regmap, rtc->base + day_reg, &val);
	if (ret)
		return ret;

	day = val & SPRD_RTC_DAY_MASK;
	*secs = (((time64_t)(day * 24) + hour) * 60 + min) * 60 + sec;
	return 0;
}

__attribute__((used)) static int sprd_rtc_set_secs(struct sprd_rtc *rtc, enum sprd_rtc_reg_types type,
			     time64_t secs)
{
	u32 sec_reg, min_reg, hour_reg, day_reg, sts_mask;
	u32 sec, min, hour, day, val;
	int ret, rem;

	/* convert seconds to RTC time format */
	day = div_s64_rem(secs, 86400, &rem);
	hour = rem / 3600;
	rem -= hour * 3600;
	min = rem / 60;
	sec = rem - min * 60;

	switch (type) {
	case SPRD_RTC_TIME:
		sec_reg = SPRD_RTC_SEC_CNT_UPD;
		min_reg = SPRD_RTC_MIN_CNT_UPD;
		hour_reg = SPRD_RTC_HOUR_CNT_UPD;
		day_reg = SPRD_RTC_DAY_CNT_UPD;
		sts_mask = SPRD_RTC_TIME_INT_MASK;
		break;
	case SPRD_RTC_ALARM:
		sec_reg = SPRD_RTC_SEC_ALM_UPD;
		min_reg = SPRD_RTC_MIN_ALM_UPD;
		hour_reg = SPRD_RTC_HOUR_ALM_UPD;
		day_reg = SPRD_RTC_DAY_ALM_UPD;
		sts_mask = SPRD_RTC_ALMTIME_INT_MASK;
		break;
	case SPRD_RTC_AUX_ALARM:
		sec_reg = SPRD_RTC_SEC_AUXALM_UPD;
		min_reg = SPRD_RTC_MIN_AUXALM_UPD;
		hour_reg = SPRD_RTC_HOUR_AUXALM_UPD;
		day_reg = SPRD_RTC_DAY_AUXALM_UPD;
		sts_mask = 0;
		break;
	default:
		return -EINVAL;
	}

	ret = regmap_write(rtc->regmap, rtc->base + sec_reg, sec);
	if (ret)
		return ret;

	ret = regmap_write(rtc->regmap, rtc->base + min_reg, min);
	if (ret)
		return ret;

	ret = regmap_write(rtc->regmap, rtc->base + hour_reg, hour);
	if (ret)
		return ret;

	ret = regmap_write(rtc->regmap, rtc->base + day_reg, day);
	if (ret)
		return ret;

	if (type == SPRD_RTC_AUX_ALARM)
		return 0;

	/*
	 * Since the time and normal alarm registers are put in always-power-on
	 * region supplied by VDDRTC, then these registers changing time will
	 * be very long, about 125ms. Thus here we should wait until all
	 * values are updated successfully.
	 */
	ret = regmap_read_poll_timeout(rtc->regmap,
				       rtc->base + SPRD_RTC_INT_RAW_STS, val,
				       ((val & sts_mask) == sts_mask),
				       SPRD_RTC_POLL_DELAY_US,
				       SPRD_RTC_POLL_TIMEOUT);
	if (ret < 0) {
		dev_err(rtc->dev, "set time/alarm values timeout\n");
		return ret;
	}

	return regmap_write(rtc->regmap, rtc->base + SPRD_RTC_INT_CLR,
			    sts_mask);
}

__attribute__((used)) static int sprd_rtc_read_aux_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	time64_t secs;
	u32 val;
	int ret;

	ret = sprd_rtc_get_secs(rtc, SPRD_RTC_AUX_ALARM, &secs);
	if (ret)
		return ret;

	rtc_time64_to_tm(secs, &alrm->time);

	ret = regmap_read(rtc->regmap, rtc->base + SPRD_RTC_INT_EN, &val);
	if (ret)
		return ret;

	alrm->enabled = !!(val & SPRD_RTC_AUXALM_EN);

	ret = regmap_read(rtc->regmap, rtc->base + SPRD_RTC_INT_RAW_STS, &val);
	if (ret)
		return ret;

	alrm->pending = !!(val & SPRD_RTC_AUXALM_EN);
	return 0;
}

__attribute__((used)) static int sprd_rtc_set_aux_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	time64_t secs = rtc_tm_to_time64(&alrm->time);
	int ret;

	/* clear the auxiliary alarm interrupt status */
	ret = regmap_write(rtc->regmap, rtc->base + SPRD_RTC_INT_CLR,
			   SPRD_RTC_AUXALM_EN);
	if (ret)
		return ret;

	ret = sprd_rtc_set_secs(rtc, SPRD_RTC_AUX_ALARM, secs);
	if (ret)
		return ret;

	if (alrm->enabled) {
		ret = regmap_update_bits(rtc->regmap,
					 rtc->base + SPRD_RTC_INT_EN,
					 SPRD_RTC_AUXALM_EN,
					 SPRD_RTC_AUXALM_EN);
	} else {
		ret = regmap_update_bits(rtc->regmap,
					 rtc->base + SPRD_RTC_INT_EN,
					 SPRD_RTC_AUXALM_EN, 0);
	}

	return ret;
}

__attribute__((used)) static int sprd_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	time64_t secs;
	int ret;

	if (!rtc->valid) {
		dev_warn(dev, "RTC values are invalid\n");
		return -EINVAL;
	}

	ret = sprd_rtc_get_secs(rtc, SPRD_RTC_TIME, &secs);
	if (ret)
		return ret;

	rtc_time64_to_tm(secs, tm);
	return 0;
}

__attribute__((used)) static int sprd_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	time64_t secs = rtc_tm_to_time64(tm);
	int ret;

	ret = sprd_rtc_set_secs(rtc, SPRD_RTC_TIME, secs);
	if (ret)
		return ret;

	if (!rtc->valid) {
		/* Clear RTC power status firstly */
		ret = regmap_write(rtc->regmap, rtc->base + SPRD_RTC_PWR_CTRL,
				   SPRD_RTC_POWER_STS_CLEAR);
		if (ret)
			return ret;

		/*
		 * Set RTC power status to indicate now RTC has valid time
		 * values.
		 */
		ret = regmap_write(rtc->regmap, rtc->base + SPRD_RTC_PWR_CTRL,
				   SPRD_RTC_POWER_STS_VALID);
		if (ret)
			return ret;

		rtc->valid = true;
	}

	return 0;
}

__attribute__((used)) static int sprd_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	time64_t secs;
	int ret;
	u32 val;

	/*
	 * If aie_timer is enabled, we should get the normal alarm time.
	 * Otherwise we should get auxiliary alarm time.
	 */
	if (rtc->rtc && rtc->rtc->aie_timer.enabled == 0)
		return sprd_rtc_read_aux_alarm(dev, alrm);

	ret = sprd_rtc_get_secs(rtc, SPRD_RTC_ALARM, &secs);
	if (ret)
		return ret;

	rtc_time64_to_tm(secs, &alrm->time);

	ret = regmap_read(rtc->regmap, rtc->base + SPRD_RTC_INT_EN, &val);
	if (ret)
		return ret;

	alrm->enabled = !!(val & SPRD_RTC_ALARM_EN);

	ret = regmap_read(rtc->regmap, rtc->base + SPRD_RTC_INT_RAW_STS, &val);
	if (ret)
		return ret;

	alrm->pending = !!(val & SPRD_RTC_ALARM_EN);
	return 0;
}

__attribute__((used)) static int sprd_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	time64_t secs = rtc_tm_to_time64(&alrm->time);
	struct rtc_time aie_time =
		rtc_ktime_to_tm(rtc->rtc->aie_timer.node.expires);
	int ret;

	/*
	 * We have 2 groups alarms: normal alarm and auxiliary alarm. Since
	 * both normal alarm event and auxiliary alarm event can wake up system
	 * from deep sleep, but only alarm event can power up system from power
	 * down status. Moreover we do not need to poll about 125ms when
	 * updating auxiliary alarm registers. Thus we usually set auxiliary
	 * alarm when wake up system from deep sleep, and for other scenarios,
	 * we should set normal alarm with polling status.
	 *
	 * So here we check if the alarm time is set by aie_timer, if yes, we
	 * should set normal alarm, if not, we should set auxiliary alarm which
	 * means it is just a wake event.
	 */
	if (!rtc->rtc->aie_timer.enabled || rtc_tm_sub(&aie_time, &alrm->time))
		return sprd_rtc_set_aux_alarm(dev, alrm);

	/* clear the alarm interrupt status firstly */
	ret = regmap_write(rtc->regmap, rtc->base + SPRD_RTC_INT_CLR,
			   SPRD_RTC_ALARM_EN);
	if (ret)
		return ret;

	ret = sprd_rtc_set_secs(rtc, SPRD_RTC_ALARM, secs);
	if (ret)
		return ret;

	if (alrm->enabled) {
		ret = regmap_update_bits(rtc->regmap,
					 rtc->base + SPRD_RTC_INT_EN,
					 SPRD_RTC_ALARM_EN,
					 SPRD_RTC_ALARM_EN);
		if (ret)
			return ret;

		/* unlock the alarm to enable the alarm function. */
		ret = sprd_rtc_lock_alarm(rtc, false);
	} else {
		regmap_update_bits(rtc->regmap,
				   rtc->base + SPRD_RTC_INT_EN,
				   SPRD_RTC_ALARM_EN, 0);

		/*
		 * Lock the alarm function in case fake alarm event will power
		 * up systems.
		 */
		ret = sprd_rtc_lock_alarm(rtc, true);
	}

	return ret;
}

__attribute__((used)) static int sprd_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct sprd_rtc *rtc = dev_get_drvdata(dev);
	int ret;

	if (enabled) {
		ret = regmap_update_bits(rtc->regmap,
					 rtc->base + SPRD_RTC_INT_EN,
					 SPRD_RTC_ALARM_EN | SPRD_RTC_AUXALM_EN,
					 SPRD_RTC_ALARM_EN | SPRD_RTC_AUXALM_EN);
		if (ret)
			return ret;

		ret = sprd_rtc_lock_alarm(rtc, false);
	} else {
		regmap_update_bits(rtc->regmap, rtc->base + SPRD_RTC_INT_EN,
				   SPRD_RTC_ALARM_EN | SPRD_RTC_AUXALM_EN, 0);

		ret = sprd_rtc_lock_alarm(rtc, true);
	}

	return ret;
}

__attribute__((used)) static irqreturn_t sprd_rtc_handler(int irq, void *dev_id)
{
	struct sprd_rtc *rtc = dev_id;
	int ret;

	ret = sprd_rtc_clear_alarm_ints(rtc);
	if (ret)
		return IRQ_RETVAL(ret);

	rtc_update_irq(rtc->rtc, 1, RTC_AF | RTC_IRQF);
	return IRQ_HANDLED;
}

__attribute__((used)) static int sprd_rtc_check_power_down(struct sprd_rtc *rtc)
{
	u32 val;
	int ret;

	ret = regmap_read(rtc->regmap, rtc->base + SPRD_RTC_PWR_STS, &val);
	if (ret)
		return ret;

	/*
	 * If the RTC power status value is SPRD_RTC_POWER_RESET_VALUE, which
	 * means the RTC has been powered down, so the RTC time values are
	 * invalid.
	 */
	rtc->valid = val == SPRD_RTC_POWER_RESET_VALUE ? false : true;
	return 0;
}

__attribute__((used)) static int sprd_rtc_probe(struct platform_device *pdev)
{
	struct device_node *node = pdev->dev.of_node;
	struct sprd_rtc *rtc;
	int ret;

	rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->regmap = dev_get_regmap(pdev->dev.parent, NULL);
	if (!rtc->regmap)
		return -ENODEV;

	ret = of_property_read_u32(node, "reg", &rtc->base);
	if (ret) {
		dev_err(&pdev->dev, "failed to get RTC base address\n");
		return ret;
	}

	rtc->irq = platform_get_irq(pdev, 0);
	if (rtc->irq < 0) {
		dev_err(&pdev->dev, "failed to get RTC irq number\n");
		return rtc->irq;
	}

	rtc->rtc = devm_rtc_allocate_device(&pdev->dev);
	if (IS_ERR(rtc->rtc))
		return PTR_ERR(rtc->rtc);

	rtc->dev = &pdev->dev;
	platform_set_drvdata(pdev, rtc);

	/* clear all RTC interrupts and disable all RTC interrupts */
	ret = sprd_rtc_disable_ints(rtc);
	if (ret) {
		dev_err(&pdev->dev, "failed to disable RTC interrupts\n");
		return ret;
	}

	/* check if RTC time values are valid */
	ret = sprd_rtc_check_power_down(rtc);
	if (ret) {
		dev_err(&pdev->dev, "failed to check RTC time values\n");
		return ret;
	}

	ret = devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
					sprd_rtc_handler,
					IRQF_ONESHOT | IRQF_EARLY_RESUME,
					pdev->name, rtc);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to request RTC irq\n");
		return ret;
	}

	rtc->rtc->ops = &sprd_rtc_ops;
	rtc->rtc->range_min = 0;
	rtc->rtc->range_max = 5662310399LL;
	ret = rtc_register_device(rtc->rtc);
	if (ret) {
		dev_err(&pdev->dev, "failed to register rtc device\n");
		return ret;
	}

	device_init_wakeup(&pdev->dev, 1);
	return 0;
}

__attribute__((used)) static int sprd_rtc_remove(struct platform_device *pdev)
{
	device_init_wakeup(&pdev->dev, 0);
	return 0;
}


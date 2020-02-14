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
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; } ;
struct cpcap_time {int tod1; int tod2; unsigned long day; } ;
struct cpcap_rtc {unsigned int alarm_enabled; scalar_t__ vendor; void* update_irq; void* alarm_irq; int /*<<< orphan*/  regmap; int /*<<< orphan*/  rtc_dev; scalar_t__ update_enabled; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  CPCAP_REG_DAY ; 
 int /*<<< orphan*/  CPCAP_REG_DAYA ; 
 int /*<<< orphan*/  CPCAP_REG_TOD1 ; 
 int /*<<< orphan*/  CPCAP_REG_TOD2 ; 
 int /*<<< orphan*/  CPCAP_REG_TODA1 ; 
 int /*<<< orphan*/  CPCAP_REG_TODA2 ; 
 scalar_t__ CPCAP_VENDOR_ST ; 
 unsigned long DAY_MASK ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_TRIGGER_NONE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int RTC_UF ; 
 unsigned long SECS_PER_DAY ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int TOD1_MASK ; 
 int TOD2_MASK ; 
 int cpcap_get_vendor (struct device*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  cpcap_rtc_ops ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct cpcap_rtc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int device_init_wakeup (struct device*,int) ; 
 struct cpcap_rtc* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,void*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct cpcap_rtc*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (struct device*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_irq (void*) ; 
 int /*<<< orphan*/  enable_irq (void*) ; 
 void* platform_get_irq (struct platform_device*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cpcap_rtc*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  rtc_time_to_tm (unsigned long,struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_tm_to_time (struct rtc_time*,unsigned long*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int rtc_valid_tm (struct rtc_time*) ; 

__attribute__((used)) static void cpcap2rtc_time(struct rtc_time *rtc, struct cpcap_time *cpcap)
{
	unsigned long int tod;
	unsigned long int time;

	tod = (cpcap->tod1 & TOD1_MASK) | ((cpcap->tod2 & TOD2_MASK) << 8);
	time = tod + ((cpcap->day & DAY_MASK) * SECS_PER_DAY);

	rtc_time_to_tm(time, rtc);
}

__attribute__((used)) static void rtc2cpcap_time(struct cpcap_time *cpcap, struct rtc_time *rtc)
{
	unsigned long time;

	rtc_tm_to_time(rtc, &time);

	cpcap->day = time / SECS_PER_DAY;
	time %= SECS_PER_DAY;
	cpcap->tod2 = (time >> 8) & TOD2_MASK;
	cpcap->tod1 = time & TOD1_MASK;
}

__attribute__((used)) static int cpcap_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct cpcap_rtc *rtc = dev_get_drvdata(dev);

	if (rtc->alarm_enabled == enabled)
		return 0;

	if (enabled)
		enable_irq(rtc->alarm_irq);
	else
		disable_irq(rtc->alarm_irq);

	rtc->alarm_enabled = !!enabled;

	return 0;
}

__attribute__((used)) static int cpcap_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct cpcap_rtc *rtc;
	struct cpcap_time cpcap_tm;
	int temp_tod2;
	int ret;

	rtc = dev_get_drvdata(dev);

	ret = regmap_read(rtc->regmap, CPCAP_REG_TOD2, &temp_tod2);
	ret |= regmap_read(rtc->regmap, CPCAP_REG_DAY, &cpcap_tm.day);
	ret |= regmap_read(rtc->regmap, CPCAP_REG_TOD1, &cpcap_tm.tod1);
	ret |= regmap_read(rtc->regmap, CPCAP_REG_TOD2, &cpcap_tm.tod2);

	if (temp_tod2 > cpcap_tm.tod2)
		ret |= regmap_read(rtc->regmap, CPCAP_REG_DAY, &cpcap_tm.day);

	if (ret) {
		dev_err(dev, "Failed to read time\n");
		return -EIO;
	}

	cpcap2rtc_time(tm, &cpcap_tm);

	return 0;
}

__attribute__((used)) static int cpcap_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct cpcap_rtc *rtc;
	struct cpcap_time cpcap_tm;
	int ret = 0;

	rtc = dev_get_drvdata(dev);

	rtc2cpcap_time(&cpcap_tm, tm);

	if (rtc->alarm_enabled)
		disable_irq(rtc->alarm_irq);
	if (rtc->update_enabled)
		disable_irq(rtc->update_irq);

	if (rtc->vendor == CPCAP_VENDOR_ST) {
		/* The TOD1 and TOD2 registers MUST be written in this order
		 * for the change to properly set.
		 */
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD1,
					  TOD1_MASK, cpcap_tm.tod1);
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD2,
					  TOD2_MASK, cpcap_tm.tod2);
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_DAY,
					  DAY_MASK, cpcap_tm.day);
	} else {
		/* Clearing the upper lower 8 bits of the TOD guarantees that
		 * the upper half of TOD (TOD2) will not increment for 0xFF RTC
		 * ticks (255 seconds).  During this time we can safely write
		 * to DAY, TOD2, then TOD1 (in that order) and expect RTC to be
		 * synchronized to the exact time requested upon the final write
		 * to TOD1.
		 */
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD1,
					  TOD1_MASK, 0);
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_DAY,
					  DAY_MASK, cpcap_tm.day);
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD2,
					  TOD2_MASK, cpcap_tm.tod2);
		ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD1,
					  TOD1_MASK, cpcap_tm.tod1);
	}

	if (rtc->update_enabled)
		enable_irq(rtc->update_irq);
	if (rtc->alarm_enabled)
		enable_irq(rtc->alarm_irq);

	return ret;
}

__attribute__((used)) static int cpcap_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct cpcap_rtc *rtc;
	struct cpcap_time cpcap_tm;
	int ret;

	rtc = dev_get_drvdata(dev);

	alrm->enabled = rtc->alarm_enabled;

	ret = regmap_read(rtc->regmap, CPCAP_REG_DAYA, &cpcap_tm.day);
	ret |= regmap_read(rtc->regmap, CPCAP_REG_TODA2, &cpcap_tm.tod2);
	ret |= regmap_read(rtc->regmap, CPCAP_REG_TODA1, &cpcap_tm.tod1);

	if (ret) {
		dev_err(dev, "Failed to read time\n");
		return -EIO;
	}

	cpcap2rtc_time(&alrm->time, &cpcap_tm);
	return rtc_valid_tm(&alrm->time);
}

__attribute__((used)) static int cpcap_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct cpcap_rtc *rtc;
	struct cpcap_time cpcap_tm;
	int ret;

	rtc = dev_get_drvdata(dev);

	rtc2cpcap_time(&cpcap_tm, &alrm->time);

	if (rtc->alarm_enabled)
		disable_irq(rtc->alarm_irq);

	ret = regmap_update_bits(rtc->regmap, CPCAP_REG_DAYA, DAY_MASK,
				 cpcap_tm.day);
	ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TODA2, TOD2_MASK,
				  cpcap_tm.tod2);
	ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TODA1, TOD1_MASK,
				  cpcap_tm.tod1);

	if (!ret) {
		enable_irq(rtc->alarm_irq);
		rtc->alarm_enabled = true;
	}

	return ret;
}

__attribute__((used)) static irqreturn_t cpcap_rtc_alarm_irq(int irq, void *data)
{
	struct cpcap_rtc *rtc = data;

	rtc_update_irq(rtc->rtc_dev, 1, RTC_AF | RTC_IRQF);
	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t cpcap_rtc_update_irq(int irq, void *data)
{
	struct cpcap_rtc *rtc = data;

	rtc_update_irq(rtc->rtc_dev, 1, RTC_UF | RTC_IRQF);
	return IRQ_HANDLED;
}

__attribute__((used)) static int cpcap_rtc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct cpcap_rtc *rtc;
	int err;

	rtc = devm_kzalloc(dev, sizeof(*rtc), GFP_KERNEL);
	if (!rtc)
		return -ENOMEM;

	rtc->regmap = dev_get_regmap(dev->parent, NULL);
	if (!rtc->regmap)
		return -ENODEV;

	platform_set_drvdata(pdev, rtc);
	rtc->rtc_dev = devm_rtc_device_register(dev, "cpcap_rtc",
						&cpcap_rtc_ops, THIS_MODULE);

	if (IS_ERR(rtc->rtc_dev))
		return PTR_ERR(rtc->rtc_dev);

	err = cpcap_get_vendor(dev, rtc->regmap, &rtc->vendor);
	if (err)
		return err;

	rtc->alarm_irq = platform_get_irq(pdev, 0);
	err = devm_request_threaded_irq(dev, rtc->alarm_irq, NULL,
					cpcap_rtc_alarm_irq, IRQF_TRIGGER_NONE,
					"rtc_alarm", rtc);
	if (err) {
		dev_err(dev, "Could not request alarm irq: %d\n", err);
		return err;
	}
	disable_irq(rtc->alarm_irq);

	/* Stock Android uses the 1 Hz interrupt for "secure clock daemon",
	 * which is not supported by the mainline kernel. The mainline kernel
	 * does not use the irq at the moment, but we explicitly request and
	 * disable it, so that its masked and does not wake up the processor
	 * every second.
	 */
	rtc->update_irq = platform_get_irq(pdev, 1);
	err = devm_request_threaded_irq(dev, rtc->update_irq, NULL,
					cpcap_rtc_update_irq, IRQF_TRIGGER_NONE,
					"rtc_1hz", rtc);
	if (err) {
		dev_err(dev, "Could not request update irq: %d\n", err);
		return err;
	}
	disable_irq(rtc->update_irq);

	err = device_init_wakeup(dev, 1);
	if (err) {
		dev_err(dev, "wakeup initialization failed (%d)\n", err);
		/* ignore error and continue without wakeup support */
	}

	return 0;
}


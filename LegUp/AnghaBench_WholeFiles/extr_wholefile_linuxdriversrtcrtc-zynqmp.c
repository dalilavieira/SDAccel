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
struct xlnx_rtc_dev {int calibval; scalar_t__ alarm_irq; scalar_t__ sec_irq; int /*<<< orphan*/  rtc; scalar_t__ reg_base; } ;
struct rtc_time {int dummy; } ;
struct rtc_wkalrm {int enabled; struct rtc_time time; } ;
struct resource {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int RTC_AF ; 
 scalar_t__ RTC_ALRM ; 
 int RTC_BATT_EN ; 
 int RTC_CALIB_DEF ; 
 int RTC_CALIB_MASK ; 
 scalar_t__ RTC_CALIB_WR ; 
 scalar_t__ RTC_CTRL ; 
 scalar_t__ RTC_CUR_TM ; 
 int RTC_INT_ALRM ; 
 scalar_t__ RTC_INT_DIS ; 
 scalar_t__ RTC_INT_EN ; 
 scalar_t__ RTC_INT_MASK ; 
 int RTC_INT_SEC ; 
 scalar_t__ RTC_INT_STS ; 
 int RTC_IRQF ; 
 unsigned long RTC_SEC_MAX_VAL ; 
 scalar_t__ RTC_SET_TM_RD ; 
 scalar_t__ RTC_SET_TM_WR ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct xlnx_rtc_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct xlnx_rtc_dev* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct xlnx_rtc_dev*) ; 
 int /*<<< orphan*/  devm_rtc_device_register (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 void* platform_get_irq_byname (struct platform_device*,char*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xlnx_rtc_dev*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int,struct rtc_time*) ; 
 int rtc_tm_to_time64 (struct rtc_time*) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  xlnx_rtc_ops ; 

__attribute__((used)) static int xlnx_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
	unsigned long new_time;

	/*
	 * The value written will be updated after 1 sec into the
	 * seconds read register, so we need to program time +1 sec
	 * to get the correct time on read.
	 */
	new_time = rtc_tm_to_time64(tm) + 1;

	if (new_time > RTC_SEC_MAX_VAL)
		return -EINVAL;

	/*
	 * Writing into calibration register will clear the Tick Counter and
	 * force the next second to be signaled exactly in 1 second period
	 */
	xrtcdev->calibval &= RTC_CALIB_MASK;
	writel(xrtcdev->calibval, (xrtcdev->reg_base + RTC_CALIB_WR));

	writel(new_time, xrtcdev->reg_base + RTC_SET_TM_WR);

	/*
	 * Clear the rtc interrupt status register after setting the
	 * time. During a read_time function, the code should read the
	 * RTC_INT_STATUS register and if bit 0 is still 0, it means
	 * that one second has not elapsed yet since RTC was set and
	 * the current time should be read from SET_TIME_READ register;
	 * otherwise, CURRENT_TIME register is read to report the time
	 */
	writel(RTC_INT_SEC, xrtcdev->reg_base + RTC_INT_STS);

	return 0;
}

__attribute__((used)) static int xlnx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	u32 status;
	unsigned long read_time;
	struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);

	status = readl(xrtcdev->reg_base + RTC_INT_STS);

	if (status & RTC_INT_SEC) {
		/*
		 * RTC has updated the CURRENT_TIME with the time written into
		 * SET_TIME_WRITE register.
		 */
		rtc_time64_to_tm(readl(xrtcdev->reg_base + RTC_CUR_TM), tm);
	} else {
		/*
		 * Time written in SET_TIME_WRITE has not yet updated into
		 * the seconds read register, so read the time from the
		 * SET_TIME_WRITE instead of CURRENT_TIME register.
		 * Since we add +1 sec while writing, we need to -1 sec while
		 * reading.
		 */
		read_time = readl(xrtcdev->reg_base + RTC_SET_TM_RD) - 1;
		rtc_time64_to_tm(read_time, tm);
	}

	return 0;
}

__attribute__((used)) static int xlnx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);

	rtc_time64_to_tm(readl(xrtcdev->reg_base + RTC_ALRM), &alrm->time);
	alrm->enabled = readl(xrtcdev->reg_base + RTC_INT_MASK) & RTC_INT_ALRM;

	return 0;
}

__attribute__((used)) static int xlnx_rtc_alarm_irq_enable(struct device *dev, u32 enabled)
{
	struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);

	if (enabled)
		writel(RTC_INT_ALRM, xrtcdev->reg_base + RTC_INT_EN);
	else
		writel(RTC_INT_ALRM, xrtcdev->reg_base + RTC_INT_DIS);

	return 0;
}

__attribute__((used)) static int xlnx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
	unsigned long alarm_time;

	alarm_time = rtc_tm_to_time64(&alrm->time);

	if (alarm_time > RTC_SEC_MAX_VAL)
		return -EINVAL;

	writel((u32)alarm_time, (xrtcdev->reg_base + RTC_ALRM));

	xlnx_rtc_alarm_irq_enable(dev, alrm->enabled);

	return 0;
}

__attribute__((used)) static void xlnx_init_rtc(struct xlnx_rtc_dev *xrtcdev)
{
	u32 rtc_ctrl;

	/* Enable RTC switch to battery when VCC_PSAUX is not available */
	rtc_ctrl = readl(xrtcdev->reg_base + RTC_CTRL);
	rtc_ctrl |= RTC_BATT_EN;
	writel(rtc_ctrl, xrtcdev->reg_base + RTC_CTRL);

	/*
	 * Based on crystal freq of 33.330 KHz
	 * set the seconds counter and enable, set fractions counter
	 * to default value suggested as per design spec
	 * to correct RTC delay in frequency over period of time.
	 */
	xrtcdev->calibval &= RTC_CALIB_MASK;
	writel(xrtcdev->calibval, (xrtcdev->reg_base + RTC_CALIB_WR));
}

__attribute__((used)) static irqreturn_t xlnx_rtc_interrupt(int irq, void *id)
{
	struct xlnx_rtc_dev *xrtcdev = (struct xlnx_rtc_dev *)id;
	unsigned int status;

	status = readl(xrtcdev->reg_base + RTC_INT_STS);
	/* Check if interrupt asserted */
	if (!(status & (RTC_INT_SEC | RTC_INT_ALRM)))
		return IRQ_NONE;

	/* Clear RTC_INT_ALRM interrupt only */
	writel(RTC_INT_ALRM, xrtcdev->reg_base + RTC_INT_STS);

	if (status & RTC_INT_ALRM)
		rtc_update_irq(xrtcdev->rtc, 1, RTC_IRQF | RTC_AF);

	return IRQ_HANDLED;
}

__attribute__((used)) static int xlnx_rtc_probe(struct platform_device *pdev)
{
	struct xlnx_rtc_dev *xrtcdev;
	struct resource *res;
	int ret;

	xrtcdev = devm_kzalloc(&pdev->dev, sizeof(*xrtcdev), GFP_KERNEL);
	if (!xrtcdev)
		return -ENOMEM;

	platform_set_drvdata(pdev, xrtcdev);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	xrtcdev->reg_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(xrtcdev->reg_base))
		return PTR_ERR(xrtcdev->reg_base);

	xrtcdev->alarm_irq = platform_get_irq_byname(pdev, "alarm");
	if (xrtcdev->alarm_irq < 0) {
		dev_err(&pdev->dev, "no irq resource\n");
		return xrtcdev->alarm_irq;
	}
	ret = devm_request_irq(&pdev->dev, xrtcdev->alarm_irq,
			       xlnx_rtc_interrupt, 0,
			       dev_name(&pdev->dev), xrtcdev);
	if (ret) {
		dev_err(&pdev->dev, "request irq failed\n");
		return ret;
	}

	xrtcdev->sec_irq = platform_get_irq_byname(pdev, "sec");
	if (xrtcdev->sec_irq < 0) {
		dev_err(&pdev->dev, "no irq resource\n");
		return xrtcdev->sec_irq;
	}
	ret = devm_request_irq(&pdev->dev, xrtcdev->sec_irq,
			       xlnx_rtc_interrupt, 0,
			       dev_name(&pdev->dev), xrtcdev);
	if (ret) {
		dev_err(&pdev->dev, "request irq failed\n");
		return ret;
	}

	ret = of_property_read_u32(pdev->dev.of_node, "calibration",
				   &xrtcdev->calibval);
	if (ret)
		xrtcdev->calibval = RTC_CALIB_DEF;

	xlnx_init_rtc(xrtcdev);

	device_init_wakeup(&pdev->dev, 1);

	xrtcdev->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
					 &xlnx_rtc_ops, THIS_MODULE);
	return PTR_ERR_OR_ZERO(xrtcdev->rtc);
}

__attribute__((used)) static int xlnx_rtc_remove(struct platform_device *pdev)
{
	xlnx_rtc_alarm_irq_enable(&pdev->dev, 0);
	device_init_wakeup(&pdev->dev, 0);

	return 0;
}


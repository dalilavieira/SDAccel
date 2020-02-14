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
struct seq_file {int dummy; } ;
struct rtc_time {int dummy; } ;
struct resource {int dummy; } ;
struct TYPE_4__ {struct ep93xx_rtc* platform_data; int /*<<< orphan*/  kobj; } ;
struct platform_device {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct ep93xx_rtc {scalar_t__ rtc; scalar_t__ mmio_base; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ EP93XX_RTC_DATA ; 
 scalar_t__ EP93XX_RTC_LOAD ; 
 scalar_t__ EP93XX_RTC_SWCOMP ; 
 unsigned long EP93XX_RTC_SWCOMP_DEL_MASK ; 
 unsigned long EP93XX_RTC_SWCOMP_DEL_SHIFT ; 
 unsigned long EP93XX_RTC_SWCOMP_INT_MASK ; 
 unsigned long EP93XX_RTC_SWCOMP_INT_SHIFT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct ep93xx_rtc* dev_get_platdata (struct device*) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 struct ep93xx_rtc* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ devm_rtc_device_register (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ep93xx_rtc_ops ; 
 int /*<<< orphan*/  ep93xx_rtc_sysfs_files ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ep93xx_rtc*) ; 
 unsigned long readl (scalar_t__) ; 
 int /*<<< orphan*/  rtc_time_to_tm (unsigned long,struct rtc_time*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,unsigned short) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned short) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static int ep93xx_rtc_get_swcomp(struct device *dev, unsigned short *preload,
				unsigned short *delete)
{
	struct ep93xx_rtc *ep93xx_rtc = dev_get_platdata(dev);
	unsigned long comp;

	comp = readl(ep93xx_rtc->mmio_base + EP93XX_RTC_SWCOMP);

	if (preload)
		*preload = (comp & EP93XX_RTC_SWCOMP_INT_MASK)
				>> EP93XX_RTC_SWCOMP_INT_SHIFT;

	if (delete)
		*delete = (comp & EP93XX_RTC_SWCOMP_DEL_MASK)
				>> EP93XX_RTC_SWCOMP_DEL_SHIFT;

	return 0;
}

__attribute__((used)) static int ep93xx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct ep93xx_rtc *ep93xx_rtc = dev_get_platdata(dev);
	unsigned long time;

	 time = readl(ep93xx_rtc->mmio_base + EP93XX_RTC_DATA);

	rtc_time_to_tm(time, tm);
	return 0;
}

__attribute__((used)) static int ep93xx_rtc_set_mmss(struct device *dev, unsigned long secs)
{
	struct ep93xx_rtc *ep93xx_rtc = dev_get_platdata(dev);

	writel(secs + 1, ep93xx_rtc->mmio_base + EP93XX_RTC_LOAD);
	return 0;
}

__attribute__((used)) static int ep93xx_rtc_proc(struct device *dev, struct seq_file *seq)
{
	unsigned short preload, delete;

	ep93xx_rtc_get_swcomp(dev, &preload, &delete);

	seq_printf(seq, "preload\t\t: %d\n", preload);
	seq_printf(seq, "delete\t\t: %d\n", delete);

	return 0;
}

__attribute__((used)) static ssize_t ep93xx_rtc_show_comp_preload(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	unsigned short preload;

	ep93xx_rtc_get_swcomp(dev, &preload, NULL);

	return sprintf(buf, "%d\n", preload);
}

__attribute__((used)) static ssize_t ep93xx_rtc_show_comp_delete(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	unsigned short delete;

	ep93xx_rtc_get_swcomp(dev, NULL, &delete);

	return sprintf(buf, "%d\n", delete);
}

__attribute__((used)) static int ep93xx_rtc_probe(struct platform_device *pdev)
{
	struct ep93xx_rtc *ep93xx_rtc;
	struct resource *res;
	int err;

	ep93xx_rtc = devm_kzalloc(&pdev->dev, sizeof(*ep93xx_rtc), GFP_KERNEL);
	if (!ep93xx_rtc)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ep93xx_rtc->mmio_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ep93xx_rtc->mmio_base))
		return PTR_ERR(ep93xx_rtc->mmio_base);

	pdev->dev.platform_data = ep93xx_rtc;
	platform_set_drvdata(pdev, ep93xx_rtc);

	ep93xx_rtc->rtc = devm_rtc_device_register(&pdev->dev,
				pdev->name, &ep93xx_rtc_ops, THIS_MODULE);
	if (IS_ERR(ep93xx_rtc->rtc)) {
		err = PTR_ERR(ep93xx_rtc->rtc);
		goto exit;
	}

	err = sysfs_create_group(&pdev->dev.kobj, &ep93xx_rtc_sysfs_files);
	if (err)
		goto exit;

	return 0;

exit:
	pdev->dev.platform_data = NULL;
	return err;
}

__attribute__((used)) static int ep93xx_rtc_remove(struct platform_device *pdev)
{
	sysfs_remove_group(&pdev->dev.kobj, &ep93xx_rtc_sysfs_files);
	pdev->dev.platform_data = NULL;

	return 0;
}


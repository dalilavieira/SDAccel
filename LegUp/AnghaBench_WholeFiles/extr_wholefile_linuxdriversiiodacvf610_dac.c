#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct vf610_dac {unsigned int conv_mode; scalar_t__ clk; scalar_t__ regs; TYPE_2__* dev; } ;
struct resource {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned int VF610_DAC_CONV_LOW_POWER ; 
 int VF610_DAC_DACEN ; 
 int VF610_DAC_DACRFS ; 
 int VF610_DAC_DAT0 (int) ; 
 int VF610_DAC_LPEN ; 
 scalar_t__ VF610_DACx_STATCTRL ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 scalar_t__ devm_clk_get (TYPE_2__*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 scalar_t__ devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct vf610_dac* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  vf610_dac_iio_channels ; 
 int /*<<< orphan*/  vf610_dac_iio_info ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void vf610_dac_init(struct vf610_dac *info)
{
	int val;

	info->conv_mode = VF610_DAC_CONV_LOW_POWER;
	val = VF610_DAC_DACEN | VF610_DAC_DACRFS |
		VF610_DAC_LPEN;
	writel(val, info->regs + VF610_DACx_STATCTRL);
}

__attribute__((used)) static void vf610_dac_exit(struct vf610_dac *info)
{
	int val;

	val = readl(info->regs + VF610_DACx_STATCTRL);
	val &= ~VF610_DAC_DACEN;
	writel(val, info->regs + VF610_DACx_STATCTRL);
}

__attribute__((used)) static int vf610_set_conversion_mode(struct iio_dev *indio_dev,
				const struct iio_chan_spec *chan,
				unsigned int mode)
{
	struct vf610_dac *info = iio_priv(indio_dev);
	int val;

	mutex_lock(&indio_dev->mlock);
	info->conv_mode = mode;
	val = readl(info->regs + VF610_DACx_STATCTRL);
	if (mode)
		val |= VF610_DAC_LPEN;
	else
		val &= ~VF610_DAC_LPEN;
	writel(val, info->regs + VF610_DACx_STATCTRL);
	mutex_unlock(&indio_dev->mlock);

	return 0;
}

__attribute__((used)) static int vf610_get_conversion_mode(struct iio_dev *indio_dev,
				const struct iio_chan_spec *chan)
{
	struct vf610_dac *info = iio_priv(indio_dev);

	return info->conv_mode;
}

__attribute__((used)) static int vf610_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int *val, int *val2,
			long mask)
{
	struct vf610_dac *info = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		*val = VF610_DAC_DAT0(readl(info->regs));
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		/*
		 * DACRFS is always 1 for valid reference and typical
		 * reference voltage as per Vybrid datasheet is 3.3V
		 * from section 9.1.2.1 of Vybrid datasheet
		 */
		*val = 3300 /* mV */;
		*val2 = 12;
		return IIO_VAL_FRACTIONAL_LOG2;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int vf610_write_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int val, int val2,
			long mask)
{
	struct vf610_dac *info = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&indio_dev->mlock);
		writel(VF610_DAC_DAT0(val), info->regs);
		mutex_unlock(&indio_dev->mlock);
		return 0;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int vf610_dac_probe(struct platform_device *pdev)
{
	struct iio_dev *indio_dev;
	struct vf610_dac *info;
	struct resource *mem;
	int ret;

	indio_dev = devm_iio_device_alloc(&pdev->dev,
					sizeof(struct vf610_dac));
	if (!indio_dev) {
		dev_err(&pdev->dev, "Failed allocating iio device\n");
		return -ENOMEM;
	}

	info = iio_priv(indio_dev);
	info->dev = &pdev->dev;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	info->regs = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(info->regs))
		return PTR_ERR(info->regs);

	info->clk = devm_clk_get(&pdev->dev, "dac");
	if (IS_ERR(info->clk)) {
		dev_err(&pdev->dev, "Failed getting clock, err = %ld\n",
			PTR_ERR(info->clk));
		return PTR_ERR(info->clk);
	}

	platform_set_drvdata(pdev, indio_dev);

	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->dev.of_node = pdev->dev.of_node;
	indio_dev->info = &vf610_dac_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = vf610_dac_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(vf610_dac_iio_channels);

	ret = clk_prepare_enable(info->clk);
	if (ret) {
		dev_err(&pdev->dev,
			"Could not prepare or enable the clock\n");
		return ret;
	}

	vf610_dac_init(info);

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(&pdev->dev, "Couldn't register the device\n");
		goto error_iio_device_register;
	}

	return 0;

error_iio_device_register:
	clk_disable_unprepare(info->clk);

	return ret;
}

__attribute__((used)) static int vf610_dac_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct vf610_dac *info = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	vf610_dac_exit(info);
	clk_disable_unprepare(info->clk);

	return 0;
}


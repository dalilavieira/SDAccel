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
typedef  int u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct imx7d_adc_feature {size_t clk_pre_div; size_t avg_num; int core_time_unit; int average_en; } ;
struct imx7d_adc_analogue_core_clk {int reg_config; int pre_div; } ;
struct imx7d_adc {unsigned int regs; int pre_div_num; int channel; int value; int vref_uv; unsigned int vref; unsigned int clk; int /*<<< orphan*/ * dev; int /*<<< orphan*/  completion; struct imx7d_adc_feature adc_feature; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int channel; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SAMP_FREQ 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 size_t IMX7D_ADC_ANALOG_CLK_PRE_DIV_4 ; 
 size_t IMX7D_ADC_AVERAGE_NUM_32 ; 
 int /*<<< orphan*/  IMX7D_ADC_TIMEOUT ; 
 int IMX7D_EACH_CHANNEL_REG_OFFSET ; 
 unsigned int IMX7D_REG_ADC_ADC_CFG ; 
 int IMX7D_REG_ADC_ADC_CFG_ADC_CLK_DOWN ; 
 int IMX7D_REG_ADC_ADC_CFG_ADC_EN ; 
 int IMX7D_REG_ADC_ADC_CFG_ADC_POWER_DOWN ; 
 unsigned int IMX7D_REG_ADC_CHANNEL_CFG2_BASE ; 
 unsigned int IMX7D_REG_ADC_CHA_B_CNV_RSLT ; 
 unsigned int IMX7D_REG_ADC_CHC_D_CNV_RSLT ; 
 int IMX7D_REG_ADC_CH_CFG1_CHANNEL_AVG_EN ; 
 int IMX7D_REG_ADC_CH_CFG1_CHANNEL_EN ; 
 int IMX7D_REG_ADC_CH_CFG1_CHANNEL_SEL (int) ; 
 int IMX7D_REG_ADC_CH_CFG1_CHANNEL_SINGLE ; 
 int IMX7D_REG_ADC_INT_CHANNEL_INT_EN ; 
 unsigned int IMX7D_REG_ADC_INT_EN ; 
 unsigned int IMX7D_REG_ADC_INT_SIG_EN ; 
 unsigned int IMX7D_REG_ADC_INT_STATUS ; 
 int IMX7D_REG_ADC_INT_STATUS_CHANNEL_CONV_TIME_OUT ; 
 int IMX7D_REG_ADC_INT_STATUS_CHANNEL_INT_STATUS ; 
 unsigned int IMX7D_REG_ADC_TIMER_UNIT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (unsigned int) ; 
 int PTR_ERR (unsigned int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (unsigned int) ; 
 int clk_prepare_enable (unsigned int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 unsigned int devm_clk_get (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 unsigned int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 unsigned int devm_regulator_get (int /*<<< orphan*/ *,char*) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct imx7d_adc*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct imx7d_adc* iio_priv (struct iio_dev*) ; 
 struct imx7d_adc_analogue_core_clk* imx7d_adc_analogue_clk ; 
 int* imx7d_adc_average_num ; 
 int /*<<< orphan*/  imx7d_adc_iio_channels ; 
 int /*<<< orphan*/  imx7d_adc_iio_info ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int) ; 
 void* readl (unsigned int) ; 
 int /*<<< orphan*/  regulator_disable (unsigned int) ; 
 int regulator_enable (unsigned int) ; 
 int regulator_get_voltage (unsigned int) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 long wait_for_completion_interruptible_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,unsigned int) ; 

__attribute__((used)) static void imx7d_adc_feature_config(struct imx7d_adc *info)
{
	info->adc_feature.clk_pre_div = IMX7D_ADC_ANALOG_CLK_PRE_DIV_4;
	info->adc_feature.avg_num = IMX7D_ADC_AVERAGE_NUM_32;
	info->adc_feature.core_time_unit = 1;
	info->adc_feature.average_en = true;
}

__attribute__((used)) static void imx7d_adc_sample_rate_set(struct imx7d_adc *info)
{
	struct imx7d_adc_feature *adc_feature = &info->adc_feature;
	struct imx7d_adc_analogue_core_clk adc_analogure_clk;
	u32 i;
	u32 tmp_cfg1;
	u32 sample_rate = 0;

	/*
	 * Before sample set, disable channel A,B,C,D. Here we
	 * clear the bit 31 of register REG_ADC_CH_A\B\C\D_CFG1.
	 */
	for (i = 0; i < 4; i++) {
		tmp_cfg1 =
			readl(info->regs + i * IMX7D_EACH_CHANNEL_REG_OFFSET);
		tmp_cfg1 &= ~IMX7D_REG_ADC_CH_CFG1_CHANNEL_EN;
		writel(tmp_cfg1,
		       info->regs + i * IMX7D_EACH_CHANNEL_REG_OFFSET);
	}

	adc_analogure_clk = imx7d_adc_analogue_clk[adc_feature->clk_pre_div];
	sample_rate |= adc_analogure_clk.reg_config;
	info->pre_div_num = adc_analogure_clk.pre_div;

	sample_rate |= adc_feature->core_time_unit;
	writel(sample_rate, info->regs + IMX7D_REG_ADC_TIMER_UNIT);
}

__attribute__((used)) static void imx7d_adc_hw_init(struct imx7d_adc *info)
{
	u32 cfg;

	/* power up and enable adc analogue core */
	cfg = readl(info->regs + IMX7D_REG_ADC_ADC_CFG);
	cfg &= ~(IMX7D_REG_ADC_ADC_CFG_ADC_CLK_DOWN |
		 IMX7D_REG_ADC_ADC_CFG_ADC_POWER_DOWN);
	cfg |= IMX7D_REG_ADC_ADC_CFG_ADC_EN;
	writel(cfg, info->regs + IMX7D_REG_ADC_ADC_CFG);

	/* enable channel A,B,C,D interrupt */
	writel(IMX7D_REG_ADC_INT_CHANNEL_INT_EN,
	       info->regs + IMX7D_REG_ADC_INT_SIG_EN);
	writel(IMX7D_REG_ADC_INT_CHANNEL_INT_EN,
	       info->regs + IMX7D_REG_ADC_INT_EN);

	imx7d_adc_sample_rate_set(info);
}

__attribute__((used)) static void imx7d_adc_channel_set(struct imx7d_adc *info)
{
	u32 cfg1 = 0;
	u32 cfg2;
	u32 channel;

	channel = info->channel;

	/* the channel choose single conversion, and enable average mode */
	cfg1 |= (IMX7D_REG_ADC_CH_CFG1_CHANNEL_EN |
		 IMX7D_REG_ADC_CH_CFG1_CHANNEL_SINGLE);
	if (info->adc_feature.average_en)
		cfg1 |= IMX7D_REG_ADC_CH_CFG1_CHANNEL_AVG_EN;

	/*
	 * physical channel 0 chose logical channel A
	 * physical channel 1 chose logical channel B
	 * physical channel 2 chose logical channel C
	 * physical channel 3 chose logical channel D
	 */
	cfg1 |= IMX7D_REG_ADC_CH_CFG1_CHANNEL_SEL(channel);

	/*
	 * read register REG_ADC_CH_A\B\C\D_CFG2, according to the
	 * channel chosen
	 */
	cfg2 = readl(info->regs + IMX7D_EACH_CHANNEL_REG_OFFSET * channel +
		     IMX7D_REG_ADC_CHANNEL_CFG2_BASE);

	cfg2 |= imx7d_adc_average_num[info->adc_feature.avg_num];

	/*
	 * write the register REG_ADC_CH_A\B\C\D_CFG2, according to
	 * the channel chosen
	 */
	writel(cfg2, info->regs + IMX7D_EACH_CHANNEL_REG_OFFSET * channel +
	       IMX7D_REG_ADC_CHANNEL_CFG2_BASE);
	writel(cfg1, info->regs + IMX7D_EACH_CHANNEL_REG_OFFSET * channel);
}

__attribute__((used)) static u32 imx7d_adc_get_sample_rate(struct imx7d_adc *info)
{
	/* input clock is always 24MHz */
	u32 input_clk = 24000000;
	u32 analogue_core_clk;
	u32 core_time_unit = info->adc_feature.core_time_unit;
	u32 tmp;

	analogue_core_clk = input_clk / info->pre_div_num;
	tmp = (core_time_unit + 1) * 6;

	return analogue_core_clk / tmp;
}

__attribute__((used)) static int imx7d_adc_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int *val,
			int *val2,
			long mask)
{
	struct imx7d_adc *info = iio_priv(indio_dev);

	u32 channel;
	long ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&indio_dev->mlock);
		reinit_completion(&info->completion);

		channel = chan->channel & 0x03;
		info->channel = channel;
		imx7d_adc_channel_set(info);

		ret = wait_for_completion_interruptible_timeout
				(&info->completion, IMX7D_ADC_TIMEOUT);
		if (ret == 0) {
			mutex_unlock(&indio_dev->mlock);
			return -ETIMEDOUT;
		}
		if (ret < 0) {
			mutex_unlock(&indio_dev->mlock);
			return ret;
		}

		*val = info->value;
		mutex_unlock(&indio_dev->mlock);
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		info->vref_uv = regulator_get_voltage(info->vref);
		*val = info->vref_uv / 1000;
		*val2 = 12;
		return IIO_VAL_FRACTIONAL_LOG2;

	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = imx7d_adc_get_sample_rate(info);
		return IIO_VAL_INT;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int imx7d_adc_read_data(struct imx7d_adc *info)
{
	u32 channel;
	u32 value;

	channel = info->channel & 0x03;

	/*
	 * channel A and B conversion result share one register,
	 * bit[27~16] is the channel B conversion result,
	 * bit[11~0] is the channel A conversion result.
	 * channel C and D is the same.
	 */
	if (channel < 2)
		value = readl(info->regs + IMX7D_REG_ADC_CHA_B_CNV_RSLT);
	else
		value = readl(info->regs + IMX7D_REG_ADC_CHC_D_CNV_RSLT);
	if (channel & 0x1)	/* channel B or D */
		value = (value >> 16) & 0xFFF;
	else			/* channel A or C */
		value &= 0xFFF;

	return value;
}

__attribute__((used)) static irqreturn_t imx7d_adc_isr(int irq, void *dev_id)
{
	struct imx7d_adc *info = dev_id;
	int status;

	status = readl(info->regs + IMX7D_REG_ADC_INT_STATUS);
	if (status & IMX7D_REG_ADC_INT_STATUS_CHANNEL_INT_STATUS) {
		info->value = imx7d_adc_read_data(info);
		complete(&info->completion);

		/*
		 * The register IMX7D_REG_ADC_INT_STATUS can't clear
		 * itself after read operation, need software to write
		 * 0 to the related bit. Here we clear the channel A/B/C/D
		 * conversion finished flag.
		 */
		status &= ~IMX7D_REG_ADC_INT_STATUS_CHANNEL_INT_STATUS;
		writel(status, info->regs + IMX7D_REG_ADC_INT_STATUS);
	}

	/*
	 * If the channel A/B/C/D conversion timeout, report it and clear these
	 * timeout flags.
	 */
	if (status & IMX7D_REG_ADC_INT_STATUS_CHANNEL_CONV_TIME_OUT) {
		pr_err("%s: ADC got conversion time out interrupt: 0x%08x\n",
			dev_name(info->dev), status);
		status &= ~IMX7D_REG_ADC_INT_STATUS_CHANNEL_CONV_TIME_OUT;
		writel(status, info->regs + IMX7D_REG_ADC_INT_STATUS);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int imx7d_adc_reg_access(struct iio_dev *indio_dev,
			unsigned reg, unsigned writeval,
			unsigned *readval)
{
	struct imx7d_adc *info = iio_priv(indio_dev);

	if (!readval || reg % 4 || reg > IMX7D_REG_ADC_ADC_CFG)
		return -EINVAL;

	*readval = readl(info->regs + reg);

	return 0;
}

__attribute__((used)) static void imx7d_adc_power_down(struct imx7d_adc *info)
{
	u32 adc_cfg;

	adc_cfg = readl(info->regs + IMX7D_REG_ADC_ADC_CFG);
	adc_cfg |= IMX7D_REG_ADC_ADC_CFG_ADC_CLK_DOWN |
		   IMX7D_REG_ADC_ADC_CFG_ADC_POWER_DOWN;
	adc_cfg &= ~IMX7D_REG_ADC_ADC_CFG_ADC_EN;
	writel(adc_cfg, info->regs + IMX7D_REG_ADC_ADC_CFG);
}

__attribute__((used)) static int imx7d_adc_probe(struct platform_device *pdev)
{
	struct imx7d_adc *info;
	struct iio_dev *indio_dev;
	struct resource *mem;
	int irq;
	int ret;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
	if (!indio_dev) {
		dev_err(&pdev->dev, "Failed allocating iio device\n");
		return -ENOMEM;
	}

	info = iio_priv(indio_dev);
	info->dev = &pdev->dev;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	info->regs = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(info->regs)) {
		ret = PTR_ERR(info->regs);
		dev_err(&pdev->dev,
			"Failed to remap adc memory, err = %d\n", ret);
		return ret;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "No irq resource?\n");
		return irq;
	}

	info->clk = devm_clk_get(&pdev->dev, "adc");
	if (IS_ERR(info->clk)) {
		ret = PTR_ERR(info->clk);
		dev_err(&pdev->dev, "Failed getting clock, err = %d\n", ret);
		return ret;
	}

	info->vref = devm_regulator_get(&pdev->dev, "vref");
	if (IS_ERR(info->vref)) {
		ret = PTR_ERR(info->vref);
		dev_err(&pdev->dev,
			"Failed getting reference voltage, err = %d\n", ret);
		return ret;
	}

	ret = regulator_enable(info->vref);
	if (ret) {
		dev_err(&pdev->dev,
			"Can't enable adc reference top voltage, err = %d\n",
			ret);
		return ret;
	}

	platform_set_drvdata(pdev, indio_dev);

	init_completion(&info->completion);

	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->info = &imx7d_adc_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = imx7d_adc_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(imx7d_adc_iio_channels);

	ret = clk_prepare_enable(info->clk);
	if (ret) {
		dev_err(&pdev->dev,
			"Could not prepare or enable the clock.\n");
		goto error_adc_clk_enable;
	}

	ret = devm_request_irq(info->dev, irq,
				imx7d_adc_isr, 0,
				dev_name(&pdev->dev), info);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed requesting irq, irq = %d\n", irq);
		goto error_iio_device_register;
	}

	imx7d_adc_feature_config(info);
	imx7d_adc_hw_init(info);

	ret = iio_device_register(indio_dev);
	if (ret) {
		imx7d_adc_power_down(info);
		dev_err(&pdev->dev, "Couldn't register the device.\n");
		goto error_iio_device_register;
	}

	return 0;

error_iio_device_register:
	clk_disable_unprepare(info->clk);
error_adc_clk_enable:
	regulator_disable(info->vref);

	return ret;
}

__attribute__((used)) static int imx7d_adc_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct imx7d_adc *info = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	imx7d_adc_power_down(info);

	clk_disable_unprepare(info->clk);
	regulator_disable(info->vref);

	return 0;
}


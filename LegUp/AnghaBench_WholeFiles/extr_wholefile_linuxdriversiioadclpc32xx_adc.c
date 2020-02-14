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
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct lpc32xx_adc_state {int value; int /*<<< orphan*/  completion; int /*<<< orphan*/  clk; int /*<<< orphan*/  adc_base; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int address; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 long IIO_CHAN_INFO_RAW ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPC32XXAD_CTRL (int /*<<< orphan*/ ) ; 
 int LPC32XXAD_INTERNAL ; 
 int /*<<< orphan*/  LPC32XXAD_NAME ; 
 int LPC32XXAD_PDN_CTRL ; 
 int LPC32XXAD_REFm ; 
 int LPC32XXAD_REFp ; 
 int /*<<< orphan*/  LPC32XXAD_SELECT (int /*<<< orphan*/ ) ; 
 int LPC32XXAD_STROBE ; 
 int /*<<< orphan*/  LPC32XXAD_VALUE (int /*<<< orphan*/ ) ; 
 int LPC32XXAD_VALUE_MASK ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  devm_ioremap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct lpc32xx_adc_state*) ; 
 struct lpc32xx_adc_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lpc32xx_adc_iio_channels ; 
 int /*<<< orphan*/  lpc32xx_adc_iio_info ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int lpc32xx_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val,
			    int *val2,
			    long mask)
{
	struct lpc32xx_adc_state *st = iio_priv(indio_dev);
	int ret;
	if (mask == IIO_CHAN_INFO_RAW) {
		mutex_lock(&indio_dev->mlock);
		ret = clk_prepare_enable(st->clk);
		if (ret) {
			mutex_unlock(&indio_dev->mlock);
			return ret;
		}
		/* Measurement setup */
		__raw_writel(LPC32XXAD_INTERNAL | (chan->address) |
			     LPC32XXAD_REFp | LPC32XXAD_REFm,
			     LPC32XXAD_SELECT(st->adc_base));
		/* Trigger conversion */
		__raw_writel(LPC32XXAD_PDN_CTRL | LPC32XXAD_STROBE,
			     LPC32XXAD_CTRL(st->adc_base));
		wait_for_completion(&st->completion); /* set by ISR */
		clk_disable_unprepare(st->clk);
		*val = st->value;
		mutex_unlock(&indio_dev->mlock);

		return IIO_VAL_INT;
	}

	return -EINVAL;
}

__attribute__((used)) static irqreturn_t lpc32xx_adc_isr(int irq, void *dev_id)
{
	struct lpc32xx_adc_state *st = dev_id;

	/* Read value and clear irq */
	st->value = __raw_readl(LPC32XXAD_VALUE(st->adc_base)) &
		LPC32XXAD_VALUE_MASK;
	complete(&st->completion);

	return IRQ_HANDLED;
}

__attribute__((used)) static int lpc32xx_adc_probe(struct platform_device *pdev)
{
	struct lpc32xx_adc_state *st = NULL;
	struct resource *res;
	int retval = -ENODEV;
	struct iio_dev *iodev = NULL;
	int irq;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "failed to get platform I/O memory\n");
		return -ENXIO;
	}

	iodev = devm_iio_device_alloc(&pdev->dev, sizeof(*st));
	if (!iodev)
		return -ENOMEM;

	st = iio_priv(iodev);

	st->adc_base = devm_ioremap(&pdev->dev, res->start,
				    resource_size(res));
	if (!st->adc_base) {
		dev_err(&pdev->dev, "failed mapping memory\n");
		return -EBUSY;
	}

	st->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(st->clk)) {
		dev_err(&pdev->dev, "failed getting clock\n");
		return PTR_ERR(st->clk);
	}

	irq = platform_get_irq(pdev, 0);
	if (irq <= 0) {
		dev_err(&pdev->dev, "failed getting interrupt resource\n");
		return -ENXIO;
	}

	retval = devm_request_irq(&pdev->dev, irq, lpc32xx_adc_isr, 0,
				  LPC32XXAD_NAME, st);
	if (retval < 0) {
		dev_err(&pdev->dev, "failed requesting interrupt\n");
		return retval;
	}

	platform_set_drvdata(pdev, iodev);

	init_completion(&st->completion);

	iodev->name = LPC32XXAD_NAME;
	iodev->dev.parent = &pdev->dev;
	iodev->info = &lpc32xx_adc_iio_info;
	iodev->modes = INDIO_DIRECT_MODE;
	iodev->channels = lpc32xx_adc_iio_channels;
	iodev->num_channels = ARRAY_SIZE(lpc32xx_adc_iio_channels);

	retval = devm_iio_device_register(&pdev->dev, iodev);
	if (retval)
		return retval;

	dev_info(&pdev->dev, "LPC32XX ADC driver loaded, IRQ %d\n", irq);

	return 0;
}


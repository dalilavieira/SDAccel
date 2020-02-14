#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  void* u32 ;
struct TYPE_15__ {int /*<<< orphan*/  parent; struct device_node* of_node; } ;
struct platform_device {TYPE_3__ dev; } ;
struct palmas_platform_data {struct palmas_gpadc_platform_data* gpadc_pdata; } ;
struct palmas_gpadc_platform_data {int ch0_current; int ch3_current; unsigned int extended_delay; scalar_t__ adc_wakeup1_data; scalar_t__ adc_wakeup2_data; int /*<<< orphan*/  auto_conversion_period_ms; } ;
struct palmas_gpadc {unsigned int extended_delay; unsigned int ch0_current; unsigned int ch3_current; int irq; int wakeup1_enable; int irq_auto_0; int wakeup2_enable; int irq_auto_1; TYPE_2__* adc_info; TYPE_3__* dev; int /*<<< orphan*/  wakeup2_data; int /*<<< orphan*/  wakeup1_data; int /*<<< orphan*/  palmas; int /*<<< orphan*/  auto_conversion_period; int /*<<< orphan*/  conv_completion; } ;
struct TYPE_13__ {TYPE_3__* parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int channel; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_14__ {int x1; int x2; int v1; int v2; int gain_error; int gain; int offset; int /*<<< orphan*/  is_uncalibrated; int /*<<< orphan*/  trim2_reg; int /*<<< orphan*/  trim1_reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IIO_CHAN_INFO_PROCESSED 129 
#define  IIO_CHAN_INFO_RAW 128 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  MOD_NAME ; 
 unsigned int PALMAS_ADC_CH0_CURRENT_SRC_0 ; 
 unsigned int PALMAS_ADC_CH0_CURRENT_SRC_15 ; 
 unsigned int PALMAS_ADC_CH0_CURRENT_SRC_20 ; 
 unsigned int PALMAS_ADC_CH0_CURRENT_SRC_5 ; 
 unsigned int PALMAS_ADC_CH3_CURRENT_SRC_0 ; 
 unsigned int PALMAS_ADC_CH3_CURRENT_SRC_10 ; 
 unsigned int PALMAS_ADC_CH3_CURRENT_SRC_400 ; 
 unsigned int PALMAS_ADC_CH3_CURRENT_SRC_800 ; 
 int PALMAS_ADC_CH_MAX ; 
 int /*<<< orphan*/  PALMAS_ADC_CONVERSION_TIMEOUT ; 
 int /*<<< orphan*/  PALMAS_GPADC_AUTO_CTRL ; 
 unsigned int PALMAS_GPADC_AUTO_CTRL_SHUTDOWN_CONV0 ; 
 unsigned int PALMAS_GPADC_AUTO_CTRL_SHUTDOWN_CONV1 ; 
 int /*<<< orphan*/  PALMAS_GPADC_BASE ; 
 int /*<<< orphan*/  PALMAS_GPADC_CTRL1 ; 
 unsigned int PALMAS_GPADC_CTRL1_CURRENT_SRC_CH0_MASK ; 
 unsigned int PALMAS_GPADC_CTRL1_CURRENT_SRC_CH0_SHIFT ; 
 unsigned int PALMAS_GPADC_CTRL1_CURRENT_SRC_CH3_MASK ; 
 unsigned int PALMAS_GPADC_CTRL1_CURRENT_SRC_CH3_SHIFT ; 
 unsigned int PALMAS_GPADC_CTRL1_GPADC_FORCE ; 
 int /*<<< orphan*/  PALMAS_GPADC_EOC_SW_IRQ ; 
 int /*<<< orphan*/  PALMAS_GPADC_RT_CTRL ; 
 unsigned int PALMAS_GPADC_RT_CTRL_EXTEND_DELAY ; 
 unsigned int PALMAS_GPADC_RT_CTRL_EXTEND_DELAY_SHIFT ; 
 int /*<<< orphan*/  PALMAS_GPADC_SW_CONV0_LSB ; 
 int /*<<< orphan*/  PALMAS_GPADC_SW_SELECT ; 
 int PALMAS_GPADC_SW_SELECT_SW_CONV0_SEL_MASK ; 
 int PALMAS_GPADC_SW_SELECT_SW_CONV_EN ; 
 unsigned int PALMAS_GPADC_SW_SELECT_SW_START_CONV0 ; 
 int /*<<< orphan*/  PALMAS_INT3_MASK ; 
 unsigned int PALMAS_INT3_MASK_GPADC_EOC_SW ; 
 int /*<<< orphan*/  PALMAS_INTERRUPT_BASE ; 
 int /*<<< orphan*/  PALMAS_TRIM_GPADC_BASE ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct palmas_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 char* dev_name (TYPE_3__*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_3__*,struct iio_dev*) ; 
 struct iio_dev* dev_to_iio_dev (TYPE_3__*) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (TYPE_3__*,int) ; 
 int /*<<< orphan*/  device_wakeup_disable (TYPE_3__*) ; 
 int /*<<< orphan*/  device_wakeup_enable (TYPE_3__*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_3__*,int) ; 
 struct palmas_gpadc_platform_data* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,struct palmas_gpadc*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct palmas_gpadc* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,scalar_t__,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned int of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,void**) ; 
 int palmas_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*,int) ; 
 int /*<<< orphan*/  palmas_gpadc_iio_channel ; 
 int /*<<< orphan*/  palmas_gpadc_iio_info ; 
 TYPE_2__* palmas_gpadc_info ; 
 int palmas_irq_get_virq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int palmas_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int palmas_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int palmas_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* platform_get_irq (struct platform_device*,int) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct palmas_gpadc*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int palmas_disable_auto_conversion(struct palmas_gpadc *adc)
{
	int ret;

	ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
			PALMAS_GPADC_CTRL1,
			PALMAS_GPADC_CTRL1_GPADC_FORCE,
			PALMAS_GPADC_CTRL1_GPADC_FORCE);
	if (ret < 0) {
		dev_err(adc->dev, "GPADC_CTRL1 update failed: %d\n", ret);
		return ret;
	}

	ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
			PALMAS_GPADC_AUTO_CTRL,
			PALMAS_GPADC_AUTO_CTRL_SHUTDOWN_CONV1 |
			PALMAS_GPADC_AUTO_CTRL_SHUTDOWN_CONV0,
			0);
	if (ret < 0) {
		dev_err(adc->dev, "AUTO_CTRL update failed: %d\n", ret);
		return ret;
	}

	udelay(100);

	ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
			PALMAS_GPADC_CTRL1,
			PALMAS_GPADC_CTRL1_GPADC_FORCE, 0);
	if (ret < 0)
		dev_err(adc->dev, "GPADC_CTRL1 update failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static irqreturn_t palmas_gpadc_irq(int irq, void *data)
{
	struct palmas_gpadc *adc = data;

	complete(&adc->conv_completion);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t palmas_gpadc_irq_auto(int irq, void *data)
{
	struct palmas_gpadc *adc = data;

	dev_dbg(adc->dev, "Threshold interrupt %d occurs\n", irq);
	palmas_disable_auto_conversion(adc);

	return IRQ_HANDLED;
}

__attribute__((used)) static int palmas_gpadc_start_mask_interrupt(struct palmas_gpadc *adc,
						bool mask)
{
	int ret;

	if (!mask)
		ret = palmas_update_bits(adc->palmas, PALMAS_INTERRUPT_BASE,
					PALMAS_INT3_MASK,
					PALMAS_INT3_MASK_GPADC_EOC_SW, 0);
	else
		ret = palmas_update_bits(adc->palmas, PALMAS_INTERRUPT_BASE,
					PALMAS_INT3_MASK,
					PALMAS_INT3_MASK_GPADC_EOC_SW,
					PALMAS_INT3_MASK_GPADC_EOC_SW);
	if (ret < 0)
		dev_err(adc->dev, "GPADC INT MASK update failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static int palmas_gpadc_enable(struct palmas_gpadc *adc, int adc_chan,
			       int enable)
{
	unsigned int mask, val;
	int ret;

	if (enable) {
		val = (adc->extended_delay
			<< PALMAS_GPADC_RT_CTRL_EXTEND_DELAY_SHIFT);
		ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
					PALMAS_GPADC_RT_CTRL,
					PALMAS_GPADC_RT_CTRL_EXTEND_DELAY, val);
		if (ret < 0) {
			dev_err(adc->dev, "RT_CTRL update failed: %d\n", ret);
			return ret;
		}

		mask = (PALMAS_GPADC_CTRL1_CURRENT_SRC_CH0_MASK |
			PALMAS_GPADC_CTRL1_CURRENT_SRC_CH3_MASK |
			PALMAS_GPADC_CTRL1_GPADC_FORCE);
		val = (adc->ch0_current
			<< PALMAS_GPADC_CTRL1_CURRENT_SRC_CH0_SHIFT);
		val |= (adc->ch3_current
			<< PALMAS_GPADC_CTRL1_CURRENT_SRC_CH3_SHIFT);
		val |= PALMAS_GPADC_CTRL1_GPADC_FORCE;
		ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
				PALMAS_GPADC_CTRL1, mask, val);
		if (ret < 0) {
			dev_err(adc->dev,
				"Failed to update current setting: %d\n", ret);
			return ret;
		}

		mask = (PALMAS_GPADC_SW_SELECT_SW_CONV0_SEL_MASK |
			PALMAS_GPADC_SW_SELECT_SW_CONV_EN);
		val = (adc_chan | PALMAS_GPADC_SW_SELECT_SW_CONV_EN);
		ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
				PALMAS_GPADC_SW_SELECT, mask, val);
		if (ret < 0) {
			dev_err(adc->dev, "SW_SELECT update failed: %d\n", ret);
			return ret;
		}
	} else {
		ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
				PALMAS_GPADC_SW_SELECT, 0);
		if (ret < 0)
			dev_err(adc->dev, "SW_SELECT write failed: %d\n", ret);

		ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
				PALMAS_GPADC_CTRL1,
				PALMAS_GPADC_CTRL1_GPADC_FORCE, 0);
		if (ret < 0) {
			dev_err(adc->dev, "CTRL1 update failed: %d\n", ret);
			return ret;
		}
	}

	return ret;
}

__attribute__((used)) static int palmas_gpadc_read_prepare(struct palmas_gpadc *adc, int adc_chan)
{
	int ret;

	ret = palmas_gpadc_enable(adc, adc_chan, true);
	if (ret < 0)
		return ret;

	return palmas_gpadc_start_mask_interrupt(adc, 0);
}

__attribute__((used)) static void palmas_gpadc_read_done(struct palmas_gpadc *adc, int adc_chan)
{
	palmas_gpadc_start_mask_interrupt(adc, 1);
	palmas_gpadc_enable(adc, adc_chan, false);
}

__attribute__((used)) static int palmas_gpadc_calibrate(struct palmas_gpadc *adc, int adc_chan)
{
	int k;
	int d1;
	int d2;
	int ret;
	int gain;
	int x1 =  adc->adc_info[adc_chan].x1;
	int x2 =  adc->adc_info[adc_chan].x2;
	int v1 = adc->adc_info[adc_chan].v1;
	int v2 = adc->adc_info[adc_chan].v2;

	ret = palmas_read(adc->palmas, PALMAS_TRIM_GPADC_BASE,
				adc->adc_info[adc_chan].trim1_reg, &d1);
	if (ret < 0) {
		dev_err(adc->dev, "TRIM read failed: %d\n", ret);
		goto scrub;
	}

	ret = palmas_read(adc->palmas, PALMAS_TRIM_GPADC_BASE,
				adc->adc_info[adc_chan].trim2_reg, &d2);
	if (ret < 0) {
		dev_err(adc->dev, "TRIM read failed: %d\n", ret);
		goto scrub;
	}

	/* gain error calculation */
	k = (1000 + (1000 * (d2 - d1)) / (x2 - x1));

	/* gain calculation */
	gain = ((v2 - v1) * 1000) / (x2 - x1);

	adc->adc_info[adc_chan].gain_error = k;
	adc->adc_info[adc_chan].gain = gain;
	/* offset Calculation */
	adc->adc_info[adc_chan].offset = (d1 * 1000) - ((k - 1000) * x1);

scrub:
	return ret;
}

__attribute__((used)) static int palmas_gpadc_start_conversion(struct palmas_gpadc *adc, int adc_chan)
{
	unsigned int val;
	int ret;

	init_completion(&adc->conv_completion);
	ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
				PALMAS_GPADC_SW_SELECT,
				PALMAS_GPADC_SW_SELECT_SW_START_CONV0,
				PALMAS_GPADC_SW_SELECT_SW_START_CONV0);
	if (ret < 0) {
		dev_err(adc->dev, "SELECT_SW_START write failed: %d\n", ret);
		return ret;
	}

	ret = wait_for_completion_timeout(&adc->conv_completion,
				PALMAS_ADC_CONVERSION_TIMEOUT);
	if (ret == 0) {
		dev_err(adc->dev, "conversion not completed\n");
		return -ETIMEDOUT;
	}

	ret = palmas_bulk_read(adc->palmas, PALMAS_GPADC_BASE,
				PALMAS_GPADC_SW_CONV0_LSB, &val, 2);
	if (ret < 0) {
		dev_err(adc->dev, "SW_CONV0_LSB read failed: %d\n", ret);
		return ret;
	}

	ret = val & 0xFFF;

	return ret;
}

__attribute__((used)) static int palmas_gpadc_get_calibrated_code(struct palmas_gpadc *adc,
						int adc_chan, int val)
{
	if (!adc->adc_info[adc_chan].is_uncalibrated)
		val  = (val*1000 - adc->adc_info[adc_chan].offset) /
					adc->adc_info[adc_chan].gain_error;

	if (val < 0) {
		dev_err(adc->dev, "Mismatch with calibration\n");
		return 0;
	}

	val = (val * adc->adc_info[adc_chan].gain) / 1000;

	return val;
}

__attribute__((used)) static int palmas_gpadc_read_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
	struct  palmas_gpadc *adc = iio_priv(indio_dev);
	int adc_chan = chan->channel;
	int ret = 0;

	if (adc_chan > PALMAS_ADC_CH_MAX)
		return -EINVAL;

	mutex_lock(&indio_dev->mlock);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
	case IIO_CHAN_INFO_PROCESSED:
		ret = palmas_gpadc_read_prepare(adc, adc_chan);
		if (ret < 0)
			goto out;

		ret = palmas_gpadc_start_conversion(adc, adc_chan);
		if (ret < 0) {
			dev_err(adc->dev,
			"ADC start conversion failed\n");
			goto out;
		}

		if (mask == IIO_CHAN_INFO_PROCESSED)
			ret = palmas_gpadc_get_calibrated_code(
							adc, adc_chan, ret);

		*val = ret;

		ret = IIO_VAL_INT;
		goto out;
	}

	mutex_unlock(&indio_dev->mlock);
	return ret;

out:
	palmas_gpadc_read_done(adc, adc_chan);
	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static int palmas_gpadc_get_adc_dt_data(struct platform_device *pdev,
	struct palmas_gpadc_platform_data **gpadc_pdata)
{
	struct device_node *np = pdev->dev.of_node;
	struct palmas_gpadc_platform_data *gp_data;
	int ret;
	u32 pval;

	gp_data = devm_kzalloc(&pdev->dev, sizeof(*gp_data), GFP_KERNEL);
	if (!gp_data)
		return -ENOMEM;

	ret = of_property_read_u32(np, "ti,channel0-current-microamp", &pval);
	if (!ret)
		gp_data->ch0_current = pval;

	ret = of_property_read_u32(np, "ti,channel3-current-microamp", &pval);
	if (!ret)
		gp_data->ch3_current = pval;

	gp_data->extended_delay = of_property_read_bool(np,
					"ti,enable-extended-delay");

	*gpadc_pdata = gp_data;

	return 0;
}

__attribute__((used)) static int palmas_gpadc_probe(struct platform_device *pdev)
{
	struct palmas_gpadc *adc;
	struct palmas_platform_data *pdata;
	struct palmas_gpadc_platform_data *gpadc_pdata = NULL;
	struct iio_dev *indio_dev;
	int ret, i;

	pdata = dev_get_platdata(pdev->dev.parent);

	if (pdata && pdata->gpadc_pdata)
		gpadc_pdata = pdata->gpadc_pdata;

	if (!gpadc_pdata && pdev->dev.of_node) {
		ret = palmas_gpadc_get_adc_dt_data(pdev, &gpadc_pdata);
		if (ret < 0)
			return ret;
	}
	if (!gpadc_pdata)
		return -EINVAL;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc));
	if (!indio_dev) {
		dev_err(&pdev->dev, "iio_device_alloc failed\n");
		return -ENOMEM;
	}

	adc = iio_priv(indio_dev);
	adc->dev = &pdev->dev;
	adc->palmas = dev_get_drvdata(pdev->dev.parent);
	adc->adc_info = palmas_gpadc_info;
	init_completion(&adc->conv_completion);
	dev_set_drvdata(&pdev->dev, indio_dev);

	adc->auto_conversion_period = gpadc_pdata->auto_conversion_period_ms;
	adc->irq = palmas_irq_get_virq(adc->palmas, PALMAS_GPADC_EOC_SW_IRQ);
	if (adc->irq < 0) {
		dev_err(adc->dev,
			"get virq failed: %d\n", adc->irq);
		ret = adc->irq;
		goto out;
	}
	ret = request_threaded_irq(adc->irq, NULL,
		palmas_gpadc_irq,
		IRQF_ONESHOT, dev_name(adc->dev),
		adc);
	if (ret < 0) {
		dev_err(adc->dev,
			"request irq %d failed: %d\n", adc->irq, ret);
		goto out;
	}

	if (gpadc_pdata->adc_wakeup1_data) {
		memcpy(&adc->wakeup1_data, gpadc_pdata->adc_wakeup1_data,
			sizeof(adc->wakeup1_data));
		adc->wakeup1_enable = true;
		adc->irq_auto_0 =  platform_get_irq(pdev, 1);
		ret = request_threaded_irq(adc->irq_auto_0, NULL,
				palmas_gpadc_irq_auto,
				IRQF_ONESHOT,
				"palmas-adc-auto-0", adc);
		if (ret < 0) {
			dev_err(adc->dev, "request auto0 irq %d failed: %d\n",
				adc->irq_auto_0, ret);
			goto out_irq_free;
		}
	}

	if (gpadc_pdata->adc_wakeup2_data) {
		memcpy(&adc->wakeup2_data, gpadc_pdata->adc_wakeup2_data,
				sizeof(adc->wakeup2_data));
		adc->wakeup2_enable = true;
		adc->irq_auto_1 =  platform_get_irq(pdev, 2);
		ret = request_threaded_irq(adc->irq_auto_1, NULL,
				palmas_gpadc_irq_auto,
				IRQF_ONESHOT,
				"palmas-adc-auto-1", adc);
		if (ret < 0) {
			dev_err(adc->dev, "request auto1 irq %d failed: %d\n",
				adc->irq_auto_1, ret);
			goto out_irq_auto0_free;
		}
	}

	/* set the current source 0 (value 0/5/15/20 uA => 0..3) */
	if (gpadc_pdata->ch0_current <= 1)
		adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_0;
	else if (gpadc_pdata->ch0_current <= 5)
		adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_5;
	else if (gpadc_pdata->ch0_current <= 15)
		adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_15;
	else
		adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_20;

	/* set the current source 3 (value 0/10/400/800 uA => 0..3) */
	if (gpadc_pdata->ch3_current <= 1)
		adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_0;
	else if (gpadc_pdata->ch3_current <= 10)
		adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_10;
	else if (gpadc_pdata->ch3_current <= 400)
		adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_400;
	else
		adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_800;

	adc->extended_delay = gpadc_pdata->extended_delay;

	indio_dev->name = MOD_NAME;
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->info = &palmas_gpadc_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = palmas_gpadc_iio_channel;
	indio_dev->num_channels = ARRAY_SIZE(palmas_gpadc_iio_channel);

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(adc->dev, "iio_device_register() failed: %d\n", ret);
		goto out_irq_auto1_free;
	}

	device_set_wakeup_capable(&pdev->dev, 1);
	for (i = 0; i < PALMAS_ADC_CH_MAX; i++) {
		if (!(adc->adc_info[i].is_uncalibrated))
			palmas_gpadc_calibrate(adc, i);
	}

	if (adc->wakeup1_enable || adc->wakeup2_enable)
		device_wakeup_enable(&pdev->dev);

	return 0;

out_irq_auto1_free:
	if (gpadc_pdata->adc_wakeup2_data)
		free_irq(adc->irq_auto_1, adc);
out_irq_auto0_free:
	if (gpadc_pdata->adc_wakeup1_data)
		free_irq(adc->irq_auto_0, adc);
out_irq_free:
	free_irq(adc->irq, adc);
out:
	return ret;
}

__attribute__((used)) static int palmas_gpadc_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(&pdev->dev);
	struct palmas_gpadc *adc = iio_priv(indio_dev);

	if (adc->wakeup1_enable || adc->wakeup2_enable)
		device_wakeup_disable(&pdev->dev);
	iio_device_unregister(indio_dev);
	free_irq(adc->irq, adc);
	if (adc->wakeup1_enable)
		free_irq(adc->irq_auto_0, adc);
	if (adc->wakeup2_enable)
		free_irq(adc->irq_auto_1, adc);

	return 0;
}


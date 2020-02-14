#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct stm32_lptimer {scalar_t__ has_encoder; int /*<<< orphan*/  clk; int /*<<< orphan*/  regmap; } ;
struct stm32_lptim_cnt {int preset; int quadrature_mode; int polarity; int /*<<< orphan*/  clk; int /*<<< orphan*/  regmap; TYPE_2__* dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/ * channels; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int FIELD_GET (int,int) ; 
 int FIELD_PREP (int,int) ; 
#define  IIO_CHAN_INFO_ENABLE 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 scalar_t__ IS_ERR_OR_NULL (struct stm32_lptimer*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  STM32_LPTIM_ARR ; 
 int /*<<< orphan*/  STM32_LPTIM_CFGR ; 
 int STM32_LPTIM_CKPOL ; 
 int /*<<< orphan*/  STM32_LPTIM_CMP ; 
 int STM32_LPTIM_CMPOKCF_ARROKCF ; 
 int STM32_LPTIM_CMPOK_ARROK ; 
 int /*<<< orphan*/  STM32_LPTIM_CNT ; 
 int STM32_LPTIM_CNTSTRT ; 
 int STM32_LPTIM_COUNTMODE ; 
 int /*<<< orphan*/  STM32_LPTIM_CR ; 
 int STM32_LPTIM_ENABLE ; 
 int STM32_LPTIM_ENC ; 
 int /*<<< orphan*/  STM32_LPTIM_ICR ; 
 int /*<<< orphan*/  STM32_LPTIM_ISR ; 
 scalar_t__ STM32_LPTIM_MAX_ARR ; 
 int STM32_LPTIM_PRESC ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int clk_enable (int /*<<< orphan*/ ) ; 
 struct stm32_lptimer* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 int devm_iio_device_register (TYPE_2__*,struct iio_dev*) ; 
 struct stm32_lptim_cnt* iio_priv (struct iio_dev*) ; 
 int kstrtouint (char const*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct stm32_lptim_cnt*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_read_poll_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  stm32_lptim_cnt_channels ; 
 int /*<<< orphan*/  stm32_lptim_cnt_iio_info ; 
 int /*<<< orphan*/  stm32_lptim_enc_channels ; 

__attribute__((used)) static int stm32_lptim_is_enabled(struct stm32_lptim_cnt *priv)
{
	u32 val;
	int ret;

	ret = regmap_read(priv->regmap, STM32_LPTIM_CR, &val);
	if (ret)
		return ret;

	return FIELD_GET(STM32_LPTIM_ENABLE, val);
}

__attribute__((used)) static int stm32_lptim_set_enable_state(struct stm32_lptim_cnt *priv,
					int enable)
{
	int ret;
	u32 val;

	val = FIELD_PREP(STM32_LPTIM_ENABLE, enable);
	ret = regmap_write(priv->regmap, STM32_LPTIM_CR, val);
	if (ret)
		return ret;

	if (!enable) {
		clk_disable(priv->clk);
		return 0;
	}

	/* LP timer must be enabled before writing CMP & ARR */
	ret = regmap_write(priv->regmap, STM32_LPTIM_ARR, priv->preset);
	if (ret)
		return ret;

	ret = regmap_write(priv->regmap, STM32_LPTIM_CMP, 0);
	if (ret)
		return ret;

	/* ensure CMP & ARR registers are properly written */
	ret = regmap_read_poll_timeout(priv->regmap, STM32_LPTIM_ISR, val,
				       (val & STM32_LPTIM_CMPOK_ARROK),
				       100, 1000);
	if (ret)
		return ret;

	ret = regmap_write(priv->regmap, STM32_LPTIM_ICR,
			   STM32_LPTIM_CMPOKCF_ARROKCF);
	if (ret)
		return ret;

	ret = clk_enable(priv->clk);
	if (ret) {
		regmap_write(priv->regmap, STM32_LPTIM_CR, 0);
		return ret;
	}

	/* Start LP timer in continuous mode */
	return regmap_update_bits(priv->regmap, STM32_LPTIM_CR,
				  STM32_LPTIM_CNTSTRT, STM32_LPTIM_CNTSTRT);
}

__attribute__((used)) static int stm32_lptim_setup(struct stm32_lptim_cnt *priv, int enable)
{
	u32 mask = STM32_LPTIM_ENC | STM32_LPTIM_COUNTMODE |
		   STM32_LPTIM_CKPOL | STM32_LPTIM_PRESC;
	u32 val;

	/* Setup LP timer encoder/counter and polarity, without prescaler */
	if (priv->quadrature_mode)
		val = enable ? STM32_LPTIM_ENC : 0;
	else
		val = enable ? STM32_LPTIM_COUNTMODE : 0;
	val |= FIELD_PREP(STM32_LPTIM_CKPOL, enable ? priv->polarity : 0);

	return regmap_update_bits(priv->regmap, STM32_LPTIM_CFGR, mask, val);
}

__attribute__((used)) static int stm32_lptim_write_raw(struct iio_dev *indio_dev,
				 struct iio_chan_spec const *chan,
				 int val, int val2, long mask)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_ENABLE:
		if (val < 0 || val > 1)
			return -EINVAL;

		/* Check nobody uses the timer, or already disabled/enabled */
		ret = stm32_lptim_is_enabled(priv);
		if ((ret < 0) || (!ret && !val))
			return ret;
		if (val && ret)
			return -EBUSY;

		ret = stm32_lptim_setup(priv, val);
		if (ret)
			return ret;
		return stm32_lptim_set_enable_state(priv, val);

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int stm32_lptim_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);
	u32 dat;
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = regmap_read(priv->regmap, STM32_LPTIM_CNT, &dat);
		if (ret)
			return ret;
		*val = dat;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_ENABLE:
		ret = stm32_lptim_is_enabled(priv);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		/* Non-quadrature mode: scale = 1 */
		*val = 1;
		*val2 = 0;
		if (priv->quadrature_mode) {
			/*
			 * Quadrature encoder mode:
			 * - both edges, quarter cycle, scale is 0.25
			 * - either rising/falling edge scale is 0.5
			 */
			if (priv->polarity > 1)
				*val2 = 2;
			else
				*val2 = 1;
		}
		return IIO_VAL_FRACTIONAL_LOG2;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int stm32_lptim_get_quadrature_mode(struct iio_dev *indio_dev,
					   const struct iio_chan_spec *chan)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);

	return priv->quadrature_mode;
}

__attribute__((used)) static int stm32_lptim_set_quadrature_mode(struct iio_dev *indio_dev,
					   const struct iio_chan_spec *chan,
					   unsigned int type)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);

	if (stm32_lptim_is_enabled(priv))
		return -EBUSY;

	priv->quadrature_mode = type;

	return 0;
}

__attribute__((used)) static int stm32_lptim_cnt_get_polarity(struct iio_dev *indio_dev,
					const struct iio_chan_spec *chan)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);

	return priv->polarity;
}

__attribute__((used)) static int stm32_lptim_cnt_set_polarity(struct iio_dev *indio_dev,
					const struct iio_chan_spec *chan,
					unsigned int type)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);

	if (stm32_lptim_is_enabled(priv))
		return -EBUSY;

	priv->polarity = type;

	return 0;
}

__attribute__((used)) static ssize_t stm32_lptim_cnt_get_preset(struct iio_dev *indio_dev,
					  uintptr_t private,
					  const struct iio_chan_spec *chan,
					  char *buf)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);

	return snprintf(buf, PAGE_SIZE, "%u\n", priv->preset);
}

__attribute__((used)) static ssize_t stm32_lptim_cnt_set_preset(struct iio_dev *indio_dev,
					  uintptr_t private,
					  const struct iio_chan_spec *chan,
					  const char *buf, size_t len)
{
	struct stm32_lptim_cnt *priv = iio_priv(indio_dev);
	int ret;

	if (stm32_lptim_is_enabled(priv))
		return -EBUSY;

	ret = kstrtouint(buf, 0, &priv->preset);
	if (ret)
		return ret;

	if (priv->preset > STM32_LPTIM_MAX_ARR)
		return -EINVAL;

	return len;
}

__attribute__((used)) static int stm32_lptim_cnt_probe(struct platform_device *pdev)
{
	struct stm32_lptimer *ddata = dev_get_drvdata(pdev->dev.parent);
	struct stm32_lptim_cnt *priv;
	struct iio_dev *indio_dev;

	if (IS_ERR_OR_NULL(ddata))
		return -EINVAL;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*priv));
	if (!indio_dev)
		return -ENOMEM;

	priv = iio_priv(indio_dev);
	priv->dev = &pdev->dev;
	priv->regmap = ddata->regmap;
	priv->clk = ddata->clk;
	priv->preset = STM32_LPTIM_MAX_ARR;

	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->dev.of_node = pdev->dev.of_node;
	indio_dev->info = &stm32_lptim_cnt_iio_info;
	if (ddata->has_encoder)
		indio_dev->channels = &stm32_lptim_enc_channels;
	else
		indio_dev->channels = &stm32_lptim_cnt_channels;
	indio_dev->num_channels = 1;

	platform_set_drvdata(pdev, priv);

	return devm_iio_device_register(&pdev->dev, indio_dev);
}


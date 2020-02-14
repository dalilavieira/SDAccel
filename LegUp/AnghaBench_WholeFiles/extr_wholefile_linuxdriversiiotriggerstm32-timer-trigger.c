#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct stm32_timers {unsigned long long max_arr; int /*<<< orphan*/  clk; int /*<<< orphan*/  regmap; } ;
struct stm32_timer_trigger_cfg {unsigned int num_valids_table; char*** valids_table; } ;
struct stm32_timer_trigger {unsigned long long max_arr; char** triggers; int has_trgo2; char** valids; int /*<<< orphan*/  clk; int /*<<< orphan*/  regmap; struct device* dev; } ;
struct device {TYPE_3__* driver; int /*<<< orphan*/  of_node; struct device* parent; } ;
struct platform_device {struct device dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  groups; struct device* parent; } ;
struct iio_trigger {char* name; int /*<<< orphan*/ * ops; TYPE_1__ dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; struct device* parent; } ;
struct iio_dev {int num_channels; TYPE_2__ dev; int /*<<< orphan*/ * channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_8__ {scalar_t__ data; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_match_table; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (char***) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IIO_CHAN_INFO_ENABLE 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_HARDWARE_TRIGGERED ; 
 void* MASTER_MODE2_MAX ; 
 void* MASTER_MODE_MAX ; 
 int MAX_TIM_PSC ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  TIM_ARR ; 
 int /*<<< orphan*/  TIM_CCER ; 
 int TIM_CCER_CCXE ; 
 int /*<<< orphan*/  TIM_CNT ; 
 int /*<<< orphan*/  TIM_CR1 ; 
 int TIM_CR1_ARPE ; 
 int TIM_CR1_CEN ; 
 int TIM_CR1_DIR ; 
 int /*<<< orphan*/  TIM_CR2 ; 
 int TIM_CR2_MMS ; 
 int TIM_CR2_MMS2 ; 
 int TIM_CR2_MMS2_SHIFT ; 
 int TIM_CR2_MMS_SHIFT ; 
 int /*<<< orphan*/  TIM_EGR ; 
 int TIM_EGR_UG ; 
 int /*<<< orphan*/  TIM_PSC ; 
 int /*<<< orphan*/  TIM_SMCR ; 
 int TIM_SMCR_SMS ; 
 int TIM_SMCR_TS ; 
 unsigned int TIM_SMCR_TS_SHIFT ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 scalar_t__ clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 struct iio_trigger* devm_iio_trigger_alloc (struct device*,char*,char const* const) ; 
 int devm_iio_trigger_register (struct device*,struct iio_trigger*) ; 
 struct stm32_timer_trigger* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (unsigned long long,int) ; 
 struct stm32_timer_trigger* iio_priv (struct iio_dev*) ; 
 struct stm32_timer_trigger* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct stm32_timer_trigger*) ; 
 int is_stm32_timer_trigger (struct iio_trigger*) ; 
 int kstrtouint (char const*,int,unsigned int*) ; 
 char** master_mode_table ; 
 TYPE_4__* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,unsigned int*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct stm32_timer_trigger*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,char*) ; 
 int snprintf (char*,scalar_t__,char*,...) ; 
 int sprintf (char*,char*,unsigned int) ; 
 char*** stm32_quadrature_modes ; 
 int /*<<< orphan*/  stm32_trigger_attr_groups ; 
 int /*<<< orphan*/  stm32_trigger_channel ; 
 int /*<<< orphan*/  stm32_trigger_info ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  strncmp (char*,char const* const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strstr (char const*,char*) ; 
 int /*<<< orphan*/  timer_trigger_ops ; 
 struct iio_trigger* to_iio_trigger (struct device*) ; 
 char*** triggers_table ; 

__attribute__((used)) static bool stm32_timer_is_trgo2_name(const char *name)
{
	return !!strstr(name, "trgo2");
}

__attribute__((used)) static bool stm32_timer_is_trgo_name(const char *name)
{
	return (!!strstr(name, "trgo") && !strstr(name, "trgo2"));
}

__attribute__((used)) static int stm32_timer_start(struct stm32_timer_trigger *priv,
			     struct iio_trigger *trig,
			     unsigned int frequency)
{
	unsigned long long prd, div;
	int prescaler = 0;
	u32 ccer, cr1;

	/* Period and prescaler values depends of clock rate */
	div = (unsigned long long)clk_get_rate(priv->clk);

	do_div(div, frequency);

	prd = div;

	/*
	 * Increase prescaler value until we get a result that fit
	 * with auto reload register maximum value.
	 */
	while (div > priv->max_arr) {
		prescaler++;
		div = prd;
		do_div(div, (prescaler + 1));
	}
	prd = div;

	if (prescaler > MAX_TIM_PSC) {
		dev_err(priv->dev, "prescaler exceeds the maximum value\n");
		return -EINVAL;
	}

	/* Check if nobody else use the timer */
	regmap_read(priv->regmap, TIM_CCER, &ccer);
	if (ccer & TIM_CCER_CCXE)
		return -EBUSY;

	regmap_read(priv->regmap, TIM_CR1, &cr1);
	if (!(cr1 & TIM_CR1_CEN))
		clk_enable(priv->clk);

	regmap_write(priv->regmap, TIM_PSC, prescaler);
	regmap_write(priv->regmap, TIM_ARR, prd - 1);
	regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_ARPE, TIM_CR1_ARPE);

	/* Force master mode to update mode */
	if (stm32_timer_is_trgo2_name(trig->name))
		regmap_update_bits(priv->regmap, TIM_CR2, TIM_CR2_MMS2,
				   0x2 << TIM_CR2_MMS2_SHIFT);
	else
		regmap_update_bits(priv->regmap, TIM_CR2, TIM_CR2_MMS,
				   0x2 << TIM_CR2_MMS_SHIFT);

	/* Make sure that registers are updated */
	regmap_update_bits(priv->regmap, TIM_EGR, TIM_EGR_UG, TIM_EGR_UG);

	/* Enable controller */
	regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_CEN, TIM_CR1_CEN);

	return 0;
}

__attribute__((used)) static void stm32_timer_stop(struct stm32_timer_trigger *priv)
{
	u32 ccer, cr1;

	regmap_read(priv->regmap, TIM_CCER, &ccer);
	if (ccer & TIM_CCER_CCXE)
		return;

	regmap_read(priv->regmap, TIM_CR1, &cr1);
	if (cr1 & TIM_CR1_CEN)
		clk_disable(priv->clk);

	/* Stop timer */
	regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_ARPE, 0);
	regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_CEN, 0);
	regmap_write(priv->regmap, TIM_PSC, 0);
	regmap_write(priv->regmap, TIM_ARR, 0);

	/* Make sure that registers are updated */
	regmap_update_bits(priv->regmap, TIM_EGR, TIM_EGR_UG, TIM_EGR_UG);
}

__attribute__((used)) static ssize_t stm32_tt_store_frequency(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t len)
{
	struct iio_trigger *trig = to_iio_trigger(dev);
	struct stm32_timer_trigger *priv = iio_trigger_get_drvdata(trig);
	unsigned int freq;
	int ret;

	ret = kstrtouint(buf, 10, &freq);
	if (ret)
		return ret;

	if (freq == 0) {
		stm32_timer_stop(priv);
	} else {
		ret = stm32_timer_start(priv, trig, freq);
		if (ret)
			return ret;
	}

	return len;
}

__attribute__((used)) static ssize_t stm32_tt_read_frequency(struct device *dev,
				       struct device_attribute *attr, char *buf)
{
	struct iio_trigger *trig = to_iio_trigger(dev);
	struct stm32_timer_trigger *priv = iio_trigger_get_drvdata(trig);
	u32 psc, arr, cr1;
	unsigned long long freq = 0;

	regmap_read(priv->regmap, TIM_CR1, &cr1);
	regmap_read(priv->regmap, TIM_PSC, &psc);
	regmap_read(priv->regmap, TIM_ARR, &arr);

	if (cr1 & TIM_CR1_CEN) {
		freq = (unsigned long long)clk_get_rate(priv->clk);
		do_div(freq, psc + 1);
		do_div(freq, arr + 1);
	}

	return sprintf(buf, "%d\n", (unsigned int)freq);
}

__attribute__((used)) static ssize_t stm32_tt_show_master_mode(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	struct stm32_timer_trigger *priv = dev_get_drvdata(dev);
	struct iio_trigger *trig = to_iio_trigger(dev);
	u32 cr2;

	regmap_read(priv->regmap, TIM_CR2, &cr2);

	if (stm32_timer_is_trgo2_name(trig->name))
		cr2 = (cr2 & TIM_CR2_MMS2) >> TIM_CR2_MMS2_SHIFT;
	else
		cr2 = (cr2 & TIM_CR2_MMS) >> TIM_CR2_MMS_SHIFT;

	return snprintf(buf, PAGE_SIZE, "%s\n", master_mode_table[cr2]);
}

__attribute__((used)) static ssize_t stm32_tt_store_master_mode(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t len)
{
	struct stm32_timer_trigger *priv = dev_get_drvdata(dev);
	struct iio_trigger *trig = to_iio_trigger(dev);
	u32 mask, shift, master_mode_max;
	int i;

	if (stm32_timer_is_trgo2_name(trig->name)) {
		mask = TIM_CR2_MMS2;
		shift = TIM_CR2_MMS2_SHIFT;
		master_mode_max = MASTER_MODE2_MAX;
	} else {
		mask = TIM_CR2_MMS;
		shift = TIM_CR2_MMS_SHIFT;
		master_mode_max = MASTER_MODE_MAX;
	}

	for (i = 0; i <= master_mode_max; i++) {
		if (!strncmp(master_mode_table[i], buf,
			     strlen(master_mode_table[i]))) {
			regmap_update_bits(priv->regmap, TIM_CR2, mask,
					   i << shift);
			/* Make sure that registers are updated */
			regmap_update_bits(priv->regmap, TIM_EGR,
					   TIM_EGR_UG, TIM_EGR_UG);
			return len;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static ssize_t stm32_tt_show_master_mode_avail(struct device *dev,
					       struct device_attribute *attr,
					       char *buf)
{
	struct iio_trigger *trig = to_iio_trigger(dev);
	unsigned int i, master_mode_max;
	size_t len = 0;

	if (stm32_timer_is_trgo2_name(trig->name))
		master_mode_max = MASTER_MODE2_MAX;
	else
		master_mode_max = MASTER_MODE_MAX;

	for (i = 0; i <= master_mode_max; i++)
		len += scnprintf(buf + len, PAGE_SIZE - len,
			"%s ", master_mode_table[i]);

	/* replace trailing space by newline */
	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static int stm32_setup_iio_triggers(struct stm32_timer_trigger *priv)
{
	int ret;
	const char * const *cur = priv->triggers;

	while (cur && *cur) {
		struct iio_trigger *trig;
		bool cur_is_trgo = stm32_timer_is_trgo_name(*cur);
		bool cur_is_trgo2 = stm32_timer_is_trgo2_name(*cur);

		if (cur_is_trgo2 && !priv->has_trgo2) {
			cur++;
			continue;
		}

		trig = devm_iio_trigger_alloc(priv->dev, "%s", *cur);
		if  (!trig)
			return -ENOMEM;

		trig->dev.parent = priv->dev->parent;
		trig->ops = &timer_trigger_ops;

		/*
		 * sampling frequency and master mode attributes
		 * should only be available on trgo/trgo2 triggers
		 */
		if (cur_is_trgo || cur_is_trgo2)
			trig->dev.groups = stm32_trigger_attr_groups;

		iio_trigger_set_drvdata(trig, priv);

		ret = devm_iio_trigger_register(priv->dev, trig);
		if (ret)
			return ret;
		cur++;
	}

	return 0;
}

__attribute__((used)) static int stm32_counter_read_raw(struct iio_dev *indio_dev,
				  struct iio_chan_spec const *chan,
				  int *val, int *val2, long mask)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 dat;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		regmap_read(priv->regmap, TIM_CNT, &dat);
		*val = dat;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_ENABLE:
		regmap_read(priv->regmap, TIM_CR1, &dat);
		*val = (dat & TIM_CR1_CEN) ? 1 : 0;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		regmap_read(priv->regmap, TIM_SMCR, &dat);
		dat &= TIM_SMCR_SMS;

		*val = 1;
		*val2 = 0;

		/* in quadrature case scale = 0.25 */
		if (dat == 3)
			*val2 = 2;

		return IIO_VAL_FRACTIONAL_LOG2;
	}

	return -EINVAL;
}

__attribute__((used)) static int stm32_counter_write_raw(struct iio_dev *indio_dev,
				   struct iio_chan_spec const *chan,
				   int val, int val2, long mask)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 dat;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return regmap_write(priv->regmap, TIM_CNT, val);

	case IIO_CHAN_INFO_SCALE:
		/* fixed scale */
		return -EINVAL;

	case IIO_CHAN_INFO_ENABLE:
		if (val) {
			regmap_read(priv->regmap, TIM_CR1, &dat);
			if (!(dat & TIM_CR1_CEN))
				clk_enable(priv->clk);
			regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_CEN,
					   TIM_CR1_CEN);
		} else {
			regmap_read(priv->regmap, TIM_CR1, &dat);
			regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_CEN,
					   0);
			if (dat & TIM_CR1_CEN)
				clk_disable(priv->clk);
		}
		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int stm32_counter_validate_trigger(struct iio_dev *indio_dev,
					  struct iio_trigger *trig)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	const char * const *cur = priv->valids;
	unsigned int i = 0;

	if (!is_stm32_timer_trigger(trig))
		return -EINVAL;

	while (cur && *cur) {
		if (!strncmp(trig->name, *cur, strlen(trig->name))) {
			regmap_update_bits(priv->regmap,
					   TIM_SMCR, TIM_SMCR_TS,
					   i << TIM_SMCR_TS_SHIFT);
			return 0;
		}
		cur++;
		i++;
	}

	return -EINVAL;
}

__attribute__((used)) static int stm32_set_trigger_mode(struct iio_dev *indio_dev,
				  const struct iio_chan_spec *chan,
				  unsigned int mode)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);

	regmap_update_bits(priv->regmap, TIM_SMCR, TIM_SMCR_SMS, TIM_SMCR_SMS);

	return 0;
}

__attribute__((used)) static int stm32_get_trigger_mode(struct iio_dev *indio_dev,
				  const struct iio_chan_spec *chan)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 smcr;

	regmap_read(priv->regmap, TIM_SMCR, &smcr);

	return (smcr & TIM_SMCR_SMS) == TIM_SMCR_SMS ? 0 : -EINVAL;
}

__attribute__((used)) static int stm32_enable_mode2sms(int mode)
{
	switch (mode) {
	case 0:
		return 0;
	case 1:
		return 5;
	case 2:
		return 6;
	}

	return -EINVAL;
}

__attribute__((used)) static int stm32_set_enable_mode(struct iio_dev *indio_dev,
				 const struct iio_chan_spec *chan,
				 unsigned int mode)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	int sms = stm32_enable_mode2sms(mode);
	u32 val;

	if (sms < 0)
		return sms;
	/*
	 * Triggered mode sets CEN bit automatically by hardware. So, first
	 * enable counter clock, so it can use it. Keeps it in sync with CEN.
	 */
	if (sms == 6) {
		regmap_read(priv->regmap, TIM_CR1, &val);
		if (!(val & TIM_CR1_CEN))
			clk_enable(priv->clk);
	}

	regmap_update_bits(priv->regmap, TIM_SMCR, TIM_SMCR_SMS, sms);

	return 0;
}

__attribute__((used)) static int stm32_sms2enable_mode(int mode)
{
	switch (mode) {
	case 0:
		return 0;
	case 5:
		return 1;
	case 6:
		return 2;
	}

	return -EINVAL;
}

__attribute__((used)) static int stm32_get_enable_mode(struct iio_dev *indio_dev,
				 const struct iio_chan_spec *chan)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 smcr;

	regmap_read(priv->regmap, TIM_SMCR, &smcr);
	smcr &= TIM_SMCR_SMS;

	return stm32_sms2enable_mode(smcr);
}

__attribute__((used)) static int stm32_set_quadrature_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     unsigned int mode)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);

	regmap_update_bits(priv->regmap, TIM_SMCR, TIM_SMCR_SMS, mode + 1);

	return 0;
}

__attribute__((used)) static int stm32_get_quadrature_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 smcr;
	int mode;

	regmap_read(priv->regmap, TIM_SMCR, &smcr);
	mode = (smcr & TIM_SMCR_SMS) - 1;
	if ((mode < 0) || (mode > ARRAY_SIZE(stm32_quadrature_modes)))
		return -EINVAL;

	return mode;
}

__attribute__((used)) static int stm32_set_count_direction(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     unsigned int dir)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 val;
	int mode;

	/* In encoder mode, direction is RO (given by TI1/TI2 signals) */
	regmap_read(priv->regmap, TIM_SMCR, &val);
	mode = (val & TIM_SMCR_SMS) - 1;
	if ((mode >= 0) || (mode < ARRAY_SIZE(stm32_quadrature_modes)))
		return -EBUSY;

	return regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_DIR,
				  dir ? TIM_CR1_DIR : 0);
}

__attribute__((used)) static int stm32_get_count_direction(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 cr1;

	regmap_read(priv->regmap, TIM_CR1, &cr1);

	return ((cr1 & TIM_CR1_DIR) ? 1 : 0);
}

__attribute__((used)) static ssize_t stm32_count_get_preset(struct iio_dev *indio_dev,
				      uintptr_t private,
				      const struct iio_chan_spec *chan,
				      char *buf)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	u32 arr;

	regmap_read(priv->regmap, TIM_ARR, &arr);

	return snprintf(buf, PAGE_SIZE, "%u\n", arr);
}

__attribute__((used)) static ssize_t stm32_count_set_preset(struct iio_dev *indio_dev,
				      uintptr_t private,
				      const struct iio_chan_spec *chan,
				      const char *buf, size_t len)
{
	struct stm32_timer_trigger *priv = iio_priv(indio_dev);
	unsigned int preset;
	int ret;

	ret = kstrtouint(buf, 0, &preset);
	if (ret)
		return ret;

	/* TIMx_ARR register shouldn't be buffered (ARPE=0) */
	regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_ARPE, 0);
	regmap_write(priv->regmap, TIM_ARR, preset);

	return len;
}

__attribute__((used)) static struct stm32_timer_trigger *stm32_setup_counter_device(struct device *dev)
{
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(dev,
					  sizeof(struct stm32_timer_trigger));
	if (!indio_dev)
		return NULL;

	indio_dev->name = dev_name(dev);
	indio_dev->dev.parent = dev;
	indio_dev->info = &stm32_trigger_info;
	indio_dev->modes = INDIO_HARDWARE_TRIGGERED;
	indio_dev->num_channels = 1;
	indio_dev->channels = &stm32_trigger_channel;
	indio_dev->dev.of_node = dev->of_node;

	ret = devm_iio_device_register(dev, indio_dev);
	if (ret)
		return NULL;

	return iio_priv(indio_dev);
}

bool is_stm32_timer_trigger(struct iio_trigger *trig)
{
	return (trig->ops == &timer_trigger_ops);
}

__attribute__((used)) static void stm32_timer_detect_trgo2(struct stm32_timer_trigger *priv)
{
	u32 val;

	/*
	 * Master mode selection 2 bits can only be written and read back when
	 * timer supports it.
	 */
	regmap_update_bits(priv->regmap, TIM_CR2, TIM_CR2_MMS2, TIM_CR2_MMS2);
	regmap_read(priv->regmap, TIM_CR2, &val);
	regmap_update_bits(priv->regmap, TIM_CR2, TIM_CR2_MMS2, 0);
	priv->has_trgo2 = !!val;
}

__attribute__((used)) static int stm32_timer_trigger_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct stm32_timer_trigger *priv;
	struct stm32_timers *ddata = dev_get_drvdata(pdev->dev.parent);
	const struct stm32_timer_trigger_cfg *cfg;
	unsigned int index;
	int ret;

	if (of_property_read_u32(dev->of_node, "reg", &index))
		return -EINVAL;

	cfg = (const struct stm32_timer_trigger_cfg *)
		of_match_device(dev->driver->of_match_table, dev)->data;

	if (index >= ARRAY_SIZE(triggers_table) ||
	    index >= cfg->num_valids_table)
		return -EINVAL;

	/* Create an IIO device only if we have triggers to be validated */
	if (*cfg->valids_table[index])
		priv = stm32_setup_counter_device(dev);
	else
		priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);

	if (!priv)
		return -ENOMEM;

	priv->dev = dev;
	priv->regmap = ddata->regmap;
	priv->clk = ddata->clk;
	priv->max_arr = ddata->max_arr;
	priv->triggers = triggers_table[index];
	priv->valids = cfg->valids_table[index];
	stm32_timer_detect_trgo2(priv);

	ret = stm32_setup_iio_triggers(priv);
	if (ret)
		return ret;

	platform_set_drvdata(pdev, priv);

	return 0;
}


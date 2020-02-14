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
typedef  int u8 ;
typedef  int u16 ;
struct ts_nbus {int /*<<< orphan*/  lock; struct pwm_device* pwm; struct pwm_device* csn; struct pwm_device* rdy; struct pwm_device* txrx; struct pwm_device* ale; struct pwm_device* data; struct pwm_device* strobe; } ;
struct pwm_device {struct pwm_device** desc; } ;
struct pwm_args {int /*<<< orphan*/  period; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct gpio_descs {struct gpio_descs** desc; } ;

/* Variables and functions */
 int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (struct pwm_device*) ; 
 int PTR_ERR (struct pwm_device*) ; 
 int TS_NBUS_DIRECTION_IN ; 
 int TS_NBUS_DIRECTION_OUT ; 
 int TS_NBUS_WRITE_ADR ; 
 int TS_NBUS_WRITE_VAL ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ts_nbus* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ts_nbus*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct pwm_device* devm_gpiod_get_array (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct ts_nbus* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct pwm_device* devm_pwm_get (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gpiod_direction_input (struct pwm_device*) ; 
 int /*<<< orphan*/  gpiod_direction_output (struct pwm_device*,int) ; 
 scalar_t__ gpiod_get_value_cansleep (struct pwm_device*) ; 
 int /*<<< orphan*/  gpiod_set_array_value_cansleep (int,struct pwm_device**,int*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (struct pwm_device*,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int of_platform_populate (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct device*) ; 
 int /*<<< orphan*/  pwm_apply_args (struct pwm_device*) ; 
 int pwm_config (struct pwm_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pwm_disable (struct pwm_device*) ; 
 int /*<<< orphan*/  pwm_enable (struct pwm_device*) ; 
 int /*<<< orphan*/  pwm_get_args (struct pwm_device*,struct pwm_args*) ; 

__attribute__((used)) static int ts_nbus_init_pdata(struct platform_device *pdev, struct ts_nbus
		*ts_nbus)
{
	ts_nbus->data = devm_gpiod_get_array(&pdev->dev, "ts,data",
			GPIOD_OUT_HIGH);
	if (IS_ERR(ts_nbus->data)) {
		dev_err(&pdev->dev, "failed to retrieve ts,data-gpio from dts\n");
		return PTR_ERR(ts_nbus->data);
	}

	ts_nbus->csn = devm_gpiod_get(&pdev->dev, "ts,csn", GPIOD_OUT_HIGH);
	if (IS_ERR(ts_nbus->csn)) {
		dev_err(&pdev->dev, "failed to retrieve ts,csn-gpio from dts\n");
		return PTR_ERR(ts_nbus->csn);
	}

	ts_nbus->txrx = devm_gpiod_get(&pdev->dev, "ts,txrx", GPIOD_OUT_HIGH);
	if (IS_ERR(ts_nbus->txrx)) {
		dev_err(&pdev->dev, "failed to retrieve ts,txrx-gpio from dts\n");
		return PTR_ERR(ts_nbus->txrx);
	}

	ts_nbus->strobe = devm_gpiod_get(&pdev->dev, "ts,strobe", GPIOD_OUT_HIGH);
	if (IS_ERR(ts_nbus->strobe)) {
		dev_err(&pdev->dev, "failed to retrieve ts,strobe-gpio from dts\n");
		return PTR_ERR(ts_nbus->strobe);
	}

	ts_nbus->ale = devm_gpiod_get(&pdev->dev, "ts,ale", GPIOD_OUT_HIGH);
	if (IS_ERR(ts_nbus->ale)) {
		dev_err(&pdev->dev, "failed to retrieve ts,ale-gpio from dts\n");
		return PTR_ERR(ts_nbus->ale);
	}

	ts_nbus->rdy = devm_gpiod_get(&pdev->dev, "ts,rdy", GPIOD_IN);
	if (IS_ERR(ts_nbus->rdy)) {
		dev_err(&pdev->dev, "failed to retrieve ts,rdy-gpio from dts\n");
		return PTR_ERR(ts_nbus->rdy);
	}

	return 0;
}

__attribute__((used)) static void ts_nbus_set_direction(struct ts_nbus *ts_nbus, int direction)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (direction == TS_NBUS_DIRECTION_IN)
			gpiod_direction_input(ts_nbus->data->desc[i]);
		else
			/* when used as output the default state of the data
			 * lines are set to high */
			gpiod_direction_output(ts_nbus->data->desc[i], 1);
	}
}

__attribute__((used)) static void ts_nbus_reset_bus(struct ts_nbus *ts_nbus)
{
	int i;
	int values[8];

	for (i = 0; i < 8; i++)
		values[i] = 0;

	gpiod_set_array_value_cansleep(8, ts_nbus->data->desc, values);
	gpiod_set_value_cansleep(ts_nbus->csn, 0);
	gpiod_set_value_cansleep(ts_nbus->strobe, 0);
	gpiod_set_value_cansleep(ts_nbus->ale, 0);
}

__attribute__((used)) static void ts_nbus_start_transaction(struct ts_nbus *ts_nbus)
{
	gpiod_set_value_cansleep(ts_nbus->strobe, 1);
}

__attribute__((used)) static int ts_nbus_read_byte(struct ts_nbus *ts_nbus, u8 *val)
{
	struct gpio_descs *gpios = ts_nbus->data;
	int ret, i;

	*val = 0;
	for (i = 0; i < 8; i++) {
		ret = gpiod_get_value_cansleep(gpios->desc[i]);
		if (ret < 0)
			return ret;
		if (ret)
			*val |= BIT(i);
	}

	return 0;
}

__attribute__((used)) static void ts_nbus_write_byte(struct ts_nbus *ts_nbus, u8 byte)
{
	struct gpio_descs *gpios = ts_nbus->data;
	int i;
	int values[8];

	for (i = 0; i < 8; i++)
		if (byte & BIT(i))
			values[i] = 1;
		else
			values[i] = 0;

	gpiod_set_array_value_cansleep(8, gpios->desc, values);
}

__attribute__((used)) static int ts_nbus_read_bus(struct ts_nbus *ts_nbus, u8 *val)
{
	ts_nbus_reset_bus(ts_nbus);
	ts_nbus_start_transaction(ts_nbus);

	return ts_nbus_read_byte(ts_nbus, val);
}

__attribute__((used)) static void ts_nbus_write_bus(struct ts_nbus *ts_nbus, int cmd, u8 val)
{
	ts_nbus_reset_bus(ts_nbus);

	if (cmd == TS_NBUS_WRITE_ADR)
		gpiod_set_value_cansleep(ts_nbus->ale, 1);

	ts_nbus_write_byte(ts_nbus, val);
	ts_nbus_start_transaction(ts_nbus);
}

int ts_nbus_read(struct ts_nbus *ts_nbus, u8 adr, u16 *val)
{
	int ret, i;
	u8 byte;

	/* bus access must be atomic */
	mutex_lock(&ts_nbus->lock);

	/* set the bus in read mode */
	gpiod_set_value_cansleep(ts_nbus->txrx, 0);

	/* write address */
	ts_nbus_write_bus(ts_nbus, TS_NBUS_WRITE_ADR, adr);

	/* set the data gpios direction as input before reading */
	ts_nbus_set_direction(ts_nbus, TS_NBUS_DIRECTION_IN);

	/* reading value MSB first */
	do {
		*val = 0;
		byte = 0;
		for (i = 1; i >= 0; i--) {
			/* read a byte from the bus, leave on error */
			ret = ts_nbus_read_bus(ts_nbus, &byte);
			if (ret < 0)
				goto err;

			/* append the byte read to the final value */
			*val |= byte << (i * 8);
		}
		gpiod_set_value_cansleep(ts_nbus->csn, 1);
		ret = gpiod_get_value_cansleep(ts_nbus->rdy);
	} while (ret);

err:
	/* restore the data gpios direction as output after reading */
	ts_nbus_set_direction(ts_nbus, TS_NBUS_DIRECTION_OUT);

	mutex_unlock(&ts_nbus->lock);

	return ret;
}

int ts_nbus_write(struct ts_nbus *ts_nbus, u8 adr, u16 val)
{
	int i;

	/* bus access must be atomic */
	mutex_lock(&ts_nbus->lock);

	/* set the bus in write mode */
	gpiod_set_value_cansleep(ts_nbus->txrx, 1);

	/* write address */
	ts_nbus_write_bus(ts_nbus, TS_NBUS_WRITE_ADR, adr);

	/* writing value MSB first */
	for (i = 1; i >= 0; i--)
		ts_nbus_write_bus(ts_nbus, TS_NBUS_WRITE_VAL, (u8)(val >> (i * 8)));

	/* wait for completion */
	gpiod_set_value_cansleep(ts_nbus->csn, 1);
	while (gpiod_get_value_cansleep(ts_nbus->rdy) != 0) {
		gpiod_set_value_cansleep(ts_nbus->csn, 0);
		gpiod_set_value_cansleep(ts_nbus->csn, 1);
	}

	mutex_unlock(&ts_nbus->lock);

	return 0;
}

__attribute__((used)) static int ts_nbus_probe(struct platform_device *pdev)
{
	struct pwm_device *pwm;
	struct pwm_args pargs;
	struct device *dev = &pdev->dev;
	struct ts_nbus *ts_nbus;
	int ret;

	ts_nbus = devm_kzalloc(dev, sizeof(*ts_nbus), GFP_KERNEL);
	if (!ts_nbus)
		return -ENOMEM;

	mutex_init(&ts_nbus->lock);

	ret = ts_nbus_init_pdata(pdev, ts_nbus);
	if (ret < 0)
		return ret;

	pwm = devm_pwm_get(dev, NULL);
	if (IS_ERR(pwm)) {
		ret = PTR_ERR(pwm);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "unable to request PWM\n");
		return ret;
	}

	pwm_get_args(pwm, &pargs);
	if (!pargs.period) {
		dev_err(&pdev->dev, "invalid PWM period\n");
		return -EINVAL;
	}

	/*
	 * FIXME: pwm_apply_args() should be removed when switching to
	 * the atomic PWM API.
	 */
	pwm_apply_args(pwm);
	ret = pwm_config(pwm, pargs.period, pargs.period);
	if (ret < 0)
		return ret;

	/*
	 * we can now start the FPGA and populate the peripherals.
	 */
	pwm_enable(pwm);
	ts_nbus->pwm = pwm;

	/*
	 * let the child nodes retrieve this instance of the ts-nbus.
	 */
	dev_set_drvdata(dev, ts_nbus);

	ret = of_platform_populate(dev->of_node, NULL, NULL, dev);
	if (ret < 0)
		return ret;

	dev_info(dev, "initialized\n");

	return 0;
}

__attribute__((used)) static int ts_nbus_remove(struct platform_device *pdev)
{
	struct ts_nbus *ts_nbus = dev_get_drvdata(&pdev->dev);

	/* shutdown the FPGA */
	mutex_lock(&ts_nbus->lock);
	pwm_disable(ts_nbus->pwm);
	mutex_unlock(&ts_nbus->lock);

	return 0;
}


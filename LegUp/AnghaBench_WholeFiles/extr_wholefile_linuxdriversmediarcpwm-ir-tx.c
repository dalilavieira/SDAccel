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
typedef  void* u32 ;
struct rc_dev {int (* tx_ir ) (struct rc_dev*,unsigned int*,unsigned int) ;int (* s_tx_duty_cycle ) (struct rc_dev*,void*) ;int (* s_tx_carrier ) (struct rc_dev*,void*) ;int /*<<< orphan*/  device_name; int /*<<< orphan*/  driver_name; struct pwm_ir* priv; } ;
struct pwm_ir {int duty_cycle; int carrier; struct pwm_device* pwm; } ;
struct pwm_device {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  ktime_t ;

/* Variables and functions */
 int /*<<< orphan*/  DEVICE_NAME ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct pwm_device*) ; 
 int NSEC_PER_SEC ; 
 int PTR_ERR (struct pwm_device*) ; 
 int /*<<< orphan*/  RC_DRIVER_IR_RAW_TX ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct pwm_ir* devm_kmalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct pwm_device* devm_pwm_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct rc_dev* devm_rc_allocate_device (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int devm_rc_register_device (int /*<<< orphan*/ *,struct rc_dev*) ; 
 int /*<<< orphan*/  ktime_add_us (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  ktime_get () ; 
 long ktime_us_delta (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pwm_config (struct pwm_device*,int,int) ; 
 int /*<<< orphan*/  pwm_disable (struct pwm_device*) ; 
 int /*<<< orphan*/  pwm_enable (struct pwm_device*) ; 
 int /*<<< orphan*/  usleep_range (long,long) ; 

__attribute__((used)) static int pwm_ir_set_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
	struct pwm_ir *pwm_ir = dev->priv;

	pwm_ir->duty_cycle = duty_cycle;

	return 0;
}

__attribute__((used)) static int pwm_ir_set_carrier(struct rc_dev *dev, u32 carrier)
{
	struct pwm_ir *pwm_ir = dev->priv;

	if (!carrier)
		return -EINVAL;

	pwm_ir->carrier = carrier;

	return 0;
}

__attribute__((used)) static int pwm_ir_tx(struct rc_dev *dev, unsigned int *txbuf,
		     unsigned int count)
{
	struct pwm_ir *pwm_ir = dev->priv;
	struct pwm_device *pwm = pwm_ir->pwm;
	int i, duty, period;
	ktime_t edge;
	long delta;

	period = DIV_ROUND_CLOSEST(NSEC_PER_SEC, pwm_ir->carrier);
	duty = DIV_ROUND_CLOSEST(pwm_ir->duty_cycle * period, 100);

	pwm_config(pwm, duty, period);

	edge = ktime_get();

	for (i = 0; i < count; i++) {
		if (i % 2) // space
			pwm_disable(pwm);
		else
			pwm_enable(pwm);

		edge = ktime_add_us(edge, txbuf[i]);
		delta = ktime_us_delta(edge, ktime_get());
		if (delta > 0)
			usleep_range(delta, delta + 10);
	}

	pwm_disable(pwm);

	return count;
}

__attribute__((used)) static int pwm_ir_probe(struct platform_device *pdev)
{
	struct pwm_ir *pwm_ir;
	struct rc_dev *rcdev;
	int rc;

	pwm_ir = devm_kmalloc(&pdev->dev, sizeof(*pwm_ir), GFP_KERNEL);
	if (!pwm_ir)
		return -ENOMEM;

	pwm_ir->pwm = devm_pwm_get(&pdev->dev, NULL);
	if (IS_ERR(pwm_ir->pwm))
		return PTR_ERR(pwm_ir->pwm);

	pwm_ir->carrier = 38000;
	pwm_ir->duty_cycle = 50;

	rcdev = devm_rc_allocate_device(&pdev->dev, RC_DRIVER_IR_RAW_TX);
	if (!rcdev)
		return -ENOMEM;

	rcdev->priv = pwm_ir;
	rcdev->driver_name = DRIVER_NAME;
	rcdev->device_name = DEVICE_NAME;
	rcdev->tx_ir = pwm_ir_tx;
	rcdev->s_tx_duty_cycle = pwm_ir_set_duty_cycle;
	rcdev->s_tx_carrier = pwm_ir_set_carrier;

	rc = devm_rc_register_device(&pdev->dev, rcdev);
	if (rc < 0)
		dev_err(&pdev->dev, "failed to register rc device\n");

	return rc;
}


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
struct rc_dev {int (* tx_ir ) (struct rc_dev*,unsigned int*,unsigned int) ;int (* s_tx_duty_cycle ) (struct rc_dev*,void*) ;int (* s_tx_carrier ) (struct rc_dev*,void*) ;int /*<<< orphan*/  device_name; int /*<<< orphan*/  driver_name; struct gpio_ir* priv; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct gpio_ir {int duty_cycle; int carrier; int /*<<< orphan*/  lock; int /*<<< orphan*/  gpio; } ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  ktime_t ;

/* Variables and functions */
 int /*<<< orphan*/  DEVICE_NAME ; 
 unsigned int DIV_ROUND_CLOSEST (int,int) ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int NSEC_PER_SEC ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RC_DRIVER_IR_RAW_TX ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  devm_gpiod_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct gpio_ir* devm_kmalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct rc_dev* devm_rc_allocate_device (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int devm_rc_register_device (int /*<<< orphan*/ *,struct rc_dev*) ; 
 int /*<<< orphan*/  gpiod_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ktime_add_ns (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  ktime_add_us (int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ ktime_before (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get () ; 
 int /*<<< orphan*/  ktime_sub (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ktime_to_ns (int /*<<< orphan*/ ) ; 
 int ktime_us_delta (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ndelay (int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int gpio_ir_tx_set_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
	struct gpio_ir *gpio_ir = dev->priv;

	gpio_ir->duty_cycle = duty_cycle;

	return 0;
}

__attribute__((used)) static int gpio_ir_tx_set_carrier(struct rc_dev *dev, u32 carrier)
{
	struct gpio_ir *gpio_ir = dev->priv;

	if (!carrier)
		return -EINVAL;

	gpio_ir->carrier = carrier;

	return 0;
}

__attribute__((used)) static int gpio_ir_tx(struct rc_dev *dev, unsigned int *txbuf,
		      unsigned int count)
{
	struct gpio_ir *gpio_ir = dev->priv;
	unsigned long flags;
	ktime_t edge;
	/*
	 * delta should never exceed 0.5 seconds (IR_MAX_DURATION) and on
	 * m68k ndelay(s64) does not compile; so use s32 rather than s64.
	 */
	s32 delta;
	int i;
	unsigned int pulse, space;

	/* Ensure the dividend fits into 32 bit */
	pulse = DIV_ROUND_CLOSEST(gpio_ir->duty_cycle * (NSEC_PER_SEC / 100),
				  gpio_ir->carrier);
	space = DIV_ROUND_CLOSEST((100 - gpio_ir->duty_cycle) *
				  (NSEC_PER_SEC / 100), gpio_ir->carrier);

	spin_lock_irqsave(&gpio_ir->lock, flags);

	edge = ktime_get();

	for (i = 0; i < count; i++) {
		if (i % 2) {
			// space
			edge = ktime_add_us(edge, txbuf[i]);
			delta = ktime_us_delta(edge, ktime_get());
			if (delta > 10) {
				spin_unlock_irqrestore(&gpio_ir->lock, flags);
				usleep_range(delta, delta + 10);
				spin_lock_irqsave(&gpio_ir->lock, flags);
			} else if (delta > 0) {
				udelay(delta);
			}
		} else {
			// pulse
			ktime_t last = ktime_add_us(edge, txbuf[i]);

			while (ktime_before(ktime_get(), last)) {
				gpiod_set_value(gpio_ir->gpio, 1);
				edge = ktime_add_ns(edge, pulse);
				delta = ktime_to_ns(ktime_sub(edge,
							      ktime_get()));
				if (delta > 0)
					ndelay(delta);
				gpiod_set_value(gpio_ir->gpio, 0);
				edge = ktime_add_ns(edge, space);
				delta = ktime_to_ns(ktime_sub(edge,
							      ktime_get()));
				if (delta > 0)
					ndelay(delta);
			}

			edge = last;
		}
	}

	spin_unlock_irqrestore(&gpio_ir->lock, flags);

	return count;
}

__attribute__((used)) static int gpio_ir_tx_probe(struct platform_device *pdev)
{
	struct gpio_ir *gpio_ir;
	struct rc_dev *rcdev;
	int rc;

	gpio_ir = devm_kmalloc(&pdev->dev, sizeof(*gpio_ir), GFP_KERNEL);
	if (!gpio_ir)
		return -ENOMEM;

	rcdev = devm_rc_allocate_device(&pdev->dev, RC_DRIVER_IR_RAW_TX);
	if (!rcdev)
		return -ENOMEM;

	gpio_ir->gpio = devm_gpiod_get(&pdev->dev, NULL, GPIOD_OUT_LOW);
	if (IS_ERR(gpio_ir->gpio)) {
		if (PTR_ERR(gpio_ir->gpio) != -EPROBE_DEFER)
			dev_err(&pdev->dev, "Failed to get gpio (%ld)\n",
				PTR_ERR(gpio_ir->gpio));
		return PTR_ERR(gpio_ir->gpio);
	}

	rcdev->priv = gpio_ir;
	rcdev->driver_name = DRIVER_NAME;
	rcdev->device_name = DEVICE_NAME;
	rcdev->tx_ir = gpio_ir_tx;
	rcdev->s_tx_duty_cycle = gpio_ir_tx_set_duty_cycle;
	rcdev->s_tx_carrier = gpio_ir_tx_set_carrier;

	gpio_ir->carrier = 38000;
	gpio_ir->duty_cycle = 50;
	spin_lock_init(&gpio_ir->lock);

	rc = devm_rc_register_device(&pdev->dev, rcdev);
	if (rc < 0)
		dev_err(&pdev->dev, "failed to register rc device\n");

	return rc;
}


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
struct seq_file {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct cec_gpio {int cec_is_low; int cec_have_irq; char* cec_irq; int hpd_is_high; int v5_is_high; void* adap; void* v5_irq; void* v5_gpio; void* hpd_irq; void* hpd_gpio; void* cec_gpio; struct device* dev; void* hpd_ts; void* v5_ts; } ;
struct cec_adapter {int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int CEC_CAP_DEFAULTS ; 
 int CEC_CAP_MONITOR_ALL ; 
 int CEC_CAP_MONITOR_PIN ; 
 int CEC_CAP_PHYS_ADDR ; 
 int ENOMEM ; 
 int ENOTTY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH_OPEN_DRAIN ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  cec_delete_adapter (void*) ; 
 struct cec_gpio* cec_get_drvdata (struct cec_adapter*) ; 
 int /*<<< orphan*/  cec_gpio_pin_ops ; 
 void* cec_pin_allocate_adapter (int /*<<< orphan*/ *,struct cec_gpio*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cec_pin_changed (void*,int) ; 
 int /*<<< orphan*/  cec_queue_pin_5v_event (void*,int,void*) ; 
 int /*<<< orphan*/  cec_queue_pin_hpd_event (void*,int,void*) ; 
 int cec_register_adapter (void*,struct device*) ; 
 int /*<<< orphan*/  cec_unregister_adapter (void*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 void* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct cec_gpio* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,void*,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int,char*,struct cec_gpio*) ; 
 int /*<<< orphan*/  free_irq (char*,struct cec_gpio*) ; 
 int gpiod_get_value (void*) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 void* gpiod_to_irq (void*) ; 
 void* ktime_get () ; 
 struct cec_gpio* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cec_gpio*) ; 
 scalar_t__ request_irq (char*,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct cec_gpio*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char*) ; 

__attribute__((used)) static bool cec_gpio_read(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (cec->cec_is_low)
		return false;
	return gpiod_get_value(cec->cec_gpio);
}

__attribute__((used)) static void cec_gpio_high(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (!cec->cec_is_low)
		return;
	cec->cec_is_low = false;
	gpiod_set_value(cec->cec_gpio, 1);
}

__attribute__((used)) static void cec_gpio_low(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (cec->cec_is_low)
		return;
	if (WARN_ON_ONCE(cec->cec_have_irq))
		free_irq(cec->cec_irq, cec);
	cec->cec_have_irq = false;
	cec->cec_is_low = true;
	gpiod_set_value(cec->cec_gpio, 0);
}

__attribute__((used)) static irqreturn_t cec_hpd_gpio_irq_handler_thread(int irq, void *priv)
{
	struct cec_gpio *cec = priv;

	cec_queue_pin_hpd_event(cec->adap, cec->hpd_is_high, cec->hpd_ts);
	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t cec_5v_gpio_irq_handler(int irq, void *priv)
{
	struct cec_gpio *cec = priv;
	bool is_high = gpiod_get_value(cec->v5_gpio);

	if (is_high == cec->v5_is_high)
		return IRQ_HANDLED;
	cec->v5_ts = ktime_get();
	cec->v5_is_high = is_high;
	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t cec_5v_gpio_irq_handler_thread(int irq, void *priv)
{
	struct cec_gpio *cec = priv;

	cec_queue_pin_5v_event(cec->adap, cec->v5_is_high, cec->v5_ts);
	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t cec_hpd_gpio_irq_handler(int irq, void *priv)
{
	struct cec_gpio *cec = priv;
	bool is_high = gpiod_get_value(cec->hpd_gpio);

	if (is_high == cec->hpd_is_high)
		return IRQ_HANDLED;
	cec->hpd_ts = ktime_get();
	cec->hpd_is_high = is_high;
	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t cec_gpio_irq_handler(int irq, void *priv)
{
	struct cec_gpio *cec = priv;

	cec_pin_changed(cec->adap, gpiod_get_value(cec->cec_gpio));
	return IRQ_HANDLED;
}

__attribute__((used)) static bool cec_gpio_enable_irq(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (cec->cec_have_irq)
		return true;

	if (request_irq(cec->cec_irq, cec_gpio_irq_handler,
			IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
			adap->name, cec))
		return false;
	cec->cec_have_irq = true;
	return true;
}

__attribute__((used)) static void cec_gpio_disable_irq(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (cec->cec_have_irq)
		free_irq(cec->cec_irq, cec);
	cec->cec_have_irq = false;
}

__attribute__((used)) static void cec_gpio_status(struct cec_adapter *adap, struct seq_file *file)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	seq_printf(file, "mode: %s\n", cec->cec_is_low ? "low-drive" : "read");
	if (cec->cec_have_irq)
		seq_printf(file, "using irq: %d\n", cec->cec_irq);
	if (cec->hpd_gpio)
		seq_printf(file, "hpd: %s\n",
			   cec->hpd_is_high ? "high" : "low");
	if (cec->v5_gpio)
		seq_printf(file, "5V: %s\n",
			   cec->v5_is_high ? "high" : "low");
}

__attribute__((used)) static int cec_gpio_read_hpd(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (!cec->hpd_gpio)
		return -ENOTTY;
	return gpiod_get_value(cec->hpd_gpio);
}

__attribute__((used)) static int cec_gpio_read_5v(struct cec_adapter *adap)
{
	struct cec_gpio *cec = cec_get_drvdata(adap);

	if (!cec->v5_gpio)
		return -ENOTTY;
	return gpiod_get_value(cec->v5_gpio);
}

__attribute__((used)) static void cec_gpio_free(struct cec_adapter *adap)
{
	cec_gpio_disable_irq(adap);
}

__attribute__((used)) static int cec_gpio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct cec_gpio *cec;
	int ret;

	cec = devm_kzalloc(dev, sizeof(*cec), GFP_KERNEL);
	if (!cec)
		return -ENOMEM;

	cec->dev = dev;

	cec->cec_gpio = devm_gpiod_get(dev, "cec", GPIOD_OUT_HIGH_OPEN_DRAIN);
	if (IS_ERR(cec->cec_gpio))
		return PTR_ERR(cec->cec_gpio);
	cec->cec_irq = gpiod_to_irq(cec->cec_gpio);

	cec->hpd_gpio = devm_gpiod_get_optional(dev, "hpd", GPIOD_IN);
	if (IS_ERR(cec->hpd_gpio))
		return PTR_ERR(cec->hpd_gpio);

	cec->v5_gpio = devm_gpiod_get_optional(dev, "v5", GPIOD_IN);
	if (IS_ERR(cec->v5_gpio))
		return PTR_ERR(cec->v5_gpio);

	cec->adap = cec_pin_allocate_adapter(&cec_gpio_pin_ops,
		cec, pdev->name, CEC_CAP_DEFAULTS | CEC_CAP_PHYS_ADDR |
				 CEC_CAP_MONITOR_ALL | CEC_CAP_MONITOR_PIN);
	if (IS_ERR(cec->adap))
		return PTR_ERR(cec->adap);

	if (cec->hpd_gpio) {
		cec->hpd_irq = gpiod_to_irq(cec->hpd_gpio);
		ret = devm_request_threaded_irq(dev, cec->hpd_irq,
			cec_hpd_gpio_irq_handler,
			cec_hpd_gpio_irq_handler_thread,
			IRQF_ONESHOT |
			IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
			"hpd-gpio", cec);
		if (ret)
			return ret;
	}

	if (cec->v5_gpio) {
		cec->v5_irq = gpiod_to_irq(cec->v5_gpio);
		ret = devm_request_threaded_irq(dev, cec->v5_irq,
			cec_5v_gpio_irq_handler,
			cec_5v_gpio_irq_handler_thread,
			IRQF_ONESHOT |
			IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
			"v5-gpio", cec);
		if (ret)
			return ret;
	}

	ret = cec_register_adapter(cec->adap, &pdev->dev);
	if (ret) {
		cec_delete_adapter(cec->adap);
		return ret;
	}

	platform_set_drvdata(pdev, cec);
	return 0;
}

__attribute__((used)) static int cec_gpio_remove(struct platform_device *pdev)
{
	struct cec_gpio *cec = platform_get_drvdata(pdev);

	cec_unregister_adapter(cec->adap);
	return 0;
}


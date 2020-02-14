#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct st_rc_device {int overclocking; unsigned int sample_mult; unsigned int sample_div; int rxuhfmode; int irq; scalar_t__ sys_clock; struct rc_dev* rdev; struct device* dev; scalar_t__ rstc; scalar_t__ base; scalar_t__ rx_base; scalar_t__ irq_wake; } ;
struct resource {int dummy; } ;
struct rc_dev {int rx_resolution; int (* open ) (struct rc_dev*) ;void (* close ) (struct rc_dev*) ;char* device_name; int /*<<< orphan*/  map_name; int /*<<< orphan*/  driver_name; struct st_rc_device* priv; void* timeout; int /*<<< orphan*/  allowed_protocols; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_4__ {int timeout; int pulse; void* duration; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_IR_RAW_EVENT (TYPE_1__) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int IRB_FIFO_NOT_EMPTY ; 
 scalar_t__ IRB_MAX_SYM_PERIOD ; 
 int IRB_OVERFLOW ; 
 scalar_t__ IRB_RX_EN ; 
 int IRB_RX_INTS ; 
 scalar_t__ IRB_RX_INT_CLEAR ; 
 scalar_t__ IRB_RX_INT_EN ; 
 scalar_t__ IRB_RX_INT_STATUS ; 
 scalar_t__ IRB_RX_ON ; 
 int IRB_RX_OVERRUN_INT ; 
 scalar_t__ IRB_RX_POLARITY_INV ; 
 scalar_t__ IRB_RX_STATUS ; 
 scalar_t__ IRB_RX_SYS ; 
 int IRB_SAMPLE_FREQ ; 
 scalar_t__ IRB_SAMPLE_RATE_COMM ; 
 unsigned int IRB_TIMEOUT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IR_ST_NAME ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 unsigned int MAX_SYMB_TIME ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  RC_DRIVER_IR_RAW ; 
 int /*<<< orphan*/  RC_MAP_EMPTY ; 
 int /*<<< orphan*/  RC_PROTO_BIT_ALL_IR_DECODER ; 
 void* US_TO_NS (unsigned int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_get_rate (scalar_t__) ; 
 int /*<<< orphan*/  clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_pm_clear_wake_irq (struct device*) ; 
 int /*<<< orphan*/  dev_pm_set_wake_irq (struct device*,int) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 scalar_t__ devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (struct device*,struct resource*) ; 
 struct st_rc_device* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct st_rc_device*) ; 
 TYPE_1__ ev ; 
 int /*<<< orphan*/  ir_raw_event_handle (struct rc_dev*) ; 
 int /*<<< orphan*/  ir_raw_event_reset (struct rc_dev*) ; 
 int /*<<< orphan*/  ir_raw_event_store (struct rc_dev*,TYPE_1__*) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  of_property_read_string (struct device_node*,char*,char const**) ; 
 struct st_rc_device* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct st_rc_device*) ; 
 int /*<<< orphan*/  pm_wakeup_event (struct device*,int /*<<< orphan*/ ) ; 
 struct rc_dev* rc_allocate_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rc_free_device (struct rc_dev*) ; 
 int rc_register_device (struct rc_dev*) ; 
 int /*<<< orphan*/  rc_unregister_device (struct rc_dev*) ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  reset_control_deassert (scalar_t__) ; 
 scalar_t__ reset_control_get_optional_exclusive (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 scalar_t__ time_is_after_jiffies (unsigned long) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void st_rc_send_lirc_timeout(struct rc_dev *rdev)
{
	DEFINE_IR_RAW_EVENT(ev);
	ev.timeout = true;
	ir_raw_event_store(rdev, &ev);
}

__attribute__((used)) static irqreturn_t st_rc_rx_interrupt(int irq, void *data)
{
	unsigned long timeout;
	unsigned int symbol, mark = 0;
	struct st_rc_device *dev = data;
	int last_symbol = 0;
	u32 status, int_status;
	DEFINE_IR_RAW_EVENT(ev);

	if (dev->irq_wake)
		pm_wakeup_event(dev->dev, 0);

	/* FIXME: is 10ms good enough ? */
	timeout = jiffies +  msecs_to_jiffies(10);
	do {
		status  = readl(dev->rx_base + IRB_RX_STATUS);
		if (!(status & (IRB_FIFO_NOT_EMPTY | IRB_OVERFLOW)))
			break;

		int_status = readl(dev->rx_base + IRB_RX_INT_STATUS);
		if (unlikely(int_status & IRB_RX_OVERRUN_INT)) {
			/* discard the entire collection in case of errors!  */
			ir_raw_event_reset(dev->rdev);
			dev_info(dev->dev, "IR RX overrun\n");
			writel(IRB_RX_OVERRUN_INT,
					dev->rx_base + IRB_RX_INT_CLEAR);
			continue;
		}

		symbol = readl(dev->rx_base + IRB_RX_SYS);
		mark = readl(dev->rx_base + IRB_RX_ON);

		if (symbol == IRB_TIMEOUT)
			last_symbol = 1;

		 /* Ignore any noise */
		if ((mark > 2) && (symbol > 1)) {
			symbol -= mark;
			if (dev->overclocking) { /* adjustments to timings */
				symbol *= dev->sample_mult;
				symbol /= dev->sample_div;
				mark *= dev->sample_mult;
				mark /= dev->sample_div;
			}

			ev.duration = US_TO_NS(mark);
			ev.pulse = true;
			ir_raw_event_store(dev->rdev, &ev);

			if (!last_symbol) {
				ev.duration = US_TO_NS(symbol);
				ev.pulse = false;
				ir_raw_event_store(dev->rdev, &ev);
			} else  {
				st_rc_send_lirc_timeout(dev->rdev);
			}

		}
		last_symbol = 0;
	} while (time_is_after_jiffies(timeout));

	writel(IRB_RX_INTS, dev->rx_base + IRB_RX_INT_CLEAR);

	/* Empty software fifo */
	ir_raw_event_handle(dev->rdev);
	return IRQ_HANDLED;
}

__attribute__((used)) static void st_rc_hardware_init(struct st_rc_device *dev)
{
	int baseclock, freqdiff;
	unsigned int rx_max_symbol_per = MAX_SYMB_TIME;
	unsigned int rx_sampling_freq_div;

	/* Enable the IP */
	reset_control_deassert(dev->rstc);

	clk_prepare_enable(dev->sys_clock);
	baseclock = clk_get_rate(dev->sys_clock);

	/* IRB input pins are inverted internally from high to low. */
	writel(1, dev->rx_base + IRB_RX_POLARITY_INV);

	rx_sampling_freq_div = baseclock / IRB_SAMPLE_FREQ;
	writel(rx_sampling_freq_div, dev->base + IRB_SAMPLE_RATE_COMM);

	freqdiff = baseclock - (rx_sampling_freq_div * IRB_SAMPLE_FREQ);
	if (freqdiff) { /* over clocking, workout the adjustment factors */
		dev->overclocking = true;
		dev->sample_mult = 1000;
		dev->sample_div = baseclock / (10000 * rx_sampling_freq_div);
		rx_max_symbol_per = (rx_max_symbol_per * 1000)/dev->sample_div;
	}

	writel(rx_max_symbol_per, dev->rx_base + IRB_MAX_SYM_PERIOD);
}

__attribute__((used)) static int st_rc_remove(struct platform_device *pdev)
{
	struct st_rc_device *rc_dev = platform_get_drvdata(pdev);

	dev_pm_clear_wake_irq(&pdev->dev);
	device_init_wakeup(&pdev->dev, false);
	clk_disable_unprepare(rc_dev->sys_clock);
	rc_unregister_device(rc_dev->rdev);
	return 0;
}

__attribute__((used)) static int st_rc_open(struct rc_dev *rdev)
{
	struct st_rc_device *dev = rdev->priv;
	unsigned long flags;
	local_irq_save(flags);
	/* enable interrupts and receiver */
	writel(IRB_RX_INTS, dev->rx_base + IRB_RX_INT_EN);
	writel(0x01, dev->rx_base + IRB_RX_EN);
	local_irq_restore(flags);

	return 0;
}

__attribute__((used)) static void st_rc_close(struct rc_dev *rdev)
{
	struct st_rc_device *dev = rdev->priv;
	/* disable interrupts and receiver */
	writel(0x00, dev->rx_base + IRB_RX_EN);
	writel(0x00, dev->rx_base + IRB_RX_INT_EN);
}

__attribute__((used)) static int st_rc_probe(struct platform_device *pdev)
{
	int ret = -EINVAL;
	struct rc_dev *rdev;
	struct device *dev = &pdev->dev;
	struct resource *res;
	struct st_rc_device *rc_dev;
	struct device_node *np = pdev->dev.of_node;
	const char *rx_mode;

	rc_dev = devm_kzalloc(dev, sizeof(struct st_rc_device), GFP_KERNEL);

	if (!rc_dev)
		return -ENOMEM;

	rdev = rc_allocate_device(RC_DRIVER_IR_RAW);

	if (!rdev)
		return -ENOMEM;

	if (np && !of_property_read_string(np, "rx-mode", &rx_mode)) {

		if (!strcmp(rx_mode, "uhf")) {
			rc_dev->rxuhfmode = true;
		} else if (!strcmp(rx_mode, "infrared")) {
			rc_dev->rxuhfmode = false;
		} else {
			dev_err(dev, "Unsupported rx mode [%s]\n", rx_mode);
			goto err;
		}

	} else {
		goto err;
	}

	rc_dev->sys_clock = devm_clk_get(dev, NULL);
	if (IS_ERR(rc_dev->sys_clock)) {
		dev_err(dev, "System clock not found\n");
		ret = PTR_ERR(rc_dev->sys_clock);
		goto err;
	}

	rc_dev->irq = platform_get_irq(pdev, 0);
	if (rc_dev->irq < 0) {
		ret = rc_dev->irq;
		goto err;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	rc_dev->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(rc_dev->base)) {
		ret = PTR_ERR(rc_dev->base);
		goto err;
	}

	if (rc_dev->rxuhfmode)
		rc_dev->rx_base = rc_dev->base + 0x40;
	else
		rc_dev->rx_base = rc_dev->base;

	rc_dev->rstc = reset_control_get_optional_exclusive(dev, NULL);
	if (IS_ERR(rc_dev->rstc)) {
		ret = PTR_ERR(rc_dev->rstc);
		goto err;
	}

	rc_dev->dev = dev;
	platform_set_drvdata(pdev, rc_dev);
	st_rc_hardware_init(rc_dev);

	rdev->allowed_protocols = RC_PROTO_BIT_ALL_IR_DECODER;
	/* rx sampling rate is 10Mhz */
	rdev->rx_resolution = 100;
	rdev->timeout = US_TO_NS(MAX_SYMB_TIME);
	rdev->priv = rc_dev;
	rdev->open = st_rc_open;
	rdev->close = st_rc_close;
	rdev->driver_name = IR_ST_NAME;
	rdev->map_name = RC_MAP_EMPTY;
	rdev->device_name = "ST Remote Control Receiver";

	ret = rc_register_device(rdev);
	if (ret < 0)
		goto clkerr;

	rc_dev->rdev = rdev;
	if (devm_request_irq(dev, rc_dev->irq, st_rc_rx_interrupt,
			     0, IR_ST_NAME, rc_dev) < 0) {
		dev_err(dev, "IRQ %d register failed\n", rc_dev->irq);
		ret = -EINVAL;
		goto rcerr;
	}

	/* enable wake via this device */
	device_init_wakeup(dev, true);
	dev_pm_set_wake_irq(dev, rc_dev->irq);

	/*
	 * for LIRC_MODE_MODE2 or LIRC_MODE_PULSE or LIRC_MODE_RAW
	 * lircd expects a long space first before a signal train to sync.
	 */
	st_rc_send_lirc_timeout(rdev);

	dev_info(dev, "setup in %s mode\n", rc_dev->rxuhfmode ? "UHF" : "IR");

	return ret;
rcerr:
	rc_unregister_device(rdev);
	rdev = NULL;
clkerr:
	clk_disable_unprepare(rc_dev->sys_clock);
err:
	rc_free_device(rdev);
	dev_err(dev, "Unable to register device (%d)\n", ret);
	return ret;
}


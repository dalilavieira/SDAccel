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
struct rc_scancode_filter {int /*<<< orphan*/  data; int /*<<< orphan*/  mask; } ;
struct rc_dev {int timeout; int /*<<< orphan*/  wakeup_protocol; struct loopback_dev* priv; } ;
struct loopback_dev {int txmask; int txcarrier; int txduty; int rxcarriermin; int rxcarriermax; int learning; int idle; int carrierreport; } ;
struct ir_raw_event {int dummy; } ;
struct TYPE_4__ {int pulse; unsigned int duration; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_IR_RAW_EVENT (TYPE_1__) ; 
 int EINVAL ; 
 int ENOBUFS ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int RXMASK_LEARNING ; 
 int RXMASK_REGULAR ; 
 int /*<<< orphan*/  dprintk (char*,...) ; 
 int ir_raw_encode_scancode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ir_raw_event*,unsigned int const) ; 
 int /*<<< orphan*/  ir_raw_event_handle (struct rc_dev*) ; 
 int /*<<< orphan*/  ir_raw_event_store (struct rc_dev*,struct ir_raw_event*) ; 
 int /*<<< orphan*/  ir_raw_event_store_with_filter (struct rc_dev*,TYPE_1__*) ; 
 int /*<<< orphan*/  kfree (struct ir_raw_event*) ; 
 struct ir_raw_event* kmalloc_array (unsigned int const,int,int /*<<< orphan*/ ) ; 
 TYPE_1__ rawir ; 

__attribute__((used)) static int loop_set_tx_mask(struct rc_dev *dev, u32 mask)
{
	struct loopback_dev *lodev = dev->priv;

	if ((mask & (RXMASK_REGULAR | RXMASK_LEARNING)) != mask) {
		dprintk("invalid tx mask: %u\n", mask);
		return -EINVAL;
	}

	dprintk("setting tx mask: %u\n", mask);
	lodev->txmask = mask;
	return 0;
}

__attribute__((used)) static int loop_set_tx_carrier(struct rc_dev *dev, u32 carrier)
{
	struct loopback_dev *lodev = dev->priv;

	dprintk("setting tx carrier: %u\n", carrier);
	lodev->txcarrier = carrier;
	return 0;
}

__attribute__((used)) static int loop_set_tx_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
	struct loopback_dev *lodev = dev->priv;

	if (duty_cycle < 1 || duty_cycle > 99) {
		dprintk("invalid duty cycle: %u\n", duty_cycle);
		return -EINVAL;
	}

	dprintk("setting duty cycle: %u\n", duty_cycle);
	lodev->txduty = duty_cycle;
	return 0;
}

__attribute__((used)) static int loop_set_rx_carrier_range(struct rc_dev *dev, u32 min, u32 max)
{
	struct loopback_dev *lodev = dev->priv;

	if (min < 1 || min > max) {
		dprintk("invalid rx carrier range %u to %u\n", min, max);
		return -EINVAL;
	}

	dprintk("setting rx carrier range %u to %u\n", min, max);
	lodev->rxcarriermin = min;
	lodev->rxcarriermax = max;
	return 0;
}

__attribute__((used)) static int loop_tx_ir(struct rc_dev *dev, unsigned *txbuf, unsigned count)
{
	struct loopback_dev *lodev = dev->priv;
	u32 rxmask;
	unsigned i;
	DEFINE_IR_RAW_EVENT(rawir);

	if (lodev->txcarrier < lodev->rxcarriermin ||
	    lodev->txcarrier > lodev->rxcarriermax) {
		dprintk("ignoring tx, carrier out of range\n");
		goto out;
	}

	if (lodev->learning)
		rxmask = RXMASK_LEARNING;
	else
		rxmask = RXMASK_REGULAR;

	if (!(rxmask & lodev->txmask)) {
		dprintk("ignoring tx, rx mask mismatch\n");
		goto out;
	}

	for (i = 0; i < count; i++) {
		rawir.pulse = i % 2 ? false : true;
		rawir.duration = txbuf[i] * 1000;
		if (rawir.duration)
			ir_raw_event_store_with_filter(dev, &rawir);
	}

	/* Fake a silence long enough to cause us to go idle */
	rawir.pulse = false;
	rawir.duration = dev->timeout;
	ir_raw_event_store_with_filter(dev, &rawir);

	ir_raw_event_handle(dev);

out:
	return count;
}

__attribute__((used)) static void loop_set_idle(struct rc_dev *dev, bool enable)
{
	struct loopback_dev *lodev = dev->priv;

	if (lodev->idle != enable) {
		dprintk("%sing idle mode\n", enable ? "enter" : "exit");
		lodev->idle = enable;
	}
}

__attribute__((used)) static int loop_set_learning_mode(struct rc_dev *dev, int enable)
{
	struct loopback_dev *lodev = dev->priv;

	if (lodev->learning != enable) {
		dprintk("%sing learning mode\n", enable ? "enter" : "exit");
		lodev->learning = !!enable;
	}

	return 0;
}

__attribute__((used)) static int loop_set_carrier_report(struct rc_dev *dev, int enable)
{
	struct loopback_dev *lodev = dev->priv;

	if (lodev->carrierreport != enable) {
		dprintk("%sabling carrier reports\n", enable ? "en" : "dis");
		lodev->carrierreport = !!enable;
	}

	return 0;
}

__attribute__((used)) static int loop_set_wakeup_filter(struct rc_dev *dev,
				  struct rc_scancode_filter *sc)
{
	static const unsigned int max = 512;
	struct ir_raw_event *raw;
	int ret;
	int i;

	/* fine to disable filter */
	if (!sc->mask)
		return 0;

	/* encode the specified filter and loop it back */
	raw = kmalloc_array(max, sizeof(*raw), GFP_KERNEL);
	if (!raw)
		return -ENOMEM;

	ret = ir_raw_encode_scancode(dev->wakeup_protocol, sc->data, raw, max);
	/* still loop back the partial raw IR even if it's incomplete */
	if (ret == -ENOBUFS)
		ret = max;
	if (ret >= 0) {
		/* do the loopback */
		for (i = 0; i < ret; ++i)
			ir_raw_event_store(dev, &raw[i]);
		ir_raw_event_handle(dev);

		ret = 0;
	}

	kfree(raw);

	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct st_uvis25_hw {int enabled; int irq; struct regmap* regmap; TYPE_3__* trig; } ;
struct regmap {int dummy; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_9__ {struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/ * info; int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; TYPE_2__ dev; int /*<<< orphan*/  modes; } ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_8__ {struct device* parent; } ;
struct TYPE_10__ {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALIGN (int,int) ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_PROCESSED 132 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 unsigned long IRQF_ONESHOT ; 
#define  IRQF_TRIGGER_FALLING 131 
#define  IRQF_TRIGGER_HIGH 130 
#define  IRQF_TRIGGER_LOW 129 
#define  IRQF_TRIGGER_RISING 128 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  ST_UVIS25_DEV_NAME ; 
 int /*<<< orphan*/  ST_UVIS25_REG_BDU_MASK ; 
 int /*<<< orphan*/  ST_UVIS25_REG_BOOT_MASK ; 
 int /*<<< orphan*/  ST_UVIS25_REG_CTRL1_ADDR ; 
 int /*<<< orphan*/  ST_UVIS25_REG_CTRL2_ADDR ; 
 int /*<<< orphan*/  ST_UVIS25_REG_CTRL3_ADDR ; 
 int /*<<< orphan*/  ST_UVIS25_REG_HL_MASK ; 
 int /*<<< orphan*/  ST_UVIS25_REG_ODR_MASK ; 
 int /*<<< orphan*/  ST_UVIS25_REG_OUT_ADDR ; 
 int /*<<< orphan*/  ST_UVIS25_REG_STATUS_ADDR ; 
 int ST_UVIS25_REG_UV_DA_MASK ; 
 int /*<<< orphan*/  ST_UVIS25_REG_WHOAMI_ADDR ; 
 int ST_UVIS25_REG_WHOAMI_VAL ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,unsigned long) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,void*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 TYPE_3__* devm_iio_trigger_alloc (struct device*,char*,int /*<<< orphan*/ ) ; 
 int devm_iio_trigger_register (struct device*,TYPE_3__*) ; 
 int devm_iio_triggered_buffer_setup (struct device*,struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),unsigned long,int /*<<< orphan*/ ,struct st_uvis25_hw*) ; 
 int /*<<< orphan*/  disable_irq (int) ; 
 int /*<<< orphan*/  enable_irq (int) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct st_uvis25_hw* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (TYPE_3__*) ; 
 int /*<<< orphan*/  iio_trigger_poll_chained (TYPE_3__*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_3__*,struct iio_dev*) ; 
 int /*<<< orphan*/  irq_get_irq_data (int) ; 
 unsigned long irqd_get_trigger_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct device* regmap_get_device (struct regmap*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  st_uvis25_buffer_ops ; 
 int /*<<< orphan*/  st_uvis25_channels ; 
 int /*<<< orphan*/  st_uvis25_info ; 

__attribute__((used)) static int st_uvis25_check_whoami(struct st_uvis25_hw *hw)
{
	int err, data;

	err = regmap_read(hw->regmap, ST_UVIS25_REG_WHOAMI_ADDR, &data);
	if (err < 0) {
		dev_err(regmap_get_device(hw->regmap),
			"failed to read whoami register\n");
		return err;
	}

	if (data != ST_UVIS25_REG_WHOAMI_VAL) {
		dev_err(regmap_get_device(hw->regmap),
			"wrong whoami {%02x vs %02x}\n",
			data, ST_UVIS25_REG_WHOAMI_VAL);
		return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static int st_uvis25_set_enable(struct st_uvis25_hw *hw, bool enable)
{
	int err;

	err = regmap_update_bits(hw->regmap, ST_UVIS25_REG_CTRL1_ADDR,
				 ST_UVIS25_REG_ODR_MASK, enable);
	if (err < 0)
		return err;

	hw->enabled = enable;

	return 0;
}

__attribute__((used)) static int st_uvis25_read_oneshot(struct st_uvis25_hw *hw, u8 addr, int *val)
{
	int err;

	err = st_uvis25_set_enable(hw, true);
	if (err < 0)
		return err;

	msleep(1500);

	/*
	 * in order to avoid possible race conditions with interrupt
	 * generation, disable the sensor first and then poll output
	 * register. That sequence guarantees the interrupt will be reset
	 * when irq line is unmasked
	 */
	err = st_uvis25_set_enable(hw, false);
	if (err < 0)
		return err;

	err = regmap_read(hw->regmap, addr, val);

	return err < 0 ? err : IIO_VAL_INT;
}

__attribute__((used)) static int st_uvis25_read_raw(struct iio_dev *iio_dev,
			      struct iio_chan_spec const *ch,
			      int *val, int *val2, long mask)
{
	int ret;

	ret = iio_device_claim_direct_mode(iio_dev);
	if (ret)
		return ret;

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED: {
		struct st_uvis25_hw *hw = iio_priv(iio_dev);

		/*
		 * mask irq line during oneshot read since the sensor
		 * does not export the capability to disable data-ready line
		 * in the register map and it is enabled by default.
		 * If the line is unmasked during read_raw() it will be set
		 * active and never reset since the trigger is disabled
		 */
		if (hw->irq > 0)
			disable_irq(hw->irq);
		ret = st_uvis25_read_oneshot(hw, ch->address, val);
		if (hw->irq > 0)
			enable_irq(hw->irq);
		break;
	}
	default:
		ret = -EINVAL;
		break;
	}

	iio_device_release_direct_mode(iio_dev);

	return ret;
}

__attribute__((used)) static irqreturn_t st_uvis25_trigger_handler_thread(int irq, void *private)
{
	struct st_uvis25_hw *hw = private;
	int err, status;

	err = regmap_read(hw->regmap, ST_UVIS25_REG_STATUS_ADDR, &status);
	if (err < 0)
		return IRQ_HANDLED;

	if (!(status & ST_UVIS25_REG_UV_DA_MASK))
		return IRQ_NONE;

	iio_trigger_poll_chained(hw->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int st_uvis25_allocate_trigger(struct iio_dev *iio_dev)
{
	struct st_uvis25_hw *hw = iio_priv(iio_dev);
	struct device *dev = regmap_get_device(hw->regmap);
	bool irq_active_low = false;
	unsigned long irq_type;
	int err;

	irq_type = irqd_get_trigger_type(irq_get_irq_data(hw->irq));

	switch (irq_type) {
	case IRQF_TRIGGER_HIGH:
	case IRQF_TRIGGER_RISING:
		break;
	case IRQF_TRIGGER_LOW:
	case IRQF_TRIGGER_FALLING:
		irq_active_low = true;
		break;
	default:
		dev_info(dev, "mode %lx unsupported\n", irq_type);
		return -EINVAL;
	}

	err = regmap_update_bits(hw->regmap, ST_UVIS25_REG_CTRL3_ADDR,
				 ST_UVIS25_REG_HL_MASK, irq_active_low);
	if (err < 0)
		return err;

	err = devm_request_threaded_irq(dev, hw->irq, NULL,
					st_uvis25_trigger_handler_thread,
					irq_type | IRQF_ONESHOT,
					iio_dev->name, hw);
	if (err) {
		dev_err(dev, "failed to request trigger irq %d\n",
			hw->irq);
		return err;
	}

	hw->trig = devm_iio_trigger_alloc(dev, "%s-trigger",
					  iio_dev->name);
	if (!hw->trig)
		return -ENOMEM;

	iio_trigger_set_drvdata(hw->trig, iio_dev);
	hw->trig->dev.parent = dev;

	return devm_iio_trigger_register(dev, hw->trig);
}

__attribute__((used)) static int st_uvis25_buffer_preenable(struct iio_dev *iio_dev)
{
	return st_uvis25_set_enable(iio_priv(iio_dev), true);
}

__attribute__((used)) static int st_uvis25_buffer_postdisable(struct iio_dev *iio_dev)
{
	return st_uvis25_set_enable(iio_priv(iio_dev), false);
}

__attribute__((used)) static irqreturn_t st_uvis25_buffer_handler_thread(int irq, void *p)
{
	u8 buffer[ALIGN(sizeof(u8), sizeof(s64)) + sizeof(s64)];
	struct iio_poll_func *pf = p;
	struct iio_dev *iio_dev = pf->indio_dev;
	struct st_uvis25_hw *hw = iio_priv(iio_dev);
	int err;

	err = regmap_read(hw->regmap, ST_UVIS25_REG_OUT_ADDR, (int *)buffer);
	if (err < 0)
		goto out;

	iio_push_to_buffers_with_timestamp(iio_dev, buffer,
					   iio_get_time_ns(iio_dev));

out:
	iio_trigger_notify_done(hw->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int st_uvis25_allocate_buffer(struct iio_dev *iio_dev)
{
	struct st_uvis25_hw *hw = iio_priv(iio_dev);

	return devm_iio_triggered_buffer_setup(regmap_get_device(hw->regmap),
					       iio_dev, NULL,
					       st_uvis25_buffer_handler_thread,
					       &st_uvis25_buffer_ops);
}

__attribute__((used)) static int st_uvis25_init_sensor(struct st_uvis25_hw *hw)
{
	int err;

	err = regmap_update_bits(hw->regmap, ST_UVIS25_REG_CTRL2_ADDR,
				 ST_UVIS25_REG_BOOT_MASK, 1);
	if (err < 0)
		return err;

	msleep(2000);

	return regmap_update_bits(hw->regmap, ST_UVIS25_REG_CTRL1_ADDR,
				  ST_UVIS25_REG_BDU_MASK, 1);
}

int st_uvis25_probe(struct device *dev, int irq, struct regmap *regmap)
{
	struct st_uvis25_hw *hw;
	struct iio_dev *iio_dev;
	int err;

	iio_dev = devm_iio_device_alloc(dev, sizeof(*hw));
	if (!iio_dev)
		return -ENOMEM;

	dev_set_drvdata(dev, (void *)iio_dev);

	hw = iio_priv(iio_dev);
	hw->irq = irq;
	hw->regmap = regmap;

	err = st_uvis25_check_whoami(hw);
	if (err < 0)
		return err;

	iio_dev->modes = INDIO_DIRECT_MODE;
	iio_dev->dev.parent = dev;
	iio_dev->channels = st_uvis25_channels;
	iio_dev->num_channels = ARRAY_SIZE(st_uvis25_channels);
	iio_dev->name = ST_UVIS25_DEV_NAME;
	iio_dev->info = &st_uvis25_info;

	err = st_uvis25_init_sensor(hw);
	if (err < 0)
		return err;

	if (hw->irq > 0) {
		err = st_uvis25_allocate_buffer(iio_dev);
		if (err < 0)
			return err;

		err = st_uvis25_allocate_trigger(iio_dev);
		if (err)
			return err;
	}

	return devm_iio_device_register(dev, iio_dev);
}


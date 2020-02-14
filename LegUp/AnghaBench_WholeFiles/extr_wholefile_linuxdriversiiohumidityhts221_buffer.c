#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct st_sensors_platform_data {scalar_t__ open_drain; } ;
struct iio_trigger {int dummy; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct iio_dev {struct iio_chan_spec* channels; int /*<<< orphan*/  trig; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct hts221_hw {TYPE_6__* dev; TYPE_2__* trig; int /*<<< orphan*/  regmap; int /*<<< orphan*/  irq; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_16__ {scalar_t__ platform_data; struct device_node* of_node; } ;
struct TYPE_14__ {TYPE_6__* parent; } ;
struct TYPE_15__ {TYPE_1__ dev; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALIGN (int,int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FIELD_PREP (int /*<<< orphan*/ ,int) ; 
 int HTS221_DATA_SIZE ; 
 int /*<<< orphan*/  HTS221_REG_DRDY_EN_ADDR ; 
 int /*<<< orphan*/  HTS221_REG_DRDY_EN_MASK ; 
 int /*<<< orphan*/  HTS221_REG_DRDY_HL_ADDR ; 
 int /*<<< orphan*/  HTS221_REG_DRDY_HL_MASK ; 
 int /*<<< orphan*/  HTS221_REG_DRDY_PP_OD_ADDR ; 
 int /*<<< orphan*/  HTS221_REG_DRDY_PP_OD_MASK ; 
 int /*<<< orphan*/  HTS221_REG_STATUS_ADDR ; 
 int HTS221_RH_DRDY_MASK ; 
 size_t HTS221_SENSOR_H ; 
 size_t HTS221_SENSOR_T ; 
 unsigned long IRQF_ONESHOT ; 
 unsigned long IRQF_SHARED ; 
#define  IRQF_TRIGGER_FALLING 131 
#define  IRQF_TRIGGER_HIGH 130 
#define  IRQF_TRIGGER_LOW 129 
#define  IRQF_TRIGGER_RISING 128 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (TYPE_6__*,char*,unsigned long) ; 
 TYPE_2__* devm_iio_trigger_alloc (TYPE_6__*,char*,int /*<<< orphan*/ ) ; 
 int devm_iio_trigger_register (TYPE_6__*,TYPE_2__*) ; 
 int devm_iio_triggered_buffer_setup (TYPE_6__*,struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int devm_request_threaded_irq (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),unsigned long,int /*<<< orphan*/ ,struct hts221_hw*) ; 
 int /*<<< orphan*/  hts221_buffer_ops ; 
 int hts221_set_enable (struct hts221_hw*,int) ; 
 int /*<<< orphan*/  hts221_trigger_ops ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct hts221_hw* iio_priv (struct iio_dev*) ; 
 struct iio_dev* iio_priv_to_dev (struct hts221_hw*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_get (TYPE_2__*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (TYPE_2__*) ; 
 int /*<<< orphan*/  iio_trigger_poll_chained (TYPE_2__*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_2__*,struct iio_dev*) ; 
 int /*<<< orphan*/  irq_get_irq_data (int /*<<< orphan*/ ) ; 
 unsigned long irqd_get_trigger_type (int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hts221_trig_set_state(struct iio_trigger *trig, bool state)
{
	struct iio_dev *iio_dev = iio_trigger_get_drvdata(trig);
	struct hts221_hw *hw = iio_priv(iio_dev);

	return regmap_update_bits(hw->regmap, HTS221_REG_DRDY_EN_ADDR,
				  HTS221_REG_DRDY_EN_MASK,
				  FIELD_PREP(HTS221_REG_DRDY_EN_MASK, state));
}

__attribute__((used)) static irqreturn_t hts221_trigger_handler_thread(int irq, void *private)
{
	struct hts221_hw *hw = private;
	int err, status;

	err = regmap_read(hw->regmap, HTS221_REG_STATUS_ADDR, &status);
	if (err < 0)
		return IRQ_HANDLED;

	/*
	 * H_DA bit (humidity data available) is routed to DRDY line.
	 * Humidity sample is computed after temperature one.
	 * Here we can assume data channels are both available if H_DA bit
	 * is set in status register
	 */
	if (!(status & HTS221_RH_DRDY_MASK))
		return IRQ_NONE;

	iio_trigger_poll_chained(hw->trig);

	return IRQ_HANDLED;
}

int hts221_allocate_trigger(struct hts221_hw *hw)
{
	struct iio_dev *iio_dev = iio_priv_to_dev(hw);
	bool irq_active_low = false, open_drain = false;
	struct device_node *np = hw->dev->of_node;
	struct st_sensors_platform_data *pdata;
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
		dev_info(hw->dev,
			 "mode %lx unsupported, using IRQF_TRIGGER_RISING\n",
			 irq_type);
		irq_type = IRQF_TRIGGER_RISING;
		break;
	}

	err = regmap_update_bits(hw->regmap, HTS221_REG_DRDY_HL_ADDR,
				 HTS221_REG_DRDY_HL_MASK,
				 FIELD_PREP(HTS221_REG_DRDY_HL_MASK,
					    irq_active_low));
	if (err < 0)
		return err;

	pdata = (struct st_sensors_platform_data *)hw->dev->platform_data;
	if ((np && of_property_read_bool(np, "drive-open-drain")) ||
	    (pdata && pdata->open_drain)) {
		irq_type |= IRQF_SHARED;
		open_drain = true;
	}

	err = regmap_update_bits(hw->regmap, HTS221_REG_DRDY_PP_OD_ADDR,
				 HTS221_REG_DRDY_PP_OD_MASK,
				 FIELD_PREP(HTS221_REG_DRDY_PP_OD_MASK,
					    open_drain));
	if (err < 0)
		return err;

	err = devm_request_threaded_irq(hw->dev, hw->irq, NULL,
					hts221_trigger_handler_thread,
					irq_type | IRQF_ONESHOT,
					hw->name, hw);
	if (err) {
		dev_err(hw->dev, "failed to request trigger irq %d\n",
			hw->irq);
		return err;
	}

	hw->trig = devm_iio_trigger_alloc(hw->dev, "%s-trigger",
					  iio_dev->name);
	if (!hw->trig)
		return -ENOMEM;

	iio_trigger_set_drvdata(hw->trig, iio_dev);
	hw->trig->ops = &hts221_trigger_ops;
	hw->trig->dev.parent = hw->dev;
	iio_dev->trig = iio_trigger_get(hw->trig);

	return devm_iio_trigger_register(hw->dev, hw->trig);
}

__attribute__((used)) static int hts221_buffer_preenable(struct iio_dev *iio_dev)
{
	return hts221_set_enable(iio_priv(iio_dev), true);
}

__attribute__((used)) static int hts221_buffer_postdisable(struct iio_dev *iio_dev)
{
	return hts221_set_enable(iio_priv(iio_dev), false);
}

__attribute__((used)) static irqreturn_t hts221_buffer_handler_thread(int irq, void *p)
{
	u8 buffer[ALIGN(2 * HTS221_DATA_SIZE, sizeof(s64)) + sizeof(s64)];
	struct iio_poll_func *pf = p;
	struct iio_dev *iio_dev = pf->indio_dev;
	struct hts221_hw *hw = iio_priv(iio_dev);
	struct iio_chan_spec const *ch;
	int err;

	/* humidity data */
	ch = &iio_dev->channels[HTS221_SENSOR_H];
	err = regmap_bulk_read(hw->regmap, ch->address,
			       buffer, HTS221_DATA_SIZE);
	if (err < 0)
		goto out;

	/* temperature data */
	ch = &iio_dev->channels[HTS221_SENSOR_T];
	err = regmap_bulk_read(hw->regmap, ch->address,
			       buffer + HTS221_DATA_SIZE, HTS221_DATA_SIZE);
	if (err < 0)
		goto out;

	iio_push_to_buffers_with_timestamp(iio_dev, buffer,
					   iio_get_time_ns(iio_dev));

out:
	iio_trigger_notify_done(hw->trig);

	return IRQ_HANDLED;
}

int hts221_allocate_buffers(struct hts221_hw *hw)
{
	return devm_iio_triggered_buffer_setup(hw->dev, iio_priv_to_dev(hw),
					NULL, hts221_buffer_handler_thread,
					&hts221_buffer_ops);
}


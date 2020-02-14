#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct itg3200 {TYPE_2__* trig; struct i2c_client* i2c; } ;
struct iio_trigger {int dummy; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct iio_dev {int /*<<< orphan*/  trig; int /*<<< orphan*/  id; int /*<<< orphan*/  name; } ;
struct i2c_msg {int flags; int len; int* buf; int /*<<< orphan*/  addr; } ;
struct i2c_client {int flags; int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  s16 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_10__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_11__ {int /*<<< orphan*/ * ops; TYPE_1__ dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int ITG3200_IRQ_DATA_RDY_ENABLE ; 
 int /*<<< orphan*/  ITG3200_REG_IRQ_CONFIG ; 
 int ITG3200_REG_TEMP_OUT_H ; 
 int ITG3200_SCAN_ELEMENTS ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct itg3200* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_2__* iio_trigger_alloc (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_free (TYPE_2__*) ; 
 int /*<<< orphan*/  iio_trigger_generic_data_rdy_poll ; 
 int /*<<< orphan*/  iio_trigger_get (TYPE_2__*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int iio_trigger_register (TYPE_2__*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_2__*,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (TYPE_2__*) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int itg3200_read_reg_8 (struct iio_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  itg3200_trigger_ops ; 
 int itg3200_write_reg_8 (struct iio_dev*,int /*<<< orphan*/ ,int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,TYPE_2__*) ; 

__attribute__((used)) static int itg3200_read_all_channels(struct i2c_client *i2c, __be16 *buf)
{
	u8 tx = 0x80 | ITG3200_REG_TEMP_OUT_H;
	struct i2c_msg msg[2] = {
		{
			.addr = i2c->addr,
			.flags = i2c->flags,
			.len = 1,
			.buf = &tx,
		},
		{
			.addr = i2c->addr,
			.flags = i2c->flags | I2C_M_RD,
			.len = ITG3200_SCAN_ELEMENTS * sizeof(s16),
			.buf = (char *)&buf,
		},
	};

	return i2c_transfer(i2c->adapter, msg, 2);
}

__attribute__((used)) static irqreturn_t itg3200_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct itg3200 *st = iio_priv(indio_dev);
	__be16 buf[ITG3200_SCAN_ELEMENTS + sizeof(s64)/sizeof(u16)];

	int ret = itg3200_read_all_channels(st->i2c, buf);
	if (ret < 0)
		goto error_ret;

	iio_push_to_buffers_with_timestamp(indio_dev, buf, pf->timestamp);

	iio_trigger_notify_done(indio_dev->trig);

error_ret:
	return IRQ_HANDLED;
}

int itg3200_buffer_configure(struct iio_dev *indio_dev)
{
	return iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
		itg3200_trigger_handler, NULL);
}

void itg3200_buffer_unconfigure(struct iio_dev *indio_dev)
{
	iio_triggered_buffer_cleanup(indio_dev);
}

__attribute__((used)) static int itg3200_data_rdy_trigger_set_state(struct iio_trigger *trig,
		bool state)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	int ret;
	u8 msc;

	ret = itg3200_read_reg_8(indio_dev, ITG3200_REG_IRQ_CONFIG, &msc);
	if (ret)
		goto error_ret;

	if (state)
		msc |= ITG3200_IRQ_DATA_RDY_ENABLE;
	else
		msc &= ~ITG3200_IRQ_DATA_RDY_ENABLE;

	ret = itg3200_write_reg_8(indio_dev, ITG3200_REG_IRQ_CONFIG, msc);
	if (ret)
		goto error_ret;

error_ret:
	return ret;

}

int itg3200_probe_trigger(struct iio_dev *indio_dev)
{
	int ret;
	struct itg3200 *st = iio_priv(indio_dev);

	st->trig = iio_trigger_alloc("%s-dev%d", indio_dev->name,
				     indio_dev->id);
	if (!st->trig)
		return -ENOMEM;

	ret = request_irq(st->i2c->irq,
			  &iio_trigger_generic_data_rdy_poll,
			  IRQF_TRIGGER_RISING,
			  "itg3200_data_rdy",
			  st->trig);
	if (ret)
		goto error_free_trig;


	st->trig->dev.parent = &st->i2c->dev;
	st->trig->ops = &itg3200_trigger_ops;
	iio_trigger_set_drvdata(st->trig, indio_dev);
	ret = iio_trigger_register(st->trig);
	if (ret)
		goto error_free_irq;

	/* select default trigger */
	indio_dev->trig = iio_trigger_get(st->trig);

	return 0;

error_free_irq:
	free_irq(st->i2c->irq, st->trig);
error_free_trig:
	iio_trigger_free(st->trig);
	return ret;
}

void itg3200_remove_trigger(struct iio_dev *indio_dev)
{
	struct itg3200 *st = iio_priv(indio_dev);

	iio_trigger_unregister(st->trig);
	free_irq(st->i2c->irq, st->trig);
	iio_trigger_free(st->trig);
}


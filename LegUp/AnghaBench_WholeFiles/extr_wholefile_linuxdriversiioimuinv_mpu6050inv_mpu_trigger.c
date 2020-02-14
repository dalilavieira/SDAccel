#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int gyro_fifo_enable; int accl_fifo_enable; int /*<<< orphan*/  user_ctrl; } ;
struct inv_mpu6050_state {int skip_samples; TYPE_4__* trig; int /*<<< orphan*/  map; int /*<<< orphan*/  irq; int /*<<< orphan*/  lock; TYPE_2__ chip_config; TYPE_1__* reg; } ;
struct iio_trigger {int dummy; } ;
struct iio_dev {int /*<<< orphan*/  trig; int /*<<< orphan*/  dev; int /*<<< orphan*/  id; int /*<<< orphan*/  name; int /*<<< orphan*/  active_scan_mask; } ;
struct TYPE_11__ {int /*<<< orphan*/  parent; } ;
struct TYPE_12__ {int /*<<< orphan*/ * ops; TYPE_3__ dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  user_ctrl; int /*<<< orphan*/  int_enable; int /*<<< orphan*/  fifo_en; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  INV_MPU6050_BIT_PWR_ACCL_STBY ; 
 int /*<<< orphan*/  INV_MPU6050_BIT_PWR_GYRO_STBY ; 
 int /*<<< orphan*/  INV_MPU6050_SCAN_ACCL_X ; 
 int /*<<< orphan*/  INV_MPU6050_SCAN_ACCL_Y ; 
 int /*<<< orphan*/  INV_MPU6050_SCAN_ACCL_Z ; 
 int /*<<< orphan*/  INV_MPU6050_SCAN_GYRO_X ; 
 int /*<<< orphan*/  INV_MPU6050_SCAN_GYRO_Y ; 
 int /*<<< orphan*/  INV_MPU6050_SCAN_GYRO_Z ; 
 TYPE_4__* devm_iio_trigger_alloc (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_iio_trigger_register (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,char*,TYPE_4__*) ; 
 struct inv_mpu6050_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_trigger_generic_data_rdy_poll ; 
 int /*<<< orphan*/  iio_trigger_get (TYPE_4__*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_4__*,struct iio_dev*) ; 
 int inv_mpu6050_set_power_itg (struct inv_mpu6050_state*,int) ; 
 int inv_mpu6050_switch_engine (struct inv_mpu6050_state*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inv_mpu_trigger_ops ; 
 int inv_reset_fifo (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regmap_get_device (int /*<<< orphan*/ ) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void inv_scan_query(struct iio_dev *indio_dev)
{
	struct inv_mpu6050_state  *st = iio_priv(indio_dev);

	st->chip_config.gyro_fifo_enable =
		test_bit(INV_MPU6050_SCAN_GYRO_X,
			 indio_dev->active_scan_mask) ||
		test_bit(INV_MPU6050_SCAN_GYRO_Y,
			 indio_dev->active_scan_mask) ||
		test_bit(INV_MPU6050_SCAN_GYRO_Z,
			 indio_dev->active_scan_mask);

	st->chip_config.accl_fifo_enable =
		test_bit(INV_MPU6050_SCAN_ACCL_X,
			 indio_dev->active_scan_mask) ||
		test_bit(INV_MPU6050_SCAN_ACCL_Y,
			 indio_dev->active_scan_mask) ||
		test_bit(INV_MPU6050_SCAN_ACCL_Z,
			 indio_dev->active_scan_mask);
}

__attribute__((used)) static int inv_mpu6050_set_enable(struct iio_dev *indio_dev, bool enable)
{
	struct inv_mpu6050_state *st = iio_priv(indio_dev);
	int result;

	if (enable) {
		result = inv_mpu6050_set_power_itg(st, true);
		if (result)
			return result;
		inv_scan_query(indio_dev);
		st->skip_samples = 0;
		if (st->chip_config.gyro_fifo_enable) {
			result = inv_mpu6050_switch_engine(st, true,
					INV_MPU6050_BIT_PWR_GYRO_STBY);
			if (result)
				goto error_power_off;
			/* gyro first sample is out of specs, skip it */
			st->skip_samples = 1;
		}
		if (st->chip_config.accl_fifo_enable) {
			result = inv_mpu6050_switch_engine(st, true,
					INV_MPU6050_BIT_PWR_ACCL_STBY);
			if (result)
				goto error_gyro_off;
		}
		result = inv_reset_fifo(indio_dev);
		if (result)
			goto error_accl_off;
	} else {
		result = regmap_write(st->map, st->reg->fifo_en, 0);
		if (result)
			goto error_accl_off;

		result = regmap_write(st->map, st->reg->int_enable, 0);
		if (result)
			goto error_accl_off;

		result = regmap_write(st->map, st->reg->user_ctrl,
				      st->chip_config.user_ctrl);
		if (result)
			goto error_accl_off;

		result = inv_mpu6050_switch_engine(st, false,
					INV_MPU6050_BIT_PWR_ACCL_STBY);
		if (result)
			goto error_accl_off;

		result = inv_mpu6050_switch_engine(st, false,
					INV_MPU6050_BIT_PWR_GYRO_STBY);
		if (result)
			goto error_gyro_off;

		result = inv_mpu6050_set_power_itg(st, false);
		if (result)
			goto error_power_off;
	}

	return 0;

error_accl_off:
	if (st->chip_config.accl_fifo_enable)
		inv_mpu6050_switch_engine(st, false,
					  INV_MPU6050_BIT_PWR_ACCL_STBY);
error_gyro_off:
	if (st->chip_config.gyro_fifo_enable)
		inv_mpu6050_switch_engine(st, false,
					  INV_MPU6050_BIT_PWR_GYRO_STBY);
error_power_off:
	inv_mpu6050_set_power_itg(st, false);
	return result;
}

__attribute__((used)) static int inv_mpu_data_rdy_trigger_set_state(struct iio_trigger *trig,
					      bool state)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct inv_mpu6050_state *st = iio_priv(indio_dev);
	int result;

	mutex_lock(&st->lock);
	result = inv_mpu6050_set_enable(indio_dev, state);
	mutex_unlock(&st->lock);

	return result;
}

int inv_mpu6050_probe_trigger(struct iio_dev *indio_dev, int irq_type)
{
	int ret;
	struct inv_mpu6050_state *st = iio_priv(indio_dev);

	st->trig = devm_iio_trigger_alloc(&indio_dev->dev,
					  "%s-dev%d",
					  indio_dev->name,
					  indio_dev->id);
	if (!st->trig)
		return -ENOMEM;

	ret = devm_request_irq(&indio_dev->dev, st->irq,
			       &iio_trigger_generic_data_rdy_poll,
			       irq_type,
			       "inv_mpu",
			       st->trig);
	if (ret)
		return ret;

	st->trig->dev.parent = regmap_get_device(st->map);
	st->trig->ops = &inv_mpu_trigger_ops;
	iio_trigger_set_drvdata(st->trig, indio_dev);

	ret = devm_iio_trigger_register(&indio_dev->dev, st->trig);
	if (ret)
		return ret;

	indio_dev->trig = iio_trigger_get(st->trig);

	return 0;
}


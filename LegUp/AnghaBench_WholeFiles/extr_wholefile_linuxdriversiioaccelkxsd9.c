#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct regmap {int dummy; } ;
struct iio_mount_matrix {int dummy; } ;
struct kxsd9_state {int scale; TYPE_2__* regs; struct iio_mount_matrix const orientation; struct regmap* map; struct device* dev; } ;
struct iio_poll_func {struct iio_dev const* indio_dev; } ;
struct TYPE_7__ {struct device* parent; } ;
typedef  struct iio_dev {char const* name; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  num_channels; TYPE_2__* channels; int /*<<< orphan*/  trig; } const iio_dev ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  raw_val ;
typedef  int irqreturn_t ;
typedef  int /*<<< orphan*/ **** __be16 ;
struct TYPE_8__ {int /*<<< orphan*/  supply; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQ_HANDLED ; 
 unsigned int KXSD9_CTRL_B_ENABLE ; 
 unsigned int KXSD9_CTRL_C_FS_2G ; 
 unsigned int KXSD9_CTRL_C_FS_MASK ; 
 unsigned int KXSD9_CTRL_C_LP_1000HZ ; 
 unsigned int KXSD9_CTRL_C_MOT_LAT ; 
 unsigned int KXSD9_CTRL_C_MOT_LEV ; 
 int /*<<< orphan*/  KXSD9_REG_CTRL_B ; 
 int /*<<< orphan*/  KXSD9_REG_CTRL_C ; 
 int /*<<< orphan*/  KXSD9_REG_X ; 
 int KXSD9_ZERO_G_OFFSET ; 
 int be16_to_cpu (int /*<<< orphan*/ ****) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct iio_dev const* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev const*) ; 
 struct iio_dev const* devm_iio_device_alloc (struct device*,int) ; 
 int devm_regulator_bulk_get (struct device*,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int iio_device_register (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct kxsd9_state* iio_priv (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev const*,int /*<<< orphan*/ *****,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev const*) ; 
 int iio_triggered_buffer_setup (struct iio_dev const*,int /*<<< orphan*/ ,int (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kxsd9_buffer_setup_ops ; 
 TYPE_2__* kxsd9_channels ; 
 int /*<<< orphan*/  kxsd9_info ; 
 int* kxsd9_micro_scales ; 
 int /*<<< orphan*/  kxsd9_reg_iovdd ; 
 int /*<<< orphan*/  kxsd9_reg_vdd ; 
 int /*<<< orphan*/  kxsd9_scan_masks ; 
 int /*<<< orphan*/  msleep (int) ; 
 int of_iio_read_mount_matrix (struct device*,char*,struct iio_mount_matrix const*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (struct device*,int) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (struct device*) ; 
 int regmap_bulk_read (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ******,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,int) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,unsigned int) ; 
 int regulator_bulk_disable (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int regulator_bulk_enable (int /*<<< orphan*/ ,TYPE_2__*) ; 

__attribute__((used)) static int kxsd9_write_scale(struct iio_dev *indio_dev, int micro)
{
	int ret, i;
	struct kxsd9_state *st = iio_priv(indio_dev);
	bool foundit = false;

	for (i = 0; i < 4; i++)
		if (micro == kxsd9_micro_scales[i]) {
			foundit = true;
			break;
		}
	if (!foundit)
		return -EINVAL;

	ret = regmap_update_bits(st->map,
				 KXSD9_REG_CTRL_C,
				 KXSD9_CTRL_C_FS_MASK,
				 i);
	if (ret < 0)
		goto error_ret;

	/* Cached scale when the sensor is powered down */
	st->scale = i;

error_ret:
	return ret;
}

__attribute__((used)) static int kxsd9_write_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int val,
			   int val2,
			   long mask)
{
	int ret = -EINVAL;
	struct kxsd9_state *st = iio_priv(indio_dev);

	pm_runtime_get_sync(st->dev);

	if (mask == IIO_CHAN_INFO_SCALE) {
		/* Check no integer component */
		if (val)
			return -EINVAL;
		ret = kxsd9_write_scale(indio_dev, val2);
	}

	pm_runtime_mark_last_busy(st->dev);
	pm_runtime_put_autosuspend(st->dev);

	return ret;
}

__attribute__((used)) static int kxsd9_read_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *chan,
			  int *val, int *val2, long mask)
{
	int ret = -EINVAL;
	struct kxsd9_state *st = iio_priv(indio_dev);
	unsigned int regval;
	__be16 raw_val;
	u16 nval;

	pm_runtime_get_sync(st->dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = regmap_bulk_read(st->map, chan->address, &raw_val,
				       sizeof(raw_val));
		if (ret)
			goto error_ret;
		nval = be16_to_cpu(raw_val);
		/* Only 12 bits are valid */
		nval >>= 4;
		*val = nval;
		ret = IIO_VAL_INT;
		break;
	case IIO_CHAN_INFO_OFFSET:
		/* This has a bias of -2048 */
		*val = KXSD9_ZERO_G_OFFSET;
		ret = IIO_VAL_INT;
		break;
	case IIO_CHAN_INFO_SCALE:
		ret = regmap_read(st->map,
				  KXSD9_REG_CTRL_C,
				  &regval);
		if (ret < 0)
			goto error_ret;
		*val = 0;
		*val2 = kxsd9_micro_scales[regval & KXSD9_CTRL_C_FS_MASK];
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;
	}

error_ret:
	pm_runtime_mark_last_busy(st->dev);
	pm_runtime_put_autosuspend(st->dev);

	return ret;
}

__attribute__((used)) static irqreturn_t kxsd9_trigger_handler(int irq, void *p)
{
	const struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct kxsd9_state *st = iio_priv(indio_dev);
	int ret;
	/* 4 * 16bit values AND timestamp */
	__be16 hw_values[8];

	ret = regmap_bulk_read(st->map,
			       KXSD9_REG_X,
			       &hw_values,
			       8);
	if (ret) {
		dev_err(st->dev,
			"error reading data\n");
		return ret;
	}

	iio_push_to_buffers_with_timestamp(indio_dev,
					   hw_values,
					   iio_get_time_ns(indio_dev));
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int kxsd9_buffer_preenable(struct iio_dev *indio_dev)
{
	struct kxsd9_state *st = iio_priv(indio_dev);

	pm_runtime_get_sync(st->dev);

	return 0;
}

__attribute__((used)) static int kxsd9_buffer_postdisable(struct iio_dev *indio_dev)
{
	struct kxsd9_state *st = iio_priv(indio_dev);

	pm_runtime_mark_last_busy(st->dev);
	pm_runtime_put_autosuspend(st->dev);

	return 0;
}

__attribute__((used)) static const struct iio_mount_matrix *
kxsd9_get_mount_matrix(const struct iio_dev *indio_dev,
		       const struct iio_chan_spec *chan)
{
	struct kxsd9_state *st = iio_priv(indio_dev);

	return &st->orientation;
}

__attribute__((used)) static int kxsd9_power_up(struct kxsd9_state *st)
{
	int ret;

	/* Enable the regulators */
	ret = regulator_bulk_enable(ARRAY_SIZE(st->regs), st->regs);
	if (ret) {
		dev_err(st->dev, "Cannot enable regulators\n");
		return ret;
	}

	/* Power up */
	ret = regmap_write(st->map,
			   KXSD9_REG_CTRL_B,
			   KXSD9_CTRL_B_ENABLE);
	if (ret)
		return ret;

	/*
	 * Set 1000Hz LPF, 2g fullscale, motion wakeup threshold 1g,
	 * latched wakeup
	 */
	ret = regmap_write(st->map,
			   KXSD9_REG_CTRL_C,
			   KXSD9_CTRL_C_LP_1000HZ |
			   KXSD9_CTRL_C_MOT_LEV	|
			   KXSD9_CTRL_C_MOT_LAT |
			   st->scale);
	if (ret)
		return ret;

	/*
	 * Power-up time depends on the LPF setting, but typ 15.9 ms, let's
	 * set 20 ms to allow for some slack.
	 */
	msleep(20);

	return 0;
}

__attribute__((used)) static int kxsd9_power_down(struct kxsd9_state *st)
{
	int ret;

	/*
	 * Set into low power mode - since there may be more users of the
	 * regulators this is the first step of the power saving: it will
	 * make sure we conserve power even if there are others users on the
	 * regulators.
	 */
	ret = regmap_update_bits(st->map,
				 KXSD9_REG_CTRL_B,
				 KXSD9_CTRL_B_ENABLE,
				 0);
	if (ret)
		return ret;

	/* Disable the regulators */
	ret = regulator_bulk_disable(ARRAY_SIZE(st->regs), st->regs);
	if (ret) {
		dev_err(st->dev, "Cannot disable regulators\n");
		return ret;
	}

	return 0;
}

int kxsd9_common_probe(struct device *dev,
		       struct regmap *map,
		       const char *name)
{
	struct iio_dev *indio_dev;
	struct kxsd9_state *st;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;

	st = iio_priv(indio_dev);
	st->dev = dev;
	st->map = map;

	indio_dev->channels = kxsd9_channels;
	indio_dev->num_channels = ARRAY_SIZE(kxsd9_channels);
	indio_dev->name = name;
	indio_dev->dev.parent = dev;
	indio_dev->info = &kxsd9_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->available_scan_masks = kxsd9_scan_masks;

	/* Read the mounting matrix, if present */
	ret = of_iio_read_mount_matrix(dev,
				       "mount-matrix",
				       &st->orientation);
	if (ret)
		return ret;

	/* Fetch and turn on regulators */
	st->regs[0].supply = kxsd9_reg_vdd;
	st->regs[1].supply = kxsd9_reg_iovdd;
	ret = devm_regulator_bulk_get(dev,
				      ARRAY_SIZE(st->regs),
				      st->regs);
	if (ret) {
		dev_err(dev, "Cannot get regulators\n");
		return ret;
	}
	/* Default scaling */
	st->scale = KXSD9_CTRL_C_FS_2G;

	kxsd9_power_up(st);

	ret = iio_triggered_buffer_setup(indio_dev,
					 iio_pollfunc_store_time,
					 kxsd9_trigger_handler,
					 &kxsd9_buffer_setup_ops);
	if (ret) {
		dev_err(dev, "triggered buffer setup failed\n");
		goto err_power_down;
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto err_cleanup_buffer;

	dev_set_drvdata(dev, indio_dev);

	/* Enable runtime PM */
	pm_runtime_get_noresume(dev);
	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	/*
	 * Set autosuspend to two orders of magnitude larger than the
	 * start-up time. 20ms start-up time means 2000ms autosuspend,
	 * i.e. 2 seconds.
	 */
	pm_runtime_set_autosuspend_delay(dev, 2000);
	pm_runtime_use_autosuspend(dev);
	pm_runtime_put(dev);

	return 0;

err_cleanup_buffer:
	iio_triggered_buffer_cleanup(indio_dev);
err_power_down:
	kxsd9_power_down(st);

	return ret;
}

int kxsd9_common_remove(struct device *dev)
{
	struct iio_dev *indio_dev = dev_get_drvdata(dev);
	struct kxsd9_state *st = iio_priv(indio_dev);

	iio_triggered_buffer_cleanup(indio_dev);
	iio_device_unregister(indio_dev);
	pm_runtime_get_sync(dev);
	pm_runtime_put_noidle(dev);
	pm_runtime_disable(dev);
	kxsd9_power_down(st);

	return 0;
}


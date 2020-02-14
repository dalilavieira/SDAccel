#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_9__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct pm860x_touch_pdata {int gpadc_prebias; int slot_cycle; int off_scale; int sw_cal; int tsi_prebias; int pen_prebias; int pen_prechg; int res_x; } ;
struct pm860x_touch {int res_x; int irq; TYPE_3__* idev; struct i2c_client* i2c; struct pm860x_chip* chip; } ;
struct pm860x_chip {scalar_t__ id; TYPE_9__* dev; struct i2c_client* companion; struct i2c_client* client; } ;
struct TYPE_19__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_9__ dev; } ;
struct input_dev {int dummy; } ;
struct i2c_client {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_17__ {TYPE_9__* parent; } ;
struct TYPE_16__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_18__ {char* name; char* phys; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; int /*<<< orphan*/  absbit; TYPE_2__ dev; TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_PRESSURE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int ACCURATE_BIT ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_I2C ; 
 scalar_t__ CHIP_PM8607 ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  EV_SYN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  MEAS_EN3 ; 
 int MEAS_LEN ; 
 int MEAS_PD_EN ; 
 int /*<<< orphan*/  MEAS_TSIX_1 ; 
 int MEAS_TSIX_EN ; 
 int MEAS_TSIY_EN ; 
 int MEAS_TSIZ1_EN ; 
 int MEAS_TSIZ2_EN ; 
 int PM8607_GPADC_EN ; 
 int /*<<< orphan*/  PM8607_GPADC_MISC1 ; 
 int PM8607_GPADC_OFF_SCALE_MASK ; 
 int PM8607_GPADC_PREBIAS_MASK ; 
 int PM8607_GPADC_SLOT_CYCLE_MASK ; 
 int PM8607_GPADC_SW_CAL_MASK ; 
 int /*<<< orphan*/  PM8607_PD_PREBIAS ; 
 int PM8607_PD_PREBIAS_MASK ; 
 int PM8607_PD_PRECHG_MASK ; 
 int /*<<< orphan*/  PM8607_TSI_PREBIAS ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_9__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_9__*,char*) ; 
 struct pm860x_chip* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct pm860x_touch_pdata* dev_get_platdata (TYPE_9__*) ; 
 TYPE_3__* devm_input_allocate_device (TYPE_9__*) ; 
 struct pm860x_touch* devm_kzalloc (TYPE_9__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_9__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct pm860x_touch*) ; 
 struct pm860x_touch* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (TYPE_3__*) ; 
 int /*<<< orphan*/  input_report_abs (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (TYPE_3__*,struct pm860x_touch*) ; 
 int /*<<< orphan*/  input_sync (TYPE_3__*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int pm860x_bulk_read (struct i2c_client*,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int pm860x_reg_write (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int pm860x_set_bits (struct i2c_client*,int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ pm860x_touch_dt_init (struct platform_device*,struct pm860x_chip*,int*) ; 

__attribute__((used)) static irqreturn_t pm860x_touch_handler(int irq, void *data)
{
	struct pm860x_touch *touch = data;
	struct pm860x_chip *chip = touch->chip;
	unsigned char buf[MEAS_LEN];
	int x, y, pen_down;
	int z1, z2, rt = 0;
	int ret;

	ret = pm860x_bulk_read(touch->i2c, MEAS_TSIX_1, MEAS_LEN, buf);
	if (ret < 0)
		goto out;

	pen_down = buf[1] & (1 << 6);
	x = ((buf[0] & 0xFF) << 4) | (buf[1] & 0x0F);
	y = ((buf[2] & 0xFF) << 4) | (buf[3] & 0x0F);
	z1 = ((buf[4] & 0xFF) << 4) | (buf[5] & 0x0F);
	z2 = ((buf[6] & 0xFF) << 4) | (buf[7] & 0x0F);

	if (pen_down) {
		if ((x != 0) && (z1 != 0) && (touch->res_x != 0)) {
			rt = z2 / z1 - 1;
			rt = (rt * touch->res_x * x) >> ACCURATE_BIT;
			dev_dbg(chip->dev, "z1:%d, z2:%d, rt:%d\n",
				z1, z2, rt);
		}
		input_report_abs(touch->idev, ABS_X, x);
		input_report_abs(touch->idev, ABS_Y, y);
		input_report_abs(touch->idev, ABS_PRESSURE, rt);
		input_report_key(touch->idev, BTN_TOUCH, 1);
		dev_dbg(chip->dev, "pen down at [%d, %d].\n", x, y);
	} else {
		input_report_abs(touch->idev, ABS_PRESSURE, 0);
		input_report_key(touch->idev, BTN_TOUCH, 0);
		dev_dbg(chip->dev, "pen release\n");
	}
	input_sync(touch->idev);

out:
	return IRQ_HANDLED;
}

__attribute__((used)) static int pm860x_touch_open(struct input_dev *dev)
{
	struct pm860x_touch *touch = input_get_drvdata(dev);
	int data, ret;

	data = MEAS_PD_EN | MEAS_TSIX_EN | MEAS_TSIY_EN
		| MEAS_TSIZ1_EN | MEAS_TSIZ2_EN;
	ret = pm860x_set_bits(touch->i2c, MEAS_EN3, data, data);
	if (ret < 0)
		goto out;
	return 0;
out:
	return ret;
}

__attribute__((used)) static void pm860x_touch_close(struct input_dev *dev)
{
	struct pm860x_touch *touch = input_get_drvdata(dev);
	int data;

	data = MEAS_PD_EN | MEAS_TSIX_EN | MEAS_TSIY_EN
		| MEAS_TSIZ1_EN | MEAS_TSIZ2_EN;
	pm860x_set_bits(touch->i2c, MEAS_EN3, data, 0);
}

__attribute__((used)) static int pm860x_touch_probe(struct platform_device *pdev)
{
	struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
	struct pm860x_touch_pdata *pdata = dev_get_platdata(&pdev->dev);
	struct pm860x_touch *touch;
	struct i2c_client *i2c = (chip->id == CHIP_PM8607) ? chip->client \
				 : chip->companion;
	int irq, ret, res_x = 0, data = 0;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "No IRQ resource!\n");
		return -EINVAL;
	}

	if (pm860x_touch_dt_init(pdev, chip, &res_x)) {
		if (pdata) {
			/* set GPADC MISC1 register */
			data = 0;
			data |= (pdata->gpadc_prebias << 1)
				& PM8607_GPADC_PREBIAS_MASK;
			data |= (pdata->slot_cycle << 3)
				& PM8607_GPADC_SLOT_CYCLE_MASK;
			data |= (pdata->off_scale << 5)
				& PM8607_GPADC_OFF_SCALE_MASK;
			data |= (pdata->sw_cal << 7)
				& PM8607_GPADC_SW_CAL_MASK;
			if (data) {
				ret = pm860x_reg_write(i2c,
					PM8607_GPADC_MISC1, data);
				if (ret < 0)
					return -EINVAL;
			}
			/* set tsi prebias time */
			if (pdata->tsi_prebias) {
				data = pdata->tsi_prebias;
				ret = pm860x_reg_write(i2c,
					PM8607_TSI_PREBIAS, data);
				if (ret < 0)
					return -EINVAL;
			}
			/* set prebias & prechg time of pen detect */
			data = 0;
			data |= pdata->pen_prebias
				& PM8607_PD_PREBIAS_MASK;
			data |= (pdata->pen_prechg << 5)
				& PM8607_PD_PRECHG_MASK;
			if (data) {
				ret = pm860x_reg_write(i2c,
					PM8607_PD_PREBIAS, data);
				if (ret < 0)
					return -EINVAL;
			}
			res_x = pdata->res_x;
		} else {
			dev_err(&pdev->dev, "failed to get platform data\n");
			return -EINVAL;
		}
	}
	/* enable GPADC */
	ret = pm860x_set_bits(i2c, PM8607_GPADC_MISC1, PM8607_GPADC_EN,
			      PM8607_GPADC_EN);
	if (ret)
		return ret;

	touch = devm_kzalloc(&pdev->dev, sizeof(struct pm860x_touch),
			     GFP_KERNEL);
	if (!touch)
		return -ENOMEM;

	touch->idev = devm_input_allocate_device(&pdev->dev);
	if (!touch->idev) {
		dev_err(&pdev->dev, "Failed to allocate input device!\n");
		return -ENOMEM;
	}

	touch->idev->name = "88pm860x-touch";
	touch->idev->phys = "88pm860x/input0";
	touch->idev->id.bustype = BUS_I2C;
	touch->idev->dev.parent = &pdev->dev;
	touch->idev->open = pm860x_touch_open;
	touch->idev->close = pm860x_touch_close;
	touch->chip = chip;
	touch->i2c = i2c;
	touch->irq = irq;
	touch->res_x = res_x;
	input_set_drvdata(touch->idev, touch);

	ret = devm_request_threaded_irq(&pdev->dev, touch->irq, NULL,
					pm860x_touch_handler, IRQF_ONESHOT,
					"touch", touch);
	if (ret < 0)
		return ret;

	__set_bit(EV_ABS, touch->idev->evbit);
	__set_bit(ABS_X, touch->idev->absbit);
	__set_bit(ABS_Y, touch->idev->absbit);
	__set_bit(ABS_PRESSURE, touch->idev->absbit);
	__set_bit(EV_SYN, touch->idev->evbit);
	__set_bit(EV_KEY, touch->idev->evbit);
	__set_bit(BTN_TOUCH, touch->idev->keybit);

	input_set_abs_params(touch->idev, ABS_X, 0, 1 << ACCURATE_BIT, 0, 0);
	input_set_abs_params(touch->idev, ABS_Y, 0, 1 << ACCURATE_BIT, 0, 0);
	input_set_abs_params(touch->idev, ABS_PRESSURE, 0, 1 << ACCURATE_BIT,
				0, 0);

	ret = input_register_device(touch->idev);
	if (ret < 0) {
		dev_err(chip->dev, "Failed to register touch!\n");
		return ret;
	}

	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tps6521x_pwrbutton {struct tps6521x_data* data; struct input_dev* idev; struct device* dev; int /*<<< orphan*/  regmap; int /*<<< orphan*/  phys; } ;
struct tps6521x_data {unsigned int pb_mask; char* name; int /*<<< orphan*/  reg_status; } ;
struct device {int /*<<< orphan*/  parent; int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {struct tps6521x_data* data; } ;
struct TYPE_4__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_3__ {struct device* parent; } ;
struct input_dev {char* name; TYPE_2__ id; TYPE_1__ dev; int /*<<< orphan*/  phys; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_I2C ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KEY_POWER ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 struct tps6521x_pwrbutton* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct tps6521x_pwrbutton*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_tps6521x_pb_match ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_wakeup_event (struct device*,int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 

__attribute__((used)) static irqreturn_t tps6521x_pb_irq(int irq, void *_pwr)
{
	struct tps6521x_pwrbutton *pwr = _pwr;
	const struct tps6521x_data *tps_data = pwr->data;
	unsigned int reg;
	int error;

	error = regmap_read(pwr->regmap, tps_data->reg_status, &reg);
	if (error) {
		dev_err(pwr->dev, "can't read register: %d\n", error);
		goto out;
	}

	if (reg & tps_data->pb_mask) {
		input_report_key(pwr->idev, KEY_POWER, 1);
		pm_wakeup_event(pwr->dev, 0);
	} else {
		input_report_key(pwr->idev, KEY_POWER, 0);
	}

	input_sync(pwr->idev);

out:
	return IRQ_HANDLED;
}

__attribute__((used)) static int tps6521x_pb_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct tps6521x_pwrbutton *pwr;
	struct input_dev *idev;
	const struct of_device_id *match;
	int error;
	int irq;

	match = of_match_node(of_tps6521x_pb_match, dev->of_node);
	if (!match)
		return -ENXIO;

	pwr = devm_kzalloc(dev, sizeof(*pwr), GFP_KERNEL);
	if (!pwr)
		return -ENOMEM;

	pwr->data = match->data;

	idev = devm_input_allocate_device(dev);
	if (!idev)
		return -ENOMEM;

	idev->name = pwr->data->name;
	snprintf(pwr->phys, sizeof(pwr->phys), "%s/input0",
		pwr->data->name);
	idev->phys = pwr->phys;
	idev->dev.parent = dev;
	idev->id.bustype = BUS_I2C;

	input_set_capability(idev, EV_KEY, KEY_POWER);

	pwr->regmap = dev_get_regmap(dev->parent, NULL);
	pwr->dev = dev;
	pwr->idev = idev;
	device_init_wakeup(dev, true);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(dev, "No IRQ resource!\n");
		return -EINVAL;
	}

	error = devm_request_threaded_irq(dev, irq, NULL, tps6521x_pb_irq,
					  IRQF_TRIGGER_RISING |
						IRQF_TRIGGER_FALLING |
						IRQF_ONESHOT,
					  pwr->data->name, pwr);
	if (error) {
		dev_err(dev, "failed to request IRQ #%d: %d\n", irq, error);
		return error;
	}

	error= input_register_device(idev);
	if (error) {
		dev_err(dev, "Can't register power button: %d\n", error);
		return error;
	}

	return 0;
}


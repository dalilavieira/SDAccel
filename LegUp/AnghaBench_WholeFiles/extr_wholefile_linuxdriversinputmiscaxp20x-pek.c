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
typedef  int /*<<< orphan*/  val_str ;
struct platform_device_id {scalar_t__ driver_data; } ;
struct TYPE_8__ {struct device* parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_7__ {TYPE_2__* parent; } ;
struct input_dev {char* name; char* phys; TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct axp20x_time {unsigned int idx; unsigned int time; } ;
struct axp20x_pek {int irq_dbf; int irq_dbr; struct axp20x_info* info; struct axp20x_dev* axp20x; struct input_dev* input; } ;
struct axp20x_info {unsigned int startup_mask; unsigned int shutdown_mask; struct axp20x_time* shutdown_time; struct axp20x_time* startup_time; } ;
struct axp20x_dev {scalar_t__ variant; int /*<<< orphan*/  regmap_irqc; int /*<<< orphan*/  regmap; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  AXP20X_PEK_KEY ; 
 scalar_t__ AXP288_ID ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KEY_POWER ; 
 unsigned int UINT_MAX ; 
 unsigned int abs (unsigned int) ; 
 int /*<<< orphan*/  axp20x_attribute_group ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int devm_device_add_group (TYPE_2__*,int /*<<< orphan*/ *) ; 
 struct input_dev* devm_input_allocate_device (TYPE_2__*) ; 
 struct axp20x_pek* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_any_context_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct input_dev*) ; 
 int /*<<< orphan*/  enable_irq_wake (int) ; 
 int ffs (unsigned int) ; 
 struct axp20x_pek* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct axp20x_pek*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int kstrtouint (char*,int,unsigned int*) ; 
 struct platform_device_id* platform_get_device_id (struct platform_device*) ; 
 void* platform_get_irq_byname (struct platform_device*,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct axp20x_pek*) ; 
 void* regmap_irq_get_virq (int /*<<< orphan*/ ,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int sprintf (char*,char*,unsigned int) ; 
 size_t strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 

__attribute__((used)) static ssize_t axp20x_show_attr(struct device *dev,
				const struct axp20x_time *time,
				unsigned int mask, char *buf)
{
	struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);
	unsigned int val;
	int ret, i;

	ret = regmap_read(axp20x_pek->axp20x->regmap, AXP20X_PEK_KEY, &val);
	if (ret != 0)
		return ret;

	val &= mask;
	val >>= ffs(mask) - 1;

	for (i = 0; i < 4; i++)
		if (val == time[i].idx)
			val = time[i].time;

	return sprintf(buf, "%u\n", val);
}

__attribute__((used)) static ssize_t axp20x_show_attr_startup(struct device *dev,
					struct device_attribute *attr,
					char *buf)
{
	struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);

	return axp20x_show_attr(dev, axp20x_pek->info->startup_time,
				axp20x_pek->info->startup_mask, buf);
}

__attribute__((used)) static ssize_t axp20x_show_attr_shutdown(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);

	return axp20x_show_attr(dev, axp20x_pek->info->shutdown_time,
				axp20x_pek->info->shutdown_mask, buf);
}

__attribute__((used)) static ssize_t axp20x_store_attr(struct device *dev,
				 const struct axp20x_time *time,
				 unsigned int mask, const char *buf,
				 size_t count)
{
	struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);
	char val_str[20];
	size_t len;
	int ret, i;
	unsigned int val, idx = 0;
	unsigned int best_err = UINT_MAX;

	val_str[sizeof(val_str) - 1] = '\0';
	strncpy(val_str, buf, sizeof(val_str) - 1);
	len = strlen(val_str);

	if (len && val_str[len - 1] == '\n')
		val_str[len - 1] = '\0';

	ret = kstrtouint(val_str, 10, &val);
	if (ret)
		return ret;

	for (i = 3; i >= 0; i--) {
		unsigned int err;

		err = abs(time[i].time - val);
		if (err < best_err) {
			best_err = err;
			idx = time[i].idx;
		}

		if (!err)
			break;
	}

	idx <<= ffs(mask) - 1;
	ret = regmap_update_bits(axp20x_pek->axp20x->regmap, AXP20X_PEK_KEY,
				 mask, idx);
	if (ret != 0)
		return -EINVAL;

	return count;
}

__attribute__((used)) static ssize_t axp20x_store_attr_startup(struct device *dev,
					 struct device_attribute *attr,
					 const char *buf, size_t count)
{
	struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);

	return axp20x_store_attr(dev, axp20x_pek->info->startup_time,
				 axp20x_pek->info->startup_mask, buf, count);
}

__attribute__((used)) static ssize_t axp20x_store_attr_shutdown(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t count)
{
	struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);

	return axp20x_store_attr(dev, axp20x_pek->info->shutdown_time,
				 axp20x_pek->info->shutdown_mask, buf, count);
}

__attribute__((used)) static irqreturn_t axp20x_pek_irq(int irq, void *pwr)
{
	struct input_dev *idev = pwr;
	struct axp20x_pek *axp20x_pek = input_get_drvdata(idev);

	/*
	 * The power-button is connected to ground so a falling edge (dbf)
	 * means it is pressed.
	 */
	if (irq == axp20x_pek->irq_dbf)
		input_report_key(idev, KEY_POWER, true);
	else if (irq == axp20x_pek->irq_dbr)
		input_report_key(idev, KEY_POWER, false);

	input_sync(idev);

	return IRQ_HANDLED;
}

__attribute__((used)) static int axp20x_pek_probe_input_device(struct axp20x_pek *axp20x_pek,
					 struct platform_device *pdev)
{
	struct axp20x_dev *axp20x = axp20x_pek->axp20x;
	struct input_dev *idev;
	int error;

	axp20x_pek->irq_dbr = platform_get_irq_byname(pdev, "PEK_DBR");
	if (axp20x_pek->irq_dbr < 0) {
		dev_err(&pdev->dev, "No IRQ for PEK_DBR, error=%d\n",
				axp20x_pek->irq_dbr);
		return axp20x_pek->irq_dbr;
	}
	axp20x_pek->irq_dbr = regmap_irq_get_virq(axp20x->regmap_irqc,
						  axp20x_pek->irq_dbr);

	axp20x_pek->irq_dbf = platform_get_irq_byname(pdev, "PEK_DBF");
	if (axp20x_pek->irq_dbf < 0) {
		dev_err(&pdev->dev, "No IRQ for PEK_DBF, error=%d\n",
				axp20x_pek->irq_dbf);
		return axp20x_pek->irq_dbf;
	}
	axp20x_pek->irq_dbf = regmap_irq_get_virq(axp20x->regmap_irqc,
						  axp20x_pek->irq_dbf);

	axp20x_pek->input = devm_input_allocate_device(&pdev->dev);
	if (!axp20x_pek->input)
		return -ENOMEM;

	idev = axp20x_pek->input;

	idev->name = "axp20x-pek";
	idev->phys = "m1kbd/input2";
	idev->dev.parent = &pdev->dev;

	input_set_capability(idev, EV_KEY, KEY_POWER);

	input_set_drvdata(idev, axp20x_pek);

	error = devm_request_any_context_irq(&pdev->dev, axp20x_pek->irq_dbr,
					     axp20x_pek_irq, 0,
					     "axp20x-pek-dbr", idev);
	if (error < 0) {
		dev_err(&pdev->dev, "Failed to request dbr IRQ#%d: %d\n",
			axp20x_pek->irq_dbr, error);
		return error;
	}

	error = devm_request_any_context_irq(&pdev->dev, axp20x_pek->irq_dbf,
					  axp20x_pek_irq, 0,
					  "axp20x-pek-dbf", idev);
	if (error < 0) {
		dev_err(&pdev->dev, "Failed to request dbf IRQ#%d: %d\n",
			axp20x_pek->irq_dbf, error);
		return error;
	}

	error = input_register_device(idev);
	if (error) {
		dev_err(&pdev->dev, "Can't register input device: %d\n",
			error);
		return error;
	}

	if (axp20x_pek->axp20x->variant == AXP288_ID)
		enable_irq_wake(axp20x_pek->irq_dbr);

	return 0;
}

__attribute__((used)) static bool axp20x_pek_should_register_input(struct axp20x_pek *axp20x_pek,
					     struct platform_device *pdev)
{
	return true;
}

__attribute__((used)) static int axp20x_pek_probe(struct platform_device *pdev)
{
	struct axp20x_pek *axp20x_pek;
	const struct platform_device_id *match = platform_get_device_id(pdev);
	int error;

	if (!match) {
		dev_err(&pdev->dev, "Failed to get platform_device_id\n");
		return -EINVAL;
	}

	axp20x_pek = devm_kzalloc(&pdev->dev, sizeof(struct axp20x_pek),
				  GFP_KERNEL);
	if (!axp20x_pek)
		return -ENOMEM;

	axp20x_pek->axp20x = dev_get_drvdata(pdev->dev.parent);

	if (axp20x_pek_should_register_input(axp20x_pek, pdev)) {
		error = axp20x_pek_probe_input_device(axp20x_pek, pdev);
		if (error)
			return error;
	}

	axp20x_pek->info = (struct axp20x_info *)match->driver_data;

	error = devm_device_add_group(&pdev->dev, &axp20x_attribute_group);
	if (error) {
		dev_err(&pdev->dev, "Failed to create sysfs attributes: %d\n",
			error);
		return error;
	}

	platform_set_drvdata(pdev, axp20x_pek);

	return 0;
}


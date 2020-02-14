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
typedef  size_t u8 ;
struct tps65910_board {int vmbch_threshold; int vmbch2_threshold; } ;
struct tps65910 {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct attribute {int /*<<< orphan*/  name; } ;
struct device_attribute {struct attribute attr; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct comparator {int uV_max; int* vsel_table; int /*<<< orphan*/  reg; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int COMP1 ; 
 int COMP2 ; 
 int EINVAL ; 
 int /*<<< orphan*/  dev_attr_comp1_threshold ; 
 int /*<<< orphan*/  dev_attr_comp2_threshold ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 struct tps65910* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct tps65910_board* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int device_create_file (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int tps65910_reg_read (struct tps65910*,int /*<<< orphan*/ ,unsigned int*) ; 
 int tps65910_reg_write (struct tps65910*,int /*<<< orphan*/ ,size_t) ; 
 struct comparator* tps_comparators ; 

__attribute__((used)) static int comp_threshold_set(struct tps65910 *tps65910, int id, int voltage)
{
	struct comparator tps_comp = tps_comparators[id];
	int curr_voltage = 0;
	int ret;
	u8 index = 0, val;

	while (curr_voltage < tps_comp.uV_max) {
		curr_voltage = tps_comp.vsel_table[index];
		if (curr_voltage >= voltage)
			break;
		else if (curr_voltage < voltage)
			index ++;
	}

	if (curr_voltage > tps_comp.uV_max)
		return -EINVAL;

	val = index << 1;
	ret = tps65910_reg_write(tps65910, tps_comp.reg, val);

	return ret;
}

__attribute__((used)) static int comp_threshold_get(struct tps65910 *tps65910, int id)
{
	struct comparator tps_comp = tps_comparators[id];
	unsigned int val;
	int ret;

	ret = tps65910_reg_read(tps65910, tps_comp.reg, &val);
	if (ret < 0)
		return ret;

	val >>= 1;
	return tps_comp.vsel_table[val];
}

__attribute__((used)) static ssize_t comp_threshold_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct tps65910 *tps65910 = dev_get_drvdata(dev->parent);
	struct attribute comp_attr = attr->attr;
	int id, uVolt;

	if (!strcmp(comp_attr.name, "comp1_threshold"))
		id = COMP1;
	else if (!strcmp(comp_attr.name, "comp2_threshold"))
		id = COMP2;
	else
		return -EINVAL;

	uVolt = comp_threshold_get(tps65910, id);

	return sprintf(buf, "%d\n", uVolt);
}

__attribute__((used)) static int tps65911_comparator_probe(struct platform_device *pdev)
{
	struct tps65910 *tps65910 = dev_get_drvdata(pdev->dev.parent);
	struct tps65910_board *pdata = dev_get_platdata(tps65910->dev);
	int ret;

	ret = comp_threshold_set(tps65910, COMP1,  pdata->vmbch_threshold);
	if (ret < 0) {
		dev_err(&pdev->dev, "cannot set COMP1 threshold\n");
		return ret;
	}

	ret = comp_threshold_set(tps65910, COMP2, pdata->vmbch2_threshold);
	if (ret < 0) {
		dev_err(&pdev->dev, "cannot set COMP2 threshold\n");
		return ret;
	}

	/* Create sysfs entry */
	ret = device_create_file(&pdev->dev, &dev_attr_comp1_threshold);
	if (ret < 0)
		dev_err(&pdev->dev, "failed to add COMP1 sysfs file\n");

	ret = device_create_file(&pdev->dev, &dev_attr_comp2_threshold);
	if (ret < 0)
		dev_err(&pdev->dev, "failed to add COMP2 sysfs file\n");

	return ret;
}

__attribute__((used)) static int tps65911_comparator_remove(struct platform_device *pdev)
{
	struct tps65910 *tps65910;

	tps65910 = dev_get_drvdata(pdev->dev.parent);
	device_remove_file(&pdev->dev, &dev_attr_comp2_threshold);
	device_remove_file(&pdev->dev, &dev_attr_comp1_threshold);

	return 0;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  long u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int /*<<< orphan*/  parent; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  long s8 ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int ENODEV ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  REG_CTSTS ; 
 int /*<<< orphan*/  REG_TSFSC ; 
 int REG_TSTHRHI ; 
 int /*<<< orphan*/  REG_TSTIMER ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ *,char*) ; 
 struct device* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i5500_temp_groups ; 
 int pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,long*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t temp1_input_show(struct device *dev,
				struct device_attribute *devattr, char *buf)
{
	struct pci_dev *pdev = to_pci_dev(dev->parent);
	long temp;
	u16 tsthrhi;
	s8 tsfsc;

	pci_read_config_word(pdev, REG_TSTHRHI, &tsthrhi);
	pci_read_config_byte(pdev, REG_TSFSC, &tsfsc);
	temp = ((long)tsthrhi - tsfsc) * 500;

	return sprintf(buf, "%ld\n", temp);
}

__attribute__((used)) static ssize_t show_thresh(struct device *dev,
			   struct device_attribute *devattr, char *buf)
{
	struct pci_dev *pdev = to_pci_dev(dev->parent);
	int reg = to_sensor_dev_attr(devattr)->index;
	long temp;
	u16 tsthr;

	pci_read_config_word(pdev, reg, &tsthr);
	temp = tsthr * 500;

	return sprintf(buf, "%ld\n", temp);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev,
			  struct device_attribute *devattr, char *buf)
{
	struct pci_dev *pdev = to_pci_dev(dev->parent);
	int nr = to_sensor_dev_attr(devattr)->index;
	u8 ctsts;

	pci_read_config_byte(pdev, REG_CTSTS, &ctsts);
	return sprintf(buf, "%u\n", (unsigned int)ctsts & (1 << nr));
}

__attribute__((used)) static int i5500_temp_probe(struct pci_dev *pdev,
			    const struct pci_device_id *id)
{
	int err;
	struct device *hwmon_dev;
	u32 tstimer;
	s8 tsfsc;

	err = pci_enable_device(pdev);
	if (err) {
		dev_err(&pdev->dev, "Failed to enable device\n");
		return err;
	}

	pci_read_config_byte(pdev, REG_TSFSC, &tsfsc);
	pci_read_config_dword(pdev, REG_TSTIMER, &tstimer);
	if (tsfsc == 0x7F && tstimer == 0x07D30D40) {
		dev_notice(&pdev->dev, "Sensor seems to be disabled\n");
		return -ENODEV;
	}

	hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev,
							   "intel5500", NULL,
							   i5500_temp_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}


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
typedef  int u32 ;
struct work_struct {int dummy; } ;
struct kobject {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int CPU_THERMAL_THRESHOLD ; 
 int LOONGSON_CHIPTEMP (int) ; 
#define  PRID_REV_LOONGSON3A_R1 133 
#define  PRID_REV_LOONGSON3A_R2 132 
#define  PRID_REV_LOONGSON3A_R3_0 131 
#define  PRID_REV_LOONGSON3A_R3_1 130 
#define  PRID_REV_LOONGSON3B_R1 129 
#define  PRID_REV_LOONGSON3B_R2 128 
 int PRID_REV_MASK ; 
 int /*<<< orphan*/ * hwmon_cputemp ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int nr_packages ; 
 int /*<<< orphan*/  orderly_poweroff (int) ; 
 int read_c0_prid () ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 int sysfs_create_files (struct kobject*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sysfs_remove_files (struct kobject*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  thermal_work ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

int loongson3_cpu_temp(int cpu)
{
	u32 reg, prid_rev;

	reg = LOONGSON_CHIPTEMP(cpu);
	prid_rev = read_c0_prid() & PRID_REV_MASK;
	switch (prid_rev) {
	case PRID_REV_LOONGSON3A_R1:
		reg = (reg >> 8) & 0xff;
		break;
	case PRID_REV_LOONGSON3A_R2:
	case PRID_REV_LOONGSON3B_R1:
	case PRID_REV_LOONGSON3B_R2:
		reg = ((reg >> 8) & 0xff) - 100;
		break;
	case PRID_REV_LOONGSON3A_R3_0:
	case PRID_REV_LOONGSON3A_R3_1:
		reg = (reg & 0xffff)*731/0x4000 - 273;
		break;
	}
	return (int)reg * 1000;
}

__attribute__((used)) static ssize_t get_hwmon_name(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "cpu-hwmon\n");
}

__attribute__((used)) static ssize_t cpu_temp_label(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	int id = (to_sensor_dev_attr(attr))->index - 1;
	return sprintf(buf, "CPU %d Temperature\n", id);
}

__attribute__((used)) static ssize_t get_cpu_temp(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	int id = (to_sensor_dev_attr(attr))->index - 1;
	int value = loongson3_cpu_temp(id);
	return sprintf(buf, "%d\n", value);
}

__attribute__((used)) static int create_sysfs_cputemp_files(struct kobject *kobj)
{
	int i, ret = 0;

	for (i=0; i<nr_packages; i++)
		ret = sysfs_create_files(kobj, hwmon_cputemp[i]);

	return ret;
}

__attribute__((used)) static void remove_sysfs_cputemp_files(struct kobject *kobj)
{
	int i;

	for (i=0; i<nr_packages; i++)
		sysfs_remove_files(kobj, hwmon_cputemp[i]);
}

__attribute__((used)) static void do_thermal_timer(struct work_struct *work)
{
	int i, value, temp_max = 0;

	for (i=0; i<nr_packages; i++) {
		value = loongson3_cpu_temp(i);
		if (value > temp_max)
			temp_max = value;
	}

	if (temp_max <= CPU_THERMAL_THRESHOLD)
		schedule_delayed_work(&thermal_work, msecs_to_jiffies(5000));
	else
		orderly_poweroff(true);
}


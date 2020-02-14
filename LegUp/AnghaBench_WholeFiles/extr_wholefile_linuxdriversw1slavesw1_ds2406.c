#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; } ;
struct w1_slave {TYPE_1__ dev; TYPE_2__* master; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  scalar_t__ loff_t ;
struct TYPE_6__ {int /*<<< orphan*/  bus_mutex; } ;

/* Variables and functions */
 int EFAULT ; 
 int EINVAL ; 
 int EIO ; 
 int NB_SYSFS_BIN_FILES ; 
 int W1_F12_FUNC_READ_STATUS ; 
 int W1_F12_FUNC_WRITE_STATUS ; 
 int crc16_byte (int,int) ; 
 struct w1_slave* kobj_to_w1_slave (struct kobject*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * w1_f12_sysfs_bin_files ; 
 int /*<<< orphan*/  w1_read_block (TYPE_2__*,int*,int) ; 
 scalar_t__ w1_reset_select_slave (struct w1_slave*) ; 
 int /*<<< orphan*/  w1_write_8 (TYPE_2__*,int) ; 
 int /*<<< orphan*/  w1_write_block (TYPE_2__*,int*,int) ; 

__attribute__((used)) static ssize_t w1_f12_read_state(
	struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t off, size_t count)
{
	u8 w1_buf[6]={W1_F12_FUNC_READ_STATUS, 7, 0, 0, 0, 0};
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	u16 crc=0;
	int i;
	ssize_t rtnval=1;

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_reset_select_slave(sl)) {
		mutex_unlock(&sl->master->bus_mutex);
		return -EIO;
	}

	w1_write_block(sl->master, w1_buf, 3);
	w1_read_block(sl->master, w1_buf+3, 3);
	for (i=0; i<6; i++)
		crc=crc16_byte(crc, w1_buf[i]);
	if (crc==0xb001) /* good read? */
		*buf=((w1_buf[3]>>5)&3)|0x30;
	else
		rtnval=-EIO;

	mutex_unlock(&sl->master->bus_mutex);

	return rtnval;
}

__attribute__((used)) static ssize_t w1_f12_write_output(
	struct file *filp, struct kobject *kobj,
	struct bin_attribute *bin_attr,
	char *buf, loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	u8 w1_buf[6]={W1_F12_FUNC_WRITE_STATUS, 7, 0, 0, 0, 0};
	u16 crc=0;
	int i;
	ssize_t rtnval=1;

	if (count != 1 || off != 0)
		return -EFAULT;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_reset_select_slave(sl)) {
		mutex_unlock(&sl->master->bus_mutex);
		return -EIO;
	}

	w1_buf[3] = (((*buf)&3)<<5)|0x1F;
	w1_write_block(sl->master, w1_buf, 4);
	w1_read_block(sl->master, w1_buf+4, 2);
	for (i=0; i<6; i++)
		crc=crc16_byte(crc, w1_buf[i]);
	if (crc==0xb001) /* good read? */
		w1_write_8(sl->master, 0xFF);
	else
		rtnval=-EIO;

	mutex_unlock(&sl->master->bus_mutex);
	return rtnval;
}

__attribute__((used)) static int w1_f12_add_slave(struct w1_slave *sl)
{
	int err = 0;
	int i;

	for (i = 0; i < NB_SYSFS_BIN_FILES && !err; ++i)
		err = sysfs_create_bin_file(
			&sl->dev.kobj,
			&(w1_f12_sysfs_bin_files[i]));
	if (err)
		while (--i >= 0)
			sysfs_remove_bin_file(&sl->dev.kobj,
				&(w1_f12_sysfs_bin_files[i]));
	return err;
}

__attribute__((used)) static void w1_f12_remove_slave(struct w1_slave *sl)
{
	int i;
	for (i = NB_SYSFS_BIN_FILES - 1; i >= 0; --i)
		sysfs_remove_bin_file(&sl->dev.kobj,
			&(w1_f12_sysfs_bin_files[i]));
}


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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct w1_slave {TYPE_2__* master; int /*<<< orphan*/  reg_num; int /*<<< orphan*/  dev; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct bin_attribute {TYPE_1__ attr; } ;
typedef  int ssize_t ;
typedef  scalar_t__ loff_t ;
struct TYPE_8__ {int /*<<< orphan*/  bus_mutex; } ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 int EFAULT ; 
 int EINVAL ; 
 int EIO ; 
 scalar_t__ W1_F29_FUNC_CHANN_ACCESS_WRITE ; 
 scalar_t__ W1_F29_FUNC_READ_PIO_REGS ; 
 int /*<<< orphan*/  W1_F29_FUNC_RESET_ACTIVITY_LATCHES ; 
 scalar_t__ W1_F29_FUNC_WRITE_COND_SEARCH_REG ; 
 scalar_t__ W1_F29_REG_ACTIVITY_LATCH_STATE ; 
 scalar_t__ W1_F29_REG_COND_SEARCH_POL_SELECT ; 
 scalar_t__ W1_F29_REG_COND_SEARCH_SELECT_MASK ; 
 scalar_t__ W1_F29_REG_CONTROL_AND_STATUS ; 
 scalar_t__ W1_F29_REG_LOGIG_STATE ; 
 scalar_t__ W1_F29_REG_OUTPUT_LATCH_STATE ; 
 unsigned int W1_F29_RETRIES ; 
 scalar_t__ W1_F29_SUCCESS_CONFIRM_BYTE ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct w1_slave* kobj_to_w1_slave (struct kobject*) ; 
 int /*<<< orphan*/  le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 char w1_read_8 (TYPE_2__*) ; 
 int w1_reset_bus (TYPE_2__*) ; 
 scalar_t__ w1_reset_resume_command (TYPE_2__*) ; 
 scalar_t__ w1_reset_select_slave (struct w1_slave*) ; 
 int /*<<< orphan*/  w1_write_8 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w1_write_block (TYPE_2__*,scalar_t__*,int) ; 

__attribute__((used)) static int _read_reg(struct w1_slave *sl, u8 address, unsigned char* buf)
{
	u8 wrbuf[3];
	dev_dbg(&sl->dev,
			"Reading with slave: %p, reg addr: %0#4x, buff addr: %p",
			sl, (unsigned int)address, buf);

	if (!buf)
		return -EINVAL;

	mutex_lock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex locked");

	if (w1_reset_select_slave(sl)) {
		mutex_unlock(&sl->master->bus_mutex);
		return -EIO;
	}

	wrbuf[0] = W1_F29_FUNC_READ_PIO_REGS;
	wrbuf[1] = address;
	wrbuf[2] = 0;
	w1_write_block(sl->master, wrbuf, 3);
	*buf = w1_read_8(sl->master);

	mutex_unlock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex unlocked");
	return 1;
}

__attribute__((used)) static ssize_t state_read(struct file *filp, struct kobject *kobj,
			  struct bin_attribute *bin_attr, char *buf, loff_t off,
			  size_t count)
{
	dev_dbg(&kobj_to_w1_slave(kobj)->dev,
		"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
		bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
	if (count != 1 || off != 0)
		return -EFAULT;
	return _read_reg(kobj_to_w1_slave(kobj), W1_F29_REG_LOGIG_STATE, buf);
}

__attribute__((used)) static ssize_t output_read(struct file *filp, struct kobject *kobj,
			   struct bin_attribute *bin_attr, char *buf,
			   loff_t off, size_t count)
{
	dev_dbg(&kobj_to_w1_slave(kobj)->dev,
		"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
		bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
	if (count != 1 || off != 0)
		return -EFAULT;
	return _read_reg(kobj_to_w1_slave(kobj),
					 W1_F29_REG_OUTPUT_LATCH_STATE, buf);
}

__attribute__((used)) static ssize_t activity_read(struct file *filp, struct kobject *kobj,
			     struct bin_attribute *bin_attr, char *buf,
			     loff_t off, size_t count)
{
	dev_dbg(&kobj_to_w1_slave(kobj)->dev,
		"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
		bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
	if (count != 1 || off != 0)
		return -EFAULT;
	return _read_reg(kobj_to_w1_slave(kobj),
					 W1_F29_REG_ACTIVITY_LATCH_STATE, buf);
}

__attribute__((used)) static ssize_t cond_search_mask_read(struct file *filp, struct kobject *kobj,
				     struct bin_attribute *bin_attr, char *buf,
				     loff_t off, size_t count)
{
	dev_dbg(&kobj_to_w1_slave(kobj)->dev,
		"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
		bin_attr->attr.name, kobj, (unsigned int)off, count, buf);
	if (count != 1 || off != 0)
		return -EFAULT;
	return _read_reg(kobj_to_w1_slave(kobj),
		W1_F29_REG_COND_SEARCH_SELECT_MASK, buf);
}

__attribute__((used)) static ssize_t cond_search_polarity_read(struct file *filp,
					 struct kobject *kobj,
					 struct bin_attribute *bin_attr,
					 char *buf, loff_t off, size_t count)
{
	if (count != 1 || off != 0)
		return -EFAULT;
	return _read_reg(kobj_to_w1_slave(kobj),
		W1_F29_REG_COND_SEARCH_POL_SELECT, buf);
}

__attribute__((used)) static ssize_t status_control_read(struct file *filp, struct kobject *kobj,
				   struct bin_attribute *bin_attr, char *buf,
				   loff_t off, size_t count)
{
	if (count != 1 || off != 0)
		return -EFAULT;
	return _read_reg(kobj_to_w1_slave(kobj),
		W1_F29_REG_CONTROL_AND_STATUS, buf);
}

__attribute__((used)) static ssize_t output_write(struct file *filp, struct kobject *kobj,
			    struct bin_attribute *bin_attr, char *buf,
			    loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	u8 w1_buf[3];
	u8 readBack;
	unsigned int retries = W1_F29_RETRIES;

	if (count != 1 || off != 0)
		return -EFAULT;

	dev_dbg(&sl->dev, "locking mutex for write_output");
	mutex_lock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex locked");

	if (w1_reset_select_slave(sl))
		goto error;

	while (retries--) {
		w1_buf[0] = W1_F29_FUNC_CHANN_ACCESS_WRITE;
		w1_buf[1] = *buf;
		w1_buf[2] = ~(*buf);
		w1_write_block(sl->master, w1_buf, 3);

		readBack = w1_read_8(sl->master);

		if (readBack != W1_F29_SUCCESS_CONFIRM_BYTE) {
			if (w1_reset_resume_command(sl->master))
				goto error;
			/* try again, the slave is ready for a command */
			continue;
		}

#ifdef CONFIG_W1_SLAVE_DS2408_READBACK
		/* here the master could read another byte which
		   would be the PIO reg (the actual pin logic state)
		   since in this driver we don't know which pins are
		   in and outs, there's no value to read the state and
		   compare. with (*buf) so end this command abruptly: */
		if (w1_reset_resume_command(sl->master))
			goto error;

		/* go read back the output latches */
		/* (the direct effect of the write above) */
		w1_buf[0] = W1_F29_FUNC_READ_PIO_REGS;
		w1_buf[1] = W1_F29_REG_OUTPUT_LATCH_STATE;
		w1_buf[2] = 0;
		w1_write_block(sl->master, w1_buf, 3);
		/* read the result of the READ_PIO_REGS command */
		if (w1_read_8(sl->master) == *buf)
#endif
		{
			/* success! */
			mutex_unlock(&sl->master->bus_mutex);
			dev_dbg(&sl->dev,
				"mutex unlocked, retries:%d", retries);
			return 1;
		}
	}
error:
	mutex_unlock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex unlocked in error, retries:%d", retries);

	return -EIO;
}

__attribute__((used)) static ssize_t activity_write(struct file *filp, struct kobject *kobj,
			      struct bin_attribute *bin_attr, char *buf,
			      loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	unsigned int retries = W1_F29_RETRIES;

	if (count != 1 || off != 0)
		return -EFAULT;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_reset_select_slave(sl))
		goto error;

	while (retries--) {
		w1_write_8(sl->master, W1_F29_FUNC_RESET_ACTIVITY_LATCHES);
		if (w1_read_8(sl->master) == W1_F29_SUCCESS_CONFIRM_BYTE) {
			mutex_unlock(&sl->master->bus_mutex);
			return 1;
		}
		if (w1_reset_resume_command(sl->master))
			goto error;
	}

error:
	mutex_unlock(&sl->master->bus_mutex);
	return -EIO;
}

__attribute__((used)) static ssize_t status_control_write(struct file *filp, struct kobject *kobj,
				    struct bin_attribute *bin_attr, char *buf,
				    loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	u8 w1_buf[4];
	unsigned int retries = W1_F29_RETRIES;

	if (count != 1 || off != 0)
		return -EFAULT;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_reset_select_slave(sl))
		goto error;

	while (retries--) {
		w1_buf[0] = W1_F29_FUNC_WRITE_COND_SEARCH_REG;
		w1_buf[1] = W1_F29_REG_CONTROL_AND_STATUS;
		w1_buf[2] = 0;
		w1_buf[3] = *buf;

		w1_write_block(sl->master, w1_buf, 4);
		if (w1_reset_resume_command(sl->master))
			goto error;

		w1_buf[0] = W1_F29_FUNC_READ_PIO_REGS;
		w1_buf[1] = W1_F29_REG_CONTROL_AND_STATUS;
		w1_buf[2] = 0;

		w1_write_block(sl->master, w1_buf, 3);
		if (w1_read_8(sl->master) == *buf) {
			/* success! */
			mutex_unlock(&sl->master->bus_mutex);
			return 1;
		}
	}
error:
	mutex_unlock(&sl->master->bus_mutex);

	return -EIO;
}

__attribute__((used)) static int w1_f29_disable_test_mode(struct w1_slave *sl)
{
	int res;
	u8 magic[10] = {0x96, };
	u64 rn = le64_to_cpu(*((u64*)&sl->reg_num));

	memcpy(&magic[1], &rn, 8);
	magic[9] = 0x3C;

	mutex_lock(&sl->master->bus_mutex);

	res = w1_reset_bus(sl->master);
	if (res)
		goto out;
	w1_write_block(sl->master, magic, ARRAY_SIZE(magic));

	res = w1_reset_bus(sl->master);
out:
	mutex_unlock(&sl->master->bus_mutex);
	return res;
}


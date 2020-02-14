#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  char u8 ;
struct w1_slave {int /*<<< orphan*/  dev; TYPE_2__* master; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  name; } ;
struct bin_attribute {TYPE_1__ attr; } ;
typedef  int ssize_t ;
typedef  scalar_t__ loff_t ;
struct TYPE_7__ {int /*<<< orphan*/  bus_mutex; } ;

/* Variables and functions */
 int EFAULT ; 
 int EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  W1_F3A_FUNC_PIO_ACCESS_READ ; 
 char W1_F3A_FUNC_PIO_ACCESS_WRITE ; 
 unsigned int W1_F3A_RETRIES ; 
 scalar_t__ W1_F3A_SUCCESS_CONFIRM_BYTE ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct w1_slave* kobj_to_w1_slave (struct kobject*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ w1_read_8 (TYPE_2__*) ; 
 scalar_t__ w1_reset_resume_command (TYPE_2__*) ; 
 scalar_t__ w1_reset_select_slave (struct w1_slave*) ; 
 int /*<<< orphan*/  w1_write_8 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w1_write_block (TYPE_2__*,char*,int) ; 

__attribute__((used)) static ssize_t state_read(struct file *filp, struct kobject *kobj,
			  struct bin_attribute *bin_attr, char *buf, loff_t off,
			  size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	dev_dbg(&sl->dev,
		"Reading %s kobj: %p, off: %0#10x, count: %zu, buff addr: %p",
		bin_attr->attr.name, kobj, (unsigned int)off, count, buf);

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	mutex_lock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex locked");

	if (w1_reset_select_slave(sl)) {
		mutex_unlock(&sl->master->bus_mutex);
		return -EIO;
	}

	w1_write_8(sl->master, W1_F3A_FUNC_PIO_ACCESS_READ);
	*buf = w1_read_8(sl->master);

	mutex_unlock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex unlocked");

	/* check for correct complement */
	if ((*buf & 0x0F) != ((~*buf >> 4) & 0x0F))
		return -EIO;
	else
		return 1;
}

__attribute__((used)) static ssize_t output_write(struct file *filp, struct kobject *kobj,
			    struct bin_attribute *bin_attr, char *buf,
			    loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	u8 w1_buf[3];
	unsigned int retries = W1_F3A_RETRIES;

	if (count != 1 || off != 0)
		return -EFAULT;

	dev_dbg(&sl->dev, "locking mutex for write_output");
	mutex_lock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex locked");

	if (w1_reset_select_slave(sl))
		goto error;

	/* according to the DS2413 datasheet the most significant 6 bits
	   should be set to "1"s, so do it now */
	*buf = *buf | 0xFC;

	while (retries--) {
		w1_buf[0] = W1_F3A_FUNC_PIO_ACCESS_WRITE;
		w1_buf[1] = *buf;
		w1_buf[2] = ~(*buf);
		w1_write_block(sl->master, w1_buf, 3);

		if (w1_read_8(sl->master) == W1_F3A_SUCCESS_CONFIRM_BYTE) {
			mutex_unlock(&sl->master->bus_mutex);
			dev_dbg(&sl->dev, "mutex unlocked, retries:%d", retries);
			return 1;
		}
		if (w1_reset_resume_command(sl->master))
			goto error;
	}

error:
	mutex_unlock(&sl->master->bus_mutex);
	dev_dbg(&sl->dev, "mutex unlocked in error, retries:%d", retries);
	return -EIO;
}


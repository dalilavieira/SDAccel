#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
struct w1_slave {int /*<<< orphan*/  reg_num; struct w1_master* master; } ;
struct w1_master {int /*<<< orphan*/  bus_mutex; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  dev_addr ;
typedef  int /*<<< orphan*/  cmd ;

/* Variables and functions */
 int BIT (int) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  W1_ALARM_SEARCH ; 
 int W1_MATCH_ROM ; 
 int /*<<< orphan*/  W1_SEARCH ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct w1_slave* dev_to_w1_slave (struct device*) ; 
 int le64_to_cpu (int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sscanf (char const*,char*,unsigned int*,int*) ; 
 int w1_read_8 (struct w1_master*) ; 
 scalar_t__ w1_reset_bus (struct w1_master*) ; 
 int w1_triplet (struct w1_master*,int) ; 
 int /*<<< orphan*/  w1_write_8 (struct w1_master*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w1_write_block (struct w1_master*,int*,int) ; 

__attribute__((used)) static int w1_ds2405_select(struct w1_slave *sl, bool only_active)
{
	struct w1_master *dev = sl->master;

	u64 dev_addr = le64_to_cpu(*(u64 *)&sl->reg_num);
	unsigned int bit_ctr;

	if (w1_reset_bus(dev) != 0)
		return 0;

	/*
	 * We cannot use a normal Match ROM command
	 * since doing so would toggle PIO state
	 */
	w1_write_8(dev, only_active ? W1_ALARM_SEARCH : W1_SEARCH);

	for (bit_ctr = 0; bit_ctr < 64; bit_ctr++) {
		int bit2send = !!(dev_addr & BIT(bit_ctr));
		u8 ret;

		ret = w1_triplet(dev, bit2send);

		if ((ret & (BIT(0) | BIT(1))) ==
		    (BIT(0) | BIT(1))) /* no devices found */
			return 0;

		if (!!(ret & BIT(2)) != bit2send)
			/* wrong direction taken - no such device */
			return 0;
	}

	return 1;
}

__attribute__((used)) static int w1_ds2405_read_pio(struct w1_slave *sl)
{
	if (w1_ds2405_select(sl, true))
		return 0; /* "active" means PIO is low */

	if (w1_ds2405_select(sl, false))
		return 1;

	return -ENODEV;
}

__attribute__((used)) static ssize_t state_show(struct device *device,
			  struct device_attribute *attr, char *buf)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	struct w1_master *dev = sl->master;

	int ret;
	ssize_t f_retval;
	u8 state;

	ret = mutex_lock_interruptible(&dev->bus_mutex);
	if (ret)
		return ret;

	if (!w1_ds2405_select(sl, false)) {
		f_retval = -ENODEV;
		goto out_unlock;
	}

	state = w1_read_8(dev);
	if (state != 0 &&
	    state != 0xff) {
		dev_err(device, "non-consistent state %x\n", state);
		f_retval = -EIO;
		goto out_unlock;
	}

	*buf = state ? '1' : '0';
	f_retval = 1;

out_unlock:
	w1_reset_bus(dev);
	mutex_unlock(&dev->bus_mutex);

	return f_retval;
}

__attribute__((used)) static ssize_t output_show(struct device *device,
			   struct device_attribute *attr, char *buf)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	struct w1_master *dev = sl->master;

	int ret;
	ssize_t f_retval;

	ret = mutex_lock_interruptible(&dev->bus_mutex);
	if (ret)
		return ret;

	ret = w1_ds2405_read_pio(sl);
	if (ret < 0) {
		f_retval = ret;
		goto out_unlock;
	}

	*buf = ret ? '1' : '0';
	f_retval = 1;

out_unlock:
	w1_reset_bus(dev);
	mutex_unlock(&dev->bus_mutex);

	return f_retval;
}

__attribute__((used)) static ssize_t output_store(struct device *device,
			    struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	struct w1_master *dev = sl->master;

	int ret, current_pio;
	unsigned int val;
	ssize_t f_retval;

	if (count < 1)
		return -EINVAL;

	if (sscanf(buf, " %u%n", &val, &ret) < 1)
		return -EINVAL;

	if (val != 0 && val != 1)
		return -EINVAL;

	f_retval = ret;

	ret = mutex_lock_interruptible(&dev->bus_mutex);
	if (ret)
		return ret;

	current_pio = w1_ds2405_read_pio(sl);
	if (current_pio < 0) {
		f_retval = current_pio;
		goto out_unlock;
	}

	if (current_pio == val)
		goto out_unlock;

	if (w1_reset_bus(dev) != 0) {
		f_retval = -ENODEV;
		goto out_unlock;
	}

	/*
	 * can't use w1_reset_select_slave() here since it uses Skip ROM if
	 * there is only one device on bus
	 */
	do {
		u64 dev_addr = le64_to_cpu(*(u64 *)&sl->reg_num);
		u8 cmd[9];

		cmd[0] = W1_MATCH_ROM;
		memcpy(&cmd[1], &dev_addr, sizeof(dev_addr));

		w1_write_block(dev, cmd, sizeof(cmd));
	} while (0);

out_unlock:
	w1_reset_bus(dev);
	mutex_unlock(&dev->bus_mutex);

	return f_retval;
}


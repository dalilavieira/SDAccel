#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
typedef  scalar_t__ u8 ;
struct w1_slave {TYPE_1__* master; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct bin_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  scalar_t__ loff_t ;
typedef  int int16_t ;
struct TYPE_5__ {int /*<<< orphan*/  bus_mutex; } ;

/* Variables and functions */
 int DS2438_ADC_INPUT_VAD ; 
 int DS2438_ADC_INPUT_VDD ; 
 unsigned int DS2438_MAX_CONVERSION_TIME ; 
 int DS2438_PAGE_SIZE ; 
 scalar_t__ DS2438_STATUS_AD ; 
 scalar_t__ DS2438_STATUS_IAD ; 
 size_t DS2438_TEMP_LSB ; 
 size_t DS2438_TEMP_MSB ; 
 size_t DS2438_VOLTAGE_LSB ; 
 size_t DS2438_VOLTAGE_MSB ; 
 int EFAULT ; 
 int EINVAL ; 
 int EIO ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  W1_DS2438_CONVERT_TEMP ; 
 int /*<<< orphan*/  W1_DS2438_CONVERT_VOLTAGE ; 
 scalar_t__ W1_DS2438_COPY_SCRATCH ; 
 scalar_t__ W1_DS2438_READ_SCRATCH ; 
 scalar_t__ W1_DS2438_RECALL_MEMORY ; 
 unsigned int W1_DS2438_RETRIES ; 
 scalar_t__ W1_DS2438_WRITE_SCRATCH ; 
 struct w1_slave* kobj_to_w1_slave (struct kobject*) ; 
 int /*<<< orphan*/  memcpy (char*,scalar_t__**,int) ; 
 unsigned long msleep_interruptible (unsigned int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int snprintf (char*,int,char*,int) ; 
 scalar_t__ w1_calc_crc8 (scalar_t__*,int) ; 
 scalar_t__ w1_read_8 (TYPE_1__*) ; 
 size_t w1_read_block (TYPE_1__*,scalar_t__*,int) ; 
 scalar_t__ w1_reset_select_slave (struct w1_slave*) ; 
 int /*<<< orphan*/  w1_write_8 (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w1_write_block (TYPE_1__*,scalar_t__*,int) ; 

__attribute__((used)) static int w1_ds2438_get_page(struct w1_slave *sl, int pageno, u8 *buf)
{
	unsigned int retries = W1_DS2438_RETRIES;
	u8 w1_buf[2];
	u8 crc;
	size_t count;

	while (retries--) {
		crc = 0;

		if (w1_reset_select_slave(sl))
			continue;
		w1_buf[0] = W1_DS2438_RECALL_MEMORY;
		w1_buf[1] = 0x00;
		w1_write_block(sl->master, w1_buf, 2);

		if (w1_reset_select_slave(sl))
			continue;
		w1_buf[0] = W1_DS2438_READ_SCRATCH;
		w1_buf[1] = 0x00;
		w1_write_block(sl->master, w1_buf, 2);

		count = w1_read_block(sl->master, buf, DS2438_PAGE_SIZE + 1);
		if (count == DS2438_PAGE_SIZE + 1) {
			crc = w1_calc_crc8(buf, DS2438_PAGE_SIZE);

			/* check for correct CRC */
			if ((u8)buf[DS2438_PAGE_SIZE] == crc)
				return 0;
		}
	}
	return -1;
}

__attribute__((used)) static int w1_ds2438_get_temperature(struct w1_slave *sl, int16_t *temperature)
{
	unsigned int retries = W1_DS2438_RETRIES;
	u8 w1_buf[DS2438_PAGE_SIZE + 1 /*for CRC*/];
	unsigned int tm = DS2438_MAX_CONVERSION_TIME;
	unsigned long sleep_rem;
	int ret;

	mutex_lock(&sl->master->bus_mutex);

	while (retries--) {
		if (w1_reset_select_slave(sl))
			continue;
		w1_write_8(sl->master, W1_DS2438_CONVERT_TEMP);

		mutex_unlock(&sl->master->bus_mutex);
		sleep_rem = msleep_interruptible(tm);
		if (sleep_rem != 0) {
			ret = -1;
			goto post_unlock;
		}

		if (mutex_lock_interruptible(&sl->master->bus_mutex) != 0) {
			ret = -1;
			goto post_unlock;
		}

		break;
	}

	if (w1_ds2438_get_page(sl, 0, w1_buf) == 0) {
		*temperature = (((int16_t) w1_buf[DS2438_TEMP_MSB]) << 8) | ((uint16_t) w1_buf[DS2438_TEMP_LSB]);
		ret = 0;
	} else
		ret = -1;

	mutex_unlock(&sl->master->bus_mutex);

post_unlock:
	return ret;
}

__attribute__((used)) static int w1_ds2438_change_config_bit(struct w1_slave *sl, u8 mask, u8 value)
{
	unsigned int retries = W1_DS2438_RETRIES;
	u8 w1_buf[3];
	u8 status;
	int perform_write = 0;

	while (retries--) {
		if (w1_reset_select_slave(sl))
			continue;
		w1_buf[0] = W1_DS2438_RECALL_MEMORY;
		w1_buf[1] = 0x00;
		w1_write_block(sl->master, w1_buf, 2);

		if (w1_reset_select_slave(sl))
			continue;
		w1_buf[0] = W1_DS2438_READ_SCRATCH;
		w1_buf[1] = 0x00;
		w1_write_block(sl->master, w1_buf, 2);

		/* reading one byte of result */
		status = w1_read_8(sl->master);

		/* if bit0=1, set a value to a mask for easy compare */
		if (value)
			value = mask;

		if ((status & mask) == value)
			return 0;	/* already set as requested */
		else {
			/* changing bit */
			status ^= mask;
			perform_write = 1;
		}
		break;
	}

	if (perform_write) {
		retries = W1_DS2438_RETRIES;
		while (retries--) {
			if (w1_reset_select_slave(sl))
				continue;
			w1_buf[0] = W1_DS2438_WRITE_SCRATCH;
			w1_buf[1] = 0x00;
			w1_buf[2] = status;
			w1_write_block(sl->master, w1_buf, 3);

			if (w1_reset_select_slave(sl))
				continue;
			w1_buf[0] = W1_DS2438_COPY_SCRATCH;
			w1_buf[1] = 0x00;
			w1_write_block(sl->master, w1_buf, 2);

			return 0;
		}
	}
	return -1;
}

__attribute__((used)) static uint16_t w1_ds2438_get_voltage(struct w1_slave *sl,
				      int adc_input, uint16_t *voltage)
{
	unsigned int retries = W1_DS2438_RETRIES;
	u8 w1_buf[DS2438_PAGE_SIZE + 1 /*for CRC*/];
	unsigned int tm = DS2438_MAX_CONVERSION_TIME;
	unsigned long sleep_rem;
	int ret;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_ds2438_change_config_bit(sl, DS2438_STATUS_AD, adc_input)) {
		ret = -1;
		goto pre_unlock;
	}

	while (retries--) {
		if (w1_reset_select_slave(sl))
			continue;
		w1_write_8(sl->master, W1_DS2438_CONVERT_VOLTAGE);

		mutex_unlock(&sl->master->bus_mutex);
		sleep_rem = msleep_interruptible(tm);
		if (sleep_rem != 0) {
			ret = -1;
			goto post_unlock;
		}

		if (mutex_lock_interruptible(&sl->master->bus_mutex) != 0) {
			ret = -1;
			goto post_unlock;
		}

		break;
	}

	if (w1_ds2438_get_page(sl, 0, w1_buf) == 0) {
		*voltage = (((uint16_t) w1_buf[DS2438_VOLTAGE_MSB]) << 8) | ((uint16_t) w1_buf[DS2438_VOLTAGE_LSB]);
		ret = 0;
	} else
		ret = -1;

pre_unlock:
	mutex_unlock(&sl->master->bus_mutex);

post_unlock:
	return ret;
}

__attribute__((used)) static ssize_t iad_write(struct file *filp, struct kobject *kobj,
			 struct bin_attribute *bin_attr, char *buf,
			 loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	int ret;

	if (count != 1 || off != 0)
		return -EFAULT;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_ds2438_change_config_bit(sl, DS2438_STATUS_IAD, *buf & 0x01) == 0)
		ret = 1;
	else
		ret = -EIO;

	mutex_unlock(&sl->master->bus_mutex);

	return ret;
}

__attribute__((used)) static ssize_t page0_read(struct file *filp, struct kobject *kobj,
			  struct bin_attribute *bin_attr, char *buf,
			  loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	int ret;
	u8 w1_buf[DS2438_PAGE_SIZE + 1 /*for CRC*/];

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	mutex_lock(&sl->master->bus_mutex);

	if (w1_ds2438_get_page(sl, 0, w1_buf) == 0) {
		memcpy(buf, &w1_buf, DS2438_PAGE_SIZE);
		ret = DS2438_PAGE_SIZE;
	} else
		ret = -EIO;

	mutex_unlock(&sl->master->bus_mutex);

	return ret;
}

__attribute__((used)) static ssize_t temperature_read(struct file *filp, struct kobject *kobj,
				struct bin_attribute *bin_attr, char *buf,
				loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	int ret;
	ssize_t c = PAGE_SIZE;
	int16_t temp;

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	if (w1_ds2438_get_temperature(sl, &temp) == 0) {
		c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", temp);
		ret = PAGE_SIZE - c;
	} else
		ret = -EIO;

	return ret;
}

__attribute__((used)) static ssize_t vad_read(struct file *filp, struct kobject *kobj,
			struct bin_attribute *bin_attr, char *buf,
			loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	int ret;
	ssize_t c = PAGE_SIZE;
	uint16_t voltage;

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	if (w1_ds2438_get_voltage(sl, DS2438_ADC_INPUT_VAD, &voltage) == 0) {
		c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", voltage);
		ret = PAGE_SIZE - c;
	} else
		ret = -EIO;

	return ret;
}

__attribute__((used)) static ssize_t vdd_read(struct file *filp, struct kobject *kobj,
			struct bin_attribute *bin_attr, char *buf,
			loff_t off, size_t count)
{
	struct w1_slave *sl = kobj_to_w1_slave(kobj);
	int ret;
	ssize_t c = PAGE_SIZE;
	uint16_t voltage;

	if (off != 0)
		return 0;
	if (!buf)
		return -EINVAL;

	if (w1_ds2438_get_voltage(sl, DS2438_ADC_INPUT_VDD, &voltage) == 0) {
		c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", voltage);
		ret = PAGE_SIZE - c;
	} else
		ret = -EIO;

	return ret;
}


#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct w1_therm_family_data {int dummy; } ;
struct TYPE_8__ {scalar_t__ id; } ;
struct w1_slave {scalar_t__* family_data; struct w1_master* master; TYPE_3__ reg_num; TYPE_2__* family; } ;
struct w1_reg_num {scalar_t__ family; scalar_t__ id; } ;
struct w1_master {int pullup_duration; int /*<<< orphan*/  bus_mutex; } ;
struct therm_info {scalar_t__* rom; int verdict; scalar_t__ crc; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int s32 ;
typedef  int s16 ;
typedef  int /*<<< orphan*/  rom ;
typedef  int /*<<< orphan*/  ack ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_9__ {int (* convert ) (scalar_t__*) ;int (* eeprom ) (struct device*) ;int (* precision ) (struct device*,int) ;TYPE_1__* f; } ;
struct TYPE_7__ {scalar_t__ fid; } ;
struct TYPE_6__ {scalar_t__ fid; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 int EINTR ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  THERM_REFCNT (scalar_t__*) ; 
 scalar_t__ W1_42_CHAIN ; 
 scalar_t__ W1_42_CHAIN_DONE ; 
 scalar_t__ W1_42_CHAIN_DONE_INV ; 
 scalar_t__ W1_42_CHAIN_OFF ; 
 scalar_t__ W1_42_CHAIN_OFF_INV ; 
 scalar_t__ W1_42_CHAIN_ON ; 
 scalar_t__ W1_42_CHAIN_ON_INV ; 
 scalar_t__ W1_42_COND_READ ; 
 scalar_t__ W1_42_FINISHED_BYTE ; 
 scalar_t__ W1_42_SUCCESS_CONFIRM_BYTE ; 
 scalar_t__ W1_CONVERT_TEMP ; 
 scalar_t__ W1_COPY_SCRATCHPAD ; 
 scalar_t__ W1_READ_PSUPPLY ; 
 scalar_t__ W1_READ_SCRATCHPAD ; 
 scalar_t__ W1_SKIP_ROM ; 
 scalar_t__ W1_WRITE_SCRATCHPAD ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ ) ; 
 int atomic_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ ,int) ; 
 int atomic_sub_return (int,int /*<<< orphan*/ ) ; 
 struct w1_slave* dev_to_w1_slave (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int /*<<< orphan*/  kfree (scalar_t__*) ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int le16_to_cpup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,int*,int) ; 
 int /*<<< orphan*/  memset (scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 unsigned long msleep_interruptible (unsigned int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int snprintf (char*,int,char*,int,...) ; 
 int stub1 (scalar_t__*) ; 
 int stub2 (struct device*) ; 
 int stub3 (struct device*,int) ; 
 scalar_t__ w1_calc_crc8 (scalar_t__*,int) ; 
 int /*<<< orphan*/  w1_next_pullup (struct w1_master*,unsigned int) ; 
 scalar_t__ w1_read_8 (struct w1_master*) ; 
 int w1_read_block (struct w1_master*,scalar_t__*,int) ; 
 scalar_t__ w1_reset_bus (struct w1_master*) ; 
 scalar_t__ w1_reset_select_slave (struct w1_slave*) ; 
 int w1_strong_pullup ; 
 TYPE_4__* w1_therm_families ; 
 int /*<<< orphan*/  w1_write_8 (struct w1_master*,scalar_t__) ; 

__attribute__((used)) static int w1_therm_add_slave(struct w1_slave *sl)
{
	sl->family_data = kzalloc(sizeof(struct w1_therm_family_data),
		GFP_KERNEL);
	if (!sl->family_data)
		return -ENOMEM;
	atomic_set(THERM_REFCNT(sl->family_data), 1);
	return 0;
}

__attribute__((used)) static void w1_therm_remove_slave(struct w1_slave *sl)
{
	int refcnt = atomic_sub_return(1, THERM_REFCNT(sl->family_data));

	while (refcnt) {
		msleep(1000);
		refcnt = atomic_read(THERM_REFCNT(sl->family_data));
	}
	kfree(sl->family_data);
	sl->family_data = NULL;
}

__attribute__((used)) static inline int w1_therm_eeprom(struct device *device)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	struct w1_master *dev = sl->master;
	u8 rom[9], external_power;
	int ret, max_trying = 10;
	u8 *family_data = sl->family_data;

	if (!sl->family_data) {
		ret = -ENODEV;
		goto error;
	}

	/* prevent the slave from going away in sleep */
	atomic_inc(THERM_REFCNT(family_data));

	ret = mutex_lock_interruptible(&dev->bus_mutex);
	if (ret != 0)
		goto dec_refcnt;

	memset(rom, 0, sizeof(rom));

	while (max_trying--) {
		if (!w1_reset_select_slave(sl)) {
			unsigned int tm = 10;
			unsigned long sleep_rem;

			/* check if in parasite mode */
			w1_write_8(dev, W1_READ_PSUPPLY);
			external_power = w1_read_8(dev);

			if (w1_reset_select_slave(sl))
				continue;

			/* 10ms strong pullup/delay after the copy command */
			if (w1_strong_pullup == 2 ||
			    (!external_power && w1_strong_pullup))
				w1_next_pullup(dev, tm);

			w1_write_8(dev, W1_COPY_SCRATCHPAD);

			if (external_power) {
				mutex_unlock(&dev->bus_mutex);

				sleep_rem = msleep_interruptible(tm);
				if (sleep_rem != 0) {
					ret = -EINTR;
					goto dec_refcnt;
				}

				ret = mutex_lock_interruptible(&dev->bus_mutex);
				if (ret != 0)
					goto dec_refcnt;
			} else if (!w1_strong_pullup) {
				sleep_rem = msleep_interruptible(tm);
				if (sleep_rem != 0) {
					ret = -EINTR;
					goto mt_unlock;
				}
			}

			break;
		}
	}

mt_unlock:
	mutex_unlock(&dev->bus_mutex);
dec_refcnt:
	atomic_dec(THERM_REFCNT(family_data));
error:
	return ret;
}

__attribute__((used)) static inline int w1_DS18S20_precision(struct device *device, int val)
{
	return 0;
}

__attribute__((used)) static inline int w1_DS18B20_precision(struct device *device, int val)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	struct w1_master *dev = sl->master;
	u8 rom[9], crc;
	int ret, max_trying = 10;
	u8 *family_data = sl->family_data;
	uint8_t precision_bits;
	uint8_t mask = 0x60;

	if (val > 12 || val < 9) {
		pr_warn("Unsupported precision\n");
		ret = -EINVAL;
		goto error;
	}

	if (!sl->family_data) {
		ret = -ENODEV;
		goto error;
	}

	/* prevent the slave from going away in sleep */
	atomic_inc(THERM_REFCNT(family_data));

	ret = mutex_lock_interruptible(&dev->bus_mutex);
	if (ret != 0)
		goto dec_refcnt;

	memset(rom, 0, sizeof(rom));

	/* translate precision to bitmask (see datasheet page 9) */
	switch (val) {
	case 9:
		precision_bits = 0x00;
		break;
	case 10:
		precision_bits = 0x20;
		break;
	case 11:
		precision_bits = 0x40;
		break;
	case 12:
	default:
		precision_bits = 0x60;
		break;
	}

	while (max_trying--) {
		crc = 0;

		if (!w1_reset_select_slave(sl)) {
			int count = 0;

			/* read values to only alter precision bits */
			w1_write_8(dev, W1_READ_SCRATCHPAD);
			count = w1_read_block(dev, rom, 9);
			if (count != 9)
				dev_warn(device, "w1_read_block() returned %u instead of 9.\n",	count);

			crc = w1_calc_crc8(rom, 8);
			if (rom[8] == crc) {
				rom[4] = (rom[4] & ~mask) | (precision_bits & mask);

				if (!w1_reset_select_slave(sl)) {
					w1_write_8(dev, W1_WRITE_SCRATCHPAD);
					w1_write_8(dev, rom[2]);
					w1_write_8(dev, rom[3]);
					w1_write_8(dev, rom[4]);

					break;
				}
			}
		}
	}

	mutex_unlock(&dev->bus_mutex);
dec_refcnt:
	atomic_dec(THERM_REFCNT(family_data));
error:
	return ret;
}

__attribute__((used)) static inline int w1_DS18B20_convert_temp(u8 rom[9])
{
	s16 t = le16_to_cpup((__le16 *)rom);

	return t*1000/16;
}

__attribute__((used)) static inline int w1_DS18S20_convert_temp(u8 rom[9])
{
	int t, h;

	if (!rom[7])
		return 0;

	if (rom[1] == 0)
		t = ((s32)rom[0] >> 1)*1000;
	else
		t = 1000*(-1*(s32)(0x100-rom[0]) >> 1);

	t -= 250;
	h = 1000*((s32)rom[7] - (s32)rom[6]);
	h /= (s32)rom[7];
	t += h;

	return t;
}

__attribute__((used)) static inline int w1_convert_temp(u8 rom[9], u8 fid)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(w1_therm_families); ++i)
		if (w1_therm_families[i].f->fid == fid)
			return w1_therm_families[i].convert(rom);

	return 0;
}

__attribute__((used)) static ssize_t w1_slave_store(struct device *device,
			      struct device_attribute *attr, const char *buf,
			      size_t size)
{
	int val, ret;
	struct w1_slave *sl = dev_to_w1_slave(device);
	int i;

	ret = kstrtoint(buf, 0, &val);
	if (ret)
		return ret;

	for (i = 0; i < ARRAY_SIZE(w1_therm_families); ++i) {
		if (w1_therm_families[i].f->fid == sl->family->fid) {
			/* zero value indicates to write current configuration to eeprom */
			if (val == 0)
				ret = w1_therm_families[i].eeprom(device);
			else
				ret = w1_therm_families[i].precision(device, val);
			break;
		}
	}
	return ret ? : size;
}

__attribute__((used)) static ssize_t read_therm(struct device *device,
			  struct w1_slave *sl, struct therm_info *info)
{
	struct w1_master *dev = sl->master;
	u8 external_power;
	int ret, max_trying = 10;
	u8 *family_data = sl->family_data;

	if (!family_data) {
		ret = -ENODEV;
		goto error;
	}

	/* prevent the slave from going away in sleep */
	atomic_inc(THERM_REFCNT(family_data));

	ret = mutex_lock_interruptible(&dev->bus_mutex);
	if (ret != 0)
		goto dec_refcnt;

	memset(info->rom, 0, sizeof(info->rom));

	while (max_trying--) {

		info->verdict = 0;
		info->crc = 0;

		if (!w1_reset_select_slave(sl)) {
			int count = 0;
			unsigned int tm = 750;
			unsigned long sleep_rem;

			w1_write_8(dev, W1_READ_PSUPPLY);
			external_power = w1_read_8(dev);

			if (w1_reset_select_slave(sl))
				continue;

			/* 750ms strong pullup (or delay) after the convert */
			if (w1_strong_pullup == 2 ||
					(!external_power && w1_strong_pullup))
				w1_next_pullup(dev, tm);

			w1_write_8(dev, W1_CONVERT_TEMP);

			if (external_power) {
				mutex_unlock(&dev->bus_mutex);

				sleep_rem = msleep_interruptible(tm);
				if (sleep_rem != 0) {
					ret = -EINTR;
					goto dec_refcnt;
				}

				ret = mutex_lock_interruptible(&dev->bus_mutex);
				if (ret != 0)
					goto dec_refcnt;
			} else if (!w1_strong_pullup) {
				sleep_rem = msleep_interruptible(tm);
				if (sleep_rem != 0) {
					ret = -EINTR;
					goto mt_unlock;
				}
			}

			if (!w1_reset_select_slave(sl)) {

				w1_write_8(dev, W1_READ_SCRATCHPAD);
				count = w1_read_block(dev, info->rom, 9);
				if (count != 9) {
					dev_warn(device, "w1_read_block() "
						"returned %u instead of 9.\n",
						count);
				}

				info->crc = w1_calc_crc8(info->rom, 8);

				if (info->rom[8] == info->crc)
					info->verdict = 1;
			}
		}

		if (info->verdict)
			break;
	}

mt_unlock:
	mutex_unlock(&dev->bus_mutex);
dec_refcnt:
	atomic_dec(THERM_REFCNT(family_data));
error:
	return ret;
}

__attribute__((used)) static ssize_t w1_slave_show(struct device *device,
			     struct device_attribute *attr, char *buf)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	struct therm_info info;
	u8 *family_data = sl->family_data;
	int ret, i;
	ssize_t c = PAGE_SIZE;
	u8 fid = sl->family->fid;

	ret = read_therm(device, sl, &info);
	if (ret)
		return ret;

	for (i = 0; i < 9; ++i)
		c -= snprintf(buf + PAGE_SIZE - c, c, "%02x ", info.rom[i]);
	c -= snprintf(buf + PAGE_SIZE - c, c, ": crc=%02x %s\n",
		      info.crc, (info.verdict) ? "YES" : "NO");
	if (info.verdict)
		memcpy(family_data, info.rom, sizeof(info.rom));
	else
		dev_warn(device, "Read failed CRC check\n");

	for (i = 0; i < 9; ++i)
		c -= snprintf(buf + PAGE_SIZE - c, c, "%02x ",
			      ((u8 *)family_data)[i]);

	c -= snprintf(buf + PAGE_SIZE - c, c, "t=%d\n",
			w1_convert_temp(info.rom, fid));
	ret = PAGE_SIZE - c;
	return ret;
}

__attribute__((used)) static ssize_t w1_seq_show(struct device *device,
	struct device_attribute *attr, char *buf)
{
	struct w1_slave *sl = dev_to_w1_slave(device);
	ssize_t c = PAGE_SIZE;
	int rv;
	int i;
	u8 ack;
	u64 rn;
	struct w1_reg_num *reg_num;
	int seq = 0;

	mutex_lock(&sl->master->bus_mutex);
	/* Place all devices in CHAIN state */
	if (w1_reset_bus(sl->master))
		goto error;
	w1_write_8(sl->master, W1_SKIP_ROM);
	w1_write_8(sl->master, W1_42_CHAIN);
	w1_write_8(sl->master, W1_42_CHAIN_ON);
	w1_write_8(sl->master, W1_42_CHAIN_ON_INV);
	msleep(sl->master->pullup_duration);

	/* check for acknowledgment */
	ack = w1_read_8(sl->master);
	if (ack != W1_42_SUCCESS_CONFIRM_BYTE)
		goto error;

	/* In case the bus fails to send 0xFF, limit*/
	for (i = 0; i <= 64; i++) {
		if (w1_reset_bus(sl->master))
			goto error;

		w1_write_8(sl->master, W1_42_COND_READ);
		rv = w1_read_block(sl->master, (u8 *)&rn, 8);
		reg_num = (struct w1_reg_num *) &rn;
		if (reg_num->family == W1_42_FINISHED_BYTE)
			break;
		if (sl->reg_num.id == reg_num->id)
			seq = i;

		w1_write_8(sl->master, W1_42_CHAIN);
		w1_write_8(sl->master, W1_42_CHAIN_DONE);
		w1_write_8(sl->master, W1_42_CHAIN_DONE_INV);
		w1_read_block(sl->master, &ack, sizeof(ack));

		/* check for acknowledgment */
		ack = w1_read_8(sl->master);
		if (ack != W1_42_SUCCESS_CONFIRM_BYTE)
			goto error;

	}

	/* Exit from CHAIN state */
	if (w1_reset_bus(sl->master))
		goto error;
	w1_write_8(sl->master, W1_SKIP_ROM);
	w1_write_8(sl->master, W1_42_CHAIN);
	w1_write_8(sl->master, W1_42_CHAIN_OFF);
	w1_write_8(sl->master, W1_42_CHAIN_OFF_INV);

	/* check for acknowledgment */
	ack = w1_read_8(sl->master);
	if (ack != W1_42_SUCCESS_CONFIRM_BYTE)
		goto error;
	mutex_unlock(&sl->master->bus_mutex);

	c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", seq);
	return PAGE_SIZE - c;
error:
	mutex_unlock(&sl->master->bus_mutex);
	return -EIO;
}


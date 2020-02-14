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
struct rtc_time {unsigned int tm_min; unsigned int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; int tm_yday; int tm_isdst; int /*<<< orphan*/  tm_sec; } ;
struct notifier_block {int dummy; } ;
struct list_head {struct list_head* prev; } ;
struct TYPE_2__ {int early_init; int /*<<< orphan*/ * qos; int /*<<< orphan*/  lock; } ;
struct device {TYPE_1__ power; } ;

/* Variables and functions */
 unsigned int DEVHASH ; 
 unsigned int DEVSEED ; 
 unsigned int FILEHASH ; 
#define  PM_POST_HIBERNATION 129 
#define  PM_POST_SUSPEND 128 
 unsigned int USERHASH ; 
 char* __tracedata_end ; 
 char* __tracedata_start ; 
 char* dev_driver_string (struct device*) ; 
 unsigned int dev_hash_value ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 char* dev_name (struct device*) ; 
 int device_is_registered (struct device*) ; 
 int /*<<< orphan*/  device_pm_lock () ; 
 int /*<<< orphan*/  device_pm_unlock () ; 
 struct list_head dpm_list ; 
 unsigned int hash_value_early_read ; 
 int /*<<< orphan*/  mc146818_get_time (struct rtc_time*) ; 
 int /*<<< orphan*/  mc146818_set_time (struct rtc_time*) ; 
 int /*<<< orphan*/  pm_trace_nb ; 
 int pm_trace_rtc_abused ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  register_pm_notifier (int /*<<< orphan*/ *) ; 
 int snprintf (char*,size_t,char*,char*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 struct device* to_device (struct list_head*) ; 

__attribute__((used)) static inline void device_pm_init_common(struct device *dev)
{
	if (!dev->power.early_init) {
		spin_lock_init(&dev->power.lock);
		dev->power.qos = NULL;
		dev->power.early_init = true;
	}
}

__attribute__((used)) static inline void pm_runtime_early_init(struct device *dev)
{
	device_pm_init_common(dev);
}

__attribute__((used)) static inline void pm_runtime_init(struct device *dev) {}

__attribute__((used)) static inline void pm_runtime_reinit(struct device *dev) {}

__attribute__((used)) static inline void pm_runtime_remove(struct device *dev) {}

__attribute__((used)) static inline int dpm_sysfs_add(struct device *dev) { return 0; }

__attribute__((used)) static inline void dpm_sysfs_remove(struct device *dev) {}

__attribute__((used)) static inline void device_pm_sleep_init(struct device *dev) {}

__attribute__((used)) static inline void device_pm_add(struct device *dev) {}

__attribute__((used)) static inline void device_pm_remove(struct device *dev)
{
	pm_runtime_remove(dev);
}

__attribute__((used)) static inline void device_pm_move_before(struct device *deva,
					 struct device *devb) {}

__attribute__((used)) static inline void device_pm_move_after(struct device *deva,
					struct device *devb) {}

__attribute__((used)) static inline void device_pm_move_last(struct device *dev) {}

__attribute__((used)) static inline void device_pm_check_callbacks(struct device *dev) {}

__attribute__((used)) static inline bool device_pm_initialized(struct device *dev)
{
	return device_is_registered(dev);
}

__attribute__((used)) static inline void device_pm_init(struct device *dev)
{
	device_pm_init_common(dev);
	device_pm_sleep_init(dev);
	pm_runtime_init(dev);
}

__attribute__((used)) static int set_magic_time(unsigned int user, unsigned int file, unsigned int device)
{
	unsigned int n = user + USERHASH*(file + FILEHASH*device);

	// June 7th, 2006
	static struct rtc_time time = {
		.tm_sec = 0,
		.tm_min = 0,
		.tm_hour = 0,
		.tm_mday = 7,
		.tm_mon = 5,	// June - counting from zero
		.tm_year = 106,
		.tm_wday = 3,
		.tm_yday = 160,
		.tm_isdst = 1
	};

	time.tm_year = (n % 100);
	n /= 100;
	time.tm_mon = (n % 12);
	n /= 12;
	time.tm_mday = (n % 28) + 1;
	n /= 28;
	time.tm_hour = (n % 24);
	n /= 24;
	time.tm_min = (n % 20) * 3;
	n /= 20;
	mc146818_set_time(&time);
	pm_trace_rtc_abused = true;
	return n ? -1 : 0;
}

__attribute__((used)) static unsigned int read_magic_time(void)
{
	struct rtc_time time;
	unsigned int val;

	mc146818_get_time(&time);
	pr_info("RTC time: %2d:%02d:%02d, date: %02d/%02d/%02d\n",
		time.tm_hour, time.tm_min, time.tm_sec,
		time.tm_mon + 1, time.tm_mday, time.tm_year % 100);
	val = time.tm_year;				/* 100 years */
	if (val > 100)
		val -= 100;
	val += time.tm_mon * 100;			/* 12 months */
	val += (time.tm_mday-1) * 100 * 12;		/* 28 month-days */
	val += time.tm_hour * 100 * 12 * 28;		/* 24 hours */
	val += (time.tm_min / 3) * 100 * 12 * 28 * 24;	/* 20 3-minute intervals */
	return val;
}

__attribute__((used)) static unsigned int hash_string(unsigned int seed, const char *data, unsigned int mod)
{
	unsigned char c;
	while ((c = *data++) != 0) {
		seed = (seed << 16) + (seed << 6) - seed + c;
	}
	return seed % mod;
}

void set_trace_device(struct device *dev)
{
	dev_hash_value = hash_string(DEVSEED, dev_name(dev), DEVHASH);
}

void generate_pm_trace(const void *tracedata, unsigned int user)
{
	unsigned short lineno = *(unsigned short *)tracedata;
	const char *file = *(const char **)(tracedata + 2);
	unsigned int user_hash_value, file_hash_value;

	user_hash_value = user % USERHASH;
	file_hash_value = hash_string(lineno, file, FILEHASH);
	set_magic_time(user_hash_value, file_hash_value, dev_hash_value);
}

__attribute__((used)) static int show_file_hash(unsigned int value)
{
	int match;
	char *tracedata;

	match = 0;
	for (tracedata = __tracedata_start ; tracedata < __tracedata_end ;
			tracedata += 2 + sizeof(unsigned long)) {
		unsigned short lineno = *(unsigned short *)tracedata;
		const char *file = *(const char **)(tracedata + 2);
		unsigned int hash = hash_string(lineno, file, FILEHASH);
		if (hash != value)
			continue;
		pr_info("  hash matches %s:%u\n", file, lineno);
		match++;
	}
	return match;
}

__attribute__((used)) static int show_dev_hash(unsigned int value)
{
	int match = 0;
	struct list_head *entry;

	device_pm_lock();
	entry = dpm_list.prev;
	while (entry != &dpm_list) {
		struct device * dev = to_device(entry);
		unsigned int hash = hash_string(DEVSEED, dev_name(dev), DEVHASH);
		if (hash == value) {
			dev_info(dev, "hash matches\n");
			match++;
		}
		entry = entry->prev;
	}
	device_pm_unlock();
	return match;
}

int show_trace_dev_match(char *buf, size_t size)
{
	unsigned int value = hash_value_early_read / (USERHASH * FILEHASH);
	int ret = 0;
	struct list_head *entry;

	/*
	 * It's possible that multiple devices will match the hash and we can't
	 * tell which is the culprit, so it's best to output them all.
	 */
	device_pm_lock();
	entry = dpm_list.prev;
	while (size && entry != &dpm_list) {
		struct device *dev = to_device(entry);
		unsigned int hash = hash_string(DEVSEED, dev_name(dev),
						DEVHASH);
		if (hash == value) {
			int len = snprintf(buf, size, "%s\n",
					    dev_driver_string(dev));
			if (len > size)
				len = size;
			buf += len;
			ret += len;
			size -= len;
		}
		entry = entry->prev;
	}
	device_pm_unlock();
	return ret;
}

__attribute__((used)) static int
pm_trace_notify(struct notifier_block *nb, unsigned long mode, void *_unused)
{
	switch (mode) {
	case PM_POST_HIBERNATION:
	case PM_POST_SUSPEND:
		if (pm_trace_rtc_abused) {
			pm_trace_rtc_abused = false;
			pr_warn("Possible incorrect RTC due to pm_trace, please use 'ntpdate' or 'rdate' to reset it.\n");
		}
		break;
	default:
		break;
	}
	return 0;
}

__attribute__((used)) static int early_resume_init(void)
{
	hash_value_early_read = read_magic_time();
	register_pm_notifier(&pm_trace_nb);
	return 0;
}

__attribute__((used)) static int late_resume_init(void)
{
	unsigned int val = hash_value_early_read;
	unsigned int user, file, dev;

	user = val % USERHASH;
	val = val / USERHASH;
	file = val % FILEHASH;
	val = val / FILEHASH;
	dev = val /* % DEVHASH */;

	pr_info("  Magic number: %d:%d:%d\n", user, file, dev);
	show_file_hash(file);
	show_dev_hash(dev);
	return 0;
}


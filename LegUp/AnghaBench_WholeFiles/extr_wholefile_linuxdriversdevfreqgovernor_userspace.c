#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct userspace_data {int valid; unsigned long user_frequency; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_7__ {scalar_t__ sd; } ;
struct TYPE_6__ {TYPE_3__ kobj; int /*<<< orphan*/  parent; } ;
struct devfreq {unsigned long max_freq; unsigned long min_freq; unsigned long previous_freq; struct userspace_data* data; TYPE_2__ dev; int /*<<< orphan*/  lock; int /*<<< orphan*/  last_status; TYPE_1__* profile; } ;
typedef  int ssize_t ;
struct TYPE_5__ {int (* get_dev_status ) (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
#define  DEVFREQ_GOV_START 129 
#define  DEVFREQ_GOV_STOP 128 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_attr_group ; 
 int /*<<< orphan*/  kfree (struct userspace_data*) ; 
 struct userspace_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  sscanf (char const*,char*,unsigned long*) ; 
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int sysfs_create_group (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (TYPE_3__*,int /*<<< orphan*/ *) ; 
 struct devfreq* to_devfreq (struct device*) ; 
 int update_devfreq (struct devfreq*) ; 

__attribute__((used)) static inline int devfreq_update_stats(struct devfreq *df)
{
	return df->profile->get_dev_status(df->dev.parent, &df->last_status);
}

__attribute__((used)) static int devfreq_userspace_func(struct devfreq *df, unsigned long *freq)
{
	struct userspace_data *data = df->data;

	if (data->valid) {
		unsigned long adjusted_freq = data->user_frequency;

		if (df->max_freq && adjusted_freq > df->max_freq)
			adjusted_freq = df->max_freq;

		if (df->min_freq && adjusted_freq < df->min_freq)
			adjusted_freq = df->min_freq;

		*freq = adjusted_freq;
	} else {
		*freq = df->previous_freq; /* No user freq specified yet */
	}
	return 0;
}

__attribute__((used)) static ssize_t store_freq(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct devfreq *devfreq = to_devfreq(dev);
	struct userspace_data *data;
	unsigned long wanted;
	int err = 0;

	mutex_lock(&devfreq->lock);
	data = devfreq->data;

	sscanf(buf, "%lu", &wanted);
	data->user_frequency = wanted;
	data->valid = true;
	err = update_devfreq(devfreq);
	if (err == 0)
		err = count;
	mutex_unlock(&devfreq->lock);
	return err;
}

__attribute__((used)) static ssize_t show_freq(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct devfreq *devfreq = to_devfreq(dev);
	struct userspace_data *data;
	int err = 0;

	mutex_lock(&devfreq->lock);
	data = devfreq->data;

	if (data->valid)
		err = sprintf(buf, "%lu\n", data->user_frequency);
	else
		err = sprintf(buf, "undefined\n");
	mutex_unlock(&devfreq->lock);
	return err;
}

__attribute__((used)) static int userspace_init(struct devfreq *devfreq)
{
	int err = 0;
	struct userspace_data *data = kzalloc(sizeof(struct userspace_data),
					      GFP_KERNEL);

	if (!data) {
		err = -ENOMEM;
		goto out;
	}
	data->valid = false;
	devfreq->data = data;

	err = sysfs_create_group(&devfreq->dev.kobj, &dev_attr_group);
out:
	return err;
}

__attribute__((used)) static void userspace_exit(struct devfreq *devfreq)
{
	/*
	 * Remove the sysfs entry, unless this is being called after
	 * device_del(), which should have done this already via kobject_del().
	 */
	if (devfreq->dev.kobj.sd)
		sysfs_remove_group(&devfreq->dev.kobj, &dev_attr_group);

	kfree(devfreq->data);
	devfreq->data = NULL;
}

__attribute__((used)) static int devfreq_userspace_handler(struct devfreq *devfreq,
			unsigned int event, void *data)
{
	int ret = 0;

	switch (event) {
	case DEVFREQ_GOV_START:
		ret = userspace_init(devfreq);
		break;
	case DEVFREQ_GOV_STOP:
		userspace_exit(devfreq);
		break;
	default:
		break;
	}

	return ret;
}


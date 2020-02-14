#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct devfreq_simple_ondemand_data {int upthreshold; int downdifferential; } ;
struct devfreq_dev_status {int total_time; int busy_time; unsigned long current_frequency; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct devfreq {unsigned long max_freq; unsigned long min_freq; struct devfreq_dev_status last_status; struct devfreq_simple_ondemand_data* data; TYPE_2__ dev; TYPE_1__* profile; } ;
struct TYPE_3__ {int (* get_dev_status ) (int /*<<< orphan*/ ,struct devfreq_dev_status*) ;} ;

/* Variables and functions */
#define  DEVFREQ_GOV_INTERVAL 132 
#define  DEVFREQ_GOV_RESUME 131 
#define  DEVFREQ_GOV_START 130 
#define  DEVFREQ_GOV_STOP 129 
#define  DEVFREQ_GOV_SUSPEND 128 
 unsigned int DFSO_DOWNDIFFERENCTIAL ; 
 unsigned int DFSO_UPTHRESHOLD ; 
 int EINVAL ; 
 unsigned long UINT_MAX ; 
 int /*<<< orphan*/  devfreq_interval_update (struct devfreq*,unsigned int*) ; 
 int /*<<< orphan*/  devfreq_monitor_resume (struct devfreq*) ; 
 int /*<<< orphan*/  devfreq_monitor_start (struct devfreq*) ; 
 int /*<<< orphan*/  devfreq_monitor_stop (struct devfreq*) ; 
 int /*<<< orphan*/  devfreq_monitor_suspend (struct devfreq*) ; 
 unsigned long long div_u64 (unsigned long long,unsigned int) ; 
 int stub1 (int /*<<< orphan*/ ,struct devfreq_dev_status*) ; 

__attribute__((used)) static inline int devfreq_update_stats(struct devfreq *df)
{
	return df->profile->get_dev_status(df->dev.parent, &df->last_status);
}

__attribute__((used)) static int devfreq_simple_ondemand_func(struct devfreq *df,
					unsigned long *freq)
{
	int err;
	struct devfreq_dev_status *stat;
	unsigned long long a, b;
	unsigned int dfso_upthreshold = DFSO_UPTHRESHOLD;
	unsigned int dfso_downdifferential = DFSO_DOWNDIFFERENCTIAL;
	struct devfreq_simple_ondemand_data *data = df->data;
	unsigned long max = (df->max_freq) ? df->max_freq : UINT_MAX;

	err = devfreq_update_stats(df);
	if (err)
		return err;

	stat = &df->last_status;

	if (data) {
		if (data->upthreshold)
			dfso_upthreshold = data->upthreshold;
		if (data->downdifferential)
			dfso_downdifferential = data->downdifferential;
	}
	if (dfso_upthreshold > 100 ||
	    dfso_upthreshold < dfso_downdifferential)
		return -EINVAL;

	/* Assume MAX if it is going to be divided by zero */
	if (stat->total_time == 0) {
		*freq = max;
		return 0;
	}

	/* Prevent overflow */
	if (stat->busy_time >= (1 << 24) || stat->total_time >= (1 << 24)) {
		stat->busy_time >>= 7;
		stat->total_time >>= 7;
	}

	/* Set MAX if it's busy enough */
	if (stat->busy_time * 100 >
	    stat->total_time * dfso_upthreshold) {
		*freq = max;
		return 0;
	}

	/* Set MAX if we do not know the initial frequency */
	if (stat->current_frequency == 0) {
		*freq = max;
		return 0;
	}

	/* Keep the current frequency */
	if (stat->busy_time * 100 >
	    stat->total_time * (dfso_upthreshold - dfso_downdifferential)) {
		*freq = stat->current_frequency;
		return 0;
	}

	/* Set the desired frequency based on the load */
	a = stat->busy_time;
	a *= stat->current_frequency;
	b = div_u64(a, stat->total_time);
	b *= 100;
	b = div_u64(b, (dfso_upthreshold - dfso_downdifferential / 2));
	*freq = (unsigned long) b;

	if (df->min_freq && *freq < df->min_freq)
		*freq = df->min_freq;
	if (df->max_freq && *freq > df->max_freq)
		*freq = df->max_freq;

	return 0;
}

__attribute__((used)) static int devfreq_simple_ondemand_handler(struct devfreq *devfreq,
				unsigned int event, void *data)
{
	switch (event) {
	case DEVFREQ_GOV_START:
		devfreq_monitor_start(devfreq);
		break;

	case DEVFREQ_GOV_STOP:
		devfreq_monitor_stop(devfreq);
		break;

	case DEVFREQ_GOV_INTERVAL:
		devfreq_interval_update(devfreq, (unsigned int *)data);
		break;

	case DEVFREQ_GOV_SUSPEND:
		devfreq_monitor_suspend(devfreq);
		break;

	case DEVFREQ_GOV_RESUME:
		devfreq_monitor_resume(devfreq);
		break;

	default:
		break;
	}

	return 0;
}


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
typedef  int time_t ;
struct xtm {unsigned int second; unsigned int minute; unsigned int hour; int dse; int weekday; unsigned int monthday; unsigned int month; } ;
struct xt_time_info {int flags; scalar_t__ date_start; scalar_t__ date_stop; unsigned int daytime_start; unsigned int daytime_stop; int weekdays_match; int monthdays_match; } ;
struct xt_mtchk_param {struct xt_time_info* matchinfo; } ;
struct xt_action_param {struct xt_time_info* matchinfo; } ;
struct sk_buff {scalar_t__ tstamp; } ;
typedef  scalar_t__ s64 ;
struct TYPE_2__ {int tz_minuteswest; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int*) ; 
 unsigned int DSE_FIRST ; 
 int EDOM ; 
 int EINVAL ; 
 int /*<<< orphan*/  NSEC_PER_SEC ; 
 int SECONDS_PER_DAY ; 
 int XT_TIME_ALL_FLAGS ; 
 int XT_TIME_ALL_MONTHDAYS ; 
 int XT_TIME_CONTIGUOUS ; 
 int XT_TIME_LOCAL_TZ ; 
 scalar_t__ XT_TIME_MAX_DAYTIME ; 
 int /*<<< orphan*/  __net_timestamp (struct sk_buff*) ; 
 unsigned int* days_since_epoch ; 
 unsigned int* days_since_leapyear ; 
 unsigned int* days_since_year ; 
 scalar_t__ div_s64 (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ ktime_to_ns (scalar_t__) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,...) ; 
 TYPE_1__ sys_tz ; 

__attribute__((used)) static inline bool is_leap(unsigned int y)
{
	return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

__attribute__((used)) static inline unsigned int localtime_1(struct xtm *r, time_t time)
{
	unsigned int v, w;

	/* Each day has 86400s, so finding the hour/minute is actually easy. */
	v         = time % SECONDS_PER_DAY;
	r->second = v % 60;
	w         = v / 60;
	r->minute = w % 60;
	r->hour   = w / 60;
	return v;
}

__attribute__((used)) static inline void localtime_2(struct xtm *r, time_t time)
{
	/*
	 * Here comes the rest (weekday, monthday). First, divide the SSTE
	 * by seconds-per-day to get the number of _days_ since the epoch.
	 */
	r->dse = time / 86400;

	/*
	 * 1970-01-01 (w=0) was a Thursday (4).
	 * -1 and +1 map Sunday properly onto 7.
	 */
	r->weekday = (4 + r->dse - 1) % 7 + 1;
}

__attribute__((used)) static void localtime_3(struct xtm *r, time_t time)
{
	unsigned int year, i, w = r->dse;

	/*
	 * In each year, a certain number of days-since-the-epoch have passed.
	 * Find the year that is closest to said days.
	 *
	 * Consider, for example, w=21612 (2029-03-04). Loop will abort on
	 * dse[i] <= w, which happens when dse[i] == 21550. This implies
	 * year == 2009. w will then be 62.
	 */
	for (i = 0, year = DSE_FIRST; days_since_epoch[i] > w;
	    ++i, --year)
		/* just loop */;

	w -= days_since_epoch[i];

	/*
	 * By now we have the current year, and the day of the year.
	 * r->yearday = w;
	 *
	 * On to finding the month (like above). In each month, a certain
	 * number of days-since-New Year have passed, and find the closest
	 * one.
	 *
	 * Consider w=62 (in a non-leap year). Loop will abort on
	 * dsy[i] < w, which happens when dsy[i] == 31+28 (i == 2).
	 * Concludes i == 2, i.e. 3rd month => March.
	 *
	 * (A different approach to use would be to subtract a monthlength
	 * from w repeatedly while counting.)
	 */
	if (is_leap(year)) {
		/* use days_since_leapyear[] in a leap year */
		for (i = ARRAY_SIZE(days_since_leapyear) - 1;
		    i > 0 && days_since_leapyear[i] > w; --i)
			/* just loop */;
		r->monthday = w - days_since_leapyear[i] + 1;
	} else {
		for (i = ARRAY_SIZE(days_since_year) - 1;
		    i > 0 && days_since_year[i] > w; --i)
			/* just loop */;
		r->monthday = w - days_since_year[i] + 1;
	}

	r->month    = i + 1;
}

__attribute__((used)) static bool
time_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_time_info *info = par->matchinfo;
	unsigned int packet_time;
	struct xtm current_time;
	s64 stamp;

	/*
	 * We cannot use get_seconds() instead of __net_timestamp() here.
	 * Suppose you have two rules:
	 * 	1. match before 13:00
	 * 	2. match after 13:00
	 * If you match against processing time (get_seconds) it
	 * may happen that the same packet matches both rules if
	 * it arrived at the right moment before 13:00.
	 */
	if (skb->tstamp == 0)
		__net_timestamp((struct sk_buff *)skb);

	stamp = ktime_to_ns(skb->tstamp);
	stamp = div_s64(stamp, NSEC_PER_SEC);

	if (info->flags & XT_TIME_LOCAL_TZ)
		/* Adjust for local timezone */
		stamp -= 60 * sys_tz.tz_minuteswest;

	/*
	 * xt_time will match when _all_ of the following hold:
	 *   - 'now' is in the global time range date_start..date_end
	 *   - 'now' is in the monthday mask
	 *   - 'now' is in the weekday mask
	 *   - 'now' is in the daytime range time_start..time_end
	 * (and by default, libxt_time will set these so as to match)
	 */

	if (stamp < info->date_start || stamp > info->date_stop)
		return false;

	packet_time = localtime_1(&current_time, stamp);

	if (info->daytime_start < info->daytime_stop) {
		if (packet_time < info->daytime_start ||
		    packet_time > info->daytime_stop)
			return false;
	} else {
		if (packet_time < info->daytime_start &&
		    packet_time > info->daytime_stop)
			return false;

		/** if user asked to ignore 'next day', then e.g.
		 *  '1 PM Wed, August 1st' should be treated
		 *  like 'Tue 1 PM July 31st'.
		 *
		 * This also causes
		 * 'Monday, "23:00 to 01:00", to match for 2 hours, starting
		 * Monday 23:00 to Tuesday 01:00.
		 */
		if ((info->flags & XT_TIME_CONTIGUOUS) &&
		     packet_time <= info->daytime_stop)
			stamp -= SECONDS_PER_DAY;
	}

	localtime_2(&current_time, stamp);

	if (!(info->weekdays_match & (1 << current_time.weekday)))
		return false;

	/* Do not spend time computing monthday if all days match anyway */
	if (info->monthdays_match != XT_TIME_ALL_MONTHDAYS) {
		localtime_3(&current_time, stamp);
		if (!(info->monthdays_match & (1 << current_time.monthday)))
			return false;
	}

	return true;
}

__attribute__((used)) static int time_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_time_info *info = par->matchinfo;

	if (info->daytime_start > XT_TIME_MAX_DAYTIME ||
	    info->daytime_stop > XT_TIME_MAX_DAYTIME) {
		pr_info_ratelimited("invalid argument - start or stop time greater than 23:59:59\n");
		return -EDOM;
	}

	if (info->flags & ~XT_TIME_ALL_FLAGS) {
		pr_info_ratelimited("unknown flags 0x%x\n",
				    info->flags & ~XT_TIME_ALL_FLAGS);
		return -EINVAL;
	}

	if ((info->flags & XT_TIME_CONTIGUOUS) &&
	     info->daytime_start < info->daytime_stop)
		return -EINVAL;

	return 0;
}


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
typedef  int timelib_sll ;

/* Variables and functions */
 int* d_table_common ; 
 int* d_table_leap ; 
 int* m_table_common ; 
 int* m_table_leap ; 
 int* ml_table_common ; 
 int* ml_table_leap ; 
 int timelib_is_leap (int) ; 

__attribute__((used)) static timelib_sll positive_mod(timelib_sll x, timelib_sll y)
{
	timelib_sll tmp;

	tmp = x % y;
	if (tmp < 0) {
		tmp += y;
	}

	return tmp;
}

__attribute__((used)) static timelib_sll century_value(timelib_sll j)
{
	return 6 - positive_mod(j, 4) * 2;
}

__attribute__((used)) static timelib_sll timelib_day_of_week_ex(timelib_sll y, timelib_sll m, timelib_sll d, int iso)
{
	timelib_sll c1, y1, m1, dow;

	/* Only valid for Gregorian calendar, commented out as we don't handle
	 * Julian calendar. We just return the 'wrong' day of week to be
	 * consistent. */
	c1 = century_value(y / 100);
	y1 = positive_mod(y, 100);
	m1 = timelib_is_leap(y) ? m_table_leap[m] : m_table_common[m];
	dow = positive_mod((c1 + y1 + m1 + (y1 / 4) + d), 7);
	if (iso) {
		if (dow == 0) {
			dow = 7;
		}
	}
	return dow;
}

timelib_sll timelib_day_of_week(timelib_sll y, timelib_sll m, timelib_sll d)
{
	return timelib_day_of_week_ex(y, m, d, 0);
}

timelib_sll timelib_iso_day_of_week(timelib_sll y, timelib_sll m, timelib_sll d)
{
	return timelib_day_of_week_ex(y, m, d, 1);
}

timelib_sll timelib_day_of_year(timelib_sll y, timelib_sll m, timelib_sll d)
{
	return (timelib_is_leap(y) ? d_table_leap[m] : d_table_common[m]) + d - 1;
}

timelib_sll timelib_days_in_month(timelib_sll y, timelib_sll m)
{
	return timelib_is_leap(y) ? ml_table_leap[m] : ml_table_common[m];
}

void timelib_isoweek_from_date(timelib_sll y, timelib_sll m, timelib_sll d, timelib_sll *iw, timelib_sll *iy)
{
	int y_leap, prev_y_leap, doy, jan1weekday, weekday;

	y_leap = timelib_is_leap(y);
	prev_y_leap = timelib_is_leap(y-1);
	doy = timelib_day_of_year(y, m, d) + 1;
	if (y_leap && m > 2) {
		doy++;
	}
	jan1weekday = timelib_day_of_week(y, 1, 1);
	weekday = timelib_day_of_week(y, m, d);
	if (weekday == 0) weekday = 7;
	if (jan1weekday == 0) jan1weekday = 7;
	/* Find if Y M D falls in YearNumber Y-1, WeekNumber 52 or 53 */
	if (doy <= (8 - jan1weekday) && jan1weekday > 4) {
		*iy = y - 1;
		if (jan1weekday == 5 || (jan1weekday == 6 && prev_y_leap)) {
			*iw = 53;
		} else {
			*iw = 52;
		}
	} else {
		*iy = y;
	}
	/* 8. Find if Y M D falls in YearNumber Y+1, WeekNumber 1 */
	if (*iy == y) {
		int i;

		i = y_leap ? 366 : 365;
		if ((i - (doy - y_leap)) < (4 - weekday)) {
			*iy = y + 1;
			*iw = 1;
			return;
		}
	}
	/* 9. Find if Y M D falls in YearNumber Y, WeekNumber 1 through 53 */
	if (*iy == y) {
		int j;

		j = doy + (7 - weekday) + (jan1weekday - 1);
		*iw = j / 7;
		if (jan1weekday > 4) {
			*iw -= 1;
		}
	}
}

void timelib_isodate_from_date(timelib_sll y, timelib_sll m, timelib_sll d, timelib_sll *iy, timelib_sll *iw, timelib_sll *id)
{
	timelib_isoweek_from_date(y, m, d, iw, iy);
	*id = timelib_day_of_week_ex(y, m, d, 1);
}

__attribute__((used)) static timelib_sll timelib_daynr_from_weeknr_ex(timelib_sll iy, timelib_sll iw, timelib_sll id, timelib_sll *y)
{
	timelib_sll dow, day;

	/* Figure out the dayofweek for y-1-1 */
	dow = timelib_day_of_week(iy, 1, 1);
	/* then use that to figure out the offset for day 1 of week 1 */
	day = 0 - (dow > 4 ? dow - 7 : dow);
	/* and adjust the year to the natural year if we need to */
	*y = (iw == 1 && day < 0 && id < dow) ? iy - 1 : iy;

	/* Add weeks and days */
	return day + ((iw - 1) * 7) + id;
}

timelib_sll timelib_daynr_from_weeknr(timelib_sll iy, timelib_sll iw, timelib_sll id)
{
	timelib_sll dummy_iso_year;

	return timelib_daynr_from_weeknr_ex(iy, iw, id, &dummy_iso_year);
}

void timelib_date_from_isodate(timelib_sll iy, timelib_sll iw, timelib_sll id, timelib_sll *y, timelib_sll *m, timelib_sll *d)
{
	timelib_sll daynr = timelib_daynr_from_weeknr_ex(iy, iw, id, y) + 1;
	int *table;

	*m = 0;

	if (daynr <= 0) {
		*y += 1;
	}

	if (timelib_is_leap(*y)) {
		table = ml_table_leap;
		if (daynr > 366) {
			*y += 1;
			daynr -= 366;
		}
	} else {
		table = ml_table_common;
		if (daynr > 365) {
			*y += 1;
			daynr -= 365;
		}
	}

	do {
		daynr -= table[*m];
		(*m)++;
	} while (daynr > table[*m]);

	if (daynr <= 0) {
		daynr += 31;
		*y -= 1;
		*m = 12;
	}

	*d = daynr;
}

int timelib_valid_time(timelib_sll h, timelib_sll i, timelib_sll s)
{
	if (h < 0 || h > 23 || i < 0 || i > 59 || s < 0 || s > 59) {
		return 0;
	}
	return 1;
}

int timelib_valid_date(timelib_sll y, timelib_sll m, timelib_sll d)
{
	if (m < 1 || m > 12 || d < 1 || d > timelib_days_in_month(y, m)) {
		return 0;
	}
	return 1;
}


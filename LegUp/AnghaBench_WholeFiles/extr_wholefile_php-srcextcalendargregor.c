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
typedef  int zend_long ;

/* Variables and functions */
 int DAYS_PER_400_YEARS ; 
 int DAYS_PER_4_YEARS ; 
 int DAYS_PER_5_MONTHS ; 
 int GREGOR_SDN_OFFSET ; 
 int LONG_MAX ; 

void SdnToGregorian(
					   zend_long sdn,
					   int *pYear,
					   int *pMonth,
					   int *pDay)
{
	int century;
	int year;
	int month;
	int day;
	zend_long temp;
	int dayOfYear;

	if (sdn <= 0 ||
			sdn > (LONG_MAX - 4 * GREGOR_SDN_OFFSET) / 4) {
		goto fail;
	}
	temp = (sdn + GREGOR_SDN_OFFSET) * 4 - 1;

	/* Calculate the century (year/100). */
	century = temp / DAYS_PER_400_YEARS;

	/* Calculate the year and day of year (1 <= dayOfYear <= 366). */
	temp = ((temp % DAYS_PER_400_YEARS) / 4) * 4 + 3;
	year = (century * 100) + (temp / DAYS_PER_4_YEARS);
	dayOfYear = (temp % DAYS_PER_4_YEARS) / 4 + 1;

	/* Calculate the month and day of month. */
	temp = dayOfYear * 5 - 3;
	month = temp / DAYS_PER_5_MONTHS;
	day = (temp % DAYS_PER_5_MONTHS) / 5 + 1;

	/* Convert to the normal beginning of the year. */
	if (month < 10) {
		month += 3;
	} else {
		year += 1;
		month -= 9;
	}

	/* Adjust to the B.C./A.D. type numbering. */
	year -= 4800;
	if (year <= 0)
		year--;

	*pYear = year;
	*pMonth = month;
	*pDay = day;
	return;

fail:
	*pYear = 0;
	*pMonth = 0;
	*pDay = 0;
}

zend_long GregorianToSdn(
						   int inputYear,
						   int inputMonth,
						   int inputDay)
{
	zend_long year;
	int month;

	/* check for invalid dates */
	if (inputYear == 0 || inputYear < -4714 ||
		inputMonth <= 0 || inputMonth > 12 ||
		inputDay <= 0 || inputDay > 31) {
		return (0);
	}
	/* check for dates before SDN 1 (Nov 25, 4714 B.C.) */
	if (inputYear == -4714) {
		if (inputMonth < 11) {
			return (0);
		}
		if (inputMonth == 11 && inputDay < 25) {
			return (0);
		}
	}
	/* Make year always a positive number. */
	if (inputYear < 0) {
		year = inputYear + 4801;
	} else {
		year = inputYear + 4800;
	}

	/* Adjust the start of the year. */
	if (inputMonth > 2) {
		month = inputMonth - 3;
	} else {
		month = inputMonth + 9;
		year--;
	}

	return (((year / 100) * DAYS_PER_400_YEARS) / 4
			+ ((year % 100) * DAYS_PER_4_YEARS) / 4
			+ (month * DAYS_PER_5_MONTHS + 2) / 5
			+ inputDay
			- GREGOR_SDN_OFFSET);
}

